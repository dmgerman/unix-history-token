begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* **  GLOBALS.H -- Equel declarations ** **	Compilation Flags: **		xDEBUG -- for Chardebug, to provide compatability **			with older Equels' "-c" flag, and for  **			Lex_debug for the "-v" flag. ** **	Version: **		@(#)globals.h	7.1	2/5/81 */
end_comment

begin_comment
comment|/* **	Structure declarations */
end_comment

begin_comment
comment|/* parser keyword and operator table node */
end_comment

begin_struct
struct|struct
name|optab
block|{
name|char
modifier|*
name|op_term
decl_stmt|;
comment|/* pointer to terminal */
name|int
name|op_token
decl_stmt|;
comment|/* lexical token */
name|int
name|op_code
decl_stmt|;
comment|/* code to distinguish different op_terms  				 * with the same .op_token 				 */
block|}
struct|;
end_struct

begin_comment
comment|/* C variable tree node */
end_comment

begin_struct
struct|struct
name|cvar
block|{
name|char
modifier|*
name|c_id
decl_stmt|;
comment|/* identifier */
name|char
name|c_type
decl_stmt|;
comment|/* type */
name|char
name|c_indir
decl_stmt|;
comment|/* indirection level (- 1 for strings) */
name|struct
name|cvar
modifier|*
name|c_left
decl_stmt|;
comment|/*< sub-tree */
name|struct
name|cvar
modifier|*
name|c_right
decl_stmt|;
comment|/*> sub-tree */
block|}
struct|;
end_struct

begin_comment
comment|/* Display structures (linked list of strings) */
end_comment

