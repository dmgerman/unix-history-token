begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * uinttoa - return an asciized unsigned integer  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"lib_strbuf.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_function
name|char
modifier|*
name|uinttoa
parameter_list|(
name|u_long
name|uval
parameter_list|)
block|{
specifier|register
name|char
modifier|*
name|buf
decl_stmt|;
name|LIB_GETBUF
argument_list|(
name|buf
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|sprintf
argument_list|(
name|buf
argument_list|,
literal|"%lu"
argument_list|,
operator|(
name|u_long
operator|)
name|uval
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
block|}
end_function

end_unit

