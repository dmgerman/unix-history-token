begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<X/mit-copyright.h>
end_include

begin_comment
comment|/* $Header: chartable.h,v 10.3 86/02/01 16:06:06 tony Rel $ */
end_comment

begin_define
define|#
directive|define
name|CIGNORE
value|0
end_define

begin_define
define|#
directive|define
name|BUFFER_MODE
value|1
end_define

begin_define
define|#
directive|define
name|CLINEFEED
value|2
end_define

begin_define
define|#
directive|define
name|CRETURN
value|4
end_define

begin_define
define|#
directive|define
name|CPRINTING
value|6
end_define

begin_define
define|#
directive|define
name|FLUSH
value|8
end_define

begin_define
define|#
directive|define
name|CRI
value|10
end_define

begin_define
define|#
directive|define
name|CESC
value|12
end_define

begin_define
define|#
directive|define
name|CCANCEL
value|14
end_define

begin_define
define|#
directive|define
name|CLS1
value|16
end_define

begin_define
define|#
directive|define
name|CLS0
value|18
end_define

begin_define
define|#
directive|define
name|CTEKINIT
value|20
end_define

begin_define
define|#
directive|define
name|CTEKALPH
value|22
end_define

begin_define
define|#
directive|define
name|CCSI
value|24
end_define

begin_define
define|#
directive|define
name|CDCS
value|26
end_define

begin_define
define|#
directive|define
name|CTAB
value|28
end_define

begin_define
define|#
directive|define
name|CFORMFEED
value|30
end_define

begin_define
define|#
directive|define
name|CBACKSPACE
value|32
end_define

begin_define
define|#
directive|define
name|CSS2
value|34
end_define

begin_define
define|#
directive|define
name|CSS3
value|36
end_define

begin_define
define|#
directive|define
name|CIND
value|38
end_define

begin_define
define|#
directive|define
name|CNEL
value|40
end_define

begin_define
define|#
directive|define
name|CBELL
value|42
end_define

begin_comment
comment|/*  * Decode table		  */
end_comment

begin_define
define|#
directive|define
name|ctable
value|(&chartable[1])
end_define

