begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler.    Motorola m88100 running DG/UX.    Copyright (C) 1988, 1989, 1990, 1991 Free Software Foundation, Inc.    Contributed by Michael Tiemann (tiemann@mcc.com)    Enhanced by Michael Meissner (meissner@osf.org)    Currently supported by Tom Wood (wood@dg-rtp.dg.com)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* You're not seeing double!  To transition to dwarf debugging, both are    supported.  The option -msvr4 and -mversion-03.00 specify (for DG/UX)    `real' elf.  With these combinations, -g means dwarf.  */
end_comment

begin_comment
comment|/* DWARF_DEBUGGING_INFO defined in svr4.h.  */
end_comment

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
define|\
value|(GET_VERSION_0300_SYNTAX ? DWARF_DEBUG : SDB_DEBUG)
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|NO_BUGS
end_ifndef

begin_define
define|#
directive|define
name|AS_BUG_IMMEDIATE_LABEL
end_define

begin_comment
comment|/* The DG/UX 4.30 assembler doesn't accept the symbol `fcr63'.  */
end_comment

begin_define
define|#
directive|define
name|AS_BUG_FLDCR
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"svr4.h"
end_include

begin_include
include|#
directive|include
file|"m88k.h"
end_include

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
name|MASK_LEGEND
value|0x20000000
end_define

begin_comment
comment|/* Retain legend information */
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
name|TARGET_STANDARD
value|(target_flags& MASK_STANDARD)
end_define

begin_define
define|#
directive|define
name|TARGET_LEGEND
value|(target_flags& MASK_LEGEND)
end_define

begin_define
define|#
directive|define
name|TARGET_EXTERNAL_LEGEND
value|(target_flags& MASK_EXTERNAL_LEGEND)
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
value|{ "standard",			 MASK_STANDARD }, \     { "legend",				 MASK_LEGEND }, \     { "external-legend",		 MASK_EXTERNAL_LEGEND }, \
comment|/* the following is used only in the *_SPEC's */
value|\     { "keep-coff",			 0 },
end_define

begin_comment
comment|/* Default switches */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_CHECK_ZERO_DIV	 | \ 			 MASK_OCS_DEBUG_INFO	 | \ 			 MASK_OCS_FRAME_POSITION)
end_define

begin_undef
undef|#
directive|undef
name|CPU_DEFAULT
end_undef

begin_define
define|#
directive|define
name|CPU_DEFAULT
value|MASK_88000
end_define

begin_comment
comment|/* Macros to be automatically defined.  __svr4__ is our extension.    __CLASSIFY_TYPE__ is used in the<varargs.h> and<stdarg.h> header    files with DG/UX revision 5.40 and later.  This allows GNU CC to    operate without installing the header files.  */
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
value|"-Dm88000 -Dm88k -Dunix -DDGUX -D__CLASSIFY_TYPE__=2\    -D__svr4__ -Asystem(unix) -Acpu(m88k) -Amachine(m88k)"
end_define

begin_comment
comment|/* If -m88100 is in effect, add -Dm88100; similarly for -m88110.    Here, the CPU_DEFAULT is assumed to be -m88000.  If not -ansi,    -traditional, or restricting include files to one specific source    target, specify full DG/UX features.  */
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
value|"%{!m88000:%{!m88100:%{m88110:-D__m88110__}}} \ 		  %{!m88000:%{!m88110:%{m88100:-D__m88100__}}} \ 		  %{!ansi:%{!traditional:-D__OPEN_NAMESPACE__}}"
end_define

begin_comment
comment|/* Assembler support (-V, silicon filter, legends for mxdb).  */
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
value|"\ %{V} %{v:%{!V:-V}} %{pipe: - %{msvr4:%{mversion-03.00:-KV3}}}\ %{!mlegend:%{mstandard:-Wc,off}}\ %{mlegend:-Wc,-fix-bb,-h\"gcc-2.2.14\",-s\"%i\"\ %{traditional:,-lc}%{!traditional:,-lansi-c}\ %{mstandard:,-keep-std}\ %{mkeep-coff:,-keep-coff}\ %{mexternal-legend:,-external}\ %{mocs-frame-position:,-ocs}}"
end_define

