begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* quotearg.h - quote arguments for output    Copyright (C) 1998, 1999, 2000 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert<eggert@twinsun.com> */
end_comment

begin_comment
comment|/* Basic quoting styles.  */
end_comment

begin_enum
enum|enum
name|quoting_style
block|{
name|literal_quoting_style
block|,
comment|/* --quoting-style=literal */
name|shell_quoting_style
block|,
comment|/* --quoting-style=shell */
name|shell_always_quoting_style
block|,
comment|/* --quoting-style=shell-always */
name|c_quoting_style
block|,
comment|/* --quoting-style=c */
name|escape_quoting_style
block|,
comment|/* --quoting-style=escape */
name|locale_quoting_style
block|,
comment|/* --quoting-style=locale */
name|clocale_quoting_style
comment|/* --quoting-style=clocale */
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

begin_ifndef
ifndef|#
directive|ifndef
name|PARAMS
end_ifndef

begin_if
if|#
directive|if
name|defined
name|PROTOTYPES
operator|||
name|defined
name|__STDC__
end_if

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|Args
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|PARAMS
parameter_list|(
name|Args
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The functions listed below set and use a hidden variable    that contains the default quoting style options.  */
end_comment

begin_comment
comment|/* Allocate a new set of quoting options, with contents initially identical    to O if O is not null, or to the default if O is null.    It is the caller's responsibility to free the result.  */
end_comment

begin_decl_stmt
name|struct
name|quoting_options
modifier|*
name|clone_quoting_options
name|PARAMS
argument_list|(
operator|(
expr|struct
name|quoting_options
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Get the value of O's quoting style.  If O is null, use the default.  */
end_comment

begin_decl_stmt
name|enum
name|quoting_style
name|get_quoting_style
name|PARAMS
argument_list|(
operator|(
expr|struct
name|quoting_options
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In O (or in the default if O is null),    set the value of the quoting style to S.  */
end_comment

begin_decl_stmt
name|void
name|set_quoting_style
name|PARAMS
argument_list|(
operator|(
expr|struct
name|quoting_options
operator|*
name|o
operator|,
expr|enum
name|quoting_style
name|s
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* In O (or in the default if O is null),    set the value of the quoting options for character C to I.    Return the old value.  Currently, the only values defined for I are    0 (the default) and 1 (which means to quote the character even if    it would not otherwise be quoted).  */
end_comment

begin_decl_stmt
name|int
name|set_char_quoting
name|PARAMS
argument_list|(
operator|(
expr|struct
name|quoting_options
operator|*
name|o
operator|,
name|char
name|c
operator|,
name|int
name|i
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Place into buffer BUFFER (of size BUFFERSIZE) a quoted version of    argument ARG (of size ARGSIZE), using O to control quoting.    If O is null, use the default.    Terminate the output with a null character, and return the written    size of the output, not counting the terminating null.    If BUFFERSIZE is too small to store the output string, return the    value that would have been returned had BUFFERSIZE been large enough.    If ARGSIZE is -1, use the string length of the argument for ARGSIZE.  */
end_comment

begin_decl_stmt
name|size_t
name|quotearg_buffer
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
name|buffer
operator|,
name|size_t
name|buffersize
operator|,
name|char
specifier|const
operator|*
name|arg
operator|,
name|size_t
name|argsize
operator|,
expr|struct
name|quoting_options
specifier|const
operator|*
name|o
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use storage slot N to return a quoted version of the string ARG.    Use the default quoting options.    The returned value points to static storage that can be    reused by the next call to this function with the same value of N.    N must be nonnegative.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|quotearg_n
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
name|n
operator|,
name|char
specifier|const
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Equivalent to quotearg_n (0, ARG).  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|quotearg
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Use style S and storage slot N to return a quoted version of the string ARG.    This is like quotearg_n (N, ARG), except that it uses S with no other    options to specify the quoting method.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|quotearg_n_style
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
name|n
operator|,
expr|enum
name|quoting_style
name|s
operator|,
name|char
specifier|const
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Equivalent to quotearg_n_style (0, S, ARG).  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|quotearg_style
name|PARAMS
argument_list|(
operator|(
expr|enum
name|quoting_style
name|s
operator|,
name|char
specifier|const
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Like quotearg (ARG), except also quote any instances of CH.  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|quotearg_char
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
name|arg
operator|,
name|char
name|ch
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Equivalent to quotearg_char (ARG, ':').  */
end_comment

begin_decl_stmt
name|char
modifier|*
name|quotearg_colon
name|PARAMS
argument_list|(
operator|(
name|char
specifier|const
operator|*
name|arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

