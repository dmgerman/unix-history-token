begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- TypeDumpVisitor.h - CodeView type info dumper -----------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_TYPEDUMPVISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_TYPEDUMPVISITOR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/ArrayRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringSet.h"
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
name|class
name|ScopedPrinter
decl_stmt|;
name|namespace
name|codeview
block|{
comment|/// Dumper for CodeView type streams found in COFF object files and PDB files.
name|class
name|TypeDumpVisitor
range|:
name|public
name|TypeVisitorCallbacks
block|{
name|public
operator|:
name|TypeDumpVisitor
argument_list|(
argument|TypeDatabase&TypeDB
argument_list|,
argument|ScopedPrinter *W
argument_list|,
argument|bool PrintRecordBytes
argument_list|)
operator|:
name|W
argument_list|(
name|W
argument_list|)
block|,
name|PrintRecordBytes
argument_list|(
name|PrintRecordBytes
argument_list|)
block|,
name|TypeDB
argument_list|(
argument|TypeDB
argument_list|)
block|{}
comment|/// When dumping types from an IPI stream in a PDB, a type index may refer to
comment|/// a type or an item ID. The dumper will lookup the "name" of the index in
comment|/// the item database if appropriate. If ItemDB is null, it will use TypeDB,
comment|/// which is correct when dumping types from an object file (/Z7).
name|void
name|setItemDB
argument_list|(
argument|TypeDatabase&DB
argument_list|)
block|{
name|ItemDB
operator|=
operator|&
name|DB
block|; }
name|void
name|printTypeIndex
argument_list|(
argument|StringRef FieldName
argument_list|,
argument|TypeIndex TI
argument_list|)
specifier|const
block|;
name|void
name|printItemIndex
argument_list|(
argument|StringRef FieldName
argument_list|,
argument|TypeIndex TI
argument_list|)
specifier|const
block|;
comment|/// Action to take on unknown types. By default, they are ignored.
name|Error
name|visitUnknownType
argument_list|(
argument|CVType&Record
argument_list|)
name|override
block|;
name|Error
name|visitUnknownMember
argument_list|(
argument|CVMemberRecord&Record
argument_list|)
name|override
block|;
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
file|"TypeRecords.def"
name|private
operator|:
name|void
name|printMemberAttributes
argument_list|(
argument|MemberAttributes Attrs
argument_list|)
block|;
name|void
name|printMemberAttributes
argument_list|(
argument|MemberAccess Access
argument_list|,
argument|MethodKind Kind
argument_list|,
argument|MethodOptions Options
argument_list|)
block|;
comment|/// Get the database of indices for the stream that we are dumping. If ItemDB
comment|/// is set, then we must be dumping an item (IPI) stream. This will also
comment|/// always get the appropriate DB for printing item names.
name|TypeDatabase
operator|&
name|getSourceDB
argument_list|()
specifier|const
block|{
return|return
name|ItemDB
operator|?
operator|*
name|ItemDB
operator|:
name|TypeDB
return|;
block|}
name|ScopedPrinter
operator|*
name|W
block|;
name|bool
name|PrintRecordBytes
operator|=
name|false
block|;
name|TypeDatabase
operator|&
name|TypeDB
block|;
name|TypeDatabase
operator|*
name|ItemDB
operator|=
name|nullptr
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

end_unit

