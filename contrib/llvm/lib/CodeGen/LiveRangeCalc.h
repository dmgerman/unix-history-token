begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- LiveRangeCalc.h - Calculate live ranges ---------------*- C++ -*-===//
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
comment|// The LiveRangeCalc class can be used to compute live ranges from scratch.  It
end_comment

begin_comment
comment|// caches information about values in the CFG to speed up repeated operations
end_comment

begin_comment
comment|// on the same live range.  The cache can be shared by non-overlapping live
end_comment

begin_comment
comment|// ranges.  SplitKit uses that when computing the live range of split products.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// A low-level interface is available to clients that know where a variable is
end_comment

begin_comment
comment|// live, but don't know which value it has as every point.  LiveRangeCalc will
end_comment

begin_comment
comment|// propagate values down the dominator tree, and even insert PHI-defs where
end_comment

begin_comment
comment|// needed.  SplitKit uses this faster interface when possible.
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
name|LLVM_CODEGEN_LIVERANGECALC_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_LIVERANGECALC_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IndexedMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/LiveInterval.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|/// Forward declarations for MachineDominators.h:
name|class
name|MachineDominatorTree
decl_stmt|;
name|template
operator|<
name|class
name|NodeT
operator|>
name|class
name|DomTreeNodeBase
expr_stmt|;
typedef|typedef
name|DomTreeNodeBase
operator|<
name|MachineBasicBlock
operator|>
name|MachineDomTreeNode
expr_stmt|;
name|class
name|LiveRangeCalc
block|{
specifier|const
name|MachineFunction
modifier|*
name|MF
decl_stmt|;
specifier|const
name|MachineRegisterInfo
modifier|*
name|MRI
decl_stmt|;
name|SlotIndexes
modifier|*
name|Indexes
decl_stmt|;
name|MachineDominatorTree
modifier|*
name|DomTree
decl_stmt|;
name|VNInfo
operator|::
name|Allocator
operator|*
name|Alloc
expr_stmt|;
comment|/// Seen - Bit vector of active entries in LiveOut, also used as a visited
comment|/// set by findReachingDefs.  One entry per basic block, indexed by block
comment|/// number.  This is kept as a separate bit vector because it can be cleared
comment|/// quickly when switching live ranges.
name|BitVector
name|Seen
decl_stmt|;
comment|/// LiveOutPair - A value and the block that defined it.  The domtree node is
comment|/// redundant, it can be computed as: MDT[Indexes.getMBBFromIndex(VNI->def)].
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|VNInfo
operator|*
operator|,
name|MachineDomTreeNode
operator|*
operator|>
name|LiveOutPair
expr_stmt|;
comment|/// LiveOutMap - Map basic blocks to the value leaving the block.
typedef|typedef
name|IndexedMap
operator|<
name|LiveOutPair
operator|,
name|MBB2NumberFunctor
operator|>
name|LiveOutMap
expr_stmt|;
comment|/// LiveOut - Map each basic block where a live range is live out to the
comment|/// live-out value and its defining block.
comment|///
comment|/// For every basic block, MBB, one of these conditions shall be true:
comment|///
comment|///  1. !Seen.count(MBB->getNumber())
comment|///     Blocks without a Seen bit are ignored.
comment|///  2. LiveOut[MBB].second.getNode() == MBB
comment|///     The live-out value is defined in MBB.
comment|///  3. forall P in preds(MBB): LiveOut[P] == LiveOut[MBB]
comment|///     The live-out value passses through MBB. All predecessors must carry
comment|///     the same value.
comment|///
comment|/// The domtree node may be null, it can be computed.
comment|///
comment|/// The map can be shared by multiple live ranges as long as no two are
comment|/// live-out of the same block.
name|LiveOutMap
name|LiveOut
decl_stmt|;
comment|/// LiveInBlock - Information about a basic block where a live range is known
comment|/// to be live-in, but the value has not yet been determined.
struct|struct
name|LiveInBlock
block|{
comment|// The live range set that is live-in to this block.  The algorithms can
comment|// handle multiple non-overlapping live ranges simultaneously.
name|LiveRange
modifier|&
name|LR
decl_stmt|;
comment|// DomNode - Dominator tree node for the block.
comment|// Cleared when the final value has been determined and LI has been updated.
name|MachineDomTreeNode
modifier|*
name|DomNode
decl_stmt|;
comment|// Position in block where the live-in range ends, or SlotIndex() if the
comment|// range passes through the block.  When the final value has been
comment|// determined, the range from the block start to Kill will be added to LI.
name|SlotIndex
name|Kill
decl_stmt|;
comment|// Live-in value filled in by updateSSA once it is known.
name|VNInfo
modifier|*
name|Value
decl_stmt|;
name|LiveInBlock
argument_list|(
argument|LiveRange&LR
argument_list|,
argument|MachineDomTreeNode *node
argument_list|,
argument|SlotIndex kill
argument_list|)
block|:
name|LR
argument_list|(
name|LR
argument_list|)
operator|,
name|DomNode
argument_list|(
name|node
argument_list|)
operator|,
name|Kill
argument_list|(
name|kill
argument_list|)
operator|,
name|Value
argument_list|(
literal|0
argument_list|)
block|{}
block|}
struct|;
comment|/// LiveIn - Work list of blocks where the live-in value has yet to be
comment|/// determined.  This list is typically computed by findReachingDefs() and
comment|/// used as a work list by updateSSA().  The low-level interface may also be
comment|/// used to add entries directly.
name|SmallVector
operator|<
name|LiveInBlock
operator|,
literal|16
operator|>
name|LiveIn
expr_stmt|;
comment|/// Assuming that LI is live-in to KillMBB and killed at Kill, find the set
comment|/// of defs that can reach it.
comment|///
comment|/// If only one def can reach Kill, all paths from the def to kill are added
comment|/// to LI, and the function returns true.
comment|///
comment|/// If multiple values can reach Kill, the blocks that need LI to be live in
comment|/// are added to the LiveIn array, and the function returns false.
comment|///
comment|/// PhysReg, when set, is used to verify live-in lists on basic blocks.
name|bool
name|findReachingDefs
parameter_list|(
name|LiveRange
modifier|&
name|LR
parameter_list|,
name|MachineBasicBlock
modifier|&
name|KillMBB
parameter_list|,
name|SlotIndex
name|Kill
parameter_list|,
name|unsigned
name|PhysReg
parameter_list|)
function_decl|;
comment|/// updateSSA - Compute the values that will be live in to all requested
comment|/// blocks in LiveIn.  Create PHI-def values as required to preserve SSA form.
comment|///
comment|/// Every live-in block must be jointly dominated by the added live-out
comment|/// blocks.  No values are read from the live ranges.
name|void
name|updateSSA
parameter_list|()
function_decl|;
comment|/// Add liveness as specified in the LiveIn vector.
name|void
name|updateLiveIns
parameter_list|()
function_decl|;
name|public
label|:
name|LiveRangeCalc
argument_list|()
operator|:
name|MF
argument_list|(
literal|0
argument_list|)
operator|,
name|MRI
argument_list|(
literal|0
argument_list|)
operator|,
name|Indexes
argument_list|(
literal|0
argument_list|)
operator|,
name|DomTree
argument_list|(
literal|0
argument_list|)
operator|,
name|Alloc
argument_list|(
literal|0
argument_list|)
block|{}
comment|//===--------------------------------------------------------------------===//
comment|// High-level interface.
comment|//===--------------------------------------------------------------------===//
comment|//
comment|// Calculate live ranges from scratch.
comment|//
comment|/// reset - Prepare caches for a new set of non-overlapping live ranges.  The
comment|/// caches must be reset before attempting calculations with a live range
comment|/// that may overlap a previously computed live range, and before the first
comment|/// live range in a function.  If live ranges are not known to be
comment|/// non-overlapping, call reset before each.
name|void
name|reset
argument_list|(
specifier|const
name|MachineFunction
operator|*
name|MF
argument_list|,
name|SlotIndexes
operator|*
argument_list|,
name|MachineDominatorTree
operator|*
argument_list|,
name|VNInfo
operator|::
name|Allocator
operator|*
argument_list|)
expr_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// Mid-level interface.
comment|//===--------------------------------------------------------------------===//
comment|//
comment|// Modify existing live ranges.
comment|//
comment|/// extend - Extend the live range of LI to reach Kill.
comment|///
comment|/// The existing values in LI must be live so they jointly dominate Kill.  If
comment|/// Kill is not dominated by a single existing value, PHI-defs are inserted
comment|/// as required to preserve SSA form.  If Kill is known to be dominated by a
comment|/// single existing value, Alloc may be null.
comment|///
comment|/// PhysReg, when set, is used to verify live-in lists on basic blocks.
name|void
name|extend
parameter_list|(
name|LiveRange
modifier|&
name|LR
parameter_list|,
name|SlotIndex
name|Kill
parameter_list|,
name|unsigned
name|PhysReg
init|=
literal|0
parameter_list|)
function_decl|;
comment|/// createDeadDefs - Create a dead def in LI for every def operand of Reg.
comment|/// Each instruction defining Reg gets a new VNInfo with a corresponding
comment|/// minimal live range.
name|void
name|createDeadDefs
parameter_list|(
name|LiveRange
modifier|&
name|LR
parameter_list|,
name|unsigned
name|Reg
parameter_list|)
function_decl|;
comment|/// createDeadDefs - Create a dead def in LI for every def of LI->reg.
name|void
name|createDeadDefs
parameter_list|(
name|LiveInterval
modifier|&
name|LI
parameter_list|)
block|{
name|createDeadDefs
argument_list|(
name|LI
argument_list|,
name|LI
operator|.
name|reg
argument_list|)
expr_stmt|;
block|}
comment|/// extendToUses - Extend the live range of LI to reach all uses of Reg.
comment|///
comment|/// All uses must be jointly dominated by existing liveness.  PHI-defs are
comment|/// inserted as needed to preserve SSA form.
name|void
name|extendToUses
parameter_list|(
name|LiveRange
modifier|&
name|LR
parameter_list|,
name|unsigned
name|Reg
parameter_list|)
function_decl|;
comment|/// extendToUses - Extend the live range of LI to reach all uses of LI->reg.
name|void
name|extendToUses
parameter_list|(
name|LiveInterval
modifier|&
name|LI
parameter_list|)
block|{
name|extendToUses
argument_list|(
name|LI
argument_list|,
name|LI
operator|.
name|reg
argument_list|)
expr_stmt|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Low-level interface.
comment|//===--------------------------------------------------------------------===//
comment|//
comment|// These functions can be used to compute live ranges where the live-in and
comment|// live-out blocks are already known, but the SSA value in each block is
comment|// unknown.
comment|//
comment|// After calling reset(), add known live-out values and known live-in blocks.
comment|// Then call calculateValues() to compute the actual value that is
comment|// live-in to each block, and add liveness to the live ranges.
comment|//
comment|/// setLiveOutValue - Indicate that VNI is live out from MBB.  The
comment|/// calculateValues() function will not add liveness for MBB, the caller
comment|/// should take care of that.
comment|///
comment|/// VNI may be null only if MBB is a live-through block also passed to
comment|/// addLiveInBlock().
name|void
name|setLiveOutValue
parameter_list|(
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|,
name|VNInfo
modifier|*
name|VNI
parameter_list|)
block|{
name|Seen
operator|.
name|set
argument_list|(
name|MBB
operator|->
name|getNumber
argument_list|()
argument_list|)
expr_stmt|;
name|LiveOut
index|[
name|MBB
index|]
operator|=
name|LiveOutPair
argument_list|(
name|VNI
argument_list|,
operator|(
name|MachineDomTreeNode
operator|*
operator|)
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/// addLiveInBlock - Add a block with an unknown live-in value.  This
comment|/// function can only be called once per basic block.  Once the live-in value
comment|/// has been determined, calculateValues() will add liveness to LI.
comment|///
comment|/// @param LR      The live range that is live-in to the block.
comment|/// @param DomNode The domtree node for the block.
comment|/// @param Kill    Index in block where LI is killed.  If the value is
comment|///                live-through, set Kill = SLotIndex() and also call
comment|///                setLiveOutValue(MBB, 0).
name|void
name|addLiveInBlock
parameter_list|(
name|LiveRange
modifier|&
name|LR
parameter_list|,
name|MachineDomTreeNode
modifier|*
name|DomNode
parameter_list|,
name|SlotIndex
name|Kill
init|=
name|SlotIndex
argument_list|()
parameter_list|)
block|{
name|LiveIn
operator|.
name|push_back
argument_list|(
name|LiveInBlock
argument_list|(
name|LR
argument_list|,
name|DomNode
argument_list|,
name|Kill
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|/// calculateValues - Calculate the value that will be live-in to each block
comment|/// added with addLiveInBlock.  Add PHI-def values as needed to preserve SSA
comment|/// form.  Add liveness to all live-in blocks up to the Kill point, or the
comment|/// whole block for live-through blocks.
comment|///
comment|/// Every predecessor of a live-in block must have been given a value with
comment|/// setLiveOutValue, the value may be null for live-trough blocks.
name|void
name|calculateValues
parameter_list|()
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

