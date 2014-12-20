begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|NTP_WIN_TERMIOS_H
end_ifndef

begin_define
define|#
directive|define
name|NTP_WIN_TERMIOS_H
end_define

begin_comment
comment|/*  Flag definitions for compatibility  *  ================================== */
end_comment

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_define
define|#
directive|define
name|NCCS
value|18
end_define

begin_comment
comment|/* refclock_arc.c uses VTIME (17) */
end_comment

begin_define
define|#
directive|define
name|VEOL
value|3
end_define

begin_typedef
typedef|typedef
name|unsigned
name|char
name|cc_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|speed_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|tcflag_t
typedef|;
end_typedef

begin_struct
struct|struct
name|termios
block|{
name|tcflag_t
name|c_iflag
decl_stmt|;
comment|/* input mode flags */
name|tcflag_t
name|c_oflag
decl_stmt|;
comment|/* output mode flags */
name|tcflag_t
name|c_cflag
decl_stmt|;
comment|/* control mode flags */
name|tcflag_t
name|c_lflag
decl_stmt|;
comment|/* local mode flags */
name|cc_t
name|c_line
decl_stmt|;
comment|/* line discipline */
name|cc_t
name|c_cc
index|[
name|NCCS
index|]
decl_stmt|;
comment|/* control characters */
name|speed_t
name|c_ispeed
decl_stmt|;
comment|/* input speed */
name|speed_t
name|c_ospeed
decl_stmt|;
comment|/* output speed */
block|}
struct|;
end_struct

begin_comment
comment|/* c_cc characters  #define VINTR 0 #define VQUIT 1 #define VERASE 2 #define VKILL 3 #define VEOF 4 #define VTIME 5 #define VMIN 6 #define VSWTC 7 #define VSTART 8 #define VSTOP 9 #define VSUSP 10 #define VEOL 11 #define VREPRINT 12 #define VDISCARD 13 #define VWERASE 14 #define VLNEXT 15 #define VEOL2 16 */
end_comment

begin_comment
comment|/* c_iflag bits */
end_comment

begin_define
define|#
directive|define
name|IGNBRK
value|0000001
end_define

begin_define
define|#
directive|define
name|BRKINT
value|0000002
end_define

begin_define
define|#
directive|define
name|IGNPAR
value|0000004
end_define

begin_define
define|#
directive|define
name|PARMRK
value|0000010
end_define

begin_define
define|#
directive|define
name|INPCK
value|0000020
end_define

begin_define
define|#
directive|define
name|ISTRIP
value|0000040
end_define

begin_define
define|#
directive|define
name|INLCR
value|0000100
end_define

begin_define
define|#
directive|define
name|IGNCR
value|0000200
end_define

begin_define
define|#
directive|define
name|ICRNL
value|0000400
end_define

begin_define
define|#
directive|define
name|IUCLC
value|0001000
end_define

begin_define
define|#
directive|define
name|IXON
value|0002000
end_define

begin_define
define|#
directive|define
name|IXANY
value|0004000
end_define

begin_define
define|#
directive|define
name|IXOFF
value|0010000
end_define

begin_define
define|#
directive|define
name|IMAXBEL
value|0020000
end_define

begin_comment
comment|/* c_oflag bits */
end_comment

begin_define
define|#
directive|define
name|OPOST
value|0000001
end_define

begin_define
define|#
directive|define
name|OLCUC
value|0000002
end_define

begin_define
define|#
directive|define
name|ONLCR
value|0000004
end_define

begin_define
define|#
directive|define
name|OCRNL
value|0000010
end_define

begin_define
define|#
directive|define
name|ONOCR
value|0000020
end_define

begin_define
define|#
directive|define
name|ONLRET
value|0000040
end_define

begin_define
define|#
directive|define
name|OFILL
value|0000100
end_define

begin_define
define|#
directive|define
name|OFDEL
value|0000200
end_define

begin_define
define|#
directive|define
name|NLDLY
value|0000400
end_define

begin_define
define|#
directive|define
name|NL0
value|0000000
end_define

begin_define
define|#
directive|define
name|NL1
value|0000400
end_define

begin_define
define|#
directive|define
name|CRDLY
value|0003000
end_define

begin_define
define|#
directive|define
name|CR0
value|0000000
end_define

begin_define
define|#
directive|define
name|CR1
value|0001000
end_define

begin_define
define|#
directive|define
name|CR2
value|0002000
end_define

begin_define
define|#
directive|define
name|CR3
value|0003000
end_define

begin_define
define|#
directive|define
name|TABDLY
value|0014000
end_define

