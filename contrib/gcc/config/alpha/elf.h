begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for DEC Alpha w/ELF.    Copyright (C) 1996, 1997, 1998, 1999, 2000, 2001, 2002    Free Software Foundation, Inc.    Contributed by Richard Henderson (rth@tamu.edu).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.    */
end_comment

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
comment|/* ??? Move all SDB stuff from alpha.h to osf.h.  */
end_comment

begin_undef
undef|#
directive|undef
name|SDB_DEBUGGING_INFO
end_undef

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_define
define|#
directive|define
name|DWARF2_DEBUGGING_INFO
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
name|ASM_FINAL_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1_SPEC
value|"%{G*}"
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
value|"%{G*} %{relax:-relax} %{!gstabs*:-no-mdebug}%{gstabs*:-mdebug}"
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
value|"-m elf64alpha %{G*} %{relax:-relax}		\   %{O*:-O3} %{!O*:-O1}						\   %{shared:-shared}						\   %{!shared:							\     %{!static:							\       %{rdynamic:-export-dynamic}				\       %{!dynamic-linker:-dynamic-linker %(elf_dynamic_linker)}}	\     %{static:-static}}"
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
value|do {								\   if (write_symbols == DBX_DEBUG)				\     {								\       alpha_write_verstamp (FILE);				\       output_file_directive (FILE, main_input_filename);	\     }								\   fprintf (FILE, "\t.set noat\n");				\   fprintf (FILE, "\t.set noreorder\n");				\   if (TARGET_EXPLICIT_RELOCS)					\     fprintf (FILE, "\t.set nomacro\n");				\   if (TARGET_BWX | TARGET_MAX | TARGET_FIX | TARGET_CIX)	\     {								\       fprintf (FILE, "\t.arch %s\n",				\                (TARGET_CPU_EV6 ? "ev6"				\                 : TARGET_MAX ? "pca56" : "ev56"));		\     }								\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|IDENT_ASM_OP
end_undef

begin_define
define|#
directive|define
name|IDENT_ASM_OP
value|"\t.ident\t"
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
value|fprintf (FILE, "%s\"%s\"\n", IDENT_ASM_OP, NAME);
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
value|"\t.zero\t"
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
value|fprintf (FILE, "%s%u\n", SKIP_ASM_OP, (SIZE))
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
value|"\t.align\t"
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
value|ASM_GLOBALIZE_LABEL (FILE, XSTR (FUN, 0))
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
value|"\t.comm\t"
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
value|do {									\   fprintf ((FILE), "%s", COMMON_ASM_OP);				\   assemble_name ((FILE), (NAME));					\   fprintf ((FILE), ",%u,%u\n", (SIZE), (ALIGN) / BITS_PER_UNIT);	\ } while (0)
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
value|do {									\   if ((SIZE)<= g_switch_value)						\     sbss_section();							\   else									\     bss_section();							\   fprintf (FILE, "%s", TYPE_ASM_OP);					\   assemble_name (FILE, NAME);						\   putc (',', FILE);							\   fprintf (FILE, TYPE_OPERAND_FMT, "object");				\   putc ('\n', FILE);							\   if (!flag_inhibit_size_directive)					\     {									\       fprintf (FILE, "%s", SIZE_ASM_OP);				\       assemble_name (FILE, NAME);					\       fprintf (FILE, ",%d\n", (SIZE));					\     }									\   ASM_OUTPUT_ALIGN ((FILE), exact_log2((ALIGN) / BITS_PER_UNIT));	\   ASM_OUTPUT_LABEL(FILE, NAME);						\   ASM_OUTPUT_SKIP((FILE), (SIZE) ? (SIZE) : 1);				\ } while (0)
end_define

begin_comment
comment|/* This says how to output assembler code to declare an    uninitialized external linkage data object.  */
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
value|do {									\   ASM_GLOBALIZE_LABEL (FILE, NAME);					\   ASM_OUTPUT_ALIGNED_LOCAL (FILE, NAME, SIZE, ALIGN);			\ } while (0)
end_define

begin_comment
comment|/* Biggest alignment supported by the object file format of this    machine.  Use this macro to limit the alignment which can be    specified using the `__attribute__ ((aligned (N)))' construct.  If    not defined, the default value is `BIGGEST_ALIGNMENT'.      This value is really 2^63.  Since gcc figures the alignment in bits,    we could only potentially get to 2^60 on suitible hosts.  Due to other    considerations in varasm, we must restrict this to what fits in an int.  */
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
define|\
value|(1<< (HOST_BITS_PER_INT< 64 ? HOST_BITS_PER_INT - 2 : 62))
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
value|"\t.ascii\t"
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
value|"\t.section\t.rodata"
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
value|"\t.section\t.bss"
end_define

begin_undef
undef|#
directive|undef
name|SBSS_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|SBSS_SECTION_ASM_OP
value|"\t.section\t.sbss,\"aw\""
end_define

begin_undef
undef|#
directive|undef
name|SDATA_SECTION_ASM_OP
end_undef

begin_define
define|#
directive|define
name|SDATA_SECTION_ASM_OP
value|"\t.section\t.sdata,\"aw\""
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
value|"\t.section\t.init"
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
value|"\t.section\t.fini"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_GAS_SUBSECTION_ORDERING
end_ifdef

begin_define
define|#
directive|define
name|ASM_SECTION_START_OP
value|"\t.subsection\t-1"
end_define

begin_comment
comment|/* Output assembly directive to move to the beginning of current section.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SECTION_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|fprintf ((FILE), "%s\n", ASM_SECTION_START_OP)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|in_const, in_sbss, in_sdata
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
value|CONST_SECTION_FUNCTION						\   SECTION_FUNCTION_TEMPLATE(sbss_section, in_sbss, SBSS_SECTION_ASM_OP)	\   SECTION_FUNCTION_TEMPLATE(sdata_section, in_sdata, SDATA_SECTION_ASM_OP)
end_define

begin_decl_stmt
specifier|extern
name|void
name|sbss_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|void
name|sdata_section
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

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
value|void								\ const_section ()						\ {								\   if (!USE_CONST_SECTION)					\     text_section();						\   else if (in_section != in_const)				\     {								\       fprintf (asm_out_file, "%s\n", CONST_SECTION_ASM_OP);	\       in_section = in_const;					\     }								\ }
end_define

begin_undef
undef|#
directive|undef
name|SECTION_FUNCTION_TEMPLATE
end_undef

begin_define
define|#
directive|define
name|SECTION_FUNCTION_TEMPLATE
parameter_list|(
name|FN
parameter_list|,
name|ENUM
parameter_list|,
name|OP
parameter_list|)
define|\
value|void FN ()					\ {						\   if (in_section != ENUM)			\     {						\       fprintf (asm_out_file, "%s\n", OP);	\       in_section = ENUM;			\     }						\ }
end_define

begin_comment
comment|/* Switch into a generic section.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ASM_NAMED_SECTION
value|default_elf_asm_named_section
end_define

begin_comment
comment|/* A C statement or statements to switch to the appropriate    section for output of DECL.  DECL is either a `VAR_DECL' node    or a constant of some sort.  RELOC indicates whether forming    the initial value of DECL requires link-time relocations.     Set SECNUM to: 	0	.text 	1	.rodata 	2	.data 	3	.sdata 	4	.bss 	5	.sbss */
end_comment

begin_define
define|#
directive|define
name|DO_SELECT_SECTION
parameter_list|(
name|SECNUM
parameter_list|,
name|DECL
parameter_list|,
name|RELOC
parameter_list|)
define|\
value|do								\      {								\        HOST_WIDE_INT size;					\        SECNUM = 1;						\        if (TREE_CODE (DECL) == FUNCTION_DECL)			\ 	 {							\ 	   SECNUM = 0;						\ 	   break;						\ 	 }							\        else if (TREE_CODE (DECL) == STRING_CST)			\ 	 {							\ 	   if (flag_writable_strings)				\ 	     SECNUM = 2;					\ 	   else							\ 	     SECNUM = 0x101;					\ 	   break;						\ 	 }							\        else if (TREE_CODE (DECL) == VAR_DECL)			\ 	 {							\ 	   if (DECL_INITIAL (DECL) == NULL			\ 	       || DECL_INITIAL (DECL) == error_mark_node)	\ 	     SECNUM = 4;					\ 	   else if ((flag_pic&& RELOC)				\ 		    || ! TREE_READONLY (DECL)			\ 		    || TREE_SIDE_EFFECTS (DECL)			\ 		    || ! TREE_CONSTANT (DECL_INITIAL (DECL)))	\ 	     SECNUM = 2;					\ 	  else if (flag_merge_constants>= 2)			\ 	    {							\
comment|/* C and C++ don't allow different variables to	\ 		 share the same location.  -fmerge-all-constants\ 		 allows even that (at the expense of not	\ 		 conforming).  */
value|\ 	      if (TREE_CODE (DECL_INITIAL (DECL)) == STRING_CST)\ 		SECNUM = 0x201;					\ 	      else						\ 		SECNUM = 0x301;					\ 	    }							\ 	 }							\        else if (TREE_CODE (DECL) == CONSTRUCTOR)		\ 	 {							\ 	   if ((flag_pic&& RELOC)				\ 	       || TREE_SIDE_EFFECTS (DECL)			\ 	       || ! TREE_CONSTANT (DECL))			\ 	     SECNUM = 2;					\ 	 }							\ 								\
comment|/* Select small data sections based on size.  */
value|\        size = int_size_in_bytes (TREE_TYPE (DECL));		\        if (size>= 0&& size<= g_switch_value)			\ 	 {							\ 	   if ((SECNUM& 0xff)>= 2)				\ 	     SECNUM += 1;					\
comment|/* Move readonly data to .sdata only if -msmall-data.  */
value|\
comment|/* ??? Consider .sdata.{lit4,lit8} as		\ 	      SHF_MERGE|SHF_ALPHA_GPREL.  */
value|\ 	   else if (TARGET_SMALL_DATA)				\ 	     SECNUM = 3;					\ 	 }							\      }								\    while (0)
end_define

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
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|do							\     {							\       typedef void (*sec_fn) PARAMS ((void));		\       static sec_fn const sec_functions[6] =		\       {							\ 	text_section,					\ 	const_section,					\ 	data_section,					\ 	sdata_section,					\ 	bss_section,					\ 	sbss_section					\       };						\ 							\       int sec;						\ 							\       DO_SELECT_SECTION (sec, DECL, RELOC);		\ 							\       switch (sec)					\ 	{						\ 	case 0x101:					\ 	  mergeable_string_section (DECL, ALIGN, 0);	\ 	  break;					\ 	case 0x201:					\ 	  mergeable_string_section (DECL_INITIAL (DECL),\ 				    ALIGN, 0);		\ 	  break;					\ 	case 0x301:					\ 	  mergeable_constant_section (DECL_MODE (DECL),	\ 				      ALIGN, 0);	\ 	  break;					\ 	default:					\ 	  (*sec_functions[sec]) ();			\ 	  break;					\ 	}						\     }							\   while (0)
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

begin_undef
undef|#
directive|undef
name|UNIQUE_SECTION
end_undef

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
value|do									\     {									\       static const char * const prefixes[6][2] =			\       {									\ 	{ ".text.",   ".gnu.linkonce.t." },				\ 	{ ".rodata.", ".gnu.linkonce.r." },				\ 	{ ".data.",   ".gnu.linkonce.d." },				\ 	{ ".sdata.",  ".gnu.linkonce.s." },				\ 	{ ".bss.",    ".gnu.linkonce.b." },				\ 	{ ".sbss.",   ".gnu.linkonce.sb." }				\       };								\ 									\       int nlen, plen, sec;						\       const char *name, *prefix;					\       char *string;							\ 									\       DO_SELECT_SECTION (sec, DECL, RELOC);				\ 									\       name = IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (DECL));		\       STRIP_NAME_ENCODING (name, name);					\       nlen = strlen (name);						\ 									\       prefix = prefixes[sec& 0xff][DECL_ONE_ONLY(DECL)];		\       plen = strlen (prefix);						\ 									\       string = alloca (nlen + plen + 1);				\ 									\       memcpy (string, prefix, plen);					\       memcpy (string + plen, name, nlen + 1);				\ 									\       DECL_SECTION_NAME (DECL) = build_string (nlen + plen, string);	\     }									\   while (0)
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
parameter_list|,
name|ALIGN
parameter_list|)
define|\
value|do {									\   if (TARGET_SMALL_DATA&& GET_MODE_SIZE (MODE)<= g_switch_value)	\
comment|/* ??? Consider .sdata.{lit4,lit8} as SHF_MERGE|SHF_ALPHA_GPREL.  */
value|\     sdata_section ();							\   else									\     mergeable_constant_section((MODE), (ALIGN), 0);			\ } while (0)
end_define

