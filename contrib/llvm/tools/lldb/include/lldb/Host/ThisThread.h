begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- ThisThread.h --------------------------------------------*- C++ -*-===//
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
name|lldb_Host_ThisThread_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_ThisThread_h_
end_define

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
name|llvm
block|{
name|template
operator|<
name|class
name|T
operator|>
name|class
name|SmallVectorImpl
expr_stmt|;
block|}
end_decl_stmt

begin_decl_stmt
name|namespace
name|lldb_private
block|{
name|class
name|ThisThread
block|{
name|private
label|:
name|ThisThread
argument_list|()
expr_stmt|;
name|public
label|:
comment|// ThisThread common functions.
specifier|static
name|void
name|SetName
argument_list|(
name|llvm
operator|::
name|StringRef
name|name
argument_list|,
name|int
name|max_length
argument_list|)
decl_stmt|;
comment|// ThisThread platform-specific functions.
specifier|static
name|void
name|SetName
argument_list|(
name|llvm
operator|::
name|StringRef
name|name
argument_list|)
decl_stmt|;
specifier|static
name|void
name|GetName
argument_list|(
name|llvm
operator|::
name|SmallVectorImpl
operator|<
name|char
operator|>
operator|&
name|name
argument_list|)
decl_stmt|;
block|}
empty_stmt|;
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

