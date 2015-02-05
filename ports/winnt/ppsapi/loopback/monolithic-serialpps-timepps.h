begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************************************************************  *								       *  * Copyright (c) David L. Mills 1999-2000			       *  *								       *  * Permission to use, copy, modify, and distribute this software and   *  * its documentation for any purpose and with or without fee is hereby *  * granted, provided that the above copyright notice appears in all    *  * copies and that both the copyright notice and this permission       *  * notice appear in supporting documentation, and that the name        *  * University of Delaware not be used in advertising or publicity      *  * pertaining to distribution of the software without specific,        *  * written prior permission. The University of Delaware makes no       *  * representations about the suitability this software for any	       *  * purpose. It is provided "as is" without express or implied          *  * warranty.							       *  *								       *  ***********************************************************************  *								       *  * This header file complies with "Pulse-Per-Second API for UNIX-like  *  * Operating Systems, Version 1.0", rfc2783. Credit is due Jeff Mogul  *  * and Marc Brett, from whom much of this code was shamelessly stolen. *  *								       *  * This modified timepps.h can be used to provide a PPSAPI interface   *  * to a machine running Windows with a suitably modified 	       *  * serialpps.sys being used in place of serial.sys.  It can	       *  * be extended to support a modified parallel port driver once	       *  * available.							       *  *								       *  * This Windows version was derived by Dave Hart		       *  *<davehart@davehart.com> from Mills' timepps-Solaris.h	       *  *								       *  ***********************************************************************  *								       *  * Some of this include file					       *  * Copyright (c) 1999 by Ulrich Windl,				       *  *	based on code by Reg Clemens<reg@dwf.com>		       *  *		based on code by Poul-Henning Kamp<phk@FreeBSD.org>   *  *								       *  ***********************************************************************  *								       *  * "THE BEER-WARE LICENSE" (Revision 42):                              *  *<phk@FreeBSD.org> wrote this file.  As long as you retain this      *  * notice you can do whatever you want with this stuff. If we meet some*  * day, and you think this stuff is worth it, you can buy me a beer    *  * in return.	Poul-Henning Kamp				       *  *								       *  **********************************************************************/
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
name|PPS_HECTONANOSECONDS
value|10000000
end_define

begin_comment
comment|/* 100ns units in a second */
end_comment

begin_define
define|#
directive|define
name|PPS_FILETIME_1970
value|0x019db1ded53e8000
end_define

begin_comment
comment|/* unix epoch to Windows */
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
comment|/* convert timespec to ntp_fp */
define|\
value|do { \ 		double d_temp; \ 	\ 		(x).integral += (unsigned int)PPS_JAN_1970; \ 		d_temp = (x).fractional * PPS_FRAC / PPS_NANOSECOND; \ 		if (d_temp>= PPS_FRAC) \ 			(x).integral++; \ 		(x).fractional = (unsigned int)d_temp; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|PPS_NTPTOTSPEC
parameter_list|(
name|x
parameter_list|)
comment|/* convert ntp_fp to timespec */
define|\
value|do { \ 		double d_temp; \ 	\ 		(x).tv_sec -= (time_t)PPS_JAN_1970; \ 		d_temp = (double)((x).tv_nsec); \ 		d_temp *= PPS_NANOSECOND; \ 		d_temp /= PPS_FRAC; \ 		(x).tv_nsec = (long)d_temp; \ 	} while (0)
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
comment|/*  * Kernel discipline actions (not used in Windows yet)  */
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

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|push
name|)
end_pragma

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|disable
name|:
name|201
name|)
end_pragma

