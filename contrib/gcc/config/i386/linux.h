begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running Linux-based GNU systems with ELF format.    Copyright (C) 1994, 1995, 1996, 1997, 1998, 1999, 2001, 2002, 2004, 2005,    2006 Free Software Foundation, Inc.    Contributed by Eric Youngdale.    Modified for stabs-in-ELF by H.J. Lu.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Output at beginning of assembler file.  */
end_comment

begin_comment
comment|/* The .file command should always begin the output.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_START_FILE_DIRECTIVE
value|true
end_define

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (i386 Linux/ELF)");
end_define

begin_comment
comment|/* The svr4 ABI for the i386 says that records and unions are returned    in memory.  */
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

begin_comment
comment|/* We arrange for the whole %gs segment to map the tls area.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_TLS_DIRECT_SEG_REFS_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_TLS_DIRECT_SEG_REFS_DEFAULT
value|MASK_TLS_DIRECT_SEG_REFS
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
value|"#"
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
comment|/* Output assembler code to FILE to call the profiler.    To the best of my knowledge, no Linux libc has required the label    argument to mcount.  */
end_comment

begin_define
define|#
directive|define
name|NO_PROFILE_COUNTERS
value|1
end_define

begin_undef
undef|#
directive|undef
name|MCOUNT_NAME
end_undef

begin_define
define|#
directive|define
name|MCOUNT_NAME
value|"mcount"
end_define

begin_comment
comment|/* The GLIBC version of mcount for the x86 assumes that there is a    frame, so we cannot allow profiling without a frame pointer.  */
end_comment

begin_undef
undef|#
directive|undef
name|SUBTARGET_FRAME_POINTER_REQUIRED
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_FRAME_POINTER_REQUIRED
value|current_function_profile
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
value|"unsigned int"
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
value|"int"
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
value|"long int"
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
value|BITS_PER_WORD
end_define

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do						\     {						\ 	LINUX_TARGET_OS_CPP_BUILTINS();		\     }						\   while (0)
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
value|"%{posix:-D_POSIX_SOURCE} %{pthread:-D_REENTRANT}"
end_define

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%(cc1_cpu) %{profile:-p}"
end_define

begin_comment
comment|/* Provide a LINK_SPEC appropriate for Linux.  Here we provide support    for the special GCC options -static and -shared, which allow us to    link things in one of these three modes by applying the appropriate    combinations of options at link-time. We like to support here for    as many of the other GNU linker options as possible. But I don't    have the time to search for those flags. I am sure how to add    support for -soname shared_object_name. H.J.     I took out %{v:%{!V:-V}}. It is too much :-(. They can use    -Wl,-V.     When the -shared link option is used a final link is not being    done.  */
end_comment

begin_comment
comment|/* If ELF is the default format, we should not use /lib/elf.  */
end_comment

begin_comment
comment|/* These macros may be overridden in k*bsd-gnu.h and i386/k*bsd-gnu.h. */
end_comment

begin_define
define|#
directive|define
name|LINK_EMULATION
value|"elf_i386"
end_define

begin_define
define|#
directive|define
name|GLIBC_DYNAMIC_LINKER
value|"/lib/ld-linux.so.2"
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_EXTRA_SPECS
end_undef

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
define|\
value|{ "link_emulation", LINK_EMULATION },\   { "dynamic_linker", LINUX_DYNAMIC_LINKER }
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
value|"-m %(link_emulation) %{shared:-shared} \   %{!shared: \     %{!ibcs: \       %{!static: \ 	%{rdynamic:-export-dynamic} \ 	%{!dynamic-linker:-dynamic-linker %(dynamic_linker)}} \ 	%{static:-static}}}"
end_define

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
value|do {									\     if ((LOG) != 0) {							\       if ((MAX_SKIP) == 0) fprintf ((FILE), "\t.p2align %d\n", (LOG));	\       else fprintf ((FILE), "\t.p2align %d,,%d\n", (LOG), (MAX_SKIP));	\     }									\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Handle special EH pointer encodings.  Absolute, pc-relative, and    indirect are handled automatically.  */
end_comment

begin_define
define|#
directive|define
name|ASM_MAYBE_OUTPUT_ENCODED_ADDR_RTX
parameter_list|(
name|FILE
parameter_list|,
name|ENCODING
parameter_list|,
name|SIZE
parameter_list|,
name|ADDR
parameter_list|,
name|DONE
parameter_list|)
define|\
value|do {									\     if ((SIZE) == 4&& ((ENCODING)& 0x70) == DW_EH_PE_datarel)		\       {									\         fputs (ASM_LONG, FILE);			\         assemble_name (FILE, XSTR (ADDR, 0));				\ 	fputs (((ENCODING)& DW_EH_PE_indirect ? "@GOT" : "@GOTOFF"), FILE); \         goto DONE;							\       }									\   } while (0)
end_define

begin_comment
comment|/* Used by crtstuff.c to initialize the base of data-relative relocations.    These are GOT relative on x86, so return the pic register.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__PIC__
end_ifdef

begin_define
define|#
directive|define
name|CRT_GET_RFIB_DATA
parameter_list|(
name|BASE
parameter_list|)
define|\
value|{						\     register void *ebx_ __asm__("ebx");		\     BASE = ebx_;				\   }
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CRT_GET_RFIB_DATA
parameter_list|(
name|BASE
parameter_list|)
define|\
value|__asm__ ("call\t.LPR%=\n"						\ 	   ".LPR%=:\n\t"						\ 	   "popl\t%0\n\t"						\
comment|/* Due to a GAS bug, this cannot use EAX.  That encodes	\ 	      smaller than the traditional EBX, which results in the	\ 	      offset being off by one.  */
value|\ 	   "addl\t$_GLOBAL_OFFSET_TABLE_+[.-.LPR%=],%0"			\ 	   : "=d"(BASE))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|NEED_INDICATE_EXEC_STACK
end_undef

begin_define
define|#
directive|define
name|NEED_INDICATE_EXEC_STACK
value|1
end_define

begin_define
define|#
directive|define
name|MD_UNWIND_SUPPORT
value|"config/i386/linux-unwind.h"
end_define

begin_comment
comment|/* This macro may be overridden in i386/k*bsd-gnu.h.  */
end_comment

begin_define
define|#
directive|define
name|REG_NAME
parameter_list|(
name|reg
parameter_list|)
value|reg
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|TARGET_LIBC_PROVIDES_SSP
end_ifdef

begin_comment
comment|/* i386 glibc provides __stack_chk_guard in %gs:0x14.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_THREAD_SSP_OFFSET
value|0x14
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

