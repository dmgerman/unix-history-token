begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header$ */
end_comment

begin_comment
comment|/*  * Target definitions  *  * Author: Peter J. Nicklin  */
end_comment

begin_comment
comment|/*  * Target struct  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_target
block|{
name|int
name|type
decl_stmt|;
comment|/* prog, lib, or other target type */
name|int
name|dest
decl_stmt|;
comment|/* target destination flag */
block|}
name|TARGET
typedef|;
end_typedef

end_unit

