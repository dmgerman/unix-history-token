begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Protocol which allows access to the images in the images database.  (C) Copyright 2016 Hewlett Packard Enterprise Development LP<BR>  This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License that accompanies this distribution. The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_HII_IMAGE_EX_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_HII_IMAGE_EX_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/HiiImage.h>
end_include

begin_comment
comment|//
end_comment

begin_comment
comment|// Global ID for the Hii Image Ex Protocol.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_HII_IMAGE_EX_PROTOCOL_GUID
define|\
value|{0x1a1241e6, 0x8f19, 0x41a9,  { 0xbc, 0xe, 0xe8, 0xef, 0x39, 0xe0, 0x65, 0x46 }}
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_HII_IMAGE_EX_PROTOCOL
name|EFI_HII_IMAGE_EX_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   The prototype of this extension function is the same with EFI_HII_IMAGE_PROTOCOL.NewImage().   Same with EFI_HII_IMAGE_PROTOCOL.NewImage().This protocol invokes EFI_HII_IMAGE_PROTOCOL.NewImage() implicitly.    @param  This                   A pointer to the EFI_HII_IMAGE_EX_PROTOCOL instance.   @param  PackageList            Handle of the package list where this image will                                  be added.   @param  ImageId                On return, contains the new image id, which is                                  unique within PackageList.   @param  Image                  Points to the image.    @retval EFI_SUCCESS            The new image was added successfully.   @retval EFI_NOT_FOUND          The specified PackageList could not be found in                                  database.   @retval EFI_OUT_OF_RESOURCES   Could not add the image due to lack of resources.   @retval EFI_INVALID_PARAMETER  Image is NULL or ImageId is NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_NEW_IMAGE_EX
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HII_IMAGE_EX_PROTOCOL
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
comment|/**   Return the information about the image, associated with the package list.   The prototype of this extension function is the same with EFI_HII_IMAGE_PROTOCOL.GetImage().   Same with EFI_HII_IMAGE_PROTOCOL.SetImage(),this protocol invokes EFI_HII_IMAGE_PROTOCOL.SetImage() implicitly.    @param  This                   A pointer to the EFI_HII_IMAGE_EX_PROTOCOL instance.   @param  PackageList            Handle of the package list where this image will                                  be searched.   @param  ImageId                The image's id,, which is unique within                                  PackageList.   @param  Image                  Points to the image.    @retval EFI_SUCCESS            The new image was returned successfully.   @retval EFI_NOT_FOUND          The image specified by ImageId is not in the                                  database. The specified PackageList is not in                                  the database.   @retval EFI_BUFFER_TOO_SMALL   The buffer specified by ImageSize is too small to                                  hold the image.   @retval EFI_INVALID_PARAMETER  The Image or ImageSize was NULL.   @retval EFI_OUT_OF_RESOURCES   The bitmap could not be retrieved because there                                  was not enough memory.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_GET_IMAGE_EX
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HII_IMAGE_EX_PROTOCOL
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
comment|/**   Change the information about the image. The prototype of this extension   function is the same with EFI_HII_IMAGE_PROTOCOL.SetImage().  Same with   EFI_HII_IMAGE_PROTOCOL.DrawImageId(),this protocol invokes EFI_HII_IMAGE_PROTOCOL.DrawImageId() implicitly.    @param  This                   A pointer to the EFI_HII_IMAGE_EX_PROTOCOL instance.   @param  PackageList            The package list containing the images.   @param  ImageId                The image's id,, which is unique within                                  PackageList.   @param  Image                  Points to the image.    @retval EFI_SUCCESS            The new image was updated successfully.   @retval EFI_NOT_FOUND          The image specified by ImageId is not in the                                  database. The specified PackageList is not in                                  the database.   @retval EFI_INVALID_PARAMETER  The Image was NULL.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_SET_IMAGE_EX
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HII_IMAGE_EX_PROTOCOL
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
comment|/**   Renders an image to a bitmap or to the display. The prototype of this extension   function is the same with EFI_HII_IMAGE_PROTOCOL.DrawImage().   Same with EFI_HII_IMAGE_PROTOCOL.SetImage(),this protocol invokes EFI_HII_IMAGE_PROTOCOL.SetImage() implicitly.    @param  This                   A pointer to the EFI_HII_IMAGE_EX_PROTOCOL instance.   @param  Flags                  Describes how the image is to be drawn.   @param  Image                  Points to the image to be displayed.   @param  Blt                    If this points to a non-NULL on entry, this points                                  to the image, which is Width pixels wide and                                  Height pixels high.  The image will be drawn onto                                  this image and  EFI_HII_DRAW_FLAG_CLIP is implied.                                  If this points to a  NULL on entry, then a buffer                                  will be allocated to hold  the generated image and                                  the pointer updated on exit. It is the caller's                                  responsibility to free this buffer.   @param  BltX                   Specifies the offset from the left and top edge of                                  the  output image of the first pixel in the image.   @param  BltY                   Specifies the offset from the left and top edge of                                  the  output image of the first pixel in the image.    @retval EFI_SUCCESS            The image was successfully drawn.   @retval EFI_OUT_OF_RESOURCES   Unable to allocate an output buffer for Blt.   @retval EFI_INVALID_PARAMETER  The Image or Blt was NULL.                                  Any combination of Flags is invalid.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_DRAW_IMAGE_EX
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HII_IMAGE_EX_PROTOCOL
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
comment|/**   Renders an image to a bitmap or the screen containing the contents of the specified   image. The prototype of this extension function is the same with E   FI_HII_IMAGE_PROTOCOL.DrawImageId().   Same with EFI_HII_IMAGE_PROTOCOL.DrawImageId(),this protocol invokes EFI_HII_IMAGE_PROTOCOL.DrawImageId() implicitly.    @param  This                   A pointer to the EFI_HII_IMAGE_EX_PROTOCOL instance.   @param  Flags                  Describes how the image is to be drawn.   @param  PackageList            The package list in the HII database to search for                                  the  specified image.   @param  ImageId                The image's id, which is unique within                                  PackageList.   @param  Blt                    If this points to a non-NULL on entry, this points                                  to the image, which is Width pixels wide and                                  Height pixels high. The image will be drawn onto                                  this image and EFI_HII_DRAW_FLAG_CLIP is implied.                                  If this points to a NULL on entry, then a buffer                                  will be allocated to hold  the generated image                                  and the pointer updated on exit. It is the caller's                                  responsibility to free this buffer.   @param  BltX                   Specifies the offset from the left and top edge of                                  the output image of the first pixel in the image.   @param  BltY                   Specifies the offset from the left and top edge of                                  the output image of the first pixel in the image.    @retval EFI_SUCCESS            The image was successfully drawn.   @retval EFI_OUT_OF_RESOURCES   Unable to allocate an output buffer for Blt.   @retval EFI_INVALID_PARAMETER  The Blt was NULL.   @retval EFI_NOT_FOUND          The image specified by ImageId is not in the database.                                  The specified PackageList is not in the database.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_DRAW_IMAGE_ID_EX
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HII_IMAGE_EX_PROTOCOL
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
comment|/**   This function returns the image information to EFI_IMAGE_OUTPUT. Only the width   and height are returned to the EFI_IMAGE_OUTPUT instead of decoding the image   to the buffer. This function is used to get the geometry of the image. This function   will try to locate all of the EFI_HII_IMAGE_DECODER_PROTOCOL installed on the   system if the decoder of image type is not supported by the EFI_HII_IMAGE_EX_PROTOCOL.    @param  This                   A pointer to the EFI_HII_IMAGE_EX_PROTOCOL instance.   @param  PackageList            Handle of the package list where this image will                                  be searched.   @param  ImageId                The image's id,, which is unique within PackageList.   @param  Image                  Points to the image.    @retval EFI_SUCCESS            The new image was returned successfully.   @retval EFI_NOT_FOUND          The image specified by ImageId is not in the                                  database. The specified PackageList is not in the database.   @retval EFI_BUFFER_TOO_SMALL   The buffer specified by ImageSize is too small to                                  hold the image.   @retval EFI_INVALID_PARAMETER  The Image or ImageSize was NULL.   @retval EFI_OUT_OF_RESOURCES   The bitmap could not be retrieved because there                                  was not enough memory.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_GET_IMAGE_INFO
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_HII_IMAGE_EX_PROTOCOL
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
name|EFI_IMAGE_OUTPUT
modifier|*
name|Image
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Protocol which allows access to the images in the images database.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_HII_IMAGE_EX_PROTOCOL
block|{
name|EFI_HII_NEW_IMAGE_EX
name|NewImageEx
decl_stmt|;
name|EFI_HII_GET_IMAGE_EX
name|GetImageEx
decl_stmt|;
name|EFI_HII_SET_IMAGE_EX
name|SetImageEx
decl_stmt|;
name|EFI_HII_DRAW_IMAGE_EX
name|DrawImageEx
decl_stmt|;
name|EFI_HII_DRAW_IMAGE_ID_EX
name|DrawImageIdEx
decl_stmt|;
name|EFI_HII_GET_IMAGE_INFO
name|GetImageInfo
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHiiImageExProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

