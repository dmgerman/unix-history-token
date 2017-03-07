begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This PPI will be installed at the end of PEI for all boot paths, including    normal, recovery, and S3. It allows for PEIMs to possibly quiesce hardware,    build handoff information for the next phase of execution,    or provide some terminal processing behavior.    Copyright (c) 2006 - 2008, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__END_OF_PEI_PHASE_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__END_OF_PEI_PHASE_PPI_H__
end_define

begin_define
define|#
directive|define
name|EFI_PEI_END_OF_PEI_PHASE_PPI_GUID
define|\
value|{ \     0x605EA650, 0xC65C, 0x42e1, {0xBA, 0x80, 0x91, 0xA5, 0x2A, 0xB6, 0x18, 0xC6 } \   }
end_define

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiEndOfPeiSignalPpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

