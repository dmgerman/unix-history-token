begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stafil.c    Get the name of the UUCP statistics file.     Copyright (C) 1992 Ian Lance Taylor     This file is part of the Taylor UUCP uuconf library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License    as published by the Free Software Foundation; either version 2 of    the License, or (at your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this library; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
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
name|_uuconf_stafil_rcsid
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
comment|/* Get the name of the UUCP statistics file.  */
end_comment

begin_function
name|int
name|uuconf_statsfile
parameter_list|(
name|pglobal
parameter_list|,
name|pzstats
parameter_list|)
name|pointer
name|pglobal
decl_stmt|;
specifier|const
name|char
modifier|*
modifier|*
name|pzstats
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
name|pzstats
operator|=
name|qglobal
operator|->
name|qprocess
operator|->
name|zstatsfile
expr_stmt|;
return|return
name|UUCONF_SUCCESS
return|;
block|}
end_function

end_unit

