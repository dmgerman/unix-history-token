begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file defines the encoding for the VFR (Visual Form Representation) language.   IFR is primarily consumed by the EFI presentation engine, and produced by EFI   internal application and drivers as well as all add-in card option-ROM drivers  Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR> (C) Copyright 2016 Hewlett Packard Enterprise Development LP<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   These definitions are from UEFI 2.1 and 2.2.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__UEFI_INTERNAL_FORMREPRESENTATION_H__
end_ifndef

begin_define
define|#
directive|define
name|__UEFI_INTERNAL_FORMREPRESENTATION_H__
end_define

begin_include
include|#
directive|include
file|<Guid/HiiFormMapMethodGuid.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// The following types are currently defined:
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|VOID
modifier|*
name|EFI_HII_HANDLE
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|CHAR16
modifier|*
name|EFI_STRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT16
name|EFI_IMAGE_ID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT16
name|EFI_QUESTION_ID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT16
name|EFI_STRING_ID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT16
name|EFI_FORM_ID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT16
name|EFI_VARSTORE_ID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT16
name|EFI_ANIMATION_ID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT16
name|EFI_DEFAULT_ID
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|UINT32
name|EFI_HII_FONT_STYLE
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|1
name|)
end_pragma

begin_comment
comment|//
end_comment

begin_comment
comment|// Definitions for Package Lists and Package Headers
end_comment

begin_comment
comment|// Section 27.3.1
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The header found at the start of each package list.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_GUID
name|PackageListGuid
decl_stmt|;
name|UINT32
name|PackageLength
decl_stmt|;
block|}
name|EFI_HII_PACKAGE_LIST_HEADER
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The header found at the start of each package.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|Length
range|:
literal|24
decl_stmt|;
name|UINT32
name|Type
range|:
literal|8
decl_stmt|;
comment|// UINT8  Data[...];
block|}
name|EFI_HII_PACKAGE_HEADER
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Value of HII package type
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_HII_PACKAGE_TYPE_ALL
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_HII_PACKAGE_TYPE_GUID
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_HII_PACKAGE_FORMS
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_HII_PACKAGE_STRINGS
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_HII_PACKAGE_FONTS
value|0x05
end_define

begin_define
define|#
directive|define
name|EFI_HII_PACKAGE_IMAGES
value|0x06
end_define

begin_define
define|#
directive|define
name|EFI_HII_PACKAGE_SIMPLE_FONTS
value|0x07
end_define

begin_define
define|#
directive|define
name|EFI_HII_PACKAGE_DEVICE_PATH
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_HII_PACKAGE_KEYBOARD_LAYOUT
value|0x09
end_define

begin_define
define|#
directive|define
name|EFI_HII_PACKAGE_ANIMATIONS
value|0x0A
end_define

begin_define
define|#
directive|define
name|EFI_HII_PACKAGE_END
value|0xDF
end_define

begin_define
define|#
directive|define
name|EFI_HII_PACKAGE_TYPE_SYSTEM_BEGIN
value|0xE0
end_define

begin_define
define|#
directive|define
name|EFI_HII_PACKAGE_TYPE_SYSTEM_END
value|0xFF
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Definitions for Simplified Font Package
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Contents of EFI_NARROW_GLYPH.Attributes.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_GLYPH_NON_SPACING
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_GLYPH_WIDE
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_GLYPH_HEIGHT
value|19
end_define

begin_define
define|#
directive|define
name|EFI_GLYPH_WIDTH
value|8
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_NARROW_GLYPH has a preferred dimension (w x h) of 8 x 19 pixels.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The Unicode representation of the glyph. The term weight is the
comment|/// technical term for a character code.
comment|///
name|CHAR16
name|UnicodeWeight
decl_stmt|;
comment|///
comment|/// The data element containing the glyph definitions.
comment|///
name|UINT8
name|Attributes
decl_stmt|;
comment|///
comment|/// The column major glyph representation of the character. Bits
comment|/// with values of one indicate that the corresponding pixel is to be
comment|/// on when normally displayed; those with zero are off.
comment|///
name|UINT8
name|GlyphCol1
index|[
name|EFI_GLYPH_HEIGHT
index|]
decl_stmt|;
block|}
name|EFI_NARROW_GLYPH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_WIDE_GLYPH has a preferred dimension (w x h) of 16 x 19 pixels, which is large enough
end_comment

begin_comment
comment|/// to accommodate logographic characters.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The Unicode representation of the glyph. The term weight is the
comment|/// technical term for a character code.
comment|///
name|CHAR16
name|UnicodeWeight
decl_stmt|;
comment|///
comment|/// The data element containing the glyph definitions.
comment|///
name|UINT8
name|Attributes
decl_stmt|;
comment|///
comment|/// The column major glyph representation of the character. Bits
comment|/// with values of one indicate that the corresponding pixel is to be
comment|/// on when normally displayed; those with zero are off.
comment|///
name|UINT8
name|GlyphCol1
index|[
name|EFI_GLYPH_HEIGHT
index|]
decl_stmt|;
comment|///
comment|/// The column major glyph representation of the character. Bits
comment|/// with values of one indicate that the corresponding pixel is to be
comment|/// on when normally displayed; those with zero are off.
comment|///
name|UINT8
name|GlyphCol2
index|[
name|EFI_GLYPH_HEIGHT
index|]
decl_stmt|;
comment|///
comment|/// Ensures that sizeof (EFI_WIDE_GLYPH) is twice the
comment|/// sizeof (EFI_NARROW_GLYPH). The contents of Pad must
comment|/// be zero.
comment|///
name|UINT8
name|Pad
index|[
literal|3
index|]
decl_stmt|;
block|}
name|EFI_WIDE_GLYPH
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// A simplified font package consists of a font header
end_comment

begin_comment
comment|/// followed by a series of glyph structures.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_SIMPLE_FONT_PACKAGE_HDR
block|{
name|EFI_HII_PACKAGE_HEADER
name|Header
decl_stmt|;
name|UINT16
name|NumberOfNarrowGlyphs
decl_stmt|;
name|UINT16
name|NumberOfWideGlyphs
decl_stmt|;
comment|// EFI_NARROW_GLYPH       NarrowGlyphs[];
comment|// EFI_WIDE_GLYPH         WideGlyphs[];
block|}
name|EFI_HII_SIMPLE_FONT_PACKAGE_HDR
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Definitions for Font Package
end_comment

begin_comment
comment|// Section 27.3.3
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Value for font style
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_HII_FONT_STYLE_NORMAL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EFI_HII_FONT_STYLE_BOLD
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_HII_FONT_STYLE_ITALIC
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_HII_FONT_STYLE_EMBOSS
value|0x00010000
end_define

begin_define
define|#
directive|define
name|EFI_HII_FONT_STYLE_OUTLINE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|EFI_HII_FONT_STYLE_SHADOW
value|0x00040000
end_define

begin_define
define|#
directive|define
name|EFI_HII_FONT_STYLE_UNDERLINE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|EFI_HII_FONT_STYLE_DBL_UNDER
value|0x00100000
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_GLYPH_INFO
block|{
name|UINT16
name|Width
decl_stmt|;
name|UINT16
name|Height
decl_stmt|;
name|INT16
name|OffsetX
decl_stmt|;
name|INT16
name|OffsetY
decl_stmt|;
name|INT16
name|AdvanceX
decl_stmt|;
block|}
name|EFI_HII_GLYPH_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The fixed header consists of a standard record header,
end_comment

begin_comment
comment|/// then the character values in this section, the flags
end_comment

begin_comment
comment|/// (including the encoding method) and the offsets of the glyph
end_comment

