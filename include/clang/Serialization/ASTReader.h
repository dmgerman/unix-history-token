begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ASTReader.h - AST File Reader --------------------------*- C++ -*-===//
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
comment|//  This file defines the ASTReader class, which reads AST files.
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
name|LLVM_CLANG_FRONTEND_AST_READER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_AST_READER_H
end_define

begin_include
include|#
directive|include
file|"clang/Serialization/ASTBitCodes.h"
end_include

begin_include
include|#
directive|include
file|"clang/Serialization/ContinuousRangeMap.h"
end_include

begin_include
include|#
directive|include
file|"clang/Serialization/Module.h"
end_include

begin_include
include|#
directive|include
file|"clang/Serialization/ModuleManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/ExternalSemaSource.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclarationName.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclObjC.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TemplateBase.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/ExternalPreprocessorSource.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/HeaderSearch.h"
end_include

begin_include
include|#
directive|include
file|"clang/Lex/PreprocessingRecord.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/Diagnostic.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/FileManager.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/FileSystemOptions.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/IdentifierTable.h"
end_include

begin_include
include|#
directive|include
file|"clang/Basic/SourceManager.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/APFloat.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/APInt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/APSInt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/OwningPtr.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Bitcode/BitstreamReader.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|<deque>
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<utility>
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
name|class
name|MemoryBuffer
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|AddrLabelExpr
decl_stmt|;
name|class
name|ASTConsumer
decl_stmt|;
name|class
name|ASTContext
decl_stmt|;
name|class
name|ASTIdentifierIterator
decl_stmt|;
name|class
name|ASTUnit
decl_stmt|;
comment|// FIXME: Layering violation and egregious hack.
name|class
name|Attr
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|DeclContext
decl_stmt|;
name|class
name|NestedNameSpecifier
decl_stmt|;
name|class
name|CXXBaseSpecifier
decl_stmt|;
name|class
name|CXXConstructorDecl
decl_stmt|;
name|class
name|CXXCtorInitializer
decl_stmt|;
name|class
name|GotoStmt
decl_stmt|;
name|class
name|MacroDefinition
decl_stmt|;
name|class
name|NamedDecl
decl_stmt|;
name|class
name|OpaqueValueExpr
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|Sema
decl_stmt|;
name|class
name|SwitchCase
decl_stmt|;
name|class
name|ASTDeserializationListener
decl_stmt|;
name|class
name|ASTWriter
decl_stmt|;
name|class
name|ASTReader
decl_stmt|;
name|class
name|ASTDeclReader
decl_stmt|;
name|class
name|ASTStmtReader
decl_stmt|;
name|class
name|TypeLocReader
decl_stmt|;
struct_decl|struct
name|HeaderFileInfo
struct_decl|;
name|class
name|VersionTuple
decl_stmt|;
struct|struct
name|PCHPredefinesBlock
block|{
comment|/// \brief The file ID for this predefines buffer in a PCH file.
name|FileID
name|BufferID
decl_stmt|;
comment|/// \brief This predefines buffer in a PCH file.
name|StringRef
name|Data
decl_stmt|;
block|}
struct|;
typedef|typedef
name|SmallVector
operator|<
name|PCHPredefinesBlock
operator|,
literal|2
operator|>
name|PCHPredefinesBlocks
expr_stmt|;
comment|/// \brief Abstract interface for callback invocations by the ASTReader.
comment|///
comment|/// While reading an AST file, the ASTReader will call the methods of the
comment|/// listener to pass on specific information. Some of the listener methods can
comment|/// return true to indicate to the ASTReader that the information (and
comment|/// consequently the AST file) is invalid.
name|class
name|ASTReaderListener
block|{
name|public
label|:
name|virtual
operator|~
name|ASTReaderListener
argument_list|()
expr_stmt|;
comment|/// \brief Receives the language options.
comment|///
comment|/// \returns true to indicate the options are invalid or false otherwise.
name|virtual
name|bool
name|ReadLanguageOptions
parameter_list|(
specifier|const
name|LangOptions
modifier|&
name|LangOpts
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Receives the target triple.
comment|///
comment|/// \returns true to indicate the target triple is invalid or false otherwise.
name|virtual
name|bool
name|ReadTargetTriple
parameter_list|(
name|StringRef
name|Triple
parameter_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Receives the contents of the predefines buffer.
comment|///
comment|/// \param Buffers Information about the predefines buffers.
comment|///
comment|/// \param OriginalFileName The original file name for the AST file, which
comment|/// will appear as an entry in the predefines buffer.
comment|///
comment|/// \param SuggestedPredefines If necessary, additional definitions are added
comment|/// here.
comment|///
comment|/// \returns true to indicate the predefines are invalid or false otherwise.
name|virtual
name|bool
name|ReadPredefinesBuffer
argument_list|(
specifier|const
name|PCHPredefinesBlocks
operator|&
name|Buffers
argument_list|,
name|StringRef
name|OriginalFileName
argument_list|,
name|std
operator|::
name|string
operator|&
name|SuggestedPredefines
argument_list|,
name|FileManager
operator|&
name|FileMgr
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Receives a HeaderFileInfo entry.
name|virtual
name|void
name|ReadHeaderFileInfo
parameter_list|(
specifier|const
name|HeaderFileInfo
modifier|&
name|HFI
parameter_list|,
name|unsigned
name|ID
parameter_list|)
block|{}
comment|/// \brief Receives __COUNTER__ value.
name|virtual
name|void
name|ReadCounter
parameter_list|(
name|unsigned
name|Value
parameter_list|)
block|{}
block|}
empty_stmt|;
comment|/// \brief ASTReaderListener implementation to validate the information of
comment|/// the PCH file against an initialized Preprocessor.
name|class
name|PCHValidator
range|:
name|public
name|ASTReaderListener
block|{
name|Preprocessor
operator|&
name|PP
block|;
name|ASTReader
operator|&
name|Reader
block|;
name|unsigned
name|NumHeaderInfos
block|;
name|public
operator|:
name|PCHValidator
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|,
name|ASTReader
operator|&
name|Reader
argument_list|)
operator|:
name|PP
argument_list|(
name|PP
argument_list|)
block|,
name|Reader
argument_list|(
name|Reader
argument_list|)
block|,
name|NumHeaderInfos
argument_list|(
literal|0
argument_list|)
block|{}
name|virtual
name|bool
name|ReadLanguageOptions
argument_list|(
specifier|const
name|LangOptions
operator|&
name|LangOpts
argument_list|)
block|;
name|virtual
name|bool
name|ReadTargetTriple
argument_list|(
argument|StringRef Triple
argument_list|)
block|;
name|virtual
name|bool
name|ReadPredefinesBuffer
argument_list|(
argument|const PCHPredefinesBlocks&Buffers
argument_list|,
argument|StringRef OriginalFileName
argument_list|,
argument|std::string&SuggestedPredefines
argument_list|,
argument|FileManager&FileMgr
argument_list|)
block|;
name|virtual
name|void
name|ReadHeaderFileInfo
argument_list|(
argument|const HeaderFileInfo&HFI
argument_list|,
argument|unsigned ID
argument_list|)
block|;
name|virtual
name|void
name|ReadCounter
argument_list|(
argument|unsigned Value
argument_list|)
block|;
name|private
operator|:
name|void
name|Error
argument_list|(
specifier|const
name|char
operator|*
name|Msg
argument_list|)
block|; }
decl_stmt|;
name|namespace
name|serialization
block|{
name|class
name|ReadMethodPoolVisitor
decl_stmt|;
name|namespace
name|reader
block|{
name|class
name|ASTIdentifierLookupTrait
decl_stmt|;
block|}
block|}
comment|// end namespace serialization
comment|/// \brief Reads an AST files chain containing the contents of a translation
comment|/// unit.
comment|///
comment|/// The ASTReader class reads bitstreams (produced by the ASTWriter
comment|/// class) containing the serialized representation of a given
comment|/// abstract syntax tree and its supporting data structures. An
comment|/// instance of the ASTReader can be attached to an ASTContext object,
comment|/// which will provide access to the contents of the AST files.
comment|///
comment|/// The AST reader provides lazy de-serialization of declarations, as
comment|/// required when traversing the AST. Only those AST nodes that are
comment|/// actually required will be de-serialized.
name|class
name|ASTReader
range|:
name|public
name|ExternalPreprocessorSource
decl_stmt|,
name|public
name|ExternalPreprocessingRecordSource
decl_stmt|,
name|public
name|ExternalHeaderFileInfoSource
decl_stmt|,
name|public
name|ExternalSemaSource
decl_stmt|,
name|public
name|IdentifierInfoLookup
decl_stmt|,
name|public
name|ExternalIdentifierLookup
decl_stmt|,
name|public
name|ExternalSLocEntrySource
block|{
name|public
label|:
enum|enum
name|ASTReadResult
block|{
name|Success
block|,
name|Failure
block|,
name|IgnorePCH
block|}
enum|;
comment|/// \brief Types of AST files.
name|friend
name|class
name|PCHValidator
decl_stmt|;
name|friend
name|class
name|ASTDeclReader
decl_stmt|;
name|friend
name|class
name|ASTStmtReader
decl_stmt|;
name|friend
name|class
name|ASTIdentifierIterator
decl_stmt|;
name|friend
name|class
name|serialization
operator|::
name|reader
operator|::
name|ASTIdentifierLookupTrait
expr_stmt|;
name|friend
name|class
name|TypeLocReader
decl_stmt|;
name|friend
name|class
name|ASTWriter
decl_stmt|;
name|friend
name|class
name|ASTUnit
decl_stmt|;
comment|// ASTUnit needs to remap source locations.
name|friend
name|class
name|serialization
operator|::
name|ReadMethodPoolVisitor
expr_stmt|;
typedef|typedef
name|serialization
operator|::
name|Module
name|Module
expr_stmt|;
typedef|typedef
name|serialization
operator|::
name|ModuleKind
name|ModuleKind
expr_stmt|;
typedef|typedef
name|serialization
operator|::
name|ModuleManager
name|ModuleManager
expr_stmt|;
typedef|typedef
name|ModuleManager
operator|::
name|ModuleIterator
name|ModuleIterator
expr_stmt|;
typedef|typedef
name|ModuleManager
operator|::
name|ModuleConstIterator
name|ModuleConstIterator
expr_stmt|;
typedef|typedef
name|ModuleManager
operator|::
name|ModuleReverseIterator
name|ModuleReverseIterator
expr_stmt|;
name|private
label|:
comment|/// \brief The receiver of some callbacks invoked by ASTReader.
name|llvm
operator|::
name|OwningPtr
operator|<
name|ASTReaderListener
operator|>
name|Listener
expr_stmt|;
comment|/// \brief The receiver of deserialization events.
name|ASTDeserializationListener
modifier|*
name|DeserializationListener
decl_stmt|;
name|SourceManager
modifier|&
name|SourceMgr
decl_stmt|;
name|FileManager
modifier|&
name|FileMgr
decl_stmt|;
name|DiagnosticsEngine
modifier|&
name|Diags
decl_stmt|;
comment|/// \brief The semantic analysis object that will be processing the
comment|/// AST files and the translation unit that uses it.
name|Sema
modifier|*
name|SemaObj
decl_stmt|;
comment|/// \brief The preprocessor that will be loading the source file.
name|Preprocessor
modifier|&
name|PP
decl_stmt|;
comment|/// \brief The AST context into which we'll read the AST files.
name|ASTContext
modifier|&
name|Context
decl_stmt|;
comment|/// \brief The AST consumer.
name|ASTConsumer
modifier|*
name|Consumer
decl_stmt|;
comment|/// \brief The module manager which manages modules and their dependencies
name|ModuleManager
name|ModuleMgr
decl_stmt|;
comment|/// \brief A map of global bit offsets to the module that stores entities
comment|/// at those bit offsets.
name|ContinuousRangeMap
operator|<
name|uint64_t
operator|,
name|Module
operator|*
operator|,
literal|4
operator|>
name|GlobalBitOffsetsMap
expr_stmt|;
comment|/// \brief A map of negated SLocEntryIDs to the modules containing them.
name|ContinuousRangeMap
operator|<
name|unsigned
operator|,
name|Module
operator|*
operator|,
literal|64
operator|>
name|GlobalSLocEntryMap
expr_stmt|;
typedef|typedef
name|ContinuousRangeMap
operator|<
name|unsigned
operator|,
name|Module
operator|*
operator|,
literal|64
operator|>
name|GlobalSLocOffsetMapType
expr_stmt|;
comment|/// \brief A map of reversed (SourceManager::MaxLoadedOffset - SLocOffset)
comment|/// SourceLocation offsets to the modules containing them.
name|GlobalSLocOffsetMapType
name|GlobalSLocOffsetMap
decl_stmt|;
comment|/// \brief Types that have already been loaded from the chain.
comment|///
comment|/// When the pointer at index I is non-NULL, the type with
comment|/// ID = (I + 1)<< FastQual::Width has already been loaded
name|std
operator|::
name|vector
operator|<
name|QualType
operator|>
name|TypesLoaded
expr_stmt|;
typedef|typedef
name|ContinuousRangeMap
operator|<
name|serialization
operator|::
name|TypeID
operator|,
name|Module
operator|*
operator|,
literal|4
operator|>
name|GlobalTypeMapType
expr_stmt|;
comment|/// \brief Mapping from global type IDs to the module in which the
comment|/// type resides along with the offset that should be added to the
comment|/// global type ID to produce a local ID.
name|GlobalTypeMapType
name|GlobalTypeMap
decl_stmt|;
comment|/// \brief Declarations that have already been loaded from the chain.
comment|///
comment|/// When the pointer at index I is non-NULL, the declaration with ID
comment|/// = I + 1 has already been loaded.
name|std
operator|::
name|vector
operator|<
name|Decl
operator|*
operator|>
name|DeclsLoaded
expr_stmt|;
typedef|typedef
name|ContinuousRangeMap
operator|<
name|serialization
operator|::
name|DeclID
operator|,
name|Module
operator|*
operator|,
literal|4
operator|>
name|GlobalDeclMapType
expr_stmt|;
comment|/// \brief Mapping from global declaration IDs to the module in which the
comment|/// declaration resides.
name|GlobalDeclMapType
name|GlobalDeclMap
decl_stmt|;
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|Module
operator|*
operator|,
name|uint64_t
operator|>
name|FileOffset
expr_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|FileOffset
operator|,
literal|2
operator|>
name|FileOffsetsTy
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|serialization
operator|::
name|DeclID
operator|,
name|FileOffsetsTy
operator|>
name|DeclUpdateOffsetsMap
expr_stmt|;
comment|/// \brief Declarations that have modifications residing in a later file
comment|/// in the chain.
name|DeclUpdateOffsetsMap
name|DeclUpdateOffsets
decl_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|serialization
operator|::
name|DeclID
operator|,
name|std
operator|::
name|pair
operator|<
name|Module
operator|*
operator|,
name|uint64_t
operator|>
expr|>
name|DeclReplacementMap
expr_stmt|;
comment|/// \brief Declarations that have been replaced in a later file in the chain.
name|DeclReplacementMap
name|ReplacedDecls
decl_stmt|;
comment|// Updates for visible decls can occur for other contexts than just the
comment|// TU, and when we read those update records, the actual context will not
comment|// be available yet (unless it's the TU), so have this pending map using the
comment|// ID as a key. It will be realized when the context is actually loaded.
typedef|typedef
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|void
operator|*
operator|,
name|Module
operator|*
operator|>
operator|,
literal|1
operator|>
name|DeclContextVisibleUpdates
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|serialization
operator|::
name|DeclID
operator|,
name|DeclContextVisibleUpdates
operator|>
name|DeclContextVisibleUpdatesPending
expr_stmt|;
comment|/// \brief Updates to the visible declarations of declaration contexts that
comment|/// haven't been loaded yet.
name|DeclContextVisibleUpdatesPending
name|PendingVisibleUpdates
decl_stmt|;
typedef|typedef
name|SmallVector
operator|<
name|CXXRecordDecl
operator|*
operator|,
literal|4
operator|>
name|ForwardRefs
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|CXXRecordDecl
operator|*
operator|,
name|ForwardRefs
operator|>
name|PendingForwardRefsMap
expr_stmt|;
comment|/// \brief Forward references that have a definition but the definition decl
comment|/// is still initializing. When the definition gets read it will update
comment|/// the DefinitionData pointer of all pending references.
name|PendingForwardRefsMap
name|PendingForwardRefs
decl_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|serialization
operator|::
name|DeclID
operator|,
name|serialization
operator|::
name|DeclID
operator|>
name|FirstLatestDeclIDMap
expr_stmt|;
comment|/// \brief Map of first declarations from a chained PCH that point to the
comment|/// most recent declarations in another AST file.
name|FirstLatestDeclIDMap
name|FirstLatestDeclIDs
decl_stmt|;
comment|/// \brief Set of ObjC interfaces that have categories chained to them in
comment|/// other modules.
name|llvm
operator|::
name|DenseSet
operator|<
name|serialization
operator|::
name|GlobalDeclID
operator|>
name|ObjCChainedCategoriesInterfaces
expr_stmt|;
comment|/// \brief Read the records that describe the contents of declcontexts.
name|bool
name|ReadDeclContextStorage
argument_list|(
name|Module
operator|&
name|M
argument_list|,
name|llvm
operator|::
name|BitstreamCursor
operator|&
name|Cursor
argument_list|,
specifier|const
name|std
operator|::
name|pair
operator|<
name|uint64_t
argument_list|,
name|uint64_t
operator|>
operator|&
name|Offsets
argument_list|,
name|serialization
operator|::
name|DeclContextInfo
operator|&
name|Info
argument_list|)
decl_stmt|;
comment|/// \brief A vector containing identifiers that have already been
comment|/// loaded.
comment|///
comment|/// If the pointer at index I is non-NULL, then it refers to the
comment|/// IdentifierInfo for the identifier with ID=I+1 that has already
comment|/// been loaded.
name|std
operator|::
name|vector
operator|<
name|IdentifierInfo
operator|*
operator|>
name|IdentifiersLoaded
expr_stmt|;
typedef|typedef
name|ContinuousRangeMap
operator|<
name|serialization
operator|::
name|IdentID
operator|,
name|Module
operator|*
operator|,
literal|4
operator|>
name|GlobalIdentifierMapType
expr_stmt|;
comment|/// \brief Mapping from global identifer IDs to the module in which the
comment|/// identifier resides along with the offset that should be added to the
comment|/// global identifier ID to produce a local ID.
name|GlobalIdentifierMapType
name|GlobalIdentifierMap
decl_stmt|;
comment|/// \brief A vector containing selectors that have already been loaded.
comment|///
comment|/// This vector is indexed by the Selector ID (-1). NULL selector
comment|/// entries indicate that the particular selector ID has not yet
comment|/// been loaded.
name|SmallVector
operator|<
name|Selector
operator|,
literal|16
operator|>
name|SelectorsLoaded
expr_stmt|;
typedef|typedef
name|ContinuousRangeMap
operator|<
name|serialization
operator|::
name|SelectorID
operator|,
name|Module
operator|*
operator|,
literal|4
operator|>
name|GlobalSelectorMapType
expr_stmt|;
comment|/// \brief Mapping from global selector IDs to the module in which the
comment|/// selector resides along with the offset that should be added to the
comment|/// global selector ID to produce a local ID.
name|GlobalSelectorMapType
name|GlobalSelectorMap
decl_stmt|;
comment|/// \brief Mapping from identifiers that represent macros whose definitions
comment|/// have not yet been deserialized to the global offset where the macro
comment|/// record resides.
name|llvm
operator|::
name|DenseMap
operator|<
name|IdentifierInfo
operator|*
operator|,
name|uint64_t
operator|>
name|UnreadMacroRecordOffsets
expr_stmt|;
typedef|typedef
name|ContinuousRangeMap
operator|<
name|unsigned
operator|,
name|Module
operator|*
operator|,
literal|4
operator|>
name|GlobalPreprocessedEntityMapType
expr_stmt|;
comment|/// \brief Mapping from global preprocessing entity IDs to the module in
comment|/// which the preprocessed entity resides along with the offset that should be
comment|/// added to the global preprocessing entitiy ID to produce a local ID.
name|GlobalPreprocessedEntityMapType
name|GlobalPreprocessedEntityMap
decl_stmt|;
comment|/// \name CodeGen-relevant special data
comment|/// \brief Fields containing data that is relevant to CodeGen.
comment|//@{
comment|/// \brief The IDs of all declarations that fulfill the criteria of
comment|/// "interesting" decls.
comment|///
comment|/// This contains the data loaded from all EXTERNAL_DEFINITIONS blocks in the
comment|/// chain. The referenced declarations are deserialized and passed to the
comment|/// consumer eagerly.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|16
operator|>
name|ExternalDefinitions
expr_stmt|;
comment|/// \brief The IDs of all tentative definitions stored in the the chain.
comment|///
comment|/// Sema keeps track of all tentative definitions in a TU because it has to
comment|/// complete them and pass them on to CodeGen. Thus, tentative definitions in
comment|/// the PCH chain must be eagerly deserialized.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|16
operator|>
name|TentativeDefinitions
expr_stmt|;
comment|/// \brief The IDs of all CXXRecordDecls stored in the chain whose VTables are
comment|/// used.
comment|///
comment|/// CodeGen has to emit VTables for these records, so they have to be eagerly
comment|/// deserialized.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|64
operator|>
name|VTableUses
expr_stmt|;
comment|/// \brief A snapshot of the pending instantiations in the chain.
comment|///
comment|/// This record tracks the instantiations that Sema has to perform at the
comment|/// end of the TU. It consists of a pair of values for every pending
comment|/// instantiation where the first value is the ID of the decl and the second
comment|/// is the instantiation location.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|64
operator|>
name|PendingInstantiations
expr_stmt|;
comment|//@}
comment|/// \name DiagnosticsEngine-relevant special data
comment|/// \brief Fields containing data that is used for generating diagnostics
comment|//@{
comment|/// \brief A snapshot of Sema's unused file-scoped variable tracking, for
comment|/// generating warnings.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|16
operator|>
name|UnusedFileScopedDecls
expr_stmt|;
comment|/// \brief A list of all the delegating constructors we've seen, to diagnose
comment|/// cycles.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|4
operator|>
name|DelegatingCtorDecls
expr_stmt|;
comment|/// \brief Method selectors used in a @selector expression. Used for
comment|/// implementation of -Wselector.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|64
operator|>
name|ReferencedSelectorsData
expr_stmt|;
comment|/// \brief A snapshot of Sema's weak undeclared identifier tracking, for
comment|/// generating warnings.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|64
operator|>
name|WeakUndeclaredIdentifiers
expr_stmt|;
comment|/// \brief The IDs of type aliases for ext_vectors that exist in the chain.
comment|///
comment|/// Used by Sema for finding sugared names for ext_vectors in diagnostics.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|4
operator|>
name|ExtVectorDecls
expr_stmt|;
comment|//@}
comment|/// \name Sema-relevant special data
comment|/// \brief Fields containing data that is used for semantic analysis
comment|//@{
comment|/// \brief The IDs of all locally scoped external decls in the chain.
comment|///
comment|/// Sema tracks these to validate that the types are consistent across all
comment|/// local external declarations.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|16
operator|>
name|LocallyScopedExternalDecls
expr_stmt|;
comment|/// \brief The IDs of all dynamic class declarations in the chain.
comment|///
comment|/// Sema tracks these because it checks for the key functions being defined
comment|/// at the end of the TU, in which case it directs CodeGen to emit the VTable.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|16
operator|>
name|DynamicClasses
expr_stmt|;
comment|/// \brief The IDs of the declarations Sema stores directly.
comment|///
comment|/// Sema tracks a few important decls, such as namespace std, directly.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|4
operator|>
name|SemaDeclRefs
expr_stmt|;
comment|/// \brief The IDs of the types ASTContext stores directly.
comment|///
comment|/// The AST context tracks a few important types, such as va_list, directly.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|16
operator|>
name|SpecialTypes
expr_stmt|;
comment|/// \brief The IDs of CUDA-specific declarations ASTContext stores directly.
comment|///
comment|/// The AST context tracks a few important decls, currently cudaConfigureCall,
comment|/// directly.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|2
operator|>
name|CUDASpecialDeclRefs
expr_stmt|;
comment|/// \brief The floating point pragma option settings.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|1
operator|>
name|FPPragmaOptions
expr_stmt|;
comment|/// \brief The OpenCL extension settings.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|1
operator|>
name|OpenCLExtensions
expr_stmt|;
comment|/// \brief A list of the namespaces we've seen.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|4
operator|>
name|KnownNamespaces
expr_stmt|;
comment|//@}
comment|/// \brief The original file name that was used to build the primary AST file,
comment|/// which may have been modified for relocatable-pch support.
name|std
operator|::
name|string
name|OriginalFileName
expr_stmt|;
comment|/// \brief The actual original file name that was used to build the primary
comment|/// AST file.
name|std
operator|::
name|string
name|ActualOriginalFileName
expr_stmt|;
comment|/// \brief The file ID for the original file that was used to build the
comment|/// primary AST file.
name|FileID
name|OriginalFileID
decl_stmt|;
comment|/// \brief The directory that the PCH was originally created in. Used to
comment|/// allow resolving headers even after headers+PCH was moved to a new path.
name|std
operator|::
name|string
name|OriginalDir
expr_stmt|;
comment|/// \brief The directory that the PCH we are reading is stored in.
name|std
operator|::
name|string
name|CurrentDir
expr_stmt|;
comment|/// \brief Whether this precompiled header is a relocatable PCH file.
name|bool
name|RelocatablePCH
decl_stmt|;
comment|/// \brief The system include root to be used when loading the
comment|/// precompiled header.
name|std
operator|::
name|string
name|isysroot
expr_stmt|;
comment|/// \brief Whether to disable the normal validation performed on precompiled
comment|/// headers when they are loaded.
name|bool
name|DisableValidation
decl_stmt|;
comment|/// \brief Whether to disable the use of stat caches in AST files.
name|bool
name|DisableStatCache
decl_stmt|;
comment|/// \brief Mapping from switch-case IDs in the chain to switch-case statements
comment|///
comment|/// Statements usually don't have IDs, but switch cases need them, so that the
comment|/// switch statement can refer to them.
name|std
operator|::
name|map
operator|<
name|unsigned
operator|,
name|SwitchCase
operator|*
operator|>
name|SwitchCaseStmts
expr_stmt|;
comment|/// \brief Mapping from opaque value IDs to OpaqueValueExprs.
name|std
operator|::
name|map
operator|<
name|unsigned
operator|,
name|OpaqueValueExpr
operator|*
operator|>
name|OpaqueValueExprs
expr_stmt|;
comment|/// \brief The number of stat() calls that hit/missed the stat
comment|/// cache.
name|unsigned
name|NumStatHits
decl_stmt|,
name|NumStatMisses
decl_stmt|;
comment|/// \brief The number of source location entries de-serialized from
comment|/// the PCH file.
name|unsigned
name|NumSLocEntriesRead
decl_stmt|;
comment|/// \brief The number of source location entries in the chain.
name|unsigned
name|TotalNumSLocEntries
decl_stmt|;
comment|/// \brief The number of statements (and expressions) de-serialized
comment|/// from the chain.
name|unsigned
name|NumStatementsRead
decl_stmt|;
comment|/// \brief The total number of statements (and expressions) stored
comment|/// in the chain.
name|unsigned
name|TotalNumStatements
decl_stmt|;
comment|/// \brief The number of macros de-serialized from the chain.
name|unsigned
name|NumMacrosRead
decl_stmt|;
comment|/// \brief The total number of macros stored in the chain.
name|unsigned
name|TotalNumMacros
decl_stmt|;
comment|/// \brief The number of selectors that have been read.
name|unsigned
name|NumSelectorsRead
decl_stmt|;
comment|/// \brief The number of method pool entries that have been read.
name|unsigned
name|NumMethodPoolEntriesRead
decl_stmt|;
comment|/// \brief The number of times we have looked up a selector in the method
comment|/// pool and not found anything interesting.
name|unsigned
name|NumMethodPoolMisses
decl_stmt|;
comment|/// \brief The total number of method pool entries in the selector table.
name|unsigned
name|TotalNumMethodPoolEntries
decl_stmt|;
comment|/// Number of lexical decl contexts read/total.
name|unsigned
name|NumLexicalDeclContextsRead
decl_stmt|,
name|TotalLexicalDeclContexts
decl_stmt|;
comment|/// Number of visible decl contexts read/total.
name|unsigned
name|NumVisibleDeclContextsRead
decl_stmt|,
name|TotalVisibleDeclContexts
decl_stmt|;
comment|/// Total size of modules, in bits, currently loaded
name|uint64_t
name|TotalModulesSizeInBits
decl_stmt|;
comment|/// \brief Number of Decl/types that are currently deserializing.
name|unsigned
name|NumCurrentElementsDeserializing
decl_stmt|;
comment|/// Number of CXX base specifiers currently loaded
name|unsigned
name|NumCXXBaseSpecifiersLoaded
decl_stmt|;
comment|/// \brief An IdentifierInfo that has been loaded but whose top-level
comment|/// declarations of the same name have not (yet) been loaded.
struct|struct
name|PendingIdentifierInfo
block|{
name|IdentifierInfo
modifier|*
name|II
decl_stmt|;
name|SmallVector
operator|<
name|uint32_t
operator|,
literal|4
operator|>
name|DeclIDs
expr_stmt|;
block|}
struct|;
comment|/// \brief The set of identifiers that were read while the AST reader was
comment|/// (recursively) loading declarations.
comment|///
comment|/// The declarations on the identifier chain for these identifiers will be
comment|/// loaded once the recursive loading has completed.
name|std
operator|::
name|deque
operator|<
name|PendingIdentifierInfo
operator|>
name|PendingIdentifierInfos
expr_stmt|;
comment|/// \brief Contains declarations and definitions that will be
comment|/// "interesting" to the ASTConsumer, when we get that AST consumer.
comment|///
comment|/// "Interesting" declarations are those that have data that may
comment|/// need to be emitted, such as inline function definitions or
comment|/// Objective-C protocols.
name|std
operator|::
name|deque
operator|<
name|Decl
operator|*
operator|>
name|InterestingDecls
expr_stmt|;
comment|/// \brief We delay loading of the previous declaration chain to avoid
comment|/// deeply nested calls when there are many redeclarations.
name|std
operator|::
name|deque
operator|<
name|std
operator|::
name|pair
operator|<
name|Decl
operator|*
operator|,
name|serialization
operator|::
name|DeclID
operator|>
expr|>
name|PendingPreviousDecls
expr_stmt|;
comment|/// \brief Ready to load the previous declaration of the given Decl.
name|void
name|loadAndAttachPreviousDecl
argument_list|(
name|Decl
operator|*
name|D
argument_list|,
name|serialization
operator|::
name|DeclID
name|ID
argument_list|)
decl_stmt|;
comment|/// \brief When reading a Stmt tree, Stmt operands are placed in this stack.
name|SmallVector
operator|<
name|Stmt
operator|*
operator|,
literal|16
operator|>
name|StmtStack
expr_stmt|;
comment|/// \brief What kind of records we are reading.
enum|enum
name|ReadingKind
block|{
name|Read_Decl
block|,
name|Read_Type
block|,
name|Read_Stmt
block|}
enum|;
comment|/// \brief What kind of records we are reading.
name|ReadingKind
name|ReadingKind
decl_stmt|;
comment|/// \brief RAII object to change the reading kind.
name|class
name|ReadingKindTracker
block|{
name|ASTReader
modifier|&
name|Reader
decl_stmt|;
name|enum
name|ReadingKind
name|PrevKind
decl_stmt|;
name|ReadingKindTracker
argument_list|(
specifier|const
name|ReadingKindTracker
operator|&
argument_list|)
expr_stmt|;
comment|// do not implement
name|ReadingKindTracker
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ReadingKindTracker
operator|&
operator|)
decl_stmt|;
comment|// do not implement
name|public
label|:
name|ReadingKindTracker
argument_list|(
argument|enum ReadingKind newKind
argument_list|,
argument|ASTReader&reader
argument_list|)
block|:
name|Reader
argument_list|(
name|reader
argument_list|)
operator|,
name|PrevKind
argument_list|(
argument|Reader.ReadingKind
argument_list|)
block|{
name|Reader
operator|.
name|ReadingKind
operator|=
name|newKind
block|;     }
operator|~
name|ReadingKindTracker
argument_list|()
block|{
name|Reader
operator|.
name|ReadingKind
operator|=
name|PrevKind
block|; }
block|}
empty_stmt|;
comment|/// \brief All predefines buffers in the chain, to be treated as if
comment|/// concatenated.
name|PCHPredefinesBlocks
name|PCHPredefinesBuffers
decl_stmt|;
comment|/// \brief Suggested contents of the predefines buffer, after this
comment|/// PCH file has been processed.
comment|///
comment|/// In most cases, this string will be empty, because the predefines
comment|/// buffer computed to build the PCH file will be identical to the
comment|/// predefines buffer computed from the command line. However, when
comment|/// there are differences that the PCH reader can work around, this
comment|/// predefines buffer may contain additional definitions.
name|std
operator|::
name|string
name|SuggestedPredefines
expr_stmt|;
comment|/// \brief Reads a statement from the specified cursor.
name|Stmt
modifier|*
name|ReadStmtFromStream
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|)
function_decl|;
comment|/// \brief Get a FileEntry out of stored-in-PCH filename, making sure we take
comment|/// into account all the necessary relocations.
specifier|const
name|FileEntry
modifier|*
name|getFileEntry
parameter_list|(
name|StringRef
name|filename
parameter_list|)
function_decl|;
name|void
name|MaybeAddSystemRootToFilename
argument_list|(
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|)
decl_stmt|;
name|ASTReadResult
name|ReadASTCore
parameter_list|(
name|StringRef
name|FileName
parameter_list|,
name|ModuleKind
name|Type
parameter_list|,
name|Module
modifier|*
name|ImportedBy
parameter_list|)
function_decl|;
name|ASTReadResult
name|ReadASTBlock
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|)
function_decl|;
name|bool
name|CheckPredefinesBuffers
parameter_list|()
function_decl|;
name|bool
name|ParseLineTable
argument_list|(
name|Module
operator|&
name|F
argument_list|,
name|SmallVectorImpl
operator|<
name|uint64_t
operator|>
operator|&
name|Record
argument_list|)
decl_stmt|;
name|ASTReadResult
name|ReadSourceManagerBlock
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|)
function_decl|;
name|ASTReadResult
name|ReadSLocEntryRecord
parameter_list|(
name|int
name|ID
parameter_list|)
function_decl|;
name|llvm
operator|::
name|BitstreamCursor
operator|&
name|SLocCursorForID
argument_list|(
argument|int ID
argument_list|)
expr_stmt|;
name|SourceLocation
name|getImportLocation
parameter_list|(
name|Module
modifier|*
name|F
parameter_list|)
function_decl|;
name|bool
name|ParseLanguageOptions
argument_list|(
specifier|const
name|SmallVectorImpl
operator|<
name|uint64_t
operator|>
operator|&
name|Record
argument_list|)
decl_stmt|;
struct|struct
name|RecordLocation
block|{
name|RecordLocation
argument_list|(
argument|Module *M
argument_list|,
argument|uint64_t O
argument_list|)
block|:
name|F
argument_list|(
name|M
argument_list|)
operator|,
name|Offset
argument_list|(
argument|O
argument_list|)
block|{}
name|Module
operator|*
name|F
expr_stmt|;
name|uint64_t
name|Offset
decl_stmt|;
block|}
struct|;
name|QualType
name|readTypeRecord
parameter_list|(
name|unsigned
name|Index
parameter_list|)
function_decl|;
name|RecordLocation
name|TypeCursorForIndex
parameter_list|(
name|unsigned
name|Index
parameter_list|)
function_decl|;
name|void
name|LoadedDecl
parameter_list|(
name|unsigned
name|Index
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
name|Decl
modifier|*
name|ReadDeclRecord
argument_list|(
name|serialization
operator|::
name|DeclID
name|ID
argument_list|)
decl_stmt|;
name|RecordLocation
name|DeclCursorForID
argument_list|(
name|serialization
operator|::
name|DeclID
name|ID
argument_list|)
decl_stmt|;
name|void
name|loadDeclUpdateRecords
argument_list|(
name|serialization
operator|::
name|DeclID
name|ID
argument_list|,
name|Decl
operator|*
name|D
argument_list|)
decl_stmt|;
name|void
name|loadObjCChainedCategories
argument_list|(
name|serialization
operator|::
name|GlobalDeclID
name|ID
argument_list|,
name|ObjCInterfaceDecl
operator|*
name|D
argument_list|)
decl_stmt|;
name|RecordLocation
name|getLocalBitOffset
parameter_list|(
name|uint64_t
name|GlobalOffset
parameter_list|)
function_decl|;
name|uint64_t
name|getGlobalBitOffset
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|,
name|uint32_t
name|LocalOffset
parameter_list|)
function_decl|;
comment|/// \brief Returns the first preprocessed entity ID that ends after \arg BLoc.
name|serialization
operator|::
name|PreprocessedEntityID
name|findBeginPreprocessedEntity
argument_list|(
argument|SourceLocation BLoc
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Returns the first preprocessed entity ID that begins after \arg ELoc.
name|serialization
operator|::
name|PreprocessedEntityID
name|findEndPreprocessedEntity
argument_list|(
argument|SourceLocation ELoc
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief \arg SLocMapI points at a chunk of a module that contains no
comment|/// preprocessed entities or the entities it contains are not the ones we are
comment|/// looking for. Find the next module that contains entities and return the ID
comment|/// of the first entry.
name|serialization
operator|::
name|PreprocessedEntityID
name|findNextPreprocessedEntity
argument_list|(
argument|GlobalSLocOffsetMapType::const_iterator SLocMapI
argument_list|)
specifier|const
expr_stmt|;
name|void
name|PassInterestingDeclsToConsumer
parameter_list|()
function_decl|;
comment|/// \brief Produce an error diagnostic and return true.
comment|///
comment|/// This routine should only be used for fatal errors that have to
comment|/// do with non-routine failures (e.g., corrupted AST file).
name|void
name|Error
parameter_list|(
name|StringRef
name|Msg
parameter_list|)
function_decl|;
name|void
name|Error
parameter_list|(
name|unsigned
name|DiagID
parameter_list|,
name|StringRef
name|Arg1
init|=
name|StringRef
argument_list|()
parameter_list|,
name|StringRef
name|Arg2
init|=
name|StringRef
argument_list|()
parameter_list|)
function_decl|;
name|ASTReader
argument_list|(
specifier|const
name|ASTReader
operator|&
argument_list|)
expr_stmt|;
comment|// do not implement
name|ASTReader
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ASTReader
operator|&
operator|)
decl_stmt|;
comment|// do not implement
name|public
label|:
typedef|typedef
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|64
operator|>
name|RecordData
expr_stmt|;
comment|/// \brief Load the AST file and validate its contents against the given
comment|/// Preprocessor.
comment|///
comment|/// \param PP the preprocessor associated with the context in which this
comment|/// precompiled header will be loaded.
comment|///
comment|/// \param Context the AST context that this precompiled header will be
comment|/// loaded into.
comment|///
comment|/// \param isysroot If non-NULL, the system include path specified by the
comment|/// user. This is only used with relocatable PCH files. If non-NULL,
comment|/// a relocatable PCH file will use the default path "/".
comment|///
comment|/// \param DisableValidation If true, the AST reader will suppress most
comment|/// of its regular consistency checking, allowing the use of precompiled
comment|/// headers that cannot be determined to be compatible.
comment|///
comment|/// \param DisableStatCache If true, the AST reader will ignore the
comment|/// stat cache in the AST files. This performance pessimization can
comment|/// help when an AST file is being used in cases where the
comment|/// underlying files in the file system may have changed, but
comment|/// parsing should still continue.
name|ASTReader
argument_list|(
argument|Preprocessor&PP
argument_list|,
argument|ASTContext&Context
argument_list|,
argument|StringRef isysroot =
literal|""
argument_list|,
argument|bool DisableValidation = false
argument_list|,
argument|bool DisableStatCache = false
argument_list|)
empty_stmt|;
operator|~
name|ASTReader
argument_list|()
expr_stmt|;
name|SourceManager
operator|&
name|getSourceManager
argument_list|()
specifier|const
block|{
return|return
name|SourceMgr
return|;
block|}
comment|/// \brief Load the AST file designated by the given file name.
name|ASTReadResult
name|ReadAST
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|FileName
argument_list|,
name|ModuleKind
name|Type
argument_list|)
decl_stmt|;
comment|/// \brief Checks that no file that is stored in PCH is out-of-sync with
comment|/// the actual file in the file system.
name|ASTReadResult
name|validateFileEntries
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|)
function_decl|;
comment|/// \brief Set the AST callbacks listener.
name|void
name|setListener
parameter_list|(
name|ASTReaderListener
modifier|*
name|listener
parameter_list|)
block|{
name|Listener
operator|.
name|reset
argument_list|(
name|listener
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Set the AST deserialization listener.
name|void
name|setDeserializationListener
parameter_list|(
name|ASTDeserializationListener
modifier|*
name|Listener
parameter_list|)
function_decl|;
comment|/// \brief Initializes the ASTContext
name|void
name|InitializeContext
parameter_list|()
function_decl|;
comment|/// \brief Add in-memory (virtual file) buffer.
name|void
name|addInMemoryBuffer
argument_list|(
name|StringRef
operator|&
name|FileName
argument_list|,
name|llvm
operator|::
name|MemoryBuffer
operator|*
name|Buffer
argument_list|)
block|{
name|ModuleMgr
operator|.
name|addInMemoryBuffer
argument_list|(
name|FileName
argument_list|,
name|Buffer
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Retrieve the module manager.
name|ModuleManager
modifier|&
name|getModuleManager
parameter_list|()
block|{
return|return
name|ModuleMgr
return|;
block|}
comment|/// \brief Retrieve the preprocessor.
name|Preprocessor
operator|&
name|getPreprocessor
argument_list|()
specifier|const
block|{
return|return
name|PP
return|;
block|}
comment|/// \brief Retrieve the name of the original source file name
specifier|const
name|std
operator|::
name|string
operator|&
name|getOriginalSourceFile
argument_list|()
block|{
return|return
name|OriginalFileName
return|;
block|}
comment|/// \brief Retrieve the name of the original source file name directly from
comment|/// the AST file, without actually loading the AST file.
specifier|static
name|std
operator|::
name|string
name|getOriginalSourceFile
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|ASTFileName
argument_list|,
name|FileManager
operator|&
name|FileMgr
argument_list|,
name|DiagnosticsEngine
operator|&
name|Diags
argument_list|)
expr_stmt|;
comment|/// \brief Returns the suggested contents of the predefines buffer,
comment|/// which contains a (typically-empty) subset of the predefines
comment|/// build prior to including the precompiled header.
specifier|const
name|std
operator|::
name|string
operator|&
name|getSuggestedPredefines
argument_list|()
block|{
return|return
name|SuggestedPredefines
return|;
block|}
comment|/// \brief Read a preallocated preprocessed entity from the external source.
comment|///
comment|/// \returns null if an error occurred that prevented the preprocessed
comment|/// entity from being loaded.
name|virtual
name|PreprocessedEntity
modifier|*
name|ReadPreprocessedEntity
parameter_list|(
name|unsigned
name|Index
parameter_list|)
function_decl|;
comment|/// \brief Returns a pair of [Begin, End) indices of preallocated
comment|/// preprocessed entities that \arg Range encompasses.
name|virtual
name|std
operator|::
name|pair
operator|<
name|unsigned
operator|,
name|unsigned
operator|>
name|findPreprocessedEntitiesInRange
argument_list|(
argument|SourceRange Range
argument_list|)
expr_stmt|;
comment|/// \brief Read the header file information for the given file entry.
name|virtual
name|HeaderFileInfo
name|GetHeaderFileInfo
parameter_list|(
specifier|const
name|FileEntry
modifier|*
name|FE
parameter_list|)
function_decl|;
name|void
name|ReadPragmaDiagnosticMappings
parameter_list|(
name|DiagnosticsEngine
modifier|&
name|Diag
parameter_list|)
function_decl|;
comment|/// \brief Returns the number of source locations found in the chain.
name|unsigned
name|getTotalNumSLocs
argument_list|()
specifier|const
block|{
return|return
name|TotalNumSLocEntries
return|;
block|}
comment|/// \brief Returns the number of identifiers found in the chain.
name|unsigned
name|getTotalNumIdentifiers
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|IdentifiersLoaded
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Returns the number of types found in the chain.
name|unsigned
name|getTotalNumTypes
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|TypesLoaded
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Returns the number of declarations found in the chain.
name|unsigned
name|getTotalNumDecls
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|DeclsLoaded
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Returns the number of selectors found in the chain.
name|unsigned
name|getTotalNumSelectors
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|SelectorsLoaded
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Returns the number of preprocessed entities known to the AST
comment|/// reader.
name|unsigned
name|getTotalNumPreprocessedEntities
argument_list|()
specifier|const
block|{
name|unsigned
name|Result
operator|=
literal|0
block|;
for|for
control|(
name|ModuleConstIterator
name|I
init|=
name|ModuleMgr
operator|.
name|begin
argument_list|()
init|,
name|E
init|=
name|ModuleMgr
operator|.
name|end
argument_list|()
init|;
name|I
operator|!=
name|E
condition|;
operator|++
name|I
control|)
block|{
name|Result
operator|+=
operator|(
operator|*
name|I
operator|)
operator|->
name|NumPreprocessedEntities
expr_stmt|;
block|}
return|return
name|Result
return|;
block|}
comment|/// \brief Returns the number of C++ base specifiers found in the chain.
name|unsigned
name|getTotalNumCXXBaseSpecifiers
argument_list|()
specifier|const
block|{
return|return
name|NumCXXBaseSpecifiersLoaded
return|;
block|}
comment|/// \brief Reads a TemplateArgumentLocInfo appropriate for the
comment|/// given TemplateArgument kind.
name|TemplateArgumentLocInfo
name|GetTemplateArgumentLocInfo
argument_list|(
name|Module
operator|&
name|F
argument_list|,
name|TemplateArgument
operator|::
name|ArgKind
name|Kind
argument_list|,
specifier|const
name|RecordData
operator|&
name|Record
argument_list|,
name|unsigned
operator|&
name|Idx
argument_list|)
decl_stmt|;
comment|/// \brief Reads a TemplateArgumentLoc.
name|TemplateArgumentLoc
name|ReadTemplateArgumentLoc
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
comment|/// \brief Reads a declarator info from the given record.
name|TypeSourceInfo
modifier|*
name|GetTypeSourceInfo
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
comment|/// \brief Resolve a type ID into a type, potentially building a new
comment|/// type.
name|QualType
name|GetType
argument_list|(
name|serialization
operator|::
name|TypeID
name|ID
argument_list|)
decl_stmt|;
comment|/// \brief Resolve a local type ID within a given AST file into a type.
name|QualType
name|getLocalType
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
name|unsigned
name|LocalID
parameter_list|)
function_decl|;
comment|/// \brief Map a local type ID within a given AST file into a global type ID.
name|serialization
operator|::
name|TypeID
name|getGlobalTypeID
argument_list|(
argument|Module&F
argument_list|,
argument|unsigned LocalID
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Read a type from the current position in the given record, which
comment|/// was read from the given AST file.
name|QualType
name|readType
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
block|{
if|if
condition|(
name|Idx
operator|>=
name|Record
operator|.
name|size
argument_list|()
condition|)
return|return
name|QualType
argument_list|()
return|;
return|return
name|getLocalType
argument_list|(
name|F
argument_list|,
name|Record
index|[
name|Idx
operator|++
index|]
argument_list|)
return|;
block|}
comment|/// \brief Map from a local declaration ID within a given module to a
comment|/// global declaration ID.
name|serialization
operator|::
name|DeclID
name|getGlobalDeclID
argument_list|(
argument|Module&F
argument_list|,
argument|unsigned LocalID
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Returns true if global DeclID \arg ID originated from module
comment|/// \arg M.
name|bool
name|isDeclIDFromModule
argument_list|(
name|serialization
operator|::
name|GlobalDeclID
name|ID
argument_list|,
name|Module
operator|&
name|M
argument_list|)
decl|const
decl_stmt|;
comment|/// \brief Resolve a declaration ID into a declaration, potentially
comment|/// building a new declaration.
name|Decl
modifier|*
name|GetDecl
argument_list|(
name|serialization
operator|::
name|DeclID
name|ID
argument_list|)
decl_stmt|;
name|virtual
name|Decl
modifier|*
name|GetExternalDecl
parameter_list|(
name|uint32_t
name|ID
parameter_list|)
function_decl|;
comment|/// \brief Reads a declaration with the given local ID in the given module.
name|Decl
modifier|*
name|GetLocalDecl
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
name|uint32_t
name|LocalID
parameter_list|)
block|{
return|return
name|GetDecl
argument_list|(
name|getGlobalDeclID
argument_list|(
name|F
argument_list|,
name|LocalID
argument_list|)
argument_list|)
return|;
block|}
comment|/// \brief Reads a declaration with the given local ID in the given module.
comment|///
comment|/// \returns The requested declaration, casted to the given return type.
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|GetLocalDeclAs
argument_list|(
argument|Module&F
argument_list|,
argument|uint32_t LocalID
argument_list|)
block|{
return|return
name|cast_or_null
operator|<
name|T
operator|>
operator|(
name|GetLocalDecl
argument_list|(
name|F
argument_list|,
name|LocalID
argument_list|)
operator|)
return|;
block|}
comment|/// \brief Reads a declaration ID from the given position in a record in the
comment|/// given module.
comment|///
comment|/// \returns The declaration ID read from the record, adjusted to a global ID.
name|serialization
operator|::
name|DeclID
name|ReadDeclID
argument_list|(
name|Module
operator|&
name|F
argument_list|,
specifier|const
name|RecordData
operator|&
name|Record
argument_list|,
name|unsigned
operator|&
name|Idx
argument_list|)
expr_stmt|;
comment|/// \brief Reads a declaration from the given position in a record in the
comment|/// given module.
name|Decl
modifier|*
name|ReadDecl
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|R
parameter_list|,
name|unsigned
modifier|&
name|I
parameter_list|)
block|{
return|return
name|GetDecl
argument_list|(
name|ReadDeclID
argument_list|(
name|F
argument_list|,
name|R
argument_list|,
name|I
argument_list|)
argument_list|)
return|;
block|}
comment|/// \brief Reads a declaration from the given position in a record in the
comment|/// given module.
comment|///
comment|/// \returns The declaration read from this location, casted to the given
comment|/// result type.
name|template
operator|<
name|typename
name|T
operator|>
name|T
operator|*
name|ReadDeclAs
argument_list|(
argument|Module&F
argument_list|,
argument|const RecordData&R
argument_list|,
argument|unsigned&I
argument_list|)
block|{
return|return
name|cast_or_null
operator|<
name|T
operator|>
operator|(
name|GetDecl
argument_list|(
name|ReadDeclID
argument_list|(
name|F
argument_list|,
name|R
argument_list|,
name|I
argument_list|)
argument_list|)
operator|)
return|;
block|}
comment|/// \brief Read a CXXBaseSpecifiers ID form the given record and
comment|/// return its global bit offset.
name|uint64_t
name|readCXXBaseSpecifiers
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
name|virtual
name|CXXBaseSpecifier
modifier|*
name|GetExternalCXXBaseSpecifiers
parameter_list|(
name|uint64_t
name|Offset
parameter_list|)
function_decl|;
comment|/// \brief Resolve the offset of a statement into a statement.
comment|///
comment|/// This operation will read a new statement from the external
comment|/// source each time it is called, and is meant to be used via a
comment|/// LazyOffsetPtr (which is used by Decls for the body of functions, etc).
name|virtual
name|Stmt
modifier|*
name|GetExternalDeclStmt
parameter_list|(
name|uint64_t
name|Offset
parameter_list|)
function_decl|;
comment|/// ReadBlockAbbrevs - Enter a subblock of the specified BlockID with the
comment|/// specified cursor.  Read the abbreviations that are at the top of the block
comment|/// and then leave the cursor pointing into the block.
name|bool
name|ReadBlockAbbrevs
argument_list|(
name|llvm
operator|::
name|BitstreamCursor
operator|&
name|Cursor
argument_list|,
name|unsigned
name|BlockID
argument_list|)
decl_stmt|;
comment|/// \brief Finds all the visible declarations with a given name.
comment|/// The current implementation of this method just loads the entire
comment|/// lookup table as unmaterialized references.
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
expr_stmt|;
comment|/// \brief Read all of the declarations lexically stored in a
comment|/// declaration context.
comment|///
comment|/// \param DC The declaration context whose declarations will be
comment|/// read.
comment|///
comment|/// \param Decls Vector that will contain the declarations loaded
comment|/// from the external source. The caller is responsible for merging
comment|/// these declarations with any declarations already stored in the
comment|/// declaration context.
comment|///
comment|/// \returns true if there was an error while reading the
comment|/// declarations for this declaration context.
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
name|Decls
argument_list|)
decl_stmt|;
comment|/// \brief Notify ASTReader that we started deserialization of
comment|/// a decl or type so until FinishedDeserializing is called there may be
comment|/// decls that are initializing. Must be paired with FinishedDeserializing.
name|virtual
name|void
name|StartedDeserializing
parameter_list|()
block|{
operator|++
name|NumCurrentElementsDeserializing
expr_stmt|;
block|}
comment|/// \brief Notify ASTReader that we finished the deserialization of
comment|/// a decl or type. Must be paired with StartedDeserializing.
name|virtual
name|void
name|FinishedDeserializing
parameter_list|()
function_decl|;
comment|/// \brief Function that will be invoked when we begin parsing a new
comment|/// translation unit involving this external AST source.
comment|///
comment|/// This function will provide all of the external definitions to
comment|/// the ASTConsumer.
name|virtual
name|void
name|StartTranslationUnit
parameter_list|(
name|ASTConsumer
modifier|*
name|Consumer
parameter_list|)
function_decl|;
comment|/// \brief Print some statistics about AST usage.
name|virtual
name|void
name|PrintStats
parameter_list|()
function_decl|;
comment|/// \brief Dump information about the AST reader to standard error.
name|void
name|dump
parameter_list|()
function_decl|;
comment|/// Return the amount of memory used by memory buffers, breaking down
comment|/// by heap-backed versus mmap'ed memory.
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
comment|/// \brief Initialize the semantic source with the Sema instance
comment|/// being used to perform semantic analysis on the abstract syntax
comment|/// tree.
name|virtual
name|void
name|InitializeSema
parameter_list|(
name|Sema
modifier|&
name|S
parameter_list|)
function_decl|;
comment|/// \brief Inform the semantic consumer that Sema is no longer available.
name|virtual
name|void
name|ForgetSema
parameter_list|()
block|{
name|SemaObj
operator|=
literal|0
expr_stmt|;
block|}
comment|/// \brief Retrieve the IdentifierInfo for the named identifier.
comment|///
comment|/// This routine builds a new IdentifierInfo for the given identifier. If any
comment|/// declarations with this name are visible from translation unit scope, their
comment|/// declarations will be deserialized and introduced into the declaration
comment|/// chain of the identifier.
name|virtual
name|IdentifierInfo
modifier|*
name|get
parameter_list|(
specifier|const
name|char
modifier|*
name|NameStart
parameter_list|,
specifier|const
name|char
modifier|*
name|NameEnd
parameter_list|)
function_decl|;
name|IdentifierInfo
modifier|*
name|get
parameter_list|(
name|StringRef
name|Name
parameter_list|)
block|{
return|return
name|get
argument_list|(
name|Name
operator|.
name|begin
argument_list|()
argument_list|,
name|Name
operator|.
name|end
argument_list|()
argument_list|)
return|;
block|}
comment|/// \brief Retrieve an iterator into the set of all identifiers
comment|/// in all loaded AST files.
name|virtual
name|IdentifierIterator
operator|*
name|getIdentifiers
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Load the contents of the global method pool for a given
comment|/// selector.
comment|///
comment|/// \returns a pair of Objective-C methods lists containing the
comment|/// instance and factory methods, respectively, with this selector.
name|virtual
name|std
operator|::
name|pair
operator|<
name|ObjCMethodList
operator|,
name|ObjCMethodList
operator|>
name|ReadMethodPool
argument_list|(
argument|Selector Sel
argument_list|)
expr_stmt|;
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
decl_stmt|;
name|virtual
name|void
name|ReadTentativeDefinitions
argument_list|(
name|SmallVectorImpl
operator|<
name|VarDecl
operator|*
operator|>
operator|&
name|TentativeDefs
argument_list|)
decl_stmt|;
name|virtual
name|void
name|ReadUnusedFileScopedDecls
argument_list|(
name|SmallVectorImpl
operator|<
specifier|const
name|DeclaratorDecl
operator|*
operator|>
operator|&
name|Decls
argument_list|)
decl_stmt|;
name|virtual
name|void
name|ReadDelegatingConstructors
argument_list|(
name|SmallVectorImpl
operator|<
name|CXXConstructorDecl
operator|*
operator|>
operator|&
name|Decls
argument_list|)
decl_stmt|;
name|virtual
name|void
name|ReadExtVectorDecls
argument_list|(
name|SmallVectorImpl
operator|<
name|TypedefNameDecl
operator|*
operator|>
operator|&
name|Decls
argument_list|)
decl_stmt|;
name|virtual
name|void
name|ReadDynamicClasses
argument_list|(
name|SmallVectorImpl
operator|<
name|CXXRecordDecl
operator|*
operator|>
operator|&
name|Decls
argument_list|)
decl_stmt|;
name|virtual
name|void
name|ReadLocallyScopedExternalDecls
argument_list|(
name|SmallVectorImpl
operator|<
name|NamedDecl
operator|*
operator|>
operator|&
name|Decls
argument_list|)
decl_stmt|;
name|virtual
name|void
name|ReadReferencedSelectors
argument_list|(
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|Selector
argument_list|,
name|SourceLocation
operator|>
expr|>
operator|&
name|Sels
argument_list|)
decl_stmt|;
name|virtual
name|void
name|ReadWeakUndeclaredIdentifiers
argument_list|(
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|IdentifierInfo
operator|*
argument_list|,
name|WeakInfo
operator|>
expr|>
operator|&
name|WI
argument_list|)
decl_stmt|;
name|virtual
name|void
name|ReadUsedVTables
argument_list|(
name|SmallVectorImpl
operator|<
name|ExternalVTableUse
operator|>
operator|&
name|VTables
argument_list|)
decl_stmt|;
name|virtual
name|void
name|ReadPendingInstantiations
argument_list|(
name|SmallVectorImpl
operator|<
name|std
operator|::
name|pair
operator|<
name|ValueDecl
operator|*
argument_list|,
name|SourceLocation
operator|>
expr|>
operator|&
name|Pending
argument_list|)
decl_stmt|;
comment|/// \brief Load a selector from disk, registering its ID if it exists.
name|void
name|LoadSelector
parameter_list|(
name|Selector
name|Sel
parameter_list|)
function_decl|;
name|void
name|SetIdentifierInfo
parameter_list|(
name|unsigned
name|ID
parameter_list|,
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
function_decl|;
name|void
name|SetGloballyVisibleDecls
argument_list|(
name|IdentifierInfo
operator|*
name|II
argument_list|,
specifier|const
name|SmallVectorImpl
operator|<
name|uint32_t
operator|>
operator|&
name|DeclIDs
argument_list|,
name|bool
name|Nonrecursive
operator|=
name|false
argument_list|)
decl_stmt|;
comment|/// \brief Report a diagnostic.
name|DiagnosticBuilder
name|Diag
parameter_list|(
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
comment|/// \brief Report a diagnostic.
name|DiagnosticBuilder
name|Diag
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|unsigned
name|DiagID
parameter_list|)
function_decl|;
name|IdentifierInfo
modifier|*
name|DecodeIdentifierInfo
argument_list|(
name|serialization
operator|::
name|IdentifierID
name|ID
argument_list|)
decl_stmt|;
name|IdentifierInfo
modifier|*
name|GetIdentifierInfo
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
block|{
return|return
name|DecodeIdentifierInfo
argument_list|(
name|getGlobalIdentifierID
argument_list|(
name|M
argument_list|,
name|Record
index|[
name|Idx
operator|++
index|]
argument_list|)
argument_list|)
return|;
block|}
name|virtual
name|IdentifierInfo
modifier|*
name|GetIdentifier
argument_list|(
name|serialization
operator|::
name|IdentifierID
name|ID
argument_list|)
block|{
return|return
name|DecodeIdentifierInfo
argument_list|(
name|ID
argument_list|)
return|;
block|}
name|IdentifierInfo
modifier|*
name|getLocalIdentifier
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|,
name|unsigned
name|LocalID
parameter_list|)
function_decl|;
name|serialization
operator|::
name|IdentifierID
name|getGlobalIdentifierID
argument_list|(
argument|Module&M
argument_list|,
argument|unsigned LocalID
argument_list|)
expr_stmt|;
comment|/// \brief Read the source location entry with index ID.
name|virtual
name|bool
name|ReadSLocEntry
parameter_list|(
name|int
name|ID
parameter_list|)
function_decl|;
comment|/// \brief Retrieve a selector from the given module with its local ID
comment|/// number.
name|Selector
name|getLocalSelector
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|,
name|unsigned
name|LocalID
parameter_list|)
function_decl|;
name|Selector
name|DecodeSelector
argument_list|(
name|serialization
operator|::
name|SelectorID
name|Idx
argument_list|)
decl_stmt|;
name|virtual
name|Selector
name|GetExternalSelector
argument_list|(
name|serialization
operator|::
name|SelectorID
name|ID
argument_list|)
decl_stmt|;
name|uint32_t
name|GetNumExternalSelectors
parameter_list|()
function_decl|;
name|Selector
name|ReadSelector
parameter_list|(
name|Module
modifier|&
name|M
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
block|{
return|return
name|getLocalSelector
argument_list|(
name|M
argument_list|,
name|Record
index|[
name|Idx
operator|++
index|]
argument_list|)
return|;
block|}
comment|/// \brief Retrieve the global selector ID that corresponds to this
comment|/// the local selector ID in a given module.
name|serialization
operator|::
name|SelectorID
name|getGlobalSelectorID
argument_list|(
argument|Module&F
argument_list|,
argument|unsigned LocalID
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Read a declaration name.
name|DeclarationName
name|ReadDeclarationName
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
name|void
name|ReadDeclarationNameLoc
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
name|DeclarationNameLoc
modifier|&
name|DNLoc
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
name|void
name|ReadDeclarationNameInfo
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
name|DeclarationNameInfo
modifier|&
name|NameInfo
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
name|void
name|ReadQualifierInfo
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
name|QualifierInfo
modifier|&
name|Info
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
name|NestedNameSpecifier
modifier|*
name|ReadNestedNameSpecifier
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
name|NestedNameSpecifierLoc
name|ReadNestedNameSpecifierLoc
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
comment|/// \brief Read a template name.
name|TemplateName
name|ReadTemplateName
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
comment|/// \brief Read a template argument.
name|TemplateArgument
name|ReadTemplateArgument
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
comment|/// \brief Read a template parameter list.
name|TemplateParameterList
modifier|*
name|ReadTemplateParameterList
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
comment|/// \brief Read a template argument array.
name|void
name|ReadTemplateArgumentList
argument_list|(
name|SmallVector
operator|<
name|TemplateArgument
argument_list|,
literal|8
operator|>
operator|&
name|TemplArgs
argument_list|,
name|Module
operator|&
name|F
argument_list|,
specifier|const
name|RecordData
operator|&
name|Record
argument_list|,
name|unsigned
operator|&
name|Idx
argument_list|)
decl_stmt|;
comment|/// \brief Read a UnresolvedSet structure.
name|void
name|ReadUnresolvedSet
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
name|UnresolvedSetImpl
modifier|&
name|Set
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
comment|/// \brief Read a C++ base specifier.
name|CXXBaseSpecifier
name|ReadCXXBaseSpecifier
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
comment|/// \brief Read a CXXCtorInitializer array.
name|std
operator|::
name|pair
operator|<
name|CXXCtorInitializer
operator|*
operator|*
operator|,
name|unsigned
operator|>
name|ReadCXXCtorInitializers
argument_list|(
name|Module
operator|&
name|F
argument_list|,
specifier|const
name|RecordData
operator|&
name|Record
argument_list|,
name|unsigned
operator|&
name|Idx
argument_list|)
expr_stmt|;
comment|/// \brief Read a source location from raw form.
name|SourceLocation
name|ReadSourceLocation
argument_list|(
name|Module
operator|&
name|Module
argument_list|,
name|unsigned
name|Raw
argument_list|)
decl|const
block|{
name|SourceLocation
name|Loc
init|=
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|Raw
argument_list|)
decl_stmt|;
name|assert
argument_list|(
name|Module
operator|.
name|SLocRemap
operator|.
name|find
argument_list|(
name|Loc
operator|.
name|getOffset
argument_list|()
argument_list|)
operator|!=
name|Module
operator|.
name|SLocRemap
operator|.
name|end
argument_list|()
operator|&&
literal|"Cannot find offset to remap."
argument_list|)
expr_stmt|;
name|int
name|Remap
init|=
name|Module
operator|.
name|SLocRemap
operator|.
name|find
argument_list|(
name|Loc
operator|.
name|getOffset
argument_list|()
argument_list|)
operator|->
name|second
decl_stmt|;
return|return
name|Loc
operator|.
name|getLocWithOffset
argument_list|(
name|Remap
argument_list|)
return|;
block|}
comment|/// \brief Read a source location.
name|SourceLocation
name|ReadSourceLocation
parameter_list|(
name|Module
modifier|&
name|Module
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
block|{
return|return
name|ReadSourceLocation
argument_list|(
name|Module
argument_list|,
name|Record
index|[
name|Idx
operator|++
index|]
argument_list|)
return|;
block|}
comment|/// \brief Read a source range.
name|SourceRange
name|ReadSourceRange
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
comment|/// \brief Read an integral value
name|llvm
operator|::
name|APInt
name|ReadAPInt
argument_list|(
specifier|const
name|RecordData
operator|&
name|Record
argument_list|,
name|unsigned
operator|&
name|Idx
argument_list|)
expr_stmt|;
comment|/// \brief Read a signed integral value
name|llvm
operator|::
name|APSInt
name|ReadAPSInt
argument_list|(
specifier|const
name|RecordData
operator|&
name|Record
argument_list|,
name|unsigned
operator|&
name|Idx
argument_list|)
expr_stmt|;
comment|/// \brief Read a floating-point value
name|llvm
operator|::
name|APFloat
name|ReadAPFloat
argument_list|(
specifier|const
name|RecordData
operator|&
name|Record
argument_list|,
name|unsigned
operator|&
name|Idx
argument_list|)
expr_stmt|;
comment|// \brief Read a string
name|std
operator|::
name|string
name|ReadString
argument_list|(
specifier|const
name|RecordData
operator|&
name|Record
argument_list|,
name|unsigned
operator|&
name|Idx
argument_list|)
expr_stmt|;
comment|/// \brief Read a version tuple.
name|VersionTuple
name|ReadVersionTuple
parameter_list|(
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
name|CXXTemporary
modifier|*
name|ReadCXXTemporary
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
comment|/// \brief Reads attributes from the current stream position.
name|void
name|ReadAttributes
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
name|AttrVec
modifier|&
name|Attrs
parameter_list|,
specifier|const
name|RecordData
modifier|&
name|Record
parameter_list|,
name|unsigned
modifier|&
name|Idx
parameter_list|)
function_decl|;
comment|/// \brief Reads a statement.
name|Stmt
modifier|*
name|ReadStmt
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|)
function_decl|;
comment|/// \brief Reads an expression.
name|Expr
modifier|*
name|ReadExpr
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|)
function_decl|;
comment|/// \brief Reads a sub-statement operand during statement reading.
name|Stmt
modifier|*
name|ReadSubStmt
parameter_list|()
block|{
name|assert
argument_list|(
name|ReadingKind
operator|==
name|Read_Stmt
operator|&&
literal|"Should be called only during statement reading!"
argument_list|)
expr_stmt|;
comment|// Subexpressions are stored from last to first, so the next Stmt we need
comment|// is at the back of the stack.
name|assert
argument_list|(
operator|!
name|StmtStack
operator|.
name|empty
argument_list|()
operator|&&
literal|"Read too many sub statements!"
argument_list|)
expr_stmt|;
return|return
name|StmtStack
operator|.
name|pop_back_val
argument_list|()
return|;
block|}
comment|/// \brief Reads a sub-expression operand during statement reading.
name|Expr
modifier|*
name|ReadSubExpr
parameter_list|()
function_decl|;
comment|/// \brief Reads the macro record located at the given offset.
name|void
name|ReadMacroRecord
parameter_list|(
name|Module
modifier|&
name|F
parameter_list|,
name|uint64_t
name|Offset
parameter_list|)
function_decl|;
comment|/// \brief Determine the global preprocessed entity ID that corresponds to
comment|/// the given local ID within the given module.
name|serialization
operator|::
name|PreprocessedEntityID
name|getGlobalPreprocessedEntityID
argument_list|(
argument|Module&M
argument_list|,
argument|unsigned LocalID
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Note that the identifier is a macro whose record will be loaded
comment|/// from the given AST file at the given (file-local) offset.
name|void
name|SetIdentifierIsMacro
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|Module
modifier|&
name|F
parameter_list|,
name|uint64_t
name|Offset
parameter_list|)
function_decl|;
comment|/// \brief Read the set of macros defined by this external macro source.
name|virtual
name|void
name|ReadDefinedMacros
parameter_list|()
function_decl|;
comment|/// \brief Read the macro definition for this identifier.
name|virtual
name|void
name|LoadMacroDefinition
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
function_decl|;
comment|/// \brief Read the macro definition corresponding to this iterator
comment|/// into the unread macro record offsets table.
name|void
name|LoadMacroDefinition
argument_list|(
name|llvm
operator|::
name|DenseMap
operator|<
name|IdentifierInfo
operator|*
argument_list|,
name|uint64_t
operator|>
operator|::
name|iterator
name|Pos
argument_list|)
decl_stmt|;
comment|/// \brief Retrieve the AST context that this AST reader supplements.
name|ASTContext
modifier|&
name|getContext
parameter_list|()
block|{
return|return
name|Context
return|;
block|}
comment|// \brief Contains declarations that were loaded before we have
comment|// access to a Sema object.
name|SmallVector
operator|<
name|NamedDecl
operator|*
operator|,
literal|16
operator|>
name|PreloadedDecls
expr_stmt|;
comment|/// \brief Retrieve the semantic analysis object used to analyze the
comment|/// translation unit in which the precompiled header is being
comment|/// imported.
name|Sema
modifier|*
name|getSema
parameter_list|()
block|{
return|return
name|SemaObj
return|;
block|}
comment|/// \brief Retrieve the identifier table associated with the
comment|/// preprocessor.
name|IdentifierTable
modifier|&
name|getIdentifierTable
parameter_list|()
function_decl|;
comment|/// \brief Record that the given ID maps to the given switch-case
comment|/// statement.
name|void
name|RecordSwitchCaseID
parameter_list|(
name|SwitchCase
modifier|*
name|SC
parameter_list|,
name|unsigned
name|ID
parameter_list|)
function_decl|;
comment|/// \brief Retrieve the switch-case statement with the given ID.
name|SwitchCase
modifier|*
name|getSwitchCaseWithID
parameter_list|(
name|unsigned
name|ID
parameter_list|)
function_decl|;
name|void
name|ClearSwitchCaseIDs
parameter_list|()
function_decl|;
block|}
empty_stmt|;
comment|/// \brief Helper class that saves the current stream position and
comment|/// then restores it when destroyed.
struct|struct
name|SavedStreamPosition
block|{
name|explicit
name|SavedStreamPosition
argument_list|(
name|llvm
operator|::
name|BitstreamCursor
operator|&
name|Cursor
argument_list|)
range|:
name|Cursor
argument_list|(
name|Cursor
argument_list|)
decl_stmt|,
name|Offset
argument_list|(
name|Cursor
operator|.
name|GetCurrentBitNo
argument_list|()
argument_list|)
block|{ }
operator|~
name|SavedStreamPosition
argument_list|()
block|{
name|Cursor
operator|.
name|JumpToBit
argument_list|(
name|Offset
argument_list|)
block|;   }
name|private
operator|:
name|llvm
operator|::
name|BitstreamCursor
operator|&
name|Cursor
expr_stmt|;
name|uint64_t
name|Offset
decl_stmt|;
block|}
struct|;
specifier|inline
name|void
name|PCHValidator
operator|::
name|Error
argument_list|(
argument|const char *Msg
argument_list|)
block|{
name|Reader
operator|.
name|Error
argument_list|(
name|Msg
argument_list|)
block|; }
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

