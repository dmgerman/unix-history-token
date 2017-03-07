begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares EFI PCI Override protocol which provides the interface between   the PCI bus driver/PCI Host Bridge Resource Allocation driver and an implementation's   driver to describe the unique features of a platform.   This protocol is optional.    Copyright (c) 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is defined in UEFI Platform Initialization Specification 1.2   Volume 5: Standards  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCI_OVERRIDE_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCI_OVERRIDE_H_
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI_PCI_OVERRIDE_PROTOCOL has the same structure with EFI_PCI_PLATFORM_PROTOCOL
end_comment

begin_comment
comment|///
end_comment

begin_include
include|#
directive|include
file|<Protocol/PciPlatform.h>
end_include

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the EFI_PCI_OVERRIDE_PROTOCOL
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_PCI_OVERRIDE_GUID
define|\
value|{ \     0xb5b35764, 0x460c, 0x4a06, {0x99, 0xfc, 0x77, 0xa1, 0x7c, 0x1b, 0x5c, 0xeb} \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Declaration for EFI_PCI_OVERRIDE_PROTOCOL
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|EFI_PCI_PLATFORM_PROTOCOL
name|EFI_PCI_OVERRIDE_PROTOCOL
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPciOverrideProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

