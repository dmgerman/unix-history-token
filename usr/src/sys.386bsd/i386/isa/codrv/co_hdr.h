begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * General declarations for CO driver  *  *      Copyright 1992 by Holger Veit  *	May be freely used with Bill Jolitz's port of   *	386bsd and may be included in a 386bsd collection  *	as long as binary and source are available and reproduce the above  *	copyright.  *  *	You may freely modify this code and contribute improvements based  *	on this code as long as you don't claim to be the original author.  *	Commercial use of this source requires permittance of the copyright   *	holder. A general license for 386bsd will override this restriction.  *  *	Use at your own risk. The copyright holder or any person who makes  *	this code available for the public (administrators of public archives  *	for instance) are not responsible for any harm to hardware or software  *	that might happen due to wrong application or program faults.  *  *	@(#) $RCSfile: co_hdr.h,v $	$Revision: 1.11 $ (Contributed to 386bsd) $Date: 93/01/23 23:14:39 $  *  *	History: see CO_HISTORY  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CO_HDR_H_
end_ifndef

begin_define
define|#
directive|define
name|_CO_HDR_H_
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|GLOBAL
end_ifndef

begin_define
define|#
directive|define
name|GLOBAL
value|extern
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"param.h"
end_include

begin_include
include|#
directive|include
file|"malloc.h"
end_include

begin_include
include|#
directive|include
file|"conf.h"
end_include

begin_include
include|#
directive|include
file|"ioctl.h"
end_include

begin_include
include|#
directive|include
file|"proc.h"
end_include

begin_include
include|#
directive|include
file|"user.h"
end_include

begin_include
include|#
directive|include
file|"tty.h"
end_include

begin_include
include|#
directive|include
file|"uio.h"
end_include

begin_include
include|#
directive|include
file|"fcntl.h"
end_include

begin_include
include|#
directive|include
file|"i386/isa/isa_device.h"
end_include

begin_include
include|#
directive|include
file|"callout.h"
end_include

begin_include
include|#
directive|include
file|"systm.h"
end_include

begin_include
include|#
directive|include
file|"kernel.h"
end_include

begin_include
include|#
directive|include
file|"vnode.h"
end_include

begin_include
include|#
directive|include
file|"syslog.h"
end_include

begin_include
include|#
directive|include
file|"i386/isa/icu.h"
end_include

begin_include
include|#
directive|include
file|"i386/i386/cons.h"
end_include

begin_include
include|#
directive|include
file|"i386/isa/isa.h"
end_include

begin_include
include|#
directive|include
file|"i386/isa/ic/i8042.h"
end_include

begin_include
include|#
directive|include
file|"i386/isa/kbd.h"
end_include

begin_include
include|#
directive|include
file|"machine/pc/display.h"
end_include

begin_include
include|#
directive|include
file|"machine/psl.h"
end_include

begin_include
include|#
directive|include
file|"machine/frame.h"
end_include

begin_include
include|#
directive|include
file|"ioctl_pc.h"
end_include

begin_comment
comment|/*   *  user adjustable constants  */
end_comment

begin_comment
comment|/*#define NETBSD*/
end_comment

begin_comment
comment|/* define this if you have NetBSD */
end_comment

begin_define
define|#
directive|define
name|SCRSAVER
value|2
end_define

begin_comment
comment|/* 1=standard moving block */
end_comment

begin_comment
comment|/* 2=moving snake (thanks: Christoph Robitschko) */
end_comment

begin_define
define|#
directive|define
name|BLANKTIMEOUT
value|10*60
end_define

begin_comment
comment|/* Default Screen blanking after 10*60 seconds */
end_comment

begin_define
define|#
directive|define
name|KBDTIMEOUT
value|0x15000l
end_define

begin_comment
comment|/* timeout parameter for a keyboard response 				  * adjust for slow keyboard at a fast computer 				  * (e.g. 486DX laptop) 				  */
end_comment

begin_define
define|#
directive|define
name|KBDRETRIES
value|5
end_define

begin_comment
comment|/* max. no. of tries to reset the keyboard in 				 * probing loop, avoids hanging forever if 				 * keyboard does not reply like expected 				 */
end_comment

begin_define
define|#
directive|define
name|FAT_CURSOR
end_define

begin_comment
comment|/* full size cursor, undef if to leave unchanged */
end_comment

begin_comment
comment|/*  default screen attributes */
end_comment

begin_define
define|#
directive|define
name|DEF_STD_BGAT
value|BG_BLACK
end_define

begin_comment
comment|/* standard background */
end_comment

begin_define
define|#
directive|define
name|DEF_STD_M_FGAT
value|FG_LIGHTGREY
end_define

begin_comment
comment|/* standard mono foreground */
end_comment

begin_define
define|#
directive|define
name|DEF_STD_C_FGAT
value|FG_LIGHTGREY
end_define

begin_comment
comment|/* standard color foreground */
end_comment

begin_define
define|#
directive|define
name|DEF_KERN_BGAT
value|BG_BLACK
end_define

begin_comment
comment|/* kernelmode background */
end_comment

begin_define
define|#
directive|define
name|DEF_KERN_M_FGAT
value|FG_UNDERLINE
end_define

begin_comment
comment|/* kernelmode mono foreground */
end_comment

begin_define
define|#
directive|define
name|DEF_KERN_C_FGAT
value|FG_LIGHTBLUE
end_define

begin_comment
comment|/* XXX (to distinguish) kernelmode color foreground */
end_comment

begin_define
define|#
directive|define
name|DEF_SO_M_AT
value|FG_INTENSE|BG_LIGHTGREY
end_define

begin_comment
comment|/* standout mono mode */
end_comment

begin_define
define|#
directive|define
name|DEF_SO_C_AT
value|FG_YELLOW|BG_BLACK
end_define

begin_comment
comment|/* standout color mode */
end_comment

begin_comment
comment|/*****************NO USER DEFINABLE DATA BELOW THIS LINE*******************/
end_comment

begin_comment
comment|/* this is an anachronism in the moment: there is no ioctl other than CODRV1  * public available. If you want to write a different ioctl set  * based on the core system, read co_codrv1.c as a template.  */
end_comment

begin_define
define|#
directive|define
name|CODRV1
value|1
end_define

begin_comment
comment|/* I dunno why this had to be changed! */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NETBSD
end_ifndef

begin_include
include|#
directive|include
file|"ddb.h"
end_include

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* is NetBSD */
end_comment

begin_undef
undef|#
directive|undef
name|NDDB
end_undef

begin_ifdef
ifdef|#
directive|ifdef
name|DDB
end_ifdef

begin_define
define|#
directive|define
name|NDDB
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|NDDB
value|0
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
comment|/* NetBSD */
end_comment

begin_define
define|#
directive|define
name|DEFAULTCOL
value|80
end_define

begin_define
define|#
directive|define
name|DEFAULTROW
value|25
end_define

begin_define
define|#
directive|define
name|CHR
value|2
end_define

begin_comment
comment|/* Don't think these locations are true virtual addrs! */
end_comment

begin_define
define|#
directive|define
name|MONO_BUF
value|0xfe0b0000
end_define

begin_define
define|#
directive|define
name|CGA_BUF
value|0xfe0b8000
end_define

begin_define
define|#
directive|define
name|EGA_BIOS
value|0xfe0c0000
end_define

begin_define
define|#
directive|define
name|ALTEGA_BIOS
value|0xfe0e0000
end_define

begin_comment
comment|/* alternate video BIOS location */
end_comment

begin_define
define|#
directive|define
name|IOPHYSMEM
value|0xa0000
end_define

begin_define
define|#
directive|define
name|MONO_BASE
value|0x3b4
end_define

begin_define
define|#
directive|define
name|CGA_BASE
value|0x3d4
end_define

begin_comment
comment|/* 6845 register definitions */
end_comment

begin_define
define|#
directive|define
name|M6845_ADDR
value|0
end_define

begin_define
define|#
directive|define
name|M6845_HTOTAL
value|0
end_define

begin_define
define|#
directive|define
name|M6845_HDISPL
value|1
end_define

begin_define
define|#
directive|define
name|M6845_HSYNC
value|2
end_define

begin_define
define|#
directive|define
name|M6845_SYNCWIDTH
value|3
end_define

begin_define
define|#
directive|define
name|M6845_VTOTAL
value|4
end_define

begin_define
define|#
directive|define
name|M6845_VTOTADJ
value|5
end_define

begin_define
define|#
directive|define
name|M6845_VDISPL
value|6
end_define

begin_define
define|#
directive|define
name|M6845_VSYNC
value|7
end_define

begin_define
define|#
directive|define
name|M6845_IMODE
value|8
end_define

begin_define
define|#
directive|define
name|M6845_MAXSCAN
value|9
end_define

begin_define
define|#
directive|define
name|M6845_CURSTART
value|0x0A
end_define

begin_define
define|#
directive|define
name|M6845_CUREND
value|0x0B
end_define

begin_define
define|#
directive|define
name|M6845_STARTADRH
value|0x0C
end_define

begin_define
define|#
directive|define
name|M6845_STARTADRL
value|0x0D
end_define

begin_define
define|#
directive|define
name|M6845_CURSORH
value|0x0E
end_define

begin_define
define|#
directive|define
name|M6845_CURSORL
value|0x0F
end_define

begin_define
define|#
directive|define
name|M6845_LPENH
value|0x10
end_define

begin_define
define|#
directive|define
name|M6845_LPENL
value|0x11
end_define

begin_comment
comment|/* for screentimeout */
end_comment

begin_define
define|#
directive|define
name|BLANKSTART
value|0
end_define

begin_comment
comment|/* for reset and change */
end_comment

begin_define
define|#
directive|define
name|BLANKSTOP
value|1
end_define

begin_comment
comment|/* temporarily suspend */
end_comment

begin_define
define|#
directive|define
name|MAXESCPARAM
value|10
end_define

begin_comment
comment|/* max # of ESC parameters */
end_comment

begin_comment
comment|/* for fonts */
end_comment

begin_define
define|#
directive|define
name|XLAT2PC8
value|0xFFFE
end_define

begin_define
define|#
directive|define
name|NOFONT
value|0xFFFD
end_define

begin_define
define|#
directive|define
name|ISOLATIN1
value|0
end_define

begin_comment
comment|/* abbreviation for LED control */
end_comment

begin_define
define|#
directive|define
name|leds
parameter_list|(
name|vp
parameter_list|)
value|((vp->altgrled ? \ 	vp->altgrlock : vp->shiftled ? \ 	vp->shiftlock : vp->caps)<< 2 | \ 	vp->num<<1 | vp->scroll)
end_define

begin_comment
comment|/*  *  local types  */
end_comment

begin_define
define|#
directive|define
name|KBDMAXOVLKEYSIZE
value|15
end_define

begin_comment
comment|/* excl. zero byte */
end_comment

begin_define
define|#
directive|define
name|KBDDEFOVLKEYSIZE
value|4
end_define

begin_comment
comment|/* excl. zero byte */
end_comment

begin_comment
comment|/* This defines the actually used table for key assignments, and is  * dynamically assigned.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|kbd_ovlkey
name|Ovl_tbl
typedef|;
end_typedef

begin_comment
comment|/* This defines the default table for key assignments. This table does  * not have entries for META, ALTGR, SHIFTALTGR like the overloaded key  * table  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_short
name|type
decl_stmt|;
comment|/* type of key */
name|Ovl_tbl
modifier|*
name|ovlptr
decl_stmt|;
comment|/* -vak pointer into overload table */
name|XCHAR
name|unshift
index|[
name|KBDDEFOVLKEYSIZE
operator|+
literal|1
index|]
decl_stmt|;
comment|/* default codes */
name|XCHAR
name|shift
index|[
name|KBDDEFOVLKEYSIZE
operator|+
literal|1
index|]
decl_stmt|;
name|XCHAR
name|ctrl
index|[
name|KBDDEFOVLKEYSIZE
operator|+
literal|1
index|]
decl_stmt|;
block|}
name|Keycap_def
typedef|;
end_typedef

