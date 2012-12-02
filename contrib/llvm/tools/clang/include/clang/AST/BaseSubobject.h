begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- BaseSubobject.h - BaseSubobject class ----------------------------===//
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
comment|// This file provides a definition of the BaseSubobject class.
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
name|LLVM_CLANG_AST_BASESUBOBJECT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_BASESUBOBJECT_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/CharUnits.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/DenseMap.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/type_traits.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|CXXRecordDecl
decl_stmt|;
comment|// BaseSubobject - Uniquely identifies a direct or indirect base class.
comment|// Stores both the base class decl and the offset from the most derived class to
comment|// the base class. Used for vtable and VTT generation.
name|class
name|BaseSubobject
block|{
comment|/// Base - The base class declaration.
specifier|const
name|CXXRecordDecl
modifier|*
name|Base
decl_stmt|;
comment|/// BaseOffset - The offset from the most derived class to the base class.
name|CharUnits
name|BaseOffset
decl_stmt|;
name|public
label|:
name|BaseSubobject
argument_list|()
block|{ }
name|BaseSubobject
argument_list|(
argument|const CXXRecordDecl *Base
argument_list|,
argument|CharUnits BaseOffset
argument_list|)
block|:
name|Base
argument_list|(
name|Base
argument_list|)
operator|,
name|BaseOffset
argument_list|(
argument|BaseOffset
argument_list|)
block|{ }
comment|/// getBase - Returns the base class declaration.
specifier|const
name|CXXRecordDecl
operator|*
name|getBase
argument_list|()
specifier|const
block|{
return|return
name|Base
return|;
block|}
comment|/// getBaseOffset - Returns the base class offset.
name|CharUnits
name|getBaseOffset
argument_list|()
specifier|const
block|{
return|return
name|BaseOffset
return|;
block|}
name|friend
name|bool
name|operator
operator|==
operator|(
specifier|const
name|BaseSubobject
operator|&
name|LHS
operator|,
specifier|const
name|BaseSubobject
operator|&
name|RHS
operator|)
block|{
return|return
name|LHS
operator|.
name|Base
operator|==
name|RHS
operator|.
name|Base
operator|&&
name|LHS
operator|.
name|BaseOffset
operator|==
name|RHS
operator|.
name|BaseOffset
return|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|clang
operator|::
name|BaseSubobject
operator|>
block|{
specifier|static
name|clang
operator|::
name|BaseSubobject
name|getEmptyKey
argument_list|()
block|{
return|return
name|clang
operator|::
name|BaseSubobject
argument_list|(
name|DenseMapInfo
operator|<
specifier|const
name|clang
operator|::
name|CXXRecordDecl
operator|*
operator|>
operator|::
name|getEmptyKey
argument_list|()
argument_list|,
name|clang
operator|::
name|CharUnits
operator|::
name|fromQuantity
argument_list|(
name|DenseMapInfo
operator|<
name|int64_t
operator|>
operator|::
name|getEmptyKey
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|clang
operator|::
name|BaseSubobject
name|getTombstoneKey
argument_list|()
block|{
return|return
name|clang
operator|::
name|BaseSubobject
argument_list|(
name|DenseMapInfo
operator|<
specifier|const
name|clang
operator|::
name|CXXRecordDecl
operator|*
operator|>
operator|::
name|getTombstoneKey
argument_list|()
argument_list|,
name|clang
operator|::
name|CharUnits
operator|::
name|fromQuantity
argument_list|(
name|DenseMapInfo
operator|<
name|int64_t
operator|>
operator|::
name|getTombstoneKey
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
argument|const clang::BaseSubobject&Base
argument_list|)
block|{
typedef|typedef
name|std
operator|::
name|pair
operator|<
specifier|const
name|clang
operator|::
name|CXXRecordDecl
operator|*
operator|,
name|clang
operator|::
name|CharUnits
operator|>
name|PairTy
expr_stmt|;
return|return
name|DenseMapInfo
operator|<
name|PairTy
operator|>
operator|::
name|getHashValue
argument_list|(
name|PairTy
argument_list|(
name|Base
operator|.
name|getBase
argument_list|()
argument_list|,
name|Base
operator|.
name|getBaseOffset
argument_list|()
argument_list|)
argument_list|)
return|;
block|}
specifier|static
name|bool
name|isEqual
argument_list|(
specifier|const
name|clang
operator|::
name|BaseSubobject
operator|&
name|LHS
argument_list|,
specifier|const
name|clang
operator|::
name|BaseSubobject
operator|&
name|RHS
argument_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
comment|// It's OK to treat BaseSubobject as a POD type.
end_comment

begin_expr_stmt
name|template
operator|<
operator|>
expr|struct
name|isPodLike
operator|<
name|clang
operator|::
name|BaseSubobject
operator|>
block|{
specifier|static
specifier|const
name|bool
name|value
operator|=
name|true
block|; }
expr_stmt|;
end_expr_stmt

begin_endif
unit|}
endif|#
directive|endif
end_endif

end_unit