begin_comment
comment|/* Define the strings used for the special svr4 .type and .size directives.    These strings generally do not vary from one system running svr4 to    another, but if a given system (e.g. m88k running svr) needs to use    different pseudo-op names for these, they may be overridden in the    file which includes this one.  */
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
value|"\t.type\t"
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
value|"\t.size\t"
end_define

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
value|do { fputs ("\t.weak\t", FILE); assemble_name (FILE, NAME); \        fputc ('\n', FILE); } while (0)
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
name|ALIAS
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {								\     assemble_name(FILE, ALIAS);					\     fputs(" = ", FILE);						\     assemble_name(FILE, NAME);					\     fputc('\n', FILE);						\   } while (0)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DEF_FROM_DECLS
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DEF_FROM_DECLS
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|TARGET
parameter_list|)
define|\
value|do {								\     const char *alias = XSTR (XEXP (DECL_RTL (DECL), 0), 0);	\     const char *name = IDENTIFIER_POINTER (TARGET);		\     if (TREE_CODE (DECL) == FUNCTION_DECL)			\       {								\ 	fputc ('$', FILE);					\ 	assemble_name (FILE, alias);				\ 	fputs ("..ng = $", FILE);				\ 	assemble_name (FILE, name);				\ 	fputs ("..ng\n", FILE);					\       }								\     assemble_name(FILE, alias);					\     fputs(" = ", FILE);						\     assemble_name(FILE, name);					\     fputc('\n', FILE);						\   } while (0)
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
comment|/* These macros generate the special .type and .size directives which    are used to set the corresponding fields of the linker symbol table    entries in an ELF object file under SVR4.  These macros also output    the starting labels for the relevant functions/objects.  */
end_comment

