begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ExternalSemaSource.h - External Sema Interface ---------*- C++ -*-===//
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
comment|//  This file defines the ExternalSemaSource interface.
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
name|LLVM_CLANG_SEMA_EXTERNAL_SEMA_SOURCE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_EXTERNAL_SEMA_SOURCE_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/ExternalASTSource.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/TypoCorrection.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/Weak.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/MapVector.h"
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
name|class
name|LookupResult
decl_stmt|;
struct_decl|struct
name|ObjCMethodList
struct_decl|;
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
struct_decl|struct
name|LateParsedTemplate
struct_decl|;
comment|/// \brief A simple structure that captures a vtable use for the purposes of
comment|/// the \c ExternalSemaSource.
struct|struct
name|ExternalVTableUse
block|{
name|CXXRecordDecl
modifier|*
name|Record
decl_stmt|;
name|SourceLocation
name|Location
decl_stmt|;
name|bool
name|DefinitionRequired
decl_stmt|;
block|}
struct|;
comment|/// \brief An abstract interface that should be implemented by
comment|/// external AST sources that also provide information for semantic
comment|/// analysis.
name|class
name|ExternalSemaSource
range|:
name|public
name|ExternalASTSource
block|{
name|public
operator|:
name|ExternalSemaSource
argument_list|()
block|{
name|ExternalASTSource
operator|::
name|SemaSource
operator|=
name|true
block|;   }
operator|~
name|ExternalSemaSource
argument_list|()
block|;
comment|/// \brief Initialize the semantic source with the Sema instance
comment|/// being used to perform semantic analysis on the abstract syntax
comment|/// tree.
name|virtual
name|void
name|InitializeSema
argument_list|(
argument|Sema&S
argument_list|)
block|{}
comment|/// \brief Inform the semantic consumer that Sema is no longer available.
name|virtual
name|void
name|ForgetSema
argument_list|()
block|{}
comment|/// \brief Load the contents of the global method pool for a given
comment|/// selector.
name|virtual
name|void
name|ReadMethodPool
argument_list|(
argument|Selector Sel
argument_list|)
block|;
comment|/// \brief Load the set of namespaces that are known to the external source,
comment|/// which will be used during typo correction.
name|virtual
name|void
name|ReadKnownNamespaces
argument_list|(
name|SmallVectorImpl
operator|<
name|NamespaceDecl
operator|*
operator|>
operator|&
name|Namespaces
argument_list|)
block|;
comment|/// \brief Load the set of used but not defined functions or variables with
comment|/// internal linkage, or used but not defined internal functions.
name|virtual
name|void
name|ReadUndefinedButUsed
argument_list|(
name|llvm
operator|::
name|DenseMap
operator|<
name|NamedDecl
operator|*
argument_list|,
name|SourceLocation
operator|>
operator|&
name|Undefined
argument_list|)
block|;
comment|/// \brief Do last resort, unqualified lookup on a LookupResult that
comment|/// Sema cannot find.
comment|///
comment|/// \param R a LookupResult that is being recovered.
comment|///
comment|/// \param S the Scope of the identifier occurrence.
comment|///
comment|/// \return true to tell Sema to recover using the LookupResult.
name|virtual
name|bool
name|LookupUnqualified
argument_list|(
argument|LookupResult&R
argument_list|,
argument|Scope *S
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Read the set of tentative definitions known to the external Sema
comment|/// source.
comment|///
comment|/// The external source should append its own tentative definitions to the
comment|/// given vector of tentative definitions. Note that this routine may be
comment|/// invoked multiple times; the external source should take care not to
comment|/// introduce the same declarations repeatedly.
name|virtual
name|void
name|ReadTentativeDefinitions
argument_list|(
argument|SmallVectorImpl<VarDecl *>&TentativeDefs
argument_list|)
block|{}
comment|/// \brief Read the set of unused file-scope declarations known to the
comment|/// external Sema source.
comment|///
comment|/// The external source should append its own unused, filed-scope to the
comment|/// given vector of declarations. Note that this routine may be
comment|/// invoked multiple times; the external source should take care not to
comment|/// introduce the same declarations repeatedly.
name|virtual
name|void
name|ReadUnusedFileScopedDecls
argument_list|(
argument|SmallVectorImpl<const DeclaratorDecl *>&Decls
argument_list|)
block|{}
comment|/// \brief Read the set of delegating constructors known to the
comment|/// external Sema source.
comment|///
comment|/// The external source should append its own delegating constructors to the
comment|/// given vector of declarations. Note that this routine may be
comment|/// invoked multiple times; the external source should take care not to
comment|/// introduce the same declarations repeatedly.
name|virtual
name|void
name|ReadDelegatingConstructors
argument_list|(
argument|SmallVectorImpl<CXXConstructorDecl *>&Decls
argument_list|)
block|{}
comment|/// \brief Read the set of ext_vector type declarations known to the
comment|/// external Sema source.
comment|///
comment|/// The external source should append its own ext_vector type declarations to
comment|/// the given vector of declarations. Note that this routine may be
comment|/// invoked multiple times; the external source should take care not to
comment|/// introduce the same declarations repeatedly.
name|virtual
name|void
name|ReadExtVectorDecls
argument_list|(
argument|SmallVectorImpl<TypedefNameDecl *>&Decls
argument_list|)
block|{}
comment|/// \brief Read the set of dynamic classes known to the external Sema source.
comment|///
comment|/// The external source should append its own dynamic classes to
comment|/// the given vector of declarations. Note that this routine may be
comment|/// invoked multiple times; the external source should take care not to
comment|/// introduce the same declarations repeatedly.
name|virtual
name|void
name|ReadDynamicClasses
argument_list|(
argument|SmallVectorImpl<CXXRecordDecl *>&Decls
argument_list|)
block|{}
comment|/// \brief Read the set of locally-scoped external declarations known to the
comment|/// external Sema source.
comment|///
comment|/// The external source should append its own locally-scoped external
comment|/// declarations to the given vector of declarations. Note that this routine
comment|/// may be invoked multiple times; the external source should take care not
comment|/// to introduce the same declarations repeatedly.
name|virtual
name|void
name|ReadLocallyScopedExternCDecls
argument_list|(
argument|SmallVectorImpl<NamedDecl *>&Decls
argument_list|)
block|{}
comment|/// \brief Read the set of referenced selectors known to the
comment|/// external Sema source.
comment|///
comment|/// The external source should append its own referenced selectors to the
comment|/// given vector of selectors. Note that this routine
comment|/// may be invoked multiple times; the external source should take care not
comment|/// to introduce the same selectors repeatedly.
name|virtual
name|void
name|ReadReferencedSelectors
argument_list|(
argument|SmallVectorImpl<std::pair<Selector
argument_list|,
argument|SourceLocation>>&Sels
argument_list|)
block|{}
comment|/// \brief Read the set of weak, undeclared identifiers known to the
comment|/// external Sema source.
comment|///
comment|/// The external source should append its own weak, undeclared identifiers to
comment|/// the given vector. Note that this routine may be invoked multiple times;
comment|/// the external source should take care not to introduce the same identifiers
comment|/// repeatedly.
name|virtual
name|void
name|ReadWeakUndeclaredIdentifiers
argument_list|(
argument|SmallVectorImpl<std::pair<IdentifierInfo *
argument_list|,
argument|WeakInfo>>&WI
argument_list|)
block|{}
comment|/// \brief Read the set of used vtables known to the external Sema source.
comment|///
comment|/// The external source should append its own used vtables to the given
comment|/// vector. Note that this routine may be invoked multiple times; the external
comment|/// source should take care not to introduce the same vtables repeatedly.
name|virtual
name|void
name|ReadUsedVTables
argument_list|(
argument|SmallVectorImpl<ExternalVTableUse>&VTables
argument_list|)
block|{}
comment|/// \brief Read the set of pending instantiations known to the external
comment|/// Sema source.
comment|///
comment|/// The external source should append its own pending instantiations to the
comment|/// given vector. Note that this routine may be invoked multiple times; the
comment|/// external source should take care not to introduce the same instantiations
comment|/// repeatedly.
name|virtual
name|void
name|ReadPendingInstantiations
argument_list|(
argument|SmallVectorImpl<std::pair<ValueDecl *
argument_list|,
argument|SourceLocation>>&Pending
argument_list|)
block|{}
comment|/// \brief Read the set of late parsed template functions for this source.
comment|///
comment|/// The external source should insert its own late parsed template functions
comment|/// into the map. Note that this routine may be invoked multiple times; the
comment|/// external source should take care not to introduce the same map entries
comment|/// repeatedly.
name|virtual
name|void
name|ReadLateParsedTemplates
argument_list|(
argument|llvm::DenseMap<const FunctionDecl *
argument_list|,
argument|LateParsedTemplate *>&LPTMap
argument_list|)
block|{}
comment|/// \copydoc Sema::CorrectTypo
comment|/// \note LookupKind must correspond to a valid Sema::LookupNameKind
comment|///
comment|/// ExternalSemaSource::CorrectTypo is always given the first chance to
comment|/// correct a typo (really, to offer suggestions to repair a failed lookup).
comment|/// It will even be called when SpellChecking is turned off or after a
comment|/// fatal error has already been detected.
name|virtual
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
block|{
return|return
name|TypoCorrection
argument_list|()
return|;
block|}
comment|/// \brief Produces a diagnostic note if the external source contains a
comment|/// complete definition for \p T.
comment|///
comment|/// \param Loc the location at which a complete type was required but not
comment|/// provided
comment|///
comment|/// \param T the \c QualType that should have been complete at \p Loc
comment|///
comment|/// \return true if a diagnostic was produced, false otherwise.
name|virtual
name|bool
name|MaybeDiagnoseMissingCompleteType
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|QualType T
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|// isa/cast/dyn_cast support
specifier|static
name|bool
name|classof
argument_list|(
argument|const ExternalASTSource *Source
argument_list|)
block|{
return|return
name|Source
operator|->
name|SemaSource
return|;
block|}
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

