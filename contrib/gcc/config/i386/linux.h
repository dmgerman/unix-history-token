begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running Linux-based GNU systems with ELF format.    Copyright (C) 1994, 1995, 1996, 1997, 1998, 1999, 2001, 2002    Free Software Foundation, Inc.    Contributed by Eric Youngdale.    Modified for stabs-in-ELF by H.J. Lu.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|LINUX_DEFAULT_ELF
end_define

begin_comment
comment|/* Output at beginning of assembler file.  */
end_comment

begin_comment
comment|/* The .file command should always begin the output.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FILE_START
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do {									\ 	output_file_directive (FILE, main_input_filename);		\ 	if (ix86_asm_dialect == ASM_INTEL)				\ 	  fputs ("\t.intel_syntax\n", FILE);				\   } while (0)
end_define

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

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
end_define

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
value|{									\   if (flag_pic)								\     fprintf (FILE, "\tcall\t*mcount@GOT(%%ebx)\n");			\   else									\     fprintf (FILE, "\tcall\tmcount\n");					\ }
end_define

begin_comment
comment|/* True if it is possible to profile code that does not have a frame    pointer.       The GLIBC version of mcount for the x86 assumes that there is a    frame, so we cannot allow profiling without a frame pointer.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_ALLOWS_PROFILING_WITHOUT_FRAME_POINTER
end_undef

begin_define
define|#
directive|define
name|TARGET_ALLOWS_PROFILING_WITHOUT_FRAME_POINTER
value|false
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

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_define
define|#
directive|define
name|CPP_PREDEFINES
value|"-D__ELF__ -Dunix -Dlinux -Asystem=posix"
end_define

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|USE_GNULIBC_1
end_ifdef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%(cpp_cpu) %{fPIC:-D__PIC__ -D__pic__} %{fpic:-D__PIC__ -D__pic__} %{posix:-D_POSIX_SOURCE}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%(cpp_cpu) %{fPIC:-D__PIC__ -D__pic__} %{fpic:-D__PIC__ -D__pic__} %{posix:-D_POSIX_SOURCE} %{pthread:-D_REENTRANT}"
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|USE_GNULIBC_1
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_DEFAULT_ELF
end_ifndef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-m elf_i386 %{shared:-shared} \   %{!shared: \     %{!ibcs: \       %{!static: \ 	%{rdynamic:-export-dynamic} \ 	%{!dynamic-linker:-dynamic-linker /lib/elf/ld-linux.so.1} \ 	%{!rpath:-rpath /lib/elf/}} %{static:-static}}}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-m elf_i386 %{shared:-shared} \   %{!shared: \     %{!ibcs: \       %{!static: \ 	%{rdynamic:-export-dynamic} \ 	%{!dynamic-linker:-dynamic-linker /lib/ld-linux.so.1}} \ 	%{static:-static}}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-m elf_i386 %{shared:-shared} \   %{!shared: \     %{!ibcs: \       %{!static: \ 	%{rdynamic:-export-dynamic} \ 	%{!dynamic-linker:-dynamic-linker /lib/ld-linux.so.2}} \ 	%{static:-static}}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__PIC__
argument_list|)
operator|&&
name|defined
argument_list|(
name|USE_GNULIBC_1
argument_list|)
end_if

begin_comment
comment|/* This is a kludge. The i386 GNU/Linux dynamic linker needs ___brk_addr,    __environ and atexit.  We have to make sure they are in the .dynsym    section.  We do this by forcing the assembler to create undefined     references to these symbols in the object file.  */
end_comment

begin_undef
undef|#
directive|undef
name|CRT_CALL_STATIC_FUNCTION
end_undef

