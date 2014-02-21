begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HeuristcBase.h --- Heuristic base class for PBQP --------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CODEGEN_PBQP_HEURISTICBASE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_PBQP_HEURISTICBASE_H
end_define

begin_include
include|#
directive|include
file|"HeuristicSolver.h"
end_include

begin_decl_stmt
name|namespace
name|PBQP
block|{
comment|/// \brief Abstract base class for heuristic implementations.
comment|///
comment|/// This class provides a handy base for heuristic implementations with common
comment|/// solver behaviour implemented for a number of methods.
comment|///
comment|/// To implement your own heuristic using this class as a base you'll have to
comment|/// implement, as a minimum, the following methods:
comment|///<ul>
comment|///<li> void addToHeuristicList(Graph::NodeItr) : Add a node to the
comment|///        heuristic reduction list.
comment|///<li> void heuristicReduce() : Perform a single heuristic reduction.
comment|///<li> void preUpdateEdgeCosts(Graph::EdgeItr) : Handle the (imminent)
comment|///        change to the cost matrix on the given edge (by R2).
comment|///<li> void postUpdateEdgeCostts(Graph::EdgeItr) : Handle the new
comment|///        costs on the given edge.
comment|///<li> void handleAddEdge(Graph::EdgeItr) : Handle the addition of a new
comment|///        edge into the PBQP graph (by R2).
comment|///<li> void handleRemoveEdge(Graph::EdgeItr, Graph::NodeItr) : Handle the
comment|///        disconnection of the given edge from the given node.
comment|///<li> A constructor for your derived class : to pass back a reference to
comment|///        the solver which is using this heuristic.
comment|///</ul>
comment|///
comment|/// These methods are implemented in this class for documentation purposes,
comment|/// but will assert if called.
comment|///
comment|/// Note that this class uses the curiously recursive template idiom to
comment|/// forward calls to the derived class. These methods need not be made
comment|/// virtual, and indeed probably shouldn't for performance reasons.
comment|///
comment|/// You'll also need to provide NodeData and EdgeData structs in your class.
comment|/// These can be used to attach data relevant to your heuristic to each
comment|/// node/edge in the PBQP graph.
name|template
operator|<
name|typename
name|HImpl
operator|>
name|class
name|HeuristicBase
block|{
name|private
operator|:
typedef|typedef
name|std
operator|::
name|list
operator|<
name|Graph
operator|::
name|NodeId
operator|>
name|OptimalList
expr_stmt|;
name|HeuristicSolverImpl
operator|<
name|HImpl
operator|>
operator|&
name|s
expr_stmt|;
name|Graph
modifier|&
name|g
decl_stmt|;
name|OptimalList
name|optimalList
decl_stmt|;
comment|// Return a reference to the derived heuristic.
name|HImpl
modifier|&
name|impl
parameter_list|()
block|{
return|return
name|static_cast
operator|<
name|HImpl
operator|&
operator|>
operator|(
operator|*
name|this
operator|)
return|;
block|}
comment|// Add the given node to the optimal reductions list. Keep an iterator to
comment|// its location for fast removal.
name|void
name|addToOptimalReductionList
argument_list|(
name|Graph
operator|::
name|NodeId
name|nId
argument_list|)
block|{
name|optimalList
operator|.
name|insert
argument_list|(
name|optimalList
operator|.
name|end
argument_list|()
argument_list|,
name|nId
argument_list|)
expr_stmt|;
block|}
name|public
label|:
comment|/// \brief Construct an instance with a reference to the given solver.
comment|/// @param solver The solver which is using this heuristic instance.
name|HeuristicBase
argument_list|(
name|HeuristicSolverImpl
operator|<
name|HImpl
operator|>
operator|&
name|solver
argument_list|)
operator|:
name|s
argument_list|(
name|solver
argument_list|)
operator|,
name|g
argument_list|(
argument|s.getGraph()
argument_list|)
block|{ }
comment|/// \brief Get the solver which is using this heuristic instance.
comment|/// @return The solver which is using this heuristic instance.
comment|///
comment|/// You can use this method to get access to the solver in your derived
comment|/// heuristic implementation.
name|HeuristicSolverImpl
operator|<
name|HImpl
operator|>
operator|&
name|getSolver
argument_list|()
block|{
return|return
name|s
return|;
block|}
comment|/// \brief Get the graph representing the problem to be solved.
comment|/// @return The graph representing the problem to be solved.
name|Graph
modifier|&
name|getGraph
parameter_list|()
block|{
return|return
name|g
return|;
block|}
comment|/// \brief Tell the solver to simplify the graph before the reduction phase.
comment|/// @return Whether or not the solver should run a simplification phase
comment|///         prior to the main setup and reduction.
comment|///
comment|/// HeuristicBase returns true from this method as it's a sensible default,
comment|/// however you can over-ride it in your derived class if you want different
comment|/// behaviour.
name|bool
name|solverRunSimplify
argument_list|()
specifier|const
block|{
return|return
name|true
return|;
block|}
comment|/// \brief Decide whether a node should be optimally or heuristically
comment|///        reduced.
comment|/// @return Whether or not the given node should be listed for optimal
comment|///         reduction (via R0, R1 or R2).
comment|///
comment|/// HeuristicBase returns true for any node with degree less than 3. This is
comment|/// sane and sensible for many situations, but not all. You can over-ride
comment|/// this method in your derived class if you want a different selection
comment|/// criteria. Note however that your criteria for selecting optimal nodes
comment|/// should be<i>at least</i> as strong as this. I.e. Nodes of degree 3 or
comment|/// higher should not be selected under any circumstances.
name|bool
name|shouldOptimallyReduce
argument_list|(
name|Graph
operator|::
name|NodeId
name|nId
argument_list|)
block|{
if|if
condition|(
name|g
operator|.
name|getNodeDegree
argument_list|(
name|nId
argument_list|)
operator|<
literal|3
condition|)
return|return
name|true
return|;
comment|// else
return|return
name|false
return|;
block|}
comment|/// \brief Add the given node to the list of nodes to be optimally reduced.
comment|/// @param nId Node id to be added.
comment|///
comment|/// You probably don't want to over-ride this, except perhaps to record
comment|/// statistics before calling this implementation. HeuristicBase relies on
comment|/// its behaviour.
name|void
name|addToOptimalReduceList
argument_list|(
name|Graph
operator|::
name|NodeId
name|nId
argument_list|)
block|{
name|optimalList
operator|.
name|push_back
argument_list|(
name|nId
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Initialise the heuristic.
comment|///
comment|/// HeuristicBase iterates over all nodes in the problem and adds them to
comment|/// the appropriate list using addToOptimalReduceList or
comment|/// addToHeuristicReduceList based on the result of shouldOptimallyReduce.
comment|///
comment|/// This behaviour should be fine for most situations.
name|void
name|setup
parameter_list|()
block|{
for|for
control|(
name|Graph
operator|::
name|NodeItr
name|nItr
operator|=
name|g
operator|.
name|nodesBegin
argument_list|()
operator|,
name|nEnd
operator|=
name|g
operator|.
name|nodesEnd
argument_list|()
init|;
name|nItr
operator|!=
name|nEnd
condition|;
operator|++
name|nItr
control|)
block|{
if|if
condition|(
name|impl
argument_list|()
operator|.
name|shouldOptimallyReduce
argument_list|(
operator|*
name|nItr
argument_list|)
condition|)
block|{
name|addToOptimalReduceList
argument_list|(
operator|*
name|nItr
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|impl
argument_list|()
operator|.
name|addToHeuristicReduceList
argument_list|(
operator|*
name|nItr
argument_list|)
expr_stmt|;
block|}
block|}
block|}
comment|/// \brief Optimally reduce one of the nodes in the optimal reduce list.
comment|/// @return True if a reduction takes place, false if the optimal reduce
comment|///         list is empty.
comment|///
comment|/// Selects a node from the optimal reduce list and removes it, applying
comment|/// R0, R1 or R2 as appropriate based on the selected node's degree.
name|bool
name|optimalReduce
parameter_list|()
block|{
if|if
condition|(
name|optimalList
operator|.
name|empty
argument_list|()
condition|)
return|return
name|false
return|;
name|Graph
operator|::
name|NodeId
name|nId
operator|=
name|optimalList
operator|.
name|front
argument_list|()
expr_stmt|;
name|optimalList
operator|.
name|pop_front
argument_list|()
expr_stmt|;
switch|switch
condition|(
name|s
operator|.
name|getSolverDegree
argument_list|(
name|nId
argument_list|)
condition|)
block|{
case|case
literal|0
case|:
name|s
operator|.
name|applyR0
argument_list|(
name|nId
argument_list|)
expr_stmt|;
break|break;
case|case
literal|1
case|:
name|s
operator|.
name|applyR1
argument_list|(
name|nId
argument_list|)
expr_stmt|;
break|break;
case|case
literal|2
case|:
name|s
operator|.
name|applyR2
argument_list|(
name|nId
argument_list|)
expr_stmt|;
break|break;
default|default:
name|llvm_unreachable
argument_list|(
literal|"Optimal reductions of degree> 2 nodes is invalid."
argument_list|)
expr_stmt|;
block|}
return|return
name|true
return|;
block|}
comment|/// \brief Perform the PBQP reduction process.
comment|///
comment|/// Reduces the problem to the empty graph by repeated application of the
comment|/// reduction rules R0, R1, R2 and RN.
comment|/// R0, R1 or R2 are always applied if possible before RN is used.
name|void
name|reduce
parameter_list|()
block|{
name|bool
name|finished
init|=
name|false
decl_stmt|;
while|while
condition|(
operator|!
name|finished
condition|)
block|{
if|if
condition|(
operator|!
name|optimalReduce
argument_list|()
condition|)
block|{
if|if
condition|(
name|impl
argument_list|()
operator|.
name|heuristicReduce
argument_list|()
condition|)
block|{
name|getSolver
argument_list|()
operator|.
name|recordRN
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|finished
operator|=
name|true
expr_stmt|;
block|}
block|}
block|}
block|}
comment|/// \brief Add a node to the heuristic reduce list.
comment|/// @param nId Node id to add to the heuristic reduce list.
name|void
name|addToHeuristicList
argument_list|(
name|Graph
operator|::
name|NodeId
name|nId
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Must be implemented in derived class."
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Heuristically reduce one of the nodes in the heuristic
comment|///        reduce list.
comment|/// @return True if a reduction takes place, false if the heuristic reduce
comment|///         list is empty.
name|bool
name|heuristicReduce
parameter_list|()
block|{
name|llvm_unreachable
argument_list|(
literal|"Must be implemented in derived class."
argument_list|)
expr_stmt|;
return|return
name|false
return|;
block|}
comment|/// \brief Prepare a change in the costs on the given edge.
comment|/// @param eId Edge id.
name|void
name|preUpdateEdgeCosts
argument_list|(
name|Graph
operator|::
name|EdgeId
name|eId
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Must be implemented in derived class."
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Handle the change in the costs on the given edge.
comment|/// @param eId Edge id.
name|void
name|postUpdateEdgeCostts
argument_list|(
name|Graph
operator|::
name|EdgeId
name|eId
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Must be implemented in derived class."
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Handle the addition of a new edge into the PBQP graph.
comment|/// @param eId Edge id for the added edge.
name|void
name|handleAddEdge
argument_list|(
name|Graph
operator|::
name|EdgeId
name|eId
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Must be implemented in derived class."
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Handle disconnection of an edge from a node.
comment|/// @param eId Edge id for edge being disconnected.
comment|/// @param nId Node id for the node being disconnected from.
comment|///
comment|/// Edges are frequently removed due to the removal of a node. This
comment|/// method allows for the effect to be computed only for the remaining
comment|/// node in the graph.
name|void
name|handleRemoveEdge
argument_list|(
name|Graph
operator|::
name|EdgeId
name|eId
argument_list|,
name|Graph
operator|::
name|NodeId
name|nId
argument_list|)
block|{
name|llvm_unreachable
argument_list|(
literal|"Must be implemented in derived class."
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Clean up any structures used by HeuristicBase.
comment|///
comment|/// At present this just performs a sanity check: that the optimal reduce
comment|/// list is empty now that reduction has completed.
comment|///
comment|/// If your derived class has more complex structures which need tearing
comment|/// down you should over-ride this method but include a call back to this
comment|/// implementation.
name|void
name|cleanup
parameter_list|()
block|{
name|assert
argument_list|(
name|optimalList
operator|.
name|empty
argument_list|()
operator|&&
literal|"Nodes left over in optimal reduce list?"
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_PBQP_HEURISTICBASE_H
end_comment

end_unit

