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
name|ASMLEXER_H
end_ifndef

begin_define
define|#
directive|define
name|ASMLEXER_H
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
file|"llvm/MC/MCAsmInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MemoryBuffer
decl_stmt|;
name|class
name|SMLoc
decl_stmt|;
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
block|;
specifier|const
name|MemoryBuffer
operator|*
name|CurBuf
block|;
specifier|const
name|char
operator|*
name|TokStart
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|AsmLexer
operator|&
operator|)
block|;
comment|// DO NOT IMPLEMENT
name|AsmLexer
argument_list|(
specifier|const
name|AsmLexer
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|protected
operator|:
comment|/// LexToken - Read the next token and return its code.
name|virtual
name|AsmToken
name|LexToken
argument_list|()
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
operator|~
name|AsmLexer
argument_list|()
block|;
name|void
name|setBuffer
argument_list|(
specifier|const
name|MemoryBuffer
operator|*
name|buf
argument_list|,
specifier|const
name|char
operator|*
name|ptr
operator|=
name|NULL
argument_list|)
block|;
name|SMLoc
name|getLoc
argument_list|()
specifier|const
block|;
name|StringRef
name|LexUntilEndOfStatement
argument_list|()
block|;
name|bool
name|isAtStartOfComment
argument_list|(
argument|char Char
argument_list|)
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
name|LexQuote
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

end_unit

