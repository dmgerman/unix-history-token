begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * refclock_hopfpci.c  *  * - clock driver for hopf 6039 PCI board (GPS or DCF77)  * Bernd Altmeier altmeier@atlsoft.de  *  * latest source and further information can be found at:  * http://www.ATLSoft.de/ntp  *  * In order to run this driver you have to install and test  * the PCI-board driver for your system first.  *  * On Linux/UNIX  *  * The driver attempts to open the device /dev/hopf6039 .  * The device entry will be made by the installation process of  * the kernel module for the PCI-bus board. The driver sources  * belongs to the delivery equipment of the PCI-board.  *  * On Windows NT/2000  *  * The driver attempts to open the device by calling the function  * "OpenHopfDevice()". This function will be installed by the  * Device Driver for the PCI-bus board. The driver belongs to the  * delivery equipment of the PCI-board.  *  *  * Start   21.03.2000 Revision: 01.20  * changes 22.12.2000 Revision: 01.40 flag1 = 1 sync even if Quarz  *  */
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
name|CLOCK_HOPF_PCI
argument_list|)
end_if

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

begin_undef
undef|#
directive|undef
name|fileno
end_undef

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_undef
undef|#
directive|undef
name|fileno
end_undef

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_WINNT
end_ifndef

begin_include
include|#
directive|include
file|<sys/ipc.h>
end_include

begin_include
include|#
directive|include
file|<assert.h>
end_include

begin_include
include|#
directive|include
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|"hopf6039.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|"hopf_PCI_io.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * hopfpci interface definitions  */
end_comment

begin_define
define|#
directive|define
name|PRECISION
value|(-10)
end_define

begin_comment
comment|/* precision assumed (1 ms) */
end_comment

begin_define
define|#
directive|define
name|REFID
value|"hopf"
end_define

begin_comment
comment|/* reference ID */
end_comment

begin_define
define|#
directive|define
name|DESCRIPTION
value|"hopf Elektronik PCI radio board"
end_define

begin_define
define|#
directive|define
name|NSAMPLES
value|3
end_define

begin_comment
comment|/* stages of median filter */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYS_WINNT
end_ifndef

begin_define
define|#
directive|define
name|DEVICE
value|"/dev/hopf6039"
end_define

begin_comment
comment|/* device name inode*/
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEVICE
value|"hopf6039"
end_define

begin_comment
comment|/* device name WinNT  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|LEWAPWAR
value|0x20
end_define

begin_comment
comment|/* leap second warning bit */
end_comment

begin_define
define|#
directive|define
name|HOPF_OPMODE
value|0xC0
end_define

begin_comment
comment|/* operation mode mask */
end_comment

begin_define
define|#
directive|define
name|HOPF_INVALID
value|0x00
end_define

begin_comment
comment|/* no time code available */
end_comment

begin_define
define|#
directive|define
name|HOPF_INTERNAL
value|0x40
end_define

begin_comment
comment|/* internal clock */
end_comment

begin_define
define|#
directive|define
name|HOPF_RADIO
value|0x80
end_define

begin_comment
comment|/* radio clock */
end_comment

begin_define
define|#
directive|define
name|HOPF_RADIOHP
value|0xC0
end_define

begin_comment
comment|/* high precision radio clock */
end_comment

begin_comment
comment|/*  * hopfclock unit control structure.  */
end_comment

begin_struct
struct|struct
name|hopfclock_unit
block|{
name|short
name|unit
decl_stmt|;
comment|/* NTP refclock unit number */
name|char
name|leap_status
decl_stmt|;
comment|/* leap second flag */
block|}
struct|;
end_struct

begin_decl_stmt
name|int
name|fd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* file descr. */
end_comment

begin_comment
comment|/*  * Function prototypes  */
end_comment

