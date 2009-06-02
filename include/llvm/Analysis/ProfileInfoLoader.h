begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ProfileInfoLoader.h - Load& convert profile information -*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                      The LLVM Compiler Infrastructure
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
comment|// The ProfileInfoLoader class is used to load and represent profiling
end_comment

begin_comment
comment|// information read in from the dump file.  If conversions between formats are
end_comment

begin_comment
comment|// needed, it can also do this.
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
name|LLVM_ANALYSIS_PROFILEINFOLOADER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_PROFILEINFOLOADER_H
end_define

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Module
decl_stmt|;
name|class
name|Function
decl_stmt|;
name|class
name|BasicBlock
decl_stmt|;
name|class
name|ProfileInfoLoader
block|{
name|Module
modifier|&
name|M
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|CommandLines
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|FunctionCounts
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|BlockCounts
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|EdgeCounts
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|BBTrace
expr_stmt|;
name|public
label|:
comment|// ProfileInfoLoader ctor - Read the specified profiling data file, exiting
comment|// the program if the file is invalid or broken.
name|ProfileInfoLoader
argument_list|(
specifier|const
name|char
operator|*
name|ToolName
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|,
name|Module
operator|&
name|M
argument_list|)
expr_stmt|;
name|unsigned
name|getNumExecutions
argument_list|()
specifier|const
block|{
return|return
name|CommandLines
operator|.
name|size
argument_list|()
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getExecution
argument_list|(
argument|unsigned i
argument_list|)
specifier|const
block|{
return|return
name|CommandLines
index|[
name|i
index|]
return|;
block|}
comment|// getFunctionCounts - This method is used by consumers of function counting
comment|// information.  If we do not directly have function count information, we
comment|// compute it from other, more refined, types of profile information.
comment|//
name|void
name|getFunctionCounts
argument_list|(
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|Function
operator|*
argument_list|,
name|unsigned
operator|>
expr|>
operator|&
name|Counts
argument_list|)
decl_stmt|;
comment|// hasAccurateBlockCounts - Return true if we can synthesize accurate block
comment|// frequency information from whatever we have.
comment|//
name|bool
name|hasAccurateBlockCounts
argument_list|()
specifier|const
block|{
return|return
operator|!
name|BlockCounts
operator|.
name|empty
argument_list|()
operator|||
operator|!
name|EdgeCounts
operator|.
name|empty
argument_list|()
return|;
block|}
comment|// hasAccurateEdgeCounts - Return true if we can synthesize accurate edge
comment|// frequency information from whatever we have.
comment|//
name|bool
name|hasAccurateEdgeCounts
argument_list|()
specifier|const
block|{
return|return
operator|!
name|EdgeCounts
operator|.
name|empty
argument_list|()
return|;
block|}
comment|// getBlockCounts - This method is used by consumers of block counting
comment|// information.  If we do not directly have block count information, we
comment|// compute it from other, more refined, types of profile information.
comment|//
name|void
name|getBlockCounts
argument_list|(
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|BasicBlock
operator|*
argument_list|,
name|unsigned
operator|>
expr|>
operator|&
name|Counts
argument_list|)
decl_stmt|;
comment|// getEdgeCounts - This method is used by consumers of edge counting
comment|// information.  If we do not directly have edge count information, we compute
comment|// it from other, more refined, types of profile information.
comment|//
comment|// Edges are represented as a pair, where the first element is the basic block
comment|// and the second element is the successor number.
comment|//
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|BasicBlock
operator|*
operator|,
name|unsigned
operator|>
name|Edge
expr_stmt|;
name|void
name|getEdgeCounts
argument_list|(
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|Edge
argument_list|,
name|unsigned
operator|>
expr|>
operator|&
name|Counts
argument_list|)
decl_stmt|;
comment|// getBBTrace - This method is used by consumers of basic-block trace
comment|// information.
comment|//
name|void
name|getBBTrace
argument_list|(
name|std
operator|::
name|vector
operator|<
name|BasicBlock
operator|*
operator|>
operator|&
name|Trace
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

