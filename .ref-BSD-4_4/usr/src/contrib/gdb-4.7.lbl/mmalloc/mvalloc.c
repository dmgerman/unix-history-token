begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Allocate memory on a page boundary.    Copyright (C) 1991 Free Software Foundation, Inc.  The GNU C Library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  The GNU C Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with the GNU C Library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|"mmalloc.h"
end_include

begin_comment
comment|/* Cache the pagesize for the current host machine.  Note that if the host    does not readily provide a getpagesize() function, we need to emulate it    elsewhere, not clutter up this file with lots of kluges to try to figure    it out. */
end_comment

begin_decl_stmt
specifier|static
name|size_t
name|pagesize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|getpagesize
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|PTR
name|mvalloc
parameter_list|(
name|md
parameter_list|,
name|size
parameter_list|)
name|PTR
name|md
decl_stmt|;
name|size_t
name|size
decl_stmt|;
block|{
if|if
condition|(
name|pagesize
operator|==
literal|0
condition|)
block|{
name|pagesize
operator|=
name|getpagesize
argument_list|()
expr_stmt|;
block|}
return|return
operator|(
name|mmemalign
argument_list|(
name|md
argument_list|,
name|pagesize
argument_list|,
name|size
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

