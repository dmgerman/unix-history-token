begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * refclock_jjy - clock driver for JJY receivers  */
end_comment

begin_comment
comment|/**********************************************************************/
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  Copyright (C) 2001, Takao Abe.  All rights reserved.              */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  Permission to use, copy, modify, and distribute this software     */
end_comment

begin_comment
comment|/*  and its documentation for any purpose is hereby granted           */
end_comment

begin_comment
comment|/*  without fee, provided that the following conditions are met:      */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  One retains the entire copyright notice properly, and both the    */
end_comment

begin_comment
comment|/*  copyright notice and this license. in the documentation and/or    */
end_comment

begin_comment
comment|/*  other materials provided with the distribution.                   */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  This software and the name of the author must not be used to      */
end_comment

begin_comment
comment|/*  endorse or promote products derived from this software without    */
end_comment

begin_comment
comment|/*  prior written permission.                                         */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  THIS SOFTWARE IS PROVIDED "AS IS" WITHOUT EXPRESSED OR IMPLIED    */
end_comment

begin_comment
comment|/*  WARRANTIES OF ANY KIND, INCLUDING, BUT NOT LIMITED TO, THE        */
end_comment

begin_comment
comment|/*  IMPLIED WARRANTIES OF MERCHANTABLILITY AND FITNESS FOR A          */
end_comment

begin_comment
comment|/*  PARTICULAR PURPOSE.                                               */
end_comment

begin_comment
comment|/*  IN NO EVENT SHALL THE AUTHOR TAKAO ABE BE LIABLE FOR ANY DIRECT,  */
end_comment

begin_comment
comment|/*  INDIRECT, GENERAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES   */
end_comment

begin_comment
comment|/*  ( INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE        */
end_comment

begin_comment
comment|/*  GOODS OR SERVICES; LOSS OF USE, DATA OR PROFITS; OR BUSINESS      */
end_comment

begin_comment
comment|/*  INTERRUPTION ) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,     */
end_comment

begin_comment
comment|/*  WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT ( INCLUDING        */
end_comment

begin_comment
comment|/*  NEGLIGENCE OR OTHERWISE ) ARISING IN ANY WAY OUT OF THE USE OF    */
end_comment

begin_comment
comment|/*  THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  This driver is developed in my private time, and is opened as     */
end_comment

begin_comment
comment|/*  voluntary contributions for the NTP.                              */
end_comment

begin_comment
comment|/*  The manufacturer of the JJY receiver has not participated in      */
end_comment

begin_comment
comment|/*  a development of this driver.                                     */
end_comment

begin_comment
comment|/*  The manufacturer does not warrant anything about this driver,     */
end_comment

begin_comment
comment|/*  and is not liable for anything about this driver.                 */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/**********************************************************************/
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  Author     Takao Abe                                              */
end_comment

begin_comment
comment|/*  Email      abetakao@bea.hi-ho.ne.jp                               */
end_comment

begin_comment
comment|/*  Homepage   http://www.bea.hi-ho.ne.jp/abetakao/                   */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/**********************************************************************/
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  History                                                           */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  2001/07/15                                                        */
end_comment

begin_comment
comment|/*    [New]    Support the Tristate Ltd. JJY receiver                 */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  2001/08/04                                                        */
end_comment

begin_comment
comment|/*    [Change] Log to clockstats even if bad reply                    */
end_comment

begin_comment
comment|/*    [Fix]    PRECISION = (-3) (about 100 ms)                        */
end_comment

begin_comment
comment|/*    [Add]    Support the C-DEX Co.Ltd. JJY receiver                 */
end_comment

begin_comment
comment|/*  2001/12/04                                                        */
end_comment

begin_comment
comment|/*    [Fix]    C-DEX JST2000 ( fukusima@goto.info.waseda.ac.jp )      */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/**********************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|REFCLOCK
argument_list|)
operator|&&
name|defined
argument_list|(
name|CLOCK_JJY
argument_list|)
end_if

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<time.h>
end_include

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
file|"ntp_tty.h"
end_include

begin_include
include|#
directive|include
file|"ntp_refclock.h"
end_include

begin_include
include|#
directive|include
file|"ntp_calendar.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_comment
comment|/**********************************************************************/
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  The Tristate Ltd. JJY receiver JJY01                              */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  Command        Response                 Remarks                   */
end_comment

begin_comment
comment|/*  ------------   ----------------------   ---------------------     */
end_comment

begin_comment
comment|/*  date<CR><LF>   YYYY/MM/DD XXX<CR><LF>                             */
end_comment

begin_comment
comment|/*  time<CR><LF>   HH:MM:SS<CR><LF>                                   */
end_comment

begin_comment
comment|/*  stim<CR><LF>   HH:MM:SS<CR><LF>         Reply at just second      */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  During synchronization after a receiver is turned on,             */
end_comment

begin_comment
comment|/*  It replies the past time from 2000/01/01 00:00:00.                */
end_comment

begin_comment
comment|/*  The function "refclock_process" checks the time and tells         */
end_comment

begin_comment
comment|/*  as an insanity time.                                              */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/**********************************************************************/
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  The C-DEX Co. Ltd. JJY receiver JST2000                           */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/*  Command        Response                 Remarks                   */
end_comment

begin_comment
comment|/*  ------------   ----------------------   ---------------------     */
end_comment

