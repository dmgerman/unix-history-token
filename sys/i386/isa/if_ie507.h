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

end_unit

