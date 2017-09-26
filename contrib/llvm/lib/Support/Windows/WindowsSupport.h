begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===- WindowsSupport.h - Common Windows Include File -----------*- C++ -*-===//
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
comment|// This file defines things specific to Windows implementations.  In addition to
end_comment

begin_comment
comment|// providing some helpers for working with win32 APIs, this header wraps
end_comment

begin_comment
comment|//<windows.h> with some portability macros.  Always include WindowsSupport.h
end_comment

begin_comment
comment|// instead of including<windows.h> directly.
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

begin_ifndef
ifndef|#
directive|ifndef
name|LLVM_SUPPORT_WINDOWSSUPPORT_H
end_ifndef

begin_define
define|#
directive|define
name|LLVM_SUPPORT_WINDOWSSUPPORT_H
end_define

begin_comment
comment|// mingw-w64 tends to define it as 0x0502 in its headers.
end_comment

begin_undef
undef|#
directive|undef
name|_WIN32_WINNT
end_undef

begin_undef
undef|#
directive|undef
name|_WIN32_IE
end_undef

begin_comment
comment|// Require at least Windows 7 API.
end_comment

begin_define
define|#
directive|define
name|_WIN32_WINNT
value|0x0601
end_define

begin_define
define|#
directive|define
name|_WIN32_IE
value|0x0800
end_define

begin_comment
comment|// MinGW at it again. FIXME: verify if still needed.
end_comment

begin_define
define|#
directive|define
name|WIN32_LEAN_AND_MEAN
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NOMINMAX
end_ifndef

begin_define
define|#
directive|define
name|NOMINMAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"llvm/ADT/SmallVector.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringExtras.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/StringRef.h"
end_include

begin_include
include|#
directive|include
file|"llvm/ADT/Twine.h"
end_include

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
file|"llvm/Support/Chrono.h"
end_include

begin_include
include|#
directive|include
file|"llvm/Support/Compiler.h"
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

begin_include
include|#
directive|include
file|<system_error>
end_include

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_comment
comment|// Must be included after windows.h
end_comment

begin_include
include|#
directive|include
file|<wincrypt.h>
end_include

begin_comment
comment|/// Determines if the program is running on Windows 8 or newer. This
end_comment

begin_comment
comment|/// reimplements one of the helpers in the Windows 8.1 SDK, which are intended
end_comment

begin_comment
comment|/// to supercede raw calls to GetVersionEx. Old SDKs, Cygwin, and MinGW don't
end_comment

begin_comment
comment|/// yet have VersionHelpers.h, so we have our own helper.
end_comment

