#include "MainComponent.h"
#include "melatonin/MyComponentBuilder.hpp"
#include "PJNotifier.hpp"

using namespace juce;

//==============================================================================
MainComponent::MainComponent()
{
    setSize (600, 400);
    
    String typeStr( melatonin::type ( *this ) );
    auto xmlFilePath = File::getSpecialLocation (File::userDesktopDirectory)
        .getChildFile (typeStr + ".xml");
    File xmlFile( xmlFilePath );
    if (!xmlFile.existsAsFile())
    {
        xmlFilePath = File::getSpecialLocation (File::currentApplicationFile)
            .getChildFile ("Contents")
            .getChildFile ("Resources")
            .getChildFile (typeStr + ".xml");
        xmlFile = xmlFilePath;
    }
    String componentXML = xmlFile.loadFileAsString();
    ValueTree valueTree = ValueTree::fromXml(componentXML);
    MyComponentBuilder cb;
    /*Component *comp = */cb.createComponentTree(valueTree, this, this, this, this);

    inspector = std::make_unique<melatonin::Inspector> (*this);
    inspector->setVisible (true);
    inspector->toggle( false );
}

MainComponent::~MainComponent()
{
    deleteAllChildrenRecursively( this );
}

void
MainComponent::deleteAllChildrenRecursively( Component *c )
{
    String typeStr( melatonin::type (*c) );
    //std::cout << "deleteAllChildrenRecursively " << typeStr << std::endl;
    if ((typeStr != "juce::DrawableButton") &&
        (typeStr != "juce::TabbedButtonBar") &&
        !typeStr.startsWith("melatonin::") &&
        !typeStr.startsWith( "juce::Viewport::") &&
        !typeStr.startsWith( "juce::TextEditor::")
        )
        // special case - this creates components that can't be deleted
    {
        while (int n = c->getNumChildComponents())
        {
            Component *child = c->getChildComponent(n-1);
            c->removeChildComponent ( n-1 );
            this->deleteAllChildrenRecursively( child );
        }
        
        if (c != this)
        {
            delete c;
        }
    }
}

void MainComponent::buttonClicked (juce::Button* buttonThatWasClicked)
{
    PJNotifier::sendNotif( buttonThatWasClicked->getName(), buttonThatWasClicked);
}

void MainComponent::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    PJNotifier::sendNotif( sliderThatWasMoved->getName(), sliderThatWasMoved);
}

void
MainComponent::changeListenerCallback(ChangeBroadcaster *source)
{
    if (auto *c = dynamic_cast<Component *>( source ))
    {
        PJNotifier::sendNotif( c->getName(), c);
    }
}

//==============================================================================
void MainComponent::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setFont (juce::FontOptions (16.0f));
    g.setColour (juce::Colours::white);
    g.drawText ("Hello World!", getLocalBounds(), juce::Justification::centred, true);
}

void MainComponent::resized()
{
    // This is called when the MainComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
