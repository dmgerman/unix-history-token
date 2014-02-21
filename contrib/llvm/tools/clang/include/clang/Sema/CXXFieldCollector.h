begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CXXFieldCollector.h - Utility class for C++ class semantic analysis ===//
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
comment|//  This file provides CXXFieldCollector that is used during parsing& semantic
end_comment

begin_comment
comment|//  analysis of C++ classes.
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
name|LLVM_CLANG_SEMA_CXXFIELDCOLLECTOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_CLANG_SEMA_CXXFIELDCOLLECTOR_H
end_define

begin_include
include|#
directive|include
file|"clang/Basic/LLVM.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_decl_stmt
name|namespace
name|clang
block|{
name|class
name|FieldDecl
decl_stmt|;
comment|/// CXXFieldCollector - Used to keep track of CXXFieldDecls during parsing of
comment|/// C++ classes.
name|class
name|CXXFieldCollector
block|{
comment|/// Fields - Contains all FieldDecls collected during parsing of a C++
comment|/// class. When a nested class is entered, its fields are appended to the
comment|/// fields of its parent class, when it is exited its fields are removed.
name|SmallVector
operator|<
name|FieldDecl
operator|*
operator|,
literal|32
operator|>
name|Fields
expr_stmt|;
comment|/// FieldCount - Each entry represents the number of fields collected during
comment|/// the parsing of a C++ class. When a nested class is entered, a new field
comment|/// count is pushed, when it is exited, the field count is popped.
name|SmallVector
operator|<
name|size_t
operator|,
literal|4
operator|>
name|FieldCount
expr_stmt|;
comment|// Example:
comment|//
comment|// class C {
comment|//   int x,y;
comment|//   class NC {
comment|//     int q;
comment|//     // At this point, Fields contains [x,y,q] decls and FieldCount contains
comment|//     // [2,1].
comment|//   };
comment|//   int z;
comment|//   // At this point, Fields contains [x,y,z] decls and FieldCount contains
comment|//   // [3].
comment|// };
name|public
label|:
comment|/// StartClass - Called by Sema::ActOnStartCXXClassDef.
name|void
name|StartClass
parameter_list|()
block|{
name|FieldCount
operator|.
name|push_back
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
comment|/// Add - Called by Sema::ActOnCXXMemberDeclarator.
name|void
name|Add
parameter_list|(
name|FieldDecl
modifier|*
name|D
parameter_list|)
block|{
name|Fields
operator|.
name|push_back
argument_list|(
name|D
argument_list|)
expr_stmt|;
operator|++
name|FieldCount
operator|.
name|back
argument_list|()
expr_stmt|;
block|}
comment|/// getCurNumField - The number of fields added to the currently parsed class.
name|size_t
name|getCurNumFields
argument_list|()
specifier|const
block|{
name|assert
argument_list|(
operator|!
name|FieldCount
operator|.
name|empty
argument_list|()
operator|&&
literal|"no currently-parsed class"
argument_list|)
block|;
return|return
name|FieldCount
operator|.
name|back
argument_list|()
return|;
block|}
comment|/// getCurFields - Pointer to array of fields added to the currently parsed
comment|/// class.
name|FieldDecl
modifier|*
modifier|*
name|getCurFields
parameter_list|()
block|{
return|return
operator|&
operator|*
operator|(
name|Fields
operator|.
name|end
argument_list|()
operator|-
name|getCurNumFields
argument_list|()
operator|)
return|;
block|}
comment|/// FinishClass - Called by Sema::ActOnFinishCXXClassDef.
name|void
name|FinishClass
parameter_list|()
block|{
name|Fields
operator|.
name|resize
argument_list|(
name|Fields
operator|.
name|size
argument_list|()
operator|-
name|getCurNumFields
argument_list|()
argument_list|)
expr_stmt|;
name|FieldCount
operator|.
name|pop_back
argument_list|()
expr_stmt|;
block|}
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// end namespace clang
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

