begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions of target machine for GNU compiler, for Advanced RISC Machines    ARM compilation, AOF Assembler.    Copyright (C) 1995, 1996, 1997, 2000 Free Software Foundation, Inc.    Contributed by Richard Earnshaw (rearnsha@armltd.co.uk)  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_escape
end_escape

begin_define
define|#
directive|define
name|AOF_ASSEMBLER
end_define

begin_define
define|#
directive|define
name|LINK_LIBGCC_SPECIAL
value|1
end_define

begin_define
define|#
directive|define
name|LINK_SPEC
value|"%{aof} %{bin} %{aif} %{ihf} %{shl,*} %{reent*} %{split} \ 		   %{ov*,*} %{reloc*} -nodebug"
end_define

begin_define
define|#
directive|define
name|STARTFILE_SPEC
value|"crtbegin.o%s"
end_define

begin_define
define|#
directive|define
name|ENDFILE_SPEC
value|"crtend.o%s"
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ASM_SPEC
end_ifndef

begin_define
define|#
directive|define
name|ASM_SPEC
value|"%{g -g} -arch 4 \ -apcs 3%{mapcs-32:/32bit}%{mapcs-26:/26bit}%{!mapcs-26:%{!macps-32:/26bit}}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|LIB_SPEC
end_ifndef

begin_define
define|#
directive|define
name|LIB_SPEC
value|"%{Eb: armlib_h.32b%s}%{!Eb: armlib_h.32l%s}"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LIBGCC_SPEC
value|"libgcc.a%s"
end_define

begin_comment
comment|/* Dividing the Output into Sections (Text, Data, ...) */
end_comment

begin_comment
comment|/* AOF Assembler syntax is a nightmare when it comes to areas, since once    we change from one area to another, we can't go back again.  Instead,    we must create a new area with the same attributes and add the new output    to that.  Unfortunately, there is nothing we can do here to guarantee that    two areas with the same attributes will be linked adjacently in the    resulting executable, so we have to be careful not to do pc-relative     addressing across such boundaries.  */
end_comment

begin_define
define|#
directive|define
name|TEXT_SECTION_ASM_OP
value|aof_text_section ()
end_define

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
value|text_section ();
end_define

begin_define
define|#
directive|define
name|DATA_SECTION_ASM_OP
value|aof_data_section ()
end_define

begin_define
define|#
directive|define
name|EXTRA_SECTIONS
value|in_zero_init, in_common
end_define

begin_define
define|#
directive|define
name|EXTRA_SECTION_FUNCTIONS
define|\
value|ZERO_INIT_SECTION		\ COMMON_SECTION
end_define

begin_define
define|#
directive|define
name|ZERO_INIT_SECTION
define|\
value|void								\ zero_init_section ()						\ {								\   static int zero_init_count = 1;				\   if (in_section != in_zero_init)				\     {								\       fprintf (asm_out_file, "\tAREA |C$$zidata%d|,NOINIT\n",	\ 	       zero_init_count++);				\       in_section = in_zero_init;				\     }								\ }
end_define

begin_comment
comment|/* Used by ASM_OUTPUT_COMMON (below) to tell varasm.c that we've    changed areas.  */
end_comment

begin_define
define|#
directive|define
name|COMMON_SECTION
define|\
value|void								\ common_section ()						\ {								\   if (in_section != in_common)					\     {								\       in_section = in_common;					\     }								\ }
end_define

begin_define
define|#
directive|define
name|CTOR_LIST_BEGIN
define|\
value|asm (CTORS_SECTION_ASM_OP);				\ extern func_ptr __CTOR_END__[1];			\ func_ptr __CTOR_LIST__[1] = {__CTOR_END__};
end_define

begin_define
define|#
directive|define
name|CTOR_LIST_END
define|\
value|asm (CTORS_SECTION_ASM_OP);				\ func_ptr __CTOR_END__[1] = { (func_ptr) 0 };
end_define

begin_define
define|#
directive|define
name|DO_GLOBAL_CTORS_BODY
define|\
value|do {					\   func_ptr *ptr = __CTOR_LIST__ + 1;	\   while (*ptr)				\     (*ptr++) ();			\ } while (0)
end_define

begin_define
define|#
directive|define
name|DTOR_LIST_BEGIN
define|\
value|asm (DTORS_SECTION_ASM_OP);				\ extern func_ptr __DTOR_END__[1];			\ func_ptr __DTOR_LIST__[1] = {__DTOR_END__};
end_define

