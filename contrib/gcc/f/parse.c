begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU Fortran    Copyright (C) 1995 Free Software Foundation, Inc.    Contributed by James Craig Burley.  This file is part of GNU Fortran.  GNU Fortran is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU Fortran is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU Fortran; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.	 */
end_comment

begin_include
include|#
directive|include
file|"proj.h"
end_include

begin_include
include|#
directive|include
file|"top.h"
end_include

begin_include
include|#
directive|include
file|"com.h"
end_include

begin_include
include|#
directive|include
file|"where.h"
end_include

begin_include
include|#
directive|include
file|"version.h"
end_include

begin_include
include|#
directive|include
file|"flags.h"
end_include

begin_define
define|#
directive|define
name|NAME_OF_STDIN
value|"<stdin>"
end_define

begin_decl_stmt
specifier|extern
name|FILE
modifier|*
name|finput
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|yyparse
parameter_list|()
block|{
name|ffewhereFile
name|wf
decl_stmt|;
if|if
condition|(
name|ffe_is_version
argument_list|()
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"GNU Fortran Front End version %s\n"
argument_list|,
name|ffe_version_string
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ffe_is_pedantic
argument_list|()
condition|)
name|ffe_set_is_pedantic
argument_list|(
name|pedantic
argument_list|)
expr_stmt|;
name|wf
operator|=
name|ffewhere_file_new
argument_list|(
name|main_input_filename
argument_list|,
name|strlen
argument_list|(
name|main_input_filename
argument_list|)
argument_list|)
expr_stmt|;
name|ffecom_file
argument_list|(
name|main_input_filename
argument_list|)
expr_stmt|;
name|ffe_file
argument_list|(
name|wf
argument_list|,
name|finput
argument_list|)
expr_stmt|;
name|ffecom_finish_compile
argument_list|()
expr_stmt|;
return|return
literal|0
return|;
block|}
end_function

end_unit

