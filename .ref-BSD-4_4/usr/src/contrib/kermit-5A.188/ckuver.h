begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* ckuver.h -- C-Kermit UNIX Version heralds */
end_comment

begin_comment
comment|/*   Author: Frank da Cruz (fdc@columbia.edu, FDCCU@CUVMA.BITNET),   Columbia University Center for Computing Activities.   First released January 1985.   Copyright (C) 1985, 1992, Trustees of Columbia University in the City of New   York.  Permission is granted to any individual or institution to use this   software as long as it is not sold for profit.  This copyright notice must be   retained.  This software may not be included in commercial products without   written permission of Columbia University. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKUVER_H
end_ifndef

begin_define
define|#
directive|define
name|CKUVER_H
end_define

begin_comment
comment|/* Arranged more or less alphabetically by compiler symbol */
end_comment

begin_comment
comment|/* Must be included AFTER ckcdeb.h. */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Apple Macintosh"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|A986
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Altos 986 / Xenix 3.0"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* A986 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|aegis
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Apollo DOMAIN/IX 4.2 BSD"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|ATTSV
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Apollo DOMAIN/IX System V"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HERALD
value|" Apollo Aegis"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4  */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* aegis */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AIXRS
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" IBM RS/6000 (AIX 3.x)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIXRS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PS2AIX10
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" IBM PS/2 (AIX 1.x)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PS2AIX10 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AIXPS2
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" IBM PS/2 (AIX 3.x)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIXPS2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AIX370
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|HERALD
end_ifndef

begin_define
define|#
directive|define
name|HERALD
value|" IBM System/370 (AIX 3.x)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AIX370 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATT6300
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" AT&T 6300"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATT6300 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ATT7300
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" AT&T 7300 UNIX PC"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATT7300 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|AUX
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Apple Macintosh AUX"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AUX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD44
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" 4.4 BSD"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD44 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ENCORE
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|BSD43
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Encore Multimax UMAX 4.3"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HERALD
value|" Encore Multimax UMAX 4.2"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ENCORE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD29
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" 2.9 BSD"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD29 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BSD41
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" 4.1 BSD"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD41 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|C70
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" BBN C/70"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* c70 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CIE
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" CIE Systems 680/20 Regulus"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CIE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|COHERENT
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|_I386
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" MWC Coherent 386 4.x"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HERALD
value|" PC/AT MWC Coherent 286 3.x"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I386 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* COHERENT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONVEX9
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Convex/OS"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CONVEX9 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DGUX430
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Data General DG/UX 4.30"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DGUX430 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DGUX540
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Data General DG/UX 5.4"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DGUX540 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|datageneral
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|HERALD
end_ifndef

