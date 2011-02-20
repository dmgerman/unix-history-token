begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ASTWriter.h - AST File Writer --------------------------*- C++ -*-===//
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
comment|//  This file defines the ASTWriter class, which writes an AST file
end_comment

begin_comment
comment|//  containing a serialized representation of a translation unit.
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
name|LLVM_CLANG_FRONTEND_AST_WRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_AST_WRITER_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Decl.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/DeclarationName.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/TemplateBase.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/ASTMutationListener.h"
end_include

begin_include
include|#
directive|include
file|"clang/Serialization/ASTBitCodes.h"
end_include

begin_include
include|#
directive|include
file|"clang/Serialization/ASTDeserializationListener.h"
end_include

begin_include
include|#
directive|include
file|"clang/Sema/SemaConsumer.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallPtrSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Bitcode/BitstreamWriter.h"
end_include

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<queue>
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
name|APFloat
decl_stmt|;
name|class
name|APInt
decl_stmt|;
name|class
name|BitstreamWriter
decl_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ASTContext
decl_stmt|;
name|class
name|ASTSerializationListener
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
name|FPOptions
decl_stmt|;
name|class
name|HeaderSearch
decl_stmt|;
name|class
name|MacroDefinition
decl_stmt|;
name|class
name|MemorizeStatCalls
decl_stmt|;
name|class
name|OpaqueValueExpr
decl_stmt|;
name|class
name|OpenCLOptions
decl_stmt|;
name|class
name|ASTReader
decl_stmt|;
name|class
name|PreprocessedEntity
decl_stmt|;
name|class
name|PreprocessingRecord
decl_stmt|;
name|class
name|Preprocessor
decl_stmt|;
name|class
name|Sema
decl_stmt|;
name|class
name|SourceManager
decl_stmt|;
name|class
name|SwitchCase
decl_stmt|;
name|class
name|TargetInfo
decl_stmt|;
comment|/// \brief Writes an AST file containing the contents of a translation unit.
comment|///
comment|/// The ASTWriter class produces a bitstream containing the serialized
comment|/// representation of a given abstract syntax tree and its supporting
comment|/// data structures. This bitstream can be de-serialized via an
comment|/// instance of the ASTReader class.
name|class
name|ASTWriter
range|:
name|public
name|ASTDeserializationListener
decl_stmt|,
name|public
name|ASTMutationListener
block|{
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
typedef|typedef
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|uint64_t
operator|>
name|RecordDataImpl
expr_stmt|;
name|friend
name|class
name|ASTDeclWriter
decl_stmt|;
name|private
label|:
comment|/// \brief The bitstream writer used to emit this precompiled header.
name|llvm
operator|::
name|BitstreamWriter
operator|&
name|Stream
expr_stmt|;
comment|/// \brief The reader of existing AST files, if we're chaining.
name|ASTReader
modifier|*
name|Chain
decl_stmt|;
comment|/// \brief A listener object that receives notifications when certain
comment|/// entities are serialized.
name|ASTSerializationListener
modifier|*
name|SerializationListener
decl_stmt|;
comment|/// \brief Stores a declaration or a type to be written to the AST file.
name|class
name|DeclOrType
block|{
name|public
label|:
name|DeclOrType
argument_list|(
name|Decl
operator|*
name|D
argument_list|)
operator|:
name|Stored
argument_list|(
name|D
argument_list|)
operator|,
name|IsType
argument_list|(
argument|false
argument_list|)
block|{ }
name|DeclOrType
argument_list|(
argument|QualType T
argument_list|)
operator|:
name|Stored
argument_list|(
name|T
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
operator|,
name|IsType
argument_list|(
argument|true
argument_list|)
block|{ }
name|bool
name|isType
argument_list|()
specifier|const
block|{
return|return
name|IsType
return|;
block|}
name|bool
name|isDecl
argument_list|()
specifier|const
block|{
return|return
operator|!
name|IsType
return|;
block|}
name|QualType
name|getType
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isType
argument_list|()
operator|&&
literal|"Not a type!"
argument_list|)
block|;
return|return
name|QualType
operator|::
name|getFromOpaquePtr
argument_list|(
name|Stored
argument_list|)
return|;
block|}
name|Decl
operator|*
name|getDecl
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|isDecl
argument_list|()
operator|&&
literal|"Not a decl!"
argument_list|)
block|;
return|return
name|static_cast
operator|<
name|Decl
operator|*
operator|>
operator|(
name|Stored
operator|)
return|;
block|}
name|private
label|:
name|void
modifier|*
name|Stored
decl_stmt|;
name|bool
name|IsType
decl_stmt|;
block|}
empty_stmt|;
comment|/// \brief The declarations and types to emit.
name|std
operator|::
name|queue
operator|<
name|DeclOrType
operator|>
name|DeclTypesToEmit
expr_stmt|;
comment|/// \brief The first ID number we can use for our own declarations.
name|serialization
operator|::
name|DeclID
name|FirstDeclID
expr_stmt|;
comment|/// \brief The decl ID that will be assigned to the next new decl.
name|serialization
operator|::
name|DeclID
name|NextDeclID
expr_stmt|;
comment|/// \brief Map that provides the ID numbers of each declaration within
comment|/// the output stream, as well as those deserialized from a chained PCH.
comment|///
comment|/// The ID numbers of declarations are consecutive (in order of
comment|/// discovery) and start at 2. 1 is reserved for the translation
comment|/// unit, while 0 is reserved for NULL.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|serialization
operator|::
name|DeclID
operator|>
name|DeclIDs
expr_stmt|;
comment|/// \brief Offset of each declaration in the bitstream, indexed by
comment|/// the declaration's ID.
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|DeclOffsets
expr_stmt|;
comment|/// \brief The first ID number we can use for our own types.
name|serialization
operator|::
name|TypeID
name|FirstTypeID
expr_stmt|;
comment|/// \brief The type ID that will be assigned to the next new type.
name|serialization
operator|::
name|TypeID
name|NextTypeID
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
comment|/// \brief Offset of each type in the bitstream, indexed by
comment|/// the type's ID.
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|TypeOffsets
expr_stmt|;
comment|/// \brief The first ID number we can use for our own identifiers.
name|serialization
operator|::
name|IdentID
name|FirstIdentID
expr_stmt|;
comment|/// \brief The identifier ID that will be assigned to the next new identifier.
name|serialization
operator|::
name|IdentID
name|NextIdentID
expr_stmt|;
comment|/// \brief Map that provides the ID numbers of each identifier in
comment|/// the output stream.
comment|///
comment|/// The ID numbers for identifiers are consecutive (in order of
comment|/// discovery), starting at 1. An ID of zero refers to a NULL
comment|/// IdentifierInfo.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|IdentifierInfo
operator|*
operator|,
name|serialization
operator|::
name|IdentID
operator|>
name|IdentifierIDs
expr_stmt|;
comment|/// \brief Offsets of each of the identifier IDs into the identifier
comment|/// table.
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|IdentifierOffsets
expr_stmt|;
comment|/// \brief The first ID number we can use for our own selectors.
name|serialization
operator|::
name|SelectorID
name|FirstSelectorID
expr_stmt|;
comment|/// \brief The selector ID that will be assigned to the next new identifier.
name|serialization
operator|::
name|SelectorID
name|NextSelectorID
expr_stmt|;
comment|/// \brief Map that provides the ID numbers of each Selector.
name|llvm
operator|::
name|DenseMap
operator|<
name|Selector
operator|,
name|serialization
operator|::
name|SelectorID
operator|>
name|SelectorIDs
expr_stmt|;
comment|/// \brief Offset of each selector within the method pool/selector
comment|/// table, indexed by the Selector ID (-1).
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|SelectorOffsets
expr_stmt|;
comment|/// \brief Offsets of each of the macro identifiers into the
comment|/// bitstream.
comment|///
comment|/// For each identifier that is associated with a macro, this map
comment|/// provides the offset into the bitstream where that macro is
comment|/// defined.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|IdentifierInfo
operator|*
operator|,
name|uint64_t
operator|>
name|MacroOffsets
expr_stmt|;
comment|/// \brief The set of identifiers that had macro definitions at some point.
name|std
operator|::
name|vector
operator|<
specifier|const
name|IdentifierInfo
operator|*
operator|>
name|DeserializedMacroNames
expr_stmt|;
comment|/// \brief The first ID number we can use for our own macro definitions.
name|serialization
operator|::
name|MacroID
name|FirstMacroID
expr_stmt|;
comment|/// \brief The decl ID that will be assigned to the next new macro definition.
name|serialization
operator|::
name|MacroID
name|NextMacroID
expr_stmt|;
comment|/// \brief Mapping from macro definitions (as they occur in the preprocessing
comment|/// record) to the macro IDs.
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|MacroDefinition
operator|*
operator|,
name|serialization
operator|::
name|MacroID
operator|>
name|MacroDefinitions
expr_stmt|;
comment|/// \brief Mapping from the macro definition indices in \c MacroDefinitions
comment|/// to the corresponding offsets within the preprocessor block.
name|std
operator|::
name|vector
operator|<
name|uint32_t
operator|>
name|MacroDefinitionOffsets
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|SmallVector
operator|<
name|uint64_t
operator|,
literal|2
operator|>
name|UpdateRecord
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
specifier|const
name|Decl
operator|*
operator|,
name|UpdateRecord
operator|>
name|DeclUpdateMap
expr_stmt|;
comment|/// \brief Mapping from declarations that came from a chained PCH to the
comment|/// record containing modifications to them.
name|DeclUpdateMap
name|DeclUpdates
decl_stmt|;
typedef|typedef
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
name|FirstLatestDeclMap
expr_stmt|;
comment|/// \brief Map of first declarations from a chained PCH that point to the
comment|/// most recent declarations in another PCH.
name|FirstLatestDeclMap
name|FirstLatestDecls
decl_stmt|;
comment|/// \brief Declarations encountered that might be external
comment|/// definitions.
comment|///
comment|/// We keep track of external definitions (as well as tentative
comment|/// definitions) as we are emitting declarations to the AST
comment|/// file. The AST file contains a separate record for these external
comment|/// definitions, which are provided to the AST consumer by the AST
comment|/// reader. This is behavior is required to properly cope with,
comment|/// e.g., tentative variable definitions that occur within
comment|/// headers. The declarations themselves are stored as declaration
comment|/// IDs, since they will be written out to an EXTERNAL_DEFINITIONS
comment|/// record.
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
comment|/// \brief DeclContexts that have received extensions since their serialized
comment|/// form.
comment|///
comment|/// For namespaces, when we're chaining and encountering a namespace, we check if
comment|/// its primary namespace comes from the chain. If it does, we add the primary
comment|/// to this set, so that we can write out lexical content updates for it.
name|llvm
operator|::
name|SmallPtrSet
operator|<
specifier|const
name|DeclContext
operator|*
operator|,
literal|16
operator|>
name|UpdatedDeclContexts
expr_stmt|;
typedef|typedef
name|llvm
operator|::
name|SmallPtrSet
operator|<
specifier|const
name|Decl
operator|*
operator|,
literal|16
operator|>
name|DeclsToRewriteTy
expr_stmt|;
comment|/// \brief Decls that will be replaced in the current dependent AST file.
name|DeclsToRewriteTy
name|DeclsToRewrite
decl_stmt|;
comment|/// \brief Decls that have been replaced in the current dependent AST file.
comment|///
comment|/// When a decl changes fundamentally after being deserialized (this shouldn't
comment|/// happen, but the ObjC AST nodes are designed this way), it will be
comment|/// serialized again. In this case, it is registered here, so that the reader
comment|/// knows to read the updated version.
name|llvm
operator|::
name|SmallVector
operator|<
name|std
operator|::
name|pair
operator|<
name|serialization
operator|::
name|DeclID
operator|,
name|uint64_t
operator|>
operator|,
literal|16
operator|>
name|ReplacedDecls
expr_stmt|;
comment|/// \brief Statements that we've encountered while serializing a
comment|/// declaration or type.
name|llvm
operator|::
name|SmallVector
operator|<
name|Stmt
operator|*
operator|,
literal|16
operator|>
name|StmtsToEmit
expr_stmt|;
comment|/// \brief Statements collection to use for ASTWriter::AddStmt().
comment|/// It will point to StmtsToEmit unless it is overriden.
name|llvm
operator|::
name|SmallVector
operator|<
name|Stmt
operator|*
operator|,
literal|16
operator|>
operator|*
name|CollectedStmts
expr_stmt|;
comment|/// \brief Mapping from SwitchCase statements to IDs.
name|std
operator|::
name|map
operator|<
name|SwitchCase
operator|*
operator|,
name|unsigned
operator|>
name|SwitchCaseIDs
expr_stmt|;
comment|/// \brief Mapping from OpaqueValueExpr expressions to IDs.
name|llvm
operator|::
name|DenseMap
operator|<
name|OpaqueValueExpr
operator|*
operator|,
name|unsigned
operator|>
name|OpaqueValues
expr_stmt|;
comment|/// \brief The number of statements written to the AST file.
name|unsigned
name|NumStatements
decl_stmt|;
comment|/// \brief The number of macros written to the AST file.
name|unsigned
name|NumMacros
decl_stmt|;
comment|/// \brief The number of lexical declcontexts written to the AST
comment|/// file.
name|unsigned
name|NumLexicalDeclContexts
decl_stmt|;
comment|/// \brief The number of visible declcontexts written to the AST
comment|/// file.
name|unsigned
name|NumVisibleDeclContexts
decl_stmt|;
comment|/// \brief The offset of each CXXBaseSpecifier set within the AST.
name|llvm
operator|::
name|SmallVector
operator|<
name|uint32_t
operator|,
literal|4
operator|>
name|CXXBaseSpecifiersOffsets
expr_stmt|;
comment|/// \brief The first ID number we can use for our own base specifiers.
name|serialization
operator|::
name|CXXBaseSpecifiersID
name|FirstCXXBaseSpecifiersID
expr_stmt|;
comment|/// \brief The base specifiers ID that will be assigned to the next new
comment|/// set of C++ base specifiers.
name|serialization
operator|::
name|CXXBaseSpecifiersID
name|NextCXXBaseSpecifiersID
expr_stmt|;
comment|/// \brief A set of C++ base specifiers that is queued to be written into the
comment|/// AST file.
struct|struct
name|QueuedCXXBaseSpecifiers
block|{
name|QueuedCXXBaseSpecifiers
argument_list|()
operator|:
name|ID
argument_list|()
operator|,
name|Bases
argument_list|()
operator|,
name|BasesEnd
argument_list|()
block|{ }
name|QueuedCXXBaseSpecifiers
argument_list|(
argument|serialization::CXXBaseSpecifiersID ID
argument_list|,
argument|CXXBaseSpecifier const *Bases
argument_list|,
argument|CXXBaseSpecifier const *BasesEnd
argument_list|)
operator|:
name|ID
argument_list|(
name|ID
argument_list|)
operator|,
name|Bases
argument_list|(
name|Bases
argument_list|)
operator|,
name|BasesEnd
argument_list|(
argument|BasesEnd
argument_list|)
block|{ }
name|serialization
operator|::
name|CXXBaseSpecifiersID
name|ID
expr_stmt|;
name|CXXBaseSpecifier
specifier|const
modifier|*
name|Bases
decl_stmt|;
name|CXXBaseSpecifier
specifier|const
modifier|*
name|BasesEnd
decl_stmt|;
block|}
struct|;
comment|/// \brief Queue of C++ base specifiers to be written to the AST file,
comment|/// in the order they should be written.
name|llvm
operator|::
name|SmallVector
operator|<
name|QueuedCXXBaseSpecifiers
operator|,
literal|2
operator|>
name|CXXBaseSpecifiersToWrite
expr_stmt|;
comment|/// \brief Write the given subexpression to the bitstream.
name|void
name|WriteSubStmt
parameter_list|(
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
name|void
name|WriteBlockInfoBlock
parameter_list|()
function_decl|;
name|void
name|WriteMetadata
argument_list|(
name|ASTContext
operator|&
name|Context
argument_list|,
specifier|const
name|char
operator|*
name|isysroot
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|OutputFile
argument_list|)
decl_stmt|;
name|void
name|WriteLanguageOptions
parameter_list|(
specifier|const
name|LangOptions
modifier|&
name|LangOpts
parameter_list|)
function_decl|;
name|void
name|WriteStatCache
parameter_list|(
name|MemorizeStatCalls
modifier|&
name|StatCalls
parameter_list|)
function_decl|;
name|void
name|WriteSourceManagerBlock
parameter_list|(
name|SourceManager
modifier|&
name|SourceMgr
parameter_list|,
specifier|const
name|Preprocessor
modifier|&
name|PP
parameter_list|,
specifier|const
name|char
modifier|*
name|isysroot
parameter_list|)
function_decl|;
name|void
name|WritePreprocessor
parameter_list|(
specifier|const
name|Preprocessor
modifier|&
name|PP
parameter_list|)
function_decl|;
name|void
name|WriteHeaderSearch
parameter_list|(
name|HeaderSearch
modifier|&
name|HS
parameter_list|,
specifier|const
name|char
modifier|*
name|isysroot
parameter_list|)
function_decl|;
name|void
name|WritePreprocessorDetail
parameter_list|(
name|PreprocessingRecord
modifier|&
name|PPRec
parameter_list|)
function_decl|;
name|void
name|WritePragmaDiagnosticMappings
parameter_list|(
specifier|const
name|Diagnostic
modifier|&
name|Diag
parameter_list|)
function_decl|;
name|void
name|WriteType
parameter_list|(
name|QualType
name|T
parameter_list|)
function_decl|;
name|uint64_t
name|WriteDeclContextLexicalBlock
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|)
function_decl|;
name|uint64_t
name|WriteDeclContextVisibleBlock
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|DeclContext
modifier|*
name|DC
parameter_list|)
function_decl|;
name|void
name|WriteTypeDeclOffsets
parameter_list|()
function_decl|;
name|void
name|WriteSelectors
parameter_list|(
name|Sema
modifier|&
name|SemaRef
parameter_list|)
function_decl|;
name|void
name|WriteReferencedSelectorsPool
parameter_list|(
name|Sema
modifier|&
name|SemaRef
parameter_list|)
function_decl|;
name|void
name|WriteIdentifierTable
parameter_list|(
name|Preprocessor
modifier|&
name|PP
parameter_list|)
function_decl|;
name|void
name|WriteAttributes
parameter_list|(
specifier|const
name|AttrVec
modifier|&
name|Attrs
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
name|void
name|WriteDeclUpdatesBlocks
parameter_list|()
function_decl|;
name|void
name|WriteDeclReplacementsBlock
parameter_list|()
function_decl|;
name|void
name|WriteDeclContextVisibleUpdate
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|DC
parameter_list|)
function_decl|;
name|void
name|WriteFPPragmaOptions
parameter_list|(
specifier|const
name|FPOptions
modifier|&
name|Opts
parameter_list|)
function_decl|;
name|void
name|WriteOpenCLExtensions
parameter_list|(
name|Sema
modifier|&
name|SemaRef
parameter_list|)
function_decl|;
name|unsigned
name|ParmVarDeclAbbrev
decl_stmt|;
name|unsigned
name|DeclContextLexicalAbbrev
decl_stmt|;
name|unsigned
name|DeclContextVisibleLookupAbbrev
decl_stmt|;
name|unsigned
name|UpdateVisibleAbbrev
decl_stmt|;
name|void
name|WriteDeclsBlockAbbrevs
parameter_list|()
function_decl|;
name|void
name|WriteDecl
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
name|void
name|WriteASTCore
argument_list|(
name|Sema
operator|&
name|SemaRef
argument_list|,
name|MemorizeStatCalls
operator|*
name|StatCalls
argument_list|,
specifier|const
name|char
operator|*
name|isysroot
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|OutputFile
argument_list|)
decl_stmt|;
name|void
name|WriteASTChain
parameter_list|(
name|Sema
modifier|&
name|SemaRef
parameter_list|,
name|MemorizeStatCalls
modifier|*
name|StatCalls
parameter_list|,
specifier|const
name|char
modifier|*
name|isysroot
parameter_list|)
function_decl|;
name|public
label|:
comment|/// \brief Create a new precompiled header writer that outputs to
comment|/// the given bitstream.
name|ASTWriter
argument_list|(
name|llvm
operator|::
name|BitstreamWriter
operator|&
name|Stream
argument_list|)
expr_stmt|;
comment|/// \brief Set the listener that will receive notification of serialization
comment|/// events.
name|void
name|SetSerializationListener
parameter_list|(
name|ASTSerializationListener
modifier|*
name|Listener
parameter_list|)
block|{
name|SerializationListener
operator|=
name|Listener
expr_stmt|;
block|}
comment|/// \brief Write a precompiled header for the given semantic analysis.
comment|///
comment|/// \param SemaRef a reference to the semantic analysis object that processed
comment|/// the AST to be written into the precompiled header.
comment|///
comment|/// \param StatCalls the object that cached all of the stat() calls made while
comment|/// searching for source files and headers.
comment|///
comment|/// \param isysroot if non-NULL, write a relocatable PCH file whose headers
comment|/// are relative to the given system root.
comment|///
comment|/// \param PPRec Record of the preprocessing actions that occurred while
comment|/// preprocessing this file, e.g., macro instantiations
name|void
name|WriteAST
argument_list|(
name|Sema
operator|&
name|SemaRef
argument_list|,
name|MemorizeStatCalls
operator|*
name|StatCalls
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|OutputFile
argument_list|,
specifier|const
name|char
operator|*
name|isysroot
argument_list|)
decl_stmt|;
comment|/// \brief Emit a source location.
name|void
name|AddSourceLocation
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Emit a source range.
name|void
name|AddSourceRange
parameter_list|(
name|SourceRange
name|Range
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Emit an integral value.
name|void
name|AddAPInt
argument_list|(
specifier|const
name|llvm
operator|::
name|APInt
operator|&
name|Value
argument_list|,
name|RecordDataImpl
operator|&
name|Record
argument_list|)
decl_stmt|;
comment|/// \brief Emit a signed integral value.
name|void
name|AddAPSInt
argument_list|(
specifier|const
name|llvm
operator|::
name|APSInt
operator|&
name|Value
argument_list|,
name|RecordDataImpl
operator|&
name|Record
argument_list|)
decl_stmt|;
comment|/// \brief Emit a floating-point value.
name|void
name|AddAPFloat
argument_list|(
specifier|const
name|llvm
operator|::
name|APFloat
operator|&
name|Value
argument_list|,
name|RecordDataImpl
operator|&
name|Record
argument_list|)
decl_stmt|;
comment|/// \brief Emit a reference to an identifier.
name|void
name|AddIdentifierRef
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Emit a Selector (which is a smart pointer reference).
name|void
name|AddSelectorRef
parameter_list|(
name|Selector
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Emit a CXXTemporary.
name|void
name|AddCXXTemporary
parameter_list|(
specifier|const
name|CXXTemporary
modifier|*
name|Temp
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Emit a set of C++ base specifiers to the record.
name|void
name|AddCXXBaseSpecifiersRef
parameter_list|(
name|CXXBaseSpecifier
specifier|const
modifier|*
name|Bases
parameter_list|,
name|CXXBaseSpecifier
specifier|const
modifier|*
name|BasesEnd
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Get the unique number used to refer to the given selector.
name|serialization
operator|::
name|SelectorID
name|getSelectorRef
argument_list|(
argument|Selector Sel
argument_list|)
expr_stmt|;
comment|/// \brief Get the unique number used to refer to the given identifier.
name|serialization
operator|::
name|IdentID
name|getIdentifierRef
argument_list|(
specifier|const
name|IdentifierInfo
operator|*
name|II
argument_list|)
expr_stmt|;
comment|/// \brief Retrieve the offset of the macro definition for the given
comment|/// identifier.
comment|///
comment|/// The identifier must refer to a macro.
name|uint64_t
name|getMacroOffset
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|*
name|II
parameter_list|)
block|{
name|assert
argument_list|(
name|MacroOffsets
operator|.
name|find
argument_list|(
name|II
argument_list|)
operator|!=
name|MacroOffsets
operator|.
name|end
argument_list|()
operator|&&
literal|"Identifier does not name a macro"
argument_list|)
expr_stmt|;
return|return
name|MacroOffsets
index|[
name|II
index|]
return|;
block|}
comment|/// \brief Retrieve the ID number corresponding to the given macro
comment|/// definition.
name|serialization
operator|::
name|MacroID
name|getMacroDefinitionID
argument_list|(
name|MacroDefinition
operator|*
name|MD
argument_list|)
expr_stmt|;
comment|/// \brief Emit a reference to a type.
name|void
name|AddTypeRef
parameter_list|(
name|QualType
name|T
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Force a type to be emitted and get its ID.
name|serialization
operator|::
name|TypeID
name|GetOrCreateTypeID
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
comment|/// \brief Determine the type ID of an already-emitted type.
name|serialization
operator|::
name|TypeID
name|getTypeID
argument_list|(
argument|QualType T
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Force a type to be emitted and get its index.
name|serialization
operator|::
name|TypeIdx
name|GetOrCreateTypeIdx
argument_list|(
argument|QualType T
argument_list|)
expr_stmt|;
comment|/// \brief Determine the type index of an already-emitted type.
name|serialization
operator|::
name|TypeIdx
name|getTypeIdx
argument_list|(
argument|QualType T
argument_list|)
specifier|const
expr_stmt|;
comment|/// \brief Emits a reference to a declarator info.
name|void
name|AddTypeSourceInfo
parameter_list|(
name|TypeSourceInfo
modifier|*
name|TInfo
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Emits a template argument location info.
name|void
name|AddTemplateArgumentLocInfo
argument_list|(
name|TemplateArgument
operator|::
name|ArgKind
name|Kind
argument_list|,
specifier|const
name|TemplateArgumentLocInfo
operator|&
name|Arg
argument_list|,
name|RecordDataImpl
operator|&
name|Record
argument_list|)
decl_stmt|;
comment|/// \brief Emits a template argument location.
name|void
name|AddTemplateArgumentLoc
parameter_list|(
specifier|const
name|TemplateArgumentLoc
modifier|&
name|Arg
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Emit a reference to a declaration.
name|void
name|AddDeclRef
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Force a declaration to be emitted and get its ID.
name|serialization
operator|::
name|DeclID
name|GetDeclRef
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|)
expr_stmt|;
comment|/// \brief Determine the declaration ID of an already-emitted
comment|/// declaration.
name|serialization
operator|::
name|DeclID
name|getDeclID
argument_list|(
specifier|const
name|Decl
operator|*
name|D
argument_list|)
expr_stmt|;
comment|/// \brief Emit a declaration name.
name|void
name|AddDeclarationName
parameter_list|(
name|DeclarationName
name|Name
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
name|void
name|AddDeclarationNameLoc
parameter_list|(
specifier|const
name|DeclarationNameLoc
modifier|&
name|DNLoc
parameter_list|,
name|DeclarationName
name|Name
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
name|void
name|AddDeclarationNameInfo
parameter_list|(
specifier|const
name|DeclarationNameInfo
modifier|&
name|NameInfo
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
name|void
name|AddQualifierInfo
parameter_list|(
specifier|const
name|QualifierInfo
modifier|&
name|Info
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Emit a nested name specifier.
name|void
name|AddNestedNameSpecifier
parameter_list|(
name|NestedNameSpecifier
modifier|*
name|NNS
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Emit a template name.
name|void
name|AddTemplateName
parameter_list|(
name|TemplateName
name|Name
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Emit a template argument.
name|void
name|AddTemplateArgument
parameter_list|(
specifier|const
name|TemplateArgument
modifier|&
name|Arg
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Emit a template parameter list.
name|void
name|AddTemplateParameterList
parameter_list|(
specifier|const
name|TemplateParameterList
modifier|*
name|TemplateParams
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Emit a template argument list.
name|void
name|AddTemplateArgumentList
parameter_list|(
specifier|const
name|TemplateArgumentList
modifier|*
name|TemplateArgs
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Emit a UnresolvedSet structure.
name|void
name|AddUnresolvedSet
parameter_list|(
specifier|const
name|UnresolvedSetImpl
modifier|&
name|Set
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Emit a C++ base specifier.
name|void
name|AddCXXBaseSpecifier
parameter_list|(
specifier|const
name|CXXBaseSpecifier
modifier|&
name|Base
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Emit a CXXCtorInitializer array.
name|void
name|AddCXXCtorInitializers
parameter_list|(
specifier|const
name|CXXCtorInitializer
modifier|*
specifier|const
modifier|*
name|CtorInitializers
parameter_list|,
name|unsigned
name|NumCtorInitializers
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
name|void
name|AddCXXDefinitionData
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|D
parameter_list|,
name|RecordDataImpl
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Add a string to the given record.
name|void
name|AddString
argument_list|(
name|llvm
operator|::
name|StringRef
name|Str
argument_list|,
name|RecordDataImpl
operator|&
name|Record
argument_list|)
decl_stmt|;
comment|/// \brief Mark a declaration context as needing an update.
name|void
name|AddUpdatedDeclContext
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|DC
parameter_list|)
block|{
name|UpdatedDeclContexts
operator|.
name|insert
argument_list|(
name|DC
argument_list|)
expr_stmt|;
block|}
name|void
name|RewriteDecl
parameter_list|(
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
block|{
name|DeclsToRewrite
operator|.
name|insert
argument_list|(
name|D
argument_list|)
expr_stmt|;
comment|// Reset the flag, so that we don't add this decl multiple times.
name|const_cast
operator|<
name|Decl
operator|*
operator|>
operator|(
name|D
operator|)
operator|->
name|setChangedSinceDeserialization
argument_list|(
name|false
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Note that the identifier II occurs at the given offset
comment|/// within the identifier table.
name|void
name|SetIdentifierOffset
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|uint32_t
name|Offset
parameter_list|)
function_decl|;
comment|/// \brief Note that the selector Sel occurs at the given offset
comment|/// within the method pool/selector table.
name|void
name|SetSelectorOffset
parameter_list|(
name|Selector
name|Sel
parameter_list|,
name|uint32_t
name|Offset
parameter_list|)
function_decl|;
comment|/// \brief Add the given statement or expression to the queue of
comment|/// statements to emit.
comment|///
comment|/// This routine should be used when emitting types and declarations
comment|/// that have expressions as part of their formulation. Once the
comment|/// type or declaration has been written, call FlushStmts() to write
comment|/// the corresponding statements just after the type or
comment|/// declaration.
name|void
name|AddStmt
parameter_list|(
name|Stmt
modifier|*
name|S
parameter_list|)
block|{
name|CollectedStmts
operator|->
name|push_back
argument_list|(
name|S
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Flush all of the statements and expressions that have
comment|/// been added to the queue via AddStmt().
name|void
name|FlushStmts
parameter_list|()
function_decl|;
comment|/// \brief Flush all of the C++ base specifier sets that have been added
comment|/// via \c AddCXXBaseSpecifiersRef().
name|void
name|FlushCXXBaseSpecifiers
parameter_list|()
function_decl|;
comment|/// \brief Record an ID for the given switch-case statement.
name|unsigned
name|RecordSwitchCaseID
parameter_list|(
name|SwitchCase
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/// \brief Retrieve the ID for the given switch-case statement.
name|unsigned
name|getSwitchCaseID
parameter_list|(
name|SwitchCase
modifier|*
name|S
parameter_list|)
function_decl|;
name|void
name|ClearSwitchCaseIDs
parameter_list|()
function_decl|;
comment|/// \brief Retrieve the ID for the given opaque value expression.
name|unsigned
name|getOpaqueValueID
parameter_list|(
name|OpaqueValueExpr
modifier|*
name|e
parameter_list|)
function_decl|;
name|unsigned
name|getParmVarDeclAbbrev
argument_list|()
specifier|const
block|{
return|return
name|ParmVarDeclAbbrev
return|;
block|}
name|bool
name|hasChain
argument_list|()
specifier|const
block|{
return|return
name|Chain
return|;
block|}
comment|// ASTDeserializationListener implementation
name|void
name|ReaderInitialized
parameter_list|(
name|ASTReader
modifier|*
name|Reader
parameter_list|)
function_decl|;
name|void
name|IdentifierRead
argument_list|(
name|serialization
operator|::
name|IdentID
name|ID
argument_list|,
name|IdentifierInfo
operator|*
name|II
argument_list|)
decl_stmt|;
name|void
name|TypeRead
argument_list|(
name|serialization
operator|::
name|TypeIdx
name|Idx
argument_list|,
name|QualType
name|T
argument_list|)
decl_stmt|;
name|void
name|DeclRead
argument_list|(
name|serialization
operator|::
name|DeclID
name|ID
argument_list|,
specifier|const
name|Decl
operator|*
name|D
argument_list|)
decl_stmt|;
name|void
name|SelectorRead
argument_list|(
name|serialization
operator|::
name|SelectorID
name|ID
argument_list|,
name|Selector
name|Sel
argument_list|)
decl_stmt|;
name|void
name|MacroDefinitionRead
argument_list|(
name|serialization
operator|::
name|MacroID
name|ID
argument_list|,
name|MacroDefinition
operator|*
name|MD
argument_list|)
decl_stmt|;
comment|// ASTMutationListener implementation.
name|virtual
name|void
name|CompletedTagDefinition
parameter_list|(
specifier|const
name|TagDecl
modifier|*
name|D
parameter_list|)
function_decl|;
name|virtual
name|void
name|AddedVisibleDecl
parameter_list|(
specifier|const
name|DeclContext
modifier|*
name|DC
parameter_list|,
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
name|virtual
name|void
name|AddedCXXImplicitMember
parameter_list|(
specifier|const
name|CXXRecordDecl
modifier|*
name|RD
parameter_list|,
specifier|const
name|Decl
modifier|*
name|D
parameter_list|)
function_decl|;
name|virtual
name|void
name|AddedCXXTemplateSpecialization
parameter_list|(
specifier|const
name|ClassTemplateDecl
modifier|*
name|TD
parameter_list|,
specifier|const
name|ClassTemplateSpecializationDecl
modifier|*
name|D
parameter_list|)
function_decl|;
block|}
empty_stmt|;
comment|/// \brief AST and semantic-analysis consumer that generates a
comment|/// precompiled header from the parsed source code.
name|class
name|PCHGenerator
range|:
name|public
name|SemaConsumer
block|{
specifier|const
name|Preprocessor
operator|&
name|PP
block|;
name|std
operator|::
name|string
name|OutputFile
block|;
specifier|const
name|char
operator|*
name|isysroot
block|;
name|llvm
operator|::
name|raw_ostream
operator|*
name|Out
block|;
name|Sema
operator|*
name|SemaPtr
block|;
name|MemorizeStatCalls
operator|*
name|StatCalls
block|;
comment|// owned by the FileManager
name|std
operator|::
name|vector
operator|<
name|unsigned
name|char
operator|>
name|Buffer
block|;
name|llvm
operator|::
name|BitstreamWriter
name|Stream
block|;
name|ASTWriter
name|Writer
block|;
name|bool
name|Chaining
block|;
name|protected
operator|:
name|ASTWriter
operator|&
name|getWriter
argument_list|()
block|{
return|return
name|Writer
return|;
block|}
specifier|const
name|ASTWriter
operator|&
name|getWriter
argument_list|()
specifier|const
block|{
return|return
name|Writer
return|;
block|}
name|public
operator|:
name|PCHGenerator
argument_list|(
argument|const Preprocessor&PP
argument_list|,
argument|const std::string&OutputFile
argument_list|,
argument|bool Chaining
argument_list|,
argument|const char *isysroot
argument_list|,
argument|llvm::raw_ostream *Out
argument_list|)
block|;
name|virtual
name|void
name|InitializeSema
argument_list|(
argument|Sema&S
argument_list|)
block|{
name|SemaPtr
operator|=
operator|&
name|S
block|; }
name|virtual
name|void
name|HandleTranslationUnit
argument_list|(
name|ASTContext
operator|&
name|Ctx
argument_list|)
block|;
name|virtual
name|ASTMutationListener
operator|*
name|GetASTMutationListener
argument_list|()
block|;
name|virtual
name|ASTSerializationListener
operator|*
name|GetASTSerializationListener
argument_list|()
block|;
name|virtual
name|ASTDeserializationListener
operator|*
name|GetASTDeserializationListener
argument_list|()
block|; }
decl_stmt|;
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

