begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* flags.h -- a list of all the flags that the shell knows about.  You add    a flag to this program by adding the name here, and in flags.c. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_FLAGS_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|_FLAGS_H
end_define

begin_comment
comment|/* Welcome to the world of Un*x, where everything is slightly    backwards. */
end_comment

begin_define
define|#
directive|define
name|FLAG_ON
value|'-'
end_define

begin_define
define|#
directive|define
name|FLAG_OFF
value|'+'
end_define

begin_define
define|#
directive|define
name|FLAG_ERROR
value|-1
end_define

begin_comment
comment|/* The thing that we build the array of flags out of. */
end_comment

begin_struct
struct|struct
name|flags_alist
block|{
name|char
modifier|*
name|name
decl_stmt|;
name|int
modifier|*
name|value
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|flags_alist
name|shell_flags
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|mark_modified_vars
decl_stmt|,
name|exit_immediately_on_error
decl_stmt|,
name|disallow_filename_globbing
decl_stmt|,
name|locate_commands_in_functions
decl_stmt|,
name|place_keywords_in_env
decl_stmt|,
name|read_but_dont_execute
decl_stmt|,
name|just_one_command
decl_stmt|,
name|unbound_vars_is_error
decl_stmt|,
name|echo_input_at_read
decl_stmt|,
name|echo_command_at_execute
decl_stmt|,
name|lexical_scoping
decl_stmt|,
name|no_invisible_vars
decl_stmt|,
name|noclobber
decl_stmt|,
name|hashing_disabled
decl_stmt|,
name|forced_interactive
decl_stmt|,
name|history_expansion
decl_stmt|,
name|asynchronous_notification
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
modifier|*
name|find_flag
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|change_flag
argument_list|()
decl_stmt|,
name|change_flag_char
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|char
modifier|*
name|which_set_flags
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FLAGS_H */
end_comment

end_unit

