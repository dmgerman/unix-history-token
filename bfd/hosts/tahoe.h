begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|NO_CORE_COMMAND
end_define

begin_undef
undef|#
directive|undef
name|ALIGN
end_undef

begin_comment
comment|/* They use it, we use it too */
end_comment

begin_include
include|#
directive|include
file|<machine/param.h>
end_include

begin_undef
undef|#
directive|undef
name|ALIGN
end_undef

begin_comment
comment|/* They use it, we use it too */
end_comment

begin_define
define|#
directive|define
name|HOST_PAGE_SIZE
value|NBPG
end_define

begin_define
define|#
directive|define
name|HOST_MACHINE_ARCH
value|bfd_arch_tahoe
end_define

begin_define
define|#
directive|define
name|HOST_TEXT_START_ADDR
value|0
end_define

begin_define
define|#
directive|define
name|HOST_STACK_END_ADDR
value|(KERNBASE - (UPAGES * NBPG))
end_define

begin_define
define|#
directive|define
name|HOST_BIG_ENDIAN_P
end_define

end_unit

