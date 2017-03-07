begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This PPI is installed by the platform PEIM to designate that a recovery boot    is in progress.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__BOOT_IN_RECOVERY_MODE_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__BOOT_IN_RECOVERY_MODE_PPI_H__
end_define

begin_define
define|#
directive|define
name|EFI_PEI_BOOT_IN_RECOVERY_MODE_PPI
define|\
value|{ \     0x17ee496a, 0xd8e4, 0x4b9a, {0x94, 0xd1, 0xce, 0x82, 0x72, 0x30, 0x8, 0x50 } \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiBootInRecoveryModePpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