begin_comment
comment|/// information, the glyph bitmaps and the character map.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_FONT_PACKAGE_HDR
block|{
name|EFI_HII_PACKAGE_HEADER
name|Header
decl_stmt|;
name|UINT32
name|HdrSize
decl_stmt|;
name|UINT32
name|GlyphBlockOffset
decl_stmt|;
name|EFI_HII_GLYPH_INFO
name|Cell
decl_stmt|;
name|EFI_HII_FONT_STYLE
name|FontStyle
decl_stmt|;
name|CHAR16
name|FontFamily
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_FONT_PACKAGE_HDR
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Value of different glyph info block types
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_HII_GIBT_END
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_HII_GIBT_GLYPH
value|0x10
end_define

begin_define
define|#
directive|define
name|EFI_HII_GIBT_GLYPHS
value|0x11
end_define

begin_define
define|#
directive|define
name|EFI_HII_GIBT_GLYPH_DEFAULT
value|0x12
end_define

begin_define
define|#
directive|define
name|EFI_HII_GIBT_GLYPHS_DEFAULT
value|0x13
end_define

begin_define
define|#
directive|define
name|EFI_HII_GIBT_GLYPH_VARIABILITY
value|0x14
end_define

begin_define
define|#
directive|define
name|EFI_HII_GIBT_DUPLICATE
value|0x20
end_define

begin_define
define|#
directive|define
name|EFI_HII_GIBT_SKIP2
value|0x21
end_define

begin_define
define|#
directive|define
name|EFI_HII_GIBT_SKIP1
value|0x22
end_define

begin_define
define|#
directive|define
name|EFI_HII_GIBT_DEFAULTS
value|0x23
end_define

begin_define
define|#
directive|define
name|EFI_HII_GIBT_EXT1
value|0x30
end_define

begin_define
define|#
directive|define
name|EFI_HII_GIBT_EXT2
value|0x31
end_define

begin_define
define|#
directive|define
name|EFI_HII_GIBT_EXT4
value|0x32
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_GLYPH_BLOCK
block|{
name|UINT8
name|BlockType
decl_stmt|;
block|}
name|EFI_HII_GLYPH_BLOCK
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Definition of different glyph info block types
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_GIBT_DEFAULTS_BLOCK
block|{
name|EFI_HII_GLYPH_BLOCK
name|Header
decl_stmt|;
name|EFI_HII_GLYPH_INFO
name|Cell
decl_stmt|;
block|}
name|EFI_HII_GIBT_DEFAULTS_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_GIBT_DUPLICATE_BLOCK
block|{
name|EFI_HII_GLYPH_BLOCK
name|Header
decl_stmt|;
name|CHAR16
name|CharValue
decl_stmt|;
block|}
name|EFI_HII_GIBT_DUPLICATE_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_GLYPH_GIBT_END_BLOCK
block|{
name|EFI_HII_GLYPH_BLOCK
name|Header
decl_stmt|;
block|}
name|EFI_GLYPH_GIBT_END_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_GIBT_EXT1_BLOCK
block|{
name|EFI_HII_GLYPH_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|BlockType2
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
block|}
name|EFI_HII_GIBT_EXT1_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_GIBT_EXT2_BLOCK
block|{
name|EFI_HII_GLYPH_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|BlockType2
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
block|}
name|EFI_HII_GIBT_EXT2_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_GIBT_EXT4_BLOCK
block|{
name|EFI_HII_GLYPH_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|BlockType2
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
block|}
name|EFI_HII_GIBT_EXT4_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_GIBT_GLYPH_BLOCK
block|{
name|EFI_HII_GLYPH_BLOCK
name|Header
decl_stmt|;
name|EFI_HII_GLYPH_INFO
name|Cell
decl_stmt|;
name|UINT8
name|BitmapData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_GIBT_GLYPH_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_GIBT_GLYPHS_BLOCK
block|{
name|EFI_HII_GLYPH_BLOCK
name|Header
decl_stmt|;
name|EFI_HII_GLYPH_INFO
name|Cell
decl_stmt|;
name|UINT16
name|Count
decl_stmt|;
name|UINT8
name|BitmapData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_GIBT_GLYPHS_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_GIBT_GLYPH_DEFAULT_BLOCK
block|{
name|EFI_HII_GLYPH_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|BitmapData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_GIBT_GLYPH_DEFAULT_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_GIBT_GLYPHS_DEFAULT_BLOCK
block|{
name|EFI_HII_GLYPH_BLOCK
name|Header
decl_stmt|;
name|UINT16
name|Count
decl_stmt|;
name|UINT8
name|BitmapData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_GIBT_GLYPHS_DEFAULT_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_GIBT_VARIABILITY_BLOCK
block|{
name|EFI_HII_GLYPH_BLOCK
name|Header
decl_stmt|;
name|EFI_HII_GLYPH_INFO
name|Cell
decl_stmt|;
name|UINT8
name|GlyphPackInBits
decl_stmt|;
name|UINT8
name|BitmapData
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_GIBT_VARIABILITY_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_GIBT_SKIP1_BLOCK
block|{
name|EFI_HII_GLYPH_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|SkipCount
decl_stmt|;
block|}
name|EFI_HII_GIBT_SKIP1_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_GIBT_SKIP2_BLOCK
block|{
name|EFI_HII_GLYPH_BLOCK
name|Header
decl_stmt|;
name|UINT16
name|SkipCount
decl_stmt|;
block|}
name|EFI_HII_GIBT_SKIP2_BLOCK
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Definitions for Device Path Package
end_comment

begin_comment
comment|// Section 27.3.4
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The device path package is used to carry a device path
end_comment

begin_comment
comment|/// associated with the package list.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_DEVICE_PATH_PACKAGE_HDR
block|{
name|EFI_HII_PACKAGE_HEADER
name|Header
decl_stmt|;
comment|// EFI_DEVICE_PATH_PROTOCOL DevicePath[];
block|}
name|EFI_HII_DEVICE_PATH_PACKAGE_HDR
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Definitions for GUID Package
end_comment

begin_comment
comment|// Section 27.3.5
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The GUID package is used to carry data where the format is defined by a GUID.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_GUID_PACKAGE_HDR
block|{
name|EFI_HII_PACKAGE_HEADER
name|Header
decl_stmt|;
name|EFI_GUID
name|Guid
decl_stmt|;
comment|// Data per GUID definition may follow
block|}
name|EFI_HII_GUID_PACKAGE_HDR
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Definitions for String Package
end_comment

begin_comment
comment|// Section 27.3.6
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|UEFI_CONFIG_LANG
value|"x-UEFI"
end_define

begin_define
define|#
directive|define
name|UEFI_CONFIG_LANG_2
value|"x-i-UEFI"
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// The fixed header consists of a standard record header and then the string identifiers
end_comment

begin_comment
comment|/// contained in this section and the offsets of the string and language information.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_STRING_PACKAGE_HDR
block|{
name|EFI_HII_PACKAGE_HEADER
name|Header
decl_stmt|;
name|UINT32
name|HdrSize
decl_stmt|;
name|UINT32
name|StringInfoOffset
decl_stmt|;
name|CHAR16
name|LanguageWindow
index|[
literal|16
index|]
decl_stmt|;
name|EFI_STRING_ID
name|LanguageName
decl_stmt|;
name|CHAR8
name|Language
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_STRING_PACKAGE_HDR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|BlockType
decl_stmt|;
block|}
name|EFI_HII_STRING_BLOCK
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Value of different string information block types
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_HII_SIBT_END
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_HII_SIBT_STRING_SCSU
value|0x10
end_define

begin_define
define|#
directive|define
name|EFI_HII_SIBT_STRING_SCSU_FONT
value|0x11
end_define

begin_define
define|#
directive|define
name|EFI_HII_SIBT_STRINGS_SCSU
value|0x12
end_define

begin_define
define|#
directive|define
name|EFI_HII_SIBT_STRINGS_SCSU_FONT
value|0x13
end_define

begin_define
define|#
directive|define
name|EFI_HII_SIBT_STRING_UCS2
value|0x14
end_define

begin_define
define|#
directive|define
name|EFI_HII_SIBT_STRING_UCS2_FONT
value|0x15
end_define

begin_define
define|#
directive|define
name|EFI_HII_SIBT_STRINGS_UCS2
value|0x16
end_define

begin_define
define|#
directive|define
name|EFI_HII_SIBT_STRINGS_UCS2_FONT
value|0x17
end_define

begin_define
define|#
directive|define
name|EFI_HII_SIBT_DUPLICATE
value|0x20
end_define

begin_define
define|#
directive|define
name|EFI_HII_SIBT_SKIP2
value|0x21
end_define

begin_define
define|#
directive|define
name|EFI_HII_SIBT_SKIP1
value|0x22
end_define

begin_define
define|#
directive|define
name|EFI_HII_SIBT_EXT1
value|0x30
end_define

begin_define
define|#
directive|define
name|EFI_HII_SIBT_EXT2
value|0x31
end_define

begin_define
define|#
directive|define
name|EFI_HII_SIBT_EXT4
value|0x32
end_define

begin_define
define|#
directive|define
name|EFI_HII_SIBT_FONT
value|0x40
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Definition of different string information block types
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_SIBT_DUPLICATE_BLOCK
block|{
name|EFI_HII_STRING_BLOCK
name|Header
decl_stmt|;
name|EFI_STRING_ID
name|StringId
decl_stmt|;
block|}
name|EFI_HII_SIBT_DUPLICATE_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_SIBT_END_BLOCK
block|{
name|EFI_HII_STRING_BLOCK
name|Header
decl_stmt|;
block|}
name|EFI_HII_SIBT_END_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_SIBT_EXT1_BLOCK
block|{
name|EFI_HII_STRING_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|BlockType2
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
block|}
name|EFI_HII_SIBT_EXT1_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_SIBT_EXT2_BLOCK
block|{
name|EFI_HII_STRING_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|BlockType2
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
block|}
name|EFI_HII_SIBT_EXT2_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_SIBT_EXT4_BLOCK
block|{
name|EFI_HII_STRING_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|BlockType2
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
block|}
name|EFI_HII_SIBT_EXT4_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_SIBT_FONT_BLOCK
block|{
name|EFI_HII_SIBT_EXT2_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|FontId
decl_stmt|;
name|UINT16
name|FontSize
decl_stmt|;
name|EFI_HII_FONT_STYLE
name|FontStyle
decl_stmt|;
name|CHAR16
name|FontName
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_SIBT_FONT_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_SIBT_SKIP1_BLOCK
block|{
name|EFI_HII_STRING_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|SkipCount
decl_stmt|;
block|}
name|EFI_HII_SIBT_SKIP1_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_SIBT_SKIP2_BLOCK
block|{
name|EFI_HII_STRING_BLOCK
name|Header
decl_stmt|;
name|UINT16
name|SkipCount
decl_stmt|;
block|}
name|EFI_HII_SIBT_SKIP2_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_SIBT_STRING_SCSU_BLOCK
block|{
name|EFI_HII_STRING_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|StringText
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_SIBT_STRING_SCSU_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_SIBT_STRING_SCSU_FONT_BLOCK
block|{
name|EFI_HII_STRING_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|FontIdentifier
decl_stmt|;
name|UINT8
name|StringText
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_SIBT_STRING_SCSU_FONT_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_SIBT_STRINGS_SCSU_BLOCK
block|{
name|EFI_HII_STRING_BLOCK
name|Header
decl_stmt|;
name|UINT16
name|StringCount
decl_stmt|;
name|UINT8
name|StringText
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_SIBT_STRINGS_SCSU_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_SIBT_STRINGS_SCSU_FONT_BLOCK
block|{
name|EFI_HII_STRING_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|FontIdentifier
decl_stmt|;
name|UINT16
name|StringCount
decl_stmt|;
name|UINT8
name|StringText
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_SIBT_STRINGS_SCSU_FONT_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_SIBT_STRING_UCS2_BLOCK
block|{
name|EFI_HII_STRING_BLOCK
name|Header
decl_stmt|;
name|CHAR16
name|StringText
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_SIBT_STRING_UCS2_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_SIBT_STRING_UCS2_FONT_BLOCK
block|{
name|EFI_HII_STRING_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|FontIdentifier
decl_stmt|;
name|CHAR16
name|StringText
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_SIBT_STRING_UCS2_FONT_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_SIBT_STRINGS_UCS2_BLOCK
block|{
name|EFI_HII_STRING_BLOCK
name|Header
decl_stmt|;
name|UINT16
name|StringCount
decl_stmt|;
name|CHAR16
name|StringText
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_SIBT_STRINGS_UCS2_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_SIBT_STRINGS_UCS2_FONT_BLOCK
block|{
name|EFI_HII_STRING_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|FontIdentifier
decl_stmt|;
name|UINT16
name|StringCount
decl_stmt|;
name|CHAR16
name|StringText
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_SIBT_STRINGS_UCS2_FONT_BLOCK
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Definitions for Image Package
end_comment

begin_comment
comment|// Section 27.3.7
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IMAGE_PACKAGE_HDR
block|{
name|EFI_HII_PACKAGE_HEADER
name|Header
decl_stmt|;
name|UINT32
name|ImageInfoOffset
decl_stmt|;
name|UINT32
name|PaletteInfoOffset
decl_stmt|;
block|}
name|EFI_HII_IMAGE_PACKAGE_HDR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IMAGE_BLOCK
block|{
name|UINT8
name|BlockType
decl_stmt|;
block|}
name|EFI_HII_IMAGE_BLOCK
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Value of different image information block types
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_HII_IIBT_END
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_HII_IIBT_IMAGE_1BIT
value|0x10
end_define

begin_define
define|#
directive|define
name|EFI_HII_IIBT_IMAGE_1BIT_TRANS
value|0x11
end_define

begin_define
define|#
directive|define
name|EFI_HII_IIBT_IMAGE_4BIT
value|0x12
end_define

begin_define
define|#
directive|define
name|EFI_HII_IIBT_IMAGE_4BIT_TRANS
value|0x13
end_define

begin_define
define|#
directive|define
name|EFI_HII_IIBT_IMAGE_8BIT
value|0x14
end_define

begin_define
define|#
directive|define
name|EFI_HII_IIBT_IMAGE_8BIT_TRANS
value|0x15
end_define

begin_define
define|#
directive|define
name|EFI_HII_IIBT_IMAGE_24BIT
value|0x16
end_define

begin_define
define|#
directive|define
name|EFI_HII_IIBT_IMAGE_24BIT_TRANS
value|0x17
end_define

begin_define
define|#
directive|define
name|EFI_HII_IIBT_IMAGE_JPEG
value|0x18
end_define

begin_define
define|#
directive|define
name|EFI_HII_IIBT_IMAGE_PNG
value|0x19
end_define

begin_define
define|#
directive|define
name|EFI_HII_IIBT_DUPLICATE
value|0x20
end_define

begin_define
define|#
directive|define
name|EFI_HII_IIBT_SKIP2
value|0x21
end_define

begin_define
define|#
directive|define
name|EFI_HII_IIBT_SKIP1
value|0x22
end_define

begin_define
define|#
directive|define
name|EFI_HII_IIBT_EXT1
value|0x30
end_define

begin_define
define|#
directive|define
name|EFI_HII_IIBT_EXT2
value|0x31
end_define

begin_define
define|#
directive|define
name|EFI_HII_IIBT_EXT4
value|0x32
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Definition of different image information block types
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_END_BLOCK
block|{
name|EFI_HII_IMAGE_BLOCK
name|Header
decl_stmt|;
block|}
name|EFI_HII_IIBT_END_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_EXT1_BLOCK
block|{
name|EFI_HII_IMAGE_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|BlockType2
decl_stmt|;
name|UINT8
name|Length
decl_stmt|;
block|}
name|EFI_HII_IIBT_EXT1_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_EXT2_BLOCK
block|{
name|EFI_HII_IMAGE_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|BlockType2
decl_stmt|;
name|UINT16
name|Length
decl_stmt|;
block|}
name|EFI_HII_IIBT_EXT2_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_EXT4_BLOCK
block|{
name|EFI_HII_IMAGE_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|BlockType2
decl_stmt|;
name|UINT32
name|Length
decl_stmt|;
block|}
name|EFI_HII_IIBT_EXT4_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_IMAGE_1BIT_BASE
block|{
name|UINT16
name|Width
decl_stmt|;
name|UINT16
name|Height
decl_stmt|;
name|UINT8
name|Data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_IIBT_IMAGE_1BIT_BASE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_IMAGE_1BIT_BLOCK
block|{
name|EFI_HII_IMAGE_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|PaletteIndex
decl_stmt|;
name|EFI_HII_IIBT_IMAGE_1BIT_BASE
name|Bitmap
decl_stmt|;
block|}
name|EFI_HII_IIBT_IMAGE_1BIT_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_IMAGE_1BIT_TRANS_BLOCK
block|{
name|EFI_HII_IMAGE_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|PaletteIndex
decl_stmt|;
name|EFI_HII_IIBT_IMAGE_1BIT_BASE
name|Bitmap
decl_stmt|;
block|}
name|EFI_HII_IIBT_IMAGE_1BIT_TRANS_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_RGB_PIXEL
block|{
name|UINT8
name|b
decl_stmt|;
name|UINT8
name|g
decl_stmt|;
name|UINT8
name|r
decl_stmt|;
block|}
name|EFI_HII_RGB_PIXEL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_IMAGE_24BIT_BASE
block|{
name|UINT16
name|Width
decl_stmt|;
name|UINT16
name|Height
decl_stmt|;
name|EFI_HII_RGB_PIXEL
name|Bitmap
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_IIBT_IMAGE_24BIT_BASE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_IMAGE_24BIT_BLOCK
block|{
name|EFI_HII_IMAGE_BLOCK
name|Header
decl_stmt|;
name|EFI_HII_IIBT_IMAGE_24BIT_BASE
name|Bitmap
decl_stmt|;
block|}
name|EFI_HII_IIBT_IMAGE_24BIT_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_IMAGE_24BIT_TRANS_BLOCK
block|{
name|EFI_HII_IMAGE_BLOCK
name|Header
decl_stmt|;
name|EFI_HII_IIBT_IMAGE_24BIT_BASE
name|Bitmap
decl_stmt|;
block|}
name|EFI_HII_IIBT_IMAGE_24BIT_TRANS_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_IMAGE_4BIT_BASE
block|{
name|UINT16
name|Width
decl_stmt|;
name|UINT16
name|Height
decl_stmt|;
name|UINT8
name|Data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_IIBT_IMAGE_4BIT_BASE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_IMAGE_4BIT_BLOCK
block|{
name|EFI_HII_IMAGE_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|PaletteIndex
decl_stmt|;
name|EFI_HII_IIBT_IMAGE_4BIT_BASE
name|Bitmap
decl_stmt|;
block|}
name|EFI_HII_IIBT_IMAGE_4BIT_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_IMAGE_4BIT_TRANS_BLOCK
block|{
name|EFI_HII_IMAGE_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|PaletteIndex
decl_stmt|;
name|EFI_HII_IIBT_IMAGE_4BIT_BASE
name|Bitmap
decl_stmt|;
block|}
name|EFI_HII_IIBT_IMAGE_4BIT_TRANS_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_IMAGE_8BIT_BASE
block|{
name|UINT16
name|Width
decl_stmt|;
name|UINT16
name|Height
decl_stmt|;
name|UINT8
name|Data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_IIBT_IMAGE_8BIT_BASE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_IMAGE_8BIT_PALETTE_BLOCK
block|{
name|EFI_HII_IMAGE_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|PaletteIndex
decl_stmt|;
name|EFI_HII_IIBT_IMAGE_8BIT_BASE
name|Bitmap
decl_stmt|;
block|}
name|EFI_HII_IIBT_IMAGE_8BIT_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_IMAGE_8BIT_TRANS_BLOCK
block|{
name|EFI_HII_IMAGE_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|PaletteIndex
decl_stmt|;
name|EFI_HII_IIBT_IMAGE_8BIT_BASE
name|Bitmap
decl_stmt|;
block|}
name|EFI_HII_IIBT_IMAGE_8BIT_TRAN_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_DUPLICATE_BLOCK
block|{
name|EFI_HII_IMAGE_BLOCK
name|Header
decl_stmt|;
name|EFI_IMAGE_ID
name|ImageId
decl_stmt|;
block|}
name|EFI_HII_IIBT_DUPLICATE_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_JPEG_BLOCK
block|{
name|EFI_HII_IMAGE_BLOCK
name|Header
decl_stmt|;
name|UINT32
name|Size
decl_stmt|;
name|UINT8
name|Data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_IIBT_JPEG_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_PNG_BLOCK
block|{
name|EFI_HII_IMAGE_BLOCK
name|Header
decl_stmt|;
name|UINT32
name|Size
decl_stmt|;
name|UINT8
name|Data
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_IIBT_PNG_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_SKIP1_BLOCK
block|{
name|EFI_HII_IMAGE_BLOCK
name|Header
decl_stmt|;
name|UINT8
name|SkipCount
decl_stmt|;
block|}
name|EFI_HII_IIBT_SKIP1_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IIBT_SKIP2_BLOCK
block|{
name|EFI_HII_IMAGE_BLOCK
name|Header
decl_stmt|;
name|UINT16
name|SkipCount
decl_stmt|;
block|}
name|EFI_HII_IIBT_SKIP2_BLOCK
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Definitions for Palette Information
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IMAGE_PALETTE_INFO_HEADER
block|{
name|UINT16
name|PaletteCount
decl_stmt|;
block|}
name|EFI_HII_IMAGE_PALETTE_INFO_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IMAGE_PALETTE_INFO
block|{
name|UINT16
name|PaletteSize
decl_stmt|;
name|EFI_HII_RGB_PIXEL
name|PaletteValue
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_IMAGE_PALETTE_INFO
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Definitions for Forms Package
end_comment

begin_comment
comment|// Section 27.3.8
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The Form package is used to carry form-based encoding data.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_FORM_PACKAGE_HDR
block|{
name|EFI_HII_PACKAGE_HEADER
name|Header
decl_stmt|;
comment|// EFI_IFR_OP_HEADER         OpCodeHeader;
comment|// More op-codes follow
block|}
name|EFI_HII_FORM_PACKAGE_HDR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Hour
decl_stmt|;
name|UINT8
name|Minute
decl_stmt|;
name|UINT8
name|Second
decl_stmt|;
block|}
name|EFI_HII_TIME
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|Year
decl_stmt|;
name|UINT8
name|Month
decl_stmt|;
name|UINT8
name|Day
decl_stmt|;
block|}
name|EFI_HII_DATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_QUESTION_ID
name|QuestionId
decl_stmt|;
name|EFI_FORM_ID
name|FormId
decl_stmt|;
name|EFI_GUID
name|FormSetGuid
decl_stmt|;
name|EFI_STRING_ID
name|DevicePath
decl_stmt|;
block|}
name|EFI_HII_REF
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|UINT8
name|u8
decl_stmt|;
name|UINT16
name|u16
decl_stmt|;
name|UINT32
name|u32
decl_stmt|;
name|UINT64
name|u64
decl_stmt|;
name|BOOLEAN
name|b
decl_stmt|;
name|EFI_HII_TIME
name|time
decl_stmt|;
name|EFI_HII_DATE
name|date
decl_stmt|;
name|EFI_STRING_ID
name|string
decl_stmt|;
comment|///< EFI_IFR_TYPE_STRING, EFI_IFR_TYPE_ACTION
name|EFI_HII_REF
name|ref
decl_stmt|;
comment|///< EFI_IFR_TYPE_REF
comment|// UINT8 buffer[];      ///< EFI_IFR_TYPE_BUFFER
block|}
name|EFI_IFR_TYPE_VALUE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// IFR Opcodes
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IFR_FORM_OP
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_IFR_SUBTITLE_OP
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TEXT_OP
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_IFR_IMAGE_OP
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_IFR_ONE_OF_OP
value|0x05
end_define

begin_define
define|#
directive|define
name|EFI_IFR_CHECKBOX_OP
value|0x06
end_define

begin_define
define|#
directive|define
name|EFI_IFR_NUMERIC_OP
value|0x07
end_define

begin_define
define|#
directive|define
name|EFI_IFR_PASSWORD_OP
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_IFR_ONE_OF_OPTION_OP
value|0x09
end_define

begin_define
define|#
directive|define
name|EFI_IFR_SUPPRESS_IF_OP
value|0x0A
end_define

begin_define
define|#
directive|define
name|EFI_IFR_LOCKED_OP
value|0x0B
end_define

begin_define
define|#
directive|define
name|EFI_IFR_ACTION_OP
value|0x0C
end_define

begin_define
define|#
directive|define
name|EFI_IFR_RESET_BUTTON_OP
value|0x0D
end_define

begin_define
define|#
directive|define
name|EFI_IFR_FORM_SET_OP
value|0x0E
end_define

begin_define
define|#
directive|define
name|EFI_IFR_REF_OP
value|0x0F
end_define

begin_define
define|#
directive|define
name|EFI_IFR_NO_SUBMIT_IF_OP
value|0x10
end_define

begin_define
define|#
directive|define
name|EFI_IFR_INCONSISTENT_IF_OP
value|0x11
end_define

begin_define
define|#
directive|define
name|EFI_IFR_EQ_ID_VAL_OP
value|0x12
end_define

begin_define
define|#
directive|define
name|EFI_IFR_EQ_ID_ID_OP
value|0x13
end_define

begin_define
define|#
directive|define
name|EFI_IFR_EQ_ID_VAL_LIST_OP
value|0x14
end_define

begin_define
define|#
directive|define
name|EFI_IFR_AND_OP
value|0x15
end_define

begin_define
define|#
directive|define
name|EFI_IFR_OR_OP
value|0x16
end_define

begin_define
define|#
directive|define
name|EFI_IFR_NOT_OP
value|0x17
end_define

begin_define
define|#
directive|define
name|EFI_IFR_RULE_OP
value|0x18
end_define

begin_define
define|#
directive|define
name|EFI_IFR_GRAY_OUT_IF_OP
value|0x19
end_define

begin_define
define|#
directive|define
name|EFI_IFR_DATE_OP
value|0x1A
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TIME_OP
value|0x1B
end_define

begin_define
define|#
directive|define
name|EFI_IFR_STRING_OP
value|0x1C
end_define

begin_define
define|#
directive|define
name|EFI_IFR_REFRESH_OP
value|0x1D
end_define

begin_define
define|#
directive|define
name|EFI_IFR_DISABLE_IF_OP
value|0x1E
end_define

begin_define
define|#
directive|define
name|EFI_IFR_ANIMATION_OP
value|0x1F
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TO_LOWER_OP
value|0x20
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TO_UPPER_OP
value|0x21
end_define

begin_define
define|#
directive|define
name|EFI_IFR_MAP_OP
value|0x22
end_define

begin_define
define|#
directive|define
name|EFI_IFR_ORDERED_LIST_OP
value|0x23
end_define

begin_define
define|#
directive|define
name|EFI_IFR_VARSTORE_OP
value|0x24
end_define

begin_define
define|#
directive|define
name|EFI_IFR_VARSTORE_NAME_VALUE_OP
value|0x25
end_define

begin_define
define|#
directive|define
name|EFI_IFR_VARSTORE_EFI_OP
value|0x26
end_define

begin_define
define|#
directive|define
name|EFI_IFR_VARSTORE_DEVICE_OP
value|0x27
end_define

begin_define
define|#
directive|define
name|EFI_IFR_VERSION_OP
value|0x28
end_define

begin_define
define|#
directive|define
name|EFI_IFR_END_OP
value|0x29
end_define

begin_define
define|#
directive|define
name|EFI_IFR_MATCH_OP
value|0x2A
end_define

begin_define
define|#
directive|define
name|EFI_IFR_GET_OP
value|0x2B
end_define

begin_define
define|#
directive|define
name|EFI_IFR_SET_OP
value|0x2C
end_define

begin_define
define|#
directive|define
name|EFI_IFR_READ_OP
value|0x2D
end_define

begin_define
define|#
directive|define
name|EFI_IFR_WRITE_OP
value|0x2E
end_define

begin_define
define|#
directive|define
name|EFI_IFR_EQUAL_OP
value|0x2F
end_define

begin_define
define|#
directive|define
name|EFI_IFR_NOT_EQUAL_OP
value|0x30
end_define

begin_define
define|#
directive|define
name|EFI_IFR_GREATER_THAN_OP
value|0x31
end_define

begin_define
define|#
directive|define
name|EFI_IFR_GREATER_EQUAL_OP
value|0x32
end_define

begin_define
define|#
directive|define
name|EFI_IFR_LESS_THAN_OP
value|0x33
end_define

begin_define
define|#
directive|define
name|EFI_IFR_LESS_EQUAL_OP
value|0x34
end_define

begin_define
define|#
directive|define
name|EFI_IFR_BITWISE_AND_OP
value|0x35
end_define

begin_define
define|#
directive|define
name|EFI_IFR_BITWISE_OR_OP
value|0x36
end_define

begin_define
define|#
directive|define
name|EFI_IFR_BITWISE_NOT_OP
value|0x37
end_define

begin_define
define|#
directive|define
name|EFI_IFR_SHIFT_LEFT_OP
value|0x38
end_define

begin_define
define|#
directive|define
name|EFI_IFR_SHIFT_RIGHT_OP
value|0x39
end_define

begin_define
define|#
directive|define
name|EFI_IFR_ADD_OP
value|0x3A
end_define

begin_define
define|#
directive|define
name|EFI_IFR_SUBTRACT_OP
value|0x3B
end_define

begin_define
define|#
directive|define
name|EFI_IFR_MULTIPLY_OP
value|0x3C
end_define

begin_define
define|#
directive|define
name|EFI_IFR_DIVIDE_OP
value|0x3D
end_define

begin_define
define|#
directive|define
name|EFI_IFR_MODULO_OP
value|0x3E
end_define

begin_define
define|#
directive|define
name|EFI_IFR_RULE_REF_OP
value|0x3F
end_define

begin_define
define|#
directive|define
name|EFI_IFR_QUESTION_REF1_OP
value|0x40
end_define

begin_define
define|#
directive|define
name|EFI_IFR_QUESTION_REF2_OP
value|0x41
end_define

begin_define
define|#
directive|define
name|EFI_IFR_UINT8_OP
value|0x42
end_define

begin_define
define|#
directive|define
name|EFI_IFR_UINT16_OP
value|0x43
end_define

begin_define
define|#
directive|define
name|EFI_IFR_UINT32_OP
value|0x44
end_define

begin_define
define|#
directive|define
name|EFI_IFR_UINT64_OP
value|0x45
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TRUE_OP
value|0x46
end_define

begin_define
define|#
directive|define
name|EFI_IFR_FALSE_OP
value|0x47
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TO_UINT_OP
value|0x48
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TO_STRING_OP
value|0x49
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TO_BOOLEAN_OP
value|0x4A
end_define

begin_define
define|#
directive|define
name|EFI_IFR_MID_OP
value|0x4B
end_define

begin_define
define|#
directive|define
name|EFI_IFR_FIND_OP
value|0x4C
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TOKEN_OP
value|0x4D
end_define

begin_define
define|#
directive|define
name|EFI_IFR_STRING_REF1_OP
value|0x4E
end_define

begin_define
define|#
directive|define
name|EFI_IFR_STRING_REF2_OP
value|0x4F
end_define

begin_define
define|#
directive|define
name|EFI_IFR_CONDITIONAL_OP
value|0x50
end_define

begin_define
define|#
directive|define
name|EFI_IFR_QUESTION_REF3_OP
value|0x51
end_define

begin_define
define|#
directive|define
name|EFI_IFR_ZERO_OP
value|0x52
end_define

begin_define
define|#
directive|define
name|EFI_IFR_ONE_OP
value|0x53
end_define

begin_define
define|#
directive|define
name|EFI_IFR_ONES_OP
value|0x54
end_define

begin_define
define|#
directive|define
name|EFI_IFR_UNDEFINED_OP
value|0x55
end_define

begin_define
define|#
directive|define
name|EFI_IFR_LENGTH_OP
value|0x56
end_define

begin_define
define|#
directive|define
name|EFI_IFR_DUP_OP
value|0x57
end_define

begin_define
define|#
directive|define
name|EFI_IFR_THIS_OP
value|0x58
end_define

begin_define
define|#
directive|define
name|EFI_IFR_SPAN_OP
value|0x59
end_define

begin_define
define|#
directive|define
name|EFI_IFR_VALUE_OP
value|0x5A
end_define

begin_define
define|#
directive|define
name|EFI_IFR_DEFAULT_OP
value|0x5B
end_define

begin_define
define|#
directive|define
name|EFI_IFR_DEFAULTSTORE_OP
value|0x5C
end_define

begin_define
define|#
directive|define
name|EFI_IFR_FORM_MAP_OP
value|0x5D
end_define

begin_define
define|#
directive|define
name|EFI_IFR_CATENATE_OP
value|0x5E
end_define

begin_define
define|#
directive|define
name|EFI_IFR_GUID_OP
value|0x5F
end_define

begin_define
define|#
directive|define
name|EFI_IFR_SECURITY_OP
value|0x60
end_define

begin_define
define|#
directive|define
name|EFI_IFR_MODAL_TAG_OP
value|0x61
end_define

begin_define
define|#
directive|define
name|EFI_IFR_REFRESH_ID_OP
value|0x62
end_define

begin_define
define|#
directive|define
name|EFI_IFR_WARNING_IF_OP
value|0x63
end_define

begin_define
define|#
directive|define
name|EFI_IFR_MATCH2_OP
value|0x64
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Definitions of IFR Standard Headers
end_comment

begin_comment
comment|// Section 27.3.8.2
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_OP_HEADER
block|{
name|UINT8
name|OpCode
decl_stmt|;
name|UINT8
name|Length
range|:
literal|7
decl_stmt|;
name|UINT8
name|Scope
range|:
literal|1
decl_stmt|;
block|}
name|EFI_IFR_OP_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_STATEMENT_HEADER
block|{
name|EFI_STRING_ID
name|Prompt
decl_stmt|;
name|EFI_STRING_ID
name|Help
decl_stmt|;
block|}
name|EFI_IFR_STATEMENT_HEADER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_QUESTION_HEADER
block|{
name|EFI_IFR_STATEMENT_HEADER
name|Header
decl_stmt|;
name|EFI_QUESTION_ID
name|QuestionId
decl_stmt|;
name|EFI_VARSTORE_ID
name|VarStoreId
decl_stmt|;
union|union
block|{
name|EFI_STRING_ID
name|VarName
decl_stmt|;
name|UINT16
name|VarOffset
decl_stmt|;
block|}
name|VarStoreInfo
union|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|EFI_IFR_QUESTION_HEADER
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Flag values of EFI_IFR_QUESTION_HEADER
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IFR_FLAG_READ_ONLY
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_IFR_FLAG_CALLBACK
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_IFR_FLAG_RESET_REQUIRED
value|0x10
end_define

begin_define
define|#
directive|define
name|EFI_IFR_FLAG_RECONNECT_REQUIRED
value|0x40
end_define

begin_define
define|#
directive|define
name|EFI_IFR_FLAG_OPTIONS_ONLY
value|0x80
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Definition for Opcode Reference
end_comment

begin_comment
comment|// Section 27.3.8.3
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_DEFAULTSTORE
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_STRING_ID
name|DefaultName
decl_stmt|;
name|UINT16
name|DefaultId
decl_stmt|;
block|}
name|EFI_IFR_DEFAULTSTORE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Default Identifier of default store
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_HII_DEFAULT_CLASS_STANDARD
value|0x0000
end_define

begin_define
define|#
directive|define
name|EFI_HII_DEFAULT_CLASS_MANUFACTURING
value|0x0001
end_define

begin_define
define|#
directive|define
name|EFI_HII_DEFAULT_CLASS_SAFE
value|0x0002
end_define

begin_define
define|#
directive|define
name|EFI_HII_DEFAULT_CLASS_PLATFORM_BEGIN
value|0x4000
end_define

begin_define
define|#
directive|define
name|EFI_HII_DEFAULT_CLASS_PLATFORM_END
value|0x7fff
end_define

begin_define
define|#
directive|define
name|EFI_HII_DEFAULT_CLASS_HARDWARE_BEGIN
value|0x8000
end_define

begin_define
define|#
directive|define
name|EFI_HII_DEFAULT_CLASS_HARDWARE_END
value|0xbfff
end_define

begin_define
define|#
directive|define
name|EFI_HII_DEFAULT_CLASS_FIRMWARE_BEGIN
value|0xc000
end_define

begin_define
define|#
directive|define
name|EFI_HII_DEFAULT_CLASS_FIRMWARE_END
value|0xffff
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_VARSTORE
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_GUID
name|Guid
decl_stmt|;
name|EFI_VARSTORE_ID
name|VarStoreId
decl_stmt|;
name|UINT16
name|Size
decl_stmt|;
name|UINT8
name|Name
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_IFR_VARSTORE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_VARSTORE_EFI
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_VARSTORE_ID
name|VarStoreId
decl_stmt|;
name|EFI_GUID
name|Guid
decl_stmt|;
name|UINT32
name|Attributes
decl_stmt|;
name|UINT16
name|Size
decl_stmt|;
name|UINT8
name|Name
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_IFR_VARSTORE_EFI
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_VARSTORE_NAME_VALUE
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_VARSTORE_ID
name|VarStoreId
decl_stmt|;
name|EFI_GUID
name|Guid
decl_stmt|;
block|}
name|EFI_IFR_VARSTORE_NAME_VALUE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_FORM_SET
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_GUID
name|Guid
decl_stmt|;
name|EFI_STRING_ID
name|FormSetTitle
decl_stmt|;
name|EFI_STRING_ID
name|Help
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
comment|// EFI_GUID              ClassGuid[];
block|}
name|EFI_IFR_FORM_SET
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_END
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_END
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_FORM
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|UINT16
name|FormId
decl_stmt|;
name|EFI_STRING_ID
name|FormTitle
decl_stmt|;
block|}
name|EFI_IFR_FORM
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_IMAGE
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_IMAGE_ID
name|Id
decl_stmt|;
block|}
name|EFI_IFR_IMAGE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_MODAL_TAG
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_MODAL_TAG
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_LOCKED
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_LOCKED
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_RULE
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|UINT8
name|RuleId
decl_stmt|;
block|}
name|EFI_IFR_RULE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_DEFAULT
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|UINT16
name|DefaultId
decl_stmt|;
name|UINT8
name|Type
decl_stmt|;
name|EFI_IFR_TYPE_VALUE
name|Value
decl_stmt|;
block|}
name|EFI_IFR_DEFAULT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_DEFAULT_2
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|UINT16
name|DefaultId
decl_stmt|;
name|UINT8
name|Type
decl_stmt|;
block|}
name|EFI_IFR_DEFAULT_2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_VALUE
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_VALUE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_SUBTITLE
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_IFR_STATEMENT_HEADER
name|Statement
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|EFI_IFR_SUBTITLE
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_IFR_FLAGS_HORIZONTAL
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_CHECKBOX
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_IFR_QUESTION_HEADER
name|Question
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|EFI_IFR_CHECKBOX
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_IFR_CHECKBOX_DEFAULT
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_IFR_CHECKBOX_DEFAULT_MFG
value|0x02
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_TEXT
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_IFR_STATEMENT_HEADER
name|Statement
decl_stmt|;
name|EFI_STRING_ID
name|TextTwo
decl_stmt|;
block|}
name|EFI_IFR_TEXT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_REF
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_IFR_QUESTION_HEADER
name|Question
decl_stmt|;
name|EFI_FORM_ID
name|FormId
decl_stmt|;
block|}
name|EFI_IFR_REF
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_REF2
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_IFR_QUESTION_HEADER
name|Question
decl_stmt|;
name|EFI_FORM_ID
name|FormId
decl_stmt|;
name|EFI_QUESTION_ID
name|QuestionId
decl_stmt|;
block|}
name|EFI_IFR_REF2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_REF3
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_IFR_QUESTION_HEADER
name|Question
decl_stmt|;
name|EFI_FORM_ID
name|FormId
decl_stmt|;
name|EFI_QUESTION_ID
name|QuestionId
decl_stmt|;
name|EFI_GUID
name|FormSetId
decl_stmt|;
block|}
name|EFI_IFR_REF3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_REF4
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_IFR_QUESTION_HEADER
name|Question
decl_stmt|;
name|EFI_FORM_ID
name|FormId
decl_stmt|;
name|EFI_QUESTION_ID
name|QuestionId
decl_stmt|;
name|EFI_GUID
name|FormSetId
decl_stmt|;
name|EFI_STRING_ID
name|DevicePath
decl_stmt|;
block|}
name|EFI_IFR_REF4
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_REF5
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_IFR_QUESTION_HEADER
name|Question
decl_stmt|;
block|}
name|EFI_IFR_REF5
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_RESET_BUTTON
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_IFR_STATEMENT_HEADER
name|Statement
decl_stmt|;
name|EFI_DEFAULT_ID
name|DefaultId
decl_stmt|;
block|}
name|EFI_IFR_RESET_BUTTON
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_ACTION
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_IFR_QUESTION_HEADER
name|Question
decl_stmt|;
name|EFI_STRING_ID
name|QuestionConfig
decl_stmt|;
block|}
name|EFI_IFR_ACTION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_ACTION_1
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_IFR_QUESTION_HEADER
name|Question
decl_stmt|;
block|}
name|EFI_IFR_ACTION_1
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_DATE
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_IFR_QUESTION_HEADER
name|Question
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|EFI_IFR_DATE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Flags that describe the behavior of the question.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_QF_DATE_YEAR_SUPPRESS
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_QF_DATE_MONTH_SUPPRESS
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_QF_DATE_DAY_SUPPRESS
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_QF_DATE_STORAGE
value|0x30
end_define

begin_define
define|#
directive|define
name|QF_DATE_STORAGE_NORMAL
value|0x00
end_define

begin_define
define|#
directive|define
name|QF_DATE_STORAGE_TIME
value|0x10
end_define

begin_define
define|#
directive|define
name|QF_DATE_STORAGE_WAKEUP
value|0x20
end_define

begin_typedef
typedef|typedef
union|union
block|{
struct|struct
block|{
name|UINT8
name|MinValue
decl_stmt|;
name|UINT8
name|MaxValue
decl_stmt|;
name|UINT8
name|Step
decl_stmt|;
block|}
name|u8
struct|;
struct|struct
block|{
name|UINT16
name|MinValue
decl_stmt|;
name|UINT16
name|MaxValue
decl_stmt|;
name|UINT16
name|Step
decl_stmt|;
block|}
name|u16
struct|;
struct|struct
block|{
name|UINT32
name|MinValue
decl_stmt|;
name|UINT32
name|MaxValue
decl_stmt|;
name|UINT32
name|Step
decl_stmt|;
block|}
name|u32
struct|;
struct|struct
block|{
name|UINT64
name|MinValue
decl_stmt|;
name|UINT64
name|MaxValue
decl_stmt|;
name|UINT64
name|Step
decl_stmt|;
block|}
name|u64
struct|;
block|}
name|MINMAXSTEP_DATA
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_NUMERIC
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_IFR_QUESTION_HEADER
name|Question
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|MINMAXSTEP_DATA
name|data
decl_stmt|;
block|}
name|EFI_IFR_NUMERIC
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Flags related to the numeric question
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IFR_NUMERIC_SIZE
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_IFR_NUMERIC_SIZE_1
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_IFR_NUMERIC_SIZE_2
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_IFR_NUMERIC_SIZE_4
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_IFR_NUMERIC_SIZE_8
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_IFR_DISPLAY
value|0x30
end_define

begin_define
define|#
directive|define
name|EFI_IFR_DISPLAY_INT_DEC
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_IFR_DISPLAY_UINT_DEC
value|0x10
end_define

begin_define
define|#
directive|define
name|EFI_IFR_DISPLAY_UINT_HEX
value|0x20
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_ONE_OF
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_IFR_QUESTION_HEADER
name|Question
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|MINMAXSTEP_DATA
name|data
decl_stmt|;
block|}
name|EFI_IFR_ONE_OF
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_STRING
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_IFR_QUESTION_HEADER
name|Question
decl_stmt|;
name|UINT8
name|MinSize
decl_stmt|;
name|UINT8
name|MaxSize
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|EFI_IFR_STRING
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_IFR_STRING_MULTI_LINE
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_PASSWORD
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_IFR_QUESTION_HEADER
name|Question
decl_stmt|;
name|UINT16
name|MinSize
decl_stmt|;
name|UINT16
name|MaxSize
decl_stmt|;
block|}
name|EFI_IFR_PASSWORD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_ORDERED_LIST
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_IFR_QUESTION_HEADER
name|Question
decl_stmt|;
name|UINT8
name|MaxContainers
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|EFI_IFR_ORDERED_LIST
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_IFR_UNIQUE_SET
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_IFR_NO_EMPTY_SET
value|0x02
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_TIME
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_IFR_QUESTION_HEADER
name|Question
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|EFI_IFR_TIME
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// A bit-mask that determines which unique settings are active for this opcode.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|QF_TIME_HOUR_SUPPRESS
value|0x01
end_define

