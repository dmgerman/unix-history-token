begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for GNU compiler for Intel 80x86 running DG/ux    Copyright (C) 1993, 1995, 1996, 1997, 1998 Free Software Foundation, Inc.    Currently maintained by gcc@dg-rtp.dg.com.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* for now, we are just like the sysv4 version with a    few hacks */
end_comment

begin_include
include|#
directive|include
file|"i386/sysv4.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|VERSION_INFO2
end_ifndef

begin_define
define|#
directive|define
name|VERSION_INFO2
value|"$Revision: 1.6 $"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|VERSION_STRING
end_ifndef

begin_define
define|#
directive|define
name|VERSION_STRING
value|version_string
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Identify the compiler.  */
end_comment

begin_comment
comment|/* TARGET_VERSION used by toplev.c VERSION_STRING used by -midentify-revision */
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
value|fprintf (stderr, " (%s%s, %s)", \ 				VERSION_INFO1, VERSION_INFO2, __DATE__)
end_define

begin_undef
undef|#
directive|undef
name|VERSION_INFO1
end_undef

begin_define
define|#
directive|define
name|VERSION_INFO1
value|"ix86 DG/ux, "
end_define

begin_comment
comment|/* Augment TARGET_SWITCHES with the MXDB options.  */
end_comment

begin_define
define|#
directive|define
name|MASK_STANDARD
value|0x40000000
end_define

begin_comment
comment|/* Retain standard information */
end_comment

begin_define
define|#
directive|define
name|MASK_NOLEGEND
value|0x20000000
end_define

begin_comment
comment|/* Discard legend information */
end_comment

begin_define
define|#
directive|define
name|MASK_EXTERNAL_LEGEND
value|0x10000000
end_define

begin_comment
comment|/* Make external legends */
end_comment

begin_define
define|#
directive|define
name|MASK_IDENTIFY_REVISION
value|0x08000000
end_define

begin_comment
comment|/* Emit 'ident' to .s */
end_comment

begin_define
define|#
directive|define
name|MASK_WARN_PASS_STRUCT
value|0x04000000
end_define

begin_comment
comment|/* Warn when structures are passed */
end_comment

begin_define
define|#
directive|define
name|TARGET_STANDARD
value|(target_flags& MASK_STANDARD)
end_define

begin_define
define|#
directive|define
name|TARGET_NOLEGEND
value|(target_flags& MASK_NOLEGEND)
end_define

begin_define
define|#
directive|define
name|TARGET_EXTERNAL_LEGEND
value|(target_flags& MASK_EXTERNAL_LEGEND)
end_define

begin_define
define|#
directive|define
name|TARGET_IDENTIFY_REVISION
value|(target_flags& MASK_IDENTIFY_REVISION)
end_define

begin_define
define|#
directive|define
name|TARGET_WARN_PASS_STRUCT
value|(target_flags& MASK_WARN_PASS_STRUCT)
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
value|{ "standard",			 MASK_STANDARD, "Retain standard MXDB information" },          \     { "legend",				-MASK_NOLEGEND, "Retain legend information" },          \     { "no-legend",			 MASK_NOLEGEND, "" },          \     { "external-legend",		 MASK_EXTERNAL_LEGEND, "Generate external legend information" },   \     { "identify-revision", 		 MASK_IDENTIFY_REVISION, "Emit identifying info in .s file" }, \     { "warn-passed-structs", 		 MASK_WARN_PASS_STRUCT, "Warn when a function arg is a structure" },
end_define

begin_undef
undef|#
directive|undef
name|DWARF_DEBUGGING_INFO
end_undef

begin_define
define|#
directive|define
name|DWARF_DEBUGGING_INFO
end_define

begin_comment
comment|/*   allow -gstabs so that those who have gnu-as installed   can debug c++ programs. */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DWARF_DEBUG
end_define

begin_comment
comment|/* Override svr[34].h.  */
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
value|output_file_start (FILE, f_options, sizeof f_options / sizeof f_options[0], \ 		     W_options, sizeof W_options / sizeof W_options[0])
end_define

begin_comment
comment|/* ix86 abi specified type for wchar_t */
end_comment

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

begin_comment
comment|/* Some machines may desire to change what optimizations are performed for    various optimization levels.   This macro, if defined, is executed once    just after the optimization level is determined and before the remainder    of the command options have been parsed.  Values set in this macro are    used as the default values for the other command line options.     LEVEL is the optimization level specified; 2 if -O2 is specified,    1 if -O is specified, and 0 if neither is specified.  */
end_comment

begin_comment
comment|/* This macro used to store 0 in flag_signed_bitfields.    Not only is that misuse of this macro; the whole idea is wrong.     The GNU C dialect makes bitfields signed by default,    regardless of machine type.  Making any machine inconsistent in this    regard is bad for portability.     I chose to make bitfields signed by default because this is consistent    with the way ordinary variables are handled: `int' equals `signed int'.    If there is a good reason to prefer making bitfields unsigned by default,    it cannot have anything to do with the choice of machine.    If the reason is good enough, we should change the convention for all machines.     -- rms, 20 July 1991.  */
end_comment

begin_comment
comment|/*   this really should go into dgux-local.h  */
end_comment

begin_undef
undef|#
directive|undef
name|OPTIMIZATION_OPTIONS
end_undef

