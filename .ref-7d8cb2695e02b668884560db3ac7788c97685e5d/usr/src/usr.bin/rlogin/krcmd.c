begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|sccsid
index|[]
init|=
literal|"@(#)krcmd.c	1.7 (Berkeley) %G%"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* not lint */
end_comment

begin_comment
comment|/*  *	$Source: /usr/src/usr.bin/rlogin/RCS/krcmd.c,v $  *	$Header: /mit/kerberos/ucb/mit/kcmd/RCS/krcmd.c,v 5.1  *		89/07/25 15:38:44 kfall Exp Locker: kfall $  * static char *rcsid_kcmd_c =  * "$Header: /mit/kerberos/ucb/mit/kcmd/RCS/krcmd.c,v 5.1 89/07/25 15:38:44  *	kfall Exp Locker: kfall $";  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERBEROS
end_ifdef

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CRYPT
end_ifdef

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<kerberosIV/des.h>
end_include

begin_include
include|#
directive|include
file|<kerberosIV/krb.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|SERVICE_NAME
value|"rcmd"
end_define

begin_decl_stmt
name|int
name|kcmd
name|__P
argument_list|(
operator|(
name|int
operator|*
operator|,
name|char
operator|*
operator|*
operator|,
name|u_short
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|int
operator|*
operator|,
name|KTEXT
operator|,
name|char
operator|*
operator|,
name|char
operator|*
operator|,
name|CREDENTIALS
operator|*
operator|,
name|Key_schedule
operator|,
name|MSG_DAT
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
expr|struct
name|sockaddr_in
operator|*
operator|,
name|long
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * krcmd: simplified version of Athena's "kcmd"  *	returns a socket attached to the destination, -1 or krb error on error   *	if fd2p is non-NULL, another socket is filled in for it  */
end_comment

begin_function
name|int
name|krcmd
parameter_list|(
name|ahost
parameter_list|,
name|rport
parameter_list|,
name|remuser
parameter_list|,
name|cmd
parameter_list|,
name|fd2p
parameter_list|,
name|realm
parameter_list|)
name|char
modifier|*
modifier|*
name|ahost
decl_stmt|;
name|u_short
name|rport
decl_stmt|;
name|char
modifier|*
name|remuser
decl_stmt|,
decl|*
name|cmd
decl_stmt|;
end_function

begin_decl_stmt
name|int
modifier|*
name|fd2p
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|realm
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|sock
init|=
operator|-
literal|1
decl_stmt|,
name|err
init|=
literal|0
decl_stmt|;
name|KTEXT_ST
name|ticket
decl_stmt|;
name|long
name|authopts
init|=
literal|0L
decl_stmt|;
name|err
operator|=
name|kcmd
argument_list|(
operator|&
name|sock
argument_list|,
name|ahost
argument_list|,
name|rport
argument_list|,
name|NULL
argument_list|,
comment|/* locuser not used */
name|remuser
argument_list|,
name|cmd
argument_list|,
name|fd2p
argument_list|,
operator|&
name|ticket
argument_list|,
name|SERVICE_NAME
argument_list|,
name|realm
argument_list|,
operator|(
name|CREDENTIALS
operator|*
operator|)
name|NULL
argument_list|,
comment|/* credentials not used */
operator|(
name|bit_64
operator|*
operator|)
name|NULL
argument_list|,
comment|/* key schedule not used */
operator|(
name|MSG_DAT
operator|*
operator|)
name|NULL
argument_list|,
comment|/* MSG_DAT not used */
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|)
name|NULL
argument_list|,
comment|/* local addr not used */
operator|(
expr|struct
name|sockaddr_in
operator|*
operator|)
name|NULL
argument_list|,
comment|/* foreign addr not used */
name|authopts
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|>
name|KSUCCESS
operator|&&
name|err
operator|<
name|MAX_KRB_ERRORS
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"krcmd: %s\n"
argument_list|,
name|krb_err_txt
index|[
name|err
index|]
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
if|if
condition|(
name|err
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
return|return
operator|(
name|sock
operator|)
return|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERBEROS */
end_comment

end_unit

