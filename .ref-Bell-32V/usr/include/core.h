begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* machine dependent stuff for core files */
end_comment

begin_define
define|#
directive|define
name|TXTRNDSIZ
value|512L
end_define

begin_define
define|#
directive|define
name|stacktop
parameter_list|(
name|siz
parameter_list|)
value|(0x80000000L)
end_define

begin_define
define|#
directive|define
name|stackbas
parameter_list|(
name|siz
parameter_list|)
value|(0x80000000L-siz)
end_define

end_unit

