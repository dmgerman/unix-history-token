begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions that are needed for core files.  Core section sizes for    the DPX2 are in bytes.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_define
define|#
directive|define
name|NBPG
value|1
end_define

begin_define
define|#
directive|define
name|UPAGES
value|(USIZE * NBPP)
end_define

begin_define
define|#
directive|define
name|HOST_DATA_START_ADDR
value|(u.u_exdata.ux_datorg)
end_define

begin_define
define|#
directive|define
name|HOST_STACK_END_ADDR
value|(USERSTACK)
end_define

end_unit