begin_define
define|#
directive|define
name|QF_TIME_MINUTE_SUPPRESS
value|0x02
end_define

begin_define
define|#
directive|define
name|QF_TIME_SECOND_SUPPRESS
value|0x04
end_define

begin_define
define|#
directive|define
name|QF_TIME_STORAGE
value|0x30
end_define

begin_define
define|#
directive|define
name|QF_TIME_STORAGE_NORMAL
value|0x00
end_define

begin_define
define|#
directive|define
name|QF_TIME_STORAGE_TIME
value|0x10
end_define

begin_define
define|#
directive|define
name|QF_TIME_STORAGE_WAKEUP
value|0x20
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_DISABLE_IF
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_DISABLE_IF
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_SUPPRESS_IF
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_SUPPRESS_IF
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_GRAY_OUT_IF
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_GRAY_OUT_IF
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_INCONSISTENT_IF
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_STRING_ID
name|Error
decl_stmt|;
block|}
name|EFI_IFR_INCONSISTENT_IF
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_NO_SUBMIT_IF
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_STRING_ID
name|Error
decl_stmt|;
block|}
name|EFI_IFR_NO_SUBMIT_IF
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_WARNING_IF
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_STRING_ID
name|Warning
decl_stmt|;
name|UINT8
name|TimeOut
decl_stmt|;
block|}
name|EFI_IFR_WARNING_IF
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_REFRESH
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|UINT8
name|RefreshInterval
decl_stmt|;
block|}
name|EFI_IFR_REFRESH
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_VARSTORE_DEVICE
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_STRING_ID
name|DevicePath
decl_stmt|;
block|}
name|EFI_IFR_VARSTORE_DEVICE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_ONE_OF_OPTION
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_STRING_ID
name|Option
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
name|UINT8
name|Type
decl_stmt|;
name|EFI_IFR_TYPE_VALUE
name|Value
decl_stmt|;
block|}
name|EFI_IFR_ONE_OF_OPTION
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Types of the option's value.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IFR_TYPE_NUM_SIZE_8
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TYPE_NUM_SIZE_16
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TYPE_NUM_SIZE_32
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TYPE_NUM_SIZE_64
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TYPE_BOOLEAN
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TYPE_TIME
value|0x05
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TYPE_DATE
value|0x06
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TYPE_STRING
value|0x07
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TYPE_OTHER
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TYPE_UNDEFINED
value|0x09
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TYPE_ACTION
value|0x0A
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TYPE_BUFFER
value|0x0B
end_define

