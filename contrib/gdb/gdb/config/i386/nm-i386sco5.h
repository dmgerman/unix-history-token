begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native support for SCO OpenServer 5    Copyright 1996 Free Software Foundation, Inc.    By Robert Lipe<robertl@dgii.com>. Based on     work by Ian Lance Taylor<ian@cygnus.com. and     Martin Walker<maw@netcom.com>.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/* SCO OpenServer 5 is a superset of 3.2v4.  It is actually quite    close to SVR4 [ elf, dynamic libes, mmap ] but misses a few things    like /proc. */
end_comment

begin_include
include|#
directive|include
file|"i386/nm-i386sco.h"
end_include

begin_comment
comment|/* Since the native compilers [ and linkers ] are licensed from USL,    we'll try convincing GDB of this... */
end_comment

begin_include
include|#
directive|include
file|"solib.h"
end_include

begin_comment
comment|/* Pick up shared library support */
end_comment

begin_define
define|#
directive|define
name|SVR4_SHARED_LIBS
end_define

begin_define
define|#
directive|define
name|ATTACH_DETACH
end_define

begin_comment
comment|/* SCO, does not provide<sys/ptrace.h>.  infptrace.c does not     have defaults for these values.  */
end_comment

begin_define
define|#
directive|define
name|PTRACE_ATTACH
value|10
end_define

begin_define
define|#
directive|define
name|PTRACE_DETACH
value|11
end_define

end_unit

