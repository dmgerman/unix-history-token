begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	cyreg.h	7.1	86/01/05	*/
end_comment

begin_comment
comment|/* get controller attention and start an operation */
end_comment

begin_define
define|#
directive|define
name|CY_ATTENTION
parameter_list|(
name|addr
parameter_list|)
value|movob(addr, 0xff)
end_define

begin_comment
comment|/* also known as: GO */
end_comment

begin_define
define|#
directive|define
name|CY_RESET
parameter_list|(
name|addr
parameter_list|)
value|CY_ATTENTION(addr+1)
end_define

begin_comment
comment|/* reset controller */
end_comment

begin_define
define|#
directive|define
name|CYUNIT
parameter_list|(
name|d
parameter_list|)
value|(minor(d)& 0xf)
end_define

begin_define
define|#
directive|define
name|MULTIBUS_SHORT
parameter_list|(
name|x
parameter_list|)
value|(short)((((x)>>8)&0xff) | (((x)<<8)&0xff00))
end_define

begin_define
define|#
directive|define
name|NORMAL_INTERUPT
value|0x11
end_define

begin_define
define|#
directive|define
name|CLEAR_INTERUPT
value|0x09
end_define

begin_define
define|#
directive|define
name|T_NOREWIND
value|0x80
end_define

begin_comment
comment|/* Tape Parameter Block definitions */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|long
name|cmd
decl_stmt|;
comment|/* Command */
name|short
name|control
decl_stmt|;
comment|/* Control */
name|short
name|count
decl_stmt|;
comment|/* Return count */
name|short
name|size
decl_stmt|;
comment|/* Buffer size */
name|short
name|rec_over
decl_stmt|;
comment|/* Records/Overrun */
name|char
modifier|*
name|data_ptr
decl_stmt|;
comment|/* Pointer to source/dest */
name|short
name|status
decl_stmt|;
comment|/* Status */
name|short
name|link_ptr
index|[
literal|2
index|]
decl_stmt|;
comment|/* Pointer to next parameter block */
block|}
name|fmt_tpb
typedef|;
end_typedef

begin_comment
comment|/* Controller commands */
end_comment

begin_comment
comment|/* Group. I Control status/commands */
end_comment

begin_define
define|#
directive|define
name|CONFIG
value|(0x00000000)
end_define

begin_comment
comment|/* configure */
end_comment

begin_define
define|#
directive|define
name|SET_PA
value|(0x08000000)
end_define

begin_comment
comment|/* set page */
end_comment

begin_define
define|#
directive|define
name|NO_OP
value|(0x20000000)
end_define

begin_comment
comment|/* no operation */
end_comment

begin_define
define|#
directive|define
name|DRIVE_S
value|(0x28000000)
end_define

begin_comment
comment|/* drive status */
end_comment

begin_define
define|#
directive|define
name|TAPE_AS
value|(0x74000000)
end_define

begin_comment
comment|/* tape assign */
end_comment

begin_define
define|#
directive|define
name|DRIVE_R
value|(0x90000000)
end_define

begin_comment
comment|/* drive reset */
end_comment

begin_comment
comment|/* Group. II Tape position commands */
end_comment

begin_define
define|#
directive|define
name|REWD_OV
value|(0x04000000)
end_define

begin_comment
comment|/* rewind overlapped */
end_comment

begin_define
define|#
directive|define
name|READ_FO
value|(0x1C000000)
end_define

begin_comment
comment|/* read foreign tape */
end_comment

begin_define
define|#
directive|define
name|REWD_TA
value|(0x34000000)
end_define

begin_comment
comment|/* rewind tape */
end_comment

begin_define
define|#
directive|define
name|OFF_UNL
value|(0x38000000)
end_define

begin_comment
comment|/* off_line and unload */
end_comment

begin_define
define|#
directive|define
name|WRIT_FM
value|(0x40000000)
end_define

begin_comment
comment|/* write filemark */
end_comment

begin_define
define|#
directive|define
name|SERH_FM
value|(0x44000000)
end_define

begin_comment
comment|/* search filemark */
end_comment

begin_define
define|#
directive|define
name|SRFM_FD
value|(0x44000000)
end_define

begin_comment
comment|/* search filemark forward */
end_comment

begin_define
define|#
directive|define
name|SRFM_BK
value|(0xC4000000)
end_define

