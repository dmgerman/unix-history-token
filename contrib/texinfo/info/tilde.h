begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* tilde.h: Externally available variables and function in libtilde.a. */
end_comment

begin_comment
comment|/* This file is part of GNU Info, a program for reading online documentation    stored in Info format.     This file has appeared in prior works by the Free Software Foundation;    thus it carries copyright dates from 1988 through 1993.     Copyright (C) 1988, 1989, 1990, 1991, 1992, 1993 Free Software    Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.     Written by Brian Fox (bfox@ai.mit.edu). */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TILDE_H
end_ifndef

begin_define
define|#
directive|define
name|TILDE_H
end_define

begin_include
include|#
directive|include
file|"info.h"
end_include

begin_comment
comment|/* If non-null, this contains the address of a function to call if the    standard meaning for expanding a tilde fails.  The function is called    with the text (sans tilde, as in "foo"), and returns a malloc()'ed string    which is the expansion, or a NULL pointer if there is no expansion. */
end_comment

begin_decl_stmt
specifier|extern
name|CFunction
modifier|*
name|tilde_expansion_failure_hook
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When non-null, this is a NULL terminated array of strings which    are duplicates for a tilde prefix.  Bash uses this to expand    `=~' and `:~'. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|tilde_additional_prefixes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* When non-null, this is a NULL terminated array of strings which match    the end of a username, instead of just "/".  Bash sets this to    `:' and `=~'. */
end_comment

begin_decl_stmt
specifier|extern
name|char
modifier|*
modifier|*
name|tilde_additional_suffixes
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Return a new string which is the result of tilde expanding STRING. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|tilde_expand
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* Do the work of tilde expansion on FILENAME.  FILENAME starts with a    tilde.  If there is no expansion, call tilde_expansion_failure_hook. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|tilde_expand_word
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not TILDE_H */
end_comment

end_unit

