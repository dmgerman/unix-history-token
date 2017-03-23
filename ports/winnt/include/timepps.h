begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/***********************************************************************  *								       *  * Copyright (c) David L. Mills 1999-2009			       *  *								       *  * Permission to use, copy, modify, and distribute this software and   *  * its documentation for any purpose and with or without fee is hereby *  * granted, provided that the above copyright notice appears in all    *  * copies and that both the copyright notice and this permission       *  * notice appear in supporting documentation, and that the name        *  * University of Delaware not be used in advertising or publicity      *  * pertaining to distribution of the software without specific,        *  * written prior permission. The University of Delaware makes no       *  * representations about the suitability this software for any	       *  * purpose. It is provided "as is" without express or implied          *  * warranty.							       *  *								       *  ***********************************************************************  *								       *  * This header file complies with "Pulse-Per-Second API for UNIX-like  *  * Operating Systems, Version 1.0", rfc2783. Credit is due Jeff Mogul  *  * and Marc Brett, from whom much of this code was shamelessly stolen. *  *								       *  * This modified timepps.h can be used to provide a PPSAPI interface   *  * to a machine running Windows with one or more backend provider DLLs *  * implementing the provider interfaces defined herein.		       *  *								       *  * This Windows version was derived by Dave Hart		       *  *<davehart@davehart.com> from Mills' timepps-Solaris.h	       *  *								       *  ***********************************************************************  *								       *  * Some of this include file					       *  * Copyright (c) 1999 by Ulrich Windl,				       *  *	based on code by Reg Clemens<reg@dwf.com>		       *  *		based on code by Poul-Henning Kamp<phk@FreeBSD.org>   *  *								       *  ***********************************************************************  *								       *  * "THE BEER-WARE LICENSE" (Revision 42):			       *  *<phk@FreeBSD.org> wrote this file.  As long as you retain this      *  * notice you can do whatever you want with this stuff. If we meet some*  * day, and you think this stuff is worth it, you can buy me a beer    *  * in return.	Poul-Henning Kamp				       *  *								       *  **********************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TIMEPPS_H
end_ifndef

begin_define
define|#
directive|define
name|TIMEPPS_H
end_define

begin_include
include|#
directive|include
file|"sys/time.h"
end_include

begin_comment
comment|/* in ntp ref source declares struct timespec */
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
value|do {								\ 		double d_frac;						\ 									\ 		d_frac = ((struct timespec)&(x))->tv_nsec		\ 			 * PPS_FRAC / PPS_NANOSECOND;			\ 		(x).integral = ((struct timespec)&(x))->tv_sec		\ 				+ PPS_JAN_1970;				\ 		(x).fractional = (unsigned int)d_frac;			\ 		if (d_frac>= PPS_FRAC)					\ 			(x).integral++;					\ 	} while (0)
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
value|do {								\ 		double d_frac;						\ 									\
comment|/* careful, doing in place and tv_sec may be 64bit */
value|\ 		d_frac = (double)((ntp_fp_t *)&(x))->fractional		\ 			* PPS_NANOSECOND / PPS_FRAC;			\ 		(x).tv_sec = ((ntp_fp_t *)&(x))->integral		\ 			     - (time_t)PPS_JAN_1970;			\ 		(x).tv_nsec = (long)d_frac;				\ 	} while (0)
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

begin_define
define|#
directive|define
name|PPS_TSFMT_BOTH
value|(PPS_TSFMT_TSPEC | PPS_TSFMT_NTPFP)
end_define

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
name|UINT_PTR
name|pps_handle_t
typedef|;
end_typedef

begin_comment
comment|/* pps handlebars */
end_comment

