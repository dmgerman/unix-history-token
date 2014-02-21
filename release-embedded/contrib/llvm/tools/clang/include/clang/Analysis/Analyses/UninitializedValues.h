begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//= UninitializedValues.h - Finding uses of uninitialized values -*- C++ -*-==//
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

begin_include
include|#
directive|include
file|"clang/AST/Stmt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|AnalysisDeclContext
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
comment|/// A use of a variable, which might be uninitialized.
name|class
name|UninitUse
block|{
name|public
label|:
struct|struct
name|Branch
block|{
specifier|const
name|Stmt
modifier|*
name|Terminator
decl_stmt|;
name|unsigned
name|Output
decl_stmt|;
block|}
struct|;
name|private
label|:
comment|/// The expression which uses this variable.
specifier|const
name|Expr
modifier|*
name|User
decl_stmt|;
comment|/// Is this use uninitialized whenever the function is called?
name|bool
name|UninitAfterCall
decl_stmt|;
comment|/// Is this use uninitialized whenever the variable declaration is reached?
name|bool
name|UninitAfterDecl
decl_stmt|;
comment|/// Does this use always see an uninitialized value?
name|bool
name|AlwaysUninit
decl_stmt|;
comment|/// This use is always uninitialized if it occurs after any of these branches
comment|/// is taken.
name|SmallVector
operator|<
name|Branch
operator|,
literal|2
operator|>
name|UninitBranches
expr_stmt|;
name|public
label|:
name|UninitUse
argument_list|(
argument|const Expr *User
argument_list|,
argument|bool AlwaysUninit
argument_list|)
block|:
name|User
argument_list|(
name|User
argument_list|)
operator|,
name|UninitAfterCall
argument_list|(
name|false
argument_list|)
operator|,
name|UninitAfterDecl
argument_list|(
name|false
argument_list|)
operator|,
name|AlwaysUninit
argument_list|(
argument|AlwaysUninit
argument_list|)
block|{}
name|void
name|addUninitBranch
argument_list|(
argument|Branch B
argument_list|)
block|{
name|UninitBranches
operator|.
name|push_back
argument_list|(
name|B
argument_list|)
block|;   }
name|void
name|setUninitAfterCall
argument_list|()
block|{
name|UninitAfterCall
operator|=
name|true
block|; }
name|void
name|setUninitAfterDecl
argument_list|()
block|{
name|UninitAfterDecl
operator|=
name|true
block|; }
comment|/// Get the expression containing the uninitialized use.
specifier|const
name|Expr
operator|*
name|getUser
argument_list|()
specifier|const
block|{
return|return
name|User
return|;
block|}
comment|/// The kind of uninitialized use.
enum|enum
name|Kind
block|{
comment|/// The use might be uninitialized.
name|Maybe
block|,
comment|/// The use is uninitialized whenever a certain branch is taken.
name|Sometimes
block|,
comment|/// The use is uninitialized the first time it is reached after we reach
comment|/// the variable's declaration.
name|AfterDecl
block|,
comment|/// The use is uninitialized the first time it is reached after the function
comment|/// is called.
name|AfterCall
block|,
comment|/// The use is always uninitialized.
name|Always
block|}
enum|;
comment|/// Get the kind of uninitialized use.
name|Kind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|AlwaysUninit
operator|?
name|Always
operator|:
name|UninitAfterCall
operator|?
name|AfterCall
operator|:
name|UninitAfterDecl
operator|?
name|AfterDecl
operator|:
operator|!
name|branch_empty
argument_list|()
operator|?
name|Sometimes
operator|:
name|Maybe
return|;
block|}
typedef|typedef
name|SmallVectorImpl
operator|<
name|Branch
operator|>
operator|::
name|const_iterator
name|branch_iterator
expr_stmt|;
comment|/// Branches which inevitably result in the variable being used uninitialized.
name|branch_iterator
name|branch_begin
argument_list|()
specifier|const
block|{
return|return
name|UninitBranches
operator|.
name|begin
argument_list|()
return|;
block|}
name|branch_iterator
name|branch_end
argument_list|()
specifier|const
block|{
return|return
name|UninitBranches
operator|.
name|end
argument_list|()
return|;
block|}
name|bool
name|branch_empty
argument_list|()
specifier|const
block|{
return|return
name|UninitBranches
operator|.
name|empty
argument_list|()
return|;
block|}
block|}
empty_stmt|;
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
comment|/// Called when the uninitialized variable is used at the given expression.
name|virtual
name|void
name|handleUseOfUninitVariable
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|vd
parameter_list|,
specifier|const
name|UninitUse
modifier|&
name|use
parameter_list|)
block|{}
comment|/// Called when the uninitialized variable analysis detects the
comment|/// idiom 'int x = x'.  All other uses of 'x' within the initializer
comment|/// are handled by handleUseOfUninitVariable.
name|virtual
name|void
name|handleSelfInit
parameter_list|(
specifier|const
name|VarDecl
modifier|*
name|vd
parameter_list|)
block|{}
block|}
empty_stmt|;
struct|struct
name|UninitVariablesAnalysisStats
block|{
name|unsigned
name|NumVariablesAnalyzed
decl_stmt|;
name|unsigned
name|NumBlockVisits
decl_stmt|;
block|}
struct|;
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
name|AnalysisDeclContext
modifier|&
name|ac
parameter_list|,
name|UninitVariablesHandler
modifier|&
name|handler
parameter_list|,
name|UninitVariablesAnalysisStats
modifier|&
name|stats
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

