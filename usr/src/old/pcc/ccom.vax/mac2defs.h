begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	mac2defs.h	4.1	85/03/19	*/
end_comment

begin_comment
comment|/*  * VAX-11/780 Registers  */
end_comment

begin_comment
comment|/*  * Scratch registers  */
end_comment

begin_define
define|#
directive|define
name|R0
value|0
end_define

begin_define
define|#
directive|define
name|R1
value|1
end_define

begin_define
define|#
directive|define
name|R2
value|2
end_define

begin_define
define|#
directive|define
name|R3
value|3
end_define

begin_define
define|#
directive|define
name|R4
value|4
end_define

begin_define
define|#
directive|define
name|R5
value|5
end_define

begin_comment
comment|/*  * Register variables  */
end_comment

begin_define
define|#
directive|define
name|R6
value|6
end_define

begin_define
define|#
directive|define
name|R7
value|7
end_define

begin_define
define|#
directive|define
name|R8
value|8
end_define

begin_define
define|#
directive|define
name|R9
value|9
end_define

begin_define
define|#
directive|define
name|R10
value|10
end_define

begin_define
define|#
directive|define
name|R11
value|11
end_define

begin_comment
comment|/*  * Special purpose registers  */
end_comment

begin_define
define|#
directive|define
name|AP
value|12
end_define

begin_comment
comment|/* argument pointer */
end_comment

begin_define
define|#
directive|define
name|FP
value|13
end_define

begin_comment
comment|/* frame pointer */
end_comment

begin_define
define|#
directive|define
name|SP
value|14
end_define

begin_comment
comment|/* stack pointer */
end_comment

begin_define
define|#
directive|define
name|PC
value|15
end_define

begin_comment
comment|/* program counter */
end_comment

begin_define
define|#
directive|define
name|REGSZ
value|16
end_define

begin_define
define|#
directive|define
name|TMPREG
value|FP
end_define

begin_define
define|#
directive|define
name|R2REGS
value|1
end_define

begin_comment
comment|/* permit double indexing */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|fregs
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|maxargs
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BYTEOFF
parameter_list|(
name|x
parameter_list|)
value|((x)&03)
end_define

begin_define
define|#
directive|define
name|wdal
parameter_list|(
name|k
parameter_list|)
value|(BYTEOFF(k)==0)
end_define

begin_comment
comment|/* word align */
end_comment

begin_define
define|#
directive|define
name|BITOOR
parameter_list|(
name|x
parameter_list|)
value|((x)>>3)
end_define

begin_comment
comment|/* bit offset to oreg offset */
end_comment

begin_comment
comment|/*  * Some macros used in store():  *	just evaluate the arguments, and be done with it...  */
end_comment

begin_define
define|#
directive|define
name|STOARG
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|STOFARG
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|STOSTARG
parameter_list|(
name|p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|genfcall
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|gencall(a,b)
end_define

begin_define
define|#
directive|define
name|MYREADER
parameter_list|(
name|p
parameter_list|)
value|myreader(p)
end_define

begin_function_decl
name|int
name|optim2
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* This indicates there are no additional special shapes, see match.c */
end_comment

begin_define
define|#
directive|define
name|special
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|0
end_define

end_unit

