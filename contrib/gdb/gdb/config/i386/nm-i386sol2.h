begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native support for i386 running Solaris 2.    Copyright 1998 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"nm-sysv4.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_THREAD_DB_LIB
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_struct_decl
struct_decl|struct
name|objfile
struct_decl|;
end_struct_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|target_new_objfile
parameter_list|(
name|OBJFILE
parameter_list|)
value|sol_thread_new_objfile (OBJFILE)
end_define

begin_decl_stmt
name|void
name|sol_thread_new_objfile
name|PARAMS
argument_list|(
operator|(
expr|struct
name|objfile
operator|*
name|objfile
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|FIND_NEW_THREADS
value|sol_find_new_threads
end_define

begin_decl_stmt
name|void
name|sol_find_new_threads
name|PARAMS
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

