begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Martin Birgmeier  * All rights reserved.  *  * You may redistribute unmodified or modified versions of this source  * code provided that the above copyright notice and this and the  * following conditions are retained.  *  * This software is provided ``as is'', and comes with no warranties  * of any kind. I shall in no event be liable for anything that happens  * to anyone/anything when using this software.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|"rand48.h"
end_include

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|_rand48_seed
index|[
literal|3
index|]
decl_stmt|;
end_decl_stmt

begin_function
name|long
name|mrand48
parameter_list|(
name|void
parameter_list|)
block|{
name|_dorand48
argument_list|(
name|_rand48_seed
argument_list|)
expr_stmt|;
return|return
operator|(
call|(
name|int32_t
call|)
argument_list|(
operator|(
operator|(
name|uint32_t
operator|)
name|_rand48_seed
index|[
literal|2
index|]
operator|<<
literal|16
operator|)
operator||
operator|(
name|uint32_t
operator|)
name|_rand48_seed
index|[
literal|1
index|]
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

