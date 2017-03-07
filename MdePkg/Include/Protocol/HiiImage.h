begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   The file provides services to access to images in the images database.      Copyright (c) 2006 - 2016, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HII_IMAGE_H__
end_ifndef

begin_define
define|#
directive|define
name|__HII_IMAGE_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/GraphicsOutput.h>
end_include

begin_define
define|#
directive|define
name|EFI_HII_IMAGE_PROTOCOL_GUID
define|\
value|{ 0x31a6406a, 0x6bdf, 0x4e46, { 0xb2, 0xa2, 0xeb, 0xaa, 0x89, 0xc4, 0x9, 0x20 } }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_HII_IMAGE_PROTOCOL
name|EFI_HII_IMAGE_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Flags in EFI_IMAGE_INPUT
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_IMAGE_TRANSPARENT
value|0x00000001
end_define

begin_comment
comment|/**       Definition of EFI_IMAGE_INPUT.       @param Flags  Describe image characteristics. If                 EFI_IMAGE_TRANSPARENT is set, then the image was                 designed for transparent display.    @param Width  Image width, in pixels.     @param Height Image height, in pixels.    @param Bitmap A pointer to the actual bitmap, organized left-to-right,                 top-to-bottom. The size of the bitmap is                 Width*Height*sizeof(EFI_GRAPHICS_OUTPUT_BLT_PIXEL).      **/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IMAGE_INPUT
block|{
name|UINT32
name|Flags
decl_stmt|;
name|UINT16
name|Width
decl_stmt|;
name|UINT16
name|Height
decl_stmt|;
name|EFI_GRAPHICS_OUTPUT_BLT_PIXEL
modifier|*
name|Bitmap
decl_stmt|;
block|}
name|EFI_IMAGE_INPUT
typedef|;
end_typedef

