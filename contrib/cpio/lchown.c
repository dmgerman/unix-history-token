begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* lchown.c - dummy version of lchown for systems that do not store    file owners of symbolic links.    Copyright (C) 1995 Rodney W. Grimes, Accurate Automation Company     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Written by Rodney W. Grimes<rgrimes@FreeBSD.Org> */
end_comment

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_function
name|int
name|lchown
parameter_list|(
specifier|const
name|char
modifier|*
name|path
parameter_list|,
name|uid_t
name|owner
parameter_list|,
name|gid_t
name|group
parameter_list|)
block|{
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

end_unit

