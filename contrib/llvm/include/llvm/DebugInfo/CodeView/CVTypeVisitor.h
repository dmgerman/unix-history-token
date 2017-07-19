begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- CVTypeVisitor.h ------------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_CVTYPEVISITOR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_CVTYPEVISITOR_H
end_define

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
name|TypeCollection
decl_stmt|;
name|class
name|TypeVisitorCallbacks
decl_stmt|;
enum|enum
name|VisitorDataSource
block|{
name|VDS_BytesPresent
block|,
comment|// The record bytes are passed into the the visitation
comment|// function.  The algorithm should first deserialize them
comment|// before passing them on through the pipeline.
name|VDS_BytesExternal
comment|// The record bytes are not present, and it is the
comment|// responsibility of the visitor callback interface to
comment|// supply the bytes.
block|}
enum|;
name|Error
name|visitTypeRecord
parameter_list|(
name|CVType
modifier|&
name|Record
parameter_list|,
name|TypeIndex
name|Index
parameter_list|,
name|TypeVisitorCallbacks
modifier|&
name|Callbacks
parameter_list|,
name|VisitorDataSource
name|Source
init|=
name|VDS_BytesPresent
parameter_list|)
function_decl|;
name|Error
name|visitTypeRecord
parameter_list|(
name|CVType
modifier|&
name|Record
parameter_list|,
name|TypeVisitorCallbacks
modifier|&
name|Callbacks
parameter_list|,
name|VisitorDataSource
name|Source
init|=
name|VDS_BytesPresent
parameter_list|)
function_decl|;
name|Error
name|visitMemberRecord
parameter_list|(
name|CVMemberRecord
name|Record
parameter_list|,
name|TypeVisitorCallbacks
modifier|&
name|Callbacks
parameter_list|,
name|VisitorDataSource
name|Source
init|=
name|VDS_BytesPresent
parameter_list|)
function_decl|;
name|Error
name|visitMemberRecord
argument_list|(
name|TypeLeafKind
name|Kind
argument_list|,
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|Record
argument_list|,
name|TypeVisitorCallbacks
operator|&
name|Callbacks
argument_list|)
decl_stmt|;
name|Error
name|visitMemberRecordStream
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|FieldList
argument_list|,
name|TypeVisitorCallbacks
operator|&
name|Callbacks
argument_list|)
decl_stmt|;
name|Error
name|visitTypeStream
parameter_list|(
specifier|const
name|CVTypeArray
modifier|&
name|Types
parameter_list|,
name|TypeVisitorCallbacks
modifier|&
name|Callbacks
parameter_list|,
name|VisitorDataSource
name|Source
init|=
name|VDS_BytesPresent
parameter_list|)
function_decl|;
name|Error
name|visitTypeStream
parameter_list|(
name|CVTypeRange
name|Types
parameter_list|,
name|TypeVisitorCallbacks
modifier|&
name|Callbacks
parameter_list|)
function_decl|;
name|Error
name|visitTypeStream
parameter_list|(
name|TypeCollection
modifier|&
name|Types
parameter_list|,
name|TypeVisitorCallbacks
modifier|&
name|Callbacks
parameter_list|)
function_decl|;
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
comment|// LLVM_DEBUGINFO_CODEVIEW_CVTYPEVISITOR_H
end_comment

end_unit

