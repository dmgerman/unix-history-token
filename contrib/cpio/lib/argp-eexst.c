begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Default definition for ARGP_ERR_EXIT_STATUS    Copyright (C) 1997 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Written by Miles Bader<miles@gnu.ai.mit.edu>.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

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
file|<sysexits.h>
end_include

begin_include
include|#
directive|include
file|"argp.h"
end_include

begin_comment
comment|/* The exit status that argp will use when exiting due to a parsing error.    If not defined or set by the user program, this defaults to EX_USAGE from<sysexits.h>.  */
end_comment

begin_decl_stmt
name|error_t
name|argp_err_exit_status
init|=
name|EX_USAGE
decl_stmt|;
end_decl_stmt

end_unit

