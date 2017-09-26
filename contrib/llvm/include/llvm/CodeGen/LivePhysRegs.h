begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/CodeGen/LivePhysRegs.h - Live Physical Register Set -*- C++ -*-===//
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
comment|/// This file implements the LivePhysRegs utility for tracking liveness of
end_comment

begin_comment
comment|/// physical registers. This can be used for ad-hoc liveness tracking after
end_comment

begin_comment
comment|/// register allocation. You can start with the live-ins/live-outs at the
end_comment

begin_comment
comment|/// beginning/end of a block and update the information while walking the
end_comment

begin_comment
comment|/// instructions inside the block. This implementation tracks the liveness on a
end_comment

begin_comment
comment|/// sub-register granularity.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// We assume that the high bits of a physical super-register are not preserved
end_comment

begin_comment
comment|/// unless the instruction has an implicit-use operand reading the super-
end_comment

begin_comment
comment|/// register.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// X86 Example:
end_comment

begin_comment
comment|/// %YMM0<def> = ...
end_comment

begin_comment
comment|/// %XMM0<def> = ... (Kills %XMM0, all %XMM0s sub-registers, and %YMM0)
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// %YMM0<def> = ...
end_comment

begin_comment
comment|/// %XMM0<def> = ..., %YMM0<imp-use> (%YMM0 and all its sub-registers are alive)
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CODEGEN_LIVEPHYSREGS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_LIVEPHYSREGS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/SparseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/CodeGen/MachineBasicBlock.h"
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
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineOperand
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|raw_ostream
decl_stmt|;
comment|/// \brief A set of physical registers with utility functions to track liveness
comment|/// when walking backward/forward through a basic block.
name|class
name|LivePhysRegs
block|{
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
init|=
name|nullptr
decl_stmt|;
name|SparseSet
operator|<
name|unsigned
operator|>
name|LiveRegs
expr_stmt|;
name|public
label|:
comment|/// Constructs an unitialized set. init() needs to be called to initialize it.
name|LivePhysRegs
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Constructs and initializes an empty set.
name|LivePhysRegs
argument_list|(
specifier|const
name|TargetRegisterInfo
operator|&
name|TRI
argument_list|)
operator|:
name|TRI
argument_list|(
argument|&TRI
argument_list|)
block|{
name|LiveRegs
operator|.
name|setUniverse
argument_list|(
name|TRI
operator|.
name|getNumRegs
argument_list|()
argument_list|)
block|;   }
name|LivePhysRegs
argument_list|(
specifier|const
name|LivePhysRegs
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|LivePhysRegs
modifier|&
name|operator
init|=
operator|(
specifier|const
name|LivePhysRegs
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
comment|/// (re-)initializes and clears the set.
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
name|LiveRegs
operator|.
name|clear
argument_list|()
expr_stmt|;
name|LiveRegs
operator|.
name|setUniverse
argument_list|(
name|TRI
operator|.
name|getNumRegs
argument_list|()
argument_list|)
expr_stmt|;
block|}
comment|/// Clears the set.
name|void
name|clear
parameter_list|()
block|{
name|LiveRegs
operator|.
name|clear
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
name|LiveRegs
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// Adds a physical register and all its sub-registers to the set.
name|void
name|addReg
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
name|assert
argument_list|(
name|TRI
operator|&&
literal|"LivePhysRegs is not initialized."
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|Reg
operator|<=
name|TRI
operator|->
name|getNumRegs
argument_list|()
operator|&&
literal|"Expected a physical register."
argument_list|)
expr_stmt|;
for|for
control|(
name|MCSubRegIterator
name|SubRegs
argument_list|(
name|Reg
argument_list|,
name|TRI
argument_list|,
comment|/*IncludeSelf=*/
name|true
argument_list|)
init|;
name|SubRegs
operator|.
name|isValid
argument_list|()
condition|;
operator|++
name|SubRegs
control|)
name|LiveRegs
operator|.
name|insert
argument_list|(
operator|*
name|SubRegs
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Removes a physical register, all its sub-registers, and all its
comment|/// super-registers from the set.
name|void
name|removeReg
parameter_list|(
name|unsigned
name|Reg
parameter_list|)
block|{
name|assert
argument_list|(
name|TRI
operator|&&
literal|"LivePhysRegs is not initialized."
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|Reg
operator|<=
name|TRI
operator|->
name|getNumRegs
argument_list|()
operator|&&
literal|"Expected a physical register."
argument_list|)
expr_stmt|;
for|for
control|(
name|MCRegAliasIterator
name|R
argument_list|(
name|Reg
argument_list|,
name|TRI
argument_list|,
name|true
argument_list|)
init|;
name|R
operator|.
name|isValid
argument_list|()
condition|;
operator|++
name|R
control|)
name|LiveRegs
operator|.
name|erase
argument_list|(
operator|*
name|R
argument_list|)
expr_stmt|;
block|}
comment|/// Removes physical registers clobbered by the regmask operand \p MO.
name|void
name|removeRegsInMask
argument_list|(
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|,
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
argument_list|,
specifier|const
name|MachineOperand
operator|*
operator|>>
operator|*
name|Clobbers
operator|=
name|nullptr
argument_list|)
decl_stmt|;
comment|/// \brief Returns true if register \p Reg is contained in the set. This also
comment|/// works if only the super register of \p Reg has been defined, because
comment|/// addReg() always adds all sub-registers to the set as well.
comment|/// Note: Returns false if just some sub registers are live, use available()
comment|/// when searching a free register.
name|bool
name|contains
argument_list|(
name|unsigned
name|Reg
argument_list|)
decl|const
block|{
return|return
name|LiveRegs
operator|.
name|count
argument_list|(
name|Reg
argument_list|)
return|;
block|}
comment|/// Returns true if register \p Reg and no aliasing register is in the set.
name|bool
name|available
argument_list|(
specifier|const
name|MachineRegisterInfo
operator|&
name|MRI
argument_list|,
name|unsigned
name|Reg
argument_list|)
decl|const
decl_stmt|;
comment|/// Simulates liveness when stepping backwards over an instruction(bundle).
comment|/// Remove Defs, add uses. This is the recommended way of calculating
comment|/// liveness.
name|void
name|stepBackward
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
comment|/// Simulates liveness when stepping forward over an instruction(bundle).
comment|/// Remove killed-uses, add defs. This is the not recommended way, because it
comment|/// depends on accurate kill flags. If possible use stepBackward() instead of
comment|/// this function. The clobbers set will be the list of registers either
comment|/// defined or clobbered by a regmask.  The operand will identify whether this
comment|/// is a regmask or register operand.
name|void
name|stepForward
argument_list|(
specifier|const
name|MachineInstr
operator|&
name|MI
argument_list|,
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
argument_list|,
specifier|const
name|MachineOperand
operator|*
operator|>>
operator|&
name|Clobbers
argument_list|)
decl_stmt|;
comment|/// Adds all live-in registers of basic block \p MBB.
comment|/// Live in registers are the registers in the blocks live-in list and the
comment|/// pristine registers.
name|void
name|addLiveIns
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|)
function_decl|;
comment|/// Adds all live-out registers of basic block \p MBB.
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
comment|/// Adds all live-out registers of basic block \p MBB but skips pristine
comment|/// registers.
name|void
name|addLiveOutsNoPristines
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|)
function_decl|;
name|using
name|const_iterator
init|=
name|SparseSet
operator|<
name|unsigned
operator|>
operator|::
name|const_iterator
decl_stmt|;
name|const_iterator
name|begin
argument_list|()
specifier|const
block|{
return|return
name|LiveRegs
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
name|LiveRegs
operator|.
name|end
argument_list|()
return|;
block|}
comment|/// Prints the currently live registers to \p OS.
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// Dumps the currently live registers to the debug output.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
comment|/// \brief Adds live-in registers from basic block \p MBB, taking associated
comment|/// lane masks into consideration.
name|void
name|addBlockLiveIns
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|)
function_decl|;
block|}
empty_stmt|;
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
name|LivePhysRegs
operator|&
name|LR
operator|)
block|{
name|LR
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
comment|/// \brief Computes the live-in list for \p MBB assuming all of its successors
comment|/// live-in lists are up-to-date. Uses the given LivePhysReg instance \p
comment|/// LiveRegs; This is just here to avoid repeated heap allocations when calling
comment|/// this multiple times in a pass.
name|void
name|computeLiveIns
parameter_list|(
name|LivePhysRegs
modifier|&
name|LiveRegs
parameter_list|,
specifier|const
name|MachineRegisterInfo
modifier|&
name|MRI
parameter_list|,
name|MachineBasicBlock
modifier|&
name|MBB
parameter_list|)
function_decl|;
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
comment|// LLVM_CODEGEN_LIVEPHYSREGS_H
end_comment

end_unit

