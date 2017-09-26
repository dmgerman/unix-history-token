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
name|LLVM_CLANG_STATICANALYZER_CORE_BUGREPORTER_COMMONBUGCATEGORIES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_BUGREPORTER_COMMONBUGCATEGORIES_H
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
specifier|const
name|CoreFoundationObjectiveC
decl_stmt|;
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|LogicError
decl_stmt|;
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|MemoryCoreFoundationObjectiveC
decl_stmt|;
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
name|MemoryError
decl_stmt|;
specifier|extern
specifier|const
name|char
modifier|*
specifier|const
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

