begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* clkdefs.h,v 3.1 1993/07/06 01:07:12 jbj Exp  * Defines for the "clk" timestamping STREAMS module  */
end_comment

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_comment
comment|/*  * First, we need to define the maximum size of the set of  * characters to timestamp. 32 is MORE than enough.  */
end_comment

begin_define
define|#
directive|define
name|CLK_MAXSTRSIZE
value|32
end_define

begin_comment
comment|/*  * ioctl(fd, CLK_SETSTR, (char*)c );  *  * will tell the driver that any char in the null-terminated  * string c should be timestamped. It is possible, though  * unlikely that this ioctl number could collide with an  * existing one on your system. If so, change the 'K'  * to some other letter. However, once you've compiled  * the kernel with this include file, you should NOT  * change this file.  */
end_comment

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_define
define|#
directive|define
name|CLK_SETSTR
value|_IOWN('K',01,CLK_MAXSTRSIZE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|CLK_SETSTR
value|_IOWN(K,01,CLK_MAXSTRSIZE)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

