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
name|class
name|InlineAsm
range|:
name|public
name|Value
block|{
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
name|IsMsAsm
block|;
name|InlineAsm
argument_list|(
argument|const FunctionType *Ty
argument_list|,
argument|const StringRef&AsmString
argument_list|,
argument|const StringRef&Constraints
argument_list|,
argument|bool hasSideEffects
argument_list|,
argument|bool isMsAsm = false
argument_list|)
block|;
name|virtual
operator|~
name|InlineAsm
argument_list|()
block|;
name|public
operator|:
comment|/// InlineAsm::get - Return the the specified uniqued inline asm string.
comment|///
specifier|static
name|InlineAsm
operator|*
name|get
argument_list|(
argument|const FunctionType *Ty
argument_list|,
argument|const StringRef&AsmString
argument_list|,
argument|const StringRef&Constraints
argument_list|,
argument|bool hasSideEffects
argument_list|,
argument|bool isMsAsm = false
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
name|isMsAsm
argument_list|()
specifier|const
block|{
return|return
name|IsMsAsm
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
specifier|const
name|FunctionType
operator|*
name|Ty
argument_list|,
specifier|const
name|StringRef
operator|&
name|Constraints
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
block|;      struct
name|ConstraintInfo
block|{
comment|/// Type - The basic type of the constraint: input/output/clobber
comment|///
name|ConstraintPrefix
name|Type
block|;
comment|/// isEarlyClobber - "&": output operand writes result before inputs are all
comment|/// read.  This is only ever set for an output operand.
name|bool
name|isEarlyClobber
block|;
comment|/// MatchingInput - If this is not -1, this is an output constraint where an
comment|/// input constraint is required to match it (e.g. "0").  The value is the
comment|/// constraint number that matches this one (for example, if this is
comment|/// constraint #0 and constraint #4 has the value "0", this will be 4).
name|signed
name|char
name|MatchingInput
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
block|;
comment|/// isIndirect - True if this operand is an indirect operand.  This means
comment|/// that the address of the source or destination is present in the call
comment|/// instruction, instead of it being returned or passed in explicitly.  This
comment|/// is represented with a '*' in the asm string.
name|bool
name|isIndirect
block|;
comment|/// Code - The constraint code, either the register name (in braces) or the
comment|/// constraint letter/number.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|string
operator|>
name|Codes
block|;
comment|/// Parse - Analyze the specified string (e.g. "=*&{eax}") and fill in the
comment|/// fields in this structure.  If the constraint string is not understood,
comment|/// return true, otherwise return false.
name|bool
name|Parse
argument_list|(
specifier|const
name|StringRef
operator|&
name|Str
argument_list|,
name|std
operator|::
name|vector
operator|<
name|InlineAsm
operator|::
name|ConstraintInfo
operator|>
operator|&
name|ConstraintsSoFar
argument_list|)
block|;   }
block|;
comment|/// ParseConstraints - Split up the constraint string into the specific
comment|/// constraints and their prefixes.  If this returns an empty vector, and if
comment|/// the constraint string itself isn't empty, there was an error parsing.
specifier|static
name|std
operator|::
name|vector
operator|<
name|ConstraintInfo
operator|>
name|ParseConstraints
argument_list|(
specifier|const
name|StringRef
operator|&
name|ConstraintString
argument_list|)
block|;
comment|/// ParseConstraints - Parse the constraints of this inlineasm object,
comment|/// returning them the same way that ParseConstraints(str) does.
name|std
operator|::
name|vector
operator|<
name|ConstraintInfo
operator|>
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
argument_list|(
argument|const InlineAsm *
argument_list|)
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
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
literal|0x80000000
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
literal|0x80000000
operator|)
operator|>>
literal|16
block|;
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

