begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Native support for i386.    Copyright 1986, 1987, 1989, 1992, 1994, 1998, 2000    Free Software Foundation, Inc.    Changes for 80386 by Pace Willisson (pace@prep.ai.mit.edu), July 1988.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NM_I386SCO_H
end_ifndef

begin_define
define|#
directive|define
name|NM_I386SCO_H
end_define

begin_include
include|#
directive|include
file|"i386/nm-i386v.h"
end_include

begin_comment
comment|/* When calling functions on SCO, sometimes we get an error writing some    of the segment registers.  This would appear to be a kernel    bug/non-feature.  */
end_comment

begin_define
define|#
directive|define
name|CANNOT_STORE_REGISTER
parameter_list|(
name|regno
parameter_list|)
value|((regno) == 14 || (regno) == 15)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* nm-i386sco.h */
end_comment

end_unit

