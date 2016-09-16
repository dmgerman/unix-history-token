begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copy memory to memory until the specified number of bytes    has been copied.  Overlap is NOT handled correctly.    Copyright (C) 1991, 1997, 2003 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Contributed by Torbjorn Granlund (tege@sics.se).     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Lesser General Public    License as published by the Free Software Foundation; either    version 2.1 of the License, or (at your option) any later version.     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Lesser General Public License for more details.     You should have received a copy of the GNU Lesser General Public    License along with the GNU C Library; if not, see<http://www.gnu.org/licenses/>.  */
end_comment

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"memcopy.h"
end_include

begin_include
include|#
directive|include
file|"pagecopy.h"
end_include

begin_undef
undef|#
directive|undef
name|memcpy
end_undef

begin_function
name|void
modifier|*
name|memcpy
parameter_list|(
name|dstpp
parameter_list|,
name|srcpp
parameter_list|,
name|len
parameter_list|)
name|void
modifier|*
name|dstpp
decl_stmt|;
specifier|const
name|void
modifier|*
name|srcpp
decl_stmt|;
name|size_t
name|len
decl_stmt|;
block|{
name|unsigned
name|long
name|int
name|dstp
init|=
operator|(
name|long
name|int
operator|)
name|dstpp
decl_stmt|;
name|unsigned
name|long
name|int
name|srcp
init|=
operator|(
name|long
name|int
operator|)
name|srcpp
decl_stmt|;
comment|/* Copy from the beginning to the end.  */
comment|/* If there not too few bytes to copy, use word copy.  */
if|if
condition|(
name|len
operator|>=
name|OP_T_THRES
condition|)
block|{
comment|/* Copy just a few bytes to make DSTP aligned.  */
name|len
operator|-=
operator|(
operator|-
name|dstp
operator|)
operator|%
name|OPSIZ
expr_stmt|;
name|BYTE_COPY_FWD
argument_list|(
name|dstp
argument_list|,
name|srcp
argument_list|,
operator|(
operator|-
name|dstp
operator|)
operator|%
name|OPSIZ
argument_list|)
expr_stmt|;
comment|/* Copy whole pages from SRCP to DSTP by virtual address manipulation, 	 as much as possible.  */
name|PAGE_COPY_FWD_MAYBE
argument_list|(
name|dstp
argument_list|,
name|srcp
argument_list|,
name|len
argument_list|,
name|len
argument_list|)
expr_stmt|;
comment|/* Copy from SRCP to DSTP taking advantage of the known alignment of 	 DSTP.  Number of bytes remaining is put in the third argument, 	 i.e. in LEN.  This number may vary from machine to machine.  */
name|WORD_COPY_FWD
argument_list|(
name|dstp
argument_list|,
name|srcp
argument_list|,
name|len
argument_list|,
name|len
argument_list|)
expr_stmt|;
comment|/* Fall out and copy the tail.  */
block|}
comment|/* There are just a few bytes to copy.  Use byte memory operations.  */
name|BYTE_COPY_FWD
argument_list|(
name|dstp
argument_list|,
name|srcp
argument_list|,
name|len
argument_list|)
expr_stmt|;
return|return
name|dstpp
return|;
block|}
end_function

end_unit

