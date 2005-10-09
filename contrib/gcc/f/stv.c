begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* stv.c -- Implementation File (module.c template V1.0)    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Related Modules:       None (despite the name, it doesn't really depend on ffest*)     Description:       Various and sundry info.     Modifications: */
end_comment

begin_comment
comment|/* Include files. */
end_comment

begin_include
include|#
directive|include
file|"proj.h"
end_include

begin_include
include|#
directive|include
file|"stv.h"
end_include

begin_include
include|#
directive|include
file|"lab.h"
end_include

begin_include
include|#
directive|include
file|"where.h"
end_include

begin_comment
comment|/* Externals defined here. */
end_comment

begin_decl_stmt
name|ffestvSavestate
name|ffestv_save_state_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ffewhereLine
name|ffestv_save_line_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ffewhereColumn
name|ffestv_save_col_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ffestvAccessstate
name|ffestv_access_state_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ffewhereLine
name|ffestv_access_line_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ffewhereColumn
name|ffestv_access_col_
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|ffelabNumber
name|ffestv_num_label_defines_
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Simple definitions and enumerations. */
end_comment

begin_comment
comment|/* Internal typedefs. */
end_comment

begin_comment
comment|/* Private include files. */
end_comment

begin_comment
comment|/* Internal structure definitions. */
end_comment

begin_comment
comment|/* Static objects accessed by functions in this module. */
end_comment

begin_comment
comment|/* Static functions (internal). */
end_comment

begin_comment
comment|/* Internal macros. */
end_comment

end_unit

