begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- unittest/Tooling/ReplacementTest.h - Replacements related test------===//
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
comment|//  This file defines utility class and function for Replacement related tests.
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
name|LLVM_CLANG_UNITTESTS_TOOLING_REPLACEMENTTESTBASE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_UNITTESTS_TOOLING_REPLACEMENTTESTBASE_H
end_define

begin_include
include|#
directive|include
file|"RewriterTestContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/Tooling/Core/Replacement.h"
end_include

begin_include
include|#
directive|include
file|"gtest/gtest.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|tooling
block|{
comment|/// \brief Converts a set of replacements to Replacements class.
comment|/// \return A Replacements class containing \p Replaces on success; otherwise,
comment|/// an empty Replacements is returned.
specifier|inline
name|tooling
operator|::
name|Replacements
name|toReplacements
argument_list|(
argument|const std::set<tooling::Replacement>&Replaces
argument_list|)
block|{
name|tooling
operator|::
name|Replacements
name|Result
block|;
for|for
control|(
specifier|const
specifier|auto
modifier|&
name|R
range|:
name|Replaces
control|)
block|{
name|auto
name|Err
init|=
name|Result
operator|.
name|add
argument_list|(
name|R
argument_list|)
decl_stmt|;
name|EXPECT_TRUE
argument_list|(
operator|!
name|Err
argument_list|)
expr_stmt|;
if|if
condition|(
name|Err
condition|)
block|{
name|llvm
operator|::
name|errs
argument_list|()
operator|<<
name|llvm
operator|::
name|toString
argument_list|(
name|std
operator|::
name|move
argument_list|(
name|Err
argument_list|)
argument_list|)
operator|<<
literal|"\n"
expr_stmt|;
return|return
name|tooling
operator|::
name|Replacements
argument_list|()
return|;
block|}
block|}
return|return
name|Result
return|;
block|}
comment|/// \brief A utility class for replacement related tests.
name|class
name|ReplacementTest
range|:
name|public
operator|::
name|testing
operator|::
name|Test
block|{
name|protected
operator|:
name|tooling
operator|::
name|Replacement
name|createReplacement
argument_list|(
argument|SourceLocation Start
argument_list|,
argument|unsigned Length
argument_list|,
argument|llvm::StringRef ReplacementText
argument_list|)
block|{
return|return
name|tooling
operator|::
name|Replacement
argument_list|(
name|Context
operator|.
name|Sources
argument_list|,
name|Start
argument_list|,
name|Length
argument_list|,
name|ReplacementText
argument_list|)
return|;
block|}
name|RewriterTestContext
name|Context
block|; }
decl_stmt|;
block|}
comment|// namespace tooling
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
comment|// LLVM_CLANG_UNITTESTS_TOOLING_REPLACEMENTTESTBASE_H
end_comment

end_unit

