begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* errno.c    Return the saved errno value.     Copyright (C) 1992 Ian Lance Taylor     This file is part of the Taylor UUCP uuconf library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License    as published by the Free Software Foundation; either version 2 of    the License, or (at your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this library; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     The author of the program may be contacted at ian@airs.com or    c/o Infinity Development Systems, P.O. Box 520, Waltham, MA 02254.    */
end_comment

begin_include
include|#
directive|include
file|"uucnfi.h"
end_include

begin_if
if|#
directive|if
name|USE_RCS_ID
end_if

begin_decl_stmt
specifier|const
name|char
name|_uuconf_errno_rcsid
index|[]
init|=
literal|"$Id: errno.c,v 1.1 1993/08/04 19:34:01 jtc Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_escape
end_escape

begin_comment
comment|/* Return the saved errno value.  */
end_comment

begin_function
name|int
name|uuconf_error_errno
parameter_list|(
name|pglobal
parameter_list|)
name|pointer
name|pglobal
decl_stmt|;
block|{
name|struct
name|sglobal
modifier|*
name|qglobal
init|=
operator|(
expr|struct
name|sglobal
operator|*
operator|)
name|pglobal
decl_stmt|;
if|if
condition|(
name|qglobal
operator|==
name|NULL
condition|)
return|return
name|errno
return|;
else|else
return|return
name|qglobal
operator|->
name|ierrno
return|;
block|}
end_function

end_unit

