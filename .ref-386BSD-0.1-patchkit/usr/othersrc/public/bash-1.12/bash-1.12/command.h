begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* command.h -- The structures used internally to represent commands, and    the extern declarations of the functions used to create them. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|_COMMAND_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|_COMMAND_H
end_define

begin_comment
comment|/* Instructions describing what kind of thing to do for a redirection. */
end_comment

begin_enum
enum|enum
name|r_instruction
block|{
name|r_output_direction
block|,
name|r_input_direction
block|,
name|r_inputa_direction
block|,
name|r_appending_to
block|,
name|r_reading_until
block|,
name|r_duplicating_input
block|,
name|r_duplicating_output
block|,
name|r_deblank_reading_until
block|,
name|r_close_this
block|,
name|r_err_and_out
block|,
name|r_input_output
block|,
name|r_output_force
block|,
name|r_duplicating_input_word
block|,
name|r_duplicating_output_word
block|}
enum|;
end_enum

begin_comment
comment|/* Command Types: */
end_comment

begin_enum
enum|enum
name|command_type
block|{
name|cm_for
block|,
name|cm_case
block|,
name|cm_while
block|,
name|cm_if
block|,
name|cm_simple
block|,
name|cm_connection
block|,
name|cm_function_def
block|,
name|cm_until
block|,
name|cm_group
block|}
enum|;
end_enum

begin_comment
comment|/* A structure which represents a word. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|word_desc
block|{
name|char
modifier|*
name|word
decl_stmt|;
comment|/* Zero terminated string. */
name|int
name|dollar_present
decl_stmt|;
comment|/* Non-zero means dollar sign present. */
name|int
name|quoted
decl_stmt|;
comment|/* Non-zero means single, double, or back quote 			   or backslash is present. */
name|int
name|assignment
decl_stmt|;
comment|/* Non-zero means that this word contains an 			   assignment. */
block|}
name|WORD_DESC
typedef|;
end_typedef

begin_comment
comment|/* A linked list of words. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|word_list
block|{
name|struct
name|word_list
modifier|*
name|next
decl_stmt|;
name|WORD_DESC
modifier|*
name|word
decl_stmt|;
block|}
name|WORD_LIST
typedef|;
end_typedef

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/*			Shell Command Structs			    */
end_comment

begin_comment
comment|/*								    */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* What a redirection descriptor looks like.  If FLAGS is IS_DESCRIPTOR,    then we use REDIRECTEE.DEST, else we use the file specified. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|redirect
block|{
name|struct
name|redirect
modifier|*
name|next
decl_stmt|;
comment|/* Next element, or NULL. */
name|int
name|redirector
decl_stmt|;
comment|/* Descriptor to be redirected. */
name|int
name|flags
decl_stmt|;
comment|/* Flag value for `open'. */
name|enum
name|r_instruction
name|instruction
decl_stmt|;
comment|/* What to do with the information. */
union|union
block|{
name|int
name|dest
decl_stmt|;
comment|/* Place to redirect REDIRECTOR to, or ... */
name|WORD_DESC
modifier|*
name|filename
decl_stmt|;
comment|/* filename to redirect to. */
block|}
name|redirectee
union|;
name|char
modifier|*
name|here_doc_eof
decl_stmt|;
comment|/* The word that appeared in<<foo. */
block|}
name|REDIRECT
typedef|;
end_typedef

begin_comment
comment|/* An element used in parsing.  A single word or a single redirection.    This is an ephemeral construct. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|element
block|{
name|WORD_DESC
modifier|*
name|word
decl_stmt|;
name|REDIRECT
modifier|*
name|redirect
decl_stmt|;
block|}
name|ELEMENT
typedef|;
end_typedef

begin_comment
comment|/* Possible values for command->flags. */
end_comment

begin_define
define|#
directive|define
name|CMD_WANT_SUBSHELL
value|0x01
end_define

begin_comment
comment|/* User wants a subshell: ( command ) */
end_comment

begin_define
define|#
directive|define
name|CMD_FORCE_SUBSHELL
value|0x02
end_define

