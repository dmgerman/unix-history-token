begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ASTResultSynthesizer.h ----------------------------------*- C++ -*-===//
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
name|liblldb_ASTResultSynthesizer_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ASTResultSynthesizer_h_
end_define

begin_include
include|#
directive|include
file|"clang/Sema/SemaConsumer.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ClangForward.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Target.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class ASTResultSynthesizer ASTResultSynthesizer.h "lldb/Expression/ASTResultSynthesizer.h"
comment|/// @brief Adds a result variable declaration to the ASTs for an expression.
comment|///
comment|/// Users expect the expression "i + 3" to return a result, even if a result
comment|/// variable wasn't specifically declared.  To fulfil this requirement, LLDB adds
comment|/// a result variable to the expression, transforming it to
comment|/// "int $__lldb_expr_result = i + 3."  The IR transformers ensure that the
comment|/// resulting variable is mapped to the right piece of memory.
comment|/// ASTResultSynthesizer's job is to add the variable and its initialization to
comment|/// the ASTs for the expression, and it does so by acting as a SemaConsumer for
comment|/// Clang.
comment|//----------------------------------------------------------------------
name|class
name|ASTResultSynthesizer
range|:
name|public
name|clang
operator|::
name|SemaConsumer
block|{
name|public
operator|:
comment|//----------------------------------------------------------------------
comment|/// Constructor
comment|///
comment|/// @param[in] passthrough
comment|///     Since the ASTs must typically go through to the Clang code generator
comment|///     in order to produce LLVM IR, this SemaConsumer must allow them to
comment|///     pass to the next step in the chain after processing.  Passthrough is
comment|///     the next ASTConsumer, or NULL if none is required.
comment|///
comment|/// @param[in] top_level
comment|///     If true, register all top-level Decls and don't try to handle the
comment|///     main function.
comment|///
comment|/// @param[in] target
comment|///     The target, which contains the persistent variable store and the
comment|///     AST importer.
comment|//----------------------------------------------------------------------
name|ASTResultSynthesizer
argument_list|(
argument|clang::ASTConsumer *passthrough
argument_list|,
argument|bool top_level
argument_list|,
argument|Target&target
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|/// Destructor
comment|//----------------------------------------------------------------------
operator|~
name|ASTResultSynthesizer
argument_list|()
name|override
block|;
comment|//----------------------------------------------------------------------
comment|/// Link this consumer with a particular AST context
comment|///
comment|/// @param[in] Context
comment|///     This AST context will be used for types and identifiers, and also
comment|///     forwarded to the passthrough consumer, if one exists.
comment|//----------------------------------------------------------------------
name|void
name|Initialize
argument_list|(
argument|clang::ASTContext&Context
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|/// Examine a list of Decls to find the function $__lldb_expr and
comment|/// transform its code
comment|///
comment|/// @param[in] D
comment|///     The list of Decls to search.  These may contain LinkageSpecDecls,
comment|///     which need to be searched recursively.  That job falls to
comment|///     TransformTopLevelDecl.
comment|//----------------------------------------------------------------------
name|bool
name|HandleTopLevelDecl
argument_list|(
argument|clang::DeclGroupRef D
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|/// Passthrough stub
comment|//----------------------------------------------------------------------
name|void
name|HandleTranslationUnit
argument_list|(
argument|clang::ASTContext&Ctx
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|/// Passthrough stub
comment|//----------------------------------------------------------------------
name|void
name|HandleTagDeclDefinition
argument_list|(
argument|clang::TagDecl *D
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|/// Passthrough stub
comment|//----------------------------------------------------------------------
name|void
name|CompleteTentativeDefinition
argument_list|(
argument|clang::VarDecl *D
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|/// Passthrough stub
comment|//----------------------------------------------------------------------
name|void
name|HandleVTable
argument_list|(
argument|clang::CXXRecordDecl *RD
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|/// Passthrough stub
comment|//----------------------------------------------------------------------
name|void
name|PrintStats
argument_list|()
name|override
block|;
comment|//----------------------------------------------------------------------
comment|/// Set the Sema object to use when performing transforms, and pass it on
comment|///
comment|/// @param[in] S
comment|///     The Sema to use.  Because Sema isn't externally visible, this class
comment|///     casts it to an Action for actual use.
comment|//----------------------------------------------------------------------
name|void
name|InitializeSema
argument_list|(
argument|clang::Sema&S
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|/// Reset the Sema to NULL now that transformations are done
comment|//----------------------------------------------------------------------
name|void
name|ForgetSema
argument_list|()
name|override
block|;
comment|//----------------------------------------------------------------------
comment|/// The parse has succeeded, so record its persistent decls
comment|//----------------------------------------------------------------------
name|void
name|CommitPersistentDecls
argument_list|()
block|;
name|private
operator|:
comment|//----------------------------------------------------------------------
comment|/// Hunt the given Decl for FunctionDecls named $__lldb_expr, recursing
comment|/// as necessary through LinkageSpecDecls, and calling SynthesizeResult on
comment|/// anything that was found
comment|///
comment|/// @param[in] D
comment|///     The Decl to hunt.
comment|//----------------------------------------------------------------------
name|void
name|TransformTopLevelDecl
argument_list|(
name|clang
operator|::
name|Decl
operator|*
name|D
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|/// Process an Objective-C method and produce the result variable and
comment|/// initialization
comment|///
comment|/// @param[in] MethodDecl
comment|///     The method to process.
comment|//----------------------------------------------------------------------
name|bool
name|SynthesizeObjCMethodResult
argument_list|(
name|clang
operator|::
name|ObjCMethodDecl
operator|*
name|MethodDecl
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|/// Process a function and produce the result variable and initialization
comment|///
comment|/// @param[in] FunDecl
comment|///     The function to process.
comment|//----------------------------------------------------------------------
name|bool
name|SynthesizeFunctionResult
argument_list|(
name|clang
operator|::
name|FunctionDecl
operator|*
name|FunDecl
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|/// Process a function body and produce the result variable and
comment|/// initialization
comment|///
comment|/// @param[in] Body
comment|///     The body of the function.
comment|///
comment|/// @param[in] DC
comment|///     The DeclContext of the function, into which the result variable
comment|///     is inserted.
comment|//----------------------------------------------------------------------
name|bool
name|SynthesizeBodyResult
argument_list|(
name|clang
operator|::
name|CompoundStmt
operator|*
name|Body
argument_list|,
name|clang
operator|::
name|DeclContext
operator|*
name|DC
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|/// Given a DeclContext for a function or method, find all types
comment|/// declared in the context and record any persistent types found.
comment|///
comment|/// @param[in] FunDeclCtx
comment|///     The context for the function to process.
comment|//----------------------------------------------------------------------
name|void
name|RecordPersistentTypes
argument_list|(
name|clang
operator|::
name|DeclContext
operator|*
name|FunDeclCtx
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|/// Given a TypeDecl, if it declares a type whose name starts with a
comment|/// dollar sign, register it as a pointer type in the target's scratch
comment|/// AST context.
comment|///
comment|/// @param[in] Body
comment|///     The body of the function.
comment|//----------------------------------------------------------------------
name|void
name|MaybeRecordPersistentType
argument_list|(
name|clang
operator|::
name|TypeDecl
operator|*
name|D
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|/// Given a NamedDecl, register it as a pointer type in the target's scratch
comment|/// AST context.
comment|///
comment|/// @param[in] Body
comment|///     The body of the function.
comment|//----------------------------------------------------------------------
name|void
name|RecordPersistentDecl
argument_list|(
name|clang
operator|::
name|NamedDecl
operator|*
name|D
argument_list|)
block|;
name|clang
operator|::
name|ASTContext
operator|*
name|m_ast_context
block|;
comment|///< The AST context to use for identifiers and types.
name|clang
operator|::
name|ASTConsumer
operator|*
name|m_passthrough
block|;
comment|///< The ASTConsumer down the chain, for passthrough.  NULL if it's a SemaConsumer.
name|clang
operator|::
name|SemaConsumer
operator|*
name|m_passthrough_sema
block|;
comment|///< The SemaConsumer down the chain, for passthrough.  NULL if it's an ASTConsumer.
name|std
operator|::
name|vector
operator|<
name|clang
operator|::
name|NamedDecl
operator|*
operator|>
name|m_decls
block|;
comment|///< Persistent declarations to register assuming the expression succeeds.
name|Target
operator|&
name|m_target
block|;
comment|///< The target, which contains the persistent variable store and the
name|clang
operator|::
name|Sema
operator|*
name|m_sema
block|;
comment|///< The Sema to use.
name|bool
name|m_top_level
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_ASTResultSynthesizer_h_
end_comment

end_unit

