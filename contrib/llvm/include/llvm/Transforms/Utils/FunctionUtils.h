begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Transform/Utils/FunctionUtils.h - Function Utils --------*- C++ -*-===//
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
comment|// This family of transformations manipulate LLVM functions.
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
name|LLVM_TRANSFORMS_UTILS_FUNCTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_FUNCTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicBlock
decl_stmt|;
name|class
name|DominatorTree
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Loop
decl_stmt|;
comment|/// ExtractCodeRegion - Rip out a sequence of basic blocks into a new
comment|/// function.
comment|///
name|Function
modifier|*
name|ExtractCodeRegion
argument_list|(
name|DominatorTree
operator|&
name|DT
argument_list|,
name|ArrayRef
operator|<
name|BasicBlock
operator|*
operator|>
name|code
argument_list|,
name|bool
name|AggregateArgs
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// ExtractLoop - Rip out a natural loop into a new function.
comment|///
name|Function
modifier|*
name|ExtractLoop
parameter_list|(
name|DominatorTree
modifier|&
name|DT
parameter_list|,
name|Loop
modifier|*
name|L
parameter_list|,
name|bool
name|AggregateArgs
init|=
name|false
parameter_list|)
function_decl|;
comment|/// ExtractBasicBlock - Rip out a basic block (and the associated landing pad)
comment|/// into a new function.
comment|///
name|Function
modifier|*
name|ExtractBasicBlock
argument_list|(
name|ArrayRef
operator|<
name|BasicBlock
operator|*
operator|>
name|BBs
argument_list|,
name|bool
name|AggregateArgs
operator|=
name|false
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

