begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Base configuration file for all FreeBSD targets.    Copyright (C) 1999, 2000 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Common FreeBSD configuration.     All FreeBSD architectures should include this file, which will specify    their commonalities.    Adapted from /usr/src/contrib/gcc/config/i386/freebsd.h,    /usr/src/contrib/gcc/config/svr4.h&     egcs/gcc/config/i386/freebsd-elf.h by    David O'Brien<obrien@FreeBSD.org>.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Cpp, assembler, linker, library, and startfile spec's.  */
end_comment

begin_comment
comment|/* This defines which switch letters take arguments.  On FreeBSD, most of    the normal cases (defined in gcc.c) apply, and we also have -h* and    -z* options (for the linker) (coming from SVR4).    We also have -R (alias --rpath), no -z, --soname (-h), --assert etc.  */
end_comment

begin_define
define|#
directive|define
name|FBSD_SWITCH_TAKES_ARG
parameter_list|(
name|CHAR
parameter_list|)
define|\
value|(DEFAULT_SWITCH_TAKES_ARG (CHAR)					\     || (CHAR) == 'h'							\     || (CHAR) == 'z'
comment|/* ignored by ld */
value|\     || (CHAR) == 'R')
end_define

begin_undef
undef|#
directive|undef
name|SWITCH_TAKES_ARG
end_undef

begin_define
define|#
directive|define
name|SWITCH_TAKES_ARG
parameter_list|(
name|CHAR
parameter_list|)
value|(FBSD_SWITCH_TAKES_ARG(CHAR))
end_define

begin_comment
comment|/* This defines which multi-letter switches take arguments.  */
end_comment

begin_define
define|#
directive|define
name|FBSD_WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
define|\
value|(DEFAULT_WORD_SWITCH_TAKES_ARG (STR)					\    || !strcmp ((STR), "rpath") || !strcmp ((STR), "rpath-link")		\    || !strcmp ((STR), "soname") || !strcmp ((STR), "defsym") 		\    || !strcmp ((STR), "assert") || !strcmp ((STR), "dynamic-linker"))
end_define

begin_undef
undef|#
directive|undef
name|WORD_SWITCH_TAKES_ARG
end_undef

begin_define
define|#
directive|define
name|WORD_SWITCH_TAKES_ARG
parameter_list|(
name|STR
parameter_list|)
value|(FBSD_WORD_SWITCH_TAKES_ARG(STR))
end_define

begin_comment
comment|/* Place spaces around this string.  We depend on string splicing to produce    the final CPP_PREDEFINES value.  */
end_comment

begin_define
define|#
directive|define
name|FBSD_CPP_PREDEFINES
define|\
value|" -D__FreeBSD__=4 -D__FreeBSD_cc_version=440000 -Dunix -Asystem(unix) -Asystem(FreeBSD) "
end_define

begin_define
define|#
directive|define
name|FBSD_CPP_SPEC
value|"							\   %(cpp_cpu)								\   %{!maout: -D__ELF__}							\   %{munderscores: -D__UNDERSCORES__}					\   %{maout: %{!mno-underscores: -D__UNDERSCORES__}}			\   %{fPIC:-D__PIC__ -D__pic__} %{fpic:-D__PIC__ -D__pic__}		\   %{posix:-D_POSIX_SOURCE}"
end_define

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|FBSD_CPP_SPEC
end_define

begin_comment
comment|/* Provide a LIB_SPEC appropriate for FreeBSD.  Before    __FreeBSD_version 500016, select the appropriate libc, depending on    whether we're doing profiling or need threads support.  (similar to    the default, except no -lg, and no -p).  At __FreeBSD_version    500016 and later, when threads support is requested include both    -lc and -lc_r instead of only -lc_r.  */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|500016
end_if

begin_define
define|#
directive|define
name|LIB_SPEC
value|"							\    %{!shared:								\      %{!pg: %{pthread:-lc_r} -lc}					\      %{pg:  %{pthread:-lc_r_p} -lc_p}					\    }"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LIB_SPEC
value|"							\   %{!shared:								\     %{!pg:								\       %{!pthread:-lc}							\       %{pthread:-lc_r}}							\     %{pg:								\       %{!pthread:-lc_p}							\       %{pthread:-lc_r_p}}						\   }"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/************************[  Target stuff  ]***********************************/
end_comment

begin_comment
comment|/* All FreeBSD Architectures support the ELF object file format.  */
end_comment

begin_undef
undef|#
directive|undef
name|OBJECT_FORMAT_ELF
end_undef

