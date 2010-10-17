begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* RISC/os 4.52C, and presumably other versions.  */
end_comment

begin_include
include|#
directive|include
file|<bsd43/machine/machparam.h>
end_include

begin_include
include|#
directive|include
file|<bsd43/machine/vmparam.h>
end_include

begin_define
define|#
directive|define
name|NBPG
value|BSD43_NBPG
end_define

begin_define
define|#
directive|define
name|UPAGES
value|BSD43_UPAGES
end_define

begin_define
define|#
directive|define
name|HOST_TEXT_START_ADDR
value|BSD43_USRTEXT
end_define

begin_define
define|#
directive|define
name|HOST_DATA_START_ADDR
value|BSD43_USRDATA
end_define

begin_define
define|#
directive|define
name|HOST_STACK_END_ADDR
value|BSD43_USRSTACK
end_define

end_unit

