begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*	defs.h	1.1	86/07/20	*/
end_comment

begin_include
include|#
directive|include
file|"../tahoe/psl.h"
end_include

begin_comment
comment|/************************************************/
end_comment

begin_comment
comment|/*	Basic 6/32 machine definitions 		*/
end_comment

begin_comment
comment|/************************************************/
end_comment

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
value|(~FALSE)
end_define

begin_define
define|#
directive|define
name|READ
value|0
end_define

begin_define
define|#
directive|define
name|WRITE
value|1
end_define

begin_comment
comment|/*  * Some floatng point stuff.  */
end_comment

begin_define
define|#
directive|define
name|exp
parameter_list|(
name|x
parameter_list|)
value|( (x)& 0x7f800000 )
end_define

begin_define
define|#
directive|define
name|reserved
parameter_list|(
name|x
parameter_list|)
value|( (x)< 0&& (exp(x) == 0) )
end_define

begin_comment
comment|/************************************************/
end_comment

begin_comment
comment|/*						*/
end_comment

begin_comment
comment|/*	Opcodes description table stuff		*/
end_comment

begin_comment
comment|/*						*/
end_comment

begin_comment
comment|/************************************************/
end_comment

begin_struct
struct|struct
name|operand_des
block|{
comment|/* Operand descriptor in great table */
name|int
name|add_modes
decl_stmt|;
comment|/* Allowed addressing modes */
name|int
name|length
decl_stmt|;
comment|/* Length of this data (bytes) */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|Add
value|1
end_define

begin_comment
comment|/* Any address except PC relative& ablsolute */
end_comment

begin_define
define|#
directive|define
name|Dir
value|2
end_define

begin_comment
comment|/* Direct register */
end_comment

begin_define
define|#
directive|define
name|Imm
value|4
end_define

begin_comment
comment|/* Immediate datum */
end_comment

begin_define
define|#
directive|define
name|Lit
value|8
end_define

begin_comment
comment|/* Short literal */
end_comment

begin_define
define|#
directive|define
name|Brd
value|0x10
end_define

begin_comment
comment|/* Branch displacement */
end_comment

begin_define
define|#
directive|define
name|Pcrel
value|0x20
end_define

begin_comment
comment|/* PC relative allowed */
end_comment

begin_define
define|#
directive|define
name|Abs
value|0x40
end_define

begin_comment
comment|/* Absolute address allowed */
end_comment

begin_define
define|#
directive|define
name|SPmode
value|0x80
end_define

begin_comment
comment|/* The stack pointer was involved , -(sp) or (sp)+ */
end_comment

begin_define
define|#
directive|define
name|ADDFIELD
value|0xff
end_define

begin_comment
comment|/* Allowed addressing modes */
end_comment

begin_define
define|#
directive|define
name|W
value|0x100
end_define

begin_comment
comment|/* Access is write */
end_comment

begin_define
define|#
directive|define
name|R
value|0x200
end_define

begin_comment
comment|/* Access is 'read' */
end_comment

begin_define
define|#
directive|define
name|Indx
value|0x400
end_define

begin_comment
comment|/* Indexable base address */
end_comment

begin_define
define|#
directive|define
name|NOVF
value|0x800
end_define

begin_comment
comment|/* Inhibit overflow check when writing byte/word */
end_comment

begin_define
define|#
directive|define
name|FLP
value|0x1000
end_define

begin_comment
comment|/* Floating point operand */
end_comment

begin_define
define|#
directive|define
name|M
value|(R|W)
end_define

begin_comment
comment|/* Access is 'modify' */
end_comment

begin_define
define|#
directive|define
name|PR
value|(Pcrel|Abs)
end_define

begin_define
define|#
directive|define
name|ADDR
value|(PR|Add)
end_define

begin_define
define|#
directive|define
name|ADI
value|(ADDR|Dir|Imm|Lit)
end_define

begin_define
define|#
directive|define
name|AD
value|(ADDR|Dir)
end_define

begin_define
define|#
directive|define
name|MAD
value|(M|ADDR|Dir)
end_define

begin_define
define|#
directive|define
name|WAD
value|(W|ADDR|Dir)
end_define

begin_define
define|#
directive|define
name|WD
value|(W|Dir)
end_define

begin_define
define|#
directive|define
name|NWAD
value|(NOVF|WAD)
end_define

begin_define
define|#
directive|define
name|NMAD
value|(NOVF|MAD)
end_define

begin_define
define|#
directive|define
name|RADI
value|(R|ADI)
end_define

begin_comment
comment|/* Readable datum */
end_comment

begin_define
define|#
directive|define
name|RAD
value|(R|AD)
end_define

begin_comment
comment|/* Modify type access for destinations */
end_comment

begin_define
define|#
directive|define
name|RADF
value|(RAD|FLP)
end_define

begin_define
define|#
directive|define
name|WADF
value|(WAD|FLP)
end_define

begin_struct
struct|struct
name|opcode_des
block|{
comment|/* One line in the big table */
name|int
function_decl|(
modifier|*
name|routine
function_decl|)
parameter_list|()
function_decl|;
comment|/* Handler for this opcode */
name|struct
name|operand_des
name|operand
index|[
literal|4
index|]
decl_stmt|;
comment|/* Up to 4 operands */
block|}
struct|;
end_struct

begin_comment
comment|/************************************************/
end_comment

begin_comment
comment|/*						*/
end_comment

begin_comment
comment|/*	Operand descriptor as returned		*/
end_comment

begin_comment
comment|/*	by the address mode decoder 		*/
end_comment

begin_comment
comment|/*						*/
end_comment

begin_comment
comment|/************************************************/
end_comment

begin_struct
struct|struct
name|oprnd
block|{
name|long
name|mode
decl_stmt|;
comment|/* Add, Imm, Dir or Brd */
name|long
name|reg_number
decl_stmt|;
comment|/* returned for Dir mode */
name|long
name|address
decl_stmt|;
comment|/* Relevant for Add or Brd */
name|long
name|data
decl_stmt|;
name|long
name|data2
decl_stmt|;
comment|/* Up to 8 bytes returned */
name|long
name|length
decl_stmt|;
comment|/* Length of data manipulated */
block|}
struct|;
end_struct

begin_comment
comment|/************************************************/
end_comment

begin_comment
comment|/*						*/
end_comment

begin_comment
comment|/*	Some PSL macros (usefull)		*/
end_comment

begin_comment
comment|/*						*/
end_comment

begin_comment
comment|/************************************************/
end_comment

begin_define
define|#
directive|define
name|carry
value|(psl& PSL_C)
end_define

begin_define
define|#
directive|define
name|negative
value|(psl& PSL_N)
end_define

begin_define
define|#
directive|define
name|overflow
value|(psl& PSL_V)
end_define

begin_define
define|#
directive|define
name|zero
value|(psl& PSL_Z)
end_define

begin_define
define|#
directive|define
name|carry_1
value|psl |= PSL_C
end_define

begin_define
define|#
directive|define
name|negative_1
value|psl |= PSL_N
end_define

begin_define
define|#
directive|define
name|overflow_1
value|psl |= PSL_V
end_define

begin_define
define|#
directive|define
name|zero_1
value|psl |= PSL_Z
end_define

begin_define
define|#
directive|define
name|carry_0
value|psl&= ~PSL_C
end_define

begin_define
define|#
directive|define
name|negative_0
value|psl&= ~PSL_N
end_define

begin_define
define|#
directive|define
name|overflow_0
value|psl&= ~PSL_V
end_define

begin_define
define|#
directive|define
name|zero_0
value|psl&= ~PSL_Z
end_define

begin_function_decl
name|struct
name|oprnd
modifier|*
name|operand
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
name|struct
name|opcode_des
name|Table
index|[]
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|double_length
block|{
name|int
name|low
decl_stmt|;
name|int
name|high
decl_stmt|;
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|double_length
name|quadword
typedef|;
end_typedef

end_unit

