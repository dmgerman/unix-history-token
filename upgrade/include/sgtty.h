begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|sgttyb
block|{
name|char
name|sg_ispeed
decl_stmt|;
name|char
name|sg_ospeed
decl_stmt|;
name|char
name|sg_erase
decl_stmt|;
name|char
name|sg_kill
decl_stmt|;
name|int
name|sg_flags
decl_stmt|;
block|}
struct|;
end_struct

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

end_unit

