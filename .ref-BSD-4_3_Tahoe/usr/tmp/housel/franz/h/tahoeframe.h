begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* not used - just to look at I guess */
end_comment

begin_define
define|#
directive|define
name|FRAMOFFSET
value|(-8)
end_define

begin_comment
comment|/* FP points to frame + 8 */
end_comment

begin_struct
struct|struct
name|machframe
block|{
name|lispval
function_decl|(
modifier|*
name|pc
function_decl|)
parameter_list|()
function_decl|;
name|short
name|mask
decl_stmt|;
name|short
name|removed
decl_stmt|;
name|struct
name|machframe
modifier|*
name|fp
decl_stmt|;
name|lispval
modifier|*
name|arg
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

