begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	tu.c	82/01/17	4.4	*/
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|VAX750
argument_list|)
operator|||
name|defined
argument_list|(
name|VAX7ZZ
argument_list|)
end_if

begin_comment
comment|/*  * TU58 DECtape II device driver  *  * Bill Shannon - DEC - 01/12/81  *  * This driver controls the console TU58s on a VAX-11/750 or VAX-11/7ZZ.  * It could be easily modified for a Unibus TU58.  The TU58  * is treated as a block device (only).  Error detection and  * recovery is almost non-existant.  It is assumed that the  * TU58 will follow the RSP protocol exactly, very few protocol  * errors are checked for.  It is assumed that the 750 uses standard  * RSP while the 7ZZ uses Modified RSP (MRSP).  At the time when 750's  * are converted to MRSP (by replacing EPROMS in the TU58), the tests  * based on MRSP can be removed.  */
end_comment

begin_define
define|#
directive|define
name|NTU
value|((cpu == VAX_750) ? 1 : 2)
end_define

begin_define
define|#
directive|define
name|MRSP
value|(cpu != VAX_750)
end_define

begin_include
include|#
directive|include
file|"../h/param.h"
end_include

begin_include
include|#
directive|include
file|"../h/systm.h"
end_include

begin_include
include|#
directive|include
file|"../h/buf.h"
end_include

begin_include
include|#
directive|include
file|"../h/conf.h"
end_include

begin_include
include|#
directive|include
file|"../h/dir.h"
end_include

begin_include
include|#
directive|include
file|"../h/user.h"
end_include

begin_include
include|#
directive|include
file|"../h/mtpr.h"
end_include

begin_include
include|#
directive|include
file|"../h/cpu.h"
end_include

begin_define
define|#
directive|define
name|printd
value|if(tudebug) printf
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|printd
end_ifdef

begin_decl_stmt
name|int
name|tudebug
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* printd */
end_comment

begin_endif
endif|#
directive|endif
endif|printd
end_endif

begin_define
define|#
directive|define
name|NTUBLK
value|512
end_define

begin_comment
comment|/* number of blocks on a TU58 cassette */
end_comment

begin_define
define|#
directive|define
name|TUIPL
value|((cpu == VAX_750) ? 0x17 : 0x14)
end_define

begin_comment
comment|/*  * Device register bits  */
end_comment

begin_define
define|#
directive|define
name|READY
value|0200
end_define

begin_comment
comment|/* transmitter ready */
end_comment

begin_define
define|#
directive|define
name|DONE
value|0200
end_define

begin_comment
comment|/* receiver done */
end_comment

begin_define
define|#
directive|define
name|IE
value|0100
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|BREAK
value|1
end_define

begin_comment
comment|/* send break */
end_comment

begin_comment
comment|/*  * Structure of a command packet  */
end_comment

begin_struct
struct|struct
name|packet
block|{
name|u_char
name|pk_flag
decl_stmt|;
comment|/* indicates packet type (cmd, data, etc.) */
name|u_char
name|pk_mcount
decl_stmt|;
comment|/* length of packet (bytes) */
name|u_char
name|pk_op
decl_stmt|;
comment|/* operation to perform (read, write, etc.) */
name|char
name|pk_mod
decl_stmt|;
comment|/* modifier for op or returned status */
name|u_char
name|pk_unit
decl_stmt|;
comment|/* unit number */
name|u_char
name|pk_sw
decl_stmt|;
comment|/* switches */
name|u_short
name|pk_seq
decl_stmt|;
comment|/* sequence number, always zero */
name|u_short
name|pk_count
decl_stmt|;
comment|/* requested byte count for read or write */
name|u_short
name|pk_block
decl_stmt|;
comment|/* block number for read, write, or seek */
name|u_short
name|pk_chksum
decl_stmt|;
comment|/* checksum, by words with end around carry */
block|}
struct|;
end_struct

begin_decl_stmt
name|struct
name|packet
name|tucmd
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a command sent to the TU58 */
end_comment

begin_decl_stmt
name|struct
name|packet
name|tudata
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* a command or data returned from TU58 */
end_comment

begin_comment
comment|/*  * State information  */
end_comment

begin_struct
struct|struct
name|tu
block|{
name|u_char
modifier|*
name|rbptr
decl_stmt|;
comment|/* pointer to buffer for read */
name|int
name|rcnt
decl_stmt|;
comment|/* how much to read */
name|u_char
modifier|*
name|wbptr
decl_stmt|;
comment|/* pointer to buffer for write */
name|int
name|wcnt
decl_stmt|;
comment|/* how much to write */
name|int
name|state
decl_stmt|;
comment|/* current state of tansfer operation */
name|int
name|flag
decl_stmt|;
comment|/* read in progress flag */
name|char
modifier|*
name|addr
decl_stmt|;
comment|/* real buffer data address */
name|int
name|count
decl_stmt|;
comment|/* real requested count */
name|int
name|serrs
decl_stmt|;
comment|/* count of soft errors */
name|int
name|cerrs
decl_stmt|;
comment|/* count of checksum errors */
name|int
name|herrs
decl_stmt|;
comment|/* count of hard errors */
block|}
name|tu
struct|;
end_struct

