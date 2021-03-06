/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.0

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
#include "AudioPlayer.h"
//[/Headers]

#include "InputSignalDragDrop.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
InputSignalDragDrop::InputSignalDragDrop ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (comboBox = new ComboBox ("new combo box"));
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (String());
    comboBox->setTextWhenNoChoicesAvailable (TRANS("FIR"));
    comboBox->addItem (TRANS("FIR"), 1);
    comboBox->addItem (TRANS("FFT"), 2);
    comboBox->addSeparator();
    comboBox->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("input signal")));
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("impulse response")));
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("output")));
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (play_btn = new TextButton ("new button"));
    play_btn->setButtonText (TRANS("play"));
    play_btn->addListener (this);
    play_btn->setColour (TextButton::buttonColourId, Colour (0xff13c607));

    addAndMakeVisible (stop_btn = new TextButton ("new button"));
    stop_btn->setButtonText (TRANS("stop"));
    stop_btn->addListener (this);
    stop_btn->setColour (TextButton::buttonColourId, Colours::crimson);

    addAndMakeVisible (textButton3 = new TextButton ("new button"));
    textButton3->setButtonText (TRANS("save..."));
    textButton3->addListener (this);
    textButton3->setColour (TextButton::buttonColourId, Colour (0xff0611d0));

    addAndMakeVisible (generate_btn = new TextButton ("new button"));
    generate_btn->setButtonText (TRANS("generate"));
    generate_btn->addListener (this);
    generate_btn->setColour (TextButton::buttonColourId, Colour (0xff680086));

    addAndMakeVisible (label4 = new Label ("new label",
                                           TRANS("offline convolver")));
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (input_signal = new InputVisualizer (320, 160));
    input_signal->setName ("input signal");

    addAndMakeVisible (impulse_response = new ImpulseVisualizer (320, 160));
    impulse_response->setName ("impulse response");

    addAndMakeVisible (convolved_signal = new OutputVisualizer (528, 144, this->input_signal, this->impulse_response
                                                                ));
    convolved_signal->setName ("convolved signal");

    addAndMakeVisible (knoblabel = new Label ("new label",
                                              TRANS("balance")));
    knoblabel->setFont (Font (15.60f, Font::plain).withTypefaceStyle ("Regular"));
    knoblabel->setJustificationType (Justification::centredLeft);
    knoblabel->setEditable (false, false, false);
    knoblabel->setColour (TextEditor::textColourId, Colours::black);
    knoblabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (balance_knob = new Slider ("new slider"));
    balance_knob->setExplicitFocusOrder (1);
    balance_knob->setRange (0, 1, 0);
    balance_knob->setSliderStyle (Slider::RotaryHorizontalVerticalDrag);
    balance_knob->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    balance_knob->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (800, 600);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

InputSignalDragDrop::~InputSignalDragDrop()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    comboBox = nullptr;
    label = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    play_btn = nullptr;
    stop_btn = nullptr;
    textButton3 = nullptr;
    generate_btn = nullptr;
    label4 = nullptr;
    input_signal = nullptr;
    impulse_response = nullptr;
    convolved_signal = nullptr;
    knoblabel = nullptr;
    balance_knob = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void InputSignalDragDrop::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff7000e7));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void InputSignalDragDrop::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    comboBox->setBounds (proportionOfWidth (0.7876f), proportionOfHeight (0.0000f), proportionOfWidth (0.2110f), proportionOfHeight (0.0410f));
    label->setBounds (proportionOfWidth (0.1238f), proportionOfHeight (0.0819f), proportionOfWidth (0.1238f), proportionOfHeight (0.0410f));
    label2->setBounds (proportionOfWidth (0.7314f), proportionOfHeight (0.0819f), proportionOfWidth (0.1575f), proportionOfHeight (0.0410f));
    label3->setBounds (328, 312, 48, 24);
    play_btn->setBounds (proportionOfWidth (0.1350f), proportionOfHeight (0.8601f), proportionOfWidth (0.2110f), proportionOfHeight (0.0410f));
    stop_btn->setBounds (proportionOfWidth (0.3826f), proportionOfHeight (0.8601f), proportionOfWidth (0.2110f), proportionOfHeight (0.0410f));
    textButton3->setBounds (proportionOfWidth (0.6526f), proportionOfHeight (0.8601f), proportionOfWidth (0.2110f), proportionOfHeight (0.0410f));
    generate_btn->setBounds (proportionOfWidth (0.4163f), proportionOfHeight (0.4642f), proportionOfWidth (0.1463f), proportionOfHeight (0.0410f));
    label4->setBounds (proportionOfWidth (0.4163f), proportionOfHeight (0.0000f), proportionOfWidth (0.1575f), proportionOfHeight (0.0410f));
    input_signal->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.1365f), proportionOfWidth (0.3713f), proportionOfHeight (0.2730f));
    impulse_response->setBounds (proportionOfWidth (0.6189f), proportionOfHeight (0.1365f), proportionOfWidth (0.3713f), proportionOfHeight (0.2730f));
    convolved_signal->setBounds (proportionOfWidth (0.0000f), proportionOfHeight (0.5870f), proportionOfWidth (1.0014f), proportionOfHeight (0.2457f));
    knoblabel->setBounds (proportionOfWidth (0.4501f), proportionOfHeight (0.1911f), proportionOfWidth (0.0900f), proportionOfHeight (0.0410f));
    balance_knob->setBounds (proportionOfWidth (0.4051f), proportionOfHeight (0.2457f), proportionOfWidth (0.1688f), proportionOfHeight (0.1502f));
    //[UserResized] Add your own custom resize handling here..
    balance_knob->setValue(0.5);
    //[/UserResized]
}

