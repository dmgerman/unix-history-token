begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@FreeBSD.org> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $FreeBSD$  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_XRPUIO_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_XRPUIO_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_define
define|#
directive|define
name|XRPU_MAX_PPS
value|16
end_define

begin_struct
struct|struct
name|xrpu_timecounting
block|{
comment|/* The timecounter itself */
name|u_int
name|xt_addr_trigger
decl_stmt|;
name|u_int
name|xt_addr_latch
decl_stmt|;
name|unsigned
name|xt_mask
decl_stmt|;
name|u_int32_t
name|xt_frequency
decl_stmt|;
name|char
name|xt_name
index|[
literal|16
index|]
decl_stmt|;
comment|/* The PPS latches */
struct|struct
block|{
name|u_int
name|xt_addr_assert
decl_stmt|;
name|u_int
name|xt_addr_clear
decl_stmt|;
block|}
name|xt_pps
index|[
name|XRPU_MAX_PPS
index|]
struct|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|XRPU_IOC_TIMECOUNTING
value|_IOW('6', 1, struct xrpu_timecounting)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_XRPUIO_H_ */
end_comment

end_unit

