begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TypeRecordMapping.h --------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_TYPERECORDMAPPING_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_TYPERECORDMAPPING_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CodeViewRecordIO.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeVisitorCallbacks.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|BinaryStreamReader
decl_stmt|;
name|class
name|BinaryStreamWriter
decl_stmt|;
name|namespace
name|codeview
block|{
name|class
name|TypeRecordMapping
range|:
name|public
name|TypeVisitorCallbacks
block|{
name|public
operator|:
name|explicit
name|TypeRecordMapping
argument_list|(
name|BinaryStreamReader
operator|&
name|Reader
argument_list|)
operator|:
name|IO
argument_list|(
argument|Reader
argument_list|)
block|{}
name|explicit
name|TypeRecordMapping
argument_list|(
name|BinaryStreamWriter
operator|&
name|Writer
argument_list|)
operator|:
name|IO
argument_list|(
argument|Writer
argument_list|)
block|{}
name|Error
name|visitTypeBegin
argument_list|(
argument|CVType&Record
argument_list|)
name|override
block|;
name|Error
name|visitTypeEnd
argument_list|(
argument|CVType&Record
argument_list|)
name|override
block|;
name|Error
name|visitMemberBegin
argument_list|(
argument|CVMemberRecord&Record
argument_list|)
name|override
block|;
name|Error
name|visitMemberEnd
argument_list|(
argument|CVMemberRecord&Record
argument_list|)
name|override
block|;
define|#
directive|define
name|TYPE_RECORD
parameter_list|(
name|EnumName
parameter_list|,
name|EnumVal
parameter_list|,
name|Name
parameter_list|)
define|\
value|Error visitKnownRecord(CVType&CVR, Name##Record&Record) override;
define|#
directive|define
name|MEMBER_RECORD
parameter_list|(
name|EnumName
parameter_list|,
name|EnumVal
parameter_list|,
name|Name
parameter_list|)
define|\
value|Error visitKnownMember(CVMemberRecord&CVR, Name##Record&Record) override;
define|#
directive|define
name|TYPE_RECORD_ALIAS
parameter_list|(
name|EnumName
parameter_list|,
name|EnumVal
parameter_list|,
name|Name
parameter_list|,
name|AliasName
parameter_list|)
define|#
directive|define
name|MEMBER_RECORD_ALIAS
parameter_list|(
name|EnumName
parameter_list|,
name|EnumVal
parameter_list|,
name|Name
parameter_list|,
name|AliasName
parameter_list|)
include|#
directive|include
file|"TypeRecords.def"
name|private
operator|:
name|Optional
operator|<
name|TypeLeafKind
operator|>
name|TypeKind
block|;
name|Optional
operator|<
name|TypeLeafKind
operator|>
name|MemberKind
block|;
name|CodeViewRecordIO
name|IO
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

