begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The file provides services to retrieve font information.    Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HII_FONT_H__
end_ifndef

begin_define
define|#
directive|define
name|__HII_FONT_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/GraphicsOutput.h>
end_include

begin_include
include|#
directive|include
file|<Protocol/HiiImage.h>
end_include

begin_define
define|#
directive|define
name|EFI_HII_FONT_PROTOCOL_GUID
define|\
value|{ 0xe9ca4775, 0x8657, 0x47fc, { 0x97, 0xe7, 0x7e, 0xd6, 0x5a, 0x8, 0x43, 0x24 } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_HII_FONT_PROTOCOL
name|EFI_HII_FONT_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|VOID
modifier|*
name|EFI_FONT_HANDLE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_HII_OUT_FLAGS.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|EFI_HII_OUT_FLAGS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_HII_OUT_FLAG_CLIP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_HII_OUT_FLAG_WRAP
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_HII_OUT_FLAG_CLIP_CLEAN_Y
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EFI_HII_OUT_FLAG_CLIP_CLEAN_X
value|0x00000008
end_define

begin_define
define|#
directive|define
name|EFI_HII_OUT_FLAG_TRANSPARENT
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EFI_HII_IGNORE_IF_NO_GLYPH
value|0x00000020
end_define

begin_define
define|#
directive|define
name|EFI_HII_IGNORE_LINE_BREAK
value|0x00000040
end_define

begin_define
define|#
directive|define
name|EFI_HII_DIRECT_TO_SCREEN
value|0x00000080
end_define

begin_comment
comment|/**   Definition of EFI_HII_ROW_INFO. **/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_ROW_INFO
block|{
comment|///
comment|/// The index of the first character in the string which is displayed on the line.
comment|///
name|UINTN
name|StartIndex
decl_stmt|;
comment|///
comment|/// The index of the last character in the string which is displayed on the line.
comment|/// If this is the same as StartIndex, then no characters are displayed.
comment|///
name|UINTN
name|EndIndex
decl_stmt|;
name|UINTN
name|LineHeight
decl_stmt|;
comment|///< The height of the line, in pixels.
name|UINTN
name|LineWidth
decl_stmt|;
comment|///< The width of the text on the line, in pixels.
comment|///
comment|/// The font baseline offset in pixels from the bottom of the row, or 0 if none.
comment|///
name|UINTN
name|BaselineOffset
decl_stmt|;
block|}
name|EFI_HII_ROW_INFO
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Font info flag. All flags (FONT, SIZE, STYLE, and COLOR) are defined.
end_comment

begin_comment
comment|/// They are defined as EFI_FONT_INFO_***
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|EFI_FONT_INFO_MASK
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_FONT_INFO_SYS_FONT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_FONT_INFO_SYS_SIZE
value|0x00000002
end_define

begin_define
define|#
directive|define
name|EFI_FONT_INFO_SYS_STYLE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|EFI_FONT_INFO_SYS_FORE_COLOR
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EFI_FONT_INFO_SYS_BACK_COLOR
value|0x00000020
end_define

begin_define
define|#
directive|define
name|EFI_FONT_INFO_RESIZE
value|0x00001000
end_define

begin_define
define|#
directive|define
name|EFI_FONT_INFO_RESTYLE
value|0x00002000
end_define

begin_define
define|#
directive|define
name|EFI_FONT_INFO_ANY_FONT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|EFI_FONT_INFO_ANY_SIZE
value|0x00020000
end_define

begin_define
define|#
directive|define
name|EFI_FONT_INFO_ANY_STYLE
value|0x00040000
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI_FONT_INFO
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_HII_FONT_STYLE
name|FontStyle
decl_stmt|;
name|UINT16
name|FontSize
decl_stmt|;
comment|///< character cell height in pixels
name|CHAR16
name|FontName
index|[
literal|1
index|]
decl_stmt|;
block|}
name|EFI_FONT_INFO
typedef|;
end_typedef

