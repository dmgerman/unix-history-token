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
name|ObjCMethodList
modifier|*
name|Next
decl_stmt|;
name|ObjCMethodList
argument_list|()
block|{
name|Method
operator|=
literal|0
expr_stmt|;
name|Next
operator|=
literal|0
expr_stmt|;
block|}
name|ObjCMethodList
argument_list|(
argument|ObjCMethodDecl *M
argument_list|,
argument|ObjCMethodList *C
argument_list|)
block|{
name|Method
operator|=
name|M
expr_stmt|;
name|Next
operator|=
name|C
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

