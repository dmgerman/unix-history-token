begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Convert file size to number of blocks on System V-like machines.    Copyright (C) 1990 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Written by Brian L. Matthews, blm@6sceng.UUCP. */
end_comment

begin_escape
end_escape

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ST_BLOCKS_MISSING
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|_POSIX_SOURCE
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|NINDIR
end_ifndef

begin_comment
comment|/* Some SysV's, like Irix, seem to lack these.  Hope they're correct. */
end_comment

begin_comment
comment|/* Size of a indirect block, in bytes. */
end_comment

begin_define
define|#
directive|define
name|BSIZE
value|1024
end_define

begin_comment
comment|/* Number of inode pointers per indirect block. */
end_comment

begin_define
define|#
directive|define
name|NINDIR
value|(BSIZE/sizeof(daddr_t))
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
name|long
name|st_blocks
parameter_list|(
name|size
parameter_list|)
name|long
name|size
decl_stmt|;
block|{
name|long
name|datablks
init|=
operator|(
name|size
operator|+
literal|512
operator|-
literal|1
operator|)
operator|/
literal|512
decl_stmt|;
name|long
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

begin_endif
endif|#
directive|endif
end_endif

end_unit

