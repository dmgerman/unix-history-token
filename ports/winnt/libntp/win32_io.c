begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* This file implements i/o calls that are specific to Windows */
end_comment

begin_include
include|#
directive|include
file|<config.h>
end_include

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
file|"ntp_net.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"ntp_syslog.h"
end_include

begin_include
include|#
directive|include
file|"win32_io.h"
end_include

begin_include
include|#
directive|include
file|<isc/win32os.h>
end_include

begin_comment
comment|/*  * Define this macro to control the behavior of connection  * resets on UDP sockets.  See Microsoft KnowledgeBase Article Q263823  * for details.  * Based on that article, it is surprising that a much newer winsock2.h  * does not define SIO_UDP_CONNRESET (the one that comes with VS 2008).  * NOTE: This requires that Windows 2000 systems install Service Pack 2  * or later.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SIO_UDP_CONNRESET
end_ifndef

begin_define
define|#
directive|define
name|SIO_UDP_CONNRESET
value|_WSAIOW(IOC_VENDOR,12)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function
name|void
name|InitSockets
parameter_list|(
name|void
parameter_list|)
block|{
name|WORD
name|wVersionRequested
decl_stmt|;
name|WSADATA
name|wsaData
decl_stmt|;
name|int
name|err
decl_stmt|;
comment|/* Need Winsock 2.0 or better */
name|wVersionRequested
operator|=
name|MAKEWORD
argument_list|(
literal|2
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|err
operator|=
name|WSAStartup
argument_list|(
name|wVersionRequested
argument_list|,
operator|&
name|wsaData
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
block|{
name|SetLastError
argument_list|(
name|err
argument_list|)
expr_stmt|;
name|mfprintf
argument_list|(
name|stderr
argument_list|,
literal|"No usable winsock: %m\n"
argument_list|)
expr_stmt|;
name|SetLastError
argument_list|(
name|err
argument_list|)
expr_stmt|;
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"No usable winsock: %m"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_comment
comment|/*  * Windows 2000 systems incorrectly cause UDP sockets using WASRecvFrom  * to not work correctly, returning a WSACONNRESET error when a WSASendTo  * fails with an "ICMP port unreachable" response and preventing the  * socket from using the WSARecvFrom in subsequent operations.  * The function below fixes this, but requires that Windows 2000  * Service Pack 2 or later be installed on the system.  NT 4.0  * systems are not affected by this and work correctly.  * See Microsoft Knowledge Base Article Q263823 for details of this.  */
end_comment

begin_function
name|void
name|connection_reset_fix
parameter_list|(
name|SOCKET
name|fd
parameter_list|,
name|sockaddr_u
modifier|*
name|addr
parameter_list|)
block|{
name|DWORD
name|dw
decl_stmt|;
name|BOOL
name|bNewBehavior
init|=
name|FALSE
decl_stmt|;
name|DWORD
name|status
decl_stmt|;
comment|/* 	 * disable bad behavior using IOCTL: SIO_UDP_CONNRESET 	 * NT 4.0 has no problem 	 */
if|if
condition|(
name|isc_win32os_majorversion
argument_list|()
operator|>=
literal|5
condition|)
block|{
name|status
operator|=
name|WSAIoctl
argument_list|(
name|fd
argument_list|,
name|SIO_UDP_CONNRESET
argument_list|,
operator|&
name|bNewBehavior
argument_list|,
sizeof|sizeof
argument_list|(
name|bNewBehavior
argument_list|)
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
operator|&
name|dw
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
if|if
condition|(
name|SOCKET_ERROR
operator|==
name|status
condition|)
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"connection_reset_fix() failed for address %s: %m"
argument_list|,
name|stoa
argument_list|(
name|addr
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