begin_comment
comment|/* nonstd extension nameless union */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|ntp_fp
block|{
union|union
name|ntp_fp_sec
block|{
name|unsigned
name|int
name|integral
decl_stmt|;
name|int
name|s_integral
decl_stmt|;
block|}
union|;
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

begin_pragma
pragma|#
directive|pragma
name|warning
name|(
name|pop
name|)
end_pragma

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
comment|/* addition of NTP fixed-point format */
end_comment

begin_define
define|#
directive|define
name|NTPFP_M_ADD
parameter_list|(
name|r_i
parameter_list|,
name|r_f
parameter_list|,
name|a_i
parameter_list|,
name|a_f
parameter_list|)
comment|/* r += a */
define|\
value|do { \ 		register u_int32 lo_tmp; \ 		register u_int32 hi_tmp; \ 		\ 		lo_tmp = ((r_f)& 0xffff) + ((a_f)& 0xffff); \ 		hi_tmp = (((r_f)>> 16)& 0xffff) + (((a_f)>> 16)& 0xffff); \ 		if (lo_tmp& 0x10000) \ 			hi_tmp++; \ 		(r_f) = ((hi_tmp& 0xffff)<< 16) | (lo_tmp& 0xffff); \ 		\ 		(r_i) += (a_i); \ 		if (hi_tmp& 0x10000) \ 			(r_i)++; \ 	} while (0)
end_define

begin_define
define|#
directive|define
name|NTPFP_L_ADDS
parameter_list|(
name|r
parameter_list|,
name|a
parameter_list|)
value|NTPFP_M_ADD((r)->integral, (r)->fractional, \ 					    (a)->s_integral, (a)->fractional)
end_define

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
value|(PPS_CANWAIT | PPS_CANPOLL)
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|filedes
decl_stmt|;
comment|/* file descriptor */
name|OVERLAPPED
name|ol
decl_stmt|;
comment|/* caches ol.hEvent for DeviceIoControl */
name|pps_params_t
name|params
decl_stmt|;
comment|/* PPS parameters set by user */
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
file|<windows.h>
end_include

begin_include
include|#
directive|include
file|<errno.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|EOPNOTSUPP
end_ifndef

begin_define
define|#
directive|define
name|EOPNOTSUPP
value|45
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_typedef
typedef|typedef
struct|struct
name|_OLD_SERIAL_PPS_STAMPS
block|{
name|LARGE_INTEGER
name|Timestamp
decl_stmt|;
name|LARGE_INTEGER
name|Counterstamp
decl_stmt|;
block|}
name|OLD_SERIAL_PPS_STAMPS
operator|,
typedef|*
name|POLDSERIAL_PPS_STAMPS
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_SERIAL_PPS_STAMPS
block|{
name|LARGE_INTEGER
name|Timestamp
decl_stmt|;
name|LARGE_INTEGER
name|Counterstamp
decl_stmt|;
name|DWORD
name|SeqNum
decl_stmt|;
block|}
name|SERIAL_PPS_STAMPS
operator|,
typedef|*
name|PSERIAL_PPS_STAMPS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IOCTL_SERIAL_GET_PPS_STAMPS
value|CTL_CODE(FILE_DEVICE_SERIAL_PORT,114,METHOD_BUFFERED,FILE_ANY_ACCESS)
end_define

begin_comment
comment|/* byte offset of member m in struct typedef s */
end_comment

begin_define
define|#
directive|define
name|PPS_OFFSETOF
parameter_list|(
name|m
parameter_list|,
name|s
parameter_list|)
value|(size_t)(&((s *)0)->m)
end_define

begin_comment
comment|/*  * ntpd on Windows only looks to errno after finding  * GetLastError returns NO_ERROR.  To accomodate its  * use of msyslog in portable code such as refclock_atom.c,  * this implementation always clears the Windows  * error code using SetLastError(NO_ERROR) when  * returning an errno.  This is also a good idea  * for any non-ntpd clients as they should use only  * the errno for PPSAPI functions.  */
end_comment

begin_define
define|#
directive|define
name|RETURN_PPS_ERRNO
parameter_list|(
name|e
parameter_list|)
define|\
value|do {	\ 	SetLastError(NO_ERROR);	\ 	errno = (e);	\ 	return -1;	\ } while (0)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|OWN_PPS_NTP_TIMESTAMP_FROM_COUNTER
end_ifdef

begin_function_decl
specifier|extern
name|void
name|pps_ntp_timestamp_from_counter
parameter_list|(
name|ntp_fp_t
modifier|*
parameter_list|,
name|ULONGLONG
parameter_list|,
name|ULONGLONG
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_comment
comment|/*  * helper routine for serialpps.sys ioctl which returns   * performance counter "timestamp" as well as a system  * FILETIME timestamp.  Converts one of the inputs to  * NTP fixed-point format.  */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|pps_ntp_timestamp_from_counter
parameter_list|(
name|ntp_fp_t
modifier|*
name|result
parameter_list|,
name|ULONGLONG
name|Timestamp
parameter_list|,
name|ULONGLONG
name|Counterstamp
parameter_list|)
block|{
name|ULONGLONG
name|BiasedTimestamp
decl_stmt|;
comment|/* convert from 100ns units to NTP fixed point format */
name|BiasedTimestamp
operator|=
name|Timestamp
operator|-
name|PPS_FILETIME_1970
expr_stmt|;
name|result
operator|->
name|integral
operator|=
name|PPS_JAN_1970
operator|+
call|(
name|unsigned
call|)
argument_list|(
name|BiasedTimestamp
operator|/
name|PPS_HECTONANOSECONDS
argument_list|)
expr_stmt|;
name|result
operator|->
name|fractional
operator|=
call|(
name|unsigned
call|)
argument_list|(
operator|(
name|BiasedTimestamp
operator|%
name|PPS_HECTONANOSECONDS
operator|)
operator|*
operator|(
name|PPS_FRAC
operator|/
name|PPS_HECTONANOSECONDS
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

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
name|OLD_SERIAL_PPS_STAMPS
name|old_pps_stamps
decl_stmt|;
name|DWORD
name|bytes
decl_stmt|;
name|OVERLAPPED
name|ol
decl_stmt|;
comment|/* 	 * Check for valid arguments and attach PPS signal. 	 */
if|if
condition|(
operator|!
name|handle
condition|)
name|RETURN_PPS_ERRNO
argument_list|(
name|EFAULT
argument_list|)
expr_stmt|;
if|if
condition|(
name|PPS_OFFSETOF
argument_list|(
name|tspec
operator|.
name|tv_nsec
argument_list|,
name|pps_timeu_t
argument_list|)
operator|!=
name|PPS_OFFSETOF
argument_list|(
name|ntpfp
operator|.
name|fractional
argument_list|,
name|pps_timeu_t
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"timepps.h needs work, union of \n"
literal|"unsigned int ntp_fp.integral and\n"
literal|"time_t timespec.tv_sec accessed\n"
literal|"interchangeably.\n"
argument_list|)
expr_stmt|;
name|RETURN_PPS_ERRNO
argument_list|(
name|EFAULT
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * For this ioctl which will never block, we don't want to go 	 * through the overhead of a completion port, so we use an 	 * event handle in the overlapped structure with its 1 bit set. 	 * 	 * From GetQueuedCompletionStatus docs: 	 * Even if you have passed the function a file handle associated  	 * with a completion port and a valid OVERLAPPED structure, an  	 * application can prevent completion port notification. This is  	 * done by specifying a valid event handle for the hEvent member  	 * of the OVERLAPPED structure, and setting its low-order bit. A  	 * valid event handle whose low-order bit is set keeps I/O  	 * completion from being queued to the completion port. 	 */
name|ol
operator|.
name|hEvent
operator|=
name|CreateEvent
argument_list|(
name|NULL
argument_list|,
name|TRUE
argument_list|,
name|FALSE
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
name|ol
operator|.
name|hEvent
operator|=
call|(
name|HANDLE
call|)
argument_list|(
operator|(
name|ULONG_PTR
operator|)
name|ol
operator|.
name|hEvent
operator||
literal|1
argument_list|)
expr_stmt|;
if|if
condition|(
name|FALSE
operator|==
name|DeviceIoControl
argument_list|(
operator|(
name|HANDLE
operator|)
name|_get_osfhandle
argument_list|(
name|filedes
argument_list|)
argument_list|,
name|IOCTL_SERIAL_GET_PPS_STAMPS
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
operator|&
name|old_pps_stamps
argument_list|,
sizeof|sizeof
argument_list|(
name|old_pps_stamps
argument_list|)
argument_list|,
operator|&
name|bytes
argument_list|,
operator|&
name|ol
argument_list|)
operator|||
sizeof|sizeof
argument_list|(
name|old_pps_stamps
argument_list|)
operator|!=
name|bytes
condition|)
block|{
comment|/*  		 * If you want to write some dead code this could detect the  		 * IOCTL being pended, but the driver always has the info 		 * instantly, so ERROR_IO_PENDING isn't a concern. 		 */
name|CloseHandle
argument_list|(
name|ol
operator|.
name|hEvent
argument_list|)
expr_stmt|;
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"time_pps_create: IOCTL_SERIAL_GET_PPS_STAMPS: %d %d\n"
argument_list|,
name|bytes
argument_list|,
name|GetLastError
argument_list|()
argument_list|)
expr_stmt|;
name|RETURN_PPS_ERRNO
argument_list|(
name|ENXIO
argument_list|)
expr_stmt|;
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
name|RETURN_PPS_ERRNO
argument_list|(
name|ENOMEM
argument_list|)
expr_stmt|;
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
name|ol
operator|.
name|hEvent
operator|=
name|ol
operator|.
name|hEvent
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
name|RETURN_PPS_ERRNO
argument_list|(
name|EBADF
argument_list|)
expr_stmt|;
name|CloseHandle
argument_list|(
name|handle
operator|->
name|ol
operator|.
name|hEvent
argument_list|)
expr_stmt|;
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
name|RETURN_PPS_ERRNO
argument_list|(
name|EBADF
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|params
condition|)
name|RETURN_PPS_ERRNO
argument_list|(
name|EFAULT
argument_list|)
expr_stmt|;
comment|/* 	 * There was no reasonable consensu in the API working group. 	 * I require `api_version' to be set! 	 */
if|if
condition|(
name|params
operator|->
name|api_version
operator|!=
name|PPS_API_VERS_1
condition|)
name|RETURN_PPS_ERRNO
argument_list|(
name|EINVAL
argument_list|)
expr_stmt|;
comment|/* 	 * only settable modes are PPS_CAPTUREASSERT and PPS_OFFSETASSERT 	 */
name|mode_in
operator|=
name|params
operator|->
name|mode
expr_stmt|;
comment|/* 	 * Only one of the time formats may be selected 	 * if a nonzero assert offset is supplied. 	 */
if|if
condition|(
operator|(
name|mode_in
operator|&
operator|(
name|PPS_TSFMT_TSPEC
operator||
name|PPS_TSFMT_NTPFP
operator|)
operator|)
operator|==
operator|(
name|PPS_TSFMT_TSPEC
operator||
name|PPS_TSFMT_NTPFP
operator|)
condition|)
block|{
if|if
condition|(
name|handle
operator|->
name|params
operator|.
name|assert_offset
operator|.
name|tv_sec
operator|||
name|handle
operator|->
name|params
operator|.
name|assert_offset
operator|.
name|tv_nsec
condition|)
name|RETURN_PPS_ERRNO
argument_list|(
name|EINVAL
argument_list|)
expr_stmt|;
comment|/* 		 * If no offset was specified but both time 		 * format flags are used consider it harmless 		 * but turn off PPS_TSFMT_NTPFP so getparams 		 * will not show both formats lit. 		 */
name|mode_in
operator|&=
operator|~
name|PPS_TSFMT_NTPFP
expr_stmt|;
block|}
comment|/* turn off read-only bits */
name|mode_in
operator|&=
operator|~
name|PPS_RO
expr_stmt|;
comment|/* 	 * test remaining bits, should only have captureassert,  	 * offsetassert, and/or timestamp format bits. 	 */
if|if
condition|(
name|mode_in
operator|&
operator|~
operator|(
name|PPS_CAPTUREASSERT
operator||
name|PPS_OFFSETASSERT
operator||
name|PPS_TSFMT_TSPEC
operator||
name|PPS_TSFMT_NTPFP
operator|)
condition|)
name|RETURN_PPS_ERRNO
argument_list|(
name|EOPNOTSUPP
argument_list|)
expr_stmt|;
comment|/* 	 * ok, ready to go. 	 */
name|mode
operator|=
name|handle
operator|->
name|params
operator|.
name|mode
expr_stmt|;
name|handle
operator|->
name|params
operator|=
operator|*
name|params
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
name|handle
operator|->
name|params
operator|.
name|api_version
operator|=
name|PPS_API_VERS_1
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
name|RETURN_PPS_ERRNO
argument_list|(
name|EBADF
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|params
condition|)
name|RETURN_PPS_ERRNO
argument_list|(
name|EFAULT
argument_list|)
expr_stmt|;
operator|*
name|params
operator|=
name|handle
operator|->
name|params
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
name|RETURN_PPS_ERRNO
argument_list|(
name|EBADF
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|mode
condition|)
name|RETURN_PPS_ERRNO
argument_list|(
name|EFAULT
argument_list|)
expr_stmt|;
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
name|SERIAL_PPS_STAMPS
name|pps_stamps
decl_stmt|;
name|pps_info_t
name|infobuf
decl_stmt|;
name|BOOL
name|rc
decl_stmt|;
name|DWORD
name|bytes
decl_stmt|;
name|DWORD
name|lasterr
decl_stmt|;
comment|/* 	 * Check for valid arguments and fetch timestamps 	 */
if|if
condition|(
operator|!
name|handle
condition|)
name|RETURN_PPS_ERRNO
argument_list|(
name|EBADF
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|ppsinfo
condition|)
name|RETURN_PPS_ERRNO
argument_list|(
name|EFAULT
argument_list|)
expr_stmt|;
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
operator|*
name|ppsinfo
operator|=
name|infobuf
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
comment|/* 	 * First rev of serialpps.sys didn't support the SeqNum field, 	 * support it by simply returning constant 0 for serial in that case. 	 */
name|pps_stamps
operator|.
name|SeqNum
operator|=
literal|0
expr_stmt|;
comment|/* 	 * interrogate (hopefully) serialpps.sys 	 * if it's the standard serial.sys or another driver, 	 * IOCTL_SERIAL_GET_PPS_STAMPS is most likely unknown 	 * and will result in ERROR_INVALID_PARAMETER. 	 */
name|bytes
operator|=
literal|0
expr_stmt|;
name|rc
operator|=
name|DeviceIoControl
argument_list|(
operator|(
name|HANDLE
operator|)
name|_get_osfhandle
argument_list|(
name|handle
operator|->
name|filedes
argument_list|)
argument_list|,
name|IOCTL_SERIAL_GET_PPS_STAMPS
argument_list|,
name|NULL
argument_list|,
literal|0
argument_list|,
operator|&
name|pps_stamps
argument_list|,
sizeof|sizeof
argument_list|(
name|pps_stamps
argument_list|)
argument_list|,
operator|&
name|bytes
argument_list|,
operator|&
name|handle
operator|->
name|ol
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|rc
condition|)
block|{
name|lasterr
operator|=
name|GetLastError
argument_list|()
expr_stmt|;
if|if
condition|(
name|ERROR_INVALID_PARAMETER
operator|!=
name|lasterr
condition|)
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"time_pps_fetch: ioctl err %d\n"
argument_list|,
name|lasterr
argument_list|)
expr_stmt|;
name|RETURN_PPS_ERRNO
argument_list|(
name|EOPNOTSUPP
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|bytes
operator|!=
sizeof|sizeof
argument_list|(
name|pps_stamps
argument_list|)
operator|&&
name|bytes
operator|!=
sizeof|sizeof
argument_list|(
name|OLD_SERIAL_PPS_STAMPS
argument_list|)
condition|)
block|{
name|fprintf
argument_list|(
name|stderr
argument_list|,
literal|"time_pps_fetch: wanted %d or %d bytes got %d from "
literal|"IOCTL_SERIAL_GET_PPS_STAMPS 0x%x\n"
argument_list|,
sizeof|sizeof
argument_list|(
name|OLD_SERIAL_PPS_STAMPS
argument_list|)
argument_list|,
sizeof|sizeof
argument_list|(
name|SERIAL_PPS_STAMPS
argument_list|)
argument_list|,
name|bytes
argument_list|,
name|IOCTL_SERIAL_GET_PPS_STAMPS
argument_list|)
expr_stmt|;
name|RETURN_PPS_ERRNO
argument_list|(
name|ENXIO
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * pps_ntp_timestamp_from_counter takes the two flavors 	 * of timestamp we have (counter and system time) and 	 * uses whichever it can to give the best NTP fixed-point 	 * conversion.  In ntpd the Counterstamp is typically 	 * used.  A stub implementation in this file simply 	 * converts from Windows Timestamp to NTP fixed-point. 	 */
name|pps_ntp_timestamp_from_counter
argument_list|(
operator|&
name|infobuf
operator|.
name|assert_timestamp_ntpfp
argument_list|,
name|pps_stamps
operator|.
name|Timestamp
operator|.
name|QuadPart
argument_list|,
name|pps_stamps
operator|.
name|Counterstamp
operator|.
name|QuadPart
argument_list|)
expr_stmt|;
comment|/* 	 * Note that only assert timestamps 	 * are captured by this interface. 	 */
name|infobuf
operator|.
name|assert_sequence
operator|=
name|pps_stamps
operator|.
name|SeqNum
expr_stmt|;
comment|/* 	 * Apply offset and translate to specified format 	 */
switch|switch
condition|(
name|tsformat
condition|)
block|{
case|case
name|PPS_TSFMT_NTPFP
case|:
comment|/* NTP format requires no translation */
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
name|NTPFP_L_ADDS
argument_list|(
operator|&
name|infobuf
operator|.
name|assert_timestamp_ntpfp
argument_list|,
operator|&
name|handle
operator|->
name|params
operator|.
name|assert_offset_ntpfp
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|PPS_TSFMT_TSPEC
case|:
comment|/* timespec format requires conversion to nsecs form */
name|PPS_NTPTOTSPEC
argument_list|(
name|infobuf
operator|.
name|assert_timestamp
argument_list|)
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
break|break;
default|default:
name|RETURN_PPS_ERRNO
argument_list|(
name|EINVAL
argument_list|)
expr_stmt|;
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
operator|*
name|ppsinfo
operator|=
name|infobuf
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * time_pps_kcbind - specify kernel consumer  *  * Not supported so far by Windows.  */
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
comment|/* 	 * Check for valid arguments before revealing the ugly truth 	 */
if|if
condition|(
operator|!
name|handle
condition|)
name|RETURN_PPS_ERRNO
argument_list|(
name|EBADF
argument_list|)
expr_stmt|;
name|RETURN_PPS_ERRNO
argument_list|(
name|EOPNOTSUPP
argument_list|)
expr_stmt|;
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

