begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* getversion.c -- select backup filename type    Copyright (C) 1990 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* Written by David MacKenzie<djm@ai.mit.edu> */
end_comment

begin_include
include|#
directive|include
file|"backupfile.h"
end_include

begin_function_decl
name|int
name|argmatch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|invalid_arg
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|program_name
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|backup_args
index|[]
init|=
block|{
literal|"never"
block|,
literal|"simple"
block|,
literal|"nil"
block|,
literal|"existing"
block|,
literal|"t"
block|,
literal|"numbered"
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|enum
name|backup_type
name|backup_types
index|[]
init|=
block|{
name|simple
block|,
name|simple
block|,
name|numbered_existing
block|,
name|numbered_existing
block|,
name|numbered
block|,
name|numbered
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return the type of backup indicated by VERSION.    Unique abbreviations are accepted. */
end_comment

begin_function
name|enum
name|backup_type
name|get_version
parameter_list|(
name|version
parameter_list|)
name|char
modifier|*
name|version
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
if|if
condition|(
name|version
operator|==
literal|0
operator|||
operator|*
name|version
operator|==
literal|0
condition|)
return|return
name|numbered_existing
return|;
name|i
operator|=
name|argmatch
argument_list|(
name|version
argument_list|,
name|backup_args
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|>=
literal|0
condition|)
return|return
name|backup_types
index|[
name|i
index|]
return|;
name|invalid_arg
argument_list|(
literal|"version control type"
argument_list|,
name|version
argument_list|,
name|i
argument_list|)
expr_stmt|;
return|return
name|numbered_existing
return|;
block|}
end_function

end_unit

