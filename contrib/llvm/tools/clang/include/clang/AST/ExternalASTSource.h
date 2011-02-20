begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ExternalASTSource.h - Abstract External AST Interface --*- C++ -*-===//
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
comment|//  This file defines the ExternalASTSource interface, which enables
end_comment

begin_comment
comment|//  construction of AST nodes from some external source.x
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
name|LLVM_CLANG_AST_EXTERNAL_AST_SOURCE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_EXTERNAL_AST_SOURCE_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/DeclBase.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|class
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTConsumer
decl_stmt|;
name|class
name|CXXBaseSpecifier
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|DeclContext
decl_stmt|;
name|class
name|DeclContextLookupResult
decl_stmt|;
name|class
name|DeclarationName
decl_stmt|;
name|class
name|ExternalSemaSource
decl_stmt|;
comment|// layering violation required for downcasting
name|class
name|NamedDecl
decl_stmt|;
name|class
name|Selector
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|TagDecl
decl_stmt|;
comment|/// \brief Abstract interface for external sources of AST nodes.
comment|///
comment|/// External AST sources provide AST nodes constructed from some
comment|/// external source, such as a precompiled header. External AST
comment|/// sources can resolve types and declarations from abstract IDs into
comment|/// actual type and declaration nodes, and read parts of declaration
comment|/// contexts.
name|class
name|ExternalASTSource
block|{
comment|/// \brief Whether this AST source also provides information for
comment|/// semantic analysis.
name|bool
name|SemaSource
decl_stmt|;
name|friend
name|class
name|ExternalSemaSource
decl_stmt|;
name|public
label|:
name|ExternalASTSource
argument_list|()
operator|:
name|SemaSource
argument_list|(
argument|false
argument_list|)
block|{ }
name|virtual
operator|~
name|ExternalASTSource
argument_list|()
expr_stmt|;
comment|/// \brief RAII class for safely pairing a StartedDeserializing call
comment|/// with FinishedDeserializing.
name|class
name|Deserializing
block|{
name|ExternalASTSource
modifier|*
name|Source
decl_stmt|;
name|public
label|:
name|explicit
name|Deserializing
argument_list|(
name|ExternalASTSource
operator|*
name|source
argument_list|)
operator|:
name|Source
argument_list|(
argument|source
argument_list|)
block|{
name|assert
argument_list|(
name|Source
argument_list|)
block|;
name|Source
operator|->
name|StartedDeserializing
argument_list|()
block|;     }
operator|~
name|Deserializing
argument_list|()
block|{
name|Source
operator|->
name|FinishedDeserializing
argument_list|()
block|;     }
block|}
empty_stmt|;
comment|/// \brief Resolve a declaration ID into a declaration, potentially
comment|/// building a new declaration.
comment|///
comment|/// This method only needs to be implemented if the AST source ever
comment|/// passes back decl sets as VisibleDeclaration objects.
name|virtual
name|Decl
modifier|*
name|GetExternalDecl
parameter_list|(
name|uint32_t
name|ID
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Resolve a selector ID into a selector.
comment|///
comment|/// This operation only needs to be implemented if the AST source
comment|/// returns non-zero for GetNumKnownSelectors().
name|virtual
name|Selector
name|GetExternalSelector
parameter_list|(
name|uint32_t
name|ID
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Returns the number of selectors known to the external AST
comment|/// source.
name|virtual
name|uint32_t
name|GetNumExternalSelectors
parameter_list|()
init|=
literal|0
function_decl|;
comment|/// \brief Resolve the offset of a statement in the decl stream into
comment|/// a statement.
comment|///
comment|/// This operation is meant to be used via a LazyOffsetPtr.  It only
comment|/// needs to be implemented if the AST source uses methods like
comment|/// FunctionDecl::setLazyBody when building decls.
name|virtual
name|Stmt
modifier|*
name|GetExternalDeclStmt
parameter_list|(
name|uint64_t
name|Offset
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Resolve the offset of a set of C++ base specifiers in the decl
comment|/// stream into an array of specifiers.
name|virtual
name|CXXBaseSpecifier
modifier|*
name|GetExternalCXXBaseSpecifiers
parameter_list|(
name|uint64_t
name|Offset
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Finds all declarations with the given name in the
comment|/// given context.
comment|///
comment|/// Generally the final step of this method is either to call
comment|/// SetExternalVisibleDeclsForName or to recursively call lookup on
comment|/// the DeclContext after calling SetExternalVisibleDecls.
name|virtual
name|DeclContextLookupResult
name|FindExternalVisibleDeclsByName
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|DeclarationName
name|Name
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Deserialize all the visible declarations from external storage.
comment|///
comment|/// Name lookup deserializes visible declarations lazily, thus a DeclContext
comment|/// may not have a complete name lookup table. This function deserializes
comment|/// the rest of visible declarations from the external storage and completes
comment|/// the name lookup table of the DeclContext.
name|virtual
name|void
name|MaterializeVisibleDecls
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|DC
parameter_list|)
init|=
literal|0
function_decl|;
comment|/// \brief Finds all declarations lexically contained within the given
comment|/// DeclContext, after applying an optional filter predicate.
comment|///
comment|/// \param isKindWeWant a predicate function that returns true if the passed
comment|/// declaration kind is one we are looking for. If NULL, all declarations
comment|/// are returned.
comment|///
comment|/// \return true if an error occurred
name|virtual
name|bool
name|FindExternalLexicalDecls
argument_list|(
specifier|const
name|DeclContext
operator|*
name|DC
argument_list|,
name|bool
argument_list|(
operator|*
name|isKindWeWant
argument_list|)
argument_list|(
name|Decl
operator|::
name|Kind
argument_list|)
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|Decl
operator|*
operator|>
operator|&
name|Result
argument_list|)
init|=
literal|0
decl_stmt|;
comment|/// \brief Finds all declarations lexically contained within the given
comment|/// DeclContext.
comment|///
comment|/// \return true if an error occurred
name|bool
name|FindExternalLexicalDecls
argument_list|(
specifier|const
name|DeclContext
operator|*
name|DC
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|Decl
operator|*
operator|>
operator|&
name|Result
argument_list|)
block|{
return|return
name|FindExternalLexicalDecls
argument_list|(
name|DC
argument_list|,
literal|0
argument_list|,
name|Result
argument_list|)
return|;
block|}
name|template
operator|<
name|typename
name|DeclTy
operator|>
name|bool
name|FindExternalLexicalDeclsBy
argument_list|(
argument|const DeclContext *DC
argument_list|,
argument|llvm::SmallVectorImpl<Decl*>&Result
argument_list|)
block|{
return|return
name|FindExternalLexicalDecls
argument_list|(
name|DC
argument_list|,
name|DeclTy
operator|::
name|classofKind
argument_list|,
name|Result
argument_list|)
return|;
block|}
comment|/// \brief Gives the external AST source an opportunity to complete
comment|/// an incomplete type.
name|virtual
name|void
name|CompleteType
parameter_list|(
name|TagDecl
modifier|*
name|Tag
parameter_list|)
block|{}
comment|/// \brief Gives the external AST source an opportunity to complete an
comment|/// incomplete Objective-C class.
comment|///
comment|/// This routine will only be invoked if the "externally completed" bit is
comment|/// set on the ObjCInterfaceDecl via the function
comment|/// \c ObjCInterfaceDecl::setExternallyCompleted().
name|virtual
name|void
name|CompleteType
parameter_list|(
name|ObjCInterfaceDecl
modifier|*
name|Class
parameter_list|)
block|{ }
comment|/// \brief Notify ExternalASTSource that we started deserialization of
comment|/// a decl or type so until FinishedDeserializing is called there may be
comment|/// decls that are initializing. Must be paired with FinishedDeserializing.
comment|///
comment|/// The default implementation of this method is a no-op.
name|virtual
name|void
name|StartedDeserializing
parameter_list|()
block|{ }
comment|/// \brief Notify ExternalASTSource that we finished the deserialization of
comment|/// a decl or type. Must be paired with StartedDeserializing.
comment|///
comment|/// The default implementation of this method is a no-op.
name|virtual
name|void
name|FinishedDeserializing
parameter_list|()
block|{ }
comment|/// \brief Function that will be invoked when we begin parsing a new
comment|/// translation unit involving this external AST source.
comment|///
comment|/// The default implementation of this method is a no-op.
name|virtual
name|void
name|StartTranslationUnit
parameter_list|(
name|ASTConsumer
modifier|*
name|Consumer
parameter_list|)
block|{ }
comment|/// \brief Print any statistics that have been gathered regarding
comment|/// the external AST source.
comment|///
comment|/// The default implementation of this method is a no-op.
name|virtual
name|void
name|PrintStats
parameter_list|()
function_decl|;
name|protected
label|:
specifier|static
name|DeclContextLookupResult
name|SetExternalVisibleDeclsForName
argument_list|(
specifier|const
name|DeclContext
operator|*
name|DC
argument_list|,
name|DeclarationName
name|Name
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|NamedDecl
operator|*
operator|>
operator|&
name|Decls
argument_list|)
decl_stmt|;
specifier|static
name|DeclContextLookupResult
name|SetNoExternalVisibleDeclsForName
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|DeclarationName
name|Name
parameter_list|)
function_decl|;
name|void
name|MaterializeVisibleDeclsForName
argument_list|(
specifier|const
name|DeclContext
operator|*
name|DC
argument_list|,
name|DeclarationName
name|Name
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|NamedDecl
operator|*
operator|>
operator|&
name|Decls
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief A lazy pointer to an AST node (of base type T) that resides
comment|/// within an external AST source.
comment|///
comment|/// The AST node is identified within the external AST source by a
comment|/// 63-bit offset, and can be retrieved via an operation on the
comment|/// external AST source itself.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|OffsT
operator|,
name|T
operator|*
operator|(
name|ExternalASTSource
operator|::
operator|*
name|Get
operator|)
operator|(
name|OffsT
name|Offset
operator|)
operator|>
expr|struct
name|LazyOffsetPtr
block|{
comment|/// \brief Either a pointer to an AST node or the offset within the
comment|/// external AST source where the AST node can be found.
comment|///
comment|/// If the low bit is clear, a pointer to the AST node. If the low
comment|/// bit is set, the upper 63 bits are the offset.
name|mutable
name|uint64_t
name|Ptr
block|;
name|public
operator|:
name|LazyOffsetPtr
argument_list|()
operator|:
name|Ptr
argument_list|(
literal|0
argument_list|)
block|{ }
name|explicit
name|LazyOffsetPtr
argument_list|(
name|T
operator|*
name|Ptr
argument_list|)
operator|:
name|Ptr
argument_list|(
argument|reinterpret_cast<uint64_t>(Ptr)
argument_list|)
block|{ }
name|explicit
name|LazyOffsetPtr
argument_list|(
argument|uint64_t Offset
argument_list|)
operator|:
name|Ptr
argument_list|(
argument|(Offset<<
literal|1
argument|) |
literal|0x01
argument_list|)
block|{
name|assert
argument_list|(
operator|(
name|Offset
operator|<<
literal|1
operator|>>
literal|1
operator|)
operator|==
name|Offset
operator|&&
literal|"Offsets must require< 63 bits"
argument_list|)
block|;
if|if
condition|(
name|Offset
operator|==
literal|0
condition|)
name|Ptr
operator|=
literal|0
expr_stmt|;
block|}
name|LazyOffsetPtr
operator|&
name|operator
operator|=
operator|(
name|T
operator|*
name|Ptr
operator|)
block|{
name|this
operator|->
name|Ptr
operator|=
name|reinterpret_cast
operator|<
name|uint64_t
operator|>
operator|(
name|Ptr
operator|)
block|;
return|return
operator|*
name|this
return|;
block|}
name|LazyOffsetPtr
operator|&
name|operator
operator|=
operator|(
name|uint64_t
name|Offset
operator|)
block|{
name|assert
argument_list|(
operator|(
name|Offset
operator|<<
literal|1
operator|>>
literal|1
operator|)
operator|==
name|Offset
operator|&&
literal|"Offsets must require< 63 bits"
argument_list|)
block|;
if|if
condition|(
name|Offset
operator|==
literal|0
condition|)
name|Ptr
operator|=
literal|0
expr_stmt|;
else|else
name|Ptr
operator|=
operator|(
name|Offset
operator|<<
literal|1
operator|)
operator||
literal|0x01
expr_stmt|;
return|return
operator|*
name|this
return|;
block|}
comment|/// \brief Whether this pointer is non-NULL.
comment|///
comment|/// This operation does not require the AST node to be deserialized.
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|Ptr
operator|!=
literal|0
return|;
block|}
comment|/// \brief Whether this pointer is currently stored as an offset.
name|bool
name|isOffset
argument_list|()
specifier|const
block|{
return|return
name|Ptr
operator|&
literal|0x01
return|;
block|}
comment|/// \brief Retrieve the pointer to the AST node that this lazy pointer
comment|///
comment|/// \param Source the external AST source.
comment|///
comment|/// \returns a pointer to the AST node.
name|T
modifier|*
name|get
argument_list|(
name|ExternalASTSource
operator|*
name|Source
argument_list|)
decl|const
block|{
if|if
condition|(
name|isOffset
argument_list|()
condition|)
block|{
name|assert
argument_list|(
name|Source
operator|&&
literal|"Cannot deserialize a lazy pointer without an AST source"
argument_list|)
expr_stmt|;
name|Ptr
operator|=
name|reinterpret_cast
operator|<
name|uint64_t
operator|>
operator|(
operator|(
name|Source
operator|->*
name|Get
operator|)
operator|(
name|Ptr
operator|>>
literal|1
operator|)
operator|)
expr_stmt|;
block|}
return|return
name|reinterpret_cast
operator|<
name|T
operator|*
operator|>
operator|(
name|Ptr
operator|)
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief A lazy pointer to a statement.
end_comment

begin_typedef
typedef|typedef
name|LazyOffsetPtr
operator|<
name|Stmt
operator|,
name|uint64_t
operator|,
operator|&
name|ExternalASTSource
operator|::
name|GetExternalDeclStmt
operator|>
name|LazyDeclStmtPtr
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief A lazy pointer to a declaration.
end_comment

begin_typedef
typedef|typedef
name|LazyOffsetPtr
operator|<
name|Decl
operator|,
name|uint32_t
operator|,
operator|&
name|ExternalASTSource
operator|::
name|GetExternalDecl
operator|>
name|LazyDeclPtr
expr_stmt|;
end_typedef

begin_comment
comment|/// \brief A lazy pointer to a set of CXXBaseSpecifiers.
end_comment

begin_typedef
typedef|typedef
name|LazyOffsetPtr
operator|<
name|CXXBaseSpecifier
operator|,
name|uint64_t
operator|,
operator|&
name|ExternalASTSource
operator|::
name|GetExternalCXXBaseSpecifiers
operator|>
name|LazyCXXBaseSpecifiersPtr
expr_stmt|;
end_typedef

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_AST_EXTERNAL_AST_SOURCE_H
end_comment

end_unit

