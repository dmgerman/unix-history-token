begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for GNU compiler for Intel 80386 running Interix    Parts Copyright (C) 1991, 1999 Free Software Foundation, Inc.     Parts:      by Douglas B. Rupp (drupp@cs.washington.edu).      by Ron Guilmette (rfg@netcom.com).      by Donn Terry (donn@softway.com).      by Mumit Khan (khan@xraylith.wisc.edu).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|YES_UNDERSCORES
end_define

begin_comment
comment|/* YES_UNDERSCORES must preceed gas.h */
end_comment

begin_include
include|#
directive|include
file|<i386/gas.h>
end_include

begin_comment
comment|/* The rest must follow. */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_define
define|#
directive|define
name|SDB_DEBUGGING_INFO
end_define

begin_define
define|#
directive|define
name|PREFERRED_DEBUGGING_TYPE
value|DBX_DEBUG
end_define

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
end_define

begin_undef
undef|#
directive|undef
name|HANDLE_PRAGMA_WEAK
end_undef

begin_comment
comment|/* until the link format can handle it */
end_comment

begin_comment
comment|/* By default, target has a 80387, uses IEEE compatible arithmetic,    and returns float values in the 387 and needs stack probes    We also align doubles to 64-bits for MSVC default compatability */
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
define|\
value|(MASK_80387 | MASK_IEEE_FP | MASK_FLOAT_RETURNS | MASK_STACK_PROBE | \     MASK_ALIGN_DOUBLE)
end_define

begin_undef
undef|#
directive|undef
name|TARGET_CPU_DEFAULT
end_undef

begin_define
define|#
directive|define
name|TARGET_CPU_DEFAULT
value|2
end_define

begin_comment
comment|/* 486 */
end_comment

begin_define
define|#
directive|define
name|WCHAR_UNSIGNED
value|1
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE_SIZE
value|16
end_define

begin_define
define|#
directive|define
name|WCHAR_TYPE
value|"short unsigned int"
end_define

begin_comment
comment|/* WinNT (and thus Interix) use unsigned int */
end_comment

begin_define
define|#
directive|define
name|SIZE_TYPE
value|"unsigned int"
end_define

begin_define
define|#
directive|define
name|ASM_LOAD_ADDR
parameter_list|(
name|loc
parameter_list|,
name|reg
parameter_list|)
value|"     leal " #loc "," #reg "\n"
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
comment|/* cpp handles __STDC__ */
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
value|" \   -D__INTERIX \   -D__OPENNT \   -D_M_IX86=300 -D_X86_=1 \   -D__stdcall=__attribute__((__stdcall__)) \   -D__cdecl=__attribute__((__cdecl__)) \   -Asystem(unix) -Asystem(interix) -Asystem(interix) -Acpu(i386) -Amachine(i386)"
end_define

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_comment
comment|/* Write out the correct language type definition for the header files.      Unless we have assembler language, write out the symbols for C.    cpp_cpu is an Intel specific variant. See i386.h    mieee is an Alpha specific variant.  Cross polination a bad idea.    */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|"\ %{!.S:	-D__LANGUAGE_C__ -D__LANGUAGE_C %{!ansi:-DLANGUAGE_C}}  \ %{.S:	-D__LANGUAGE_ASSEMBLY__ -D__LANGUAGE_ASSEMBLY %{!ansi:-DLANGUAGE_ASSEMBLY}} \ %{.cc:	-D__LANGUAGE_C_PLUS_PLUS__ -D__LANGUAGE_C_PLUS_PLUS -D__cplusplus} \ %{.cxx:	-D__LANGUAGE_C_PLUS_PLUS__ -D__LANGUAGE_C_PLUS_PLUS -D__cplusplus} \ %{.C:	-D__LANGUAGE_C_PLUS_PLUS__ -D__LANGUAGE_C_PLUS_PLUS -D__cplusplus} \ %{.m:	-D__LANGUAGE_OBJECTIVE_C__ -D__LANGUAGE_OBJECTIVE_C} \ -remap \ %(cpp_cpu) \ %{posix:-D_POSIX_SOURCE} \ -idirafter %$INTERIX_ROOT/usr/include"
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
value|fprintf (stderr, " (i386 Interix)");
end_define