begin_comment
comment|/*  * States  */
end_comment

begin_define
define|#
directive|define
name|INIT1
value|0
end_define

begin_comment
comment|/* sending nulls */
end_comment

begin_define
define|#
directive|define
name|INIT2
value|1
end_define

begin_comment
comment|/* sending inits */
end_comment

begin_define
define|#
directive|define
name|IDLE
value|2
end_define

begin_comment
comment|/* initialized, no transfer in progress */
end_comment

begin_define
define|#
directive|define
name|SENDH
value|3
end_define

begin_comment
comment|/* sending header */
end_comment

begin_define
define|#
directive|define
name|SENDD
value|4
end_define

begin_comment
comment|/* sending data */
end_comment

begin_define
define|#
directive|define
name|SENDC
value|5
end_define

begin_comment
comment|/* sending checksum */
end_comment

begin_define
define|#
directive|define
name|SENDR
value|6
end_define

begin_comment
comment|/* sending read command packet */
end_comment

begin_define
define|#
directive|define
name|SENDW
value|7
end_define

begin_comment
comment|/* sending write command packet */
end_comment

begin_define
define|#
directive|define
name|GETH
value|8
end_define

begin_comment
comment|/* reading header */
end_comment

begin_define
define|#
directive|define
name|GETD
value|9
end_define

begin_comment
comment|/* reading data */
end_comment

begin_define
define|#
directive|define
name|GETC
value|10
end_define

begin_comment
comment|/* reading checksum */
end_comment

begin_define
define|#
directive|define
name|GET
value|11
end_define

begin_comment
comment|/* reading an entire packet */
end_comment

begin_define
define|#
directive|define
name|WAIT
value|12
end_define

begin_comment
comment|/* waiting for continue */
end_comment

begin_comment
comment|/*  * Packet Flags  */
end_comment

begin_define
define|#
directive|define
name|TUF_DATA
value|1
end_define

begin_comment
comment|/* data packet */
end_comment

begin_define
define|#
directive|define
name|TUF_CMD
value|2
end_define

begin_comment
comment|/* command packet */
end_comment

begin_define
define|#
directive|define
name|TUF_INITF
value|4
end_define

begin_comment
comment|/* initialize */
end_comment

begin_define
define|#
directive|define
name|TUF_CONT
value|020
end_define

begin_comment
comment|/* continue */
end_comment

begin_define
define|#
directive|define
name|TUF_XOFF
value|023
end_define

begin_comment
comment|/* flow control */
end_comment

begin_comment
comment|/*  * Op Codes  */
end_comment

begin_define
define|#
directive|define
name|TUOP_INIT
value|1
end_define

begin_comment
comment|/* initialize */
end_comment

begin_define
define|#
directive|define
name|TUOP_READ
value|2
end_define

begin_comment
comment|/* read block */
end_comment

begin_define
define|#
directive|define
name|TUOP_WRITE
value|3
end_define

begin_comment
comment|/* write block */
end_comment

begin_define
define|#
directive|define
name|TUOP_SEEK
value|5
end_define

begin_comment
comment|/* seek to block */
end_comment

begin_define
define|#
directive|define
name|TUOP_DIAGNOSE
value|7
end_define

begin_comment
comment|/* run micro-diagnostics */
end_comment

begin_define
define|#
directive|define
name|TUOP_END
value|0100
end_define

begin_comment
comment|/* end packet */
end_comment

begin_comment
comment|/*  * Switches  */
end_comment

begin_define
define|#
directive|define
name|TUSW_MRSP
value|010
end_define

begin_comment
comment|/* use Modified RSP */
end_comment

