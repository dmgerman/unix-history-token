begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- Transform/Utils/CodeExtractor.h - Code extraction util --*- C++ -*-===//
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
comment|// A utility to support extracting code from one function into its own
end_comment

begin_comment
comment|// stand-alone function.
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
name|LLVM_TRANSFORMS_UTILS_CODEEXTRACTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TRANSFORMS_UTILS_CODEEXTRACTOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SetVector.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|ArrayRef
expr_stmt|;
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
name|class
name|Module
decl_stmt|;
name|class
name|RegionNode
decl_stmt|;
name|class
name|Type
decl_stmt|;
name|class
name|Value
decl_stmt|;
comment|/// \brief Utility class for extracting code into a new function.
comment|///
comment|/// This utility provides a simple interface for extracting some sequence of
comment|/// code into its own function, replacing it with a call to that function. It
comment|/// also provides various methods to query about the nature and result of
comment|/// such a transformation.
comment|///
comment|/// The rough algorithm used is:
comment|/// 1) Find both the inputs and outputs for the extracted region.
comment|/// 2) Pass the inputs as arguments, remapping them within the extracted
comment|///    function to arguments.
comment|/// 3) Add allocas for any scalar outputs, adding all of the outputs' allocas
comment|///    as arguments, and inserting stores to the arguments for any scalars.
name|class
name|CodeExtractor
block|{
typedef|typedef
name|SetVector
operator|<
name|Value
operator|*
operator|>
name|ValueSet
expr_stmt|;
comment|// Various bits of state computed on construction.
name|DominatorTree
modifier|*
specifier|const
name|DT
decl_stmt|;
specifier|const
name|bool
name|AggregateArgs
decl_stmt|;
comment|// Bits of intermediate state computed at various phases of extraction.
name|SetVector
operator|<
name|BasicBlock
operator|*
operator|>
name|Blocks
expr_stmt|;
name|unsigned
name|NumExitBlocks
decl_stmt|;
name|Type
modifier|*
name|RetTy
decl_stmt|;
name|public
label|:
comment|/// \brief Create a code extractor for a single basic block.
comment|///
comment|/// In this formation, we don't require a dominator tree. The given basic
comment|/// block is set up for extraction.
name|CodeExtractor
argument_list|(
argument|BasicBlock *BB
argument_list|,
argument|bool AggregateArgs = false
argument_list|)
empty_stmt|;
comment|/// \brief Create a code extractor for a sequence of blocks.
comment|///
comment|/// Given a sequence of basic blocks where the first block in the sequence
comment|/// dominates the rest, prepare a code extractor object for pulling this
comment|/// sequence out into its new function. When a DominatorTree is also given,
comment|/// extra checking and transformations are enabled.
name|CodeExtractor
argument_list|(
argument|ArrayRef<BasicBlock *> BBs
argument_list|,
argument|DominatorTree *DT = nullptr
argument_list|,
argument|bool AggregateArgs = false
argument_list|)
empty_stmt|;
comment|/// \brief Create a code extractor for a loop body.
comment|///
comment|/// Behaves just like the generic code sequence constructor, but uses the
comment|/// block sequence of the loop.
name|CodeExtractor
argument_list|(
argument|DominatorTree&DT
argument_list|,
argument|Loop&L
argument_list|,
argument|bool AggregateArgs = false
argument_list|)
empty_stmt|;
comment|/// \brief Create a code extractor for a region node.
comment|///
comment|/// Behaves just like the generic code sequence constructor, but uses the
comment|/// block sequence of the region node passed in.
name|CodeExtractor
argument_list|(
argument|DominatorTree&DT
argument_list|,
argument|const RegionNode&RN
argument_list|,
argument|bool AggregateArgs = false
argument_list|)
empty_stmt|;
comment|/// \brief Perform the extraction, returning the new function.
comment|///
comment|/// Returns zero when called on a CodeExtractor instance where isEligible
comment|/// returns false.
name|Function
modifier|*
name|extractCodeRegion
parameter_list|()
function_decl|;
comment|/// \brief Test whether this code extractor is eligible.
comment|///
comment|/// Based on the blocks used when constructing the code extractor,
comment|/// determine whether it is eligible for extraction.
name|bool
name|isEligible
argument_list|()
specifier|const
block|{
return|return
operator|!
name|Blocks
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// \brief Compute the set of input values and output values for the code.
comment|///
comment|/// These can be used either when performing the extraction or to evaluate
comment|/// the expected size of a call to the extracted function. Note that this
comment|/// work cannot be cached between the two as once we decide to extract
comment|/// a code sequence, that sequence is modified, including changing these
comment|/// sets, before extraction occurs. These modifications won't have any
comment|/// significant impact on the cost however.
name|void
name|findInputsOutputs
argument_list|(
name|ValueSet
operator|&
name|Inputs
argument_list|,
name|ValueSet
operator|&
name|Outputs
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|void
name|severSplitPHINodes
parameter_list|(
name|BasicBlock
modifier|*
modifier|&
name|Header
parameter_list|)
function_decl|;
name|void
name|splitReturnBlocks
parameter_list|()
function_decl|;
name|Function
modifier|*
name|constructFunction
parameter_list|(
specifier|const
name|ValueSet
modifier|&
name|inputs
parameter_list|,
specifier|const
name|ValueSet
modifier|&
name|outputs
parameter_list|,
name|BasicBlock
modifier|*
name|header
parameter_list|,
name|BasicBlock
modifier|*
name|newRootNode
parameter_list|,
name|BasicBlock
modifier|*
name|newHeader
parameter_list|,
name|Function
modifier|*
name|oldFunction
parameter_list|,
name|Module
modifier|*
name|M
parameter_list|)
function_decl|;
name|void
name|moveCodeToFunction
parameter_list|(
name|Function
modifier|*
name|newFunction
parameter_list|)
function_decl|;
name|void
name|emitCallAndSwitchStatement
parameter_list|(
name|Function
modifier|*
name|newFunction
parameter_list|,
name|BasicBlock
modifier|*
name|newHeader
parameter_list|,
name|ValueSet
modifier|&
name|inputs
parameter_list|,
name|ValueSet
modifier|&
name|outputs
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

