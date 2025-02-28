//
//  MyRelativeCoordinatePositioner.hpp
//  orandj - App
//
//  Created by GZ on 12/14/24.
//  Copyright © 2024 JUCE. All rights reserved.
//

#ifndef MyRelativeCoordinatePositioner_hpp
#define MyRelativeCoordinatePositioner_hpp

#include <JuceHeader.h>

using namespace std;
using namespace juce;

class MyRelativeCoordinatePositioner :
    public Component::Positioner,
    public ComponentListener
{
public:
    MyRelativeCoordinatePositioner(Component& component, bool shouldFit = false );

    static MyRelativeCoordinatePositioner *makeForComponent(Component &component, bool shouldFit = false);
    void fitToParent( bool shouldFit );
    void applyNewBounds (const Rectangle<int>& newBounds) override;
    void grabPositionInParent();
    void componentParentHierarchyChanged (Component& component) override;

    // since this is only called for the *parent*, both the positionable and its parent
    // must have a MyRelativeCoordinatePositioner attached
    void componentMovedOrResized (Component &p, bool wasMoved, bool wasResized) override;

    std::map<juce::Identifier, juce::Value> params;
};


#endif /* MyRelativeCoordinatePositioner_hpp */
