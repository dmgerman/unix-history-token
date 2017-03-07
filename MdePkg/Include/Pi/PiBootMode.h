begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Present the boot mode values in PI.    Copyright (c) 2006 - 2012, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   PI Version 1.2.1A  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PI_BOOT_MODE_H__
end_ifndef

begin_define
define|#
directive|define
name|__PI_BOOT_MODE_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// EFI boot mode
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
name|UINT32
name|EFI_BOOT_MODE
typedef|;
end_typedef

begin_comment
comment|//
end_comment

begin_comment
comment|// 0x21 - 0xf..f are reserved.
end_comment

begin_comment
comment|//
end_comment

begin_define
define|#
directive|define
name|BOOT_WITH_FULL_CONFIGURATION
value|0x00
end_define

begin_define
define|#
directive|define
name|BOOT_WITH_MINIMAL_CONFIGURATION
value|0x01
end_define

begin_define
define|#
directive|define
name|BOOT_ASSUMING_NO_CONFIGURATION_CHANGES
value|0x02
end_define

begin_define
define|#
directive|define
name|BOOT_WITH_FULL_CONFIGURATION_PLUS_DIAGNOSTICS
value|0x03
end_define

begin_define
define|#
directive|define
name|BOOT_WITH_DEFAULT_SETTINGS
value|0x04
end_define

begin_define
define|#
directive|define
name|BOOT_ON_S4_RESUME
value|0x05
end_define

begin_define
define|#
directive|define
name|BOOT_ON_S5_RESUME
value|0x06
end_define

begin_define
define|#
directive|define
name|BOOT_WITH_MFG_MODE_SETTINGS
value|0x07
end_define

begin_define
define|#
directive|define
name|BOOT_ON_S2_RESUME
value|0x10
end_define

begin_define
define|#
directive|define
name|BOOT_ON_S3_RESUME
value|0x11
end_define

begin_define
define|#
directive|define
name|BOOT_ON_FLASH_UPDATE
value|0x12
end_define

begin_define
define|#
directive|define
name|BOOT_IN_RECOVERY_MODE
value|0x20
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