begin_define
define|#
directive|define
name|OBJECT_FORMAT_ELF
end_define

begin_comment
comment|/* Don't assume anything about the header files.  */
end_comment

begin_undef
undef|#
directive|undef
name|NO_IMPLICIT_EXTERN_C
end_undef

begin_define
define|#
directive|define
name|NO_IMPLICIT_EXTERN_C
end_define

begin_comment
comment|/* Implicit library calls should use memcpy, not bcopy, etc.  */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_MEM_FUNCTIONS
end_undef

begin_define
define|#
directive|define
name|TARGET_MEM_FUNCTIONS
end_define

begin_comment
comment|/* Allow #sccs in preprocessor.  */
end_comment

begin_undef
undef|#
directive|undef
name|SCCS_DIRECTIVE
end_undef

begin_define
define|#
directive|define
name|SCCS_DIRECTIVE
end_define

begin_undef
undef|#
directive|undef
name|HAVE_ATEXIT
end_undef

begin_define
define|#
directive|define
name|HAVE_ATEXIT
end_define

begin_comment
comment|/* Code generation parameters.  */
end_comment

begin_comment
comment|/* Don't default to pcc-struct-return, because gcc is the only compiler, and    we want to retain compatibility with older gcc versions    (even though the SVR4 ABI for the i386 says that records and unions are    returned in memory).  */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_PCC_STRUCT_RETURN
end_undef

begin_define
define|#
directive|define
name|DEFAULT_PCC_STRUCT_RETURN
value|0
end_define

begin_comment
comment|/* Writing `int' for a bitfield forces int alignment for the structure.  */
end_comment

begin_comment
comment|/* XXX: ok for Alpha??  */
end_comment

begin_undef
undef|#
directive|undef
name|PCC_BITFIELD_TYPE_MATTERS
end_undef

begin_define
define|#
directive|define
name|PCC_BITFIELD_TYPE_MATTERS
value|1
end_define

begin_comment
comment|/* Use periods rather than dollar signs in special g++ assembler names.    This ensures the configuration knows our system correctly so we can link    with libraries compiled with the native cc.  */
end_comment

begin_undef
undef|#
directive|undef
name|NO_DOLLAR_IN_LABEL
end_undef

begin_comment
comment|/* The prefix to add to user-visible assembler symbols.    For System V Release 4& ELF the convention is *not* to prepend a leading    underscore onto user-level symbol names.  */
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
comment|/* Handle #pragma weak and #pragma pack.  */
end_comment

begin_undef
undef|#
directive|undef
name|HANDLE_SYSV_PRAGMA
end_undef

begin_define
define|#
directive|define
name|HANDLE_SYSV_PRAGMA
end_define

begin_comment
comment|/* While FreeBSD ELF no longer uses our home-grown crtbegin.o/crtend.o and thus    could switch to the DWARF2 unwinding mechanisms.  I don't want to make the    switch mid-branch.  So continue to use sjlj-exceptions.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|WANT_DWARF2_UNWIND
end_ifdef

begin_comment
comment|/* FreeBSD ELF will use DWARF2 unwinding in 5.0+, as some psABI requires it.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* Maintain compatibility with the FreeBSD {3,4}.x C++ ABI.  */
end_comment

