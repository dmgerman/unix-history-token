begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Target definitions for GNU compiler for Alliant FX/2800    running Concentrix 2.2     Copyright (C) 1991 Free Software Foundation, Inc.     Written by Howard Chu (hyc@hanauma.jpl.nasa.gov).  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|OUTPUT_TDESC
end_define

begin_include
include|#
directive|include
file|"i860v4.h"
end_include

begin_comment
comment|/* The Alliant fx2800 running Concentrix 2.x is weird.  This is basically    a BSD 4.3 based operating system, but it uses svr4 ELF format object    files and it somehow puts BSD stabs records into the ELF files for    symbolic debug information.  The assembler is "mostly an SVR4 assembler    with some Alliant additions. We based it on the `Intel 80860 Assembly    Language Specification' from AT&T." */
end_comment

begin_comment
comment|/* This file consists of three sections. The first section establishes    definitions unique to the Alliant FX/2800. The next section reconciles    differences between Alliant and i860v4.h, and the last overrides the    remaining differences with svr4.h */
end_comment

begin_undef
undef|#
directive|undef
name|TARGET_VERSION
end_undef

begin_define
define|#
directive|define
name|TARGET_VERSION
value|fprintf (stderr, " (i860 Alliant)");
end_define

begin_comment
comment|/* atexit is not present prior to Concentrix 2.2. Uncomment the following    if you're on 2.1 or older. */
end_comment

begin_comment
comment|/* #undef HAVE_ATEXIT */
end_comment

begin_define
define|#
directive|define
name|I860_STRICT_ABI_PROLOGUES
end_define

begin_define
define|#
directive|define
name|LINK_LIBGCC_SPECIAL
value|1
end_define

begin_comment
comment|/* Most of the Alliant-specific definitions here are to get stab info that    Alliant's dbx can understand. */
end_comment

begin_define
define|#
directive|define
name|DBX_DEBUGGING_INFO
end_define

begin_define
define|#
directive|define
name|DEFAULT_GDB_EXTENSIONS
value|0
end_define

begin_define
define|#
directive|define
name|DBX_NO_XREFS
end_define

begin_define
define|#
directive|define
name|DBX_NO_EXTRA_TAGS
end_define

begin_comment
comment|/* Alliant dbx also needs to see the function stab before anything    else in the function. */
end_comment

begin_define
define|#
directive|define
name|DBX_FUNCTION_FIRST
end_define

begin_define
define|#
directive|define
name|DBX_LBRAC_FIRST
end_define

begin_comment
comment|/* Alliant dbx also needs to see the end of a function somewhere. */
end_comment

begin_define
define|#
directive|define
name|DBX_OUTPUT_FUNCTION_END
parameter_list|(
name|file
parameter_list|,
name|decl
parameter_list|)
define|\
value|fprintf (file, ".stab \"\",.,0x%x,0,0\n", N_EFUN)
end_define

begin_comment
comment|/* Alliant dbx has predefined types, so they must be emitted with the    proper type numbers. The defined types are:       Type #	C, Fortran, Pascal Types 	--	------------------------ 	 1	char, integer*1 	 2	short, 	integer*2 	 3	int, long, integer*4, integer 	 4	logical*1, byte 	 5	logical*2 	 6	logical*4, logical 	 7	float, real*4, 	real 	 8	double, real*8,	double 	 9	single complex, complex*8, complex 	10	double complex, doublecomplex 	11	character 	12	void 	13	nil 	14	boolean 	15	unsigned char, ubyte 	16	unsigned short, uword 	17	unsigned, unsigned int, unsigned long, ulong 	18	quad, logical*8 	19	long long, integer*8 	20	unsigned long long, uquad*8     21-100	reserved for future predefined types 	100	long redefine same as 3 	101	unsigned long same as 17 	--	-------------------- 	102	First user program type     Since long and unsigned long are int references, they must be handled    as special cases. The Alliant compiler doesn't use types 18-20, so it    sets long& unsigned long in 18& 19, not in 100& 101 as shown above. */
end_comment

