begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|utimbuf
block|{
name|time_t
name|actime
decl_stmt|;
name|time_t
name|modtime
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|utime
parameter_list|(
name|char
modifier|*
parameter_list|,
name|struct
name|utimbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

