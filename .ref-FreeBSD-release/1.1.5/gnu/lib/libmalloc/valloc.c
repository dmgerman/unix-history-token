begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Allocate memory on a page boundary.    Copyright (C) 1991, 1992, 1993 Free Software Foundation, Inc.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with this library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     The author may be reached (Email) at the address mike@ai.mit.edu,    or (US mail) as Mike Haertel c/o Free Software Foundation.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MALLOC_INTERNAL
end_ifndef

begin_define
define|#
directive|define
name|_MALLOC_INTERNAL
end_define

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__GNU_LIBRARY__
end_ifdef

begin_decl_stmt
specifier|extern
name|size_t
name|__getpagesize
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"getpagesize.h"
end_include

begin_define
define|#
directive|define
name|__getpagesize
parameter_list|()
value|getpagesize()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|size_t
name|pagesize
decl_stmt|;
end_decl_stmt

begin_function
name|__ptr_t
name|valloc
parameter_list|(
name|size
parameter_list|)
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
name|pagesize
operator|=
name|__getpagesize
argument_list|()
expr_stmt|;
return|return
name|memalign
argument_list|(
name|pagesize
argument_list|,
name|size
argument_list|)
return|;
block|}
end_function

end_unit

