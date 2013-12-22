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
name|LLVM_CLANG_AST_MATCHERS_DYNAMIC_REGISTRY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_MATCHERS_DYNAMIC_REGISTRY_H
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
name|class
name|Registry
block|{
name|public
label|:
comment|/// \brief Construct a matcher from the registry by name.
comment|///
comment|/// Consult the registry of known matchers and construct the appropriate
comment|/// matcher by name.
comment|///
comment|/// \param MatcherName The name of the matcher to instantiate.
comment|///
comment|/// \param NameRange The location of the name in the matcher source.
comment|///   Useful for error reporting.
comment|///
comment|/// \param Args The argument list for the matcher. The number and types of the
comment|///   values must be valid for the matcher requested. Otherwise, the function
comment|///   will return an error.
comment|///
comment|/// \return The matcher object constructed if no error was found.
comment|///   A null matcher if the matcher is not found, or if the number of
comment|///   arguments or argument types do not match the signature.
comment|///   In that case \c Error will contain the description of the error.
specifier|static
name|VariantMatcher
name|constructMatcher
argument_list|(
name|StringRef
name|MatcherName
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
name|StringRef
name|MatcherName
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

