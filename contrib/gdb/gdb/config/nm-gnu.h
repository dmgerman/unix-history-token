begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Common declarations for the GNU Hurd     Copyright 1995, 1996, 1998, 1999 Free Software Foundation, Inc.     Written by Miles Bader<miles@gnu.ai.mit.edu>     The GNU Hurd is free software; you can redistribute it and/or    modify it under the terms of the GNU General Public License as    published by the Free Software Foundation; either version 2, or (at    your option) any later version.     The GNU Hurd is distributed in the hope that it will be useful, but    WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU    General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__NM_GNU_H__
end_ifndef

begin_define
define|#
directive|define
name|__NM_GNU_H__
end_define

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<mach.h>
end_include

begin_include
include|#
directive|include
file|<mach/exception.h>
end_include

begin_include
include|#
directive|include
file|"regcache.h"
end_include

begin_function_decl
specifier|extern
name|char
modifier|*
name|gnu_target_pid_to_str
parameter_list|(
name|int
name|pid
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Before storing, we need to read all the registers.  */
end_comment

begin_define
define|#
directive|define
name|CHILD_PREPARE_TO_STORE
parameter_list|()
value|deprecated_read_register_bytes (0, NULL, DEPRECATED_REGISTER_BYTES)
end_define

begin_comment
comment|/* Don't do wait_for_inferior on attach.  */
end_comment

begin_define
define|#
directive|define
name|ATTACH_NO_WAIT
end_define

begin_comment
comment|/* Use SVR4 style shared library support */
end_comment

begin_define
define|#
directive|define
name|SVR4_SHARED_LIBS
end_define

begin_include
include|#
directive|include
file|"solib.h"
end_include

begin_define
define|#
directive|define
name|NO_CORE_OPS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __NM_GNU_H__ */
end_comment

end_unit

