begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* hsys.c    User function to get a system from the HDB configuration files.     Copyright (C) 1992 Ian Lance Taylor     This file is part of the Taylor UUCP uuconf library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License    as published by the Free Software Foundation; either version 2 of    the License, or (at your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this library; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
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
name|_uuconf_hsys_rcsid
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
comment|/* Get system information from the HDB configuration files.  This is a    wrapper for the internal function which makes sure that every field    gets a default value.  */
end_comment

begin_function
name|int
name|uuconf_hdb_system_info
parameter_list|(
name|pglobal
parameter_list|,
name|zsystem
parameter_list|,
name|qsys
parameter_list|)
name|pointer
name|pglobal
decl_stmt|;
specifier|const
name|char
modifier|*
name|zsystem
decl_stmt|;
name|struct
name|uuconf_system
modifier|*
name|qsys
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
name|int
name|iret
decl_stmt|;
name|iret
operator|=
name|_uuconf_ihdb_system_internal
argument_list|(
name|qglobal
argument_list|,
name|zsystem
argument_list|,
name|qsys
argument_list|)
expr_stmt|;
if|if
condition|(
name|iret
operator|!=
name|UUCONF_SUCCESS
condition|)
return|return
name|iret
return|;
return|return
name|_uuconf_isystem_basic_default
argument_list|(
name|qglobal
argument_list|,
name|qsys
argument_list|)
return|;
block|}
end_function

end_unit

