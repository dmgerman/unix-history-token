begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* char id_sleep[] = "@(#)sleep_.c	1.1";  *  * sleep for awhile  *  * calling sequence:  *	call sleep(seconds)  * where:  *	seconds is an integer number of seconds to sleep (see sleep(3))  */
end_comment

begin_macro
name|sleep_
argument_list|(
argument|sec
argument_list|)
end_macro

begin_decl_stmt
name|long
modifier|*
name|sec
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|sleep
argument_list|(
operator|(
name|unsigned
name|int
operator|)
operator|*
name|sec
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

