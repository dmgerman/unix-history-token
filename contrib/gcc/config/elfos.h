begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* elfos.h  --  operating system specific defines to be used when    targeting GCC for some generic ELF system    Copyright (C) 1991, 1994, 1995, 1999, 2000 Free Software Foundation, Inc.    Based on svr4.h contributed by Ron Guilmette (rfg@netcom.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* For the sake of libgcc2.c, indicate target supports atexit.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_ATEXIT
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
value|"crtend.o%s"
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
value|"%{!shared: \ 			 %{!symbolic: \ 			  %{pg:gcrt0.o%s}%{!pg:%{p:mcrt0.o%s}%{!p:crt0.o%s}}}}\ 			crtbegin.o%s"
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
comment|/* All ELF targets can support DWARF-2.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_DEBUGGING_INFO
end_define

begin_comment
comment|/* Also allow them to support STABS debugging.  */
end_comment

begin_include
include|#
directive|include
file|"dbxelf.h"
end_include

begin_comment
comment|/* The GNU tools operate better with stabs.  Since we don't have    any native tools to be compatible with, default to stabs.  */
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
value|DBX_DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

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
comment|/* This is how to output a reference to a user-level label named NAME.    `assemble_name' uses this.     For System V Release 4 the convention is *not* to prepend a leading    underscore onto user-level symbol names.  */
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
value|fprintf (FILE, "%s", NAME)
end_define

begin_comment
comment|/* This is how to output an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.     For most svr4 systems, the convention is that any symbol which begins    with a period is not put into the linker symbol table by the assembler.  */
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
comment|/* This is how to store into the string LABEL    the symbol_ref name of an internal numbered label where    PREFIX is the class of label and NUM is the number within the class.    This is suitable for output with `assemble_name'.     For most svr4 systems, the convention is that any symbol which begins    with a period is not put into the linker symbol table by the assembler.  */
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
comment|/* Switch into a generic section.    This is currently only used to support section attributes.  */
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
value|do {									\   static struct section_info						\     {									\       struct section_info *next;				        \       char *name;						        \       enum sect_enum {SECT_RW, SECT_RO, SECT_EXEC} type;		\     } *sections;							\   struct section_info *s;						\   char *mode;								\   enum sect_enum type;							\ 									\   for (s = sections; s; s = s->next)					\     if (!strcmp (NAME, s->name))					\       break;								\ 									\   if (DECL&& TREE_CODE (DECL) == FUNCTION_DECL)			\     type = SECT_EXEC, mode = "ax";					\   else if (DECL&& DECL_READONLY_SECTION (DECL, RELOC))			\     type = SECT_RO, mode = "a";						\   else									\     type = SECT_RW, mode = "aw";					\ 									\   if (s == 0)								\     {									\       s = (struct section_info *) xmalloc (sizeof (struct section_info));  \       s->name = xmalloc ((strlen (NAME) + 1) * sizeof (*NAME));		\       strcpy (s->name, NAME);						\       s->type = type;							\       s->next = sections;						\       sections = s;							\       fprintf (FILE, ".section\t%s,\"%s\",@progbits\n", NAME, mode);	\     }									\   else									\     {									\       if (DECL&& s->type != type)					\ 	error_with_decl (DECL, "%s causes a section type conflict");	\ 									\       fprintf (FILE, ".section\t%s\n", NAME);				\     }									\ } while (0)
end_define

begin_define
define|#
directive|define
name|MAKE_DECL_ONE_ONLY
parameter_list|(
name|DECL
parameter_list|)
value|(DECL_WEAK (DECL) = 1)
end_define

begin_define
define|#
directive|define
name|UNIQUE_SECTION_P
parameter_list|(
name|DECL
parameter_list|)
value|(DECL_ONE_ONLY (DECL))
end_define

begin_define
define|#
directive|define
name|UNIQUE_SECTION
parameter_list|(
name|DECL
parameter_list|,
name|RELOC
parameter_list|)
define|\
value|do {								\   int len;							\   char *name, *string, *prefix;					\ 								\   name = IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (DECL));	\ 								\   if (! DECL_ONE_ONLY (DECL))					\     {								\       if (TREE_CODE (DECL) == FUNCTION_DECL)			\ 	prefix = ".text.";					\       else if (DECL_READONLY_SECTION (DECL, RELOC))		\ 	prefix = ".rodata.";					\       else							\ 	prefix = ".data.";					\     }								\   else if (TREE_CODE (DECL) == FUNCTION_DECL)			\     prefix = ".gnu.linkonce.t.";				\   else if (DECL_READONLY_SECTION (DECL, RELOC))			\     prefix = ".gnu.linkonce.r.";				\   else								\     prefix = ".gnu.linkonce.d.";				\ 								\   len = strlen (name) + strlen (prefix);			\   string = alloca (len + 1);					\   sprintf (string, "%s%s", prefix, name);			\ 								\   DECL_SECTION_NAME (DECL) = build_string (len, string);	\ } while (0)
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
value|{									\   if (TREE_CODE (DECL) == STRING_CST)					\     {									\       if (! flag_writable_strings)					\ 	const_section ();						\       else								\ 	data_section ();						\     }									\   else if (TREE_CODE (DECL) == VAR_DECL					\ 	   || TREE_CODE (DECL) == CONSTRUCTOR)				\     {									\       if ((flag_pic&& RELOC)						\ 	  || !TREE_READONLY (DECL) || TREE_SIDE_EFFECTS (DECL)		\ 	  || !DECL_INITIAL (DECL)					\ 	  || (DECL_INITIAL (DECL) != error_mark_node			\&& !TREE_CONSTANT (DECL_INITIAL (DECL))))			\ 	data_section ();						\       else								\ 	const_section ();						\     }									\   else									\     const_section ();							\ }
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

