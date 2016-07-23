begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ScriptParser.h -------------------------------------------*- C++ -*-===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//                             The LLVM Linker
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
name|LLD_ELF_SCRIPT_PARSER_H
end_ifndef

begin_define
define|#
directive|define
name|LLD_ELF_SCRIPT_PARSER_H
end_define

begin_include
include|#
directive|include
file|"lld/Core/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lld
block|{
name|namespace
name|elf
block|{
name|class
name|ScriptParserBase
block|{
name|public
label|:
name|explicit
name|ScriptParserBase
argument_list|(
argument|StringRef S
argument_list|)
block|:
name|Input
argument_list|(
name|S
argument_list|)
operator|,
name|Tokens
argument_list|(
argument|tokenize(S)
argument_list|)
block|{}
name|explicit
name|ScriptParserBase
argument_list|(
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|Tokens
argument_list|)
operator|:
name|Input
argument_list|(
literal|""
argument_list|)
operator|,
name|Tokens
argument_list|(
argument|std::move(Tokens)
argument_list|)
block|{}
name|protected
operator|:
name|void
name|setError
argument_list|(
specifier|const
name|Twine
operator|&
name|Msg
argument_list|)
expr_stmt|;
specifier|static
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|tokenize
argument_list|(
argument|StringRef S
argument_list|)
expr_stmt|;
specifier|static
name|StringRef
name|skipSpace
parameter_list|(
name|StringRef
name|S
parameter_list|)
function_decl|;
name|bool
name|atEOF
parameter_list|()
function_decl|;
name|StringRef
name|next
parameter_list|()
function_decl|;
name|StringRef
name|peek
parameter_list|()
function_decl|;
name|bool
name|skip
parameter_list|(
name|StringRef
name|Tok
parameter_list|)
function_decl|;
name|void
name|expect
parameter_list|(
name|StringRef
name|Expect
parameter_list|)
function_decl|;
name|size_t
name|getPos
parameter_list|()
function_decl|;
name|void
name|printErrorPos
parameter_list|()
function_decl|;
name|StringRef
name|Input
decl_stmt|;
name|std
operator|::
name|vector
operator|<
name|StringRef
operator|>
name|Tokens
expr_stmt|;
name|size_t
name|Pos
init|=
literal|0
decl_stmt|;
name|bool
name|Error
init|=
name|false
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace elf
block|}
end_decl_stmt

begin_comment
comment|// namespace lld
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

