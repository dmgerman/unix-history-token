begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * utvtoa - return an asciized representation of an unsigned struct timeval  */
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

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VMS
argument_list|)
end_if

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"ntp_unixtime.h"
end_include

begin_function
name|char
modifier|*
name|utvtoa
parameter_list|(
specifier|const
name|struct
name|timeval
modifier|*
name|tv
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
literal|"%lu.%06lu"
argument_list|,
operator|(
name|u_long
operator|)
name|tv
operator|->
name|tv_sec
argument_list|,
operator|(
name|u_long
operator|)
name|tv
operator|->
name|tv_usec
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
block|}
end_function

end_unit

