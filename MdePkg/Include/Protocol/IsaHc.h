begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   ISA HC Protocol as defined in the PI 1.2.1 specification.    This protocol provides registration for ISA devices on a positive- or   subtractive-decode ISA bus. It allows devices to be registered and also   handles opening and closing the apertures which are positively-decoded.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This protocol is from PI Version 1.2.1.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ISA_HC_PROTOCOL_H__
end_ifndef

begin_define
define|#
directive|define
name|__ISA_HC_PROTOCOL_H__
end_define

begin_define
define|#
directive|define
name|EFI_ISA_HC_PROTOCOL_GUID
define|\
value|{ \     0xbcdaf080, 0x1bde, 0x4e22, {0xae, 0x6a, 0x43, 0x54, 0x1e, 0x12, 0x8e, 0xc4} \   }
end_define

begin_define
define|#
directive|define
name|EFI_ISA_HC_SERVICE_BINDING_PROTOCOL_GUID
define|\
value|{ \     0xfad7933a, 0x6c21, 0x4234, {0xa4, 0x34, 0x0a, 0x8a, 0x0d, 0x2b, 0x07, 0x81} \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_ISA_HC_PROTOCOL
name|EFI_ISA_HC_PROTOCOL
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|_EFI_ISA_HC_PROTOCOL
modifier|*
name|PEFI_ISA_HC_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Open I/O aperture.    This function opens an I/O aperture in a ISA Host Controller for the I/O addresses   specified by IoAddress to IoAddress + IoLength - 1. It may be possible that a   single hardware aperture may be used for more than one device. This function   tracks the number of times that each aperture is referenced, and does not close   the hardware aperture (via CloseIoAperture()) until there are no more references to it.    @param This             A pointer to this instance of the EFI_ISA_HC_PROTOCOL.   @param IoAddress        An unsigned integer that specifies the first byte of the                           I/O space required.   @param IoLength         An unsigned integer that specifies the number of bytes                           of the I/O space required.   @param IoApertureHandle A pointer to the returned I/O aperture handle. This                           value can be used on subsequent calls to CloseIoAperture().    @retval EFI_SUCCESS          The I/O aperture was opened successfully.   @retval EFI_UNSUPPORTED      The ISA Host Controller is a subtractive-decode controller.   @retval EFI_OUT_OF_RESOURCES There is no available I/O aperture. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ISA_HC_OPEN_IO
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_ISA_HC_PROTOCOL
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
comment|/**   Close I/O aperture.    This function closes a previously opened I/O aperture handle. If there are no   more I/O aperture handles that refer to the hardware I/O aperture resource,   then the hardware I/O aperture is closed. It may be possible that a single   hardware aperture may be used for more than one device. This function tracks   the number of times that each aperture is referenced, and does not close the   hardware aperture (via CloseIoAperture()) until there are no more references to it.    @param This             A pointer to this instance of the EFI_ISA_HC_PROTOCOL.   @param IoApertureHandle The I/O aperture handle previously returned from a                            call to OpenIoAperture().    @retval EFI_SUCCESS     The IO aperture was closed successfully. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_ISA_HC_CLOSE_IO
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_ISA_HC_PROTOCOL
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
comment|/// ISA HC Protocol
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_ISA_HC_PROTOCOL
block|{
comment|///
comment|/// The version of this protocol. Higher version numbers are backward
comment|/// compatible with lower version numbers.
comment|///
name|UINT32
name|Version
decl_stmt|;
comment|///
comment|/// Open an I/O aperture.
comment|///
name|EFI_ISA_HC_OPEN_IO
name|OpenIoAperture
decl_stmt|;
comment|///
comment|/// Close an I/O aperture.
comment|///
name|EFI_ISA_HC_CLOSE_IO
name|CloseIoAperture
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|///
end_comment

begin_comment
comment|/// Reference to variable defined in the .DEC file
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiIsaHcProtocolGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiIsaHcServiceBindingProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|//  __ISA_HC_H__
end_comment

end_unit

