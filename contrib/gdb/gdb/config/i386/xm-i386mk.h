begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions to make GDB run on Mach 3 OSF 1/MK on an Intel 386    Copyright (C) 1992 Free Software Foundation, Inc.  This file is part of GDB.  This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.  This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.  You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  */
end_comment

begin_define
define|#
directive|define
name|HAVE_TERMIO
value|1
end_define

begin_define
define|#
directive|define
name|EMULATOR_BASE
value|0xa0000000
end_define

begin_define
define|#
directive|define
name|EMULATOR_END
value|0xa0040000
end_define

begin_include
include|#
directive|include
file|"i386/xm-i386m3.h"
end_include

end_unit

