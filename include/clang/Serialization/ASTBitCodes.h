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
name|LLVM_CLANG_FRONTEND_PCHBITCODES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_FRONTEND_PCHBITCODES_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
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

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
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
literal|4
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
comment|/// \brief An ID number that refers to a declaration in an AST file.
comment|///
comment|/// The ID numbers of declarations are consecutive (in order of
comment|/// discovery) and start at 2. 0 is reserved for NULL, and 1 is
comment|/// reserved for the translation unit declaration.
typedef|typedef
name|uint32_t
name|DeclID
typedef|;
comment|/// \brief a Decl::Kind/DeclID pair.
typedef|typedef
name|std
operator|::
name|pair
operator|<
name|uint32_t
operator|,
name|DeclID
operator|>
name|KindDeclIDPair
expr_stmt|;
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
comment|/// \brief Map that provides the ID numbers of each type within the
comment|/// output stream, plus those deserialized from a chained PCH.
comment|///
comment|/// The ID numbers of types are consecutive (in order of discovery)
comment|/// and start at 1. 0 is reserved for NULL. When types are actually
comment|/// stored in the stream, the ID number is shifted by 2 bits to
comment|/// allow for the const/volatile qualifiers.
comment|///
comment|/// Keys in the map never have const/volatile qualifiers.
typedef|typedef
name|llvm
operator|::
name|DenseMap
operator|<
name|QualType
operator|,
name|TypeIdx
operator|,
name|UnsafeQualTypeDenseMapInfo
operator|>
name|TypeIdxMap
expr_stmt|;
comment|/// \brief An ID number that refers to an identifier in an AST file.
typedef|typedef
name|uint32_t
name|IdentID
typedef|;
comment|/// \brief An ID number that refers to a macro in an AST file.
typedef|typedef
name|uint32_t
name|MacroID
typedef|;
comment|/// \brief An ID number that refers to an ObjC selctor in an AST file.
typedef|typedef
name|uint32_t
name|SelectorID
typedef|;
comment|/// \brief An ID number that refers to a set of CXXBaseSpecifiers in an
comment|/// AST file.
typedef|typedef
name|uint32_t
name|CXXBaseSpecifiersID
typedef|;
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
comment|/// \brief The block containing DECL_UPDATES records.
name|DECL_UPDATES_BLOCK_ID
block|,
comment|/// \brief The block containing the detailed preprocessing record.
name|PREPROCESSOR_DETAIL_BLOCK_ID
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
comment|/// \brief Record code for the language options table.
comment|///
comment|/// The record with this code contains the contents of the
comment|/// LangOptions structure. We serialize the entire contents of
comment|/// the structure, and let the reader decide which options are
comment|/// actually important to check.
name|LANGUAGE_OPTIONS
init|=
literal|3
block|,
comment|/// \brief AST file metadata, including the AST file version number
comment|/// and the target triple used to build the AST file.
name|METADATA
init|=
literal|4
block|,
comment|/// \brief Record code for the table of offsets of each
comment|/// identifier ID.
comment|///
comment|/// The offset table contains offsets into the blob stored in
comment|/// the IDENTIFIER_TABLE record. Each offset points to the
comment|/// NULL-terminated string that corresponds to that identifier.
name|IDENTIFIER_OFFSET
init|=
literal|5
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
literal|6
block|,
comment|/// \brief Record code for the array of external definitions.
comment|///
comment|/// The AST file contains a list of all of the unnamed external
comment|/// definitions present within the parsed headers, stored as an
comment|/// array of declaration IDs. These external definitions will be
comment|/// reported to the AST consumer after the AST file has been
comment|/// read, since their presence can affect the semantics of the
comment|/// program (e.g., for code generation).
name|EXTERNAL_DEFINITIONS
init|=
literal|7
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
literal|8
block|,
comment|/// \brief Record code for the extra statistics we gather while
comment|/// generating an AST file.
name|STATISTICS
init|=
literal|9
block|,
comment|/// \brief Record code for the array of tentative definitions.
name|TENTATIVE_DEFINITIONS
init|=
literal|10
block|,
comment|/// \brief Record code for the array of locally-scoped external
comment|/// declarations.
name|LOCALLY_SCOPED_EXTERNAL_DECLS
init|=
literal|11
block|,
comment|/// \brief Record code for the table of offsets into the
comment|/// Objective-C method pool.
name|SELECTOR_OFFSETS
init|=
literal|12
block|,
comment|/// \brief Record code for the Objective-C method pool,
name|METHOD_POOL
init|=
literal|13
block|,
comment|/// \brief The value of the next __COUNTER__ to dispense.
comment|/// [PP_COUNTER_VALUE, Val]
name|PP_COUNTER_VALUE
init|=
literal|14
block|,
comment|/// \brief Record code for the table of offsets into the block
comment|/// of source-location information.
name|SOURCE_LOCATION_OFFSETS
init|=
literal|15
block|,
comment|/// \brief Record code for the set of source location entries
comment|/// that need to be preloaded by the AST reader.
comment|///
comment|/// This set contains the source location entry for the
comment|/// predefines buffer and for any file entries that need to be
comment|/// preloaded.
name|SOURCE_LOCATION_PRELOADS
init|=
literal|16
block|,
comment|/// \brief Record code for the stat() cache.
name|STAT_CACHE
init|=
literal|17
block|,
comment|/// \brief Record code for the set of ext_vector type names.
name|EXT_VECTOR_DECLS
init|=
literal|18
block|,
comment|/// \brief Record code for the original file that was used to
comment|/// generate the AST file.
name|ORIGINAL_FILE_NAME
init|=
literal|19
block|,
comment|/// Record #20 intentionally left blank.
comment|/// \brief Record code for the version control branch and revision
comment|/// information of the compiler used to build this AST file.
name|VERSION_CONTROL_BRANCH_REVISION
init|=
literal|21
block|,
comment|/// \brief Record code for the array of unused file scoped decls.
name|UNUSED_FILESCOPED_DECLS
init|=
literal|22
block|,
comment|/// \brief Record code for the table of offsets to macro definition
comment|/// entries in the preprocessing record.
name|MACRO_DEFINITION_OFFSETS
init|=
literal|23
block|,
comment|/// \brief Record code for the array of VTable uses.
name|VTABLE_USES
init|=
literal|24
block|,
comment|/// \brief Record code for the array of dynamic classes.
name|DYNAMIC_CLASSES
init|=
literal|25
block|,
comment|/// \brief Record code for the chained AST metadata, including the
comment|/// AST file version and the name of the PCH this depends on.
name|CHAINED_METADATA
init|=
literal|26
block|,
comment|/// \brief Record code for referenced selector pool.
name|REFERENCED_SELECTOR_POOL
init|=
literal|27
block|,
comment|/// \brief Record code for an update to the TU's lexically contained
comment|/// declarations.
name|TU_UPDATE_LEXICAL
init|=
literal|28
block|,
comment|/// \brief Record code for an update to first decls pointing to the
comment|/// latest redeclarations.
name|REDECLS_UPDATE_LATEST
init|=
literal|29
block|,
comment|/// \brief Record code for declarations that Sema keeps references of.
name|SEMA_DECL_REFS
init|=
literal|30
block|,
comment|/// \brief Record code for weak undeclared identifiers.
name|WEAK_UNDECLARED_IDENTIFIERS
init|=
literal|31
block|,
comment|/// \brief Record code for pending implicit instantiations.
name|PENDING_IMPLICIT_INSTANTIATIONS
init|=
literal|32
block|,
comment|/// \brief Record code for a decl replacement block.
comment|///
comment|/// If a declaration is modified after having been deserialized, and then
comment|/// written to a dependent AST file, its ID and offset must be added to
comment|/// the replacement block.
name|DECL_REPLACEMENTS
init|=
literal|33
block|,
comment|/// \brief Record code for an update to a decl context's lookup table.
comment|///
comment|/// In practice, this should only be used for the TU and namespaces.
name|UPDATE_VISIBLE
init|=
literal|34
block|,
comment|/// \brief Record for offsets of DECL_UPDATES records for declarations
comment|/// that were modified after being deserialized and need updates.
name|DECL_UPDATE_OFFSETS
init|=
literal|35
block|,
comment|/// \brief Record of updates for a declaration that was modified after
comment|/// being deserialized.
name|DECL_UPDATES
init|=
literal|36
block|,
comment|/// \brief Record code for the table of offsets to CXXBaseSpecifier
comment|/// sets.
name|CXX_BASE_SPECIFIER_OFFSETS
init|=
literal|37
block|,
comment|/// \brief Record code for #pragma diagnostic mappings.
name|DIAG_PRAGMA_MAPPINGS
init|=
literal|38
block|,
comment|/// \brief Record code for special CUDA declarations.
name|CUDA_SPECIAL_DECL_REFS
init|=
literal|39
block|,
comment|/// \brief Record code for header search information.
name|HEADER_SEARCH_TABLE
init|=
literal|40
block|,
comment|/// \brief The directory that the PCH was originally created in.
name|ORIGINAL_PCH_DIR
init|=
literal|41
block|,
comment|/// \brief Record code for floating point #pragma options.
name|FP_PRAGMA_OPTIONS
init|=
literal|42
block|,
comment|/// \brief Record code for enabled OpenCL extensions.
name|OPENCL_EXTENSIONS
init|=
literal|43
block|}
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
comment|/// SM_SLOC_BUFFER_ENTRY record.
name|SM_SLOC_BUFFER_BLOB
init|=
literal|3
block|,
comment|/// \brief Describes a source location entry (SLocEntry) for a
comment|/// macro instantiation.
name|SM_SLOC_INSTANTIATION_ENTRY
init|=
literal|4
block|,
comment|/// \brief Describes the SourceManager's line table, with
comment|/// information about #line directives.
name|SM_LINE_TABLE
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
comment|/// [PP_MACRO_FUNCTION_LIKE,<ObjectLikeStuff>, IsC99Varargs, IsGNUVarars,
comment|///  NumArgs, ArgIdentInfoID* ]
name|PP_MACRO_FUNCTION_LIKE
init|=
literal|2
block|,
comment|/// \brief Describes one token.
comment|/// [PP_TOKEN, SLoc, Length, IdentInfoID, Kind, Flags]
name|PP_TOKEN
init|=
literal|3
block|}
enum|;
comment|/// \brief Record types used within a preprocessor detail block.
enum|enum
name|PreprocessorDetailRecordTypes
block|{
comment|/// \brief Describes a macro instantiation within the preprocessing
comment|/// record.
name|PPD_MACRO_INSTANTIATION
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
comment|/// types (the<overload> and<dependent> type markers). Such
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
comment|/// AST.
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
comment|/// \brief __builtin_va_list
name|SPECIAL_TYPE_BUILTIN_VA_LIST
init|=
literal|0
block|,
comment|/// \brief Objective-C "id" type
name|SPECIAL_TYPE_OBJC_ID
init|=
literal|1
block|,
comment|/// \brief Objective-C selector type
name|SPECIAL_TYPE_OBJC_SELECTOR
init|=
literal|2
block|,
comment|/// \brief Objective-C Protocol type
name|SPECIAL_TYPE_OBJC_PROTOCOL
init|=
literal|3
block|,
comment|/// \brief Objective-C Class type
name|SPECIAL_TYPE_OBJC_CLASS
init|=
literal|4
block|,
comment|/// \brief CFConstantString type
name|SPECIAL_TYPE_CF_CONSTANT_STRING
init|=
literal|5
block|,
comment|/// \brief Objective-C fast enumeration state type
name|SPECIAL_TYPE_OBJC_FAST_ENUMERATION_STATE
init|=
literal|6
block|,
comment|/// \brief C FILE typedef type
name|SPECIAL_TYPE_FILE
init|=
literal|7
block|,
comment|/// \brief C jmp_buf typedef type
name|SPECIAL_TYPE_jmp_buf
init|=
literal|8
block|,
comment|/// \brief C sigjmp_buf typedef type
name|SPECIAL_TYPE_sigjmp_buf
init|=
literal|9
block|,
comment|/// \brief Objective-C "id" redefinition type
name|SPECIAL_TYPE_OBJC_ID_REDEFINITION
init|=
literal|10
block|,
comment|/// \brief Objective-C "Class" redefinition type
name|SPECIAL_TYPE_OBJC_CLASS_REDEFINITION
init|=
literal|11
block|,
comment|/// \brief Block descriptor type for Blocks CodeGen
name|SPECIAL_TYPE_BLOCK_DESCRIPTOR
init|=
literal|12
block|,
comment|/// \brief Block extedned descriptor type for Blocks CodeGen
name|SPECIAL_TYPE_BLOCK_EXTENDED_DESCRIPTOR
init|=
literal|13
block|,
comment|/// \brief Objective-C "SEL" redefinition type
name|SPECIAL_TYPE_OBJC_SEL_REDEFINITION
init|=
literal|14
block|,
comment|/// \brief NSConstantString type
name|SPECIAL_TYPE_NS_CONSTANT_STRING
init|=
literal|15
block|,
comment|/// \brief Whether __[u]int128_t identifier is installed.
name|SPECIAL_TYPE_INT128_INSTALLED
init|=
literal|16
block|,
comment|/// \brief Cached "auto" deduction type.
name|SPECIAL_TYPE_AUTO_DEDUCT
init|=
literal|17
block|,
comment|/// \brief Cached "auto&&" deduction type.
name|SPECIAL_TYPE_AUTO_RREF_DEDUCT
init|=
literal|18
block|}
enum|;
comment|/// \brief Record codes for each kind of declaration.
comment|///
comment|/// These constants describe the declaration records that can occur within
comment|/// a declarations block (identified by DECLS_BLOCK_ID). Each
comment|/// constant describes a record for a specific declaration class
comment|/// in the AST.
enum|enum
name|DeclCode
block|{
comment|/// \brief A TranslationUnitDecl record.
name|DECL_TRANSLATION_UNIT
init|=
literal|50
block|,
comment|/// \brief A TypedefDecl record.
name|DECL_TYPEDEF
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
comment|/// \brief A ObjCClassDecl record.
name|DECL_OBJC_CLASS
block|,
comment|/// \brief A ObjCForwardProtocolDecl record.
name|DECL_OBJC_FORWARD_PROTOCOL
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
comment|/// \brief A VarDecl record.
name|DECL_VAR
block|,
comment|/// \brief An ImplicitParamDecl record.
name|DECL_IMPLICIT_PARAM
block|,
comment|/// \brief A ParmVarDecl record.
name|DECL_PARM_VAR
block|,
comment|/// \brief A FileScopeAsmDecl record.
name|DECL_FILE_SCOPE_ASM
block|,
comment|/// \brief A BlockDecl record.
name|DECL_BLOCK
block|,
comment|/// \brief A record that stores the set of declarations that are
comment|/// lexically stored within a given DeclContext.
comment|///
comment|/// The record itself is a blob that is an array of declaration IDs,
comment|/// in the order in which those declarations were added to the
comment|/// declaration context. This data is used when iterating over
comment|/// the contents of a DeclContext, e.g., via
comment|/// DeclContext::decls_begin()/DeclContext::decls_end().
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
comment|/// \brief A UsingShadowDecl record.
name|DECL_USING_SHADOW
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
comment|/// \brief A CXXRecordDecl record.
name|DECL_CXX_RECORD
block|,
comment|/// \brief A CXXMethodDecl record.
name|DECL_CXX_METHOD
block|,
comment|/// \brief A CXXConstructorDecl record.
name|DECL_CXX_CONSTRUCTOR
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
comment|/// \brief A StaticAssertDecl record.
name|DECL_STATIC_ASSERT
block|,
comment|/// \brief A record containing CXXBaseSpecifiers.
name|DECL_CXX_BASE_SPECIFIERS
block|,
comment|/// \brief A IndirectFieldDecl record.
name|DECL_INDIRECTFIELD
block|,
comment|/// \brief A NonTypeTemplateParmDecl record that stores an expanded
comment|/// non-type template parameter pack.
name|DECL_EXPANDED_NON_TYPE_TEMPLATE_PARM_PACK
block|}
enum|;
comment|/// \brief Record codes for each kind of statement or expression.
comment|///
comment|/// These constants describe the records that describe statements
comment|/// or expressions. These records  occur within type and declarations
comment|/// block, so they begin with record values of 100.  Each constant
comment|/// describes a record for a specific statement or expression class in the
comment|/// AST.
enum|enum
name|StmtCode
block|{
comment|/// \brief A marker record that indicates that we are at the end
comment|/// of an expression.
name|STMT_STOP
init|=
literal|100
block|,
comment|/// \brief A NULL expression.
name|STMT_NULL_PTR
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
comment|/// \brief An AsmStmt record.
name|STMT_ASM
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
comment|/// \brief BlockExpr
name|EXPR_BLOCK
block|,
comment|/// \brief A BlockDeclRef record.
name|EXPR_BLOCK_DECL_REF
block|,
comment|/// \brief A GenericSelectionExpr record.
name|EXPR_GENERIC_SELECTION
block|,
comment|// Objective-C
comment|/// \brief An ObjCStringLiteral record.
name|EXPR_OBJC_STRING_LITERAL
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
comment|/// \brief UNUSED
name|EXPR_OBJC_KVC_REF_EXPR
block|,
comment|/// \brief An ObjCMessageExpr record.
name|EXPR_OBJC_MESSAGE_EXPR
block|,
comment|/// \brief An ObjCIsa Expr record.
name|EXPR_OBJC_ISA
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
name|EXPR_CXX_UUIDOF_EXPR
block|,
comment|// CXXUuidofExpr (of expr).
name|EXPR_CXX_UUIDOF_TYPE
block|,
comment|// CXXUuidofExpr (of type).
name|EXPR_CXX_THIS
block|,
comment|// CXXThisExpr
name|EXPR_CXX_THROW
block|,
comment|// CXXThrowExpr
name|EXPR_CXX_DEFAULT_ARG
block|,
comment|// CXXDefaultArgExpr
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
name|EXPR_CXX_UNARY_TYPE_TRAIT
block|,
comment|// UnaryTypeTraitExpr
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
name|EXPR_BINARY_TYPE_TRAIT
block|,
comment|// BinaryTypeTraitExpr
name|EXPR_ARRAY_TYPE_TRAIT
block|,
comment|// ArrayTypeTraitIntExpr
name|EXPR_PACK_EXPANSION
block|,
comment|// PackExpansionExpr
name|EXPR_SIZEOF_PACK
block|,
comment|// SizeOfPackExpr
name|EXPR_SUBST_NON_TYPE_TEMPLATE_PARM_PACK
block|,
comment|// SubstNonTypeTemplateParmPackExpr
comment|// CUDA
name|EXPR_CUDA_KERNEL_CALL
comment|// CUDAKernelCallExpr
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
comment|/// @}
block|}
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

