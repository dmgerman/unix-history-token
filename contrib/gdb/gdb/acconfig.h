begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Define if compiling on Solaris 7. */
end_comment

begin_undef
undef|#
directive|undef
name|_MSE_INT_H
end_undef

begin_comment
comment|/* Define if pstatus_t type is available */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PSTATUS_T
end_undef

begin_comment
comment|/* Define if prrun_t type is available */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PRRUN_T
end_undef

begin_comment
comment|/* Define if fpregset_t type is available. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_FPREGSET_T
end_undef

begin_comment
comment|/* Define if gregset_t type is available. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GREGSET_T
end_undef

begin_comment
comment|/* Define if<sys/procfs.h> has prgregset_t. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PRGREGSET_T
end_undef

begin_comment
comment|/* Define if<sys/procfs.h> has prfpregset_t. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PRFPREGSET_T
end_undef

begin_comment
comment|/* Define if<sys/procfs.h> has lwpid_t. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_LWPID_T
end_undef

begin_comment
comment|/* Define if<sys/procfs.h> has psaddr_t. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PSADDR_T
end_undef

begin_comment
comment|/* Define if the prfpregset_t type is broken. */
end_comment

begin_undef
undef|#
directive|undef
name|PRFPREGSET_T_BROKEN
end_undef

begin_comment
comment|/* Define if you want to use new multi-fd /proc interface    (replaces HAVE_MULTIPLE_PROC_FDS as well as other macros). */
end_comment

begin_undef
undef|#
directive|undef
name|NEW_PROC_API
end_undef

begin_comment
comment|/* Define if ioctl argument PIOCSET is available. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PROCFS_PIOCSET
end_undef

begin_comment
comment|/* Define if the `long long' type works.  */
end_comment

begin_undef
undef|#
directive|undef
name|CC_HAS_LONG_LONG
end_undef

begin_comment
comment|/* Define if the "ll" format works to print long long ints. */
end_comment

begin_undef
undef|#
directive|undef
name|PRINTF_HAS_LONG_LONG
end_undef

begin_comment
comment|/* Define if the "%Lg" format works to print long doubles. */
end_comment

begin_undef
undef|#
directive|undef
name|PRINTF_HAS_LONG_DOUBLE
end_undef

begin_comment
comment|/* Define if the "%Lg" format works to scan long doubles. */
end_comment

begin_undef
undef|#
directive|undef
name|SCANF_HAS_LONG_DOUBLE
end_undef

begin_comment
comment|/* Define if using Solaris thread debugging.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_THREAD_DB_LIB
end_undef

begin_comment
comment|/* Define on a GNU/Linux system to work around problems in sys/procfs.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|START_INFERIOR_TRAPS_EXPECTED
end_undef

begin_undef
undef|#
directive|undef
name|sys_quotactl
end_undef

begin_comment
comment|/* Define if you have HPUX threads */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_HPUX_THREAD_SUPPORT
end_undef

begin_comment
comment|/* Define if you want to use the memory mapped malloc package (mmalloc). */
end_comment

begin_undef
undef|#
directive|undef
name|USE_MMALLOC
end_undef

begin_comment
comment|/* Define if the runtime uses a routine from mmalloc before gdb has a chance    to initialize mmalloc, and we want to force checking to be used anyway.    This may cause spurious memory corruption messages if the runtime tries    to explicitly deallocate that memory when gdb calls exit. */
end_comment

begin_undef
undef|#
directive|undef
name|MMCHECK_FORCE
end_undef

begin_comment
comment|/* Define to 1 if NLS is requested.  */
end_comment

begin_undef
undef|#
directive|undef
name|ENABLE_NLS
end_undef

begin_comment
comment|/* Define as 1 if you have catgets and don't want to use GNU gettext.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_CATGETS
end_undef

begin_comment
comment|/* Define as 1 if you have gettext and don't want to use GNU gettext.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GETTEXT
end_undef

begin_comment
comment|/* Define as 1 if you have the stpcpy function.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_STPCPY
end_undef

begin_comment
comment|/* Define if your locale.h file contains LC_MESSAGES.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_LC_MESSAGES
end_undef

begin_comment
comment|/* Define if you want to use the full-screen terminal user interface.  */
end_comment

begin_undef
undef|#
directive|undef
name|TUI
end_undef

begin_comment
comment|/* Define if<proc_service.h> on solaris uses int instead of    size_t, and assorted other type changes. */
end_comment

begin_undef
undef|#
directive|undef
name|PROC_SERVICE_IS_OLD
end_undef

begin_comment
comment|/* If you want to specify a default CPU variant, define this to be its    name, as a C string.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_CPU_DEFAULT
end_undef

begin_comment
comment|/* Define if the simulator is being linked in.  */
end_comment

begin_undef
undef|#
directive|undef
name|WITH_SIM
end_undef

begin_comment
comment|/* Set to true if the save_state_t structure is present */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_STRUCT_SAVE_STATE_T
end_undef

begin_comment
comment|/* Set to true if the save_state_t structure has the ss_wide member */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_STRUCT_MEMBER_SS_WIDE
end_undef

begin_comment
comment|/* Define if<sys/ptrace.h> defines the PTRACE_GETREGS request.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PTRACE_GETREGS
end_undef

begin_comment
comment|/* Define if<sys/ptrace.h> defines the PTRACE_GETXFPREGS request.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PTRACE_GETXFPREGS
end_undef

end_unit

