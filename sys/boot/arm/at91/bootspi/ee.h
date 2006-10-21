begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_function_decl
name|void
name|EEInit
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EERead
parameter_list|(
name|unsigned
name|ee_off
parameter_list|,
name|char
modifier|*
name|data_addr
parameter_list|,
name|unsigned
name|size
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|EEWrite
parameter_list|(
name|unsigned
name|ee_off
parameter_list|,
specifier|const
name|char
modifier|*
name|data_addr
parameter_list|,
name|unsigned
name|size
parameter_list|)
function_decl|;
end_function_decl

end_unit

