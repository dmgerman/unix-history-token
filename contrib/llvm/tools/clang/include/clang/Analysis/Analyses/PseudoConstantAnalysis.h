begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== PseudoConstantAnalysis.h - Find Pseudo-constants in the AST -*- C++ -*-==//
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
comment|// This file tracks the usage of variables in a Decl body to see if they are
end_comment

begin_comment
comment|// never written to, implying that they constant. This is useful in static
end_comment

begin_comment
comment|// analysis to see if a developer might have intended a variable to be const.
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
name|LLVM_CLANG_ANALYSIS_ANALYSES_PSEUDOCONSTANTANALYSIS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_ANALYSIS_ANALYSES_PSEUDOCONSTANTANALYSIS_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Stmt.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|PseudoConstantAnalysis
block|{
name|public
label|:
name|PseudoConstantAnalysis
argument_list|(
specifier|const
name|Stmt
operator|*
name|DeclBody
argument_list|)
expr_stmt|;
operator|~
name|PseudoConstantAnalysis
argument_list|()
expr_stmt|;
name|bool
name|isPseudoConstant
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|VD
parameter_list|)
function_decl|;
name|bool
name|wasReferenced
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|VD
parameter_list|)
function_decl|;
name|private
label|:
name|void
name|RunAnalysis
parameter_list|()
function_decl|;
specifier|inline
specifier|static
specifier|const
name|Decl
modifier|*
name|getDecl
parameter_list|(
specifier|const
name|Expr
modifier|*
name|E
parameter_list|)
function_decl|;
comment|// for storing the result of analyzed ValueDecls
name|void
modifier|*
name|NonConstantsImpl
decl_stmt|;
name|void
modifier|*
name|UsedVarsImpl
decl_stmt|;
specifier|const
name|Stmt
modifier|*
name|DeclBody
decl_stmt|;
name|bool
name|Analyzed
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

