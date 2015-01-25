begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TokenConcatenation.h - Token Concatenation Avoidance ---*- C++ -*-===//
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
comment|// This file defines the TokenConcatenation class.
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
name|LLVM_CLANG_LEX_TOKENCONCATENATION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_TOKENCONCATENATION_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/TokenKinds.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Preprocessor
decl_stmt|;
name|class
name|Token
decl_stmt|;
comment|/// TokenConcatenation class, which answers the question of
comment|///   "Is it safe to emit two tokens without a whitespace between them, or
comment|///    would that cause implicit concatenation of the tokens?"
comment|///
comment|/// For example, it emitting two identifiers "foo" and "bar" next to each
comment|/// other would cause the lexer to produce one "foobar" token.  Emitting "1"
comment|/// and ")" next to each other is safe.
comment|///
name|class
name|TokenConcatenation
block|{
name|Preprocessor
modifier|&
name|PP
decl_stmt|;
enum|enum
name|AvoidConcatInfo
block|{
comment|/// By default, a token never needs to avoid concatenation.  Most tokens
comment|/// (e.g. ',', ')', etc) don't cause a problem when concatenated.
name|aci_never_avoid_concat
init|=
literal|0
block|,
comment|/// aci_custom_firstchar - AvoidConcat contains custom code to handle this
comment|/// token's requirements, and it needs to know the first character of the
comment|/// token.
name|aci_custom_firstchar
init|=
literal|1
block|,
comment|/// aci_custom - AvoidConcat contains custom code to handle this token's
comment|/// requirements, but it doesn't need to know the first character of the
comment|/// token.
name|aci_custom
init|=
literal|2
block|,
comment|/// aci_avoid_equal - Many tokens cannot be safely followed by an '='
comment|/// character.  For example, "<<" turns into "<<=" when followed by an =.
name|aci_avoid_equal
init|=
literal|4
block|}
enum|;
comment|/// TokenInfo - This array contains information for each token on what
comment|/// action to take when avoiding concatenation of tokens in the AvoidConcat
comment|/// method.
name|char
name|TokenInfo
index|[
name|tok
operator|::
name|NUM_TOKENS
index|]
decl_stmt|;
name|public
label|:
name|TokenConcatenation
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|)
expr_stmt|;
name|bool
name|AvoidConcat
argument_list|(
specifier|const
name|Token
operator|&
name|PrevPrevTok
argument_list|,
specifier|const
name|Token
operator|&
name|PrevTok
argument_list|,
specifier|const
name|Token
operator|&
name|Tok
argument_list|)
decl|const
decl_stmt|;
name|private
label|:
comment|/// IsIdentifierStringPrefix - Return true if the spelling of the token
comment|/// is literally 'L', 'u', 'U', or 'u8'.
name|bool
name|IsIdentifierStringPrefix
argument_list|(
specifier|const
name|Token
operator|&
name|Tok
argument_list|)
decl|const
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

