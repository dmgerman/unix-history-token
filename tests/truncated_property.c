begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * libfdt - Flat Device Tree manipulation  *	Testcase for misbehaviour on a truncated property  * Copyright (C) 2006 David Gibson, IBM Corporation.  *  * This library is free software; you can redistribute it and/or  * modify it under the terms of the GNU Lesser General Public License  * as published by the Free Software Foundation; either version 2.1 of  * the License, or (at your option) any later version.  *  * This library is distributed in the hope that it will be useful, but  * WITHOUT ANY WARRANTY; without even the implied warranty of  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  * Lesser General Public License for more details.  *  * You should have received a copy of the GNU Lesser General Public  * License along with this library; if not, write to the Free Software  * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA  */
end_comment

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<libfdt.h>
end_include

begin_include
include|#
directive|include
file|"tests.h"
end_include

begin_include
include|#
directive|include
file|"testdata.h"
end_include

begin_function
name|int
name|main
parameter_list|(
name|int
name|argc
parameter_list|,
name|char
modifier|*
name|argv
index|[]
parameter_list|)
block|{
name|void
modifier|*
name|fdt
init|=
operator|&
name|_truncated_property
decl_stmt|;
specifier|const
name|void
modifier|*
name|prop
decl_stmt|;
name|int
name|len
decl_stmt|;
name|test_init
argument_list|(
name|argc
argument_list|,
name|argv
argument_list|)
expr_stmt|;
name|prop
operator|=
name|fdt_getprop
argument_list|(
name|fdt
argument_list|,
literal|0
argument_list|,
literal|"truncated"
argument_list|,
operator|&
name|len
argument_list|)
expr_stmt|;
if|if
condition|(
name|prop
condition|)
name|FAIL
argument_list|(
literal|"fdt_getprop() succeeded on truncated property"
argument_list|)
expr_stmt|;
if|if
condition|(
name|len
operator|!=
operator|-
name|FDT_ERR_BADSTRUCTURE
condition|)
name|FAIL
argument_list|(
literal|"fdt_getprop() failed with \"%s\" instead of \"%s\""
argument_list|,
name|fdt_strerror
argument_list|(
name|len
argument_list|)
argument_list|,
name|fdt_strerror
argument_list|(
operator|-
name|FDT_ERR_BADSTRUCTURE
argument_list|)
argument_list|)
expr_stmt|;
name|PASS
argument_list|()
expr_stmt|;
block|}
end_function

end_unit

