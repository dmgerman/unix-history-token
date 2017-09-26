begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- LiveRegMatrix.h - Track register interference ----------*- C++ -*---===//
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
comment|// The LiveRegMatrix analysis pass keeps track of virtual register interference
end_comment

begin_comment
comment|// along two dimensions: Slot indexes and register units. The matrix is used by
end_comment

begin_comment
comment|// register allocators to ensure that no interfering virtual registers get
end_comment

begin_comment
comment|// assigned to overlapping physical registers.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Register units are defined in MCRegisterInfo.h, they represent the smallest
end_comment

begin_comment
comment|// unit of interference when dealing with overlapping physical registers. The
end_comment

begin_comment
comment|// LiveRegMatrix is represented as a LiveIntervalUnion per register unit. When
end_comment

begin_comment
comment|// a virtual register is assigned to a physical register, the live range for
end_comment

begin_comment
comment|// the virtual register is inserted into the LiveIntervalUnion for each regunit
end_comment

begin_comment
comment|// in the physreg.
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
name|LLVM_CODEGEN_LIVEREGMATRIX_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_LIVEREGMATRIX_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/LiveIntervalUnion.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineFunctionPass.h"
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
name|AnalysisUsage
decl_stmt|;
name|class
name|LiveInterval
decl_stmt|;
name|class
name|LiveIntervals
decl_stmt|;
name|class
name|MachineFunction
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
name|class
name|VirtRegMap
decl_stmt|;
name|class
name|LiveRegMatrix
range|:
name|public
name|MachineFunctionPass
block|{
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
block|;
name|LiveIntervals
operator|*
name|LIS
block|;
name|VirtRegMap
operator|*
name|VRM
block|;
comment|// UserTag changes whenever virtual registers have been modified.
name|unsigned
name|UserTag
operator|=
literal|0
block|;
comment|// The matrix is represented as a LiveIntervalUnion per register unit.
name|LiveIntervalUnion
operator|::
name|Allocator
name|LIUAlloc
block|;
name|LiveIntervalUnion
operator|::
name|Array
name|Matrix
block|;
comment|// Cached queries per register unit.
name|std
operator|::
name|unique_ptr
operator|<
name|LiveIntervalUnion
operator|::
name|Query
index|[]
operator|>
name|Queries
block|;
comment|// Cached register mask interference info.
name|unsigned
name|RegMaskTag
operator|=
literal|0
block|;
name|unsigned
name|RegMaskVirtReg
operator|=
literal|0
block|;
name|BitVector
name|RegMaskUsable
block|;
comment|// MachineFunctionPass boilerplate.
name|void
name|getAnalysisUsage
argument_list|(
argument|AnalysisUsage&
argument_list|)
specifier|const
name|override
block|;
name|bool
name|runOnMachineFunction
argument_list|(
argument|MachineFunction&
argument_list|)
name|override
block|;
name|void
name|releaseMemory
argument_list|()
name|override
block|;
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|LiveRegMatrix
argument_list|()
block|;
comment|//===--------------------------------------------------------------------===//
comment|// High-level interface.
comment|//===--------------------------------------------------------------------===//
comment|//
comment|// Check for interference before assigning virtual registers to physical
comment|// registers.
comment|//
comment|/// Invalidate cached interference queries after modifying virtual register
comment|/// live ranges. Interference checks may return stale information unless
comment|/// caches are invalidated.
name|void
name|invalidateVirtRegs
argument_list|()
block|{
operator|++
name|UserTag
block|; }
expr|enum
name|InterferenceKind
block|{
comment|/// No interference, go ahead and assign.
name|IK_Free
operator|=
literal|0
block|,
comment|/// Virtual register interference. There are interfering virtual registers
comment|/// assigned to PhysReg or its aliases. This interference could be resolved
comment|/// by unassigning those other virtual registers.
name|IK_VirtReg
block|,
comment|/// Register unit interference. A fixed live range is in the way, typically
comment|/// argument registers for a call. This can't be resolved by unassigning
comment|/// other virtual registers.
name|IK_RegUnit
block|,
comment|/// RegMask interference. The live range is crossing an instruction with a
comment|/// regmask operand that doesn't preserve PhysReg. This typically means
comment|/// VirtReg is live across a call, and PhysReg isn't call-preserved.
name|IK_RegMask
block|}
block|;
comment|/// Check for interference before assigning VirtReg to PhysReg.
comment|/// If this function returns IK_Free, it is legal to assign(VirtReg, PhysReg).
comment|/// When there is more than one kind of interference, the InterferenceKind
comment|/// with the highest enum value is returned.
name|InterferenceKind
name|checkInterference
argument_list|(
argument|LiveInterval&VirtReg
argument_list|,
argument|unsigned PhysReg
argument_list|)
block|;
comment|/// Assign VirtReg to PhysReg.
comment|/// This will mark VirtReg's live range as occupied in the LiveRegMatrix and
comment|/// update VirtRegMap. The live range is expected to be available in PhysReg.
name|void
name|assign
argument_list|(
argument|LiveInterval&VirtReg
argument_list|,
argument|unsigned PhysReg
argument_list|)
block|;
comment|/// Unassign VirtReg from its PhysReg.
comment|/// Assuming that VirtReg was previously assigned to a PhysReg, this undoes
comment|/// the assignment and updates VirtRegMap accordingly.
name|void
name|unassign
argument_list|(
name|LiveInterval
operator|&
name|VirtReg
argument_list|)
block|;
comment|/// Returns true if the given \p PhysReg has any live intervals assigned.
name|bool
name|isPhysRegUsed
argument_list|(
argument|unsigned PhysReg
argument_list|)
specifier|const
block|;
comment|//===--------------------------------------------------------------------===//
comment|// Low-level interface.
comment|//===--------------------------------------------------------------------===//
comment|//
comment|// Provide access to the underlying LiveIntervalUnions.
comment|//
comment|/// Check for regmask interference only.
comment|/// Return true if VirtReg crosses a regmask operand that clobbers PhysReg.
comment|/// If PhysReg is null, check if VirtReg crosses any regmask operands.
name|bool
name|checkRegMaskInterference
argument_list|(
argument|LiveInterval&VirtReg
argument_list|,
argument|unsigned PhysReg =
literal|0
argument_list|)
block|;
comment|/// Check for regunit interference only.
comment|/// Return true if VirtReg overlaps a fixed assignment of one of PhysRegs's
comment|/// register units.
name|bool
name|checkRegUnitInterference
argument_list|(
argument|LiveInterval&VirtReg
argument_list|,
argument|unsigned PhysReg
argument_list|)
block|;
comment|/// Query a line of the assigned virtual register matrix directly.
comment|/// Use MCRegUnitIterator to enumerate all regunits in the desired PhysReg.
comment|/// This returns a reference to an internal Query data structure that is only
comment|/// valid until the next query() call.
name|LiveIntervalUnion
operator|::
name|Query
operator|&
name|query
argument_list|(
argument|const LiveRange&LR
argument_list|,
argument|unsigned RegUnit
argument_list|)
block|;
comment|/// Directly access the live interval unions per regunit.
comment|/// This returns an array indexed by the regunit number.
name|LiveIntervalUnion
operator|*
name|getLiveUnions
argument_list|()
block|{
return|return
operator|&
name|Matrix
index|[
literal|0
index|]
return|;
block|}
expr|}
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
comment|// LLVM_CODEGEN_LIVEREGMATRIX_H
end_comment

end_unit

