begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: fbdefs.h,v 4.300 91/06/09 06:33:54 root Rel41 $ SONY  *  *	@(#)fbdefs.h	7.4 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|mips
end_ifndef

begin_define
define|#
directive|define
name|volatile
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_SINGLE
end_ifdef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|news3400
argument_list|)
operator|||
name|defined
argument_list|(
name|news3700
argument_list|)
end_if

begin_define
define|#
directive|define
name|splbitmap
value|spl3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|FB_LOCK
value|lock_bitmap()
end_define

begin_define
define|#
directive|define
name|FB_UNLOCK
value|unlock_bitmap()
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CPU_SINGLE */
end_comment

begin_undef
undef|#
directive|undef
name|PRE_EMPT
end_undef

begin_define
define|#
directive|define
name|PRE_EMPT
end_define

begin_define
define|#
directive|define
name|FB_LOCK
end_define

begin_define
define|#
directive|define
name|FB_UNLOCK
end_define

begin_include
include|#
directive|include
file|<news3400/fb/fbsem.h>
end_include

begin_comment
comment|/* semaphore name */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_SINGLE */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|news3400
argument_list|)
operator|||
name|defined
argument_list|(
name|news3700
argument_list|)
end_if

begin_define
define|#
directive|define
name|WB_FLUSH
value|MachEmptyWriteBuffer()
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WB_FLUSH
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * macro to compute modulo  * 	MOD(-1, 16) --> 15  *	DIV(-1, 16) --> -1  */
end_comment

begin_define
define|#
directive|define
name|MOD
parameter_list|(
name|x
parameter_list|,
name|d
parameter_list|,
name|t
parameter_list|)
value|(((t)=(x)%(d))>=0?(t):(t)+(d))
end_define

begin_define
define|#
directive|define
name|TRUNC
parameter_list|(
name|x
parameter_list|,
name|d
parameter_list|,
name|t
parameter_list|)
value|((x)-MOD(x,d,t))
end_define

begin_define
define|#
directive|define
name|DIV
parameter_list|(
name|x
parameter_list|,
name|d
parameter_list|,
name|t
parameter_list|)
value|(((x)-MOD(x,d,t))/(d))
end_define

begin_comment
comment|/* BitsPerWord should be 2^x */
end_comment

begin_define
define|#
directive|define
name|MODWORD
parameter_list|(
name|x
parameter_list|)
value|((x)&((BitsPerWord)-1))
end_define

begin_define
define|#
directive|define
name|TRUNCWORD
parameter_list|(
name|x
parameter_list|)
value|((x)-MODWORD(x))
end_define

begin_define
define|#
directive|define
name|DIVWORD
parameter_list|(
name|x
parameter_list|)
value|(((x)-MODWORD(x))/BitsPerWord)
end_define

begin_define
define|#
directive|define
name|AllOnes
value|0xffff
end_define

begin_comment
comment|/* transparency */
end_comment

begin_define
define|#
directive|define
name|TRANS
parameter_list|(
name|t
parameter_list|,
name|f
parameter_list|)
value|((t) ? ((f)& 0x3 | 0x4) : (f))
end_define

begin_comment
comment|/*  *	color definitions  */
end_comment

begin_define
define|#
directive|define
name|MODE_1to1
value|0
end_define

begin_define
define|#
directive|define
name|MODE_1toN
value|1
end_define

begin_define
define|#
directive|define
name|MODE_Nto1
value|2
end_define

begin_define
define|#
directive|define
name|MODE_NtoN
value|3
end_define

begin_define
define|#
directive|define
name|PARALLEL
value|0
end_define

begin_define
define|#
directive|define
name|INTERNAL
value|1
end_define

begin_define
define|#
directive|define
name|NODRAW
value|0
end_define

begin_define
define|#
directive|define
name|DRAW
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
name|_mergeRopBits
block|{
name|unsigned
name|long
name|ca1
decl_stmt|,
name|cx1
decl_stmt|,
name|ca2
decl_stmt|,
name|cx2
decl_stmt|;
block|}
name|mergeRopRec
typedef|;
end_typedef

