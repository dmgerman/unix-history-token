begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running FreeBSD with either a.out or ELF format    Copyright (C) 1996, 2000, 2002 Free Software Foundation, Inc.    Contributed by Eric Youngdale.    Modified for stabs-in-ELF by H.J. Lu.    Adapted from GNU/Linux version by John Polstra.    Added support for generating "old a.out gas" on the fly by Peter Wemm.    Continued development by David O'Brien<obrien@freebsd.org>  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
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
value|fprintf (stderr, " (i386 FreeBSD/ELF)");
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
value|"%(cc1_cpu) %{profile:-p} \   %{gline:%{!g:%{!g0:%{!g1:%{!g2: -g1}}}}} \   %{maout: %{!mno-underscores: %{!munderscores: -munderscores }}}"
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
value|"%{v*: -v} %{maout: %{fpic:-k} %{fPIC:-k}}"
end_define

begin_undef
undef|#
directive|undef
name|ASM_FINAL_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_FINAL_SPEC
value|"%|"
end_define

begin_comment
comment|/* Provide a LINK_SPEC appropriate for FreeBSD.  Here we provide support    for the special GCC options -static and -shared, which allow us to    link things in one of these three modes by applying the appropriate    combinations of options at link-time. We like to support here for    as many of the other GNU linker options as possible. But I don't    have the time to search for those flags. I am sure how to add    support for -soname shared_object_name. H.J.     When the -shared link option is used a final link is not being    done.  */
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
value|"\  %{p:%e`-p' not supported; use `-pg' and gprof(1)} \   %{maout: %{shared:-Bshareable} \     %{!shared:%{!nostdlib:%{!r:%{!e*:-e start}}} -dc -dp %{static:-Bstatic} \       %{pg:-Bstatic} %{Z}} \     %{assert*} %{R*}} \   %{!maout: \     %{Wl,*:%*} \     %{v:-V} \     %{assert*} %{R*} %{rpath*} %{defsym*} \     %{shared:-Bshareable %{h*} %{soname*}} \     %{!shared: \       %{!static: \ 	%{rdynamic: -export-dynamic} \ 	%{!dynamic-linker: -dynamic-linker /usr/libexec/ld-elf.so.1}} \       %{static:-Bstatic}} \     %{symbolic:-Bsymbolic}}"
end_define

begin_comment
comment|/* Provide a STARTFILE_SPEC appropriate for FreeBSD.  Here we add the magical    crtbegin.o file (see crtstuff.c) which provides part of the support for    getting C++ file-scope static object constructed before entering `main'.  */
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
value|"\   %{maout: %{shared:c++rt0.o%s} \     %{!shared: \       %{pg:gcrt0.o%s}%{!pg: \ 	%{static:scrt0.o%s} \ 	%{!static:crt0.o%s}}}} \   %{!maout: \     %{!shared: \       %{pg:gcrt1.o%s} \       %{!pg: \ 	%{p:gcrt1.o%s} \ 	%{!p:crt1.o%s}}} \     crti.o%s \     %{!shared:crtbegin.o%s} \     %{shared:crtbeginS.o%s}}"
end_define

begin_comment
comment|/* Provide an ENDFILE_SPEC appropriate for FreeBSD/i386.  Here we tack on our    own magical crtend.o file (see crtstuff.c) which provides part of the    support for getting C++ file-scope static object constructed before    entering `main', followed by the normal "finalizer" file, `crtn.o'.  */
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
value|"\   %{!maout: \     %{!shared:crtend.o%s} \     %{shared:crtendS.o%s} crtn.o%s}"
end_define

begin_comment
comment|/* FreeBSD conditionalizes the use of ".section rodata" depending on    ELF mode - otherwise .text.  */
end_comment

begin_undef
undef|#
directive|undef
name|USE_CONST_SECTION
end_undef

begin_define
define|#
directive|define
name|USE_CONST_SECTION
value|TARGET_ELF
end_define

begin_comment
comment|/* ".string" doesn't work for the aout case. */
end_comment

begin_undef
undef|#
directive|undef
name|STRING_ASM_OP
end_undef

begin_define
define|#
directive|define
name|STRING_ASM_OP
value|(TARGET_AOUT ? "\t.asciz\t" : "\t.string\t")
end_define

begin_comment
comment|/************************[  Target stuff  ]***********************************/
end_comment

begin_comment
comment|/* Define the actual types of some ANSI-mandated types.    Needs to agree with<machine/ansi.h>.  GCC defaults come from c-decl.c,    c-common.c, and config/<arch>/<arch>.h.  */
end_comment

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
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (i386 FreeBSD/ELF)");
end_define

begin_define
define|#
directive|define
name|MASK_PROFILER_EPILOGUE
value|010000000000
end_define