begin_define
define|#
directive|define
name|TAB0
value|0000000
end_define

begin_define
define|#
directive|define
name|TAB1
value|0004000
end_define

begin_define
define|#
directive|define
name|TAB2
value|0010000
end_define

begin_define
define|#
directive|define
name|TAB3
value|0014000
end_define

begin_define
define|#
directive|define
name|XTABS
value|0014000
end_define

begin_define
define|#
directive|define
name|BSDLY
value|0020000
end_define

begin_define
define|#
directive|define
name|BS0
value|0000000
end_define

begin_define
define|#
directive|define
name|BS1
value|0020000
end_define

begin_define
define|#
directive|define
name|VTDLY
value|0040000
end_define

begin_define
define|#
directive|define
name|VT0
value|0000000
end_define

begin_define
define|#
directive|define
name|VT1
value|0040000
end_define

begin_define
define|#
directive|define
name|FFDLY
value|0100000
end_define

begin_define
define|#
directive|define
name|FF0
value|0000000
end_define

begin_define
define|#
directive|define
name|FF1
value|0100000
end_define

begin_comment
comment|/* c_cflag bit meaning */
end_comment

begin_define
define|#
directive|define
name|CBAUD
value|0010017
end_define

begin_define
define|#
directive|define
name|B0
value|0000000
end_define

begin_comment
comment|/* hang up */
end_comment

begin_define
define|#
directive|define
name|B50
value|0000001
end_define

begin_define
define|#
directive|define
name|B75
value|0000002
end_define

begin_define
define|#
directive|define
name|B110
value|0000003
end_define

begin_define
define|#
directive|define
name|B134
value|0000004
end_define

begin_define
define|#
directive|define
name|B150
value|0000005
end_define

begin_define
define|#
directive|define
name|B200
value|0000006
end_define

begin_define
define|#
directive|define
name|B300
value|0000007
end_define

begin_define
define|#
directive|define
name|B600
value|0000010
end_define

begin_define
define|#
directive|define
name|B1200
value|0000011
end_define

begin_define
define|#
directive|define
name|B1800
value|0000012
end_define

begin_define
define|#
directive|define
name|B2400
value|0000013
end_define

begin_define
define|#
directive|define
name|B4800
value|0000014
end_define

begin_define
define|#
directive|define
name|B9600
value|0000015
end_define

begin_define
define|#
directive|define
name|B19200
value|0000016
end_define

begin_define
define|#
directive|define
name|B38400
value|0000017
end_define

begin_define
define|#
directive|define
name|EXTA
value|B19200
end_define

begin_define
define|#
directive|define
name|EXTB
value|B38400
end_define

begin_define
define|#
directive|define
name|CSIZE
value|0000060
end_define

begin_define
define|#
directive|define
name|CS5
value|0000000
end_define

begin_define
define|#
directive|define
name|CS6
value|0000020
end_define

begin_define
define|#
directive|define
name|CS7
value|0000040
end_define

begin_define
define|#
directive|define
name|CS8
value|0000060
end_define

begin_define
define|#
directive|define
name|CSTOPB
value|0000100
end_define

begin_define
define|#
directive|define
name|CREAD
value|0000200
end_define

begin_define
define|#
directive|define
name|PARENB
value|0000400
end_define

begin_define
define|#
directive|define
name|PARODD
value|0001000
end_define

begin_define
define|#
directive|define
name|HUPCL
value|0002000
end_define

begin_define
define|#
directive|define
name|CLOCAL
value|0004000
end_define

begin_define
define|#
directive|define
name|CBAUDEX
value|0010000
end_define

begin_define
define|#
directive|define
name|B57600
value|0010001
end_define

begin_define
define|#
directive|define
name|B115200
value|0010002
end_define

begin_define
define|#
directive|define
name|B230400
value|0010003
end_define

begin_define
define|#
directive|define
name|B460800
value|0010004
end_define

begin_define
define|#
directive|define
name|CIBAUD
value|002003600000
end_define

begin_comment
comment|/* input baud rate (not used) */
end_comment

begin_define
define|#
directive|define
name|CRTSCTS
value|020000000000
end_define

begin_comment
comment|/* flow control */
end_comment

begin_comment
comment|/* c_lflag bits */
end_comment

begin_define
define|#
directive|define
name|ISIG
value|0000001
end_define

begin_define
define|#
directive|define
name|ICANON
value|0000002
end_define

begin_define
define|#
directive|define
name|XCASE
value|0000004
end_define

begin_define
define|#
directive|define
name|ECHO
value|0000010
end_define

