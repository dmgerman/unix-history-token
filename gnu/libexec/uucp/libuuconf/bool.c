begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* bool.c    Parse a boolean string into a variable.     Copyright (C) 1992 Ian Lance Taylor     This file is part of the Taylor UUCP uuconf library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License    as published by the Free Software Foundation; either version 2 of    the License, or (at your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this library; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
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
name|_uuconf_bool_rcsid
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
comment|/* Parse a boolean string into a variable.  This is called by    uuconf_cmd_args, as well as other functions.  The parsing is done    in a single place to make it easy to change.  This should return an    error code, including both UUCONF_CMDTABRET_KEEP and    UUCONF_CMDTABRET_EXIT if appropriate.  */
end_comment

begin_comment
comment|/*ARGSIGNORED*/
end_comment

begin_function
name|int
name|_uuconf_iboolean
parameter_list|(
name|qglobal
parameter_list|,
name|zval
parameter_list|,
name|pi
parameter_list|)
name|struct
name|sglobal
modifier|*
name|qglobal
decl_stmt|;
specifier|const
name|char
modifier|*
name|zval
decl_stmt|;
name|boolean
modifier|*
name|pi
decl_stmt|;
block|{
switch|switch
condition|(
operator|*
name|zval
condition|)
block|{
case|case
literal|'y'
case|:
case|case
literal|'Y'
case|:
case|case
literal|'t'
case|:
case|case
literal|'T'
case|:
operator|*
name|pi
operator|=
name|TRUE
expr_stmt|;
break|break;
case|case
literal|'n'
case|:
case|case
literal|'N'
case|:
case|case
literal|'f'
case|:
case|case
literal|'F'
case|:
operator|*
name|pi
operator|=
name|FALSE
expr_stmt|;
break|break;
default|default:
return|return
name|UUCONF_SYNTAX_ERROR
operator||
name|UUCONF_CMDTABRET_EXIT
return|;
block|}
return|return
name|UUCONF_CMDTABRET_CONTINUE
return|;
block|}
end_function

end_unit

