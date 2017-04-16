begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- MultiplexExternalSemaSource.h - External Sema Interface-*- C++ -*-===//
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
comment|//  This file defines ExternalSemaSource interface, dispatching to all clients
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
name|LLVM_CLANG_SEMA_MULTIPLEXEXTERNALSEMASOURCE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_MULTIPLEXEXTERNALSEMASOURCE_H
end_define

begin_include
include|#
directive|include
file|"clang/Sema/ExternalSemaSource.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/Weak.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CXXConstructorDecl
decl_stmt|;
name|class
name|CXXRecordDecl
decl_stmt|;
name|class
name|DeclaratorDecl
decl_stmt|;
struct_decl|struct
name|ExternalVTableUse
struct_decl|;
name|class
name|LookupResult
decl_stmt|;
name|class
name|NamespaceDecl
decl_stmt|;
name|class
name|Scope
decl_stmt|;
name|class
name|Sema
decl_stmt|;
name|class
name|TypedefNameDecl
decl_stmt|;
name|class
name|ValueDecl
decl_stmt|;
name|class
name|VarDecl
decl_stmt|;
comment|/// \brief An abstract interface that should be implemented by
comment|/// external AST sources that also provide information for semantic
comment|/// analysis.
name|class
name|MultiplexExternalSemaSource
range|:
name|public
name|ExternalSemaSource
block|{
name|private
operator|:
name|SmallVector
operator|<
name|ExternalSemaSource
operator|*
block|,
literal|2
operator|>
name|Sources
block|;
comment|// doesn't own them.
name|public
operator|:
comment|///\brief Constructs a new multiplexing external sema source and appends the
comment|/// given element to it.
comment|///
comment|///\param[in] s1 - A non-null (old) ExternalSemaSource.
comment|///\param[in] s2 - A non-null (new) ExternalSemaSource.
comment|///
name|MultiplexExternalSemaSource
argument_list|(
name|ExternalSemaSource
operator|&
name|s1
argument_list|,
name|ExternalSemaSource
operator|&
name|s2
argument_list|)
block|;
operator|~
name|MultiplexExternalSemaSource
argument_list|()
name|override
block|;
comment|///\brief Appends new source to the source list.
comment|///
comment|///\param[in] source - An ExternalSemaSource.
comment|///
name|void
name|addSource
argument_list|(
name|ExternalSemaSource
operator|&
name|source
argument_list|)
block|;
comment|//===--------------------------------------------------------------------===//
comment|// ExternalASTSource.
comment|//===--------------------------------------------------------------------===//
comment|/// \brief Resolve a declaration ID into a declaration, potentially
comment|/// building a new declaration.
name|Decl
operator|*
name|GetExternalDecl
argument_list|(
argument|uint32_t ID
argument_list|)
name|override
block|;
comment|/// \brief Complete the redeclaration chain if it's been extended since the
comment|/// previous generation of the AST source.
name|void
name|CompleteRedeclChain
argument_list|(
argument|const Decl *D
argument_list|)
name|override
block|;
comment|/// \brief Resolve a selector ID into a selector.
name|Selector
name|GetExternalSelector
argument_list|(
argument|uint32_t ID
argument_list|)
name|override
block|;
comment|/// \brief Returns the number of selectors known to the external AST
comment|/// source.
name|uint32_t
name|GetNumExternalSelectors
argument_list|()
name|override
block|;
comment|/// \brief Resolve the offset of a statement in the decl stream into
comment|/// a statement.
name|Stmt
operator|*
name|GetExternalDeclStmt
argument_list|(
argument|uint64_t Offset
argument_list|)
name|override
block|;
comment|/// \brief Resolve the offset of a set of C++ base specifiers in the decl
comment|/// stream into an array of specifiers.
name|CXXBaseSpecifier
operator|*
name|GetExternalCXXBaseSpecifiers
argument_list|(
argument|uint64_t Offset
argument_list|)
name|override
block|;
comment|/// \brief Resolve a handle to a list of ctor initializers into the list of
comment|/// initializers themselves.
name|CXXCtorInitializer
operator|*
operator|*
name|GetExternalCXXCtorInitializers
argument_list|(
argument|uint64_t Offset
argument_list|)
name|override
block|;
name|ExtKind
name|hasExternalDefinitions
argument_list|(
argument|const Decl *D
argument_list|)
name|override
block|;
comment|/// \brief Find all declarations with the given name in the
comment|/// given context.
name|bool
name|FindExternalVisibleDeclsByName
argument_list|(
argument|const DeclContext *DC
argument_list|,
argument|DeclarationName Name
argument_list|)
name|override
block|;
comment|/// \brief Ensures that the table of all visible declarations inside this
comment|/// context is up to date.
name|void
name|completeVisibleDeclsMap
argument_list|(
argument|const DeclContext *DC
argument_list|)
name|override
block|;
comment|/// \brief Finds all declarations lexically contained within the given
comment|/// DeclContext, after applying an optional filter predicate.
comment|///
comment|/// \param IsKindWeWant a predicate function that returns true if the passed
comment|/// declaration kind is one we are looking for.
name|void
name|FindExternalLexicalDecls
argument_list|(
argument|const DeclContext *DC
argument_list|,
argument|llvm::function_ref<bool(Decl::Kind)> IsKindWeWant
argument_list|,
argument|SmallVectorImpl<Decl *>&Result
argument_list|)
name|override
block|;
comment|/// \brief Get the decls that are contained in a file in the Offset/Length
comment|/// range. \p Length can be 0 to indicate a point at \p Offset instead of
comment|/// a range.
name|void
name|FindFileRegionDecls
argument_list|(
argument|FileID File
argument_list|,
argument|unsigned Offset
argument_list|,
argument|unsigned Length
argument_list|,
argument|SmallVectorImpl<Decl *>&Decls
argument_list|)
name|override
block|;
comment|/// \brief Gives the external AST source an opportunity to complete
comment|/// an incomplete type.
name|void
name|CompleteType
argument_list|(
argument|TagDecl *Tag
argument_list|)
name|override
block|;
comment|/// \brief Gives the external AST source an opportunity to complete an
comment|/// incomplete Objective-C class.
comment|///
comment|/// This routine will only be invoked if the "externally completed" bit is
comment|/// set on the ObjCInterfaceDecl via the function
comment|/// \c ObjCInterfaceDecl::setExternallyCompleted().
name|void
name|CompleteType
argument_list|(
argument|ObjCInterfaceDecl *Class
argument_list|)
name|override
block|;
comment|/// \brief Loads comment ranges.
name|void
name|ReadComments
argument_list|()
name|override
block|;
comment|/// \brief Notify ExternalASTSource that we started deserialization of
comment|/// a decl or type so until FinishedDeserializing is called there may be
comment|/// decls that are initializing. Must be paired with FinishedDeserializing.
name|void
name|StartedDeserializing
argument_list|()
name|override
block|;
comment|/// \brief Notify ExternalASTSource that we finished the deserialization of
comment|/// a decl or type. Must be paired with StartedDeserializing.
name|void
name|FinishedDeserializing
argument_list|()
name|override
block|;
comment|/// \brief Function that will be invoked when we begin parsing a new
comment|/// translation unit involving this external AST source.
name|void
name|StartTranslationUnit
argument_list|(
argument|ASTConsumer *Consumer
argument_list|)
name|override
block|;
comment|/// \brief Print any statistics that have been gathered regarding
comment|/// the external AST source.
name|void
name|PrintStats
argument_list|()
name|override
block|;
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
comment|/// (either direct or not). If any bases are not given offsets, the bases will
comment|/// be laid out according to the ABI.
comment|///
comment|/// \returns true if the record layout was provided, false otherwise.
name|bool
name|layoutRecordType
argument_list|(
argument|const RecordDecl *Record
argument_list|,
argument|uint64_t&Size
argument_list|,
argument|uint64_t&Alignment
argument_list|,
argument|llvm::DenseMap<const FieldDecl *
argument_list|,
argument|uint64_t>&FieldOffsets
argument_list|,
argument|llvm::DenseMap<const CXXRecordDecl *
argument_list|,
argument|CharUnits>&BaseOffsets
argument_list|,
argument|llvm::DenseMap<const CXXRecordDecl *
argument_list|,
argument|CharUnits>&VirtualBaseOffsets
argument_list|)
name|override
block|;
comment|/// Return the amount of memory used by memory buffers, breaking down
comment|/// by heap-backed versus mmap'ed memory.
name|void
name|getMemoryBufferSizes
argument_list|(
argument|MemoryBufferSizes&sizes
argument_list|)
specifier|const
name|override
block|;
comment|//===--------------------------------------------------------------------===//
comment|// ExternalSemaSource.
comment|//===--------------------------------------------------------------------===//
comment|/// \brief Initialize the semantic source with the Sema instance
comment|/// being used to perform semantic analysis on the abstract syntax
comment|/// tree.
name|void
name|InitializeSema
argument_list|(
argument|Sema&S
argument_list|)
name|override
block|;
comment|/// \brief Inform the semantic consumer that Sema is no longer available.
name|void
name|ForgetSema
argument_list|()
name|override
block|;
comment|/// \brief Load the contents of the global method pool for a given
comment|/// selector.
name|void
name|ReadMethodPool
argument_list|(
argument|Selector Sel
argument_list|)
name|override
block|;
comment|/// Load the contents of the global method pool for a given
comment|/// selector if necessary.
name|void
name|updateOutOfDateSelector
argument_list|(
argument|Selector Sel
argument_list|)
name|override
block|;
comment|/// \brief Load the set of namespaces that are known to the external source,
comment|/// which will be used during typo correction.
name|void
name|ReadKnownNamespaces
argument_list|(
argument|SmallVectorImpl<NamespaceDecl*>&Namespaces
argument_list|)
name|override
block|;
comment|/// \brief Load the set of used but not defined functions or variables with
comment|/// internal linkage, or used but not defined inline functions.
name|void
name|ReadUndefinedButUsed
argument_list|(
argument|llvm::MapVector<NamedDecl *
argument_list|,
argument|SourceLocation>&Undefined
argument_list|)
name|override
block|;
name|void
name|ReadMismatchingDeleteExpressions
argument_list|(
argument|llvm::MapVector<       FieldDecl *
argument_list|,
argument|llvm::SmallVector<std::pair<SourceLocation
argument_list|,
argument|bool>
argument_list|,
literal|4
argument|>>&                                             Exprs
argument_list|)
name|override
block|;
comment|/// \brief Do last resort, unqualified lookup on a LookupResult that
comment|/// Sema cannot find.
comment|///
comment|/// \param R a LookupResult that is being recovered.
comment|///
comment|/// \param S the Scope of the identifier occurrence.
comment|///
comment|/// \return true to tell Sema to recover using the LookupResult.
name|bool
name|LookupUnqualified
argument_list|(
argument|LookupResult&R
argument_list|,
argument|Scope *S
argument_list|)
name|override
block|;
comment|/// \brief Read the set of tentative definitions known to the external Sema
comment|/// source.
comment|///
comment|/// The external source should append its own tentative definitions to the
comment|/// given vector of tentative definitions. Note that this routine may be
comment|/// invoked multiple times; the external source should take care not to
comment|/// introduce the same declarations repeatedly.
name|void
name|ReadTentativeDefinitions
argument_list|(
argument|SmallVectorImpl<VarDecl*>&Defs
argument_list|)
name|override
block|;
comment|/// \brief Read the set of unused file-scope declarations known to the
comment|/// external Sema source.
comment|///
comment|/// The external source should append its own unused, filed-scope to the
comment|/// given vector of declarations. Note that this routine may be
comment|/// invoked multiple times; the external source should take care not to
comment|/// introduce the same declarations repeatedly.
name|void
name|ReadUnusedFileScopedDecls
argument_list|(
argument|SmallVectorImpl<const DeclaratorDecl*>&Decls
argument_list|)
name|override
block|;
comment|/// \brief Read the set of delegating constructors known to the
comment|/// external Sema source.
comment|///
comment|/// The external source should append its own delegating constructors to the
comment|/// given vector of declarations. Note that this routine may be
comment|/// invoked multiple times; the external source should take care not to
comment|/// introduce the same declarations repeatedly.
name|void
name|ReadDelegatingConstructors
argument_list|(
argument|SmallVectorImpl<CXXConstructorDecl*>&Decls
argument_list|)
name|override
block|;
comment|/// \brief Read the set of ext_vector type declarations known to the
comment|/// external Sema source.
comment|///
comment|/// The external source should append its own ext_vector type declarations to
comment|/// the given vector of declarations. Note that this routine may be
comment|/// invoked multiple times; the external source should take care not to
comment|/// introduce the same declarations repeatedly.
name|void
name|ReadExtVectorDecls
argument_list|(
argument|SmallVectorImpl<TypedefNameDecl*>&Decls
argument_list|)
name|override
block|;
comment|/// \brief Read the set of potentially unused typedefs known to the source.
comment|///
comment|/// The external source should append its own potentially unused local
comment|/// typedefs to the given vector of declarations. Note that this routine may
comment|/// be invoked multiple times; the external source should take care not to
comment|/// introduce the same declarations repeatedly.
name|void
name|ReadUnusedLocalTypedefNameCandidates
argument_list|(
argument|llvm::SmallSetVector<const TypedefNameDecl *
argument_list|,
literal|4
argument|>&Decls
argument_list|)
name|override
block|;
comment|/// \brief Read the set of referenced selectors known to the
comment|/// external Sema source.
comment|///
comment|/// The external source should append its own referenced selectors to the
comment|/// given vector of selectors. Note that this routine
comment|/// may be invoked multiple times; the external source should take care not
comment|/// to introduce the same selectors repeatedly.
name|void
name|ReadReferencedSelectors
argument_list|(
argument|SmallVectorImpl<std::pair<Selector
argument_list|,
argument|SourceLocation>>&Sels
argument_list|)
name|override
block|;
comment|/// \brief Read the set of weak, undeclared identifiers known to the
comment|/// external Sema source.
comment|///
comment|/// The external source should append its own weak, undeclared identifiers to
comment|/// the given vector. Note that this routine may be invoked multiple times;
comment|/// the external source should take care not to introduce the same identifiers
comment|/// repeatedly.
name|void
name|ReadWeakUndeclaredIdentifiers
argument_list|(
argument|SmallVectorImpl<std::pair<IdentifierInfo*
argument_list|,
argument|WeakInfo>>&WI
argument_list|)
name|override
block|;
comment|/// \brief Read the set of used vtables known to the external Sema source.
comment|///
comment|/// The external source should append its own used vtables to the given
comment|/// vector. Note that this routine may be invoked multiple times; the external
comment|/// source should take care not to introduce the same vtables repeatedly.
name|void
name|ReadUsedVTables
argument_list|(
argument|SmallVectorImpl<ExternalVTableUse>&VTables
argument_list|)
name|override
block|;
comment|/// \brief Read the set of pending instantiations known to the external
comment|/// Sema source.
comment|///
comment|/// The external source should append its own pending instantiations to the
comment|/// given vector. Note that this routine may be invoked multiple times; the
comment|/// external source should take care not to introduce the same instantiations
comment|/// repeatedly.
name|void
name|ReadPendingInstantiations
argument_list|(
argument|SmallVectorImpl<std::pair<ValueDecl*
argument_list|,
argument|SourceLocation>>& Pending
argument_list|)
name|override
block|;
comment|/// \brief Read the set of late parsed template functions for this source.
comment|///
comment|/// The external source should insert its own late parsed template functions
comment|/// into the map. Note that this routine may be invoked multiple times; the
comment|/// external source should take care not to introduce the same map entries
comment|/// repeatedly.
name|void
name|ReadLateParsedTemplates
argument_list|(
argument|llvm::MapVector<const FunctionDecl *
argument_list|,
argument|std::unique_ptr<LateParsedTemplate>>&LPTMap
argument_list|)
name|override
block|;
comment|/// \copydoc ExternalSemaSource::CorrectTypo
comment|/// \note Returns the first nonempty correction.
name|TypoCorrection
name|CorrectTypo
argument_list|(
argument|const DeclarationNameInfo&Typo
argument_list|,
argument|int LookupKind
argument_list|,
argument|Scope *S
argument_list|,
argument|CXXScopeSpec *SS
argument_list|,
argument|CorrectionCandidateCallback&CCC
argument_list|,
argument|DeclContext *MemberContext
argument_list|,
argument|bool EnteringContext
argument_list|,
argument|const ObjCObjectPointerType *OPT
argument_list|)
name|override
block|;
comment|/// \brief Produces a diagnostic note if one of the attached sources
comment|/// contains a complete definition for \p T. Queries the sources in list
comment|/// order until the first one claims that a diagnostic was produced.
comment|///
comment|/// \param Loc the location at which a complete type was required but not
comment|/// provided
comment|///
comment|/// \param T the \c QualType that should have been complete at \p Loc
comment|///
comment|/// \return true if a diagnostic was produced, false otherwise.
name|bool
name|MaybeDiagnoseMissingCompleteType
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|QualType T
argument_list|)
name|override
block|;
comment|// isa/cast/dyn_cast support
specifier|static
name|bool
name|classof
argument_list|(
argument|const MultiplexExternalSemaSource*
argument_list|)
block|{
return|return
name|true
return|;
block|}
comment|//static bool classof(const ExternalSemaSource*) { return true; }
expr|}
block|;   }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

