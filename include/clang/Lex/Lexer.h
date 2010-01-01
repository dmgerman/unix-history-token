begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Lexer.h - C Language Family Lexer ----------------------*- C++ -*-===//
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
comment|//  This file defines the Lexer interface.
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
name|LLVM_CLANG_LEXER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEXER_H
end_define

begin_include
include|#
directive|include
file|"clang/Lex/PreprocessorLexer.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|Diagnostic
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|DiagnosticBuilder
decl_stmt|;
comment|/// Lexer - This provides a simple interface that turns a text buffer into a
comment|/// stream of tokens.  This provides no support for file reading or buffering,
comment|/// or buffering/seeking of tokens, only forward lexing is supported.  It relies
comment|/// on the specified Preprocessor object to handle preprocessor directives, etc.
name|class
name|Lexer
range|:
name|public
name|PreprocessorLexer
block|{
comment|//===--------------------------------------------------------------------===//
comment|// Constant configuration values for this lexer.
specifier|const
name|char
operator|*
name|BufferStart
block|;
comment|// Start of the buffer.
specifier|const
name|char
operator|*
name|BufferEnd
block|;
comment|// End of the buffer.
name|SourceLocation
name|FileLoc
block|;
comment|// Location for start of file.
name|LangOptions
name|Features
block|;
comment|// Features enabled by this language (cache).
name|bool
name|Is_PragmaLexer
operator|:
literal|1
block|;
comment|// True if lexer for _Pragma handling.
name|bool
name|IsInConflictMarker
operator|:
literal|1
block|;
comment|// True if in a VCS conflict marker '<<<<<<<'
comment|//===--------------------------------------------------------------------===//
comment|// Context-specific lexing flags set by the preprocessor.
comment|//
comment|/// ExtendedTokenMode - The lexer can optionally keep comments and whitespace
comment|/// and return them as tokens.  This is used for -C and -CC modes, and
comment|/// whitespace preservation can be useful for some clients that want to lex
comment|/// the file in raw mode and get every character from the file.
comment|///
comment|/// When this is set to 2 it returns comments and whitespace.  When set to 1
comment|/// it returns comments, when it is set to 0 it returns normal tokens only.
name|unsigned
name|char
name|ExtendedTokenMode
block|;
comment|//===--------------------------------------------------------------------===//
comment|// Context that changes as the file is lexed.
comment|// NOTE: any state that mutates when in raw mode must have save/restore code
comment|// in Lexer::isNextPPTokenLParen.
comment|// BufferPtr - Current pointer into the buffer.  This is the next character
comment|// to be lexed.
specifier|const
name|char
operator|*
name|BufferPtr
block|;
comment|// IsAtStartOfLine - True if the next lexed token should get the "start of
comment|// line" flag set on it.
name|bool
name|IsAtStartOfLine
block|;
name|Lexer
argument_list|(
specifier|const
name|Lexer
operator|&
argument_list|)
block|;
comment|// DO NOT IMPLEMENT
name|void
name|operator
operator|=
operator|(
specifier|const
name|Lexer
operator|&
operator|)
block|;
comment|// DO NOT IMPLEMENT
name|friend
name|class
name|Preprocessor
block|;
name|void
name|InitLexer
argument_list|(
specifier|const
name|char
operator|*
name|BufStart
argument_list|,
specifier|const
name|char
operator|*
name|BufPtr
argument_list|,
specifier|const
name|char
operator|*
name|BufEnd
argument_list|)
block|;
name|public
operator|:
comment|/// Lexer constructor - Create a new lexer object for the specified buffer
comment|/// with the specified preprocessor managing the lexing process.  This lexer
comment|/// assumes that the associated file buffer and Preprocessor objects will
comment|/// outlive it, so it doesn't take ownership of either of them.
name|Lexer
argument_list|(
argument|FileID FID
argument_list|,
argument|const llvm::MemoryBuffer *InputBuffer
argument_list|,
argument|Preprocessor&PP
argument_list|)
block|;
comment|/// Lexer constructor - Create a new raw lexer object.  This object is only
comment|/// suitable for calls to 'LexRawToken'.  This lexer assumes that the text
comment|/// range will outlive it, so it doesn't take ownership of it.
name|Lexer
argument_list|(
argument|SourceLocation FileLoc
argument_list|,
argument|const LangOptions&Features
argument_list|,
argument|const char *BufStart
argument_list|,
argument|const char *BufPtr
argument_list|,
argument|const char *BufEnd
argument_list|)
block|;
comment|/// Lexer constructor - Create a new raw lexer object.  This object is only
comment|/// suitable for calls to 'LexRawToken'.  This lexer assumes that the text
comment|/// range will outlive it, so it doesn't take ownership of it.
name|Lexer
argument_list|(
argument|FileID FID
argument_list|,
argument|const llvm::MemoryBuffer *InputBuffer
argument_list|,
argument|const SourceManager&SM
argument_list|,
argument|const LangOptions&Features
argument_list|)
block|;
comment|/// Create_PragmaLexer: Lexer constructor - Create a new lexer object for
comment|/// _Pragma expansion.  This has a variety of magic semantics that this method
comment|/// sets up.  It returns a new'd Lexer that must be delete'd when done.
specifier|static
name|Lexer
operator|*
name|Create_PragmaLexer
argument_list|(
argument|SourceLocation SpellingLoc
argument_list|,
argument|SourceLocation InstantiationLocStart
argument_list|,
argument|SourceLocation InstantiationLocEnd
argument_list|,
argument|unsigned TokLen
argument_list|,
argument|Preprocessor&PP
argument_list|)
block|;
comment|/// getFeatures - Return the language features currently enabled.  NOTE: this
comment|/// lexer modifies features as a file is parsed!
specifier|const
name|LangOptions
operator|&
name|getFeatures
argument_list|()
specifier|const
block|{
return|return
name|Features
return|;
block|}
comment|/// getFileLoc - Return the File Location for the file we are lexing out of.
comment|/// The physical location encodes the location where the characters come from,
comment|/// the virtual location encodes where we should *claim* the characters came
comment|/// from.  Currently this is only used by _Pragma handling.
name|SourceLocation
name|getFileLoc
argument_list|()
specifier|const
block|{
return|return
name|FileLoc
return|;
block|}
comment|/// Lex - Return the next token in the file.  If this is the end of file, it
comment|/// return the tok::eof token.  Return true if an error occurred and
comment|/// compilation should terminate, false if normal.  This implicitly involves
comment|/// the preprocessor.
name|void
name|Lex
argument_list|(
argument|Token&Result
argument_list|)
block|{
comment|// Start a new token.
name|Result
operator|.
name|startToken
argument_list|()
block|;
comment|// NOTE, any changes here should also change code after calls to
comment|// Preprocessor::HandleDirective
if|if
condition|(
name|IsAtStartOfLine
condition|)
block|{
name|Result
operator|.
name|setFlag
argument_list|(
name|Token
operator|::
name|StartOfLine
argument_list|)
expr_stmt|;
name|IsAtStartOfLine
operator|=
name|false
expr_stmt|;
block|}
comment|// Get a token.  Note that this may delete the current lexer if the end of
comment|// file is reached.
name|LexTokenInternal
argument_list|(
name|Result
argument_list|)
expr_stmt|;
block|}
comment|/// isPragmaLexer - Returns true if this Lexer is being used to lex a pragma.
name|bool
name|isPragmaLexer
argument_list|()
specifier|const
block|{
return|return
name|Is_PragmaLexer
return|;
block|}
comment|/// IndirectLex - An indirect call to 'Lex' that can be invoked via
comment|///  the PreprocessorLexer interface.
name|void
name|IndirectLex
argument_list|(
argument|Token&Result
argument_list|)
block|{
name|Lex
argument_list|(
name|Result
argument_list|)
block|; }
comment|/// LexFromRawLexer - Lex a token from a designated raw lexer (one with no
comment|/// associated preprocessor object.  Return true if the 'next character to
comment|/// read' pointer points at the end of the lexer buffer, false otherwise.
name|bool
name|LexFromRawLexer
argument_list|(
argument|Token&Result
argument_list|)
block|{
name|assert
argument_list|(
name|LexingRawMode
operator|&&
literal|"Not already in raw mode!"
argument_list|)
block|;
name|Lex
argument_list|(
name|Result
argument_list|)
block|;
comment|// Note that lexing to the end of the buffer doesn't implicitly delete the
comment|// lexer when in raw mode.
return|return
name|BufferPtr
operator|==
name|BufferEnd
return|;
block|}
comment|/// isKeepWhitespaceMode - Return true if the lexer should return tokens for
comment|/// every character in the file, including whitespace and comments.  This
comment|/// should only be used in raw mode, as the preprocessor is not prepared to
comment|/// deal with the excess tokens.
name|bool
name|isKeepWhitespaceMode
argument_list|()
specifier|const
block|{
return|return
name|ExtendedTokenMode
operator|>
literal|1
return|;
block|}
comment|/// SetKeepWhitespaceMode - This method lets clients enable or disable
comment|/// whitespace retention mode.
name|void
name|SetKeepWhitespaceMode
argument_list|(
argument|bool Val
argument_list|)
block|{
name|assert
argument_list|(
operator|(
operator|!
name|Val
operator|||
name|LexingRawMode
operator|)
operator|&&
literal|"Can only enable whitespace retention in raw mode"
argument_list|)
block|;
name|ExtendedTokenMode
operator|=
name|Val
condition|?
literal|2
else|:
literal|0
block|;   }
comment|/// inKeepCommentMode - Return true if the lexer should return comments as
comment|/// tokens.
name|bool
name|inKeepCommentMode
argument_list|()
specifier|const
block|{
return|return
name|ExtendedTokenMode
operator|>
literal|0
return|;
block|}
comment|/// SetCommentRetentionMode - Change the comment retention mode of the lexer
comment|/// to the specified mode.  This is really only useful when lexing in raw
comment|/// mode, because otherwise the lexer needs to manage this.
name|void
name|SetCommentRetentionState
argument_list|(
argument|bool Mode
argument_list|)
block|{
name|assert
argument_list|(
operator|!
name|isKeepWhitespaceMode
argument_list|()
operator|&&
literal|"Can't play with comment retention state when retaining whitespace"
argument_list|)
block|;
name|ExtendedTokenMode
operator|=
name|Mode
condition|?
literal|1
else|:
literal|0
block|;   }
specifier|const
name|char
operator|*
name|getBufferStart
argument_list|()
specifier|const
block|{
return|return
name|BufferStart
return|;
block|}
comment|/// ReadToEndOfLine - Read the rest of the current preprocessor line as an
comment|/// uninterpreted string.  This switches the lexer out of directive mode.
name|std
operator|::
name|string
name|ReadToEndOfLine
argument_list|()
block|;
comment|/// Diag - Forwarding function for diagnostics.  This translate a source
comment|/// position in the current buffer into a SourceLocation object for rendering.
name|DiagnosticBuilder
name|Diag
argument_list|(
argument|const char *Loc
argument_list|,
argument|unsigned DiagID
argument_list|)
specifier|const
block|;
comment|/// getSourceLocation - Return a source location identifier for the specified
comment|/// offset in the current file.
name|SourceLocation
name|getSourceLocation
argument_list|(
argument|const char *Loc
argument_list|,
argument|unsigned TokLen =
literal|1
argument_list|)
specifier|const
block|;
comment|/// getSourceLocation - Return a source location for the next character in
comment|/// the current file.
name|SourceLocation
name|getSourceLocation
argument_list|()
block|{
return|return
name|getSourceLocation
argument_list|(
name|BufferPtr
argument_list|)
return|;
block|}
comment|/// Stringify - Convert the specified string into a C string by escaping '\'
comment|/// and " characters.  This does not add surrounding ""'s to the string.
comment|/// If Charify is true, this escapes the ' character instead of ".
specifier|static
name|std
operator|::
name|string
name|Stringify
argument_list|(
argument|const std::string&Str
argument_list|,
argument|bool Charify = false
argument_list|)
block|;
comment|/// Stringify - Convert the specified string into a C string by escaping '\'
comment|/// and " characters.  This does not add surrounding ""'s to the string.
specifier|static
name|void
name|Stringify
argument_list|(
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Str
argument_list|)
block|;
comment|/// MeasureTokenLength - Relex the token at the specified location and return
comment|/// its length in bytes in the input file.  If the token needs cleaning (e.g.
comment|/// includes a trigraph or an escaped newline) then this count includes bytes
comment|/// that are part of that.
specifier|static
name|unsigned
name|MeasureTokenLength
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|const SourceManager&SM
argument_list|,
argument|const LangOptions&LangOpts
argument_list|)
block|;
comment|//===--------------------------------------------------------------------===//
comment|// Internal implementation interfaces.
name|private
operator|:
comment|/// LexTokenInternal - Internal interface to lex a preprocessing token. Called
comment|/// by Lex.
comment|///
name|void
name|LexTokenInternal
argument_list|(
name|Token
operator|&
name|Result
argument_list|)
block|;
comment|/// FormTokenWithChars - When we lex a token, we have identified a span
comment|/// starting at BufferPtr, going to TokEnd that forms the token.  This method
comment|/// takes that range and assigns it to the token as its location and size.  In
comment|/// addition, since tokens cannot overlap, this also updates BufferPtr to be
comment|/// TokEnd.
name|void
name|FormTokenWithChars
argument_list|(
argument|Token&Result
argument_list|,
argument|const char *TokEnd
argument_list|,
argument|tok::TokenKind Kind
argument_list|)
block|{
name|unsigned
name|TokLen
operator|=
name|TokEnd
operator|-
name|BufferPtr
block|;
name|Result
operator|.
name|setLength
argument_list|(
name|TokLen
argument_list|)
block|;
name|Result
operator|.
name|setLocation
argument_list|(
name|getSourceLocation
argument_list|(
name|BufferPtr
argument_list|,
name|TokLen
argument_list|)
argument_list|)
block|;
name|Result
operator|.
name|setKind
argument_list|(
name|Kind
argument_list|)
block|;
name|BufferPtr
operator|=
name|TokEnd
block|;   }
comment|/// isNextPPTokenLParen - Return 1 if the next unexpanded token will return a
comment|/// tok::l_paren token, 0 if it is something else and 2 if there are no more
comment|/// tokens in the buffer controlled by this lexer.
name|unsigned
name|isNextPPTokenLParen
argument_list|()
block|;
comment|//===--------------------------------------------------------------------===//
comment|// Lexer character reading interfaces.
name|public
operator|:
comment|// This lexer is built on two interfaces for reading characters, both of which
comment|// automatically provide phase 1/2 translation.  getAndAdvanceChar is used
comment|// when we know that we will be reading a character from the input buffer and
comment|// that this character will be part of the result token. This occurs in (f.e.)
comment|// string processing, because we know we need to read until we find the
comment|// closing '"' character.
comment|//
comment|// The second interface is the combination of getCharAndSize with
comment|// ConsumeChar.  getCharAndSize reads a phase 1/2 translated character,
comment|// returning it and its size.  If the lexer decides that this character is
comment|// part of the current token, it calls ConsumeChar on it.  This two stage
comment|// approach allows us to emit diagnostics for characters (e.g. warnings about
comment|// trigraphs), knowing that they only are emitted if the character is
comment|// consumed.
comment|/// isObviouslySimpleCharacter - Return true if the specified character is
comment|/// obviously the same in translation phase 1 and translation phase 3.  This
comment|/// can return false for characters that end up being the same, but it will
comment|/// never return true for something that needs to be mapped.
specifier|static
name|bool
name|isObviouslySimpleCharacter
argument_list|(
argument|char C
argument_list|)
block|{
return|return
name|C
operator|!=
literal|'?'
operator|&&
name|C
operator|!=
literal|'\\'
return|;
block|}
comment|/// getAndAdvanceChar - Read a single 'character' from the specified buffer,
comment|/// advance over it, and return it.  This is tricky in several cases.  Here we
comment|/// just handle the trivial case and fall-back to the non-inlined
comment|/// getCharAndSizeSlow method to handle the hard case.
specifier|inline
name|char
name|getAndAdvanceChar
argument_list|(
argument|const char *&Ptr
argument_list|,
argument|Token&Tok
argument_list|)
block|{
comment|// If this is not a trigraph and not a UCN or escaped newline, return
comment|// quickly.
if|if
condition|(
name|isObviouslySimpleCharacter
argument_list|(
name|Ptr
index|[
literal|0
index|]
argument_list|)
condition|)
return|return
operator|*
name|Ptr
operator|++
return|;
name|unsigned
name|Size
operator|=
literal|0
block|;
name|char
name|C
operator|=
name|getCharAndSizeSlow
argument_list|(
name|Ptr
argument_list|,
name|Size
argument_list|,
operator|&
name|Tok
argument_list|)
block|;
name|Ptr
operator|+=
name|Size
block|;
return|return
name|C
return|;
block|}
name|private
label|:
comment|/// ConsumeChar - When a character (identified by getCharAndSize) is consumed
comment|/// and added to a given token, check to see if there are diagnostics that
comment|/// need to be emitted or flags that need to be set on the token.  If so, do
comment|/// it.
specifier|const
name|char
modifier|*
name|ConsumeChar
parameter_list|(
specifier|const
name|char
modifier|*
name|Ptr
parameter_list|,
name|unsigned
name|Size
parameter_list|,
name|Token
modifier|&
name|Tok
parameter_list|)
block|{
comment|// Normal case, we consumed exactly one token.  Just return it.
if|if
condition|(
name|Size
operator|==
literal|1
condition|)
return|return
name|Ptr
operator|+
name|Size
return|;
comment|// Otherwise, re-lex the character with a current token, allowing
comment|// diagnostics to be emitted and flags to be set.
name|Size
operator|=
literal|0
expr_stmt|;
name|getCharAndSizeSlow
argument_list|(
name|Ptr
argument_list|,
name|Size
argument_list|,
operator|&
name|Tok
argument_list|)
expr_stmt|;
return|return
name|Ptr
operator|+
name|Size
return|;
block|}
comment|/// getCharAndSize - Peek a single 'character' from the specified buffer,
comment|/// get its size, and return it.  This is tricky in several cases.  Here we
comment|/// just handle the trivial case and fall-back to the non-inlined
comment|/// getCharAndSizeSlow method to handle the hard case.
specifier|inline
name|char
name|getCharAndSize
parameter_list|(
specifier|const
name|char
modifier|*
name|Ptr
parameter_list|,
name|unsigned
modifier|&
name|Size
parameter_list|)
block|{
comment|// If this is not a trigraph and not a UCN or escaped newline, return
comment|// quickly.
if|if
condition|(
name|isObviouslySimpleCharacter
argument_list|(
name|Ptr
index|[
literal|0
index|]
argument_list|)
condition|)
block|{
name|Size
operator|=
literal|1
expr_stmt|;
return|return
operator|*
name|Ptr
return|;
block|}
name|Size
operator|=
literal|0
expr_stmt|;
return|return
name|getCharAndSizeSlow
argument_list|(
name|Ptr
argument_list|,
name|Size
argument_list|)
return|;
block|}
comment|/// getCharAndSizeSlow - Handle the slow/uncommon case of the getCharAndSize
comment|/// method.
name|char
name|getCharAndSizeSlow
parameter_list|(
specifier|const
name|char
modifier|*
name|Ptr
parameter_list|,
name|unsigned
modifier|&
name|Size
parameter_list|,
name|Token
modifier|*
name|Tok
init|=
literal|0
parameter_list|)
function_decl|;
name|public
label|:
comment|/// getCharAndSizeNoWarn - Like the getCharAndSize method, but does not ever
comment|/// emit a warning.
specifier|static
specifier|inline
name|char
name|getCharAndSizeNoWarn
parameter_list|(
specifier|const
name|char
modifier|*
name|Ptr
parameter_list|,
name|unsigned
modifier|&
name|Size
parameter_list|,
specifier|const
name|LangOptions
modifier|&
name|Features
parameter_list|)
block|{
comment|// If this is not a trigraph and not a UCN or escaped newline, return
comment|// quickly.
if|if
condition|(
name|isObviouslySimpleCharacter
argument_list|(
name|Ptr
index|[
literal|0
index|]
argument_list|)
condition|)
block|{
name|Size
operator|=
literal|1
expr_stmt|;
return|return
operator|*
name|Ptr
return|;
block|}
name|Size
operator|=
literal|0
expr_stmt|;
return|return
name|getCharAndSizeSlowNoWarn
argument_list|(
name|Ptr
argument_list|,
name|Size
argument_list|,
name|Features
argument_list|)
return|;
block|}
comment|/// getEscapedNewLineSize - Return the size of the specified escaped newline,
comment|/// or 0 if it is not an escaped newline. P[-1] is known to be a "\" on entry
comment|/// to this function.
specifier|static
name|unsigned
name|getEscapedNewLineSize
parameter_list|(
specifier|const
name|char
modifier|*
name|P
parameter_list|)
function_decl|;
comment|/// SkipEscapedNewLines - If P points to an escaped newline (or a series of
comment|/// them), skip over them and return the first non-escaped-newline found,
comment|/// otherwise return P.
specifier|static
specifier|const
name|char
modifier|*
name|SkipEscapedNewLines
parameter_list|(
specifier|const
name|char
modifier|*
name|P
parameter_list|)
function_decl|;
name|private
label|:
comment|/// getCharAndSizeSlowNoWarn - Same as getCharAndSizeSlow, but never emits a
comment|/// diagnostic.
specifier|static
name|char
name|getCharAndSizeSlowNoWarn
parameter_list|(
specifier|const
name|char
modifier|*
name|Ptr
parameter_list|,
name|unsigned
modifier|&
name|Size
parameter_list|,
specifier|const
name|LangOptions
modifier|&
name|Features
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|// Other lexer functions.
comment|// Helper functions to lex the remainder of a token of the specific type.
name|void
name|LexIdentifier
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|,
specifier|const
name|char
modifier|*
name|CurPtr
parameter_list|)
function_decl|;
name|void
name|LexNumericConstant
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|,
specifier|const
name|char
modifier|*
name|CurPtr
parameter_list|)
function_decl|;
name|void
name|LexStringLiteral
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|,
specifier|const
name|char
modifier|*
name|CurPtr
parameter_list|,
name|bool
name|Wide
parameter_list|)
function_decl|;
name|void
name|LexAngledStringLiteral
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|,
specifier|const
name|char
modifier|*
name|CurPtr
parameter_list|)
function_decl|;
name|void
name|LexCharConstant
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|,
specifier|const
name|char
modifier|*
name|CurPtr
parameter_list|)
function_decl|;
name|bool
name|LexEndOfFile
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|,
specifier|const
name|char
modifier|*
name|CurPtr
parameter_list|)
function_decl|;
name|bool
name|SkipWhitespace
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|,
specifier|const
name|char
modifier|*
name|CurPtr
parameter_list|)
function_decl|;
name|bool
name|SkipBCPLComment
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|,
specifier|const
name|char
modifier|*
name|CurPtr
parameter_list|)
function_decl|;
name|bool
name|SkipBlockComment
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|,
specifier|const
name|char
modifier|*
name|CurPtr
parameter_list|)
function_decl|;
name|bool
name|SaveBCPLComment
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|,
specifier|const
name|char
modifier|*
name|CurPtr
parameter_list|)
function_decl|;
name|bool
name|IsStartOfConflictMarker
parameter_list|(
specifier|const
name|char
modifier|*
name|CurPtr
parameter_list|)
function_decl|;
name|bool
name|HandleEndOfConflictMarker
parameter_list|(
specifier|const
name|char
modifier|*
name|CurPtr
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

