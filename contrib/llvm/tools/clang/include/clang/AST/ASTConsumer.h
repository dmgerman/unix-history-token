begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ASTConsumer.h - Abstract interface for reading ASTs ----*- C++ -*-===//
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
comment|//  This file defines the ASTConsumer class.
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
name|LLVM_CLANG_AST_ASTCONSUMER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_ASTCONSUMER_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|CXXRecordDecl
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|DeclGroupRef
decl_stmt|;
name|class
name|HandleTagDeclDefinition
decl_stmt|;
name|class
name|ASTMutationListener
decl_stmt|;
name|class
name|ASTDeserializationListener
decl_stmt|;
comment|// layering violation because void* is ugly
name|class
name|SemaConsumer
decl_stmt|;
comment|// layering violation required for safe SemaConsumer
name|class
name|TagDecl
decl_stmt|;
name|class
name|VarDecl
decl_stmt|;
name|class
name|FunctionDecl
decl_stmt|;
name|class
name|ImportDecl
decl_stmt|;
comment|/// ASTConsumer - This is an abstract interface that should be implemented by
comment|/// clients that read ASTs.  This abstraction layer allows the client to be
comment|/// independent of the AST producer (e.g. parser vs AST dump file reader, etc).
name|class
name|ASTConsumer
block|{
comment|/// \brief Whether this AST consumer also requires information about
comment|/// semantic analysis.
name|bool
name|SemaConsumer
decl_stmt|;
name|friend
name|class
name|SemaConsumer
decl_stmt|;
name|public
label|:
name|ASTConsumer
argument_list|()
operator|:
name|SemaConsumer
argument_list|(
argument|false
argument_list|)
block|{ }
name|virtual
operator|~
name|ASTConsumer
argument_list|()
block|{}
comment|/// Initialize - This is called to initialize the consumer, providing the
comment|/// ASTContext.
name|virtual
name|void
name|Initialize
argument_list|(
argument|ASTContext&Context
argument_list|)
block|{}
comment|/// HandleTopLevelDecl - Handle the specified top-level declaration.  This is
comment|/// called by the parser to process every top-level Decl*. Note that D can be
comment|/// the head of a chain of Decls (e.g. for `int a, b` the chain will have two
comment|/// elements). Use Decl::getNextDeclarator() to walk the chain.
comment|///
comment|/// \returns true to continue parsing, or false to abort parsing.
name|virtual
name|bool
name|HandleTopLevelDecl
argument_list|(
argument|DeclGroupRef D
argument_list|)
expr_stmt|;
comment|/// HandleInterestingDecl - Handle the specified interesting declaration. This
comment|/// is called by the AST reader when deserializing things that might interest
comment|/// the consumer. The default implementation forwards to HandleTopLevelDecl.
name|virtual
name|void
name|HandleInterestingDecl
parameter_list|(
name|DeclGroupRef
name|D
parameter_list|)
function_decl|;
comment|/// HandleTranslationUnit - This method is called when the ASTs for entire
comment|/// translation unit have been parsed.
name|virtual
name|void
name|HandleTranslationUnit
parameter_list|(
name|ASTContext
modifier|&
name|Ctx
parameter_list|)
block|{}
comment|/// HandleTagDeclDefinition - This callback is invoked each time a TagDecl
comment|/// (e.g. struct, union, enum, class) is completed.  This allows the client to
comment|/// hack on the type, which can occur at any point in the file (because these
comment|/// can be defined in declspecs).
name|virtual
name|void
name|HandleTagDeclDefinition
parameter_list|(
name|TagDecl
modifier|*
name|D
parameter_list|)
block|{}
comment|/// \brief This callback is invoked the first time each TagDecl is required to
comment|/// be complete.
name|virtual
name|void
name|HandleTagDeclRequiredDefinition
parameter_list|(
specifier|const
name|TagDecl
modifier|*
name|D
parameter_list|)
block|{}
comment|/// \brief Invoked when a function is implicitly instantiated.
comment|/// Note that at this point point it does not have a body, its body is
comment|/// instantiated at the end of the translation unit and passed to
comment|/// HandleTopLevelDecl.
name|virtual
name|void
name|HandleCXXImplicitFunctionInstantiation
parameter_list|(
name|FunctionDecl
modifier|*
name|D
parameter_list|)
block|{}
comment|/// \brief Handle the specified top-level declaration that occurred inside
comment|/// and ObjC container.
comment|/// The default implementation ignored them.
name|virtual
name|void
name|HandleTopLevelDeclInObjCContainer
parameter_list|(
name|DeclGroupRef
name|D
parameter_list|)
function_decl|;
comment|/// \brief Handle an ImportDecl that was implicitly created due to an
comment|/// inclusion directive.
comment|/// The default implementation passes it to HandleTopLevelDecl.
name|virtual
name|void
name|HandleImplicitImportDecl
parameter_list|(
name|ImportDecl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// \brief Handle a pragma that appends to Linker Options.  Currently this
comment|/// only exists to support Microsoft's #pragma comment(linker, "/foo").
name|virtual
name|void
name|HandleLinkerOptionPragma
argument_list|(
name|llvm
operator|::
name|StringRef
name|Opts
argument_list|)
block|{}
comment|/// \brief Handle a pragma that emits a mismatch identifier and value to the
comment|/// object file for the linker to work with.  Currently, this only exists to
comment|/// support Microsoft's #pragma detect_mismatch.
name|virtual
name|void
name|HandleDetectMismatch
argument_list|(
name|llvm
operator|::
name|StringRef
name|Name
argument_list|,
name|llvm
operator|::
name|StringRef
name|Value
argument_list|)
block|{}
comment|/// \brief Handle a dependent library created by a pragma in the source.
comment|/// Currently this only exists to support Microsoft's
comment|/// #pragma comment(lib, "/foo").
name|virtual
name|void
name|HandleDependentLibrary
argument_list|(
name|llvm
operator|::
name|StringRef
name|Lib
argument_list|)
block|{}
comment|/// CompleteTentativeDefinition - Callback invoked at the end of a translation
comment|/// unit to notify the consumer that the given tentative definition should be
comment|/// completed.
comment|///
comment|/// The variable declaration itself will be a tentative
comment|/// definition. If it had an incomplete array type, its type will
comment|/// have already been changed to an array of size 1. However, the
comment|/// declaration remains a tentative definition and has not been
comment|/// modified by the introduction of an implicit zero initializer.
name|virtual
name|void
name|CompleteTentativeDefinition
parameter_list|(
name|VarDecl
modifier|*
name|D
parameter_list|)
block|{}
comment|/// HandleCXXStaticMemberVarInstantiation - Tell the consumer that this
comment|// variable has been instantiated.
name|virtual
name|void
name|HandleCXXStaticMemberVarInstantiation
parameter_list|(
name|VarDecl
modifier|*
name|D
parameter_list|)
block|{}
comment|/// \brief Callback involved at the end of a translation unit to
comment|/// notify the consumer that a vtable for the given C++ class is
comment|/// required.
comment|///
comment|/// \param RD The class whose vtable was used.
comment|///
comment|/// \param DefinitionRequired Whether a definition of this vtable is
comment|/// required in this translation unit; otherwise, it is only needed if
comment|/// it was actually used.
name|virtual
name|void
name|HandleVTable
parameter_list|(
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|,
name|bool
name|DefinitionRequired
parameter_list|)
block|{}
comment|/// \brief If the consumer is interested in entities getting modified after
comment|/// their initial creation, it should return a pointer to
comment|/// an ASTMutationListener here.
name|virtual
name|ASTMutationListener
modifier|*
name|GetASTMutationListener
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
comment|/// \brief If the consumer is interested in entities being deserialized from
comment|/// AST files, it should return a pointer to a ASTDeserializationListener here
name|virtual
name|ASTDeserializationListener
modifier|*
name|GetASTDeserializationListener
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
comment|/// PrintStats - If desired, print any statistics.
name|virtual
name|void
name|PrintStats
parameter_list|()
block|{}
comment|/// \brief This callback is called for each function if the Parser was
comment|/// initialized with \c SkipFunctionBodies set to \c true.
comment|///
comment|/// \return \c true if the function's body should be skipped. The function
comment|/// body may be parsed anyway if it is needed (for instance, if it contains
comment|/// the code completion point or is constexpr).
name|virtual
name|bool
name|shouldSkipFunctionBody
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
block|{
return|return
name|true
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

