begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	psl.h	4.3	81/02/23	*/
end_comment

begin_comment
comment|/*  * VAX program status longword  */
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
comment|/* floating point underflow enable */
end_comment

begin_define
define|#
directive|define
name|PSL_DV
value|0x00000080
end_define

begin_comment
comment|/* decimal overflow enable bit */
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
value|0x00c00000
end_define

begin_comment
comment|/* previous mode (all on is user) */
end_comment

begin_define
define|#
directive|define
name|PSL_CURMOD
value|0x03000000
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
name|PSL_FPD
value|0x08000000
end_define

begin_comment
comment|/* first part done */
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
name|PSL_CM
value|0x80000000
end_define

begin_comment
comment|/* compatibility mode */
end_comment

begin_define
define|#
directive|define
name|PSL_USERCLR
value|0x3c20ff00
end_define

begin_comment
comment|/* bits must be clear in user mode */
end_comment

end_unit

