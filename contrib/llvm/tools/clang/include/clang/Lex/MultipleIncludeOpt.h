begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- MultipleIncludeOpt.h - Header Multiple-Include Optzn ---*- C++ -*-===//
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
comment|/// \brief Defines the MultipleIncludeOpt interface.
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
name|LLVM_CLANG_MULTIPLEINCLUDEOPT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_MULTIPLEINCLUDEOPT_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|IdentifierInfo
decl_stmt|;
comment|/// \brief Implements the simple state machine that the Lexer class uses to
comment|/// detect files subject to the 'multiple-include' optimization.
comment|///
comment|/// The public methods in this class are triggered by various
comment|/// events that occur when a file is lexed, and after the entire file is lexed,
comment|/// information about which macro (if any) controls the header is returned.
name|class
name|MultipleIncludeOpt
block|{
comment|/// ReadAnyTokens - This is set to false when a file is first opened and true
comment|/// any time a token is returned to the client or a (non-multiple-include)
comment|/// directive is parsed.  When the final \#endif is parsed this is reset back
comment|/// to false, that way any tokens before the first \#ifdef or after the last
comment|/// \#endif can be easily detected.
name|bool
name|ReadAnyTokens
decl_stmt|;
comment|/// ReadAnyTokens - This is set to false when a file is first opened and true
comment|/// any time a token is returned to the client or a (non-multiple-include)
comment|/// directive is parsed.  When the final #endif is parsed this is reset back
comment|/// to false, that way any tokens before the first #ifdef or after the last
comment|/// #endif can be easily detected.
name|bool
name|DidMacroExpansion
decl_stmt|;
comment|/// TheMacro - The controlling macro for a file, if valid.
comment|///
specifier|const
name|IdentifierInfo
modifier|*
name|TheMacro
decl_stmt|;
name|public
label|:
name|MultipleIncludeOpt
argument_list|()
block|{
name|ReadAnyTokens
operator|=
name|false
expr_stmt|;
name|DidMacroExpansion
operator|=
name|false
expr_stmt|;
name|TheMacro
operator|=
literal|0
expr_stmt|;
block|}
comment|/// Invalidate - Permanently mark this file as not being suitable for the
comment|/// include-file optimization.
name|void
name|Invalidate
parameter_list|()
block|{
comment|// If we have read tokens but have no controlling macro, the state-machine
comment|// below can never "accept".
name|ReadAnyTokens
operator|=
name|true
expr_stmt|;
name|TheMacro
operator|=
literal|0
expr_stmt|;
block|}
comment|/// getHasReadAnyTokensVal - This is used for the \#ifndef hande-shake at the
comment|/// top of the file when reading preprocessor directives.  Otherwise, reading
comment|/// the "ifndef x" would count as reading tokens.
name|bool
name|getHasReadAnyTokensVal
argument_list|()
specifier|const
block|{
return|return
name|ReadAnyTokens
return|;
block|}
comment|// If a token is read, remember that we have seen a side-effect in this file.
name|void
name|ReadToken
parameter_list|()
block|{
name|ReadAnyTokens
operator|=
name|true
expr_stmt|;
block|}
comment|/// ExpandedMacro - When a macro is expanded with this lexer as the current
comment|/// buffer, this method is called to disable the MIOpt if needed.
name|void
name|ExpandedMacro
parameter_list|()
block|{
name|DidMacroExpansion
operator|=
name|true
expr_stmt|;
block|}
comment|/// \brief Called when entering a top-level \#ifndef directive (or the
comment|/// "\#if !defined" equivalent) without any preceding tokens.
comment|///
comment|/// Note, we don't care about the input value of 'ReadAnyTokens'.  The caller
comment|/// ensures that this is only called if there are no tokens read before the
comment|/// \#ifndef.  The caller is required to do this, because reading the \#if
comment|/// line obviously reads in in tokens.
name|void
name|EnterTopLevelIFNDEF
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|*
name|M
parameter_list|)
block|{
comment|// If the macro is already set, this is after the top-level #endif.
if|if
condition|(
name|TheMacro
condition|)
return|return
name|Invalidate
argument_list|()
return|;
comment|// If we have already expanded a macro by the end of the #ifndef line, then
comment|// there is a macro expansion *in* the #ifndef line.  This means that the
comment|// condition could evaluate differently when subsequently #included.  Reject
comment|// this.
if|if
condition|(
name|DidMacroExpansion
condition|)
return|return
name|Invalidate
argument_list|()
return|;
comment|// Remember that we're in the #if and that we have the macro.
name|ReadAnyTokens
operator|=
name|true
expr_stmt|;
name|TheMacro
operator|=
name|M
expr_stmt|;
block|}
comment|/// \brief Invoked when a top level conditional (except \#ifndef) is found.
name|void
name|EnterTopLevelConditional
parameter_list|()
block|{
comment|// If a conditional directive (except #ifndef) is found at the top level,
comment|// there is a chunk of the file not guarded by the controlling macro.
name|Invalidate
argument_list|()
expr_stmt|;
block|}
comment|/// \brief Called when the lexer exits the top-level conditional.
name|void
name|ExitTopLevelConditional
parameter_list|()
block|{
comment|// If we have a macro, that means the top of the file was ok.  Set our state
comment|// back to "not having read any tokens" so we can detect anything after the
comment|// #endif.
if|if
condition|(
operator|!
name|TheMacro
condition|)
return|return
name|Invalidate
argument_list|()
return|;
comment|// At this point, we haven't "read any tokens" but we do have a controlling
comment|// macro.
name|ReadAnyTokens
operator|=
name|false
expr_stmt|;
block|}
comment|/// \brief Once the entire file has been lexed, if there is a controlling
comment|/// macro, return it.
specifier|const
name|IdentifierInfo
operator|*
name|GetControllingMacroAtEndOfFile
argument_list|()
specifier|const
block|{
comment|// If we haven't read any tokens after the #endif, return the controlling
comment|// macro if it's valid (if it isn't, it will be null).
if|if
condition|(
operator|!
name|ReadAnyTokens
condition|)
return|return
name|TheMacro
return|;
return|return
literal|0
return|;
block|}
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

