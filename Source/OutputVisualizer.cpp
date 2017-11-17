/*
  ==============================================================================

    InputVisualizer.cpp
    Created: 17 Nov 2017 10:16:48am
    Author:  Jack Campbell

  ==============================================================================
*/

#include "OutputVisualizer.h"

OutputVisualizer::OutputVisualizer(int width, int height) : AudioVisualizerController(width, height) {};

// visualize wave and play sound
// don't listen to files dropped, listen for "generate button" click
void OutputVisualizer::filesDropped (const StringArray &files, int, int)
{
    printf("file name: %s", files[0].toRawUTF8());
    File file(files[0]);
    this->_audioFile = file;
    thumbnail.setSource (new FileInputSource (file));          // [7]
    
}
