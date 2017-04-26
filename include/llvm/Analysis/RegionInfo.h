begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- RegionInfo.h - SESE region analysis ----------------------*- C++ -*-===//
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
comment|// Calculate a program structure tree built out of single entry single exit
end_comment

begin_comment
comment|// regions.
end_comment

begin_comment
comment|// The basic ideas are taken from "The Program Structure Tree - Richard Johnson,
end_comment

begin_comment
comment|// David Pearson, Keshav Pingali - 1994", however enriched with ideas from "The
end_comment

begin_comment
comment|// Refined Process Structure Tree - Jussi Vanhatalo, Hagen Voelyer, Jana
end_comment

begin_comment
comment|// Koehler - 2009".
end_comment

begin_comment
comment|// The algorithm to calculate these data structures however is completely
end_comment

begin_comment
comment|// different, as it takes advantage of existing information already available
end_comment

begin_comment
comment|// in (Post)dominace tree and dominance frontier passes. This leads to a simpler
end_comment

begin_comment
comment|// and in practice hopefully better performing algorithm. The runtime of the
end_comment

begin_comment
comment|// algorithms described in the papers above are both linear in graph size,
end_comment

begin_comment
comment|// O(V+E), whereas this algorithm is not, as the dominance frontier information
end_comment

begin_comment
comment|// itself is not, but in practice runtime seems to be in the order of magnitude
end_comment

begin_comment
comment|// of dominance tree calculation.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// WARNING: LLVM is generally very concerned about compile time such that
end_comment

begin_comment
comment|//          the use of additional analysis passes in the default
end_comment

begin_comment
comment|//          optimization sequence is avoided as much as possible.
end_comment

begin_comment
comment|//          Specifically, if you do not need the RegionInfo, but dominance
end_comment

begin_comment
comment|//          information could be sufficient please base your work only on
end_comment

begin_comment
comment|//          the dominator tree. Most passes maintain it, such that using
end_comment

begin_comment
comment|//          it has often near zero cost. In contrast RegionInfo is by
end_comment

begin_comment
comment|//          default not available, is not maintained by existing
end_comment

