begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* AWE32 driver version number */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|AWE_VERSION_H_DEF
end_ifndef

begin_define
define|#
directive|define
name|AWE_VERSION_H_DEF
end_define

begin_define
define|#
directive|define
name|AWE_VERSION_NUMBER
value|0x00040203
end_define

begin_define
define|#
directive|define
name|AWEDRV_VERSION
value|"0.4.2c"
end_define

begin_define
define|#
directive|define
name|AWE_MAJOR_VERSION
parameter_list|(
name|id
parameter_list|)
value|(((id)>> 16)& 0xff)
end_define

begin_define
define|#
directive|define
name|AWE_MINOR_VERSION
parameter_list|(
name|id
parameter_list|)
value|(((id)>> 8)& 0xff)
end_define

begin_define
define|#
directive|define
name|AWE_TINY_VERSION
parameter_list|(
name|id
parameter_list|)
value|((id)& 0xff)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