begin_function
specifier|inline
name|bool
name|RunningWindows8OrGreater
parameter_list|()
block|{
comment|// Windows 8 is version 6.2, service pack 0.
name|OSVERSIONINFOEXW
name|osvi
init|=
block|{}
decl_stmt|;
name|osvi
operator|.
name|dwOSVersionInfoSize
operator|=
sizeof|sizeof
argument_list|(
name|OSVERSIONINFO
argument_list|)
expr_stmt|;
name|osvi
operator|.
name|dwMajorVersion
operator|=
literal|6
expr_stmt|;
name|osvi
operator|.
name|dwMinorVersion
operator|=
literal|2
expr_stmt|;
name|osvi
operator|.
name|wServicePackMajor
operator|=
literal|0
expr_stmt|;
name|DWORDLONG
name|Mask
init|=
literal|0
decl_stmt|;
name|Mask
operator|=
name|VerSetConditionMask
argument_list|(
name|Mask
argument_list|,
name|VER_MAJORVERSION
argument_list|,
name|VER_GREATER_EQUAL
argument_list|)
expr_stmt|;
name|Mask
operator|=
name|VerSetConditionMask
argument_list|(
name|Mask
argument_list|,
name|VER_MINORVERSION
argument_list|,
name|VER_GREATER_EQUAL
argument_list|)
expr_stmt|;
name|Mask
operator|=
name|VerSetConditionMask
argument_list|(
name|Mask
argument_list|,
name|VER_SERVICEPACKMAJOR
argument_list|,
name|VER_GREATER_EQUAL
argument_list|)
expr_stmt|;
return|return
name|VerifyVersionInfoW
argument_list|(
operator|&
name|osvi
argument_list|,
name|VER_MAJORVERSION
operator||
name|VER_MINORVERSION
operator||
name|VER_SERVICEPACKMAJOR
argument_list|,
name|Mask
argument_list|)
operator|!=
name|FALSE
return|;
block|}
end_function

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
name|DWORD
name|LastError
init|=
name|GetLastError
argument_list|()
decl_stmt|;
name|DWORD
name|R
init|=
name|FormatMessageA
argument_list|(
name|FORMAT_MESSAGE_ALLOCATE_BUFFER
operator||
name|FORMAT_MESSAGE_FROM_SYSTEM
operator||
name|FORMAT_MESSAGE_MAX_WIDTH_MASK
argument_list|,
name|NULL
argument_list|,
name|LastError
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
decl_stmt|;
if|if
condition|(
name|R
condition|)
operator|*
name|ErrMsg
operator|=
name|prefix
operator|+
literal|": "
operator|+
name|buffer
expr_stmt|;
else|else
operator|*
name|ErrMsg
operator|=
name|prefix
operator|+
literal|": Unknown error"
expr_stmt|;
operator|*
name|ErrMsg
operator|+=
literal|" (0x"
operator|+
name|llvm
operator|::
name|utohexstr
argument_list|(
name|LastError
argument_list|)
operator|+
literal|")"
expr_stmt|;
name|LocalFree
argument_list|(
name|buffer
argument_list|)
expr_stmt|;
return|return
name|R
operator|!=
literal|0
return|;
block|}
end_decl_stmt

