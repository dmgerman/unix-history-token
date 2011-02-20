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

begin_include
include|#
directive|include
file|"llvm/MC/MCParser/MCAsmParserExtension.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCStreamer
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
range|:
name|public
name|MCAsmParserExtension
block|{
name|TargetAsmParser
argument_list|(
specifier|const
name|TargetAsmParser
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
operator|=
operator|(
specifier|const
name|TargetAsmParser
operator|&
operator|)
block|;
comment|// DO NOT IMPLEMENT
name|protected
operator|:
comment|// Can only create subclasses.
name|TargetAsmParser
argument_list|(
specifier|const
name|Target
operator|&
argument_list|)
block|;
comment|/// The Target that this machine was created for.
specifier|const
name|Target
operator|&
name|TheTarget
block|;
comment|/// The current set of available features.
name|unsigned
name|AvailableFeatures
block|;
name|public
operator|:
name|virtual
operator|~
name|TargetAsmParser
argument_list|()
block|;
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
name|unsigned
name|getAvailableFeatures
argument_list|()
specifier|const
block|{
return|return
name|AvailableFeatures
return|;
block|}
name|void
name|setAvailableFeatures
argument_list|(
argument|unsigned Value
argument_list|)
block|{
name|AvailableFeatures
operator|=
name|Value
block|; }
name|virtual
name|bool
name|ParseRegister
argument_list|(
name|unsigned
operator|&
name|RegNo
argument_list|,
name|SMLoc
operator|&
name|StartLoc
argument_list|,
name|SMLoc
operator|&
name|EndLoc
argument_list|)
operator|=
literal|0
block|;
comment|/// ParseInstruction - Parse one assembly instruction.
comment|///
comment|/// The parser is positioned following the instruction name. The target
comment|/// specific instruction parser should parse the entire instruction and
comment|/// construct the appropriate MCInst, or emit an error. On success, the entire
comment|/// line should be parsed up to and including the end-of-statement token. On
comment|/// failure, the parser is not required to read to the end of the line.
comment|//
comment|/// \param Name - The instruction name.
comment|/// \param NameLoc - The source location of the name.
comment|/// \param Operands [out] - The list of parsed operands, this returns
comment|///        ownership of them to the caller.
comment|/// \return True on failure.
name|virtual
name|bool
name|ParseInstruction
argument_list|(
argument|StringRef Name
argument_list|,
argument|SMLoc NameLoc
argument_list|,
argument|SmallVectorImpl<MCParsedAsmOperand*>&Operands
argument_list|)
operator|=
literal|0
block|;
comment|/// ParseDirective - Parse a target specific assembler directive
comment|///
comment|/// The parser is positioned following the directive name.  The target
comment|/// specific directive parser should parse the entire directive doing or
comment|/// recording any target specific work, or return true and do nothing if the
comment|/// directive is not target specific. If the directive is specific for
comment|/// the target, the entire line is parsed up to and including the
comment|/// end-of-statement token and false is returned.
comment|///
comment|/// \param DirectiveID - the identifier token of the directive.
name|virtual
name|bool
name|ParseDirective
argument_list|(
argument|AsmToken DirectiveID
argument_list|)
operator|=
literal|0
block|;
comment|/// MatchAndEmitInstruction - Recognize a series of operands of a parsed
comment|/// instruction as an actual MCInst and emit it to the specified MCStreamer.
comment|/// This returns false on success and returns true on failure to match.
comment|///
comment|/// On failure, the target parser is responsible for emitting a diagnostic
comment|/// explaining the match failure.
name|virtual
name|bool
name|MatchAndEmitInstruction
argument_list|(
argument|SMLoc IDLoc
argument_list|,
argument|SmallVectorImpl<MCParsedAsmOperand*>&Operands
argument_list|,
argument|MCStreamer&Out
argument_list|)
operator|=
literal|0
block|;    }
decl_stmt|;
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