begin_define
define|#
directive|define
name|EFI_IFR_TYPE_REF
value|0x0C
end_define

begin_define
define|#
directive|define
name|EFI_IFR_OPTION_DEFAULT
value|0x10
end_define

begin_define
define|#
directive|define
name|EFI_IFR_OPTION_DEFAULT_MFG
value|0x20
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_GUID
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_GUID
name|Guid
decl_stmt|;
comment|//Optional Data Follows
block|}
name|EFI_IFR_GUID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_REFRESH_ID
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_GUID
name|RefreshEventGroupId
decl_stmt|;
block|}
name|EFI_IFR_REFRESH_ID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_DUP
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_DUP
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_EQ_ID_ID
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_QUESTION_ID
name|QuestionId1
decl_stmt|;
name|EFI_QUESTION_ID
name|QuestionId2
decl_stmt|;
block|}
name|EFI_IFR_EQ_ID_ID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_EQ_ID_VAL
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_QUESTION_ID
name|QuestionId
decl_stmt|;
name|UINT16
name|Value
decl_stmt|;
block|}
name|EFI_IFR_EQ_ID_VAL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_EQ_ID_VAL_LIST
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_QUESTION_ID
name|QuestionId
decl_stmt|;
name|UINT16
name|ListLength
decl_stmt|;
name|UINT16
name|ValueList
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_IFR_EQ_ID_VAL_LIST
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_UINT8
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Value
decl_stmt|;
block|}
name|EFI_IFR_UINT8
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_UINT16
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Value
decl_stmt|;
block|}
name|EFI_IFR_UINT16
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_UINT32
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|UINT32
name|Value
decl_stmt|;
block|}
name|EFI_IFR_UINT32
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_UINT64
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|UINT64
name|Value
decl_stmt|;
block|}
name|EFI_IFR_UINT64
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_QUESTION_REF1
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_QUESTION_ID
name|QuestionId
decl_stmt|;
block|}
name|EFI_IFR_QUESTION_REF1
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_QUESTION_REF2
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_QUESTION_REF2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_QUESTION_REF3
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_QUESTION_REF3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_QUESTION_REF3_2
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_STRING_ID
name|DevicePath
decl_stmt|;
block|}
name|EFI_IFR_QUESTION_REF3_2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_QUESTION_REF3_3
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_STRING_ID
name|DevicePath
decl_stmt|;
name|EFI_GUID
name|Guid
decl_stmt|;
block|}
name|EFI_IFR_QUESTION_REF3_3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_RULE_REF
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|UINT8
name|RuleId
decl_stmt|;
block|}
name|EFI_IFR_RULE_REF
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_STRING_REF1
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_STRING_ID
name|StringId
decl_stmt|;
block|}
name|EFI_IFR_STRING_REF1
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_STRING_REF2
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_STRING_REF2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_THIS
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_THIS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_TRUE
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_TRUE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_FALSE
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_FALSE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_ONE
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_ONE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_ONES
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_ONES
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_ZERO
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_ZERO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_UNDEFINED
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_UNDEFINED
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_VERSION
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_VERSION
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_LENGTH
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_LENGTH
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_NOT
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_NOT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_BITWISE_NOT
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_BITWISE_NOT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_TO_BOOLEAN
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_TO_BOOLEAN
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// For EFI_IFR_TO_STRING, when converting from
end_comment

