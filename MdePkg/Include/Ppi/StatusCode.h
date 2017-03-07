begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/** @file   This file declares Status Code PPI.   This ppi provides a service that allows PEIMs to report status codes.    Copyright (c) 2006 - 2009, Intel Corporation. All rights reserved.<BR>   This program and the accompanying materials                             are licensed and made available under the terms and conditions of the BSD License            which accompanies this distribution.  The full text of the license may be found at           http://opensource.org/licenses/bsd-license.php                                                THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                        WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.                 @par Revision Reference:   This PPI is introduced in PI Version 1.0.  **/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__STATUS_CODE_PPI_H__
end_ifndef

begin_define
define|#
directive|define
name|__STATUS_CODE_PPI_H__
end_define

begin_define
define|#
directive|define
name|EFI_PEI_REPORT_PROGRESS_CODE_PPI_GUID
define|\
value|{ 0x229832d3, 0x7a30, 0x4b36, {0xb8, 0x27, 0xf4, 0xc, 0xb7, 0xd4, 0x54, 0x36 } }
end_define

begin_comment
comment|//
end_comment

begin_comment
comment|// EFI_PEI_PROGRESS_CODE_PPI.ReportStatusCode() is equivalent to the
end_comment

begin_comment
comment|// PEI Service ReportStatusCode().
end_comment

begin_comment
comment|// It is introduced in PIPeiCis.h.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This PPI provides the service to report status code.
end_comment

begin_comment
comment|/// There can be only one instance of this service in the system.
end_comment

begin_comment
comment|///
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|EFI_PEI_REPORT_STATUS_CODE
name|ReportStatusCode
decl_stmt|;
block|}
name|EFI_PEI_PROGRESS_CODE_PPI
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|EFI_GUID
name|gEfiPeiStatusCodePpiGuid
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

