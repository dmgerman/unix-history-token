begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler,    for Alpha FreeBSD systems.    Copyright (C) 1998 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This is used on Alpha platforms that use the ELF format.    This was taken from the NetBSD configuration, and modified    for FreeBSD/Alpha by Hidetoshi Shimokawa<simokawa@FreeBSD.ORG> */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Make gcc agree with<machine/ansi.h> */
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
value|32
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
value|0
end_define

begin_comment
comment|/* Provide a CPP_SPEC appropriate for FreeBSD.  Current we just deal with    the GCC option `-posix'.  */
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
value|"%{posix:-D_POSIX_SOURCE}"
end_define

begin_comment
comment|/* Provide an ASM_SPEC appropriate for a FreeBSD/Alpha target.  This differs    from the generic FreeBSD ASM_SPEC in that no special handling of PIC is    necessary on the Alpha.  */
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
value|" %| %{mcpu=*:-m%*}"
end_define

begin_undef
undef|#
directive|undef
name|ASM_FINAL_SPEC
end_undef

begin_comment
comment|/* Output assembler code to FILE to increment profiler label # LABELNO    for profiling a function entry.  Under FreeBSD/Alpha, the assembler does    nothing special with -pg. */
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
value|fputs ("\tjsr $28,_mcount\n", (FILE));
end_define

begin_comment
comment|/* at */
end_comment

begin_comment
comment|/* Show that we need a GP when profiling.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_PROFILING_NEEDS_GP
end_define

begin_undef
undef|#
directive|undef
name|HAS_INIT_SECTION
end_undef

begin_undef
undef|#
directive|undef
name|PREFERRED_DEBUGGING_TYPE
end_undef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
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
value|fprintf (stderr, " (FreeBSD/alpha ELF)");
end_define

begin_comment
comment|/* Names to predefine in the preprocessor for this target machine.    XXX FreeBSD, by convention, shouldn't do __alpha, but lots of applications    expect it because that's what OSF/1 does.  */
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
define|\
value|"-D__alpha__ -D__alpha -D__ELF__ -Acpu(alpha) -Amachine(alpha)"	\   CPP_FBSD_PREDEFINES
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
value|"-m elf64alpha					\   %{p:%e`-p' not supported; use `-pg' and gprof(1)}		\   %{Wl,*:%*}							\   %{assert*} %{R*} %{rpath*} %{defsym*}				\   %{shared:-Bshareable %{h*} %{soname*}}			\   %{symbolic:-Bsymbolic}					\   %{!shared:							\     %{!static:							\       %{rdynamic:-export-dynamic}				\       %{!dynamic-linker:-dynamic-linker /usr/libexec/ld-elf.so.1} \     %{static:-Bstatic}}"
end_define

begin_comment
comment|/* Provide a STARTFILE_SPEC for FreeBSD that is compatible with the    non-aout version used on i386. */
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
value|"%{!shared: %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} %{!p:crt1.o%s}}} \     %{!shared:crtbegin.o%s} %{shared:crtbeginS.o%s}"
end_define

begin_comment
comment|/* Provide a ENDFILE_SPEC appropriate for FreeBSD.  Here we tack on    the file which provides part of the support for getting C++    file-scope static object deconstructed after exiting `main' */
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
value|"%{!shared:crtend.o%s} %{shared:crtendS.o%s}"
end_define

begin_comment
comment|/* Handle #pragma weak and #pragma pack.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
end_define

begin_undef
undef|#
directive|undef
name|OBJECT_FORMAT_COFF
end_undef

begin_undef
undef|#
directive|undef
name|EXTENDED_COFF
end_undef

begin_define
define|#
directive|define
name|OBJECT_FORMAT_ELF
end_define

begin_comment
comment|/* This is the char to use for continuation (in case we need to turn    continuation back on).  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_CONTIN_CHAR
end_undef

begin_define
define|#
directive|define
name|DBX_CONTIN_CHAR
value|'?'
end_define

begin_undef
undef|#
directive|undef
name|TARGET_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_DEFAULT
value|(MASK_FP | MASK_FPREGS | MASK_GAS)
end_define

begin_comment
comment|/* Output at beginning of assembler file.  */
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
value|{									\   alpha_write_verstamp (FILE);						\   output_file_directive ((FILE), main_input_filename);			\   fprintf ((FILE), "\t.version\t\"01.01\"\n");				\   fprintf ((FILE), "\t.set noat\n");					\ }
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
name|STREAM
parameter_list|,
name|LINE
parameter_list|)
define|\
value|alpha_output_lineno ((STREAM), (LINE))
end_define

begin_function_decl
specifier|extern
name|void
name|alpha_output_lineno
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|output_file_directive
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Attach a special .ident directive to the end of the file to identify    the version of GCC which compiled this code.  The format of the    .ident string is patterned after the ones produced by native svr4    C compilers.  */
end_comment

