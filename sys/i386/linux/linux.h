begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994-1995 Søren Schmidt  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer   *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LINUX_H
end_ifndef

begin_define
define|#
directive|define
name|LINUX_H
end_define

begin_typedef
typedef|typedef
name|unsigned
name|short
name|linux_uid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|linux_gid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|linux_dev_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|linux_ino_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|linux_mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|linux_nlink_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|linux_time_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|linux_clock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|char
modifier|*
name|linux_caddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|linux_off_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|val
index|[
literal|2
index|]
decl_stmt|;
block|}
name|linux_fsid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|linux_pid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|linux_sigset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|linux_handler_t
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|void
function_decl|(
modifier|*
name|sa_handler
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
name|linux_sigset_t
name|sa_mask
decl_stmt|;
name|unsigned
name|long
name|sa_flags
decl_stmt|;
name|void
function_decl|(
modifier|*
name|sa_restorer
function_decl|)
parameter_list|(
name|void
parameter_list|)
function_decl|;
block|}
name|linux_sigaction_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|linux_key_t
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|int
name|bsd_to_linux_signal
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|linux_to_bsd_signal
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* misc defines */
end_comment

begin_define
define|#
directive|define
name|LINUX_NAME_MAX
value|255
end_define

begin_comment
comment|/* signal numbers */
end_comment

begin_define
define|#
directive|define
name|LINUX_SIGHUP
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_SIGINT
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_SIGQUIT
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_SIGILL
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_SIGTRAP
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_SIGABRT
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_SIGIOT
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_SIGUNUSED
value|7
end_define

begin_define
define|#
directive|define
name|LINUX_SIGFPE
value|8
end_define

begin_define
define|#
directive|define
name|LINUX_SIGKILL
value|9
end_define

begin_define
define|#
directive|define
name|LINUX_SIGUSR1
value|10
end_define

begin_define
define|#
directive|define
name|LINUX_SIGSEGV
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_SIGUSR2
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_SIGPIPE
value|13
end_define

begin_define
define|#
directive|define
name|LINUX_SIGALRM
value|14
end_define

begin_define
define|#
directive|define
name|LINUX_SIGTERM
value|15
end_define

begin_define
define|#
directive|define
name|LINUX_SIGSTKFLT
value|16
end_define

begin_define
define|#
directive|define
name|LINUX_SIGCHLD
value|17
end_define

begin_define
define|#
directive|define
name|LINUX_SIGCONT
value|18
end_define

begin_define
define|#
directive|define
name|LINUX_SIGSTOP
value|19
end_define

begin_define
define|#
directive|define
name|LINUX_SIGTSTP
value|20
end_define

begin_define
define|#
directive|define
name|LINUX_SIGTTIN
value|21
end_define

begin_define
define|#
directive|define
name|LINUX_SIGTTOU
value|22
end_define

begin_define
define|#
directive|define
name|LINUX_SIGIO
value|23
end_define

begin_define
define|#
directive|define
name|LINUX_SIGPOLL
value|LINUX_SIGIO
end_define

begin_define
define|#
directive|define
name|LINUX_SIGURG
value|LINUX_SIGIO
end_define

begin_define
define|#
directive|define
name|LINUX_SIGXCPU
value|24
end_define

begin_define
define|#
directive|define
name|LINUX_SIGXFSZ
value|25
end_define

begin_define
define|#
directive|define
name|LINUX_SIGVTALRM
value|26
end_define

begin_define
define|#
directive|define
name|LINUX_SIGPROF
value|27
end_define

begin_define
define|#
directive|define
name|LINUX_SIGWINCH
value|28
end_define

begin_define
define|#
directive|define
name|LINUX_SIGLOST
value|29
end_define

begin_define
define|#
directive|define
name|LINUX_SIGPWR
value|30
end_define

begin_define
define|#
directive|define
name|LINUX_SIGBUS
value|LINUX_SIGUNUSED
end_define

begin_define
define|#
directive|define
name|LINUX_NSIG
value|32
end_define

begin_comment
comment|/* sigaction flags */
end_comment

