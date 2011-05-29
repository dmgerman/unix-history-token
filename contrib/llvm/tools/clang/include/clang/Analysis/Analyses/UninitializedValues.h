begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//= UninitializedValues.h - Finding uses of uninitialized values --*- C++ -*-==//
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
comment|// This file defines APIs for invoking and reported uninitialized values
end_comment

begin_comment
comment|// warnings.
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
name|LLVM_CLANG_UNINIT_VALS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_UNINIT_VALS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|AnalysisContext
decl_stmt|;
name|class
name|CFG
decl_stmt|;
name|class
name|DeclContext
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|VarDecl
decl_stmt|;
name|class
name|UninitVariablesHandler
block|{
name|public
label|:
name|UninitVariablesHandler
argument_list|()
block|{}
name|virtual
operator|~
name|UninitVariablesHandler
argument_list|()
expr_stmt|;
name|virtual
name|void
name|handleUseOfUninitVariable
parameter_list|(
specifier|const
name|Expr
modifier|*
name|ex
parameter_list|,
specifier|const
name|VarDecl
modifier|*
name|vd
parameter_list|,
name|bool
name|isAlwaysUninit
parameter_list|)
block|{}
block|}
empty_stmt|;
name|void
name|runUninitializedVariablesAnalysis
parameter_list|(
specifier|const
name|DeclContext
modifier|&
name|dc
parameter_list|,
specifier|const
name|CFG
modifier|&
name|cfg
parameter_list|,
name|AnalysisContext
modifier|&
name|ac
parameter_list|,
name|UninitVariablesHandler
modifier|&
name|handler
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

