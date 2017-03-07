begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   GUID indicates that the form set contains forms designed to be used    for platform configuration and this form set will be displayed.  Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.<BR> This program and the accompanying materials are licensed and made available under  the terms and conditions of the BSD License that accompanies this distribution.   The full text of the license may be found at http://opensource.org/licenses/bsd-license.php.                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                      WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   GUID defined in UEFI 2.1.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HII_PLATFORM_SETUP_FORMSET_GUID_H__
end_ifndef

begin_define
define|#
directive|define
name|__HII_PLATFORM_SETUP_FORMSET_GUID_H__
end_define

begin_define
define|#
directive|define
name|EFI_HII_PLATFORM_SETUP_FORMSET_GUID
define|\
value|{ 0x93039971, 0x8545, 0x4b04, { 0xb4, 0x5e, 0x32, 0xeb, 0x83, 0x26, 0x4, 0xe } }
end_define

begin_define
define|#
directive|define
name|EFI_HII_DRIVER_HEALTH_FORMSET_GUID
define|\
value|{ 0xf22fc20c, 0x8cf4, 0x45eb, { 0x8e, 0x6, 0xad, 0x4e, 0x50, 0xb9, 0x5d, 0xd3 } }
end_define

begin_define
define|#
directive|define
name|EFI_HII_USER_CREDENTIAL_FORMSET_GUID
define|\
value|{ 0x337f4407, 0x5aee, 0x4b83, { 0xb2, 0xa7, 0x4e, 0xad, 0xca, 0x30, 0x88, 0xcd } }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHiiPlatformSetupFormsetGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHiiDriverHealthFormsetGuid
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHiiUserCredentialFormsetGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

