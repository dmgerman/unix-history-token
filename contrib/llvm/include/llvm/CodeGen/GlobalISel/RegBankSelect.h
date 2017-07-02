begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=- llvm/CodeGen/GlobalISel/RegBankSelect.h - Reg Bank Selector --*- C++ -*-=//
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
comment|/// \file This file describes the interface of the MachineFunctionPass
end_comment

begin_comment
comment|/// responsible for assigning the generic virtual registers to register bank.
end_comment

begin_comment
comment|/// By default, the reg bank selector relies on local decisions to
end_comment

begin_comment
comment|/// assign the register bank. In other words, it looks at one instruction
end_comment

begin_comment
comment|/// at a time to decide where the operand of that instruction should live.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// At higher optimization level, we could imagine that the reg bank selector
end_comment

begin_comment
comment|/// would use more global analysis and do crazier thing like duplicating
end_comment

begin_comment
comment|/// instructions and so on. This is future work.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For now, the pass uses a greedy algorithm to decide where the operand
end_comment

begin_comment
comment|/// of an instruction should live. It asks the target which banks may be
end_comment

begin_comment
comment|/// used for each operand of the instruction and what is the cost. Then,
end_comment

begin_comment
comment|/// it chooses the solution which minimize the cost of the instruction plus
end_comment

begin_comment
comment|/// the cost of any move that may be needed to to the values into the right
end_comment

begin_comment
comment|/// register bank.
end_comment

begin_comment
comment|/// In other words, the cost for an instruction on a register bank RegBank
end_comment

begin_comment
comment|/// is: Cost of I on RegBank plus the sum of the cost for bringing the
end_comment

begin_comment
comment|/// input operands from their current register bank to RegBank.
end_comment

begin_comment
comment|/// Thus, the following formula:
end_comment

begin_comment
comment|/// cost(I, RegBank) = cost(I.Opcode, RegBank) +
end_comment

begin_comment
comment|///    sum(for each arg in I.arguments: costCrossCopy(arg.RegBank, RegBank))
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// E.g., Let say we are assigning the register bank for the instruction
end_comment

begin_comment
comment|/// defining v2.
end_comment

begin_comment
comment|/// v0(A_REGBANK) = ...
end_comment

begin_comment
comment|/// v1(A_REGBANK) = ...
end_comment

begin_comment
comment|/// v2 = G_ADD i32 v0, v1<-- MI
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The target may say it can generate G_ADD i32 on register bank A and B
end_comment

begin_comment
comment|/// with a cost of respectively 5 and 1.
end_comment

begin_comment
comment|/// Then, let say the cost of a cross register bank copies from A to B is 1.
end_comment

begin_comment
comment|/// The reg bank selector would compare the following two costs:
end_comment

begin_comment
comment|/// cost(MI, A_REGBANK) = cost(G_ADD, A_REGBANK) + cost(v0.RegBank, A_REGBANK) +
end_comment

begin_comment
comment|///    cost(v1.RegBank, A_REGBANK)
end_comment

begin_comment
comment|///                     = 5 + cost(A_REGBANK, A_REGBANK) + cost(A_REGBANK,
end_comment

begin_comment
comment|///                                                             A_REGBANK)
end_comment

begin_comment
comment|///                     = 5 + 0 + 0 = 5
end_comment

begin_comment
comment|/// cost(MI, B_REGBANK) = cost(G_ADD, B_REGBANK) + cost(v0.RegBank, B_REGBANK) +
end_comment

begin_comment
comment|///    cost(v1.RegBank, B_REGBANK)
end_comment

begin_comment
comment|///                     = 1 + cost(A_REGBANK, B_REGBANK) + cost(A_REGBANK,
end_comment

begin_comment
comment|///                                                             B_REGBANK)
end_comment

begin_comment
comment|///                     = 1 + 1 + 1 = 3
end_comment

begin_comment
comment|/// Therefore, in this specific example, the reg bank selector would choose
end_comment

begin_comment
comment|/// bank B for MI.
end_comment

begin_comment
comment|/// v0(A_REGBANK) = ...
end_comment

begin_comment
comment|/// v1(A_REGBANK) = ...
end_comment

begin_comment
comment|/// tmp0(B_REGBANK) = COPY v0
end_comment

begin_comment
comment|/// tmp1(B_REGBANK) = COPY v1
end_comment

