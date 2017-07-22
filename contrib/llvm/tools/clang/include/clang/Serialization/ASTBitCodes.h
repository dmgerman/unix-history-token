begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ASTBitCodes.h - Enum values for the PCH bitcode format ---*- C++ -*-===//
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
comment|// This header defines Bitcode enum values for Clang serialized AST files.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// The enum values defined in this file should be considered permanent.  If
end_comment

begin_comment
comment|// new features are added, they should have values added at the end of the
end_comment

begin_comment
comment|// respective lists.
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
name|LLVM_CLANG_SERIALIZATION_ASTBITCODES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SERIALIZATION_ASTBITCODES_H
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
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Bitcode/BitCodes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|serialization
block|{
comment|/// \brief AST file major version number supported by this version of
comment|/// Clang.
comment|///
comment|/// Whenever the AST file format changes in a way that makes it
comment|/// incompatible with previous versions (such that a reader
comment|/// designed for the previous version could not support reading
comment|/// the new version), this number should be increased.
comment|///
comment|/// Version 4 of AST files also requires that the version control branch and
comment|/// revision match exactly, since there is no backward compatibility of
comment|/// AST files at this time.
specifier|const
name|unsigned
name|VERSION_MAJOR
init|=
literal|6
decl_stmt|;
comment|/// \brief AST file minor version number supported by this version of
comment|/// Clang.
comment|///
comment|/// Whenever the AST format changes in a way that is still
comment|/// compatible with previous versions (such that a reader designed
comment|/// for the previous version could still support reading the new
comment|/// version by ignoring new kinds of subblocks), this number
comment|/// should be increased.
specifier|const
name|unsigned
name|VERSION_MINOR
init|=
literal|0
decl_stmt|;
comment|/// \brief An ID number that refers to an identifier in an AST file.
comment|///
comment|/// The ID numbers of identifiers are consecutive (in order of discovery)
comment|/// and start at 1. 0 is reserved for NULL.
typedef|typedef
name|uint32_t
name|IdentifierID
typedef|;
comment|/// \brief An ID number that refers to a declaration in an AST file.
comment|///
comment|/// The ID numbers of declarations are consecutive (in order of
comment|/// discovery), with values below NUM_PREDEF_DECL_IDS being reserved.
comment|/// At the start of a chain of precompiled headers, declaration ID 1 is
comment|/// used for the translation unit declaration.
typedef|typedef
name|uint32_t
name|DeclID
typedef|;
comment|// FIXME: Turn these into classes so we can have some type safety when
comment|// we go from local ID to global and vice-versa.
typedef|typedef
name|DeclID
name|LocalDeclID
typedef|;
typedef|typedef
name|DeclID
name|GlobalDeclID
typedef|;
comment|/// \brief An ID number that refers to a type in an AST file.
comment|///
comment|/// The ID of a type is partitioned into two parts: the lower
comment|/// three bits are used to store the const/volatile/restrict
comment|/// qualifiers (as with QualType) and the upper bits provide a
comment|/// type index. The type index values are partitioned into two
comment|/// sets. The values below NUM_PREDEF_TYPE_IDs are predefined type
comment|/// IDs (based on the PREDEF_TYPE_*_ID constants), with 0 as a
comment|/// placeholder for "no type". Values from NUM_PREDEF_TYPE_IDs are
comment|/// other types that have serialized representations.
typedef|typedef
name|uint32_t
name|TypeID
typedef|;
comment|/// \brief A type index; the type ID with the qualifier bits removed.
name|class
name|TypeIdx
block|{
name|uint32_t
name|Idx
decl_stmt|;
name|public
label|:
name|TypeIdx
argument_list|()
operator|:
name|Idx
argument_list|(
literal|0
argument_list|)
block|{ }
name|explicit
name|TypeIdx
argument_list|(
argument|uint32_t index
argument_list|)
operator|:
name|Idx
argument_list|(
argument|index
argument_list|)
block|{ }
name|uint32_t
name|getIndex
argument_list|()
specifier|const
block|{
return|return
name|Idx
return|;
block|}
name|TypeID
name|asTypeID
argument_list|(
name|unsigned
name|FastQuals
argument_list|)
decl|const
block|{
if|if
condition|(
name|Idx
operator|==
name|uint32_t
argument_list|(
operator|-
literal|1
argument_list|)
condition|)
return|return
name|TypeID
argument_list|(
operator|-
literal|1
argument_list|)
return|;
return|return
operator|(
name|Idx
operator|<<
name|Qualifiers
operator|::
name|FastWidth
operator|)
operator||
name|FastQuals
return|;
block|}
specifier|static
name|TypeIdx
name|fromTypeID
parameter_list|(
name|TypeID
name|ID
parameter_list|)
block|{
if|if
condition|(
name|ID
operator|==
name|TypeID
argument_list|(
operator|-
literal|1
argument_list|)
condition|)
return|return
name|TypeIdx
argument_list|(
operator|-
literal|1
argument_list|)
return|;
return|return
name|TypeIdx
argument_list|(
name|ID
operator|>>
name|Qualifiers
operator|::
name|FastWidth
argument_list|)
return|;
block|}
block|}
empty_stmt|;
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
comment|/// \brief An ID number that refers to an identifier in an AST file.
typedef|typedef
name|uint32_t
name|IdentID
typedef|;
comment|/// \brief The number of predefined identifier IDs.
specifier|const
name|unsigned
name|int
name|NUM_PREDEF_IDENT_IDS
init|=
literal|1
decl_stmt|;
comment|/// \brief An ID number that refers to a macro in an AST file.
typedef|typedef
name|uint32_t
name|MacroID
typedef|;
comment|/// \brief A global ID number that refers to a macro in an AST file.
typedef|typedef
name|uint32_t
name|GlobalMacroID
typedef|;
comment|/// \brief A local to a module ID number that refers to a macro in an
comment|/// AST file.
typedef|typedef
name|uint32_t
name|LocalMacroID
typedef|;
comment|/// \brief The number of predefined macro IDs.
specifier|const
name|unsigned
name|int
name|NUM_PREDEF_MACRO_IDS
init|=
literal|1
decl_stmt|;
comment|/// \brief An ID number that refers to an ObjC selector in an AST file.
typedef|typedef
name|uint32_t
name|SelectorID
typedef|;
comment|/// \brief The number of predefined selector IDs.
specifier|const
name|unsigned
name|int
name|NUM_PREDEF_SELECTOR_IDS
init|=
literal|1
decl_stmt|;
comment|/// \brief An ID number that refers to a set of CXXBaseSpecifiers in an
comment|/// AST file.
typedef|typedef
name|uint32_t
name|CXXBaseSpecifiersID
typedef|;
comment|/// \brief An ID number that refers to a list of CXXCtorInitializers in an
comment|/// AST file.
typedef|typedef
name|uint32_t
name|CXXCtorInitializersID
typedef|;
comment|/// \brief An ID number that refers to an entity in the detailed
comment|/// preprocessing record.
typedef|typedef
name|uint32_t
name|PreprocessedEntityID
typedef|;
comment|/// \brief An ID number that refers to a submodule in a module file.
typedef|typedef
name|uint32_t
name|SubmoduleID
typedef|;
comment|/// \brief The number of predefined submodule IDs.
specifier|const
name|unsigned
name|int
name|NUM_PREDEF_SUBMODULE_IDS
init|=
literal|1
decl_stmt|;
comment|/// \brief Source range/offset of a preprocessed entity.
struct|struct
name|PPEntityOffset
block|{
comment|/// \brief Raw source location of beginning of range.
name|unsigned
name|Begin
decl_stmt|;
comment|/// \brief Raw source location of end of range.
name|unsigned
name|End
decl_stmt|;
comment|/// \brief Offset in the AST file.
name|uint32_t
name|BitOffset
decl_stmt|;
name|PPEntityOffset
argument_list|(
argument|SourceRange R
argument_list|,
argument|uint32_t BitOffset
argument_list|)
block|:
name|Begin
argument_list|(
name|R
operator|.
name|getBegin
argument_list|()
operator|.
name|getRawEncoding
argument_list|()
argument_list|)
operator|,
name|End
argument_list|(
name|R
operator|.
name|getEnd
argument_list|()
operator|.
name|getRawEncoding
argument_list|()
argument_list|)
operator|,
name|BitOffset
argument_list|(
argument|BitOffset
argument_list|)
block|{ }
name|SourceLocation
name|getBegin
argument_list|()
specifier|const
block|{
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|Begin
argument_list|)
return|;
block|}
name|SourceLocation
name|getEnd
argument_list|()
specifier|const
block|{
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|End
argument_list|)
return|;
block|}
block|}
struct|;
comment|/// \brief Source range/offset of a preprocessed entity.
struct|struct
name|DeclOffset
block|{
comment|/// \brief Raw source location.
name|unsigned
name|Loc
decl_stmt|;
comment|/// \brief Offset in the AST file.
name|uint32_t
name|BitOffset
decl_stmt|;
name|DeclOffset
argument_list|()
operator|:
name|Loc
argument_list|(
literal|0
argument_list|)
operator|,
name|BitOffset
argument_list|(
literal|0
argument_list|)
block|{ }
name|DeclOffset
argument_list|(
argument|SourceLocation Loc
argument_list|,
argument|uint32_t BitOffset
argument_list|)
operator|:
name|Loc
argument_list|(
name|Loc
operator|.
name|getRawEncoding
argument_list|()
argument_list|)
operator|,
name|BitOffset
argument_list|(
argument|BitOffset
argument_list|)
block|{ }
name|void
name|setLocation
argument_list|(
argument|SourceLocation L
argument_list|)
block|{
name|Loc
operator|=
name|L
operator|.
name|getRawEncoding
argument_list|()
block|;       }
name|SourceLocation
name|getLocation
argument_list|()
specifier|const
block|{
return|return
name|SourceLocation
operator|::
name|getFromRawEncoding
argument_list|(
name|Loc
argument_list|)
return|;
block|}
block|}
struct|;
comment|/// \brief The number of predefined preprocessed entity IDs.
specifier|const
name|unsigned
name|int
name|NUM_PREDEF_PP_ENTITY_IDS
init|=
literal|1
decl_stmt|;
comment|/// \brief Describes the various kinds of blocks that occur within
comment|/// an AST file.
enum|enum
name|BlockIDs
block|{
comment|/// \brief The AST block, which acts as a container around the
comment|/// full AST block.
name|AST_BLOCK_ID
init|=
name|llvm
operator|::
name|bitc
operator|::
name|FIRST_APPLICATION_BLOCKID
block|,
comment|/// \brief The block containing information about the source
comment|/// manager.
name|SOURCE_MANAGER_BLOCK_ID
block|,
comment|/// \brief The block containing information about the
comment|/// preprocessor.
name|PREPROCESSOR_BLOCK_ID
block|,
comment|/// \brief The block containing the definitions of all of the
comment|/// types and decls used within the AST file.
name|DECLTYPES_BLOCK_ID
block|,
comment|/// \brief The block containing the detailed preprocessing record.
name|PREPROCESSOR_DETAIL_BLOCK_ID
block|,
comment|/// \brief The block containing the submodule structure.
name|SUBMODULE_BLOCK_ID
block|,
comment|/// \brief The block containing comments.
name|COMMENTS_BLOCK_ID
block|,
comment|/// \brief The control block, which contains all of the
comment|/// information that needs to be validated prior to committing
comment|/// to loading the AST file.
name|CONTROL_BLOCK_ID
block|,
comment|/// \brief The block of input files, which were used as inputs
comment|/// to create this AST file.
comment|///
comment|/// This block is part of the control block.
name|INPUT_FILES_BLOCK_ID
block|,
comment|/// \brief The block of configuration options, used to check that
comment|/// a module is being used in a configuration compatible with the
comment|/// configuration in which it was built.
comment|///
comment|/// This block is part of the control block.
name|OPTIONS_BLOCK_ID
block|,
comment|/// \brief A block containing a module file extension.
name|EXTENSION_BLOCK_ID
block|,
comment|/// A block with unhashed content.
comment|///
comment|/// These records should not change the \a ASTFileSignature.  See \a
comment|/// UnhashedControlBlockRecordTypes for the list of records.
name|UNHASHED_CONTROL_BLOCK_ID
block|,     }
enum|;
comment|/// \brief Record types that occur within the control block.
enum|enum
name|ControlRecordTypes
block|{
comment|/// \brief AST file metadata, including the AST file version number
comment|/// and information about the compiler used to build this AST file.
name|METADATA
init|=
literal|1
block|,
comment|/// \brief Record code for the list of other AST files imported by
comment|/// this AST file.
name|IMPORTS
block|,
comment|/// \brief Record code for the original file that was used to
comment|/// generate the AST file, including both its file ID and its
comment|/// name.
name|ORIGINAL_FILE
block|,
comment|/// \brief The directory that the PCH was originally created in.
name|ORIGINAL_PCH_DIR
block|,
comment|/// \brief Record code for file ID of the file or buffer that was used to
comment|/// generate the AST file.
name|ORIGINAL_FILE_ID
block|,
comment|/// \brief Offsets into the input-files block where input files
comment|/// reside.
name|INPUT_FILE_OFFSETS
block|,
comment|/// \brief Record code for the module name.
name|MODULE_NAME
block|,
comment|/// \brief Record code for the module map file that was used to build this
comment|/// AST file.
name|MODULE_MAP_FILE
block|,
comment|/// \brief Record code for the module build directory.
name|MODULE_DIRECTORY
block|,     }
enum|;
comment|/// \brief Record types that occur within the options block inside
comment|/// the control block.
enum|enum
name|OptionsRecordTypes
block|{
comment|/// \brief Record code for the language options table.
comment|///
comment|/// The record with this code contains the contents of the
comment|/// LangOptions structure. We serialize the entire contents of
comment|/// the structure, and let the reader decide which options are
comment|/// actually important to check.
name|LANGUAGE_OPTIONS
init|=
literal|1
block|,
comment|/// \brief Record code for the target options table.
name|TARGET_OPTIONS
block|,
comment|/// \brief Record code for the filesystem options table.
name|FILE_SYSTEM_OPTIONS
block|,
comment|/// \brief Record code for the headers search options table.
name|HEADER_SEARCH_OPTIONS
block|,
comment|/// \brief Record code for the preprocessor options table.
name|PREPROCESSOR_OPTIONS
block|,     }
enum|;
comment|/// Record codes for the unhashed control block.
enum|enum
name|UnhashedControlBlockRecordTypes
block|{
comment|/// Record code for the signature that identifiers this AST file.
name|SIGNATURE
init|=
literal|1
block|,
comment|/// Record code for the diagnostic options table.
name|DIAGNOSTIC_OPTIONS
block|,
comment|/// Record code for \#pragma diagnostic mappings.
name|DIAG_PRAGMA_MAPPINGS
block|,     }
enum|;
comment|/// \brief Record code for extension blocks.
enum|enum
name|ExtensionBlockRecordTypes
block|{
comment|/// Metadata describing this particular extension.
name|EXTENSION_METADATA
init|=
literal|1
block|,
comment|/// The first record ID allocated to the extensions themselves.
name|FIRST_EXTENSION_RECORD_ID
init|=
literal|4
block|}
enum|;
comment|/// \brief Record types that occur within the input-files block
comment|/// inside the control block.
enum|enum
name|InputFileRecordTypes
block|{
comment|/// \brief An input file.
name|INPUT_FILE
init|=
literal|1
block|}
enum|;
comment|/// \brief Record types that occur within the AST block itself.
enum|enum
name|ASTRecordTypes
block|{
comment|/// \brief Record code for the offsets of each type.
comment|///
comment|/// The TYPE_OFFSET constant describes the record that occurs
comment|/// within the AST block. The record itself is an array of offsets that
comment|/// point into the declarations and types block (identified by
comment|/// DECLTYPES_BLOCK_ID). The index into the array is based on the ID
comment|/// of a type. For a given type ID @c T, the lower three bits of
comment|/// @c T are its qualifiers (const, volatile, restrict), as in
comment|/// the QualType class. The upper bits, after being shifted and
comment|/// subtracting NUM_PREDEF_TYPE_IDS, are used to index into the
comment|/// TYPE_OFFSET block to determine the offset of that type's
comment|/// corresponding record within the DECLTYPES_BLOCK_ID block.
name|TYPE_OFFSET
init|=
literal|1
block|,
comment|/// \brief Record code for the offsets of each decl.
comment|///
comment|/// The DECL_OFFSET constant describes the record that occurs
comment|/// within the block identified by DECL_OFFSETS_BLOCK_ID within
comment|/// the AST block. The record itself is an array of offsets that
comment|/// point into the declarations and types block (identified by
comment|/// DECLTYPES_BLOCK_ID). The declaration ID is an index into this
comment|/// record, after subtracting one to account for the use of
comment|/// declaration ID 0 for a NULL declaration pointer. Index 0 is
comment|/// reserved for the translation unit declaration.
name|DECL_OFFSET
init|=
literal|2
block|,
comment|/// \brief Record code for the table of offsets of each
comment|/// identifier ID.
comment|///
comment|/// The offset table contains offsets into the blob stored in
comment|/// the IDENTIFIER_TABLE record. Each offset points to the
comment|/// NULL-terminated string that corresponds to that identifier.
name|IDENTIFIER_OFFSET
init|=
literal|3
block|,
comment|/// \brief This is so that older clang versions, before the introduction
comment|/// of the control block, can read and reject the newer PCH format.
comment|/// *DON'T CHANGE THIS NUMBER*.
name|METADATA_OLD_FORMAT
init|=
literal|4
block|,
comment|/// \brief Record code for the identifier table.
comment|///
comment|/// The identifier table is a simple blob that contains
comment|/// NULL-terminated strings for all of the identifiers
comment|/// referenced by the AST file. The IDENTIFIER_OFFSET table
comment|/// contains the mapping from identifier IDs to the characters
comment|/// in this blob. Note that the starting offsets of all of the
comment|/// identifiers are odd, so that, when the identifier offset
comment|/// table is loaded in, we can use the low bit to distinguish
comment|/// between offsets (for unresolved identifier IDs) and
comment|/// IdentifierInfo pointers (for already-resolved identifier
comment|/// IDs).
name|IDENTIFIER_TABLE
init|=
literal|5
block|,
comment|/// \brief Record code for the array of eagerly deserialized decls.
comment|///
comment|/// The AST file contains a list of all of the declarations that should be
comment|/// eagerly deserialized present within the parsed headers, stored as an
comment|/// array of declaration IDs. These declarations will be
comment|/// reported to the AST consumer after the AST file has been
comment|/// read, since their presence can affect the semantics of the
comment|/// program (e.g., for code generation).
name|EAGERLY_DESERIALIZED_DECLS
init|=
literal|6
block|,
comment|/// \brief Record code for the set of non-builtin, special
comment|/// types.
comment|///
comment|/// This record contains the type IDs for the various type nodes
comment|/// that are constructed during semantic analysis (e.g.,
comment|/// __builtin_va_list). The SPECIAL_TYPE_* constants provide
comment|/// offsets into this record.
name|SPECIAL_TYPES
init|=
literal|7
block|,
comment|/// \brief Record code for the extra statistics we gather while
comment|/// generating an AST file.
name|STATISTICS
init|=
literal|8
block|,
comment|/// \brief Record code for the array of tentative definitions.
name|TENTATIVE_DEFINITIONS
init|=
literal|9
block|,
comment|// ID 10 used to be for a list of extern "C" declarations.
comment|/// \brief Record code for the table of offsets into the
comment|/// Objective-C method pool.
name|SELECTOR_OFFSETS
init|=
literal|11
block|,
comment|/// \brief Record code for the Objective-C method pool,
name|METHOD_POOL
init|=
literal|12
block|,
comment|/// \brief The value of the next __COUNTER__ to dispense.
comment|/// [PP_COUNTER_VALUE, Val]
name|PP_COUNTER_VALUE
init|=
literal|13
block|,
comment|/// \brief Record code for the table of offsets into the block
comment|/// of source-location information.
name|SOURCE_LOCATION_OFFSETS
init|=
literal|14
block|,
comment|/// \brief Record code for the set of source location entries
comment|/// that need to be preloaded by the AST reader.
comment|///
comment|/// This set contains the source location entry for the
comment|/// predefines buffer and for any file entries that need to be
comment|/// preloaded.
name|SOURCE_LOCATION_PRELOADS
init|=
literal|15
block|,
comment|/// \brief Record code for the set of ext_vector type names.
name|EXT_VECTOR_DECLS
init|=
literal|16
block|,
comment|/// \brief Record code for the array of unused file scoped decls.
name|UNUSED_FILESCOPED_DECLS
init|=
literal|17
block|,
comment|/// \brief Record code for the table of offsets to entries in the
comment|/// preprocessing record.
name|PPD_ENTITIES_OFFSETS
init|=
literal|18
block|,
comment|/// \brief Record code for the array of VTable uses.
name|VTABLE_USES
init|=
literal|19
block|,
comment|// ID 20 used to be for a list of dynamic classes.
comment|/// \brief Record code for referenced selector pool.
name|REFERENCED_SELECTOR_POOL
init|=
literal|21
block|,
comment|/// \brief Record code for an update to the TU's lexically contained
comment|/// declarations.
name|TU_UPDATE_LEXICAL
init|=
literal|22
block|,
comment|// ID 23 used to be for a list of local redeclarations.
comment|/// \brief Record code for declarations that Sema keeps references of.
name|SEMA_DECL_REFS
init|=
literal|24
block|,
comment|/// \brief Record code for weak undeclared identifiers.
name|WEAK_UNDECLARED_IDENTIFIERS
init|=
literal|25
block|,
comment|/// \brief Record code for pending implicit instantiations.
name|PENDING_IMPLICIT_INSTANTIATIONS
init|=
literal|26
block|,
comment|// ID 27 used to be for a list of replacement decls.
comment|/// \brief Record code for an update to a decl context's lookup table.
comment|///
comment|/// In practice, this should only be used for the TU and namespaces.
name|UPDATE_VISIBLE
init|=
literal|28
block|,
comment|/// \brief Record for offsets of DECL_UPDATES records for declarations
comment|/// that were modified after being deserialized and need updates.
name|DECL_UPDATE_OFFSETS
init|=
literal|29
block|,
comment|// ID 30 used to be a decl update record. These are now in the DECLTYPES
comment|// block.
comment|// ID 31 used to be a list of offsets to DECL_CXX_BASE_SPECIFIERS records.
comment|// ID 32 used to be the code for \#pragma diagnostic mappings.
comment|/// \brief Record code for special CUDA declarations.
name|CUDA_SPECIAL_DECL_REFS
init|=
literal|33
block|,
comment|/// \brief Record code for header search information.
name|HEADER_SEARCH_TABLE
init|=
literal|34
block|,
comment|/// \brief Record code for floating point \#pragma options.
name|FP_PRAGMA_OPTIONS
init|=
literal|35
block|,
comment|/// \brief Record code for enabled OpenCL extensions.
name|OPENCL_EXTENSIONS
init|=
literal|36
block|,
comment|/// \brief The list of delegating constructor declarations.
name|DELEGATING_CTORS
init|=
literal|37
block|,
comment|/// \brief Record code for the set of known namespaces, which are used
comment|/// for typo correction.
name|KNOWN_NAMESPACES
init|=
literal|38
block|,
comment|/// \brief Record code for the remapping information used to relate
comment|/// loaded modules to the various offsets and IDs(e.g., source location
comment|/// offests, declaration and type IDs) that are used in that module to
comment|/// refer to other modules.
name|MODULE_OFFSET_MAP
init|=
literal|39
block|,
comment|/// \brief Record code for the source manager line table information,
comment|/// which stores information about \#line directives.
name|SOURCE_MANAGER_LINE_TABLE
init|=
literal|40
block|,
comment|/// \brief Record code for map of Objective-C class definition IDs to the
comment|/// ObjC categories in a module that are attached to that class.
name|OBJC_CATEGORIES_MAP
init|=
literal|41
block|,
comment|/// \brief Record code for a file sorted array of DeclIDs in a module.
name|FILE_SORTED_DECLS
init|=
literal|42
block|,
comment|/// \brief Record code for an array of all of the (sub)modules that were
comment|/// imported by the AST file.
name|IMPORTED_MODULES
init|=
literal|43
block|,
comment|// ID 44 used to be a table of merged canonical declarations.
comment|// ID 45 used to be a list of declaration IDs of local redeclarations.
comment|/// \brief Record code for the array of Objective-C categories (including
comment|/// extensions).
comment|///
comment|/// This array can only be interpreted properly using the Objective-C
comment|/// categories map.
name|OBJC_CATEGORIES
init|=
literal|46
block|,
comment|/// \brief Record code for the table of offsets of each macro ID.
comment|///
comment|/// The offset table contains offsets into the blob stored in
comment|/// the preprocessor block. Each offset points to the corresponding
comment|/// macro definition.
name|MACRO_OFFSET
init|=
literal|47
block|,
comment|/// \brief A list of "interesting" identifiers. Only used in C++ (where we
comment|/// don't normally do lookups into the serialized identifier table). These
comment|/// are eagerly deserialized.
name|INTERESTING_IDENTIFIERS
init|=
literal|48
block|,
comment|/// \brief Record code for undefined but used functions and variables that
comment|/// need a definition in this TU.
name|UNDEFINED_BUT_USED
init|=
literal|49
block|,
comment|/// \brief Record code for late parsed template functions.
name|LATE_PARSED_TEMPLATE
init|=
literal|50
block|,
comment|/// \brief Record code for \#pragma optimize options.
name|OPTIMIZE_PRAGMA_OPTIONS
init|=
literal|51
block|,
comment|/// \brief Record code for potentially unused local typedef names.
name|UNUSED_LOCAL_TYPEDEF_NAME_CANDIDATES
init|=
literal|52
block|,
comment|// ID 53 used to be a table of constructor initializer records.
comment|/// \brief Delete expressions that will be analyzed later.
name|DELETE_EXPRS_TO_ANALYZE
init|=
literal|54
block|,
comment|/// \brief Record code for \#pragma ms_struct options.
name|MSSTRUCT_PRAGMA_OPTIONS
init|=
literal|55
block|,
comment|/// \brief Record code for \#pragma ms_struct options.
name|POINTERS_TO_MEMBERS_PRAGMA_OPTIONS
init|=
literal|56
block|,
comment|/// \brief Number of unmatched #pragma clang cuda_force_host_device begin
comment|/// directives we've seen.
name|CUDA_PRAGMA_FORCE_HOST_DEVICE_DEPTH
init|=
literal|57
block|,
comment|/// \brief Record code for types associated with OpenCL extensions.
name|OPENCL_EXTENSION_TYPES
init|=
literal|58
block|,
comment|/// \brief Record code for declarations associated with OpenCL extensions.
name|OPENCL_EXTENSION_DECLS
init|=
literal|59
block|,
name|MODULAR_CODEGEN_DECLS
init|=
literal|60
block|,
comment|/// \brief Record code for \#pragma pack options.
name|PACK_PRAGMA_OPTIONS
init|=
literal|61
block|,
comment|/// \brief The stack of open #ifs/#ifdefs recorded in a preamble.
name|PP_CONDITIONAL_STACK
init|=
literal|62
block|,     }
enum|;
comment|/// \brief Record types used within a source manager block.
enum|enum
name|SourceManagerRecordTypes
block|{
comment|/// \brief Describes a source location entry (SLocEntry) for a
comment|/// file.
name|SM_SLOC_FILE_ENTRY
init|=
literal|1
block|,
comment|/// \brief Describes a source location entry (SLocEntry) for a
comment|/// buffer.
name|SM_SLOC_BUFFER_ENTRY
init|=
literal|2
block|,
comment|/// \brief Describes a blob that contains the data for a buffer
comment|/// entry. This kind of record always directly follows a
comment|/// SM_SLOC_BUFFER_ENTRY record or a SM_SLOC_FILE_ENTRY with an
comment|/// overridden buffer.
name|SM_SLOC_BUFFER_BLOB
init|=
literal|3
block|,
comment|/// \brief Describes a zlib-compressed blob that contains the data for
comment|/// a buffer entry.
name|SM_SLOC_BUFFER_BLOB_COMPRESSED
init|=
literal|4
block|,
comment|/// \brief Describes a source location entry (SLocEntry) for a
comment|/// macro expansion.
name|SM_SLOC_EXPANSION_ENTRY
init|=
literal|5
block|}
enum|;
comment|/// \brief Record types used within a preprocessor block.
enum|enum
name|PreprocessorRecordTypes
block|{
comment|// The macros in the PP section are a PP_MACRO_* instance followed by a
comment|// list of PP_TOKEN instances for each token in the definition.
comment|/// \brief An object-like macro definition.
comment|/// [PP_MACRO_OBJECT_LIKE, IdentInfoID, SLoc, IsUsed]
name|PP_MACRO_OBJECT_LIKE
init|=
literal|1
block|,
comment|/// \brief A function-like macro definition.
comment|/// [PP_MACRO_FUNCTION_LIKE, \<ObjectLikeStuff>, IsC99Varargs,
comment|/// IsGNUVarars, NumArgs, ArgIdentInfoID* ]
name|PP_MACRO_FUNCTION_LIKE
init|=
literal|2
block|,
comment|/// \brief Describes one token.
comment|/// [PP_TOKEN, SLoc, Length, IdentInfoID, Kind, Flags]
name|PP_TOKEN
init|=
literal|3
block|,
comment|/// \brief The macro directives history for a particular identifier.
name|PP_MACRO_DIRECTIVE_HISTORY
init|=
literal|4
block|,
comment|/// \brief A macro directive exported by a module.
comment|/// [PP_MODULE_MACRO, SubmoduleID, MacroID, (Overridden SubmoduleID)*]
name|PP_MODULE_MACRO
init|=
literal|5
block|,     }
enum|;
comment|/// \brief Record types used within a preprocessor detail block.
enum|enum
name|PreprocessorDetailRecordTypes
block|{
comment|/// \brief Describes a macro expansion within the preprocessing record.
name|PPD_MACRO_EXPANSION
init|=
literal|0
block|,
comment|/// \brief Describes a macro definition within the preprocessing record.
name|PPD_MACRO_DEFINITION
init|=
literal|1
block|,
comment|/// \brief Describes an inclusion directive within the preprocessing
comment|/// record.
name|PPD_INCLUSION_DIRECTIVE
init|=
literal|2
block|}
enum|;
comment|/// \brief Record types used within a submodule description block.
enum|enum
name|SubmoduleRecordTypes
block|{
comment|/// \brief Metadata for submodules as a whole.
name|SUBMODULE_METADATA
init|=
literal|0
block|,
comment|/// \brief Defines the major attributes of a submodule, including its
comment|/// name and parent.
name|SUBMODULE_DEFINITION
init|=
literal|1
block|,
comment|/// \brief Specifies the umbrella header used to create this module,
comment|/// if any.
name|SUBMODULE_UMBRELLA_HEADER
init|=
literal|2
block|,
comment|/// \brief Specifies a header that falls into this (sub)module.
name|SUBMODULE_HEADER
init|=
literal|3
block|,
comment|/// \brief Specifies a top-level header that falls into this (sub)module.
name|SUBMODULE_TOPHEADER
init|=
literal|4
block|,
comment|/// \brief Specifies an umbrella directory.
name|SUBMODULE_UMBRELLA_DIR
init|=
literal|5
block|,
comment|/// \brief Specifies the submodules that are imported by this
comment|/// submodule.
name|SUBMODULE_IMPORTS
init|=
literal|6
block|,
comment|/// \brief Specifies the submodules that are re-exported from this
comment|/// submodule.
name|SUBMODULE_EXPORTS
init|=
literal|7
block|,
comment|/// \brief Specifies a required feature.
name|SUBMODULE_REQUIRES
init|=
literal|8
block|,
comment|/// \brief Specifies a header that has been explicitly excluded
comment|/// from this submodule.
name|SUBMODULE_EXCLUDED_HEADER
init|=
literal|9
block|,
comment|/// \brief Specifies a library or framework to link against.
name|SUBMODULE_LINK_LIBRARY
init|=
literal|10
block|,
comment|/// \brief Specifies a configuration macro for this module.
name|SUBMODULE_CONFIG_MACRO
init|=
literal|11
block|,
comment|/// \brief Specifies a conflict with another module.
name|SUBMODULE_CONFLICT
init|=
literal|12
block|,
comment|/// \brief Specifies a header that is private to this submodule.
name|SUBMODULE_PRIVATE_HEADER
init|=
literal|13
block|,
comment|/// \brief Specifies a header that is part of the module but must be
comment|/// textually included.
name|SUBMODULE_TEXTUAL_HEADER
init|=
literal|14
block|,
comment|/// \brief Specifies a header that is private to this submodule but
comment|/// must be textually included.
name|SUBMODULE_PRIVATE_TEXTUAL_HEADER
init|=
literal|15
block|,
comment|/// \brief Specifies some declarations with initializers that must be
comment|/// emitted to initialize the module.
name|SUBMODULE_INITIALIZERS
init|=
literal|16
block|,     }
enum|;
comment|/// \brief Record types used within a comments block.
enum|enum
name|CommentRecordTypes
block|{
name|COMMENTS_RAW_COMMENT
init|=
literal|0
block|}
enum|;
comment|/// \defgroup ASTAST AST file AST constants
comment|///
comment|/// The constants in this group describe various components of the
comment|/// abstract syntax tree within an AST file.
comment|///
comment|/// @{
comment|/// \brief Predefined type IDs.
comment|///
comment|/// These type IDs correspond to predefined types in the AST
comment|/// context, such as built-in types (int) and special place-holder
comment|/// types (the \<overload> and \<dependent> type markers). Such
comment|/// types are never actually serialized, since they will be built
comment|/// by the AST context when it is created.
enum|enum
name|PredefinedTypeIDs
block|{
comment|/// \brief The NULL type.
name|PREDEF_TYPE_NULL_ID
init|=
literal|0
block|,
comment|/// \brief The void type.
name|PREDEF_TYPE_VOID_ID
init|=
literal|1
block|,
comment|/// \brief The 'bool' or '_Bool' type.
name|PREDEF_TYPE_BOOL_ID
init|=
literal|2
block|,
comment|/// \brief The 'char' type, when it is unsigned.
name|PREDEF_TYPE_CHAR_U_ID
init|=
literal|3
block|,
comment|/// \brief The 'unsigned char' type.
name|PREDEF_TYPE_UCHAR_ID
init|=
literal|4
block|,
comment|/// \brief The 'unsigned short' type.
name|PREDEF_TYPE_USHORT_ID
init|=
literal|5
block|,
comment|/// \brief The 'unsigned int' type.
name|PREDEF_TYPE_UINT_ID
init|=
literal|6
block|,
comment|/// \brief The 'unsigned long' type.
name|PREDEF_TYPE_ULONG_ID
init|=
literal|7
block|,
comment|/// \brief The 'unsigned long long' type.
name|PREDEF_TYPE_ULONGLONG_ID
init|=
literal|8
block|,
comment|/// \brief The 'char' type, when it is signed.
name|PREDEF_TYPE_CHAR_S_ID
init|=
literal|9
block|,
comment|/// \brief The 'signed char' type.
name|PREDEF_TYPE_SCHAR_ID
init|=
literal|10
block|,
comment|/// \brief The C++ 'wchar_t' type.
name|PREDEF_TYPE_WCHAR_ID
init|=
literal|11
block|,
comment|/// \brief The (signed) 'short' type.
name|PREDEF_TYPE_SHORT_ID
init|=
literal|12
block|,
comment|/// \brief The (signed) 'int' type.
name|PREDEF_TYPE_INT_ID
init|=
literal|13
block|,
comment|/// \brief The (signed) 'long' type.
name|PREDEF_TYPE_LONG_ID
init|=
literal|14
block|,
comment|/// \brief The (signed) 'long long' type.
name|PREDEF_TYPE_LONGLONG_ID
init|=
literal|15
block|,
comment|/// \brief The 'float' type.
name|PREDEF_TYPE_FLOAT_ID
init|=
literal|16
block|,
comment|/// \brief The 'double' type.
name|PREDEF_TYPE_DOUBLE_ID
init|=
literal|17
block|,
comment|/// \brief The 'long double' type.
name|PREDEF_TYPE_LONGDOUBLE_ID
init|=
literal|18
block|,
comment|/// \brief The placeholder type for overloaded function sets.
name|PREDEF_TYPE_OVERLOAD_ID
init|=
literal|19
block|,
comment|/// \brief The placeholder type for dependent types.
name|PREDEF_TYPE_DEPENDENT_ID
init|=
literal|20
block|,
comment|/// \brief The '__uint128_t' type.
name|PREDEF_TYPE_UINT128_ID
init|=
literal|21
block|,
comment|/// \brief The '__int128_t' type.
name|PREDEF_TYPE_INT128_ID
init|=
literal|22
block|,
comment|/// \brief The type of 'nullptr'.
name|PREDEF_TYPE_NULLPTR_ID
init|=
literal|23
block|,
comment|/// \brief The C++ 'char16_t' type.
name|PREDEF_TYPE_CHAR16_ID
init|=
literal|24
block|,
comment|/// \brief The C++ 'char32_t' type.
name|PREDEF_TYPE_CHAR32_ID
init|=
literal|25
block|,
comment|/// \brief The ObjC 'id' type.
name|PREDEF_TYPE_OBJC_ID
init|=
literal|26
block|,
comment|/// \brief The ObjC 'Class' type.
name|PREDEF_TYPE_OBJC_CLASS
init|=
literal|27
block|,
comment|/// \brief The ObjC 'SEL' type.
name|PREDEF_TYPE_OBJC_SEL
init|=
literal|28
block|,
comment|/// \brief The 'unknown any' placeholder type.
name|PREDEF_TYPE_UNKNOWN_ANY
init|=
literal|29
block|,
comment|/// \brief The placeholder type for bound member functions.
name|PREDEF_TYPE_BOUND_MEMBER
init|=
literal|30
block|,
comment|/// \brief The "auto" deduction type.
name|PREDEF_TYPE_AUTO_DEDUCT
init|=
literal|31
block|,
comment|/// \brief The "auto&&" deduction type.
name|PREDEF_TYPE_AUTO_RREF_DEDUCT
init|=
literal|32
block|,
comment|/// \brief The OpenCL 'half' / ARM NEON __fp16 type.
name|PREDEF_TYPE_HALF_ID
init|=
literal|33
block|,
comment|/// \brief ARC's unbridged-cast placeholder type.
name|PREDEF_TYPE_ARC_UNBRIDGED_CAST
init|=
literal|34
block|,
comment|/// \brief The pseudo-object placeholder type.
name|PREDEF_TYPE_PSEUDO_OBJECT
init|=
literal|35
block|,
comment|/// \brief The placeholder type for builtin functions.
name|PREDEF_TYPE_BUILTIN_FN
init|=
literal|36
block|,
comment|/// \brief OpenCL event type.
name|PREDEF_TYPE_EVENT_ID
init|=
literal|37
block|,
comment|/// \brief OpenCL clk event type.
name|PREDEF_TYPE_CLK_EVENT_ID
init|=
literal|38
block|,
comment|/// \brief OpenCL sampler type.
name|PREDEF_TYPE_SAMPLER_ID
init|=
literal|39
block|,
comment|/// \brief OpenCL queue type.
name|PREDEF_TYPE_QUEUE_ID
init|=
literal|40
block|,
comment|/// \brief OpenCL reserve_id type.
name|PREDEF_TYPE_RESERVE_ID_ID
init|=
literal|41
block|,
comment|/// \brief The placeholder type for OpenMP array section.
name|PREDEF_TYPE_OMP_ARRAY_SECTION
init|=
literal|42
block|,
comment|/// \brief The '__float128' type
name|PREDEF_TYPE_FLOAT128_ID
init|=
literal|43
block|,
comment|/// \brief OpenCL image types with auto numeration
define|#
directive|define
name|IMAGE_TYPE
parameter_list|(
name|ImgType
parameter_list|,
name|Id
parameter_list|,
name|SingletonId
parameter_list|,
name|Access
parameter_list|,
name|Suffix
parameter_list|)
define|\
value|PREDEF_TYPE_##Id##_ID,
include|#
directive|include
file|"clang/Basic/OpenCLImageTypes.def"
block|}
enum|;
comment|/// \brief The number of predefined type IDs that are reserved for
comment|/// the PREDEF_TYPE_* constants.
comment|///
comment|/// Type IDs for non-predefined types will start at
comment|/// NUM_PREDEF_TYPE_IDs.
specifier|const
name|unsigned
name|NUM_PREDEF_TYPE_IDS
init|=
literal|100
decl_stmt|;
comment|/// \brief Record codes for each kind of type.
comment|///
comment|/// These constants describe the type records that can occur within a
comment|/// block identified by DECLTYPES_BLOCK_ID in the AST file. Each
comment|/// constant describes a record for a specific type class in the
comment|/// AST. Note that DeclCode values share this code space.
enum|enum
name|TypeCode
block|{
comment|/// \brief An ExtQualType record.
name|TYPE_EXT_QUAL
init|=
literal|1
block|,
comment|/// \brief A ComplexType record.
name|TYPE_COMPLEX
init|=
literal|3
block|,
comment|/// \brief A PointerType record.
name|TYPE_POINTER
init|=
literal|4
block|,
comment|/// \brief A BlockPointerType record.
name|TYPE_BLOCK_POINTER
init|=
literal|5
block|,
comment|/// \brief An LValueReferenceType record.
name|TYPE_LVALUE_REFERENCE
init|=
literal|6
block|,
comment|/// \brief An RValueReferenceType record.
name|TYPE_RVALUE_REFERENCE
init|=
literal|7
block|,
comment|/// \brief A MemberPointerType record.
name|TYPE_MEMBER_POINTER
init|=
literal|8
block|,
comment|/// \brief A ConstantArrayType record.
name|TYPE_CONSTANT_ARRAY
init|=
literal|9
block|,
comment|/// \brief An IncompleteArrayType record.
name|TYPE_INCOMPLETE_ARRAY
init|=
literal|10
block|,
comment|/// \brief A VariableArrayType record.
name|TYPE_VARIABLE_ARRAY
init|=
literal|11
block|,
comment|/// \brief A VectorType record.
name|TYPE_VECTOR
init|=
literal|12
block|,
comment|/// \brief An ExtVectorType record.
name|TYPE_EXT_VECTOR
init|=
literal|13
block|,
comment|/// \brief A FunctionNoProtoType record.
name|TYPE_FUNCTION_NO_PROTO
init|=
literal|14
block|,
comment|/// \brief A FunctionProtoType record.
name|TYPE_FUNCTION_PROTO
init|=
literal|15
block|,
comment|/// \brief A TypedefType record.
name|TYPE_TYPEDEF
init|=
literal|16
block|,
comment|/// \brief A TypeOfExprType record.
name|TYPE_TYPEOF_EXPR
init|=
literal|17
block|,
comment|/// \brief A TypeOfType record.
name|TYPE_TYPEOF
init|=
literal|18
block|,
comment|/// \brief A RecordType record.
name|TYPE_RECORD
init|=
literal|19
block|,
comment|/// \brief An EnumType record.
name|TYPE_ENUM
init|=
literal|20
block|,
comment|/// \brief An ObjCInterfaceType record.
name|TYPE_OBJC_INTERFACE
init|=
literal|21
block|,
comment|/// \brief An ObjCObjectPointerType record.
name|TYPE_OBJC_OBJECT_POINTER
init|=
literal|22
block|,
comment|/// \brief a DecltypeType record.
name|TYPE_DECLTYPE
init|=
literal|23
block|,
comment|/// \brief An ElaboratedType record.
name|TYPE_ELABORATED
init|=
literal|24
block|,
comment|/// \brief A SubstTemplateTypeParmType record.
name|TYPE_SUBST_TEMPLATE_TYPE_PARM
init|=
literal|25
block|,
comment|/// \brief An UnresolvedUsingType record.
name|TYPE_UNRESOLVED_USING
init|=
literal|26
block|,
comment|/// \brief An InjectedClassNameType record.
name|TYPE_INJECTED_CLASS_NAME
init|=
literal|27
block|,
comment|/// \brief An ObjCObjectType record.
name|TYPE_OBJC_OBJECT
init|=
literal|28
block|,
comment|/// \brief An TemplateTypeParmType record.
name|TYPE_TEMPLATE_TYPE_PARM
init|=
literal|29
block|,
comment|/// \brief An TemplateSpecializationType record.
name|TYPE_TEMPLATE_SPECIALIZATION
init|=
literal|30
block|,
comment|/// \brief A DependentNameType record.
name|TYPE_DEPENDENT_NAME
init|=
literal|31
block|,
comment|/// \brief A DependentTemplateSpecializationType record.
name|TYPE_DEPENDENT_TEMPLATE_SPECIALIZATION
init|=
literal|32
block|,
comment|/// \brief A DependentSizedArrayType record.
name|TYPE_DEPENDENT_SIZED_ARRAY
init|=
literal|33
block|,
comment|/// \brief A ParenType record.
name|TYPE_PAREN
init|=
literal|34
block|,
comment|/// \brief A PackExpansionType record.
name|TYPE_PACK_EXPANSION
init|=
literal|35
block|,
comment|/// \brief An AttributedType record.
name|TYPE_ATTRIBUTED
init|=
literal|36
block|,
comment|/// \brief A SubstTemplateTypeParmPackType record.
name|TYPE_SUBST_TEMPLATE_TYPE_PARM_PACK
init|=
literal|37
block|,
comment|/// \brief A AutoType record.
name|TYPE_AUTO
init|=
literal|38
block|,
comment|/// \brief A UnaryTransformType record.
name|TYPE_UNARY_TRANSFORM
init|=
literal|39
block|,
comment|/// \brief An AtomicType record.
name|TYPE_ATOMIC
init|=
literal|40
block|,
comment|/// \brief A DecayedType record.
name|TYPE_DECAYED
init|=
literal|41
block|,
comment|/// \brief An AdjustedType record.
name|TYPE_ADJUSTED
init|=
literal|42
block|,
comment|/// \brief A PipeType record.
name|TYPE_PIPE
init|=
literal|43
block|,
comment|/// \brief An ObjCTypeParamType record.
name|TYPE_OBJC_TYPE_PARAM
init|=
literal|44
block|,
comment|/// \brief A DeducedTemplateSpecializationType record.
name|TYPE_DEDUCED_TEMPLATE_SPECIALIZATION
init|=
literal|45
block|,
comment|/// \brief A DependentSizedExtVectorType record.
name|TYPE_DEPENDENT_SIZED_EXT_VECTOR
init|=
literal|46
block|}
enum|;
comment|/// \brief The type IDs for special types constructed by semantic
comment|/// analysis.
comment|///
comment|/// The constants in this enumeration are indices into the
comment|/// SPECIAL_TYPES record.
enum|enum
name|SpecialTypeIDs
block|{
comment|/// \brief CFConstantString type
name|SPECIAL_TYPE_CF_CONSTANT_STRING
init|=
literal|0
block|,
comment|/// \brief C FILE typedef type
name|SPECIAL_TYPE_FILE
init|=
literal|1
block|,
comment|/// \brief C jmp_buf typedef type
name|SPECIAL_TYPE_JMP_BUF
init|=
literal|2
block|,
comment|/// \brief C sigjmp_buf typedef type
name|SPECIAL_TYPE_SIGJMP_BUF
init|=
literal|3
block|,
comment|/// \brief Objective-C "id" redefinition type
name|SPECIAL_TYPE_OBJC_ID_REDEFINITION
init|=
literal|4
block|,
comment|/// \brief Objective-C "Class" redefinition type
name|SPECIAL_TYPE_OBJC_CLASS_REDEFINITION
init|=
literal|5
block|,
comment|/// \brief Objective-C "SEL" redefinition type
name|SPECIAL_TYPE_OBJC_SEL_REDEFINITION
init|=
literal|6
block|,
comment|/// \brief C ucontext_t typedef type
name|SPECIAL_TYPE_UCONTEXT_T
init|=
literal|7
block|}
enum|;
comment|/// \brief The number of special type IDs.
specifier|const
name|unsigned
name|NumSpecialTypeIDs
init|=
literal|8
decl_stmt|;
comment|/// \brief Predefined declaration IDs.
comment|///
comment|/// These declaration IDs correspond to predefined declarations in the AST
comment|/// context, such as the NULL declaration ID. Such declarations are never
comment|/// actually serialized, since they will be built by the AST context when
comment|/// it is created.
enum|enum
name|PredefinedDeclIDs
block|{
comment|/// \brief The NULL declaration.
name|PREDEF_DECL_NULL_ID
init|=
literal|0
block|,
comment|/// \brief The translation unit.
name|PREDEF_DECL_TRANSLATION_UNIT_ID
init|=
literal|1
block|,
comment|/// \brief The Objective-C 'id' type.
name|PREDEF_DECL_OBJC_ID_ID
init|=
literal|2
block|,
comment|/// \brief The Objective-C 'SEL' type.
name|PREDEF_DECL_OBJC_SEL_ID
init|=
literal|3
block|,
comment|/// \brief The Objective-C 'Class' type.
name|PREDEF_DECL_OBJC_CLASS_ID
init|=
literal|4
block|,
comment|/// \brief The Objective-C 'Protocol' type.
name|PREDEF_DECL_OBJC_PROTOCOL_ID
init|=
literal|5
block|,
comment|/// \brief The signed 128-bit integer type.
name|PREDEF_DECL_INT_128_ID
init|=
literal|6
block|,
comment|/// \brief The unsigned 128-bit integer type.
name|PREDEF_DECL_UNSIGNED_INT_128_ID
init|=
literal|7
block|,
comment|/// \brief The internal 'instancetype' typedef.
name|PREDEF_DECL_OBJC_INSTANCETYPE_ID
init|=
literal|8
block|,
comment|/// \brief The internal '__builtin_va_list' typedef.
name|PREDEF_DECL_BUILTIN_VA_LIST_ID
init|=
literal|9
block|,
comment|/// \brief The internal '__va_list_tag' struct, if any.
name|PREDEF_DECL_VA_LIST_TAG
init|=
literal|10
block|,
comment|/// \brief The internal '__builtin_ms_va_list' typedef.
name|PREDEF_DECL_BUILTIN_MS_VA_LIST_ID
init|=
literal|11
block|,
comment|/// \brief The extern "C" context.
name|PREDEF_DECL_EXTERN_C_CONTEXT_ID
init|=
literal|12
block|,
comment|/// \brief The internal '__make_integer_seq' template.
name|PREDEF_DECL_MAKE_INTEGER_SEQ_ID
init|=
literal|13
block|,
comment|/// \brief The internal '__NSConstantString' typedef.
name|PREDEF_DECL_CF_CONSTANT_STRING_ID
init|=
literal|14
block|,
comment|/// \brief The internal '__NSConstantString' tag type.
name|PREDEF_DECL_CF_CONSTANT_STRING_TAG_ID
init|=
literal|15
block|,
comment|/// \brief The internal '__type_pack_element' template.
name|PREDEF_DECL_TYPE_PACK_ELEMENT_ID
init|=
literal|16
block|,     }
enum|;
comment|/// \brief The number of declaration IDs that are predefined.
comment|///
comment|/// For more information about predefined declarations, see the
comment|/// \c PredefinedDeclIDs type and the PREDEF_DECL_*_ID constants.
specifier|const
name|unsigned
name|int
name|NUM_PREDEF_DECL_IDS
init|=
literal|17
decl_stmt|;
comment|/// \brief Record of updates for a declaration that was modified after
comment|/// being deserialized. This can occur within DECLTYPES_BLOCK_ID.
specifier|const
name|unsigned
name|int
name|DECL_UPDATES
init|=
literal|49
decl_stmt|;
comment|/// \brief Record code for a list of local redeclarations of a declaration.
comment|/// This can occur within DECLTYPES_BLOCK_ID.
specifier|const
name|unsigned
name|int
name|LOCAL_REDECLARATIONS
init|=
literal|50
decl_stmt|;
comment|/// \brief Record codes for each kind of declaration.
comment|///
comment|/// These constants describe the declaration records that can occur within
comment|/// a declarations block (identified by DECLTYPES_BLOCK_ID). Each
comment|/// constant describes a record for a specific declaration class
comment|/// in the AST. Note that TypeCode values share this code space.
enum|enum
name|DeclCode
block|{
comment|/// \brief A TypedefDecl record.
name|DECL_TYPEDEF
init|=
literal|51
block|,
comment|/// \brief A TypeAliasDecl record.
name|DECL_TYPEALIAS
block|,
comment|/// \brief An EnumDecl record.
name|DECL_ENUM
block|,
comment|/// \brief A RecordDecl record.
name|DECL_RECORD
block|,
comment|/// \brief An EnumConstantDecl record.
name|DECL_ENUM_CONSTANT
block|,
comment|/// \brief A FunctionDecl record.
name|DECL_FUNCTION
block|,
comment|/// \brief A ObjCMethodDecl record.
name|DECL_OBJC_METHOD
block|,
comment|/// \brief A ObjCInterfaceDecl record.
name|DECL_OBJC_INTERFACE
block|,
comment|/// \brief A ObjCProtocolDecl record.
name|DECL_OBJC_PROTOCOL
block|,
comment|/// \brief A ObjCIvarDecl record.
name|DECL_OBJC_IVAR
block|,
comment|/// \brief A ObjCAtDefsFieldDecl record.
name|DECL_OBJC_AT_DEFS_FIELD
block|,
comment|/// \brief A ObjCCategoryDecl record.
name|DECL_OBJC_CATEGORY
block|,
comment|/// \brief A ObjCCategoryImplDecl record.
name|DECL_OBJC_CATEGORY_IMPL
block|,
comment|/// \brief A ObjCImplementationDecl record.
name|DECL_OBJC_IMPLEMENTATION
block|,
comment|/// \brief A ObjCCompatibleAliasDecl record.
name|DECL_OBJC_COMPATIBLE_ALIAS
block|,
comment|/// \brief A ObjCPropertyDecl record.
name|DECL_OBJC_PROPERTY
block|,
comment|/// \brief A ObjCPropertyImplDecl record.
name|DECL_OBJC_PROPERTY_IMPL
block|,
comment|/// \brief A FieldDecl record.
name|DECL_FIELD
block|,
comment|/// \brief A MSPropertyDecl record.
name|DECL_MS_PROPERTY
block|,
comment|/// \brief A VarDecl record.
name|DECL_VAR
block|,
comment|/// \brief An ImplicitParamDecl record.
name|DECL_IMPLICIT_PARAM
block|,
comment|/// \brief A ParmVarDecl record.
name|DECL_PARM_VAR
block|,
comment|/// \brief A DecompositionDecl record.
name|DECL_DECOMPOSITION
block|,
comment|/// \brief A BindingDecl record.
name|DECL_BINDING
block|,
comment|/// \brief A FileScopeAsmDecl record.
name|DECL_FILE_SCOPE_ASM
block|,
comment|/// \brief A BlockDecl record.
name|DECL_BLOCK
block|,
comment|/// \brief A CapturedDecl record.
name|DECL_CAPTURED
block|,
comment|/// \brief A record that stores the set of declarations that are
comment|/// lexically stored within a given DeclContext.
comment|///
comment|/// The record itself is a blob that is an array of declaration IDs,
comment|/// in the order in which those declarations were added to the
comment|/// declaration context. This data is used when iterating over
comment|/// the contents of a DeclContext, e.g., via
comment|/// DeclContext::decls_begin() and DeclContext::decls_end().
name|DECL_CONTEXT_LEXICAL
block|,
comment|/// \brief A record that stores the set of declarations that are
comment|/// visible from a given DeclContext.
comment|///
comment|/// The record itself stores a set of mappings, each of which
comment|/// associates a declaration name with one or more declaration
comment|/// IDs. This data is used when performing qualified name lookup
comment|/// into a DeclContext via DeclContext::lookup.
name|DECL_CONTEXT_VISIBLE
block|,
comment|/// \brief A LabelDecl record.
name|DECL_LABEL
block|,
comment|/// \brief A NamespaceDecl record.
name|DECL_NAMESPACE
block|,
comment|/// \brief A NamespaceAliasDecl record.
name|DECL_NAMESPACE_ALIAS
block|,
comment|/// \brief A UsingDecl record.
name|DECL_USING
block|,
comment|/// \brief A UsingPackDecl record.
name|DECL_USING_PACK
block|,
comment|/// \brief A UsingShadowDecl record.
name|DECL_USING_SHADOW
block|,
comment|/// \brief A ConstructorUsingShadowDecl record.
name|DECL_CONSTRUCTOR_USING_SHADOW
block|,
comment|/// \brief A UsingDirecitveDecl record.
name|DECL_USING_DIRECTIVE
block|,
comment|/// \brief An UnresolvedUsingValueDecl record.
name|DECL_UNRESOLVED_USING_VALUE
block|,
comment|/// \brief An UnresolvedUsingTypenameDecl record.
name|DECL_UNRESOLVED_USING_TYPENAME
block|,
comment|/// \brief A LinkageSpecDecl record.
name|DECL_LINKAGE_SPEC
block|,
comment|/// \brief An ExportDecl record.
name|DECL_EXPORT
block|,
comment|/// \brief A CXXRecordDecl record.
name|DECL_CXX_RECORD
block|,
comment|/// \brief A CXXDeductionGuideDecl record.
name|DECL_CXX_DEDUCTION_GUIDE
block|,
comment|/// \brief A CXXMethodDecl record.
name|DECL_CXX_METHOD
block|,
comment|/// \brief A CXXConstructorDecl record.
name|DECL_CXX_CONSTRUCTOR
block|,
comment|/// \brief A CXXConstructorDecl record for an inherited constructor.
name|DECL_CXX_INHERITED_CONSTRUCTOR
block|,
comment|/// \brief A CXXDestructorDecl record.
name|DECL_CXX_DESTRUCTOR
block|,
comment|/// \brief A CXXConversionDecl record.
name|DECL_CXX_CONVERSION
block|,
comment|/// \brief An AccessSpecDecl record.
name|DECL_ACCESS_SPEC
block|,
comment|/// \brief A FriendDecl record.
name|DECL_FRIEND
block|,
comment|/// \brief A FriendTemplateDecl record.
name|DECL_FRIEND_TEMPLATE
block|,
comment|/// \brief A ClassTemplateDecl record.
name|DECL_CLASS_TEMPLATE
block|,
comment|/// \brief A ClassTemplateSpecializationDecl record.
name|DECL_CLASS_TEMPLATE_SPECIALIZATION
block|,
comment|/// \brief A ClassTemplatePartialSpecializationDecl record.
name|DECL_CLASS_TEMPLATE_PARTIAL_SPECIALIZATION
block|,
comment|/// \brief A VarTemplateDecl record.
name|DECL_VAR_TEMPLATE
block|,
comment|/// \brief A VarTemplateSpecializationDecl record.
name|DECL_VAR_TEMPLATE_SPECIALIZATION
block|,
comment|/// \brief A VarTemplatePartialSpecializationDecl record.
name|DECL_VAR_TEMPLATE_PARTIAL_SPECIALIZATION
block|,
comment|/// \brief A FunctionTemplateDecl record.
name|DECL_FUNCTION_TEMPLATE
block|,
comment|/// \brief A TemplateTypeParmDecl record.
name|DECL_TEMPLATE_TYPE_PARM
block|,
comment|/// \brief A NonTypeTemplateParmDecl record.
name|DECL_NON_TYPE_TEMPLATE_PARM
block|,
comment|/// \brief A TemplateTemplateParmDecl record.
name|DECL_TEMPLATE_TEMPLATE_PARM
block|,
comment|/// \brief A TypeAliasTemplateDecl record.
name|DECL_TYPE_ALIAS_TEMPLATE
block|,
comment|/// \brief A StaticAssertDecl record.
name|DECL_STATIC_ASSERT
block|,
comment|/// \brief A record containing CXXBaseSpecifiers.
name|DECL_CXX_BASE_SPECIFIERS
block|,
comment|/// \brief A record containing CXXCtorInitializers.
name|DECL_CXX_CTOR_INITIALIZERS
block|,
comment|/// \brief A IndirectFieldDecl record.
name|DECL_INDIRECTFIELD
block|,
comment|/// \brief A NonTypeTemplateParmDecl record that stores an expanded
comment|/// non-type template parameter pack.
name|DECL_EXPANDED_NON_TYPE_TEMPLATE_PARM_PACK
block|,
comment|/// \brief A TemplateTemplateParmDecl record that stores an expanded
comment|/// template template parameter pack.
name|DECL_EXPANDED_TEMPLATE_TEMPLATE_PARM_PACK
block|,
comment|/// \brief A ClassScopeFunctionSpecializationDecl record a class scope
comment|/// function specialization. (Microsoft extension).
name|DECL_CLASS_SCOPE_FUNCTION_SPECIALIZATION
block|,
comment|/// \brief An ImportDecl recording a module import.
name|DECL_IMPORT
block|,
comment|/// \brief An OMPThreadPrivateDecl record.
name|DECL_OMP_THREADPRIVATE
block|,
comment|/// \brief An EmptyDecl record.
name|DECL_EMPTY
block|,
comment|/// \brief An ObjCTypeParamDecl record.
name|DECL_OBJC_TYPE_PARAM
block|,
comment|/// \brief An OMPCapturedExprDecl record.
name|DECL_OMP_CAPTUREDEXPR
block|,
comment|/// \brief A PragmaCommentDecl record.
name|DECL_PRAGMA_COMMENT
block|,
comment|/// \brief A PragmaDetectMismatchDecl record.
name|DECL_PRAGMA_DETECT_MISMATCH
block|,
comment|/// \brief An OMPDeclareReductionDecl record.
name|DECL_OMP_DECLARE_REDUCTION
block|,     }
enum|;
comment|/// \brief Record codes for each kind of statement or expression.
comment|///
comment|/// These constants describe the records that describe statements
comment|/// or expressions. These records  occur within type and declarations
comment|/// block, so they begin with record values of 128.  Each constant
comment|/// describes a record for a specific statement or expression class in the
comment|/// AST.
enum|enum
name|StmtCode
block|{
comment|/// \brief A marker record that indicates that we are at the end
comment|/// of an expression.
name|STMT_STOP
init|=
literal|128
block|,
comment|/// \brief A NULL expression.
name|STMT_NULL_PTR
block|,
comment|/// \brief A reference to a previously [de]serialized Stmt record.
name|STMT_REF_PTR
block|,
comment|/// \brief A NullStmt record.
name|STMT_NULL
block|,
comment|/// \brief A CompoundStmt record.
name|STMT_COMPOUND
block|,
comment|/// \brief A CaseStmt record.
name|STMT_CASE
block|,
comment|/// \brief A DefaultStmt record.
name|STMT_DEFAULT
block|,
comment|/// \brief A LabelStmt record.
name|STMT_LABEL
block|,
comment|/// \brief An AttributedStmt record.
name|STMT_ATTRIBUTED
block|,
comment|/// \brief An IfStmt record.
name|STMT_IF
block|,
comment|/// \brief A SwitchStmt record.
name|STMT_SWITCH
block|,
comment|/// \brief A WhileStmt record.
name|STMT_WHILE
block|,
comment|/// \brief A DoStmt record.
name|STMT_DO
block|,
comment|/// \brief A ForStmt record.
name|STMT_FOR
block|,
comment|/// \brief A GotoStmt record.
name|STMT_GOTO
block|,
comment|/// \brief An IndirectGotoStmt record.
name|STMT_INDIRECT_GOTO
block|,
comment|/// \brief A ContinueStmt record.
name|STMT_CONTINUE
block|,
comment|/// \brief A BreakStmt record.
name|STMT_BREAK
block|,
comment|/// \brief A ReturnStmt record.
name|STMT_RETURN
block|,
comment|/// \brief A DeclStmt record.
name|STMT_DECL
block|,
comment|/// \brief A CapturedStmt record.
name|STMT_CAPTURED
block|,
comment|/// \brief A GCC-style AsmStmt record.
name|STMT_GCCASM
block|,
comment|/// \brief A MS-style AsmStmt record.
name|STMT_MSASM
block|,
comment|/// \brief A PredefinedExpr record.
name|EXPR_PREDEFINED
block|,
comment|/// \brief A DeclRefExpr record.
name|EXPR_DECL_REF
block|,
comment|/// \brief An IntegerLiteral record.
name|EXPR_INTEGER_LITERAL
block|,
comment|/// \brief A FloatingLiteral record.
name|EXPR_FLOATING_LITERAL
block|,
comment|/// \brief An ImaginaryLiteral record.
name|EXPR_IMAGINARY_LITERAL
block|,
comment|/// \brief A StringLiteral record.
name|EXPR_STRING_LITERAL
block|,
comment|/// \brief A CharacterLiteral record.
name|EXPR_CHARACTER_LITERAL
block|,
comment|/// \brief A ParenExpr record.
name|EXPR_PAREN
block|,
comment|/// \brief A ParenListExpr record.
name|EXPR_PAREN_LIST
block|,
comment|/// \brief A UnaryOperator record.
name|EXPR_UNARY_OPERATOR
block|,
comment|/// \brief An OffsetOfExpr record.
name|EXPR_OFFSETOF
block|,
comment|/// \brief A SizefAlignOfExpr record.
name|EXPR_SIZEOF_ALIGN_OF
block|,
comment|/// \brief An ArraySubscriptExpr record.
name|EXPR_ARRAY_SUBSCRIPT
block|,
comment|/// \brief A CallExpr record.
name|EXPR_CALL
block|,
comment|/// \brief A MemberExpr record.
name|EXPR_MEMBER
block|,
comment|/// \brief A BinaryOperator record.
name|EXPR_BINARY_OPERATOR
block|,
comment|/// \brief A CompoundAssignOperator record.
name|EXPR_COMPOUND_ASSIGN_OPERATOR
block|,
comment|/// \brief A ConditionOperator record.
name|EXPR_CONDITIONAL_OPERATOR
block|,
comment|/// \brief An ImplicitCastExpr record.
name|EXPR_IMPLICIT_CAST
block|,
comment|/// \brief A CStyleCastExpr record.
name|EXPR_CSTYLE_CAST
block|,
comment|/// \brief A CompoundLiteralExpr record.
name|EXPR_COMPOUND_LITERAL
block|,
comment|/// \brief An ExtVectorElementExpr record.
name|EXPR_EXT_VECTOR_ELEMENT
block|,
comment|/// \brief An InitListExpr record.
name|EXPR_INIT_LIST
block|,
comment|/// \brief A DesignatedInitExpr record.
name|EXPR_DESIGNATED_INIT
block|,
comment|/// \brief A DesignatedInitUpdateExpr record.
name|EXPR_DESIGNATED_INIT_UPDATE
block|,
comment|/// \brief An NoInitExpr record.
name|EXPR_NO_INIT
block|,
comment|/// \brief An ArrayInitLoopExpr record.
name|EXPR_ARRAY_INIT_LOOP
block|,
comment|/// \brief An ArrayInitIndexExpr record.
name|EXPR_ARRAY_INIT_INDEX
block|,
comment|/// \brief An ImplicitValueInitExpr record.
name|EXPR_IMPLICIT_VALUE_INIT
block|,
comment|/// \brief A VAArgExpr record.
name|EXPR_VA_ARG
block|,
comment|/// \brief An AddrLabelExpr record.
name|EXPR_ADDR_LABEL
block|,
comment|/// \brief A StmtExpr record.
name|EXPR_STMT
block|,
comment|/// \brief A ChooseExpr record.
name|EXPR_CHOOSE
block|,
comment|/// \brief A GNUNullExpr record.
name|EXPR_GNU_NULL
block|,
comment|/// \brief A ShuffleVectorExpr record.
name|EXPR_SHUFFLE_VECTOR
block|,
comment|/// \brief A ConvertVectorExpr record.
name|EXPR_CONVERT_VECTOR
block|,
comment|/// \brief BlockExpr
name|EXPR_BLOCK
block|,
comment|/// \brief A GenericSelectionExpr record.
name|EXPR_GENERIC_SELECTION
block|,
comment|/// \brief A PseudoObjectExpr record.
name|EXPR_PSEUDO_OBJECT
block|,
comment|/// \brief An AtomicExpr record.
name|EXPR_ATOMIC
block|,
comment|// Objective-C
comment|/// \brief An ObjCStringLiteral record.
name|EXPR_OBJC_STRING_LITERAL
block|,
name|EXPR_OBJC_BOXED_EXPRESSION
block|,
name|EXPR_OBJC_ARRAY_LITERAL
block|,
name|EXPR_OBJC_DICTIONARY_LITERAL
block|,
comment|/// \brief An ObjCEncodeExpr record.
name|EXPR_OBJC_ENCODE
block|,
comment|/// \brief An ObjCSelectorExpr record.
name|EXPR_OBJC_SELECTOR_EXPR
block|,
comment|/// \brief An ObjCProtocolExpr record.
name|EXPR_OBJC_PROTOCOL_EXPR
block|,
comment|/// \brief An ObjCIvarRefExpr record.
name|EXPR_OBJC_IVAR_REF_EXPR
block|,
comment|/// \brief An ObjCPropertyRefExpr record.
name|EXPR_OBJC_PROPERTY_REF_EXPR
block|,
comment|/// \brief An ObjCSubscriptRefExpr record.
name|EXPR_OBJC_SUBSCRIPT_REF_EXPR
block|,
comment|/// \brief UNUSED
name|EXPR_OBJC_KVC_REF_EXPR
block|,
comment|/// \brief An ObjCMessageExpr record.
name|EXPR_OBJC_MESSAGE_EXPR
block|,
comment|/// \brief An ObjCIsa Expr record.
name|EXPR_OBJC_ISA
block|,
comment|/// \brief An ObjCIndirectCopyRestoreExpr record.
name|EXPR_OBJC_INDIRECT_COPY_RESTORE
block|,
comment|/// \brief An ObjCForCollectionStmt record.
name|STMT_OBJC_FOR_COLLECTION
block|,
comment|/// \brief An ObjCAtCatchStmt record.
name|STMT_OBJC_CATCH
block|,
comment|/// \brief An ObjCAtFinallyStmt record.
name|STMT_OBJC_FINALLY
block|,
comment|/// \brief An ObjCAtTryStmt record.
name|STMT_OBJC_AT_TRY
block|,
comment|/// \brief An ObjCAtSynchronizedStmt record.
name|STMT_OBJC_AT_SYNCHRONIZED
block|,
comment|/// \brief An ObjCAtThrowStmt record.
name|STMT_OBJC_AT_THROW
block|,
comment|/// \brief An ObjCAutoreleasePoolStmt record.
name|STMT_OBJC_AUTORELEASE_POOL
block|,
comment|/// \brief An ObjCBoolLiteralExpr record.
name|EXPR_OBJC_BOOL_LITERAL
block|,
comment|/// \brief An ObjCAvailabilityCheckExpr record.
name|EXPR_OBJC_AVAILABILITY_CHECK
block|,
comment|// C++
comment|/// \brief A CXXCatchStmt record.
name|STMT_CXX_CATCH
block|,
comment|/// \brief A CXXTryStmt record.
name|STMT_CXX_TRY
block|,
comment|/// \brief A CXXForRangeStmt record.
name|STMT_CXX_FOR_RANGE
block|,
comment|/// \brief A CXXOperatorCallExpr record.
name|EXPR_CXX_OPERATOR_CALL
block|,
comment|/// \brief A CXXMemberCallExpr record.
name|EXPR_CXX_MEMBER_CALL
block|,
comment|/// \brief A CXXConstructExpr record.
name|EXPR_CXX_CONSTRUCT
block|,
comment|/// \brief A CXXInheritedCtorInitExpr record.
name|EXPR_CXX_INHERITED_CTOR_INIT
block|,
comment|/// \brief A CXXTemporaryObjectExpr record.
name|EXPR_CXX_TEMPORARY_OBJECT
block|,
comment|/// \brief A CXXStaticCastExpr record.
name|EXPR_CXX_STATIC_CAST
block|,
comment|/// \brief A CXXDynamicCastExpr record.
name|EXPR_CXX_DYNAMIC_CAST
block|,
comment|/// \brief A CXXReinterpretCastExpr record.
name|EXPR_CXX_REINTERPRET_CAST
block|,
comment|/// \brief A CXXConstCastExpr record.
name|EXPR_CXX_CONST_CAST
block|,
comment|/// \brief A CXXFunctionalCastExpr record.
name|EXPR_CXX_FUNCTIONAL_CAST
block|,
comment|/// \brief A UserDefinedLiteral record.
name|EXPR_USER_DEFINED_LITERAL
block|,
comment|/// \brief A CXXStdInitializerListExpr record.
name|EXPR_CXX_STD_INITIALIZER_LIST
block|,
comment|/// \brief A CXXBoolLiteralExpr record.
name|EXPR_CXX_BOOL_LITERAL
block|,
name|EXPR_CXX_NULL_PTR_LITERAL
block|,
comment|// CXXNullPtrLiteralExpr
name|EXPR_CXX_TYPEID_EXPR
block|,
comment|// CXXTypeidExpr (of expr).
name|EXPR_CXX_TYPEID_TYPE
block|,
comment|// CXXTypeidExpr (of type).
name|EXPR_CXX_THIS
block|,
comment|// CXXThisExpr
name|EXPR_CXX_THROW
block|,
comment|// CXXThrowExpr
name|EXPR_CXX_DEFAULT_ARG
block|,
comment|// CXXDefaultArgExpr
name|EXPR_CXX_DEFAULT_INIT
block|,
comment|// CXXDefaultInitExpr
name|EXPR_CXX_BIND_TEMPORARY
block|,
comment|// CXXBindTemporaryExpr
name|EXPR_CXX_SCALAR_VALUE_INIT
block|,
comment|// CXXScalarValueInitExpr
name|EXPR_CXX_NEW
block|,
comment|// CXXNewExpr
name|EXPR_CXX_DELETE
block|,
comment|// CXXDeleteExpr
name|EXPR_CXX_PSEUDO_DESTRUCTOR
block|,
comment|// CXXPseudoDestructorExpr
name|EXPR_EXPR_WITH_CLEANUPS
block|,
comment|// ExprWithCleanups
name|EXPR_CXX_DEPENDENT_SCOPE_MEMBER
block|,
comment|// CXXDependentScopeMemberExpr
name|EXPR_CXX_DEPENDENT_SCOPE_DECL_REF
block|,
comment|// DependentScopeDeclRefExpr
name|EXPR_CXX_UNRESOLVED_CONSTRUCT
block|,
comment|// CXXUnresolvedConstructExpr
name|EXPR_CXX_UNRESOLVED_MEMBER
block|,
comment|// UnresolvedMemberExpr
name|EXPR_CXX_UNRESOLVED_LOOKUP
block|,
comment|// UnresolvedLookupExpr
name|EXPR_CXX_EXPRESSION_TRAIT
block|,
comment|// ExpressionTraitExpr
name|EXPR_CXX_NOEXCEPT
block|,
comment|// CXXNoexceptExpr
name|EXPR_OPAQUE_VALUE
block|,
comment|// OpaqueValueExpr
name|EXPR_BINARY_CONDITIONAL_OPERATOR
block|,
comment|// BinaryConditionalOperator
name|EXPR_TYPE_TRAIT
block|,
comment|// TypeTraitExpr
name|EXPR_ARRAY_TYPE_TRAIT
block|,
comment|// ArrayTypeTraitIntExpr
name|EXPR_PACK_EXPANSION
block|,
comment|// PackExpansionExpr
name|EXPR_SIZEOF_PACK
block|,
comment|// SizeOfPackExpr
name|EXPR_SUBST_NON_TYPE_TEMPLATE_PARM
block|,
comment|// SubstNonTypeTemplateParmExpr
name|EXPR_SUBST_NON_TYPE_TEMPLATE_PARM_PACK
block|,
comment|// SubstNonTypeTemplateParmPackExpr
name|EXPR_FUNCTION_PARM_PACK
block|,
comment|// FunctionParmPackExpr
name|EXPR_MATERIALIZE_TEMPORARY
block|,
comment|// MaterializeTemporaryExpr
name|EXPR_CXX_FOLD
block|,
comment|// CXXFoldExpr
comment|// CUDA
name|EXPR_CUDA_KERNEL_CALL
block|,
comment|// CUDAKernelCallExpr
comment|// OpenCL
name|EXPR_ASTYPE
block|,
comment|// AsTypeExpr
comment|// Microsoft
name|EXPR_CXX_PROPERTY_REF_EXPR
block|,
comment|// MSPropertyRefExpr
name|EXPR_CXX_PROPERTY_SUBSCRIPT_EXPR
block|,
comment|// MSPropertySubscriptExpr
name|EXPR_CXX_UUIDOF_EXPR
block|,
comment|// CXXUuidofExpr (of expr).
name|EXPR_CXX_UUIDOF_TYPE
block|,
comment|// CXXUuidofExpr (of type).
name|STMT_SEH_LEAVE
block|,
comment|// SEHLeaveStmt
name|STMT_SEH_EXCEPT
block|,
comment|// SEHExceptStmt
name|STMT_SEH_FINALLY
block|,
comment|// SEHFinallyStmt
name|STMT_SEH_TRY
block|,
comment|// SEHTryStmt
comment|// OpenMP directives
name|STMT_OMP_PARALLEL_DIRECTIVE
block|,
name|STMT_OMP_SIMD_DIRECTIVE
block|,
name|STMT_OMP_FOR_DIRECTIVE
block|,
name|STMT_OMP_FOR_SIMD_DIRECTIVE
block|,
name|STMT_OMP_SECTIONS_DIRECTIVE
block|,
name|STMT_OMP_SECTION_DIRECTIVE
block|,
name|STMT_OMP_SINGLE_DIRECTIVE
block|,
name|STMT_OMP_MASTER_DIRECTIVE
block|,
name|STMT_OMP_CRITICAL_DIRECTIVE
block|,
name|STMT_OMP_PARALLEL_FOR_DIRECTIVE
block|,
name|STMT_OMP_PARALLEL_FOR_SIMD_DIRECTIVE
block|,
name|STMT_OMP_PARALLEL_SECTIONS_DIRECTIVE
block|,
name|STMT_OMP_TASK_DIRECTIVE
block|,
name|STMT_OMP_TASKYIELD_DIRECTIVE
block|,
name|STMT_OMP_BARRIER_DIRECTIVE
block|,
name|STMT_OMP_TASKWAIT_DIRECTIVE
block|,
name|STMT_OMP_FLUSH_DIRECTIVE
block|,
name|STMT_OMP_ORDERED_DIRECTIVE
block|,
name|STMT_OMP_ATOMIC_DIRECTIVE
block|,
name|STMT_OMP_TARGET_DIRECTIVE
block|,
name|STMT_OMP_TARGET_DATA_DIRECTIVE
block|,
name|STMT_OMP_TARGET_ENTER_DATA_DIRECTIVE
block|,
name|STMT_OMP_TARGET_EXIT_DATA_DIRECTIVE
block|,
name|STMT_OMP_TARGET_PARALLEL_DIRECTIVE
block|,
name|STMT_OMP_TARGET_PARALLEL_FOR_DIRECTIVE
block|,
name|STMT_OMP_TEAMS_DIRECTIVE
block|,
name|STMT_OMP_TASKGROUP_DIRECTIVE
block|,
name|STMT_OMP_CANCELLATION_POINT_DIRECTIVE
block|,
name|STMT_OMP_CANCEL_DIRECTIVE
block|,
name|STMT_OMP_TASKLOOP_DIRECTIVE
block|,
name|STMT_OMP_TASKLOOP_SIMD_DIRECTIVE
block|,
name|STMT_OMP_DISTRIBUTE_DIRECTIVE
block|,
name|STMT_OMP_TARGET_UPDATE_DIRECTIVE
block|,
name|STMT_OMP_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE
block|,
name|STMT_OMP_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE
block|,
name|STMT_OMP_DISTRIBUTE_SIMD_DIRECTIVE
block|,
name|STMT_OMP_TARGET_PARALLEL_FOR_SIMD_DIRECTIVE
block|,
name|STMT_OMP_TARGET_SIMD_DIRECTIVE
block|,
name|STMT_OMP_TEAMS_DISTRIBUTE_DIRECTIVE
block|,
name|STMT_OMP_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE
block|,
name|STMT_OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE
block|,
name|STMT_OMP_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE
block|,
name|STMT_OMP_TARGET_TEAMS_DIRECTIVE
block|,
name|STMT_OMP_TARGET_TEAMS_DISTRIBUTE_DIRECTIVE
block|,
name|STMT_OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_DIRECTIVE
block|,
name|STMT_OMP_TARGET_TEAMS_DISTRIBUTE_PARALLEL_FOR_SIMD_DIRECTIVE
block|,
name|STMT_OMP_TARGET_TEAMS_DISTRIBUTE_SIMD_DIRECTIVE
block|,
name|EXPR_OMP_ARRAY_SECTION
block|,
comment|// ARC
name|EXPR_OBJC_BRIDGED_CAST
block|,
comment|// ObjCBridgedCastExpr
name|STMT_MS_DEPENDENT_EXISTS
block|,
comment|// MSDependentExistsStmt
name|EXPR_LAMBDA
comment|// LambdaExpr
block|}
enum|;
comment|/// \brief The kinds of designators that can occur in a
comment|/// DesignatedInitExpr.
enum|enum
name|DesignatorTypes
block|{
comment|/// \brief Field designator where only the field name is known.
name|DESIG_FIELD_NAME
init|=
literal|0
block|,
comment|/// \brief Field designator where the field has been resolved to
comment|/// a declaration.
name|DESIG_FIELD_DECL
init|=
literal|1
block|,
comment|/// \brief Array designator.
name|DESIG_ARRAY
init|=
literal|2
block|,
comment|/// \brief GNU array range designator.
name|DESIG_ARRAY_RANGE
init|=
literal|3
block|}
enum|;
comment|/// \brief The different kinds of data that can occur in a
comment|/// CtorInitializer.
enum|enum
name|CtorInitializerType
block|{
name|CTOR_INITIALIZER_BASE
block|,
name|CTOR_INITIALIZER_DELEGATING
block|,
name|CTOR_INITIALIZER_MEMBER
block|,
name|CTOR_INITIALIZER_INDIRECT_MEMBER
block|}
enum|;
comment|/// \brief Describes the redeclarations of a declaration.
struct|struct
name|LocalRedeclarationsInfo
block|{
name|DeclID
name|FirstID
decl_stmt|;
comment|// The ID of the first declaration
name|unsigned
name|Offset
decl_stmt|;
comment|// Offset into the array of redeclaration chains.
name|friend
name|bool
name|operator
operator|<
operator|(
specifier|const
name|LocalRedeclarationsInfo
operator|&
name|X
operator|,
specifier|const
name|LocalRedeclarationsInfo
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|FirstID
operator|<
name|Y
operator|.
name|FirstID
return|;
block|}
name|friend
name|bool
name|operator
operator|>
operator|(
specifier|const
name|LocalRedeclarationsInfo
operator|&
name|X
operator|,
specifier|const
name|LocalRedeclarationsInfo
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|FirstID
operator|>
name|Y
operator|.
name|FirstID
return|;
block|}
name|friend
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|LocalRedeclarationsInfo
operator|&
name|X
operator|,
specifier|const
name|LocalRedeclarationsInfo
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|FirstID
operator|<=
name|Y
operator|.
name|FirstID
return|;
block|}
name|friend
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|LocalRedeclarationsInfo
operator|&
name|X
operator|,
specifier|const
name|LocalRedeclarationsInfo
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|FirstID
operator|>=
name|Y
operator|.
name|FirstID
return|;
block|}
block|}
struct|;
comment|/// \brief Describes the categories of an Objective-C class.
struct|struct
name|ObjCCategoriesInfo
block|{
name|DeclID
name|DefinitionID
decl_stmt|;
comment|// The ID of the definition
name|unsigned
name|Offset
decl_stmt|;
comment|// Offset into the array of category lists.
name|friend
name|bool
name|operator
operator|<
operator|(
specifier|const
name|ObjCCategoriesInfo
operator|&
name|X
operator|,
specifier|const
name|ObjCCategoriesInfo
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|DefinitionID
operator|<
name|Y
operator|.
name|DefinitionID
return|;
block|}
name|friend
name|bool
name|operator
operator|>
operator|(
specifier|const
name|ObjCCategoriesInfo
operator|&
name|X
operator|,
specifier|const
name|ObjCCategoriesInfo
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|DefinitionID
operator|>
name|Y
operator|.
name|DefinitionID
return|;
block|}
name|friend
name|bool
name|operator
operator|<=
operator|(
specifier|const
name|ObjCCategoriesInfo
operator|&
name|X
operator|,
specifier|const
name|ObjCCategoriesInfo
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|DefinitionID
operator|<=
name|Y
operator|.
name|DefinitionID
return|;
block|}
name|friend
name|bool
name|operator
operator|>=
operator|(
specifier|const
name|ObjCCategoriesInfo
operator|&
name|X
operator|,
specifier|const
name|ObjCCategoriesInfo
operator|&
name|Y
operator|)
block|{
return|return
name|X
operator|.
name|DefinitionID
operator|>=
name|Y
operator|.
name|DefinitionID
return|;
block|}
block|}
struct|;
comment|/// \brief A key used when looking up entities by \ref DeclarationName.
comment|///
comment|/// Different \ref DeclarationNames are mapped to different keys, but the
comment|/// same key can occasionally represent multiple names (for names that
comment|/// contain types, in particular).
name|class
name|DeclarationNameKey
block|{
typedef|typedef
name|unsigned
name|NameKind
typedef|;
name|NameKind
name|Kind
decl_stmt|;
name|uint64_t
name|Data
decl_stmt|;
name|public
label|:
name|DeclarationNameKey
argument_list|()
operator|:
name|Kind
argument_list|()
operator|,
name|Data
argument_list|()
block|{}
name|DeclarationNameKey
argument_list|(
argument|DeclarationName Name
argument_list|)
expr_stmt|;
name|DeclarationNameKey
argument_list|(
argument|NameKind Kind
argument_list|,
argument|uint64_t Data
argument_list|)
block|:
name|Kind
argument_list|(
name|Kind
argument_list|)
operator|,
name|Data
argument_list|(
argument|Data
argument_list|)
block|{}
name|NameKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|IdentifierInfo
operator|*
name|getIdentifier
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|DeclarationName
operator|::
name|Identifier
operator|||
name|Kind
operator|==
name|DeclarationName
operator|::
name|CXXLiteralOperatorName
operator|||
name|Kind
operator|==
name|DeclarationName
operator|::
name|CXXDeductionGuideName
argument_list|)
block|;
return|return
operator|(
name|IdentifierInfo
operator|*
operator|)
name|Data
return|;
block|}
name|Selector
name|getSelector
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|DeclarationName
operator|::
name|ObjCZeroArgSelector
operator|||
name|Kind
operator|==
name|DeclarationName
operator|::
name|ObjCOneArgSelector
operator|||
name|Kind
operator|==
name|DeclarationName
operator|::
name|ObjCMultiArgSelector
argument_list|)
block|;
return|return
name|Selector
argument_list|(
name|Data
argument_list|)
return|;
block|}
name|OverloadedOperatorKind
name|getOperatorKind
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
name|Kind
operator|==
name|DeclarationName
operator|::
name|CXXOperatorName
argument_list|)
block|;
return|return
operator|(
name|OverloadedOperatorKind
operator|)
name|Data
return|;
block|}
comment|/// Compute a fingerprint of this key for use in on-disk hash table.
name|unsigned
name|getHash
argument_list|()
specifier|const
expr_stmt|;
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|DeclarationNameKey
operator|&
name|A
operator|,
specifier|const
name|DeclarationNameKey
operator|&
name|B
operator|)
block|{
return|return
name|A
operator|.
name|Kind
operator|==
name|B
operator|.
name|Kind
operator|&&
name|A
operator|.
name|Data
operator|==
name|B
operator|.
name|Data
return|;
block|}
block|}
empty_stmt|;
comment|/// @}
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|clang
operator|::
name|serialization
operator|::
name|DeclarationNameKey
operator|>
block|{
specifier|static
name|clang
operator|::
name|serialization
operator|::
name|DeclarationNameKey
name|getEmptyKey
argument_list|()
block|{
return|return
name|clang
operator|::
name|serialization
operator|::
name|DeclarationNameKey
argument_list|(
operator|-
literal|1
argument_list|,
literal|1
argument_list|)
return|;
block|}
specifier|static
name|clang
operator|::
name|serialization
operator|::
name|DeclarationNameKey
name|getTombstoneKey
argument_list|()
block|{
return|return
name|clang
operator|::
name|serialization
operator|::
name|DeclarationNameKey
argument_list|(
operator|-
literal|1
argument_list|,
literal|2
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
argument|const clang::serialization::DeclarationNameKey&Key
argument_list|)
block|{
return|return
name|Key
operator|.
name|getHash
argument_list|()
return|;
block|}
specifier|static
name|bool
name|isEqual
argument_list|(
argument|const clang::serialization::DeclarationNameKey&L
argument_list|,
argument|const clang::serialization::DeclarationNameKey&R
argument_list|)
block|{
return|return
name|L
operator|==
name|R
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

