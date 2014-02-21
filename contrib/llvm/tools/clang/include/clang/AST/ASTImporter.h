begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ASTImporter.h - Importing ASTs from other Contexts -----*- C++ -*-===//
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
comment|//  This file defines the ASTImporter class which imports AST nodes from one
end_comment

begin_comment
comment|//  context into another context.
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
name|LLVM_CLANG_AST_ASTIMPORTER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_ASTIMPORTER_H
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
file|"clang/Basic/SourceLocation.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|DeclContext
decl_stmt|;
name|class
name|DiagnosticsEngine
decl_stmt|;
name|class
name|Expr
decl_stmt|;
name|class
name|FileManager
decl_stmt|;
name|class
name|IdentifierInfo
decl_stmt|;
name|class
name|NestedNameSpecifier
decl_stmt|;
name|class
name|Stmt
decl_stmt|;
name|class
name|TypeSourceInfo
decl_stmt|;
comment|/// \brief Imports selected nodes from one AST context into another context,
comment|/// merging AST nodes where appropriate.
name|class
name|ASTImporter
block|{
name|public
label|:
typedef|typedef
name|llvm
operator|::
name|DenseSet
operator|<
name|std
operator|::
name|pair
operator|<
name|Decl
operator|*
operator|,
name|Decl
operator|*
operator|>
expr|>
name|NonEquivalentDeclSet
expr_stmt|;
name|private
label|:
comment|/// \brief The contexts we're importing to and from.
name|ASTContext
modifier|&
name|ToContext
decl_stmt|,
modifier|&
name|FromContext
decl_stmt|;
comment|/// \brief The file managers we're importing to and from.
name|FileManager
modifier|&
name|ToFileManager
decl_stmt|,
modifier|&
name|FromFileManager
decl_stmt|;
comment|/// \brief Whether to perform a minimal import.
name|bool
name|Minimal
decl_stmt|;
comment|/// \brief Whether the last diagnostic came from the "from" context.
name|bool
name|LastDiagFromFrom
decl_stmt|;
comment|/// \brief Mapping from the already-imported types in the "from" context
comment|/// to the corresponding types in the "to" context.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Type
operator|*
operator|,
specifier|const
name|Type
operator|*
operator|>
name|ImportedTypes
expr_stmt|;
comment|/// \brief Mapping from the already-imported declarations in the "from"
comment|/// context to the corresponding declarations in the "to" context.
name|llvm
operator|::
name|DenseMap
operator|<
name|Decl
operator|*
operator|,
name|Decl
operator|*
operator|>
name|ImportedDecls
expr_stmt|;
comment|/// \brief Mapping from the already-imported statements in the "from"
comment|/// context to the corresponding statements in the "to" context.
name|llvm
operator|::
name|DenseMap
operator|<
name|Stmt
operator|*
operator|,
name|Stmt
operator|*
operator|>
name|ImportedStmts
expr_stmt|;
comment|/// \brief Mapping from the already-imported FileIDs in the "from" source
comment|/// manager to the corresponding FileIDs in the "to" source manager.
name|llvm
operator|::
name|DenseMap
operator|<
name|FileID
operator|,
name|FileID
operator|>
name|ImportedFileIDs
expr_stmt|;
comment|/// \brief Imported, anonymous tag declarations that are missing their
comment|/// corresponding typedefs.
name|SmallVector
operator|<
name|TagDecl
operator|*
operator|,
literal|4
operator|>
name|AnonTagsWithPendingTypedefs
expr_stmt|;
comment|/// \brief Declaration (from, to) pairs that are known not to be equivalent
comment|/// (which we have already complained about).
name|NonEquivalentDeclSet
name|NonEquivalentDecls
decl_stmt|;
name|public
label|:
comment|/// \brief Create a new AST importer.
comment|///
comment|/// \param ToContext The context we'll be importing into.
comment|///
comment|/// \param ToFileManager The file manager we'll be importing into.
comment|///
comment|/// \param FromContext The context we'll be importing from.
comment|///
comment|/// \param FromFileManager The file manager we'll be importing into.
comment|///
comment|/// \param MinimalImport If true, the importer will attempt to import
comment|/// as little as it can, e.g., by importing declarations as forward
comment|/// declarations that can be completed at a later point.
name|ASTImporter
argument_list|(
argument|ASTContext&ToContext
argument_list|,
argument|FileManager&ToFileManager
argument_list|,
argument|ASTContext&FromContext
argument_list|,
argument|FileManager&FromFileManager
argument_list|,
argument|bool MinimalImport
argument_list|)
empty_stmt|;
name|virtual
operator|~
name|ASTImporter
argument_list|()
expr_stmt|;
comment|/// \brief Whether the importer will perform a minimal import, creating
comment|/// to-be-completed forward declarations when possible.
name|bool
name|isMinimalImport
argument_list|()
specifier|const
block|{
return|return
name|Minimal
return|;
block|}
comment|/// \brief Import the given type from the "from" context into the "to"
comment|/// context.
comment|///
comment|/// \returns the equivalent type in the "to" context, or a NULL type if
comment|/// an error occurred.
name|QualType
name|Import
parameter_list|(
name|QualType
name|FromT
parameter_list|)
function_decl|;
comment|/// \brief Import the given type source information from the
comment|/// "from" context into the "to" context.
comment|///
comment|/// \returns the equivalent type source information in the "to"
comment|/// context, or NULL if an error occurred.
name|TypeSourceInfo
modifier|*
name|Import
parameter_list|(
name|TypeSourceInfo
modifier|*
name|FromTSI
parameter_list|)
function_decl|;
comment|/// \brief Import the given declaration from the "from" context into the
comment|/// "to" context.
comment|///
comment|/// \returns the equivalent declaration in the "to" context, or a NULL type
comment|/// if an error occurred.
name|Decl
modifier|*
name|Import
parameter_list|(
name|Decl
modifier|*
name|FromD
parameter_list|)
function_decl|;
comment|/// \brief Import the given declaration context from the "from"
comment|/// AST context into the "to" AST context.
comment|///
comment|/// \returns the equivalent declaration context in the "to"
comment|/// context, or a NULL type if an error occurred.
name|DeclContext
modifier|*
name|ImportContext
parameter_list|(
name|DeclContext
modifier|*
name|FromDC
parameter_list|)
function_decl|;
comment|/// \brief Import the given expression from the "from" context into the
comment|/// "to" context.
comment|///
comment|/// \returns the equivalent expression in the "to" context, or NULL if
comment|/// an error occurred.
name|Expr
modifier|*
name|Import
parameter_list|(
name|Expr
modifier|*
name|FromE
parameter_list|)
function_decl|;
comment|/// \brief Import the given statement from the "from" context into the
comment|/// "to" context.
comment|///
comment|/// \returns the equivalent statement in the "to" context, or NULL if
comment|/// an error occurred.
name|Stmt
modifier|*
name|Import
parameter_list|(
name|Stmt
modifier|*
name|FromS
parameter_list|)
function_decl|;
comment|/// \brief Import the given nested-name-specifier from the "from"
comment|/// context into the "to" context.
comment|///
comment|/// \returns the equivalent nested-name-specifier in the "to"
comment|/// context, or NULL if an error occurred.
name|NestedNameSpecifier
modifier|*
name|Import
parameter_list|(
name|NestedNameSpecifier
modifier|*
name|FromNNS
parameter_list|)
function_decl|;
comment|/// \brief Import the given nested-name-specifier from the "from"
comment|/// context into the "to" context.
comment|///
comment|/// \returns the equivalent nested-name-specifier in the "to"
comment|/// context.
name|NestedNameSpecifierLoc
name|Import
parameter_list|(
name|NestedNameSpecifierLoc
name|FromNNS
parameter_list|)
function_decl|;
comment|/// \brief Import the goven template name from the "from" context into the
comment|/// "to" context.
name|TemplateName
name|Import
parameter_list|(
name|TemplateName
name|From
parameter_list|)
function_decl|;
comment|/// \brief Import the given source location from the "from" context into
comment|/// the "to" context.
comment|///
comment|/// \returns the equivalent source location in the "to" context, or an
comment|/// invalid source location if an error occurred.
name|SourceLocation
name|Import
parameter_list|(
name|SourceLocation
name|FromLoc
parameter_list|)
function_decl|;
comment|/// \brief Import the given source range from the "from" context into
comment|/// the "to" context.
comment|///
comment|/// \returns the equivalent source range in the "to" context, or an
comment|/// invalid source location if an error occurred.
name|SourceRange
name|Import
parameter_list|(
name|SourceRange
name|FromRange
parameter_list|)
function_decl|;
comment|/// \brief Import the given declaration name from the "from"
comment|/// context into the "to" context.
comment|///
comment|/// \returns the equivalent declaration name in the "to" context,
comment|/// or an empty declaration name if an error occurred.
name|DeclarationName
name|Import
parameter_list|(
name|DeclarationName
name|FromName
parameter_list|)
function_decl|;
comment|/// \brief Import the given identifier from the "from" context
comment|/// into the "to" context.
comment|///
comment|/// \returns the equivalent identifier in the "to" context.
name|IdentifierInfo
modifier|*
name|Import
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|*
name|FromId
parameter_list|)
function_decl|;
comment|/// \brief Import the given Objective-C selector from the "from"
comment|/// context into the "to" context.
comment|///
comment|/// \returns the equivalent selector in the "to" context.
name|Selector
name|Import
parameter_list|(
name|Selector
name|FromSel
parameter_list|)
function_decl|;
comment|/// \brief Import the given file ID from the "from" context into the
comment|/// "to" context.
comment|///
comment|/// \returns the equivalent file ID in the source manager of the "to"
comment|/// context.
name|FileID
name|Import
parameter_list|(
name|FileID
parameter_list|)
function_decl|;
comment|/// \brief Import the definition of the given declaration, including all of
comment|/// the declarations it contains.
comment|///
comment|/// This routine is intended to be used
name|void
name|ImportDefinition
parameter_list|(
name|Decl
modifier|*
name|From
parameter_list|)
function_decl|;
comment|/// \brief Cope with a name conflict when importing a declaration into the
comment|/// given context.
comment|///
comment|/// This routine is invoked whenever there is a name conflict while
comment|/// importing a declaration. The returned name will become the name of the
comment|/// imported declaration. By default, the returned name is the same as the
comment|/// original name, leaving the conflict unresolve such that name lookup
comment|/// for this name is likely to find an ambiguity later.
comment|///
comment|/// Subclasses may override this routine to resolve the conflict, e.g., by
comment|/// renaming the declaration being imported.
comment|///
comment|/// \param Name the name of the declaration being imported, which conflicts
comment|/// with other declarations.
comment|///
comment|/// \param DC the declaration context (in the "to" AST context) in which
comment|/// the name is being imported.
comment|///
comment|/// \param IDNS the identifier namespace in which the name will be found.
comment|///
comment|/// \param Decls the set of declarations with the same name as the
comment|/// declaration being imported.
comment|///
comment|/// \param NumDecls the number of conflicting declarations in \p Decls.
comment|///
comment|/// \returns the name that the newly-imported declaration should have.
name|virtual
name|DeclarationName
name|HandleNameConflict
parameter_list|(
name|DeclarationName
name|Name
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|,
name|unsigned
name|IDNS
parameter_list|,
name|NamedDecl
modifier|*
modifier|*
name|Decls
parameter_list|,
name|unsigned
name|NumDecls
parameter_list|)
function_decl|;
comment|/// \brief Retrieve the context that AST nodes are being imported into.
name|ASTContext
operator|&
name|getToContext
argument_list|()
specifier|const
block|{
return|return
name|ToContext
return|;
block|}
comment|/// \brief Retrieve the context that AST nodes are being imported from.
name|ASTContext
operator|&
name|getFromContext
argument_list|()
specifier|const
block|{
return|return
name|FromContext
return|;
block|}
comment|/// \brief Retrieve the file manager that AST nodes are being imported into.
name|FileManager
operator|&
name|getToFileManager
argument_list|()
specifier|const
block|{
return|return
name|ToFileManager
return|;
block|}
comment|/// \brief Retrieve the file manager that AST nodes are being imported from.
name|FileManager
operator|&
name|getFromFileManager
argument_list|()
specifier|const
block|{
return|return
name|FromFileManager
return|;
block|}
comment|/// \brief Report a diagnostic in the "to" context.
name|DiagnosticBuilder
name|ToDiag
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
comment|/// \brief Report a diagnostic in the "from" context.
name|DiagnosticBuilder
name|FromDiag
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
comment|/// \brief Return the set of declarations that we know are not equivalent.
name|NonEquivalentDeclSet
modifier|&
name|getNonEquivalentDecls
parameter_list|()
block|{
return|return
name|NonEquivalentDecls
return|;
block|}
comment|/// \brief Called for ObjCInterfaceDecl, ObjCProtocolDecl, and TagDecl.
comment|/// Mark the Decl as complete, filling it in as much as possible.
comment|///
comment|/// \param D A declaration in the "to" context.
name|virtual
name|void
name|CompleteDecl
parameter_list|(
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
comment|/// \brief Note that we have imported the "from" declaration by mapping it
comment|/// to the (potentially-newly-created) "to" declaration.
comment|///
comment|/// Subclasses can override this function to observe all of the \c From ->
comment|/// \c To declaration mappings as they are imported.
name|virtual
name|Decl
modifier|*
name|Imported
parameter_list|(
name|Decl
modifier|*
name|From
parameter_list|,
name|Decl
modifier|*
name|To
parameter_list|)
function_decl|;
comment|/// \brief Called by StructuralEquivalenceContext.  If a RecordDecl is
comment|/// being compared to another RecordDecl as part of import, completing the
comment|/// other RecordDecl may trigger importation of the first RecordDecl. This
comment|/// happens especially for anonymous structs.  If the original of the second
comment|/// RecordDecl can be found, we can complete it without the need for
comment|/// importation, eliminating this loop.
name|virtual
name|Decl
modifier|*
name|GetOriginalDecl
parameter_list|(
name|Decl
modifier|*
name|To
parameter_list|)
block|{
return|return
name|NULL
return|;
block|}
comment|/// \brief Determine whether the given types are structurally
comment|/// equivalent.
name|bool
name|IsStructurallyEquivalent
parameter_list|(
name|QualType
name|From
parameter_list|,
name|QualType
name|To
parameter_list|,
name|bool
name|Complain
init|=
name|true
parameter_list|)
function_decl|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_AST_ASTIMPORTER_H
end_comment

end_unit

