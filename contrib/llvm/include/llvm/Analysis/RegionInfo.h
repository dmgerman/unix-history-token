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
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DepthFirstIterator.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/GraphTraits.h"
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
file|"llvm/IR/BasicBlock.h"
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
file|"llvm/Pass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/raw_ostream.h"
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

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<type_traits>
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
name|DominanceFrontier
decl_stmt|;
name|class
name|DominatorTree
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
name|class
name|RegionNode
decl_stmt|;
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
name|using
name|BrokenT
operator|=
name|typename
name|FuncT_
operator|::
name|UnknownRegionTypeError
block|; }
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
name|using
name|FuncT
operator|=
name|Function
block|;
name|using
name|BlockT
operator|=
name|BasicBlock
block|;
name|using
name|RegionT
operator|=
name|Region
block|;
name|using
name|RegionNodeT
operator|=
name|RegionNode
block|;
name|using
name|RegionInfoT
operator|=
name|RegionInfo
block|;
name|using
name|DomTreeT
operator|=
name|DominatorTree
block|;
name|using
name|DomTreeNodeT
operator|=
name|DomTreeNode
block|;
name|using
name|DomFrontierT
operator|=
name|DominanceFrontier
block|;
name|using
name|PostDomTreeT
operator|=
name|PostDominatorTree
block|;
name|using
name|InstT
operator|=
name|Instruction
block|;
name|using
name|LoopT
operator|=
name|Loop
block|;
name|using
name|LoopInfoT
operator|=
name|LoopInfo
block|;
specifier|static
name|unsigned
name|getNumSuccessors
argument_list|(
argument|BasicBlock *BB
argument_list|)
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
expr|}
block|;
comment|/// @brief Marker class to iterate over the elements of a Region in flat mode.
comment|///
comment|/// The class is used to either iterate in Flat mode or by not using it to not
comment|/// iterate in Flat mode.  During a Flat mode iteration all Regions are entered
comment|/// and the iteration returns every BasicBlock.  If the Flat mode is not
comment|/// selected for SubRegions just one RegionNode containing the subregion is
comment|/// returned.
name|template
operator|<
name|class
name|GraphType
operator|>
name|class
name|FlatIt
block|{}
block|;
comment|/// @brief A RegionNode represents a subregion or a BasicBlock that is part of a
comment|/// Region.
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
name|using
name|BlockT
operator|=
name|typename
name|Tr
operator|::
name|BlockT
block|;
name|using
name|RegionT
operator|=
name|typename
name|Tr
operator|::
name|RegionT
block|;
name|private
operator|:
comment|/// This is the entry basic block that starts this region node.  If this is a
comment|/// BasicBlock RegionNode, then entry is just the basic block, that this
comment|/// RegionNode represents.  Otherwise it is the entry of this (Sub)RegionNode.
comment|///
comment|/// In the BBtoRegionNode map of the parent of this node, BB will always map
comment|/// to this node no matter which kind of node this one is.
comment|///
comment|/// The node can hold either a Region or a BasicBlock.
comment|/// Use one bit to save, if this RegionNode is a subregion or BasicBlock
comment|/// RegionNode.
name|PointerIntPair
operator|<
name|BlockT
operator|*
block|,
literal|1
block|,
name|bool
operator|>
name|entry
block|;
comment|/// @brief The parent Region of this RegionNode.
comment|/// @see getParent()
name|RegionT
operator|*
name|parent
block|;
name|protected
operator|:
comment|/// @brief Create a RegionNode.
comment|///
comment|/// @param Parent      The parent of this RegionNode.
comment|/// @param Entry       The entry BasicBlock of the RegionNode.  If this
comment|///                    RegionNode represents a BasicBlock, this is the
comment|///                    BasicBlock itself.  If it represents a subregion, this
comment|///                    is the entry BasicBlock of the subregion.
comment|/// @param isSubRegion If this RegionNode represents a SubRegion.
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
block|,
name|parent
argument_list|(
argument|Parent
argument_list|)
block|{}
name|public
operator|:
name|RegionNodeBase
argument_list|(
specifier|const
name|RegionNodeBase
operator|&
argument_list|)
operator|=
name|delete
block|;
name|RegionNodeBase
operator|&
name|operator
operator|=
operator|(
specifier|const
name|RegionNodeBase
operator|&
operator|)
operator|=
name|delete
block|;
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
comment|/// @brief Get the entry BasicBlock of this RegionNode.
comment|///
comment|/// If this RegionNode represents a BasicBlock this is just the BasicBlock
comment|/// itself, otherwise we return the entry BasicBlock of the Subregion
comment|///
comment|/// @return The entry BasicBlock of this RegionNode.
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
comment|/// @brief Get the content of this RegionNode.
comment|///
comment|/// This can be either a BasicBlock or a subregion. Before calling getNodeAs()
comment|/// check the type of the content with the isSubRegion() function call.
comment|///
comment|/// @return The content of this RegionNode.
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
block|;
comment|/// @brief Is this RegionNode a subregion?
comment|///
comment|/// @return True if it contains a subregion. False if it contains a
comment|///         BasicBlock.
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
expr|}
block|;
comment|//===----------------------------------------------------------------------===//
comment|/// @brief A single entry single exit Region.
comment|///
comment|/// A Region is a connected subgraph of a control flow graph that has exactly
comment|/// two connections to the remaining graph. It can be used to analyze or
comment|/// optimize parts of the control flow graph.
comment|///
comment|/// A<em> simple Region</em> is connected to the remaining graph by just two
comment|/// edges. One edge entering the Region and another one leaving the Region.
comment|///
comment|/// An<em> extended Region</em> (or just Region) is a subgraph that can be
comment|/// transform into a simple Region. The transformation is done by adding
comment|/// BasicBlocks that merge several entry or exit edges so that after the merge
comment|/// just one entry and one exit edge exists.
comment|///
comment|/// The \e Entry of a Region is the first BasicBlock that is passed after
comment|/// entering the Region. It is an element of the Region. The entry BasicBlock
comment|/// dominates all BasicBlocks in the Region.
comment|///
comment|/// The \e Exit of a Region is the first BasicBlock that is passed after
comment|/// leaving the Region. It is not an element of the Region. The exit BasicBlock,
comment|/// postdominates all BasicBlocks in the Region.
comment|///
comment|/// A<em> canonical Region</em> cannot be constructed by combining smaller
comment|/// Regions.
comment|///
comment|/// Region A is the \e parent of Region B, if B is completely contained in A.
comment|///
comment|/// Two canonical Regions either do not intersect at all or one is
comment|/// the parent of the other.
comment|///
comment|/// The<em> Program Structure Tree</em> is a graph (V, E) where V is the set of
comment|/// Regions in the control flow graph and E is the \e parent relation of these
comment|/// Regions.
comment|///
comment|/// Example:
comment|///
comment|/// \verbatim
comment|/// A simple control flow graph, that contains two regions.
comment|///
comment|///        1
comment|///       / |
comment|///      2   |
comment|///     / \   3
comment|///    4   5  |
comment|///    |   |  |
comment|///    6   7  8
comment|///     \  | /
comment|///      \ |/       Region A: 1 -> 9 {1,2,3,4,5,6,7,8}
comment|///        9        Region B: 2 -> 9 {2,4,5,6,7}
comment|/// \endverbatim
comment|///
comment|/// You can obtain more examples by either calling
comment|///
comment|///<tt> "opt -regions -analyze anyprogram.ll"</tt>
comment|/// or
comment|///<tt> "opt -view-regions-only anyprogram.ll"</tt>
comment|///
comment|/// on any LLVM file you are interested in.
comment|///
comment|/// The first call returns a textual representation of the program structure
comment|/// tree, the second one creates a graphical representation using graphviz.
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
name|friend
name|class
name|RegionInfoBase
operator|<
name|Tr
operator|>
block|;
name|using
name|FuncT
operator|=
name|typename
name|Tr
operator|::
name|FuncT
block|;
name|using
name|BlockT
operator|=
name|typename
name|Tr
operator|::
name|BlockT
block|;
name|using
name|RegionInfoT
operator|=
name|typename
name|Tr
operator|::
name|RegionInfoT
block|;
name|using
name|RegionT
operator|=
name|typename
name|Tr
operator|::
name|RegionT
block|;
name|using
name|RegionNodeT
operator|=
name|typename
name|Tr
operator|::
name|RegionNodeT
block|;
name|using
name|DomTreeT
operator|=
name|typename
name|Tr
operator|::
name|DomTreeT
block|;
name|using
name|LoopT
operator|=
name|typename
name|Tr
operator|::
name|LoopT
block|;
name|using
name|LoopInfoT
operator|=
name|typename
name|Tr
operator|::
name|LoopInfoT
block|;
name|using
name|InstT
operator|=
name|typename
name|Tr
operator|::
name|InstT
block|;
name|using
name|BlockTraits
operator|=
name|GraphTraits
operator|<
name|BlockT
operator|*
operator|>
block|;
name|using
name|InvBlockTraits
operator|=
name|GraphTraits
operator|<
name|Inverse
operator|<
name|BlockT
operator|*
operator|>>
block|;
name|using
name|SuccIterTy
operator|=
name|typename
name|BlockTraits
operator|::
name|ChildIteratorType
block|;
name|using
name|PredIterTy
operator|=
name|typename
name|InvBlockTraits
operator|::
name|ChildIteratorType
block|;
comment|// Information necessary to manage this Region.
name|RegionInfoT
operator|*
name|RI
block|;
name|DomTreeT
operator|*
name|DT
block|;
comment|// The exit BasicBlock of this region.
comment|// (The entry BasicBlock is part of RegionNode)
name|BlockT
operator|*
name|exit
block|;
name|using
name|RegionSet
operator|=
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
block|;
comment|// The subregions of this region.
name|RegionSet
name|children
block|;
name|using
name|BBNodeMapT
operator|=
name|std
operator|::
name|map
operator|<
name|BlockT
operator|*
block|,
name|std
operator|::
name|unique_ptr
operator|<
name|RegionNodeT
operator|>>
block|;
comment|// Save the BasicBlock RegionNodes that are element of this Region.
name|mutable
name|BBNodeMapT
name|BBNodeMap
block|;
comment|/// Check if a BB is in this Region. This check also works
comment|/// if the region is incorrectly built. (EXPENSIVE!)
name|void
name|verifyBBInRegion
argument_list|(
argument|BlockT *BB
argument_list|)
specifier|const
block|;
comment|/// Walk over all the BBs of the region starting from BB and
comment|/// verify that all reachable basic blocks are elements of the region.
comment|/// (EXPENSIVE!)
name|void
name|verifyWalk
argument_list|(
argument|BlockT *BB
argument_list|,
argument|std::set<BlockT *> *visitedBB
argument_list|)
specifier|const
block|;
comment|/// Verify if the region and its children are valid regions (EXPENSIVE!)
name|void
name|verifyRegionNest
argument_list|()
specifier|const
block|;
name|public
operator|:
comment|/// @brief Create a new region.
comment|///
comment|/// @param Entry  The entry basic block of the region.
comment|/// @param Exit   The exit basic block of the region.
comment|/// @param RI     The region info object that is managing this region.
comment|/// @param DT     The dominator tree of the current function.
comment|/// @param Parent The surrounding region or NULL if this is a top level
comment|///               region.
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
block|;
name|RegionBase
argument_list|(
specifier|const
name|RegionBase
operator|&
argument_list|)
operator|=
name|delete
block|;
name|RegionBase
operator|&
name|operator
operator|=
operator|(
specifier|const
name|RegionBase
operator|&
operator|)
operator|=
name|delete
block|;
comment|/// Delete the Region and all its subregions.
operator|~
name|RegionBase
argument_list|()
block|;
comment|/// @brief Get the entry BasicBlock of the Region.
comment|/// @return The entry BasicBlock of the region.
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
comment|/// @brief Replace the entry basic block of the region with the new basic
comment|///        block.
comment|///
comment|/// @param BB  The new entry basic block of the region.
name|void
name|replaceEntry
argument_list|(
name|BlockT
operator|*
name|BB
argument_list|)
block|;
comment|/// @brief Replace the exit basic block of the region with the new basic
comment|///        block.
comment|///
comment|/// @param BB  The new exit basic block of the region.
name|void
name|replaceExit
argument_list|(
name|BlockT
operator|*
name|BB
argument_list|)
block|;
comment|/// @brief Recursively replace the entry basic block of the region.
comment|///
comment|/// This function replaces the entry basic block with a new basic block. It
comment|/// also updates all child regions that have the same entry basic block as
comment|/// this region.
comment|///
comment|/// @param NewEntry The new entry basic block.
name|void
name|replaceEntryRecursive
argument_list|(
name|BlockT
operator|*
name|NewEntry
argument_list|)
block|;
comment|/// @brief Recursively replace the exit basic block of the region.
comment|///
comment|/// This function replaces the exit basic block with a new basic block. It
comment|/// also updates all child regions that have the same exit basic block as
comment|/// this region.
comment|///
comment|/// @param NewExit The new exit basic block.
name|void
name|replaceExitRecursive
argument_list|(
name|BlockT
operator|*
name|NewExit
argument_list|)
block|;
comment|/// @brief Get the exit BasicBlock of the Region.
comment|/// @return The exit BasicBlock of the Region, NULL if this is the TopLevel
comment|///         Region.
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
comment|/// @brief Get the parent of the Region.
comment|/// @return The parent of the Region or NULL if this is a top level
comment|///         Region.
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
comment|/// @brief Get the RegionNode representing the current Region.
comment|/// @return The RegionNode representing the current Region.
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
comment|/// @brief Get the nesting level of this Region.
comment|///
comment|/// An toplevel Region has depth 0.
comment|///
comment|/// @return The depth of the region.
name|unsigned
name|getDepth
argument_list|()
specifier|const
block|;
comment|/// @brief Check if a Region is the TopLevel region.
comment|///
comment|/// The toplevel region represents the whole function.
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
comment|/// @brief Return a new (non-canonical) region, that is obtained by joining
comment|///        this region with its predecessors.
comment|///
comment|/// @return A region also starting at getEntry(), but reaching to the next
comment|///         basic block that forms with getEntry() a (non-canonical) region.
comment|///         NULL if such a basic block does not exist.
name|RegionT
operator|*
name|getExpandedRegion
argument_list|()
specifier|const
block|;
comment|/// @brief Return the first block of this region's single entry edge,
comment|///        if existing.
comment|///
comment|/// @return The BasicBlock starting this region's single entry edge,
comment|///         else NULL.
name|BlockT
operator|*
name|getEnteringBlock
argument_list|()
specifier|const
block|;
comment|/// @brief Return the first block of this region's single exit edge,
comment|///        if existing.
comment|///
comment|/// @return The BasicBlock starting this region's single exit edge,
comment|///         else NULL.
name|BlockT
operator|*
name|getExitingBlock
argument_list|()
specifier|const
block|;
comment|/// @brief Is this a simple region?
comment|///
comment|/// A region is simple if it has exactly one exit and one entry edge.
comment|///
comment|/// @return True if the Region is simple.
name|bool
name|isSimple
argument_list|()
specifier|const
block|;
comment|/// @brief Returns the name of the Region.
comment|/// @return The Name of the Region.
name|std
operator|::
name|string
name|getNameStr
argument_list|()
specifier|const
block|;
comment|/// @brief Return the RegionInfo object, that belongs to this Region.
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
comment|/// PrintStyle - Print region in difference ways.
expr|enum
name|PrintStyle
block|{
name|PrintNone
block|,
name|PrintBB
block|,
name|PrintRN
block|}
block|;
comment|/// @brief Print the region.
comment|///
comment|/// @param OS The output stream the Region is printed to.
comment|/// @param printTree Print also the tree of subregions.
comment|/// @param level The indentation level used for printing.
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|,
argument|bool printTree = true
argument_list|,
argument|unsigned level =
literal|0
argument_list|,
argument|PrintStyle Style = PrintNone
argument_list|)
specifier|const
block|;
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
comment|/// @brief Print the region to stderr.
name|void
name|dump
argument_list|()
specifier|const
block|;
endif|#
directive|endif
comment|/// @brief Check if the region contains a BasicBlock.
comment|///
comment|/// @param BB The BasicBlock that might be contained in this Region.
comment|/// @return True if the block is contained in the region otherwise false.
name|bool
name|contains
argument_list|(
argument|const BlockT *BB
argument_list|)
specifier|const
block|;
comment|/// @brief Check if the region contains another region.
comment|///
comment|/// @param SubRegion The region that might be contained in this Region.
comment|/// @return True if SubRegion is contained in the region otherwise false.
name|bool
name|contains
argument_list|(
argument|const RegionT *SubRegion
argument_list|)
specifier|const
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
comment|/// @brief Check if the region contains an Instruction.
comment|///
comment|/// @param Inst The Instruction that might be contained in this region.
comment|/// @return True if the Instruction is contained in the region otherwise
comment|/// false.
name|bool
name|contains
argument_list|(
argument|const InstT *Inst
argument_list|)
specifier|const
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
comment|/// @brief Check if the region contains a loop.
comment|///
comment|/// @param L The loop that might be contained in this region.
comment|/// @return True if the loop is contained in the region otherwise false.
comment|///         In case a NULL pointer is passed to this function the result
comment|///         is false, except for the region that describes the whole function.
comment|///         In that case true is returned.
name|bool
name|contains
argument_list|(
argument|const LoopT *L
argument_list|)
specifier|const
block|;
comment|/// @brief Get the outermost loop in the region that contains a loop.
comment|///
comment|/// Find for a Loop L the outermost loop OuterL that is a parent loop of L
comment|/// and is itself contained in the region.
comment|///
comment|/// @param L The loop the lookup is started.
comment|/// @return The outermost loop in the region, NULL if such a loop does not
comment|///         exist or if the region describes the whole function.
name|LoopT
operator|*
name|outermostLoopInRegion
argument_list|(
argument|LoopT *L
argument_list|)
specifier|const
block|;
comment|/// @brief Get the outermost loop in the region that contains a basic block.
comment|///
comment|/// Find for a basic block BB the outermost loop L that contains BB and is
comment|/// itself contained in the region.
comment|///
comment|/// @param LI A pointer to a LoopInfo analysis.
comment|/// @param BB The basic block surrounded by the loop.
comment|/// @return The outermost loop in the region, NULL if such a loop does not
comment|///         exist or if the region describes the whole function.
name|LoopT
operator|*
name|outermostLoopInRegion
argument_list|(
argument|LoopInfoT *LI
argument_list|,
argument|BlockT *BB
argument_list|)
specifier|const
block|;
comment|/// @brief Get the subregion that starts at a BasicBlock
comment|///
comment|/// @param BB The BasicBlock the subregion should start.
comment|/// @return The Subregion if available, otherwise NULL.
name|RegionT
operator|*
name|getSubRegionNode
argument_list|(
argument|BlockT *BB
argument_list|)
specifier|const
block|;
comment|/// @brief Get the RegionNode for a BasicBlock
comment|///
comment|/// @param BB The BasicBlock at which the RegionNode should start.
comment|/// @return If available, the RegionNode that represents the subregion
comment|///         starting at BB. If no subregion starts at BB, the RegionNode
comment|///         representing BB.
name|RegionNodeT
operator|*
name|getNode
argument_list|(
argument|BlockT *BB
argument_list|)
specifier|const
block|;
comment|/// @brief Get the BasicBlock RegionNode for a BasicBlock
comment|///
comment|/// @param BB The BasicBlock for which the RegionNode is requested.
comment|/// @return The RegionNode representing the BB.
name|RegionNodeT
operator|*
name|getBBNode
argument_list|(
argument|BlockT *BB
argument_list|)
specifier|const
block|;
comment|/// @brief Add a new subregion to this Region.
comment|///
comment|/// @param SubRegion The new subregion that will be added.
comment|/// @param moveChildren Move the children of this region, that are also
comment|///                     contained in SubRegion into SubRegion.
name|void
name|addSubRegion
argument_list|(
argument|RegionT *SubRegion
argument_list|,
argument|bool moveChildren = false
argument_list|)
block|;
comment|/// @brief Remove a subregion from this Region.
comment|///
comment|/// The subregion is not deleted, as it will probably be inserted into another
comment|/// region.
comment|/// @param SubRegion The SubRegion that will be removed.
name|RegionT
operator|*
name|removeSubRegion
argument_list|(
name|RegionT
operator|*
name|SubRegion
argument_list|)
block|;
comment|/// @brief Move all direct child nodes of this Region to another Region.
comment|///
comment|/// @param To The Region the child nodes will be transferred to.
name|void
name|transferChildrenTo
argument_list|(
name|RegionT
operator|*
name|To
argument_list|)
block|;
comment|/// @brief Verify if the region is a correct region.
comment|///
comment|/// Check if this is a correctly build Region. This is an expensive check, as
comment|/// the complete CFG of the Region will be walked.
name|void
name|verifyRegion
argument_list|()
specifier|const
block|;
comment|/// @brief Clear the cache for BB RegionNodes.
comment|///
comment|/// After calling this function the BasicBlock RegionNodes will be stored at
comment|/// different memory locations. RegionNodes obtained before this function is
comment|/// called are therefore not comparable to RegionNodes abtained afterwords.
name|void
name|clearNodeCache
argument_list|()
block|;
comment|/// @name Subregion Iterators
comment|///
comment|/// These iterators iterator over all subregions of this Region.
comment|//@{
name|using
name|iterator
operator|=
name|typename
name|RegionSet
operator|::
name|iterator
block|;
name|using
name|const_iterator
operator|=
name|typename
name|RegionSet
operator|::
name|const_iterator
block|;
name|iterator
name|begin
argument_list|()
block|{
return|return
name|children
operator|.
name|begin
argument_list|()
return|;
block|}
name|iterator
name|end
argument_list|()
block|{
return|return
name|children
operator|.
name|end
argument_list|()
return|;
block|}
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
comment|//@}
comment|/// @name BasicBlock Iterators
comment|///
comment|/// These iterators iterate over all BasicBlocks that are contained in this
comment|/// Region. The iterator also iterates over BasicBlocks that are elements of
comment|/// a subregion of this Region. It is therefore called a flat iterator.
comment|//@{
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
block|,
specifier|const
name|BlockT
block|,
name|BlockT
operator|>
operator|::
name|type
operator|*
operator|>
block|{
name|using
name|super
operator|=
name|df_iterator
operator|<
name|typename
name|std
operator|::
name|conditional
operator|<
name|IsConst
block|,
specifier|const
name|BlockT
block|,
name|BlockT
operator|>
operator|::
name|type
operator|*
operator|>
block|;
name|public
operator|:
name|using
name|Self
operator|=
name|block_iterator_wrapper
operator|<
name|IsConst
operator|>
block|;
name|using
name|value_type
operator|=
name|typename
name|super
operator|::
name|value_type
block|;
comment|// Construct the begin iterator.
name|block_iterator_wrapper
argument_list|(
argument|value_type Entry
argument_list|,
argument|value_type Exit
argument_list|)
operator|:
name|super
argument_list|(
argument|df_begin(Entry)
argument_list|)
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
block|;     }
comment|// Construct the end iterator.
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
expr|}
block|;
name|using
name|block_iterator
operator|=
name|block_iterator_wrapper
operator|<
name|false
operator|>
block|;
name|using
name|const_block_iterator
operator|=
name|block_iterator_wrapper
operator|<
name|true
operator|>
block|;
name|block_iterator
name|block_begin
argument_list|()
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
name|block_iterator
name|block_end
argument_list|()
block|{
return|return
name|block_iterator
argument_list|()
return|;
block|}
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
name|using
name|block_range
operator|=
name|iterator_range
operator|<
name|block_iterator
operator|>
block|;
name|using
name|const_block_range
operator|=
name|iterator_range
operator|<
name|const_block_iterator
operator|>
block|;
comment|/// @brief Returns a range view of the basic blocks in the region.
specifier|inline
name|block_range
name|blocks
argument_list|()
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
comment|/// @brief Returns a range view of the basic blocks in the region.
comment|///
comment|/// This is the 'const' version of the range view.
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
comment|//@}
comment|/// @name Element Iterators
comment|///
comment|/// These iterators iterate over all BasicBlock and subregion RegionNodes that
comment|/// are direct children of this Region. It does not iterate over any
comment|/// RegionNodes that are also element of a subregion of this Region.
comment|//@{
name|using
name|element_iterator
operator|=
name|df_iterator
operator|<
name|RegionNodeT
operator|*
block|,
name|df_iterator_default_set
operator|<
name|RegionNodeT
operator|*
operator|>
block|,
name|false
block|,
name|GraphTraits
operator|<
name|RegionNodeT
operator|*
operator|>>
block|;
name|using
name|const_element_iterator
operator|=
name|df_iterator
operator|<
specifier|const
name|RegionNodeT
operator|*
block|,
name|df_iterator_default_set
operator|<
specifier|const
name|RegionNodeT
operator|*
operator|>
block|,
name|false
block|,
name|GraphTraits
operator|<
specifier|const
name|RegionNodeT
operator|*
operator|>>
block|;
name|element_iterator
name|element_begin
argument_list|()
block|;
name|element_iterator
name|element_end
argument_list|()
block|;
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
name|const_element_iterator
name|element_begin
argument_list|()
specifier|const
block|;
name|const_element_iterator
name|element_end
argument_list|()
specifier|const
block|;
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
comment|//@}
expr|}
block|;
comment|/// Print a RegionNode.
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
block|;
comment|//===----------------------------------------------------------------------===//
comment|/// @brief Analysis that detects all canonical Regions.
comment|///
comment|/// The RegionInfo pass detects all canonical regions in a function. The Regions
comment|/// are connected using the parent relation. This builds a Program Structure
comment|/// Tree.
name|template
operator|<
name|class
name|Tr
operator|>
name|class
name|RegionInfoBase
block|{
name|friend
name|class
name|RegionInfo
block|;
name|friend
name|class
name|MachineRegionInfo
block|;
name|using
name|BlockT
operator|=
name|typename
name|Tr
operator|::
name|BlockT
block|;
name|using
name|FuncT
operator|=
name|typename
name|Tr
operator|::
name|FuncT
block|;
name|using
name|RegionT
operator|=
name|typename
name|Tr
operator|::
name|RegionT
block|;
name|using
name|RegionInfoT
operator|=
name|typename
name|Tr
operator|::
name|RegionInfoT
block|;
name|using
name|DomTreeT
operator|=
name|typename
name|Tr
operator|::
name|DomTreeT
block|;
name|using
name|DomTreeNodeT
operator|=
name|typename
name|Tr
operator|::
name|DomTreeNodeT
block|;
name|using
name|PostDomTreeT
operator|=
name|typename
name|Tr
operator|::
name|PostDomTreeT
block|;
name|using
name|DomFrontierT
operator|=
name|typename
name|Tr
operator|::
name|DomFrontierT
block|;
name|using
name|BlockTraits
operator|=
name|GraphTraits
operator|<
name|BlockT
operator|*
operator|>
block|;
name|using
name|InvBlockTraits
operator|=
name|GraphTraits
operator|<
name|Inverse
operator|<
name|BlockT
operator|*
operator|>>
block|;
name|using
name|SuccIterTy
operator|=
name|typename
name|BlockTraits
operator|::
name|ChildIteratorType
block|;
name|using
name|PredIterTy
operator|=
name|typename
name|InvBlockTraits
operator|::
name|ChildIteratorType
block|;
name|using
name|BBtoBBMap
operator|=
name|DenseMap
operator|<
name|BlockT
operator|*
block|,
name|BlockT
operator|*
operator|>
block|;
name|using
name|BBtoRegionMap
operator|=
name|DenseMap
operator|<
name|BlockT
operator|*
block|,
name|RegionT
operator|*
operator|>
block|;
name|RegionInfoBase
argument_list|()
block|;
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
block|,
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
block|,
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
block|,
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
block|,
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
name|virtual
operator|~
name|RegionInfoBase
argument_list|()
block|;
name|DomTreeT
operator|*
name|DT
block|;
name|PostDomTreeT
operator|*
name|PDT
block|;
name|DomFrontierT
operator|*
name|DF
block|;
comment|/// The top level region.
name|RegionT
operator|*
name|TopLevelRegion
operator|=
name|nullptr
block|;
comment|/// Map every BB to the smallest region, that contains BB.
name|BBtoRegionMap
name|BBtoRegion
block|;
name|protected
operator|:
comment|/// \brief Update refences to a RegionInfoT held by the RegionT managed here
comment|///
comment|/// This is a post-move helper. Regions hold references to the owning
comment|/// RegionInfo object. After a move these need to be fixed.
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
block|;
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
block|}
name|private
operator|:
comment|/// \brief Wipe this region tree's state without releasing any resources.
comment|///
comment|/// This is essentially a post-move helper only. It leaves the object in an
comment|/// assignable and destroyable state, but otherwise invalid.
name|void
name|wipe
argument_list|()
block|{
name|DT
operator|=
name|nullptr
block|;
name|PDT
operator|=
name|nullptr
block|;
name|DF
operator|=
name|nullptr
block|;
name|TopLevelRegion
operator|=
name|nullptr
block|;
name|BBtoRegion
operator|.
name|clear
argument_list|()
block|;   }
comment|// Check whether the entries of BBtoRegion for the BBs of region
comment|// SR are correct. Triggers an assertion if not. Calls itself recursively for
comment|// subregions.
name|void
name|verifyBBMap
argument_list|(
argument|const RegionT *SR
argument_list|)
specifier|const
block|;
comment|// Returns true if BB is in the dominance frontier of
comment|// entry, because it was inherited from exit. In the other case there is an
comment|// edge going from entry to BB without passing exit.
name|bool
name|isCommonDomFrontier
argument_list|(
argument|BlockT *BB
argument_list|,
argument|BlockT *entry
argument_list|,
argument|BlockT *exit
argument_list|)
specifier|const
block|;
comment|// Check if entry and exit surround a valid region, based on
comment|// dominance tree and dominance frontier.
name|bool
name|isRegion
argument_list|(
argument|BlockT *entry
argument_list|,
argument|BlockT *exit
argument_list|)
specifier|const
block|;
comment|// Saves a shortcut pointing from entry to exit.
comment|// This function may extend this shortcut if possible.
name|void
name|insertShortCut
argument_list|(
argument|BlockT *entry
argument_list|,
argument|BlockT *exit
argument_list|,
argument|BBtoBBMap *ShortCut
argument_list|)
specifier|const
block|;
comment|// Returns the next BB that postdominates N, while skipping
comment|// all post dominators that cannot finish a canonical region.
name|DomTreeNodeT
operator|*
name|getNextPostDom
argument_list|(
argument|DomTreeNodeT *N
argument_list|,
argument|BBtoBBMap *ShortCut
argument_list|)
specifier|const
block|;
comment|// A region is trivial, if it contains only one BB.
name|bool
name|isTrivialRegion
argument_list|(
argument|BlockT *entry
argument_list|,
argument|BlockT *exit
argument_list|)
specifier|const
block|;
comment|// Creates a single entry single exit region.
name|RegionT
operator|*
name|createRegion
argument_list|(
name|BlockT
operator|*
name|entry
argument_list|,
name|BlockT
operator|*
name|exit
argument_list|)
block|;
comment|// Detect all regions starting with bb 'entry'.
name|void
name|findRegionsWithEntry
argument_list|(
name|BlockT
operator|*
name|entry
argument_list|,
name|BBtoBBMap
operator|*
name|ShortCut
argument_list|)
block|;
comment|// Detects regions in F.
name|void
name|scanForRegions
argument_list|(
name|FuncT
operator|&
name|F
argument_list|,
name|BBtoBBMap
operator|*
name|ShortCut
argument_list|)
block|;
comment|// Get the top most parent with the same entry block.
name|RegionT
operator|*
name|getTopMostParent
argument_list|(
name|RegionT
operator|*
name|region
argument_list|)
block|;
comment|// Build the region hierarchy after all region detected.
name|void
name|buildRegionsTree
argument_list|(
name|DomTreeNodeT
operator|*
name|N
argument_list|,
name|RegionT
operator|*
name|region
argument_list|)
block|;
comment|// Update statistic about created regions.
name|virtual
name|void
name|updateStatistics
argument_list|(
name|RegionT
operator|*
name|R
argument_list|)
operator|=
literal|0
block|;
comment|// Detect all regions in function and build the region tree.
name|void
name|calculate
argument_list|(
name|FuncT
operator|&
name|F
argument_list|)
block|;
name|public
operator|:
name|RegionInfoBase
argument_list|(
specifier|const
name|RegionInfoBase
operator|&
argument_list|)
operator|=
name|delete
block|;
name|RegionInfoBase
operator|&
name|operator
operator|=
operator|(
specifier|const
name|RegionInfoBase
operator|&
operator|)
operator|=
name|delete
block|;
specifier|static
name|bool
name|VerifyRegionInfo
block|;
specifier|static
name|typename
name|RegionT
operator|::
name|PrintStyle
name|printStyle
block|;
name|void
name|print
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
block|;
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
name|void
name|dump
argument_list|()
specifier|const
block|;
endif|#
directive|endif
name|void
name|releaseMemory
argument_list|()
block|;
comment|/// @brief Get the smallest region that contains a BasicBlock.
comment|///
comment|/// @param BB The basic block.
comment|/// @return The smallest region, that contains BB or NULL, if there is no
comment|/// region containing BB.
name|RegionT
operator|*
name|getRegionFor
argument_list|(
argument|BlockT *BB
argument_list|)
specifier|const
block|;
comment|/// @brief  Set the smallest region that surrounds a basic block.
comment|///
comment|/// @param BB The basic block surrounded by a region.
comment|/// @param R The smallest region that surrounds BB.
name|void
name|setRegionFor
argument_list|(
name|BlockT
operator|*
name|BB
argument_list|,
name|RegionT
operator|*
name|R
argument_list|)
block|;
comment|/// @brief A shortcut for getRegionFor().
comment|///
comment|/// @param BB The basic block.
comment|/// @return The smallest region, that contains BB or NULL, if there is no
comment|/// region containing BB.
name|RegionT
operator|*
name|operator
index|[]
operator|(
name|BlockT
operator|*
name|BB
operator|)
specifier|const
block|;
comment|/// @brief Return the exit of the maximal refined region, that starts at a
comment|/// BasicBlock.
comment|///
comment|/// @param BB The BasicBlock the refined region starts.
name|BlockT
operator|*
name|getMaxRegionExit
argument_list|(
argument|BlockT *BB
argument_list|)
specifier|const
block|;
comment|/// @brief Find the smallest region that contains two regions.
comment|///
comment|/// @param A The first region.
comment|/// @param B The second region.
comment|/// @return The smallest region containing A and B.
name|RegionT
operator|*
name|getCommonRegion
argument_list|(
argument|RegionT *A
argument_list|,
argument|RegionT *B
argument_list|)
specifier|const
block|;
comment|/// @brief Find the smallest region that contains two basic blocks.
comment|///
comment|/// @param A The first basic block.
comment|/// @param B The second basic block.
comment|/// @return The smallest region that contains A and B.
name|RegionT
operator|*
name|getCommonRegion
argument_list|(
argument|BlockT *A
argument_list|,
argument|BlockT *B
argument_list|)
specifier|const
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
comment|/// @brief Find the smallest region that contains a set of regions.
comment|///
comment|/// @param Regions A vector of regions.
comment|/// @return The smallest region that contains all regions in Regions.
name|RegionT
operator|*
name|getCommonRegion
argument_list|(
argument|SmallVectorImpl<RegionT *>&Regions
argument_list|)
specifier|const
block|;
comment|/// @brief Find the smallest region that contains a set of basic blocks.
comment|///
comment|/// @param BBs A vector of basic blocks.
comment|/// @return The smallest region that contains all basic blocks in BBS.
name|RegionT
operator|*
name|getCommonRegion
argument_list|(
argument|SmallVectorImpl<BlockT *>&BBs
argument_list|)
specifier|const
block|;
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
comment|/// @brief Clear the Node Cache for all Regions.
comment|///
comment|/// @see Region::clearNodeCache()
name|void
name|clearNodeCache
argument_list|()
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
name|void
name|verifyAnalysis
argument_list|()
specifier|const
block|; }
block|;
name|class
name|Region
block|;
name|class
name|RegionNode
operator|:
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
operator|,
name|Entry
operator|,
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
name|using
name|Base
operator|=
name|RegionInfoBase
operator|<
name|RegionTraits
operator|<
name|Function
operator|>>
block|;
name|explicit
name|RegionInfo
argument_list|()
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
operator|~
name|RegionInfo
argument_list|()
name|override
block|;
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
name|using
name|Result
operator|=
name|RegionInfo
block|;
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
block|;
comment|/// \brief Printer pass for the \c RegionInfo.
name|class
name|RegionInfoPrinterPass
operator|:
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
block|;
comment|/// \brief Verifier pass for the \c RegionInfo.
block|struct
name|RegionInfoVerifierPass
operator|:
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
block|;
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
name|using
name|BlockT
operator|=
name|typename
name|Tr
operator|::
name|BlockT
block|;
name|using
name|RegionT
operator|=
name|typename
name|Tr
operator|::
name|RegionT
block|;
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
block|}
specifier|extern
name|template
name|class
name|RegionBase
operator|<
name|RegionTraits
operator|<
name|Function
operator|>>
block|;
specifier|extern
name|template
name|class
name|RegionNodeBase
operator|<
name|RegionTraits
operator|<
name|Function
operator|>>
block|;
specifier|extern
name|template
name|class
name|RegionInfoBase
operator|<
name|RegionTraits
operator|<
name|Function
operator|>>
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_ANALYSIS_REGIONINFO_H
end_comment

end_unit

