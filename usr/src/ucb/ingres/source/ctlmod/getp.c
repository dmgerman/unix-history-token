begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|"ctlmod.h"
end_include

begin_include
include|#
directive|include
file|<pv.h>
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)getp.c
literal|7.1
literal|2
argument|/
literal|5
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **  GETP -- returns the current PV ** **	Parameters: **		none ** **	Returns: **		a pointer to the pv. (the PV[PC].pv_type == PV_EOF) ** **	Side Effects: **		sets PV[PC].pv_type = PV_EOF. */
end_comment

begin_function
name|PARM
modifier|*
name|getp
parameter_list|()
block|{
name|Ctx
operator|.
name|ctx_pv
index|[
name|Ctx
operator|.
name|ctx_pc
index|]
operator|.
name|pv_type
operator|=
name|PV_EOF
expr_stmt|;
return|return
operator|(
name|Ctx
operator|.
name|ctx_pv
operator|)
return|;
block|}
end_function

end_unit

