begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* 	pcic98reg.h  	PC9801NS/A PCMCIA contorer routine conpatible to PCIC 	Noriyuki Hosobuchi 96.1.20  */
end_comment

begin_comment
comment|/*--- I/O port definition */
end_comment

begin_define
define|#
directive|define
name|PCIC98_REG0
value|0x0a8e
end_define

begin_comment
comment|/* byte */
end_comment

begin_define
define|#
directive|define
name|PCIC98_REG1
value|0x1a8e
end_define

begin_comment
comment|/* byte */
end_comment

begin_define
define|#
directive|define
name|PCIC98_REG2
value|0x2a8e
end_define

begin_comment
comment|/* byte */
end_comment

begin_define
define|#
directive|define
name|PCIC98_REG3
value|0x3a8e
end_define

begin_comment
comment|/* byte : Interrupt */
end_comment

begin_define
define|#
directive|define
name|PCIC98_REG4
value|0x4a8e
end_define

begin_comment
comment|/* word : PC98 side IO base */
end_comment

begin_define
define|#
directive|define
name|PCIC98_REG5
value|0x5a8e
end_define

begin_comment
comment|/* word : Card side IO base */
end_comment

begin_define
define|#
directive|define
name|PCIC98_REG6
value|0x7a8e
end_define

begin_comment
comment|/* byte */
end_comment

begin_define
define|#
directive|define
name|PCIC98_REG_WINSEL
value|0x1e8e
end_define

begin_comment
comment|/* byte : win bank select register */
end_comment

begin_define
define|#
directive|define
name|PCIC98_REG_PAGOFS
value|0x0e8e
end_define

begin_comment
comment|/* word */
end_comment

begin_comment
comment|/* PC98_REG_WINSEL */
end_comment

begin_define
define|#
directive|define
name|PCIC98_MAPWIN
value|0x84
end_define

begin_comment
comment|/* map Card on 0xda0000 - 0xdbffff */
end_comment

begin_define
define|#
directive|define
name|PCIC98_UNMAPWIN
value|0x00
end_define

begin_comment
comment|/* PCIC98_REG1 */
end_comment

begin_define
define|#
directive|define
name|PCIC98_CARDEXIST
value|0x08
end_define

begin_comment
comment|/* 1:exist 0:not exist */
end_comment

begin_comment
comment|/* PCIC98_REG2 */
end_comment

begin_define
define|#
directive|define
name|PCIC98_IOMEMORY
value|0x80
end_define

begin_comment
comment|/* 1:IO 0:Memory */
end_comment

begin_define
define|#
directive|define
name|PCIC98_MAPIO
value|0x40
end_define

begin_comment
comment|/* 0:IO map 1:??? */
end_comment

begin_define
define|#
directive|define
name|PCIC98_8BIT
value|0x20
end_define

begin_comment
comment|/* bit width 1:8bit 0:16bit */
end_comment

begin_define
define|#
directive|define
name|PCIC98_MAP128
value|0x10
end_define

begin_comment
comment|/* IO map size 1:128byte 0:16byte */
end_comment

begin_define
define|#
directive|define
name|PCIC98_VCC3P3V
value|0x02
end_define

begin_comment
comment|/* Vcc 1:3.3V 0:5.0V */
end_comment

begin_comment
comment|/* PCIC98_REG3 */
end_comment

begin_define
define|#
directive|define
name|PCIC98_INT0
value|(0xf8 + 0x0)
end_define

begin_comment
comment|/* INT0(IRQ3) */
end_comment

begin_define
define|#
directive|define
name|PCIC98_INT1
value|(0xf8 + 0x1)
end_define

begin_comment
comment|/* INT1(IRQ5) */
end_comment

begin_define
define|#
directive|define
name|PCIC98_INT2
value|(0xf8 + 0x2)
end_define

begin_comment
comment|/* INT2(IRQ6) */
end_comment

begin_define
define|#
directive|define
name|PCIC98_INT4
value|(0xf8 + 0x4)
end_define

begin_comment
comment|/* INT4(IRQ10) */
end_comment

begin_define
define|#
directive|define
name|PCIC98_INT5
value|(0xf8 + 0x5)
end_define

begin_comment
comment|/* INT5(IRQ12) */
end_comment

begin_define
define|#
directive|define
name|PCIC98_INTDISABLE
value|(0xf8 + 0x7)
end_define

begin_comment
comment|/* disable interrupt */
end_comment

begin_comment
comment|/* PCIC98_REG6 */
end_comment

begin_define
define|#
directive|define
name|PCIC98_ATTRMEM
value|0x20
end_define

begin_comment
comment|/* 1:attr mem 0:common mem */
end_comment

begin_define
define|#
directive|define
name|PCIC98_VPP12V
value|0x10
end_define

begin_comment
comment|/* Vpp 0:5V 1:12V */
end_comment

end_unit