begin_comment
comment|/// unsigned integers, these flags control the format:
end_comment

begin_comment
comment|/// 0 = unsigned decimal.
end_comment

begin_comment
comment|/// 1 = signed decimal.
end_comment

begin_comment
comment|/// 2 = hexadecimal (lower-case alpha).
end_comment

begin_comment
comment|/// 3 = hexadecimal (upper-case alpha).
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_IFR_STRING_UNSIGNED_DEC
value|0
end_define

begin_define
define|#
directive|define
name|EFI_IFR_STRING_SIGNED_DEC
value|1
end_define

begin_define
define|#
directive|define
name|EFI_IFR_STRING_LOWERCASE_HEX
value|2
end_define

begin_define
define|#
directive|define
name|EFI_IFR_STRING_UPPERCASE_HEX
value|3
end_define

begin_comment
comment|///@}
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// When converting from a buffer, these flags control the format:
end_comment

begin_comment
comment|/// 0 = ASCII.
end_comment

begin_comment
comment|/// 8 = Unicode.
end_comment

begin_comment
comment|///@{
end_comment

begin_define
define|#
directive|define
name|EFI_IFR_STRING_ASCII
value|0
end_define

begin_define
define|#
directive|define
name|EFI_IFR_STRING_UNICODE
value|8
end_define

