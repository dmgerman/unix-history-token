begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Work around the bug in some systems whereby rename fails when the source    path has a trailing slash.  The rename from SunOS 4.1.1_U1 has this bug.    Copyright (C) 2001 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* written by Volker Borchert */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|HAVE_STDLIB_H
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STRING_H
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"dirname.h"
end_include

begin_include
include|#
directive|include
file|"xalloc.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_DECL_FREE
end_ifndef

begin_expr_stmt
literal|"this configure-time declaration test was not run"
endif|#
directive|endif
if|#
directive|if
operator|!
name|HAVE_DECL_FREE
name|void
name|free
argument_list|()
expr_stmt|;
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Rename the file SRC_PATH to DST_PATH, removing any trailing    slashes from SRC_PATH.  Needed for SunOS 4.1.1_U1.  */
end_comment

begin_function
name|int
name|rpl_rename
parameter_list|(
specifier|const
name|char
modifier|*
name|src_path
parameter_list|,
specifier|const
name|char
modifier|*
name|dst_path
parameter_list|)
block|{
name|char
modifier|*
name|src_temp
decl_stmt|;
name|int
name|ret_val
decl_stmt|;
name|size_t
name|s_len
init|=
name|strlen
argument_list|(
name|src_path
argument_list|)
decl_stmt|;
if|if
condition|(
name|s_len
operator|&&
name|src_path
index|[
name|s_len
operator|-
literal|1
index|]
operator|==
literal|'/'
condition|)
block|{
name|src_temp
operator|=
name|xstrdup
argument_list|(
name|src_path
argument_list|)
expr_stmt|;
name|strip_trailing_slashes
argument_list|(
name|src_temp
argument_list|)
expr_stmt|;
block|}
else|else
name|src_temp
operator|=
operator|(
name|char
operator|*
operator|)
name|src_path
expr_stmt|;
name|ret_val
operator|=
name|rename
argument_list|(
name|src_temp
argument_list|,
name|dst_path
argument_list|)
expr_stmt|;
if|if
condition|(
name|src_temp
operator|!=
name|src_path
condition|)
name|free
argument_list|(
name|src_temp
argument_list|)
expr_stmt|;
return|return
name|ret_val
return|;
block|}
end_function

end_unit

