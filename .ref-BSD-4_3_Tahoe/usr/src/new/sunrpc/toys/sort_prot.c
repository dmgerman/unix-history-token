begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * sort_prot.c  * Implements the protcol filter for the toy sort service.  */
end_comment

begin_include
include|#
directive|include
file|<rpc/rpc.h>
end_include

begin_include
include|#
directive|include
file|"sort_prot.h"
end_include

begin_function
name|int
name|xdr_sortstrings
parameter_list|(
name|xdrs
parameter_list|,
name|ssp
parameter_list|)
name|XDR
modifier|*
name|xdrs
decl_stmt|;
name|struct
name|sortstrings
modifier|*
name|ssp
decl_stmt|;
block|{
return|return
operator|(
name|xdr_array
argument_list|(
name|xdrs
argument_list|,
operator|&
name|ssp
operator|->
name|s
argument_list|,
operator|&
name|ssp
operator|->
name|ns
argument_list|,
name|MAXSORTSIZE
argument_list|,
sizeof|sizeof
argument_list|(
name|char
operator|*
argument_list|)
argument_list|,
name|xdr_wrapstring
argument_list|)
operator|)
return|;
block|}
end_function

end_unit

