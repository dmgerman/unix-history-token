begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<machine/vmparam.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_undef
undef|#
directive|undef
name|UPAGES
end_undef

begin_define
define|#
directive|define
name|UPAGES
value|3
end_define

begin_define
define|#
directive|define
name|HOST_PAGE_SIZE
value|NBPG
end_define

begin_define
define|#
directive|define
name|HOST_SEGMENT_SIZE
value|NBPG
end_define

begin_define
define|#
directive|define
name|HOST_MACHINE_ARCH
value|bfd_arch_m88k
end_define

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

end_unit

