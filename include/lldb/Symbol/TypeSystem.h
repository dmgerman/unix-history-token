begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- TypeSystem.h ------------------------------------------*- C++ -*-===//
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
name|liblldb_TypeSystem_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_TypeSystem_h_
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
file|<functional>
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

begin_comment
comment|// Other libraries and framework includes
end_comment

begin_include
include|#
directive|include
file|"llvm/ADT/APSInt.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Casting.h"
end_include

begin_comment
comment|// Project includes
end_comment

begin_include
include|#
directive|include
file|"lldb/lldb-private.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/PluginInterface.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Expression/Expression.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Host/Mutex.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/CompilerDecl.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Symbol/CompilerDeclContext.h"
end_include

begin_decl_stmt
name|class
name|DWARFDIE
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|class
name|DWARFASTParser
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// Interface for representing the Type Systems in different languages.
comment|//----------------------------------------------------------------------
name|class
name|TypeSystem
range|:
name|public
name|PluginInterface
block|{
name|public
operator|:
comment|//----------------------------------------------------------------------
comment|// Intrusive type system that allows us to use llvm casting.
comment|//
comment|// To add a new type system:
comment|//
comment|// 1 - Add a new enumeration for llvm casting below for your TypeSystem
comment|//     subclass, here we will use eKindFoo
comment|//
comment|// 2 - Your TypeSystem subclass will inherit from TypeSystem and needs
comment|//     to implement a static classof() function that returns your
comment|//     enumeration:
comment|//
comment|//    class Foo : public lldb_private::TypeSystem
comment|//    {
comment|//        static bool classof(const TypeSystem *ts)
comment|//        {
comment|//            return ts->getKind() == TypeSystem::eKindFoo;
comment|//        }
comment|//    };
comment|//
comment|// 3 - Contruct your TypeSystem subclass with the enumeration from below
comment|//
comment|//    Foo() :
comment|//        TypeSystem(TypeSystem::eKindFoo),
comment|//        ...
comment|//    {
comment|//    }
comment|//
comment|// Then you can use the llvm casting on any "TypeSystem *" to get an
comment|// instance of your subclass.
comment|//----------------------------------------------------------------------
expr|enum
name|LLVMCastKind
block|{
name|eKindClang
block|,
name|eKindSwift
block|,
name|eKindGo
block|,
name|kNumKinds
block|}
block|;
comment|//----------------------------------------------------------------------
comment|// Constructors and Destructors
comment|//----------------------------------------------------------------------
name|TypeSystem
argument_list|(
argument|LLVMCastKind kind
argument_list|)
block|;
operator|~
name|TypeSystem
argument_list|()
name|override
block|;
name|LLVMCastKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|m_kind
return|;
block|}
specifier|static
name|lldb
operator|::
name|TypeSystemSP
name|CreateInstance
argument_list|(
argument|lldb::LanguageType language
argument_list|,
argument|Module *module
argument_list|)
block|;
specifier|static
name|lldb
operator|::
name|TypeSystemSP
name|CreateInstance
argument_list|(
argument|lldb::LanguageType language
argument_list|,
argument|Target *target
argument_list|)
block|;
name|virtual
name|DWARFASTParser
operator|*
name|GetDWARFParser
argument_list|()
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
name|SymbolFile
operator|*
name|GetSymbolFile
argument_list|()
specifier|const
block|{
return|return
name|m_sym_file
return|;
block|}
comment|// Returns true if the symbol file changed during the set accessor.
name|virtual
name|void
name|SetSymbolFile
argument_list|(
argument|SymbolFile *sym_file
argument_list|)
block|{
name|m_sym_file
operator|=
name|sym_file
block|;     }
comment|//----------------------------------------------------------------------
comment|// CompilerDecl functions
comment|//----------------------------------------------------------------------
name|virtual
name|ConstString
name|DeclGetName
argument_list|(
name|void
operator|*
name|opaque_decl
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|ConstString
name|DeclGetMangledName
argument_list|(
name|void
operator|*
name|opaque_decl
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|VariableSP
name|DeclGetVariable
argument_list|(
name|void
operator|*
name|opaque_decl
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|DeclLinkToObject
argument_list|(
name|void
operator|*
name|opaque_decl
argument_list|,
name|std
operator|::
name|shared_ptr
operator|<
name|void
operator|>
name|object
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|CompilerDeclContext
name|DeclGetDeclContext
argument_list|(
name|void
operator|*
name|opaque_decl
argument_list|)
block|;
name|virtual
name|CompilerType
name|DeclGetFunctionReturnType
argument_list|(
name|void
operator|*
name|opaque_decl
argument_list|)
block|;
name|virtual
name|size_t
name|DeclGetFunctionNumArguments
argument_list|(
name|void
operator|*
name|opaque_decl
argument_list|)
block|;
name|virtual
name|CompilerType
name|DeclGetFunctionArgumentType
argument_list|(
argument|void *opaque_decl
argument_list|,
argument|size_t arg_idx
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|// CompilerDeclContext functions
comment|//----------------------------------------------------------------------
name|virtual
name|std
operator|::
name|vector
operator|<
name|CompilerDecl
operator|>
name|DeclContextFindDeclByName
argument_list|(
argument|void *opaque_decl_ctx
argument_list|,
argument|ConstString name
argument_list|)
block|;
name|virtual
name|bool
name|DeclContextIsStructUnionOrClass
argument_list|(
name|void
operator|*
name|opaque_decl_ctx
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|ConstString
name|DeclContextGetName
argument_list|(
name|void
operator|*
name|opaque_decl_ctx
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|ConstString
name|DeclContextGetScopeQualifiedName
argument_list|(
name|void
operator|*
name|opaque_decl_ctx
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|DeclContextIsClassMethod
argument_list|(
name|void
operator|*
name|opaque_decl_ctx
argument_list|,
name|lldb
operator|::
name|LanguageType
operator|*
name|language_ptr
argument_list|,
name|bool
operator|*
name|is_instance_method_ptr
argument_list|,
name|ConstString
operator|*
name|language_object_name_ptr
argument_list|)
operator|=
literal|0
block|;
comment|//----------------------------------------------------------------------
comment|// Tests
comment|//----------------------------------------------------------------------
name|virtual
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
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsAggregateType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsAnonymousType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
block|;
name|virtual
name|bool
name|IsCharType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsCompleteType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsDefined
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsFloatingPointType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|uint32_t&count
argument_list|,
argument|bool&is_complex
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsFunctionType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|bool *is_variadic_ptr
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|size_t
name|GetNumberOfFunctionArguments
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|CompilerType
name|GetFunctionArgumentAtIndex
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|const size_t index
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsFunctionPointerType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsIntegerType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|bool&is_signed
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsPossibleDynamicType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|CompilerType *target_type
argument_list|,
comment|// Can pass NULL
argument|bool check_cplusplus
argument_list|,
argument|bool check_objc
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsPointerType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|CompilerType *pointee_type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsScalarType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsVoidType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
comment|// TypeSystems can support more than one language
name|virtual
name|bool
name|SupportsLanguage
argument_list|(
argument|lldb::LanguageType language
argument_list|)
operator|=
literal|0
block|;
comment|//----------------------------------------------------------------------
comment|// Type Completion
comment|//----------------------------------------------------------------------
name|virtual
name|bool
name|GetCompleteType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
comment|//----------------------------------------------------------------------
comment|// AST related queries
comment|//----------------------------------------------------------------------
name|virtual
name|uint32_t
name|GetPointerByteSize
argument_list|()
operator|=
literal|0
block|;
comment|//----------------------------------------------------------------------
comment|// Accessors
comment|//----------------------------------------------------------------------
name|virtual
name|ConstString
name|GetTypeName
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|uint32_t
name|GetTypeInfo
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|CompilerType *pointee_or_element_compiler_type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|lldb
operator|::
name|LanguageType
name|GetMinimumLanguage
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|lldb
operator|::
name|TypeClass
name|GetTypeClass
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
comment|//----------------------------------------------------------------------
comment|// Creating related types
comment|//----------------------------------------------------------------------
name|virtual
name|CompilerType
name|GetArrayElementType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|uint64_t *stride
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|CompilerType
name|GetCanonicalType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
comment|// Returns -1 if this isn't a function of if the function doesn't have a prototype
comment|// Returns a value>= 0 if there is a prototype.
name|virtual
name|int
name|GetFunctionArgumentCount
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|CompilerType
name|GetFunctionArgumentTypeAtIndex
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|size_t idx
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|CompilerType
name|GetFunctionReturnType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|size_t
name|GetNumMemberFunctions
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|TypeMemberFunctionImpl
name|GetMemberFunctionAtIndex
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|size_t idx
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|CompilerType
name|GetPointeeType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|CompilerType
name|GetPointerType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|CompilerType
name|GetLValueReferenceType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
block|;
name|virtual
name|CompilerType
name|GetRValueReferenceType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
block|;
name|virtual
name|CompilerType
name|AddConstModifier
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
block|;
name|virtual
name|CompilerType
name|AddVolatileModifier
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
block|;
name|virtual
name|CompilerType
name|AddRestrictModifier
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
block|;
name|virtual
name|CompilerType
name|CreateTypedef
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|const char *name
argument_list|,
argument|const CompilerDeclContext&decl_ctx
argument_list|)
block|;
comment|//----------------------------------------------------------------------
comment|// Exploring the type
comment|//----------------------------------------------------------------------
name|virtual
name|uint64_t
name|GetBitSize
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|ExecutionContextScope *exe_scope
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|lldb
operator|::
name|Encoding
name|GetEncoding
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|uint64_t&count
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|lldb
operator|::
name|Format
name|GetFormat
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|uint32_t
name|GetNumChildren
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|bool omit_empty_base_classes
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|CompilerType
name|GetBuiltinTypeByName
argument_list|(
specifier|const
name|ConstString
operator|&
name|name
argument_list|)
block|;
name|virtual
name|lldb
operator|::
name|BasicType
name|GetBasicTypeEnumeration
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|void
name|ForEachEnumerator
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|std::function<bool (const CompilerType&integer_type, const ConstString&name, const llvm::APSInt&value)> const&callback
argument_list|)
block|{     }
name|virtual
name|uint32_t
name|GetNumFields
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|CompilerType
name|GetFieldAtIndex
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|size_t idx
argument_list|,
argument|std::string& name
argument_list|,
argument|uint64_t *bit_offset_ptr
argument_list|,
argument|uint32_t *bitfield_bit_size_ptr
argument_list|,
argument|bool *is_bitfield_ptr
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|uint32_t
name|GetNumDirectBaseClasses
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|uint32_t
name|GetNumVirtualBaseClasses
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|CompilerType
name|GetDirectBaseClassAtIndex
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|size_t idx
argument_list|,
argument|uint32_t *bit_offset_ptr
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|CompilerType
name|GetVirtualBaseClassAtIndex
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|size_t idx
argument_list|,
argument|uint32_t *bit_offset_ptr
argument_list|)
operator|=
literal|0
block|;
name|virtual
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
argument|std::string& child_name
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
operator|=
literal|0
block|;
comment|// Lookup a child given a name. This function will match base class names
comment|// and member member names in "clang_type" only, not descendants.
name|virtual
name|uint32_t
name|GetIndexOfChildWithName
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|const char *name
argument_list|,
argument|bool omit_empty_base_classes
argument_list|)
operator|=
literal|0
block|;
comment|// Lookup a child member given a name. This function will match member names
comment|// only and will descend into "clang_type" children in search for the first
comment|// member in this class, or any base class that matches "name".
comment|// TODO: Return all matches for a given name by returning a vector<vector<uint32_t>>
comment|// so we catch all names that match a given child name, not just the first.
name|virtual
name|size_t
name|GetIndexOfChildMemberWithName
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|const char *name
argument_list|,
argument|bool omit_empty_base_classes
argument_list|,
argument|std::vector<uint32_t>& child_indexes
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|size_t
name|GetNumTemplateArguments
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|CompilerType
name|GetTemplateArgument
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|size_t idx
argument_list|,
argument|lldb::TemplateArgumentKind&kind
argument_list|)
operator|=
literal|0
block|;
comment|//----------------------------------------------------------------------
comment|// Dumping types
comment|//----------------------------------------------------------------------
name|virtual
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
operator|=
literal|0
block|;
name|virtual
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
operator|=
literal|0
block|;
name|virtual
name|void
name|DumpTypeDescription
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
comment|// Dump to stdout
name|virtual
name|void
name|DumpTypeDescription
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|Stream *s
argument_list|)
operator|=
literal|0
block|;
comment|//----------------------------------------------------------------------
comment|// TODO: These methods appear unused. Should they be removed?
comment|//----------------------------------------------------------------------
name|virtual
name|bool
name|IsRuntimeGeneratedType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
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
operator|=
literal|0
block|;
comment|// Converts "s" to a floating point value and place resulting floating
comment|// point bytes in the "dst" buffer.
name|virtual
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
operator|=
literal|0
block|;
comment|//----------------------------------------------------------------------
comment|// TODO: Determine if these methods should move to ClangASTContext.
comment|//----------------------------------------------------------------------
name|virtual
name|bool
name|IsPointerOrReferenceType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|CompilerType *pointee_type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|unsigned
name|GetTypeQualifiers
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsCStringType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|uint32_t&length
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|size_t
name|GetTypeBitAlign
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|CompilerType
name|GetBasicTypeFromAST
argument_list|(
argument|lldb::BasicType basic_type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|CompilerType
name|GetBuiltinTypeForEncodingAndBitSize
argument_list|(
argument|lldb::Encoding encoding
argument_list|,
argument|size_t bit_size
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsBeingDefined
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsConst
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|uint32_t
name|IsHomogeneousAggregate
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|CompilerType* base_type_ptr
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsPolymorphicClass
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsTypedefType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
comment|// If the current object represents a typedef type, get the underlying type
name|virtual
name|CompilerType
name|GetTypedefedType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsVectorType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|CompilerType *element_type
argument_list|,
argument|uint64_t *size
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|CompilerType
name|GetFullyUnqualifiedType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|CompilerType
name|GetNonReferenceType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|IsReferenceType
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|,
argument|CompilerType *pointee_type
argument_list|,
argument|bool* is_rvalue
argument_list|)
operator|=
literal|0
block|;
name|virtual
name|bool
name|ShouldTreatScalarValueAsAddress
argument_list|(
argument|lldb::opaque_compiler_type_t type
argument_list|)
block|{
return|return
name|IsPointerOrReferenceType
argument_list|(
name|type
argument_list|,
name|nullptr
argument_list|)
return|;
block|}
name|virtual
name|UserExpression
operator|*
name|GetUserExpression
argument_list|(
argument|const char *expr
argument_list|,
argument|const char *expr_prefix
argument_list|,
argument|lldb::LanguageType language
argument_list|,
argument|Expression::ResultType desired_type
argument_list|,
argument|const EvaluateExpressionOptions&options
argument_list|)
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
name|FunctionCaller
operator|*
name|GetFunctionCaller
argument_list|(
argument|const CompilerType&return_type
argument_list|,
argument|const Address& function_address
argument_list|,
argument|const ValueList&arg_value_list
argument_list|,
argument|const char *name
argument_list|)
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
name|UtilityFunction
operator|*
name|GetUtilityFunction
argument_list|(
argument|const char *text
argument_list|,
argument|const char *name
argument_list|)
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
name|PersistentExpressionState
operator|*
name|GetPersistentExpressionState
argument_list|()
block|{
return|return
name|nullptr
return|;
block|}
name|virtual
name|CompilerType
name|GetTypeForFormatters
argument_list|(
name|void
operator|*
name|type
argument_list|)
block|;
name|virtual
name|LazyBool
name|ShouldPrintAsOneLiner
argument_list|(
name|void
operator|*
name|type
argument_list|,
name|ValueObject
operator|*
name|valobj
argument_list|)
block|;
comment|// Type systems can have types that are placeholder types, which are meant to indicate
comment|// the presence of a type, but offer no actual information about said types, and leave
comment|// the burden of actually figuring type information out to dynamic type resolution. For instance
comment|// a language with a generics system, can use placeholder types to indicate "type argument goes here",
comment|// without promising uniqueness of the placeholder, nor attaching any actually idenfiable information
comment|// to said placeholder. This API allows type systems to tell LLDB when such a type has been encountered
comment|// In response, the debugger can react by not using this type as a cache entry in any type-specific way
comment|// For instance, LLDB will currently not cache any formatters that are discovered on such a type as
comment|// attributable to the meaningless type itself, instead preferring to use the dynamic type
name|virtual
name|bool
name|IsMeaninglessWithoutDynamicResolution
argument_list|(
name|void
operator|*
name|type
argument_list|)
block|;
name|protected
operator|:
specifier|const
name|LLVMCastKind
name|m_kind
block|;
comment|// Support for llvm casting
name|SymbolFile
operator|*
name|m_sym_file
block|;  }
decl_stmt|;
name|class
name|TypeSystemMap
block|{
name|public
label|:
name|TypeSystemMap
argument_list|()
expr_stmt|;
operator|~
name|TypeSystemMap
argument_list|()
expr_stmt|;
name|void
name|Clear
parameter_list|()
function_decl|;
comment|// Iterate through all of the type systems that are created. Return true
comment|// from callback to keep iterating, false to stop iterating.
name|void
name|ForEach
argument_list|(
name|std
operator|::
name|function
operator|<
name|bool
argument_list|(
name|TypeSystem
operator|*
argument_list|)
operator|>
specifier|const
operator|&
name|callback
argument_list|)
decl_stmt|;
name|TypeSystem
modifier|*
name|GetTypeSystemForLanguage
argument_list|(
name|lldb
operator|::
name|LanguageType
name|language
argument_list|,
name|Module
operator|*
name|module
argument_list|,
name|bool
name|can_create
argument_list|)
decl_stmt|;
name|TypeSystem
modifier|*
name|GetTypeSystemForLanguage
argument_list|(
name|lldb
operator|::
name|LanguageType
name|language
argument_list|,
name|Target
operator|*
name|target
argument_list|,
name|bool
name|can_create
argument_list|)
decl_stmt|;
name|protected
label|:
typedef|typedef
name|std
operator|::
name|map
operator|<
name|lldb
operator|::
name|LanguageType
operator|,
name|lldb
operator|::
name|TypeSystemSP
operator|>
name|collection
expr_stmt|;
name|mutable
name|Mutex
name|m_mutex
decl_stmt|;
comment|///< A mutex to keep this object happy in multi-threaded environments.
name|collection
name|m_map
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// liblldb_TypeSystem_h_
end_comment

end_unit

