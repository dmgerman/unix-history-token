begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       message.h
end_comment

begin_comment
comment|/// \brief      Printing messages to stderr
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

begin_comment
comment|/// Verbosity levels
end_comment

begin_enum
enum|enum
name|message_verbosity
block|{
name|V_SILENT
block|,
comment|///< No messages
name|V_ERROR
block|,
comment|///< Only error messages
name|V_WARNING
block|,
comment|///< Errors and warnings
name|V_VERBOSE
block|,
comment|///< Errors, warnings, and verbose statistics
name|V_DEBUG
block|,
comment|///< Very verbose
block|}
enum|;
end_enum

begin_comment
comment|/// \brief      Signals used for progress message handling
end_comment

begin_decl_stmt
specifier|extern
specifier|const
name|int
name|message_progress_sigs
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/// \brief      Initializes the message functions
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If an error occurs, this function doesn't return.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
specifier|extern
name|void
name|message_init
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Increase verbosity level by one step unless it was at maximum.
end_comment

begin_function_decl
specifier|extern
name|void
name|message_verbosity_increase
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Decrease verbosity level by one step unless it was at minimum.
end_comment

begin_function_decl
specifier|extern
name|void
name|message_verbosity_decrease
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Get the current verbosity level.
end_comment

begin_function_decl
specifier|extern
name|enum
name|message_verbosity
name|message_verbosity_get
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Print a message if verbosity level is at least "verbosity"
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This doesn't touch the exit status.
end_comment

begin_function_decl
specifier|extern
name|void
name|message
parameter_list|(
name|enum
name|message_verbosity
name|verbosity
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|lzma_attribute
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|2
operator|,
function_decl|3
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief      Prints a warning and possibly sets exit status
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The message is printed only if verbosity level is at least V_WARNING.
end_comment

begin_comment
comment|/// The exit status is set to WARNING unless it was already at ERROR.
end_comment

begin_function_decl
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
function_decl|lzma_attribute
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief      Prints an error message and sets exit status
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The message is printed only if verbosity level is at least V_ERROR.
end_comment

begin_comment
comment|/// The exit status is set to ERROR.
end_comment

begin_function_decl
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
function_decl|lzma_attribute
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief      Prints an error message and exits with EXIT_ERROR
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The message is printed only if verbosity level is at least V_ERROR.
end_comment

begin_function_decl
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
function_decl|lzma_attribute
parameter_list|(
function_decl|(__format__
parameter_list|(
name|__printf__
parameter_list|,
function_decl|1
operator|,
function_decl|2
end_function_decl

begin_expr_stmt
unit|)))
name|lzma_attribute
argument_list|(
operator|(
name|__noreturn__
operator|)
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// Print an error message that an internal error occurred and exit with
end_comment

begin_comment
comment|/// EXIT_ERROR.
end_comment

begin_function_decl
specifier|extern
name|void
name|message_bug
parameter_list|(
name|void
parameter_list|)
function_decl|lzma_attribute
parameter_list|(
function_decl|(__noreturn__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Print a message that establishing signal handlers failed, and exit with
end_comment

begin_comment
comment|/// exit status ERROR.
end_comment

begin_function_decl
specifier|extern
name|void
name|message_signal_handler
parameter_list|(
name|void
parameter_list|)
function_decl|lzma_attribute
parameter_list|(
function_decl|(__noreturn__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Convert lzma_ret to a string.
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|message_strm
parameter_list|(
name|lzma_ret
name|code
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Display how much memory was needed and how much the limit was.
end_comment

begin_function_decl
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
function_decl|;
end_function_decl

begin_comment
comment|/// Buffer size for message_filters_to_str()
end_comment

begin_define
define|#
directive|define
name|FILTERS_STR_SIZE
value|512
end_define

begin_comment
comment|/// \brief      Get the filter chain as a string
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param      buf         Pointer to caller allocated buffer to hold
end_comment

begin_comment
comment|///                         the filter chain string
end_comment

begin_comment
comment|/// \param      filters     Pointer to the filter chain
end_comment

begin_comment
comment|/// \param      all_known   If true, all filter options are printed.
end_comment

begin_comment
comment|///                         If false, only the options that get stored
end_comment

begin_comment
comment|///                         into .xz headers are printed.
end_comment

begin_function_decl
specifier|extern
name|void
name|message_filters_to_str
parameter_list|(
name|char
name|buf
index|[
name|FILTERS_STR_SIZE
index|]
parameter_list|,
specifier|const
name|lzma_filter
modifier|*
name|filters
parameter_list|,
name|bool
name|all_known
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Print the filter chain.
end_comment

begin_function_decl
specifier|extern
name|void
name|message_filters_show
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
function_decl|;
end_function_decl

begin_comment
comment|/// Print a message that user should try --help.
end_comment

begin_function_decl
specifier|extern
name|void
name|message_try_help
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// Prints the version number to stdout and exits with exit status SUCCESS.
end_comment

begin_function_decl
specifier|extern
name|void
name|message_version
parameter_list|(
name|void
parameter_list|)
function_decl|lzma_attribute
parameter_list|(
function_decl|(__noreturn__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// Print the help message.
end_comment

begin_function_decl
specifier|extern
name|void
name|message_help
parameter_list|(
name|bool
name|long_help
parameter_list|)
function_decl|lzma_attribute
parameter_list|(
function_decl|(__noreturn__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief      Set the total number of files to be processed
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Standard input is counted as a file here. This is used when printing
end_comment

begin_comment
comment|/// the filename via message_filename().
end_comment

begin_function_decl
specifier|extern
name|void
name|message_set_files
parameter_list|(
name|unsigned
name|int
name|files
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Set the name of the current file and possibly print it too
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// The name is printed immediately if --list was used or if --verbose
end_comment

begin_comment
comment|/// was used and stderr is a terminal. Even when the filename isn't printed,
end_comment

begin_comment
comment|/// it is stored so that it can be printed later if needed for progress
end_comment

begin_comment
comment|/// messages.
end_comment

begin_function_decl
specifier|extern
name|void
name|message_filename
parameter_list|(
specifier|const
name|char
modifier|*
name|src_name
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Start progress info handling
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// message_filename() must be called before this function to set
end_comment

begin_comment
comment|/// the filename.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This must be paired with a call to message_progress_end() before the
end_comment

begin_comment
comment|/// given *strm becomes invalid.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param      strm      Pointer to lzma_stream used for the coding.
end_comment

begin_comment
comment|/// \param      in_size   Size of the input file, or zero if unknown.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
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
function_decl|;
end_function_decl

begin_comment
comment|/// Update the progress info if in verbose mode and enough time has passed
end_comment

begin_comment
comment|/// since the previous update. This can be called only when
end_comment

begin_comment
comment|/// message_progress_start() has already been used.
end_comment

begin_function_decl
specifier|extern
name|void
name|message_progress_update
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Finishes the progress message if we were in verbose mode
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param      finished    True if the whole stream was successfully coded
end_comment

begin_comment
comment|///                         and output written to the output stream.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
specifier|extern
name|void
name|message_progress_end
parameter_list|(
name|bool
name|finished
parameter_list|)
function_decl|;
end_function_decl

end_unit

