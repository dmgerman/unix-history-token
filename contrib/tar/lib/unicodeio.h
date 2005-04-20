begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Unicode character output to streams with locale dependent encoding.     Copyright (C) 2000, 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|UNICODEIO_H
end_ifndef

begin_define
define|#
directive|define
name|UNICODEIO_H
end_define

begin_include
include|#
directive|include
file|<stdio.h>
end_include

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
operator|(
name|defined
name|__STDC__
operator|&&
name|__STDC__
operator|)
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
comment|/* Converts the Unicode character CODE to its multibyte representation    in the current locale and calls the CALLBACK on the resulting byte    sequence.  If an error occurs, invokes ERROR_CALLBACK instead,    passing it CODE with errno set appropriately.  Returns whatever the    callback returns.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|unicode_to_mb
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
name|code
operator|,
name|int
argument_list|(
argument|*callback
argument_list|)
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|buf
operator|,
name|size_t
name|buflen
operator|,
name|void
operator|*
name|callback_arg
operator|)
argument_list|)
operator|,
name|int
argument_list|(
argument|*error_callback
argument_list|)
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
name|code
operator|,
name|void
operator|*
name|callback_arg
operator|)
argument_list|)
operator|,
name|void
operator|*
name|callback_arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Success callback that outputs the conversion of the character.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|print_unicode_success
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|buf
operator|,
name|size_t
name|buflen
operator|,
name|void
operator|*
name|callback_arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Failure callback that outputs an ASCII representation.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|print_unicode_failure
name|PARAMS
argument_list|(
operator|(
name|unsigned
name|int
name|code
operator|,
name|void
operator|*
name|callback_arg
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Outputs the Unicode character CODE to the output stream STREAM.    Returns -1 (setting errno) if unsuccessful.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|print_unicode_char
name|PARAMS
argument_list|(
operator|(
name|FILE
operator|*
name|stream
operator|,
name|unsigned
name|int
name|code
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

