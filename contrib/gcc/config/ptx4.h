begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Operating system specific defines to be used when targeting GCC for some    generic System V Release 4 system.    Copyright (C) 1996, 1997, 1998, 1999 Free Software Foundation, Inc.    Contributed by Ron Guilmette (rfg@monkeys.com).    Renamed and changed to suit Dynix/ptx v4 and later.    Modified by Tim Wright (timw@sequent.com).    This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
comment|/* For the sake of libgcc2.c, indicate target supports atexit.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
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

begin_define
define|#
directive|define
name|ASM_SPEC
define|\
value|"-no_0f_fix %{v:-V} %{Qy:} %{!Qn:-Qy} %{n} %{T} %{Ym,*} %{Yd,*} %{Wa,*:%*}"
end_define

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
comment|/* Attach a special .ident directive to the end of the file to identify    the version of GCC which compiled this code.  The format of the    .ident string is patterned after the ones produced by native svr4    C compilers.  */
end_comment

begin_define
define|#
directive|define
name|IDENT_ASM_OP
value|".ident"
end_define

begin_define
define|#
directive|define
name|ASM_FILE_END
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do {				 				\      if (!flag_no_ident)					\ 	fprintf ((FILE), "\t%s\t\"GCC: (GNU) %s\"\n",		\ 		 IDENT_ASM_OP, version_string);			\    } while (0)
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
comment|/* Output #ident as a .ident.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_IDENT
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|fprintf (FILE, "\t%s\t\"%s\"\n", IDENT_ASM_OP, NAME);
end_define

begin_comment
comment|/* Use periods rather than dollar signs in special g++ assembler names.  */
end_comment

begin_define
define|#
directive|define
name|NO_DOLLAR_IN_LABEL
end_define

begin_comment
comment|/* Writing `int' for a bitfield forces int alignment for the structure.  */
end_comment

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_comment
comment|/* Implicit library calls should use memcpy, not bcopy, etc.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* Handle #pragma weak and #pragma pack.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
end_define

begin_comment
comment|/* System V Release 4 uses DWARF debugging info.  */
end_comment

begin_define
define|#
directive|define
name|DWARF_DEBUGGING_INFO
end_define

begin_comment
comment|/* The numbers used to denote specific machine registers in the System V    Release 4 DWARF debugging information are quite likely to be totally    different from the numbers used in BSD stabs debugging information    for the same kind of target machine.  Thus, we undefine the macro    DBX_REGISTER_NUMBER here as an extra inducement to get people to    provide proper machine-specific definitions of DBX_REGISTER_NUMBER    (which is also used to provide DWARF registers numbers in dwarfout.c)    in their tm.h files which include this file.  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_REGISTER_NUMBER
end_undef

begin_comment
comment|/* gas on SVR4 supports the use of .stabs.  Permit -gstabs to be used    in general, although it will only work when using gas.  */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* Use DWARF debugging info by default.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PREFERRED_DEBUGGING_TYPE
end_ifndef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DWARF_DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Make LBRAC and RBRAC addresses relative to the start of the    function.  The native Solaris stabs debugging format works this    way, gdb expects it, and it reduces the number of relocation    entries.  */
end_comment

begin_define
define|#
directive|define
name|DBX_BLOCKS_FUNCTION_RELATIVE
value|1
end_define

begin_comment
comment|/* When using stabs, gcc2_compiled must be a stabs entry, not an    ordinary symbol, or gdb won't see it.  The stabs entry must be    before the N_SO in order for gdb to find it.  */
end_comment

begin_define
define|#
directive|define
name|ASM_IDENTIFY_GCC
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do									\   {									\     if (write_symbols != DBX_DEBUG)					\       fputs ("gcc2_compiled.:\n", FILE);				\     else								\       fputs ("\t.stabs\t\"gcc2_compiled.\", 0x3c, 0, 0, 0\n", FILE);	\   }									\ while (0)
end_define

