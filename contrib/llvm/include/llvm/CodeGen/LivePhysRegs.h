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
comment|// This file implements the LivePhysRegs utility for tracking liveness of
end_comment

begin_comment
comment|// physical registers. This can be used for ad-hoc liveness tracking after
end_comment

begin_comment
comment|// register allocation. You can start with the live-ins/live-outs at the
end_comment

begin_comment
comment|// beginning/end of a block and update the information while walking the
end_comment

begin_comment
comment|// instructions inside the block. This implementation tracks the liveness on a
end_comment

begin_comment
comment|// sub-register granularity.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// We assume that the high bits of a physical super-register are not preserved
end_comment

begin_comment
comment|// unless the instruction has an implicit-use operand reading the super-
end_comment

begin_comment
comment|// register.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// X86 Example:
end_comment

begin_comment
comment|// %YMM0<def> = ...
end_comment

begin_comment
comment|// %XMM0<def> = ... (Kills %XMM0, all %XMM0s sub-registers, and %YMM0)
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// %YMM0<def> = ...
end_comment

begin_comment
comment|// %XMM0<def> = ..., %YMM0<imp-use> (%YMM0 and all its sub-registers are alive)
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CODEGEN_LIVE_PHYS_REGS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_LIVE_PHYS_REGS_H
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
file|"llvm/Target/TargetRegisterInfo.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineInstr
decl_stmt|;
comment|/// \brief A set of live physical registers with functions to track liveness
comment|/// when walking backward/forward through a basic block.
name|class
name|LivePhysRegs
block|{
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
decl_stmt|;
name|SparseSet
operator|<
name|unsigned
operator|>
name|LiveRegs
expr_stmt|;
name|LivePhysRegs
argument_list|(
argument|const LivePhysRegs&
argument_list|)
name|LLVM_DELETED_FUNCTION
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
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|public
label|:
comment|/// \brief Constructs a new empty LivePhysRegs set.
name|LivePhysRegs
argument_list|()
operator|:
name|TRI
argument_list|(
name|nullptr
argument_list|)
operator|,
name|LiveRegs
argument_list|()
block|{}
comment|/// \brief Constructs and initialize an empty LivePhysRegs set.
name|LivePhysRegs
argument_list|(
specifier|const
name|TargetRegisterInfo
operator|*
name|TRI
argument_list|)
operator|:
name|TRI
argument_list|(
argument|TRI
argument_list|)
block|{
name|assert
argument_list|(
name|TRI
operator|&&
literal|"Invalid TargetRegisterInfo pointer."
argument_list|)
block|;
name|LiveRegs
operator|.
name|setUniverse
argument_list|(
name|TRI
operator|->
name|getNumRegs
argument_list|()
argument_list|)
block|;   }
comment|/// \brief Clear and initialize the LivePhysRegs set.
name|void
name|init
argument_list|(
argument|const TargetRegisterInfo *_TRI
argument_list|)
block|{
name|assert
argument_list|(
name|_TRI
operator|&&
literal|"Invalid TargetRegisterInfo pointer."
argument_list|)
block|;
name|TRI
operator|=
name|_TRI
block|;
name|LiveRegs
operator|.
name|clear
argument_list|()
block|;
name|LiveRegs
operator|.
name|setUniverse
argument_list|(
name|TRI
operator|->
name|getNumRegs
argument_list|()
argument_list|)
block|;   }
comment|/// \brief Clears the LivePhysRegs set.
name|void
name|clear
argument_list|()
block|{
name|LiveRegs
operator|.
name|clear
argument_list|()
block|; }
comment|/// \brief Returns true if the set is empty.
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
comment|/// \brief Adds a physical register and all its sub-registers to the set.
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
name|erase
argument_list|(
operator|*
name|SubRegs
argument_list|)
expr_stmt|;
for|for
control|(
name|MCSuperRegIterator
name|SuperRegs
argument_list|(
name|Reg
argument_list|,
name|TRI
argument_list|,
comment|/*IncludeSelf=*/
name|false
argument_list|)
init|;
name|SuperRegs
operator|.
name|isValid
argument_list|()
condition|;
operator|++
name|SuperRegs
control|)
name|LiveRegs
operator|.
name|erase
argument_list|(
operator|*
name|SuperRegs
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Removes physical registers clobbered by the regmask operand @p MO.
name|void
name|removeRegsInMask
parameter_list|(
specifier|const
name|MachineOperand
modifier|&
name|MO
parameter_list|)
function_decl|;
comment|/// \brief Returns true if register @p Reg is contained in the set. This also
comment|/// works if only the super register of @p Reg has been defined, because we
comment|/// always add also all sub-registers to the set.
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
comment|/// \brief Simulates liveness when stepping backwards over an
comment|/// instruction(bundle): Remove Defs, add uses. This is the recommended way of
comment|/// calculating liveness.
name|void
name|stepBackward
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
comment|/// \brief Simulates liveness when stepping forward over an
comment|/// instruction(bundle): Remove killed-uses, add defs. This is the not
comment|/// recommended way, because it depends on accurate kill flags. If possible
comment|/// use stepBackwards() instead of this function.
name|void
name|stepForward
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|)
function_decl|;
comment|/// \brief Adds all live-in registers of basic block @p MBB.
name|void
name|addLiveIns
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
block|{
for|for
control|(
name|MachineBasicBlock
operator|::
name|livein_iterator
name|LI
operator|=
name|MBB
operator|->
name|livein_begin
argument_list|()
operator|,
name|LE
operator|=
name|MBB
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
name|addReg
argument_list|(
operator|*
name|LI
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Adds all live-out registers of basic block @p MBB.
name|void
name|addLiveOuts
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|)
block|{
for|for
control|(
name|MachineBasicBlock
operator|::
name|const_succ_iterator
name|SI
operator|=
name|MBB
operator|->
name|succ_begin
argument_list|()
operator|,
name|SE
operator|=
name|MBB
operator|->
name|succ_end
argument_list|()
init|;
name|SI
operator|!=
name|SE
condition|;
operator|++
name|SI
control|)
name|addLiveIns
argument_list|(
operator|*
name|SI
argument_list|)
expr_stmt|;
block|}
typedef|typedef
name|SparseSet
operator|<
name|unsigned
operator|>
operator|::
name|const_iterator
name|const_iterator
expr_stmt|;
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
comment|/// \brief Prints the currently live registers to @p OS.
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Dumps the currently live registers to the debug output.
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
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
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CODEGEN_LIVE_PHYS_REGS_H
end_comment

end_unit

