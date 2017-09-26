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
name|LLVM_CLANG_LEX_LEXER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_LEXER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LangOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/PreprocessorLexer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|DiagnosticsEngine
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
comment|/// ConflictMarkerKind - Kinds of conflict marker which the lexer might be
comment|/// recovering from.
enum|enum
name|ConflictMarkerKind
block|{
comment|/// Not within a conflict marker.
name|CMK_None
block|,
comment|/// A normal or diff3 conflict marker, initiated by at least 7 "<"s,
comment|/// separated by at least 7 "="s or "|"s, and terminated by at least 7 ">"s.
name|CMK_Normal
block|,
comment|/// A Perforce-style conflict marker, initiated by 4 ">"s,
comment|/// separated by 4 "="s, and terminated by 4 "<"s.
name|CMK_Perforce
block|}
enum|;
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
name|void
name|anchor
argument_list|()
name|override
block|;
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
name|LangOpts
block|;
comment|// LangOpts enabled by this language (cache).
name|bool
name|Is_PragmaLexer
block|;
comment|// True if lexer for _Pragma handling.
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
name|bool
name|IsAtPhysicalStartOfLine
block|;
name|bool
name|HasLeadingSpace
block|;
name|bool
name|HasLeadingEmptyMacro
block|;
comment|// CurrentConflictMarkerState - The kind of conflict marker we are handling.
name|ConflictMarkerKind
name|CurrentConflictMarkerState
block|;
name|Lexer
argument_list|(
specifier|const
name|Lexer
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
name|Lexer
operator|&
operator|)
operator|=
name|delete
block|;
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
comment|/// suitable for calls to 'LexFromRawLexer'.  This lexer assumes that the
comment|/// text range will outlive it, so it doesn't take ownership of it.
name|Lexer
argument_list|(
argument|SourceLocation FileLoc
argument_list|,
argument|const LangOptions&LangOpts
argument_list|,
argument|const char *BufStart
argument_list|,
argument|const char *BufPtr
argument_list|,
argument|const char *BufEnd
argument_list|)
block|;
comment|/// Lexer constructor - Create a new raw lexer object.  This object is only
comment|/// suitable for calls to 'LexFromRawLexer'.  This lexer assumes that the
comment|/// text range will outlive it, so it doesn't take ownership of it.
name|Lexer
argument_list|(
argument|FileID FID
argument_list|,
argument|const llvm::MemoryBuffer *InputBuffer
argument_list|,
argument|const SourceManager&SM
argument_list|,
argument|const LangOptions&LangOpts
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
argument|SourceLocation ExpansionLocStart
argument_list|,
argument|SourceLocation ExpansionLocEnd
argument_list|,
argument|unsigned TokLen
argument_list|,
argument|Preprocessor&PP
argument_list|)
block|;
comment|/// getLangOpts - Return the language features currently enabled.
comment|/// NOTE: this lexer modifies features as a file is parsed!
specifier|const
name|LangOptions
operator|&
name|getLangOpts
argument_list|()
specifier|const
block|{
return|return
name|LangOpts
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
name|private
operator|:
comment|/// Lex - Return the next token in the file.  If this is the end of file, it
comment|/// return the tok::eof token.  This implicitly involves the preprocessor.
name|bool
name|Lex
argument_list|(
name|Token
operator|&
name|Result
argument_list|)
block|;
name|public
operator|:
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
name|private
operator|:
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
name|public
operator|:
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
operator|||
name|LangOpts
operator|.
name|TraditionalCPP
operator|)
operator|&&
literal|"Can only retain whitespace in raw mode or -traditional-cpp"
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
comment|/// Sets the extended token mode back to its initial value, according to the
comment|/// language options and preprocessor. This controls whether the lexer
comment|/// produces comment and whitespace tokens.
comment|///
comment|/// This requires the lexer to have an associated preprocessor. A standalone
comment|/// lexer has nothing to reset to.
name|void
name|resetExtendedTokenMode
argument_list|()
block|;
comment|/// Gets source code buffer.
name|StringRef
name|getBuffer
argument_list|()
specifier|const
block|{
return|return
name|StringRef
argument_list|(
name|BufferStart
argument_list|,
name|BufferEnd
operator|-
name|BufferStart
argument_list|)
return|;
block|}
comment|/// ReadToEndOfLine - Read the rest of the current preprocessor line as an
comment|/// uninterpreted string.  This switches the lexer out of directive mode.
name|void
name|ReadToEndOfLine
argument_list|(
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|*
name|Result
operator|=
name|nullptr
argument_list|)
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
name|override
block|{
return|return
name|getSourceLocation
argument_list|(
name|BufferPtr
argument_list|)
return|;
block|}
comment|/// \brief Return the current location in the buffer.
specifier|const
name|char
operator|*
name|getBufferLocation
argument_list|()
specifier|const
block|{
return|return
name|BufferPtr
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
argument|StringRef Str
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
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|Str
argument_list|)
block|;
comment|/// getSpelling - This method is used to get the spelling of a token into a
comment|/// preallocated buffer, instead of as an std::string.  The caller is required
comment|/// to allocate enough space for the token, which is guaranteed to be at least
comment|/// Tok.getLength() bytes long.  The length of the actual result is returned.
comment|///
comment|/// Note that this method may do two possible things: it may either fill in
comment|/// the buffer specified with characters, or it may *change the input pointer*
comment|/// to point to a constant buffer with the data already in it (avoiding a
comment|/// copy).  The caller is not allowed to modify the returned buffer pointer
comment|/// if an internal buffer is returned.
specifier|static
name|unsigned
name|getSpelling
argument_list|(
specifier|const
name|Token
operator|&
name|Tok
argument_list|,
specifier|const
name|char
operator|*
operator|&
name|Buffer
argument_list|,
specifier|const
name|SourceManager
operator|&
name|SourceMgr
argument_list|,
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|,
name|bool
operator|*
name|Invalid
operator|=
name|nullptr
argument_list|)
block|;
comment|/// getSpelling() - Return the 'spelling' of the Tok token.  The spelling of a
comment|/// token is the characters used to represent the token in the source file
comment|/// after trigraph expansion and escaped-newline folding.  In particular, this
comment|/// wants to get the true, uncanonicalized, spelling of things like digraphs
comment|/// UCNs, etc.
specifier|static
name|std
operator|::
name|string
name|getSpelling
argument_list|(
specifier|const
name|Token
operator|&
name|Tok
argument_list|,
specifier|const
name|SourceManager
operator|&
name|SourceMgr
argument_list|,
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|,
name|bool
operator|*
name|Invalid
operator|=
name|nullptr
argument_list|)
block|;
comment|/// getSpelling - This method is used to get the spelling of the
comment|/// token at the given source location.  If, as is usually true, it
comment|/// is not necessary to copy any data, then the returned string may
comment|/// not point into the provided buffer.
comment|///
comment|/// This method lexes at the expansion depth of the given
comment|/// location and does not jump to the expansion or spelling
comment|/// location.
specifier|static
name|StringRef
name|getSpelling
argument_list|(
argument|SourceLocation loc
argument_list|,
argument|SmallVectorImpl<char>&buffer
argument_list|,
argument|const SourceManager&SourceMgr
argument_list|,
argument|const LangOptions&LangOpts
argument_list|,
argument|bool *invalid = nullptr
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
comment|/// \brief Relex the token at the specified location.
comment|/// \returns true if there was a failure, false on success.
specifier|static
name|bool
name|getRawToken
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|Token&Result
argument_list|,
argument|const SourceManager&SM
argument_list|,
argument|const LangOptions&LangOpts
argument_list|,
argument|bool IgnoreWhiteSpace = false
argument_list|)
block|;
comment|/// \brief Given a location any where in a source buffer, find the location
comment|/// that corresponds to the beginning of the token in which the original
comment|/// source location lands.
specifier|static
name|SourceLocation
name|GetBeginningOfToken
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|const SourceManager&SM
argument_list|,
argument|const LangOptions&LangOpts
argument_list|)
block|;
comment|/// AdvanceToTokenCharacter - If the current SourceLocation specifies a
comment|/// location at the start of a token, return a new location that specifies a
comment|/// character within the token.  This handles trigraphs and escaped newlines.
specifier|static
name|SourceLocation
name|AdvanceToTokenCharacter
argument_list|(
argument|SourceLocation TokStart
argument_list|,
argument|unsigned Character
argument_list|,
argument|const SourceManager&SM
argument_list|,
argument|const LangOptions&LangOpts
argument_list|)
block|;
comment|/// \brief Computes the source location just past the end of the
comment|/// token at this source location.
comment|///
comment|/// This routine can be used to produce a source location that
comment|/// points just past the end of the token referenced by \p Loc, and
comment|/// is generally used when a diagnostic needs to point just after a
comment|/// token where it expected something different that it received. If
comment|/// the returned source location would not be meaningful (e.g., if
comment|/// it points into a macro), this routine returns an invalid
comment|/// source location.
comment|///
comment|/// \param Offset an offset from the end of the token, where the source
comment|/// location should refer to. The default offset (0) produces a source
comment|/// location pointing just past the end of the token; an offset of 1 produces
comment|/// a source location pointing to the last character in the token, etc.
specifier|static
name|SourceLocation
name|getLocForEndOfToken
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|unsigned Offset
argument_list|,
argument|const SourceManager&SM
argument_list|,
argument|const LangOptions&LangOpts
argument_list|)
block|;
comment|/// \brief Given a token range, produce a corresponding CharSourceRange that
comment|/// is not a token range. This allows the source range to be used by
comment|/// components that don't have access to the lexer and thus can't find the
comment|/// end of the range for themselves.
specifier|static
name|CharSourceRange
name|getAsCharRange
argument_list|(
argument|SourceRange Range
argument_list|,
argument|const SourceManager&SM
argument_list|,
argument|const LangOptions&LangOpts
argument_list|)
block|{
name|SourceLocation
name|End
operator|=
name|getLocForEndOfToken
argument_list|(
name|Range
operator|.
name|getEnd
argument_list|()
argument_list|,
literal|0
argument_list|,
name|SM
argument_list|,
name|LangOpts
argument_list|)
block|;
return|return
name|End
operator|.
name|isInvalid
argument_list|()
condition|?
name|CharSourceRange
argument_list|()
else|:
name|CharSourceRange
operator|::
name|getCharRange
argument_list|(
name|Range
operator|.
name|getBegin
argument_list|()
argument_list|,
name|End
operator|.
name|getLocWithOffset
argument_list|(
operator|-
literal|1
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|CharSourceRange
name|getAsCharRange
argument_list|(
argument|CharSourceRange Range
argument_list|,
argument|const SourceManager&SM
argument_list|,
argument|const LangOptions&LangOpts
argument_list|)
block|{
return|return
name|Range
operator|.
name|isTokenRange
argument_list|()
condition|?
name|getAsCharRange
argument_list|(
name|Range
operator|.
name|getAsRange
argument_list|()
argument_list|,
name|SM
argument_list|,
name|LangOpts
argument_list|)
else|:
name|Range
return|;
block|}
comment|/// \brief Returns true if the given MacroID location points at the first
comment|/// token of the macro expansion.
comment|///
comment|/// \param MacroBegin If non-null and function returns true, it is set to
comment|/// begin location of the macro.
specifier|static
name|bool
name|isAtStartOfMacroExpansion
argument_list|(
argument|SourceLocation loc
argument_list|,
argument|const SourceManager&SM
argument_list|,
argument|const LangOptions&LangOpts
argument_list|,
argument|SourceLocation *MacroBegin = nullptr
argument_list|)
block|;
comment|/// \brief Returns true if the given MacroID location points at the last
comment|/// token of the macro expansion.
comment|///
comment|/// \param MacroEnd If non-null and function returns true, it is set to
comment|/// end location of the macro.
specifier|static
name|bool
name|isAtEndOfMacroExpansion
argument_list|(
argument|SourceLocation loc
argument_list|,
argument|const SourceManager&SM
argument_list|,
argument|const LangOptions&LangOpts
argument_list|,
argument|SourceLocation *MacroEnd = nullptr
argument_list|)
block|;
comment|/// \brief Accepts a range and returns a character range with file locations.
comment|///
comment|/// Returns a null range if a part of the range resides inside a macro
comment|/// expansion or the range does not reside on the same FileID.
comment|///
comment|/// This function is trying to deal with macros and return a range based on
comment|/// file locations. The cases where it can successfully handle macros are:
comment|///
comment|/// -begin or end range lies at the start or end of a macro expansion, in
comment|///  which case the location will be set to the expansion point, e.g:
comment|///    \#define M 1 2
comment|///    a M
comment|/// If you have a range [a, 2] (where 2 came from the macro), the function
comment|/// will return a range for "a M"
comment|/// if you have range [a, 1], the function will fail because the range
comment|/// overlaps with only a part of the macro
comment|///
comment|/// -The macro is a function macro and the range can be mapped to the macro
comment|///  arguments, e.g:
comment|///    \#define M 1 2
comment|///    \#define FM(x) x
comment|///    FM(a b M)
comment|/// if you have range [b, 2], the function will return the file range "b M"
comment|/// inside the macro arguments.
comment|/// if you have range [a, 2], the function will return the file range
comment|/// "FM(a b M)" since the range includes all of the macro expansion.
specifier|static
name|CharSourceRange
name|makeFileCharRange
argument_list|(
argument|CharSourceRange Range
argument_list|,
argument|const SourceManager&SM
argument_list|,
argument|const LangOptions&LangOpts
argument_list|)
block|;
comment|/// \brief Returns a string for the source that the range encompasses.
specifier|static
name|StringRef
name|getSourceText
argument_list|(
argument|CharSourceRange Range
argument_list|,
argument|const SourceManager&SM
argument_list|,
argument|const LangOptions&LangOpts
argument_list|,
argument|bool *Invalid = nullptr
argument_list|)
block|;
comment|/// \brief Retrieve the name of the immediate macro expansion.
comment|///
comment|/// This routine starts from a source location, and finds the name of the macro
comment|/// responsible for its immediate expansion. It looks through any intervening
comment|/// macro argument expansions to compute this. It returns a StringRef which
comment|/// refers to the SourceManager-owned buffer of the source where that macro
comment|/// name is spelled. Thus, the result shouldn't out-live that SourceManager.
specifier|static
name|StringRef
name|getImmediateMacroName
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|const SourceManager&SM
argument_list|,
argument|const LangOptions&LangOpts
argument_list|)
block|;
comment|/// \brief Retrieve the name of the immediate macro expansion.
comment|///
comment|/// This routine starts from a source location, and finds the name of the
comment|/// macro responsible for its immediate expansion. It looks through any
comment|/// intervening macro argument expansions to compute this. It returns a
comment|/// StringRef which refers to the SourceManager-owned buffer of the source
comment|/// where that macro name is spelled. Thus, the result shouldn't out-live
comment|/// that SourceManager.
comment|///
comment|/// This differs from Lexer::getImmediateMacroName in that any macro argument
comment|/// location will result in the topmost function macro that accepted it.
comment|/// e.g.
comment|/// \code
comment|///   MAC1( MAC2(foo) )
comment|/// \endcode
comment|/// for location of 'foo' token, this function will return "MAC1" while
comment|/// Lexer::getImmediateMacroName will return "MAC2".
specifier|static
name|StringRef
name|getImmediateMacroNameForDiagnostics
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|const SourceManager&SM
argument_list|,
argument|const LangOptions&LangOpts
argument_list|)
block|;
comment|/// \brief Compute the preamble of the given file.
comment|///
comment|/// The preamble of a file contains the initial comments, include directives,
comment|/// and other preprocessor directives that occur before the code in this
comment|/// particular file actually begins. The preamble of the main source file is
comment|/// a potential prefix header.
comment|///
comment|/// \param Buffer The memory buffer containing the file's contents.
comment|///
comment|/// \param MaxLines If non-zero, restrict the length of the preamble
comment|/// to fewer than this number of lines.
comment|///
comment|/// \returns The offset into the file where the preamble ends and the rest
comment|/// of the file begins along with a boolean value indicating whether
comment|/// the preamble ends at the beginning of a new line.
specifier|static
name|std
operator|::
name|pair
operator|<
name|unsigned
block|,
name|bool
operator|>
name|ComputePreamble
argument_list|(
argument|StringRef Buffer
argument_list|,
argument|const LangOptions&LangOpts
argument_list|,
argument|unsigned MaxLines =
literal|0
argument_list|)
block|;
comment|/// \brief Checks that the given token is the first token that occurs after
comment|/// the given location (this excludes comments and whitespace). Returns the
comment|/// location immediately after the specified token. If the token is not found
comment|/// or the location is inside a macro, the returned source location will be
comment|/// invalid.
specifier|static
name|SourceLocation
name|findLocationAfterToken
argument_list|(
argument|SourceLocation loc
argument_list|,
argument|tok::TokenKind TKind
argument_list|,
argument|const SourceManager&SM
argument_list|,
argument|const LangOptions&LangOpts
argument_list|,
argument|bool SkipTrailingWhitespaceAndNewLine
argument_list|)
block|;
comment|/// \brief Returns true if the given character could appear in an identifier.
specifier|static
name|bool
name|isIdentifierBodyChar
argument_list|(
argument|char c
argument_list|,
argument|const LangOptions&LangOpts
argument_list|)
block|;
comment|/// getCharAndSizeNoWarn - Like the getCharAndSize method, but does not ever
comment|/// emit a warning.
specifier|static
specifier|inline
name|char
name|getCharAndSizeNoWarn
argument_list|(
argument|const char *Ptr
argument_list|,
argument|unsigned&Size
argument_list|,
argument|const LangOptions&LangOpts
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
name|LangOpts
argument_list|)
return|;
block|}
comment|/// Returns the leading whitespace for line that corresponds to the given
comment|/// location \p Loc.
specifier|static
name|StringRef
name|getIndentationForLine
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
specifier|const
name|SourceManager
modifier|&
name|SM
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|// Internal implementation interfaces.
name|private
label|:
comment|/// LexTokenInternal - Internal interface to lex a preprocessing token. Called
comment|/// by Lex.
comment|///
name|bool
name|LexTokenInternal
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|,
name|bool
name|TokAtPhysicalStartOfLine
parameter_list|)
function_decl|;
name|bool
name|CheckUnicodeWhitespace
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|,
name|uint32_t
name|C
parameter_list|,
specifier|const
name|char
modifier|*
name|CurPtr
parameter_list|)
function_decl|;
comment|/// Given that a token begins with the Unicode character \p C, figure out
comment|/// what kind of token it is and dispatch to the appropriate lexing helper
comment|/// function.
name|bool
name|LexUnicode
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|,
name|uint32_t
name|C
parameter_list|,
specifier|const
name|char
modifier|*
name|CurPtr
parameter_list|)
function_decl|;
comment|/// FormTokenWithChars - When we lex a token, we have identified a span
comment|/// starting at BufferPtr, going to TokEnd that forms the token.  This method
comment|/// takes that range and assigns it to the token as its location and size.  In
comment|/// addition, since tokens cannot overlap, this also updates BufferPtr to be
comment|/// TokEnd.
name|void
name|FormTokenWithChars
argument_list|(
name|Token
operator|&
name|Result
argument_list|,
specifier|const
name|char
operator|*
name|TokEnd
argument_list|,
name|tok
operator|::
name|TokenKind
name|Kind
argument_list|)
block|{
name|unsigned
name|TokLen
init|=
name|TokEnd
operator|-
name|BufferPtr
decl_stmt|;
name|Result
operator|.
name|setLength
argument_list|(
name|TokLen
argument_list|)
expr_stmt|;
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
expr_stmt|;
name|Result
operator|.
name|setKind
argument_list|(
name|Kind
argument_list|)
expr_stmt|;
name|BufferPtr
operator|=
name|TokEnd
expr_stmt|;
block|}
comment|/// isNextPPTokenLParen - Return 1 if the next unexpanded token will return a
comment|/// tok::l_paren token, 0 if it is something else and 2 if there are no more
comment|/// tokens in the buffer controlled by this lexer.
name|unsigned
name|isNextPPTokenLParen
parameter_list|()
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|// Lexer character reading interfaces.
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
parameter_list|(
name|char
name|C
parameter_list|)
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
parameter_list|(
specifier|const
name|char
modifier|*
modifier|&
name|Ptr
parameter_list|,
name|Token
modifier|&
name|Tok
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
return|return
operator|*
name|Ptr
operator|++
return|;
name|unsigned
name|Size
init|=
literal|0
decl_stmt|;
name|char
name|C
init|=
name|getCharAndSizeSlow
argument_list|(
name|Ptr
argument_list|,
name|Size
argument_list|,
operator|&
name|Tok
argument_list|)
decl_stmt|;
name|Ptr
operator|+=
name|Size
expr_stmt|;
return|return
name|C
return|;
block|}
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
name|nullptr
parameter_list|)
function_decl|;
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
name|LangOpts
parameter_list|)
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|// Other lexer functions.
name|void
name|SkipBytes
parameter_list|(
name|unsigned
name|Bytes
parameter_list|,
name|bool
name|StartOfLine
parameter_list|)
function_decl|;
name|void
name|PropagateLineStartLeadingSpaceInfo
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|)
function_decl|;
specifier|const
name|char
modifier|*
name|LexUDSuffix
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
name|IsStringLiteral
parameter_list|)
function_decl|;
comment|// Helper functions to lex the remainder of a token of the specific type.
name|bool
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
name|bool
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
name|bool
name|LexStringLiteral
argument_list|(
name|Token
operator|&
name|Result
argument_list|,
specifier|const
name|char
operator|*
name|CurPtr
argument_list|,
name|tok
operator|::
name|TokenKind
name|Kind
argument_list|)
decl_stmt|;
name|bool
name|LexRawStringLiteral
argument_list|(
name|Token
operator|&
name|Result
argument_list|,
specifier|const
name|char
operator|*
name|CurPtr
argument_list|,
name|tok
operator|::
name|TokenKind
name|Kind
argument_list|)
decl_stmt|;
name|bool
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
name|bool
name|LexCharConstant
argument_list|(
name|Token
operator|&
name|Result
argument_list|,
specifier|const
name|char
operator|*
name|CurPtr
argument_list|,
name|tok
operator|::
name|TokenKind
name|Kind
argument_list|)
decl_stmt|;
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
parameter_list|,
name|bool
modifier|&
name|TokAtPhysicalStartOfLine
parameter_list|)
function_decl|;
name|bool
name|SkipLineComment
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
modifier|&
name|TokAtPhysicalStartOfLine
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
parameter_list|,
name|bool
modifier|&
name|TokAtPhysicalStartOfLine
parameter_list|)
function_decl|;
name|bool
name|SaveLineComment
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
name|bool
name|lexEditorPlaceholder
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
name|isCodeCompletionPoint
argument_list|(
specifier|const
name|char
operator|*
name|CurPtr
argument_list|)
decl|const
decl_stmt|;
name|void
name|cutOffLexing
parameter_list|()
block|{
name|BufferPtr
operator|=
name|BufferEnd
expr_stmt|;
block|}
name|bool
name|isHexaLiteral
parameter_list|(
specifier|const
name|char
modifier|*
name|Start
parameter_list|,
specifier|const
name|LangOptions
modifier|&
name|LangOpts
parameter_list|)
function_decl|;
comment|/// Read a universal character name.
comment|///
comment|/// \param CurPtr The position in the source buffer after the initial '\'.
comment|///               If the UCN is syntactically well-formed (but not necessarily
comment|///               valid), this parameter will be updated to point to the
comment|///               character after the UCN.
comment|/// \param SlashLoc The position in the source buffer of the '\'.
comment|/// \param Tok The token being formed. Pass \c NULL to suppress diagnostics
comment|///            and handle token formation in the caller.
comment|///
comment|/// \return The Unicode codepoint specified by the UCN, or 0 if the UCN is
comment|///         invalid.
name|uint32_t
name|tryReadUCN
parameter_list|(
specifier|const
name|char
modifier|*
modifier|&
name|CurPtr
parameter_list|,
specifier|const
name|char
modifier|*
name|SlashLoc
parameter_list|,
name|Token
modifier|*
name|Tok
parameter_list|)
function_decl|;
comment|/// \brief Try to consume a UCN as part of an identifier at the current
comment|/// location.
comment|/// \param CurPtr Initially points to the range of characters in the source
comment|///               buffer containing the '\'. Updated to point past the end of
comment|///               the UCN on success.
comment|/// \param Size The number of characters occupied by the '\' (including
comment|///             trigraphs and escaped newlines).
comment|/// \param Result The token being produced. Marked as containing a UCN on
comment|///               success.
comment|/// \return \c true if a UCN was lexed and it produced an acceptable
comment|///         identifier character, \c false otherwise.
name|bool
name|tryConsumeIdentifierUCN
parameter_list|(
specifier|const
name|char
modifier|*
modifier|&
name|CurPtr
parameter_list|,
name|unsigned
name|Size
parameter_list|,
name|Token
modifier|&
name|Result
parameter_list|)
function_decl|;
comment|/// \brief Try to consume an identifier character encoded in UTF-8.
comment|/// \param CurPtr Points to the start of the (potential) UTF-8 code unit
comment|///        sequence. On success, updated to point past the end of it.
comment|/// \return \c true if a UTF-8 sequence mapping to an acceptable identifier
comment|///         character was lexed, \c false otherwise.
name|bool
name|tryConsumeIdentifierUTF8Char
parameter_list|(
specifier|const
name|char
modifier|*
modifier|&
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

