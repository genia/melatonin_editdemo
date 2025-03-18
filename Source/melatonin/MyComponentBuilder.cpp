//
//  MyComponentBuilder.cpp
//  orandj - App
//
//  Created by GZ on 11/30/24.
//  Copyright © 2024 JUCE. All rights reserved.
//

#include "MyComponentBuilder.hpp"
#include "melatonin_inspector/InsetRelativeCoordinatePositioner.hpp"
#include "BinaryData.h"

#define Q(str) #str
Slider::SliderStyle
MyComponentBuilder::sliderStyleValue( String styleStr )
{
#define StyleVal( str ) if (styleStr == Q(str)) return juce::Slider::str;
    
    StyleVal(LinearHorizontal)               /**< A traditional horizontal slider. */
    StyleVal(LinearVertical)                 /**< A traditional vertical slider. */
    StyleVal(LinearBar)                      /**< A horizontal bar slider with the text label drawn on top of it. */
    StyleVal(LinearBarVertical)              /**< A vertical bar slider with the text label drawn on top of it. */
    StyleVal(Rotary)                         /**< A rotary control that you move by dragging the mouse in a circular motion, like a knob.
                                         @see setRotaryParameters */
    StyleVal(RotaryHorizontalDrag)           /**< A rotary control that you move by dragging the mouse left-to-right.
                                         @see setRotaryParameters */
    StyleVal(RotaryVerticalDrag)             /**< A rotary control that you move by dragging the mouse up-and-down.
                                         @see setRotaryParameters */
    StyleVal(RotaryHorizontalVerticalDrag)   /**< A rotary control that you move by dragging the mouse up-and-down or left-to-right.
                                         @see setRotaryParameters */
    StyleVal(IncDecButtons)                  /**< A pair of buttons that increment or decrement the slider's value by the increment set in setRange(). */

    StyleVal(TwoValueHorizontal)             /**< A horizontal slider that has two thumbs instead of one, so it can show a minimum and maximum value.
                                         @see setMinValue, setMaxValue */
    StyleVal(TwoValueVertical)               /**< A vertical slider that has two thumbs instead of one, so it can show a minimum and maximum value.
                                         @see setMinValue, setMaxValue */

    StyleVal(ThreeValueHorizontal)           /**< A horizontal slider that has three thumbs instead of one, so it can show a minimum and maximum
                                         value, with the current value being somewhere between them.
                                         @see setMinValue, setMaxValue */
    StyleVal(ThreeValueVertical)
    return juce::Slider::LinearHorizontal;
}
String sliderStyleString( Slider::SliderStyle style )
{
#define StyleStr( sym ) if (style == juce::Slider::sym) return Q( sym );
    
    StyleStr(LinearHorizontal)               /**< A traditional horizontal slider. */
    StyleStr(LinearVertical)                 /**< A traditional vertical slider. */
    StyleStr(LinearBar)                      /**< A horizontal bar slider with the text label drawn on top of it. */
    StyleStr(LinearBarVertical)              /**< A vertical bar slider with the text label drawn on top of it. */
    StyleStr(Rotary)                         /**< A rotary control that you move by dragging the mouse in a circular motion, like a knob.
                                         @see setRotaryParameters */
    StyleStr(RotaryHorizontalDrag)           /**< A rotary control that you move by dragging the mouse left-to-right.
                                         @see setRotaryParameters */
    StyleStr(RotaryVerticalDrag)             /**< A rotary control that you move by dragging the mouse up-and-down.
                                         @see setRotaryParameters */
    StyleStr(RotaryHorizontalVerticalDrag)   /**< A rotary control that you move by dragging the mouse up-and-down or left-to-right.
                                         @see setRotaryParameters */
    StyleStr(IncDecButtons)                  /**< A pair of buttons that increment or decrement the slider's value by the increment set in setRange(). */

    StyleStr(TwoValueHorizontal)             /**< A horizontal slider that has two thumbs instead of one, so it can show a minimum and maximum value.
                                         @see setMinValue, setMaxValue */
    StyleStr(TwoValueVertical)               /**< A vertical slider that has two thumbs instead of one, so it can show a minimum and maximum value.
                                         @see setMinValue, setMaxValue */

    StyleStr(ThreeValueHorizontal)           /**< A horizontal slider that has three thumbs instead of one, so it can show a minimum and maximum
                                         value, with the current value being somewhere between them.
                                         @see setMinValue, setMaxValue */
    StyleStr(ThreeValueVertical)
    return "";
}


