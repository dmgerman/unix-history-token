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

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<utility>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Describes the different kinds of linkage
comment|/// (C++ [basic.link], C99 6.2.2) that an entity may have.
enum|enum
name|Linkage
enum|:
name|unsigned
name|char
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
comment|/// \brief No linkage according to the standard, but is visible from other
comment|/// translation units because of types defined in a inline function.
name|VisibleNoLinkage
block|,
comment|/// \brief Internal linkage according to the Modules TS, but can be referred
comment|/// to from other translation units indirectly through inline functions and
comment|/// templates in the module interface.
name|ModuleInternalLinkage
block|,
comment|/// \brief Module linkage, which indicates that the entity can be referred
comment|/// to from other translation units within the same module, and indirectly
comment|/// from arbitrary other translation units through inline functions and
comment|/// templates in the module interface.
name|ModuleLinkage
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
name|GVA_AvailableExternally
block|,
name|GVA_DiscardableODR
block|,
name|GVA_StrongExternal
block|,
name|GVA_StrongODR
block|}
enum|;
specifier|inline
name|bool
name|isDiscardableGVALinkage
parameter_list|(
name|GVALinkage
name|L
parameter_list|)
block|{
return|return
name|L
operator|<=
name|GVA_DiscardableODR
return|;
block|}
specifier|inline
name|bool
name|isExternallyVisible
parameter_list|(
name|Linkage
name|L
parameter_list|)
block|{
return|return
name|L
operator|>=
name|VisibleNoLinkage
return|;
block|}
specifier|inline
name|Linkage
name|getFormalLinkage
parameter_list|(
name|Linkage
name|L
parameter_list|)
block|{
switch|switch
condition|(
name|L
condition|)
block|{
case|case
name|UniqueExternalLinkage
case|:
return|return
name|ExternalLinkage
return|;
case|case
name|VisibleNoLinkage
case|:
return|return
name|NoLinkage
return|;
case|case
name|ModuleInternalLinkage
case|:
return|return
name|InternalLinkage
return|;
default|default:
return|return
name|L
return|;
block|}
block|}
specifier|inline
name|bool
name|isExternalFormalLinkage
parameter_list|(
name|Linkage
name|L
parameter_list|)
block|{
return|return
name|getFormalLinkage
argument_list|(
name|L
argument_list|)
operator|==
name|ExternalLinkage
return|;
block|}
comment|/// \brief Compute the minimum linkage given two linkages.
comment|///
comment|/// The linkage can be interpreted as a pair formed by the formal linkage and
comment|/// a boolean for external visibility. This is just what getFormalLinkage and
comment|/// isExternallyVisible return. We want the minimum of both components. The
comment|/// Linkage enum is defined in an order that makes this simple, we just need
comment|/// special cases for when VisibleNoLinkage would lose the visible bit and
comment|/// become NoLinkage.
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
if|if
condition|(
name|L2
operator|==
name|VisibleNoLinkage
condition|)
name|std
operator|::
name|swap
argument_list|(
name|L1
argument_list|,
name|L2
argument_list|)
expr_stmt|;
if|if
condition|(
name|L1
operator|==
name|VisibleNoLinkage
condition|)
block|{
if|if
condition|(
name|L2
operator|==
name|InternalLinkage
condition|)
return|return
name|NoLinkage
return|;
if|if
condition|(
name|L2
operator|==
name|UniqueExternalLinkage
condition|)
return|return
name|NoLinkage
return|;
block|}
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