begin_define
define|#
directive|define
name|LINUX_SA_NOCLDSTOP
value|0x00000001
end_define

begin_define
define|#
directive|define
name|LINUX_SA_ONSTACK
value|0x08000000
end_define

begin_define
define|#
directive|define
name|LINUX_SA_RESTART
value|0x10000000
end_define

begin_define
define|#
directive|define
name|LINUX_SA_INTERRUPT
value|0x20000000
end_define

begin_define
define|#
directive|define
name|LINUX_SA_NOMASK
value|0x40000000
end_define

begin_define
define|#
directive|define
name|LINUX_SA_ONESHOT
value|0x80000000
end_define

begin_comment
comment|/* sigprocmask actions */
end_comment

begin_define
define|#
directive|define
name|LINUX_SIG_BLOCK
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_SIG_UNBLOCK
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_SIG_SETMASK
value|2
end_define

begin_comment
comment|/* termio commands */
end_comment

begin_define
define|#
directive|define
name|LINUX_TCGETS
value|0x5401
end_define

begin_define
define|#
directive|define
name|LINUX_TCSETS
value|0x5402
end_define

begin_define
define|#
directive|define
name|LINUX_TCSETSW
value|0x5403
end_define

begin_define
define|#
directive|define
name|LINUX_TCSETSF
value|0x5404
end_define

begin_define
define|#
directive|define
name|LINUX_TCGETA
value|0x5405
end_define

begin_define
define|#
directive|define
name|LINUX_TCSETA
value|0x5406
end_define

begin_define
define|#
directive|define
name|LINUX_TCSETAW
value|0x5407
end_define

begin_define
define|#
directive|define
name|LINUX_TCSETAF
value|0x5408
end_define

begin_define
define|#
directive|define
name|LINUX_TCSBRK
value|0x5409
end_define

begin_define
define|#
directive|define
name|LINUX_TCXONC
value|0x540A
end_define

begin_define
define|#
directive|define
name|LINUX_TCFLSH
value|0x540B
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCEXCL
value|0x540C
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCNXCL
value|0x540D
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSCTTY
value|0x540E
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCGPGRP
value|0x540F
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSPGRP
value|0x5410
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCOUTQ
value|0x5411
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSTI
value|0x5412
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCGWINSZ
value|0x5413
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSWINSZ
value|0x5414
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCMGET
value|0x5415
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCMBIS
value|0x5416
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCMBIC
value|0x5417
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCMSET
value|0x5418
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCGSOFTCAR
value|0x5419
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSSOFTCAR
value|0x541A
end_define

begin_define
define|#
directive|define
name|LINUX_FIONREAD
value|0x541B
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCINQ
value|FIONREAD
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCLINUX
value|0x541C
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCCONS
value|0x541D
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCGSERIAL
value|0x541E
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSSERIAL
value|0x541F
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCPKT
value|0x5420
end_define

begin_define
define|#
directive|define
name|LINUX_FIONBIO
value|0x5421
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCNOTTY
value|0x5422
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSETD
value|0x5423
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCGETD
value|0x5424
end_define

begin_define
define|#
directive|define
name|LINUX_TCSBRKP
value|0x5425
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCTTYGSTRUCT
value|0x5426
end_define

begin_define
define|#
directive|define
name|LINUX_FIONCLEX
value|0x5450
end_define

begin_define
define|#
directive|define
name|LINUX_FIOCLEX
value|0x5451
end_define

begin_define
define|#
directive|define
name|LINUX_FIOASYNC
value|0x5452
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSERCONFIG
value|0x5453
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSERGWILD
value|0x5454
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSERSWILD
value|0x5455
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCGLCKTRMIOS
value|0x5456
end_define

begin_define
define|#
directive|define
name|LINUX_TIOCSLCKTRMIOS
value|0x5457
end_define

begin_comment
comment|/* line disciplines */
end_comment

begin_define
define|#
directive|define
name|LINUX_N_TTY
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_N_SLIP
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_N_MOUSE
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_N_PPP
value|3
end_define

begin_comment
comment|/* Linux termio c_cc values */
end_comment

