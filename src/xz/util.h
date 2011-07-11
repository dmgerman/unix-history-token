begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|///////////////////////////////////////////////////////////////////////////////
end_comment

begin_comment
comment|//
end_comment

begin_comment
comment|/// \file       util.h
end_comment

begin_comment
comment|/// \brief      Miscellaneous utility functions
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
comment|/// \brief      Safe malloc() that never returns NULL
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \note       xmalloc(), xrealloc(), and xstrdup() must not be used when
end_comment

begin_comment
comment|///             there are files open for writing, that should be cleaned up
end_comment

begin_comment
comment|///             before exiting.
end_comment

begin_define
define|#
directive|define
name|xmalloc
parameter_list|(
name|size
parameter_list|)
value|xrealloc(NULL, size)
end_define

begin_comment
comment|/// \brief      Safe realloc() that never returns NULL
end_comment

begin_function_decl
specifier|extern
name|void
modifier|*
name|xrealloc
parameter_list|(
name|void
modifier|*
name|ptr
parameter_list|,
name|size_t
name|size
parameter_list|)
function_decl|lzma_attribute
parameter_list|(
function_decl|(__malloc__
end_function_decl

begin_expr_stmt
unit|))
name|lzma_attr_alloc_size
argument_list|(
literal|2
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/// \brief      Safe strdup() that never returns NULL
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|xstrdup
parameter_list|(
specifier|const
name|char
modifier|*
name|src
parameter_list|)
function_decl|lzma_attribute
parameter_list|(
function_decl|(__malloc__
end_function_decl

begin_empty_stmt
unit|))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief      Fancy version of strtoull()
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param      name    Name of the option to show in case of an error
end_comment

begin_comment
comment|/// \param      value   String containing the number to be parsed; may
end_comment

begin_comment
comment|///                     contain suffixes "k", "M", "G", "Ki", "Mi", or "Gi"
end_comment

begin_comment
comment|/// \param      min     Minimum valid value
end_comment

begin_comment
comment|/// \param      max     Maximum valid value
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return     Parsed value that is in the range [min, max]. Does not return
end_comment

begin_comment
comment|///             if an error occurs.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
specifier|extern
name|uint64_t
name|str_to_uint64
parameter_list|(
specifier|const
name|char
modifier|*
name|name
parameter_list|,
specifier|const
name|char
modifier|*
name|value
parameter_list|,
name|uint64_t
name|min
parameter_list|,
name|uint64_t
name|max
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Round an integer up to the next full MiB and convert to MiB
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is used when printing memory usage and limit.
end_comment

begin_function_decl
specifier|extern
name|uint64_t
name|round_up_to_mib
parameter_list|(
name|uint64_t
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Convert uint64_t to a string
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// Convert the given value to a string with locale-specific thousand
end_comment

begin_comment
comment|/// separators, if supported by the snprintf() implementation. The string
end_comment

begin_comment
comment|/// is stored into an internal static buffer indicated by the slot argument.
end_comment

begin_comment
comment|/// A pointer to the selected buffer is returned.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This function exists, because non-POSIX systems don't support thousand
end_comment

begin_comment
comment|/// separator in format strings. Solving the problem in a simple way doesn't
end_comment

begin_comment
comment|/// work, because it breaks gettext (specifically, the xgettext tool).
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|uint64_to_str
parameter_list|(
name|uint64_t
name|value
parameter_list|,
name|uint32_t
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_enum
enum|enum
name|nicestr_unit
block|{
name|NICESTR_B
block|,
name|NICESTR_KIB
block|,
name|NICESTR_MIB
block|,
name|NICESTR_GIB
block|,
name|NICESTR_TIB
block|, }
enum|;
end_enum

begin_comment
comment|/// \brief      Convert uint64_t to a nice human readable string
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// This is like uint64_to_str() but uses B, KiB, MiB, GiB, or TiB suffix
end_comment

begin_comment
comment|/// and optionally includes the exact size in parenthesis.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \param      value     Value to be printed
end_comment

begin_comment
comment|/// \param      unit_min  Smallest unit to use. This and unit_max are used
end_comment

begin_comment
comment|///                       e.g. when showing the progress indicator to force
end_comment

begin_comment
comment|///                       the unit to MiB.
end_comment

begin_comment
comment|/// \param      unit_max  Biggest unit to use. assert(unit_min<= unit_max).
end_comment

begin_comment
comment|/// \param      always_also_bytes
end_comment

begin_comment
comment|///                       Show also the exact byte value in parenthesis
end_comment

begin_comment
comment|///                       if the nicely formatted string uses bigger unit
end_comment

begin_comment
comment|///                       than bytes.
end_comment

begin_comment
comment|/// \param      slot      Which static buffer to use to hold the string.
end_comment

begin_comment
comment|///                       This is shared with uint64_to_str().
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \return     Pointer to statically allocated buffer containing the string.
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// \note       This uses double_to_str() internally so the static buffer
end_comment

begin_comment
comment|///             in double_to_str() will be overwritten.
end_comment

begin_comment
comment|///
end_comment

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|uint64_to_nicestr
parameter_list|(
name|uint64_t
name|value
parameter_list|,
name|enum
name|nicestr_unit
name|unit_min
parameter_list|,
name|enum
name|nicestr_unit
name|unit_max
parameter_list|,
name|bool
name|always_also_bytes
parameter_list|,
name|uint32_t
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Wrapper for snprintf() to help constructing a string in pieces
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// A maximum of *left bytes is written starting from *pos. *pos and *left
end_comment

begin_comment
comment|/// are updated accordingly.
end_comment

begin_function_decl
specifier|extern
name|void
name|my_snprintf
parameter_list|(
name|char
modifier|*
modifier|*
name|pos
parameter_list|,
name|size_t
modifier|*
name|left
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
function_decl|3
operator|,
function_decl|4
end_function_decl

begin_empty_stmt
unit|)))
empty_stmt|;
end_empty_stmt

begin_comment
comment|/// \brief      Check if filename is empty and print an error message
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_empty_filename
parameter_list|(
specifier|const
name|char
modifier|*
name|filename
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Test if stdin is a terminal
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If stdin is a terminal, an error message is printed and exit status set
end_comment

begin_comment
comment|/// to EXIT_ERROR.
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_tty_stdin
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/// \brief      Test if stdout is a terminal
end_comment

begin_comment
comment|///
end_comment

begin_comment
comment|/// If stdout is a terminal, an error message is printed and exit status set
end_comment

begin_comment
comment|/// to EXIT_ERROR.
end_comment

begin_function_decl
specifier|extern
name|bool
name|is_tty_stdout
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

end_unit

