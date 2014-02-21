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
comment|//  construction of AST nodes from some external source.
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
file|"clang/AST/CharUnits.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclBase.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

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
name|DeclarationName
decl_stmt|;
name|class
name|ExternalSemaSource
decl_stmt|;
comment|// layering violation required for downcasting
name|class
name|FieldDecl
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|class
name|NamedDecl
decl_stmt|;
name|class
name|RecordDecl
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
comment|/// \brief Enumeration describing the result of loading information from
comment|/// an external source.
enum|enum
name|ExternalLoadResult
block|{
comment|/// \brief Loading the external information has succeeded.
name|ELR_Success
block|,
comment|/// \brief Loading the external information has failed.
name|ELR_Failure
block|,
comment|/// \brief The external information has already been loaded, and therefore
comment|/// no additional processing is required.
name|ELR_AlreadyLoaded
block|}
enum|;
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
comment|///
comment|/// The default implementation of this method is a no-op.
name|virtual
name|Decl
modifier|*
name|GetExternalDecl
parameter_list|(
name|uint32_t
name|ID
parameter_list|)
function_decl|;
comment|/// \brief Resolve a selector ID into a selector.
comment|///
comment|/// This operation only needs to be implemented if the AST source
comment|/// returns non-zero for GetNumKnownSelectors().
comment|///
comment|/// The default implementation of this method is a no-op.
name|virtual
name|Selector
name|GetExternalSelector
parameter_list|(
name|uint32_t
name|ID
parameter_list|)
function_decl|;
comment|/// \brief Returns the number of selectors known to the external AST
comment|/// source.
comment|///
comment|/// The default implementation of this method is a no-op.
name|virtual
name|uint32_t
name|GetNumExternalSelectors
parameter_list|()
function_decl|;
comment|/// \brief Resolve the offset of a statement in the decl stream into
comment|/// a statement.
comment|///
comment|/// This operation is meant to be used via a LazyOffsetPtr.  It only
comment|/// needs to be implemented if the AST source uses methods like
comment|/// FunctionDecl::setLazyBody when building decls.
comment|///
comment|/// The default implementation of this method is a no-op.
name|virtual
name|Stmt
modifier|*
name|GetExternalDeclStmt
parameter_list|(
name|uint64_t
name|Offset
parameter_list|)
function_decl|;
comment|/// \brief Resolve the offset of a set of C++ base specifiers in the decl
comment|/// stream into an array of specifiers.
comment|///
comment|/// The default implementation of this method is a no-op.
name|virtual
name|CXXBaseSpecifier
modifier|*
name|GetExternalCXXBaseSpecifiers
parameter_list|(
name|uint64_t
name|Offset
parameter_list|)
function_decl|;
comment|/// \brief Update an out-of-date identifier.
name|virtual
name|void
name|updateOutOfDateIdentifier
parameter_list|(
name|IdentifierInfo
modifier|&
name|II
parameter_list|)
block|{ }
comment|/// \brief Find all declarations with the given name in the given context,
comment|/// and add them to the context by calling SetExternalVisibleDeclsForName
comment|/// or SetNoExternalVisibleDeclsForName.
comment|/// \return \c true if any declarations might have been found, \c false if
comment|/// we definitely have no declarations with tbis name.
comment|///
comment|/// The default implementation of this method is a no-op returning \c false.
name|virtual
name|bool
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
function_decl|;
comment|/// \brief Ensures that the table of all visible declarations inside this
comment|/// context is up to date.
comment|///
comment|/// The default implementation of this function is a no-op.
name|virtual
name|void
name|completeVisibleDeclsMap
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|DC
parameter_list|)
function_decl|;
comment|/// \brief Retrieve the module that corresponds to the given module ID.
name|virtual
name|Module
modifier|*
name|getModule
parameter_list|(
name|unsigned
name|ID
parameter_list|)
block|{
return|return
literal|0
return|;
block|}
comment|/// \brief Finds all declarations lexically contained within the given
comment|/// DeclContext, after applying an optional filter predicate.
comment|///
comment|/// \param isKindWeWant a predicate function that returns true if the passed
comment|/// declaration kind is one we are looking for. If NULL, all declarations
comment|/// are returned.
comment|///
comment|/// \return an indication of whether the load succeeded or failed.
comment|///
comment|/// The default implementation of this method is a no-op.
name|virtual
name|ExternalLoadResult
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
name|SmallVectorImpl
operator|<
name|Decl
operator|*
operator|>
operator|&
name|Result
argument_list|)
decl_stmt|;
comment|/// \brief Finds all declarations lexically contained within the given
comment|/// DeclContext.
comment|///
comment|/// \return true if an error occurred
name|ExternalLoadResult
name|FindExternalLexicalDecls
argument_list|(
specifier|const
name|DeclContext
operator|*
name|DC
argument_list|,
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
name|ExternalLoadResult
name|FindExternalLexicalDeclsBy
argument_list|(
argument|const DeclContext *DC
argument_list|,
argument|SmallVectorImpl<Decl*>&Result
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
comment|/// \brief Get the decls that are contained in a file in the Offset/Length
comment|/// range. \p Length can be 0 to indicate a point at \p Offset instead of
comment|/// a range.
name|virtual
name|void
name|FindFileRegionDecls
argument_list|(
name|FileID
name|File
argument_list|,
name|unsigned
name|Offset
argument_list|,
name|unsigned
name|Length
argument_list|,
name|SmallVectorImpl
operator|<
name|Decl
operator|*
operator|>
operator|&
name|Decls
argument_list|)
block|{}
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
comment|/// \brief Loads comment ranges.
name|virtual
name|void
name|ReadComments
parameter_list|()
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
comment|/// \brief Perform layout on the given record.
comment|///
comment|/// This routine allows the external AST source to provide an specific
comment|/// layout for a record, overriding the layout that would normally be
comment|/// constructed. It is intended for clients who receive specific layout
comment|/// details rather than source code (such as LLDB). The client is expected
comment|/// to fill in the field offsets, base offsets, virtual base offsets, and
comment|/// complete object size.
comment|///
comment|/// \param Record The record whose layout is being requested.
comment|///
comment|/// \param Size The final size of the record, in bits.
comment|///
comment|/// \param Alignment The final alignment of the record, in bits.
comment|///
comment|/// \param FieldOffsets The offset of each of the fields within the record,
comment|/// expressed in bits. All of the fields must be provided with offsets.
comment|///
comment|/// \param BaseOffsets The offset of each of the direct, non-virtual base
comment|/// classes. If any bases are not given offsets, the bases will be laid
comment|/// out according to the ABI.
comment|///
comment|/// \param VirtualBaseOffsets The offset of each of the virtual base classes
comment|/// (either direct or not). If any bases are not given offsets, the bases will be laid
comment|/// out according to the ABI.
comment|///
comment|/// \returns true if the record layout was provided, false otherwise.
name|virtual
name|bool
name|layoutRecordType
argument_list|(
specifier|const
name|RecordDecl
operator|*
name|Record
argument_list|,
name|uint64_t
operator|&
name|Size
argument_list|,
name|uint64_t
operator|&
name|Alignment
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|FieldDecl
operator|*
argument_list|,
name|uint64_t
operator|>
operator|&
name|FieldOffsets
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CXXRecordDecl
operator|*
argument_list|,
name|CharUnits
operator|>
operator|&
name|BaseOffsets
argument_list|,
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CXXRecordDecl
operator|*
argument_list|,
name|CharUnits
operator|>
operator|&
name|VirtualBaseOffsets
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|//===--------------------------------------------------------------------===//
comment|// Queries for performance analysis.
comment|//===--------------------------------------------------------------------===//
struct|struct
name|MemoryBufferSizes
block|{
name|size_t
name|malloc_bytes
decl_stmt|;
name|size_t
name|mmap_bytes
decl_stmt|;
name|MemoryBufferSizes
argument_list|(
argument|size_t malloc_bytes
argument_list|,
argument|size_t mmap_bytes
argument_list|)
block|:
name|malloc_bytes
argument_list|(
name|malloc_bytes
argument_list|)
operator|,
name|mmap_bytes
argument_list|(
argument|mmap_bytes
argument_list|)
block|{}
block|}
struct|;
comment|/// Return the amount of memory used by memory buffers, breaking down
comment|/// by heap-backed versus mmap'ed memory.
name|MemoryBufferSizes
name|getMemoryBufferSizes
argument_list|()
specifier|const
block|{
name|MemoryBufferSizes
name|sizes
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|)
block|;
name|getMemoryBufferSizes
argument_list|(
name|sizes
argument_list|)
block|;
return|return
name|sizes
return|;
block|}
name|virtual
name|void
name|getMemoryBufferSizes
argument_list|(
name|MemoryBufferSizes
operator|&
name|sizes
argument_list|)
decl|const
decl_stmt|;
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
name|ArrayRef
operator|<
name|NamedDecl
operator|*
operator|>
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
name|LLVM_EXPLICIT
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
comment|/// \brief Whether this pointer is non-NULL.
comment|///
comment|/// This operation does not require the AST node to be deserialized.
name|bool
name|isValid
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
comment|/// \brief Represents a lazily-loaded vector of data.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The lazily-loaded vector of data contains data that is partially loaded
end_comment

begin_comment
comment|/// from an external source and partially added by local translation. The
end_comment

begin_comment
comment|/// items loaded from the external source are loaded lazily, when needed for
end_comment

begin_comment
comment|/// iteration over the complete vector.
end_comment

begin_expr_stmt
name|template
operator|<
name|typename
name|T
operator|,
name|typename
name|Source
operator|,
name|void
argument_list|(
name|Source
operator|::
operator|*
name|Loader
argument_list|)
argument_list|(
name|SmallVectorImpl
operator|<
name|T
operator|>
operator|&
argument_list|)
operator|,
name|unsigned
name|LoadedStorage
operator|=
literal|2
operator|,
name|unsigned
name|LocalStorage
operator|=
literal|4
operator|>
name|class
name|LazyVector
block|{
name|SmallVector
operator|<
name|T
block|,
name|LoadedStorage
operator|>
name|Loaded
block|;
name|SmallVector
operator|<
name|T
block|,
name|LocalStorage
operator|>
name|Local
block|;
name|public
operator|:
comment|// Iteration over the elements in the vector.
name|class
name|iterator
block|{
name|LazyVector
operator|*
name|Self
block|;
comment|/// \brief Position within the vector..
comment|///
comment|/// In a complete iteration, the Position field walks the range [-M, N),
comment|/// where negative values are used to indicate elements
comment|/// loaded from the external source while non-negative values are used to
comment|/// indicate elements added via \c push_back().
comment|/// However, to provide iteration in source order (for, e.g., chained
comment|/// precompiled headers), dereferencing the iterator flips the negative
comment|/// values (corresponding to loaded entities), so that position -M
comment|/// corresponds to element 0 in the loaded entities vector, position -M+1
comment|/// corresponds to element 1 in the loaded entities vector, etc. This
comment|/// gives us a reasonably efficient, source-order walk.
name|int
name|Position
block|;
name|friend
name|class
name|LazyVector
block|;
name|public
operator|:
typedef|typedef
name|T
name|value_type
typedef|;
typedef|typedef
name|value_type
modifier|&
name|reference
typedef|;
end_expr_stmt

begin_typedef
typedef|typedef
name|value_type
modifier|*
name|pointer
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|std
operator|::
name|random_access_iterator_tag
name|iterator_category
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|difference_type
typedef|;
end_typedef

begin_expr_stmt
name|iterator
argument_list|()
operator|:
name|Self
argument_list|(
literal|0
argument_list|)
operator|,
name|Position
argument_list|(
literal|0
argument_list|)
block|{ }
name|iterator
argument_list|(
argument|LazyVector *Self
argument_list|,
argument|int Position
argument_list|)
operator|:
name|Self
argument_list|(
name|Self
argument_list|)
operator|,
name|Position
argument_list|(
argument|Position
argument_list|)
block|{ }
name|reference
name|operator
operator|*
operator|(
operator|)
specifier|const
block|{
if|if
condition|(
name|Position
operator|<
literal|0
condition|)
return|return
name|Self
operator|->
name|Loaded
operator|.
name|end
argument_list|()
index|[
name|Position
index|]
return|;
end_expr_stmt

begin_return
return|return
name|Self
operator|->
name|Local
index|[
name|Position
index|]
return|;
end_return

begin_expr_stmt
unit|}          pointer
name|operator
operator|->
expr|(
end_expr_stmt

begin_expr_stmt
unit|)
specifier|const
block|{
if|if
condition|(
name|Position
operator|<
literal|0
condition|)
return|return
operator|&
name|Self
operator|->
name|Loaded
operator|.
name|end
argument_list|()
index|[
name|Position
index|]
return|;
end_expr_stmt

begin_return
return|return
operator|&
name|Self
operator|->
name|Local
index|[
name|Position
index|]
return|;
end_return

begin_expr_stmt
unit|}          reference
name|operator
index|[]
operator|(
name|difference_type
name|D
operator|)
block|{
return|return
operator|*
operator|(
operator|*
name|this
operator|+
name|D
operator|)
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator
operator|&
name|operator
operator|++
operator|(
operator|)
block|{
operator|++
name|Position
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator
name|operator
operator|++
operator|(
name|int
operator|)
block|{
name|iterator
name|Prev
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|++
name|Position
block|;
return|return
name|Prev
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator
operator|&
name|operator
operator|--
operator|(
operator|)
block|{
operator|--
name|Position
block|;
return|return
operator|*
name|this
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|iterator
name|operator
operator|--
operator|(
name|int
operator|)
block|{
name|iterator
name|Prev
argument_list|(
operator|*
name|this
argument_list|)
block|;
operator|--
name|Position
block|;
return|return
name|Prev
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|iterator
operator|&
name|X
operator|,
specifier|const
name|iterator
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Position
operator|==
name|Y
operator|.
name|Position
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|!=
operator|(
specifier|const
name|iterator
operator|&
name|X
operator|,
specifier|const
name|iterator
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Position
operator|!=
name|Y
operator|.
name|Position
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|<
operator|(
specifier|const
name|iterator
operator|&
name|X
operator|,
specifier|const
name|iterator
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Position
operator|<
name|Y
operator|.
name|Position
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|>
operator|(
specifier|const
name|iterator
operator|&
name|X
operator|,
specifier|const
name|iterator
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Position
operator|>
name|Y
operator|.
name|Position
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|iterator
operator|&
name|X
operator|,
specifier|const
name|iterator
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Position
operator|<
name|Y
operator|.
name|Position
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|iterator
operator|&
name|X
operator|,
specifier|const
name|iterator
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Position
operator|>
name|Y
operator|.
name|Position
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|iterator
operator|&
name|operator
operator|+=
operator|(
name|iterator
operator|&
name|X
operator|,
name|difference_type
name|D
operator|)
block|{
name|X
operator|.
name|Position
operator|+=
name|D
block|;
return|return
name|X
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|iterator
operator|&
name|operator
operator|-=
operator|(
name|iterator
operator|&
name|X
operator|,
name|difference_type
name|D
operator|)
block|{
name|X
operator|.
name|Position
operator|-=
name|D
block|;
return|return
name|X
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|iterator
name|operator
operator|+
operator|(
name|iterator
name|X
operator|,
name|difference_type
name|D
operator|)
block|{
name|X
operator|.
name|Position
operator|+=
name|D
block|;
return|return
name|X
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|iterator
name|operator
operator|+
operator|(
name|difference_type
name|D
operator|,
name|iterator
name|X
operator|)
block|{
name|X
operator|.
name|Position
operator|+=
name|D
block|;
return|return
name|X
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|difference_type
name|operator
operator|-
operator|(
specifier|const
name|iterator
operator|&
name|X
operator|,
specifier|const
name|iterator
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|Position
operator|-
name|Y
operator|.
name|Position
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|friend
name|iterator
name|operator
operator|-
operator|(
name|iterator
name|X
operator|,
name|difference_type
name|D
operator|)
block|{
name|X
operator|.
name|Position
operator|-=
name|D
block|;
return|return
name|X
return|;
block|}
end_expr_stmt

begin_decl_stmt
unit|};
name|friend
name|class
name|iterator
decl_stmt|;
end_decl_stmt

begin_function
name|iterator
name|begin
parameter_list|(
name|Source
modifier|*
name|source
parameter_list|,
name|bool
name|LocalOnly
init|=
name|false
parameter_list|)
block|{
if|if
condition|(
name|LocalOnly
condition|)
return|return
name|iterator
argument_list|(
name|this
argument_list|,
literal|0
argument_list|)
return|;
if|if
condition|(
name|source
condition|)
operator|(
name|source
operator|->*
name|Loader
operator|)
operator|(
name|Loaded
operator|)
expr_stmt|;
return|return
name|iterator
argument_list|(
name|this
argument_list|,
operator|-
operator|(
name|int
operator|)
name|Loaded
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
name|iterator
name|end
parameter_list|()
block|{
return|return
name|iterator
argument_list|(
name|this
argument_list|,
name|Local
operator|.
name|size
argument_list|()
argument_list|)
return|;
block|}
end_function

begin_function
name|void
name|push_back
parameter_list|(
specifier|const
name|T
modifier|&
name|LocalValue
parameter_list|)
block|{
name|Local
operator|.
name|push_back
argument_list|(
name|LocalValue
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
name|void
name|erase
parameter_list|(
name|iterator
name|From
parameter_list|,
name|iterator
name|To
parameter_list|)
block|{
if|if
condition|(
name|From
operator|.
name|Position
operator|<
literal|0
operator|&&
name|To
operator|.
name|Position
operator|<
literal|0
condition|)
block|{
name|Loaded
operator|.
name|erase
argument_list|(
name|Loaded
operator|.
name|end
argument_list|()
operator|+
name|From
operator|.
name|Position
argument_list|,
name|Loaded
operator|.
name|end
argument_list|()
operator|+
name|To
operator|.
name|Position
argument_list|)
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|From
operator|.
name|Position
operator|<
literal|0
condition|)
block|{
name|Loaded
operator|.
name|erase
argument_list|(
name|Loaded
operator|.
name|end
argument_list|()
operator|+
name|From
operator|.
name|Position
argument_list|,
name|Loaded
operator|.
name|end
argument_list|()
argument_list|)
expr_stmt|;
name|From
operator|=
name|begin
argument_list|(
literal|0
argument_list|,
name|true
argument_list|)
expr_stmt|;
block|}
name|Local
operator|.
name|erase
argument_list|(
name|Local
operator|.
name|begin
argument_list|()
operator|+
name|From
operator|.
name|Position
argument_list|,
name|Local
operator|.
name|begin
argument_list|()
operator|+
name|To
operator|.
name|Position
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
unit|};
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

