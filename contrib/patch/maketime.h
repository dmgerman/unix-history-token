begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Yield time_t from struct partime yielded by partime.  */
end_comment

begin_comment
comment|/* Copyright 1993, 1994, 1995 Paul Eggert    Distributed under license by the Free Software Foundation, Inc.     This file is part of RCS.     RCS is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     RCS is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with RCS; see the file COPYING.    If not, write to the Free Software Foundation,    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Report problems and direct all questions to:     rcs-bugs@cs.purdue.edu   */
end_comment

begin_if
if|#
directive|if
name|defined
name|__STDC__
operator|||
name|has_prototypes
end_if

begin_define
define|#
directive|define
name|__MAKETIME_P
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
name|__MAKETIME_P
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
name|struct
name|tm
modifier|*
name|time2tm
name|__MAKETIME_P
argument_list|(
operator|(
name|time_t
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|difftm
name|__MAKETIME_P
argument_list|(
operator|(
expr|struct
name|tm
specifier|const
operator|*
operator|,
expr|struct
name|tm
specifier|const
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|str2time
name|__MAKETIME_P
argument_list|(
operator|(
name|char
specifier|const
operator|*
operator|,
name|time_t
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|time_t
name|tm2time
name|__MAKETIME_P
argument_list|(
operator|(
expr|struct
name|tm
operator|*
operator|,
name|int
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|adjzone
name|__MAKETIME_P
argument_list|(
operator|(
expr|struct
name|tm
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

end_unit