begin_comment
comment|/// v2(B_REGBANK) = G_ADD i32 tmp0, tmp1
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
name|LLVM_CODEGEN_GLOBALISEL_REGBANKSELECT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GLOBALISEL_REGBANKSELECT_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/GlobalISel/MachineIRBuilder.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/GlobalISel/RegisterBankInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineOptimizationRemarkEmitter.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BlockFrequency
decl_stmt|;
name|class
name|MachineBlockFrequencyInfo
decl_stmt|;
name|class
name|MachineBranchProbabilityInfo
decl_stmt|;
name|class
name|MachineOperand
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|Pass
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
name|class
name|TargetPassConfig
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
comment|/// This pass implements the reg bank selector pass used in the GlobalISel
comment|/// pipeline. At the end of this pass, all register operands have been assigned
name|class
name|RegBankSelect
range|:
name|public
name|MachineFunctionPass
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
comment|/// List of the modes supported by the RegBankSelect pass.
block|enum
name|Mode
block|{
comment|/// Assign the register banks as fast as possible (default).
name|Fast
block|,
comment|/// Greedily minimize the cost of assigning register banks.
comment|/// This should produce code of greater quality, but will
comment|/// require more compile time.
name|Greedy
block|}
block|;
comment|/// Abstract class used to represent an insertion point in a CFG.
comment|/// This class records an insertion point and materializes it on
comment|/// demand.
comment|/// It allows to reason about the frequency of this insertion point,
comment|/// without having to logically materialize it (e.g., on an edge),
comment|/// before we actually need to insert something.
name|class
name|InsertPoint
block|{
name|protected
operator|:
comment|/// Tell if the insert point has already been materialized.
name|bool
name|WasMaterialized
operator|=
name|false
block|;
comment|/// Materialize the insertion point.
comment|///
comment|/// If isSplit() is true, this involves actually splitting
comment|/// the block or edge.
comment|///
comment|/// \post getPointImpl() returns a valid iterator.
comment|/// \post getInsertMBBImpl() returns a valid basic block.
comment|/// \post isSplit() == false ; no more splitting should be required.
name|virtual
name|void
name|materialize
argument_list|()
operator|=
literal|0
block|;
comment|/// Return the materialized insertion basic block.
comment|/// Code will be inserted into that basic block.
comment|///
comment|/// \pre ::materialize has been called.
name|virtual
name|MachineBasicBlock
operator|&
name|getInsertMBBImpl
argument_list|()
operator|=
literal|0
block|;
comment|/// Return the materialized insertion point.
comment|/// Code will be inserted before that point.
comment|///
comment|/// \pre ::materialize has been called.
name|virtual
name|MachineBasicBlock
operator|::
name|iterator
name|getPointImpl
argument_list|()
operator|=
literal|0
block|;
name|public
operator|:
name|virtual
operator|~
name|InsertPoint
argument_list|()
operator|=
expr|default
block|;
comment|/// The first call to this method will cause the splitting to
comment|/// happen if need be, then sub sequent calls just return
comment|/// the iterator to that point. I.e., no more splitting will
comment|/// occur.
comment|///
comment|/// \return The iterator that should be used with
comment|/// MachineBasicBlock::insert. I.e., additional code happens
comment|/// before that point.
name|MachineBasicBlock
operator|::
name|iterator
name|getPoint
argument_list|()
block|{
if|if
condition|(
operator|!
name|WasMaterialized
condition|)
block|{
name|WasMaterialized
operator|=
name|true
expr_stmt|;
name|assert
argument_list|(
name|canMaterialize
argument_list|()
operator|&&
literal|"Impossible to materialize this point"
argument_list|)
expr_stmt|;
name|materialize
argument_list|()
expr_stmt|;
block|}
comment|// When we materialized the point we should have done the splitting.
name|assert
argument_list|(
operator|!
name|isSplit
argument_list|()
operator|&&
literal|"Wrong pre-condition"
argument_list|)
expr_stmt|;
return|return
name|getPointImpl
argument_list|()
return|;
block|}
comment|/// The first call to this method will cause the splitting to
comment|/// happen if need be, then sub sequent calls just return
comment|/// the basic block that contains the insertion point.
comment|/// I.e., no more splitting will occur.
comment|///
comment|/// \return The basic block should be used with
comment|/// MachineBasicBlock::insert and ::getPoint. The new code should
comment|/// happen before that point.
name|MachineBasicBlock
operator|&
name|getInsertMBB
argument_list|()
block|{
if|if
condition|(
operator|!
name|WasMaterialized
condition|)
block|{
name|WasMaterialized
operator|=
name|true
expr_stmt|;
name|assert
argument_list|(
name|canMaterialize
argument_list|()
operator|&&
literal|"Impossible to materialize this point"
argument_list|)
expr_stmt|;
name|materialize
argument_list|()
expr_stmt|;
block|}
comment|// When we materialized the point we should have done the splitting.
name|assert
argument_list|(
operator|!
name|isSplit
argument_list|()
operator|&&
literal|"Wrong pre-condition"
argument_list|)
expr_stmt|;
return|return
name|getInsertMBBImpl
argument_list|()
return|;
block|}
comment|/// Insert \p MI in the just before ::getPoint()
name|MachineBasicBlock
operator|::
name|iterator
name|insert
argument_list|(
argument|MachineInstr&MI
argument_list|)
block|{
return|return
name|getInsertMBB
argument_list|()
operator|.
name|insert
argument_list|(
name|getPoint
argument_list|()
argument_list|,
operator|&
name|MI
argument_list|)
return|;
block|}
comment|/// Does this point involve splitting an edge or block?
comment|/// As soon as ::getPoint is called and thus, the point
comment|/// materialized, the point will not require splitting anymore,
comment|/// i.e., this will return false.
name|virtual
name|bool
name|isSplit
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// Frequency of the insertion point.
comment|/// \p P is used to access the various analysis that will help to
comment|/// get that information, like MachineBlockFrequencyInfo.  If \p P
comment|/// does not contain enough enough to return the actual frequency,
comment|/// this returns 1.
name|virtual
name|uint64_t
name|frequency
argument_list|(
specifier|const
name|Pass
operator|&
name|P
argument_list|)
decl|const
block|{
return|return
literal|1
return|;
block|}
comment|/// Check whether this insertion point can be materialized.
comment|/// As soon as ::getPoint is called and thus, the point materialized
comment|/// calling this method does not make sense.
name|virtual
name|bool
name|canMaterialize
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Insertion point before or after an instruction.
end_comment

begin_decl_stmt
name|class
name|InstrInsertPoint
range|:
name|public
name|InsertPoint
block|{
name|private
operator|:
comment|/// Insertion point.
name|MachineInstr
operator|&
name|Instr
block|;
comment|/// Does the insertion point is before or after Instr.
name|bool
name|Before
block|;
name|void
name|materialize
argument_list|()
name|override
block|;
name|MachineBasicBlock
operator|::
name|iterator
name|getPointImpl
argument_list|()
name|override
block|{
if|if
condition|(
name|Before
condition|)
return|return
name|Instr
return|;
return|return
name|Instr
operator|.
name|getNextNode
argument_list|()
condition|?
operator|*
name|Instr
operator|.
name|getNextNode
argument_list|()
else|:
name|Instr
operator|.
name|getParent
argument_list|()
operator|->
name|end
argument_list|()
return|;
block|}
end_decl_stmt

begin_function
name|MachineBasicBlock
modifier|&
name|getInsertMBBImpl
parameter_list|()
function|override
block|{
return|return
operator|*
name|Instr
operator|.
name|getParent
argument_list|()
return|;
block|}
end_function

begin_label
name|public
label|:
end_label

begin_comment
comment|/// Create an insertion point before (\p Before=true) or after \p Instr.
end_comment

begin_macro
name|InstrInsertPoint
argument_list|(
argument|MachineInstr&Instr
argument_list|,
argument|bool Before = true
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|bool
name|isSplit
argument_list|()
specifier|const
name|override
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|uint64_t
name|frequency
argument_list|(
specifier|const
name|Pass
operator|&
name|P
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Worst case, we need to slice the basic block, but that is still doable.
end_comment

begin_expr_stmt
name|bool
name|canMaterialize
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
end_expr_stmt

begin_comment
unit|};
comment|/// Insertion point at the beginning or end of a basic block.
end_comment

begin_decl_stmt
name|class
name|MBBInsertPoint
range|:
name|public
name|InsertPoint
block|{
name|private
operator|:
comment|/// Insertion point.
name|MachineBasicBlock
operator|&
name|MBB
block|;
comment|/// Does the insertion point is at the beginning or end of MBB.
name|bool
name|Beginning
block|;
name|void
name|materialize
argument_list|()
name|override
block|{
comment|/*Nothing to do to materialize*/
block|}
name|MachineBasicBlock
operator|::
name|iterator
name|getPointImpl
argument_list|()
name|override
block|{
return|return
name|Beginning
operator|?
name|MBB
operator|.
name|begin
argument_list|()
operator|:
name|MBB
operator|.
name|end
argument_list|()
return|;
block|}
name|MachineBasicBlock
operator|&
name|getInsertMBBImpl
argument_list|()
name|override
block|{
return|return
name|MBB
return|;
block|}
name|public
operator|:
name|MBBInsertPoint
argument_list|(
argument|MachineBasicBlock&MBB
argument_list|,
argument|bool Beginning = true
argument_list|)
operator|:
name|InsertPoint
argument_list|()
block|,
name|MBB
argument_list|(
name|MBB
argument_list|)
block|,
name|Beginning
argument_list|(
argument|Beginning
argument_list|)
block|{
comment|// If we try to insert before phis, we should use the insertion
comment|// points on the incoming edges.
name|assert
argument_list|(
operator|(
operator|!
name|Beginning
operator|||
name|MBB
operator|.
name|getFirstNonPHI
argument_list|()
operator|==
name|MBB
operator|.
name|begin
argument_list|()
operator|)
operator|&&
literal|"Invalid beginning point"
argument_list|)
block|;
comment|// If we try to insert after the terminators, we should use the
comment|// points on the outcoming edges.
name|assert
argument_list|(
operator|(
name|Beginning
operator|||
name|MBB
operator|.
name|getFirstTerminator
argument_list|()
operator|==
name|MBB
operator|.
name|end
argument_list|()
operator|)
operator|&&
literal|"Invalid end point"
argument_list|)
block|;     }
name|bool
name|isSplit
argument_list|()
specifier|const
name|override
block|{
return|return
name|false
return|;
block|}
name|uint64_t
name|frequency
argument_list|(
argument|const Pass&P
argument_list|)
specifier|const
name|override
block|;
name|bool
name|canMaterialize
argument_list|()
specifier|const
name|override
block|{
return|return
name|true
return|;
block|}
block|;   }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Insertion point on an edge.
end_comment

begin_decl_stmt
name|class
name|EdgeInsertPoint
range|:
name|public
name|InsertPoint
block|{
name|private
operator|:
comment|/// Source of the edge.
name|MachineBasicBlock
operator|&
name|Src
block|;
comment|/// Destination of the edge.
comment|/// After the materialization is done, this hold the basic block
comment|/// that resulted from the splitting.
name|MachineBasicBlock
operator|*
name|DstOrSplit
block|;
comment|/// P is used to update the analysis passes as applicable.
name|Pass
operator|&
name|P
block|;
name|void
name|materialize
argument_list|()
name|override
block|;
name|MachineBasicBlock
operator|::
name|iterator
name|getPointImpl
argument_list|()
name|override
block|{
comment|// DstOrSplit should be the Split block at this point.
comment|// I.e., it should have one predecessor, Src, and one successor,
comment|// the original Dst.
name|assert
argument_list|(
name|DstOrSplit
operator|&&
name|DstOrSplit
operator|->
name|isPredecessor
argument_list|(
operator|&
name|Src
argument_list|)
operator|&&
name|DstOrSplit
operator|->
name|pred_size
argument_list|()
operator|==
literal|1
operator|&&
name|DstOrSplit
operator|->
name|succ_size
argument_list|()
operator|==
literal|1
operator|&&
literal|"Did not split?!"
argument_list|)
block|;
return|return
name|DstOrSplit
operator|->
name|begin
argument_list|()
return|;
block|}
name|MachineBasicBlock
operator|&
name|getInsertMBBImpl
argument_list|()
name|override
block|{
return|return
operator|*
name|DstOrSplit
return|;
block|}
name|public
operator|:
name|EdgeInsertPoint
argument_list|(
name|MachineBasicBlock
operator|&
name|Src
argument_list|,
name|MachineBasicBlock
operator|&
name|Dst
argument_list|,
name|Pass
operator|&
name|P
argument_list|)
operator|:
name|InsertPoint
argument_list|()
block|,
name|Src
argument_list|(
name|Src
argument_list|)
block|,
name|DstOrSplit
argument_list|(
operator|&
name|Dst
argument_list|)
block|,
name|P
argument_list|(
argument|P
argument_list|)
block|{}
name|bool
name|isSplit
argument_list|()
specifier|const
name|override
block|{
return|return
name|Src
operator|.
name|succ_size
argument_list|()
operator|>
literal|1
operator|&&
name|DstOrSplit
operator|->
name|pred_size
argument_list|()
operator|>
literal|1
return|;
block|}
name|uint64_t
name|frequency
argument_list|(
argument|const Pass&P
argument_list|)
specifier|const
name|override
block|;
name|bool
name|canMaterialize
argument_list|()
specifier|const
name|override
block|;   }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Struct used to represent the placement of a repairing point for
end_comment

begin_comment
comment|/// a given operand.
end_comment

begin_decl_stmt
name|class
name|RepairingPlacement
block|{
name|public
label|:
comment|/// Define the kind of action this repairing needs.
enum|enum
name|RepairingKind
block|{
comment|/// Nothing to repair, just drop this action.
name|None
block|,
comment|/// Reparing code needs to happen before InsertPoints.
name|Insert
block|,
comment|/// (Re)assign the register bank of the operand.
name|Reassign
block|,
comment|/// Mark this repairing placement as impossible.
name|Impossible
block|}
enum|;
comment|/// \name Convenient types for a list of insertion points.
comment|/// @{
name|using
name|InsertionPoints
init|=
name|SmallVector
operator|<
name|std
operator|::
name|unique_ptr
operator|<
name|InsertPoint
operator|>
decl_stmt|, 2>;
name|using
name|insertpt_iterator
init|=
name|InsertionPoints
operator|::
name|iterator
decl_stmt|;
name|using
name|const_insertpt_iterator
init|=
name|InsertionPoints
operator|::
name|const_iterator
decl_stmt|;
comment|/// @}
name|private
label|:
comment|/// Kind of repairing.
name|RepairingKind
name|Kind
decl_stmt|;
comment|/// Index of the operand that will be repaired.
name|unsigned
name|OpIdx
decl_stmt|;
comment|/// Are all the insert points materializeable?
name|bool
name|CanMaterialize
decl_stmt|;
comment|/// Is there any of the insert points needing splitting?
name|bool
name|HasSplit
init|=
name|false
decl_stmt|;
comment|/// Insertion point for the repair code.
comment|/// The repairing code needs to happen just before these points.
name|InsertionPoints
name|InsertPoints
decl_stmt|;
comment|/// Some insertion points may need to update the liveness and such.
name|Pass
modifier|&
name|P
decl_stmt|;
name|public
label|:
comment|/// Create a repairing placement for the \p OpIdx-th operand of
comment|/// \p MI. \p TRI is used to make some checks on the register aliases
comment|/// if the machine operand is a physical register. \p P is used to
comment|/// to update liveness information and such when materializing the
comment|/// points.
name|RepairingPlacement
argument_list|(
argument|MachineInstr&MI
argument_list|,
argument|unsigned OpIdx
argument_list|,
argument|const TargetRegisterInfo&TRI
argument_list|,
argument|Pass&P
argument_list|,
argument|RepairingKind Kind = RepairingKind::Insert
argument_list|)
empty_stmt|;
comment|/// \name Getters.
comment|/// @{
name|RepairingKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|unsigned
name|getOpIdx
argument_list|()
specifier|const
block|{
return|return
name|OpIdx
return|;
block|}
name|bool
name|canMaterialize
argument_list|()
specifier|const
block|{
return|return
name|CanMaterialize
return|;
block|}
name|bool
name|hasSplit
parameter_list|()
block|{
return|return
name|HasSplit
return|;
block|}
comment|/// @}
comment|/// \name Overloaded methods to add an insertion point.
comment|/// @{
comment|/// Add a MBBInsertionPoint to the list of InsertPoints.
name|void
name|addInsertPoint
parameter_list|(
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|,
name|bool
name|Beginning
parameter_list|)
function_decl|;
comment|/// Add a InstrInsertionPoint to the list of InsertPoints.
name|void
name|addInsertPoint
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|,
name|bool
name|Before
parameter_list|)
function_decl|;
comment|/// Add an EdgeInsertionPoint (\p Src, \p Dst) to the list of InsertPoints.
name|void
name|addInsertPoint
parameter_list|(
name|MachineBasicBlock
modifier|&
name|Src
parameter_list|,
name|MachineBasicBlock
modifier|&
name|Dst
parameter_list|)
function_decl|;
comment|/// Add an InsertPoint to the list of insert points.
comment|/// This method takes the ownership of&\p Point.
name|void
name|addInsertPoint
parameter_list|(
name|InsertPoint
modifier|&
name|Point
parameter_list|)
function_decl|;
comment|/// @}
comment|/// \name Accessors related to the insertion points.
comment|/// @{
name|insertpt_iterator
name|begin
parameter_list|()
block|{
return|return
name|InsertPoints
operator|.
name|begin
argument_list|()
return|;
block|}
name|insertpt_iterator
name|end
parameter_list|()
block|{
return|return
name|InsertPoints
operator|.
name|end
argument_list|()
return|;
block|}
name|const_insertpt_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|InsertPoints
operator|.
name|begin
argument_list|()
return|;
block|}
name|const_insertpt_iterator
name|end
argument_list|()
specifier|const
block|{
return|return
name|InsertPoints
operator|.
name|end
argument_list|()
return|;
block|}
name|unsigned
name|getNumInsertPoints
argument_list|()
specifier|const
block|{
return|return
name|InsertPoints
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// @}
comment|/// Change the type of this repairing placement to \p NewKind.
comment|/// It is not possible to switch a repairing placement to the
comment|/// RepairingKind::Insert. There is no fundamental problem with
comment|/// that, but no uses as well, so do not support it for now.
comment|///
comment|/// \pre NewKind != RepairingKind::Insert
comment|/// \post getKind() == NewKind
name|void
name|switchTo
parameter_list|(
name|RepairingKind
name|NewKind
parameter_list|)
block|{
name|assert
argument_list|(
name|NewKind
operator|!=
name|Kind
operator|&&
literal|"Already of the right Kind"
argument_list|)
expr_stmt|;
name|Kind
operator|=
name|NewKind
expr_stmt|;
name|InsertPoints
operator|.
name|clear
argument_list|()
expr_stmt|;
name|CanMaterialize
operator|=
name|NewKind
operator|!=
name|RepairingKind
operator|::
name|Impossible
expr_stmt|;
name|HasSplit
operator|=
name|false
expr_stmt|;
name|assert
argument_list|(
name|NewKind
operator|!=
name|RepairingKind
operator|::
name|Insert
operator|&&
literal|"We would need more MI to switch to Insert"
argument_list|)
expr_stmt|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_label
name|private
label|:
end_label

begin_comment
comment|/// Helper class used to represent the cost for mapping an instruction.
end_comment

begin_comment
comment|/// When mapping an instruction, we may introduce some repairing code.
end_comment

begin_comment
comment|/// In most cases, the repairing code is local to the instruction,
end_comment

begin_comment
comment|/// thus, we can omit the basic block frequency from the cost.
end_comment

begin_comment
comment|/// However, some alternatives may produce non-local cost, e.g., when
end_comment

begin_comment
comment|/// repairing a phi, and thus we then need to scale the local cost
end_comment

begin_comment
comment|/// to the non-local cost. This class does this for us.
end_comment

begin_comment
comment|/// \note: We could simply always scale the cost. The problem is that
end_comment

begin_comment
comment|/// there are higher chances that we saturate the cost easier and end
end_comment

begin_comment
comment|/// up having the same cost for actually different alternatives.
end_comment

begin_comment
comment|/// Another option would be to use APInt everywhere.
end_comment

begin_decl_stmt
name|class
name|MappingCost
block|{
name|private
label|:
comment|/// Cost of the local instructions.
comment|/// This cost is free of basic block frequency.
name|uint64_t
name|LocalCost
init|=
literal|0
decl_stmt|;
comment|/// Cost of the non-local instructions.
comment|/// This cost should include the frequency of the related blocks.
name|uint64_t
name|NonLocalCost
init|=
literal|0
decl_stmt|;
comment|/// Frequency of the block where the local instructions live.
name|uint64_t
name|LocalFreq
decl_stmt|;
name|MappingCost
argument_list|(
argument|uint64_t LocalCost
argument_list|,
argument|uint64_t NonLocalCost
argument_list|,
argument|uint64_t LocalFreq
argument_list|)
block|:
name|LocalCost
argument_list|(
name|LocalCost
argument_list|)
operator|,
name|NonLocalCost
argument_list|(
name|NonLocalCost
argument_list|)
operator|,
name|LocalFreq
argument_list|(
argument|LocalFreq
argument_list|)
block|{}
comment|/// Check if this cost is saturated.
name|bool
name|isSaturated
argument_list|()
specifier|const
expr_stmt|;
name|public
label|:
comment|/// Create a MappingCost assuming that most of the instructions
comment|/// will occur in a basic block with \p LocalFreq frequency.
name|MappingCost
argument_list|(
specifier|const
name|BlockFrequency
operator|&
name|LocalFreq
argument_list|)
expr_stmt|;
comment|/// Add \p Cost to the local cost.
comment|/// \return true if this cost is saturated, false otherwise.
name|bool
name|addLocalCost
parameter_list|(
name|uint64_t
name|Cost
parameter_list|)
function_decl|;
comment|/// Add \p Cost to the non-local cost.
comment|/// Non-local cost should reflect the frequency of their placement.
comment|/// \return true if this cost is saturated, false otherwise.
name|bool
name|addNonLocalCost
parameter_list|(
name|uint64_t
name|Cost
parameter_list|)
function_decl|;
comment|/// Saturate the cost to the maximal representable value.
name|void
name|saturate
parameter_list|()
function_decl|;
comment|/// Return an instance of MappingCost that represents an
comment|/// impossible mapping.
specifier|static
name|MappingCost
name|ImpossibleCost
parameter_list|()
function_decl|;
comment|/// Check if this is less than \p Cost.
name|bool
name|operator
operator|<
operator|(
specifier|const
name|MappingCost
operator|&
name|Cost
operator|)
specifier|const
expr_stmt|;
comment|/// Check if this is equal to \p Cost.
name|bool
name|operator
operator|==
operator|(
specifier|const
name|MappingCost
operator|&
name|Cost
operator|)
specifier|const
expr_stmt|;
comment|/// Check if this is not equal to \p Cost.
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|MappingCost
operator|&
name|Cost
operator|)
specifier|const
block|{
return|return
operator|!
operator|(
operator|*
name|this
operator|==
name|Cost
operator|)
return|;
block|}
comment|/// Check if this is greater than \p Cost.
name|bool
name|operator
operator|>
operator|(
specifier|const
name|MappingCost
operator|&
name|Cost
operator|)
specifier|const
block|{
return|return
operator|*
name|this
operator|!=
name|Cost
operator|&&
name|Cost
operator|<
operator|*
name|this
return|;
block|}
comment|/// Print this on dbgs() stream.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
comment|/// Print this on \p OS;
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// Overload the stream operator for easy debug printing.
name|friend
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
name|MappingCost
operator|&
name|Cost
operator|)
block|{
name|Cost
operator|.
name|print
argument_list|(
name|OS
argument_list|)
block|;
return|return
name|OS
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Interface to the target lowering info related
end_comment

begin_comment
comment|/// to register banks.
end_comment

begin_decl_stmt
specifier|const
name|RegisterBankInfo
modifier|*
name|RBI
init|=
name|nullptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// MRI contains all the register class/bank information that this
end_comment

begin_comment
comment|/// pass uses and updates.
end_comment

begin_decl_stmt
name|MachineRegisterInfo
modifier|*
name|MRI
init|=
name|nullptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Information on the register classes for the current function.
end_comment

begin_decl_stmt
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
init|=
name|nullptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Get the frequency of blocks.
end_comment

begin_comment
comment|/// This is required for non-fast mode.
end_comment

begin_decl_stmt
name|MachineBlockFrequencyInfo
modifier|*
name|MBFI
init|=
name|nullptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Get the frequency of the edges.
end_comment

begin_comment
comment|/// This is required for non-fast mode.
end_comment

begin_decl_stmt
name|MachineBranchProbabilityInfo
modifier|*
name|MBPI
init|=
name|nullptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Current optimization remark emitter. Used to report failures.
end_comment

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|MachineOptimizationRemarkEmitter
operator|>
name|MORE
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Helper class used for every code morphing.
end_comment

begin_decl_stmt
name|MachineIRBuilder
name|MIRBuilder
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Optimization mode of the pass.
end_comment

begin_decl_stmt
name|Mode
name|OptMode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Current target configuration. Controls how the pass handles errors.
end_comment

begin_decl_stmt
specifier|const
name|TargetPassConfig
modifier|*
name|TPC
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Assign the register bank of each operand of \p MI.
end_comment

begin_comment
comment|/// \return True on success, false otherwise.
end_comment

begin_function_decl
name|bool
name|assignInstr
parameter_list|(
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Initialize the field members using \p MF.
end_comment

begin_function_decl
name|void
name|init
parameter_list|(
name|MachineFunction
modifier|&
name|MF
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Check if \p Reg is already assigned what is described by \p ValMapping.
end_comment

begin_comment
comment|/// \p OnlyAssign == true means that \p Reg just needs to be assigned a
end_comment

begin_comment
comment|/// register bank.  I.e., no repairing is necessary to have the
end_comment

begin_comment
comment|/// assignment match.
end_comment

begin_decl_stmt
name|bool
name|assignmentMatch
argument_list|(
name|unsigned
name|Reg
argument_list|,
specifier|const
name|RegisterBankInfo
operator|::
name|ValueMapping
operator|&
name|ValMapping
argument_list|,
name|bool
operator|&
name|OnlyAssign
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Insert repairing code for \p Reg as specified by \p ValMapping.
end_comment

begin_comment
comment|/// The repairing placement is specified by \p RepairPt.
end_comment

begin_comment
comment|/// \p NewVRegs contains all the registers required to remap \p Reg.
end_comment

begin_comment
comment|/// In other words, the number of registers in NewVRegs must be equal
end_comment

begin_comment
comment|/// to ValMapping.BreakDown.size().
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The transformation could be sketched as:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// ... = op Reg
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|/// Becomes
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|///<NewRegs> = COPY or extract Reg
end_comment

begin_comment
comment|/// ... = op Reg
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// and
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// Reg = op ...
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|/// Becomes
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|/// Reg = op ...
end_comment

begin_comment
comment|/// Reg = COPY or build_sequence<NewRegs>
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \pre NewVRegs.size() == ValMapping.BreakDown.size()
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \note The caller is supposed to do the rewriting of op if need be.
end_comment

begin_comment
comment|/// I.e., Reg = op ... =><NewRegs> = NewOp ...
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return True if the repairing worked, false otherwise.
end_comment

begin_decl_stmt
name|bool
name|repairReg
argument_list|(
name|MachineOperand
operator|&
name|MO
argument_list|,
specifier|const
name|RegisterBankInfo
operator|::
name|ValueMapping
operator|&
name|ValMapping
argument_list|,
name|RegBankSelect
operator|::
name|RepairingPlacement
operator|&
name|RepairPt
argument_list|,
specifier|const
name|iterator_range
operator|<
name|SmallVectorImpl
operator|<
name|unsigned
operator|>
operator|::
name|const_iterator
operator|>
operator|&
name|NewVRegs
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Return the cost of the instruction needed to map \p MO to \p ValMapping.
end_comment

begin_comment
comment|/// The cost is free of basic block frequencies.
end_comment

begin_comment
comment|/// \pre MO.isReg()
end_comment

begin_comment
comment|/// \pre MO is assigned to a register bank.
end_comment

begin_comment
comment|/// \pre ValMapping is a valid mapping for MO.
end_comment

begin_decl_stmt
name|uint64_t
name|getRepairCost
argument_list|(
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|,
specifier|const
name|RegisterBankInfo
operator|::
name|ValueMapping
operator|&
name|ValMapping
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Find the best mapping for \p MI from \p PossibleMappings.
end_comment

begin_comment
comment|/// \return a reference on the best mapping in \p PossibleMappings.
end_comment

begin_expr_stmt
specifier|const
name|RegisterBankInfo
operator|::
name|InstructionMapping
operator|&
name|findBestMapping
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|,
name|RegisterBankInfo
operator|::
name|InstructionMappings
operator|&
name|PossibleMappings
argument_list|,
name|SmallVectorImpl
operator|<
name|RepairingPlacement
operator|>
operator|&
name|RepairPts
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Compute the cost of mapping \p MI with \p InstrMapping and
end_comment

begin_comment
comment|/// compute the repairing placement for such mapping in \p
end_comment

begin_comment
comment|/// RepairPts.
end_comment

begin_comment
comment|/// \p BestCost is used to specify when the cost becomes too high
end_comment

begin_comment
comment|/// and thus it is not worth computing the RepairPts.  Moreover if
end_comment

begin_comment
comment|/// \p BestCost == nullptr, the mapping cost is actually not
end_comment

begin_comment
comment|/// computed.
end_comment

begin_decl_stmt
name|MappingCost
name|computeMapping
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|,
specifier|const
name|RegisterBankInfo
operator|::
name|InstructionMapping
operator|&
name|InstrMapping
argument_list|,
name|SmallVectorImpl
operator|<
name|RepairingPlacement
operator|>
operator|&
name|RepairPts
argument_list|,
specifier|const
name|MappingCost
operator|*
name|BestCost
operator|=
name|nullptr
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// When \p RepairPt involves splitting to repair \p MO for the
end_comment

begin_comment
comment|/// given \p ValMapping, try to change the way we repair such that
end_comment

begin_comment
comment|/// the splitting is not required anymore.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \pre \p RepairPt.hasSplit()
end_comment

begin_comment
comment|/// \pre \p MO == MO.getParent()->getOperand(\p RepairPt.getOpIdx())
end_comment

begin_comment
comment|/// \pre \p ValMapping is the mapping of \p MO for MO.getParent()
end_comment

begin_comment
comment|///      that implied \p RepairPt.
end_comment

begin_decl_stmt
name|void
name|tryAvoidingSplit
argument_list|(
name|RegBankSelect
operator|::
name|RepairingPlacement
operator|&
name|RepairPt
argument_list|,
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|,
specifier|const
name|RegisterBankInfo
operator|::
name|ValueMapping
operator|&
name|ValMapping
argument_list|)
decl|const
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Apply \p Mapping to \p MI. \p RepairPts represents the different
end_comment

begin_comment
comment|/// mapping action that need to happen for the mapping to be
end_comment

begin_comment
comment|/// applied.
end_comment

begin_comment
comment|/// \return True if the mapping was applied sucessfully, false otherwise.
end_comment

begin_decl_stmt
name|bool
name|applyMapping
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|,
specifier|const
name|RegisterBankInfo
operator|::
name|InstructionMapping
operator|&
name|InstrMapping
argument_list|,
name|SmallVectorImpl
operator|<
name|RepairingPlacement
operator|>
operator|&
name|RepairPts
argument_list|)
decl_stmt|;
end_decl_stmt

begin_label
name|public
label|:
end_label

begin_comment
comment|/// Create a RegBankSelect pass with the specified \p RunningMode.
end_comment

begin_macro
name|RegBankSelect
argument_list|(
argument|Mode RunningMode = Fast
argument_list|)
end_macro

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|StringRef
name|getPassName
argument_list|()
specifier|const
name|override
block|{
return|return
literal|"RegBankSelect"
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|void
name|getAnalysisUsage
argument_list|(
name|AnalysisUsage
operator|&
name|AU
argument_list|)
decl|const
name|override
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|MachineFunctionProperties
name|getRequiredProperties
argument_list|()
specifier|const
name|override
block|{
return|return
name|MachineFunctionProperties
argument_list|()
operator|.
name|set
argument_list|(
name|MachineFunctionProperties
operator|::
name|Property
operator|::
name|IsSSA
argument_list|)
operator|.
name|set
argument_list|(
name|MachineFunctionProperties
operator|::
name|Property
operator|::
name|Legalized
argument_list|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|MachineFunctionProperties
name|getSetProperties
argument_list|()
specifier|const
name|override
block|{
return|return
name|MachineFunctionProperties
argument_list|()
operator|.
name|set
argument_list|(
name|MachineFunctionProperties
operator|::
name|Property
operator|::
name|RegBankSelected
argument_list|)
return|;
block|}
end_expr_stmt

begin_comment
comment|/// Walk through \p MF and assign a register bank to every virtual register
end_comment

begin_comment
comment|/// that are still mapped to nothing.
end_comment

begin_comment
comment|/// The target needs to provide a RegisterBankInfo and in particular
end_comment

begin_comment
comment|/// override RegisterBankInfo::getInstrMapping.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Simplified algo:
end_comment

begin_comment
comment|/// \code
end_comment

begin_comment
comment|///   RBI = MF.subtarget.getRegBankInfo()
end_comment

begin_comment
comment|///   MIRBuilder.setMF(MF)
end_comment

begin_comment
comment|///   for each bb in MF
end_comment

begin_comment
comment|///     for each inst in bb
end_comment

begin_comment
comment|///       MIRBuilder.setInstr(inst)
end_comment

begin_comment
comment|///       MappingCosts = RBI.getMapping(inst);
end_comment

begin_comment
comment|///       Idx = findIdxOfMinCost(MappingCosts)
end_comment

begin_comment
comment|///       CurRegBank = MappingCosts[Idx].RegBank
end_comment

begin_comment
comment|///       MRI.setRegBank(inst.getOperand(0).getReg(), CurRegBank)
end_comment

begin_comment
comment|///       for each argument in inst
end_comment

begin_comment
comment|///         if (CurRegBank != argument.RegBank)
end_comment

begin_comment
comment|///           ArgReg = argument.getReg()
end_comment

begin_comment
comment|///           Tmp = MRI.createNewVirtual(MRI.getSize(ArgReg), CurRegBank)
end_comment

begin_comment
comment|///           MIRBuilder.buildInstr(COPY, Tmp, ArgReg)
end_comment

begin_comment
comment|///           inst.getOperand(argument.getOperandNo()).setReg(Tmp)
end_comment

begin_comment
comment|/// \endcode
end_comment

begin_decl_stmt
name|bool
name|runOnMachineFunction
argument_list|(
name|MachineFunction
operator|&
name|MF
argument_list|)
name|override
decl_stmt|;
end_decl_stmt

begin_comment
unit|};  }
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_GLOBALISEL_REGBANKSELECT_H
end_comment

end_unit