begin_comment
comment|/* Like block addresses, stabs line numbers are relative to the    current function.  */
end_comment

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
comment|/* In order for relative line numbers to work, we must output the    stabs entry for the function name first.  */
end_comment

begin_define
define|#
directive|define
name|DBX_FUNCTION_FIRST
end_define

begin_comment
comment|/* Generate a blank trailing N_SO to mark the end of the .o file, since    we can't depend upon the linker to mark .o file boundaries with    embedded stabs.  */
end_comment

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
comment|/* This causes trouble, because it requires the host machine    to support ANSI C.  */
end_comment

begin_comment
comment|/* #define MULTIBYTE_CHARS */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_BYTE_OP
end_undef

begin_define
define|#
directive|define
name|ASM_BYTE_OP
value|".byte"
end_define

begin_undef
undef|#
directive|undef
name|SET_ASM_OP
end_undef

begin_define
define|#
directive|define
name|SET_ASM_OP
value|".set"
end_define

begin_comment
comment|/* This is how to begin an assembly language file.  Most svr4 assemblers want    at least a .file directive to come first, and some want to see a .version    directive come right after that.  Here we just establish a default    which generates only the .file directive.  If you need a .version    directive for any specific target, you should override this definition    in the target-specific file which includes this one.  */
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
value|output_file_directive ((FILE), main_input_filename)
end_define

begin_comment
comment|/* This is how to allocate empty space in some section.  The .zero    pseudo-op is used for this on most svr4 assemblers.  */
end_comment

begin_define
define|#
directive|define
name|SKIP_ASM_OP
value|".zero"
end_define

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
value|fprintf (FILE, "\t%s\t%u\n", SKIP_ASM_OP, (SIZE))
end_define

begin_comment
comment|/* The prefix to add to user-visible assembler symbols.     For System V Release 4 the convention is *not* to prepend a leading    underscore onto user-level symbol names.  */
end_comment

begin_undef
undef|#
directive|undef
name|USER_LABEL_PREFIX
end_undef

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|""
end_define

begin_comment
comment|/* This is how to output an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.     For most svr4 systems, the convention is that any symbol which begins    with a period is not put into the linker symbol table by the assembler. */
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
value|do {									\   fprintf (FILE, ".%s%d:\n", PREFIX, NUM);				\ } while (0)
end_define

begin_comment
comment|/* This is how to store into the string LABEL    the symbol_ref name of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    This is suitable for output with `assemble_name'.     For most svr4 systems, the convention is that any symbol which begins    with a period is not put into the linker symbol table by the assembler. */
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
value|do {									\   sprintf (LABEL, "*.%s%d", PREFIX, NUM);				\ } while (0)
end_define

begin_comment
comment|/* Output the label which precedes a jumptable.  Note that for all svr4    systems where we actually generate jumptables (which is to say every    svr4 target except i386, where we use casesi instead) we put the jump-    tables into the .rodata section and since other stuff could have been    put into the .rodata section prior to any given jumptable, we have to    make sure that the location counter for the .rodata section gets pro-    perly re-aligned prior to the actual beginning of the jump table.  */
end_comment

begin_define
define|#
directive|define
name|ALIGN_ASM_OP
value|".align"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_BEFORE_CASE_LABEL
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_BEFORE_CASE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|,
name|TABLE
parameter_list|)
define|\
value|ASM_OUTPUT_ALIGN ((FILE), 2);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_CASE_LABEL
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_CASE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|,
name|JUMPTABLE
parameter_list|)
define|\
value|do {									\     ASM_OUTPUT_BEFORE_CASE_LABEL (FILE, PREFIX, NUM, JUMPTABLE)		\     ASM_OUTPUT_INTERNAL_LABEL (FILE, PREFIX, NUM);			\   } while (0)
end_define

