begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<signal.h>
end_include

begin_define
define|#
directive|define
name|MAXPTR
value|(char *)-1
end_define

begin_comment
comment|/* max value of any pointer variable */
end_comment

begin_comment
comment|/* likely to be machine-dependent */
end_comment

begin_comment
comment|/* starting values for typesetting parameters: */
end_comment

begin_define
define|#
directive|define
name|PS
value|10
end_define

begin_comment
comment|/* default point size */
end_comment

begin_define
define|#
directive|define
name|FT
value|1
end_define

begin_comment
comment|/* default font position */
end_comment

begin_define
define|#
directive|define
name|ST
value|1
end_define

begin_comment
comment|/* default stipple */
end_comment

begin_define
define|#
directive|define
name|LL
value|(unsigned) 65*INCH/10
end_define

begin_comment
comment|/* line length; 39picas=6.5in */
end_comment

begin_define
define|#
directive|define
name|VS
value|((12*INCH)/72)
end_define

begin_comment
comment|/* initial vert space */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|NROFF
end_ifdef

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
comment|/* increments per inch */
end_comment

begin_define
define|#
directive|define
name|SPS
value|INCH/10
end_define

begin_comment
comment|/* space size */
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
comment|/* page offset */
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
comment|/* set at 8 Ems at init time */
end_comment

begin_define
define|#
directive|define
name|ICS
value|2*SPS
end_define

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
comment|/* TROFF */
end_comment

begin_comment
comment|/* Inch is set by ptinit() when troff started. 	/* all derived values set then too 	*/
end_comment

begin_define
define|#
directive|define
name|INCH
value|Inch
end_define

begin_comment
comment|/* troff resolution -- number of goobies/inch  */
end_comment

begin_define
define|#
directive|define
name|POINT
value|(INCH/72)
end_define

begin_comment
comment|/* goobies per point (1/72 inch) */
end_comment

begin_define
define|#
directive|define
name|HOR
value|Hor
end_define

begin_comment
comment|/* horizontal resolution in goobies */
end_comment

begin_define
define|#
directive|define
name|VERT
value|Vert
end_define

begin_comment
comment|/* vertical resolution in goobies */
end_comment

begin_define
define|#
directive|define
name|SPS
value|(EM/3)
end_define

begin_comment
comment|/* space size  */
end_comment

begin_define
define|#
directive|define
name|SS
value|12
end_define

begin_comment
comment|/* space size in 36ths of an em */
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
value|(INCH - INCH/27)
end_define

begin_comment
comment|/* page offset 26/27ths inch */
end_comment

begin_comment
comment|/* #	define	EM	(POINT * pts) */
end_comment

begin_define
define|#
directive|define
name|EM
value|(((long) INCH * pts + 36) / 72)
end_define

begin_comment
comment|/* don't lose significance */
end_comment

begin_define
define|#
directive|define
name|EMPTS
parameter_list|(
name|pts
parameter_list|)
value|(((long) INCH * (pts) + 36) / 72)
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
value|1
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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* These "characters" are used to encode various internal functions /* Some make use of the fact that most ascii characters between /* 0 and 040 don't have any graphic or other function. /* The few that do have a purpose (e.g., \n, \b, \t, ... /* are avoided by the ad hoc choices here. /* See ifilt[] in n1.c for others -- 1, 2, 3, 5, 6, 7, 010, 011, 012  */
end_comment

begin_define
define|#
directive|define
name|LEADER
value|001
end_define

begin_define
define|#
directive|define
name|IMP
value|004
end_define

begin_comment
comment|/* impossible char; glues things together */
end_comment

begin_define
define|#
directive|define
name|TAB
value|011
end_define

begin_define
define|#
directive|define
name|RPT
value|014
end_define

begin_comment
comment|/* next character is to be repeated many times */
end_comment

begin_define
define|#
directive|define
name|CHARHT
value|015
end_define

begin_comment
comment|/* size field sets character height */
end_comment

begin_define
define|#
directive|define
name|SLANT
value|016
end_define

begin_comment
comment|/* size field sets amount of slant */
end_comment

begin_define
define|#
directive|define
name|DRAWFCN
value|017
end_define

begin_comment
comment|/* next several chars describe arb drawing fcn */
end_comment

begin_comment
comment|/* style: 's' m */
end_comment

begin_comment
comment|/* thickness: 't' w */
end_comment

begin_comment
comment|/* line: 'l' dx dy char */
end_comment

begin_comment
comment|/* circle: 'c' r */
end_comment

