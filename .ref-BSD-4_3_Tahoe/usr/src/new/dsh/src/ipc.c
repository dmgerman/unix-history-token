begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<stdio.h>
end_include

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

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netdb.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_define
define|#
directive|define
name|FIRSTPORT
value|1425
end_define

begin_define
define|#
directive|define
name|LASTPORT
value|64000
end_define

begin_comment
comment|/* some useful definitions */
end_comment

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|bool
value|char
end_define

begin_define
define|#
directive|define
name|HOSTNAMESIZE
value|32
end_define

begin_decl_stmt
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the magic global */
end_comment

begin_decl_stmt
name|char
name|ourhostname
index|[
name|HOSTNAMESIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* local host name */
end_comment

begin_decl_stmt
name|long
name|ourhostaddr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* our host's address */
end_comment

begin_decl_stmt
name|bool
name|havehost
init|=
name|FALSE
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* true if ourhost* is valid */
end_comment

begin_comment
comment|/* get info about local host */
end_comment

begin_macro
name|getmyhoststuff
argument_list|()
end_macro

begin_block
block|{
name|char
modifier|*
name|temp
decl_stmt|;
name|gethostname
argument_list|(
name|ourhostname
argument_list|,
name|HOSTNAMESIZE
argument_list|)
expr_stmt|;
name|netaddr
argument_list|(
name|ourhostname
argument_list|,
operator|&
name|ourhostaddr
argument_list|)
expr_stmt|;
name|havehost
operator|=
name|TRUE
expr_stmt|;
block|}
end_block

begin_comment
comment|/* return our host's name */
end_comment

begin_function
name|char
modifier|*
name|myhostname
parameter_list|()
block|{
if|if
condition|(
operator|!
name|havehost
condition|)
block|{
name|getmyhoststuff
argument_list|()
expr_stmt|;
block|}
return|return
name|ourhostname
return|;
block|}
end_function

begin_comment
comment|/* return our host's address */
end_comment

begin_macro
name|myhostaddr
argument_list|()
end_macro

begin_block
block|{
if|if
condition|(
operator|!
name|havehost
condition|)
block|{
name|getmyhoststuff
argument_list|()
expr_stmt|;
block|}
return|return
name|ourhostaddr
return|;
block|}
end_block

begin_comment
comment|/*  *	make a datagram socket  */
end_comment

begin_macro
name|makedgsocket
argument_list|(
argument|pptr
argument_list|)
end_macro

begin_decl_stmt
name|int
modifier|*
name|pptr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* port number */
end_comment

begin_block
block|{
name|int
name|sock
decl_stmt|,
name|i
decl_stmt|,
name|rv
decl_stmt|;
name|struct
name|sockaddr_in
name|sin
decl_stmt|;
comment|/* set up INET address */
name|sin
operator|.
name|sin_family
operator|=
name|AF_INET
expr_stmt|;
name|sin
operator|.
name|sin_addr
operator|.
name|s_addr
operator|=
name|myhostaddr
argument_list|()
expr_stmt|;
name|bzero
argument_list|(
name|sin
operator|.
name|sin_zero
argument_list|,
literal|8
argument_list|)
expr_stmt|;
comment|/* get a socket */
name|sock
operator|=
name|socket
argument_list|(
name|AF_INET
argument_list|,
name|SOCK_DGRAM
argument_list|,
literal|0
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|sock
operator|<
literal|0
condition|)
block|{
name|error
argument_list|(
literal|"opening datagram socket"
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
operator|*
name|pptr
operator|==
literal|0
condition|)
block|{
for|for
control|(
operator|*
name|pptr
operator|=
name|FIRSTPORT
init|;
operator|*
name|pptr
operator|<
name|LASTPORT
condition|;
operator|*
name|pptr
operator|+=
literal|11
control|)
block|{
name|sin
operator|.
name|sin_port
operator|=
name|htons
argument_list|(
operator|(
name|u_short
operator|)
operator|*
name|pptr
argument_list|)
expr_stmt|;
name|rv
operator|=
name|bind
argument_list|(
name|sock
argument_list|,
operator|&
name|sin
argument_list|,
sizeof|sizeof
argument_list|(
name|sin
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|rv
operator|==
literal|0
condition|)
block|{
break|break;
block|}
block|}
block|}
else|else
block|{
name|sin
operator|.
name|sin_port
operator|=
name|htons
argument_list|(
operator|(
name|u_short
operator|)
operator|*
name|pptr
argument_list|)
expr_stmt|;
name|rv
operator|=
name|bind
argument_list|(
name|sock
argument_list|,
operator|&
name|sin
argument_list|,
sizeof|sizeof
argument_list|(
name|sin
argument_list|)
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
if|if
condition|(
name|rv
operator|!=
literal|0
condition|)
block|{
name|close
argument_list|(
name|sock
argument_list|)
expr_stmt|;
name|error
argument_list|(
literal|"binding datagram socket"
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
name|sock
operator|)
return|;
block|}
end_block

begin_comment
comment|/* get the network address of a machine */
end_comment

begin_function
name|long
name|netaddr
parameter_list|(
name|name
parameter_list|,
name|addrptr
parameter_list|)
name|char
modifier|*
name|name
decl_stmt|;
name|char
modifier|*
name|addrptr
decl_stmt|;
block|{
name|long
name|iaddr
decl_stmt|;
name|struct
name|hostent
modifier|*
name|hp
decl_stmt|,
modifier|*
name|gethostbyname
argument_list|()
decl_stmt|;
name|hp
operator|=
name|gethostbyname
argument_list|(
name|name
argument_list|)
expr_stmt|;
name|bcopy
argument_list|(
name|hp
operator|->
name|h_addr
argument_list|,
name|addrptr
argument_list|,
name|hp
operator|->
name|h_length
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/* are these two names synonymns? */
end_comment

begin_macro
name|aresynonyms
argument_list|(
argument|name1
argument_list|,
argument|name2
argument_list|)
end_macro

begin_decl_stmt
name|char
modifier|*
name|name1
decl_stmt|,
modifier|*
name|name2
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|hostent
modifier|*
name|hp
decl_stmt|,
modifier|*
name|gethostbyname
argument_list|()
decl_stmt|;
name|char
modifier|*
modifier|*
name|ptr
decl_stmt|;
name|hp
operator|=
name|gethostbyname
argument_list|(
name|name1
argument_list|)
expr_stmt|;
if|if
condition|(
name|hp
operator|==
literal|0
condition|)
return|return
operator|(
name|FALSE
operator|)
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|name2
argument_list|,
name|hp
operator|->
name|h_name
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|TRUE
operator|)
return|;
for|for
control|(
name|ptr
operator|=
name|hp
operator|->
name|h_aliases
init|;
operator|*
name|ptr
operator|!=
literal|0
condition|;
name|ptr
operator|++
control|)
block|{
if|if
condition|(
name|strcmp
argument_list|(
name|name2
argument_list|,
operator|*
name|ptr
argument_list|)
operator|==
literal|0
condition|)
return|return
operator|(
name|TRUE
operator|)
return|;
block|}
return|return
operator|(
name|FALSE
operator|)
return|;
block|}
end_block

begin_comment
comment|/* receive a datagram via the inet */
end_comment

begin_macro
name|recvdg
argument_list|(
argument|fd
argument_list|,
argument|buf
argument_list|,
argument|len
argument_list|)
end_macro

begin_decl_stmt
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* socket to receive over */
end_comment

begin_decl_stmt
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer to receive into */
end_comment

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* size in bytes of that buffer */
end_comment

begin_block
block|{
name|struct
name|sockaddr
name|faddr
decl_stmt|;
name|int
name|flen
decl_stmt|;
name|int
name|rv
decl_stmt|,
name|i
decl_stmt|;
name|flen
operator|=
sizeof|sizeof
argument_list|(
name|faddr
argument_list|)
expr_stmt|;
name|rv
operator|=
name|recvfrom
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
name|len
argument_list|,
literal|0
argument_list|,
operator|&
name|faddr
argument_list|,
operator|&
name|flen
argument_list|)
expr_stmt|;
return|return
operator|(
name|rv
operator|)
return|;
block|}
end_block

begin_comment
comment|/* send an inet datagram */
end_comment

begin_macro
name|senddg
argument_list|(
argument|fd
argument_list|,
argument|buf
argument_list|,
argument|len
argument_list|,
argument|destname
argument_list|,
argument|destport
argument_list|)
end_macro

begin_decl_stmt
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* socket to send via */
end_comment

begin_decl_stmt
name|char
modifier|*
name|buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* buffer to send */
end_comment

begin_decl_stmt
name|int
name|len
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* number of bytes to send */
end_comment

begin_decl_stmt
name|char
modifier|*
name|destname
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of host we're sending to */
end_comment

begin_decl_stmt
name|int
name|destport
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* the udp port on that node */
end_comment

begin_block
block|{
name|struct
name|sockaddr_in
name|sin
decl_stmt|;
name|int
name|rv
decl_stmt|,
name|i
decl_stmt|;
name|char
modifier|*
name|ptr
decl_stmt|;
name|sin
operator|.
name|sin_family
operator|=
name|AF_INET
expr_stmt|;
name|bzero
argument_list|(
name|sin
operator|.
name|sin_zero
argument_list|,
literal|8
argument_list|)
expr_stmt|;
name|netaddr
argument_list|(
name|destname
argument_list|,
operator|&
operator|(
name|sin
operator|.
name|sin_addr
operator|)
argument_list|)
expr_stmt|;
name|sin
operator|.
name|sin_port
operator|=
name|htons
argument_list|(
operator|(
name|u_short
operator|)
name|destport
argument_list|)
expr_stmt|;
name|rv
operator|=
name|sendto
argument_list|(
name|fd
argument_list|,
name|buf
argument_list|,
name|len
argument_list|,
literal|0
argument_list|,
operator|&
name|sin
argument_list|,
sizeof|sizeof
argument_list|(
name|sin
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|rv
operator|)
return|;
block|}
end_block

end_unit

