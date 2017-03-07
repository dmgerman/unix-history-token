begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This PPI opens or closes an I/O aperture in a ISA HOST controller.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is from PI Version 1.2.1.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ISA_HC_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__ISA_HC_PPI_H__
end_define

begin_define
define|#
directive|define
name|EFI_ISA_HC_PPI_GUID
define|\
value|{ \     0x8d48bd70, 0xc8a3, 0x4c06, {0x90, 0x1b, 0x74, 0x79, 0x46, 0xaa, 0xc3, 0x58} \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_ISA_HC_PPI
name|EFI_ISA_HC_PPI
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_EFI_ISA_HC_PPI
modifier|*
name|PEFI_ISA_HC_PPI
typedef|;
end_typedef

begin_comment
comment|/**   Open I/O aperture.    This function opens an I/O aperture in a ISA Host Controller for the I/O   addresses specified by IoAddress to IoAddress + IoLength - 1. It is possible   that more than one caller may be assigned to the same aperture.   It may be possible that a single hardware aperture may be used for more than   one device. This function tracks the number of times that each aperture is    referenced, and doesa not close the hardware aperture (via CloseIoAperture())   until there are no more references to it.     @param This             A pointer to this instance of the EFI_ISA_HC_PPI.   @param IoAddress        An unsigned integer that specifies the first byte of                           the I/O space required.   @param IoLength         An unsigned integer that specifies the number of                           bytes of the I/O space required.   @param IoApertureHandle A pointer to the returned I/O aperture handle.                           This value can be used on subsequent calls to CloseIoAperture().    @retval EFI_SUCCESS          The I/O aperture was opened successfully.   @retval EFI_UNSUPPORTED      The ISA Host Controller is a subtractive-decode controller.   @retval EFI_OUT_OF_RESOURCES There is no available I/O aperture. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_ISA_HC_OPEN_IO
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_ISA_HC_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINT16
name|IoAddress
parameter_list|,
name|IN
name|UINT16
name|IoLength
parameter_list|,
name|OUT
name|UINT64
modifier|*
name|IoApertureHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/**   Close I/O aperture.    This function closes a previously opened I/O aperture handle. If there are no   more I/O aperture handles that refer to the hardware I/O aperture resource,   then the hardware I/O aperture is closed.   It may be possible that a single hardware aperture may be used for more than   one device. This function tracks the number of times that each aperture is   referenced, and does not close the hardware aperture (via CloseIoAperture())   until there are no more references to it.    @param This             A pointer to this instance of the EFI_ISA_HC_PPI.   @param IoApertureHandle The I/O aperture handle previously returned from a                           call to OpenIoAperture().    @retval EFI_SUCCESS   The I/O aperture was closed successfully. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_PEI_ISA_HC_CLOSE_IO
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_ISA_HC_PPI
modifier|*
name|This
parameter_list|,
name|IN
name|UINT64
name|IoApertureHandle
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// This PPI provides functions for opening or closing an I/O aperture.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_ISA_HC_PPI
block|{
comment|///
comment|/// An unsigned integer that specifies the version of the PPI structure.
comment|///
name|UINT32
name|Version
decl_stmt|;
comment|///
comment|/// The address of the ISA/LPC Bridge device.
comment|/// For PCI, this is the segment, bus, device and function of the a ISA/LPC
comment|/// Bridge device.
comment|///
comment|/// If bits 24-31 are 0, then the definition is:
comment|/// Bits 0:2   - Function
comment|/// Bits 3-7   - Device
comment|/// Bits 8:15  - Bus
comment|/// Bits 16-23 - Segment
comment|/// Bits 24-31 - Bus Type
comment|/// If bits 24-31 are 0xff, then the definition is platform-specific.
comment|///
name|UINT32
name|Address
decl_stmt|;
comment|///
comment|/// Opens an aperture on a positive-decode ISA Host Controller.
comment|///
name|EFI_PEI_ISA_HC_OPEN_IO
name|OpenIoAperture
decl_stmt|;
comment|///
comment|/// Closes an aperture on a positive-decode ISA Host Controller.
comment|///
name|EFI_PEI_ISA_HC_CLOSE_IO
name|CloseIoAperture
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiIsaHcPpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

