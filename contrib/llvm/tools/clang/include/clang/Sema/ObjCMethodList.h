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
name|LLVM_CLANG_SEMA_OBJC_METHOD_LIST_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_OBJC_METHOD_LIST_H
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
comment|/// ObjCMethodList - a linked list of methods with different signatures.
struct|struct
name|ObjCMethodList
block|{
name|ObjCMethodDecl
modifier|*
name|Method
decl_stmt|;
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
operator|:
name|Method
argument_list|(
argument|nullptr
argument_list|)
block|{ }
name|ObjCMethodList
argument_list|(
name|ObjCMethodDecl
operator|*
name|M
argument_list|,
name|ObjCMethodList
operator|*
name|C
argument_list|)
operator|:
name|Method
argument_list|(
name|M
argument_list|)
operator|,
name|NextAndExtraBits
argument_list|(
argument|C
argument_list|,
literal|0
argument_list|)
block|{ }
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
block|}
struct|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

