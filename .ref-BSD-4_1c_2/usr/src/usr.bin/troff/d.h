begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)d.h	4.1 6/7/82  */
end_comment

begin_struct
struct|struct
name|d
block|{
name|filep
name|op
decl_stmt|;
name|int
name|dnl
decl_stmt|,
name|dimac
decl_stmt|,
name|ditrap
decl_stmt|,
name|ditf
decl_stmt|,
name|alss
decl_stmt|,
name|blss
decl_stmt|,
name|nls
decl_stmt|,
name|mkline
decl_stmt|,
name|maxl
decl_stmt|,
name|hnl
decl_stmt|,
name|curd
decl_stmt|;
block|}
name|d
index|[
name|NDI
index|]
struct|,
modifier|*
name|dip
struct|;
end_struct

end_unit