Component *
MyComponentBuilder::createComponentTree(ValueTree &vt,
                                        Component *c,
                                        Button::Listener *buttonListener,
                                        Slider::Listener *sliderListener,
                                        ChangeListener *changeListener)
{
    String name = vt.getProperty("name");
    String componentClass = vt.getProperty("type");
    bool isTabbedButtonBar = false;
    
    if (c == nullptr)
    {
        if (componentClass == "juce::Component")
        {
            c = new juce::Component();
        }
        else if (componentClass == "juce::TextButton")
        {
            c = new juce::TextButton();
            c->setColour (juce::TextButton::buttonColourId, juce::Colour (0xffb5b5b5));
            Button *b = (Button *)c;
            b->setButtonText(vt.getProperty("buttonText"));
            if (buttonListener != nullptr)
            {
                b->addListener(buttonListener);
            }
        }
        else if (componentClass == "juce::ToggleButton")
        {
            c = new juce::ToggleButton();
            Button *b = (Button *)c;
            b->setButtonText(vt.getProperty("buttonText"));
            if (buttonListener != nullptr)
            {
                b->addListener(buttonListener);
            }
        }
        else if (componentClass == "juce::DrawableButton")
        {
            c = new juce::DrawableButton(name, juce::DrawableButton::ImageFitted);
            DrawableButton *b = (DrawableButton *)c;
            b->setButtonText(vt.getProperty("buttonText"));

            String svgName( vt.getProperty("sourceFile") );
            
            int size = 0;
            String rsrcName = svgName.replace(".", "_");
            auto data = BinaryData::getNamedResource (rsrcName.toUTF8(), size);
            std::unique_ptr< Drawable > drawable = Drawable::createFromImageData(data, size);
            Colour origColour( 0xff5f6368 );
            Colour newColour( Colours::lightgrey );
            drawable->setName( svgName );
            std::unique_ptr< Drawable > one = drawable->createCopy();
            one->replaceColour(origColour, newColour);
            std::unique_ptr< Drawable > two = drawable->createCopy();
            two->replaceColour(origColour, newColour.darker());
            std::unique_ptr< Drawable > three = drawable->createCopy();
            three->replaceColour(origColour, newColour.darker(.8));
            
            b->setImages(one.get(), two.get(), three.get() );

            if (buttonListener != nullptr)
            {
                b->addListener (buttonListener);
            }
        }
        else if (componentClass == "juce::Slider")
        {
            c = new juce::Slider();
            Slider *s = (Slider *)c;
            s->setRange (vt.getProperty("min"), vt.getProperty("max"), vt.getProperty("int"));
            s->setSliderStyle (sliderStyleValue(vt.getProperty("style")));
            s->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
            if (sliderListener != nullptr)
            {
                s->addListener (sliderListener);
            }
        }
        else if (componentClass == "juce::Label")
        {
            c = new juce::Label();
            Label *l = (Label *)c;
            l->setText(vt.getProperty("labelText"), dontSendNotification);
            l->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
            l->setJustificationType (juce::Justification::centredLeft);
            l->setEditable (false, false, false);
            l->setColour (juce::TextEditor::textColourId, juce::Colours::black);
            l->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));
        }
        else if (componentClass == "juce::TextEditor")
        {
            c = new juce::TextEditor();
            c->setColour (juce::TextEditor::textColourId, juce::Colour (0xff220080));
            c->setColour (juce::TextEditor::backgroundColourId, juce::Colours::lightgrey);//juce::Colour (0x00495358));
            c->setColour (juce::TextEditor::highlightColourId, juce::Colour (0x8565bcec));
        }
        else if (componentClass == "juce::TabbedButtonBar")
        {
            c = new juce::TabbedButtonBar(TabbedButtonBar::TabsAtTop);
            if (changeListener != nullptr)
            {
                juce::TabbedButtonBar *tb = (juce::TabbedButtonBar *)c;
                tb->addChangeListener (changeListener);
            }

            isTabbedButtonBar = true;
        }
    }
    else if (auto *tb = dynamic_cast<juce::TabbedButtonBar *>(c))
    {
        if (componentClass == "juce::TabBarButton")
        {
            tb->addTab(name, Colours::grey, -1);
            c = tb->getTabButton(tb->getNumTabs()-1);
        }
        else
        {
            c = nullptr;
        }
    }
        
    if (c != nullptr)
    {
        c->setName(name);
        c->setBounds(vt.getProperty("x"), vt.getProperty("y"),
                     vt.getProperty("width"), vt.getProperty("height"));
                
        melatonin::InsetRelativeCoordinatePositioner *mrp = melatonin::InsetRelativeCoordinatePositioner::makeForComponent( *c );
        String styleStr = vt.getProperty("style");
        StringArray styleSpecs = StringArray::fromTokens(styleStr, ";", "");
        for (String spec : styleSpecs)
        {
            StringArray oneSpec = StringArray::fromTokens(spec, ":", "");
            oneSpec.trim();
            
            if (oneSpec.size() == 2)
            {
                mrp->params[oneSpec[0]] = oneSpec[1].getIntValue();
                mrp->params[oneSpec[0] + "Enabled"] = true;
            }
        }

        for (auto child : vt)
        {
            Component *childComp = this->createComponentTree(child, isTabbedButtonBar?c:nullptr, buttonListener, sliderListener, changeListener);
            if (childComp != nullptr)
            {
                c->addAndMakeVisible( childComp );
            }
        }
        c->getAccessibilityHandler();
    }
    return c;
}

