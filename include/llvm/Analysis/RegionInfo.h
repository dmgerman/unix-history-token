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
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_ANALYSIS_REGION_INFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_ANALYSIS_REGION_INFO_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/Dominators.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Analysis/PostDominators.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|Region
decl_stmt|;
name|class
name|RegionInfo
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|Loop
decl_stmt|;
name|class
name|LoopInfo
decl_stmt|;
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
expr_stmt|;
comment|/// @brief A RegionNode represents a subregion or a BasicBlock that is part of a
comment|/// Region.
name|class
name|RegionNode
block|{
comment|// DO NOT IMPLEMENT
name|RegionNode
argument_list|(
specifier|const
name|RegionNode
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
specifier|const
name|RegionNode
modifier|&
name|operator
init|=
operator|(
specifier|const
name|RegionNode
operator|&
operator|)
decl_stmt|;
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
name|BasicBlock
operator|*
operator|,
literal|1
operator|,
name|bool
operator|>
name|entry
expr_stmt|;
name|protected
label|:
comment|/// @brief The parent Region of this RegionNode.
comment|/// @see getParent()
name|Region
modifier|*
name|parent
decl_stmt|;
name|public
label|:
comment|/// @brief Create a RegionNode.
comment|///
comment|/// @param Parent      The parent of this RegionNode.
comment|/// @param Entry       The entry BasicBlock of the RegionNode.  If this
comment|///                    RegionNode represents a BasicBlock, this is the
comment|///                    BasicBlock itself.  If it represents a subregion, this
comment|///                    is the entry BasicBlock of the subregion.
comment|/// @param isSubRegion If this RegionNode represents a SubRegion.
specifier|inline
name|RegionNode
argument_list|(
argument|Region* Parent
argument_list|,
argument|BasicBlock* Entry
argument_list|,
argument|bool isSubRegion =
literal|0
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
comment|/// @brief Get the parent Region of this RegionNode.
comment|///
comment|/// The parent Region is the Region this RegionNode belongs to. If for
comment|/// example a BasicBlock is element of two Regions, there exist two
comment|/// RegionNodes for this BasicBlock. Each with the getParent() function
comment|/// pointing to the Region this RegionNode belongs to.
comment|///
comment|/// @return Get the parent Region of this RegionNode.
specifier|inline
name|Region
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
name|BasicBlock
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
expr_stmt|;
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
block|}
empty_stmt|;
comment|/// Print a RegionNode.
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
name|RegionNode
operator|&
name|Node
operator|)
expr_stmt|;
name|template
operator|<
operator|>
specifier|inline
name|BasicBlock
operator|*
name|RegionNode
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
specifier|inline
name|Region
operator|*
name|RegionNode
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
return|return
name|reinterpret_cast
operator|<
name|Region
operator|*
operator|>
operator|(
name|const_cast
operator|<
name|RegionNode
operator|*
operator|>
operator|(
name|this
operator|)
operator|)
return|;
block|}
comment|//===----------------------------------------------------------------------===//
comment|/// @brief A single entry single exit Region.
comment|///
comment|/// A Region is a connected subgraph of a control flow graph that has exactly
comment|/// two connections to the remaining graph. It can be used to analyze or
comment|/// optimize parts of the control flow graph.
comment|///
comment|/// A<em> simple Region</em> is connected to the remaing graph by just two
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
name|class
name|Region
range|:
name|public
name|RegionNode
block|{
name|friend
name|class
name|RegionInfo
block|;
comment|// DO NOT IMPLEMENT
name|Region
argument_list|(
specifier|const
name|Region
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
specifier|const
name|Region
operator|&
name|operator
operator|=
operator|(
specifier|const
name|Region
operator|&
operator|)
block|;
comment|// Information necessary to manage this Region.
name|RegionInfo
operator|*
name|RI
block|;
name|DominatorTree
operator|*
name|DT
block|;
comment|// The exit BasicBlock of this region.
comment|// (The entry BasicBlock is part of RegionNode)
name|BasicBlock
operator|*
name|exit
block|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|Region
operator|*
operator|>
name|RegionSet
expr_stmt|;
comment|// The subregions of this region.
name|RegionSet
name|children
decl_stmt|;
typedef|typedef
name|std
operator|::
name|map
operator|<
name|BasicBlock
operator|*
operator|,
name|RegionNode
operator|*
operator|>
name|BBNodeMapT
expr_stmt|;
comment|// Save the BasicBlock RegionNodes that are element of this Region.
name|mutable
name|BBNodeMapT
name|BBNodeMap
decl_stmt|;
comment|/// verifyBBInRegion - Check if a BB is in this Region. This check also works
comment|/// if the region is incorrectly built. (EXPENSIVE!)
name|void
name|verifyBBInRegion
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
comment|/// verifyWalk - Walk over all the BBs of the region starting from BB and
comment|/// verify that all reachable basic blocks are elements of the region.
comment|/// (EXPENSIVE!)
name|void
name|verifyWalk
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|,
name|std
operator|::
name|set
operator|<
name|BasicBlock
operator|*
operator|>
operator|*
name|visitedBB
argument_list|)
decl|const
decl_stmt|;
comment|/// verifyRegionNest - Verify if the region and its children are valid
comment|/// regions (EXPENSIVE!)
name|void
name|verifyRegionNest
argument_list|()
specifier|const
expr_stmt|;
name|public
label|:
comment|/// @brief Create a new region.
comment|///
comment|/// @param Entry  The entry basic block of the region.
comment|/// @param Exit   The exit basic block of the region.
comment|/// @param RI     The region info object that is managing this region.
comment|/// @param DT     The dominator tree of the current function.
comment|/// @param Parent The surrounding region or NULL if this is a top level
comment|///               region.
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
literal|0
argument_list|)
expr_stmt|;
comment|/// Delete the Region and all its subregions.
operator|~
name|Region
argument_list|()
expr_stmt|;
comment|/// @brief Get the entry BasicBlock of the Region.
comment|/// @return The entry BasicBlock of the region.
name|BasicBlock
operator|*
name|getEntry
argument_list|()
specifier|const
block|{
return|return
name|RegionNode
operator|::
name|getEntry
argument_list|()
return|;
block|}
comment|/// @brief Get the exit BasicBlock of the Region.
comment|/// @return The exit BasicBlock of the Region, NULL if this is the TopLevel
comment|///         Region.
name|BasicBlock
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
name|Region
operator|*
name|getParent
argument_list|()
specifier|const
block|{
return|return
name|RegionNode
operator|::
name|getParent
argument_list|()
return|;
block|}
comment|/// @brief Get the RegionNode representing the current Region.
comment|/// @return The RegionNode representing the current Region.
name|RegionNode
operator|*
name|getNode
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|RegionNode
operator|*
operator|>
operator|(
name|reinterpret_cast
operator|<
specifier|const
name|RegionNode
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
expr_stmt|;
comment|/// @brief Is this a simple region?
comment|///
comment|/// A region is simple if it has exactly one exit and one entry edge.
comment|///
comment|/// @return True if the Region is simple.
name|bool
name|isSimple
argument_list|()
specifier|const
expr_stmt|;
comment|/// @brief Returns the name of the Region.
comment|/// @return The Name of the Region.
name|std
operator|::
name|string
name|getNameStr
argument_list|()
specifier|const
expr_stmt|;
comment|/// @brief Return the RegionInfo object, that belongs to this Region.
name|RegionInfo
operator|*
name|getRegionInfo
argument_list|()
specifier|const
block|{
return|return
name|RI
return|;
block|}
comment|/// @brief Print the region.
comment|///
comment|/// @param OS The output stream the Region is printed to.
comment|/// @param printTree Print also the tree of subregions.
comment|/// @param level The indentation level used for printing.
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
argument_list|)
decl|const
decl_stmt|;
comment|/// @brief Print the region to stderr.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// @brief Check if the region contains a BasicBlock.
comment|///
comment|/// @param BB The BasicBlock that might be contained in this Region.
comment|/// @return True if the block is contained in the region otherwise false.
name|bool
name|contains
argument_list|(
specifier|const
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
comment|/// @brief Check if the region contains another region.
comment|///
comment|/// @param SubRegion The region that might be contained in this Region.
comment|/// @return True if SubRegion is contained in the region otherwise false.
name|bool
name|contains
argument_list|(
specifier|const
name|Region
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
comment|/// @brief Check if the region contains an Instruction.
comment|///
comment|/// @param Inst The Instruction that might be contained in this region.
comment|/// @return True if the Instruction is contained in the region otherwise false.
name|bool
name|contains
argument_list|(
specifier|const
name|Instruction
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
specifier|const
name|Loop
operator|*
name|L
argument_list|)
decl|const
decl_stmt|;
comment|/// @brief Get the outermost loop in the region that contains a loop.
comment|///
comment|/// Find for a Loop L the outermost loop OuterL that is a parent loop of L
comment|/// and is itself contained in the region.
comment|///
comment|/// @param L The loop the lookup is started.
comment|/// @return The outermost loop in the region, NULL if such a loop does not
comment|///         exist or if the region describes the whole function.
name|Loop
modifier|*
name|outermostLoopInRegion
argument_list|(
name|Loop
operator|*
name|L
argument_list|)
decl|const
decl_stmt|;
comment|/// @brief Get the outermost loop in the region that contains a basic block.
comment|///
comment|/// Find for a basic block BB the outermost loop L that contains BB and is
comment|/// itself contained in the region.
comment|///
comment|/// @param LI A pointer to a LoopInfo analysis.
comment|/// @param BB The basic block surrounded by the loop.
comment|/// @return The outermost loop in the region, NULL if such a loop does not
comment|///         exist or if the region describes the whole function.
name|Loop
modifier|*
name|outermostLoopInRegion
argument_list|(
name|LoopInfo
operator|*
name|LI
argument_list|,
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
comment|/// @brief Get the subregion that starts at a BasicBlock
comment|///
comment|/// @param BB The BasicBlock the subregion should start.
comment|/// @return The Subregion if available, otherwise NULL.
name|Region
modifier|*
name|getSubRegionNode
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
comment|/// @brief Get the RegionNode for a BasicBlock
comment|///
comment|/// @param BB The BasicBlock at which the RegionNode should start.
comment|/// @return If available, the RegionNode that represents the subregion
comment|///         starting at BB. If no subregion starts at BB, the RegionNode
comment|///         representing BB.
name|RegionNode
modifier|*
name|getNode
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
comment|/// @brief Get the BasicBlock RegionNode for a BasicBlock
comment|///
comment|/// @param BB The BasicBlock for which the RegionNode is requested.
comment|/// @return The RegionNode representing the BB.
name|RegionNode
modifier|*
name|getBBNode
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
comment|/// @brief Add a new subregion to this Region.
comment|///
comment|/// @param SubRegion The new subregion that will be added.
name|void
name|addSubRegion
parameter_list|(
name|Region
modifier|*
name|SubRegion
parameter_list|)
function_decl|;
comment|/// @brief Remove a subregion from this Region.
comment|///
comment|/// The subregion is not deleted, as it will probably be inserted into another
comment|/// region.
comment|/// @param SubRegion The SubRegion that will be removed.
name|Region
modifier|*
name|removeSubRegion
parameter_list|(
name|Region
modifier|*
name|SubRegion
parameter_list|)
function_decl|;
comment|/// @brief Move all direct child nodes of this Region to another Region.
comment|///
comment|/// @param To The Region the child nodes will be transfered to.
name|void
name|transferChildrenTo
parameter_list|(
name|Region
modifier|*
name|To
parameter_list|)
function_decl|;
comment|/// @brief Verify if the region is a correct region.
comment|///
comment|/// Check if this is a correctly build Region. This is an expensive check, as
comment|/// the complete CFG of the Region will be walked.
name|void
name|verifyRegion
argument_list|()
specifier|const
expr_stmt|;
comment|/// @brief Clear the cache for BB RegionNodes.
comment|///
comment|/// After calling this function the BasicBlock RegionNodes will be stored at
comment|/// different memory locations. RegionNodes obtained before this function is
comment|/// called are therefore not comparable to RegionNodes abtained afterwords.
name|void
name|clearNodeCache
parameter_list|()
function_decl|;
comment|/// @name Subregion Iterators
comment|///
comment|/// These iterators iterator over all subregions of this Region.
comment|//@{
typedef|typedef
name|RegionSet
operator|::
name|iterator
name|iterator
expr_stmt|;
typedef|typedef
name|RegionSet
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
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
comment|/// These iterators iterate over all BasicBlock RegionNodes that are
comment|/// contained in this Region. The iterator also iterates over BasicBlocks
comment|/// that are elements of a subregion of this Region. It is therefore called a
comment|/// flat iterator.
comment|//@{
typedef|typedef
name|df_iterator
operator|<
name|RegionNode
operator|*
operator|,
name|SmallPtrSet
operator|<
name|RegionNode
operator|*
operator|,
literal|8
operator|>
operator|,
name|false
operator|,
name|GraphTraits
operator|<
name|FlatIt
operator|<
name|RegionNode
operator|*
operator|>
expr|>
operator|>
name|block_iterator
expr_stmt|;
typedef|typedef
name|df_iterator
operator|<
specifier|const
name|RegionNode
operator|*
operator|,
name|SmallPtrSet
operator|<
specifier|const
name|RegionNode
operator|*
operator|,
literal|8
operator|>
operator|,
name|false
operator|,
name|GraphTraits
operator|<
name|FlatIt
operator|<
specifier|const
name|RegionNode
operator|*
operator|>
expr|>
operator|>
name|const_block_iterator
expr_stmt|;
name|block_iterator
name|block_begin
parameter_list|()
function_decl|;
name|block_iterator
name|block_end
parameter_list|()
function_decl|;
name|const_block_iterator
name|block_begin
argument_list|()
specifier|const
expr_stmt|;
name|const_block_iterator
name|block_end
argument_list|()
specifier|const
expr_stmt|;
comment|//@}
comment|/// @name Element Iterators
comment|///
comment|/// These iterators iterate over all BasicBlock and subregion RegionNodes that
comment|/// are direct children of this Region. It does not iterate over any
comment|/// RegionNodes that are also element of a subregion of this Region.
comment|//@{
typedef|typedef
name|df_iterator
operator|<
name|RegionNode
operator|*
operator|,
name|SmallPtrSet
operator|<
name|RegionNode
operator|*
operator|,
literal|8
operator|>
operator|,
name|false
operator|,
name|GraphTraits
operator|<
name|RegionNode
operator|*
operator|>
expr|>
name|element_iterator
expr_stmt|;
typedef|typedef
name|df_iterator
operator|<
specifier|const
name|RegionNode
operator|*
operator|,
name|SmallPtrSet
operator|<
specifier|const
name|RegionNode
operator|*
operator|,
literal|8
operator|>
operator|,
name|false
operator|,
name|GraphTraits
operator|<
specifier|const
name|RegionNode
operator|*
operator|>
expr|>
name|const_element_iterator
expr_stmt|;
name|element_iterator
name|element_begin
parameter_list|()
function_decl|;
name|element_iterator
name|element_end
parameter_list|()
function_decl|;
name|const_element_iterator
name|element_begin
argument_list|()
specifier|const
expr_stmt|;
name|const_element_iterator
name|element_end
argument_list|()
specifier|const
expr_stmt|;
comment|//@}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

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

begin_decl_stmt
name|class
name|RegionInfo
range|:
name|public
name|FunctionPass
block|{
typedef|typedef
name|DenseMap
operator|<
name|BasicBlock
operator|*
operator|,
name|BasicBlock
operator|*
operator|>
name|BBtoBBMap
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|DenseMap
operator|<
name|BasicBlock
operator|*
operator|,
name|Region
operator|*
operator|>
name|BBtoRegionMap
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|SmallPtrSet
operator|<
name|Region
operator|*
operator|,
literal|4
operator|>
name|RegionSet
expr_stmt|;
end_typedef

begin_comment
comment|// DO NOT IMPLEMENT
end_comment

begin_expr_stmt
name|RegionInfo
argument_list|(
specifier|const
name|RegionInfo
operator|&
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// DO NOT IMPLEMENT
end_comment

begin_decl_stmt
specifier|const
name|RegionInfo
modifier|&
name|operator
init|=
operator|(
specifier|const
name|RegionInfo
operator|&
operator|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DominatorTree
modifier|*
name|DT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|PostDominatorTree
modifier|*
name|PDT
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|DominanceFrontier
modifier|*
name|DF
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// The top level region.
end_comment

begin_decl_stmt
name|Region
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

begin_comment
comment|// isCommonDomFrontier - Returns true if BB is in the dominance frontier of
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
name|BasicBlock
operator|*
name|BB
argument_list|,
name|BasicBlock
operator|*
name|entry
argument_list|,
name|BasicBlock
operator|*
name|exit
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// isRegion - Check if entry and exit surround a valid region, based on
end_comment

begin_comment
comment|// dominance tree and dominance frontier.
end_comment

begin_decl_stmt
name|bool
name|isRegion
argument_list|(
name|BasicBlock
operator|*
name|entry
argument_list|,
name|BasicBlock
operator|*
name|exit
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// insertShortCut - Saves a shortcut pointing from entry to exit.
end_comment

begin_comment
comment|// This function may extend this shortcut if possible.
end_comment

begin_decl_stmt
name|void
name|insertShortCut
argument_list|(
name|BasicBlock
operator|*
name|entry
argument_list|,
name|BasicBlock
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
comment|// getNextPostDom - Returns the next BB that postdominates N, while skipping
end_comment

begin_comment
comment|// all post dominators that cannot finish a canonical region.
end_comment

begin_decl_stmt
name|DomTreeNode
modifier|*
name|getNextPostDom
argument_list|(
name|DomTreeNode
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
comment|// isTrivialRegion - A region is trivial, if it contains only one BB.
end_comment

begin_decl_stmt
name|bool
name|isTrivialRegion
argument_list|(
name|BasicBlock
operator|*
name|entry
argument_list|,
name|BasicBlock
operator|*
name|exit
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|// createRegion - Creates a single entry single exit region.
end_comment

begin_function_decl
name|Region
modifier|*
name|createRegion
parameter_list|(
name|BasicBlock
modifier|*
name|entry
parameter_list|,
name|BasicBlock
modifier|*
name|exit
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// findRegionsWithEntry - Detect all regions starting with bb 'entry'.
end_comment

begin_function_decl
name|void
name|findRegionsWithEntry
parameter_list|(
name|BasicBlock
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
comment|// scanForRegions - Detects regions in F.
end_comment

begin_function_decl
name|void
name|scanForRegions
parameter_list|(
name|Function
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
comment|// getTopMostParent - Get the top most parent with the same entry block.
end_comment

begin_function_decl
name|Region
modifier|*
name|getTopMostParent
parameter_list|(
name|Region
modifier|*
name|region
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// buildRegionsTree - build the region hierarchy after all region detected.
end_comment

begin_function_decl
name|void
name|buildRegionsTree
parameter_list|(
name|DomTreeNode
modifier|*
name|N
parameter_list|,
name|Region
modifier|*
name|region
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// Calculate - detecte all regions in function and build the region tree.
end_comment

begin_function_decl
name|void
name|Calculate
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|releaseMemory
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|// updateStatistics - Update statistic about created regions.
end_comment

begin_function_decl
name|void
name|updateStatistics
parameter_list|(
name|Region
modifier|*
name|R
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|// isSimple - Check if a region is a simple region with exactly one entry
end_comment

begin_comment
comment|// edge and exactly one exit edge.
end_comment

begin_decl_stmt
name|bool
name|isSimple
argument_list|(
name|Region
operator|*
name|R
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_decl_stmt
specifier|static
name|char
name|ID
decl_stmt|;
end_decl_stmt

begin_function_decl
name|explicit
name|RegionInfo
parameter_list|()
function_decl|;
end_function_decl

begin_expr_stmt
operator|~
name|RegionInfo
argument_list|()
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// @name FunctionPass interface
end_comment

begin_comment
comment|//@{
end_comment

begin_function_decl
name|virtual
name|bool
name|runOnFunction
parameter_list|(
name|Function
modifier|&
name|F
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
name|virtual
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|virtual
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|,
specifier|const
name|Module
operator|*
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|virtual
name|void
name|verifyAnalysis
argument_list|()
specifier|const
expr_stmt|;
end_expr_stmt

begin_comment
comment|//@}
end_comment

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
name|Region
modifier|*
name|getRegionFor
argument_list|(
name|BasicBlock
operator|*
name|BB
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

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
name|Region
modifier|*
name|operator
index|[]
argument_list|(
name|BasicBlock
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
name|BasicBlock
modifier|*
name|getMaxRegionExit
argument_list|(
name|BasicBlock
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
name|Region
modifier|*
name|getCommonRegion
argument_list|(
name|Region
operator|*
name|A
argument_list|,
name|Region
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
name|Region
modifier|*
name|getCommonRegion
argument_list|(
name|BasicBlock
operator|*
name|A
argument_list|,
name|BasicBlock
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
name|Region
modifier|*
name|getCommonRegion
argument_list|(
name|SmallVectorImpl
operator|<
name|Region
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
name|Region
modifier|*
name|getCommonRegion
argument_list|(
name|SmallVectorImpl
operator|<
name|BasicBlock
operator|*
operator|>
operator|&
name|BBs
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|Region
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
unit|};
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
name|RegionNode
operator|&
name|Node
operator|)
block|{
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
name|getNodeAs
operator|<
name|Region
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
name|getNodeAs
operator|<
name|BasicBlock
operator|>
operator|(
operator|)
operator|->
name|getNameStr
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

