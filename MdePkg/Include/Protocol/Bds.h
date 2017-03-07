begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Boot Device Selection Architectural Protocol as defined in PI spec Volume 2 DXE    When the DXE core is done it calls the BDS via this protocol.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ARCH_PROTOCOL_BDS_H__
end_ifndef

begin_define
define|#
directive|define
name|__ARCH_PROTOCOL_BDS_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the BDS Architectural Protocol
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_BDS_ARCH_PROTOCOL_GUID
define|\
value|{ 0x665E3FF6, 0x46CC, 0x11d4, {0x9A, 0x38, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D } }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Declare forward reference for the BDS Architectural Protocol
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|struct
name|_EFI_BDS_ARCH_PROTOCOL
name|EFI_BDS_ARCH_PROTOCOL
typedef|;
end_typedef

begin_comment
comment|/**   This function uses policy data from the platform to determine what operating    system or system utility should be loaded and invoked.  This function call    also optionally make the use of user input to determine the operating system    or system utility to be loaded and invoked.  When the DXE Core has dispatched    all the drivers on the dispatch queue, this function is called.  This    function will attempt to connect the boot devices required to load and invoke    the selected operating system or system utility.  During this process,    additional firmware volumes may be discovered that may contain addition DXE    drivers that can be dispatched by the DXE Core.   If a boot device cannot be    fully connected, this function calls the DXE Service Dispatch() to allow the    DXE drivers from any newly discovered firmware volumes to be dispatched.     Then the boot device connection can be attempted again.  If the same boot    device connection operation fails twice in a row, then that boot device has    failed, and should be skipped.  This function should never return.    @param  This             The EFI_BDS_ARCH_PROTOCOL instance.    @return None.  **/
end_comment

begin_typedef
typedef|typedef
name|VOID
function_decl|(
name|EFIAPI
modifier|*
name|EFI_BDS_ENTRY
function_decl|)
parameter_list|(
name|IN
name|EFI_BDS_ARCH_PROTOCOL
modifier|*
name|This
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|///
end_comment

begin_comment
comment|/// The EFI_BDS_ARCH_PROTOCOL transfers control from DXE to an operating
end_comment

begin_comment
comment|/// system or a system utility.  If there are not enough drivers initialized
end_comment

begin_comment
comment|/// when this protocol is used to access the required boot device(s), then
end_comment

begin_comment
comment|/// this protocol should add drivers to the dispatch queue and return control
end_comment

begin_comment
comment|/// back to the dispatcher.  Once the required boot devices are available, then
end_comment

begin_comment
comment|/// the boot device can be used to load and invoke an OS or a system utility.
end_comment

begin_comment
comment|///
end_comment

begin_struct
struct|struct
name|_EFI_BDS_ARCH_PROTOCOL
block|{
name|EFI_BDS_ENTRY
name|Entry
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiBdsArchProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

