begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	cyreg.h	7.3	87/01/11	*/
end_comment

begin_comment
comment|/*  * Tapemaster controller definitions.  */
end_comment

begin_comment
comment|/* for byte swapping Multibus values */
end_comment

begin_define
define|#
directive|define
name|htoms
parameter_list|(
name|x
parameter_list|)
value|(short)((((x)>>8)&0xff) | (((x)<<8)&0xff00))
end_define

begin_define
define|#
directive|define
name|b_repcnt
value|b_bcount
end_define

begin_define
define|#
directive|define
name|b_command
value|b_resid
end_define

begin_comment
comment|/*  * System configuration pointer.  * Memory address is jumpered on controller.  */
end_comment

begin_struct
struct|struct
name|cyscp
block|{
name|char
name|csp_buswidth
decl_stmt|;
comment|/* system bus width */
define|#
directive|define
name|CSP_16BITS
value|1
comment|/* 16-bit system bus */
define|#
directive|define
name|CSP_8BITS
value|0
comment|/* 8-bit system bus */
name|char
name|csp_unused
decl_stmt|;
name|u_char
name|csp_scb
index|[
literal|4
index|]
decl_stmt|;
comment|/* point to system config block */
block|}
struct|;
end_struct

begin_comment
comment|/*  * System configuration block  */
end_comment