begin_define
define|#
directive|define
name|LINUX_VINTR
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_VQUIT
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_VERASE
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_VKILL
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_VEOF
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_VTIME
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_VMIN
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_VSWTC
value|7
end_define

begin_define
define|#
directive|define
name|LINUX_NCC
value|8
end_define

begin_comment
comment|/* Linux termios c_cc values */
end_comment

begin_define
define|#
directive|define
name|LINUX_VSTART
value|8
end_define

begin_define
define|#
directive|define
name|LINUX_VSTOP
value|9
end_define

begin_define
define|#
directive|define
name|LINUX_VSUSP
value|10
end_define

begin_define
define|#
directive|define
name|LINUX_VEOL
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_VREPRINT
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_VDISCARD
value|13
end_define

begin_define
define|#
directive|define
name|LINUX_VWERASE
value|14
end_define

begin_define
define|#
directive|define
name|LINUX_VLNEXT
value|15
end_define

begin_define
define|#
directive|define
name|LINUX_VEOL2
value|16
end_define

begin_define
define|#
directive|define
name|LINUX_NCCS
value|17
end_define

begin_comment
comment|/* Linux c_iflag masks */
end_comment

begin_define
define|#
directive|define
name|LINUX_IGNBRK
value|0x0000001
end_define

begin_define
define|#
directive|define
name|LINUX_BRKINT
value|0x0000002
end_define

begin_define
define|#
directive|define
name|LINUX_IGNPAR
value|0x0000004
end_define

begin_define
define|#
directive|define
name|LINUX_PARMRK
value|0x0000008
end_define

begin_define
define|#
directive|define
name|LINUX_INPCK
value|0x0000010
end_define

begin_define
define|#
directive|define
name|LINUX_ISTRIP
value|0x0000020
end_define

begin_define
define|#
directive|define
name|LINUX_INLCR
value|0x0000040
end_define

begin_define
define|#
directive|define
name|LINUX_IGNCR
value|0x0000080
end_define

begin_define
define|#
directive|define
name|LINUX_ICRNL
value|0x0000100
end_define

begin_define
define|#
directive|define
name|LINUX_IUCLC
value|0x0000200
end_define

begin_define
define|#
directive|define
name|LINUX_IXON
value|0x0000400
end_define

begin_define
define|#
directive|define
name|LINUX_IXANY
value|0x0000800
end_define

begin_define
define|#
directive|define
name|LINUX_IXOFF
value|0x0001000
end_define

begin_define
define|#
directive|define
name|LINUX_IMAXBEL
value|0x0002000
end_define

begin_comment
comment|/* Linux c_oflag masks */
end_comment

begin_define
define|#
directive|define
name|LINUX_OPOST
value|0x0000001
end_define

begin_define
define|#
directive|define
name|LINUX_OLCUC
value|0x0000002
end_define

begin_define
define|#
directive|define
name|LINUX_ONLCR
value|0x0000004
end_define

begin_define
define|#
directive|define
name|LINUX_OCRNL
value|0x0000008
end_define

begin_define
define|#
directive|define
name|LINUX_ONOCR
value|0x0000010
end_define

begin_define
define|#
directive|define
name|LINUX_ONLRET
value|0x0000020
end_define

begin_define
define|#
directive|define
name|LINUX_OFILL
value|0x0000040
end_define

begin_define
define|#
directive|define
name|LINUX_OFDEL
value|0x0000080
end_define

begin_define
define|#
directive|define
name|LINUX_NLDLY
value|0x0000100
end_define

begin_define
define|#
directive|define
name|LINUX_NL0
value|0x0000000
end_define

begin_define
define|#
directive|define
name|LINUX_NL1
value|0x0000100
end_define

begin_define
define|#
directive|define
name|LINUX_CRDLY
value|0x0000600
end_define

begin_define
define|#
directive|define
name|LINUX_CR0
value|0x0000000
end_define

begin_define
define|#
directive|define
name|LINUX_CR1
value|0x0000200
end_define

begin_define
define|#
directive|define
name|LINUX_CR2
value|0x0000400
end_define

begin_define
define|#
directive|define
name|LINUX_CR3
value|0x0000600
end_define

