begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* fileman.c -- A tiny application which demonstrates how to use the    GNU Readline library.  This application interactively allows users    to manipulate files and their modes. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_FILE_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_UNISTD_H
end_ifdef

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_STRING_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !HAVE_STRING_H */
end_comment

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !HAVE_STRING_H */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STDLIB_H
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|READLINE_LIBRARY
end_ifdef

begin_include
include|#
directive|include
file|"readline.h"
end_include

begin_include
include|#
directive|include
file|"history.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<readline/readline.h>
end_include

begin_include
include|#
directive|include
file|<readline/history.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|char
modifier|*
name|xmalloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* The names of functions that actually do the manipulation. */
end_comment

begin_decl_stmt
name|int
name|com_list
argument_list|()
decl_stmt|,
name|com_view
argument_list|()
decl_stmt|,
name|com_rename
argument_list|()
decl_stmt|,
name|com_stat
argument_list|()
decl_stmt|,
name|com_pwd
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|com_delete
argument_list|()
decl_stmt|,
name|com_help
argument_list|()
decl_stmt|,
name|com_cd
argument_list|()
decl_stmt|,
name|com_quit
argument_list|()
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* A structure which contains information on the commands this program    can understand. */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
modifier|*
name|name
decl_stmt|;
comment|/* User printable name of the function. */
name|Function
modifier|*
name|func
decl_stmt|;
comment|/* Function to call to do the job. */
name|char
modifier|*
name|doc
decl_stmt|;
comment|/* Documentation for this function.  */
block|}
name|COMMAND
typedef|;
end_typedef

