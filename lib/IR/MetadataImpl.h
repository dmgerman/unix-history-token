begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MetadataImpl.h - Helpers for implementing metadata -----------------===//
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
comment|// This file has private helpers for implementing metadata types.
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
name|LLVM_IR_METADATAIMPL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_IR_METADATAIMPL_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/DenseSet.h"
end_include

begin_include
include|#
directive|include
file|"llvm/IR/Metadata.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|template
operator|<
name|class
name|T
operator|,
name|class
name|InfoT
operator|>
specifier|static
name|T
operator|*
name|getUniqued
argument_list|(
argument|DenseSet<T *
argument_list|,
argument|InfoT>&Store
argument_list|,
argument|const typename InfoT::KeyTy&Key
argument_list|)
block|{
name|auto
name|I
operator|=
name|Store
operator|.
name|find_as
argument_list|(
name|Key
argument_list|)
block|;
return|return
name|I
operator|==
name|Store
operator|.
name|end
argument_list|()
condition|?
name|nullptr
else|:
operator|*
name|I
return|;
block|}
name|template
operator|<
name|class
name|T
operator|>
name|T
operator|*
name|MDNode
operator|::
name|storeImpl
argument_list|(
argument|T *N
argument_list|,
argument|StorageType Storage
argument_list|)
block|{
switch|switch
condition|(
name|Storage
condition|)
block|{
case|case
name|Uniqued
case|:
name|llvm_unreachable
argument_list|(
literal|"Cannot unique without a uniquing-store"
argument_list|)
expr_stmt|;
case|case
name|Distinct
case|:
name|N
operator|->
name|storeDistinctInContext
argument_list|()
expr_stmt|;
break|break;
case|case
name|Temporary
case|:
break|break;
block|}
return|return
name|N
return|;
block|}
name|template
operator|<
name|class
name|T
operator|,
name|class
name|StoreT
operator|>
name|T
operator|*
name|MDNode
operator|::
name|storeImpl
argument_list|(
argument|T *N
argument_list|,
argument|StorageType Storage
argument_list|,
argument|StoreT&Store
argument_list|)
block|{
switch|switch
condition|(
name|Storage
condition|)
block|{
case|case
name|Uniqued
case|:
name|Store
operator|.
name|insert
argument_list|(
name|N
argument_list|)
expr_stmt|;
break|break;
case|case
name|Distinct
case|:
name|N
operator|->
name|storeDistinctInContext
argument_list|()
expr_stmt|;
break|break;
case|case
name|Temporary
case|:
break|break;
block|}
return|return
name|N
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

