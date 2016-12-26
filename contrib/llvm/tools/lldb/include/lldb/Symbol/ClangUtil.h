begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ClangUtil.h ---------------------------------------------*- C++ -*-===//
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
comment|// A collection of helper methods and data structures for manipulating clang
end_comment

begin_comment
comment|// types and decls.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLDB_SYMBOL_CLANGUTIL_H
end_ifndef

begin_define
define|#
directive|define
name|LLDB_SYMBOL_CLANGUTIL_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/CompilerType.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
struct|struct
name|ClangUtil
block|{
specifier|static
name|bool
name|IsClangType
parameter_list|(
specifier|const
name|CompilerType
modifier|&
name|ct
parameter_list|)
function_decl|;
specifier|static
name|clang
operator|::
name|QualType
name|GetQualType
argument_list|(
specifier|const
name|CompilerType
operator|&
name|ct
argument_list|)
expr_stmt|;
specifier|static
name|clang
operator|::
name|QualType
name|GetCanonicalQualType
argument_list|(
specifier|const
name|CompilerType
operator|&
name|ct
argument_list|)
expr_stmt|;
specifier|static
name|CompilerType
name|RemoveFastQualifiers
parameter_list|(
specifier|const
name|CompilerType
modifier|&
name|ct
parameter_list|)
function_decl|;
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

