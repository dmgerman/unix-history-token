begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   SMM PCI Root Bridge IO protocol as defined in the PI 1.2 specification.    This protocol provides PCI I/O and memory access within SMM.    Copyright (c) 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SMM_PCI_ROOT_BRIDGE_IO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SMM_PCI_ROOT_BRIDGE_IO_H_
end_define

begin_include
include|#
directive|include
file|<Protocol/PciRootBridgeIo.h>
end_include

begin_define
define|#
directive|define
name|EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL_GUID
define|\
value|{ \     0x8bc1714d, 0xffcb, 0x41c3, { 0x89, 0xdc, 0x6c, 0x74, 0xd0, 0x6d, 0x98, 0xea } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This protocol provides the same functionality as the PCI Root Bridge I/O Protocol defined in the
end_comment

begin_comment
comment|/// UEFI 2.1 Specifcation, section 13.2, except that the functions for Map() and Unmap() may return
end_comment

begin_comment
comment|/// EFI_UNSUPPORTED.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_PCI_ROOT_BRIDGE_IO_PROTOCOL
name|EFI_SMM_PCI_ROOT_BRIDGE_IO_PROTOCOL
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSmmPciRootBridgeIoProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