begin_comment
comment|/*  * ntpd on Windows is typically distributed as a binary as few users  * have the tools needed to build from source.  Rather than build  * a single timepps.h for Windows which knows how to talk to all  * PPS implementations frozen in time as of compiling, this timepps.h  * allows one or more backend providers to be used by naming a DLL  * which exports the provider interfaces defined here.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
name|ppsapi_magic_tag
block|{
name|PPSAPI_MAGIC_UNIT
init|=
literal|0x70707355
block|,
comment|/* ppsU */
block|}
name|ppsapi_magic
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|pps_provider_tag
modifier|*
name|provider
decl_stmt|;
name|void
modifier|*
name|context
decl_stmt|;
comment|/* provider's unit pointer */
name|ppsapi_magic
name|magic
decl_stmt|;
comment|/* to detect invalid handles */
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
name|void
function_decl|(
modifier|*
name|ppps_ntp_timestamp_from_counter
function_decl|)
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
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|pps_handle_t
function_decl|(
modifier|*
name|pcreate_pps_handle
function_decl|)
parameter_list|(
name|void
modifier|*
name|prov_context
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/*  * ppsapi_prov_init() - exported by backend DLLs  *  * Return value is pps capabilities available to PPSAPI consumers  * via time_pps_getcaps().  */
end_comment

begin_define
define|#
directive|define
name|PPSAPI_TIMEPPS_PROV_VER
value|2
end_define

begin_typedef
typedef|typedef
name|int
function_decl|(
name|WINAPI
modifier|*
name|pppsapi_prov_init
function_decl|)
parameter_list|(
name|int
name|ppsapi_timepps_prov_ver
parameter_list|,
name|pcreate_pps_handle
name|create_pps_handle
parameter_list|,
name|ppps_ntp_timestamp_from_counter
name|ntp_timestamp_from_counter
parameter_list|,
name|char
modifier|*
name|short_name_buf
parameter_list|,
name|size_t
name|short_name_size
parameter_list|,
name|char
modifier|*
name|full_name_buf
parameter_list|,
name|size_t
name|full_name_size
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|WINAPI
modifier|*
name|provtime_pps_create
function_decl|)
parameter_list|(
name|HANDLE
name|winhandle
parameter_list|,
comment|/* user device handle */
name|pps_handle_t
modifier|*
name|phandle
comment|/* returned handle */
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|WINAPI
modifier|*
name|provtime_pps_destroy
function_decl|)
parameter_list|(
name|pps_unit_t
modifier|*
name|unit
parameter_list|,
name|void
modifier|*
name|context
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|WINAPI
modifier|*
name|provtime_pps_setparams
function_decl|)
parameter_list|(
name|pps_unit_t
modifier|*
name|unit
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
specifier|const
name|pps_params_t
modifier|*
name|params
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|WINAPI
modifier|*
name|provtime_pps_fetch
function_decl|)
parameter_list|(
name|pps_unit_t
modifier|*
name|unit
parameter_list|,
name|void
modifier|*
name|context
parameter_list|,
specifier|const
name|int
name|tsformat
parameter_list|,
name|pps_info_t
modifier|*
name|pinfo
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
name|timeout
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
name|WINAPI
modifier|*
name|provtime_pps_kcbind
function_decl|)
parameter_list|(
name|pps_unit_t
modifier|*
name|unit
parameter_list|,
name|void
modifier|*
name|context
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
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|pps_provider_tag
block|{
name|struct
name|pps_provider_tag
modifier|*
name|next
decl_stmt|;
name|int
name|caps
decl_stmt|;
name|char
modifier|*
name|short_name
decl_stmt|;
name|char
modifier|*
name|full_name
decl_stmt|;
name|provtime_pps_create
name|ptime_pps_create
decl_stmt|;
name|provtime_pps_destroy
name|ptime_pps_destroy
decl_stmt|;
name|provtime_pps_setparams
name|ptime_pps_setparams
decl_stmt|;
name|provtime_pps_fetch
name|ptime_pps_fetch
decl_stmt|;
name|provtime_pps_kcbind
name|ptime_pps_kcbind
decl_stmt|;
block|}
name|ppsapi_provider
typedef|;
end_typedef

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
comment|/*  * helper routine for serialpps.sys ioctl which returns   * performance counter "timestamp" as well as a system  * FILETIME timestamp.  Converts one of the inputs to  * NTP fixed-point format.  *  * You will probably want to supply your own and #define  * OWN_PPS_NTP_TIMESTAMP_FROM_COUNTER, as this stub  * converts only the low-resolution system timestamp.  *  * When implementing a provider, use the pointer to this  * conversion function supplied to your prov_init(), as  * the copy in your DLL will likely be the stub below,  * where you want the one provided by the PPSAPI client  * such as ntpd.  */
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
comment|/*  * time_pps_create - create PPS handle from file descriptor  *  * This is the initial entrypoint of PPSAPI from the client.  Note  * to maintain source compatibility with Unix, the input file  * descriptor really is a descriptor from the C runtime low-numbered  * descriptor namespace, though it may have been converted from a  * native Windows HANDLE using _open_osfhandle().  */
end_comment

begin_function_decl
specifier|extern
name|int
name|time_pps_create
parameter_list|(
name|int
name|filedes
parameter_list|,
comment|/* device file descriptor */
name|pps_handle_t
modifier|*
name|phandle
comment|/* returned handle */
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * release PPS handle  */
end_comment

begin_function_decl
specifier|extern
name|int
name|time_pps_destroy
parameter_list|(
name|pps_handle_t
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * set parameters for handle  */
end_comment

begin_function_decl
specifier|extern
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
function_decl|;
end_function_decl

begin_comment
comment|/*  * get parameters for handle  */
end_comment

begin_function_decl
specifier|extern
name|int
name|time_pps_getparams
parameter_list|(
name|pps_handle_t
name|handle
parameter_list|,
name|pps_params_t
modifier|*
name|params_buf
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*   * time_pps_getcap - get capabilities for handle  */
end_comment

begin_function_decl
specifier|extern
name|int
name|time_pps_getcap
parameter_list|(
name|pps_handle_t
name|handle
parameter_list|,
name|int
modifier|*
name|pmode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Fetch timestamps  */
end_comment

begin_function_decl
specifier|extern
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
name|pinfo
parameter_list|,
specifier|const
name|struct
name|timespec
modifier|*
name|ptimeout
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * time_pps_kcbind - specify kernel consumer  *  * Not supported so far by Windows.  */
end_comment

begin_function_decl
specifier|extern
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
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TIMEPPS_H */
end_comment

end_unit

