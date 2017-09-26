begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MinimalTypeDumper.h ------------------------------------ *- C++ --*-===//
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
name|LLVM_TOOLS_LLVMPDBUTIL_MINIMAL_TYPE_DUMPER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLVMPDBUTIL_MINIMAL_TYPE_DUMPER_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/TypeVisitorCallbacks.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamArray.h"
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|codeview
block|{
name|class
name|LazyRandomTypeCollection
decl_stmt|;
block|}
name|namespace
name|pdb
block|{
name|class
name|LinePrinter
decl_stmt|;
name|class
name|MinimalTypeDumpVisitor
range|:
name|public
name|codeview
operator|::
name|TypeVisitorCallbacks
block|{
name|public
operator|:
name|MinimalTypeDumpVisitor
argument_list|(
argument|LinePrinter&P
argument_list|,
argument|uint32_t Width
argument_list|,
argument|bool RecordBytes
argument_list|,
argument|bool Hashes
argument_list|,
argument|codeview::LazyRandomTypeCollection&Types
argument_list|,
argument|uint32_t NumHashBuckets
argument_list|,
argument|FixedStreamArray<support::ulittle32_t> HashValues
argument_list|)
operator|:
name|P
argument_list|(
name|P
argument_list|)
block|,
name|Width
argument_list|(
name|Width
argument_list|)
block|,
name|RecordBytes
argument_list|(
name|RecordBytes
argument_list|)
block|,
name|Hashes
argument_list|(
name|Hashes
argument_list|)
block|,
name|Types
argument_list|(
name|Types
argument_list|)
block|,
name|NumHashBuckets
argument_list|(
name|NumHashBuckets
argument_list|)
block|,
name|HashValues
argument_list|(
argument|HashValues
argument_list|)
block|{}
name|Error
name|visitTypeBegin
argument_list|(
argument|codeview::CVType&Record
argument_list|,
argument|codeview::TypeIndex Index
argument_list|)
name|override
block|;
name|Error
name|visitTypeEnd
argument_list|(
argument|codeview::CVType&Record
argument_list|)
name|override
block|;
name|Error
name|visitMemberBegin
argument_list|(
argument|codeview::CVMemberRecord&Record
argument_list|)
name|override
block|;
name|Error
name|visitMemberEnd
argument_list|(
argument|codeview::CVMemberRecord&Record
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
value|Error visitKnownRecord(codeview::CVType&CVR,                                \                          codeview::Name##Record&Record) override;
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
value|Error visitKnownMember(codeview::CVMemberRecord&CVR,                        \                          codeview::Name##Record&Record) override;
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
argument|codeview::TypeIndex TI
argument_list|)
specifier|const
block|;
name|LinePrinter
operator|&
name|P
block|;
name|uint32_t
name|Width
block|;
name|bool
name|RecordBytes
operator|=
name|false
block|;
name|bool
name|Hashes
operator|=
name|false
block|;
name|codeview
operator|::
name|LazyRandomTypeCollection
operator|&
name|Types
block|;
name|uint32_t
name|NumHashBuckets
block|;
name|FixedStreamArray
operator|<
name|support
operator|::
name|ulittle32_t
operator|>
name|HashValues
block|; }
decl_stmt|;
block|}
comment|// namespace pdb
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