begin_comment
comment|/* ellipse: 'e' rx ry */
end_comment

begin_comment
comment|/* arc: 'a' dx dy r */
end_comment

begin_comment
comment|/* wiggly line '~' x y x y ... */
end_comment

begin_comment
comment|/*	or     'g' x y x y ... */
end_comment

begin_define
define|#
directive|define
name|DRAWTHICK
value|'t'
end_define

begin_define
define|#
directive|define
name|DRAWSTYLE
value|'s'
end_define

begin_define
define|#
directive|define
name|DRAWLINE
value|'l'
end_define

begin_define
define|#
directive|define
name|DRAWCIRCLE
value|'c'
end_define

begin_comment
comment|/* circle */
end_comment

begin_define
define|#
directive|define
name|DRAWELLIPSE
value|'e'
end_define

begin_define
define|#
directive|define
name|DRAWARC
value|'a'
end_define

begin_comment
comment|/* arbitrary arc */
end_comment

begin_define
define|#
directive|define
name|DRAWCURVE
value|'g'
end_define

begin_comment
comment|/* gremlin spline */
end_comment

begin_define
define|#
directive|define
name|DRAWWIG
value|'~'
end_define

begin_comment
comment|/* wiggly line with spline */
end_comment

begin_define
define|#
directive|define
name|DRAWPOLY
value|'p'
end_define

begin_comment
comment|/* polygon with stipples */
end_comment

begin_define
define|#
directive|define
name|DRAWUBPOLY
value|'P'
end_define

begin_comment
comment|/* polygon, stipples, no border */
end_comment

begin_define
define|#
directive|define
name|LEFT
value|020
end_define

begin_comment
comment|/* \{ */
end_comment

begin_define
define|#
directive|define
name|RIGHT
value|021
end_define

begin_comment
comment|/* \} */
end_comment

begin_define
define|#
directive|define
name|FILLER
value|022
end_define

begin_comment
comment|/* \& and similar purposes */
end_comment

begin_define
define|#
directive|define
name|OHC
value|024
end_define

begin_comment
comment|/* optional hyphenation character \% */
end_comment

begin_define
define|#
directive|define
name|CONT
value|025
end_define

begin_comment
comment|/* \c character */
end_comment

begin_define
define|#
directive|define
name|PRESC
value|026
end_define

begin_comment
comment|/* printable escape */
end_comment

begin_define
define|#
directive|define
name|XPAR
value|030
end_define

begin_comment
comment|/* transparent mode indicator */
end_comment

begin_define
define|#
directive|define
name|FLSS
value|031
end_define

begin_define
define|#
directive|define
name|WORDSP
value|032
end_define

begin_comment
comment|/* paddable word space */
end_comment

begin_define
define|#
directive|define
name|ESC
value|033
end_define

begin_comment
comment|/* there are several tests (using iscontrol()) 	/* that rely on these having 034 true. 	*/
end_comment

begin_define
define|#
directive|define
name|iscontrol
parameter_list|(
name|n
parameter_list|)
value|(n>=034&& n<=037)
end_define

begin_comment
comment|/* used to test the next two */
end_comment

begin_define
define|#
directive|define
name|HX
value|035
end_define

begin_comment
comment|/* next character is value of \x'...' */
end_comment

begin_define
define|#
directive|define
name|FONTPOS
value|036
end_define

begin_comment
comment|/* position of font \f(XX encoded in top */
end_comment

begin_define
define|#
directive|define
name|FONTNAME
value|037
end_define

begin_comment
comment|/* name of font in \f(XX in top */
end_comment

begin_comment
comment|/* have to appear in this order */
end_comment

begin_define
define|#
directive|define
name|HYPHEN
value|c_hyphen
end_define

begin_define
define|#
directive|define
name|EMDASH
value|c_emdash
end_define

begin_comment
comment|/* \(em */
end_comment

begin_define
define|#
directive|define
name|RULE
value|c_rule
end_define

begin_comment
comment|/* \(ru */
end_comment

begin_define
define|#
directive|define
name|MINUS
value|c_minus
end_define

begin_comment
comment|/* minus sign on current font */
end_comment

begin_define
define|#
directive|define
name|NARSP
value|c_narsp
end_define

begin_comment
comment|/* narrow space \|: fake character */
end_comment

begin_define
define|#
directive|define
name|HNARSP
value|c_hnarsp
end_define

begin_comment
comment|/* half narrow space \^: fake character */
end_comment

begin_define
define|#
directive|define
name|LIG_FI
value|c_fi
end_define

