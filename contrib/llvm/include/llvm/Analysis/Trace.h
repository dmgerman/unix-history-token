begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/Analysis/Trace.h - Represent one trace of LLVM code -*- C++ -*-===//
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
comment|// This class represents a single trace of LLVM basic blocks.  A trace is a
end_comment

begin_comment
comment|// single entry, multiple exit, region of code that is often hot.  Trace-based
end_comment

begin_comment
comment|// optimizations treat traces almost like they are a large, strange, basic
end_comment

begin_comment
comment|// block: because the trace path is assumed to be hot, optimizations for the
end_comment

begin_comment
comment|// fall-through path are made at the expense of the non-fall-through paths.
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
name|LLVM_ANALYSIS_TRACE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_TRACE_H
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BasicBlock
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|Trace
block|{
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|BasicBlock
operator|*
operator|>
name|BasicBlockListType
expr_stmt|;
name|BasicBlockListType
name|BasicBlocks
decl_stmt|;
name|public
label|:
comment|/// Trace ctor - Make a new trace from a vector of basic blocks,
comment|/// residing in the function which is the parent of the first
comment|/// basic block in the vector.
comment|///
name|Trace
argument_list|(
specifier|const
name|std
operator|::
name|vector
operator|<
name|BasicBlock
operator|*
operator|>
operator|&
name|vBB
argument_list|)
operator|:
name|BasicBlocks
argument_list|(
argument|vBB
argument_list|)
block|{}
comment|/// getEntryBasicBlock - Return the entry basic block (first block)
comment|/// of the trace.
comment|///
name|BasicBlock
operator|*
name|getEntryBasicBlock
argument_list|()
specifier|const
block|{
return|return
name|BasicBlocks
index|[
literal|0
index|]
return|;
block|}
comment|/// operator[]/getBlock - Return basic block N in the trace.
comment|///
name|BasicBlock
modifier|*
name|operator
index|[]
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
return|return
name|BasicBlocks
index|[
name|i
index|]
return|;
block|}
name|BasicBlock
modifier|*
name|getBlock
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
return|return
name|BasicBlocks
index|[
name|i
index|]
return|;
block|}
comment|/// getFunction - Return this trace's parent function.
comment|///
name|Function
operator|*
name|getFunction
argument_list|()
specifier|const
expr_stmt|;
comment|/// getModule - Return this Module that contains this trace's parent
comment|/// function.
comment|///
name|Module
operator|*
name|getModule
argument_list|()
specifier|const
expr_stmt|;
comment|/// getBlockIndex - Return the index of the specified basic block in the
comment|/// trace, or -1 if it is not in the trace.
name|int
name|getBlockIndex
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|X
argument_list|)
decl|const
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|BasicBlocks
operator|.
name|size
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|BasicBlocks
index|[
name|i
index|]
operator|==
name|X
condition|)
return|return
name|i
return|;
return|return
operator|-
literal|1
return|;
block|}
comment|/// contains - Returns true if this trace contains the given basic
comment|/// block.
comment|///
name|bool
name|contains
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|X
argument_list|)
decl|const
block|{
return|return
name|getBlockIndex
argument_list|(
name|X
argument_list|)
operator|!=
operator|-
literal|1
return|;
block|}
comment|/// Returns true if B1 occurs before B2 in the trace, or if it is the same
comment|/// block as B2..  Both blocks must be in the trace.
comment|///
name|bool
name|dominates
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|B1
argument_list|,
specifier|const
name|BasicBlock
operator|*
name|B2
argument_list|)
decl|const
block|{
name|int
name|B1Idx
init|=
name|getBlockIndex
argument_list|(
name|B1
argument_list|)
decl_stmt|,
name|B2Idx
init|=
name|getBlockIndex
argument_list|(
name|B2
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|B1Idx
operator|!=
operator|-
literal|1
operator|&&
name|B2Idx
operator|!=
operator|-
literal|1
operator|&&
literal|"Block is not in the trace!"
argument_list|)
expr_stmt|;
return|return
name|B1Idx
operator|<=
name|B2Idx
return|;
block|}
comment|// BasicBlock iterators...
typedef|typedef
name|BasicBlockListType
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|BasicBlockListType
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|const_iterator
operator|>
name|const_reverse_iterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|reverse_iterator
operator|<
name|iterator
operator|>
name|reverse_iterator
expr_stmt|;
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|BasicBlocks
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|BasicBlocks
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
parameter_list|()
block|{
return|return
name|BasicBlocks
operator|.
name|end
argument_list|()
return|;
block|}
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|BasicBlocks
operator|.
name|end
argument_list|()
return|;
block|}
name|reverse_iterator
name|rbegin
parameter_list|()
block|{
return|return
name|BasicBlocks
operator|.
name|rbegin
argument_list|()
return|;
block|}
name|const_reverse_iterator
name|rbegin
argument_list|()
specifier|const
block|{
return|return
name|BasicBlocks
operator|.
name|rbegin
argument_list|()
return|;
block|}
name|reverse_iterator
name|rend
parameter_list|()
block|{
return|return
name|BasicBlocks
operator|.
name|rend
argument_list|()
return|;
block|}
name|const_reverse_iterator
name|rend
argument_list|()
specifier|const
block|{
return|return
name|BasicBlocks
operator|.
name|rend
argument_list|()
return|;
block|}
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|BasicBlocks
operator|.
name|size
argument_list|()
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|BasicBlocks
operator|.
name|empty
argument_list|()
return|;
block|}
name|iterator
name|erase
parameter_list|(
name|iterator
name|q
parameter_list|)
block|{
return|return
name|BasicBlocks
operator|.
name|erase
argument_list|(
name|q
argument_list|)
return|;
block|}
name|iterator
name|erase
parameter_list|(
name|iterator
name|q1
parameter_list|,
name|iterator
name|q2
parameter_list|)
block|{
return|return
name|BasicBlocks
operator|.
name|erase
argument_list|(
name|q1
argument_list|,
name|q2
argument_list|)
return|;
block|}
comment|/// print - Write trace to output stream.
comment|///
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|O
argument_list|)
decl|const
decl_stmt|;
comment|/// dump - Debugger convenience method; writes trace to standard error
comment|/// output stream.
comment|///
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// TRACE_H
end_comment

end_unit

