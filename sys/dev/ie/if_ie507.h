begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * $FreeBSD$  * Definitions for 3C507  */
end_comment

begin_define
define|#
directive|define
name|IE507_CTRL
value|6
end_define

begin_comment
comment|/* control port */
end_comment

begin_define
define|#
directive|define
name|IE507_ICTRL
value|10
end_define

begin_comment
comment|/* interrupt control */
end_comment

begin_define
define|#
directive|define
name|IE507_ATTN
value|11
end_define

begin_comment
comment|/* any write here sends a chan attn */
end_comment

begin_define
define|#
directive|define
name|IE507_ROM
value|13
end_define

begin_comment
comment|/* rom configuration? */
end_comment

begin_define
define|#
directive|define
name|IE507_MADDR
value|14
end_define

begin_comment
comment|/* shared memory configuration */
end_comment

begin_define
define|#
directive|define
name|IE507_IRQ
value|15
end_define

begin_comment
comment|/* IRQ configuration */
end_comment

begin_comment
comment|/* Bank 0 -- "*3COM*" signature */
end_comment

begin_define
define|#
directive|define
name|EL_SIG
value|0
end_define

begin_comment
comment|/* offset of ASCII signature -- "*3COM*" */
end_comment

begin_comment
comment|/* Bank 1 -- ethernet address */
end_comment

begin_define
define|#
directive|define
name|EL_ADDR
value|0
end_define

begin_comment
comment|/* offset of card's ethernet address */
end_comment

begin_comment
comment|/* Bank 2 -- card part #, revision, date of manufacture */
end_comment

begin_define
define|#
directive|define
name|EL_TYPE
value|0
end_define

begin_comment
comment|/* offset of card part # */
end_comment

begin_define
define|#
directive|define
name|EL_TYPE_HI
value|0
end_define

begin_comment
comment|/* offset of card part # -- high byte */
end_comment

begin_define
define|#
directive|define
name|EL_TYPE_MID
value|1
end_define

begin_comment
comment|/* offset of card part # -- middle byte */
end_comment

begin_define
define|#
directive|define
name|EL_TYPE_LOW
value|2
end_define

begin_comment
comment|/* offset of card part # -- low byte */
end_comment

begin_define
define|#
directive|define
name|EL_REV
value|3
end_define

begin_comment
comment|/* offset of card revision, in BCD */
end_comment

begin_define
define|#
directive|define
name|EL_DOM_DAY
value|4
end_define

begin_comment
comment|/* offset of date of manf: day in BCD */
end_comment

begin_define
define|#
directive|define
name|EL_DOM_MY
value|4
end_define

begin_comment
comment|/* offset of date of manf: month, year in BCD */
end_comment

begin_comment
comment|/*  * Definitions for non-bankswitched registers  */
end_comment

begin_comment
comment|/* General control register */
end_comment

begin_define
define|#
directive|define
name|EL_CTRL_BNK0
value|0x00
end_define

begin_comment
comment|/* register bank 0 */
end_comment

begin_define
define|#
directive|define
name|EL_CTRL_BNK1
value|0x01
end_define

begin_comment
comment|/* register bank 1 */
end_comment

begin_define
define|#
directive|define
name|EL_CTRL_BNK2
value|0x02
end_define

begin_comment
comment|/* register bank 2 */
end_comment

begin_define
define|#
directive|define
name|EL_CTRL_IEN
value|0x04
end_define

begin_comment
comment|/* interrupt enable */
end_comment

begin_define
define|#
directive|define
name|EL_CTRL_INTL
value|0x08
end_define

begin_comment
comment|/* interrupt active latch */
end_comment

begin_define
define|#
directive|define
name|EL_CTRL_16BIT
value|0x10
end_define

begin_comment
comment|/* bus width; clear = 8-bit, set = 16-bit */
end_comment

begin_define
define|#
directive|define
name|EL_CTRL_LOOP
value|0x20
end_define

begin_comment
comment|/* loopback mode */
end_comment

begin_define
define|#
directive|define
name|EL_CTRL_NRST
value|0x80
end_define

begin_comment
comment|/* turn off to reset */
end_comment

begin_define
define|#
directive|define
name|EL_CTRL_RESET
value|(EL_CTRL_LOOP)
end_define

