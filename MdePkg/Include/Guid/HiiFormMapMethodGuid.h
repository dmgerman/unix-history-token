begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Guid used to identify HII FormMap configuration method.    Copyright (c) 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   GUID defined in UEFI 2.2 spec. **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EFI_HII_FORMMAP_GUID_H__
end_ifndef

begin_define
define|#
directive|define
name|__EFI_HII_FORMMAP_GUID_H__
end_define

begin_define
define|#
directive|define
name|EFI_HII_STANDARD_FORM_GUID
define|\
value|{ 0x3bd2f4ec, 0xe524, 0x46e4, { 0xa9, 0xd8, 0x51, 0x1, 0x17, 0x42, 0x55, 0x62 } }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHiiStandardFormGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

