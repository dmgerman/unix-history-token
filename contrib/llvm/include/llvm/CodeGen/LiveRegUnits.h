begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/CodeGen/LiveRegUnits.h - Register Unit Set ----------*- C++ -*-===//
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
comment|/// \file
end_comment

begin_comment
comment|/// A set of register units. It is intended for register liveness tracking.
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
name|LLVM_CODEGEN_LIVEREGUNITS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_LIVEREGUNITS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/BitVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/LaneBitmask.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineBasicBlock
decl_stmt|;
comment|/// A set of register units used to track register liveness.
name|class
name|LiveRegUnits
block|{
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
init|=
name|nullptr
decl_stmt|;
name|BitVector
name|Units
decl_stmt|;
name|public
label|:
comment|/// Constructs a new empty LiveRegUnits set.
name|LiveRegUnits
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Constructs and initialize an empty LiveRegUnits set.
name|LiveRegUnits
argument_list|(
argument|const TargetRegisterInfo&TRI
argument_list|)
block|{
name|init
argument_list|(
name|TRI
argument_list|)
expr_stmt|;
block|}
comment|/// Initialize and clear the set.
name|void
name|init
parameter_list|(
specifier|const
name|TargetRegisterInfo
modifier|&
name|TRI
parameter_list|)
block|{
name|this
operator|->
name|TRI
operator|=
operator|&
name|TRI
expr_stmt|;
name|Units
operator|.
name|reset
argument_list|()
expr_stmt|;
name|Units
operator|.
name|resize
argument_list|(
name|TRI
operator|.
name|getNumRegUnits
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/// Clears the set.
name|void
name|clear
parameter_list|()
block|{
name|Units
operator|.
name|reset
argument_list|()
expr_stmt|;
block|}
comment|/// Returns true if the set is empty.
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|Units
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// Adds register units covered by physical register \p Reg.
name|void
name|addReg
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
for|for
control|(
name|MCRegUnitIterator
name|Unit
argument_list|(
name|Reg
argument_list|,
name|TRI
argument_list|)
init|;
name|Unit
operator|.
name|isValid
argument_list|()
condition|;
operator|++
name|Unit
control|)
name|Units
operator|.
name|set
argument_list|(
operator|*
name|Unit
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Adds register units covered by physical register \p Reg that are
comment|/// part of the lanemask \p Mask.
name|void
name|addRegMasked
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
name|LaneBitmask
name|Mask
parameter_list|)
block|{
for|for
control|(
name|MCRegUnitMaskIterator
name|Unit
argument_list|(
name|Reg
argument_list|,
name|TRI
argument_list|)
init|;
name|Unit
operator|.
name|isValid
argument_list|()
condition|;
operator|++
name|Unit
control|)
block|{
name|LaneBitmask
name|UnitMask
init|=
operator|(
operator|*
name|Unit
operator|)
operator|.
name|second
decl_stmt|;
if|if
condition|(
name|UnitMask
operator|.
name|none
argument_list|()
operator|||
operator|(
name|UnitMask
operator|&
name|Mask
operator|)
operator|.
name|any
argument_list|()
condition|)
name|Units
operator|.
name|set
argument_list|(
operator|(
operator|*
name|Unit
operator|)
operator|.
name|first
argument_list|)
expr_stmt|;
block|}
block|}
comment|/// Removes all register units covered by physical register \p Reg.
name|void
name|removeReg
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
for|for
control|(
name|MCRegUnitIterator
name|Unit
argument_list|(
name|Reg
argument_list|,
name|TRI
argument_list|)
init|;
name|Unit
operator|.
name|isValid
argument_list|()
condition|;
operator|++
name|Unit
control|)
name|Units
operator|.
name|reset
argument_list|(
operator|*
name|Unit
argument_list|)
expr_stmt|;
block|}
comment|/// Removes register units not preserved by the regmask \p RegMask.
comment|/// The regmask has the same format as the one in the RegMask machine operand.
name|void
name|removeRegsNotPreserved
parameter_list|(
specifier|const
name|uint32_t
modifier|*
name|RegMask
parameter_list|)
function_decl|;
comment|/// Adds register units not preserved by the regmask \p RegMask.
comment|/// The regmask has the same format as the one in the RegMask machine operand.
name|void
name|addRegsInMask
parameter_list|(
specifier|const
name|uint32_t
modifier|*
name|RegMask
parameter_list|)
function_decl|;
comment|/// Returns true if no part of physical register \p Reg is live.
name|bool
name|available
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
block|{
for|for
control|(
name|MCRegUnitIterator
name|Unit
argument_list|(
name|Reg
argument_list|,
name|TRI
argument_list|)
init|;
name|Unit
operator|.
name|isValid
argument_list|()
condition|;
operator|++
name|Unit
control|)
block|{
if|if
condition|(
name|Units
operator|.
name|test
argument_list|(
operator|*
name|Unit
argument_list|)
condition|)
return|return
name|false
return|;
block|}
return|return
name|true
return|;
block|}
comment|/// Updates liveness when stepping backwards over the instruction \p MI.
comment|/// This removes all register units defined or clobbered in \p MI and then
comment|/// adds the units used (as in use operands) in \p MI.
name|void
name|stepBackward
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
comment|/// Adds all register units used, defined or clobbered in \p MI.
comment|/// This is useful when walking over a range of instruction to find registers
comment|/// unused over the whole range.
name|void
name|accumulate
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
comment|/// Adds registers living out of block \p MBB.
comment|/// Live out registers are the union of the live-in registers of the successor
comment|/// blocks and pristine registers. Live out registers of the end block are the
comment|/// callee saved registers.
name|void
name|addLiveOuts
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|)
function_decl|;
comment|/// Adds registers living into block \p MBB.
name|void
name|addLiveIns
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|)
function_decl|;
comment|/// Adds all register units marked in the bitvector \p RegUnits.
name|void
name|addUnits
parameter_list|(
specifier|const
name|BitVector
modifier|&
name|RegUnits
parameter_list|)
block|{
name|Units
operator||=
name|RegUnits
expr_stmt|;
block|}
comment|/// Removes all register units marked in the bitvector \p RegUnits.
name|void
name|removeUnits
parameter_list|(
specifier|const
name|BitVector
modifier|&
name|RegUnits
parameter_list|)
block|{
name|Units
operator|.
name|reset
argument_list|(
name|RegUnits
argument_list|)
expr_stmt|;
block|}
comment|/// Return the internal bitvector representation of the set.
specifier|const
name|BitVector
operator|&
name|getBitVector
argument_list|()
specifier|const
block|{
return|return
name|Units
return|;
block|}
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

begin_comment
comment|// LLVM_CODEGEN_LIVEREGUNITS_H
end_comment

end_unit

