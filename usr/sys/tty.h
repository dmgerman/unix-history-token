begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|clist
block|{
name|int
name|c_cc
decl_stmt|;
name|int
name|c_cf
decl_stmt|;
name|int
name|c_cl
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|tty
block|{
name|struct
name|clist
name|t_rawq
decl_stmt|;
name|struct
name|clist
name|t_canq
decl_stmt|;
name|struct
name|clist
name|t_outq
decl_stmt|;
name|int
name|t_flags
decl_stmt|;
name|int
modifier|*
name|t_addr
decl_stmt|;
name|char
name|t_delct
decl_stmt|;
name|char
name|t_col
decl_stmt|;
name|char
name|t_erase
decl_stmt|;
name|char
name|t_kill
decl_stmt|;
name|char
name|t_state
decl_stmt|;
name|char
name|t_char
decl_stmt|;
name|int
name|t_speeds
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
name|char
name|partab
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|TTIPRI
value|10
end_define

begin_define
define|#
directive|define
name|TTOPRI
value|20
end_define

begin_define
define|#
directive|define
name|CERASE
value|'#'
end_define

begin_define
define|#
directive|define
name|CEOT
value|004
end_define

begin_define
define|#
directive|define
name|CKILL
value|'@'
end_define

begin_define
define|#
directive|define
name|CQUIT
value|034
end_define

begin_comment
comment|/* FS, cntl shift L */
end_comment

begin_define
define|#
directive|define
name|CINTR
value|0177
end_define

begin_comment
comment|/* DEL */
end_comment

begin_comment
comment|/* limits */
end_comment

begin_define
define|#
directive|define
name|TTHIWAT
value|50
end_define

begin_define
define|#
directive|define
name|TTLOWAT
value|30
end_define

begin_define
define|#
directive|define
name|TTYHOG
value|256
end_define

begin_comment
comment|/* modes */
end_comment

begin_define
define|#
directive|define
name|NODELAY
value|01
end_define

begin_define
define|#
directive|define
name|XTABS
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
name|HUPCL
value|0400
end_define

begin_define
define|#
directive|define
name|NTDELAY
value|010000
end_define

begin_comment
comment|/* Bits */
end_comment

begin_define
define|#
directive|define
name|DONE
value|0200
end_define

begin_define
define|#
directive|define
name|IENABLE
value|0100
end_define

begin_define
define|#
directive|define
name|TIMEOUT
value|01
end_define

begin_define
define|#
directive|define
name|WOPEN
value|02
end_define

begin_define
define|#
directive|define
name|ISOPEN
value|04
end_define

begin_define
define|#
directive|define
name|SSTART
value|010
end_define

begin_define
define|#
directive|define
name|CARR_ON
value|020
end_define

begin_define
define|#
directive|define
name|BUSY
value|040
end_define

end_unit

