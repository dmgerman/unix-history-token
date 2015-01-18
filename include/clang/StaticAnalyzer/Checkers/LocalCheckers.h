begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//==- LocalCheckers.h - Intra-Procedural+Flow-Sensitive Checkers -*- C++ -*-==//
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
comment|//  This file defines the interface to call a set of intra-procedural (local)
end_comment

begin_comment
comment|//  checkers that use flow/path-sensitive analyses to find bugs.
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
name|LLVM_CLANG_STATICANALYZER_CHECKERS_LOCALCHECKERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CHECKERS_LOCALCHECKERS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ento
block|{
name|class
name|ExprEngine
decl_stmt|;
name|void
name|RegisterCallInliner
parameter_list|(
name|ExprEngine
modifier|&
name|Eng
parameter_list|)
function_decl|;
block|}
comment|// end namespace ento
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