begin_define
define|#
directive|define
name|LINUX_TABDLY
value|0x0001800
end_define

begin_define
define|#
directive|define
name|LINUX_TAB0
value|0x0000000
end_define

begin_define
define|#
directive|define
name|LINUX_TAB1
value|0x0000800
end_define

begin_define
define|#
directive|define
name|LINUX_TAB2
value|0x0001000
end_define

begin_define
define|#
directive|define
name|LINUX_TAB3
value|0x0001800
end_define

begin_define
define|#
directive|define
name|LINUX_XTABS
value|0x0001800
end_define

begin_define
define|#
directive|define
name|LINUX_BSDLY
value|0x0002000
end_define

begin_define
define|#
directive|define
name|LINUX_BS0
value|0x0000000
end_define

begin_define
define|#
directive|define
name|LINUX_BS1
value|0x0002000
end_define

begin_define
define|#
directive|define
name|LINUX_VTDLY
value|0x0004000
end_define

begin_define
define|#
directive|define
name|LINUX_VT0
value|0x0000000
end_define

begin_define
define|#
directive|define
name|LINUX_VT1
value|0x0004000
end_define

begin_define
define|#
directive|define
name|LINUX_FFDLY
value|0x0008000
end_define

begin_define
define|#
directive|define
name|LINUX_FF0
value|0x0000000
end_define

begin_define
define|#
directive|define
name|LINUX_FF1
value|0x0008000
end_define

begin_define
define|#
directive|define
name|LINUX_CBAUD
value|0x0000100f
end_define

begin_define
define|#
directive|define
name|LINUX_B0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|LINUX_B50
value|0x00000001
end_define

begin_define
define|#
directive|define
name|LINUX_B75
value|0x00000002
end_define

begin_define
define|#
directive|define
name|LINUX_B110
value|0x00000003
end_define

begin_define
define|#
directive|define
name|LINUX_B134
value|0x00000004
end_define

begin_define
define|#
directive|define
name|LINUX_B150
value|0x00000005
end_define

begin_define
define|#
directive|define
name|LINUX_B200
value|0x00000006
end_define

begin_define
define|#
directive|define
name|LINUX_B300
value|0x00000007
end_define

begin_define
define|#
directive|define
name|LINUX_B600
value|0x00000008
end_define

begin_define
define|#
directive|define
name|LINUX_B1200
value|0x00000009
end_define

begin_define
define|#
directive|define
name|LINUX_B1800
value|0x0000000a
end_define

begin_define
define|#
directive|define
name|LINUX_B2400
value|0x0000000b
end_define

begin_define
define|#
directive|define
name|LINUX_B4800
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|LINUX_B9600
value|0x0000000d
end_define

begin_define
define|#
directive|define
name|LINUX_B19200
value|0x0000000e
end_define

begin_define
define|#
directive|define
name|LINUX_B38400
value|0x0000000f
end_define

begin_define
define|#
directive|define
name|LINUX_EXTA
value|LINUX_B19200
end_define

begin_define
define|#
directive|define
name|LINUX_EXTB
value|LINUX_B38400
end_define

begin_define
define|#
directive|define
name|LINUX_CBAUDEX
value|0x00001000
end_define

begin_define
define|#
directive|define
name|LINUX_B57600
value|0x00001001
end_define

begin_define
define|#
directive|define
name|LINUX_B115200
value|0x00001002
end_define

begin_define
define|#
directive|define
name|LINUX_CSIZE
value|0x00000030
end_define

begin_define
define|#
directive|define
name|LINUX_CS5
value|0x00000000
end_define

begin_define
define|#
directive|define
name|LINUX_CS6
value|0x00000010
end_define

begin_define
define|#
directive|define
name|LINUX_CS7
value|0x00000020
end_define

begin_define
define|#
directive|define
name|LINUX_CS8
value|0x00000030
end_define

begin_define
define|#
directive|define
name|LINUX_CSTOPB
value|0x00000040
end_define

begin_define
define|#
directive|define
name|LINUX_CREAD
value|0x00000080
end_define

begin_define
define|#
directive|define
name|LINUX_PARENB
value|0x00000100
end_define

