begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- RemoteTargetMessage.h - LLI out-of-process message protocol -----===//
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

begin_comment
comment|//
end_comment

begin_comment
comment|// Definition of the LLIMessageType enum which is used for communication with a
end_comment

begin_comment
comment|// child process for remote execution.
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
name|LLI_REMOTETARGETMESSAGE_H
end_ifndef

begin_define
define|#
directive|define
name|LLI_REMOTETARGETMESSAGE_H
end_define

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// LLI messages from parent-to-child or vice versa follow an exceedingly simple
comment|// protocol where the first four bytes represent the message type, the next
comment|// four bytes represent the size of data for the command and following bytes
comment|// represent the actual data.
comment|//
comment|// The protocol is not intended to be robust, secure or fault-tolerant.  It is
comment|// only here for testing purposes and is therefore intended to be the simplest
comment|// implementation that will work.  It is assumed that the parent and child
comment|// share characteristics like endianness.
enum|enum
name|LLIMessageType
block|{
name|LLI_Error
init|=
operator|-
literal|1
block|,
name|LLI_ChildActive
init|=
literal|0
block|,
comment|// Data = not used
name|LLI_AllocateSpace
block|,
comment|// Data = struct { uint_32t Align, uint_32t Size }
name|LLI_AllocationResult
block|,
comment|// Data = uint64_t AllocAddress (in Child memory space)
name|LLI_LoadCodeSection
block|,
comment|// Data = uint32_t Addr, followed by section contests
name|LLI_LoadDataSection
block|,
comment|// Data = uint32_t Addr, followed by section contents
name|LLI_LoadComplete
block|,
comment|// Data = not used
name|LLI_Execute
block|,
comment|// Data = Address of function to execute
name|LLI_ExecutionResult
block|,
comment|// Data = uint64_t Result
name|LLI_Terminate
comment|// Data = not used
block|}
enum|;
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

