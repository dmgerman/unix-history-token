begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: acconfig.h,v 1.9 2002/06/10 01:27:13 lukem Exp $ */
end_comment

begin_expr_stmt
unit|@
name|TOP
expr|@ @
name|BOTTOM
expr|@
end_expr_stmt

begin_comment
comment|/* Define if your compiler supports `long long' */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_LONG_LONG
end_undef

begin_comment
comment|/* Define if *printf() uses %qd to print `long long' (otherwise uses %lld) */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PRINTF_QD
end_undef

begin_comment
comment|/* Define if in_port_t exists */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_IN_PORT_T
end_undef

begin_comment
comment|/* Define if sa_family_t exists in<sys/socket.h> */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SA_FAMILY_T
end_undef

begin_comment
comment|/* Define if struct sockaddr.sa_len exists (implies sockaddr_in.sin_len, etc) */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SOCKADDR_SA_LEN
end_undef

begin_comment
comment|/* Define if socklen_t exists */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SOCKLEN_T
end_undef

begin_comment
comment|/* Define if AF_INET6 exists in<sys/socket.h> */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_AF_INET6
end_undef

begin_comment
comment|/* Define if `struct sockaddr_in6' exists in<netinet/in.h> */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_SOCKADDR_IN6
end_undef

begin_comment
comment|/* Define if `struct addrinfo' exists in<netdb.h> */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_ADDRINFO
end_undef

begin_comment
comment|/*  * Define if<netdb.h> contains AI_NUMERICHOST et al.  * Systems which only implement RFC2133 will need this.  */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_RFC2553_NETDB
end_undef

begin_comment
comment|/* Define if `struct direct' has a d_namlen element */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_D_NAMLEN
end_undef

begin_comment
comment|/* Define if h_errno exists in<netdb.h> */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_H_ERRNO_D
end_undef

begin_comment
comment|/* Define if fclose() is declared in<stdio.h> */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_FCLOSE_D
end_undef

begin_comment
comment|/* Define if getpass() is declared in<stdlib.h> or<unistd.h> */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_GETPASS_D
end_undef

begin_comment
comment|/* Define if optarg is declared in<stdlib.h> or<unistd.h> */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_OPTARG_D
end_undef

begin_comment
comment|/* Define if optind is declared in<stdlib.h> or<unistd.h> */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_OPTIND_D
end_undef

begin_comment
comment|/* Define if pclose() is declared in<stdio.h> */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_PCLOSE_D
end_undef

begin_comment
comment|/* Define if `long long' is supported and sizeof(off_t)>= 8 */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_QUAD_SUPPORT
end_undef

begin_comment
comment|/* Define if strptime() is declared in<time.h> */
end_comment

begin_undef
undef|#
directive|undef
name|HAVE_STRPTIME_D
end_undef

begin_comment
comment|/*  * Define this if compiling with SOCKS (the firewall traversal library).  * Also, you must define connect, getsockname, bind, accept, listen, and  * select to their R-versions.  */
end_comment

begin_undef
undef|#
directive|undef
name|SOCKS
end_undef

begin_undef
undef|#
directive|undef
name|SOCKS4
end_undef

begin_undef
undef|#
directive|undef
name|SOCKS5
end_undef

begin_undef
undef|#
directive|undef
name|connect
end_undef

begin_undef
undef|#
directive|undef
name|getsockname
end_undef

begin_undef
undef|#
directive|undef
name|bind
end_undef

begin_undef
undef|#
directive|undef
name|accept
end_undef

begin_undef
undef|#
directive|undef
name|listen
end_undef

begin_undef
undef|#
directive|undef
name|select
end_undef

begin_undef
undef|#
directive|undef
name|dup
end_undef

begin_undef
undef|#
directive|undef
name|dup2
end_undef

begin_undef
undef|#
directive|undef
name|fclose
end_undef

begin_undef
undef|#
directive|undef
name|gethostbyname
end_undef

begin_undef
undef|#
directive|undef
name|getpeername
end_undef

begin_undef
undef|#
directive|undef
name|read
end_undef

begin_undef
undef|#
directive|undef
name|recv
end_undef

begin_undef
undef|#
directive|undef
name|recvfrom
end_undef

begin_undef
undef|#
directive|undef
name|rresvport
end_undef

begin_undef
undef|#
directive|undef
name|send
end_undef

begin_undef
undef|#
directive|undef
name|sendto
end_undef

begin_undef
undef|#
directive|undef
name|shutdown
end_undef

begin_undef
undef|#
directive|undef
name|write
end_undef

end_unit

