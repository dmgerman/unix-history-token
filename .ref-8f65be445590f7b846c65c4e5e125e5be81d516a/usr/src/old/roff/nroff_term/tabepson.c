begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*************************************************************************  * This is 'tabepson.c' for an Epson FX80. Default spacing is elite.	 *  * This represents a combination and very slight modification of two	 *  *  nroff driving tables. Specifically :				 *  *									 *  *     tablpr.c  by UCB Computing Center (the approximation of greek)    *  *									 *  *     tabfx80p.c by Goeke@MIT-Multics.ARPA (Epson print mode switching) *  *	replaces big curly bracket parts with the following:		 *  *									 *  *		PRINT MODE:		  CHARACTER SEQUENCE		 *  *		FX80 set Double Strike 	 	\(lt			 *  *		FX80 cancels D.S.  	 	\(lb			 *  *		FX80 set Condensed 	 	\(rt			 *  *		FX80 cancels Condensed 	 	\(rb			 *  *		FX80 set Pica size 	 	\(lk			 *  *		FX80 set Elite size	 	\(rk			 *  *		FX80 set Proportional 	 	\(bv 			 *  *		FX80 set Expanded Mode 	 	\(lf 			 *  *		FX80 cancel Expanded Mode	\(rf 			 *  *		FX80 underline on 	 	\(lc 			 *  *		FX80 underline off 	 	\(rc 			 *  *									 *  *  --> J. Michael Cherry, 1/18/85  molbio@ucblapis or			 *  *				    ucbvax!molbio!mike			 *  *									 *  *************************************************************************/
end_comment

begin_define
define|#
directive|define
name|INCH
value|240
end_define

begin_struct
struct|struct
block|{
name|int
name|bset
decl_stmt|;
comment|/* terminal driver set          */
name|int
name|breset
decl_stmt|;
comment|/* terminal driver reset        */
name|int
name|Hor
decl_stmt|;
comment|/* horizontal resolution        */
name|int
name|Vert
decl_stmt|;
comment|/* vetical resolution           */
name|int
name|Newline
decl_stmt|;
comment|/* length on one line feed      */
name|int
name|Char
decl_stmt|;
comment|/* character size increment     */
name|int
name|Em
decl_stmt|;
comment|/* em size                      */
name|int
name|Halfline
decl_stmt|;
comment|/* length of half line feed     */
name|int
name|Adj
decl_stmt|;
comment|/* white size increment         */
name|char
modifier|*
name|twinit
decl_stmt|;
comment|/* initialize string to printer */
name|char
modifier|*
name|twrest
decl_stmt|;
comment|/* reset string to printer      */
name|char
modifier|*
name|twnl
decl_stmt|;
comment|/* newline string               */
name|char
modifier|*
name|hlr
decl_stmt|;
comment|/* half-line-feed-reverse       */
name|char
modifier|*
name|hlf
decl_stmt|;
comment|/* half-line-feed-forward       */
name|char
modifier|*
name|flr
decl_stmt|;
comment|/* full-line-feed-reverse       */
name|char
modifier|*
name|bdon
decl_stmt|;
comment|/* bold-on string               */
name|char
modifier|*
name|bdoff
decl_stmt|;
comment|/* bold-off string              */
name|char
modifier|*
name|ploton
decl_stmt|;
comment|/* plot on string               */
name|char
modifier|*
name|plotoff
decl_stmt|;
comment|/* plot off string              */
name|char
modifier|*
name|up
decl_stmt|;
comment|/* these strings move as        */
name|char
modifier|*
name|down
decl_stmt|;
comment|/*     indicated in plot mode   */
name|char
modifier|*
name|right
decl_stmt|;
comment|/*     in best available        */
name|char
modifier|*
name|left
decl_stmt|;
comment|/*     resolution               */
name|char
modifier|*
name|codetab
index|[
literal|256
operator|-
literal|32
index|]
decl_stmt|;
comment|/* see the table                */
name|int
name|zzz
decl_stmt|;
block|}
name|t
init|=
block|{
comment|/*bset*/
literal|0
block|,
comment|/*breset*/
literal|0
block|,
comment|/*Hor*/
name|INCH
operator|/
literal|120
block|,
comment|/* must be consisten with plot increments */
comment|/*Vert*/
name|INCH
operator|/
literal|48
block|,
comment|/* ditto */
comment|/*Newline*/
name|INCH
operator|/
literal|6
block|,
comment|/*Char*/
name|INCH
operator|/
literal|12
block|,
comment|/* the character unit for the code table */
comment|/*Em*/
name|INCH
operator|/
literal|12
block|,
comment|/* the nominal space size */
comment|/*Halfline*/
name|INCH
operator|/
literal|12
block|,
comment|/*Adj*/
name|INCH
operator|/
literal|12
block|,
comment|/* the white caused by a single plot move */
comment|/*twinit*/
literal|"\033M"
block|,
comment|/* invoke elite */
comment|/*twrest*/
literal|"\033@"
block|,
comment|/* reset printer to deflauts */
comment|/*twnl*/
literal|"\n"
block|,
comment|/* newline code        */
comment|/*hlr*/
literal|"\033j\022"
block|,
comment|/*hlf*/
literal|"\033J\022"
block|,
comment|/* forward feed */
comment|/*flr*/
literal|"\033j\044"
block|,
comment|/*bdon*/
literal|"\033G"
block|,
comment|/* Alternate chars.  '\fB' to invoke */
comment|/*bdoff*/
literal|"\033H"
block|,
comment|/* Standard chars. '\fP' to invoke */
comment|/*ploton*/
literal|""
block|,
comment|/*plotoff*/
literal|""
block|,
comment|/*up*/
literal|""
block|,
comment|/*down*/
literal|""
block|,
comment|/*right*/
literal|""
block|,
comment|/*left*/
literal|""
block|,
literal|"\001 "
block|,
comment|/*space*/
literal|"\001!"
block|,
comment|/*!*/
literal|"\001\""
block|,
comment|/*"*/
literal|"\001#"
block|,
comment|/*#*/
literal|"\001$"
block|,
comment|/*$*/
literal|"\001%"
block|,
comment|/*%*/
literal|"\001&"
block|,
comment|/*&*/
literal|"\001'"
block|,
comment|/*' close*/
literal|"\001("
block|,
comment|/*(*/
literal|"\001)"
block|,
comment|/*)*/
literal|"\001*"
block|,
comment|/***/
literal|"\001+"
block|,
comment|/*+*/
literal|"\001,"
block|,
comment|/*,*/
literal|"\001-"
block|,
comment|/*- hyphen*/
literal|"\001."
block|,
comment|/*.*/
literal|"\001/"
block|,
comment|/*/*/
literal|"\2010"
block|,
comment|/*0*/
literal|"\2011"
block|,
comment|/*1*/
literal|"\2012"
block|,
comment|/*2*/
literal|"\2013"
block|,
comment|/*3*/
literal|"\2014"
block|,
comment|/*4*/
literal|"\2015"
block|,
comment|/*5*/
literal|"\2016"
block|,
comment|/*6*/
literal|"\2017"
block|,
comment|/*7*/
literal|"\2018"
block|,
comment|/*8*/
literal|"\2019"
block|,
comment|/*9*/
literal|"\001:"
block|,
comment|/*:*/
literal|"\001;"
block|,
comment|/*;*/
literal|"\001<"
block|,
comment|/*<*/
literal|"\001="
block|,
comment|/*=*/
literal|"\001>"
block|,
comment|/*>*/
literal|"\001?"
block|,
comment|/*?*/
literal|"\001@"
block|,
comment|/*@*/
literal|"\201A"
block|,
comment|/*A*/
literal|"\201B"
block|,
comment|/*B*/
literal|"\201C"
block|,
comment|/*C*/
literal|"\201D"
block|,
comment|/*D*/
literal|"\201E"
block|,
comment|/*E*/
literal|"\201F"
block|,
comment|/*F*/
literal|"\201G"
block|,
comment|/*G*/
literal|"\201H"
block|,
comment|/*H*/
literal|"\201I"
block|,
comment|/*I*/
literal|"\201J"
block|,
comment|/*J*/
literal|"\201K"
block|,
comment|/*K*/
literal|"\201L"
block|,
comment|/*L*/
literal|"\201M"
block|,
comment|/*M*/
literal|"\201N"
block|,
comment|/*N*/
literal|"\201O"
block|,
comment|/*O*/
literal|"\201P"
block|,
comment|/*P*/
literal|"\201Q"
block|,
comment|/*Q*/
literal|"\201R"
block|,
comment|/*R*/
literal|"\201S"
block|,
comment|/*S*/
literal|"\201T"
block|,
comment|/*T*/
literal|"\201U"
block|,
comment|/*U*/
literal|"\201V"
block|,
comment|/*V*/
literal|"\201W"
block|,
comment|/*W*/
literal|"\201X"
block|,
comment|/*X*/
literal|"\201Y"
block|,
comment|/*Y*/
literal|"\201Z"
block|,
comment|/*Z*/
literal|"\001["
block|,
comment|/*[*/
literal|"\001\\"
block|,
comment|/*\*/
literal|"\001]"
block|,
comment|/*]*/
literal|"\001^"
block|,
comment|/*^*/
literal|"\001_"
block|,
comment|/*_ dash*/
literal|"\001`"
block|,
comment|/*` open*/
literal|"\201a"
block|,
comment|/*a*/
literal|"\201b"
block|,
comment|/*b*/
literal|"\201c"
block|,
comment|/*c*/
literal|"\201d"
block|,
comment|/*d*/
literal|"\201e"
block|,
comment|/*e*/
literal|"\201f"
block|,
comment|/*f*/
literal|"\201g"
block|,
comment|/*g*/
literal|"\201h"
block|,
comment|/*h*/
literal|"\201i"
block|,
comment|/*i*/
literal|"\201j"
block|,
comment|/*j*/
literal|"\201k"
block|,
comment|/*k*/
literal|"\201l"
block|,
comment|/*l*/
literal|"\201m"
block|,
comment|/*m*/
literal|"\201n"
block|,
comment|/*n*/
literal|"\201o"
block|,
comment|/*o*/
literal|"\201p"
block|,
comment|/*p*/
literal|"\201q"
block|,
comment|/*q*/
literal|"\201r"
block|,
comment|/*r*/
literal|"\201s"
block|,
comment|/*s*/
literal|"\201t"
block|,
comment|/*t*/
literal|"\201u"
block|,
comment|/*u*/
literal|"\201v"
block|,
comment|/*v*/
literal|"\201w"
block|,
comment|/*w*/
literal|"\201x"
block|,
comment|/*x*/
literal|"\201y"
block|,
comment|/*y*/
literal|"\201z"
block|,
comment|/*z*/
literal|"\001{"
block|,
comment|/*{*/
literal|"\001|"
block|,
comment|/*|*/
literal|"\001}"
block|,
comment|/*}*/
literal|"\001~"
block|,
comment|/*~*/
literal|"\001"
block|,
comment|/* narrow sp */
literal|"\001-"
block|,
comment|/*hyphen*/
literal|"\001\033j\003.\033J\003"
block|,
comment|/*bullet*/
literal|"\002[]"
block|,
comment|/*square*/
literal|"\001-"
block|,
comment|/*3/4 em*/
literal|"\001_"
block|,
comment|/*rule*/
literal|"\0031/4"
block|,
comment|/*1/4*/
literal|"\0031/2"
block|,
comment|/*1/2*/
literal|"\0033/4"
block|,
comment|/*3/4*/
literal|"\001-"
block|,
comment|/*minus*/
literal|"\202fi"
block|,
comment|/*fi*/
literal|"\202fl"
block|,
comment|/*fl*/
literal|"\202ff"
block|,
comment|/*ff*/
literal|"\203ffi"
block|,
comment|/*ffi*/
literal|"\203ffl"
block|,
comment|/*ffl*/
literal|"\001\033j\013o\033J\013"
block|,
comment|/*degree*/
literal|"\001|\b\033j\002-\033J\002"
block|,
comment|/*dagger*/
literal|"\001 "
block|,
comment|/* section*/
literal|"\001'"
block|,
comment|/*foot mark*/
literal|"\001'"
block|,
comment|/*acute accent*/
literal|"\001`"
block|,
comment|/*grave accent*/
literal|"\001_"
block|,
comment|/*underrule*/
literal|"\001/"
block|,
comment|/*slash (longer)*/
literal|"\001\0"
block|,
comment|/*half narrow space => 1/12 em */
literal|"\001 "
block|,
comment|/*unpaddable space*/
literal|"\201o\b("
block|,
comment|/*alpha*/
literal|"\2018\b|"
block|,
comment|/*beta*/
literal|"\201>\b/"
block|,
comment|/*gamma*/
literal|"\201d\b`"
block|,
comment|/*delta*/
literal|"\201C\b-"
block|,
comment|/*epsilon*/
literal|"\000\0"
block|,
comment|/*zeta*/
literal|"\201n"
block|,
comment|/*eta*/
literal|"\201o\b-"
block|,
comment|/*theta*/
literal|"\201i"
block|,
comment|/*iota*/
literal|"\201k"
block|,
comment|/*kappa*/
literal|"\201,\b\\"
block|,
comment|/*lambda*/
literal|"\201u"
block|,
comment|/*mu*/
literal|"\201v"
block|,
comment|/*nu*/
literal|"\000\0"
block|,
comment|/*xi*/
literal|"\201o"
block|,
comment|/*omicron*/
literal|"\202i\b~i\b~"
block|,
comment|/*pi*/
literal|"\201p"
block|,
comment|/*rho*/
literal|"\201o\b~"
block|,
comment|/*sigma*/
literal|"\201i\b~"
block|,
comment|/*tau*/
literal|"\201u"
block|,
comment|/*upsilon*/
literal|"\201o\b|"
block|,
comment|/*phi*/
literal|"\201x"
block|,
comment|/*chi*/
literal|"\201u\b|"
block|,
comment|/*psi*/
literal|"\201w"
block|,
comment|/*omega*/
literal|"\201I\b~"
block|,
comment|/*Gamma*/
literal|"\202/\b_\\\b_"
block|,
comment|/*Delta*/
literal|"\201O\b-"
block|,
comment|/*Theta*/
literal|"\202/\\"
block|,
comment|/*Lambda*/
literal|"\201=\b_"
block|,
comment|/*Xi*/
literal|"\202TT"
block|,
comment|/*Pi*/
literal|"\201>\b_\b~"
block|,
comment|/*Sigma*/
literal|"\000"
block|,
comment|/**/
literal|"\201Y"
block|,
comment|/*Upsilon*/
literal|"\201O\b|"
block|,
comment|/*Phi*/
literal|"\201U\b|"
block|,
comment|/*Psi*/
literal|"\201O\b_"
block|,
comment|/*Omega*/
literal|"\001v\b/"
block|,
comment|/*square root*/
literal|"\000\0"
block|,
comment|/*terminal sigma*/
literal|"\001~"
block|,
comment|/*root en*/
literal|"\001>\b_"
block|,
comment|/*>=*/
literal|"\001<\b_"
block|,
comment|/*<=*/
literal|"\001=\b_"
block|,
comment|/*identically equal*/
literal|"\001-"
block|,
comment|/*equation minus*/
literal|"\001~\b_"
block|,
comment|/*approx =*/
literal|"\001~"
block|,
comment|/*approximates*/
literal|"\001=\b/"
block|,
comment|/*not equal*/
literal|"\002->"
block|,
comment|/*right arrow*/
literal|"\002<-"
block|,
comment|/*left arrow*/
literal|"\001|\b^"
block|,
comment|/*up arrow*/
literal|"\001|\bv"
block|,
comment|/*down arrow*/
literal|"\001="
block|,
comment|/*equation equal*/
literal|"\001x"
block|,
comment|/*multiply*/
literal|"\001:\b-"
block|,
comment|/*divide*/
literal|"\001+\b_"
block|,
comment|/*plus-minus*/
literal|"\002(\b~)\b~"
block|,
comment|/*cup (union)*/
literal|"\002(\b_)\b_"
block|,
comment|/*cap (intersection)*/
literal|"\002(="
block|,
comment|/*subset of*/
literal|"\002=)"
block|,
comment|/*superset of*/
literal|"\002(=\b_"
block|,
comment|/*improper subset*/
literal|"\002=\b_)"
block|,
comment|/*improper superset*/
literal|"\002oo"
block|,
comment|/*infinity*/
literal|"\001o\b`"
block|,
comment|/*partial derivative*/
literal|"\002\\\b~/\b~"
block|,
comment|/*gradient*/
literal|"\000\0"
block|,
comment|/*not*/
literal|"\000\0"
block|,
comment|/*integral sign*/
literal|"\002oc"
block|,
comment|/*proportional to*/
literal|"\001O\b/"
block|,
comment|/*empty set*/
literal|"\001<\b-"
block|,
comment|/*member of*/
literal|"\001+"
block|,
comment|/*equation plus*/
literal|"\003(R)"
block|,
comment|/*registered*/
literal|"\003(C)"
block|,
comment|/*copyright*/
literal|"\001|"
block|,
comment|/*box rule */
literal|"\001c\b/"
block|,
comment|/*cent sign*/
literal|"\001|\b="
block|,
comment|/*dbl dagger*/
literal|"\002=>"
block|,
comment|/*right hand*/
literal|"\002<="
block|,
comment|/*left hand*/
literal|"\001*"
block|,
comment|/*math * */
literal|"\000\0"
block|,
comment|/*bell system sign*/
literal|"\001|"
block|,
comment|/*or (was star)*/
literal|"\001O"
block|,
comment|/*circle*/
literal|"\000\033G"
block|,
comment|/* FX80 set Double Strike */
comment|/* \(lt */
literal|"\000\033H"
block|,
comment|/* FX80 cancels D.S.  */
comment|/* \(lb */
block|}
struct|;
end_struct

end_unit