begin_comment
comment|/* search filemark backward */
end_comment

begin_define
define|#
directive|define
name|SPACE
value|(0x48000000)
end_define

begin_comment
comment|/* skip record */
end_comment

begin_define
define|#
directive|define
name|SP_FORW
value|(0x48000000)
end_define

begin_comment
comment|/* space forward */
end_comment

begin_define
define|#
directive|define
name|SP_BACK
value|(0xC8000000)
end_define

begin_comment
comment|/* space backwords */
end_comment

begin_define
define|#
directive|define
name|ERASE_F
value|(0x4C000000)
end_define

begin_comment
comment|/* erase fixed length */
end_comment

begin_define
define|#
directive|define
name|ERASE_T
value|(0x50000000)
end_define

begin_comment
comment|/* erase to end of tape */
end_comment

begin_define
define|#
directive|define
name|SPAC_FM
value|(0x70000000)
end_define

begin_comment
comment|/* space filemark */
end_comment

begin_define
define|#
directive|define
name|SP_FM_F
value|(0x70000000)
end_define

begin_comment
comment|/* space filemark forward */
end_comment

begin_define
define|#
directive|define
name|SP_FM_B
value|(0xC9000000)
end_define

begin_comment
comment|/* space filemark backward */
end_comment

begin_define
define|#
directive|define
name|SERH_MU
value|(0x94000000)
end_define

begin_comment
comment|/* search multiple filemarks */
end_comment

begin_comment
comment|/* Group. III Data transfer commands */
end_comment

begin_define
define|#
directive|define
name|READ_BU
value|(0x10000000)
end_define

begin_comment
comment|/* read buffered */
end_comment

begin_define
define|#
directive|define
name|WRIT_BU
value|(0x14000000)
end_define

begin_comment
comment|/* write buffered */
end_comment

begin_define
define|#
directive|define
name|EDIT_BU
value|(0x18000000)
end_define

begin_comment
comment|/* edit buffered */
end_comment

begin_define
define|#
directive|define
name|READ_TA
value|(0x2C000000)
end_define

begin_comment
comment|/* read tape */
end_comment

begin_define
define|#
directive|define
name|WRIT_TA
value|(0x30000000)
end_define

begin_comment
comment|/* write tape */
end_comment

begin_define
define|#
directive|define
name|EDIT_TA
value|(0x3C000000)
end_define

begin_comment
comment|/* edit tape */
end_comment

begin_define
define|#
directive|define
name|READ_ST
value|(0x60000000)
end_define

begin_comment
comment|/* read streaming */
end_comment

begin_define
define|#
directive|define
name|WRIT_ST
value|(0x64000000)
end_define

begin_comment
comment|/* write streaming */
end_comment

begin_comment
comment|/* Group. IV Special commands */
end_comment

begin_define
define|#
directive|define
name|EXCHANG
value|(0x0C000000)
end_define

begin_comment
comment|/* exchange system and tapemaster RAM */
end_comment

begin_define
define|#
directive|define
name|BLOCK_M
value|(0x80000000)
end_define

begin_comment
comment|/* block move */
end_comment

begin_comment
comment|/* Group. V Diagnostic commands */
end_comment

begin_define
define|#
directive|define
name|TEST_SH
value|(0x54000000)
end_define

begin_comment
comment|/* short memory test */
end_comment

begin_define
define|#
directive|define
name|TEST_LG
value|(0x58000000)
end_define

begin_comment
comment|/* long memory test */
end_comment

begin_define
define|#
directive|define
name|TEST_CN
value|(0x5C000000)
end_define

begin_comment
comment|/* controller confidence test */
end_comment

begin_define
define|#
directive|define
name|TEST_RW
value|(0x68000000)
end_define

begin_comment
comment|/* test read/write timeing */
end_comment

begin_comment
comment|/* Control field bit definitions */
end_comment

begin_define
define|#
directive|define
name|CW_UNIT
value|(0x000c<<8)
end_define

begin_comment
comment|/* tape select mask, 2 bit field */
end_comment

begin_define
define|#
directive|define
name|CW_MAIL
value|(0x0010<<8)
end_define

begin_comment
comment|/* mailbox flag */
end_comment

begin_define
define|#
directive|define
name|CW_INTR
value|(0x0020<<8)
end_define

