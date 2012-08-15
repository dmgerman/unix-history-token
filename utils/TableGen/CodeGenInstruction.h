begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CodeGenInstruction.h - Instruction Class Wrapper ---------*- C++ -*-===//
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
comment|// This file defines a wrapper class for the 'Instruction' TableGen class.
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
name|CODEGEN_INSTRUCTION_H
end_ifndef

begin_define
define|#
directive|define
name|CODEGEN_INSTRUCTION_H
end_define

begin_include
include|#
directive|include
file|"llvm/CodeGen/ValueTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SourceMgr.h"
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
name|Record
decl_stmt|;
name|class
name|DagInit
decl_stmt|;
name|class
name|CodeGenTarget
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|CGIOperandList
block|{
name|public
label|:
name|class
name|ConstraintInfo
block|{
enum|enum
block|{
name|None
block|,
name|EarlyClobber
block|,
name|Tied
block|}
name|Kind
enum|;
name|unsigned
name|OtherTiedOperand
decl_stmt|;
name|public
label|:
name|ConstraintInfo
argument_list|()
operator|:
name|Kind
argument_list|(
argument|None
argument_list|)
block|{}
specifier|static
name|ConstraintInfo
name|getEarlyClobber
argument_list|()
block|{
name|ConstraintInfo
name|I
block|;
name|I
operator|.
name|Kind
operator|=
name|EarlyClobber
block|;
name|I
operator|.
name|OtherTiedOperand
operator|=
literal|0
block|;
return|return
name|I
return|;
block|}
specifier|static
name|ConstraintInfo
name|getTied
parameter_list|(
name|unsigned
name|Op
parameter_list|)
block|{
name|ConstraintInfo
name|I
decl_stmt|;
name|I
operator|.
name|Kind
operator|=
name|Tied
expr_stmt|;
name|I
operator|.
name|OtherTiedOperand
operator|=
name|Op
expr_stmt|;
return|return
name|I
return|;
block|}
name|bool
name|isNone
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|None
return|;
block|}
name|bool
name|isEarlyClobber
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|EarlyClobber
return|;
block|}
name|bool
name|isTied
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|Tied
return|;
block|}
name|unsigned
name|getTiedOperand
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isTied
argument_list|()
argument_list|)
block|;
return|return
name|OtherTiedOperand
return|;
block|}
block|}
empty_stmt|;
comment|/// OperandInfo - The information we keep track of for each operand in the
comment|/// operand list for a tablegen instruction.
struct|struct
name|OperandInfo
block|{
comment|/// Rec - The definition this operand is declared as.
comment|///
name|Record
modifier|*
name|Rec
decl_stmt|;
comment|/// Name - If this operand was assigned a symbolic name, this is it,
comment|/// otherwise, it's empty.
name|std
operator|::
name|string
name|Name
expr_stmt|;
comment|/// PrinterMethodName - The method used to print operands of this type in
comment|/// the asmprinter.
name|std
operator|::
name|string
name|PrinterMethodName
expr_stmt|;
comment|/// EncoderMethodName - The method used to get the machine operand value
comment|/// for binary encoding. "getMachineOpValue" by default.
name|std
operator|::
name|string
name|EncoderMethodName
expr_stmt|;
comment|/// OperandType - A value from MCOI::OperandType representing the type of
comment|/// the operand.
name|std
operator|::
name|string
name|OperandType
expr_stmt|;
comment|/// MIOperandNo - Currently (this is meant to be phased out), some logical
comment|/// operands correspond to multiple MachineInstr operands.  In the X86
comment|/// target for example, one address operand is represented as 4
comment|/// MachineOperands.  Because of this, the operand number in the
comment|/// OperandList may not match the MachineInstr operand num.  Until it
comment|/// does, this contains the MI operand index of this operand.
name|unsigned
name|MIOperandNo
decl_stmt|;
name|unsigned
name|MINumOperands
decl_stmt|;
comment|// The number of operands.
comment|/// DoNotEncode - Bools are set to true in this vector for each operand in
comment|/// the DisableEncoding list.  These should not be emitted by the code
comment|/// emitter.
name|std
operator|::
name|vector
operator|<
name|bool
operator|>
name|DoNotEncode
expr_stmt|;
comment|/// MIOperandInfo - Default MI operand type. Note an operand may be made
comment|/// up of multiple MI operands.
name|DagInit
modifier|*
name|MIOperandInfo
decl_stmt|;
comment|/// Constraint info for this operand.  This operand can have pieces, so we
comment|/// track constraint info for each.
name|std
operator|::
name|vector
operator|<
name|ConstraintInfo
operator|>
name|Constraints
expr_stmt|;
name|OperandInfo
argument_list|(
argument|Record *R
argument_list|,
argument|const std::string&N
argument_list|,
argument|const std::string&PMN
argument_list|,
argument|const std::string&EMN
argument_list|,
argument|const std::string&OT
argument_list|,
argument|unsigned MION
argument_list|,
argument|unsigned MINO
argument_list|,
argument|DagInit *MIOI
argument_list|)
block|:
name|Rec
argument_list|(
name|R
argument_list|)
operator|,
name|Name
argument_list|(
name|N
argument_list|)
operator|,
name|PrinterMethodName
argument_list|(
name|PMN
argument_list|)
operator|,
name|EncoderMethodName
argument_list|(
name|EMN
argument_list|)
operator|,
name|OperandType
argument_list|(
name|OT
argument_list|)
operator|,
name|MIOperandNo
argument_list|(
name|MION
argument_list|)
operator|,
name|MINumOperands
argument_list|(
name|MINO
argument_list|)
operator|,
name|MIOperandInfo
argument_list|(
argument|MIOI
argument_list|)
block|{}
comment|/// getTiedOperand - If this operand is tied to another one, return the
comment|/// other operand number.  Otherwise, return -1.
name|int
name|getTiedRegister
argument_list|()
specifier|const
block|{
for|for
control|(
name|unsigned
name|j
init|=
literal|0
init|,
name|e
init|=
name|Constraints
operator|.
name|size
argument_list|()
init|;
name|j
operator|!=
name|e
condition|;
operator|++
name|j
control|)
block|{
specifier|const
name|CGIOperandList
operator|::
name|ConstraintInfo
operator|&
name|CI
operator|=
name|Constraints
index|[
name|j
index|]
expr_stmt|;
if|if
condition|(
name|CI
operator|.
name|isTied
argument_list|()
condition|)
return|return
name|CI
operator|.
name|getTiedOperand
argument_list|()
return|;
block|}
return|return
operator|-
literal|1
return|;
block|}
block|}
struct|;
name|CGIOperandList
argument_list|(
name|Record
operator|*
name|D
argument_list|)
expr_stmt|;
name|Record
modifier|*
name|TheDef
decl_stmt|;
comment|// The actual record containing this OperandList.
comment|/// NumDefs - Number of def operands declared, this is the number of
comment|/// elements in the instruction's (outs) list.
comment|///
name|unsigned
name|NumDefs
decl_stmt|;
comment|/// OperandList - The list of declared operands, along with their declared
comment|/// type (which is a record).
name|std
operator|::
name|vector
operator|<
name|OperandInfo
operator|>
name|OperandList
expr_stmt|;
comment|// Information gleaned from the operand list.
name|bool
name|isPredicable
decl_stmt|;
name|bool
name|hasOptionalDef
decl_stmt|;
name|bool
name|isVariadic
decl_stmt|;
comment|// Provide transparent accessors to the operand list.
name|bool
name|empty
argument_list|()
specifier|const
block|{
return|return
name|OperandList
operator|.
name|empty
argument_list|()
return|;
block|}
name|unsigned
name|size
argument_list|()
specifier|const
block|{
return|return
name|OperandList
operator|.
name|size
argument_list|()
return|;
block|}
specifier|const
name|OperandInfo
modifier|&
name|operator
index|[]
argument_list|(
name|unsigned
name|i
argument_list|)
decl|const
block|{
return|return
name|OperandList
index|[
name|i
index|]
return|;
block|}
name|OperandInfo
modifier|&
name|operator
function|[]
parameter_list|(
name|unsigned
name|i
parameter_list|)
block|{
return|return
name|OperandList
index|[
name|i
index|]
return|;
block|}
name|OperandInfo
modifier|&
name|back
parameter_list|()
block|{
return|return
name|OperandList
operator|.
name|back
argument_list|()
return|;
block|}
specifier|const
name|OperandInfo
operator|&
name|back
argument_list|()
specifier|const
block|{
return|return
name|OperandList
operator|.
name|back
argument_list|()
return|;
block|}
comment|/// getOperandNamed - Return the index of the operand with the specified
comment|/// non-empty name.  If the instruction does not have an operand with the
comment|/// specified name, throw an exception.
name|unsigned
name|getOperandNamed
argument_list|(
name|StringRef
name|Name
argument_list|)
decl|const
decl_stmt|;
comment|/// hasOperandNamed - Query whether the instruction has an operand of the
comment|/// given name. If so, return true and set OpIdx to the index of the
comment|/// operand. Otherwise, return false.
name|bool
name|hasOperandNamed
argument_list|(
name|StringRef
name|Name
argument_list|,
name|unsigned
operator|&
name|OpIdx
argument_list|)
decl|const
decl_stmt|;
comment|/// ParseOperandName - Parse an operand name like "$foo" or "$foo.bar",
comment|/// where $foo is a whole operand and $foo.bar refers to a suboperand.
comment|/// This throws an exception if the name is invalid.  If AllowWholeOp is
comment|/// true, references to operands with suboperands are allowed, otherwise
comment|/// not.
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|ParseOperandName
argument_list|(
argument|const std::string&Op
argument_list|,
argument|bool AllowWholeOp = true
argument_list|)
expr_stmt|;
comment|/// getFlattenedOperandNumber - Flatten a operand/suboperand pair into a
comment|/// flat machineinstr operand #.
name|unsigned
name|getFlattenedOperandNumber
argument_list|(
name|std
operator|::
name|pair
operator|<
name|unsigned
argument_list|,
name|unsigned
operator|>
name|Op
argument_list|)
decl|const
block|{
return|return
name|OperandList
index|[
name|Op
operator|.
name|first
index|]
operator|.
name|MIOperandNo
operator|+
name|Op
operator|.
name|second
return|;
block|}
comment|/// getSubOperandNumber - Unflatten a operand number into an
comment|/// operand/suboperand pair.
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|getSubOperandNumber
argument_list|(
argument|unsigned Op
argument_list|)
specifier|const
block|{
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
condition|;
operator|++
name|i
control|)
block|{
name|assert
argument_list|(
name|i
operator|<
name|OperandList
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid flat operand #"
argument_list|)
expr_stmt|;
if|if
condition|(
name|OperandList
index|[
name|i
index|]
operator|.
name|MIOperandNo
operator|+
name|OperandList
index|[
name|i
index|]
operator|.
name|MINumOperands
operator|>
name|Op
condition|)
return|return
name|std
operator|::
name|make_pair
argument_list|(
name|i
argument_list|,
name|Op
operator|-
name|OperandList
index|[
name|i
index|]
operator|.
name|MIOperandNo
argument_list|)
return|;
block|}
block|}
comment|/// isFlatOperandNotEmitted - Return true if the specified flat operand #
comment|/// should not be emitted with the code emitter.
name|bool
name|isFlatOperandNotEmitted
argument_list|(
argument|unsigned FlatOpNo
argument_list|)
specifier|const
block|{
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|unsigned
operator|>
name|Op
operator|=
name|getSubOperandNumber
argument_list|(
name|FlatOpNo
argument_list|)
block|;
if|if
condition|(
name|OperandList
index|[
name|Op
operator|.
name|first
index|]
operator|.
name|DoNotEncode
operator|.
name|size
argument_list|()
operator|>
name|Op
operator|.
name|second
condition|)
return|return
name|OperandList
index|[
name|Op
operator|.
name|first
index|]
operator|.
name|DoNotEncode
index|[
name|Op
operator|.
name|second
index|]
return|;
return|return
name|false
return|;
block|}
name|void
name|ProcessDisableEncoding
argument_list|(
name|std
operator|::
name|string
name|Value
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|CodeGenInstruction
block|{
name|public
label|:
name|Record
modifier|*
name|TheDef
decl_stmt|;
comment|// The actual record defining this instruction.
name|std
operator|::
name|string
name|Namespace
expr_stmt|;
comment|// The namespace the instruction is in.
comment|/// AsmString - The format string used to emit a .s file for the
comment|/// instruction.
name|std
operator|::
name|string
name|AsmString
expr_stmt|;
comment|/// Operands - This is information about the (ins) and (outs) list specified
comment|/// to the instruction.
name|CGIOperandList
name|Operands
decl_stmt|;
comment|/// ImplicitDefs/ImplicitUses - These are lists of registers that are
comment|/// implicitly defined and used by the instruction.
name|std
operator|::
name|vector
operator|<
name|Record
operator|*
operator|>
name|ImplicitDefs
operator|,
name|ImplicitUses
expr_stmt|;
comment|// Various boolean values we track for the instruction.
name|bool
name|isReturn
decl_stmt|;
name|bool
name|isBranch
decl_stmt|;
name|bool
name|isIndirectBranch
decl_stmt|;
name|bool
name|isCompare
decl_stmt|;
name|bool
name|isMoveImm
decl_stmt|;
name|bool
name|isBitcast
decl_stmt|;
name|bool
name|isBarrier
decl_stmt|;
name|bool
name|isCall
decl_stmt|;
name|bool
name|canFoldAsLoad
decl_stmt|;
name|bool
name|mayLoad
decl_stmt|,
name|mayStore
decl_stmt|;
name|bool
name|isPredicable
decl_stmt|;
name|bool
name|isConvertibleToThreeAddress
decl_stmt|;
name|bool
name|isCommutable
decl_stmt|;
name|bool
name|isTerminator
decl_stmt|;
name|bool
name|isReMaterializable
decl_stmt|;
name|bool
name|hasDelaySlot
decl_stmt|;
name|bool
name|usesCustomInserter
decl_stmt|;
name|bool
name|hasPostISelHook
decl_stmt|;
name|bool
name|hasCtrlDep
decl_stmt|;
name|bool
name|isNotDuplicable
decl_stmt|;
name|bool
name|hasSideEffects
decl_stmt|;
name|bool
name|neverHasSideEffects
decl_stmt|;
name|bool
name|isAsCheapAsAMove
decl_stmt|;
name|bool
name|hasExtraSrcRegAllocReq
decl_stmt|;
name|bool
name|hasExtraDefRegAllocReq
decl_stmt|;
name|bool
name|isCodeGenOnly
decl_stmt|;
name|bool
name|isPseudo
decl_stmt|;
name|CodeGenInstruction
argument_list|(
name|Record
operator|*
name|R
argument_list|)
expr_stmt|;
comment|/// HasOneImplicitDefWithKnownVT - If the instruction has at least one
comment|/// implicit def and it has a known VT, return the VT, otherwise return
comment|/// MVT::Other.
name|MVT
operator|::
name|SimpleValueType
name|HasOneImplicitDefWithKnownVT
argument_list|(
argument|const CodeGenTarget&TargetInfo
argument_list|)
specifier|const
expr_stmt|;
comment|/// FlattenAsmStringVariants - Flatten the specified AsmString to only
comment|/// include text from the specified variant, returning the new string.
specifier|static
name|std
operator|::
name|string
name|FlattenAsmStringVariants
argument_list|(
argument|StringRef AsmString
argument_list|,
argument|unsigned Variant
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// CodeGenInstAlias - This represents an InstAlias definition.
end_comment

begin_decl_stmt
name|class
name|CodeGenInstAlias
block|{
name|public
label|:
name|Record
modifier|*
name|TheDef
decl_stmt|;
comment|// The actual record defining this InstAlias.
comment|/// AsmString - The format string used to emit a .s file for the
comment|/// instruction.
name|std
operator|::
name|string
name|AsmString
expr_stmt|;
comment|/// Result - The result instruction.
name|DagInit
modifier|*
name|Result
decl_stmt|;
comment|/// ResultInst - The instruction generated by the alias (decoded from
comment|/// Result).
name|CodeGenInstruction
modifier|*
name|ResultInst
decl_stmt|;
struct|struct
name|ResultOperand
block|{
name|private
label|:
name|std
operator|::
name|string
name|Name
expr_stmt|;
name|Record
modifier|*
name|R
decl_stmt|;
name|int64_t
name|Imm
decl_stmt|;
name|public
label|:
enum|enum
block|{
name|K_Record
block|,
name|K_Imm
block|,
name|K_Reg
block|}
name|Kind
enum|;
name|ResultOperand
argument_list|(
argument|std::string N
argument_list|,
argument|Record *r
argument_list|)
block|:
name|Name
argument_list|(
name|N
argument_list|)
operator|,
name|R
argument_list|(
name|r
argument_list|)
operator|,
name|Kind
argument_list|(
argument|K_Record
argument_list|)
block|{}
name|ResultOperand
argument_list|(
argument|int64_t I
argument_list|)
operator|:
name|Imm
argument_list|(
name|I
argument_list|)
operator|,
name|Kind
argument_list|(
argument|K_Imm
argument_list|)
block|{}
name|ResultOperand
argument_list|(
name|Record
operator|*
name|r
argument_list|)
operator|:
name|R
argument_list|(
name|r
argument_list|)
operator|,
name|Kind
argument_list|(
argument|K_Reg
argument_list|)
block|{}
name|bool
name|isRecord
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|K_Record
return|;
block|}
name|bool
name|isImm
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|K_Imm
return|;
block|}
name|bool
name|isReg
argument_list|()
specifier|const
block|{
return|return
name|Kind
operator|==
name|K_Reg
return|;
block|}
name|StringRef
name|getName
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isRecord
argument_list|()
argument_list|)
block|;
return|return
name|Name
return|;
block|}
name|Record
operator|*
name|getRecord
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isRecord
argument_list|()
argument_list|)
block|;
return|return
name|R
return|;
block|}
name|int64_t
name|getImm
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isImm
argument_list|()
argument_list|)
block|;
return|return
name|Imm
return|;
block|}
name|Record
operator|*
name|getRegister
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isReg
argument_list|()
argument_list|)
block|;
return|return
name|R
return|;
block|}
block|}
struct|;
comment|/// ResultOperands - The decoded operands for the result instruction.
name|std
operator|::
name|vector
operator|<
name|ResultOperand
operator|>
name|ResultOperands
expr_stmt|;
comment|/// ResultInstOperandIndex - For each operand, this vector holds a pair of
comment|/// indices to identify the corresponding operand in the result
comment|/// instruction.  The first index specifies the operand and the second
comment|/// index specifies the suboperand.  If there are no suboperands or if all
comment|/// of them are matched by the operand, the second value should be -1.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|int
operator|>
expr|>
name|ResultInstOperandIndex
expr_stmt|;
name|CodeGenInstAlias
argument_list|(
name|Record
operator|*
name|R
argument_list|,
name|CodeGenTarget
operator|&
name|T
argument_list|)
expr_stmt|;
name|bool
name|tryAliasOpMatch
parameter_list|(
name|DagInit
modifier|*
name|Result
parameter_list|,
name|unsigned
name|AliasOpNo
parameter_list|,
name|Record
modifier|*
name|InstOpRec
parameter_list|,
name|bool
name|hasSubOps
parameter_list|,
name|SMLoc
name|Loc
parameter_list|,
name|CodeGenTarget
modifier|&
name|T
parameter_list|,
name|ResultOperand
modifier|&
name|ResOp
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

