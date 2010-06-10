begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       message.c
end_comment

begin_comment
comment|/// \brief      Printing messages
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

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_TIME_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_comment
comment|/// Number of the current file
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|int
name|files_pos
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Total number of input files; zero if unknown.
end_comment

begin_decl_stmt
specifier|static
name|unsigned
name|int
name|files_total
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Verbosity level
end_comment

begin_decl_stmt
specifier|static
name|enum
name|message_verbosity
name|verbosity
init|=
name|V_WARNING
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Filename which we will print with the verbose messages
end_comment

begin_decl_stmt
specifier|static
specifier|const
name|char
modifier|*
name|filename
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// True once the a filename has been printed to stderr as part of progress
end_comment

begin_comment
comment|/// message. If automatic progress updating isn't enabled, this becomes true
end_comment

begin_comment
comment|/// after the first progress message has been printed due to user sending
end_comment

begin_comment
comment|/// SIGINFO, SIGUSR1, or SIGALRM. Once this variable is true, we will print
end_comment

begin_comment
comment|/// an empty line before the next filename to make the output more readable.
end_comment

begin_decl_stmt
specifier|static
name|bool
name|first_filename_printed
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// This is set to true when we have printed the current filename to stderr
end_comment

begin_comment
comment|/// as part of a progress message. This variable is useful only if not
end_comment

begin_comment
comment|/// updating progress automatically: if user sends many SIGINFO, SIGUSR1, or
end_comment

begin_comment
comment|/// SIGALRM signals, we won't print the name of the same file multiple times.
end_comment

begin_decl_stmt
specifier|static
name|bool
name|current_filename_printed
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// True if we should print progress indicator and update it automatically
end_comment

begin_comment
comment|/// if also verbose>= V_VERBOSE.
end_comment

begin_decl_stmt
specifier|static
name|bool
name|progress_automatic
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// True if message_progress_start() has been called but
end_comment

begin_comment
comment|/// message_progress_end() hasn't been called yet.
end_comment

begin_decl_stmt
specifier|static
name|bool
name|progress_started
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// This is true when a progress message was printed and the cursor is still
end_comment

begin_comment
comment|/// on the same line with the progress message. In that case, a newline has
end_comment

begin_comment
comment|/// to be printed before any error messages.
end_comment

begin_decl_stmt
specifier|static
name|bool
name|progress_active
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Pointer to lzma_stream used to do the encoding or decoding.
end_comment

begin_decl_stmt
specifier|static
name|lzma_stream
modifier|*
name|progress_strm
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Expected size of the input stream is needed to show completion percentage
end_comment

begin_comment
comment|/// and estimate remaining time.
end_comment

begin_decl_stmt
specifier|static
name|uint64_t
name|expected_in_size
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Time when we started processing the file
end_comment

begin_decl_stmt
specifier|static
name|uint64_t
name|start_time
decl_stmt|;
end_decl_stmt

begin_comment
comment|// Use alarm() and SIGALRM when they are supported. This has two minor
end_comment

begin_comment
comment|// advantages over the alternative of polling gettimeofday():
end_comment

begin_comment
comment|//  - It is possible for the user to send SIGINFO, SIGUSR1, or SIGALRM to
end_comment

begin_comment
comment|//    get intermediate progress information even when --verbose wasn't used
end_comment

begin_comment
comment|//    or stderr is not a terminal.
end_comment

begin_comment
comment|//  - alarm() + SIGALRM seems to have slightly less overhead than polling
end_comment

begin_comment
comment|//    gettimeofday().
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SIGALRM
end_ifdef

begin_comment
comment|/// The signal handler for SIGALRM sets this to true. It is set back to false
end_comment

begin_comment
comment|/// once the progress message has been updated.
end_comment

begin_decl_stmt
specifier|static
specifier|volatile
name|sig_atomic_t
name|progress_needs_updating
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Signal handler for SIGALRM
end_comment

begin_decl_stmt
specifier|static
name|void
name|progress_signal_handler
argument_list|(
name|int
name|sig
name|lzma_attribute
argument_list|(
operator|(
name|unused
operator|)
argument_list|)
argument_list|)
block|{
name|progress_needs_updating
operator|=
name|true
expr_stmt|;
return|return;
block|}
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/// This is true when progress message printing is wanted. Using the same
end_comment

begin_comment
comment|/// variable name as above to avoid some ifdefs.
end_comment

begin_decl_stmt
specifier|static
name|bool
name|progress_needs_updating
init|=
name|false
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// Elapsed time when the next progress message update should be done.
end_comment

begin_decl_stmt
specifier|static
name|uint64_t
name|progress_next_update
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/// Get the current time as microseconds since epoch
end_comment

begin_function
specifier|static
name|uint64_t
name|my_time
parameter_list|(
name|void
parameter_list|)
block|{
name|struct
name|timeval
name|tv
decl_stmt|;
name|gettimeofday
argument_list|(
operator|&
name|tv
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return
call|(
name|uint64_t
call|)
argument_list|(
name|tv
operator|.
name|tv_sec
argument_list|)
operator|*
name|UINT64_C
argument_list|(
literal|1000000
argument_list|)
operator|+
name|tv
operator|.
name|tv_usec
return|;
block|}
end_function

begin_function
specifier|extern
name|void
name|message_init
parameter_list|(
name|void
parameter_list|)
block|{
comment|// If --verbose is used, we use a progress indicator if and only
comment|// if stderr is a terminal. If stderr is not a terminal, we print
comment|// verbose information only after finishing the file. As a special
comment|// exception, even if --verbose was not used, user can send SIGALRM
comment|// to make us print progress information once without automatic
comment|// updating.
name|progress_automatic
operator|=
name|isatty
argument_list|(
name|STDERR_FILENO
argument_list|)
expr_stmt|;
comment|// Commented out because COLUMNS is rarely exported to environment.
comment|// Most users have at least 80 columns anyway, let's think something
comment|// fancy here if enough people complain.
comment|/* 	if (progress_automatic) { 		// stderr is a terminal. Check the COLUMNS environment 		// variable to see if the terminal is wide enough. If COLUMNS 		// doesn't exist or it has some unparsable value, we assume 		// that the terminal is wide enough. 		const char *columns_str = getenv("COLUMNS"); 		if (columns_str != NULL) { 			char *endptr; 			const long columns = strtol(columns_str,&endptr, 10); 			if (*endptr != '\0' || columns< 80) 				progress_automatic = false; 		} 	} */
ifdef|#
directive|ifdef
name|SIGALRM
comment|// At least DJGPP lacks SA_RESTART. It's not essential for us (the
comment|// rest of the code can handle interrupted system calls), so just
comment|// define it zero.
ifndef|#
directive|ifndef
name|SA_RESTART
define|#
directive|define
name|SA_RESTART
value|0
endif|#
directive|endif
comment|// Establish the signal handlers which set a flag to tell us that
comment|// progress info should be updated. Since these signals don't
comment|// require any quick action, we set SA_RESTART.
specifier|static
specifier|const
name|int
name|sigs
index|[]
init|=
block|{
ifdef|#
directive|ifdef
name|SIGALRM
name|SIGALRM
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SIGINFO
name|SIGINFO
block|,
endif|#
directive|endif
ifdef|#
directive|ifdef
name|SIGUSR1
name|SIGUSR1
block|,
endif|#
directive|endif
block|}
decl_stmt|;
name|struct
name|sigaction
name|sa
decl_stmt|;
name|sigemptyset
argument_list|(
operator|&
name|sa
operator|.
name|sa_mask
argument_list|)
expr_stmt|;
name|sa
operator|.
name|sa_flags
operator|=
name|SA_RESTART
expr_stmt|;
name|sa
operator|.
name|sa_handler
operator|=
operator|&
name|progress_signal_handler
expr_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|i
operator|<
name|ARRAY_SIZE
argument_list|(
name|sigs
argument_list|)
condition|;
operator|++
name|i
control|)
if|if
condition|(
name|sigaction
argument_list|(
name|sigs
index|[
name|i
index|]
argument_list|,
operator|&
name|sa
argument_list|,
name|NULL
argument_list|)
condition|)
name|message_signal_handler
argument_list|()
expr_stmt|;
endif|#
directive|endif
return|return;
block|}
end_function

