begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       main.c
end_comment

begin_comment
comment|/// \brief      main()
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  Author:     Lasse Collin
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|//  This file has been put into the public domain.
end_comment

begin_comment
comment|//  You can do whatever you want with this file.
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_include
include|#
directive|include
file|"private.h"
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_comment
comment|/// Exit status to use. This can be changed with set_exit_status().
end_comment

begin_decl_stmt
specifier|static
name|enum
name|exit_status_type
name|exit_status
init|=
name|E_SUCCESS
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
end_if

begin_comment
comment|/// exit_status has to be protected with a critical section due to
end_comment

begin_comment
comment|/// how "signal handling" is done on Windows. See signals.c for details.
end_comment

begin_decl_stmt
specifier|static
name|CRITICAL_SECTION
name|exit_status_cs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// True if --no-warn is specified. When this is true, we don't set
end_comment

begin_comment
comment|/// the exit status to E_WARNING when something worth a warning happens.
end_comment

begin_decl_stmt
specifier|static
name|bool
name|no_warn
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_function
specifier|extern
name|void
name|set_exit_status
parameter_list|(
name|enum
name|exit_status_type
name|new_status
parameter_list|)
block|{
name|assert
argument_list|(
name|new_status
operator|==
name|E_WARNING
operator|||
name|new_status
operator|==
name|E_ERROR
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
name|EnterCriticalSection
argument_list|(
operator|&
name|exit_status_cs
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|exit_status
operator|!=
name|E_ERROR
condition|)
name|exit_status
operator|=
name|new_status
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
name|LeaveCriticalSection
argument_list|(
operator|&
name|exit_status_cs
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return;
block|}
end_function

begin_function
specifier|extern
name|void
name|set_exit_no_warn
parameter_list|(
name|void
parameter_list|)
block|{
name|no_warn
operator|=
name|true
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|static
specifier|const
name|char
modifier|*
name|read_name
parameter_list|(
specifier|const
name|args_info
modifier|*
name|args
parameter_list|)
block|{
comment|// FIXME: Maybe we should have some kind of memory usage limit here
comment|// like the tool has for the actual compression and decompression.
comment|// Giving some huge text file with --files0 makes us to read the
comment|// whole file in RAM.
specifier|static
name|char
modifier|*
name|name
init|=
name|NULL
decl_stmt|;
specifier|static
name|size_t
name|size
init|=
literal|256
decl_stmt|;
comment|// Allocate the initial buffer. This is never freed, since after it
comment|// is no longer needed, the program exits very soon. It is safe to
comment|// use xmalloc() and xrealloc() in this function, because while
comment|// executing this function, no files are open for writing, and thus
comment|// there's no need to cleanup anything before exiting.
if|if
condition|(
name|name
operator|==
name|NULL
condition|)
name|name
operator|=
name|xmalloc
argument_list|(
name|size
argument_list|)
expr_stmt|;
comment|// Write position in name
name|size_t
name|pos
init|=
literal|0
decl_stmt|;
comment|// Read one character at a time into name.
while|while
condition|(
operator|!
name|user_abort
condition|)
block|{
specifier|const
name|int
name|c
init|=
name|fgetc
argument_list|(
name|args
operator|->
name|files_file
argument_list|)
decl_stmt|;
if|if
condition|(
name|ferror
argument_list|(
name|args
operator|->
name|files_file
argument_list|)
condition|)
block|{
comment|// Take care of EINTR since we have established
comment|// the signal handlers already.
if|if
condition|(
name|errno
operator|==
name|EINTR
condition|)
continue|continue;
name|message_error
argument_list|(
name|_
argument_list|(
literal|"%s: Error reading filenames: %s"
argument_list|)
argument_list|,
name|args
operator|->
name|files_name
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
if|if
condition|(
name|feof
argument_list|(
name|args
operator|->
name|files_file
argument_list|)
condition|)
block|{
if|if
condition|(
name|pos
operator|!=
literal|0
condition|)
name|message_error
argument_list|(
name|_
argument_list|(
literal|"%s: Unexpected end of input "
literal|"when reading filenames"
argument_list|)
argument_list|,
name|args
operator|->
name|files_name
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
if|if
condition|(
name|c
operator|==
name|args
operator|->
name|files_delim
condition|)
block|{
comment|// We allow consecutive newline (--files) or '\0'
comment|// characters (--files0), and ignore such empty
comment|// filenames.
if|if
condition|(
name|pos
operator|==
literal|0
condition|)
continue|continue;
comment|// A non-empty name was read. Terminate it with '\0'
comment|// and return it.
name|name
index|[
name|pos
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
name|name
return|;
block|}
if|if
condition|(
name|c
operator|==
literal|'\0'
condition|)
block|{
comment|// A null character was found when using --files,
comment|// which expects plain text input separated with
comment|// newlines.
name|message_error
argument_list|(
name|_
argument_list|(
literal|"%s: Null character found when "
literal|"reading filenames; maybe you meant "
literal|"to use `--files0' instead "
literal|"of `--files'?"
argument_list|)
argument_list|,
name|args
operator|->
name|files_name
argument_list|)
expr_stmt|;
return|return
name|NULL
return|;
block|}
name|name
index|[
name|pos
operator|++
index|]
operator|=
name|c
expr_stmt|;
comment|// Allocate more memory if needed. There must always be space
comment|// at least for one character to allow terminating the string
comment|// with '\0'.
if|if
condition|(
name|pos
operator|==
name|size
condition|)
block|{
name|size
operator|*=
literal|2
expr_stmt|;
name|name
operator|=
name|xrealloc
argument_list|(
name|name
argument_list|,
name|size
argument_list|)
expr_stmt|;
block|}
block|}
return|return
name|NULL
return|;
block|}
end_function

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
modifier|*
name|argv
parameter_list|)
block|{
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
name|InitializeCriticalSection
argument_list|(
operator|&
name|exit_status_cs
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Set up the progname variable.
name|tuklib_progname_init
argument_list|(
name|argv
argument_list|)
expr_stmt|;
comment|// Initialize the file I/O. This makes sure that
comment|// stdin, stdout, and stderr are something valid.
name|io_init
argument_list|()
expr_stmt|;
comment|// Set up the locale and message translations.
name|tuklib_gettext_init
argument_list|(
name|PACKAGE
argument_list|,
name|LOCALEDIR
argument_list|)
expr_stmt|;
comment|// Initialize handling of error/warning/other messages.
name|message_init
argument_list|()
expr_stmt|;
comment|// Set hardware-dependent default values. These can be overriden
comment|// on the command line, thus this must be done before args_parse().
name|hardware_init
argument_list|()
expr_stmt|;
comment|// Parse the command line arguments and get an array of filenames.
comment|// This doesn't return if something is wrong with the command line
comment|// arguments. If there are no arguments, one filename ("-") is still
comment|// returned to indicate stdin.
name|args_info
name|args
decl_stmt|;
name|args_parse
argument_list|(
operator|&
name|args
argument_list|,
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
if|if
condition|(
name|opt_mode
operator|!=
name|MODE_LIST
operator|&&
name|opt_robot
condition|)
name|message_fatal
argument_list|(
name|_
argument_list|(
literal|"Compression and decompression with --robot "
literal|"are not supported yet."
argument_list|)
argument_list|)
expr_stmt|;
comment|// Tell the message handling code how many input files there are if
comment|// we know it. This way the progress indicator can show it.
if|if
condition|(
name|args
operator|.
name|files_name
operator|!=
name|NULL
condition|)
name|message_set_files
argument_list|(
literal|0
argument_list|)
expr_stmt|;
else|else
name|message_set_files
argument_list|(
name|args
operator|.
name|arg_count
argument_list|)
expr_stmt|;
comment|// Refuse to write compressed data to standard output if it is
comment|// a terminal.
if|if
condition|(
name|opt_mode
operator|==
name|MODE_COMPRESS
condition|)
block|{
if|if
condition|(
name|opt_stdout
operator|||
operator|(
name|args
operator|.
name|arg_count
operator|==
literal|1
operator|&&
name|strcmp
argument_list|(
name|args
operator|.
name|arg_names
index|[
literal|0
index|]
argument_list|,
literal|"-"
argument_list|)
operator|==
literal|0
operator|)
condition|)
block|{
if|if
condition|(
name|is_tty_stdout
argument_list|()
condition|)
block|{
name|message_try_help
argument_list|()
expr_stmt|;
name|tuklib_exit
argument_list|(
name|E_ERROR
argument_list|,
name|E_ERROR
argument_list|,
name|false
argument_list|)
expr_stmt|;
block|}
block|}
block|}
comment|// Set up the signal handlers. We don't need these before we
comment|// start the actual action and not in --list mode, so this is
comment|// done after parsing the command line arguments.
comment|//
comment|// It's good to keep signal handlers in normal compression and
comment|// decompression modes even when only writing to stdout, because
comment|// we might need to restore O_APPEND flag on stdout before exiting.
comment|// In --test mode, signal handlers aren't really needed, but let's
comment|// keep them there for consistency with normal decompression.
if|if
condition|(
name|opt_mode
operator|!=
name|MODE_LIST
condition|)
name|signals_init
argument_list|()
expr_stmt|;
comment|// coder_run() handles compression, decompression, and testing.
comment|// list_file() is for --list.
name|void
function_decl|(
modifier|*
name|run
function_decl|)
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
init|=
name|opt_mode
operator|==
name|MODE_LIST
condition|?
operator|&
name|list_file
operator|:
operator|&
name|coder_run
function_decl|;
comment|// Process the files given on the command line. Note that if no names
comment|// were given, args_parse() gave us a fake "-" filename.
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|args
operator|.
name|arg_count
operator|&&
operator|!
name|user_abort
condition|;
operator|++
name|i
control|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
literal|"-"
argument_list|,
name|args
operator|.
name|arg_names
index|[
name|i
index|]
argument_list|)
operator|==
literal|0
condition|)
block|{
comment|// Processing from stdin to stdout. Check that we
comment|// aren't writing compressed data to a terminal or
comment|// reading it from a terminal.
if|if
condition|(
name|opt_mode
operator|==
name|MODE_COMPRESS
condition|)
block|{
if|if
condition|(
name|is_tty_stdout
argument_list|()
condition|)
continue|continue;
block|}
elseif|else
if|if
condition|(
name|is_tty_stdin
argument_list|()
condition|)
block|{
continue|continue;
block|}
comment|// It doesn't make sense to compress data from stdin
comment|// if we are supposed to read filenames from stdin
comment|// too (enabled with --files or --files0).
if|if
condition|(
name|args
operator|.
name|files_name
operator|==
name|stdin_filename
condition|)
block|{
name|message_error
argument_list|(
name|_
argument_list|(
literal|"Cannot read data from "
literal|"standard input when "
literal|"reading filenames "
literal|"from standard input"
argument_list|)
argument_list|)
expr_stmt|;
continue|continue;
block|}
comment|// Replace the "-" with a special pointer, which is
comment|// recognized by coder_run() and other things.
comment|// This way error messages get a proper filename
comment|// string and the code still knows that it is
comment|// handling the special case of stdin.
name|args
operator|.
name|arg_names
index|[
name|i
index|]
operator|=
operator|(
name|char
operator|*
operator|)
name|stdin_filename
expr_stmt|;
block|}
comment|// Do the actual compression or decompression.
name|run
argument_list|(
name|args
operator|.
name|arg_names
index|[
name|i
index|]
argument_list|)
expr_stmt|;
block|}
comment|// If --files or --files0 was used, process the filenames from the
comment|// given file or stdin. Note that here we don't consider "-" to
comment|// indicate stdin like we do with the command line arguments.
if|if
condition|(
name|args
operator|.
name|files_name
operator|!=
name|NULL
condition|)
block|{
comment|// read_name() checks for user_abort so we don't need to
comment|// check it as loop termination condition.
while|while
condition|(
name|true
condition|)
block|{
specifier|const
name|char
modifier|*
name|name
init|=
name|read_name
argument_list|(
operator|&
name|args
argument_list|)
decl_stmt|;
if|if
condition|(
name|name
operator|==
name|NULL
condition|)
break|break;
comment|// read_name() doesn't return empty names.
name|assert
argument_list|(
name|name
index|[
literal|0
index|]
operator|!=
literal|'\0'
argument_list|)
expr_stmt|;
name|run
argument_list|(
name|name
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|args
operator|.
name|files_name
operator|!=
name|stdin_filename
condition|)
operator|(
name|void
operator|)
name|fclose
argument_list|(
name|args
operator|.
name|files_file
argument_list|)
expr_stmt|;
block|}
comment|// All files have now been handled. If in --list mode, display
comment|// the totals before exiting. We don't have signal handlers
comment|// enabled in --list mode, so we don't need to check user_abort.
if|if
condition|(
name|opt_mode
operator|==
name|MODE_LIST
condition|)
block|{
name|assert
argument_list|(
operator|!
name|user_abort
argument_list|)
expr_stmt|;
name|list_totals
argument_list|()
expr_stmt|;
block|}
ifndef|#
directive|ifndef
name|NDEBUG
name|coder_free
argument_list|()
expr_stmt|;
name|args_free
argument_list|()
expr_stmt|;
endif|#
directive|endif
comment|// If we have got a signal, raise it to kill the program instead
comment|// of calling tuklib_exit().
name|signals_exit
argument_list|()
expr_stmt|;
comment|// Make a local copy of exit_status to keep the Windows code
comment|// thread safe. At this point it is fine if we miss the user
comment|// pressing C-c and don't set the exit_status to E_ERROR on
comment|// Windows.
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
name|EnterCriticalSection
argument_list|(
operator|&
name|exit_status_cs
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|enum
name|exit_status_type
name|es
init|=
name|exit_status
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|_WIN32
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__CYGWIN__
argument_list|)
name|LeaveCriticalSection
argument_list|(
operator|&
name|exit_status_cs
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|// Suppress the exit status indicating a warning if --no-warn
comment|// was specified.
if|if
condition|(
name|es
operator|==
name|E_WARNING
operator|&&
name|no_warn
condition|)
name|es
operator|=
name|E_SUCCESS
expr_stmt|;
name|tuklib_exit
argument_list|(
name|es
argument_list|,
name|E_ERROR
argument_list|,
name|message_verbosity_get
argument_list|()
operator|!=
name|V_SILENT
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

