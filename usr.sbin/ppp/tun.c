begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Id$  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/select.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_include
include|#
directive|include
file|<net/if_tun.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
end_include

begin_include
include|#
directive|include
file|"hdlc.h"
end_include

begin_include
include|#
directive|include
file|"defs.h"
end_include

begin_include
include|#
directive|include
file|"loadalias.h"
end_include

begin_include
include|#
directive|include
file|"command.h"
end_include

begin_include
include|#
directive|include
file|"vars.h"
end_include

begin_include
include|#
directive|include
file|"log.h"
end_include

begin_include
include|#
directive|include
file|"tun.h"
end_include

begin_function
name|void
name|tun_configure
parameter_list|(
name|int
name|mtu
parameter_list|,
name|int
name|speed
parameter_list|)
block|{
name|struct
name|tuninfo
name|info
decl_stmt|;
name|info
operator|.
name|type
operator|=
literal|23
expr_stmt|;
name|info
operator|.
name|mtu
operator|=
name|mtu
expr_stmt|;
if|if
condition|(
name|VarPrefMTU
operator|!=
literal|0
operator|&&
name|VarPrefMTU
operator|<
name|mtu
condition|)
name|info
operator|.
name|mtu
operator|=
name|VarPrefMTU
expr_stmt|;
name|info
operator|.
name|baudrate
operator|=
name|speed
expr_stmt|;
ifdef|#
directive|ifdef
name|__OpenBSD__
name|info
operator|.
name|flags
operator|=
name|IFF_UP
operator||
name|IFF_POINTOPOINT
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|ioctl
argument_list|(
name|tun_out
argument_list|,
name|TUNSIFINFO
argument_list|,
operator|&
name|info
argument_list|)
operator|<
literal|0
condition|)
name|LogPrintf
argument_list|(
name|LogERROR
argument_list|,
literal|"tun_configure: ioctl(TUNSIFINFO): %s\n"
argument_list|,
name|strerror
argument_list|(
name|errno
argument_list|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

