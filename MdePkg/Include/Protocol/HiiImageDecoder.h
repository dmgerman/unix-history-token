begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This protocol provides generic image decoder interfaces to various image formats.  (C) Copyright 2016 Hewlett Packard Enterprise Development LP<BR>   Copyright (c) 2016, Intel Corporation. All rights reserved.<BR>  This program and the accompanying materials are licensed and made available under the terms and conditions of the BSD License that accompanies this distribution. The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS, WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HII_IMAGE_DECODER_H__
end_ifndef

begin_define
define|#
directive|define
name|__HII_IMAGE_DECODER_H__
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
comment|// In UEFI 2.6 spec,this guid value is duplicate with
end_comment

begin_comment
comment|// EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL_GUID. Now update this guid value to
end_comment

begin_comment
comment|// avoid the duplicate guid issue. So its value is not consistent with
end_comment

begin_comment
comment|// UEFI spec definition now. We have proposed to update UEFI spec to
end_comment

begin_comment
comment|// use this new guid. After new spec released, we will remove this
end_comment

begin_comment
comment|// comments.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|EFI_HII_IMAGE_DECODER_PROTOCOL_GUID
define|\
value|{0x9e66f251, 0x727c, 0x418c, { 0xbf, 0xd6, 0xc2, 0xb4, 0x25, 0x28, 0x18, 0xea }}
end_define

begin_define
define|#
directive|define
name|EFI_HII_IMAGE_DECODER_NAME_JPEG_GUID
define|\
value|{0xefefd093, 0xd9b, 0x46eb,  { 0xa8, 0x56, 0x48, 0x35, 0x7, 0x0, 0xc9, 0x8 }}
end_define

begin_define
define|#
directive|define
name|EFI_HII_IMAGE_DECODER_NAME_PNG_GUID
define|\
value|{0xaf060190, 0x5e3a, 0x4025, { 0xaf, 0xbd, 0xe1, 0xf9, 0x5, 0xbf, 0xaa, 0x4c }}
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_HII_IMAGE_DECODER_PROTOCOL
name|EFI_HII_IMAGE_DECODER_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
name|EFI_HII_IMAGE_DECODER_COLOR_TYPE_RGB
init|=
literal|0x0
block|,
name|EFI_HII_IMAGE_DECODER_COLOR_TYPE_RGBA
init|=
literal|0x1
block|,
name|EFI_HII_IMAGE_DECODER_COLOR_TYPE_CMYK
init|=
literal|0x2
block|,
name|EFI_HII_IMAGE_DECODER_COLOR_TYPE_UNKNOWN
init|=
literal|0xFF
block|}
name|EFI_HII_IMAGE_DECODER_COLOR_TYPE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI_HII_IMAGE_DECODER_IMAGE_INFO_HEADER
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// DecoderName        Name of the decoder
end_comment

begin_comment
comment|// ImageInfoSize      The size of entire image information structure in bytes
end_comment

begin_comment
comment|// ImageWidth         The image width
end_comment

begin_comment
comment|// ImageHeight        The image height
end_comment

begin_comment
comment|// ColorType          The color type, see EFI_HII_IMAGE_DECODER_COLOR_TYPE.
end_comment

begin_comment
comment|// ColorDepthInBits   The color depth in bits
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IMAGE_DECODER_IMAGE_INFO_HEADER
block|{
name|EFI_GUID
name|DecoderName
decl_stmt|;
name|UINT16
name|ImageInfoSize
decl_stmt|;
name|UINT16
name|ImageWidth
decl_stmt|;
name|UINT16
name|ImageHeight
decl_stmt|;
name|EFI_HII_IMAGE_DECODER_COLOR_TYPE
name|ColorType
decl_stmt|;
name|UINT8
name|ColorDepthInBits
decl_stmt|;
block|}
name|EFI_HII_IMAGE_DECODER_IMAGE_INFO_HEADER
typedef|;
end_typedef

begin_define
define|#
directive|define
name|EFI_IMAGE_JPEG_SCANTYPE_PROGREESSIVE
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_IMAGE_JPEG_SCANTYPE_INTERLACED
value|0x02
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI_HII_IMAGE_DECODER_JPEG_INFO
end_comment

begin_comment
comment|// Header         The common header
end_comment

begin_comment
comment|// ScanType       The scan type of JPEG image
end_comment

begin_comment
comment|// Reserved       Reserved
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IMAGE_DECODER_JPEG_INFO
block|{
name|EFI_HII_IMAGE_DECODER_IMAGE_INFO_HEADER
name|Header
decl_stmt|;
name|UINT16
name|ScanType
decl_stmt|;
name|UINT64
name|Reserved
decl_stmt|;
block|}
name|EFI_HII_IMAGE_DECODER_JPEG_INFO
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI_HII_IMAGE_DECODER_PNG_INFO
end_comment

begin_comment
comment|// Header         The common header
end_comment

begin_comment
comment|// Channels       Number of channels in the PNG image
end_comment

begin_comment
comment|// Reserved       Reserved
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IMAGE_DECODER_PNG_INFO
block|{
name|EFI_HII_IMAGE_DECODER_IMAGE_INFO_HEADER
name|Header
decl_stmt|;
name|UINT16
name|Channels
decl_stmt|;
name|UINT64
name|Reserved
decl_stmt|;
block|}
name|EFI_HII_IMAGE_DECODER_PNG_INFO
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI_HII_IMAGE_DECODER_OTHER_INFO
end_comment

