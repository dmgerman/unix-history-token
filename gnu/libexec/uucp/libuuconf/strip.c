begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* maxuxq.c    Get information about what things should be stripped.     Copyright (C) 1995 Ian Lance Taylor     This file is part of the Taylor UUCP uuconf library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License    as published by the Free Software Foundation; either version 2 of    the License, or (at your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this library; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
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
name|_uuconf_strip_rcsid
index|[]
init|=
literal|"$FreeBSD$"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Get information about what types of global information should be    stripped.  There are currently only two, which we return as a    couple of bits.  We store them as two separate variables, so we    don't need to have a special function to set the values correctly.  */
end_comment

begin_function
name|int
name|uuconf_strip
parameter_list|(
name|pglobal
parameter_list|,
name|pistrip
parameter_list|)
name|pointer
name|pglobal
decl_stmt|;
name|int
modifier|*
name|pistrip
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
operator|*
name|pistrip
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|qglobal
operator|->
name|qprocess
operator|->
name|fstrip_login
condition|)
operator|*
name|pistrip
operator||=
name|UUCONF_STRIP_LOGIN
expr_stmt|;
if|if
condition|(
name|qglobal
operator|->
name|qprocess
operator|->
name|fstrip_proto
condition|)
operator|*
name|pistrip
operator||=
name|UUCONF_STRIP_PROTO
expr_stmt|;
return|return
name|UUCONF_SUCCESS
return|;
block|}
end_function

end_unit

