begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* mrgblk.c    Merge two memory blocks together.     Copyright (C) 1992 Ian Lance Taylor     This file is part of the Taylor UUCP uuconf library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License    as published by the Free Software Foundation; either version 2 of    the License, or (at your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this library; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     The author of the program may be contacted at ian@airs.com or    c/o Infinity Development Systems, P.O. Box 520, Waltham, MA 02254.    */
end_comment

begin_include
include|#
directive|include
file|"uucnfi.h"
end_include

begin_if
if|#
directive|if
name|USE_RCS_ID
end_if

begin_decl_stmt
specifier|const
name|char
name|_uuconf_mrgblk_rcsid
index|[]
init|=
literal|"$Id: mrgblk.c,v 1.1 1993/08/04 19:34:50 jtc Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"alloc.h"
end_include

begin_escape
end_escape

begin_comment
comment|/* Merge one memory block into another one, returning the combined    memory block.  */
end_comment

begin_function
name|pointer
name|_uuconf_pmalloc_block_merge
parameter_list|(
name|p1
parameter_list|,
name|p2
parameter_list|)
name|pointer
name|p1
decl_stmt|;
name|pointer
name|p2
decl_stmt|;
block|{
name|struct
name|sblock
modifier|*
name|q1
init|=
operator|(
expr|struct
name|sblock
operator|*
operator|)
name|p1
decl_stmt|;
name|struct
name|sblock
modifier|*
name|q2
init|=
operator|(
expr|struct
name|sblock
operator|*
operator|)
name|p2
decl_stmt|;
name|struct
name|sblock
modifier|*
modifier|*
name|pq
decl_stmt|;
for|for
control|(
name|pq
operator|=
operator|&
name|q1
init|;
operator|*
name|pq
operator|!=
name|NULL
condition|;
name|pq
operator|=
operator|&
operator|(
operator|*
name|pq
operator|)
operator|->
name|qnext
control|)
empty_stmt|;
operator|*
name|pq
operator|=
name|q2
expr_stmt|;
return|return
operator|(
name|pointer
operator|)
name|q1
return|;
block|}
end_function

end_unit