begin_comment
comment|/* \(ff */
end_comment

begin_define
define|#
directive|define
name|LIG_FL
value|c_fl
end_define

begin_comment
comment|/* \(fl */
end_comment

begin_define
define|#
directive|define
name|LIG_FF
value|c_ff
end_define

begin_comment
comment|/* \(ff */
end_comment

begin_define
define|#
directive|define
name|LIG_FFI
value|c_ffi
end_define

begin_comment
comment|/* \(Fi */
end_comment

begin_define
define|#
directive|define
name|LIG_FFL
value|c_ffl
end_define

begin_comment
comment|/* \(Fl */
end_comment

begin_define
define|#
directive|define
name|ACUTE
value|c_acute
end_define

begin_comment
comment|/* acute accent \(aa */
end_comment

begin_define
define|#
directive|define
name|GRAVE
value|c_grave
end_define

begin_comment
comment|/* grave accent \(ga */
end_comment

begin_define
define|#
directive|define
name|UNDERLINE
value|c_under
end_define

begin_comment
comment|/* \(ul */
end_comment

begin_define
define|#
directive|define
name|ROOTEN
value|c_rooten
end_define

begin_comment
comment|/* root en \(rn */
end_comment

begin_define
define|#
directive|define
name|BOXRULE
value|c_boxrule
end_define

begin_comment
comment|/* box rule \(br */
end_comment

begin_define
define|#
directive|define
name|LEFTHAND
value|c_lefthand
end_define

begin_comment
comment|/* array sizes, and similar limits: */
end_comment

begin_define
define|#
directive|define
name|NFONT
value|60
end_define

begin_comment
comment|/* maximum number of fonts (including specials) */
end_comment

begin_define
define|#
directive|define
name|EXTRAFONT
value|500
end_define

begin_comment
comment|/* extra space for swapping a font */
end_comment

begin_define
define|#
directive|define
name|NN
value|300
end_define

begin_comment
comment|/* number registers */
end_comment

begin_define
define|#
directive|define
name|NNAMES
value|15
end_define

begin_comment
comment|/* predefined reg names */
end_comment

begin_define
define|#
directive|define
name|NIF
value|15
end_define

begin_comment
comment|/* if-else nesting */
end_comment

begin_define
define|#
directive|define
name|NS
value|64
end_define

begin_comment
comment|/* name buffer */
end_comment

begin_define
define|#
directive|define
name|NTM
value|256
end_define

begin_comment
comment|/* tm buffer */
end_comment

begin_define
define|#
directive|define
name|NEV
value|3
end_define

begin_comment
comment|/* environments */
end_comment

begin_define
define|#
directive|define
name|EVLSZ
value|10
end_define

begin_comment
comment|/* size of ev stack */
end_comment

begin_define
define|#
directive|define
name|DSIZE
value|512
end_define

begin_comment
comment|/* disk sector size in chars */
end_comment

begin_comment
comment|/* the following defines the size of the infamous environment block.    this macro is guaranteed to blow older C preprocessors out of the    water.  Any additions to ni.c between "block" and the end of the    data space affects this macro. */
end_comment

begin_define
define|#
directive|define
name|EVUSED
define|\
value|(61 * sizeof(int)
comment|/* integers in env block */
value|\ 		+ 4 * sizeof(tchar)
comment|/* tchars in env block */
value|\ 		+ 5 * sizeof(tchar *)
comment|/* tchar pointers in env block */
value|\ 		+ NHYP * sizeof(tchar *)
comment|/* hytab */
value|\ 		+ NTAB * sizeof(int)
comment|/* tabtab */
value|\ 		+ (LNSIZE+WDSIZE) * sizeof(tchar))
end_define

begin_comment
comment|/* line+word */
end_comment

begin_define
define|#
directive|define
name|EVSPARE
value|DSIZE - EVUSED % DSIZE
end_define

begin_comment
comment|/* number of leftover chars */
end_comment

begin_define
define|#
directive|define
name|EVS
value|(EVUSED + EVSPARE)
end_define

begin_comment
comment|/* should be a multiple of DSIZE */
end_comment

begin_define
define|#
directive|define
name|NM
value|500
end_define

begin_comment
comment|/* requests + macros */
end_comment

begin_define
define|#
directive|define
name|DELTA
value|1024
end_define

begin_comment
comment|/* delta core bytes */
end_comment

begin_define
define|#
directive|define
name|NHYP
value|10
end_define

begin_comment
comment|/* max hyphens per word */
end_comment

begin_define
define|#
directive|define
name|NHEX
value|128
end_define

