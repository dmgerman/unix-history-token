begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of various defaults for tm.h macros.    Copyright (C) 1992, 1996, 1997, 1998, 1999, 2000, 2001    Free Software Foundation, Inc.    Contributed by Ron Guilmette (rfg@monkeys.com)  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GCC_DEFAULTS_H
end_ifndef

begin_define
define|#
directive|define
name|GCC_DEFAULTS_H
end_define

begin_comment
comment|/* Define default standard character escape sequences.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_BELL
end_ifndef

begin_define
define|#
directive|define
name|TARGET_BELL
value|007
end_define

begin_define
define|#
directive|define
name|TARGET_BS
value|010
end_define

begin_define
define|#
directive|define
name|TARGET_TAB
value|011
end_define

begin_define
define|#
directive|define
name|TARGET_NEWLINE
value|012
end_define

begin_define
define|#
directive|define
name|TARGET_VT
value|013
end_define

begin_define
define|#
directive|define
name|TARGET_FF
value|014
end_define

begin_define
define|#
directive|define
name|TARGET_CR
value|015
end_define

begin_define
define|#
directive|define
name|TARGET_ESC
value|033
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Store in OUTPUT a string (made with alloca) containing    an assembler-name for a local static variable or function named NAME.    LABELNO is an integer which is different for each call.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_FORMAT_PRIVATE_NAME
end_ifndef

begin_define
define|#
directive|define
name|ASM_FORMAT_PRIVATE_NAME
parameter_list|(
name|OUTPUT
parameter_list|,
name|NAME
parameter_list|,
name|LABELNO
parameter_list|)
define|\
value|do {									\     int len = strlen (NAME);						\     char *temp = (char *) alloca (len + 3);				\     temp[0] = 'L';							\     strcpy (&temp[1], (NAME));						\     temp[len + 1] = '.';						\     temp[len + 2] = 0;							\     (OUTPUT) = (char *) alloca (strlen (NAME) + 11);			\     ASM_GENERATE_INTERNAL_LABEL (OUTPUT, temp, LABELNO);		\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_STABD_OP
end_ifndef

begin_define
define|#
directive|define
name|ASM_STABD_OP
value|"\t.stabd\t"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is how to output an element of a case-vector that is absolute.    Some targets don't use this, but we have to define it anyway.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_ADDR_VEC_ELT
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_VEC_ELT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do { fputs (integer_asm_op (POINTER_SIZE / UNITS_PER_WORD, TRUE), FILE); \      ASM_OUTPUT_INTERNAL_LABEL (FILE, "L", (VALUE));			\      fputc ('\n', FILE);						\    } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Provide default for ASM_OUTPUT_ALTERNATE_LABEL_NAME.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_ALTERNATE_LABEL_NAME
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALTERNATE_LABEL_NAME
parameter_list|(
name|FILE
parameter_list|,
name|INSN
parameter_list|)
define|\
value|do { ASM_OUTPUT_LABEL(FILE,LABEL_ALTERNATE_NAME (INSN)); } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* choose a reasonable default for ASM_OUTPUT_ASCII.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_ASCII
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|MYFILE
parameter_list|,
name|MYSTRING
parameter_list|,
name|MYLENGTH
parameter_list|)
define|\
value|do {									      \     FILE *_hide_asm_out_file = (MYFILE);				      \     const unsigned char *_hide_p = (const unsigned char *) (MYSTRING);	      \     int _hide_thissize = (MYLENGTH);					      \     {									      \       FILE *asm_out_file = _hide_asm_out_file;				      \       const unsigned char *p = _hide_p;					      \       int thissize = _hide_thissize;					      \       int i;								      \       fprintf (asm_out_file, "\t.ascii \"");				      \ 									      \       for (i = 0; i< thissize; i++)					      \ 	{								      \ 	  int c = p[i];			   				      \ 	  if (c == '\"' || c == '\\')					      \ 	    putc ('\\', asm_out_file);					      \ 	  if (ISPRINT(c))						      \ 	    putc (c, asm_out_file);					      \ 	  else								      \ 	    {								      \ 	      fprintf (asm_out_file, "\\%o", c);			      \
comment|/* After an octal-escape, if a digit follows,		      \ 		 terminate one string constant and start another.	      \ 		 The VAX assembler fails to stop reading the escape	      \ 		 after three digits, so this is the only way we		      \ 		 can get it to parse the data properly.  */
value|\ 	      if (i< thissize - 1&& ISDIGIT(p[i + 1]))		      \ 		fprintf (asm_out_file, "\"\n\t.ascii \"");		      \ 	  }								      \ 	}								      \       fprintf (asm_out_file, "\"\n");					      \     }									      \   }									      \   while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is how we tell the assembler to equate two values.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SET_ASM_OP
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_DEF
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DEF
parameter_list|(
name|FILE
parameter_list|,
name|LABEL1
parameter_list|,
name|LABEL2
parameter_list|)
define|\
value|do {	fprintf ((FILE), "%s", SET_ASM_OP);				\ 	assemble_name (FILE, LABEL1);					\ 	fprintf (FILE, ",");						\ 	assemble_name (FILE, LABEL2);					\ 	fprintf (FILE, "\n");						\   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is how to output a reference to a user-level label named NAME.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_LABELREF
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
value|asm_fprintf ((FILE), "%U%s", (NAME))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Allow target to print debug info labels specially.  This is useful for    VLIW targets, since debug info labels should go into the middle of    instruction bundles instead of breaking them.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_DEBUG_LABEL
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DEBUG_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|ASM_OUTPUT_INTERNAL_LABEL (FILE, PREFIX, NUM)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is how we tell the assembler that a symbol is weak.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_WEAK_ALIAS
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ASM_WEAKEN_LABEL
argument_list|)
operator|&&
name|defined
argument_list|(
name|ASM_OUTPUT_DEF
argument_list|)
end_if