begin_undef
undef|#
directive|undef
name|IDENT_ASM_OP
end_undef

begin_define
define|#
directive|define
name|IDENT_ASM_OP
value|".ident"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|IDENTIFY_WITH_IDENT
end_ifdef

begin_undef
undef|#
directive|undef
name|ASM_IDENTIFY_GCC
end_undef

begin_define
define|#
directive|define
name|ASM_IDENTIFY_GCC
parameter_list|(
name|FILE
parameter_list|)
end_define

begin_comment
comment|/* nothing */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_IDENTIFY_LANGUAGE
end_undef

begin_define
define|#
directive|define
name|ASM_IDENTIFY_LANGUAGE
parameter_list|(
name|FILE
parameter_list|)
define|\
value|fprintf((FILE), "\t%s \"GCC (%s) %s\"\n", IDENT_ASM_OP,		\ 	 lang_identify(), version_string)
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|ASM_FILE_END
end_undef

begin_define
define|#
directive|define
name|ASM_FILE_END
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do {									\      fprintf ((FILE), "\t%s\t\"GCC: (GNU) %s\"\n",			\ 	      IDENT_ASM_OP, version_string);				\    } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_IDENT
end_undef

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
value|fprintf ((FILE), "\t%s\t\"%s\"\n", IDENT_ASM_OP, (NAME));
end_define

begin_comment
comment|/* This is how to allocate empty space in some section.  The .zero    pseudo-op is used for this on most svr4 assemblers.  */
end_comment

begin_undef
undef|#
directive|undef
name|SKIP_ASM_OP
end_undef

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
value|fprintf ((FILE), "\t%s\t%u\n", SKIP_ASM_OP, (SIZE))
end_define

begin_comment
comment|/* Output the label which precedes a jumptable.  Note that for all svr4    systems where we actually generate jumptables (which is to say every    svr4 target except i386, where we use casesi instead) we put the jump-    tables into the .rodata section and since other stuff could have been    put into the .rodata section prior to any given jumptable, we have to    make sure that the location counter for the .rodata section gets pro-    perly re-aligned prior to the actual beginning of the jump table.  */
end_comment

begin_undef
undef|#
directive|undef
name|ALIGN_ASM_OP
end_undef

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
value|do {									\     ASM_OUTPUT_BEFORE_CASE_LABEL ((FILE), (PREFIX), (NUM), (JUMPTABLE))	\     ASM_OUTPUT_INTERNAL_LABEL ((FILE), (PREFIX), (NUM));		\   } while (0)
end_define

begin_comment
comment|/* The standard SVR4 assembler seems to require that certain builtin    library routines (e.g. .udiv) be explicitly declared as .globl    in each assembly file where they are referenced.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_EXTERNAL_LIBCALL
end_undef

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
value|ASM_GLOBALIZE_LABEL ((FILE), XSTR ((FUN), 0))
end_define

begin_comment
comment|/* This says how to output assembler code to declare an    uninitialized external linkage data object.  Under SVR4,    the linker seems to want the alignment of data objects    to depend on their types.  We do exactly that here.  */
end_comment

begin_undef
undef|#
directive|undef
name|COMMON_ASM_OP
end_undef

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

begin_undef
undef|#
directive|undef
name|LOCAL_ASM_OP
end_undef

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
value|do {									\   fprintf ((FILE), "\t%s\t", LOCAL_ASM_OP);				\   assemble_name ((FILE), (NAME));					\   fprintf ((FILE), "\n");						\   ASM_OUTPUT_ALIGNED_COMMON ((FILE), (NAME), (SIZE), (ALIGN));		\ } while (0)
end_define

begin_comment
comment|/* This is the pseudo-op used to generate a 64-bit word of data with a    specific value in some section.  */
end_comment

begin_undef
undef|#
directive|undef
name|INT_ASM_OP
end_undef

begin_define
define|#
directive|define
name|INT_ASM_OP
value|".quad"
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

begin_undef
undef|#
directive|undef
name|USE_CONST_SECTION
end_undef

begin_define
define|#
directive|define
name|USE_CONST_SECTION
value|1
end_define

begin_undef
undef|#
directive|undef
name|CONST_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|CONST_SECTION_ASM_OP
value|".section\t.rodata"
end_define

begin_comment
comment|/* Define the pseudo-ops used to switch to the .ctors and .dtors sections.     Note that we want to give these sections the SHF_WRITE attribute    because these sections will actually contain data (i.e. tables of    addresses of functions in the current root executable or shared library    file) and, in the case of a shared library, the relocatable addresses    will have to be properly resolved/relocated (and then written into) by    the dynamic linker when it actually attaches the given shared library    to the executing process.  (Note that on SVR4, you may wish to use the    `-z text' option to the ELF linker, when building a shared library, as    an additional check that you are doing everything right.  But if you do    use the `-z text' option when building a shared library, you will get    errors unless the .ctors and .dtors sections are marked as writable    via the SHF_WRITE attribute.)  */
end_comment

