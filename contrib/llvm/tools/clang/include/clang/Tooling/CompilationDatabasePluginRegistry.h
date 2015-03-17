begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- CompilationDatabasePluginRegistry.h - ------------------*- C++ -*-===//
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
name|LLVM_CLANG_TOOLING_COMPILATIONDATABASEPLUGINREGISTRY_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_COMPILATIONDATABASEPLUGINREGISTRY_H
end_define

begin_include
include|#
directive|include
file|"clang/Tooling/CompilationDatabase.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Registry.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|tooling
block|{
name|class
name|CompilationDatabasePlugin
decl_stmt|;
typedef|typedef
name|llvm
operator|::
name|Registry
operator|<
name|CompilationDatabasePlugin
operator|>
name|CompilationDatabasePluginRegistry
expr_stmt|;
block|}
comment|// end namespace tooling
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

