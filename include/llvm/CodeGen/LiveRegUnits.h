begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/CodeGen/LiveRegUnits.h - Live register unit set ----*- C++ -*-===//
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
comment|// This file implements a Set of live register units. This can be used for ad
end_comment

begin_comment
comment|// hoc liveness tracking after register allocation. You can start with the
end_comment

begin_comment
comment|// live-ins/live-outs at the beginning/end of a block and update the information
end_comment

begin_comment
comment|// while walking the instructions inside the block.
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
comment|/// A set of live register units with functions to track liveness when walking
comment|/// backward/forward through a basic block.
name|class
name|LiveRegUnits
block|{
name|SparseSet
operator|<
name|unsigned
operator|>
name|LiveUnits
expr_stmt|;
name|LiveRegUnits
argument_list|(
argument|const LiveRegUnits&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|LiveRegUnits
modifier|&
name|operator
init|=
operator|(
specifier|const
name|LiveRegUnits
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|public
label|:
comment|/// \brief Constructs a new empty LiveRegUnits set.
name|LiveRegUnits
argument_list|()
block|{}
name|void
name|init
parameter_list|(
specifier|const
name|TargetRegisterInfo
modifier|*
name|TRI
parameter_list|)
block|{
name|LiveUnits
operator|.
name|clear
argument_list|()
expr_stmt|;
name|LiveUnits
operator|.
name|setUniverse
argument_list|(
name|TRI
operator|->
name|getNumRegs
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|void
name|clear
parameter_list|()
block|{
name|LiveUnits
operator|.
name|clear
argument_list|()
expr_stmt|;
block|}
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|LiveUnits
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// \brief Adds a register to the set.
name|void
name|addReg
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
specifier|const
name|MCRegisterInfo
modifier|&
name|MCRI
parameter_list|)
block|{
for|for
control|(
name|MCRegUnitIterator
name|RUnits
argument_list|(
name|Reg
argument_list|,
operator|&
name|MCRI
argument_list|)
init|;
name|RUnits
operator|.
name|isValid
argument_list|()
condition|;
operator|++
name|RUnits
control|)
name|LiveUnits
operator|.
name|insert
argument_list|(
operator|*
name|RUnits
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Removes a register from the set.
name|void
name|removeReg
parameter_list|(
name|unsigned
name|Reg
parameter_list|,
specifier|const
name|MCRegisterInfo
modifier|&
name|MCRI
parameter_list|)
block|{
for|for
control|(
name|MCRegUnitIterator
name|RUnits
argument_list|(
name|Reg
argument_list|,
operator|&
name|MCRI
argument_list|)
init|;
name|RUnits
operator|.
name|isValid
argument_list|()
condition|;
operator|++
name|RUnits
control|)
name|LiveUnits
operator|.
name|erase
argument_list|(
operator|*
name|RUnits
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Removes registers clobbered by the regmask operand @p Op.
name|void
name|removeRegsInMask
parameter_list|(
specifier|const
name|MachineOperand
modifier|&
name|Op
parameter_list|,
specifier|const
name|MCRegisterInfo
modifier|&
name|MCRI
parameter_list|)
function_decl|;
comment|/// \brief Returns true if register @p Reg (or one of its super register) is
comment|/// contained in the set.
name|bool
name|contains
argument_list|(
name|unsigned
name|Reg
argument_list|,
specifier|const
name|MCRegisterInfo
operator|&
name|MCRI
argument_list|)
decl|const
block|{
for|for
control|(
name|MCRegUnitIterator
name|RUnits
argument_list|(
name|Reg
argument_list|,
operator|&
name|MCRI
argument_list|)
init|;
name|RUnits
operator|.
name|isValid
argument_list|()
condition|;
operator|++
name|RUnits
control|)
block|{
if|if
condition|(
name|LiveUnits
operator|.
name|count
argument_list|(
operator|*
name|RUnits
argument_list|)
condition|)
return|return
name|true
return|;
block|}
return|return
name|false
return|;
block|}
comment|/// \brief Simulates liveness when stepping backwards over an
comment|/// instruction(bundle): Remove Defs, add uses.
name|void
name|stepBackward
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|,
specifier|const
name|MCRegisterInfo
modifier|&
name|MCRI
parameter_list|)
function_decl|;
comment|/// \brief Simulates liveness when stepping forward over an
comment|/// instruction(bundle): Remove killed-uses, add defs.
name|void
name|stepForward
parameter_list|(
specifier|const
name|MachineInstr
modifier|&
name|MI
parameter_list|,
specifier|const
name|MCRegisterInfo
modifier|&
name|MCRI
parameter_list|)
function_decl|;
comment|/// \brief Adds all registers in the live-in list of block @p BB.
name|void
name|addLiveIns
parameter_list|(
specifier|const
name|MachineBasicBlock
modifier|*
name|MBB
parameter_list|,
specifier|const
name|MCRegisterInfo
modifier|&
name|MCRI
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

