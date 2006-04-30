begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * trygetea.c - test program for getether.c  *  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_if
if|#
directive|if
name|defined
argument_list|(
name|SUNOS
argument_list|)
operator|||
name|defined
argument_list|(
name|SVR4
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|_AIX32
end_ifdef

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_comment
comment|/* for struct timeval in net/if.h */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_comment
comment|/* for struct ifreq */
end_comment

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/inet.h>
end_include

begin_comment
comment|/* inet_ntoa */
end_comment

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_include
include|#
directive|include
file|"getether.h"
end_include

begin_decl_stmt
name|int
name|debug
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|progname
decl_stmt|;
end_decl_stmt

begin_function
name|void
name|main
parameter_list|(
name|argc
parameter_list|,
name|argv
parameter_list|)
name|int
name|argc
decl_stmt|;
name|char
modifier|*
modifier|*
name|argv
decl_stmt|;
block|{
name|u_char
name|ea
index|[
literal|16
index|]
decl_stmt|;
comment|/* Ethernet address */
name|int
name|i
decl_stmt|;
name|progname
operator|=
name|argv
index|[
literal|0
index|]
expr_stmt|;
comment|/* for report */
if|if
condition|(
name|argc
operator|<
literal|2
condition|)
block|{
name|printf
argument_list|(
literal|"need interface name\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|(
name|i
operator|=
name|getether
argument_list|(
name|argv
index|[
literal|1
index|]
argument_list|,
operator|(
name|char
operator|*
operator|)
name|ea
argument_list|)
operator|)
operator|<
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"Could not get Ethernet address (rc=%d)\n"
argument_list|,
name|i
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|1
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|"Ether-addr"
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
literal|6
condition|;
name|i
operator|++
control|)
name|printf
argument_list|(
literal|":%x"
argument_list|,
name|ea
index|[
name|i
index|]
operator|&
literal|0xFF
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
name|exit
argument_list|(
literal|0
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