begin_comment
comment|/* Shell needs to force a subshell. */
end_comment

begin_define
define|#
directive|define
name|CMD_INVERT_RETURN
value|0x04
end_define

begin_comment
comment|/* Invert the exit value. */
end_comment

begin_define
define|#
directive|define
name|CMD_IGNORE_RETURN
value|0x08
end_define

begin_comment
comment|/* Ignore the exit value.  For set -e. */
end_comment

begin_define
define|#
directive|define
name|CMD_NO_FUNCTIONS
value|0x10
end_define

begin_comment
comment|/* Ignore functions during command lookup. */
end_comment

begin_define
define|#
directive|define
name|CMD_INHIBIT_EXPANSION
value|0x20
end_define

begin_comment
comment|/* Do not expand the command words. */
end_comment

begin_comment
comment|/* What a command looks like. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|command
block|{
name|enum
name|command_type
name|type
decl_stmt|;
comment|/* FOR CASE WHILE IF CONNECTION or SIMPLE. */
name|int
name|flags
decl_stmt|;
comment|/* Flags controlling execution environment. */
name|REDIRECT
modifier|*
name|redirects
decl_stmt|;
comment|/* Special redirects for FOR CASE, etc. */
union|union
block|{
name|struct
name|for_com
modifier|*
name|For
decl_stmt|;
name|struct
name|case_com
modifier|*
name|Case
decl_stmt|;
name|struct
name|while_com
modifier|*
name|While
decl_stmt|;
name|struct
name|if_com
modifier|*
name|If
decl_stmt|;
name|struct
name|connection
modifier|*
name|Connection
decl_stmt|;
name|struct
name|simple_com
modifier|*
name|Simple
decl_stmt|;
name|struct
name|function_def
modifier|*
name|Function_def
decl_stmt|;
name|struct
name|group_com
modifier|*
name|Group
decl_stmt|;
block|}
name|value
union|;
block|}
name|COMMAND
typedef|;
end_typedef

begin_comment
comment|/* Structure used to represent the CONNECTION type. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|connection
block|{
name|int
name|ignore
decl_stmt|;
comment|/* Unused; simplifies make_command (). */
name|COMMAND
modifier|*
name|first
decl_stmt|;
comment|/* Pointer to the first command. */
name|COMMAND
modifier|*
name|second
decl_stmt|;
comment|/* Pointer to the second command. */
name|int
name|connector
decl_stmt|;
comment|/* What separates this command from others. */
block|}
name|CONNECTION
typedef|;
end_typedef

begin_comment
comment|/* Structures used to represent the CASE command. */
end_comment

begin_comment
comment|/* Pattern/action structure for CASE_COM. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pattern_list
block|{
name|struct
name|pattern_list
modifier|*
name|next
decl_stmt|;
comment|/* Clause to try in case this one failed. */
name|WORD_LIST
modifier|*
name|patterns
decl_stmt|;
comment|/* Linked list of patterns to test. */
name|COMMAND
modifier|*
name|action
decl_stmt|;
comment|/* Thing to execute if a pattern matches. */
block|}
name|PATTERN_LIST
typedef|;
end_typedef

begin_comment
comment|/* The CASE command. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|case_com
block|{
name|int
name|flags
decl_stmt|;
comment|/* See description of CMD flags. */
name|WORD_DESC
modifier|*
name|word
decl_stmt|;
comment|/* The thing to test. */
name|PATTERN_LIST
modifier|*
name|clauses
decl_stmt|;
comment|/* The clauses to test against, or NULL. */
block|}
name|CASE_COM
typedef|;
end_typedef

begin_comment
comment|/* FOR command. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|for_com
block|{
name|int
name|flags
decl_stmt|;
comment|/* See description of CMD flags. */
name|WORD_DESC
modifier|*
name|name
decl_stmt|;
comment|/* The variable name to get mapped over. */
name|WORD_LIST
modifier|*
name|map_list
decl_stmt|;
comment|/* The things to map over.  This is never NULL. */
name|COMMAND
modifier|*
name|action
decl_stmt|;
comment|/* The action to execute. 			   During execution, NAME is bound to successive 			   members of MAP_LIST. */
block|}
name|FOR_COM
typedef|;
end_typedef