void InputSignalDragDrop::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox)
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void InputSignalDragDrop::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == play_btn)
    {
        //[UserButtonCode_play_btn] -- add your button handler code here..
        //[/UserButtonCode_play_btn]
    }
    else if (buttonThatWasClicked == stop_btn)
    {
        //[UserButtonCode_stop_btn] -- add your button handler code here..
        //[/UserButtonCode_stop_btn]
    }
    else if (buttonThatWasClicked == textButton3)
    {
        //[UserButtonCode_textButton3] -- add your button handler code here..
        //[/UserButtonCode_textButton3]
    }
    else if (buttonThatWasClicked == generate_btn)
    {
        //[UserButtonCode_generate_btn] -- add your button handler code here..
        AudioPlayer::StartPlaying();
        //this->convolved_signal->convolveInput();
        //[/UserButtonCode_generate_btn]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void InputSignalDragDrop::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == balance_knob)
    {
        //[UserSliderCode_balance_knob] -- add your slider handling code here..
        AudioPlayer::setBalance(float(balance_knob->getValue()));
        //[/UserSliderCode_balance_knob]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="InputSignalDragDrop" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="800" initialHeight="600">
  <BACKGROUND backgroundColour="ff7000e7"/>
  <COMBOBOX name="new combo box" id="2df48afdde95becd" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="78.762% 0% 21.097% 4.096%"
            editable="0" layout="33" items="FIR&#10;FFT&#10;" textWhenNonSelected=""
            textWhenNoItems="FIR"/>
  <LABEL name="new label" id="7e501145e4d68d84" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="12.377% 8.191% 12.377% 4.096%" edTextCol="ff000000"
         edBkgCol="0" labelText="input signal" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="3a2472127aa01e06" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="73.136% 8.191% 15.752% 4.096%" edTextCol="ff000000"
         edBkgCol="0" labelText="impulse response" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="947256eccf805144" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="328 312 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="output" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         kerning="0" bold="0" italic="0" justification="33"/>
  <TEXTBUTTON name="new button" id="9828601046c46721" memberName="play_btn"
              virtualName="" explicitFocusOrder="0" pos="13.502% 86.007% 21.097% 4.096%"
              bgColOff="ff13c607" buttonText="play" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="e403bf2fb01af142" memberName="stop_btn"
              virtualName="" explicitFocusOrder="0" pos="38.256% 86.007% 21.097% 4.096%"
              bgColOff="ffdc143c" buttonText="stop" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="aa9a7381001db93b" memberName="textButton3"
              virtualName="" explicitFocusOrder="0" pos="65.26% 86.007% 21.097% 4.096%"
              bgColOff="ff0611d0" buttonText="save..." connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="54b07578b1563b5e" memberName="generate_btn"
              virtualName="" explicitFocusOrder="0" pos="41.632% 46.416% 14.627% 4.096%"
              bgColOff="ff680086" buttonText="generate" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <LABEL name="new label" id="155bf9d0f038cd6e" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="41.632% 0% 15.752% 4.096%" edTextCol="ff000000"
         edBkgCol="0" labelText="offline convolver" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" kerning="0" bold="0" italic="0" justification="33"/>
  <GENERICCOMPONENT name="input signal" id="40a5ca03491cd6a1" memberName="input_signal"
                    virtualName="" explicitFocusOrder="0" pos="0% 13.652% 37.131% 27.304%"
                    class="InputVisualizer" params="320, 160"/>
  <GENERICCOMPONENT name="impulse response" id="d326fe927b8ccec" memberName="impulse_response"
                    virtualName="" explicitFocusOrder="0" pos="61.885% 13.652% 37.131% 27.304%"
                    class="ImpulseVisualizer" params="320, 160"/>
  <GENERICCOMPONENT name="convolved signal" id="bf0184a07e7f25db" memberName="convolved_signal"
                    virtualName="" explicitFocusOrder="0" pos="0% 58.703% 100.141% 24.573%"
                    class="OutputVisualizer" params="528, 144, this-&gt;input_signal, this-&gt;impulse_response&#10;"/>
  <LABEL name="new label" id="fa94c46cf23083d" memberName="knoblabel"
         virtualName="" explicitFocusOrder="0" pos="45.007% 19.113% 9.001% 4.096%"
         edTextCol="ff000000" edBkgCol="0" labelText="balance" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15.599999999999999645" kerning="0" bold="0" italic="0"
         justification="33"/>
  <SLIDER name="new slider" id="5f2f30d110b8dfa5" memberName="balance_knob"
          virtualName="" explicitFocusOrder="1" pos="40.506% 24.573% 16.878% 15.017%"
          min="0" max="1" int="0" style="RotaryHorizontalVerticalDrag"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
