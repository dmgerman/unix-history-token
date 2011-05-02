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
name|ASTReader
decl_stmt|;
name|class
name|ASTDeclReader
decl_stmt|;
name|class
name|ASTStmtReader
decl_stmt|;
name|class
name|ASTIdentifierLookupTrait
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
name|llvm
operator|::
name|StringRef
name|Data
expr_stmt|;
block|}
struct|;
typedef|typedef
name|llvm
operator|::
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
argument_list|(
name|llvm
operator|::
name|StringRef
name|Triple
argument_list|)
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
name|llvm
operator|::
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
argument|llvm::StringRef Triple
argument_list|)
block|;
name|virtual
name|bool
name|ReadPredefinesBuffer
argument_list|(
argument|const PCHPredefinesBlocks&Buffers
argument_list|,
argument|llvm::StringRef OriginalFileName
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
enum|enum
name|ASTFileType
block|{
name|Module
block|,
comment|///< File is a module proper.
name|PCH
block|,
comment|///< File is a PCH file treated as such.
name|Preamble
block|,
comment|///< File is a PCH file treated as the preamble.
name|MainFile
comment|///< File is a PCH file treated as the actual main file.
block|}
enum|;
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
name|ASTIdentifierLookupTrait
decl_stmt|;
name|friend
name|class
name|TypeLocReader
decl_stmt|;
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
name|Diagnostic
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
modifier|*
name|PP
decl_stmt|;
comment|/// \brief The AST context into which we'll read the AST files.
name|ASTContext
modifier|*
name|Context
decl_stmt|;
comment|/// \brief The AST consumer.
name|ASTConsumer
modifier|*
name|Consumer
decl_stmt|;
comment|/// \brief AST buffers for chained PCHs created and stored in memory.
comment|/// First (not depending on another) PCH in chain is in front.
name|std
operator|::
name|vector
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|*
operator|>
name|ASTBuffers
expr_stmt|;
comment|/// \brief Information that is needed for every module.
struct|struct
name|PerFileData
block|{
name|PerFileData
argument_list|(
argument|ASTFileType Ty
argument_list|)
empty_stmt|;
operator|~
name|PerFileData
argument_list|()
expr_stmt|;
comment|// === General information ===
comment|/// \brief The type of this AST file.
name|ASTFileType
name|Type
decl_stmt|;
comment|/// \brief The file name of the AST file.
name|std
operator|::
name|string
name|FileName
expr_stmt|;
comment|/// \brief The memory buffer that stores the data associated with
comment|/// this AST file.
name|llvm
operator|::
name|OwningPtr
operator|<
name|llvm
operator|::
name|MemoryBuffer
operator|>
name|Buffer
expr_stmt|;
comment|/// \brief The size of this file, in bits.
name|uint64_t
name|SizeInBits
decl_stmt|;
comment|/// \brief The bitstream reader from which we'll read the AST file.
name|llvm
operator|::
name|BitstreamReader
name|StreamFile
expr_stmt|;
comment|/// \brief The main bitstream cursor for the main block.
name|llvm
operator|::
name|BitstreamCursor
name|Stream
expr_stmt|;
comment|// === Source Locations ===
comment|/// \brief Cursor used to read source location entries.
name|llvm
operator|::
name|BitstreamCursor
name|SLocEntryCursor
expr_stmt|;
comment|/// \brief The number of source location entries in this AST file.
name|unsigned
name|LocalNumSLocEntries
decl_stmt|;
comment|/// \brief Offsets for all of the source location entries in the
comment|/// AST file.
specifier|const
name|uint32_t
modifier|*
name|SLocOffsets
decl_stmt|;
comment|/// \brief The entire size of this module's source location offset range.
name|unsigned
name|LocalSLocSize
decl_stmt|;
comment|// === Identifiers ===
comment|/// \brief The number of identifiers in this AST file.
name|unsigned
name|LocalNumIdentifiers
decl_stmt|;
comment|/// \brief Offsets into the identifier table data.
comment|///
comment|/// This array is indexed by the identifier ID (-1), and provides
comment|/// the offset into IdentifierTableData where the string data is
comment|/// stored.
specifier|const
name|uint32_t
modifier|*
name|IdentifierOffsets
decl_stmt|;
comment|/// \brief Actual data for the on-disk hash table of identifiers.
comment|///
comment|/// This pointer points into a memory buffer, where the on-disk hash
comment|/// table for identifiers actually lives.
specifier|const
name|char
modifier|*
name|IdentifierTableData
decl_stmt|;
comment|/// \brief A pointer to an on-disk hash table of opaque type
comment|/// IdentifierHashTable.
name|void
modifier|*
name|IdentifierLookupTable
decl_stmt|;
comment|// === Macros ===
comment|/// \brief The cursor to the start of the preprocessor block, which stores
comment|/// all of the macro definitions.
name|llvm
operator|::
name|BitstreamCursor
name|MacroCursor
expr_stmt|;
comment|/// \brief The offset of the start of the set of defined macros.
name|uint64_t
name|MacroStartOffset
decl_stmt|;
comment|// === Detailed PreprocessingRecord ===
comment|/// \brief The cursor to the start of the (optional) detailed preprocessing
comment|/// record block.
name|llvm
operator|::
name|BitstreamCursor
name|PreprocessorDetailCursor
expr_stmt|;
comment|/// \brief The offset of the start of the preprocessor detail cursor.
name|uint64_t
name|PreprocessorDetailStartOffset
decl_stmt|;
comment|/// \brief The number of macro definitions in this file.
name|unsigned
name|LocalNumMacroDefinitions
decl_stmt|;
comment|/// \brief Offsets of all of the macro definitions in the preprocessing
comment|/// record in the AST file.
specifier|const
name|uint32_t
modifier|*
name|MacroDefinitionOffsets
decl_stmt|;
comment|// === Header search information ===
comment|/// \brief The number of local HeaderFileInfo structures.
name|unsigned
name|LocalNumHeaderFileInfos
decl_stmt|;
comment|/// \brief Actual data for the on-disk hash table of header file
comment|/// information.
comment|///
comment|/// This pointer points into a memory buffer, where the on-disk hash
comment|/// table for header file information actually lives.
specifier|const
name|char
modifier|*
name|HeaderFileInfoTableData
decl_stmt|;
comment|/// \brief The on-disk hash table that contains information about each of
comment|/// the header files.
name|void
modifier|*
name|HeaderFileInfoTable
decl_stmt|;
comment|// === Selectors ===
comment|/// \brief The number of selectors new to this file.
comment|///
comment|/// This is the number of entries in SelectorOffsets.
name|unsigned
name|LocalNumSelectors
decl_stmt|;
comment|/// \brief Offsets into the selector lookup table's data array
comment|/// where each selector resides.
specifier|const
name|uint32_t
modifier|*
name|SelectorOffsets
decl_stmt|;
comment|/// \brief A pointer to the character data that comprises the selector table
comment|///
comment|/// The SelectorOffsets table refers into this memory.
specifier|const
name|unsigned
name|char
modifier|*
name|SelectorLookupTableData
decl_stmt|;
comment|/// \brief A pointer to an on-disk hash table of opaque type
comment|/// ASTSelectorLookupTable.
comment|///
comment|/// This hash table provides the IDs of all selectors, and the associated
comment|/// instance and factory methods.
name|void
modifier|*
name|SelectorLookupTable
decl_stmt|;
comment|/// \brief Method selectors used in a @selector expression. Used for
comment|/// implementation of -Wselector.
name|llvm
operator|::
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|64
operator|>
name|ReferencedSelectorsData
expr_stmt|;
comment|// === Declarations ===
comment|/// DeclsCursor - This is a cursor to the start of the DECLS_BLOCK block. It
comment|/// has read all the abbreviations at the start of the block and is ready to
comment|/// jump around with these in context.
name|llvm
operator|::
name|BitstreamCursor
name|DeclsCursor
expr_stmt|;
comment|/// \brief The number of declarations in this AST file.
name|unsigned
name|LocalNumDecls
decl_stmt|;
comment|/// \brief Offset of each declaration within the bitstream, indexed
comment|/// by the declaration ID (-1).
specifier|const
name|uint32_t
modifier|*
name|DeclOffsets
decl_stmt|;
comment|/// \brief A snapshot of the pending instantiations in the chain.
comment|///
comment|/// This record tracks the instantiations that Sema has to perform at the
comment|/// end of the TU. It consists of a pair of values for every pending
comment|/// instantiation where the first value is the ID of the decl and the second
comment|/// is the instantiation location.
name|llvm
operator|::
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|64
operator|>
name|PendingInstantiations
expr_stmt|;
comment|/// \brief The number of C++ base specifier sets in this AST file.
name|unsigned
name|LocalNumCXXBaseSpecifiers
decl_stmt|;
comment|/// \brief Offset of each C++ base specifier set within the bitstream,
comment|/// indexed by the C++ base specifier set ID (-1).
specifier|const
name|uint32_t
modifier|*
name|CXXBaseSpecifiersOffsets
decl_stmt|;
comment|// === Types ===
comment|/// \brief The number of types in this AST file.
name|unsigned
name|LocalNumTypes
decl_stmt|;
comment|/// \brief Offset of each type within the bitstream, indexed by the
comment|/// type ID, or the representation of a Type*.
specifier|const
name|uint32_t
modifier|*
name|TypeOffsets
decl_stmt|;
comment|// === Miscellaneous ===
comment|/// \brief The AST stat cache installed for this file, if any.
comment|///
comment|/// The dynamic type of this stat cache is always ASTStatCache
name|void
modifier|*
name|StatCache
decl_stmt|;
comment|/// \brief The number of preallocated preprocessing entities in the
comment|/// preprocessing record.
name|unsigned
name|NumPreallocatedPreprocessingEntities
decl_stmt|;
comment|/// \brief The next module in source order.
name|PerFileData
modifier|*
name|NextInSource
decl_stmt|;
comment|/// \brief All the modules that loaded this one. Can contain NULL for
comment|/// directly loaded modules.
name|llvm
operator|::
name|SmallVector
operator|<
name|PerFileData
operator|*
operator|,
literal|1
operator|>
name|Loaders
expr_stmt|;
block|}
struct|;
comment|/// \brief All loaded modules, indexed by name.
name|llvm
operator|::
name|StringMap
operator|<
name|PerFileData
operator|*
operator|>
name|Modules
expr_stmt|;
comment|/// \brief The first module in source order.
name|PerFileData
modifier|*
name|FirstInSource
decl_stmt|;
comment|/// \brief The chain of AST files. The first entry is the one named by the
comment|/// user, the last one is the one that doesn't depend on anything further.
comment|/// That is, the entry I was created with -include-pch I+1.
name|llvm
operator|::
name|SmallVector
operator|<
name|PerFileData
operator|*
operator|,
literal|2
operator|>
name|Chain
expr_stmt|;
comment|/// \brief SLocEntries that we're going to preload.
name|llvm
operator|::
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|64
operator|>
name|PreloadSLocEntries
expr_stmt|;
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
comment|/// \brief Map that provides the ID numbers of each type within the
comment|/// output stream, plus those deserialized from a chained PCH.
comment|///
comment|/// The ID numbers of types are consecutive (in order of discovery)
comment|/// and start at 1. 0 is reserved for NULL. When types are actually
comment|/// stored in the stream, the ID number is shifted by 2 bits to
comment|/// allow for the const/volatile qualifiers.
comment|///
comment|/// Keys in the map never have const/volatile qualifiers.
name|serialization
operator|::
name|TypeIdxMap
name|TypeIdxs
expr_stmt|;
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
name|std
operator|::
name|pair
operator|<
name|PerFileData
operator|*
operator|,
name|uint64_t
operator|>
name|FileOffset
expr_stmt|;
typedef|typedef
name|llvm
operator|::
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
name|PerFileData
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
comment|/// \brief Information about the contents of a DeclContext.
struct|struct
name|DeclContextInfo
block|{
name|void
modifier|*
name|NameLookupTableData
decl_stmt|;
comment|// a ASTDeclContextNameLookupTable.
specifier|const
name|serialization
operator|::
name|KindDeclIDPair
operator|*
name|LexicalDecls
expr_stmt|;
name|unsigned
name|NumLexicalDecls
decl_stmt|;
block|}
struct|;
comment|// In a full chain, there could be multiple updates to every decl context,
comment|// so this is a vector. However, typically a chain is only two elements long,
comment|// with only one file containing updates, so there will be only one update
comment|// per decl context.
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|DeclContextInfo
operator|,
literal|1
operator|>
name|DeclContextInfos
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|DeclContext
operator|*
operator|,
name|DeclContextInfos
operator|>
name|DeclContextOffsetsMap
expr_stmt|;
comment|// Updates for visible decls can occur for other contexts than just the
comment|// TU, and when we read those update records, the actual context will not
comment|// be available yet (unless it's the TU), so have this pending map using the
comment|// ID as a key. It will be realized when the context is actually loaded.
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|void
operator|*
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
comment|/// \brief Offsets of the lexical and visible declarations for each
comment|/// DeclContext.
name|DeclContextOffsetsMap
name|DeclContextOffsets
decl_stmt|;
comment|/// \brief Updates to the visible declarations of declaration contexts that
comment|/// haven't been loaded yet.
name|DeclContextVisibleUpdatesPending
name|PendingVisibleUpdates
decl_stmt|;
typedef|typedef
name|llvm
operator|::
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
comment|/// \brief Read the records that describe the contents of declcontexts.
name|bool
name|ReadDeclContextStorage
argument_list|(
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
comment|/// \brief A vector containing selectors that have already been loaded.
comment|///
comment|/// This vector is indexed by the Selector ID (-1). NULL selector
comment|/// entries indicate that the particular selector ID has not yet
comment|/// been loaded.
name|llvm
operator|::
name|SmallVector
operator|<
name|Selector
operator|,
literal|16
operator|>
name|SelectorsLoaded
expr_stmt|;
comment|/// \brief The macro definitions we have already loaded.
name|llvm
operator|::
name|SmallVector
operator|<
name|MacroDefinition
operator|*
operator|,
literal|16
operator|>
name|MacroDefinitionsLoaded
expr_stmt|;
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
comment|/// \name CodeGen-relevant special data
comment|/// \brief Fields containing data that is relevant to CodeGen.
comment|//@{
comment|/// \brief The IDs of all declarations that fulfill the criteria of
comment|/// "interesting" decls.
comment|///
comment|/// This contains the data loaded from all EXTERNAL_DEFINITIONS blocks in the
comment|/// chain. The referenced declarations are deserialized and passed to the
comment|/// consumer eagerly.
name|llvm
operator|::
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
name|llvm
operator|::
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
name|llvm
operator|::
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|64
operator|>
name|VTableUses
expr_stmt|;
comment|//@}
comment|/// \name Diagnostic-relevant special data
comment|/// \brief Fields containing data that is used for generating diagnostics
comment|//@{
comment|/// \brief A snapshot of Sema's unused file-scoped variable tracking, for
comment|/// generating warnings.
name|llvm
operator|::
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|16
operator|>
name|UnusedFileScopedDecls
expr_stmt|;
comment|/// \brief A snapshot of Sema's weak undeclared identifier tracking, for
comment|/// generating warnings.
name|llvm
operator|::
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
name|llvm
operator|::
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
name|llvm
operator|::
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
name|llvm
operator|::
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
name|llvm
operator|::
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
name|llvm
operator|::
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
name|llvm
operator|::
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|2
operator|>
name|CUDASpecialDeclRefs
expr_stmt|;
comment|/// \brief The floating point pragma option settings.
name|llvm
operator|::
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|1
operator|>
name|FPPragmaOptions
expr_stmt|;
comment|/// \brief The OpenCL extension settings.
name|llvm
operator|::
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|1
operator|>
name|OpenCLExtensions
expr_stmt|;
comment|//@}
comment|/// \brief Diagnostic IDs and their mappings that the user changed.
name|llvm
operator|::
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|8
operator|>
name|PragmaDiagMappings
expr_stmt|;
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
specifier|const
name|char
modifier|*
name|isysroot
decl_stmt|;
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
comment|/// \brief The next offset for a SLocEntry after everything in this reader.
name|unsigned
name|NextSLocOffset
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
comment|/// \brief Number of Decl/types that are currently deserializing.
name|unsigned
name|NumCurrentElementsDeserializing
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
name|llvm
operator|::
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
name|llvm
operator|::
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
name|PerFileData
modifier|&
name|F
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
argument_list|(
name|llvm
operator|::
name|StringRef
name|FileName
argument_list|,
name|ASTFileType
name|Type
argument_list|)
decl_stmt|;
name|ASTReadResult
name|ReadASTBlock
parameter_list|(
name|PerFileData
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
name|PerFileData
operator|&
name|F
argument_list|,
name|llvm
operator|::
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
name|PerFileData
modifier|&
name|F
parameter_list|)
function_decl|;
name|ASTReadResult
name|ReadSLocEntryRecord
parameter_list|(
name|unsigned
name|ID
parameter_list|)
function_decl|;
name|PerFileData
modifier|*
name|SLocCursorForID
parameter_list|(
name|unsigned
name|ID
parameter_list|)
function_decl|;
name|SourceLocation
name|getImportLocation
parameter_list|(
name|PerFileData
modifier|*
name|F
parameter_list|)
function_decl|;
name|bool
name|ParseLanguageOptions
argument_list|(
specifier|const
name|llvm
operator|::
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
argument|PerFileData *M
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
name|PerFileData
operator|*
name|F
expr_stmt|;
name|uint64_t
name|Offset
decl_stmt|;
block|}
struct|;
name|QualType
name|ReadTypeRecord
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
name|unsigned
name|Index
argument_list|,
name|serialization
operator|::
name|DeclID
name|ID
argument_list|)
decl_stmt|;
name|RecordLocation
name|DeclCursorForIndex
argument_list|(
name|unsigned
name|Index
argument_list|,
name|serialization
operator|::
name|DeclID
name|ID
argument_list|)
decl_stmt|;
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
argument_list|(
name|llvm
operator|::
name|StringRef
name|Msg
argument_list|)
decl_stmt|;
name|void
name|Error
argument_list|(
name|unsigned
name|DiagID
argument_list|,
name|llvm
operator|::
name|StringRef
name|Arg1
operator|=
name|llvm
operator|::
name|StringRef
argument_list|()
argument_list|,
name|llvm
operator|::
name|StringRef
name|Arg2
operator|=
name|llvm
operator|::
name|StringRef
argument_list|()
argument_list|)
decl_stmt|;
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
name|llvm
operator|::
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
argument|ASTContext *Context
argument_list|,
argument|const char *isysroot =
literal|0
argument_list|,
argument|bool DisableValidation = false
argument_list|,
argument|bool DisableStatCache = false
argument_list|)
empty_stmt|;
comment|/// \brief Load the AST file without using any pre-initialized Preprocessor.
comment|///
comment|/// The necessary information to initialize a Preprocessor later can be
comment|/// obtained by setting a ASTReaderListener.
comment|///
comment|/// \param SourceMgr the source manager into which the AST file will be loaded
comment|///
comment|/// \param FileMgr the file manager into which the AST file will be loaded.
comment|///
comment|/// \param Diags the diagnostics system to use for reporting errors and
comment|/// warnings relevant to loading the AST file.
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
argument|SourceManager&SourceMgr
argument_list|,
argument|FileManager&FileMgr
argument_list|,
argument|Diagnostic&Diags
argument_list|,
argument|const char *isysroot =
literal|0
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
comment|/// \brief Load the precompiled header designated by the given file
comment|/// name.
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
name|ASTFileType
name|Type
argument_list|)
decl_stmt|;
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
comment|/// \brief Set the Preprocessor to use.
name|void
name|setPreprocessor
parameter_list|(
name|Preprocessor
modifier|&
name|pp
parameter_list|)
function_decl|;
comment|/// \brief Sets and initializes the given Context.
name|void
name|InitializeContext
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|)
function_decl|;
comment|/// \brief Set AST buffers for chained PCHs created and stored in memory.
comment|/// First (not depending on another) PCH in chain is first in array.
name|void
name|setASTMemoryBuffers
argument_list|(
name|llvm
operator|::
name|MemoryBuffer
operator|*
operator|*
name|bufs
argument_list|,
name|unsigned
name|numBufs
argument_list|)
block|{
name|ASTBuffers
operator|.
name|clear
argument_list|()
expr_stmt|;
name|ASTBuffers
operator|.
name|insert
argument_list|(
name|ASTBuffers
operator|.
name|begin
argument_list|()
argument_list|,
name|bufs
argument_list|,
name|bufs
operator|+
name|numBufs
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Retrieve the name of the named (primary) AST file
specifier|const
name|std
operator|::
name|string
operator|&
name|getFileName
argument_list|()
specifier|const
block|{
return|return
name|Chain
index|[
literal|0
index|]
operator|->
name|FileName
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
name|Diagnostic
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
comment|/// \brief Read preprocessed entities into the preprocessing record.
name|virtual
name|void
name|ReadPreprocessedEntities
parameter_list|()
function_decl|;
comment|/// \brief Read the preprocessed entity at the given offset.
name|virtual
name|PreprocessedEntity
modifier|*
name|ReadPreprocessedEntityAtOffset
parameter_list|(
name|uint64_t
name|Offset
parameter_list|)
function_decl|;
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
name|Diagnostic
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
comment|/// \brief Returns the next SLocEntry offset after the chain.
name|unsigned
name|getNextSLocOffset
argument_list|()
specifier|const
block|{
return|return
name|NextSLocOffset
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
comment|/// \brief Returns the number of macro definitions found in the chain.
name|unsigned
name|getTotalNumMacroDefinitions
argument_list|()
specifier|const
block|{
return|return
name|static_cast
operator|<
name|unsigned
operator|>
operator|(
name|MacroDefinitionsLoaded
operator|.
name|size
argument_list|()
operator|)
return|;
block|}
comment|/// \brief Returns the number of C++ base specifiers found in the chain.
name|unsigned
name|getTotalNumCXXBaseSpecifiers
argument_list|()
specifier|const
expr_stmt|;
comment|/// \brief Reads a TemplateArgumentLocInfo appropriate for the
comment|/// given TemplateArgument kind.
name|TemplateArgumentLocInfo
name|GetTemplateArgumentLocInfo
argument_list|(
name|PerFileData
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
name|PerFileData
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
name|PerFileData
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
comment|/// \brief Resolve and return the translation unit declaration.
name|TranslationUnitDecl
modifier|*
name|GetTranslationUnitDecl
parameter_list|()
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
comment|/// \brief Returns the type ID associated with the given type.
comment|/// If the type didn't come from the AST file the ID that is returned is
comment|/// marked as "doesn't exist in AST".
name|serialization
operator|::
name|TypeID
name|GetTypeID
argument_list|(
argument|QualType T
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Returns the type index associated with the given type.
comment|/// If the type didn't come from the AST file the index that is returned is
comment|/// marked as "doesn't exist in AST".
name|serialization
operator|::
name|TypeIdx
name|GetTypeIdx
argument_list|(
argument|QualType T
argument_list|)
specifier|const
expr_stmt|;
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
comment|/// \brief Resolve a CXXBaseSpecifiers ID into an offset into the chain
comment|/// of loaded AST files.
name|uint64_t
name|GetCXXBaseSpecifiersOffset
argument_list|(
name|serialization
operator|::
name|CXXBaseSpecifiersID
name|ID
argument_list|)
decl_stmt|;
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
name|virtual
name|void
name|MaterializeVisibleDecls
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|DC
parameter_list|)
function_decl|;
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
argument_list|(
name|llvm
operator|::
name|StringRef
name|Name
argument_list|)
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
name|llvm
operator|::
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
parameter_list|(
name|unsigned
name|Idx
parameter_list|)
function_decl|;
name|IdentifierInfo
modifier|*
name|GetIdentifierInfo
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
block|{
return|return
name|DecodeIdentifierInfo
argument_list|(
name|Record
index|[
name|Idx
operator|++
index|]
argument_list|)
return|;
block|}
name|virtual
name|IdentifierInfo
modifier|*
name|GetIdentifier
parameter_list|(
name|unsigned
name|ID
parameter_list|)
block|{
return|return
name|DecodeIdentifierInfo
argument_list|(
name|ID
argument_list|)
return|;
block|}
comment|/// \brief Read the source location entry with index ID.
name|virtual
name|bool
name|ReadSLocEntry
parameter_list|(
name|unsigned
name|ID
parameter_list|)
function_decl|;
name|Selector
name|DecodeSelector
parameter_list|(
name|unsigned
name|Idx
parameter_list|)
function_decl|;
name|virtual
name|Selector
name|GetExternalSelector
parameter_list|(
name|uint32_t
name|ID
parameter_list|)
function_decl|;
name|uint32_t
name|GetNumExternalSelectors
parameter_list|()
function_decl|;
name|Selector
name|GetSelector
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
block|{
return|return
name|DecodeSelector
argument_list|(
name|Record
index|[
name|Idx
operator|++
index|]
argument_list|)
return|;
block|}
comment|/// \brief Read a declaration name.
name|DeclarationName
name|ReadDeclarationName
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
name|void
name|ReadDeclarationNameLoc
parameter_list|(
name|PerFileData
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
name|PerFileData
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
name|PerFileData
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
name|PerFileData
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
name|PerFileData
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
name|PerFileData
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
name|PerFileData
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
name|llvm
operator|::
name|SmallVector
operator|<
name|TemplateArgument
argument_list|,
literal|8
operator|>
operator|&
name|TemplArgs
argument_list|,
name|PerFileData
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
name|PerFileData
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
name|PerFileData
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
parameter_list|(
name|PerFileData
modifier|&
name|Module
parameter_list|,
name|unsigned
name|Raw
parameter_list|)
block|{
operator|(
name|void
operator|)
name|Module
expr_stmt|;
comment|// No remapping yet
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|Raw
argument_list|)
return|;
block|}
comment|/// \brief Read a source location.
name|SourceLocation
name|ReadSourceLocation
parameter_list|(
name|PerFileData
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
name|PerFileData
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
name|PerFileData
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
name|PerFileData
modifier|&
name|F
parameter_list|)
function_decl|;
comment|/// \brief Reads an expression.
name|Expr
modifier|*
name|ReadExpr
parameter_list|(
name|PerFileData
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
name|PreprocessedEntity
modifier|*
name|ReadMacroRecord
parameter_list|(
name|PerFileData
modifier|&
name|F
parameter_list|,
name|uint64_t
name|Offset
parameter_list|)
function_decl|;
comment|/// \brief Reads the preprocessed entity located at the current stream
comment|/// position.
name|PreprocessedEntity
modifier|*
name|LoadPreprocessedEntity
parameter_list|(
name|PerFileData
modifier|&
name|F
parameter_list|)
function_decl|;
comment|/// \brief Note that the identifier is a macro whose record will be loaded
comment|/// from the given AST file at the given (file-local) offset.
name|void
name|SetIdentifierIsMacro
parameter_list|(
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|PerFileData
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
comment|/// \brief Retrieve the macro definition with the given ID.
name|MacroDefinition
modifier|*
name|getMacroDefinition
argument_list|(
name|serialization
operator|::
name|MacroID
name|ID
argument_list|)
decl_stmt|;
comment|/// \brief Retrieve the AST context that this AST reader supplements.
name|ASTContext
modifier|*
name|getContext
parameter_list|()
block|{
return|return
name|Context
return|;
block|}
comment|// \brief Contains declarations that were loaded before we have
comment|// access to a Sema object.
name|llvm
operator|::
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

