begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Locale-specific memory comparison.    Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Contributed by Paul Eggert<eggert@twinsun.com>.  */
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
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|"gettext.h"
end_include

begin_define
define|#
directive|define
name|_
parameter_list|(
name|msgid
parameter_list|)
value|gettext (msgid)
end_define

begin_include
include|#
directive|include
file|"error.h"
end_include

begin_include
include|#
directive|include
file|"exitfail.h"
end_include

begin_include
include|#
directive|include
file|"memcoll.h"
end_include

begin_include
include|#
directive|include
file|"quotearg.h"
end_include

begin_include
include|#
directive|include
file|"xmemcoll.h"
end_include

begin_comment
comment|/* Compare S1 (with length S1LEN) and S2 (with length S2LEN) according    to the LC_COLLATE locale.  S1 and S2 do not overlap, and are not    adjacent.  Temporarily modify the bytes after S1 and S2, but    restore their original contents before returning.  Report an error    and exit if there is an error.  */
end_comment

begin_function
name|int
name|xmemcoll
parameter_list|(
name|char
modifier|*
name|s1
parameter_list|,
name|size_t
name|s1len
parameter_list|,
name|char
modifier|*
name|s2
parameter_list|,
name|size_t
name|s2len
parameter_list|)
block|{
name|int
name|diff
init|=
name|memcoll
argument_list|(
name|s1
argument_list|,
name|s1len
argument_list|,
name|s2
argument_list|,
name|s2len
argument_list|)
decl_stmt|;
name|int
name|collation_errno
init|=
name|errno
decl_stmt|;
if|if
condition|(
name|collation_errno
condition|)
block|{
name|error
argument_list|(
literal|0
argument_list|,
name|collation_errno
argument_list|,
name|_
argument_list|(
literal|"string comparison failed"
argument_list|)
argument_list|)
expr_stmt|;
name|error
argument_list|(
literal|0
argument_list|,
literal|0
argument_list|,
name|_
argument_list|(
literal|"Set LC_ALL='C' to work around the problem."
argument_list|)
argument_list|)
expr_stmt|;
name|error
argument_list|(
name|exit_failure
argument_list|,
literal|0
argument_list|,
name|_
argument_list|(
literal|"The strings compared were %s and %s."
argument_list|)
argument_list|,
name|quotearg_n_style_mem
argument_list|(
literal|0
argument_list|,
name|locale_quoting_style
argument_list|,
name|s1
argument_list|,
name|s1len
argument_list|)
argument_list|,
name|quotearg_n_style_mem
argument_list|(
literal|1
argument_list|,
name|locale_quoting_style
argument_list|,
name|s2
argument_list|,
name|s2len
argument_list|)
argument_list|)
expr_stmt|;
block|}
return|return
name|diff
return|;
block|}
end_function

end_unit

