begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Operating system specific defines to be used when targeting GCC for some    generic System V Release 4 system.    Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001 Free Software Foundation, Inc.    Contributed by Ron Guilmette (rfg@monkeys.com).    Renamed and changed to suit Dynix/ptx v4 and later.    Modified by Tim Wright (timw@sequent.com).    Modified by Janis Johnson (janis@us.ibm.com).    This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Define a symbol indicating that we are using svr4.h.  */
end_comment

begin_define
define|#
directive|define
name|USING_SVR4_H
end_define

begin_comment
comment|/* Use DWARF debugging info by default.  */
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
value|DWARF_DEBUG
end_define

begin_comment
comment|/* Cpp, assembler, linker, library, and startfile spec's.  */
end_comment

begin_comment
comment|/* This defines which switch letters take arguments.  On svr4, most of    the normal cases (defined in gcc.c) apply, and we also have -h* and    -z* options (for the linker).  Note however that there is no such    thing as a -T option for svr4.  */
end_comment

begin_define
define|#
directive|define
name|SWITCH_TAKES_ARG
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|(   (CHAR) == 'D' \    || (CHAR) == 'U' \    || (CHAR) == 'o' \    || (CHAR) == 'e' \    || (CHAR) == 'u' \    || (CHAR) == 'I' \    || (CHAR) == 'm' \    || (CHAR) == 'L' \    || (CHAR) == 'A' \    || (CHAR) == 'h' \    || (CHAR) == 'z')
end_define

begin_comment
comment|/* This defines which multi-letter switches take arguments.  On svr4,    there are no such switches except those implemented by GCC itself.  */
end_comment

begin_define
define|#
directive|define
name|WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
define|\
value|(DEFAULT_WORD_SWITCH_TAKES_ARG (STR)			\&& strcmp (STR, "Tdata")&& strcmp (STR, "Ttext")	\&& strcmp (STR, "Tbss"))
end_define

begin_comment
comment|/* You should redefine CPP_PREDEFINES in any file which includes this one.    The definition should be appropriate for the type of target system    involved, and it should include any -A (assertion) options which are    appropriate for the given target system.  */
end_comment

begin_undef
undef|#
directive|undef
name|CPP_PREDEFINES
end_undef

begin_comment
comment|/* Provide an ASM_SPEC appropriate for svr4.  Here we try to support as    many of the specialized svr4 assembler options as seems reasonable,    given that there are certain options which we can't (or shouldn't)    support directly due to the fact that they conflict with other options     for other svr4 tools (e.g. ld) or with other options for GCC itself.    For example, we don't support the -o (output file) or -R (remove    input file) options because GCC already handles these things.  We    also don't support the -m (run m4) option for the assembler because    that conflicts with the -m (produce load map) option of the svr4    linker.  We do however allow passing arbitrary options to the svr4    assembler via the -Wa, option.     Note that gcc doesn't allow a space to follow -Y in a -Ym,* or -Yd,*    option. */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|USE_GAS
end_ifdef

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"%{v:-V} %{Qy:} %{!Qn:-Qy} %{n} %{T} %{Ym,*} %{Yd,*} %{Wa,*:%*}"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"-no_0f_fix -no_eflags_chk %{v:-V} %{Qy:} %{!Qn:-Qy} %{n} %{T} %{Ym,*} %{Yd,*} %{Wa,*:%*}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* svr4 assemblers need the `-' (indicating input from stdin) to come after    the -o option (and its argument) for some reason.  If we try to put it    before the -o option, the assembler will try to read the file named as    the output file in the -o option as an input file (after it has already    written some stuff to it) and the binary stuff contained therein will    cause totally confuse the assembler, resulting in many spurious error    messages.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FINAL_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_FINAL_SPEC
value|"%{pipe:-}"
end_define

begin_comment
comment|/* Provide a LIB_SPEC appropriate for svr4.  Here we tack on the default    standard C library (unless we are building a shared library).  */
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

begin_comment
comment|/* Provide a LIBGCC_SPEC appropriate for svr4.  We also want to exclude    libgcc when -symbolic.  */
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
value|"%{!shared:%{!symbolic:-lgcc}}"
end_define

begin_comment
comment|/* Provide an ENDFILE_SPEC appropriate for svr4.  Here we tack on our own    magical crtend.o file (see crtstuff.c) which provides part of the    support for getting C++ file-scope static object constructed before    entering `main', followed by the normal svr3/svr4 "finalizer" file,    which is either `gcrtn.o' or `crtn.o'.  */
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
value|"crtend.o%s %{pg:gcrtn.o}%{!pg:crtn.o%s}"
end_define

