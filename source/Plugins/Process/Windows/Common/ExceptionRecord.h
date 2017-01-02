begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ExceptionRecord.h ---------------------------------------*- C++ -*-===//
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
name|liblldb_Plugins_Process_Windows_ExceptionRecord_H_
end_ifndef

begin_define
define|#
directive|define
name|liblldb_Plugins_Process_Windows_ExceptionRecord_H_
end_define

begin_include
include|#
directive|include
file|"lldb/Host/windows/windows.h"
end_include

begin_include
include|#
directive|include
file|"lldb/lldb-forward.h"
end_include

begin_include
include|#
directive|include
file|<dbghelp.h>
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<vector>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
comment|//----------------------------------------------------------------------
comment|// ExceptionRecord
comment|//
comment|// ExceptionRecord defines an interface which allows implementors to receive
comment|// notification of events that happen in a debugged process.
comment|//----------------------------------------------------------------------
name|class
name|ExceptionRecord
block|{
name|public
label|:
name|ExceptionRecord
argument_list|(
argument|const EXCEPTION_RECORD&record
argument_list|,
argument|lldb::tid_t thread_id
argument_list|)
block|{
name|m_code
operator|=
name|record
operator|.
name|ExceptionCode
expr_stmt|;
name|m_continuable
operator|=
operator|(
name|record
operator|.
name|ExceptionFlags
operator|==
literal|0
operator|)
expr_stmt|;
if|if
condition|(
name|record
operator|.
name|ExceptionRecord
condition|)
name|m_next_exception
operator|.
name|reset
argument_list|(
argument|new ExceptionRecord(*record.ExceptionRecord, thread_id)
argument_list|)
expr_stmt|;
name|m_exception_addr
operator|=
name|reinterpret_cast
operator|<
name|lldb
operator|::
name|addr_t
operator|>
operator|(
name|record
operator|.
name|ExceptionAddress
operator|)
expr_stmt|;
name|m_thread_id
operator|=
name|thread_id
expr_stmt|;
name|m_arguments
operator|.
name|assign
argument_list|(
name|record
operator|.
name|ExceptionInformation
argument_list|,
name|record
operator|.
name|ExceptionInformation
operator|+
name|record
operator|.
name|NumberParameters
argument_list|)
expr_stmt|;
block|}
comment|// MINIDUMP_EXCEPTIONs are almost identical to EXCEPTION_RECORDs.
name|ExceptionRecord
argument_list|(
argument|const MINIDUMP_EXCEPTION&record
argument_list|,
argument|lldb::tid_t thread_id
argument_list|)
block|:
name|m_code
argument_list|(
name|record
operator|.
name|ExceptionCode
argument_list|)
operator|,
name|m_continuable
argument_list|(
name|record
operator|.
name|ExceptionFlags
operator|==
literal|0
argument_list|)
operator|,
name|m_next_exception
argument_list|(
name|nullptr
argument_list|)
operator|,
name|m_exception_addr
argument_list|(
name|static_cast
operator|<
name|lldb
operator|::
name|addr_t
operator|>
operator|(
name|record
operator|.
name|ExceptionAddress
operator|)
argument_list|)
operator|,
name|m_thread_id
argument_list|(
name|thread_id
argument_list|)
operator|,
name|m_arguments
argument_list|(
argument|record.ExceptionInformation
argument_list|,
argument|record.ExceptionInformation + record.NumberParameters
argument_list|)
block|{
comment|// Set up link to nested exception.
if|if
condition|(
name|record
operator|.
name|ExceptionRecord
condition|)
block|{
name|m_next_exception
operator|.
name|reset
argument_list|(
argument|new ExceptionRecord(           *reinterpret_cast<const MINIDUMP_EXCEPTION *>(record.ExceptionRecord),           thread_id)
argument_list|)
expr_stmt|;
block|}
block|}
name|virtual
operator|~
name|ExceptionRecord
argument_list|()
block|{}
name|DWORD
name|GetExceptionCode
argument_list|()
specifier|const
block|{
return|return
name|m_code
return|;
block|}
name|bool
name|IsContinuable
argument_list|()
specifier|const
block|{
return|return
name|m_continuable
return|;
block|}
specifier|const
name|ExceptionRecord
operator|*
name|GetNextException
argument_list|()
specifier|const
block|{
return|return
name|m_next_exception
operator|.
name|get
argument_list|()
return|;
block|}
name|lldb
operator|::
name|addr_t
name|GetExceptionAddress
argument_list|()
specifier|const
block|{
return|return
name|m_exception_addr
return|;
block|}
name|lldb
operator|::
name|tid_t
name|GetThreadID
argument_list|()
specifier|const
block|{
return|return
name|m_thread_id
return|;
block|}
name|private
label|:
name|DWORD
name|m_code
decl_stmt|;
name|bool
name|m_continuable
decl_stmt|;
name|std
operator|::
name|shared_ptr
operator|<
name|ExceptionRecord
operator|>
name|m_next_exception
expr_stmt|;
name|lldb
operator|::
name|addr_t
name|m_exception_addr
expr_stmt|;
name|lldb
operator|::
name|tid_t
name|m_thread_id
expr_stmt|;
name|std
operator|::
name|vector
operator|<
name|ULONG_PTR
operator|>
name|m_arguments
expr_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

