begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* variables.h -- data structures for shell variables. */
end_comment

begin_comment
comment|/* Shell variables and functions are stored in hash tables. */
end_comment

begin_include
include|#
directive|include
file|"hash.h"
end_include

begin_comment
comment|/* What a shell variable looks like. */
end_comment

begin_typedef
typedef|typedef
name|struct
name|variable
modifier|*
name|DYNAMIC_FUNC
parameter_list|()
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|variable
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* Symbol that the user types. */
name|char
modifier|*
name|value
decl_stmt|;
comment|/* Value that is returned. */
name|DYNAMIC_FUNC
modifier|*
name|dynamic_value
decl_stmt|;
comment|/* Function called to return a `dynamic' 				   value for a variable, like $SECONDS 				   or $RANDOM. */
name|DYNAMIC_FUNC
modifier|*
name|assign_func
decl_stmt|;
comment|/* Function called when this `special 				   variable' is assigned a value in 				   bind_variable. */
name|int
name|attributes
decl_stmt|;
comment|/* export, readonly, array, invisible... */
name|int
name|context
decl_stmt|;
comment|/* Which context this variable belongs to. */
name|struct
name|variable
modifier|*
name|prev_context
decl_stmt|;
comment|/* Value from previous context or NULL. */
block|}
name|SHELL_VAR
typedef|;
end_typedef

begin_comment
comment|/* The various attributes that a given variable can have.    We only reserve one byte of the INT. */
end_comment

begin_define
define|#
directive|define
name|att_exported
value|0x01
end_define

begin_comment
comment|/* %00000001 (export to environment) */
end_comment

begin_define
define|#
directive|define
name|att_readonly
value|0x02
end_define

begin_comment
comment|/* %00000010 (cannot change)	     */
end_comment

begin_define
define|#
directive|define
name|att_invisible
value|0x04
end_define

begin_comment
comment|/* %00000100 (cannot see)	     */
end_comment

begin_define
define|#
directive|define
name|att_array
value|0x08
end_define

begin_comment
comment|/* %00001000 (value is an array)     */
end_comment

begin_define
define|#
directive|define
name|att_nounset
value|0x10
end_define

begin_comment
comment|/* %00010000 (cannot unset)	     */
end_comment

begin_define
define|#
directive|define
name|att_function
value|0x20
end_define

begin_comment
comment|/* %00100000 (value is a function)   */
end_comment

begin_define
define|#
directive|define
name|att_integer
value|0x40
end_define

begin_comment
comment|/* %01000000 (internal rep. is int)  */
end_comment

begin_define
define|#
directive|define
name|exported_p
parameter_list|(
name|var
parameter_list|)
value|((((var)->attributes)& (att_exported)))
end_define

begin_define
define|#
directive|define
name|readonly_p
parameter_list|(
name|var
parameter_list|)
value|((((var)->attributes)& (att_readonly)))
end_define

begin_define
define|#
directive|define
name|invisible_p
parameter_list|(
name|var
parameter_list|)
value|((((var)->attributes)& (att_invisible)))
end_define

begin_define
define|#
directive|define
name|array_p
parameter_list|(
name|var
parameter_list|)
value|((((var)->attributes)& (att_array)))
end_define

begin_define
define|#
directive|define
name|function_p
parameter_list|(
name|var
parameter_list|)
value|((((var)->attributes)& (att_function)))
end_define

begin_define
define|#
directive|define
name|integer_p
parameter_list|(
name|var
parameter_list|)
value|((((var)->attributes)& (att_integer)))
end_define

begin_define
define|#
directive|define
name|value_cell
parameter_list|(
name|var
parameter_list|)
value|((var)->value)
end_define

begin_define
define|#
directive|define
name|function_cell
parameter_list|(
name|var
parameter_list|)
value|(COMMAND *)((var)->value)
end_define

begin_comment
comment|/* Stuff for hacking variables. */
end_comment

begin_decl_stmt
specifier|extern
name|HASH_TABLE
modifier|*
name|shell_variables
decl_stmt|,
modifier|*
name|shell_functions
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SHELL_VAR
modifier|*
name|find_function
argument_list|()
decl_stmt|,
modifier|*
name|find_variable
argument_list|()
decl_stmt|,
modifier|*
name|variable_lookup
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|SHELL_VAR
modifier|*
name|copy_variable
argument_list|()
decl_stmt|,
modifier|*
name|bind_variable
argument_list|()
decl_stmt|,
modifier|*
name|bind_function
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|get_string_value
argument_list|()
decl_stmt|,
modifier|*
name|dollar_vars
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|export_env
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|SHELL_VAR
modifier|*
modifier|*
name|map_over
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|SHELL_VAR
modifier|*
modifier|*
name|all_shell_variables
argument_list|()
decl_stmt|,
modifier|*
modifier|*
name|all_shell_functions
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|variable_in_context
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|variable_context
decl_stmt|;
end_decl_stmt

end_unit

