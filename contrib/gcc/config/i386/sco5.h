begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running SCO Unix System V 3.2 Version 5.    Copyright (C) 1992, 1995, 1996, 1997, 1998, 1999, 2000, 2002, 2003    Free Software Foundation, Inc.    Contributed by Kean Johnston (jkj@sco.com)  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
value|fprintf (stderr, " (i386, SCO OpenServer 5 Syntax)");
end_define

begin_undef
undef|#
directive|undef
name|ASM_QUAD
end_undef

begin_undef
undef|#
directive|undef
name|GLOBAL_ASM_OP
end_undef

begin_define
define|#
directive|define
name|GLOBAL_ASM_OP
value|"\t.globl\t"
end_define

begin_undef
undef|#
directive|undef
name|BSS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|BSS_SECTION_ASM_OP
value|"\t.section\t.bss, \"aw\", @nobits"
end_define

begin_comment
comment|/*  * NOTE: We really do want CTORS_SECTION_ASM_OP and DTORS_SECTION_ASM_OP.  * Here's the reason why. If we dont define them, and we dont define them  * to always emit to the same section, the default is to emit to "named"  * ctors and dtors sections. This would be great if we could use GNU ld,  * but we can't. The native linker could possibly be trained to coalesce  * named ctors sections, but that hasn't been done either. So if we don't  * define these, many C++ ctors and dtors dont get run, because they never  * wind up in the ctors/dtors arrays.  */
end_comment

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|"\t.section\t.ctors, \"aw\""
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|"\t.section\t.dtors, \"aw\""
end_define

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_START_FILE_DIRECTIVE
value|true
end_define

begin_undef
undef|#
directive|undef
name|X86_FILE_START_VERSION_DIRECTIVE
end_undef

begin_define
define|#
directive|define
name|X86_FILE_START_VERSION_DIRECTIVE
value|true
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
value|svr4_dbx_register_map[n]
end_define

begin_define
define|#
directive|define
name|DWARF2_DEBUGGING_INFO
value|1
end_define

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
value|1
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
value|DWARF2_DEBUG
end_define

begin_undef
undef|#
directive|undef
name|DWARF2_UNWIND_INFO
end_undef

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|1
end_define

begin_undef
undef|#
directive|undef
name|NO_IMPLICIT_EXTERN_C
end_undef

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
value|1
end_define

begin_undef
undef|#
directive|undef
name|SWITCH_TAKES_ARG
end_undef

begin_define
define|#
directive|define
name|SWITCH_TAKES_ARG
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|(DEFAULT_SWITCH_TAKES_ARG(CHAR)					\    || (CHAR) == 'h' 							\    || (CHAR) == 'R' 							\    || (CHAR) == 'Y' 							\    || (CHAR) == 'z')
end_define

begin_undef
undef|#
directive|undef
name|WORD_SWITCH_TAKES_ARG
end_undef

begin_define
define|#
directive|define
name|WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
define|\
value|(DEFAULT_WORD_SWITCH_TAKES_ARG (STR)					\&& strcmp (STR, "Tdata")&& strcmp (STR, "Ttext")			\&& strcmp (STR, "Tbss"))
end_define

begin_undef
undef|#
directive|undef
name|TARGET_SUBTARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_SUBTARGET_DEFAULT
value|(MASK_80387 | MASK_IEEE_FP | MASK_FLOAT_RETURNS)
end_define

begin_comment
comment|/*  * Define sizes and types  */
end_comment

begin_undef
undef|#
directive|undef
name|SIZE_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|PTRDIFF_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|WCHAR_TYPE_SIZE
end_undef

begin_undef
undef|#
directive|undef
name|WINT_TYPE
end_undef

begin_undef
undef|#
directive|undef
name|LONG_DOUBLE_TYPE_SIZE
end_undef

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_define
define|#
directive|define
name|PTRDIFF_TYPE
value|"int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"long int"
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_define
define|#
directive|define
name|WINT_TYPE
value|"long int"
end_define

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|96
end_define

begin_comment
comment|/*  * New for multilib support. Set the default switches for multilib,  * which is -melf.  */
end_comment

begin_define
define|#
directive|define
name|MULTILIB_DEFAULTS
value|{ "melf" }
end_define

begin_escape
end_escape