begin_define
define|#
directive|define
name|HERALD
value|" Data General AOS/VS"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HERALD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* datageneral */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|DELL_SVR4
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Dell System V R4"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* DELL_SVR4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ICL_SVR4
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" ICL System V R4 DRS N/X"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ICL_SVR4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|FT18
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|FT21
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Fortune For:Pro 2.1"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HERALD
value|" Fortune For:Pro 1.8"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FT21 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* FT18 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GEMDOS
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Atari ST GEM 1.0"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* GEMDOS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|I386IX
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SVR3JC
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Interactive UNIX System V/386 R3.2"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HERALD
value|" Interactive Systems Corp 386/ix"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR3JC */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* I386IX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IRIX40
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Silicon Graphics IRIX 4.0"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IRIX40 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ISIII
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Interactive Systems Corp System III"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ISIII */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|IX370
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" IBM IX/370"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* IX370 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HPUX
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" HP 9000 Series HP-UX"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HPUX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MINIX
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Minix"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MINIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MIPS
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" MIPS RISC/OS (System V R3)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MIPS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NEXT
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" NeXT"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* NEXT */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OSF
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" DEC OSF/1 1.0"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OSF */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PTX
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" DYNIX/PTX 1.3"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PTX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PCIX
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" PC/IX"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PCIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sxaE50
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" PFU SX/A V10/L50"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sxaE50 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|PROVX1
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" DEC Professional 300 (Venix 1.0)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROVX1 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RTAIX
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" IBM RT PC (AIX 2.2)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RTAIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RTU
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Masscomp/Concurrent RTU"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* RTU */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sony_news
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" SONY NEWS"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sony_news */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|"SUN Solaris 2.1"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sun */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SOLARIS
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|sun
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" SUN Solaris 2.0"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HERALD
value|" Solaris 2.0"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUN */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SOLARIS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUNOS4
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|SUNOS41
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" SunOS 4.1 (BSD)"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HERALD
value|" SunOS 4.0 (BSD)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNOS41 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUNOS4 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SUN4S5
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HDBUUCP
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" SunOS 4.1 (SVR3)"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HERALD
value|" SunOS 4.0 (SVR3)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HDBUUCP */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SUN4S5 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TOWER1
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" NCR Tower 1632 (OS 1.02)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TOWER1 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|TRS16
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Tandy 16/6000 (Xenix 3.0)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TRS16 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|u3b2
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|HERALD
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SVR3
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" AT&T 3B2 (System V R3)"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HERALD
value|" AT&T 3B2 (System V)"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HERALD */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* u3b2 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ultrix
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" VAX/ULTRIX"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|mips
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" DECstation/ULTRIX"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HERALD
value|" ULTRIX"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* mips */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vax */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ultrix */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OXOS
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Olivetti X/OS"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OXOS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_386BSD
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" 386BSD"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _386BSD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|POSIX
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HERALD
end_ifdef

begin_undef
undef|#
directive|undef
name|HERALD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HERALD */
end_comment

begin_define
define|#
directive|define
name|HERALD
value|" POSIX"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* POSIX */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UTS24
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Amdahl UTS 2.4"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTS24 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UTSV
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Amdahl UTS V"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTSV */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|VXVE
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" CDC VX/VE 5.2.1 System V"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* VXVE */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XENIX
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HERALD
end_ifdef

begin_undef
undef|#
directive|undef
name|HERALD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HERALD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|M_UNIX
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" SCO UNIX/386"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|M_I386
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Xenix/386"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|M_I286
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Xenix/286"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HERALD
value|" Xenix"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M_I286 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M_I386 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M_UNIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* XENIX  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|ZILOG
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Zilog S8000 Zeus 3.21+"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ZILOG */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|UTEK
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" UTek"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* UTEK */
end_comment

begin_comment
comment|/* Catch-alls for anything not defined explicitly above */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HERALD
end_ifndef

begin_ifdef
ifdef|#
directive|ifdef
name|SVR4
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|i386
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" AT&T System V/386 R4"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|AMIX
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" Commodore Amiga System V/m68k R4"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HERALD
value|" AT&T System V R4"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AMIX */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* i386 */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|SVR3
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" AT&T System V R3"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|ATTSV
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" AT&T System III / System V"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|BSD43
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|pdp11
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" PDP-11 2.10 BSD"
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" VAX 4.3 BSD"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HERALD
value|" 4.3 BSD"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vax */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* pdp11 */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|BSD4
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" VAX 4.2 BSD"
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|HERALD
value|" 4.2 BSD"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* vax */
end_comment

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|V7
end_ifdef

begin_define
define|#
directive|define
name|HERALD
value|" UNIX Version 7"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* V7 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BSD43 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ATTSV */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR3 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SVR4 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HERALD */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|OS2
end_ifdef

begin_ifdef
ifdef|#
directive|ifdef
name|HERALD
end_ifdef

begin_undef
undef|#
directive|undef
name|HERALD
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HERALD */
end_comment

begin_define
define|#
directive|define
name|HERALD
value|" OS/2"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* OS/2 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HERALD
end_ifndef

begin_define
define|#
directive|define
name|HERALD
value|" Unknown Version"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* HERALD */
end_comment

begin_comment
comment|/* Hardware type */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|vax
end_ifdef

begin_comment
comment|/* DEC VAX */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"vax"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  vax */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|pdp11
end_ifdef