namespace melatonin
{

void InspectorComponent::deleteComponent()
{
    if (!selectedComponent)
    {
        AlertWindow::showMessageBox ( AlertWindow::InfoIcon, "Error", "Please select a component to delete." );
        return;
    }
    
    Component *selComponent = selectedComponent.getComponent();
    selectComponent (nullptr);
    selectComponentCallback(selComponent);
    delete selComponent;
}

void InspectorComponent::downloadXML()
{
    if (!selectedComponent)
    {
        AlertWindow::showMessageBox ( AlertWindow::InfoIcon, "Error", "Please select a component to export." );
        return;
    }
    
    //Component *selComponent = selectedComponent.getComponent();

    String typeStr( melatonin::type ( *selectedComponent ) );
    
    String xmlString( melatonin::walkComponent( selectedComponent ).toXmlString() );
    File fileLocation = File::getSpecialLocation (File::userDesktopDirectory);
    FileChooser fileChooser ("Save component XML", fileLocation.getChildFile( typeStr + ".xml" ), "*.xml");
    
    if (fileChooser.browseForFileToSave(true))
    {
        File file( fileChooser.getResult() );
        file.replaceWithText( xmlString );
    }
}

void InspectorComponent::addComponent()
{
    if (!selectedComponent)
    {
        AlertWindow::showMessageBox ( AlertWindow::InfoIcon, "Error", "To add a new component, please select a parent component first." );
        return;
    }
    
    String xmlFilename( "ComponentTemplates.xml" );
    auto xmlFilePath = File::getSpecialLocation (File::userDesktopDirectory)
        .getChildFile (xmlFilename);
    File xmlFile( xmlFilePath );
    String componentTemplateXML;
    if (xmlFile.existsAsFile())
    {
        componentTemplateXML = xmlFile.loadFileAsString();
    }
    else
    {
        int size = 0;
        String rsrcName = xmlFilename.replace(".", "_");
        const char *data = BinaryData::getNamedResource (rsrcName.toUTF8(), size);
        componentTemplateXML = data;
    }
    ValueTree valueTree = ValueTree::fromXml(componentTemplateXML);
    PopupMenu m;
    for (auto child : valueTree) {
        String menuItemLabel( String("Add ") + child.getProperty("label").toString() );
        String menuItemContentXML( child.toXmlString() );
        
        m.addItem (PopupMenu::Item ( menuItemLabel ).setAction ([=, this] { addComponentFromXML( menuItemContentXML ); } ) );
    }
    
    m.show();
}
void InspectorComponent::addComponentFromXML(const String &componentXML)
{
    if (!selectedComponent)
    {
        AlertWindow::showMessageBox ( AlertWindow::InfoIcon, "Error", "To add a new component, please select a parent component first." );
        return;
    }
    
    ValueTree valueTree = ValueTree::fromXml(componentXML);
    MyComponentBuilder cb;
    Component *newComponent = cb.createComponentTree(valueTree, nullptr);

    if (newComponent == nullptr)
    {
        AlertWindow::showMessageBox ( AlertWindow::InfoIcon, "Error", "Couldn't create new component!" );
        return;
    }

    selectedComponent->addAndMakeVisible( newComponent, 0 );
    outlineComponentCallback( selectedComponent );
    selectComponent( newComponent );
    displayComponentInfo( newComponent );
}

String labelText( Component *c )
{
    if (auto* label = dynamic_cast<juce::Label*> (c))
    {
        return " labelText=\"" + label->getText() + "\"";
    }
    return "";
}

String buttonText( Component *c )
{
    if (auto* button = dynamic_cast<juce::Button*> (c))
    {
        return " buttonText=\"" + button->getButtonText() + "\"";
    }
    return "";
}

ValueTree walkComponent( Component *c )
{
    ValueTree componentVt {
        "component", {
            { "type", melatonin::type (*c).replace("&", "") },
            { "name", c->getName() },
            { "x", c->getX() },
            { "y", c->getY() },
            { "width", c->getWidth() },
            { "height", c->getHeight() },
        } };    

    melatonin::InsetRelativeCoordinatePositioner *mrp = dynamic_cast<melatonin::InsetRelativeCoordinatePositioner*>( c->getPositioner() );
    if (mrp != nullptr)
    {
        String styleStr;
        const std::array<Identifier, 4> paramNames = {
            "leftInset",
            "rightInset",
            "topInset",
            "bottomInset",
        };
        for (auto paramName : paramNames)
        {
            if (mrp->params[paramName + "Enabled"].getValue())
            {
                styleStr = styleStr + paramName + ": " + String((int)mrp->params[paramName].getValue()) + "; ";
            }
        }
        componentVt.setProperty("style", styleStr, nullptr);
    }

    if (auto* slider = dynamic_cast<juce::Slider*> (c))
    {
        componentVt.setProperty("min", slider->getMinimum(), nullptr);
        componentVt.setProperty("max", slider->getMaximum(), nullptr);
        componentVt.setProperty("int", slider->getInterval(), nullptr);
        componentVt.setProperty("slider", sliderStyleString( slider->getSliderStyle() ), nullptr);
    }
    if (auto* button = dynamic_cast<juce::Button*> (c))
    {
        componentVt.setProperty( "buttonText", button->getButtonText(), nullptr );
        if (auto* drawableButton = dynamic_cast<juce::DrawableButton*> (c))
        {
            Drawable *dr = drawableButton->getNormalImage();
            componentVt.setProperty( "sourceFile", dr->getName(), nullptr );
        }
    }
    if (auto* label = dynamic_cast<juce::Label*> (c))
    {
        componentVt.setProperty( "labelText", label->getText(), nullptr );
    }
    
    for (int i = 0; i < c->getNumChildComponents(); ++i)
    {
        auto child = c->getChildComponent (i);
        if (componentString (child) != "Melatonin Overlay")
        {
            ValueTree childVt = walkComponent(child);
            componentVt.addChild(childVt, -1, nullptr);
        }
    }
    return componentVt;
}

}
