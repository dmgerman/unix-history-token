begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************************************************************  *								       *  * Copyright (c) David L. Mills 1999-2000			       *  *								       *  * Permission to use, copy, modify, and distribute this software and   *  * its documentation for any purpose and with or without fee is hereby *  * granted, provided that the above copyright notice appears in all    *  * copies and that both the copyright notice and this permission       *  * notice appear in supporting documentation, and that the name        *  * University of Delaware not be used in advertising or publicity      *  * pertaining to distribution of the software without specific,        *  * written prior permission. The University of Delaware makes no       *  * representations about the suitability this software for any	       *  * purpose. It is provided "as is" without express or implied          *  * warranty.							       *  *								       *  ***********************************************************************  *								       *  * This header file complies with "Pulse-Per-Second API for UNIX-like  *  * Operating Systems, Version 1.0", rfc2783. Credit is due Jeff Mogul  *  * and Marc Brett, from whom much of this code was shamelessly stolen. *  *								       *  * this modified timepps.h can be used to provide a PPSAPI interface   *  * to a machine running SCO Unix.				       *  *								       *  ***********************************************************************  *								       *  * A full PPSAPI interface to the SCO Unix kernel would be better, but *  * this at least removes the necessity for special coding from the NTP *  * NTP drivers. 						       *  *								       *  ***********************************************************************  *								       *  * Some of this include file					       *  * Copyright (c) 1999 by Ulrich Windl,				       *  *	based on code by Reg Clemens<reg@dwf.com>		       *  *		based on code by Poul-Henning Kamp<phk@FreeBSD.org>   *  *								       *  ***********************************************************************  *								       *  * "THE BEER-WARE LICENSE" (Revision 42):                              *  *<phk@FreeBSD.org> wrote this file.  As long as you retain this      *  * notice you can do whatever you want with this stuff. If we meet some*  * day, and you think this stuff is worth it, you can buy me a beer    *  * in return.	Poul-Henning Kamp				       *  *								       *  **********************************************************************/
end_comment

begin_comment
comment|/*SCO UNIX version, TIOCDCDTIMESTAMP assumed to exist. */
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
file|<termios.h>
end_include

begin_comment
comment|/* to get TIOCDCDTIMESTAMP */
end_comment

begin_comment
comment|/* Implementation note: the logical states ``assert'' and ``clear''  * are implemented in terms of the UART register, i.e. ``assert''  * means the bit is set.  */
end_comment

begin_comment
comment|/*  * The following definitions are architecture independent  */
end_comment

begin_define
define|#
directive|define
name|PPS_API_VERS_1
value|1
end_define

begin_comment
comment|/* API version number */
end_comment

begin_define
define|#
directive|define
name|PPS_JAN_1970
value|2208988800UL
end_define

begin_comment
comment|/* 1970 - 1900 in seconds */
end_comment

begin_define
define|#
directive|define
name|PPS_NANOSECOND
value|1000000000L
end_define

begin_comment
comment|/* one nanosecond in decimal */
end_comment

begin_define
define|#
directive|define
name|PPS_FRAC
value|4294967296.
end_define

begin_comment
comment|/* 2^32 as a double */
end_comment