begin_comment
comment|/**    This function adds the image Image to the group of images   owned by PackageList, and returns a new image identifier   (ImageId).    @param This        A pointer to the EFI_HII_IMAGE_PROTOCOL instance.       @param PackageList Handle of the package list where this image will be added.    @param ImageId     On return, contains the new image id, which is                      unique within PackageList.    @param Image       Points to the image.    @retval EFI_SUCCESS             The new image was added                                   successfully      @retval EFI_OUT_OF_RESOURCES    Could not add the image.      @retval EFI_INVALID_PARAMETER   Image is NULL or ImageId is                                   NULL.   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_NEW_IMAGE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HII_IMAGE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HII_HANDLE
name|PackageList
parameter_list|,
name|OUT
name|EFI_IMAGE_ID
modifier|*
name|ImageId
parameter_list|,
name|IN
name|CONST
name|EFI_IMAGE_INPUT
modifier|*
name|Image
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**    This function retrieves the image specified by ImageId which   is associated with the specified PackageList and copies it   into the buffer specified by Image. If the image specified by   ImageId is not present in the specified PackageList, then   EFI_NOT_FOUND is returned. If the buffer specified by   ImageSize is too small to hold the image, then   EFI_BUFFER_TOO_SMALL will be returned. ImageSize will be   updated to the size of buffer actually required to hold the   image.    @param This         A pointer to the EFI_HII_IMAGE_PROTOCOL instance.       @param PackageList  The package list in the HII database to                       search for the specified image.      @param ImageId      The image's id, which is unique within                       PackageList.      @param Image        Points to the new image.      @retval EFI_SUCCESS            The image was returned successfully.    @retval EFI_NOT_FOUND          The image specified by ImageId is not                                  available. Or The specified PackageList is not in the database.      @retval EFI_INVALID_PARAMETER  The Image or Langugae was NULL.   @retval EFI_OUT_OF_RESOURCES   The bitmap could not be retrieved because there was not                                  enough memory.   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_GET_IMAGE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HII_IMAGE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HII_HANDLE
name|PackageList
parameter_list|,
name|IN
name|EFI_IMAGE_ID
name|ImageId
parameter_list|,
name|OUT
name|EFI_IMAGE_INPUT
modifier|*
name|Image
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**       This function updates the image specified by ImageId in the   specified PackageListHandle to the image specified by Image.     @param This         A pointer to the EFI_HII_IMAGE_PROTOCOL instance.     @param PackageList  The package list containing the images.    @param ImageId      The image id, which is unique within PackageList.    @param Image        Points to the image.    @retval EFI_SUCCESS           The image was successfully updated.      @retval EFI_NOT_FOUND         The image specified by ImageId is not in the database.                                 The specified PackageList is not in the database.       @retval EFI_INVALID_PARAMETER The Image or Language was NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_SET_IMAGE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HII_IMAGE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HII_HANDLE
name|PackageList
parameter_list|,
name|IN
name|EFI_IMAGE_ID
name|ImageId
parameter_list|,
name|IN
name|CONST
name|EFI_IMAGE_INPUT
modifier|*
name|Image
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_HII_DRAW_FLAGS describes how the image is to be drawn.
end_comment

begin_comment
comment|/// These flags are defined as EFI_HII_DRAW_FLAG_***
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|EFI_HII_DRAW_FLAGS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_HII_DRAW_FLAG_CLIP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|EFI_HII_DRAW_FLAG_TRANSPARENT
value|0x00000030
end_define

begin_define
define|#
directive|define
name|EFI_HII_DRAW_FLAG_DEFAULT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|EFI_HII_DRAW_FLAG_FORCE_TRANS
value|0x00000010
end_define

begin_define
define|#
directive|define
name|EFI_HII_DRAW_FLAG_FORCE_OPAQUE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|EFI_HII_DIRECT_TO_SCREEN
value|0x00000080
end_define

begin_comment
comment|/**       Definition of EFI_IMAGE_OUTPUT.       @param Width  Width of the output image.    @param Height Height of the output image.    @param Bitmap Points to the output bitmap.    @param Screen Points to the EFI_GRAPHICS_OUTPUT_PROTOCOL which                 describes the screen on which to draw the                 specified image.  **/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_IMAGE_OUTPUT
block|{
name|UINT16
name|Width
decl_stmt|;
name|UINT16
name|Height
decl_stmt|;
union|union
block|{
name|EFI_GRAPHICS_OUTPUT_BLT_PIXEL
modifier|*
name|Bitmap
decl_stmt|;
name|EFI_GRAPHICS_OUTPUT_PROTOCOL
modifier|*
name|Screen
decl_stmt|;
block|}
name|Image
union|;
block|}
name|EFI_IMAGE_OUTPUT
typedef|;
end_typedef

