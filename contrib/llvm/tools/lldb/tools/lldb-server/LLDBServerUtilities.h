begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- LLDBServerUtilities.h -----------------------------------*- C++ -*-===//
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

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|namespace
name|lldb_server
block|{
name|class
name|LLDBServerUtilities
block|{
name|public
label|:
specifier|static
name|bool
name|SetupLogging
argument_list|(
specifier|const
name|std
operator|::
name|string
operator|&
name|log_file
argument_list|,
specifier|const
name|llvm
operator|::
name|StringRef
operator|&
name|log_channels
argument_list|,
name|uint32_t
name|log_options
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
block|}
end_decl_stmt

end_unit

