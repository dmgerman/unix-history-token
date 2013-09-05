begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ASTTypeTraits.h ----------------------------------------*- C++ -*-===//
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
comment|//  Provides a dynamically typed node container that can be used to store
end_comment

begin_comment
comment|//  an AST base node at runtime in the same storage in a type safe way.
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
name|LLVM_CLANG_AST_AST_TYPE_TRAITS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_AST_TYPE_TRAITS_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Stmt.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TypeLoc.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/AlignOf.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|ast_type_traits
block|{
comment|/// \brief A dynamically typed AST node container.
comment|///
comment|/// Stores an AST node in a type safe way. This allows writing code that
comment|/// works with different kinds of AST nodes, despite the fact that they don't
comment|/// have a common base class.
comment|///
comment|/// Use \c create(Node) to create a \c DynTypedNode from an AST node,
comment|/// and \c get<T>() to retrieve the node as type T if the types match.
comment|///
comment|/// See \c NodeTypeTag for which node base types are currently supported;
comment|/// You can create DynTypedNodes for all nodes in the inheritance hierarchy of
comment|/// the supported base types.
name|class
name|DynTypedNode
block|{
name|public
label|:
comment|/// \brief Creates a \c DynTypedNode from \c Node.
name|template
operator|<
name|typename
name|T
operator|>
specifier|static
name|DynTypedNode
name|create
argument_list|(
argument|const T&Node
argument_list|)
block|{
return|return
name|BaseConverter
operator|<
name|T
operator|>
operator|::
name|create
argument_list|(
name|Node
argument_list|)
return|;
block|}
comment|/// \brief Retrieve the stored node as type \c T.
comment|///
comment|/// Returns NULL if the stored node does not have a type that is
comment|/// convertible to \c T.
comment|///
comment|/// For types that have identity via their pointer in the AST
comment|/// (like \c Stmt and \c Decl) the returned pointer points to the
comment|/// referenced AST node.
comment|/// For other types (like \c QualType) the value is stored directly
comment|/// in the \c DynTypedNode, and the returned pointer points at
comment|/// the storage inside DynTypedNode. For those nodes, do not
comment|/// use the pointer outside the scope of the DynTypedNode.
name|template
operator|<
name|typename
name|T
operator|>
specifier|const
name|T
operator|*
name|get
argument_list|()
specifier|const
block|{
return|return
name|BaseConverter
operator|<
name|T
operator|>
operator|::
name|get
argument_list|(
name|Tag
argument_list|,
name|Storage
operator|.
name|buffer
argument_list|)
return|;
block|}
comment|/// \brief Returns a pointer that identifies the stored AST node.
comment|///
comment|/// Note that this is not supported by all AST nodes. For AST nodes
comment|/// that don't have a pointer-defined identity inside the AST, this
comment|/// method returns NULL.
specifier|const
name|void
operator|*
name|getMemoizationData
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
comment|/// \brief Takes care of converting from and to \c T.
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|EnablerT
operator|=
name|void
operator|>
expr|struct
name|BaseConverter
expr_stmt|;
comment|/// \brief Supported base node types.
enum|enum
name|NodeTypeTag
block|{
name|NT_Decl
block|,
name|NT_Stmt
block|,
name|NT_NestedNameSpecifier
block|,
name|NT_NestedNameSpecifierLoc
block|,
name|NT_QualType
block|,
name|NT_Type
block|,
name|NT_TypeLoc
block|}
name|Tag
enum|;
comment|/// \brief Stores the data of the node.
comment|///
comment|/// Note that we can store \c Decls and \c Stmts by pointer as they are
comment|/// guaranteed to be unique pointers pointing to dedicated storage in the
comment|/// AST. \c QualTypes on the other hand do not have storage or unique
comment|/// pointers and thus need to be stored by value.
name|llvm
operator|::
name|AlignedCharArrayUnion
operator|<
name|Decl
operator|*
operator|,
name|Stmt
operator|*
operator|,
name|NestedNameSpecifier
operator|,
name|NestedNameSpecifierLoc
operator|,
name|QualType
operator|,
name|Type
operator|,
name|TypeLoc
operator|>
name|Storage
expr_stmt|;
block|}
empty_stmt|;
comment|// FIXME: Pull out abstraction for the following.
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|DynTypedNode
operator|::
name|BaseConverter
operator|<
name|T
operator|,
name|typename
name|llvm
operator|::
name|enable_if
operator|<
name|llvm
operator|::
name|is_base_of
operator|<
name|Decl
operator|,
name|T
operator|>
expr|>
operator|::
name|type
operator|>
block|{
specifier|static
specifier|const
name|T
operator|*
name|get
argument_list|(
argument|NodeTypeTag Tag
argument_list|,
argument|const char Storage[]
argument_list|)
block|{
if|if
condition|(
name|Tag
operator|==
name|NT_Decl
condition|)
return|return
name|dyn_cast
operator|<
name|T
operator|>
operator|(
operator|*
name|reinterpret_cast
operator|<
name|Decl
operator|*
specifier|const
operator|*
operator|>
operator|(
name|Storage
operator|)
operator|)
return|;
return|return
name|NULL
return|;
block|}
specifier|static
name|DynTypedNode
name|create
parameter_list|(
specifier|const
name|Decl
modifier|&
name|Node
parameter_list|)
block|{
name|DynTypedNode
name|Result
decl_stmt|;
name|Result
operator|.
name|Tag
operator|=
name|NT_Decl
expr_stmt|;
name|new
argument_list|(
argument|Result.Storage.buffer
argument_list|)
specifier|const
name|Decl
operator|*
operator|(
operator|&
name|Node
operator|)
expr_stmt|;
return|return
name|Result
return|;
block|}
block|}
empty_stmt|;
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|DynTypedNode
operator|::
name|BaseConverter
operator|<
name|T
operator|,
name|typename
name|llvm
operator|::
name|enable_if
operator|<
name|llvm
operator|::
name|is_base_of
operator|<
name|Stmt
operator|,
name|T
operator|>
expr|>
operator|::
name|type
operator|>
block|{
specifier|static
specifier|const
name|T
operator|*
name|get
argument_list|(
argument|NodeTypeTag Tag
argument_list|,
argument|const char Storage[]
argument_list|)
block|{
if|if
condition|(
name|Tag
operator|==
name|NT_Stmt
condition|)
return|return
name|dyn_cast
operator|<
name|T
operator|>
operator|(
operator|*
name|reinterpret_cast
operator|<
name|Stmt
operator|*
specifier|const
operator|*
operator|>
operator|(
name|Storage
operator|)
operator|)
return|;
return|return
name|NULL
return|;
block|}
specifier|static
name|DynTypedNode
name|create
parameter_list|(
specifier|const
name|Stmt
modifier|&
name|Node
parameter_list|)
block|{
name|DynTypedNode
name|Result
decl_stmt|;
name|Result
operator|.
name|Tag
operator|=
name|NT_Stmt
expr_stmt|;
name|new
argument_list|(
argument|Result.Storage.buffer
argument_list|)
specifier|const
name|Stmt
operator|*
operator|(
operator|&
name|Node
operator|)
expr_stmt|;
return|return
name|Result
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|>
expr|struct
name|DynTypedNode
operator|::
name|BaseConverter
operator|<
name|T
operator|,
name|typename
name|llvm
operator|::
name|enable_if
operator|<
name|llvm
operator|::
name|is_base_of
operator|<
name|Type
operator|,
name|T
operator|>
expr|>
operator|::
name|type
operator|>
block|{
specifier|static
specifier|const
name|T
operator|*
name|get
argument_list|(
argument|NodeTypeTag Tag
argument_list|,
argument|const char Storage[]
argument_list|)
block|{
if|if
condition|(
name|Tag
operator|==
name|NT_Type
condition|)
return|return
name|dyn_cast
operator|<
name|T
operator|>
operator|(
operator|*
name|reinterpret_cast
operator|<
name|Type
operator|*
specifier|const
operator|*
operator|>
operator|(
name|Storage
operator|)
operator|)
return|;
return|return
name|NULL
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|DynTypedNode
name|create
parameter_list|(
specifier|const
name|Type
modifier|&
name|Node
parameter_list|)
block|{
name|DynTypedNode
name|Result
decl_stmt|;
name|Result
operator|.
name|Tag
operator|=
name|NT_Type
expr_stmt|;
name|new
argument_list|(
argument|Result.Storage.buffer
argument_list|)
specifier|const
name|Type
operator|*
operator|(
operator|&
name|Node
operator|)
expr_stmt|;
return|return
name|Result
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|DynTypedNode
operator|::
name|BaseConverter
operator|<
name|NestedNameSpecifier
operator|,
name|void
operator|>
block|{
specifier|static
specifier|const
name|NestedNameSpecifier
operator|*
name|get
argument_list|(
argument|NodeTypeTag Tag
argument_list|,
argument|const char Storage[]
argument_list|)
block|{
if|if
condition|(
name|Tag
operator|==
name|NT_NestedNameSpecifier
condition|)
return|return
operator|*
name|reinterpret_cast
operator|<
name|NestedNameSpecifier
operator|*
specifier|const
operator|*
operator|>
operator|(
name|Storage
operator|)
return|;
return|return
name|NULL
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|DynTypedNode
name|create
parameter_list|(
specifier|const
name|NestedNameSpecifier
modifier|&
name|Node
parameter_list|)
block|{
name|DynTypedNode
name|Result
decl_stmt|;
name|Result
operator|.
name|Tag
operator|=
name|NT_NestedNameSpecifier
expr_stmt|;
name|new
argument_list|(
argument|Result.Storage.buffer
argument_list|)
specifier|const
name|NestedNameSpecifier
operator|*
operator|(
operator|&
name|Node
operator|)
expr_stmt|;
return|return
name|Result
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|DynTypedNode
operator|::
name|BaseConverter
operator|<
name|NestedNameSpecifierLoc
operator|,
name|void
operator|>
block|{
specifier|static
specifier|const
name|NestedNameSpecifierLoc
operator|*
name|get
argument_list|(
argument|NodeTypeTag Tag
argument_list|,
argument|const char Storage[]
argument_list|)
block|{
if|if
condition|(
name|Tag
operator|==
name|NT_NestedNameSpecifierLoc
condition|)
return|return
name|reinterpret_cast
operator|<
specifier|const
name|NestedNameSpecifierLoc
operator|*
operator|>
operator|(
name|Storage
operator|)
return|;
return|return
name|NULL
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|DynTypedNode
name|create
parameter_list|(
specifier|const
name|NestedNameSpecifierLoc
modifier|&
name|Node
parameter_list|)
block|{
name|DynTypedNode
name|Result
decl_stmt|;
name|Result
operator|.
name|Tag
operator|=
name|NT_NestedNameSpecifierLoc
expr_stmt|;
name|new
argument_list|(
argument|Result.Storage.buffer
argument_list|)
name|NestedNameSpecifierLoc
argument_list|(
name|Node
argument_list|)
expr_stmt|;
return|return
name|Result
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|DynTypedNode
operator|::
name|BaseConverter
operator|<
name|QualType
operator|,
name|void
operator|>
block|{
specifier|static
specifier|const
name|QualType
operator|*
name|get
argument_list|(
argument|NodeTypeTag Tag
argument_list|,
argument|const char Storage[]
argument_list|)
block|{
if|if
condition|(
name|Tag
operator|==
name|NT_QualType
condition|)
return|return
name|reinterpret_cast
operator|<
specifier|const
name|QualType
operator|*
operator|>
operator|(
name|Storage
operator|)
return|;
return|return
name|NULL
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|DynTypedNode
name|create
parameter_list|(
specifier|const
name|QualType
modifier|&
name|Node
parameter_list|)
block|{
name|DynTypedNode
name|Result
decl_stmt|;
name|Result
operator|.
name|Tag
operator|=
name|NT_QualType
expr_stmt|;
name|new
argument_list|(
argument|Result.Storage.buffer
argument_list|)
name|QualType
argument_list|(
name|Node
argument_list|)
expr_stmt|;
return|return
name|Result
return|;
block|}
end_function

begin_expr_stmt
unit|};
name|template
operator|<
operator|>
expr|struct
name|DynTypedNode
operator|::
name|BaseConverter
operator|<
name|TypeLoc
operator|,
name|void
operator|>
block|{
specifier|static
specifier|const
name|TypeLoc
operator|*
name|get
argument_list|(
argument|NodeTypeTag Tag
argument_list|,
argument|const char Storage[]
argument_list|)
block|{
if|if
condition|(
name|Tag
operator|==
name|NT_TypeLoc
condition|)
return|return
name|reinterpret_cast
operator|<
specifier|const
name|TypeLoc
operator|*
operator|>
operator|(
name|Storage
operator|)
return|;
return|return
name|NULL
return|;
block|}
end_expr_stmt

begin_function
specifier|static
name|DynTypedNode
name|create
parameter_list|(
specifier|const
name|TypeLoc
modifier|&
name|Node
parameter_list|)
block|{
name|DynTypedNode
name|Result
decl_stmt|;
name|Result
operator|.
name|Tag
operator|=
name|NT_TypeLoc
expr_stmt|;
name|new
argument_list|(
argument|Result.Storage.buffer
argument_list|)
name|TypeLoc
argument_list|(
name|Node
argument_list|)
expr_stmt|;
return|return
name|Result
return|;
block|}
end_function

begin_comment
unit|};
comment|// The only operation we allow on unsupported types is \c get.
end_comment

begin_comment
comment|// This allows to conveniently use \c DynTypedNode when having an arbitrary
end_comment

begin_comment
comment|// AST node that is not supported, but prevents misuse - a user cannot create
end_comment

begin_comment
comment|// a DynTypedNode from arbitrary types.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|EnablerT
operator|>
expr|struct
name|DynTypedNode
operator|::
name|BaseConverter
block|{
specifier|static
specifier|const
name|T
operator|*
name|get
argument_list|(
argument|NodeTypeTag Tag
argument_list|,
argument|const char Storage[]
argument_list|)
block|{
return|return
name|NULL
return|;
block|}
end_expr_stmt

begin_expr_stmt
unit|};
specifier|inline
specifier|const
name|void
operator|*
name|DynTypedNode
operator|::
name|getMemoizationData
argument_list|()
specifier|const
block|{
switch|switch
condition|(
name|Tag
condition|)
block|{
case|case
name|NT_Decl
case|:
return|return
name|BaseConverter
operator|<
name|Decl
operator|>
operator|::
name|get
argument_list|(
name|Tag
argument_list|,
name|Storage
operator|.
name|buffer
argument_list|)
return|;
case|case
name|NT_Stmt
case|:
return|return
name|BaseConverter
operator|<
name|Stmt
operator|>
operator|::
name|get
argument_list|(
name|Tag
argument_list|,
name|Storage
operator|.
name|buffer
argument_list|)
return|;
default|default:
return|return
name|NULL
return|;
block|}
expr_stmt|;
end_expr_stmt

begin_comment
unit|}  }
comment|// end namespace ast_type_traits
end_comment

begin_comment
unit|}
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_AST_AST_TYPE_TRAITS_H
end_comment

end_unit

