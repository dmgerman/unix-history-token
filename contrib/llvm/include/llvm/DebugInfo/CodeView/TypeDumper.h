begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- TypeDumper.h - CodeView type info dumper ----------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_TYPEDUMPER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_TYPEDUMPER_H
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
name|CVTypeDumper
range|:
name|public
name|TypeVisitorCallbacks
block|{
name|public
operator|:
name|CVTypeDumper
argument_list|(
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
argument|PrintRecordBytes
argument_list|)
block|{}
name|StringRef
name|getTypeName
argument_list|(
argument|TypeIndex TI
argument_list|)
block|;
name|void
name|printTypeIndex
argument_list|(
argument|StringRef FieldName
argument_list|,
argument|TypeIndex TI
argument_list|)
block|;
comment|/// Dumps one type record.  Returns false if there was a type parsing error,
comment|/// and true otherwise.  This should be called in order, since the dumper
comment|/// maintains state about previous records which are necessary for cross
comment|/// type references.
name|Error
name|dump
argument_list|(
specifier|const
name|CVRecord
operator|<
name|TypeLeafKind
operator|>
operator|&
name|Record
argument_list|)
block|;
comment|/// Dumps the type records in Types. Returns false if there was a type stream
comment|/// parse error, and true otherwise.
name|Error
name|dump
argument_list|(
specifier|const
name|CVTypeArray
operator|&
name|Types
argument_list|)
block|;
comment|/// Dumps the type records in Data. Returns false if there was a type stream
comment|/// parse error, and true otherwise. Use this method instead of the
comment|/// CVTypeArray overload when type records are laid out contiguously in
comment|/// memory.
name|Error
name|dump
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Data
argument_list|)
block|;
comment|/// Gets the type index for the next type record.
name|unsigned
name|getNextTypeIndex
argument_list|()
specifier|const
block|{
return|return
literal|0x1000
operator|+
name|CVUDTNames
operator|.
name|size
argument_list|()
return|;
block|}
comment|/// Records the name of a type, and reserves its type index.
name|void
name|recordType
argument_list|(
argument|StringRef Name
argument_list|)
block|{
name|CVUDTNames
operator|.
name|push_back
argument_list|(
name|Name
argument_list|)
block|; }
comment|/// Saves the name in a StringSet and creates a stable StringRef.
name|StringRef
name|saveName
argument_list|(
argument|StringRef TypeName
argument_list|)
block|{
return|return
name|TypeNames
operator|.
name|insert
argument_list|(
name|TypeName
argument_list|)
operator|.
name|first
operator|->
name|getKey
argument_list|()
return|;
block|}
name|void
name|setPrinter
argument_list|(
name|ScopedPrinter
operator|*
name|P
argument_list|)
block|;
name|ScopedPrinter
operator|*
name|getPrinter
argument_list|()
block|{
return|return
name|W
return|;
block|}
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
name|ScopedPrinter
operator|*
name|W
block|;
name|bool
name|IsInFieldList
operator|=
name|false
block|;
name|bool
name|PrintRecordBytes
operator|=
name|false
block|;
comment|/// Name of the current type. Only valid before visitTypeEnd.
name|StringRef
name|Name
block|;
comment|/// All user defined type records in .debug$T live in here. Type indices
comment|/// greater than 0x1000 are user defined. Subtract 0x1000 from the index to
comment|/// index into this vector.
name|SmallVector
operator|<
name|StringRef
block|,
literal|10
operator|>
name|CVUDTNames
block|;
name|StringSet
operator|<
operator|>
name|TypeNames
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

