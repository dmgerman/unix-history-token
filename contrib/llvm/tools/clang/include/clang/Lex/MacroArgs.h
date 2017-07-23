begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- MacroArgs.h - Formal argument info for Macros ----------*- C++ -*-===//
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
comment|// This file defines the MacroArgs interface.
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
name|LLVM_CLANG_LEX_MACROARGS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LEX_MACROARGS_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
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
file|<vector>
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
name|SourceLocation
decl_stmt|;
comment|/// MacroArgs - An instance of this class captures information about
comment|/// the formal arguments specified to a function-like macro invocation.
name|class
name|MacroArgs
block|{
comment|/// NumUnexpArgTokens - The number of raw, unexpanded tokens for the
comment|/// arguments.  All of the actual argument tokens are allocated immediately
comment|/// after the MacroArgs object in memory.  This is all of the arguments
comment|/// concatenated together, with 'EOF' markers at the end of each argument.
name|unsigned
name|NumUnexpArgTokens
decl_stmt|;
comment|/// VarargsElided - True if this is a C99 style varargs macro invocation and
comment|/// there was no argument specified for the "..." argument.  If the argument
comment|/// was specified (even empty) or this isn't a C99 style varargs function, or
comment|/// if in strict mode and the C99 varargs macro had only a ... argument, this
comment|/// is false.
name|bool
name|VarargsElided
decl_stmt|;
comment|/// PreExpArgTokens - Pre-expanded tokens for arguments that need them.  Empty
comment|/// if not yet computed.  This includes the EOF marker at the end of the
comment|/// stream.
name|std
operator|::
name|vector
operator|<
name|std
operator|::
name|vector
operator|<
name|Token
operator|>
expr|>
name|PreExpArgTokens
expr_stmt|;
comment|/// StringifiedArgs - This contains arguments in 'stringified' form.  If the
comment|/// stringified form of an argument has not yet been computed, this is empty.
name|std
operator|::
name|vector
operator|<
name|Token
operator|>
name|StringifiedArgs
expr_stmt|;
comment|/// ArgCache - This is a linked list of MacroArgs objects that the
comment|/// Preprocessor owns which we use to avoid thrashing malloc/free.
name|MacroArgs
modifier|*
name|ArgCache
decl_stmt|;
comment|/// MacroArgs - The number of arguments the invoked macro expects.
name|unsigned
name|NumMacroArgs
decl_stmt|;
name|MacroArgs
argument_list|(
argument|unsigned NumToks
argument_list|,
argument|bool varargsElided
argument_list|,
argument|unsigned MacroArgs
argument_list|)
block|:
name|NumUnexpArgTokens
argument_list|(
name|NumToks
argument_list|)
operator|,
name|VarargsElided
argument_list|(
name|varargsElided
argument_list|)
operator|,
name|ArgCache
argument_list|(
name|nullptr
argument_list|)
operator|,
name|NumMacroArgs
argument_list|(
argument|MacroArgs
argument_list|)
block|{}
operator|~
name|MacroArgs
argument_list|()
operator|=
expr|default
expr_stmt|;
name|public
label|:
comment|/// MacroArgs ctor function - Create a new MacroArgs object with the specified
comment|/// macro and argument info.
specifier|static
name|MacroArgs
modifier|*
name|create
argument_list|(
specifier|const
name|MacroInfo
operator|*
name|MI
argument_list|,
name|ArrayRef
operator|<
name|Token
operator|>
name|UnexpArgTokens
argument_list|,
name|bool
name|VarargsElided
argument_list|,
name|Preprocessor
operator|&
name|PP
argument_list|)
decl_stmt|;
comment|/// destroy - Destroy and deallocate the memory for this object.
comment|///
name|void
name|destroy
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|)
function_decl|;
comment|/// ArgNeedsPreexpansion - If we can prove that the argument won't be affected
comment|/// by pre-expansion, return false.  Otherwise, conservatively return true.
name|bool
name|ArgNeedsPreexpansion
argument_list|(
specifier|const
name|Token
operator|*
name|ArgTok
argument_list|,
name|Preprocessor
operator|&
name|PP
argument_list|)
decl|const
decl_stmt|;
comment|/// getUnexpArgument - Return a pointer to the first token of the unexpanded
comment|/// token list for the specified formal.
comment|///
specifier|const
name|Token
modifier|*
name|getUnexpArgument
argument_list|(
name|unsigned
name|Arg
argument_list|)
decl|const
decl_stmt|;
comment|/// getArgLength - Given a pointer to an expanded or unexpanded argument,
comment|/// return the number of tokens, not counting the EOF, that make up the
comment|/// argument.
specifier|static
name|unsigned
name|getArgLength
parameter_list|(
specifier|const
name|Token
modifier|*
name|ArgPtr
parameter_list|)
function_decl|;
comment|/// getPreExpArgument - Return the pre-expanded form of the specified
comment|/// argument.
specifier|const
name|std
operator|::
name|vector
operator|<
name|Token
operator|>
operator|&
name|getPreExpArgument
argument_list|(
argument|unsigned Arg
argument_list|,
argument|const MacroInfo *MI
argument_list|,
argument|Preprocessor&PP
argument_list|)
expr_stmt|;
comment|/// getStringifiedArgument - Compute, cache, and return the specified argument
comment|/// that has been 'stringified' as required by the # operator.
specifier|const
name|Token
modifier|&
name|getStringifiedArgument
parameter_list|(
name|unsigned
name|ArgNo
parameter_list|,
name|Preprocessor
modifier|&
name|PP
parameter_list|,
name|SourceLocation
name|ExpansionLocStart
parameter_list|,
name|SourceLocation
name|ExpansionLocEnd
parameter_list|)
function_decl|;
comment|/// getNumMacroArguments - Return the number of arguments the invoked macro
comment|/// expects.
name|unsigned
name|getNumMacroArguments
argument_list|()
specifier|const
block|{
return|return
name|NumMacroArgs
return|;
block|}
comment|/// isVarargsElidedUse - Return true if this is a C99 style varargs macro
comment|/// invocation and there was no argument specified for the "..." argument.  If
comment|/// the argument was specified (even empty) or this isn't a C99 style varargs
comment|/// function, or if in strict mode and the C99 varargs macro had only a ...
comment|/// argument, this returns false.
name|bool
name|isVarargsElidedUse
argument_list|()
specifier|const
block|{
return|return
name|VarargsElided
return|;
block|}
comment|/// StringifyArgument - Implement C99 6.10.3.2p2, converting a sequence of
comment|/// tokens into the literal string token that should be produced by the C #
comment|/// preprocessor operator.  If Charify is true, then it should be turned into
comment|/// a character literal for the Microsoft charize (#@) extension.
comment|///
specifier|static
name|Token
name|StringifyArgument
parameter_list|(
specifier|const
name|Token
modifier|*
name|ArgToks
parameter_list|,
name|Preprocessor
modifier|&
name|PP
parameter_list|,
name|bool
name|Charify
parameter_list|,
name|SourceLocation
name|ExpansionLocStart
parameter_list|,
name|SourceLocation
name|ExpansionLocEnd
parameter_list|)
function_decl|;
comment|/// deallocate - This should only be called by the Preprocessor when managing
comment|/// its freelist.
name|MacroArgs
modifier|*
name|deallocate
parameter_list|()
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

