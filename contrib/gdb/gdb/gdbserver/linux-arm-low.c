begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* GNU/Linux/ARM specific low level interface, for the remote server for GDB.    Copyright 1995, 1996, 1998, 1999, 2000, 2001, 2002    Free Software Foundation, Inc.     This file is part of GDB.     This program is free software; you can redistribute it and/or modify    it under the terms of the GNU General Public License as published by    the Free Software Foundation; either version 2 of the License, or    (at your option) any later version.     This program is distributed in the hope that it will be useful,    but WITHOUT ANY WARRANTY; without even the implied warranty of    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    GNU General Public License for more details.     You should have received a copy of the GNU General Public License    along with this program; if not, write to the Free Software    Foundation, Inc., 59 Temple Place - Suite 330,    Boston, MA 02111-1307, USA.  */
end_comment

begin_include
include|#
directive|include
file|"server.h"
end_include

begin_include
include|#
directive|include
file|"linux-low.h"
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_REG_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/reg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
name|int
name|num_regs
init|=
literal|16
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|regmap
index|[]
init|=
block|{
literal|0
block|,
literal|4
block|,
literal|8
block|,
literal|12
block|,
literal|16
block|,
literal|20
block|,
literal|24
block|,
literal|28
block|,
literal|32
block|,
literal|36
block|,
literal|40
block|,
literal|44
block|,
literal|48
block|,
literal|52
block|,
literal|56
block|,
literal|60
block|, }
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|cannot_store_register
parameter_list|(
name|int
name|regno
parameter_list|)
block|{
return|return
operator|(
name|regno
operator|>=
name|num_regs
operator|)
return|;
block|}
end_function

begin_function
name|int
name|cannot_fetch_register
parameter_list|(
name|int
name|regno
parameter_list|)
block|{
return|return
operator|(
name|regno
operator|>=
name|num_regs
operator|)
return|;
block|}
end_function

end_unit

