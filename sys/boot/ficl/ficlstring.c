begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************* ** f i c l s t r i n g . c ** Forth Inspired Command Language ** ANS STRING words plus ficl extras for c-string class ** Author: John Sadler (john_sadler@alum.mit.edu) ** Created: 2 June 2000 **  *******************************************************************/
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TESTMAIN
end_ifdef

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<stand.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"ficl.h"
end_include

begin_comment
comment|/**************************************************************************                         f o r m a t ** ( params... fmt-addr fmt-u dest-addr dest-u -- dest-addr dest-u ) **************************************************************************/
end_comment

begin_function
name|void
name|ficlStrFormat
parameter_list|(
name|FICL_VM
modifier|*
name|pVM
parameter_list|)
block|{
return|return;
block|}
end_function

end_unit

