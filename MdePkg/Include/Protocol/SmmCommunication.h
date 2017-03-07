begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI SMM Communication Protocol as defined in the PI 1.2 specification.    This protocol provides a means of communicating between drivers outside of SMM and SMI    handlers inside of SMM.      Copyright (c) 2009 - 2011, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMM_COMMUNICATION_H_
end_ifndef

begin_define
define|#
directive|define
name|_SMM_COMMUNICATION_H_
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// Need include this header file for EFI_SMM_COMMUNICATE_HEADER data structure.
end_comment

begin_comment
comment|//
end_comment

begin_include
include|#
directive|include
file|<Uefi/UefiAcpiDataTable.h>
end_include

begin_define
define|#
directive|define
name|EFI_SMM_COMMUNICATION_PROTOCOL_GUID
define|\
value|{ \     0xc68ed8e2, 0x9dc6, 0x4cbd, { 0x9d, 0x94, 0xdb, 0x65, 0xac, 0xc5, 0xc3, 0x32 } \   }
end_define

begin_typedef
typedef|typedef
name|struct
name|_EFI_SMM_COMMUNICATION_PROTOCOL
name|EFI_SMM_COMMUNICATION_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   Communicates with a registered handler.      This function provides a service to send and receive messages from a registered UEFI service.    @param[in] This                The EFI_SMM_COMMUNICATION_PROTOCOL instance.   @param[in] CommBuffer          A pointer to the buffer to convey into SMRAM.   @param[in] CommSize            The size of the data buffer being passed in.On exit, the size of data                                  being returned. Zero if the handler does not wish to reply with any data.    @retval EFI_SUCCESS            The message was successfully posted.   @retval EFI_INVALID_PARAMETER  The CommBuffer was NULL. **/
end_comment

begin_typedef
typedef|typedef
name|EFI_STATUS
function_decl|(
name|EFIAPI
modifier|*
name|EFI_SMM_COMMUNICATE2
function_decl|)
parameter_list|(
name|IN
name|CONST
name|EFI_SMM_COMMUNICATION_PROTOCOL
modifier|*
name|This
parameter_list|,
name|IN
name|OUT
name|VOID
modifier|*
name|CommBuffer
parameter_list|,
name|IN
name|OUT
name|UINTN
modifier|*
name|CommSize
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI SMM Communication Protocol provides runtime services for communicating
end_comment

begin_comment
comment|/// between DXE drivers and a registered SMI handler.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_SMM_COMMUNICATION_PROTOCOL
block|{
name|EFI_SMM_COMMUNICATE2
name|Communicate
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSmmCommunicationProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

