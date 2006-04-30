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

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|SYSV_TTYS
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|STREAM
argument_list|)
operator|&
operator|!
name|defined
argument_list|(
name|BSD_TTYS
argument_list|)
end_if

begin_define
define|#
directive|define
name|BSD_TTYS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYSV_TTYS STREAM BSD_TTYS */
end_comment

begin_comment
comment|/*  * Line discipline flags. These require line discipline or streams  * modules to be installed/loaded in the kernel. If specified, but not  * installed, the code runs as if unspecified.  */
end_comment

begin_define
define|#
directive|define
name|LDISC_STD
value|0x0
end_define

begin_comment
comment|/* standard */
end_comment

begin_define
define|#
directive|define
name|LDISC_CLK
value|0x1
end_define

begin_comment
comment|/* tty_clk \n intercept */
end_comment

begin_define
define|#
directive|define
name|LDISC_CLKPPS
value|0x2
end_define

begin_comment
comment|/* tty_clk \377 intercept */
end_comment

begin_define
define|#
directive|define
name|LDISC_ACTS
value|0x4
end_define

begin_comment
comment|/* tty_clk #* intercept */
end_comment

begin_define
define|#
directive|define
name|LDISC_CHU
value|0x8
end_define

begin_comment
comment|/* depredated */
end_comment

begin_define
define|#
directive|define
name|LDISC_PPS
value|0x10
end_define

begin_comment
comment|/* ppsclock, ppsapi */
end_comment

begin_define
define|#
directive|define
name|LDISC_RAW
value|0x20
end_define

begin_comment
comment|/* raw binary */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_TTY_H */
end_comment

end_unit