begin_define
define|#
directive|define
name|ASM_OUTPUT_WEAK_ALIAS
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do							\     {							\       ASM_WEAKEN_LABEL (STREAM, NAME);			\       if (VALUE)					\         ASM_OUTPUT_DEF (STREAM, NAME, VALUE);		\     }							\   while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This determines whether or not we support weak symbols.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUPPORTS_WEAK
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|ASM_WEAKEN_LABEL
end_ifdef

begin_define
define|#
directive|define
name|SUPPORTS_WEAK
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SUPPORTS_WEAK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This determines whether or not we support link-once semantics.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUPPORTS_ONE_ONLY
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|MAKE_DECL_ONE_ONLY
end_ifdef

begin_define
define|#
directive|define
name|SUPPORTS_ONE_ONLY
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|SUPPORTS_ONE_ONLY
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If the target supports weak symbols, define TARGET_ATTRIBUTE_WEAK to    provide a weak attribute.  Else define it to nothing.      This would normally belong in ansidecl.h, but SUPPORTS_WEAK is    not available at that time.     Note, this is only for use by target files which we know are to be    compiled by GCC.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ATTRIBUTE_WEAK
end_ifndef

begin_if
if|#
directive|if
name|SUPPORTS_WEAK
end_if

begin_define
define|#
directive|define
name|TARGET_ATTRIBUTE_WEAK
value|__attribute__ ((weak))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_ATTRIBUTE_WEAK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If the target supports init_priority C++ attribute, give    SUPPORTS_INIT_PRIORITY a nonzero value.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SUPPORTS_INIT_PRIORITY
end_ifndef

begin_define
define|#
directive|define
name|SUPPORTS_INIT_PRIORITY
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUPPORTS_INIT_PRIORITY */
end_comment

begin_comment
comment|/* If duplicate library search directories can be removed from a    linker command without changing the linker's semantics, give this    symbol a nonzero.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LINK_ELIMINATE_DUPLICATE_LDIRECTORIES
end_ifndef

begin_define
define|#
directive|define
name|LINK_ELIMINATE_DUPLICATE_LDIRECTORIES
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LINK_ELIMINATE_DUPLICATE_LDIRECTORIES */
end_comment

begin_comment
comment|/* If we have a definition of INCOMING_RETURN_ADDR_RTX, assume that    the rest of the DWARF 2 frame unwind support is also provided.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|DWARF2_UNWIND_INFO
argument_list|)
operator|&&
name|defined
argument_list|(
name|INCOMING_RETURN_ADDR_RTX
argument_list|)
end_if

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If we have named sections, and we're using crtstuff to run ctors,    use them for registering eh frame information.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TARGET_ASM_NAMED_SECTION
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|EH_FRAME_IN_DATA_SECTION
argument_list|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|EH_FRAME_SECTION_NAME
end_ifndef

begin_define
define|#
directive|define
name|EH_FRAME_SECTION_NAME
value|".eh_frame"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If we have named section and we support weak symbols, then use the    .jcr section for recording java classes which need to be registered    at program start-up time.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|TARGET_ASM_NAMED_SECTION
argument_list|)
operator|&&
name|SUPPORTS_WEAK
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|JCR_SECTION_NAME
end_ifndef

begin_define
define|#
directive|define
name|JCR_SECTION_NAME
value|".jcr"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If we have no definition for UNIQUE_SECTION, but do have the     ability to generate arbitrary sections, construct something    reasonable.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNIQUE_SECTION
end_ifndef

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
value|do {								\   int len;							\   const char *name;						\   char *string;							\ 								\   name = IDENTIFIER_POINTER (DECL_ASSEMBLER_NAME (DECL));	\
comment|/* Strip off any encoding in name.  */
value|\   STRIP_NAME_ENCODING (name, name);				\ 								\   len = strlen (name) + 1;					\   string = alloca (len + 1);					\   sprintf (string, ".%s", name);				\ 								\   DECL_SECTION_NAME (DECL) = build_string (len, string);	\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* By default, we generate a label at the beginning and end of the    text section, and compute the size of the text section by    subtracting the two.  However, on some platforms that doesn't     work, and we use the section itself, rather than a label at the    beginning of it, to indicate the start of the section.  On such    platforms, define this to zero.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DWARF2_GENERATE_TEXT_SECTION_LABEL
end_ifndef

