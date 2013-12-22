begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|DefinedInBImpl
block|{
name|void
name|f
parameter_list|()
function_decl|;
struct|struct
name|Inner
block|{}
struct|;
name|friend
name|void
name|FoundByADL
parameter_list|(
name|DefinedInBImpl
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

end_unit

