begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<machine/param.h>
end_include

begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_undef
undef|#
directive|undef
name|ALIGN
end_undef

begin_define
define|#
directive|define
name|HOST_PAGE_SIZE
value|NBPG
end_define

begin_comment
comment|/* #define	HOST_SEGMENT_SIZE	NBPG -- we use HOST_DATA_START_ADDR */
end_comment

begin_define
define|#
directive|define
name|HOST_MACHINE_ARCH
value|bfd_arch_mips
end_define

begin_comment
comment|/* #define	HOST_MACHINE_MACHINE	 */
end_comment

begin_define
define|#
directive|define
name|HOST_TEXT_START_ADDR
value|USRTEXT
end_define

begin_define
define|#
directive|define
name|HOST_STACK_END_ADDR
value|USRSTACK
end_define

begin_define
define|#
directive|define
name|NO_CORE_COMMAND
end_define

end_unit

