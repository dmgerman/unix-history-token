begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- lldb-android.h --------------------------------------------*- C++ -*-===//
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
name|LLDB_lldb_android_h_
end_ifndef

begin_define
define|#
directive|define
name|LLDB_lldb_android_h_
end_define

begin_include
include|#
directive|include
file|<sstream>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_decl_stmt
name|namespace
name|std
block|{
name|template
operator|<
name|typename
name|T
operator|>
name|std
operator|::
name|string
name|to_string
argument_list|(
argument|T value
argument_list|)
block|{
name|std
operator|::
name|ostringstream
name|os
block|;
name|os
operator|<<
name|value
block|;
return|return
name|os
operator|.
name|str
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|// LLDB_lldb_android_h_
end_comment

end_unit