begin_define
define|#
directive|define
name|DBX_OUTPUT_STANDARD_TYPES
parameter_list|(
name|syms
parameter_list|)
define|\
value|{ char *dtyps[]={"", "char", "short int", "int", "logical*1",		\ 	"logical*2", "logical*4", "float", "double", "complex",		\ 	"doublecomplex", "character", "void", "nil", "boolean",		\ 	"unsigned char", "short unsigned int", "unsigned int",		\ 	"logical*8", "long long int", "long long unsigned int",""};	\ 									\   tree decl;								\   int i;								\ 									\   for (i=1;*dtyps[i];i++)						\     for (decl = syms; decl; decl = TREE_CHAIN(decl))			\ 	if ((TREE_CODE (decl) == TYPE_DECL)&& DECL_NAME(decl)&&	\ 	    !strcmp(IDENTIFIER_POINTER(DECL_NAME(decl)), dtyps[i])) {	\ 		TYPE_SYMTAB_ADDRESS (TREE_TYPE (decl)) = i;		\ 		typevec[i] = TYPE_DEFINED;				\ 		dbxout_symbol (decl, 0);				\ 		break;							\ 	}								\ 									\   for (decl = syms; decl; decl = TREE_CHAIN(decl))			\     if ((TREE_CODE (decl) == TYPE_DECL)&& DECL_NAME(decl)&&		\ 	!strcmp(IDENTIFIER_POINTER(DECL_NAME(decl)),"long int")) {	\       TYPE_SYMTAB_ADDRESS (TREE_TYPE (decl)) = i;			\       typevec[i] = TYPE_DEFINED;					\       fprintf(asmfile,".stab \"long int:t%d=3\",0,0x%x,0,0\n",		\ 		i++,N_LSYM);						\       TREE_ASM_WRITTEN (decl) = 1;					\       break;								\     }									\ 									\   for (decl = syms; decl; decl = TREE_CHAIN(decl))			\     if ((TREE_CODE (decl) == TYPE_DECL)&& DECL_NAME(decl)&& !strcmp(	\ 	IDENTIFIER_POINTER(DECL_NAME(decl)),"long unsigned int")) {	\       TYPE_SYMTAB_ADDRESS (TREE_TYPE (decl)) = i;			\       typevec[i] = TYPE_DEFINED;					\       fprintf(asmfile,".stab \"long unsigned int:t%d=17\",0,0x%x,0,0\n",\ 		i++,N_LSYM);						\       TREE_ASM_WRITTEN (decl) = 1;					\       break;								\     }									\   next_type_number = i; };
end_define

begin_comment
comment|/* Alliant dbx doesn't understand split names... */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|0
end_define

begin_comment
comment|/* The syntax for stabs records is also different; there is only a single    ".stab" directive instead of the 3 directives in BSD, and the order of    arguments is slightly changed. */
end_comment

begin_define
define|#
directive|define
name|ASM_STABS_OP
value|".stab"
end_define

begin_define
define|#
directive|define
name|ASM_STABN_OP
value|".stab"
end_define

begin_define
define|#
directive|define
name|ASM_STABD_OP
value|".stab"
end_define

begin_define
define|#
directive|define
name|DBX_MEMPARM_STABS_LETTER
value|'k'
end_define

begin_define
define|#
directive|define
name|DBX_REGPARM_STABS_LETTER
value|'r'
end_define

begin_define
define|#
directive|define
name|ASM_OUTPUT_SOURCE_LINE
parameter_list|(
name|file
parameter_list|,
name|num
parameter_list|)
define|\
value|fprintf (file, "\t.stab \"\",.,0x%x,0,%d\n",	\ 		N_SLINE,num)
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_comment
comment|/* Alliant dbx only reads first N_SO, so it 	   ignores the filename if dir is present. */
end_comment

