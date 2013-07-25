begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PathNumbering.h ----------------------------------------*- C++ -*---===//
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
comment|// Ball-Larus path numbers uniquely identify paths through a directed acyclic
end_comment

begin_comment
comment|// graph (DAG) [Ball96].  For a CFG backedges are removed and replaced by phony
end_comment

begin_comment
comment|// edges to obtain a DAG, and thus the unique path numbers [Ball96].
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The purpose of this analysis is to enumerate the edges in a CFG in order
end_comment

begin_comment
comment|// to obtain paths from path numbers in a convenient manner.  As described in
end_comment

begin_comment
comment|// [Ball96] edges can be enumerated such that given a path number by following
end_comment

begin_comment
comment|// the CFG and updating the path number, the path is obtained.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// [Ball96]
end_comment

begin_comment
comment|//  T. Ball and J. R. Larus. "Efficient Path Profiling."
end_comment

begin_comment
comment|//  International Symposium on Microarchitecture, pages 46-57, 1996.
end_comment

begin_comment
comment|//  http://portal.acm.org/citation.cfm?id=243857
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
name|LLVM_ANALYSIS_PATHNUMBERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_PATHNUMBERING_H
end_define

begin_include
include|#
directive|include
file|"llvm/Analysis/ProfileInfoTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/BasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Instructions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/CFG.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<stack>
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
name|class
name|BallLarusNode
decl_stmt|;
name|class
name|BallLarusEdge
decl_stmt|;
name|class
name|BallLarusDag
decl_stmt|;
comment|// typedefs for storage/ interators of various DAG components
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|BallLarusNode
operator|*
operator|>
name|BLNodeVector
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|BallLarusNode
operator|*
operator|>
operator|::
name|iterator
name|BLNodeIterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|BallLarusEdge
operator|*
operator|>
name|BLEdgeVector
expr_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|BallLarusEdge
operator|*
operator|>
operator|::
name|iterator
name|BLEdgeIterator
expr_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|BasicBlock
operator|*
operator|,
name|BallLarusNode
operator|*
operator|>
name|BLBlockNodeMap
expr_stmt|;
typedef|typedef
name|std
operator|::
name|stack
operator|<
name|BallLarusNode
operator|*
operator|>
name|BLNodeStack
expr_stmt|;
comment|// Represents a basic block with information necessary for the BallLarus
comment|// algorithms.
name|class
name|BallLarusNode
block|{
name|public
label|:
enum|enum
name|NodeColor
block|{
name|WHITE
block|,
name|GRAY
block|,
name|BLACK
block|}
enum|;
comment|// Constructor: Initializes a new Node for the given BasicBlock
name|BallLarusNode
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
operator|:
name|_basicBlock
argument_list|(
name|BB
argument_list|)
operator|,
name|_numberPaths
argument_list|(
literal|0
argument_list|)
operator|,
name|_color
argument_list|(
argument|WHITE
argument_list|)
block|{
specifier|static
name|unsigned
name|nextUID
operator|=
literal|0
block|;
name|_uid
operator|=
name|nextUID
operator|++
block|;   }
comment|// Returns the basic block for the BallLarusNode
name|BasicBlock
operator|*
name|getBlock
argument_list|()
expr_stmt|;
comment|// Get/set the number of paths to the exit starting at the node.
name|unsigned
name|getNumberPaths
parameter_list|()
function_decl|;
name|void
name|setNumberPaths
parameter_list|(
name|unsigned
name|numberPaths
parameter_list|)
function_decl|;
comment|// Get/set the NodeColor used in graph algorithms.
name|NodeColor
name|getColor
parameter_list|()
function_decl|;
name|void
name|setColor
parameter_list|(
name|NodeColor
name|color
parameter_list|)
function_decl|;
comment|// Iterator information for predecessor edges. Includes phony and
comment|// backedges.
name|BLEdgeIterator
name|predBegin
parameter_list|()
function_decl|;
name|BLEdgeIterator
name|predEnd
parameter_list|()
function_decl|;
name|unsigned
name|getNumberPredEdges
parameter_list|()
function_decl|;
comment|// Iterator information for successor edges. Includes phony and
comment|// backedges.
name|BLEdgeIterator
name|succBegin
parameter_list|()
function_decl|;
name|BLEdgeIterator
name|succEnd
parameter_list|()
function_decl|;
name|unsigned
name|getNumberSuccEdges
parameter_list|()
function_decl|;
comment|// Add an edge to the predecessor list.
name|void
name|addPredEdge
parameter_list|(
name|BallLarusEdge
modifier|*
name|edge
parameter_list|)
function_decl|;
comment|// Remove an edge from the predecessor list.
name|void
name|removePredEdge
parameter_list|(
name|BallLarusEdge
modifier|*
name|edge
parameter_list|)
function_decl|;
comment|// Add an edge to the successor list.
name|void
name|addSuccEdge
parameter_list|(
name|BallLarusEdge
modifier|*
name|edge
parameter_list|)
function_decl|;
comment|// Remove an edge from the successor list.
name|void
name|removeSuccEdge
parameter_list|(
name|BallLarusEdge
modifier|*
name|edge
parameter_list|)
function_decl|;
comment|// Returns the name of the BasicBlock being represented.  If BasicBlock
comment|// is null then returns "<null>".  If BasicBlock has no name, then
comment|// "<unnamed>" is returned.  Intended for use with debug output.
name|std
operator|::
name|string
name|getName
argument_list|()
expr_stmt|;
name|private
label|:
comment|// The corresponding underlying BB.
name|BasicBlock
modifier|*
name|_basicBlock
decl_stmt|;
comment|// Holds the predecessor edges of this node.
name|BLEdgeVector
name|_predEdges
decl_stmt|;
comment|// Holds the successor edges of this node.
name|BLEdgeVector
name|_succEdges
decl_stmt|;
comment|// The number of paths from the node to the exit.
name|unsigned
name|_numberPaths
decl_stmt|;
comment|// 'Color' used by graph algorithms to mark the node.
name|NodeColor
name|_color
decl_stmt|;
comment|// Unique ID to ensure naming difference with dotgraphs
name|unsigned
name|_uid
decl_stmt|;
comment|// Removes an edge from an edgeVector.  Used by removePredEdge and
comment|// removeSuccEdge.
name|void
name|removeEdge
parameter_list|(
name|BLEdgeVector
modifier|&
name|v
parameter_list|,
name|BallLarusEdge
modifier|*
name|e
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|// Represents an edge in the Dag.  For an edge, v -> w, v is the source, and
comment|// w is the target.
name|class
name|BallLarusEdge
block|{
name|public
label|:
enum|enum
name|EdgeType
block|{
name|NORMAL
block|,
name|BACKEDGE
block|,
name|SPLITEDGE
block|,
name|BACKEDGE_PHONY
block|,
name|SPLITEDGE_PHONY
block|,
name|CALLEDGE_PHONY
block|}
enum|;
comment|// Constructor: Initializes an BallLarusEdge with a source and target.
name|BallLarusEdge
argument_list|(
argument|BallLarusNode* source
argument_list|,
argument|BallLarusNode* target
argument_list|,
argument|unsigned duplicateNumber
argument_list|)
block|:
name|_source
argument_list|(
name|source
argument_list|)
operator|,
name|_target
argument_list|(
name|target
argument_list|)
operator|,
name|_weight
argument_list|(
literal|0
argument_list|)
operator|,
name|_edgeType
argument_list|(
name|NORMAL
argument_list|)
operator|,
name|_realEdge
argument_list|(
name|NULL
argument_list|)
operator|,
name|_duplicateNumber
argument_list|(
argument|duplicateNumber
argument_list|)
block|{}
comment|// Returns the source/ target node of this edge.
name|BallLarusNode
operator|*
name|getSource
argument_list|()
specifier|const
expr_stmt|;
name|BallLarusNode
operator|*
name|getTarget
argument_list|()
specifier|const
expr_stmt|;
comment|// Sets the type of the edge.
name|EdgeType
name|getType
argument_list|()
specifier|const
expr_stmt|;
comment|// Gets the type of the edge.
name|void
name|setType
parameter_list|(
name|EdgeType
name|type
parameter_list|)
function_decl|;
comment|// Returns the weight of this edge.  Used to decode path numbers to
comment|// sequences of basic blocks.
name|unsigned
name|getWeight
parameter_list|()
function_decl|;
comment|// Sets the weight of the edge.  Used during path numbering.
name|void
name|setWeight
parameter_list|(
name|unsigned
name|weight
parameter_list|)
function_decl|;
comment|// Gets/sets the phony edge originating at the root.
name|BallLarusEdge
modifier|*
name|getPhonyRoot
parameter_list|()
function_decl|;
name|void
name|setPhonyRoot
parameter_list|(
name|BallLarusEdge
modifier|*
name|phonyRoot
parameter_list|)
function_decl|;
comment|// Gets/sets the phony edge terminating at the exit.
name|BallLarusEdge
modifier|*
name|getPhonyExit
parameter_list|()
function_decl|;
name|void
name|setPhonyExit
parameter_list|(
name|BallLarusEdge
modifier|*
name|phonyExit
parameter_list|)
function_decl|;
comment|// Gets/sets the associated real edge if this is a phony edge.
name|BallLarusEdge
modifier|*
name|getRealEdge
parameter_list|()
function_decl|;
name|void
name|setRealEdge
parameter_list|(
name|BallLarusEdge
modifier|*
name|realEdge
parameter_list|)
function_decl|;
comment|// Returns the duplicate number of the edge.
name|unsigned
name|getDuplicateNumber
parameter_list|()
function_decl|;
name|protected
label|:
comment|// Source node for this edge.
name|BallLarusNode
modifier|*
name|_source
decl_stmt|;
comment|// Target node for this edge.
name|BallLarusNode
modifier|*
name|_target
decl_stmt|;
name|private
label|:
comment|// Edge weight cooresponding to path number increments before removing
comment|// increments along a spanning tree. The sum over the edge weights gives
comment|// the path number.
name|unsigned
name|_weight
decl_stmt|;
comment|// Type to represent for what this edge is intended
name|EdgeType
name|_edgeType
decl_stmt|;
comment|// For backedges and split-edges, the phony edge which is linked to the
comment|// root node of the DAG. This contains a path number initialization.
name|BallLarusEdge
modifier|*
name|_phonyRoot
decl_stmt|;
comment|// For backedges and split-edges, the phony edge which is linked to the
comment|// exit node of the DAG. This contains a path counter increment, and
comment|// potentially a path number increment.
name|BallLarusEdge
modifier|*
name|_phonyExit
decl_stmt|;
comment|// If this is a phony edge, _realEdge is a link to the back or split
comment|// edge. Otherwise, this is null.
name|BallLarusEdge
modifier|*
name|_realEdge
decl_stmt|;
comment|// An ID to differentiate between those edges which have the same source
comment|// and destination blocks.
name|unsigned
name|_duplicateNumber
decl_stmt|;
block|}
empty_stmt|;
comment|// Represents the Ball Larus DAG for a given Function.  Can calculate
comment|// various properties required for instrumentation or analysis.  E.g. the
comment|// edge weights that determine the path number.
name|class
name|BallLarusDag
block|{
name|public
label|:
comment|// Initializes a BallLarusDag from the CFG of a given function.  Must
comment|// call init() after creation, since some initialization requires
comment|// virtual functions.
name|BallLarusDag
argument_list|(
name|Function
operator|&
name|F
argument_list|)
operator|:
name|_root
argument_list|(
name|NULL
argument_list|)
operator|,
name|_exit
argument_list|(
name|NULL
argument_list|)
operator|,
name|_function
argument_list|(
argument|F
argument_list|)
block|{}
comment|// Initialization that requires virtual functions which are not fully
comment|// functional in the constructor.
name|void
name|init
argument_list|()
expr_stmt|;
comment|// Frees all memory associated with the DAG.
name|virtual
operator|~
name|BallLarusDag
argument_list|()
expr_stmt|;
comment|// Calculate the path numbers by assigning edge increments as prescribed
comment|// in Ball-Larus path profiling.
name|void
name|calculatePathNumbers
parameter_list|()
function_decl|;
comment|// Returns the number of paths for the DAG.
name|unsigned
name|getNumberOfPaths
parameter_list|()
function_decl|;
comment|// Returns the root (i.e. entry) node for the DAG.
name|BallLarusNode
modifier|*
name|getRoot
parameter_list|()
function_decl|;
comment|// Returns the exit node for the DAG.
name|BallLarusNode
modifier|*
name|getExit
parameter_list|()
function_decl|;
comment|// Returns the function for the DAG.
name|Function
modifier|&
name|getFunction
parameter_list|()
function_decl|;
comment|// Clears the node colors.
name|void
name|clearColors
argument_list|(
name|BallLarusNode
operator|::
name|NodeColor
name|color
argument_list|)
decl_stmt|;
name|protected
label|:
comment|// All nodes in the DAG.
name|BLNodeVector
name|_nodes
decl_stmt|;
comment|// All edges in the DAG.
name|BLEdgeVector
name|_edges
decl_stmt|;
comment|// All backedges in the DAG.
name|BLEdgeVector
name|_backEdges
decl_stmt|;
comment|// Allows subclasses to determine which type of Node is created.
comment|// Override this method to produce subclasses of BallLarusNode if
comment|// necessary. The destructor of BallLarusDag will call free on each pointer
comment|// created.
name|virtual
name|BallLarusNode
modifier|*
name|createNode
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|// Allows subclasses to determine which type of Edge is created.
comment|// Override this method to produce subclasses of BallLarusEdge if
comment|// necessary.  Parameters source and target will have been created by
comment|// createNode and can be cast to the subclass of BallLarusNode*
comment|// returned by createNode. The destructor of BallLarusDag will call free
comment|// on each pointer created.
name|virtual
name|BallLarusEdge
modifier|*
name|createEdge
parameter_list|(
name|BallLarusNode
modifier|*
name|source
parameter_list|,
name|BallLarusNode
modifier|*
name|target
parameter_list|,
name|unsigned
name|duplicateNumber
parameter_list|)
function_decl|;
comment|// Proxy to node's constructor.  Updates the DAG state.
name|BallLarusNode
modifier|*
name|addNode
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
comment|// Proxy to edge's constructor.  Updates the DAG state.
name|BallLarusEdge
modifier|*
name|addEdge
parameter_list|(
name|BallLarusNode
modifier|*
name|source
parameter_list|,
name|BallLarusNode
modifier|*
name|target
parameter_list|,
name|unsigned
name|duplicateNumber
parameter_list|)
function_decl|;
name|private
label|:
comment|// The root (i.e. entry) node for this DAG.
name|BallLarusNode
modifier|*
name|_root
decl_stmt|;
comment|// The exit node for this DAG.
name|BallLarusNode
modifier|*
name|_exit
decl_stmt|;
comment|// The function represented by this DAG.
name|Function
modifier|&
name|_function
decl_stmt|;
comment|// Processes one node and its imediate edges for building the DAG.
name|void
name|buildNode
argument_list|(
name|BLBlockNodeMap
operator|&
name|inDag
argument_list|,
name|std
operator|::
name|stack
operator|<
name|BallLarusNode
operator|*
operator|>
operator|&
name|dfsStack
argument_list|)
decl_stmt|;
comment|// Process an edge in the CFG for DAG building.
name|void
name|buildEdge
argument_list|(
name|BLBlockNodeMap
operator|&
name|inDag
argument_list|,
name|std
operator|::
name|stack
operator|<
name|BallLarusNode
operator|*
operator|>
operator|&
name|dfsStack
argument_list|,
name|BallLarusNode
operator|*
name|currentNode
argument_list|,
name|BasicBlock
operator|*
name|succBB
argument_list|,
name|unsigned
name|duplicateNumber
argument_list|)
decl_stmt|;
comment|// The weight on each edge is the increment required along any path that
comment|// contains that edge.
name|void
name|calculatePathNumbersFrom
parameter_list|(
name|BallLarusNode
modifier|*
name|node
parameter_list|)
function_decl|;
comment|// Adds a backedge with its phony edges.  Updates the DAG state.
name|void
name|addBackedge
parameter_list|(
name|BallLarusNode
modifier|*
name|source
parameter_list|,
name|BallLarusNode
modifier|*
name|target
parameter_list|,
name|unsigned
name|duplicateCount
parameter_list|)
function_decl|;
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

end_unit

