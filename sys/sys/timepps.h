begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@FreeBSD.org> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $Id: timepps.h,v 1.3 1998/06/13 09:30:24 phk Exp $  *  * The is a FreeBSD protype version of the "draft-mogul-pps-api-02.txt"   * specification for Pulse Per Second timing interfaces.    *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_TIMEPPS_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_TIMEPPS_H_
end_define

begin_include
include|#
directive|include
file|<sys/ioccom.h>
end_include

begin_typedef
typedef|typedef
name|int
name|pps_handle_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|pps_seq_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ntp_fp
block|{
name|unsigned
name|int
name|integral
decl_stmt|;
name|unsigned
name|int
name|fractional
decl_stmt|;
block|}
name|ntp_fp_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
union|union
name|pps_timeu
block|{
name|struct
name|timespec
name|tspec
decl_stmt|;
name|ntp_fp_t
name|ntpfp
decl_stmt|;
name|unsigned
name|long
name|longpair
index|[
literal|2
index|]
decl_stmt|;
block|}
name|pps_timeu_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|pps_seq_t
name|assert_sequence
decl_stmt|;
comment|/* assert event seq # */
name|pps_seq_t
name|clear_sequence
decl_stmt|;
comment|/* clear event seq # */
name|pps_timeu_t
name|assert_tu
decl_stmt|;
name|pps_timeu_t
name|clear_tu
decl_stmt|;
name|int
name|current_mode
decl_stmt|;
comment|/* current mode bits */
block|}
name|pps_info_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|assert_timestamp
value|assert_tu.tspec
end_define

begin_define
define|#
directive|define
name|clear_timestamp
value|clear_tu.tspec
end_define

begin_define
define|#
directive|define
name|assert_timestamp_ntpfp
value|assert_tu.ntpfp
end_define

begin_define
define|#
directive|define
name|clear_timestamp_ntpfp
value|clear_tu.ntpfp
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|mode
decl_stmt|;
comment|/* mode bits */
name|pps_timeu_t
name|assert_off_tu
decl_stmt|;
name|pps_timeu_t
name|clear_off_tu
decl_stmt|;
block|}
name|pps_params_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|assert_offset
value|assert_off_tu.tspec
end_define

begin_define
define|#
directive|define
name|clear_offset
value|clear_off_tu.tspec
end_define

begin_define
define|#
directive|define
name|assert_offset_ntpfp
value|assert_off_tu.ntpfp
end_define

begin_define
define|#
directive|define
name|clear_offset_ntpfp
value|clear_off_tu.ntpfp
end_define

begin_define
define|#
directive|define
name|PPS_CAPTUREASSERT
value|0x01
end_define

begin_define
define|#
directive|define
name|PPS_CAPTURECLEAR
value|0x02
end_define

begin_define
define|#
directive|define
name|PPS_CAPTUREBOTH
value|0x03
end_define

begin_define
define|#
directive|define
name|PPS_OFFSETASSERT
value|0x10
end_define

begin_define
define|#
directive|define
name|PPS_OFFSETCLEAR
value|0x20
end_define

begin_define
define|#
directive|define
name|PPS_HARDPPSONASSERT
value|0x04
end_define

begin_define
define|#
directive|define
name|PPS_HARDPPSONCLEAR
value|0x08
end_define

begin_define
define|#
directive|define
name|PPS_ECHOASSERT
value|0x40
end_define

begin_define
define|#
directive|define
name|PPS_ECHOCLEAR
value|0x80
end_define

begin_define
define|#
directive|define
name|PPS_CANWAIT
value|0x100
end_define

begin_define
define|#
directive|define
name|PPS_TSFMT_TSPEC
value|0x1000
end_define

begin_define
define|#
directive|define
name|PPS_TSFMT_NTPFP
value|0x2000
end_define

begin_struct
struct|struct
name|pps_wait_args
block|{
name|struct
name|timespec
name|timeout
decl_stmt|;
name|pps_info_t
name|pps_info_buf
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|PPS_IOC_CREATE
value|_IO('1', 1)
end_define

begin_define
define|#
directive|define
name|PPS_IOC_DESTROY
value|_IO('1', 2)
end_define

begin_define
define|#
directive|define
name|PPS_IOC_SETPARAMS
value|_IOW('1', 3, pps_params_t)
end_define

begin_define
define|#
directive|define
name|PPS_IOC_GETPARAMS
value|_IOR('1', 4, pps_params_t)
end_define

begin_define
define|#
directive|define
name|PPS_IOC_GETCAP
value|_IOR('1', 5, int)
end_define

begin_define
define|#
directive|define
name|PPS_IOC_FETCH
value|_IOWR('1', 6, pps_info_t)
end_define

begin_define
define|#
directive|define
name|PPS_IOC_WAIT
value|_IOWR('1', 6, struct pps_wait_args)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_decl_stmt
name|int
name|std_pps_ioctl
name|__P
argument_list|(
operator|(
name|u_long
name|cmd
operator|,
name|caddr_t
name|data
operator|,
name|pps_params_t
operator|*
name|pp
operator|,
name|pps_info_t
operator|*
name|pi
operator|,
name|int
name|ppscap
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_TIMEPPS_H_ */
end_comment

end_unit

