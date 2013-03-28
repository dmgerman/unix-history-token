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

begin_define
define|#
directive|define
name|umac_new
value|ssh_umac128_new
end_define

begin_define
define|#
directive|define
name|umac_update
value|ssh_umac128_update
end_define

begin_define
define|#
directive|define
name|umac_final
value|ssh_umac128_final
end_define

begin_define
define|#
directive|define
name|umac_delete
value|ssh_umac128_delete
end_define

begin_include
include|#
directive|include
file|"umac.c"
end_include

end_unit

