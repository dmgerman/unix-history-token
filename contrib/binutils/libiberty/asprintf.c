begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Like sprintf but provides a pointer to malloc'd storage, which must    be freed by the caller.    Copyright (C) 1997 Free Software Foundation, Inc.    Contributed by Cygnus Solutions.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_include
include|#
directive|include
file|"libiberty.h"
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|ANSI_PROTOTYPES
argument_list|)
operator|||
name|defined
argument_list|(
name|ALMOST_STDC
argument_list|)
end_if

begin_define
define|#
directive|define
name|USE_STDARG
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_STDARG
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VARARGS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|USE_STDARG
end_ifdef

begin_function
name|int
name|asprintf
parameter_list|(
name|char
modifier|*
modifier|*
name|buf
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
else|#
directive|else
function|int asprintf
parameter_list|(
name|buf
parameter_list|,
name|fmt
parameter_list|,
name|va_alist
parameter_list|)
name|char
modifier|*
modifier|*
name|buf
decl_stmt|;
specifier|const
name|char
modifier|*
name|fmt
decl_stmt|;
function|va_dcl
endif|#
directive|endif
block|{
name|int
name|status
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
ifdef|#
directive|ifdef
name|USE_STDARG
name|va_start
argument_list|(
name|ap
argument_list|,
name|fmt
argument_list|)
expr_stmt|;
else|#
directive|else
name|va_start
argument_list|(
name|ap
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|status
operator|=
name|vasprintf
argument_list|(
name|buf
argument_list|,
name|fmt
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|status
return|;
block|}
end_function

end_unit

