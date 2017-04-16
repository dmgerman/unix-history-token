begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==-- llvm/CodeGen/GlobalISel/InstructionSelector.h -------------*- C++ -*-==//
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
comment|/// \file This file declares the API for the instruction selector.
end_comment

begin_comment
comment|/// This class is responsible for selecting machine instructions.
end_comment

begin_comment
comment|/// It's implemented by the target. It's used by the InstructionSelect pass.
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
name|LLVM_CODEGEN_GLOBALISEL_INSTRUCTIONSELECTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CODEGEN_GLOBALISEL_INSTRUCTIONSELECTOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
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
name|MachineOperand
decl_stmt|;
name|class
name|MachineRegisterInfo
decl_stmt|;
name|class
name|RegisterBankInfo
decl_stmt|;
name|class
name|TargetInstrInfo
decl_stmt|;
name|class
name|TargetRegisterInfo
decl_stmt|;
comment|/// Provides the logic to select generic machine instructions.
name|class
name|InstructionSelector
block|{
name|public
label|:
name|virtual
operator|~
name|InstructionSelector
argument_list|()
block|{}
comment|/// Select the (possibly generic) instruction \p I to only use target-specific
comment|/// opcodes. It is OK to insert multiple instructions, but they cannot be
comment|/// generic pre-isel instructions.
comment|///
comment|/// \returns whether selection succeeded.
comment|/// \pre  I.getParent()&& I.getParent()->getParent()
comment|/// \post
comment|///   if returns true:
comment|///     for I in all mutated/inserted instructions:
comment|///       !isPreISelGenericOpcode(I.getOpcode())
comment|///
name|virtual
name|bool
name|select
argument_list|(
argument|MachineInstr&I
argument_list|)
specifier|const
operator|=
literal|0
expr_stmt|;
name|protected
label|:
name|InstructionSelector
argument_list|()
expr_stmt|;
comment|/// Mutate the newly-selected instruction \p I to constrain its (possibly
comment|/// generic) virtual register operands to the instruction's register class.
comment|/// This could involve inserting COPYs before (for uses) or after (for defs).
comment|/// This requires the number of operands to match the instruction description.
comment|/// \returns whether operand regclass constraining succeeded.
comment|///
comment|// FIXME: Not all instructions have the same number of operands. We should
comment|// probably expose a constrain helper per operand and let the target selector
comment|// constrain individual registers, like fast-isel.
name|bool
name|constrainSelectedInstRegOperands
argument_list|(
name|MachineInstr
operator|&
name|I
argument_list|,
specifier|const
name|TargetInstrInfo
operator|&
name|TII
argument_list|,
specifier|const
name|TargetRegisterInfo
operator|&
name|TRI
argument_list|,
specifier|const
name|RegisterBankInfo
operator|&
name|RBI
argument_list|)
decl|const
decl_stmt|;
name|Optional
operator|<
name|int64_t
operator|>
name|getConstantVRegVal
argument_list|(
argument|unsigned VReg
argument_list|,
argument|const MachineRegisterInfo&MRI
argument_list|)
specifier|const
expr_stmt|;
name|bool
name|isOperandImmEqual
argument_list|(
specifier|const
name|MachineOperand
operator|&
name|MO
argument_list|,
name|int64_t
name|Value
argument_list|,
specifier|const
name|MachineRegisterInfo
operator|&
name|MRI
argument_list|)
decl|const
decl_stmt|;
name|bool
name|isObviouslySafeToFold
argument_list|(
name|MachineInstr
operator|&
name|MI
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

