begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"ctlmod.h"
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)cm_close.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  CM_CLOSE -- close the parser write pipe ** **	This routine is a Kludge for use by the tty monitor only. **	It is here because of the difficulty of getting at the **	Cm struct from another directory. */
end_comment

begin_macro
name|cm_close
argument_list|()
end_macro

begin_block
block|{
name|close
argument_list|(
name|Cm
operator|.
name|cm_proc
index|[
literal|1
index|]
operator|.
name|pr_file
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

