begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Macro definitions for Intel 386 running under LynxOS.    Copyright 1993, 1995, 2002 Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_I386LYNX_H
end_ifndef

begin_define
define|#
directive|define
name|TM_I386LYNX_H
end_define

begin_include
include|#
directive|include
file|"config/tm-lynx.h"
end_include

begin_comment
comment|/* Most definitions from sysv could be used. */
end_comment

begin_include
include|#
directive|include
file|"i386/tm-i386.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_I386LYNX_H */
end_comment

end_unit

