begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//=--- AllocationDiagnostics.h - Config options for allocation diags *- C++ -*-//
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
comment|// Declares the configuration functions for leaks/allocation diagnostics.
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
name|LLVM_CLANG_LIB_STATICANALYZER_CHECKERS_ALLOCATIONDIAGNOSTICS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_STATICANALYZER_CHECKERS_ALLOCATIONDIAGNOSTICS_H
end_define

begin_include
include|#
directive|include
file|"clang/StaticAnalyzer/Core/AnalyzerOptions.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
comment|/// \brief Returns true if leak diagnostics should directly reference
comment|/// the allocatin site (where possible).
comment|///
comment|/// The default is false.
comment|///
name|bool
name|shouldIncludeAllocationSiteInLeakDiagnostics
parameter_list|(
name|AnalyzerOptions
modifier|&
name|AOpts
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

