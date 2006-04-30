begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* isdir.c -- determine whether a directory exists    Copyright (C) 1990, 1998 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_if
if|#
directive|if
name|STAT_MACROS_BROKEN
end_if

begin_undef
undef|#
directive|undef
name|S_ISDIR
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
name|S_ISDIR
operator|&&
name|defined
name|S_IFDIR
end_if

begin_define
define|#
directive|define
name|S_ISDIR
parameter_list|(
name|Mode
parameter_list|)
value|(((Mode)& S_IFMT) == S_IFDIR)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If PATH is an existing directory or symbolic link to a directory,    return nonzero, else 0.  */
end_comment

begin_function
name|int
name|isdir
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|)
block|{
name|struct
name|stat
name|stats
decl_stmt|;
return|return
name|stat
argument_list|(
name|path
argument_list|,
operator|&
name|stats
argument_list|)
operator|==
literal|0
operator|&&
name|S_ISDIR
argument_list|(
name|stats
operator|.
name|st_mode
argument_list|)
return|;
block|}
end_function

end_unit

