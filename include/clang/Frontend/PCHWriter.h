begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- PCHWriter.h - Precompiled Headers Writer ---------------*- C++ -*-===//
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
comment|//  This file defines the PCHWriter class, which writes a precompiled
end_comment

begin_comment
comment|//  header containing a serialized representation of a translation
end_comment

begin_comment
comment|//  unit.
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
name|LLVM_CLANG_FRONTEND_PCH_WRITER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_PCH_WRITER_H
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
file|"clang/Frontend/PCHBitCodes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
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
name|LabelStmt
decl_stmt|;
name|class
name|MemorizeStatCalls
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
comment|/// A structure for putting "fast"-unqualified QualTypes into a
comment|/// DenseMap.  This uses the standard pointer hash function.
struct|struct
name|UnsafeQualTypeDenseMapInfo
block|{
specifier|static
specifier|inline
name|bool
name|isEqual
parameter_list|(
name|QualType
name|A
parameter_list|,
name|QualType
name|B
parameter_list|)
block|{
return|return
name|A
operator|==
name|B
return|;
block|}
specifier|static
specifier|inline
name|bool
name|isPod
parameter_list|()
block|{
return|return
name|true
return|;
block|}
specifier|static
specifier|inline
name|QualType
name|getEmptyKey
parameter_list|()
block|{
return|return
name|QualType
operator|::
name|getFromOpaquePtr
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|1
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|QualType
name|getTombstoneKey
parameter_list|()
block|{
return|return
name|QualType
operator|::
name|getFromOpaquePtr
argument_list|(
operator|(
name|void
operator|*
operator|)
literal|2
argument_list|)
return|;
block|}
specifier|static
specifier|inline
name|unsigned
name|getHashValue
parameter_list|(
name|QualType
name|T
parameter_list|)
block|{
name|assert
argument_list|(
operator|!
name|T
operator|.
name|getLocalFastQualifiers
argument_list|()
operator|&&
literal|"hash invalid for types with fast quals"
argument_list|)
expr_stmt|;
name|uintptr_t
name|v
init|=
name|reinterpret_cast
operator|<
name|uintptr_t
operator|>
operator|(
name|T
operator|.
name|getAsOpaquePtr
argument_list|()
operator|)
decl_stmt|;
return|return
operator|(
name|unsigned
argument_list|(
name|v
argument_list|)
operator|>>
literal|4
operator|)
operator|^
operator|(
name|unsigned
argument_list|(
name|v
argument_list|)
operator|>>
literal|9
operator|)
return|;
block|}
block|}
struct|;
comment|/// \brief Writes a precompiled header containing the contents of a
comment|/// translation unit.
comment|///
comment|/// The PCHWriter class produces a bitstream containing the serialized
comment|/// representation of a given abstract syntax tree and its supporting
comment|/// data structures. This bitstream can be de-serialized via an
comment|/// instance of the PCHReader class.
name|class
name|PCHWriter
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
name|private
label|:
comment|/// \brief The bitstream writer used to emit this precompiled header.
name|llvm
operator|::
name|BitstreamWriter
operator|&
name|Stream
expr_stmt|;
comment|/// \brief Stores a declaration or a type to be written to the PCH file.
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
comment|/// \brief Map that provides the ID numbers of each declaration within
comment|/// the output stream.
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
name|pch
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
comment|/// \brief Map that provides the ID numbers of each type within the
comment|/// output stream.
comment|///
comment|/// The ID numbers of types are consecutive (in order of discovery)
comment|/// and start at 1. 0 is reserved for NULL. When types are actually
comment|/// stored in the stream, the ID number is shifted by 2 bits to
comment|/// allow for the const/volatile qualifiers.
comment|///
comment|/// Keys in the map never have const/volatile qualifiers.
name|llvm
operator|::
name|DenseMap
operator|<
name|QualType
operator|,
name|pch
operator|::
name|TypeID
operator|,
name|UnsafeQualTypeDenseMapInfo
operator|>
name|TypeIDs
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
comment|/// \brief The type ID that will be assigned to the next new type.
name|pch
operator|::
name|TypeID
name|NextTypeID
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
name|pch
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
comment|/// \brief Map that provides the ID numbers of each Selector.
name|llvm
operator|::
name|DenseMap
operator|<
name|Selector
operator|,
name|pch
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
comment|/// \brief A vector of all Selectors (ordered by ID).
name|std
operator|::
name|vector
operator|<
name|Selector
operator|>
name|SelVector
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
comment|/// \brief Declarations encountered that might be external
comment|/// definitions.
comment|///
comment|/// We keep track of external definitions (as well as tentative
comment|/// definitions) as we are emitting declarations to the PCH
comment|/// file. The PCH file contains a separate record for these external
comment|/// definitions, which are provided to the AST consumer by the PCH
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
comment|/// \brief Statements that we've encountered while serializing a
comment|/// declaration or type.
name|llvm
operator|::
name|SmallVector
operator|<
name|Stmt
operator|*
operator|,
literal|8
operator|>
name|StmtsToEmit
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
comment|/// \brief Mapping from LabelStmt statements to IDs.
name|std
operator|::
name|map
operator|<
name|LabelStmt
operator|*
operator|,
name|unsigned
operator|>
name|LabelIDs
expr_stmt|;
comment|/// \brief The number of statements written to the PCH file.
name|unsigned
name|NumStatements
decl_stmt|;
comment|/// \brief The number of macros written to the PCH file.
name|unsigned
name|NumMacros
decl_stmt|;
comment|/// \brief The number of lexical declcontexts written to the PCH
comment|/// file.
name|unsigned
name|NumLexicalDeclContexts
decl_stmt|;
comment|/// \brief The number of visible declcontexts written to the PCH
comment|/// file.
name|unsigned
name|NumVisibleDeclContexts
decl_stmt|;
name|void
name|WriteBlockInfoBlock
parameter_list|()
function_decl|;
name|void
name|WriteMetadata
parameter_list|(
name|ASTContext
modifier|&
name|Context
parameter_list|,
specifier|const
name|char
modifier|*
name|isysroot
parameter_list|)
function_decl|;
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
parameter_list|,
specifier|const
name|char
modifier|*
name|isysroot
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
name|WriteComments
parameter_list|(
name|ASTContext
modifier|&
name|Context
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
name|WriteMethodPool
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
name|WriteAttributeRecord
parameter_list|(
specifier|const
name|Attr
modifier|*
name|Attr
parameter_list|)
function_decl|;
name|unsigned
name|ParmVarDeclAbbrev
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
name|public
label|:
comment|/// \brief Create a new precompiled header writer that outputs to
comment|/// the given bitstream.
name|PCHWriter
argument_list|(
name|llvm
operator|::
name|BitstreamWriter
operator|&
name|Stream
argument_list|)
expr_stmt|;
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
name|void
name|WritePCH
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
comment|/// \brief Emit a source location.
name|void
name|AddSourceLocation
parameter_list|(
name|SourceLocation
name|Loc
parameter_list|,
name|RecordData
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
name|RecordData
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
name|RecordData
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
name|RecordData
operator|&
name|Record
argument_list|)
decl_stmt|;
comment|/// \brief Emit a reference to an identifier
name|void
name|AddIdentifierRef
parameter_list|(
specifier|const
name|IdentifierInfo
modifier|*
name|II
parameter_list|,
name|RecordData
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Emit a Selector (which is a smart pointer reference)
name|void
name|AddSelectorRef
parameter_list|(
specifier|const
name|Selector
parameter_list|,
name|RecordData
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Get the unique number used to refer to the given
comment|/// identifier.
name|pch
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
comment|/// \brief Emit a reference to a type.
name|void
name|AddTypeRef
parameter_list|(
name|QualType
name|T
parameter_list|,
name|RecordData
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Emits a reference to a declarator info.
name|void
name|AddDeclaratorInfo
parameter_list|(
name|DeclaratorInfo
modifier|*
name|DInfo
parameter_list|,
name|RecordData
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Emits a template argument location.
name|void
name|AddTemplateArgumentLoc
parameter_list|(
specifier|const
name|TemplateArgumentLoc
modifier|&
name|Arg
parameter_list|,
name|RecordData
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
name|RecordData
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Determine the declaration ID of an already-emitted
comment|/// declaration.
name|pch
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
name|RecordData
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// \brief Add a string to the given record.
name|void
name|AddString
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Str
argument_list|,
name|RecordData
operator|&
name|Record
argument_list|)
decl_stmt|;
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
name|StmtsToEmit
operator|.
name|push_back
argument_list|(
name|S
argument_list|)
expr_stmt|;
block|}
comment|/// \brief Write the given subexpression to the bitstream.
name|void
name|WriteSubStmt
parameter_list|(
name|Stmt
modifier|*
name|S
parameter_list|)
function_decl|;
comment|/// \brief Flush all of the statements and expressions that have
comment|/// been added to the queue via AddStmt().
name|void
name|FlushStmts
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
comment|/// \brief Retrieve the ID for the given label statement, which may
comment|/// or may not have been emitted yet.
name|unsigned
name|GetLabelID
parameter_list|(
name|LabelStmt
modifier|*
name|S
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
block|}
empty_stmt|;
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