begin_define
define|#
directive|define
name|XC0
value|{ 0,1,1,1 }
end_define

begin_define
define|#
directive|define
name|XC1
parameter_list|(
name|a
parameter_list|)
value|{ a,0,1,1 }
end_define

begin_define
define|#
directive|define
name|XC2
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|{ a,b,0,1 }
end_define

begin_define
define|#
directive|define
name|XC3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|{ a,b,c,0 }
end_define

begin_define
define|#
directive|define
name|XC4
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|{ a,b,c,d }
end_define

begin_define
define|#
directive|define
name|XE3
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|{ '\033',a,b,0 }
end_define

begin_if
if|#
directive|if
name|XCHAR
operator|==
name|u_char
end_if

begin_define
define|#
directive|define
name|xc_bcopy
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|sz
parameter_list|)
value|bcopyb(src,dst,sz)
end_define

begin_define
define|#
directive|define
name|xc_char2xc
parameter_list|(
name|X
parameter_list|)
value|(X)
end_define

begin_else
else|#
directive|else
end_else

begin_expr_stmt
name|ERROR
operator|!
name|CHANGE
name|xc_bcopy
operator|!
operator|!
operator|!
operator|!
operator|!
operator|!
end_expr_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* This is the special functions lookup table (local version of   * struct kbd_special  */
end_comment

begin_define
define|#
directive|define
name|MAXNROFSPEC
value|30
end_define

begin_comment
comment|/* so many keys may have special functions */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|u_short
name|key
decl_stmt|;
name|u_short
name|modifier
decl_stmt|;
name|u_short
name|scan
decl_stmt|;
name|u_short
name|function
decl_stmt|;
block|}
name|Spec_tbl
typedef|;
end_typedef

