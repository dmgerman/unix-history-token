begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.hin.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* Define if on AIX 3.    System headers sometimes define this.    We just want to avoid a redefinition error message.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALL_SOURCE
end_ifndef

begin_comment
comment|/* #undef _ALL_SOURCE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if the closedir function returns void instead of int.  */
end_comment

begin_comment
comment|/* #undef CLOSEDIR_VOID */
end_comment

begin_comment
comment|/* Define to empty if the keyword does not work.  */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define if you don't have vprintf but do have _doprnt.  */
end_comment

begin_comment
comment|/* #undef HAVE_DOPRNT */
end_comment

begin_comment
comment|/* Define if you support file names longer than 14 characters.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_FILE_NAMES
value|1
end_define

begin_comment
comment|/* Define if you have the vprintf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VPRINTF
value|1
end_define

begin_comment
comment|/* Define if on MINIX.  */
end_comment

begin_comment
comment|/* #undef _MINIX */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef mode_t */
end_comment

begin_comment
comment|/* Define to `long' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef off_t */
end_comment

begin_comment
comment|/* Define if the system does not provide POSIX.1 features except    with this defined.  */
end_comment

begin_comment
comment|/* #undef _POSIX_1_SOURCE */
end_comment

begin_comment
comment|/* Define if you need to in order for stat and other things to work.  */
end_comment

begin_comment
comment|/* #undef _POSIX_SOURCE */
end_comment

begin_comment
comment|/* Define as the return type of signal handlers (int or void).  */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_comment
comment|/* Define to `unsigned' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* Define if you have the ANSI C header files.  */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Define if there is a member named d_ino in the struct describing    directory headers.  */
end_comment

begin_define
define|#
directive|define
name|D_INO_IN_DIRENT
value|1
end_define

begin_comment
comment|/* Define if memchr works.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMCHR
value|1
end_define

begin_comment
comment|/* Define if `struct utimbuf' is declared -- usually in<utime.h>.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_UTIMBUF
value|1
end_define

begin_comment
comment|/* Define if you have the _doprintf function.  */
end_comment

begin_comment
comment|/* #undef HAVE__DOPRINTF */
end_comment

begin_comment
comment|/* Define if you have the isascii function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISASCII
value|1
end_define

begin_comment
comment|/* Define if you have the memchr function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMCHR
value|1
end_define

begin_comment
comment|/* Define if you have the memcmp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMCMP
value|1
end_define

begin_comment
comment|/* Define if you have the mkdir function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKDIR
value|1
end_define

begin_comment
comment|/* Define if you have the mktemp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKTEMP
value|1
end_define

begin_comment
comment|/* Define if you have the pathconf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PATHCONF
value|1
end_define

begin_comment
comment|/* Define if you have the raise function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RAISE
value|1
end_define

begin_comment
comment|/* Define if you have the rename function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_RENAME
value|1
end_define

begin_comment
comment|/* Define if you have the sigaction function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGACTION
value|1
end_define

begin_comment
comment|/* Define if you have the sigprocmask function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGPROCMASK
value|1
end_define

begin_comment
comment|/* Define if you have the sigsetmask function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGSETMASK
value|1
end_define

begin_comment
comment|/* Define if you have the<dirent.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
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
comment|/* Define if you have the<limits.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<ndir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_NDIR_H */
end_comment

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
comment|/* Define if you have the<sys/dir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_DIR_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/ndir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_NDIR_H */
end_comment

begin_comment
comment|/* Define if you have the<unistd.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define if you have the<utime.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UTIME_H
value|1
end_define

begin_comment
comment|/* Define if you have the<varargs.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VARARGS_H
value|1
end_define

end_unit

