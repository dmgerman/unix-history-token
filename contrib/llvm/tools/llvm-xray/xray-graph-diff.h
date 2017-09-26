begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- xray-graph-diff.h - XRay Graph Diff Renderer ------------*- C++ -*-===//
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
comment|// Generate a DOT file to represent the difference between the function call
end_comment

begin_comment
comment|// graph of two differnent traces.
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
name|XRAY_GRAPH_DIFF_H
end_ifndef

begin_define
define|#
directive|define
name|XRAY_GRAPH_DIFF_H
end_define

begin_include
include|#
directive|include
file|"xray-graph.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/XRay/Graph.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|xray
block|{
comment|// This class creates a graph representing the difference between two
comment|// xray-graphs And allows you to print it to a dot file, with optional color
comment|// coding.
name|class
name|GraphDiffRenderer
block|{
specifier|static
specifier|const
name|int
name|N
init|=
literal|2
decl_stmt|;
name|public
label|:
name|using
name|StatType
init|=
name|GraphRenderer
operator|::
name|StatType
decl_stmt|;
name|using
name|TimeStat
init|=
name|GraphRenderer
operator|::
name|TimeStat
decl_stmt|;
name|using
name|GREdgeValueType
init|=
name|GraphRenderer
operator|::
name|GraphT
operator|::
name|EdgeValueType
decl_stmt|;
name|using
name|GRVertexValueType
init|=
name|GraphRenderer
operator|::
name|GraphT
operator|::
name|VertexValueType
decl_stmt|;
struct|struct
name|EdgeAttribute
block|{
name|std
operator|::
name|array
operator|<
specifier|const
name|GREdgeValueType
operator|*
operator|,
name|N
operator|>
name|CorrEdgePtr
operator|=
block|{}
expr_stmt|;
block|}
struct|;
struct|struct
name|VertexAttribute
block|{
name|std
operator|::
name|array
operator|<
specifier|const
name|GRVertexValueType
operator|*
operator|,
name|N
operator|>
name|CorrVertexPtr
operator|=
block|{}
expr_stmt|;
block|}
struct|;
name|using
name|GraphT
init|=
name|Graph
operator|<
name|VertexAttribute
decl_stmt|,
name|EdgeAttribute
decl_stmt|,
name|StringRef
decl|>
decl_stmt|;
name|class
name|Factory
block|{
name|std
operator|::
name|array
operator|<
name|std
operator|::
name|reference_wrapper
operator|<
specifier|const
name|GraphRenderer
operator|::
name|GraphT
operator|>
operator|,
name|N
operator|>
name|G
expr_stmt|;
name|public
label|:
name|template
operator|<
name|typename
operator|...
name|Ts
operator|>
name|Factory
argument_list|(
name|Ts
operator|&
operator|...
name|Args
argument_list|)
operator|:
name|G
block|{
block|{
name|Args
operator|...
block|}
block|}
block|{}
name|Expected
operator|<
name|GraphDiffRenderer
operator|>
name|getGraphDiffRenderer
argument_list|()
expr_stmt|;
block|}
empty_stmt|;
name|private
label|:
name|GraphT
name|G
decl_stmt|;
name|GraphDiffRenderer
argument_list|()
operator|=
expr|default
expr_stmt|;
name|public
label|:
name|void
name|exportGraphAsDOT
parameter_list|(
name|raw_ostream
modifier|&
name|OS
parameter_list|,
name|StatType
name|EdgeLabel
init|=
name|StatType
operator|::
name|NONE
parameter_list|,
name|StatType
name|EdgeColor
init|=
name|StatType
operator|::
name|NONE
parameter_list|,
name|StatType
name|VertexLabel
init|=
name|StatType
operator|::
name|NONE
parameter_list|,
name|StatType
name|VertexColor
init|=
name|StatType
operator|::
name|NONE
parameter_list|,
name|int
name|TruncLen
init|=
literal|40
parameter_list|)
function_decl|;
specifier|const
name|GraphT
modifier|&
name|getGraph
parameter_list|()
block|{
return|return
name|G
return|;
block|}
block|}
empty_stmt|;
block|}
comment|// namespace xray
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

