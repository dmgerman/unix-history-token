begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	frame.h	1.1	86/01/05	*/
end_comment

begin_comment
comment|/*  * Definition of the tahoe call frame.  */
end_comment

begin_struct
struct|struct
name|frame
block|{
name|int
name|fr_savpc
decl_stmt|;
comment|/* saved program counter */
name|u_int
name|fr_mask
range|:
literal|16
decl_stmt|,
comment|/* register save mask */
name|fr_removed
range|:
literal|16
decl_stmt|;
comment|/* 4*number of arguments + 4 */
name|int
name|fr_savfp
decl_stmt|;
comment|/* saved frame pointer */
block|}
struct|;
end_struct

end_unit