begin_define
define|#
directive|define
name|ECHOE
value|0000020
end_define

begin_define
define|#
directive|define
name|ECHOK
value|0000040
end_define

begin_define
define|#
directive|define
name|ECHONL
value|0000100
end_define

begin_define
define|#
directive|define
name|NOFLSH
value|0000200
end_define

begin_define
define|#
directive|define
name|TOSTOP
value|0000400
end_define

begin_define
define|#
directive|define
name|ECHOCTL
value|0001000
end_define

begin_define
define|#
directive|define
name|ECHOPRT
value|0002000
end_define

begin_define
define|#
directive|define
name|ECHOKE
value|0004000
end_define

begin_define
define|#
directive|define
name|FLUSHO
value|0010000
end_define

begin_define
define|#
directive|define
name|PENDIN
value|0040000
end_define

begin_define
define|#
directive|define
name|IEXTEN
value|0100000
end_define

begin_comment
comment|/* tcflow() and TCXONC use these */
end_comment

begin_define
define|#
directive|define
name|TCOOFF
value|0
end_define

begin_define
define|#
directive|define
name|TCOON
value|1
end_define

begin_define
define|#
directive|define
name|TCIOFF
value|2
end_define

begin_define
define|#
directive|define
name|TCION
value|3
end_define

begin_comment
comment|/* tcflush() and TCFLSH use these */
end_comment

begin_define
define|#
directive|define
name|TCIFLUSH
value|0
end_define

begin_define
define|#
directive|define
name|TCOFLUSH
value|1
end_define

begin_define
define|#
directive|define
name|TCIOFLUSH
value|2
end_define

begin_comment
comment|/* tcsetattr uses these */
end_comment

begin_define
define|#
directive|define
name|TCSANOW
value|0
end_define

begin_define
define|#
directive|define
name|TCSADRAIN
value|1
end_define

begin_define
define|#
directive|define
name|TCSAFLUSH
value|2
end_define

begin_define
define|#
directive|define
name|VMIN
value|16
end_define

begin_define
define|#
directive|define
name|VTIME
value|17
end_define

begin_comment
comment|/* modem lines */
end_comment

begin_define
define|#
directive|define
name|TIOCM_LE
value|0x001
end_define

begin_define
define|#
directive|define
name|TIOCM_DTR
value|0x002
end_define

begin_define
define|#
directive|define
name|TIOCM_RTS
value|0x004
end_define

begin_define
define|#
directive|define
name|TIOCM_ST
value|0x008
end_define

begin_define
define|#
directive|define
name|TIOCM_SR
value|0x010
end_define

begin_define
define|#
directive|define
name|TIOCM_CTS
value|0x020
end_define

begin_define
define|#
directive|define
name|TIOCM_CAR
value|0x040
end_define

begin_define
define|#
directive|define
name|TIOCM_RNG
value|0x080
end_define

begin_define
define|#
directive|define
name|TIOCM_DSR
value|0x100
end_define

begin_define
define|#
directive|define
name|TIOCM_CD
value|TIOCM_CAR
end_define

begin_define
define|#
directive|define
name|TIOCM_RI
value|TIOCM_RNG
end_define

begin_define
define|#
directive|define
name|TIOCM_OUT1
value|0x2000
end_define

begin_define
define|#
directive|define
name|TIOCM_OUT2
value|0x4000
end_define

begin_comment
comment|/* ioctl */
end_comment

begin_define
define|#
directive|define
name|TIOCMGET
value|1
end_define

begin_define
define|#
directive|define
name|TIOCMSET
value|2
end_define

begin_define
define|#
directive|define
name|TIOCMBIC
value|3
end_define

begin_define
define|#
directive|define
name|TIOCMBIS
value|4
end_define

begin_comment
comment|/* NOP cfsetospeed() and cfsetispeed() for now */
end_comment

begin_define
define|#
directive|define
name|cfsetospeed
parameter_list|(
name|dcb
parameter_list|,
name|spd
parameter_list|)
value|(0)
end_define

begin_define
define|#
directive|define
name|cfsetispeed
parameter_list|(
name|dcb
parameter_list|,
name|spd
parameter_list|)
value|(0)
end_define

begin_function_decl
specifier|extern
name|int
name|closeserial
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|ioctl
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
name|int
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tcsetattr
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|,
specifier|const
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tcgetattr
parameter_list|(
name|int
parameter_list|,
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|tcflush
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|isserialhandle
parameter_list|(
name|HANDLE
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NTP_WIN_TERMIOS_H */
end_comment

end_unit