begin_comment
comment|/* The global __fltused is necessary to cause the printf/scanf routines    for outputting/inputting floating point numbers to be loaded.  Since this    is kind of hard to detect, we just do it all the time. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ASM_FILE_START
end_ifdef

begin_undef
undef|#
directive|undef
name|ASM_FILE_START
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|FILE
parameter_list|)
define|\
value|do {  fprintf (FILE, "\t.file\t");                            \         output_quoted_string (FILE, dump_base_name);            \         fprintf (FILE, "\n");                                   \         fprintf (FILE, ".global\t__fltused\n");                 \   } while (0)
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
value|do									\     {									\       register unsigned char *_limited_str = (unsigned char *) (STR);	\       register unsigned ch;						\       fprintf ((FILE), "\t%s\t\"", STRING_ASM_OP);			\       for (; (ch = *_limited_str); _limited_str++)			\         {								\ 	  register int escape = ESCAPES[ch];				\ 	  switch (escape)						\ 	    {								\ 	    case 0:							\ 	      putc (ch, (FILE));					\ 	      break;							\ 	    case 1:							\ 	      fprintf ((FILE), "\\%03o", ch);				\ 	      break;							\ 	    default:							\ 	      putc ('\\', (FILE));					\ 	      putc (escape, (FILE));					\ 	      break;							\ 	    }								\         }								\       fprintf ((FILE), "\"\n");						\     }									\   while (0)
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
value|do									\     {									\       register unsigned char *_ascii_bytes = (unsigned char *) (STR);	\       register unsigned char *limit = _ascii_bytes + (LENGTH);		\       register unsigned bytes_in_chunk = 0;				\       for (; _ascii_bytes< limit; _ascii_bytes++)			\         {								\ 	  register unsigned char *p;					\ 	  if (bytes_in_chunk>= 64)					\ 	    {								\ 	      fputc ('\n', (FILE));					\ 	      bytes_in_chunk = 0;					\ 	    }								\ 	  for (p = _ascii_bytes; p< limit&& *p != '\0'; p++)		\ 	    continue;							\ 	  if (p< limit&& (p - _ascii_bytes)<= STRING_LIMIT)		\ 	    {								\ 	      if (bytes_in_chunk> 0)					\ 		{							\ 		  fputc ('\n', (FILE));					\ 		  bytes_in_chunk = 0;					\ 		}							\ 	      ASM_OUTPUT_LIMITED_STRING ((FILE), _ascii_bytes);		\ 	      _ascii_bytes = p;						\ 	    }								\ 	  else								\ 	    {								\ 	      if (bytes_in_chunk == 0)					\ 		fprintf ((FILE), "\t.byte\t");				\ 	      else							\ 		fputc (',', (FILE));					\ 	      fprintf ((FILE), "0x%02x", *_ascii_bytes);		\ 	      bytes_in_chunk += 5;					\ 	    }								\ 	}								\       if (bytes_in_chunk> 0)						\         fprintf ((FILE), "\n");						\     }									\   while (0)
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is relative.    This is only used for PIC code.  See comments by the `casesi' insn in    i386.md for an explanation of the expression this outputs.    PE format differs on what PC-relative offsets look like (see    coff_i386_rtype_to_howto), and we need to compensate (by one word) here. */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ADDR_DIFF_ELT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_DIFF_ELT
parameter_list|(
name|FILE
parameter_list|,
name|BODY
parameter_list|,
name|VALUE
parameter_list|,
name|REL
parameter_list|)
define|\
value|fprintf (FILE, "\t.long __GLOBAL_OFFSET_TABLE_+[.-%s%d+4]\n", LPREFIX, VALUE)
end_define