begin_undef
undef|#
directive|undef
name|CTORS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|".section\t.ctors,\"aw\""
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
value|".section\t.dtors,\"aw\""
end_define

begin_comment
comment|/* On svr4, we *do* have support for the .init and .fini sections, and we    can put stuff in there to be executed before and after `main'.  We let    crtstuff.c and other files know this by defining the following symbols.    The definitions say how to change sections to the .init and .fini    sections.  This is the same for all known svr4 assemblers.  */
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
value|".section\t.init"
end_define

begin_undef
undef|#
directive|undef
name|FINI_SECTION_ASM_OP
end_undef

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

begin_undef
undef|#
directive|undef
name|READONLY_DATA_SECTION
end_undef

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

begin_undef
undef|#
directive|undef
name|CONST_SECTION_FUNCTION
end_undef

begin_define
define|#
directive|define
name|CONST_SECTION_FUNCTION
define|\
value|void									\ const_section ()							\ {									\   if (!USE_CONST_SECTION)						\     text_section();							\   else if (in_section != in_const)					\     {									\       fprintf (asm_out_file, "%s\n", CONST_SECTION_ASM_OP);		\       in_section = in_const;						\     }									\ }
end_define

begin_undef
undef|#
directive|undef
name|CTORS_SECTION_FUNCTION
end_undef

begin_define
define|#
directive|define
name|CTORS_SECTION_FUNCTION
define|\
value|void									\ ctors_section ()							\ {									\   if (in_section != in_ctors)						\     {									\       fprintf (asm_out_file, "%s\n", CTORS_SECTION_ASM_OP);		\       in_section = in_ctors;						\     }									\ }
end_define

begin_undef
undef|#
directive|undef
name|DTORS_SECTION_FUNCTION
end_undef

begin_define
define|#
directive|define
name|DTORS_SECTION_FUNCTION
define|\
value|void									\ dtors_section ()							\ {									\   if (in_section != in_dtors)						\     {									\       fprintf (asm_out_file, "%s\n", DTORS_SECTION_ASM_OP);		\       in_section = in_dtors;						\     }									\ }
end_define

begin_comment
comment|/* Switch into a generic section.    This is currently only used to support section attributes.     We make the section read-only and executable for a function decl,    read-only for a const data decl, and writable for a non-const data decl.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_SECTION_NAME
end_undef

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
value|fprintf ((FILE), ".section\t%s,\"%s\",@progbits\n", (NAME),		\ 	   (DECL)&& TREE_CODE (DECL) == FUNCTION_DECL ? "ax" :		\ 	   (DECL)&& DECL_READONLY_SECTION ((DECL), (RELOC)) ? "a" : "aw")
end_define

begin_comment
comment|/* A C statement (sans semicolon) to output an element in the table of    global constructors.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_CONSTRUCTOR
end_undef

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
value|do {									\     ctors_section ();							\     fprintf ((FILE), "\t%s\t ", INT_ASM_OP);				\     assemble_name ((FILE), (NAME));					\     fprintf ((FILE), "\n");						\   } while (0)
end_define

begin_comment
comment|/* A C statement (sans semicolon) to output an element in the table of    global destructors.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DESTRUCTOR
end_undef

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
value|do {									\     dtors_section ();							\     fprintf ((FILE), "\t%s\t ", INT_ASM_OP);				\     assemble_name ((FILE), (NAME));					\     fprintf ((FILE), "\n");						\   } while (0)
end_define

begin_comment
comment|/* A C statement or statements to switch to the appropriate    section for output of DECL.  DECL is either a `VAR_DECL' node    or a constant of some sort.  RELOC indicates whether forming    the initial value of DECL requires link-time relocations.  */
end_comment

begin_undef
undef|#
directive|undef
name|SELECT_SECTION
end_undef

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
value|{									\   if (TREE_CODE (DECL) == STRING_CST)					\     {									\       if (! flag_writable_strings)					\ 	const_section ();						\       else								\ 	data_section ();						\     }									\   else if (TREE_CODE (DECL) == VAR_DECL)				\     {									\       if ((flag_pic&& (RELOC))						\ 	  || !TREE_READONLY (DECL) || TREE_SIDE_EFFECTS (DECL)		\ 	  || !DECL_INITIAL (DECL)					\ 	  || (DECL_INITIAL (DECL) != error_mark_node			\&& !TREE_CONSTANT (DECL_INITIAL (DECL))))			\ 	data_section ();						\       else								\ 	const_section ();						\     }									\   else									\     const_section ();							\ }
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
comment|/* Define the strings used for the .type, .size and .set directives.    These strings generally do not vary from one system running svr4 to    another, but if a given system (e.g. m88k running svr) needs to use    different pseudo-op names for these, they may be overridden in the    file which includes this one.  */
end_comment