begin_define
define|#
directive|define
name|DWARF2_UNWIND_INFO
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Do not use ``thunks'' to implement C++ vtables.  This method still has    fatal bugs.  Also, GCC 3.0 will have a new C++ ABI that may not even    support `thunks'.  */
end_comment

begin_undef
undef|#
directive|undef
name|DEFAULT_VTABLE_THUNKS
end_undef

begin_comment
comment|/************************[  Assembler stuff  ]********************************/
end_comment

begin_comment
comment|/* Override the default comment-starter of "/".  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_COMMENT_START
end_undef

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|"#"
end_define

begin_comment
comment|/* Attach a special .ident directive to the end of the file to identify    the version of GCC which compiled this code.  The format of the .ident    string is patterned after the ones produced by native SVR4 C compilers.  */
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
value|"\t.ident\t"
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
value|fprintf ((FILE), "%s\"%s\"\n", IDENT_ASM_OP, (NAME));
end_define

begin_comment
comment|/* Identify the front-end which produced this file.  To keep symbol    space down, and not confuse kdb, only do this if the language is    not C. (svr4.h defines ASM_IDENTIFY_GCC but neglects this) */
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
value|{									\     if (strcmp (lang_identify (), "c") != 0)				\         output_lang_identify (FILE);					\   }
end_define

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
value|do {				 					\     if (!flag_no_ident)							\       fprintf ((FILE), "%s\"GCC: (GNU) %s %s\"\n",			\ 		IDENT_ASM_OP, lang_identify(), version_string);		\   } while (0)
end_define

begin_comment
comment|/* This is the pseudo-op used to generate a contiguous sequence of byte    values from a double-quoted string WITHOUT HAVING A TERMINATING NUL    AUTOMATICALLY APPENDED.  This is the same for most SVR4 assemblers.  */
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

begin_undef
undef|#
directive|undef
name|ASM_BYTE_OP
end_undef

begin_define
define|#
directive|define
name|ASM_BYTE_OP
value|"\t.byte\t"
end_define

begin_comment
comment|/* This is how to allocate empty space in some section.  The .zero    pseudo-op is used for this on most ELF assemblers.  */
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

begin_comment
comment|/* A table of bytes codes used by the ASM_OUTPUT_ASCII and    ASM_OUTPUT_LIMITED_STRING macros.  Each byte in the table    corresponds to a particular byte value [0..255].  For any    given byte value, if the value in the corresponding table    position is zero, the given character can be output directly.    If the table value is 1, the byte must be output as a \ooo    octal escape.  If the tables value is anything else, then the    byte value should be output as a \ followed by the value    in the table.  Note that we can use standard UN*X escape    sequences for many control characters, but we don't use    \a to represent BEL because some SVR4 assemblers (e.g. on    the i386) don't know about that.  Also, we don't use \v    since some versions of gas, such as 2.2 did not accept it.  */
end_comment

begin_define
define|#
directive|define
name|ESCAPES
define|\
value|"\1\1\1\1\1\1\1\1btn\1fr\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\ \0\0\"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\ \0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\\\0\0\0\ \0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\ \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\ \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\ \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\ \1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1"
end_define

begin_comment
comment|/* Some SVR4 assemblers have a limit on the number of characters which    can appear in the operand of a .string directive.  If your assembler    has such a limitation, you should define STRING_LIMIT to reflect that    limit.  Note that at least some SVR4 assemblers have a limit on the    actual number of bytes in the double-quoted string, and that they    count each character in an escape sequence as one byte.  Thus, an    escape sequence like \377 would count as four bytes.     If your target assembler doesn't support the .string directive, you    should define this to zero. */
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
comment|/* Output the label which precedes a jumptable.  Note that for all svr4/ELF    systems where we actually generate jumptables (which is to say every    SVR4 target except i386, where we use casesi instead) we put the jump-    tables into the .rodata section and since other stuff could have been    put into the .rodata section prior to any given jumptable, we have to    make sure that the location counter for the .rodata section gets pro-    perly re-aligned prior to the actual beginning of the jump table.  */
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

begin_comment
comment|/* This says how to output assembler code to declare an    uninitialized external linkage data object.  Under SVR4/ELF,    the linker seems to want the alignment of data objects    to depend on their types.  We do exactly that here.  */
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

begin_comment
comment|/* This says how to output assembler code to declare an    uninitialized internal linkage data object.  Under SVR4/ELF,    the linker seems to want the alignment of data objects    to depend on their types.  We do exactly that here.  */
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
value|"\t.local\t"
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_BEFORE_CASE_LABEL
end_undef

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
comment|/* The standard SVR4/ELF assembler seems to require that certain builtin    library routines (e.g. .udiv) be explicitly declared as .globl    in each assembly file where they are referenced.  */
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
comment|/* Support const sections and the ctors and dtors sections for g++.    Note that there appears to be two different ways to support const    sections at the moment.  You can either #define the symbol    READONLY_DATA_SECTION (giving it some code which switches to the    readonly data section) or else you can #define the symbols    EXTRA_SECTIONS, EXTRA_SECTION_FUNCTIONS, SELECT_SECTION, and    SELECT_RTX_SECTION.  We do both here just to be on the safe side.      FreeBSD conditionalizes the use of ".section rodata" depending on    ELF mode - otherwise .text.  */
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
value|TARGET_ELF
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
value|"\t.section\t.ctors,\"aw\""
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
value|"\t.section\t.dtors,\"aw\""
end_define

begin_comment
comment|/* On SVR4, we *do* have support for the .init and .fini sections, and we    can put stuff in there to be executed before and after `main'.  We let    crtstuff.c and other files know this by defining the following symbols.    The definitions say how to change sections to the .init and .fini    sections.  This is the same for all known SVR4 assemblers.  */
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
value|void									\   const_section ()							\   {									\     if (!USE_CONST_SECTION)						\       text_section();							\     else if (in_section != in_const)					\       {									\ 	fprintf (asm_out_file, "%s\n", CONST_SECTION_ASM_OP);		\ 	in_section = in_const;						\       }									\   }
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
value|void									\   ctors_section ()							\   {									\     if (in_section != in_ctors)						\       {									\ 	fprintf (asm_out_file, "%s\n", CTORS_SECTION_ASM_OP);		\ 	in_section = in_ctors;						\       }									\   }
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
value|void									\   dtors_section ()							\   {									\     if (in_section != in_dtors)						\       {									\  	fprintf (asm_out_file, "%s\n", DTORS_SECTION_ASM_OP);		\ 	in_section = in_dtors;						\       }									\   }
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
comment|/* Define the strings used for the special svr4/ELF .type and .size    directives.  These strings generally do not vary from one svr4/ELF    system to another.  */
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
value|do {									\     fputs ("\t.globl\t", (FILE)); assemble_name ((FILE), (NAME));	\     fputc ('\n', (FILE));						\     fputs ("\t.weak\t", (FILE)); assemble_name ((FILE), (NAME));	\     fputc ('\n', (FILE));						\   } while (0)
end_define

