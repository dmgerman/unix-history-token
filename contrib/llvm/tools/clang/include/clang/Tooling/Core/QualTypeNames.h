begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- QualTypeNames.h - Generate Complete QualType Names ----*- C++ -*-===//
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
comment|// ===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// \file
end_comment

begin_comment
comment|// Functionality to generate the fully-qualified names of QualTypes,
end_comment

begin_comment
comment|// including recursively expanding any subtypes and template
end_comment

begin_comment
comment|// parameters.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// More precisely: Generates a name that can be used to name the same
end_comment

begin_comment
comment|// type if used at the end of the current translation unit--with
end_comment

begin_comment
comment|// certain limitations. See below.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// This code desugars names only very minimally, so in this code:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// namespace A {
end_comment

begin_comment
comment|//   struct X {};
end_comment

begin_comment
comment|// }
end_comment

begin_comment
comment|// using A::X;
end_comment

begin_comment
comment|// namespace B {
end_comment

begin_comment
comment|//   using std::tuple;
end_comment

begin_comment
comment|//   typedef tuple<X> TX;
end_comment

begin_comment
comment|//   TX t;
end_comment

begin_comment
comment|// }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// B::t's type is reported as "B::TX", rather than std::tuple<A::X>.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Also, this code replaces types found via using declarations with
end_comment

begin_comment
comment|// their more qualified name, so for the code:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// using std::tuple;
end_comment

begin_comment
comment|// tuple<int> TInt;
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// TInt's type will be named, "std::tuple<int>".
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Limitations:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// Some types have ambiguous names at the end of a translation unit,
end_comment

begin_comment
comment|// are not namable at all there, or are special cases in other ways.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 1) Types with only local scope will have their local names:
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// void foo() {
end_comment

begin_comment
comment|//   struct LocalType {} LocalVar;
end_comment

begin_comment
comment|// }
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// LocalVar's type will be named, "struct LocalType", without any
end_comment

begin_comment
comment|// qualification.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// 2) Types that have been shadowed are reported normally, but a
end_comment

begin_comment
comment|// client using that name at the end of the translation unit will be
end_comment

begin_comment
comment|// referring to a different type.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|// ===----------------------------------------------------------------------===//
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_CLANG_TOOLING_CORE_QUALTYPENAMES_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_TOOLING_CORE_QUALTYPENAMES_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/ASTContext.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|namespace
name|TypeName
block|{
comment|/// \brief Get the fully qualified name for a type. This includes full
comment|/// qualification of all template parameters etc.
comment|///
comment|/// \param[in] QT - the type for which the fully qualified name will be
comment|/// returned.
comment|/// \param[in] Ctx - the ASTContext to be used.
comment|/// \param[in] WithGlobalNsPrefix - If true, then the global namespace
comment|/// specifier "::" will be prepended to the fully qualified name.
name|std
operator|::
name|string
name|getFullyQualifiedName
argument_list|(
argument|QualType QT
argument_list|,
argument|const ASTContext&Ctx
argument_list|,
argument|bool WithGlobalNsPrefix = false
argument_list|)
expr_stmt|;
block|}
comment|// end namespace TypeName
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
comment|// LLVM_CLANG_TOOLING_CORE_QUALTYPENAMES_H
end_comment

end_unit

