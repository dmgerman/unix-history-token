begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	cyvar.h	1.2	86/12/18	*/
end_comment

begin_define
define|#
directive|define
name|TM_ATTENTION
parameter_list|(
name|addr
parameter_list|,
name|x
parameter_list|)
value|movob(addr,x)
end_define

begin_comment
comment|/* also known as: GO */
end_comment

begin_define
define|#
directive|define
name|TM_RESET
parameter_list|(
name|addr
parameter_list|,
name|x
parameter_list|)
value|TM_ATTENTION((addr+1),x)
end_define

begin_comment
comment|/* reset controller */
end_comment

begin_define
define|#
directive|define
name|TM_SHORT
parameter_list|(
name|x
parameter_list|)
value|(short)((((x)>> 8)& 0xff) + (((x)<< 8)& 0xff00))
end_define

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
comment|/* Group. I Control status/commands */
end_comment

begin_define
define|#
directive|define
name|CONFIG
value|(0x00000000L)
end_define

begin_comment
comment|/* configure */
end_comment

begin_define
define|#
directive|define
name|SET_PA
value|(0x08000000L)
end_define

begin_comment
comment|/* set page */
end_comment

begin_define
define|#
directive|define
name|NO_OP
value|(0x20000000L)
end_define

begin_comment
comment|/* no operation */
end_comment

begin_define
define|#
directive|define
name|DRIVE_S
value|(0x28000000L)
end_define

begin_comment
comment|/* drive status */
end_comment

begin_define
define|#
directive|define
name|TAPE_AS
value|(0x74000000L)
end_define

begin_comment
comment|/* tape assign */
end_comment

begin_define
define|#
directive|define
name|DRIVE_R
value|(0x90000000L)
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
value|(0x04000000L)
end_define

begin_comment
comment|/* rewind overlapped */
end_comment

begin_define
define|#
directive|define
name|READ_FO
value|(0x1C000000L)
end_define

begin_comment
comment|/* read foreign tape */
end_comment

begin_define
define|#
directive|define
name|REWD_TA
value|(0x34000000L)
end_define

begin_comment
comment|/* rewind tape */
end_comment

begin_define
define|#
directive|define
name|OFF_UNL
value|(0x38000000L)
end_define

begin_comment
comment|/* off_line and unload */
end_comment

begin_define
define|#
directive|define
name|WRIT_FM
value|(0x40000000L)
end_define

begin_comment
comment|/* write filemark */
end_comment

begin_define
define|#
directive|define
name|SERH_FM
value|(0x44000000L)
end_define

begin_comment
comment|/* search filemark */
end_comment

begin_define
define|#
directive|define
name|SRFM_FD
value|(0x44000000L)
end_define

begin_comment
comment|/* search filemark forward */
end_comment

begin_define
define|#
directive|define
name|SRFM_BK
value|(0xC4000000L)
end_define

begin_comment
comment|/* search filemark backward */
end_comment

begin_define
define|#
directive|define
name|SPACE
value|(0x48000000L)
end_define

begin_comment
comment|/* skip record */
end_comment

begin_define
define|#
directive|define
name|SP_FORW
value|(0x48000000L)
end_define

begin_comment
comment|/* space forward */
end_comment

begin_define
define|#
directive|define
name|SP_BACK
value|(0xC8000000L)
end_define

begin_comment
comment|/* space backwords */
end_comment

begin_define
define|#
directive|define
name|ERASE_F
value|(0x4C000000L)
end_define

begin_comment
comment|/* erase fixed length */
end_comment

begin_define
define|#
directive|define
name|ERASE_T
value|(0x50000000L)
end_define

begin_comment
comment|/* erase to end of tape */
end_comment

begin_define
define|#
directive|define
name|SPAC_FM
value|(0x70000000L)
end_define

begin_comment
comment|/* space filemark */
end_comment

begin_define
define|#
directive|define
name|SERH_MU
value|(0x94000000L)
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
value|(0x10000000L)
end_define

