//
//  MyComponentBuilder.hpp
//  orandj - App
//
//  Created by GZ on 11/30/24.
//  Copyright © 2024 JUCE. All rights reserved.
//

#ifndef MyComponentBuilder_hpp
#define MyComponentBuilder_hpp

#include <JuceHeader.h>
using namespace juce;

class MyComponentBuilder {
public:
    MyComponentBuilder() {}
    
    Component *createComponentTree(ValueTree &vt,
                                   Component *c = nullptr,
                                   Button::Listener *buttonListener = nullptr,
                                   Slider::Listener *sliderListener = nullptr,
                                   ChangeListener *changeListener = nullptr);
};

namespace melatonin {

ValueTree walkComponent( Component *c );

};

#endif /* MyComponentBuilder_hpp */
