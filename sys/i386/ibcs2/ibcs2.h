begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1994 Søren Schmidt  * Copyright (c) 1994 Sean Eric Fagan  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer  *    in this position and unchanged.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software withough specific prior written permission  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* trace all iBCS2 system calls */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|ibcs2_trace
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* convert signals between bsd& iBCS2 */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|bsd_to_ibcs2_signal
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|ibcs2_to_bsd_signal
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
name|char
modifier|*
name|ibcs2_sig_to_str
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* iBCS2 type definitions */
end_comment

begin_typedef
typedef|typedef
name|char
modifier|*
name|ibcs2_caddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|ibcs2_daddr_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|ibcs2_off_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|ibcs2_key_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|ibcs2_uid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ibcs2_x_uid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|ibcs2_gid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ibcs2_x_gid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|ibcs2_nlink_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ibcs2_x_nlink_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|ibcs2_dev_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|ibcs2_x_dev_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|ibcs2_ino_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ibcs2_x_ino_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|ibcs2_mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ibcs2_x_mode_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|ibcs2_pid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|ibcs2_x_pid_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|ibcs2_size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|ibcs2_time_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|timespec
name|ibcs2_timestruc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|ibcs2_clock_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|ibcs2_sigset_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
function_decl|(
modifier|*
name|ibcs2_sig_t
function_decl|)
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* misc defines */
end_comment

begin_define
define|#
directive|define
name|UA_ALLOC
parameter_list|()
define|\
value|(ALIGN(((caddr_t)PS_STRINGS) - SPARE_USRSPACE))
end_define

begin_define
define|#
directive|define
name|IBCS2_RETVAL_SIZE
value|(3 * sizeof(int))
end_define

begin_define
define|#
directive|define
name|IBCS2_MAGIC_IN
value|0xe215
end_define

begin_define
define|#
directive|define
name|IBCS2_MAGIC_OUT
value|0x8e11
end_define

begin_define
define|#
directive|define
name|IBCS2_MAGIC_RETURN
parameter_list|(
name|arg
parameter_list|)
value|*(((int *)arg) - 3) = IBCS2_MAGIC_OUT; \ 				*(((int *)arg) - 2) = retval[0]; \ 				*(((int *)arg) - 1) = retval[1]; \ 				return(0);
end_define

begin_comment
comment|/* iBCS2 signal numbers */
end_comment

begin_define
define|#
directive|define
name|IBCS2_SIGHUP
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGINT
value|2
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGQUIT
value|3
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGILL
value|4
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGTRAP
value|5
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGIOT
value|6
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGABRT
value|6
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGEMT
value|7
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGFPE
value|8
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGKILL
value|9
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGBUS
value|10
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGSEGV
value|11
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGSYS
value|12
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGPIPE
value|13
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGALRM
value|14
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGTERM
value|15
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGUSR1
value|16
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGUSR2
value|17
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGCLD
value|18
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGCHLD
value|18
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGPWR
value|19
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGWINCH
value|20
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGURG
value|21
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGPOLL
value|22
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGIO
value|22
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGSTOP
value|23
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGTSTP
value|24
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGCONT
value|25
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGTTIN
value|26
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGTTOU
value|27
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGVTALRM
value|28
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGPROF
value|29
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGGXCPU
value|30
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGGXFSZ
value|31
end_define

begin_define
define|#
directive|define
name|IBCS2_NSIG
value|32
end_define

begin_define
define|#
directive|define
name|IBCS2_SIGMASK
value|0xFF
end_define

begin_define
define|#
directive|define
name|IBCS2_SA_NOCLDSTOP
value|0x01
end_define

begin_define
define|#
directive|define
name|IBCS2_SIG_DFL
value|(void (*)())0
end_define

begin_define
define|#
directive|define
name|IBCS2_SIG_IGN
value|(void (*)())1
end_define

begin_define
define|#
directive|define
name|IBCS2_SIG_HOLD
value|(void (*)())2
end_define

begin_comment
comment|/* iBCS2 open& fcntl file modes */
end_comment

begin_define
define|#
directive|define
name|IBCS2_RDONLY
value|0x000
end_define

begin_define
define|#
directive|define
name|IBCS2_WRONLY
value|0x001
end_define

begin_define
define|#
directive|define
name|IBCS2_RDWR
value|0x002
end_define

begin_define
define|#
directive|define
name|IBCS2_NDELAY
value|0x004
end_define

begin_define
define|#
directive|define
name|IBCS2_APPEND
value|0x008
end_define

begin_define
define|#
directive|define
name|IBCS2_SYNC
value|0x010
end_define

