begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|P1_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|P1_COMMENT
value|1
end_define

begin_comment
comment|/* Fortan comment string */
end_comment

begin_define
define|#
directive|define
name|P1_EOF
value|2
end_define

begin_comment
comment|/* End of file dummy token */
end_comment

begin_define
define|#
directive|define
name|P1_SET_LINE
value|3
end_define

begin_comment
comment|/* Reset the line counter */
end_comment

begin_define
define|#
directive|define
name|P1_FILENAME
value|4
end_define

begin_comment
comment|/* Name of current input file */
end_comment

begin_define
define|#
directive|define
name|P1_NAME_POINTER
value|5
end_define

begin_comment
comment|/* Pointer to hash table entry */
end_comment

begin_define
define|#
directive|define
name|P1_CONST
value|6
end_define

begin_comment
comment|/* Some constant value */
end_comment

begin_define
define|#
directive|define
name|P1_EXPR
value|7
end_define

begin_comment
comment|/* Followed by opcode */
end_comment

begin_comment
comment|/* The next two tokens could be grouped together, since they always come    from an Addr structure */
end_comment

begin_define
define|#
directive|define
name|P1_IDENT
value|8
end_define

begin_comment
comment|/* Char string identifier in addrp->user 				   field */
end_comment

begin_define
define|#
directive|define
name|P1_EXTERN
value|9
end_define

begin_comment
comment|/* Pointer to external symbol entry */
end_comment

begin_define
define|#
directive|define
name|P1_HEAD
value|10
end_define

begin_comment
comment|/* Function header info */
end_comment

begin_define
define|#
directive|define
name|P1_LIST
value|11
end_define

begin_comment
comment|/* A list of data (e.g. arguments) will 				   follow the tag, type, and count */
end_comment

begin_define
define|#
directive|define
name|P1_LITERAL
value|12
end_define

begin_comment
comment|/* Hold the index into the literal pool */
end_comment

begin_define
define|#
directive|define
name|P1_LABEL
value|13
end_define

begin_comment
comment|/* label value */
end_comment

begin_define
define|#
directive|define
name|P1_ASGOTO
value|14
end_define

begin_comment
comment|/* Store the hash table pointer of 				   variable used in assigned goto */
end_comment

begin_define
define|#
directive|define
name|P1_GOTO
value|15
end_define

begin_comment
comment|/* Store the statement number */
end_comment

begin_define
define|#
directive|define
name|P1_IF
value|16
end_define

begin_comment
comment|/* store the condition as an expression */
end_comment

begin_define
define|#
directive|define
name|P1_ELSE
value|17
end_define

begin_comment
comment|/* No data */
end_comment

begin_define
define|#
directive|define
name|P1_ELIF
value|18
end_define

begin_comment
comment|/* store the condition as an expression */
end_comment

begin_define
define|#
directive|define
name|P1_ENDIF
value|19
end_define

begin_comment
comment|/* Marks the end of a block IF */
end_comment

begin_define
define|#
directive|define
name|P1_ENDELSE
value|20
end_define

begin_comment
comment|/* Marks the end of a block ELSE */
end_comment

begin_define
define|#
directive|define
name|P1_ADDR
value|21
end_define

begin_comment
comment|/* Addr data; used for arrays, common and 				   equiv addressing, NOT for names, idents 				   or externs */
end_comment

begin_define
define|#
directive|define
name|P1_SUBR_RET
value|22
end_define

begin_comment
comment|/* Subroutine return; the return expression 				   follows */
end_comment

begin_define
define|#
directive|define
name|P1_COMP_GOTO
value|23
end_define

begin_comment
comment|/* Computed goto; has expr, label list */
end_comment

begin_define
define|#
directive|define
name|P1_FOR
value|24
end_define

begin_comment
comment|/* C FOR loop; three expressions follow */
end_comment

begin_define
define|#
directive|define
name|P1_ENDFOR
value|25
end_define

begin_comment
comment|/* End of C FOR loop */
end_comment

begin_define
define|#
directive|define
name|P1_FORTRAN
value|26
end_define

begin_comment
comment|/* original Fortran source */
end_comment

begin_define
define|#
directive|define
name|P1_CHARP
value|27
end_define

begin_comment
comment|/* user.Charp field -- for long names */
end_comment

begin_define
define|#
directive|define
name|P1_WHILE1START
value|28
end_define

begin_comment
comment|/* start of DO WHILE */
end_comment

begin_define
define|#
directive|define
name|P1_WHILE2START
value|29
end_define

begin_comment
comment|/* rest of DO WHILE */
end_comment

begin_define
define|#
directive|define
name|P1_PROCODE
value|30
end_define

