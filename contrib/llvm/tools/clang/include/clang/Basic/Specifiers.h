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
comment|//
end_comment

begin_comment
comment|// This file defines various enumerations that describe declaration and
end_comment

begin_comment
comment|// type specifiers.
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
comment|// C++0x char16_t
name|TST_char32
block|,
comment|// C++0x char32_t
name|TST_int
block|,
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
name|TST_typename
block|,
comment|// Typedef, C++ class-name or enum name, etc.
name|TST_typeofType
block|,
name|TST_typeofExpr
block|,
name|TST_decltype
block|,
comment|// C++0x decltype
name|TST_auto
block|,
comment|// C++0x auto
name|TST_unknown_anytype
block|,
comment|// __unknown_anytype extension
name|TST_error
comment|// erroneous type
block|}
enum|;
comment|/// WrittenBuiltinSpecs - Structure that packs information about the
comment|/// type specifiers that were written in a particular type specifier
comment|/// sequence.
struct|struct
name|WrittenBuiltinSpecs
block|{
comment|/*DeclSpec::TST*/
name|unsigned
name|Type
range|:
literal|5
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
comment|/// AccessSpecifier - A C++ access specifier (public, private,
comment|/// protected), plus the special value "none" which means
comment|/// different things in different contexts.
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
comment|/// ExprValueKind - The categorization of expression values,
comment|/// currently following the C++0x scheme.
enum|enum
name|ExprValueKind
block|{
comment|/// An r-value expression (a gr-value in the C++0x taxonomy)
comment|/// produces a temporary value.
name|VK_RValue
block|,
comment|/// An l-value expression is a reference to an object with
comment|/// independent storage.
name|VK_LValue
block|,
comment|/// An x-value expression is a reference to an object with
comment|/// independent storage but which can be "moved", i.e.
comment|/// efficiently cannibalized for its resources.
name|VK_XValue
block|}
enum|;
comment|/// A further classification of the kind of object referenced by an
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
comment|/// An Objective C property is a logical field of an Objective-C
comment|/// object which is read and written via Objective C method calls.
name|OK_ObjCProperty
block|}
enum|;
comment|// \brief Describes the kind of template specialization that a
comment|// particular template specialization declaration represents.
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
comment|/// (C++0x [temp.explicit]).
name|TSK_ExplicitInstantiationDeclaration
block|,
comment|/// This template specialization was instantiated from a template
comment|/// due to an explicit instantiation definition request
comment|/// (C++ [temp.explicit]).
name|TSK_ExplicitInstantiationDefinition
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
name|SC_Auto
block|,
name|SC_Register
block|}
enum|;
comment|/// Checks whether the given storage class is legal for functions.
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
comment|/// Checks whether the given storage class is legal for variables.
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

