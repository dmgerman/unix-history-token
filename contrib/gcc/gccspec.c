begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Specific flags and argument handling of the C front-end.    Copyright (C) 1999 Free Software Foundation, Inc.  This file is part of GNU CC.  GNU CC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GNU CC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GNU CC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_include
include|#
directive|include
file|"system.h"
end_include

begin_comment
comment|/* Filter argc and argv before processing by the gcc driver proper. */
end_comment

begin_decl_stmt
name|void
name|lang_specific_driver
argument_list|(
name|fn
argument_list|,
name|in_argc
argument_list|,
name|in_argv
argument_list|,
name|in_added_libraries
argument_list|)
name|void
argument_list|(
operator|*
name|fn
argument_list|)
argument_list|()
name|ATTRIBUTE_UNUSED
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|in_argc
name|ATTRIBUTE_UNUSED
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
modifier|*
modifier|*
name|in_argv
name|ATTRIBUTE_UNUSED
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
modifier|*
name|in_added_libraries
name|ATTRIBUTE_UNUSED
decl_stmt|;
end_decl_stmt

begin_block
block|{
return|return;
comment|/* Not used for C. */
block|}
end_block

begin_comment
comment|/* Called before linking.  Returns 0 on success and -1 on failure. */
end_comment

begin_function
name|int
name|lang_specific_pre_link
parameter_list|()
block|{
return|return
literal|0
return|;
comment|/* Not used for C. */
block|}
end_function

begin_comment
comment|/* Number of extra output files that lang_specific_pre_link may generate. */
end_comment

begin_decl_stmt
name|int
name|lang_specific_extra_outfiles
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Not used for C. */
end_comment

end_unit

