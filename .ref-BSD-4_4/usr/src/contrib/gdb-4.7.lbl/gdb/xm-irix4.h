begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for irix4 hosting support.  Copyright (C) 1991, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* This is for the iris. */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIO
end_define

begin_include
include|#
directive|include
file|"xm-bigmips.h"
end_include

begin_comment
comment|/* Override register locations in upage for SGI machines */
end_comment

begin_undef
undef|#
directive|undef
name|REGISTER_U_ADDR
end_undef

begin_define
define|#
directive|define
name|REGISTER_U_ADDR
parameter_list|(
name|addr
parameter_list|,
name|blockend
parameter_list|,
name|regno
parameter_list|)
define|\
value|if (regno< PC_REGNUM)				\       addr = regno;					\   else							\       addr = regno + NSIG_HNDLRS;
end_define

begin_comment
comment|/* Skip over signal handlers */
end_comment

begin_comment
comment|/* BEGIN GW MODS */
end_comment

begin_comment
comment|/* Irix defines psignal() in signal.h, which gets gcc rather angry at us  * because their definition is markedly different.  */
end_comment

begin_define
define|#
directive|define
name|PSIGNAL_IN_SIGNAL_H
end_define

begin_define
define|#
directive|define
name|BROKEN_SIGINFO_H
end_define

begin_comment
comment|/*<sys/siginfo.h> si_pid& si_uid are bogus */
end_comment

end_unit