begin_comment
comment|/* Override svr4.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FINAL_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|STARTFILE_SPEC
end_undef

begin_comment
comment|/* Linker and library spec's.    -static, -shared, -symbolic, -h* and -z* access AT&T V.4 link options.    -svr4 instructs gcc to place /usr/lib/values-X[cat].o on link the line.    When the -G link option is used (-shared and -symbolic) a final link is    not being done.  */
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
value|"%{z*} %{h*} %{V} %{v:%{!V:-V}} \ 		   %{static:-dn -Bstatic} \ 		   %{shared:-G -dy} \ 		   %{symbolic:-Bsymbolic -G -dy} \ 		   %{pg:-L/usr/lib/libp}%{p:-L/usr/lib/libp}"
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
value|"%{!shared:%{!symbolic:%{pg:gcrt0.o%s} \ 			 %{!pg:%{p:/lib/mcrt0.o}%{!p:/lib/crt0.o}} \ 			 %{svr4:%{ansi:/lib/values-Xc.o} \ 			  %{!ansi:%{traditional:/lib/values-Xt.o} \ 			   %{!traditional:/usr/lib/values-Xa.o}}}}}"
end_define

begin_undef
undef|#
directive|undef
name|GPLUSPLUS_INCLUDE_DIR
end_undef

begin_define
define|#
directive|define
name|GPLUSPLUS_INCLUDE_DIR
value|"/usr/opt/g++/lib/g++-include"
end_define

begin_comment
comment|/* Fast DG/UX version of profiler that does not require lots of    registers to be stored.  */
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
value|output_function_profiler (FILE, LABELNO, "gcc.mcount", 0)
end_define

begin_comment
comment|/* DGUX V.4 isn't quite ELF--yet.  */
end_comment

begin_undef
undef|#
directive|undef
name|VERSION_0300_SYNTAX
end_undef

begin_define
define|#
directive|define
name|VERSION_0300_SYNTAX
value|(TARGET_SVR4&& m88k_version_0300)
end_define

begin_comment
comment|/* Same, but used before OVERRIDE_OPTIONS has been processed.  */
end_comment

begin_define
define|#
directive|define
name|GET_VERSION_0300_SYNTAX
define|\
value|(TARGET_SVR4&& m88k_version != 0&& strcmp (m88k_version, "03.00")>= 0)
end_define

begin_comment
comment|/* Output the legend info for mxdb when debugging except if standard    debugging information only is explicitly requested.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FIRST_LINE
end_undef

begin_define
define|#
directive|define
name|ASM_FIRST_LINE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do {									\     if (VERSION_0300_SYNTAX)						\       fprintf (FILE, "\t%s\t \"03.00\"\n", VERSION_ASM_OP);		\     if (write_symbols != NO_DEBUG					\&& ! (TARGET_STANDARD&& ! TARGET_LEGEND))			\       {									\ 	fprintf (FILE, ";legend_info -fix-bb -h\"gcc-%s\" -s\"%s\"",	\ 		 VERSION_STRING, main_input_filename);			\ 	fputs (flag_traditional ? " -lc" : " -lansi-c", FILE);		\ 	if (TARGET_STANDARD)						\ 	  fputs (" -keep-std", FILE);					\ 	if (TARGET_EXTERNAL_LEGEND)					\ 	  fputs (" -external", FILE);					\ 	if (TARGET_OCS_FRAME_POSITION)					\ 	  fputs (" -ocs", FILE);					\ 	fputc ('\n', FILE);						\       }									\   } while (0)
end_define

begin_comment
comment|/* Override svr4.h.  */
end_comment

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

begin_comment
comment|/* Override svr4.h and m88k.h except when compiling crtstuff.c.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|CRT_BEGIN
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CRT_END
argument_list|)
end_if

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* The SVR4 init method doesn't yet work.  */
end_comment

begin_undef
undef|#
directive|undef
name|INIT_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|INIT_SECTION_ASM_OP
value|(VERSION_0300_SYNTAX		\ 			     ? "section\t .init,\"xa\""	\ 			     : "section\t .init,\"x\"")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|CTORS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|(VERSION_0300_SYNTAX		\ 			      ? "section\t .ctors,\"aw\""	\ 			      : "section\t .ctors,\"d\"")
end_define

begin_undef
undef|#
directive|undef
name|DTORS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|(VERSION_0300_SYNTAX		\ 			      ? "section\t .dtors,\"aw\""	\ 			      : "section\t .dtors,\"d\"")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* crtstuff.c */
end_comment

end_unit

