begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel x86 running BeOS    Copyright (C) 1998, 1999, 2000, 2001 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
value|fprintf (stderr, " (i386 BeOS/ELF)");
end_define

begin_comment
comment|/* Change debugging to Dwarf2.  */
end_comment

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DWARF2_DEBUG
end_define

begin_comment
comment|/* The SVR4 ABI for the i386 says that records and unions are returned    in memory.  */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_PCC_STRUCT_RETURN
end_undef

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|1
end_define

begin_undef
undef|#
directive|undef
name|ASM_COMMENT_START
end_undef

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|" #"
end_define

begin_undef
undef|#
directive|undef
name|DBX_REGISTER_NUMBER
end_undef

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|n
parameter_list|)
define|\
value|(TARGET_64BIT ? dbx64_register_map[n] : svr4_dbx_register_map[n])
end_define

begin_comment
comment|/* Output assembler code to FILE to increment profiler label # LABELNO    for profiling a function entry.  */
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
value|{									\   if (flag_pic)								\     {									\       fprintf (FILE, "\tleal %sP%d@GOTOFF(%%ebx),%%edx\n",		\ 	       LPREFIX, (LABELNO));					\       fprintf (FILE, "\tcall *mcount@GOT(%%ebx)\n");			\     }									\   else									\     {									\       fprintf (FILE, "\tmovl $%sP%d,%%edx\n", LPREFIX, (LABELNO));	\       fprintf (FILE, "\tcall mcount\n");				\     }									\ }
end_define

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"long unsigned int"
end_define

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"long int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"short unsigned int"
end_define

begin_undef
undef|#
directive|undef
name|WCHAR_UNSIGNED
end_undef

begin_define
define|#
directive|define
name|WCHAR_UNSIGNED
value|1
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
value|16
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
value|"-D__ELF__ -D__BEOS__ -D__INTEL__ -D_X86_=1 \ -D__stdcall=__attribute__((__stdcall__)) \ -D__cdecl=__attribute__((__cdecl__)) \ -D__declspec(x)=__attribute__((x)) \ -Asystem=beos"
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
value|"%(cpp_cpu) %{!no-fPIC:%{!no-fpic:-D__PIC__ -D__pic__}}"
end_define

begin_comment
comment|/* BeOS uses lots of multichars, so don't warn about them unless the    user explicitly asks for the warnings with -Wmultichar.  Note that    CC1_SPEC is used for both cc1 and cc1plus.  */
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
value|"%{!no-fpic:%{!fPIC:-fpic}} %{!Wmultichar: -Wno-multichar} %(cc1_cpu) %{profile:-p}"
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
value|"%{!Wctor-dtor-privacy:-Wno-ctor-dtor-privacy}"
end_define

begin_comment
comment|/* Provide a LINK_SPEC appropriate for BeOS.  Here we provide support    for the special GCC options -static and -shared, which allow us to    link things in one of these three modes by applying the appropriate    combinations of options at link-time.  */
end_comment

begin_comment
comment|/* If ELF is the default format, we should not use /lib/elf.  */
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
value|"%{!o*:-o %b} -m elf_i386_be -shared -Bsymbolic %{nostart:-e 0}"
end_define

begin_comment
comment|/* Provide start and end file specs appropriate to glibc.  */
end_comment

begin_comment
comment|/* LIB_SPEC for BeOS */
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
value|"-lnet -lroot"
end_define

begin_comment
comment|/* gcc runtime lib is built into libroot.so on BeOS */
end_comment

