begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- MacroInfo.h - Information about #defined identifiers ---*- C++ -*-===//
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
comment|// This file defines the MacroInfo interface.
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
name|LLVM_CLANG_MACROINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_MACROINFO_H
end_define

begin_include
include|#
directive|include
file|"clang/Lex/Token.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Allocator.h"
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
name|Preprocessor
decl_stmt|;
comment|/// MacroInfo - Each identifier that is #define'd has an instance of this class
comment|/// associated with it, used to implement macro expansion.
name|class
name|MacroInfo
block|{
comment|//===--------------------------------------------------------------------===//
comment|// State set when the macro is defined.
comment|/// Location - This is the place the macro is defined.
name|SourceLocation
name|Location
decl_stmt|;
comment|/// EndLocation - The location of the last token in the macro.
name|SourceLocation
name|EndLocation
decl_stmt|;
comment|/// Arguments - The list of arguments for a function-like macro.  This can be
comment|/// empty, for, e.g. "#define X()".  In a C99-style variadic macro, this
comment|/// includes the __VA_ARGS__ identifier on the list.
name|IdentifierInfo
modifier|*
modifier|*
name|ArgumentList
decl_stmt|;
name|unsigned
name|NumArguments
decl_stmt|;
comment|/// ReplacementTokens - This is the list of tokens that the macro is defined
comment|/// to.
name|llvm
operator|::
name|SmallVector
operator|<
name|Token
operator|,
literal|8
operator|>
name|ReplacementTokens
expr_stmt|;
comment|/// IsFunctionLike - True if this macro is a function-like macro, false if it
comment|/// is an object-like macro.
name|bool
name|IsFunctionLike
range|:
literal|1
decl_stmt|;
comment|/// IsC99Varargs - True if this macro is of the form "#define X(...)" or
comment|/// "#define X(Y,Z,...)".  The __VA_ARGS__ token should be replaced with the
comment|/// contents of "..." in an invocation.
name|bool
name|IsC99Varargs
range|:
literal|1
decl_stmt|;
comment|/// IsGNUVarargs -  True if this macro is of the form "#define X(a...)".  The
comment|/// "a" identifier in the replacement list will be replaced with all arguments
comment|/// of the macro starting with the specified one.
name|bool
name|IsGNUVarargs
range|:
literal|1
decl_stmt|;
comment|/// IsBuiltinMacro - True if this is a builtin macro, such as __LINE__, and if
comment|/// it has not yet been redefined or undefined.
name|bool
name|IsBuiltinMacro
range|:
literal|1
decl_stmt|;
comment|/// IsFromAST - True if this macro was loaded from an AST file.
name|bool
name|IsFromAST
range|:
literal|1
decl_stmt|;
name|private
label|:
comment|//===--------------------------------------------------------------------===//
comment|// State that changes as the macro is used.
comment|/// IsDisabled - True if we have started an expansion of this macro already.
comment|/// This disbles recursive expansion, which would be quite bad for things like
comment|/// #define A A.
name|bool
name|IsDisabled
range|:
literal|1
decl_stmt|;
comment|/// IsUsed - True if this macro is either defined in the main file and has
comment|/// been used, or if it is not defined in the main file.  This is used to
comment|/// emit -Wunused-macros diagnostics.
name|bool
name|IsUsed
range|:
literal|1
decl_stmt|;
comment|/// AllowRedefinitionsWithoutWarning - True if this macro can be redefined
comment|/// without emitting a warning.
name|bool
name|IsAllowRedefinitionsWithoutWarning
range|:
literal|1
decl_stmt|;
comment|/// \brief Must warn if the macro is unused at the end of translation unit.
name|bool
name|IsWarnIfUnused
range|:
literal|1
decl_stmt|;
operator|~
name|MacroInfo
argument_list|()
block|{
name|assert
argument_list|(
name|ArgumentList
operator|==
literal|0
operator|&&
literal|"Didn't call destroy before dtor!"
argument_list|)
block|;   }
name|public
operator|:
name|MacroInfo
argument_list|(
argument|SourceLocation DefLoc
argument_list|)
expr_stmt|;
name|MacroInfo
argument_list|(
specifier|const
name|MacroInfo
operator|&
name|MI
argument_list|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|&
name|PPAllocator
argument_list|)
expr_stmt|;
comment|/// FreeArgumentList - Free the argument list of the macro, restoring it to a
comment|/// state where it can be reused for other devious purposes.
name|void
name|FreeArgumentList
parameter_list|()
block|{
name|ArgumentList
operator|=
literal|0
expr_stmt|;
name|NumArguments
operator|=
literal|0
expr_stmt|;
block|}
comment|/// Destroy - destroy this MacroInfo object.
name|void
name|Destroy
parameter_list|()
block|{
name|FreeArgumentList
argument_list|()
expr_stmt|;
name|this
operator|->
expr|~
name|MacroInfo
argument_list|()
expr_stmt|;
block|}
comment|/// getDefinitionLoc - Return the location that the macro was defined at.
comment|///
name|SourceLocation
name|getDefinitionLoc
argument_list|()
specifier|const
block|{
return|return
name|Location
return|;
block|}
comment|/// setDefinitionEndLoc - Set the location of the last token in the macro.
comment|///
name|void
name|setDefinitionEndLoc
parameter_list|(
name|SourceLocation
name|EndLoc
parameter_list|)
block|{
name|EndLocation
operator|=
name|EndLoc
expr_stmt|;
block|}
comment|/// getDefinitionEndLoc - Return the location of the last token in the macro.
comment|///
name|SourceLocation
name|getDefinitionEndLoc
argument_list|()
specifier|const
block|{
return|return
name|EndLocation
return|;
block|}
comment|/// isIdenticalTo - Return true if the specified macro definition is equal to
comment|/// this macro in spelling, arguments, and whitespace.  This is used to emit
comment|/// duplicate definition warnings.  This implements the rules in C99 6.10.3.
name|bool
name|isIdenticalTo
argument_list|(
specifier|const
name|MacroInfo
operator|&
name|Other
argument_list|,
name|Preprocessor
operator|&
name|PP
argument_list|)
decl|const
decl_stmt|;
comment|/// setIsBuiltinMacro - Set or clear the isBuiltinMacro flag.
comment|///
name|void
name|setIsBuiltinMacro
parameter_list|(
name|bool
name|Val
init|=
name|true
parameter_list|)
block|{
name|IsBuiltinMacro
operator|=
name|Val
expr_stmt|;
block|}
comment|/// setIsUsed - Set the value of the IsUsed flag.
comment|///
name|void
name|setIsUsed
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|IsUsed
operator|=
name|Val
expr_stmt|;
block|}
comment|/// setIsAllowRedefinitionsWithoutWarning - Set the value of the
comment|/// IsAllowRedefinitionsWithoutWarning flag.
name|void
name|setIsAllowRedefinitionsWithoutWarning
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|IsAllowRedefinitionsWithoutWarning
operator|=
name|Val
expr_stmt|;
block|}
comment|/// \brief Set the value of the IsWarnIfUnused flag.
name|void
name|setIsWarnIfUnused
parameter_list|(
name|bool
name|val
parameter_list|)
block|{
name|IsWarnIfUnused
operator|=
name|val
expr_stmt|;
block|}
comment|/// setArgumentList - Set the specified list of identifiers as the argument
comment|/// list for this macro.
name|void
name|setArgumentList
argument_list|(
name|IdentifierInfo
operator|*
specifier|const
operator|*
name|List
argument_list|,
name|unsigned
name|NumArgs
argument_list|,
name|llvm
operator|::
name|BumpPtrAllocator
operator|&
name|PPAllocator
argument_list|)
block|{
name|assert
argument_list|(
name|ArgumentList
operator|==
literal|0
operator|&&
name|NumArguments
operator|==
literal|0
operator|&&
literal|"Argument list already set!"
argument_list|)
expr_stmt|;
if|if
condition|(
name|NumArgs
operator|==
literal|0
condition|)
return|return;
name|NumArguments
operator|=
name|NumArgs
expr_stmt|;
name|ArgumentList
operator|=
name|PPAllocator
operator|.
name|Allocate
operator|<
name|IdentifierInfo
operator|*
operator|>
operator|(
name|NumArgs
operator|)
expr_stmt|;
for|for
control|(
name|unsigned
name|i
init|=
literal|0
init|;
name|i
operator|!=
name|NumArgs
condition|;
operator|++
name|i
control|)
name|ArgumentList
index|[
name|i
index|]
operator|=
name|List
index|[
name|i
index|]
expr_stmt|;
block|}
comment|/// Arguments - The list of arguments for a function-like macro.  This can be
comment|/// empty, for, e.g. "#define X()".
typedef|typedef
name|IdentifierInfo
modifier|*
specifier|const
modifier|*
name|arg_iterator
typedef|;
name|bool
name|arg_empty
argument_list|()
specifier|const
block|{
return|return
name|NumArguments
operator|==
literal|0
return|;
block|}
name|arg_iterator
name|arg_begin
argument_list|()
specifier|const
block|{
return|return
name|ArgumentList
return|;
block|}
name|arg_iterator
name|arg_end
argument_list|()
specifier|const
block|{
return|return
name|ArgumentList
operator|+
name|NumArguments
return|;
block|}
name|unsigned
name|getNumArgs
argument_list|()
specifier|const
block|{
return|return
name|NumArguments
return|;
block|}
comment|/// getArgumentNum - Return the argument number of the specified identifier,
comment|/// or -1 if the identifier is not a formal argument identifier.
name|int
name|getArgumentNum
argument_list|(
name|IdentifierInfo
operator|*
name|Arg
argument_list|)
decl|const
block|{
for|for
control|(
name|arg_iterator
name|I
init|=
name|arg_begin
argument_list|()
init|,
name|E
init|=
name|arg_end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
if|if
condition|(
operator|*
name|I
operator|==
name|Arg
condition|)
return|return
name|I
operator|-
name|arg_begin
argument_list|()
return|;
return|return
operator|-
literal|1
return|;
block|}
comment|/// Function/Object-likeness.  Keep track of whether this macro has formal
comment|/// parameters.
name|void
name|setIsFunctionLike
parameter_list|()
block|{
name|IsFunctionLike
operator|=
name|true
expr_stmt|;
block|}
name|bool
name|isFunctionLike
argument_list|()
specifier|const
block|{
return|return
name|IsFunctionLike
return|;
block|}
name|bool
name|isObjectLike
argument_list|()
specifier|const
block|{
return|return
operator|!
name|IsFunctionLike
return|;
block|}
comment|/// Varargs querying methods.  This can only be set for function-like macros.
name|void
name|setIsC99Varargs
parameter_list|()
block|{
name|IsC99Varargs
operator|=
name|true
expr_stmt|;
block|}
name|void
name|setIsGNUVarargs
parameter_list|()
block|{
name|IsGNUVarargs
operator|=
name|true
expr_stmt|;
block|}
name|bool
name|isC99Varargs
argument_list|()
specifier|const
block|{
return|return
name|IsC99Varargs
return|;
block|}
name|bool
name|isGNUVarargs
argument_list|()
specifier|const
block|{
return|return
name|IsGNUVarargs
return|;
block|}
name|bool
name|isVariadic
argument_list|()
specifier|const
block|{
return|return
name|IsC99Varargs
operator||
name|IsGNUVarargs
return|;
block|}
comment|/// isBuiltinMacro - Return true if this macro is a builtin macro, such as
comment|/// __LINE__, which requires processing before expansion.
name|bool
name|isBuiltinMacro
argument_list|()
specifier|const
block|{
return|return
name|IsBuiltinMacro
return|;
block|}
comment|/// isFromAST - Return true if this macro was loaded from an AST file.
name|bool
name|isFromAST
argument_list|()
specifier|const
block|{
return|return
name|IsFromAST
return|;
block|}
comment|/// setIsFromAST - Set whether this macro was loaded from an AST file.
name|void
name|setIsFromAST
parameter_list|(
name|bool
name|FromAST
init|=
name|true
parameter_list|)
block|{
name|IsFromAST
operator|=
name|FromAST
expr_stmt|;
block|}
comment|/// isUsed - Return false if this macro is defined in the main file and has
comment|/// not yet been used.
name|bool
name|isUsed
argument_list|()
specifier|const
block|{
return|return
name|IsUsed
return|;
block|}
comment|/// isAllowRedefinitionsWithoutWarning - Return true if this macro can be
comment|/// redefined without warning.
name|bool
name|isAllowRedefinitionsWithoutWarning
argument_list|()
specifier|const
block|{
return|return
name|IsAllowRedefinitionsWithoutWarning
return|;
block|}
comment|/// \brief Return true if we should emit a warning if the macro is unused.
name|bool
name|isWarnIfUnused
argument_list|()
specifier|const
block|{
return|return
name|IsWarnIfUnused
return|;
block|}
comment|/// getNumTokens - Return the number of tokens that this macro expands to.
comment|///
name|unsigned
name|getNumTokens
argument_list|()
specifier|const
block|{
return|return
name|ReplacementTokens
operator|.
name|size
argument_list|()
return|;
block|}
specifier|const
name|Token
modifier|&
name|getReplacementToken
argument_list|(
name|unsigned
name|Tok
argument_list|)
decl|const
block|{
name|assert
argument_list|(
name|Tok
operator|<
name|ReplacementTokens
operator|.
name|size
argument_list|()
operator|&&
literal|"Invalid token #"
argument_list|)
expr_stmt|;
return|return
name|ReplacementTokens
index|[
name|Tok
index|]
return|;
block|}
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|Token
operator|,
literal|8
operator|>
operator|::
name|const_iterator
name|tokens_iterator
expr_stmt|;
name|tokens_iterator
name|tokens_begin
argument_list|()
specifier|const
block|{
return|return
name|ReplacementTokens
operator|.
name|begin
argument_list|()
return|;
block|}
name|tokens_iterator
name|tokens_end
argument_list|()
specifier|const
block|{
return|return
name|ReplacementTokens
operator|.
name|end
argument_list|()
return|;
block|}
name|bool
name|tokens_empty
argument_list|()
specifier|const
block|{
return|return
name|ReplacementTokens
operator|.
name|empty
argument_list|()
return|;
block|}
comment|/// AddTokenToBody - Add the specified token to the replacement text for the
comment|/// macro.
name|void
name|AddTokenToBody
parameter_list|(
specifier|const
name|Token
modifier|&
name|Tok
parameter_list|)
block|{
name|ReplacementTokens
operator|.
name|push_back
argument_list|(
name|Tok
argument_list|)
expr_stmt|;
block|}
comment|/// isEnabled - Return true if this macro is enabled: in other words, that we
comment|/// are not currently in an expansion of this macro.
name|bool
name|isEnabled
argument_list|()
specifier|const
block|{
return|return
operator|!
name|IsDisabled
return|;
block|}
name|void
name|EnableMacro
parameter_list|()
block|{
name|assert
argument_list|(
name|IsDisabled
operator|&&
literal|"Cannot enable an already-enabled macro!"
argument_list|)
expr_stmt|;
name|IsDisabled
operator|=
name|false
expr_stmt|;
block|}
name|void
name|DisableMacro
parameter_list|()
block|{
name|assert
argument_list|(
operator|!
name|IsDisabled
operator|&&
literal|"Cannot disable an already-disabled macro!"
argument_list|)
expr_stmt|;
name|IsDisabled
operator|=
name|true
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