begin_comment
comment|/* The standard SVR4 assembler seems to require that certain builtin    library routines (e.g. .udiv) be explicitly declared as .globl    in each assembly file where they are referenced.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_EXTERNAL_LIBCALL
parameter_list|(
name|FILE
parameter_list|,
name|FUN
parameter_list|)
define|\
value|ASM_GLOBALIZE_LABEL (FILE, XSTR (FUN, 0))
end_define

begin_comment
comment|/* This says how to output assembler code to declare an    uninitialized external linkage data object.  Under SVR4,    the linker seems to want the alignment of data objects    to depend on their types.  We do exactly that here.  */
end_comment

begin_define
define|#
directive|define
name|COMMON_ASM_OP
value|".comm"
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
value|do {									\   fprintf ((FILE), "\t%s\t", COMMON_ASM_OP);				\   assemble_name ((FILE), (NAME));					\   fprintf ((FILE), ",%u,%u\n", (SIZE), (ALIGN) / BITS_PER_UNIT);	\ } while (0)
end_define

begin_comment
comment|/* This says how to output assembler code to declare an    uninitialized internal linkage data object.  Under SVR4,    the linker seems to want the alignment of data objects    to depend on their types.  We do exactly that here.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_ASM_OP
value|".local"
end_define

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
value|do {									\   fprintf ((FILE), "\t%s\t", LOCAL_ASM_OP);				\   assemble_name ((FILE), (NAME));					\   fprintf ((FILE), "\n");						\   ASM_OUTPUT_ALIGNED_COMMON (FILE, NAME, SIZE, ALIGN);			\ } while (0)
end_define

begin_comment
comment|/* This is the pseudo-op used to generate a 32-bit word of data with a    specific value in some section.  This is the same for all known svr4    assemblers.  */
end_comment

begin_define
define|#
directive|define
name|INT_ASM_OP
value|".long"
end_define

begin_comment
comment|/* This is the pseudo-op used to generate a contiguous sequence of byte    values from a double-quoted string WITHOUT HAVING A TERMINATING NUL    AUTOMATICALLY APPENDED.  This is the same for most svr4 assemblers.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASCII_DATA_ASM_OP
end_undef

begin_define
define|#
directive|define
name|ASCII_DATA_ASM_OP
value|".ascii"
end_define

begin_comment
comment|/* Support const sections and the ctors and dtors sections for g++.    Note that there appears to be two different ways to support const    sections at the moment.  You can either #define the symbol    READONLY_DATA_SECTION (giving it some code which switches to the    readonly data section) or else you can #define the symbols    EXTRA_SECTIONS, EXTRA_SECTION_FUNCTIONS, SELECT_SECTION, and    SELECT_RTX_SECTION.  We do both here just to be on the safe side.  */
end_comment

begin_define
define|#
directive|define
name|USE_CONST_SECTION
value|1
end_define

begin_define
define|#
directive|define
name|CONST_SECTION_ASM_OP
value|".section\t.rodata"
end_define

begin_comment
comment|/* Define the pseudo-ops used to switch to the .ctors and .dtors sections.     Note that we want to give these sections the SHF_WRITE attribute    because these sections will actually contain data (i.e. tables of    addresses of functions in the current root executable or shared library    file) and, in the case of a shared library, the relocatable addresses    will have to be properly resolved/relocated (and then written into) by    the dynamic linker when it actually attaches the given shared library    to the executing process.  (Note that on SVR4, you may wish to use the    `-z text' option to the ELF linker, when building a shared library, as    an additional check that you are doing everything right.  But if you do    use the `-z text' option when building a shared library, you will get    errors unless the .ctors and .dtors sections are marked as writable    via the SHF_WRITE attribute.)  */
end_comment

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|".section\t.ctors,\"aw\""
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|".section\t.dtors,\"aw\""
end_define

begin_comment
comment|/* On svr4, we *do* have support for the .init and .fini sections, and we    can put stuff in there to be executed before and after `main'.  We let    crtstuff.c and other files know this by defining the following symbols.    The definitions say how to change sections to the .init and .fini    sections.  This is the same for all known svr4 assemblers.  */
end_comment

begin_define
define|#
directive|define
name|INIT_SECTION_ASM_OP
value|".section\t.init"
end_define

begin_define
define|#
directive|define
name|FINI_SECTION_ASM_OP
value|".section\t.fini"
end_define

