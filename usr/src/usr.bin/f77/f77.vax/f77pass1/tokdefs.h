begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)tokdefs.h	5.1 (Berkeley) 6/7/85  */
end_comment

begin_define
define|#
directive|define
name|SEOS
value|1
end_define

begin_define
define|#
directive|define
name|SCOMMENT
value|2
end_define

begin_define
define|#
directive|define
name|SLABEL
value|3
end_define

begin_define
define|#
directive|define
name|SUNKNOWN
value|4
end_define

begin_define
define|#
directive|define
name|SHOLLERITH
value|5
end_define

begin_define
define|#
directive|define
name|SSTRING
value|6
end_define

begin_define
define|#
directive|define
name|SICON
value|7
end_define

begin_define
define|#
directive|define
name|SRCON
value|8
end_define

begin_define
define|#
directive|define
name|SDCON
value|9
end_define

begin_define
define|#
directive|define
name|SBITCON
value|10
end_define

begin_define
define|#
directive|define
name|SOCTCON
value|11
end_define

begin_define
define|#
directive|define
name|SHEXCON
value|12
end_define

begin_define
define|#
directive|define
name|STRUE
value|13
end_define

begin_define
define|#
directive|define
name|SFALSE
value|14
end_define

begin_define
define|#
directive|define
name|SNAME
value|15
end_define

begin_define
define|#
directive|define
name|SNAMEEQ
value|16
end_define

begin_define
define|#
directive|define
name|SFIELD
value|17
end_define

begin_define
define|#
directive|define
name|SSCALE
value|18
end_define

begin_define
define|#
directive|define
name|SINCLUDE
value|19
end_define

begin_define
define|#
directive|define
name|SLET
value|20
end_define

begin_define
define|#
directive|define
name|SASSIGN
value|21
end_define

begin_define
define|#
directive|define
name|SAUTOMATIC
value|22
end_define

begin_define
define|#
directive|define
name|SBACKSPACE
value|23
end_define

begin_define
define|#
directive|define
name|SBLOCK
value|24
end_define

begin_define
define|#
directive|define
name|SCALL
value|25
end_define

begin_define
define|#
directive|define
name|SCHARACTER
value|26
end_define

begin_define
define|#
directive|define
name|SCLOSE
value|27
end_define

begin_define
define|#
directive|define
name|SCOMMON
value|28
end_define

begin_define
define|#
directive|define
name|SCOMPLEX
value|29
end_define

begin_define
define|#
directive|define
name|SCONTINUE
value|30
end_define

begin_define
define|#
directive|define
name|SDATA
value|31
end_define

begin_define
define|#
directive|define
name|SDCOMPLEX
value|32
end_define

begin_define
define|#
directive|define
name|SDIMENSION
value|33
end_define

begin_define
define|#
directive|define
name|SDO
value|34
end_define

begin_define
define|#
directive|define
name|SDOUBLE
value|35
end_define

begin_define
define|#
directive|define
name|SELSE
value|36
end_define

begin_define
define|#
directive|define
name|SELSEIF
value|37
end_define

begin_define
define|#
directive|define
name|SEND
value|38
end_define

begin_define
define|#
directive|define
name|SENDFILE
value|39
end_define

begin_define
define|#
directive|define
name|SENDIF
value|40
end_define

begin_define
define|#
directive|define
name|SENTRY
value|41
end_define

begin_define
define|#
directive|define
name|SEQUIV
value|42
end_define

begin_define
define|#
directive|define
name|SEXTERNAL
value|43
end_define

begin_define
define|#
directive|define
name|SFORMAT
value|44
end_define

begin_define
define|#
directive|define
name|SFUNCTION
value|45
end_define

begin_define
define|#
directive|define
name|SGOTO
value|46
end_define

begin_define
define|#
directive|define
name|SASGOTO
value|47
end_define

begin_define
define|#
directive|define
name|SCOMPGOTO
value|48
end_define

begin_define
define|#
directive|define
name|SARITHIF
value|49
end_define

begin_define
define|#
directive|define
name|SLOGIF
value|50
end_define

begin_define
define|#
directive|define
name|SIMPLICIT
value|51
end_define

begin_define
define|#
directive|define
name|SINQUIRE
value|52
end_define

begin_define
define|#
directive|define
name|SINTEGER
value|53
end_define

begin_define
define|#
directive|define
name|SINTRINSIC
value|54
end_define

begin_define
define|#
directive|define
name|SLOGICAL
value|55
end_define

begin_define
define|#
directive|define
name|SNAMELIST
value|56
end_define

begin_define
define|#
directive|define
name|SOPEN
value|57
end_define

begin_define
define|#
directive|define
name|SPARAM
value|58
end_define

begin_define
define|#
directive|define
name|SPAUSE
value|59
end_define

begin_define
define|#
directive|define
name|SPRINT
value|60
end_define

begin_define
define|#
directive|define
name|SPROGRAM
value|61
end_define

begin_define
define|#
directive|define
name|SPUNCH
value|62
end_define

begin_define
define|#
directive|define
name|SREAD
value|63
end_define

begin_define
define|#
directive|define
name|SREAL
value|64
end_define

begin_define
define|#
directive|define
name|SRETURN
value|65
end_define

begin_define
define|#
directive|define
name|SREWIND
value|66
end_define

begin_define
define|#
directive|define
name|SSAVE
value|67
end_define

begin_define
define|#
directive|define
name|SSTATIC
value|68
end_define

begin_define
define|#
directive|define
name|SSTOP
value|69
end_define

begin_define
define|#
directive|define
name|SSUBROUTINE
value|70
end_define

begin_define
define|#
directive|define
name|STHEN
value|71
end_define

begin_define
define|#
directive|define
name|STO
value|72
end_define

begin_define
define|#
directive|define
name|SUNDEFINED
value|73
end_define

begin_define
define|#
directive|define
name|SWRITE
value|74
end_define

begin_define
define|#
directive|define
name|SLPAR
value|75
end_define

begin_define
define|#
directive|define
name|SRPAR
value|76
end_define

begin_define
define|#
directive|define
name|SEQUALS
value|77
end_define

begin_define
define|#
directive|define
name|SCOLON
value|78
end_define

begin_define
define|#
directive|define
name|SCOMMA
value|79
end_define

begin_define
define|#
directive|define
name|SCURRENCY
value|80
end_define

begin_define
define|#
directive|define
name|SPLUS
value|81
end_define

begin_define
define|#
directive|define
name|SMINUS
value|82
end_define

begin_define
define|#
directive|define
name|SSTAR
value|83
end_define

begin_define
define|#
directive|define
name|SSLASH
value|84
end_define

begin_define
define|#
directive|define
name|SPOWER
value|85
end_define

begin_define
define|#
directive|define
name|SCONCAT
value|86
end_define

begin_define
define|#
directive|define
name|SAND
value|87
end_define

begin_define
define|#
directive|define
name|SOR
value|88
end_define

begin_define
define|#
directive|define
name|SNEQV
value|89
end_define

begin_define
define|#
directive|define
name|SEQV
value|90
end_define

begin_define
define|#
directive|define
name|SNOT
value|91
end_define

begin_define
define|#
directive|define
name|SEQ
value|92
end_define

begin_define
define|#
directive|define
name|SLT
value|93
end_define

begin_define
define|#
directive|define
name|SGT
value|94
end_define

begin_define
define|#
directive|define
name|SLE
value|95
end_define

begin_define
define|#
directive|define
name|SGE
value|96
end_define

begin_define
define|#
directive|define
name|SNE
value|97
end_define

end_unit

