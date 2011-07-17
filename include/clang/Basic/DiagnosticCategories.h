begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- DiagnosticCategories.h - Diagnostic Categories Enumerators-*- C++ -*===//
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
name|LLVM_CLANG_BASIC_DIAGNOSTICCATEGORIES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_DIAGNOSTICCATEGORIES_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|diag
block|{
enum|enum
block|{
define|#
directive|define
name|GET_CATEGORY_TABLE
define|#
directive|define
name|CATEGORY
parameter_list|(
name|X
parameter_list|,
name|ENUM
parameter_list|)
value|ENUM,
include|#
directive|include
file|"clang/Basic/DiagnosticGroups.inc"
undef|#
directive|undef
name|CATEGORY
undef|#
directive|undef
name|GET_CATEGORY_TABLE
name|DiagCat_NUM_CATEGORIES
block|}
enum|;
block|}
comment|// end namespace diag
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

