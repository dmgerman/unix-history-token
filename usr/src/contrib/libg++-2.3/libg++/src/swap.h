begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* From Ron Guillmette; apparently needed for Hansen's code */
end_comment

begin_define
define|#
directive|define
name|swap
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|({ typeof(a) temp = (a); (a) = (b); (b) = temp; })
end_define

end_unit