begin_comment
comment|/* IF command. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|if_com
block|{
name|int
name|flags
decl_stmt|;
comment|/* See description of CMD flags. */
name|COMMAND
modifier|*
name|test
decl_stmt|;
comment|/* Thing to test. */
name|COMMAND
modifier|*
name|true_case
decl_stmt|;
comment|/* What to do if the test returned non-zero. */
name|COMMAND
modifier|*
name|false_case
decl_stmt|;
comment|/* What to do if the test returned zero. */
block|}
name|IF_COM
typedef|;
end_typedef

begin_comment
comment|/* WHILE command. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|while_com
block|{
name|int
name|flags
decl_stmt|;
comment|/* See description of CMD flags. */
name|COMMAND
modifier|*
name|test
decl_stmt|;
comment|/* Thing to test. */
name|COMMAND
modifier|*
name|action
decl_stmt|;
comment|/* Thing to do while test is non-zero. */
block|}
name|WHILE_COM
typedef|;
end_typedef

begin_comment
comment|/* The "simple" command.  Just a collection of words and redirects. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|simple_com
block|{
name|int
name|flags
decl_stmt|;
comment|/* See description of CMD flags. */
name|WORD_LIST
modifier|*
name|words
decl_stmt|;
comment|/* The program name, the arguments, 				   variable assignments, etc. */
name|REDIRECT
modifier|*
name|redirects
decl_stmt|;
comment|/* Redirections to perform. */
block|}
name|SIMPLE_COM
typedef|;
end_typedef

begin_comment
comment|/* The "function_def" command.  This isn't really a command, but it is    represented as such for now.  If the function def appears within     `(' `)' the parser tries to set the SUBSHELL bit of the command.  That    means that FUNCTION_DEF has to be run through the executor.  Maybe this    command should be defined in a subshell.  Who knows or cares. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|function_def
block|{
name|int
name|ignore
decl_stmt|;
comment|/* See description of CMD flags. */
name|WORD_DESC
modifier|*
name|name
decl_stmt|;
comment|/* The name of the function. */
name|COMMAND
modifier|*
name|command
decl_stmt|;
comment|/* The parsed execution tree. */
block|}
name|FUNCTION_DEF
typedef|;
end_typedef

begin_comment
comment|/* A command that is `grouped' allows pipes to take effect over    the entire command structure. */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|group_com
block|{
name|int
name|ignore
decl_stmt|;
comment|/* See description of CMD flags. */
name|COMMAND
modifier|*
name|command
decl_stmt|;
block|}
name|GROUP_COM
typedef|;
end_typedef

begin_comment
comment|/* Forward declarations of functions called by the grammer. */
end_comment

begin_function_decl
specifier|extern
name|REDIRECT
modifier|*
name|make_redirection
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|WORD_LIST
modifier|*
name|make_word_list
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|WORD_DESC
modifier|*
name|make_word
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|COMMAND
modifier|*
name|make_for_command
argument_list|()
decl_stmt|,
modifier|*
name|make_case_command
argument_list|()
decl_stmt|,
modifier|*
name|make_if_command
argument_list|()
decl_stmt|,
modifier|*
name|make_while_command
argument_list|()
decl_stmt|,
modifier|*
name|command_connect
argument_list|()
decl_stmt|,
modifier|*
name|make_simple_command
argument_list|()
decl_stmt|,
modifier|*
name|make_function_def
argument_list|()
decl_stmt|,
modifier|*
name|clean_simple_command
argument_list|()
decl_stmt|,
modifier|*
name|make_until_command
argument_list|()
decl_stmt|,
modifier|*
name|make_group_command
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|PATTERN_LIST
modifier|*
name|make_pattern_list
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|COMMAND
modifier|*
name|global_command
decl_stmt|,
modifier|*
name|copy_command
argument_list|()
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _COMMAND_H */
end_comment

end_unit