begin_function
specifier|extern
name|void
name|message_verbosity_increase
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|verbosity
operator|<
name|V_DEBUG
condition|)
operator|++
name|verbosity
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|extern
name|void
name|message_verbosity_decrease
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|verbosity
operator|>
name|V_SILENT
condition|)
operator|--
name|verbosity
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|extern
name|enum
name|message_verbosity
name|message_verbosity_get
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|verbosity
return|;
block|}
end_function

begin_function
specifier|extern
name|void
name|message_set_files
parameter_list|(
name|unsigned
name|int
name|files
parameter_list|)
block|{
name|files_total
operator|=
name|files
expr_stmt|;
return|return;
block|}
end_function

begin_comment
comment|/// Prints the name of the current file if it hasn't been printed already,
end_comment

begin_comment
comment|/// except if we are processing exactly one stream from stdin to stdout.
end_comment

begin_comment
comment|/// I think it looks nicer to not print "(stdin)" when --verbose is used
end_comment

begin_comment
comment|/// in a pipe and no other files are processed.
end_comment

begin_function
specifier|static
name|void
name|print_filename
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|files_total
operator|!=
literal|1
operator|||
name|filename
operator|!=
name|stdin_filename
condition|)
block|{
name|signals_block
argument_list|()
expr_stmt|;
name|FILE
modifier|*
name|file
init|=
name|opt_mode
operator|==
name|MODE_LIST
condition|?
name|stdout
else|:
name|stderr
decl_stmt|;
comment|// If a file was already processed, put an empty line
comment|// before the next filename to improve readability.
if|if
condition|(
name|first_filename_printed
condition|)
name|fputc
argument_list|(
literal|'\n'
argument_list|,
name|file
argument_list|)
expr_stmt|;
name|first_filename_printed
operator|=
name|true
expr_stmt|;
name|current_filename_printed
operator|=
name|true
expr_stmt|;
comment|// If we don't know how many files there will be due
comment|// to usage of --files or --files0.
if|if
condition|(
name|files_total
operator|==
literal|0
condition|)
name|fprintf
argument_list|(
name|file
argument_list|,
literal|"%s (%u)\n"
argument_list|,
name|filename
argument_list|,
name|files_pos
argument_list|)
expr_stmt|;
else|else
name|fprintf
argument_list|(
name|file
argument_list|,
literal|"%s (%u/%u)\n"
argument_list|,
name|filename
argument_list|,
name|files_pos
argument_list|,
name|files_total
argument_list|)
expr_stmt|;
name|signals_unblock
argument_list|()
expr_stmt|;
block|}
return|return;
block|}
end_function

