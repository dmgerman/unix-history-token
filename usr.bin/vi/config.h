begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated automatically from configure.in by autoheader.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Define to empty if the keyword does not work.  */
end_comment

begin_comment
comment|/* #undef const */
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
comment|/* Define if your struct stat has st_blksize.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ST_BLKSIZE
value|1
end_define

begin_comment
comment|/* Define if you have<vfork.h>.  */
end_comment

begin_comment
comment|/* #undef HAVE_VFORK_H */
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
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

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
comment|/* Define if your<sys/time.h> declares struct tm.  */
end_comment

begin_comment
comment|/* #undef TM_IN_SYS_TIME */
end_comment

begin_comment
comment|/* Define vfork as fork if vfork does not work.  */
end_comment

begin_comment
comment|/* #undef vfork */
end_comment

begin_comment
comment|/* Define if your processor stores words with the most significant    byte first (like Motorola and SPARC, unlike Intel and VAX).  */
end_comment

begin_comment
comment|/* #undef WORDS_BIGENDIAN */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef ssize_t */
end_comment

begin_comment
comment|/* Define if you want a debugging version. */
end_comment

begin_comment
comment|/* #undef DEBUG */
end_comment

begin_comment
comment|/* Define if you have a System V-style (broken) gettimeofday. */
end_comment

begin_comment
comment|/* #undef HAVE_BROKEN_GETTIMEOFDAY */
end_comment

begin_comment
comment|/* Define if you have a Ultrix-style (broken) vdisable. */
end_comment

begin_comment
comment|/* #undef HAVE_BROKEN_VDISABLE */
end_comment

begin_comment
comment|/* Define if you have a BSD version of curses. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYSV_CURSES
end_ifndef

begin_define
define|#
directive|define
name|HAVE_BSD_CURSES
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if you have the curses(3) addnstr function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CURSES_ADDNSTR
value|1
end_define

begin_comment
comment|/* Define if you have the curses(3) beep function. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV_CURSES
end_ifdef

begin_define
define|#
directive|define
name|HAVE_CURSES_BEEP
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if you have the curses(3) flash function. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV_CURSES
end_ifdef

begin_define
define|#
directive|define
name|HAVE_CURSES_FLASH
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if you have the curses(3) idlok function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CURSES_IDLOK
value|1
end_define

begin_comment
comment|/* Define if you have the curses(3) keypad function. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV_CURSES
end_ifdef

begin_define
define|#
directive|define
name|HAVE_CURSES_KEYPAD
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if you have the curses(3) newterm function. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV_CURSES
end_ifdef

begin_define
define|#
directive|define
name|HAVE_CURSES_NEWTERM
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if you have the curses(3) setupterm function. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV_CURSES
end_ifdef

begin_define
define|#
directive|define
name|HAVE_CURSES_SETUPTERM
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if you have the curses(3) tigetstr/tigetnum functions. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SYSV_CURSES
end_ifdef

begin_define
define|#
directive|define
name|HAVE_CURSES_TIGETSTR
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if you have the chsize(2) system call. */
end_comment

begin_comment
comment|/* #undef HAVE_FTRUNCATE_CHSIZE */
end_comment

begin_comment
comment|/* Define if you have the ftruncate(2) system call. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FTRUNCATE_FTRUNCATE
value|1
end_define

begin_comment
comment|/* Define if you have fcntl(2) style locking. */
end_comment

begin_comment
comment|/* #undef HAVE_LOCK_FCNTL */
end_comment

begin_comment
comment|/* Define if you have flock(2) style locking. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOCK_FLOCK
value|1
end_define

begin_comment
comment|/* Define if you want to compile in the Perl interpreter. */
end_comment

begin_comment
comment|/* #undef HAVE_PERL_INTERP */
end_comment

begin_comment
comment|/* XXX: SET IN Makefile CFLAGS */
end_comment

begin_comment
comment|/* Define if your Perl is at least 5.003_01. */
end_comment

begin_comment
comment|/* #undef HAVE_PERL_5_003_01 */
end_comment

begin_comment
comment|/* XXX: SET IN Makefile CFLAGS */
end_comment

begin_comment
comment|/* Define if you have the Berkeley style revoke(2) system call. */
end_comment

begin_define
define|#
directive|define
name|HAVE_REVOKE
value|1
end_define

begin_comment
comment|/* Define if you have<sys/mman.h> */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_MMAN_H
value|1
end_define

begin_comment
comment|/* Define if you have<sys/select.h> */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_SELECT_H 1 */
end_comment

begin_comment
comment|/* Define if you have the System V style pty calls. */
end_comment

begin_comment
comment|/* #undef HAVE_SYS5_PTY */
end_comment

begin_comment
comment|/* Define if you want to compile in the Tcl interpreter. */
end_comment

begin_comment
comment|/* #define HAVE_TCL_INTERP */
end_comment

begin_comment
comment|/* XXX: SET IN Makefile CFLAGS */
end_comment

begin_comment
comment|/* Define if your sprintf returns a pointer, not a length. */
end_comment

begin_comment
comment|/* #undef SPRINTF_RET_CHARPNT */
end_comment

begin_comment
comment|/* Define if you have the bsearch function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_BSEARCH
value|1
end_define

begin_comment
comment|/* Define if you have the gethostname function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETHOSTNAME
value|1
end_define

begin_comment
comment|/* Define if you have the getopt function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETOPT
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
comment|/* Define if you have the memchr function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMCHR
value|1
end_define

begin_comment
comment|/* Define if you have the memcpy function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMCPY
value|1
end_define

begin_comment
comment|/* Define if you have the memmove function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMMOVE
value|1
end_define

begin_comment
comment|/* Define if you have the memset function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMSET
value|1
end_define

begin_comment
comment|/* Define if you have the mkstemp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MKSTEMP
value|1
end_define

begin_comment
comment|/* Define if you have the mmap function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MMAP
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
comment|/* Define if you have the snprintf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SNPRINTF
value|1
end_define

begin_comment
comment|/* Define if you have the strdup function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_comment
comment|/* Define if you have the strerror function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* Define if you have the strpbrk function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRPBRK
value|1
end_define

begin_comment
comment|/* Define if you have the strsep function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSEP
value|1
end_define

begin_comment
comment|/* Define if you have the strtol function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOL
value|1
end_define

begin_comment
comment|/* Define if you have the strtoul function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOUL
value|1
end_define

begin_comment
comment|/* Define if you have the unsetenv function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNSETENV
value|1
end_define

begin_comment
comment|/* Define if you have the valloc function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VALLOC
value|1
end_define

begin_comment
comment|/* Define if you have the vsnprintf function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_VSNPRINTF
value|1
end_define

end_unit

