begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AsmParser.h - Parser for Assembly Files ------------------*- C++ -*-===//
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
comment|// This class declares the parser for assembly files.
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
name|ASMPARSER_H
end_ifndef

begin_define
define|#
directive|define
name|ASMPARSER_H
end_define

begin_include
include|#
directive|include
file|"AsmLexer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCStreamer.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|AsmExpr
decl_stmt|;
name|class
name|MCContext
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|MCStreamer
decl_stmt|;
name|class
name|MCValue
decl_stmt|;
name|class
name|AsmParser
block|{
name|public
label|:
struct_decl|struct
name|X86Operand
struct_decl|;
name|private
label|:
name|AsmLexer
name|Lexer
decl_stmt|;
name|MCContext
modifier|&
name|Ctx
decl_stmt|;
name|MCStreamer
modifier|&
name|Out
decl_stmt|;
name|public
label|:
name|AsmParser
argument_list|(
name|SourceMgr
operator|&
name|SM
argument_list|,
name|MCContext
operator|&
name|ctx
argument_list|,
name|MCStreamer
operator|&
name|OutStr
argument_list|)
operator|:
name|Lexer
argument_list|(
name|SM
argument_list|)
operator|,
name|Ctx
argument_list|(
name|ctx
argument_list|)
operator|,
name|Out
argument_list|(
argument|OutStr
argument_list|)
block|{}
operator|~
name|AsmParser
argument_list|()
block|{}
name|bool
name|Run
argument_list|()
expr_stmt|;
name|private
label|:
name|bool
name|ParseStatement
parameter_list|()
function_decl|;
name|void
name|Warning
parameter_list|(
name|SMLoc
name|L
parameter_list|,
specifier|const
name|char
modifier|*
name|Msg
parameter_list|)
function_decl|;
name|bool
name|Error
parameter_list|(
name|SMLoc
name|L
parameter_list|,
specifier|const
name|char
modifier|*
name|Msg
parameter_list|)
function_decl|;
name|bool
name|TokError
parameter_list|(
specifier|const
name|char
modifier|*
name|Msg
parameter_list|)
function_decl|;
name|void
name|EatToEndOfStatement
parameter_list|()
function_decl|;
name|bool
name|ParseAssignment
parameter_list|(
specifier|const
name|char
modifier|*
name|Name
parameter_list|,
name|bool
name|IsDotSet
parameter_list|)
function_decl|;
comment|/// ParseExpression - Parse a general assembly expression.
comment|///
comment|/// @param Res - The resulting expression. The pointer value is null on error.
comment|/// @result - False on success.
name|bool
name|ParseExpression
parameter_list|(
name|AsmExpr
modifier|*
modifier|&
name|Res
parameter_list|)
function_decl|;
comment|/// ParseAbsoluteExpression - Parse an expression which must evaluate to an
comment|/// absolute value.
comment|///
comment|/// @param Res - The value of the absolute expression. The result is undefined
comment|/// on error.
comment|/// @result - False on success.
name|bool
name|ParseAbsoluteExpression
parameter_list|(
name|int64_t
modifier|&
name|Res
parameter_list|)
function_decl|;
comment|/// ParseRelocatableExpression - Parse an expression which must be
comment|/// relocatable.
comment|///
comment|/// @param Res - The relocatable expression value. The result is undefined on
comment|/// error.
comment|/// @result - False on success.
name|bool
name|ParseRelocatableExpression
parameter_list|(
name|MCValue
modifier|&
name|Res
parameter_list|)
function_decl|;
comment|/// ParseParenRelocatableExpression - Parse an expression which must be
comment|/// relocatable, assuming that an initial '(' has already been consumed.
comment|///
comment|/// @param Res - The relocatable expression value. The result is undefined on
comment|/// error.
comment|/// @result - False on success.
comment|///
comment|/// @see ParseRelocatableExpression, ParseParenExpr.
name|bool
name|ParseParenRelocatableExpression
parameter_list|(
name|MCValue
modifier|&
name|Res
parameter_list|)
function_decl|;
name|bool
name|ParsePrimaryExpr
parameter_list|(
name|AsmExpr
modifier|*
modifier|&
name|Res
parameter_list|)
function_decl|;
name|bool
name|ParseBinOpRHS
parameter_list|(
name|unsigned
name|Precedence
parameter_list|,
name|AsmExpr
modifier|*
modifier|&
name|Res
parameter_list|)
function_decl|;
name|bool
name|ParseParenExpr
parameter_list|(
name|AsmExpr
modifier|*
modifier|&
name|Res
parameter_list|)
function_decl|;
comment|// X86 specific.
name|bool
name|ParseX86InstOperands
parameter_list|(
specifier|const
name|char
modifier|*
name|InstName
parameter_list|,
name|MCInst
modifier|&
name|Inst
parameter_list|)
function_decl|;
name|bool
name|ParseX86Operand
parameter_list|(
name|X86Operand
modifier|&
name|Op
parameter_list|)
function_decl|;
name|bool
name|ParseX86MemOperand
parameter_list|(
name|X86Operand
modifier|&
name|Op
parameter_list|)
function_decl|;
name|bool
name|ParseX86Register
parameter_list|(
name|X86Operand
modifier|&
name|Op
parameter_list|)
function_decl|;
comment|// Directive Parsing.
name|bool
name|ParseDirectiveDarwinSection
parameter_list|()
function_decl|;
comment|// Darwin specific ".section".
name|bool
name|ParseDirectiveSectionSwitch
parameter_list|(
specifier|const
name|char
modifier|*
name|Section
parameter_list|,
specifier|const
name|char
modifier|*
name|Directives
init|=
literal|0
parameter_list|)
function_decl|;
name|bool
name|ParseDirectiveAscii
parameter_list|(
name|bool
name|ZeroTerminated
parameter_list|)
function_decl|;
comment|// ".ascii", ".asciiz"
name|bool
name|ParseDirectiveValue
parameter_list|(
name|unsigned
name|Size
parameter_list|)
function_decl|;
comment|// ".byte", ".long", ...
name|bool
name|ParseDirectiveFill
parameter_list|()
function_decl|;
comment|// ".fill"
name|bool
name|ParseDirectiveSpace
parameter_list|()
function_decl|;
comment|// ".space"
name|bool
name|ParseDirectiveSet
parameter_list|()
function_decl|;
comment|// ".set"
name|bool
name|ParseDirectiveOrg
parameter_list|()
function_decl|;
comment|// ".org"
comment|// ".align{,32}", ".p2align{,w,l}"
name|bool
name|ParseDirectiveAlign
parameter_list|(
name|bool
name|IsPow2
parameter_list|,
name|unsigned
name|ValueSize
parameter_list|)
function_decl|;
comment|/// ParseDirectiveSymbolAttribute - Parse a directive like ".globl" which
comment|/// accepts a single symbol (which should be a label or an external).
name|bool
name|ParseDirectiveSymbolAttribute
argument_list|(
name|MCStreamer
operator|::
name|SymbolAttr
name|Attr
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

