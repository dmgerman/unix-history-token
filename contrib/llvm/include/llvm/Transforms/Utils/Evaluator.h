begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Evaluator.h - LLVM IR evaluator -------------------------*- C++ -*-===//
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
comment|// Function evaluator for LLVM IR.
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
name|LLVM_TRANSFORMS_UTILS_EVALUATOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_EVALUATOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Constant.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/GlobalVariable.h"
end_include

begin_include
include|#
directive|include
file|<deque>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|DataLayout
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|TargetLibraryInfo
decl_stmt|;
comment|/// This class evaluates LLVM IR, producing the Constant representing each SSA
comment|/// instruction.  Changes to global variables are stored in a mapping that can
comment|/// be iterated over after the evaluation is complete.  Once an evaluation call
comment|/// fails, the evaluation object should not be reused.
name|class
name|Evaluator
block|{
name|public
label|:
name|Evaluator
argument_list|(
specifier|const
name|DataLayout
operator|&
name|DL
argument_list|,
specifier|const
name|TargetLibraryInfo
operator|*
name|TLI
argument_list|)
operator|:
name|DL
argument_list|(
name|DL
argument_list|)
operator|,
name|TLI
argument_list|(
argument|TLI
argument_list|)
block|{
name|ValueStack
operator|.
name|emplace_back
argument_list|()
block|;   }
operator|~
name|Evaluator
argument_list|()
block|{
for|for
control|(
name|auto
operator|&
name|Tmp
operator|:
name|AllocaTmps
control|)
comment|// If there are still users of the alloca, the program is doing something
comment|// silly, e.g. storing the address of the alloca somewhere and using it
comment|// later.  Since this is undefined, we'll just make it be null.
if|if
condition|(
operator|!
name|Tmp
operator|->
name|use_empty
argument_list|()
condition|)
name|Tmp
operator|->
name|replaceAllUsesWith
argument_list|(
name|Constant
operator|::
name|getNullValue
argument_list|(
name|Tmp
operator|->
name|getType
argument_list|()
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// Evaluate a call to function F, returning true if successful, false if we
comment|/// can't evaluate it.  ActualArgs contains the formal arguments for the
comment|/// function.
name|bool
name|EvaluateFunction
argument_list|(
name|Function
operator|*
name|F
argument_list|,
name|Constant
operator|*
operator|&
name|RetVal
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|Constant
operator|*
operator|>
operator|&
name|ActualArgs
argument_list|)
decl_stmt|;
comment|/// Evaluate all instructions in block BB, returning true if successful, false
comment|/// if we can't evaluate it.  NewBB returns the next BB that control flows
comment|/// into, or null upon return.
name|bool
name|EvaluateBlock
argument_list|(
name|BasicBlock
operator|::
name|iterator
name|CurInst
argument_list|,
name|BasicBlock
operator|*
operator|&
name|NextBB
argument_list|)
decl_stmt|;
name|Constant
modifier|*
name|getVal
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|)
block|{
if|if
condition|(
name|Constant
modifier|*
name|CV
init|=
name|dyn_cast
operator|<
name|Constant
operator|>
operator|(
name|V
operator|)
condition|)
return|return
name|CV
return|;
name|Constant
modifier|*
name|R
init|=
name|ValueStack
operator|.
name|back
argument_list|()
operator|.
name|lookup
argument_list|(
name|V
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|R
operator|&&
literal|"Reference to an uncomputed value!"
argument_list|)
expr_stmt|;
return|return
name|R
return|;
block|}
name|void
name|setVal
parameter_list|(
name|Value
modifier|*
name|V
parameter_list|,
name|Constant
modifier|*
name|C
parameter_list|)
block|{
name|ValueStack
operator|.
name|back
argument_list|()
index|[
name|V
index|]
operator|=
name|C
expr_stmt|;
block|}
specifier|const
name|DenseMap
operator|<
name|Constant
operator|*
operator|,
name|Constant
operator|*
operator|>
operator|&
name|getMutatedMemory
argument_list|()
specifier|const
block|{
return|return
name|MutatedMemory
return|;
block|}
specifier|const
name|SmallPtrSetImpl
operator|<
name|GlobalVariable
operator|*
operator|>
operator|&
name|getInvariants
argument_list|()
specifier|const
block|{
return|return
name|Invariants
return|;
block|}
name|private
label|:
name|Constant
modifier|*
name|ComputeLoadResult
parameter_list|(
name|Constant
modifier|*
name|P
parameter_list|)
function_decl|;
comment|/// As we compute SSA register values, we store their contents here. The back
comment|/// of the deque contains the current function and the stack contains the
comment|/// values in the calling frames.
name|std
operator|::
name|deque
operator|<
name|DenseMap
operator|<
name|Value
operator|*
operator|,
name|Constant
operator|*
operator|>>
name|ValueStack
expr_stmt|;
comment|/// This is used to detect recursion.  In pathological situations we could hit
comment|/// exponential behavior, but at least there is nothing unbounded.
name|SmallVector
operator|<
name|Function
operator|*
operator|,
literal|4
operator|>
name|CallStack
expr_stmt|;
comment|/// For each store we execute, we update this map.  Loads check this to get
comment|/// the most up-to-date value.  If evaluation is successful, this state is
comment|/// committed to the process.
name|DenseMap
operator|<
name|Constant
operator|*
operator|,
name|Constant
operator|*
operator|>
name|MutatedMemory
expr_stmt|;
comment|/// To 'execute' an alloca, we create a temporary global variable to represent
comment|/// its body.  This vector is needed so we can delete the temporary globals
comment|/// when we are done.
name|SmallVector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|GlobalVariable
operator|>
operator|,
literal|32
operator|>
name|AllocaTmps
expr_stmt|;
comment|/// These global variables have been marked invariant by the static
comment|/// constructor.
name|SmallPtrSet
operator|<
name|GlobalVariable
operator|*
operator|,
literal|8
operator|>
name|Invariants
expr_stmt|;
comment|/// These are constants we have checked and know to be simple enough to live
comment|/// in a static initializer of a global.
name|SmallPtrSet
operator|<
name|Constant
operator|*
operator|,
literal|8
operator|>
name|SimpleConstants
expr_stmt|;
specifier|const
name|DataLayout
modifier|&
name|DL
decl_stmt|;
specifier|const
name|TargetLibraryInfo
modifier|*
name|TLI
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

