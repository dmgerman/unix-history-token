begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ASTStructExtractor.h ------------------------------------*- C++ -*-===//
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
name|liblldb_ASTStructExtractor_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ASTStructExtractor_h_
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
file|"lldb/Expression/ClangExpressionVariable.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/ClangFunction.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class ASTStructExtractor ASTStructExtractor.h "lldb/Expression/ASTStructExtractor.h"
comment|/// @brief Extracts and describes the argument structure for a wrapped function.
comment|///
comment|/// This pass integrates with ClangFunction, which calls functions with custom
comment|/// sets of arguments.  To avoid having to implement the full calling convention
comment|/// for the target's architecture, ClangFunction writes a simple wrapper
comment|/// function that takes a pointer to an argument structure that contains room
comment|/// for the address of the function to be called, the values of all its
comment|/// arguments, and room for the function's return value.
comment|///
comment|/// The definition of this struct is itself in the body of the wrapper function,
comment|/// so Clang does the structure layout itself.  ASTStructExtractor reads through
comment|/// the AST for the wrapper function and finds the struct.
comment|//----------------------------------------------------------------------
name|class
name|ASTStructExtractor
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
comment|/// @param[in] struct_name
comment|///     The name of the structure to extract from the wrapper function.
comment|///
comment|/// @param[in] function
comment|///     The caller object whose members should be populated with information
comment|///     about the argument struct.  ClangFunction friends ASTStructExtractor
comment|///     for this purpose.
comment|//----------------------------------------------------------------------
name|ASTStructExtractor
argument_list|(
name|clang
operator|::
name|ASTConsumer
operator|*
name|passthrough
argument_list|,
specifier|const
name|char
operator|*
name|struct_name
argument_list|,
name|ClangFunction
operator|&
name|function
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|/// Destructor
comment|//----------------------------------------------------------------------
name|virtual
operator|~
name|ASTStructExtractor
argument_list|()
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
name|clang
operator|::
name|ASTContext
operator|&
name|Context
argument_list|)
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
block|;
comment|//----------------------------------------------------------------------
comment|/// Passthrough stub
comment|//----------------------------------------------------------------------
name|void
name|HandleTranslationUnit
argument_list|(
name|clang
operator|::
name|ASTContext
operator|&
name|Ctx
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|/// Passthrough stub
comment|//----------------------------------------------------------------------
name|void
name|HandleTagDeclDefinition
argument_list|(
name|clang
operator|::
name|TagDecl
operator|*
name|D
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|/// Passthrough stub
comment|//----------------------------------------------------------------------
name|void
name|CompleteTentativeDefinition
argument_list|(
name|clang
operator|::
name|VarDecl
operator|*
name|D
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|/// Passthrough stub
comment|//----------------------------------------------------------------------
name|void
name|HandleVTable
argument_list|(
name|clang
operator|::
name|CXXRecordDecl
operator|*
name|RD
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|/// Passthrough stub
comment|//----------------------------------------------------------------------
name|void
name|PrintStats
argument_list|()
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
name|clang
operator|::
name|Sema
operator|&
name|S
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|/// Reset the Sema to NULL now that transformations are done
comment|//----------------------------------------------------------------------
name|void
name|ForgetSema
argument_list|()
block|;
name|private
operator|:
comment|//----------------------------------------------------------------------
comment|/// Hunt the given FunctionDecl for the argument struct and place
comment|/// information about it into m_function
comment|///
comment|/// @param[in] F
comment|///     The FunctionDecl to hunt.
comment|//----------------------------------------------------------------------
name|void
name|ExtractFromFunctionDecl
argument_list|(
name|clang
operator|::
name|FunctionDecl
operator|*
name|F
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|/// Hunt the given Decl for FunctionDecls named the same as the wrapper
comment|/// function name, recursing as necessary through LinkageSpecDecls, and
comment|/// calling ExtractFromFunctionDecl on anything that was found
comment|///
comment|/// @param[in] D
comment|///     The Decl to hunt.
comment|//----------------------------------------------------------------------
name|void
name|ExtractFromTopLevelDecl
argument_list|(
name|clang
operator|::
name|Decl
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
name|clang
operator|::
name|Sema
operator|*
name|m_sema
block|;
comment|///< The Sema to use.
name|clang
operator|::
name|Action
operator|*
name|m_action
block|;
comment|///< The Sema to use, cast to an Action so it's usable.
name|ClangFunction
operator|&
name|m_function
block|;
comment|///< The function to populate with information about the argument structure.
name|std
operator|::
name|string
name|m_struct_name
block|;
comment|///< The name of the structure to extract.
block|}
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

