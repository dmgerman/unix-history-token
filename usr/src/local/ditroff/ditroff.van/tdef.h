begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * @(#)tdef.h	2.4 (Berkeley) 11/3/90  */
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
name|ULFONT
value|2
end_define

begin_comment
comment|/* default underline font */
end_comment

begin_define
define|#
directive|define
name|BDFONT
value|3
end_define

begin_comment
comment|/* default emboldening font */
end_comment

begin_define
define|#
directive|define
name|BIFONT
value|4
end_define

begin_comment
comment|/* default bold italic font */
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
value|t.Adj
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
name|PO
value|(INCH)
end_define

begin_comment
comment|/* page offset 1 inch */
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
name|DRAWSPLINE
value|'~'
end_define

begin_comment
comment|/* quadratic B spline */
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
name|XON
value|023
end_define

begin_comment
comment|/* \X'...' starts here */
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
name|UNPAD
value|027
end_define

begin_comment
comment|/* unpaddable blank */
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

begin_define
define|#
directive|define
name|XOFF
value|034
end_define

begin_comment
comment|/* \X'...' ends here */
end_comment

begin_define
define|#
directive|define
name|iscontrol
parameter_list|(
name|n
parameter_list|)
value|(n==035 || n==036)
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
name|MAXFONTS
value|99
end_define

begin_comment
comment|/* Max number of mounted fonts (in fontab) */
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
comment|/* left hand for word overflow */
end_comment

begin_define
define|#
directive|define
name|DAGGER
value|c_dagger
end_define

begin_comment
comment|/* dagger for footnotes */
end_comment

begin_comment
comment|/* array sizes, and similar limits: */
end_comment

begin_define
define|#
directive|define
name|NFONT
value|128
end_define

begin_comment
comment|/* maximum number of fonts (including specials) */
end_comment

begin_define
define|#
directive|define
name|NN
value|400
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
value|128
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
value|2048
end_define

begin_comment
comment|/* disk sector size in chars */
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
value|8192
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
value|40
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
value|1024
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
value|512
end_define

begin_comment
comment|/* number of items in trtab[] */
end_comment

begin_define
define|#
directive|define
name|NWIDCACHE
value|512
end_define

begin_comment
comment|/* number of items in widcache[] */
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
name|IBUFSZ
value|8192
end_define

begin_comment
comment|/* bytes */
end_comment

begin_define
define|#
directive|define
name|NC
value|1024
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
comment|/* 	Internal character representation: 	Internally, every character is carried around as 	a 32 bit cookie, called a "tchar" (typedef long). 	Bits are numbered 31..0 from left to right. 	If bit 15 is 1, the character is motion, with 		if bit 16 it's vertical motion 		if bit 17 it's negative motion 	If bit 15 is 0, the character is a real character. 		if bit 31	zero motion 		bits 30..24	size 		bits 23..16	font 		bit 8		absolute char number in 7..0 	This implies at most 256-32 characters in a single font, 	which is going to be a problem somewhere */
end_comment

begin_comment
comment|/* in the following, "L" should really be a tchar, but ... */
end_comment

begin_define
define|#
directive|define
name|MOT
value|(01L<<15)
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
value|((n)& MOT)
end_define

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
value|(unsigned)(0177777& (n)& ~MOT)
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
name|ABSCHAR
value|0400
end_define

begin_comment
comment|/* absolute char number in this font */
end_comment

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
name|sbits
parameter_list|(
name|n
parameter_list|)
value|(((n)>> 24)& 0177)
end_define

begin_define
define|#
directive|define
name|fbits
parameter_list|(
name|n
parameter_list|)
value|(((n)>> 16)& 0377)
end_define

begin_define
define|#
directive|define
name|sfbits
parameter_list|(
name|n
parameter_list|)
value|(unsigned)(0177777& (((n)& SFMASK)>> 16))
end_define

begin_define
define|#
directive|define
name|cbits
parameter_list|(
name|n
parameter_list|)
value|(unsigned)(0177777& (n))
end_define

begin_comment
comment|/* isolate bottom 16 bits  */
end_comment

begin_define
define|#
directive|define
name|absbits
parameter_list|(
name|n
parameter_list|)
value|(cbits(n)& ~ABSCHAR)
end_define

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
value|n = (n& ~077777L | (c))
end_define

begin_comment
comment|/* set character bits */
end_comment

begin_define
define|#
directive|define
name|BYTEMASK
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
name|TABMASK
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
name|TABBIT
value|02
end_define

begin_comment
comment|/* bits in gchtab */
end_comment

begin_define
define|#
directive|define
name|LDRBIT
value|04
end_define

begin_define
define|#
directive|define
name|FCBIT
value|010
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
name|oput
parameter_list|(
name|c
parameter_list|)
value|putc(c, ptid)
end_define

begin_comment
comment|/*  * "temp file" parameters.  macros and strings  * are stored in an array of linked blocks,  * which may be in memory if INCORE is set during  * compilation, or otherwise in a file.  * The numerology is delicate if filep is 16 bits: 	#define BLK 128 	#define NBLIST 512  * i.e., the product is 16 bits long.   * If filep is an unsigned long (and if your  * compiler will let you say that) then NBLIST  * can be a lot bigger.  Of course that makes  * the file or core image a lot bigger too,  * and means you don't detect missing diversion  * terminations as quickly... .  * It also means that you may have trouble running  * on non-swapping systems, since the core image  * will be over 1Mb.   * In any case, both must be powers of 2.  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|int
name|filep
typedef|;
end_typedef

begin_comment
comment|/* this is good for 32 bit machines */
end_comment

begin_define
define|#
directive|define
name|BLK
value|128
end_define

begin_comment
comment|/* alloc block in tchars */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|SMALLER
end_ifdef

begin_define
define|#
directive|define
name|NBLIST
value|1024
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NBLIST
value|2048
end_define

begin_comment
comment|/* allocation list.  smallish machines use 1024, bigger use 2048 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

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

begin_function_decl
specifier|extern
name|tchar
name|setch
parameter_list|()
function_decl|;
end_function_decl

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
name|c_dagger
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|d
block|{
comment|/* diversion */
name|filep
name|op
decl_stmt|;
name|int
name|dnl
decl_stmt|;
name|int
name|dimac
decl_stmt|;
name|int
name|ditrap
decl_stmt|;
name|int
name|ditf
decl_stmt|;
name|int
name|alss
decl_stmt|;
name|int
name|blss
decl_stmt|;
name|int
name|nls
decl_stmt|;
name|int
name|mkline
decl_stmt|;
name|int
name|maxl
decl_stmt|;
name|int
name|hnl
decl_stmt|;
name|int
name|curd
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|s
block|{
comment|/* stack frame */
name|int
name|nargs
decl_stmt|;
name|struct
name|s
modifier|*
name|pframe
decl_stmt|;
name|filep
name|pip
decl_stmt|;
name|int
name|pnchar
decl_stmt|;
name|tchar
name|prchar
decl_stmt|;
name|int
name|ppendt
decl_stmt|;
name|tchar
name|pch
decl_stmt|;
name|tchar
modifier|*
name|lastpbp
decl_stmt|;
name|int
name|mname
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
specifier|extern
struct|struct
name|contab
block|{
name|unsigned
name|short
name|rq
decl_stmt|;
name|struct
name|contab
modifier|*
name|link
decl_stmt|;
name|int
function_decl|(
modifier|*
name|f
function_decl|)
parameter_list|()
function_decl|;
name|unsigned
name|mx
decl_stmt|;
block|}
name|contab
index|[
name|NM
index|]
struct|;
end_struct

begin_struct
specifier|extern
struct|struct
name|numtab
block|{
name|short
name|r
decl_stmt|;
comment|/* name */
name|short
name|fmt
decl_stmt|;
name|short
name|inc
decl_stmt|;
name|int
name|val
decl_stmt|;
name|struct
name|numtab
modifier|*
name|link
decl_stmt|;
block|}
name|numtab
index|[
name|NN
index|]
struct|;
end_struct

begin_define
define|#
directive|define
name|PN
value|0
end_define

begin_define
define|#
directive|define
name|NL
value|1
end_define

begin_define
define|#
directive|define
name|YR
value|2
end_define

begin_define
define|#
directive|define
name|HP
value|3
end_define

begin_define
define|#
directive|define
name|CT
value|4
end_define

begin_define
define|#
directive|define
name|DN
value|5
end_define

begin_define
define|#
directive|define
name|MO
value|6
end_define

begin_define
define|#
directive|define
name|DY
value|7
end_define

begin_define
define|#
directive|define
name|DW
value|8
end_define

begin_define
define|#
directive|define
name|LN
value|9
end_define

begin_define
define|#
directive|define
name|DL
value|10
end_define

begin_define
define|#
directive|define
name|ST
value|11
end_define

begin_define
define|#
directive|define
name|SB
value|12
end_define

begin_define
define|#
directive|define
name|CD
value|13
end_define

begin_define
define|#
directive|define
name|PID
value|14
end_define

begin_comment
comment|/* the infamous environment block */
end_comment

begin_define
define|#
directive|define
name|ics
value|(env->_ics)
end_define

begin_define
define|#
directive|define
name|sps
value|(env->_sps)
end_define

begin_define
define|#
directive|define
name|spacesz
value|(env->_spacesz)
end_define

begin_define
define|#
directive|define
name|lss
value|(env->_lss)
end_define

begin_define
define|#
directive|define
name|lss1
value|(env->_lss1)
end_define

begin_define
define|#
directive|define
name|ll
value|(env->_ll)
end_define

begin_define
define|#
directive|define
name|ll1
value|(env->_ll1)
end_define

begin_define
define|#
directive|define
name|lt
value|(env->_lt)
end_define

begin_define
define|#
directive|define
name|lt1
value|(env->_lt1)
end_define

begin_define
define|#
directive|define
name|ic
value|(env->_ic)
end_define

begin_define
define|#
directive|define
name|icf
value|(env->_icf)
end_define

begin_define
define|#
directive|define
name|chbits
value|(env->_chbits)
end_define

begin_define
define|#
directive|define
name|spbits
value|(env->_spbits)
end_define

begin_define
define|#
directive|define
name|nmbits
value|(env->_nmbits)
end_define

begin_define
define|#
directive|define
name|apts
value|(env->_apts)
end_define

begin_define
define|#
directive|define
name|apts1
value|(env->_apts1)
end_define

begin_define
define|#
directive|define
name|pts
value|(env->_pts)
end_define

begin_define
define|#
directive|define
name|pts1
value|(env->_pts1)
end_define

begin_define
define|#
directive|define
name|font
value|(env->_font)
end_define

begin_define
define|#
directive|define
name|font1
value|(env->_font1)
end_define

begin_define
define|#
directive|define
name|ls
value|(env->_ls)
end_define

begin_define
define|#
directive|define
name|ls1
value|(env->_ls1)
end_define

begin_define
define|#
directive|define
name|ad
value|(env->_ad)
end_define

begin_define
define|#
directive|define
name|nms
value|(env->_nms)
end_define

begin_define
define|#
directive|define
name|ndf
value|(env->_ndf)
end_define

begin_define
define|#
directive|define
name|fi
value|(env->_fi)
end_define

begin_define
define|#
directive|define
name|cc
value|(env->_cc)
end_define

begin_define
define|#
directive|define
name|c2
value|(env->_c2)
end_define

begin_define
define|#
directive|define
name|ohc
value|(env->_ohc)
end_define

begin_define
define|#
directive|define
name|tdelim
value|(env->_tdelim)
end_define

begin_define
define|#
directive|define
name|hyf
value|(env->_hyf)
end_define

begin_define
define|#
directive|define
name|hyoff
value|(env->_hyoff)
end_define

begin_define
define|#
directive|define
name|hyalg
value|(env->_hyalg)
end_define

begin_define
define|#
directive|define
name|hyalg1
value|(env->_hyalg1)
end_define

begin_define
define|#
directive|define
name|thresh
value|(env->_thresh)
end_define

begin_define
define|#
directive|define
name|un1
value|(env->_un1)
end_define

begin_define
define|#
directive|define
name|tabc
value|(env->_tabc)
end_define

begin_define
define|#
directive|define
name|dotc
value|(env->_dotc)
end_define

begin_define
define|#
directive|define
name|adsp
value|(env->_adsp)
end_define

begin_define
define|#
directive|define
name|adrem
value|(env->_adrem)
end_define

begin_define
define|#
directive|define
name|lastl
value|(env->_lastl)
end_define

begin_define
define|#
directive|define
name|nel
value|(env->_nel)
end_define

begin_define
define|#
directive|define
name|admod
value|(env->_admod)
end_define

begin_define
define|#
directive|define
name|wordp
value|(env->_wordp)
end_define

begin_define
define|#
directive|define
name|spflg
value|(env->_spflg)
end_define

begin_define
define|#
directive|define
name|linep
value|(env->_linep)
end_define

begin_define
define|#
directive|define
name|wdend
value|(env->_wdend)
end_define

begin_define
define|#
directive|define
name|wdstart
value|(env->_wdstart)
end_define

begin_define
define|#
directive|define
name|wne
value|(env->_wne)
end_define

begin_define
define|#
directive|define
name|ne
value|(env->_ne)
end_define

begin_define
define|#
directive|define
name|nc
value|(env->_nc)
end_define

begin_define
define|#
directive|define
name|nb
value|(env->_nb)
end_define

begin_define
define|#
directive|define
name|lnmod
value|(env->_lnmod)
end_define

begin_define
define|#
directive|define
name|nwd
value|(env->_nwd)
end_define

begin_define
define|#
directive|define
name|nn
value|(env->_nn)
end_define

begin_define
define|#
directive|define
name|ni
value|(env->_ni)
end_define

begin_define
define|#
directive|define
name|ul
value|(env->_ul)
end_define

begin_define
define|#
directive|define
name|cu
value|(env->_cu)
end_define

begin_define
define|#
directive|define
name|ce
value|(env->_ce)
end_define

begin_define
define|#
directive|define
name|in
value|(env->_in)
end_define

begin_define
define|#
directive|define
name|in1
value|(env->_in1)
end_define

begin_define
define|#
directive|define
name|un
value|(env->_un)
end_define

begin_define
define|#
directive|define
name|wch
value|(env->_wch)
end_define

begin_define
define|#
directive|define
name|pendt
value|(env->_pendt)
end_define

begin_define
define|#
directive|define
name|pendw
value|(env->_pendw)
end_define

begin_define
define|#
directive|define
name|pendnf
value|(env->_pendnf)
end_define

begin_define
define|#
directive|define
name|spread
value|(env->_spread)
end_define

begin_define
define|#
directive|define
name|it
value|(env->_it)
end_define

begin_define
define|#
directive|define
name|itmac
value|(env->_itmac)
end_define

begin_define
define|#
directive|define
name|lnsize
value|(env->_lnsize)
end_define

begin_define
define|#
directive|define
name|hyptr
value|(env->_hyptr)
end_define

begin_define
define|#
directive|define
name|tabtab
value|(env->_tabtab)
end_define

begin_define
define|#
directive|define
name|line
value|(env->_line)
end_define

begin_define
define|#
directive|define
name|word
value|(env->_word)
end_define

begin_comment
comment|/*  * Note (jaap)  * If this structure changes in ni.c, you should change  * this as well  */
end_comment

begin_struct
struct|struct
name|env
block|{
name|int
name|_ics
decl_stmt|;
name|int
name|_sps
decl_stmt|;
name|int
name|_spacesz
decl_stmt|;
name|int
name|_lss
decl_stmt|;
name|int
name|_lss1
decl_stmt|;
name|int
name|_ll
decl_stmt|;
name|int
name|_ll1
decl_stmt|;
name|int
name|_lt
decl_stmt|;
name|int
name|_lt1
decl_stmt|;
name|tchar
name|_ic
decl_stmt|;
name|int
name|_icf
decl_stmt|;
name|tchar
name|_chbits
decl_stmt|;
name|tchar
name|_spbits
decl_stmt|;
name|tchar
name|_nmbits
decl_stmt|;
name|int
name|_apts
decl_stmt|;
name|int
name|_apts1
decl_stmt|;
name|int
name|_pts
decl_stmt|;
name|int
name|_pts1
decl_stmt|;
name|int
name|_font
decl_stmt|;
name|int
name|_font1
decl_stmt|;
name|int
name|_ls
decl_stmt|;
name|int
name|_ls1
decl_stmt|;
name|int
name|_ad
decl_stmt|;
name|int
name|_nms
decl_stmt|;
name|int
name|_ndf
decl_stmt|;
name|int
name|_fi
decl_stmt|;
name|int
name|_cc
decl_stmt|;
name|int
name|_c2
decl_stmt|;
name|int
name|_ohc
decl_stmt|;
name|int
name|_tdelim
decl_stmt|;
name|int
name|_hyf
decl_stmt|;
name|int
name|_hyoff
decl_stmt|;
name|int
name|_hyalg
decl_stmt|;
name|int
name|_hyalg1
decl_stmt|;
name|int
name|_thresh
decl_stmt|;
name|int
name|_un1
decl_stmt|;
name|int
name|_tabc
decl_stmt|;
name|int
name|_dotc
decl_stmt|;
name|int
name|_adsp
decl_stmt|;
name|int
name|_adrem
decl_stmt|;
name|int
name|_lastl
decl_stmt|;
name|int
name|_nel
decl_stmt|;
name|int
name|_admod
decl_stmt|;
name|tchar
modifier|*
name|_wordp
decl_stmt|;
name|int
name|_spflg
decl_stmt|;
name|tchar
modifier|*
name|_linep
decl_stmt|;
name|tchar
modifier|*
name|_wdend
decl_stmt|;
name|tchar
modifier|*
name|_wdstart
decl_stmt|;
name|int
name|_wne
decl_stmt|;
name|int
name|_ne
decl_stmt|;
name|int
name|_nc
decl_stmt|;
name|int
name|_nb
decl_stmt|;
name|int
name|_lnmod
decl_stmt|;
name|int
name|_nwd
decl_stmt|;
name|int
name|_nn
decl_stmt|;
name|int
name|_ni
decl_stmt|;
name|int
name|_ul
decl_stmt|;
name|int
name|_cu
decl_stmt|;
name|int
name|_ce
decl_stmt|;
name|int
name|_in
decl_stmt|;
name|int
name|_in1
decl_stmt|;
name|int
name|_un
decl_stmt|;
name|int
name|_wch
decl_stmt|;
name|int
name|_pendt
decl_stmt|;
name|tchar
modifier|*
name|_pendw
decl_stmt|;
name|int
name|_pendnf
decl_stmt|;
name|int
name|_spread
decl_stmt|;
name|int
name|_it
decl_stmt|;
name|int
name|_itmac
decl_stmt|;
name|int
name|_lnsize
decl_stmt|;
name|tchar
modifier|*
name|_hyptr
index|[
name|NHYP
index|]
decl_stmt|;
name|int
name|_tabtab
index|[
name|NTAB
index|]
decl_stmt|;
name|tchar
name|_line
index|[
name|LNSIZE
index|]
decl_stmt|;
name|tchar
name|_word
index|[
name|WDSIZE
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|env
modifier|*
name|env
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|env
name|env_array
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * All changes will come after this comment (jaap)  */
end_comment

begin_comment
comment|/*  * hyphenation dependent stuff (jaap)  */
end_comment

begin_define
define|#
directive|define
name|THRESH
value|160
end_define

begin_comment
comment|/*digram goodness threshold (from n8.c, (jaap))*/
end_comment

begin_define
define|#
directive|define
name|DUTCH_THRESH
value|3
end_define

begin_comment
comment|/* for recursive bestesplits (jaap) */
end_comment

begin_define
define|#
directive|define
name|ORIGINAL
value|0
end_define

begin_comment
comment|/* original (American) English) algorithm */
end_comment

begin_define
define|#
directive|define
name|DUTCH
value|1
end_define

begin_comment
comment|/* second hyphenation routine (bestesplits) */
end_comment

begin_define
define|#
directive|define
name|MAXDIALECTS
value|1
end_define

begin_comment
comment|/* number of hyphenation algorithms */
end_comment

begin_comment
comment|/*  * define enough space for the fontcache. EXTRAFONT is maximum space  * currently to be used by a font. The space for the fonttab is  * for the "logical to physical font table mapping addition (jaap).  */
end_comment

begin_define
define|#
directive|define
name|MAXCHARS
value|255
end_define

begin_comment
comment|/* current maximum of characters in a font */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CWI
end_ifdef

begin_define
define|#
directive|define
name|EXTRAFONT
value|(3*MAXCHARS * sizeof(char) + dev.nchtab + (128-32) \ 	* sizeof(char) + sizeof(struct Font) + 255 * sizeof(short))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|EXTRAFONT
value|(3*MAXCHARS * sizeof(char) + dev.nchtab + (128-32) \ 	* sizeof(char) + sizeof(struct Font))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_define
define|#
directive|define
name|fdprintf
value|fprintf
end_define

begin_define
define|#
directive|define
name|flusho
parameter_list|()
end_define

end_unit