begin_comment
comment|/*<ENQ>1J<ETX><STX>JYYMMDD HHMMSSS<ETX>                          */
end_comment

begin_comment
comment|/*                                                                    */
end_comment

begin_comment
comment|/**********************************************************************/
end_comment

begin_comment
comment|/*  * Interface definitions  */
end_comment

begin_define
define|#
directive|define
name|DEVICE
value|"/dev/jjy%d"
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

begin_define
define|#
directive|define
name|REFID
value|"JJY"
end_define

begin_comment
comment|/* reference ID */
end_comment

begin_define
define|#
directive|define
name|DESCRIPTION
value|"JJY Receiver"
end_define

begin_define
define|#
directive|define
name|PRECISION
value|(-3)
end_define

begin_comment
comment|/* precision assumed (about 100 ms) */
end_comment

begin_comment
comment|/*  * JJY unit control structure  */
end_comment

begin_struct
struct|struct
name|jjyunit
block|{
name|char
name|unittype
decl_stmt|;
comment|/* UNITTYPE_XXXXXXXXXX */
name|short
name|version
decl_stmt|;
name|short
name|linediscipline
decl_stmt|;
comment|/* LDISC_CLK or LDISC_RAW */
name|int
name|linecount
decl_stmt|;
name|int
name|lineerror
decl_stmt|;
name|int
name|year
decl_stmt|,
name|month
decl_stmt|,
name|day
decl_stmt|,
name|hour
decl_stmt|,
name|minute
decl_stmt|,
name|second
decl_stmt|,
name|msecond
decl_stmt|;
comment|/* LDISC_RAW only */
define|#
directive|define
name|MAX_LINECOUNT
value|8
define|#
directive|define
name|MAX_RAWBUF
value|64
name|int
name|lineexpect
decl_stmt|;
name|int
name|charexpect
index|[
name|MAX_LINECOUNT
index|]
decl_stmt|;
name|int
name|charcount
decl_stmt|;
name|char
name|rawbuf
index|[
name|MAX_RAWBUF
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|UNITTYPE_TRISTATE_JJY01
value|1
end_define

begin_define
define|#
directive|define
name|UNITTYPE_CDEX_JST2000
value|2
end_define

begin_comment
comment|/*  * Function prototypes  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|jjy_start
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|jjy_shutdown
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|jjy_poll
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|jjy_poll_tristate_jjy01
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|jjy_poll_cdex_jst2000
name|P
argument_list|(
operator|(
name|int
operator|,
expr|struct
name|peer
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|void
name|jjy_receive
name|P
argument_list|(
operator|(
expr|struct
name|recvbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|jjy_receive_tristate_jjy01
name|P
argument_list|(
operator|(
expr|struct
name|recvbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|jjy_receive_cdex_jst2000
name|P
argument_list|(
operator|(
expr|struct
name|recvbuf
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Transfer vector  */
end_comment

begin_decl_stmt
name|struct
name|refclock
name|refclock_jjy
init|=
block|{
name|jjy_start
block|,
comment|/* start up driver */
name|jjy_shutdown
block|,
comment|/* shutdown driver */
name|jjy_poll
block|,
comment|/* transmit poll message */
name|noentry
block|,
comment|/* not used */
name|noentry
block|,
comment|/* not used */
name|noentry
block|,
comment|/* not used */
name|NOFLAGS
comment|/* not used */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Start up driver return code  */
end_comment

begin_define
define|#
directive|define
name|RC_START_SUCCESS
value|1
end_define

begin_define
define|#
directive|define
name|RC_START_ERROR
value|0
end_define

begin_comment
comment|/*  * Local constants definition  */
end_comment

begin_define
define|#
directive|define
name|MAX_LOGTEXT
value|64
end_define

begin_comment
comment|/**************************************************************************************************/
end_comment

begin_comment
comment|/*  jjy_start - open the devices and initialize data for processing                               */
end_comment

begin_comment
comment|/**************************************************************************************************/
end_comment

begin_function
specifier|static
name|int
name|jjy_start
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|peer
modifier|*
name|peer
parameter_list|)
block|{
name|struct
name|jjyunit
modifier|*
name|up
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
name|int
name|fd
decl_stmt|;
name|char
modifier|*
name|pDeviceName
decl_stmt|;
name|short
name|iDiscipline
decl_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
condition|)
block|{
name|printf
argument_list|(
literal|"jjy_start (refclock_jjy.c) : %s  mode=%d  "
argument_list|,
name|ntoa
argument_list|(
operator|&
name|peer
operator|->
name|srcadr
argument_list|)
argument_list|,
name|peer
operator|->
name|ttl
argument_list|)
expr_stmt|;
name|printf
argument_list|(
name|DEVICE
argument_list|,
name|unit
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"\n"
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* 	 * Open serial port 	 */
if|if
condition|(
operator|!
operator|(
name|pDeviceName
operator|=
operator|(
name|char
operator|*
operator|)
name|emalloc
argument_list|(
name|strlen
argument_list|(
name|DEVICE
argument_list|)
operator|+
literal|10
argument_list|)
operator|)
condition|)
block|{
return|return
name|RC_START_ERROR
return|;
block|}
name|sprintf
argument_list|(
name|pDeviceName
argument_list|,
name|DEVICE
argument_list|,
name|unit
argument_list|)
expr_stmt|;
comment|/* 	 * peer->ttl is a mode number specified by "127.127.40.X mode N" in the ntp.conf 	 */
switch|switch
condition|(
name|peer
operator|->
name|ttl
condition|)
block|{
case|case
literal|0
case|:
case|case
literal|1
case|:
name|iDiscipline
operator|=
name|LDISC_CLK
expr_stmt|;
break|break ;
case|case
literal|2
case|:
name|iDiscipline
operator|=
name|LDISC_RAW
expr_stmt|;
break|break ;
default|default :
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"JJY receiver [ %s mode %d ] : Unsupported mode"
argument_list|,
name|ntoa
argument_list|(
operator|&
name|peer
operator|->
name|srcadr
argument_list|)
argument_list|,
name|peer
operator|->
name|ttl
argument_list|)
expr_stmt|;
name|free
argument_list|(
operator|(
name|void
operator|*
operator|)
name|pDeviceName
argument_list|)
expr_stmt|;
return|return
name|RC_START_ERROR
return|;
block|}
if|if
condition|(
operator|!
operator|(
name|fd
operator|=
name|refclock_open
argument_list|(
name|pDeviceName
argument_list|,
name|SPEED232
argument_list|,
name|iDiscipline
argument_list|)
operator|)
condition|)
block|{
name|free
argument_list|(
operator|(
name|void
operator|*
operator|)
name|pDeviceName
argument_list|)
expr_stmt|;
return|return
name|RC_START_ERROR
return|;
block|}
name|free
argument_list|(
operator|(
name|void
operator|*
operator|)
name|pDeviceName
argument_list|)
expr_stmt|;
comment|/* 	 * Allocate and initialize unit structure 	 */
if|if
condition|(
operator|!
operator|(
name|up
operator|=
operator|(
expr|struct
name|jjyunit
operator|*
operator|)
name|emalloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|jjyunit
argument_list|)
argument_list|)
operator|)
condition|)
block|{
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
return|return
name|RC_START_ERROR
return|;
block|}
name|memset
argument_list|(
operator|(
name|char
operator|*
operator|)
name|up
argument_list|,
literal|0
argument_list|,
sizeof|sizeof
argument_list|(
expr|struct
name|jjyunit
argument_list|)
argument_list|)
expr_stmt|;
name|up
operator|->
name|linediscipline
operator|=
name|iDiscipline
expr_stmt|;
comment|/* 	 * peer->ttl is a mode number specified by "127.127.40.X mode N" in the ntp.conf 	 */
switch|switch
condition|(
name|peer
operator|->
name|ttl
condition|)
block|{
case|case
literal|0
case|:
comment|/* 		 * The mode 0 is a default clock type at this time. 		 * But this will be change to auto-detect mode in the future. 		 */
case|case
literal|1
case|:
name|up
operator|->
name|unittype
operator|=
name|UNITTYPE_TRISTATE_JJY01
expr_stmt|;
name|up
operator|->
name|version
operator|=
literal|100
expr_stmt|;
name|up
operator|->
name|lineexpect
operator|=
literal|2
expr_stmt|;
name|up
operator|->
name|charexpect
index|[
literal|0
index|]
operator|=
literal|14
expr_stmt|;
comment|/* YYYY/MM/DD WWW<CR><LF> */
name|up
operator|->
name|charexpect
index|[
literal|1
index|]
operator|=
literal|8
expr_stmt|;
comment|/* HH:MM:SS<CR><LF> */
break|break ;
case|case
literal|2
case|:
name|up
operator|->
name|unittype
operator|=
name|UNITTYPE_CDEX_JST2000
expr_stmt|;
name|up
operator|->
name|lineexpect
operator|=
literal|1
expr_stmt|;
name|up
operator|->
name|charexpect
index|[
literal|0
index|]
operator|=
literal|15
expr_stmt|;
comment|/*<STX>JYYMMDD HHMMSSS<ETX> */
break|break ;
default|default :
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"JJY receiver [ %s mode %d ] : Unsupported mode"
argument_list|,
name|ntoa
argument_list|(
operator|&
name|peer
operator|->
name|srcadr
argument_list|)
argument_list|,
name|peer
operator|->
name|ttl
argument_list|)
expr_stmt|;
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|free
argument_list|(
operator|(
name|void
operator|*
operator|)
name|up
argument_list|)
expr_stmt|;
return|return
name|RC_START_ERROR
return|;
block|}
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
name|pp
operator|->
name|unitptr
operator|=
operator|(
name|caddr_t
operator|)
name|up
expr_stmt|;
name|pp
operator|->
name|io
operator|.
name|clock_recv
operator|=
name|jjy_receive
expr_stmt|;
name|pp
operator|->
name|io
operator|.
name|srcclock
operator|=
operator|(
name|caddr_t
operator|)
name|peer
expr_stmt|;
name|pp
operator|->
name|io
operator|.
name|datalen
operator|=
literal|0
expr_stmt|;
name|pp
operator|->
name|io
operator|.
name|fd
operator|=
name|fd
expr_stmt|;
if|if
condition|(
operator|!
name|io_addclock
argument_list|(
operator|&
name|pp
operator|->
name|io
argument_list|)
condition|)
block|{
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
name|free
argument_list|(
operator|(
name|void
operator|*
operator|)
name|up
argument_list|)
expr_stmt|;
return|return
name|RC_START_ERROR
return|;
block|}
comment|/* 	 * Initialize miscellaneous variables 	 */
name|peer
operator|->
name|precision
operator|=
name|PRECISION
expr_stmt|;
name|peer
operator|->
name|burst
operator|=
literal|1
expr_stmt|;
name|pp
operator|->
name|clockdesc
operator|=
name|DESCRIPTION
expr_stmt|;
name|memcpy
argument_list|(
operator|(
name|char
operator|*
operator|)
operator|&
name|pp
operator|->
name|refid
argument_list|,
name|REFID
argument_list|,
name|strlen
argument_list|(
name|REFID
argument_list|)
argument_list|)
expr_stmt|;
return|return
name|RC_START_SUCCESS
return|;
block|}
end_function