begin_expr_stmt
name|template
operator|<
name|typename
name|HandleTraits
operator|>
name|class
name|ScopedHandle
block|{
typedef|typedef
name|typename
name|HandleTraits
operator|::
name|handle_type
name|handle_type
expr_stmt|;
name|handle_type
name|Handle
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|ScopedHandle
argument_list|(
specifier|const
name|ScopedHandle
operator|&
name|other
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|// = delete;
end_comment

begin_decl_stmt
name|void
name|operator
init|=
operator|(
specifier|const
name|ScopedHandle
operator|&
name|other
operator|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|// = delete;
end_comment

begin_label
name|public
label|:
end_label

begin_expr_stmt
name|ScopedHandle
argument_list|()
operator|:
name|Handle
argument_list|(
argument|HandleTraits::GetInvalid()
argument_list|)
block|{}
name|explicit
name|ScopedHandle
argument_list|(
argument|handle_type h
argument_list|)
operator|:
name|Handle
argument_list|(
argument|h
argument_list|)
block|{}
operator|~
name|ScopedHandle
argument_list|()
block|{
if|if
condition|(
name|HandleTraits
operator|::
name|IsValid
argument_list|(
name|Handle
argument_list|)
condition|)
name|HandleTraits
operator|::
name|Close
argument_list|(
name|Handle
argument_list|)
expr_stmt|;
block|}
end_expr_stmt

begin_function
name|handle_type
name|take
parameter_list|()
block|{
name|handle_type
name|t
init|=
name|Handle
decl_stmt|;
name|Handle
operator|=
name|HandleTraits
operator|::
name|GetInvalid
argument_list|()
expr_stmt|;
return|return
name|t
return|;
block|}
end_function

begin_decl_stmt
name|ScopedHandle
modifier|&
name|operator
init|=
operator|(
name|handle_type
name|h
operator|)
block|{
if|if
condition|(
name|HandleTraits
operator|::
name|IsValid
argument_list|(
name|Handle
argument_list|)
condition|)
name|HandleTraits
operator|::
name|Close
argument_list|(
name|Handle
argument_list|)
expr_stmt|;
name|Handle
operator|=
name|h
decl_stmt|;
end_decl_stmt

begin_return
return|return
operator|*
name|this
return|;
end_return

begin_comment
unit|}
comment|// True if Handle is valid.
end_comment

begin_expr_stmt
unit|explicit
name|operator
name|bool
argument_list|()
specifier|const
block|{
return|return
name|HandleTraits
operator|::
name|IsValid
argument_list|(
name|Handle
argument_list|)
operator|?
name|true
operator|:
name|false
return|;
block|}
end_expr_stmt

begin_expr_stmt
name|operator
name|handle_type
argument_list|()
specifier|const
block|{
return|return
name|Handle
return|;
block|}
end_expr_stmt

begin_struct
unit|};
struct|struct
name|CommonHandleTraits
block|{
typedef|typedef
name|HANDLE
name|handle_type
typedef|;
specifier|static
name|handle_type
name|GetInvalid
parameter_list|()
block|{
return|return
name|INVALID_HANDLE_VALUE
return|;
block|}
specifier|static
name|void
name|Close
parameter_list|(
name|handle_type
name|h
parameter_list|)
block|{
operator|::
name|CloseHandle
argument_list|(
name|h
argument_list|)
expr_stmt|;
block|}
specifier|static
name|bool
name|IsValid
parameter_list|(
name|handle_type
name|h
parameter_list|)
block|{
return|return
name|h
operator|!=
name|GetInvalid
argument_list|()
return|;
block|}
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|JobHandleTraits
range|:
name|CommonHandleTraits
block|{
specifier|static
name|handle_type
name|GetInvalid
argument_list|()
block|{
return|return
name|NULL
return|;
block|}
expr|}
block|;  struct
name|CryptContextTraits
operator|:
name|CommonHandleTraits
block|{
typedef|typedef
name|HCRYPTPROV
name|handle_type
typedef|;
specifier|static
name|handle_type
name|GetInvalid
argument_list|()
block|{
return|return
literal|0
return|;
block|}
specifier|static
name|void
name|Close
argument_list|(
argument|handle_type h
argument_list|)
block|{
operator|::
name|CryptReleaseContext
argument_list|(
name|h
argument_list|,
literal|0
argument_list|)
block|;   }
specifier|static
name|bool
name|IsValid
argument_list|(
argument|handle_type h
argument_list|)
block|{
return|return
name|h
operator|!=
name|GetInvalid
argument_list|()
return|;
block|}
expr|}
block|;  struct
name|RegTraits
operator|:
name|CommonHandleTraits
block|{
typedef|typedef
name|HKEY
name|handle_type
typedef|;
specifier|static
name|handle_type
name|GetInvalid
argument_list|()
block|{
return|return
name|NULL
return|;
block|}
specifier|static
name|void
name|Close
argument_list|(
argument|handle_type h
argument_list|)
block|{
operator|::
name|RegCloseKey
argument_list|(
name|h
argument_list|)
block|;   }
specifier|static
name|bool
name|IsValid
argument_list|(
argument|handle_type h
argument_list|)
block|{
return|return
name|h
operator|!=
name|GetInvalid
argument_list|()
return|;
block|}
expr|}
block|;  struct
name|FindHandleTraits
operator|:
name|CommonHandleTraits
block|{
specifier|static
name|void
name|Close
argument_list|(
argument|handle_type h
argument_list|)
block|{
operator|::
name|FindClose
argument_list|(
name|h
argument_list|)
block|;   }
block|}
block|;  struct
name|FileHandleTraits
operator|:
name|CommonHandleTraits
block|{}
block|;
typedef|typedef
name|ScopedHandle
operator|<
name|CommonHandleTraits
operator|>
name|ScopedCommonHandle
expr_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|ScopedHandle
operator|<
name|FileHandleTraits
operator|>
name|ScopedFileHandle
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|ScopedHandle
operator|<
name|CryptContextTraits
operator|>
name|ScopedCryptContext
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|ScopedHandle
operator|<
name|RegTraits
operator|>
name|ScopedRegHandle
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|ScopedHandle
operator|<
name|FindHandleTraits
operator|>
name|ScopedFindHandle
expr_stmt|;
end_typedef

begin_typedef
typedef|typedef
name|ScopedHandle
operator|<
name|JobHandleTraits
operator|>
name|ScopedJobHandle
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
name|namespace
name|sys
block|{
specifier|inline
name|std
operator|::
name|chrono
operator|::
name|nanoseconds
name|toDuration
argument_list|(
argument|FILETIME Time
argument_list|)
block|{
name|ULARGE_INTEGER
name|TimeInteger
block|;
name|TimeInteger
operator|.
name|LowPart
operator|=
name|Time
operator|.
name|dwLowDateTime
block|;
name|TimeInteger
operator|.
name|HighPart
operator|=
name|Time
operator|.
name|dwHighDateTime
block|;
comment|// FILETIME's are # of 100 nanosecond ticks (1/10th of a microsecond)
return|return
name|std
operator|::
name|chrono
operator|::
name|nanoseconds
argument_list|(
literal|100
operator|*
name|TimeInteger
operator|.
name|QuadPart
argument_list|)
return|;
block|}
specifier|inline
name|TimePoint
operator|<
operator|>
name|toTimePoint
argument_list|(
argument|FILETIME Time
argument_list|)
block|{
name|ULARGE_INTEGER
name|TimeInteger
block|;
name|TimeInteger
operator|.
name|LowPart
operator|=
name|Time
operator|.
name|dwLowDateTime
block|;
name|TimeInteger
operator|.
name|HighPart
operator|=
name|Time
operator|.
name|dwHighDateTime
block|;
comment|// Adjust for different epoch
name|TimeInteger
operator|.
name|QuadPart
operator|-=
literal|11644473600ll
operator|*
literal|10000000
block|;
comment|// FILETIME's are # of 100 nanosecond ticks (1/10th of a microsecond)
return|return
name|TimePoint
operator|<
operator|>
operator|(
name|std
operator|::
name|chrono
operator|::
name|nanoseconds
argument_list|(
literal|100
operator|*
name|TimeInteger
operator|.
name|QuadPart
argument_list|)
operator|)
return|;
block|}
specifier|inline
name|FILETIME
name|toFILETIME
argument_list|(
name|TimePoint
operator|<
operator|>
name|TP
argument_list|)
block|{
name|ULARGE_INTEGER
name|TimeInteger
decl_stmt|;
name|TimeInteger
operator|.
name|QuadPart
operator|=
name|TP
operator|.
name|time_since_epoch
argument_list|()
operator|.
name|count
argument_list|()
operator|/
literal|100
expr_stmt|;
name|TimeInteger
operator|.
name|QuadPart
operator|+=
literal|11644473600ll
operator|*
literal|10000000
expr_stmt|;
name|FILETIME
name|Time
decl_stmt|;
name|Time
operator|.
name|dwLowDateTime
operator|=
name|TimeInteger
operator|.
name|LowPart
expr_stmt|;
name|Time
operator|.
name|dwHighDateTime
operator|=
name|TimeInteger
operator|.
name|HighPart
expr_stmt|;
return|return
name|Time
return|;
block|}
name|namespace
name|path
block|{
name|std
operator|::
name|error_code
name|widenPath
argument_list|(
specifier|const
name|Twine
operator|&
name|Path8
argument_list|,
name|SmallVectorImpl
operator|<
name|wchar_t
operator|>
operator|&
name|Path16
argument_list|)
expr_stmt|;
block|}
comment|// end namespace path
name|namespace
name|windows
block|{
name|std
operator|::
name|error_code
name|UTF8ToUTF16
argument_list|(
argument|StringRef utf8
argument_list|,
argument|SmallVectorImpl<wchar_t>&utf16
argument_list|)
expr_stmt|;
name|std
operator|::
name|error_code
name|UTF16ToUTF8
argument_list|(
argument|const wchar_t *utf16
argument_list|,
argument|size_t utf16_len
argument_list|,
argument|SmallVectorImpl<char>&utf8
argument_list|)
expr_stmt|;
comment|/// Convert from UTF16 to the current code page used in the system
name|std
operator|::
name|error_code
name|UTF16ToCurCP
argument_list|(
argument|const wchar_t *utf16
argument_list|,
argument|size_t utf16_len
argument_list|,
argument|SmallVectorImpl<char>&utf8
argument_list|)
expr_stmt|;
block|}
comment|// end namespace windows
block|}
comment|// end namespace sys
block|}
end_decl_stmt

begin_comment
comment|// end namespace llvm.
end_comment

begin_endif
endif|#
directive|endif
end_endif

end_unit

