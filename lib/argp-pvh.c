begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Default definition for ARGP_PROGRAM_VERSION_HOOK.    Copyright (C) 1996, 1997, 1999, 2004 Free Software Foundation, Inc.    This file is part of the GNU C Library.    Written by Miles Bader<miles@gnu.ai.mit.edu>.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2, or (at your option)    any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License along    with this program; if not, write to the Free Software Foundation,    Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|"argp.h"
end_include

begin_comment
comment|/* If set by the user program to a non-zero value, then a default option    --version is added (unless the ARGP_NO_HELP flag is used), which calls    this function with a stream to print the version to and a pointer to the    current parsing state, and then exits (unless the ARGP_NO_EXIT flag is    used).  This variable takes precedent over ARGP_PROGRAM_VERSION.  */
end_comment

begin_function_decl
name|void
function_decl|(
modifier|*
name|argp_program_version_hook
function_decl|)
parameter_list|(
name|FILE
modifier|*
name|stream
parameter_list|,
name|struct
name|argp_state
modifier|*
name|state
parameter_list|)
init|=
name|NULL
function_decl|;
end_function_decl

end_unit

