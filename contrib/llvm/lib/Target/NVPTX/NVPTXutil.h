begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- NVPTXutil.h - Functions exported to CodeGen --*- C++ -*-===//
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
comment|//
end_comment

begin_comment
comment|// This file contains the functions that can be used in CodeGen.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_LIB_TARGET_NVPTX_NVPTXUTIL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_LIB_TARGET_NVPTX_NVPTXUTIL_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunction.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineInstr.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|bool
name|isParamLoad
parameter_list|(
specifier|const
name|MachineInstr
modifier|*
parameter_list|)
function_decl|;
name|uint64_t
name|encode_leb128
parameter_list|(
specifier|const
name|char
modifier|*
name|str
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

