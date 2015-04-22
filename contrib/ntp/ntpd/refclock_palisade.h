begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * This software was developed by the Software and Component Technologies  * group of Trimble Navigation, Ltd.  *  * Copyright (c) 1997, 1998, 1999, 2000   Trimble Navigation Ltd.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *    This product includes software developed by Trimble Navigation, Ltd.  * 4. The name of Trimble Navigation Ltd. may not be used to endorse or  *    promote products derived from this software without specific prior  *    written permission.  *  * THIS SOFTWARE IS PROVIDED BY TRIMBLE NAVIGATION LTD. ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL TRIMBLE NAVIGATION LTD. BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/*  * refclock_palisade - clock driver for the Trimble Palisade GPS  * timing receiver  *  * For detailed information on this program, please refer to the html   * Refclock 29 page accompanying the NTP distribution.  *  * for questions / bugs / comments, contact:  * sven_dietrich@trimble.com  *  * Sven-Thorsten Dietrich  * 645 North Mary Avenue  * Post Office Box 3642  * Sunnyvale, CA 94088-3642  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|REFCLOCK_PALISADE_H
end_ifndef

begin_define
define|#
directive|define
name|REFCLOCK_PALISADE_H
end_define

begin_if
if|#
directive|if
name|defined
name|HAVE_SYS_MODEM_H
end_if

begin_include
include|#
directive|include
file|<sys/modem.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|__QNXNTO__
end_ifndef

begin_define
define|#
directive|define
name|TIOCMSET
value|MCSETA
end_define

begin_define
define|#
directive|define
name|TIOCMGET
value|MCGETA
end_define

begin_define
define|#
directive|define
name|TIOCM_RTS
value|MRTS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_TERMIOS_H
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|TERMIOS_NEEDS__SVID3
end_ifdef

begin_define
define|#
directive|define
name|_SVID3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<termios.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|TERMIOS_NEEDS__SVID3
end_ifdef

begin_undef
undef|#
directive|undef
name|_SVID3
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_SYS_IOCTL_H
end_ifdef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ntpd.h"
end_include

begin_include
include|#
directive|include
file|"ntp_io.h"
end_include

begin_include
include|#
directive|include
file|"ntp_control.h"
end_include

begin_include
include|#
directive|include
file|"ntp_refclock.h"
end_include

begin_include
include|#
directive|include
file|"ntp_unixtime.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_comment
comment|/*  * GPS Definitions  */
end_comment

begin_define
define|#
directive|define
name|DESCRIPTION
value|"Trimble Palisade GPS"
end_define

begin_comment
comment|/* Long name */
end_comment

begin_define
define|#
directive|define
name|PRECISION
value|(-20)
end_define

begin_comment
comment|/* precision assumed (about 1 us) */
end_comment

begin_define
define|#
directive|define
name|REFID
value|"GPS\0"
end_define

begin_comment
comment|/* reference ID */
end_comment

begin_define
define|#
directive|define
name|TRMB_MINPOLL
value|4
end_define

begin_comment
comment|/* 16 seconds */
end_comment

begin_define
define|#
directive|define
name|TRMB_MAXPOLL
value|5
end_define

begin_comment
comment|/* 32 seconds */
end_comment

begin_comment
comment|/*  * I/O Definitions  */
end_comment

begin_define
define|#
directive|define
name|DEVICE
value|"/dev/palisade%d"
end_define

begin_comment
comment|/* device name and unit */
end_comment

begin_define
define|#
directive|define
name|SPEED232
value|B9600
end_define

begin_comment
comment|/* uart speed (9600 baud) */
end_comment

begin_comment
comment|/*  * TSIP Report Definitions  */
end_comment

begin_define
define|#
directive|define
name|LENCODE_8F0B
value|74
end_define

begin_comment
comment|/* Length of TSIP 8F-0B Packet& header */
end_comment

begin_define
define|#
directive|define
name|LENCODE_NTP
value|22
end_define

begin_comment
comment|/* Length of Palisade NTP Packet */
end_comment

begin_define
define|#
directive|define
name|LENCODE_8FAC
value|68
end_define

begin_comment
comment|/* Length of Thunderbolt 8F-AC Position Packet*/
end_comment

begin_define
define|#
directive|define
name|LENCODE_8FAB
value|17
end_define

begin_comment
comment|/* Length of Thunderbolt Primary Timing Packet*/
end_comment

begin_comment
comment|/* Allowed Sub-Packet ID's */
end_comment

begin_define
define|#
directive|define
name|PACKET_8F0B
value|0x0B
end_define

begin_define
define|#
directive|define
name|PACKET_NTP
value|0xAD
end_define

begin_comment
comment|/* Thunderbolt Packets */
end_comment

begin_define
define|#
directive|define
name|PACKET_8FAC
value|0xAC
end_define

begin_comment
comment|/* Supplementary Thunderbolt Time Packet */
end_comment

begin_define
define|#
directive|define
name|PACKET_8FAB
value|0xAB
end_define

begin_comment
comment|/* Primary Thunderbolt Time Packet */
end_comment

begin_define
define|#
directive|define
name|PACKET_6D
value|0x6D
end_define

begin_comment
comment|/* Supplementary Thunderbolt Tracking Stats */
end_comment

begin_define
define|#
directive|define
name|PACKET_41
value|0x41
end_define

