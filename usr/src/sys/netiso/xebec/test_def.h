begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|blah
block|{
name|unsigned
name|int
name|blahfield
decl_stmt|;
name|int
name|dummyi
decl_stmt|;
name|char
name|dummyc
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|test_pcbstruct
block|{
name|int
name|test_pcbfield
decl_stmt|;
name|int
name|test_state
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MACRO1
parameter_list|(
name|arg
parameter_list|)
value|if(arg != 0) { printf("macro1\n"); }
end_define

end_unit

