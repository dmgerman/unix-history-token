begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CXTypes.h - Routines for manipulating CXTypes ----------------------===//
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
comment|// This file defines routines for manipulating CXCursors.
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
name|LLVM_CLANG_TOOLS_LIBCLANG_CXTYPE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLS_LIBCLANG_CXTYPE_H
end_define

begin_include
include|#
directive|include
file|"clang-c/Index.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTUnit
decl_stmt|;
name|namespace
name|cxtype
block|{
name|CXType
name|MakeCXType
parameter_list|(
name|QualType
name|T
parameter_list|,
name|CXTranslationUnit
name|TU
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang::cxtype
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

