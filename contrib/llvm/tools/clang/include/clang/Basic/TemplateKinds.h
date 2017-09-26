begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- TemplateKinds.h - Enum values for C++ Template Kinds ---*- C++ -*-===//
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
comment|/// \brief Defines the clang::TemplateNameKind enum.
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
name|LLVM_CLANG_BASIC_TEMPLATEKINDS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_TEMPLATEKINDS_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Specifies the kind of template name that an identifier refers to.
comment|/// Be careful when changing this: this enumeration is used in diagnostics.
enum|enum
name|TemplateNameKind
block|{
comment|/// The name does not refer to a template.
name|TNK_Non_template
init|=
literal|0
block|,
comment|/// The name refers to a function template or a set of overloaded
comment|/// functions that includes at least one function template.
name|TNK_Function_template
block|,
comment|/// The name refers to a template whose specialization produces a
comment|/// type. The template itself could be a class template, template
comment|/// template parameter, or template alias.
name|TNK_Type_template
block|,
comment|/// The name refers to a variable template whose specialization produces a
comment|/// variable.
name|TNK_Var_template
block|,
comment|/// The name refers to a dependent template name:
comment|/// \code
comment|/// template<typename MetaFun, typename T1, typename T2> struct apply2 {
comment|///   typedef typename MetaFun::template apply<T1, T2>::type type;
comment|/// };
comment|/// \endcode
comment|///
comment|/// Here, "apply" is a dependent template name within the typename
comment|/// specifier in the typedef. "apply" is a nested template, and
comment|/// whether the template name is assumed to refer to a type template or a
comment|/// function template depends on the context in which the template
comment|/// name occurs.
name|TNK_Dependent_template_name
block|}
enum|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

