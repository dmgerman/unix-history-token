begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	mem.h	4.2	81/02/19	*/
end_comment

begin_comment
comment|/*  * Memory controller registers  */
end_comment

begin_struct
struct|struct
name|mcr
block|{
name|int
name|mc_reg
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|nmcr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|mcr
modifier|*
name|mcraddr
index|[
literal|4
index|]
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|M780_HIERR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|M780_ERLOG
value|0x10000000
end_define

begin_define
define|#
directive|define
name|M750_UNCORR
value|0xc0000000
end_define

begin_define
define|#
directive|define
name|M750_CORERR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|M750_ERLOG
value|(M750_UNCORR|M750_CORERR)
end_define

begin_define
define|#
directive|define
name|MCR_750
value|((struct nexus *)0xf20000)
end_define

begin_define
define|#
directive|define
name|MEMINTVL
value|(60*60*10)
end_define

begin_comment
comment|/* 10 minutes */
end_comment

end_unit

