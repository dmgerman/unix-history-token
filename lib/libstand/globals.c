begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	$NetBSD: globals.c,v 1.3 1995/09/18 21:19:27 pk Exp $	*/
end_comment

begin_comment
comment|/*  *	globals.c:  *  *	global variables should be separate, so nothing else  *	must be included extraneously.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|"stand.h"
end_include

begin_include
include|#
directive|include
file|"net.h"
end_include

begin_decl_stmt
name|u_char
name|bcea
index|[
literal|6
index|]
init|=
name|BA
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* broadcast ethernet address */
end_comment

begin_decl_stmt
name|char
name|rootpath
index|[
name|FNAME_SIZE
index|]
init|=
literal|"/"
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* root mount path */
end_comment

begin_decl_stmt
name|char
name|bootfile
index|[
name|FNAME_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* bootp says to boot this */
end_comment

begin_decl_stmt
name|char
name|hostname
index|[
name|FNAME_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* our hostname */
end_comment

begin_decl_stmt
name|int
name|hostnamelen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|domainname
index|[
name|FNAME_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* our DNS domain */
end_comment

begin_decl_stmt
name|int
name|domainnamelen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
name|ifname
index|[
name|IFNAME_SIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* name of interface (e.g. "le0") */
end_comment

begin_decl_stmt
name|struct
name|in_addr
name|myip
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* my ip address */
end_comment

begin_decl_stmt
name|struct
name|in_addr
name|nameip
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* DNS server ip address */
end_comment

begin_decl_stmt
name|struct
name|in_addr
name|rootip
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* root ip address */
end_comment

begin_decl_stmt
name|struct
name|in_addr
name|swapip
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* swap ip address */
end_comment

begin_decl_stmt
name|struct
name|in_addr
name|gateip
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* swap ip address */
end_comment

begin_decl_stmt
name|n_long
name|netmask
init|=
literal|0xffffff00
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* subnet or net mask */
end_comment

begin_decl_stmt
name|int
name|errno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* our old friend */
end_comment

end_unit

