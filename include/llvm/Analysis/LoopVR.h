begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LoopVR.cpp - Value Range analysis driven by loop information -------===//
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
comment|// This file defines the interface for the loop-driven value range pass.
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
name|LLVM_ANALYSIS_LOOPVR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_LOOPVR_H
end_define

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/ScalarEvolution.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/ConstantRange.h"
end_include

begin_include
include|#
directive|include
file|<iosfwd>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// LoopVR - This class maintains a mapping of Values to ConstantRanges.
comment|/// There are interfaces to look up and update ranges by value, and for
comment|/// accessing all values with range information.
comment|///
name|class
name|LoopVR
range|:
name|public
name|FunctionPass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|// Class identification, replacement for typeinfo
name|LoopVR
argument_list|()
operator|:
name|FunctionPass
argument_list|(
argument|&ID
argument_list|)
block|{}
name|bool
name|runOnFunction
argument_list|(
name|Function
operator|&
name|F
argument_list|)
block|;
name|virtual
name|void
name|print
argument_list|(
argument|std::ostream&os
argument_list|,
argument|const Module *
argument_list|)
specifier|const
block|;
name|void
name|releaseMemory
argument_list|()
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
block|{
name|AU
operator|.
name|addRequiredTransitive
operator|<
name|LoopInfo
operator|>
operator|(
operator|)
block|;
name|AU
operator|.
name|addRequiredTransitive
operator|<
name|ScalarEvolution
operator|>
operator|(
operator|)
block|;
name|AU
operator|.
name|setPreservesAll
argument_list|()
block|;   }
comment|//===---------------------------------------------------------------------
comment|// Methods that are used to look up and update particular values.
comment|/// get - return the ConstantRange for a given Value of IntegerType.
name|ConstantRange
name|get
argument_list|(
name|Value
operator|*
name|V
argument_list|)
block|;
comment|/// remove - remove a value from this analysis.
name|void
name|remove
argument_list|(
name|Value
operator|*
name|V
argument_list|)
block|;
comment|/// narrow - improve our unterstanding of a Value by pointing out that it
comment|/// must fall within ConstantRange. To replace a range, remove it first.
name|void
name|narrow
argument_list|(
name|Value
operator|*
name|V
argument_list|,
specifier|const
name|ConstantRange
operator|&
name|CR
argument_list|)
block|;
comment|//===---------------------------------------------------------------------
comment|// Methods that are used to iterate across all values with information.
comment|/// size - returns the number of Values with information
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|Map
operator|.
name|size
argument_list|()
return|;
block|}
typedef|typedef
name|std
operator|::
name|map
operator|<
name|Value
operator|*
operator|,
name|ConstantRange
operator|*
operator|>
operator|::
name|iterator
name|iterator
expr_stmt|;
comment|/// begin - return an iterator to the first Value, ConstantRange pair
name|iterator
name|begin
argument_list|()
block|{
return|return
name|Map
operator|.
name|begin
argument_list|()
return|;
block|}
comment|/// end - return an iterator one past the last Value, ConstantRange pair
name|iterator
name|end
argument_list|()
block|{
return|return
name|Map
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// getValue - return the Value referenced by an iterator
name|Value
operator|*
name|getValue
argument_list|(
argument|iterator I
argument_list|)
block|{
return|return
name|I
operator|->
name|first
return|;
block|}
comment|/// getConstantRange - return the ConstantRange referenced by an iterator
name|ConstantRange
name|getConstantRange
argument_list|(
argument|iterator I
argument_list|)
block|{
return|return
operator|*
name|I
operator|->
name|second
return|;
block|}
name|private
operator|:
name|ConstantRange
name|compute
argument_list|(
name|Value
operator|*
name|V
argument_list|)
decl_stmt|;
name|ConstantRange
name|getRange
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|,
name|Loop
modifier|*
name|L
parameter_list|,
name|ScalarEvolution
modifier|&
name|SE
parameter_list|)
function_decl|;
name|ConstantRange
name|getRange
parameter_list|(
specifier|const
name|SCEV
modifier|*
name|S
parameter_list|,
specifier|const
name|SCEV
modifier|*
name|T
parameter_list|,
name|ScalarEvolution
modifier|&
name|SE
parameter_list|)
function_decl|;
name|std
operator|::
name|map
operator|<
name|Value
operator|*
operator|,
name|ConstantRange
operator|*
operator|>
name|Map
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

