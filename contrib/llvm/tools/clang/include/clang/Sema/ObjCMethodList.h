begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===--- ObjCMethodList.h - A singly linked list of methods -----*- C++ -*-===//
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
comment|// This file defines ObjCMethodList, a singly-linked list of methods.
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
name|LLVM_CLANG_SEMA_OBJCMETHODLIST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_OBJCMETHODLIST_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/PointerIntPair.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|ObjCMethodDecl
decl_stmt|;
comment|/// \brief a linked list of methods with the same selector name but different
comment|/// signatures.
struct|struct
name|ObjCMethodList
block|{
comment|// NOTE: If you add any members to this struct, make sure to serialize them.
comment|/// \brief If there is more than one decl with this signature.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|ObjCMethodDecl
operator|*
operator|,
literal|1
operator|>
name|MethodAndHasMoreThanOneDecl
expr_stmt|;
comment|/// \brief The next list object and 2 bits for extra info.
name|llvm
operator|::
name|PointerIntPair
operator|<
name|ObjCMethodList
operator|*
operator|,
literal|2
operator|>
name|NextAndExtraBits
expr_stmt|;
name|ObjCMethodList
argument_list|()
block|{ }
name|ObjCMethodList
argument_list|(
name|ObjCMethodDecl
operator|*
name|M
argument_list|)
operator|:
name|MethodAndHasMoreThanOneDecl
argument_list|(
argument|M
argument_list|,
literal|0
argument_list|)
block|{}
name|ObjCMethodList
operator|*
name|getNext
argument_list|()
specifier|const
block|{
return|return
name|NextAndExtraBits
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|unsigned
name|getBits
argument_list|()
specifier|const
block|{
return|return
name|NextAndExtraBits
operator|.
name|getInt
argument_list|()
return|;
block|}
name|void
name|setNext
parameter_list|(
name|ObjCMethodList
modifier|*
name|L
parameter_list|)
block|{
name|NextAndExtraBits
operator|.
name|setPointer
argument_list|(
name|L
argument_list|)
expr_stmt|;
block|}
name|void
name|setBits
parameter_list|(
name|unsigned
name|B
parameter_list|)
block|{
name|NextAndExtraBits
operator|.
name|setInt
argument_list|(
name|B
argument_list|)
expr_stmt|;
block|}
name|ObjCMethodDecl
operator|*
name|getMethod
argument_list|()
specifier|const
block|{
return|return
name|MethodAndHasMoreThanOneDecl
operator|.
name|getPointer
argument_list|()
return|;
block|}
name|void
name|setMethod
parameter_list|(
name|ObjCMethodDecl
modifier|*
name|M
parameter_list|)
block|{
return|return
name|MethodAndHasMoreThanOneDecl
operator|.
name|setPointer
argument_list|(
name|M
argument_list|)
return|;
block|}
name|bool
name|hasMoreThanOneDecl
argument_list|()
specifier|const
block|{
return|return
name|MethodAndHasMoreThanOneDecl
operator|.
name|getInt
argument_list|()
return|;
block|}
name|void
name|setHasMoreThanOneDecl
parameter_list|(
name|bool
name|B
parameter_list|)
block|{
return|return
name|MethodAndHasMoreThanOneDecl
operator|.
name|setInt
argument_list|(
name|B
argument_list|)
return|;
block|}
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