begin_define
define|#
directive|define
name|IBCS2_NONBLOCK
value|0x080
end_define

begin_define
define|#
directive|define
name|IBCS2_CREAT
value|0x100
end_define

begin_define
define|#
directive|define
name|IBCS2_TRUNC
value|0x200
end_define

begin_define
define|#
directive|define
name|IBCS2_EXCL
value|0x400
end_define

begin_define
define|#
directive|define
name|IBCS2_NOCTTY
value|0x800
end_define

begin_define
define|#
directive|define
name|IBCS2_PRIV
value|0x1000
end_define

begin_comment
comment|/* iBCS2 fcntl commands */
end_comment

begin_define
define|#
directive|define
name|IBCS2_F_DUPFD
value|0
end_define

begin_define
define|#
directive|define
name|IBCS2_F_GETFD
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_F_SETFD
value|2
end_define

begin_define
define|#
directive|define
name|IBCS2_F_GETFL
value|3
end_define

begin_define
define|#
directive|define
name|IBCS2_F_SETFL
value|4
end_define

begin_define
define|#
directive|define
name|IBCS2_F_GETLK
value|5
end_define

begin_define
define|#
directive|define
name|IBCS2_F_SETLK
value|6
end_define

begin_define
define|#
directive|define
name|IBCS2_F_SETLKW
value|7
end_define

begin_define
define|#
directive|define
name|IBCS2_F_RDLCK
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_F_WRLCK
value|2
end_define

begin_define
define|#
directive|define
name|IBCS2_F_UNLCK
value|3
end_define

begin_comment
comment|/* iBCS2 poll commands */
end_comment

begin_define
define|#
directive|define
name|IBCS2_POLLIN
value|0x0001
end_define

begin_define
define|#
directive|define
name|IBCS2_POLLPRI
value|0x0002
end_define

begin_define
define|#
directive|define
name|IBCS2_POLLOUT
value|0x0004
end_define

begin_define
define|#
directive|define
name|IBCS2_POLLERR
value|0x0008
end_define

begin_define
define|#
directive|define
name|IBCS2_POLLHUP
value|0x0010
end_define

begin_define
define|#
directive|define
name|IBCS2_POLLNVAL
value|0x0020
end_define

begin_define
define|#
directive|define
name|IBCS2_POLLRDNORM
value|0x0040
end_define

begin_define
define|#
directive|define
name|IBCS2_POLLWRNORM
value|0x0004
end_define

begin_define
define|#
directive|define
name|IBCS2_POLLRDBAND
value|0x0080
end_define

begin_define
define|#
directive|define
name|IBCS2_POLLWRBAND
value|0x0100
end_define

begin_define
define|#
directive|define
name|IBCS2_READPOLL
value|(IBCS2_POLLIN|IBCS2_POLLRDNORM|IBCS2_POLLRDBAND)
end_define

begin_define
define|#
directive|define
name|IBCS2_WRITEPOLL
value|(IBCS2_POLLOUT|IBCS2_POLLWRNORM|IBCS2_POLLWRBAND)
end_define

begin_comment
comment|/* iBCS2 termio input modes */
end_comment

begin_define
define|#
directive|define
name|IBCS2_IGNBRK
value|0x0001
end_define

begin_define
define|#
directive|define
name|IBCS2_BRKINT
value|0x0002
end_define

begin_define
define|#
directive|define
name|IBCS2_IGNPAR
value|0x0004
end_define

begin_define
define|#
directive|define
name|IBCS2_PARMRK
value|0x0008
end_define

begin_define
define|#
directive|define
name|IBCS2_INPCK
value|0x0010
end_define

begin_define
define|#
directive|define
name|IBCS2_ISTRIP
value|0x0020
end_define

begin_define
define|#
directive|define
name|IBCS2_INLCR
value|0x0040
end_define

begin_define
define|#
directive|define
name|IBCS2_IGNCR
value|0x0080
end_define

begin_define
define|#
directive|define
name|IBCS2_ICRNL
value|0x0100
end_define

begin_define
define|#
directive|define
name|IBCS2_IUCLC
value|0x0200
end_define

begin_define
define|#
directive|define
name|IBCS2_IXON
value|0x0400
end_define

begin_define
define|#
directive|define
name|IBCS2_IXANY
value|0x0800
end_define

begin_define
define|#
directive|define
name|IBCS2_IXOFF
value|0x1000
end_define

begin_define
define|#
directive|define
name|IBCS2_DOSMODE
value|0x8000
end_define

begin_comment
comment|/* iBCS2 termio output modes */
end_comment

begin_define
define|#
directive|define
name|IBCS2_OPOST
value|0x0001
end_define