begin_define
define|#
directive|define
name|MASK_AOUT
value|004000000000
end_define

begin_comment
comment|/* a.out not elf */
end_comment

begin_define
define|#
directive|define
name|MASK_UNDERSCORES
value|002000000000
end_define

begin_comment
comment|/* use leading _ */
end_comment

begin_define
define|#
directive|define
name|TARGET_PROFILER_EPILOGUE
value|(target_flags& MASK_PROFILER_EPILOGUE)
end_define

begin_define
define|#
directive|define
name|TARGET_AOUT
value|(target_flags& MASK_AOUT)
end_define

begin_define
define|#
directive|define
name|TARGET_ELF
value|((target_flags& MASK_AOUT) == 0)
end_define

begin_define
define|#
directive|define
name|TARGET_UNDERSCORES
value|((target_flags& MASK_UNDERSCORES) != 0)
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
value|{ "profiler-epilogue",	 MASK_PROFILER_EPILOGUE, "Function profiler epilogue"}, \   { "no-profiler-epilogue",	-MASK_PROFILER_EPILOGUE, "No function profiler epilogue"}, \   { "aout",			 MASK_AOUT, "Generate an a.out (vs. ELF) binary"}, \   { "no-aout",			-MASK_AOUT, "Do not generate an a.out binary"}, \   { "underscores",		 MASK_UNDERSCORES, "Add leading underscores to symbols"}, \   { "no-underscores",		-MASK_UNDERSCORES, "Do not add leading underscores to symbols"},
end_define

begin_comment
comment|/* This goes away when the math emulator is fixed.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_SUBTARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_SUBTARGET_DEFAULT
define|\
value|(MASK_80387 | MASK_IEEE_FP | MASK_FLOAT_RETURNS | MASK_NO_FANCY_MATH_387)
end_define

begin_comment
comment|/* Don't default to pcc-struct-return, we want to retain compatibility with    older gcc versions AND pcc-struct-return is nonreentrant.    (even though the SVR4 ABI for the i386 says that records and unions are    returned in memory).  */
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
value|0
end_define

begin_comment
comment|/* The a.out tools do not support "linkonce" sections. */
end_comment

begin_undef
undef|#
directive|undef
name|SUPPORTS_ONE_ONLY
end_undef

begin_define
define|#
directive|define
name|SUPPORTS_ONE_ONLY
value|TARGET_ELF
end_define

begin_comment
comment|/* Prefix for internally generated assembler labels.  If we aren't using    underscores, we are using prefix `.'s to identify labels that should    be ignored, as in `i386/gas.h' --karl@cs.umb.edu  */
end_comment

begin_undef
undef|#
directive|undef
name|LPREFIX
end_undef

begin_define
define|#
directive|define
name|LPREFIX
value|((TARGET_UNDERSCORES) ? "L" : ".L")
end_define

begin_comment
comment|/* supply our own hook for calling __main() from main() */
end_comment

begin_undef
undef|#
directive|undef
name|INVOKE__main
end_undef

begin_define
define|#
directive|define
name|INVOKE__main
end_define

begin_undef
undef|#
directive|undef
name|GEN_CALL__MAIN
end_undef

begin_define
define|#
directive|define
name|GEN_CALL__MAIN
define|\
value|do {									\     if (!(TARGET_ELF))							\       emit_library_call (gen_rtx (SYMBOL_REF, Pmode, NAME__MAIN), 0,	\ 			 VOIDmode, 0);					\   } while (0)
end_define

begin_comment
comment|/* Tell final.c that we don't need a label passed to mcount.  */
end_comment

begin_define
define|#
directive|define
name|NO_PROFILE_COUNTERS
value|1
end_define

begin_comment
comment|/* Output assembler code to FILE to begin profiling of the current function.    LABELNO is an optional label.  */
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
value|do {									\     char *_name = TARGET_AOUT ? "mcount" : ".mcount";			\     if (flag_pic)							\       fprintf ((FILE), "\tcall *%s@GOT(%%ebx)\n", _name);		\     else								\       fprintf ((FILE), "\tcall %s\n", _name);				\   } while (0)
end_define

begin_comment
comment|/* Output assembler code to FILE to end profiling of the current function.  */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_PROFILER_EPILOGUE
end_undef

begin_comment
comment|/* BDE will need to fix this. */
end_comment

begin_comment
comment|/************************[  Assembler stuff  ]********************************/
end_comment

begin_comment
comment|/* Override the default comment-starter of "/" from unix.h.  */
end_comment

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