begin_struct
struct|struct
name|disp_node
block|{
name|char
modifier|*
name|d_elm
decl_stmt|;
comment|/* display element */
name|struct
name|disp_node
modifier|*
name|d_next
decl_stmt|;
comment|/* next node */
name|int
name|d_line
decl_stmt|;
comment|/* for Symsp nodes, line 					 * where lexeme was seen 					 */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|display
block|{
name|struct
name|disp_node
modifier|*
name|disp_first
decl_stmt|;
comment|/* first node in display */
name|struct
name|disp_node
modifier|*
name|disp_last
decl_stmt|;
comment|/* last node in display */
block|}
struct|;
end_struct

begin_comment
comment|/* Retrieval list */
end_comment

begin_struct
struct|struct
name|ret_var
block|{
name|char
modifier|*
name|r_elm
decl_stmt|;
comment|/* string invoking variable 					 * e.g. "*intpa [2]" 					 */
name|struct
name|ret_var
modifier|*
name|r_next
decl_stmt|;
comment|/* next variable used in "tupret" */
name|char
name|r_type
decl_stmt|;
comment|/* type of variable */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ret_list
block|{
name|struct
name|ret_var
modifier|*
name|ret_first
decl_stmt|;
comment|/* first node in ret_var chain */
name|struct
name|ret_var
modifier|*
name|ret_last
decl_stmt|;
comment|/* last node in chain */
block|}
struct|;
end_struct

begin_comment
comment|/* "# include" file processing stack (list) */
end_comment

begin_struct
struct|struct
name|inc_file
block|{
name|int
name|inc_yyline
decl_stmt|;
comment|/* old file's yyline */
name|int
name|inc_lineout
decl_stmt|;
comment|/*  "    "     Lineout */
name|char
modifier|*
name|inc_fid
decl_stmt|;
comment|/* name */
name|FILE
modifier|*
name|inc_infile
decl_stmt|;
comment|/* In_file */
name|FILE
modifier|*
name|inc_outfile
decl_stmt|;
comment|/* Out_file */
name|struct
name|inc_file
modifier|*
name|inc_next
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  ** Structure for yacc generated terminal codes **	This avoids having to include functions in **	[grammar.y] for the function to know the  **	parser generated token numbers. */
end_comment

begin_struct
struct|struct
name|special
block|{
name|int
name|sp_name
decl_stmt|;
comment|/* NAME */
name|int
name|sp_sconst
decl_stmt|;
comment|/* SCONST */
name|int
name|sp_i2const
decl_stmt|;
comment|/* I2CONST */
name|int
name|sp_i4const
decl_stmt|;
comment|/* I4CONST */
name|int
name|sp_f8const
decl_stmt|;
comment|/* F8CONST */
name|int
name|sp_quote
decl_stmt|;
comment|/* QUOTE */
name|int
name|sp_bgncmnt
decl_stmt|;
comment|/* BGNCMNT */
name|int
name|sp_endcmnt
decl_stmt|;
comment|/* ENDCMNT */
name|int
name|sp_c_code
decl_stmt|;
comment|/* C_CODE */
name|int
name|sp_struct_var
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* **	Global definitions  */
end_comment

begin_decl_stmt
name|int
name|Opcode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* operator code to distinguis tokens */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|yychar
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* yacc input token */
end_comment

begin_decl_stmt
name|int
name|yyline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* yacc external line counter */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|yydebug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set by "-y" command line arg, 					 * has yacc parser give details 					 * of parse 					 */
end_comment

begin_decl_stmt
name|int
name|Newline
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* less than one token has been 					 * read from the input line, and 					 *  yylex isn't sure yet whether it is 					 * C_CODE or not 					 */
end_comment

begin_decl_stmt
name|int
name|Lineout
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output line count */
end_comment

begin_decl_stmt
name|int
name|In_quote
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if inside an IIwrite("... */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Input_file_name
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file name */
end_comment

begin_decl_stmt
name|int
name|Type_spec
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* used in parser, in C-declarations */
end_comment

begin_decl_stmt
name|int
name|C_code_flg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to indicate C-code in scanner */
end_comment

begin_decl_stmt
name|int
name|Pre_proc_flg
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set to indicate a  					 * pre-processor line  					 */
end_comment

begin_decl_stmt
name|int
name|Block_level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*> 0 local, 0 global */
end_comment

begin_decl_stmt
name|int
name|Indir_level
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* holds indirection level 					 * of a reference to a C-var 					 */
end_comment

begin_decl_stmt
name|int
name|Field_indir
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* indirection on a field of 					 * a structure variable 					 */
end_comment

begin_decl_stmt
name|int
name|Opflag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* mode in which to interpret syntax */
end_comment

begin_decl_stmt
name|int
name|In_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if output is in a string */
end_comment

begin_decl_stmt
name|int
name|Fillmode
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set if output line is being filled */
end_comment

begin_decl_stmt
name|int
name|Fillcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* count to fill a line to */
end_comment

begin_decl_stmt
name|int
name|Charcnt
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # chars written onto output line */
end_comment

begin_decl_stmt
name|int
name|Lastc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* type of last char read (OPCHAR or  					 * KEYCHAR) 					 */
end_comment

begin_decl_stmt
name|int
name|Arg_error
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set in argproc() [main.c] on 					 * error in prcessing command line 					 * arguments. 					 */
end_comment

begin_decl_stmt
name|int
name|Rtdb
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* set by "-d" command line arg, 					 * supplies equel runtime support 					 * with info to report file name 					 * and line number in case of an 					 * error 					 */
end_comment

begin_decl_stmt
name|int
name|Kwrdnum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of entries in Kwrdtab [tokens.y] */
end_comment

begin_decl_stmt
name|char
name|Line_buf
index|[
name|MAXSTRING
operator|+
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer for input line */
end_comment

begin_decl_stmt
name|char
modifier|*
name|Line_pos
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* position in input line */
end_comment

begin_decl_stmt
name|int
name|Peekc
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* holds backup character */
end_comment

begin_decl_stmt
name|int
name|Struct_flag
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* while processing a structure 					 * variable declaration, is set 					 */
end_comment

begin_decl_stmt
name|struct
name|cvar
modifier|*
name|Cvarp
decl_stmt|,
modifier|*
name|Fieldp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* to process C variables */
end_comment

begin_decl_stmt
name|struct
name|optab
name|Kwrdtab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table of key words [tokens.y] */
end_comment

begin_decl_stmt
name|struct
name|optab
name|Optab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* table of operators [tokens.y] */
end_comment

begin_decl_stmt
name|struct
name|special
name|Tokens
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* holds yacc generated lex codes 					 * [tokens.y] 					 */
end_comment

begin_decl_stmt
name|char
name|Cmap
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a type for each character [cmap.c] */
end_comment

begin_decl_stmt
name|struct
name|cvar
modifier|*
name|C_globals
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global C-variable tree */
end_comment

begin_decl_stmt
name|struct
name|cvar
modifier|*
name|C_locals
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Local C-variable tree */
end_comment

begin_decl_stmt
name|struct
name|cvar
modifier|*
name|F_locals
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Local structure fields */
end_comment

begin_decl_stmt
name|struct
name|cvar
modifier|*
name|F_globals
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Global structure fields */
end_comment

begin_decl_stmt
name|struct
name|display
name|Displays
index|[
literal|1
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Cv_display is set to point at this 					 * so that Cv_display may be passed 					 * as a parameter instead of&Cv_display 					 */
end_comment

begin_decl_stmt
name|struct
name|display
modifier|*
name|Cv_display
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* display into which "cvarx"'s  					 * get put  					 */
end_comment

begin_decl_stmt
name|struct
name|display
name|Symsp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* storage for symbols read by 					 * yylex()  					 */
end_comment

begin_decl_stmt
name|struct
name|ret_list
name|Ret_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* list of variables in a "ctlelm" */
end_comment

begin_decl_stmt
name|struct
name|inc_file
modifier|*
name|Inc_files
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* stack of files pushed by #includes */
end_comment

begin_comment
comment|/* **	I/O manipulation data structures */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|In_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* input file */
end_comment

begin_decl_stmt
name|FILE
modifier|*
name|Out_file
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* output file */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|xDEBUG
end_ifdef

begin_decl_stmt
name|char
name|Lex_debug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* debugging info for lexemes in yylex() 				 * [yylex.c] 				 */
end_comment

begin_decl_stmt
name|char
name|Chardebug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* print debugging info for routine 				 * in getch.c 				 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|extern
name|struct
name|cvar
modifier|*
name|getcvar
argument_list|()
decl_stmt|,
modifier|*
name|getfield
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|struct
name|disp_node
modifier|*
name|addsym
parameter_list|()
function_decl|;
end_function_decl

end_unit

