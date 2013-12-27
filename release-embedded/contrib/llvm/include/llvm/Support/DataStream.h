begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===---- llvm/Support/DataStream.h - Lazy bitcode streaming ----*- C++ -*-===//
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
comment|// This header defines DataStreamer, which fetches bytes of data from
end_comment

begin_comment
comment|// a stream source. It provides support for streaming (lazy reading) of
end_comment

begin_comment
comment|// data, e.g. bitcode
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
name|LLVM_SUPPORT_DATASTREAM_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_DATASTREAM_H
end_define

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
name|DataStreamer
block|{
name|public
label|:
comment|/// Fetch bytes [start-end) from the stream, and write them to the
comment|/// buffer pointed to by buf. Returns the number of bytes actually written.
name|virtual
name|size_t
name|GetBytes
parameter_list|(
name|unsigned
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|len
parameter_list|)
init|=
literal|0
function_decl|;
name|virtual
operator|~
name|DataStreamer
argument_list|()
expr_stmt|;
block|}
empty_stmt|;
name|DataStreamer
modifier|*
name|getDataFileStreamer
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|Filename
argument_list|,
name|std
operator|::
name|string
operator|*
name|Err
argument_list|)
decl_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLVM_SUPPORT_DATASTREAM_H_
end_comment

end_unit