begin_decl_stmt
specifier|extern
name|mergeRopRec
name|mergeRopBits
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DoRop
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|,
name|r
parameter_list|)
define|\
value|{  \ 	switch(f) {  \ 	case BF_0: \ 		(r) = 0; break;  \ 	case BF_SDA: \ 		(r) = (s)&(d); break;  \ 	case BF_SDIA: \ 		(r) = (s)&~(d); break;  \ 	case BF_S: \ 		(r) = (s); break;  \ 	case BF_SIDA: \ 		(r) = ~(s)&(d); break;  \ 	case BF_D: \ 		(r) = (d); break;  \ 	case BF_SDX: \ 		(r) = (s)^(d); break;  \ 	case BF_SDO: \ 		(r) = (s)|(d); break;  \ 	case BF_SDOI: \ 		(r) = ~((s)|(d)); break;  \ 	case BF_SDXI: \ 		(r) = ~((s)^(d)); break;  \ 	case BF_DI: \ 		(r) = ~(d); break;  \ 	case BF_SDIO: \ 		(r) = (s)|~(d); break;  \ 	case BF_SI: \ 		(r) = ~(s); break;  \ 	case BF_SIDO: \ 		(r) = ~(s)|(d); break;  \ 	case BF_SDAI: \ 		(r) = ~((s)&(d)); break;  \ 	case BF_1: \ 		(r) = 0xffffffff; break;  \ 	}  \ }
end_define

begin_define
define|#
directive|define
name|DoMergeRop
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
define|\
value|((dst)& ((src)& _ca1 ^ _cx1) ^ ((src)& _ca2 ^ _cx2))
end_define

begin_define
define|#
directive|define
name|DoMergeRopMask
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|mask
parameter_list|)
define|\
value|((dst)& (((src)& _ca1 ^ _cx1) | ~(mask)) ^ \ 	(((src)& _ca2 ^ _cx2)& (mask)))
end_define

begin_define
define|#
directive|define
name|DoMergeFill
parameter_list|(
name|dst
parameter_list|)
value|(((dst)& (rop_and)) ^ (rop_xor))
end_define

begin_define
define|#
directive|define
name|DoMergeFillMask
parameter_list|(
name|dst
parameter_list|,
name|mask
parameter_list|)
define|\
value|(((dst)& ((rop_and) | ~(mask))) ^ ((rop_xor)& (mask)))
end_define

begin_define
define|#
directive|define
name|DoMultiRop
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
define|\
value|{ \ 	DoRop(funcs[0], src, dst, tmp0) \ 	DoRop(funcs[1], src, dst, tmp1) \ 	DoRop(funcs[2], src, dst, tmp2) \ 	DoRop(funcs[3], src, dst, tmp3) \ 	(dst) = tmp0& masks[0] | tmp1& masks[1] | \ 	    tmp2& masks[2] | tmp3& masks[3]; \ }
end_define

begin_define
define|#
directive|define
name|DoMultiRopMask
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|mask
parameter_list|)
define|\
value|{ \ 	DoRop(funcs[0], src, dst, tmp0) \ 	DoRop(funcs[1], src, dst, tmp1) \ 	DoRop(funcs[2], src, dst, tmp2) \ 	DoRop(funcs[3], src, dst, tmp3) \ 	(dst) = dst& ~(mask) | \ 	    (tmp0& masks[0] | tmp1& masks[1] | \ 		tmp2& masks[2] | tmp3& masks[3])& mask; \ }
end_define

begin_define
define|#
directive|define
name|TypeAt
parameter_list|(
name|m
parameter_list|,
name|p
parameter_list|)
value|((m)->fm_vaddr + (p) - (m)->fm_offset)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_DOUBLE
end_ifdef

begin_define
define|#
directive|define
name|_TypeAt
parameter_list|(
name|m
parameter_list|,
name|p
parameter_list|)
value|((m)->fm_addr[(p)>>CLSHIFT] + (CLOFSET&(p)))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CPU_DOUBLE */
end_comment

begin_define
define|#
directive|define
name|_TypeAt
parameter_list|(
name|m
parameter_list|,
name|p
parameter_list|)
value|((m)->fm_vaddr + (p) - (m)->fm_offset)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_DOUBLE */
end_comment

begin_define
define|#
directive|define
name|WordAt
parameter_list|(
name|m
parameter_list|,
name|p
parameter_list|)
value|(*(Word *)_TypeAt(m, p))
end_define

begin_comment
comment|/* *	Device Dependent Structure */
end_comment

begin_define
define|#
directive|define
name|MAXPLANE
value|24
end_define

