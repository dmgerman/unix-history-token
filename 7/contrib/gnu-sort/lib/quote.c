begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* quote.c - quote arguments for output    Copyright (C) 1998, 1999, 2000, 2001, 2003 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert<eggert@twinsun.com> */
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

begin_include
include|#
directive|include
file|"quotearg.h"
end_include

begin_include
include|#
directive|include
file|"quote.h"
end_include

begin_comment
comment|/* Return an unambiguous printable representation of NAME,    allocated in slot N, suitable for diagnostics.  */
end_comment

begin_function
name|char
specifier|const
modifier|*
name|quote_n
parameter_list|(
name|int
name|n
parameter_list|,
name|char
specifier|const
modifier|*
name|name
parameter_list|)
block|{
return|return
name|quotearg_n_style
argument_list|(
name|n
argument_list|,
name|locale_quoting_style
argument_list|,
name|name
argument_list|)
return|;
block|}
end_function

begin_comment
comment|/* Return an unambiguous printable representation of NAME,    suitable for diagnostics.  */
end_comment

begin_function
name|char
specifier|const
modifier|*
name|quote
parameter_list|(
name|char
specifier|const
modifier|*
name|name
parameter_list|)
block|{
return|return
name|quote_n
argument_list|(
literal|0
argument_list|,
name|name
argument_list|)
return|;
block|}
end_function

end_unit

