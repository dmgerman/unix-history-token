begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- TypeServerHandler.h --------------------------------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_CODEVIEW_TYPESERVERHANDLER_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_CODEVIEW_TYPESERVERHANDLER_H
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
decl_stmt|;
name|class
name|TypeServerHandler
block|{
name|public
label|:
name|virtual
operator|~
name|TypeServerHandler
argument_list|()
block|{}
comment|/// Handle a TypeServer record.  If the implementation returns true
comment|/// the record will not be processed by the top-level visitor.  If
comment|/// it returns false, it will be processed.  If it returns an Error,
comment|/// then the top-level visitor will fail.
name|virtual
name|Expected
operator|<
name|bool
operator|>
name|handle
argument_list|(
argument|TypeServer2Record&TS
argument_list|,
argument|TypeVisitorCallbacks&Callbacks
argument_list|)
block|{
return|return
name|false
return|;
block|}
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

