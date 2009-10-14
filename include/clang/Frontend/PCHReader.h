begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- PCHReader.h - Precompiled Headers Reader ---------------*- C++ -*-===//
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
comment|//  This file defines the PCHReader class, which reads a precompiled header.
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
name|LLVM_CLANG_FRONTEND_PCH_READER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_PCH_READER_H
end_define

begin_include
include|#
directive|include
file|"clang/Frontend/PCHBitCodes.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclarationName.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/ExternalSemaSource.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclObjC.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
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
file|"llvm/ADT/DenseMap.h"
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
name|Attr
decl_stmt|;
name|class
name|Decl
decl_stmt|;
name|class
name|DeclContext
decl_stmt|;
name|class
name|GotoStmt
decl_stmt|;
name|class
name|LabelStmt
decl_stmt|;
name|class
name|NamedDecl
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
name|PCHReader
decl_stmt|;
struct_decl|struct
name|HeaderFileInfo
struct_decl|;
comment|/// \brief Abstract interface for callback invocations by the PCHReader.
comment|///
comment|/// While reading a PCH file, the PCHReader will call the methods of the
comment|/// listener to pass on specific information. Some of the listener methods can
comment|/// return true to indicate to the PCHReader that the information (and
comment|/// consequently the PCH file) is invalid.
name|class
name|PCHReaderListener
block|{
name|public
label|:
name|virtual
operator|~
name|PCHReaderListener
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
specifier|const
name|std
operator|::
name|string
operator|&
name|Triple
argument_list|)
block|{
return|return
name|false
return|;
block|}
comment|/// \brief Receives the contents of the predefines buffer.
comment|///
comment|/// \param PCHPredef The start of the predefines buffer in the PCH
comment|/// file.
comment|///
comment|/// \param PCHPredefLen The length of the predefines buffer in the PCH
comment|/// file.
comment|///
comment|/// \param PCHBufferID The FileID for the PCH predefines buffer.
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
name|char
operator|*
name|PCHPredef
argument_list|,
name|unsigned
name|PCHPredefLen
argument_list|,
name|FileID
name|PCHBufferID
argument_list|,
name|std
operator|::
name|string
operator|&
name|SuggestedPredefines
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
comment|/// \brief PCHReaderListener implementation to validate the information of
comment|/// the PCH file against an initialized Preprocessor.
name|class
name|PCHValidator
range|:
name|public
name|PCHReaderListener
block|{
name|Preprocessor
operator|&
name|PP
block|;
name|PCHReader
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
name|PCHReader
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
specifier|const
name|std
operator|::
name|string
operator|&
name|Triple
argument_list|)
block|;
name|virtual
name|bool
name|ReadPredefinesBuffer
argument_list|(
argument|const char *PCHPredef
argument_list|,
argument|unsigned PCHPredefLen
argument_list|,
argument|FileID PCHBufferID
argument_list|,
argument|std::string&SuggestedPredefines
argument_list|)
block|;
name|virtual
name|void
name|ReadHeaderFileInfo
argument_list|(
specifier|const
name|HeaderFileInfo
operator|&
name|HFI
argument_list|)
block|;
name|virtual
name|void
name|ReadCounter
argument_list|(
argument|unsigned Value
argument_list|)
block|; }
decl_stmt|;
comment|/// \brief Reads a precompiled head containing the contents of a
comment|/// translation unit.
comment|///
comment|/// The PCHReader class reads a bitstream (produced by the PCHWriter
comment|/// class) containing the serialized representation of a given
comment|/// abstract syntax tree and its supporting data structures. An
comment|/// instance of the PCHReader can be attached to an ASTContext object,
comment|/// which will provide access to the contents of the PCH file.
comment|///
comment|/// The PCH reader provides lazy de-serialization of declarations, as
comment|/// required when traversing the AST. Only those AST nodes that are
comment|/// actually required will be de-serialized.
name|class
name|PCHReader
range|:
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
name|PCHReadResult
block|{
name|Success
block|,
name|Failure
block|,
name|IgnorePCH
block|}
enum|;
name|private
label|:
comment|/// \ brief The receiver of some callbacks invoked by PCHReader.
name|llvm
operator|::
name|OwningPtr
operator|<
name|PCHReaderListener
operator|>
name|Listener
expr_stmt|;
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
comment|/// PCH file and the translation unit that uses it.
name|Sema
modifier|*
name|SemaObj
decl_stmt|;
comment|/// \brief The preprocessor that will be loading the source file.
name|Preprocessor
modifier|*
name|PP
decl_stmt|;
comment|/// \brief The AST context into which we'll read the PCH file.
name|ASTContext
modifier|*
name|Context
decl_stmt|;
comment|/// \brief The AST consumer.
name|ASTConsumer
modifier|*
name|Consumer
decl_stmt|;
comment|/// \brief The bitstream reader from which we'll read the PCH file.
name|llvm
operator|::
name|BitstreamReader
name|StreamFile
expr_stmt|;
name|llvm
operator|::
name|BitstreamCursor
name|Stream
expr_stmt|;
comment|/// DeclsCursor - This is a cursor to the start of the DECLS_BLOCK block.  It
comment|/// has read all the abbreviations at the start of the block and is ready to
comment|/// jump around with these in context.
name|llvm
operator|::
name|BitstreamCursor
name|DeclsCursor
expr_stmt|;
comment|/// \brief The file name of the PCH file.
name|std
operator|::
name|string
name|FileName
expr_stmt|;
comment|/// \brief The memory buffer that stores the data associated with
comment|/// this PCH file.
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
comment|/// \brief Offset type for all of the source location entries in the
comment|/// PCH file.
specifier|const
name|uint32_t
modifier|*
name|SLocOffsets
decl_stmt|;
comment|/// \brief The number of source location entries in the PCH file.
name|unsigned
name|TotalNumSLocEntries
decl_stmt|;
comment|/// \brief Cursor used to read source location entries.
name|llvm
operator|::
name|BitstreamCursor
name|SLocEntryCursor
expr_stmt|;
comment|/// \brief Offset of each type within the bitstream, indexed by the
comment|/// type ID, or the representation of a Type*.
specifier|const
name|uint32_t
modifier|*
name|TypeOffsets
decl_stmt|;
comment|/// \brief Types that have already been loaded from the PCH file.
comment|///
comment|/// When the pointer at index I is non-NULL, the type with
comment|/// ID = (I + 1)<< 3 has already been loaded from the PCH file.
name|std
operator|::
name|vector
operator|<
name|QualType
operator|>
name|TypesLoaded
expr_stmt|;
comment|/// \brief Offset of each declaration within the bitstream, indexed
comment|/// by the declaration ID (-1).
specifier|const
name|uint32_t
modifier|*
name|DeclOffsets
decl_stmt|;
comment|/// \brief Declarations that have already been loaded from the PCH file.
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
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|DeclContext
operator|*
operator|,
name|std
operator|::
name|pair
operator|<
name|uint64_t
operator|,
name|uint64_t
operator|>
expr|>
name|DeclContextOffsetsMap
expr_stmt|;
comment|/// \brief Offsets of the lexical and visible declarations for each
comment|/// DeclContext.
name|DeclContextOffsetsMap
name|DeclContextOffsets
decl_stmt|;
comment|/// \brief Actual data for the on-disk hash table.
comment|///
comment|// This pointer points into a memory buffer, where the on-disk hash
comment|// table for identifiers actually lives.
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
comment|/// \brief A pointer to an on-disk hash table of opaque type
comment|/// PCHMethodPoolLookupTable.
comment|///
comment|/// This hash table provides the instance and factory methods
comment|/// associated with every selector known in the PCH file.
name|void
modifier|*
name|MethodPoolLookupTable
decl_stmt|;
comment|/// \brief A pointer to the character data that comprises the method
comment|/// pool.
comment|///
comment|/// The SelectorOffsets table refers into this memory.
specifier|const
name|unsigned
name|char
modifier|*
name|MethodPoolLookupTableData
decl_stmt|;
comment|/// \brief The number of selectors stored in the method pool itself.
name|unsigned
name|TotalSelectorsInMethodPool
decl_stmt|;
comment|/// \brief Offsets into the method pool lookup table's data array
comment|/// where each selector resides.
specifier|const
name|uint32_t
modifier|*
name|SelectorOffsets
decl_stmt|;
comment|/// \brief The total number of selectors stored in the PCH file.
name|unsigned
name|TotalNumSelectors
decl_stmt|;
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
comment|/// \brief A sorted array of source ranges containing comments.
name|SourceRange
modifier|*
name|Comments
decl_stmt|;
comment|/// \brief The number of source ranges in the Comments array.
name|unsigned
name|NumComments
decl_stmt|;
comment|/// \brief The set of external definitions stored in the the PCH
comment|/// file.
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
comment|/// \brief The set of tentative definitions stored in the the PCH
comment|/// file.
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
comment|/// \brief The set of locally-scoped external declarations stored in
comment|/// the the PCH file.
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
comment|/// \brief The set of ext_vector type declarations stored in the the
comment|/// PCH file.
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
comment|/// \brief The set of Objective-C category definitions stored in the
comment|/// the PCH file.
name|llvm
operator|::
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|4
operator|>
name|ObjCCategoryImpls
expr_stmt|;
comment|/// \brief The original file name that was used to build the PCH
comment|/// file.
name|std
operator|::
name|string
name|OriginalFileName
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
comment|/// \brief Mapping from switch-case IDs in the PCH file to
comment|/// switch-case statements.
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
comment|/// \brief Mapping from label statement IDs in the PCH file to label
comment|/// statements.
name|std
operator|::
name|map
operator|<
name|unsigned
operator|,
name|LabelStmt
operator|*
operator|>
name|LabelStmts
expr_stmt|;
comment|/// \brief Mapping from label IDs to the set of "goto" statements
comment|/// that point to that label before the label itself has been
comment|/// de-serialized.
name|std
operator|::
name|multimap
operator|<
name|unsigned
operator|,
name|GotoStmt
operator|*
operator|>
name|UnresolvedGotoStmts
expr_stmt|;
comment|/// \brief Mapping from label IDs to the set of address label
comment|/// expressions that point to that label before the label itself has
comment|/// been de-serialized.
name|std
operator|::
name|multimap
operator|<
name|unsigned
operator|,
name|AddrLabelExpr
operator|*
operator|>
name|UnresolvedAddrLabelExprs
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
comment|/// \brief The number of statements (and expressions) de-serialized
comment|/// from the PCH file.
name|unsigned
name|NumStatementsRead
decl_stmt|;
comment|/// \brief The total number of statements (and expressions) stored
comment|/// in the PCH file.
name|unsigned
name|TotalNumStatements
decl_stmt|;
comment|/// \brief The number of macros de-serialized from the PCH file.
name|unsigned
name|NumMacrosRead
decl_stmt|;
comment|/// \brief The number of method pool entries that have been read.
name|unsigned
name|NumMethodPoolSelectorsRead
decl_stmt|;
comment|/// \brief The number of times we have looked into the global method
comment|/// pool and not found anything.
name|unsigned
name|NumMethodPoolMisses
decl_stmt|;
comment|/// \brief The total number of macros stored in the PCH file.
name|unsigned
name|TotalNumMacros
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
comment|/// \brief When a type or declaration is being loaded from the PCH file, an
comment|/// instantance of this RAII object will be available on the stack to
comment|/// indicate when we are in a recursive-loading situation.
name|class
name|LoadingTypeOrDecl
block|{
name|PCHReader
modifier|&
name|Reader
decl_stmt|;
name|LoadingTypeOrDecl
modifier|*
name|Parent
decl_stmt|;
name|LoadingTypeOrDecl
argument_list|(
specifier|const
name|LoadingTypeOrDecl
operator|&
argument_list|)
expr_stmt|;
comment|// do not implement
name|LoadingTypeOrDecl
modifier|&
name|operator
init|=
operator|(
specifier|const
name|LoadingTypeOrDecl
operator|&
operator|)
decl_stmt|;
comment|// do not implement
name|public
label|:
name|explicit
name|LoadingTypeOrDecl
parameter_list|(
name|PCHReader
modifier|&
name|Reader
parameter_list|)
function_decl|;
operator|~
name|LoadingTypeOrDecl
argument_list|()
expr_stmt|;
block|}
empty_stmt|;
name|friend
name|class
name|LoadingTypeOrDecl
decl_stmt|;
comment|/// \brief If we are currently loading a type or declaration, points to the
comment|/// most recent LoadingTypeOrDecl object on the stack.
name|LoadingTypeOrDecl
modifier|*
name|CurrentlyLoadingTypeOrDecl
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
comment|/// \brief The set of identifiers that were read while the PCH reader was
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
comment|/// \brief FIXME: document!
name|llvm
operator|::
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|4
operator|>
name|SpecialTypes
expr_stmt|;
comment|/// \brief Contains declarations and definitions that will be
comment|/// "interesting" to the ASTConsumer, when we get that AST consumer.
comment|///
comment|/// "Interesting" declarations are those that have data that may
comment|/// need to be emitted, such as inline function definitions or
comment|/// Objective-C protocols.
name|llvm
operator|::
name|SmallVector
operator|<
name|Decl
operator|*
operator|,
literal|16
operator|>
name|InterestingDecls
expr_stmt|;
comment|/// \brief The file ID for the predefines buffer in the PCH file.
name|FileID
name|PCHPredefinesBufferID
decl_stmt|;
comment|/// \brief Pointer to the beginning of the predefines buffer in the
comment|/// PCH file.
specifier|const
name|char
modifier|*
name|PCHPredefines
decl_stmt|;
comment|/// \brief Length of the predefines buffer in the PCH file.
name|unsigned
name|PCHPredefinesLen
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
name|PCHReadResult
name|ReadPCHBlock
parameter_list|()
function_decl|;
name|bool
name|CheckPredefinesBuffer
parameter_list|(
specifier|const
name|char
modifier|*
name|PCHPredef
parameter_list|,
name|unsigned
name|PCHPredefLen
parameter_list|,
name|FileID
name|PCHBufferID
parameter_list|)
function_decl|;
name|bool
name|ParseLineTable
argument_list|(
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
name|PCHReadResult
name|ReadSourceManagerBlock
parameter_list|()
function_decl|;
name|PCHReadResult
name|ReadSLocEntryRecord
parameter_list|(
name|unsigned
name|ID
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
name|QualType
name|ReadTypeRecord
parameter_list|(
name|uint64_t
name|Offset
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
parameter_list|(
name|uint64_t
name|Offset
parameter_list|,
name|unsigned
name|Index
parameter_list|)
function_decl|;
comment|/// \brief Produce an error diagnostic and return true.
comment|///
comment|/// This routine should only be used for fatal errors that have to
comment|/// do with non-routine failures (e.g., corrupted PCH file).
name|bool
name|Error
parameter_list|(
specifier|const
name|char
modifier|*
name|Msg
parameter_list|)
function_decl|;
name|PCHReader
argument_list|(
specifier|const
name|PCHReader
operator|&
argument_list|)
expr_stmt|;
comment|// do not implement
name|PCHReader
modifier|&
name|operator
init|=
operator|(
specifier|const
name|PCHReader
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
comment|/// \brief Load the PCH file and validate its contents against the given
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
name|PCHReader
argument_list|(
name|Preprocessor
operator|&
name|PP
argument_list|,
name|ASTContext
operator|*
name|Context
argument_list|,
specifier|const
name|char
operator|*
name|isysroot
operator|=
literal|0
argument_list|)
expr_stmt|;
comment|/// \brief Load the PCH file without using any pre-initialized Preprocessor.
comment|///
comment|/// The necessary information to initialize a Preprocessor later can be
comment|/// obtained by setting a PCHReaderListener.
comment|///
comment|/// \param SourceMgr the source manager into which the precompiled header
comment|/// will be loaded.
comment|///
comment|/// \param FileMgr the file manager into which the precompiled header will
comment|/// be loaded.
comment|///
comment|/// \param Diags the diagnostics system to use for reporting errors and
comment|/// warnings relevant to loading the precompiled header.
comment|///
comment|/// \param isysroot If non-NULL, the system include path specified by the
comment|/// user. This is only used with relocatable PCH files. If non-NULL,
comment|/// a relocatable PCH file will use the default path "/".
name|PCHReader
argument_list|(
name|SourceManager
operator|&
name|SourceMgr
argument_list|,
name|FileManager
operator|&
name|FileMgr
argument_list|,
name|Diagnostic
operator|&
name|Diags
argument_list|,
specifier|const
name|char
operator|*
name|isysroot
operator|=
literal|0
argument_list|)
expr_stmt|;
operator|~
name|PCHReader
argument_list|()
expr_stmt|;
comment|/// \brief Load the precompiled header designated by the given file
comment|/// name.
name|PCHReadResult
name|ReadPCH
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|FileName
argument_list|)
decl_stmt|;
comment|/// \brief Set the PCH callbacks listener.
name|void
name|setListener
parameter_list|(
name|PCHReaderListener
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
comment|/// \brief Set the Preprocessor to use.
name|void
name|setPreprocessor
parameter_list|(
name|Preprocessor
modifier|&
name|pp
parameter_list|)
block|{
name|PP
operator|=
operator|&
name|pp
expr_stmt|;
block|}
comment|/// \brief Sets and initializes the given Context.
name|void
name|InitializeContext
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|)
function_decl|;
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
comment|/// \brief Retrieve the name of the original source file name
comment|/// directly from the PCH file, without actually loading the PCH
comment|/// file.
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
name|PCHFileName
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
comment|/// \brief Reads the source ranges that correspond to comments from
comment|/// an external AST source.
comment|///
comment|/// \param Comments the contents of this vector will be
comment|/// replaced with the sorted set of source ranges corresponding to
comment|/// comments in the source code.
name|virtual
name|void
name|ReadComments
argument_list|(
name|std
operator|::
name|vector
operator|<
name|SourceRange
operator|>
operator|&
name|Comments
argument_list|)
decl_stmt|;
comment|/// \brief Resolve a type ID into a type, potentially building a new
comment|/// type.
name|virtual
name|QualType
name|GetType
argument_list|(
name|pch
operator|::
name|TypeID
name|ID
argument_list|)
decl_stmt|;
comment|/// \brief Resolve a declaration ID into a declaration, potentially
comment|/// building a new declaration.
name|virtual
name|Decl
modifier|*
name|GetDecl
argument_list|(
name|pch
operator|::
name|DeclID
name|ID
argument_list|)
decl_stmt|;
comment|/// \brief Resolve the offset of a statement into a statement.
comment|///
comment|/// This operation will read a new statement from the external
comment|/// source each time it is called, and is meant to be used via a
comment|/// LazyOffsetPtr (which is used by Decls for the body of functions, etc).
name|virtual
name|Stmt
modifier|*
name|GetDeclStmt
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
name|ReadDeclsLexicallyInContext
argument_list|(
name|DeclContext
operator|*
name|DC
argument_list|,
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|pch
operator|::
name|DeclID
operator|>
operator|&
name|Decls
argument_list|)
decl_stmt|;
comment|/// \brief Read all of the declarations visible from a declaration
comment|/// context.
comment|///
comment|/// \param DC The declaration context whose visible declarations
comment|/// will be read.
comment|///
comment|/// \param Decls A vector of visible declaration structures,
comment|/// providing the mapping from each name visible in the declaration
comment|/// context to the declaration IDs of declarations with that name.
comment|///
comment|/// \returns true if there was an error while reading the
comment|/// declarations for this declaration context.
comment|///
comment|/// FIXME: Using this intermediate data structure results in an
comment|/// extraneous copying of the data. Could we pass in a reference to
comment|/// the StoredDeclsMap instead?
name|virtual
name|bool
name|ReadDeclsVisibleInContext
argument_list|(
name|DeclContext
operator|*
name|DC
argument_list|,
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
comment|/// \brief Print some statistics about PCH usage.
name|virtual
name|void
name|PrintStats
parameter_list|()
function_decl|;
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
comment|/// \brief Retrieve the IdentifierInfo for the named identifier.
comment|///
comment|/// This routine builds a new IdentifierInfo for the given
comment|/// identifier. If any declarations with this name are visible from
comment|/// translation unit scope, their declarations will be deserialized
comment|/// and introduced into the declaration chain of the
comment|/// identifier. FIXME: if this identifier names a macro, deserialize
comment|/// the macro.
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
name|void
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
comment|/// \brief Reads attributes from the current stream position.
name|Attr
modifier|*
name|ReadAttributes
parameter_list|()
function_decl|;
comment|/// \brief ReadDeclExpr - Reads an expression from the current decl cursor.
name|Expr
modifier|*
name|ReadDeclExpr
parameter_list|()
function_decl|;
comment|/// \brief ReadTypeExpr - Reads an expression from the current type cursor.
name|Expr
modifier|*
name|ReadTypeExpr
parameter_list|()
function_decl|;
comment|/// \brief Reads a statement from the specified cursor.
name|Stmt
modifier|*
name|ReadStmt
argument_list|(
name|llvm
operator|::
name|BitstreamCursor
operator|&
name|Cursor
argument_list|)
decl_stmt|;
comment|/// \brief Read a statement from the current DeclCursor.
name|Stmt
modifier|*
name|ReadDeclStmt
parameter_list|()
block|{
return|return
name|ReadStmt
argument_list|(
name|DeclsCursor
argument_list|)
return|;
block|}
comment|/// \brief Reads the macro record located at the given offset.
name|void
name|ReadMacroRecord
parameter_list|(
name|uint64_t
name|Offset
parameter_list|)
function_decl|;
comment|/// \brief Retrieve the AST context that this PCH reader
comment|/// supplements.
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
comment|/// \brief Retrieve the stream that this PCH reader is reading from.
name|llvm
operator|::
name|BitstreamCursor
operator|&
name|getStream
argument_list|()
block|{
return|return
name|Stream
return|;
block|}
name|llvm
operator|::
name|BitstreamCursor
operator|&
name|getDeclsCursor
argument_list|()
block|{
return|return
name|DeclsCursor
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
comment|/// \brief Record that the given label statement has been
comment|/// deserialized and has the given ID.
name|void
name|RecordLabelStmt
parameter_list|(
name|LabelStmt
modifier|*
name|S
parameter_list|,
name|unsigned
name|ID
parameter_list|)
function_decl|;
comment|/// \brief Set the label of the given statement to the label
comment|/// identified by ID.
comment|///
comment|/// Depending on the order in which the label and other statements
comment|/// referencing that label occur, this operation may complete
comment|/// immediately (updating the statement) or it may queue the
comment|/// statement to be back-patched later.
name|void
name|SetLabelOf
parameter_list|(
name|GotoStmt
modifier|*
name|S
parameter_list|,
name|unsigned
name|ID
parameter_list|)
function_decl|;
comment|/// \brief Set the label of the given expression to the label
comment|/// identified by ID.
comment|///
comment|/// Depending on the order in which the label and other statements
comment|/// referencing that label occur, this operation may complete
comment|/// immediately (updating the statement) or it may queue the
comment|/// statement to be back-patched later.
name|void
name|SetLabelOf
parameter_list|(
name|AddrLabelExpr
modifier|*
name|S
parameter_list|,
name|unsigned
name|ID
parameter_list|)
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

