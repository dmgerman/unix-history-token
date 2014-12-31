begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AsmWriterInst.h - Classes encapsulating a printable inst -*- C++ -*-===//
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
comment|// These classes implement a parser for assembly strings.  The parser splits
end_comment

begin_comment
comment|// the string into operands, which can be literal strings (the constant bits of
end_comment

begin_comment
comment|// the string), actual operands (i.e., operands from the MachineInstr), and
end_comment

begin_comment
comment|// dynamically-generated text, specified by raw C++ code.
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
name|ASMWRITER_INST_H
end_ifndef

begin_define
define|#
directive|define
name|ASMWRITER_INST_H
end_define

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
name|CodeGenInstruction
decl_stmt|;
name|class
name|Record
decl_stmt|;
struct|struct
name|AsmWriterOperand
block|{
enum|enum
name|OpType
block|{
comment|// Output this text surrounded by quotes to the asm.
name|isLiteralTextOperand
block|,
comment|// This is the name of a routine to call to print the operand.
name|isMachineInstrOperand
block|,
comment|// Output this text verbatim to the asm writer.  It is code that
comment|// will output some text to the asm.
name|isLiteralStatementOperand
block|}
name|OperandType
enum|;
comment|/// Str - For isLiteralTextOperand, this IS the literal text.  For
comment|/// isMachineInstrOperand, this is the PrinterMethodName for the operand..
comment|/// For isLiteralStatementOperand, this is the code to insert verbatim
comment|/// into the asm writer.
name|std
operator|::
name|string
name|Str
expr_stmt|;
comment|/// CGIOpNo - For isMachineInstrOperand, this is the index of the operand in
comment|/// the CodeGenInstruction.
name|unsigned
name|CGIOpNo
decl_stmt|;
comment|/// MiOpNo - For isMachineInstrOperand, this is the operand number of the
comment|/// machine instruction.
name|unsigned
name|MIOpNo
decl_stmt|;
comment|/// MiModifier - For isMachineInstrOperand, this is the modifier string for
comment|/// an operand, specified with syntax like ${opname:modifier}.
name|std
operator|::
name|string
name|MiModifier
expr_stmt|;
comment|// To make VS STL happy
name|AsmWriterOperand
argument_list|(
argument|OpType op = isLiteralTextOperand
argument_list|)
block|:
name|OperandType
argument_list|(
argument|op
argument_list|)
block|{}
name|AsmWriterOperand
argument_list|(
argument|const std::string&LitStr
argument_list|,
argument|OpType op = isLiteralTextOperand
argument_list|)
block|:
name|OperandType
argument_list|(
name|op
argument_list|)
operator|,
name|Str
argument_list|(
argument|LitStr
argument_list|)
block|{}
name|AsmWriterOperand
argument_list|(
argument|const std::string&Printer
argument_list|,
argument|unsigned _CGIOpNo
argument_list|,
argument|unsigned _MIOpNo
argument_list|,
argument|const std::string&Modifier
argument_list|,
argument|OpType op = isMachineInstrOperand
argument_list|)
operator|:
name|OperandType
argument_list|(
name|op
argument_list|)
operator|,
name|Str
argument_list|(
name|Printer
argument_list|)
operator|,
name|CGIOpNo
argument_list|(
name|_CGIOpNo
argument_list|)
operator|,
name|MIOpNo
argument_list|(
name|_MIOpNo
argument_list|)
operator|,
name|MiModifier
argument_list|(
argument|Modifier
argument_list|)
block|{}
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|AsmWriterOperand
operator|&
name|Other
operator|)
specifier|const
block|{
if|if
condition|(
name|OperandType
operator|!=
name|Other
operator|.
name|OperandType
operator|||
name|Str
operator|!=
name|Other
operator|.
name|Str
condition|)
return|return
name|true
return|;
if|if
condition|(
name|OperandType
operator|==
name|isMachineInstrOperand
condition|)
return|return
name|MIOpNo
operator|!=
name|Other
operator|.
name|MIOpNo
operator|||
name|MiModifier
operator|!=
name|Other
operator|.
name|MiModifier
return|;
return|return
name|false
return|;
block|}
name|bool
name|operator
decl|==
argument_list|(
specifier|const
name|AsmWriterOperand
operator|&
name|Other
argument_list|)
decl|const
block|{
return|return
operator|!
name|operator
operator|!=
operator|(
name|Other
operator|)
return|;
block|}
comment|/// getCode - Return the code that prints this operand.
name|std
decl|::
name|string
name|getCode
argument_list|()
decl|const
struct|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|AsmWriterInst
block|{
name|public
label|:
name|std
operator|::
name|vector
operator|<
name|AsmWriterOperand
operator|>
name|Operands
expr_stmt|;
specifier|const
name|CodeGenInstruction
modifier|*
name|CGI
decl_stmt|;
name|AsmWriterInst
argument_list|(
argument|const CodeGenInstruction&CGI
argument_list|,
argument|unsigned Variant
argument_list|,
argument|int OperandSpacing
argument_list|)
empty_stmt|;
comment|/// MatchesAllButOneOp - If this instruction is exactly identical to the
comment|/// specified instruction except for one differing operand, return the
comment|/// differing operand number.  Otherwise return ~0.
name|unsigned
name|MatchesAllButOneOp
argument_list|(
specifier|const
name|AsmWriterInst
operator|&
name|Other
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
name|void
name|AddLiteralString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Str
argument_list|)
block|{
comment|// If the last operand was already a literal text string, append this to
comment|// it, otherwise add a new operand.
if|if
condition|(
operator|!
name|Operands
operator|.
name|empty
argument_list|()
operator|&&
name|Operands
operator|.
name|back
argument_list|()
operator|.
name|OperandType
operator|==
name|AsmWriterOperand
operator|::
name|isLiteralTextOperand
condition|)
name|Operands
operator|.
name|back
argument_list|()
operator|.
name|Str
operator|.
name|append
argument_list|(
name|Str
argument_list|)
expr_stmt|;
else|else
name|Operands
operator|.
name|push_back
argument_list|(
name|AsmWriterOperand
argument_list|(
name|Str
argument_list|)
argument_list|)
expr_stmt|;
block|}
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

