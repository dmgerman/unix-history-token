begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- Win32/Win32.h - Common Win32 Include File ----------------*- C++ -*-===//
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
comment|// This file defines things specific to Win32 implementations.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|//=== WARNING: Implementation here must contain only generic Win32 code that
end_comment

begin_comment
comment|//===          is guaranteed to work on *all* Win32 variants.
end_comment

begin_comment
comment|//===----------------------------------------------------------------------===//
end_comment

begin_comment
comment|// Require at least Windows 2000 API.
end_comment

begin_define
define|#
directive|define
name|_WIN32_WINNT
value|0x0500
end_define

begin_include
include|#
directive|include
file|"llvm/Config/config.h"
end_include

begin_comment
comment|// Get autoconf configuration settings
end_comment

begin_include
include|#
directive|include
file|"windows.h"
end_include

begin_include
include|#
directive|include
file|<cassert>
end_include

begin_include
include|#
directive|include
file|<string>
end_include

begin_decl_stmt
specifier|inline
name|bool
name|MakeErrMsg
argument_list|(
name|std
operator|::
name|string
operator|*
name|ErrMsg
argument_list|,
specifier|const
name|std
operator|::
name|string
operator|&
name|prefix
argument_list|)
block|{
if|if
condition|(
operator|!
name|ErrMsg
condition|)
return|return
name|true
return|;
name|char
modifier|*
name|buffer
init|=
name|NULL
decl_stmt|;
name|FormatMessage
argument_list|(
name|FORMAT_MESSAGE_ALLOCATE_BUFFER
operator||
name|FORMAT_MESSAGE_FROM_SYSTEM
argument_list|,
name|NULL
argument_list|,
name|GetLastError
argument_list|()
argument_list|,
literal|0
argument_list|,
operator|(
name|LPSTR
operator|)
operator|&
name|buffer
argument_list|,
literal|1
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
operator|*
name|ErrMsg
operator|=
name|prefix
operator|+
name|buffer
expr_stmt|;
name|LocalFree
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
return|return
name|true
return|;
block|}
end_decl_stmt

begin_decl_stmt
name|class
name|AutoHandle
block|{
name|HANDLE
name|handle
decl_stmt|;
name|public
label|:
name|AutoHandle
argument_list|(
argument|HANDLE h
argument_list|)
block|:
name|handle
argument_list|(
argument|h
argument_list|)
block|{}
operator|~
name|AutoHandle
argument_list|()
block|{
if|if
condition|(
name|handle
condition|)
name|CloseHandle
argument_list|(
name|handle
argument_list|)
expr_stmt|;
block|}
name|operator
name|HANDLE
parameter_list|()
block|{
return|return
name|handle
return|;
block|}
name|AutoHandle
modifier|&
name|operator
init|=
operator|(
name|HANDLE
name|h
operator|)
block|{
name|handle
operator|=
name|h
block|;
return|return
operator|*
name|this
return|;
block|}
block|}
end_decl_stmt

begin_empty_stmt
empty_stmt|;
end_empty_stmt

end_unit