begin_comment
comment|/* Indicate that jump tables go in the text section.  This is    necessary when compiling PIC code.  */
end_comment

begin_define
define|#
directive|define
name|JUMP_TABLES_IN_TEXT_SECTION
value|1
end_define

begin_comment
comment|/* Emit code to check the stack when allocating more that 4000    bytes in one go. */
end_comment

begin_define
define|#
directive|define
name|CHECK_STACK_LIMIT
value|0x1000
end_define

begin_comment
comment|/* the following are OSF linker (not gld) specific... we don't want them */
end_comment

begin_undef
undef|#
directive|undef
name|HAS_INIT_SECTION
end_undef

begin_undef
undef|#
directive|undef
name|LD_INIT_SWITCH
end_undef

begin_undef
undef|#
directive|undef
name|LD_FINI_SWITCH
end_undef

begin_comment
comment|/* The following are needed for C++, but also needed for profiling */
end_comment

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
value|".section\t.rdata,\"r\""
end_define

begin_comment
comment|/* Define the pseudo-ops used to switch to the .ctors and .dtors sections.     Note that we want to give these sections the SHF_WRITE attribute    because these sections will actually contain data (i.e. tables of    addresses of functions in the current root executable or shared library    file) and, in the case of a shared library, the relocatable addresses    will have to be properly resolved/relocated (and then written into) by    the dynamic linker when it actually attaches the given shared library    to the executing process.  (Note that on SVR4, you may wish to use the    `-z text' option to the ELF linker, when building a shared library, as    an additional check that you are doing everything right.  But if you do    use the `-z text' option when building a shared library, you will get    errors unless the .ctors and .dtors sections are marked as writable    via the SHF_WRITE attribute.)  */
end_comment

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|".section\t.ctors,\"x\""
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|".section\t.dtors,\"x\""
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

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Currently gas chokes on this; that's not too hard to fix, but there's    not a lot of impeteus to do it, either.  If it is done, gas will have    to handle long section name escapes (which are defined in the COFF/PE    document as /nnn where nnn is a string table index).  The benefit:    section attributes and -ffunction-sections, neither of which seem to    be critical. */
end_comment

begin_comment
comment|/* gas may have been fixed? bfd was. */
end_comment

begin_comment
comment|/* Switch into a generic section.    This is currently only used to support section attributes.     We make the section read-only and executable for a function decl,    read-only for a const data decl, and writable for a non-const data decl.  */
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
parameter_list|)
define|\
value|fprintf (FILE, ".section\t%s,\"%s\",@progbits\n", NAME, \ 	   (DECL)&& TREE_CODE (DECL) == FUNCTION_DECL ? "ax" : \ 	   (DECL)&& TREE_READONLY (DECL) ? "a" : "aw")
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|INT_ASM_OP
value|".long"
end_define

begin_comment
comment|/* The MS compilers take alignment as a number of bytes, so we do as well */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_ALIGN
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|FILE
parameter_list|,
name|LOG
parameter_list|)
define|\
value|if ((LOG)!=0) fprintf ((FILE), "\t.balign %d\n", 1<<(LOG))
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
comment|/* The linker will take care of this, and having them causes problems with    ld -r (specifically -rU). */
end_comment

begin_define
define|#
directive|define
name|CTOR_LISTS_DEFINED_EXTERNALLY
value|1
end_define

begin_define
define|#
directive|define
name|SET_ASM_OP
value|".set"
end_define

begin_comment
comment|/* Output a definition (implements alias) */
end_comment

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
value|do									\ {									\     fprintf ((FILE), "\t%s\t", SET_ASM_OP);				\     assemble_name (FILE, LABEL1);					\     fprintf (FILE, ",");						\     assemble_name (FILE, LABEL2);					\     fprintf (FILE, "\n");						\     }									\ while (0)
end_define

begin_define
define|#
directive|define
name|HOST_PTR_PRINTF
value|"%p"
end_define

