begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- PCHBitCodes.h - Enum values for the PCH bitcode format ---*- C++ -*-===//
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
comment|// This header defines Bitcode enum values for Clang precompiled header files.
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
file|"llvm/Bitcode/BitCodes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/System/DataTypes.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|pch
block|{
comment|/// \brief PCH major version number supported by this version of
comment|/// Clang.
comment|///
comment|/// Whenever the PCH format changes in a way that makes it
comment|/// incompatible with previous versions (such that a reader
comment|/// designed for the previous version could not support reading
comment|/// the new version), this number should be increased.
comment|///
comment|/// Version 3 of PCH files also requires that the Subversion branch and
comment|/// revision match exactly, since there is no backward compatibility of
comment|/// PCH files at this time.
specifier|const
name|unsigned
name|VERSION_MAJOR
init|=
literal|3
decl_stmt|;
comment|/// \brief PCH minor version number supported by this version of
comment|/// Clang.
comment|///
comment|/// Whenever the PCH format changes in a way that is still
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
comment|/// \brief An ID number that refers to a declaration in a PCH file.
comment|///
comment|/// The ID numbers of types are consecutive (in order of
comment|/// discovery) and start at 2. 0 is reserved for NULL, and 1 is
comment|/// reserved for the translation unit declaration.
typedef|typedef
name|uint32_t
name|DeclID
typedef|;
comment|/// \brief An ID number that refers to a type in a PCH file.
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
comment|/// \brief An ID number that refers to an identifier in a PCH
comment|/// file.
typedef|typedef
name|uint32_t
name|IdentID
typedef|;
typedef|typedef
name|uint32_t
name|SelectorID
typedef|;
comment|/// \brief Describes the various kinds of blocks that occur within
comment|/// a PCH file.
enum|enum
name|BlockIDs
block|{
comment|/// \brief The PCH block, which acts as a container around the
comment|/// full PCH block.
name|PCH_BLOCK_ID
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
comment|/// types and decls used within the PCH file.
name|DECLTYPES_BLOCK_ID
block|}
enum|;
comment|/// \brief Record types that occur within the PCH block itself.
enum|enum
name|PCHRecordTypes
block|{
comment|/// \brief Record code for the offsets of each type.
comment|///
comment|/// The TYPE_OFFSET constant describes the record that occurs
comment|/// within the PCH block. The record itself is an array of offsets that
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
comment|/// the PCH block. The record itself is an array of offsets that
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
comment|/// \brief PCH metadata, including the PCH file version number
comment|/// and the target triple used to build the PCH file.
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
comment|/// referenced by the PCH file. The IDENTIFIER_OFFSET table
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
comment|/// The PCH file contains a list of all of the unnamed external
comment|/// definitions present within the parsed headers, stored as an
comment|/// array of declaration IDs. These external definitions will be
comment|/// reported to the AST consumer after the PCH file has been
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
comment|/// generating a PCH file.
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
comment|/// that need to be preloaded by the PCH reader.
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
comment|/// generate the precompiled header.
name|ORIGINAL_FILE_NAME
init|=
literal|19
block|,
comment|/// \brief Record code for the sorted array of source ranges where
comment|/// comments were encountered in the source code.
name|COMMENT_RANGES
init|=
literal|20
block|,
comment|/// \brief Record code for the Subversion branch and revision information
comment|/// of the compiler used to build this PCH file.
name|SVN_BRANCH_REVISION
init|=
literal|21
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
block|,
comment|/// \brief Describes one header file info [isImport, DirInfo, NumIncludes]
comment|/// ControllingMacro is optional.
name|SM_HEADER_FILE_INFO
init|=
literal|6
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
comment|/// \defgroup PCHAST Precompiled header AST constants
comment|///
comment|/// The constants in this group describe various components of the
comment|/// abstract syntax tree within a precompiled header.
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
comment|/// block identified by DECLTYPES_BLOCK_ID in the PCH file. Each
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
comment|/// \brief A FixedWidthIntType record.
name|TYPE_FIXED_WIDTH_INT
init|=
literal|2
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
comment|/// \brief Attributes attached to a declaration.
name|DECL_ATTR
init|=
literal|50
block|,
comment|/// \brief A TranslationUnitDecl record.
name|DECL_TRANSLATION_UNIT
block|,
comment|/// \brief A TypedefDecl record.
name|DECL_TYPEDEF
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
comment|/// The record itself is an array of declaration IDs, in the
comment|/// order in which those declarations were added to the
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
comment|/// \brief A UnaryOperator record.
name|EXPR_UNARY_OPERATOR
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
comment|/// \brief A TypesCompatibleExpr record.
name|EXPR_TYPES_COMPATIBLE
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
comment|/// \brief An ObjCImplicitSetterGetterRefExpr record.
name|EXPR_OBJC_KVC_REF_EXPR
block|,
comment|/// \brief An ObjCMessageExpr record.
name|EXPR_OBJC_MESSAGE_EXPR
block|,
comment|/// \brief An ObjCSuperExpr record.
name|EXPR_OBJC_SUPER_EXPR
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
comment|/// \brief A CXXOperatorCallExpr record.
name|EXPR_CXX_OPERATOR_CALL
block|,
comment|/// \brief A CXXConstructExpr record.
name|EXPR_CXX_CONSTRUCT
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

