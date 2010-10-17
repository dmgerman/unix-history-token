begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Implement the stpcpy function.    Copyright (C) 2003 Free Software Foundation, Inc.    Written by Kaveh R. Ghazi<ghazi@caip.rutgers.edu>.  This file is part of the libiberty library. Libiberty is free software; you can redistribute it and/or modify it under the terms of the GNU Library General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  Libiberty is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Library General Public License for more details.  You should have received a copy of the GNU Library General Public License along with libiberty; see the file COPYING.LIB.  If not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental char* stpcpy (char *@var{dst}, const char *@var{src})  Copies the string @var{src} into @var{dst}.  Returns a pointer to @var{dst} + strlen(@var{src}).  @end deftypefn  */
end_comment

begin_include
include|#
directive|include
file|<ansidecl.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ANSI_PROTOTYPES
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
specifier|extern
name|size_t
name|strlen
name|PARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|PTR
name|memcpy
name|PARAMS
argument_list|(
operator|(
name|PTR
operator|,
specifier|const
name|PTR
operator|,
name|size_t
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_function
name|char
modifier|*
name|stpcpy
parameter_list|(
name|dst
parameter_list|,
name|src
parameter_list|)
name|char
modifier|*
name|dst
decl_stmt|;
specifier|const
name|char
modifier|*
name|src
decl_stmt|;
block|{
specifier|const
name|size_t
name|len
init|=
name|strlen
argument_list|(
name|src
argument_list|)
decl_stmt|;
return|return
operator|(
name|char
operator|*
operator|)
name|memcpy
argument_list|(
name|dst
argument_list|,
name|src
argument_list|,
name|len
operator|+
literal|1
argument_list|)
operator|+
name|len
return|;
block|}
end_function

end_unit

