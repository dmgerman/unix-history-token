begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Defines for the "clk" timestamping STREAMS module  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * First, we need to define the maximum size of the set of  * characters to timestamp. 32 is MORE than enough.  */
end_comment

begin_define
define|#
directive|define
name|CLK_MAXSTRSIZE
value|32
end_define

begin_struct
struct|struct
name|clk_tstamp_charset
block|{
comment|/* XXX to use _IOW not _IOWN */
name|char
name|val
index|[
name|CLK_MAXSTRSIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ioctl(fd, CLK_SETSTR, (char*)c );  *  * will tell the driver that any char in the null-terminated  * string c should be timestamped. It is possible, though  * unlikely that this ioctl number could collide with an  * existing one on your system. If so, change the 'K'  * to some other letter. However, once you've compiled  * the kernel with this include file, you should NOT  * change this file.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__STDC__
argument_list|)
end_if

begin_comment
comment|/* XXX avoid __STDC__=0 on SOLARIS */
end_comment

begin_define
define|#
directive|define
name|CLK_SETSTR
value|_IOW('K', 01, struct clk_tstamp_charset)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CLK_SETSTR
value|_IOW(K, 01, struct clk_tstamp_charset)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

