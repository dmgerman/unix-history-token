begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TokenLexer.h - Lex from a token buffer -----------------*- C++ -*-===//
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
comment|// This file defines the TokenLexer interface.
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
name|LLVM_CLANG_TOKENLEXER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOKENLEXER_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|MacroInfo
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|Token
decl_stmt|;
name|class
name|MacroArgs
decl_stmt|;
comment|/// TokenLexer - This implements a lexer that returns tokens from a macro body
comment|/// or token stream instead of lexing from a character buffer.  This is used for
comment|/// macro expansion and _Pragma handling, for example.
comment|///
name|class
name|TokenLexer
block|{
comment|/// Macro - The macro we are expanding from.  This is null if expanding a
comment|/// token stream.
comment|///
name|MacroInfo
modifier|*
name|Macro
decl_stmt|;
comment|/// ActualArgs - The actual arguments specified for a function-like macro, or
comment|/// null.  The TokenLexer owns the pointed-to object.
name|MacroArgs
modifier|*
name|ActualArgs
decl_stmt|;
comment|/// PP - The current preprocessor object we are expanding for.
comment|///
name|Preprocessor
modifier|&
name|PP
decl_stmt|;
comment|/// Tokens - This is the pointer to an array of tokens that the macro is
comment|/// defined to, with arguments expanded for function-like macros.  If this is
comment|/// a token stream, these are the tokens we are returning.  This points into
comment|/// the macro definition we are lexing from, a cache buffer that is owned by
comment|/// the preprocessor, or some other buffer that we may or may not own
comment|/// (depending on OwnsTokens).
comment|/// Note that if it points into Preprocessor's cache buffer, the Preprocessor
comment|/// may update the pointer as needed.
specifier|const
name|Token
modifier|*
name|Tokens
decl_stmt|;
name|friend
name|class
name|Preprocessor
decl_stmt|;
comment|/// NumTokens - This is the length of the Tokens array.
comment|///
name|unsigned
name|NumTokens
decl_stmt|;
comment|/// CurToken - This is the next token that Lex will return.
comment|///
name|unsigned
name|CurToken
decl_stmt|;
comment|/// ExpandLocStart/End - The source location range where this macro was
comment|/// expanded.
name|SourceLocation
name|ExpandLocStart
decl_stmt|,
name|ExpandLocEnd
decl_stmt|;
comment|/// \brief Source location pointing at the source location entry chunk that
comment|/// was reserved for the current macro expansion.
name|SourceLocation
name|MacroExpansionStart
decl_stmt|;
comment|/// \brief The offset of the macro expansion in the
comment|/// "source location address space".
name|unsigned
name|MacroStartSLocOffset
decl_stmt|;
comment|/// \brief Location of the macro definition.
name|SourceLocation
name|MacroDefStart
decl_stmt|;
comment|/// \brief Length of the macro definition.
name|unsigned
name|MacroDefLength
decl_stmt|;
comment|/// Lexical information about the expansion point of the macro: the identifier
comment|/// that the macro expanded from had these properties.
name|bool
name|AtStartOfLine
range|:
literal|1
decl_stmt|;
name|bool
name|HasLeadingSpace
range|:
literal|1
decl_stmt|;
comment|/// OwnsTokens - This is true if this TokenLexer allocated the Tokens
comment|/// array, and thus needs to free it when destroyed.  For simple object-like
comment|/// macros (for example) we just point into the token buffer of the macro
comment|/// definition, we don't make a copy of it.
name|bool
name|OwnsTokens
range|:
literal|1
decl_stmt|;
comment|/// DisableMacroExpansion - This is true when tokens lexed from the TokenLexer
comment|/// should not be subject to further macro expansion.
name|bool
name|DisableMacroExpansion
range|:
literal|1
decl_stmt|;
name|TokenLexer
argument_list|(
argument|const TokenLexer&
argument_list|)
name|LLVM_DELETED_FUNCTION
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|TokenLexer
operator|&
operator|)
name|LLVM_DELETED_FUNCTION
decl_stmt|;
name|public
label|:
comment|/// Create a TokenLexer for the specified macro with the specified actual
comment|/// arguments.  Note that this ctor takes ownership of the ActualArgs pointer.
comment|/// ILEnd specifies the location of the ')' for a function-like macro or the
comment|/// identifier for an object-like macro.
name|TokenLexer
argument_list|(
argument|Token&Tok
argument_list|,
argument|SourceLocation ILEnd
argument_list|,
argument|MacroInfo *MI
argument_list|,
argument|MacroArgs *ActualArgs
argument_list|,
argument|Preprocessor&pp
argument_list|)
block|:
name|Macro
argument_list|(
literal|0
argument_list|)
operator|,
name|ActualArgs
argument_list|(
literal|0
argument_list|)
operator|,
name|PP
argument_list|(
name|pp
argument_list|)
operator|,
name|OwnsTokens
argument_list|(
argument|false
argument_list|)
block|{
name|Init
argument_list|(
name|Tok
argument_list|,
name|ILEnd
argument_list|,
name|MI
argument_list|,
name|ActualArgs
argument_list|)
block|;   }
comment|/// Init - Initialize this TokenLexer to expand from the specified macro
comment|/// with the specified argument information.  Note that this ctor takes
comment|/// ownership of the ActualArgs pointer.  ILEnd specifies the location of the
comment|/// ')' for a function-like macro or the identifier for an object-like macro.
name|void
name|Init
argument_list|(
argument|Token&Tok
argument_list|,
argument|SourceLocation ILEnd
argument_list|,
argument|MacroInfo *MI
argument_list|,
argument|MacroArgs *ActualArgs
argument_list|)
expr_stmt|;
comment|/// Create a TokenLexer for the specified token stream.  If 'OwnsTokens' is
comment|/// specified, this takes ownership of the tokens and delete[]'s them when
comment|/// the token lexer is empty.
name|TokenLexer
argument_list|(
argument|const Token *TokArray
argument_list|,
argument|unsigned NumToks
argument_list|,
argument|bool DisableExpansion
argument_list|,
argument|bool ownsTokens
argument_list|,
argument|Preprocessor&pp
argument_list|)
block|:
name|Macro
argument_list|(
literal|0
argument_list|)
operator|,
name|ActualArgs
argument_list|(
literal|0
argument_list|)
operator|,
name|PP
argument_list|(
name|pp
argument_list|)
operator|,
name|OwnsTokens
argument_list|(
argument|false
argument_list|)
block|{
name|Init
argument_list|(
name|TokArray
argument_list|,
name|NumToks
argument_list|,
name|DisableExpansion
argument_list|,
name|ownsTokens
argument_list|)
block|;   }
comment|/// Init - Initialize this TokenLexer with the specified token stream.
comment|/// This does not take ownership of the specified token vector.
comment|///
comment|/// DisableExpansion is true when macro expansion of tokens lexed from this
comment|/// stream should be disabled.
name|void
name|Init
argument_list|(
argument|const Token *TokArray
argument_list|,
argument|unsigned NumToks
argument_list|,
argument|bool DisableMacroExpansion
argument_list|,
argument|bool OwnsTokens
argument_list|)
expr_stmt|;
operator|~
name|TokenLexer
argument_list|()
block|{
name|destroy
argument_list|()
block|; }
comment|/// isNextTokenLParen - If the next token lexed will pop this macro off the
comment|/// expansion stack, return 2.  If the next unexpanded token is a '(', return
comment|/// 1, otherwise return 0.
name|unsigned
name|isNextTokenLParen
argument_list|()
specifier|const
expr_stmt|;
comment|/// Lex - Lex and return a token from this macro stream.
name|bool
name|Lex
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
comment|/// isParsingPreprocessorDirective - Return true if we are in the middle of a
comment|/// preprocessor directive.
name|bool
name|isParsingPreprocessorDirective
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|void
name|destroy
parameter_list|()
function_decl|;
comment|/// isAtEnd - Return true if the next lex call will pop this macro off the
comment|/// include stack.
name|bool
name|isAtEnd
argument_list|()
specifier|const
block|{
return|return
name|CurToken
operator|==
name|NumTokens
return|;
block|}
comment|/// PasteTokens - Tok is the LHS of a ## operator, and CurToken is the ##
comment|/// operator.  Read the ## and RHS, and paste the LHS/RHS together.  If there
comment|/// are is another ## after it, chomp it iteratively.  Return the result as
comment|/// Tok.  If this returns true, the caller should immediately return the
comment|/// token.
name|bool
name|PasteTokens
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
comment|/// Expand the arguments of a function-like macro so that we can quickly
comment|/// return preexpanded tokens from Tokens.
name|void
name|ExpandFunctionArguments
parameter_list|()
function_decl|;
comment|/// HandleMicrosoftCommentPaste - In microsoft compatibility mode, /##/ pastes
comment|/// together to form a comment that comments out everything in the current
comment|/// macro, other active macros, and anything left on the current physical
comment|/// source line of the expanded buffer.  Handle this by returning the
comment|/// first token on the next line.
name|void
name|HandleMicrosoftCommentPaste
parameter_list|(
name|Token
modifier|&
name|Tok
parameter_list|)
function_decl|;
comment|/// \brief If \p loc is a FileID and points inside the current macro
comment|/// definition, returns the appropriate source location pointing at the
comment|/// macro expansion source location entry.
name|SourceLocation
name|getExpansionLocForMacroDefLoc
argument_list|(
name|SourceLocation
name|loc
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Creates SLocEntries and updates the locations of macro argument
comment|/// tokens to their new expanded locations.
comment|///
comment|/// \param ArgIdSpellLoc the location of the macro argument id inside the
comment|/// macro definition.
name|void
name|updateLocForMacroArgTokens
parameter_list|(
name|SourceLocation
name|ArgIdSpellLoc
parameter_list|,
name|Token
modifier|*
name|begin_tokens
parameter_list|,
name|Token
modifier|*
name|end_tokens
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
block|}
empty_stmt|;
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

