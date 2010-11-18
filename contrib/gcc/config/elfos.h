begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* elfos.h  --  operating system specific defines to be used when    targeting GCC for some generic ELF system    Copyright (C) 1991, 1994, 1995, 1999, 2000, 2001, 2002, 2003, 2004    Free Software Foundation, Inc.    Based on svr4.h contributed by Ron Guilmette (rfg@netcom.com).  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_OBJFMT_CPP_BUILTINS
parameter_list|()
define|\
value|do						\     {						\ 	builtin_define ("__ELF__");		\     }						\   while (0)
end_define

begin_comment
comment|/* Define a symbol indicating that we are using elfos.h.    Some CPU specific configuration files use this.  */
end_comment

begin_define
define|#
directive|define
name|USING_ELFOS_H
end_define

begin_comment
comment|/* The prefix to add to user-visible assembler symbols.     For ELF systems the convention is *not* to prepend a leading    underscore onto user-level symbol names.  */
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
comment|/* Biggest alignment supported by the object file format of this    machine.  Use this macro to limit the alignment which can be    specified using the `__attribute__ ((aligned (N)))' construct.  If    not defined, the default value is `BIGGEST_ALIGNMENT'.  */
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
value|(32768 * 8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use periods rather than dollar signs in special g++ assembler names.  */
end_comment

begin_define
define|#
directive|define
name|NO_DOLLAR_IN_LABEL
end_define

begin_comment
comment|/* Writing `int' for a bit-field forces int alignment for the structure.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PCC_BITFIELD_TYPE_MATTERS
end_ifndef

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Handle #pragma weak and #pragma pack.  */
end_comment

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
value|1
end_define

begin_comment
comment|/* All ELF targets can support DWARF-2.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_DEBUGGING_INFO
value|1
end_define

begin_comment
comment|/* The GNU tools operate better with dwarf2, and it is required by some    psABI's.  Since we don't have any native tools to be compatible with,    default to dwarf2.  */
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
value|DWARF2_DEBUG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* All SVR4 targets use the ELF object file format.  */
end_comment

begin_define
define|#
directive|define
name|OBJECT_FORMAT_ELF
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
value|fprintf (FILE, "%s\"%s\"\n", IDENT_ASM_OP, NAME);
end_define

begin_define
define|#
directive|define
name|IDENT_ASM_OP
value|"\t.ident\t"
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
value|"\t.set\t"
end_define

begin_comment
comment|/* Most svr4 assemblers want a .file directive at the beginning of    their input file.  */
end_comment

begin_define
define|#
directive|define
name|TARGET_ASM_FILE_START_FILE_DIRECTIVE
value|true
end_define

begin_comment
comment|/* This is how to allocate empty space in some section.  The .zero    pseudo-op is used for this on most svr4 assemblers.  */
end_comment

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
value|fprintf ((FILE), "%s"HOST_WIDE_INT_PRINT_UNSIGNED"\n",\ 	    SKIP_ASM_OP, (SIZE))
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
value|do								\     {								\       sprintf (LABEL, "*.%s%u", PREFIX, (unsigned) (NUM));	\     }								\   while (0)
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
value|do									\     {									\       ASM_OUTPUT_BEFORE_CASE_LABEL (FILE, PREFIX, NUM, JUMPTABLE)	\ 	(*targetm.asm_out.internal_label) (FILE, PREFIX, NUM);			\     }									\   while (0)
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
value|(*targetm.asm_out.globalize_label) (FILE, XSTR (FUN, 0))
end_define

begin_comment
comment|/* This says how to output assembler code to declare an    uninitialized external linkage data object.  Under SVR4,    the linker seems to want the alignment of data objects    to depend on their types.  We do exactly that here.  */
end_comment

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
value|do									\     {									\       fprintf ((FILE), "%s", COMMON_ASM_OP);				\       assemble_name ((FILE), (NAME));					\       fprintf ((FILE), ","HOST_WIDE_INT_PRINT_UNSIGNED",%u\n",		\ 	       (SIZE), (ALIGN) / BITS_PER_UNIT);			\     }									\   while (0)
end_define

begin_comment
comment|/* This says how to output assembler code to declare an    uninitialized internal linkage data object.  Under SVR4,    the linker seems to want the alignment of data objects    to depend on their types.  We do exactly that here.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_ASM_OP
value|"\t.local\t"
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
value|do								\     {								\       fprintf ((FILE), "%s", LOCAL_ASM_OP);			\       assemble_name ((FILE), (NAME));				\       fprintf ((FILE), "\n");					\       ASM_OUTPUT_ALIGNED_COMMON (FILE, NAME, SIZE, ALIGN);	\     }								\   while (0)
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
comment|/* Support a read-only data section.  */
end_comment

begin_define
define|#
directive|define
name|READONLY_DATA_SECTION_ASM_OP
value|"\t.section\t.rodata"
end_define

begin_comment
comment|/* On svr4, we *do* have support for the .init and .fini sections, and we    can put stuff in there to be executed before and after `main'.  We let    crtstuff.c and other files know this by defining the following symbols.    The definitions say how to change sections to the .init and .fini    sections.  This is the same for all known svr4 assemblers.  */
end_comment

begin_define
define|#
directive|define
name|INIT_SECTION_ASM_OP
value|"\t.section\t.init"
end_define

begin_define
define|#
directive|define
name|FINI_SECTION_ASM_OP
value|"\t.section\t.fini"
end_define

begin_comment
comment|/* Output assembly directive to move to the beginning of current section.  */
end_comment

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

begin_define
define|#
directive|define
name|MAKE_DECL_ONE_ONLY
parameter_list|(
name|DECL
parameter_list|)
value|(DECL_WEAK (DECL) = 1)
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

begin_undef
undef|#
directive|undef
name|TARGET_ASM_SELECT_RTX_SECTION
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_SELECT_RTX_SECTION
value|default_elf_select_rtx_section
end_define

begin_undef
undef|#
directive|undef
name|TARGET_ASM_SELECT_SECTION
end_undef

begin_define
define|#
directive|define
name|TARGET_ASM_SELECT_SECTION
value|default_elf_select_section
end_define

begin_undef
undef|#
directive|undef
name|TARGET_HAVE_SWITCHABLE_BSS_SECTIONS
end_undef

begin_define
define|#
directive|define
name|TARGET_HAVE_SWITCHABLE_BSS_SECTIONS
value|true
end_define

begin_comment
comment|/* Define the strings used for the special svr4 .type and .size directives.    These strings generally do not vary from one system running svr4 to    another, but if a given system (e.g. m88k running svr) needs to use    different pseudo-op names for these, they may be overridden in the    file which includes this one.  */
end_comment

begin_define
define|#
directive|define
name|TYPE_ASM_OP
value|"\t.type\t"
end_define

begin_define
define|#
directive|define
name|SIZE_ASM_OP
value|"\t.size\t"
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
value|do					\     {					\       fputs ("\t.weak\t", (FILE));	\       assemble_name ((FILE), (NAME));	\       fputc ('\n', (FILE));		\     }					\   while (0)
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

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_DECLARE_FUNCTION_NAME
end_ifndef

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
value|do								\     {								\       ASM_OUTPUT_TYPE_DIRECTIVE (FILE, NAME, "function");	\       ASM_DECLARE_RESULT (FILE, DECL_RESULT (DECL));		\       ASM_OUTPUT_LABEL (FILE, NAME);				\     }								\   while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|do								\     {								\       HOST_WIDE_INT size;					\ 								\       ASM_OUTPUT_TYPE_DIRECTIVE (FILE, NAME, "object");		\ 								\       size_directive_output = 0;				\       if (!flag_inhibit_size_directive				\&& (DECL)&& DECL_SIZE (DECL))			\ 	{							\ 	  size_directive_output = 1;				\ 	  size = int_size_in_bytes (TREE_TYPE (DECL));		\ 	  ASM_OUTPUT_SIZE_DIRECTIVE (FILE, NAME, size);		\ 	}							\ 								\       ASM_OUTPUT_LABEL (FILE, NAME);				\     }								\   while (0)
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
value|do								\     {								\       const char *name = XSTR (XEXP (DECL_RTL (DECL), 0), 0);	\       HOST_WIDE_INT size;					\ 								\       if (!flag_inhibit_size_directive				\&& DECL_SIZE (DECL)					\&& ! AT_END&& TOP_LEVEL				\&& DECL_INITIAL (DECL) == error_mark_node		\&& !size_directive_output)				\ 	{							\ 	  size_directive_output = 1;				\ 	  size = int_size_in_bytes (TREE_TYPE (DECL));		\ 	  ASM_OUTPUT_SIZE_DIRECTIVE (FILE, name, size);		\ 	}							\     }								\   while (0)
end_define

begin_comment
comment|/* This is how to declare the size of a function.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_DECLARE_FUNCTION_SIZE
end_ifndef

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
value|do								\     {								\       if (!flag_inhibit_size_directive)				\ 	ASM_OUTPUT_MEASURED_SIZE (FILE, FNAME);			\     }								\   while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

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
value|"\t.string\t"
end_define

begin_comment
comment|/* The routine used to output NUL terminated strings.  We use a special    version of this for most svr4 targets because doing so makes the    generated assembly code more compact (and thus faster to assemble)    as well as more readable, especially for targets like the i386    (where the only alternative is to output character sequences as    comma separated lists of numbers).  */
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
value|do							\     {							\       register const unsigned char *_limited_str =	\ 	(const unsigned char *) (STR);			\       register unsigned ch;				\ 							\       fprintf ((FILE), "%s\"", STRING_ASM_OP);		\ 							\       for (; (ch = *_limited_str); _limited_str++)	\         {						\ 	  register int escape;				\ 							\ 	  switch (escape = ESCAPES[ch])			\ 	    {						\ 	    case 0:					\ 	      putc (ch, (FILE));			\ 	      break;					\ 	    case 1:					\ 	      fprintf ((FILE), "\\%03o", ch);		\ 	      break;					\ 	    default:					\ 	      putc ('\\', (FILE));			\ 	      putc (escape, (FILE));			\ 	      break;					\ 	    }						\         }						\ 							\       fprintf ((FILE), "\"\n");				\     }							\   while (0)
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
value|do									\     {									\       const unsigned char *_ascii_bytes =				\ 	(const unsigned char *) (STR);					\       const unsigned char *limit = _ascii_bytes + (LENGTH);		\       const unsigned char *last_null = NULL;				\       unsigned bytes_in_chunk = 0;					\ 									\       for (; _ascii_bytes< limit; _ascii_bytes++)			\         {								\ 	  const unsigned char *p;					\ 									\ 	  if (bytes_in_chunk>= 60)					\ 	    {								\ 	      fprintf ((FILE), "\"\n");					\ 	      bytes_in_chunk = 0;					\ 	    }								\ 									\ 	  if (_ascii_bytes> last_null)					\ 	    {								\ 	      for (p = _ascii_bytes; p< limit&& *p != '\0'; p++)	\ 		continue;						\ 	      last_null = p;						\ 	    }								\ 	  else								\ 	    p = last_null;						\ 									\ 	  if (p< limit&& (p - _ascii_bytes)<= (long)STRING_LIMIT)	\ 	    {								\ 	      if (bytes_in_chunk> 0)					\ 		{							\ 		  fprintf ((FILE), "\"\n");				\ 		  bytes_in_chunk = 0;					\ 		}							\ 									\ 	      ASM_OUTPUT_LIMITED_STRING ((FILE), _ascii_bytes);		\ 	      _ascii_bytes = p;						\ 	    }								\ 	  else								\ 	    {								\ 	      register int escape;					\ 	      register unsigned ch;					\ 									\ 	      if (bytes_in_chunk == 0)					\ 		fprintf ((FILE), "%s\"", ASCII_DATA_ASM_OP);		\ 									\ 	      switch (escape = ESCAPES[ch = *_ascii_bytes])		\ 		{							\ 		case 0:							\ 		  putc (ch, (FILE));					\ 		  bytes_in_chunk++;					\ 		  break;						\ 		case 1:							\ 		  fprintf ((FILE), "\\%03o", ch);			\ 		  bytes_in_chunk += 4;					\ 		  break;						\ 		default:						\ 		  putc ('\\', (FILE));					\ 		  putc (escape, (FILE));				\ 		  bytes_in_chunk += 2;					\ 		  break;						\ 		}							\ 	    }								\ 	}								\ 									\       if (bytes_in_chunk> 0)						\         fprintf ((FILE), "\"\n");					\     }									\   while (0)
end_define

end_unit

