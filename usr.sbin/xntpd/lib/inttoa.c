begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* inttoa.c,v 3.1 1993/07/06 01:08:25 jbj Exp  * inttoa - return an asciized signed integer  */
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
name|inttoa
parameter_list|(
name|ival
parameter_list|)
name|LONG
name|ival
decl_stmt|;
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
literal|"%ld"
argument_list|,
name|ival
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
block|}
end_function

end_unit

