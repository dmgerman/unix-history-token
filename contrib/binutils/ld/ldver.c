begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ldver.c -- Print linker version.    Copyright 1991, 1992, 1993, 1994, 1995, 1996, 1997, 2000    Free Software Foundation, Inc.  This file is part of GLD, the Gnu Linker.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|"sysdep.h"
end_include

begin_include
include|#
directive|include
file|"ld.h"
end_include

begin_include
include|#
directive|include
file|"ldver.h"
end_include

begin_include
include|#
directive|include
file|"ldexp.h"
end_include

begin_include
include|#
directive|include
file|"ldlang.h"
end_include

begin_include
include|#
directive|include
file|"ldfile.h"
end_include

begin_include
include|#
directive|include
file|"ldemul.h"
end_include

begin_include
include|#
directive|include
file|"ldmain.h"
end_include

begin_decl_stmt
specifier|const
name|char
modifier|*
name|ld_program_version
init|=
name|VERSION
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|ldversion
parameter_list|(
name|noisy
parameter_list|)
name|int
name|noisy
decl_stmt|;
block|{
name|fprintf
argument_list|(
name|stdout
argument_list|,
name|_
argument_list|(
literal|"GNU ld version %s (with BFD %s)\n"
argument_list|)
argument_list|,
name|ld_program_version
argument_list|,
name|BFD_VERSION
argument_list|)
expr_stmt|;
if|if
condition|(
name|noisy
condition|)
block|{
name|ld_emulation_xfer_type
modifier|*
modifier|*
name|ptr
init|=
name|ld_emulations
decl_stmt|;
name|printf
argument_list|(
name|_
argument_list|(
literal|"  Supported emulations:\n"
argument_list|)
argument_list|)
expr_stmt|;
while|while
condition|(
operator|*
name|ptr
condition|)
block|{
name|printf
argument_list|(
literal|"   %s\n"
argument_list|,
operator|(
operator|*
name|ptr
operator|)
operator|->
name|emulation_name
argument_list|)
expr_stmt|;
name|ptr
operator|++
expr_stmt|;
block|}
block|}
block|}
end_function

end_unit

