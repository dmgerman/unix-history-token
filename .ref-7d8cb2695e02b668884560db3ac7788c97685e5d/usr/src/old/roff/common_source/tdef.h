begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1991 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.proprietary.c%  *  *	@(#)tdef.h	4.9 (Berkeley) %G%  */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_undef
undef|#
directive|undef
name|CMASK
end_undef

begin_comment
comment|/* XXX */
end_comment

begin_undef
undef|#
directive|undef
name|BIG
end_undef

begin_comment
comment|/* XXX */
end_comment

begin_define
define|#
directive|define
name|MAXPTR
value|(-1)
end_define

begin_comment
comment|/* max value of any pointer variable */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NROFF
end_ifdef

begin_comment
comment|/*NROFF*/
end_comment

begin_define
define|#
directive|define
name|EM
value|t.Em
end_define

begin_define
define|#
directive|define
name|HOR
value|t.Hor
end_define

begin_define
define|#
directive|define
name|VERT
value|t.Vert
end_define

begin_define
define|#
directive|define
name|INCH
value|240
end_define

begin_comment
comment|/*increments per inch*/
end_comment

begin_define
define|#
directive|define
name|SPS
value|INCH/10
end_define

begin_comment
comment|/*space size*/
end_comment

begin_define
define|#
directive|define
name|SS
value|INCH/10
end_define

begin_comment
comment|/* " */
end_comment

begin_define
define|#
directive|define
name|TRAILER
value|0
end_define

begin_define
define|#
directive|define
name|UNPAD
value|0227
end_define

begin_define
define|#
directive|define
name|PO
value|0
end_define

begin_comment
comment|/*page offset*/
end_comment

begin_define
define|#
directive|define
name|ASCII
value|1
end_define

begin_define
define|#
directive|define
name|PTID
value|1
end_define

begin_define
define|#
directive|define
name|LG
value|0
end_define

begin_define
define|#
directive|define
name|DTAB
value|0
end_define

begin_comment
comment|/*set at 8 Ems at init time*/
end_comment

begin_define
define|#
directive|define
name|ICS
value|2*SPS
end_define

begin_define
define|#
directive|define
name|TEMP
value|256
end_define

begin_comment
comment|/*65K*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|NROFF
end_ifndef

begin_comment
comment|/*TROFF*/
end_comment

begin_define
define|#
directive|define
name|INCH
value|432
end_define

begin_comment
comment|/*troff resolution*/
end_comment

begin_define
define|#
directive|define
name|SPS
value|20
end_define

begin_comment
comment|/*space size at 10pt; 1/3 Em*/
end_comment

begin_define
define|#
directive|define
name|SS
value|12
end_define

begin_comment
comment|/*space size in 36ths of an em*/
end_comment

begin_define
define|#
directive|define
name|TRAILER
value|6048
end_define

begin_comment
comment|/*144*14*3 = 14 inches*/
end_comment

begin_define
define|#
directive|define
name|UNPAD
value|027
end_define

begin_define
define|#
directive|define
name|PO
value|416
end_define

begin_comment
comment|/*page offset 26/27ths inch*/
end_comment

begin_define
define|#
directive|define
name|HOR
value|1
end_define

begin_define
define|#
directive|define
name|VERT
value|3
end_define

begin_define
define|#
directive|define
name|EM
value|(6*(pts&077))
end_define

begin_define
define|#
directive|define
name|ASCII
value|0
end_define

begin_define
define|#
directive|define
name|PTID
value|0
end_define

begin_define
define|#
directive|define
name|LG
value|1
end_define

begin_define
define|#
directive|define
name|DTAB
value|(INCH/2)
end_define

begin_define
define|#
directive|define
name|ICS
value|3*SPS
end_define

begin_define
define|#
directive|define
name|TEMP
value|512
end_define

begin_comment
comment|/*128K*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_define
define|#
directive|define
name|NARSP
value|0177
end_define

begin_comment
comment|/*narrow space*/
end_comment

begin_define
define|#
directive|define
name|HNSP
value|0226
end_define

begin_comment
comment|/*half narrow space*/
end_comment

begin_define
define|#
directive|define
name|PS
value|10
end_define

begin_comment
comment|/*default point size*/
end_comment

begin_define
define|#
directive|define
name|FT
value|0
end_define

begin_comment
comment|/*default font position*/
end_comment

begin_define
define|#
directive|define
name|LL
value|65*INCH/10
end_define

begin_comment
comment|/*line length; 39picas=6.5in*/
end_comment

begin_define
define|#
directive|define
name|VS
value|INCH/6
end_define

begin_comment
comment|/*vert space; 12points*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMUNIX
end_ifdef

begin_define
define|#
directive|define
name|NN
value|528
end_define

begin_comment
comment|/*number registers*/
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NN
value|132
end_define

begin_comment
comment|/*number registers*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #define NN 200	*/
end_comment

begin_define
define|#
directive|define
name|NNAMES
value|14
end_define

begin_comment
comment|/*predefined reg names*/
end_comment

begin_define
define|#
directive|define
name|NIF
value|15
end_define

begin_comment
comment|/*if-else nesting*/
end_comment

begin_define
define|#
directive|define
name|NS
value|64
end_define

begin_comment
comment|/*name buffer*/
end_comment

begin_define
define|#
directive|define
name|NTM
value|256
end_define

begin_comment
comment|/*tm buffer*/
end_comment

begin_define
define|#
directive|define
name|NEV
value|3
end_define

begin_comment
comment|/*environments*/
end_comment

begin_define
define|#
directive|define
name|EVLSZ
value|10
end_define

begin_comment
comment|/*size of ev stack*/
end_comment

begin_comment
comment|/* #define EVS 4*256	*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMUNIX
end_ifdef

begin_define
define|#
directive|define
name|NM
value|600
end_define

begin_define
define|#
directive|define
name|EVS
value|6*256
end_define

begin_comment
comment|/*environment size in words*/
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NM
value|300
end_define

begin_comment
comment|/*requests + macros*/
end_comment

begin_define
define|#
directive|define
name|EVS
value|3*256
end_define

begin_comment
comment|/*environment size in words*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|DELTA
value|512
end_define

begin_comment
comment|/*delta core bytes*/
end_comment

begin_define
define|#
directive|define
name|NHYP
value|10
end_define

begin_comment
comment|/*max hyphens per word*/
end_comment

begin_define
define|#
directive|define
name|NHEX
value|128
end_define

begin_comment
comment|/*byte size of exception word list*/
end_comment

begin_define
define|#
directive|define
name|NTAB
value|35
end_define

begin_comment
comment|/*tab stops*/
end_comment

begin_define
define|#
directive|define
name|NSO
value|5
end_define

begin_comment
comment|/*"so" depth*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMUNIX
end_ifdef

begin_define
define|#
directive|define
name|WDSIZE
value|340
end_define

begin_comment
comment|/*word buffer size*/
end_comment

begin_define
define|#
directive|define
name|LNSIZE
value|960
end_define

begin_comment
comment|/*line buffer size*/
end_comment

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WDSIZE
value|170
end_define

begin_comment
comment|/*word buffer size*/
end_comment

begin_define
define|#
directive|define
name|LNSIZE
value|480
end_define

begin_comment
comment|/*line buffer size*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #define LNSIZE 680	*/
end_comment

begin_define
define|#
directive|define
name|NDI
value|5
end_define

begin_comment
comment|/*number of diversions*/
end_comment

begin_define
define|#
directive|define
name|DBL
value|0100000
end_define

begin_comment
comment|/*double size indicator*/
end_comment

begin_define
define|#
directive|define
name|MOT
value|0100000
end_define

begin_comment
comment|/*motion character indicator*/
end_comment

begin_define
define|#
directive|define
name|MOTV
value|0160000
end_define

begin_comment
comment|/*clear for motion part*/
end_comment

begin_define
define|#
directive|define
name|VMOT
value|0040000
end_define

begin_comment
comment|/*vert motion bit*/
end_comment

begin_define
define|#
directive|define
name|NMOT
value|0020000
end_define

begin_comment
comment|/* negative motion indicator*/
end_comment

begin_define
define|#
directive|define
name|MMASK
value|0100000
end_define

begin_comment
comment|/*macro mask indicator*/
end_comment

begin_define
define|#
directive|define
name|CMASK
value|0100377
end_define

begin_define
define|#
directive|define
name|ZBIT
value|0400
end_define

begin_comment
comment|/*zero width char*/
end_comment

begin_define
define|#
directive|define
name|BMASK
value|0377
end_define

begin_define
define|#
directive|define
name|BYTE
value|8
end_define

begin_define
define|#
directive|define
name|IMP
value|004
end_define

begin_comment
comment|/*impossible char*/
end_comment

begin_define
define|#
directive|define
name|FILLER
value|037
end_define

begin_define
define|#
directive|define
name|PRESC
value|026
end_define

begin_define
define|#
directive|define
name|HX
value|0376
end_define

begin_comment
comment|/*High-order part of xlss*/
end_comment

begin_define
define|#
directive|define
name|LX
value|0375
end_define

begin_comment
comment|/*low-order part of xlss*/
end_comment

begin_define
define|#
directive|define
name|CONT
value|025
end_define

begin_define
define|#
directive|define
name|COLON
value|013
end_define

begin_define
define|#
directive|define
name|XPAR
value|030
end_define

begin_define
define|#
directive|define
name|ESC
value|033
end_define

begin_define
define|#
directive|define
name|FLSS
value|031
end_define

begin_define
define|#
directive|define
name|RPT
value|014
end_define

begin_define
define|#
directive|define
name|JREG
value|0374
end_define

begin_define
define|#
directive|define
name|NTRAP
value|20
end_define

begin_comment
comment|/*number of traps*/
end_comment

begin_define
define|#
directive|define
name|NPN
value|20
end_define

begin_comment
comment|/*numbers in "-o"*/
end_comment

begin_define
define|#
directive|define
name|T_PAD
value|0101
end_define

begin_comment
comment|/*cat padding*/
end_comment

begin_define
define|#
directive|define
name|T_INIT
value|0100
end_define

begin_define
define|#
directive|define
name|T_IESC
value|16
end_define

begin_comment
comment|/*initial offset*/
end_comment

begin_define
define|#
directive|define
name|T_STOP
value|0111
end_define

begin_define
define|#
directive|define
name|NPP
value|10
end_define

begin_comment
comment|/*pads per field*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMUNIX
end_ifdef

begin_define
define|#
directive|define
name|FBUFSZ
value|1024
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|FBUFSZ
value|256
end_define

begin_comment
comment|/*field buf size words*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|OBUFSZ
value|8192
end_define

begin_comment
comment|/*bytes*/
end_comment

begin_define
define|#
directive|define
name|IBUFSZ
value|8192
end_define

begin_comment
comment|/*bytes*/
end_comment

begin_define
define|#
directive|define
name|NC
value|256
end_define

begin_comment
comment|/*cbuf size words*/
end_comment

begin_define
define|#
directive|define
name|NOV
value|10
end_define

begin_comment
comment|/*number of overstrike chars*/
end_comment

begin_define
define|#
directive|define
name|TDELIM
value|032
end_define

begin_define
define|#
directive|define
name|LEFT
value|035
end_define

begin_define
define|#
directive|define
name|RIGHT
value|036
end_define

begin_define
define|#
directive|define
name|LEADER
value|001
end_define

begin_define
define|#
directive|define
name|TAB
value|011
end_define

begin_define
define|#
directive|define
name|TMASK
value|037777
end_define

begin_define
define|#
directive|define
name|RTAB
value|0100000
end_define

begin_define
define|#
directive|define
name|CTAB
value|0040000
end_define

begin_define
define|#
directive|define
name|OHC
value|024
end_define

begin_define
define|#
directive|define
name|PAIR
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|(A|(B<<BYTE))
end_define

begin_define
define|#
directive|define
name|BLK
value|128
end_define

begin_comment
comment|/*alloc block words*/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VMUNIX
end_ifdef

begin_define
define|#
directive|define
name|BIG
value|1024
end_define

begin_endif
endif|#
directive|endif
endif|VMUNIX
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|BIG
end_ifdef

begin_typedef
typedef|typedef
name|long
name|filep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NBLIST
value|BIG
end_define

begin_comment
comment|/*allocation , BIG = 256 per 65k*/
end_comment

begin_define
define|#
directive|define
name|BLKBITS
value|7
end_define

begin_comment
comment|/*for BLK=128*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|BIG
end_ifndef

begin_typedef
typedef|typedef
name|unsigned
name|filep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NBLIST
value|TEMP
end_define

begin_comment
comment|/*allocation list, TEMP<=512*/
end_comment

begin_comment
comment|/* BLK*NBLIST<=65536 words, if filep=unsigned */
end_comment

begin_define
define|#
directive|define
name|BLKBITS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

