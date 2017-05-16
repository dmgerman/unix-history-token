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
file|"llvm/ADT/TinyPtrVector.h"
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
file|"llvm/DebugInfo/CodeView/TypeServerHandler.h"
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
name|namespace
name|codeview
block|{
name|class
name|CVTypeVisitor
block|{
name|public
label|:
name|explicit
name|CVTypeVisitor
parameter_list|(
name|TypeVisitorCallbacks
modifier|&
name|Callbacks
parameter_list|)
function_decl|;
name|void
name|addTypeServerHandler
parameter_list|(
name|TypeServerHandler
modifier|&
name|Handler
parameter_list|)
function_decl|;
name|Error
name|visitTypeRecord
parameter_list|(
name|CVType
modifier|&
name|Record
parameter_list|,
name|TypeIndex
name|Index
parameter_list|)
function_decl|;
name|Error
name|visitTypeRecord
parameter_list|(
name|CVType
modifier|&
name|Record
parameter_list|)
function_decl|;
name|Error
name|visitMemberRecord
parameter_list|(
name|CVMemberRecord
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// Visits the type records in Data. Sets the error flag on parse failures.
name|Error
name|visitTypeStream
parameter_list|(
specifier|const
name|CVTypeArray
modifier|&
name|Types
parameter_list|)
function_decl|;
name|Error
name|visitTypeStream
parameter_list|(
name|CVTypeRange
name|Types
parameter_list|)
function_decl|;
name|Error
name|visitFieldListMemberStream
argument_list|(
name|ArrayRef
operator|<
name|uint8_t
operator|>
name|FieldList
argument_list|)
decl_stmt|;
name|Error
name|visitFieldListMemberStream
parameter_list|(
name|BinaryStreamReader
name|Reader
parameter_list|)
function_decl|;
name|private
label|:
name|Expected
operator|<
name|bool
operator|>
name|handleTypeServer
argument_list|(
name|CVType
operator|&
name|Record
argument_list|)
expr_stmt|;
name|Error
name|finishVisitation
parameter_list|(
name|CVType
modifier|&
name|Record
parameter_list|)
function_decl|;
comment|/// The interface to the class that gets notified of each visitation.
name|TypeVisitorCallbacks
modifier|&
name|Callbacks
decl_stmt|;
name|TinyPtrVector
operator|<
name|TypeServerHandler
operator|*
operator|>
name|Handlers
expr_stmt|;
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
comment|// LLVM_DEBUGINFO_CODEVIEW_CVTYPEVISITOR_H
end_comment

end_unit

