begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ----------------------------------------------------------------------------  * "THE BEER-WARE LICENSE" (Revision 42):  *<phk@FreeBSD.org> wrote this file.  As long as you retain this notice you  * can do whatever you want with this stuff. If we meet some day, and you think  * this stuff is worth it, you can buy me a beer in return.   Poul-Henning Kamp  * ----------------------------------------------------------------------------  *  * $Id: timepps.h,v 1.7 1999/03/30 11:44:59 phk Exp $  *  * The is a FreeBSD protype version of the "draft-mogul-pps-api-02.txt"   * specification for Pulse Per Second timing interfaces.    *  * NOTE: There is no current maintainer for this API in FreeBSD, and  *       the implementation will not be updated to track the newer  *	 versions of the draft.  Contact phk@FreeBSD.org for more info.  *  */
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

begin_struct
struct|struct
name|pps_state
block|{
name|pps_params_t
name|ppsparam
decl_stmt|;
name|pps_info_t
name|ppsinfo
decl_stmt|;
name|int
name|ppscap
decl_stmt|;
name|struct
name|timecounter
modifier|*
name|ppstc
decl_stmt|;
name|unsigned
name|ppscount
index|[
literal|3
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|void
name|pps_event
name|__P
argument_list|(
operator|(
expr|struct
name|pps_state
operator|*
name|pps
operator|,
expr|struct
name|timecounter
operator|*
name|tc
operator|,
name|unsigned
name|count
operator|,
name|int
name|event
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|pps_init
name|__P
argument_list|(
operator|(
expr|struct
name|pps_state
operator|*
name|pps
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|pps_ioctl
name|__P
argument_list|(
operator|(
name|u_long
name|cmd
operator|,
name|caddr_t
name|data
operator|,
expr|struct
name|pps_state
operator|*
name|pps
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|void
name|hardpps
name|__P
argument_list|(
operator|(
expr|struct
name|timespec
operator|*
name|tsp
operator|,
name|long
name|nsec
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !KERNEL */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|time_pps_create
parameter_list|(
name|int
name|filedes
parameter_list|,
name|pps_handle_t
modifier|*
name|handle
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
operator|*
name|handle
operator|=
operator|-
literal|1
expr_stmt|;
name|error
operator|=
name|ioctl
argument_list|(
name|filedes
argument_list|,
name|PPS_IOC_CREATE
argument_list|,
literal|0
argument_list|)
expr_stmt|;
if|if
condition|(
name|error
operator|<
literal|0
condition|)
return|return
operator|(
operator|-
literal|1
operator|)
return|;
operator|*
name|handle
operator|=
name|filedes
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|time_pps_destroy
parameter_list|(
name|pps_handle_t
name|handle
parameter_list|)
block|{
return|return
operator|(
name|ioctl
argument_list|(
name|handle
argument_list|,
name|PPS_IOC_DESTROY
argument_list|,
literal|0
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|time_pps_setparams
parameter_list|(
name|pps_handle_t
name|handle
parameter_list|,
specifier|const
name|pps_params_t
modifier|*
name|ppsparams
parameter_list|)
block|{
return|return
operator|(
name|ioctl
argument_list|(
name|handle
argument_list|,
name|PPS_IOC_SETPARAMS
argument_list|,
name|ppsparams
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|time_pps_getparams
parameter_list|(
name|pps_handle_t
name|handle
parameter_list|,
name|pps_params_t
modifier|*
name|ppsparams
parameter_list|)
block|{
return|return
operator|(
name|ioctl
argument_list|(
name|handle
argument_list|,
name|PPS_IOC_GETPARAMS
argument_list|,
name|ppsparams
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|time_pps_getcap
parameter_list|(
name|pps_handle_t
name|handle
parameter_list|,
name|int
modifier|*
name|mode
parameter_list|)
block|{
return|return
operator|(
name|ioctl
argument_list|(
name|handle
argument_list|,
name|PPS_IOC_GETCAP
argument_list|,
name|mode
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|time_pps_fetch
parameter_list|(
name|pps_handle_t
name|handle
parameter_list|,
name|pps_info_t
modifier|*
name|ppsinfobuf
parameter_list|)
block|{
return|return
operator|(
name|ioctl
argument_list|(
name|handle
argument_list|,
name|PPS_IOC_FETCH
argument_list|,
name|ppsinfobuf
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|int
name|time_pps_wait
parameter_list|(
name|pps_handle_t
name|handle
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
name|timeout
parameter_list|,
name|pps_info_t
modifier|*
name|ppsinfobuf
parameter_list|)
block|{
name|int
name|error
decl_stmt|;
name|struct
name|pps_wait_args
name|arg
decl_stmt|;
name|arg
operator|.
name|timeout
operator|=
operator|*
name|timeout
expr_stmt|;
name|error
operator|=
name|ioctl
argument_list|(
name|handle
argument_list|,
name|PPS_IOC_WAIT
argument_list|,
operator|&
name|arg
argument_list|)
expr_stmt|;
operator|*
name|ppsinfobuf
operator|=
name|arg
operator|.
name|pps_info_buf
expr_stmt|;
return|return
operator|(
name|error
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_TIMEPPS_H_ */
end_comment

end_unit

