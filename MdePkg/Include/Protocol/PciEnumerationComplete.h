begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   PCI Enumeration Complete Protocol as defined in the PI 1.1 specification.   This protocol indicates that pci enumeration complete    Copyright (c) 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This Protocol is defined in UEFI Platform Initialization Specification 1.2   Volume 5: Standards  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PCI_ENUMERATION_COMPLETE_H_
end_ifndef

begin_define
define|#
directive|define
name|_PCI_ENUMERATION_COMPLETE_H_
end_define

begin_define
define|#
directive|define
name|EFI_PCI_ENUMERATION_COMPLETE_GUID
define|\
value|{  \    0x30cfe3e7, 0x3de1, 0x4586, { 0xbe, 0x20, 0xde, 0xab, 0xa1, 0xb3, 0xb7, 0x93  } \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPciEnumerationCompleteProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

