begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/InlineAsm.h - Class to represent inline asm strings -*- C++ -*-===//
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
comment|// This class represents the inline asm strings, which are Value*'s that are
end_comment

begin_comment
comment|// used as the callee operand of call instructions.  InlineAsm's are uniqued
end_comment

begin_comment
comment|// like constants, and created via InlineAsm::get(...).
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
name|LLVM_IR_INLINEASM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_INLINEASM_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Value.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<string>
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
name|FunctionType
decl_stmt|;
name|class
name|PointerType
decl_stmt|;
name|template
operator|<
name|class
name|ConstantClass
operator|>
name|class
name|ConstantUniqueMap
expr_stmt|;
name|class
name|InlineAsm
name|final
range|:
name|public
name|Value
block|{
name|public
operator|:
expr|enum
name|AsmDialect
block|{
name|AD_ATT
block|,
name|AD_Intel
block|}
block|;
name|private
operator|:
name|friend
expr|struct
name|InlineAsmKeyType
block|;
name|friend
name|class
name|ConstantUniqueMap
operator|<
name|InlineAsm
operator|>
block|;
name|std
operator|::
name|string
name|AsmString
block|,
name|Constraints
block|;
name|FunctionType
operator|*
name|FTy
block|;
name|bool
name|HasSideEffects
block|;
name|bool
name|IsAlignStack
block|;
name|AsmDialect
name|Dialect
block|;
name|InlineAsm
argument_list|(
argument|FunctionType *Ty
argument_list|,
argument|const std::string&AsmString
argument_list|,
argument|const std::string&Constraints
argument_list|,
argument|bool hasSideEffects
argument_list|,
argument|bool isAlignStack
argument_list|,
argument|AsmDialect asmDialect
argument_list|)
block|;
comment|/// When the ConstantUniqueMap merges two types and makes two InlineAsms
comment|/// identical, it destroys one of them with this method.
name|void
name|destroyConstant
argument_list|()
block|;
name|public
operator|:
name|InlineAsm
argument_list|(
specifier|const
name|InlineAsm
operator|&
argument_list|)
operator|=
name|delete
block|;
name|InlineAsm
operator|&
name|operator
operator|=
operator|(
specifier|const
name|InlineAsm
operator|&
operator|)
operator|=
name|delete
block|;
comment|/// InlineAsm::get - Return the specified uniqued inline asm string.
comment|///
specifier|static
name|InlineAsm
operator|*
name|get
argument_list|(
argument|FunctionType *Ty
argument_list|,
argument|StringRef AsmString
argument_list|,
argument|StringRef Constraints
argument_list|,
argument|bool hasSideEffects
argument_list|,
argument|bool isAlignStack = false
argument_list|,
argument|AsmDialect asmDialect = AD_ATT
argument_list|)
block|;
name|bool
name|hasSideEffects
argument_list|()
specifier|const
block|{
return|return
name|HasSideEffects
return|;
block|}
name|bool
name|isAlignStack
argument_list|()
specifier|const
block|{
return|return
name|IsAlignStack
return|;
block|}
name|AsmDialect
name|getDialect
argument_list|()
specifier|const
block|{
return|return
name|Dialect
return|;
block|}
comment|/// getType - InlineAsm's are always pointers.
comment|///
name|PointerType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
name|PointerType
operator|*
operator|>
operator|(
name|Value
operator|::
name|getType
argument_list|()
operator|)
return|;
block|}
comment|/// getFunctionType - InlineAsm's are always pointers to functions.
comment|///
name|FunctionType
operator|*
name|getFunctionType
argument_list|()
specifier|const
block|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getAsmString
argument_list|()
specifier|const
block|{
return|return
name|AsmString
return|;
block|}
specifier|const
name|std
operator|::
name|string
operator|&
name|getConstraintString
argument_list|()
specifier|const
block|{
return|return
name|Constraints
return|;
block|}
comment|/// Verify - This static method can be used by the parser to check to see if
comment|/// the specified constraint string is legal for the type.  This returns true
comment|/// if legal, false if not.
comment|///
specifier|static
name|bool
name|Verify
argument_list|(
argument|FunctionType *Ty
argument_list|,
argument|StringRef Constraints
argument_list|)
block|;
comment|// Constraint String Parsing
block|enum
name|ConstraintPrefix
block|{
name|isInput
block|,
comment|// 'x'
name|isOutput
block|,
comment|// '=x'
name|isClobber
comment|// '~x'
block|}
block|;
name|using
name|ConstraintCodeVector
operator|=
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
block|;    struct
name|SubConstraintInfo
block|{
comment|/// MatchingInput - If this is not -1, this is an output constraint where an
comment|/// input constraint is required to match it (e.g. "0").  The value is the
comment|/// constraint number that matches this one (for example, if this is
comment|/// constraint #0 and constraint #4 has the value "0", this will be 4).
name|signed
name|char
name|MatchingInput
operator|=
operator|-
literal|1
block|;
comment|/// Code - The constraint code, either the register name (in braces) or the
comment|/// constraint letter/number.
name|ConstraintCodeVector
name|Codes
block|;
comment|/// Default constructor.
name|SubConstraintInfo
argument_list|()
operator|=
expr|default
block|;   }
block|;
name|using
name|SubConstraintInfoVector
operator|=
name|std
operator|::
name|vector
operator|<
name|SubConstraintInfo
operator|>
block|;   struct
name|ConstraintInfo
block|;
name|using
name|ConstraintInfoVector
operator|=
name|std
operator|::
name|vector
operator|<
name|ConstraintInfo
operator|>
block|;    struct
name|ConstraintInfo
block|{
comment|/// Type - The basic type of the constraint: input/output/clobber
comment|///
name|ConstraintPrefix
name|Type
operator|=
name|isInput
block|;
comment|/// isEarlyClobber - "&": output operand writes result before inputs are all
comment|/// read.  This is only ever set for an output operand.
name|bool
name|isEarlyClobber
operator|=
name|false
block|;
comment|/// MatchingInput - If this is not -1, this is an output constraint where an
comment|/// input constraint is required to match it (e.g. "0").  The value is the
comment|/// constraint number that matches this one (for example, if this is
comment|/// constraint #0 and constraint #4 has the value "0", this will be 4).
name|signed
name|char
name|MatchingInput
operator|=
operator|-
literal|1
block|;
comment|/// hasMatchingInput - Return true if this is an output constraint that has
comment|/// a matching input constraint.
name|bool
name|hasMatchingInput
argument_list|()
specifier|const
block|{
return|return
name|MatchingInput
operator|!=
operator|-
literal|1
return|;
block|}
comment|/// isCommutative - This is set to true for a constraint that is commutative
comment|/// with the next operand.
name|bool
name|isCommutative
operator|=
name|false
block|;
comment|/// isIndirect - True if this operand is an indirect operand.  This means
comment|/// that the address of the source or destination is present in the call
comment|/// instruction, instead of it being returned or passed in explicitly.  This
comment|/// is represented with a '*' in the asm string.
name|bool
name|isIndirect
operator|=
name|false
block|;
comment|/// Code - The constraint code, either the register name (in braces) or the
comment|/// constraint letter/number.
name|ConstraintCodeVector
name|Codes
block|;
comment|/// isMultipleAlternative - '|': has multiple-alternative constraints.
name|bool
name|isMultipleAlternative
operator|=
name|false
block|;
comment|/// multipleAlternatives - If there are multiple alternative constraints,
comment|/// this array will contain them.  Otherwise it will be empty.
name|SubConstraintInfoVector
name|multipleAlternatives
block|;
comment|/// The currently selected alternative constraint index.
name|unsigned
name|currentAlternativeIndex
operator|=
literal|0
block|;
comment|/// Default constructor.
name|ConstraintInfo
argument_list|()
operator|=
expr|default
block|;
comment|/// Parse - Analyze the specified string (e.g. "=*&{eax}") and fill in the
comment|/// fields in this structure.  If the constraint string is not understood,
comment|/// return true, otherwise return false.
name|bool
name|Parse
argument_list|(
argument|StringRef Str
argument_list|,
argument|ConstraintInfoVector&ConstraintsSoFar
argument_list|)
block|;
comment|/// selectAlternative - Point this constraint to the alternative constraint
comment|/// indicated by the index.
name|void
name|selectAlternative
argument_list|(
argument|unsigned index
argument_list|)
block|;   }
block|;
comment|/// ParseConstraints - Split up the constraint string into the specific
comment|/// constraints and their prefixes.  If this returns an empty vector, and if
comment|/// the constraint string itself isn't empty, there was an error parsing.
specifier|static
name|ConstraintInfoVector
name|ParseConstraints
argument_list|(
argument|StringRef ConstraintString
argument_list|)
block|;
comment|/// ParseConstraints - Parse the constraints of this inlineasm object,
comment|/// returning them the same way that ParseConstraints(str) does.
name|ConstraintInfoVector
name|ParseConstraints
argument_list|()
specifier|const
block|{
return|return
name|ParseConstraints
argument_list|(
name|Constraints
argument_list|)
return|;
block|}
comment|// Methods for support type inquiry through isa, cast, and dyn_cast:
specifier|static
name|bool
name|classof
argument_list|(
argument|const Value *V
argument_list|)
block|{
return|return
name|V
operator|->
name|getValueID
argument_list|()
operator|==
name|Value
operator|::
name|InlineAsmVal
return|;
block|}
comment|// These are helper methods for dealing with flags in the INLINEASM SDNode
comment|// in the backend.
comment|//
comment|// The encoding of the flag word is currently:
comment|//   Bits 2-0 - A Kind_* value indicating the kind of the operand.
comment|//   Bits 15-3 - The number of SDNode operands associated with this inline
comment|//               assembly operand.
comment|//   If bit 31 is set:
comment|//     Bit 30-16 - The operand number that this operand must match.
comment|//                 When bits 2-0 are Kind_Mem, the Constraint_* value must be
comment|//                 obtained from the flags for this operand number.
comment|//   Else if bits 2-0 are Kind_Mem:
comment|//     Bit 30-16 - A Constraint_* value indicating the original constraint
comment|//                 code.
comment|//   Else:
comment|//     Bit 30-16 - The register class ID to use for the operand.
expr|enum
operator|:
name|uint32_t
block|{
comment|// Fixed operands on an INLINEASM SDNode.
name|Op_InputChain
operator|=
literal|0
block|,
name|Op_AsmString
operator|=
literal|1
block|,
name|Op_MDNode
operator|=
literal|2
block|,
name|Op_ExtraInfo
operator|=
literal|3
block|,
comment|// HasSideEffects, IsAlignStack, AsmDialect.
name|Op_FirstOperand
operator|=
literal|4
block|,
comment|// Fixed operands on an INLINEASM MachineInstr.
name|MIOp_AsmString
operator|=
literal|0
block|,
name|MIOp_ExtraInfo
operator|=
literal|1
block|,
comment|// HasSideEffects, IsAlignStack, AsmDialect.
name|MIOp_FirstOperand
operator|=
literal|2
block|,
comment|// Interpretation of the MIOp_ExtraInfo bit field.
name|Extra_HasSideEffects
operator|=
literal|1
block|,
name|Extra_IsAlignStack
operator|=
literal|2
block|,
name|Extra_AsmDialect
operator|=
literal|4
block|,
name|Extra_MayLoad
operator|=
literal|8
block|,
name|Extra_MayStore
operator|=
literal|16
block|,
name|Extra_IsConvergent
operator|=
literal|32
block|,
comment|// Inline asm operands map to multiple SDNode / MachineInstr operands.
comment|// The first operand is an immediate describing the asm operand, the low
comment|// bits is the kind:
name|Kind_RegUse
operator|=
literal|1
block|,
comment|// Input register, "r".
name|Kind_RegDef
operator|=
literal|2
block|,
comment|// Output register, "=r".
name|Kind_RegDefEarlyClobber
operator|=
literal|3
block|,
comment|// Early-clobber output register, "=&r".
name|Kind_Clobber
operator|=
literal|4
block|,
comment|// Clobbered register, "~r".
name|Kind_Imm
operator|=
literal|5
block|,
comment|// Immediate.
name|Kind_Mem
operator|=
literal|6
block|,
comment|// Memory operand, "m".
comment|// Memory constraint codes.
comment|// These could be tablegenerated but there's little need to do that since
comment|// there's plenty of space in the encoding to support the union of all
comment|// constraint codes for all targets.
name|Constraint_Unknown
operator|=
literal|0
block|,
name|Constraint_es
block|,
name|Constraint_i
block|,
name|Constraint_m
block|,
name|Constraint_o
block|,
name|Constraint_v
block|,
name|Constraint_Q
block|,
name|Constraint_R
block|,
name|Constraint_S
block|,
name|Constraint_T
block|,
name|Constraint_Um
block|,
name|Constraint_Un
block|,
name|Constraint_Uq
block|,
name|Constraint_Us
block|,
name|Constraint_Ut
block|,
name|Constraint_Uv
block|,
name|Constraint_Uy
block|,
name|Constraint_X
block|,
name|Constraint_Z
block|,
name|Constraint_ZC
block|,
name|Constraint_Zy
block|,
name|Constraints_Max
operator|=
name|Constraint_Zy
block|,
name|Constraints_ShiftAmount
operator|=
literal|16
block|,
name|Flag_MatchingOperand
operator|=
literal|0x80000000
block|}
block|;
specifier|static
name|unsigned
name|getFlagWord
argument_list|(
argument|unsigned Kind
argument_list|,
argument|unsigned NumOps
argument_list|)
block|{
name|assert
argument_list|(
operator|(
operator|(
name|NumOps
operator|<<
literal|3
operator|)
operator|&
operator|~
literal|0xffff
operator|)
operator|==
literal|0
operator|&&
literal|"Too many inline asm operands!"
argument_list|)
block|;
name|assert
argument_list|(
name|Kind
operator|>=
name|Kind_RegUse
operator|&&
name|Kind
operator|<=
name|Kind_Mem
operator|&&
literal|"Invalid Kind"
argument_list|)
block|;
return|return
name|Kind
operator||
operator|(
name|NumOps
operator|<<
literal|3
operator|)
return|;
block|}
specifier|static
name|bool
name|isRegDefKind
argument_list|(
argument|unsigned Flag
argument_list|)
block|{
return|return
name|getKind
argument_list|(
name|Flag
argument_list|)
operator|==
name|Kind_RegDef
return|;
block|}
specifier|static
name|bool
name|isImmKind
argument_list|(
argument|unsigned Flag
argument_list|)
block|{
return|return
name|getKind
argument_list|(
name|Flag
argument_list|)
operator|==
name|Kind_Imm
return|;
block|}
specifier|static
name|bool
name|isMemKind
argument_list|(
argument|unsigned Flag
argument_list|)
block|{
return|return
name|getKind
argument_list|(
name|Flag
argument_list|)
operator|==
name|Kind_Mem
return|;
block|}
specifier|static
name|bool
name|isRegDefEarlyClobberKind
argument_list|(
argument|unsigned Flag
argument_list|)
block|{
return|return
name|getKind
argument_list|(
name|Flag
argument_list|)
operator|==
name|Kind_RegDefEarlyClobber
return|;
block|}
specifier|static
name|bool
name|isClobberKind
argument_list|(
argument|unsigned Flag
argument_list|)
block|{
return|return
name|getKind
argument_list|(
name|Flag
argument_list|)
operator|==
name|Kind_Clobber
return|;
block|}
comment|/// getFlagWordForMatchingOp - Augment an existing flag word returned by
comment|/// getFlagWord with information indicating that this input operand is tied
comment|/// to a previous output operand.
specifier|static
name|unsigned
name|getFlagWordForMatchingOp
argument_list|(
argument|unsigned InputFlag
argument_list|,
argument|unsigned MatchedOperandNo
argument_list|)
block|{
name|assert
argument_list|(
name|MatchedOperandNo
operator|<=
literal|0x7fff
operator|&&
literal|"Too big matched operand"
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|InputFlag
operator|&
operator|~
literal|0xffff
operator|)
operator|==
literal|0
operator|&&
literal|"High bits already contain data"
argument_list|)
block|;
return|return
name|InputFlag
operator||
name|Flag_MatchingOperand
operator||
operator|(
name|MatchedOperandNo
operator|<<
literal|16
operator|)
return|;
block|}
comment|/// getFlagWordForRegClass - Augment an existing flag word returned by
comment|/// getFlagWord with the required register class for the following register
comment|/// operands.
comment|/// A tied use operand cannot have a register class, use the register class
comment|/// from the def operand instead.
specifier|static
name|unsigned
name|getFlagWordForRegClass
argument_list|(
argument|unsigned InputFlag
argument_list|,
argument|unsigned RC
argument_list|)
block|{
comment|// Store RC + 1, reserve the value 0 to mean 'no register class'.
operator|++
name|RC
block|;
name|assert
argument_list|(
operator|!
name|isImmKind
argument_list|(
name|InputFlag
argument_list|)
operator|&&
literal|"Immediates cannot have a register class"
argument_list|)
block|;
name|assert
argument_list|(
operator|!
name|isMemKind
argument_list|(
name|InputFlag
argument_list|)
operator|&&
literal|"Memory operand cannot have a register class"
argument_list|)
block|;
name|assert
argument_list|(
name|RC
operator|<=
literal|0x7fff
operator|&&
literal|"Too large register class ID"
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|InputFlag
operator|&
operator|~
literal|0xffff
operator|)
operator|==
literal|0
operator|&&
literal|"High bits already contain data"
argument_list|)
block|;
return|return
name|InputFlag
operator||
operator|(
name|RC
operator|<<
literal|16
operator|)
return|;
block|}
comment|/// Augment an existing flag word returned by getFlagWord with the constraint
comment|/// code for a memory constraint.
specifier|static
name|unsigned
name|getFlagWordForMem
argument_list|(
argument|unsigned InputFlag
argument_list|,
argument|unsigned Constraint
argument_list|)
block|{
name|assert
argument_list|(
name|isMemKind
argument_list|(
name|InputFlag
argument_list|)
operator|&&
literal|"InputFlag is not a memory constraint!"
argument_list|)
block|;
name|assert
argument_list|(
name|Constraint
operator|<=
literal|0x7fff
operator|&&
literal|"Too large a memory constraint ID"
argument_list|)
block|;
name|assert
argument_list|(
name|Constraint
operator|<=
name|Constraints_Max
operator|&&
literal|"Unknown constraint ID"
argument_list|)
block|;
name|assert
argument_list|(
operator|(
name|InputFlag
operator|&
operator|~
literal|0xffff
operator|)
operator|==
literal|0
operator|&&
literal|"High bits already contain data"
argument_list|)
block|;
return|return
name|InputFlag
operator||
operator|(
name|Constraint
operator|<<
name|Constraints_ShiftAmount
operator|)
return|;
block|}
specifier|static
name|unsigned
name|convertMemFlagWordToMatchingFlagWord
argument_list|(
argument|unsigned InputFlag
argument_list|)
block|{
name|assert
argument_list|(
name|isMemKind
argument_list|(
name|InputFlag
argument_list|)
argument_list|)
block|;
return|return
name|InputFlag
operator|&
operator|~
operator|(
literal|0x7fff
operator|<<
name|Constraints_ShiftAmount
operator|)
return|;
block|}
specifier|static
name|unsigned
name|getKind
argument_list|(
argument|unsigned Flags
argument_list|)
block|{
return|return
name|Flags
operator|&
literal|7
return|;
block|}
specifier|static
name|unsigned
name|getMemoryConstraintID
argument_list|(
argument|unsigned Flag
argument_list|)
block|{
name|assert
argument_list|(
name|isMemKind
argument_list|(
name|Flag
argument_list|)
argument_list|)
block|;
return|return
operator|(
name|Flag
operator|>>
name|Constraints_ShiftAmount
operator|)
operator|&
literal|0x7fff
return|;
block|}
comment|/// getNumOperandRegisters - Extract the number of registers field from the
comment|/// inline asm operand flag.
specifier|static
name|unsigned
name|getNumOperandRegisters
argument_list|(
argument|unsigned Flag
argument_list|)
block|{
return|return
operator|(
name|Flag
operator|&
literal|0xffff
operator|)
operator|>>
literal|3
return|;
block|}
comment|/// isUseOperandTiedToDef - Return true if the flag of the inline asm
comment|/// operand indicates it is an use operand that's matched to a def operand.
specifier|static
name|bool
name|isUseOperandTiedToDef
argument_list|(
argument|unsigned Flag
argument_list|,
argument|unsigned&Idx
argument_list|)
block|{
if|if
condition|(
operator|(
name|Flag
operator|&
name|Flag_MatchingOperand
operator|)
operator|==
literal|0
condition|)
return|return
name|false
return|;
name|Idx
operator|=
operator|(
name|Flag
operator|&
operator|~
name|Flag_MatchingOperand
operator|)
operator|>>
literal|16
block|;
return|return
name|true
return|;
block|}
comment|/// hasRegClassConstraint - Returns true if the flag contains a register
comment|/// class constraint.  Sets RC to the register class ID.
specifier|static
name|bool
name|hasRegClassConstraint
parameter_list|(
name|unsigned
name|Flag
parameter_list|,
name|unsigned
modifier|&
name|RC
parameter_list|)
block|{
if|if
condition|(
name|Flag
operator|&
name|Flag_MatchingOperand
condition|)
return|return
name|false
return|;
name|unsigned
name|High
init|=
name|Flag
operator|>>
literal|16
decl_stmt|;
comment|// getFlagWordForRegClass() uses 0 to mean no register class, and otherwise
comment|// stores RC + 1.
if|if
condition|(
operator|!
name|High
condition|)
return|return
name|false
return|;
name|RC
operator|=
name|High
operator|-
literal|1
expr_stmt|;
return|return
name|true
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_IR_INLINEASM_H
end_comment

end_unit

