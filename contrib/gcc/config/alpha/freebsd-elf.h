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
file|"alpha/freebsd.h"
end_include

begin_include
include|#
directive|include
file|"alpha/elf.h"
end_include

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (FreeBSD/alpha ELF)");
end_define

begin_undef
undef|#
directive|undef
name|SDB_DEBUGGING_INFO
end_undef

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_undef
undef|#
directive|undef
name|DBS_DEBUGGING_INFO
end_undef

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
define|\
value|((len> 1&& !strncmp (str, "gsdb", len)) ? SDB_DEBUG : DBX_DEBUG)
end_define

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-Dunix -D__alpha -D__alpha__ -D__ELF__ -D__FreeBSD__=3 -Asystem(unix) -Asystem(FreeBSD) -Acpu(alpha) -Amachine(alpha)"
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
value|"-m elf64alpha					\   %{O*:-O3} %{!O*:-O1}						\   %{assert*}							\   %{shared:-shared}						\   %{!shared:							\     -dc -dp							\     %{!nostdlib:%{!r*:%{!e*:-e _start}}}			\     %{!static:							\       %{rdynamic:-export-dynamic}				\       %{!dynamic-linker:-dynamic-linker /usr/libexec/ld-elf.so.1}} \     %{static:-static}}"
end_define

begin_comment
comment|/* Provide a STARTFILE_SPEC for FreeBSD that is compatible with the    non-aout version used on i386. */
end_comment

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
define|\
value|"%{!shared: %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} %{!p:crt1.o%s}}} \     %{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}"
end_define

begin_comment
comment|/* Provide a ENDFILE_SPEC appropriate for FreeBSD.  Here we tack on    the file which provides part of the support for getting C++    file-scope static object deconstructed after exiting `main' */
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
value|"%{!shared:crtend.o%s} %{shared:crtendS.o%s}"
end_define

begin_comment
comment|/* Handle #pragma weak and #pragma pack.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
end_define

begin_undef
undef|#
directive|undef
name|SET_ASM_OP
end_undef

begin_define
define|#
directive|define
name|SET_ASM_OP
value|".set"
end_define

end_unit