begin_comment
comment|/**************************************************************************************************/
end_comment

begin_comment
comment|/*  jjy_shutdown - shutdown the clock                                                             */
end_comment

begin_comment
comment|/**************************************************************************************************/
end_comment

begin_function
specifier|static
name|void
name|jjy_shutdown
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|peer
modifier|*
name|peer
parameter_list|)
block|{
name|struct
name|jjyunit
modifier|*
name|up
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
name|up
operator|=
operator|(
expr|struct
name|jjyunit
operator|*
operator|)
name|pp
operator|->
name|unitptr
expr_stmt|;
name|io_closeclock
argument_list|(
operator|&
name|pp
operator|->
name|io
argument_list|)
expr_stmt|;
name|free
argument_list|(
operator|(
name|void
operator|*
operator|)
name|up
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**************************************************************************************************/
end_comment

begin_comment
comment|/*  jjy_receive - receive data from the serial interface                                          */
end_comment

begin_comment
comment|/**************************************************************************************************/
end_comment

begin_function
specifier|static
name|void
name|jjy_receive
parameter_list|(
name|struct
name|recvbuf
modifier|*
name|rbufp
parameter_list|)
block|{
name|struct
name|jjyunit
modifier|*
name|up
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
name|struct
name|peer
modifier|*
name|peer
decl_stmt|;
name|l_fp
name|tRecvTimestamp
decl_stmt|;
comment|/* arrival timestamp */
name|int
name|rc
decl_stmt|;
name|char
name|sLogText
index|[
name|MAX_LOGTEXT
index|]
decl_stmt|;
name|int
name|i
decl_stmt|,
name|bCntrlChar
decl_stmt|;
comment|/* 	 * Initialize pointers and read the timecode and timestamp 	 */
name|peer
operator|=
operator|(
expr|struct
name|peer
operator|*
operator|)
name|rbufp
operator|->
name|recv_srcclock
expr_stmt|;
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
name|up
operator|=
operator|(
expr|struct
name|jjyunit
operator|*
operator|)
name|pp
operator|->
name|unitptr
expr_stmt|;
comment|/* 	 * Get next input line 	 */
name|pp
operator|->
name|lencode
operator|=
name|refclock_gtlin
argument_list|(
name|rbufp
argument_list|,
name|pp
operator|->
name|a_lastcode
argument_list|,
name|BMAX
argument_list|,
operator|&
name|tRecvTimestamp
argument_list|)
expr_stmt|;
if|if
condition|(
name|up
operator|->
name|linediscipline
operator|==
name|LDISC_RAW
condition|)
block|{
comment|/* 		 * The reply with<STX> and<ETX> may give a blank line 		 */
if|if
condition|(
name|pp
operator|->
name|lencode
operator|==
literal|0
operator|&&
name|up
operator|->
name|charcount
operator|==
literal|0
condition|)
return|return ;
comment|/* 		 * Copy received charaters to temporary buffer  		 */
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|pp
operator|->
name|lencode
operator|&&
name|up
operator|->
name|charcount
operator|<
name|MAX_RAWBUF
operator|-
literal|2
condition|;
name|i
operator|++
operator|,
name|up
operator|->
name|charcount
operator|++
control|)
block|{
name|up
operator|->
name|rawbuf
index|[
name|up
operator|->
name|charcount
index|]
operator|=
name|pp
operator|->
name|a_lastcode
index|[
name|i
index|]
expr_stmt|;
block|}
while|while
condition|(
name|up
operator|->
name|charcount
operator|>
literal|0
operator|&&
name|up
operator|->
name|rawbuf
index|[
literal|0
index|]
operator|<
literal|' '
condition|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|up
operator|->
name|charcount
operator|-
literal|1
condition|;
name|i
operator|++
control|)
name|up
operator|->
name|rawbuf
index|[
name|i
index|]
operator|=
name|up
operator|->
name|rawbuf
index|[
name|i
operator|+
literal|1
index|]
expr_stmt|;
name|up
operator|->
name|charcount
operator|--
expr_stmt|;
block|}
name|bCntrlChar
operator|=
literal|0
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|up
operator|->
name|charcount
condition|;
name|i
operator|++
control|)
block|{
if|if
condition|(
name|up
operator|->
name|rawbuf
index|[
name|i
index|]
operator|<
literal|' '
condition|)
block|{
name|bCntrlChar
operator|=
literal|1
expr_stmt|;
break|break ;
block|}
block|}
if|if
condition|(
name|pp
operator|->
name|lencode
operator|>
literal|0
operator|&&
name|up
operator|->
name|linecount
operator|<
name|up
operator|->
name|lineexpect
condition|)
block|{
if|if
condition|(
name|bCntrlChar
operator|==
literal|0
operator|&&
name|up
operator|->
name|charcount
operator|<
name|up
operator|->
name|charexpect
index|[
name|up
operator|->
name|linecount
index|]
condition|)
return|return ;
block|}
name|up
operator|->
name|rawbuf
index|[
name|up
operator|->
name|charcount
index|]
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
comment|/* 		 * The reply with<CR><LF> gives a blank line 		 */
if|if
condition|(
name|pp
operator|->
name|lencode
operator|==
literal|0
condition|)
return|return ;
block|}
comment|/* 	 * We get down to business 	 */
name|pp
operator|->
name|lastrec
operator|=
name|tRecvTimestamp
expr_stmt|;
name|up
operator|->
name|linecount
operator|++
expr_stmt|;
if|if
condition|(
name|up
operator|->
name|lineerror
operator|!=
literal|0
condition|)
return|return ;
switch|switch
condition|(
name|up
operator|->
name|unittype
condition|)
block|{
case|case
name|UNITTYPE_TRISTATE_JJY01
case|:
name|rc
operator|=
name|jjy_receive_tristate_jjy01
argument_list|(
name|rbufp
argument_list|)
expr_stmt|;
break|break ;
case|case
name|UNITTYPE_CDEX_JST2000
case|:
name|rc
operator|=
name|jjy_receive_cdex_jst2000
argument_list|(
name|rbufp
argument_list|)
expr_stmt|;
break|break ;
default|default :
name|rc
operator|=
literal|0
expr_stmt|;
break|break ;
block|}
if|if
condition|(
name|up
operator|->
name|linediscipline
operator|==
name|LDISC_RAW
condition|)
block|{
if|if
condition|(
name|up
operator|->
name|linecount
operator|<=
name|up
operator|->
name|lineexpect
operator|&&
name|up
operator|->
name|charcount
operator|>
name|up
operator|->
name|charexpect
index|[
name|up
operator|->
name|linecount
operator|-
literal|1
index|]
condition|)
block|{
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|up
operator|->
name|charcount
operator|-
name|up
operator|->
name|charexpect
index|[
name|up
operator|->
name|linecount
operator|-
literal|1
index|]
condition|;
name|i
operator|++
control|)
block|{
name|up
operator|->
name|rawbuf
index|[
name|i
index|]
operator|=
name|up
operator|->
name|rawbuf
index|[
name|i
operator|+
name|up
operator|->
name|charexpect
index|[
name|up
operator|->
name|linecount
operator|-
literal|1
index|]
index|]
expr_stmt|;
block|}
name|up
operator|->
name|charcount
operator|-=
name|up
operator|->
name|charexpect
index|[
name|up
operator|->
name|linecount
operator|-
literal|1
index|]
expr_stmt|;
block|}
else|else
block|{
name|up
operator|->
name|charcount
operator|=
literal|0
expr_stmt|;
block|}
block|}
if|if
condition|(
name|rc
operator|==
literal|0
condition|)
return|return ;
if|if
condition|(
name|up
operator|->
name|lineerror
operator|!=
literal|0
condition|)
block|{
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_BADREPLY
argument_list|)
expr_stmt|;
name|strcpy
argument_list|(
name|sLogText
argument_list|,
literal|"BAD REPLY ["
argument_list|)
expr_stmt|;
if|if
condition|(
name|up
operator|->
name|linediscipline
operator|==
name|LDISC_RAW
condition|)
block|{
name|strncat
argument_list|(
name|sLogText
argument_list|,
name|up
operator|->
name|rawbuf
argument_list|,
name|MAX_LOGTEXT
operator|-
name|strlen
argument_list|(
name|sLogText
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|strncat
argument_list|(
name|sLogText
argument_list|,
name|pp
operator|->
name|a_lastcode
argument_list|,
name|MAX_LOGTEXT
operator|-
name|strlen
argument_list|(
name|sLogText
argument_list|)
operator|-
literal|1
argument_list|)
expr_stmt|;
block|}
name|sLogText
index|[
name|MAX_LOGTEXT
operator|-
literal|1
index|]
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|strlen
argument_list|(
name|sLogText
argument_list|)
operator|<
name|MAX_LOGTEXT
operator|-
literal|2
condition|)
name|strcat
argument_list|(
name|sLogText
argument_list|,
literal|"]"
argument_list|)
expr_stmt|;
name|record_clock_stats
argument_list|(
operator|&
name|peer
operator|->
name|srcadr
argument_list|,
name|sLogText
argument_list|)
expr_stmt|;
return|return ;
block|}
name|pp
operator|->
name|year
operator|=
name|up
operator|->
name|year
expr_stmt|;
name|pp
operator|->
name|day
operator|=
name|ymd2yd
argument_list|(
name|up
operator|->
name|year
argument_list|,
name|up
operator|->
name|month
argument_list|,
name|up
operator|->
name|day
argument_list|)
expr_stmt|;
name|pp
operator|->
name|hour
operator|=
name|up
operator|->
name|hour
expr_stmt|;
name|pp
operator|->
name|minute
operator|=
name|up
operator|->
name|minute
expr_stmt|;
name|pp
operator|->
name|second
operator|=
name|up
operator|->
name|second
expr_stmt|;
name|pp
operator|->
name|nsec
operator|=
name|up
operator|->
name|msecond
operator|*
literal|1000000
expr_stmt|;
comment|/*  	 * JST to UTC  	 */
name|pp
operator|->
name|hour
operator|-=
literal|9
expr_stmt|;
if|if
condition|(
name|pp
operator|->
name|hour
operator|<
literal|0
condition|)
block|{
name|pp
operator|->
name|hour
operator|+=
literal|24
expr_stmt|;
name|pp
operator|->
name|day
operator|--
expr_stmt|;
if|if
condition|(
name|pp
operator|->
name|day
operator|<
literal|1
condition|)
block|{
name|pp
operator|->
name|year
operator|--
expr_stmt|;
name|pp
operator|->
name|day
operator|=
name|ymd2yd
argument_list|(
name|pp
operator|->
name|year
argument_list|,
literal|12
argument_list|,
literal|31
argument_list|)
expr_stmt|;
block|}
block|}
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
condition|)
block|{
name|printf
argument_list|(
literal|"jjy_receive (refclock_jjy.c) : %04d/%02d/%02d %02d:%02d:%02d JST   "
argument_list|,
name|up
operator|->
name|year
argument_list|,
name|up
operator|->
name|month
argument_list|,
name|up
operator|->
name|day
argument_list|,
name|up
operator|->
name|hour
argument_list|,
name|up
operator|->
name|minute
argument_list|,
name|up
operator|->
name|second
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"( %04d/%03d %02d:%02d:%02d UTC )\n"
argument_list|,
name|pp
operator|->
name|year
argument_list|,
name|pp
operator|->
name|day
argument_list|,
name|pp
operator|->
name|hour
argument_list|,
name|pp
operator|->
name|minute
argument_list|,
name|pp
operator|->
name|second
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
comment|/* 	 * Process the new sample in the median filter and determine the 	 * timecode timestamp. 	 */
if|if
condition|(
operator|!
name|refclock_process
argument_list|(
name|pp
argument_list|)
condition|)
block|{
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_BADTIME
argument_list|)
expr_stmt|;
name|sprintf
argument_list|(
name|sLogText
argument_list|,
literal|"BAD TIME %04d/%02d/%02d %02d:%02d:%02d JST"
argument_list|,
name|up
operator|->
name|year
argument_list|,
name|up
operator|->
name|month
argument_list|,
name|up
operator|->
name|day
argument_list|,
name|up
operator|->
name|hour
argument_list|,
name|up
operator|->
name|minute
argument_list|,
name|up
operator|->
name|second
argument_list|)
expr_stmt|;
name|record_clock_stats
argument_list|(
operator|&
name|peer
operator|->
name|srcadr
argument_list|,
name|sLogText
argument_list|)
expr_stmt|;
return|return ;
block|}
name|sprintf
argument_list|(
name|sLogText
argument_list|,
literal|"%04d/%02d/%02d %02d:%02d:%02d JST"
argument_list|,
name|up
operator|->
name|year
argument_list|,
name|up
operator|->
name|month
argument_list|,
name|up
operator|->
name|day
argument_list|,
name|up
operator|->
name|hour
argument_list|,
name|up
operator|->
name|minute
argument_list|,
name|up
operator|->
name|second
argument_list|)
expr_stmt|;
name|pp
operator|->
name|lastref
operator|=
name|pp
operator|->
name|lastrec
expr_stmt|;
name|refclock_receive
argument_list|(
name|peer
argument_list|)
expr_stmt|;
name|record_clock_stats
argument_list|(
operator|&
name|peer
operator|->
name|srcadr
argument_list|,
name|sLogText
argument_list|)
expr_stmt|;
block|}
end_function