begin_comment
comment|/* Override the default comment-starter of "/APP" from unix.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_APP_ON
end_undef

begin_define
define|#
directive|define
name|ASM_APP_ON
value|"#APP\n"
end_define

begin_undef
undef|#
directive|undef
name|ASM_APP_OFF
end_undef

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|"#NO_APP\n"
end_define

begin_comment
comment|/* This is how to store into the string BUF    the symbol_ref name of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    This is suitable for output with `assemble_name'.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_GENERATE_INTERNAL_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_GENERATE_INTERNAL_LABEL
parameter_list|(
name|LABEL
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|sprintf ((LABEL), "*%s%s%u", (TARGET_UNDERSCORES) ? "" : ".",		\ 	   (PREFIX), (unsigned) (NUM))
end_define

begin_comment
comment|/* This is how to output an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    For most svr4/ELF systems, the convention is that any symbol which begins    with a period is not put into the linker symbol table by the assembler.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_INTERNAL_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|fprintf ((FILE), "%s%s%u:\n", (TARGET_UNDERSCORES) ? "" : ".",	\ 	   (PREFIX), (unsigned) (NUM))
end_define

begin_comment
comment|/* This is how to output a reference to a user-level label named NAME.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LABELREF
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\     char *_name = (NAME);						\
comment|/* Hack to avoid writing lots of rtl in				\        FUNCTION_PROFILER_EPILOGUE ().  */
value|\     if (*_name == '.'&& strcmp(_name + 1, "mexitcount") == 0)		\       {									\ 	if (TARGET_AOUT)						\ 	  _name++;							\ 	if (flag_pic)							\ 	  fprintf ((FILE), "*%s@GOT(%%ebx)", _name);			\ 	else								\ 	  fprintf ((FILE), "%s", _name);				\       }									\     else								\       fprintf (FILE, "%s%s", TARGET_UNDERSCORES ? "_" : "", _name);	\ } while (0)
end_define

begin_comment
comment|/* This is how to hack on the symbol code of certain relcalcitrant    symbols to modify their output in output_pic_addr_const ().  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_HACK_SYMBOLREF_CODE
end_undef

begin_comment
comment|/* BDE will need to fix this. */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGN
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|)
define|\
value|if ((LOG)!=0) {							\     if (in_text_section())						\       fprintf ((FILE), "\t.p2align %d,0x90\n", (LOG));			\     else								\       fprintf ((FILE), "\t.p2align %d\n", (LOG));			\   }
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_COMMON
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_COMMON
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|do {									\     if (TARGET_ELF)							\       {									\ 	fprintf ((FILE), "%s", COMMON_ASM_OP);				\ 	assemble_name ((FILE), (NAME));					\ 	fprintf ((FILE), ",%u,%u\n", (SIZE), (ALIGN) / BITS_PER_UNIT);	\       }									\     else								\       {									\ 	int rounded = (SIZE);						\ 	if (rounded == 0) rounded = 1;					\ 	rounded += (BIGGEST_ALIGNMENT / BITS_PER_UNIT) - 1;		\ 	rounded = (rounded / (BIGGEST_ALIGNMENT / BITS_PER_UNIT)	\ 		   * (BIGGEST_ALIGNMENT / BITS_PER_UNIT));		\ 	fprintf ((FILE), "%s ", COMMON_ASM_OP);				\ 	assemble_name ((FILE), (NAME));					\ 	fprintf ((FILE), ",%u\n", (rounded));				\       }									\   } while (0)
end_define

begin_comment
comment|/* This says how to output assembler code to declare an    uninitialized internal linkage data object.  Under SVR4,    the linker seems to want the alignment of data objects    to depend on their types.  We do exactly that here.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_LOCAL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGNED_LOCAL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|do {									\     if (TARGET_ELF)							\       {									\ 	fprintf ((FILE), "%s", LOCAL_ASM_OP);				\ 	assemble_name ((FILE), (NAME));					\ 	fprintf ((FILE), "\n");						\ 	ASM_OUTPUT_ALIGNED_COMMON ((FILE), (NAME), (SIZE), (ALIGN));	\       }									\     else								\       {									\ 	int rounded = (SIZE);						\ 	if (rounded == 0) rounded = 1;					\ 	rounded += (BIGGEST_ALIGNMENT / BITS_PER_UNIT) - 1;		\ 	rounded = (rounded / (BIGGEST_ALIGNMENT / BITS_PER_UNIT)	\ 		   * (BIGGEST_ALIGNMENT / BITS_PER_UNIT));		\ 	fputs ("\t.lcomm\t", (FILE));					\ 	assemble_name ((FILE), (NAME));					\ 	fprintf ((FILE), ",%u\n", (rounded));				\       }									\   } while (0)
end_define

begin_comment
comment|/* How to output some space.  The rules are different depending on the    object format.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SKIP
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SKIP
parameter_list|(
name|FILE
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|do {									\     if (TARGET_ELF)							\       {									\         fprintf ((FILE), "%s%u\n", SKIP_ASM_OP, (SIZE));		\       }									\     else								\       {									\         fprintf ((FILE), "\t.space\t%u\n", (SIZE));			\       }									\   } while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SOURCE_LINE
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_LINE
parameter_list|(
name|FILE
parameter_list|,
name|LINE
parameter_list|)
define|\
value|do {									\     static int sym_lineno = 1;						\     if (TARGET_ELF)							\       {									\ 	fprintf ((FILE), ".stabn 68,0,%d,.LM%d-", (LINE), sym_lineno);	\ 	assemble_name ((FILE), 						\ 		XSTR (XEXP (DECL_RTL (current_function_decl), 0), 0));	\ 	fprintf ((FILE), "\n.LM%d:\n", sym_lineno);			\ 	sym_lineno += 1;						\       }									\     else								\       {									\ 	fprintf ((FILE), "\t%s %d,0,%d\n", ASM_STABD_OP, N_SLINE,	\ 		lineno);						\       }									\   } while (0)
end_define

begin_comment
comment|/* A C statement to output to the stdio stream FILE an assembler    command to advance the location counter to a multiple of 1<<LOG    bytes if it is within MAX_SKIP bytes.     This is used to align code labels according to Intel recommendations.  */
end_comment