begin_comment
comment|/* Thunderbolt I dont know what this packet is, it's not documented on my manual*/
end_comment

begin_comment
comment|/* Acutime Packets */
end_comment

begin_define
define|#
directive|define
name|PACKET_41A
value|0x41
end_define

begin_comment
comment|/* GPS time */
end_comment

begin_define
define|#
directive|define
name|PACKET_46
value|0x46
end_define

begin_comment
comment|/* Receiver Health */
end_comment

begin_define
define|#
directive|define
name|DLE
value|0x10
end_define

begin_define
define|#
directive|define
name|ETX
value|0x03
end_define

begin_comment
comment|/* parse states */
end_comment

begin_define
define|#
directive|define
name|TSIP_PARSED_EMPTY
value|0
end_define

begin_define
define|#
directive|define
name|TSIP_PARSED_FULL
value|1
end_define

begin_define
define|#
directive|define
name|TSIP_PARSED_DLE_1
value|2
end_define

begin_define
define|#
directive|define
name|TSIP_PARSED_DATA
value|3
end_define

begin_define
define|#
directive|define
name|TSIP_PARSED_DLE_2
value|4
end_define

begin_comment
comment|/*   * Leap-Insert and Leap-Delete are encoded as follows:  * 	PALISADE_UTC_TIME set   and PALISADE_LEAP_PENDING set: INSERT leap  */
end_comment

begin_define
define|#
directive|define
name|PALISADE_LEAP_INPROGRESS
value|0x08
end_define

begin_comment
comment|/* This is the leap flag			*/
end_comment

begin_define
define|#
directive|define
name|PALISADE_LEAP_WARNING
value|0x04
end_define

begin_comment
comment|/* GPS Leap Warning (see ICD-200) */
end_comment

begin_define
define|#
directive|define
name|PALISADE_LEAP_PENDING
value|0x02
end_define

begin_comment
comment|/* Leap Pending (24 hours)		*/
end_comment

begin_define
define|#
directive|define
name|PALISADE_UTC_TIME
value|0x01
end_define

begin_comment
comment|/* UTC time available				*/
end_comment

begin_define
define|#
directive|define
name|mb
parameter_list|(
name|_X_
parameter_list|)
value|(up->rpt_buf[(_X_ + 1)])
end_define

begin_comment
comment|/* shortcut for buffer access	*/
end_comment

begin_comment
comment|/* Conversion Definitions */
end_comment

begin_define
define|#
directive|define
name|GPS_PI
value|(3.1415926535898)
end_define

begin_define
define|#
directive|define
name|R2D
value|(180.0/GPS_PI)
end_define

begin_comment
comment|/*  * Structure for build data packets for send (thunderbolt uses it only)  * taken from Markus Prosch  */
end_comment

begin_struct
struct|struct
name|packettx
block|{
name|short
name|size
decl_stmt|;
name|u_char
modifier|*
name|data
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Palisade unit control structure.  */
end_comment

begin_struct
struct|struct
name|palisade_unit
block|{
name|short
name|unit
decl_stmt|;
comment|/* NTP refclock unit number */
name|int
name|polled
decl_stmt|;
comment|/* flag to detect noreplies */
name|char
name|leap_status
decl_stmt|;
comment|/* leap second flag */
name|char
name|rpt_status
decl_stmt|;
comment|/* TSIP Parser State */
name|short
name|rpt_cnt
decl_stmt|;
comment|/* TSIP packet length so far */
name|char
name|rpt_buf
index|[
name|BMAX
index|]
decl_stmt|;
comment|/* packet assembly buffer */
name|int
name|type
decl_stmt|;
comment|/* Clock mode type */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Function prototypes  */
end_comment

begin_function_decl
specifier|static
name|int
name|palisade_start
parameter_list|(
name|int
parameter_list|,
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|palisade_shutdown
parameter_list|(
name|int
parameter_list|,
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|palisade_receive
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|palisade_poll
parameter_list|(
name|int
parameter_list|,
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|palisade_io
parameter_list|(
name|struct
name|recvbuf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|palisade_configure
parameter_list|(
name|int
parameter_list|,
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|TSIP_decode
parameter_list|(
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|HW_poll
parameter_list|(
name|struct
name|refclockproc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|double
name|getdbl
parameter_list|(
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|short
name|getint
parameter_list|(
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int32
name|getlong
parameter_list|(
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|PALISADE_SENDCMD_RESURRECTED
end_ifdef

begin_function_decl
specifier|static
name|void
name|sendcmd
parameter_list|(
name|struct
name|packettx
modifier|*
name|buffer
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|static
name|void
name|sendsupercmd
parameter_list|(
name|struct
name|packettx
modifier|*
name|buffer
parameter_list|,
name|int
name|c1
parameter_list|,
name|int
name|c2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|sendbyte
parameter_list|(
name|struct
name|packettx
modifier|*
name|buffer
parameter_list|,
name|int
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|sendint
parameter_list|(
name|struct
name|packettx
modifier|*
name|buffer
parameter_list|,
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|int
name|sendetx
parameter_list|(
name|struct
name|packettx
modifier|*
name|buffer
parameter_list|,
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|init_thunderbolt
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|init_acutime
parameter_list|(
name|int
name|fd
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REFCLOCK_PALISADE_H */
end_comment

end_unit

