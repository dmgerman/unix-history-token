begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $Source: /usr/src/kerberosIV/krb/RCS/util.c,v $  * $Author: bostic $  *  * Copyright 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  *  * Miscellaneous debug printing utilities  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|lint
end_ifndef

begin_decl_stmt
specifier|static
name|char
name|rcsid_util_c
index|[]
init|=
literal|"$Header: /usr/src/kerberosIV/krb/RCS/util.c,v 4.10 91/02/25 15:31:14 bostic Exp $"
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
endif|lint
end_endif

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
file|<arpa/inet.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_comment
comment|/*  * Print some of the contents of the given authenticator structure  * (AUTH_DAT defined in "krb.h").  Fields printed are:  *  * pname, pinst, prealm, netaddr, flags, cksum, timestamp, session  */
end_comment

begin_macro
name|ad_print
argument_list|(
argument|x
argument_list|)
end_macro

begin_decl_stmt
name|AUTH_DAT
modifier|*
name|x
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|struct
name|in_addr
name|add
decl_stmt|;
comment|/* 	 * Print the contents of an auth_dat struct.  We can't cast a char 	 * array (x->address) to a struct in_addr, so we must turn off 	 * lint checking here. 	 * 	 * The above was the original comment -- I don't really understand 	 * the problem, but gcc won't compile it the way it was.  Hope this 	 * works -- TK. 	 */
name|add
operator|.
name|s_addr
operator|=
name|x
operator|->
name|address
expr_stmt|;
name|printf
argument_list|(
literal|"\n%s %s %s %s flags %u cksum 0x%X\n\ttkt_tm 0x%X sess_key"
argument_list|,
name|x
operator|->
name|pname
argument_list|,
name|x
operator|->
name|pinst
argument_list|,
name|x
operator|->
name|prealm
argument_list|,
name|inet_ntoa
argument_list|(
name|add
argument_list|)
argument_list|,
name|x
operator|->
name|k_flags
argument_list|,
name|x
operator|->
name|checksum
argument_list|,
name|x
operator|->
name|time_sec
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"[8] ="
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|NOENCRYPTION
name|placebo_cblock_print
argument_list|(
name|x
operator|->
name|session
argument_list|)
expr_stmt|;
else|#
directive|else
comment|/* Do Encryption */
name|des_cblock_print_file
argument_list|(
name|x
operator|->
name|session
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* NOENCRYPTION */
comment|/* skip reply for now */
block|}
end_block

begin_ifdef
ifdef|#
directive|ifdef
name|NOENCRYPTION
end_ifdef

begin_comment
comment|/*  * Print in hex the 8 bytes of the given session key.  *  * Printed format is:  " 0x { x, x, x, x, x, x, x, x }"  */
end_comment

begin_macro
name|placebo_cblock_print
argument_list|(
argument|x
argument_list|)
end_macro

begin_decl_stmt
name|des_cblock
name|x
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|unsigned
name|char
modifier|*
name|y
init|=
operator|(
name|unsigned
name|char
operator|*
operator|)
name|x
decl_stmt|;
specifier|register
name|int
name|i
init|=
literal|0
decl_stmt|;
name|printf
argument_list|(
literal|" 0x { "
argument_list|)
expr_stmt|;
while|while
condition|(
name|i
operator|++
operator|<
literal|8
condition|)
block|{
name|printf
argument_list|(
literal|"%x"
argument_list|,
operator|*
name|y
operator|++
argument_list|)
expr_stmt|;
if|if
condition|(
name|i
operator|<
literal|8
condition|)
name|printf
argument_list|(
literal|", "
argument_list|)
expr_stmt|;
block|}
name|printf
argument_list|(
literal|" }"
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NOENCRYPTION */
end_comment

end_unit

