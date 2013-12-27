begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- Linkage.h - Linkage enumeration and utilities ----------*- C++ -*-===//
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
comment|/// \brief Defines the Linkage enumeration and various utility functions.
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
name|LLVM_CLANG_BASIC_LINKAGE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_BASIC_LINKAGE_H
end_define

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Describes the different kinds of linkage
comment|/// (C++ [basic.link], C99 6.2.2) that an entity may have.
enum|enum
name|Linkage
block|{
comment|/// \brief No linkage, which means that the entity is unique and
comment|/// can only be referred to from within its scope.
name|NoLinkage
init|=
literal|0
block|,
comment|/// \brief Internal linkage, which indicates that the entity can
comment|/// be referred to from within the translation unit (but not other
comment|/// translation units).
name|InternalLinkage
block|,
comment|/// \brief External linkage within a unique namespace.
comment|///
comment|/// From the language perspective, these entities have external
comment|/// linkage. However, since they reside in an anonymous namespace,
comment|/// their names are unique to this translation unit, which is
comment|/// equivalent to having internal linkage from the code-generation
comment|/// point of view.
name|UniqueExternalLinkage
block|,
comment|/// \brief External linkage, which indicates that the entity can
comment|/// be referred to from other translation units.
name|ExternalLinkage
block|}
enum|;
comment|/// \brief Describes the different kinds of language linkage
comment|/// (C++ [dcl.link]) that an entity may have.
enum|enum
name|LanguageLinkage
block|{
name|CLanguageLinkage
block|,
name|CXXLanguageLinkage
block|,
name|NoLanguageLinkage
block|}
enum|;
comment|/// \brief A more specific kind of linkage than enum Linkage.
comment|///
comment|/// This is relevant to CodeGen and AST file reading.
enum|enum
name|GVALinkage
block|{
name|GVA_Internal
block|,
name|GVA_C99Inline
block|,
name|GVA_CXXInline
block|,
name|GVA_StrongExternal
block|,
name|GVA_TemplateInstantiation
block|,
name|GVA_ExplicitTemplateInstantiation
block|}
enum|;
comment|/// \brief Determine whether the given linkage is semantically external.
specifier|inline
name|bool
name|isExternalLinkage
parameter_list|(
name|Linkage
name|L
parameter_list|)
block|{
return|return
name|L
operator|==
name|UniqueExternalLinkage
operator|||
name|L
operator|==
name|ExternalLinkage
return|;
block|}
comment|/// \brief Compute the minimum linkage given two linages.
specifier|inline
name|Linkage
name|minLinkage
parameter_list|(
name|Linkage
name|L1
parameter_list|,
name|Linkage
name|L2
parameter_list|)
block|{
return|return
name|L1
operator|<
name|L2
condition|?
name|L1
else|:
name|L2
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
comment|// LLVM_CLANG_BASIC_LINKAGE_H
end_comment

end_unit