begin_define
define|#
directive|define
name|HOST_PTR_AS_INT
value|unsigned long
end_define

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_TEST
value|TYPE_NATIVE(rec)
end_define

begin_define
define|#
directive|define
name|GROUP_BITFIELDS_BY_ALIGN
value|TYPE_NATIVE(rec)
end_define

begin_comment
comment|/* The following two flags are usually "off" for i386, because some non-gnu    tools (for the i386) don't handle them.  However, we don't have that    problem, so.... */
end_comment

begin_comment
comment|/* Forward references to tags are allowed.  */
end_comment

begin_define
define|#
directive|define
name|SDB_ALLOW_FORWARD_REFERENCES
end_define

begin_comment
comment|/* Unknown tags are also allowed.  */
end_comment

begin_define
define|#
directive|define
name|SDB_ALLOW_UNKNOWN_REFERENCES
end_define

begin_comment
comment|/* The integer half of this list needs to be constant.  However, there's    a lot of disagreement about what the floating point adjustments should    be.  We pick one that works with gdb.  (The underlying problem is    what to do about the segment registers.  Since we have access to them    from /proc, we'll allow them to be accessed in gdb, even tho the    gcc compiler can't generate them.  (There's some evidence that     MSVC does, but possibly only for certain special "canned" sequences.) */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_REGISTER_NUMBER
end_undef

begin_define
define|#
directive|define
name|DBX_REGISTER_NUMBER
parameter_list|(
name|n
parameter_list|)
define|\
value|((n) == 0 ? 0 \  : (n) == 1 ? 2 \  : (n) == 2 ? 1 \  : (n) == 3 ? 3 \  : (n) == 4 ? 6 \  : (n) == 5 ? 7 \  : (n) == 6 ? 5 \  : (n) == 7 ? 4 \  : ((n)>= FIRST_STACK_REG&& (n)<= LAST_STACK_REG) ? (n)+8 \  : (-1))
end_define

begin_comment
comment|/* Define this macro if references to a symbol must be treated    differently depending on something about the variable or    function named by the symbol (such as what section it is in).     Apply stddef, handle (as yet unimplemented) pic.     stddef renaming does NOT apply to Alpha. */
end_comment

begin_function_decl
name|char
modifier|*
name|gen_stdcall_suffix
parameter_list|()
function_decl|;
end_function_decl

begin_undef
undef|#
directive|undef
name|ENCODE_SECTION_INFO
end_undef

begin_define
define|#
directive|define
name|ENCODE_SECTION_INFO
parameter_list|(
name|DECL
parameter_list|)
define|\
value|do 									\   {									\     if (flag_pic)							\       {									\ 	rtx rtl = (TREE_CODE_CLASS (TREE_CODE (DECL)) != 'd'		\ 		   ? TREE_CST_RTL (DECL) : DECL_RTL (DECL));		\ 	SYMBOL_REF_FLAG (XEXP (rtl, 0))					\ 	  = (TREE_CODE_CLASS (TREE_CODE (DECL)) != 'd'			\ 	     || ! TREE_PUBLIC (DECL));					\       }									\     if (TREE_CODE (DECL) == FUNCTION_DECL) 				\       if (lookup_attribute ("stdcall",					\ 			    TYPE_ATTRIBUTES (TREE_TYPE (DECL))))	\         XEXP (DECL_RTL (DECL), 0) = 					\           gen_rtx (SYMBOL_REF, Pmode, gen_stdcall_suffix (DECL)); 	\   }									\ while (0)
end_define

begin_comment
comment|/* This macro gets just the user-specified name    out of the string in a SYMBOL_REF.  Discard    trailing @[NUM] encoded by ENCODE_SECTION_INFO.  */
end_comment

begin_undef
undef|#
directive|undef
name|STRIP_NAME_ENCODING
end_undef