begin_comment
comment|//          transformations and there is no intention to do so.
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
name|LLVM_ANALYSIS_REGIONINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_REGIONINFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DepthFirstIterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/iterator_range.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/CFG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Dominators.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/PassManager.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// Class to be specialized for different users of RegionInfo
comment|// (i.e. BasicBlocks or MachineBasicBlocks). This is only to avoid needing to
comment|// pass around an unreasonable number of template parameters.
name|template
operator|<
name|class
name|FuncT_
operator|>
expr|struct
name|RegionTraits
block|{
comment|// FuncT
comment|// BlockT
comment|// RegionT
comment|// RegionNodeT
comment|// RegionInfoT
typedef|typedef
name|typename
name|FuncT_
operator|::
name|UnknownRegionTypeError
name|BrokenT
expr_stmt|;
block|}
empty_stmt|;
name|class
name|DominatorTree
decl_stmt|;
name|class
name|DominanceFrontier
decl_stmt|;
name|class
name|Loop
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
struct_decl|struct
name|PostDominatorTree
struct_decl|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|Region
decl_stmt|;
name|template
operator|<
name|class
name|RegionTr
operator|>
name|class
name|RegionBase
expr_stmt|;
name|class
name|RegionNode
decl_stmt|;
name|class
name|RegionInfo
decl_stmt|;
name|template
operator|<
name|class
name|RegionTr
operator|>
name|class
name|RegionInfoBase
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|RegionTraits
operator|<
name|Function
operator|>
block|{
typedef|typedef
name|Function
name|FuncT
typedef|;
typedef|typedef
name|BasicBlock
name|BlockT
typedef|;
typedef|typedef
name|Region
name|RegionT
typedef|;
typedef|typedef
name|RegionNode
name|RegionNodeT
typedef|;
typedef|typedef
name|RegionInfo
name|RegionInfoT
typedef|;
typedef|typedef
name|DominatorTree
name|DomTreeT
typedef|;
typedef|typedef
name|DomTreeNode
name|DomTreeNodeT
typedef|;
typedef|typedef
name|DominanceFrontier
name|DomFrontierT
typedef|;
typedef|typedef
name|PostDominatorTree
name|PostDomTreeT
typedef|;
typedef|typedef
name|Instruction
name|InstT
typedef|;
typedef|typedef
name|Loop
name|LoopT
typedef|;
typedef|typedef
name|LoopInfo
name|LoopInfoT
typedef|;
specifier|static
name|unsigned
name|getNumSuccessors
parameter_list|(
name|BasicBlock
modifier|*
name|BB
parameter_list|)
block|{
return|return
name|BB
operator|->
name|getTerminator
argument_list|()
operator|->
name|getNumSuccessors
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// @brief Marker class to iterate over the elements of a Region in flat mode.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The class is used to either iterate in Flat mode or by not using it to not
end_comment

begin_comment
comment|/// iterate in Flat mode.  During a Flat mode iteration all Regions are entered
end_comment

begin_comment
comment|/// and the iteration returns every BasicBlock.  If the Flat mode is not
end_comment

begin_comment
comment|/// selected for SubRegions just one RegionNode containing the subregion is
end_comment

begin_comment
comment|/// returned.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|GraphType
operator|>
name|class
name|FlatIt
block|{}
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @brief A RegionNode represents a subregion or a BasicBlock that is part of a
end_comment

begin_comment
comment|/// Region.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|Tr
operator|>
name|class
name|RegionNodeBase
block|{
name|friend
name|class
name|RegionBase
operator|<
name|Tr
operator|>
block|;
name|public
operator|:
typedef|typedef
name|typename
name|Tr
operator|::
name|BlockT
name|BlockT
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|Tr
operator|::
name|RegionT
name|RegionT
expr_stmt|;
end_typedef

begin_label
name|private
label|:
end_label

begin_expr_stmt
name|RegionNodeBase
argument_list|(
specifier|const
name|RegionNodeBase
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|RegionNodeBase
modifier|&
name|operator
init|=
operator|(
specifier|const
name|RegionNodeBase
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// This is the entry basic block that starts this region node.  If this is a
end_comment

begin_comment
comment|/// BasicBlock RegionNode, then entry is just the basic block, that this
end_comment

begin_comment
comment|/// RegionNode represents.  Otherwise it is the entry of this (Sub)RegionNode.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// In the BBtoRegionNode map of the parent of this node, BB will always map
end_comment

begin_comment
comment|/// to this node no matter which kind of node this one is.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The node can hold either a Region or a BasicBlock.
end_comment

begin_comment
comment|/// Use one bit to save, if this RegionNode is a subregion or BasicBlock
end_comment

begin_comment
comment|/// RegionNode.
end_comment

begin_expr_stmt
name|PointerIntPair
operator|<
name|BlockT
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|entry
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @brief The parent Region of this RegionNode.
end_comment

begin_comment
comment|/// @see getParent()
end_comment

begin_decl_stmt
name|RegionT
modifier|*
name|parent
decl_stmt|;
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// @brief Create a RegionNode.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Parent      The parent of this RegionNode.
end_comment

begin_comment
comment|/// @param Entry       The entry BasicBlock of the RegionNode.  If this
end_comment

begin_comment
comment|///                    RegionNode represents a BasicBlock, this is the
end_comment

begin_comment
comment|///                    BasicBlock itself.  If it represents a subregion, this
end_comment

begin_comment
comment|///                    is the entry BasicBlock of the subregion.
end_comment

begin_comment
comment|/// @param isSubRegion If this RegionNode represents a SubRegion.
end_comment

begin_expr_stmt
specifier|inline
name|RegionNodeBase
argument_list|(
argument|RegionT *Parent
argument_list|,
argument|BlockT *Entry
argument_list|,
argument|bool isSubRegion = false
argument_list|)
operator|:
name|entry
argument_list|(
name|Entry
argument_list|,
name|isSubRegion
argument_list|)
operator|,
name|parent
argument_list|(
argument|Parent
argument_list|)
block|{}
name|public
operator|:
comment|/// @brief Get the parent Region of this RegionNode.
comment|///
comment|/// The parent Region is the Region this RegionNode belongs to. If for
comment|/// example a BasicBlock is element of two Regions, there exist two
comment|/// RegionNodes for this BasicBlock. Each with the getParent() function
comment|/// pointing to the Region this RegionNode belongs to.
comment|///
comment|/// @return Get the parent Region of this RegionNode.
specifier|inline
name|RegionT
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|parent
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @brief Get the entry BasicBlock of this RegionNode.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If this RegionNode represents a BasicBlock this is just the BasicBlock
end_comment

begin_comment
comment|/// itself, otherwise we return the entry BasicBlock of the Subregion
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return The entry BasicBlock of this RegionNode.
end_comment

begin_expr_stmt
specifier|inline
name|BlockT
operator|*
name|getEntry
argument_list|()
specifier|const
block|{
return|return
name|entry
operator|.
name|getPointer
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @brief Get the content of this RegionNode.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This can be either a BasicBlock or a subregion. Before calling getNodeAs()
end_comment

begin_comment
comment|/// check the type of the content with the isSubRegion() function call.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return The content of this RegionNode.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|T
operator|>
specifier|inline
name|T
operator|*
name|getNodeAs
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @brief Is this RegionNode a subregion?
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return True if it contains a subregion. False if it contains a
end_comment

begin_comment
comment|///         BasicBlock.
end_comment

begin_expr_stmt
specifier|inline
name|bool
name|isSubRegion
argument_list|()
specifier|const
block|{
return|return
name|entry
operator|.
name|getInt
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// @brief A single entry single exit Region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A Region is a connected subgraph of a control flow graph that has exactly
end_comment

begin_comment
comment|/// two connections to the remaining graph. It can be used to analyze or
end_comment

begin_comment
comment|/// optimize parts of the control flow graph.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A<em> simple Region</em> is connected to the remaining graph by just two
end_comment

begin_comment
comment|/// edges. One edge entering the Region and another one leaving the Region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// An<em> extended Region</em> (or just Region) is a subgraph that can be
end_comment

begin_comment
comment|/// transform into a simple Region. The transformation is done by adding
end_comment

begin_comment
comment|/// BasicBlocks that merge several entry or exit edges so that after the merge
end_comment

begin_comment
comment|/// just one entry and one exit edge exists.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The \e Entry of a Region is the first BasicBlock that is passed after
end_comment

begin_comment
comment|/// entering the Region. It is an element of the Region. The entry BasicBlock
end_comment

begin_comment
comment|/// dominates all BasicBlocks in the Region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The \e Exit of a Region is the first BasicBlock that is passed after
end_comment

begin_comment
comment|/// leaving the Region. It is not an element of the Region. The exit BasicBlock,
end_comment

begin_comment
comment|/// postdominates all BasicBlocks in the Region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A<em> canonical Region</em> cannot be constructed by combining smaller
end_comment

begin_comment
comment|/// Regions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Region A is the \e parent of Region B, if B is completely contained in A.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Two canonical Regions either do not intersect at all or one is
end_comment

begin_comment
comment|/// the parent of the other.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The<em> Program Structure Tree</em> is a graph (V, E) where V is the set of
end_comment

begin_comment
comment|/// Regions in the control flow graph and E is the \e parent relation of these
end_comment

begin_comment
comment|/// Regions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Example:
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \verbatim
end_comment

begin_comment
comment|/// A simple control flow graph, that contains two regions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///        1
end_comment

begin_comment
comment|///       / |
end_comment

begin_comment
comment|///      2   |
end_comment

begin_comment
comment|///     / \   3
end_comment

begin_comment
comment|///    4   5  |
end_comment

begin_comment
comment|///    |   |  |
end_comment

begin_comment
comment|///    6   7  8
end_comment

begin_comment
comment|///     \  | /
end_comment

begin_comment
comment|///      \ |/       Region A: 1 -> 9 {1,2,3,4,5,6,7,8}
end_comment

begin_comment
comment|///        9        Region B: 2 -> 9 {2,4,5,6,7}
end_comment

begin_comment
comment|/// \endverbatim
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// You can obtain more examples by either calling
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|///<tt> "opt -regions -analyze anyprogram.ll"</tt>
end_comment

begin_comment
comment|/// or
end_comment

begin_comment
comment|///<tt> "opt -view-regions-only anyprogram.ll"</tt>
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// on any LLVM file you are interested in.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The first call returns a textual representation of the program structure
end_comment

begin_comment
comment|/// tree, the second one creates a graphical representation using graphviz.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|Tr
operator|>
name|class
name|RegionBase
operator|:
name|public
name|RegionNodeBase
operator|<
name|Tr
operator|>
block|{
typedef|typedef
name|typename
name|Tr
operator|::
name|FuncT
name|FuncT
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|Tr
operator|::
name|BlockT
name|BlockT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Tr
operator|::
name|RegionInfoT
name|RegionInfoT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Tr
operator|::
name|RegionT
name|RegionT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Tr
operator|::
name|RegionNodeT
name|RegionNodeT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Tr
operator|::
name|DomTreeT
name|DomTreeT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Tr
operator|::
name|LoopT
name|LoopT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Tr
operator|::
name|LoopInfoT
name|LoopInfoT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Tr
operator|::
name|InstT
name|InstT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|GraphTraits
operator|<
name|BlockT
operator|*
operator|>
name|BlockTraits
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|GraphTraits
operator|<
name|Inverse
operator|<
name|BlockT
operator|*
operator|>>
name|InvBlockTraits
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|BlockTraits
operator|::
name|ChildIteratorType
name|SuccIterTy
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|InvBlockTraits
operator|::
name|ChildIteratorType
name|PredIterTy
expr_stmt|;
end_typedef

begin_expr_stmt
name|friend
name|class
name|RegionInfoBase
operator|<
name|Tr
operator|>
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RegionBase
argument_list|(
specifier|const
name|RegionBase
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|RegionBase
modifier|&
name|operator
init|=
operator|(
specifier|const
name|RegionBase
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Information necessary to manage this Region.
end_comment

begin_decl_stmt
name|RegionInfoT
modifier|*
name|RI
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DomTreeT
modifier|*
name|DT
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The exit BasicBlock of this region.
end_comment

begin_comment
comment|// (The entry BasicBlock is part of RegionNode)
end_comment

begin_decl_stmt
name|BlockT
modifier|*
name|exit
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|RegionT
operator|>>
name|RegionSet
expr_stmt|;
end_typedef

begin_comment
comment|// The subregions of this region.
end_comment

begin_decl_stmt
name|RegionSet
name|children
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|std
operator|::
name|map
operator|<
name|BlockT
operator|*
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|RegionNodeT
operator|>>
name|BBNodeMapT
expr_stmt|;
end_typedef

begin_comment
comment|// Save the BasicBlock RegionNodes that are element of this Region.
end_comment

begin_decl_stmt
name|mutable
name|BBNodeMapT
name|BBNodeMap
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Check if a BB is in this Region. This check also works
end_comment

begin_comment
comment|/// if the region is incorrectly built. (EXPENSIVE!)
end_comment

begin_decl_stmt
name|void
name|verifyBBInRegion
argument_list|(
name|BlockT
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Walk over all the BBs of the region starting from BB and
end_comment

begin_comment
comment|/// verify that all reachable basic blocks are elements of the region.
end_comment

begin_comment
comment|/// (EXPENSIVE!)
end_comment

begin_decl_stmt
name|void
name|verifyWalk
argument_list|(
name|BlockT
operator|*
name|BB
argument_list|,
name|std
operator|::
name|set
operator|<
name|BlockT
operator|*
operator|>
operator|*
name|visitedBB
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Verify if the region and its children are valid regions (EXPENSIVE!)
end_comment

begin_expr_stmt
name|void
name|verifyRegionNest
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// @brief Create a new region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Entry  The entry basic block of the region.
end_comment

begin_comment
comment|/// @param Exit   The exit basic block of the region.
end_comment

begin_comment
comment|/// @param RI     The region info object that is managing this region.
end_comment

begin_comment
comment|/// @param DT     The dominator tree of the current function.
end_comment

begin_comment
comment|/// @param Parent The surrounding region or NULL if this is a top level
end_comment

begin_comment
comment|///               region.
end_comment

begin_expr_stmt
name|RegionBase
argument_list|(
name|BlockT
operator|*
name|Entry
argument_list|,
name|BlockT
operator|*
name|Exit
argument_list|,
name|RegionInfoT
operator|*
name|RI
argument_list|,
name|DomTreeT
operator|*
name|DT
argument_list|,
name|RegionT
operator|*
name|Parent
operator|=
name|nullptr
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Delete the Region and all its subregions.
end_comment

begin_expr_stmt
operator|~
name|RegionBase
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @brief Get the entry BasicBlock of the Region.
end_comment

begin_comment
comment|/// @return The entry BasicBlock of the region.
end_comment

begin_expr_stmt
name|BlockT
operator|*
name|getEntry
argument_list|()
specifier|const
block|{
return|return
name|RegionNodeBase
operator|<
name|Tr
operator|>
operator|::
name|getEntry
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @brief Replace the entry basic block of the region with the new basic
end_comment

begin_comment
comment|///        block.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param BB  The new entry basic block of the region.
end_comment

begin_function_decl
name|void
name|replaceEntry
parameter_list|(
name|BlockT
modifier|*
name|BB
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @brief Replace the exit basic block of the region with the new basic
end_comment

begin_comment
comment|///        block.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param BB  The new exit basic block of the region.
end_comment

begin_function_decl
name|void
name|replaceExit
parameter_list|(
name|BlockT
modifier|*
name|BB
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @brief Recursively replace the entry basic block of the region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function replaces the entry basic block with a new basic block. It
end_comment

begin_comment
comment|/// also updates all child regions that have the same entry basic block as
end_comment

begin_comment
comment|/// this region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param NewEntry The new entry basic block.
end_comment

begin_function_decl
name|void
name|replaceEntryRecursive
parameter_list|(
name|BlockT
modifier|*
name|NewEntry
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @brief Recursively replace the exit basic block of the region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function replaces the exit basic block with a new basic block. It
end_comment

begin_comment
comment|/// also updates all child regions that have the same exit basic block as
end_comment

begin_comment
comment|/// this region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param NewExit The new exit basic block.
end_comment

begin_function_decl
name|void
name|replaceExitRecursive
parameter_list|(
name|BlockT
modifier|*
name|NewExit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @brief Get the exit BasicBlock of the Region.
end_comment

begin_comment
comment|/// @return The exit BasicBlock of the Region, NULL if this is the TopLevel
end_comment

begin_comment
comment|///         Region.
end_comment

begin_expr_stmt
name|BlockT
operator|*
name|getExit
argument_list|()
specifier|const
block|{
return|return
name|exit
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @brief Get the parent of the Region.
end_comment

begin_comment
comment|/// @return The parent of the Region or NULL if this is a top level
end_comment

begin_comment
comment|///         Region.
end_comment

begin_expr_stmt
name|RegionT
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|RegionNodeBase
operator|<
name|Tr
operator|>
operator|::
name|getParent
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @brief Get the RegionNode representing the current Region.
end_comment

begin_comment
comment|/// @return The RegionNode representing the current Region.
end_comment

begin_expr_stmt
name|RegionNodeT
operator|*
name|getNode
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|RegionNodeT
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|RegionNodeT
operator|*
operator|>
operator|(
name|this
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @brief Get the nesting level of this Region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// An toplevel Region has depth 0.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return The depth of the region.
end_comment

begin_expr_stmt
name|unsigned
name|getDepth
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @brief Check if a Region is the TopLevel region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The toplevel region represents the whole function.
end_comment

begin_expr_stmt
name|bool
name|isTopLevelRegion
argument_list|()
specifier|const
block|{
return|return
name|exit
operator|==
name|nullptr
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @brief Return a new (non-canonical) region, that is obtained by joining
end_comment

begin_comment
comment|///        this region with its predecessors.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return A region also starting at getEntry(), but reaching to the next
end_comment

begin_comment
comment|///         basic block that forms with getEntry() a (non-canonical) region.
end_comment

begin_comment
comment|///         NULL if such a basic block does not exist.
end_comment

begin_expr_stmt
name|RegionT
operator|*
name|getExpandedRegion
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @brief Return the first block of this region's single entry edge,
end_comment

begin_comment
comment|///        if existing.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return The BasicBlock starting this region's single entry edge,
end_comment

begin_comment
comment|///         else NULL.
end_comment

begin_expr_stmt
name|BlockT
operator|*
name|getEnteringBlock
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @brief Return the first block of this region's single exit edge,
end_comment

begin_comment
comment|///        if existing.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return The BasicBlock starting this region's single exit edge,
end_comment

begin_comment
comment|///         else NULL.
end_comment

begin_expr_stmt
name|BlockT
operator|*
name|getExitingBlock
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @brief Is this a simple region?
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A region is simple if it has exactly one exit and one entry edge.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @return True if the Region is simple.
end_comment

begin_expr_stmt
name|bool
name|isSimple
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @brief Returns the name of the Region.
end_comment

begin_comment
comment|/// @return The Name of the Region.
end_comment

begin_expr_stmt
name|std
operator|::
name|string
name|getNameStr
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @brief Return the RegionInfo object, that belongs to this Region.
end_comment

begin_expr_stmt
name|RegionInfoT
operator|*
name|getRegionInfo
argument_list|()
specifier|const
block|{
return|return
name|RI
return|;
block|}
end_expr_stmt

begin_comment
comment|/// PrintStyle - Print region in difference ways.
end_comment

begin_enum
enum|enum
name|PrintStyle
block|{
name|PrintNone
block|,
name|PrintBB
block|,
name|PrintRN
block|}
enum|;
end_enum

begin_comment
comment|/// @brief Print the region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param OS The output stream the Region is printed to.
end_comment

begin_comment
comment|/// @param printTree Print also the tree of subregions.
end_comment

begin_comment
comment|/// @param level The indentation level used for printing.
end_comment

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
name|bool
name|printTree
operator|=
name|true
argument_list|,
name|unsigned
name|level
operator|=
literal|0
argument_list|,
name|PrintStyle
name|Style
operator|=
name|PrintNone
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NDEBUG
argument_list|)
operator|||
name|defined
argument_list|(
name|LLVM_ENABLE_DUMP
argument_list|)
end_if

begin_comment
comment|/// @brief Print the region to stderr.
end_comment

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// @brief Check if the region contains a BasicBlock.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param BB The BasicBlock that might be contained in this Region.
end_comment

begin_comment
comment|/// @return True if the block is contained in the region otherwise false.
end_comment

begin_decl_stmt
name|bool
name|contains
argument_list|(
specifier|const
name|BlockT
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @brief Check if the region contains another region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param SubRegion The region that might be contained in this Region.
end_comment

begin_comment
comment|/// @return True if SubRegion is contained in the region otherwise false.
end_comment

begin_decl_stmt
name|bool
name|contains
argument_list|(
specifier|const
name|RegionT
operator|*
name|SubRegion
argument_list|)
decl|const
block|{
comment|// Toplevel Region.
if|if
condition|(
operator|!
name|getExit
argument_list|()
condition|)
return|return
name|true
return|;
return|return
name|contains
argument_list|(
name|SubRegion
operator|->
name|getEntry
argument_list|()
argument_list|)
operator|&&
operator|(
name|contains
argument_list|(
name|SubRegion
operator|->
name|getExit
argument_list|()
argument_list|)
operator|||
name|SubRegion
operator|->
name|getExit
argument_list|()
operator|==
name|getExit
argument_list|()
operator|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @brief Check if the region contains an Instruction.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Inst The Instruction that might be contained in this region.
end_comment

begin_comment
comment|/// @return True if the Instruction is contained in the region otherwise
end_comment

begin_comment
comment|/// false.
end_comment

begin_decl_stmt
name|bool
name|contains
argument_list|(
specifier|const
name|InstT
operator|*
name|Inst
argument_list|)
decl|const
block|{
return|return
name|contains
argument_list|(
name|Inst
operator|->
name|getParent
argument_list|()
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @brief Check if the region contains a loop.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param L The loop that might be contained in this region.
end_comment

begin_comment
comment|/// @return True if the loop is contained in the region otherwise false.
end_comment

begin_comment
comment|///         In case a NULL pointer is passed to this function the result
end_comment

begin_comment
comment|///         is false, except for the region that describes the whole function.
end_comment

begin_comment
comment|///         In that case true is returned.
end_comment

begin_decl_stmt
name|bool
name|contains
argument_list|(
specifier|const
name|LoopT
operator|*
name|L
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @brief Get the outermost loop in the region that contains a loop.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Find for a Loop L the outermost loop OuterL that is a parent loop of L
end_comment

begin_comment
comment|/// and is itself contained in the region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param L The loop the lookup is started.
end_comment

begin_comment
comment|/// @return The outermost loop in the region, NULL if such a loop does not
end_comment

begin_comment
comment|///         exist or if the region describes the whole function.
end_comment

begin_decl_stmt
name|LoopT
modifier|*
name|outermostLoopInRegion
argument_list|(
name|LoopT
operator|*
name|L
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @brief Get the outermost loop in the region that contains a basic block.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Find for a basic block BB the outermost loop L that contains BB and is
end_comment

begin_comment
comment|/// itself contained in the region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param LI A pointer to a LoopInfo analysis.
end_comment

begin_comment
comment|/// @param BB The basic block surrounded by the loop.
end_comment

begin_comment
comment|/// @return The outermost loop in the region, NULL if such a loop does not
end_comment

begin_comment
comment|///         exist or if the region describes the whole function.
end_comment

begin_decl_stmt
name|LoopT
modifier|*
name|outermostLoopInRegion
argument_list|(
name|LoopInfoT
operator|*
name|LI
argument_list|,
name|BlockT
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @brief Get the subregion that starts at a BasicBlock
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param BB The BasicBlock the subregion should start.
end_comment

begin_comment
comment|/// @return The Subregion if available, otherwise NULL.
end_comment

begin_decl_stmt
name|RegionT
modifier|*
name|getSubRegionNode
argument_list|(
name|BlockT
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @brief Get the RegionNode for a BasicBlock
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param BB The BasicBlock at which the RegionNode should start.
end_comment

begin_comment
comment|/// @return If available, the RegionNode that represents the subregion
end_comment

begin_comment
comment|///         starting at BB. If no subregion starts at BB, the RegionNode
end_comment

begin_comment
comment|///         representing BB.
end_comment

begin_decl_stmt
name|RegionNodeT
modifier|*
name|getNode
argument_list|(
name|BlockT
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @brief Get the BasicBlock RegionNode for a BasicBlock
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param BB The BasicBlock for which the RegionNode is requested.
end_comment

begin_comment
comment|/// @return The RegionNode representing the BB.
end_comment

begin_decl_stmt
name|RegionNodeT
modifier|*
name|getBBNode
argument_list|(
name|BlockT
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @brief Add a new subregion to this Region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param SubRegion The new subregion that will be added.
end_comment

begin_comment
comment|/// @param moveChildren Move the children of this region, that are also
end_comment

begin_comment
comment|///                     contained in SubRegion into SubRegion.
end_comment

begin_function_decl
name|void
name|addSubRegion
parameter_list|(
name|RegionT
modifier|*
name|SubRegion
parameter_list|,
name|bool
name|moveChildren
init|=
name|false
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @brief Remove a subregion from this Region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The subregion is not deleted, as it will probably be inserted into another
end_comment

begin_comment
comment|/// region.
end_comment

begin_comment
comment|/// @param SubRegion The SubRegion that will be removed.
end_comment

begin_function_decl
name|RegionT
modifier|*
name|removeSubRegion
parameter_list|(
name|RegionT
modifier|*
name|SubRegion
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @brief Move all direct child nodes of this Region to another Region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param To The Region the child nodes will be transferred to.
end_comment

begin_function_decl
name|void
name|transferChildrenTo
parameter_list|(
name|RegionT
modifier|*
name|To
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @brief Verify if the region is a correct region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Check if this is a correctly build Region. This is an expensive check, as
end_comment

begin_comment
comment|/// the complete CFG of the Region will be walked.
end_comment

begin_expr_stmt
name|void
name|verifyRegion
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @brief Clear the cache for BB RegionNodes.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// After calling this function the BasicBlock RegionNodes will be stored at
end_comment

begin_comment
comment|/// different memory locations. RegionNodes obtained before this function is
end_comment

begin_comment
comment|/// called are therefore not comparable to RegionNodes abtained afterwords.
end_comment

begin_function_decl
name|void
name|clearNodeCache
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// @name Subregion Iterators
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These iterators iterator over all subregions of this Region.
end_comment

begin_comment
comment|//@{
end_comment

begin_typedef
typedef|typedef
name|typename
name|RegionSet
operator|::
name|iterator
name|iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|RegionSet
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
end_typedef

begin_function
name|iterator
name|begin
parameter_list|()
block|{
return|return
name|children
operator|.
name|begin
argument_list|()
return|;
block|}
end_function

begin_function
name|iterator
name|end
parameter_list|()
block|{
return|return
name|children
operator|.
name|end
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|children
operator|.
name|begin
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|children
operator|.
name|end
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|//@}
end_comment

begin_comment
comment|/// @name BasicBlock Iterators
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These iterators iterate over all BasicBlocks that are contained in this
end_comment

begin_comment
comment|/// Region. The iterator also iterates over BasicBlocks that are elements of
end_comment

begin_comment
comment|/// a subregion of this Region. It is therefore called a flat iterator.
end_comment

begin_comment
comment|//@{
end_comment

begin_expr_stmt
name|template
operator|<
name|bool
name|IsConst
operator|>
name|class
name|block_iterator_wrapper
operator|:
name|public
name|df_iterator
operator|<
name|typename
name|std
operator|::
name|conditional
operator|<
name|IsConst
operator|,
specifier|const
name|BlockT
operator|,
name|BlockT
operator|>
operator|::
name|type
operator|*
operator|>
block|{
typedef|typedef
name|df_iterator
operator|<
name|typename
name|std
operator|::
name|conditional
operator|<
name|IsConst
operator|,
specifier|const
name|BlockT
operator|,
name|BlockT
operator|>
operator|::
name|type
operator|*
operator|>
name|super
expr_stmt|;
name|public
operator|:
end_expr_stmt

begin_typedef
typedef|typedef
name|block_iterator_wrapper
operator|<
name|IsConst
operator|>
name|Self
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|super
operator|::
name|value_type
name|value_type
expr_stmt|;
end_typedef

begin_comment
comment|// Construct the begin iterator.
end_comment

begin_macro
name|block_iterator_wrapper
argument_list|(
argument|value_type Entry
argument_list|,
argument|value_type Exit
argument_list|)
end_macro

begin_macro
unit|:
name|super
argument_list|(
argument|df_begin(Entry)
argument_list|)
end_macro

begin_block
block|{
comment|// Mark the exit of the region as visited, so that the children of the
comment|// exit and the exit itself, i.e. the block outside the region will never
comment|// be visited.
name|super
operator|::
name|Visited
operator|.
name|insert
argument_list|(
name|Exit
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|// Construct the end iterator.
end_comment

begin_expr_stmt
name|block_iterator_wrapper
argument_list|()
operator|:
name|super
argument_list|(
argument|df_end<value_type>((BlockT *)nullptr)
argument_list|)
block|{}
comment|/*implicit*/
name|block_iterator_wrapper
argument_list|(
argument|super I
argument_list|)
operator|:
name|super
argument_list|(
argument|I
argument_list|)
block|{}
comment|// FIXME: Even a const_iterator returns a non-const BasicBlock pointer.
comment|//        This was introduced for backwards compatibility, but should
comment|//        be removed as soon as all users are fixed.
name|BlockT
operator|*
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
return|return
name|const_cast
operator|<
name|BlockT
operator|*
operator|>
operator|(
name|super
operator|::
name|operator
operator|*
operator|(
operator|)
operator|)
return|;
block|}
end_expr_stmt

begin_typedef
unit|};
typedef|typedef
name|block_iterator_wrapper
operator|<
name|false
operator|>
name|block_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|block_iterator_wrapper
operator|<
name|true
operator|>
name|const_block_iterator
expr_stmt|;
end_typedef

begin_function
name|block_iterator
name|block_begin
parameter_list|()
block|{
return|return
name|block_iterator
argument_list|(
name|getEntry
argument_list|()
argument_list|,
name|getExit
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
name|block_iterator
name|block_end
parameter_list|()
block|{
return|return
name|block_iterator
argument_list|()
return|;
block|}
end_function

begin_expr_stmt
name|const_block_iterator
name|block_begin
argument_list|()
specifier|const
block|{
return|return
name|const_block_iterator
argument_list|(
name|getEntry
argument_list|()
argument_list|,
name|getExit
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_block_iterator
name|block_end
argument_list|()
specifier|const
block|{
return|return
name|const_block_iterator
argument_list|()
return|;
block|}
end_expr_stmt

begin_typedef
typedef|typedef
name|iterator_range
operator|<
name|block_iterator
operator|>
name|block_range
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|iterator_range
operator|<
name|const_block_iterator
operator|>
name|const_block_range
expr_stmt|;
end_typedef

begin_comment
comment|/// @brief Returns a range view of the basic blocks in the region.
end_comment

begin_function
specifier|inline
name|block_range
name|blocks
parameter_list|()
block|{
return|return
name|block_range
argument_list|(
name|block_begin
argument_list|()
argument_list|,
name|block_end
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/// @brief Returns a range view of the basic blocks in the region.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is the 'const' version of the range view.
end_comment

begin_expr_stmt
specifier|inline
name|const_block_range
name|blocks
argument_list|()
specifier|const
block|{
return|return
name|const_block_range
argument_list|(
name|block_begin
argument_list|()
argument_list|,
name|block_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|//@}
end_comment

begin_comment
comment|/// @name Element Iterators
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// These iterators iterate over all BasicBlock and subregion RegionNodes that
end_comment

begin_comment
comment|/// are direct children of this Region. It does not iterate over any
end_comment

begin_comment
comment|/// RegionNodes that are also element of a subregion of this Region.
end_comment

begin_comment
comment|//@{
end_comment

begin_typedef
typedef|typedef
name|df_iterator
operator|<
name|RegionNodeT
operator|*
operator|,
name|df_iterator_default_set
operator|<
name|RegionNodeT
operator|*
operator|>
operator|,
name|false
operator|,
name|GraphTraits
operator|<
name|RegionNodeT
operator|*
operator|>>
name|element_iterator
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|df_iterator
operator|<
specifier|const
name|RegionNodeT
operator|*
operator|,
name|df_iterator_default_set
operator|<
specifier|const
name|RegionNodeT
operator|*
operator|>
operator|,
name|false
operator|,
name|GraphTraits
operator|<
specifier|const
name|RegionNodeT
operator|*
operator|>>
name|const_element_iterator
expr_stmt|;
end_typedef

begin_function_decl
name|element_iterator
name|element_begin
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|element_iterator
name|element_end
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
name|iterator_range
operator|<
name|element_iterator
operator|>
name|elements
argument_list|()
block|{
return|return
name|make_range
argument_list|(
name|element_begin
argument_list|()
argument_list|,
name|element_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|const_element_iterator
name|element_begin
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|const_element_iterator
name|element_end
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|iterator_range
operator|<
name|const_element_iterator
operator|>
name|elements
argument_list|()
specifier|const
block|{
return|return
name|make_range
argument_list|(
name|element_begin
argument_list|()
argument_list|,
name|element_end
argument_list|()
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|//@}
end_comment

begin_comment
unit|};
comment|/// Print a RegionNode.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|Tr
operator|>
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|RegionNodeBase
operator|<
name|Tr
operator|>
operator|&
name|Node
operator|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|/// @brief Analysis that detects all canonical Regions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The RegionInfo pass detects all canonical regions in a function. The Regions
end_comment

begin_comment
comment|/// are connected using the parent relation. This builds a Program Structure
end_comment

begin_comment
comment|/// Tree.
end_comment

begin_expr_stmt
name|template
operator|<
name|class
name|Tr
operator|>
name|class
name|RegionInfoBase
block|{
typedef|typedef
name|typename
name|Tr
operator|::
name|BlockT
name|BlockT
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|Tr
operator|::
name|FuncT
name|FuncT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Tr
operator|::
name|RegionT
name|RegionT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Tr
operator|::
name|RegionInfoT
name|RegionInfoT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Tr
operator|::
name|DomTreeT
name|DomTreeT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Tr
operator|::
name|DomTreeNodeT
name|DomTreeNodeT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Tr
operator|::
name|PostDomTreeT
name|PostDomTreeT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|Tr
operator|::
name|DomFrontierT
name|DomFrontierT
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|GraphTraits
operator|<
name|BlockT
operator|*
operator|>
name|BlockTraits
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|GraphTraits
operator|<
name|Inverse
operator|<
name|BlockT
operator|*
operator|>>
name|InvBlockTraits
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|BlockTraits
operator|::
name|ChildIteratorType
name|SuccIterTy
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|typename
name|InvBlockTraits
operator|::
name|ChildIteratorType
name|PredIterTy
expr_stmt|;
end_typedef

begin_decl_stmt
name|friend
name|class
name|RegionInfo
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|friend
name|class
name|MachineRegionInfo
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|DenseMap
operator|<
name|BlockT
operator|*
operator|,
name|BlockT
operator|*
operator|>
name|BBtoBBMap
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|DenseMap
operator|<
name|BlockT
operator|*
operator|,
name|RegionT
operator|*
operator|>
name|BBtoRegionMap
expr_stmt|;
end_typedef

begin_expr_stmt
name|RegionInfoBase
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|virtual
operator|~
name|RegionInfoBase
argument_list|()
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|RegionInfoBase
argument_list|(
specifier|const
name|RegionInfoBase
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
end_expr_stmt

begin_decl_stmt
specifier|const
name|RegionInfoBase
modifier|&
name|operator
init|=
operator|(
specifier|const
name|RegionInfoBase
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|RegionInfoBase
argument_list|(
name|RegionInfoBase
operator|&&
name|Arg
argument_list|)
operator|:
name|DT
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Arg
operator|.
name|DT
argument_list|)
argument_list|)
operator|,
name|PDT
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Arg
operator|.
name|PDT
argument_list|)
argument_list|)
operator|,
name|DF
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Arg
operator|.
name|DF
argument_list|)
argument_list|)
operator|,
name|TopLevelRegion
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Arg
operator|.
name|TopLevelRegion
argument_list|)
argument_list|)
operator|,
name|BBtoRegion
argument_list|(
argument|std::move(Arg.BBtoRegion)
argument_list|)
block|{
name|Arg
operator|.
name|wipe
argument_list|()
block|;   }
name|RegionInfoBase
operator|&
name|operator
operator|=
operator|(
name|RegionInfoBase
operator|&&
name|RHS
operator|)
block|{
name|DT
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|DT
argument_list|)
block|;
name|PDT
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|PDT
argument_list|)
block|;
name|DF
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|DF
argument_list|)
block|;
name|TopLevelRegion
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|TopLevelRegion
argument_list|)
block|;
name|BBtoRegion
operator|=
name|std
operator|::
name|move
argument_list|(
name|RHS
operator|.
name|BBtoRegion
argument_list|)
block|;
name|RHS
operator|.
name|wipe
argument_list|()
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|DomTreeT
modifier|*
name|DT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PostDomTreeT
modifier|*
name|PDT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DomFrontierT
modifier|*
name|DF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The top level region.
end_comment

begin_decl_stmt
name|RegionT
modifier|*
name|TopLevelRegion
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Map every BB to the smallest region, that contains BB.
end_comment

begin_decl_stmt
name|BBtoRegionMap
name|BBtoRegion
decl_stmt|;
end_decl_stmt

begin_label
name|protected
label|:
end_label

begin_comment
comment|/// \brief Update refences to a RegionInfoT held by the RegionT managed here
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is a post-move helper. Regions hold references to the owning
end_comment

begin_comment
comment|/// RegionInfo object. After a move these need to be fixed.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|TheRegionT
operator|>
name|void
name|updateRegionTree
argument_list|(
argument|RegionInfoT&RI
argument_list|,
argument|TheRegionT *R
argument_list|)
block|{
if|if
condition|(
operator|!
name|R
condition|)
return|return;
name|R
operator|->
name|RI
operator|=
operator|&
name|RI
expr_stmt|;
end_expr_stmt

begin_for
for|for
control|(
name|auto
operator|&
name|SubR
operator|:
operator|*
name|R
control|)
name|updateRegionTree
argument_list|(
name|RI
argument_list|,
name|SubR
operator|.
name|get
argument_list|()
argument_list|)
expr_stmt|;
end_for

begin_comment
unit|}  private:
comment|/// \brief Wipe this region tree's state without releasing any resources.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is essentially a post-move helper only. It leaves the object in an
end_comment

begin_comment
comment|/// assignable and destroyable state, but otherwise invalid.
end_comment

begin_function
name|void
name|wipe
parameter_list|()
block|{
name|DT
operator|=
name|nullptr
expr_stmt|;
name|PDT
operator|=
name|nullptr
expr_stmt|;
name|DF
operator|=
name|nullptr
expr_stmt|;
name|TopLevelRegion
operator|=
name|nullptr
expr_stmt|;
name|BBtoRegion
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
end_function

begin_comment
comment|// Check whether the entries of BBtoRegion for the BBs of region
end_comment

begin_comment
comment|// SR are correct. Triggers an assertion if not. Calls itself recursively for
end_comment

begin_comment
comment|// subregions.
end_comment

begin_decl_stmt
name|void
name|verifyBBMap
argument_list|(
specifier|const
name|RegionT
operator|*
name|SR
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Returns true if BB is in the dominance frontier of
end_comment

begin_comment
comment|// entry, because it was inherited from exit. In the other case there is an
end_comment

begin_comment
comment|// edge going from entry to BB without passing exit.
end_comment

begin_decl_stmt
name|bool
name|isCommonDomFrontier
argument_list|(
name|BlockT
operator|*
name|BB
argument_list|,
name|BlockT
operator|*
name|entry
argument_list|,
name|BlockT
operator|*
name|exit
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Check if entry and exit surround a valid region, based on
end_comment

begin_comment
comment|// dominance tree and dominance frontier.
end_comment

begin_decl_stmt
name|bool
name|isRegion
argument_list|(
name|BlockT
operator|*
name|entry
argument_list|,
name|BlockT
operator|*
name|exit
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Saves a shortcut pointing from entry to exit.
end_comment

begin_comment
comment|// This function may extend this shortcut if possible.
end_comment

begin_decl_stmt
name|void
name|insertShortCut
argument_list|(
name|BlockT
operator|*
name|entry
argument_list|,
name|BlockT
operator|*
name|exit
argument_list|,
name|BBtoBBMap
operator|*
name|ShortCut
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Returns the next BB that postdominates N, while skipping
end_comment

begin_comment
comment|// all post dominators that cannot finish a canonical region.
end_comment

begin_decl_stmt
name|DomTreeNodeT
modifier|*
name|getNextPostDom
argument_list|(
name|DomTreeNodeT
operator|*
name|N
argument_list|,
name|BBtoBBMap
operator|*
name|ShortCut
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// A region is trivial, if it contains only one BB.
end_comment

begin_decl_stmt
name|bool
name|isTrivialRegion
argument_list|(
name|BlockT
operator|*
name|entry
argument_list|,
name|BlockT
operator|*
name|exit
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Creates a single entry single exit region.
end_comment

begin_function_decl
name|RegionT
modifier|*
name|createRegion
parameter_list|(
name|BlockT
modifier|*
name|entry
parameter_list|,
name|BlockT
modifier|*
name|exit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Detect all regions starting with bb 'entry'.
end_comment

begin_function_decl
name|void
name|findRegionsWithEntry
parameter_list|(
name|BlockT
modifier|*
name|entry
parameter_list|,
name|BBtoBBMap
modifier|*
name|ShortCut
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Detects regions in F.
end_comment

begin_function_decl
name|void
name|scanForRegions
parameter_list|(
name|FuncT
modifier|&
name|F
parameter_list|,
name|BBtoBBMap
modifier|*
name|ShortCut
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Get the top most parent with the same entry block.
end_comment

begin_function_decl
name|RegionT
modifier|*
name|getTopMostParent
parameter_list|(
name|RegionT
modifier|*
name|region
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Build the region hierarchy after all region detected.
end_comment

begin_function_decl
name|void
name|buildRegionsTree
parameter_list|(
name|DomTreeNodeT
modifier|*
name|N
parameter_list|,
name|RegionT
modifier|*
name|region
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Update statistic about created regions.
end_comment

begin_function_decl
name|virtual
name|void
name|updateStatistics
parameter_list|(
name|RegionT
modifier|*
name|R
parameter_list|)
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|// Detect all regions in function and build the region tree.
end_comment

begin_function_decl
name|void
name|calculate
parameter_list|(
name|FuncT
modifier|&
name|F
parameter_list|)
function_decl|;
end_function_decl

begin_label
name|public
label|:
end_label

begin_decl_stmt
specifier|static
name|bool
name|VerifyRegionInfo
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|static
name|typename
name|RegionT
operator|::
name|PrintStyle
name|printStyle
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|NDEBUG
argument_list|)
operator|||
name|defined
argument_list|(
name|LLVM_ENABLE_DUMP
argument_list|)
end_if

begin_expr_stmt
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|void
name|releaseMemory
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// @brief Get the smallest region that contains a BasicBlock.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param BB The basic block.
end_comment

begin_comment
comment|/// @return The smallest region, that contains BB or NULL, if there is no
end_comment

begin_comment
comment|/// region containing BB.
end_comment

begin_decl_stmt
name|RegionT
modifier|*
name|getRegionFor
argument_list|(
name|BlockT
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @brief  Set the smallest region that surrounds a basic block.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param BB The basic block surrounded by a region.
end_comment

begin_comment
comment|/// @param R The smallest region that surrounds BB.
end_comment

begin_function_decl
name|void
name|setRegionFor
parameter_list|(
name|BlockT
modifier|*
name|BB
parameter_list|,
name|RegionT
modifier|*
name|R
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// @brief A shortcut for getRegionFor().
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param BB The basic block.
end_comment

begin_comment
comment|/// @return The smallest region, that contains BB or NULL, if there is no
end_comment

begin_comment
comment|/// region containing BB.
end_comment

begin_decl_stmt
name|RegionT
modifier|*
name|operator
index|[]
argument_list|(
name|BlockT
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @brief Return the exit of the maximal refined region, that starts at a
end_comment

begin_comment
comment|/// BasicBlock.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param BB The BasicBlock the refined region starts.
end_comment

begin_decl_stmt
name|BlockT
modifier|*
name|getMaxRegionExit
argument_list|(
name|BlockT
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @brief Find the smallest region that contains two regions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param A The first region.
end_comment

begin_comment
comment|/// @param B The second region.
end_comment

begin_comment
comment|/// @return The smallest region containing A and B.
end_comment

begin_decl_stmt
name|RegionT
modifier|*
name|getCommonRegion
argument_list|(
name|RegionT
operator|*
name|A
argument_list|,
name|RegionT
operator|*
name|B
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @brief Find the smallest region that contains two basic blocks.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param A The first basic block.
end_comment

begin_comment
comment|/// @param B The second basic block.
end_comment

begin_comment
comment|/// @return The smallest region that contains A and B.
end_comment

begin_decl_stmt
name|RegionT
modifier|*
name|getCommonRegion
argument_list|(
name|BlockT
operator|*
name|A
argument_list|,
name|BlockT
operator|*
name|B
argument_list|)
decl|const
block|{
return|return
name|getCommonRegion
argument_list|(
name|getRegionFor
argument_list|(
name|A
argument_list|)
argument_list|,
name|getRegionFor
argument_list|(
name|B
argument_list|)
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
comment|/// @brief Find the smallest region that contains a set of regions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param Regions A vector of regions.
end_comment

begin_comment
comment|/// @return The smallest region that contains all regions in Regions.
end_comment

begin_decl_stmt
name|RegionT
modifier|*
name|getCommonRegion
argument_list|(
name|SmallVectorImpl
operator|<
name|RegionT
operator|*
operator|>
operator|&
name|Regions
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// @brief Find the smallest region that contains a set of basic blocks.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @param BBs A vector of basic blocks.
end_comment

begin_comment
comment|/// @return The smallest region that contains all basic blocks in BBS.
end_comment

begin_decl_stmt
name|RegionT
modifier|*
name|getCommonRegion
argument_list|(
name|SmallVectorImpl
operator|<
name|BlockT
operator|*
operator|>
operator|&
name|BBs
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|RegionT
operator|*
name|getTopLevelRegion
argument_list|()
specifier|const
block|{
return|return
name|TopLevelRegion
return|;
block|}
end_expr_stmt

begin_comment
comment|/// @brief Clear the Node Cache for all Regions.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// @see Region::clearNodeCache()
end_comment

begin_function
name|void
name|clearNodeCache
parameter_list|()
block|{
if|if
condition|(
name|TopLevelRegion
condition|)
name|TopLevelRegion
operator|->
name|clearNodeCache
argument_list|()
expr_stmt|;
block|}
end_function

begin_expr_stmt
name|void
name|verifyAnalysis
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_decl_stmt
unit|};
name|class
name|Region
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|RegionNode
range|:
name|public
name|RegionNodeBase
operator|<
name|RegionTraits
operator|<
name|Function
operator|>>
block|{
name|public
operator|:
specifier|inline
name|RegionNode
argument_list|(
argument|Region *Parent
argument_list|,
argument|BasicBlock *Entry
argument_list|,
argument|bool isSubRegion = false
argument_list|)
operator|:
name|RegionNodeBase
operator|<
name|RegionTraits
operator|<
name|Function
operator|>>
operator|(
name|Parent
expr|,
name|Entry
expr|,
name|isSubRegion
operator|)
block|{}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|Region
operator|&
name|RN
operator|)
specifier|const
block|{
return|return
name|this
operator|==
name|reinterpret_cast
operator|<
specifier|const
name|RegionNode
operator|*
operator|>
operator|(
operator|&
name|RN
operator|)
return|;
block|}
expr|}
block|;
name|class
name|Region
operator|:
name|public
name|RegionBase
operator|<
name|RegionTraits
operator|<
name|Function
operator|>>
block|{
name|public
operator|:
name|Region
argument_list|(
name|BasicBlock
operator|*
name|Entry
argument_list|,
name|BasicBlock
operator|*
name|Exit
argument_list|,
name|RegionInfo
operator|*
name|RI
argument_list|,
name|DominatorTree
operator|*
name|DT
argument_list|,
name|Region
operator|*
name|Parent
operator|=
name|nullptr
argument_list|)
block|;
operator|~
name|Region
argument_list|()
block|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|RegionNode
operator|&
name|RN
operator|)
specifier|const
block|{
return|return
operator|&
name|RN
operator|==
name|reinterpret_cast
operator|<
specifier|const
name|RegionNode
operator|*
operator|>
operator|(
name|this
operator|)
return|;
block|}
expr|}
block|;
name|class
name|RegionInfo
operator|:
name|public
name|RegionInfoBase
operator|<
name|RegionTraits
operator|<
name|Function
operator|>>
block|{
name|public
operator|:
typedef|typedef
name|RegionInfoBase
operator|<
name|RegionTraits
operator|<
name|Function
operator|>>
name|Base
expr_stmt|;
name|explicit
name|RegionInfo
argument_list|()
block|;
operator|~
name|RegionInfo
argument_list|()
name|override
block|;
name|RegionInfo
argument_list|(
name|RegionInfo
operator|&&
name|Arg
argument_list|)
operator|:
name|Base
argument_list|(
argument|std::move(static_cast<Base&>(Arg))
argument_list|)
block|{
name|updateRegionTree
argument_list|(
operator|*
name|this
argument_list|,
name|TopLevelRegion
argument_list|)
block|;   }
name|RegionInfo
operator|&
name|operator
operator|=
operator|(
name|RegionInfo
operator|&&
name|RHS
operator|)
block|{
name|Base
operator|::
name|operator
operator|=
operator|(
name|std
operator|::
name|move
argument_list|(
name|static_cast
operator|<
name|Base
operator|&
operator|>
operator|(
name|RHS
operator|)
argument_list|)
operator|)
block|;
name|updateRegionTree
argument_list|(
operator|*
name|this
argument_list|,
name|TopLevelRegion
argument_list|)
block|;
return|return
operator|*
name|this
return|;
block|}
comment|/// Handle invalidation explicitly.
name|bool
name|invalidate
argument_list|(
name|Function
operator|&
name|F
argument_list|,
specifier|const
name|PreservedAnalyses
operator|&
name|PA
argument_list|,
name|FunctionAnalysisManager
operator|::
name|Invalidator
operator|&
argument_list|)
block|;
comment|// updateStatistics - Update statistic about created regions.
name|void
name|updateStatistics
argument_list|(
argument|Region *R
argument_list|)
name|final
block|;
name|void
name|recalculate
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|DominatorTree
operator|*
name|DT
argument_list|,
name|PostDominatorTree
operator|*
name|PDT
argument_list|,
name|DominanceFrontier
operator|*
name|DF
argument_list|)
block|;
ifndef|#
directive|ifndef
name|NDEBUG
comment|/// @brief Opens a viewer to show the GraphViz visualization of the regions.
comment|///
comment|/// Useful during debugging as an alternative to dump().
name|void
name|view
argument_list|()
block|;
comment|/// @brief Opens a viewer to show the GraphViz visualization of this region
comment|/// without instructions in the BasicBlocks.
comment|///
comment|/// Useful during debugging as an alternative to dump().
name|void
name|viewOnly
argument_list|()
block|;
endif|#
directive|endif
block|}
block|;
name|class
name|RegionInfoPass
operator|:
name|public
name|FunctionPass
block|{
name|RegionInfo
name|RI
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|explicit
name|RegionInfoPass
argument_list|()
block|;
operator|~
name|RegionInfoPass
argument_list|()
name|override
block|;
name|RegionInfo
operator|&
name|getRegionInfo
argument_list|()
block|{
return|return
name|RI
return|;
block|}
specifier|const
name|RegionInfo
operator|&
name|getRegionInfo
argument_list|()
specifier|const
block|{
return|return
name|RI
return|;
block|}
comment|/// @name FunctionPass interface
comment|//@{
name|bool
name|runOnFunction
argument_list|(
argument|Function&F
argument_list|)
name|override
block|;
name|void
name|releaseMemory
argument_list|()
name|override
block|;
name|void
name|verifyAnalysis
argument_list|()
specifier|const
name|override
block|;
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&AU
argument_list|)
specifier|const
name|override
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|const Module *
argument_list|)
specifier|const
name|override
block|;
name|void
name|dump
argument_list|()
specifier|const
block|;
comment|//@}
block|}
block|;
comment|/// \brief Analysis pass that exposes the \c RegionInfo for a function.
name|class
name|RegionInfoAnalysis
operator|:
name|public
name|AnalysisInfoMixin
operator|<
name|RegionInfoAnalysis
operator|>
block|{
name|friend
name|AnalysisInfoMixin
operator|<
name|RegionInfoAnalysis
operator|>
block|;
specifier|static
name|AnalysisKey
name|Key
block|;
name|public
operator|:
typedef|typedef
name|RegionInfo
name|Result
typedef|;
name|RegionInfo
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Printer pass for the \c RegionInfo.
end_comment

begin_decl_stmt
name|class
name|RegionInfoPrinterPass
range|:
name|public
name|PassInfoMixin
operator|<
name|RegionInfoPrinterPass
operator|>
block|{
name|raw_ostream
operator|&
name|OS
block|;
name|public
operator|:
name|explicit
name|RegionInfoPrinterPass
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
block|;
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Verifier pass for the \c RegionInfo.
end_comment

begin_decl_stmt
name|struct
name|RegionInfoVerifierPass
range|:
name|PassInfoMixin
operator|<
name|RegionInfoVerifierPass
operator|>
block|{
name|PreservedAnalyses
name|run
argument_list|(
name|Function
operator|&
name|F
argument_list|,
name|FunctionAnalysisManager
operator|&
name|AM
argument_list|)
block|; }
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
operator|>
specifier|inline
name|BasicBlock
operator|*
name|RegionNodeBase
operator|<
name|RegionTraits
operator|<
name|Function
operator|>>
operator|::
name|getNodeAs
operator|<
name|BasicBlock
operator|>
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|isSubRegion
argument_list|()
operator|&&
literal|"This is not a BasicBlock RegionNode!"
argument_list|)
block|;
return|return
name|getEntry
argument_list|()
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
operator|>
name|template
operator|<
operator|>
specifier|inline
name|Region
operator|*
name|RegionNodeBase
operator|<
name|RegionTraits
operator|<
name|Function
operator|>>
operator|::
name|getNodeAs
operator|<
name|Region
operator|>
operator|(
operator|)
specifier|const
block|{
name|assert
argument_list|(
name|isSubRegion
argument_list|()
operator|&&
literal|"This is not a subregion RegionNode!"
argument_list|)
block|;
name|auto
name|Unconst
operator|=
name|const_cast
operator|<
name|RegionNodeBase
operator|<
name|RegionTraits
operator|<
name|Function
operator|>>
operator|*
operator|>
operator|(
name|this
operator|)
block|;
return|return
name|reinterpret_cast
operator|<
name|Region
operator|*
operator|>
operator|(
name|Unconst
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|template
operator|<
name|class
name|Tr
operator|>
specifier|inline
name|raw_ostream
operator|&
name|operator
operator|<<
operator|(
name|raw_ostream
operator|&
name|OS
operator|,
specifier|const
name|RegionNodeBase
operator|<
name|Tr
operator|>
operator|&
name|Node
operator|)
block|{
typedef|typedef
name|typename
name|Tr
operator|::
name|BlockT
name|BlockT
expr_stmt|;
end_expr_stmt

begin_typedef
typedef|typedef
name|typename
name|Tr
operator|::
name|RegionT
name|RegionT
expr_stmt|;
end_typedef

begin_if
if|if
condition|(
name|Node
operator|.
name|isSubRegion
argument_list|()
condition|)
return|return
name|OS
operator|<<
name|Node
operator|.
name|template
name|getNodeAs
operator|<
name|RegionT
operator|>
operator|(
operator|)
operator|->
name|getNameStr
argument_list|()
return|;
else|else
return|return
name|OS
operator|<<
name|Node
operator|.
name|template
name|getNodeAs
operator|<
name|BlockT
operator|>
operator|(
operator|)
operator|->
name|getName
argument_list|()
return|;
end_if

begin_expr_stmt
unit|}  extern
name|template
name|class
name|RegionBase
operator|<
name|RegionTraits
operator|<
name|Function
operator|>>
expr_stmt|;
end_expr_stmt

begin_extern
extern|extern template class RegionNodeBase<RegionTraits<Function>>;
end_extern

begin_extern
extern|extern template class RegionInfoBase<RegionTraits<Function>>;
end_extern

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

