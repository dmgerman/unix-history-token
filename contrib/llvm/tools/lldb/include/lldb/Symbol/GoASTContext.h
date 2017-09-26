begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- GoASTContext.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_GoASTContext_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_GoASTContext_h_
end_define

begin_comment
comment|// C Includes
end_comment

begin_comment
comment|// C++ Includes
end_comment

begin_include
include|#
directive|include
file|<map>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<set>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/Symbol/CompilerType.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/TypeSystem.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Utility/ConstString.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|Declaration
decl_stmt|;
name|class
name|GoType
decl_stmt|;
name|class
name|GoASTContext
range|:
name|public
name|TypeSystem
block|{
name|public
operator|:
name|GoASTContext
argument_list|()
block|;
operator|~
name|GoASTContext
argument_list|()
name|override
block|;
comment|//------------------------------------------------------------------
comment|// PluginInterface functions
comment|//------------------------------------------------------------------
name|ConstString
name|GetPluginName
argument_list|()
name|override
block|;
name|uint32_t
name|GetPluginVersion
argument_list|()
name|override
block|;
specifier|static
name|ConstString
name|GetPluginNameStatic
argument_list|()
block|;
specifier|static
name|lldb
operator|::
name|TypeSystemSP
name|CreateInstance
argument_list|(
argument|lldb::LanguageType language
argument_list|,
argument|Module *module
argument_list|,
argument|Target *target
argument_list|)
block|;
specifier|static
name|void
name|EnumerateSupportedLanguages
argument_list|(
name|std
operator|::
name|set
operator|<
name|lldb
operator|::
name|LanguageType
operator|>
operator|&
name|languages_for_types
argument_list|,
name|std
operator|::
name|set
operator|<
name|lldb
operator|::
name|LanguageType
operator|>
operator|&
name|languages_for_expressions
argument_list|)
block|;
specifier|static
name|void
name|Initialize
argument_list|()
block|;
specifier|static
name|void
name|Terminate
argument_list|()
block|;
name|DWARFASTParser
operator|*
name|GetDWARFParser
argument_list|()
name|override
block|;
name|void
name|SetAddressByteSize
argument_list|(
argument|int byte_size
argument_list|)
block|{
name|m_pointer_byte_size
operator|=
name|byte_size
block|; }
comment|//------------------------------------------------------------------
comment|// llvm casting support
comment|//------------------------------------------------------------------
specifier|static
name|bool
name|classof
argument_list|(
argument|const TypeSystem *ts
argument_list|)
block|{
return|return
name|ts
operator|->
name|getKind
argument_list|()
operator|==
name|TypeSystem
operator|::
name|eKindGo
return|;
block|}
comment|//----------------------------------------------------------------------
comment|// CompilerDecl functions
comment|//----------------------------------------------------------------------
name|ConstString
name|DeclGetName
argument_list|(
argument|void *opaque_decl
argument_list|)
name|override
block|{
return|return
name|ConstString
argument_list|()
return|;
block|}
comment|//----------------------------------------------------------------------
comment|// CompilerDeclContext functions
comment|//----------------------------------------------------------------------
name|bool
name|DeclContextIsStructUnionOrClass
argument_list|(
argument|void *opaque_decl_ctx
argument_list|)
name|override
block|{
return|return
name|false
return|;
block|}
name|ConstString
name|DeclContextGetName
argument_list|(
argument|void *opaque_decl_ctx
argument_list|)
name|override
block|{
return|return
name|ConstString
argument_list|()
return|;
block|}
name|ConstString
name|DeclContextGetScopeQualifiedName
argument_list|(
argument|void *opaque_decl_ctx
argument_list|)
name|override
block|{
return|return
name|ConstString
argument_list|()
return|;
block|}
name|bool
name|DeclContextIsClassMethod
argument_list|(
argument|void *opaque_decl_ctx
argument_list|,
argument|lldb::LanguageType *language_ptr
argument_list|,
argument|bool *is_instance_method_ptr
argument_list|,
argument|ConstString *language_object_name_ptr
argument_list|)
name|override
block|{
return|return
name|false
return|;
block|}
comment|//----------------------------------------------------------------------
comment|// Creating Types
comment|//----------------------------------------------------------------------
name|CompilerType
name|CreateArrayType
argument_list|(
argument|const ConstString&name
argument_list|,
argument|const CompilerType&element_type
argument_list|,
argument|uint64_t length
argument_list|)
block|;
name|CompilerType
name|CreateBaseType
argument_list|(
argument|int go_kind
argument_list|,
argument|const ConstString&type_name_const_str
argument_list|,
argument|uint64_t byte_size
argument_list|)
block|;
comment|// For interface, map, chan.
name|CompilerType
name|CreateTypedefType
argument_list|(
argument|int kind
argument_list|,
argument|const ConstString&name
argument_list|,
argument|CompilerType impl
argument_list|)
block|;
name|CompilerType
name|CreateVoidType
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|)
block|;
name|CompilerType
name|CreateFunctionType
argument_list|(
argument|const lldb_private::ConstString&name
argument_list|,
argument|CompilerType *params
argument_list|,
argument|size_t params_count
argument_list|,
argument|bool is_variadic
argument_list|)
block|;
name|CompilerType
name|CreateStructType
argument_list|(
argument|int kind
argument_list|,
argument|const ConstString&name
argument_list|,
argument|uint32_t byte_size
argument_list|)
block|;
name|void
name|CompleteStructType
argument_list|(
specifier|const
name|CompilerType
operator|&
name|type
argument_list|)
block|;
name|void
name|AddFieldToStruct
argument_list|(
argument|const CompilerType&struct_type
argument_list|,
argument|const ConstString&name
argument_list|,
argument|const CompilerType&field_type
argument_list|,
argument|uint32_t byte_offset
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|// Tests
comment|//----------------------------------------------------------------------
specifier|static
name|bool
name|IsGoString
argument_list|(
specifier|const
name|CompilerType
operator|&
name|type
argument_list|)
block|;
specifier|static
name|bool
name|IsGoSlice
argument_list|(
specifier|const
name|CompilerType
operator|&
name|type
argument_list|)
block|;
specifier|static
name|bool
name|IsGoInterface
argument_list|(
specifier|const
name|CompilerType
operator|&
name|type
argument_list|)
block|;
specifier|static
name|bool
name|IsDirectIface
argument_list|(
argument|uint8_t kind
argument_list|)
block|;
specifier|static
name|bool
name|IsPointerKind
argument_list|(
argument|uint8_t kind
argument_list|)
block|;
name|bool
name|IsArrayType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|CompilerType *element_type
argument_list|,
argument|uint64_t *size
argument_list|,
argument|bool *is_incomplete
argument_list|)
name|override
block|;
name|bool
name|IsAggregateType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|bool
name|IsCharType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|bool
name|IsCompleteType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|bool
name|IsDefined
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|bool
name|IsFloatingPointType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|uint32_t&count
argument_list|,
argument|bool&is_complex
argument_list|)
name|override
block|;
name|bool
name|IsFunctionType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|bool *is_variadic_ptr = nullptr
argument_list|)
name|override
block|;
name|size_t
name|GetNumberOfFunctionArguments
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|CompilerType
name|GetFunctionArgumentAtIndex
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|const size_t index
argument_list|)
name|override
block|;
name|bool
name|IsFunctionPointerType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|bool
name|IsBlockPointerType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|CompilerType *function_pointer_type_ptr
argument_list|)
name|override
block|;
name|bool
name|IsIntegerType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|bool&is_signed
argument_list|)
name|override
block|;
name|bool
name|IsPossibleDynamicType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|CompilerType *target_type
argument_list|,
comment|// Can pass nullptr
argument|bool check_cplusplus
argument_list|,
argument|bool check_objc
argument_list|)
name|override
block|;
name|bool
name|IsPointerType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|CompilerType *pointee_type = nullptr
argument_list|)
name|override
block|;
name|bool
name|IsScalarType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|bool
name|IsVoidType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|bool
name|SupportsLanguage
argument_list|(
argument|lldb::LanguageType language
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|// Type Completion
comment|//----------------------------------------------------------------------
name|bool
name|GetCompleteType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|// AST related queries
comment|//----------------------------------------------------------------------
name|uint32_t
name|GetPointerByteSize
argument_list|()
name|override
block|;
comment|//----------------------------------------------------------------------
comment|// Accessors
comment|//----------------------------------------------------------------------
name|ConstString
name|GetTypeName
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|uint32_t
name|GetTypeInfo
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|CompilerType *pointee_or_element_compiler_type = nullptr
argument_list|)
name|override
block|;
name|lldb
operator|::
name|LanguageType
name|GetMinimumLanguage
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|lldb
operator|::
name|TypeClass
name|GetTypeClass
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|// Creating related types
comment|//----------------------------------------------------------------------
name|CompilerType
name|GetArrayElementType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|uint64_t *stride = nullptr
argument_list|)
name|override
block|;
name|CompilerType
name|GetCanonicalType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
comment|// Returns -1 if this isn't a function of if the function doesn't have a
comment|// prototype
comment|// Returns a value>= 0 if there is a prototype.
name|int
name|GetFunctionArgumentCount
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|CompilerType
name|GetFunctionArgumentTypeAtIndex
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|size_t idx
argument_list|)
name|override
block|;
name|CompilerType
name|GetFunctionReturnType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|size_t
name|GetNumMemberFunctions
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|TypeMemberFunctionImpl
name|GetMemberFunctionAtIndex
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|size_t idx
argument_list|)
name|override
block|;
name|CompilerType
name|GetPointeeType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|CompilerType
name|GetPointerType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|// Exploring the type
comment|//----------------------------------------------------------------------
name|uint64_t
name|GetBitSize
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|ExecutionContextScope *exe_scope
argument_list|)
name|override
block|;
name|lldb
operator|::
name|Encoding
name|GetEncoding
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|uint64_t&count
argument_list|)
name|override
block|;
name|lldb
operator|::
name|Format
name|GetFormat
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|uint32_t
name|GetNumChildren
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|bool omit_empty_base_classes
argument_list|)
name|override
block|;
name|lldb
operator|::
name|BasicType
name|GetBasicTypeEnumeration
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|CompilerType
name|GetBuiltinTypeForEncodingAndBitSize
argument_list|(
argument|lldb::Encoding encoding
argument_list|,
argument|size_t bit_size
argument_list|)
name|override
block|;
name|uint32_t
name|GetNumFields
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|CompilerType
name|GetFieldAtIndex
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|size_t idx
argument_list|,
argument|std::string&name
argument_list|,
argument|uint64_t *bit_offset_ptr
argument_list|,
argument|uint32_t *bitfield_bit_size_ptr
argument_list|,
argument|bool *is_bitfield_ptr
argument_list|)
name|override
block|;
name|uint32_t
name|GetNumDirectBaseClasses
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|{
return|return
literal|0
return|;
block|}
name|uint32_t
name|GetNumVirtualBaseClasses
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|{
return|return
literal|0
return|;
block|}
name|CompilerType
name|GetDirectBaseClassAtIndex
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|size_t idx
argument_list|,
argument|uint32_t *bit_offset_ptr
argument_list|)
name|override
block|{
return|return
name|CompilerType
argument_list|()
return|;
block|}
name|CompilerType
name|GetVirtualBaseClassAtIndex
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|size_t idx
argument_list|,
argument|uint32_t *bit_offset_ptr
argument_list|)
name|override
block|{
return|return
name|CompilerType
argument_list|()
return|;
block|}
name|CompilerType
name|GetChildCompilerTypeAtIndex
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|ExecutionContext *exe_ctx
argument_list|,
argument|size_t idx
argument_list|,
argument|bool transparent_pointers
argument_list|,
argument|bool omit_empty_base_classes
argument_list|,
argument|bool ignore_array_bounds
argument_list|,
argument|std::string&child_name
argument_list|,
argument|uint32_t&child_byte_size
argument_list|,
argument|int32_t&child_byte_offset
argument_list|,
argument|uint32_t&child_bitfield_bit_size
argument_list|,
argument|uint32_t&child_bitfield_bit_offset
argument_list|,
argument|bool&child_is_base_class
argument_list|,
argument|bool&child_is_deref_of_parent
argument_list|,
argument|ValueObject *valobj
argument_list|,
argument|uint64_t&language_flags
argument_list|)
name|override
block|;
comment|// Lookup a child given a name. This function will match base class names
comment|// and member member names in "clang_type" only, not descendants.
name|uint32_t
name|GetIndexOfChildWithName
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|const char *name
argument_list|,
argument|bool omit_empty_base_classes
argument_list|)
name|override
block|;
comment|// Lookup a child member given a name. This function will match member names
comment|// only and will descend into "clang_type" children in search for the first
comment|// member in this class, or any base class that matches "name".
comment|// TODO: Return all matches for a given name by returning a
comment|// vector<vector<uint32_t>>
comment|// so we catch all names that match a given child name, not just the first.
name|size_t
name|GetIndexOfChildMemberWithName
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|const char *name
argument_list|,
argument|bool omit_empty_base_classes
argument_list|,
argument|std::vector<uint32_t>&child_indexes
argument_list|)
name|override
block|;
name|size_t
name|GetNumTemplateArguments
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|{
return|return
literal|0
return|;
block|}
name|CompilerType
name|GetTemplateArgument
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|size_t idx
argument_list|,
argument|lldb::TemplateArgumentKind&kind
argument_list|)
name|override
block|{
return|return
name|CompilerType
argument_list|()
return|;
block|}
comment|//----------------------------------------------------------------------
comment|// Dumping types
comment|//----------------------------------------------------------------------
name|void
name|DumpValue
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|ExecutionContext *exe_ctx
argument_list|,
argument|Stream *s
argument_list|,
argument|lldb::Format format
argument_list|,
argument|const DataExtractor&data
argument_list|,
argument|lldb::offset_t data_offset
argument_list|,
argument|size_t data_byte_size
argument_list|,
argument|uint32_t bitfield_bit_size
argument_list|,
argument|uint32_t bitfield_bit_offset
argument_list|,
argument|bool show_types
argument_list|,
argument|bool show_summary
argument_list|,
argument|bool verbose
argument_list|,
argument|uint32_t depth
argument_list|)
name|override
block|;
name|bool
name|DumpTypeValue
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|Stream *s
argument_list|,
argument|lldb::Format format
argument_list|,
argument|const DataExtractor&data
argument_list|,
argument|lldb::offset_t data_offset
argument_list|,
argument|size_t data_byte_size
argument_list|,
argument|uint32_t bitfield_bit_size
argument_list|,
argument|uint32_t bitfield_bit_offset
argument_list|,
argument|ExecutionContextScope *exe_scope
argument_list|)
name|override
block|;
name|void
name|DumpTypeDescription
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
comment|// Dump to stdout
name|void
name|DumpTypeDescription
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|Stream *s
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|// TODO: These methods appear unused. Should they be removed?
comment|//----------------------------------------------------------------------
name|bool
name|IsRuntimeGeneratedType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|void
name|DumpSummary
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|ExecutionContext *exe_ctx
argument_list|,
argument|Stream *s
argument_list|,
argument|const DataExtractor&data
argument_list|,
argument|lldb::offset_t data_offset
argument_list|,
argument|size_t data_byte_size
argument_list|)
name|override
block|;
comment|// Converts "s" to a floating point value and place resulting floating
comment|// point bytes in the "dst" buffer.
name|size_t
name|ConvertStringToFloatValue
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|const char *s
argument_list|,
argument|uint8_t *dst
argument_list|,
argument|size_t dst_size
argument_list|)
name|override
block|;
comment|//----------------------------------------------------------------------
comment|// TODO: Determine if these methods should move to ClangASTContext.
comment|//----------------------------------------------------------------------
name|bool
name|IsPointerOrReferenceType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|CompilerType *pointee_type = nullptr
argument_list|)
name|override
block|;
name|unsigned
name|GetTypeQualifiers
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|bool
name|IsCStringType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|uint32_t&length
argument_list|)
name|override
block|;
name|size_t
name|GetTypeBitAlign
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|CompilerType
name|GetBasicTypeFromAST
argument_list|(
argument|lldb::BasicType basic_type
argument_list|)
name|override
block|;
name|bool
name|IsBeingDefined
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|bool
name|IsConst
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|uint32_t
name|IsHomogeneousAggregate
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|CompilerType *base_type_ptr
argument_list|)
name|override
block|;
name|bool
name|IsPolymorphicClass
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|bool
name|IsTypedefType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
comment|// If the current object represents a typedef type, get the underlying type
name|CompilerType
name|GetTypedefedType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|bool
name|IsVectorType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|CompilerType *element_type
argument_list|,
argument|uint64_t *size
argument_list|)
name|override
block|;
name|CompilerType
name|GetFullyUnqualifiedType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|CompilerType
name|GetNonReferenceType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
name|override
block|;
name|bool
name|IsReferenceType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|CompilerType *pointee_type = nullptr
argument_list|,
argument|bool *is_rvalue = nullptr
argument_list|)
name|override
block|;
name|private
operator|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|ConstString
operator|,
name|std
operator|::
name|unique_ptr
operator|<
name|GoType
operator|>>
name|TypeMap
expr_stmt|;
name|int
name|m_pointer_byte_size
decl_stmt|;
name|int
name|m_int_byte_size
decl_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|TypeMap
operator|>
name|m_types
expr_stmt|;
name|std
operator|::
name|unique_ptr
operator|<
name|DWARFASTParser
operator|>
name|m_dwarf_ast_parser_ap
expr_stmt|;
name|GoASTContext
argument_list|(
specifier|const
name|GoASTContext
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
specifier|const
name|GoASTContext
modifier|&
name|operator
init|=
operator|(
specifier|const
name|GoASTContext
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_decl_stmt
name|class
name|GoASTContextForExpr
range|:
name|public
name|GoASTContext
block|{
name|public
operator|:
name|GoASTContextForExpr
argument_list|(
argument|lldb::TargetSP target
argument_list|)
operator|:
name|m_target_wp
argument_list|(
argument|target
argument_list|)
block|{}
name|UserExpression
operator|*
name|GetUserExpression
argument_list|(
argument|llvm::StringRef expr
argument_list|,
argument|llvm::StringRef prefix
argument_list|,
argument|lldb::LanguageType language
argument_list|,
argument|Expression::ResultType desired_type
argument_list|,
argument|const EvaluateExpressionOptions&options
argument_list|)
name|override
block|;
name|private
operator|:
name|lldb
operator|::
name|TargetWP
name|m_target_wp
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_GoASTContext_h_
end_comment

end_unit