begin_comment
comment|/* Provide a LINK_SPEC appropriate for svr4.  Here we provide support    for the special GCC options -static, -shared, and -symbolic which    allow us to link things in one of these three modes by applying the    appropriate combinations of options at link-time.  We also provide    support here for as many of the other svr4 linker options as seems    reasonable, given that some of them conflict with options for other    svr4 tools (e.g. the assembler).  In particular, we do support the    -z*, -V, -b, -t, -Qy, -Qn, and -YP* options here, and the -e*,    -l*, -o*, -r, -s, -u*, and -L* options are directly supported    by gcc.c itself.  We don't directly support the -m (generate load    map) option because that conflicts with the -m (run m4) option of    the svr4 assembler.  We also don't directly support the svr4 linker's    -I* or -M* options because these conflict with existing GCC options.    We do however allow passing arbitrary options to the svr4 linker    via the -Wl, option.  We don't support the svr4 linker's -a option    at all because it is totally useless and because it conflicts with    GCC's own -a option.     Note that gcc doesn't allow a space to follow -Y in a -YP,* option.     When the -G link option is used (-shared and -symbolic) a final link is    not being done.  */
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
value|"%{h*} %{v:-V} \ 		   %{b} %{Wl,*:%*} \ 		   %{static:-dn -Bstatic} \ 		   %{shared:-G -dy -z text} \ 		   %{symbolic:-Bsymbolic -G -dy -z text} \ 		   %{G:-G} \ 		   %{YP,*} \ 		   %{!YP,*:%{p:-Y P,/lib/libp:/usr/lib/libp:/lib:/usr/lib} \ 		    %{!p:-Y P,/lib:/usr/lib}} \ 		   %{Qy:} %{!Qn:-Qy}"
end_define

begin_comment
comment|/* Gcc automatically adds in one of the files /lib/values-Xc.o,    /lib/values-Xa.o, or /lib/values-Xt.o for each final link    step (depending upon the other gcc options selected, such as    -traditional and -ansi).  These files each contain one (initialized)    copy of a special variable called `_lib_version'.  Each one of these    files has `_lib_version' initialized to a different (enum) value.    The SVR4 library routines query the value of `_lib_version' at run    to decide how they should behave.  Specifically, they decide (based    upon the value of `_lib_version') if they will act in a strictly ANSI    conforming manner or not. */
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
value|"%{!shared: \ 			 %{!symbolic: \ 			  %{pg:gcrt1.o%s}%{!pg:%{p:mcrt1.o%s}%{!p:crt1.o%s}}}}\ 			%{pg:gcrti.o%s}%{!pg:crti.o%s} \ 			%{ansi:values-Xc.o%s} \ 			%{!ansi: \ 			 %{traditional:values-Xt.o%s} \ 			 %{!traditional:values-Xa.o%s}} \  			crtbegin.o%s"
end_define

begin_comment
comment|/* Allow #sccs in preprocessor.  */
end_comment

begin_define
define|#
directive|define
name|SCCS_DIRECTIVE
end_define

begin_comment
comment|/* Don't use bcopy, which doesn't handle overlaps before DYNIX/ptx 4.6. */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_BCOPY
end_undef

begin_comment
comment|/* The numbers used to denote specific machine registers in the System V    Release 4 DWARF debugging information are quite likely to be totally    different from the numbers used in BSD stabs debugging information    for the same kind of target machine.  Thus, we undefine the macro    DBX_REGISTER_NUMBER here as an extra inducement to get people to    provide proper machine-specific definitions of DBX_REGISTER_NUMBER    (which is also used to provide DWARF registers numbers in dwarfout.c)    in their tm.h files which include this file.  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_REGISTER_NUMBER
end_undef

begin_comment
comment|/* Like block addresses, stabs line numbers are relative to the    current function.  */
end_comment

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
name|file
parameter_list|,
name|line
parameter_list|)
define|\
value|do									\   {									\     static int sym_lineno = 1;						\     fprintf (file, ".stabn 68,0,%d,.LM%d-",				\ 	     line, sym_lineno);						\     assemble_name (file,						\ 		   XSTR (XEXP (DECL_RTL (current_function_decl), 0), 0));\     fprintf (file, "\n.LM%d:\n", sym_lineno);				\     sym_lineno += 1;							\   }									\ while (0)
end_define

begin_comment
comment|/* Generate a blank trailing N_SO to mark the end of the .o file, since    we can't depend upon the linker to mark .o file boundaries with    embedded stabs.  */
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
value|fprintf (FILE,							\ 	   "\t.text\n\t.stabs \"\",%d,0,0,.Letext\n.Letext:\n", N_SO)
end_define

begin_comment
comment|/* Define the actual types of some ANSI-mandated types.  (These    definitions should work for most SVR4 systems).  */
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
comment|/* This says how to output assembler code to declare an uninitialized    external linkage data item.  There's a bug in the DYNIX/ptx linker    (PR 254649) when the alignment for such an object is specified, so    ignore the ALIGN parameter. */
end_comment

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
value|do {									\   fprintf ((FILE), "%s", COMMON_ASM_OP);				\   assemble_name ((FILE), (NAME));					\   fprintf ((FILE), ",%u\n", (SIZE));					\ } while (0)
end_define

end_unit