begin_comment
comment|/* A default list of other sections which we might be "in" at any given    time.  For targets that use additional sections (e.g. .tdesc) you    should override this definition in the target-specific file which    includes this file.  */
end_comment

begin_undef
undef|#
directive|undef
name|EXTRA_SECTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
value|in_const, in_ctors, in_dtors
end_define

begin_comment
comment|/* A default list of extra section function definitions.  For targets    that use additional sections (e.g. .tdesc) you should override this    definition in the target-specific file which includes this file.  */
end_comment

begin_undef
undef|#
directive|undef
name|EXTRA_SECTION_FUNCTIONS
end_undef

begin_define
define|#
directive|define
name|EXTRA_SECTION_FUNCTIONS
define|\
value|CONST_SECTION_FUNCTION						\   CTORS_SECTION_FUNCTION						\   DTORS_SECTION_FUNCTION
end_define

begin_define
define|#
directive|define
name|READONLY_DATA_SECTION
parameter_list|()
value|const_section ()
end_define

begin_function_decl
specifier|extern
name|void
name|text_section
parameter_list|()
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|CONST_SECTION_FUNCTION
define|\
value|void									\ const_section ()							\ {									\   if (!USE_CONST_SECTION)						\     text_section();							\   else if (in_section != in_const)					\     {									\       fprintf (asm_out_file, "%s\n", CONST_SECTION_ASM_OP);		\       in_section = in_const;						\     }									\ }
end_define

begin_define
define|#
directive|define
name|CTORS_SECTION_FUNCTION
define|\
value|void									\ ctors_section ()							\ {									\   if (in_section != in_ctors)						\     {									\       fprintf (asm_out_file, "%s\n", CTORS_SECTION_ASM_OP);		\       in_section = in_ctors;						\     }									\ }
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_FUNCTION
define|\
value|void									\ dtors_section ()							\ {									\   if (in_section != in_dtors)						\     {									\       fprintf (asm_out_file, "%s\n", DTORS_SECTION_ASM_OP);		\       in_section = in_dtors;						\     }									\ }
end_define

begin_comment
comment|/* Switch into a generic section.    This is currently only used to support section attributes.     We make the section read-only and executable for a function decl,    read-only for a const data decl, and writable for a non-const data decl. */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SECTION_NAME
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|,
name|RELOC
parameter_list|)
define|\
value|fprintf (FILE, ".section\t%s,\"%s\",@progbits\n", NAME, \ 	   (DECL)&& TREE_CODE (DECL) == FUNCTION_DECL ? "ax" : \ 	   (DECL)&& DECL_READONLY_SECTION (DECL, RELOC) ? "a" : "aw")
end_define

begin_comment
comment|/* A C statement (sans semicolon) to output an element in the table of    global constructors.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_CONSTRUCTOR
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\     ctors_section ();							\     fprintf (FILE, "\t%s\t ", INT_ASM_OP);				\     assemble_name (FILE, NAME);						\     fprintf (FILE, "\n");						\   } while (0)
end_define

begin_comment
comment|/* A C statement (sans semicolon) to output an element in the table of    global destructors.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_DESTRUCTOR
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {									\     dtors_section ();                   				\     fprintf (FILE, "\t%s\t ", INT_ASM_OP);				\     assemble_name (FILE, NAME);              				\     fprintf (FILE, "\n");						\   } while (0)
end_define

begin_comment
comment|/* A C statement or statements to switch to the appropriate    section for output of DECL.  DECL is either a `VAR_DECL' node    or a constant of some sort.  RELOC indicates whether forming    the initial value of DECL requires link-time relocations.  */
end_comment

