begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * /src/NTP/ntp-4/libparse/trim_info.c,v 4.2 1998/12/20 23:45:31 kardel RELEASE_19990228_A  *  * $Created: Sun Aug  2 20:20:34 1998 $  *  * Copyright (C) 1998 by Frank Kardel  */
end_comment

begin_include
include|#
directive|include
file|"ntp_types.h"
end_include

begin_include
include|#
directive|include
file|"trimble.h"
end_include

begin_function
name|cmd_info_t
modifier|*
name|trimble_convert
parameter_list|(
name|unsigned
name|int
name|cmd
parameter_list|,
name|cmd_info_t
modifier|*
name|tbl
parameter_list|)
block|{
name|int
name|i
decl_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|tbl
index|[
name|i
index|]
operator|.
name|cmd
operator|!=
literal|0xFF
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|tbl
index|[
name|i
index|]
operator|.
name|cmd
operator|==
name|cmd
condition|)
return|return
operator|&
name|tbl
index|[
name|i
index|]
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/*  * trim_info.c,v  * Revision 4.2  1998/12/20 23:45:31  kardel  * fix types and warnings  *  * Revision 4.1  1998/08/09 22:27:48  kardel  * Trimble TSIP support  *  */
end_comment

end_unit