begin_comment
comment|/* noise, noise, noise (local structure) */
end_comment

begin_struct
struct|struct
name|kbd_sound
block|{
name|int
name|pitch
decl_stmt|;
comment|/* Frequency in Hz */
name|int
name|duration
decl_stmt|;
comment|/* Time in msec */
block|}
struct|;
end_struct

begin_comment
comment|/*  * global variables  */
end_comment

begin_decl_stmt
name|GLOBAL
name|struct
name|consinfo
name|cons_capabilities
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|GLOBAL
specifier|volatile
name|char
name|vtswsema
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|u_short
modifier|*
name|Crtat
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* only absolute address in video area */
end_comment

begin_decl_stmt
specifier|extern
name|Keycap_def
name|kbd_keytab
index|[]
decl_stmt|;
end_decl_stmt

begin_macro
name|GLOBAL
end_macro

begin_struct
struct|struct
name|consoftc
block|{
name|int
name|cs_mymajor
decl_stmt|;
name|int
name|cs_flags
decl_stmt|;
define|#
directive|define
name|CO_INITRB
value|0x001
define|#
directive|define
name|CO_INITTTY
value|0x002
define|#
directive|define
name|CO_OPEN
value|0x004
comment|/* cs_opencnt != 0 */
define|#
directive|define
name|CO_OPENRAW
value|0x008
define|#
directive|define
name|CO_POLLING
value|0x010
comment|/* polling for input */
define|#
directive|define
name|CO_ACTIVE
value|0x020
comment|/* timeout active (unused) */
define|#
directive|define
name|CO_ASYNC
value|0x040
comment|/* Async I/O mode */
define|#
directive|define
name|CO_RDWAIT
value|0x080
comment|/* blocked on read */
name|int
name|cs_timo
decl_stmt|;
comment|/* timeouts since interrupt (unused) */
name|u_long
name|cs_wedgecnt
decl_stmt|;
comment|/* times restarted (unused)*/
name|u_long
name|cs_ovfl
decl_stmt|;
comment|/* buffer overflows */
ifdef|#
directive|ifdef
name|OLDPATCHKIT
name|struct
name|proc
modifier|*
name|cs_selp
decl_stmt|;
comment|/* Process waiting for select call */
else|#
directive|else
name|pid_t
name|cs_rsel
decl_stmt|;
comment|/* Process waiting for select call */
endif|#
directive|endif
name|int
name|cs_pgid
decl_stmt|;
comment|/* Process group for ASYNC I/O */
comment|/*XXX*/
name|struct
name|tty
modifier|*
name|cs_constty
decl_stmt|;
comment|/* used to restore constty if */
comment|/* anyone dares to steal CONSOLE during raw open */
name|struct
name|vty
modifier|*
name|cs_actvty
decl_stmt|;
comment|/* active vty which owns the /dev/kbd */
name|int
name|cs_opencnt
decl_stmt|;
comment|/* counter for opens from vtys */
block|}
name|consoftc
struct|;
end_struct