begin_comment
comment|//
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_HII_IMAGE_DECODER_OTHER_INFO
block|{
name|EFI_HII_IMAGE_DECODER_IMAGE_INFO_HEADER
name|Header
decl_stmt|;
name|CHAR16
name|ImageExtenion
index|[
literal|1
index|]
decl_stmt|;
comment|//
comment|// Variable length of image file extension name.
comment|//
block|}
name|EFI_HII_IMAGE_DECODER_OTHER_INFO
typedef|;
end_typedef

begin_comment
comment|/**   There could be more than one EFI_HII_IMAGE_DECODER_PROTOCOL instances installed   in the system for different image formats. This function returns the decoder   name which callers can use to find the proper image decoder for the image. It   is possible to support multiple image formats in one EFI_HII_IMAGE_DECODER_PROTOCOL.   The capability of the supported image formats is returned in DecoderName and   NumberOfDecoderName.    @param This                    EFI_HII_IMAGE_DECODER_PROTOCOL instance.   @param DecoderName             Pointer to a dimension to retrieve the decoder                                  names in EFI_GUID format. The number of the                                  decoder names is returned in NumberOfDecoderName.   @param NumberofDecoderName     Pointer to retrieve the number of decoders which                                  supported by this decoder driver.    @retval EFI_SUCCESS            Get decoder name success.   @retval EFI_UNSUPPORTED        Get decoder name fail.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_IMAGE_DECODER_GET_NAME
function_decl|)
parameter_list|(
name|IN
name|EFI_HII_IMAGE_DECODER_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|EFI_GUID
modifier|*
modifier|*
name|DecoderName
parameter_list|,
name|IN
name|OUT
name|UINT16
modifier|*
name|NumberOfDecoderName
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function returns the image information of the given image raw data. This   function first checks whether the image raw data is supported by this decoder   or not. This function may go through the first few bytes in the image raw data   for the specific data structure or the image signature. If the image is not supported   by this image decoder, this function returns EFI_UNSUPPORTED to the caller.   Otherwise, this function returns the proper image information to the caller.   It is the caller?s responsibility to free the ImageInfo.    @param This                    EFI_HII_IMAGE_DECODER_PROTOCOL instance.   @param Image                   Pointer to the image raw data.   @param SizeOfImage             Size of the entire image raw data.   @param ImageInfo               Pointer to receive EFI_HII_IMAGE_DECODER_IMAGE_INFO_HEADER.    @retval EFI_SUCCESS            Get image info success.   @retval EFI_UNSUPPORTED        Unsupported format of image.   @retval EFI_INVALID_PARAMETER  Incorrect parameter.   @retval EFI_BAD_BUFFER_SIZE    Not enough memory.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_IMAGE_DECODER_GET_IMAGE_INFO
function_decl|)
parameter_list|(
name|IN
name|EFI_HII_IMAGE_DECODER_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|VOID
modifier|*
name|Image
parameter_list|,
name|IN
name|UINTN
name|SizeOfImage
parameter_list|,
name|IN
name|OUT
name|EFI_HII_IMAGE_DECODER_IMAGE_INFO_HEADER
modifier|*
modifier|*
name|ImageInfo
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   This function decodes the image which the image type of this image is supported   by this EFI_HII_IMAGE_DECODER_PROTOCOL. If **Bitmap is not NULL, the caller intends   to put the image in the given image buffer. That allows the caller to put an   image overlap on the original image. The transparency is handled by the image   decoder because the transparency capability depends on the image format. Callers   can set Transparent to FALSE to force disabling the transparency process on the   image. Forcing Transparent to FALSE may also improve the performance of the image   decoding because the image decoder can skip the transparency processing.  If **Bitmap   is NULL, the image decoder allocates the memory buffer for the EFI_IMAGE_OUTPUT   and decodes the image to the image buffer. It is the caller?s responsibility to   free the memory for EFI_IMAGE_OUTPUT. Image decoder doesn?t have to handle the   transparency in this case because there is no background image given by the caller.   The background color in this case is all black (#00000000).    @param This                    EFI_HII_IMAGE_DECODER_PROTOCOL instance.   @param Image                   Pointer to the image raw data.   @param ImageRawDataSize        Size of the entire image raw data.   @param Blt                     EFI_IMAGE_OUTPUT to receive the image or overlap                                  the image on the original buffer.   @param Transparent             BOOLEAN value indicates whether the image decoder                                  has to handle the transparent image or not.     @retval EFI_SUCCESS            Image decode success.   @retval EFI_UNSUPPORTED        Unsupported format of image.   @retval EFI_INVALID_PARAMETER  Incorrect parameter.   @retval EFI_BAD_BUFFER_SIZE    Not enough memory.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_HII_IMAGE_DECODER_DECODE
function_decl|)
parameter_list|(
name|IN
name|EFI_HII_IMAGE_DECODER_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|VOID
modifier|*
name|Image
parameter_list|,
name|IN
name|UINTN
name|ImageRawDataSize
parameter_list|,
name|IN
name|OUT
name|EFI_IMAGE_OUTPUT
modifier|*
modifier|*
name|Bitmap
parameter_list|,
name|IN
name|BOOLEAN
name|Transparent
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|_EFI_HII_IMAGE_DECODER_PROTOCOL
block|{
name|EFI_HII_IMAGE_DECODER_GET_NAME
name|GetImageDecoderName
decl_stmt|;
name|EFI_HII_IMAGE_DECODER_GET_IMAGE_INFO
name|GetImageInfo
decl_stmt|;
name|EFI_HII_IMAGE_DECODER_DECODE
name|DecodeImage
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHiiImageDecoderProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHiiImageDecoderNameJpegGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHiiImageDecoderNamePngGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

