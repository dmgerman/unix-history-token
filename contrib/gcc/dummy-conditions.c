begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Support for calculating constant conditions.    Copyright (C) 2002 Free Software Foundation, Inc.     This file is part of GNU CC.     GNU CC is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     GNU CC is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with GNU CC; see the file COPYING.  If not, write to    the Free Software Foundation, 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"hconfig.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_include
include|#
directive|include
file|"gensupport.h"
end_include

begin_comment
comment|/* MD generators that are run before insn-conditions.c exists should    link against this file instead.  Currently that is genconditions    and genconstants.  */
end_comment

begin_comment
comment|/* Empty conditions table to prevent link errors.  */
end_comment

begin_decl_stmt
specifier|const
name|struct
name|c_test
name|insn_conditions
index|[
literal|1
index|]
init|=
block|{
block|{
literal|0
block|,
literal|0
block|}
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|const
name|size_t
name|n_insn_conditions
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Disable insn elision, since it is currently impossible.  */
end_comment

begin_decl_stmt
specifier|const
name|int
name|insn_elision_unavailable
init|=
literal|1
decl_stmt|;
end_decl_stmt

end_unit