begin_macro
name|GLOBAL
end_macro

begin_struct
struct|struct
name|kbdstate
block|{
name|int
name|pitch
decl_stmt|;
comment|/* default pitch of beep */
name|int
name|duration
decl_stmt|;
comment|/* default duration of beep */
comment|/* XXX could be bitfields. But why? */
name|u_char
name|m0flag
decl_stmt|;
comment|/* clear META-map flag */
name|u_char
name|c0flag
decl_stmt|;
comment|/* clear CRTL-map flag */
name|u_char
name|a0flag
decl_stmt|;
comment|/* clear ALT-map flag */
name|u_char
name|ledstate
decl_stmt|;
comment|/* current state of kbd LEDS */
name|u_char
name|shift_down
decl_stmt|;
comment|/* shift pressed */
name|u_char
name|ctrl_down
decl_stmt|;
comment|/* ctrl pressed */
name|u_char
name|meta_down
decl_stmt|;
comment|/* meta pressed */
name|u_char
name|altgr_down
decl_stmt|;
comment|/* altgr pressed */
name|u_char
name|repeat
decl_stmt|;
comment|/* allow key repetition */
name|u_char
name|id
decl_stmt|;
comment|/* keyboard id */
name|int
name|tpmrate
decl_stmt|;
comment|/* repetition rate/delay */
block|}
name|kbs
struct|;
end_struct