begin_comment
comment|/* Write the extra assembler code needed to declare an object properly.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_OBJECT_NAME
end_undef

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
value|do {								\     HOST_WIDE_INT size;						\     fprintf (FILE, "%s", TYPE_ASM_OP);				\     assemble_name (FILE, NAME);					\     putc (',', FILE);						\     fprintf (FILE, TYPE_OPERAND_FMT, "object");			\     putc ('\n', FILE);						\     size_directive_output = 0;					\     if (!flag_inhibit_size_directive				\&& DECL_SIZE (DECL)					\&& (size = int_size_in_bytes (TREE_TYPE (DECL)))> 0)	\       {								\ 	size_directive_output = 1;				\ 	fprintf (FILE, "%s", SIZE_ASM_OP);			\ 	assemble_name (FILE, NAME);				\ 	fputc (',', FILE);					\ 	fprintf (FILE, HOST_WIDE_INT_PRINT_DEC, size);		\ 	fputc ('\n', FILE);					\       }								\     ASM_OUTPUT_LABEL(FILE, NAME);				\   } while (0)
end_define

begin_comment
comment|/* Output the size directive for a decl in rest_of_decl_compilation    in the case where we did not do so before the initializer.    Once we find the error_mark_node, we know that the value of    size_directive_output was set    by ASM_DECLARE_OBJECT_NAME when it was run for the same decl.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FINISH_DECLARE_OBJECT
end_undef

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
value|do {									\     const char *name = XSTR (XEXP (DECL_RTL (DECL), 0), 0);		\     HOST_WIDE_INT size;							\     if (!flag_inhibit_size_directive					\&& DECL_SIZE (DECL)						\&& ! AT_END&& TOP_LEVEL					\&& DECL_INITIAL (DECL) == error_mark_node			\&& !size_directive_output					\&& (size = int_size_in_bytes (TREE_TYPE (DECL)))> 0)		\       {									\ 	size_directive_output = 1;					\ 	fprintf (FILE, "%s", SIZE_ASM_OP);				\ 	assemble_name (FILE, name);					\ 	fputc (',', FILE);						\ 	fprintf (FILE, HOST_WIDE_INT_PRINT_DEC, size);			\ 	fputc ('\n', FILE);						\       }									\   } while (0)
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
value|"\t.string\t"
end_define

begin_comment
comment|/* GAS is the only Alpha/ELF assembler.  */
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
value|(1)
end_define