begin_comment
comment|/**************************************************************************************************/
end_comment

begin_function
specifier|static
name|int
name|jjy_receive_tristate_jjy01
parameter_list|(
name|struct
name|recvbuf
modifier|*
name|rbufp
parameter_list|)
block|{
name|struct
name|jjyunit
modifier|*
name|up
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
name|struct
name|peer
modifier|*
name|peer
decl_stmt|;
name|char
modifier|*
name|pBuf
decl_stmt|;
name|int
name|iLen
decl_stmt|;
name|int
name|rc
decl_stmt|;
comment|/* 	 * Initialize pointers and read the timecode and timestamp 	 */
name|peer
operator|=
operator|(
expr|struct
name|peer
operator|*
operator|)
name|rbufp
operator|->
name|recv_srcclock
expr_stmt|;
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
name|up
operator|=
operator|(
expr|struct
name|jjyunit
operator|*
operator|)
name|pp
operator|->
name|unitptr
expr_stmt|;
if|if
condition|(
name|up
operator|->
name|linediscipline
operator|==
name|LDISC_RAW
condition|)
block|{
name|pBuf
operator|=
name|up
operator|->
name|rawbuf
expr_stmt|;
name|iLen
operator|=
name|up
operator|->
name|charcount
expr_stmt|;
block|}
else|else
block|{
name|pBuf
operator|=
name|pp
operator|->
name|a_lastcode
expr_stmt|;
name|iLen
operator|=
name|pp
operator|->
name|lencode
expr_stmt|;
block|}
switch|switch
condition|(
name|up
operator|->
name|linecount
condition|)
block|{
case|case
literal|1
case|:
comment|/* YYYY/MM/DD */
if|if
condition|(
name|iLen
operator|<
literal|10
condition|)
block|{
name|up
operator|->
name|lineerror
operator|=
literal|1
expr_stmt|;
break|break ;
block|}
name|rc
operator|=
name|sscanf
argument_list|(
name|pBuf
argument_list|,
literal|"%4d/%2d/%2d"
argument_list|,
operator|&
name|up
operator|->
name|year
argument_list|,
operator|&
name|up
operator|->
name|month
argument_list|,
operator|&
name|up
operator|->
name|day
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|3
operator|||
name|up
operator|->
name|year
operator|<
literal|2000
operator|||
name|up
operator|->
name|month
operator|<
literal|1
operator|||
name|up
operator|->
name|month
operator|>
literal|12
operator|||
name|up
operator|->
name|day
operator|<
literal|1
operator|||
name|up
operator|->
name|day
operator|>
literal|31
condition|)
block|{
name|up
operator|->
name|lineerror
operator|=
literal|1
expr_stmt|;
break|break ;
block|}
return|return
literal|0
return|;
case|case
literal|2
case|:
comment|/* HH:MM:SS */
if|if
condition|(
name|iLen
operator|<
literal|8
condition|)
block|{
name|up
operator|->
name|lineerror
operator|=
literal|1
expr_stmt|;
break|break ;
block|}
name|rc
operator|=
name|sscanf
argument_list|(
name|pBuf
argument_list|,
literal|"%2d:%2d:%2d"
argument_list|,
operator|&
name|up
operator|->
name|hour
argument_list|,
operator|&
name|up
operator|->
name|minute
argument_list|,
operator|&
name|up
operator|->
name|second
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|3
operator|||
name|up
operator|->
name|hour
operator|>
literal|23
operator|||
name|up
operator|->
name|minute
operator|>
literal|59
operator|||
name|up
operator|->
name|second
operator|>
literal|60
condition|)
block|{
name|up
operator|->
name|lineerror
operator|=
literal|1
expr_stmt|;
break|break ;
block|}
name|up
operator|->
name|msecond
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|up
operator|->
name|hour
operator|==
literal|0
operator|&&
name|up
operator|->
name|minute
operator|==
literal|0
operator|&&
name|up
operator|->
name|second
operator|<=
literal|2
condition|)
block|{
comment|/* 			 * The command "date" and "time" ( or "stim" ) were sent to the JJY receiver continuously. 			 * But the JJY receiver replies a date and time separately. 			 * Just after midnight transtions, we ignore this time. 			 */
return|return
literal|0
return|;
block|}
break|break ;
default|default :
comment|/*  Unexpected reply */
name|up
operator|->
name|lineerror
operator|=
literal|1
expr_stmt|;
break|break ;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/**************************************************************************************************/
end_comment

begin_function
specifier|static
name|int
name|jjy_receive_cdex_jst2000
parameter_list|(
name|struct
name|recvbuf
modifier|*
name|rbufp
parameter_list|)
block|{
name|struct
name|jjyunit
modifier|*
name|up
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
name|struct
name|peer
modifier|*
name|peer
decl_stmt|;
name|char
modifier|*
name|pBuf
decl_stmt|;
name|int
name|iLen
decl_stmt|;
name|int
name|rc
decl_stmt|;
comment|/* 	 * Initialize pointers and read the timecode and timestamp 	 */
name|peer
operator|=
operator|(
expr|struct
name|peer
operator|*
operator|)
name|rbufp
operator|->
name|recv_srcclock
expr_stmt|;
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
name|up
operator|=
operator|(
expr|struct
name|jjyunit
operator|*
operator|)
name|pp
operator|->
name|unitptr
expr_stmt|;
if|if
condition|(
name|up
operator|->
name|linediscipline
operator|==
name|LDISC_RAW
condition|)
block|{
name|pBuf
operator|=
name|up
operator|->
name|rawbuf
expr_stmt|;
name|iLen
operator|=
name|up
operator|->
name|charcount
expr_stmt|;
block|}
else|else
block|{
name|pBuf
operator|=
name|pp
operator|->
name|a_lastcode
expr_stmt|;
name|iLen
operator|=
name|pp
operator|->
name|lencode
expr_stmt|;
block|}
switch|switch
condition|(
name|up
operator|->
name|linecount
condition|)
block|{
case|case
literal|1
case|:
comment|/* JYYMMDD HHMMSSS */
if|if
condition|(
name|iLen
operator|<
literal|15
condition|)
block|{
name|up
operator|->
name|lineerror
operator|=
literal|1
expr_stmt|;
break|break ;
block|}
name|rc
operator|=
name|sscanf
argument_list|(
name|pBuf
argument_list|,
literal|"J%2d%2d%2d%*1d%2d%2d%2d%1d"
argument_list|,
operator|&
name|up
operator|->
name|year
argument_list|,
operator|&
name|up
operator|->
name|month
argument_list|,
operator|&
name|up
operator|->
name|day
argument_list|,
operator|&
name|up
operator|->
name|hour
argument_list|,
operator|&
name|up
operator|->
name|minute
argument_list|,
operator|&
name|up
operator|->
name|second
argument_list|,
operator|&
name|up
operator|->
name|msecond
argument_list|)
expr_stmt|;
if|if
condition|(
name|rc
operator|!=
literal|7
operator|||
name|up
operator|->
name|month
operator|<
literal|1
operator|||
name|up
operator|->
name|month
operator|>
literal|12
operator|||
name|up
operator|->
name|day
operator|<
literal|1
operator|||
name|up
operator|->
name|day
operator|>
literal|31
operator|||
name|up
operator|->
name|hour
operator|>
literal|23
operator|||
name|up
operator|->
name|minute
operator|>
literal|59
operator|||
name|up
operator|->
name|second
operator|>
literal|60
condition|)
block|{
name|up
operator|->
name|lineerror
operator|=
literal|1
expr_stmt|;
break|break ;
block|}
name|up
operator|->
name|year
operator|+=
literal|2000
expr_stmt|;
name|up
operator|->
name|msecond
operator|*=
literal|100
expr_stmt|;
break|break ;
default|default :
comment|/*  Unexpected reply */
name|up
operator|->
name|lineerror
operator|=
literal|1
expr_stmt|;
break|break ;
block|}
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/**************************************************************************************************/
end_comment

begin_comment
comment|/*  jjy_poll - called by the transmit procedure                                                   */
end_comment

begin_comment
comment|/**************************************************************************************************/
end_comment

begin_function
specifier|static
name|void
name|jjy_poll
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|peer
modifier|*
name|peer
parameter_list|)
block|{
name|struct
name|jjyunit
modifier|*
name|up
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
name|up
operator|=
operator|(
expr|struct
name|jjyunit
operator|*
operator|)
name|pp
operator|->
name|unitptr
expr_stmt|;
if|if
condition|(
name|pp
operator|->
name|polls
operator|>
literal|0
operator|&&
name|up
operator|->
name|linecount
operator|==
literal|0
condition|)
block|{
comment|/* 		 * No reply for last command 		 */
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_TIMEOUT
argument_list|)
expr_stmt|;
block|}
ifdef|#
directive|ifdef
name|DEBUG
if|if
condition|(
name|debug
condition|)
block|{
name|printf
argument_list|(
literal|"jjy_poll (refclock_jjy.c) : %ld\n"
argument_list|,
name|pp
operator|->
name|polls
argument_list|)
expr_stmt|;
block|}
endif|#
directive|endif
name|pp
operator|->
name|polls
operator|++
expr_stmt|;
name|up
operator|->
name|linecount
operator|=
literal|0
expr_stmt|;
name|up
operator|->
name|lineerror
operator|=
literal|0
expr_stmt|;
name|up
operator|->
name|charcount
operator|=
literal|0
expr_stmt|;
switch|switch
condition|(
name|up
operator|->
name|unittype
condition|)
block|{
case|case
name|UNITTYPE_TRISTATE_JJY01
case|:
name|jjy_poll_tristate_jjy01
argument_list|(
name|unit
argument_list|,
name|peer
argument_list|)
expr_stmt|;
break|break ;
case|case
name|UNITTYPE_CDEX_JST2000
case|:
name|jjy_poll_cdex_jst2000
argument_list|(
name|unit
argument_list|,
name|peer
argument_list|)
expr_stmt|;
break|break ;
default|default :
break|break ;
block|}
block|}
end_function

