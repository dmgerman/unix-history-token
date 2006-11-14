begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* quotearg.h - quote arguments for output     Copyright (C) 1998, 1999, 2000, 2001, 2002, 2004 Free Software    Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert<eggert@twinsun.com> */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|QUOTEARG_H_
end_ifndef

begin_define
define|#
directive|define
name|QUOTEARG_H_
value|1
end_define

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_comment
comment|/* Basic quoting styles.  */
end_comment

begin_enum
enum|enum
name|quoting_style
block|{
comment|/* Output names as-is (ls --quoting-style=literal).  */
name|literal_quoting_style
block|,
comment|/* Quote names for the shell if they contain shell metacharacters        or would cause ambiguous output (ls --quoting-style=shell).  */
name|shell_quoting_style
block|,
comment|/* Quote names for the shell, even if they would normally not        require quoting (ls --quoting-style=shell-always).  */
name|shell_always_quoting_style
block|,
comment|/* Quote names as for a C language string (ls --quoting-style=c).  */
name|c_quoting_style
block|,
comment|/* Like c_quoting_style except omit the surrounding double-quote        characters (ls --quoting-style=escape).  */
name|escape_quoting_style
block|,
comment|/* Like clocale_quoting_style, but quote `like this' instead of        "like this" in the default C locale (ls --quoting-style=locale).  */
name|locale_quoting_style
block|,
comment|/* Like c_quoting_style except use quotation marks appropriate for        the locale (ls --quoting-style=clocale).  */
name|clocale_quoting_style
block|}
enum|;
end_enum

begin_comment
comment|/* For now, --quoting-style=literal is the default, but this may change.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_QUOTING_STYLE
end_ifndef

begin_define
define|#
directive|define
name|DEFAULT_QUOTING_STYLE
value|literal_quoting_style
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Names of quoting styles and their corresponding values.  */
end_comment

begin_decl_stmt
specifier|extern
name|char
specifier|const
modifier|*
specifier|const
name|quoting_style_args
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|enum
name|quoting_style
specifier|const
name|quoting_style_vals
index|[]
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|quoting_options
struct_decl|;
end_struct_decl

begin_comment
comment|/* The functions listed below set and use a hidden variable    that contains the default quoting style options.  */
end_comment

begin_comment
comment|/* Allocate a new set of quoting options, with contents initially identical    to O if O is not null, or to the default if O is null.    It is the caller's responsibility to free the result.  */
end_comment

begin_function_decl
name|struct
name|quoting_options
modifier|*
name|clone_quoting_options
parameter_list|(
name|struct
name|quoting_options
modifier|*
name|o
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Get the value of O's quoting style.  If O is null, use the default.  */
end_comment

begin_function_decl
name|enum
name|quoting_style
name|get_quoting_style
parameter_list|(
name|struct
name|quoting_options
modifier|*
name|o
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In O (or in the default if O is null),    set the value of the quoting style to S.  */
end_comment

begin_function_decl
name|void
name|set_quoting_style
parameter_list|(
name|struct
name|quoting_options
modifier|*
name|o
parameter_list|,
name|enum
name|quoting_style
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* In O (or in the default if O is null),    set the value of the quoting options for character C to I.    Return the old value.  Currently, the only values defined for I are    0 (the default) and 1 (which means to quote the character even if    it would not otherwise be quoted).  */
end_comment

begin_function_decl
name|int
name|set_char_quoting
parameter_list|(
name|struct
name|quoting_options
modifier|*
name|o
parameter_list|,
name|char
name|c
parameter_list|,
name|int
name|i
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Place into buffer BUFFER (of size BUFFERSIZE) a quoted version of    argument ARG (of size ARGSIZE), using O to control quoting.    If O is null, use the default.    Terminate the output with a null character, and return the written    size of the output, not counting the terminating null.    If BUFFERSIZE is too small to store the output string, return the    value that would have been returned had BUFFERSIZE been large enough.    If ARGSIZE is -1, use the string length of the argument for ARGSIZE.  */
end_comment

begin_function_decl
name|size_t
name|quotearg_buffer
parameter_list|(
name|char
modifier|*
name|buffer
parameter_list|,
name|size_t
name|buffersize
parameter_list|,
name|char
specifier|const
modifier|*
name|arg
parameter_list|,
name|size_t
name|argsize
parameter_list|,
name|struct
name|quoting_options
specifier|const
modifier|*
name|o
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Like quotearg_buffer, except return the result in a newly allocated    buffer.  It is the caller's responsibility to free the result.  */
end_comment

begin_function_decl
name|char
modifier|*
name|quotearg_alloc
parameter_list|(
name|char
specifier|const
modifier|*
name|arg
parameter_list|,
name|size_t
name|argsize
parameter_list|,
name|struct
name|quoting_options
specifier|const
modifier|*
name|o
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Use storage slot N to return a quoted version of the string ARG.    Use the default quoting options.    The returned value points to static storage that can be    reused by the next call to this function with the same value of N.    N must be nonnegative.  */
end_comment

begin_function_decl
name|char
modifier|*
name|quotearg_n
parameter_list|(
name|int
name|n
parameter_list|,
name|char
specifier|const
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Equivalent to quotearg_n (0, ARG).  */
end_comment

begin_function_decl
name|char
modifier|*
name|quotearg
parameter_list|(
name|char
specifier|const
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Use style S and storage slot N to return a quoted version of the string ARG.    This is like quotearg_n (N, ARG), except that it uses S with no other    options to specify the quoting method.  */
end_comment

begin_function_decl
name|char
modifier|*
name|quotearg_n_style
parameter_list|(
name|int
name|n
parameter_list|,
name|enum
name|quoting_style
name|s
parameter_list|,
name|char
specifier|const
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Use style S and storage slot N to return a quoted version of the    argument ARG of size ARGSIZE.  This is like quotearg_n_style    (N, S, ARG), except it can quote null bytes.  */
end_comment

begin_function_decl
name|char
modifier|*
name|quotearg_n_style_mem
parameter_list|(
name|int
name|n
parameter_list|,
name|enum
name|quoting_style
name|s
parameter_list|,
name|char
specifier|const
modifier|*
name|arg
parameter_list|,
name|size_t
name|argsize
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Equivalent to quotearg_n_style (0, S, ARG).  */
end_comment

begin_function_decl
name|char
modifier|*
name|quotearg_style
parameter_list|(
name|enum
name|quoting_style
name|s
parameter_list|,
name|char
specifier|const
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Like quotearg (ARG), except also quote any instances of CH.  */
end_comment

begin_function_decl
name|char
modifier|*
name|quotearg_char
parameter_list|(
name|char
specifier|const
modifier|*
name|arg
parameter_list|,
name|char
name|ch
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Equivalent to quotearg_char (ARG, ':').  */
end_comment

begin_function_decl
name|char
modifier|*
name|quotearg_colon
parameter_list|(
name|char
specifier|const
modifier|*
name|arg
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !QUOTEARG_H_ */
end_comment

end_unit

