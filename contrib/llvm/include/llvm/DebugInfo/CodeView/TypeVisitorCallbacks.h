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
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CodeView.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CVRecord.h"
end_include

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
block|{}
comment|/// Action to take on unknown types. By default, they are ignored.
name|virtual
name|Error
name|visitUnknownType
argument_list|(
argument|const CVRecord<TypeLeafKind>&Record
argument_list|)
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
argument_list|(
specifier|const
name|CVRecord
operator|<
name|TypeLeafKind
operator|>
operator|&
name|Record
argument_list|)
block|{
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
comment|/// Paired begin/end actions for all types. Receives all record data,
comment|/// including the fixed-length record prefix.
name|virtual
name|Error
name|visitTypeBegin
argument_list|(
specifier|const
name|CVRecord
operator|<
name|TypeLeafKind
operator|>
operator|&
name|Record
argument_list|)
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
argument_list|(
specifier|const
name|CVRecord
operator|<
name|TypeLeafKind
operator|>
operator|&
name|Record
argument_list|)
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
name|visitFieldListBegin
argument_list|(
specifier|const
name|CVRecord
operator|<
name|TypeLeafKind
operator|>
operator|&
name|Record
argument_list|)
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
name|visitFieldListEnd
argument_list|(
specifier|const
name|CVRecord
operator|<
name|TypeLeafKind
operator|>
operator|&
name|Record
argument_list|)
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
value|virtual Error visit##Name(Name##Record&Record) { return Error::success(); }
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
value|TYPE_RECORD(EnumName, EnumVal, Name)
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
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

