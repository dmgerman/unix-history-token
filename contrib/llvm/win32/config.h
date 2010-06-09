begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file is appended to config.h.in to form the Windows version of  * config.h */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"LLVM (win32 vc8.0)"
end_define

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|2.4
end_define

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|"llvm 2.6svn"
end_define

begin_define
define|#
directive|define
name|LLVM_HOSTTRIPLE
value|"i686-pc-win32"
end_define

begin_define
define|#
directive|define
name|HAVE_WINDOWS_H
value|1
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
name|HAVE_SYS_STAT_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STDIO_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_CEILF
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_FLOORF
value|1
end_define

begin_define
define|#
directive|define
name|SHLIBEXT
value|".lib"
end_define

begin_define
define|#
directive|define
name|error_t
value|int
end_define

begin_define
define|#
directive|define
name|HAVE_ERRNO_H
value|1
end_define

begin_define
define|#
directive|define
name|LTDL_DLOPEN_DEPLIBS
value|1
end_define

begin_define
define|#
directive|define
name|LTDL_OBJDIR
value|"_libs"
end_define

begin_define
define|#
directive|define
name|LTDL_SHLIBPATH_VAR
value|"PATH"
end_define

begin_define
define|#
directive|define
name|LTDL_SHLIB_EXT
value|".dll"
end_define

begin_define
define|#
directive|define
name|LTDL_SYSSEARCHPATH
value|""
end_define

begin_define
define|#
directive|define
name|LLVM_ON_WIN32
value|1
end_define

begin_define
define|#
directive|define
name|strtoll
value|_strtoi64
end_define

begin_define
define|#
directive|define
name|strtoull
value|_strtoui64
end_define

begin_define
define|#
directive|define
name|stricmp
value|_stricmp
end_define

begin_define
define|#
directive|define
name|strdup
value|_strdup
end_define

end_unit

