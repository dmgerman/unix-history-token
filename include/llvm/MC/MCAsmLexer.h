begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- llvm/MC/MCAsmLexer.h - Abstract Asm Lexer Interface -----*- C++ -*-===//
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
name|LLVM_MC_MCASMLEXER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_MC_MCASMLEXER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|MCAsmLexer
decl_stmt|;
name|class
name|MCInst
decl_stmt|;
name|class
name|SMLoc
decl_stmt|;
name|class
name|Target
decl_stmt|;
comment|/// AsmToken - Target independent representation for an assembler token.
struct|struct
name|AsmToken
block|{
enum|enum
name|TokenKind
block|{
comment|// Markers
name|Eof
block|,
name|Error
block|,
comment|// String values.
name|Identifier
block|,
name|String
block|,
comment|// Integer values.
name|Integer
block|,
comment|// No-value.
name|EndOfStatement
block|,
name|Colon
block|,
name|Plus
block|,
name|Minus
block|,
name|Tilde
block|,
name|Slash
block|,
comment|// '/'
name|LParen
block|,
name|RParen
block|,
name|LBrac
block|,
name|RBrac
block|,
name|LCurly
block|,
name|RCurly
block|,
name|Star
block|,
name|Comma
block|,
name|Dollar
block|,
name|Equal
block|,
name|EqualEqual
block|,
name|Pipe
block|,
name|PipePipe
block|,
name|Caret
block|,
name|Amp
block|,
name|AmpAmp
block|,
name|Exclaim
block|,
name|ExclaimEqual
block|,
name|Percent
block|,
name|Hash
block|,
name|Less
block|,
name|LessEqual
block|,
name|LessLess
block|,
name|LessGreater
block|,
name|Greater
block|,
name|GreaterEqual
block|,
name|GreaterGreater
block|}
enum|;
name|TokenKind
name|Kind
decl_stmt|;
comment|/// A reference to the entire token contents; this is always a pointer into
comment|/// a memory buffer owned by the source manager.
name|StringRef
name|Str
decl_stmt|;
name|int64_t
name|IntVal
decl_stmt|;
name|public
label|:
name|AsmToken
argument_list|()
block|{}
name|AsmToken
argument_list|(
argument|TokenKind _Kind
argument_list|,
argument|StringRef _Str
argument_list|,
argument|int64_t _IntVal =
literal|0
argument_list|)
block|:
name|Kind
argument_list|(
name|_Kind
argument_list|)
operator|,
name|Str
argument_list|(
name|_Str
argument_list|)
operator|,
name|IntVal
argument_list|(
argument|_IntVal
argument_list|)
block|{}
name|TokenKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|bool
name|is
argument_list|(
name|TokenKind
name|K
argument_list|)
decl|const
block|{
return|return
name|Kind
operator|==
name|K
return|;
block|}
name|bool
name|isNot
argument_list|(
name|TokenKind
name|K
argument_list|)
decl|const
block|{
return|return
name|Kind
operator|!=
name|K
return|;
block|}
name|SMLoc
name|getLoc
argument_list|()
specifier|const
expr_stmt|;
comment|/// getStringContents - Get the contents of a string token (without quotes).
name|StringRef
name|getStringContents
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|String
operator|&&
literal|"This token isn't a string!"
argument_list|)
block|;
return|return
name|Str
operator|.
name|slice
argument_list|(
literal|1
argument_list|,
name|Str
operator|.
name|size
argument_list|()
operator|-
literal|1
argument_list|)
return|;
block|}
comment|/// getIdentifier - Get the identifier string for the current token, which
comment|/// should be an identifier or a string. This gets the portion of the string
comment|/// which should be used as the identifier, e.g., it does not include the
comment|/// quotes on strings.
name|StringRef
name|getIdentifier
argument_list|()
specifier|const
block|{
if|if
condition|(
name|Kind
operator|==
name|Identifier
condition|)
return|return
name|getString
argument_list|()
return|;
return|return
name|getStringContents
argument_list|()
return|;
block|}
comment|/// getString - Get the string for the current token, this includes all
comment|/// characters (for example, the quotes on strings) in the token.
comment|///
comment|/// The returned StringRef points into the source manager's memory buffer, and
comment|/// is safe to store across calls to Lex().
name|StringRef
name|getString
argument_list|()
decl|const
block|{
return|return
name|Str
return|;
block|}
comment|// FIXME: Don't compute this in advance, it makes every token larger, and is
comment|// also not generally what we want (it is nicer for recovery etc. to lex 123br
comment|// as a single token, then diagnose as an invalid number).
name|int64_t
name|getIntVal
argument_list|()
decl|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|Integer
operator|&&
literal|"This token isn't an integer!"
argument_list|)
expr_stmt|;
return|return
name|IntVal
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// MCAsmLexer - Generic assembler lexer interface, for use by target specific
end_comment

begin_comment
comment|/// assembly lexers.
end_comment

begin_decl_stmt
name|class
name|MCAsmLexer
block|{
comment|/// The current token, stored in the base class for faster access.
name|AsmToken
name|CurTok
decl_stmt|;
name|MCAsmLexer
argument_list|(
specifier|const
name|MCAsmLexer
operator|&
argument_list|)
expr_stmt|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
init|=
operator|(
specifier|const
name|MCAsmLexer
operator|&
operator|)
decl_stmt|;
comment|// DO NOT IMPLEMENT
name|protected
label|:
comment|// Can only create subclasses.
name|MCAsmLexer
argument_list|()
expr_stmt|;
name|virtual
name|AsmToken
name|LexToken
parameter_list|()
init|=
literal|0
function_decl|;
name|public
label|:
name|virtual
operator|~
name|MCAsmLexer
argument_list|()
expr_stmt|;
comment|/// Lex - Consume the next token from the input stream and return it.
comment|///
comment|/// The lexer will continuosly return the end-of-file token once the end of
comment|/// the main input file has been reached.
specifier|const
name|AsmToken
modifier|&
name|Lex
parameter_list|()
block|{
return|return
name|CurTok
operator|=
name|LexToken
argument_list|()
return|;
block|}
comment|/// getTok - Get the current (last) lexed token.
specifier|const
name|AsmToken
modifier|&
name|getTok
parameter_list|()
block|{
return|return
name|CurTok
return|;
block|}
comment|/// getKind - Get the kind of current token.
name|AsmToken
operator|::
name|TokenKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|CurTok
operator|.
name|getKind
argument_list|()
return|;
block|}
comment|/// is - Check if the current token has kind \arg K.
name|bool
name|is
argument_list|(
name|AsmToken
operator|::
name|TokenKind
name|K
argument_list|)
decl|const
block|{
return|return
name|CurTok
operator|.
name|is
argument_list|(
name|K
argument_list|)
return|;
block|}
comment|/// isNot - Check if the current token has kind \arg K.
name|bool
name|isNot
argument_list|(
name|AsmToken
operator|::
name|TokenKind
name|K
argument_list|)
decl|const
block|{
return|return
name|CurTok
operator|.
name|isNot
argument_list|(
name|K
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// End llvm namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