begin_decl_stmt
name|u_char
name|tunull
index|[
literal|2
index|]
init|=
block|{
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* nulls to send for initialization */
end_comment

begin_decl_stmt
name|u_char
name|tuinit
index|[
literal|2
index|]
init|=
block|{
name|TUF_INITF
block|,
name|TUF_INITF
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* inits to send */
end_comment

begin_decl_stmt
name|int
name|tutimer
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|struct
name|buf
name|tutab
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* I/O queue header */
end_comment

begin_comment
comment|/*  * Open the TU58  */
end_comment

begin_comment
comment|/*ARGSUSED*/
end_comment

begin_macro
name|tuopen
argument_list|(
argument|dev
argument_list|,
argument|flag
argument_list|)
end_macro

begin_block
block|{
specifier|extern
name|int
name|tuwatch
parameter_list|()
function_decl|;
specifier|register
name|s
expr_stmt|;
ifdef|#
directive|ifdef
name|lint
name|turintr
argument_list|()
expr_stmt|;
name|tuwintr
argument_list|()
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|minor
argument_list|(
name|dev
argument_list|)
operator|>=
name|NTU
condition|)
block|{
name|u
operator|.
name|u_error
operator|=
name|ENXIO
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|tutimer
operator|==
literal|0
condition|)
block|{
name|tutimer
operator|++
expr_stmt|;
name|timeout
argument_list|(
name|tuwatch
argument_list|,
operator|(
name|caddr_t
operator|)
literal|0
argument_list|,
name|hz
argument_list|)
expr_stmt|;
block|}
name|s
operator|=
name|splx
argument_list|(
name|TUIPL
argument_list|)
expr_stmt|;
if|if
condition|(
name|tu
operator|.
name|state
operator|!=
name|IDLE
condition|)
block|{
name|tureset
argument_list|()
expr_stmt|;
name|sleep
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|tu
argument_list|,
name|PZERO
argument_list|)
expr_stmt|;
name|tutab
operator|.
name|b_active
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|tu
operator|.
name|state
operator|!=
name|IDLE
condition|)
block|{
comment|/* couldn't initialize */
name|u
operator|.
name|u_error
operator|=
name|ENXIO
expr_stmt|;
name|tu
operator|.
name|state
operator|=
name|INIT1
expr_stmt|;
name|tu
operator|.
name|rcnt
operator|=
name|tu
operator|.
name|wcnt
operator|=
literal|0
expr_stmt|;
name|mtpr
argument_list|(
name|CSTS
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mtpr
argument_list|(
name|CSRS
argument_list|,
literal|0
argument_list|)
expr_stmt|;
block|}
block|}
else|else
name|mtpr
argument_list|(
name|CSRS
argument_list|,
name|IE
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Close the TU58  */
end_comment

begin_macro
name|tuclose
argument_list|(
argument|dev
argument_list|)
end_macro

begin_block
block|{
if|if
condition|(
name|tutab
operator|.
name|b_active
operator|==
literal|0
condition|)
block|{
name|mtpr
argument_list|(
name|CSRS
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|tutimer
operator|=
literal|0
expr_stmt|;
block|}
if|if
condition|(
name|tu
operator|.
name|serrs
operator|+
name|tu
operator|.
name|cerrs
operator|+
name|tu
operator|.
name|herrs
operator|!=
literal|0
condition|)
block|{
comment|/* any errors ? */
name|uprintf
argument_list|(
literal|"tu%d: %d soft errors, %d chksum errors, %d hard errors\n"
argument_list|,
name|minor
argument_list|(
name|dev
argument_list|)
argument_list|,
name|tu
operator|.
name|serrs
argument_list|,
name|tu
operator|.
name|cerrs
argument_list|,
name|tu
operator|.
name|herrs
argument_list|)
expr_stmt|;
name|tu
operator|.
name|serrs
operator|=
name|tu
operator|.
name|cerrs
operator|=
name|tu
operator|.
name|herrs
operator|=
literal|0
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  * Reset the TU58  */
end_comment

begin_macro
name|tureset
argument_list|()
end_macro

begin_block
block|{
name|tu
operator|.
name|state
operator|=
name|INIT1
expr_stmt|;
name|tu
operator|.
name|wbptr
operator|=
name|tunull
expr_stmt|;
name|tu
operator|.
name|wcnt
operator|=
sizeof|sizeof
name|tunull
expr_stmt|;
name|tucmd
operator|.
name|pk_flag
operator|=
name|TUF_CMD
expr_stmt|;
name|tucmd
operator|.
name|pk_mcount
operator|=
sizeof|sizeof
name|tucmd
operator|-
literal|4
expr_stmt|;
name|tucmd
operator|.
name|pk_mod
operator|=
literal|0
expr_stmt|;
name|tucmd
operator|.
name|pk_seq
operator|=
literal|0
expr_stmt|;
name|tucmd
operator|.
name|pk_sw
operator|=
name|MRSP
condition|?
name|TUSW_MRSP
else|:
literal|0
expr_stmt|;
name|tutab
operator|.
name|b_active
operator|++
expr_stmt|;
name|mtpr
argument_list|(
name|CSRS
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|mtpr
argument_list|(
name|CSTS
argument_list|,
name|IE
operator||
name|BREAK
argument_list|)
expr_stmt|;
name|tuxintr
argument_list|()
expr_stmt|;
comment|/* start output */
return|return;
block|}
end_block

begin_comment
comment|/*  * Strategy routine for block I/O  */
end_comment

begin_expr_stmt
name|tustrategy
argument_list|(
name|bp
argument_list|)
specifier|register
expr|struct
name|buf
operator|*
name|bp
expr_stmt|;
end_expr_stmt

begin_block
block|{
specifier|register
name|int
name|s
decl_stmt|;
if|if
condition|(
name|bp
operator|->
name|b_blkno
operator|>=
name|NTUBLK
condition|)
block|{
comment|/* block number out of range? */
name|bp
operator|->
name|b_flags
operator||=
name|B_ERROR
expr_stmt|;
name|iodone
argument_list|(
name|bp
argument_list|)
expr_stmt|;
return|return;
block|}
name|bp
operator|->
name|av_forw
operator|=
name|NULL
expr_stmt|;
name|s
operator|=
name|splx
argument_list|(
name|TUIPL
argument_list|)
expr_stmt|;
if|if
condition|(
name|tutab
operator|.
name|b_actf
operator|==
name|NULL
condition|)
name|tutab
operator|.
name|b_actf
operator|=
name|bp
expr_stmt|;
else|else
name|tutab
operator|.
name|b_actl
operator|->
name|av_forw
operator|=
name|bp
expr_stmt|;
name|tutab
operator|.
name|b_actl
operator|=
name|bp
expr_stmt|;
if|if
condition|(
name|tutab
operator|.
name|b_active
operator|==
name|NULL
condition|)
name|tustart
argument_list|()
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Start the transfer  */
end_comment

begin_macro
name|tustart
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
if|if
condition|(
operator|(
name|bp
operator|=
name|tutab
operator|.
name|b_actf
operator|)
operator|==
name|NULL
condition|)
return|return;
if|if
condition|(
name|tu
operator|.
name|state
operator|!=
name|IDLE
condition|)
block|{
name|tureset
argument_list|()
expr_stmt|;
return|return;
block|}
name|tutab
operator|.
name|b_active
operator|++
expr_stmt|;
name|tutab
operator|.
name|b_errcnt
operator|=
literal|0
expr_stmt|;
name|tucmd
operator|.
name|pk_op
operator|=
name|bp
operator|->
name|b_flags
operator|&
name|B_READ
condition|?
name|TUOP_READ
else|:
name|TUOP_WRITE
expr_stmt|;
name|tucmd
operator|.
name|pk_unit
operator|=
name|minor
argument_list|(
name|bp
operator|->
name|b_dev
argument_list|)
expr_stmt|;
name|tucmd
operator|.
name|pk_count
operator|=
name|tu
operator|.
name|count
operator|=
name|bp
operator|->
name|b_bcount
expr_stmt|;
name|tucmd
operator|.
name|pk_block
operator|=
name|bp
operator|->
name|b_blkno
expr_stmt|;
name|tucmd
operator|.
name|pk_chksum
operator|=
name|tuchk
argument_list|(
operator|*
operator|(
operator|(
name|short
operator|*
operator|)
operator|&
name|tucmd
operator|)
argument_list|,
operator|(
name|caddr_t
operator|)
operator|&
name|tucmd
operator|.
name|pk_op
argument_list|,
operator|(
name|int
operator|)
name|tucmd
operator|.
name|pk_mcount
argument_list|)
expr_stmt|;
name|tu
operator|.
name|state
operator|=
name|bp
operator|->
name|b_flags
operator|&
name|B_READ
condition|?
name|SENDR
else|:
name|SENDW
expr_stmt|;
name|tu
operator|.
name|addr
operator|=
name|bp
operator|->
name|b_un
operator|.
name|b_addr
expr_stmt|;
name|tu
operator|.
name|count
operator|=
name|bp
operator|->
name|b_bcount
expr_stmt|;
name|tu
operator|.
name|wbptr
operator|=
operator|(
name|u_char
operator|*
operator|)
operator|&
name|tucmd
expr_stmt|;
name|tu
operator|.
name|wcnt
operator|=
sizeof|sizeof
name|tucmd
expr_stmt|;
name|tuxintr
argument_list|()
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * TU58 receiver interrupt  */
end_comment

begin_macro
name|turintr
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
specifier|register
name|int
name|c
decl_stmt|;
name|c
operator|=
name|mfpr
argument_list|(
name|CSRD
argument_list|)
operator|&
literal|0xff
expr_stmt|;
comment|/* get the char, clear the interrupt */
if|if
condition|(
name|MRSP
condition|)
block|{
while|while
condition|(
operator|(
name|mfpr
argument_list|(
name|CSTS
argument_list|)
operator|&
name|READY
operator|)
operator|==
literal|0
condition|)
empty_stmt|;
name|mtpr
argument_list|(
name|CSTD
argument_list|,
name|TUF_CONT
argument_list|)
expr_stmt|;
comment|/* ACK */
block|}
if|if
condition|(
name|tu
operator|.
name|rcnt
condition|)
block|{
comment|/* still waiting for data? */
operator|*
name|tu
operator|.
name|rbptr
operator|++
operator|=
name|c
expr_stmt|;
comment|/* yup, put it there */
if|if
condition|(
operator|--
name|tu
operator|.
name|rcnt
condition|)
comment|/* decrement count, any left? */
return|return;
comment|/* get some more */
block|}
comment|/* 	 * We got all the data we were expecting for now, 	 * switch on the state of the transfer. 	 */
switch|switch
condition|(
name|tu
operator|.
name|state
condition|)
block|{
case|case
name|INIT2
case|:
if|if
condition|(
name|c
operator|==
name|TUF_CONT
condition|)
comment|/* did we get the expected continue? */
name|tu
operator|.
name|state
operator|=
name|IDLE
expr_stmt|;
else|else
name|tu
operator|.
name|state
operator|=
name|INIT1
expr_stmt|;
comment|/* bad news... */
name|tu
operator|.
name|flag
operator|=
literal|0
expr_stmt|;
name|wakeup
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|tu
argument_list|)
expr_stmt|;
name|tustart
argument_list|()
expr_stmt|;
break|break;
case|case
name|WAIT
case|:
comment|/* waiting for continue */
if|if
condition|(
name|c
operator|!=
name|TUF_CONT
condition|)
block|{
name|tu
operator|.
name|state
operator|=
name|INIT1
expr_stmt|;
comment|/* bad news... */
break|break;
block|}
name|tu
operator|.
name|flag
operator|=
literal|0
expr_stmt|;
name|tudata
operator|.
name|pk_flag
operator|=
name|TUF_DATA
expr_stmt|;
name|tudata
operator|.
name|pk_mcount
operator|=
name|MIN
argument_list|(
literal|128
argument_list|,
name|tu
operator|.
name|count
argument_list|)
expr_stmt|;
name|tudata
operator|.
name|pk_chksum
operator|=
name|tuchk
argument_list|(
operator|*
operator|(
operator|(
name|short
operator|*
operator|)
operator|&
name|tudata
operator|)
argument_list|,
operator|(
name|caddr_t
operator|)
name|tu
operator|.
name|addr
argument_list|,
operator|(
name|int
operator|)
name|tudata
operator|.
name|pk_mcount
argument_list|)
expr_stmt|;
name|tu
operator|.
name|state
operator|=
name|SENDH
expr_stmt|;
name|tu
operator|.
name|wbptr
operator|=
operator|(
name|u_char
operator|*
operator|)
operator|&
name|tudata
expr_stmt|;
name|tu
operator|.
name|wcnt
operator|=
literal|2
expr_stmt|;
name|tuxintr
argument_list|()
expr_stmt|;
break|break;
case|case
name|GETH
case|:
comment|/* got header, get data */
if|if
condition|(
name|tudata
operator|.
name|pk_flag
operator|==
name|TUF_DATA
condition|)
comment|/* data message? */
name|tu
operator|.
name|rbptr
operator|=
operator|(
name|u_char
operator|*
operator|)
name|tu
operator|.
name|addr
expr_stmt|;
comment|/* yes put in buffer */
name|tu
operator|.
name|rcnt
operator|=
name|tudata
operator|.
name|pk_mcount
expr_stmt|;
comment|/* amount to get */
name|tu
operator|.
name|state
operator|=
name|GETD
expr_stmt|;
break|break;
case|case
name|GETD
case|:
comment|/* got data, get checksum */
name|tu
operator|.
name|rbptr
operator|=
operator|(
name|u_char
operator|*
operator|)
operator|&
name|tudata
operator|.
name|pk_chksum
expr_stmt|;
name|tu
operator|.
name|rcnt
operator|=
sizeof|sizeof
name|tudata
operator|.
name|pk_chksum
expr_stmt|;
name|tu
operator|.
name|state
operator|=
name|GETC
expr_stmt|;
break|break;
case|case
name|GET
case|:
case|case
name|GETC
case|:
comment|/* got entire packet */
ifdef|#
directive|ifdef
name|notdef
if|if
condition|(
name|tudata
operator|.
name|pk_chksum
operator|!=
name|tuchk
argument_list|(
operator|*
operator|(
operator|(
name|short
operator|*
operator|)
operator|&
name|tudata
operator|)
argument_list|,
name|tudata
operator|.
name|pk_flag
operator|==
name|TUF_DATA
condition|?
name|tu
operator|.
name|addr
else|:
operator|&
name|tudata
operator|.
name|pk_op
argument_list|,
operator|(
name|int
operator|)
name|tudata
operator|.
name|pk_mcount
argument_list|)
condition|)
name|tu
operator|.
name|cerrs
operator|++
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
name|tudata
operator|.
name|pk_flag
operator|==
name|TUF_DATA
condition|)
block|{
comment|/* data packet, advance to next */
name|tu
operator|.
name|addr
operator|+=
name|tudata
operator|.
name|pk_mcount
expr_stmt|;
name|tu
operator|.
name|count
operator|-=
name|tudata
operator|.
name|pk_mcount
expr_stmt|;
name|tu
operator|.
name|state
operator|=
name|GETH
expr_stmt|;
name|tu
operator|.
name|rbptr
operator|=
operator|(
name|u_char
operator|*
operator|)
operator|&
name|tudata
expr_stmt|;
comment|/* next packet */
name|tu
operator|.
name|rcnt
operator|=
literal|2
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|tudata
operator|.
name|pk_flag
operator|==
name|TUF_CMD
operator|&&
name|tudata
operator|.
name|pk_op
operator|==
name|TUOP_END
condition|)
block|{
comment|/* end packet, idle and reenable transmitter */
name|tu
operator|.
name|state
operator|=
name|IDLE
expr_stmt|;
name|tu
operator|.
name|flag
operator|=
literal|0
expr_stmt|;
name|mtpr
argument_list|(
name|CSTS
argument_list|,
name|IE
argument_list|)
expr_stmt|;
name|printd
argument_list|(
literal|"ON "
argument_list|)
expr_stmt|;
if|if
condition|(
operator|(
name|bp
operator|=
name|tutab
operator|.
name|b_actf
operator|)
operator|==
name|NULL
condition|)
block|{
name|printf
argument_list|(
literal|"tu: no bp!\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"active %d\n"
argument_list|,
name|tutab
operator|.
name|b_active
argument_list|)
expr_stmt|;
name|tustart
argument_list|()
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|tudata
operator|.
name|pk_mod
operator|<
literal|0
condition|)
block|{
comment|/* hard error */
name|bp
operator|->
name|b_flags
operator||=
name|B_ERROR
expr_stmt|;
name|tu
operator|.
name|herrs
operator|++
expr_stmt|;
name|harderr
argument_list|(
name|bp
argument_list|,
literal|"tu"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"  pk_mod %d\n"
argument_list|,
operator|-
name|tudata
operator|.
name|pk_mod
argument_list|)
expr_stmt|;
block|}
elseif|else
if|if
condition|(
name|tudata
operator|.
name|pk_mod
operator|>
literal|0
condition|)
comment|/* soft error */
name|tu
operator|.
name|serrs
operator|++
expr_stmt|;
name|tutab
operator|.
name|b_active
operator|=
name|NULL
expr_stmt|;
name|tutab
operator|.
name|b_actf
operator|=
name|bp
operator|->
name|av_forw
expr_stmt|;
name|bp
operator|->
name|b_resid
operator|=
name|tu
operator|.
name|count
expr_stmt|;
name|iodone
argument_list|(
name|bp
argument_list|)
expr_stmt|;
name|tustart
argument_list|()
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"neither data nor end: %o %o\n"
argument_list|,
name|tudata
operator|.
name|pk_flag
operator|&
literal|0xff
argument_list|,
name|tudata
operator|.
name|pk_op
operator|&
literal|0xff
argument_list|)
expr_stmt|;
name|mtpr
argument_list|(
name|CSRS
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* flush the rest */
name|tu
operator|.
name|state
operator|=
name|INIT1
expr_stmt|;
block|}
break|break;
case|case
name|IDLE
case|:
case|case
name|INIT1
case|:
break|break;
default|default:
if|if
condition|(
name|c
operator|==
name|TUF_INITF
condition|)
block|{
name|printf
argument_list|(
literal|"TU protocol error, state %d\n"
argument_list|,
name|tu
operator|.
name|state
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%o %d %d\n"
argument_list|,
name|tucmd
operator|.
name|pk_op
argument_list|,
name|tucmd
operator|.
name|pk_count
argument_list|,
name|tucmd
operator|.
name|pk_block
argument_list|)
expr_stmt|;
name|tutab
operator|.
name|b_active
operator|=
name|NULL
expr_stmt|;
if|if
condition|(
name|bp
operator|=
name|tutab
operator|.
name|b_actf
condition|)
block|{
name|bp
operator|->
name|b_flags
operator||=
name|B_ERROR
expr_stmt|;
name|tutab
operator|.
name|b_actf
operator|=
name|bp
operator|->
name|av_forw
expr_stmt|;
name|iodone
argument_list|(
name|bp
argument_list|)
expr_stmt|;
block|}
name|tu
operator|.
name|state
operator|=
name|INIT1
expr_stmt|;
block|}
else|else
block|{
name|printf
argument_list|(
literal|"TU receive state error %d %o\n"
argument_list|,
name|tu
operator|.
name|state
argument_list|,
name|c
argument_list|)
expr_stmt|;
comment|/*	tu.state = INIT1; */
name|wakeup
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|tu
argument_list|)
expr_stmt|;
block|}
block|}
block|}
end_block

begin_comment
comment|/*  * TU58 transmitter interrupt  */
end_comment

begin_macro
name|tuxintr
argument_list|()
end_macro

begin_block
block|{
name|top
label|:
if|if
condition|(
name|tu
operator|.
name|wcnt
condition|)
block|{
comment|/* still stuff to send, send one byte */
while|while
condition|(
operator|(
name|mfpr
argument_list|(
name|CSTS
argument_list|)
operator|&
name|READY
operator|)
operator|==
literal|0
condition|)
empty_stmt|;
name|mtpr
argument_list|(
name|CSTD
argument_list|,
operator|*
name|tu
operator|.
name|wbptr
operator|++
argument_list|)
expr_stmt|;
name|tu
operator|.
name|wcnt
operator|--
expr_stmt|;
return|return;
block|}
comment|/* 	 * Last message byte was sent out. 	 * Switch on state of transfer. 	 */
name|printd
argument_list|(
literal|"tuxintr: state %d\n"
argument_list|,
name|tu
operator|.
name|state
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|tu
operator|.
name|state
condition|)
block|{
case|case
name|INIT1
case|:
comment|/* two nulls sent, remove break, send inits */
name|mtpr
argument_list|(
name|CSTS
argument_list|,
name|IE
argument_list|)
expr_stmt|;
name|printd
argument_list|(
literal|"ON2 "
argument_list|)
expr_stmt|;
name|tu
operator|.
name|state
operator|=
name|INIT2
expr_stmt|;
name|tu
operator|.
name|wbptr
operator|=
name|tuinit
expr_stmt|;
name|tu
operator|.
name|wcnt
operator|=
sizeof|sizeof
name|tuinit
expr_stmt|;
goto|goto
name|top
goto|;
case|case
name|INIT2
case|:
comment|/* inits sent, wait for continue */
operator|(
name|void
operator|)
name|mfpr
argument_list|(
name|CSRD
argument_list|)
expr_stmt|;
name|mtpr
argument_list|(
name|CSRS
argument_list|,
name|IE
argument_list|)
expr_stmt|;
name|tu
operator|.
name|flag
operator|=
literal|1
expr_stmt|;
break|break;
case|case
name|IDLE
case|:
comment|/* stray interrupt? */
break|break;
case|case
name|SENDR
case|:
comment|/* read cmd packet sent, get ready for data */
name|tu
operator|.
name|state
operator|=
name|GETH
expr_stmt|;
name|tu
operator|.
name|rbptr
operator|=
operator|(
name|u_char
operator|*
operator|)
operator|&
name|tudata
expr_stmt|;
name|tu
operator|.
name|rcnt
operator|=
literal|2
expr_stmt|;
name|tu
operator|.
name|flag
operator|=
literal|1
expr_stmt|;
name|mtpr
argument_list|(
name|CSTS
argument_list|,
literal|0
argument_list|)
expr_stmt|;
comment|/* disable transmitter interrupts */
name|printd
argument_list|(
literal|"OFF "
argument_list|)
expr_stmt|;
break|break;
case|case
name|SENDW
case|:
comment|/* write cmd packet sent, wait for continue */
name|tu
operator|.
name|state
operator|=
name|WAIT
expr_stmt|;
name|tu
operator|.
name|flag
operator|=
literal|1
expr_stmt|;
if|if
condition|(
operator|(
name|mfpr
argument_list|(
name|CSRS
argument_list|)
operator|&
name|IE
operator|)
operator|==
literal|0
condition|)
block|{
name|printf
argument_list|(
literal|"NO IE\n"
argument_list|)
expr_stmt|;
name|mtpr
argument_list|(
name|CSRS
argument_list|,
name|IE
argument_list|)
expr_stmt|;
block|}
break|break;
case|case
name|SENDH
case|:
comment|/* header sent, send data */
name|tu
operator|.
name|state
operator|=
name|SENDD
expr_stmt|;
name|tu
operator|.
name|wbptr
operator|=
operator|(
name|u_char
operator|*
operator|)
name|tu
operator|.
name|addr
expr_stmt|;
name|tu
operator|.
name|wcnt
operator|=
name|tudata
operator|.
name|pk_mcount
expr_stmt|;
goto|goto
name|top
goto|;
case|case
name|SENDD
case|:
comment|/* data sent, send checksum */
name|tu
operator|.
name|state
operator|=
name|SENDC
expr_stmt|;
name|tu
operator|.
name|wbptr
operator|=
operator|(
name|u_char
operator|*
operator|)
operator|&
name|tudata
operator|.
name|pk_chksum
expr_stmt|;
name|tu
operator|.
name|wcnt
operator|=
sizeof|sizeof
name|tudata
operator|.
name|pk_chksum
expr_stmt|;
goto|goto
name|top
goto|;
case|case
name|SENDC
case|:
comment|/* checksum sent, wait for continue */
name|tu
operator|.
name|addr
operator|+=
name|tudata
operator|.
name|pk_mcount
expr_stmt|;
comment|/* update buffer address */
name|tu
operator|.
name|count
operator|-=
name|tudata
operator|.
name|pk_mcount
expr_stmt|;
comment|/* and count */
if|if
condition|(
name|tu
operator|.
name|count
operator|==
literal|0
condition|)
block|{
comment|/* all done? */
name|tu
operator|.
name|state
operator|=
name|GET
expr_stmt|;
comment|/* set up to get end packet */
name|tu
operator|.
name|rbptr
operator|=
operator|(
name|u_char
operator|*
operator|)
operator|&
name|tudata
expr_stmt|;
name|tu
operator|.
name|rcnt
operator|=
sizeof|sizeof
name|tudata
expr_stmt|;
name|tu
operator|.
name|flag
operator|=
literal|1
expr_stmt|;
name|mtpr
argument_list|(
name|CSTS
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|printd
argument_list|(
literal|"OFF2 "
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|tu
operator|.
name|state
operator|=
name|WAIT
expr_stmt|;
comment|/* wait for continue */
name|tu
operator|.
name|flag
operator|=
literal|1
expr_stmt|;
block|}
break|break;
default|default:
comment|/* random interrupt, probably from MRSP ACK */
break|break;
block|}
name|printd
argument_list|(
literal|"  new state %d\n"
argument_list|,
name|tu
operator|.
name|state
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * Compute checksum TU58 fashion  *  * *** WARNING ***  * This procedure is not in C because  * it has to be fast and it is hard to  * do add-carry in C.  Sorry.  */
end_comment

begin_expr_stmt
name|tuchk
argument_list|(
name|word0
argument_list|,
name|wp
argument_list|,
name|n
argument_list|)
specifier|register
name|int
name|word0
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* known to be r11 */
end_comment

begin_decl_stmt
specifier|register
name|caddr_t
name|wp
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* known to be r10 */
end_comment

begin_decl_stmt
specifier|register
name|int
name|n
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* known to be r9 */
end_comment

begin_block
block|{
ifdef|#
directive|ifdef
name|lint
comment|/* for some reason ARGSUSED doesn't work to quiet lint */
name|word0
operator|=
literal|0
expr_stmt|;
name|n
operator|=
name|word0
expr_stmt|;
name|word0
operator|=
name|n
expr_stmt|;
name|wp
operator|=
literal|0
expr_stmt|;
name|wp
operator|=
name|wp
expr_stmt|;
endif|#
directive|endif
asm|asm("loop:");
asm|asm("	addw2	(r10)+,r11");
comment|/* add a word to sum */
asm|asm("	adwc	$0,r11");
comment|/* add in carry, end-around */
asm|asm("	acbl	$2,$-2,r9,loop");
comment|/* done yet? */
asm|asm("	blbc	r9,ok");
comment|/* odd byte count? */
asm|asm("	movzbw	(r10),r10");
comment|/* yes, get last byte */
asm|asm("	addw2	r10,r11");
comment|/* add it in */
asm|asm("	adwc	$0,r11");
comment|/* and the carry */
asm|asm("ok:");
asm|asm("	movl	r11,r0");
comment|/* return sum */
ifdef|#
directive|ifdef
name|lint
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
block|}
end_block

begin_macro
name|tuwatch
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|int
name|s
decl_stmt|;
specifier|register
name|struct
name|buf
modifier|*
name|bp
decl_stmt|;
if|if
condition|(
name|tutimer
operator|==
literal|0
condition|)
block|{
name|tu
operator|.
name|flag
operator|=
literal|0
expr_stmt|;
return|return;
block|}
if|if
condition|(
name|tu
operator|.
name|flag
condition|)
name|tu
operator|.
name|flag
operator|++
expr_stmt|;
if|if
condition|(
name|tu
operator|.
name|flag
operator|>
literal|40
condition|)
block|{
name|printf
argument_list|(
literal|"tu: read stalled\n"
argument_list|)
expr_stmt|;
name|printf
argument_list|(
literal|"%X %X %X %X %X %X %X %X\n"
argument_list|,
name|tu
operator|.
name|rbptr
argument_list|,
name|tu
operator|.
name|rcnt
argument_list|,
name|tu
operator|.
name|wbptr
argument_list|,
name|tu
operator|.
name|wcnt
argument_list|,
name|tu
operator|.
name|state
argument_list|,
name|tu
operator|.
name|flag
argument_list|,
name|tu
operator|.
name|addr
argument_list|,
name|tu
operator|.
name|count
argument_list|)
expr_stmt|;
name|tu
operator|.
name|flag
operator|=
literal|0
expr_stmt|;
name|s
operator|=
name|splx
argument_list|(
name|TUIPL
argument_list|)
expr_stmt|;
operator|(
name|void
operator|)
name|mfpr
argument_list|(
name|CSRD
argument_list|)
expr_stmt|;
name|mtpr
argument_list|(
name|CSRS
argument_list|,
name|IE
argument_list|)
expr_stmt|;
comment|/* in case we were flushing */
name|mtpr
argument_list|(
name|CSTS
argument_list|,
name|IE
argument_list|)
expr_stmt|;
name|tu
operator|.
name|state
operator|=
name|IDLE
expr_stmt|;
if|if
condition|(
name|tutab
operator|.
name|b_active
condition|)
block|{
if|if
condition|(
operator|++
name|tutab
operator|.
name|b_errcnt
operator|>
literal|1
condition|)
block|{
if|if
condition|(
name|bp
operator|=
name|tutab
operator|.
name|b_actf
condition|)
block|{
name|bp
operator|->
name|b_flags
operator||=
name|B_ERROR
expr_stmt|;
name|iodone
argument_list|(
name|bp
argument_list|)
expr_stmt|;
block|}
block|}
else|else
name|tustart
argument_list|()
expr_stmt|;
block|}
else|else
name|wakeup
argument_list|(
operator|(
name|caddr_t
operator|)
operator|&
name|tu
argument_list|)
expr_stmt|;
name|splx
argument_list|(
name|s
argument_list|)
expr_stmt|;
block|}
name|timeout
argument_list|(
name|tuwatch
argument_list|,
operator|(
name|caddr_t
operator|)
literal|0
argument_list|,
name|hz
argument_list|)
expr_stmt|;
block|}
end_block

begin_endif
endif|#
directive|endif
end_endif

end_unit