begin_struct
struct|struct
name|fbdev
block|{
name|struct
name|fbdev_ops
modifier|*
name|fbbm_op
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|unit
decl_stmt|;
name|lRectangle
name|FrameRect
decl_stmt|;
name|lRectangle
name|VisRect
decl_stmt|;
name|lRectangle
name|CursorRect
decl_stmt|;
name|lRectangle
name|MaskRect
decl_stmt|;
name|lRectangle
name|SaveRect
decl_stmt|;
name|lBitmap
name|Krom_BM0
decl_stmt|;
name|lBitmap
name|Krom_BM1
decl_stmt|;
name|char
modifier|*
name|Krom_base
decl_stmt|;
name|lPoint
name|Krom_font_extent0
decl_stmt|;
name|lPoint
name|Krom_font_extent1
decl_stmt|;
name|char
name|funcvec
index|[
name|MAXPLANE
index|]
decl_stmt|;
name|int
name|Mode
decl_stmt|;
name|int
name|Pmask
decl_stmt|;
name|unsigned
name|int
name|pat
decl_stmt|;
name|char
name|func
decl_stmt|;
name|int
name|fore
decl_stmt|;
name|int
name|aux
decl_stmt|;
name|int
name|trans
decl_stmt|;
name|int
name|cache_off
decl_stmt|;
name|int
name|font_w
decl_stmt|;
name|int
name|font_h
decl_stmt|;
name|int
name|char_w
decl_stmt|;
name|int
name|char_h
decl_stmt|;
name|int
name|scr_w
decl_stmt|;
name|int
name|scr_h
decl_stmt|;
name|int
name|ch_pos
decl_stmt|;
name|int
name|ul_pos
decl_stmt|;
name|int
name|x_offset
decl_stmt|;
name|int
name|y_offset
decl_stmt|;
name|int
name|rit_m
decl_stmt|;
name|int
name|btm_m
decl_stmt|;
name|lRectangle
name|moveArea
decl_stmt|;
name|lPoint
name|size
decl_stmt|;
name|lPoint
name|hot
decl_stmt|;
name|char
name|curfuncv
index|[
name|MAXPLANE
index|]
decl_stmt|;
name|char
name|maskfuncv
index|[
name|MAXPLANE
index|]
decl_stmt|;
name|int
name|cursorSet
decl_stmt|;
name|int
name|cursorShow
decl_stmt|;
name|int
name|cursorVis
decl_stmt|;
name|lPoint
name|cursorP
decl_stmt|;
name|char
modifier|*
name|rcont_base
decl_stmt|;
name|char
modifier|*
name|rcont_reg
decl_stmt|;
name|int
name|fbNplane
decl_stmt|;
name|int
name|Colorwidth
decl_stmt|;
name|int
name|planemask
decl_stmt|;
name|int
name|Mono
decl_stmt|;
name|int
name|Dimmer
decl_stmt|;
name|int
name|DispVer
decl_stmt|;
name|unsigned
name|short
name|status_flag
decl_stmt|;
name|unsigned
name|short
name|run_flag
decl_stmt|;
name|char
modifier|*
name|private
decl_stmt|;
name|int
name|hard_cursor
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|CPU_SINGLE
end_ifdef

begin_struct
struct|struct
name|mfbdev
block|{
name|char
modifier|*
name|vram_start
decl_stmt|;
name|int
name|vram_width
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CPU_SINGLE */
end_comment

begin_struct
struct|struct
name|fbdev_ops
block|{
name|void
function_decl|(
modifier|*
name|fb_rop_init
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|fb_rop_copy
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|fb_rop_winit
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|fb_rop_write
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|fb_rop_read
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|fb_rop_cinit
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|fb_rop_clear
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|fb_rop_vect
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|fb_rop_dot
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|fb_rop_fillscan
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|fb_rop_wait
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|fb_rop_reset
function_decl|)
parameter_list|()
function_decl|;
name|char
modifier|*
function_decl|(
modifier|*
name|fb_Krom_addr
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|fb_init_palette
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fb_set_palette
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fb_get_palette
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fb_get_pixel
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fb_set_dimmer
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fb_get_dimmer
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fb_open
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fb_close
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fb_ioctl
function_decl|)
parameter_list|()
function_decl|;
name|int
function_decl|(
modifier|*
name|fb_get_page
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|fb_cursor_set
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|fb_cursor_on
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|fb_cursor_off
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|fb_cursor_move
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|autodev
block|{
name|int
name|type
decl_stmt|;
name|char
modifier|*
name|base
decl_stmt|;
name|char
modifier|*
name|reg
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fbdevsw
block|{
name|int
name|num
decl_stmt|;
name|int
function_decl|(
modifier|*
name|fb_probe
function_decl|)
parameter_list|()
function_decl|;
name|void
function_decl|(
modifier|*
name|fb_setup
function_decl|)
parameter_list|()
function_decl|;
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|autodev
name|autodev
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fbdev
name|fbdev
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|nfbdev
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|struct
name|fbdev
modifier|*
name|consfb
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|fb_color_pallet_def
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|fb_gray_pallet_def
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*	fb_ioctl Command	*/
end_comment

begin_define
define|#
directive|define
name|FB_INTCHECK
value|1
end_define

begin_define
define|#
directive|define
name|FB_INTCLEAR
value|2
end_define

begin_define
define|#
directive|define
name|FB_INTENABLE
value|3
end_define

begin_define
define|#
directive|define
name|FB_STATUSCHECK
value|4
end_define

begin_define
define|#
directive|define
name|FB_SETVIDEOCTL
value|10
end_define

begin_define
define|#
directive|define
name|FB_GETVIDEOSTATUS
value|11
end_define

begin_define
define|#
directive|define
name|FB_SETPALETTEMODE
value|12
end_define

begin_define
define|#
directive|define
name|FB_GETPALETTEMODE
value|13
end_define

begin_define
define|#
directive|define
name|FB_INT_VSYNC
value|1
end_define

begin_define
define|#
directive|define
name|FB_INT_ROPDONE
value|2
end_define

begin_define
define|#
directive|define
name|FB_STATUS_ROPEXEC
value|4
end_define

begin_define
define|#
directive|define
name|FB_STATUS_ROPWAIT
value|8
end_define

begin_define
define|#
directive|define
name|FB_STATUS_ROPVSYNC
value|16
end_define

begin_comment
comment|/*	run_flag	*/
end_comment

begin_define
define|#
directive|define
name|FB_ACTIVE
value|1
end_define

begin_define
define|#
directive|define
name|FB_WAITING
value|2
end_define

begin_define
define|#
directive|define
name|FB_DONE
value|4
end_define

begin_comment
comment|/* *	Pseudo Frame Buffer  *	 *	unit no *	   0		Console Device and old Interface (/dev/fb) *	   1		B/W Display and New Interface	(/dev/mfb) *	   2		Color Display and New Interface	(/dev/cfb) * */
end_comment

begin_define
define|#
directive|define
name|fbbm_rop_init
parameter_list|(
name|fb
parameter_list|,
name|func
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_rop_init)(fb, func)
end_define

begin_define
define|#
directive|define
name|fbbm_rop_copy
parameter_list|(
name|fb
parameter_list|,
name|s
parameter_list|,
name|d
parameter_list|,
name|rp
parameter_list|,
name|wp
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_rop_copy)(fb, s, d, rp, wp)
end_define

begin_define
define|#
directive|define
name|fbbm_rop_winit
parameter_list|(
name|fb
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_rop_winit)(fb)
end_define

begin_define
define|#
directive|define
name|fbbm_rop_write
parameter_list|(
name|fb
parameter_list|,
name|map
parameter_list|,
name|p
parameter_list|,
name|width
parameter_list|,
name|srp
parameter_list|,
name|drp
parameter_list|,
name|wplane
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_rop_write)(fb, map, p, width, srp, drp, wplane)
end_define

begin_define
define|#
directive|define
name|fbbm_rop_read
parameter_list|(
name|fb
parameter_list|,
name|map
parameter_list|,
name|p
parameter_list|,
name|width
parameter_list|,
name|srp
parameter_list|,
name|drp
parameter_list|,
name|rplane
parameter_list|,
name|wplane
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_rop_read)(fb, map, p, width, srp, drp, rplane, wplane)
end_define

begin_define
define|#
directive|define
name|fbbm_rop_cinit
parameter_list|(
name|fb
parameter_list|,
name|wplane
parameter_list|,
name|bw
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_rop_cinit)(fb, wplane, bw)
end_define

begin_define
define|#
directive|define
name|fbbm_rop_clear
parameter_list|(
name|fb
parameter_list|,
name|dr
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_rop_clear)(fb, dr)
end_define

begin_define
define|#
directive|define
name|fbbm_rop_vect
parameter_list|(
name|fb
parameter_list|,
name|dr
parameter_list|,
name|func
parameter_list|,
name|forc
parameter_list|,
name|auxc
parameter_list|,
name|transp
parameter_list|,
name|wplane
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|,
name|lptn
parameter_list|,
name|lpf
parameter_list|,
name|sw
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_rop_vect)(fb, dr, func, forc, auxc, transp, wplane, n, p, lptn, lpf, sw)
end_define

begin_define
define|#
directive|define
name|fbbm_rop_dot
parameter_list|(
name|fb
parameter_list|,
name|dr
parameter_list|,
name|func
parameter_list|,
name|forc
parameter_list|,
name|auxc
parameter_list|,
name|transp
parameter_list|,
name|wplane
parameter_list|,
name|n
parameter_list|,
name|p
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_rop_dot)(fb, dr, func, forc, auxc, transp, wplane, n, p)
end_define

begin_define
define|#
directive|define
name|fbbm_rop_fillscan
parameter_list|(
name|fb
parameter_list|,
name|ls
parameter_list|,
name|ns
parameter_list|,
name|clip
parameter_list|,
name|sw
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_rop_fillscan)(fb, ls, ns, clip, sw)
end_define

begin_define
define|#
directive|define
name|fbbm_Krom_addr
parameter_list|(
name|fb
parameter_list|,
name|c
parameter_list|,
name|sr
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_Krom_addr)(fb, c, sr)
end_define

begin_define
define|#
directive|define
name|fbbm_rop_wait
parameter_list|(
name|fb
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_rop_wait)(fb)
end_define

begin_define
define|#
directive|define
name|fbbm_rop_reset
parameter_list|(
name|fb
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_rop_reset)(fb)
end_define

begin_define
define|#
directive|define
name|fbbm_init_palette
parameter_list|(
name|fb
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_init_palette)(fb)
end_define

begin_define
define|#
directive|define
name|fbbm_set_palette
parameter_list|(
name|fb
parameter_list|,
name|palette
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_set_palette)(fb, palette)
end_define

begin_define
define|#
directive|define
name|fbbm_get_palette
parameter_list|(
name|fb
parameter_list|,
name|palette
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_get_palette)(fb, palette)
end_define

begin_define
define|#
directive|define
name|fbbm_get_pixel
parameter_list|(
name|fb
parameter_list|,
name|pixel
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_get_pixel)(fb, pixel)
end_define

begin_define
define|#
directive|define
name|fbbm_set_dimmer
parameter_list|(
name|fb
parameter_list|,
name|n
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_set_dimmer)(fb, n)
end_define

begin_define
define|#
directive|define
name|fbbm_get_dimmer
parameter_list|(
name|fb
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_get_dimmer)(fb)
end_define

begin_define
define|#
directive|define
name|fbbm_open
parameter_list|(
name|fb
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_open)(fb)
end_define

begin_define
define|#
directive|define
name|fbbm_close
parameter_list|(
name|fb
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_close)(fb)
end_define

begin_define
define|#
directive|define
name|fbbm_ioctl
parameter_list|(
name|fb
parameter_list|,
name|cmd
parameter_list|,
name|data
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_ioctl)(fb, cmd, data)
end_define

begin_define
define|#
directive|define
name|fbbm_get_page
parameter_list|(
name|fb
parameter_list|,
name|off
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_get_page)(fb, off)
end_define

begin_define
define|#
directive|define
name|fbbm_cursor_set
parameter_list|(
name|fb
parameter_list|,
name|fc
parameter_list|,
name|bc
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_cursor_set)(fb, fc, bc)
end_define

begin_define
define|#
directive|define
name|fbbm_cursor_on
parameter_list|(
name|fb
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_cursor_on)(fb)
end_define

begin_define
define|#
directive|define
name|fbbm_cursor_off
parameter_list|(
name|fb
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_cursor_off)(fb)
end_define

begin_define
define|#
directive|define
name|fbbm_cursor_move
parameter_list|(
name|fb
parameter_list|)
define|\
value|(*(fb)->fbbm_op->fb_cursor_move)(fb)
end_define

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|mfbstarttab16
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|mfbendtab16
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|mfbpartmasks16
index|[
literal|16
index|]
index|[
literal|16
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|mfbstarttab32
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|mfbendtab32
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|int
name|mfbpartmasks32
index|[
literal|32
index|]
index|[
literal|32
index|]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|void
name|mfb_copy_area32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_copyinv_area32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_or_area32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_xor_area32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_general_area32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_clr_area32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_inv_area32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_set_area32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_copy_area16
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_copyinv_area16
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_or_area16
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_xor_area16
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_general_area16
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_clr_area16
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_inv_area16
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_set_area16
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_clrvvector32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_clrhvector32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_clrvector32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_invvvector32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_invhvector32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_invvector32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_setvvector32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_sethvector32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_setvector32
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_point
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|mfb_vector32
parameter_list|()
function_decl|;
end_function_decl

end_unit

