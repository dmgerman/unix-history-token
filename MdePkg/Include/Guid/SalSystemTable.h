begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   GUIDs used for SAL system table entries in the EFI system table.    SAL System Table contains Itanium-based processor centric information about   the system.    Copyright (c) 2006 - 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   GUIDs defined in UEFI 2.0 spec.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__SAL_SYSTEM_TABLE_GUID_H__
end_ifndef

begin_define
define|#
directive|define
name|__SAL_SYSTEM_TABLE_GUID_H__
end_define

begin_define
define|#
directive|define
name|SAL_SYSTEM_TABLE_GUID
define|\
value|{ \     0xeb9d2d32, 0x2d88, 0x11d3, {0x9a, 0x16, 0x0, 0x90, 0x27, 0x3f, 0xc1, 0x4d } \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiSalSystemTableGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

