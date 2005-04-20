begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Convert file size to number of blocks on System V-like machines.    Copyright (C) 1990, 1997, 1998, 1999 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by Brian L. Matthews, blm@6sceng.UUCP. */
end_comment

begin_escape
end_escape

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

begin_if
if|#
directive|if
name|HAVE_SYS_PARAM_H
end_if

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|HAVE_STRUCT_STAT_ST_BLOCKS
operator|&&
operator|!
name|defined
name|_POSIX_SOURCE
operator|&&
name|defined
name|BSIZE
end_if

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
name|NINDIR
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__DJGPP__
argument_list|)
end_if

begin_typedef
typedef|typedef
name|long
name|daddr_t
typedef|;
end_typedef

begin_comment
comment|/* for disk address */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Some SysV's, like Irix, seem to lack this.  Hope it's correct. */
end_comment

begin_comment
comment|/* Number of inode pointers per indirect block. */
end_comment

begin_define
define|#
directive|define
name|NINDIR
value|(BSIZE / sizeof (daddr_t))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !NINDIR */
end_comment

begin_comment
comment|/* Number of direct block addresses in an inode. */
end_comment

begin_define
define|#
directive|define
name|NDIR
value|10
end_define

begin_comment
comment|/* Return the number of 512-byte blocks in a file of SIZE bytes. */
end_comment

begin_function
name|off_t
name|st_blocks
parameter_list|(
name|off_t
name|size
parameter_list|)
block|{
name|off_t
name|datablks
init|=
name|size
operator|/
literal|512
operator|+
operator|(
name|size
operator|%
literal|512
operator|!=
literal|0
operator|)
decl_stmt|;
name|off_t
name|indrblks
init|=
literal|0
decl_stmt|;
if|if
condition|(
name|datablks
operator|>
name|NDIR
condition|)
block|{
name|indrblks
operator|=
operator|(
name|datablks
operator|-
name|NDIR
operator|-
literal|1
operator|)
operator|/
name|NINDIR
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|datablks
operator|>
name|NDIR
operator|+
name|NINDIR
condition|)
block|{
name|indrblks
operator|+=
operator|(
name|datablks
operator|-
name|NDIR
operator|-
name|NINDIR
operator|-
literal|1
operator|)
operator|/
operator|(
name|NINDIR
operator|*
name|NINDIR
operator|)
operator|+
literal|1
expr_stmt|;
if|if
condition|(
name|datablks
operator|>
name|NDIR
operator|+
name|NINDIR
operator|+
name|NINDIR
operator|*
name|NINDIR
condition|)
name|indrblks
operator|++
expr_stmt|;
block|}
block|}
return|return
name|datablks
operator|+
name|indrblks
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* This declaration is solely to ensure that after preprocessing    this file is never empty.  */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|textutils_fileblocks_unused
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

