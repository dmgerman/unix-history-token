begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
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
literal|"@(#)krcmd.c	8.1 (Berkeley) 6/6/93"
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
comment|/*  *	$Source: /pub/FreeBSD/FreeBSD-CVS/src/usr.bin/rlogin/krcmd.c,v $  *	$Header: /mit/kerberos/ucb/mit/kcmd/RCS/krcmd.c,v 5.1  *		89/07/25 15:38:44 kfall Exp Locker: kfall $  * static char *rcsid_kcmd_c =  * "$Header: /mit/kerberos/ucb/mit/kcmd/RCS/krcmd.c,v 5.1 89/07/25 15:38:44  *	kfall Exp Locker: kfall $";  */
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
comment|/*  * krcmd: simplified version of Athena's "kcmd"  *	returns a socket attached to the destination, -1 or krb error on error  *	if fd2p is non-NULL, another socket is filled in for it  */
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
literal|0
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

begin_ifdef
ifdef|#
directive|ifdef
name|CRYPT
end_ifdef

begin_function
name|int
name|krcmd_mutual
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
parameter_list|,
name|cred
parameter_list|,
name|sched
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

begin_decl_stmt
name|CREDENTIALS
modifier|*
name|cred
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|Key_schedule
name|sched
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|sock
decl_stmt|,
name|err
decl_stmt|;
name|KTEXT_ST
name|ticket
decl_stmt|;
name|MSG_DAT
name|msg_dat
decl_stmt|;
name|struct
name|sockaddr_in
name|laddr
decl_stmt|,
name|faddr
decl_stmt|;
name|long
name|authopts
init|=
name|KOPT_DO_MUTUAL
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
name|cred
argument_list|,
comment|/* filled in */
name|sched
argument_list|,
comment|/* filled in */
operator|&
name|msg_dat
argument_list|,
comment|/* filled in */
operator|&
name|laddr
argument_list|,
comment|/* filled in */
operator|&
name|faddr
argument_list|,
comment|/* filled in */
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
literal|"krcmd_mutual: %s\n"
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
comment|/* CRYPT */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERBEROS */
end_comment

end_unit

