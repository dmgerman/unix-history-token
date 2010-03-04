begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright 2008 Jon Loeliger, Freescale Semiconductor, Inc.  *  * This program is free software; you can redistribute it and/or  * modify it under the terms of the GNU General Public License as  * published by the Free Software Foundation; either version 2 of the  * License, or (at your option) any later version.  *  *  This program is distributed in the hope that it will be useful,  *  but WITHOUT ANY WARRANTY; without even the implied warranty of  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  *  General Public License for more details.  *  *  You should have received a copy of the GNU General Public License  *  along with this program; if not, write to the Free Software  *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  *                                                                   USA  */
end_comment

begin_include
include|#
directive|include
file|"dtc.h"
end_include

begin_function
name|char
modifier|*
name|xstrdup
parameter_list|(
specifier|const
name|char
modifier|*
name|s
parameter_list|)
block|{
name|int
name|len
init|=
name|strlen
argument_list|(
name|s
argument_list|)
operator|+
literal|1
decl_stmt|;
name|char
modifier|*
name|dup
init|=
name|xmalloc
argument_list|(
name|len
argument_list|)
decl_stmt|;
name|memcpy
argument_list|(
name|dup
argument_list|,
name|s
argument_list|,
name|len
argument_list|)
expr_stmt|;
return|return
name|dup
return|;
block|}
end_function

end_unit