begin_comment
comment|/* read buffered */
end_comment

begin_define
define|#
directive|define
name|WRIT_BU
value|(0x14000000L)
end_define

begin_comment
comment|/* write buffered */
end_comment

begin_define
define|#
directive|define
name|EDIT_BU
value|(0x18000000L)
end_define

begin_comment
comment|/* edit buffered */
end_comment

begin_define
define|#
directive|define
name|READ_TA
value|(0x2C000000L)
end_define

begin_comment
comment|/* read tape */
end_comment

begin_define
define|#
directive|define
name|WRIT_TA
value|(0x30000000L)
end_define

begin_comment
comment|/* write tape */
end_comment

begin_define
define|#
directive|define
name|EDIT_TA
value|(0x3C000000L)
end_define

begin_comment
comment|/* edit tape */
end_comment

begin_define
define|#
directive|define
name|READ_ST
value|(0x60000000L)
end_define

begin_comment
comment|/* read streaming */
end_comment

begin_define
define|#
directive|define
name|WRIT_ST
value|(0x64000000L)
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
value|(0x0C000000L)
end_define

begin_comment
comment|/* exchange system and tapemaster RAM */
end_comment

begin_define
define|#
directive|define
name|BLOCK_M
value|(0x80000000L)
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
value|(0x54000000L)
end_define

begin_comment
comment|/* short memory test */
end_comment

begin_define
define|#
directive|define
name|TEST_LG
value|(0x58000000L)
end_define

begin_comment
comment|/* long memory test */
end_comment

begin_define
define|#
directive|define
name|TEST_CN
value|(0x5C000000L)
end_define

begin_comment
comment|/* controller confidence test */
end_comment

begin_define
define|#
directive|define
name|TEST_RW
value|(0x68000000L)
end_define

begin_comment
comment|/* test read/write timeing */
end_comment

begin_comment
comment|/* Control byte[0] bit assignments */
end_comment

begin_define
define|#
directive|define
name|CW_TSm
value|(0x0C)
end_define

begin_comment
comment|/* tape select mask, 2 bit field */
end_comment

begin_define
define|#
directive|define
name|CW_TSs
value|(2)
end_define

begin_comment
comment|/* tape select shift, 2 bit field<<shift */
end_comment

begin_define
define|#
directive|define
name|CW_M
value|(0x10)
end_define

begin_comment
comment|/* mailbox flag */
end_comment

begin_define
define|#
directive|define
name|CW_I
value|(0x20)
end_define

begin_comment
comment|/* interrupt flag */
end_comment

begin_define
define|#
directive|define
name|CW_L
value|(0x40)
end_define

begin_comment
comment|/* link flag */
end_comment

begin_define
define|#
directive|define
name|CW_BL
value|(0x80)
end_define

begin_comment
comment|/* bus lock flag */
end_comment

begin_comment
comment|/* Control byte[1] bit assignments */
end_comment

begin_define
define|#
directive|define
name|CW_BS
value|(0x01)
end_define

begin_comment
comment|/* bank select */
end_comment

begin_define
define|#
directive|define
name|CW_R
value|(0x04)
end_define

begin_comment
comment|/* reverse flag */
end_comment

begin_define
define|#
directive|define
name|CW_SD
value|(0x08)
end_define

begin_comment
comment|/* speed/density */
end_comment

begin_define
define|#
directive|define
name|CW_25ips
value|(0x00)
end_define

begin_comment
comment|/* 25 inches per second speed */
end_comment

begin_define
define|#
directive|define
name|CW_100ips
value|(0x08)
end_define

begin_comment
comment|/* 100 inches per second speed */
end_comment

begin_define
define|#
directive|define
name|CW_C
value|(0x10)
end_define

begin_comment
comment|/* continuous */
end_comment

begin_define
define|#
directive|define
name|CW_W
value|(0x80)
end_define

begin_comment
comment|/* width */
end_comment

begin_define
define|#
directive|define
name|CW_8bits
value|(0x00)
end_define

