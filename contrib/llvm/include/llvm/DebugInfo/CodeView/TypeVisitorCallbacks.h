begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TypeVisitorCallbacks.h -----------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_TYPEVISITORCALLBACKS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_TYPEVISITORCALLBACKS_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeRecord.h"
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
name|namespace
name|codeview
block|{
name|class
name|TypeVisitorCallbacks
block|{
name|friend
name|class
name|CVTypeVisitor
decl_stmt|;
name|public
label|:
name|virtual
operator|~
name|TypeVisitorCallbacks
argument_list|()
operator|=
expr|default
expr_stmt|;
comment|/// Action to take on unknown types. By default, they are ignored.
name|virtual
name|Error
name|visitUnknownType
parameter_list|(
name|CVType
modifier|&
name|Record
parameter_list|)
block|{
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
comment|/// Paired begin/end actions for all types. Receives all record data,
comment|/// including the fixed-length record prefix.  visitTypeBegin() should return
comment|/// the type of the Record, or an error if it cannot be determined.  Exactly
comment|/// one of the two visitTypeBegin methods will be called, depending on whether
comment|/// records are being visited sequentially or randomly.  An implementation
comment|/// should be prepared to handle both (or assert if it can't handle random
comment|/// access visitation).
name|virtual
name|Error
name|visitTypeBegin
parameter_list|(
name|CVType
modifier|&
name|Record
parameter_list|)
block|{
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|virtual
name|Error
name|visitTypeBegin
parameter_list|(
name|CVType
modifier|&
name|Record
parameter_list|,
name|TypeIndex
name|Index
parameter_list|)
block|{
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|virtual
name|Error
name|visitTypeEnd
parameter_list|(
name|CVType
modifier|&
name|Record
parameter_list|)
block|{
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|virtual
name|Error
name|visitUnknownMember
parameter_list|(
name|CVMemberRecord
modifier|&
name|Record
parameter_list|)
block|{
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|virtual
name|Error
name|visitMemberBegin
parameter_list|(
name|CVMemberRecord
modifier|&
name|Record
parameter_list|)
block|{
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|virtual
name|Error
name|visitMemberEnd
parameter_list|(
name|CVMemberRecord
modifier|&
name|Record
parameter_list|)
block|{
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
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
value|virtual Error visitKnownRecord(CVType&CVR, Name##Record&Record) {          \     return Error::success();                                                   \   }
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
value|virtual Error visitKnownMember(CVMemberRecord&CVM, Name##Record&Record) {  \     return Error::success();                                                   \   }
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
block|}
empty_stmt|;
block|}
comment|// end namespace codeview
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_CODEVIEW_TYPEVISITORCALLBACKS_H
end_comment

end_unit