begin_define
define|#
directive|define
name|OPTIMIZATION_OPTIONS
parameter_list|(
name|LEVEL
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|do {							\     extern int flag_signed_bitfields;			\     flag_signed_bitfields = 0;				\     optimization_options (LEVEL,SIZE);			\   } while (0)
end_define

begin_comment
comment|/* The normal location of the `ld' and `as' programs */
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
comment|/* The normal location of the various *crt*.o files is the */
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
comment|/* Macros to be automatically defined.      __CLASSIFY_TYPE__ is used in the<varargs.h> and<stdarg.h> header    files with DG/UX revision 5.40 and later.  This allows GNU CC to    operate without installing the header files.  */
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
value|"-Di386 -D__ix86 -Dunix -DDGUX -D__CLASSIFY_TYPE__=2\    -Asystem(unix) -Asystem(svr4) -Acpu(i386) -Amachine(i386)"
end_define

begin_comment
comment|/*      If not -ansi, -traditional, or restricting include files to one      specific source target, specify full DG/UX features.    */
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
value|"%{!ansi:%{!traditional:-D__OPEN_NAMESPACE__}}"
end_define

begin_comment
comment|/* Assembler support (legends for mxdb).  */
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
value|"\ %{mno-legend:%{mstandard:-Wc,off}}\ %{g:%{!mno-legend:-Wc,-fix-bb,-s\"%i\"\ %{traditional:,-lc}%{!traditional:,-lansi-c}\ %{mstandard:,-keep-std}\ %{mexternal-legend:,-external}}}"
end_define

begin_comment
comment|/* Override svr4.h.  */
end_comment

begin_comment
comment|/* hassey 3/12/94 keep svr4 ASM_FINAL_SPEC allows -pipe to work */
end_comment

begin_comment
comment|/* Linker and library spec's.    -static, -shared, -symbolic, -h* and -z* access AT&T V.4 link options.    -svr4 instructs gcc to place /usr/lib/values-X[cat].o on link the line.    The absence of -msvr4 indicates linking done in a COFF environment and    adds the link script to the link line.  In all environments, the first    and last objects are crtbegin.o and crtend.o.    When the -G link option is used (-shared and -symbolic) a final link is    not being done.  */
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
value|"%{!shared:%{!symbolic:-lc}}"
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
value|"%{z*} %{h*} %{v:-V} \ 		   %{static:-dn -Bstatic} \ 		   %{shared:-G -dy} \ 		   %{symbolic:-Bsymbolic -G -dy} \ 		   %{pg:-L/usr/lib/libp}%{p:-L/usr/lib/libp}"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CROSS_COMPILE
end_ifdef

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%{!shared:%{!symbolic:%{pg:gcrt1.o%s} 		\ 			                      %{!pg:%{p:mcrt1.o%s} 	\ 					      %{!p:crt1.o%s}}}} 	\ 			 %{pg:gcrti.o%s}%{!pg:crti.o%s} 		\ 			 crtbegin.o%s 					\ 			 %{ansi:values-Xc.o%s} 				\ 			 %{!ansi:%{traditional:values-Xt.o%s} 		\ 			         %{!traditional:values-Xa.o%s}}"
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
value|"crtend.o%s %{pg:gcrtn.o}%{!pg:crtn.o%s}"
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"%{!shared:%{!symbolic:%{pg:gcrt1.o%s} 		\ 			                      %{!pg:%{p:/lib/mcrt1.o%s}	\ 					      %{!p:/lib/crt1.o%s}}} 	\ 			%{pg:gcrti.o%s}%{!pg:/lib/crti.o%s}} 		\ 			crtbegin.o%s 					\ 			%{ansi:/lib/values-Xc.o%s} 			\ 			%{!ansi:%{traditional:/lib/values-Xt.o%s} 	\ 			        %{!traditional:/lib/values-Xa.o%s}}"
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
value|"crtend.o%s %{pg:gcrtn.o}%{!pg:/lib/crtn.o}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CROSS_COMPILE */
end_comment

begin_comment
comment|/* The maximum alignment which the object file format can support.    page alignment would seem to be enough */
end_comment

begin_undef
undef|#
directive|undef
name|MAX_OFILE_ALIGNMENT
end_undef

begin_define
define|#
directive|define
name|MAX_OFILE_ALIGNMENT
value|0x1000
end_define

begin_comment
comment|/* Must use data section for relocatable constants when pic.  */
end_comment

begin_undef
undef|#
directive|undef
name|SELECT_RTX_SECTION
end_undef

begin_define
define|#
directive|define
name|SELECT_RTX_SECTION
parameter_list|(
name|MODE
parameter_list|,
name|RTX
parameter_list|)
define|\
value|{                                               \   if (flag_pic&& symbolic_operand (RTX))       \     data_section ();                            \   else                                          \     const_section ();                           \ }
end_define

begin_comment
comment|/* This supplements FUNCTION_ARG's definition in i386.h to check    TARGET_WARN_PASS_STRUCT */
end_comment

begin_undef
undef|#
directive|undef
name|FUNCTION_ARG
end_undef

begin_define
define|#
directive|define
name|FUNCTION_ARG
parameter_list|(
name|CUM
parameter_list|,
name|MODE
parameter_list|,
name|TYPE
parameter_list|,
name|NAMED
parameter_list|)
define|\
value|((((MODE) == BLKmode&& TARGET_WARN_PASS_STRUCT) ? \     warning ("argument is a structure"),0 : 0), \     (function_arg (&CUM, MODE, TYPE, NAMED)))
end_define

begin_comment
comment|/* Add .align 1 to avoid .backalign bug in assembler */
end_comment

begin_undef
undef|#
directive|undef
name|CONST_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|CONST_SECTION_ASM_OP
value|".section\t.rodata\n\t.align 1"
end_define

end_unit

