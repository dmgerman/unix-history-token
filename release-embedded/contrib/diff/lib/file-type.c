begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Return a string describing the type of a file.     Copyright (C) 1993, 1994, 2001, 2002, 2004 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|"file-type.h"
end_include

begin_include
include|#
directive|include
file|<gettext.h>
end_include

begin_define
define|#
directive|define
name|_
parameter_list|(
name|text
parameter_list|)
value|gettext (text)
end_define

begin_function
name|char
specifier|const
modifier|*
name|file_type
parameter_list|(
name|struct
name|stat
specifier|const
modifier|*
name|st
parameter_list|)
block|{
comment|/* See POSIX 1003.1-2001 XCU Table 4-8 lines 17093-17107 for some of      these formats.       To keep diagnostics grammatical in English, the returned string      must start with a consonant.  */
if|if
condition|(
name|S_ISREG
argument_list|(
name|st
operator|->
name|st_mode
argument_list|)
condition|)
return|return
name|st
operator|->
name|st_size
operator|==
literal|0
condition|?
name|_
argument_list|(
literal|"regular empty file"
argument_list|)
else|:
name|_
argument_list|(
literal|"regular file"
argument_list|)
return|;
if|if
condition|(
name|S_ISDIR
argument_list|(
name|st
operator|->
name|st_mode
argument_list|)
condition|)
return|return
name|_
argument_list|(
literal|"directory"
argument_list|)
return|;
if|if
condition|(
name|S_ISBLK
argument_list|(
name|st
operator|->
name|st_mode
argument_list|)
condition|)
return|return
name|_
argument_list|(
literal|"block special file"
argument_list|)
return|;
if|if
condition|(
name|S_ISCHR
argument_list|(
name|st
operator|->
name|st_mode
argument_list|)
condition|)
return|return
name|_
argument_list|(
literal|"character special file"
argument_list|)
return|;
if|if
condition|(
name|S_ISFIFO
argument_list|(
name|st
operator|->
name|st_mode
argument_list|)
condition|)
return|return
name|_
argument_list|(
literal|"fifo"
argument_list|)
return|;
if|if
condition|(
name|S_ISLNK
argument_list|(
name|st
operator|->
name|st_mode
argument_list|)
condition|)
return|return
name|_
argument_list|(
literal|"symbolic link"
argument_list|)
return|;
if|if
condition|(
name|S_ISSOCK
argument_list|(
name|st
operator|->
name|st_mode
argument_list|)
condition|)
return|return
name|_
argument_list|(
literal|"socket"
argument_list|)
return|;
if|if
condition|(
name|S_TYPEISMQ
argument_list|(
name|st
argument_list|)
condition|)
return|return
name|_
argument_list|(
literal|"message queue"
argument_list|)
return|;
if|if
condition|(
name|S_TYPEISSEM
argument_list|(
name|st
argument_list|)
condition|)
return|return
name|_
argument_list|(
literal|"semaphore"
argument_list|)
return|;
if|if
condition|(
name|S_TYPEISSHM
argument_list|(
name|st
argument_list|)
condition|)
return|return
name|_
argument_list|(
literal|"shared memory object"
argument_list|)
return|;
if|if
condition|(
name|S_TYPEISTMO
argument_list|(
name|st
argument_list|)
condition|)
return|return
name|_
argument_list|(
literal|"typed memory object"
argument_list|)
return|;
return|return
name|_
argument_list|(
literal|"weird file"
argument_list|)
return|;
block|}
end_function

end_unit