begin_comment
comment|/* byte size of exception word list */
end_comment

begin_define
define|#
directive|define
name|NTAB
value|35
end_define

begin_comment
comment|/* tab stops */
end_comment

begin_define
define|#
directive|define
name|NSO
value|5
end_define

begin_comment
comment|/* "so" depth */
end_comment

begin_define
define|#
directive|define
name|WDSIZE
value|270
end_define

begin_comment
comment|/* word buffer size */
end_comment

begin_define
define|#
directive|define
name|LNSIZE
value|680
end_define

begin_comment
comment|/* line buffer size */
end_comment

begin_define
define|#
directive|define
name|NDI
value|5
end_define

begin_comment
comment|/* number of diversions */
end_comment

begin_define
define|#
directive|define
name|NTRTAB
value|350
end_define

begin_comment
comment|/* number of items in trtab[] */
end_comment

begin_define
define|#
directive|define
name|NTRAP
value|20
end_define

begin_comment
comment|/* number of traps */
end_comment

begin_define
define|#
directive|define
name|NPN
value|20
end_define

begin_comment
comment|/* numbers in "-o" */
end_comment

begin_define
define|#
directive|define
name|FBUFSZ
value|256
end_define

begin_comment
comment|/* field buf size words */
end_comment

begin_define
define|#
directive|define
name|OBUFSZ
value|512
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|IBUFSZ
value|512
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|NC
value|256
end_define

begin_comment
comment|/* cbuf size words */
end_comment

begin_define
define|#
directive|define
name|NOV
value|10
end_define

begin_comment
comment|/* number of overstrike chars */
end_comment

begin_define
define|#
directive|define
name|NPP
value|10
end_define

begin_comment
comment|/* pads per field */
end_comment

begin_comment
comment|/* 	Internal character representation: 	Internally, every character is carried around as 	a 32 bit cookie, called a "tchar" (typedef long). 	Bits are numbered 31..0 from left to right. 	If bit 15 is 1, the character is motion, with 		if bit 16 it's vertical motion 		if bit 17 it's negative motion 	If bit 15 is 0, the character is a real character. 		if bit 31	zero motion 		bits 30..24	size 		bits 23..16	font */
end_comment

begin_comment
comment|/* in the following, "L" should really be a tchar, but ... */
end_comment

begin_define
define|#
directive|define
name|MOT
value|(unsigned short)(01<<15)
end_define

begin_comment
comment|/* motion character indicator */
end_comment

begin_define
define|#
directive|define
name|MOTV
value|(07L<<15)
end_define

begin_comment
comment|/* clear for motion part */
end_comment

begin_define
define|#
directive|define
name|VMOT
value|(01L<<16)
end_define

begin_comment
comment|/* vert motion bit */
end_comment

begin_define
define|#
directive|define
name|NMOT
value|(01L<<17)
end_define

begin_comment
comment|/* negative motion indicator*/
end_comment

begin_define
define|#
directive|define
name|MAXMOT
value|32767
end_define

begin_comment
comment|/* bad way to write this!!! */
end_comment

begin_define
define|#
directive|define
name|ismot
parameter_list|(
name|n
parameter_list|)
value|((unsigned short)(n)& MOT)
end_define

begin_comment
comment|/* (short) is a cheap mask */
end_comment

begin_define
define|#
directive|define
name|isvmot
parameter_list|(
name|n
parameter_list|)
value|((n)& VMOT)
end_define

begin_comment
comment|/* must have tested MOT previously */
end_comment

begin_define
define|#
directive|define
name|isnmot
parameter_list|(
name|n
parameter_list|)
value|((n)& NMOT)
end_define

begin_comment
comment|/* ditto */
end_comment

begin_define
define|#
directive|define
name|absmot
parameter_list|(
name|n
parameter_list|)
value|((unsigned short)(n)& ~MOT)
end_define

begin_comment
comment|/* (short) is cheap mask */
end_comment

begin_define
define|#
directive|define
name|ZBIT
value|(01L<< 31)
end_define

begin_comment
comment|/* zero width char */
end_comment

begin_define
define|#
directive|define
name|iszbit
parameter_list|(
name|n
parameter_list|)
value|((n)& ZBIT)
end_define

begin_define
define|#
directive|define
name|SMASK
value|(0177L<< 24)
end_define

begin_define
define|#
directive|define
name|FMASK
value|(0377L<< 16)
end_define

begin_define
define|#
directive|define
name|SFMASK
value|(SMASK|FMASK)
end_define

