begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Various diagnostic subroutines for the GNU C language.    Copyright (C) 2000, 2001 Free Software Foundation, Inc.    Contributed by Gabriel Dos Reis<gdr@codesourcery.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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

begin_include
include|#
directive|include
file|"tree.h"
end_include

begin_include
include|#
directive|include
file|"c-tree.h"
end_include

begin_include
include|#
directive|include
file|"tm_p.h"
end_include

begin_include
include|#
directive|include
file|"flags.h"
end_include

begin_include
include|#
directive|include
file|"diagnostic.h"
end_include

begin_comment
comment|/* Issue an ISO C99 pedantic warning MSGID.  */
end_comment

begin_decl_stmt
name|void
name|pedwarn_c99
name|VPARAMS
argument_list|(
operator|(
specifier|const
name|char
operator|*
name|msgid
operator|,
operator|...
operator|)
argument_list|)
block|{
name|diagnostic_context
name|dc
decl_stmt|;
name|VA_OPEN
argument_list|(
name|ap
argument_list|,
name|msgid
argument_list|)
expr_stmt|;
name|VA_FIXEDARG
argument_list|(
name|ap
argument_list|,
specifier|const
name|char
operator|*
argument_list|,
name|msgid
argument_list|)
expr_stmt|;
name|set_diagnostic_context
argument_list|(
operator|&
name|dc
argument_list|,
name|msgid
argument_list|,
operator|&
name|ap
argument_list|,
name|input_filename
argument_list|,
name|lineno
argument_list|,
operator|!
name|flag_isoc99
operator|||
operator|!
name|flag_pedantic_errors
argument_list|)
expr_stmt|;
name|report_diagnostic
argument_list|(
operator|&
name|dc
argument_list|)
expr_stmt|;
name|VA_CLOSE
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_decl_stmt

end_unit

