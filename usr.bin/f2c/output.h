begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* nice_printf -- same arguments as fprintf.  	All output which is to become C code must be directed through this    function.  For now, no buffering is done.  Later on, every line of    output will be filtered to accomodate the style definitions (e.g. one    statement per line, spaces between function names and argument lists,    etc.) */
end_comment

begin_include
include|#
directive|include
file|"niceprintf.h"
end_include

begin_function_decl
specifier|extern
name|int
name|nice_printf
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Definitions for the opcode table.  The table is indexed by the macros    which are #defined in   defines.h   */
end_comment

begin_define
define|#
directive|define
name|UNARY_OP
value|01
end_define

begin_define
define|#
directive|define
name|BINARY_OP
value|02
end_define

begin_define
define|#
directive|define
name|SPECIAL_FMT
value|NULL
end_define

begin_define
define|#
directive|define
name|is_unary_op
parameter_list|(
name|x
parameter_list|)
value|(opcode_table[x].type == UNARY_OP)
end_define

begin_define
define|#
directive|define
name|is_binary_op
parameter_list|(
name|x
parameter_list|)
value|(opcode_table[x].type == BINARY_OP)
end_define

begin_define
define|#
directive|define
name|op_precedence
parameter_list|(
name|x
parameter_list|)
value|(opcode_table[x].prec)
end_define

begin_define
define|#
directive|define
name|op_format
parameter_list|(
name|x
parameter_list|)
value|(opcode_table[x].format)
end_define

begin_comment
comment|/* _assoc_table -- encodes left-associativity and right-associativity    information; indexed by precedence level.  Only 2, 3, 14 are    right-associative.  Source:  Kernighan& Ritchie, p. 49 */
end_comment

begin_decl_stmt
specifier|extern
name|char
name|_assoc_table
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|is_right_assoc
parameter_list|(
name|x
parameter_list|)
value|(_assoc_table [x])
end_define

begin_define
define|#
directive|define
name|is_left_assoc
parameter_list|(
name|x
parameter_list|)
value|(! _assoc_table [x])
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|type
decl_stmt|;
comment|/* UNARY_OP or BINARY_OP */
name|int
name|prec
decl_stmt|;
comment|/* Precedence level, useful for adjusting 				   number of parens to insert.  Zero is a 				   special level, and 2, 3, 14 are 				   right-associative */
name|char
modifier|*
name|format
decl_stmt|;
block|}
name|table_entry
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|fl_fmt_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Float constant format string */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|db_fmt_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Double constant format string */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|cm_fmt_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Complex constant format string */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|dcm_fmt_string
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Double Complex constant format string */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|indent
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of spaces to indent; this is a 				   temporary fix */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|tab_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Number of spaces in each tab */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|in_string
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|table_entry
name|opcode_table
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|expr_out
argument_list|()
decl_stmt|,
name|out_init
argument_list|()
decl_stmt|,
name|out_addr
argument_list|()
decl_stmt|,
name|out_const
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|out_name
argument_list|()
decl_stmt|,
name|extern_out
argument_list|()
decl_stmt|,
name|out_asgoto
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|out_if
argument_list|()
decl_stmt|,
name|out_else
argument_list|()
decl_stmt|,
name|elif_out
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|endif_out
argument_list|()
decl_stmt|,
name|end_else_out
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|compgoto_out
argument_list|()
decl_stmt|,
name|out_for
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|out_end_for
argument_list|()
decl_stmt|,
name|out_and_free_statement
argument_list|()
decl_stmt|;
end_decl_stmt

end_unit

