/* ==================================== JUCER_BINARY_RESOURCE ====================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#include <cstring>

namespace BinaryData
{

//================== ComponentTemplates.xml ==================
static const unsigned char temp_binary_data_0[] =
"<ComponentTemplates>\n"
"    \n"
"    <component label=\"Component\" type=\"juce::Component\" name=\"component\" x=\"0\" y=\"0\" width=\"100\" height=\"100\"/>\n"
"    \n"
"    <component label=\"TextButton\" type=\"juce::TextButton\" name=\"text button\" x=\"0\" y=\"0\" width=\"40\" height=\"24\" buttonText=\"text button\"/>\n"
"\n"
"    <component label=\"Checkbox\" type=\"juce::ToggleButton\" name=\"toggle button\" x=\"0\" y=\"0\" width=\"40\" height=\"24\" buttonText=\"toggle button\"/>\n"
"\n"
"    <component label=\"ImageButton\" type=\"juce::ImageButton\" name=\"image button\" x=\"416\" y=\"16\" width=\"24\" height=\"24\" buttonText=\"image button\"/>\n"
"\n"
"    <component label=\"DrawableButton\" type=\"juce::DrawableButton\" name=\"drawable button\" x=\"416\" y=\"16\" width=\"24\" height=\"24\" sourceFile=\"compress.svg\"/>\n"
"\n"
"    <component label=\"Label\" type=\"juce::Label\" name=\"label\" x=\"0\" y=\"0\" width=\"40\" height=\"24\" labelText=\"label\"/>\n"
"    \n"
"    <component label=\"TextEditor\" type=\"juce::TextEditor\" name=\"edittext\" x=\"0\" y=\"0\" width=\"200\" height=\"100\"/>\n"
"    \n"
"    <component label=\"HorizSlider\" type=\"juce::Slider\" name=\"horiz slider\" x=\"0\" y=\"0\" width=\"200\" height=\"24\" min=\"1\" max=\"10\" int=\"1\" style=\"LinearHorizontal\"/>\n"
"    \n"
"    <component label=\"VertSlider\" type=\"juce::Slider\" name=\"vert slider\" x=\"0\" y=\"0\" width=\"30\" height=\"183\" min=\"0\" max=\"100\" int=\"1\" style=\"LinearVertical\"/>\n"
"    \n"
"</ComponentTemplates>\n";

const char* ComponentTemplates_xml = (const char*) temp_binary_data_0;

//================== MainComponent.xml ==================
static const unsigned char temp_binary_data_1[] =
"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n"
"\r\n"
"<component type=\"MainComponent\" name=\"\" x=\"0\" y=\"0\" width=\"645\" height=\"357\"\r\n"
"           style=\"\">\r\n"
"  <component type=\"juce::Slider\" name=\"horiz slider\" x=\"17\" y=\"123\" width=\"200\"\r\n"
"             height=\"24\" style=\"\" min=\"1.0\" max=\"10.0\" int=\"1.0\" slider=\"LinearHorizontal\"/>\r\n"
"  <component type=\"juce::TextEditor\" name=\"edittext\" x=\"327\" y=\"18\" width=\"200\"\r\n"
"             height=\"100\" style=\"\">\r\n"
"    <component type=\"juce::TextEditor::TextEditorViewport\" name=\"\" x=\"1\" y=\"1\"\r\n"
"               width=\"196\" height=\"98\">\r\n"
"      <component type=\"juce::Viewport::AccessibilityIgnoredComponent\" name=\"\"\r\n"
"                 x=\"0\" y=\"0\" width=\"196\" height=\"98\">\r\n"
"        <component type=\"juce::TextEditor::TextHolderComponent\" name=\"\" x=\"0\" y=\"0\"\r\n"
"                   width=\"196\" height=\"18\">\r\n"
"          <component type=\"juce::CaretComponent\" name=\"\" x=\"4\" y=\"4\" width=\"2\" height=\"14\"/>\r\n"
"        </component>\r\n"
"      </component>\r\n"
"      <component type=\"juce::ScrollBar\" name=\"\" x=\"196\" y=\"0\" width=\"8\" height=\"98\"/>\r\n"
"      <component type=\"juce::ScrollBar\" name=\"\" x=\"0\" y=\"98\" width=\"196\" height=\"8\"/>\r\n"
"    </component>\r\n"
"  </component>\r\n"
"  <component type=\"juce::Label\" name=\"label\" x=\"0\" y=\"0\" width=\"40\" height=\"24\"\r\n"
"             style=\"\" labelText=\"label\"/>\r\n"
"  <component type=\"juce::TextButton\" name=\"text button\" x=\"8\" y=\"60\" width=\"40\"\r\n"
"             height=\"24\" style=\"\" buttonText=\"text button\"/>\r\n"
"  <component type=\"melatonin::FPSMeter\" name=\"\" x=\"0\" y=\"0\" width=\"0\" height=\"0\"/>\r\n"
"</component>\r\n";

const char* MainComponent_xml = (const char*) temp_binary_data_1;


const char* getNamedResource (const char* resourceNameUTF8, int& numBytes);
const char* getNamedResource (const char* resourceNameUTF8, int& numBytes)
{
    unsigned int hash = 0;

    if (resourceNameUTF8 != nullptr)
        while (*resourceNameUTF8 != 0)
            hash = 31 * hash + (unsigned int) *resourceNameUTF8++;

    switch (hash)
    {
        case 0x434c0034:  numBytes = 1324; return ComponentTemplates_xml;
        case 0x3902947c:  numBytes = 1529; return MainComponent_xml;
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "ComponentTemplates_xml",
    "MainComponent_xml"
};

const char* originalFilenames[] =
{
    "ComponentTemplates.xml",
    "MainComponent.xml"
};

const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8)
{
    for (unsigned int i = 0; i < (sizeof (namedResourceList) / sizeof (namedResourceList[0])); ++i)
        if (strcmp (namedResourceList[i], resourceNameUTF8) == 0)
            return originalFilenames[i];

    return nullptr;
}

}
