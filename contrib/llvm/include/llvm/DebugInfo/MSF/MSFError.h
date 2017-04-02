begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- MSFError.h - Error extensions for MSF Files --------------*- C++ -*-===//
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
name|LLVM_DEBUGINFO_MSF_MSFERROR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_MSF_MSFERROR_H
end_define

begin_include
include|#
directive|include
file|"llvm/Support/Error.h"
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
name|namespace
name|msf
block|{
name|enum
name|class
name|msf_error_code
block|{
name|unspecified
operator|=
literal|1
operator|,
name|insufficient_buffer
operator|,
name|not_writable
operator|,
name|no_stream
operator|,
name|invalid_format
operator|,
name|block_in_use
block|}
empty_stmt|;
comment|/// Base class for errors originating when parsing raw PDB files
name|class
name|MSFError
range|:
name|public
name|ErrorInfo
operator|<
name|MSFError
operator|>
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|MSFError
argument_list|(
argument|msf_error_code C
argument_list|)
block|;
name|MSFError
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Context
argument_list|)
block|;
name|MSFError
argument_list|(
argument|msf_error_code C
argument_list|,
argument|const std::string&Context
argument_list|)
block|;
name|void
name|log
argument_list|(
argument|raw_ostream&OS
argument_list|)
specifier|const
name|override
block|;
specifier|const
name|std
operator|::
name|string
operator|&
name|getErrorMessage
argument_list|()
specifier|const
block|;
name|std
operator|::
name|error_code
name|convertToErrorCode
argument_list|()
specifier|const
name|override
block|;
name|private
operator|:
name|std
operator|::
name|string
name|ErrMsg
block|;
name|msf_error_code
name|Code
block|; }
decl_stmt|;
block|}
comment|// namespace msf
block|}
end_decl_stmt

begin_comment
comment|// namespace llvm
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_DEBUGINFO_MSF_MSFERROR_H
end_comment

end_unit

