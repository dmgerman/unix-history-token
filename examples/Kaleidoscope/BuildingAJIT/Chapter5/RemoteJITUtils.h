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
file|"llvm/ExecutionEngine/Orc/RawByteChannel.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<cerrno>
end_include

begin_include
include|#
directive|include
file|<system_error>
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
name|final
range|:
name|public
name|llvm
operator|::
name|orc
operator|::
name|rpc
operator|::
name|RawByteChannel
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
name|llvm
operator|::
name|Error
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
name|Completed
operator|=
literal|0
block|;
while|while
condition|(
name|Completed
operator|<
name|static_cast
operator|<
name|ssize_t
operator|>
operator|(
name|Size
operator|)
condition|)
block|{
name|ssize_t
name|Read
init|=
operator|::
name|read
argument_list|(
name|InFD
argument_list|,
name|Dst
operator|+
name|Completed
argument_list|,
name|Size
operator|-
name|Completed
argument_list|)
decl_stmt|;
if|if
condition|(
name|Read
operator|<=
literal|0
condition|)
block|{
name|auto
name|ErrNo
init|=
name|errno
decl_stmt|;
if|if
condition|(
name|ErrNo
operator|==
name|EAGAIN
operator|||
name|ErrNo
operator|==
name|EINTR
condition|)
continue|continue;
else|else
return|return
name|llvm
operator|::
name|errorCodeToError
argument_list|(
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
argument_list|)
return|;
block|}
name|Completed
operator|+=
name|Read
expr_stmt|;
block|}
return|return
name|llvm
operator|::
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|llvm
operator|::
name|Error
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
name|Completed
operator|=
literal|0
block|;
while|while
condition|(
name|Completed
operator|<
name|static_cast
operator|<
name|ssize_t
operator|>
operator|(
name|Size
operator|)
condition|)
block|{
name|ssize_t
name|Written
init|=
operator|::
name|write
argument_list|(
name|OutFD
argument_list|,
name|Src
operator|+
name|Completed
argument_list|,
name|Size
operator|-
name|Completed
argument_list|)
decl_stmt|;
if|if
condition|(
name|Written
operator|<
literal|0
condition|)
block|{
name|auto
name|ErrNo
init|=
name|errno
decl_stmt|;
if|if
condition|(
name|ErrNo
operator|==
name|EAGAIN
operator|||
name|ErrNo
operator|==
name|EINTR
condition|)
continue|continue;
else|else
return|return
name|llvm
operator|::
name|errorCodeToError
argument_list|(
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
argument_list|)
return|;
block|}
name|Completed
operator|+=
name|Written
expr_stmt|;
block|}
return|return
name|llvm
operator|::
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|llvm
operator|::
name|Error
name|send
argument_list|()
name|override
block|{
return|return
name|llvm
operator|::
name|Error
operator|::
name|success
argument_list|()
return|;
block|}
name|private
operator|:
name|int
name|InFD
block|,
name|OutFD
block|; }
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_TOOLS_LLI_REMOTEJITUTILS_H
end_comment

end_unit

