begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_decl_stmt
specifier|static
name|int
name|gpib_port
init|=
literal|0x2c0
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IEEE
value|gpib_port
end_define

begin_comment
comment|/*NAT4882 Registers*/
end_comment

begin_define
define|#
directive|define
name|DIR
value|IEEE+0
end_define

begin_define
define|#
directive|define
name|CDOR
value|IEEE+0
end_define

begin_define
define|#
directive|define
name|ISR1
value|IEEE+2
end_define

begin_define
define|#
directive|define
name|IMR1
value|IEEE+2
end_define

begin_define
define|#
directive|define
name|ISR2
value|IEEE+4
end_define

begin_define
define|#
directive|define
name|IMR2
value|IEEE+4
end_define

begin_define
define|#
directive|define
name|SPSR
value|IEEE+6
end_define

begin_define
define|#
directive|define
name|KSR
value|IEEE+0x17
end_define

begin_define
define|#
directive|define
name|KCR
value|IEEE+0x17
end_define

begin_define
define|#
directive|define
name|SPMR
value|IEEE+6
end_define

begin_define
define|#
directive|define
name|ADSR
value|IEEE+8
end_define

begin_define
define|#
directive|define
name|ADMR
value|IEEE+8
end_define

begin_define
define|#
directive|define
name|CPTR
value|IEEE+0x0A
end_define

begin_define
define|#
directive|define
name|SASR
value|IEEE+0x1B
end_define

begin_define
define|#
directive|define
name|AUXMR
value|IEEE+0x0A
end_define

begin_define
define|#
directive|define
name|ADR0
value|IEEE+0x0c
end_define

begin_define
define|#
directive|define
name|ISR0
value|IEEE+0x1d
end_define

begin_define
define|#
directive|define
name|IMR0
value|IEEE+0x1d
end_define

begin_define
define|#
directive|define
name|ADR
value|IEEE+0x0c
end_define

begin_define
define|#
directive|define
name|ADR1
value|IEEE+0x0e
end_define

begin_define
define|#
directive|define
name|BSR
value|IEEE+0x1f
end_define

begin_define
define|#
directive|define
name|BCR
value|IEEE+0x1f
end_define

begin_define
define|#
directive|define
name|EOSR
value|IEEE+0x0e
end_define

begin_comment
comment|/*Turbo 488 Registers*/
end_comment

begin_define
define|#
directive|define
name|CNT2
value|IEEE+0x09
end_define

begin_define
define|#
directive|define
name|CNT3
value|IEEE+0x0b
end_define

begin_define
define|#
directive|define
name|HSSEL
value|IEEE+0x0d
end_define

begin_define
define|#
directive|define
name|STS1
value|IEEE+0x10
end_define

begin_define
define|#
directive|define
name|CFG
value|IEEE+0x10
end_define

begin_define
define|#
directive|define
name|IMR3
value|IEEE+0x12
end_define

begin_define
define|#
directive|define
name|CNT0
value|IEEE+0x14
end_define

begin_define
define|#
directive|define
name|CNT1
value|IEEE+0x16
end_define

begin_define
define|#
directive|define
name|FIFOB
value|IEEE+0x18
end_define

begin_define
define|#
directive|define
name|FIFOA
value|IEEE+0x19
end_define

begin_define
define|#
directive|define
name|ISR3
value|IEEE+0x1a
end_define

begin_define
define|#
directive|define
name|CCRG
value|IEEE+0x1a
end_define

begin_define
define|#
directive|define
name|STS2
value|IEEE+0x1c
end_define

begin_define
define|#
directive|define
name|CMDR
value|IEEE+0x1c
end_define

begin_define
define|#
directive|define
name|TIMER
value|IEEE+0x1e
end_define

begin_define
define|#
directive|define
name|ACCWR
value|IEEE+0x05
end_define

begin_define
define|#
directive|define
name|INTR
value|IEEE+0x07
end_define

begin_define
define|#
directive|define
name|pon
value|0
end_define

begin_define
define|#
directive|define
name|chip_reset
value|2
end_define

begin_define
define|#
directive|define
name|rhdf
value|3
end_define

begin_define
define|#
directive|define
name|trig
value|4
end_define

begin_define
define|#
directive|define
name|rtl_pulse
value|5
end_define

begin_define
define|#
directive|define
name|rtl_off
value|5
end_define

begin_define
define|#
directive|define
name|rtl_on
value|0x0d
end_define

begin_define
define|#
directive|define
name|seoi
value|6
end_define

begin_define
define|#
directive|define
name|ist_off
value|1
end_define

begin_define
define|#
directive|define
name|ist_on
value|9
end_define

begin_define
define|#
directive|define
name|rlc
value|0x0a
end_define

begin_define
define|#
directive|define
name|rqc
value|8
end_define

begin_define
define|#
directive|define
name|lut
value|0x0b
end_define

begin_define
define|#
directive|define
name|lul
value|0x0c
end_define

begin_define
define|#
directive|define
name|nbaf
value|0x0e
end_define

begin_define
define|#
directive|define
name|gts
value|0x10
end_define

begin_define
define|#
directive|define
name|tca
value|0x11
end_define

begin_define
define|#
directive|define
name|tcs
value|0x12
end_define

begin_define
define|#
directive|define
name|tcse
value|0x1a
end_define

begin_define
define|#
directive|define
name|ltn
value|0x13
end_define

begin_define
define|#
directive|define
name|ltn_cont
value|0x1b
end_define

begin_define
define|#
directive|define
name|lun
value|0x1c
end_define

begin_define
define|#
directive|define
name|rsc_off
value|0x14
end_define

begin_define
define|#
directive|define
name|sic_rsc
value|0x1e
end_define

begin_define
define|#
directive|define
name|sic_rsc_off
value|0x16
end_define

begin_define
define|#
directive|define
name|sre_rsc
value|0x1f
end_define

begin_define
define|#
directive|define
name|sre_rsc_off
value|0x17
end_define

begin_define
define|#
directive|define
name|reqt
value|0x18
end_define

begin_define
define|#
directive|define
name|reqf
value|0x19
end_define

begin_define
define|#
directive|define
name|rppl
value|0x1d
end_define

begin_define
define|#
directive|define
name|hldi
value|0x51
end_define

end_unit

