begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Finish access to a mmap'd malloc managed region.    Copyright 1992 Free Software Foundation, Inc.     Contributed by Fred Fish at Cygnus Support.   fnf@cygnus.com  This file is part of the GNU C Library.  The GNU C Library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  The GNU C Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with the GNU C Library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_comment
comment|/* After sys/types.h, at least for dpx/2.  */
end_comment

begin_include
include|#
directive|include
file|"mmalloc.h"
end_include

begin_comment
comment|/* Terminate access to a mmalloc managed region by unmapping all memory pages    associated with the region, and closing the file descriptor if it is one    that we opened.     Returns NULL on success.     Returns the malloc descriptor on failure, which can subsequently be used    for further action, such as obtaining more information about the nature of    the failure by examining the preserved errno value.     Note that the malloc descriptor that we are using is currently located in    region we are about to unmap, so we first make a local copy of it on the    stack and use the copy. */
end_comment

begin_function
name|PTR
name|mmalloc_detach
parameter_list|(
name|md
parameter_list|)
name|PTR
name|md
decl_stmt|;
block|{
name|struct
name|mdesc
name|mtemp
decl_stmt|;
if|if
condition|(
name|md
operator|!=
name|NULL
condition|)
block|{
name|mtemp
operator|=
operator|*
operator|(
expr|struct
name|mdesc
operator|*
operator|)
name|md
expr_stmt|;
comment|/* Now unmap all the pages associated with this region by asking for a 	 negative increment equal to the current size of the region. */
if|if
condition|(
operator|(
name|mtemp
operator|.
name|morecore
argument_list|(
operator|&
name|mtemp
argument_list|,
name|mtemp
operator|.
name|base
operator|-
name|mtemp
operator|.
name|top
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
comment|/* Update the original malloc descriptor with any changes */
operator|*
operator|(
expr|struct
name|mdesc
operator|*
operator|)
name|md
operator|=
name|mtemp
expr_stmt|;
block|}
else|else
block|{
if|if
condition|(
name|mtemp
operator|.
name|flags
operator|&
name|MMALLOC_DEVZERO
condition|)
block|{
name|close
argument_list|(
name|mtemp
operator|.
name|fd
argument_list|)
expr_stmt|;
block|}
name|md
operator|=
name|NULL
expr_stmt|;
block|}
block|}
return|return
operator|(
name|md
operator|)
return|;
block|}
end_function

end_unit

