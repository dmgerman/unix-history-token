begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- FieldListRecordBuilder.h ---------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_FIELDLISTRECORDBUILDER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_FIELDLISTRECORDBUILDER_H
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
block|{
name|public
label|:
name|MethodInfo
argument_list|()
operator|:
name|Access
argument_list|()
operator|,
name|Kind
argument_list|()
operator|,
name|Options
argument_list|()
operator|,
name|Type
argument_list|()
operator|,
name|VTableSlotOffset
argument_list|(
argument|-
literal|1
argument_list|)
block|{}
name|MethodInfo
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
operator|:
name|Access
argument_list|(
name|Access
argument_list|)
operator|,
name|Kind
argument_list|(
name|Kind
argument_list|)
operator|,
name|Options
argument_list|(
name|Options
argument_list|)
operator|,
name|Type
argument_list|(
name|Type
argument_list|)
operator|,
name|VTableSlotOffset
argument_list|(
argument|VTableSlotOffset
argument_list|)
block|{}
name|MemberAccess
name|getAccess
argument_list|()
specifier|const
block|{
return|return
name|Access
return|;
block|}
name|MethodKind
name|getKind
argument_list|()
specifier|const
block|{
return|return
name|Kind
return|;
block|}
name|MethodOptions
name|getOptions
argument_list|()
specifier|const
block|{
return|return
name|Options
return|;
block|}
name|TypeIndex
name|getType
argument_list|()
specifier|const
block|{
return|return
name|Type
return|;
block|}
name|int32_t
name|getVTableSlotOffset
argument_list|()
specifier|const
block|{
return|return
name|VTableSlotOffset
return|;
block|}
name|private
label|:
name|MemberAccess
name|Access
decl_stmt|;
name|MethodKind
name|Kind
decl_stmt|;
name|MethodOptions
name|Options
decl_stmt|;
name|TypeIndex
name|Type
decl_stmt|;
name|int32_t
name|VTableSlotOffset
decl_stmt|;
block|}
empty_stmt|;
name|class
name|FieldListRecordBuilder
range|:
name|public
name|ListRecordBuilder
block|{
name|private
operator|:
name|FieldListRecordBuilder
argument_list|(
specifier|const
name|FieldListRecordBuilder
operator|&
argument_list|)
operator|=
name|delete
block|;
name|void
name|operator
operator|=
operator|(
specifier|const
name|FieldListRecordBuilder
operator|&
operator|)
operator|=
name|delete
block|;
name|public
operator|:
name|FieldListRecordBuilder
argument_list|()
block|;
name|void
name|writeBaseClass
argument_list|(
argument|MemberAccess Access
argument_list|,
argument|TypeIndex Type
argument_list|,
argument|uint64_t Offset
argument_list|)
block|;
name|void
name|writeEnumerate
argument_list|(
argument|MemberAccess Access
argument_list|,
argument|uint64_t Value
argument_list|,
argument|StringRef Name
argument_list|)
block|;
name|void
name|writeIndirectVirtualBaseClass
argument_list|(
argument|MemberAccess Access
argument_list|,
argument|TypeIndex Type
argument_list|,
argument|TypeIndex VirtualBasePointerType
argument_list|,
argument|int64_t VirtualBasePointerOffset
argument_list|,
argument|uint64_t SlotIndex
argument_list|)
block|;
name|void
name|writeMember
argument_list|(
argument|MemberAccess Access
argument_list|,
argument|TypeIndex Type
argument_list|,
argument|uint64_t Offset
argument_list|,
argument|StringRef Name
argument_list|)
block|;
name|void
name|writeOneMethod
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
argument_list|,
argument|StringRef Name
argument_list|)
block|;
name|void
name|writeOneMethod
argument_list|(
argument|const MethodInfo&Method
argument_list|,
argument|StringRef Name
argument_list|)
block|;
name|void
name|writeMethod
argument_list|(
argument|uint16_t OverloadCount
argument_list|,
argument|TypeIndex MethodList
argument_list|,
argument|StringRef Name
argument_list|)
block|;
name|void
name|writeNestedType
argument_list|(
argument|TypeIndex Type
argument_list|,
argument|StringRef Name
argument_list|)
block|;
name|void
name|writeStaticMember
argument_list|(
argument|MemberAccess Access
argument_list|,
argument|TypeIndex Type
argument_list|,
argument|StringRef Name
argument_list|)
block|;
name|void
name|writeVirtualBaseClass
argument_list|(
argument|MemberAccess Access
argument_list|,
argument|TypeIndex Type
argument_list|,
argument|TypeIndex VirtualBasePointerType
argument_list|,
argument|int64_t VirtualBasePointerOffset
argument_list|,
argument|uint64_t SlotIndex
argument_list|)
block|;
name|void
name|writeVirtualBaseClass
argument_list|(
argument|TypeRecordKind Kind
argument_list|,
argument|MemberAccess Access
argument_list|,
argument|TypeIndex Type
argument_list|,
argument|TypeIndex VirtualBasePointerType
argument_list|,
argument|int64_t VirtualBasePointerOffset
argument_list|,
argument|uint64_t SlotIndex
argument_list|)
block|;
name|void
name|writeVirtualFunctionTablePointer
argument_list|(
argument|TypeIndex Type
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

