begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ingres.h>
end_include

begin_include
include|#
directive|include
file|<symbol.h>
end_include

begin_include
include|#
directive|include
file|"IIglobals.h"
end_include

begin_include
include|#
directive|include
file|<sccs.h>
end_include

begin_macro
name|SCCSID
argument_list|(
argument|@(#)IIsetup.c
literal|7.2
literal|2
argument|/
literal|16
argument|/
literal|81
argument_list|)
end_macro

begin_comment
comment|/* **	IIsetup is called to mark the start of a retrieve. */
end_comment

begin_macro
name|IIsetup
argument_list|()
end_macro

begin_block
block|{
ifdef|#
directive|ifdef
name|xETR1
if|if
condition|(
name|IIdebug
condition|)
name|printf
argument_list|(
literal|"IIsetup\n"
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|IIin_retrieve
operator|=
literal|1
expr_stmt|;
name|IIr_sym
operator|.
name|type
operator|=
name|IIr_sym
operator|.
name|len
operator|=
literal|0
expr_stmt|;
name|IIdomains
operator|=
literal|0
expr_stmt|;
name|IIerrflag
operator|=
literal|0
expr_stmt|;
comment|/* flush old data from IIpb and do pre-read */
name|IIpb_flush
argument_list|(
operator|&
name|IIpb
argument_list|)
expr_stmt|;
name|IIpb_prime
argument_list|(
operator|&
name|IIpb
argument_list|,
name|PB_NOTYPE
argument_list|)
expr_stmt|;
block|}
end_block

end_unit

