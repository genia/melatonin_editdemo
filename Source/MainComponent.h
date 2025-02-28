#pragma once

#include <JuceHeader.h>
#include "melatonin_inspector/melatonin_inspector.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent  :
    public juce::Component,
    public juce::Button::Listener,
    public juce::Slider::Listener,
    public juce::ChangeListener
{
public:
    //==============================================================================
    MainComponent();
    ~MainComponent() override;
    void deleteAllChildrenRecursively( juce::Component *c );

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void buttonClicked (juce::Button* buttonThatWasClicked) override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void changeListenerCallback(juce::ChangeBroadcaster *source) override;

private:
    //==============================================================================
    // Your private member variables go here...

    std::unique_ptr<melatonin::Inspector> inspector;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
};