begin_undef
undef|#
directive|undef
name|TYPE_ASM_OP
end_undef

begin_define
define|#
directive|define
name|TYPE_ASM_OP
value|".type"
end_define

begin_undef
undef|#
directive|undef
name|SIZE_ASM_OP
end_undef

begin_define
define|#
directive|define
name|SIZE_ASM_OP
value|".size"
end_define

begin_comment
comment|/* This is how we tell the assembler that two symbols have the same value.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DEF
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DEF
parameter_list|(
name|FILE
parameter_list|,
name|NAME1
parameter_list|,
name|NAME2
parameter_list|)
define|\
value|do { assemble_name((FILE), (NAME1));					\        fputs(" = ", (FILE));						\        assemble_name((FILE), (NAME2));					\        fputc('\n', (FILE)); } while (0)
end_define

begin_comment
comment|/* A table of bytes codes used by the ASM_OUTPUT_ASCII and    ASM_OUTPUT_LIMITED_STRING macros.  Each byte in the table    corresponds to a particular byte value [0..255].  For any    given byte value, if the value in the corresponding table    position is zero, the given character can be output directly.    If the table value is 1, the byte must be output as a \ooo    octal escape.  If the tables value is anything else, then the    byte value should be output as a \ followed by the value    in the table.  Note that we can use standard UN*X escape    sequences for many control characters, but we don't use    \a to represent BEL because some svr4 assemblers (e.g. on    the i386) don't know about that.  Also, we don't use \v    since some versions of gas, such as 2.2 did not accept it.  */
end_comment

begin_undef
undef|#
directive|undef
name|ESCAPES
end_undef

begin_define
define|#
directive|define
name|ESCAPES
define|\
value|"\1\1\1\1\1\1\1\1btn\1fr\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\ \0\0\"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\ \0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\\\0\0\0\ \0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\ \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\ \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\ \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\ \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1"
end_define

begin_comment
comment|/* Some svr4 assemblers have a limit on the number of characters which    can appear in the operand of a .string directive.  If your assembler    has such a limitation, you should define STRING_LIMIT to reflect that    limit.  Note that at least some svr4 assemblers have a limit on the    actual number of bytes in the double-quoted string, and that they    count each character in an escape sequence as one byte.  Thus, an    escape sequence like \377 would count as four bytes.     If your target assembler doesn't support the .string directive, you    should define this to zero.  */
end_comment

begin_undef
undef|#
directive|undef
name|STRING_LIMIT
end_undef

begin_define
define|#
directive|define
name|STRING_LIMIT
value|((unsigned) 256)
end_define

begin_undef
undef|#
directive|undef
name|STRING_ASM_OP
end_undef

begin_define
define|#
directive|define
name|STRING_ASM_OP
value|".string"
end_define

begin_comment
comment|/* We always use gas here, so we don't worry about ECOFF assembler problems.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_GAS
end_undef

begin_define
define|#
directive|define
name|TARGET_GAS
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
comment|/* Some imports from svr4.h in support of shared libraries.  Currently, we    need the DECLARE_OBJECT_SIZE stuff.  */
end_comment

begin_comment
comment|/* This is how we tell the assembler that a symbol is weak.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_WEAKEN_LABEL
end_undef

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
value|do { fputs ("\t.globl\t", (FILE)); assemble_name ((FILE), (NAME));	\        fputc ('\n', (FILE));						\        fputs ("\t.weak\t", (FILE)); assemble_name ((FILE), (NAME));	\        fputc ('\n', (FILE)); } while (0)
end_define

begin_comment
comment|/* The following macro defines the format used to output the second    operand of the .type assembler directive.  Different svr4 assemblers    expect various different forms for this operand.  The one given here    is just a default.  You may need to override it in your machine-    specific tm.h file (depending upon the particulars of your assembler).  */
end_comment

begin_undef
undef|#
directive|undef
name|TYPE_OPERAND_FMT
end_undef

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
comment|/* Handle cross-compilation on 32-bits machines (such as i386) for 64-bits    machines (Alpha in this case).  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|HOST_BITS_PER_LONG
end_undef

begin_define
define|#
directive|define
name|HOST_BITS_PER_LONG
value|32
end_define

begin_undef
undef|#
directive|undef
name|HOST_WIDE_INT
end_undef

begin_define
define|#
directive|define
name|HOST_WIDE_INT
value|long long
end_define

begin_undef
undef|#
directive|undef
name|HOST_BITS_PER_WIDE_INT
end_undef

begin_define
define|#
directive|define
name|HOST_BITS_PER_WIDE_INT
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