begin_comment
comment|/* width 8 bits */
end_comment

begin_define
define|#
directive|define
name|CW_16bits
value|(0x80)
end_define

begin_comment
comment|/* width 16 bits */
end_comment

begin_comment
comment|/* status byte[0] bit assignements */
end_comment

begin_define
define|#
directive|define
name|CS_P
value|(0x02)
end_define

begin_comment
comment|/* Protected, no write ring */
end_comment

begin_define
define|#
directive|define
name|CS_FB
value|(0x04)
end_define

begin_comment
comment|/* formatter busy */
end_comment

begin_define
define|#
directive|define
name|CS_DR
value|(0x08)
end_define

begin_comment
comment|/* drive ready */
end_comment

begin_define
define|#
directive|define
name|CS_EOT
value|(0x10)
end_define

begin_comment
comment|/* end of tape detected */
end_comment

begin_define
define|#
directive|define
name|CS_LP
value|(0x20)
end_define

begin_comment
comment|/* tape is at load point */
end_comment

begin_define
define|#
directive|define
name|CS_OL
value|(0x40)
end_define

begin_comment
comment|/* drive on_line */
end_comment

begin_define
define|#
directive|define
name|CS_FM
value|(0x80)
end_define

begin_comment
comment|/* Filemark detected */
end_comment

begin_comment
comment|/* status byte[1] bit assignements */
end_comment

begin_define
define|#
directive|define
name|CS_ERm
value|(0x1F)
end_define

begin_comment
comment|/* Command (Error) mask */
end_comment

begin_define
define|#
directive|define
name|CS_CR
value|(0x20)
end_define

begin_comment
comment|/* Command (Retry) */
end_comment

begin_define
define|#
directive|define
name|CS_CC
value|(0x40)
end_define

begin_comment
comment|/* Command (Complete) */
end_comment

begin_define
define|#
directive|define
name|CS_CE
value|(0x80)
end_define

begin_comment
comment|/* Command (Entered) */
end_comment

begin_comment
comment|/* block move control byte[0] bit assignments */
end_comment

begin_define
define|#
directive|define
name|BM_SI
value|(0x01)
end_define

begin_comment
comment|/* increment source address */
end_comment

begin_define
define|#
directive|define
name|BM_SW
value|(0x02)
end_define

begin_comment
comment|/* source width */
end_comment

begin_define
define|#
directive|define
name|BM_DI
value|(0x04)
end_define

begin_comment
comment|/* increment destination address */
end_comment

begin_define
define|#
directive|define
name|BM_DW
value|(0x08)
end_define

begin_comment
comment|/* destination width */
end_comment

begin_define
define|#
directive|define
name|BM_M
value|(0x10)
end_define

begin_comment
comment|/* mailbox flag */
end_comment

begin_define
define|#
directive|define
name|BM_I
value|(0x20)
end_define

begin_comment
comment|/* interrupt flag */
end_comment

begin_define
define|#
directive|define
name|BM_L
value|(0x40)
end_define

begin_comment
comment|/* link flag */
end_comment

begin_define
define|#
directive|define
name|BM_BL
value|(0x80)
end_define

begin_comment
comment|/* bus lock flag */
end_comment

begin_comment
comment|/* block move control byte[1] bit assignments */
end_comment

begin_define
define|#
directive|define
name|BM_T
value|(0x01)
end_define

begin_comment
comment|/* translate flag */
end_comment

begin_define
define|#
directive|define
name|BM_S
value|(0x02)
end_define

begin_comment
comment|/* search flag */
end_comment

begin_define
define|#
directive|define
name|BM_NC
value|(0x04)
end_define

begin_comment
comment|/* non_compare flag */
end_comment

begin_define
define|#
directive|define
name|BM_TH
value|(0x08)
end_define

begin_comment
comment|/* throttle flag */
end_comment

begin_define
define|#
directive|define
name|BM_SL
value|(0x10)
end_define

begin_comment
comment|/* source local flag */
end_comment

