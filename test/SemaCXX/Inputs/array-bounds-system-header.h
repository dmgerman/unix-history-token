begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// "System header" for testing that -Warray-bounds is properly suppressed in
end_comment

begin_comment
comment|// certain cases.
end_comment

begin_define
define|#
directive|define
name|BAD_MACRO_1
define|\
value|int i[3]; \     i[3] = 5
end_define

begin_define
define|#
directive|define
name|BAD_MACRO_2
parameter_list|(
name|_b
parameter_list|,
name|_i
parameter_list|)
define|\
value|(_b)[(_i)] = 5
end_define

begin_define
define|#
directive|define
name|QUESTIONABLE_MACRO
parameter_list|(
name|_a
parameter_list|)
define|\
value|sizeof(_a)> 3 ? (_a)[3] = 5 : 5
end_define

begin_define
define|#
directive|define
name|NOP
parameter_list|(
name|x
parameter_list|)
value|(x)
end_define

end_unit