begin_function
specifier|extern
name|void
name|message_filename
parameter_list|(
specifier|const
name|char
modifier|*
name|src_name
parameter_list|)
block|{
comment|// Start numbering the files starting from one.
operator|++
name|files_pos
expr_stmt|;
name|filename
operator|=
name|src_name
expr_stmt|;
if|if
condition|(
name|verbosity
operator|>=
name|V_VERBOSE
operator|&&
operator|(
name|progress_automatic
operator|||
name|opt_mode
operator|==
name|MODE_LIST
operator|)
condition|)
name|print_filename
argument_list|()
expr_stmt|;
else|else
name|current_filename_printed
operator|=
name|false
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|extern
name|void
name|message_progress_start
parameter_list|(
name|lzma_stream
modifier|*
name|strm
parameter_list|,
name|uint64_t
name|in_size
parameter_list|)
block|{
comment|// Store the pointer to the lzma_stream used to do the coding.
comment|// It is needed to find out the position in the stream.
name|progress_strm
operator|=
name|strm
expr_stmt|;
comment|// Store the processing start time of the file and its expected size.
comment|// If we aren't printing any statistics, then these are unused. But
comment|// since it is possible that the user sends us a signal to show
comment|// statistics, we need to have these available anyway.
name|start_time
operator|=
name|my_time
argument_list|()
expr_stmt|;
name|expected_in_size
operator|=
name|in_size
expr_stmt|;
comment|// Indicate that progress info may need to be printed before
comment|// printing error messages.
name|progress_started
operator|=
name|true
expr_stmt|;
comment|// If progress indicator is wanted, print the filename and possibly
comment|// the file count now.
if|if
condition|(
name|verbosity
operator|>=
name|V_VERBOSE
operator|&&
name|progress_automatic
condition|)
block|{
comment|// Start the timer to display the first progress message
comment|// after one second. An alternative would be to show the
comment|// first message almost immediately, but delaying by one
comment|// second looks better to me, since extremely early
comment|// progress info is pretty much useless.
ifdef|#
directive|ifdef
name|SIGALRM
comment|// First disable a possibly existing alarm.
name|alarm
argument_list|(
literal|0
argument_list|)
expr_stmt|;
name|progress_needs_updating
operator|=
name|false
expr_stmt|;
name|alarm
argument_list|(
literal|1
argument_list|)
expr_stmt|;
else|#
directive|else
name|progress_needs_updating
operator|=
name|true
expr_stmt|;
name|progress_next_update
operator|=
literal|1000000
expr_stmt|;
endif|#
directive|endif
block|}
return|return;
block|}
end_function

begin_comment
comment|/// Make the string indicating completion percentage.
end_comment

begin_function
specifier|static
specifier|const
name|char
modifier|*
name|progress_percentage
parameter_list|(
name|uint64_t
name|in_pos
parameter_list|)
block|{
comment|// If the size of the input file is unknown or the size told us is
comment|// clearly wrong since we have processed more data than the alleged
comment|// size of the file, show a static string indicating that we have
comment|// no idea of the completion percentage.
if|if
condition|(
name|expected_in_size
operator|==
literal|0
operator|||
name|in_pos
operator|>
name|expected_in_size
condition|)
return|return
literal|"--- %"
return|;
comment|// Never show 100.0 % before we actually are finished.
name|double
name|percentage
init|=
call|(
name|double
call|)
argument_list|(
name|in_pos
argument_list|)
operator|/
call|(
name|double
call|)
argument_list|(
name|expected_in_size
argument_list|)
operator|*
literal|99.9
decl_stmt|;
specifier|static
name|char
name|buf
index|[
sizeof|sizeof
argument_list|(
literal|"99.9 %"
argument_list|)
index|]
decl_stmt|;
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%.1f %%"
argument_list|,
name|percentage
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
block|}
end_function

begin_comment
comment|/// Make the string containing the amount of input processed, amount of
end_comment

begin_comment
comment|/// output produced, and the compression ratio.
end_comment

begin_function
specifier|static
specifier|const
name|char
modifier|*
name|progress_sizes
parameter_list|(
name|uint64_t
name|compressed_pos
parameter_list|,
name|uint64_t
name|uncompressed_pos
parameter_list|,
name|bool
name|final
parameter_list|)
block|{
comment|// This is enough to hold sizes up to about 99 TiB if thousand
comment|// separator is used, or about 1 PiB without thousand separator.
comment|// After that the progress indicator will look a bit silly, since
comment|// the compression ratio no longer fits with three decimal places.
specifier|static
name|char
name|buf
index|[
literal|36
index|]
decl_stmt|;
name|char
modifier|*
name|pos
init|=
name|buf
decl_stmt|;
name|size_t
name|left
init|=
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
decl_stmt|;
comment|// Print the sizes. If this the final message, use more reasonable
comment|// units than MiB if the file was small.
specifier|const
name|enum
name|nicestr_unit
name|unit_min
init|=
name|final
condition|?
name|NICESTR_B
else|:
name|NICESTR_MIB
decl_stmt|;
name|my_snprintf
argument_list|(
operator|&
name|pos
argument_list|,
operator|&
name|left
argument_list|,
literal|"%s / %s"
argument_list|,
name|uint64_to_nicestr
argument_list|(
name|compressed_pos
argument_list|,
name|unit_min
argument_list|,
name|NICESTR_TIB
argument_list|,
name|false
argument_list|,
literal|0
argument_list|)
argument_list|,
name|uint64_to_nicestr
argument_list|(
name|uncompressed_pos
argument_list|,
name|unit_min
argument_list|,
name|NICESTR_TIB
argument_list|,
name|false
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
comment|// Avoid division by zero. If we cannot calculate the ratio, set
comment|// it to some nice number greater than 10.0 so that it gets caught
comment|// in the next if-clause.
specifier|const
name|double
name|ratio
init|=
name|uncompressed_pos
operator|>
literal|0
condition|?
call|(
name|double
call|)
argument_list|(
name|compressed_pos
argument_list|)
operator|/
call|(
name|double
call|)
argument_list|(
name|uncompressed_pos
argument_list|)
else|:
literal|16.0
decl_stmt|;
comment|// If the ratio is very bad, just indicate that it is greater than
comment|// 9.999. This way the length of the ratio field stays fixed.
if|if
condition|(
name|ratio
operator|>
literal|9.999
condition|)
name|snprintf
argument_list|(
name|pos
argument_list|,
name|left
argument_list|,
literal|"> %.3f"
argument_list|,
literal|9.999
argument_list|)
expr_stmt|;
else|else
name|snprintf
argument_list|(
name|pos
argument_list|,
name|left
argument_list|,
literal|" = %.3f"
argument_list|,
name|ratio
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
block|}
end_function

begin_comment
comment|/// Make the string containing the processing speed of uncompressed data.
end_comment

begin_function
specifier|static
specifier|const
name|char
modifier|*
name|progress_speed
parameter_list|(
name|uint64_t
name|uncompressed_pos
parameter_list|,
name|uint64_t
name|elapsed
parameter_list|)
block|{
comment|// Don't print the speed immediately, since the early values look
comment|// somewhat random.
if|if
condition|(
name|elapsed
operator|<
literal|3000000
condition|)
return|return
literal|""
return|;
specifier|static
specifier|const
name|char
name|unit
index|[]
index|[
literal|8
index|]
init|=
block|{
literal|"KiB/s"
block|,
literal|"MiB/s"
block|,
literal|"GiB/s"
block|, 	}
decl_stmt|;
name|size_t
name|unit_index
init|=
literal|0
decl_stmt|;
comment|// Calculate the speed as KiB/s.
name|double
name|speed
init|=
call|(
name|double
call|)
argument_list|(
name|uncompressed_pos
argument_list|)
operator|/
operator|(
call|(
name|double
call|)
argument_list|(
name|elapsed
argument_list|)
operator|*
operator|(
literal|1024.0
operator|/
literal|1e6
operator|)
operator|)
decl_stmt|;
comment|// Adjust the unit of the speed if needed.
while|while
condition|(
name|speed
operator|>
literal|999.0
condition|)
block|{
name|speed
operator|/=
literal|1024.0
expr_stmt|;
if|if
condition|(
operator|++
name|unit_index
operator|==
name|ARRAY_SIZE
argument_list|(
name|unit
argument_list|)
condition|)
return|return
literal|""
return|;
comment|// Way too fast ;-)
block|}
comment|// Use decimal point only if the number is small. Examples:
comment|//  - 0.1 KiB/s
comment|//  - 9.9 KiB/s
comment|//  - 99 KiB/s
comment|//  - 999 KiB/s
specifier|static
name|char
name|buf
index|[
sizeof|sizeof
argument_list|(
literal|"999 GiB/s"
argument_list|)
index|]
decl_stmt|;
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%.*f %s"
argument_list|,
name|speed
operator|>
literal|9.9
condition|?
literal|0
else|:
literal|1
argument_list|,
name|speed
argument_list|,
name|unit
index|[
name|unit_index
index|]
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
block|}
end_function

begin_comment
comment|/// Make a string indicating elapsed or remaining time. The format is either
end_comment

begin_comment
comment|/// M:SS or H:MM:SS depending on if the time is an hour or more.
end_comment

begin_function
specifier|static
specifier|const
name|char
modifier|*
name|progress_time
parameter_list|(
name|uint64_t
name|useconds
parameter_list|)
block|{
comment|// 9999 hours = 416 days
specifier|static
name|char
name|buf
index|[
sizeof|sizeof
argument_list|(
literal|"9999:59:59"
argument_list|)
index|]
decl_stmt|;
name|uint32_t
name|seconds
init|=
name|useconds
operator|/
literal|1000000
decl_stmt|;
comment|// Don't show anything if the time is zero or ridiculously big.
if|if
condition|(
name|seconds
operator|==
literal|0
operator|||
name|seconds
operator|>
operator|(
operator|(
literal|9999
operator|*
literal|60
operator|)
operator|+
literal|59
operator|)
operator|*
literal|60
operator|+
literal|59
condition|)
return|return
literal|""
return|;
name|uint32_t
name|minutes
init|=
name|seconds
operator|/
literal|60
decl_stmt|;
name|seconds
operator|%=
literal|60
expr_stmt|;
if|if
condition|(
name|minutes
operator|>=
literal|60
condition|)
block|{
specifier|const
name|uint32_t
name|hours
init|=
name|minutes
operator|/
literal|60
decl_stmt|;
name|minutes
operator|%=
literal|60
expr_stmt|;
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%"
name|PRIu32
literal|":%02"
name|PRIu32
literal|":%02"
name|PRIu32
argument_list|,
name|hours
argument_list|,
name|minutes
argument_list|,
name|seconds
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%"
name|PRIu32
literal|":%02"
name|PRIu32
argument_list|,
name|minutes
argument_list|,
name|seconds
argument_list|)
expr_stmt|;
block|}
return|return
name|buf
return|;
block|}
end_function

begin_comment
comment|/// Return a string containing estimated remaining time when
end_comment

begin_comment
comment|/// reasonably possible.
end_comment

begin_function
specifier|static
specifier|const
name|char
modifier|*
name|progress_remaining
parameter_list|(
name|uint64_t
name|in_pos
parameter_list|,
name|uint64_t
name|elapsed
parameter_list|)
block|{
comment|// Don't show the estimated remaining time when it wouldn't
comment|// make sense:
comment|//  - Input size is unknown.
comment|//  - Input has grown bigger since we started (de)compressing.
comment|//  - We haven't processed much data yet, so estimate would be
comment|//    too inaccurate.
comment|//  - Only a few seconds has passed since we started (de)compressing,
comment|//    so estimate would be too inaccurate.
if|if
condition|(
name|expected_in_size
operator|==
literal|0
operator|||
name|in_pos
operator|>
name|expected_in_size
operator|||
name|in_pos
operator|<
operator|(
name|UINT64_C
argument_list|(
literal|1
argument_list|)
operator|<<
literal|19
operator|)
operator|||
name|elapsed
operator|<
literal|8000000
condition|)
return|return
literal|""
return|;
comment|// Calculate the estimate. Don't give an estimate of zero seconds,
comment|// since it is possible that all the input has been already passed
comment|// to the library, but there is still quite a bit of output pending.
name|uint32_t
name|remaining
init|=
call|(
name|double
call|)
argument_list|(
name|expected_in_size
operator|-
name|in_pos
argument_list|)
operator|*
operator|(
call|(
name|double
call|)
argument_list|(
name|elapsed
argument_list|)
operator|/
literal|1e6
operator|)
operator|/
call|(
name|double
call|)
argument_list|(
name|in_pos
argument_list|)
decl_stmt|;
if|if
condition|(
name|remaining
operator|<
literal|1
condition|)
name|remaining
operator|=
literal|1
expr_stmt|;
specifier|static
name|char
name|buf
index|[
sizeof|sizeof
argument_list|(
literal|"9 h 55 min"
argument_list|)
index|]
decl_stmt|;
comment|// Select appropriate precision for the estimated remaining time.
if|if
condition|(
name|remaining
operator|<=
literal|10
condition|)
block|{
comment|// A maximum of 10 seconds remaining.
comment|// Show the number of seconds as is.
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%"
name|PRIu32
literal|" s"
argument_list|,
name|remaining
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|remaining
operator|<=
literal|50
condition|)
block|{
comment|// A maximum of 50 seconds remaining.
comment|// Round up to the next multiple of five seconds.
name|remaining
operator|=
operator|(
name|remaining
operator|+
literal|4
operator|)
operator|/
literal|5
operator|*
literal|5
expr_stmt|;
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%"
name|PRIu32
literal|" s"
argument_list|,
name|remaining
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|remaining
operator|<=
literal|590
condition|)
block|{
comment|// A maximum of 9 minutes and 50 seconds remaining.
comment|// Round up to the next multiple of ten seconds.
name|remaining
operator|=
operator|(
name|remaining
operator|+
literal|9
operator|)
operator|/
literal|10
operator|*
literal|10
expr_stmt|;
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%"
name|PRIu32
literal|" min %"
name|PRIu32
literal|" s"
argument_list|,
name|remaining
operator|/
literal|60
argument_list|,
name|remaining
operator|%
literal|60
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|remaining
operator|<=
literal|59
operator|*
literal|60
condition|)
block|{
comment|// A maximum of 59 minutes remaining.
comment|// Round up to the next multiple of a minute.
name|remaining
operator|=
operator|(
name|remaining
operator|+
literal|59
operator|)
operator|/
literal|60
expr_stmt|;
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%"
name|PRIu32
literal|" min"
argument_list|,
name|remaining
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|remaining
operator|<=
literal|9
operator|*
literal|3600
operator|+
literal|50
operator|*
literal|60
condition|)
block|{
comment|// A maximum of 9 hours and 50 minutes left.
comment|// Round up to the next multiple of ten minutes.
name|remaining
operator|=
operator|(
name|remaining
operator|+
literal|599
operator|)
operator|/
literal|600
operator|*
literal|10
expr_stmt|;
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%"
name|PRIu32
literal|" h %"
name|PRIu32
literal|" min"
argument_list|,
name|remaining
operator|/
literal|60
argument_list|,
name|remaining
operator|%
literal|60
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|remaining
operator|<=
literal|23
operator|*
literal|3600
condition|)
block|{
comment|// A maximum of 23 hours remaining.
comment|// Round up to the next multiple of an hour.
name|remaining
operator|=
operator|(
name|remaining
operator|+
literal|3599
operator|)
operator|/
literal|3600
expr_stmt|;
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%"
name|PRIu32
literal|" h"
argument_list|,
name|remaining
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|remaining
operator|<=
literal|9
operator|*
literal|24
operator|*
literal|3600
operator|+
literal|23
operator|*
literal|3600
condition|)
block|{
comment|// A maximum of 9 days and 23 hours remaining.
comment|// Round up to the next multiple of an hour.
name|remaining
operator|=
operator|(
name|remaining
operator|+
literal|3599
operator|)
operator|/
literal|3600
expr_stmt|;
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%"
name|PRIu32
literal|" d %"
name|PRIu32
literal|" h"
argument_list|,
name|remaining
operator|/
literal|24
argument_list|,
name|remaining
operator|%
literal|24
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|remaining
operator|<=
literal|999
operator|*
literal|24
operator|*
literal|3600
condition|)
block|{
comment|// A maximum of 999 days remaining. ;-)
comment|// Round up to the next multiple of a day.
name|remaining
operator|=
operator|(
name|remaining
operator|+
literal|24
operator|*
literal|3600
operator|-
literal|1
operator|)
operator|/
operator|(
literal|24
operator|*
literal|3600
operator|)
expr_stmt|;
name|snprintf
argument_list|(
name|buf
argument_list|,
sizeof|sizeof
argument_list|(
name|buf
argument_list|)
argument_list|,
literal|"%"
name|PRIu32
literal|" d"
argument_list|,
name|remaining
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// The estimated remaining time is too big. Don't show it.
return|return
literal|""
return|;
block|}
return|return
name|buf
return|;
block|}
end_function

begin_comment
comment|/// Calculate the elapsed time as microseconds.
end_comment

begin_function
specifier|static
name|uint64_t
name|progress_elapsed
parameter_list|(
name|void
parameter_list|)
block|{
return|return
name|my_time
argument_list|()
operator|-
name|start_time
return|;
block|}
end_function

begin_comment
comment|/// Get information about position in the stream. This is currently simple,
end_comment

begin_comment
comment|/// but it will become more complicated once we have multithreading support.
end_comment

begin_function
specifier|static
name|void
name|progress_pos
parameter_list|(
name|uint64_t
modifier|*
name|in_pos
parameter_list|,
name|uint64_t
modifier|*
name|compressed_pos
parameter_list|,
name|uint64_t
modifier|*
name|uncompressed_pos
parameter_list|)
block|{
operator|*
name|in_pos
operator|=
name|progress_strm
operator|->
name|total_in
expr_stmt|;
if|if
condition|(
name|opt_mode
operator|==
name|MODE_COMPRESS
condition|)
block|{
operator|*
name|compressed_pos
operator|=
name|progress_strm
operator|->
name|total_out
expr_stmt|;
operator|*
name|uncompressed_pos
operator|=
name|progress_strm
operator|->
name|total_in
expr_stmt|;
block|}
else|else
block|{
operator|*
name|compressed_pos
operator|=
name|progress_strm
operator|->
name|total_in
expr_stmt|;
operator|*
name|uncompressed_pos
operator|=
name|progress_strm
operator|->
name|total_out
expr_stmt|;
block|}
return|return;
block|}
end_function

begin_function
specifier|extern
name|void
name|message_progress_update
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
operator|!
name|progress_needs_updating
condition|)
return|return;
comment|// Calculate how long we have been processing this file.
specifier|const
name|uint64_t
name|elapsed
init|=
name|progress_elapsed
argument_list|()
decl_stmt|;
ifndef|#
directive|ifndef
name|SIGALRM
if|if
condition|(
name|progress_next_update
operator|>
name|elapsed
condition|)
return|return;
name|progress_next_update
operator|=
name|elapsed
operator|+
literal|1000000
expr_stmt|;
endif|#
directive|endif
comment|// Get our current position in the stream.
name|uint64_t
name|in_pos
decl_stmt|;
name|uint64_t
name|compressed_pos
decl_stmt|;
name|uint64_t
name|uncompressed_pos
decl_stmt|;
name|progress_pos
argument_list|(
operator|&
name|in_pos
argument_list|,
operator|&
name|compressed_pos
argument_list|,
operator|&
name|uncompressed_pos
argument_list|)
expr_stmt|;
comment|// Block signals so that fprintf() doesn't get interrupted.
name|signals_block
argument_list|()
expr_stmt|;
comment|// Print the filename if it hasn't been printed yet.
if|if
condition|(
operator|!
name|current_filename_printed
condition|)
name|print_filename
argument_list|()
expr_stmt|;
comment|// Print the actual progress message. The idea is that there is at
comment|// least three spaces between the fields in typical situations, but
comment|// even in rare situations there is at least one space.
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\r %6s %35s   %9s %10s   %10s\r"
argument_list|,
name|progress_percentage
argument_list|(
name|in_pos
argument_list|)
argument_list|,
name|progress_sizes
argument_list|(
name|compressed_pos
argument_list|,
name|uncompressed_pos
argument_list|,
name|false
argument_list|)
argument_list|,
name|progress_speed
argument_list|(
name|uncompressed_pos
argument_list|,
name|elapsed
argument_list|)
argument_list|,
name|progress_time
argument_list|(
name|elapsed
argument_list|)
argument_list|,
name|progress_remaining
argument_list|(
name|in_pos
argument_list|,
name|elapsed
argument_list|)
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|SIGALRM
comment|// Updating the progress info was finished. Reset
comment|// progress_needs_updating to wait for the next SIGALRM.
comment|//
comment|// NOTE: This has to be done before alarm(1) or with (very) bad
comment|// luck we could be setting this to false after the alarm has already
comment|// been triggered.
name|progress_needs_updating
operator|=
name|false
expr_stmt|;
if|if
condition|(
name|verbosity
operator|>=
name|V_VERBOSE
operator|&&
name|progress_automatic
condition|)
block|{
comment|// Mark that the progress indicator is active, so if an error
comment|// occurs, the error message gets printed cleanly.
name|progress_active
operator|=
name|true
expr_stmt|;
comment|// Restart the timer so that progress_needs_updating gets
comment|// set to true after about one second.
name|alarm
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// The progress message was printed because user had sent us
comment|// SIGALRM. In this case, each progress message is printed
comment|// on its own line.
name|fputc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
else|#
directive|else
comment|// When SIGALRM isn't supported and we get here, it's always due to
comment|// automatic progress update. We set progress_active here too like
comment|// described above.
name|assert
argument_list|(
name|verbosity
operator|>=
name|V_VERBOSE
argument_list|)
expr_stmt|;
name|assert
argument_list|(
name|progress_automatic
argument_list|)
expr_stmt|;
name|progress_active
operator|=
name|true
expr_stmt|;
endif|#
directive|endif
name|signals_unblock
argument_list|()
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|static
name|void
name|progress_flush
parameter_list|(
name|bool
name|finished
parameter_list|)
block|{
if|if
condition|(
operator|!
name|progress_started
operator|||
name|verbosity
operator|<
name|V_VERBOSE
condition|)
return|return;
name|uint64_t
name|in_pos
decl_stmt|;
name|uint64_t
name|compressed_pos
decl_stmt|;
name|uint64_t
name|uncompressed_pos
decl_stmt|;
name|progress_pos
argument_list|(
operator|&
name|in_pos
argument_list|,
operator|&
name|compressed_pos
argument_list|,
operator|&
name|uncompressed_pos
argument_list|)
expr_stmt|;
comment|// Avoid printing intermediate progress info if some error occurs
comment|// in the beginning of the stream. (If something goes wrong later in
comment|// the stream, it is sometimes useful to tell the user where the
comment|// error approximately occurred, especially if the error occurs
comment|// after a time-consuming operation.)
if|if
condition|(
operator|!
name|finished
operator|&&
operator|!
name|progress_active
operator|&&
operator|(
name|compressed_pos
operator|==
literal|0
operator|||
name|uncompressed_pos
operator|==
literal|0
operator|)
condition|)
return|return;
name|progress_active
operator|=
name|false
expr_stmt|;
specifier|const
name|uint64_t
name|elapsed
init|=
name|progress_elapsed
argument_list|()
decl_stmt|;
name|signals_block
argument_list|()
expr_stmt|;
comment|// When using the auto-updating progress indicator, the final
comment|// statistics are printed in the same format as the progress
comment|// indicator itself.
if|if
condition|(
name|progress_automatic
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"\r %6s %35s   %9s %10s   %10s\n"
argument_list|,
name|finished
condition|?
literal|"100 %"
else|:
name|progress_percentage
argument_list|(
name|in_pos
argument_list|)
argument_list|,
name|progress_sizes
argument_list|(
name|compressed_pos
argument_list|,
name|uncompressed_pos
argument_list|,
name|true
argument_list|)
argument_list|,
name|progress_speed
argument_list|(
name|uncompressed_pos
argument_list|,
name|elapsed
argument_list|)
argument_list|,
name|progress_time
argument_list|(
name|elapsed
argument_list|)
argument_list|,
name|finished
condition|?
literal|""
else|:
name|progress_remaining
argument_list|(
name|in_pos
argument_list|,
name|elapsed
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// The filename is always printed.
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|filename
argument_list|)
expr_stmt|;
comment|// Percentage is printed only if we didn't finish yet.
if|if
condition|(
operator|!
name|finished
condition|)
block|{
comment|// Don't print the percentage when it isn't known
comment|// (starts with a dash).
specifier|const
name|char
modifier|*
name|percentage
init|=
name|progress_percentage
argument_list|(
name|in_pos
argument_list|)
decl_stmt|;
if|if
condition|(
name|percentage
index|[
literal|0
index|]
operator|!=
literal|'-'
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s, "
argument_list|,
name|percentage
argument_list|)
expr_stmt|;
block|}
comment|// Size information is always printed.
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s"
argument_list|,
name|progress_sizes
argument_list|(
name|compressed_pos
argument_list|,
name|uncompressed_pos
argument_list|,
name|true
argument_list|)
argument_list|)
expr_stmt|;
comment|// The speed and elapsed time aren't always shown.
specifier|const
name|char
modifier|*
name|speed
init|=
name|progress_speed
argument_list|(
name|uncompressed_pos
argument_list|,
name|elapsed
argument_list|)
decl_stmt|;
if|if
condition|(
name|speed
index|[
literal|0
index|]
operator|!=
literal|'\0'
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|", %s"
argument_list|,
name|speed
argument_list|)
expr_stmt|;
specifier|const
name|char
modifier|*
name|elapsed_str
init|=
name|progress_time
argument_list|(
name|elapsed
argument_list|)
decl_stmt|;
if|if
condition|(
name|elapsed_str
index|[
literal|0
index|]
operator|!=
literal|'\0'
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|", %s"
argument_list|,
name|elapsed_str
argument_list|)
expr_stmt|;
name|fputc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
block|}
name|signals_unblock
argument_list|()
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|extern
name|void
name|message_progress_end
parameter_list|(
name|bool
name|success
parameter_list|)
block|{
name|assert
argument_list|(
name|progress_started
argument_list|)
expr_stmt|;
name|progress_flush
argument_list|(
name|success
argument_list|)
expr_stmt|;
name|progress_started
operator|=
name|false
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|static
name|void
name|vmessage
parameter_list|(
name|enum
name|message_verbosity
name|v
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
name|va_list
name|ap
parameter_list|)
block|{
if|if
condition|(
name|v
operator|<=
name|verbosity
condition|)
block|{
name|signals_block
argument_list|()
expr_stmt|;
name|progress_flush
argument_list|(
name|false
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|progname
argument_list|)
expr_stmt|;
name|vfprintf
argument_list|(
name|stderr
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|fputc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
name|signals_unblock
argument_list|()
expr_stmt|;
block|}
return|return;
block|}
end_function

begin_function
specifier|extern
name|void
name|message
parameter_list|(
name|enum
name|message_verbosity
name|v
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|vmessage
argument_list|(
name|v
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|extern
name|void
name|message_warning
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|vmessage
argument_list|(
name|V_WARNING
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
name|set_exit_status
argument_list|(
name|E_WARNING
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|extern
name|void
name|message_error
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|vmessage
argument_list|(
name|V_ERROR
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
name|set_exit_status
argument_list|(
name|E_ERROR
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|extern
name|void
name|message_fatal
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
block|{
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
name|vmessage
argument_list|(
name|V_ERROR
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
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
end_function

begin_function
specifier|extern
name|void
name|message_bug
parameter_list|(
name|void
parameter_list|)
block|{
name|message_fatal
argument_list|(
name|_
argument_list|(
literal|"Internal error (bug)"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|extern
name|void
name|message_signal_handler
parameter_list|(
name|void
parameter_list|)
block|{
name|message_fatal
argument_list|(
name|_
argument_list|(
literal|"Cannot establish signal handlers"
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|extern
specifier|const
name|char
modifier|*
name|message_strm
parameter_list|(
name|lzma_ret
name|code
parameter_list|)
block|{
switch|switch
condition|(
name|code
condition|)
block|{
case|case
name|LZMA_NO_CHECK
case|:
return|return
name|_
argument_list|(
literal|"No integrity check; not verifying file integrity"
argument_list|)
return|;
case|case
name|LZMA_UNSUPPORTED_CHECK
case|:
return|return
name|_
argument_list|(
literal|"Unsupported type of integrity check; "
literal|"not verifying file integrity"
argument_list|)
return|;
case|case
name|LZMA_MEM_ERROR
case|:
return|return
name|strerror
argument_list|(
name|ENOMEM
argument_list|)
return|;
case|case
name|LZMA_MEMLIMIT_ERROR
case|:
return|return
name|_
argument_list|(
literal|"Memory usage limit reached"
argument_list|)
return|;
case|case
name|LZMA_FORMAT_ERROR
case|:
return|return
name|_
argument_list|(
literal|"File format not recognized"
argument_list|)
return|;
case|case
name|LZMA_OPTIONS_ERROR
case|:
return|return
name|_
argument_list|(
literal|"Unsupported options"
argument_list|)
return|;
case|case
name|LZMA_DATA_ERROR
case|:
return|return
name|_
argument_list|(
literal|"Compressed data is corrupt"
argument_list|)
return|;
case|case
name|LZMA_BUF_ERROR
case|:
return|return
name|_
argument_list|(
literal|"Unexpected end of input"
argument_list|)
return|;
case|case
name|LZMA_OK
case|:
case|case
name|LZMA_STREAM_END
case|:
case|case
name|LZMA_GET_CHECK
case|:
case|case
name|LZMA_PROG_ERROR
case|:
return|return
name|_
argument_list|(
literal|"Internal error (bug)"
argument_list|)
return|;
block|}
return|return
name|NULL
return|;
block|}
end_function

begin_function
specifier|extern
name|void
name|message_mem_needed
parameter_list|(
name|enum
name|message_verbosity
name|v
parameter_list|,
name|uint64_t
name|memusage
parameter_list|)
block|{
if|if
condition|(
name|v
operator|>
name|verbosity
condition|)
return|return;
comment|// Convert memusage to MiB, rounding up to the next full MiB.
comment|// This way the user can always use the displayed usage as
comment|// the new memory usage limit. (If we rounded to the nearest,
comment|// the user might need to +1 MiB to get high enough limit.)
name|memusage
operator|=
name|round_up_to_mib
argument_list|(
name|memusage
argument_list|)
expr_stmt|;
comment|// 2^64 with thousand separators + " MiB" suffix + '\0' = 26 + 4 + 1
name|char
name|memlimitstr
index|[
literal|32
index|]
decl_stmt|;
comment|// Show the memory usage limit as MiB unless it is less than 1 MiB.
comment|// This way it's easy to notice errors where one has typed
comment|// --memory=123 instead of --memory=123MiB.
name|uint64_t
name|memlimit
init|=
name|hardware_memlimit_get
argument_list|()
decl_stmt|;
if|if
condition|(
name|memlimit
operator|<
operator|(
name|UINT32_C
argument_list|(
literal|1
argument_list|)
operator|<<
literal|20
operator|)
condition|)
block|{
name|snprintf
argument_list|(
name|memlimitstr
argument_list|,
sizeof|sizeof
argument_list|(
name|memlimitstr
argument_list|)
argument_list|,
literal|"%s B"
argument_list|,
name|uint64_to_str
argument_list|(
name|memlimit
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
comment|// Round up just like with memusage. If this function is
comment|// called for informational purposes (to just show the
comment|// current usage and limit), we should never show that
comment|// the usage is higher than the limit, which would give
comment|// a false impression that the memory usage limit isn't
comment|// properly enforced.
name|snprintf
argument_list|(
name|memlimitstr
argument_list|,
sizeof|sizeof
argument_list|(
name|memlimitstr
argument_list|)
argument_list|,
literal|"%s MiB"
argument_list|,
name|uint64_to_str
argument_list|(
name|round_up_to_mib
argument_list|(
name|memlimit
argument_list|)
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|message
argument_list|(
name|v
argument_list|,
name|_
argument_list|(
literal|"%s MiB of memory is required. The limit is %s."
argument_list|)
argument_list|,
name|uint64_to_str
argument_list|(
name|memusage
argument_list|,
literal|0
argument_list|)
argument_list|,
name|memlimitstr
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|extern
name|void
name|message_filters
parameter_list|(
name|enum
name|message_verbosity
name|v
parameter_list|,
specifier|const
name|lzma_filter
modifier|*
name|filters
parameter_list|)
block|{
if|if
condition|(
name|v
operator|>
name|verbosity
condition|)
return|return;
name|fprintf
argument_list|(
name|stderr
argument_list|,
name|_
argument_list|(
literal|"%s: Filter chain:"
argument_list|)
argument_list|,
name|progname
argument_list|)
expr_stmt|;
for|for
control|(
name|size_t
name|i
init|=
literal|0
init|;
name|filters
index|[
name|i
index|]
operator|.
name|id
operator|!=
name|LZMA_VLI_UNKNOWN
condition|;
operator|++
name|i
control|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|" --"
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|filters
index|[
name|i
index|]
operator|.
name|id
condition|)
block|{
case|case
name|LZMA_FILTER_LZMA1
case|:
case|case
name|LZMA_FILTER_LZMA2
case|:
block|{
specifier|const
name|lzma_options_lzma
modifier|*
name|opt
init|=
name|filters
index|[
name|i
index|]
operator|.
name|options
decl_stmt|;
specifier|const
name|char
modifier|*
name|mode
decl_stmt|;
specifier|const
name|char
modifier|*
name|mf
decl_stmt|;
switch|switch
condition|(
name|opt
operator|->
name|mode
condition|)
block|{
case|case
name|LZMA_MODE_FAST
case|:
name|mode
operator|=
literal|"fast"
expr_stmt|;
break|break;
case|case
name|LZMA_MODE_NORMAL
case|:
name|mode
operator|=
literal|"normal"
expr_stmt|;
break|break;
default|default:
name|mode
operator|=
literal|"UNKNOWN"
expr_stmt|;
break|break;
block|}
switch|switch
condition|(
name|opt
operator|->
name|mf
condition|)
block|{
case|case
name|LZMA_MF_HC3
case|:
name|mf
operator|=
literal|"hc3"
expr_stmt|;
break|break;
case|case
name|LZMA_MF_HC4
case|:
name|mf
operator|=
literal|"hc4"
expr_stmt|;
break|break;
case|case
name|LZMA_MF_BT2
case|:
name|mf
operator|=
literal|"bt2"
expr_stmt|;
break|break;
case|case
name|LZMA_MF_BT3
case|:
name|mf
operator|=
literal|"bt3"
expr_stmt|;
break|break;
case|case
name|LZMA_MF_BT4
case|:
name|mf
operator|=
literal|"bt4"
expr_stmt|;
break|break;
default|default:
name|mf
operator|=
literal|"UNKNOWN"
expr_stmt|;
break|break;
block|}
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"lzma%c=dict=%"
name|PRIu32
literal|",lc=%"
name|PRIu32
literal|",lp=%"
name|PRIu32
literal|",pb=%"
name|PRIu32
literal|",mode=%s,nice=%"
name|PRIu32
literal|",mf=%s"
literal|",depth=%"
name|PRIu32
argument_list|,
name|filters
index|[
name|i
index|]
operator|.
name|id
operator|==
name|LZMA_FILTER_LZMA2
condition|?
literal|'2'
else|:
literal|'1'
argument_list|,
name|opt
operator|->
name|dict_size
argument_list|,
name|opt
operator|->
name|lc
argument_list|,
name|opt
operator|->
name|lp
argument_list|,
name|opt
operator|->
name|pb
argument_list|,
name|mode
argument_list|,
name|opt
operator|->
name|nice_len
argument_list|,
name|mf
argument_list|,
name|opt
operator|->
name|depth
argument_list|)
expr_stmt|;
break|break;
block|}
case|case
name|LZMA_FILTER_X86
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"x86"
argument_list|)
expr_stmt|;
break|break;
case|case
name|LZMA_FILTER_POWERPC
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"powerpc"
argument_list|)
expr_stmt|;
break|break;
case|case
name|LZMA_FILTER_IA64
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ia64"
argument_list|)
expr_stmt|;
break|break;
case|case
name|LZMA_FILTER_ARM
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"arm"
argument_list|)
expr_stmt|;
break|break;
case|case
name|LZMA_FILTER_ARMTHUMB
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"armthumb"
argument_list|)
expr_stmt|;
break|break;
case|case
name|LZMA_FILTER_SPARC
case|:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"sparc"
argument_list|)
expr_stmt|;
break|break;
case|case
name|LZMA_FILTER_DELTA
case|:
block|{
specifier|const
name|lzma_options_delta
modifier|*
name|opt
init|=
name|filters
index|[
name|i
index|]
operator|.
name|options
decl_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"delta=dist=%"
name|PRIu32
argument_list|,
name|opt
operator|->
name|dist
argument_list|)
expr_stmt|;
break|break;
block|}
default|default:
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"UNKNOWN"
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
name|fputc
argument_list|(
literal|'\n'
argument_list|,
name|stderr
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|extern
name|void
name|message_try_help
parameter_list|(
name|void
parameter_list|)
block|{
comment|// Print this with V_WARNING instead of V_ERROR to prevent it from
comment|// showing up when --quiet has been specified.
name|message
argument_list|(
name|V_WARNING
argument_list|,
name|_
argument_list|(
literal|"Try `%s --help' for more information."
argument_list|)
argument_list|,
name|progname
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_function
specifier|extern
name|void
name|message_memlimit
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|opt_robot
condition|)
name|printf
argument_list|(
literal|"%"
name|PRIu64
literal|"\n"
argument_list|,
name|hardware_memlimit_get
argument_list|()
argument_list|)
expr_stmt|;
else|else
name|printf
argument_list|(
name|_
argument_list|(
literal|"%s MiB (%s bytes)\n"
argument_list|)
argument_list|,
name|uint64_to_str
argument_list|(
name|round_up_to_mib
argument_list|(
name|hardware_memlimit_get
argument_list|()
argument_list|)
argument_list|,
literal|0
argument_list|)
argument_list|,
name|uint64_to_str
argument_list|(
name|hardware_memlimit_get
argument_list|()
argument_list|,
literal|1
argument_list|)
argument_list|)
expr_stmt|;
name|tuklib_exit
argument_list|(
name|E_SUCCESS
argument_list|,
name|E_ERROR
argument_list|,
name|verbosity
operator|!=
name|V_SILENT
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|extern
name|void
name|message_version
parameter_list|(
name|void
parameter_list|)
block|{
comment|// It is possible that liblzma version is different than the command
comment|// line tool version, so print both.
if|if
condition|(
name|opt_robot
condition|)
block|{
name|printf
argument_list|(
literal|"XZ_VERSION=%d\nLIBLZMA_VERSION=%d\n"
argument_list|,
name|LZMA_VERSION
argument_list|,
name|lzma_version_number
argument_list|()
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"xz ("
name|PACKAGE_NAME
literal|") "
name|LZMA_VERSION_STRING
literal|"\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"liblzma %s\n"
argument_list|,
name|lzma_version_string
argument_list|()
argument_list|)
expr_stmt|;
block|}
name|tuklib_exit
argument_list|(
name|E_SUCCESS
argument_list|,
name|E_ERROR
argument_list|,
name|verbosity
operator|!=
name|V_SILENT
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|extern
name|void
name|message_help
parameter_list|(
name|bool
name|long_help
parameter_list|)
block|{
name|printf
argument_list|(
name|_
argument_list|(
literal|"Usage: %s [OPTION]... [FILE]...\n"
literal|"Compress or decompress FILEs in the .xz format.\n\n"
argument_list|)
argument_list|,
name|progname
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|_
argument_list|(
literal|"Mandatory arguments to long options are mandatory for "
literal|"short options too.\n"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|long_help
condition|)
name|puts
argument_list|(
name|_
argument_list|(
literal|" Operation mode:\n"
argument_list|)
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|_
argument_list|(
literal|"  -z, --compress      force compression\n"
literal|"  -d, --decompress    force decompression\n"
literal|"  -t, --test          test compressed file integrity\n"
literal|"  -l, --list          list information about files"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|long_help
condition|)
name|puts
argument_list|(
name|_
argument_list|(
literal|"\n Operation modifiers:\n"
argument_list|)
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|_
argument_list|(
literal|"  -k, --keep          keep (don't delete) input files\n"
literal|"  -f, --force         force overwrite of output file and (de)compress links\n"
literal|"  -c, --stdout        write to standard output and don't delete input files"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|long_help
condition|)
name|puts
argument_list|(
name|_
argument_list|(
literal|"      --no-sparse     do not create sparse files when decompressing\n"
literal|"  -S, --suffix=.SUF   use the suffix `.SUF' on compressed files\n"
literal|"      --files=[FILE]  read filenames to process from FILE; if FILE is\n"
literal|"                      omitted, filenames are read from the standard input;\n"
literal|"                      filenames must be terminated with the newline character\n"
literal|"      --files0=[FILE] like --files but use the null character as terminator"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|long_help
condition|)
block|{
name|puts
argument_list|(
name|_
argument_list|(
literal|"\n Basic file format and compression options:\n"
argument_list|)
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|_
argument_list|(
literal|"  -F, --format=FMT    file format to encode or decode; possible values are\n"
literal|"                      `auto' (default), `xz', `lzma', and `raw'\n"
literal|"  -C, --check=CHECK   integrity check type: `crc32', `crc64' (default),\n"
literal|"                      `sha256', or `none' (use with caution)"
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|puts
argument_list|(
name|_
argument_list|(
literal|"  -0 .. -9            compression preset; 0-2 fast compression, 3-5 good\n"
literal|"                      compression, 6-9 excellent compression; default is 6"
argument_list|)
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|_
argument_list|(
literal|"  -e, --extreme       use more CPU time when encoding to increase compression\n"
literal|"                      ratio without increasing memory usage of the decoder"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|long_help
condition|)
name|puts
argument_list|(
name|_
argument_list|(
comment|// xgettext:no-c-format
literal|"  -M, --memory=NUM    use roughly NUM bytes of memory at maximum; 0 indicates\n"
literal|"                      the default setting, which is 40 % of total RAM"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|long_help
condition|)
block|{
name|puts
argument_list|(
name|_
argument_list|(
literal|"\n Custom filter chain for compression (alternative for using presets):"
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HAVE_ENCODER_LZMA1
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_DECODER_LZMA1
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|HAVE_ENCODER_LZMA2
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_DECODER_LZMA2
argument_list|)
name|puts
argument_list|(
name|_
argument_list|(
literal|"\n"
literal|"  --lzma1[=OPTS]      LZMA1 or LZMA2; OPTS is a comma-separated list of zero or\n"
literal|"  --lzma2[=OPTS]      more of the following options (valid values; default):\n"
literal|"                        preset=NUM reset options to preset number NUM (0-9)\n"
literal|"                        dict=NUM   dictionary size (4KiB - 1536MiB; 8MiB)\n"
literal|"                        lc=NUM     number of literal context bits (0-4; 3)\n"
literal|"                        lp=NUM     number of literal position bits (0-4; 0)\n"
literal|"                        pb=NUM     number of position bits (0-4; 2)\n"
literal|"                        mode=MODE  compression mode (fast, normal; normal)\n"
literal|"                        nice=NUM   nice length of a match (2-273; 64)\n"
literal|"                        mf=NAME    match finder (hc3, hc4, bt2, bt3, bt4; bt4)\n"
literal|"                        depth=NUM  maximum search depth; 0=automatic (default)"
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|puts
argument_list|(
name|_
argument_list|(
literal|"\n"
literal|"  --x86[=OPTS]        x86 BCJ filter\n"
literal|"  --powerpc[=OPTS]    PowerPC BCJ filter (big endian only)\n"
literal|"  --ia64[=OPTS]       IA64 (Itanium) BCJ filter\n"
literal|"  --arm[=OPTS]        ARM BCJ filter (little endian only)\n"
literal|"  --armthumb[=OPTS]   ARM-Thumb BCJ filter (little endian only)\n"
literal|"  --sparc[=OPTS]      SPARC BCJ filter\n"
literal|"                      Valid OPTS for all BCJ filters:\n"
literal|"                        start=NUM  start offset for conversions (default=0)"
argument_list|)
argument_list|)
expr_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|HAVE_ENCODER_DELTA
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_DECODER_DELTA
argument_list|)
name|puts
argument_list|(
name|_
argument_list|(
literal|"\n"
literal|"  --delta[=OPTS]      Delta filter; valid OPTS (valid values; default):\n"
literal|"                        dist=NUM   distance between bytes being subtracted\n"
literal|"                                   from each other (1-256; 1)"
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|defined
argument_list|(
name|HAVE_ENCODER_SUBBLOCK
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_DECODER_SUBBLOCK
argument_list|)
name|puts
argument_list|(
name|_
argument_list|(
literal|"\n"
literal|"  --subblock[=OPTS]   Subblock filter; valid OPTS (valid values; default):\n"
literal|"                        size=NUM   number of bytes of data per subblock\n"
literal|"                                   (1 - 256Mi; 4Ki)\n"
literal|"                        rle=NUM    run-length encoder chunk size (0-256; 0)"
argument_list|)
argument_list|)
expr_stmt|;
endif|#
directive|endif
block|}
if|if
condition|(
name|long_help
condition|)
name|puts
argument_list|(
name|_
argument_list|(
literal|"\n Other options:\n"
argument_list|)
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|_
argument_list|(
literal|"  -q, --quiet         suppress warnings; specify twice to suppress errors too\n"
literal|"  -v, --verbose       be verbose; specify twice for even more verbose"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|long_help
condition|)
block|{
name|puts
argument_list|(
name|_
argument_list|(
literal|"  -Q, --no-warn       make warnings not affect the exit status"
argument_list|)
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|_
argument_list|(
literal|"      --robot         use machine-parsable messages (useful for scripts)"
argument_list|)
argument_list|)
expr_stmt|;
name|puts
argument_list|(
literal|""
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|_
argument_list|(
literal|"      --info-memory   display the memory usage limit and exit"
argument_list|)
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|_
argument_list|(
literal|"  -h, --help          display the short help (lists only the basic options)\n"
literal|"  -H, --long-help     display this long help and exit"
argument_list|)
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|puts
argument_list|(
name|_
argument_list|(
literal|"  -h, --help          display this short help and exit\n"
literal|"  -H, --long-help     display the long help (lists also the advanced options)"
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|puts
argument_list|(
name|_
argument_list|(
literal|"  -V, --version       display the version number and exit"
argument_list|)
argument_list|)
expr_stmt|;
name|puts
argument_list|(
name|_
argument_list|(
literal|"\nWith no FILE, or when FILE is -, read standard input.\n"
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|long_help
condition|)
block|{
name|printf
argument_list|(
name|_
argument_list|(
literal|"On this system and configuration, this program will use a maximum of roughly\n"
literal|"%s MiB RAM and "
argument_list|)
argument_list|,
name|uint64_to_str
argument_list|(
name|round_up_to_mib
argument_list|(
name|hardware_memlimit_get
argument_list|()
argument_list|)
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
name|N_
argument_list|(
literal|"one thread.\n\n"
argument_list|,
literal|"%s threads.\n\n"
argument_list|,
name|hardware_threadlimit_get
argument_list|()
argument_list|)
argument_list|,
name|uint64_to_str
argument_list|(
name|hardware_threadlimit_get
argument_list|()
argument_list|,
literal|0
argument_list|)
argument_list|)
expr_stmt|;
block|}
comment|// TRANSLATORS: This message indicates the bug reporting address
comment|// for this package. Please add _another line_ saying
comment|// "Report translation bugs to<...>\n" with the email or WWW
comment|// address for translation bugs. Thanks.
name|printf
argument_list|(
name|_
argument_list|(
literal|"Report bugs to<%s> (in English or Finnish).\n"
argument_list|)
argument_list|,
name|PACKAGE_BUGREPORT
argument_list|)
expr_stmt|;
name|printf
argument_list|(
name|_
argument_list|(
literal|"%s home page:<%s>\n"
argument_list|)
argument_list|,
name|PACKAGE_NAME
argument_list|,
name|PACKAGE_URL
argument_list|)
expr_stmt|;
name|tuklib_exit
argument_list|(
name|E_SUCCESS
argument_list|,
name|E_ERROR
argument_list|,
name|verbosity
operator|!=
name|V_SILENT
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

