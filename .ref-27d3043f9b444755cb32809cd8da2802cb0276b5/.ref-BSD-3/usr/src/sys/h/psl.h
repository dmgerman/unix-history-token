begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	psl.h	2.1	1/5/80 */
end_comment

begin_comment
comment|/*  * VAX program status longword  */
end_comment

begin_define
define|#
directive|define
name|PSL_C
value|0x1
end_define

begin_comment
comment|/* carry bit */
end_comment

begin_define
define|#
directive|define
name|PSL_V
value|0x2
end_define

begin_comment
comment|/* overflow bit */
end_comment

begin_define
define|#
directive|define
name|PSL_Z
value|0x4
end_define

begin_comment
comment|/* zero bit */
end_comment

begin_define
define|#
directive|define
name|PSL_N
value|0x8
end_define

begin_comment
comment|/* negative bit */
end_comment

begin_define
define|#
directive|define
name|PSL_T
value|0x10
end_define

begin_comment
comment|/* trace enable bit */
end_comment

begin_define
define|#
directive|define
name|PSL_IV
value|0x20
end_define

begin_comment
comment|/* integer overflow enable bit */
end_comment

begin_define
define|#
directive|define
name|PSL_FU
value|0x40
end_define

begin_comment
comment|/* floating point underflow enable */
end_comment

begin_define
define|#
directive|define
name|PSL_DV
value|0x80
end_define

begin_comment
comment|/* decimal overflow enable bit */
end_comment

begin_define
define|#
directive|define
name|PSL_IPL
value|0x1f0000
end_define

begin_comment
comment|/* interrupt priority level */
end_comment

begin_define
define|#
directive|define
name|PSL_PRVMOD
value|0xc00000
end_define

begin_comment
comment|/* previous mode */
end_comment

begin_define
define|#
directive|define
name|PSL_CURMOD
value|0x3000000
end_define

begin_comment
comment|/* current mode */
end_comment

begin_define
define|#
directive|define
name|PSL_IS
value|0x4000000
end_define

begin_comment
comment|/* interrupt stack */
end_comment

begin_define
define|#
directive|define
name|PSL_FPD
value|0x8000000
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

end_unit

