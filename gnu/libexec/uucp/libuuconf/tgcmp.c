begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tgcmp.c    A comparison function for grades for _uuconf_time_parse.     Copyright (C) 1992 Ian Lance Taylor     This file is part of the Taylor UUCP uuconf library.     This library is free software; you can redistribute it and/or    modify it under the terms of the GNU Library General Public License    as published by the Free Software Foundation; either version 2 of    the License, or (at your option) any later version.     This library is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    Library General Public License for more details.     You should have received a copy of the GNU Library General Public    License along with this library; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     The author of the program may be contacted at ian@airs.com or    c/o Cygnus Support, 48 Grove Street, Somerville, MA 02144.    */
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
name|_uuconf_tgcmp_rcsid
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
comment|/* A comparison function to pass to _uuconf_itime_parse.  This    compares grades.  We can't just pass uuconf_grade_cmp, since    _uuconf_itime_parse wants a function takes longs as arguments.  */
end_comment

begin_function
name|int
name|_uuconf_itime_grade_cmp
parameter_list|(
name|i1
parameter_list|,
name|i2
parameter_list|)
name|long
name|i1
decl_stmt|;
name|long
name|i2
decl_stmt|;
block|{
return|return
name|UUCONF_GRADE_CMP
argument_list|(
operator|(
name|int
operator|)
name|i1
argument_list|,
operator|(
name|int
operator|)
name|i2
argument_list|)
return|;
block|}
end_function

end_unit

