/*
  ==============================================================================

    AudioVisualizerController.cpp
    Created: 17 Sep 2017 5:41:09pm
    Author:  Jack Campbell

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "./AudioVisualizerController.h"
#include "./AudioPlayer.h"


//==============================================================================
/*
AudioVisualizerController::AudioVisualizerController() : state(Stopped), thumbnailCache(5), thumbnail(512, formatManager, thumbnailCache)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    setSize (400, 600);
    formatManager.registerBasicFormats();
    
    this->thumbnail.addChangeListener(this);
    setAudioChannels (2, 2);
}*/


AudioVisualizerController::AudioVisualizerController(int width, int height) : thumbnailCache(5), thumbnail(512, formatManager, thumbnailCache)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    setSize (width, height);
    
    formatManager.registerBasicFormats();
    
    this->thumbnail.addChangeListener(this);
}

AudioVisualizerController::~AudioVisualizerController()
{
    this->thumbnail.clear();
}

void AudioVisualizerController::paint (Graphics& g)
{
    const Rectangle<int> thumbnailBounds (0, 0, getWidth(), getHeight());
    
    if (thumbnail.getNumChannels() == 0)
    {
        g.setColour (Colours::darkgrey);
        g.fillRect (thumbnailBounds);
        g.setColour (Colours::white);
        g.drawFittedText ("No File Loaded", thumbnailBounds, Justification::centred, 1.0f);
    }
    else
    {
        g.setColour (Colours::white);
        g.fillRect (thumbnailBounds);
        
        g.setColour (Colours::red);                                     // [8]
        
        thumbnail.drawChannels (g,                                      // [9]
                                thumbnailBounds,
                                0.0,                                    // start time
                                thumbnail.getTotalLength(),             // end time
                                1.0f);                                  // vertical zoom
    }
}

void AudioVisualizerController::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

bool AudioVisualizerController::isInterestedInFileDrag (const StringArray &files)
{
    printf("interested in file drag");
    return true;
}
void AudioVisualizerController::filesDropped (const StringArray &files, int, int)
{
    printf("file name: %s", files[0].toRawUTF8());
    File file(files[0]);
    this->_audioFile = file;
    AudioPlayer::setAudioFile(file);
    thumbnail.setSource (new FileInputSource (file));          // [7]
   
}

void AudioVisualizerController::changeListenerCallback (ChangeBroadcaster* source)
{
    if (source == &thumbnail)        repaint();
}
