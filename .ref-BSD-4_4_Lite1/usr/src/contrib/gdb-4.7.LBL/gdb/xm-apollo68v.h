begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro defintions for an Apollo.    Copyright (C) 1986, 1987, 1989 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_comment
comment|/*  * Changes for 80386 by Pace Willisson (pace@prep.ai.mit.edu)  * July 1988  */
end_comment

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|BIG_ENDIAN
end_define

begin_comment
comment|/* I'm running gdb 3.4 under 386/ix 2.0.2, which is a derivative of AT&T's Sys V/386 3.2.  On some machines, gdb crashes when it's starting up while calling the vendor's termio tgetent() routine.  It always works when run under itself (actually, under 3.2, it's not an infinitely recursive bug.) After some poking around, it appears that depending on the environment size, or whether you're running YP, or the phase of the moon or something, the stack is not always long-aligned when main() is called, and tgetent() takes strong offense at that.  On some machines this bug never appears, but on those where it does, it occurs quite reliably.  */
end_comment

begin_define
define|#
directive|define
name|ALIGN_STACK_ON_STARTUP
end_define

begin_comment
comment|/* define USG if you are using sys5 /usr/include's */
end_comment

begin_define
define|#
directive|define
name|USG
end_define

begin_define
define|#
directive|define
name|HAVE_TERMIO
end_define

begin_define
define|#
directive|define
name|FETCH_INFERIOR_REGISTERS
end_define

end_unit

