begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_pragma
pragma|#
directive|pragma
name|GCC
name|system_header
end_pragma

begin_pragma
pragma|#
directive|pragma
name|once
end_pragma

begin_function
specifier|inline
name|void
name|f
parameter_list|()
block|{
specifier|register
name|int
name|k
decl_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|to_int
parameter_list|(
name|x
parameter_list|)
value|({ register int n = (x); n; })
end_define

end_unit

