begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* gawkmisc.c --- miscellanious gawk routines that are OS specific.      Copyright (C) 1986, 1988, 1989, 1991 - 96 the Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_decl_stmt
name|char
name|quote
init|=
literal|'\''
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|defpath
init|=
name|DEFPATH
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|envsep
init|=
literal|':'
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* gawk_name --- pull out the "gawk" part from how the OS called us */
end_comment

begin_function
name|char
modifier|*
name|gawk_name
parameter_list|(
name|filespec
parameter_list|)
specifier|const
name|char
modifier|*
name|filespec
decl_stmt|;
block|{
name|char
modifier|*
name|p
decl_stmt|;
comment|/* "path/name" -> "name" */
name|p
operator|=
name|strrchr
argument_list|(
name|filespec
argument_list|,
literal|'/'
argument_list|)
expr_stmt|;
return|return
operator|(
name|p
operator|==
name|NULL
condition|?
operator|(
name|char
operator|*
operator|)
name|filespec
else|:
name|p
operator|+
literal|1
operator|)
return|;
block|}
end_function

begin_comment
comment|/* os_arg_fixup --- fixup the command line */
end_comment

begin_function
name|void
name|os_arg_fixup
parameter_list|(
name|argcp
parameter_list|,
name|argvp
parameter_list|)
name|int
modifier|*
name|argcp
decl_stmt|;
name|char
modifier|*
modifier|*
modifier|*
name|argvp
decl_stmt|;
block|{
comment|/* no-op */
return|return;
block|}
end_function

begin_comment
comment|/* os_devopen --- open special per-OS devices */
end_comment

begin_function
name|int
name|os_devopen
parameter_list|(
name|name
parameter_list|,
name|flag
parameter_list|)
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
name|int
name|flag
decl_stmt|;
block|{
comment|/* no-op */
return|return
name|INVALID_HANDLE
return|;
block|}
end_function

begin_comment
comment|/* optimal_bufsize --- determine optimal buffer size */
end_comment

begin_function
name|int
name|optimal_bufsize
parameter_list|(
name|fd
parameter_list|,
name|stb
parameter_list|)
name|int
name|fd
decl_stmt|;
name|struct
name|stat
modifier|*
name|stb
decl_stmt|;
block|{
comment|/* force all members to zero in case OS doesn't use all of them. */
name|memset
argument_list|(
name|stb
argument_list|,
literal|'\0'
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|stat
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 * System V.n, n< 4, doesn't have the file system block size in the 	 * stat structure. So we have to make some sort of reasonable 	 * guess. We use stdio's BUFSIZ, since that is what it was 	 * meant for in the first place. 	 */
ifdef|#
directive|ifdef
name|HAVE_ST_BLKSIZE
define|#
directive|define
name|DEFBLKSIZE
value|(stb->st_blksize ? stb->st_blksize : BUFSIZ)
else|#
directive|else
define|#
directive|define
name|DEFBLKSIZE
value|BUFSIZ
endif|#
directive|endif
if|if
condition|(
name|isatty
argument_list|(
name|fd
argument_list|)
condition|)
return|return
name|BUFSIZ
return|;
if|if
condition|(
name|fstat
argument_list|(
name|fd
argument_list|,
name|stb
argument_list|)
operator|==
operator|-
literal|1
condition|)
name|fatal
argument_list|(
literal|"can't stat fd %d (%s)"
argument_list|,
name|fd
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|lseek
argument_list|(
name|fd
argument_list|,
operator|(
name|off_t
operator|)
literal|0
argument_list|,
literal|0
argument_list|)
operator|==
operator|-
literal|1
condition|)
comment|/* not a regular file */
return|return
name|DEFBLKSIZE
return|;
if|if
condition|(
name|stb
operator|->
name|st_size
operator|>
literal|0
operator|&&
name|stb
operator|->
name|st_size
operator|<
name|DEFBLKSIZE
condition|)
comment|/* small file */
return|return
name|stb
operator|->
name|st_size
return|;
return|return
name|DEFBLKSIZE
return|;
block|}
end_function

begin_comment
comment|/* ispath --- return true if path has directory components */
end_comment

begin_function
name|int
name|ispath
parameter_list|(
name|file
parameter_list|)
specifier|const
name|char
modifier|*
name|file
decl_stmt|;
block|{
return|return
operator|(
name|strchr
argument_list|(
name|file
argument_list|,
literal|'/'
argument_list|)
operator|!=
name|NULL
operator|)
return|;
block|}
end_function

begin_comment
comment|/* isdirpunct --- return true if char is a directory separator */
end_comment

begin_function
name|int
name|isdirpunct
parameter_list|(
name|c
parameter_list|)
name|int
name|c
decl_stmt|;
block|{
return|return
operator|(
name|c
operator|==
literal|'/'
operator|)
return|;
block|}
end_function

end_unit