begin_define
define|#
directive|define
name|DBX_OUTPUT_MAIN_SOURCE_DIRECTORY
parameter_list|(
name|file
parameter_list|,
name|name
parameter_list|)
define|\
value|fprintf (file, ".stab \"%s/\",.Ltext0,0x%x,0,0\n",	\ 		name, N_SO)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBX_OUTPUT_MAIN_SOURCE_DIRECTORY
parameter_list|(
name|file
parameter_list|,
name|name
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DBX_OUTPUT_MAIN_SOURCE_FILENAME
parameter_list|(
name|file
parameter_list|,
name|name
parameter_list|)
define|\
value|fprintf (file, ".stab \"%s\",.Ltext0,0x%x,0,0\n",	\ 		name, N_SO);					\ 	text_section ();					\ 	ASM_OUTPUT_INTERNAL_LABEL (file, "Ltext", 0)
end_define

begin_define
define|#
directive|define
name|DBX_OUTPUT_SOURCE_FILENAME
parameter_list|(
name|file
parameter_list|,
name|name
parameter_list|)
define|\
value|fprintf (file, ".stab \"%s\",.Ltext0,0x%x,0,0\n",	\ 		name, N_SOL);
end_define

begin_define
define|#
directive|define
name|DBX_OUTPUT_CONSTANT_SYMBOL
parameter_list|(
name|file
parameter_list|,
name|name
parameter_list|,
name|ival
parameter_list|)
define|\
value|fprintf (file, ".stab \"%s:c=i%d\",0,0x%x,0,0\n",	\ 		name, ival, N_LSYM)
end_define

begin_define
define|#
directive|define
name|DBX_FINISH_SYMBOL
parameter_list|(
name|decl
parameter_list|)
define|\
value|int line = 0;						\ 	fprintf (asmfile, "\",");				\ 	if (current_sym_addr)					\ 	  output_addr_const (asmfile, current_sym_addr);	\ 	else							\ 	  fprintf (asmfile, "%d", current_sym_value);		\ 	if (decl != 0&& TREE_CODE(decl) == FUNCTION_DECL)	\ 	  line=DECL_SOURCE_LINE (decl);				\ 	fprintf (asmfile, ",0x%x,%d,%d\n", current_sym_code,	\ 	  line!=0?64:0,line)
end_define

begin_define
define|#
directive|define
name|DBX_OUTPUT_CATCH
parameter_list|(
name|file
parameter_list|,
name|decl
parameter_list|,
name|name
parameter_list|)
define|\
value|fprintf (file, ".stab \"%s:C1\",",			\ 	   IDENTIFIER_POINTER (DECL_NAME (decl)));	\   assemble_name (file, name);				\   fprintf (file, ",0x%x,0,0\n", N_CATCH)
end_define

begin_define
define|#
directive|define
name|DBX_OUTPUT_LBRAC
parameter_list|(
name|file
parameter_list|,
name|name
parameter_list|)
define|\
value|if (depth> 1) {			\     fprintf (file, ".stab \"\",");	\     assemble_name (file, name);		\     fprintf (file, ",0x%x,0,%d\n", N_LBRAC, depth); }
end_define

begin_define
define|#
directive|define
name|DBX_OUTPUT_RBRAC
parameter_list|(
name|file
parameter_list|,
name|name
parameter_list|)
define|\
value|if (depth> 1) {			\     fprintf (file, ".stab \"\",");	\     assemble_name (file, name);		\     fprintf (file, ",0x%x,0,%d\n", N_RBRAC, depth); }
end_define

begin_define
define|#
directive|define
name|DBX_OUTPUT_ENUM
parameter_list|(
name|file
parameter_list|,
name|type
parameter_list|)
define|\
value|fprintf (file, "e3");						\   CHARS(2);							\   for (tem = TYPE_VALUES (type); tem; tem = TREE_CHAIN (tem))	\     {								\       fprintf (asmfile, "%s:%d,",				\ 	       IDENTIFIER_POINTER (TREE_PURPOSE (tem)),		\ 	       TREE_INT_CST_LOW (TREE_VALUE (tem)));		\       CHARS (11 + IDENTIFIER_LENGTH (TREE_PURPOSE (tem)));	\       if (TREE_CHAIN (tem) != 0)				\ 	CONTIN;							\     }								\   putc (';', asmfile);						\   CHARS (1);
end_define

begin_comment
comment|/* Undefine some things defined in i860.h because the native C compiler    on the FX/2800 emits code to do these operations inline.  For GCC,    we will use the default implementation of these things... i.e.    generating calls to libgcc1 routines.  */
end_comment

begin_undef
undef|#
directive|undef
name|DIVSI3_LIBCALL
end_undef

begin_undef
undef|#
directive|undef
name|UDIVSI3_LIBCALL
end_undef

begin_undef
undef|#
directive|undef
name|REMSI3_LIBCALL
end_undef

begin_undef
undef|#
directive|undef
name|UREMSI3_LIBCALL
end_undef

begin_comment
comment|/* The Alliant compiler's mod function gives the wrong result after a    shift operation. This bug typically hits in hash functions. */
end_comment

begin_define
define|#
directive|define
name|perform_umodsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a %= b; if (a == b) a=0; return a
end_define

begin_define
define|#
directive|define
name|perform_modsi3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|a %= b; if (a == b) a=0; return a
end_define

begin_comment
comment|/* Global pointer needs to be 8 byte aligned? Link error if not... */
end_comment

begin_define
define|#
directive|define
name|DATA_ALIGNMENT
parameter_list|(
name|dummy
parameter_list|,
name|align
parameter_list|)
define|\
value|((TREE_PUBLIC (decl)&&	\ 	 (TREE_CODE (TREE_TYPE (decl))==POINTER_TYPE)) ? 64:align)
end_define

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
value|fprintf (FILE, "\tcall __mcount_\n\tnop\n")
end_define

begin_comment
comment|/* Overrides for i860v4.h begin here */
end_comment

begin_comment
comment|/* Provide a set of pre-definitions and pre-assertions appropriate for    the i860 running Concentrix 2.x.  */
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
value|"-Di860 -Dunix -DBSD4_3 -Dalliant -Asystem(unix) -Acpu(i860) -Amachine(i860)"
end_define

begin_undef
undef|#
directive|undef
name|I860_REG_PREFIX
end_undef

begin_undef
undef|#
directive|undef
name|ASM_COMMENT_START
end_undef

begin_define
define|#
directive|define
name|ASM_COMMENT_START
value|"//"
end_define

begin_comment
comment|/* Use definitions of ASM_OUTPUT_{DOUBLE,FLOAT} as given in i860.h */
end_comment

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_DOUBLE
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_DOUBLE
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf(FILE, "\t.double %.20e\n", (VALUE))
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_FLOAT
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_FLOAT
parameter_list|(
name|FILE
parameter_list|,
name|VALUE
parameter_list|)
define|\
value|fprintf(FILE, "\t.float %.12e\n", (VALUE))
end_define

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
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_FUNCTION_PREFIX
end_undef

begin_define
define|#
directive|define
name|ASM_OUTPUT_FUNCTION_PREFIX
parameter_list|(
name|FILE
parameter_list|,
name|NAME
parameter_list|)
define|\
value|fputs("\tnop\n", (FILE));			\   current_function_original_name = (NAME)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_PROLOGUE_SUFFIX
end_undef

begin_comment
comment|/* Overrides for svr4.h begin here */
end_comment

begin_undef
undef|#
directive|undef
name|SVR4
end_undef

begin_undef
undef|#
directive|undef
name|SWITCH_TAKES_ARG
end_undef

begin_undef
undef|#
directive|undef
name|WORD_SWITCH_TAKES_ARG
end_undef

begin_undef
undef|#
directive|undef
name|ASM_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|ASM_FINAL_SPEC
end_undef

begin_undef
undef|#
directive|undef
name|MD_STARTFILE_PREFIX
end_undef

begin_undef
undef|#
directive|undef
name|MD_EXEC_PREFIX
end_undef

begin_comment
comment|/* Generate an error message if -p option is selected. Concentrix 2.x    does not support prof format profiling, only gprof is supported. */
end_comment

begin_define
define|#
directive|define
name|CPP_SPEC
value|"%{p:%e-p option not supported: use -pg instead}"
end_define

begin_comment
comment|/* Provide an appropriate LIB_SPEC. The crtend.o file provides part of the    support for getting C++ file-scope static objects constructed before    entering `main'. */
end_comment

begin_undef
undef|#
directive|undef
name|LIB_SPEC
end_undef

begin_define
define|#
directive|define
name|LIB_SPEC
define|\
value|"%{g*:-lg} %{!pg:-lc}%{pg:-lc_p} crtend.o%s"
end_define

begin_comment
comment|/* Tell linker to strip local symbols, since assembler may not. */
end_comment

begin_undef
undef|#
directive|undef
name|LINK_SPEC
end_undef

begin_define
define|#
directive|define
name|LINK_SPEC
value|"-X"
end_define

begin_comment
comment|/* Get the correct startup file for regular or profiled code. Also    use the crtbegin.o file for C++ ... */
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
value|"%{!pg:crt0.o%s}%{pg:gcrt0.o%s} crtbegin.o%s"
end_define

begin_undef
undef|#
directive|undef
name|SCCS_DIRECTIVE
end_undef

begin_undef
undef|#
directive|undef
name|NO_DOLLAR_IN_LABEL
end_undef

begin_undef
undef|#
directive|undef
name|TARGET_MEM_FUNCTIONS
end_undef

begin_undef
undef|#
directive|undef
name|DWARF_DEBUGGING_INFO
end_undef

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
value|fprintf (FILE, "_%s", NAME)
end_define

begin_undef
undef|#
directive|undef
name|ASM_OUTPUT_EXTERNAL_LIBCALL
end_undef

begin_undef
undef|#
directive|undef
name|BSS_ASM_OP
end_undef

begin_define
define|#
directive|define
name|BSS_ASM_OP
value|"\t.lcomm"
end_define

end_unit