begin_comment
comment|/* The following macro defines the [default] format used with ELF to output    the second operand of the .type assembler directive.  */
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
comment|/* Write the extra assembler code needed to declare a function's result.    Most svr4/ELF assemblers don't require any special declaration of the    result value.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_DECLARE_RESULT
end_undef

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

begin_comment
comment|/* These macros generate the special .type and .size directives which    are used to set the corresponding fields of the linker symbol table    entries in an ELF object file under SVR4/ELF.  These macros also output    the starting labels for the relevant functions/objects.  */
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
value|do {									\     fprintf (FILE, "%s ", TYPE_ASM_OP);					\     assemble_name (FILE, NAME);						\     putc (',', FILE);							\     fprintf (FILE, TYPE_OPERAND_FMT, "object");				\     putc ('\n', FILE);							\     size_directive_output = 0;						\     if (!flag_inhibit_size_directive&& DECL_SIZE (DECL))		\       {									\ 	size_directive_output = 1;					\ 	fprintf (FILE, "%s ", SIZE_ASM_OP);				\ 	assemble_name (FILE, NAME);					\ 	putc (',', FILE);						\ 	fprintf (FILE, HOST_WIDE_INT_PRINT_DEC,				\ 		 int_size_in_bytes (TREE_TYPE (DECL)));			\ 	fputc ('\n', FILE);						\       }									\     ASM_OUTPUT_LABEL(FILE, NAME);					\   } while (0)
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
value|do {									\     char *name = XSTR (XEXP (DECL_RTL (DECL), 0), 0);			\     if (!flag_inhibit_size_directive&& DECL_SIZE (DECL)		\&& ! AT_END&& TOP_LEVEL					\&& DECL_INITIAL (DECL) == error_mark_node			\&& !size_directive_output)					\       {									\ 	size_directive_output = 1;					\ 	fprintf (FILE, "%s ", SIZE_ASM_OP);				\ 	assemble_name (FILE, name);					\ 	putc (',', FILE);						\ 	fprintf (FILE, HOST_WIDE_INT_PRINT_DEC,				\ 		int_size_in_bytes (TREE_TYPE (DECL))); 			\ 	fputc ('\n', FILE);						\       }									\   } while (0)
end_define

begin_comment
comment|/************************[  Debugger stuff  ]*********************************/
end_comment

begin_comment
comment|/* All ELF targets can support DWARF-2.  */
end_comment

begin_undef
undef|#
directive|undef
name|DWARF2_DEBUGGING_INFO
end_undef

begin_define
define|#
directive|define
name|DWARF2_DEBUGGING_INFO
end_define

begin_comment
comment|/* This is BSD, so we want the DBX format.  */
end_comment

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_comment
comment|/* This is BSD, so use stabs instead of DWARF debug format.  */
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
value|DBX_DEBUG
end_define

begin_comment
comment|/* But allow STABS to be supported as well.    	Note that we want to override some definition settings done for some    	architecture's native OS's tools that don't apply to us.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_IDENTIFY_GCC
end_undef

begin_undef
undef|#
directive|undef
name|ASM_IDENTIFY_LANGUAGE
end_undef

end_unit

