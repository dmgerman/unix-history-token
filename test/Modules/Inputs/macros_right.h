begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_decl_stmt
unit|@
name|import
name|macros_top
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|RIGHT
value|unsigned short
end_define

begin_define
define|#
directive|define
name|LEFT_RIGHT_IDENTICAL
value|int
end_define

begin_define
define|#
directive|define
name|LEFT_RIGHT_DIFFERENT
value|int
end_define

begin_define
define|#
directive|define
name|LEFT_RIGHT_DIFFERENT2
value|int
end_define

begin_define
define|#
directive|define
name|LEFT_RIGHT_DIFFERENT3
value|int
end_define

begin_undef
undef|#
directive|undef
name|TOP_RIGHT_REDEF
end_undef

begin_define
define|#
directive|define
name|TOP_RIGHT_REDEF
value|float
end_define

begin_define
define|#
directive|define
name|FN_ADD
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(x+y)
end_define

begin_undef
undef|#
directive|undef
name|TOP_OTHER_DEF_RIGHT_UNDEF
end_undef

end_unit

