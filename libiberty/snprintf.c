begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Implement the snprintf function.    Copyright (C) 2003 Free Software Foundation, Inc.    Written by Kaveh R. Ghazi<ghazi@caip.rutgers.edu>.  This file is part of the libiberty library.  This library is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This library is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  As a special exception, if you link this library with files compiled with a GNU compiler to produce an executable, this does not cause the resulting executable to be covered by the GNU General Public License. This exception does not however invalidate any other reasons why the executable file might be covered by the GNU General Public License. */
end_comment

begin_comment
comment|/*  @deftypefn Supplemental int snprintf (char *@var{buf}, size_t @var{n}, const char *@var{format}, ...)  This function is similar to sprintf, but it will print at most @var{n} characters.  On error the return value is -1, otherwise it returns the number of characters that would have been printed had @var{n} been sufficiently large, regardless of the actual value of @var{n}.  Note some pre-C99 system libraries do not implement this correctly so users cannot generally rely on the return value if the system version of this function is used.  @end deftypefn  */
end_comment

begin_include
include|#
directive|include
file|"ansidecl.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|ANSI_PROTOTYPES
end_ifdef

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_include
include|#
directive|include
file|<stddef.h>
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
name|int
name|vsnprintf
name|PARAMS
argument_list|(
operator|(
name|char
operator|*
operator|,
name|size_t
operator|,
specifier|const
name|char
operator|*
operator|,
name|va_list
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|snprintf
name|VPARAMS
argument_list|(
operator|(
name|char
operator|*
name|s
operator|,
name|size_t
name|n
operator|,
specifier|const
name|char
operator|*
name|format
operator|,
operator|...
operator|)
argument_list|)
block|{
name|int
name|result
decl_stmt|;
name|VA_OPEN
argument_list|(
name|ap
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|VA_FIXEDARG
argument_list|(
name|ap
argument_list|,
name|char
operator|*
argument_list|,
name|s
argument_list|)
expr_stmt|;
name|VA_FIXEDARG
argument_list|(
name|ap
argument_list|,
name|size_t
argument_list|,
name|n
argument_list|)
expr_stmt|;
name|VA_FIXEDARG
argument_list|(
name|ap
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|format
argument_list|)
expr_stmt|;
name|result
operator|=
name|vsnprintf
argument_list|(
name|s
argument_list|,
name|n
argument_list|,
name|format
argument_list|,
name|ap
argument_list|)
expr_stmt|;
name|VA_CLOSE
argument_list|(
name|ap
argument_list|)
expr_stmt|;
return|return
name|result
return|;
block|}
end_decl_stmt

end_unit

