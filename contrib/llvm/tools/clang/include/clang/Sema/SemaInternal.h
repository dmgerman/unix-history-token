begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- SemaInternal.h - Internal Sema Interfaces --------------*- C++ -*-===//
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
comment|// This file provides common API and #includes for the internal
end_comment

begin_comment
comment|// implementation of Sema.
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
name|LLVM_CLANG_SEMA_SEMA_INTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_SEMA_INTERNAL_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/ASTContext.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/Sema.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/SemaDiagnostic.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
specifier|inline
name|PartialDiagnostic
name|Sema
operator|::
name|PDiag
argument_list|(
argument|unsigned DiagID
argument_list|)
block|{
return|return
name|PartialDiagnostic
argument_list|(
name|DiagID
argument_list|,
name|Context
operator|.
name|getDiagAllocator
argument_list|()
argument_list|)
return|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

