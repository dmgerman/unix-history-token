begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* remunk.c    Get the name of the remote.unknown shell script.     Copyright (C) 1992 Ian Lance Taylor     This file is part of the Taylor UUCP uuconf library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License    as published by the Free Software Foundation; either version 2 of    the License, or (at your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this library; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.     The author of the program may be contacted at ian@airs.com or    c/o Infinity Development Systems, P.O. Box 520, Waltham, MA 02254.    */
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
name|_uuconf_remunk_rcsid
index|[]
init|=
literal|"$Id: remunk.c,v 1.1 1993/08/04 19:34:59 jtc Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_escape
end_escape

begin_comment
comment|/* Get the name of the remote.unknown shell script.  */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|int
name|uuconf_remote_unknown
parameter_list|(
name|pglobal
parameter_list|,
name|pzname
parameter_list|)
name|pointer
name|pglobal
decl_stmt|;
name|char
modifier|*
modifier|*
name|pzname
decl_stmt|;
block|{
if|#
directive|if
name|HAVE_TAYLOR_CONFIG
operator|||
operator|!
name|HAVE_HDB_CONFIG
return|return
name|UUCONF_NOT_FOUND
return|;
else|#
directive|else
return|return
name|uuconf_hdb_remote_unknown
argument_list|(
name|pglobal
argument_list|,
name|pzname
argument_list|)
return|;
endif|#
directive|endif
block|}
end_function

end_unit