begin_comment
comment|/* XXX configuration of this is broken in the same way as HAVE_GAS_SHF_MERGE,    but it is easier to fix in an MD way.  */
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
value|do {									\   if ((LOG) != 0) {							\     if (TARGET_AOUT)							\       ASM_OUTPUT_ALIGN ((FILE), (LOG));					\     else if ((MAX_SKIP) == 0)						\       fprintf ((FILE), "\t.p2align %d\n", (LOG));			\     else								\       fprintf ((FILE), "\t.p2align %d,,%d\n", (LOG), (MAX_SKIP));	\   }									\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/************************[  Debugger stuff  ]*********************************/
end_comment

begin_comment
comment|/* The a.out tools do not support "Lscope" .stabs symbols. */
end_comment

begin_undef
undef|#
directive|undef
name|NO_DBX_FUNCTION_END
end_undef

begin_define
define|#
directive|define
name|NO_DBX_FUNCTION_END
value|TARGET_AOUT
end_define

begin_comment
comment|/* In ELF, the function stabs come first, before the relative offsets.  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_FUNCTION_FIRST
end_undef

begin_define
define|#
directive|define
name|DBX_CHECK_FUNCTION_FIRST
value|TARGET_ELF
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
value|(TARGET_64BIT ? dbx64_register_map[n]	\ 				: (write_symbols == DWARF2_DEBUG	\ 	    			  || write_symbols == DWARF_DEBUG)	\ 				  ? svr4_dbx_register_map[(n)]		\ 				  : dbx_register_map[(n)])
end_define

begin_comment
comment|/* tag end of file in elf mode */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_OUTPUT_MAIN_SOURCE_FILE_END
end_undef

begin_define
define|#
directive|define
name|DBX_OUTPUT_MAIN_SOURCE_FILE_END
parameter_list|(
name|FILE
parameter_list|,
name|FILENAME
parameter_list|)
define|\
value|do {									\     if (TARGET_ELF) {							\       fprintf ((FILE), "\t.text\n\t.stabs \"\",%d,0,0,%LLetext\n%LLetext:\n", \ 		N_SO);							\     }									\   } while (0)
end_define

begin_comment
comment|/* stabs-in-elf has offsets relative to function beginning */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_OUTPUT_LBRAC
end_undef

begin_define
define|#
directive|define
name|DBX_OUTPUT_LBRAC
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\     fprintf (asmfile, "%s %d,0,0,", ASM_STABN_OP, N_LBRAC);		\     assemble_name (asmfile, buf);					\     if (TARGET_ELF)							\       {									\         fputc ('-', asmfile);						\         assemble_name (asmfile,						\ 	      	 XSTR (XEXP (DECL_RTL (current_function_decl), 0), 0));	\       }									\     fprintf (asmfile, "\n");						\   } while (0)
end_define

begin_undef
undef|#
directive|undef
name|DBX_OUTPUT_RBRAC
end_undef

begin_define
define|#
directive|define
name|DBX_OUTPUT_RBRAC
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\     fprintf (asmfile, "%s %d,0,0,", ASM_STABN_OP, N_RBRAC);		\     assemble_name (asmfile, buf);					\     if (TARGET_ELF)							\       {									\         fputc ('-', asmfile);						\         assemble_name (asmfile,						\ 		 XSTR (XEXP (DECL_RTL (current_function_decl), 0), 0));	\       }									\     fprintf (asmfile, "\n");						\   } while (0)
end_define

end_unit

