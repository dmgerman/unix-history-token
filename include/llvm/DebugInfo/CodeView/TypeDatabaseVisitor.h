begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- TypeDatabaseVisitor.h -----------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_TYPEDATABASEVISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_TYPEDATABASEVISITOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/PointerUnion.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeDatabase.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeIndex.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeRecord.h"
end_include

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeVisitorCallbacks.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
comment|/// Dumper for CodeView type streams found in COFF object files and PDB files.
name|class
name|TypeDatabaseVisitor
range|:
name|public
name|TypeVisitorCallbacks
block|{
name|public
operator|:
name|explicit
name|TypeDatabaseVisitor
argument_list|(
name|TypeDatabase
operator|&
name|TypeDB
argument_list|)
operator|:
name|TypeDB
argument_list|(
argument|&TypeDB
argument_list|)
block|{}
comment|/// Paired begin/end actions for all types. Receives all record data,
comment|/// including the fixed-length record prefix.
name|Error
name|visitTypeBegin
argument_list|(
argument|CVType&Record
argument_list|)
name|override
block|;
name|Error
name|visitTypeBegin
argument_list|(
argument|CVType&Record
argument_list|,
argument|TypeIndex Index
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
file|"llvm/DebugInfo/CodeView/CodeViewTypes.def"
name|private
operator|:
name|StringRef
name|getTypeName
argument_list|(
argument|TypeIndex Index
argument_list|)
specifier|const
block|;
name|StringRef
name|saveTypeName
argument_list|(
argument|StringRef Name
argument_list|)
block|;
name|bool
name|IsInFieldList
operator|=
name|false
block|;
comment|/// Name of the current type. Only valid before visitTypeEnd.
name|StringRef
name|Name
block|;
comment|/// Current type index.  Only valid before visitTypeEnd, and if we are
comment|/// visiting a random access type database.
name|Optional
operator|<
name|TypeIndex
operator|>
name|CurrentTypeIndex
block|;
name|TypeDatabase
operator|*
name|TypeDB
block|; }
decl_stmt|;
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
comment|// LLVM_DEBUGINFO_CODEVIEW_TYPEDUMPER_H
end_comment

end_unit

