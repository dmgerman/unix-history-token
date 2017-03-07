begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   S3 SMM Save State Protocol as defined in PI1.2 Specification VOLUME 5 Standard.    The EFI_S3_SMM_SAVE_STATE_PROTOCOL publishes the PI SMMboot script abstractions   On an S3 resume boot path the data stored via this protocol is replayed in the order it was stored.   The order of replay is the order either of the S3 Save State Protocol or S3 SMM Save State Protocol   Write() functions were called during the boot process. Insert(), Label(), and   Compare() operations are ordered relative other S3 SMM Save State Protocol write() operations   and the order relative to S3 State Save Write() operations is not defined. Due to these ordering   restrictions it is recommended that the S3 State Save Protocol be used during the DXE phase when   every possible.   The EFI_S3_SMM_SAVE_STATE_PROTOCOL can be called at runtime and   EFI_OUT_OF_RESOURCES may be returned from a runtime call. It is the responsibility of the   platform to ensure enough memory resource exists to save the system state. It is recommended that   runtime calls be minimized by the caller.      Copyright (c) 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.       @par Revision Reference:   This PPI is defined in UEFI Platform Initialization Specification 1.2 Volume 5:    Standards            **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__S3_SMM_SAVE_STATE_H__
end_ifndef

begin_define
define|#
directive|define
name|__S3_SMM_SAVE_STATE_H__
end_define

begin_include
include|#
directive|include
file|<Protocol/S3SaveState.h>
end_include

begin_define
define|#
directive|define
name|EFI_S3_SMM_SAVE_STATE_PROTOCOL_GUID
define|\
value|{0x320afe62, 0xe593, 0x49cb, { 0xa9, 0xf1, 0xd4, 0xc2, 0xf4, 0xaf, 0x1, 0x4c }}
end_define

begin_typedef
typedef|typedef
name|EFI_S3_SAVE_STATE_PROTOCOL
name|EFI_S3_SMM_SAVE_STATE_PROTOCOL
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiS3SmmSaveStateProtocolGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// __S3_SMM_SAVE_STATE_H__
end_comment

end_unit

