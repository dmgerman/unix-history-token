begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  */
end_comment

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_struct
struct|struct
name|ida_user_command
block|{
name|int
name|command
decl_stmt|;
name|int
name|drive
decl_stmt|;
name|u_int32_t
name|blkno
decl_stmt|;
union|union
block|{
name|struct
name|ida_drive_info
name|di
decl_stmt|;
name|struct
name|ida_drive_info_ext
name|die
decl_stmt|;
name|struct
name|ida_controller_info
name|ci
decl_stmt|;
name|struct
name|ida_drive_status
name|ds
decl_stmt|;
name|struct
name|ida_phys_drv_info
name|pdi
decl_stmt|;
name|struct
name|ida_blink_drv_leds
name|bdl
decl_stmt|;
name|struct
name|ida_label_logical
name|ll
decl_stmt|;
name|u_int8_t
name|buf
decl_stmt|;
block|}
name|d
union|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IDAIO_COMMAND
value|_IOWR('I', 100, struct ida_user_command)
end_define

end_unit

