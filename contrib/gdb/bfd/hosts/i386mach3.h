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

begin_comment
comment|/* This is an ugly way to hack around the incorrect  * definition of UPAGES in i386/machparam.h.  *  * The definition should specify the size reserved  * for "struct user" in core files in PAGES,  * but instead it gives it in 512-byte core-clicks  * for i386 and i860. UPAGES is used only in trad-core.c.  */
end_comment

begin_if
if|#
directive|if
name|UPAGES
operator|==
literal|16
end_if

begin_undef
undef|#
directive|undef
name|UPAGES
end_undef

begin_define
define|#
directive|define
name|UPAGES
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|UPAGES
operator|!=
literal|2
end_if

begin_expr_stmt
name|FIXME
operator|!
operator|!
name|UPAGES
name|is
name|neither
literal|2
name|nor
literal|16
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|HOST_PAGE_SIZE
value|1
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
value|bfd_arch_i386
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

