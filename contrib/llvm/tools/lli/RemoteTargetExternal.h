begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===----- RemoteTargetExternal.h - LLVM out-of-process JIT execution -----===//
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
comment|// Definition of the RemoteTargetExternal class which executes JITed code in a
end_comment

begin_comment
comment|// separate process from where it was built.
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
name|LLVM_TOOLS_LLI_REMOTETARGETEXTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLI_REMOTETARGETEXTERNAL_H
end_define

begin_include
include|#
directive|include
file|"RPCChannel.h"
end_include

begin_include
include|#
directive|include
file|"RemoteTarget.h"
end_include

begin_include
include|#
directive|include
file|"RemoteTargetMessage.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Config/config.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/DataTypes.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Memory.h"
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|class
name|RemoteTargetExternal
range|:
name|public
name|RemoteTarget
block|{
name|RPCChannel
name|RPC
block|;
name|bool
name|WriteBytes
argument_list|(
argument|const void *Data
argument_list|,
argument|size_t Size
argument_list|)
block|{
return|return
name|RPC
operator|.
name|WriteBytes
argument_list|(
name|Data
argument_list|,
name|Size
argument_list|)
return|;
block|}
name|bool
name|ReadBytes
argument_list|(
argument|void *Data
argument_list|,
argument|size_t Size
argument_list|)
block|{
return|return
name|RPC
operator|.
name|ReadBytes
argument_list|(
name|Data
argument_list|,
name|Size
argument_list|)
return|;
block|}
name|public
operator|:
comment|/// Allocate space in the remote target address space.
comment|///
comment|/// @param      Size      Amount of space, in bytes, to allocate.
comment|/// @param      Alignment Required minimum alignment for allocated space.
comment|/// @param[out] Address   Remote address of the allocated memory.
comment|///
comment|/// @returns True on success. On failure, ErrorMsg is updated with
comment|///          descriptive text of the encountered error.
name|bool
name|allocateSpace
argument_list|(
argument|size_t Size
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|uint64_t&Address
argument_list|)
name|override
block|;
comment|/// Load data into the target address space.
comment|///
comment|/// @param      Address   Destination address in the target process.
comment|/// @param      Data      Source address in the host process.
comment|/// @param      Size      Number of bytes to copy.
comment|///
comment|/// @returns True on success. On failure, ErrorMsg is updated with
comment|///          descriptive text of the encountered error.
name|bool
name|loadData
argument_list|(
argument|uint64_t Address
argument_list|,
argument|const void *Data
argument_list|,
argument|size_t Size
argument_list|)
name|override
block|;
comment|/// Load code into the target address space and prepare it for execution.
comment|///
comment|/// @param      Address   Destination address in the target process.
comment|/// @param      Data      Source address in the host process.
comment|/// @param      Size      Number of bytes to copy.
comment|///
comment|/// @returns True on success. On failure, ErrorMsg is updated with
comment|///          descriptive text of the encountered error.
name|bool
name|loadCode
argument_list|(
argument|uint64_t Address
argument_list|,
argument|const void *Data
argument_list|,
argument|size_t Size
argument_list|)
name|override
block|;
comment|/// Execute code in the target process. The called function is required
comment|/// to be of signature int "(*)(void)".
comment|///
comment|/// @param      Address   Address of the loaded function in the target
comment|///                       process.
comment|/// @param[out] RetVal    The integer return value of the called function.
comment|///
comment|/// @returns True on success. On failure, ErrorMsg is updated with
comment|///          descriptive text of the encountered error.
name|bool
name|executeCode
argument_list|(
argument|uint64_t Address
argument_list|,
argument|int&RetVal
argument_list|)
name|override
block|;
comment|/// Minimum alignment for memory permissions. Used to separate code and
comment|/// data regions to make sure data doesn't get marked as code or vice
comment|/// versa.
comment|///
comment|/// @returns Page alignment return value. Default of 4k.
name|unsigned
name|getPageAlignment
argument_list|()
name|override
block|{
return|return
literal|4096
return|;
block|}
name|bool
name|create
argument_list|()
name|override
block|{
name|RPC
operator|.
name|ChildName
operator|=
name|ChildName
block|;
if|if
condition|(
operator|!
name|RPC
operator|.
name|createServer
argument_list|()
condition|)
return|return
name|true
return|;
comment|// We must get Ack from the client (blocking read)
if|if
condition|(
operator|!
name|Receive
argument_list|(
name|LLI_ChildActive
argument_list|)
condition|)
block|{
name|ErrorMsg
operator|+=
literal|", (RPCChannel::create) - Stopping process!"
expr_stmt|;
name|stop
argument_list|()
expr_stmt|;
return|return
name|false
return|;
block|}
return|return
name|true
return|;
block|}
comment|/// Terminate the remote process.
name|void
name|stop
argument_list|()
name|override
expr_stmt|;
name|RemoteTargetExternal
argument_list|(
name|std
operator|::
name|string
operator|&
name|Name
argument_list|)
operator|:
name|RemoteTarget
argument_list|()
operator|,
name|ChildName
argument_list|(
argument|Name
argument_list|)
block|{}
name|virtual
operator|~
name|RemoteTargetExternal
argument_list|()
block|{}
name|private
operator|:
name|std
operator|::
name|string
name|ChildName
expr_stmt|;
name|bool
name|SendAllocateSpace
parameter_list|(
name|uint32_t
name|Alignment
parameter_list|,
name|uint32_t
name|Size
parameter_list|)
function_decl|;
name|bool
name|SendLoadSection
parameter_list|(
name|uint64_t
name|Addr
parameter_list|,
specifier|const
name|void
modifier|*
name|Data
parameter_list|,
name|uint32_t
name|Size
parameter_list|,
name|bool
name|IsCode
parameter_list|)
function_decl|;
name|bool
name|SendExecute
parameter_list|(
name|uint64_t
name|Addr
parameter_list|)
function_decl|;
name|bool
name|SendTerminate
parameter_list|()
function_decl|;
comment|// High-level wrappers for receiving data
name|bool
name|Receive
parameter_list|(
name|LLIMessageType
name|Msg
parameter_list|)
function_decl|;
name|bool
name|Receive
parameter_list|(
name|LLIMessageType
name|Msg
parameter_list|,
name|int32_t
modifier|&
name|Data
parameter_list|)
function_decl|;
name|bool
name|Receive
parameter_list|(
name|LLIMessageType
name|Msg
parameter_list|,
name|uint64_t
modifier|&
name|Data
parameter_list|)
function_decl|;
comment|// Lower level target-independent read/write to deal with errors
name|bool
name|ReceiveHeader
parameter_list|(
name|LLIMessageType
name|Msg
parameter_list|)
function_decl|;
name|bool
name|ReceivePayload
parameter_list|()
function_decl|;
name|bool
name|SendHeader
parameter_list|(
name|LLIMessageType
name|Msg
parameter_list|)
function_decl|;
name|bool
name|SendPayload
parameter_list|()
function_decl|;
comment|// Functions to append/retrieve data from the payload
name|SmallVector
operator|<
specifier|const
name|void
operator|*
operator|,
literal|2
operator|>
name|SendData
expr_stmt|;
name|SmallVector
operator|<
name|void
operator|*
operator|,
literal|1
operator|>
name|ReceiveData
expr_stmt|;
comment|// Future proof
name|SmallVector
operator|<
name|int
operator|,
literal|2
operator|>
name|Sizes
expr_stmt|;
name|void
name|AppendWrite
parameter_list|(
specifier|const
name|void
modifier|*
name|Data
parameter_list|,
name|uint32_t
name|Size
parameter_list|)
function_decl|;
name|void
name|AppendRead
parameter_list|(
name|void
modifier|*
name|Data
parameter_list|,
name|uint32_t
name|Size
parameter_list|)
function_decl|;
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

begin_comment
unit|}
comment|// end namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

