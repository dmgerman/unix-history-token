begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* XXX */
end_comment

begin_comment
comment|/*  * This file was derived from source obtained from NetBSD/Alpha which  * is publicly available for ftp. The patch was developed by cgd@netbsd.org  * during the time he worked at CMU. He claims that CMU own this patch  * to gcc and that they have not (and will not) release the patch for  * incorporation in FSF sources. We are supposedly able to use the patch,  * but we are not allowed to forward it back to FSF for inclusion in  * their source releases.  *  * This all has me (jb@freebsd.org) confused because (a) I see no copyright  * messages that tell me that use is restricted; and (b) I expected that  * the patch was originally developed from other files which are subject  * to GPL.  *  * Use of this file is restricted until its CMU ownership is tested.  */
end_comment

begin_include
include|#
directive|include
file|"alpha/alpha.h"
end_include

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|32
end_define

begin_comment
comment|/* FreeBSD-specific things: */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-D__FreeBSD__ -D__alpha__ -D__alpha"
end_define

begin_comment
comment|/* Look for the include files in the system-defined places.  */
end_comment

begin_undef
undef|#
directive|undef
name|GPLUSPLUS_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|GPLUSPLUS_INCLUDE_DIR
value|"/usr/include/g++"
end_define

begin_undef
undef|#
directive|undef
name|GCC_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|GCC_INCLUDE_DIR
value|"/usr/include"
end_define

begin_undef
undef|#
directive|undef
name|INCLUDE_DEFAULTS
end_undef

begin_define
define|#
directive|define
name|INCLUDE_DEFAULTS
define|\
value|{                                     \     { GPLUSPLUS_INCLUDE_DIR, 1, 1 },    \     { GCC_INCLUDE_DIR, 0, 0 },          \     { 0, 0, 0 }                         \   }
end_define

begin_comment
comment|/* Under FreeBSD, the normal location of the `ld' and `as' programs is the    /usr/bin directory.  */
end_comment

begin_undef
undef|#
directive|undef
name|MD_EXEC_PREFIX
end_undef

begin_define
define|#
directive|define
name|MD_EXEC_PREFIX
value|"/usr/bin/"
end_define

begin_comment
comment|/* Under FreeBSD, the normal location of the various *crt*.o files is the    /usr/lib directory.  */
end_comment

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_define
define|#
directive|define
name|MD_STARTFILE_PREFIX
value|"/usr/lib/"
end_define

begin_comment
comment|/* Provide a CPP_SPEC appropriate for FreeBSD.  Current we just deal with    the GCC option `-posix'.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{posix:-D_POSIX_SOURCE}"
end_define

begin_comment
comment|/* Provide an ASM_SPEC appropriate for FreeBSD. */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|" %|"
end_define

begin_undef
undef|#
directive|undef
name|ASM_FINAL_SPEC
end_undef

begin_comment
comment|/* Provide a LIB_SPEC appropriate for FreeBSD.  Just select the appropriate    libc, depending on whether we're doing profiling.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{!shared:%{!pg:%{!pthread:-lc}%{pthread:-lpthread -lc}}%{pg:%{!pthread:-lc_p}%{pthread:-lpthread_p -lc_p}}}"
end_define

begin_comment
comment|/* Provide a LINK_SPEC appropriate for FreeBSD.  Here we provide support    for the special GCC options -static, -assert, and -nostdlib.  */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
define|\
value|"%{!nostdlib:%{!r*:%{!e*:-e __start}}} -dc -dp %{static:-Bstatic} %{assert*}"
end_define

begin_comment
comment|/* Output assembler code to FILE to increment profiler label # LABELNO    for profiling a function entry.  Under FreeBSD/Alpha, the assembler does    nothing special with -pg. */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER
end_undef

begin_define
define|#
directive|define
name|FUNCTION_PROFILER
parameter_list|(
name|FILE
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|fputs ("\tjsr $28,_mcount\n", (FILE));
end_define

begin_comment
comment|/* at */
end_comment

begin_comment
comment|/* Show that we need a GP when profiling.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_PROFILING_NEEDS_GP
end_define

begin_define
define|#
directive|define
name|bsd4_4
end_define

begin_undef
undef|#
directive|undef
name|HAS_INIT_SECTION
end_undef

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

end_unit

