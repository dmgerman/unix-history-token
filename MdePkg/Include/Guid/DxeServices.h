begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   GUID used to identify the DXE Services Table    Copyright (c) 2006 - 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   GUID introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DXE_SERVICES_GUID_H__
end_ifndef

begin_define
define|#
directive|define
name|__DXE_SERVICES_GUID_H__
end_define

begin_define
define|#
directive|define
name|DXE_SERVICES_TABLE_GUID
define|\
value|{ \     0x5ad34ba, 0x6f02, 0x4214, {0x95, 0x2e, 0x4d, 0xa0, 0x39, 0x8e, 0x2b, 0xb9 } \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiDxeServicesTableGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

