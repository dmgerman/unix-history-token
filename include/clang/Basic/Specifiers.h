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
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_BASIC_SPECIFIERS_H
end_comment

end_unit

