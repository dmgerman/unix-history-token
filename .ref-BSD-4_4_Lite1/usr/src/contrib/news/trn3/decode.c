begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Id: decode.c,v 3.0 1991/11/22 04:12:25 davison Trn $  */
end_comment

begin_include
include|#
directive|include
file|"EXTERN.h"
end_include

begin_include
include|#
directive|include
file|"common.h"
end_include

begin_include
include|#
directive|include
file|"INTERN.h"
end_include

begin_include
include|#
directive|include
file|"decode.h"
end_include

begin_function
name|void
name|decode_init
parameter_list|()
block|{
name|unship_init
argument_list|()
expr_stmt|;
block|}
end_function

begin_function
name|void
name|decode_end
parameter_list|()
block|{
if|if
condition|(
name|decode_fp
operator|!=
name|Nullfp
condition|)
block|{
name|fclose
argument_list|(
name|decode_fp
argument_list|)
expr_stmt|;
name|decode_fp
operator|=
name|Nullfp
expr_stmt|;
name|printf
argument_list|(
literal|"\n%s INCOMPLETE -- removed.\n"
argument_list|,
argument|decode_dest
argument_list|)
name|FLUSH
expr_stmt|;
name|unlink
argument_list|(
name|decode_dest
argument_list|)
expr_stmt|;
block|}
block|}
end_function

end_unit

