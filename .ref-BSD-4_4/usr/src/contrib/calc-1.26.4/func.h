begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 David I. Bell  * Permission is granted to use, distribute, or modify this source,  * provided that this copyright notice remains intact.  */
end_comment

begin_comment
comment|/*  * Structure of a function.  * The f_opcodes array is actually of variable size.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|func
name|FUNC
typedef|;
end_typedef

begin_struct
struct|struct
name|func
block|{
name|FUNC
modifier|*
name|f_next
decl_stmt|;
comment|/* next function in list */
name|unsigned
name|long
name|f_opcodecount
decl_stmt|;
comment|/* size of opcode array */
name|unsigned
name|int
name|f_localcount
decl_stmt|;
comment|/* number of local variables */
name|unsigned
name|int
name|f_paramcount
decl_stmt|;
comment|/* max number of parameters */
name|char
modifier|*
name|f_name
decl_stmt|;
comment|/* function name */
name|VALUE
name|f_savedvalue
decl_stmt|;
comment|/* saved value of last expression */
name|long
name|f_opcodes
index|[
literal|1
index|]
decl_stmt|;
comment|/* array of opcodes (variable length) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Amount of space needed to allocate a function of n opcodes.  */
end_comment

begin_define
define|#
directive|define
name|funcsize
parameter_list|(
name|n
parameter_list|)
value|(sizeof(FUNC) + (n) * sizeof(long))
end_define

begin_comment
comment|/*  * Size of a character pointer rounded up to a number of opcodes.  */
end_comment

begin_define
define|#
directive|define
name|PTR_SIZE
value|((sizeof(char *) + sizeof(long) - 1) / sizeof(long))
end_define

begin_decl_stmt
specifier|extern
name|FUNC
modifier|*
name|curfunc
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current function being compiled */
end_comment

begin_function_decl
specifier|extern
name|FUNC
modifier|*
name|findfunc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return function given index */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|namefunc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return function name given index */
end_comment

begin_function_decl
specifier|extern
name|BOOL
name|evaluate
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* evaluate a line */
end_comment

begin_function_decl
specifier|extern
name|long
name|adduserfunc
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|beginfunc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* initialize a function for definition */
end_comment

begin_function_decl
specifier|extern
name|int
name|builtinopcode
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return the opcode for a built-in function */
end_comment

begin_function_decl
specifier|extern
name|void
name|addop
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add an opcode to the current function */
end_comment

begin_function_decl
specifier|extern
name|void
name|endfunc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* commit the just defined function for use */
end_comment

begin_function_decl
specifier|extern
name|void
name|addopindex
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add an opcode& index to the current func */
end_comment

begin_function_decl
specifier|extern
name|void
name|addoplabel
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add jump-type opcode + label to the func */
end_comment

begin_function_decl
specifier|extern
name|void
name|addopptr
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add an opcode + char ptr to the func */
end_comment

begin_function_decl
specifier|extern
name|void
name|showbuiltins
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* show list of primitive builtin funcs */
end_comment

begin_function_decl
specifier|extern
name|int
name|getbuiltinfunc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* return the index of a built-in func */
end_comment

begin_function_decl
specifier|extern
name|void
name|builtincheck
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* determine if the # of arguments are legal */
end_comment

begin_function_decl
specifier|extern
name|void
name|addopfunction
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* add opcode + index + arg count to the func */
end_comment

begin_function_decl
specifier|extern
name|void
name|showfunctions
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* show the list of user defined functs */
end_comment

begin_function_decl
specifier|extern
name|void
name|clearopt
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* clear optimization done for next opcode */
end_comment

begin_comment
comment|/* END CODE */
end_comment

end_unit