begin_decl_stmt
name|unsigned
name|char
name|chartable
index|[
literal|257
index|]
init|=
block|{
name|FLUSH
block|,
comment|/* EOF code (-1)		*/
name|CIGNORE
block|,
comment|/* NUL				*/
name|CIGNORE
block|,
comment|/* SOH				*/
name|CIGNORE
block|,
comment|/* STX				*/
name|CIGNORE
block|,
comment|/* ETX				*/
name|CIGNORE
block|,
comment|/* EOT				*/
name|CIGNORE
block|,
comment|/* ENQ				*/
name|CIGNORE
block|,
comment|/* ACK				*/
name|CBELL
block|,
comment|/* BEL				*/
name|CBACKSPACE
block|,
comment|/* BS				*/
name|CTAB
block|,
comment|/* HT				*/
name|CLINEFEED
block|,
comment|/* LF				*/
name|CLINEFEED
block|,
comment|/* VT				*/
name|CFORMFEED
block|,
comment|/* FF				*/
name|CRETURN
block|,
comment|/* CR				*/
name|CLS1
block|,
comment|/* SO	(Locking shift 1)	*/
name|CLS0
block|,
comment|/* SI	(Locking shift 0)	*/
name|CIGNORE
block|,
comment|/* DLE				*/
name|CIGNORE
block|,
comment|/* DC1				*/
name|CIGNORE
block|,
comment|/* DC2				*/
name|CIGNORE
block|,
comment|/* DC3				*/
name|CIGNORE
block|,
comment|/* DC4				*/
name|CIGNORE
block|,
comment|/* NAK				*/
name|CIGNORE
block|,
comment|/* SYN				*/
name|CIGNORE
block|,
comment|/* ETB				*/
name|CCANCEL
block|,
comment|/* CAN				*/
name|CIGNORE
block|,
comment|/* EM				*/
name|CCANCEL
block|,
comment|/* SUB				*/
name|CESC
block|,
comment|/* ESC	(ESCAPE introducer)	*/
name|CTEKINIT
block|,
comment|/* FS	(Tek point plot mode)	*/
name|CTEKINIT
block|,
comment|/* GS	(Tek vector plot mode)	*/
name|CTEKINIT
block|,
comment|/* RS	(Tek incr. plot mode)	*/
name|CTEKALPH
block|,
comment|/* US	(Tek alpha mode)	*/
name|CPRINTING
block|,
comment|/* SP				*/
name|CPRINTING
block|,
comment|/* !				*/
name|CPRINTING
block|,
comment|/* "				*/
name|CPRINTING
block|,
comment|/* #				*/
name|CPRINTING
block|,
comment|/* $				*/
name|CPRINTING
block|,
comment|/* %				*/
name|CPRINTING
block|,
comment|/*&				*/
name|CPRINTING
block|,
comment|/* '				*/
name|CPRINTING
block|,
comment|/* (				*/
name|CPRINTING
block|,
comment|/* )				*/
name|CPRINTING
block|,
comment|/* *				*/
name|CPRINTING
block|,
comment|/* +				*/
name|CPRINTING
block|,
comment|/* ,				*/
name|CPRINTING
block|,
comment|/* -				*/
name|CPRINTING
block|,
comment|/* .				*/
name|CPRINTING
block|,
comment|/* /				*/
name|CPRINTING
block|,
comment|/* 0				*/
name|CPRINTING
block|,
comment|/* 1				*/
name|CPRINTING
block|,
comment|/* 2				*/
name|CPRINTING
block|,
comment|/* 3				*/
name|CPRINTING
block|,
comment|/* 4				*/
name|CPRINTING
block|,
comment|/* 5				*/
name|CPRINTING
block|,
comment|/* 6				*/
name|CPRINTING
block|,
comment|/* 7				*/
name|CPRINTING
block|,
comment|/* 8				*/
name|CPRINTING
block|,
comment|/* 9				*/
name|CPRINTING
block|,
comment|/* :				*/
name|CPRINTING
block|,
comment|/* ;				*/
name|CPRINTING
block|,
comment|/*<				*/
name|CPRINTING
block|,
comment|/* =				*/
name|CPRINTING
block|,
comment|/*>				*/
name|CPRINTING
block|,
comment|/* ?				*/
name|CPRINTING
block|,
comment|/* @				*/
name|CPRINTING
block|,
comment|/* A				*/
name|CPRINTING
block|,
comment|/* B				*/
name|CPRINTING
block|,
comment|/* C				*/
name|CPRINTING
block|,
comment|/* D				*/
name|CPRINTING
block|,
comment|/* E				*/
name|CPRINTING
block|,
comment|/* F				*/
name|CPRINTING
block|,
comment|/* G				*/
name|CPRINTING
block|,
comment|/* H				*/
name|CPRINTING
block|,
comment|/* I				*/
name|CPRINTING
block|,
comment|/* J				*/
name|CPRINTING
block|,
comment|/* K				*/
name|CPRINTING
block|,
comment|/* L				*/
name|CPRINTING
block|,
comment|/* M				*/
name|CPRINTING
block|,
comment|/* N				*/
name|CPRINTING
block|,
comment|/* O				*/
name|CPRINTING
block|,
comment|/* P				*/
name|CPRINTING
block|,
comment|/* Q				*/
name|CPRINTING
block|,
comment|/* R				*/
name|CPRINTING
block|,
comment|/* S				*/
name|CPRINTING
block|,
comment|/* T				*/
name|CPRINTING
block|,
comment|/* U				*/
name|CPRINTING
block|,
comment|/* V				*/
name|CPRINTING
block|,
comment|/* W				*/
name|CPRINTING
block|,
comment|/* X				*/
name|CPRINTING
block|,
comment|/* Y				*/
name|CPRINTING
block|,
comment|/* Z				*/
name|CPRINTING
block|,
comment|/* [				*/
name|CPRINTING
block|,
comment|/* \				*/
name|CPRINTING
block|,
comment|/* ]				*/
name|CPRINTING
block|,
comment|/* ^				*/
name|CPRINTING
block|,
comment|/* _				*/
name|CPRINTING
block|,
comment|/* `				*/
name|CPRINTING
block|,
comment|/* a				*/
name|CPRINTING
block|,
comment|/* b				*/
name|CPRINTING
block|,
comment|/* c				*/
name|CPRINTING
block|,
comment|/* d				*/
name|CPRINTING
block|,
comment|/* e				*/
name|CPRINTING
block|,
comment|/* f				*/
name|CPRINTING
block|,
comment|/* g				*/
name|CPRINTING
block|,
comment|/* h				*/
name|CPRINTING
block|,
comment|/* i				*/
name|CPRINTING
block|,
comment|/* j				*/
name|CPRINTING
block|,
comment|/* k				*/
name|CPRINTING
block|,
comment|/* l				*/
name|CPRINTING
block|,
comment|/* m				*/
name|CPRINTING
block|,
comment|/* n				*/
name|CPRINTING
block|,
comment|/* o				*/
name|CPRINTING
block|,
comment|/* p				*/
name|CPRINTING
block|,
comment|/* q				*/
name|CPRINTING
block|,
comment|/* r				*/
name|CPRINTING
block|,
comment|/* s				*/
name|CPRINTING
block|,
comment|/* t				*/
name|CPRINTING
block|,
comment|/* u				*/
name|CPRINTING
block|,
comment|/* v				*/
name|CPRINTING
block|,
comment|/* w				*/
name|CPRINTING
block|,
comment|/* x				*/
name|CPRINTING
block|,
comment|/* y				*/
name|CPRINTING
block|,
comment|/* z				*/
name|CPRINTING
block|,
comment|/* {				*/
name|CPRINTING
block|,
comment|/* |				*/
name|CPRINTING
block|,
comment|/* }				*/
name|CPRINTING
block|,
comment|/* ~				*/
name|CIGNORE
block|,
comment|/* DEL				*/
name|CIGNORE
block|,
comment|/* Reserved.			*/
name|CIGNORE
block|,
comment|/* Reserved.			*/
name|CIGNORE
block|,
comment|/* Reserved.			*/
name|CIGNORE
block|,
comment|/* Reserved.			*/
name|CIND
block|,
comment|/* IND				*/
name|CNEL
block|,
comment|/* NEL				*/
name|CIGNORE
block|,
comment|/* SSA				*/
name|CIGNORE
block|,
comment|/* ESA				*/
name|CIGNORE
block|,
comment|/* HTS				*/
name|CIGNORE
block|,
comment|/* HTJ				*/
name|CIGNORE
block|,
comment|/* VTS				*/
name|CIGNORE
block|,
comment|/* PLD				*/
name|CIGNORE
block|,
comment|/* PLU				*/
name|CRI
block|,
comment|/* RI				*/
name|CSS2
block|,
comment|/* SS2				*/
name|CSS3
block|,
comment|/* SS3				*/
name|CDCS
block|,
comment|/* DCS				*/
name|CIGNORE
block|,
comment|/* PU1				*/
name|CIGNORE
block|,
comment|/* PU2				*/
name|CIGNORE
block|,
comment|/* STS				*/
name|CIGNORE
block|,
comment|/* CCH				*/
name|CIGNORE
block|,
comment|/* MW				*/
name|CIGNORE
block|,
comment|/* SPA				*/
name|CIGNORE
block|,
comment|/* EPA				*/
name|CIGNORE
block|,
comment|/* Reserved			*/
name|CIGNORE
block|,
comment|/* Reserved			*/
name|CIGNORE
block|,
comment|/* Reserved			*/
name|CCSI
block|,
comment|/* CSI				*/
name|CCANCEL
block|,
comment|/* ST				*/
name|CDCS
block|,
comment|/* OSC				*/
name|CDCS
block|,
comment|/* PM				*/
name|CDCS
block|,
comment|/* APC				*/
name|CPRINTING
block|,
comment|/* SP				*/
name|CPRINTING
block|,
comment|/* Inverted !			*/
name|CPRINTING
block|,
comment|/* Cent				*/
name|CPRINTING
block|,
comment|/* Pound Sterling		*/
name|CPRINTING
block|,
comment|/* 				*/
name|CPRINTING
block|,
comment|/* Yen				*/
name|CPRINTING
block|,
comment|/* 				*/
name|CPRINTING
block|,
comment|/* Section sign			*/
name|CPRINTING
block|,
comment|/* Blob				*/
name|CPRINTING
block|,
comment|/* Copyright			*/
name|CPRINTING
block|,
comment|/* Fem. ordinal			*/
name|CPRINTING
block|,
comment|/*<<				*/
name|CPRINTING
block|,
comment|/* 				*/
name|CPRINTING
block|,
comment|/* 				*/
name|CPRINTING
block|,
comment|/* 				*/
name|CPRINTING
block|,
comment|/* 				*/
name|CPRINTING
block|,
comment|/* Degree			*/
name|CPRINTING
block|,
comment|/* +/-				*/
name|CPRINTING
block|,
comment|/* Superscript 2		*/
name|CPRINTING
block|,
comment|/* Superscript 3		*/
name|CPRINTING
block|,
comment|/* 				*/
name|CPRINTING
block|,
comment|/* Micro			*/
name|CPRINTING
block|,
comment|/* Paragraph			*/
name|CPRINTING
block|,
comment|/* Dot				*/
name|CPRINTING
block|,
comment|/* 				*/
name|CPRINTING
block|,
comment|/* Superscript 1		*/
name|CPRINTING
block|,
comment|/* Masc. ordinal		*/
name|CPRINTING
block|,
comment|/*>>				*/
name|CPRINTING
block|,
comment|/* 1/4				*/
name|CPRINTING
block|,
comment|/* 1/2				*/
name|CPRINTING
block|,
comment|/* 				*/
name|CPRINTING
block|,
comment|/* Inverted ?			*/
name|CPRINTING
block|,
comment|/* A grave			*/
name|CPRINTING
block|,
comment|/* A acute			*/
name|CPRINTING
block|,
comment|/* A curcumflex			*/
name|CPRINTING
block|,
comment|/* A tilde			*/
name|CPRINTING
block|,
comment|/* A diaresis			*/
name|CPRINTING
block|,
comment|/* A ring			*/
name|CPRINTING
block|,
comment|/* AE				*/
name|CPRINTING
block|,
comment|/* C cedilla			*/
name|CPRINTING
block|,
comment|/* E grave			*/
name|CPRINTING
block|,
comment|/* E acute			*/
name|CPRINTING
block|,
comment|/* E curcumflex			*/
name|CPRINTING
block|,
comment|/* E diaresis			*/
name|CPRINTING
block|,
comment|/* I grave			*/
name|CPRINTING
block|,
comment|/* I acute			*/
name|CPRINTING
block|,
comment|/* I curcumflex			*/
name|CPRINTING
block|,
comment|/* I diaresis			*/
name|CPRINTING
block|,
comment|/* 				*/
name|CPRINTING
block|,
comment|/* N tilde			*/
name|CPRINTING
block|,
comment|/* O grave			*/
name|CPRINTING
block|,
comment|/* O acute			*/
name|CPRINTING
block|,
comment|/* O circumflex			*/
name|CPRINTING
block|,
comment|/* O tilde			*/
name|CPRINTING
block|,
comment|/* O diaresis			*/
name|CPRINTING
block|,
comment|/* OE				*/
name|CPRINTING
block|,
comment|/* O slash			*/
name|CPRINTING
block|,
comment|/* U grave			*/
name|CPRINTING
block|,
comment|/* U acute			*/
name|CPRINTING
block|,
comment|/* U circumflex			*/
name|CPRINTING
block|,
comment|/* U diaresis			*/
name|CPRINTING
block|,
comment|/* Y diaresis			*/
name|CPRINTING
block|,
comment|/* 				*/
name|CPRINTING
block|,
comment|/* German "s"			*/
name|CPRINTING
block|,
comment|/* a grave			*/
name|CPRINTING
block|,
comment|/* a acute			*/
name|CPRINTING
block|,
comment|/* a curcumflex			*/
name|CPRINTING
block|,
comment|/* a tilde			*/
name|CPRINTING
block|,
comment|/* a diaresis			*/
name|CPRINTING
block|,
comment|/* a ring			*/
name|CPRINTING
block|,
comment|/* ae				*/
name|CPRINTING
block|,
comment|/* c cedilla			*/
name|CPRINTING
block|,
comment|/* e grave			*/
name|CPRINTING
block|,
comment|/* e acute			*/
name|CPRINTING
block|,
comment|/* e curcumflex			*/
name|CPRINTING
block|,
comment|/* e diaresis			*/
name|CPRINTING
block|,
comment|/* i grave			*/
name|CPRINTING
block|,
comment|/* i acute			*/
name|CPRINTING
block|,
comment|/* i circumflex			*/
name|CPRINTING
block|,
comment|/* i diaresis			*/
name|CPRINTING
block|,
comment|/* 				*/
name|CPRINTING
block|,
comment|/* n tilde			*/
name|CPRINTING
block|,
comment|/* o grave			*/
name|CPRINTING
block|,
comment|/* o acute			*/
name|CPRINTING
block|,
comment|/* o curcumflex			*/
name|CPRINTING
block|,
comment|/* o tilde			*/
name|CPRINTING
block|,
comment|/* o diaresis			*/
name|CPRINTING
block|,
comment|/* oe				*/
name|CPRINTING
block|,
comment|/* o slash			*/
name|CPRINTING
block|,
comment|/* u grave			*/
name|CPRINTING
block|,
comment|/* u acute			*/
name|CPRINTING
block|,
comment|/* u circumflex			*/
name|CPRINTING
block|,
comment|/* u diaresis			*/
name|CPRINTING
block|,
comment|/* y diaresis			*/
name|CPRINTING
block|,
comment|/* 				*/
name|CIGNORE
comment|/* Right delete			*/
block|}
decl_stmt|;
end_decl_stmt

end_unit

