begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* addblk.c    Add an malloc block to a memory block.     Copyright (C) 1992 Ian Lance Taylor     This file is part of the Taylor UUCP uuconf library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License    as published by the Free Software Foundation; either version 2 of    the License, or (at your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this library; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, Building 200, 1 Kendall Square, Cambridge, MA 02139.    */
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
name|_uuconf_addblk_rcsid
index|[]
init|=
literal|"$Id: addblk.c,v 1.3 1994/01/30 21:14:29 ian Rel $"
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
comment|/* Add a memory buffer allocated by malloc to a memory block.  This is    used by the uuconf_cmd functions so that they don't have to    constantly copy data into memory.  Returns 0 on success, non 0 on    failure. */
end_comment

begin_function
name|int
name|uuconf_add_block
parameter_list|(
name|pblock
parameter_list|,
name|padd
parameter_list|)
name|pointer
name|pblock
decl_stmt|;
name|pointer
name|padd
decl_stmt|;
block|{
name|struct
name|sblock
modifier|*
name|q
init|=
operator|(
expr|struct
name|sblock
operator|*
operator|)
name|pblock
decl_stmt|;
name|struct
name|sadded
modifier|*
name|qnew
decl_stmt|;
name|qnew
operator|=
operator|(
expr|struct
name|sadded
operator|*
operator|)
name|uuconf_malloc
argument_list|(
name|pblock
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|sadded
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|qnew
operator|==
name|NULL
condition|)
return|return
literal|1
return|;
name|qnew
operator|->
name|qnext
operator|=
name|q
operator|->
name|qadded
expr_stmt|;
name|qnew
operator|->
name|padded
operator|=
name|padd
expr_stmt|;
name|q
operator|->
name|qadded
operator|=
name|qnew
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

