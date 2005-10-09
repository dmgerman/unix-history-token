begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Parse a string, yielding a struct partime that describes it.  */
end_comment

begin_comment
comment|/* Copyright 1993, 1994, 1995 Paul Eggert    Distributed under license by the Free Software Foundation, Inc.  This file is part of RCS.  RCS is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  RCS is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with RCS; see the file COPYING. If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  Report problems and direct all questions to:      rcs-bugs@cs.purdue.edu  */
end_comment

begin_define
define|#
directive|define
name|TM_UNDEFINED
value|(-1)
end_define

begin_define
define|#
directive|define
name|TM_DEFINED
parameter_list|(
name|x
parameter_list|)
value|(0<= (x))
end_define

begin_define
define|#
directive|define
name|TM_UNDEFINED_ZONE
value|((long) -24 * 60 * 60)
end_define

begin_define
define|#
directive|define
name|TM_LOCAL_ZONE
value|(TM_UNDEFINED_ZONE - 1)
end_define

begin_struct
struct|struct
name|partime
block|{
comment|/* 	* This structure describes the parsed time. 	* Only the following tm_* values in it are used: 	*	sec, min, hour, mday, mon, year, wday, yday. 	* If TM_UNDEFINED(value), the parser never found the value. 	* The tm_year field is the actual year, not the year - 1900; 	* but see ymodulus below. 	*/
name|struct
name|tm
name|tm
decl_stmt|;
comment|/* 	* If !TM_UNDEFINED(ymodulus), 	* then tm.tm_year is actually modulo ymodulus. 	*/
name|int
name|ymodulus
decl_stmt|;
comment|/* 	* Week of year, ISO 8601 style. 	* If TM_UNDEFINED(yweek), the parser never found yweek. 	* Weeks start on Mondays. 	* Week 1 includes Jan 4. 	*/
name|int
name|yweek
decl_stmt|;
comment|/* Seconds east of UTC; or TM_LOCAL_ZONE or TM_UNDEFINED_ZONE.  */
name|long
name|zone
decl_stmt|;
block|}
struct|;
end_struct

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
operator|||
name|has_prototypes
end_if

begin_define
define|#
directive|define
name|__PARTIME_P
parameter_list|(
name|x
parameter_list|)
value|x
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__PARTIME_P
parameter_list|(
name|x
parameter_list|)
value|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|char
modifier|*
name|partime
name|__PARTIME_P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
expr|struct
name|partime
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|parzone
name|__PARTIME_P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|long
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

