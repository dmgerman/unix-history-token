begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Copyright (C) 1998, 1999, 2001 Free Software Foundation, Inc.    This file is derived from the one in the GNU C Library.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_comment
comment|/* Disable the definition of mkstemp to rpl_mkstemp (from config.h) in this    file.  Otherwise, we'd get conflicting prototypes for rpl_mkstemp on    most systems.  */
end_comment

begin_undef
undef|#
directive|undef
name|mkstemp
end_undef

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__GT_FILE
end_ifndef

begin_define
define|#
directive|define
name|__GT_FILE
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|__gen_tempname
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Generate a unique temporary file name from TEMPLATE.    The last six characters of TEMPLATE must be "XXXXXX";    they are replaced with a string that makes the filename unique.    Then open the file and return a fd. */
end_comment

begin_function
name|int
name|rpl_mkstemp
parameter_list|(
name|char
modifier|*
name|template
parameter_list|)
block|{
return|return
name|__gen_tempname
argument_list|(
name|template
argument_list|,
name|__GT_FILE
argument_list|)
return|;
block|}
end_function

end_unit

