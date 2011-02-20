begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Fake system header for Sema/conversion.c */
end_comment

begin_define
define|#
directive|define
name|LONG_MAX
value|__LONG_MAX__
end_define

begin_define
define|#
directive|define
name|SETBIT
parameter_list|(
name|set
parameter_list|,
name|bit
parameter_list|)
value|do { int i = bit; set[i/(8*sizeof(set[0]))] |= (1<< (i%(8*sizeof(set)))); } while(0)
end_define

end_unit

