begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * 386 processor status longword.  */
end_comment

begin_define
define|#
directive|define
name|PSL_C
value|0x00000001
end_define

begin_comment
comment|/* carry bit */
end_comment

begin_define
define|#
directive|define
name|PSL_PF
value|0x00000004
end_define

begin_comment
comment|/* parity bit */
end_comment

begin_define
define|#
directive|define
name|PSL_AF
value|0x00000010
end_define

begin_comment
comment|/* bcd carry bit */
end_comment

begin_define
define|#
directive|define
name|PSL_Z
value|0x00000040
end_define

begin_comment
comment|/* zero bit */
end_comment

begin_define
define|#
directive|define
name|PSL_N
value|0x00000080
end_define

begin_comment
comment|/* negative bit */
end_comment

begin_define
define|#
directive|define
name|PSL_ALLCC
value|0x000000d5
end_define

begin_comment
comment|/* all cc bits - unlikely */
end_comment

begin_define
define|#
directive|define
name|PSL_T
value|0x00000100
end_define

begin_comment
comment|/* trace enable bit */
end_comment

begin_define
define|#
directive|define
name|PSL_I
value|0x00000200
end_define

begin_comment
comment|/* interrupt enable bit */
end_comment

begin_define
define|#
directive|define
name|PSL_D
value|0x00000400
end_define

begin_comment
comment|/* string instruction direction bit */
end_comment

begin_define
define|#
directive|define
name|PSL_V
value|0x00000800
end_define

begin_comment
comment|/* overflow bit */
end_comment

begin_define
define|#
directive|define
name|PSL_IOPL
value|0x00003000
end_define

begin_comment
comment|/* i/o priviledge level enable */
end_comment

begin_define
define|#
directive|define
name|PSL_NT
value|0x00004000
end_define

begin_comment
comment|/* nested task bit */
end_comment

begin_define
define|#
directive|define
name|PSL_RF
value|0x00010000
end_define

begin_comment
comment|/* restart flag bit */
end_comment

begin_define
define|#
directive|define
name|PSL_VM
value|0x00020000
end_define

begin_comment
comment|/* virtual 8086 mode bit */
end_comment

begin_define
define|#
directive|define
name|PSL_MBZ
value|0xfffc7fb7
end_define

begin_comment
comment|/* must be zero bits */
end_comment

begin_define
define|#
directive|define
name|PSL_MBO
value|0x00000002
end_define

begin_comment
comment|/* must be one bits */
end_comment

begin_define
define|#
directive|define
name|PSL_USERSET
value|(PSL_IOPL)
end_define

begin_define
define|#
directive|define
name|PSL_USERCLR
value|(PSL_I|PSL_NT)
end_define

end_unit