begin_function_decl
specifier|static
name|int
name|hopfpci_start
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
name|hopfpci_shutdown
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
name|hopfpci_poll
parameter_list|(
name|int
name|unit
parameter_list|,
name|struct
name|peer
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Transfer vector  */
end_comment

begin_decl_stmt
name|struct
name|refclock
name|refclock_hopfpci
init|=
block|{
name|hopfpci_start
block|,
comment|/* start up driver */
name|hopfpci_shutdown
block|,
comment|/* shut down driver */
name|hopfpci_poll
block|,
comment|/* transmit poll message */
name|noentry
block|,
comment|/* not used */
name|noentry
block|,
comment|/* initialize driver (not used) */
name|noentry
block|,
comment|/* not used */
name|NOFLAGS
comment|/* not used */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * hopfpci_start - attach to hopf PCI board 6039  */
end_comment

begin_function
specifier|static
name|int
name|hopfpci_start
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
name|struct
name|hopfclock_unit
modifier|*
name|up
decl_stmt|;
comment|/* 	 * Allocate and initialize unit structure 	 */
name|up
operator|=
operator|(
expr|struct
name|hopfclock_unit
operator|*
operator|)
name|emalloc
argument_list|(
sizeof|sizeof
argument_list|(
expr|struct
name|hopfclock_unit
argument_list|)
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|up
operator|)
condition|)
block|{
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"hopfPCIClock(%d) emalloc: %m"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
ifdef|#
directive|ifdef
name|DEBUG
name|printf
argument_list|(
literal|"hopfPCIClock(%d) emalloc\n"
argument_list|,
name|unit
argument_list|)
expr_stmt|;
endif|#
directive|endif
return|return
operator|(
literal|0
operator|)
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
name|hopfclock_unit
argument_list|)
argument_list|)
expr_stmt|;
ifndef|#
directive|ifndef
name|SYS_WINNT
name|fd
operator|=
name|open
argument_list|(
name|DEVICE
argument_list|,
name|O_RDWR
argument_list|)
expr_stmt|;
comment|/* try to open hopf clock device */
else|#
directive|else
if|if
condition|(
operator|!
name|OpenHopfDevice
argument_list|()
condition|)
block|{
name|msyslog
argument_list|(
name|LOG_ERR
argument_list|,
literal|"Start: %s unit: %d failed!"
argument_list|,
name|DEVICE
argument_list|,
name|unit
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
endif|#
directive|endif
name|pp
operator|=
name|peer
operator|->
name|procptr
expr_stmt|;
name|pp
operator|->
name|io
operator|.
name|clock_recv
operator|=
name|noentry
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
operator|-
literal|1
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
name|get_systime
argument_list|(
operator|&
name|pp
operator|->
name|lastrec
argument_list|)
expr_stmt|;
comment|/* 	 * Initialize miscellaneous peer variables 	 */
if|if
condition|(
name|pp
operator|->
name|unitptr
operator|!=
literal|0
condition|)
block|{
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
literal|4
argument_list|)
expr_stmt|;
name|peer
operator|->
name|precision
operator|=
name|PRECISION
expr_stmt|;
name|pp
operator|->
name|clockdesc
operator|=
name|DESCRIPTION
expr_stmt|;
name|up
operator|->
name|leap_status
operator|=
literal|0
expr_stmt|;
name|up
operator|->
name|unit
operator|=
operator|(
name|short
operator|)
name|unit
expr_stmt|;
return|return
operator|(
literal|1
operator|)
return|;
block|}
else|else
block|{
return|return
literal|0
return|;
block|}
block|}
end_function

begin_comment
comment|/*  * hopfpci_shutdown - shut down the clock  */
end_comment

begin_function
specifier|static
name|void
name|hopfpci_shutdown
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
specifier|register
name|struct
name|hopfpciTime
modifier|*
name|up
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
name|hopfpciTime
operator|*
operator|)
name|pp
operator|->
name|unitptr
expr_stmt|;
ifndef|#
directive|ifndef
name|SYS_WINNT
name|close
argument_list|(
name|fd
argument_list|)
expr_stmt|;
else|#
directive|else
name|CloseHopfDevice
argument_list|()
expr_stmt|;
comment|//	UnmapViewOfFile (up);
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * hopfpci_poll - called by the transmit procedure  */
end_comment

