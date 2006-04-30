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
comment|/* Define if you have<vfork.h>.  */
end_comment

begin_comment
comment|/* #undef HAVE_VFORK_H */
end_comment

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
comment|/* Define to `int' if<sys/types.h> doesn't define.  */
end_comment

begin_comment
comment|/* #undef pid_t */
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
comment|/* Define if the `setpgrp' function takes no argument.  */
end_comment

begin_comment
comment|/* #undef SETPGRP_VOID */
end_comment

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
comment|/* Define vfork as fork if vfork does not work.  */
end_comment

begin_comment
comment|/* #undef vfork */
end_comment

begin_comment
comment|/* Define if compiling on Solaris 7. */
end_comment

begin_comment
comment|/* #undef _MSE_INT_H */
end_comment

begin_comment
comment|/* Define if your struct reg has r_fs.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_REG_R_FS
value|1
end_define

begin_comment
comment|/* Define if your struct reg has r_gs.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_REG_R_GS
value|1
end_define

begin_comment
comment|/* Define if<link.h> exists and defines struct link_map which has    members with an ``l_'' prefix.  (For Solaris, SVR4, and    SVR4-like systems.) */
end_comment

begin_define
define|#
directive|define
name|HAVE_STRUCT_LINK_MAP_WITH_L_MEMBERS
value|1
end_define

begin_comment
comment|/* Define if<link.h> exists and defines struct link_map which has   members with an ``lm_'' prefix.  (For SunOS.)  */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_LINK_MAP_WITH_LM_MEMBERS */
end_comment

begin_comment
comment|/* Define if<link.h> exists and defines a struct so_map which has   members with an ``som_'' prefix.  (Found on older *BSD systems.)  */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_SO_MAP_WITH_SOM_MEMBERS */
end_comment

begin_comment
comment|/* Define if<sys/link.h> has struct link_map32 */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_LINK_MAP32 */
end_comment

begin_comment
comment|/* Define if the prfpregset_t type is broken. */
end_comment

begin_comment
comment|/* #undef PRFPREGSET_T_BROKEN */
end_comment

begin_comment
comment|/* Define if you want to use new multi-fd /proc interface    (replaces HAVE_MULTIPLE_PROC_FDS as well as other macros). */
end_comment

begin_comment
comment|/* #undef NEW_PROC_API */
end_comment

begin_comment
comment|/* Define if ioctl argument PIOCSET is available. */
end_comment

begin_comment
comment|/* #undef HAVE_PROCFS_PIOCSET */
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
comment|/* Define if<proc_service.h> on solaris uses int instead of    size_t, and assorted other type changes. */
end_comment

begin_comment
comment|/* #undef PROC_SERVICE_IS_OLD */
end_comment

begin_comment
comment|/* If you want to specify a default CPU variant, define this to be its    name, as a C string.  */
end_comment

begin_comment
comment|/* #undef TARGET_CPU_DEFAULT */
end_comment

begin_comment
comment|/* Define if the simulator is being linked in.  */
end_comment

begin_comment
comment|/* #undef WITH_SIM */
end_comment

begin_comment
comment|/* Set to true if the save_state_t structure is present */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_SAVE_STATE_T */
end_comment

begin_comment
comment|/* Set to true if the save_state_t structure has the ss_wide member */
end_comment

begin_comment
comment|/* #undef HAVE_STRUCT_MEMBER_SS_WIDE */
end_comment

begin_comment
comment|/* Define if<sys/ptrace.h> defines the PTRACE_GETREGS request.  */
end_comment

begin_comment
comment|/* #undef HAVE_PTRACE_GETREGS */
end_comment

begin_comment
comment|/* Define if<sys/ptrace.h> defines the PTRACE_GETFPXREGS request.  */
end_comment

begin_comment
comment|/* #undef HAVE_PTRACE_GETFPXREGS */
end_comment

begin_comment
comment|/* Define if<sys/ptrace.h> defines the PT_GETDBREGS request.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_PT_GETDBREGS
value|1
end_define

begin_comment
comment|/* Define if<sys/ptrace.h> defines the PT_GETXMMREGS request.  */
end_comment

begin_comment
comment|/* #undef HAVE_PT_GETXMMREGS */
end_comment

begin_comment
comment|/* Define if gnu-regex.c included with GDB should be used. */
end_comment

begin_define
define|#
directive|define
name|USE_INCLUDED_REGEX
value|1
end_define

begin_comment
comment|/* BFD's default architecture. */
end_comment

begin_comment
comment|/* #define DEFAULT_BFD_ARCH bfd_alpha_arch */
end_comment

begin_comment
comment|/* BFD's default target vector. */
end_comment

begin_comment
comment|/* #define DEFAULT_BFD_VEC bfd_elf64_alpha_vec */
end_comment

begin_comment
comment|/* Multi-arch enabled. */
end_comment

begin_comment
comment|/* #undef GDB_MULTI_ARCH */
end_comment

begin_comment
comment|/* hostfile */
end_comment

begin_comment
comment|/* #define GDB_XM_FILE 1 */
end_comment

begin_comment
comment|/* targetfile */
end_comment

