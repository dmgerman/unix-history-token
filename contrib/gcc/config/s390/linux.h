begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for Linux for S/390.    Copyright (C) 1999, 2000, 2001, 2002 Free Software Foundation, Inc.    Contributed by Hartmut Penner (hpenner@de.ibm.com) and                   Ulrich Weigand (uweigand@de.ibm.com).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_H
end_ifndef

begin_define
define|#
directive|define
name|_LINUX_H
end_define

begin_comment
comment|/* Target specific version string.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEFAULT_TARGET_64BIT
end_ifdef

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (Linux for zSeries)");
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (Linux for S/390)");
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Target specific type definitions.  */
end_comment

begin_comment
comment|/* ??? Do we really want long as size_t on 31-bit?  */
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
value|(TARGET_64BIT ? "long unsigned int" : "long unsigned int")
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
value|(TARGET_64BIT ? "long int" : "int")
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

begin_comment
comment|/* Target specific preprocessor settings.  */
end_comment

begin_define
define|#
directive|define
name|NO_BUILTIN_SIZE_TYPE
end_define

begin_define
define|#
directive|define
name|NO_BUILTIN_PTRDIFF_TYPE
end_define

begin_define
define|#
directive|define
name|CPP_PREDEFINES
define|\
value|"-Dunix -Asystem(unix) -D__gnu_linux__ -Dlinux -Asystem(linux) -D__ELF__ \    -Acpu(s390) -Amachine(s390) -D__s390__"
end_define

begin_define
define|#
directive|define
name|CPP_ARCH31_SPEC
define|\
value|"-D__SIZE_TYPE__=long\\ unsigned\\ int -D__PTRDIFF_TYPE__=int"
end_define

begin_define
define|#
directive|define
name|CPP_ARCH64_SPEC
define|\
value|"-D__SIZE_TYPE__=long\\ unsigned\\ int -D__PTRDIFF_TYPE__=long\\ int \    -D__s390x__ -D__LONG_MAX__=9223372036854775807L"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEFAULT_TARGET_64BIT
end_ifdef

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{m31:%(cpp_arch31)} %{!m31:%(cpp_arch64)}"
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|CPP_SPEC
end_undef

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{m64:%(cpp_arch64)} %{!m64:%(cpp_arch31)}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Target specific compiler settings.  */
end_comment

begin_comment
comment|/* ??? -fcaller-saves sometimes doesn't work.  Fix this! */
end_comment

begin_undef
undef|#
directive|undef
name|CC1_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1_SPEC
value|"-fno-caller-saves"
end_define

begin_undef
undef|#
directive|undef
name|CC1PLUS_SPEC
end_undef

begin_define
define|#
directive|define
name|CC1PLUS_SPEC
value|"-fno-caller-saves"
end_define

begin_comment
comment|/* Target specific assembler settings.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DEFAULT_TARGET_64BIT
end_ifdef

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{m31:-m31 -Aesa}"
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{m64:-m64 -Aesame}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Target specific linker settings.  */
end_comment

begin_define
define|#
directive|define
name|LINK_ARCH31_SPEC
define|\
value|"-m elf_s390 \    %{shared:-shared} \    %{!shared: \       %{static:-static} \       %{!static: \ 	%{rdynamic:-export-dynamic} \ 	%{!dynamic-linker:-dynamic-linker /lib/ld.so.1}}}"
end_define

begin_define
define|#
directive|define
name|LINK_ARCH64_SPEC
define|\
value|"-m elf64_s390 \    %{shared:-shared} \    %{!shared: \       %{static:-static} \       %{!static: \ 	%{rdynamic:-export-dynamic} \ 	%{!dynamic-linker:-dynamic-linker /lib/ld64.so.1}}}"
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|DEFAULT_TARGET_64BIT
end_ifdef

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{m31:%(link_arch31)} %{!m31:%(link_arch64)}"
end_define

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{m64:%(link_arch64)} %{!m64:%(link_arch31)}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This macro defines names of additional specifications to put in the specs    that can be used in various specifications like CC1_SPEC.  Its definition    is an initializer with a subgrouping for each command option.  */
end_comment

