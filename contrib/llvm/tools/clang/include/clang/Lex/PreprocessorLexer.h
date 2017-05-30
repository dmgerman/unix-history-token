begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- PreprocessorLexer.h - C Language Family Lexer ----------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the PreprocessorLexer interface.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_LEX_PREPROCESSORLEXER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_PREPROCESSORLEXER_H
end_define

begin_include
include|#
directive|include
file|"clang/Lex/MultipleIncludeOpt.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/Token.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|FileEntry
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|PreprocessorLexer
block|{
name|virtual
name|void
name|anchor
parameter_list|()
function_decl|;
name|protected
label|:
name|Preprocessor
modifier|*
name|PP
decl_stmt|;
comment|// Preprocessor object controlling lexing.
comment|/// The SourceManager FileID corresponding to the file being lexed.
specifier|const
name|FileID
name|FID
decl_stmt|;
comment|/// \brief Number of SLocEntries before lexing the file.
name|unsigned
name|InitialNumSLocEntries
decl_stmt|;
comment|//===--------------------------------------------------------------------===//
comment|// Context-specific lexing flags set by the preprocessor.
comment|//===--------------------------------------------------------------------===//
comment|/// \brief True when parsing \#XXX; turns '\\n' into a tok::eod token.
name|bool
name|ParsingPreprocessorDirective
decl_stmt|;
comment|/// \brief True after \#include; turns \<xx> into a tok::angle_string_literal
comment|/// token.
name|bool
name|ParsingFilename
decl_stmt|;
comment|/// \brief True if in raw mode.
comment|///
comment|/// Raw mode disables interpretation of tokens and is a far faster mode to
comment|/// lex in than non-raw-mode.  This flag:
comment|///  1. If EOF of the current lexer is found, the include stack isn't popped.
comment|///  2. Identifier information is not looked up for identifier tokens.  As an
comment|///     effect of this, implicit macro expansion is naturally disabled.
comment|///  3. "#" tokens at the start of a line are treated as normal tokens, not
comment|///     implicitly transformed by the lexer.
comment|///  4. All diagnostic messages are disabled.
comment|///  5. No callbacks are made into the preprocessor.
comment|///
comment|/// Note that in raw mode that the PP pointer may be null.
name|bool
name|LexingRawMode
decl_stmt|;
comment|/// \brief A state machine that detects the \#ifndef-wrapping a file
comment|/// idiom for the multiple-include optimization.
name|MultipleIncludeOpt
name|MIOpt
decl_stmt|;
comment|/// \brief Information about the set of \#if/\#ifdef/\#ifndef blocks
comment|/// we are currently in.
name|SmallVector
operator|<
name|PPConditionalInfo
operator|,
literal|4
operator|>
name|ConditionalStack
expr_stmt|;
name|PreprocessorLexer
argument_list|(
specifier|const
name|PreprocessorLexer
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|void
name|operator
init|=
operator|(
specifier|const
name|PreprocessorLexer
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|friend
name|class
name|Preprocessor
decl_stmt|;
name|PreprocessorLexer
argument_list|(
argument|Preprocessor *pp
argument_list|,
argument|FileID fid
argument_list|)
empty_stmt|;
name|PreprocessorLexer
argument_list|()
operator|:
name|PP
argument_list|(
name|nullptr
argument_list|)
operator|,
name|InitialNumSLocEntries
argument_list|(
literal|0
argument_list|)
operator|,
name|ParsingPreprocessorDirective
argument_list|(
name|false
argument_list|)
operator|,
name|ParsingFilename
argument_list|(
name|false
argument_list|)
operator|,
name|LexingRawMode
argument_list|(
argument|false
argument_list|)
block|{}
name|virtual
operator|~
name|PreprocessorLexer
argument_list|()
block|{}
name|virtual
name|void
name|IndirectLex
argument_list|(
name|Token
operator|&
name|Result
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// \brief Return the source location for the next observable location.
name|virtual
name|SourceLocation
name|getSourceLocation
parameter_list|()
init|=
literal|0
function_decl|;
comment|//===--------------------------------------------------------------------===//
comment|// #if directive handling.
comment|/// pushConditionalLevel - When we enter a \#if directive, this keeps track of
comment|/// what we are currently in for diagnostic emission (e.g. \#if with missing
comment|/// \#endif).
name|void
name|pushConditionalLevel
parameter_list|(
name|SourceLocation
name|DirectiveStart
parameter_list|,
name|bool
name|WasSkipping
parameter_list|,
name|bool
name|FoundNonSkip
parameter_list|,
name|bool
name|FoundElse
parameter_list|)
block|{
name|PPConditionalInfo
name|CI
decl_stmt|;
name|CI
operator|.
name|IfLoc
operator|=
name|DirectiveStart
expr_stmt|;
name|CI
operator|.
name|WasSkipping
operator|=
name|WasSkipping
expr_stmt|;
name|CI
operator|.
name|FoundNonSkip
operator|=
name|FoundNonSkip
expr_stmt|;
name|CI
operator|.
name|FoundElse
operator|=
name|FoundElse
expr_stmt|;
name|ConditionalStack
operator|.
name|push_back
argument_list|(
name|CI
argument_list|)
expr_stmt|;
block|}
name|void
name|pushConditionalLevel
parameter_list|(
specifier|const
name|PPConditionalInfo
modifier|&
name|CI
parameter_list|)
block|{
name|ConditionalStack
operator|.
name|push_back
argument_list|(
name|CI
argument_list|)
expr_stmt|;
block|}
comment|/// popConditionalLevel - Remove an entry off the top of the conditional
comment|/// stack, returning information about it.  If the conditional stack is empty,
comment|/// this returns true and does not fill in the arguments.
name|bool
name|popConditionalLevel
parameter_list|(
name|PPConditionalInfo
modifier|&
name|CI
parameter_list|)
block|{
if|if
condition|(
name|ConditionalStack
operator|.
name|empty
argument_list|()
condition|)
return|return
name|true
return|;
name|CI
operator|=
name|ConditionalStack
operator|.
name|pop_back_val
argument_list|()
expr_stmt|;
return|return
name|false
return|;
block|}
comment|/// \brief Return the top of the conditional stack.
comment|/// \pre This requires that there be a conditional active.
name|PPConditionalInfo
modifier|&
name|peekConditionalLevel
parameter_list|()
block|{
name|assert
argument_list|(
operator|!
name|ConditionalStack
operator|.
name|empty
argument_list|()
operator|&&
literal|"No conditionals active!"
argument_list|)
expr_stmt|;
return|return
name|ConditionalStack
operator|.
name|back
argument_list|()
return|;
block|}
name|unsigned
name|getConditionalStackDepth
argument_list|()
specifier|const
block|{
return|return
name|ConditionalStack
operator|.
name|size
argument_list|()
return|;
block|}
name|public
label|:
comment|//===--------------------------------------------------------------------===//
comment|// Misc. lexing methods.
comment|/// \brief After the preprocessor has parsed a \#include, lex and
comment|/// (potentially) macro expand the filename.
comment|///
comment|/// If the sequence parsed is not lexically legal, emit a diagnostic and
comment|/// return a result EOD token.
name|void
name|LexIncludeFilename
parameter_list|(
name|Token
modifier|&
name|Result
parameter_list|)
function_decl|;
comment|/// \brief Inform the lexer whether or not we are currently lexing a
comment|/// preprocessor directive.
name|void
name|setParsingPreprocessorDirective
parameter_list|(
name|bool
name|f
parameter_list|)
block|{
name|ParsingPreprocessorDirective
operator|=
name|f
expr_stmt|;
block|}
comment|/// \brief Return true if this lexer is in raw mode or not.
name|bool
name|isLexingRawMode
argument_list|()
specifier|const
block|{
return|return
name|LexingRawMode
return|;
block|}
comment|/// \brief Return the preprocessor object for this lexer.
name|Preprocessor
operator|*
name|getPP
argument_list|()
specifier|const
block|{
return|return
name|PP
return|;
block|}
name|FileID
name|getFileID
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|PP
operator|&&
literal|"PreprocessorLexer::getFileID() should only be used with a Preprocessor"
argument_list|)
block|;
return|return
name|FID
return|;
block|}
comment|/// \brief Number of SLocEntries before lexing the file.
name|unsigned
name|getInitialNumSLocEntries
argument_list|()
specifier|const
block|{
return|return
name|InitialNumSLocEntries
return|;
block|}
comment|/// getFileEntry - Return the FileEntry corresponding to this FileID.  Like
comment|/// getFileID(), this only works for lexers with attached preprocessors.
specifier|const
name|FileEntry
operator|*
name|getFileEntry
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Iterator that traverses the current stack of preprocessor
comment|/// conditional directives (\#if/\#ifdef/\#ifndef).
typedef|typedef
name|SmallVectorImpl
operator|<
name|PPConditionalInfo
operator|>
operator|::
name|const_iterator
name|conditional_iterator
expr_stmt|;
name|conditional_iterator
name|conditional_begin
argument_list|()
specifier|const
block|{
return|return
name|ConditionalStack
operator|.
name|begin
argument_list|()
return|;
block|}
name|conditional_iterator
name|conditional_end
argument_list|()
specifier|const
block|{
return|return
name|ConditionalStack
operator|.
name|end
argument_list|()
return|;
block|}
name|void
name|setConditionalLevels
argument_list|(
name|ArrayRef
operator|<
name|PPConditionalInfo
operator|>
name|CL
argument_list|)
block|{
name|ConditionalStack
operator|.
name|clear
argument_list|()
expr_stmt|;
name|ConditionalStack
operator|.
name|append
argument_list|(
name|CL
operator|.
name|begin
argument_list|()
argument_list|,
name|CL
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
block|}
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