begin_comment
comment|/* Please note that these specs may look messy but they are required in    order to emulate the SCO Development system as closely as possible.    With SCO Open Server 5.0, you now get the linker and assembler free,    so that is what these specs are targeted for. These utilities are    very argument sensitive: a space in the wrong place breaks everything.    So please forgive this mess. It works.     Parameters which can be passed to gcc, and their SCO equivalents:    GCC Parameter                SCO Equivalent    -ansi                        -a ansi    -posix                       -a posix    -Xpg4                        -a xpg4    -Xpg4plus                    -a xpg4plus    -Xods30                      -a ods30     As with SCO, the default is XPG4 plus mode. SCO also allows you to    specify a C dialect with -Xt, -Xa, -Xc, -Xk and -Xm. These are passed    on to the assembler and linker in the same way that the SCO compiler    does.     SCO also allows you to compile, link and generate either ELF or COFF    binaries. With gcc, we now only support ELF mode.     GCC also requires that the user has installed OSS646, the Execution    Environment Update, or is running release 5.0.7 or later. This has    many fixes to the ELF link editor and assembler, and a considerably    improved libc and RTLD.     In terms of tool usage, we want to use the standard link editor always,    and either the GNU assembler or the native assembler. With OSS646 the    native assembler has grown up quite a bit. Some of the specs below    assume that /usr/gnu is the prefix for the GNU tools, because thats    where the SCO provided ones go. This is especially important for    include and library search path ordering. We want to look in /usr/gnu    first because frequently people are linking against -lintl, and they    MEAN to link with gettext. What they get is the SCO intl library. Its    a REAL pity that GNU gettext chose that name; perhaps in a future    version they can be persuaded to change it to -lgnuintl and have a    link so that -lintl will work for other systems. The same goes for    header files. We want /usr/gnu/include searched for before the system    header files. Hence the -isystem /usr/gnu/include in the CPP_SPEC.    We get /usr/gnu/lib first by virtue of the MD_STARTFILE_PREFIX below. */
end_comment

begin_define
define|#
directive|define
name|MD_STARTFILE_PREFIX
value|"/usr/gnu/lib/"
end_define

begin_define
define|#
directive|define
name|MD_STARTFILE_PREFIX_1
value|"/usr/ccs/lib/"
end_define

begin_if
if|#
directive|if
name|USE_GAS
end_if

begin_define
define|#
directive|define
name|MD_EXEC_PREFIX
value|"/usr/gnu/bin/"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|MD_EXEC_PREFIX
value|"/usr/ccs/bin/elf/"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Always use the system linker, please.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_LINKER
end_ifndef

begin_define
define|#
directive|define
name|DEFAULT_LINKER
value|"/usr/ccs/bin/elf/ld"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Set up assembler flags for PIC and ELF compilations */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_if
if|#
directive|if
name|USE_GAS
end_if

begin_comment
comment|/* Leave ASM_SPEC undefined so we pick up the master copy from gcc.c  */
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"%{Ym,*} %{Yd,*} %{Wa,*:%*} \     -E%{Xa:a}%{!Xa:%{Xc:c}%{!Xc:%{Xk:k}%{!Xk:%{Xt:t}%{!Xt:a}}}},%{ansi:ansi}%{!ansi:%{posix:posix}%{!posix:%{Xpg4:xpg4}%{!Xpg4:%{Xpg4plus:XPG4PLUS}%{!Xpg4plus:%{Xods30:ods30}%{!Xods30:XPG4PLUS}}}}},ELF %{Qn:} %{!Qy:-Qn}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Use crti.o for shared objects, crt1.o for normal executables. Make sure  * to recognize both -G and -shared as a valid way of introducing shared  * library generation. This is important for backwards compatibility.  */
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
value|"%{pg:%e-pg not supported on this platform} \   %{p:%{pp:%e-p and -pp specified - pick one}} \  %{!shared:\    %{!symbolic: \     %{!G: \      %{pp:pcrt1elf.o%s}%{p:mcrt1.o%s}%{!p:%{!pp:crt1.o%s}}}}} \   crti.o%s \   %{ansi:values-Xc.o%s} \   %{!ansi: \    %{traditional:values-Xt.o%s} \     %{!traditional: \      %{Xa:values-Xa.o%s} \       %{!Xa:%{Xc:values-Xc.o%s} \        %{!Xc:%{Xk:values-Xk.o%s} \         %{!Xk:%{Xt:values-Xt.o%s} \          %{!Xt:values-Xa.o%s}}}}}} \   crtbegin.o%s"
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
define|\
value|"crtend.o%s crtn.o%s"
end_define