begin_define
define|#
directive|define
name|CRT_CALL_STATIC_FUNCTION
parameter_list|(
name|SECTION_OP
parameter_list|,
name|FUNC
parameter_list|)
define|\
value|asm (SECTION_OP "\n\t"				\ 	"call " USER_LABEL_PREFIX #FUNC "\n"		\ 	TEXT_SECTION_ASM_OP "\n\t"			\ 	".extern ___brk_addr\n\t"			\ 	".type ___brk_addr,@object\n\t"			\ 	".extern __environ\n\t"				\ 	".type __environ,@object\n\t"			\ 	".extern atexit\n\t"				\ 	".type atexit,@function");
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

begin_comment
comment|/* Do code reading to identify a signal frame, and set the frame    state data appropriately.  See unwind-dw2.c for the structs.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IN_LIBGCC2
end_ifdef

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<sys/ucontext.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|MD_FALLBACK_FRAME_STATE_FOR
parameter_list|(
name|CONTEXT
parameter_list|,
name|FS
parameter_list|,
name|SUCCESS
parameter_list|)
define|\
value|do {									\     unsigned char *pc_ = (CONTEXT)->ra;					\     struct sigcontext *sc_;						\     long new_cfa_;							\ 									\
comment|/* popl %eax ; movl $__NR_sigreturn,%eax ; int $0x80  */
value|\     if (*(unsigned short *)(pc_+0) == 0xb858				\&& *(unsigned int *)(pc_+2) == 119				\&& *(unsigned short *)(pc_+6) == 0x80cd)			\       sc_ = (CONTEXT)->cfa + 4;						\
comment|/* movl $__NR_rt_sigreturn,%eax ; int $0x80  */
value|\     else if (*(unsigned char *)(pc_+0) == 0xb8				\&& *(unsigned int *)(pc_+1) == 173				\&& *(unsigned short *)(pc_+5) == 0x80cd)			\       {									\ 	struct rt_sigframe {						\ 	  int sig;							\ 	  struct siginfo *pinfo;					\ 	  void *puc;							\ 	  struct siginfo info;						\ 	  struct ucontext uc;						\ 	} *rt_ = (CONTEXT)->cfa;					\ 	sc_ = (struct sigcontext *)&rt_->uc.uc_mcontext;		\       }									\     else								\       break;								\ 									\     new_cfa_ = sc_->esp;						\     (FS)->cfa_how = CFA_REG_OFFSET;					\     (FS)->cfa_reg = 4;							\     (FS)->cfa_offset = new_cfa_ - (long) (CONTEXT)->cfa;		\ 									\
comment|/* The SVR4 register numbering macros aren't usable in libgcc.  */
value|\     (FS)->regs.reg[0].how = REG_SAVED_OFFSET;				\     (FS)->regs.reg[0].loc.offset = (long)&sc_->eax - new_cfa_;		\     (FS)->regs.reg[3].how = REG_SAVED_OFFSET;				\     (FS)->regs.reg[3].loc.offset = (long)&sc_->ebx - new_cfa_;		\     (FS)->regs.reg[1].how = REG_SAVED_OFFSET;				\     (FS)->regs.reg[1].loc.offset = (long)&sc_->ecx - new_cfa_;		\     (FS)->regs.reg[2].how = REG_SAVED_OFFSET;				\     (FS)->regs.reg[2].loc.offset = (long)&sc_->edx - new_cfa_;		\     (FS)->regs.reg[6].how = REG_SAVED_OFFSET;				\     (FS)->regs.reg[6].loc.offset = (long)&sc_->esi - new_cfa_;		\     (FS)->regs.reg[7].how = REG_SAVED_OFFSET;				\     (FS)->regs.reg[7].loc.offset = (long)&sc_->edi - new_cfa_;		\     (FS)->regs.reg[5].how = REG_SAVED_OFFSET;				\     (FS)->regs.reg[5].loc.offset = (long)&sc_->ebp - new_cfa_;		\     (FS)->regs.reg[8].how = REG_SAVED_OFFSET;				\     (FS)->regs.reg[8].loc.offset = (long)&sc_->eip - new_cfa_;		\     (FS)->retaddr_column = 8;						\     goto SUCCESS;							\   } while (0)
end_define

end_unit

