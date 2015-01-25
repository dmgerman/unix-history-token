begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ModelInjector.h -----------------------------------------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief This file defines the clang::ento::ModelInjector class which implements the
end_comment

begin_comment
comment|/// clang::CodeInjector interface. This class is responsible for injecting
end_comment

begin_comment
comment|/// function definitions that were synthesized from model files.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Model files allow definitions of functions to be lazily constituted for functions
end_comment

begin_comment
comment|/// which lack bodies in the original source code.  This allows the analyzer
end_comment

begin_comment
comment|/// to more precisely analyze code that calls such functions, analyzing the
end_comment

begin_comment
comment|/// artificial definitions (which typically approximate the semantics of the
end_comment

begin_comment
comment|/// called function) when called by client code.  These definitions are
end_comment

begin_comment
comment|/// reconstituted lazily, on-demand, by the static analyzer engine.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_SA_FRONTEND_MODELINJECTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SA_FRONTEND_MODELINJECTOR_H
end_define

begin_include
include|#
directive|include
file|"clang/Analysis/CodeInjector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/IntrusiveRefCntPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringMap.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CompilerInstance
decl_stmt|;
name|class
name|ASTUnit
decl_stmt|;
name|class
name|ASTReader
decl_stmt|;
name|class
name|NamedDecl
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|namespace
name|ento
block|{
name|class
name|ModelInjector
range|:
name|public
name|CodeInjector
block|{
name|public
operator|:
name|ModelInjector
argument_list|(
name|CompilerInstance
operator|&
name|CI
argument_list|)
block|;
name|Stmt
operator|*
name|getBody
argument_list|(
specifier|const
name|FunctionDecl
operator|*
name|D
argument_list|)
block|;
name|Stmt
operator|*
name|getBody
argument_list|(
specifier|const
name|ObjCMethodDecl
operator|*
name|D
argument_list|)
block|;
name|private
operator|:
comment|/// \brief Synthesize a body for a declaration
comment|///
comment|/// This method first looks up the appropriate model file based on the
comment|/// model-path configuration option and the name of the declaration that is
comment|/// looked up. If no model were synthesized yet for a function with that name
comment|/// it will create a new compiler instance to parse the model file using the
comment|/// ASTContext, Preprocessor, SourceManager of the original compiler instance.
comment|/// The former resources are shared between the two compiler instance, so the
comment|/// newly created instance have to "leak" these objects, since they are owned
comment|/// by the original instance.
comment|///
comment|/// The model-path should be either an absolute path or relative to the
comment|/// working directory of the compiler.
name|void
name|onBodySynthesis
argument_list|(
specifier|const
name|NamedDecl
operator|*
name|D
argument_list|)
block|;
name|CompilerInstance
operator|&
name|CI
block|;
comment|// FIXME: double memoization is redundant, with memoization both here and in
comment|// BodyFarm.
name|llvm
operator|::
name|StringMap
operator|<
name|Stmt
operator|*
operator|>
name|Bodies
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

