begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- llvm/MC/MCParsedAsmOperand.h - Asm Parser Operand --------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_MC_MCPARSER_MCPARSEDASMOPERAND_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCPARSER_MCPARSEDASMOPERAND_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/SMLoc.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|raw_ostream
decl_stmt|;
comment|/// MCParsedAsmOperand - This abstract class represents a source-level assembly
comment|/// instruction operand.  It should be subclassed by target-specific code.  This
comment|/// base class is used by target-independent clients and is the interface
comment|/// between parsing an asm instruction and recognizing it.
name|class
name|MCParsedAsmOperand
block|{
comment|/// MCOperandNum - The corresponding MCInst operand number.  Only valid when
comment|/// parsing MS-style inline assembly.
name|unsigned
name|MCOperandNum
decl_stmt|;
comment|/// Constraint - The constraint on this operand.  Only valid when parsing
comment|/// MS-style inline assembly.
name|std
operator|::
name|string
name|Constraint
expr_stmt|;
name|protected
label|:
comment|// This only seems to need to be movable (by ARMOperand) but ARMOperand has
comment|// lots of members and MSVC doesn't support defaulted move ops, so to avoid
comment|// that verbosity, just rely on defaulted copy ops. It's only the Constraint
comment|// string member that would benefit from movement anyway.
name|MCParsedAsmOperand
argument_list|()
operator|=
expr|default
expr_stmt|;
name|MCParsedAsmOperand
argument_list|(
specifier|const
name|MCParsedAsmOperand
operator|&
name|RHS
argument_list|)
operator|=
expr|default
expr_stmt|;
name|MCParsedAsmOperand
modifier|&
name|operator
init|=
operator|(
specifier|const
name|MCParsedAsmOperand
operator|&
operator|)
operator|=
expr|default
decl_stmt|;
name|public
label|:
name|virtual
operator|~
name|MCParsedAsmOperand
argument_list|()
operator|=
expr|default
expr_stmt|;
name|void
name|setConstraint
parameter_list|(
name|StringRef
name|C
parameter_list|)
block|{
name|Constraint
operator|=
name|C
operator|.
name|str
argument_list|()
expr_stmt|;
block|}
name|StringRef
name|getConstraint
parameter_list|()
block|{
return|return
name|Constraint
return|;
block|}
name|void
name|setMCOperandNum
parameter_list|(
name|unsigned
name|OpNum
parameter_list|)
block|{
name|MCOperandNum
operator|=
name|OpNum
expr_stmt|;
block|}
name|unsigned
name|getMCOperandNum
parameter_list|()
block|{
return|return
name|MCOperandNum
return|;
block|}
name|virtual
name|StringRef
name|getSymName
parameter_list|()
block|{
return|return
name|StringRef
argument_list|()
return|;
block|}
name|virtual
name|void
modifier|*
name|getOpDecl
parameter_list|()
block|{
return|return
name|nullptr
return|;
block|}
comment|/// isToken - Is this a token operand?
name|virtual
name|bool
name|isToken
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// isImm - Is this an immediate operand?
name|virtual
name|bool
name|isImm
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// isReg - Is this a register operand?
name|virtual
name|bool
name|isReg
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
name|virtual
name|unsigned
name|getReg
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// isMem - Is this a memory operand?
name|virtual
name|bool
name|isMem
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// getStartLoc - Get the location of the first token of this operand.
name|virtual
name|SMLoc
name|getStartLoc
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// getEndLoc - Get the location of the last token of this operand.
name|virtual
name|SMLoc
name|getEndLoc
argument_list|()
specifier|const
operator|=
literal|0
expr_stmt|;
comment|/// needAddressOf - Do we need to emit code to get the address of the
comment|/// variable/label?   Only valid when parsing MS-style inline assembly.
name|virtual
name|bool
name|needAddressOf
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// isOffsetOf - Do we need to emit code to get the offset of the variable,
comment|/// rather then the value of the variable?   Only valid when parsing MS-style
comment|/// inline assembly.
name|virtual
name|bool
name|isOffsetOf
argument_list|()
specifier|const
block|{
return|return
name|false
return|;
block|}
comment|/// getOffsetOfLoc - Get the location of the offset operator.
name|virtual
name|SMLoc
name|getOffsetOfLoc
argument_list|()
specifier|const
block|{
return|return
name|SMLoc
argument_list|()
return|;
block|}
comment|/// print - Print a debug representation of the operand to the given stream.
name|virtual
name|void
name|print
argument_list|(
name|raw_ostream
operator|&
name|OS
argument_list|)
decl|const
init|=
literal|0
decl_stmt|;
comment|/// dump - Print to the debug stream.
name|virtual
name|void
name|dump
argument_list|()
specifier|const
expr_stmt|;
block|}
empty_stmt|;
comment|//===----------------------------------------------------------------------===//
comment|// Debugging Support
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
name|MCParsedAsmOperand
operator|&
name|MO
operator|)
block|{
name|MO
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
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_MC_MCPARSER_MCPARSEDASMOPERAND_H
end_comment

end_unit

