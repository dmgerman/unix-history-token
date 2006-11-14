begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Default host-specific hook definitions.    Copyright (C) 2003 Free Software Foundation, Inc.  This file is part of GCC.  GCC is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2, or (at your option) any later version.  GCC is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with GCC; see the file COPYING.  If not, write to the Free Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
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
file|"hosthooks.h"
end_include

begin_include
include|#
directive|include
file|"hosthooks-def.h"
end_include

begin_decl_stmt
specifier|const
name|struct
name|host_hooks
name|host_hooks
init|=
name|HOST_HOOKS_INITIALIZER
decl_stmt|;
end_decl_stmt

end_unit