begin_comment
comment|/* DEC PDP-11 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"pdp11"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* pdp11 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__ALPHA
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"Alpha"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __ALPHA */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__hp9000s800
end_ifdef

begin_comment
comment|/* HP 9000 */
end_comment

begin_define
define|#
directive|define
name|CKCPU
value|"hp9000s800"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __hp9000s800 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__hp9000s500
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"hp9000s500"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __hp9000s500 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__hp9000s300
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"hp9000s300"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __hp9000s300 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__hp9000s200
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"hp9000s200"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __hp9000s200 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|m88000
end_ifdef

begin_comment
comment|/* Motorola 88000 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"mc88000"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* m88000 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__using_M88KBCS
end_ifdef

begin_comment
comment|/* DG symbol for Motorola 88000 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"mc88000"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __using_M88KBCS */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|m88k
end_ifdef

begin_comment
comment|/* Motorola symbol for 88000 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"mc88000"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* m88k */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|mc68040
end_ifdef

begin_comment
comment|/* Motorola 68040 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"mc68040"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* mc68040 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|mc68030
end_ifdef

begin_comment
comment|/* Motorola 68030 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"mc68030"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* mc68030 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|mc68020
end_ifdef

begin_comment
comment|/* Motorola 68020 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"mc68020"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* mc68020 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|mc68010
end_ifdef

begin_comment
comment|/* Motorola 68010 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"mc68010"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* mc68010 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|mc68000
end_ifdef

begin_comment
comment|/* Motorola 68000 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"mc68000"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* mc68000 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|mc68k
end_ifdef

begin_comment
comment|/* Ditto (used by DIAB DS90) */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"mc68000"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* mc68k */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|m68
end_ifdef

begin_comment
comment|/* Ditto */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"mc68000"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* m68 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|m68k
end_ifdef

begin_comment
comment|/* Ditto */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"mc68000"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* m68k */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|i486
end_ifdef

begin_comment
comment|/* Intel 80486 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"i486"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* i80486 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|i386
end_ifdef

begin_comment
comment|/* Intel 80386 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"i386"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* i80386 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|i286
end_ifdef

begin_comment
comment|/* Intel 80286 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"i286"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* i286 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|i186
end_ifdef

begin_comment
comment|/* Intel 80186 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"i186"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* i186 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|M_I386
end_ifdef

begin_comment
comment|/* Intel 80386 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"i386"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M_I386 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_M_I386
end_ifdef

begin_comment
comment|/* Intel 80386 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"i386"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _M_I386 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|M_I286
end_ifdef

begin_comment
comment|/* Intel 80286 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"i286"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M_I286 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|M_I86
end_ifdef

begin_comment
comment|/* Intel 80x86 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"ix86"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* M_I86 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|sparc
end_ifdef

begin_comment
comment|/* SUN SPARC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"sparc"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* sparc */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|mips
end_ifdef

begin_comment
comment|/* MIPS RISC processor */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"mips"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* mips */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|_IBMR2
end_ifdef

begin_comment
comment|/* IBM RS/6000 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_comment
comment|/* (what do they call the chip?) */
end_comment

begin_define
define|#
directive|define
name|CKCPU
value|"rs6000"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* rs6000 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|u3b5
end_ifdef

begin_comment
comment|/* WE32000 MAC-32, AT&T 3Bx */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"u3b5"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* u3b5 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|n3b
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"n3b"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* n3b */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|u3b
end_ifdef

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"u3b"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* u3b */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|n16
end_ifdef

begin_comment
comment|/* Encore Multimax */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"n16"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* n16 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|u370
end_ifdef

begin_comment
comment|/* IBM 370 */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"u370"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* u370 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|MAC
end_ifdef

begin_comment
comment|/* Macintosh catch-all */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_define
define|#
directive|define
name|CKCPU
value|"mc68000"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* MAC */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CKCPU
end_ifndef

begin_comment
comment|/* All others */
end_comment

begin_define
define|#
directive|define
name|CKCPU
value|"unknown"
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKCPU */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CKUVER_H */
end_comment

end_unit

