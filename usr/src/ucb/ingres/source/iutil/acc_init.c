begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)acc_init.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  ACC_INIT -- fake acc_init. ** **	Modules that do not pull in the access method library will **	choke.  So we include an acc_init here that the ctl module **	can pick up if the access method library has not been **	loaded. */
end_comment

begin_macro
name|acc_init
argument_list|()
end_macro

begin_block
block|{ }
end_block

end_unit

