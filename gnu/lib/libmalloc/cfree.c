begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 1993 Free Software Foundation, Inc. This file is part of the GNU C Library.  The GNU C Library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  The GNU C Library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with the GNU C Library; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
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

begin_undef
undef|#
directive|undef
name|cfree
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|_LIBC
end_ifdef

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_include
include|#
directive|include
file|<gnu-stabs.h>
end_include

begin_macro
name|function_alias
argument_list|(
argument|cfree
argument_list|,
argument|free
argument_list|,
argument|void
argument_list|,
argument|(ptr)
argument_list|,
argument|DEFUN(cfree, (ptr), PTR ptr)
argument_list|)
end_macro

begin_else
else|#
directive|else
end_else

begin_function
name|void
name|cfree
parameter_list|(
name|ptr
parameter_list|)
name|__ptr_t
name|ptr
decl_stmt|;
block|{
name|free
argument_list|(
name|ptr
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

end_unit

