begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- RemoteTarget.h - LLVM Remote process JIT execution ----------------===//
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
comment|// Definition of the RemoteTarget class which executes JITed code in a
end_comment

begin_comment
comment|// separate address range from where it was built.
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
name|REMOTEPROCESS_H
end_ifndef

begin_define
define|#
directive|define
name|REMOTEPROCESS_H
end_define

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
name|RemoteTarget
block|{
name|std
operator|::
name|string
name|ErrorMsg
expr_stmt|;
name|bool
name|IsRunning
decl_stmt|;
name|SmallVector
operator|<
name|sys
operator|::
name|MemoryBlock
operator|,
literal|16
operator|>
name|Allocations
expr_stmt|;
name|public
label|:
name|StringRef
name|getErrorMsg
argument_list|()
specifier|const
block|{
return|return
name|ErrorMsg
return|;
block|}
comment|/// Allocate space in the remote target address space.
comment|///
comment|/// @param      Size      Amount of space, in bytes, to allocate.
comment|/// @param      Alignment Required minimum alignment for allocated space.
comment|/// @param[out] Address   Remote address of the allocated memory.
comment|///
comment|/// @returns False on success. On failure, ErrorMsg is updated with
comment|///          descriptive text of the encountered error.
name|virtual
name|bool
name|allocateSpace
parameter_list|(
name|size_t
name|Size
parameter_list|,
name|unsigned
name|Alignment
parameter_list|,
name|uint64_t
modifier|&
name|Address
parameter_list|)
function_decl|;
comment|/// Load data into the target address space.
comment|///
comment|/// @param      Address   Destination address in the target process.
comment|/// @param      Data      Source address in the host process.
comment|/// @param      Size      Number of bytes to copy.
comment|///
comment|/// @returns False on success. On failure, ErrorMsg is updated with
comment|///          descriptive text of the encountered error.
name|virtual
name|bool
name|loadData
parameter_list|(
name|uint64_t
name|Address
parameter_list|,
specifier|const
name|void
modifier|*
name|Data
parameter_list|,
name|size_t
name|Size
parameter_list|)
function_decl|;
comment|/// Load code into the target address space and prepare it for execution.
comment|///
comment|/// @param      Address   Destination address in the target process.
comment|/// @param      Data      Source address in the host process.
comment|/// @param      Size      Number of bytes to copy.
comment|///
comment|/// @returns False on success. On failure, ErrorMsg is updated with
comment|///          descriptive text of the encountered error.
name|virtual
name|bool
name|loadCode
parameter_list|(
name|uint64_t
name|Address
parameter_list|,
specifier|const
name|void
modifier|*
name|Data
parameter_list|,
name|size_t
name|Size
parameter_list|)
function_decl|;
comment|/// Execute code in the target process. The called function is required
comment|/// to be of signature int "(*)(void)".
comment|///
comment|/// @param      Address   Address of the loaded function in the target
comment|///                       process.
comment|/// @param[out] RetVal    The integer return value of the called function.
comment|///
comment|/// @returns False on success. On failure, ErrorMsg is updated with
comment|///          descriptive text of the encountered error.
name|virtual
name|bool
name|executeCode
parameter_list|(
name|uint64_t
name|Address
parameter_list|,
name|int
modifier|&
name|RetVal
parameter_list|)
function_decl|;
comment|/// Minimum alignment for memory permissions. Used to seperate code and
comment|/// data regions to make sure data doesn't get marked as code or vice
comment|/// versa.
comment|///
comment|/// @returns Page alignment return value. Default of 4k.
name|virtual
name|unsigned
name|getPageAlignment
parameter_list|()
block|{
return|return
literal|4096
return|;
block|}
comment|/// Start the remote process.
name|virtual
name|void
name|create
parameter_list|()
function_decl|;
comment|/// Terminate the remote process.
name|virtual
name|void
name|stop
parameter_list|()
function_decl|;
name|RemoteTarget
argument_list|()
operator|:
name|ErrorMsg
argument_list|(
literal|""
argument_list|)
operator|,
name|IsRunning
argument_list|(
argument|false
argument_list|)
block|{}
name|virtual
operator|~
name|RemoteTarget
argument_list|()
block|{
if|if
condition|(
name|IsRunning
condition|)
name|stop
argument_list|()
expr_stmt|;
block|}
comment|// Create an instance of the system-specific remote target class.
specifier|static
name|RemoteTarget
modifier|*
name|createRemoteTarget
parameter_list|()
function_decl|;
specifier|static
name|RemoteTarget
modifier|*
name|createExternalRemoteTarget
argument_list|(
name|std
operator|::
name|string
operator|&
name|ChildName
argument_list|)
decl_stmt|;
specifier|static
name|bool
name|hostSupportsExternalRemoteTarget
parameter_list|()
function_decl|;
name|private
label|:
comment|// Main processing function for the remote target process. Command messages
comment|// are received on file descriptor CmdFD and responses come back on OutFD.
specifier|static
name|void
name|doRemoteTargeting
parameter_list|(
name|int
name|CmdFD
parameter_list|,
name|int
name|OutFD
parameter_list|)
function_decl|;
block|}
empty_stmt|;
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