begin_function
specifier|static
name|void
name|hopfpci_poll
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
specifier|register
name|struct
name|hopfpciTime
modifier|*
name|up
decl_stmt|;
name|HOPFTIME
name|m_time
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
name|hopfpciTime
operator|*
operator|)
name|pp
operator|->
name|unitptr
expr_stmt|;
ifndef|#
directive|ifndef
name|SYS_WINNT
name|ioctl
argument_list|(
name|fd
argument_list|,
name|HOPF_CLOCK_GET_UTC
argument_list|,
operator|&
name|m_time
argument_list|)
expr_stmt|;
else|#
directive|else
name|GetHopfSystemTime
argument_list|(
operator|&
name|m_time
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|pp
operator|->
name|polls
operator|++
expr_stmt|;
name|pp
operator|->
name|day
operator|=
name|ymd2yd
argument_list|(
name|m_time
operator|.
name|wYear
argument_list|,
name|m_time
operator|.
name|wMonth
argument_list|,
name|m_time
operator|.
name|wDay
argument_list|)
expr_stmt|;
name|pp
operator|->
name|hour
operator|=
name|m_time
operator|.
name|wHour
expr_stmt|;
name|pp
operator|->
name|minute
operator|=
name|m_time
operator|.
name|wMinute
expr_stmt|;
name|pp
operator|->
name|second
operator|=
name|m_time
operator|.
name|wSecond
expr_stmt|;
name|pp
operator|->
name|msec
operator|=
name|m_time
operator|.
name|wMilliseconds
expr_stmt|;
name|pp
operator|->
name|usec
operator|=
literal|0
expr_stmt|;
if|if
condition|(
name|m_time
operator|.
name|wStatus
operator|&
name|LEWAPWAR
condition|)
name|pp
operator|->
name|leap
operator|=
name|LEAP_ADDSECOND
expr_stmt|;
else|else
name|pp
operator|->
name|leap
operator|=
name|LEAP_NOWARNING
expr_stmt|;
name|sprintf
argument_list|(
name|pp
operator|->
name|a_lastcode
argument_list|,
literal|"ST: %02X T: %02d:%02d:%02d.%03d D: %02d.%02d.%04d"
argument_list|,
name|m_time
operator|.
name|wStatus
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
argument_list|,
name|pp
operator|->
name|msec
argument_list|,
name|m_time
operator|.
name|wDay
argument_list|,
name|m_time
operator|.
name|wMonth
argument_list|,
name|m_time
operator|.
name|wYear
argument_list|)
expr_stmt|;
name|pp
operator|->
name|lencode
operator|=
name|strlen
argument_list|(
name|pp
operator|->
name|a_lastcode
argument_list|)
expr_stmt|;
name|get_systime
argument_list|(
operator|&
name|pp
operator|->
name|lastrec
argument_list|)
expr_stmt|;
comment|/* 	 * If clock has no valid status then report error and exit 	 */
if|if
condition|(
operator|(
name|m_time
operator|.
name|wStatus
operator|&
name|HOPF_OPMODE
operator|)
operator|==
name|HOPF_INVALID
condition|)
block|{
comment|/* time ok? */
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_BADTIME
argument_list|)
expr_stmt|;
name|pp
operator|->
name|leap
operator|=
name|LEAP_NOTINSYNC
expr_stmt|;
return|return;
block|}
comment|/* 	 * Test if time is running on internal quarz 	 * if CLK_FLAG1 is set, sychronize even if no radio operation 	 */
if|if
condition|(
operator|(
name|m_time
operator|.
name|wStatus
operator|&
name|HOPF_OPMODE
operator|)
operator|==
name|HOPF_INTERNAL
condition|)
block|{
if|if
condition|(
operator|(
name|pp
operator|->
name|sloppyclockflag
operator|&
name|CLK_FLAG1
operator|)
operator|==
literal|0
condition|)
block|{
name|refclock_report
argument_list|(
name|peer
argument_list|,
name|CEVNT_BADTIME
argument_list|)
expr_stmt|;
name|pp
operator|->
name|leap
operator|=
name|LEAP_NOTINSYNC
expr_stmt|;
return|return;
block|}
block|}
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
return|return;
block|}
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
name|pp
operator|->
name|a_lastcode
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_decl_stmt
name|int
name|refclock_hopfpci_bs
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

