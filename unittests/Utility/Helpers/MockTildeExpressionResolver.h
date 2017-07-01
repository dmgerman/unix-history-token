begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--------------------- TildeExpressionResolver.h ------------*- C++ -*-===//
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLDB_UNITTESTS_UTILITY_MOCKS_MOCK_TILDE_EXPRESSION_RESOLVER_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_UNITTESTS_UTILITY_MOCKS_MOCK_TILDE_EXPRESSION_RESOLVER_H
end_define

begin_include
include|#
directive|include
file|"lldb/Utility/TildeExpressionResolver.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallString.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|MockTildeExpressionResolver
range|:
name|public
name|TildeExpressionResolver
block|{
name|llvm
operator|::
name|StringRef
name|CurrentUser
block|;
name|llvm
operator|::
name|StringMap
operator|<
name|llvm
operator|::
name|StringRef
operator|>
name|UserDirectories
block|;
name|public
operator|:
name|MockTildeExpressionResolver
argument_list|(
argument|llvm::StringRef CurrentUser
argument_list|,
argument|llvm::StringRef HomeDir
argument_list|)
block|;
name|void
name|AddKnownUser
argument_list|(
argument|llvm::StringRef User
argument_list|,
argument|llvm::StringRef HomeDir
argument_list|)
block|;
name|void
name|Clear
argument_list|()
block|;
name|void
name|SetCurrentUser
argument_list|(
argument|llvm::StringRef User
argument_list|)
block|;
name|bool
name|ResolveExact
argument_list|(
argument|llvm::StringRef Expr
argument_list|,
argument|llvm::SmallVectorImpl<char>&Output
argument_list|)
name|override
block|;
name|bool
name|ResolvePartial
argument_list|(
argument|llvm::StringRef Expr
argument_list|,
argument|llvm::StringSet<>&Output
argument_list|)
name|override
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

