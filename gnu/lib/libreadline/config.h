begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* Define if on MINIX.  */
end_comment

begin_comment
comment|/* #undef _MINIX */
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
comment|/* Define if the `S_IS*' macros in<sys/stat.h> do not work properly.  */
end_comment

begin_comment
comment|/* #undef STAT_MACROS_BROKEN */
end_comment

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
value|1
end_define

begin_comment
comment|/* Define if you have the lstat function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LSTAT
value|1
end_define

begin_comment
comment|/* Define if you have the memmove function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMMOVE
value|1
end_define

begin_comment
comment|/* Define if you have the putenv function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PUTENV
value|1
end_define

begin_comment
comment|/* Define if you have the select function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SELECT
value|1
end_define

begin_comment
comment|/* Define if you have the setenv function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETENV
value|1
end_define

begin_comment
comment|/* Define if you have the strcasecmp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCASECMP
value|1
end_define

begin_comment
comment|/* Define if you have the setlocale function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLOCALE
value|1
end_define

begin_comment
comment|/* Define if you have the tcgetattr function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TCGETATTR
value|1
end_define

begin_comment
comment|/* Define if you have the strcoll function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCOLL
value|1
end_define

begin_comment
comment|/* #undef STRCOLL_BROKEN */
end_comment

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
comment|/* Define if you have the<ndir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_NDIR_H */
end_comment

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
comment|/* Define if you have the<sys/dir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_DIR_H */
end_comment

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
comment|/* Define if you have the<sys/ndir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_NDIR_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/pte.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PTE_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/ptem.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_PTEM_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/select.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SELECT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/stream.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_STREAM_H */
end_comment

begin_comment
comment|/* Define if you have the<termcap.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMCAP_H
value|1
end_define

begin_comment
comment|/* Define if you have the<termio.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_TERMIO_H */
end_comment

begin_comment
comment|/* Define if you have the<termios.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIOS_H
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

begin_comment
comment|/* Define if you have the<varargs.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VARARGS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<stdarg.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDARG_H
value|1
end_define

begin_define
define|#
directive|define
name|HAVE_LOCALE_H
value|1
end_define

begin_comment
comment|/* Definitions pulled in from aclocal.m4. */
end_comment

begin_define
define|#
directive|define
name|VOID_SIGHANDLER
value|1
end_define

begin_define
define|#
directive|define
name|GWINSZ_IN_SYS_IOCTL
value|1
end_define

begin_define
define|#
directive|define
name|STRUCT_WINSIZE_IN_SYS_IOCTL
value|1
end_define

begin_comment
comment|/* #undef STRUCT_WINSIZE_IN_TERMIOS */
end_comment

begin_define
define|#
directive|define
name|TIOCSTAT_IN_SYS_IOCTL
value|1
end_define

begin_define
define|#
directive|define
name|FIONREAD_IN_SYS_IOCTL
value|1
end_define

begin_comment
comment|/* #undef SPEED_T_IN_SYS_TYPES */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPW_DECLS
value|1
end_define

begin_define
define|#
directive|define
name|STRUCT_DIRENT_HAS_D_INO
value|1
end_define

begin_define
define|#
directive|define
name|STRUCT_DIRENT_HAS_D_FILENO
value|1
end_define

begin_comment
comment|/* #undef HAVE_BSD_SIGNALS */
end_comment

begin_define
define|#
directive|define
name|HAVE_POSIX_SIGNALS
value|1
end_define

begin_comment
comment|/* #undef HAVE_USG_SIGHOLD */
end_comment

begin_comment
comment|/* #undef MUST_REINSTALL_SIGHANDLERS */
end_comment

begin_define
define|#
directive|define
name|HAVE_POSIX_SIGSETJMP
value|1
end_define

begin_comment
comment|/* config.h.bot */
end_comment

begin_comment
comment|/* modify settings or make new ones based on what autoconf tells us. */
end_comment

begin_comment
comment|/* Ultrix botches type-ahead when switching from canonical to    non-canonical mode, at least through version 4.3 */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_TERMIOS_H
argument_list|)
operator|||
operator|!
name|defined
argument_list|(
name|HAVE_TCGETATTR
argument_list|)
operator|||
name|defined
argument_list|(
name|ultrix
argument_list|)
end_if

begin_define
define|#
directive|define
name|TERMIOS_MISSING
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STRCOLL_BROKEN
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_STRCOLL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|HAVE_STDARG_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|PREFER_STDARG
end_define

begin_define
define|#
directive|define
name|USE_VARARGS
end_define

begin_else
else|#
directive|else
end_else

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_VARARGS_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|PREFER_VARARGS
end_define

begin_define
define|#
directive|define
name|USE_VARARGS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

