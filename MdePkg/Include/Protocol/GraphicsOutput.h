begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Graphics Output Protocol from the UEFI 2.0 specification.    Abstraction of a very simple graphics device.    Copyright (c) 2006 - 2012, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__GRAPHICS_OUTPUT_H__
end_ifndef

begin_define
define|#
directive|define
name|__GRAPHICS_OUTPUT_H__
end_define

begin_define
define|#
directive|define
name|EFI_GRAPHICS_OUTPUT_PROTOCOL_GUID
define|\
value|{ \     0x9042a9de, 0x23dc, 0x4a38, {0x96, 0xfb, 0x7a, 0xde, 0xd0, 0x80, 0x51, 0x6a } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_GRAPHICS_OUTPUT_PROTOCOL
name|EFI_GRAPHICS_OUTPUT_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT32
name|RedMask
decl_stmt|;
name|UINT32
name|GreenMask
decl_stmt|;
name|UINT32
name|BlueMask
decl_stmt|;
name|UINT32
name|ReservedMask
decl_stmt|;
block|}
name|EFI_PIXEL_BITMASK
typedef|;
end_typedef

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// A pixel is 32-bits and byte zero represents red, byte one represents green,
comment|/// byte two represents blue, and byte three is reserved. This is the definition
comment|/// for the physical frame buffer. The byte values for the red, green, and blue
comment|/// components represent the color intensity. This color intensity value range
comment|/// from a minimum intensity of 0 to maximum intensity of 255.
comment|///
name|PixelRedGreenBlueReserved8BitPerColor
block|,
comment|///
comment|/// A pixel is 32-bits and byte zero represents blue, byte one represents green,
comment|/// byte two represents red, and byte three is reserved. This is the definition
comment|/// for the physical frame buffer. The byte values for the red, green, and blue
comment|/// components represent the color intensity. This color intensity value range
comment|/// from a minimum intensity of 0 to maximum intensity of 255.
comment|///
name|PixelBlueGreenRedReserved8BitPerColor
block|,
comment|///
comment|/// The Pixel definition of the physical frame buffer.
comment|///
name|PixelBitMask
block|,
comment|///
comment|/// This mode does not support a physical frame buffer.
comment|///
name|PixelBltOnly
block|,
comment|///
comment|/// Valid EFI_GRAPHICS_PIXEL_FORMAT enum values are less than this value.
comment|///
name|PixelFormatMax
block|}
name|EFI_GRAPHICS_PIXEL_FORMAT
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The version of this data structure. A value of zero represents the
comment|/// EFI_GRAPHICS_OUTPUT_MODE_INFORMATION structure as defined in this specification.
comment|///
name|UINT32
name|Version
decl_stmt|;
comment|///
comment|/// The size of video screen in pixels in the X dimension.
comment|///
name|UINT32
name|HorizontalResolution
decl_stmt|;
comment|///
comment|/// The size of video screen in pixels in the Y dimension.
comment|///
name|UINT32
name|VerticalResolution
decl_stmt|;
comment|///
comment|/// Enumeration that defines the physical format of the pixel. A value of PixelBltOnly
comment|/// implies that a linear frame buffer is not available for this mode.
comment|///
name|EFI_GRAPHICS_PIXEL_FORMAT
name|PixelFormat
decl_stmt|;
comment|///
comment|/// This bit-mask is only valid if PixelFormat is set to PixelPixelBitMask.
comment|/// A bit being set defines what bits are used for what purpose such as Red, Green, Blue, or Reserved.
comment|///
name|EFI_PIXEL_BITMASK
name|PixelInformation
decl_stmt|;
comment|///
comment|/// Defines the number of pixel elements per video memory line.
comment|///
name|UINT32
name|PixelsPerScanLine
decl_stmt|;
block|}
name|EFI_GRAPHICS_OUTPUT_MODE_INFORMATION
typedef|;
end_typedef

