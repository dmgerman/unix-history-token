begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * A clist structure is the head  * of a linked list queue of characters.  * The characters are stored in 4-word  * blocks containing a link and several characters.  * The routines getc and putc  * manipulate these structures.  */
end_comment

begin_struct
struct|struct
name|clist
block|{
name|int
name|c_cc
decl_stmt|;
comment|/* character count */
name|char
modifier|*
name|c_cf
decl_stmt|;
comment|/* pointer to first char */
name|char
modifier|*
name|c_cl
decl_stmt|;
comment|/* pointer to last char */
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
function_decl|(
modifier|*
name|t_oproc
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to start output */
name|int
function_decl|(
modifier|*
name|t_iproc
function_decl|)
parameter_list|()
function_decl|;
comment|/* routine to start input */
name|struct
name|chan
modifier|*
name|t_chan
decl_stmt|;
comment|/* destination channel */
name|caddr_t
name|t_linep
decl_stmt|;
comment|/* aux line discipline pointer */
name|caddr_t
name|t_addr
decl_stmt|;
comment|/* device address */
name|short
name|t_flags
decl_stmt|;
comment|/* mode, settable by ioctl call */
name|short
name|t_state
decl_stmt|;
comment|/* internal state, not visible externally */
name|short
name|t_pgrp
decl_stmt|;
comment|/* process group name */
name|char
name|t_delct
decl_stmt|;
comment|/* number of delimiters in raw q */
name|char
name|t_line
decl_stmt|;
comment|/* line discipline */
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
name|t_char
decl_stmt|;
comment|/* character temporary */
name|char
name|t_ispeed
decl_stmt|;
comment|/* input speed */
name|char
name|t_ospeed
decl_stmt|;
comment|/* output speed */
block|}
struct|;
end_struct

begin_comment
comment|/*  * structure of arg for ioctl  */
end_comment

begin_struct
struct|struct
name|ttiocb
block|{
name|char
name|ioc_ispeed
decl_stmt|;
name|char
name|ioc_ospeed
decl_stmt|;
name|char
name|ioc_erase
decl_stmt|;
name|char
name|ioc_kill
decl_stmt|;
name|int
name|ioc_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|TTIPRI
value|28
end_define

begin_define
define|#
directive|define
name|TTOPRI
value|29
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

begin_define
define|#
directive|define
name|CSTOP
value|023
end_define

begin_comment
comment|/* Stop output: ctl-s */
end_comment

begin_define
define|#
directive|define
name|CSTART
value|021
end_define

begin_comment
comment|/* Start output: ctl-q */
end_comment

begin_comment
comment|/* limits */
end_comment

begin_define
define|#
directive|define
name|TTHIWAT
value|100
end_define

begin_define
define|#
directive|define
name|TTLOWAT
value|50
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

begin_define
define|#
directive|define
name|XCLUDE
value|0200
end_define

begin_comment
comment|/* exclusive-use flag against open */
end_comment

begin_define
define|#
directive|define
name|TTSTOP
value|0400
end_define

begin_comment
comment|/* Output stopped by ctl-s */
end_comment

begin_define
define|#
directive|define
name|HUPCLS
value|01000
end_define

begin_comment
comment|/* Hang up upon last close */
end_comment

begin_define
define|#
directive|define
name|TBLOCK
value|02000
end_define

begin_comment
comment|/* tandem queue blocked */
end_comment

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
name|TIOCTSTP
value|(('t'<<8)|16)
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
name|FIOCLEX
value|(('f'<<8)|1)
end_define

begin_define
define|#
directive|define
name|FIONCLEX
value|(('f'<<8)|2)
end_define

end_unit

