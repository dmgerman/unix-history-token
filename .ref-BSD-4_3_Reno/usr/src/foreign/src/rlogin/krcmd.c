begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted provided  * that: (1) source distributions retain this entire copyright notice and  * comment, and (2) distributions including binaries display the following  * acknowledgement:  ``This product includes software developed by the  * University of California, Berkeley and its contributors'' in the  * documentation or other materials provided with the distribution and in  * all advertising materials mentioning features or use of this software.  * Neither the name of the University nor the names of its contributors may  * be used to endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
literal|"@(#)krcmd.c	1.6.1.1 (Berkeley) 10/21/90"
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
comment|/*  *	$Source: /mit/kerberos/ucb/mit/kcmd/RCS/krcmd.c,v $  *	$Header: /mit/kerberos/ucb/mit/kcmd/RCS/krcmd.c,v 5.1  *		89/07/25 15:38:44 kfall Exp Locker: kfall $  * static char *rcsid_kcmd_c =  * "$Header: /mit/kerberos/ucb/mit/kcmd/RCS/krcmd.c,v 5.1 89/07/25 15:38:44  *	kfall Exp Locker: kfall $";  */
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

begin_include
include|#
directive|include
file|<stdio.h>
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

begin_define
define|#
directive|define
name|SERVICE_NAME
value|"rcmd"
end_define

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