begin_comment
comment|/* ??? This is gonna be lovely when the next release of gcc has     some new symbol in, so that links start failing.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIBGCC_SPEC
end_undef

begin_define
define|#
directive|define
name|LIBGCC_SPEC
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
value|"crti.o%s crtbegin.o%s %{!nostart:start_dyn.o%s} init_term_dyn.o%s %{p:i386-mcount.o%s}"
end_define

begin_undef
undef|#
directive|undef
name|ENDFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|"crtend.o%s crtn.o%s"
end_define

begin_comment
comment|/* A C statement (sans semicolon) to output to the stdio stream    FILE the assembler definition of uninitialized global DECL named    NAME whose size is SIZE bytes and alignment is ALIGN bytes.    Try to use asm_output_aligned_bss to implement this macro.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_BSS
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|asm_output_aligned_bss (FILE, DECL, NAME, SIZE, ALIGN)
end_define

begin_comment
comment|/* A C statement to output to the stdio stream FILE an assembler    command to advance the location counter to a multiple of 1<<LOG    bytes if it is within MAX_SKIP bytes.     This is used to align code labels according to Intel recommendations.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GAS_MAX_SKIP_P2ALIGN
end_ifdef

begin_define
define|#
directive|define
name|ASM_OUTPUT_MAX_SKIP_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|,
name|MAX_SKIP
parameter_list|)
define|\
value|if ((LOG)!=0) \     if ((MAX_SKIP)==0) fprintf ((FILE), "\t.p2align %d\n", (LOG)); \     else fprintf ((FILE), "\t.p2align %d,,%d\n", (LOG), (MAX_SKIP))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For native compiler, use standard BeOS include file search paths    rooted in /boot/develop/headers.  For a cross compiler, don't    expect the host to use the BeOS directory scheme, and instead look    for the BeOS include files relative to TOOL_INCLUDE_DIR.  Yes, we    use ANSI string concatenation here (FIXME) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CROSS_COMPILE
end_ifndef

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
value|{ \     { GPLUSPLUS_INCLUDE_DIR, "G++", 1, 1 },\     { GCC_INCLUDE_DIR, "GCC", 0, 0 },\     { TOOL_INCLUDE_DIR, "BINUTILS", 0, 1}, \     { "/boot/develop/headers/be/add-ons/graphics", 0, 0, 0 },\     { "/boot/develop/headers/be/devel", 0, 0, 0 },\     { "/boot/develop/headers/be/translation", 0, 0, 0 },\     { "/boot/develop/headers/be/mail", 0, 0, 0 },\     { "/boot/develop/headers/gnu", 0, 0, 0 },\     { "/boot/develop/headers/be/drivers", 0, 0, 0 },\     { "/boot/develop/headers/be/opengl", 0, 0, 0 },\     { "/boot/develop/headers/be/game", 0, 0, 0 },\     { "/boot/develop/headers/be/support", 0, 0, 0 },\     { "/boot/develop/headers/be/storage", 0, 0, 0 },\     { "/boot/develop/headers/be/kernel", 0, 0, 0 },\     { "/boot/develop/headers/be/net", 0, 0, 0 },\     { "/boot/develop/headers/be/midi", 0, 0, 0 },\     { "/boot/develop/headers/be/midi2", 0, 0, 0 },\     { "/boot/develop/headers/be/media", 0, 0, 0 },\     { "/boot/develop/headers/be/interface", 0, 0, 0 },\     { "/boot/develop/headers/be/device", 0, 0, 0 },\     { "/boot/develop/headers/be/app", 0, 0, 0 },\     { "/boot/develop/headers/be/precompiled", 0, 0, 0 },\     { "/boot/develop/headers/be/add-ons/input_server", 0, 0, 0 },\     { "/boot/develop/headers/be/add-ons/net_server", 0, 0, 0 },\     { "/boot/develop/headers/be/add-ons/screen_saver", 0, 0, 0 },\     { "/boot/develop/headers/be/add-ons/tracker", 0, 0, 0 },\     { "/boot/develop/headers/be/be_apps/Deskbar", 0, 0, 0 },\     { "/boot/develop/headers/be/be_apps/NetPositive", 0, 0, 0 },\     { "/boot/develop/headers/be/be_apps/Tracker", 0, 0, 0 },\     { "/boot/develop/headers/be/drivers/tty", 0, 0, 0 },\     { "/boot/develop/headers/be/net/netinet", 0, 0, 0 },\     { "/boot/develop/headers/be/storage", 0, 0, 0 },\     { "/boot/develop/headers/be", 0, 0, 0 },\     { "/boot/develop/headers/cpp", 0, 0, 0 },\     { "/boot/develop/headers/posix", 0, 0, 0 },\     { "/boot/develop/headers", 0, 0, 0 }, \     { 0, 0, 0, 0 } \     }
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CROSS_COMPILE */
end_comment

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
value|{ \     { GPLUSPLUS_INCLUDE_DIR, "G++", 1, 1 },\     { GCC_INCLUDE_DIR, "GCC", 0, 0 },\     { TOOL_INCLUDE_DIR, "BINUTILS", 0, 1}, \     { CROSS_INCLUDE_DIR "/be/add-ons/graphics", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/devel", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/translation", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/mail", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/gnu", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/drivers", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/opengl", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/game", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/support", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/storage", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/kernel", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/net", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/midi", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/midi2", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/media", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/interface", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/device", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/app", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/precompiled", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/add-ons/input_server", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/add-ons/net_server", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/add-ons/screen_saver", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/add-ons/tracker", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/be_apps/Deskbar", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/be_apps/NetPositive", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/be_apps/Tracker", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/drivers/tty", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/net/netinet", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be/storage", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/be", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/cpp", 0, 0, 0 },\     { CROSS_INCLUDE_DIR "/posix", 0, 0, 0 },\     { CROSS_INCLUDE_DIR , 0, 0, 0 }, \     { 0, 0, 0, 0 } \     }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Whee.  LIBRARY_PATH is Be's LD_LIBRARY_PATH, which of course will    cause nasty problems if we override it.  */
end_comment

begin_define
define|#
directive|define
name|LIBRARY_PATH_ENV
value|"BELIBRARIES"
end_define

begin_comment
comment|/* BeOS doesn't have a separate math library.  */
end_comment

begin_define
define|#
directive|define
name|MATH_LIBRARY
value|""
end_define

begin_comment
comment|/* BeOS headers are C++-aware (and often use C++).  */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_comment
comment|/* Define this macro if in some cases global symbols from one translation    unit may not be bound to undefined symbols in another translation unit    without user intervention.  For instance, under Microsoft Windows    symbols must be explicitly imported from shared libraries (DLLs).  */
end_comment

begin_define
define|#
directive|define
name|MULTIPLE_SYMBOL_SPACES
end_define

end_unit