begin_define
define|#
directive|define
name|SELECT_SECTION
parameter_list|(
name|DECL
parameter_list|,
name|RELOC
parameter_list|)
define|\
value|{									\   if (TREE_CODE (DECL) == STRING_CST)					\     {									\       if (! flag_writable_strings)					\ 	const_section ();						\       else								\ 	data_section ();						\     }									\   else if (TREE_CODE (DECL) == VAR_DECL)				\     {									\       if ((flag_pic&& RELOC)						\ 	  || !TREE_READONLY (DECL) || TREE_SIDE_EFFECTS (DECL)		\ 	  || !DECL_INITIAL (DECL)					\ 	  || (DECL_INITIAL (DECL) != error_mark_node			\&& !TREE_CONSTANT (DECL_INITIAL (DECL))))			\ 	data_section ();						\       else								\ 	const_section ();						\     }									\   else									\     const_section ();							\ }
end_define

begin_comment
comment|/* A C statement or statements to switch to the appropriate    section for output of RTX in mode MODE.  RTX is some kind    of constant in RTL.  The argument MODE is redundant except    in the case of a `const_int' rtx.  Currently, these always    go into the const section.  */
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
value|const_section()
end_define

begin_comment
comment|/* Define the strings used for the special svr4 .type and .size directives.    These strings generally do not vary from one system running svr4 to    another, but if a given system (e.g. m88k running svr) needs to use    different pseudo-op names for these, they may be overridden in the    file which includes this one.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_ASM_OP
value|".type"
end_define

begin_define
define|#
directive|define
name|SIZE_ASM_OP
value|".size"
end_define

begin_comment
comment|/* This is how we tell the assembler that a symbol is weak.  */
end_comment

begin_define
define|#
directive|define
name|ASM_WEAKEN_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do { fputs ("\t.weak\t", FILE); assemble_name (FILE, NAME); \        fputc ('\n', FILE); } while (0)
end_define

begin_comment
comment|/* The following macro defines the format used to output the second    operand of the .type assembler directive.  Different svr4 assemblers    expect various different forms for this operand.  The one given here    is just a default.  You may need to override it in your machine-    specific tm.h file (depending upon the particulars of your assembler).  */
end_comment

begin_define
define|#
directive|define
name|TYPE_OPERAND_FMT
value|"@%s"
end_define

begin_comment
comment|/* Write the extra assembler code needed to declare a function's result.    Most svr4 assemblers don't require any special declaration of the    result value, but there are exceptions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_DECLARE_RESULT
end_ifndef

begin_define
define|#
directive|define
name|ASM_DECLARE_RESULT
parameter_list|(
name|FILE
parameter_list|,
name|RESULT
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These macros generate the special .type and .size directives which    are used to set the corresponding fields of the linker symbol table    entries in an ELF object file under SVR4.  These macros also output    the starting labels for the relevant functions/objects.  */
end_comment

begin_comment
comment|/* Write the extra assembler code needed to declare a function properly.    Some svr4 assemblers need to also have something extra said about the    function's return value.  We allow for that here.  */
end_comment

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_NAME
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do {									\     fprintf (FILE, "\t%s\t ", TYPE_ASM_OP);				\     assemble_name (FILE, NAME);						\     putc (',', FILE);							\     fprintf (FILE, TYPE_OPERAND_FMT, "function");			\     putc ('\n', FILE);							\     ASM_DECLARE_RESULT (FILE, DECL_RESULT (DECL));			\     ASM_OUTPUT_LABEL(FILE, NAME);					\   } while (0)
end_define

begin_comment
comment|/* Write the extra assembler code needed to declare an object properly.  */
end_comment

begin_define
define|#
directive|define
name|ASM_DECLARE_OBJECT_NAME
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do {									\     fprintf (FILE, "\t%s\t ", TYPE_ASM_OP);				\     assemble_name (FILE, NAME);						\     putc (',', FILE);							\     fprintf (FILE, TYPE_OPERAND_FMT, "object");				\     putc ('\n', FILE);							\     size_directive_output = 0;						\     if (!flag_inhibit_size_directive&& DECL_SIZE (DECL))		\       {									\ 	size_directive_output = 1;					\ 	fprintf (FILE, "\t%s\t ", SIZE_ASM_OP);				\ 	assemble_name (FILE, NAME);					\ 	fprintf (FILE, ",%d\n",  int_size_in_bytes (TREE_TYPE (DECL)));	\       }									\     ASM_OUTPUT_LABEL(FILE, NAME);					\   } while (0)
end_define

