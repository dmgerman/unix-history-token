begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1993 Martin Birgmeier  * All rights reserved.  *  * You may redistribute unmodified or modified versions of this source  * code provided that the above copyright notice and this and the  * following conditions are retained.  *  * This software is provided ``as is'', and comes with no warranties  * of any kind. I shall in no event be liable for anything that happens  * to anyone/anything when using this software.  */
end_comment

begin_include
include|#
directive|include
file|"rand48.h"
end_include

begin_function
name|long
name|jrand48
parameter_list|(
name|unsigned
name|short
name|xseed
index|[
literal|3
index|]
parameter_list|)
block|{
name|_dorand48
argument_list|(
name|xseed
argument_list|)
expr_stmt|;
return|return
operator|(
operator|(
name|long
operator|)
name|xseed
index|[
literal|2
index|]
operator|<<
literal|16
operator|)
operator|+
operator|(
name|long
operator|)
name|xseed
index|[
literal|1
index|]
return|;
block|}
end_function

end_unit

