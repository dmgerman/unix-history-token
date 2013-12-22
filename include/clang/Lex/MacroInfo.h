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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines the clang::MacroInfo and clang::MacroDirective classes.
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
comment|/// \brief Encapsulates the data about a macro definition (e.g. its tokens).
comment|///
comment|/// There's an instance of this class for every #define.
name|class
name|MacroInfo
block|{
comment|//===--------------------------------------------------------------------===//
comment|// State set when the macro is defined.
comment|/// \brief The location the macro is defined.
name|SourceLocation
name|Location
decl_stmt|;
comment|/// \brief The location of the last token in the macro.
name|SourceLocation
name|EndLocation
decl_stmt|;
comment|/// \brief The list of arguments for a function-like macro.
comment|///
comment|/// ArgumentList points to the first of NumArguments pointers.
comment|///
comment|/// This can be empty, for, e.g. "#define X()".  In a C99-style variadic macro, this
comment|/// includes the \c __VA_ARGS__ identifier on the list.
name|IdentifierInfo
modifier|*
modifier|*
name|ArgumentList
decl_stmt|;
comment|/// \see ArgumentList
name|unsigned
name|NumArguments
decl_stmt|;
comment|/// \brief This is the list of tokens that the macro is defined to.
name|SmallVector
operator|<
name|Token
operator|,
literal|8
operator|>
name|ReplacementTokens
expr_stmt|;
comment|/// \brief Length in characters of the macro definition.
name|mutable
name|unsigned
name|DefinitionLength
decl_stmt|;
name|mutable
name|bool
name|IsDefinitionLengthCached
range|:
literal|1
decl_stmt|;
comment|/// \brief True if this macro is function-like, false if it is object-like.
name|bool
name|IsFunctionLike
range|:
literal|1
decl_stmt|;
comment|/// \brief True if this macro is of the form "#define X(...)" or
comment|/// "#define X(Y,Z,...)".
comment|///
comment|/// The __VA_ARGS__ token should be replaced with the contents of "..." in an
comment|/// invocation.
name|bool
name|IsC99Varargs
range|:
literal|1
decl_stmt|;
comment|/// \brief True if this macro is of the form "#define X(a...)".
comment|///
comment|/// The "a" identifier in the replacement list will be replaced with all arguments
comment|/// of the macro starting with the specified one.
name|bool
name|IsGNUVarargs
range|:
literal|1
decl_stmt|;
comment|/// \brief True if this macro requires processing before expansion.
comment|///
comment|/// This is the case for builtin macros such as __LINE__, so long as they have
comment|/// not been redefined, but not for regular predefined macros from the "<built-in>"
comment|/// memory buffer (see Preprocessing::getPredefinesFileID).
name|bool
name|IsBuiltinMacro
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether this macro contains the sequence ", ## __VA_ARGS__"
name|bool
name|HasCommaPasting
range|:
literal|1
decl_stmt|;
name|private
label|:
comment|//===--------------------------------------------------------------------===//
comment|// State that changes as the macro is used.
comment|/// \brief True if we have started an expansion of this macro already.
comment|///
comment|/// This disables recursive expansion, which would be quite bad for things
comment|/// like \#define A A.
name|bool
name|IsDisabled
range|:
literal|1
decl_stmt|;
comment|/// \brief True if this macro is either defined in the main file and has
comment|/// been used, or if it is not defined in the main file.
comment|///
comment|/// This is used to emit -Wunused-macros diagnostics.
name|bool
name|IsUsed
range|:
literal|1
decl_stmt|;
comment|/// \brief True if this macro can be redefined without emitting a warning.
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
comment|/// \brief Whether this macro info was loaded from an AST file.
name|unsigned
name|FromASTFile
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
comment|/// \brief Free the argument list of the macro.
comment|///
comment|/// This restores this MacroInfo to a state where it can be reused for other
comment|/// devious purposes.
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
comment|/// \brief Destroy this MacroInfo object.
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
comment|/// \brief Return the location that the macro was defined at.
name|SourceLocation
name|getDefinitionLoc
argument_list|()
specifier|const
block|{
return|return
name|Location
return|;
block|}
comment|/// \brief Set the location of the last token in the macro.
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
comment|/// \brief Return the location of the last token in the macro.
name|SourceLocation
name|getDefinitionEndLoc
argument_list|()
specifier|const
block|{
return|return
name|EndLocation
return|;
block|}
comment|/// \brief Get length in characters of the macro definition.
name|unsigned
name|getDefinitionLength
argument_list|(
name|SourceManager
operator|&
name|SM
argument_list|)
decl|const
block|{
if|if
condition|(
name|IsDefinitionLengthCached
condition|)
return|return
name|DefinitionLength
return|;
return|return
name|getDefinitionLengthSlow
argument_list|(
name|SM
argument_list|)
return|;
block|}
comment|/// \brief Return true if the specified macro definition is equal to
comment|/// this macro in spelling, arguments, and whitespace.
comment|///
comment|/// \param Syntactically if true, the macro definitions can be identical even
comment|/// if they use different identifiers for the function macro parameters.
comment|/// Otherwise the comparison is lexical and this implements the rules in
comment|/// C99 6.10.3.
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
argument_list|,
name|bool
name|Syntactically
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Set or clear the isBuiltinMacro flag.
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
comment|/// \brief Set the value of the IsUsed flag.
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
comment|/// \brief Set the value of the IsAllowRedefinitionsWithoutWarning flag.
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
comment|/// \brief Set the specified list of identifiers as the argument list for
comment|/// this macro.
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
comment|/// \brief Return the argument number of the specified identifier,
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
comment|/// \brief Return true if this macro requires processing before expansion.
comment|///
comment|/// This is true only for builtin macro, such as \__LINE__, whose values
comment|/// are not given by fixed textual expansions.  Regular predefined macros
comment|/// from the "<built-in>" buffer are not reported as builtins by this
comment|/// function.
name|bool
name|isBuiltinMacro
argument_list|()
specifier|const
block|{
return|return
name|IsBuiltinMacro
return|;
block|}
name|bool
name|hasCommaPasting
argument_list|()
specifier|const
block|{
return|return
name|HasCommaPasting
return|;
block|}
name|void
name|setHasCommaPasting
parameter_list|()
block|{
name|HasCommaPasting
operator|=
name|true
expr_stmt|;
block|}
comment|/// \brief Return false if this macro is defined in the main file and has
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
comment|/// \brief Return true if this macro can be redefined without warning.
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
comment|/// \brief Return the number of tokens that this macro expands to.
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
name|SmallVectorImpl
operator|<
name|Token
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
comment|/// \brief Add the specified token to the replacement text for the macro.
name|void
name|AddTokenToBody
parameter_list|(
specifier|const
name|Token
modifier|&
name|Tok
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|IsDefinitionLengthCached
operator|&&
literal|"Changing replacement tokens after definition length got calculated"
argument_list|)
expr_stmt|;
name|ReplacementTokens
operator|.
name|push_back
argument_list|(
name|Tok
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Return true if this macro is enabled.
comment|///
comment|/// In other words, that we are not currently in an expansion of this macro.
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
comment|/// \brief Determine whether this macro info came from an AST file (such as
comment|/// a precompiled header or module) rather than having been parsed.
name|bool
name|isFromASTFile
argument_list|()
specifier|const
block|{
return|return
name|FromASTFile
return|;
block|}
comment|/// \brief Retrieve the global ID of the module that owns this particular
comment|/// macro info.
name|unsigned
name|getOwningModuleID
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isFromASTFile
argument_list|()
condition|)
return|return
operator|*
operator|(
specifier|const
name|unsigned
operator|*
operator|)
operator|(
name|this
operator|+
literal|1
operator|)
return|;
return|return
literal|0
return|;
block|}
name|private
label|:
name|unsigned
name|getDefinitionLengthSlow
argument_list|(
name|SourceManager
operator|&
name|SM
argument_list|)
decl|const
decl_stmt|;
name|void
name|setOwningModuleID
parameter_list|(
name|unsigned
name|ID
parameter_list|)
block|{
name|assert
argument_list|(
name|isFromASTFile
argument_list|()
argument_list|)
expr_stmt|;
operator|*
operator|(
name|unsigned
operator|*
operator|)
operator|(
name|this
operator|+
literal|1
operator|)
operator|=
name|ID
expr_stmt|;
block|}
name|friend
name|class
name|Preprocessor
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|DefMacroDirective
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief Encapsulates changes to the "macros namespace" (the location where
end_comment

begin_comment
comment|/// the macro name became active, the location where it was undefined, etc.).
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// MacroDirectives, associated with an identifier, are used to model the macro
end_comment

begin_comment
comment|/// history. Usually a macro definition (MacroInfo) is where a macro name
end_comment

begin_comment
comment|/// becomes active (MacroDirective) but modules can have their own macro
end_comment

begin_comment
comment|/// history, separate from the local (current translation unit) macro history.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// For example, if "@import A;" imports macro FOO, there will be a new local
end_comment

begin_comment
comment|/// MacroDirective created to indicate that "FOO" became active at the import
end_comment

begin_comment
comment|/// location. Module "A" itself will contain another MacroDirective in its macro
end_comment

begin_comment
comment|/// history (at the point of the definition of FOO) and both MacroDirectives
end_comment

begin_comment
comment|/// will point to the same MacroInfo object.
end_comment

begin_comment
comment|///
end_comment

begin_decl_stmt
name|class
name|MacroDirective
block|{
name|public
label|:
enum|enum
name|Kind
block|{
name|MD_Define
block|,
name|MD_Undefine
block|,
name|MD_Visibility
block|}
enum|;
name|protected
label|:
comment|/// \brief Previous macro directive for the same identifier, or NULL.
name|MacroDirective
modifier|*
name|Previous
decl_stmt|;
name|SourceLocation
name|Loc
decl_stmt|;
comment|/// \brief MacroDirective kind.
name|unsigned
name|MDKind
range|:
literal|2
decl_stmt|;
comment|/// \brief True if the macro directive was loaded from a PCH file.
name|bool
name|IsFromPCH
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether the macro directive is currently "hidden".
comment|///
comment|/// Note that this is transient state that is never serialized to the AST
comment|/// file.
name|bool
name|IsHidden
range|:
literal|1
decl_stmt|;
comment|// Used by DefMacroDirective -----------------------------------------------//
comment|/// \brief True if this macro was imported from a module.
name|bool
name|IsImported
range|:
literal|1
decl_stmt|;
comment|/// \brief Whether the definition of this macro is ambiguous, due to
comment|/// multiple definitions coming in from multiple modules.
name|bool
name|IsAmbiguous
range|:
literal|1
decl_stmt|;
comment|// Used by VisibilityMacroDirective ----------------------------------------//
comment|/// \brief Whether the macro has public visibility (when described in a
comment|/// module).
name|bool
name|IsPublic
range|:
literal|1
decl_stmt|;
name|MacroDirective
argument_list|(
argument|Kind K
argument_list|,
argument|SourceLocation Loc
argument_list|)
block|:
name|Previous
argument_list|(
literal|0
argument_list|)
operator|,
name|Loc
argument_list|(
name|Loc
argument_list|)
operator|,
name|MDKind
argument_list|(
name|K
argument_list|)
operator|,
name|IsFromPCH
argument_list|(
name|false
argument_list|)
operator|,
name|IsHidden
argument_list|(
name|false
argument_list|)
operator|,
name|IsImported
argument_list|(
name|false
argument_list|)
operator|,
name|IsAmbiguous
argument_list|(
name|false
argument_list|)
operator|,
name|IsPublic
argument_list|(
argument|true
argument_list|)
block|{   }
name|public
operator|:
name|Kind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
argument_list|(
name|MDKind
argument_list|)
return|;
block|}
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|Loc
return|;
block|}
comment|/// \brief Set previous definition of the macro with the same name.
name|void
name|setPrevious
parameter_list|(
name|MacroDirective
modifier|*
name|Prev
parameter_list|)
block|{
name|Previous
operator|=
name|Prev
expr_stmt|;
block|}
comment|/// \brief Get previous definition of the macro with the same name.
specifier|const
name|MacroDirective
operator|*
name|getPrevious
argument_list|()
specifier|const
block|{
return|return
name|Previous
return|;
block|}
comment|/// \brief Get previous definition of the macro with the same name.
name|MacroDirective
modifier|*
name|getPrevious
parameter_list|()
block|{
return|return
name|Previous
return|;
block|}
comment|/// \brief Return true if the macro directive was loaded from a PCH file.
name|bool
name|isFromPCH
argument_list|()
specifier|const
block|{
return|return
name|IsFromPCH
return|;
block|}
name|void
name|setIsFromPCH
parameter_list|()
block|{
name|IsFromPCH
operator|=
name|true
expr_stmt|;
block|}
comment|/// \brief Determine whether this macro directive is hidden.
name|bool
name|isHidden
argument_list|()
specifier|const
block|{
return|return
name|IsHidden
return|;
block|}
comment|/// \brief Set whether this macro directive is hidden.
name|void
name|setHidden
parameter_list|(
name|bool
name|Val
parameter_list|)
block|{
name|IsHidden
operator|=
name|Val
expr_stmt|;
block|}
name|class
name|DefInfo
block|{
name|DefMacroDirective
modifier|*
name|DefDirective
decl_stmt|;
name|SourceLocation
name|UndefLoc
decl_stmt|;
name|bool
name|IsPublic
decl_stmt|;
name|public
label|:
name|DefInfo
argument_list|()
operator|:
name|DefDirective
argument_list|(
literal|0
argument_list|)
block|{ }
name|DefInfo
argument_list|(
argument|DefMacroDirective *DefDirective
argument_list|,
argument|SourceLocation UndefLoc
argument_list|,
argument|bool isPublic
argument_list|)
operator|:
name|DefDirective
argument_list|(
name|DefDirective
argument_list|)
operator|,
name|UndefLoc
argument_list|(
name|UndefLoc
argument_list|)
operator|,
name|IsPublic
argument_list|(
argument|isPublic
argument_list|)
block|{ }
specifier|const
name|DefMacroDirective
operator|*
name|getDirective
argument_list|()
specifier|const
block|{
return|return
name|DefDirective
return|;
block|}
name|DefMacroDirective
modifier|*
name|getDirective
parameter_list|()
block|{
return|return
name|DefDirective
return|;
block|}
specifier|inline
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
expr_stmt|;
specifier|inline
name|MacroInfo
modifier|*
name|getMacroInfo
parameter_list|()
function_decl|;
specifier|const
name|MacroInfo
operator|*
name|getMacroInfo
argument_list|()
specifier|const
block|{
return|return
name|const_cast
operator|<
name|DefInfo
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getMacroInfo
argument_list|()
return|;
block|}
name|SourceLocation
name|getUndefLocation
argument_list|()
specifier|const
block|{
return|return
name|UndefLoc
return|;
block|}
name|bool
name|isUndefined
argument_list|()
specifier|const
block|{
return|return
name|UndefLoc
operator|.
name|isValid
argument_list|()
return|;
block|}
name|bool
name|isPublic
argument_list|()
specifier|const
block|{
return|return
name|IsPublic
return|;
block|}
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
name|DefDirective
operator|!=
literal|0
return|;
block|}
name|bool
name|isInvalid
argument_list|()
specifier|const
block|{
return|return
operator|!
name|isValid
argument_list|()
return|;
block|}
name|LLVM_EXPLICIT
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|isValid
argument_list|()
return|;
block|}
specifier|inline
name|DefInfo
name|getPreviousDefinition
parameter_list|(
name|bool
name|AllowHidden
init|=
name|false
parameter_list|)
function_decl|;
specifier|const
name|DefInfo
name|getPreviousDefinition
argument_list|(
name|bool
name|AllowHidden
operator|=
name|false
argument_list|)
decl|const
block|{
return|return
name|const_cast
operator|<
name|DefInfo
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getPreviousDefinition
argument_list|(
name|AllowHidden
argument_list|)
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Traverses the macro directives history and returns the next
comment|/// macro definition directive along with info about its undefined location
comment|/// (if there is one) and if it is public or private.
name|DefInfo
name|getDefinition
parameter_list|(
name|bool
name|AllowHidden
init|=
name|false
parameter_list|)
function_decl|;
specifier|const
name|DefInfo
name|getDefinition
argument_list|(
name|bool
name|AllowHidden
operator|=
name|false
argument_list|)
decl|const
block|{
return|return
name|const_cast
operator|<
name|MacroDirective
operator|*
operator|>
operator|(
name|this
operator|)
operator|->
name|getDefinition
argument_list|(
name|AllowHidden
argument_list|)
return|;
block|}
name|bool
name|isDefined
argument_list|(
name|bool
name|AllowHidden
operator|=
name|false
argument_list|)
decl|const
block|{
if|if
condition|(
specifier|const
name|DefInfo
name|Def
init|=
name|getDefinition
argument_list|(
name|AllowHidden
argument_list|)
condition|)
return|return
operator|!
name|Def
operator|.
name|isUndefined
argument_list|()
return|;
return|return
name|false
return|;
block|}
specifier|const
name|MacroInfo
modifier|*
name|getMacroInfo
argument_list|(
name|bool
name|AllowHidden
operator|=
name|false
argument_list|)
decl|const
block|{
return|return
name|getDefinition
argument_list|(
name|AllowHidden
argument_list|)
operator|.
name|getMacroInfo
argument_list|()
return|;
block|}
name|MacroInfo
modifier|*
name|getMacroInfo
parameter_list|(
name|bool
name|AllowHidden
init|=
name|false
parameter_list|)
block|{
return|return
name|getDefinition
argument_list|(
name|AllowHidden
argument_list|)
operator|.
name|getMacroInfo
argument_list|()
return|;
block|}
comment|/// \brief Find macro definition active in the specified source location. If
comment|/// this macro was not defined there, return NULL.
specifier|const
name|DefInfo
name|findDirectiveAtLoc
argument_list|(
name|SourceLocation
name|L
argument_list|,
name|SourceManager
operator|&
name|SM
argument_list|)
decl|const
decl_stmt|;
specifier|static
name|bool
name|classof
parameter_list|(
specifier|const
name|MacroDirective
modifier|*
parameter_list|)
block|{
return|return
name|true
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A directive for a defined macro or a macro imported from a module.
end_comment

begin_decl_stmt
name|class
name|DefMacroDirective
range|:
name|public
name|MacroDirective
block|{
name|MacroInfo
operator|*
name|Info
block|;
name|public
operator|:
name|explicit
name|DefMacroDirective
argument_list|(
name|MacroInfo
operator|*
name|MI
argument_list|)
operator|:
name|MacroDirective
argument_list|(
name|MD_Define
argument_list|,
name|MI
operator|->
name|getDefinitionLoc
argument_list|()
argument_list|)
block|,
name|Info
argument_list|(
argument|MI
argument_list|)
block|{
name|assert
argument_list|(
name|MI
operator|&&
literal|"MacroInfo is null"
argument_list|)
block|;   }
name|DefMacroDirective
argument_list|(
argument|MacroInfo *MI
argument_list|,
argument|SourceLocation Loc
argument_list|,
argument|bool isImported
argument_list|)
operator|:
name|MacroDirective
argument_list|(
name|MD_Define
argument_list|,
name|Loc
argument_list|)
block|,
name|Info
argument_list|(
argument|MI
argument_list|)
block|{
name|assert
argument_list|(
name|MI
operator|&&
literal|"MacroInfo is null"
argument_list|)
block|;
name|IsImported
operator|=
name|isImported
block|;   }
comment|/// \brief The data for the macro definition.
specifier|const
name|MacroInfo
operator|*
name|getInfo
argument_list|()
specifier|const
block|{
return|return
name|Info
return|;
block|}
name|MacroInfo
operator|*
name|getInfo
argument_list|()
block|{
return|return
name|Info
return|;
block|}
comment|/// \brief True if this macro was imported from a module.
name|bool
name|isImported
argument_list|()
specifier|const
block|{
return|return
name|IsImported
return|;
block|}
comment|/// \brief Determine whether this macro definition is ambiguous with
comment|/// other macro definitions.
name|bool
name|isAmbiguous
argument_list|()
specifier|const
block|{
return|return
name|IsAmbiguous
return|;
block|}
comment|/// \brief Set whether this macro definition is ambiguous.
name|void
name|setAmbiguous
argument_list|(
argument|bool Val
argument_list|)
block|{
name|IsAmbiguous
operator|=
name|Val
block|; }
specifier|static
name|bool
name|classof
argument_list|(
argument|const MacroDirective *MD
argument_list|)
block|{
return|return
name|MD
operator|->
name|getKind
argument_list|()
operator|==
name|MD_Define
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const DefMacroDirective *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// \brief A directive for an undefined macro.
name|class
name|UndefMacroDirective
operator|:
name|public
name|MacroDirective
block|{
name|public
operator|:
name|explicit
name|UndefMacroDirective
argument_list|(
argument|SourceLocation UndefLoc
argument_list|)
operator|:
name|MacroDirective
argument_list|(
argument|MD_Undefine
argument_list|,
argument|UndefLoc
argument_list|)
block|{
name|assert
argument_list|(
name|UndefLoc
operator|.
name|isValid
argument_list|()
operator|&&
literal|"Invalid UndefLoc!"
argument_list|)
block|;   }
specifier|static
name|bool
name|classof
argument_list|(
argument|const MacroDirective *MD
argument_list|)
block|{
return|return
name|MD
operator|->
name|getKind
argument_list|()
operator|==
name|MD_Undefine
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const UndefMacroDirective *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
comment|/// \brief A directive for setting the module visibility of a macro.
name|class
name|VisibilityMacroDirective
operator|:
name|public
name|MacroDirective
block|{
name|public
operator|:
name|explicit
name|VisibilityMacroDirective
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|bool Public
argument_list|)
operator|:
name|MacroDirective
argument_list|(
argument|MD_Visibility
argument_list|,
argument|Loc
argument_list|)
block|{
name|IsPublic
operator|=
name|Public
block|;   }
comment|/// \brief Determine whether this macro is part of the public API of its
comment|/// module.
name|bool
name|isPublic
argument_list|()
specifier|const
block|{
return|return
name|IsPublic
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const MacroDirective *MD
argument_list|)
block|{
return|return
name|MD
operator|->
name|getKind
argument_list|()
operator|==
name|MD_Visibility
return|;
block|}
specifier|static
name|bool
name|classof
argument_list|(
argument|const VisibilityMacroDirective *
argument_list|)
block|{
return|return
name|true
return|;
block|}
expr|}
block|;
specifier|inline
name|SourceLocation
name|MacroDirective
operator|::
name|DefInfo
operator|::
name|getLocation
argument_list|()
specifier|const
block|{
if|if
condition|(
name|isInvalid
argument_list|()
condition|)
return|return
name|SourceLocation
argument_list|()
return|;
return|return
name|DefDirective
operator|->
name|getLocation
argument_list|()
return|;
block|}
specifier|inline
name|MacroInfo
operator|*
name|MacroDirective
operator|::
name|DefInfo
operator|::
name|getMacroInfo
argument_list|()
block|{
if|if
condition|(
name|isInvalid
argument_list|()
condition|)
return|return
literal|0
return|;
return|return
name|DefDirective
operator|->
name|getInfo
argument_list|()
return|;
block|}
specifier|inline
name|MacroDirective
operator|::
name|DefInfo
name|MacroDirective
operator|::
name|DefInfo
operator|::
name|getPreviousDefinition
argument_list|(
argument|bool AllowHidden
argument_list|)
block|{
if|if
condition|(
name|isInvalid
argument_list|()
operator|||
name|DefDirective
operator|->
name|getPrevious
argument_list|()
operator|==
literal|0
condition|)
return|return
name|DefInfo
argument_list|()
return|;
return|return
name|DefDirective
operator|->
name|getPrevious
argument_list|()
operator|->
name|getDefinition
argument_list|(
name|AllowHidden
argument_list|)
return|;
block|}
end_decl_stmt

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