begin_define
define|#
directive|define
name|DTOR_LIST_END
define|\
value|asm (DTORS_SECTION_ASM_OP);				\ func_ptr __DTOR_END__[1] = { (func_ptr) 0 };
end_define

begin_define
define|#
directive|define
name|DO_GLOBAL_DTORS_BODY
define|\
value|do {					\   func_ptr *ptr = __DTOR_LIST__ + 1;	\   while (*ptr)				\     (*ptr++) ();			\ } while (0)
end_define

begin_define
define|#
directive|define
name|JUMP_TABLES_IN_TEXT_SECTION
value|1
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|ARM_OS_NAME
end_ifndef

begin_define
define|#
directive|define
name|ARM_OS_NAME
value|"(generic)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* For the AOF linker, we need to reference __main to force the standard    library to get linked in. */
end_comment

begin_define
define|#
directive|define
name|ASM_FILE_START
parameter_list|(
name|STREAM
parameter_list|)
define|\
value|{								\   fprintf ((STREAM), "%s Generated by gcc %s for ARM/%s\n", 	\ 	   ASM_COMMENT_START, version_string, ARM_OS_NAME);	\   fprintf ((STREAM), "__r0\tRN\t0\n");				\   fprintf ((STREAM), "__a1\tRN\t0\n");				\   fprintf ((STREAM), "__a2\tRN\t1\n");				\   fprintf ((STREAM), "__a3\tRN\t2\n");				\   fprintf ((STREAM), "__a4\tRN\t3\n");				\   fprintf ((STREAM), "__v1\tRN\t4\n");				\   fprintf ((STREAM), "__v2\tRN\t5\n");				\   fprintf ((STREAM), "__v3\tRN\t6\n");				\   fprintf ((STREAM), "__v4\tRN\t7\n");				\   fprintf ((STREAM), "__v5\tRN\t8\n");				\   fprintf ((STREAM), "__v6\tRN\t9\n");				\   fprintf ((STREAM), "__sl\tRN\t10\n");				\   fprintf ((STREAM), "__fp\tRN\t11\n");				\   fprintf ((STREAM), "__ip\tRN\t12\n");				\   fprintf ((STREAM), "__sp\tRN\t13\n");				\   fprintf ((STREAM), "__lr\tRN\t14\n");				\   fprintf ((STREAM), "__pc\tRN\t15\n");				\   fprintf ((STREAM), "__f0\tFN\t0\n");				\   fprintf ((STREAM), "__f1\tFN\t1\n");				\   fprintf ((STREAM), "__f2\tFN\t2\n");				\   fprintf ((STREAM), "__f3\tFN\t3\n");				\   fprintf ((STREAM), "__f4\tFN\t4\n");				\   fprintf ((STREAM), "__f5\tFN\t5\n");				\   fprintf ((STREAM), "__f6\tFN\t6\n");				\   fprintf ((STREAM), "__f7\tFN\t7\n");				\   text_section ();						\ }
end_define

begin_comment
comment|/* Some systems use __main in a way incompatible with its use in gcc, in these    cases use the macros NAME__MAIN to give a quoted symbol and SYMBOL__MAIN to    give the same symbol without quotes for an alternative entry point.  You    must define both, or neither. */
end_comment

begin_define
define|#
directive|define
name|NAME__MAIN
value|"__gccmain"
end_define

begin_define
define|#
directive|define
name|SYMBOL__MAIN
value|__gccmain
end_define

begin_define
define|#
directive|define
name|ASM_FILE_END
parameter_list|(
name|STREAM
parameter_list|)
define|\
value|do					\ {					\   if (flag_pic)				\     aof_dump_pic_table (STREAM);	\   aof_dump_imports (STREAM);		\   fputs ("\tEND\n", (STREAM));		\ } while (0);
end_define

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|";"
end_define

begin_define
define|#
directive|define
name|ASM_APP_ON
value|""
end_define

