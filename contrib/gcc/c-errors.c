begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Various diagnostic subroutines for the GNU C language.    Copyright (C) 2000, 2001, 2003 Free Software Foundation, Inc.    Contributed by Gabriel Dos Reis<gdr@codesourcery.com>  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */
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
file|"coretypes.h"
end_include

begin_include
include|#
directive|include
file|"tm.h"
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

begin_function
name|void
name|pedwarn_c99
parameter_list|(
specifier|const
name|char
modifier|*
name|gmsgid
parameter_list|,
modifier|...
parameter_list|)
block|{
name|diagnostic_info
name|diagnostic
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|gmsgid
argument_list|)
expr_stmt|;
name|diagnostic_set_info
argument_list|(
operator|&
name|diagnostic
argument_list|,
name|gmsgid
argument_list|,
operator|&
name|ap
argument_list|,
name|input_location
argument_list|,
name|flag_isoc99
condition|?
name|pedantic_error_kind
argument_list|()
else|:
name|DK_WARNING
argument_list|)
expr_stmt|;
name|report_diagnostic
argument_list|(
operator|&
name|diagnostic
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* Issue an ISO C90 pedantic warning MSGID.  This function is supposed to    be used for matters that are allowed in ISO C99 but not supported in    ISO C90, thus we explicitly don't pedwarn when C99 is specified.    (There is no flag_c90.)  */
end_comment

begin_function
name|void
name|pedwarn_c90
parameter_list|(
specifier|const
name|char
modifier|*
name|gmsgid
parameter_list|,
modifier|...
parameter_list|)
block|{
name|diagnostic_info
name|diagnostic
decl_stmt|;
name|va_list
name|ap
decl_stmt|;
name|va_start
argument_list|(
name|ap
argument_list|,
name|gmsgid
argument_list|)
expr_stmt|;
name|diagnostic_set_info
argument_list|(
operator|&
name|diagnostic
argument_list|,
name|gmsgid
argument_list|,
operator|&
name|ap
argument_list|,
name|input_location
argument_list|,
name|flag_isoc99
condition|?
name|DK_WARNING
else|:
name|pedantic_error_kind
argument_list|()
argument_list|)
expr_stmt|;
name|report_diagnostic
argument_list|(
operator|&
name|diagnostic
argument_list|)
expr_stmt|;
name|va_end
argument_list|(
name|ap
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