begin_define
define|#
directive|define
name|IBCS2_OLCUC
value|0x0002
end_define

begin_define
define|#
directive|define
name|IBCS2_ONLCR
value|0x0004
end_define

begin_define
define|#
directive|define
name|IBCS2_OCRNL
value|0x0008
end_define

begin_define
define|#
directive|define
name|IBCS2_ONOCR
value|0x0010
end_define

begin_define
define|#
directive|define
name|IBCS2_ONLRET
value|0x0020
end_define

begin_define
define|#
directive|define
name|IBCS2_OFILL
value|0x0040
end_define

begin_define
define|#
directive|define
name|IBCS2_OFDEL
value|0x0080
end_define

begin_define
define|#
directive|define
name|IBCS2_NL1
value|0x0100
end_define

begin_define
define|#
directive|define
name|IBCS2_CR1
value|0x0200
end_define

begin_define
define|#
directive|define
name|IBCS2_CR2
value|0x0400
end_define

begin_define
define|#
directive|define
name|IBCS2_TAB1
value|0x0800
end_define

begin_define
define|#
directive|define
name|IBCS2_TAB2
value|0x1000
end_define

begin_define
define|#
directive|define
name|IBCS2_BS1
value|0x2000
end_define

begin_define
define|#
directive|define
name|IBCS2_VT1
value|0x4000
end_define

begin_define
define|#
directive|define
name|IBCS2_FF1
value|0x8000
end_define

begin_comment
comment|/* iBCS2 termio control modes */
end_comment

begin_define
define|#
directive|define
name|IBCS2_CBAUD
value|0x000F
end_define

begin_define
define|#
directive|define
name|IBCS2_B0
value|0x0
end_define

begin_define
define|#
directive|define
name|IBCS2_B50
value|0x0001
end_define

begin_define
define|#
directive|define
name|IBCS2_B75
value|0x0002
end_define

begin_define
define|#
directive|define
name|IBCS2_B110
value|0x0003
end_define

begin_define
define|#
directive|define
name|IBCS2_B134
value|0x0004
end_define

begin_define
define|#
directive|define
name|IBCS2_B150
value|0x0005
end_define

begin_define
define|#
directive|define
name|IBCS2_B200
value|0x0006
end_define

begin_define
define|#
directive|define
name|IBCS2_B300
value|0x0007
end_define

begin_define
define|#
directive|define
name|IBCS2_B600
value|0x0008
end_define

begin_define
define|#
directive|define
name|IBCS2_B1200
value|0x0009
end_define

begin_define
define|#
directive|define
name|IBCS2_B1800
value|0x000A
end_define

begin_define
define|#
directive|define
name|IBCS2_B2400
value|0x000B
end_define

begin_define
define|#
directive|define
name|IBCS2_B4800
value|0x000C
end_define

begin_define
define|#
directive|define
name|IBCS2_B9600
value|0x000D
end_define

begin_define
define|#
directive|define
name|IBCS2_B19200
value|0x000E
end_define

begin_define
define|#
directive|define
name|IBCS2_B38400
value|0x000F
end_define

begin_define
define|#
directive|define
name|IBCS2_CSIZE
value|0x0030
end_define

begin_define
define|#
directive|define
name|IBCS2_CS5
value|0x0
end_define

begin_define
define|#
directive|define
name|IBCS2_CS6
value|0x0010
end_define

begin_define
define|#
directive|define
name|IBCS2_CS7
value|0x0020
end_define

begin_define
define|#
directive|define
name|IBCS2_CS8
value|0x0030
end_define

begin_define
define|#
directive|define
name|IBCS2_CSTOPB
value|0x0040
end_define

begin_define
define|#
directive|define
name|IBCS2_CREAD
value|0x0080
end_define

begin_define
define|#
directive|define
name|IBCS2_PARENB
value|0x0100
end_define

begin_define
define|#
directive|define
name|IBCS2_PARODD
value|0x0200
end_define

begin_define
define|#
directive|define
name|IBCS2_HUPCL
value|0x0400
end_define

begin_define
define|#
directive|define
name|IBCS2_CLOCAL
value|0x0800
end_define

begin_define
define|#
directive|define
name|IBCS2_RCV1EN
value|0x1000
end_define

begin_define
define|#
directive|define
name|IBCS2_XMT1EN
value|0x2000
end_define

begin_define
define|#
directive|define
name|IBCS2_LOBLK
value|0x4000
end_define

begin_define
define|#
directive|define
name|IBCS2_XCLUDE
value|0x8000
end_define

begin_comment
comment|/* iBCS2 termio line discipline 0 modes */
end_comment

