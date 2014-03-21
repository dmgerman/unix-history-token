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
name|LLI_REMOTETARGETEXTERNAL_H
end_ifndef

begin_define
define|#
directive|define
name|LLI_REMOTETARGETEXTERNAL_H
end_define

begin_include
include|#
directive|include
file|"llvm/Config/config.h"
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
name|public
operator|:
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
argument_list|(
argument|size_t Size
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|uint64_t&Address
argument_list|)
block|;
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
argument_list|(
argument|uint64_t Address
argument_list|,
argument|const void *Data
argument_list|,
argument|size_t Size
argument_list|)
block|;
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
argument_list|(
argument|uint64_t Address
argument_list|,
argument|const void *Data
argument_list|,
argument|size_t Size
argument_list|)
block|;
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
argument_list|(
argument|uint64_t Address
argument_list|,
argument|int&RetVal
argument_list|)
block|;
comment|/// Minimum alignment for memory permissions. Used to seperate code and
comment|/// data regions to make sure data doesn't get marked as code or vice
comment|/// versa.
comment|///
comment|/// @returns Page alignment return value. Default of 4k.
name|virtual
name|unsigned
name|getPageAlignment
argument_list|()
block|{
return|return
literal|4096
return|;
block|}
comment|/// Start the remote process.
name|virtual
name|void
name|create
argument_list|()
block|;
comment|/// Terminate the remote process.
name|virtual
name|void
name|stop
argument_list|()
block|;
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
block|,
name|ChildName
argument_list|(
argument|Name
argument_list|)
block|{}
name|virtual
operator|~
name|RemoteTargetExternal
argument_list|()
block|;
name|private
operator|:
name|std
operator|::
name|string
name|ChildName
block|;
comment|// This will get filled in as a point to an OS-specific structure.
name|void
operator|*
name|ConnectionData
block|;
name|void
name|SendAllocateSpace
argument_list|(
argument|uint32_t Alignment
argument_list|,
argument|uint32_t Size
argument_list|)
block|;
name|void
name|SendLoadSection
argument_list|(
argument|uint64_t Addr
argument_list|,
argument|const void *Data
argument_list|,
argument|uint32_t Size
argument_list|,
argument|bool IsCode
argument_list|)
block|;
name|void
name|SendExecute
argument_list|(
argument|uint64_t Addr
argument_list|)
block|;
name|void
name|SendTerminate
argument_list|()
block|;
name|void
name|Receive
argument_list|(
argument|LLIMessageType Msg
argument_list|)
block|;
name|void
name|Receive
argument_list|(
argument|LLIMessageType Msg
argument_list|,
argument|int&Data
argument_list|)
block|;
name|void
name|Receive
argument_list|(
argument|LLIMessageType Msg
argument_list|,
argument|uint64_t&Data
argument_list|)
block|;
name|int
name|WriteBytes
argument_list|(
argument|const void *Data
argument_list|,
argument|size_t Size
argument_list|)
block|;
name|int
name|ReadBytes
argument_list|(
argument|void *Data
argument_list|,
argument|size_t Size
argument_list|)
block|;
name|void
name|Wait
argument_list|()
block|; }
decl_stmt|;
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
comment|// LLI_REMOTETARGETEXTERNAL_H
end_comment

end_unit