begin_define
define|#
directive|define
name|TARGET_OS_CPP_BUILTINS
parameter_list|()
define|\
value|do								\     {								\ 	builtin_define ("__unix");				\ 	builtin_define ("_SCO_DS");				\ 	builtin_define ("_SCO_DS_LL");				\ 	builtin_define ("_SCO_ELF");				\ 	builtin_define ("_M_I386");				\ 	builtin_define ("_M_XENIX");				\ 	builtin_define ("_M_UNIX");				\ 	builtin_assert ("system=svr3");				\ 	if (flag_iso)						\ 	  cpp_define (pfile, "_STRICT_ANSI");			\ 	if (flag_pic)						\ 	  {							\ 	    builtin_define ("__PIC__");				\ 	    builtin_define ("__pic__");				\ 	  }							\     }								\   while (0)
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
value|"\   -isystem /usr/gnu/include \   %{!Xods30:-D_STRICT_NAMES} \   %{!ansi:%{!posix:%{!Xods30:-D_SCO_XPG_VERS=4}}} \   %{ansi:-isystem include/ansi%s -isystem /usr/include/ansi} \   %{!ansi: \    %{posix:-isystem include/posix%s -isystem /usr/include/posix \            -D_POSIX_C_SOURCE=2 -D_POSIX_SOURCE=1} \     %{!posix:%{Xpg4:-isystem include/xpg4%s -isystem /usr/include/xpg4 \                     -D_XOPEN_SOURCE=1} \      %{!Xpg4:-D_M_I86 -D_M_I86SM -D_M_INTERNAT -D_M_SDATA -D_M_STEXT \              -D_M_BITFIELDS -D_M_SYS5 -D_M_SYSV -D_M_SYSIII \              -D_M_WORDSWAP -Dunix -DM_I386 -DM_UNIX -DM_XENIX \              %{Xods30:-isystem include/ods_30_compat%s \                       -isystem /usr/include/ods_30_compat \                       -D_SCO_ODS_30 -DM_I86 -DM_I86SM -DM_SDATA -DM_STEXT \                       -DM_BITFIELDS -DM_SYS5 -DM_SYSV -DM_INTERNAT -DM_SYSIII \                       -DM_WORDSWAP}}}} \   %{scointl:-DM_INTERNAT -D_M_INTERNAT} \   %{Xa:-D_SCO_C_DIALECT=1} \   %{!Xa:%{Xc:-D_SCO_C_DIALECT=3} \    %{!Xc:%{Xk:-D_SCO_C_DIALECT=4} \     %{!Xk:%{Xt:-D_SCO_C_DIALECT=2} \      %{!Xt:-D_SCO_C_DIALECT=1}}}}"
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
define|\
value|"%{!shared:%{!symbolic:%{!G:-E%{Xa:a}%{!Xa:%{Xc:c}%{!Xc:%{Xk:k}%{!Xk:%{Xt:t}%{!Xt:a}}}},%{ansi:ansi}%{!ansi:%{posix:posix}%{!posix:%{Xpg4:xpg4}%{!Xpg4:%{Xpg4plus:XPG4PLUS}%{!Xpg4plus:%{Xods30:ods30}%{!Xods30:XPG4PLUS}}}}},ELF}}} \   %{Wl,*:%*} %{YP,*} %{YL,*} %{YU,*} \   %{!YP,*:%{p:-YP,/usr/ccs/libp:/lib/libp:/usr/lib/libp:/usr/ccs/lib:/lib:/usr/lib} \    %{!p:-YP,/usr/ccs/lib:/lib:/usr/lib}} \   %{h*} %{static:-dn -Bstatic %{G:%e-G and -static are mutually exclusive}} \   %{shared:%{!G:-G}} %{G:%{!shared:-G}} %{shared:%{G:-G}} \   %{shared:-dy %{symbolic:-Bsymbolic -G} %{z*}} %{R*} %{Y*} \   %{Qn:} %{!Qy:-Qn} -z alt_resolve"
end_define

begin_comment
comment|/* Library spec. If we are not building a shared library, provide the    standard libraries, as per the SCO compiler.  */
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
define|\
value|"%{shared:%{!G:pic/libgcc.a%s}} \   %{G:%{!shared:pic/libgcc.a%s}} \   %{shared:%{G:pic/libgcc.a%s}} \   %{p:%{!pp:-lelfprof -lelf}} %{pp:%{!p:-lelfprof -lelf}} \   %{!shared:%{!symbolic:%{!G:-lcrypt -lgen -lc}}}"
end_define

begin_undef
undef|#
directive|undef
name|LIBGCC_SPEC
end_undef

begin_define
define|#
directive|define
name|LIBGCC_SPEC
define|\
value|"%{!shared:%{!G:-lgcc}}"
end_define

begin_comment
comment|/* Here for legacy support only so we still accept -melf flag */
end_comment

begin_define
define|#
directive|define
name|MASK_COFF
value|010000000000
end_define

begin_comment
comment|/* Mask for COFF generation */
end_comment

begin_define
define|#
directive|define
name|TARGET_ELF
value|(1)
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
value|{ "elf", -MASK_COFF, N_("Generate ELF output")  },
end_define

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
value|do {									\     if ((SIZE) == 4&& ((ENCODING)& 0x70) == DW_EH_PE_datarel)		\       {									\         fputs (ASM_LONG, FILE);						\         assemble_name (FILE, XSTR (ADDR, 0));				\ 	fputs (((ENCODING)& DW_EH_PE_indirect ? "@GOT" : "@GOTOFF"), FILE); \         goto DONE;							\       }									\   } while (0)
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

end_unit