begin_define
define|#
directive|define
name|IBCS2_ISIG
value|0x0001
end_define

begin_define
define|#
directive|define
name|IBCS2_ICANON
value|0x0002
end_define

begin_define
define|#
directive|define
name|IBCS2_XCASE
value|0x0004
end_define

begin_define
define|#
directive|define
name|IBCS2_ECHO
value|0x0008
end_define

begin_define
define|#
directive|define
name|IBCS2_ECHOE
value|0x0010
end_define

begin_define
define|#
directive|define
name|IBCS2_ECHOK
value|0x0020
end_define

begin_define
define|#
directive|define
name|IBCS2_ECHONL
value|0x0040
end_define

begin_define
define|#
directive|define
name|IBCS2_NOFLSH
value|0x0080
end_define

begin_comment
comment|/* iBCS2 control characters */
end_comment

begin_define
define|#
directive|define
name|IBCS2_VINTR
value|0
end_define

begin_define
define|#
directive|define
name|IBCS2_VQUIT
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_VERASE
value|2
end_define

begin_define
define|#
directive|define
name|IBCS2_VKILL
value|3
end_define

begin_define
define|#
directive|define
name|IBCS2_VEOF
value|4
end_define

begin_comment
comment|/* ICANON */
end_comment

begin_define
define|#
directive|define
name|IBCS2_VEOL
value|5
end_define

begin_comment
comment|/* ICANON */
end_comment

begin_define
define|#
directive|define
name|IBCS2_VEOL2
value|6
end_define

begin_define
define|#
directive|define
name|IBCS2_VSWTCH
value|7
end_define

begin_define
define|#
directive|define
name|IBCS2_VMIN
value|4
end_define

begin_comment
comment|/* !ICANON */
end_comment

begin_define
define|#
directive|define
name|IBCS2_VTIME
value|5
end_define

begin_comment
comment|/* !ICANON */
end_comment

begin_define
define|#
directive|define
name|IBCS2_VSUSP
value|10
end_define

begin_define
define|#
directive|define
name|IBCS2_VSTART
value|11
end_define

begin_define
define|#
directive|define
name|IBCS2_VSTOP
value|12
end_define

begin_define
define|#
directive|define
name|IBCS2_NCC
value|8
end_define

begin_comment
comment|/* termio */
end_comment

begin_define
define|#
directive|define
name|IBCS2_NCCS
value|13
end_define

begin_comment
comment|/* termios */
end_comment

begin_comment
comment|/* iBCS2 ulimit commands */
end_comment

begin_define
define|#
directive|define
name|IBCS2_GETFSIZE
value|1
end_define

begin_define
define|#
directive|define
name|IBCS2_SETFSIZE
value|2
end_define

begin_define
define|#
directive|define
name|IBCS2_GETPSIZE
value|3
end_define

begin_define
define|#
directive|define
name|IBCS2_GETMOPEN
value|4
end_define

begin_comment
comment|/* iBCS2 emulator trace control */
end_comment

begin_define
define|#
directive|define
name|IBCS2_TRACE_FILE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|IBCS2_TRACE_IOCTL
value|0x00000002
end_define

begin_define
define|#
directive|define
name|IBCS2_TRACE_ISC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|IBCS2_TRACE_MISC
value|0x00000008
end_define

begin_define
define|#
directive|define
name|IBCS2_TRACE_SIGNAL
value|0x00000010
end_define

begin_define
define|#
directive|define
name|IBCS2_TRACE_STATS
value|0x00000020
end_define

begin_define
define|#
directive|define
name|IBCS2_TRACE_XENIX
value|0x00000040
end_define

begin_define
define|#
directive|define
name|IBCS2_TRACE_IOCTLCNV
value|0x00000080
end_define

begin_define
define|#
directive|define
name|IBCS2_TRACE_COFF
value|0x01000000
end_define

begin_define
define|#
directive|define
name|IBCS2_TRACE_ELF
value|0x02000000
end_define

begin_define
define|#
directive|define
name|IBCS2_TRACE_ALL
value|0x0300007f
end_define

begin_define
define|#
directive|define
name|IBCS2_FP_NO
value|0
end_define

begin_comment
comment|/* no fp support */
end_comment

begin_define
define|#
directive|define
name|IBCS2_FP_SW
value|1
end_define

begin_comment
comment|/* software emulator */
end_comment

begin_define
define|#
directive|define
name|IBCS2_FP_287
value|2
end_define

begin_comment
comment|/* 80287 FPU */
end_comment

begin_define
define|#
directive|define
name|IBCS2_FP_387
value|3
end_define

begin_comment
comment|/* 80387 FPU */
end_comment

end_unit

