begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* memcpy    Copyright (C) 1991 Free Software Foundation, Inc.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  NAME  	memcpy -- copy memory regions of arbitary length  SYNOPSIS  	void* memcpy (void *out, const void *in, size_t n);  DESCRIPTION  	Copy LENGTH bytes from memory region pointed to by IN to memory 	region pointed to by OUT. */
end_comment

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|size_t
value|unsigned long
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|PTR
name|DEFUN
argument_list|(
name|memcpy
argument_list|,
operator|(
name|out
operator|,
name|in
operator|,
name|length
operator|)
argument_list|,
name|PTR
name|out
name|AND
name|CONST
name|PTR
name|in
name|AND
name|size_t
name|length
argument_list|)
block|{
name|bcopy
argument_list|(
name|in
argument_list|,
name|out
argument_list|,
name|length
argument_list|)
expr_stmt|;
return|return
name|out
return|;
block|}
end_decl_stmt

end_unit