begin_comment
comment|///@}
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_TO_STRING
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Format
decl_stmt|;
block|}
name|EFI_IFR_TO_STRING
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_TO_UINT
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_TO_UINT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_TO_UPPER
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_TO_UPPER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_TO_LOWER
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_TO_LOWER
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_ADD
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_ADD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_AND
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_AND
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_BITWISE_AND
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_BITWISE_AND
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_BITWISE_OR
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_BITWISE_OR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_CATENATE
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_CATENATE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_DIVIDE
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_DIVIDE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_EQUAL
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_EQUAL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_GREATER_EQUAL
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_GREATER_EQUAL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_GREATER_THAN
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_GREATER_THAN
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_LESS_EQUAL
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_LESS_EQUAL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_LESS_THAN
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_LESS_THAN
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_MATCH
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_MATCH
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_MATCH2
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|EFI_GUID
name|SyntaxType
decl_stmt|;
block|}
name|EFI_IFR_MATCH2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_MULTIPLY
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_MULTIPLY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_MODULO
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_MODULO
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_NOT_EQUAL
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_NOT_EQUAL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_OR
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_OR
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_SHIFT_LEFT
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_SHIFT_LEFT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_SHIFT_RIGHT
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_SHIFT_RIGHT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_SUBTRACT
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_SUBTRACT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_CONDITIONAL
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_CONDITIONAL
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Flags governing the matching criteria of EFI_IFR_FIND
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IFR_FF_CASE_SENSITIVE
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_IFR_FF_CASE_INSENSITIVE
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_FIND
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Format
decl_stmt|;
block|}
name|EFI_IFR_FIND
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_MID
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_MID
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_TOKEN
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_TOKEN
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Flags specifying whether to find the first matching string
end_comment

begin_comment
comment|// or the first non-matching string.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_IFR_FLAGS_FIRST_MATCHING
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_IFR_FLAGS_FIRST_NON_MATCHING
value|0x01
end_define

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_SPAN
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
name|UINT8
name|Flags
decl_stmt|;
block|}
name|EFI_IFR_SPAN
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_SECURITY
block|{
comment|///
comment|/// Standard opcode header, where Header.Op = EFI_IFR_SECURITY_OP.
comment|///
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// Security permission level.
comment|///
name|EFI_GUID
name|Permissions
decl_stmt|;
block|}
name|EFI_IFR_SECURITY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_FORM_MAP_METHOD
block|{
comment|///
comment|/// The string identifier which provides the human-readable name of
comment|/// the configuration method for this standards map form.
comment|///
name|EFI_STRING_ID
name|MethodTitle
decl_stmt|;
comment|///
comment|/// Identifier which uniquely specifies the configuration methods
comment|/// associated with this standards map form.
comment|///
name|EFI_GUID
name|MethodIdentifier
decl_stmt|;
block|}
name|EFI_IFR_FORM_MAP_METHOD
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_FORM_MAP
block|{
comment|///
comment|/// The sequence that defines the type of opcode as well as the length
comment|/// of the opcode being defined. Header.OpCode = EFI_IFR_FORM_MAP_OP.
comment|///
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// The unique identifier for this particular form.
comment|///
name|EFI_FORM_ID
name|FormId
decl_stmt|;
comment|///
comment|/// One or more configuration method's name and unique identifier.
comment|///
comment|// EFI_IFR_FORM_MAP_METHOD  Methods[];
block|}
name|EFI_IFR_FORM_MAP
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_SET
block|{
comment|///
comment|/// The sequence that defines the type of opcode as well as the length
comment|/// of the opcode being defined. Header.OpCode = EFI_IFR_SET_OP.
comment|///
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// Specifies the identifier of a previously declared variable store to
comment|/// use when storing the question's value.
comment|///
name|EFI_VARSTORE_ID
name|VarStoreId
decl_stmt|;
union|union
block|{
comment|///
comment|/// A 16-bit Buffer Storage offset.
comment|///
name|EFI_STRING_ID
name|VarName
decl_stmt|;
comment|///
comment|/// A Name Value or EFI Variable name (VarName).
comment|///
name|UINT16
name|VarOffset
decl_stmt|;
block|}
name|VarStoreInfo
union|;
comment|///
comment|/// Specifies the type used for storage.
comment|///
name|UINT8
name|VarStoreType
decl_stmt|;
block|}
name|EFI_IFR_SET
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_GET
block|{
comment|///
comment|/// The sequence that defines the type of opcode as well as the length
comment|/// of the opcode being defined. Header.OpCode = EFI_IFR_GET_OP.
comment|///
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// Specifies the identifier of a previously declared variable store to
comment|/// use when retrieving the value.
comment|///
name|EFI_VARSTORE_ID
name|VarStoreId
decl_stmt|;
union|union
block|{
comment|///
comment|/// A 16-bit Buffer Storage offset.
comment|///
name|EFI_STRING_ID
name|VarName
decl_stmt|;
comment|///
comment|/// A Name Value or EFI Variable name (VarName).
comment|///
name|UINT16
name|VarOffset
decl_stmt|;
block|}
name|VarStoreInfo
union|;
comment|///
comment|/// Specifies the type used for storage.
comment|///
name|UINT8
name|VarStoreType
decl_stmt|;
block|}
name|EFI_IFR_GET
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_READ
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_READ
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_WRITE
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_WRITE
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_MAP
block|{
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
block|}
name|EFI_IFR_MAP
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Definitions for Keyboard Package
end_comment