begin_define
define|#
directive|define
name|ASM_APP_OFF
value|""
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_ASCII
parameter_list|(
name|STREAM
parameter_list|,
name|PTR
parameter_list|,
name|LEN
parameter_list|)
define|\
value|{							\   int i;						\   const char *ptr = (PTR);				\   fprintf ((STREAM), "\tDCB");				\   for (i = 0; i< (long)(LEN); i++)			\     fprintf ((STREAM), "&%02x%s", 			\ 	     (unsigned ) *(ptr++),			\ 	     (i + 1< (long)(LEN)				\ 	      ? ((i& 3) == 3 ? "\n\tDCB" : ",")	\ 	      : "\n"));					\ }
end_define

begin_define
define|#
directive|define
name|IS_ASM_LOGICAL_LINE_SEPARATOR
parameter_list|(
name|C
parameter_list|)
value|((C) == '\n')
end_define

begin_comment
comment|/* Output of Uninitialized Variables */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_COMMON
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|(common_section (),						\    fprintf ((STREAM), "\tAREA "),				\    assemble_name ((STREAM), (NAME)),				\    fprintf ((STREAM), ", DATA, COMMON\n\t%% %d\t%s size=%d\n",	\ 	    (ROUNDED), ASM_COMMENT_START, SIZE))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_LOCAL
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|SIZE
parameter_list|,
name|ROUNDED
parameter_list|)
define|\
value|(zero_init_section (),				\     assemble_name ((STREAM), (NAME)),			\     fprintf ((STREAM), "\n"),				\     fprintf ((STREAM), "\t%% %d\t%s size=%d\n",		\ 	     (ROUNDED), ASM_COMMENT_START, SIZE))
end_define

begin_comment
comment|/* Output and Generation of Labels */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|arm_main_function
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|ASM_GLOBALIZE_LABEL
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {							\   fprintf ((STREAM), "\tEXPORT\t");			\   assemble_name ((STREAM), (NAME));			\   fputc ('\n', (STREAM));				\   if ((NAME)[0] == 'm'&& ! strcmp ((NAME), "main"))	\     arm_main_function = 1;				\ } while (0)
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABEL
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|do {					\   assemble_name (STREAM,NAME);		\   fputs ("\n", STREAM);			\ } while (0)
end_define

begin_define
define|#
directive|define
name|ASM_DECLARE_FUNCTION_NAME
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|{						\   if (TARGET_POKE_FUNCTION_NAME)		\     arm_poke_function_name ((STREAM), (NAME));	\   ASM_OUTPUT_LABEL (STREAM, NAME);		\   if (! TREE_PUBLIC (DECL))			\     {						\       fputs ("\tKEEP ", STREAM);		\       ASM_OUTPUT_LABEL (STREAM, NAME);		\     }						\   aof_delete_import ((NAME));			\ }
end_define

begin_define
define|#
directive|define
name|ASM_DECLARE_OBJECT_NAME
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|,
name|DECL
parameter_list|)
define|\
value|{						\   ASM_OUTPUT_LABEL (STREAM, NAME);		\   if (! TREE_PUBLIC (DECL))			\     {						\       fputs ("\tKEEP ", STREAM);		\       ASM_OUTPUT_LABEL (STREAM, NAME);		\     }						\   aof_delete_import ((NAME));			\ }
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_EXTERNAL
parameter_list|(
name|STREAM
parameter_list|,
name|DECL
parameter_list|,
name|NAME
parameter_list|)
define|\
value|aof_add_import ((NAME))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_EXTERNAL_LIBCALL
parameter_list|(
name|STREAM
parameter_list|,
name|SYMREF
parameter_list|)
define|\
value|(fprintf ((STREAM), "\tIMPORT\t"),			\   assemble_name ((STREAM), XSTR ((SYMREF), 0)),		\   fputc ('\n', (STREAM)))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_LABELREF
parameter_list|(
name|STREAM
parameter_list|,
name|NAME
parameter_list|)
define|\
value|fprintf ((STREAM), "|%s|", NAME)
end_define

begin_define
define|#
directive|define
name|ASM_GENERATE_INTERNAL_LABEL
parameter_list|(
name|STRING
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|)
define|\
value|sprintf ((STRING), "*|%s..%ld|", (PREFIX), (long)(NUM))
end_define

begin_define
define|#
directive|define
name|ASM_FORMAT_PRIVATE_NAME
parameter_list|(
name|OUTVAR
parameter_list|,
name|NAME
parameter_list|,
name|NUMBER
parameter_list|)
define|\
value|((OUTVAR) = (char *) alloca (strlen ((NAME)) + 10),	\   sprintf ((OUTVAR), "%s.%d", (NAME), (NUMBER)))
end_define

