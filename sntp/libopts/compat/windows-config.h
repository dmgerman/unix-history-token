begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * \file windows-config.h  *  *  This file contains all of the routines that must be linked into  *  an executable to use the generated option processing.  The optional  *  routines are in separately compiled modules so that they will not  *  necessarily be linked in.  *  *  This file is part of AutoOpts, a companion to AutoGen.  *  AutoOpts is free software.  *  AutoOpts is Copyright (C) 1992-2014 by Bruce Korb - all rights reserved  *  *  AutoOpts is available under any one of two licenses.  The license  *  in use must be one of these two and the choice is under the control  *  of the user of the license.  *  *   The GNU Lesser General Public License, version 3 or later  *      See the files "COPYING.lgplv3" and "COPYING.gplv3"  *  *   The Modified Berkeley Software Distribution License  *      See the file "COPYING.mbsd"  *  *  These files have the following sha256 sums:  *  *  8584710e9b04216a394078dc156b781d0b47e1729104d666658aecef8ee32e95  COPYING.gplv3  *  4379e7444a0e2ce2b12dd6f5a52a27a4d02d39d247901d3285c88cf0d37f477b  COPYING.lgplv3  *  13aa749a5b0a454917a944ed8fffc530b784f5ead522b1aacaf4ec8aa55a6239  COPYING.mbsd  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|WINDOWS_CONFIG_HACKERY
end_ifndef

begin_define
define|#
directive|define
name|WINDOWS_CONFIG_HACKERY
value|1
end_define

begin_comment
comment|/*  * The definitions below have been stolen from NTP's config.h for Windows.  * However, they may be kept here in order to keep libopts independent from  * the NTP project.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__windows__
end_ifndef

begin_define
define|#
directive|define
name|__windows__
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Miscellaneous functions that Microsoft maps to other names  */
end_comment

begin_define
define|#
directive|define
name|snprintf
value|_snprintf
end_define

begin_define
define|#
directive|define
name|SIZEOF_INT
value|4
end_define

begin_define
define|#
directive|define
name|SIZEOF_CHARP
value|4
end_define

begin_define
define|#
directive|define
name|SIZEOF_LONG
value|4
end_define

begin_define
define|#
directive|define
name|SIZEOF_SHORT
value|2
end_define

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRCHR
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/*  * VS.NET's version of wspiapi.h has a bug in it where it assigns a value  * to a variable inside an if statement. It should be comparing them.  * We prevent inclusion since we are not using this code so we don't have  * to see the warning messages  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WSPIAPI_H_
end_ifndef

begin_define
define|#
directive|define
name|_WSPIAPI_H_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Prevent inclusion of winsock.h in windows.h */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_WINSOCKAPI_
end_ifndef

begin_define
define|#
directive|define
name|_WINSOCKAPI_
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__RPCASYNC_H__
end_ifndef

begin_define
define|#
directive|define
name|__RPCASYNC_H__
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Include Windows headers */
end_comment

begin_include
include|#
directive|include
file|<windows.h>
end_include

begin_include
include|#
directive|include
file|<winsock2.h>
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_comment
comment|/*  * Compatibility declarations for Windows, assuming SYS_WINNT  * has been defined.  */
end_comment

begin_define
define|#
directive|define
name|strdup
value|_strdup
end_define

begin_define
define|#
directive|define
name|stat
value|_stat
end_define

begin_comment
comment|/* struct stat from<sys/stat.h> */
end_comment

begin_define
define|#
directive|define
name|unlink
value|_unlink
end_define

begin_define
define|#
directive|define
name|fchmod
parameter_list|(
name|_x
parameter_list|,
name|_y
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ssize_t
value|SSIZE_T
end_define

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_define
define|#
directive|define
name|open
value|_open
end_define

begin_define
define|#
directive|define
name|close
value|_close
end_define

begin_define
define|#
directive|define
name|read
value|_read
end_define

begin_define
define|#
directive|define
name|write
value|_write
end_define

begin_define
define|#
directive|define
name|lseek
value|_lseek
end_define

begin_define
define|#
directive|define
name|pipe
value|_pipe
end_define

begin_define
define|#
directive|define
name|dup2
value|_dup2
end_define

begin_define
define|#
directive|define
name|O_RDWR
value|_O_RDWR
end_define

begin_define
define|#
directive|define
name|O_RDONLY
value|_O_RDONLY
end_define

begin_define
define|#
directive|define
name|O_EXCL
value|_O_EXCL
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISREG
end_ifndef

begin_define
define|#
directive|define
name|S_IFREG
value|_S_IFREG
end_define

begin_define
define|#
directive|define
name|S_ISREG
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& S_IFREG) == S_IFREG)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|S_ISDIR
end_ifndef

begin_define
define|#
directive|define
name|S_IFDIR
value|_S_IFDIR
end_define

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|mode
parameter_list|)
value|(((mode)& S_IFDIR) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* C99 exact size integer support. */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_INTTYPES_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<inttypes.h>
end_include

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_STDINT_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_define
define|#
directive|define
name|MISSING_INTTYPES_H
value|1
end_define

begin_elif
elif|#
directive|elif
operator|!
name|defined
argument_list|(
name|ADDED_EXACT_SIZE_INTEGERS
argument_list|)
end_elif

begin_define
define|#
directive|define
name|ADDED_EXACT_SIZE_INTEGERS
value|1
end_define

begin_define
define|#
directive|define
name|MISSING_INTTYPES_H
value|1
end_define

begin_typedef
typedef|typedef
name|__int8
name|int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int8
name|uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int16
name|int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int16
name|uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int32
name|int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int32
name|uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|__int64
name|int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|__int64
name|uint64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|uintptr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|intptr_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* WINDOWS_CONFIG_HACKERY */
end_comment

begin_comment
comment|/* windows-config.h ends here */
end_comment

end_unit

