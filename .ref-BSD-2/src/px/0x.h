begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * px - Berkeley Pascal interpreter  *  * Version 1.0, July 1977  *  * Written by Bill Joy and Chuck Haley  * November-December 1976  *  * Based on an earlier version by Ken Thompson  *  * Px is described in detail in the "PX 1.0 Implementation Notes"  * The source code for px is in several major pieces:  *  *	int.c		C main program which reads in interpreter code  *	00int.s		Driver including main interpreter loop  *	dd*.s		Where dd are digits, interpreter instructions  *			grouped by their positions in the interpreter table.  *	p*.c		Various C language routines supporting the system.  *  * In addition there are several headers defining mappings for error  * messages names into codes, and a definition of the interpreter transfer  * table. These are made by the script Emake in this directory and the scripts  * in the directory '../opcodes'.  */
end_comment

begin_decl_stmt
name|int
name|argc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Pascal runtime errors cause emulator traps  * to the routine onemt which transfers to the  * routine 'error' in the file perror.c to decode them.  * This method saves at least one word per static error.  */
end_comment

begin_function_decl
name|int
name|onemt
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Definitions for memory allocation  * Memory allocation routines are in 'palloc.c'  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|bottmem
decl_stmt|,
modifier|*
name|memptr
decl_stmt|,
modifier|*
name|high
decl_stmt|,
modifier|*
name|maxstk
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * The file i/o routines maintain a notion of a "current file".  * The printing name of this file is kept in the variable  * "file" for use in error messages.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|file
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_comment
comment|/*  * THE RUNTIME DISPLAY  *  * The entries in the display point to the active static block marks.  * The first entry in the display is for the global variables,  * then the procedure or function at level one, etc.  * Each display entry points to a stack frame as shown:  *  *		base of stack frame  *		  ---------------  *		  |		|  *		  | block mark  |  *		  |		|  *		  ---------------<-- display entry points here  *		  |             |  *		  |   local	|  *		  |  variables  |  *		  |		|  *		  ---------------  *		  |		|  *		  |  expression |  *		  |  temporary  |  *		  |  storage	|  *		  |		|  *		  - - - - - - - -  *  * The information in the block mark is thus at positive offsets from  * the display pointer entries while the local variables are at negative  * offsets. The block mark actually consists of two parts. The first  * part is created at CALL and the second at entry, i.e. BEGIN. Thus:  *  *		-------------------------  *		|			|  *		|  Saved lino		|  *		|  Saved lc		|  *		|  Saved dp		|  *		|			|  *		-------------------------  *		|			|  *		|  Saved (dp)		|  *		|			|  *		|  Current section name	|  *		|   and entry line ptr	|  *		|			|  *		|  Saved file name and	|  *		|   file buffer ptr	|  *		|			|  *		|  Empty tos value	|  *		|			|  *		-------------------------  */
end_comment

begin_decl_stmt
name|int
name|display
index|[
literal|20
index|]
decl_stmt|,
modifier|*
name|dp
decl_stmt|;
end_decl_stmt

begin_escape
end_escape

begin_decl_stmt
name|int
name|lino
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|nodump
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Random number generator constants  */
end_comment

begin_decl_stmt
name|long
name|seed
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|randa
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|randc
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|randm
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|double
name|randim
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Structures to access things on the stack  */
end_comment

begin_struct
struct|struct
block|{
name|char
name|pchar
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
block|{
name|int
name|pint
decl_stmt|;
name|int
name|p2int
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
block|{
name|long
name|plong
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
block|{
name|double
name|pdouble
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|char
name|discard
decl_stmt|;
end_decl_stmt

end_unit