begin_comment
comment|/**************************************************************************************************/
end_comment

begin_function
specifier|static
name|void
name|jjy_poll_tristate_jjy01
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|peer
modifier|*
name|peer
parameter_list|)
block|{
name|struct
name|jjyunit
modifier|*
name|up
decl_stmt|;
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
name|up
operator|=
operator|(
expr|struct
name|jjyunit
operator|*
operator|)
name|pp
operator|->
name|unitptr
expr_stmt|;
comment|/* 	 * Send "date<CR><LF>" command 	 */
if|if
condition|(
name|write
argument_list|(
name|pp
operator|->
name|io
operator|.
name|fd
argument_list|,
literal|"date\r\n"
argument_list|,
literal|6
argument_list|)
operator|!=
literal|6
condition|)
block|{
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_FAULT
argument_list|)
expr_stmt|;
block|}
comment|/* 	 * Send "stim<CR><LF>" or "time<CR><LF>" command 	 */
if|if
condition|(
name|up
operator|->
name|version
operator|>=
literal|100
condition|)
block|{
if|if
condition|(
name|write
argument_list|(
name|pp
operator|->
name|io
operator|.
name|fd
argument_list|,
literal|"stim\r\n"
argument_list|,
literal|6
argument_list|)
operator|!=
literal|6
condition|)
block|{
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_FAULT
argument_list|)
expr_stmt|;
block|}
block|}
else|else
block|{
if|if
condition|(
name|write
argument_list|(
name|pp
operator|->
name|io
operator|.
name|fd
argument_list|,
literal|"time\r\n"
argument_list|,
literal|6
argument_list|)
operator|!=
literal|6
condition|)
block|{
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_FAULT
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_function

begin_comment
comment|/**************************************************************************************************/
end_comment

begin_function
specifier|static
name|void
name|jjy_poll_cdex_jst2000
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|peer
modifier|*
name|peer
parameter_list|)
block|{
name|struct
name|refclockproc
modifier|*
name|pp
decl_stmt|;
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
comment|/* 	 * Send "<ENQ>1J<ETX>" command 	 */
if|if
condition|(
name|write
argument_list|(
name|pp
operator|->
name|io
operator|.
name|fd
argument_list|,
literal|"\0051J\003"
argument_list|,
literal|4
argument_list|)
operator|!=
literal|4
condition|)
block|{
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_FAULT
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|refclock_jjy_bs
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* REFCLOCK */
end_comment

end_unit

