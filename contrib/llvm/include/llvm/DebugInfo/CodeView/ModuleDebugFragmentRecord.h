begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- ModuleDebugFragment.h ------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_MODULEDEBUGFRAGMENTRECORD_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_MODULEDEBUGFRAGMENTRECORD_H
end_define

begin_include
include|#
directive|include
file|"llvm/DebugInfo/CodeView/CodeView.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamArray.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/BinaryStreamWriter.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Endian.h"
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
name|ModuleDebugFragment
decl_stmt|;
comment|// Corresponds to the `CV_DebugSSubsectionHeader_t` structure.
struct|struct
name|ModuleDebugFragmentHeader
block|{
name|support
operator|::
name|ulittle32_t
name|Kind
expr_stmt|;
comment|// codeview::ModuleDebugFragmentKind enum
name|support
operator|::
name|ulittle32_t
name|Length
expr_stmt|;
comment|// number of bytes occupied by this record.
block|}
struct|;
name|class
name|ModuleDebugFragmentRecord
block|{
name|public
label|:
name|ModuleDebugFragmentRecord
argument_list|()
expr_stmt|;
name|ModuleDebugFragmentRecord
argument_list|(
argument|ModuleDebugFragmentKind Kind
argument_list|,
argument|BinaryStreamRef Data
argument_list|)
empty_stmt|;
specifier|static
name|Error
name|initialize
parameter_list|(
name|BinaryStreamRef
name|Stream
parameter_list|,
name|ModuleDebugFragmentRecord
modifier|&
name|Info
parameter_list|)
function_decl|;
name|uint32_t
name|getRecordLength
argument_list|()
specifier|const
expr_stmt|;
name|ModuleDebugFragmentKind
name|kind
argument_list|()
specifier|const
expr_stmt|;
name|BinaryStreamRef
name|getRecordData
argument_list|()
specifier|const
expr_stmt|;
name|private
label|:
name|ModuleDebugFragmentKind
name|Kind
decl_stmt|;
name|BinaryStreamRef
name|Data
decl_stmt|;
block|}
empty_stmt|;
name|class
name|ModuleDebugFragmentRecordBuilder
block|{
name|public
label|:
name|ModuleDebugFragmentRecordBuilder
argument_list|(
argument|ModuleDebugFragmentKind Kind
argument_list|,
argument|ModuleDebugFragment&Frag
argument_list|)
empty_stmt|;
name|uint32_t
name|calculateSerializedLength
parameter_list|()
function_decl|;
name|Error
name|commit
parameter_list|(
name|BinaryStreamWriter
modifier|&
name|Writer
parameter_list|)
function_decl|;
name|private
label|:
name|ModuleDebugFragmentKind
name|Kind
decl_stmt|;
name|ModuleDebugFragment
modifier|&
name|Frag
decl_stmt|;
block|}
empty_stmt|;
block|}
comment|// namespace codeview
name|template
operator|<
operator|>
expr|struct
name|VarStreamArrayExtractor
operator|<
name|codeview
operator|::
name|ModuleDebugFragmentRecord
operator|>
block|{
typedef|typedef
name|void
name|ContextType
typedef|;
specifier|static
name|Error
name|extract
argument_list|(
argument|BinaryStreamRef Stream
argument_list|,
argument|uint32_t&Length
argument_list|,
argument|codeview::ModuleDebugFragmentRecord&Info
argument_list|)
block|{
if|if
condition|(
name|auto
name|EC
init|=
name|codeview
operator|::
name|ModuleDebugFragmentRecord
operator|::
name|initialize
argument_list|(
name|Stream
argument_list|,
name|Info
argument_list|)
condition|)
return|return
name|EC
return|;
name|Length
operator|=
name|Info
operator|.
name|getRecordLength
argument_list|()
expr_stmt|;
return|return
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
end_decl_stmt

begin_decl_stmt
unit|};
name|namespace
name|codeview
block|{
typedef|typedef
name|VarStreamArray
operator|<
name|ModuleDebugFragmentRecord
operator|>
name|ModuleDebugFragmentArray
expr_stmt|;
block|}
end_decl_stmt

begin_comment
unit|}
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_CODEVIEW_MODULEDEBUGFRAGMENTRECORD_H
end_comment

end_unit