begin_comment
comment|/* How initialization functions are handled */
end_comment

begin_define
define|#
directive|define
name|CTORS_SECTION_ASM_OP
value|"\tAREA\t|C$$gnu_ctorsvec|, DATA, READONLY"
end_define

begin_define
define|#
directive|define
name|DTORS_SECTION_ASM_OP
value|"\tAREA\t|C$$gnu_dtorsvec|, DATA, READONLY"
end_define

begin_comment
comment|/* Output of Assembler Instructions */
end_comment

begin_define
define|#
directive|define
name|REGISTER_NAMES
define|\
value|{					\   "a1", "a2", "a3", "a4",	\   "v1", "v2", "v3", "v4",	\   "v5", "v6", "sl", "fp",	\   "ip", "sp", "lr", "pc",	\   "f0", "f1", "f2", "f3",	\   "f4", "f5", "f6", "f7",	\   "cc", "sfp", "afp"		\ }
end_define

begin_define
define|#
directive|define
name|ADDITIONAL_REGISTER_NAMES
define|\
value|{						\   {"r0", 0}, {"a1", 0},				\   {"r1", 1}, {"a2", 1},				\   {"r2", 2}, {"a3", 2},				\   {"r3", 3}, {"a4", 3},		      		\   {"r4", 4}, {"v1", 4},				\   {"r5", 5}, {"v2", 5},				\   {"r6", 6}, {"v3", 6},				\   {"r7", 7}, {"wr", 7},				\   {"r8", 8}, {"v5", 8},				\   {"r9", 9}, {"v6", 9},				\   {"r10", 10}, {"sl", 10}, {"v7", 10},		\   {"r11", 11}, {"fp", 11},			\   {"r12", 12}, {"ip", 12}, 			\   {"r13", 13}, {"sp", 13}, 			\   {"r14", 14}, {"lr", 14},			\   {"r15", 15}, {"pc", 15}			\ }
end_define

begin_define
define|#
directive|define
name|REGISTER_PREFIX
value|"__"
end_define

begin_define
define|#
directive|define
name|USER_LABEL_PREFIX
value|""
end_define

begin_define
define|#
directive|define
name|LOCAL_LABEL_PREFIX
value|""
end_define

begin_comment
comment|/* AOF does not prefix user function names with an underscore.  */
end_comment

begin_define
define|#
directive|define
name|ARM_MCOUNT_NAME
value|"_mcount"
end_define

begin_comment
comment|/* Output of Dispatch Tables */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_DIFF_ELT
parameter_list|(
name|STREAM
parameter_list|,
name|BODY
parameter_list|,
name|VALUE
parameter_list|,
name|REL
parameter_list|)
define|\
value|fprintf ((STREAM), "\tb\t|L..%d|\n", (VALUE))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_ADDR_VEC_ELT
parameter_list|(
name|STREAM
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf ((STREAM), "\tDCD\t|L..%d|\n", (VALUE))
end_define

begin_comment
comment|/* A label marking the start of a jump table is a data label. */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_CASE_LABEL
parameter_list|(
name|STREAM
parameter_list|,
name|PREFIX
parameter_list|,
name|NUM
parameter_list|,
name|TABLE
parameter_list|)
define|\
value|fprintf ((STREAM), "\tALIGN\n|%s..%d|\n", (PREFIX), (NUM))
end_define

begin_comment
comment|/* Assembler Commands for Alignment */
end_comment

begin_define
define|#
directive|define
name|ASM_OUTPUT_SKIP
parameter_list|(
name|STREAM
parameter_list|,
name|NBYTES
parameter_list|)
define|\
value|fprintf ((STREAM), "\t%%\t%d\n", (NBYTES))
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_ALIGN
parameter_list|(
name|STREAM
parameter_list|,
name|POWER
parameter_list|)
define|\
value|do {							\   register int amount = 1<< (POWER);			\   if (amount == 2)					\     fprintf ((STREAM), "\tALIGN 2\n");			\   else if (amount == 4)					\     fprintf ((STREAM), "\tALIGN\n");			\   else							\     fprintf ((STREAM), "\tALIGN %d\n", amount);		\ } while (0)
end_define

begin_undef
undef|#
directive|undef
name|DBX_DEBUGGING_INFO
end_undef

end_unit

