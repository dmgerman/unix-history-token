begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)psl.h	7.1 (Berkeley) 5/21/88  */
end_comment

begin_comment
comment|/*  * TAHOE processor status longword.  */
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
name|PSL_V
value|0x00000002
end_define

begin_comment
comment|/* overflow bit */
end_comment

begin_define
define|#
directive|define
name|PSL_Z
value|0x00000004
end_define

begin_comment
comment|/* zero bit */
end_comment

begin_define
define|#
directive|define
name|PSL_N
value|0x00000008
end_define

begin_comment
comment|/* negative bit */
end_comment

begin_define
define|#
directive|define
name|PSL_ALLCC
value|0x0000000f
end_define

begin_comment
comment|/* all cc bits - unlikely */
end_comment

begin_define
define|#
directive|define
name|PSL_T
value|0x00000010
end_define

begin_comment
comment|/* trace enable bit */
end_comment

begin_define
define|#
directive|define
name|PSL_IV
value|0x00000020
end_define

begin_comment
comment|/* integer overflow enable bit */
end_comment

begin_define
define|#
directive|define
name|PSL_FU
value|0x00000040
end_define

begin_comment
comment|/* float underflow enable 	*/
end_comment

begin_define
define|#
directive|define
name|PSL_DBL
value|0x00000080
end_define

begin_comment
comment|/* f.p. prescision indicator	*/
end_comment

begin_define
define|#
directive|define
name|PSL_SFE
value|0x00000100
end_define

begin_comment
comment|/* system-forced-exception */
end_comment

begin_define
define|#
directive|define
name|PSL_IPL
value|0x001f0000
end_define

begin_comment
comment|/* interrupt priority level */
end_comment

begin_define
define|#
directive|define
name|PSL_PRVMOD
value|0x00000000
end_define

begin_comment
comment|/* previous mode (kernel mode) */
end_comment

begin_define
define|#
directive|define
name|PSL_CURMOD
value|0x01000000
end_define

begin_comment
comment|/* current mode (all on is user) */
end_comment

begin_define
define|#
directive|define
name|PSL_IS
value|0x04000000
end_define

begin_comment
comment|/* interrupt stack */
end_comment

begin_define
define|#
directive|define
name|PSL_TP
value|0x40000000
end_define

begin_comment
comment|/* trace pending */
end_comment

begin_define
define|#
directive|define
name|PSL_MBZ
value|0xbae0fe00
end_define

begin_comment
comment|/* must be zero bits */
end_comment

begin_define
define|#
directive|define
name|PSL_USERSET
value|(PSL_CURMOD)
end_define

begin_define
define|#
directive|define
name|PSL_USERCLR
value|(PSL_IS|PSL_IPL|PSL_MBZ|PSL_SFE|PSL_DBL|PSL_FU)
end_define

end_unit

