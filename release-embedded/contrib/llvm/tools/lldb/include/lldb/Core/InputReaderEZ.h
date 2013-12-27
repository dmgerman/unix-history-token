begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- InputReaderEZ.h -----------------------------------------*- C++ -*-===//
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
name|liblldb_InputReaderEZ_h_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_InputReaderEZ_h_
end_define

begin_include
include|#
directive|include
file|"lldb/Core/InputReader.h"
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|InputReaderEZ
range|:
name|public
name|InputReader
block|{
name|private
operator|:
specifier|static
name|size_t
name|Callback_Impl
argument_list|(
argument|void *baton
argument_list|,
argument|InputReader&reader
argument_list|,
argument|lldb::InputReaderAction notification
argument_list|,
argument|const char *bytes
argument_list|,
argument|size_t bytes_len
argument_list|)
block|;
name|public
operator|:
name|InputReaderEZ
argument_list|(
name|Debugger
operator|&
name|debugger
argument_list|)
operator|:
name|InputReader
argument_list|(
argument|debugger
argument_list|)
block|{}
name|virtual
operator|~
name|InputReaderEZ
argument_list|()
block|;
name|using
name|InputReader
operator|::
name|Initialize
block|;
name|virtual
name|Error
name|Initialize
argument_list|(
argument|void* baton
argument_list|,
argument|lldb::InputReaderGranularity token_size = lldb::eInputReaderGranularityLine
argument_list|,
argument|const char* end_token =
literal|"DONE"
argument_list|,
argument|const char *prompt =
literal|"> "
argument_list|,
argument|bool echo = true
argument_list|)
block|;
name|virtual
name|Error
name|Initialize
argument_list|(
name|InitializationParameters
operator|&
name|params
argument_list|)
block|;
name|virtual
name|void
name|ActivateHandler
argument_list|(
argument|HandlerData&
argument_list|)
block|{}
name|virtual
name|void
name|DeactivateHandler
argument_list|(
argument|HandlerData&
argument_list|)
block|{}
name|virtual
name|void
name|ReactivateHandler
argument_list|(
argument|HandlerData&
argument_list|)
block|{}
name|virtual
name|void
name|AsynchronousOutputWrittenHandler
argument_list|(
argument|HandlerData&
argument_list|)
block|{}
name|virtual
name|void
name|GotTokenHandler
argument_list|(
argument|HandlerData&
argument_list|)
block|{}
name|virtual
name|void
name|InterruptHandler
argument_list|(
argument|HandlerData&
argument_list|)
block|{}
name|virtual
name|void
name|EOFHandler
argument_list|(
argument|HandlerData&
argument_list|)
block|{}
name|virtual
name|void
name|DoneHandler
argument_list|(
argument|HandlerData&
argument_list|)
block|{}
name|virtual
name|bool
name|GetSaveUserInput
argument_list|()
block|{
return|return
name|m_save_user_input
return|;
block|}
name|protected
operator|:
name|friend
name|class
name|Debugger
block|;
name|private
operator|:
name|DISALLOW_COPY_AND_ASSIGN
argument_list|(
name|InputReaderEZ
argument_list|)
block|;  }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace lldb_private
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// #ifndef liblldb_InputReaderEZ_h_
end_comment

end_unit

