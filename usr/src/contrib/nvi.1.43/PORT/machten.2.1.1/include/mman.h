begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* Fake<sys/mman.h> included by ex/ex_tag.c. */
end_comment

begin_undef
undef|#
directive|undef
name|PROT_READ
end_undef

begin_define
define|#
directive|define
name|PROT_READ
value|0
end_define

begin_undef
undef|#
directive|undef
name|MAP_PRIVATE
end_undef

begin_define
define|#
directive|define
name|MAP_PRIVATE
value|0
end_define

begin_define
define|#
directive|define
name|mmap
value|mmap_read
end_define

begin_define
define|#
directive|define
name|munmap
value|munmap_read
end_define

end_unit

