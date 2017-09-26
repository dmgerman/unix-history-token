begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|//===-- HostInfoBase.h ------------------------------------------*- C++ -*-===//
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
name|lldb_Host_HostInfo_h_
end_ifndef

begin_define
define|#
directive|define
name|lldb_Host_HostInfo_h_
end_define

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_comment
comment|/// @class HostInfo HostInfo.h "lldb/Host/HostInfo.h"
end_comment

begin_comment
comment|/// @brief A class that provides host computer information.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// HostInfo is a class that answers information about the host operating
end_comment

begin_comment
comment|/// system.  Note that HostInfo is NOT intended to be used to manipulate or
end_comment

begin_comment
comment|/// control the operating system.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// HostInfo is implemented in an OS-specific class (for example
end_comment

begin_comment
comment|/// HostInfoWindows) in a separate file, and then typedefed to HostInfo here.
end_comment

begin_comment
comment|/// Users of the class reference it as HostInfo::method().
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Not all hosts provide the same functionality.  It is important that methods
end_comment

begin_comment
comment|/// only be implemented at the lowest level at which they make sense.  It should
end_comment

begin_comment
comment|/// be up to the clients of the class to ensure that they not attempt to call a
end_comment

begin_comment
comment|/// method which doesn't make sense for a particular platform.  For example,
end_comment

begin_comment
comment|/// when implementing a method that only makes sense on a posix-compliant
end_comment

begin_comment
comment|/// system, implement it on HostInfoPosix, and not on HostInfoBase with a
end_comment

begin_comment
comment|/// default implementation.  This way, users of HostInfo are required to think
end_comment

begin_comment
comment|/// about the implications of calling a particular method and if used in a
end_comment

begin_comment
comment|/// context where the method doesn't make sense, will generate a compiler error.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|//----------------------------------------------------------------------
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
end_if

begin_include
include|#
directive|include
file|"lldb/Host/windows/HostInfoWindows.h"
end_include

begin_define
define|#
directive|define
name|HOST_INFO_TYPE
value|HostInfoWindows
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__linux__
argument_list|)
end_elif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__ANDROID__
argument_list|)
end_if

begin_include
include|#
directive|include
file|"lldb/Host/android/HostInfoAndroid.h"
end_include

begin_define
define|#
directive|define
name|HOST_INFO_TYPE
value|HostInfoAndroid
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"lldb/Host/linux/HostInfoLinux.h"
end_include

begin_define
define|#
directive|define
name|HOST_INFO_TYPE
value|HostInfoLinux
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__FreeBSD__
argument_list|)
operator|||
name|defined
argument_list|(
name|__FreeBSD_kernel__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"lldb/Host/freebsd/HostInfoFreeBSD.h"
end_include

begin_define
define|#
directive|define
name|HOST_INFO_TYPE
value|HostInfoFreeBSD
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__NetBSD__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"lldb/Host/netbsd/HostInfoNetBSD.h"
end_include

begin_define
define|#
directive|define
name|HOST_INFO_TYPE
value|HostInfoNetBSD
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__OpenBSD__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"lldb/Host/openbsd/HostInfoOpenBSD.h"
end_include

begin_define
define|#
directive|define
name|HOST_INFO_TYPE
value|HostInfoOpenBSD
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|__APPLE__
argument_list|)
end_elif

begin_include
include|#
directive|include
file|"lldb/Host/macosx/HostInfoMacOSX.h"
end_include

begin_define
define|#
directive|define
name|HOST_INFO_TYPE
value|HostInfoMacOSX
end_define

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"lldb/Host/posix/HostInfoPosix.h"
end_include

begin_define
define|#
directive|define
name|HOST_INFO_TYPE
value|HostInfoPosix
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|namespace
name|lldb_private
block|{
typedef|typedef
name|HOST_INFO_TYPE
name|HostInfo
typedef|;
block|}
end_decl_stmt

begin_undef
undef|#
directive|undef
name|HOST_INFO_TYPE
end_undef

begin_endif
endif|#
directive|endif
end_endif

end_unit

