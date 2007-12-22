begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for ia64-linux target.  */
end_comment

begin_comment
comment|/* This macro is a C statement to print on `stderr' a string describing the    particular machine description choice.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (IA-64) Linux");
end_define

begin_comment
comment|/* This is for -profile to use -lc_p instead of -lc.  */
end_comment

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%{profile:-p} %{G*}"
end_define

begin_comment
comment|/* Target OS builtins.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do {						\ 	LINUX_TARGET_OS_CPP_BUILTINS();		\ 	builtin_define("_LONGLONG");		\ } while (0)
end_define

begin_comment
comment|/* Need to override linux.h STARTFILE_SPEC, since it has crtbeginT.o in.  */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LD_PIE
end_ifdef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{!shared: %{pg|p|profile:gcrt1.o%s;pie:Scrt1.o%s;:crt1.o%s}}\    crti.o%s %{shared|pie:crtbeginS.o%s;:crtbegin.o%s}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{!shared: %{pg|p|profile:gcrt1.o%s;:crt1.o%s}}\    crti.o%s %{shared|pie:crtbeginS.o%s;:crtbegin.o%s}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Similar to standard Linux, but adding -ffast-math support.  */
end_comment

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
define|\
value|"%{ffast-math|funsafe-math-optimizations:crtfastmath.o%s} \    %{shared|pie:crtendS.o%s;:crtend.o%s} crtn.o%s"
end_define

begin_comment
comment|/* Define this for shared library support because it isn't in the main    linux.h file.  */
end_comment

begin_define
define|#
directive|define
name|GLIBC_DYNAMIC_LINKER
value|"/lib/ld-linux-ia64.so.2"
end_define

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"\   %{shared:-shared} \   %{!shared: \     %{!static: \       %{rdynamic:-export-dynamic} \       %{!dynamic-linker:-dynamic-linker " LINUX_DYNAMIC_LINKER "}} \       %{static:-static}}"
end_define

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{posix:-D_POSIX_SOURCE} %{pthread:-D_REENTRANT}"
end_define

begin_define
define|#
directive|define
name|JMP_BUF_SIZE
value|76
end_define

begin_comment
comment|/* Override linux.h LINK_EH_SPEC definition.    Signalize that because we have fde-glibc, we don't need all C shared libs    linked against -lgcc_s.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_EH_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_EH_SPEC
value|""
end_define

begin_define
define|#
directive|define
name|MD_UNWIND_SUPPORT
value|"config/ia64/linux-unwind.h"
end_define

end_unit