begin_struct
struct|struct
name|cyscb
block|{
name|char
name|csb_fixed
decl_stmt|;
comment|/* fixed value code (must be 3) */
name|char
name|csb_unused
decl_stmt|;
comment|/* unused */
name|u_char
name|csb_ccb
index|[
literal|4
index|]
decl_stmt|;
comment|/* pointer to channel control block */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|CSB_FIXED
value|0x3
end_define

begin_comment
comment|/*  * Channel control block definitions  */
end_comment

begin_struct
struct|struct
name|cyccb
block|{
name|char
name|cbcw
decl_stmt|;
comment|/* channel control word */
name|char
name|cbgate
decl_stmt|;
comment|/* tpb access gate */
name|u_char
name|cbtpb
index|[
literal|4
index|]
decl_stmt|;
comment|/* first tape parameter block */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|GATE_OPEN
value|(char)(0x00)
end_define

begin_define
define|#
directive|define
name|GATE_CLOSED
value|(char)(0xff)
end_define

begin_define
define|#
directive|define
name|CY_GO
parameter_list|(
name|addr
parameter_list|)
value|movob((addr), 0xff)
end_define

begin_comment
comment|/* channel attention */
end_comment

begin_define
define|#
directive|define
name|CY_RESET
parameter_list|(
name|addr
parameter_list|)
value|movob((addr)+1, 0xff)
end_define

begin_comment
comment|/* software controller reset */
end_comment

begin_define
define|#
directive|define
name|CBCW_IE
value|0x11
end_define

begin_comment
comment|/* interrupt on cmd completion */
end_comment

begin_define
define|#
directive|define
name|CBCW_CLRINT
value|0x09
end_define

begin_comment
comment|/* clear active interrupt */
end_comment

begin_comment
comment|/*  * Tape parameter block definitions  */
end_comment

begin_struct
struct|struct
name|cytpb
block|{
name|long
name|tpcmd
decl_stmt|;
comment|/* command, see below */
name|short
name|tpcontrol
decl_stmt|;
comment|/* control word */
name|short
name|tpcount
decl_stmt|;
comment|/* return count */
name|short
name|tpsize
decl_stmt|;
comment|/* buffer size */
name|short
name|tprec
decl_stmt|;
comment|/* records/overrun */
name|u_char
name|tpdata
index|[
literal|4
index|]
decl_stmt|;
comment|/* pointer to source/dest */
name|short
name|tpstatus
decl_stmt|;
comment|/* status */
name|u_char
name|tplink
index|[
literal|4
index|]
decl_stmt|;
comment|/* pointer to next parameter block */
block|}
struct|;
end_struct

begin_comment
comment|/* control field bit definitions */
end_comment

begin_define
define|#
directive|define
name|CYCW_UNIT
value|(0x000c<<8)
end_define

begin_comment
comment|/* unit select mask, 2 bit field */
end_comment

begin_define
define|#
directive|define
name|CYCW_IE
value|(0x0020<<8)
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|CYCW_LOCK
value|(0x0080<<8)
end_define

begin_comment
comment|/* bus lock flag */
end_comment

begin_define
define|#
directive|define
name|CYCW_REV
value|(0x0400>>8)
end_define

begin_comment
comment|/* reverse flag */
end_comment

begin_define
define|#
directive|define
name|CYCW_SPEED
value|(0x0800>>8)
end_define

begin_comment
comment|/* speed/density */
end_comment

begin_define
define|#
directive|define
name|CYCW_25IPS
value|0
end_define

begin_define
define|#
directive|define
name|CYCW_100IPS
value|(0x0800>>8)
end_define

begin_define
define|#
directive|define
name|CYCW_WIDTH
value|(0x8000>>8)
end_define

begin_comment
comment|/* width */
end_comment

begin_define
define|#
directive|define
name|CYCW_8BITS
value|0
end_define

begin_define
define|#
directive|define
name|CYCW_16BITS
value|(0x8000>>8)
end_define

begin_define
define|#
directive|define
name|CYCW_BITS
value|"\20\3REV\005100IPS\00716BITS\16IE\20LOCK"
end_define

begin_comment
comment|/*  * Controller commands  */
end_comment

begin_comment
comment|/* control status/commands */
end_comment

begin_define
define|#
directive|define
name|CY_CONFIG
value|(0x00<<24)
end_define

begin_comment
comment|/* configure */
end_comment

begin_define
define|#
directive|define
name|CY_NOP
value|(0x20<<24)
end_define

begin_comment
comment|/* no operation */
end_comment

begin_define
define|#
directive|define
name|CY_SETPAGE
value|(0x08<<24)
end_define

begin_comment
comment|/* set page (addr bits 20-23) */
end_comment

begin_define
define|#
directive|define
name|CY_SENSE
value|(0x28<<24)
end_define

begin_comment
comment|/* drive status */
end_comment

begin_define
define|#
directive|define
name|CY_CLRINT
value|(0x9c<<24)
end_define

begin_comment
comment|/* clear Multibus interrupt */
end_comment

begin_comment
comment|/* tape position commands */
end_comment

begin_define
define|#
directive|define
name|CY_REW
value|(0x34<<24)
end_define

begin_comment
comment|/* rewind tape */
end_comment

begin_define
define|#
directive|define
name|CY_OFFL
value|(0x38<<24)
end_define

begin_comment
comment|/* off_line and unload */
end_comment

begin_define
define|#
directive|define
name|CY_WEOF
value|(0x40<<24)
end_define

begin_comment
comment|/* write end-of-file mark */
end_comment

begin_define
define|#
directive|define
name|CY_SFORW
value|(0x70<<24)
end_define

begin_comment
comment|/* space record forward */
end_comment

begin_define
define|#
directive|define
name|CY_SREV
value|(CY_SFORW|CYCW_REV)
end_define

begin_comment
comment|/* space record backwards */
end_comment

begin_define
define|#
directive|define
name|CY_FSF
value|(0x44<<24)
end_define

begin_comment
comment|/* space file forward */
end_comment

begin_define
define|#
directive|define
name|CY_BSF
value|(CY_FSF|CYCW_REV)
end_define

begin_comment
comment|/* space file backwards */
end_comment

begin_define
define|#
directive|define
name|CY_ERASE
value|(0x4c<<24)
end_define

begin_comment
comment|/* erase record */
end_comment

begin_comment
comment|/* data transfer commands */
end_comment

begin_define
define|#
directive|define
name|CY_BRCOM
value|(0x10<<24)
end_define

begin_comment
comment|/* read buffered */
end_comment

begin_define
define|#
directive|define
name|CY_BWCOM
value|(0x14<<24)
end_define

begin_comment
comment|/* write buffered */
end_comment

begin_define
define|#
directive|define
name|CY_RCOM
value|(0x2c<<24)
end_define

begin_comment
comment|/* read tape unbuffered */
end_comment

begin_define
define|#
directive|define
name|CY_WCOM
value|(0x30<<24)
end_define

begin_comment
comment|/* write tape unbuffered */
end_comment

begin_comment
comment|/* status field bit definitions */
end_comment

begin_define
define|#
directive|define
name|CYS_WP
value|(0x0002<<8)
end_define

begin_comment
comment|/* write protected, no write ring */
end_comment

begin_define
define|#
directive|define
name|CYS_BSY
value|(0x0004<<8)
end_define

begin_comment
comment|/* formatter busy */
end_comment

begin_define
define|#
directive|define
name|CYS_RDY
value|(0x0008<<8)
end_define

begin_comment
comment|/* drive ready */
end_comment

begin_define
define|#
directive|define
name|CYS_EOT
value|(0x0010<<8)
end_define

begin_comment
comment|/* end of tape detected */
end_comment

begin_define
define|#
directive|define
name|CYS_BOT
value|(0x0020<<8)
end_define

begin_comment
comment|/* tape is at load point */
end_comment

begin_define
define|#
directive|define
name|CYS_OL
value|(0x0040<<8)
end_define

begin_comment
comment|/* drive on_line */
end_comment

begin_define
define|#
directive|define
name|CYS_FM
value|(0x0080<<8)
end_define

begin_comment
comment|/* filemark detected */
end_comment

begin_define
define|#
directive|define
name|CYS_ERR
value|(0x1f00>>8)
end_define

begin_comment
comment|/* error value mask */
end_comment

begin_define
define|#
directive|define
name|CYS_CR
value|(0x2000>>8)
end_define

begin_comment
comment|/* controller executed retries */
end_comment

begin_define
define|#
directive|define
name|CYS_CC
value|(0x4000>>8)
end_define

begin_comment
comment|/* command completed successfully */
end_comment

begin_define
define|#
directive|define
name|CYS_CE
value|(0x8000>>8)
end_define

begin_comment
comment|/* command execution has begun */
end_comment

begin_define
define|#
directive|define
name|CYS_BITS
value|"\20\6CR\7CC\10CE\12WP\13BSY\14RDY\15EOT/BOT\16BOT\17OL\20FM"
end_define

begin_comment
comment|/* error codes for CYS_ERR */
end_comment

begin_define
define|#
directive|define
name|CYER_TIMOUT
value|0x01
end_define

begin_comment
comment|/* timed out data busy false */
end_comment

begin_define
define|#
directive|define
name|CYER_TIMOUT1
value|0x02
end_define

begin_comment
comment|/* data busy false,formatter,ready */
end_comment

begin_define
define|#
directive|define
name|CYER_TIMOUT2
value|0x03
end_define

begin_comment
comment|/* time out ready busy false */
end_comment

begin_define
define|#
directive|define
name|CYER_TIMOUT3
value|0x04
end_define

begin_comment
comment|/* time out ready busy true */
end_comment

begin_define
define|#
directive|define
name|CYER_TIMOUT4
value|0x05
end_define

begin_comment
comment|/* time out data busy true */
end_comment

begin_define
define|#
directive|define
name|CYER_NXM
value|0x06
end_define

begin_comment
comment|/* time out memory */
end_comment

begin_define
define|#
directive|define
name|CYER_BLANK
value|0x07
end_define

begin_comment
comment|/* blank tape */
end_comment

begin_define
define|#
directive|define
name|CYER_DIAG
value|0x08
end_define

begin_comment
comment|/* micro-diagnostic */
end_comment

begin_define
define|#
directive|define
name|CYER_EOT
value|0x09
end_define

begin_comment
comment|/* EOT forward, BOT rev. */
end_comment

begin_define
define|#
directive|define
name|CYER_BOT
value|0x09
end_define

begin_comment
comment|/* EOT forward, BOT rev. */
end_comment

begin_define
define|#
directive|define
name|CYER_HERR
value|0x0a
end_define

begin_comment
comment|/* retry unsuccessful */
end_comment

begin_define
define|#
directive|define
name|CYER_FIFO
value|0x0b
end_define

begin_comment
comment|/* FIFO over/under flow */
end_comment

begin_define
define|#
directive|define
name|CYER_PARITY
value|0x0d
end_define

begin_comment
comment|/* drive to tapemaster parity error */
end_comment

begin_define
define|#
directive|define
name|CYER_CKSUM
value|0x0e
end_define

begin_comment
comment|/* prom checksum */
end_comment

begin_define
define|#
directive|define
name|CYER_STROBE
value|0x0f
end_define

begin_comment
comment|/* time out tape strobe */
end_comment

begin_define
define|#
directive|define
name|CYER_NOTRDY
value|0x10
end_define

begin_comment
comment|/* tape not ready */
end_comment

begin_define
define|#
directive|define
name|CYER_PROT
value|0x11
end_define

begin_comment
comment|/* write, no enable ring */
end_comment

begin_define
define|#
directive|define
name|CYER_JUMPER
value|0x13
end_define

begin_comment
comment|/* missing diagnostic jumper */
end_comment

begin_define
define|#
directive|define
name|CYER_LINK
value|0x14
end_define

begin_comment
comment|/* bad link, link inappropriate */
end_comment

begin_define
define|#
directive|define
name|CYER_FM
value|0x15
end_define

begin_comment
comment|/* unexpected filemark */
end_comment

begin_define
define|#
directive|define
name|CYER_PARAM
value|0x16
end_define

begin_comment
comment|/* bad parameter, byte count ? */
end_comment

begin_define
define|#
directive|define
name|CYER_HDWERR
value|0x18
end_define

begin_comment
comment|/* unidentified hardware error */
end_comment

begin_define
define|#
directive|define
name|CYER_NOSTRM
value|0x19
end_define

begin_comment
comment|/* streaming terminated */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CYERROR
end_ifdef

begin_decl_stmt
name|char
modifier|*
name|cyerror
index|[]
init|=
block|{
literal|"no error"
block|,
literal|"timeout"
block|,
literal|"timeout1"
block|,
literal|"timeout2"
block|,
literal|"timeout3"
block|,
literal|"timeout4"
block|,
literal|"non-existent memory"
block|,
literal|"blank tape"
block|,
literal|"micro-diagnostic"
block|,
literal|"eot/bot detected"
block|,
literal|"retry unsuccessful"
block|,
literal|"fifo over/under-flow"
block|,
literal|"#0xc"
block|,
literal|"drive to controller parity error"
block|,
literal|"prom checksum"
block|,
literal|"time out tape strobe (record length error)"
block|,
literal|"tape not ready"
block|,
literal|"write protected"
block|,
literal|"#0x12"
block|,
literal|"missing diagnostic jumper"
block|,
literal|"invalid link pointer"
block|,
literal|"unexpected file mark"
block|,
literal|"invalid byte count/parameter"
block|,
literal|"#0x17"
block|,
literal|"unidentified hardware error"
block|,
literal|"streaming terminated"
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|NCYERROR
value|(sizeof (cyerror) / sizeof (cyerror[0]))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Masks defining hard and soft errors (must check against 1<<CYER_code).  */
end_comment

begin_define
define|#
directive|define
name|CYMASK
parameter_list|(
name|e
parameter_list|)
value|(1<<(CYER_
comment|/**/
value|e))
end_define

begin_define
define|#
directive|define
name|CYER_HARD
value|(CYMASK(TIMOUT)|CYMASK(TIMOUT1)|CYMASK(TIMOUT2)|\     CYMASK(TIMOUT3)|CYMASK(TIMOUT4)|CYMASK(NXM)|CYMASK(DIAG)|CYMASK(JUMPER)|\     CYMASK(STROBE)|CYMASK(PROT)|CYMASK(CKSUM)|CYMASK(HERR)|CYMASK(BLANK))
end_define

begin_define
define|#
directive|define
name|CYER_SOFT
value|(CYMASK(FIFO)|CYMASK(NOTRDY)|CYMASK(PARITY))
end_define

end_unit

