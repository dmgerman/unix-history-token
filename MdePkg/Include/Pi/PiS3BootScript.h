begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file contains the boot script defintions that are shared between the    Boot Script Executor PPI and the Boot Script Save Protocol.    Copyright (c) 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PI_S3_BOOT_SCRIPT_H_
end_ifndef

begin_define
define|#
directive|define
name|_PI_S3_BOOT_SCRIPT_H_
end_define

begin_comment
comment|//*******************************************
end_comment

begin_comment
comment|// EFI Boot Script Opcode definitions
end_comment

begin_comment
comment|//*******************************************
end_comment

begin_define
define|#
directive|define
name|EFI_BOOT_SCRIPT_IO_WRITE_OPCODE
value|0x00
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_SCRIPT_IO_READ_WRITE_OPCODE
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_SCRIPT_MEM_WRITE_OPCODE
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_SCRIPT_MEM_READ_WRITE_OPCODE
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_SCRIPT_PCI_CONFIG_WRITE_OPCODE
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_SCRIPT_PCI_CONFIG_READ_WRITE_OPCODE
value|0x05
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_SCRIPT_SMBUS_EXECUTE_OPCODE
value|0x06
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_SCRIPT_STALL_OPCODE
value|0x07
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_SCRIPT_DISPATCH_OPCODE
value|0x08
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_SCRIPT_DISPATCH_2_OPCODE
value|0x09
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_SCRIPT_INFORMATION_OPCODE
value|0x0A
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_SCRIPT_PCI_CONFIG2_WRITE_OPCODE
value|0x0B
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_SCRIPT_PCI_CONFIG2_READ_WRITE_OPCODE
value|0x0C
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_SCRIPT_IO_POLL_OPCODE
value|0x0D
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_SCRIPT_MEM_POLL_OPCODE
value|0x0E
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_SCRIPT_PCI_CONFIG_POLL_OPCODE
value|0x0F
end_define

begin_define
define|#
directive|define
name|EFI_BOOT_SCRIPT_PCI_CONFIG2_POLL_OPCODE
value|0x10
end_define

begin_comment
comment|//*******************************************
end_comment

begin_comment
comment|// EFI_BOOT_SCRIPT_WIDTH
end_comment

begin_comment
comment|//*******************************************
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|EfiBootScriptWidthUint8
block|,
name|EfiBootScriptWidthUint16
block|,
name|EfiBootScriptWidthUint32
block|,
name|EfiBootScriptWidthUint64
block|,
name|EfiBootScriptWidthFifoUint8
block|,
name|EfiBootScriptWidthFifoUint16
block|,
name|EfiBootScriptWidthFifoUint32
block|,
name|EfiBootScriptWidthFifoUint64
block|,
name|EfiBootScriptWidthFillUint8
block|,
name|EfiBootScriptWidthFillUint16
block|,
name|EfiBootScriptWidthFillUint32
block|,
name|EfiBootScriptWidthFillUint64
block|,
name|EfiBootScriptWidthMaximum
block|}
name|EFI_BOOT_SCRIPT_WIDTH
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

end_unit

