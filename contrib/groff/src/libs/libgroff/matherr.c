begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1989, 1990, 1991, 1992 Free Software Foundation, Inc.      Written by James Clark (jjc@jclark.com)  This file is part of groff.  groff is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  groff is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with groff; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA. */
end_comment

begin_include
include|#
directive|include
file|<math.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_STRUCT_EXCEPTION
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|TLOSS
end_ifdef

begin_function
name|int
name|matherr
parameter_list|(
name|exc
parameter_list|)
name|struct
name|exception
modifier|*
name|exc
decl_stmt|;
block|{
switch|switch
condition|(
name|exc
operator|->
name|type
condition|)
block|{
case|case
name|SING
case|:
case|case
name|DOMAIN
case|:
name|errno
operator|=
name|EDOM
expr_stmt|;
break|break;
case|case
name|OVERFLOW
case|:
case|case
name|UNDERFLOW
case|:
case|case
name|TLOSS
case|:
case|case
name|PLOSS
case|:
name|errno
operator|=
name|ERANGE
expr_stmt|;
break|break;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TLOSS */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_STRUCT_EXCEPTION */
end_comment

end_unit

