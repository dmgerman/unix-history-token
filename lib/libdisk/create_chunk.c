begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@login.dknet.dk> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $Id$  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<err.h>
end_include

begin_include
include|#
directive|include
file|"libdisk.h"
end_include

begin_function
name|int
name|Create_Chunk
parameter_list|(
name|struct
name|disk
modifier|*
name|d
parameter_list|,
name|u_long
name|offset
parameter_list|,
name|u_long
name|size
parameter_list|,
name|chunk_e
name|type
parameter_list|,
name|int
name|subtype
parameter_list|,
name|u_long
name|flags
parameter_list|)
block|{
return|return
name|Add_Chunk
argument_list|(
name|d
argument_list|,
name|offset
argument_list|,
name|size
argument_list|,
literal|"X"
argument_list|,
name|type
argument_list|,
name|subtype
argument_list|,
name|flags
argument_list|)
return|;
block|}
end_function

end_unit

