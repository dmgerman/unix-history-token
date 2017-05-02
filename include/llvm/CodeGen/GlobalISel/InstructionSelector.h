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

begin_include
include|#
directive|include
file|<bitset>
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineInstrBuilder
decl_stmt|;
name|class
name|MachineFunction
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
comment|/// Container class for CodeGen predicate results.
comment|/// This is convenient because std::bitset does not have a constructor
comment|/// with an initializer list of set bits.
comment|///
comment|/// Each InstructionSelector subclass should define a PredicateBitset class with:
comment|///   const unsigned MAX_SUBTARGET_PREDICATES = 192;
comment|///   using PredicateBitset = PredicateBitsetImpl<MAX_SUBTARGET_PREDICATES>;
comment|/// and updating the constant to suit the target. Tablegen provides a suitable
comment|/// definition for the predicates in use in<Target>GenGlobalISel.inc when
comment|/// GET_GLOBALISEL_PREDICATE_BITSET is defined.
name|template
operator|<
name|std
operator|::
name|size_t
name|MaxPredicates
operator|>
name|class
name|PredicateBitsetImpl
operator|:
name|public
name|std
operator|::
name|bitset
operator|<
name|MaxPredicates
operator|>
block|{
name|public
operator|:
comment|// Cannot inherit constructors because it's not supported by VC++..
name|PredicateBitsetImpl
argument_list|()
operator|=
expr|default
block|;
name|PredicateBitsetImpl
argument_list|(
specifier|const
name|std
operator|::
name|bitset
operator|<
name|MaxPredicates
operator|>
operator|&
name|B
argument_list|)
operator|:
name|std
operator|::
name|bitset
operator|<
name|MaxPredicates
operator|>
operator|(
name|B
operator|)
block|{}
name|PredicateBitsetImpl
argument_list|(
argument|std::initializer_list<unsigned> Init
argument_list|)
block|{
for|for
control|(
name|auto
name|I
range|:
name|Init
control|)
name|std
operator|::
name|bitset
operator|<
name|MaxPredicates
operator|>
operator|::
name|set
argument_list|(
name|I
argument_list|)
expr_stmt|;
block|}
expr|}
block|;
comment|/// Provides the logic to select generic machine instructions.
name|class
name|InstructionSelector
block|{
name|public
operator|:
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
block|;
name|protected
operator|:
typedef|typedef
name|std
operator|::
name|function
operator|<
name|void
argument_list|(
name|MachineInstrBuilder
operator|&
argument_list|)
operator|>
name|ComplexRendererFn
expr_stmt|;
name|InstructionSelector
argument_list|()
block|;
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
argument|MachineInstr&I
argument_list|,
argument|const TargetInstrInfo&TII
argument_list|,
argument|const TargetRegisterInfo&TRI
argument_list|,
argument|const RegisterBankInfo&RBI
argument_list|)
specifier|const
block|;
name|bool
name|isOperandImmEqual
argument_list|(
argument|const MachineOperand&MO
argument_list|,
argument|int64_t Value
argument_list|,
argument|const MachineRegisterInfo&MRI
argument_list|)
specifier|const
block|;
name|bool
name|isObviouslySafeToFold
argument_list|(
argument|MachineInstr&MI
argument_list|)
specifier|const
block|; }
expr_stmt|;
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

