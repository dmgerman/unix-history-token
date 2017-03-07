begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares Memory Discovered PPI.    This PPI is published by the PEI Foundation when the main memory is installed.    It is essentially a PPI with no associated interface. Its purpose is to be used   as a signal for other PEIMs who can register for a notification on its installation.     Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PEI_MEMORY_DISCOVERED_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__PEI_MEMORY_DISCOVERED_PPI_H__
end_define

begin_define
define|#
directive|define
name|EFI_PEI_PERMANENT_MEMORY_INSTALLED_PPI_GUID
define|\
value|{ \     0xf894643d, 0xc449, 0x42d1, {0x8e, 0xa8, 0x85, 0xbd, 0xd8, 0xc6, 0x5b, 0xde } \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiMemoryDiscoveredPpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

