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

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCInst
decl_stmt|;
name|class
name|AsmParser
block|{
name|AsmLexer
name|Lexer
decl_stmt|;
struct_decl|struct
name|X86Operand
struct_decl|;
name|public
label|:
name|AsmParser
argument_list|(
name|SourceMgr
operator|&
name|SM
argument_list|)
operator|:
name|Lexer
argument_list|(
argument|SM
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
name|ParseExpression
parameter_list|(
name|int64_t
modifier|&
name|Res
parameter_list|)
function_decl|;
name|bool
name|ParsePrimaryExpr
parameter_list|(
name|int64_t
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
name|int64_t
modifier|&
name|Res
parameter_list|)
function_decl|;
name|bool
name|ParseParenExpr
parameter_list|(
name|int64_t
modifier|&
name|Res
parameter_list|)
function_decl|;
comment|// X86 specific.
name|bool
name|ParseX86InstOperands
parameter_list|(
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

