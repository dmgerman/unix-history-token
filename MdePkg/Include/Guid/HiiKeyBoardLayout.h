begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file    HII keyboard layout GUID as defined in UEFI2.1 specification      Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   GUIDs defined in UEFI 2.1 spec.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__HII_KEYBOARD_LAYOUT_GUID_H__
end_ifndef

begin_define
define|#
directive|define
name|__HII_KEYBOARD_LAYOUT_GUID_H__
end_define

begin_define
define|#
directive|define
name|EFI_HII_SET_KEYBOARD_LAYOUT_EVENT_GUID
define|\
value|{ 0x14982a4f, 0xb0ed, 0x45b8, { 0xa8, 0x11, 0x5a, 0x7a, 0x9b, 0xc2, 0x32, 0xdf }}
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHiiKeyBoardLayoutGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

