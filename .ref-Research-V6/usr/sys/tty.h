begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * A clist structure is the head  * of a linked list queue of characters.  * The characters are stored in 4-word  * blocks containing a link and 6 characters.  * The routines getc and putc (m45.s or m40.s)  * manipulate these structures.  */
end_comment

begin_struct
struct|struct
name|clist
block|{
name|int
name|c_cc
decl_stmt|;
comment|/* character count */
name|int
name|c_cf
decl_stmt|;
comment|/* pointer to first block */
name|int
name|c_cl
decl_stmt|;
comment|/* pointer to last block */
block|}
struct|;
end_struct

begin_comment
comment|/*  * A tty structure is needed for  * each UNIX character device that  * is used for normal terminal IO.  * The routines in tty.c handle the  * common code associated with  * these structures.  * The definition and device dependent  * code is in each driver. (kl.c dc.c dh.c)  */
end_comment

begin_struct
struct|struct
name|tty
block|{
name|struct
name|clist
name|t_rawq
decl_stmt|;
comment|/* input chars right off device */
name|struct
name|clist
name|t_canq
decl_stmt|;
comment|/* input chars after erase and kill */
name|struct
name|clist
name|t_outq
decl_stmt|;
comment|/* output list to device */
name|int
name|t_flags
decl_stmt|;
comment|/* mode, settable by stty call */
name|int
modifier|*
name|t_addr
decl_stmt|;
comment|/* device address (register or startup fcn) */
name|char
name|t_delct
decl_stmt|;
comment|/* number of delimiters in raw q */
name|char
name|t_col
decl_stmt|;
comment|/* printing column of device */
name|char
name|t_erase
decl_stmt|;
comment|/* erase character */
name|char
name|t_kill
decl_stmt|;
comment|/* kill character */
name|char
name|t_state
decl_stmt|;
comment|/* internal state, not visible externally */
name|char
name|t_char
decl_stmt|;
comment|/* character temporary */
name|int
name|t_speeds
decl_stmt|;
comment|/* output+input line speed */
name|int
name|t_dev
decl_stmt|;
comment|/* device name */
block|}
struct|;
end_struct

begin_decl_stmt
name|char
name|partab
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* ASCII table: parity, character class */
end_comment

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

begin_comment
comment|/* default special characters */
end_comment

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
name|HUPCL
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
name|CRDELAY
value|030000
end_define

begin_define
define|#
directive|define
name|VTDELAY
value|040000
end_define

begin_comment
comment|/* Hardware bits */
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

begin_comment
comment|/* Internal state bits */
end_comment

begin_define
define|#
directive|define
name|TIMEOUT
value|01
end_define

begin_comment
comment|/* Delay timeout in progress */
end_comment

begin_define
define|#
directive|define
name|WOPEN
value|02
end_define

begin_comment
comment|/* Waiting for open to complete */
end_comment

begin_define
define|#
directive|define
name|ISOPEN
value|04
end_define

begin_comment
comment|/* Device is open */
end_comment

begin_define
define|#
directive|define
name|SSTART
value|010
end_define

begin_comment
comment|/* Has special start routine at addr */
end_comment

begin_define
define|#
directive|define
name|CARR_ON
value|020
end_define

begin_comment
comment|/* Software copy of carrier-present */
end_comment

begin_define
define|#
directive|define
name|BUSY
value|040
end_define

begin_comment
comment|/* Output in progress */
end_comment

begin_define
define|#
directive|define
name|ASLEEP
value|0100
end_define

begin_comment
comment|/* Wakeup when output done */
end_comment

end_unit