begin_comment
comment|/* Provide a STARTFILE_SPEC appropriate for ELF.  Here we add the    (even more) magical crtbegin.o file which provides part of the    support for getting C++ file-scope static object constructed    before entering `main'.   */
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
value|"%{!shared: \      %{pg:gcrt1.o%s} %{!pg:%{p:gcrt1.o%s} %{!p:crt1.o%s}}}\    crti.o%s %{static:crtbeginT.o%s}\    %{!static:%{shared:crtbeginS.o%s}%{!shared:crtbegin.o%s}}"
end_define

begin_comment
comment|/* Provide a ENDFILE_SPEC appropriate for ELF.  Here we tack on the    magical crtend.o file which provides part of the support for    getting C++ file-scope static object constructed before entering    `main', followed by a normal ELF "finalizer" file, `crtn.o'.  */
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
value|"%{ffast-math|funsafe-math-optimizations:crtfastmath.o%s} \    %{shared:crtendS.o%s}%{!shared:crtend.o%s} crtn.o%s"
end_define

begin_comment
comment|/* We support #pragma.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
end_define

begin_comment
comment|/* Select a format to encode pointers in exception handling data.  CODE    is 0 for data, 1 for code labels, 2 for function pointers.  GLOBAL is    true if the symbol may be affected by dynamic relocations.     Since application size is already constrained to<2GB by the form of    the ldgp relocation, we can use a 32-bit pc-relative relocation to    static data.  Dynamic data is accessed indirectly to allow for read    only EH sections.  */
end_comment