begin_define
define|#
directive|define
name|STRIP_NAME_ENCODING
parameter_list|(
name|VAR
parameter_list|,
name|SYMBOL_NAME
parameter_list|)
define|\
value|do {									\   char *_p;								\   char *_name = SYMBOL_NAME;						\   for (_p = _name; *_p&& *_p != '@'; ++_p)				\     ;									\   if (*_p == '@')							\     {									\       int _len = _p - _name;						\       (VAR) = (char *) alloca (_len + 1);				\       strncpy ((VAR), _name, _len);					\       (VAR)[_len] = '\0';						\     }									\   else									\     (VAR) = _name;							\ } while (0)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Turn this back on when the linker is updated to handle grouped    .data$ sections correctly. See corresponding note in i386/interix.c.     MK. */
end_comment

begin_comment
comment|/* Define this macro if in some cases global symbols from one translation    unit may not be bound to undefined symbols in another translation unit    without user intervention.  For instance, under Microsoft Windows    symbols must be explicitly imported from shared libraries (DLLs).  */
end_comment

begin_define
define|#
directive|define
name|MULTIPLE_SYMBOL_SPACES
end_define

begin_define
define|#
directive|define
name|UNIQUE_SECTION_P
parameter_list|(
name|DECL
parameter_list|)
value|DECL_ONE_ONLY (DECL)
end_define

begin_define
unit|extern void i386_pe_unique_section ();
define|#
directive|define
name|UNIQUE_SECTION
parameter_list|(
name|DECL
parameter_list|,
name|RELOC
parameter_list|)
value|i386_pe_unique_section (DECL, RELOC)
end_define

begin_define
define|#
directive|define
name|SUPPORTS_ONE_ONLY
value|1
end_define

begin_comment
comment|/* A C statement to output something to the assembler file to switch to section    NAME for object DECL which is either a FUNCTION_DECL, a VAR_DECL or    NULL_TREE.  Some target formats do not support arbitrary sections.  Do not    define this macro in such cases.  */
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
name|STREAM
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|,
name|RELOC
parameter_list|)
define|\
value|do {									\   static struct section_info						\     {									\       struct section_info *next;					\       char *name;							\       enum sect_enum {SECT_RW, SECT_RO, SECT_EXEC} type;		\     } *sections;							\   struct section_info *s;						\   char *mode;								\   enum sect_enum type;							\ 									\   for (s = sections; s; s = s->next)					\     if (!strcmp (NAME, s->name))					\       break;								\ 									\   if (DECL&& TREE_CODE (DECL) == FUNCTION_DECL)			\     type = SECT_EXEC, mode = "x";					\   else if (DECL&& DECL_READONLY_SECTION (DECL, RELOC))			\     type = SECT_RO, mode = "r";						\   else									\     type = SECT_RW, mode = "w";						\ 									\   if (s == 0)								\     {									\       s = (struct section_info *) xmalloc (sizeof (struct section_info)); \       s->name = xmalloc ((strlen (NAME) + 1) * sizeof (*NAME));		\       strcpy (s->name, NAME);						\       s->type = type;							\       s->next = sections;						\       sections = s;							\       fprintf (STREAM, ".section\t%s,\"%s\"\n", NAME, mode);		\
comment|/* Functions may have been compiled at various levels of		\          optimization so we can't use `same_size' here.  Instead,	\          have the linker pick one.  */
value|\       if ((DECL)&& DECL_ONE_ONLY (DECL))				\         fprintf (STREAM, "\t.linkonce %s\n",				\ 	         TREE_CODE (DECL) == FUNCTION_DECL			\ 	         ? "discard" : "same_size");				\     }									\   else									\     {									\       fprintf (STREAM, ".section\t%s,\"%s\"\n", NAME, mode);		\     }									\ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* 0 */
end_comment

begin_comment
comment|/* DWARF2 Unwinding doesn't work with exception handling yet. */
end_comment

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|0
end_define

begin_comment
comment|/* Don't assume anything about the header files. */
end_comment

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

end_unit