begin_define
define|#
directive|define
name|PPS_NORMALIZE
parameter_list|(
name|x
parameter_list|)
comment|/* normalize timespec */
define|\
value|do { \ 		if ((x).tv_nsec>= PPS_NANOSECOND) { \ 			(x).tv_nsec -= PPS_NANOSECOND; \ 			(x).tv_sec++; \ 		} else if ((x).tv_nsec< 0) { \ 			(x).tv_nsec += PPS_NANOSECOND; \ 			(x).tv_sec--; \ 		} \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|PPS_TSPECTONTP
parameter_list|(
name|x
parameter_list|)
comment|/* convert timespec to l_fp */
define|\
value|do { \ 		double d_temp; \ 	\ 		(x).integral += (unsigned int)PPS_JAN_1970; \ 		d_temp = (x).fractional * PPS_FRAC / PPS_NANOSECOND; \ 		if (d_temp>= PPS_FRAC) \ 			(x).integral++; \ 		(x).fractional = (unsigned int)d_temp; \ 	} while (0)
end_define

begin_comment
comment|/*  * Device/implementation parameters (mode)  */
end_comment

begin_define
define|#
directive|define
name|PPS_CAPTUREASSERT
value|0x01
end_define

begin_comment
comment|/* capture assert events */
end_comment

begin_define
define|#
directive|define
name|PPS_CAPTURECLEAR
value|0x02
end_define

begin_comment
comment|/* capture clear events */
end_comment

begin_define
define|#
directive|define
name|PPS_CAPTUREBOTH
value|0x03
end_define

begin_comment
comment|/* capture assert and clear events */
end_comment

begin_define
define|#
directive|define
name|PPS_OFFSETASSERT
value|0x10
end_define

begin_comment
comment|/* apply compensation for assert ev. */
end_comment

begin_define
define|#
directive|define
name|PPS_OFFSETCLEAR
value|0x20
end_define

begin_comment
comment|/* apply compensation for clear ev. */
end_comment

begin_define
define|#
directive|define
name|PPS_OFFSETBOTH
value|0x30
end_define

begin_comment
comment|/* apply compensation for both */
end_comment

begin_define
define|#
directive|define
name|PPS_CANWAIT
value|0x100
end_define

begin_comment
comment|/* Can we wait for an event? */
end_comment

begin_define
define|#
directive|define
name|PPS_CANPOLL
value|0x200
end_define

begin_comment
comment|/* "This bit is reserved for */
end_comment

begin_comment
comment|/*  * Kernel actions (mode)  */
end_comment

begin_define
define|#
directive|define
name|PPS_ECHOASSERT
value|0x40
end_define

begin_comment
comment|/* feed back assert event to output */
end_comment

begin_define
define|#
directive|define
name|PPS_ECHOCLEAR
value|0x80
end_define

begin_comment
comment|/* feed back clear event to output */
end_comment

begin_comment
comment|/*  * Timestamp formats (tsformat)  */
end_comment

begin_define
define|#
directive|define
name|PPS_TSFMT_TSPEC
value|0x1000
end_define

begin_comment
comment|/* select timespec format */
end_comment

begin_define
define|#
directive|define
name|PPS_TSFMT_NTPFP
value|0x2000
end_define

begin_comment
comment|/* select NTP format */
end_comment

begin_comment
comment|/*  * Kernel discipline actions (not used in Solaris)  */
end_comment

begin_define
define|#
directive|define
name|PPS_KC_HARDPPS
value|0
end_define

begin_comment
comment|/* enable kernel consumer */
end_comment

begin_define
define|#
directive|define
name|PPS_KC_HARDPPS_PLL
value|1
end_define

begin_comment
comment|/* phase-lock mode */
end_comment

begin_define
define|#
directive|define
name|PPS_KC_HARDPPS_FLL
value|2
end_define

begin_comment
comment|/* frequency-lock mode */
end_comment

begin_comment
comment|/*  * Type definitions  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|long
name|pps_seq_t
typedef|;
end_typedef

begin_comment
comment|/* sequence number */
end_comment

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

begin_comment
comment|/* NTP-compatible time stamp */
end_comment

begin_typedef
typedef|typedef
union|union
name|pps_timeu
block|{
comment|/* timestamp format */
name|struct
name|timespec
name|tspec
decl_stmt|;
name|ntp_fp_t
name|ntpfp
decl_stmt|;
name|unsigned
name|long
name|longpad
index|[
literal|3
index|]
decl_stmt|;
block|}
name|pps_timeu_t
typedef|;
end_typedef

begin_comment
comment|/* generic data type to represent time stamps */
end_comment

begin_comment
comment|/*  * Timestamp information structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pps_info
block|{
name|pps_seq_t
name|assert_sequence
decl_stmt|;
comment|/* seq. num. of assert event */
name|pps_seq_t
name|clear_sequence
decl_stmt|;
comment|/* seq. num. of clear event */
name|pps_timeu_t
name|assert_tu
decl_stmt|;
comment|/* time of assert event */
name|pps_timeu_t
name|clear_tu
decl_stmt|;
comment|/* time of clear event */
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

begin_comment
comment|/*  * Parameter structure  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|pps_params
block|{
name|int
name|api_version
decl_stmt|;
comment|/* API version # */
name|int
name|mode
decl_stmt|;
comment|/* mode bits */
name|pps_timeu_t
name|assert_off_tu
decl_stmt|;
comment|/* offset compensation for assert */
name|pps_timeu_t
name|clear_off_tu
decl_stmt|;
comment|/* offset compensation for clear */
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

begin_comment
comment|/*  * The following definitions are architecture-dependent  */
end_comment

begin_define
define|#
directive|define
name|PPS_CAP
value|(PPS_CAPTUREASSERT | PPS_OFFSETASSERT | PPS_TSFMT_TSPEC | PPS_TSFMT_NTPFP)
end_define

begin_define
define|#
directive|define
name|PPS_RO
value|(PPS_CANWAIT | PPS_CANPOLL | PPS_TSFMT_TSPEC | PPS_TSFMT_NTPFP)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|filedes
decl_stmt|;
comment|/* file descriptor */
name|pps_params_t
name|params
decl_stmt|;
comment|/* PPS parameters set by user */
name|struct
name|timeval
name|tv_save
decl_stmt|;
name|pps_seq_t
name|serial
decl_stmt|;
block|}
name|pps_unit_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|pps_unit_t
modifier|*
name|pps_handle_t
typedef|;
end_typedef

