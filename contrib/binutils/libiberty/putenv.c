begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1991, 1994, 1995, 1996 Free Software Foundation, Inc.    This file based on putenv.c in the GNU C Library.     The GNU C Library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License as    published by the Free Software Foundation; either version 2 of the    License, or (at your option) any later version.     The GNU C Library is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with the GNU C Library; see the file COPYING.LIB.  If not,    write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_AIX
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_pragma
pragma|#
directive|pragma
name|alloca
end_pragma

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_if
if|#
directive|if
name|HAVE_STDLIB_H
end_if

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|HAVE_STRING_H
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_ALLOCA_H
end_ifdef

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_else
else|#
directive|else
end_else

begin_ifndef
ifndef|#
directive|ifndef
name|alloca
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|__GNUC__
end_ifdef

begin_define
define|#
directive|define
name|alloca
value|__builtin_alloca
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|char
modifier|*
name|alloca
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* alloca */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ALLOCA_H */
end_comment

begin_comment
comment|/* Below this point, it's verbatim code from the glibc-2.0 implementation */
end_comment

begin_comment
comment|/* Put STRING, which is of the form "NAME=VALUE", in the environment.  */
end_comment

begin_function
name|int
name|putenv
parameter_list|(
name|string
parameter_list|)
specifier|const
name|char
modifier|*
name|string
decl_stmt|;
block|{
specifier|const
name|char
modifier|*
specifier|const
name|name_end
init|=
name|strchr
argument_list|(
name|string
argument_list|,
literal|'='
argument_list|)
decl_stmt|;
if|if
condition|(
name|name_end
condition|)
block|{
name|char
modifier|*
name|name
init|=
operator|(
name|char
operator|*
operator|)
name|alloca
argument_list|(
name|name_end
operator|-
name|string
operator|+
literal|1
argument_list|)
decl_stmt|;
name|memcpy
argument_list|(
name|name
argument_list|,
name|string
argument_list|,
name|name_end
operator|-
name|string
argument_list|)
expr_stmt|;
name|name
index|[
name|name_end
operator|-
name|string
index|]
operator|=
literal|'\0'
expr_stmt|;
return|return
name|setenv
argument_list|(
name|name
argument_list|,
name|name_end
operator|+
literal|1
argument_list|,
literal|1
argument_list|)
return|;
block|}
name|unsetenv
argument_list|(
name|string
argument_list|)
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

