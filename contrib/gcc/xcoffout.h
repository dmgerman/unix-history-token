begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* XCOFF definitions.  These are needed in dbxout.c, final.c,    and xcoffout.h.    Copyright (C) 1998, 2000, 2002, 2003, 2004    Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
end_comment

begin_comment
comment|/* Tags and typedefs are C_DECL in XCOFF, not C_LSYM.  */
end_comment

begin_define
define|#
directive|define
name|DBX_TYPE_DECL_STABS_CODE
value|N_DECL
end_define

begin_comment
comment|/* Use the XCOFF predefined type numbers.  */
end_comment

begin_define
define|#
directive|define
name|DBX_ASSIGN_FUNDAMENTAL_TYPE_NUMBER
parameter_list|(
name|TYPE
parameter_list|)
define|\
value|xcoff_assign_fundamental_type_number (TYPE)
end_define

begin_comment
comment|/* Any type with a negative type index has already been output.  */
end_comment

begin_define
define|#
directive|define
name|DBX_TYPE_DEFINED
parameter_list|(
name|TYPE
parameter_list|)
value|(TYPE_SYMTAB_ADDRESS (TYPE)< 0)
end_define

begin_comment
comment|/* Must use N_STSYM for static const variables (those in the text section)    instead of N_FUN.  */
end_comment

begin_define
define|#
directive|define
name|DBX_STATIC_CONST_VAR_CODE
value|N_STSYM
end_define

begin_comment
comment|/* For static variables, output code to define the start of a static block.  */
end_comment

begin_define
define|#
directive|define
name|DBX_STATIC_BLOCK_START
parameter_list|(
name|ASMFILE
parameter_list|,
name|CODE
parameter_list|)
define|\
value|{									\   if ((CODE) == N_STSYM)						\     fprintf ((ASMFILE), "\t.bs\t%s[RW]\n", xcoff_private_data_section_name);\   else if ((CODE) == N_LCSYM)						\     fprintf ((ASMFILE), "\t.bs\t%s\n", xcoff_bss_section_name);	\ }
end_define

begin_comment
comment|/* For static variables, output code to define the end of a static block.  */
end_comment

begin_define
define|#
directive|define
name|DBX_STATIC_BLOCK_END
parameter_list|(
name|ASMFILE
parameter_list|,
name|CODE
parameter_list|)
define|\
value|{									\   if ((CODE) == N_STSYM || (CODE) == N_LCSYM)				\     fputs ("\t.es\n", (ASMFILE));					\ }
end_define

begin_comment
comment|/* We must use N_RPYSM instead of N_RSYM for register parameters.  */
end_comment

begin_define
define|#
directive|define
name|DBX_REGPARM_STABS_CODE
value|N_RPSYM
end_define

begin_comment
comment|/* We must use 'R' instead of 'P' for register parameters.  */
end_comment

begin_define
define|#
directive|define
name|DBX_REGPARM_STABS_LETTER
value|'R'
end_define

begin_comment
comment|/* Define our own finish symbol function, since xcoff stabs have their    own different format.  */
end_comment

begin_define
define|#
directive|define
name|DBX_FINISH_STABS
parameter_list|(
name|SYM
parameter_list|,
name|CODE
parameter_list|,
name|LINE
parameter_list|,
name|ADDR
parameter_list|,
name|LABEL
parameter_list|,
name|NUMBER
parameter_list|)
value|do {	\   if (ADDR)								\     {									\
comment|/* If we are writing a function name, we must emit a dot in	\ 	 order to refer to the function code, not its descriptor.  */
value|\       if (CODE == N_FUN)						\ 	putc ('.', asm_out_file);					\ 									\
comment|/* If we are writing a function name, we must ensure that		\ 	 there is no storage-class suffix on the name.  */
value|\       if (CODE == N_FUN&& GET_CODE (ADDR) == SYMBOL_REF)		\ 	{								\ 	  const char *_p = XSTR (ADDR, 0);				\ 	  if (*_p == '*')						\ 	    fputs (_p+1, asm_out_file);					\ 	  else								\ 	    for (; *_p != '['&& *_p; _p++)				\ 	      putc (*_p, asm_out_file);					\ 	}								\       else								\ 	output_addr_const (asm_out_file, ADDR);				\     }									\
comment|/* Another special case: N_GSYM always gets the symbol name,		\      whether or not LABEL or NUMBER are set.  */
value|\   else if (CODE == N_GSYM)						\     assemble_name (asm_out_file, XSTR (XEXP (DECL_RTL (SYM), 0), 0));	\   else if (LABEL)							\     assemble_name (asm_out_file, LABEL);				\   else									\     dbxout_int (NUMBER);						\   putc (',', asm_out_file);						\   dbxout_int (stab_to_sclass (CODE));					\   fputs (",0\n", asm_out_file);						\ } while (0)
end_define

