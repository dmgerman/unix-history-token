begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* allblk.c    Allocate a memory block.     Copyright (C) 1992 Ian Lance Taylor     This file is part of the Taylor UUCP uuconf library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License    as published by the Free Software Foundation; either version 2 of    the License, or (at your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this library; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
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
name|_uuconf_allblk_rcsid
index|[]
init|=
literal|"$FreeBSD$"
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
comment|/* Allocate a new memory block.  If this fails, uuconf_errno will be    set, and the calling routine may return UUCONF_MALLOC_FAILED |    UUCONF_ERROR_ERRNO.  */
end_comment

begin_function
name|pointer
name|uuconf_malloc_block
parameter_list|()
block|{
name|struct
name|sblock
modifier|*
name|qret
decl_stmt|;
name|qret
operator|=
operator|(
expr|struct
name|sblock
operator|*
operator|)
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|sblock
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|qret
operator|==
name|NULL
condition|)
return|return
name|NULL
return|;
name|qret
operator|->
name|qnext
operator|=
name|NULL
expr_stmt|;
name|qret
operator|->
name|ifree
operator|=
literal|0
expr_stmt|;
name|qret
operator|->
name|plast
operator|=
name|NULL
expr_stmt|;
name|qret
operator|->
name|qadded
operator|=
name|NULL
expr_stmt|;
return|return
operator|(
name|pointer
operator|)
name|qret
return|;
block|}
end_function

end_unit

