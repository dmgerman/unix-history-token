begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* prtsub.c    Port information subroutines.     Copyright (C) 1992 Ian Lance Taylor     This file is part of the Taylor UUCP uuconf library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License    as published by the Free Software Foundation; either version 2 of    the License, or (at your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this library; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
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
name|_uuconf_prtsub_rcsid
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
comment|/* Clear the information in a port.  This can only clear the type    independent information; the port type specific information is    cleared when the type of the port is set.  */
end_comment

begin_function
name|void
name|_uuconf_uclear_port
parameter_list|(
name|qport
parameter_list|)
name|struct
name|uuconf_port
modifier|*
name|qport
decl_stmt|;
block|{
name|qport
operator|->
name|uuconf_zname
operator|=
name|NULL
expr_stmt|;
name|qport
operator|->
name|uuconf_ttype
operator|=
name|UUCONF_PORTTYPE_UNKNOWN
expr_stmt|;
name|qport
operator|->
name|uuconf_zprotocols
operator|=
name|NULL
expr_stmt|;
name|qport
operator|->
name|uuconf_qproto_params
operator|=
name|NULL
expr_stmt|;
comment|/* Note that we do not set RELIABLE_SPECIFIED; this just sets      defaults, so that ``seven-bit true'' does not imply ``reliable      false''.  */
name|qport
operator|->
name|uuconf_ireliable
operator|=
operator|(
name|UUCONF_RELIABLE_RELIABLE
operator||
name|UUCONF_RELIABLE_EIGHT
operator||
name|UUCONF_RELIABLE_FULLDUPLEX
operator|)
expr_stmt|;
name|qport
operator|->
name|uuconf_zlockname
operator|=
name|NULL
expr_stmt|;
name|qport
operator|->
name|uuconf_palloc
operator|=
name|NULL
expr_stmt|;
block|}
end_function

end_unit

