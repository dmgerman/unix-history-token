begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: backpage.h,v 4.3 85/05/01 11:36:11 lwall Exp $  *  * $Log:	backpage.h,v $  * Revision 4.3  85/05/01  11:36:11  lwall  * Baseline for release with 4.3bsd.  *   */
end_comment

begin_comment
comment|/* things for doing the 'back page' command */
end_comment

begin_decl_stmt
name|EXT
name|int
name|varyfd
name|INIT
argument_list|(
literal|0
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* virtual array file for storing  */
end_comment

begin_comment
comment|/* file offsets */
end_comment

begin_decl_stmt
name|EXT
name|ART_POS
name|varybuf
index|[
name|VARYSIZE
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* current window onto virtual array */
end_comment

begin_decl_stmt
name|EXT
name|long
name|oldoffset
name|INIT
argument_list|(
operator|-
literal|1
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* offset to block currently in window */
end_comment

begin_function_decl
name|void
name|backpage_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|ART_POS
name|vrdary
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|void
name|vwtary
parameter_list|()
function_decl|;
end_function_decl

end_unit