begin_comment
comment|/* invoke procode() -- to adjust params */
end_comment

begin_define
define|#
directive|define
name|P1_ELSEIFSTART
value|31
end_define

begin_comment
comment|/* handle extra code for abs, min, max 				   in else if() */
end_comment

begin_define
define|#
directive|define
name|P1_FILENAME_MAX
value|256
end_define

begin_comment
comment|/* max filename length to retain (for -g) */
end_comment

begin_define
define|#
directive|define
name|P1_STMTBUFSIZE
value|1400
end_define

begin_define
define|#
directive|define
name|COMMENT_BUFFER_SIZE
value|255
end_define

begin_comment
comment|/* max number of chars in each comment */
end_comment

begin_define
define|#
directive|define
name|CONSTANT_STR_MAX
value|1000
end_define

begin_comment
comment|/* max number of chars in string constant */
end_comment

begin_function_decl
specifier|extern
name|void
name|p1put
parameter_list|(
comment|/* int */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|p1_comment
parameter_list|(
comment|/* char * */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|p1_label
parameter_list|(
comment|/* int */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|p1_line_number
parameter_list|(
comment|/* int */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|p1put_filename
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|p1_expr
parameter_list|(
comment|/* expptr */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|p1_head
parameter_list|(
comment|/* int, char * */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|p1_if
parameter_list|(
comment|/* expptr */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|p1_else
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|p1_elif
parameter_list|(
comment|/* expptr */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|p1_endif
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|p1else_end
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|p1_subr_ret
parameter_list|(
comment|/* expptr */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|p1_goto
parameter_list|(
comment|/* long */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|p1comp_goto
parameter_list|(
comment|/* expptr, int, struct Labelblock *[] */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|p1_for
parameter_list|(
comment|/* expptr, expptr, expptr */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|p1for_end
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|p1puts
parameter_list|(
comment|/* int, char * */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* The pass 1 intermediate file has the following format:<ascii-integer-rep> [ : [<sp> [<data> ]]] \n     e.g.   1: This is a comment     This format is destined to change in the future, but for now a readable    form is more desirable than a compact form.     NOTES ABOUT THE P1 FORMAT    ----------------------------------------------------------------------  	P1_COMMENT:  The comment string (in<data>)   may be at most 		COMMENT_BUFFER_SIZE bytes long.  It must contain no newlines 		or null characters.  A side effect of the way comments are 		read in   lex.c   is that no '\377' chars may be in a 		comment either.  	P1_SET_LINE:<data>  holds the line number in the current source file.  	P1_INC_LINE:  Increment the source line number;<data>   is empty.  	P1_NAME_POINTER:<data>   holds the integer representation of a 			  pointer into a hash table entry.  	P1_CONST:  the first field in<data>   is a type tag (one of the 		   TYxxxx   macros), the next field holds the constant 		   value  	P1_EXPR:<data>   holds the opcode number of the expression, 		  followed by the type of the expression (required for 		  OPCONV).  Next is the value of   vleng. 		  The type of operation represented by the 		  opcode determines how many of the following data items 		  are part of this expression.  	P1_IDENT:<data>   holds the type, then storage, then the 		   char string identifier in the   addrp->user   field.  	P1_EXTERN:<data>   holds an offset into the external symbol 		    table entry  	P1_HEAD:  the first field in<data>  is the procedure class, the 		  second is the name of the procedure  	P1_LIST:  the first field in<data>   is the tag, the second the 		  type of the list, the third the number of elements in 		  the list  	P1_LITERAL:<data>   holds the   litnum   of a value in the 		     literal pool.  	P1_LABEL:<data>   holds the statement number of the current 		   line  	P1_ASGOTO:<data>   holds the hash table pointer of the variable  	P1_GOTO:<data>   holds the statement number to jump to  	P1_IF:<data>   is empty, the following expression is the IF 	        condition.  	P1_ELSE:<data>   is empty.  	P1_ELIF:<data>   is empty, the following expression is the IF 		  condition.  	P1_ENDIF:<data>   is empty.  	P1_ENDELSE:<data>   is empty.  	P1_ADDR:<data>   holds a direct copy of the structure.  The 		  next expression is a copy of    vleng,   and the next a 		  copy of    memoffset.  	P1_SUBR_RET:  The next token is an expression for the return value.  	P1_COMP_GOTO:  The next token is an integer expression, the 		       following one a list of labels.  	P1_FOR:  The next three expressions are the Init, Test, and 	         Increment expressions of a C FOR loop.  	P1_ENDFOR:  Marks the end of the body of a FOR loop  */
end_comment

end_unit

