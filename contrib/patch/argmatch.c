begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* argmatch.c -- find a match for a string in an array    Copyright (C) 1990, 1997 Free Software Foundation, Inc.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; see the file COPYING.    If not, write to the Free Software Foundation,    59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_comment
comment|/* Written by David MacKenzie<djm@gnu.ai.mit.edu> */
end_comment

begin_if
if|#
directive|if
name|HAVE_CONFIG_H
end_if

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<argmatch.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|HAVE_STRING_H
end_if

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If ARG is an unambiguous match for an element of the    null-terminated array OPTLIST, return the index in OPTLIST    of the matched element, else -1 if it does not match any element    or -2 if it is ambiguous (is a prefix of more than one element).  */
end_comment

begin_function
name|int
name|argmatch
parameter_list|(
name|arg
parameter_list|,
name|optlist
parameter_list|)
specifier|const
name|char
modifier|*
name|arg
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
modifier|*
name|optlist
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
comment|/* Temporary index in OPTLIST.  */
name|size_t
name|arglen
decl_stmt|;
comment|/* Length of ARG.  */
name|int
name|matchind
init|=
operator|-
literal|1
decl_stmt|;
comment|/* Index of first nonexact match.  */
name|int
name|ambiguous
init|=
literal|0
decl_stmt|;
comment|/* If nonzero, multiple nonexact match(es).  */
name|arglen
operator|=
name|strlen
argument_list|(
name|arg
argument_list|)
expr_stmt|;
comment|/* Test all elements for either exact match or abbreviated matches.  */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|optlist
index|[
name|i
index|]
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
operator|!
name|strncmp
argument_list|(
name|optlist
index|[
name|i
index|]
argument_list|,
name|arg
argument_list|,
name|arglen
argument_list|)
condition|)
block|{
if|if
condition|(
name|strlen
argument_list|(
name|optlist
index|[
name|i
index|]
argument_list|)
operator|==
name|arglen
condition|)
comment|/* Exact match found.  */
return|return
name|i
return|;
elseif|else
if|if
condition|(
name|matchind
operator|==
operator|-
literal|1
condition|)
comment|/* First nonexact match found.  */
name|matchind
operator|=
name|i
expr_stmt|;
else|else
comment|/* Second nonexact match found.  */
name|ambiguous
operator|=
literal|1
expr_stmt|;
block|}
block|}
if|if
condition|(
name|ambiguous
condition|)
return|return
operator|-
literal|2
return|;
else|else
return|return
name|matchind
return|;
block|}
end_function

begin_comment
comment|/* Error reporting for argmatch.    KIND is a description of the type of entity that was being matched.    VALUE is the invalid value that was given.    PROBLEM is the return value from argmatch.  */
end_comment

begin_function
name|void
name|invalid_arg
parameter_list|(
name|kind
parameter_list|,
name|value
parameter_list|,
name|problem
parameter_list|)
specifier|const
name|char
modifier|*
name|kind
decl_stmt|;
specifier|const
name|char
modifier|*
name|value
decl_stmt|;
name|int
name|problem
decl_stmt|;
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"%s: "
argument_list|,
name|program_name
argument_list|)
expr_stmt|;
if|if
condition|(
name|problem
operator|==
operator|-
literal|1
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"invalid"
argument_list|)
expr_stmt|;
else|else
comment|/* Assume -2.  */
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"ambiguous"
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|" %s `%s'\n"
argument_list|,
name|kind
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

