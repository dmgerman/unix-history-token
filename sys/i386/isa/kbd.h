begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Keyboard definitions  *	from: unknown origin, 386BSD 0.1  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I386_ISA_KBD_H_
end_ifndef

begin_define
define|#
directive|define
name|_I386_ISA_KBD_H_
value|1
end_define

begin_comment
comment|/* Reference:	IBM AT Technical Reference Manual,  * pp. 1-38 to 1-43, 4-3 to 4-22  */
end_comment

begin_comment
comment|/* commands sent to KBCMDP */
end_comment

begin_define
define|#
directive|define
name|KBC_CMDREAD
value|0x20
end_define

begin_comment
comment|/* read kbd cntrl command byte */
end_comment

begin_define
define|#
directive|define
name|KBC_CMDWRITE
value|0x60
end_define

begin_comment
comment|/* == LD_CMDBYTE in kd.h, write command */
end_comment

begin_define
define|#
directive|define
name|KBC_SELFTEST
value|0xAA
end_define

begin_comment
comment|/* perform self test, returns 55 when ok */
end_comment

begin_define
define|#
directive|define
name|KBC_IFTEST
value|0xAB
end_define

begin_comment
comment|/* perform interface test */
end_comment

begin_define
define|#
directive|define
name|KBC_DIAGDUMP
value|0xAC
end_define

begin_comment
comment|/* send 19 status bytes to system */
end_comment

begin_define
define|#
directive|define
name|KBC_DISKBD
value|0xAD
end_define

begin_comment
comment|/* disable keyboard */
end_comment

begin_define
define|#
directive|define
name|KBC_ENAKBD
value|0xAE
end_define

begin_comment
comment|/* enable keyboard */
end_comment

begin_define
define|#
directive|define
name|KBC_RDINP
value|0xC0
end_define

begin_comment
comment|/* read input port */
end_comment

begin_define
define|#
directive|define
name|KBC_RDID
value|0xC4
end_define

begin_comment
comment|/* read keyboard ID */
end_comment

begin_define
define|#
directive|define
name|KBC_RDOUTP
value|0xD0
end_define

begin_comment
comment|/* read output port */
end_comment

begin_define
define|#
directive|define
name|KBC_WROUTP
value|0xD1
end_define

begin_comment
comment|/* write output port */
end_comment

begin_define
define|#
directive|define
name|KBC_RDTINP
value|0xE0
end_define

begin_comment
comment|/* read test inputs */
end_comment

begin_comment
comment|/* commands sent to KBDATAP */
end_comment

begin_define
define|#
directive|define
name|KBC_STSIND
value|0xED
end_define

begin_comment
comment|/* set keyboard status indicators */
end_comment

begin_define
define|#
directive|define
name|KBC_ECHO
value|0xEE
end_define

begin_comment
comment|/* reply with 0xEE */
end_comment

begin_define
define|#
directive|define
name|KBC_SETTPM
value|0xF3
end_define

begin_comment
comment|/* Set typematic rate/delay */
end_comment

begin_define
define|#
directive|define
name|KBC_ENABLE
value|0xF4
end_define

begin_comment
comment|/* Start scanning */
end_comment

begin_define
define|#
directive|define
name|KBC_SETDEFD
value|0xF5
end_define

begin_comment
comment|/* =KBC_SETDEF, but disable scanning */
end_comment

begin_define
define|#
directive|define
name|KBC_SETDEF
value|0xF6
end_define

begin_comment
comment|/* Set power on defaults */
end_comment

begin_define
define|#
directive|define
name|KBC_RESEND
value|0xFE
end_define

begin_comment
comment|/* system wants keyboard to resend last code */
end_comment

begin_define
define|#
directive|define
name|KBC_RESET
value|0xFF
end_define

begin_comment
comment|/* Reset the keyboard */
end_comment

begin_comment
comment|/* responses */
end_comment

begin_define
define|#
directive|define
name|KBR_OVERRUN
value|0x00
end_define

begin_comment
comment|/* Keyboard flooded */
end_comment

begin_define
define|#
directive|define
name|KBR_STOK
value|0x55
end_define

begin_comment
comment|/* Selftest ok response */
end_comment

begin_define
define|#
directive|define
name|KBR_IFOK
value|0x00
end_define

begin_comment
comment|/* Interface test ok */
end_comment

begin_define
define|#
directive|define
name|KBR_IFCL_SA0
value|0x01
end_define

begin_comment
comment|/* Clock Stuck-at-0 fault */
end_comment

begin_define
define|#
directive|define
name|KBR_IFCL_SA1
value|0x02
end_define

begin_comment
comment|/* Clock Stuck-at-1 fault */
end_comment

begin_define
define|#
directive|define
name|KBR_IFDA_SA0
value|0x03
end_define

begin_comment
comment|/* Data Stuck-at-0 fault */
end_comment

begin_define
define|#
directive|define
name|KBR_IFDA_SA1
value|0x04
end_define

begin_comment
comment|/* Data Stuck-at-1 fault */
end_comment

begin_define
define|#
directive|define
name|KBR_RSTDONE
value|0xAA
end_define

begin_comment
comment|/* Keyboard reset (BAT) complete */
end_comment

begin_define
define|#
directive|define
name|KBR_E0
value|0xE0
end_define

begin_comment
comment|/* Extended prefix */
end_comment

begin_define
define|#
directive|define
name|KBR_E1
value|0xE1
end_define

begin_comment
comment|/* BREAK'S HIT :-( */
end_comment

begin_define
define|#
directive|define
name|KBR_ECHO
value|0xEE
end_define

begin_comment
comment|/* Echo response */
end_comment

begin_define
define|#
directive|define
name|KBR_F0
value|0xF0
end_define

begin_comment
comment|/* Break code prefix */
end_comment

begin_define
define|#
directive|define
name|KBR_ACK
value|0xFA
end_define

begin_comment
comment|/* Keyboard did receive command */
end_comment

begin_define
define|#
directive|define
name|KBR_BATFAIL
value|0xFC
end_define

begin_comment
comment|/* BAT failed */
end_comment

begin_define
define|#
directive|define
name|KBR_DIAGFAIL
value|0xFD
end_define

begin_comment
comment|/* Diagnostic failed response */
end_comment

begin_define
define|#
directive|define
name|KBR_RESEND
value|0xFE
end_define

begin_comment
comment|/* Keyboard needs resend of command */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I386_ISA_KBD_H_ */
end_comment

end_unit

