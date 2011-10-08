begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- ScheduleDAGInstrs.h - MachineInstr Scheduling --------------*- C++ -*-==//
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
comment|// This file implements the ScheduleDAGInstrs class, which implements
end_comment

begin_comment
comment|// scheduling for a MachineInstr-based dependency graph.
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
name|SCHEDULEDAGINSTRS_H
end_ifndef

begin_define
define|#
directive|define
name|SCHEDULEDAGINSTRS_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineDominators.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineLoopInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/ScheduleDAG.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineLoopInfo
decl_stmt|;
name|class
name|MachineDominatorTree
decl_stmt|;
comment|/// LoopDependencies - This class analyzes loop-oriented register
comment|/// dependencies, which are used to guide scheduling decisions.
comment|/// For example, loop induction variable increments should be
comment|/// scheduled as soon as possible after the variable's last use.
comment|///
name|class
name|LLVM_LIBRARY_VISIBILITY
name|LoopDependencies
block|{
specifier|const
name|MachineLoopInfo
modifier|&
name|MLI
decl_stmt|;
specifier|const
name|MachineDominatorTree
modifier|&
name|MDT
decl_stmt|;
name|public
label|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|unsigned
operator|,
name|std
operator|::
name|pair
operator|<
specifier|const
name|MachineOperand
operator|*
operator|,
name|unsigned
operator|>
expr|>
name|LoopDeps
expr_stmt|;
name|LoopDeps
name|Deps
decl_stmt|;
name|LoopDependencies
argument_list|(
specifier|const
name|MachineLoopInfo
operator|&
name|mli
argument_list|,
specifier|const
name|MachineDominatorTree
operator|&
name|mdt
argument_list|)
operator|:
name|MLI
argument_list|(
name|mli
argument_list|)
operator|,
name|MDT
argument_list|(
argument|mdt
argument_list|)
block|{}
comment|/// VisitLoop - Clear out any previous state and analyze the given loop.
comment|///
name|void
name|VisitLoop
argument_list|(
argument|const MachineLoop *Loop
argument_list|)
block|{
name|Deps
operator|.
name|clear
argument_list|()
block|;
name|MachineBasicBlock
operator|*
name|Header
operator|=
name|Loop
operator|->
name|getHeader
argument_list|()
block|;
name|SmallSet
operator|<
name|unsigned
block|,
literal|8
operator|>
name|LoopLiveIns
block|;
for|for
control|(
name|MachineBasicBlock
operator|::
name|livein_iterator
name|LI
operator|=
name|Header
operator|->
name|livein_begin
argument_list|()
operator|,
name|LE
operator|=
name|Header
operator|->
name|livein_end
argument_list|()
init|;
name|LI
operator|!=
name|LE
condition|;
operator|++
name|LI
control|)
name|LoopLiveIns
operator|.
name|insert
argument_list|(
operator|*
name|LI
argument_list|)
expr_stmt|;
specifier|const
name|MachineDomTreeNode
operator|*
name|Node
operator|=
name|MDT
operator|.
name|getNode
argument_list|(
name|Header
argument_list|)
expr_stmt|;
specifier|const
name|MachineBasicBlock
modifier|*
name|MBB
init|=
name|Node
operator|->
name|getBlock
argument_list|()
decl_stmt|;
name|assert
argument_list|(
name|Loop
operator|->
name|contains
argument_list|(
name|MBB
argument_list|)
operator|&&
literal|"Loop does not contain header!"
argument_list|)
expr_stmt|;
name|VisitRegion
argument_list|(
name|Node
argument_list|,
name|MBB
argument_list|,
name|Loop
argument_list|,
name|LoopLiveIns
argument_list|)
expr_stmt|;
block|}
name|private
label|:
name|void
name|VisitRegion
argument_list|(
specifier|const
name|MachineDomTreeNode
operator|*
name|Node
argument_list|,
specifier|const
name|MachineBasicBlock
operator|*
name|MBB
argument_list|,
specifier|const
name|MachineLoop
operator|*
name|Loop
argument_list|,
specifier|const
name|SmallSet
operator|<
name|unsigned
argument_list|,
literal|8
operator|>
operator|&
name|LoopLiveIns
argument_list|)
block|{
name|unsigned
name|Count
init|=
literal|0
decl_stmt|;
for|for
control|(
name|MachineBasicBlock
operator|::
name|const_iterator
name|I
operator|=
name|MBB
operator|->
name|begin
argument_list|()
operator|,
name|E
operator|=
name|MBB
operator|->
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
specifier|const
name|MachineInstr
modifier|*
name|MI
init|=
name|I
decl_stmt|;
if|if
condition|(
name|MI
operator|->
name|isDebugValue
argument_list|()
condition|)
continue|continue;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|,
name|e
init|=
name|MI
operator|->
name|getNumOperands
argument_list|()
init|;
name|i
operator|!=
name|e
condition|;
operator|++
name|i
control|)
block|{
specifier|const
name|MachineOperand
modifier|&
name|MO
init|=
name|MI
operator|->
name|getOperand
argument_list|(
name|i
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
name|MO
operator|.
name|isReg
argument_list|()
operator|||
operator|!
name|MO
operator|.
name|isUse
argument_list|()
condition|)
continue|continue;
name|unsigned
name|MOReg
init|=
name|MO
operator|.
name|getReg
argument_list|()
decl_stmt|;
if|if
condition|(
name|LoopLiveIns
operator|.
name|count
argument_list|(
name|MOReg
argument_list|)
condition|)
name|Deps
operator|.
name|insert
argument_list|(
name|std
operator|::
name|make_pair
argument_list|(
name|MOReg
argument_list|,
name|std
operator|::
name|make_pair
argument_list|(
operator|&
name|MO
argument_list|,
name|Count
argument_list|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
operator|++
name|Count
expr_stmt|;
comment|// Not every iteration due to dbg_value above.
block|}
specifier|const
name|std
operator|::
name|vector
operator|<
name|MachineDomTreeNode
operator|*
operator|>
operator|&
name|Children
operator|=
name|Node
operator|->
name|getChildren
argument_list|()
expr_stmt|;
for|for
control|(
name|std
operator|::
name|vector
operator|<
name|MachineDomTreeNode
operator|*
operator|>
operator|::
name|const_iterator
name|I
operator|=
name|Children
operator|.
name|begin
argument_list|()
operator|,
name|E
operator|=
name|Children
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
specifier|const
name|MachineDomTreeNode
modifier|*
name|ChildNode
init|=
operator|*
name|I
decl_stmt|;
name|MachineBasicBlock
modifier|*
name|ChildBlock
init|=
name|ChildNode
operator|->
name|getBlock
argument_list|()
decl_stmt|;
if|if
condition|(
name|Loop
operator|->
name|contains
argument_list|(
name|ChildBlock
argument_list|)
condition|)
name|VisitRegion
argument_list|(
name|ChildNode
argument_list|,
name|ChildBlock
argument_list|,
name|Loop
argument_list|,
name|LoopLiveIns
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// ScheduleDAGInstrs - A ScheduleDAG subclass for scheduling lists of
end_comment

begin_comment
comment|/// MachineInstrs.
end_comment

begin_decl_stmt
name|class
name|LLVM_LIBRARY_VISIBILITY
name|ScheduleDAGInstrs
range|:
name|public
name|ScheduleDAG
block|{
specifier|const
name|MachineLoopInfo
operator|&
name|MLI
block|;
specifier|const
name|MachineDominatorTree
operator|&
name|MDT
block|;
specifier|const
name|MachineFrameInfo
operator|*
name|MFI
block|;
specifier|const
name|InstrItineraryData
operator|*
name|InstrItins
block|;
comment|/// Defs, Uses - Remember where defs and uses of each physical register
comment|/// are as we iterate upward through the instructions. This is allocated
comment|/// here instead of inside BuildSchedGraph to avoid the need for it to be
comment|/// initialized and destructed for each block.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
expr|>
name|Defs
block|;
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
expr|>
name|Uses
block|;
comment|/// PendingLoads - Remember where unknown loads are after the most recent
comment|/// unknown store, as we iterate. As with Defs and Uses, this is here
comment|/// to minimize construction/destruction.
name|std
operator|::
name|vector
operator|<
name|SUnit
operator|*
operator|>
name|PendingLoads
block|;
comment|/// LoopRegs - Track which registers are used for loop-carried dependencies.
comment|///
name|LoopDependencies
name|LoopRegs
block|;
comment|/// LoopLiveInRegs - Track which regs are live into a loop, to help guide
comment|/// back-edge-aware scheduling.
comment|///
name|SmallSet
operator|<
name|unsigned
block|,
literal|8
operator|>
name|LoopLiveInRegs
block|;
name|protected
operator|:
comment|/// DbgValues - Remember instruction that preceeds DBG_VALUE.
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|MachineInstr
operator|*
operator|,
name|MachineInstr
operator|*
operator|>
expr|>
name|DbgValueVector
expr_stmt|;
name|DbgValueVector
name|DbgValues
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|MachineInstr
modifier|*
name|FirstDbgValue
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|MachineBasicBlock
operator|::
name|iterator
name|Begin
expr_stmt|;
end_expr_stmt

begin_comment
comment|// The beginning of the range to
end_comment

begin_comment
comment|// be scheduled. The range extends
end_comment

begin_comment
comment|// to InsertPos.
end_comment

begin_decl_stmt
name|unsigned
name|InsertPosIndex
decl_stmt|;
end_decl_stmt

begin_comment
comment|// The index in BB of InsertPos.
end_comment

begin_function_decl
name|explicit
name|ScheduleDAGInstrs
parameter_list|(
name|MachineFunction
modifier|&
name|mf
parameter_list|,
specifier|const
name|MachineLoopInfo
modifier|&
name|mli
parameter_list|,
specifier|const
name|MachineDominatorTree
modifier|&
name|mdt
parameter_list|)
function_decl|;
end_function_decl

begin_expr_stmt
name|virtual
operator|~
name|ScheduleDAGInstrs
argument_list|()
block|{}
comment|/// NewSUnit - Creates a new SUnit and return a ptr to it.
comment|///
name|SUnit
operator|*
name|NewSUnit
argument_list|(
argument|MachineInstr *MI
argument_list|)
block|{
ifndef|#
directive|ifndef
name|NDEBUG
specifier|const
name|SUnit
operator|*
name|Addr
operator|=
name|SUnits
operator|.
name|empty
argument_list|()
operator|?
literal|0
operator|:
operator|&
name|SUnits
index|[
literal|0
index|]
block|;
endif|#
directive|endif
name|SUnits
operator|.
name|push_back
argument_list|(
name|SUnit
argument_list|(
name|MI
argument_list|,
operator|(
name|unsigned
operator|)
name|SUnits
operator|.
name|size
argument_list|()
argument_list|)
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|Addr
operator|==
literal|0
operator|||
name|Addr
operator|==
operator|&
name|SUnits
index|[
literal|0
index|]
operator|)
operator|&&
literal|"SUnits std::vector reallocated on the fly!"
argument_list|)
block|;
name|SUnits
operator|.
name|back
argument_list|()
operator|.
name|OrigNode
operator|=
operator|&
name|SUnits
operator|.
name|back
argument_list|()
block|;
return|return
operator|&
name|SUnits
operator|.
name|back
argument_list|()
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Run - perform scheduling.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|void
name|Run
argument_list|(
name|MachineBasicBlock
operator|*
name|bb
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|begin
argument_list|,
name|MachineBasicBlock
operator|::
name|iterator
name|end
argument_list|,
name|unsigned
name|endindex
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// BuildSchedGraph - Build SUnits from the MachineBasicBlock that we are
end_comment

begin_comment
comment|/// input.
end_comment

begin_function_decl
name|virtual
name|void
name|BuildSchedGraph
parameter_list|(
name|AliasAnalysis
modifier|*
name|AA
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// AddSchedBarrierDeps - Add dependencies from instructions in the current
end_comment

begin_comment
comment|/// list of instructions being scheduled to scheduling barrier. We want to
end_comment

begin_comment
comment|/// make sure instructions which define registers that are either used by
end_comment

begin_comment
comment|/// the terminator or are live-out are properly scheduled. This is
end_comment

begin_comment
comment|/// especially important when the definition latency of the return value(s)
end_comment

begin_comment
comment|/// are too high to be hidden by the branch or when the liveout registers
end_comment

begin_comment
comment|/// used by instructions in the fallthrough block.
end_comment

begin_function_decl
name|void
name|AddSchedBarrierDeps
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// ComputeLatency - Compute node latency.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|virtual
name|void
name|ComputeLatency
parameter_list|(
name|SUnit
modifier|*
name|SU
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// ComputeOperandLatency - Override dependence edge latency using
end_comment

begin_comment
comment|/// operand use/def information
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|virtual
name|void
name|ComputeOperandLatency
argument_list|(
name|SUnit
operator|*
name|Def
argument_list|,
name|SUnit
operator|*
name|Use
argument_list|,
name|SDep
operator|&
name|dep
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_function_decl
name|virtual
name|MachineBasicBlock
modifier|*
name|EmitSchedule
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/// StartBlock - Prepare to perform scheduling in the given block.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|virtual
name|void
name|StartBlock
parameter_list|(
name|MachineBasicBlock
modifier|*
name|BB
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Schedule - Order nodes according to selected style, filling
end_comment

begin_comment
comment|/// in the Sequence member.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|virtual
name|void
name|Schedule
parameter_list|()
init|=
literal|0
function_decl|;
end_function_decl

begin_comment
comment|/// FinishBlock - Clean up after scheduling in the given block.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
name|virtual
name|void
name|FinishBlock
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|virtual
name|void
name|dumpNode
argument_list|(
specifier|const
name|SUnit
operator|*
name|SU
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|virtual
name|std
operator|::
name|string
name|getGraphNodeLabel
argument_list|(
argument|const SUnit *SU
argument_list|)
specifier|const
expr_stmt|;
end_expr_stmt

begin_endif
unit|}; }
endif|#
directive|endif
end_endif

end_unit

