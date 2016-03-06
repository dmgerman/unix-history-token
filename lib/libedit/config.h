begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* config.h.  Generated from config.h.in by configure.  */
end_comment

begin_comment
comment|/* config.h.in.  Generated from configure.ac by autoheader.  */
end_comment

begin_comment
comment|/* Define to 1 if the `closedir' function returns void instead of `int'. */
end_comment

begin_comment
comment|/* #undef CLOSEDIR_VOID */
end_comment

begin_comment
comment|/* Define to 1 if you have the<curses.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_CURSES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<dirent.h> header file, and it defines `DIR'.    */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<dlfcn.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_DLFCN_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `endpwent' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ENDPWENT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<fcntl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FCNTL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fgetln' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FGETLN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `fork' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FORK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have getpwnam_r and getpwuid_r that are draft POSIX.1    versions. */
end_comment

begin_comment
comment|/* #undef HAVE_GETPW_R_DRAFT */
end_comment

begin_comment
comment|/* Define to 1 if you have getpwnam_r and getpwuid_r that are POSIX.1    compatible. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETPW_R_POSIX
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<inttypes.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_INTTYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `isascii' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISASCII
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `issetugid' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISSETUGID
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `curses' library (-lcurses). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBCURSES */
end_comment

begin_comment
comment|/* Define to 1 if you have the `ncurses' library (-lncurses). */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBNCURSES
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `termcap' library (-ltermcap). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBTERMCAP */
end_comment

begin_comment
comment|/* Define to 1 if you have the `terminfo' library (-lterminfo). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBTERMINFO */
end_comment

begin_comment
comment|/* Define to 1 if you have the `termlib' library (-ltermlib). */
end_comment

begin_comment
comment|/* #undef HAVE_LIBTERMLIB */
end_comment

begin_comment
comment|/* Define to 1 if you have the<limits.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIMITS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<malloc.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MALLOC_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `memchr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMCHR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<memory.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `memset' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMSET
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<ncurses.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_NCURSES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<ndir.h> header file, and it defines `DIR'. */
end_comment

begin_comment
comment|/* #undef HAVE_NDIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `regcomp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_REGCOMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `re_comp' function. */
end_comment

begin_comment
comment|/* #undef HAVE_RE_COMP */
end_comment

begin_comment
comment|/* Define to 1 if `stat' has the bug that it succeeds when given the    zero-length file name argument. */
end_comment

begin_comment
comment|/* #undef HAVE_STAT_EMPTY_STRING_BUG */
end_comment

begin_comment
comment|/* Define to 1 if you have the<stdint.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDINT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<stdlib.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDLIB_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strcasecmp' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCASECMP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strchr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCHR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strcspn' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCSPN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strdup' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRDUP
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strerror' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRERROR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<strings.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRINGS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<string.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRING_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strlcat' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRLCAT
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strlcpy' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRLCPY
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strrchr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRRCHR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strstr' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRSTR
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strtol' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRTOL
value|1
end_define

begin_comment
comment|/* Define to 1 if struct dirent has member d_namlen */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_DIRENT_D_NAMLEN
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strunvis' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUNVIS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `strvis' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRVIS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/cdefs.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_CDEFS_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/dir.h> header file, and it defines `DIR'.    */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_DIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/ioctl.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_IOCTL_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/ndir.h> header file, and it defines `DIR'.    */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_NDIR_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the<sys/param.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/stat.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_STAT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<sys/types.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_TYPES_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have<sys/wait.h> that is POSIX.1 compatible. */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<termcap.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMCAP_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<term.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERM_H
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<unistd.h> header file. */
end_comment

begin_define
define|#
directive|define
name|HAVE_UNISTD_H
value|1
end_define

begin_comment
comment|/* Define to 1 if the system has the type `u_int32_t'. */
end_comment

begin_define
define|#
directive|define
name|HAVE_U_INT32_T
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `vfork' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VFORK
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the<vfork.h> header file. */
end_comment

begin_comment
comment|/* #undef HAVE_VFORK_H */
end_comment

begin_comment
comment|/* Define to 1 if you have the `vis' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_VIS
value|1
end_define

