begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.in.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* Name of package.  */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"bfd"
end_define

begin_comment
comment|/* Version of package.  */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"2.9.1"
end_define

begin_comment
comment|/* Whether strstr must be declared even if<string.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_STRSTR */
end_comment

begin_comment
comment|/* Whether malloc must be declared even if<stdlib.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_MALLOC */
end_comment

begin_comment
comment|/* Whether realloc must be declared even if<stdlib.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_REALLOC */
end_comment

begin_comment
comment|/* Whether free must be declared even if<stdlib.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_FREE */
end_comment

begin_comment
comment|/* Whether getenv must be declared even if<stdlib.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_GETENV */
end_comment

begin_comment
comment|/* Define if you have a working `mmap' system call.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MMAP
value|1
end_define

begin_comment
comment|/* Define if you need to in order for stat and other things to work.  */
end_comment

begin_comment
comment|/* #undef _POSIX_SOURCE */
end_comment

begin_comment
comment|/* Define if you can safely include both<sys/time.h> and<time.h>.  */
end_comment

begin_define
define|#
directive|define
name|TIME_WITH_SYS_TIME
value|1
end_define

begin_comment
comment|/* Do we need to use the b modifier when opening binary files?  */
end_comment

begin_comment
comment|/* #undef USE_BINARY_FOPEN */
end_comment

begin_comment
comment|/* Name of host specific header file to include in trad-core.c.  */
end_comment

begin_comment
comment|/* #undef TRAD_HEADER */
end_comment

begin_comment
comment|/* Define only if<sys/procfs.h> is available *and* it defines prstatus_t.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PROCFS_H */
end_comment

begin_comment
comment|/* Do we really want to use mmap if it's available?  */
end_comment

begin_comment
comment|/* #undef USE_MMAP */
end_comment

begin_comment
comment|/* Define if you have the fcntl function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL
value|1
end_define

begin_comment
comment|/* Define if you have the fdopen function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FDOPEN
value|1
end_define

begin_comment
comment|/* Define if you have the getpagesize function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPAGESIZE
value|1
end_define

begin_comment
comment|/* Define if you have the madvise function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MADVISE
value|1
end_define

begin_comment
comment|/* Define if you have the mprotect function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MPROTECT
value|1
end_define

begin_comment
comment|/* Define if you have the setitimer function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETITIMER
value|1
end_define

begin_comment
comment|/* Define if you have the sysconf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYSCONF
value|1
end_define

begin_comment
comment|/* Define if you have the<fcntl.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<stddef.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDDEF_H
value|1
end_define

begin_comment
comment|/* Define if you have the<stdlib.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define if you have the<string.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define if you have the<strings.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/file.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/time.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<time.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<unistd.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

end_unit

