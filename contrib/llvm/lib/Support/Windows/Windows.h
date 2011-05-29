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
comment|// mingw-w64 tends to define it as 0x0502 in its headers.
end_comment

begin_undef
undef|#
directive|undef
name|_WIN32_WINNT
end_undef

begin_comment
comment|// Require at least Windows 2000 API.
end_comment

begin_define
define|#
directive|define
name|_WIN32_WINNT
value|0x0500
end_define

begin_define
define|#
directive|define
name|_WIN32_IE
value|0x0500
end_define

begin_comment
comment|// MinGW at it again.
end_comment

begin_define
define|#
directive|define
name|WIN32_LEAN_AND_MEAN
end_define

begin_include
include|#
directive|include
file|"llvm/Config/config.h"
end_include

begin_comment
comment|// Get build system configuration settings
end_comment

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_include
include|#
directive|include
file|<shlobj.h>
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

begin_expr_stmt
name|template
operator|<
name|class
name|HandleType
operator|,
name|uintptr_t
name|InvalidHandle
operator|,
name|class
name|DeleterType
operator|,
name|DeleterType
name|D
operator|>
name|class
name|ScopedHandle
block|{
name|HandleType
name|Handle
block|;
name|public
operator|:
name|ScopedHandle
argument_list|()
operator|:
name|Handle
argument_list|(
argument|InvalidHandle
argument_list|)
block|{}
name|ScopedHandle
argument_list|(
argument|HandleType handle
argument_list|)
operator|:
name|Handle
argument_list|(
argument|handle
argument_list|)
block|{}
operator|~
name|ScopedHandle
argument_list|()
block|{
if|if
condition|(
name|Handle
operator|!=
name|HandleType
argument_list|(
name|InvalidHandle
argument_list|)
condition|)
name|D
argument_list|(
name|Handle
argument_list|)
expr_stmt|;
block|}
name|HandleType
name|take
argument_list|()
block|{
name|HandleType
name|temp
operator|=
name|Handle
block|;
name|Handle
operator|=
name|HandleType
argument_list|(
name|InvalidHandle
argument_list|)
block|;
return|return
name|temp
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|operator
name|HandleType
argument_list|()
specifier|const
block|{
return|return
name|Handle
return|;
block|}
end_expr_stmt

begin_decl_stmt
name|ScopedHandle
modifier|&
name|operator
init|=
operator|(
name|HandleType
name|handle
operator|)
block|{
name|Handle
operator|=
name|handle
block|;
return|return
operator|*
name|this
return|;
block|}
end_decl_stmt

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|unspecified_bool_type
function_decl|)
parameter_list|()
function_decl|;
end_typedef

begin_function
specifier|static
name|void
name|unspecified_bool_true
parameter_list|()
block|{}
end_function

begin_comment
comment|// True if Handle is valid.
end_comment

begin_expr_stmt
name|operator
name|unspecified_bool_type
argument_list|()
specifier|const
block|{
return|return
name|Handle
operator|==
name|HandleType
argument_list|(
name|InvalidHandle
argument_list|)
operator|?
literal|0
operator|:
name|unspecified_bool_true
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|bool
name|operator
operator|!
operator|(
operator|)
specifier|const
block|{
return|return
name|Handle
operator|==
name|HandleType
argument_list|(
name|InvalidHandle
argument_list|)
return|;
block|}
end_expr_stmt

begin_typedef
unit|};
typedef|typedef
name|ScopedHandle
operator|<
name|HANDLE
operator|,
name|uintptr_t
argument_list|(
operator|-
literal|1
argument_list|)
operator|,
name|BOOL
argument_list|(
name|WINAPI
operator|*
argument_list|)
argument_list|(
name|HANDLE
argument_list|)
operator|,
operator|::
name|FindClose
operator|>
name|ScopedFindHandle
expr_stmt|;
end_typedef

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
name|template
operator|<
name|class
name|T
operator|>
name|typename
name|SmallVectorImpl
operator|<
name|T
operator|>
operator|::
name|const_pointer
name|c_str
argument_list|(
argument|SmallVectorImpl<T>&str
argument_list|)
block|{
name|str
operator|.
name|push_back
argument_list|(
literal|0
argument_list|)
block|;
name|str
operator|.
name|pop_back
argument_list|()
block|;
return|return
name|str
operator|.
name|data
argument_list|()
return|;
block|}
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm.
end_comment

end_unit

