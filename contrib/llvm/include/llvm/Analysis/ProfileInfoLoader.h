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
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
expr_stmt|;
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
name|OptimalEdgeCounts
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
name|BBTrace
expr_stmt|;
name|bool
name|Warned
decl_stmt|;
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
specifier|static
specifier|const
name|unsigned
name|Uncounted
decl_stmt|;
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
specifier|const
name|std
operator|::
name|string
operator|&
name|getFileName
argument_list|()
specifier|const
block|{
return|return
name|Filename
return|;
block|}
comment|// getRawFunctionCounts - This method is used by consumers of function
comment|// counting information.
comment|//
specifier|const
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|&
name|getRawFunctionCounts
argument_list|()
specifier|const
block|{
return|return
name|FunctionCounts
return|;
block|}
comment|// getRawBlockCounts - This method is used by consumers of block counting
comment|// information.
comment|//
specifier|const
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|&
name|getRawBlockCounts
argument_list|()
specifier|const
block|{
return|return
name|BlockCounts
return|;
block|}
comment|// getEdgeCounts - This method is used by consumers of edge counting
comment|// information.
comment|//
specifier|const
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|&
name|getRawEdgeCounts
argument_list|()
specifier|const
block|{
return|return
name|EdgeCounts
return|;
block|}
comment|// getEdgeOptimalCounts - This method is used by consumers of optimal edge
comment|// counting information.
comment|//
specifier|const
name|std
operator|::
name|vector
operator|<
name|unsigned
operator|>
operator|&
name|getRawOptimalEdgeCounts
argument_list|()
specifier|const
block|{
return|return
name|OptimalEdgeCounts
return|;
block|}
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