begin_comment
comment|/* These are IBM XCOFF extensions we need to reference in dbxout.c    and xcoffout.c.  */
end_comment

begin_comment
comment|/* AIX XCOFF uses this for typedefs.  This can have any value, since it is    only used for translation into a C_DECL storage class.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|N_DECL
end_ifndef

begin_define
define|#
directive|define
name|N_DECL
value|0x8c
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIX XCOFF uses this for parameters passed in registers.  This can have    any value, since it is only used for translation into a C_RPSYM storage    class.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|N_RPSYM
end_ifndef

begin_define
define|#
directive|define
name|N_RPSYM
value|0x8e
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Name of the current include file.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|xcoff_current_include_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Names of bss and data sections.  These should be unique names for each    compilation unit.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xcoff_bss_section_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xcoff_private_data_section_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xcoff_read_only_section_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Last source file name mentioned in a NOTE insn.  */
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|char
modifier|*
name|xcoff_lastfile
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Don't write out path name for main source file.  */
end_comment

begin_define
define|#
directive|define
name|NO_DBX_MAIN_SOURCE_DIRECTORY
value|1
end_define

begin_comment
comment|/* Write out main source file name using ".file" rather than ".stabs".    We don't actually do this here, because the assembler gets confused if there    is more than one .file directive.  rs6000_xcoff_file_start is already    emitting a .file directory, so we don't output one here also.    Initialize xcoff_lastfile.  */
end_comment

begin_define
define|#
directive|define
name|DBX_OUTPUT_MAIN_SOURCE_FILENAME
parameter_list|(
name|FILE
parameter_list|,
name|FILENAME
parameter_list|)
define|\
value|xcoff_lastfile = (FILENAME)
end_define

begin_comment
comment|/* If we are still in an include file, its end must be marked.  */
end_comment

begin_define
define|#
directive|define
name|DBX_OUTPUT_MAIN_SOURCE_FILE_END
parameter_list|(
name|FILE
parameter_list|,
name|FILENAME
parameter_list|)
define|\
value|do {							\   if (xcoff_current_include_file)			\     {							\       fputs ("\t.ei\t", (FILE));			\       output_quoted_string ((FILE), xcoff_current_include_file);	\       putc ('\n', (FILE));				\       xcoff_current_include_file = NULL;		\     }							\ } while (0)
end_define

begin_comment
comment|/* Do not emit any marker for XCOFF until assembler allows XFT_CV.  */
end_comment

begin_define
define|#
directive|define
name|NO_DBX_GCC_MARKER
end_define

begin_comment
comment|/* Do not break .stabs pseudos into continuations.  */
end_comment

begin_define
define|#
directive|define
name|DBX_CONTIN_LENGTH
value|0
end_define

begin_comment
comment|/* Don't try to use the `x' type-cross-reference character in DBX data.    Also has the consequence of putting each struct, union or enum    into a separate .stabs, containing only cross-refs to the others.  */
end_comment

begin_define
define|#
directive|define
name|DBX_NO_XREFS
end_define

begin_comment
comment|/* We must put stabs in the text section.  If we don't the assembler    won't handle them correctly; it will sometimes put stabs where gdb    can't find them.  */
end_comment

begin_define
define|#
directive|define
name|DEBUG_SYMS_TEXT
end_define

begin_comment
comment|/* Prototype functions in xcoffout.c.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|stab_to_sclass
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xcoffout_begin_prologue
parameter_list|(
name|unsigned
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xcoffout_begin_block
parameter_list|(
name|unsigned
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xcoffout_end_epilogue
parameter_list|(
name|unsigned
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xcoffout_end_function
parameter_list|(
name|unsigned
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xcoffout_end_block
parameter_list|(
name|unsigned
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|xcoff_assign_fundamental_type_number
parameter_list|(
name|tree
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xcoffout_declare_function
parameter_list|(
name|FILE
modifier|*
parameter_list|,
name|tree
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|xcoffout_source_line
parameter_list|(
name|unsigned
name|int
parameter_list|,
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

