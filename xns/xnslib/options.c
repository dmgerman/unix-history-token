begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *temporary file implementing a setsockopt call  * until I find out how Maryland intends to do it.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_macro
name|SetSPPoptions
argument_list|(
argument|s
argument_list|,
argument|stream
argument_list|,
argument|eom
argument_list|,
argument|attn
argument_list|)
end_macro

begin_decl_stmt
name|int
name|s
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* SPP socket */
end_comment

begin_decl_stmt
name|u_char
name|stream
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* datastream type */
end_comment

begin_decl_stmt
name|char
name|eom
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Boolean EOM */
end_comment

begin_comment
comment|/* can't set ATTN -- use MSG_OOB instead */
end_comment

begin_block
block|{
comment|/* 	setsockopt(s, SOL_PROTO, SPPOPT_DATASTREAMTYPE,&stream, 		   sizeof(stream)); 	setsockopt(s, SOL_PROTO, SPPOPT_EOMBIT,&eom, sizeof(eom)); 	*/
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"SetSPPoptions called , now obsoleted\n"
argument_list|)
expr_stmt|;
name|abort
argument_list|()
expr_stmt|;
block|}
end_block

end_unit

