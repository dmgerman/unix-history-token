begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- RawError.h - Error extensions for raw PDB implementation -*- C++ -*-===//
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
name|LLVM_DEBUGINFO_PDB_RAW_RAWERROR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_DEBUGINFO_PDB_RAW_RAWERROR_H
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
name|pdb
block|{
name|enum
name|class
name|raw_error_code
block|{
name|unspecified
operator|=
literal|1
operator|,
name|feature_unsupported
operator|,
name|invalid_format
operator|,
name|corrupt_file
operator|,
name|insufficient_buffer
operator|,
name|no_stream
operator|,
name|index_out_of_bounds
operator|,
name|invalid_block_address
operator|,
name|duplicate_entry
operator|,
name|no_entry
operator|,
name|not_writable
operator|,
name|stream_too_long
operator|,
name|invalid_tpi_hash
operator|,
block|}
empty_stmt|;
comment|/// Base class for errors originating when parsing raw PDB files
name|class
name|RawError
range|:
name|public
name|ErrorInfo
operator|<
name|RawError
operator|>
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|RawError
argument_list|(
argument|raw_error_code C
argument_list|)
block|;
name|RawError
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Context
argument_list|)
block|;
name|RawError
argument_list|(
argument|raw_error_code C
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
name|raw_error_code
name|Code
block|; }
decl_stmt|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