begin_comment
comment|/* Output the size directive for a decl in rest_of_decl_compilation    in the case where we did not do so before the initializer.    Once we find the error_mark_node, we know that the value of    size_directive_output was set    by ASM_DECLARE_OBJECT_NAME when it was run for the same decl.  */
end_comment

begin_define
define|#
directive|define
name|ASM_FINISH_DECLARE_OBJECT
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|TOP_LEVEL
parameter_list|,
name|AT_END
parameter_list|)
define|\
value|do {									 \      char *name = XSTR (XEXP (DECL_RTL (DECL), 0), 0);			 \      if (!flag_inhibit_size_directive&& DECL_SIZE (DECL)		 \&& ! AT_END&& TOP_LEVEL					 \&& DECL_INITIAL (DECL) == error_mark_node			 \&& !size_directive_output)					 \        {								 \ 	 size_directive_output = 1;					 \ 	 fprintf (FILE, "\t%s\t ", SIZE_ASM_OP);			 \ 	 assemble_name (FILE, name);					 \ 	 fprintf (FILE, ",%d\n",  int_size_in_bytes (TREE_TYPE (DECL))); \        }								 \    } while (0)
end_define

begin_comment
comment|/* This is how to declare the size of a function.  */
end_comment

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_SIZE
parameter_list|(
name|FILE
parameter_list|,
name|FNAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|do {									\     if (!flag_inhibit_size_directive)					\       {									\         char label[256];						\ 	static int labelno;						\ 	labelno++;							\ 	ASM_GENERATE_INTERNAL_LABEL (label, "Lfe", labelno);		\ 	ASM_OUTPUT_INTERNAL_LABEL (FILE, "Lfe", labelno);		\ 	fprintf (FILE, "\t%s\t ", SIZE_ASM_OP);				\ 	assemble_name (FILE, (FNAME));					\         fprintf (FILE, ",");						\ 	assemble_name (FILE, label);					\         fprintf (FILE, "-");						\ 	assemble_name (FILE, (FNAME));					\ 	putc ('\n', FILE);						\       }									\   } while (0)
end_define

begin_comment
comment|/* A table of bytes codes used by the ASM_OUTPUT_ASCII and    ASM_OUTPUT_LIMITED_STRING macros.  Each byte in the table    corresponds to a particular byte value [0..255].  For any    given byte value, if the value in the corresponding table    position is zero, the given character can be output directly.    If the table value is 1, the byte must be output as a \ooo    octal escape.  If the tables value is anything else, then the    byte value should be output as a \ followed by the value    in the table.  Note that we can use standard UN*X escape    sequences for many control characters, but we don't use    \a to represent BEL because some svr4 assemblers (e.g. on    the i386) don't know about that.  Also, we don't use \v    since some versions of gas, such as 2.2 did not accept it.  */
end_comment

begin_define
define|#
directive|define
name|ESCAPES
define|\
value|"\1\1\1\1\1\1\1\1btn\1fr\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\ \0\0\"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\ \0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\\\0\0\0\ \0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\ \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\ \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\ \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\ \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1"
end_define

begin_comment
comment|/* Some svr4 assemblers have a limit on the number of characters which    can appear in the operand of a .string directive.  If your assembler    has such a limitation, you should define STRING_LIMIT to reflect that    limit.  Note that at least some svr4 assemblers have a limit on the    actual number of bytes in the double-quoted string, and that they    count each character in an escape sequence as one byte.  Thus, an    escape sequence like \377 would count as four bytes.     If your target assembler doesn't support the .string directive, you    should define this to zero. */
end_comment

begin_define
define|#
directive|define
name|STRING_LIMIT
value|((unsigned) 256)
end_define

begin_define
define|#
directive|define
name|STRING_ASM_OP
value|".string"
end_define

begin_comment
comment|/* The routine used to output NUL terminated strings.  We use a special    version of this for most svr4 targets because doing so makes the    generated assembly code more compact (and thus faster to assemble)    as well as more readable, especially for targets like the i386    (where the only alternative is to output character sequences as    comma separated lists of numbers).   */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_LIMITED_STRING
parameter_list|(
name|FILE
parameter_list|,
name|STR
parameter_list|)
define|\
value|do									\     {									\       register unsigned char *_limited_str = (unsigned char *) (STR);	\       register unsigned ch;						\       fprintf ((FILE), "\t%s\t\"", STRING_ASM_OP);			\       for (; ch = *_limited_str; _limited_str++)			\         {								\ 	  register int escape;						\ 	  switch (escape = ESCAPES[ch])					\ 	    {								\ 	    case 0:							\ 	      putc (ch, (FILE));					\ 	      break;							\ 	    case 1:							\ 	      fprintf ((FILE), "\\%03o", ch);				\ 	      break;							\ 	    default:							\ 	      putc ('\\', (FILE));					\ 	      putc (escape, (FILE));					\ 	      break;							\ 	    }								\         }								\       fprintf ((FILE), "\"\n");						\     }									\   while (0)
end_define

begin_comment
comment|/* The routine used to output sequences of byte values.  We use a special    version of this for most svr4 targets because doing so makes the    generated assembly code more compact (and thus faster to assemble)    as well as more readable.  Note that if we find subparts of the    character sequence which end with NUL (and which are shorter than    STRING_LIMIT) we output those using ASM_OUTPUT_LIMITED_STRING.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ASCII
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|FILE
parameter_list|,
name|STR
parameter_list|,
name|LENGTH
parameter_list|)
define|\
value|do									\     {									\       register unsigned char *_ascii_bytes = (unsigned char *) (STR);	\       register unsigned char *limit = _ascii_bytes + (LENGTH);		\       register unsigned bytes_in_chunk = 0;				\       for (; _ascii_bytes< limit; _ascii_bytes++)			\         {								\ 	  register unsigned char *p;					\ 	  if (bytes_in_chunk>= 60)					\ 	    {								\ 	      fprintf ((FILE), "\"\n");					\ 	      bytes_in_chunk = 0;					\ 	    }								\ 	  for (p = _ascii_bytes; p< limit&& *p != '\0'; p++)		\ 	    continue;							\ 	  if (p< limit&& (p - _ascii_bytes)<= STRING_LIMIT)		\ 	    {								\ 	      if (bytes_in_chunk> 0)					\ 		{							\ 		  fprintf ((FILE), "\"\n");				\ 		  bytes_in_chunk = 0;					\ 		}							\ 	      ASM_OUTPUT_LIMITED_STRING ((FILE), _ascii_bytes);		\ 	      _ascii_bytes = p;						\ 	    }								\ 	  else								\ 	    {								\ 	      register int escape;					\ 	      register unsigned ch;					\ 	      if (bytes_in_chunk == 0)					\ 		fprintf ((FILE), "\t%s\t\"", ASCII_DATA_ASM_OP);	\ 	      switch (escape = ESCAPES[ch = *_ascii_bytes])		\ 		{							\ 		case 0:							\ 		  putc (ch, (FILE));					\ 		  bytes_in_chunk++;					\ 		  break;						\ 		case 1:							\ 		  fprintf ((FILE), "\\%03o", ch);			\ 		  bytes_in_chunk += 4;					\ 		  break;						\ 		default:						\ 		  putc ('\\', (FILE));					\ 		  putc (escape, (FILE));				\ 		  bytes_in_chunk += 2;					\ 		  break;						\ 		}							\ 	    }								\ 	}								\       if (bytes_in_chunk> 0)						\         fprintf ((FILE), "\"\n");					\     }									\   while (0)
end_define

begin_comment
comment|/* All SVR4 targets use the ELF object file format.  */
end_comment

begin_define
define|#
directive|define
name|OBJECT_FORMAT_ELF
end_define

end_unit

