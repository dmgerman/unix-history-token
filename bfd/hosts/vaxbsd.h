begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|NO_CORE_COMMAND
end_define

begin_comment
comment|/* No command name in core file */
end_comment

begin_undef
undef|#
directive|undef
name|ALIGN
end_undef

begin_comment
comment|/* They use it, we use it too */
end_comment

begin_comment
comment|/* Note that HOST_PAGE_SIZE -- the page size as far as executable files    are concerned -- is not the same as NBPG, because of page clustering.  */
end_comment

begin_define
define|#
directive|define
name|HOST_PAGE_SIZE
value|1024
end_define

begin_define
define|#
directive|define
name|HOST_MACHINE_ARCH
value|bfd_arch_vax
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
value|(0x80000000 - (UPAGES * NBPG))
end_define

begin_undef
undef|#
directive|undef
name|HOST_BIG_ENDIAN_P
end_undef

end_unit