begin_comment
comment|/**   Describes font output-related information.    This structure is used for describing the way in which a string   should be rendered in a particular font. FontInfo specifies the   basic font information and ForegroundColor and BackgroundColor   specify the color in which they should be displayed. The flags   in FontInfoMask describe where the system default should be   supplied instead of the specified information. The flags also   describe what options can be used to make a match between the   font requested and the font available. **/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_FONT_DISPLAY_INFO
block|{
name|EFI_GRAPHICS_OUTPUT_BLT_PIXEL
name|ForegroundColor
decl_stmt|;
name|EFI_GRAPHICS_OUTPUT_BLT_PIXEL
name|BackgroundColor
decl_stmt|;
name|EFI_FONT_INFO_MASK
name|FontInfoMask
decl_stmt|;
name|EFI_FONT_INFO
name|FontInfo
decl_stmt|;
block|}
name|EFI_FONT_DISPLAY_INFO
typedef|;
end_typedef

begin_comment
comment|/**    This function renders a string to a bitmap or the screen using   the specified font, color and options. It either draws the   string and glyphs on an existing bitmap, allocates a new bitmap,   or uses the screen. The strings can be clipped or wrapped.   Optionally, the function also returns the information about each   row and the character position on that row. If   EFI_HII_OUT_FLAG_CLIP is set, then text will be formatted only   based on explicit line breaks and all pixels which would lie   outside the bounding box specified by Width and Height are   ignored. The information in the RowInfoArray only describes   characters which are at least partially displayed. For the final   row, the LineHeight and BaseLine may describe pixels that are   outside the limit specified by Height (unless   EFI_HII_OUT_FLAG_CLIP_CLEAN_Y is specified) even though those   pixels were not drawn. The LineWidth may describe pixels which   are outside the limit specified by Width (unless   EFI_HII_OUT_FLAG_CLIP_CLEAN_X is specified) even though those   pixels were not drawn. If EFI_HII_OUT_FLAG_CLIP_CLEAN_X is set,   then it modifies the behavior of EFI_HII_OUT_FLAG_CLIP so that   if a character's right-most on pixel cannot fit, then it will   not be drawn at all. This flag requires that   EFI_HII_OUT_FLAG_CLIP be set. If EFI_HII_OUT_FLAG_CLIP_CLEAN_Y   is set, then it modifies the behavior of EFI_HII_OUT_FLAG_CLIP   so that if a row's bottom-most pixel cannot fit, then it will   not be drawn at all. This flag requires that   EFI_HII_OUT_FLAG_CLIP be set. If EFI_HII_OUT_FLAG_WRAP is set,   then text will be wrapped at the right-most line-break   opportunity prior to a character whose right-most extent would   exceed Width. If no line-break opportunity can be found, then   the text will behave as if EFI_HII_OUT_FLAG_CLIP_CLEAN_X is set.   This flag cannot be used with EFI_HII_OUT_FLAG_CLIP_CLEAN_X. If   EFI_HII_OUT_FLAG_TRANSPARENT is set, then BackgroundColor is   ignored and all 'off' pixels in the character's drawn   will use the pixel value from Blt. This flag cannot be used if   Blt is NULL upon entry. If EFI_HII_IGNORE_IF_NO_GLYPH is set,   then characters which have no glyphs are not drawn. Otherwise,   they are replaced with Unicode character code 0xFFFD (REPLACEMENT   CHARACTER). If EFI_HII_IGNORE_LINE_BREAK is set, then explicit   line break characters will be ignored. If   EFI_HII_DIRECT_TO_SCREEN is set, then the string will be written   directly to the output device specified by Screen. Otherwise the   string will be rendered to the bitmap specified by Bitmap.    @param This             A pointer to the EFI_HII_FONT_PROTOCOL instance.    @param Flags            Describes how the string is to be drawn.    @param String           Points to the null-terminated string to be     @param StringInfo       Points to the string output information,                           including the color and font. If NULL, then                           the string will be output in the default                           system font and color.    @param Blt              If this points to a non-NULL on entry, this points                           to the image, which is Width pixels wide and                           Height pixels high. The string will be drawn onto                           this image and EFI_HII_OUT_FLAG_CLIP is implied.                           If this points to a NULL on entry, then a buffer                           will be allocated to hold the generated image and                           the pointer updated on exit. It is the caller's                           responsibility to free this buffer.    @param BltX, BltY       Specifies the offset from the left and top                           edge of the image of the first character                           cell in the image.    @param RowInfoArray     If this is non-NULL on entry, then on                           exit, this will point to an allocated buffer                           containing row information and                           RowInfoArraySize will be updated to contain                           the number of elements. This array describes                           the characters that were at least partially                           drawn and the heights of the rows. It is the                           caller's responsibility to free this buffer.    @param RowInfoArraySize If this is non-NULL on entry, then on                           exit it contains the number of                           elements in RowInfoArray.    @param ColumnInfoArray  If this is non-NULL, then on return it                           will be filled with the horizontal                           offset for each character in the                           string on the row where it is                           displayed. Non-printing characters                           will have the offset ~0. The caller is                           responsible for allocating a buffer large                           enough so that there is one entry for                           each character in the string, not                           including the null-terminator. It is                           possible when character display is                           normalized that some character cells                           overlap.    @retval EFI_SUCCESS           The string was successfully updated.      @retval EFI_OUT_OF_RESOURCES  Unable to allocate an output buffer for RowInfoArray or Blt.      @retval EFI_INVALID_PARAMETER The String or Blt was NULL.    @retval EFI_INVALID_PARAMETER Flags were invalid combination. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_STRING_TO_IMAGE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HII_FONT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HII_OUT_FLAGS
name|Flags
parameter_list|,
name|IN
name|CONST
name|EFI_STRING
name|String
parameter_list|,
name|IN
name|CONST
name|EFI_FONT_DISPLAY_INFO
modifier|*
name|StringInfo
parameter_list|,
name|IN
name|OUT
name|EFI_IMAGE_OUTPUT
modifier|*
modifier|*
name|Blt
parameter_list|,
name|IN
name|UINTN
name|BltX
parameter_list|,
name|IN
name|UINTN
name|BltY
parameter_list|,
name|OUT
name|EFI_HII_ROW_INFO
modifier|*
modifier|*
name|RowInfoArray
name|OPTIONAL
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|RowInfoArraySize
name|OPTIONAL
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|ColumnInfoArray
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**    This function renders a string as a bitmap or to the screen   and can clip or wrap the string. The bitmap is either supplied   by the caller or allocated by the function. The   strings are drawn with the font, size and style specified and   can be drawn transparently or opaquely. The function can also   return information about each row and each character's   position on the row. If EFI_HII_OUT_FLAG_CLIP is set, then   text will be formatted based only on explicit line breaks, and   all pixels that would lie outside the bounding box specified   by Width and Height are ignored. The information in the   RowInfoArray only describes characters which are at least   partially displayed. For the final row, the LineHeight and   BaseLine may describe pixels which are outside the limit   specified by Height (unless EFI_HII_OUT_FLAG_CLIP_CLEAN_Y is   specified) even though those pixels were not drawn. If   EFI_HII_OUT_FLAG_CLIP_CLEAN_X is set, then it modifies the   behavior of EFI_HII_OUT_FLAG_CLIP so that if a character's   right-most on pixel cannot fit, then it will not be drawn at   all. This flag requires that EFI_HII_OUT_FLAG_CLIP be set. If   EFI_HII_OUT_FLAG_CLIP_CLEAN_Y is set, then it modifies the   behavior of EFI_HII_OUT_FLAG_CLIP so that if a row's bottom   most pixel cannot fit, then it will not be drawn at all. This   flag requires that EFI_HII_OUT_FLAG_CLIP be set. If   EFI_HII_OUT_FLAG_WRAP is set, then text will be wrapped at the   right-most line-break opportunity prior to a character whose   right-most extent would exceed Width. If no line-break   opportunity can be found, then the text will behave as if   EFI_HII_OUT_FLAG_CLIP_CLEAN_X is set. This flag cannot be used   with EFI_HII_OUT_FLAG_CLIP_CLEAN_X. If   EFI_HII_OUT_FLAG_TRANSPARENT is set, then BackgroundColor is   ignored and all off" pixels in the character's glyph will   use the pixel value from Blt. This flag cannot be used if Blt   is NULL upon entry. If EFI_HII_IGNORE_IF_NO_GLYPH is set, then   characters which have no glyphs are not drawn. Otherwise, they   are replaced with Unicode character code 0xFFFD (REPLACEMENT   CHARACTER). If EFI_HII_IGNORE_LINE_BREAK is set, then explicit   line break characters will be ignored. If   EFI_HII_DIRECT_TO_SCREEN is set, then the string will be   written directly to the output device specified by Screen.   Otherwise the string will be rendered to the bitmap specified   by Bitmap.     @param This       A pointer to the EFI_HII_FONT_PROTOCOL instance.    @param Flags      Describes how the string is to be drawn.    @param PackageList                       The package list in the HII database to                     search for the specified string.    @param StringId   The string's id, which is unique within                     PackageList.    @param Language   Points to the language for the retrieved                     string. If NULL, then the current system                     language is used.    @param StringInfo Points to the string output information,                     including the color and font. If NULL, then                     the string will be output in the default                     system font and color.    @param Blt        If this points to a non-NULL on entry, this points                     to the image, which is Width pixels wide and                     Height pixels high. The string will be drawn onto                     this image and EFI_HII_OUT_FLAG_CLIP is implied.                     If this points to a NULL on entry, then a buffer                     will be allocated to hold the generated image and                     the pointer updated on exit. It is the caller's                     responsibility to free this buffer.    @param BltX, BltY Specifies the offset from the left and top                     edge of the output image of the first                     character cell in the image.    @param RowInfoArray     If this is non-NULL on entry, then on                           exit, this will point to an allocated                           buffer containing row information and                           RowInfoArraySize will be updated to                           contain the number of elements. This array                           describes the characters which were at                           least partially drawn and the heights of                           the rows. It is the caller's                           responsibility to free this buffer.    @param RowInfoArraySize If this is non-NULL on entry, then on                           exit it contains the number of                           elements in RowInfoArray.    @param ColumnInfoArray  If non-NULL, on return it is filled                           with the horizontal offset for each                           character in the string on the row                           where it is displayed. Non-printing                           characters will have the offset ~0.                           The caller is responsible to allocate                           a buffer large enough so that there is                           one entry for each character in the                           string, not including the                           null-terminator. It is possible when                           character display is normalized that                           some character cells overlap.     @retval EFI_SUCCESS           The string was successfully updated.    @retval EFI_OUT_OF_RESOURCES  Unable to allocate an output                                 buffer for RowInfoArray or Blt.    @retval EFI_INVALID_PARAMETER The String, or Blt, or Height, or                                 Width was NULL.   @retval EFI_INVALID_PARAMETER The Blt or PackageList was NULL.   @retval EFI_INVALID_PARAMETER Flags were invalid combination.   @retval EFI_NOT_FOUND         The specified PackageList is not in the Database,                                  or the stringid is not in the specified PackageList.   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_STRING_ID_TO_IMAGE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HII_FONT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HII_OUT_FLAGS
name|Flags
parameter_list|,
name|IN
name|EFI_HII_HANDLE
name|PackageList
parameter_list|,
name|IN
name|EFI_STRING_ID
name|StringId
parameter_list|,
name|IN
name|CONST
name|CHAR8
modifier|*
name|Language
parameter_list|,
name|IN
name|CONST
name|EFI_FONT_DISPLAY_INFO
modifier|*
name|StringInfo
name|OPTIONAL
parameter_list|,
name|IN
name|OUT
name|EFI_IMAGE_OUTPUT
modifier|*
modifier|*
name|Blt
parameter_list|,
name|IN
name|UINTN
name|BltX
parameter_list|,
name|IN
name|UINTN
name|BltY
parameter_list|,
name|OUT
name|EFI_HII_ROW_INFO
modifier|*
modifier|*
name|RowInfoArray
name|OPTIONAL
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|RowInfoArraySize
name|OPTIONAL
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|ColumnInfoArray
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**    Convert the glyph for a single character into a bitmap.    @param This       A pointer to the EFI_HII_FONT_PROTOCOL instance.    @param Char       The character to retrieve.    @param StringInfo Points to the string font and color                     information or NULL if the string should use                     the default system font and color.    @param Blt        This must point to a NULL on entry. A buffer will                     be allocated to hold the output and the pointer                     updated on exit. It is the caller's responsibility                     to free this buffer.    @param Baseline   The number of pixels from the bottom of the bitmap                     to the baseline.     @retval EFI_SUCCESS             The glyph bitmap created.    @retval EFI_OUT_OF_RESOURCES    Unable to allocate the output buffer Blt.    @retval EFI_WARN_UNKNOWN_GLYPH  The glyph was unknown and was                                   replaced with the glyph for                                   Unicode character code 0xFFFD.    @retval EFI_INVALID_PARAMETER   Blt is NULL, or Width is NULL, or                                   Height is NULL   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_GET_GLYPH
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HII_FONT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|CONST
name|CHAR16
name|Char
parameter_list|,
name|IN
name|CONST
name|EFI_FONT_DISPLAY_INFO
modifier|*
name|StringInfo
parameter_list|,
name|OUT
name|EFI_IMAGE_OUTPUT
modifier|*
modifier|*
name|Blt
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|Baseline
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**    This function iterates through fonts which match the specified   font, using the specified criteria. If String is non-NULL, then   all of the characters in the string must exist in order for a   candidate font to be returned.    @param This           A pointer to the EFI_HII_FONT_PROTOCOL instance.    @param FontHandle     On entry, points to the font handle returned                         by a previous call to GetFontInfo() or NULL                         to start with the first font. On return,                         points to the returned font handle or points                         to NULL if there are no more matching fonts.    @param StringInfoIn   Upon entry, points to the font to return                         information about. If NULL, then the information                          about the system default font will be returned.    @param  StringInfoOut Upon return, contains the matching font's information.                         If NULL, then no information is returned. This buffer                         is allocated with a call to the Boot Service AllocatePool().                         It is the caller's responsibility to call the Boot                          Service FreePool() when the caller no longer requires                         the contents of StringInfoOut.    @param String         Points to the string which will be tested to                         determine if all characters are available. If                         NULL, then any font is acceptable.      @retval EFI_SUCCESS            Matching font returned successfully.      @retval EFI_NOT_FOUND          No matching font was found.    @retval EFI_OUT_OF_RESOURCES   There were insufficient resources to complete the request.    **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_GET_FONT_INFO
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HII_FONT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_FONT_HANDLE
modifier|*
name|FontHandle
parameter_list|,
name|IN
name|CONST
name|EFI_FONT_DISPLAY_INFO
modifier|*
name|StringInfoIn
parameter_list|,
name|OPTIONAL
name|OUT
name|EFI_FONT_DISPLAY_INFO
modifier|*
modifier|*
name|StringInfoOut
parameter_list|,
name|IN
name|CONST
name|EFI_STRING
name|String
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The protocol provides the service to retrieve the font informations.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_HII_FONT_PROTOCOL
block|{
name|EFI_HII_STRING_TO_IMAGE
name|StringToImage
decl_stmt|;
name|EFI_HII_STRING_ID_TO_IMAGE
name|StringIdToImage
decl_stmt|;
name|EFI_HII_GET_GLYPH
name|GetGlyph
decl_stmt|;
name|EFI_HII_GET_FONT_INFO
name|GetFontInfo
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHiiFontProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

