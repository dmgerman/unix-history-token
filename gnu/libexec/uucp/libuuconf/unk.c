begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* unk.c    Get information about an unknown system.     Copyright (C) 1992 Ian Lance Taylor     This file is part of the Taylor UUCP uuconf library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License    as published by the Free Software Foundation; either version 2 of    the License, or (at your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this library; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
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
name|_uuconf_unk_rcsid
index|[]
init|=
literal|"$FreeBSD$"
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
comment|/* Get information about an unknown system.  If we are using    HAVE_TAYLOR_CONFIG, we just use it.  Otherwise if we are using    HAVE_HDB_CONFIG, we use it.  Otherwise we return a default system.    This isn't right for HAVE_V2_CONFIG, because it is possible to    specify default directories to read and write in USERFILE.    However, I'm not going to bother to write that code unless somebody    actually wants it.  */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_function
name|int
name|uuconf_system_unknown
parameter_list|(
name|pglobal
parameter_list|,
name|qsys
parameter_list|)
name|pointer
name|pglobal
decl_stmt|;
name|struct
name|uuconf_system
modifier|*
name|qsys
decl_stmt|;
block|{
if|#
directive|if
name|HAVE_TAYLOR_CONFIG
return|return
name|uuconf_taylor_system_unknown
argument_list|(
name|pglobal
argument_list|,
name|qsys
argument_list|)
return|;
else|#
directive|else
comment|/* ! HAVE_TAYLOR_CONFIG */
if|#
directive|if
name|HAVE_HDB_CONFIG
return|return
name|uuconf_hdb_system_unknown
argument_list|(
name|pglobal
argument_list|,
name|qsys
argument_list|)
return|;
else|#
directive|else
comment|/* ! HAVE_HDB_CONFIG */
if|#
directive|if
name|HAVE_V2_CONFIG
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
name|_uuconf_uclear_system
argument_list|(
name|qsys
argument_list|)
expr_stmt|;
name|qsys
operator|->
name|uuconf_palloc
operator|=
name|uuconf_malloc_block
argument_list|()
expr_stmt|;
if|if
condition|(
name|qsys
operator|->
name|uuconf_palloc
operator|==
name|NULL
condition|)
block|{
name|qglobal
operator|->
name|ierrno
operator|=
name|errno
expr_stmt|;
return|return
name|UUCONF_MALLOC_FAILED
operator||
name|UUCONF_ERROR_ERRNO
return|;
block|}
return|return
name|_uuconf_isystem_basic_default
argument_list|(
name|qglobal
argument_list|,
name|qsys
argument_list|)
return|;
else|#
directive|else
comment|/* ! HAVE_V2_CONFIG */
return|return
name|UUCONF_NOT_FOUND
return|;
endif|#
directive|endif
comment|/* ! HAVE_V2_CONFIG */
endif|#
directive|endif
comment|/* ! HAVE_HDB_CONFIG */
endif|#
directive|endif
comment|/* ! HAVE_TAYLOR_CONFIG */
block|}
end_function

end_unit

