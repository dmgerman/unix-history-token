begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* version.c -- binutils version information    Copyright 1991, 1996, 1997, 1998, 1999, 2000, 2001    Free Software Foundation, Inc.  This file is part of GNU Binutils.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"bfd.h"
end_include

begin_include
include|#
directive|include
file|"bucomm.h"
end_include

begin_comment
comment|/* This is the version numbers for the binutils.  They all change in    lockstep -- it's easier that way. */
end_comment

begin_decl_stmt
specifier|const
name|char
modifier|*
name|program_version
init|=
name|VERSION
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Print the version number and copyright information, and exit.  This    implements the --version option for the various programs.  */
end_comment

begin_function
name|void
name|print_version
parameter_list|(
name|name
parameter_list|)
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
block|{
comment|/* This output is intended to follow the GNU standards document.  */
comment|/* xgettext:c-format */
name|printf
argument_list|(
literal|"GNU %s %s\n"
argument_list|,
name|name
argument_list|,
name|program_version
argument_list|)
expr_stmt|;
name|printf
argument_list|(
name|_
argument_list|(
literal|"Copyright 1997, 98, 99, 2000, 2001 Free Software Foundation, Inc.\n"
argument_list|)
argument_list|)
expr_stmt|;
name|printf
argument_list|(
name|_
argument_list|(
literal|"\ This program is free software; you may redistribute it under the terms of\n\ the GNU General Public License.  This program has absolutely no warranty.\n"
argument_list|)
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

