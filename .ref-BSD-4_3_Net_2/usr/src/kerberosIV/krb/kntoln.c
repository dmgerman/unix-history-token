begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/krb/RCS/kntoln.c,v $  * $Author: kfall $  *  * Copyright 1985, 1986, 1987, 1988 by the Massachusetts Institute  * of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
modifier|*
name|rcsid_kntoln_c
init|=
literal|"$Header: /usr/src/kerberosIV/krb/RCS/kntoln.c,v 4.9 90/06/25 20:56:40 kfall Exp Locker: kfall $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* lint */
end_comment

begin_include
include|#
directive|include
file|<mit-copyright.h>
end_include

begin_include
include|#
directive|include
file|<des.h>
end_include

begin_include
include|#
directive|include
file|<krb.h>
end_include

begin_include
include|#
directive|include
file|<strings.h>
end_include

begin_comment
comment|/*  * krb_kntoln converts an auth name into a local name by looking up  * the auth name in the /etc/aname file.  The format of the aname  * file is:  *  * +-----+-----+-----+-----+------+----------+-------+-------+  * | anl | inl | rll | lnl | name | instance | realm | lname |  * +-----+-----+-----+-----+------+----------+-------+-------+  * | 1by | 1by | 1by | 1by | name | instance | realm | lname |  * +-----+-----+-----+-----+------+----------+-------+-------+  *  * If the /etc/aname file can not be opened it will set the  * local name to the auth name.  Thus, in this case it performs as  * the identity function.  *  * The name instance and realm are passed to krb_kntoln through  * the AUTH_DAT structure (ad).  *  * Now here's what it *really* does:  *  * Given a Kerberos name in an AUTH_DAT structure, check that the  * instance is null, and that the realm is the same as the local  * realm, and return the principal's name in "lname".  Return  * KSUCCESS if all goes well, otherwise KFAILURE.  */
end_comment

begin_macro
name|krb_kntoln
argument_list|(
argument|ad
argument_list|,
argument|lname
argument_list|)
end_macro

begin_decl_stmt
name|AUTH_DAT
modifier|*
name|ad
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|char
modifier|*
name|lname
decl_stmt|;
end_decl_stmt

begin_block
block|{
specifier|static
name|char
name|lrealm
index|[
name|REALM_SZ
index|]
init|=
literal|""
decl_stmt|;
if|if
condition|(
operator|!
operator|(
operator|*
name|lrealm
operator|)
operator|&&
operator|(
name|krb_get_lrealm
argument_list|(
name|lrealm
argument_list|,
literal|0
argument_list|)
operator|==
name|KFAILURE
operator|)
condition|)
return|return
operator|(
name|KFAILURE
operator|)
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|ad
operator|->
name|pinst
argument_list|,
literal|""
argument_list|)
condition|)
return|return
operator|(
name|KFAILURE
operator|)
return|;
if|if
condition|(
name|strcmp
argument_list|(
name|ad
operator|->
name|prealm
argument_list|,
name|lrealm
argument_list|)
condition|)
return|return
operator|(
name|KFAILURE
operator|)
return|;
operator|(
name|void
operator|)
name|strcpy
argument_list|(
name|lname
argument_list|,
name|ad
operator|->
name|pname
argument_list|)
expr_stmt|;
return|return
operator|(
name|KSUCCESS
operator|)
return|;
block|}
end_block

end_unit

