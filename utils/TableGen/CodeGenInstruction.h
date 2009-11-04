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
name|std
operator|::
name|string
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
block|}
struct|;
comment|/// NumDefs - Number of def operands declared.
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
name|isVariadic
decl_stmt|;
name|bool
name|hasCtrlDep
decl_stmt|;
name|bool
name|isNotDuplicable
decl_stmt|;
name|bool
name|hasOptionalDef
decl_stmt|;
name|bool
name|hasSideEffects
decl_stmt|;
name|bool
name|mayHaveSideEffects
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
name|CodeGenInstruction
argument_list|(
name|Record
operator|*
name|R
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|AsmStr
argument_list|)
expr_stmt|;
comment|/// getOperandNamed - Return the index of the operand with the specified
comment|/// non-empty name.  If the instruction does not have an operand with the
comment|/// specified name, throw an exception.
name|unsigned
name|getOperandNamed
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
decl|const
decl_stmt|;
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