begin_define
define|#
directive|define
name|DWARF2_GENERATE_TEXT_SECTION_LABEL
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Supply a default definition for PROMOTE_PROTOTYPES.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PROMOTE_PROTOTYPES
end_ifndef

begin_define
define|#
directive|define
name|PROMOTE_PROTOTYPES
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of hardware registers that go into the DWARF-2 unwind info.    If not defined, equals FIRST_PSEUDO_REGISTER  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DWARF_FRAME_REGISTERS
end_ifndef

begin_define
define|#
directive|define
name|DWARF_FRAME_REGISTERS
value|FIRST_PSEUDO_REGISTER
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* How to renumber registers for dbx and gdb.  If not defined, assume    no renumbering is necessary.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DBX_REGISTER_NUMBER
end_ifndef

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|REGNO
parameter_list|)
value|(REGNO)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Default sizes for base C types.  If the sizes are different for    your target, you should override these values by defining the    appropriate symbols in your tm.h file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CHAR_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|CHAR_TYPE_SIZE
value|BITS_PER_UNIT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SHORT_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|SHORT_TYPE_SIZE
value|(BITS_PER_UNIT * MIN ((UNITS_PER_WORD + 1) / 2, 2))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|INT_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|INT_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LONG_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|LONG_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LONG_LONG_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|LONG_LONG_TYPE_SIZE
value|(BITS_PER_WORD * 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WCHAR_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|INT_TYPE_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|WCHAR_UNSIGNED
end_ifndef

begin_define
define|#
directive|define
name|WCHAR_UNSIGNED
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FLOAT_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|FLOAT_TYPE_SIZE
value|BITS_PER_WORD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DOUBLE_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|DOUBLE_TYPE_SIZE
value|(BITS_PER_WORD * 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LONG_DOUBLE_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|LONG_DOUBLE_TYPE_SIZE
value|(BITS_PER_WORD * 2)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BUILD_VA_LIST_TYPE
end_ifndef

begin_define
define|#
directive|define
name|BUILD_VA_LIST_TYPE
parameter_list|(
name|X
parameter_list|)
value|((X) = ptr_type_node)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|PIC_OFFSET_TABLE_REGNUM
end_ifndef

begin_define
define|#
directive|define
name|PIC_OFFSET_TABLE_REGNUM
value|INVALID_REGNUM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Type used by GCOV counters.  Use 64bit data type if target supports    it.  */
end_comment

begin_if
if|#
directive|if
name|LONG_TYPE_SIZE
operator|>=
literal|64
end_if

begin_define
define|#
directive|define
name|GCOV_TYPE_SIZE
value|LONG_TYPE_SIZE
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|GCOV_TYPE_SIZE
value|LONG_LONG_TYPE_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* By default, the preprocessor should be invoked the same way in C++    as in C.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CPLUSPLUS_CPP_SPEC
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|CPP_SPEC
end_ifdef

begin_define
define|#
directive|define
name|CPLUSPLUS_CPP_SPEC
value|CPP_SPEC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ACCUMULATE_OUTGOING_ARGS
end_ifndef

begin_define
define|#
directive|define
name|ACCUMULATE_OUTGOING_ARGS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Supply a default definition for PUSH_ARGS.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PUSH_ARGS
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|PUSH_ROUNDING
end_ifdef

begin_define
define|#
directive|define
name|PUSH_ARGS
value|!ACCUMULATE_OUTGOING_ARGS
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PUSH_ARGS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If PREFERRED_STACK_BOUNDARY is not defined, set it to STACK_BOUNDARY.    STACK_BOUNDARY is required.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PREFERRED_STACK_BOUNDARY
end_ifndef

begin_define
define|#
directive|define
name|PREFERRED_STACK_BOUNDARY
value|STACK_BOUNDARY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* By default, the C++ compiler will use function addresses in the    vtable entries.  Setting this non-zero tells the compiler to use    function descriptors instead.  The value of this macro says how    many words wide the descriptor is (normally 2).  It is assumed     that the address of a function descriptor may be treated as a    pointer to a function.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_VTABLE_USES_DESCRIPTORS
end_ifndef

begin_define
define|#
directive|define
name|TARGET_VTABLE_USES_DESCRIPTORS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Select a format to encode pointers in exception handling data.  We    prefer those that result in fewer dynamic relocations.  Assume no    special support here and encode direct references.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_PREFERRED_EH_DATA_FORMAT
end_ifndef

begin_define
define|#
directive|define
name|ASM_PREFERRED_EH_DATA_FORMAT
parameter_list|(
name|CODE
parameter_list|,
name|GLOBAL
parameter_list|)
value|DW_EH_PE_absptr
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* By default, the C++ compiler will use the lowest bit of the pointer    to function to indicate a pointer-to-member-function points to a    virtual member function.  However, if FUNCTION_BOUNDARY indicates    function addresses aren't always even, the lowest bit of the delta    field will be used.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_PTRMEMFUNC_VBIT_LOCATION
end_ifndef

begin_define
define|#
directive|define
name|TARGET_PTRMEMFUNC_VBIT_LOCATION
define|\
value|(FUNCTION_BOUNDARY>= 2 * BITS_PER_UNIT \    ? ptrmemfunc_vbit_in_pfn : ptrmemfunc_vbit_in_delta)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* True if it is possible to profile code that does not have a frame    pointer.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_ALLOWS_PROFILING_WITHOUT_FRAME_POINTER
end_ifndef

begin_define
define|#
directive|define
name|TARGET_ALLOWS_PROFILING_WITHOUT_FRAME_POINTER
value|true
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_GDB_EXTENSIONS
end_ifndef

begin_define
define|#
directive|define
name|DEFAULT_GDB_EXTENSIONS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If more than one debugging type is supported, you must define    PREFERRED_DEBUGGING_TYPE to choose a format in a system-dependent way.     This is one long line cause VAXC can't handle a \-newline.  */
end_comment

begin_if
if|#
directive|if
literal|1
operator|<
operator|(
name|defined
argument_list|(
name|DBX_DEBUGGING_INFO
argument_list|)
operator|+
name|defined
argument_list|(
name|SDB_DEBUGGING_INFO
argument_list|)
operator|+
name|defined
argument_list|(
name|DWARF_DEBUGGING_INFO
argument_list|)
operator|+
name|defined
argument_list|(
name|DWARF2_DEBUGGING_INFO
argument_list|)
operator|+
name|defined
argument_list|(
name|XCOFF_DEBUGGING_INFO
argument_list|)
operator|+
name|defined
argument_list|(
name|VMS_DEBUGGING_INFO
argument_list|)
operator|)
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|PREFERRED_DEBUGGING_TYPE
end_ifndef

begin_expr_stmt
name|You
name|Lose
operator|!
name|You
name|must
name|define
name|PREFERRED_DEBUGGING_TYPE
operator|!
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no PREFERRED_DEBUGGING_TYPE */
end_comment

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Only one debugging format supported.  Define PREFERRED_DEBUGGING_TYPE 	 so other code needn't care.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DBX_DEBUGGING_INFO
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|SDB_DEBUGGING_INFO
end_ifdef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|SDB_DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DWARF_DEBUGGING_INFO
end_ifdef

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

begin_ifdef
ifdef|#
directive|ifdef
name|DWARF2_DEBUGGING_INFO
end_ifdef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DWARF2_DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|VMS_DEBUGGING_INFO
end_ifdef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|VMS_AND_DWARF2_DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|XCOFF_DEBUGGING_INFO
end_ifdef

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|XCOFF_DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* More than one debugger format enabled.  */
end_comment

begin_comment
comment|/* If still not defined, must have been because no debugging formats    are supported.  */
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
value|NO_DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is set to 1 if BYTES_BIG_ENDIAN is defined but the target uses a    little-endian method of passing and returning structures in registers.    On the HP-UX IA64 and PA64 platforms structures are aligned differently    then integral values and setting this value to 1 will allow for the    special handling of structure arguments and return values in regs.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FUNCTION_ARG_REG_LITTLE_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|FUNCTION_ARG_REG_LITTLE_ENDIAN
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Determine the register class for registers suitable to be the base    address register in a MEM.  Allow the choice to be dependent upon    the mode of the memory access.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MODE_BASE_REG_CLASS
end_ifndef

begin_define
define|#
directive|define
name|MODE_BASE_REG_CLASS
parameter_list|(
name|MODE
parameter_list|)
value|BASE_REG_CLASS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! GCC_DEFAULTS_H */
end_comment

end_unit

