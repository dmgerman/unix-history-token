begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * numtoa - return asciized network numbers store in local array space  */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_NETINET_IN_H
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_comment
comment|/* ntohl */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"ntp_fp.h"
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
name|numtoa
parameter_list|(
name|u_int32
name|num
parameter_list|)
block|{
specifier|register
name|u_int32
name|netnum
decl_stmt|;
specifier|register
name|char
modifier|*
name|buf
decl_stmt|;
name|netnum
operator|=
name|ntohl
argument_list|(
name|num
argument_list|)
expr_stmt|;
name|LIB_GETBUF
argument_list|(
name|buf
argument_list|)
expr_stmt|;
name|snprintf
argument_list|(
name|buf
argument_list|,
name|LIB_BUFLENGTH
argument_list|,
literal|"%lu.%lu.%lu.%lu"
argument_list|,
operator|(
operator|(
name|u_long
operator|)
name|netnum
operator|>>
literal|24
operator|)
operator|&
literal|0xff
argument_list|,
operator|(
operator|(
name|u_long
operator|)
name|netnum
operator|>>
literal|16
operator|)
operator|&
literal|0xff
argument_list|,
operator|(
operator|(
name|u_long
operator|)
name|netnum
operator|>>
literal|8
operator|)
operator|&
literal|0xff
argument_list|,
operator|(
name|u_long
operator|)
name|netnum
operator|&
literal|0xff
argument_list|)
expr_stmt|;
return|return
name|buf
return|;
block|}
end_function

end_unit