begin_define
define|#
directive|define
name|LINUX_PARODD
value|0x00000200
end_define

begin_define
define|#
directive|define
name|LINUX_HUPCL
value|0x00000400
end_define

begin_define
define|#
directive|define
name|LINUX_CLOCAL
value|0x00000800
end_define

begin_define
define|#
directive|define
name|LINUX_CRTSCTS
value|0x80000000
end_define

begin_comment
comment|/* Linux c_lflag masks */
end_comment

begin_define
define|#
directive|define
name|LINUX_ISIG
value|0x00000001
end_define

begin_define
define|#
directive|define
name|LINUX_ICANON
value|0x00000002
end_define

begin_define
define|#
directive|define
name|LINUX_XCASE
value|0x00000004
end_define

begin_define
define|#
directive|define
name|LINUX_ECHO
value|0x00000008
end_define

begin_define
define|#
directive|define
name|LINUX_ECHOE
value|0x00000010
end_define

begin_define
define|#
directive|define
name|LINUX_ECHOK
value|0x00000020
end_define

begin_define
define|#
directive|define
name|LINUX_ECHONL
value|0x00000040
end_define

begin_define
define|#
directive|define
name|LINUX_NOFLSH
value|0x00000080
end_define

begin_define
define|#
directive|define
name|LINUX_TOSTOP
value|0x00000100
end_define

begin_define
define|#
directive|define
name|LINUX_ECHOCTL
value|0x00000200
end_define

begin_define
define|#
directive|define
name|LINUX_ECHOPRT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|LINUX_ECHOKE
value|0x00000800
end_define

begin_define
define|#
directive|define
name|LINUX_FLUSHO
value|0x00001000
end_define

begin_define
define|#
directive|define
name|LINUX_PENDIN
value|0x00002000
end_define

begin_define
define|#
directive|define
name|LINUX_IEXTEN
value|0x00008000
end_define

begin_comment
comment|/* open/fcntl flags */
end_comment

begin_define
define|#
directive|define
name|LINUX_O_RDONLY
value|00
end_define

begin_define
define|#
directive|define
name|LINUX_O_WRONLY
value|01
end_define

begin_define
define|#
directive|define
name|LINUX_O_RDWR
value|02
end_define

begin_define
define|#
directive|define
name|LINUX_O_CREAT
value|0100
end_define

begin_define
define|#
directive|define
name|LINUX_O_EXCL
value|0200
end_define

begin_define
define|#
directive|define
name|LINUX_O_NOCTTY
value|0400
end_define

begin_define
define|#
directive|define
name|LINUX_O_TRUNC
value|01000
end_define

begin_define
define|#
directive|define
name|LINUX_O_APPEND
value|02000
end_define

begin_define
define|#
directive|define
name|LINUX_O_NONBLOCK
value|04000
end_define

begin_define
define|#
directive|define
name|LINUX_O_NDELAY
value|LINUX_O_NONBLOCK
end_define

begin_define
define|#
directive|define
name|LINUX_O_SYNC
value|010000
end_define

begin_define
define|#
directive|define
name|LINUX_FASYNC
value|020000
end_define

begin_comment
comment|/* fcntl flags */
end_comment

begin_define
define|#
directive|define
name|LINUX_F_DUPFD
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_F_GETFD
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETFD
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_F_GETFL
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETFL
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_F_GETLK
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETLK
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETLKW
value|7
end_define

begin_define
define|#
directive|define
name|LINUX_F_SETOWN
value|8
end_define

begin_define
define|#
directive|define
name|LINUX_F_GETOWN
value|9
end_define

begin_define
define|#
directive|define
name|LINUX_F_RDLCK
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_F_WRLCK
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_F_UNLCK
value|2
end_define

begin_comment
comment|/* mmap options */
end_comment

begin_define
define|#
directive|define
name|LINUX_MAP_SHARED
value|0x0001
end_define

begin_define
define|#
directive|define
name|LINUX_MAP_PRIVATE
value|0x0002
end_define

begin_define
define|#
directive|define
name|LINUX_MAP_FIXED
value|0x0010
end_define

