begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)OPnames.h	5.1 (Berkeley) 6/5/85  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|PC
end_ifndef

begin_decl_stmt
name|char
modifier|*
name|otext
index|[]
init|=
block|{
literal|0
block|,
literal|" NODUMP"
block|,
literal|" BEG"
block|,
literal|" END"
block|,
literal|" CALL"
block|,
literal|" FCALL"
block|,
literal|" FRTN"
block|,
literal|" FSAV"
block|,
literal|" SDUP2"
block|,
literal|" SDUP4"
block|,
literal|" TRA"
block|,
literal|" TRA4"
block|,
literal|" GOTO"
block|,
literal|" LINO"
block|,
literal|" PUSH"
block|,
literal|0
block|,
literal|" IF"
block|,
literal|" REL2"
block|,
literal|" REL4"
block|,
literal|" REL24"
block|,
literal|" REL42"
block|,
literal|" REL8"
block|,
literal|" RELG"
block|,
literal|" RELT"
block|,
literal|" REL28"
block|,
literal|" REL48"
block|,
literal|" REL82"
block|,
literal|" REL84"
block|,
literal|" AND"
block|,
literal|" OR"
block|,
literal|" NOT"
block|,
literal|" VAS"
block|,
literal|" AS2"
block|,
literal|" AS4"
block|,
literal|" AS24"
block|,
literal|" AS42"
block|,
literal|" AS21"
block|,
literal|" AS41"
block|,
literal|" AS28"
block|,
literal|" AS48"
block|,
literal|" AS8"
block|,
literal|" AS"
block|,
literal|" INX2P2"
block|,
literal|" INX4P2"
block|,
literal|" INX2"
block|,
literal|" INX4"
block|,
literal|" OFF"
block|,
literal|" NIL"
block|,
literal|" ADD2"
block|,
literal|" ADD4"
block|,
literal|" ADD24"
block|,
literal|" ADD42"
block|,
literal|" ADD28"
block|,
literal|" ADD48"
block|,
literal|" ADD82"
block|,
literal|" ADD84"
block|,
literal|" SUB2"
block|,
literal|" SUB4"
block|,
literal|" SUB24"
block|,
literal|" SUB42"
block|,
literal|" SUB28"
block|,
literal|" SUB48"
block|,
literal|" SUB82"
block|,
literal|" SUB84"
block|,
literal|" MUL2"
block|,
literal|" MUL4"
block|,
literal|" MUL24"
block|,
literal|" MUL42"
block|,
literal|" MUL28"
block|,
literal|" MUL48"
block|,
literal|" MUL82"
block|,
literal|" MUL84"
block|,
literal|" ABS2"
block|,
literal|" ABS4"
block|,
literal|" ABS8"
block|,
literal|0
block|,
literal|" NEG2"
block|,
literal|" NEG4"
block|,
literal|" NEG8"
block|,
literal|0
block|,
literal|" DIV2"
block|,
literal|" DIV4"
block|,
literal|" DIV24"
block|,
literal|" DIV42"
block|,
literal|" MOD2"
block|,
literal|" MOD4"
block|,
literal|" MOD24"
block|,
literal|" MOD42"
block|,
literal|" ADD8"
block|,
literal|" SUB8"
block|,
literal|" MUL8"
block|,
literal|" DVD8"
block|,
literal|" STOI"
block|,
literal|" STOD"
block|,
literal|" ITOD"
block|,
literal|" ITOS"
block|,
literal|" DVD2"
block|,
literal|" DVD4"
block|,
literal|" DVD24"
block|,
literal|" DVD42"
block|,
literal|" DVD28"
block|,
literal|" DVD48"
block|,
literal|" DVD82"
block|,
literal|" DVD84"
block|,
literal|" RV1"
block|,
literal|" RV14"
block|,
literal|" RV2"
block|,
literal|" RV24"
block|,
literal|" RV4"
block|,
literal|" RV8"
block|,
literal|" RV"
block|,
literal|" LV"
block|,
literal|" LRV1"
block|,
literal|" LRV14"
block|,
literal|" LRV2"
block|,
literal|" LRV24"
block|,
literal|" LRV4"
block|,
literal|" LRV8"
block|,
literal|" LRV"
block|,
literal|" LLV"
block|,
literal|" IND1"
block|,
literal|" IND14"
block|,
literal|" IND2"
block|,
literal|" IND24"
block|,
literal|" IND4"
block|,
literal|" IND8"
block|,
literal|" IND"
block|,
literal|0
block|,
literal|" CON1"
block|,
literal|" CON14"
block|,
literal|" CON2"
block|,
literal|" CON24"
block|,
literal|" CON4"
block|,
literal|" CON8"
block|,
literal|" CON"
block|,
literal|" LVCON"
block|,
literal|" RANG2"
block|,
literal|" RANG42"
block|,
literal|" RSNG2"
block|,
literal|" RSNG42"
block|,
literal|" RANG4"
block|,
literal|" RANG24"
block|,
literal|" RSNG4"
block|,
literal|" RSNG24"
block|,
literal|" STLIM"
block|,
literal|" LLIMIT"
block|,
literal|" BUFF"
block|,
literal|" HALT"
block|,
literal|" VINX2"
block|,
literal|" VINX24"
block|,
literal|" VINX42"
block|,
literal|" VINX4"
block|,
literal|"*ORD2"
block|,
literal|"*CONG"
block|,
literal|"*CONC"
block|,
literal|"*CONC4"
block|,
literal|"*ABORT"
block|,
literal|"*BPT"
block|,
literal|" PXPBUF"
block|,
literal|" COUNT"
block|,
literal|" CASE1OP"
block|,
literal|" CASE2OP"
block|,
literal|" CASE4OP"
block|,
literal|"*CASEBEG"
block|,
literal|"*CASE1"
block|,
literal|"*CASE2"
block|,
literal|"*CASE4"
block|,
literal|"*CASEEND"
block|,
literal|" ADDT"
block|,
literal|" SUBT"
block|,
literal|" MULT"
block|,
literal|" INCT"
block|,
literal|" CTTOT"
block|,
literal|" CARD"
block|,
literal|" IN"
block|,
literal|" ASRT"
block|,
literal|" FOR1U"
block|,
literal|" FOR2U"
block|,
literal|" FOR4U"
block|,
literal|" FOR1D"
block|,
literal|" FOR2D"
block|,
literal|" FOR4D"
block|,
literal|0
block|,
literal|0
block|,
literal|" READE"
block|,
literal|" READ4"
block|,
literal|" READC"
block|,
literal|" READ8"
block|,
literal|" READLN"
block|,
literal|" EOF"
block|,
literal|" EOLN"
block|,
literal|0
block|,
literal|" WRITEC"
block|,
literal|" WRITES"
block|,
literal|" WRITEF"
block|,
literal|" WRITLN"
block|,
literal|" PAGE"
block|,
literal|" NAM"
block|,
literal|" MAX"
block|,
literal|" MIN"
block|,
literal|" UNIT"
block|,
literal|" UNITINP"
block|,
literal|" UNITOUT"
block|,
literal|" MESSAGE"
block|,
literal|" GET"
block|,
literal|" PUT"
block|,
literal|" FNIL"
block|,
literal|0
block|,
literal|" DEFNAME"
block|,
literal|" RESET"
block|,
literal|" REWRITE"
block|,
literal|" FILE"
block|,
literal|" REMOVE"
block|,
literal|" FLUSH"
block|,
literal|0
block|,
literal|0
block|,
literal|" PACK"
block|,
literal|" UNPACK"
block|,
literal|" NEW"
block|,
literal|" DISPOSE"
block|,
literal|" DFDISP"
block|,
literal|" ARGC"
block|,
literal|" ARGV"
block|,
literal|0
block|,
literal|" CLCK"
block|,
literal|" WCLCK"
block|,
literal|" SCLCK"
block|,
literal|" DATE"
block|,
literal|" TIME"
block|,
literal|" UNDEF"
block|,
literal|0
block|,
literal|0
block|,
literal|" ATAN"
block|,
literal|" COS"
block|,
literal|" EXP"
block|,
literal|" LN"
block|,
literal|" SIN"
block|,
literal|" SQRT"
block|,
literal|" CHR2"
block|,
literal|" CHR4"
block|,
literal|" ODD2"
block|,
literal|" ODD4"
block|,
literal|" PRED2"
block|,
literal|" PRED4"
block|,
literal|" PRED24"
block|,
literal|" SUCC2"
block|,
literal|" SUCC4"
block|,
literal|" SUCC24"
block|,
literal|" SEED"
block|,
literal|" RANDOM"
block|,
literal|" EXPO"
block|,
literal|" SQR2"
block|,
literal|" SQR4"
block|,
literal|" SQR8"
block|,
literal|" ROUND"
block|,
literal|" TRUNC"
block|}
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

end_unit

