begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	inet_lnaof.c	4.1	82/10/07	*/
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<net/in.h>
end_include

begin_comment
comment|/*  * Return the local network address portion of an  * internet address; handles class a/b/c network  * number formats.  */
end_comment

begin_macro
name|in_lnaof
argument_list|(
argument|in
argument_list|)
end_macro

begin_decl_stmt
name|struct
name|in_addr
name|in
decl_stmt|;
end_decl_stmt

begin_block
block|{
if|#
directive|if
name|vax
operator|||
name|pdp11
define|#
directive|define
name|IN_LNAOF
parameter_list|(
name|in
parameter_list|)
define|\
value|(((in).s_addr&IN_CLASSA) == 0 ? (in).s_addr&IN_CLASSA_LNA : \ 		((in).s_addr&IN_CLASSB) == 0 ? (in).s_addr&IN_CLASSB_LNA : \ 			(in).s_addr&IN_CLASSC_LNA)
return|return
operator|(
operator|(
name|int
operator|)
name|htonl
argument_list|(
operator|(
name|u_long
operator|)
name|IN_LNAOF
argument_list|(
name|in
argument_list|)
argument_list|)
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|IN_LNAOF
argument_list|(
name|in
argument_list|)
operator|)
return|;
endif|#
directive|endif
block|}
end_block

end_unit

