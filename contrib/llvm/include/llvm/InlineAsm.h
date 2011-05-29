begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/InlineAsm.h - Class to represent inline asm strings-*- C++ -*-===//
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
name|LLVM_INLINEASM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_INLINEASM_H
end_define

begin_include
include|#
directive|include
file|"llvm/Value.h"
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
name|PointerType
decl_stmt|;
name|class
name|FunctionType
decl_stmt|;
name|class
name|Module
decl_stmt|;
struct_decl|struct
name|InlineAsmKeyType
struct_decl|;
name|template
operator|<
name|class
name|ValType
operator|,
name|class
name|TypeClass
operator|,
name|class
name|ConstantClass
operator|,
name|bool
name|HasLargeKey
operator|>
name|class
name|ConstantUniqueMap
expr_stmt|;
name|template
operator|<
name|class
name|ConstantClass
operator|,
name|class
name|TypeClass
operator|,
name|class
name|ValType
operator|>
expr|struct
name|ConstantCreator
expr_stmt|;
name|class
name|InlineAsm
range|:
name|public
name|Value
block|{
name|friend
expr|struct
name|ConstantCreator
operator|<
name|InlineAsm
block|,
name|PointerType
block|,
name|InlineAsmKeyType
operator|>
block|;
name|friend
name|class
name|ConstantUniqueMap
operator|<
name|InlineAsmKeyType
block|,
name|PointerType
block|,
name|InlineAsm
block|,
name|false
operator|>
block|;
name|InlineAsm
argument_list|(
specifier|const
name|InlineAsm
operator|&
argument_list|)
block|;
comment|// do not implement
name|void
name|operator
operator|=
operator|(
specifier|const
name|InlineAsm
operator|&
operator|)
block|;
comment|// do not implement
name|std
operator|::
name|string
name|AsmString
block|,
name|Constraints
block|;
name|bool
name|HasSideEffects
block|;
name|bool
name|IsAlignStack
block|;
name|InlineAsm
argument_list|(
argument|const PointerType *Ty
argument_list|,
argument|const std::string&AsmString
argument_list|,
argument|const std::string&Constraints
argument_list|,
argument|bool hasSideEffects
argument_list|,
argument|bool isAlignStack
argument_list|)
block|;
name|virtual
operator|~
name|InlineAsm
argument_list|()
block|;
comment|/// When the ConstantUniqueMap merges two types and makes two InlineAsms
comment|/// identical, it destroys one of them with this method.
name|void
name|destroyConstant
argument_list|()
block|;
name|public
operator|:
comment|/// InlineAsm::get - Return the specified uniqued inline asm string.
comment|///
specifier|static
name|InlineAsm
operator|*
name|get
argument_list|(
argument|const FunctionType *Ty
argument_list|,
argument|StringRef AsmString
argument_list|,
argument|StringRef Constraints
argument_list|,
argument|bool hasSideEffects
argument_list|,
argument|bool isAlignStack = false
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
comment|/// getType - InlineAsm's are always pointers.
comment|///
specifier|const
name|PointerType
operator|*
name|getType
argument_list|()
specifier|const
block|{
return|return
name|reinterpret_cast
operator|<
specifier|const
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
specifier|const
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
argument|const FunctionType *Ty
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
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|ConstraintCodeVector
expr_stmt|;
block|struct
name|SubConstraintInfo
block|{
comment|/// MatchingInput - If this is not -1, this is an output constraint where an
comment|/// input constraint is required to match it (e.g. "0").  The value is the
comment|/// constraint number that matches this one (for example, if this is
comment|/// constraint #0 and constraint #4 has the value "0", this will be 4).
name|signed
name|char
name|MatchingInput
block|;
comment|/// Code - The constraint code, either the register name (in braces) or the
comment|/// constraint letter/number.
name|ConstraintCodeVector
name|Codes
block|;
comment|/// Default constructor.
name|SubConstraintInfo
argument_list|()
operator|:
name|MatchingInput
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
block|}
decl_stmt|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|SubConstraintInfo
operator|>
name|SubConstraintInfoVector
expr_stmt|;
struct_decl|struct
name|ConstraintInfo
struct_decl|;
typedef|typedef
name|std
operator|::
name|vector
operator|<
name|ConstraintInfo
operator|>
name|ConstraintInfoVector
expr_stmt|;
struct|struct
name|ConstraintInfo
block|{
comment|/// Type - The basic type of the constraint: input/output/clobber
comment|///
name|ConstraintPrefix
name|Type
decl_stmt|;
comment|/// isEarlyClobber - "&": output operand writes result before inputs are all
comment|/// read.  This is only ever set for an output operand.
name|bool
name|isEarlyClobber
decl_stmt|;
comment|/// MatchingInput - If this is not -1, this is an output constraint where an
comment|/// input constraint is required to match it (e.g. "0").  The value is the
comment|/// constraint number that matches this one (for example, if this is
comment|/// constraint #0 and constraint #4 has the value "0", this will be 4).
name|signed
name|char
name|MatchingInput
decl_stmt|;
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
decl_stmt|;
comment|/// isIndirect - True if this operand is an indirect operand.  This means
comment|/// that the address of the source or destination is present in the call
comment|/// instruction, instead of it being returned or passed in explicitly.  This
comment|/// is represented with a '*' in the asm string.
name|bool
name|isIndirect
decl_stmt|;
comment|/// Code - The constraint code, either the register name (in braces) or the
comment|/// constraint letter/number.
name|ConstraintCodeVector
name|Codes
decl_stmt|;
comment|/// isMultipleAlternative - '|': has multiple-alternative constraints.
name|bool
name|isMultipleAlternative
decl_stmt|;
comment|/// multipleAlternatives - If there are multiple alternative constraints,
comment|/// this array will contain them.  Otherwise it will be empty.
name|SubConstraintInfoVector
name|multipleAlternatives
decl_stmt|;
comment|/// The currently selected alternative constraint index.
name|unsigned
name|currentAlternativeIndex
decl_stmt|;
comment|///Default constructor.
name|ConstraintInfo
argument_list|()
expr_stmt|;
comment|/// Copy constructor.
name|ConstraintInfo
argument_list|(
specifier|const
name|ConstraintInfo
operator|&
name|other
argument_list|)
expr_stmt|;
comment|/// Parse - Analyze the specified string (e.g. "=*&{eax}") and fill in the
comment|/// fields in this structure.  If the constraint string is not understood,
comment|/// return true, otherwise return false.
name|bool
name|Parse
parameter_list|(
name|StringRef
name|Str
parameter_list|,
name|ConstraintInfoVector
modifier|&
name|ConstraintsSoFar
parameter_list|)
function_decl|;
comment|/// selectAlternative - Point this constraint to the alternative constraint
comment|/// indicated by the index.
name|void
name|selectAlternative
parameter_list|(
name|unsigned
name|index
parameter_list|)
function_decl|;
block|}
struct|;
comment|/// ParseConstraints - Split up the constraint string into the specific
comment|/// constraints and their prefixes.  If this returns an empty vector, and if
comment|/// the constraint string itself isn't empty, there was an error parsing.
specifier|static
name|ConstraintInfoVector
name|ParseConstraints
parameter_list|(
name|StringRef
name|ConstraintString
parameter_list|)
function_decl|;
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
specifier|inline
name|bool
name|classof
parameter_list|(
specifier|const
name|InlineAsm
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|bool
name|classof
parameter_list|(
specifier|const
name|Value
modifier|*
name|V
parameter_list|)
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
enum|enum
block|{
name|Op_InputChain
init|=
literal|0
block|,
name|Op_AsmString
init|=
literal|1
block|,
name|Op_MDNode
init|=
literal|2
block|,
name|Op_ExtraInfo
init|=
literal|3
block|,
comment|// HasSideEffects, IsAlignStack
name|Op_FirstOperand
init|=
literal|4
block|,
name|MIOp_AsmString
init|=
literal|0
block|,
name|MIOp_ExtraInfo
init|=
literal|1
block|,
comment|// HasSideEffects, IsAlignStack
name|MIOp_FirstOperand
init|=
literal|2
block|,
name|Extra_HasSideEffects
init|=
literal|1
block|,
name|Extra_IsAlignStack
init|=
literal|2
block|,
name|Kind_RegUse
init|=
literal|1
block|,
name|Kind_RegDef
init|=
literal|2
block|,
name|Kind_Imm
init|=
literal|3
block|,
name|Kind_Mem
init|=
literal|4
block|,
name|Kind_RegDefEarlyClobber
init|=
literal|6
block|,
name|Flag_MatchingOperand
init|=
literal|0x80000000
block|}
enum|;
specifier|static
name|unsigned
name|getFlagWord
parameter_list|(
name|unsigned
name|Kind
parameter_list|,
name|unsigned
name|NumOps
parameter_list|)
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
expr_stmt|;
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
comment|/// getFlagWordForMatchingOp - Augment an existing flag word returned by
comment|/// getFlagWord with information indicating that this input operand is tied
comment|/// to a previous output operand.
specifier|static
name|unsigned
name|getFlagWordForMatchingOp
parameter_list|(
name|unsigned
name|InputFlag
parameter_list|,
name|unsigned
name|MatchedOperandNo
parameter_list|)
block|{
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
specifier|static
name|unsigned
name|getKind
parameter_list|(
name|unsigned
name|Flags
parameter_list|)
block|{
return|return
name|Flags
operator|&
literal|7
return|;
block|}
specifier|static
name|bool
name|isRegDefKind
parameter_list|(
name|unsigned
name|Flag
parameter_list|)
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
parameter_list|(
name|unsigned
name|Flag
parameter_list|)
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
parameter_list|(
name|unsigned
name|Flag
parameter_list|)
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
parameter_list|(
name|unsigned
name|Flag
parameter_list|)
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
comment|/// getNumOperandRegisters - Extract the number of registers field from the
comment|/// inline asm operand flag.
specifier|static
name|unsigned
name|getNumOperandRegisters
parameter_list|(
name|unsigned
name|Flag
parameter_list|)
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
parameter_list|(
name|unsigned
name|Flag
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
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
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

