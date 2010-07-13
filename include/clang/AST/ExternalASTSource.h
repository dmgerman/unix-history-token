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
file|"clang/AST/DeclarationName.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
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
name|clang
block|{
name|class
name|ASTConsumer
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|DeclContext
decl_stmt|;
name|class
name|ExternalSemaSource
decl_stmt|;
comment|// layering violation required for downcasting
name|class
name|Stmt
decl_stmt|;
comment|/// \brief The deserialized representation of a set of declarations
comment|/// with the same name that are visible in a given context.
struct|struct
name|VisibleDeclaration
block|{
comment|/// \brief The name of the declarations.
name|DeclarationName
name|Name
decl_stmt|;
comment|/// \brief The ID numbers of all of the declarations with this name.
comment|///
comment|/// These declarations have not necessarily been de-serialized.
name|llvm
operator|::
name|SmallVector
operator|<
name|unsigned
operator|,
literal|4
operator|>
name|Declarations
expr_stmt|;
block|}
struct|;
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
comment|/// \brief Finds all declarations with the given name in the
comment|/// given context.
comment|///
comment|/// Generally the final step of this method is either to call
comment|/// SetExternalVisibleDeclsForName or to recursively call lookup on
comment|/// the DeclContext after calling SetExternalVisibleDecls.
name|virtual
name|DeclContext
operator|::
name|lookup_result
name|FindExternalVisibleDeclsByName
argument_list|(
argument|const DeclContext *DC
argument_list|,
argument|DeclarationName Name
argument_list|)
operator|=
literal|0
expr_stmt|;
comment|/// \brief Finds all declarations lexically contained within the given
comment|/// DeclContext.
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
comment|/// \brief Initialize the context's lookup map with the given decls.
comment|/// It is assumed that none of the declarations are redeclarations of
comment|/// each other.
specifier|static
name|void
name|SetExternalVisibleDecls
argument_list|(
specifier|const
name|DeclContext
operator|*
name|DC
argument_list|,
specifier|const
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|VisibleDeclaration
operator|>
operator|&
name|Decls
argument_list|)
decl_stmt|;
comment|/// \brief Initialize the context's lookup map with the given decls.
comment|/// It is assumed that none of the declarations are redeclarations of
comment|/// each other.
specifier|static
name|void
name|SetExternalVisibleDecls
argument_list|(
specifier|const
name|DeclContext
operator|*
name|DC
argument_list|,
specifier|const
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
name|DeclContext
operator|::
name|lookup_result
name|SetExternalVisibleDeclsForName
argument_list|(
specifier|const
name|DeclContext
operator|*
name|DC
argument_list|,
specifier|const
name|VisibleDeclaration
operator|&
name|VD
argument_list|)
expr_stmt|;
specifier|static
name|DeclContext
operator|::
name|lookup_result
name|SetExternalVisibleDeclsForName
argument_list|(
argument|const DeclContext *DC
argument_list|,
argument|DeclarationName Name
argument_list|,
argument|llvm::SmallVectorImpl<NamedDecl*>&Decls
argument_list|)
expr_stmt|;
specifier|static
name|DeclContext
operator|::
name|lookup_result
name|SetNoExternalVisibleDeclsForName
argument_list|(
argument|const DeclContext *DC
argument_list|,
argument|DeclarationName Name
argument_list|)
expr_stmt|;
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
name|T
operator|*
operator|(
name|ExternalASTSource
operator|::
operator|*
name|Get
operator|)
operator|(
name|uint64_t
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
operator|&
name|ExternalASTSource
operator|::
name|GetExternalDeclStmt
operator|>
name|LazyDeclStmtPtr
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