begin_comment
comment|/* interrupt flag */
end_comment

begin_define
define|#
directive|define
name|CW_LINK
value|(0x0040<<8)
end_define

begin_comment
comment|/* link flag */
end_comment

begin_define
define|#
directive|define
name|CW_LOCK
value|(0x0080<<8)
end_define

begin_comment
comment|/* bus lock flag */
end_comment

begin_define
define|#
directive|define
name|CW_BANK
value|(0x0100>>8)
end_define

begin_comment
comment|/* bank select */
end_comment

begin_define
define|#
directive|define
name|CW_REV
value|(0x0400>>8)
end_define

begin_comment
comment|/* reverse flag */
end_comment

begin_define
define|#
directive|define
name|CW_SPEED
value|(0x0800>>8)
end_define

begin_comment
comment|/* speed/density */
end_comment

begin_define
define|#
directive|define
name|CW_25ips
value|0
end_define

begin_define
define|#
directive|define
name|CW_100ips
value|(0x0800>>8)
end_define

begin_define
define|#
directive|define
name|CW_STREAM
value|(0x1000>>8)
end_define

begin_comment
comment|/* continuous */
end_comment

begin_define
define|#
directive|define
name|CW_WIDTH
value|(0x8000>>8)
end_define

begin_comment
comment|/* width */
end_comment

begin_define
define|#
directive|define
name|CW_8bits
value|0
end_define

begin_define
define|#
directive|define
name|CW_16bits
value|(0x8000>>8)
end_define

begin_comment
comment|/* Status field bit definitions */
end_comment

begin_define
define|#
directive|define
name|CS_P
value|(0x0002<<8)
end_define

begin_comment
comment|/* Protected, no write ring */
end_comment

begin_define
define|#
directive|define
name|CS_FB
value|(0x0004<<8)
end_define

begin_comment
comment|/* formatter busy */
end_comment

begin_define
define|#
directive|define
name|CS_RDY
value|(0x0008<<8)
end_define

begin_comment
comment|/* drive ready */
end_comment

begin_define
define|#
directive|define
name|CS_EOT
value|(0x0010<<8)
end_define

begin_comment
comment|/* end of tape detected */
end_comment

begin_define
define|#
directive|define
name|CS_LP
value|(0x0020<<8)
end_define

begin_comment
comment|/* tape is at load point */
end_comment

begin_define
define|#
directive|define
name|CS_OL
value|(0x0040<<8)
end_define

begin_comment
comment|/* drive on_line */
end_comment

begin_define
define|#
directive|define
name|CS_FM
value|(0x0080<<8)
end_define

begin_comment
comment|/* Filemark detected */
end_comment

begin_define
define|#
directive|define
name|CS_ERm
value|(0x1F00>>8)
end_define

begin_comment
comment|/* Error value mask */
end_comment

begin_define
define|#
directive|define
name|CS_CR
value|(0x2000>>8)
end_define

begin_comment
comment|/* Controller executed retries */
end_comment

begin_define
define|#
directive|define
name|CS_CC
value|(0x4000>>8)
end_define

begin_comment
comment|/* Command Completed successfully */
end_comment

begin_define
define|#
directive|define
name|CS_CE
value|(0x8000>>8)
end_define

begin_comment
comment|/* Command execution has begun */
end_comment

begin_define
define|#
directive|define
name|CYDS_BITS
value|"\20\6CS_CR\7CS_CC\8CS_CE\12CS_P\13CS_FB\14CS_RDY\15CS_EOT\ \16CS_LP\17CS_OL\20CS_FM"
end_define

begin_comment
comment|/* Error value definitions for CS_ERm field */
end_comment

begin_define
define|#
directive|define
name|ER_TIMOUT
value|(0x01)
end_define

begin_comment
comment|/* timed out data busy false */
end_comment

begin_define
define|#
directive|define
name|ER_TIMOUT1
value|(0x02)
end_define

begin_comment
comment|/* data busy false,formatter,ready */
end_comment

begin_define
define|#
directive|define
name|ER_TIMOUT2
value|(0x03)
end_define

begin_comment
comment|/* time out ready busy false */
end_comment

begin_define
define|#
directive|define
name|ER_TIMOUT3
value|(0x04)
end_define

begin_comment
comment|/* time out ready busy true */
end_comment