begin_comment
comment|/* size and font in a tchar */
end_comment

begin_define
define|#
directive|define
name|CMASK
value|~MOT
end_define

begin_comment
comment|/* clears MOT */
end_comment

begin_define
define|#
directive|define
name|CMASKL
value|077777L
end_define

begin_define
define|#
directive|define
name|sbits
parameter_list|(
name|n
parameter_list|)
value|((unsigned short)((n)>> 24)& 0177)
end_define

begin_define
define|#
directive|define
name|fbits
parameter_list|(
name|n
parameter_list|)
value|((unsigned short)((n)>> 16)& 0377)
end_define

begin_define
define|#
directive|define
name|sfbits
parameter_list|(
name|n
parameter_list|)
value|((unsigned short)(((n)& SFMASK)>> 16))
end_define

begin_define
define|#
directive|define
name|cbits
parameter_list|(
name|n
parameter_list|)
value|(unsigned short)(n)
end_define

begin_comment
comment|/* isolate bottom 16 bits  */
end_comment

begin_define
define|#
directive|define
name|setsbits
parameter_list|(
name|n
parameter_list|,
name|s
parameter_list|)
value|n = (n& ~SMASK) | (tchar)(s)<< 24
end_define

begin_define
define|#
directive|define
name|setfbits
parameter_list|(
name|n
parameter_list|,
name|f
parameter_list|)
value|n = (n& ~FMASK) | (tchar)(f)<< 16
end_define

begin_define
define|#
directive|define
name|setsfbits
parameter_list|(
name|n
parameter_list|,
name|sf
parameter_list|)
value|n = (n& ~SFMASK) | (tchar)(sf)<< 16
end_define

begin_define
define|#
directive|define
name|setcbits
parameter_list|(
name|n
parameter_list|,
name|c
parameter_list|)
value|n = (n& ~CMASKL | (c))
end_define

begin_comment
comment|/* set character bits */
end_comment

begin_define
define|#
directive|define
name|MMASK
value|0100000
end_define

begin_comment
comment|/* macro mask indicator */
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
name|ZONE
value|5
end_define

begin_comment
comment|/* 5 hrs for EST */
end_comment

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
value|(unsigned) 0100000
end_define

begin_define
define|#
directive|define
name|CTAB
value|040000
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

begin_typedef
typedef|typedef
name|unsigned
name|filep
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BLK
value|128
end_define

begin_comment
comment|/* alloc block tchars */
end_comment

begin_define
define|#
directive|define
name|NBLIST
value|1024
end_define

begin_comment
comment|/* allocation list */
end_comment

begin_comment
comment|/* previous values were BLK 256 NBLIST 512 */
end_comment

begin_comment
comment|/* it seems good to keep the product constant */
end_comment

begin_comment
comment|/* BLK*NBLIST<=65536 words, if filep=unsigned */
end_comment

begin_typedef
typedef|typedef
name|long
name|tchar
typedef|;
end_typedef

begin_comment
comment|/* as an experiment */
end_comment

begin_decl_stmt
specifier|extern
name|tchar
name|getch
argument_list|()
decl_stmt|,
name|getch0
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
name|rbf
argument_list|()
decl_stmt|,
name|rbf0
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
name|mot
argument_list|()
decl_stmt|,
name|hmot
argument_list|()
decl_stmt|,
name|vmot
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
name|makem
argument_list|()
decl_stmt|,
name|sethl
argument_list|()
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|tchar
name|popi
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tchar
name|getlg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tchar
name|xlss
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tchar
name|setfield
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|tchar
name|setz
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|tchar
name|setch
argument_list|()
decl_stmt|,
name|absch
argument_list|()
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|tchar
name|setht
argument_list|()
decl_stmt|,
name|setslant
argument_list|()
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|atoi
parameter_list|(
name|i
parameter_list|)
value|((int) atoi0(i))
end_define

begin_function_decl
specifier|extern
name|long
name|atoi0
parameter_list|()
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|int
name|Inch
decl_stmt|,
name|Hor
decl_stmt|,
name|Vert
decl_stmt|,
name|Unitwidth
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* these characters are used as various signals or values /* in miscellaneous places. /* values are set in specnames in t10.c */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|c_hyphen
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c_emdash
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c_rule
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c_minus
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c_narsp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c_hnarsp
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c_fi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c_fl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c_ff
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c_ffi
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c_ffl
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c_acute
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c_grave
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c_under
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c_rooten
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c_boxrule
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|c_lefthand
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|stderr
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* this is NOT the stdio value! */
end_comment

end_unit

