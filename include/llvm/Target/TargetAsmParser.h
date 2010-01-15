begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/Target/TargetAsmParser.h - Target Assembly Parser --*- C++ -*-===//
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
name|LLVM_TARGET_TARGETPARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TARGET_TARGETPARSER_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmParser
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|class
name|SMLoc
decl_stmt|;
name|class
name|AsmToken
decl_stmt|;
name|class
name|MCParsedAsmOperand
decl_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
comment|/// TargetAsmParser - Generic interface to target specific assembly parsers.
name|class
name|TargetAsmParser
block|{
name|TargetAsmParser
argument_list|(
specifier|const
name|TargetAsmParser
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|TargetAsmParser
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|protected
label|:
comment|// Can only create subclasses.
name|TargetAsmParser
argument_list|(
specifier|const
name|Target
operator|&
argument_list|)
expr_stmt|;
comment|/// TheTarget - The Target that this machine was created for.
specifier|const
name|Target
modifier|&
name|TheTarget
decl_stmt|;
name|public
label|:
name|virtual
operator|~
name|TargetAsmParser
argument_list|()
expr_stmt|;
specifier|const
name|Target
operator|&
name|getTarget
argument_list|()
specifier|const
block|{
return|return
name|TheTarget
return|;
block|}
comment|/// ParseInstruction - Parse one assembly instruction.
comment|///
comment|/// The parser is positioned following the instruction name. The target
comment|/// specific instruction parser should parse the entire instruction and
comment|/// construct the appropriate MCInst, or emit an error. On success, the entire
comment|/// line should be parsed up to and including the end-of-statement token. On
comment|/// failure, the parser is not required to read to the end of the line.
comment|//
comment|/// \param AP - The current parser object.
comment|/// \param Name - The instruction name.
comment|/// \param Operands [out] - The list of parsed operands, this returns
comment|///        ownership of them to the caller.
comment|/// \return True on failure.
name|virtual
name|bool
name|ParseInstruction
argument_list|(
specifier|const
name|StringRef
operator|&
name|Name
argument_list|,
name|SMLoc
name|NameLoc
argument_list|,
name|SmallVectorImpl
operator|<
name|MCParsedAsmOperand
operator|*
operator|>
operator|&
name|Operands
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// ParseDirective - Parse a target specific assembler directive
comment|///
comment|/// The parser is positioned following the directive name.  The target
comment|/// specific directive parser should parse the entire directive doing or
comment|/// recording any target specific work, or return true and do nothing if the
comment|/// directive is not target specific. If the directive is specific for
comment|/// the target, the entire line is parsed up to and including the
comment|/// end-of-statement token and false is returned.
comment|///
comment|/// \param ID - the identifier token of the directive.
name|virtual
name|bool
name|ParseDirective
parameter_list|(
name|AsmToken
name|DirectiveID
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// MatchInstruction - Recognize a series of operands of a parsed instruction
comment|/// as an actual MCInst.  This returns false and fills in Inst on success and
comment|/// returns true on failure to match.
name|virtual
name|bool
name|MatchInstruction
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|MCParsedAsmOperand
operator|*
operator|>
operator|&
name|Operands
argument_list|,
name|MCInst
operator|&
name|Inst
argument_list|)
init|=
literal|0
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

