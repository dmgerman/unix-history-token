begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Structure for stty and gtty system calls.  */
end_comment

begin_struct
struct|struct
name|sgttyb
block|{
name|char
name|sg_ispeed
decl_stmt|;
comment|/* input speed */
name|char
name|sg_ospeed
decl_stmt|;
comment|/* output speed */
name|char
name|sg_erase
decl_stmt|;
comment|/* erase character */
name|char
name|sg_kill
decl_stmt|;
comment|/* kill character */
name|int
name|sg_flags
decl_stmt|;
comment|/* mode flags */
block|}
struct|;
end_struct

begin_comment
comment|/*  * List of special characters  */
end_comment

begin_struct
struct|struct
name|tchars
block|{
name|char
name|t_intrc
decl_stmt|;
comment|/* interrupt */
name|char
name|t_quitc
decl_stmt|;
comment|/* quit */
name|char
name|t_startc
decl_stmt|;
comment|/* start output */
name|char
name|t_stopc
decl_stmt|;
comment|/* stop output */
name|char
name|t_eofc
decl_stmt|;
comment|/* end-of-file */
name|char
name|t_brkc
decl_stmt|;
comment|/* input delimiter (like nl) */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Modes  */
end_comment

begin_define
define|#
directive|define
name|TANDEM
value|01
end_define

begin_define
define|#
directive|define
name|CBREAK
value|02
end_define

begin_define
define|#
directive|define
name|LCASE
value|04
end_define

begin_define
define|#
directive|define
name|ECHO
value|010
end_define

begin_define
define|#
directive|define
name|CRMOD
value|020
end_define

begin_define
define|#
directive|define
name|RAW
value|040
end_define

begin_define
define|#
directive|define
name|ODDP
value|0100
end_define

begin_define
define|#
directive|define
name|EVENP
value|0200
end_define

begin_define
define|#
directive|define
name|ANYP
value|0300
end_define

begin_define
define|#
directive|define
name|NLDELAY
value|001400
end_define

begin_define
define|#
directive|define
name|TBDELAY
value|006000
end_define

begin_define
define|#
directive|define
name|XTABS
value|06000
end_define

begin_define
define|#
directive|define
name|CRDELAY
value|030000
end_define

begin_define
define|#
directive|define
name|VTDELAY
value|040000
end_define

begin_define
define|#
directive|define
name|BSDELAY
value|0100000
end_define

begin_define
define|#
directive|define
name|ALLDELAY
value|0177400
end_define

begin_comment
comment|/*  * Delay algorithms  */
end_comment

begin_define
define|#
directive|define
name|CR0
value|0
end_define

begin_define
define|#
directive|define
name|CR1
value|010000
end_define

begin_define
define|#
directive|define
name|CR2
value|020000
end_define

begin_define
define|#
directive|define
name|CR3
value|030000
end_define

begin_define
define|#
directive|define
name|NL0
value|0
end_define

begin_define
define|#
directive|define
name|NL1
value|000400
end_define

begin_define
define|#
directive|define
name|NL2
value|001000
end_define

begin_define
define|#
directive|define
name|NL3
value|001400
end_define

begin_define
define|#
directive|define
name|TAB0
value|0
end_define

begin_define
define|#
directive|define
name|TAB1
value|002000
end_define

begin_define
define|#
directive|define
name|TAB2
value|004000
end_define

begin_define
define|#
directive|define
name|FF0
value|0
end_define

begin_define
define|#
directive|define
name|FF1
value|040000
end_define

begin_define
define|#
directive|define
name|BS0
value|0
end_define

begin_define
define|#
directive|define
name|BS1
value|0100000
end_define

begin_comment
comment|/*  * Speeds  */
end_comment

begin_define
define|#
directive|define
name|B0
value|0
end_define

begin_define
define|#
directive|define
name|B50
value|1
end_define

begin_define
define|#
directive|define
name|B75
value|2
end_define

begin_define
define|#
directive|define
name|B110
value|3
end_define

begin_define
define|#
directive|define
name|B134
value|4
end_define

begin_define
define|#
directive|define
name|B150
value|5
end_define

begin_define
define|#
directive|define
name|B200
value|6
end_define

begin_define
define|#
directive|define
name|B300
value|7
end_define

begin_define
define|#
directive|define
name|B600
value|8
end_define

begin_define
define|#
directive|define
name|B1200
value|9
end_define

begin_define
define|#
directive|define
name|B1800
value|10
end_define

begin_define
define|#
directive|define
name|B2400
value|11
end_define

begin_define
define|#
directive|define
name|B4800
value|12
end_define

begin_define
define|#
directive|define
name|B9600
value|13
end_define

begin_define
define|#
directive|define
name|EXTA
value|14
end_define

begin_define
define|#
directive|define
name|EXTB
value|15
end_define

begin_comment
comment|/*  * tty ioctl commands  */
end_comment

begin_define
define|#
directive|define
name|TIOCGETD
value|(('t'<<8)|0)
end_define

begin_define
define|#
directive|define
name|TIOCSETD
value|(('t'<<8)|1)
end_define

begin_define
define|#
directive|define
name|TIOCHPCL
value|(('t'<<8)|2)
end_define

begin_define
define|#
directive|define
name|TIOCMODG
value|(('t'<<8)|3)
end_define

begin_define
define|#
directive|define
name|TIOCMODS
value|(('t'<<8)|4)
end_define

begin_define
define|#
directive|define
name|TIOCGETP
value|(('t'<<8)|8)
end_define

begin_define
define|#
directive|define
name|TIOCSETP
value|(('t'<<8)|9)
end_define

begin_define
define|#
directive|define
name|TIOCSETN
value|(('t'<<8)|10)
end_define

begin_define
define|#
directive|define
name|TIOCEXCL
value|(('t'<<8)|13)
end_define

begin_define
define|#
directive|define
name|TIOCNXCL
value|(('t'<<8)|14)
end_define

begin_define
define|#
directive|define
name|TIOHMODE
value|(('t'<<8)|15)
end_define

begin_define
define|#
directive|define
name|TIOCTSTP
value|(('t'<<8)|16)
end_define

begin_define
define|#
directive|define
name|TIOCSETC
value|(('t'<<8)|17)
end_define

begin_define
define|#
directive|define
name|TIOCGETC
value|(('t'<<8)|18)
end_define

begin_define
define|#
directive|define
name|DIOCLSTN
value|(('d'<<8)|1)
end_define

begin_define
define|#
directive|define
name|DIOCNTRL
value|(('d'<<8)|2)
end_define

begin_define
define|#
directive|define
name|DIOCMPX
value|(('d'<<8)|3)
end_define

begin_define
define|#
directive|define
name|DIOCNMPX
value|(('d'<<8)|4)
end_define

begin_define
define|#
directive|define
name|DIOCSCALL
value|(('d'<<8)|5)
end_define

begin_define
define|#
directive|define
name|DIOCRCALL
value|(('d'<<8)|6)
end_define

begin_define
define|#
directive|define
name|DIOCPGRP
value|(('d'<<8)|7)
end_define

begin_define
define|#
directive|define
name|DIOCGETP
value|(('d'<<8)|8)
end_define

begin_define
define|#
directive|define
name|DIOCSETP
value|(('d'<<8)|9)
end_define

begin_define
define|#
directive|define
name|DIOCLOSE
value|(('d'<<8)|10)
end_define

begin_define
define|#
directive|define
name|DIOCTIME
value|(('d'<<8)|11)
end_define

begin_define
define|#
directive|define
name|DIOCRESET
value|(('d'<<8)|12)
end_define

begin_define
define|#
directive|define
name|FIOCLEX
value|(('f'<<8)|1)
end_define

begin_define
define|#
directive|define
name|FIONCLEX
value|(('f'<<8)|2)
end_define

begin_define
define|#
directive|define
name|MXLSTN
value|(('x'<<8)|1)
end_define

begin_define
define|#
directive|define
name|MXNBLK
value|(('x'<<8)|2)
end_define

end_unit

