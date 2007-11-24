begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Intel 386 running FreeBSD with ELF format    Copyright (C) 1996, 2000, 2002 Free Software Foundation, Inc.    Contributed by Eric Youngdale.    Modified for stabs-in-ELF by H.J. Lu.    Adapted from GNU/Linux version by John Polstra.    Continued development by David O'Brien<obrien@freebsd.org>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
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
value|"%(cc1_cpu) %{profile:-p}"
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
value|"%{v*: -v}"
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
value|"\  %{p:%nconsider using `-pg' instead of `-p' with gprof(1) } \     %{Wl,*:%*} \     %{v:-V} \     %{assert*} %{R*} %{rpath*} %{defsym*} \     %{shared:-Bshareable %{h*} %{soname*}} \     %{!shared: \       %{!static: \ 	%{rdynamic: -export-dynamic} \ 	%{!dynamic-linker:-dynamic-linker %(fbsd_dynamic_linker) }} \       %{static:-Bstatic}} \     %{symbolic:-Bsymbolic}"
end_define

begin_comment
comment|/* Reset our STARTFILE_SPEC which was properly set in config/freebsd.h    but trashed by config/<cpu>/<file.h>. */
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
value|FBSD_STARTFILE_SPEC
end_define

begin_comment
comment|/* Provide an ENDFILE_SPEC appropriate for FreeBSD/i386.  */
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
value|FBSD_ENDFILE_SPEC
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
value|(TARGET_64BIT ? "long unsigned int" : "unsigned int")
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
value|(TARGET_64BIT ? "long int" : "int")
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
value|(TARGET_64BIT ? 32 : BITS_PER_WORD)
end_define

begin_undef
undef|#
directive|undef
name|SUBTARGET_EXTRA_SPECS
end_undef

begin_comment
comment|/* i386.h bogusly defines it.  */
end_comment

begin_define
define|#
directive|define
name|SUBTARGET_EXTRA_SPECS
define|\
value|{ "fbsd_dynamic_linker", FBSD_DYNAMIC_LINKER }
end_define

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
name|TARGET_PROFILER_EPILOGUE
value|(target_flags& MASK_PROFILER_EPILOGUE)
end_define

begin_define
define|#
directive|define
name|TARGET_ELF
value|1
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
value|{ "profiler-epilogue",	 MASK_PROFILER_EPILOGUE, "Function profiler epilogue"}, \   { "no-profiler-epilogue",	-MASK_PROFILER_EPILOGUE, "No function profiler epilogue"},
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
comment|/* FreeBSD sets the rounding precision of the FPU to 53 bits.  Let the    compiler get the contents of<float.h> and std::numeric_limits correct.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_96_ROUND_53_LONG_DOUBLE
end_undef

begin_define
define|#
directive|define
name|TARGET_96_ROUND_53_LONG_DOUBLE
value|(!TARGET_64BIT)
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
name|MCOUNT_NAME
end_undef

begin_define
define|#
directive|define
name|MCOUNT_NAME
value|".mcount"
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
comment|/* XXX:DEO do we still need this override to defaults.h ?? */
end_comment

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
value|do {									\     const char *xname = (NAME);						\
comment|/* Hack to avoid writing lots of rtl in				\        FUNCTION_PROFILER_EPILOGUE ().  */
value|\     if (*xname == '.'&& strcmp(xname + 1, "mexitcount") == 0)		\       {									\ 	if (flag_pic)							\ 	  fprintf ((FILE), "*%s@GOT(%%ebx)", xname);			\ 	else								\ 	  fprintf ((FILE), "%s", xname);				\       }									\     else 								\       {									\ 	  if (xname[0] == '%')						\ 	    xname += 2;							\ 	  if (xname[0] == '*')						\ 	    xname += 1;							\ 	  else								\ 	    fputs (user_label_prefix, FILE);				\ 	  fputs (xname, FILE);						\       }									\ } while (0)
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
value|do {					     				\     if ((LOG)!=0) {							\       if (in_text_section())						\ 	fprintf ((FILE), "\t.p2align %d,0x90\n", (LOG));		\       else								\ 	fprintf ((FILE), "\t.p2align %d\n", (LOG));			\     }									\   } while (0)
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

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_MAX_SKIP_ALIGN
end_undef

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
value|do {									\     if ((LOG) != 0) {							\       if ((MAX_SKIP) == 0)						\ 	fprintf ((FILE), "\t.p2align %d\n", (LOG));			\       else								\ 	fprintf ((FILE), "\t.p2align %d,,%d\n", (LOG), (MAX_SKIP));	\     }									\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If defined, a C expression whose value is a string containing the    assembler operation to identify the following data as    uninitialized global data.  If not defined, and neither    `ASM_OUTPUT_BSS' nor `ASM_OUTPUT_ALIGNED_BSS' are defined,    uninitialized global data will be output in the data section if    `-fno-common' is passed, otherwise `ASM_OUTPUT_COMMON' will be    used.  */
end_comment

begin_undef
undef|#
directive|undef
name|BSS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|BSS_SECTION_ASM_OP
value|"\t.section\t.bss"
end_define

begin_comment
comment|/* Like `ASM_OUTPUT_BSS' except takes the required alignment as a    separate, explicit argument.  If you define this macro, it is used    in place of `ASM_OUTPUT_BSS', and gives you more flexibility in    handling the required alignment of the variable.  The alignment is    specified as the number of bits.     Try to use function `asm_output_aligned_bss' defined in file    `varasm.c' when defining this macro.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGNED_BSS
end_undef

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
comment|/************************[  Debugger stuff  ]*********************************/
end_comment

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
comment|/* The same functions are used to creating the DWARF2 debug info and C++    unwind info (except.c).  Regardless of the debug format requested, the    register numbers used in exception unwinding sections still have to be    DWARF compatible.  IMO the GCC folks may be abusing the DBX_REGISTER_NUMBER    macro to mean too much.  */
end_comment

begin_define
define|#
directive|define
name|DWARF_FRAME_REGNUM
parameter_list|(
name|n
parameter_list|)
value|(TARGET_64BIT ? dbx64_register_map[n]	\ 				: svr4_dbx_register_map[(n)])
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
value|do {									\     fprintf (asmfile, "%s %d,0,0,", ASM_STABN_OP, N_LBRAC);		\     assemble_name (asmfile, NAME);					\         fputc ('-', asmfile);						\         assemble_name (asmfile,						\ 	      	 XSTR (XEXP (DECL_RTL (current_function_decl), 0), 0));	\     fprintf (asmfile, "\n");						\   } while (0)
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
value|do {									\     fprintf (asmfile, "%s %d,0,0,", ASM_STABN_OP, N_RBRAC);		\     assemble_name (asmfile, NAME);					\         fputc ('-', asmfile);						\         assemble_name (asmfile,						\ 		 XSTR (XEXP (DECL_RTL (current_function_decl), 0), 0));	\     fprintf (asmfile, "\n");						\   } while (0)
end_define

end_unit

