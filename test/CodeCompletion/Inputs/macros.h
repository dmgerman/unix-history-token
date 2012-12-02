begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|FOO
end_define

begin_define
define|#
directive|define
name|BAR
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|X, Y
end_define

begin_define
define|#
directive|define
name|IDENTITY
parameter_list|(
name|X
parameter_list|)
value|X
end_define

begin_define
define|#
directive|define
name|WIBBLE
parameter_list|(
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEAD_MACRO
end_define

begin_undef
undef|#
directive|undef
name|DEAD_MACRO
end_undef

begin_define
define|#
directive|define
name|MACRO_WITH_HISTORY
value|a
end_define

begin_undef
undef|#
directive|undef
name|MACRO_WITH_HISTORY
end_undef

begin_define
define|#
directive|define
name|MACRO_WITH_HISTORY
value|b, c
end_define

begin_undef
undef|#
directive|undef
name|MACRO_WITH_HISTORY
end_undef

begin_define
define|#
directive|define
name|MACRO_WITH_HISTORY
parameter_list|(
name|X
parameter_list|,
name|Y
parameter_list|)
value|X->Y
end_define

end_unit

