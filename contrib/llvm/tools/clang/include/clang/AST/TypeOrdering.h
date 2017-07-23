begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-------------- TypeOrdering.h - Total ordering for types -------------===//
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
comment|/// \brief Allows QualTypes to be sorted and hence used in maps and sets.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Defines clang::QualTypeOrdering, a total ordering on clang::QualType,
end_comment

begin_comment
comment|/// and hence enables QualType values to be sorted and to be used in
end_comment

begin_comment
comment|/// std::maps, std::sets, llvm::DenseMaps, and llvm::DenseSets.
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
name|LLVM_CLANG_AST_TYPEORDERING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_AST_TYPEORDERING_H
end_define

begin_include
include|#
directive|include
file|"clang/AST/CanonicalType.h"
end_include

begin_include
include|#
directive|include
file|"clang/AST/Type.h"
end_include

begin_include
include|#
directive|include
file|<functional>
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
comment|/// \brief Function object that provides a total ordering on QualType values.
struct|struct
name|QualTypeOrdering
block|{
name|bool
name|operator
argument_list|()
operator|(
name|QualType
name|T1
operator|,
name|QualType
name|T2
operator|)
specifier|const
block|{
return|return
name|std
operator|::
name|less
operator|<
name|void
operator|*
operator|>
operator|(
operator|)
operator|(
name|T1
operator|.
name|getAsOpaquePtr
argument_list|()
operator|,
name|T2
operator|.
name|getAsOpaquePtr
argument_list|()
operator|)
return|;
block|}
block|}
struct|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|class
operator|>
expr|struct
name|DenseMapInfo
expr_stmt|;
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|clang
operator|::
name|QualType
operator|>
block|{
specifier|static
specifier|inline
name|clang
operator|::
name|QualType
name|getEmptyKey
argument_list|()
block|{
return|return
name|clang
operator|::
name|QualType
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|clang
operator|::
name|QualType
name|getTombstoneKey
argument_list|()
block|{
name|using
name|clang
operator|::
name|QualType
block|;
return|return
name|QualType
operator|::
name|getFromOpaquePtr
argument_list|(
name|reinterpret_cast
operator|<
name|clang
operator|::
name|Type
operator|*
operator|>
operator|(
operator|-
literal|1
operator|)
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
argument|clang::QualType Val
argument_list|)
block|{
return|return
call|(
name|unsigned
call|)
argument_list|(
operator|(
name|uintptr_t
operator|)
name|Val
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
operator|^
operator|(
call|(
name|unsigned
call|)
argument_list|(
operator|(
name|uintptr_t
operator|)
name|Val
operator|.
name|getAsOpaquePtr
argument_list|()
operator|>>
literal|9
argument_list|)
operator|)
return|;
block|}
specifier|static
name|bool
name|isEqual
argument_list|(
argument|clang::QualType LHS
argument_list|,
argument|clang::QualType RHS
argument_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
expr|}
block|;
name|template
operator|<
operator|>
expr|struct
name|DenseMapInfo
operator|<
name|clang
operator|::
name|CanQualType
operator|>
block|{
specifier|static
specifier|inline
name|clang
operator|::
name|CanQualType
name|getEmptyKey
argument_list|()
block|{
return|return
name|clang
operator|::
name|CanQualType
argument_list|()
return|;
block|}
specifier|static
specifier|inline
name|clang
operator|::
name|CanQualType
name|getTombstoneKey
argument_list|()
block|{
name|using
name|clang
operator|::
name|CanQualType
block|;
return|return
name|CanQualType
operator|::
name|getFromOpaquePtr
argument_list|(
name|reinterpret_cast
operator|<
name|clang
operator|::
name|Type
operator|*
operator|>
operator|(
operator|-
literal|1
operator|)
argument_list|)
return|;
block|}
specifier|static
name|unsigned
name|getHashValue
argument_list|(
argument|clang::CanQualType Val
argument_list|)
block|{
return|return
call|(
name|unsigned
call|)
argument_list|(
operator|(
name|uintptr_t
operator|)
name|Val
operator|.
name|getAsOpaquePtr
argument_list|()
argument_list|)
operator|^
operator|(
call|(
name|unsigned
call|)
argument_list|(
operator|(
name|uintptr_t
operator|)
name|Val
operator|.
name|getAsOpaquePtr
argument_list|()
operator|>>
literal|9
argument_list|)
operator|)
return|;
block|}
specifier|static
name|bool
name|isEqual
argument_list|(
argument|clang::CanQualType LHS
argument_list|,
argument|clang::CanQualType RHS
argument_list|)
block|{
return|return
name|LHS
operator|==
name|RHS
return|;
block|}
expr|}
block|; }
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

