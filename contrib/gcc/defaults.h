begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of various defaults for tm.h macros.    Copyright (C) 1992, 1996, 1997, 1998, 1999, 2000, 2001, 2002, 2003, 2004,    2005    Free Software Foundation, Inc.    Contributed by Ron Guilmette (rfg@monkeys.com)  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|GET_ENVIRONMENT
end_ifndef

begin_define
define|#
directive|define
name|GET_ENVIRONMENT
parameter_list|(
name|VALUE
parameter_list|,
name|NAME
parameter_list|)
value|do { (VALUE) = getenv (NAME); } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|obstack_chunk_alloc
value|((void *(*) (long)) xmalloc)
end_define

begin_define
define|#
directive|define
name|obstack_chunk_free
value|((void (*) (void *)) free)
end_define

begin_define
define|#
directive|define
name|OBSTACK_CHUNK_SIZE
value|0
end_define

begin_define
define|#
directive|define
name|gcc_obstack_init
parameter_list|(
name|OBSTACK
parameter_list|)
define|\
value|_obstack_begin ((OBSTACK), OBSTACK_CHUNK_SIZE, 0,	\ 		  obstack_chunk_alloc,			\ 		  obstack_chunk_free)
end_define

begin_comment
comment|/* Store in OUTPUT a string (made with alloca) containing an    assembler-name for a local static variable or function named NAME.    LABELNO is an integer which is different for each call.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_PN_FORMAT
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|NO_DOT_IN_LABEL
end_ifndef

begin_define
define|#
directive|define
name|ASM_PN_FORMAT
value|"%s.%lu"
end_define

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|NO_DOLLAR_IN_LABEL
end_ifndef

begin_define
define|#
directive|define
name|ASM_PN_FORMAT
value|"%s$%lu"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASM_PN_FORMAT
value|"__%s_%lu"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ! ASM_PN_FORMAT */
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
value|do { const char *const name_ = (NAME); \        char *const output_ = (OUTPUT) = \ 	 (char *) alloca (strlen (name_) + 32); \        sprintf (output_, ASM_PN_FORMAT, name_, (unsigned long)(LABELNO)); \   } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Choose a reasonable default for ASM_OUTPUT_ASCII.  */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_AS_TLS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|ASM_OUTPUT_TLS_COMMON
argument_list|)
end_if

