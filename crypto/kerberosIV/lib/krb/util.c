begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * Copyright 1988 by the Massachusetts Institute of Technology.  *  * For copying and distribution information, please see the file  *<mit-copyright.h>.  *  * Miscellaneous debug printing utilities  */
end_comment

begin_include
include|#
directive|include
file|"krb_locl.h"
end_include

begin_expr_stmt
name|RCSID
argument_list|(
literal|"$Id: util.c,v 1.6 1996/10/05 00:18:34 joda Exp $"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/*  * Print some of the contents of the given authenticator structure  * (AUTH_DAT defined in "krb.h").  Fields printed are:  *  * pname, pinst, prealm, netaddr, flags, cksum, timestamp, session  */
end_comment

begin_function
name|void
name|ad_print
parameter_list|(
name|AUTH_DAT
modifier|*
name|x
parameter_list|)
block|{
comment|/*      * Print the contents of an auth_dat struct.      */
name|struct
name|in_addr
name|address
decl_stmt|;
name|address
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
name|address
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
name|des_cblock_print_file
argument_list|(
operator|&
name|x
operator|->
name|session
argument_list|,
name|stdout
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* skip reply for now */
block|}
end_function

begin_comment
comment|/*  * Print in hex the 8 bytes of the given session key.  *  * Printed format is:  " 0x { x, x, x, x, x, x, x, x }"  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NOENCRYPTION
end_ifdef

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

end_unit

