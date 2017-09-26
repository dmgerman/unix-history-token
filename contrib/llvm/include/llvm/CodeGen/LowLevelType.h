begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== llvm/CodeGen/LowLevelType.h ------------------------------- -*- C++ -*-==//
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
comment|/// Implement a low-level type suitable for MachineInstr level instruction
end_comment

begin_comment
comment|/// selection.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This provides the CodeGen aspects of LowLevelType, such as Type conversion.
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
name|LLVM_CODEGEN_LOWLEVELTYPE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_LOWLEVELTYPE_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/LowLevelTypeImpl.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DataLayout
decl_stmt|;
name|class
name|Type
decl_stmt|;
comment|/// Construct a low-level type based on an LLVM type.
name|LLT
name|getLLTForType
parameter_list|(
name|Type
modifier|&
name|Ty
parameter_list|,
specifier|const
name|DataLayout
modifier|&
name|DL
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_LOWLEVELTYPE_H
end_comment

end_unit

