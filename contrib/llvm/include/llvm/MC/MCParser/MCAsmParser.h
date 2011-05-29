begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCAsmParser.h - Abstract Asm Parser Interface ---*- C++ -*-===//
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
name|LLVM_MC_MCASMPARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCASMPARSER_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AsmToken
decl_stmt|;
name|class
name|MCAsmInfo
decl_stmt|;
name|class
name|MCAsmLexer
decl_stmt|;
name|class
name|MCAsmParserExtension
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCExpr
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
name|class
name|SMLoc
decl_stmt|;
name|class
name|SourceMgr
decl_stmt|;
name|class
name|StringRef
decl_stmt|;
name|class
name|Target
decl_stmt|;
name|class
name|TargetAsmParser
decl_stmt|;
name|class
name|Twine
decl_stmt|;
comment|/// MCAsmParser - Generic assembler parser interface, for use by target specific
comment|/// assembly parsers.
name|class
name|MCAsmParser
block|{
name|public
label|:
typedef|typedef
name|bool
function_decl|(
modifier|*
name|DirectiveHandler
function_decl|)
parameter_list|(
name|MCAsmParserExtension
modifier|*
parameter_list|,
name|StringRef
parameter_list|,
name|SMLoc
parameter_list|)
function_decl|;
name|private
label|:
name|MCAsmParser
argument_list|(
specifier|const
name|MCAsmParser
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|MCAsmParser
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|TargetAsmParser
modifier|*
name|TargetParser
decl_stmt|;
name|unsigned
name|ShowParsedOperands
range|:
literal|1
decl_stmt|;
name|protected
label|:
comment|// Can only create subclasses.
name|MCAsmParser
argument_list|()
expr_stmt|;
name|public
label|:
name|virtual
operator|~
name|MCAsmParser
argument_list|()
expr_stmt|;
name|virtual
name|void
name|AddDirectiveHandler
parameter_list|(
name|MCAsmParserExtension
modifier|*
name|Object
parameter_list|,
name|StringRef
name|Directive
parameter_list|,
name|DirectiveHandler
name|Handler
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
name|SourceMgr
modifier|&
name|getSourceManager
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|MCAsmLexer
modifier|&
name|getLexer
parameter_list|()
init|=
literal|0
function_decl|;
name|virtual
name|MCContext
modifier|&
name|getContext
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// getStreamer - Return the output streamer for the assembler.
name|virtual
name|MCStreamer
modifier|&
name|getStreamer
parameter_list|()
init|=
literal|0
function_decl|;
name|TargetAsmParser
operator|&
name|getTargetParser
argument_list|()
specifier|const
block|{
return|return
operator|*
name|TargetParser
return|;
block|}
name|void
name|setTargetParser
parameter_list|(
name|TargetAsmParser
modifier|&
name|P
parameter_list|)
function_decl|;
name|bool
name|getShowParsedOperands
argument_list|()
specifier|const
block|{
return|return
name|ShowParsedOperands
return|;
block|}
name|void
name|setShowParsedOperands
parameter_list|(
name|bool
name|Value
parameter_list|)
block|{
name|ShowParsedOperands
operator|=
name|Value
expr_stmt|;
block|}
comment|/// Run - Run the parser on the input source buffer.
name|virtual
name|bool
name|Run
parameter_list|(
name|bool
name|NoInitialTextSection
parameter_list|,
name|bool
name|NoFinalize
init|=
name|false
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Warning - Emit a warning at the location \arg L, with the message \arg
comment|/// Msg.
name|virtual
name|void
name|Warning
parameter_list|(
name|SMLoc
name|L
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Error - Emit an error at the location \arg L, with the message \arg
comment|/// Msg.
comment|///
comment|/// \return The return value is always true, as an idiomatic convenience to
comment|/// clients.
name|virtual
name|bool
name|Error
parameter_list|(
name|SMLoc
name|L
parameter_list|,
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// Lex - Get the next AsmToken in the stream, possibly handling file
comment|/// inclusion first.
name|virtual
specifier|const
name|AsmToken
modifier|&
name|Lex
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// getTok - Get the current AsmToken from the stream.
specifier|const
name|AsmToken
modifier|&
name|getTok
parameter_list|()
function_decl|;
comment|/// \brief Report an error at the current lexer location.
name|bool
name|TokError
parameter_list|(
specifier|const
name|Twine
modifier|&
name|Msg
parameter_list|)
function_decl|;
comment|/// ParseIdentifier - Parse an identifier or string (as a quoted identifier)
comment|/// and set \arg Res to the identifier contents.
name|virtual
name|bool
name|ParseIdentifier
parameter_list|(
name|StringRef
modifier|&
name|Res
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Parse up to the end of statement and return the contents from the
comment|/// current token until the end of the statement; the current token on exit
comment|/// will be either the EndOfStatement or EOF.
name|virtual
name|StringRef
name|ParseStringToEndOfStatement
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// EatToEndOfStatement - Skip to the end of the current statement, for error
comment|/// recovery.
name|virtual
name|void
name|EatToEndOfStatement
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// ParseExpression - Parse an arbitrary expression.
comment|///
comment|/// @param Res - The value of the expression. The result is undefined
comment|/// on error.
comment|/// @result - False on success.
name|virtual
name|bool
name|ParseExpression
parameter_list|(
specifier|const
name|MCExpr
modifier|*
modifier|&
name|Res
parameter_list|,
name|SMLoc
modifier|&
name|EndLoc
parameter_list|)
init|=
literal|0
function_decl|;
name|bool
name|ParseExpression
parameter_list|(
specifier|const
name|MCExpr
modifier|*
modifier|&
name|Res
parameter_list|)
function_decl|;
comment|/// ParseParenExpression - Parse an arbitrary expression, assuming that an
comment|/// initial '(' has already been consumed.
comment|///
comment|/// @param Res - The value of the expression. The result is undefined
comment|/// on error.
comment|/// @result - False on success.
name|virtual
name|bool
name|ParseParenExpression
parameter_list|(
specifier|const
name|MCExpr
modifier|*
modifier|&
name|Res
parameter_list|,
name|SMLoc
modifier|&
name|EndLoc
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// ParseAbsoluteExpression - Parse an expression which must evaluate to an
comment|/// absolute value.
comment|///
comment|/// @param Res - The value of the absolute expression. The result is undefined
comment|/// on error.
comment|/// @result - False on success.
name|virtual
name|bool
name|ParseAbsoluteExpression
parameter_list|(
name|int64_t
modifier|&
name|Res
parameter_list|)
init|=
literal|0
function_decl|;
block|}
empty_stmt|;
comment|/// \brief Create an MCAsmParser instance.
name|MCAsmParser
modifier|*
name|createMCAsmParser
parameter_list|(
specifier|const
name|Target
modifier|&
parameter_list|,
name|SourceMgr
modifier|&
parameter_list|,
name|MCContext
modifier|&
parameter_list|,
name|MCStreamer
modifier|&
parameter_list|,
specifier|const
name|MCAsmInfo
modifier|&
parameter_list|)
function_decl|;
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

