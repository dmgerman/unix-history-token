begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- LocInfoType.h - Parsed Type with Location Information---*- C++ -*-===//
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
comment|// This file defines the LocInfoType class, which holds a type and its
end_comment

begin_comment
comment|// source-location information.
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
name|LLVM_CLANG_SEMA_LOCINFOTYPE_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_LOCINFOTYPE_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|TypeSourceInfo
decl_stmt|;
comment|/// \brief Holds a QualType and a TypeSourceInfo* that came out of a declarator
comment|/// parsing.
comment|///
comment|/// LocInfoType is a "transient" type, only needed for passing to/from Parser
comment|/// and Sema, when we want to preserve type source info for a parsed type.
comment|/// It will not participate in the type system semantics in any way.
name|class
name|LocInfoType
range|:
name|public
name|Type
block|{   enum
block|{
comment|// The last number that can fit in Type's TC.
comment|// Avoids conflict with an existing Type class.
name|LocInfo
operator|=
name|Type
operator|::
name|TypeLast
operator|+
literal|1
block|}
block|;
name|TypeSourceInfo
operator|*
name|DeclInfo
block|;
name|LocInfoType
argument_list|(
argument|QualType ty
argument_list|,
argument|TypeSourceInfo *TInfo
argument_list|)
operator|:
name|Type
argument_list|(
operator|(
name|TypeClass
operator|)
name|LocInfo
argument_list|,
name|ty
argument_list|,
name|ty
operator|->
name|isDependentType
argument_list|()
argument_list|,
name|ty
operator|->
name|isInstantiationDependentType
argument_list|()
argument_list|,
name|ty
operator|->
name|isVariablyModifiedType
argument_list|()
argument_list|,
name|ty
operator|->
name|containsUnexpandedParameterPack
argument_list|()
argument_list|)
block|,
name|DeclInfo
argument_list|(
argument|TInfo
argument_list|)
block|{
name|assert
argument_list|(
name|getTypeClass
argument_list|()
operator|==
operator|(
name|TypeClass
operator|)
name|LocInfo
operator|&&
literal|"LocInfo didn't fit in TC?"
argument_list|)
block|;   }
name|friend
name|class
name|Sema
block|;
name|public
operator|:
name|QualType
name|getType
argument_list|()
specifier|const
block|{
return|return
name|getCanonicalTypeInternal
argument_list|()
return|;
block|}
name|TypeSourceInfo
operator|*
name|getTypeSourceInfo
argument_list|()
specifier|const
block|{
return|return
name|DeclInfo
return|;
block|}
name|void
name|getAsStringInternal
argument_list|(
argument|std::string&Str
argument_list|,
argument|const PrintingPolicy&Policy
argument_list|)
specifier|const
block|;
specifier|static
name|bool
name|classof
argument_list|(
argument|const Type *T
argument_list|)
block|{
return|return
name|T
operator|->
name|getTypeClass
argument_list|()
operator|==
operator|(
name|TypeClass
operator|)
name|LocInfo
return|;
block|}
expr|}
block|;  }
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_CLANG_SEMA_LOCINFOTYPE_H
end_comment

end_unit