begin_define
define|#
directive|define
name|ASM_PREFERRED_EH_DATA_FORMAT
parameter_list|(
name|CODE
parameter_list|,
name|GLOBAL
parameter_list|)
define|\
value|(((GLOBAL) ? DW_EH_PE_indirect : 0) | DW_EH_PE_pcrel | DW_EH_PE_sdata4)
end_define

begin_comment
comment|/* If defined, a C statement to be executed just prior to the output of    assembler code for INSN.  */
end_comment

begin_define
define|#
directive|define
name|FINAL_PRESCAN_INSN
parameter_list|(
name|INSN
parameter_list|,
name|OPVEC
parameter_list|,
name|NOPERANDS
parameter_list|)
define|\
value|(alpha_this_literal_sequence_number = 0,		\   alpha_this_gpdisp_sequence_number = 0)
end_define

begin_decl_stmt
specifier|extern
name|int
name|alpha_this_literal_sequence_number
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|alpha_this_gpdisp_sequence_number
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Since the bits of the _init and _fini function is spread across    many object files, each potentially with its own GP, we must assume    we need to load our GP.  Further, the .init/.fini section can    easily be more than 4MB away from the function to call so we can't    use bsr.  */
end_comment

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
value|asm (SECTION_OP "\n"					\ "	br $29,1f\n"					\ "1:	ldgp $29,0($29)\n"				\ "	unop\n"						\ "	jsr $26," USER_LABEL_PREFIX #FUNC "\n"		\ "	.align 3\n"					\ "	.previous");
end_define

begin_comment
comment|/* If we have the capability create headers for efficient EH lookup.    As of Jan 2002, only glibc 2.2.4 can actually make use of this, but    I imagine that other systems will catch up.  In the meantime, it    doesn't harm to make sure that the data exists to be used later.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_LD_EH_FRAME_HDR
argument_list|)
end_if

begin_define
define|#
directive|define
name|LINK_EH_SPEC
value|"%{!static:--eh-frame-hdr} "
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