begin_define
define|#
directive|define
name|LINUX_MAP_ANON
value|0x0020
end_define

begin_comment
comment|/* SystemV ipc defines */
end_comment

begin_define
define|#
directive|define
name|LINUX_SEMOP
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_SEMGET
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_SEMCTL
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_MSGSND
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_MSGRCV
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_MSGGET
value|13
end_define

begin_define
define|#
directive|define
name|LINUX_MSGCTL
value|14
end_define

begin_define
define|#
directive|define
name|LINUX_SHMAT
value|21
end_define

begin_define
define|#
directive|define
name|LINUX_SHMDT
value|22
end_define

begin_define
define|#
directive|define
name|LINUX_SHMGET
value|23
end_define

begin_define
define|#
directive|define
name|LINUX_SHMCTL
value|24
end_define

begin_define
define|#
directive|define
name|LINUX_IPC_RMID
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_IPC_SET
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_IPC_STAT
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_IPC_INFO
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_LOCK
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_UNLOCK
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_STAT
value|13
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_INFO
value|14
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_RDONLY
value|0x1000
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_RND
value|0x2000
end_define

begin_define
define|#
directive|define
name|LINUX_SHM_REMAP
value|0x4000
end_define

begin_comment
comment|/* Socket defines */
end_comment

begin_define
define|#
directive|define
name|LINUX_SOCKET
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_BIND
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_CONNECT
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_LISTEN
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_ACCEPT
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_GETSOCKNAME
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_GETPEERNAME
value|7
end_define

begin_define
define|#
directive|define
name|LINUX_SOCKETPAIR
value|8
end_define

begin_define
define|#
directive|define
name|LINUX_SEND
value|9
end_define

begin_define
define|#
directive|define
name|LINUX_RECV
value|10
end_define

begin_define
define|#
directive|define
name|LINUX_SENDTO
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_RECVFROM
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_SHUTDOWN
value|13
end_define

begin_define
define|#
directive|define
name|LINUX_SETSOCKOPT
value|14
end_define

begin_define
define|#
directive|define
name|LINUX_GETSOCKOPT
value|15
end_define

begin_define
define|#
directive|define
name|LINUX_AF_UNSPEC
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_AF_UNIX
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_AF_INET
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_AF_AX25
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_AF_IPX
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_AF_APPLETALK
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_SOL_SOCKET
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_SOL_IP
value|0
end_define

begin_define
define|#
directive|define
name|LINUX_SOL_IPX
value|256
end_define

begin_define
define|#
directive|define
name|LINUX_SOL_AX25
value|257
end_define

begin_define
define|#
directive|define
name|LINUX_SOL_TCP
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_SOL_UDP
value|17
end_define

begin_define
define|#
directive|define
name|LINUX_SO_DEBUG
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_SO_REUSEADDR
value|2
end_define

begin_define
define|#
directive|define
name|LINUX_SO_TYPE
value|3
end_define

begin_define
define|#
directive|define
name|LINUX_SO_ERROR
value|4
end_define

begin_define
define|#
directive|define
name|LINUX_SO_DONTROUTE
value|5
end_define

begin_define
define|#
directive|define
name|LINUX_SO_BROADCAST
value|6
end_define

begin_define
define|#
directive|define
name|LINUX_SO_SNDBUF
value|7
end_define

begin_define
define|#
directive|define
name|LINUX_SO_RCVBUF
value|8
end_define

begin_define
define|#
directive|define
name|LINUX_SO_KEEPALIVE
value|9
end_define

begin_define
define|#
directive|define
name|LINUX_SO_OOBINLINE
value|10
end_define

begin_define
define|#
directive|define
name|LINUX_SO_NO_CHECK
value|11
end_define

begin_define
define|#
directive|define
name|LINUX_SO_PRIORITY
value|12
end_define

begin_define
define|#
directive|define
name|LINUX_SO_LINGER
value|13
end_define

begin_define
define|#
directive|define
name|LINUX_IP_TOS
value|1
end_define

begin_define
define|#
directive|define
name|LINUX_IP_TTL
value|2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LINUX_H */
end_comment

end_unit

