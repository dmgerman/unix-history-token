begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MethodListRecordBuilder.h --------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_METHODLISTRECORDBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_METHODLISTRECORDBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/ListRecordBuilder.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|MethodInfo
decl_stmt|;
name|class
name|MethodListRecordBuilder
range|:
name|public
name|ListRecordBuilder
block|{
name|private
operator|:
name|MethodListRecordBuilder
argument_list|(
specifier|const
name|MethodListRecordBuilder
operator|&
argument_list|)
operator|=
name|delete
block|;
name|MethodListRecordBuilder
operator|&
name|operator
operator|=
operator|(
specifier|const
name|MethodListRecordBuilder
operator|&
operator|)
operator|=
name|delete
block|;
name|public
operator|:
name|MethodListRecordBuilder
argument_list|()
block|;
name|void
name|writeMethod
argument_list|(
argument|MemberAccess Access
argument_list|,
argument|MethodKind Kind
argument_list|,
argument|MethodOptions Options
argument_list|,
argument|TypeIndex Type
argument_list|,
argument|int32_t VTableSlotOffset
argument_list|)
block|;
name|void
name|writeMethod
argument_list|(
specifier|const
name|MethodInfo
operator|&
name|Method
argument_list|)
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

