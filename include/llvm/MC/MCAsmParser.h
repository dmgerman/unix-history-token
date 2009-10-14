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
name|MCAsmLexer
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
name|MCValue
decl_stmt|;
name|class
name|SMLoc
decl_stmt|;
name|class
name|Twine
decl_stmt|;
comment|/// MCAsmParser - Generic assembler parser interface, for use by target specific
comment|/// assembly parsers.
name|class
name|MCAsmParser
block|{
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
comment|/// getSteamer - Return the output streamer for the assembler.
name|virtual
name|MCStreamer
modifier|&
name|getStreamer
parameter_list|()
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
comment|/// Warning - Emit an error at the location \arg L, with the message \arg
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
parameter_list|)
init|=
literal|0
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

