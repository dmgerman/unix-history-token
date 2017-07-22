begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- BinaryStreamError.h - Error extensions for Binary Streams *- C++ -*-===//
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
name|LLVM_SUPPORT_BINARYSTREAMERROR_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_BINARYSTREAMERROR_H
end_define

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

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
name|enum
name|class
name|stream_error_code
block|{
name|unspecified
operator|,
name|stream_too_short
operator|,
name|invalid_array_size
operator|,
name|invalid_offset
operator|,
name|filesystem_error
block|}
empty_stmt|;
comment|/// Base class for errors originating when parsing raw PDB files
name|class
name|BinaryStreamError
range|:
name|public
name|ErrorInfo
operator|<
name|BinaryStreamError
operator|>
block|{
name|public
operator|:
specifier|static
name|char
name|ID
block|;
name|explicit
name|BinaryStreamError
argument_list|(
argument|stream_error_code C
argument_list|)
block|;
name|explicit
name|BinaryStreamError
argument_list|(
argument|StringRef Context
argument_list|)
block|;
name|BinaryStreamError
argument_list|(
argument|stream_error_code C
argument_list|,
argument|StringRef Context
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
name|std
operator|::
name|error_code
name|convertToErrorCode
argument_list|()
specifier|const
name|override
block|;
name|StringRef
name|getErrorMessage
argument_list|()
specifier|const
block|;
name|stream_error_code
name|getErrorCode
argument_list|()
specifier|const
block|{
return|return
name|Code
return|;
block|}
name|private
operator|:
name|std
operator|::
name|string
name|ErrMsg
block|;
name|stream_error_code
name|Code
block|; }
decl_stmt|;
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
comment|// LLVM_SUPPORT_BINARYSTREAMERROR_H
end_comment

end_unit