begin_comment
comment|/* kbd state */
end_comment

begin_macro
name|GLOBAL
end_macro

begin_struct
struct|struct
name|videostate
block|{
name|char
name|blanking
decl_stmt|;
name|char
name|color
decl_stmt|;
name|char
name|f89bit
decl_stmt|;
comment|/* 8/9 bit flag */
name|short
name|cardtype
decl_stmt|;
comment|/* set by device probe */
name|short
name|cardsubtype
decl_stmt|;
comment|/* chipset version */
name|short
name|ram
decl_stmt|;
comment|/* set by whoami */
name|int
name|iobase
decl_stmt|;
name|int
name|scrtimeout
decl_stmt|;
comment|/* Timeout for screenblanker */
name|u_short
name|encoding
index|[
literal|2
index|]
decl_stmt|;
comment|/* font encoding */
name|short
name|_atiext
decl_stmt|;
comment|/* ATI VGA special regs */
block|}
name|vds
struct|;
end_struct

begin_comment
comment|/* poor man's C++. The usage of these attributes is NOT FOR NONSENSE */
end_comment

begin_define
define|#
directive|define
name|PRIVATE
end_define

begin_define
define|#
directive|define
name|PUBLIC
end_define

begin_comment
comment|/* VT central data structure */
end_comment

