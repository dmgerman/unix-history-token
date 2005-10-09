begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Copyright (C) 1996 N.M. Maclaren     Copyright (C) 1996 The University of Cambridge  This includes all of the 'Internet' headers and definitions used across modules, including those for handling timeouts.  No changes should be needed for any version of Unix with Internet (IP version 5) addressing, but would be for other addressing domains.  It needs<sys/socket.h> only because AF_INET is needed by gethostbyaddr and is defined there rather than in<netdb.h>, for some damn-fool reason. */
end_comment

begin_include
include|#
directive|include
file|<setjmp.h>
end_include

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_comment
comment|/* It is most unclear whether these should be here or in kludges.h, as they are kludges to keep 32-bit address dependencies out of the main body of internet.c, to allow for the much heralded arrival of IP version 6.  It will be interesting to see whether the universal availability of 64-bit integers arrives first. */
end_comment

begin_define
define|#
directive|define
name|local_to_address
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)->s_addr = htonl((unsigned long)y))
end_define

begin_define
define|#
directive|define
name|network_to_address
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|((x)->s_addr = (y))
end_define

begin_define
define|#
directive|define
name|NTP_PORT
value|htons((unsigned short)123)
end_define

begin_comment
comment|/* If not in /etc/services */
end_comment

begin_define
define|#
directive|define
name|port_to_integer
parameter_list|(
name|x
parameter_list|)
value|(ntohs((unsigned short)(x)))
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_SS_MAXSIZE
argument_list|)
operator|||
name|defined
argument_list|(
name|_SS_SIZE
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_IPV6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Defined in internet.c */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_IPV6
end_ifdef

begin_function_decl
specifier|extern
name|void
name|find_address
parameter_list|(
name|struct
name|sockaddr_storage
modifier|*
name|address
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|anywhere
parameter_list|,
name|struct
name|sockaddr_storage
modifier|*
name|everwhere
parameter_list|,
name|int
modifier|*
name|port
parameter_list|,
name|char
modifier|*
name|hostname
parameter_list|,
name|int
name|timespan
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_function_decl
specifier|extern
name|void
name|find_address
parameter_list|(
name|struct
name|in_addr
modifier|*
name|address
parameter_list|,
name|struct
name|in_addr
modifier|*
name|anywhere
parameter_list|,
name|struct
name|in_addr
modifier|*
name|everwhere
parameter_list|,
name|int
modifier|*
name|port
parameter_list|,
name|char
modifier|*
name|hostname
parameter_list|,
name|int
name|timespan
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

