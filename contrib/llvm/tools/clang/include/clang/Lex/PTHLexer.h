begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- PTHLexer.h - Lexer based on Pre-tokenized input --------*- C++ -*-===//
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
comment|// This file defines the PTHLexer interface.
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
name|LLVM_CLANG_LEX_PTHLEXER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_PTHLEXER_H
end_define

begin_include
include|#
directive|include
file|"clang/Lex/PreprocessorLexer.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|PTHManager
decl_stmt|;
name|class
name|PTHSpellingSearch
decl_stmt|;
name|class
name|PTHLexer
range|:
name|public
name|PreprocessorLexer
block|{
name|SourceLocation
name|FileStartLoc
block|;
comment|/// TokBuf - Buffer from PTH file containing raw token data.
specifier|const
name|unsigned
name|char
operator|*
name|TokBuf
block|;
comment|/// CurPtr - Pointer into current offset of the token buffer where
comment|///  the next token will be read.
specifier|const
name|unsigned
name|char
operator|*
name|CurPtr
block|;
comment|/// LastHashTokPtr - Pointer into TokBuf of the last processed '#'
comment|///  token that appears at the start of a line.
specifier|const
name|unsigned
name|char
operator|*
name|LastHashTokPtr
block|;
comment|/// PPCond - Pointer to a side table in the PTH file that provides a
comment|///  a concise summary of the preprocessor conditional block structure.
comment|///  This is used to perform quick skipping of conditional blocks.
specifier|const
name|unsigned
name|char
operator|*
name|PPCond
block|;
comment|/// CurPPCondPtr - Pointer inside PPCond that refers to the next entry
comment|///  to process when doing quick skipping of preprocessor blocks.
specifier|const
name|unsigned
name|char
operator|*
name|CurPPCondPtr
block|;
name|PTHLexer
argument_list|(
specifier|const
name|PTHLexer
operator|&
argument_list|)
operator|=
name|delete
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|PTHLexer
operator|&
operator|)
operator|=
name|delete
block|;
comment|/// ReadToken - Used by PTHLexer to read tokens TokBuf.
name|void
name|ReadToken
argument_list|(
name|Token
operator|&
name|T
argument_list|)
block|;
name|bool
name|LexEndOfFile
argument_list|(
name|Token
operator|&
name|Result
argument_list|)
block|;
comment|/// PTHMgr - The PTHManager object that created this PTHLexer.
name|PTHManager
operator|&
name|PTHMgr
block|;
name|Token
name|EofToken
block|;
name|protected
operator|:
name|friend
name|class
name|PTHManager
block|;
comment|/// Create a PTHLexer for the specified token stream.
name|PTHLexer
argument_list|(
argument|Preprocessor& pp
argument_list|,
argument|FileID FID
argument_list|,
argument|const unsigned char *D
argument_list|,
argument|const unsigned char* ppcond
argument_list|,
argument|PTHManager&PM
argument_list|)
block|;
name|public
operator|:
operator|~
name|PTHLexer
argument_list|()
name|override
block|{}
comment|/// Lex - Return the next token.
name|bool
name|Lex
argument_list|(
name|Token
operator|&
name|Tok
argument_list|)
block|;
name|void
name|getEOF
argument_list|(
name|Token
operator|&
name|Tok
argument_list|)
block|;
comment|/// DiscardToEndOfLine - Read the rest of the current preprocessor line as an
comment|/// uninterpreted string.  This switches the lexer out of directive mode.
name|void
name|DiscardToEndOfLine
argument_list|()
block|;
comment|/// isNextPPTokenLParen - Return 1 if the next unexpanded token will return a
comment|/// tok::l_paren token, 0 if it is something else and 2 if there are no more
comment|/// tokens controlled by this lexer.
name|unsigned
name|isNextPPTokenLParen
argument_list|()
block|{
comment|// isNextPPTokenLParen is not on the hot path, and all we care about is
comment|// whether or not we are at a token with kind tok::eof or tok::l_paren.
comment|// Just read the first byte from the current token pointer to determine
comment|// its kind.
name|tok
operator|::
name|TokenKind
name|x
operator|=
operator|(
name|tok
operator|::
name|TokenKind
operator|)
operator|*
name|CurPtr
block|;
return|return
name|x
operator|==
name|tok
operator|::
name|eof
condition|?
literal|2
else|:
name|x
operator|==
name|tok
operator|::
name|l_paren
return|;
block|}
comment|/// IndirectLex - An indirect call to 'Lex' that can be invoked via
comment|///  the PreprocessorLexer interface.
name|void
name|IndirectLex
argument_list|(
argument|Token&Result
argument_list|)
name|override
block|{
name|Lex
argument_list|(
name|Result
argument_list|)
block|; }
comment|/// getSourceLocation - Return a source location for the token in
comment|/// the current file.
name|SourceLocation
name|getSourceLocation
argument_list|()
name|override
block|;
comment|/// SkipBlock - Used by Preprocessor to skip the current conditional block.
name|bool
name|SkipBlock
argument_list|()
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

