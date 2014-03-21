begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ClangSACheckers.h - Registration functions for Checkers *- C++ -*-===//
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
comment|// Declares the registation functions for the checkers defined in
end_comment

begin_comment
comment|// libclangStaticAnalyzerCheckers.
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
name|LLVM_CLANG_SA_LIB_CHECKERS_CLANGSACHECKERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SA_LIB_CHECKERS_CLANGSACHECKERS_H
end_define

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/BugReporter/CommonBugCategories.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
name|class
name|CheckerManager
decl_stmt|;
name|class
name|CheckerRegistry
decl_stmt|;
define|#
directive|define
name|GET_CHECKERS
define|#
directive|define
name|CHECKER
parameter_list|(
name|FULLNAME
parameter_list|,
name|CLASS
parameter_list|,
name|CXXFILE
parameter_list|,
name|HELPTEXT
parameter_list|,
name|GROUPINDEX
parameter_list|,
name|HIDDEN
parameter_list|)
define|\
value|void register##CLASS(CheckerManager&mgr);
include|#
directive|include
file|"Checkers.inc"
undef|#
directive|undef
name|CHECKER
undef|#
directive|undef
name|GET_CHECKERS
block|}
comment|// end ento namespace
block|}
end_decl_stmt

begin_comment
comment|// end clang namespace
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

