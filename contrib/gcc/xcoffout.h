begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* XCOFF definitions.  These are needed in dbxout.c, final.c,    and xcoffout.h.  */
end_comment

begin_define
define|#
directive|define
name|ASM_STABS_OP
value|".stabx"
end_define

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

begin_comment
comment|/* ??? According to metin, typedef stabx must go in text control section,    but he did not make this changes everywhere where such typedef stabx    can be emitted, so it is really needed or not?  */
end_comment

begin_define
define|#
directive|define
name|DBX_OUTPUT_STANDARD_TYPES
parameter_list|(
name|SYMS
parameter_list|)
define|\
value|{						\   text_section ();				\   xcoff_output_standard_types (SYMS);		\ }
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
comment|/* For static variables, output code to define the start of a static block.     ??? The IBM rs6000/AIX assembler has a bug that causes bss block debug    info to be occasionally lost.  A simple example is this: 	int a; static int b;    The commands `gcc -g -c tmp.c; dump -t tmp.o' gives [10]	m   0x00000016         1     0    0x8f  0x0000            .bs [11]	m   0x00000000         1     0    0x90  0x0000            .es ... [21]	m   0x00000000        -2     0    0x85  0x0000            b:S-1    which is wrong.  The `b:S-1' must be between the `.bs' and `.es'.    We can apparently work around the problem by forcing the text section    (even if we are already in the text section) immediately before outputting    the `.bs'.  This should be fixed in the next major AIX release (3.3?).  */
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
value|{									\   if ((CODE) == N_STSYM)						\     fprintf ((ASMFILE), "\t.bs\t%s[RW]\n", xcoff_private_data_section_name);\   else if ((CODE) == N_LCSYM)						\     {									\       fprintf ((ASMFILE), "%s\n", TEXT_SECTION_ASM_OP);			\       fprintf ((ASMFILE), "\t.bs\t%s\n", xcoff_bss_section_name);	\     }									\ }
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
value|{									\   if (current_sym_code == N_STSYM || current_sym_code == N_LCSYM)	\     fprintf (asmfile, "\t.es\n");					\ }
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
name|DBX_FINISH_SYMBOL
parameter_list|(
name|SYM
parameter_list|)
define|\
value|{								\   if (current_sym_addr&& current_sym_code == N_FUN)		\     fprintf (asmfile, "\",.");					\   else								\     fprintf (asmfile, "\",");					\
comment|/* If we are writing a function name, we must ensure that	\      there is no storage-class suffix on the name.  */
value|\   if (current_sym_addr&& current_sym_code == N_FUN		\&& GET_CODE (current_sym_addr) == SYMBOL_REF)		\     {								\       char *_p = XSTR (current_sym_addr, 0);			\       if (*_p == '*')						\ 	fprintf (asmfile, "%s", _p+1);				\       else							\         for (; *_p != '['&& *_p; _p++)				\ 	  fprintf (asmfile, "%c", *_p);				\     }								\   else if (current_sym_addr)					\     output_addr_const (asmfile, current_sym_addr);		\   else if (current_sym_code == N_GSYM)				\     assemble_name (asmfile, XSTR (XEXP (DECL_RTL (sym), 0), 0)); \   else								\     fprintf (asmfile, "%d", current_sym_value);			\   fprintf (asmfile, ",%d,0\n", stab_to_sclass (current_sym_code)); \ }
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
comment|/* The line number of the beginning of the current function.    xcoffout.c needs this so that it can output relative linenumbers.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|xcoff_begin_function_line
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of the current include file.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xcoff_current_include_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Name of the current function file.  This is the file the `.bf' is    emitted from.  In case a line is emitted from a different file,    (by including that file of course), then the line number will be    absolute.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|xcoff_current_function_file
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
name|DBX_OUTPUT_MAIN_SOURCE_DIRECTORY
parameter_list|(
name|FILE
parameter_list|,
name|FILENAME
parameter_list|)
end_define

begin_comment
comment|/* Write out main source file name using ".file" rather than ".stabs".    We don't actually do this here, because the assembler gets confused if there    is more than one .file directive.  ASM_FILE_START in config/rs6000/rs6000.h    is already emitting a .file directory, so we don't output one here also.    Initialize xcoff_lastfile.  */
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
value|xcoff_lastfile = input_file_name
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
value|{							\   if (xcoff_current_include_file)			\     {							\       fprintf (FILE, "\t.ei\t");			\       output_quoted_string (FILE, xcoff_current_include_file);	\       fprintf (FILE, "\n");				\       xcoff_current_include_file = NULL;		\     }							\ }
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

end_unit