begin_decl_stmt
name|COMMAND
name|commands
index|[]
init|=
block|{
block|{
literal|"cd"
block|,
name|com_cd
block|,
literal|"Change to directory DIR"
block|}
block|,
block|{
literal|"delete"
block|,
name|com_delete
block|,
literal|"Delete FILE"
block|}
block|,
block|{
literal|"help"
block|,
name|com_help
block|,
literal|"Display this text"
block|}
block|,
block|{
literal|"?"
block|,
name|com_help
block|,
literal|"Synonym for `help'"
block|}
block|,
block|{
literal|"list"
block|,
name|com_list
block|,
literal|"List files in DIR"
block|}
block|,
block|{
literal|"ls"
block|,
name|com_list
block|,
literal|"Synonym for `list'"
block|}
block|,
block|{
literal|"pwd"
block|,
name|com_pwd
block|,
literal|"Print the current working directory"
block|}
block|,
block|{
literal|"quit"
block|,
name|com_quit
block|,
literal|"Quit using Fileman"
block|}
block|,
block|{
literal|"rename"
block|,
name|com_rename
block|,
literal|"Rename FILE to NEWNAME"
block|}
block|,
block|{
literal|"stat"
block|,
name|com_stat
block|,
literal|"Print out statistics on FILE"
block|}
block|,
block|{
literal|"view"
block|,
name|com_view
block|,
literal|"View the contents of FILE"
block|}
block|,
block|{
operator|(
name|char
operator|*
operator|)
name|NULL
block|,
operator|(
name|Function
operator|*
operator|)
name|NULL
block|,
operator|(
name|char
operator|*
operator|)
name|NULL
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Forward declarations. */
end_comment

begin_function_decl
name|char
modifier|*
name|stripwhite
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|COMMAND
modifier|*
name|find_command
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* The name of this program, as taken from argv[0]. */
end_comment

begin_decl_stmt
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When non-zero, this global means the user is done using this program. */
end_comment

begin_decl_stmt
name|int
name|done
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|dupstr
parameter_list|(
name|s
parameter_list|)
name|char
modifier|*
name|s
decl_stmt|;
block|{
name|char
modifier|*
name|r
decl_stmt|;
name|r
operator|=
name|xmalloc
argument_list|(
name|strlen
argument_list|(
name|s
argument_list|)
operator|+
literal|1
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|r
argument_list|,
name|s
argument_list|)
expr_stmt|;
return|return
operator|(
name|r
operator|)
return|;
block|}
end_function

begin_function
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|char
modifier|*
name|line
decl_stmt|,
modifier|*
name|s
decl_stmt|;
name|progname
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
name|initialize_readline
argument_list|()
expr_stmt|;
comment|/* Bind our completer. */
comment|/* Loop reading and executing lines until the user quits. */
for|for
control|(
init|;
name|done
operator|==
literal|0
condition|;
control|)
block|{
name|line
operator|=
name|readline
argument_list|(
literal|"FileMan: "
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|line
condition|)
break|break;
comment|/* Remove leading and trailing whitespace from the line.          Then, if there is anything left, add it to the history list          and execute it. */
name|s
operator|=
name|stripwhite
argument_list|(
name|line
argument_list|)
expr_stmt|;
if|if
condition|(
operator|*
name|s
condition|)
block|{
name|add_history
argument_list|(
name|s
argument_list|)
expr_stmt|;
name|execute_line
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
name|free
argument_list|(
name|line
argument_list|)
expr_stmt|;
block|}
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Execute a command line. */
end_comment

begin_function
name|int
name|execute_line
parameter_list|(
name|line
parameter_list|)
name|char
modifier|*
name|line
decl_stmt|;
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|COMMAND
modifier|*
name|command
decl_stmt|;
name|char
modifier|*
name|word
decl_stmt|;
comment|/* Isolate the command word. */
name|i
operator|=
literal|0
expr_stmt|;
while|while
condition|(
name|line
index|[
name|i
index|]
operator|&&
name|whitespace
argument_list|(
name|line
index|[
name|i
index|]
argument_list|)
condition|)
name|i
operator|++
expr_stmt|;
name|word
operator|=
name|line
operator|+
name|i
expr_stmt|;
while|while
condition|(
name|line
index|[
name|i
index|]
operator|&&
operator|!
name|whitespace
argument_list|(
name|line
index|[
name|i
index|]
argument_list|)
condition|)
name|i
operator|++
expr_stmt|;
if|if
condition|(
name|line
index|[
name|i
index|]
condition|)
name|line
index|[
name|i
operator|++
index|]
operator|=
literal|'\0'
expr_stmt|;
name|command
operator|=
name|find_command
argument_list|(
name|word
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|command
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: No such command for FileMan.\n"
argument_list|,
name|word
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/* Get argument to command, if any. */
while|while
condition|(
name|whitespace
argument_list|(
name|line
index|[
name|i
index|]
argument_list|)
condition|)
name|i
operator|++
expr_stmt|;
name|word
operator|=
name|line
operator|+
name|i
expr_stmt|;
comment|/* Call the function. */
return|return
operator|(
operator|(
operator|*
operator|(
name|command
operator|->
name|func
operator|)
operator|)
operator|(
name|word
operator|)
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Look up NAME as the name of a command, and return a pointer to that    command.  Return a NULL pointer if NAME isn't a command name. */
end_comment

begin_function
name|COMMAND
modifier|*
name|find_command
parameter_list|(
name|name
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
block|{
specifier|register
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|commands
index|[
name|i
index|]
operator|.
name|name
condition|;
name|i
operator|++
control|)
if|if
condition|(
name|strcmp
argument_list|(
name|name
argument_list|,
name|commands
index|[
name|i
index|]
operator|.
name|name
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
operator|&
name|commands
index|[
name|i
index|]
operator|)
return|;
return|return
operator|(
operator|(
name|COMMAND
operator|*
operator|)
name|NULL
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Strip whitespace from the start and end of STRING.  Return a pointer    into STRING. */
end_comment

begin_function
name|char
modifier|*
name|stripwhite
parameter_list|(
name|string
parameter_list|)
name|char
modifier|*
name|string
decl_stmt|;
block|{
specifier|register
name|char
modifier|*
name|s
decl_stmt|,
modifier|*
name|t
decl_stmt|;
for|for
control|(
name|s
operator|=
name|string
init|;
name|whitespace
argument_list|(
operator|*
name|s
argument_list|)
condition|;
name|s
operator|++
control|)
empty_stmt|;
if|if
condition|(
operator|*
name|s
operator|==
literal|0
condition|)
return|return
operator|(
name|s
operator|)
return|;
name|t
operator|=
name|s
operator|+
name|strlen
argument_list|(
name|s
argument_list|)
operator|-
literal|1
expr_stmt|;
while|while
condition|(
name|t
operator|>
name|s
operator|&&
name|whitespace
argument_list|(
operator|*
name|t
argument_list|)
condition|)
name|t
operator|--
expr_stmt|;
operator|*
operator|++
name|t
operator|=
literal|'\0'
expr_stmt|;
return|return
name|s
return|;
block|}
end_function

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*                                                                  */
end_comment

begin_comment
comment|/*                  Interface to Readline Completion                */
end_comment

begin_comment
comment|/*                                                                  */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_function_decl
name|char
modifier|*
name|command_generator
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
modifier|*
name|fileman_completion
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Tell the GNU Readline library how to complete.  We want to try to complete    on command names if this is the first word in the line, or on filenames    if not. */
end_comment

begin_macro
name|initialize_readline
argument_list|()
end_macro

begin_block
block|{
comment|/* Allow conditional parsing of the ~/.inputrc file. */
name|rl_readline_name
operator|=
literal|"FileMan"
expr_stmt|;
comment|/* Tell the completer that we want a crack first. */
name|rl_attempted_completion_function
operator|=
operator|(
name|CPPFunction
operator|*
operator|)
name|fileman_completion
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Attempt to complete on the contents of TEXT.  START and END bound the    region of rl_line_buffer that contains the word to complete.  TEXT is    the word to complete.  We can use the entire contents of rl_line_buffer    in case we want to do some simple parsing.  Return the array of matches,    or NULL if there aren't any. */
end_comment

begin_function
name|char
modifier|*
modifier|*
name|fileman_completion
parameter_list|(
name|text
parameter_list|,
name|start
parameter_list|,
name|end
parameter_list|)
name|char
modifier|*
name|text
decl_stmt|;
name|int
name|start
decl_stmt|,
name|end
decl_stmt|;
block|{
name|char
modifier|*
modifier|*
name|matches
decl_stmt|;
name|matches
operator|=
operator|(
name|char
operator|*
operator|*
operator|)
name|NULL
expr_stmt|;
comment|/* If this word is at the start of the line, then it is a command      to complete.  Otherwise it is the name of a file in the current      directory. */
if|if
condition|(
name|start
operator|==
literal|0
condition|)
name|matches
operator|=
name|completion_matches
argument_list|(
name|text
argument_list|,
name|command_generator
argument_list|)
expr_stmt|;
return|return
operator|(
name|matches
operator|)
return|;
block|}
end_function

begin_comment
comment|/* Generator function for command completion.  STATE lets us know whether    to start from scratch; without any state (i.e. STATE == 0), then we    start at the top of the list. */
end_comment

begin_function
name|char
modifier|*
name|command_generator
parameter_list|(
name|text
parameter_list|,
name|state
parameter_list|)
name|char
modifier|*
name|text
decl_stmt|;
name|int
name|state
decl_stmt|;
block|{
specifier|static
name|int
name|list_index
decl_stmt|,
name|len
decl_stmt|;
name|char
modifier|*
name|name
decl_stmt|;
comment|/* If this is a new word to complete, initialize now.  This includes      saving the length of TEXT for efficiency, and initializing the index      variable to 0. */
if|if
condition|(
operator|!
name|state
condition|)
block|{
name|list_index
operator|=
literal|0
expr_stmt|;
name|len
operator|=
name|strlen
argument_list|(
name|text
argument_list|)
expr_stmt|;
block|}
comment|/* Return the next name which partially matches from the command list. */
while|while
condition|(
name|name
operator|=
name|commands
index|[
name|list_index
index|]
operator|.
name|name
condition|)
block|{
name|list_index
operator|++
expr_stmt|;
if|if
condition|(
name|strncmp
argument_list|(
name|name
argument_list|,
name|text
argument_list|,
name|len
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|dupstr
argument_list|(
name|name
argument_list|)
operator|)
return|;
block|}
comment|/* If no names matched, then return NULL. */
return|return
operator|(
operator|(
name|char
operator|*
operator|)
name|NULL
operator|)
return|;
block|}
end_function

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/*                                                                  */
end_comment

begin_comment
comment|/*                       FileMan Commands                           */
end_comment

begin_comment
comment|/*                                                                  */
end_comment

begin_comment
comment|/* **************************************************************** */
end_comment

begin_comment
comment|/* String to pass to system ().  This is for the LIST, VIEW and RENAME    commands. */
end_comment

begin_decl_stmt
specifier|static
name|char
name|syscom
index|[
literal|1024
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* List the file(s) named in arg. */
end_comment

begin_macro
name|com_list
argument_list|(
argument|arg
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|arg
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|!
name|arg
condition|)
name|arg
operator|=
literal|""
expr_stmt|;
name|sprintf
argument_list|(
name|syscom
argument_list|,
literal|"ls -FClg %s"
argument_list|,
name|arg
argument_list|)
expr_stmt|;
return|return
operator|(
name|system
argument_list|(
name|syscom
argument_list|)
operator|)
return|;
block|}
end_block

begin_macro
name|com_view
argument_list|(
argument|arg
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|arg
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
operator|!
name|valid_argument
argument_list|(
literal|"view"
argument_list|,
name|arg
argument_list|)
condition|)
return|return
literal|1
return|;
if|#
directive|if
name|defined
argument_list|(
name|__MSDOS__
argument_list|)
comment|/* more.com doesn't grok slashes in pathnames */
name|sprintf
argument_list|(
name|syscom
argument_list|,
literal|"less %s"
argument_list|,
name|arg
argument_list|)
expr_stmt|;
else|#
directive|else
name|sprintf
argument_list|(
name|syscom
argument_list|,
literal|"more %s"
argument_list|,
name|arg
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
name|system
argument_list|(
name|syscom
argument_list|)
operator|)
return|;
block|}
end_block

begin_macro
name|com_rename
argument_list|(
argument|arg
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|arg
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|too_dangerous
argument_list|(
literal|"rename"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

begin_macro
name|com_stat
argument_list|(
argument|arg
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|arg
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|stat
name|finfo
decl_stmt|;
if|if
condition|(
operator|!
name|valid_argument
argument_list|(
literal|"stat"
argument_list|,
name|arg
argument_list|)
condition|)
return|return
operator|(
literal|1
operator|)
return|;
if|if
condition|(
name|stat
argument_list|(
name|arg
argument_list|,
operator|&
name|finfo
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|perror
argument_list|(
name|arg
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
name|printf
argument_list|(
literal|"Statistics for `%s':\n"
argument_list|,
name|arg
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%s has %d link%s, and is %d byte%s in length.\n"
argument_list|,
name|arg
argument_list|,
name|finfo
operator|.
name|st_nlink
argument_list|,
operator|(
name|finfo
operator|.
name|st_nlink
operator|==
literal|1
operator|)
condition|?
literal|""
else|:
literal|"s"
argument_list|,
name|finfo
operator|.
name|st_size
argument_list|,
operator|(
name|finfo
operator|.
name|st_size
operator|==
literal|1
operator|)
condition|?
literal|""
else|:
literal|"s"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"Inode Last Change at: %s"
argument_list|,
name|ctime
argument_list|(
operator|&
name|finfo
operator|.
name|st_ctime
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"      Last access at: %s"
argument_list|,
name|ctime
argument_list|(
operator|&
name|finfo
operator|.
name|st_atime
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"    Last modified at: %s"
argument_list|,
name|ctime
argument_list|(
operator|&
name|finfo
operator|.
name|st_mtime
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_macro
name|com_delete
argument_list|(
argument|arg
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|arg
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|too_dangerous
argument_list|(
literal|"delete"
argument_list|)
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

begin_comment
comment|/* Print out help for ARG, or for all of the commands if ARG is    not present. */
end_comment

begin_macro
name|com_help
argument_list|(
argument|arg
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|arg
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|register
name|int
name|i
decl_stmt|;
name|int
name|printed
init|=
literal|0
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|commands
index|[
name|i
index|]
operator|.
name|name
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|!
operator|*
name|arg
operator|||
operator|(
name|strcmp
argument_list|(
name|arg
argument_list|,
name|commands
index|[
name|i
index|]
operator|.
name|name
argument_list|)
operator|==
literal|0
operator|)
condition|)
block|{
name|printf
argument_list|(
literal|"%s\t\t%s.\n"
argument_list|,
name|commands
index|[
name|i
index|]
operator|.
name|name
argument_list|,
name|commands
index|[
name|i
index|]
operator|.
name|doc
argument_list|)
expr_stmt|;
name|printed
operator|++
expr_stmt|;
block|}
block|}
if|if
condition|(
operator|!
name|printed
condition|)
block|{
name|printf
argument_list|(
literal|"No commands match `%s'.  Possibilties are:\n"
argument_list|,
name|arg
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|commands
index|[
name|i
index|]
operator|.
name|name
condition|;
name|i
operator|++
control|)
block|{
comment|/* Print in six columns. */
if|if
condition|(
name|printed
operator|==
literal|6
condition|)
block|{
name|printed
operator|=
literal|0
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"%s\t"
argument_list|,
name|commands
index|[
name|i
index|]
operator|.
name|name
argument_list|)
expr_stmt|;
name|printed
operator|++
expr_stmt|;
block|}
if|if
condition|(
name|printed
condition|)
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/* Change to the directory ARG. */
end_comment

begin_macro
name|com_cd
argument_list|(
argument|arg
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|arg
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|if
condition|(
name|chdir
argument_list|(
name|arg
argument_list|)
operator|==
operator|-
literal|1
condition|)
block|{
name|perror
argument_list|(
name|arg
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|com_pwd
argument_list|(
literal|""
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/* Print out the current working directory. */
end_comment

begin_macro
name|com_pwd
argument_list|(
argument|ignore
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|ignore
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|char
name|dir
index|[
literal|1024
index|]
decl_stmt|,
modifier|*
name|s
decl_stmt|;
name|s
operator|=
name|getcwd
argument_list|(
name|dir
argument_list|,
sizeof|sizeof
argument_list|(
name|dir
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|s
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Error getting pwd: %s\n"
argument_list|,
name|dir
argument_list|)
expr_stmt|;
return|return
literal|1
return|;
block|}
name|printf
argument_list|(
literal|"Current directory is %s\n"
argument_list|,
name|dir
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_block

begin_comment
comment|/* The user wishes to quit using this program.  Just set DONE non-zero. */
end_comment

begin_macro
name|com_quit
argument_list|(
argument|arg
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|arg
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|done
operator|=
literal|1
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_block

begin_comment
comment|/* Function which tells you that you can't do this. */
end_comment

begin_macro
name|too_dangerous
argument_list|(
argument|caller
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|caller
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Too dangerous for me to distribute.  Write it yourself.\n"
argument_list|,
name|caller
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/* Return non-zero if ARG is a valid argument for CALLER, else print    an error message and return zero. */
end_comment

begin_function
name|int
name|valid_argument
parameter_list|(
name|caller
parameter_list|,
name|arg
parameter_list|)
name|char
modifier|*
name|caller
decl_stmt|,
decl|*
name|arg
decl_stmt|;
end_function

begin_block
block|{
if|if
condition|(
operator|!
name|arg
operator|||
operator|!
operator|*
name|arg
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: Argument required.\n"
argument_list|,
name|caller
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
return|return
operator|(
literal|1
operator|)
return|;
block|}
end_block

end_unit

