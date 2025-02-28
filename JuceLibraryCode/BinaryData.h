/* =========================================================================================

   This is an auto-generated file: Any edits you make may be overwritten!

*/

#pragma once

namespace BinaryData
{
    extern const char*   delete_svg;
    const int            delete_svgSize = 507;

    extern const char*   download_svg;
    const int            download_svgSize = 245;

    extern const char*   tackBottom_svg;
    const int            tackBottom_svgSize = 214;

    extern const char*   tackLeft_svg;
    const int            tackLeft_svgSize = 211;

    extern const char*   tackRight_svg;
    const int            tackRight_svgSize = 213;

    extern const char*   tackTop_svg;
    const int            tackTop_svgSize = 216;

    extern const char*   widgets_svg;
    const int            widgets_svgSize = 392;

    extern const char*   ComponentTemplates_xml;
    const int            ComponentTemplates_xmlSize = 1324;

    // Number of elements in the namedResourceList and originalFileNames arrays.
    const int namedResourceListSize = 8;

    // Points to the start of a list of resource names.
    extern const char* namedResourceList[];

    // Points to the start of a list of resource filenames.
    extern const char* originalFilenames[];

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding data and its size (or a null pointer if the name isn't found).
    const char* getNamedResource (const char* resourceNameUTF8, int& dataSizeInBytes);

    // If you provide the name of one of the binary resource variables above, this function will
    // return the corresponding original, non-mangled filename (or a null pointer if the name isn't found).
    const char* getNamedResourceOriginalFilename (const char* resourceNameUTF8);
}
