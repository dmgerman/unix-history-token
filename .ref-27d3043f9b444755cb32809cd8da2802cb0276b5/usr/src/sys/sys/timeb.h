begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	timeb.h	4.1	%G%	*/
end_comment

begin_comment
comment|/*  * Structure returned by ftime system call  */
end_comment

begin_struct
struct|struct
name|timeb
block|{
name|time_t
name|time
decl_stmt|;
name|unsigned
name|short
name|millitm
decl_stmt|;
name|short
name|timezone
decl_stmt|;
name|short
name|dstflag
decl_stmt|;
block|}
struct|;
end_struct

end_unit

