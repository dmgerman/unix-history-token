begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* shell.h -- The data structures used by the shell */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"general.h"
end_include

begin_include
include|#
directive|include
file|"error.h"
end_include

begin_include
include|#
directive|include
file|"variables.h"
end_include

begin_include
include|#
directive|include
file|"quit.h"
end_include

begin_include
include|#
directive|include
file|"maxpath.h"
end_include

begin_include
include|#
directive|include
file|"unwind_prot.h"
end_include

begin_include
include|#
directive|include
file|"command.h"
end_include

begin_decl_stmt
specifier|extern
name|int
name|EOF_Reached
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NO_PIPE
value|-1
end_define

begin_define
define|#
directive|define
name|REDIRECT_BOTH
value|-2
end_define

begin_define
define|#
directive|define
name|IS_DESCRIPTOR
value|-1
end_define

begin_define
define|#
directive|define
name|NO_VARIABLE
value|-1
end_define

begin_comment
comment|/* A bunch of stuff for flow of control using setjmp () and longjmp (). */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_decl_stmt
specifier|extern
name|jmp_buf
name|top_level
decl_stmt|,
name|catch
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NOT_JUMPED
value|0
end_define

begin_comment
comment|/* Not returning from a longjmp. */
end_comment

begin_define
define|#
directive|define
name|FORCE_EOF
value|1
end_define

begin_comment
comment|/* We want to stop parsing. */
end_comment

begin_define
define|#
directive|define
name|DISCARD
value|2
end_define

begin_comment
comment|/* Discard current command. */
end_comment

begin_define
define|#
directive|define
name|EXITPROG
value|3
end_define

begin_comment
comment|/* Unconditionally exit the program now. */
end_comment

begin_comment
comment|/* Values that can be returned by execute_command (). */
end_comment

begin_define
define|#
directive|define
name|EXECUTION_FAILURE
value|1
end_define

begin_define
define|#
directive|define
name|EXECUTION_SUCCESS
value|0
end_define

begin_comment
comment|/* Special exit status used when the shell is asked to execute a    binary file as a shell script. */
end_comment

begin_define
define|#
directive|define
name|EX_BINARY_FILE
value|126
end_define

begin_comment
comment|/* The list of characters that are quoted in double-quotes with a    backslash.  Other characters following a backslash cause nothing    special to happen. */
end_comment

begin_define
define|#
directive|define
name|slashify_in_quotes
value|"\\`$\""
end_define

begin_define
define|#
directive|define
name|slashify_in_here_document
value|"\\`$"
end_define

begin_comment
comment|/* Constants which specify how to handle backslashes and quoting in    expand_word_internal ().  Q_DOUBLE_QUOTES means to use the function    slashify_in_quotes () to decide whether the backslash should be    retained.  Q_HERE_DOCUMENT means slashify_in_here_document () to    decide whether to retain the backslash.  Q_KEEP_BACKSLASH means    to unconditionally retain the backslash. */
end_comment

begin_define
define|#
directive|define
name|Q_DOUBLE_QUOTES
value|0x1
end_define

begin_define
define|#
directive|define
name|Q_HERE_DOCUMENT
value|0x2
end_define

begin_define
define|#
directive|define
name|Q_KEEP_BACKSLASH
value|0x4
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|shell_environment
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|WORD_LIST
modifier|*
name|rest_of_args
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Generalized global variables. */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|executing
decl_stmt|,
name|login_shell
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Structure to pass around that holds a bitmap of file descriptors    to close, and the size of that structure.  Used in execute_cmd.c. */
end_comment

begin_struct
struct|struct
name|fd_bitmap
block|{
name|long
name|size
decl_stmt|;
name|char
modifier|*
name|bitmap
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FD_BITMAP_SIZE
value|32
end_define

end_unit

