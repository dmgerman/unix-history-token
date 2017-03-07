begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Real Time clock Architectural Protocol as defined in PI Specification VOLUME 2 DXE    This code abstracts time and data functions. Used to provide   Time and date related EFI runtime services.    The GetTime (), SetTime (), GetWakeupTime (), and SetWakeupTime () UEFI 2.0   services are added to the EFI system table and the    EFI_REAL_TIME_CLOCK_ARCH_PROTOCOL_GUID protocol is registered with a NULL    pointer.    No CRC of the EFI system table is required, since that is done in the DXE core.    Copyright (c) 2006 - 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.               **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__ARCH_PROTOCOL_REAL_TIME_CLOCK_H__
end_ifndef

begin_define
define|#
directive|define
name|__ARCH_PROTOCOL_REAL_TIME_CLOCK_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// Global ID for the Real Time Clock Architectural Protocol
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_REAL_TIME_CLOCK_ARCH_PROTOCOL_GUID
define|\
value|{ 0x27CFAC87, 0x46CC, 0x11d4, {0x9A, 0x38, 0x00, 0x90, 0x27, 0x3F, 0xC1, 0x4D } }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiRealTimeClockArchProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