begin_define
define|#
directive|define
name|BM_DL
value|(0x20)
end_define

begin_comment
comment|/* destination local flag */
end_comment

begin_comment
comment|/* block move status bit assignments */
end_comment

begin_define
define|#
directive|define
name|BS_ERm
value|(0x1F)
end_define

begin_comment
comment|/* Command (Error) mask */
end_comment

begin_define
define|#
directive|define
name|BS_HIT
value|(0x20)
end_define

begin_comment
comment|/* found match during search */
end_comment

begin_define
define|#
directive|define
name|BS_CC
value|(0x40)
end_define

begin_comment
comment|/* Command (Complete) */
end_comment

begin_define
define|#
directive|define
name|BS_CE
value|(0x80)
end_define

begin_comment
comment|/* Command (Entered) */
end_comment

begin_comment
comment|/* SC_ERROR& BM_ERROR codes */
end_comment

begin_define
define|#
directive|define
name|ER_NONE
value|(0x00)
end_define

begin_comment
comment|/* no error */
end_comment

begin_define
define|#
directive|define
name|ER_TO1
value|(0x01)
end_define

begin_comment
comment|/* timed out data busy false */
end_comment

begin_define
define|#
directive|define
name|ER_TO2
value|(0x02)
end_define

begin_comment
comment|/* data busy false,formatter,ready */
end_comment

begin_define
define|#
directive|define
name|ER_TO3
value|(0x03)
end_define

begin_comment
comment|/* time out ready busy false */
end_comment

begin_define
define|#
directive|define
name|ER_TO4
value|(0x04)
end_define

begin_comment
comment|/* time out ready busy true */
end_comment

begin_define
define|#
directive|define
name|ER_TO5
value|(0x05)
end_define

begin_comment
comment|/* time out data busy true */
end_comment

begin_define
define|#
directive|define
name|ER_TO6
value|(0x06)
end_define

begin_comment
comment|/* time out memory */
end_comment

begin_define
define|#
directive|define
name|ER_BLAN
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
name|ER_END
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

begin_comment
comment|/*		(0x0C)		/* Not used */
end_comment

begin_define
define|#
directive|define
name|ER_PARI
value|(0x0D)
end_define

begin_comment
comment|/* drive to tapemaster parity error */
end_comment

begin_define
define|#
directive|define
name|ER_PSUM
value|(0x0E)
end_define

begin_comment
comment|/* prom checksum */
end_comment

begin_define
define|#
directive|define
name|ER_TOF
value|(0x0F)
end_define

begin_comment
comment|/* time out tape strobe */
end_comment

begin_define
define|#
directive|define
name|ER_TRN
value|(0x10)
end_define

begin_comment
comment|/* tape not ready */
end_comment

begin_define
define|#
directive|define
name|ER_PRO
value|(0x11)
end_define

begin_comment
comment|/* write, no enable ring */
end_comment

begin_comment
comment|/*		(0x12)		/* Not used */
end_comment

begin_define
define|#
directive|define
name|ER_JUMP
value|(0x13)
end_define

begin_comment
comment|/* missing diagnostic jumper */
end_comment

begin_define
define|#
directive|define
name|ER_BLIN
value|(0x14)
end_define

begin_comment
comment|/* bad link, link inappropriate */
end_comment

begin_define
define|#
directive|define
name|ER_FMAR
value|(0x15)
end_define

begin_comment
comment|/* unexpected filemark */
end_comment

begin_define
define|#
directive|define
name|ER_PARA
value|(0x16)
end_define

begin_comment
comment|/* bad parameter, byte count ? */
end_comment

begin_comment
comment|/*		(0x17)		/* Not used */
end_comment

begin_define
define|#
directive|define
name|ER_ER
value|(0x18)
end_define

begin_comment
comment|/* unidentified hardware error */
end_comment

begin_define
define|#
directive|define
name|ER_STER
value|(0x19)
end_define

begin_comment
comment|/* streaming terminated */
end_comment

end_unit

