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
        default: break;
    }

    numBytes = 0;
    return nullptr;
}

const char* namedResourceList[] =
{
    "ComponentTemplates_xml"
};

const char* originalFilenames[] =
{
    "ComponentTemplates.xml"
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