begin_define
define|#
directive|define
name|EXTRA_SPECS
define|\
value|{ "cpp_arch31",	CPP_ARCH31_SPEC },	\   { "cpp_arch64",	CPP_ARCH64_SPEC },	\   { "link_arch31",	LINK_ARCH31_SPEC },	\   { "link_arch64",	LINK_ARCH64_SPEC },
end_define

begin_comment
unit|\
comment|/* Character to start a comment.  */
end_comment

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|"#"
end_define

begin_comment
comment|/* Assembler pseudos to introduce constants of various size.  */
end_comment

begin_define
define|#
directive|define
name|ASM_DOUBLE
value|"\t.double"
end_define

begin_comment
comment|/* The LOCAL_LABEL_PREFIX variable is used by dbxelf.h.  */
end_comment

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|"."
end_define

begin_comment
comment|/* Prefix for internally generated assembler labels.  */
end_comment

begin_define
define|#
directive|define
name|LPREFIX
value|".L"
end_define

begin_comment
comment|/* This is how to output the definition of a user-level label named NAME,    such as the label on a static function or variable NAME.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_LABEL
end_undef

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
value|(assemble_name (FILE, NAME), fputs (":\n", FILE))
end_define

begin_comment
comment|/* Store in OUTPUT a string (made with alloca) containing    an assembler-name for a local static variable named NAME.    LABELNO is an integer which is different for each call.  */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_FORMAT_PRIVATE_NAME
end_undef

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
value|( (OUTPUT) = (char *) alloca (strlen ((NAME)) + 10),    \   sprintf ((OUTPUT), "%s.%d", (NAME), (LABELNO)))
end_define

begin_comment
comment|/* internal macro to output long */
end_comment

begin_define
define|#
directive|define
name|_ASM_OUTPUT_LONG
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf (FILE, "\t.long\t0x%lX\n", VALUE);
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is absolute.  */
end_comment

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
value|fprintf (FILE, "%s%s%d\n", integer_asm_op (UNITS_PER_WORD, TRUE), \ 	   LPREFIX, VALUE)
end_define

begin_comment
comment|/* This is how to output an element of a case-vector that is relative.  */
end_comment

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
value|fprintf (FILE, "%s%s%d-%s%d\n", integer_asm_op (UNITS_PER_WORD, TRUE), \ 	   LPREFIX, VALUE, LPREFIX, REL)
end_define

begin_comment
comment|/* This is how to output an assembler line    that says to advance the location counter    to a multiple of 2**LOG bytes.  */
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
value|if ((LOG)!=0) fprintf ((FILE), "\t.align\t%d\n", 1<<(LOG))
end_define

begin_comment
comment|/* This is how to output an assembler line    that says to advance the location counter by SIZE bytes.  */
end_comment

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
value|fprintf ((FILE), "\t.set\t.,.+%u\n", (SIZE))
end_define

begin_comment
comment|/* This is how to output assembler code to declare an    uninitialized external linkage data object.  */
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
value|asm_output_aligned_bss (FILE, DECL, NAME, SIZE, ALIGN)
end_define

begin_comment
comment|/* Output before read-only data.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|".text"
end_define

begin_comment
comment|/* Output before writable (initialized) data.  */
end_comment

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|".data"
end_define

begin_comment
comment|/* Output before writable (uninitialized) data.  */
end_comment

begin_define
define|#
directive|define
name|BSS_SECTION_ASM_OP
value|".bss"
end_define

begin_comment
comment|/* This is how to output a command to make the user-level label named NAME    defined for reference from other files.  */
end_comment

begin_define
define|#
directive|define
name|ASM_GLOBALIZE_LABEL
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|(fputs (".globl ", FILE), assemble_name (FILE, NAME), fputs ("\n", FILE))
end_define

begin_comment
comment|/* Select section for constant in constant pool.     We are in the right section.     undef for 64 bit mode (linux64.h).  */
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
name|X
parameter_list|,
name|ALIGN
parameter_list|)
end_define

begin_escape
end_escape

