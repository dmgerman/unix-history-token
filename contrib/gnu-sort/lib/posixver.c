begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Which POSIX version to conform to, for utilities.     Copyright (C) 2002, 2003, 2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Paul Eggert.  */
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
file|"posixver.h"
end_include

begin_include
include|#
directive|include
file|<limits.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

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

begin_ifndef
ifndef|#
directive|ifndef
name|_POSIX2_VERSION
end_ifndef

begin_define
define|#
directive|define
name|_POSIX2_VERSION
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|DEFAULT_POSIX2_VERSION
end_ifndef

begin_define
define|#
directive|define
name|DEFAULT_POSIX2_VERSION
value|_POSIX2_VERSION
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* The POSIX version that utilities should conform to.  The default is    specified by the system.  */
end_comment

begin_function
name|int
name|posix2_version
parameter_list|(
name|void
parameter_list|)
block|{
name|long
name|int
name|v
init|=
name|DEFAULT_POSIX2_VERSION
decl_stmt|;
name|char
specifier|const
modifier|*
name|s
init|=
name|getenv
argument_list|(
literal|"_POSIX2_VERSION"
argument_list|)
decl_stmt|;
if|if
condition|(
name|s
operator|&&
operator|*
name|s
condition|)
block|{
name|char
modifier|*
name|e
decl_stmt|;
name|long
name|int
name|i
init|=
name|strtol
argument_list|(
name|s
argument_list|,
operator|&
name|e
argument_list|,
literal|10
argument_list|)
decl_stmt|;
if|if
condition|(
operator|!
operator|*
name|e
condition|)
name|v
operator|=
name|i
expr_stmt|;
block|}
return|return
name|v
operator|<
name|INT_MIN
condition|?
name|INT_MIN
else|:
name|v
operator|<
name|INT_MAX
condition|?
name|v
else|:
name|INT_MAX
return|;
block|}
end_function

end_unit