begin_define
define|#
directive|define
name|EL_CTRL_NORMAL
value|(EL_CTRL_NRST | EL_CTRL_IEN | EL_CTRL_BNK1)
end_define

begin_comment
comment|/* ROM& media control register */
end_comment

begin_define
define|#
directive|define
name|EL_MEDIA_MASK
value|0x80
end_define

begin_comment
comment|/* m1 = (EL_MEDIA register)& EL_MEDIA_MASK */
end_comment

begin_define
define|#
directive|define
name|EL_MEDIA_SHIFT
value|7
end_define

begin_comment
comment|/* media index = m1>> EL_MEDIA_SHIFT */
end_comment

begin_comment
comment|/* shared memory control register */
end_comment

begin_define
define|#
directive|define
name|EL_MADDR_HIGH
value|0x20
end_define

begin_comment
comment|/* memory mapping above 15Meg */
end_comment

begin_define
define|#
directive|define
name|EL_MADDR_MASK
value|0x1c
end_define

begin_comment
comment|/* m1 = (EL_MADDR register)& EL_MADDR_MASK */
end_comment

begin_define
define|#
directive|define
name|EL_MADDR_SHIFT
value|12
end_define

begin_comment
comment|/* m2 = m1<< EL_MADDR_SHIFT  */
end_comment

begin_define
define|#
directive|define
name|EL_MADDR_BASE
value|0xc0000
end_define

begin_comment
comment|/* maddr = m2 + EL_MADDR_BASE */
end_comment

begin_define
define|#
directive|define
name|EL_MSIZE_MASK
value|0x03
end_define

begin_comment
comment|/* m1 = (EL_MADDR register)& EL_MSIZE_MASK */
end_comment

begin_define
define|#
directive|define
name|EL_MSIZE_STEP
value|16384
end_define

begin_comment
comment|/* msize = (m1 + 1) * EL_MSIZE_STEP */
end_comment

begin_comment
comment|/* interrupt control register */
end_comment

begin_define
define|#
directive|define
name|EL_IRQ_MASK
value|0x0f
end_define

begin_comment
comment|/* irq = (EL_IRQ register)& EL_IRQ_MASK */
end_comment

begin_comment
comment|/*  * Definitions for Bank 0 registers  */
end_comment

begin_define
define|#
directive|define
name|EL_SIG_LEN
value|6
end_define

begin_comment
comment|/* signature length */
end_comment

begin_define
define|#
directive|define
name|EL_SIGNATURE
value|"*3COM*"
end_define

begin_comment
comment|/*  * Definitions for Bank 1 registers  */
end_comment

begin_define
define|#
directive|define
name|EL_ADDR_LEN
value|6
end_define

begin_comment
comment|/* ether address length */
end_comment

begin_comment
comment|/*  * Definitions for Bank 2 registers  */
end_comment

begin_define
define|#
directive|define
name|EL_TYPE_LEN
value|3
end_define

begin_comment
comment|/* card part # length */
end_comment

begin_comment
comment|/*  * General card-specific macros and definitions  */
end_comment

begin_define
define|#
directive|define
name|EL_IOBASE_LOW
value|0x200
end_define

begin_define
define|#
directive|define
name|EL_IOBASE_HIGH
value|0x3e0
end_define

begin_define
define|#
directive|define
name|EL_IOSIZE
value|16
end_define

begin_comment
comment|/*  * XXX: It seems that the 3C507-TP is differentiated from AUI/BNC 3C507  * by part numbers, but I'm not sure how accurate this test is, seeing  * as it's based on the sample of 3 cards I own (2AUI/BNC, 1 TP).  */
end_comment

begin_define
define|#
directive|define
name|EL_IS_TP
parameter_list|(
name|type
parameter_list|)
value|((type)[EL_TYPE_MID]> 0x70)
end_define

begin_define
define|#
directive|define
name|EL_CARD_BNC
value|0
end_define

begin_comment
comment|/* regular AUI/BNC 3C507 */
end_comment

begin_define
define|#
directive|define
name|EL_CARD_TP
value|1
end_define

begin_comment
comment|/* 3C507-TP -- no AUI/BNC */
end_comment

end_unit