begin_comment
comment|/**   Returns information for an available graphics mode that the graphics device   and the set of active video output devices supports.    @param  This                  The EFI_GRAPHICS_OUTPUT_PROTOCOL instance.   @param  ModeNumber            The mode number to return information on.   @param  SizeOfInfo            A pointer to the size, in bytes, of the Info buffer.   @param  Info                  A pointer to callee allocated buffer that returns information about ModeNumber.    @retval EFI_SUCCESS           Valid mode information was returned.   @retval EFI_DEVICE_ERROR      A hardware error occurred trying to retrieve the video mode.   @retval EFI_INVALID_PARAMETER ModeNumber is not valid.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_GRAPHICS_OUTPUT_PROTOCOL_QUERY_MODE
function_decl|)
parameter_list|(
name|IN
name|EFI_GRAPHICS_OUTPUT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|ModeNumber
parameter_list|,
name|OUT
name|UINTN
modifier|*
name|SizeOfInfo
parameter_list|,
name|OUT
name|EFI_GRAPHICS_OUTPUT_MODE_INFORMATION
modifier|*
modifier|*
name|Info
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Set the video device into the specified mode and clears the visible portions of    the output display to black.    @param  This              The EFI_GRAPHICS_OUTPUT_PROTOCOL instance.   @param  ModeNumber        Abstraction that defines the current video mode.    @retval EFI_SUCCESS       The graphics mode specified by ModeNumber was selected.   @retval EFI_DEVICE_ERROR  The device had an error and could not complete the request.   @retval EFI_UNSUPPORTED   ModeNumber is not supported by this device.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_GRAPHICS_OUTPUT_PROTOCOL_SET_MODE
function_decl|)
parameter_list|(
name|IN
name|EFI_GRAPHICS_OUTPUT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|UINT32
name|ModeNumber
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|UINT8
name|Blue
decl_stmt|;
name|UINT8
name|Green
decl_stmt|;
name|UINT8
name|Red
decl_stmt|;
name|UINT8
name|Reserved
decl_stmt|;
block|}
name|EFI_GRAPHICS_OUTPUT_BLT_PIXEL
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
block|{
name|EFI_GRAPHICS_OUTPUT_BLT_PIXEL
name|Pixel
decl_stmt|;
name|UINT32
name|Raw
decl_stmt|;
block|}
name|EFI_GRAPHICS_OUTPUT_BLT_PIXEL_UNION
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// actions for BltOperations
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
comment|///
comment|/// Write data from the BltBuffer pixel (0, 0)
comment|/// directly to every pixel of the video display rectangle
comment|/// (DestinationX, DestinationY) (DestinationX + Width, DestinationY + Height).
comment|/// Only one pixel will be used from the BltBuffer. Delta is NOT used.
comment|///
name|EfiBltVideoFill
block|,
comment|///
comment|/// Read data from the video display rectangle
comment|/// (SourceX, SourceY) (SourceX + Width, SourceY + Height) and place it in
comment|/// the BltBuffer rectangle (DestinationX, DestinationY )
comment|/// (DestinationX + Width, DestinationY + Height). If DestinationX or
comment|/// DestinationY is not zero then Delta must be set to the length in bytes
comment|/// of a row in the BltBuffer.
comment|///
name|EfiBltVideoToBltBuffer
block|,
comment|///
comment|/// Write data from the BltBuffer rectangle
comment|/// (SourceX, SourceY) (SourceX + Width, SourceY + Height) directly to the
comment|/// video display rectangle (DestinationX, DestinationY)
comment|/// (DestinationX + Width, DestinationY + Height). If SourceX or SourceY is
comment|/// not zero then Delta must be set to the length in bytes of a row in the
comment|/// BltBuffer.
comment|///
name|EfiBltBufferToVideo
block|,
comment|///
comment|/// Copy from the video display rectangle (SourceX, SourceY)
comment|/// (SourceX + Width, SourceY + Height) to the video display rectangle
comment|/// (DestinationX, DestinationY) (DestinationX + Width, DestinationY + Height).
comment|/// The BltBuffer and Delta are not used in this mode.
comment|///
name|EfiBltVideoToVideo
block|,
name|EfiGraphicsOutputBltOperationMax
block|}
name|EFI_GRAPHICS_OUTPUT_BLT_OPERATION
typedef|;
end_typedef

begin_comment
comment|/**   Blt a rectangle of pixels on the graphics screen. Blt stands for BLock Transfer.      @param  This         Protocol instance pointer.   @param  BltBuffer    The data to transfer to the graphics screen.                        Size is at least Width*Height*sizeof(EFI_GRAPHICS_OUTPUT_BLT_PIXEL).   @param  BltOperation The operation to perform when copying BltBuffer on to the graphics screen.   @param  SourceX      The X coordinate of source for the BltOperation.   @param  SourceY      The Y coordinate of source for the BltOperation.   @param  DestinationX The X coordinate of destination for the BltOperation.   @param  DestinationY The Y coordinate of destination for the BltOperation.   @param  Width        The width of a rectangle in the blt rectangle in pixels.   @param  Height       The height of a rectangle in the blt rectangle in pixels.   @param  Delta        Not used for EfiBltVideoFill or the EfiBltVideoToVideo operation.                        If a Delta of zero is used, the entire BltBuffer is being operated on.                        If a subrectangle of the BltBuffer is being used then Delta                        represents the number of bytes in a row of the BltBuffer.    @retval EFI_SUCCESS           BltBuffer was drawn to the graphics screen.   @retval EFI_INVALID_PARAMETER BltOperation is not valid.   @retval EFI_DEVICE_ERROR      The device had an error and could not complete the request.  **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_GRAPHICS_OUTPUT_PROTOCOL_BLT
function_decl|)
parameter_list|(
name|IN
name|EFI_GRAPHICS_OUTPUT_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|EFI_GRAPHICS_OUTPUT_BLT_PIXEL
modifier|*
name|BltBuffer
parameter_list|,
name|OPTIONAL
name|IN
name|EFI_GRAPHICS_OUTPUT_BLT_OPERATION
name|BltOperation
parameter_list|,
name|IN
name|UINTN
name|SourceX
parameter_list|,
name|IN
name|UINTN
name|SourceY
parameter_list|,
name|IN
name|UINTN
name|DestinationX
parameter_list|,
name|IN
name|UINTN
name|DestinationY
parameter_list|,
name|IN
name|UINTN
name|Width
parameter_list|,
name|IN
name|UINTN
name|Height
parameter_list|,
name|IN
name|UINTN
name|Delta
name|OPTIONAL
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
comment|///
comment|/// The number of modes supported by QueryMode() and SetMode().
comment|///
name|UINT32
name|MaxMode
decl_stmt|;
comment|///
comment|/// Current Mode of the graphics device. Valid mode numbers are 0 to MaxMode -1.
comment|///
name|UINT32
name|Mode
decl_stmt|;
comment|///
comment|/// Pointer to read-only EFI_GRAPHICS_OUTPUT_MODE_INFORMATION data.
comment|///
name|EFI_GRAPHICS_OUTPUT_MODE_INFORMATION
modifier|*
name|Info
decl_stmt|;
comment|///
comment|/// Size of Info structure in bytes.
comment|///
name|UINTN
name|SizeOfInfo
decl_stmt|;
comment|///
comment|/// Base address of graphics linear frame buffer.
comment|/// Offset zero in FrameBufferBase represents the upper left pixel of the display.
comment|///
name|EFI_PHYSICAL_ADDRESS
name|FrameBufferBase
decl_stmt|;
comment|///
comment|/// Amount of frame buffer needed to support the active mode as defined by
comment|/// PixelsPerScanLine xVerticalResolution x PixelElementSize.
comment|///
name|UINTN
name|FrameBufferSize
decl_stmt|;
block|}
name|EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE
typedef|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// Provides a basic abstraction to set video modes and copy pixels to and from
end_comment

begin_comment
comment|/// the graphics controller's frame buffer. The linear address of the hardware
end_comment

begin_comment
comment|/// frame buffer is also exposed so software can write directly to the video hardware.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_GRAPHICS_OUTPUT_PROTOCOL
block|{
name|EFI_GRAPHICS_OUTPUT_PROTOCOL_QUERY_MODE
name|QueryMode
decl_stmt|;
name|EFI_GRAPHICS_OUTPUT_PROTOCOL_SET_MODE
name|SetMode
decl_stmt|;
name|EFI_GRAPHICS_OUTPUT_PROTOCOL_BLT
name|Blt
decl_stmt|;
comment|///
comment|/// Pointer to EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE data.
comment|///
name|EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE
modifier|*
name|Mode
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiGraphicsOutputProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

