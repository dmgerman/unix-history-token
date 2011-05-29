begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- DataflowValues.h - Data structure for dataflow values --*- C++ -*-===//
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
comment|// This file defines a skeleton data structure for encapsulating the dataflow
end_comment

begin_comment
comment|// values for a CFG.  Typically this is subclassed to provide methods for
end_comment

begin_comment
comment|// computing these values from a CFG.
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
name|LLVM_CLANG_ANALYSES_DATAFLOW_VALUES
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSES_DATAFLOW_VALUES
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/CFG.h"
end_include

begin_include
include|#
directive|include
file|"clang/Analysis/ProgramPoint.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// Dataflow Directional Tag Classes.  These are used for tag dispatching
end_comment

begin_comment
comment|///  within the dataflow solver/transfer functions to determine what direction
end_comment

begin_comment
comment|///  a dataflow analysis flows.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|dataflow
block|{
struct|struct
name|forward_analysis_tag
block|{}
struct|;
struct|struct
name|backward_analysis_tag
block|{}
struct|;
block|}
comment|// end namespace dataflow
comment|//===----------------------------------------------------------------------===//
comment|/// DataflowValues.  Container class to store dataflow values for a CFG.
comment|//===----------------------------------------------------------------------===//
name|template
operator|<
name|typename
name|ValueTypes
operator|,
name|typename
name|_AnalysisDirTag
operator|=
name|dataflow
operator|::
name|forward_analysis_tag
operator|>
name|class
name|DataflowValues
block|{
comment|//===--------------------------------------------------------------------===//
comment|// Type declarations.
comment|//===--------------------------------------------------------------------===//
name|public
operator|:
typedef|typedef
name|typename
name|ValueTypes
operator|::
name|ValTy
name|ValTy
expr_stmt|;
typedef|typedef
name|typename
name|ValueTypes
operator|::
name|AnalysisDataTy
name|AnalysisDataTy
expr_stmt|;
typedef|typedef
name|_AnalysisDirTag
name|AnalysisDirTag
typedef|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|ProgramPoint
operator|,
name|ValTy
operator|>
name|EdgeDataMapTy
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CFGBlock
operator|*
operator|,
name|ValTy
operator|>
name|BlockDataMapTy
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Stmt
operator|*
operator|,
name|ValTy
operator|>
name|StmtDataMapTy
expr_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// Predicates.
comment|//===--------------------------------------------------------------------===//
name|public
label|:
comment|/// isForwardAnalysis - Returns true if the dataflow values are computed
comment|///  from a forward analysis.
name|bool
name|isForwardAnalysis
parameter_list|()
block|{
return|return
name|isForwardAnalysis
argument_list|(
name|AnalysisDirTag
argument_list|()
argument_list|)
return|;
block|}
comment|/// isBackwardAnalysis - Returns true if the dataflow values are computed
comment|///  from a backward analysis.
name|bool
name|isBackwardAnalysis
parameter_list|()
block|{
return|return
operator|!
name|isForwardAnalysis
argument_list|()
return|;
block|}
name|private
label|:
name|bool
name|isForwardAnalysis
argument_list|(
name|dataflow
operator|::
name|forward_analysis_tag
argument_list|)
block|{
return|return
name|true
return|;
block|}
name|bool
name|isForwardAnalysis
argument_list|(
name|dataflow
operator|::
name|backward_analysis_tag
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Initialization and accessors methods.
comment|//===--------------------------------------------------------------------===//
name|public
label|:
name|DataflowValues
argument_list|()
operator|:
name|StmtDataMap
argument_list|(
argument|NULL
argument_list|)
block|{}
operator|~
name|DataflowValues
argument_list|()
block|{
name|delete
name|StmtDataMap
block|; }
comment|/// InitializeValues - Invoked by the solver to initialize state needed for
comment|///  dataflow analysis.  This method is usually specialized by subclasses.
name|void
name|InitializeValues
argument_list|(
argument|const CFG& cfg
argument_list|)
block|{}
comment|/// getEdgeData - Retrieves the dataflow values associated with a
comment|///  CFG edge.
name|ValTy
operator|&
name|getEdgeData
argument_list|(
argument|const BlockEdge& E
argument_list|)
block|{
name|typename
name|EdgeDataMapTy
operator|::
name|iterator
name|I
operator|=
name|EdgeDataMap
operator|.
name|find
argument_list|(
name|E
argument_list|)
block|;
name|assert
argument_list|(
name|I
operator|!=
name|EdgeDataMap
operator|.
name|end
argument_list|()
operator|&&
literal|"No data associated with Edge."
argument_list|)
block|;
return|return
name|I
operator|->
name|second
return|;
block|}
specifier|const
name|ValTy
modifier|&
name|getEdgeData
argument_list|(
specifier|const
name|BlockEdge
operator|&
name|E
argument_list|)
decl|const
block|{
return|return
name|reinterpret_cast
operator|<
name|DataflowValues
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getEdgeData
argument_list|(
name|E
argument_list|)
return|;
block|}
comment|/// getBlockData - Retrieves the dataflow values associated with a
comment|///  specified CFGBlock.  If the dataflow analysis is a forward analysis,
comment|///  this data is associated with the END of the block.  If the analysis
comment|///  is a backwards analysis, it is associated with the ENTRY of the block.
name|ValTy
modifier|&
name|getBlockData
parameter_list|(
specifier|const
name|CFGBlock
modifier|*
name|B
parameter_list|)
block|{
name|typename
name|BlockDataMapTy
operator|::
name|iterator
name|I
operator|=
name|BlockDataMap
operator|.
name|find
argument_list|(
name|B
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|I
operator|!=
name|BlockDataMap
operator|.
name|end
argument_list|()
operator|&&
literal|"No data associated with block."
argument_list|)
expr_stmt|;
return|return
name|I
operator|->
name|second
return|;
block|}
specifier|const
name|ValTy
modifier|&
name|getBlockData
argument_list|(
specifier|const
name|CFGBlock
operator|*
name|B
argument_list|)
decl|const
block|{
return|return
name|const_cast
operator|<
name|DataflowValues
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getBlockData
argument_list|(
name|B
argument_list|)
return|;
block|}
comment|/// getStmtData - Retrieves the dataflow values associated with a
comment|///  specified Stmt.  If the dataflow analysis is a forward analysis,
comment|///  this data corresponds to the point immediately before a Stmt.
comment|///  If the analysis is a backwards analysis, it is associated with
comment|///  the point after a Stmt.  This data is only computed for block-level
comment|///  expressions, and only when requested when the analysis is executed.
name|ValTy
modifier|&
name|getStmtData
parameter_list|(
specifier|const
name|Stmt
modifier|*
name|S
parameter_list|)
block|{
name|assert
argument_list|(
name|StmtDataMap
operator|&&
literal|"Dataflow values were not computed for statements."
argument_list|)
expr_stmt|;
name|typename
name|StmtDataMapTy
operator|::
name|iterator
name|I
operator|=
name|StmtDataMap
operator|->
name|find
argument_list|(
name|S
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|I
operator|!=
name|StmtDataMap
operator|->
name|end
argument_list|()
operator|&&
literal|"No data associated with statement."
argument_list|)
expr_stmt|;
return|return
name|I
operator|->
name|second
return|;
block|}
specifier|const
name|ValTy
modifier|&
name|getStmtData
argument_list|(
specifier|const
name|Stmt
operator|*
name|S
argument_list|)
decl|const
block|{
return|return
name|const_cast
operator|<
name|DataflowValues
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getStmtData
argument_list|(
name|S
argument_list|)
return|;
block|}
comment|/// getEdgeDataMap - Retrieves the internal map between CFG edges and
comment|///  dataflow values.  Usually used by a dataflow solver to compute
comment|///  values for blocks.
name|EdgeDataMapTy
modifier|&
name|getEdgeDataMap
parameter_list|()
block|{
return|return
name|EdgeDataMap
return|;
block|}
specifier|const
name|EdgeDataMapTy
operator|&
name|getEdgeDataMap
argument_list|()
specifier|const
block|{
return|return
name|EdgeDataMap
return|;
block|}
comment|/// getBlockDataMap - Retrieves the internal map between CFGBlocks and
comment|/// dataflow values.  If the dataflow analysis operates in the forward
comment|/// direction, the values correspond to the dataflow values at the start
comment|/// of the block.  Otherwise, for a backward analysis, the values correpsond
comment|/// to the dataflow values at the end of the block.
name|BlockDataMapTy
modifier|&
name|getBlockDataMap
parameter_list|()
block|{
return|return
name|BlockDataMap
return|;
block|}
specifier|const
name|BlockDataMapTy
operator|&
name|getBlockDataMap
argument_list|()
specifier|const
block|{
return|return
name|BlockDataMap
return|;
block|}
comment|/// getStmtDataMap - Retrieves the internal map between Stmts and
comment|/// dataflow values.
name|StmtDataMapTy
modifier|&
name|getStmtDataMap
parameter_list|()
block|{
if|if
condition|(
operator|!
name|StmtDataMap
condition|)
name|StmtDataMap
operator|=
name|new
name|StmtDataMapTy
argument_list|()
expr_stmt|;
return|return
operator|*
name|StmtDataMap
return|;
block|}
specifier|const
name|StmtDataMapTy
operator|&
name|getStmtDataMap
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|DataflowValues
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getStmtDataMap
argument_list|()
return|;
block|}
comment|/// getAnalysisData - Retrieves the meta data associated with a
comment|///  dataflow analysis for analyzing a particular CFG.
comment|///  This is typically consumed by transfer function code (via the solver).
comment|///  This can also be used by subclasses to interpret the dataflow values.
name|AnalysisDataTy
modifier|&
name|getAnalysisData
parameter_list|()
block|{
return|return
name|AnalysisData
return|;
block|}
specifier|const
name|AnalysisDataTy
operator|&
name|getAnalysisData
argument_list|()
specifier|const
block|{
return|return
name|AnalysisData
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Internal data.
comment|//===--------------------------------------------------------------------===//
name|protected
label|:
name|EdgeDataMapTy
name|EdgeDataMap
decl_stmt|;
name|BlockDataMapTy
name|BlockDataMap
decl_stmt|;
name|StmtDataMapTy
modifier|*
name|StmtDataMap
decl_stmt|;
name|AnalysisDataTy
name|AnalysisData
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

