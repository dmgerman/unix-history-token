begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/CodeGen/GlobalISel/InstructionSelector.h ------------*- C++ -*-===//
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
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<bitset>
end_include

begin_include
include|#
directive|include
file|<cstddef>
end_include

begin_include
include|#
directive|include
file|<cstdint>
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_include
include|#
directive|include
file|<initializer_list>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|LLT
decl_stmt|;
name|class
name|MachineInstr
decl_stmt|;
name|class
name|MachineInstrBuilder
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
name|TargetRegisterClass
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
block|;  enum
block|{
comment|/// Record the specified instruction
comment|/// - NewInsnID - Instruction ID to define
comment|/// - InsnID - Instruction ID
comment|/// - OpIdx - Operand index
name|GIM_RecordInsn
block|,
comment|/// Check the feature bits
comment|/// - Expected features
name|GIM_CheckFeatures
block|,
comment|/// Check the opcode on the specified instruction
comment|/// - InsnID - Instruction ID
comment|/// - Expected opcode
name|GIM_CheckOpcode
block|,
comment|/// Check the instruction has the right number of operands
comment|/// - InsnID - Instruction ID
comment|/// - Expected number of operands
name|GIM_CheckNumOperands
block|,
comment|/// Check the type for the specified operand
comment|/// - InsnID - Instruction ID
comment|/// - OpIdx - Operand index
comment|/// - Expected type
name|GIM_CheckType
block|,
comment|/// Check the register bank for the specified operand
comment|/// - InsnID - Instruction ID
comment|/// - OpIdx - Operand index
comment|/// - Expected register bank (specified as a register class)
name|GIM_CheckRegBankForClass
block|,
comment|/// Check the operand matches a complex predicate
comment|/// - InsnID - Instruction ID
comment|/// - OpIdx - Operand index
comment|/// - RendererID - The renderer to hold the result
comment|/// - Complex predicate ID
name|GIM_CheckComplexPattern
block|,
comment|/// Check the operand is a specific integer
comment|/// - InsnID - Instruction ID
comment|/// - OpIdx - Operand index
comment|/// - Expected integer
name|GIM_CheckConstantInt
block|,
comment|/// Check the operand is a specific literal integer (i.e. MO.isImm() or MO.isCImm() is true).
comment|/// - InsnID - Instruction ID
comment|/// - OpIdx - Operand index
comment|/// - Expected integer
name|GIM_CheckLiteralInt
block|,
comment|/// Check the operand is a specific intrinsic ID
comment|/// - InsnID - Instruction ID
comment|/// - OpIdx - Operand index
comment|/// - Expected Intrinsic ID
name|GIM_CheckIntrinsicID
block|,
comment|/// Check the specified operand is an MBB
comment|/// - InsnID - Instruction ID
comment|/// - OpIdx - Operand index
name|GIM_CheckIsMBB
block|,
comment|/// Check if the specified operand is safe to fold into the current
comment|/// instruction.
comment|/// - InsnID - Instruction ID
name|GIM_CheckIsSafeToFold
block|,
comment|//=== Renderers ===
comment|/// Mutate an instruction
comment|/// - NewInsnID - Instruction ID to define
comment|/// - OldInsnID - Instruction ID to mutate
comment|/// - NewOpcode - The new opcode to use
name|GIR_MutateOpcode
block|,
comment|/// Build a new instruction
comment|/// - InsnID - Instruction ID to define
comment|/// - Opcode - The new opcode to use
name|GIR_BuildMI
block|,
comment|/// Copy an operand to the specified instruction
comment|/// - NewInsnID - Instruction ID to modify
comment|/// - OldInsnID - Instruction ID to copy from
comment|/// - OpIdx - The operand to copy
name|GIR_Copy
block|,
comment|/// Copy an operand to the specified instruction
comment|/// - NewInsnID - Instruction ID to modify
comment|/// - OldInsnID - Instruction ID to copy from
comment|/// - OpIdx - The operand to copy
comment|/// - SubRegIdx - The subregister to copy
name|GIR_CopySubReg
block|,
comment|/// Add an implicit register def to the specified instruction
comment|/// - InsnID - Instruction ID to modify
comment|/// - RegNum - The register to add
name|GIR_AddImplicitDef
block|,
comment|/// Add an implicit register use to the specified instruction
comment|/// - InsnID - Instruction ID to modify
comment|/// - RegNum - The register to add
name|GIR_AddImplicitUse
block|,
comment|/// Add an register to the specified instruction
comment|/// - InsnID - Instruction ID to modify
comment|/// - RegNum - The register to add
name|GIR_AddRegister
block|,
comment|/// Add an immediate to the specified instruction
comment|/// - InsnID - Instruction ID to modify
comment|/// - Imm - The immediate to add
name|GIR_AddImm
block|,
comment|/// Render complex operands to the specified instruction
comment|/// - InsnID - Instruction ID to modify
comment|/// - RendererID - The renderer to call
name|GIR_ComplexRenderer
block|,
comment|/// Constrain an instruction operand to a register class.
comment|/// - InsnID - Instruction ID to modify
comment|/// - OpIdx - Operand index
comment|/// - RCEnum - Register class enumeration value
name|GIR_ConstrainOperandRC
block|,
comment|/// Constrain an instructions operands according to the instruction
comment|/// description.
comment|/// - InsnID - Instruction ID to modify
name|GIR_ConstrainSelectedInstOperands
block|,
comment|/// Merge all memory operands into instruction.
comment|/// - InsnID - Instruction ID to modify
name|GIR_MergeMemOperands
block|,
comment|/// Erase from parent.
comment|/// - InsnID - Instruction ID to erase
name|GIR_EraseFromParent
block|,
comment|/// A successful emission
name|GIR_Done
block|, }
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
operator|=
expr|default
block|;
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
name|using
name|ComplexRendererFn
operator|=
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
block|;
name|using
name|RecordedMIVector
operator|=
name|SmallVector
operator|<
name|MachineInstr
operator|*
block|,
literal|4
operator|>
block|;
name|using
name|NewMIVector
operator|=
name|SmallVector
operator|<
name|MachineInstrBuilder
block|,
literal|4
operator|>
block|;    struct
name|MatcherState
block|{
name|std
operator|::
name|vector
operator|<
name|ComplexRendererFn
operator|>
name|Renderers
block|;
name|RecordedMIVector
name|MIs
block|;
name|MatcherState
argument_list|(
argument|unsigned MaxRenderers
argument_list|)
block|;   }
block|;
name|public
operator|:
name|template
operator|<
name|class
name|PredicateBitset
block|,
name|class
name|ComplexMatcherMemFn
operator|>
expr|struct
name|MatcherInfoTy
block|{
specifier|const
name|LLT
operator|*
name|TypeObjects
block|;
specifier|const
name|PredicateBitset
operator|*
name|FeatureBitsets
block|;
specifier|const
name|std
operator|::
name|vector
operator|<
name|ComplexMatcherMemFn
operator|>
name|ComplexPredicates
block|;   }
block|;
name|protected
operator|:
name|InstructionSelector
argument_list|()
block|;
comment|/// Execute a given matcher table and return true if the match was successful
comment|/// and false otherwise.
name|template
operator|<
name|class
name|TgtInstructionSelector
block|,
name|class
name|PredicateBitset
block|,
name|class
name|ComplexMatcherMemFn
operator|>
name|bool
name|executeMatchTable
argument_list|(
argument|TgtInstructionSelector&ISel
argument_list|,
argument|NewMIVector&OutMIs
argument_list|,
argument|MatcherState&State
argument_list|,
argument|const MatcherInfoTy<PredicateBitset
argument_list|,
argument|ComplexMatcherMemFn>&MatcherInfo
argument_list|,
argument|const int64_t *MatchTable
argument_list|,
argument|const TargetInstrInfo&TII
argument_list|,
argument|MachineRegisterInfo&MRI
argument_list|,
argument|const TargetRegisterInfo&TRI
argument_list|,
argument|const RegisterBankInfo&RBI
argument_list|,
argument|const PredicateBitset&AvailableFeatures
argument_list|)
specifier|const
block|;
comment|/// Constrain a register operand of an instruction \p I to a specified
comment|/// register class. This could involve inserting COPYs before (for uses) or
comment|/// after (for defs) and may replace the operand of \p I.
comment|/// \returns whether operand regclass constraining succeeded.
name|bool
name|constrainOperandRegToRegClass
argument_list|(
argument|MachineInstr&I
argument_list|,
argument|unsigned OpIdx
argument_list|,
argument|const TargetRegisterClass&RC
argument_list|,
argument|const TargetInstrInfo&TII
argument_list|,
argument|const TargetRegisterInfo&TRI
argument_list|,
argument|const RegisterBankInfo&RBI
argument_list|)
specifier|const
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
comment|// LLVM_CODEGEN_GLOBALISEL_INSTRUCTIONSELECTOR_H
end_comment

end_unit

