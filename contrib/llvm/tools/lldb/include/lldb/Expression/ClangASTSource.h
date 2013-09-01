begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ClangASTSource.h ----------------------------------------*- C++ -*-===//
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
name|liblldb_ClangASTSource_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_ClangASTSource_h_
end_define

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|"clang/Basic/IdentifierTable.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/ClangExternalASTSourceCommon.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/ClangASTImporter.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/Target.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallSet.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|/// @class ClangASTSource ClangASTSource.h "lldb/Expression/ClangASTSource.h"
comment|/// @brief Provider for named objects defined in the debug info for Clang
comment|///
comment|/// As Clang parses an expression, it may encounter names that are not
comment|/// defined inside the expression, including variables, functions, and
comment|/// types.  Clang knows the name it is looking for, but nothing else.
comment|/// The ExternalSemaSource class provides Decls (VarDecl, FunDecl, TypeDecl)
comment|/// to Clang for these names, consulting the ClangExpressionDeclMap to do
comment|/// the actual lookups.
comment|//----------------------------------------------------------------------
name|class
name|ClangASTSource
range|:
name|public
name|ClangExternalASTSourceCommon
decl_stmt|,
name|public
name|ClangASTImporter
decl|::
name|MapCompleter
block|{
name|public
label|:
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|///
comment|/// Initializes class variables.
comment|///
comment|/// @param[in] declMap
comment|///     A reference to the LLDB object that handles entity lookup.
comment|//------------------------------------------------------------------
name|ClangASTSource
argument_list|(
specifier|const
name|lldb
operator|::
name|TargetSP
operator|&
name|target
argument_list|)
operator|:
name|m_import_in_progress
argument_list|(
name|false
argument_list|)
operator|,
name|m_lookups_enabled
argument_list|(
name|false
argument_list|)
operator|,
name|m_target
argument_list|(
name|target
argument_list|)
operator|,
name|m_ast_context
argument_list|(
name|NULL
argument_list|)
operator|,
name|m_active_lookups
argument_list|()
block|{
name|m_ast_importer
operator|=
name|m_target
operator|->
name|GetClangASTImporter
argument_list|()
block|;     }
comment|//------------------------------------------------------------------
comment|/// Destructor
comment|//------------------------------------------------------------------
operator|~
name|ClangASTSource
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Interface stubs.
comment|//------------------------------------------------------------------
name|clang
operator|::
name|Decl
operator|*
name|GetExternalDecl
argument_list|(
argument|uint32_t
argument_list|)
block|{
return|return
name|NULL
return|;
block|}
name|clang
operator|::
name|Stmt
operator|*
name|GetExternalDeclStmt
argument_list|(
argument|uint64_t
argument_list|)
block|{
return|return
name|NULL
return|;
block|}
name|clang
operator|::
name|Selector
name|GetExternalSelector
argument_list|(
argument|uint32_t
argument_list|)
block|{
return|return
name|clang
operator|::
name|Selector
argument_list|()
return|;
block|}
name|uint32_t
name|GetNumExternalSelectors
parameter_list|()
block|{
return|return
literal|0
return|;
block|}
name|clang
operator|::
name|CXXBaseSpecifier
operator|*
name|GetExternalCXXBaseSpecifiers
argument_list|(
argument|uint64_t Offset
argument_list|)
block|{
return|return
name|NULL
return|;
block|}
name|void
name|MaterializeVisibleDecls
argument_list|(
specifier|const
name|clang
operator|::
name|DeclContext
operator|*
name|DC
argument_list|)
block|{
return|return;
block|}
name|void
name|InstallASTContext
argument_list|(
name|clang
operator|::
name|ASTContext
operator|*
name|ast_context
argument_list|)
block|{
name|m_ast_context
operator|=
name|ast_context
expr_stmt|;
name|m_ast_importer
operator|->
name|InstallMapCompleter
argument_list|(
name|ast_context
argument_list|,
operator|*
name|this
argument_list|)
expr_stmt|;
block|}
comment|//
comment|// APIs for ExternalASTSource
comment|//
comment|//------------------------------------------------------------------
comment|/// Look up all Decls that match a particular name.  Only handles
comment|/// Identifiers and DeclContexts that are either NamespaceDecls or
comment|/// TranslationUnitDecls.  Calls SetExternalVisibleDeclsForName with
comment|/// the result.
comment|///
comment|/// The work for this function is done by
comment|/// void FindExternalVisibleDecls (NameSearchContext&);
comment|///
comment|/// @param[in] DC
comment|///     The DeclContext to register the found Decls in.
comment|///
comment|/// @param[in] Name
comment|///     The name to find entries for.
comment|///
comment|/// @return
comment|///     Whatever SetExternalVisibleDeclsForName returns.
comment|//------------------------------------------------------------------
name|bool
name|FindExternalVisibleDeclsByName
argument_list|(
specifier|const
name|clang
operator|::
name|DeclContext
operator|*
name|DC
argument_list|,
name|clang
operator|::
name|DeclarationName
name|Name
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Enumerate all Decls in a given lexical context.
comment|///
comment|/// @param[in] DC
comment|///     The DeclContext being searched.
comment|///
comment|/// @param[in] isKindWeWant
comment|///     If non-NULL, a callback function that returns true given the
comment|///     DeclKinds of desired Decls, and false otherwise.
comment|///
comment|/// @param[in] Decls
comment|///     A vector that is filled in with matching Decls.
comment|//------------------------------------------------------------------
name|clang
operator|::
name|ExternalLoadResult
name|FindExternalLexicalDecls
argument_list|(
specifier|const
name|clang
operator|::
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
name|clang
operator|::
name|Decl
operator|::
name|Kind
argument_list|)
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|clang
operator|::
name|Decl
operator|*
operator|>
operator|&
name|Decls
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Specify the layout of the contents of a RecordDecl.
comment|///
comment|/// @param[in] Record
comment|///     The record (in the parser's AST context) that needs to be
comment|///     laid out.
comment|///
comment|/// @param[out] Size
comment|///     The total size of the record in bits.
comment|///
comment|/// @param[out] Alignment
comment|///     The alignment of the record in bits.
comment|///
comment|/// @param[in] FieldOffsets
comment|///     A map that must be populated with pairs of the record's
comment|///     fields (in the parser's AST context) and their offsets
comment|///     (measured in bits).
comment|///
comment|/// @param[in] BaseOffsets
comment|///     A map that must be populated with pairs of the record's
comment|///     C++ concrete base classes (in the parser's AST context,
comment|///     and only if the record is a CXXRecordDecl and has base
comment|///     classes) and their offsets (measured in bytes).
comment|///
comment|/// @param[in] VirtualBaseOffsets
comment|///     A map that must be populated with pairs of the record's
comment|///     C++ virtual base classes (in the parser's AST context,
comment|///     and only if the record is a CXXRecordDecl and has base
comment|///     classes) and their offsets (measured in bytes).
comment|///
comment|/// @return
comment|///     True<=> the layout is valid.
comment|//-----------------------------------------------------------------
name|bool
name|layoutRecordType
argument_list|(
specifier|const
name|clang
operator|::
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
name|clang
operator|::
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
name|clang
operator|::
name|CXXRecordDecl
operator|*
argument_list|,
name|clang
operator|::
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
name|clang
operator|::
name|CXXRecordDecl
operator|*
argument_list|,
name|clang
operator|::
name|CharUnits
operator|>
operator|&
name|VirtualBaseOffsets
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Complete a TagDecl.
comment|///
comment|/// @param[in] Tag
comment|///     The Decl to be completed in place.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|CompleteType
argument_list|(
name|clang
operator|::
name|TagDecl
operator|*
name|Tag
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Complete an ObjCInterfaceDecl.
comment|///
comment|/// @param[in] Class
comment|///     The Decl to be completed in place.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|CompleteType
argument_list|(
name|clang
operator|::
name|ObjCInterfaceDecl
operator|*
name|Class
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Called on entering a translation unit.  Tells Clang by calling
comment|/// setHasExternalVisibleStorage() and setHasExternalLexicalStorage()
comment|/// that this object has something to say about undefined names.
comment|///
comment|/// @param[in] ASTConsumer
comment|///     Unused.
comment|//------------------------------------------------------------------
name|void
name|StartTranslationUnit
argument_list|(
name|clang
operator|::
name|ASTConsumer
operator|*
name|Consumer
argument_list|)
decl_stmt|;
comment|//
comment|// APIs for NamespaceMapCompleter
comment|//
comment|//------------------------------------------------------------------
comment|/// Look up the modules containing a given namespace and put the
comment|/// appropriate entries in the namespace map.
comment|///
comment|/// @param[in] namespace_map
comment|///     The map to be completed.
comment|///
comment|/// @param[in] name
comment|///     The name of the namespace to be found.
comment|///
comment|/// @param[in] parent_map
comment|///     The map for the namespace's parent namespace, if there is
comment|///     one.
comment|//------------------------------------------------------------------
name|void
name|CompleteNamespaceMap
argument_list|(
name|ClangASTImporter
operator|::
name|NamespaceMapSP
operator|&
name|namespace_map
argument_list|,
specifier|const
name|ConstString
operator|&
name|name
argument_list|,
name|ClangASTImporter
operator|::
name|NamespaceMapSP
operator|&
name|parent_map
argument_list|)
decl|const
decl_stmt|;
comment|//
comment|// Helper APIs
comment|//
name|clang
operator|::
name|NamespaceDecl
operator|*
name|AddNamespace
argument_list|(
name|NameSearchContext
operator|&
name|context
argument_list|,
name|ClangASTImporter
operator|::
name|NamespaceMapSP
operator|&
name|namespace_decls
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// The worker function for FindExternalVisibleDeclsByName.
comment|///
comment|/// @param[in] context
comment|///     The NameSearchContext to use when filing results.
comment|//------------------------------------------------------------------
name|virtual
name|void
name|FindExternalVisibleDecls
parameter_list|(
name|NameSearchContext
modifier|&
name|context
parameter_list|)
function_decl|;
name|void
name|SetImportInProgress
parameter_list|(
name|bool
name|import_in_progress
parameter_list|)
block|{
name|m_import_in_progress
operator|=
name|import_in_progress
expr_stmt|;
block|}
name|bool
name|GetImportInProgress
parameter_list|()
block|{
return|return
name|m_import_in_progress
return|;
block|}
name|void
name|SetLookupsEnabled
parameter_list|(
name|bool
name|lookups_enabled
parameter_list|)
block|{
name|m_lookups_enabled
operator|=
name|lookups_enabled
expr_stmt|;
block|}
name|bool
name|GetLookupsEnabled
parameter_list|()
block|{
return|return
name|m_lookups_enabled
return|;
block|}
comment|//----------------------------------------------------------------------
comment|/// @class ClangASTSourceProxy ClangASTSource.h "lldb/Expression/ClangASTSource.h"
comment|/// @brief Proxy for ClangASTSource
comment|///
comment|/// Clang AST contexts like to own their AST sources, so this is a
comment|/// state-free proxy object.
comment|//----------------------------------------------------------------------
name|class
name|ClangASTSourceProxy
range|:
name|public
name|ClangExternalASTSourceCommon
block|{
name|public
operator|:
name|ClangASTSourceProxy
argument_list|(
name|ClangASTSource
operator|&
name|original
argument_list|)
operator|:
name|m_original
argument_list|(
argument|original
argument_list|)
block|{         }
name|bool
name|FindExternalVisibleDeclsByName
argument_list|(
argument|const clang::DeclContext *DC
argument_list|,
argument|clang::DeclarationName Name
argument_list|)
block|{
return|return
name|m_original
operator|.
name|FindExternalVisibleDeclsByName
argument_list|(
name|DC
argument_list|,
name|Name
argument_list|)
return|;
block|}
name|clang
operator|::
name|ExternalLoadResult
name|FindExternalLexicalDecls
argument_list|(
argument|const clang::DeclContext *DC
argument_list|,
argument|bool (*isKindWeWant)(clang::Decl::Kind)
argument_list|,
argument|llvm::SmallVectorImpl<clang::Decl*>&Decls
argument_list|)
block|{
return|return
name|m_original
operator|.
name|FindExternalLexicalDecls
argument_list|(
name|DC
argument_list|,
name|isKindWeWant
argument_list|,
name|Decls
argument_list|)
return|;
block|}
name|void
name|CompleteType
argument_list|(
argument|clang::TagDecl *Tag
argument_list|)
block|{
return|return
name|m_original
operator|.
name|CompleteType
argument_list|(
name|Tag
argument_list|)
return|;
block|}
name|void
name|CompleteType
argument_list|(
argument|clang::ObjCInterfaceDecl *Class
argument_list|)
block|{
return|return
name|m_original
operator|.
name|CompleteType
argument_list|(
name|Class
argument_list|)
return|;
block|}
name|bool
name|layoutRecordType
argument_list|(
argument|const clang::RecordDecl *Record
argument_list|,
argument|uint64_t&Size
argument_list|,
argument|uint64_t&Alignment
argument_list|,
argument|llvm::DenseMap<const clang::FieldDecl *
argument_list|,
argument|uint64_t>&FieldOffsets
argument_list|,
argument|llvm::DenseMap<const clang::CXXRecordDecl *
argument_list|,
argument|clang::CharUnits>&BaseOffsets
argument_list|,
argument|llvm::DenseMap<const clang::CXXRecordDecl *
argument_list|,
argument|clang::CharUnits>&VirtualBaseOffsets
argument_list|)
block|{
return|return
name|m_original
operator|.
name|layoutRecordType
argument_list|(
name|Record
argument_list|,
name|Size
argument_list|,
name|Alignment
argument_list|,
name|FieldOffsets
argument_list|,
name|BaseOffsets
argument_list|,
name|VirtualBaseOffsets
argument_list|)
return|;
block|}
name|void
name|StartTranslationUnit
argument_list|(
argument|clang::ASTConsumer *Consumer
argument_list|)
block|{
return|return
name|m_original
operator|.
name|StartTranslationUnit
argument_list|(
name|Consumer
argument_list|)
return|;
block|}
name|ClangASTMetadata
operator|*
name|GetMetadata
argument_list|(
argument|const void * object
argument_list|)
block|{
return|return
name|m_original
operator|.
name|GetMetadata
argument_list|(
name|object
argument_list|)
return|;
block|}
name|void
name|SetMetadata
argument_list|(
argument|const void * object
argument_list|,
argument|ClangASTMetadata&metadata
argument_list|)
block|{
return|return
name|m_original
operator|.
name|SetMetadata
argument_list|(
name|object
argument_list|,
name|metadata
argument_list|)
return|;
block|}
name|bool
name|HasMetadata
argument_list|(
argument|const void * object
argument_list|)
block|{
return|return
name|m_original
operator|.
name|HasMetadata
argument_list|(
name|object
argument_list|)
return|;
block|}
name|private
operator|:
name|ClangASTSource
operator|&
name|m_original
block|;     }
decl_stmt|;
name|clang
operator|::
name|ExternalASTSource
operator|*
name|CreateProxy
argument_list|()
block|{
return|return
name|new
name|ClangASTSourceProxy
argument_list|(
operator|*
name|this
argument_list|)
return|;
block|}
name|protected
label|:
comment|//------------------------------------------------------------------
comment|/// Look for the complete version of an Objective-C interface, and
comment|/// return it if found.
comment|///
comment|/// @param[in] interface_decl
comment|///     An ObjCInterfaceDecl that may not be the complete one.
comment|///
comment|/// @return
comment|///     NULL if the complete interface couldn't be found;
comment|///     the complete interface otherwise.
comment|//------------------------------------------------------------------
name|clang
operator|::
name|ObjCInterfaceDecl
operator|*
name|GetCompleteObjCInterface
argument_list|(
name|clang
operator|::
name|ObjCInterfaceDecl
operator|*
name|interface_decl
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find all entities matching a given name in a given module,
comment|/// using a NameSearchContext to make Decls for them.
comment|///
comment|/// @param[in] context
comment|///     The NameSearchContext that can construct Decls for this name.
comment|///
comment|/// @param[in] module
comment|///     If non-NULL, the module to query.
comment|///
comment|/// @param[in] namespace_decl
comment|///     If valid and module is non-NULL, the parent namespace.
comment|///
comment|/// @param[in] current_id
comment|///     The ID for the current FindExternalVisibleDecls invocation,
comment|///     for logging purposes.
comment|///
comment|/// @return
comment|///     True on success; false otherwise.
comment|//------------------------------------------------------------------
name|void
name|FindExternalVisibleDecls
argument_list|(
name|NameSearchContext
operator|&
name|context
argument_list|,
name|lldb
operator|::
name|ModuleSP
name|module
argument_list|,
name|ClangNamespaceDecl
operator|&
name|namespace_decl
argument_list|,
name|unsigned
name|int
name|current_id
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Find all Objective-C methods matching a given selector.
comment|///
comment|/// @param[in] context
comment|///     The NameSearchContext that can construct Decls for this name.
comment|///     Its m_decl_name contains the selector and its m_decl_context
comment|///     is the containing object.
comment|//------------------------------------------------------------------
name|void
name|FindObjCMethodDecls
parameter_list|(
name|NameSearchContext
modifier|&
name|context
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// Find all Objective-C properties and ivars with a given name.
comment|///
comment|/// @param[in] context
comment|///     The NameSearchContext that can construct Decls for this name.
comment|///     Its m_decl_name contains the name and its m_decl_context
comment|///     is the containing object.
comment|//------------------------------------------------------------------
name|void
name|FindObjCPropertyAndIvarDecls
parameter_list|(
name|NameSearchContext
modifier|&
name|context
parameter_list|)
function_decl|;
comment|//------------------------------------------------------------------
comment|/// A wrapper for ClangASTContext::CopyType that sets a flag that
comment|/// indicates that we should not respond to queries during import.
comment|///
comment|/// @param[in] dest_context
comment|///     The target AST context, typically the parser's AST context.
comment|///
comment|/// @param[in] source_context
comment|///     The source AST context, typically the AST context of whatever
comment|///     symbol file the type was found in.
comment|///
comment|/// @param[in] clang_type
comment|///     The source type.
comment|///
comment|/// @return
comment|///     The imported type.
comment|//------------------------------------------------------------------
name|ClangASTType
name|GuardedCopyType
parameter_list|(
specifier|const
name|ClangASTType
modifier|&
name|src_type
parameter_list|)
function_decl|;
name|friend
struct_decl|struct
name|NameSearchContext
struct_decl|;
name|bool
name|m_import_in_progress
decl_stmt|;
name|bool
name|m_lookups_enabled
decl_stmt|;
specifier|const
name|lldb
operator|::
name|TargetSP
name|m_target
expr_stmt|;
comment|///< The target to use in finding variables and types.
name|clang
operator|::
name|ASTContext
operator|*
name|m_ast_context
expr_stmt|;
comment|///< The AST context requests are coming in for.
name|ClangASTImporter
modifier|*
name|m_ast_importer
decl_stmt|;
comment|///< The target's AST importer.
name|std
operator|::
name|set
operator|<
specifier|const
name|char
operator|*
operator|>
name|m_active_lookups
expr_stmt|;
block|}
empty_stmt|;
comment|//----------------------------------------------------------------------
comment|/// @class NameSearchContext ClangASTSource.h "lldb/Expression/ClangASTSource.h"
comment|/// @brief Container for all objects relevant to a single name lookup
comment|///
comment|/// LLDB needs to create Decls for entities it finds.  This class communicates
comment|/// what name is being searched for and provides helper functions to construct
comment|/// Decls given appropriate type information.
comment|//----------------------------------------------------------------------
struct|struct
name|NameSearchContext
block|{
name|ClangASTSource
modifier|&
name|m_ast_source
decl_stmt|;
comment|///< The AST source making the request
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|clang
operator|::
name|NamedDecl
operator|*
operator|>
operator|&
name|m_decls
expr_stmt|;
comment|///< The list of declarations already constructed
name|ClangASTImporter
operator|::
name|NamespaceMapSP
name|m_namespace_map
expr_stmt|;
comment|///< The mapping of all namespaces found for this request back to their modules
specifier|const
name|clang
operator|::
name|DeclarationName
operator|&
name|m_decl_name
expr_stmt|;
comment|///< The name being looked for
specifier|const
name|clang
operator|::
name|DeclContext
operator|*
name|m_decl_context
expr_stmt|;
comment|///< The DeclContext to put declarations into
name|llvm
operator|::
name|SmallSet
operator|<
name|ClangASTType
operator|,
literal|5
operator|>
name|m_function_types
expr_stmt|;
comment|///< All the types of functions that have been reported, so we don't report conflicts
struct|struct
block|{
name|bool
name|variable
range|:
literal|1
decl_stmt|;
name|bool
name|function_with_type_info
range|:
literal|1
decl_stmt|;
name|bool
name|function
range|:
literal|1
decl_stmt|;
block|}
name|m_found
struct|;
comment|//------------------------------------------------------------------
comment|/// Constructor
comment|///
comment|/// Initializes class variables.
comment|///
comment|/// @param[in] astSource
comment|///     A reference to the AST source making a request.
comment|///
comment|/// @param[in] decls
comment|///     A reference to a list into which new Decls will be placed.  This
comment|///     list is typically empty when the function is called.
comment|///
comment|/// @param[in] name
comment|///     The name being searched for (always an Identifier).
comment|///
comment|/// @param[in] dc
comment|///     The DeclContext to register Decls in.
comment|//------------------------------------------------------------------
name|NameSearchContext
argument_list|(
name|ClangASTSource
operator|&
name|astSource
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|clang
operator|::
name|NamedDecl
operator|*
operator|>
operator|&
name|decls
argument_list|,
name|clang
operator|::
name|DeclarationName
operator|&
name|name
argument_list|,
specifier|const
name|clang
operator|::
name|DeclContext
operator|*
name|dc
argument_list|)
operator|:
name|m_ast_source
argument_list|(
name|astSource
argument_list|)
operator|,
name|m_decls
argument_list|(
name|decls
argument_list|)
operator|,
name|m_decl_name
argument_list|(
name|name
argument_list|)
operator|,
name|m_decl_context
argument_list|(
argument|dc
argument_list|)
block|{
name|memset
argument_list|(
operator|&
name|m_found
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|m_found
argument_list|)
argument_list|)
block|;     }
comment|//------------------------------------------------------------------
comment|/// Create a VarDecl with the name being searched for and the provided
comment|/// type and register it in the right places.
comment|///
comment|/// @param[in] type
comment|///     The opaque QualType for the VarDecl being registered.
comment|//------------------------------------------------------------------
name|clang
operator|::
name|NamedDecl
operator|*
name|AddVarDecl
argument_list|(
specifier|const
name|ClangASTType
operator|&
name|type
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Create a FunDecl with the name being searched for and the provided
comment|/// type and register it in the right places.
comment|///
comment|/// @param[in] type
comment|///     The opaque QualType for the FunDecl being registered.
comment|//------------------------------------------------------------------
name|clang
operator|::
name|NamedDecl
operator|*
name|AddFunDecl
argument_list|(
specifier|const
name|ClangASTType
operator|&
name|type
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Create a FunDecl with the name being searched for and generic
comment|/// type (i.e. intptr_t NAME_GOES_HERE(...)) and register it in the
comment|/// right places.
comment|//------------------------------------------------------------------
name|clang
operator|::
name|NamedDecl
operator|*
name|AddGenericFunDecl
argument_list|()
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Create a TypeDecl with the name being searched for and the provided
comment|/// type and register it in the right places.
comment|///
comment|/// @param[in] type
comment|///     The opaque QualType for the TypeDecl being registered.
comment|//------------------------------------------------------------------
name|clang
operator|::
name|NamedDecl
operator|*
name|AddTypeDecl
argument_list|(
specifier|const
name|ClangASTType
operator|&
name|clang_type
argument_list|)
expr_stmt|;
comment|//------------------------------------------------------------------
comment|/// Add Decls from the provided DeclContextLookupResult to the list
comment|/// of results.
comment|///
comment|/// @param[in] result
comment|///     The DeclContextLookupResult, usually returned as the result
comment|///     of querying a DeclContext.
comment|//------------------------------------------------------------------
name|void
name|AddLookupResult
argument_list|(
name|clang
operator|::
name|DeclContextLookupConstResult
name|result
argument_list|)
decl_stmt|;
comment|//------------------------------------------------------------------
comment|/// Add a NamedDecl to the list of results.
comment|///
comment|/// @param[in] decl
comment|///     The NamedDecl, usually returned as the result
comment|///     of querying a DeclContext.
comment|//------------------------------------------------------------------
name|void
name|AddNamedDecl
argument_list|(
name|clang
operator|::
name|NamedDecl
operator|*
name|decl
argument_list|)
decl_stmt|;
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

