begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * ntp_tty.h - header file for serial lines handling  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NTP_TTY_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_TTY_H
end_define

begin_comment
comment|/*  * use only one tty model - no use in initialising  * a tty in three ways  * HAVE_TERMIOS is preferred over HAVE_SYSV_TTYS over HAVE_BSD_TTYS  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_TERMIOS_H
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_SYS_TERMIOS_H
argument_list|)
end_if

begin_define
define|#
directive|define
name|HAVE_TERMIOS
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_TERMIO_H
argument_list|)
end_elif

begin_define
define|#
directive|define
name|HAVE_SYSV_TTYS
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_SGTTY_H
argument_list|)
end_elif

begin_define
define|#
directive|define
name|HAVE_BSD_TTYS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|VMS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SYS_VXWORKS
argument_list|)
end_if

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|HAVE_SYSV_TTYS
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_BSD_TTYS
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|HAVE_TERMIOS
argument_list|)
end_if

begin_include
include|#
directive|include
file|"ERROR: no tty type defined!"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !VMS&& !SYS_VXWORKS*/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_BSD_TTYS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sgtty.h>
end_include

begin_define
define|#
directive|define
name|TTY
value|struct sgttyb
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_BSD_TTYS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYSV_TTYS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<termio.h>
end_include

begin_define
define|#
directive|define
name|TTY
value|struct termio
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|tcsetattr
end_ifndef

begin_define
define|#
directive|define
name|tcsetattr
parameter_list|(
name|fd
parameter_list|,
name|cmd
parameter_list|,
name|arg
parameter_list|)
value|ioctl(fd, cmd, arg)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCSANOW
end_ifndef

begin_define
define|#
directive|define
name|TCSANOW
value|TCSETA
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCIFLUSH
end_ifndef

begin_define
define|#
directive|define
name|TCIFLUSH
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCOFLUSH
end_ifndef

begin_define
define|#
directive|define
name|TCOFLUSH
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|TCIOFLUSH
end_ifndef

begin_define
define|#
directive|define
name|TCIOFLUSH
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|tcflush
end_ifndef

begin_define
define|#
directive|define
name|tcflush
parameter_list|(
name|fd
parameter_list|,
name|arg
parameter_list|)
value|ioctl(fd, TCFLSH, arg)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HAVE_SYSV_TTYS */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_TERMIOS
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_TERMIOS_H
argument_list|)
end_if

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

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|HAVE_SYS_TERMIOS_H
argument_list|)
end_elif

begin_include
include|#
directive|include
file|<sys/termios.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TTY
value|struct termios
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_SYS_MODEM_H
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/modem.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Line discipline flags.  The depredated ones required line discipline  * or streams modules to be installed/loaded in the kernel and are now  * ignored.  Leave the LDISC_CLK and other deprecated symbols defined  * until 2013 or 2014 to avoid complicating the use of newer drivers on  * older ntpd, which is often as easy as dropping in the refclock *.c.  */
end_comment

begin_define
define|#
directive|define
name|LDISC_STD
value|0x000
end_define

begin_comment
comment|/* standard */
end_comment

begin_define
define|#
directive|define
name|LDISC_CLK
value|0x001
end_define

begin_comment
comment|/* depredated tty_clk \n */
end_comment

begin_define
define|#
directive|define
name|LDISC_CLKPPS
value|0x002
end_define

begin_comment
comment|/* depredated tty_clk \377 */
end_comment

begin_define
define|#
directive|define
name|LDISC_ACTS
value|0x004
end_define

begin_comment
comment|/* depredated tty_clk #* */
end_comment

begin_define
define|#
directive|define
name|LDISC_CHU
value|0x008
end_define

begin_comment
comment|/* depredated */
end_comment

begin_define
define|#
directive|define
name|LDISC_PPS
value|0x010
end_define

begin_comment
comment|/* depredated */
end_comment

begin_define
define|#
directive|define
name|LDISC_RAW
value|0x020
end_define

begin_comment
comment|/* raw binary */
end_comment

begin_define
define|#
directive|define
name|LDISC_ECHO
value|0x040
end_define

begin_comment
comment|/* enable echo */
end_comment

begin_define
define|#
directive|define
name|LDISC_REMOTE
value|0x080
end_define

begin_comment
comment|/* remote mode */
end_comment

begin_define
define|#
directive|define
name|LDISC_7O1
value|0x100
end_define

begin_comment
comment|/* 7-bit, odd parity for Z3801A */
end_comment

begin_comment
comment|/* function prototypes for ntp_tty.c */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SYS_VXWORKS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|SYS_WINNT
argument_list|)
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|HAVE_TERMIOS
argument_list|)
operator|||
name|defined
argument_list|(
name|HAVE_SYSV_TTYS
argument_list|)
operator|||
expr|\
name|defined
argument_list|(
name|HAVE_BSD_TTYS
argument_list|)
end_if

begin_function_decl
specifier|extern
name|int
name|ntp_tty_setup
parameter_list|(
name|int
parameter_list|,
name|u_int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ntp_tty_ioctl
parameter_list|(
name|int
parameter_list|,
name|u_int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_TTY_H */
end_comment

end_unit