begin_comment
comment|/**       This function renders an image to a bitmap or the screen using   the specified color and options. It draws the image on an   existing bitmap, allocates a new bitmap or uses the screen. The   images can be clipped. If EFI_HII_DRAW_FLAG_CLIP is set, then   all pixels drawn outside the bounding box specified by Width and   Height are ignored. If EFI_HII_DRAW_FLAG_TRANSPARENT is set,   then all 'off' pixels in the images drawn will use the   pixel value from Blt. This flag cannot be used if Blt is NULL   upon entry. If EFI_HII_DIRECT_TO_SCREEN is set, then the image   will be written directly to the output device specified by   Screen. Otherwise the image will be rendered to the bitmap   specified by Bitmap.     @param This       A pointer to the EFI_HII_IMAGE_PROTOCOL instance.      @param Flags      Describes how the image is to be drawn.                     EFI_HII_DRAW_FLAGS is defined in Related                     Definitions, below.      @param Image      Points to the image to be displayed.       @param Blt        If this points to a non-NULL on entry, this points                     to the image, which is Width pixels wide and                     Height pixels high. The image will be drawn onto                     this image and EFI_HII_DRAW_FLAG_CLIP is implied.                     If this points to a NULL on entry, then a buffer                     will be allocated to hold the generated image and                     the pointer updated on exit. It is the caller's                     responsibility to free this buffer.    @param BltX, BltY Specifies the offset from the left and top                     edge of the image of the first pixel in                     the image.    @retval EFI_SUCCESS           The image was successfully updated.    @retval EFI_OUT_OF_RESOURCES  Unable to allocate an output                                 buffer for RowInfoArray or Blt.    @retval EFI_INVALID_PARAMETER The Image or Blt or Height or                                 Width was NULL.   **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_DRAW_IMAGE
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HII_IMAGE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HII_DRAW_FLAGS
name|Flags
parameter_list|,
name|IN
name|CONST
name|EFI_IMAGE_INPUT
modifier|*
name|Image
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
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**       This function renders an image as a bitmap or to the screen and   can clip the image. The bitmap is either supplied by the caller   or else is allocated by the function. The images can be drawn   transparently or opaquely. If EFI_HII_DRAW_FLAG_CLIP is set,   then all pixels drawn outside the bounding box specified by   Width and Height are ignored. If EFI_HII_DRAW_FLAG_TRANSPARENT   is set, then all "off" pixels in the character's glyph will   use the pixel value from Blt. This flag cannot be used if Blt   is NULL upon entry. If EFI_HII_DIRECT_TO_SCREEN is set, then   the image will be written directly to the output device   specified by Screen. Otherwise the image will be rendered to   the bitmap specified by Bitmap.   This function renders an image to a bitmap or the screen using   the specified color and options. It draws the image on an   existing bitmap, allocates a new bitmap or uses the screen. The   images can be clipped. If EFI_HII_DRAW_FLAG_CLIP is set, then   all pixels drawn outside the bounding box specified by Width and   Height are ignored. The EFI_HII_DRAW_FLAG_TRANSPARENT flag   determines whether the image will be drawn transparent or   opaque. If EFI_HII_DRAW_FLAG_FORCE_TRANS is set, then the image   will be drawn so that all 'off' pixels in the image will   be drawn using the pixel value from Blt and all other pixels   will be copied. If EFI_HII_DRAW_FLAG_FORCE_OPAQUE is set, then   the image's pixels will be copied directly to the   destination. If EFI_HII_DRAW_FLAG_DEFAULT is set, then the image   will be drawn transparently or opaque, depending on the   image's transparency setting (see EFI_IMAGE_TRANSPARENT).   Images cannot be drawn transparently if Blt is NULL. If   EFI_HII_DIRECT_TO_SCREEN is set, then the image will be written   directly to the output device specified by Screen. Otherwise the   image will be rendered to the bitmap specified by Bitmap.    @param This         A pointer to the EFI_HII_IMAGE_PROTOCOL instance.     @param Flags        Describes how the image is to be drawn.    @param PackageList  The package list in the HII database to                       search for the specified image.    @param ImageId      The image's id, which is unique within PackageList.    @param Blt          If this points to a non-NULL on entry, this points                       to the image, which is Width pixels wide and                       Height pixels high. The image will be drawn onto                       this image and EFI_HII_DRAW_FLAG_CLIP is implied.                       If this points to a NULL on entry, then a buffer                       will be allocated to hold the generated image and                       the pointer updated on exit. It is the caller's                       responsibility to free this buffer.    @param BltX, BltY   Specifies the offset from the left and top                       edge of the output image of the first                       pixel in the image.    @retval EFI_SUCCESS           The image was successfully updated.      @retval EFI_OUT_OF_RESOURCES  Unable to allocate an output                                 buffer for RowInfoArray or Blt.      @retval EFI_NOT_FOUND         The image specified by ImageId is not in the database.                                  Or The specified PackageList is not in the database.                                  @retval EFI_INVALID_PARAMETER The Blt was NULL.      **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_DRAW_IMAGE_ID
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HII_IMAGE_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_HII_DRAW_FLAGS
name|Flags
parameter_list|,
name|IN
name|EFI_HII_HANDLE
name|PackageList
parameter_list|,
name|IN
name|EFI_IMAGE_ID
name|ImageId
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
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Services to access to images in the images database.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_HII_IMAGE_PROTOCOL
block|{
name|EFI_HII_NEW_IMAGE
name|NewImage
decl_stmt|;
name|EFI_HII_GET_IMAGE
name|GetImage
decl_stmt|;
name|EFI_HII_SET_IMAGE
name|SetImage
decl_stmt|;
name|EFI_HII_DRAW_IMAGE
name|DrawImage
decl_stmt|;
name|EFI_HII_DRAW_IMAGE_ID
name|DrawImageId
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHiiImageProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

