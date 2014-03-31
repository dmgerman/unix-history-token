begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_define
define|#
directive|define
name|UMAC_OUTPUT_LEN
value|16
end_define

begin_undef
undef|#
directive|undef
name|umac_ctx
end_undef

begin_define
define|#
directive|define
name|umac_ctx
value|umac128_ctx
end_define

begin_undef
undef|#
directive|undef
name|umac_new
end_undef

begin_define
define|#
directive|define
name|umac_new
value|umac128_new
end_define

begin_undef
undef|#
directive|undef
name|umac_update
end_undef

begin_define
define|#
directive|define
name|umac_update
value|umac128_update
end_define

begin_undef
undef|#
directive|undef
name|umac_final
end_undef

begin_define
define|#
directive|define
name|umac_final
value|umac128_final
end_define

begin_undef
undef|#
directive|undef
name|umac_delete
end_undef

begin_define
define|#
directive|define
name|umac_delete
value|umac128_delete
end_define

begin_include
include|#
directive|include
file|"umac.c"
end_include

end_unit

