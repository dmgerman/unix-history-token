begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// This may look like C code, but it is really -*- C++ -*-
end_comment

begin_comment
comment|/*  Copyright (C) 1994 Free Software Foundation     written by Jason Merrill (jason@cygnus.com)  This file is part of the GNU C++ Library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details. You should have received a copy of the GNU Library General Public License along with this library; if not, write to the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_defines_h
end_ifndef

begin_define
define|#
directive|define
name|_defines_h
end_define

begin_include
include|#
directive|include
file|<_G_config.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
end_include

begin_decl_stmt
specifier|const
name|size_t
name|NPOS
init|=
call|(
name|size_t
call|)
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_typedef
typedef|typedef
name|void
name|fvoid_t
parameter_list|()
function_decl|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|_WINT_T
end_ifndef

begin_define
define|#
directive|define
name|_WINT_T
end_define

begin_typedef
typedef|typedef
name|_G_wint_t
name|wint_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

