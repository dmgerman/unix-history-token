begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Host-dependent definitions for Intel 386 running BSD Unix, for GDB.    Copyright 1986, 1987, 1989, 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
end_comment

begin_define
define|#
directive|define
name|HOST_BYTE_ORDER
value|LITTLE_ENDIAN
end_define

begin_include
include|#
directive|include
file|<machine/limits.h>
end_include

begin_comment
comment|/* for INT_MIN, to avoid "INT_MIN 					   redefined" warnings from defs.h */
end_comment

begin_comment
comment|/* psignal() is in<signal.h>.  */
end_comment

begin_define
define|#
directive|define
name|PSIGNAL_IN_SIGNAL_H
end_define

begin_define
define|#
directive|define
name|HAVE_TERMIOS
end_define

end_unit

