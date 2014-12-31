begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---------- RPCChannel.h - LLVM out-of-process JIT execution ----------===//
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
name|LLI_RPCCHANNEL_H
end_ifndef

begin_define
define|#
directive|define
name|LLI_RPCCHANNEL_H
end_define

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
name|RPCChannel
block|{
name|public
label|:
name|std
operator|::
name|string
name|ChildName
expr_stmt|;
name|RPCChannel
argument_list|()
block|{}
operator|~
name|RPCChannel
argument_list|()
expr_stmt|;
comment|/// Start the remote process.
comment|///
comment|/// @returns True on success. On failure, ErrorMsg is updated with
comment|///          descriptive text of the encountered error.
name|bool
name|createServer
parameter_list|()
function_decl|;
name|bool
name|createClient
parameter_list|()
function_decl|;
comment|// This will get filled in as a point to an OS-specific structure.
name|void
modifier|*
name|ConnectionData
decl_stmt|;
name|bool
name|WriteBytes
parameter_list|(
specifier|const
name|void
modifier|*
name|Data
parameter_list|,
name|size_t
name|Size
parameter_list|)
function_decl|;
name|bool
name|ReadBytes
parameter_list|(
name|void
modifier|*
name|Data
parameter_list|,
name|size_t
name|Size
parameter_list|)
function_decl|;
name|void
name|Wait
parameter_list|()
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

begin_comment
comment|// LLI_RPCCHANNEL_H
end_comment

end_unit

