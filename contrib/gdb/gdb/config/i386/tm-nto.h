begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* QNX Neutrino target header.      Copyright 2003 Free Software Foundation, Inc.     This code was donated by QNX Software Systems Ltd.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TM_NTO_H
end_ifndef

begin_define
define|#
directive|define
name|TM_NTO_H
value|1
end_define

begin_comment
comment|/* Pick up most of what we need from the generic i386 target include file.  */
end_comment

begin_include
include|#
directive|include
file|"i386/tm-i386.h"
end_include

begin_include
include|#
directive|include
file|"tm-nto.h"
end_include

begin_include
include|#
directive|include
file|"solib.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TM_NTO_H */
end_comment

end_unit

