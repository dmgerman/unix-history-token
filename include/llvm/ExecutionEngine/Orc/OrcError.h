begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===------ OrcError.h - Reject symbol lookup requests ------*- C++ -*-===//
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
comment|//   Define an error category, error codes, and helper utilities for Orc.
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
name|LLVM_EXECUTIONENGINE_ORC_ORCERROR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_EXECUTIONENGINE_ORC_ORCERROR_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
end_include

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_decl_stmt
name|namespace
name|llvm
block|{
name|namespace
name|orc
block|{
name|enum
name|class
name|OrcErrorCode
range|:
name|int
block|{
comment|// RPC Errors
name|RemoteAllocatorDoesNotExist
operator|=
literal|1
block|,
name|RemoteAllocatorIdAlreadyInUse
block|,
name|RemoteMProtectAddrUnrecognized
block|,
name|RemoteIndirectStubsOwnerDoesNotExist
block|,
name|RemoteIndirectStubsOwnerIdAlreadyInUse
block|,
name|RPCConnectionClosed
block|,
name|RPCCouldNotNegotiateFunction
block|,
name|RPCResponseAbandoned
block|,
name|UnexpectedRPCCall
block|,
name|UnexpectedRPCResponse
block|,
name|UnknownErrorCodeFromRemote
block|}
decl_stmt|;
name|std
operator|::
name|error_code
name|orcError
argument_list|(
argument|OrcErrorCode ErrCode
argument_list|)
expr_stmt|;
block|}
comment|// End namespace orc.
block|}
end_decl_stmt

begin_comment
comment|// End namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_EXECUTIONENGINE_ORC_ORCERROR_H
end_comment

end_unit

