begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   Present the dependency expression values in PI.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   PI Version 1.0  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PI_DEPENDENCY_H__
end_ifndef

begin_define
define|#
directive|define
name|__PI_DEPENDENCY_H__
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If present, this must be the first and only opcode,
end_comment

begin_comment
comment|/// EFI_DEP_BEFORE may be used by DXE and SMM drivers.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DEP_BEFORE
value|0x00
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If present, this must be the first and only opcode,
end_comment

begin_comment
comment|/// EFI_DEP_AFTER may be used by DXE and SMM drivers.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DEP_AFTER
value|0x01
end_define

begin_define
define|#
directive|define
name|EFI_DEP_PUSH
value|0x02
end_define

begin_define
define|#
directive|define
name|EFI_DEP_AND
value|0x03
end_define

begin_define
define|#
directive|define
name|EFI_DEP_OR
value|0x04
end_define

begin_define
define|#
directive|define
name|EFI_DEP_NOT
value|0x05
end_define

begin_define
define|#
directive|define
name|EFI_DEP_TRUE
value|0x06
end_define

begin_define
define|#
directive|define
name|EFI_DEP_FALSE
value|0x07
end_define

begin_define
define|#
directive|define
name|EFI_DEP_END
value|0x08
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// If present, this must be the first opcode,
end_comment

begin_comment
comment|/// EFI_DEP_SOR is only used by DXE driver.
end_comment

begin_comment
comment|///
end_comment

begin_define
define|#
directive|define
name|EFI_DEP_SOR
value|0x09
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

