begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Module.h - Module description --------------------------*- C++ -*-===//
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
comment|//  This file defines the Module class, which describes a module that has
end_comment

begin_comment
comment|//  been loaded from an AST file.
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
name|LLVM_CLANG_SERIALIZATION_MODULE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SERIALIZATION_MODULE_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/SourceLocation.h"
end_include

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
file|"llvm/ADT/SetVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Bitcode/BitstreamReader.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|typename
name|Info
operator|>
name|class
name|OnDiskChainedHashTable
expr_stmt|;
name|template
operator|<
name|typename
name|Info
operator|>
name|class
name|OnDiskIterableChainedHashTable
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|FileEntry
decl_stmt|;
name|class
name|DeclContext
decl_stmt|;
name|class
name|Module
decl_stmt|;
name|namespace
name|serialization
block|{
name|namespace
name|reader
block|{
name|class
name|ASTDeclContextNameLookupTrait
decl_stmt|;
block|}
comment|/// \brief Specifies the kind of module that has been loaded.
enum|enum
name|ModuleKind
block|{
name|MK_Module
block|,
comment|///< File is a module proper.
name|MK_PCH
block|,
comment|///< File is a PCH file treated as such.
name|MK_Preamble
block|,
comment|///< File is a PCH file treated as the preamble.
name|MK_MainFile
comment|///< File is a PCH file treated as the actual main file.
block|}
enum|;
comment|/// \brief Information about the contents of a DeclContext.
struct|struct
name|DeclContextInfo
block|{
name|DeclContextInfo
argument_list|()
operator|:
name|NameLookupTableData
argument_list|()
operator|,
name|LexicalDecls
argument_list|()
operator|,
name|NumLexicalDecls
argument_list|()
block|{}
name|llvm
operator|::
name|OnDiskIterableChainedHashTable
operator|<
name|reader
operator|::
name|ASTDeclContextNameLookupTrait
operator|>
operator|*
name|NameLookupTableData
expr_stmt|;
comment|// an ASTDeclContextNameLookupTable.
specifier|const
name|KindDeclIDPair
modifier|*
name|LexicalDecls
decl_stmt|;
name|unsigned
name|NumLexicalDecls
decl_stmt|;
block|}
struct|;
comment|/// \brief The input file that has been loaded from this AST file, along with
comment|/// bools indicating whether this was an overridden buffer or if it was
comment|/// out-of-date or not-found.
name|class
name|InputFile
block|{
enum|enum
block|{
name|Overridden
init|=
literal|1
block|,
name|OutOfDate
init|=
literal|2
block|,
name|NotFound
init|=
literal|3
block|}
enum|;
name|llvm
operator|::
name|PointerIntPair
operator|<
specifier|const
name|FileEntry
operator|*
operator|,
literal|2
operator|,
name|unsigned
operator|>
name|Val
expr_stmt|;
name|public
label|:
name|InputFile
argument_list|()
block|{}
name|InputFile
argument_list|(
argument|const FileEntry *File
argument_list|,
argument|bool isOverridden = false
argument_list|,
argument|bool isOutOfDate = false
argument_list|)
block|{
name|assert
argument_list|(
operator|!
operator|(
name|isOverridden
operator|&&
name|isOutOfDate
operator|)
operator|&&
literal|"an overridden cannot be out-of-date"
argument_list|)
expr_stmt|;
name|unsigned
name|intVal
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|isOverridden
condition|)
name|intVal
operator|=
name|Overridden
expr_stmt|;
elseif|else
if|if
condition|(
name|isOutOfDate
condition|)
name|intVal
operator|=
name|OutOfDate
expr_stmt|;
name|Val
operator|.
name|setPointerAndInt
argument_list|(
name|File
argument_list|,
name|intVal
argument_list|)
expr_stmt|;
block|}
specifier|static
name|InputFile
name|getNotFound
parameter_list|()
block|{
name|InputFile
name|File
decl_stmt|;
name|File
operator|.
name|Val
operator|.
name|setInt
argument_list|(
name|NotFound
argument_list|)
expr_stmt|;
return|return
name|File
return|;
block|}
specifier|const
name|FileEntry
operator|*
name|getFile
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|bool
name|isOverridden
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|getInt
argument_list|()
operator|==
name|Overridden
return|;
block|}
name|bool
name|isOutOfDate
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|getInt
argument_list|()
operator|==
name|OutOfDate
return|;
block|}
name|bool
name|isNotFound
argument_list|()
specifier|const
block|{
return|return
name|Val
operator|.
name|getInt
argument_list|()
operator|==
name|NotFound
return|;
block|}
block|}
empty_stmt|;
comment|/// \brief Information about a module that has been loaded by the ASTReader.
comment|///
comment|/// Each instance of the Module class corresponds to a single AST file, which
comment|/// may be a precompiled header, precompiled preamble, a module, or an AST file
comment|/// of some sort loaded as the main file, all of which are specific formulations
comment|/// of the general notion of a "module". A module may depend on any number of
comment|/// other modules.
name|class
name|ModuleFile
block|{
name|public
label|:
name|ModuleFile
argument_list|(
argument|ModuleKind Kind
argument_list|,
argument|unsigned Generation
argument_list|)
empty_stmt|;
operator|~
name|ModuleFile
argument_list|()
expr_stmt|;
comment|// === General information ===
comment|/// \brief The index of this module in the list of modules.
name|unsigned
name|Index
decl_stmt|;
comment|/// \brief The type of this module.
name|ModuleKind
name|Kind
decl_stmt|;
comment|/// \brief The file name of the module file.
name|std
operator|::
name|string
name|FileName
expr_stmt|;
comment|/// \brief The name of the module.
name|std
operator|::
name|string
name|ModuleName
expr_stmt|;
name|std
operator|::
name|string
name|getTimestampFilename
argument_list|()
specifier|const
block|{
return|return
name|FileName
operator|+
literal|".timestamp"
return|;
block|}
comment|/// \brief The original source file name that was used to build the
comment|/// primary AST file, which may have been modified for
comment|/// relocatable-pch support.
name|std
operator|::
name|string
name|OriginalSourceFileName
expr_stmt|;
comment|/// \brief The actual original source file name that was used to
comment|/// build this AST file.
name|std
operator|::
name|string
name|ActualOriginalSourceFileName
expr_stmt|;
comment|/// \brief The file ID for the original source file that was used to
comment|/// build this AST file.
name|FileID
name|OriginalSourceFileID
decl_stmt|;
comment|/// \brief The directory that the PCH was originally created in. Used to
comment|/// allow resolving headers even after headers+PCH was moved to a new path.
name|std
operator|::
name|string
name|OriginalDir
expr_stmt|;
name|std
operator|::
name|string
name|ModuleMapPath
expr_stmt|;
comment|/// \brief Whether this precompiled header is a relocatable PCH file.
name|bool
name|RelocatablePCH
decl_stmt|;
comment|/// \brief The file entry for the module file.
specifier|const
name|FileEntry
modifier|*
name|File
decl_stmt|;
comment|/// \brief Whether this module has been directly imported by the
comment|/// user.
name|bool
name|DirectlyImported
decl_stmt|;
comment|/// \brief The generation of which this module file is a part.
name|unsigned
name|Generation
decl_stmt|;
comment|/// \brief The memory buffer that stores the data associated with
comment|/// this AST file.
name|std
operator|::
name|unique_ptr
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
comment|/// \brief The global bit offset (or base) of this module
name|uint64_t
name|GlobalBitOffset
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
comment|/// \brief The source location where the module was explicitly or implicitly
comment|/// imported in the local translation unit.
comment|///
comment|/// If module A depends on and imports module B, both modules will have the
comment|/// same DirectImportLoc, but different ImportLoc (B's ImportLoc will be a
comment|/// source location inside module A).
comment|///
comment|/// WARNING: This is largely useless. It doesn't tell you when a module was
comment|/// made visible, just when the first submodule of that module was imported.
name|SourceLocation
name|DirectImportLoc
decl_stmt|;
comment|/// \brief The source location where this module was first imported.
name|SourceLocation
name|ImportLoc
decl_stmt|;
comment|/// \brief The first source location in this module.
name|SourceLocation
name|FirstLoc
decl_stmt|;
comment|// === Input Files ===
comment|/// \brief The cursor to the start of the input-files block.
name|llvm
operator|::
name|BitstreamCursor
name|InputFilesCursor
expr_stmt|;
comment|/// \brief Offsets for all of the input file entries in the AST file.
specifier|const
name|uint32_t
modifier|*
name|InputFileOffsets
decl_stmt|;
comment|/// \brief The input files that have been loaded from this AST file.
name|std
operator|::
name|vector
operator|<
name|InputFile
operator|>
name|InputFilesLoaded
expr_stmt|;
comment|/// \brief If non-zero, specifies the time when we last validated input
comment|/// files.  Zero means we never validated them.
comment|///
comment|/// The time is specified in seconds since the start of the Epoch.
name|uint64_t
name|InputFilesValidationTimestamp
decl_stmt|;
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
comment|/// \brief The base ID in the source manager's view of this module.
name|int
name|SLocEntryBaseID
decl_stmt|;
comment|/// \brief The base offset in the source manager's view of this module.
name|unsigned
name|SLocEntryBaseOffset
decl_stmt|;
comment|/// \brief Offsets for all of the source location entries in the
comment|/// AST file.
specifier|const
name|uint32_t
modifier|*
name|SLocEntryOffsets
decl_stmt|;
comment|/// \brief SLocEntries that we're going to preload.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|4
operator|>
name|PreloadSLocEntries
expr_stmt|;
comment|/// \brief Remapping table for source locations in this module.
name|ContinuousRangeMap
operator|<
name|uint32_t
operator|,
name|int
operator|,
literal|2
operator|>
name|SLocRemap
expr_stmt|;
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
comment|/// \brief Base identifier ID for identifiers local to this module.
name|serialization
operator|::
name|IdentID
name|BaseIdentifierID
expr_stmt|;
comment|/// \brief Remapping table for identifier IDs in this module.
name|ContinuousRangeMap
operator|<
name|uint32_t
operator|,
name|int
operator|,
literal|2
operator|>
name|IdentifierRemap
expr_stmt|;
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
comment|/// \brief The number of macros in this AST file.
name|unsigned
name|LocalNumMacros
decl_stmt|;
comment|/// \brief Offsets of macros in the preprocessor block.
comment|///
comment|/// This array is indexed by the macro ID (-1), and provides
comment|/// the offset into the preprocessor block where macro definitions are
comment|/// stored.
specifier|const
name|uint32_t
modifier|*
name|MacroOffsets
decl_stmt|;
comment|/// \brief Base macro ID for macros local to this module.
name|serialization
operator|::
name|MacroID
name|BaseMacroID
expr_stmt|;
comment|/// \brief Remapping table for macro IDs in this module.
name|ContinuousRangeMap
operator|<
name|uint32_t
operator|,
name|int
operator|,
literal|2
operator|>
name|MacroRemap
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
comment|/// \brief Base preprocessed entity ID for preprocessed entities local to
comment|/// this module.
name|serialization
operator|::
name|PreprocessedEntityID
name|BasePreprocessedEntityID
expr_stmt|;
comment|/// \brief Remapping table for preprocessed entity IDs in this module.
name|ContinuousRangeMap
operator|<
name|uint32_t
operator|,
name|int
operator|,
literal|2
operator|>
name|PreprocessedEntityRemap
expr_stmt|;
specifier|const
name|PPEntityOffset
modifier|*
name|PreprocessedEntityOffsets
decl_stmt|;
name|unsigned
name|NumPreprocessedEntities
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
comment|// === Submodule information ===
comment|/// \brief The number of submodules in this module.
name|unsigned
name|LocalNumSubmodules
decl_stmt|;
comment|/// \brief Base submodule ID for submodules local to this module.
name|serialization
operator|::
name|SubmoduleID
name|BaseSubmoduleID
expr_stmt|;
comment|/// \brief Remapping table for submodule IDs in this module.
name|ContinuousRangeMap
operator|<
name|uint32_t
operator|,
name|int
operator|,
literal|2
operator|>
name|SubmoduleRemap
expr_stmt|;
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
comment|/// \brief Base selector ID for selectors local to this module.
name|serialization
operator|::
name|SelectorID
name|BaseSelectorID
expr_stmt|;
comment|/// \brief Remapping table for selector IDs in this module.
name|ContinuousRangeMap
operator|<
name|uint32_t
operator|,
name|int
operator|,
literal|2
operator|>
name|SelectorRemap
expr_stmt|;
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
name|DeclOffset
modifier|*
name|DeclOffsets
decl_stmt|;
comment|/// \brief Base declaration ID for declarations local to this module.
name|serialization
operator|::
name|DeclID
name|BaseDeclID
expr_stmt|;
comment|/// \brief Remapping table for declaration IDs in this module.
name|ContinuousRangeMap
operator|<
name|uint32_t
operator|,
name|int
operator|,
literal|2
operator|>
name|DeclRemap
expr_stmt|;
comment|/// \brief Mapping from the module files that this module file depends on
comment|/// to the base declaration ID for that module as it is understood within this
comment|/// module.
comment|///
comment|/// This is effectively a reverse global-to-local mapping for declaration
comment|/// IDs, so that we can interpret a true global ID (for this translation unit)
comment|/// as a local ID (for this module file).
name|llvm
operator|::
name|DenseMap
operator|<
name|ModuleFile
operator|*
operator|,
name|serialization
operator|::
name|DeclID
operator|>
name|GlobalToLocalDeclIDs
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
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|DeclContext
operator|*
operator|,
name|DeclContextInfo
operator|>
name|DeclContextInfosMap
expr_stmt|;
comment|/// \brief Information about the lexical and visible declarations
comment|/// for each DeclContext.
name|DeclContextInfosMap
name|DeclContextInfos
decl_stmt|;
comment|/// \brief Array of file-level DeclIDs sorted by file.
specifier|const
name|serialization
operator|::
name|DeclID
operator|*
name|FileSortedDecls
expr_stmt|;
name|unsigned
name|NumFileSortedDecls
decl_stmt|;
comment|/// \brief Array of redeclaration chain location information within this
comment|/// module file, sorted by the first declaration ID.
specifier|const
name|serialization
operator|::
name|LocalRedeclarationsInfo
operator|*
name|RedeclarationsMap
expr_stmt|;
comment|/// \brief The number of redeclaration info entries in RedeclarationsMap.
name|unsigned
name|LocalNumRedeclarationsInMap
decl_stmt|;
comment|/// \brief The redeclaration chains for declarations local to this
comment|/// module file.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|1
operator|>
name|RedeclarationChains
expr_stmt|;
comment|/// \brief Array of category list location information within this
comment|/// module file, sorted by the definition ID.
specifier|const
name|serialization
operator|::
name|ObjCCategoriesInfo
operator|*
name|ObjCCategoriesMap
expr_stmt|;
comment|/// \brief The number of redeclaration info entries in ObjCCategoriesMap.
name|unsigned
name|LocalNumObjCCategoriesInMap
decl_stmt|;
comment|/// \brief The Objective-C category lists for categories known to this
comment|/// module.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|1
operator|>
name|ObjCCategories
expr_stmt|;
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
comment|/// \brief Base type ID for types local to this module as represented in
comment|/// the global type ID space.
name|serialization
operator|::
name|TypeID
name|BaseTypeIndex
expr_stmt|;
comment|/// \brief Remapping table for type IDs in this module.
name|ContinuousRangeMap
operator|<
name|uint32_t
operator|,
name|int
operator|,
literal|2
operator|>
name|TypeRemap
expr_stmt|;
comment|// === Miscellaneous ===
comment|/// \brief Diagnostic IDs and their mappings that the user changed.
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|8
operator|>
name|PragmaDiagMappings
expr_stmt|;
comment|/// \brief List of modules which depend on this module
name|llvm
operator|::
name|SetVector
operator|<
name|ModuleFile
operator|*
operator|>
name|ImportedBy
expr_stmt|;
comment|/// \brief List of modules which this module depends on
name|llvm
operator|::
name|SetVector
operator|<
name|ModuleFile
operator|*
operator|>
name|Imports
expr_stmt|;
comment|/// \brief Determine whether this module was directly imported at
comment|/// any point during translation.
name|bool
name|isDirectlyImported
argument_list|()
specifier|const
block|{
return|return
name|DirectlyImported
return|;
block|}
comment|/// \brief Dump debugging output for this module.
name|void
name|dump
parameter_list|()
function_decl|;
block|}
empty_stmt|;
block|}
comment|// end namespace serialization
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

