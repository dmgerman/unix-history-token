begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4_4
end_ifdef

begin_define
define|#
directive|define
name|NO_CORE_COMMAND
end_define

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* Data seg start addr rounds to NBPG */
end_comment

begin_define
define|#
directive|define
name|HOST_MACHINE_ARCH
value|bfd_arch_m68k
end_define

begin_comment
comment|/* #define	HOST_MACHINE_MACHINE	 */
end_comment

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
value|0xfff00000
end_define

begin_define
define|#
directive|define
name|HOST_BIG_ENDIAN_P
end_define

end_unit

