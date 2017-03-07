begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares Reset2 PPI used to reset the platform.    This PPI is installed by some platform- or chipset-specific PEIM that   abstracts the Reset Service to other agents.    Copyright (c) 2015, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials   are licensed and made available under the terms and conditions of the BSD License   which accompanies this distribution.  The full text of the license may be found at   http://opensource.org/licenses/bsd-license.php    THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,   WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.    @par Revision Reference:   This PPI is introduced in PI Version 1.4.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__RESET2_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__RESET2_PPI_H__
end_define

begin_define
define|#
directive|define
name|EFI_PEI_RESET2_PPI_GUID
define|\
value|{ \     0x6cc45765, 0xcce4, 0x42fd, {0xbc, 0x56, 0x1, 0x1a, 0xaa, 0xc6, 0xc9, 0xa8 } \   }
end_define

begin_comment
comment|///
end_comment

begin_comment
comment|/// This PPI provides provide a simple reset service.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_EFI_PEI_RESET2_PPI
block|{
name|EFI_PEI_RESET2_SYSTEM
name|ResetSystem
decl_stmt|;
block|}
name|EFI_PEI_RESET2_PPI
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiReset2PpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

