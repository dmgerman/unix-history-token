begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* config.h.  Generated automatically by configure.  */
end_comment

begin_comment
comment|/* config.in.  Generated automatically from configure.in by autoheader.  */
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
comment|/* Whether strerror must be declared even if<string.h> is included.  */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_STRERROR */
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
comment|/* Define if using alloca.c.  */
end_comment

begin_comment
comment|/* #undef C_ALLOCA */
end_comment

begin_comment
comment|/* Define to empty if the keyword does not work.  */
end_comment

begin_comment
comment|/* #undef const */
end_comment

begin_comment
comment|/* Define to one of _getb67, GETB67, getb67 for Cray-2 and Cray-YMP systems.    This function is required for alloca.c support on those systems.  */
end_comment

begin_comment
comment|/* #undef CRAY_STACKSEG_END */
end_comment

begin_comment
comment|/* Define if you have alloca, as a function or macro.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ALLOCA
value|1
end_define

begin_comment
comment|/* Define if you have<alloca.h> and it should be used (not on Ultrix).  */
end_comment

begin_comment
comment|/* #undef HAVE_ALLOCA_H */
end_comment

begin_comment
comment|/* Define if the `long double' type works.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LONG_DOUBLE
value|1
end_define

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
comment|/* Define as __inline if that's what the C compiler calls it.  */
end_comment

begin_comment
comment|/* #undef inline */
end_comment

begin_comment
comment|/* Define to `long' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef off_t */
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
comment|/* If using the C implementation of alloca, define if you know the    direction of stack growth for your system; otherwise it will be    automatically deduced at run-time.  STACK_DIRECTION> 0 => grows toward higher addresses  STACK_DIRECTION< 0 => grows toward lower addresses  STACK_DIRECTION = 0 => direction of growth unknown  */
end_comment

begin_comment
comment|/* #undef STACK_DIRECTION */
end_comment

begin_comment
comment|/* Define if the `S_IS*' macros in<sys/stat.h> do not work properly.  */
end_comment

begin_comment
comment|/* #undef STAT_MACROS_BROKEN */
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
comment|/* Define if ioctl argument PIOCSET is available. */
end_comment

begin_comment
comment|/* #undef HAVE_PROCFS_PIOCSET */
end_comment

begin_comment
comment|/* /proc PID entries are directories containing the files    ctl as map status */
end_comment

begin_comment
comment|/* #undef HAVE_MULTIPLE_PROC_FDS */
end_comment

begin_comment
comment|/* Define if the `long long' type works.  */
end_comment

begin_define
define|#
directive|define
name|CC_HAS_LONG_LONG
value|1
end_define

begin_comment
comment|/* Define if the "ll" format works to print long long ints. */
end_comment

begin_define
define|#
directive|define
name|PRINTF_HAS_LONG_LONG
value|1
end_define

begin_comment
comment|/* Define if the "%Lg" format works to print long doubles. */
end_comment

begin_define
define|#
directive|define
name|PRINTF_HAS_LONG_DOUBLE
value|1
end_define

begin_comment
comment|/* Define if the "%Lg" format works to scan long doubles. */
end_comment

begin_define
define|#
directive|define
name|SCANF_HAS_LONG_DOUBLE
value|1
end_define

begin_comment
comment|/* Define if using Solaris thread debugging.  */
end_comment

begin_comment
comment|/* #undef HAVE_THREAD_DB_LIB */
end_comment

begin_comment
comment|/* Define on a GNU/Linux system to work around problems in sys/procfs.h.  */
end_comment

begin_comment
comment|/* #undef START_INFERIOR_TRAPS_EXPECTED */
end_comment

begin_comment
comment|/* #undef sys_quotactl */
end_comment

begin_comment
comment|/* Define if you have HPUX threads */
end_comment

begin_comment
comment|/* #undef HAVE_HPUX_THREAD_SUPPORT */
end_comment

begin_comment
comment|/* Define if you want to use the memory mapped malloc package (mmalloc). */
end_comment

begin_comment
comment|/* #undef USE_MMALLOC */
end_comment

begin_comment
comment|/* Define if the runtime uses a routine from mmalloc before gdb has a chance    to initialize mmalloc, and we want to force checking to be used anyway.    This may cause spurious memory corruption messages if the runtime tries    to explicitly deallocate that memory when gdb calls exit. */
end_comment

begin_comment
comment|/* #undef MMCHECK_FORCE */
end_comment

begin_comment
comment|/* Define if you want to use the full-screen terminal user interface.  */
end_comment

begin_comment
comment|/* #undef TUI */
end_comment

begin_comment
comment|/* Define if<proc_service.h> on solaris uses int instead of    size_t, and assorted other type changes. */
end_comment

begin_comment
comment|/* #undef PROC_SERVICE_IS_OLD */
end_comment

begin_comment
comment|/* Set to true if the save_state_t structure is present */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_SAVE_STATE_T
value|0
end_define

begin_comment
comment|/* Set to true if the save_state_t structure has the ss_wide member */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_MEMBER_SS_WIDE
value|0
end_define

begin_comment
comment|/* Define if you have the __argz_count function.  */
end_comment

begin_comment
comment|/* #undef HAVE___ARGZ_COUNT */
end_comment