begin_comment
comment|/* Output code to add DELTA to the first argument, and then jump to FUNCTION.    Used for C++ multiple inheritance.  */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_MI_THUNK
parameter_list|(
name|FILE
parameter_list|,
name|THUNK_FNDECL
parameter_list|,
name|DELTA
parameter_list|,
name|FUNCTION
parameter_list|)
define|\
value|do {                                                                          \   if (TARGET_64BIT)                                                           \     {                                                                         \       if (flag_pic)                                                           \         {                                                                     \           fprintf (FILE, "\tlarl  1,0f\n");                                   \           fprintf (FILE, "\tagf   %d,0(1)\n",                                 \                    aggregate_value_p (TREE_TYPE                               \                                       (TREE_TYPE (FUNCTION))) ? 3 :2 );       \           fprintf (FILE, "\tlarl  1,");                                       \           assemble_name (FILE, XSTR (XEXP (DECL_RTL (FUNCTION), 0), 0));      \           fprintf (FILE, "@GOTENT\n");                                        \           fprintf (FILE, "\tlg    1,0(1)\n");                                 \           fprintf (FILE, "\tbr    1\n");                                      \           fprintf (FILE, "0:\t.long  ");	                              \           fprintf (FILE, HOST_WIDE_INT_PRINT_DEC, (DELTA));                   \           fprintf (FILE, "\n");			                              \         }                                                                     \       else                                                                    \         {                                                                     \           fprintf (FILE, "\tlarl  1,0f\n");                                   \           fprintf (FILE, "\tagf   %d,0(1)\n",                                 \           aggregate_value_p (TREE_TYPE                                        \                              (TREE_TYPE (FUNCTION))) ? 3 :2 );                \           fprintf (FILE, "\tjg  ");                                           \           assemble_name (FILE, XSTR (XEXP (DECL_RTL (FUNCTION), 0), 0));      \           fprintf (FILE, "\n");                                               \           fprintf (FILE, "0:\t.long  ");		                      \           fprintf (FILE, HOST_WIDE_INT_PRINT_DEC, (DELTA));                   \           fprintf (FILE, "\n");			                              \         }                                                                     \     }                                                                         \   else                                                                        \     {                                                                         \       if (flag_pic)                                                           \         {                                                                     \           fprintf (FILE, "\tbras  1,0f\n");                                   \           fprintf (FILE, "\t.long _GLOBAL_OFFSET_TABLE_-.\n");                \           fprintf (FILE, "\t.long  ");                                        \           assemble_name (FILE, XSTR (XEXP (DECL_RTL (FUNCTION), 0), 0));      \           fprintf (FILE, "@GOT\n");                                           \           fprintf (FILE, "\t.long  ");		                              \           fprintf (FILE, HOST_WIDE_INT_PRINT_DEC, (DELTA));                   \           fprintf (FILE, "\n");			                              \           fprintf (FILE, "0:\tal  %d,8(1)\n",                                 \                    aggregate_value_p (TREE_TYPE                               \                                       (TREE_TYPE (FUNCTION))) ? 3 : 2 );      \           fprintf (FILE, "\tl     0,4(1)\n");                                 \           fprintf (FILE, "\tal    1,0(1)\n");                                 \           fprintf (FILE, "\talr   1,0\n");                                    \           fprintf (FILE, "\tl     1,0(1)\n");                                 \           fprintf (FILE, "\tbr    1\n");                                      \         } else {                                                              \           fprintf (FILE, "\tbras  1,0f\n");                                   \           fprintf (FILE, "\t.long  ");                                        \           assemble_name (FILE, XSTR (XEXP (DECL_RTL (FUNCTION), 0), 0));      \           fprintf (FILE, "-.\n");                                             \           fprintf (FILE, "\t.long  ");		                              \           fprintf (FILE, HOST_WIDE_INT_PRINT_DEC, (DELTA));                   \           fprintf (FILE, "\n");			                              \           fprintf (FILE, "0:\tal  %d,4(1)\n",                                 \                    aggregate_value_p (TREE_TYPE                               \                                       (TREE_TYPE (FUNCTION))) ? 3 : 2 );      \           fprintf (FILE, "\tal    1,0(1)\n");                                 \           fprintf (FILE, "\tbr    1\n");                                      \        }                                                                      \     }                                                                         \ } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

