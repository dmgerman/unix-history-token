begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for BeOS.    Copyright (C) 1997, 2000, 2001, 2002 Free Software Foundation, Inc.    Contributed by Fred Fish (fnf@cygnus.com), based on aix41.h    from David Edelsohn (edelsohn@npac.syr.edu).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (BeOS/PowerPC)");
end_define

begin_comment
comment|/* Enable AIX XL compiler calling convention breakage compatibility.  */
end_comment

begin_define
define|#
directive|define
name|MASK_XL_CALL
value|0x40000000
end_define

begin_define
define|#
directive|define
name|TARGET_XL_CALL
value|(target_flags& MASK_XL_CALL)
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_SWITCHES
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_SWITCHES
define|\
value|{"xl-call", 		MASK_XL_CALL,					\    N_("Always pass floating-point arguments in memory") },		\   {"no-xl-call",	- MASK_XL_CALL,					\    N_("Don't always pass floating-point arguments in memory") },	\   {"threads",		0},						\   {"pe",		0},
end_define

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"-u %(asm_cpu)"
end_define

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_comment
comment|/* __POWERPC__ must be defined for some header files */
end_comment

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-D__BEOS__ -D__POWERPC__ -Asystem=beos -Acpu=powerpc -Amachine=powerpc"
end_define

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{posix: -D_POSIX_SOURCE} %(cpp_cpu)"
end_define

begin_undef
undef|#
directive|undef
name|CPP_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_DEFAULT_SPEC
value|"-D_ARCH_PPC"
end_define

begin_comment
comment|/* This is the easiest way to disable use of gcc's builtin alloca,    which in the current BeOS release (DR9) is a problem because of the    relatively low default stack size of 256K with no way to expand it.    So anything we compile for the BeOS target should not use the    builtin alloca.  This also has the unwanted side effect of    disabling all builtin functions though.  */
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
value|"%{!fbuiltin: -fno-builtin}"
end_define

begin_undef
undef|#
directive|undef
name|CC1PLUS_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1PLUS_SPEC
value|"%{!fbuiltin: -fno-builtin}"
end_define

begin_undef
undef|#
directive|undef
name|ASM_DEFAULT_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_DEFAULT_SPEC
value|"-mppc"
end_define

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_POWERPC | MASK_NEW_MNEMONICS)
end_define

begin_undef
undef|#
directive|undef
name|PROCESSOR_DEFAULT
end_undef

begin_define
define|#
directive|define
name|PROCESSOR_DEFAULT
value|PROCESSOR_PPC603
end_define

begin_comment
comment|/* Define this macro as a C expression for the initializer of an    array of string to tell the driver program which options are    defaults for this target and thus do not need to be handled    specially when using `MULTILIB_OPTIONS'.     Do not define this macro if `MULTILIB_OPTIONS' is not defined in    the target makefile fragment or if none of the options listed in    `MULTILIB_OPTIONS' are set by default.  *Note Target Fragment::.  */
end_comment

begin_undef
undef|#
directive|undef
name|MULTILIB_DEFAULTS
end_undef

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "mcpu=powerpc" }
end_define

begin_comment
comment|/* These empty definitions get rid of the attempt to link in crt0.o    and any libraries like libc.a.    On BeOS the ld executable is actually a linker front end that first runs    the GNU linker with the -r option to generate a relocatable XCOFF output    file, and then runs Metrowork's linker (mwld) to generate a fully linked    executable.  */
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
value|""
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
value|""
end_define

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|""
end_define

begin_comment
comment|/* Text to write out after a CALL that may be replaced by glue code by    the loader.  */
end_comment

begin_undef
undef|#
directive|undef
name|RS6000_CALL_GLUE
end_undef

begin_define
define|#
directive|define
name|RS6000_CALL_GLUE
value|"cror 15,15,15"
end_define

begin_comment
comment|/* Struct alignments are done on 4 byte boundaries for all types.  */
end_comment

begin_undef
undef|#
directive|undef
name|BIGGEST_FIELD_ALIGNMENT
end_undef

begin_define
define|#
directive|define
name|BIGGEST_FIELD_ALIGNMENT
value|32
end_define

begin_comment
comment|/* STANDARD_INCLUDE_DIR is the equivalent of "/usr/include" on UNIX.  */
end_comment

begin_define
define|#
directive|define
name|STANDARD_INCLUDE_DIR
value|"/boot/develop/headers/posix"
end_define

begin_comment
comment|/* SYSTEM_INCLUDE_DIR is the location for system specific, non-POSIX headers.  */
end_comment

begin_define
define|#
directive|define
name|SYSTEM_INCLUDE_DIR
value|"/boot/develop/headers/be"
end_define

end_unit

