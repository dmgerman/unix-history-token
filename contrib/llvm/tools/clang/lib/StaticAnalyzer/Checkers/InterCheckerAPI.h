begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==--- InterCheckerAPI.h ---------------------------------------*- C++ -*-==//
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
comment|// This file allows introduction of checker dependencies. It contains APIs for
end_comment

begin_comment
comment|// inter-checker communications.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_LIB_STATICANALYZER_CHECKERS_INTERCHECKERAPI_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_LIB_STATICANALYZER_CHECKERS_INTERCHECKERAPI_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
comment|/// Register the checker which evaluates CString API calls.
name|void
name|registerCStringCheckerBasic
parameter_list|(
name|CheckerManager
modifier|&
name|Mgr
parameter_list|)
function_decl|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* INTERCHECKERAPI_H_ */
end_comment

end_unit

