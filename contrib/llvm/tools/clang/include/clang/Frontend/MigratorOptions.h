begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- MigratorOptions.h - MigratorOptions Options ------------*- C++ -*-===//
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
comment|// This header contains the structures necessary for a front-end to specify
end_comment

begin_comment
comment|// various migration analysis.
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
name|LLVM_CLANG_FRONTEND_MIGRATOROPTIONS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_MIGRATOROPTIONS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|MigratorOptions
block|{
name|public
label|:
name|unsigned
name|NoNSAllocReallocError
range|:
literal|1
decl_stmt|;
name|unsigned
name|NoFinalizeRemoval
range|:
literal|1
decl_stmt|;
name|MigratorOptions
argument_list|()
block|{
name|NoNSAllocReallocError
operator|=
literal|0
expr_stmt|;
name|NoFinalizeRemoval
operator|=
literal|0
expr_stmt|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