begin_comment
comment|// Releated definitions are in Section of EFI_HII_DATABASE_PROTOCOL
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Each enumeration values maps a physical key on a keyboard.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiKeyLCtrl
block|,
name|EfiKeyA0
block|,
name|EfiKeyLAlt
block|,
name|EfiKeySpaceBar
block|,
name|EfiKeyA2
block|,
name|EfiKeyA3
block|,
name|EfiKeyA4
block|,
name|EfiKeyRCtrl
block|,
name|EfiKeyLeftArrow
block|,
name|EfiKeyDownArrow
block|,
name|EfiKeyRightArrow
block|,
name|EfiKeyZero
block|,
name|EfiKeyPeriod
block|,
name|EfiKeyEnter
block|,
name|EfiKeyLShift
block|,
name|EfiKeyB0
block|,
name|EfiKeyB1
block|,
name|EfiKeyB2
block|,
name|EfiKeyB3
block|,
name|EfiKeyB4
block|,
name|EfiKeyB5
block|,
name|EfiKeyB6
block|,
name|EfiKeyB7
block|,
name|EfiKeyB8
block|,
name|EfiKeyB9
block|,
name|EfiKeyB10
block|,
name|EfiKeyRShift
block|,
name|EfiKeyUpArrow
block|,
name|EfiKeyOne
block|,
name|EfiKeyTwo
block|,
name|EfiKeyThree
block|,
name|EfiKeyCapsLock
block|,
name|EfiKeyC1
block|,
name|EfiKeyC2
block|,
name|EfiKeyC3
block|,
name|EfiKeyC4
block|,
name|EfiKeyC5
block|,
name|EfiKeyC6
block|,
name|EfiKeyC7
block|,
name|EfiKeyC8
block|,
name|EfiKeyC9
block|,
name|EfiKeyC10
block|,
name|EfiKeyC11
block|,
name|EfiKeyC12
block|,
name|EfiKeyFour
block|,
name|EfiKeyFive
block|,
name|EfiKeySix
block|,
name|EfiKeyPlus
block|,
name|EfiKeyTab
block|,
name|EfiKeyD1
block|,
name|EfiKeyD2
block|,
name|EfiKeyD3
block|,
name|EfiKeyD4
block|,
name|EfiKeyD5
block|,
name|EfiKeyD6
block|,
name|EfiKeyD7
block|,
name|EfiKeyD8
block|,
name|EfiKeyD9
block|,
name|EfiKeyD10
block|,
name|EfiKeyD11
block|,
name|EfiKeyD12
block|,
name|EfiKeyD13
block|,
name|EfiKeyDel
block|,
name|EfiKeyEnd
block|,
name|EfiKeyPgDn
block|,
name|EfiKeySeven
block|,
name|EfiKeyEight
block|,
name|EfiKeyNine
block|,
name|EfiKeyE0
block|,
name|EfiKeyE1
block|,
name|EfiKeyE2
block|,
name|EfiKeyE3
block|,
name|EfiKeyE4
block|,
name|EfiKeyE5
block|,
name|EfiKeyE6
block|,
name|EfiKeyE7
block|,
name|EfiKeyE8
block|,
name|EfiKeyE9
block|,
name|EfiKeyE10
block|,
name|EfiKeyE11
block|,
name|EfiKeyE12
block|,
name|EfiKeyBackSpace
block|,
name|EfiKeyIns
block|,
name|EfiKeyHome
block|,
name|EfiKeyPgUp
block|,
name|EfiKeyNLck
block|,
name|EfiKeySlash
block|,
name|EfiKeyAsterisk
block|,
name|EfiKeyMinus
block|,
name|EfiKeyEsc
block|,
name|EfiKeyF1
block|,
name|EfiKeyF2
block|,
name|EfiKeyF3
block|,
name|EfiKeyF4
block|,
name|EfiKeyF5
block|,
name|EfiKeyF6
block|,
name|EfiKeyF7
block|,
name|EfiKeyF8
block|,
name|EfiKeyF9
block|,
name|EfiKeyF10
block|,
name|EfiKeyF11
block|,
name|EfiKeyF12
block|,
name|EfiKeyPrint
block|,
name|EfiKeySLck
block|,
name|EfiKeyPause
block|}
name|EFI_KEY
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// Used to describe a physical key on a keyboard.
comment|///
name|EFI_KEY
name|Key
decl_stmt|;
comment|///
comment|/// Unicode character code for the Key.
comment|///
name|CHAR16
name|Unicode
decl_stmt|;
comment|///
comment|/// Unicode character code for the key with the shift key being held down.
comment|///
name|CHAR16
name|ShiftedUnicode
decl_stmt|;
comment|///
comment|/// Unicode character code for the key with the Alt-GR being held down.
comment|///
name|CHAR16
name|AltGrUnicode
decl_stmt|;
comment|///
comment|/// Unicode character code for the key with the Alt-GR and shift keys being held down.
comment|///
name|CHAR16
name|ShiftedAltGrUnicode
decl_stmt|;
comment|///
comment|/// Modifier keys are defined to allow for special functionality that is not necessarily
comment|/// accomplished by a printable character. Many of these modifier keys are flags to toggle
comment|/// certain state bits on and off inside of a keyboard driver.
comment|///
name|UINT16
name|Modifier
decl_stmt|;
name|UINT16
name|AffectedAttribute
decl_stmt|;
block|}
name|EFI_KEY_DESCRIPTOR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// A key which is affected by all the standard shift modifiers.
end_comment

begin_comment
comment|/// Most keys would be expected to have this bit active.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_AFFECTED_BY_STANDARD_SHIFT
value|0x0001
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This key is affected by the caps lock so that if a keyboard driver
end_comment

begin_comment
comment|/// would need to disambiguate between a key which had a "1" defined
end_comment

begin_comment
comment|/// versus an "a" character.  Having this bit turned on would tell
end_comment

begin_comment
comment|/// the keyboard driver to use the appropriate shifted state or not.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_AFFECTED_BY_CAPS_LOCK
value|0x0002
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Similar to the case of CAPS lock, if this bit is active, the key
end_comment

begin_comment
comment|/// is affected by the num lock being turned on.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_AFFECTED_BY_NUM_LOCK
value|0x0004
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT16
name|LayoutLength
decl_stmt|;
name|EFI_GUID
name|Guid
decl_stmt|;
name|UINT32
name|LayoutDescriptorStringOffset
decl_stmt|;
name|UINT8
name|DescriptorCount
decl_stmt|;
comment|// EFI_KEY_DESCRIPTOR    Descriptors[];
block|}
name|EFI_HII_KEYBOARD_LAYOUT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_HII_PACKAGE_HEADER
name|Header
decl_stmt|;
name|UINT16
name|LayoutCount
decl_stmt|;
comment|// EFI_HII_KEYBOARD_LAYOUT Layout[];
block|}
name|EFI_HII_KEYBOARD_PACKAGE_HDR
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// Modifier values
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_NULL_MODIFIER
value|0x0000
end_define

begin_define
define|#
directive|define
name|EFI_LEFT_CONTROL_MODIFIER
value|0x0001
end_define

begin_define
define|#
directive|define
name|EFI_RIGHT_CONTROL_MODIFIER
value|0x0002
end_define

begin_define
define|#
directive|define
name|EFI_LEFT_ALT_MODIFIER
value|0x0003
end_define

begin_define
define|#
directive|define
name|EFI_RIGHT_ALT_MODIFIER
value|0x0004
end_define

begin_define
define|#
directive|define
name|EFI_ALT_GR_MODIFIER
value|0x0005
end_define

begin_define
define|#
directive|define
name|EFI_INSERT_MODIFIER
value|0x0006
end_define

begin_define
define|#
directive|define
name|EFI_DELETE_MODIFIER
value|0x0007
end_define

begin_define
define|#
directive|define
name|EFI_PAGE_DOWN_MODIFIER
value|0x0008
end_define

begin_define
define|#
directive|define
name|EFI_PAGE_UP_MODIFIER
value|0x0009
end_define

begin_define
define|#
directive|define
name|EFI_HOME_MODIFIER
value|0x000A
end_define

begin_define
define|#
directive|define
name|EFI_END_MODIFIER
value|0x000B
end_define

begin_define
define|#
directive|define
name|EFI_LEFT_SHIFT_MODIFIER
value|0x000C
end_define

begin_define
define|#
directive|define
name|EFI_RIGHT_SHIFT_MODIFIER
value|0x000D
end_define

begin_define
define|#
directive|define
name|EFI_CAPS_LOCK_MODIFIER
value|0x000E
end_define

begin_define
define|#
directive|define
name|EFI_NUM_LOCK_MODIFIER
value|0x000F
end_define

begin_define
define|#
directive|define
name|EFI_LEFT_ARROW_MODIFIER
value|0x0010
end_define

begin_define
define|#
directive|define
name|EFI_RIGHT_ARROW_MODIFIER
value|0x0011
end_define

begin_define
define|#
directive|define
name|EFI_DOWN_ARROW_MODIFIER
value|0x0012
end_define

begin_define
define|#
directive|define
name|EFI_UP_ARROW_MODIFIER
value|0x0013
end_define

begin_define
define|#
directive|define
name|EFI_NS_KEY_MODIFIER
value|0x0014
end_define

begin_define
define|#
directive|define
name|EFI_NS_KEY_DEPENDENCY_MODIFIER
value|0x0015
end_define

begin_define
define|#
directive|define
name|EFI_FUNCTION_KEY_ONE_MODIFIER
value|0x0016
end_define

begin_define
define|#
directive|define
name|EFI_FUNCTION_KEY_TWO_MODIFIER
value|0x0017
end_define

begin_define
define|#
directive|define
name|EFI_FUNCTION_KEY_THREE_MODIFIER
value|0x0018
end_define

begin_define
define|#
directive|define
name|EFI_FUNCTION_KEY_FOUR_MODIFIER
value|0x0019
end_define

begin_define
define|#
directive|define
name|EFI_FUNCTION_KEY_FIVE_MODIFIER
value|0x001A
end_define

begin_define
define|#
directive|define
name|EFI_FUNCTION_KEY_SIX_MODIFIER
value|0x001B
end_define

begin_define
define|#
directive|define
name|EFI_FUNCTION_KEY_SEVEN_MODIFIER
value|0x001C
end_define

begin_define
define|#
directive|define
name|EFI_FUNCTION_KEY_EIGHT_MODIFIER
value|0x001D
end_define

begin_define
define|#
directive|define
name|EFI_FUNCTION_KEY_NINE_MODIFIER
value|0x001E
end_define

begin_define
define|#
directive|define
name|EFI_FUNCTION_KEY_TEN_MODIFIER
value|0x001F
end_define

begin_define
define|#
directive|define
name|EFI_FUNCTION_KEY_ELEVEN_MODIFIER
value|0x0020
end_define

begin_define
define|#
directive|define
name|EFI_FUNCTION_KEY_TWELVE_MODIFIER
value|0x0021
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Keys that have multiple control functions based on modifier
end_comment

begin_comment
comment|// settings are handled in the keyboard driver implementation.
end_comment

begin_comment
comment|// For instance, PRINT_KEY might have a modifier held down and
end_comment

begin_comment
comment|// is still a nonprinting character, but might have an alternate
end_comment

begin_comment
comment|// control function like SYSREQUEST
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_PRINT_MODIFIER
value|0x0022
end_define

begin_define
define|#
directive|define
name|EFI_SYS_REQUEST_MODIFIER
value|0x0023
end_define

begin_define
define|#
directive|define
name|EFI_SCROLL_LOCK_MODIFIER
value|0x0024
end_define

begin_define
define|#
directive|define
name|EFI_PAUSE_MODIFIER
value|0x0025
end_define

begin_define
define|#
directive|define
name|EFI_BREAK_MODIFIER
value|0x0026
end_define

begin_define
define|#
directive|define
name|EFI_LEFT_LOGO_MODIFIER
value|0x0027
end_define

begin_define
define|#
directive|define
name|EFI_RIGHT_LOGO_MODIFIER
value|0x0028
end_define

begin_define
define|#
directive|define
name|EFI_MENU_MODIFIER
value|0x0029
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Animation IFR opcode
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IFR_ANIMATION
block|{
comment|///
comment|/// Standard opcode header, where Header.OpCode is
comment|/// EFI_IFR_ANIMATION_OP.
comment|///
name|EFI_IFR_OP_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// Animation identifier in the HII database.
comment|///
name|EFI_ANIMATION_ID
name|Id
decl_stmt|;
block|}
name|EFI_IFR_ANIMATION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// HII animation package header.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_ANIMATION_PACKAGE_HDR
block|{
comment|///
comment|/// Standard package header, where Header.Type = EFI_HII_PACKAGE_ANIMATIONS.
comment|///
name|EFI_HII_PACKAGE_HEADER
name|Header
decl_stmt|;
comment|///
comment|/// Offset, relative to this header, of the animation information. If
comment|/// this is zero, then there are no animation sequences in the package.
comment|///
name|UINT32
name|AnimationInfoOffset
decl_stmt|;
block|}
name|EFI_HII_ANIMATION_PACKAGE_HDR
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Animation information is encoded as a series of blocks,
end_comment

