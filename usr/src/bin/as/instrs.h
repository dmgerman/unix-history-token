begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)instrs.h	5.1 (Berkeley) 4/30/85  */
end_comment

begin_comment
comment|/*  *	Argument data types  *  *	If you change these definitions, you must also change the tables  *	in assizetab.c  */
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
comment|/*  *	Constructors and extractors for argument access kinds and types  */
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
comment|/*  *	Construction of TYPX and ACCX, to make the instrs table  *	easy to use and read.  */
end_comment

begin_comment
comment|/*  *	For real memory address  */
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
comment|/*  *	For real memory addresses, or register addresses [sic]  *  *	CHEAT! we just call these read access, since  *	registers are allowed. All field instruction, except insv,  *	are are read access fields.  */
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
comment|/*  *	For branch displacement  */
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
comment|/*  *	For modification  */
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
comment|/*  *	For reading  */
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
comment|/*  *	For writing  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|INSTTAB
end_ifndef

begin_comment
comment|/*  *	Define what the entries in the table look like.  *	This is only used for adb and sdb; not for as.  */
end_comment

begin_define
define|#
directive|define
name|INSTTAB
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
name|insttab
index|[]
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
value|{name,eopcode,popdcode,nargs,a1,a2,a3,a4,a5,a6}
end_define

begin_endif
endif|#
directive|endif
endif|INSTTAB
end_endif

begin_comment
comment|/*  *	Definitions for the escape bytes  */
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

end_unit

