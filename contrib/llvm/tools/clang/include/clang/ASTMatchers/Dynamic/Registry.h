begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Registry.h - Matcher registry -----*- C++ -*-===//
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
comment|/// \brief Registry of all known matchers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The registry provides a generic interface to construct any matcher by name.
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
name|LLVM_CLANG_ASTMATCHERS_DYNAMIC_REGISTRY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ASTMATCHERS_DYNAMIC_REGISTRY_H
end_define

begin_include
include|#
directive|include
file|"clang/ASTMatchers/Dynamic/Diagnostics.h"
end_include

begin_include
include|#
directive|include
file|"clang/ASTMatchers/Dynamic/VariantValue.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ast_matchers
block|{
name|namespace
name|dynamic
block|{
name|namespace
name|internal
block|{
name|class
name|MatcherDescriptor
decl_stmt|;
block|}
typedef|typedef
specifier|const
name|internal
operator|::
name|MatcherDescriptor
operator|*
name|MatcherCtor
expr_stmt|;
struct|struct
name|MatcherCompletion
block|{
name|MatcherCompletion
argument_list|()
block|{}
name|MatcherCompletion
argument_list|(
argument|StringRef TypedText
argument_list|,
argument|StringRef MatcherDecl
argument_list|,
argument|unsigned Specificity
argument_list|)
block|:
name|TypedText
argument_list|(
name|TypedText
argument_list|)
operator|,
name|MatcherDecl
argument_list|(
name|MatcherDecl
argument_list|)
operator|,
name|Specificity
argument_list|(
argument|Specificity
argument_list|)
block|{}
comment|/// \brief The text to type to select this matcher.
name|std
operator|::
name|string
name|TypedText
expr_stmt|;
comment|/// \brief The "declaration" of the matcher, with type information.
name|std
operator|::
name|string
name|MatcherDecl
expr_stmt|;
comment|/// \brief Value corresponding to the "specificity" of the converted matcher.
comment|///
comment|/// Zero specificity indicates that this conversion would produce a trivial
comment|/// matcher that will either always or never match.
comment|/// Such matchers are excluded from code completion results.
name|unsigned
name|Specificity
decl_stmt|;
name|bool
name|operator
operator|==
operator|(
specifier|const
name|MatcherCompletion
operator|&
name|Other
operator|)
specifier|const
block|{
return|return
name|TypedText
operator|==
name|Other
operator|.
name|TypedText
operator|&&
name|MatcherDecl
operator|==
name|Other
operator|.
name|MatcherDecl
return|;
block|}
block|}
struct|;
name|class
name|Registry
block|{
name|public
label|:
comment|/// \brief Look up a matcher in the registry by name,
comment|///
comment|/// \return An opaque value which may be used to refer to the matcher
comment|/// constructor, or Optional<MatcherCtor>() if not found.
specifier|static
name|llvm
operator|::
name|Optional
operator|<
name|MatcherCtor
operator|>
name|lookupMatcherCtor
argument_list|(
argument|StringRef MatcherName
argument_list|)
expr_stmt|;
comment|/// \brief Compute the list of completion types for \p Context.
comment|///
comment|/// Each element of \p Context represents a matcher invocation, going from
comment|/// outermost to innermost. Elements are pairs consisting of a reference to
comment|/// the matcher constructor and the index of the next element in the
comment|/// argument list of that matcher (or for the last element, the index of
comment|/// the completion point in the argument list). An empty list requests
comment|/// completion for the root matcher.
specifier|static
name|std
operator|::
name|vector
operator|<
name|ArgKind
operator|>
name|getAcceptedCompletionTypes
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
name|std
operator|::
name|pair
operator|<
name|MatcherCtor
argument_list|,
name|unsigned
operator|>>
name|Context
argument_list|)
expr_stmt|;
comment|/// \brief Compute the list of completions that match any of
comment|/// \p AcceptedTypes.
comment|///
comment|/// \param AcceptedTypes All types accepted for this completion.
comment|///
comment|/// \return All completions for the specified types.
comment|/// Completions should be valid when used in \c lookupMatcherCtor().
comment|/// The matcher constructed from the return of \c lookupMatcherCtor()
comment|/// should be convertible to some type in \p AcceptedTypes.
specifier|static
name|std
operator|::
name|vector
operator|<
name|MatcherCompletion
operator|>
name|getMatcherCompletions
argument_list|(
name|ArrayRef
operator|<
name|ArgKind
operator|>
name|AcceptedTypes
argument_list|)
expr_stmt|;
comment|/// \brief Construct a matcher from the registry.
comment|///
comment|/// \param Ctor The matcher constructor to instantiate.
comment|///
comment|/// \param NameRange The location of the name in the matcher source.
comment|///   Useful for error reporting.
comment|///
comment|/// \param Args The argument list for the matcher. The number and types of the
comment|///   values must be valid for the matcher requested. Otherwise, the function
comment|///   will return an error.
comment|///
comment|/// \return The matcher object constructed if no error was found.
comment|///   A null matcher if the number of arguments or argument types do not match
comment|///   the signature.  In that case \c Error will contain the description of
comment|///   the error.
specifier|static
name|VariantMatcher
name|constructMatcher
argument_list|(
name|MatcherCtor
name|Ctor
argument_list|,
specifier|const
name|SourceRange
operator|&
name|NameRange
argument_list|,
name|ArrayRef
operator|<
name|ParserValue
operator|>
name|Args
argument_list|,
name|Diagnostics
operator|*
name|Error
argument_list|)
decl_stmt|;
comment|/// \brief Construct a matcher from the registry and bind it.
comment|///
comment|/// Similar the \c constructMatcher() above, but it then tries to bind the
comment|/// matcher to the specified \c BindID.
comment|/// If the matcher is not bindable, it sets an error in \c Error and returns
comment|/// a null matcher.
specifier|static
name|VariantMatcher
name|constructBoundMatcher
argument_list|(
name|MatcherCtor
name|Ctor
argument_list|,
specifier|const
name|SourceRange
operator|&
name|NameRange
argument_list|,
name|StringRef
name|BindID
argument_list|,
name|ArrayRef
operator|<
name|ParserValue
operator|>
name|Args
argument_list|,
name|Diagnostics
operator|*
name|Error
argument_list|)
decl_stmt|;
name|private
label|:
name|Registry
argument_list|()
name|LLVM_DELETED_FUNCTION
expr_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace dynamic
block|}
comment|// namespace ast_matchers
block|}
end_decl_stmt

begin_comment
comment|// namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_AST_MATCHERS_DYNAMIC_REGISTRY_H
end_comment

end_unit