begin_struct
struct|struct
name|vty
block|{
name|PRIVATE
name|u_short
modifier|*
name|Crtat
decl_stmt|;
comment|/* ptr to virtual video page */
name|PRIVATE
name|u_short
modifier|*
name|crtat
decl_stmt|;
comment|/* ptr to virtual cursor position */
name|PRIVATE
name|u_short
modifier|*
name|vbuf
decl_stmt|;
comment|/* video buffer */
name|PUBLIC
name|char
name|so
decl_stmt|;
comment|/* in standout mode? */
name|PUBLIC
name|char
name|vtynum
decl_stmt|;
comment|/* to get vt# from vtyptr */
name|PUBLIC
name|u_short
name|ttycnt
decl_stmt|;
comment|/* open reference counter */
name|PUBLIC
name|struct
name|tty
modifier|*
name|ttyp
decl_stmt|;
comment|/* pointer to virtual tty information */
name|PUBLIC
name|u_short
name|so_at
decl_stmt|;
comment|/* standout attribute */
name|PUBLIC
struct|struct
name|outmode
block|{
name|u_short
name|fg_at
decl_stmt|,
name|bg_at
decl_stmt|;
comment|/* kernel attributes */
name|u_short
name|def_at
decl_stmt|;
comment|/* default attribute */
name|char
name|f2
decl_stmt|;
comment|/* select second font */
name|char
name|escstate
decl_stmt|;
comment|/* escape state */
name|char
name|parcnt
decl_stmt|;
comment|/* param count */
name|int
name|param
index|[
name|MAXESCPARAM
index|]
decl_stmt|;
comment|/* ESC parameters */
block|}
name|om
index|[
literal|2
index|]
struct|;
comment|/* 0 = std, 1 = kernel */
name|PUBLIC
name|struct
name|outmode
modifier|*
name|op
decl_stmt|;
comment|/* pointer to actual set */
name|PUBLIC
name|short
name|row
decl_stmt|,
name|col
decl_stmt|;
comment|/* current cursor position */
name|PUBLIC
name|short
name|nrow
decl_stmt|,
name|ncol
decl_stmt|;
comment|/* current screen geometry */
name|PUBLIC
name|short
name|size
decl_stmt|;
comment|/* size of video space */
name|PUBLIC
name|u_char
name|visible
decl_stmt|;
comment|/* =1 is visible */
name|PUBLIC
name|u_char
name|scroll
decl_stmt|;
comment|/* =1, scrolllock active */
name|PUBLIC
name|u_char
name|caps
decl_stmt|;
comment|/* caps lock active */
name|PUBLIC
name|u_char
name|num
decl_stmt|;
comment|/* num lock active */
name|PUBLIC
name|u_char
name|shiftlock
decl_stmt|;
comment|/* shift lock active */
name|PUBLIC
name|u_char
name|altgrlock
decl_stmt|;
comment|/* altgr lock active */
name|PUBLIC
name|u_char
name|altgrled
decl_stmt|;
comment|/* -vak- CAPS led is ALTGR-LOCK */
name|PUBLIC
name|u_char
name|shiftled
decl_stmt|;
comment|/* -vak- CAPS led is CAPS-LOCK */
name|PUBLIC
name|int
name|pitch
decl_stmt|;
comment|/* vty dependent sound */
name|PUBLIC
name|int
name|duration
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* TTY structure for virtual terminals */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|vty
name|vtys
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vty data */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|tty
name|pccons
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* vty-tty buffers */
end_comment

begin_decl_stmt
specifier|extern
name|int
name|nvty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* # of available vtys */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|tty
modifier|*
name|constty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* console tty */
end_comment

begin_decl_stmt
name|GLOBAL
name|struct
name|vty
modifier|*
name|actvty
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pointer to actual vty */
end_comment

begin_comment
comment|/* Ring buffer of the raw co device */
end_comment

begin_decl_stmt
name|GLOBAL
name|struct
name|ringb
name|co_buf
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  *  prototypes  */
end_comment

begin_comment
comment|/* in co_cons.c */
end_comment

begin_function_decl
specifier|extern
name|struct
name|tty
modifier|*
name|dev2tty
parameter_list|(
name|dev_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pcopen
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|flag
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pcclose
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|flag
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|proc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pcread
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pcwrite
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pcioctl
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pcstart
parameter_list|(
name|struct
name|tty
modifier|*
name|tp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pccnprobe
parameter_list|(
name|struct
name|consdev
modifier|*
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pccninit
parameter_list|(
name|struct
name|consdev
modifier|*
name|cp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|pccnputc
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pccngetc
parameter_list|(
name|dev_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pcparam
parameter_list|(
name|struct
name|tty
modifier|*
parameter_list|,
name|struct
name|termios
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pcpoll
parameter_list|(
name|int
name|onoff
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|pg
parameter_list|(
name|char
modifier|*
name|p
parameter_list|,
name|int
name|q
parameter_list|,
name|int
name|r
parameter_list|,
name|int
name|s
parameter_list|,
name|int
name|t
parameter_list|,
name|int
name|u
parameter_list|,
name|int
name|v
parameter_list|,
name|int
name|w
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|,
name|int
name|z
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|getchar
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in co_kbd.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|reset_kbd_flags
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|coopen
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|flag
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|coclose
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|flag
parameter_list|,
name|int
name|mode
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|coread
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|struct
name|uio
modifier|*
name|uio
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cointr
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|irq
parameter_list|,
name|int
name|cpl
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cowakeup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|coselect
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|rw
parameter_list|,
name|struct
name|proc
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|coioctl
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|comap
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|offset
parameter_list|,
name|int
name|nprot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|coprobe
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|kbd_setleds
parameter_list|(
name|int
name|ledval
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|kbd_ovlinit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kbd_getokeydef
parameter_list|(
name|u_int
name|key
parameter_list|,
name|Ovl_tbl
modifier|*
name|thisdef
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kbd_getckeydef
parameter_list|(
name|u_int
name|key
parameter_list|,
name|Ovl_tbl
modifier|*
name|thisdef
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kbd_getspecial
parameter_list|(
name|struct
name|kbd_hotkey
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kbd_setspecial
parameter_list|(
name|struct
name|kbd_hotkey
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|sgetc
parameter_list|(
name|int
name|noblock
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* compatibility */
end_comment

begin_function_decl
specifier|extern
name|XCHAR
modifier|*
name|kbd_sgetc
parameter_list|(
name|int
name|noblock
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|kbd_settpmrate
parameter_list|(
name|int
name|rate
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kbd_rmkeydef
parameter_list|(
name|u_int
name|key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kbd_setkeydef
parameter_list|(
name|Ovl_tbl
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kbd_cvtsound
parameter_list|(
name|int
name|ipitch
parameter_list|,
name|int
modifier|*
name|opitch
parameter_list|,
name|int
name|idur
parameter_list|,
name|int
modifier|*
name|odur
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in co_vga.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|cons_highlight
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|cons_normal
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|coattach
parameter_list|(
name|struct
name|isa_device
modifier|*
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_setcursorpos
parameter_list|(
name|int
name|pos
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_cursor
parameter_list|(
name|int
name|a
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_doblanking
parameter_list|(
name|int
name|fct
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|sput
parameter_list|(
name|int
name|vtynum
parameter_list|,
name|XCHAR
name|c
parameter_list|,
name|int
name|ka
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|consinit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_whoami
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vga_setcshape
parameter_list|(
name|struct
name|cursorshape
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vga_getcshape
parameter_list|(
name|struct
name|cursorshape
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vga_getvideoinfo
parameter_list|(
name|struct
name|videoinfo
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_enablecg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_disablecg
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vga_xlatiso646
parameter_list|(
name|struct
name|vty
modifier|*
name|vp
parameter_list|,
name|u_short
modifier|*
name|at
parameter_list|,
name|u_short
modifier|*
name|sat
parameter_list|,
name|int
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* emulator support */
end_comment

begin_function_decl
specifier|extern
name|void
name|vga_cursorup
parameter_list|(
name|struct
name|vty
modifier|*
name|vp
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_cursordown
parameter_list|(
name|struct
name|vty
modifier|*
name|vp
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_cursorleft
parameter_list|(
name|struct
name|vty
modifier|*
name|vp
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_cursorright
parameter_list|(
name|struct
name|vty
modifier|*
name|vp
parameter_list|,
name|int
name|n
parameter_list|,
name|int
name|wrap
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_scrollup
parameter_list|(
name|struct
name|vty
modifier|*
name|vp
parameter_list|,
name|int
name|n
parameter_list|,
name|int
name|cm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_scrolldown
parameter_list|(
name|struct
name|vty
modifier|*
name|vp
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_cursormove
parameter_list|(
name|struct
name|vty
modifier|*
name|vp
parameter_list|,
name|int
name|x
parameter_list|,
name|int
name|y
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_cursorrelative
parameter_list|(
name|struct
name|vty
modifier|*
name|vp
parameter_list|,
name|int
name|dx
parameter_list|,
name|int
name|dy
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_clearcursor
parameter_list|(
name|struct
name|vty
modifier|*
name|vp
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_clearline
parameter_list|(
name|struct
name|vty
modifier|*
name|vp
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_deleteline
parameter_list|(
name|struct
name|vty
modifier|*
name|vp
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_insertline
parameter_list|(
name|struct
name|vty
modifier|*
name|vp
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_deletechars
parameter_list|(
name|struct
name|vty
modifier|*
name|vp
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_insertchars
parameter_list|(
name|struct
name|vty
modifier|*
name|vp
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_setattributes
parameter_list|(
name|struct
name|vty
modifier|*
name|vp
parameter_list|,
name|int
name|mode
parameter_list|,
name|int
name|attr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_selectfont
parameter_list|(
name|struct
name|vty
modifier|*
name|vp
parameter_list|,
name|int
name|fontnr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_wrtchar
parameter_list|(
name|struct
name|vty
modifier|*
name|vp
parameter_list|,
name|u_int
name|c
parameter_list|,
name|u_int
name|at
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vga_checkcursor
parameter_list|(
name|struct
name|vty
modifier|*
name|vp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_sendchar
parameter_list|(
name|struct
name|vty
modifier|*
name|vp
parameter_list|,
name|XCHAR
name|c
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vga_initvideo
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in co_pc3.c */
end_comment

begin_function_decl
specifier|extern
name|void
name|vtemul_init
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* initialize terminal emulator */
end_comment

begin_function_decl
specifier|extern
name|void
name|vtemul_exec
parameter_list|(
name|struct
name|vty
modifier|*
parameter_list|,
name|XCHAR
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* process data */
end_comment

begin_comment
comment|/* in co_vty.c */
end_comment

begin_function_decl
specifier|extern
name|struct
name|vty
modifier|*
name|dev2vty
parameter_list|(
name|dev_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vty_init
parameter_list|(
name|int
name|first
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vty_setactive
parameter_list|(
name|int
name|vtyno
parameter_list|,
name|int
name|sw
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vty_next
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vty_previous
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|vty_broadcast
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* in co_codrv1.c/co_codrv2.c, etc. */
end_comment

begin_function_decl
specifier|extern
name|void
name|coioctl_init
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|consioctl
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|kbdioctl
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|vgaioctl
parameter_list|(
name|dev_t
name|dev
parameter_list|,
name|int
name|cmd
parameter_list|,
name|caddr_t
name|data
parameter_list|,
name|int
name|flag
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*******************************************************************  * The video console multiplexer (not yet)  ******************************************************************/
end_comment

begin_comment
comment|/* in future this will be a struct of pointers to functions, and  * will be filled by a "module_init call  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|GFX_CONSOLE
end_ifdef

begin_define
define|#
directive|define
name|emul_cursorup
value|gfx_cursorup
end_define

begin_define
define|#
directive|define
name|emul_cursordown
value|gfx_cursordown
end_define

begin_define
define|#
directive|define
name|emul_cursorleft
value|gfx_cursorleft
end_define

begin_define
define|#
directive|define
name|emul_cursorright
value|gfx_cursorright
end_define

begin_define
define|#
directive|define
name|emul_scrollup
value|gfx_scrollup
end_define

begin_define
define|#
directive|define
name|emul_scrolldown
value|gfx_scrolldown
end_define

begin_define
define|#
directive|define
name|emul_cursormove
value|gfx_cursormove
end_define

begin_define
define|#
directive|define
name|emul_cursorrelative
value|gfx_cursorrelative
end_define

begin_define
define|#
directive|define
name|emul_clearcursor
value|gfx_clearcursor
end_define

begin_define
define|#
directive|define
name|emul_clearline
value|gfx_clearline
end_define

begin_define
define|#
directive|define
name|emul_deleteline
value|gfx_deleteline
end_define

begin_define
define|#
directive|define
name|emul_insertline
value|gfx_insertline
end_define

begin_define
define|#
directive|define
name|emul_deletechars
value|gfx_deletechars
end_define

begin_define
define|#
directive|define
name|emul_insertchars
value|gfx_insertchars
end_define

begin_define
define|#
directive|define
name|emul_setattributes
value|gfx_setattributes
end_define

begin_define
define|#
directive|define
name|emul_selectfont
value|gfx_selectfont
end_define

begin_define
define|#
directive|define
name|emul_wrtchar
value|gfx_wrtchar
end_define

begin_define
define|#
directive|define
name|emul_checkcursor
value|gfx_checkcursor
end_define

begin_define
define|#
directive|define
name|emul_sendchar
value|gfx_sendchar
end_define

begin_define
define|#
directive|define
name|emul_initvideo
value|gfx_initvideo
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|emul_cursorup
value|vga_cursorup
end_define

begin_define
define|#
directive|define
name|emul_cursordown
value|vga_cursordown
end_define

begin_define
define|#
directive|define
name|emul_cursorleft
value|vga_cursorleft
end_define

begin_define
define|#
directive|define
name|emul_cursorright
value|vga_cursorright
end_define

begin_define
define|#
directive|define
name|emul_scrollup
value|vga_scrollup
end_define

begin_define
define|#
directive|define
name|emul_scrolldown
value|vga_scrolldown
end_define

begin_define
define|#
directive|define
name|emul_cursormove
value|vga_cursormove
end_define

begin_define
define|#
directive|define
name|emul_cursorrelative
value|vga_cursorrelative
end_define

begin_define
define|#
directive|define
name|emul_clearcursor
value|vga_clearcursor
end_define

begin_define
define|#
directive|define
name|emul_clearline
value|vga_clearline
end_define

begin_define
define|#
directive|define
name|emul_deleteline
value|vga_deleteline
end_define

begin_define
define|#
directive|define
name|emul_insertline
value|vga_insertline
end_define

begin_define
define|#
directive|define
name|emul_deletechars
value|vga_deletechars
end_define

begin_define
define|#
directive|define
name|emul_insertchars
value|vga_insertchars
end_define

begin_define
define|#
directive|define
name|emul_setattributes
value|vga_setattributes
end_define

begin_define
define|#
directive|define
name|emul_selectfont
value|vga_selectfont
end_define

begin_define
define|#
directive|define
name|emul_wrtchar
value|vga_wrtchar
end_define

begin_define
define|#
directive|define
name|emul_checkcursor
value|vga_checkcursor
end_define

begin_define
define|#
directive|define
name|emul_sendchar
value|vga_sendchar
end_define

begin_define
define|#
directive|define
name|emul_initvideo
value|vga_initvideo
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
comment|/* _CO_HDR_H_
end_comment

end_unit

