begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- AsmLexer.h - Lexer for Assembly Files --------------------*- C++ -*-===//
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
comment|// This class declares the lexer for assembly files.
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
name|LLVM_MC_MCPARSER_ASMLEXER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCPARSER_ASMLEXER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/MC/MCParser/MCAsmLexer.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmInfo
decl_stmt|;
comment|/// AsmLexer - Lexer class for assembly files.
name|class
name|AsmLexer
range|:
name|public
name|MCAsmLexer
block|{
specifier|const
name|MCAsmInfo
operator|&
name|MAI
block|;
specifier|const
name|char
operator|*
name|CurPtr
operator|=
name|nullptr
block|;
name|StringRef
name|CurBuf
block|;
name|bool
name|IsAtStartOfLine
operator|=
name|true
block|;
name|bool
name|IsAtStartOfStatement
operator|=
name|true
block|;
name|bool
name|IsParsingMSInlineAsm
operator|=
name|false
block|;
name|bool
name|IsPeeking
operator|=
name|false
block|;
name|protected
operator|:
comment|/// LexToken - Read the next token and return its code.
name|AsmToken
name|LexToken
argument_list|()
name|override
block|;
name|public
operator|:
name|AsmLexer
argument_list|(
specifier|const
name|MCAsmInfo
operator|&
name|MAI
argument_list|)
block|;
name|AsmLexer
argument_list|(
specifier|const
name|AsmLexer
operator|&
argument_list|)
operator|=
name|delete
block|;
name|AsmLexer
operator|&
name|operator
operator|=
operator|(
specifier|const
name|AsmLexer
operator|&
operator|)
operator|=
name|delete
block|;
operator|~
name|AsmLexer
argument_list|()
name|override
block|;
name|void
name|setBuffer
argument_list|(
argument|StringRef Buf
argument_list|,
argument|const char *ptr = nullptr
argument_list|)
block|;
name|void
name|setParsingMSInlineAsm
argument_list|(
argument|bool V
argument_list|)
block|{
name|IsParsingMSInlineAsm
operator|=
name|V
block|; }
name|StringRef
name|LexUntilEndOfStatement
argument_list|()
name|override
block|;
name|size_t
name|peekTokens
argument_list|(
argument|MutableArrayRef<AsmToken> Buf
argument_list|,
argument|bool ShouldSkipSpace = true
argument_list|)
name|override
block|;
specifier|const
name|MCAsmInfo
operator|&
name|getMAI
argument_list|()
specifier|const
block|{
return|return
name|MAI
return|;
block|}
name|private
operator|:
name|bool
name|isAtStartOfComment
argument_list|(
specifier|const
name|char
operator|*
name|Ptr
argument_list|)
block|;
name|bool
name|isAtStatementSeparator
argument_list|(
specifier|const
name|char
operator|*
name|Ptr
argument_list|)
block|;
name|int
name|getNextChar
argument_list|()
block|;
name|AsmToken
name|ReturnError
argument_list|(
specifier|const
name|char
operator|*
name|Loc
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|Msg
argument_list|)
block|;
name|AsmToken
name|LexIdentifier
argument_list|()
block|;
name|AsmToken
name|LexSlash
argument_list|()
block|;
name|AsmToken
name|LexLineComment
argument_list|()
block|;
name|AsmToken
name|LexDigit
argument_list|()
block|;
name|AsmToken
name|LexSingleQuote
argument_list|()
block|;
name|AsmToken
name|LexQuote
argument_list|()
block|;
name|AsmToken
name|LexFloatLiteral
argument_list|()
block|;
name|AsmToken
name|LexHexFloatLiteral
argument_list|(
argument|bool NoIntDigits
argument_list|)
block|;
name|StringRef
name|LexUntilEndOfLine
argument_list|()
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_MC_MCPARSER_ASMLEXER_H
end_comment

end_unit

