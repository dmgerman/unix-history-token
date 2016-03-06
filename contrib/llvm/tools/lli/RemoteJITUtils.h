begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- RemoteJITUtils.h - Utilities for remote-JITing with LLI -*- C++ -*-===//
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
comment|// Utilities for remote-JITing with LLI.
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
name|LLVM_TOOLS_LLI_REMOTEJITUTILS_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_TOOLS_LLI_REMOTEJITUTILS_H
end_define

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/Orc/RPCChannel.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ExecutionEngine/RTDyldMemoryManager.h"
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_MSC_VER
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__MINGW32__
argument_list|)
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// RPC channel that reads from and writes from file descriptors.
end_comment

begin_decl_stmt
name|class
name|FDRPCChannel
range|:
name|public
name|llvm
operator|::
name|orc
operator|::
name|remote
operator|::
name|RPCChannel
block|{
name|public
operator|:
name|FDRPCChannel
argument_list|(
argument|int InFD
argument_list|,
argument|int OutFD
argument_list|)
operator|:
name|InFD
argument_list|(
name|InFD
argument_list|)
block|,
name|OutFD
argument_list|(
argument|OutFD
argument_list|)
block|{}
name|std
operator|::
name|error_code
name|readBytes
argument_list|(
argument|char *Dst
argument_list|,
argument|unsigned Size
argument_list|)
name|override
block|{
name|assert
argument_list|(
name|Dst
operator|&&
literal|"Attempt to read into null."
argument_list|)
block|;
name|ssize_t
name|ReadResult
operator|=
operator|::
name|read
argument_list|(
name|InFD
argument_list|,
name|Dst
argument_list|,
name|Size
argument_list|)
block|;
if|if
condition|(
name|ReadResult
operator|!=
operator|(
name|ssize_t
operator|)
name|Size
condition|)
return|return
name|std
operator|::
name|error_code
argument_list|(
name|errno
argument_list|,
name|std
operator|::
name|generic_category
argument_list|()
argument_list|)
return|;
return|return
name|std
operator|::
name|error_code
argument_list|()
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|std
operator|::
name|error_code
name|appendBytes
argument_list|(
argument|const char *Src
argument_list|,
argument|unsigned Size
argument_list|)
name|override
block|{
name|assert
argument_list|(
name|Src
operator|&&
literal|"Attempt to append from null."
argument_list|)
block|;
name|ssize_t
name|WriteResult
operator|=
operator|::
name|write
argument_list|(
name|OutFD
argument_list|,
name|Src
argument_list|,
name|Size
argument_list|)
block|;
if|if
condition|(
name|WriteResult
operator|!=
operator|(
name|ssize_t
operator|)
name|Size
condition|)
name|std
operator|::
name|error_code
argument_list|(
name|errno
argument_list|,
name|std
operator|::
name|generic_category
argument_list|()
argument_list|)
expr_stmt|;
end_expr_stmt

begin_return
return|return
name|std
operator|::
name|error_code
argument_list|()
return|;
end_return

begin_expr_stmt
unit|}    std
operator|::
name|error_code
name|send
argument_list|()
name|override
block|{
return|return
name|std
operator|::
name|error_code
argument_list|()
return|;
block|}
end_expr_stmt

begin_label
name|private
label|:
end_label

begin_decl_stmt
name|int
name|InFD
decl_stmt|,
name|OutFD
decl_stmt|;
end_decl_stmt

begin_comment
unit|};
comment|// launch the remote process (see lli.cpp) and return a channel to it.
end_comment

begin_expr_stmt
name|std
operator|::
name|unique_ptr
operator|<
name|FDRPCChannel
operator|>
name|launchRemote
argument_list|()
expr_stmt|;
end_expr_stmt

begin_decl_stmt
name|namespace
name|llvm
block|{
comment|// ForwardingMM - Adapter to connect MCJIT to Orc's Remote memory manager.
name|class
name|ForwardingMemoryManager
range|:
name|public
name|llvm
operator|::
name|RTDyldMemoryManager
block|{
name|public
operator|:
name|void
name|setMemMgr
argument_list|(
argument|std::unique_ptr<RuntimeDyld::MemoryManager> MemMgr
argument_list|)
block|{
name|this
operator|->
name|MemMgr
operator|=
name|std
operator|::
name|move
argument_list|(
name|MemMgr
argument_list|)
block|;   }
name|void
name|setResolver
argument_list|(
argument|std::unique_ptr<RuntimeDyld::SymbolResolver> Resolver
argument_list|)
block|{
name|this
operator|->
name|Resolver
operator|=
name|std
operator|::
name|move
argument_list|(
name|Resolver
argument_list|)
block|;   }
name|uint8_t
operator|*
name|allocateCodeSection
argument_list|(
argument|uintptr_t Size
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned SectionID
argument_list|,
argument|StringRef SectionName
argument_list|)
name|override
block|{
return|return
name|MemMgr
operator|->
name|allocateCodeSection
argument_list|(
name|Size
argument_list|,
name|Alignment
argument_list|,
name|SectionID
argument_list|,
name|SectionName
argument_list|)
return|;
block|}
name|uint8_t
operator|*
name|allocateDataSection
argument_list|(
argument|uintptr_t Size
argument_list|,
argument|unsigned Alignment
argument_list|,
argument|unsigned SectionID
argument_list|,
argument|StringRef SectionName
argument_list|,
argument|bool IsReadOnly
argument_list|)
name|override
block|{
return|return
name|MemMgr
operator|->
name|allocateDataSection
argument_list|(
name|Size
argument_list|,
name|Alignment
argument_list|,
name|SectionID
argument_list|,
name|SectionName
argument_list|,
name|IsReadOnly
argument_list|)
return|;
block|}
name|void
name|reserveAllocationSpace
argument_list|(
argument|uintptr_t CodeSize
argument_list|,
argument|uint32_t CodeAlign
argument_list|,
argument|uintptr_t RODataSize
argument_list|,
argument|uint32_t RODataAlign
argument_list|,
argument|uintptr_t RWDataSize
argument_list|,
argument|uint32_t RWDataAlign
argument_list|)
name|override
block|{
name|MemMgr
operator|->
name|reserveAllocationSpace
argument_list|(
name|CodeSize
argument_list|,
name|CodeAlign
argument_list|,
name|RODataSize
argument_list|,
name|RODataAlign
argument_list|,
name|RWDataSize
argument_list|,
name|RWDataAlign
argument_list|)
block|;   }
name|bool
name|needsToReserveAllocationSpace
argument_list|()
name|override
block|{
return|return
name|MemMgr
operator|->
name|needsToReserveAllocationSpace
argument_list|()
return|;
block|}
name|void
name|registerEHFrames
argument_list|(
argument|uint8_t *Addr
argument_list|,
argument|uint64_t LoadAddr
argument_list|,
argument|size_t Size
argument_list|)
name|override
block|{
name|MemMgr
operator|->
name|registerEHFrames
argument_list|(
name|Addr
argument_list|,
name|LoadAddr
argument_list|,
name|Size
argument_list|)
block|;   }
name|void
name|deregisterEHFrames
argument_list|(
argument|uint8_t *Addr
argument_list|,
argument|uint64_t LoadAddr
argument_list|,
argument|size_t Size
argument_list|)
name|override
block|{
name|MemMgr
operator|->
name|deregisterEHFrames
argument_list|(
name|Addr
argument_list|,
name|LoadAddr
argument_list|,
name|Size
argument_list|)
block|;   }
name|bool
name|finalizeMemory
argument_list|(
argument|std::string *ErrMsg = nullptr
argument_list|)
name|override
block|{
return|return
name|MemMgr
operator|->
name|finalizeMemory
argument_list|(
name|ErrMsg
argument_list|)
return|;
block|}
name|void
name|notifyObjectLoaded
argument_list|(
argument|RuntimeDyld&RTDyld
argument_list|,
argument|const object::ObjectFile&Obj
argument_list|)
name|override
block|{
name|MemMgr
operator|->
name|notifyObjectLoaded
argument_list|(
name|RTDyld
argument_list|,
name|Obj
argument_list|)
block|;   }
comment|// Don't hide the sibling notifyObjectLoaded from RTDyldMemoryManager.
name|using
name|RTDyldMemoryManager
operator|::
name|notifyObjectLoaded
block|;
name|RuntimeDyld
operator|::
name|SymbolInfo
name|findSymbol
argument_list|(
argument|const std::string&Name
argument_list|)
name|override
block|{
return|return
name|Resolver
operator|->
name|findSymbol
argument_list|(
name|Name
argument_list|)
return|;
block|}
name|RuntimeDyld
operator|::
name|SymbolInfo
name|findSymbolInLogicalDylib
argument_list|(
argument|const std::string&Name
argument_list|)
name|override
block|{
return|return
name|Resolver
operator|->
name|findSymbolInLogicalDylib
argument_list|(
name|Name
argument_list|)
return|;
block|}
name|private
operator|:
name|std
operator|::
name|unique_ptr
operator|<
name|RuntimeDyld
operator|::
name|MemoryManager
operator|>
name|MemMgr
block|;
name|std
operator|::
name|unique_ptr
operator|<
name|RuntimeDyld
operator|::
name|SymbolResolver
operator|>
name|Resolver
block|; }
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

