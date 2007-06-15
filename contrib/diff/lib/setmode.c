begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Set a file descriptor's mode to binary or to text.     Copyright (C) 2001, 2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.    If not, write to the Free Software Foundation,    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert<eggert@twinsun.com>  */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STDBOOL_H
end_if

begin_include
include|#
directive|include
file|<stdbool.h>
end_include

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
enum|enum
block|{
name|false
init|=
literal|0
block|,
name|true
init|=
literal|1
block|}
name|bool
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_SETMODE_DOS
end_if

begin_include
include|#
directive|include
file|<io.h>
end_include

begin_if
if|#
directive|if
name|HAVE_FCNTL_H
end_if

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_UNISTD_H
end_if

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"setmode.h"
end_include

begin_undef
undef|#
directive|undef
name|set_binary_mode
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|__attribute__
end_ifndef

begin_if
if|#
directive|if
name|__GNUC__
operator|<
literal|3
operator|||
name|__STRICT_ANSI__
end_if

begin_define
define|#
directive|define
name|__attribute__
parameter_list|(
name|x
parameter_list|)
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
comment|/* Set the binary mode of FD to MODE, returning its previous mode.    MODE is 1 for binary and 0 for text.  If setting the mode might    cause problems, ignore the request and return MODE.  Always return    1 on POSIX platforms, which do not distinguish between text and    binary.  */
end_comment

begin_if
if|#
directive|if
name|HAVE_SETMODE_DOS
end_if

begin_function
name|bool
name|set_binary_mode
parameter_list|(
name|int
name|fd
parameter_list|,
name|bool
name|mode
parameter_list|)
block|{
if|if
condition|(
name|isatty
argument_list|(
name|fd
argument_list|)
condition|)
return|return
name|mode
return|;
return|return
name|setmode
argument_list|(
name|fd
argument_list|,
name|mode
condition|?
name|O_BINARY
else|:
name|O_TEXT
argument_list|)
operator|!=
name|O_TEXT
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|static
name|char
name|dummy
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

