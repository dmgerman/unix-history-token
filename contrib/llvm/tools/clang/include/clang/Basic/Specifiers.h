begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Specifiers.h - Declaration and Type Specifiers ---------*- C++ -*-===//
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
comment|///
end_comment

begin_comment
comment|/// \file
end_comment

begin_comment
comment|/// \brief Defines various enumerations that describe declaration and
end_comment

begin_comment
comment|/// type specifiers.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_BASIC_SPECIFIERS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_SPECIFIERS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Specifies the width of a type, e.g., short, long, or long long.
enum|enum
name|TypeSpecifierWidth
block|{
name|TSW_unspecified
block|,
name|TSW_short
block|,
name|TSW_long
block|,
name|TSW_longlong
block|}
enum|;
comment|/// \brief Specifies the signedness of a type, e.g., signed or unsigned.
enum|enum
name|TypeSpecifierSign
block|{
name|TSS_unspecified
block|,
name|TSS_signed
block|,
name|TSS_unsigned
block|}
enum|;
comment|/// \brief Specifies the kind of type.
enum|enum
name|TypeSpecifierType
block|{
name|TST_unspecified
block|,
name|TST_void
block|,
name|TST_char
block|,
name|TST_wchar
block|,
comment|// C++ wchar_t
name|TST_char16
block|,
comment|// C++11 char16_t
name|TST_char32
block|,
comment|// C++11 char32_t
name|TST_int
block|,
name|TST_int128
block|,
name|TST_half
block|,
comment|// OpenCL half, ARM NEON __fp16
name|TST_float
block|,
name|TST_double
block|,
name|TST_bool
block|,
comment|// _Bool
name|TST_decimal32
block|,
comment|// _Decimal32
name|TST_decimal64
block|,
comment|// _Decimal64
name|TST_decimal128
block|,
comment|// _Decimal128
name|TST_enum
block|,
name|TST_union
block|,
name|TST_struct
block|,
name|TST_class
block|,
comment|// C++ class type
name|TST_interface
block|,
comment|// C++ (Microsoft-specific) __interface type
name|TST_typename
block|,
comment|// Typedef, C++ class-name or enum name, etc.
name|TST_typeofType
block|,
name|TST_typeofExpr
block|,
name|TST_decltype
block|,
comment|// C++11 decltype
name|TST_underlyingType
block|,
comment|// __underlying_type for C++11
name|TST_auto
block|,
comment|// C++11 auto
name|TST_decltype_auto
block|,
comment|// C++1y decltype(auto)
name|TST_unknown_anytype
block|,
comment|// __unknown_anytype extension
name|TST_atomic
block|,
comment|// C11 _Atomic
name|TST_image1d_t
block|,
comment|// OpenCL image1d_t
name|TST_image1d_array_t
block|,
comment|// OpenCL image1d_array_t
name|TST_image1d_buffer_t
block|,
comment|// OpenCL image1d_buffer_t
name|TST_image2d_t
block|,
comment|// OpenCL image2d_t
name|TST_image2d_array_t
block|,
comment|// OpenCL image2d_array_t
name|TST_image3d_t
block|,
comment|// OpenCL image3d_t
name|TST_sampler_t
block|,
comment|// OpenCL sampler_t
name|TST_event_t
block|,
comment|// OpenCL event_t
name|TST_error
comment|// erroneous type
block|}
enum|;
comment|/// \brief Structure that packs information about the type specifiers that
comment|/// were written in a particular type specifier sequence.
struct|struct
name|WrittenBuiltinSpecs
block|{
comment|/*DeclSpec::TST*/
name|unsigned
name|Type
range|:
literal|6
decl_stmt|;
comment|/*DeclSpec::TSS*/
name|unsigned
name|Sign
range|:
literal|2
decl_stmt|;
comment|/*DeclSpec::TSW*/
name|unsigned
name|Width
range|:
literal|2
decl_stmt|;
name|bool
name|ModeAttr
range|:
literal|1
decl_stmt|;
block|}
struct|;
comment|/// \brief A C++ access specifier (public, private, protected), plus the
comment|/// special value "none" which means different things in different contexts.
enum|enum
name|AccessSpecifier
block|{
name|AS_public
block|,
name|AS_protected
block|,
name|AS_private
block|,
name|AS_none
block|}
enum|;
comment|/// \brief The categorization of expression values, currently following the
comment|/// C++11 scheme.
enum|enum
name|ExprValueKind
block|{
comment|/// \brief An r-value expression (a pr-value in the C++11 taxonomy)
comment|/// produces a temporary value.
name|VK_RValue
block|,
comment|/// \brief An l-value expression is a reference to an object with
comment|/// independent storage.
name|VK_LValue
block|,
comment|/// \brief An x-value expression is a reference to an object with
comment|/// independent storage but which can be "moved", i.e.
comment|/// efficiently cannibalized for its resources.
name|VK_XValue
block|}
enum|;
comment|/// \brief A further classification of the kind of object referenced by an
comment|/// l-value or x-value.
enum|enum
name|ExprObjectKind
block|{
comment|/// An ordinary object is located at an address in memory.
name|OK_Ordinary
block|,
comment|/// A bitfield object is a bitfield on a C or C++ record.
name|OK_BitField
block|,
comment|/// A vector component is an element or range of elements on a vector.
name|OK_VectorComponent
block|,
comment|/// An Objective-C property is a logical field of an Objective-C
comment|/// object which is read and written via Objective-C method calls.
name|OK_ObjCProperty
block|,
comment|/// An Objective-C array/dictionary subscripting which reads an
comment|/// object or writes at the subscripted array/dictionary element via
comment|/// Objective-C method calls.
name|OK_ObjCSubscript
block|}
enum|;
comment|/// \brief Describes the kind of template specialization that a
comment|/// particular template specialization declaration represents.
enum|enum
name|TemplateSpecializationKind
block|{
comment|/// This template specialization was formed from a template-id but
comment|/// has not yet been declared, defined, or instantiated.
name|TSK_Undeclared
init|=
literal|0
block|,
comment|/// This template specialization was implicitly instantiated from a
comment|/// template. (C++ [temp.inst]).
name|TSK_ImplicitInstantiation
block|,
comment|/// This template specialization was declared or defined by an
comment|/// explicit specialization (C++ [temp.expl.spec]) or partial
comment|/// specialization (C++ [temp.class.spec]).
name|TSK_ExplicitSpecialization
block|,
comment|/// This template specialization was instantiated from a template
comment|/// due to an explicit instantiation declaration request
comment|/// (C++11 [temp.explicit]).
name|TSK_ExplicitInstantiationDeclaration
block|,
comment|/// This template specialization was instantiated from a template
comment|/// due to an explicit instantiation definition request
comment|/// (C++ [temp.explicit]).
name|TSK_ExplicitInstantiationDefinition
block|}
enum|;
comment|/// \brief Determine whether this template specialization kind refers
comment|/// to an instantiation of an entity (as opposed to a non-template or
comment|/// an explicit specialization).
specifier|inline
name|bool
name|isTemplateInstantiation
parameter_list|(
name|TemplateSpecializationKind
name|Kind
parameter_list|)
block|{
return|return
name|Kind
operator|!=
name|TSK_Undeclared
operator|&&
name|Kind
operator|!=
name|TSK_ExplicitSpecialization
return|;
block|}
comment|/// \brief Thread storage-class-specifier.
enum|enum
name|ThreadStorageClassSpecifier
block|{
name|TSCS_unspecified
block|,
comment|/// GNU __thread.
name|TSCS___thread
block|,
comment|/// C++11 thread_local. Implies 'static' at block scope, but not at
comment|/// class scope.
name|TSCS_thread_local
block|,
comment|/// C11 _Thread_local. Must be combined with either 'static' or 'extern'
comment|/// if used at block scope.
name|TSCS__Thread_local
block|}
enum|;
comment|/// \brief Storage classes.
enum|enum
name|StorageClass
block|{
comment|// These are legal on both functions and variables.
name|SC_None
block|,
name|SC_Extern
block|,
name|SC_Static
block|,
name|SC_PrivateExtern
block|,
comment|// These are only legal on variables.
name|SC_OpenCLWorkGroupLocal
block|,
name|SC_Auto
block|,
name|SC_Register
block|}
enum|;
comment|/// \brief Checks whether the given storage class is legal for functions.
specifier|inline
name|bool
name|isLegalForFunction
parameter_list|(
name|StorageClass
name|SC
parameter_list|)
block|{
return|return
name|SC
operator|<=
name|SC_PrivateExtern
return|;
block|}
comment|/// \brief Checks whether the given storage class is legal for variables.
specifier|inline
name|bool
name|isLegalForVariable
parameter_list|(
name|StorageClass
name|SC
parameter_list|)
block|{
return|return
name|true
return|;
block|}
comment|/// \brief In-class initialization styles for non-static data members.
enum|enum
name|InClassInitStyle
block|{
name|ICIS_NoInit
block|,
comment|///< No in-class initializer.
name|ICIS_CopyInit
block|,
comment|///< Copy initialization.
name|ICIS_ListInit
comment|///< Direct list-initialization.
block|}
enum|;
comment|/// \brief CallingConv - Specifies the calling convention that a function uses.
enum|enum
name|CallingConv
block|{
name|CC_C
block|,
comment|// __attribute__((cdecl))
name|CC_X86StdCall
block|,
comment|// __attribute__((stdcall))
name|CC_X86FastCall
block|,
comment|// __attribute__((fastcall))
name|CC_X86ThisCall
block|,
comment|// __attribute__((thiscall))
name|CC_X86Pascal
block|,
comment|// __attribute__((pascal))
name|CC_X86_64Win64
block|,
comment|// __attribute__((ms_abi))
name|CC_X86_64SysV
block|,
comment|// __attribute__((sysv_abi))
name|CC_AAPCS
block|,
comment|// __attribute__((pcs("aapcs")))
name|CC_AAPCS_VFP
block|,
comment|// __attribute__((pcs("aapcs-vfp")))
name|CC_PnaclCall
block|,
comment|// __attribute__((pnaclcall))
name|CC_IntelOclBicc
comment|// __attribute__((intel_ocl_bicc))
block|}
enum|;
comment|/// \brief Checks whether the given calling convention is callee-cleanup.
specifier|inline
name|bool
name|isCalleeCleanup
parameter_list|(
name|CallingConv
name|CC
parameter_list|)
block|{
switch|switch
condition|(
name|CC
condition|)
block|{
case|case
name|CC_X86StdCall
case|:
case|case
name|CC_X86FastCall
case|:
case|case
name|CC_X86ThisCall
case|:
case|case
name|CC_X86Pascal
case|:
return|return
name|true
return|;
default|default:
return|return
name|false
return|;
block|}
block|}
comment|/// \brief The storage duration for an object (per C++ [basic.stc]).
enum|enum
name|StorageDuration
block|{
name|SD_FullExpression
block|,
comment|///< Full-expression storage duration (for temporaries).
name|SD_Automatic
block|,
comment|///< Automatic storage duration (most local variables).
name|SD_Thread
block|,
comment|///< Thread storage duration.
name|SD_Static
block|,
comment|///< Static storage duration.
name|SD_Dynamic
comment|///< Dynamic storage duration.
block|}
enum|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_BASIC_SPECIFIERS_H
end_comment

end_unit

