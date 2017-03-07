begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   GUID for hardware error record variables.    Copyright (c) 2007 - 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   GUID defined in UEFI 2.1.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_HARDWARE_ERROR_VARIABLE_GUID_H_
end_ifndef

begin_define
define|#
directive|define
name|_HARDWARE_ERROR_VARIABLE_GUID_H_
end_define

begin_define
define|#
directive|define
name|EFI_HARDWARE_ERROR_VARIABLE
define|\
value|{ \     0x414E6BDD, 0xE47B, 0x47cc, {0xB2, 0x44, 0xBB, 0x61, 0x02, 0x0C, 0xF5, 0x16} \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiHardwareErrorVariableGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

