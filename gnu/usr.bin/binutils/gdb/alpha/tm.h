begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/* Definitions to make GDB run on an Alpha box under FreeBSD.  The    definitions here are used when the _target_ system is running Linux.    Copyright 1996 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_FREEBSDALPHA_H
end_ifndef

begin_define
define|#
directive|define
name|TM_FREEBSDALPHA_H
end_define

begin_include
include|#
directive|include
file|"alpha/tm-alpha.h"
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|S0_REGNUM
end_ifndef

begin_define
define|#
directive|define
name|S0_REGNUM
value|(T7_REGNUM+1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Number of traps that happen between exec'ing the shell to run an    inferior, and when we finally get to the inferior code.  This is 2    on FreeBSD and most implementations.  */
end_comment

begin_undef
undef|#
directive|undef
name|START_INFERIOR_TRAPS_EXPECTED
end_undef

begin_define
define|#
directive|define
name|START_INFERIOR_TRAPS_EXPECTED
value|2
end_define

begin_struct_decl
struct_decl|struct
name|objfile
struct_decl|;
end_struct_decl

begin_decl_stmt
name|void
name|freebsd_uthread_new_objfile
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
name|target_new_objfile
parameter_list|(
name|OBJFILE
parameter_list|)
value|freebsd_uthread_new_objfile (OBJFILE)
end_define

begin_decl_stmt
specifier|extern
name|char
modifier|*
name|freebsd_uthread_pid_to_str
name|PARAMS
argument_list|(
operator|(
name|int
name|pid
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|target_pid_to_str
parameter_list|(
name|PID
parameter_list|)
value|freebsd_uthread_pid_to_str (PID)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_FREEBSDALPHA_H */
end_comment

end_unit