begin_comment
comment|/// with each block prefixed by a single byte header EFI_HII_ANIMATION_BLOCK.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_ANIMATION_BLOCK
block|{
name|UINT8
name|BlockType
decl_stmt|;
comment|//UINT8  BlockBody[];
block|}
name|EFI_HII_ANIMATION_BLOCK
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Animation block types.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_HII_AIBT_END
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_HII_AIBT_OVERLAY_IMAGES
value|0x10
end_define

begin_define
define|#
directive|define
name|EFI_HII_AIBT_CLEAR_IMAGES
value|0x11
end_define

begin_define
define|#
directive|define
name|EFI_HII_AIBT_RESTORE_SCRN
value|0x12
end_define

begin_define
define|#
directive|define
name|EFI_HII_AIBT_OVERLAY_IMAGES_LOOP
value|0x18
end_define

begin_define
define|#
directive|define
name|EFI_HII_AIBT_CLEAR_IMAGES_LOOP
value|0x19
end_define

begin_define
define|#
directive|define
name|EFI_HII_AIBT_RESTORE_SCRN_LOOP
value|0x1A
end_define

begin_define
define|#
directive|define
name|EFI_HII_AIBT_DUPLICATE
value|0x20
end_define

begin_define
define|#
directive|define
name|EFI_HII_AIBT_SKIP2
value|0x21
end_define

begin_define
define|#
directive|define
name|EFI_HII_AIBT_SKIP1
value|0x22
end_define

begin_define
define|#
directive|define
name|EFI_HII_AIBT_EXT1
value|0x30
end_define

begin_define
define|#
directive|define
name|EFI_HII_AIBT_EXT2
value|0x31
end_define

begin_define
define|#
directive|define
name|EFI_HII_AIBT_EXT4
value|0x32
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Extended block headers used for variable sized animation records
end_comment

begin_comment
comment|/// which need an explicit length.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_AIBT_EXT1_BLOCK
block|{
comment|///
comment|/// Standard animation header, where Header.BlockType = EFI_HII_AIBT_EXT1.
comment|///
name|EFI_HII_ANIMATION_BLOCK
name|Header
decl_stmt|;
comment|///
comment|/// The block type.
comment|///
name|UINT8
name|BlockType2
decl_stmt|;
comment|///
comment|/// Size of the animation block, in bytes, including the animation block header.
comment|///
name|UINT8
name|Length
decl_stmt|;
block|}
name|EFI_HII_AIBT_EXT1_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_AIBT_EXT2_BLOCK
block|{
comment|///
comment|/// Standard animation header, where Header.BlockType = EFI_HII_AIBT_EXT2.
comment|///
name|EFI_HII_ANIMATION_BLOCK
name|Header
decl_stmt|;
comment|///
comment|/// The block type
comment|///
name|UINT8
name|BlockType2
decl_stmt|;
comment|///
comment|/// Size of the animation block, in bytes, including the animation block header.
comment|///
name|UINT16
name|Length
decl_stmt|;
block|}
name|EFI_HII_AIBT_EXT2_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_AIBT_EXT4_BLOCK
block|{
comment|///
comment|/// Standard animation header, where Header.BlockType = EFI_HII_AIBT_EXT4.
comment|///
name|EFI_HII_ANIMATION_BLOCK
name|Header
decl_stmt|;
comment|///
comment|/// The block type
comment|///
name|UINT8
name|BlockType2
decl_stmt|;
comment|///
comment|/// Size of the animation block, in bytes, including the animation block header.
comment|///
name|UINT32
name|Length
decl_stmt|;
block|}
name|EFI_HII_AIBT_EXT4_BLOCK
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_ANIMATION_CELL
block|{
comment|///
comment|/// The X offset from the upper left hand corner of the logical
comment|/// window to position the indexed image.
comment|///
name|UINT16
name|OffsetX
decl_stmt|;
comment|///
comment|/// The Y offset from the upper left hand corner of the logical
comment|/// window to position the indexed image.
comment|///
name|UINT16
name|OffsetY
decl_stmt|;
comment|///
comment|/// The image to display at the specified offset from the upper left
comment|/// hand corner of the logical window.
comment|///
name|EFI_IMAGE_ID
name|ImageId
decl_stmt|;
comment|///
comment|/// The number of milliseconds to delay after displaying the indexed
comment|/// image and before continuing on to the next linked image.  If value
comment|/// is zero, no delay.
comment|///
name|UINT16
name|Delay
decl_stmt|;
block|}
name|EFI_HII_ANIMATION_CELL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// An animation block to describe an animation sequence that does not cycle, and
end_comment

begin_comment
comment|/// where one image is simply displayed over the previous image.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_AIBT_OVERLAY_IMAGES_BLOCK
block|{
comment|///
comment|/// This is image that is to be reference by the image protocols, if the
comment|/// animation function is not supported or disabled. This image can
comment|/// be one particular image from the animation sequence (if any one
comment|/// of the animation frames has a complete image) or an alternate
comment|/// image that can be displayed alone. If the value is zero, no image
comment|/// is displayed.
comment|///
name|EFI_IMAGE_ID
name|DftImageId
decl_stmt|;
comment|///
comment|/// The overall width of the set of images (logical window width).
comment|///
name|UINT16
name|Width
decl_stmt|;
comment|///
comment|/// The overall height of the set of images (logical window height).
comment|///
name|UINT16
name|Height
decl_stmt|;
comment|///
comment|/// The number of EFI_HII_ANIMATION_CELL contained in the
comment|/// animation sequence.
comment|///
name|UINT16
name|CellCount
decl_stmt|;
comment|///
comment|/// An array of CellCount animation cells.
comment|///
name|EFI_HII_ANIMATION_CELL
name|AnimationCell
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_AIBT_OVERLAY_IMAGES_BLOCK
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// An animation block to describe an animation sequence that does not cycle,
end_comment

begin_comment
comment|/// and where the logical window is cleared to the specified color before
end_comment

begin_comment
comment|/// the next image is displayed.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_AIBT_CLEAR_IMAGES_BLOCK
block|{
comment|///
comment|/// This is image that is to be reference by the image protocols, if the
comment|/// animation function is not supported or disabled. This image can
comment|/// be one particular image from the animation sequence (if any one
comment|/// of the animation frames has a complete image) or an alternate
comment|/// image that can be displayed alone. If the value is zero, no image
comment|/// is displayed.
comment|///
name|EFI_IMAGE_ID
name|DftImageId
decl_stmt|;
comment|///
comment|/// The overall width of the set of images (logical window width).
comment|///
name|UINT16
name|Width
decl_stmt|;
comment|///
comment|/// The overall height of the set of images (logical window height).
comment|///
name|UINT16
name|Height
decl_stmt|;
comment|///
comment|/// The number of EFI_HII_ANIMATION_CELL contained in the
comment|/// animation sequence.
comment|///
name|UINT16
name|CellCount
decl_stmt|;
comment|///
comment|/// The color to clear the logical window to before displaying the
comment|/// indexed image.
comment|///
name|EFI_HII_RGB_PIXEL
name|BackgndColor
decl_stmt|;
comment|///
comment|/// An array of CellCount animation cells.
comment|///
name|EFI_HII_ANIMATION_CELL
name|AnimationCell
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_AIBT_CLEAR_IMAGES_BLOCK
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// An animation block to describe an animation sequence that does not cycle,
end_comment

begin_comment
comment|/// and where the screen is restored to the original state before the next
end_comment

begin_comment
comment|/// image is displayed.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_AIBT_RESTORE_SCRN_BLOCK
block|{
comment|///
comment|/// This is image that is to be reference by the image protocols, if the
comment|/// animation function is not supported or disabled. This image can
comment|/// be one particular image from the animation sequence (if any one
comment|/// of the animation frames has a complete image) or an alternate
comment|/// image that can be displayed alone. If the value is zero, no image
comment|/// is displayed.
comment|///
name|EFI_IMAGE_ID
name|DftImageId
decl_stmt|;
comment|///
comment|/// The overall width of the set of images (logical window width).
comment|///
name|UINT16
name|Width
decl_stmt|;
comment|///
comment|/// The overall height of the set of images (logical window height).
comment|///
name|UINT16
name|Height
decl_stmt|;
comment|///
comment|/// The number of EFI_HII_ANIMATION_CELL contained in the
comment|/// animation sequence.
comment|///
name|UINT16
name|CellCount
decl_stmt|;
comment|///
comment|/// An array of CellCount animation cells.
comment|///
name|EFI_HII_ANIMATION_CELL
name|AnimationCell
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_HII_AIBT_RESTORE_SCRN_BLOCK
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// An animation block to describe an animation sequence that continuously cycles,
end_comment

begin_comment
comment|/// and where one image is simply displayed over the previous image.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_HII_AIBT_OVERLAY_IMAGES_BLOCK
name|EFI_HII_AIBT_OVERLAY_IMAGES_LOOP_BLOCK
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// An animation block to describe an animation sequence that continuously cycles,
end_comment

begin_comment
comment|/// and where the logical window is cleared to the specified color before
end_comment

begin_comment
comment|/// the next image is displayed.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_HII_AIBT_CLEAR_IMAGES_BLOCK
name|EFI_HII_AIBT_CLEAR_IMAGES_LOOP_BLOCK
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// An animation block to describe an animation sequence that continuously cycles,
end_comment

begin_comment
comment|/// and where the screen is restored to the original state before
end_comment

begin_comment
comment|/// the next image is displayed.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_HII_AIBT_RESTORE_SCRN_BLOCK
name|EFI_HII_AIBT_RESTORE_SCRN_LOOP_BLOCK
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Assigns a new character value to a previously defined animation sequence.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_AIBT_DUPLICATE_BLOCK
block|{
comment|///
comment|/// The previously defined animation ID with the exact same
comment|/// animation information.
comment|///
name|EFI_ANIMATION_ID
name|AnimationId
decl_stmt|;
block|}
name|EFI_HII_AIBT_DUPLICATE_BLOCK
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Skips animation IDs.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_AIBT_SKIP1_BLOCK
block|{
comment|///
comment|/// The unsigned 8-bit value to add to AnimationIdCurrent.
comment|///
name|UINT8
name|SkipCount
decl_stmt|;
block|}
name|EFI_HII_AIBT_SKIP1_BLOCK
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Skips animation IDs.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_AIBT_SKIP2_BLOCK
block|{
comment|///
comment|/// The unsigned 16-bit value to add to AnimationIdCurrent.
comment|///
name|UINT16
name|SkipCount
decl_stmt|;
block|}
name|EFI_HII_AIBT_SKIP2_BLOCK
typedef|;
end_typedef

begin_pragma
pragma|#
directive|pragma
name|pack
name|(
name|)
end_pragma

begin_comment
comment|///
end_comment

begin_comment
comment|/// References to string tokens must use this macro to enable scanning for
end_comment

begin_comment
comment|/// token usages.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// STRING_TOKEN is not defined in UEFI specification. But it is placed
end_comment

begin_comment
comment|/// here for the easy access by C files and VFR source files.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|STRING_TOKEN
parameter_list|(
name|t
parameter_list|)
value|t
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// IMAGE_TOKEN is not defined in UEFI specification. But it is placed
end_comment

begin_comment
comment|/// here for the easy access by C files and VFR source files.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|IMAGE_TOKEN
parameter_list|(
name|t
parameter_list|)
value|t
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

