begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Definitions for a Motorola Delta 3300 box running System V R3.0.    Contributed by manfred@lts.sel.alcatel.de.  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_comment
comment|/* Definitions used by trad-core.c.  */
end_comment

begin_define
define|#
directive|define
name|NBPG
value|NBPC
end_define

begin_define
define|#
directive|define
name|HOST_DATA_START_ADDR
value|u.u_exdata.ux_datorg
end_define

begin_define
define|#
directive|define
name|HOST_TEXT_START_ADDR
value|u.u_exdata.ux_txtorg
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|HOST_STACK_END_ADDR
value|0x40000000
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* User's stack, copied from sys/param.h  */
end_comment

begin_define
define|#
directive|define
name|HOST_STACK_END_ADDR
value|USRSTACK
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|UPAGES
value|USIZE
end_define

begin_define
define|#
directive|define
name|TRAD_UNIX_CORE_FILE_FAILING_SIGNAL
parameter_list|(
name|abfd
parameter_list|)
define|\
value|abfd->tdata.trad_core_data->u.u_abort
end_define

end_unit

