begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- FrontendAction.h - Pluggable Frontend Action Interface --*- C++ -*-===//
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
name|LLVM_CLANG_FRONTEND_PLUGINFRONTENDACTION_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_PLUGINFRONTENDACTION_H
end_define

begin_include
include|#
directive|include
file|"clang/Frontend/FrontendAction.h"
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
comment|/// The frontend plugin registry.
typedef|typedef
name|llvm
operator|::
name|Registry
operator|<
name|FrontendAction
operator|>
name|FrontendPluginRegistry
expr_stmt|;
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

