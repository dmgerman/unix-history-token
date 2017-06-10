begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- TestClient.h --------------------------------------------*- C++ -*-===//
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

begin_include
include|#
directive|include
file|"MessageObjects.h"
end_include

begin_include
include|#
directive|include
file|"Plugins/Process/gdb-remote/GDBRemoteCommunicationClient.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Core/ArchSpec.h"
end_include

begin_include
include|#
directive|include
file|"lldb/Target/ProcessLaunchInfo.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Optional.h"
end_include

begin_include
include|#
directive|include
file|<memory>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llgs_tests
block|{
comment|// TODO: Make the test client an abstract base class, with different children
comment|// for different types of connections: llgs v. debugserver
name|class
name|TestClient
range|:
name|public
name|lldb_private
operator|::
name|process_gdb_remote
operator|::
name|GDBRemoteCommunicationClient
block|{
name|public
operator|:
specifier|static
name|void
name|Initialize
argument_list|()
block|;
name|TestClient
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|test_name
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|test_case_name
argument_list|)
block|;
name|virtual
operator|~
name|TestClient
argument_list|()
block|;
name|LLVM_NODISCARD
name|bool
name|StartDebugger
argument_list|()
block|;
name|LLVM_NODISCARD
name|bool
name|StopDebugger
argument_list|()
block|;
name|LLVM_NODISCARD
name|bool
name|SetInferior
argument_list|(
name|llvm
operator|::
name|ArrayRef
operator|<
name|std
operator|::
name|string
operator|>
name|inferior_args
argument_list|)
block|;
name|LLVM_NODISCARD
name|bool
name|ListThreadsInStopReply
argument_list|()
block|;
name|LLVM_NODISCARD
name|bool
name|SetBreakpoint
argument_list|(
argument|unsigned long address
argument_list|)
block|;
name|LLVM_NODISCARD
name|bool
name|ContinueAll
argument_list|()
block|;
name|LLVM_NODISCARD
name|bool
name|ContinueThread
argument_list|(
argument|unsigned long thread_id
argument_list|)
block|;
specifier|const
name|ProcessInfo
operator|&
name|GetProcessInfo
argument_list|()
block|;
name|llvm
operator|::
name|Optional
operator|<
name|JThreadsInfo
operator|>
name|GetJThreadsInfo
argument_list|()
block|;
specifier|const
name|StopReply
operator|&
name|GetLatestStopReply
argument_list|()
block|;
name|LLVM_NODISCARD
name|bool
name|SendMessage
argument_list|(
argument|llvm::StringRef message
argument_list|)
block|;
name|LLVM_NODISCARD
name|bool
name|SendMessage
argument_list|(
argument|llvm::StringRef message
argument_list|,
argument|std::string&response_string
argument_list|)
block|;
name|LLVM_NODISCARD
name|bool
name|SendMessage
argument_list|(
argument|llvm::StringRef message
argument_list|,
argument|std::string&response_string
argument_list|,
argument|PacketResult expected_result
argument_list|)
block|;
name|unsigned
name|int
name|GetPcRegisterId
argument_list|()
block|;
name|private
operator|:
name|LLVM_NODISCARD
name|bool
name|Continue
argument_list|(
argument|llvm::StringRef message
argument_list|)
block|;
name|LLVM_NODISCARD
name|bool
name|GenerateConnectionAddress
argument_list|(
name|std
operator|::
name|string
operator|&
name|address
argument_list|)
block|;
name|std
operator|::
name|string
name|GenerateLogFileName
argument_list|(
argument|const lldb_private::ArchSpec&arch
argument_list|)
specifier|const
block|;
name|std
operator|::
name|string
name|FormatFailedResult
argument_list|(
argument|const std::string&message
argument_list|,
argument|lldb_private::process_gdb_remote::GDBRemoteCommunication::PacketResult           result
argument_list|)
block|;
name|llvm
operator|::
name|Optional
operator|<
name|ProcessInfo
operator|>
name|m_process_info
block|;
name|llvm
operator|::
name|Optional
operator|<
name|StopReply
operator|>
name|m_stop_reply
block|;
name|lldb_private
operator|::
name|ProcessLaunchInfo
name|m_server_process_info
block|;
name|std
operator|::
name|string
name|m_test_name
block|;
name|std
operator|::
name|string
name|m_test_case_name
block|;
name|unsigned
name|int
name|m_pc_register
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_comment
comment|// namespace llgs_tests
end_comment

end_unit

