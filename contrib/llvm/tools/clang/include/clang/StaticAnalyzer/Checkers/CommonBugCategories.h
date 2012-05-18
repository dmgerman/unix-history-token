begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=--- CommonBugCategories.h - Provides common issue categories -*- C++ -*-===//
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
name|LLVM_CLANG_STATIC_ANALYZER_CHECKER_CATEGORIES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATIC_ANALYZER_CHECKER_CATEGORIES_H
end_define

begin_comment
comment|// Common strings used for the "category" of many static analyzer issues.
end_comment

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
name|namespace
name|categories
block|{
specifier|extern
specifier|const
name|char
modifier|*
name|CoreFoundationObjectiveC
decl_stmt|;
specifier|extern
specifier|const
name|char
modifier|*
name|MemoryCoreFoundationObjectiveC
decl_stmt|;
specifier|extern
specifier|const
name|char
modifier|*
name|UnixAPI
decl_stmt|;
block|}
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

