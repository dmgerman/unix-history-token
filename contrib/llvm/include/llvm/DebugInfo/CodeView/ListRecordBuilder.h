begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ListRecordBuilder.h --------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_LISTRECORDBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_LISTRECORDBUILDER_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeRecordBuilder.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|ListRecordBuilder
block|{
name|private
label|:
name|ListRecordBuilder
argument_list|(
specifier|const
name|ListRecordBuilder
operator|&
argument_list|)
operator|=
name|delete
expr_stmt|;
name|ListRecordBuilder
modifier|&
name|operator
init|=
operator|(
specifier|const
name|ListRecordBuilder
operator|&
operator|)
operator|=
name|delete
decl_stmt|;
name|protected
label|:
specifier|const
name|int
name|MethodKindShift
init|=
literal|2
decl_stmt|;
name|explicit
name|ListRecordBuilder
parameter_list|(
name|TypeRecordKind
name|Kind
parameter_list|)
function_decl|;
name|public
label|:
name|llvm
operator|::
name|StringRef
name|str
argument_list|()
block|{
return|return
name|Builder
operator|.
name|str
argument_list|()
return|;
block|}
name|protected
label|:
name|void
name|finishSubRecord
parameter_list|()
function_decl|;
name|TypeRecordBuilder
modifier|&
name|getBuilder
parameter_list|()
block|{
return|return
name|Builder
return|;
block|}
name|private
label|:
name|TypeRecordBuilder
name|Builder
decl_stmt|;
name|SmallVector
operator|<
name|size_t
operator|,
literal|4
operator|>
name|ContinuationOffsets
expr_stmt|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

