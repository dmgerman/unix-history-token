begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* memalloc.h -- consolidate code for including alloca.h or malloc.h and    defining alloca. */
end_comment

begin_comment
comment|/* Copyright (C) 1993 Free Software Foundation, Inc.     This file is part of GNU Bash, the Bourne Again SHell.     Bash is free software; you can redistribute it and/or modify it under    the terms of the GNU General Public License as published by the Free    Software Foundation; either version 2, or (at your option) any later    version.     Bash is distributed in the hope that it will be useful, but WITHOUT ANY    WARRANTY; without even the implied warranty of MERCHANTABILITY or    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License    for more details.     You should have received a copy of the GNU General Public License along    with Bash; see the file COPYING.  If not, write to the Free Software    Foundation, 675 Mass Ave, Cambridge, MA 02139, USA. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__MEMALLOC_H__
argument_list|)
end_if

begin_define
define|#
directive|define
name|__MEMALLOC_H__
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sparc
argument_list|)
operator|&&
name|defined
argument_list|(
name|sun
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ALLOCA_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ALLOCA_H
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ALLOCA
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ALLOCA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_ALLOCA_H
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_ALLOCA
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_ALLOCA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_ALLOCA_H&& !HAVE_ALLOCA */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|BUILDING_MAKEFILE
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__GNUC__
argument_list|)
end_if

begin_undef
undef|#
directive|undef
name|alloca
end_undef

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

begin_comment
comment|/* !__GNUC__ */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_ALLOCA_H
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|IBMESA
argument_list|)
end_if

begin_include
include|#
directive|include
file|<malloc.h>
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !IBMESA */
end_comment

begin_include
include|#
directive|include
file|<alloca.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !IBMESA */
end_comment

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
comment|/* !HAVE_ALLOCA_H */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__GNUC__ */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !BUILDING_MAKEFILE */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __MEMALLOC_H__ */
end_comment

end_unit