begin_comment
comment|/* Define if you have the __argz_next function.  */
end_comment

begin_comment
comment|/* #undef HAVE___ARGZ_NEXT */
end_comment

begin_comment
comment|/* Define if you have the __argz_stringify function.  */
end_comment

begin_comment
comment|/* #undef HAVE___ARGZ_STRINGIFY */
end_comment

begin_comment
comment|/* Define if you have the bcopy function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_BCOPY
value|1
end_define

begin_comment
comment|/* Define if you have the btowc function.  */
end_comment

begin_comment
comment|/* #undef HAVE_BTOWC */
end_comment

begin_comment
comment|/* Define if you have the bzero function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_BZERO
value|1
end_define

begin_comment
comment|/* Define if you have the dcgettext function.  */
end_comment

begin_comment
comment|/* #undef HAVE_DCGETTEXT */
end_comment

begin_comment
comment|/* Define if you have the getcwd function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_GETCWD
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
comment|/* Define if you have the isascii function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ISASCII
value|1
end_define

begin_comment
comment|/* Define if you have the munmap function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MUNMAP
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
comment|/* Define if you have the sbrk function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SBRK
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
comment|/* Define if you have the setlocale function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETLOCALE
value|1
end_define

begin_comment
comment|/* Define if you have the setpgid function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETPGID
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
comment|/* Define if you have the stpcpy function.  */
end_comment

begin_comment
comment|/* #undef HAVE_STPCPY */
end_comment

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
comment|/* Define if you have the strchr function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRCHR
value|1
end_define

begin_comment
comment|/* Define if you have the<argz.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_ARGZ_H */
end_comment

begin_comment
comment|/* Define if you have the<asm/debugreg.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_ASM_DEBUGREG_H */
end_comment

begin_comment
comment|/* Define if you have the<ctype.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CTYPE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<curses.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_CURSES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<endian.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_ENDIAN_H */
end_comment

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
comment|/* Define if you have the<link.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LINK_H
value|1
end_define

begin_comment
comment|/* Define if you have the<locale.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LOCALE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<malloc.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_MALLOC_H */
end_comment

begin_comment
comment|/* Define if you have the<memory.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_MEMORY_H
value|1
end_define

begin_comment
comment|/* Define if you have the<nl_types.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NL_TYPES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<objlist.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_OBJLIST_H */
end_comment

begin_comment
comment|/* Define if you have the<ptrace.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_PTRACE_H */
end_comment

begin_comment
comment|/* Define if you have the<sgtty.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SGTTY_H
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
comment|/* Define if you have the<sys/debugreg.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_DEBUGREG_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/param.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PARAM_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/procfs.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PROCFS_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/ptrace.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_PTRACE_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/reg.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_REG_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/wait.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_WAIT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<term.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERM_H
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
comment|/* Define if you have the<values.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_VALUES_H */
end_comment

begin_comment
comment|/* Define if you have the<wait.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_WAIT_H */
end_comment

begin_comment
comment|/* Define if you have the<wchar.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_WCHAR_H */
end_comment

begin_comment
comment|/* Define if you have the<wctype.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_WCTYPE_H */
end_comment

begin_comment
comment|/* Define if you have the dl library (-ldl).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBDL */
end_comment

begin_comment
comment|/* Define if you have the m library (-lm).  */
end_comment

begin_define
define|#
directive|define
name|HAVE_LIBM
value|1
end_define

begin_comment
comment|/* Define if you have the w library (-lw).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBW */
end_comment

begin_comment
comment|/* Define if you have the stpcpy function */
end_comment

begin_comment
comment|/* #undef HAVE_STPCPY */
end_comment

begin_comment
comment|/* Define if your locale.h file contains LC_MESSAGES. */
end_comment

begin_define
define|#
directive|define
name|HAVE_LC_MESSAGES
value|1
end_define

begin_comment
comment|/* Define to 1 if NLS is requested */
end_comment

begin_define
define|#
directive|define
name|ENABLE_NLS
value|1
end_define

begin_comment
comment|/* Define as 1 if you have gettext and don't want to use GNU gettext. */
end_comment

begin_comment
comment|/* #undef HAVE_GETTEXT */
end_comment

begin_comment
comment|/* Define if malloc is not declared in system header files. */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_MALLOC */
end_comment

begin_comment
comment|/* Define if realloc is not declared in system header files. */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_REALLOC */
end_comment

begin_comment
comment|/* Define if free is not declared in system header files. */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_FREE */
end_comment

begin_comment
comment|/* Define if strerror is not declared in system header files. */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_STRERROR */
end_comment

begin_comment
comment|/* Define if strdup is not declared in system header files. */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_STRDUP */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has pstatus_t. */
end_comment

begin_comment
comment|/* #undef HAVE_PSTATUS_T */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has prrun_t. */
end_comment

begin_comment
comment|/* #undef HAVE_PRRUN_T */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has gregset_t. */
end_comment

begin_define
define|#
directive|define
name|HAVE_GREGSET_T
value|1
end_define

begin_comment
comment|/* Define if<sys/procfs.h> has fpregset_t. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FPREGSET_T
value|1
end_define

end_unit

