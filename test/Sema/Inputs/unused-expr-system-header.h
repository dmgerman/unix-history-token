begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|// "System header" for testing that -Wunused-value is properly suppressed in
end_comment

begin_comment
comment|// certain cases.
end_comment

begin_define
define|#
directive|define
name|POSSIBLY_BAD_MACRO
parameter_list|(
name|x
parameter_list|)
define|\
value|{ int i = x; \     i; }
end_define

begin_define
define|#
directive|define
name|STATEMENT_EXPR_MACRO
parameter_list|(
name|x
parameter_list|)
define|\
value|(__extension__ \    ({int i = x; \      i;}))
end_define

begin_define
define|#
directive|define
name|COMMA_MACRO_1
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|{x, y;}
end_define

begin_define
define|#
directive|define
name|COMMA_MACRO_2
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|if (x) { 1 == 2, y; }
end_define

begin_define
define|#
directive|define
name|COMMA_MACRO_3
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|(x, y)
end_define

begin_define
define|#
directive|define
name|COMMA_MACRO_4
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|( 1 == 2, y )
end_define

end_unit

