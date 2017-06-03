begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Graph.h - PBQP Graph -------------------------------------*- C++ -*-===//
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
comment|// PBQP Graph class.
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
name|LLVM_CODEGEN_PBQP_GRAPH_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_PBQP_GRAPH_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/STLExtras.h"
end_include

begin_include
include|#
directive|include
file|<algorithm>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<iterator>
end_include

begin_include
include|#
directive|include
file|<limits>
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
name|namespace
name|PBQP
block|{
name|class
name|GraphBase
block|{
name|public
label|:
name|using
name|NodeId
init|=
name|unsigned
decl_stmt|;
name|using
name|EdgeId
init|=
name|unsigned
decl_stmt|;
comment|/// @brief Returns a value representing an invalid (non-existent) node.
specifier|static
name|NodeId
name|invalidNodeId
parameter_list|()
block|{
return|return
name|std
operator|::
name|numeric_limits
operator|<
name|NodeId
operator|>
operator|::
name|max
argument_list|()
return|;
block|}
comment|/// @brief Returns a value representing an invalid (non-existent) edge.
specifier|static
name|EdgeId
name|invalidEdgeId
parameter_list|()
block|{
return|return
name|std
operator|::
name|numeric_limits
operator|<
name|EdgeId
operator|>
operator|::
name|max
argument_list|()
return|;
block|}
block|}
empty_stmt|;
comment|/// PBQP Graph class.
comment|/// Instances of this class describe PBQP problems.
comment|///
name|template
operator|<
name|typename
name|SolverT
operator|>
name|class
name|Graph
operator|:
name|public
name|GraphBase
block|{
name|private
operator|:
name|using
name|CostAllocator
operator|=
name|typename
name|SolverT
operator|::
name|CostAllocator
block|;
name|public
operator|:
name|using
name|RawVector
operator|=
name|typename
name|SolverT
operator|::
name|RawVector
block|;
name|using
name|RawMatrix
operator|=
name|typename
name|SolverT
operator|::
name|RawMatrix
block|;
name|using
name|Vector
operator|=
name|typename
name|SolverT
operator|::
name|Vector
block|;
name|using
name|Matrix
operator|=
name|typename
name|SolverT
operator|::
name|Matrix
block|;
name|using
name|VectorPtr
operator|=
name|typename
name|CostAllocator
operator|::
name|VectorPtr
block|;
name|using
name|MatrixPtr
operator|=
name|typename
name|CostAllocator
operator|::
name|MatrixPtr
block|;
name|using
name|NodeMetadata
operator|=
name|typename
name|SolverT
operator|::
name|NodeMetadata
block|;
name|using
name|EdgeMetadata
operator|=
name|typename
name|SolverT
operator|::
name|EdgeMetadata
block|;
name|using
name|GraphMetadata
operator|=
name|typename
name|SolverT
operator|::
name|GraphMetadata
block|;
name|private
operator|:
name|class
name|NodeEntry
block|{
name|public
operator|:
name|using
name|AdjEdgeList
operator|=
name|std
operator|::
name|vector
operator|<
name|EdgeId
operator|>
block|;
name|using
name|AdjEdgeIdx
operator|=
name|AdjEdgeList
operator|::
name|size_type
block|;
name|using
name|AdjEdgeItr
operator|=
name|AdjEdgeList
operator|::
name|const_iterator
block|;
name|NodeEntry
argument_list|(
argument|VectorPtr Costs
argument_list|)
operator|:
name|Costs
argument_list|(
argument|std::move(Costs)
argument_list|)
block|{}
specifier|static
name|AdjEdgeIdx
name|getInvalidAdjEdgeIdx
argument_list|()
block|{
return|return
name|std
operator|::
name|numeric_limits
operator|<
name|AdjEdgeIdx
operator|>
operator|::
name|max
argument_list|()
return|;
block|}
name|AdjEdgeIdx
name|addAdjEdgeId
argument_list|(
argument|EdgeId EId
argument_list|)
block|{
name|AdjEdgeIdx
name|Idx
operator|=
name|AdjEdgeIds
operator|.
name|size
argument_list|()
block|;
name|AdjEdgeIds
operator|.
name|push_back
argument_list|(
name|EId
argument_list|)
block|;
return|return
name|Idx
return|;
block|}
name|void
name|removeAdjEdgeId
argument_list|(
argument|Graph&G
argument_list|,
argument|NodeId ThisNId
argument_list|,
argument|AdjEdgeIdx Idx
argument_list|)
block|{
comment|// Swap-and-pop for fast removal.
comment|//   1) Update the adj index of the edge currently at back().
comment|//   2) Move last Edge down to Idx.
comment|//   3) pop_back()
comment|// If Idx == size() - 1 then the setAdjEdgeIdx and swap are
comment|// redundant, but both operations are cheap.
name|G
operator|.
name|getEdge
argument_list|(
name|AdjEdgeIds
operator|.
name|back
argument_list|()
argument_list|)
operator|.
name|setAdjEdgeIdx
argument_list|(
name|ThisNId
argument_list|,
name|Idx
argument_list|)
block|;
name|AdjEdgeIds
index|[
name|Idx
index|]
operator|=
name|AdjEdgeIds
operator|.
name|back
argument_list|()
block|;
name|AdjEdgeIds
operator|.
name|pop_back
argument_list|()
block|;       }
specifier|const
name|AdjEdgeList
operator|&
name|getAdjEdgeIds
argument_list|()
specifier|const
block|{
return|return
name|AdjEdgeIds
return|;
block|}
name|VectorPtr
name|Costs
block|;
name|NodeMetadata
name|Metadata
block|;
name|private
operator|:
name|AdjEdgeList
name|AdjEdgeIds
block|;     }
block|;
name|class
name|EdgeEntry
block|{
name|public
operator|:
name|EdgeEntry
argument_list|(
argument|NodeId N1Id
argument_list|,
argument|NodeId N2Id
argument_list|,
argument|MatrixPtr Costs
argument_list|)
operator|:
name|Costs
argument_list|(
argument|std::move(Costs)
argument_list|)
block|{
name|NIds
index|[
literal|0
index|]
operator|=
name|N1Id
block|;
name|NIds
index|[
literal|1
index|]
operator|=
name|N2Id
block|;
name|ThisEdgeAdjIdxs
index|[
literal|0
index|]
operator|=
name|NodeEntry
operator|::
name|getInvalidAdjEdgeIdx
argument_list|()
block|;
name|ThisEdgeAdjIdxs
index|[
literal|1
index|]
operator|=
name|NodeEntry
operator|::
name|getInvalidAdjEdgeIdx
argument_list|()
block|;       }
name|void
name|connectToN
argument_list|(
argument|Graph&G
argument_list|,
argument|EdgeId ThisEdgeId
argument_list|,
argument|unsigned NIdx
argument_list|)
block|{
name|assert
argument_list|(
name|ThisEdgeAdjIdxs
index|[
name|NIdx
index|]
operator|==
name|NodeEntry
operator|::
name|getInvalidAdjEdgeIdx
argument_list|()
operator|&&
literal|"Edge already connected to NIds[NIdx]."
argument_list|)
block|;
name|NodeEntry
operator|&
name|N
operator|=
name|G
operator|.
name|getNode
argument_list|(
name|NIds
index|[
name|NIdx
index|]
argument_list|)
block|;
name|ThisEdgeAdjIdxs
index|[
name|NIdx
index|]
operator|=
name|N
operator|.
name|addAdjEdgeId
argument_list|(
name|ThisEdgeId
argument_list|)
block|;       }
name|void
name|connect
argument_list|(
argument|Graph&G
argument_list|,
argument|EdgeId ThisEdgeId
argument_list|)
block|{
name|connectToN
argument_list|(
name|G
argument_list|,
name|ThisEdgeId
argument_list|,
literal|0
argument_list|)
block|;
name|connectToN
argument_list|(
name|G
argument_list|,
name|ThisEdgeId
argument_list|,
literal|1
argument_list|)
block|;       }
name|void
name|setAdjEdgeIdx
argument_list|(
argument|NodeId NId
argument_list|,
argument|typename NodeEntry::AdjEdgeIdx NewIdx
argument_list|)
block|{
if|if
condition|(
name|NId
operator|==
name|NIds
index|[
literal|0
index|]
condition|)
name|ThisEdgeAdjIdxs
index|[
literal|0
index|]
operator|=
name|NewIdx
expr_stmt|;
else|else
block|{
name|assert
argument_list|(
name|NId
operator|==
name|NIds
index|[
literal|1
index|]
operator|&&
literal|"Edge not connected to NId"
argument_list|)
expr_stmt|;
name|ThisEdgeAdjIdxs
index|[
literal|1
index|]
operator|=
name|NewIdx
expr_stmt|;
block|}
block|}
name|void
name|disconnectFromN
argument_list|(
argument|Graph&G
argument_list|,
argument|unsigned NIdx
argument_list|)
block|{
name|assert
argument_list|(
name|ThisEdgeAdjIdxs
index|[
name|NIdx
index|]
operator|!=
name|NodeEntry
operator|::
name|getInvalidAdjEdgeIdx
argument_list|()
operator|&&
literal|"Edge not connected to NIds[NIdx]."
argument_list|)
block|;
name|NodeEntry
operator|&
name|N
operator|=
name|G
operator|.
name|getNode
argument_list|(
name|NIds
index|[
name|NIdx
index|]
argument_list|)
block|;
name|N
operator|.
name|removeAdjEdgeId
argument_list|(
name|G
argument_list|,
name|NIds
index|[
name|NIdx
index|]
argument_list|,
name|ThisEdgeAdjIdxs
index|[
name|NIdx
index|]
argument_list|)
block|;
name|ThisEdgeAdjIdxs
index|[
name|NIdx
index|]
operator|=
name|NodeEntry
operator|::
name|getInvalidAdjEdgeIdx
argument_list|()
block|;       }
name|void
name|disconnectFrom
argument_list|(
argument|Graph&G
argument_list|,
argument|NodeId NId
argument_list|)
block|{
if|if
condition|(
name|NId
operator|==
name|NIds
index|[
literal|0
index|]
condition|)
name|disconnectFromN
argument_list|(
name|G
argument_list|,
literal|0
argument_list|)
expr_stmt|;
else|else
block|{
name|assert
argument_list|(
name|NId
operator|==
name|NIds
index|[
literal|1
index|]
operator|&&
literal|"Edge does not connect NId"
argument_list|)
expr_stmt|;
name|disconnectFromN
argument_list|(
name|G
argument_list|,
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
name|NodeId
name|getN1Id
argument_list|()
specifier|const
block|{
return|return
name|NIds
index|[
literal|0
index|]
return|;
block|}
name|NodeId
name|getN2Id
argument_list|()
specifier|const
block|{
return|return
name|NIds
index|[
literal|1
index|]
return|;
block|}
name|MatrixPtr
name|Costs
block|;
name|EdgeMetadata
name|Metadata
block|;
name|private
operator|:
name|NodeId
name|NIds
index|[
literal|2
index|]
block|;
name|typename
name|NodeEntry
operator|::
name|AdjEdgeIdx
name|ThisEdgeAdjIdxs
index|[
literal|2
index|]
block|;     }
block|;
comment|// ----- MEMBERS -----
name|GraphMetadata
name|Metadata
block|;
name|CostAllocator
name|CostAlloc
block|;
name|SolverT
operator|*
name|Solver
operator|=
name|nullptr
block|;
name|using
name|NodeVector
operator|=
name|std
operator|::
name|vector
operator|<
name|NodeEntry
operator|>
block|;
name|using
name|FreeNodeVector
operator|=
name|std
operator|::
name|vector
operator|<
name|NodeId
operator|>
block|;
name|NodeVector
name|Nodes
block|;
name|FreeNodeVector
name|FreeNodeIds
block|;
name|using
name|EdgeVector
operator|=
name|std
operator|::
name|vector
operator|<
name|EdgeEntry
operator|>
block|;
name|using
name|FreeEdgeVector
operator|=
name|std
operator|::
name|vector
operator|<
name|EdgeId
operator|>
block|;
name|EdgeVector
name|Edges
block|;
name|FreeEdgeVector
name|FreeEdgeIds
block|;
name|Graph
argument_list|(
argument|const Graph&Other
argument_list|)
block|{}
comment|// ----- INTERNAL METHODS -----
name|NodeEntry
operator|&
name|getNode
argument_list|(
argument|NodeId NId
argument_list|)
block|{
name|assert
argument_list|(
name|NId
operator|<
name|Nodes
operator|.
name|size
argument_list|()
operator|&&
literal|"Out of bound NodeId"
argument_list|)
block|;
return|return
name|Nodes
index|[
name|NId
index|]
return|;
block|}
specifier|const
name|NodeEntry
operator|&
name|getNode
argument_list|(
argument|NodeId NId
argument_list|)
specifier|const
block|{
name|assert
argument_list|(
name|NId
operator|<
name|Nodes
operator|.
name|size
argument_list|()
operator|&&
literal|"Out of bound NodeId"
argument_list|)
block|;
return|return
name|Nodes
index|[
name|NId
index|]
return|;
block|}
name|EdgeEntry
operator|&
name|getEdge
argument_list|(
argument|EdgeId EId
argument_list|)
block|{
return|return
name|Edges
index|[
name|EId
index|]
return|;
block|}
specifier|const
name|EdgeEntry
operator|&
name|getEdge
argument_list|(
argument|EdgeId EId
argument_list|)
specifier|const
block|{
return|return
name|Edges
index|[
name|EId
index|]
return|;
block|}
name|NodeId
name|addConstructedNode
argument_list|(
argument|NodeEntry N
argument_list|)
block|{
name|NodeId
name|NId
operator|=
literal|0
block|;
if|if
condition|(
operator|!
name|FreeNodeIds
operator|.
name|empty
argument_list|()
condition|)
block|{
name|NId
operator|=
name|FreeNodeIds
operator|.
name|back
argument_list|()
expr_stmt|;
name|FreeNodeIds
operator|.
name|pop_back
argument_list|()
expr_stmt|;
name|Nodes
index|[
name|NId
index|]
operator|=
name|std
operator|::
name|move
argument_list|(
name|N
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|NId
operator|=
name|Nodes
operator|.
name|size
argument_list|()
expr_stmt|;
name|Nodes
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|N
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|NId
return|;
block|}
name|EdgeId
name|addConstructedEdge
argument_list|(
argument|EdgeEntry E
argument_list|)
block|{
name|assert
argument_list|(
name|findEdge
argument_list|(
name|E
operator|.
name|getN1Id
argument_list|()
argument_list|,
name|E
operator|.
name|getN2Id
argument_list|()
argument_list|)
operator|==
name|invalidEdgeId
argument_list|()
operator|&&
literal|"Attempt to add duplicate edge."
argument_list|)
block|;
name|EdgeId
name|EId
operator|=
literal|0
block|;
if|if
condition|(
operator|!
name|FreeEdgeIds
operator|.
name|empty
argument_list|()
condition|)
block|{
name|EId
operator|=
name|FreeEdgeIds
operator|.
name|back
argument_list|()
expr_stmt|;
name|FreeEdgeIds
operator|.
name|pop_back
argument_list|()
expr_stmt|;
name|Edges
index|[
name|EId
index|]
operator|=
name|std
operator|::
name|move
argument_list|(
name|E
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|EId
operator|=
name|Edges
operator|.
name|size
argument_list|()
expr_stmt|;
name|Edges
operator|.
name|push_back
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|E
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|EdgeEntry
modifier|&
name|NE
init|=
name|getEdge
argument_list|(
name|EId
argument_list|)
decl_stmt|;
comment|// Add the edge to the adjacency sets of its nodes.
name|NE
operator|.
name|connect
argument_list|(
operator|*
name|this
argument_list|,
name|EId
argument_list|)
block|;
return|return
name|EId
return|;
block|}
name|void
name|operator
init|=
operator|(
specifier|const
name|Graph
operator|&
name|Other
operator|)
block|{}
name|public
operator|:
name|using
name|AdjEdgeItr
operator|=
name|typename
name|NodeEntry
operator|::
name|AdjEdgeItr
decl_stmt|;
name|class
name|NodeItr
block|{
name|public
label|:
name|using
name|iterator_category
init|=
name|std
operator|::
name|forward_iterator_tag
decl_stmt|;
name|using
name|value_type
init|=
name|NodeId
decl_stmt|;
name|using
name|difference_type
init|=
name|int
decl_stmt|;
name|using
name|pointer
init|=
name|NodeId
operator|*
decl_stmt|;
name|using
name|reference
init|=
name|NodeId
operator|&
decl_stmt|;
name|NodeItr
argument_list|(
argument|NodeId CurNId
argument_list|,
argument|const Graph&G
argument_list|)
block|:
name|CurNId
argument_list|(
name|CurNId
argument_list|)
operator|,
name|EndNId
argument_list|(
name|G
operator|.
name|Nodes
operator|.
name|size
argument_list|()
argument_list|)
operator|,
name|FreeNodeIds
argument_list|(
argument|G.FreeNodeIds
argument_list|)
block|{
name|this
operator|->
name|CurNId
operator|=
name|findNextInUse
argument_list|(
name|CurNId
argument_list|)
block|;
comment|// Move to first in-use node id
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|NodeItr
operator|&
name|O
operator|)
specifier|const
block|{
return|return
name|CurNId
operator|==
name|O
operator|.
name|CurNId
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|NodeItr
operator|&
name|O
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|O
operator|)
return|;
block|}
name|NodeItr
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|CurNId
operator|=
name|findNextInUse
argument_list|(
operator|++
name|CurNId
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|NodeId
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|CurNId
return|;
block|}
name|private
label|:
name|NodeId
name|findNextInUse
argument_list|(
name|NodeId
name|NId
argument_list|)
decl|const
block|{
while|while
condition|(
name|NId
operator|<
name|EndNId
operator|&&
name|is_contained
argument_list|(
name|FreeNodeIds
argument_list|,
name|NId
argument_list|)
condition|)
block|{
operator|++
name|NId
expr_stmt|;
block|}
return|return
name|NId
return|;
block|}
name|NodeId
name|CurNId
decl_stmt|,
name|EndNId
decl_stmt|;
specifier|const
name|FreeNodeVector
modifier|&
name|FreeNodeIds
decl_stmt|;
block|}
empty_stmt|;
name|class
name|EdgeItr
block|{
name|public
label|:
name|EdgeItr
argument_list|(
argument|EdgeId CurEId
argument_list|,
argument|const Graph&G
argument_list|)
block|:
name|CurEId
argument_list|(
name|CurEId
argument_list|)
operator|,
name|EndEId
argument_list|(
name|G
operator|.
name|Edges
operator|.
name|size
argument_list|()
argument_list|)
operator|,
name|FreeEdgeIds
argument_list|(
argument|G.FreeEdgeIds
argument_list|)
block|{
name|this
operator|->
name|CurEId
operator|=
name|findNextInUse
argument_list|(
name|CurEId
argument_list|)
block|;
comment|// Move to first in-use edge id
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|EdgeItr
operator|&
name|O
operator|)
specifier|const
block|{
return|return
name|CurEId
operator|==
name|O
operator|.
name|CurEId
return|;
block|}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|EdgeItr
operator|&
name|O
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|O
operator|)
return|;
block|}
name|EdgeItr
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
name|CurEId
operator|=
name|findNextInUse
argument_list|(
operator|++
name|CurEId
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|EdgeId
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|CurEId
return|;
block|}
name|private
label|:
name|EdgeId
name|findNextInUse
argument_list|(
name|EdgeId
name|EId
argument_list|)
decl|const
block|{
while|while
condition|(
name|EId
operator|<
name|EndEId
operator|&&
name|is_contained
argument_list|(
name|FreeEdgeIds
argument_list|,
name|EId
argument_list|)
condition|)
block|{
operator|++
name|EId
expr_stmt|;
block|}
return|return
name|EId
return|;
block|}
name|EdgeId
name|CurEId
decl_stmt|,
name|EndEId
decl_stmt|;
specifier|const
name|FreeEdgeVector
modifier|&
name|FreeEdgeIds
decl_stmt|;
block|}
empty_stmt|;
name|class
name|NodeIdSet
block|{
name|public
label|:
name|NodeIdSet
argument_list|(
specifier|const
name|Graph
operator|&
name|G
argument_list|)
operator|:
name|G
argument_list|(
argument|G
argument_list|)
block|{}
name|NodeItr
name|begin
argument_list|()
specifier|const
block|{
return|return
name|NodeItr
argument_list|(
literal|0
argument_list|,
name|G
argument_list|)
return|;
block|}
name|NodeItr
name|end
argument_list|()
specifier|const
block|{
return|return
name|NodeItr
argument_list|(
name|G
operator|.
name|Nodes
operator|.
name|size
argument_list|()
argument_list|,
name|G
argument_list|)
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|G
operator|.
name|Nodes
operator|.
name|empty
argument_list|()
return|;
block|}
name|typename
name|NodeVector
operator|::
name|size_type
name|size
argument_list|()
specifier|const
block|{
return|return
name|G
operator|.
name|Nodes
operator|.
name|size
argument_list|()
operator|-
name|G
operator|.
name|FreeNodeIds
operator|.
name|size
argument_list|()
return|;
block|}
name|private
label|:
specifier|const
name|Graph
modifier|&
name|G
decl_stmt|;
block|}
empty_stmt|;
name|class
name|EdgeIdSet
block|{
name|public
label|:
name|EdgeIdSet
argument_list|(
specifier|const
name|Graph
operator|&
name|G
argument_list|)
operator|:
name|G
argument_list|(
argument|G
argument_list|)
block|{}
name|EdgeItr
name|begin
argument_list|()
specifier|const
block|{
return|return
name|EdgeItr
argument_list|(
literal|0
argument_list|,
name|G
argument_list|)
return|;
block|}
name|EdgeItr
name|end
argument_list|()
specifier|const
block|{
return|return
name|EdgeItr
argument_list|(
name|G
operator|.
name|Edges
operator|.
name|size
argument_list|()
argument_list|,
name|G
argument_list|)
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|G
operator|.
name|Edges
operator|.
name|empty
argument_list|()
return|;
block|}
name|typename
name|NodeVector
operator|::
name|size_type
name|size
argument_list|()
specifier|const
block|{
return|return
name|G
operator|.
name|Edges
operator|.
name|size
argument_list|()
operator|-
name|G
operator|.
name|FreeEdgeIds
operator|.
name|size
argument_list|()
return|;
block|}
name|private
label|:
specifier|const
name|Graph
modifier|&
name|G
decl_stmt|;
block|}
empty_stmt|;
name|class
name|AdjEdgeIdSet
block|{
name|public
label|:
name|AdjEdgeIdSet
argument_list|(
specifier|const
name|NodeEntry
operator|&
name|NE
argument_list|)
operator|:
name|NE
argument_list|(
argument|NE
argument_list|)
block|{}
name|typename
name|NodeEntry
operator|::
name|AdjEdgeItr
name|begin
argument_list|()
specifier|const
block|{
return|return
name|NE
operator|.
name|getAdjEdgeIds
argument_list|()
operator|.
name|begin
argument_list|()
return|;
block|}
name|typename
name|NodeEntry
operator|::
name|AdjEdgeItr
name|end
argument_list|()
specifier|const
block|{
return|return
name|NE
operator|.
name|getAdjEdgeIds
argument_list|()
operator|.
name|end
argument_list|()
return|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|NE
operator|.
name|getAdjEdgeIds
argument_list|()
operator|.
name|empty
argument_list|()
return|;
block|}
name|typename
name|NodeEntry
operator|::
name|AdjEdgeList
operator|::
name|size_type
name|size
argument_list|()
specifier|const
block|{
return|return
name|NE
operator|.
name|getAdjEdgeIds
argument_list|()
operator|.
name|size
argument_list|()
return|;
block|}
name|private
label|:
specifier|const
name|NodeEntry
modifier|&
name|NE
decl_stmt|;
block|}
empty_stmt|;
comment|/// @brief Construct an empty PBQP graph.
name|Graph
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// @brief Construct an empty PBQP graph with the given graph metadata.
name|Graph
argument_list|(
argument|GraphMetadata Metadata
argument_list|)
block|:
name|Metadata
argument_list|(
argument|std::move(Metadata)
argument_list|)
block|{}
comment|/// @brief Get a reference to the graph metadata.
name|GraphMetadata
modifier|&
name|getMetadata
parameter_list|()
block|{
return|return
name|Metadata
return|;
block|}
comment|/// @brief Get a const-reference to the graph metadata.
specifier|const
name|GraphMetadata
operator|&
name|getMetadata
argument_list|()
specifier|const
block|{
return|return
name|Metadata
return|;
block|}
comment|/// @brief Lock this graph to the given solver instance in preparation
comment|/// for running the solver. This method will call solver.handleAddNode for
comment|/// each node in the graph, and handleAddEdge for each edge, to give the
comment|/// solver an opportunity to set up any requried metadata.
name|void
name|setSolver
parameter_list|(
name|SolverT
modifier|&
name|S
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|Solver
operator|&&
literal|"Solver already set. Call unsetSolver()."
argument_list|)
expr_stmt|;
name|Solver
operator|=
operator|&
name|S
expr_stmt|;
for|for
control|(
name|auto
name|NId
range|:
name|nodeIds
argument_list|()
control|)
name|Solver
operator|->
name|handleAddNode
argument_list|(
name|NId
argument_list|)
expr_stmt|;
for|for
control|(
name|auto
name|EId
range|:
name|edgeIds
argument_list|()
control|)
name|Solver
operator|->
name|handleAddEdge
argument_list|(
name|EId
argument_list|)
expr_stmt|;
block|}
comment|/// @brief Release from solver instance.
name|void
name|unsetSolver
parameter_list|()
block|{
name|assert
argument_list|(
name|Solver
operator|&&
literal|"Solver not set."
argument_list|)
expr_stmt|;
name|Solver
operator|=
name|nullptr
expr_stmt|;
block|}
comment|/// @brief Add a node with the given costs.
comment|/// @param Costs Cost vector for the new node.
comment|/// @return Node iterator for the added node.
name|template
operator|<
name|typename
name|OtherVectorT
operator|>
name|NodeId
name|addNode
argument_list|(
argument|OtherVectorT Costs
argument_list|)
block|{
comment|// Get cost vector from the problem domain
name|VectorPtr
name|AllocatedCosts
operator|=
name|CostAlloc
operator|.
name|getVector
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Costs
argument_list|)
argument_list|)
block|;
name|NodeId
name|NId
operator|=
name|addConstructedNode
argument_list|(
name|NodeEntry
argument_list|(
name|AllocatedCosts
argument_list|)
argument_list|)
block|;
if|if
condition|(
name|Solver
condition|)
name|Solver
operator|->
name|handleAddNode
argument_list|(
name|NId
argument_list|)
expr_stmt|;
return|return
name|NId
return|;
block|}
comment|/// @brief Add a node bypassing the cost allocator.
comment|/// @param Costs Cost vector ptr for the new node (must be convertible to
comment|///        VectorPtr).
comment|/// @return Node iterator for the added node.
comment|///
comment|///   This method allows for fast addition of a node whose costs don't need
comment|/// to be passed through the cost allocator. The most common use case for
comment|/// this is when duplicating costs from an existing node (when using a
comment|/// pooling allocator). These have already been uniqued, so we can avoid
comment|/// re-constructing and re-uniquing them by attaching them directly to the
comment|/// new node.
name|template
operator|<
name|typename
name|OtherVectorPtrT
operator|>
name|NodeId
name|addNodeBypassingCostAllocator
argument_list|(
argument|OtherVectorPtrT Costs
argument_list|)
block|{
name|NodeId
name|NId
operator|=
name|addConstructedNode
argument_list|(
name|NodeEntry
argument_list|(
name|Costs
argument_list|)
argument_list|)
block|;
if|if
condition|(
name|Solver
condition|)
name|Solver
operator|->
name|handleAddNode
argument_list|(
name|NId
argument_list|)
expr_stmt|;
return|return
name|NId
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @brief Add an edge between the given nodes with the given costs.
end_comment

begin_comment
comment|/// @param N1Id First node.
end_comment

begin_comment
comment|/// @param N2Id Second node.
end_comment

begin_comment
comment|/// @param Costs Cost matrix for new edge.
end_comment

begin_comment
comment|/// @return Edge iterator for the added edge.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|OtherVectorT
operator|>
name|EdgeId
name|addEdge
argument_list|(
argument|NodeId N1Id
argument_list|,
argument|NodeId N2Id
argument_list|,
argument|OtherVectorT Costs
argument_list|)
block|{
name|assert
argument_list|(
name|getNodeCosts
argument_list|(
name|N1Id
argument_list|)
operator|.
name|getLength
argument_list|()
operator|==
name|Costs
operator|.
name|getRows
argument_list|()
operator|&&
name|getNodeCosts
argument_list|(
name|N2Id
argument_list|)
operator|.
name|getLength
argument_list|()
operator|==
name|Costs
operator|.
name|getCols
argument_list|()
operator|&&
literal|"Matrix dimensions mismatch."
argument_list|)
block|;
comment|// Get cost matrix from the problem domain.
name|MatrixPtr
name|AllocatedCosts
operator|=
name|CostAlloc
operator|.
name|getMatrix
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Costs
argument_list|)
argument_list|)
block|;
name|EdgeId
name|EId
operator|=
name|addConstructedEdge
argument_list|(
name|EdgeEntry
argument_list|(
name|N1Id
argument_list|,
name|N2Id
argument_list|,
name|AllocatedCosts
argument_list|)
argument_list|)
block|;
if|if
condition|(
name|Solver
condition|)
name|Solver
operator|->
name|handleAddEdge
argument_list|(
name|EId
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|EId
return|;
end_return

begin_comment
unit|}
comment|/// @brief Add an edge bypassing the cost allocator.
end_comment

begin_comment
comment|/// @param N1Id First node.
end_comment

begin_comment
comment|/// @param N2Id Second node.
end_comment

begin_comment
comment|/// @param Costs Cost matrix for new edge.
end_comment

begin_comment
comment|/// @return Edge iterator for the added edge.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   This method allows for fast addition of an edge whose costs don't need
end_comment

begin_comment
comment|/// to be passed through the cost allocator. The most common use case for
end_comment

begin_comment
comment|/// this is when duplicating costs from an existing edge (when using a
end_comment

begin_comment
comment|/// pooling allocator). These have already been uniqued, so we can avoid
end_comment

begin_comment
comment|/// re-constructing and re-uniquing them by attaching them directly to the
end_comment

begin_comment
comment|/// new edge.
end_comment

begin_expr_stmt
unit|template
operator|<
name|typename
name|OtherMatrixPtrT
operator|>
name|NodeId
name|addEdgeBypassingCostAllocator
argument_list|(
argument|NodeId N1Id
argument_list|,
argument|NodeId N2Id
argument_list|,
argument|OtherMatrixPtrT Costs
argument_list|)
block|{
name|assert
argument_list|(
name|getNodeCosts
argument_list|(
name|N1Id
argument_list|)
operator|.
name|getLength
argument_list|()
operator|==
name|Costs
operator|->
name|getRows
argument_list|()
operator|&&
name|getNodeCosts
argument_list|(
name|N2Id
argument_list|)
operator|.
name|getLength
argument_list|()
operator|==
name|Costs
operator|->
name|getCols
argument_list|()
operator|&&
literal|"Matrix dimensions mismatch."
argument_list|)
block|;
comment|// Get cost matrix from the problem domain.
name|EdgeId
name|EId
operator|=
name|addConstructedEdge
argument_list|(
name|EdgeEntry
argument_list|(
name|N1Id
argument_list|,
name|N2Id
argument_list|,
name|Costs
argument_list|)
argument_list|)
block|;
if|if
condition|(
name|Solver
condition|)
name|Solver
operator|->
name|handleAddEdge
argument_list|(
name|EId
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|EId
return|;
end_return

begin_comment
unit|}
comment|/// @brief Returns true if the graph is empty.
end_comment

begin_macro
unit|bool
name|empty
argument_list|()
end_macro

begin_expr_stmt
specifier|const
block|{
return|return
name|NodeIdSet
argument_list|(
operator|*
name|this
argument_list|)
operator|.
name|empty
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|NodeIdSet
name|nodeIds
argument_list|()
specifier|const
block|{
return|return
name|NodeIdSet
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|EdgeIdSet
name|edgeIds
argument_list|()
specifier|const
block|{
return|return
name|EdgeIdSet
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
end_expr_stmt

begin_function
name|AdjEdgeIdSet
name|adjEdgeIds
parameter_list|(
name|NodeId
name|NId
parameter_list|)
block|{
return|return
name|AdjEdgeIdSet
argument_list|(
name|getNode
argument_list|(
name|NId
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// @brief Get the number of nodes in the graph.
end_comment

begin_comment
comment|/// @return Number of nodes in the graph.
end_comment

begin_expr_stmt
name|unsigned
name|getNumNodes
argument_list|()
specifier|const
block|{
return|return
name|NodeIdSet
argument_list|(
operator|*
name|this
argument_list|)
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @brief Get the number of edges in the graph.
end_comment

begin_comment
comment|/// @return Number of edges in the graph.
end_comment

begin_expr_stmt
name|unsigned
name|getNumEdges
argument_list|()
specifier|const
block|{
return|return
name|EdgeIdSet
argument_list|(
operator|*
name|this
argument_list|)
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @brief Set a node's cost vector.
end_comment

begin_comment
comment|/// @param NId Node to update.
end_comment

begin_comment
comment|/// @param Costs New costs to set.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|OtherVectorT
operator|>
name|void
name|setNodeCosts
argument_list|(
argument|NodeId NId
argument_list|,
argument|OtherVectorT Costs
argument_list|)
block|{
name|VectorPtr
name|AllocatedCosts
operator|=
name|CostAlloc
operator|.
name|getVector
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Costs
argument_list|)
argument_list|)
block|;
if|if
condition|(
name|Solver
condition|)
name|Solver
operator|->
name|handleSetNodeCosts
argument_list|(
name|NId
argument_list|,
operator|*
name|AllocatedCosts
argument_list|)
expr_stmt|;
name|getNode
argument_list|(
name|NId
argument_list|)
operator|.
name|Costs
operator|=
name|AllocatedCosts
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/// @brief Get a VectorPtr to a node's cost vector. Rarely useful - use
end_comment

begin_comment
comment|///        getNodeCosts where possible.
end_comment

begin_comment
comment|/// @param NId Node id.
end_comment

begin_comment
comment|/// @return VectorPtr to node cost vector.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   This method is primarily useful for duplicating costs quickly by
end_comment

begin_comment
comment|/// bypassing the cost allocator. See addNodeBypassingCostAllocator. Prefer
end_comment

begin_comment
comment|/// getNodeCosts when dealing with node cost values.
end_comment

begin_decl_stmt
unit|const
name|VectorPtr
modifier|&
name|getNodeCostsPtr
argument_list|(
name|NodeId
name|NId
argument_list|)
decl|const
block|{
return|return
name|getNode
argument_list|(
name|NId
argument_list|)
operator|.
name|Costs
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @brief Get a node's cost vector.
end_comment

begin_comment
comment|/// @param NId Node id.
end_comment

begin_comment
comment|/// @return Node cost vector.
end_comment

begin_decl_stmt
specifier|const
name|Vector
modifier|&
name|getNodeCosts
argument_list|(
name|NodeId
name|NId
argument_list|)
decl|const
block|{
return|return
operator|*
name|getNodeCostsPtr
argument_list|(
name|NId
argument_list|)
return|;
block|}
end_decl_stmt

begin_function
name|NodeMetadata
modifier|&
name|getNodeMetadata
parameter_list|(
name|NodeId
name|NId
parameter_list|)
block|{
return|return
name|getNode
argument_list|(
name|NId
argument_list|)
operator|.
name|Metadata
return|;
block|}
end_function

begin_decl_stmt
specifier|const
name|NodeMetadata
modifier|&
name|getNodeMetadata
argument_list|(
name|NodeId
name|NId
argument_list|)
decl|const
block|{
return|return
name|getNode
argument_list|(
name|NId
argument_list|)
operator|.
name|Metadata
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|typename
name|NodeEntry
operator|::
name|AdjEdgeList
operator|::
name|size_type
name|getNodeDegree
argument_list|(
argument|NodeId NId
argument_list|)
specifier|const
block|{
return|return
name|getNode
argument_list|(
name|NId
argument_list|)
operator|.
name|getAdjEdgeIds
argument_list|()
operator|.
name|size
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @brief Update an edge's cost matrix.
end_comment

begin_comment
comment|/// @param EId Edge id.
end_comment

begin_comment
comment|/// @param Costs New cost matrix.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|OtherMatrixT
operator|>
name|void
name|updateEdgeCosts
argument_list|(
argument|EdgeId EId
argument_list|,
argument|OtherMatrixT Costs
argument_list|)
block|{
name|MatrixPtr
name|AllocatedCosts
operator|=
name|CostAlloc
operator|.
name|getMatrix
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Costs
argument_list|)
argument_list|)
block|;
if|if
condition|(
name|Solver
condition|)
name|Solver
operator|->
name|handleUpdateCosts
argument_list|(
name|EId
argument_list|,
operator|*
name|AllocatedCosts
argument_list|)
expr_stmt|;
name|getEdge
argument_list|(
name|EId
argument_list|)
operator|.
name|Costs
operator|=
name|AllocatedCosts
expr_stmt|;
end_expr_stmt

begin_comment
unit|}
comment|/// @brief Get a MatrixPtr to a node's cost matrix. Rarely useful - use
end_comment

begin_comment
comment|///        getEdgeCosts where possible.
end_comment

begin_comment
comment|/// @param EId Edge id.
end_comment

begin_comment
comment|/// @return MatrixPtr to edge cost matrix.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///   This method is primarily useful for duplicating costs quickly by
end_comment

begin_comment
comment|/// bypassing the cost allocator. See addNodeBypassingCostAllocator. Prefer
end_comment

begin_comment
comment|/// getEdgeCosts when dealing with edge cost values.
end_comment

begin_decl_stmt
unit|const
name|MatrixPtr
modifier|&
name|getEdgeCostsPtr
argument_list|(
name|EdgeId
name|EId
argument_list|)
decl|const
block|{
return|return
name|getEdge
argument_list|(
name|EId
argument_list|)
operator|.
name|Costs
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @brief Get an edge's cost matrix.
end_comment

begin_comment
comment|/// @param EId Edge id.
end_comment

begin_comment
comment|/// @return Edge cost matrix.
end_comment

begin_decl_stmt
specifier|const
name|Matrix
modifier|&
name|getEdgeCosts
argument_list|(
name|EdgeId
name|EId
argument_list|)
decl|const
block|{
return|return
operator|*
name|getEdge
argument_list|(
name|EId
argument_list|)
operator|.
name|Costs
return|;
block|}
end_decl_stmt

begin_function
name|EdgeMetadata
modifier|&
name|getEdgeMetadata
parameter_list|(
name|EdgeId
name|EId
parameter_list|)
block|{
return|return
name|getEdge
argument_list|(
name|EId
argument_list|)
operator|.
name|Metadata
return|;
block|}
end_function

begin_decl_stmt
specifier|const
name|EdgeMetadata
modifier|&
name|getEdgeMetadata
argument_list|(
name|EdgeId
name|EId
argument_list|)
decl|const
block|{
return|return
name|getEdge
argument_list|(
name|EId
argument_list|)
operator|.
name|Metadata
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @brief Get the first node connected to this edge.
end_comment

begin_comment
comment|/// @param EId Edge id.
end_comment

begin_comment
comment|/// @return The first node connected to the given edge.
end_comment

begin_decl_stmt
name|NodeId
name|getEdgeNode1Id
argument_list|(
name|EdgeId
name|EId
argument_list|)
decl|const
block|{
return|return
name|getEdge
argument_list|(
name|EId
argument_list|)
operator|.
name|getN1Id
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @brief Get the second node connected to this edge.
end_comment

begin_comment
comment|/// @param EId Edge id.
end_comment

begin_comment
comment|/// @return The second node connected to the given edge.
end_comment

begin_decl_stmt
name|NodeId
name|getEdgeNode2Id
argument_list|(
name|EdgeId
name|EId
argument_list|)
decl|const
block|{
return|return
name|getEdge
argument_list|(
name|EId
argument_list|)
operator|.
name|getN2Id
argument_list|()
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @brief Get the "other" node connected to this edge.
end_comment

begin_comment
comment|/// @param EId Edge id.
end_comment

begin_comment
comment|/// @param NId Node id for the "given" node.
end_comment

begin_comment
comment|/// @return The iterator for the "other" node connected to this edge.
end_comment

begin_function
name|NodeId
name|getEdgeOtherNodeId
parameter_list|(
name|EdgeId
name|EId
parameter_list|,
name|NodeId
name|NId
parameter_list|)
block|{
name|EdgeEntry
modifier|&
name|E
init|=
name|getEdge
argument_list|(
name|EId
argument_list|)
decl_stmt|;
if|if
condition|(
name|E
operator|.
name|getN1Id
argument_list|()
operator|==
name|NId
condition|)
block|{
return|return
name|E
operator|.
name|getN2Id
argument_list|()
return|;
block|}
comment|// else
return|return
name|E
operator|.
name|getN1Id
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// @brief Get the edge connecting two nodes.
end_comment

begin_comment
comment|/// @param N1Id First node id.
end_comment

begin_comment
comment|/// @param N2Id Second node id.
end_comment

begin_comment
comment|/// @return An id for edge (N1Id, N2Id) if such an edge exists,
end_comment

begin_comment
comment|///         otherwise returns an invalid edge id.
end_comment

begin_function
name|EdgeId
name|findEdge
parameter_list|(
name|NodeId
name|N1Id
parameter_list|,
name|NodeId
name|N2Id
parameter_list|)
block|{
for|for
control|(
name|auto
name|AEId
range|:
name|adjEdgeIds
argument_list|(
name|N1Id
argument_list|)
control|)
block|{
if|if
condition|(
operator|(
name|getEdgeNode1Id
argument_list|(
name|AEId
argument_list|)
operator|==
name|N2Id
operator|)
operator|||
operator|(
name|getEdgeNode2Id
argument_list|(
name|AEId
argument_list|)
operator|==
name|N2Id
operator|)
condition|)
block|{
return|return
name|AEId
return|;
block|}
block|}
return|return
name|invalidEdgeId
argument_list|()
return|;
block|}
end_function

begin_comment
comment|/// @brief Remove a node from the graph.
end_comment

begin_comment
comment|/// @param NId Node id.
end_comment

begin_function
name|void
name|removeNode
parameter_list|(
name|NodeId
name|NId
parameter_list|)
block|{
if|if
condition|(
name|Solver
condition|)
name|Solver
operator|->
name|handleRemoveNode
argument_list|(
name|NId
argument_list|)
expr_stmt|;
name|NodeEntry
modifier|&
name|N
init|=
name|getNode
argument_list|(
name|NId
argument_list|)
decl_stmt|;
comment|// TODO: Can this be for-each'd?
for|for
control|(
name|AdjEdgeItr
name|AEItr
init|=
name|N
operator|.
name|adjEdgesBegin
argument_list|()
init|,
name|AEEnd
init|=
name|N
operator|.
name|adjEdgesEnd
argument_list|()
init|;
name|AEItr
operator|!=
name|AEEnd
condition|;
control|)
block|{
name|EdgeId
name|EId
init|=
operator|*
name|AEItr
decl_stmt|;
operator|++
name|AEItr
expr_stmt|;
name|removeEdge
argument_list|(
name|EId
argument_list|)
expr_stmt|;
block|}
name|FreeNodeIds
operator|.
name|push_back
argument_list|(
name|NId
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// @brief Disconnect an edge from the given node.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Removes the given edge from the adjacency list of the given node.
end_comment

begin_comment
comment|/// This operation leaves the edge in an 'asymmetric' state: It will no
end_comment

begin_comment
comment|/// longer appear in an iteration over the given node's (NId's) edges, but
end_comment

begin_comment
comment|/// will appear in an iteration over the 'other', unnamed node's edges.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This does not correspond to any normal graph operation, but exists to
end_comment

begin_comment
comment|/// support efficient PBQP graph-reduction based solvers. It is used to
end_comment

begin_comment
comment|/// 'effectively' remove the unnamed node from the graph while the solver
end_comment

begin_comment
comment|/// is performing the reduction. The solver will later call reconnectNode
end_comment

begin_comment
comment|/// to restore the edge in the named node's adjacency list.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Since the degree of a node is the number of connected edges,
end_comment

begin_comment
comment|/// disconnecting an edge from a node 'u' will cause the degree of 'u' to
end_comment

begin_comment
comment|/// drop by 1.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A disconnected edge WILL still appear in an iteration over the graph
end_comment

begin_comment
comment|/// edges.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A disconnected edge should not be removed from the graph, it should be
end_comment

begin_comment
comment|/// reconnected first.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A disconnected edge can be reconnected by calling the reconnectEdge
end_comment

begin_comment
comment|/// method.
end_comment

begin_function
name|void
name|disconnectEdge
parameter_list|(
name|EdgeId
name|EId
parameter_list|,
name|NodeId
name|NId
parameter_list|)
block|{
if|if
condition|(
name|Solver
condition|)
name|Solver
operator|->
name|handleDisconnectEdge
argument_list|(
name|EId
argument_list|,
name|NId
argument_list|)
expr_stmt|;
name|EdgeEntry
modifier|&
name|E
init|=
name|getEdge
argument_list|(
name|EId
argument_list|)
decl_stmt|;
name|E
operator|.
name|disconnectFrom
argument_list|(
operator|*
name|this
argument_list|,
name|NId
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// @brief Convenience method to disconnect all neighbours from the given
end_comment

begin_comment
comment|///        node.
end_comment

begin_function
name|void
name|disconnectAllNeighborsFromNode
parameter_list|(
name|NodeId
name|NId
parameter_list|)
block|{
for|for
control|(
name|auto
name|AEId
range|:
name|adjEdgeIds
argument_list|(
name|NId
argument_list|)
control|)
name|disconnectEdge
argument_list|(
name|AEId
argument_list|,
name|getEdgeOtherNodeId
argument_list|(
name|AEId
argument_list|,
name|NId
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// @brief Re-attach an edge to its nodes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Adds an edge that had been previously disconnected back into the
end_comment

begin_comment
comment|/// adjacency set of the nodes that the edge connects.
end_comment

begin_function
name|void
name|reconnectEdge
parameter_list|(
name|EdgeId
name|EId
parameter_list|,
name|NodeId
name|NId
parameter_list|)
block|{
name|EdgeEntry
modifier|&
name|E
init|=
name|getEdge
argument_list|(
name|EId
argument_list|)
decl_stmt|;
name|E
operator|.
name|connectTo
argument_list|(
operator|*
name|this
argument_list|,
name|EId
argument_list|,
name|NId
argument_list|)
expr_stmt|;
if|if
condition|(
name|Solver
condition|)
name|Solver
operator|->
name|handleReconnectEdge
argument_list|(
name|EId
argument_list|,
name|NId
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/// @brief Remove an edge from the graph.
end_comment

begin_comment
comment|/// @param EId Edge id.
end_comment

begin_function
name|void
name|removeEdge
parameter_list|(
name|EdgeId
name|EId
parameter_list|)
block|{
if|if
condition|(
name|Solver
condition|)
name|Solver
operator|->
name|handleRemoveEdge
argument_list|(
name|EId
argument_list|)
expr_stmt|;
name|EdgeEntry
modifier|&
name|E
init|=
name|getEdge
argument_list|(
name|EId
argument_list|)
decl_stmt|;
name|E
operator|.
name|disconnect
argument_list|()
expr_stmt|;
name|FreeEdgeIds
operator|.
name|push_back
argument_list|(
name|EId
argument_list|)
expr_stmt|;
name|Edges
index|[
name|EId
index|]
operator|.
name|invalidate
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|/// @brief Remove all nodes and edges from the graph.
end_comment

begin_function
name|void
name|clear
parameter_list|()
block|{
name|Nodes
operator|.
name|clear
argument_list|()
expr_stmt|;
name|FreeNodeIds
operator|.
name|clear
argument_list|()
expr_stmt|;
name|Edges
operator|.
name|clear
argument_list|()
expr_stmt|;
name|FreeEdgeIds
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
unit|};  }
comment|// end namespace PBQP
end_comment

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_PBQP_GRAPH_HPP
end_comment

end_unit

