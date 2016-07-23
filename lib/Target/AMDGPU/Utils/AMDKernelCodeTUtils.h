begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AMDGPUKernelCodeTUtils.h - helpers for amd_kernel_code_t  *- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                     The LLVM Compiler Infrastructure
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This file is distributed under the University of Illinois Open Source
end_comment

begin_comment
comment|// License. See LICENSE.TXT for details.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// \file AMDKernelCodeTUtils.h
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AMDKERNELCODETUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|AMDKERNELCODETUTILS_H
end_define

begin_include
include|#
directive|include
file|"AMDKernelCodeT.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmLexer
decl_stmt|;
name|class
name|MCAsmParser
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|void
name|printAmdKernelCodeField
parameter_list|(
specifier|const
name|amd_kernel_code_t
modifier|&
name|C
parameter_list|,
name|int
name|FldIndex
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|)
function_decl|;
name|void
name|dumpAmdKernelCode
parameter_list|(
specifier|const
name|amd_kernel_code_t
modifier|*
name|C
parameter_list|,
name|raw_ostream
modifier|&
name|OS
parameter_list|,
specifier|const
name|char
modifier|*
name|tab
parameter_list|)
function_decl|;
name|bool
name|parseAmdKernelCodeField
parameter_list|(
name|StringRef
name|ID
parameter_list|,
name|MCAsmParser
modifier|&
name|Parser
parameter_list|,
name|amd_kernel_code_t
modifier|&
name|C
parameter_list|,
name|raw_ostream
modifier|&
name|Err
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// AMDKERNELCODETUTILS_H
end_comment

end_unit