begin_comment
comment|/* Define to 1 if you have the `wcsdup' function. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCSDUP
value|1
end_define

begin_comment
comment|/* Define to 1 if `fork' works. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WORKING_FORK
value|1
end_define

begin_comment
comment|/* Define to 1 if `vfork' works. */
end_comment

begin_define
define|#
directive|define
name|HAVE_WORKING_VFORK
value|1
end_define

begin_comment
comment|/* Define to 1 if `lstat' dereferences a symlink specified with a trailing    slash. */
end_comment

begin_define
define|#
directive|define
name|LSTAT_FOLLOWS_SLASHED_SYMLINK
value|1
end_define

begin_comment
comment|/* Define to the sub-directory in which libtool stores uninstalled libraries.    */
end_comment

begin_define
define|#
directive|define
name|LT_OBJDIR
value|".libs/"
end_define

begin_comment
comment|/* Name of package */
end_comment

begin_define
define|#
directive|define
name|PACKAGE
value|"libedit-20110729"
end_define

begin_comment
comment|/* Define to the address where bug reports for this package should be sent. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_BUGREPORT
value|""
end_define

begin_comment
comment|/* Define to the full name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_NAME
value|"libedit"
end_define

begin_comment
comment|/* Define to the full name and version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_STRING
value|"libedit 3.0"
end_define

begin_comment
comment|/* Define to the one symbol short name of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_TARNAME
value|"libedit-20110729"
end_define

begin_comment
comment|/* Define to the home page for this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_URL
value|""
end_define

begin_comment
comment|/* Define to the version of this package. */
end_comment

begin_define
define|#
directive|define
name|PACKAGE_VERSION
value|"3.0"
end_define

begin_comment
comment|/* Define as the return type of signal handlers (`int' or `void'). */
end_comment

begin_define
define|#
directive|define
name|RETSIGTYPE
value|void
end_define

begin_comment
comment|/* Define to 1 if you have the ANSI C header files. */
end_comment

begin_define
define|#
directive|define
name|STDC_HEADERS
value|1
end_define

begin_comment
comment|/* Enable extensions on AIX 3, Interix.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ALL_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_ALL_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable GNU extensions on systems that have them.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_GNU_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_GNU_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable threading extensions on Solaris.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX_PTHREAD_SEMANTICS
end_ifndef

begin_define
define|#
directive|define
name|_POSIX_PTHREAD_SEMANTICS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable extensions on HP NonStop.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TANDEM_SOURCE
end_ifndef

begin_define
define|#
directive|define
name|_TANDEM_SOURCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Enable general extensions on Solaris.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__EXTENSIONS__
end_ifndef

begin_define
define|#
directive|define
name|__EXTENSIONS__
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Version number of package */
end_comment

begin_define
define|#
directive|define
name|VERSION
value|"3.0"
end_define

begin_comment
comment|/* Define to 1 if you want wide-character code */
end_comment

begin_comment
comment|/* #undef WIDECHAR */
end_comment

begin_comment
comment|/* Define to 1 if on MINIX. */
end_comment

begin_comment
comment|/* #undef _MINIX */
end_comment

begin_comment
comment|/* Define to 2 if the system does not provide POSIX.1 features except with    this defined. */
end_comment

begin_comment
comment|/* #undef _POSIX_1_SOURCE */
end_comment

begin_comment
comment|/* Define to 1 if you need to in order for `stat' and other things to work. */
end_comment

begin_comment
comment|/* #undef _POSIX_SOURCE */
end_comment

begin_comment
comment|/* Define to empty if `const' does not conform to ANSI C. */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to `int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef pid_t */
end_comment

begin_comment
comment|/* Define to `unsigned int' if<sys/types.h> does not define. */
end_comment

begin_comment
comment|/* #undef size_t */
end_comment

begin_comment
comment|/* Define as `fork' if `vfork' does not work. */
end_comment

begin_comment
comment|/* #undef vfork */
end_comment

begin_include
include|#
directive|include
file|"sys.h"
end_include

begin_undef
undef|#
directive|undef
name|SCCSID
end_undef

begin_undef
undef|#
directive|undef
name|LIBC_SCCS
end_undef

begin_undef
undef|#
directive|undef
name|lint
end_undef

begin_undef
undef|#
directive|undef
name|SIZE_T_MAX
end_undef

end_unit