begin_define
define|#
directive|define
name|GDB_TM_FILE
value|1
end_define

begin_comment
comment|/* nativefile */
end_comment

begin_define
define|#
directive|define
name|GDB_NM_FILE
value|1
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
comment|/* Define if you have the canonicalize_file_name function.  */
end_comment

begin_comment
comment|/* #undef HAVE_CANONICALIZE_FILE_NAME */
end_comment

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
comment|/* Define if you have the poll function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_POLL
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
comment|/* Define if you have the realpath function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_REALPATH
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
comment|/* Define if you have the setpgrp function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SETPGRP
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
comment|/* Define if you have the socketpair function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SOCKETPAIR
value|1
end_define

begin_comment
comment|/* Define if you have the stpcpy function.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STPCPY
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
comment|/* Define if you have the<dirent.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_DIRENT_H
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
comment|/* Define if you have the<ncurses.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NCURSES_H
value|1
end_define

begin_comment
comment|/* Define if you have the<ndir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_NDIR_H */
end_comment

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
comment|/* Define if you have the<nlist.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_NLIST_H
value|1
end_define

begin_comment
comment|/* Define if you have the<objlist.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_OBJLIST_H */
end_comment

begin_comment
comment|/* Define if you have the<poll.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_POLL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<proc_service.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_PROC_SERVICE_H */
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
comment|/* Define if you have the<stdint.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_STDINT_H
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
comment|/* Define if you have the<sys/dir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_DIR_H */
end_comment

begin_comment
comment|/* Define if you have the<sys/fault.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_FAULT_H */
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
comment|/* Define if you have the<sys/filio.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_FILIO_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/ioctl.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_IOCTL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/ndir.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_SYS_NDIR_H */
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
comment|/* Define if you have the<sys/poll.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_POLL_H
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
comment|/* Define if you have the<sys/select.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SELECT_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/syscall.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_SYSCALL_H
value|1
end_define

begin_comment
comment|/* Define if you have the<sys/user.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SYS_USER_H
value|1
end_define

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
comment|/* Define if you have the<thread_db.h> header file.  */
end_comment

begin_comment
comment|/* #undef HAVE_THREAD_DB_H */
end_comment

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

begin_define
define|#
directive|define
name|HAVE_WCHAR_H
value|1
end_define

begin_comment
comment|/* Define if you have the<wctype.h> header file.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_WCTYPE_H
value|1
end_define

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
comment|/* Define if you have the socket library (-lsocket).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBSOCKET */
end_comment

begin_comment
comment|/* Define if you have the w library (-lw).  */
end_comment

begin_comment
comment|/* #undef HAVE_LIBW */
end_comment

begin_comment
comment|/* Define if you have the stpcpy function */
end_comment

begin_define
define|#
directive|define
name|HAVE_STPCPY
value|1
end_define

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

begin_comment
comment|/* #define ENABLE_NLS 1 */
end_comment

begin_comment
comment|/* Define as 1 if you have gettext and don't want to use GNU gettext. */
end_comment

begin_comment
comment|/* #undef HAVE_GETTEXT */
end_comment

begin_comment
comment|/* Define if sigsetjmp is available.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_SIGSETJMP
value|1
end_define

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
comment|/* Define if strstr is not declared in system header files. */
end_comment

begin_comment
comment|/* #undef NEED_DECLARATION_STRSTR */
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

begin_ifndef
ifndef|#
directive|ifndef
name|CROSS_COMPILE
end_ifndef

begin_define
define|#
directive|define
name|HAVE_GREGSET_T
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Define if<sys/procfs.h> has fpregset_t. */
end_comment

begin_define
define|#
directive|define
name|HAVE_FPREGSET_T
value|1
end_define

begin_comment
comment|/* Define if<sys/procfs.h> has prgregset_t. */
end_comment

begin_comment
comment|/* #undef HAVE_PRGREGSET_T */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has prfpregset_t. */
end_comment

begin_define
define|#
directive|define
name|HAVE_PRFPREGSET_T
value|1
end_define

begin_comment
comment|/* Define if<sys/procfs.h> has prgregset32_t. */
end_comment

begin_comment
comment|/* #undef HAVE_PRGREGSET32_T */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has prfpregset32_t. */
end_comment

begin_comment
comment|/* #undef HAVE_PRFPREGSET32_T */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has lwpid_t. */
end_comment

begin_comment
comment|/* #undef HAVE_LWPID_T */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has psaddr_t. */
end_comment

begin_comment
comment|/* #undef HAVE_PSADDR_T */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has prsysent_t. */
end_comment

begin_comment
comment|/* #undef HAVE_PRSYSENT_T */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has pr_sigset_t. */
end_comment

begin_comment
comment|/* #undef HAVE_PR_SIGSET_T */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has pr_sigaction64_t. */
end_comment

begin_comment
comment|/* #undef HAVE_PR_SIGACTION64_T */
end_comment

begin_comment
comment|/* Define if<sys/procfs.h> has pr_siginfo64_t. */
end_comment

begin_comment
comment|/* #undef HAVE_PR_SIGINFO64_T */
end_comment

end_unit

