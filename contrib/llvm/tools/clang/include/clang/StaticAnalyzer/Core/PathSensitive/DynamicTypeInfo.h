begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//== DynamicTypeInfo.h - Runtime type information ----------------*- C++ -*--=//
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
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_DYNAMICTYPEINFO_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_STATICANALYZER_CORE_PATHSENSITIVE_DYNAMICTYPEINFO_H
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
name|namespace
name|ento
block|{
comment|/// \brief Stores the currently inferred strictest bound on the runtime type
comment|/// of a region in a given state along the analysis path.
name|class
name|DynamicTypeInfo
block|{
name|private
label|:
name|QualType
name|T
decl_stmt|;
name|bool
name|CanBeASubClass
decl_stmt|;
name|public
label|:
name|DynamicTypeInfo
argument_list|()
operator|:
name|T
argument_list|(
argument|QualType()
argument_list|)
block|{}
name|DynamicTypeInfo
argument_list|(
argument|QualType WithType
argument_list|,
argument|bool CanBeSub = true
argument_list|)
operator|:
name|T
argument_list|(
name|WithType
argument_list|)
operator|,
name|CanBeASubClass
argument_list|(
argument|CanBeSub
argument_list|)
block|{}
comment|/// \brief Return false if no dynamic type info is available.
name|bool
name|isValid
argument_list|()
specifier|const
block|{
return|return
operator|!
name|T
operator|.
name|isNull
argument_list|()
return|;
block|}
comment|/// \brief Returns the currently inferred upper bound on the runtime type.
name|QualType
name|getType
argument_list|()
specifier|const
block|{
return|return
name|T
return|;
block|}
comment|/// \brief Returns false if the type information is precise (the type T is
comment|/// the only type in the lattice), true otherwise.
name|bool
name|canBeASubClass
argument_list|()
specifier|const
block|{
return|return
name|CanBeASubClass
return|;
block|}
name|void
name|Profile
argument_list|(
name|llvm
operator|::
name|FoldingSetNodeID
operator|&
name|ID
argument_list|)
decl|const
block|{
name|ID
operator|.
name|Add
argument_list|(
name|T
argument_list|)
expr_stmt|;
name|ID
operator|.
name|AddInteger
argument_list|(
operator|(
name|unsigned
operator|)
name|CanBeASubClass
argument_list|)
expr_stmt|;
block|}
name|bool
name|operator
operator|==
operator|(
specifier|const
name|DynamicTypeInfo
operator|&
name|X
operator|)
specifier|const
block|{
return|return
name|T
operator|==
name|X
operator|.
name|T
operator|&&
name|CanBeASubClass
operator|==
name|X
operator|.
name|CanBeASubClass
return|;
block|}
block|}
empty_stmt|;
block|}
comment|// end ento
block|}
end_decl_stmt

begin_comment
comment|// end clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