begin_define
define|#
directive|define
name|ASM_OUTPUT_TLS_COMMON
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|do									\     {									\       fprintf ((FILE), "\t.tls_common\t");				\       assemble_name ((FILE), (NAME));					\       fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%u\n",		\ 	       (SIZE), DECL_ALIGN (DECL) / BITS_PER_UNIT);		\     }									\   while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Decide whether to defer emitting the assembler output for an equate    of two values.  The default is to not defer output.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DEFERRED_OUTPUT_DEFS
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DEFERRED_OUTPUT_DEFS
parameter_list|(
name|DECL
parameter_list|,
name|TARGET
parameter_list|)
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is how to output the definition of a user-level label named    NAME, such as the label on a static function or variable NAME.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_LABEL
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do { assemble_name ((FILE), (NAME)); fputs (":\n", (FILE)); } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Output the definition of a compiler-generated label named NAME.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_INTERNAL_LABEL
end_ifndef

begin_define
define|#
directive|define
name|ASM_OUTPUT_INTERNAL_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {						\     assemble_name_raw ((FILE), (NAME));		\     fputs (":\n", (FILE));			\   } while (0)
end_define

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
value|(*targetm.asm_out.internal_label) (FILE, PREFIX, NUM)
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
comment|/* This is how we tell the assembler that a symbol is a weak alias to    another symbol that doesn't require the other symbol to be defined.    Uses of the former will turn into weak uses of the latter, i.e.,    uses that, in case the latter is undefined, will not cause errors,    and will add it to the symbol table as weak undefined.  However, if    the latter is referenced directly, a strong reference prevails.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_WEAKREF
end_ifndef

begin_if
if|#
directive|if
name|defined
name|HAVE_GAS_WEAKREF
end_if

begin_define
define|#
directive|define
name|ASM_OUTPUT_WEAKREF
parameter_list|(
name|FILE
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|do									\     {									\       fprintf ((FILE), "\t.weakref\t");					\       assemble_name ((FILE), (NAME));					\       fprintf ((FILE), ",");						\       assemble_name ((FILE), (VALUE));					\       fprintf ((FILE), "\n");						\     }									\   while (0)
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
comment|/* How to emit a .type directive.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_TYPE_DIRECTIVE
end_ifndef

begin_if
if|#
directive|if
name|defined
name|TYPE_ASM_OP
operator|&&
name|defined
name|TYPE_OPERAND_FMT
end_if

begin_define
define|#
directive|define
name|ASM_OUTPUT_TYPE_DIRECTIVE
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|TYPE
parameter_list|)
define|\
value|do							\     {							\       fputs (TYPE_ASM_OP, STREAM);			\       assemble_name (STREAM, NAME);			\       fputs (", ", STREAM);				\       fprintf (STREAM, TYPE_OPERAND_FMT, TYPE);		\       putc ('\n', STREAM);				\     }							\   while (0)
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
comment|/* How to emit a .size directive.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_OUTPUT_SIZE_DIRECTIVE
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SIZE_ASM_OP
end_ifdef

begin_define
define|#
directive|define
name|ASM_OUTPUT_SIZE_DIRECTIVE
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|)
define|\
value|do							\     {							\       HOST_WIDE_INT size_ = (SIZE);			\       fputs (SIZE_ASM_OP, STREAM);			\       assemble_name (STREAM, NAME);			\       fprintf (STREAM, ", " HOST_WIDE_INT_PRINT_DEC "\n", size_); \     }							\   while (0)
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_MEASURED_SIZE
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do							\     {							\       fputs (SIZE_ASM_OP, STREAM);			\       assemble_name (STREAM, NAME);			\       fputs (", .-", STREAM);				\       assemble_name (STREAM, NAME);			\       putc ('\n', STREAM);				\     }							\   while (0)
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ASM_WEAKEN_LABEL
argument_list|)
operator|||
name|defined
argument_list|(
name|ASM_WEAKEN_DECL
argument_list|)
end_if

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
comment|/* This determines whether weak symbols must be left out of a static    archive's table of contents.  Defining this macro to be nonzero has    the consequence that certain symbols will not be made weak that    otherwise would be.  The C++ ABI requires this macro to be zero;    see the documentation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_WEAK_NOT_IN_ARCHIVE_TOC
end_ifndef

begin_define
define|#
directive|define
name|TARGET_WEAK_NOT_IN_ARCHIVE_TOC
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This determines whether or not we need linkonce unwind information.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_USES_WEAK_UNWIND_INFO
end_ifndef

begin_define
define|#
directive|define
name|TARGET_USES_WEAK_UNWIND_INFO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* By default, there is no prefix on user-defined symbols.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USER_LABEL_PREFIX
end_ifndef

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|""
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If the target supports weak symbols, define TARGET_ATTRIBUTE_WEAK to    provide a weak attribute.  Else define it to nothing.     This would normally belong in ansidecl.h, but SUPPORTS_WEAK is    not available at that time.     Note, this is only for use by target files which we know are to be    compiled by GCC.  */
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
comment|/* Determines whether we may use common symbols to represent one-only    semantics (a.k.a. "vague linkage").  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|USE_COMMON_FOR_ONE_ONLY
end_ifndef

begin_define
define|#
directive|define
name|USE_COMMON_FOR_ONE_ONLY
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* By default we can assume that all global symbols are in one namespace,    across all shared libraries.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MULTIPLE_SYMBOL_SPACES
end_ifndef

begin_define
define|#
directive|define
name|MULTIPLE_SYMBOL_SPACES
value|0
end_define

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
name|DWARF2_UNWIND_INFO
expr|\
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
comment|/* On many systems, different EH table encodings are used under    difference circumstances.  Some will require runtime relocations;    some will not.  For those that do not require runtime relocations,    we would like to make the table read-only.  However, since the    read-only tables may need to be combined with read-write tables    that do require runtime relocation, it is not safe to make the    tables read-only unless the linker will merge read-only and    read-write sections into a single read-write section.  If your    linker does not have this ability, but your system is such that no    encoding used with non-PIC code will ever require a runtime    relocation, then you can define EH_TABLES_CAN_BE_READ_ONLY to 1 in    your target configuration file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EH_TABLES_CAN_BE_READ_ONLY
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_LD_RO_RW_SECTION_MIXING
end_ifdef

begin_define
define|#
directive|define
name|EH_TABLES_CAN_BE_READ_ONLY
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EH_TABLES_CAN_BE_READ_ONLY
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
comment|/* This decision to use a .jcr section can be overridden by defining    USE_JCR_SECTION to 0 in target file.  This is necessary if target    can define JCR_SECTION_NAME but does not have crtstuff or    linker support for .jcr section.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_USE_JCR_SECTION
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|JCR_SECTION_NAME
end_ifdef

begin_define
define|#
directive|define
name|TARGET_USE_JCR_SECTION
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_USE_JCR_SECTION
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
name|BITS_PER_UNIT
end_ifndef

begin_define
define|#
directive|define
name|BITS_PER_UNIT
value|8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BITS_PER_WORD
end_ifndef

begin_define
define|#
directive|define
name|BITS_PER_WORD
value|(BITS_PER_UNIT * UNITS_PER_WORD)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|BOOL_TYPE_SIZE
end_ifndef

begin_comment
comment|/* `bool' has size and alignment `1', on almost all platforms.  */
end_comment

begin_define
define|#
directive|define
name|BOOL_TYPE_SIZE
value|CHAR_TYPE_SIZE
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
name|DECIMAL32_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|DECIMAL32_TYPE_SIZE
value|32
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DECIMAL64_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|DECIMAL64_TYPE_SIZE
value|64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DECIMAL128_TYPE_SIZE
end_ifndef

begin_define
define|#
directive|define
name|DECIMAL128_TYPE_SIZE
value|128
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Width in bits of a pointer.  Mind the value of the macro `Pmode'.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|POINTER_SIZE
end_ifndef

begin_define
define|#
directive|define
name|POINTER_SIZE
value|BITS_PER_WORD
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

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DLLIMPORT_DECL_ATTRIBUTES
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DLLIMPORT_DECL_ATTRIBUTES
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DECLSPEC
end_ifndef

begin_if
if|#
directive|if
name|TARGET_DLLIMPORT_DECL_ATTRIBUTES
end_if

begin_comment
comment|/* If the target supports the "dllimport" attribute, users are    probably used to the "__declspec" syntax.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_DECLSPEC
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_DECLSPEC
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
comment|/* Decide whether a function's arguments should be processed    from first to last or from last to first.     They should if the stack and args grow in opposite directions, but    only if we have push insns.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PUSH_ROUNDING
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|PUSH_ARGS_REVERSED
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|STACK_GROWS_DOWNWARD
argument_list|)
operator|!=
name|defined
argument_list|(
name|ARGS_GROW_DOWNWARD
argument_list|)
end_if

begin_define
define|#
directive|define
name|PUSH_ARGS_REVERSED
value|PUSH_ARGS
end_define

begin_endif
endif|#
directive|endif
end_endif

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
name|PUSH_ARGS_REVERSED
end_ifndef

begin_define
define|#
directive|define
name|PUSH_ARGS_REVERSED
value|0
end_define

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

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DEFAULT_PACK_STRUCT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DEFAULT_PACK_STRUCT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* By default, the C++ compiler will use function addresses in the    vtable entries.  Setting this nonzero tells the compiler to use    function descriptors instead.  The value of this macro says how    many words wide the descriptor is (normally 2).  It is assumed    that the address of a function descriptor may be treated as a    pointer to a function.  */
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
comment|/* By default, the vtable entries are void pointers, the so the alignment    is the same as pointer alignment.  The value of this macro specifies    the alignment of the vtable entry in bits.  It should be defined only    when special alignment is necessary.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_VTABLE_ENTRY_ALIGN
end_ifndef

begin_define
define|#
directive|define
name|TARGET_VTABLE_ENTRY_ALIGN
value|POINTER_SIZE
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* There are a few non-descriptor entries in the vtable at offsets below    zero.  If these entries must be padded (say, to preserve the alignment    specified by TARGET_VTABLE_ENTRY_ALIGN), set this to the number of    words in each data entry.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_VTABLE_DATA_ENTRY_DISTANCE
end_ifndef

begin_define
define|#
directive|define
name|TARGET_VTABLE_DATA_ENTRY_DISTANCE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Decide whether it is safe to use a local alias for a virtual function    when constructing thunks.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_USE_LOCAL_THUNK_ALIAS_P
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|ASM_OUTPUT_DEF
end_ifdef

begin_define
define|#
directive|define
name|TARGET_USE_LOCAL_THUNK_ALIAS_P
parameter_list|(
name|DECL
parameter_list|)
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|TARGET_USE_LOCAL_THUNK_ALIAS_P
parameter_list|(
name|DECL
parameter_list|)
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
comment|/* If more than one debugging type is supported, you must define    PREFERRED_DEBUGGING_TYPE to choose the default.  */
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
expr|\
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
expr|\
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

begin_error
error|#
directive|error
error|You must define PREFERRED_DEBUGGING_TYPE
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* no PREFERRED_DEBUGGING_TYPE */
end_comment

begin_comment
comment|/* If only one debugging format is supported, define PREFERRED_DEBUGGING_TYPE    here so other code needn't care.  */
end_comment

begin_elif
elif|#
directive|elif
name|defined
name|DBX_DEBUGGING_INFO
end_elif

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_elif
elif|#
directive|elif
name|defined
name|SDB_DEBUGGING_INFO
end_elif

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|SDB_DEBUG
end_define

begin_elif
elif|#
directive|elif
name|defined
name|DWARF2_DEBUGGING_INFO
end_elif

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DWARF2_DEBUG
end_define

begin_elif
elif|#
directive|elif
name|defined
name|VMS_DEBUGGING_INFO
end_elif

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|VMS_AND_DWARF2_DEBUG
end_define

begin_elif
elif|#
directive|elif
name|defined
name|XCOFF_DEBUGGING_INFO
end_elif

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|XCOFF_DEBUG
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* No debugging format is supported by this target.  */
end_comment

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
comment|/* Define codes for all the float formats that we know of.  */
end_comment

begin_define
define|#
directive|define
name|UNKNOWN_FLOAT_FORMAT
value|0
end_define

begin_define
define|#
directive|define
name|IEEE_FLOAT_FORMAT
value|1
end_define

begin_define
define|#
directive|define
name|VAX_FLOAT_FORMAT
value|2
end_define

begin_define
define|#
directive|define
name|IBM_FLOAT_FORMAT
value|3
end_define

begin_define
define|#
directive|define
name|C4X_FLOAT_FORMAT
value|4
end_define

begin_comment
comment|/* Default to IEEE float if not specified.  Nearly all machines use it.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_FLOAT_FORMAT
end_ifndef

begin_define
define|#
directive|define
name|TARGET_FLOAT_FORMAT
value|IEEE_FLOAT_FORMAT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LARGEST_EXPONENT_IS_NORMAL
end_ifndef

begin_define
define|#
directive|define
name|LARGEST_EXPONENT_IS_NORMAL
parameter_list|(
name|SIZE
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|ROUND_TOWARDS_ZERO
end_ifndef

begin_define
define|#
directive|define
name|ROUND_TOWARDS_ZERO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MODE_HAS_NANS
end_ifndef

begin_define
define|#
directive|define
name|MODE_HAS_NANS
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(FLOAT_MODE_P (MODE)						\&& TARGET_FLOAT_FORMAT == IEEE_FLOAT_FORMAT			\&& !LARGEST_EXPONENT_IS_NORMAL (GET_MODE_BITSIZE (MODE)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MODE_HAS_INFINITIES
end_ifndef

begin_define
define|#
directive|define
name|MODE_HAS_INFINITIES
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(FLOAT_MODE_P (MODE)						\&& TARGET_FLOAT_FORMAT == IEEE_FLOAT_FORMAT			\&& !LARGEST_EXPONENT_IS_NORMAL (GET_MODE_BITSIZE (MODE)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MODE_HAS_SIGNED_ZEROS
end_ifndef

begin_define
define|#
directive|define
name|MODE_HAS_SIGNED_ZEROS
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(FLOAT_MODE_P (MODE)&& TARGET_FLOAT_FORMAT == IEEE_FLOAT_FORMAT)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|MODE_HAS_SIGN_DEPENDENT_ROUNDING
end_ifndef

begin_define
define|#
directive|define
name|MODE_HAS_SIGN_DEPENDENT_ROUNDING
parameter_list|(
name|MODE
parameter_list|)
define|\
value|(FLOAT_MODE_P (MODE)						\&& TARGET_FLOAT_FORMAT == IEEE_FLOAT_FORMAT			\&& !ROUND_TOWARDS_ZERO)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FLOAT_LIB_COMPARE_RETURNS_BOOL
end_ifndef

begin_define
define|#
directive|define
name|FLOAT_LIB_COMPARE_RETURNS_BOOL
parameter_list|(
name|MODE
parameter_list|,
name|COMPARISON
parameter_list|)
value|false
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* True if the targets integer-comparison functions return { 0, 1, 2    } to indicate {<, ==,> }.  False if { -1, 0, 1 } is used    instead.  The libgcc routines are biased.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_LIB_INT_CMP_BIASED
end_ifndef

begin_define
define|#
directive|define
name|TARGET_LIB_INT_CMP_BIASED
value|(true)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If FLOAT_WORDS_BIG_ENDIAN is not defined in the header files,    then the word-endianness is the same as for integers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|FLOAT_WORDS_BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|FLOAT_WORDS_BIG_ENDIAN
value|WORDS_BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_FLT_EVAL_METHOD
end_ifndef

begin_define
define|#
directive|define
name|TARGET_FLT_EVAL_METHOD
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_DEC_EVAL_METHOD
end_ifndef

begin_define
define|#
directive|define
name|TARGET_DEC_EVAL_METHOD
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HOT_TEXT_SECTION_NAME
end_ifndef

begin_define
define|#
directive|define
name|HOT_TEXT_SECTION_NAME
value|".text.hot"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|UNLIKELY_EXECUTED_TEXT_SECTION_NAME
end_ifndef

begin_define
define|#
directive|define
name|UNLIKELY_EXECUTED_TEXT_SECTION_NAME
value|".text.unlikely"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_LONG_COND_BRANCH
end_ifndef

begin_define
define|#
directive|define
name|HAS_LONG_COND_BRANCH
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAS_LONG_UNCOND_BRANCH
end_ifndef

begin_define
define|#
directive|define
name|HAS_LONG_UNCOND_BRANCH
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* By default, only attempt to parallelize bitwise operations, and    possibly adds/subtracts using bit-twiddling.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNITS_PER_SIMD_WORD
end_ifndef

begin_define
define|#
directive|define
name|UNITS_PER_SIMD_WORD
value|UNITS_PER_WORD
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Determine whether __cxa_atexit, rather than atexit, is used to    register C++ destructors for local statics and global objects.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_USE_CXA_ATEXIT
end_ifndef

begin_define
define|#
directive|define
name|DEFAULT_USE_CXA_ATEXIT
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If none of these macros are defined, the port must use the new    technique of defining constraints in the machine description.    tm_p.h will define those macros that machine-independent code    still uses.  */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
name|CONSTRAINT_LEN
expr|\
operator|&&
operator|!
name|defined
name|REG_CLASS_FROM_LETTER
expr|\
operator|&&
operator|!
name|defined
name|REG_CLASS_FROM_CONSTRAINT
expr|\
operator|&&
operator|!
name|defined
name|CONST_OK_FOR_LETTER_P
expr|\
operator|&&
operator|!
name|defined
name|CONST_OK_FOR_CONSTRAINT_P
expr|\
operator|&&
operator|!
name|defined
name|CONST_DOUBLE_OK_FOR_LETTER_P
expr|\
operator|&&
operator|!
name|defined
name|CONST_DOUBLE_OK_FOR_CONSTRAINT_P
expr|\
operator|&&
operator|!
name|defined
name|EXTRA_CONSTRAINT
expr|\
operator|&&
operator|!
name|defined
name|EXTRA_CONSTRAINT_STR
expr|\
operator|&&
operator|!
name|defined
name|EXTRA_MEMORY_CONSTRAINT
expr|\
operator|&&
operator|!
name|defined
name|EXTRA_ADDRESS_CONSTRAINT
end_if

begin_define
define|#
directive|define
name|USE_MD_CONSTRAINTS
end_define

begin_if
if|#
directive|if
name|GCC_VERSION
operator|>=
literal|3000
operator|&&
name|defined
name|IN_GCC
end_if

begin_comment
comment|/* These old constraint macros shouldn't appear anywhere in a    configuration using MD constraint definitions.  */
end_comment

begin_pragma
pragma|#
directive|pragma
name|GCC
name|poison
name|REG_CLASS_FROM_LETTER
name|CONST_OK_FOR_LETTER_P
pragma|\
name|CONST_DOUBLE_OK_FOR_LETTER_P
name|EXTRA_CONSTRAINT
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* old constraint mechanism in use */
end_comment

begin_comment
comment|/* Determine whether extra constraint letter should be handled    via address reload (like 'o').  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXTRA_MEMORY_CONSTRAINT
end_ifndef

begin_define
define|#
directive|define
name|EXTRA_MEMORY_CONSTRAINT
parameter_list|(
name|C
parameter_list|,
name|STR
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Determine whether extra constraint letter should be handled    as an address (like 'p').  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXTRA_ADDRESS_CONSTRAINT
end_ifndef

begin_define
define|#
directive|define
name|EXTRA_ADDRESS_CONSTRAINT
parameter_list|(
name|C
parameter_list|,
name|STR
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* When a port defines CONSTRAINT_LEN, it should use DEFAULT_CONSTRAINT_LEN    for all the characters that it does not want to change, so things like the   'length' of a digit in a matching constraint is an implementation detail,    and not part of the interface.  */
end_comment

begin_define
define|#
directive|define
name|DEFAULT_CONSTRAINT_LEN
parameter_list|(
name|C
parameter_list|,
name|STR
parameter_list|)
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CONSTRAINT_LEN
end_ifndef

begin_define
define|#
directive|define
name|CONSTRAINT_LEN
parameter_list|(
name|C
parameter_list|,
name|STR
parameter_list|)
value|DEFAULT_CONSTRAINT_LEN (C, STR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CONST_OK_FOR_LETTER_P
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CONST_OK_FOR_CONSTRAINT_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|CONST_OK_FOR_CONSTRAINT_P
parameter_list|(
name|VAL
parameter_list|,
name|C
parameter_list|,
name|STR
parameter_list|)
value|CONST_OK_FOR_LETTER_P (VAL, C)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CONST_DOUBLE_OK_FOR_LETTER_P
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|CONST_DOUBLE_OK_FOR_CONSTRAINT_P
argument_list|)
end_if

begin_define
define|#
directive|define
name|CONST_DOUBLE_OK_FOR_CONSTRAINT_P
parameter_list|(
name|OP
parameter_list|,
name|C
parameter_list|,
name|STR
parameter_list|)
define|\
value|CONST_DOUBLE_OK_FOR_LETTER_P (OP, C)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|REG_CLASS_FROM_CONSTRAINT
end_ifndef

begin_define
define|#
directive|define
name|REG_CLASS_FROM_CONSTRAINT
parameter_list|(
name|C
parameter_list|,
name|STR
parameter_list|)
value|REG_CLASS_FROM_LETTER (C)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|EXTRA_CONSTRAINT
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|EXTRA_CONSTRAINT_STR
argument_list|)
end_if

begin_define
define|#
directive|define
name|EXTRA_CONSTRAINT_STR
parameter_list|(
name|OP
parameter_list|,
name|C
parameter_list|,
name|STR
parameter_list|)
value|EXTRA_CONSTRAINT (OP, C)
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
comment|/* old constraint mechanism in use */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REGISTER_MOVE_COST
end_ifndef

begin_define
define|#
directive|define
name|REGISTER_MOVE_COST
parameter_list|(
name|m
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Determine whether the entire c99 runtime    is present in the runtime library.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TARGET_C99_FUNCTIONS
end_ifndef

begin_define
define|#
directive|define
name|TARGET_C99_FUNCTIONS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Indicate that CLZ and CTZ are undefined at zero.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CLZ_DEFINED_VALUE_AT_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CLZ_DEFINED_VALUE_AT_ZERO
parameter_list|(
name|MODE
parameter_list|,
name|VALUE
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|CTZ_DEFINED_VALUE_AT_ZERO
end_ifndef

begin_define
define|#
directive|define
name|CTZ_DEFINED_VALUE_AT_ZERO
parameter_list|(
name|MODE
parameter_list|,
name|VALUE
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Provide a default value for STORE_FLAG_VALUE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|STORE_FLAG_VALUE
end_ifndef

begin_define
define|#
directive|define
name|STORE_FLAG_VALUE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This macro is used to determine what the largest unit size that    move_by_pieces can use is.  */
end_comment

begin_comment
comment|/* MOVE_MAX_PIECES is the number of bytes at a time which we can    move efficiently, as opposed to  MOVE_MAX which is the maximum    number of bytes we can move with a single instruction.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MOVE_MAX_PIECES
end_ifndef

begin_define
define|#
directive|define
name|MOVE_MAX_PIECES
value|MOVE_MAX
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|STACK_POINTER_OFFSET
end_ifndef

begin_define
define|#
directive|define
name|STACK_POINTER_OFFSET
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LOCAL_REGNO
end_ifndef

begin_define
define|#
directive|define
name|LOCAL_REGNO
parameter_list|(
name|REGNO
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* EXIT_IGNORE_STACK should be nonzero if, when returning from a function,    the stack pointer does not matter.  The value is tested only in    functions that have frame pointers.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|EXIT_IGNORE_STACK
end_ifndef

begin_define
define|#
directive|define
name|EXIT_IGNORE_STACK
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Assume that case vectors are not pc-relative.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CASE_VECTOR_PC_RELATIVE
end_ifndef

begin_define
define|#
directive|define
name|CASE_VECTOR_PC_RELATIVE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Assume that trampolines need function alignment.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TRAMPOLINE_ALIGNMENT
end_ifndef

begin_define
define|#
directive|define
name|TRAMPOLINE_ALIGNMENT
value|FUNCTION_BOUNDARY
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Register mappings for target machines without register windows.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INCOMING_REGNO
end_ifndef

begin_define
define|#
directive|define
name|INCOMING_REGNO
parameter_list|(
name|N
parameter_list|)
value|(N)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|OUTGOING_REGNO
end_ifndef

begin_define
define|#
directive|define
name|OUTGOING_REGNO
parameter_list|(
name|N
parameter_list|)
value|(N)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|SHIFT_COUNT_TRUNCATED
end_ifndef

begin_define
define|#
directive|define
name|SHIFT_COUNT_TRUNCATED
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LEGITIMIZE_ADDRESS
end_ifndef

begin_define
define|#
directive|define
name|LEGITIMIZE_ADDRESS
parameter_list|(
name|X
parameter_list|,
name|OLDX
parameter_list|,
name|MODE
parameter_list|,
name|WIN
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LEGITIMATE_PIC_OPERAND_P
end_ifndef

begin_define
define|#
directive|define
name|LEGITIMATE_PIC_OPERAND_P
parameter_list|(
name|X
parameter_list|)
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|REVERSIBLE_CC_MODE
end_ifndef

begin_define
define|#
directive|define
name|REVERSIBLE_CC_MODE
parameter_list|(
name|MODE
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Biggest alignment supported by the object file format of this machine.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|MAX_OFILE_ALIGNMENT
end_ifndef

begin_define
define|#
directive|define
name|MAX_OFILE_ALIGNMENT
value|BIGGEST_ALIGNMENT
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|FRAME_GROWS_DOWNWARD
end_ifndef

begin_define
define|#
directive|define
name|FRAME_GROWS_DOWNWARD
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* On most machines, the CFA coincides with the first incoming parm.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ARG_POINTER_CFA_OFFSET
end_ifndef

begin_define
define|#
directive|define
name|ARG_POINTER_CFA_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
value|FIRST_PARM_OFFSET (FNDECL)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* On most machines, we use the CFA as DW_AT_frame_base.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CFA_FRAME_BASE_OFFSET
end_ifndef

begin_define
define|#
directive|define
name|CFA_FRAME_BASE_OFFSET
parameter_list|(
name|FNDECL
parameter_list|)
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The offset from the incoming value of %sp to the top of the stack frame    for the current function.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|INCOMING_FRAME_SP_OFFSET
end_ifndef

begin_define
define|#
directive|define
name|INCOMING_FRAME_SP_OFFSET
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HARD_REGNO_NREGS_HAS_PADDING
end_ifndef

begin_define
define|#
directive|define
name|HARD_REGNO_NREGS_HAS_PADDING
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|HARD_REGNO_NREGS_WITH_PADDING
parameter_list|(
name|REGNO
parameter_list|,
name|MODE
parameter_list|)
value|-1
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

