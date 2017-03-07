begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   GUID is the name of events used with CreateEventEx in order to be notified    when the EFI boot manager is about to boot a legacy boot option.   Events of this type are notificated just before Int19h is invoked.     Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   GUID introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EVENT_LEGACY_BIOS_GUID_H__
end_ifndef

begin_define
define|#
directive|define
name|__EVENT_LEGACY_BIOS_GUID_H__
end_define

begin_define
define|#
directive|define
name|EFI_EVENT_LEGACY_BOOT_GUID
define|\
value|{ 0x2a571201, 0x4966, 0x47f6, {0x8b, 0x86, 0xf3, 0x1e, 0x41, 0xf3, 0x2f, 0x10 } }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiEventLegacyBootGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

