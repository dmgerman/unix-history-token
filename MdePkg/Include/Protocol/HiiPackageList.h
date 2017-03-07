begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   EFI_HII_PACKAGE_LIST_PROTOCOL as defined in UEFI 2.1.   Boot service LoadImage() installs EFI_HII_PACKAGE_LIST_PROTOCOL on the handle   if the image contains a custom PE/COFF resource with the type 'HII'.   The protocol's interface pointer points to the HII package list, which is   contained in the resource's data.      Copyright (c) 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HII_PACKAGE_LIST_H__
end_ifndef

begin_define
define|#
directive|define
name|__HII_PACKAGE_LIST_H__
end_define

begin_define
define|#
directive|define
name|EFI_HII_PACKAGE_LIST_PROTOCOL_GUID
define|\
value|{ 0x6a1ee763, 0xd47a, 0x43b4, {0xaa, 0xbe, 0xef, 0x1d, 0xe2, 0xab, 0x56, 0xfc}}
end_define

begin_typedef
typedef|typedef
name|EFI_HII_PACKAGE_LIST_HEADER
modifier|*
name|EFI_HII_PACKAGE_LIST_PROTOCOL
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHiiPackageListProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