begin_define
define|#
directive|define
name|ER_TIMOUT4
value|(0x05)
end_define

begin_comment
comment|/* time out data busy true */
end_comment

begin_define
define|#
directive|define
name|ER_NEX
value|(0x06)
end_define

begin_comment
comment|/* time out memory */
end_comment

begin_define
define|#
directive|define
name|ER_BLANK
value|(0X07)
end_define

begin_comment
comment|/* blank tape */
end_comment

begin_define
define|#
directive|define
name|ER_DIAG
value|(0x08)
end_define

begin_comment
comment|/* micro-diagnostic */
end_comment

begin_define
define|#
directive|define
name|ER_EOT
value|(0x09)
end_define

begin_comment
comment|/* EOT forward, BOT rev. */
end_comment

begin_define
define|#
directive|define
name|ER_HARD
value|(0x0A)
end_define

begin_comment
comment|/* retry unsuccessful */
end_comment

begin_define
define|#
directive|define
name|ER_FIFO
value|(0x0B)
end_define

begin_comment
comment|/* FIFO over/under flow */
end_comment

begin_define
define|#
directive|define
name|ER_PARITY
value|(0x0D)
end_define

begin_comment
comment|/* drive to tapemaster parity error */
end_comment

begin_define
define|#
directive|define
name|ER_CHKSUM
value|(0x0E)
end_define

begin_comment
comment|/* prom checksum */
end_comment

begin_define
define|#
directive|define
name|ER_STROBE
value|(0x0F)
end_define

begin_comment
comment|/* time out tape strobe */
end_comment

begin_define
define|#
directive|define
name|ER_NOTRDY
value|(0x10)
end_define

begin_comment
comment|/* tape not ready */
end_comment

begin_define
define|#
directive|define
name|ER_PROT
value|(0x11)
end_define

begin_comment
comment|/* write, no enable ring */
end_comment

begin_define
define|#
directive|define
name|ER_JUMPER
value|(0x13)
end_define

begin_comment
comment|/* missing diagnostic jumper */
end_comment

begin_define
define|#
directive|define
name|ER_LINK
value|(0x14)
end_define

begin_comment
comment|/* bad link, link inappropriate */
end_comment

begin_define
define|#
directive|define
name|ER_FM
value|(0x15)
end_define

begin_comment
comment|/* unexpected filemark */
end_comment

begin_define
define|#
directive|define
name|ER_PARAM
value|(0x16)
end_define

begin_comment
comment|/* bad parameter, byte count ? */
end_comment

begin_define
define|#
directive|define
name|ER_HDWERR
value|(0x18)
end_define

begin_comment
comment|/* unidentified hardware error */
end_comment

begin_define
define|#
directive|define
name|ER_NOSTRM
value|(0x19)
end_define

begin_comment
comment|/* streaming terminated */
end_comment

begin_comment
comment|/* Channel control block definitions */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|ccw
decl_stmt|;
comment|/* channel control word */
name|char
name|gate
decl_stmt|;
comment|/* Tpb access gate */
name|short
name|tpb_ptr
index|[
literal|2
index|]
decl_stmt|;
comment|/* points to first tape parameter block */
block|}
name|fmt_ccb
typedef|;
end_typedef

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
value|(char)(0xFF)
end_define

begin_define
define|#
directive|define
name|NORMAL_INTERUP
value|0x11
end_define

begin_comment
comment|/* System configuration block structrure definitions */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|fixed_value
decl_stmt|;
comment|/* 0x03 fixed value code */
name|char
name|unused_scb
decl_stmt|;
name|short
name|ccb_ptr
index|[
literal|2
index|]
decl_stmt|;
comment|/* pointer to ->CHANNEL CONTROL BLOCK */
block|}
name|fmt_scb
typedef|;
end_typedef

begin_comment
comment|/* System configuration pointer structure definitions */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|bus_size
decl_stmt|;
comment|/* width of system bus 0=8; 1=16 */
name|char
name|unused_scp
decl_stmt|;
name|short
name|scb_ptr
index|[
literal|2
index|]
decl_stmt|;
comment|/* pointer to ->SYSTEM CONFIGUREATION BLOCK */
block|}
name|fmt_scp
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_16_BITS
value|1
end_define

begin_define
define|#
directive|define
name|_8_BITS
value|0
end_define

end_unit

