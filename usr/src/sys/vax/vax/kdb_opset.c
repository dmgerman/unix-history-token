begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *	@(#)kdb_opset.c	7.5 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|"../kdb/defs.h"
end_include

begin_comment
comment|/*  * Instruction printing.  */
end_comment

begin_decl_stmt
name|REGLIST
name|kdbreglist
index|[]
init|=
block|{
literal|"p1lr"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_p1lr
block|,
literal|"p1br"
block|,
operator|(
name|int
operator|*
operator|)
operator|&
name|kdbpcb
operator|.
name|pcb_p1br
block|,
literal|"p0lr"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_p0lr
block|,
literal|"p0br"
block|,
operator|(
name|int
operator|*
operator|)
operator|&
name|kdbpcb
operator|.
name|pcb_p0br
block|,
literal|"ksp"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_ksp
block|,
literal|"esp"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_esp
block|,
literal|"ssp"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_ssp
block|,
literal|"psl"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_psl
block|,
literal|"pc"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_pc
block|,
literal|"usp"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_usp
block|,
literal|"fp"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_fp
block|,
literal|"ap"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_ap
block|,
literal|"r11"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_r11
block|,
literal|"r10"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_r10
block|,
literal|"r9"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_r9
block|,
literal|"r8"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_r8
block|,
literal|"r7"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_r7
block|,
literal|"r6"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_r6
block|,
literal|"r5"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_r5
block|,
literal|"r4"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_r4
block|,
literal|"r3"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_r3
block|,
literal|"r2"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_r2
block|,
literal|"r1"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_r1
block|,
literal|"r0"
block|,
operator|&
name|kdbpcb
operator|.
name|pcb_r0
block|, }
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Argument data types  *  * If you change these definitions, you must also change the tables  * in assizetab.c  */
end_comment

begin_define
define|#
directive|define
name|TYPB
value|000
end_define

begin_comment
comment|/* byte integer */
end_comment

begin_define
define|#
directive|define
name|TYPW
value|001
end_define

begin_comment
comment|/* word integer */
end_comment

begin_define
define|#
directive|define
name|TYPL
value|002
end_define

begin_comment
comment|/* long integer */
end_comment

begin_define
define|#
directive|define
name|TYPQ
value|003
end_define

begin_comment
comment|/* quad integer */
end_comment

begin_define
define|#
directive|define
name|TYPO
value|004
end_define

begin_comment
comment|/* octa integer */
end_comment

begin_define
define|#
directive|define
name|TYPF
value|005
end_define

begin_comment
comment|/* F float */
end_comment

begin_define
define|#
directive|define
name|TYPD
value|006
end_define

begin_comment
comment|/* D float */
end_comment

begin_define
define|#
directive|define
name|TYPG
value|007
end_define

begin_comment
comment|/* G float */
end_comment

begin_define
define|#
directive|define
name|TYPH
value|010
end_define

begin_comment
comment|/* H float */
end_comment

begin_define
define|#
directive|define
name|TYPUNPACKED
value|011
end_define

begin_comment
comment|/* when unpacked into mantissa& exponent */
end_comment

begin_define
define|#
directive|define
name|TYPNONE
value|012
end_define

begin_comment
comment|/* when nothing */
end_comment

begin_define
define|#
directive|define
name|TYPLG
value|4
end_define

begin_comment
comment|/* number of bits the above take up */
end_comment

begin_define
define|#
directive|define
name|TYPMASK
value|((1<<TYPLG)-1)
end_define

begin_comment
comment|/* the mask (assumes 2's comp arith) */
end_comment

begin_comment
comment|/*  * Constructors and extractors for argument access kinds and types  */
end_comment

begin_define
define|#
directive|define
name|A_CONS
parameter_list|(
name|access
parameter_list|,
name|type
parameter_list|)
value|((access) | (type))
end_define

begin_define
define|#
directive|define
name|A_ACCEXT
parameter_list|(
name|consed
parameter_list|)
value|((consed)& (TYPMASK<< TYPLG))
end_define

begin_define
define|#
directive|define
name|A_TYPEXT
parameter_list|(
name|consed
parameter_list|)
value|((consed)& TYPMASK)
end_define

begin_comment
comment|/*  * Argument access types used to test validity of operands to operators  */
end_comment

begin_define
define|#
directive|define
name|ACCR
value|(1<<TYPLG)
end_define

begin_comment
comment|/* read */
end_comment

begin_define
define|#
directive|define
name|ACCW
value|(2<<TYPLG)
end_define

begin_comment
comment|/* write */
end_comment

begin_define
define|#
directive|define
name|ACCB
value|(4<<TYPLG)
end_define

begin_comment
comment|/* branch displacement */
end_comment

begin_define
define|#
directive|define
name|ACCA
value|(8<<TYPLG)
end_define

begin_comment
comment|/* address only */
end_comment

begin_define
define|#
directive|define
name|ACCV
value|(8<<TYPLG)
end_define

begin_comment
comment|/* address only */
end_comment

begin_define
define|#
directive|define
name|ACCM
value|(ACCR | ACCW)
end_define

begin_comment
comment|/* modify */
end_comment

begin_define
define|#
directive|define
name|ACCI
value|(ACCB | ACCR)
end_define

begin_comment
comment|/* XFC code */
end_comment

begin_define
define|#
directive|define
name|ACCESSMASK
value|(ACCA | ACCR | ACCW | ACCB)
end_define

begin_comment
comment|/* the mask */
end_comment

begin_comment
comment|/*  * Construction of TYPX and ACCX, to make the instrs table  * easy to use and read.  */
end_comment

begin_comment
comment|/*  * For real memory address  */
end_comment

begin_define
define|#
directive|define
name|A_AB
value|A_CONS(ACCA, TYPB)
end_define

begin_define
define|#
directive|define
name|A_AW
value|A_CONS(ACCA, TYPW)
end_define

begin_define
define|#
directive|define
name|A_AL
value|A_CONS(ACCA, TYPL)
end_define

begin_define
define|#
directive|define
name|A_AQ
value|A_CONS(ACCA, TYPQ)
end_define

begin_define
define|#
directive|define
name|A_AO
value|A_CONS(ACCA, TYPO)
end_define

begin_define
define|#
directive|define
name|A_AF
value|A_CONS(ACCA, TYPF)
end_define

begin_define
define|#
directive|define
name|A_AD
value|A_CONS(ACCA, TYPD)
end_define

begin_define
define|#
directive|define
name|A_AG
value|A_CONS(ACCA, TYPG)
end_define

begin_define
define|#
directive|define
name|A_AH
value|A_CONS(ACCA, TYPH)
end_define

begin_comment
comment|/*  * For real memory addresses, or register addresses [sic]  *  * CHEAT! we just call these read access, since  * registers are allowed. All field instruction, except insv,  * are are read access fields.  */
end_comment

begin_define
define|#
directive|define
name|A_VB
value|A_CONS(ACCR, TYPB)
end_define

begin_define
define|#
directive|define
name|A_VW
value|A_CONS(ACCR, TYPW)
end_define

begin_define
define|#
directive|define
name|A_VL
value|A_CONS(ACCR, TYPL)
end_define

begin_define
define|#
directive|define
name|A_VQ
value|A_CONS(ACCR, TYPQ)
end_define

begin_define
define|#
directive|define
name|A_VO
value|A_CONS(ACCR, TYPO)
end_define

begin_define
define|#
directive|define
name|A_VF
value|A_CONS(ACCR, TYPF)
end_define

begin_define
define|#
directive|define
name|A_VD
value|A_CONS(ACCR, TYPD)
end_define

begin_define
define|#
directive|define
name|A_VG
value|A_CONS(ACCR, TYPG)
end_define

begin_define
define|#
directive|define
name|A_VH
value|A_CONS(ACCR, TYPH)
end_define

begin_comment
comment|/*  * For branch displacement  */
end_comment

begin_define
define|#
directive|define
name|A_BB
value|A_CONS(ACCB, TYPB)
end_define

begin_define
define|#
directive|define
name|A_BW
value|A_CONS(ACCB, TYPW)
end_define

begin_comment
comment|/*  * For modification  */
end_comment

begin_define
define|#
directive|define
name|A_MB
value|A_CONS(ACCM, TYPB)
end_define

begin_define
define|#
directive|define
name|A_MW
value|A_CONS(ACCM, TYPW)
end_define

begin_define
define|#
directive|define
name|A_ML
value|A_CONS(ACCM, TYPL)
end_define

begin_define
define|#
directive|define
name|A_MF
value|A_CONS(ACCM, TYPF)
end_define

begin_define
define|#
directive|define
name|A_MD
value|A_CONS(ACCM, TYPD)
end_define

begin_define
define|#
directive|define
name|A_MG
value|A_CONS(ACCM, TYPG)
end_define

begin_define
define|#
directive|define
name|A_MH
value|A_CONS(ACCM, TYPH)
end_define

begin_comment
comment|/*  * For reading  */
end_comment

begin_define
define|#
directive|define
name|A_RB
value|A_CONS(ACCR, TYPB)
end_define

begin_define
define|#
directive|define
name|A_RW
value|A_CONS(ACCR, TYPW)
end_define

begin_define
define|#
directive|define
name|A_RL
value|A_CONS(ACCR, TYPL)
end_define

begin_define
define|#
directive|define
name|A_RQ
value|A_CONS(ACCR, TYPQ)
end_define

begin_define
define|#
directive|define
name|A_RO
value|A_CONS(ACCR, TYPO)
end_define

begin_define
define|#
directive|define
name|A_RF
value|A_CONS(ACCR, TYPF)
end_define

begin_define
define|#
directive|define
name|A_RD
value|A_CONS(ACCR, TYPD)
end_define

begin_define
define|#
directive|define
name|A_RG
value|A_CONS(ACCR, TYPG)
end_define

begin_define
define|#
directive|define
name|A_RH
value|A_CONS(ACCR, TYPH)
end_define

begin_comment
comment|/*  * For writing  */
end_comment

begin_define
define|#
directive|define
name|A_WB
value|A_CONS(ACCW, TYPB)
end_define

begin_define
define|#
directive|define
name|A_WW
value|A_CONS(ACCW, TYPW)
end_define

begin_define
define|#
directive|define
name|A_WL
value|A_CONS(ACCW, TYPL)
end_define

begin_define
define|#
directive|define
name|A_WQ
value|A_CONS(ACCW, TYPQ)
end_define

begin_define
define|#
directive|define
name|A_WO
value|A_CONS(ACCW, TYPO)
end_define

begin_define
define|#
directive|define
name|A_WF
value|A_CONS(ACCW, TYPF)
end_define

begin_define
define|#
directive|define
name|A_WD
value|A_CONS(ACCW, TYPD)
end_define

begin_define
define|#
directive|define
name|A_WG
value|A_CONS(ACCW, TYPG)
end_define

begin_define
define|#
directive|define
name|A_WH
value|A_CONS(ACCW, TYPH)
end_define

begin_struct
struct|struct
name|insttab
block|{
name|char
modifier|*
name|iname
decl_stmt|;
name|u_char
name|eopcode
decl_stmt|;
name|u_char
name|popcode
decl_stmt|;
name|char
name|nargs
decl_stmt|;
name|u_char
name|argtype
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|OP
parameter_list|(
name|name
parameter_list|,
name|eopcode
parameter_list|,
name|popdcode
parameter_list|,
name|nargs
parameter_list|,
name|a1
parameter_list|,
name|a2
parameter_list|,
name|a3
parameter_list|,
name|a4
parameter_list|,
name|a5
parameter_list|,
name|a6
parameter_list|)
define|\
value|{name,eopcode,popdcode,nargs,a1,a2,a3,a4,a5,a6}
end_define

begin_comment
comment|/*  * Definitions for the escape bytes  */
end_comment

begin_define
define|#
directive|define
name|CORE
value|0
end_define

begin_define
define|#
directive|define
name|NEW
value|1
end_define

begin_define
define|#
directive|define
name|ESCD
value|0xfd
end_define

begin_define
define|#
directive|define
name|ESCF
value|0xff
end_define

begin_define
define|#
directive|define
name|mapescbyte
parameter_list|(
name|b
parameter_list|)
value|((b) == ESCD ? 1 : (b) == ESCF ? 2 : 0)
end_define

begin_decl_stmt
specifier|static
name|struct
name|insttab
name|insttab
index|[]
init|=
block|{
include|#
directive|include
file|"../vax/kdb_instrs"
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Convert TYP[BWLQOFDGH] into {1 if relocation not OK}  */
end_comment

begin_decl_stmt
name|int
name|ty_NORELOC
index|[]
init|=
block|{
literal|0
block|,
comment|/* TYPB */
literal|0
block|,
comment|/* TYPW */
literal|0
block|,
comment|/* TYPL */
literal|1
block|,
comment|/* TYPQ */
literal|1
block|,
comment|/* TYPO */
literal|1
block|,
comment|/* TYPF */
literal|1
block|,
comment|/* TYPD */
literal|1
block|,
comment|/* TYPG */
literal|1
block|,
comment|/* TYPH */
literal|1
comment|/* TYPNONE */
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Convert TYP[BWLQOFDGH] into {1 ... 16}  */
end_comment

begin_decl_stmt
name|int
name|ty_nbyte
index|[]
init|=
block|{
literal|1
block|,
comment|/* TYPB */
literal|2
block|,
comment|/* TYPW */
literal|4
block|,
comment|/* TYPL */
literal|8
block|,
comment|/* TYPQ */
literal|16
block|,
comment|/* TYPO */
literal|4
block|,
comment|/* TYPF */
literal|8
block|,
comment|/* TYPD */
literal|8
block|,
comment|/* TYPG */
literal|16
block|,
comment|/* TYPH */
literal|0
comment|/* TYPNONE */
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|regname
index|[]
init|=
block|{
literal|"r0"
block|,
literal|"r1"
block|,
literal|"r2"
block|,
literal|"r3"
block|,
literal|"r4"
block|,
literal|"r5"
block|,
literal|"r6"
block|,
literal|"r7"
block|,
literal|"r8"
block|,
literal|"r9"
block|,
literal|"r10"
block|,
literal|"r11"
block|,
literal|"ap"
block|,
literal|"fp"
block|,
literal|"sp"
block|,
literal|"pc"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|char
modifier|*
name|fltimm
index|[]
init|=
block|{
literal|"0.5"
block|,
literal|"0.5625"
block|,
literal|"0.625"
block|,
literal|"0.6875"
block|,
literal|"0.75"
block|,
literal|"0.8125"
block|,
literal|"0.875"
block|,
literal|"0.9375"
block|,
literal|"1.0"
block|,
literal|"1.125"
block|,
literal|"1.25"
block|,
literal|"1.375"
block|,
literal|"1.5"
block|,
literal|"1.625"
block|,
literal|"1.75"
block|,
literal|"1.875"
block|,
literal|"2.0"
block|,
literal|"2.25"
block|,
literal|"2.5"
block|,
literal|"2.75"
block|,
literal|"3.0"
block|,
literal|"3.25"
block|,
literal|"3.5"
block|,
literal|"3.75"
block|,
literal|"4.0"
block|,
literal|"4.5"
block|,
literal|"5.0"
block|,
literal|"5.5"
block|,
literal|"6.0"
block|,
literal|"6.5"
block|,
literal|"7.0"
block|,
literal|"7.5"
block|,
literal|"8.0"
block|,
literal|"9.0"
block|,
literal|"10.0"
block|,
literal|"11.0"
block|,
literal|"12.0"
block|,
literal|"13.0"
block|,
literal|"14.0"
block|,
literal|"15.0"
block|,
literal|"16.0"
block|,
literal|"18.0"
block|,
literal|"20.0"
block|,
literal|"22.0"
block|,
literal|"24.0"
block|,
literal|"26.0"
block|,
literal|"28.0"
block|,
literal|"30.0"
block|,
literal|"32.0"
block|,
literal|"36.0"
block|,
literal|"40.0"
block|,
literal|"44.0"
block|,
literal|"48.0"
block|,
literal|"52.0"
block|,
literal|"56.0"
block|,
literal|"60.0"
block|,
literal|"64.0"
block|,
literal|"72.0"
block|,
literal|"80.0"
block|,
literal|"88.0"
block|,
literal|"96.0"
block|,
literal|"104.0"
block|,
literal|"112.0"
block|,
literal|"120.0"
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|int
name|type
decl_stmt|,
name|space
decl_stmt|,
name|incp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|insoutvar
index|[
literal|36
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Definitions for registers and for operand classes  */
end_comment

begin_function_decl
specifier|static
name|char
modifier|*
name|insregname
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* how to print a register */
end_comment

begin_define
define|#
directive|define
name|R_PC
value|0xF
end_define

begin_define
define|#
directive|define
name|OC_IMM0
value|0x0
end_define

begin_define
define|#
directive|define
name|OC_IMM1
value|0x1
end_define

begin_define
define|#
directive|define
name|OC_IMM2
value|0x2
end_define

begin_define
define|#
directive|define
name|OC_IMM3
value|0x3
end_define

begin_define
define|#
directive|define
name|OC_INDEX
value|0x4
end_define

begin_define
define|#
directive|define
name|OC_REG
value|0x5
end_define

begin_define
define|#
directive|define
name|OC_DREG
value|0x6
end_define

begin_define
define|#
directive|define
name|OC_ADREG
value|0x7
end_define

begin_define
define|#
directive|define
name|OC_AIREG
value|0x8
end_define

begin_define
define|#
directive|define
name|OC_DAIREG
value|0x9
end_define

begin_define
define|#
directive|define
name|OC_BDISP
value|0xA
end_define

begin_define
define|#
directive|define
name|OC_DBDISP
value|0xB
end_define

begin_define
define|#
directive|define
name|OC_WDISP
value|0xC
end_define

begin_define
define|#
directive|define
name|OC_DWDISP
value|0xD
end_define

begin_define
define|#
directive|define
name|OC_LDISP
value|0xE
end_define

begin_define
define|#
directive|define
name|OC_DLDISP
value|0xF
end_define

begin_define
define|#
directive|define
name|OC_SHIFT
value|4
end_define

begin_define
define|#
directive|define
name|OC_CONS
parameter_list|(
name|oc
parameter_list|,
name|reg
parameter_list|)
value|(((oc& 0xF)<< OC_SHIFT) | (reg& 0xF))
end_define

begin_define
define|#
directive|define
name|OC_AMEXT
parameter_list|(
name|x
parameter_list|)
value|(((x)>> OC_SHIFT)& 0xF)
end_define

begin_define
define|#
directive|define
name|OC_REGEXT
parameter_list|(
name|x
parameter_list|)
value|((x)& 0xF)
end_define

begin_comment
comment|/*  * Definitions for large numbers  */
end_comment

begin_include
include|#
directive|include
file|"asnumber.h"
end_include

begin_typedef
typedef|typedef
name|struct
name|as_number
modifier|*
name|numberp
typedef|;
end_typedef

begin_function_decl
specifier|static
name|numberp
name|snarf
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|numberp
name|snarfreloc
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Definitions for special instructions  */
end_comment

begin_define
define|#
directive|define
name|CASEB
value|0x8F
end_define

begin_define
define|#
directive|define
name|CASEW
value|0xAF
end_define

begin_define
define|#
directive|define
name|CASEL
value|0xCF
end_define

begin_comment
comment|/* two level 1-based index by opcode into insttab */
end_comment

begin_decl_stmt
specifier|static
name|short
name|ioptab
index|[
literal|3
index|]
index|[
literal|256
index|]
decl_stmt|;
end_decl_stmt

begin_macro
name|kdbsetup
argument_list|()
end_macro

begin_block
block|{
specifier|register
name|struct
name|insttab
modifier|*
name|p
decl_stmt|;
name|int
name|mapchar
decl_stmt|;
for|for
control|(
name|p
operator|=
name|insttab
init|;
name|p
operator|->
name|iname
condition|;
name|p
operator|++
control|)
block|{
name|mapchar
operator|=
name|mapescbyte
argument_list|(
name|p
operator|->
name|eopcode
argument_list|)
expr_stmt|;
if|if
condition|(
name|ioptab
index|[
name|mapchar
index|]
index|[
name|p
operator|->
name|popcode
index|]
condition|)
continue|continue;
name|ioptab
index|[
name|mapchar
index|]
index|[
name|p
operator|->
name|popcode
index|]
operator|=
operator|(
name|p
operator|-
name|insttab
operator|)
operator|+
literal|1
expr_stmt|;
block|}
block|}
end_block

begin_function_decl
specifier|static
name|u_char
name|snarfuchar
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Global variables for communicating with the minions and printins  */
end_comment

begin_decl_stmt
specifier|static
name|int
name|idsp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|short
name|argno
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* which argument one is working on */
end_comment

begin_decl_stmt
specifier|static
name|char
name|insoutfmt
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* how to format the relocated symbols */
end_comment

begin_expr_stmt
specifier|static
name|savevar
argument_list|(
argument|val
argument_list|)
name|long
name|val
expr_stmt|;
end_expr_stmt

begin_block
block|{
name|kdbvar
index|[
name|argno
index|]
operator|=
name|val
expr_stmt|;
name|insoutvar
index|[
name|argno
index|]
operator|=
name|val
expr_stmt|;
block|}
end_block

begin_comment
comment|/* ARGSUSED */
end_comment

begin_macro
name|kdbprintins
argument_list|(
argument|Idsp
argument_list|,
argument|ins
argument_list|)
end_macro

begin_decl_stmt
name|u_char
name|ins
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|Idsp
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|u_char
name|mode
decl_stmt|;
comment|/* mode */
name|u_char
name|ins2
decl_stmt|;
name|char
modifier|*
name|indexreg
decl_stmt|;
comment|/* print of which register indexes */
name|char
modifier|*
name|indexed
decl_stmt|;
comment|/* we indexed */
name|char
modifier|*
name|operandout
parameter_list|()
function_decl|;
specifier|register
name|u_char
modifier|*
name|ap
decl_stmt|;
specifier|register
name|struct
name|insttab
modifier|*
name|ip
decl_stmt|;
name|u_char
name|optype
decl_stmt|;
name|int
name|mapchar
decl_stmt|;
name|idsp
operator|=
name|Idsp
expr_stmt|;
name|type
operator|=
name|DSYM
expr_stmt|;
name|space
operator|=
name|idsp
expr_stmt|;
name|insoutfmt
index|[
literal|0
index|]
operator|=
literal|0
expr_stmt|;
name|incp
operator|=
literal|1
expr_stmt|;
if|if
condition|(
operator|(
name|mapchar
operator|=
name|mapescbyte
argument_list|(
name|ins
argument_list|)
operator|)
operator|!=
literal|0
condition|)
block|{
name|ins2
operator|=
name|snarfuchar
argument_list|()
expr_stmt|;
if|if
condition|(
name|ioptab
index|[
name|mapchar
index|]
index|[
name|ins2
index|]
operator|==
literal|0
condition|)
block|{
comment|/* 			 *	Oops; not a defined instruction; 			 *	back over this escape byte. 			 */
name|incp
operator|-=
literal|1
expr_stmt|;
name|mapchar
operator|=
literal|0
expr_stmt|;
block|}
else|else
block|{
name|ins
operator|=
name|ins2
expr_stmt|;
block|}
block|}
if|if
condition|(
name|ioptab
index|[
name|mapchar
index|]
index|[
name|ins
index|]
operator|==
literal|0
condition|)
block|{
name|kdbprintf
argument_list|(
literal|"<undefined operator byte>: %x"
argument_list|,
name|ins
argument_list|)
expr_stmt|;
goto|goto
name|ret
goto|;
block|}
name|ip
operator|=
operator|&
name|insttab
index|[
name|ioptab
index|[
name|mapchar
index|]
index|[
name|ins
index|]
operator|-
literal|1
index|]
expr_stmt|;
name|kdbprintf
argument_list|(
literal|"%s\t"
argument_list|,
name|ip
operator|->
name|iname
argument_list|)
expr_stmt|;
for|for
control|(
name|ap
operator|=
name|ip
operator|->
name|argtype
operator|,
name|argno
operator|=
literal|0
init|;
name|argno
operator|<
name|ip
operator|->
name|nargs
condition|;
name|argno
operator|++
operator|,
name|ap
operator|++
control|)
block|{
name|savevar
argument_list|(
literal|0x80000000
argument_list|)
expr_stmt|;
comment|/* an illegal symbol */
name|optype
operator|=
operator|*
name|ap
expr_stmt|;
if|if
condition|(
name|argno
operator|!=
literal|0
condition|)
name|kdbprintc
argument_list|(
literal|','
argument_list|)
expr_stmt|;
name|indexreg
operator|=
literal|0
expr_stmt|;
name|indexed
operator|=
literal|0
expr_stmt|;
do|do
block|{
if|if
condition|(
name|A_ACCEXT
argument_list|(
name|optype
argument_list|)
operator|&
name|ACCB
condition|)
block|{
switch|switch
condition|(
name|A_TYPEXT
argument_list|(
name|optype
argument_list|)
condition|)
block|{
case|case
name|TYPB
case|:
name|mode
operator|=
name|OC_CONS
argument_list|(
name|OC_BDISP
argument_list|,
name|R_PC
argument_list|)
expr_stmt|;
break|break;
case|case
name|TYPW
case|:
name|mode
operator|=
name|OC_CONS
argument_list|(
name|OC_WDISP
argument_list|,
name|R_PC
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
else|else
block|{
name|mode
operator|=
name|snarfuchar
argument_list|()
expr_stmt|;
block|}
name|indexreg
operator|=
name|operandout
argument_list|(
name|mode
argument_list|,
name|optype
argument_list|)
expr_stmt|;
if|if
condition|(
name|indexed
condition|)
name|kdbprintf
argument_list|(
literal|"[%s]"
argument_list|,
name|indexed
argument_list|)
expr_stmt|;
name|indexed
operator|=
name|indexreg
expr_stmt|;
block|}
do|while
condition|(
name|indexed
condition|)
do|;
block|}
if|if
condition|(
name|mapchar
operator|==
literal|0
condition|)
block|{
switch|switch
condition|(
name|ins
condition|)
block|{
case|case
name|CASEB
case|:
case|case
name|CASEW
case|:
case|case
name|CASEL
case|:
name|casebody
argument_list|(
name|insoutvar
index|[
literal|1
index|]
argument_list|,
name|insoutvar
index|[
literal|2
index|]
argument_list|)
expr_stmt|;
break|break;
default|default:
break|break;
block|}
block|}
name|ret
label|:
empty_stmt|;
name|kdbdotinc
operator|=
name|incp
expr_stmt|;
block|}
end_block

begin_macro
name|casebody
argument_list|(
argument|base
argument_list|,
argument|limit
argument_list|)
end_macro

begin_decl_stmt
name|long
name|base
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|long
name|limit
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|i
decl_stmt|;
name|u_int
name|baseincp
decl_stmt|;
name|u_int
name|advincp
decl_stmt|;
name|struct
name|as_number
modifier|*
name|valuep
decl_stmt|;
define|#
directive|define
name|OSIZE
value|(sizeof(short))
name|argno
operator|=
literal|0
expr_stmt|;
name|baseincp
operator|=
name|incp
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<=
name|limit
condition|;
name|i
operator|++
control|)
block|{
name|kdbprintc
argument_list|(
name|EOR
argument_list|)
expr_stmt|;
name|kdbprintf
argument_list|(
literal|"    %R:  "
argument_list|,
name|i
operator|+
name|base
argument_list|)
expr_stmt|;
name|valuep
operator|=
name|snarfreloc
argument_list|(
name|OSIZE
argument_list|,
literal|0
argument_list|)
expr_stmt|;
name|advincp
operator|=
name|incp
expr_stmt|;
name|incp
operator|=
name|baseincp
expr_stmt|;
name|dispaddress
argument_list|(
name|valuep
argument_list|,
name|OC_CONS
argument_list|(
name|OC_WDISP
argument_list|,
name|R_PC
argument_list|)
argument_list|)
expr_stmt|;
name|incp
operator|=
name|advincp
expr_stmt|;
block|}
block|}
end_block

begin_comment
comment|/*  * magic values to mung an offset to a register into  * something that psymoff can understand.. all magic  */
end_comment

begin_comment
comment|/* 0	1	2	3	4 */
end_comment

begin_decl_stmt
specifier|static
name|long
name|magic_masks
index|[
literal|5
index|]
init|=
block|{
literal|0
block|,
literal|0x80
block|,
literal|0x8000
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|static
name|long
name|magic_compl
index|[
literal|5
index|]
init|=
block|{
literal|0
block|,
literal|0x100
block|,
literal|0x10000
block|,
literal|0
block|,
literal|0
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Snarf up some bytes, and put in the magic relocation flags  */
end_comment

begin_function
specifier|static
name|numberp
name|snarfreloc
parameter_list|(
name|nbytes
parameter_list|)
name|int
name|nbytes
decl_stmt|;
block|{
name|numberp
name|back
decl_stmt|;
name|back
operator|=
name|snarf
argument_list|(
name|nbytes
argument_list|)
expr_stmt|;
if|if
condition|(
name|back
operator|->
name|num_ulong
index|[
literal|0
index|]
operator|&
name|magic_masks
index|[
name|nbytes
index|]
condition|)
name|back
operator|->
name|num_ulong
index|[
literal|0
index|]
operator|-=
name|magic_compl
index|[
name|nbytes
index|]
expr_stmt|;
return|return
operator|(
name|back
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * The following code is NOT portable from the PDP 11 to the VAX  * because of the byte ordering problem.  */
end_comment

begin_function
specifier|static
name|numberp
name|snarf
parameter_list|(
name|nbytes
parameter_list|)
name|int
name|nbytes
decl_stmt|;
block|{
specifier|register
name|int
name|i
decl_stmt|;
specifier|static
name|struct
name|as_number
name|backnumber
decl_stmt|;
specifier|static
name|struct
name|as_number
name|znumber
decl_stmt|;
comment|/* init'ed to 0 */
name|backnumber
operator|=
name|znumber
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|nbytes
condition|;
name|i
operator|++
control|)
name|backnumber
operator|.
name|num_uchar
index|[
name|i
index|]
operator|=
name|snarfuchar
argument_list|()
expr_stmt|;
return|return
operator|(
operator|&
name|backnumber
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Read one single character, and advance the dot  */
end_comment

begin_function
specifier|static
name|u_char
name|snarfuchar
parameter_list|()
block|{
name|u_char
name|back
decl_stmt|;
comment|/* 	 *	assert: bchkget and inkdot don't have side effects 	 */
name|back
operator|=
operator|(
name|u_char
operator|)
name|kdbbchkget
argument_list|(
name|kdbinkdot
argument_list|(
name|incp
argument_list|)
argument_list|,
name|idsp
argument_list|)
expr_stmt|;
name|incp
operator|+=
literal|1
expr_stmt|;
return|return
operator|(
name|back
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * normal operand; return non zero pointer to register  * name if this is an index instruction.  */
end_comment

begin_function
name|char
modifier|*
name|operandout
parameter_list|(
name|mode
parameter_list|,
name|optype
parameter_list|)
name|u_char
name|mode
decl_stmt|;
name|u_char
name|optype
decl_stmt|;
block|{
name|char
modifier|*
name|r
decl_stmt|;
name|int
name|regnumber
decl_stmt|;
name|int
name|nbytes
decl_stmt|;
name|regnumber
operator|=
name|OC_REGEXT
argument_list|(
name|mode
argument_list|)
expr_stmt|;
name|r
operator|=
name|insregname
argument_list|(
name|regnumber
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|OC_AMEXT
argument_list|(
name|mode
argument_list|)
condition|)
block|{
case|case
name|OC_IMM0
case|:
case|case
name|OC_IMM1
case|:
case|case
name|OC_IMM2
case|:
case|case
name|OC_IMM3
case|:
name|shortliteral
argument_list|(
name|mode
argument_list|,
name|optype
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|OC_INDEX
case|:
return|return
operator|(
name|r
operator|)
return|;
comment|/* will be printed later */
case|case
name|OC_REG
case|:
name|kdbprintf
argument_list|(
literal|"%s"
argument_list|,
name|r
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|OC_DREG
case|:
name|kdbprintf
argument_list|(
literal|"(%s)"
argument_list|,
name|r
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|OC_ADREG
case|:
name|kdbprintf
argument_list|(
literal|"-(%s)"
argument_list|,
name|r
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|OC_DAIREG
case|:
name|kdbprintc
argument_list|(
literal|'*'
argument_list|)
expr_stmt|;
case|case
name|OC_AIREG
case|:
if|if
condition|(
name|regnumber
operator|==
name|R_PC
condition|)
block|{
name|pcimmediate
argument_list|(
name|mode
argument_list|,
name|optype
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|kdbprintf
argument_list|(
literal|"(%s)+"
argument_list|,
name|r
argument_list|)
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
case|case
name|OC_DBDISP
case|:
name|kdbprintc
argument_list|(
literal|'*'
argument_list|)
expr_stmt|;
case|case
name|OC_BDISP
case|:
name|nbytes
operator|=
literal|1
expr_stmt|;
break|break;
case|case
name|OC_DWDISP
case|:
name|kdbprintc
argument_list|(
literal|'*'
argument_list|)
expr_stmt|;
case|case
name|OC_WDISP
case|:
name|nbytes
operator|=
literal|2
expr_stmt|;
break|break;
case|case
name|OC_DLDISP
case|:
name|kdbprintc
argument_list|(
literal|'*'
argument_list|)
expr_stmt|;
case|case
name|OC_LDISP
case|:
name|nbytes
operator|=
literal|4
expr_stmt|;
break|break;
block|}
name|dispaddress
argument_list|(
name|snarfreloc
argument_list|(
name|nbytes
argument_list|)
argument_list|,
name|mode
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_macro
name|dispaddress
argument_list|(
argument|valuep
argument_list|,
argument|mode
argument_list|)
end_macro

begin_decl_stmt
name|numberp
name|valuep
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|mode
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|regnumber
init|=
name|OC_REGEXT
argument_list|(
name|mode
argument_list|)
decl_stmt|;
switch|switch
condition|(
name|OC_AMEXT
argument_list|(
name|mode
argument_list|)
condition|)
block|{
case|case
name|OC_BDISP
case|:
case|case
name|OC_DBDISP
case|:
case|case
name|OC_WDISP
case|:
case|case
name|OC_DWDISP
case|:
case|case
name|OC_LDISP
case|:
case|case
name|OC_DLDISP
case|:
if|if
condition|(
name|regnumber
operator|==
name|R_PC
condition|)
block|{
comment|/* PC offset addressing */
name|valuep
operator|->
name|num_ulong
index|[
literal|0
index|]
operator|+=
name|kdbinkdot
argument_list|(
name|incp
argument_list|)
expr_stmt|;
block|}
block|}
if|if
condition|(
name|regnumber
operator|==
name|R_PC
condition|)
name|kdbpsymoff
argument_list|(
name|valuep
operator|->
name|num_ulong
index|[
literal|0
index|]
argument_list|,
name|type
argument_list|,
operator|&
name|insoutfmt
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
else|else
block|{
comment|/* } */
name|kdbprintf
argument_list|(
name|LPRMODE
argument_list|,
name|valuep
operator|->
name|num_ulong
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
name|kdbprintf
argument_list|(
name|insoutfmt
argument_list|)
expr_stmt|;
name|kdbprintf
argument_list|(
literal|"(%s)"
argument_list|,
name|insregname
argument_list|(
name|regnumber
argument_list|)
argument_list|)
expr_stmt|;
block|}
name|savevar
argument_list|(
operator|(
name|long
operator|)
name|valuep
operator|->
name|num_ulong
index|[
literal|0
index|]
argument_list|)
expr_stmt|;
block|}
end_block

begin_comment
comment|/*  * get a register name  */
end_comment

begin_function
specifier|static
name|char
modifier|*
name|insregname
parameter_list|(
name|regnumber
parameter_list|)
name|int
name|regnumber
decl_stmt|;
block|{
name|char
modifier|*
name|r
decl_stmt|;
name|r
operator|=
name|regname
index|[
name|regnumber
index|]
expr_stmt|;
return|return
operator|(
name|r
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * print out a short literal  */
end_comment

begin_macro
name|shortliteral
argument_list|(
argument|mode
argument_list|,
argument|optype
argument_list|)
end_macro

begin_decl_stmt
name|u_char
name|mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|optype
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|savevar
argument_list|(
operator|(
name|long
operator|)
name|mode
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|A_TYPEXT
argument_list|(
name|optype
argument_list|)
condition|)
block|{
case|case
name|TYPF
case|:
case|case
name|TYPD
case|:
case|case
name|TYPG
case|:
case|case
name|TYPH
case|:
name|kdbprintf
argument_list|(
literal|"$%s"
argument_list|,
name|fltimm
index|[
name|mode
index|]
argument_list|)
expr_stmt|;
break|break;
default|default:
name|kdbprintf
argument_list|(
literal|"$%r"
argument_list|,
name|mode
argument_list|)
expr_stmt|;
break|break;
block|}
block|}
end_block

begin_macro
name|pcimmediate
argument_list|(
argument|mode
argument_list|,
argument|optype
argument_list|)
end_macro

begin_decl_stmt
name|u_char
name|mode
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|optype
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|int
name|nbytes
decl_stmt|;
name|kdbprintc
argument_list|(
literal|'$'
argument_list|)
expr_stmt|;
if|if
condition|(
name|mode
operator|==
name|OC_CONS
argument_list|(
name|OC_DAIREG
argument_list|,
name|R_PC
argument_list|)
condition|)
block|{
comment|/* PC absolute, always 4 bytes*/
name|dispaddress
argument_list|(
name|snarfreloc
argument_list|(
literal|4
argument_list|)
argument_list|,
name|mode
argument_list|)
expr_stmt|;
return|return;
block|}
name|nbytes
operator|=
name|ty_nbyte
index|[
name|A_TYPEXT
argument_list|(
name|optype
argument_list|)
index|]
expr_stmt|;
if|if
condition|(
operator|!
name|ty_NORELOC
index|[
name|A_TYPEXT
argument_list|(
name|optype
argument_list|)
index|]
condition|)
block|{
name|dispaddress
argument_list|(
name|snarfreloc
argument_list|(
name|nbytes
argument_list|)
argument_list|,
name|mode
argument_list|)
expr_stmt|;
return|return;
block|}
name|bignumprint
argument_list|(
name|nbytes
argument_list|,
name|optype
argument_list|)
expr_stmt|;
block|}
end_block

begin_macro
name|bignumprint
argument_list|(
argument|nbytes
argument_list|,
argument|optype
argument_list|)
end_macro

begin_decl_stmt
name|int
name|nbytes
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|u_char
name|optype
decl_stmt|;
end_decl_stmt

begin_block
block|{
name|numberp
name|valuep
decl_stmt|;
name|int
name|leading_zero
init|=
literal|1
decl_stmt|;
specifier|register
name|int
name|bindex
decl_stmt|;
specifier|register
name|int
name|nindex
decl_stmt|;
specifier|register
name|int
name|ch
decl_stmt|;
name|valuep
operator|=
name|snarf
argument_list|(
name|nbytes
argument_list|)
expr_stmt|;
switch|switch
condition|(
name|A_TYPEXT
argument_list|(
name|optype
argument_list|)
condition|)
block|{
case|case
name|TYPF
case|:
name|kdbprintf
argument_list|(
literal|"0f%f"
argument_list|,
name|valuep
operator|->
name|num_num
operator|.
name|numFf_float
operator|.
name|Ff_value
argument_list|)
expr_stmt|;
break|break;
case|case
name|TYPD
case|:
name|kdbprintf
argument_list|(
literal|"0d%f"
argument_list|,
name|valuep
operator|->
name|num_num
operator|.
name|numFd_float
operator|.
name|Fd_value
argument_list|)
expr_stmt|;
break|break;
case|case
name|TYPG
case|:
name|kdbprintf
argument_list|(
literal|"0g::"
argument_list|)
expr_stmt|;
goto|goto
name|qprint
goto|;
case|case
name|TYPH
case|:
name|kdbprintf
argument_list|(
literal|"0h::"
argument_list|)
expr_stmt|;
goto|goto
name|qprint
goto|;
case|case
name|TYPQ
case|:
case|case
name|TYPO
case|:
name|qprint
label|:
for|for
control|(
name|bindex
operator|=
name|nbytes
operator|-
literal|1
init|;
name|bindex
operator|>=
literal|0
condition|;
operator|--
name|bindex
control|)
block|{
for|for
control|(
name|nindex
operator|=
literal|4
init|;
name|nindex
operator|>=
literal|0
condition|;
name|nindex
operator|-=
literal|4
control|)
block|{
name|ch
operator|=
operator|(
name|valuep
operator|->
name|num_uchar
index|[
name|bindex
index|]
operator|>>
name|nindex
operator|)
expr_stmt|;
name|ch
operator|&=
literal|0x0F
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|leading_zero
operator|&=
operator|(
name|ch
operator|==
literal|0
operator|)
operator|)
condition|)
block|{
if|if
condition|(
name|ch
operator|<=
literal|0x09
condition|)
name|kdbprintc
argument_list|(
name|ch
operator|+
literal|'0'
argument_list|)
expr_stmt|;
else|else
name|kdbprintc
argument_list|(
name|ch
operator|-
literal|0x0A
operator|+
literal|'a'
argument_list|)
expr_stmt|;
block|}
block|}
block|}
break|break;
block|}
block|}
end_block

end_unit