begin_comment
comment|/* pps handlebars */
end_comment

begin_comment
comment|/*  *------ Here begins the implementation-specific part! ------  */
end_comment

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_comment
comment|/*  * create PPS handle from file descriptor  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|time_pps_create
parameter_list|(
name|int
name|filedes
parameter_list|,
comment|/* file descriptor */
name|pps_handle_t
modifier|*
name|handle
comment|/* returned handle */
parameter_list|)
block|{
name|int
name|one
init|=
literal|1
decl_stmt|;
comment|/* 	 * Check for valid arguments and attach PPS signal. 	 */
if|if
condition|(
operator|!
name|handle
condition|)
block|{
name|errno
operator|=
name|EFAULT
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* null pointer */
block|}
comment|/* 	 * Allocate and initialize default unit structure. 	 */
operator|*
name|handle
operator|=
name|malloc
argument_list|(
sizeof|sizeof
argument_list|(
name|pps_unit_t
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
operator|*
name|handle
operator|)
condition|)
block|{
name|errno
operator|=
name|EBADF
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* what, no memory? */
block|}
name|memset
argument_list|(
operator|*
name|handle
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|pps_unit_t
argument_list|)
argument_list|)
expr_stmt|;
operator|(
operator|*
name|handle
operator|)
operator|->
name|filedes
operator|=
name|filedes
expr_stmt|;
operator|(
operator|*
name|handle
operator|)
operator|->
name|params
operator|.
name|api_version
operator|=
name|PPS_API_VERS_1
expr_stmt|;
operator|(
operator|*
name|handle
operator|)
operator|->
name|params
operator|.
name|mode
operator|=
name|PPS_CAPTUREASSERT
operator||
name|PPS_TSFMT_TSPEC
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * release PPS handle  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|time_pps_destroy
parameter_list|(
name|pps_handle_t
name|handle
parameter_list|)
block|{
comment|/* 	 * Check for valid arguments and detach PPS signal. 	 */
if|if
condition|(
operator|!
name|handle
condition|)
block|{
name|errno
operator|=
name|EBADF
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* bad handle */
block|}
name|free
argument_list|(
name|handle
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * set parameters for handle  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|time_pps_setparams
parameter_list|(
name|pps_handle_t
name|handle
parameter_list|,
specifier|const
name|pps_params_t
modifier|*
name|params
parameter_list|)
block|{
name|int
name|mode
decl_stmt|,
name|mode_in
decl_stmt|;
comment|/* 	 * Check for valid arguments and set parameters. 	 */
if|if
condition|(
operator|!
name|handle
condition|)
block|{
name|errno
operator|=
name|EBADF
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* bad handle */
block|}
if|if
condition|(
operator|!
name|params
condition|)
block|{
name|errno
operator|=
name|EFAULT
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* bad argument */
block|}
comment|/* 	 * There was no reasonable consensu in the API working group. 	 * I require `api_version' to be set! 	 */
if|if
condition|(
name|params
operator|->
name|api_version
operator|!=
name|PPS_API_VERS_1
condition|)
block|{
name|errno
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/* 	 * only settable modes are PPS_CAPTUREASSERT and PPS_OFFSETASSERT 	 */
name|mode_in
operator|=
name|params
operator|->
name|mode
expr_stmt|;
comment|/* turn off read-only bits */
name|mode_in
operator|&=
operator|~
name|PPS_RO
expr_stmt|;
comment|/* test remaining bits, should only have captureassert and/or offsetassert */
if|if
condition|(
name|mode_in
operator|&
operator|~
operator|(
name|PPS_CAPTUREASSERT
operator||
name|PPS_OFFSETASSERT
operator|)
condition|)
block|{
name|errno
operator|=
name|EOPNOTSUPP
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/* 	 * ok, ready to go. 	 */
name|mode
operator|=
name|handle
operator|->
name|params
operator|.
name|mode
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|handle
operator|->
name|params
argument_list|,
name|params
argument_list|,
sizeof|sizeof
argument_list|(
name|pps_params_t
argument_list|)
argument_list|)
expr_stmt|;
name|handle
operator|->
name|params
operator|.
name|api_version
operator|=
name|PPS_API_VERS_1
expr_stmt|;
name|handle
operator|->
name|params
operator|.
name|mode
operator|=
name|mode
operator||
name|mode_in
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * get parameters for handle  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|time_pps_getparams
parameter_list|(
name|pps_handle_t
name|handle
parameter_list|,
name|pps_params_t
modifier|*
name|params
parameter_list|)
block|{
comment|/* 	 * Check for valid arguments and get parameters. 	 */
if|if
condition|(
operator|!
name|handle
condition|)
block|{
name|errno
operator|=
name|EBADF
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* bad handle */
block|}
if|if
condition|(
operator|!
name|params
condition|)
block|{
name|errno
operator|=
name|EFAULT
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* bad argument */
block|}
name|memcpy
argument_list|(
name|params
argument_list|,
operator|&
name|handle
operator|->
name|params
argument_list|,
sizeof|sizeof
argument_list|(
name|pps_params_t
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/* (  * get capabilities for handle  */
end_comment

begin_function
specifier|static
specifier|inline
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
comment|/* 	 * Check for valid arguments and get capabilities. 	 */
if|if
condition|(
operator|!
name|handle
condition|)
block|{
name|errno
operator|=
name|EBADF
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* bad handle */
block|}
if|if
condition|(
operator|!
name|mode
condition|)
block|{
name|errno
operator|=
name|EFAULT
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* bad argument */
block|}
operator|*
name|mode
operator|=
name|PPS_CAP
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Fetch timestamps  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|time_pps_fetch
parameter_list|(
name|pps_handle_t
name|handle
parameter_list|,
specifier|const
name|int
name|tsformat
parameter_list|,
name|pps_info_t
modifier|*
name|ppsinfo
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
name|timeout
parameter_list|)
block|{
name|struct
name|timeval
name|tv
decl_stmt|;
name|pps_info_t
name|infobuf
decl_stmt|;
comment|/* 	 * Check for valid arguments and fetch timestamps 	 */
if|if
condition|(
operator|!
name|handle
condition|)
block|{
name|errno
operator|=
name|EBADF
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* bad handle */
block|}
if|if
condition|(
operator|!
name|ppsinfo
condition|)
block|{
name|errno
operator|=
name|EFAULT
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* bad argument */
block|}
comment|/* 	 * nb. PPS_CANWAIT is NOT set by the implementation, we can totally 	 * ignore the timeout variable. 	 */
name|memset
argument_list|(
operator|&
name|infobuf
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
name|infobuf
argument_list|)
argument_list|)
expr_stmt|;
comment|/* 	 * if not captureassert, nothing to return. 	 */
if|if
condition|(
operator|!
name|handle
operator|->
name|params
operator|.
name|mode
operator|&
name|PPS_CAPTUREASSERT
condition|)
block|{
name|memcpy
argument_list|(
name|ppsinfo
argument_list|,
operator|&
name|infobuf
argument_list|,
sizeof|sizeof
argument_list|(
name|pps_info_t
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
if|if
condition|(
name|ioctl
argument_list|(
name|instance
operator|->
name|filedes
argument_list|,
name|TIOCDCDTIMESTAMP
argument_list|,
operator|&
name|tv
argument_list|)
operator|<
literal|0
condition|)
block|{
name|perror
argument_list|(
literal|"time_pps_fetch:"
argument_list|)
expr_stmt|;
name|errno
operator|=
name|EOPNOTSUPP
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
comment|/* 	 * fake serial here 	 */
if|if
condition|(
name|tv
operator|.
name|tv_sec
operator|!=
name|handle
operator|->
name|tv_save
operator|.
name|tv_sec
operator|||
name|tv
operator|.
name|tv_usec
operator|!=
name|handle
operator|->
name|tv_save
operator|.
name|tv_usec
condition|)
block|{
name|handle
operator|->
name|tv_save
operator|=
name|tv
expr_stmt|;
name|handle
operator|->
name|serial
operator|++
expr_stmt|;
block|}
comment|/* 	 * Apply offsets as specified. Note that only assert timestamps 	 * are captured by this interface. 	 */
name|infobuf
operator|.
name|assert_sequence
operator|=
name|handle
operator|->
name|serial
expr_stmt|;
name|infobuf
operator|.
name|assert_timestamp
operator|.
name|tv_sec
operator|=
name|tv
operator|.
name|tv_sec
expr_stmt|;
name|infobuf
operator|.
name|assert_timestamp
operator|.
name|tv_nsec
operator|=
name|tv
operator|.
name|tv_usec
operator|*
literal|1000
expr_stmt|;
if|if
condition|(
name|handle
operator|->
name|params
operator|.
name|mode
operator|&
name|PPS_OFFSETASSERT
condition|)
block|{
name|infobuf
operator|.
name|assert_timestamp
operator|.
name|tv_sec
operator|+=
name|handle
operator|->
name|params
operator|.
name|assert_offset
operator|.
name|tv_sec
expr_stmt|;
name|infobuf
operator|.
name|assert_timestamp
operator|.
name|tv_nsec
operator|+=
name|handle
operator|->
name|params
operator|.
name|assert_offset
operator|.
name|tv_nsec
expr_stmt|;
name|PPS_NORMALIZE
argument_list|(
name|infobuf
operator|.
name|assert_timestamp
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Translate to specified format 	 */
switch|switch
condition|(
name|tsformat
condition|)
block|{
case|case
name|PPS_TSFMT_TSPEC
case|:
break|break;
comment|/* timespec format requires no translation */
case|case
name|PPS_TSFMT_NTPFP
case|:
comment|/* NTP format requires conversion to fraction form */
name|PPS_TSPECTONTP
argument_list|(
name|infobuf
operator|.
name|assert_timestamp_ntpfp
argument_list|)
expr_stmt|;
break|break;
default|default:
name|errno
operator|=
name|EINVAL
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|infobuf
operator|.
name|current_mode
operator|=
name|handle
operator|->
name|params
operator|.
name|mode
expr_stmt|;
name|memcpy
argument_list|(
name|ppsinfo
argument_list|,
operator|&
name|infobuf
argument_list|,
sizeof|sizeof
argument_list|(
name|pps_info_t
argument_list|)
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * specify kernel consumer  */
end_comment

begin_function
specifier|static
specifier|inline
name|int
name|time_pps_kcbind
parameter_list|(
name|pps_handle_t
name|handle
parameter_list|,
specifier|const
name|int
name|kernel_consumer
parameter_list|,
specifier|const
name|int
name|edge
parameter_list|,
specifier|const
name|int
name|tsformat
parameter_list|)
block|{
comment|/* 	 * Check for valid arguments and bind kernel consumer 	 */
if|if
condition|(
operator|!
name|handle
condition|)
block|{
name|errno
operator|=
name|EBADF
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* bad handle */
block|}
if|if
condition|(
name|geteuid
argument_list|()
operator|!=
literal|0
condition|)
block|{
name|errno
operator|=
name|EPERM
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
comment|/* must be superuser */
block|}
name|errno
operator|=
name|EOPNOTSUPP
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SYS_TIMEPPS_H_ */
end_comment

end_unit

