begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * TEGblt - ImageText expanded glyph fonts only.  For  * 8 bit displays, in Copy mode with no clipping.  */
end_comment

begin_comment
comment|/* Copyright 1989 by the Massachusetts Institute of Technology  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_comment
comment|/* $XConsortium: cfbteblt8.c,v 5.14 91/04/10 11:41:38 keith Exp $ */
end_comment

begin_include
include|#
directive|include
file|"X.h"
end_include

begin_include
include|#
directive|include
file|"Xmd.h"
end_include

begin_include
include|#
directive|include
file|"Xproto.h"
end_include

begin_include
include|#
directive|include
file|"cfb.h"
end_include

begin_include
include|#
directive|include
file|"fontstruct.h"
end_include

begin_include
include|#
directive|include
file|"dixfontstr.h"
end_include

begin_include
include|#
directive|include
file|"gcstruct.h"
end_include

begin_include
include|#
directive|include
file|"windowstr.h"
end_include

begin_include
include|#
directive|include
file|"scrnintstr.h"
end_include

begin_include
include|#
directive|include
file|"pixmapstr.h"
end_include

begin_include
include|#
directive|include
file|"regionstr.h"
end_include

begin_include
include|#
directive|include
file|"cfbmskbits.h"
end_include

begin_include
include|#
directive|include
file|"cfb8bit.h"
end_include

begin_if
if|#
directive|if
operator|(
name|PPW
operator|==
literal|4
operator|)
end_if

begin_comment
comment|/*  * this code supports up to 5 characters at a time.  The performance  * differences between 4 and 5 is usually small (~7% on PMAX) and  * frequently negative (SPARC and Sun3), so this file is compiled  * only once for now.  If you want to use the other options, you'll  * need to hack cfbgc.c as well.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NGLYPHS
end_ifndef

begin_define
define|#
directive|define
name|NGLYPHS
value|4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NGLYPHS
operator|==
literal|4
end_if

begin_define
define|#
directive|define
name|DO_COMMON
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|DO_COMMON
end_ifdef

begin_define
define|#
directive|define
name|CFBTEGBLT8
value|cfbTEGlyphBlt8
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * On little-endian machines (or where fonts are padded to 32-bit  * boundaries) we can use some magic to avoid the expense of getleftbits  */
end_comment

begin_if
if|#
directive|if
operator|(
operator|(
name|BITMAP_BIT_ORDER
operator|==
name|LSBFirst
operator|&&
name|NGLYPHS
operator|>=
literal|4
operator|)
operator|||
name|GLYPHPADBYTES
operator|==
literal|4
operator|)
end_if

begin_if
if|#
directive|if
name|GLYPHPADBYTES
operator|==
literal|1
end_if

begin_typedef
typedef|typedef
name|unsigned
name|char
modifier|*
name|glyphPointer
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USE_LEFTBITS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GLYPHPADBYTES
operator|==
literal|2
end_if

begin_typedef
typedef|typedef
name|unsigned
name|short
modifier|*
name|glyphPointer
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USE_LEFTBITS
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|GLYPHPADBYTES
operator|==
literal|4
end_if

begin_typedef
typedef|typedef
name|unsigned
name|int
modifier|*
name|glyphPointer
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|GetBitsL
value|c = BitLeft (*leftChar++, lshift)
end_define

begin_define
define|#
directive|define
name|GetBits1S
value|c = BitRight(*char1++, xoff1)
end_define

begin_define
define|#
directive|define
name|GetBits1L
value|GetBitsL | BitRight(*char1++, xoff1)
end_define

begin_define
define|#
directive|define
name|GetBits1U
value|c = *char1++
end_define

begin_define
define|#
directive|define
name|GetBits2S
value|GetBits1S | BitRight(*char2++, xoff2)
end_define

begin_define
define|#
directive|define
name|GetBits2L
value|GetBits1L | BitRight(*char2++, xoff2)
end_define

begin_define
define|#
directive|define
name|GetBits2U
value|GetBits1U | BitRight(*char2++, xoff2)
end_define

begin_define
define|#
directive|define
name|GetBits3S
value|GetBits2S | BitRight(*char3++, xoff3)
end_define

begin_define
define|#
directive|define
name|GetBits3L
value|GetBits2L | BitRight(*char3++, xoff3)
end_define

begin_define
define|#
directive|define
name|GetBits3U
value|GetBits2U | BitRight(*char3++, xoff3)
end_define

begin_define
define|#
directive|define
name|GetBits4S
value|GetBits3S | BitRight(*char4++, xoff4)
end_define

begin_define
define|#
directive|define
name|GetBits4L
value|GetBits3L | BitRight(*char4++, xoff4)
end_define

begin_define
define|#
directive|define
name|GetBits4U
value|GetBits3U | BitRight(*char4++, xoff4)
end_define

begin_define
define|#
directive|define
name|GetBits5S
value|GetBits4S | BitRight(*char5++, xoff5)
end_define

begin_define
define|#
directive|define
name|GetBits5L
value|GetBits4L | BitRight(*char5++, xoff5)
end_define

begin_define
define|#
directive|define
name|GetBits5U
value|GetBits4U | BitRight(*char5++, xoff5)
end_define

begin_else
else|#
directive|else
end_else

begin_typedef
typedef|typedef
name|unsigned
name|char
modifier|*
name|glyphPointer
typedef|;
end_typedef

begin_define
define|#
directive|define
name|USE_LEFTBITS
end_define

begin_define
define|#
directive|define
name|GetBitsL
value|WGetBitsL
end_define

begin_define
define|#
directive|define
name|GetBits1S
value|WGetBits1S
end_define

begin_define
define|#
directive|define
name|GetBits1L
value|WGetBits1L
end_define

begin_define
define|#
directive|define
name|GetBits1U
value|WGetBits1U
end_define

begin_define
define|#
directive|define
name|GetBits2S
value|GetBits1S Get1Bits (char2, tmpSrc) \ 		    c |= BitRight(tmpSrc, xoff2);
end_define

begin_define
define|#
directive|define
name|GetBits2L
value|GetBits1L Get1Bits (char2, tmpSrc) \ 		    c |= BitRight(tmpSrc, xoff2);
end_define

begin_define
define|#
directive|define
name|GetBits2U
value|GetBits1U Get1Bits (char2, tmpSrc) \ 		    c |= BitRight(tmpSrc, xoff2);
end_define

begin_define
define|#
directive|define
name|GetBits3S
value|GetBits2S Get1Bits (char3, tmpSrc) \ 		    c |= BitRight(tmpSrc, xoff3);
end_define

begin_define
define|#
directive|define
name|GetBits3L
value|GetBits2L Get1Bits (char3, tmpSrc) \ 		    c |= BitRight(tmpSrc, xoff3);
end_define

begin_define
define|#
directive|define
name|GetBits3U
value|GetBits2U Get1Bits (char3, tmpSrc) \ 		    c |= BitRight(tmpSrc, xoff3);
end_define

begin_define
define|#
directive|define
name|GetBits4S
value|GetBits3S Get1Bits (char4, tmpSrc) \ 		    c |= BitRight(tmpSrc, xoff4);
end_define

begin_define
define|#
directive|define
name|GetBits4L
value|GetBits3L Get1Bits (char4, tmpSrc) \ 		    c |= BitRight(tmpSrc, xoff4);
end_define

begin_define
define|#
directive|define
name|GetBits4U
value|GetBits3U Get1Bits (char4, tmpSrc) \ 		    c |= BitRight(tmpSrc, xoff4);
end_define

begin_define
define|#
directive|define
name|GetBits5S
value|GetBits4S Get1Bits (char5, tmpSrc) \ 		    c |= BitRight(tmpSrc, xoff5);
end_define

begin_define
define|#
directive|define
name|GetBits5L
value|GetBits4L Get1Bits (char5, tmpSrc) \ 		    c |= BitRight(tmpSrc, xoff5);
end_define

begin_define
define|#
directive|define
name|GetBits5U
value|GetBits4U Get1Bits (char5, tmpSrc) \ 		    c |= BitRight(tmpSrc, xoff5);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|USE_LEFTBITS
end_ifdef

begin_decl_stmt
specifier|extern
name|long
name|endtab
index|[]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|IncChar
parameter_list|(
name|c
parameter_list|)
value|(c = (glyphPointer) (((char *) c) + glyphBytes))
end_define

begin_define
define|#
directive|define
name|Get1Bits
parameter_list|(
name|ch
parameter_list|,
name|dst
parameter_list|)
value|glyphbits (ch, widthGlyph, glyphMask, dst); \ 			    IncChar (ch);
end_define

begin_define
define|#
directive|define
name|glyphbits
parameter_list|(
name|bits
parameter_list|,
name|width
parameter_list|,
name|mask
parameter_list|,
name|dst
parameter_list|)
value|getleftbits(bits,width,dst); \ 					dst&= mask;
end_define

begin_define
define|#
directive|define
name|WGetBitsL
value|Get1Bits(leftChar,c); \ 		    c = BitLeft (c, lshift);
end_define

begin_define
define|#
directive|define
name|WGetBits1S
value|Get1Bits (char1, c) \ 		    c = BitRight (c, xoff1);
end_define

begin_define
define|#
directive|define
name|WGetBits1L
value|WGetBitsL Get1Bits (char1, tmpSrc) \ 		    c |= BitRight (tmpSrc, xoff1);
end_define

begin_define
define|#
directive|define
name|WGetBits1U
value|Get1Bits (char1, c)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|WGetBitsL
value|GetBitsL
end_define

begin_define
define|#
directive|define
name|WGetBits1S
value|GetBits1S
end_define

begin_define
define|#
directive|define
name|WGetBits1L
value|GetBits1L
end_define

begin_define
define|#
directive|define
name|WGetBits1U
value|GetBits1U
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NGLYPHS
operator|==
literal|2
end_if

begin_define
define|#
directive|define
name|GetBitsNS
value|GetBits2S
end_define

begin_define
define|#
directive|define
name|GetBitsNL
value|GetBits2L
end_define

begin_define
define|#
directive|define
name|GetBitsNU
value|GetBits2U
end_define

begin_define
define|#
directive|define
name|LastChar
value|char2
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CFBTEGBLT8
end_ifndef

begin_define
define|#
directive|define
name|CFBTEGBLT8
value|cfbTEGlyphBlt8x2
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NGLYPHS
operator|==
literal|3
end_if

begin_define
define|#
directive|define
name|GetBitsNS
value|GetBits3S
end_define

begin_define
define|#
directive|define
name|GetBitsNL
value|GetBits3L
end_define

begin_define
define|#
directive|define
name|GetBitsNU
value|GetBits3U
end_define

begin_define
define|#
directive|define
name|LastChar
value|char3
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CFBTEGBLT8
end_ifndef

begin_define
define|#
directive|define
name|CFBTEGBLT8
value|cfbTEGlyphBlt8x3
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NGLYPHS
operator|==
literal|4
end_if

begin_define
define|#
directive|define
name|GetBitsNS
value|GetBits4S
end_define

begin_define
define|#
directive|define
name|GetBitsNL
value|GetBits4L
end_define

begin_define
define|#
directive|define
name|GetBitsNU
value|GetBits4U
end_define

begin_define
define|#
directive|define
name|LastChar
value|char4
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CFBTEGBLT8
end_ifndef

begin_define
define|#
directive|define
name|CFBTEGBLT8
value|cfbTEGlyphBlt8x4
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|NGLYPHS
operator|==
literal|5
end_if

begin_define
define|#
directive|define
name|GetBitsNS
value|GetBits5S
end_define

begin_define
define|#
directive|define
name|GetBitsNL
value|GetBits5L
end_define

begin_define
define|#
directive|define
name|GetBitsNU
value|GetBits5U
end_define

begin_define
define|#
directive|define
name|LastChar
value|char5
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|CFBTEGBLT8
end_ifndef

begin_define
define|#
directive|define
name|CFBTEGBLT8
value|cfbTEGlyphBlt8x5
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
comment|/* another ugly giant macro */
end_comment

begin_define
define|#
directive|define
name|SwitchEm
value|switch (ew) \ 		    { \ 		    case 0: \ 		    	break; \ 		    case 1: \ 		    	while (hTmp--) { \ 			    GetBits; \ 			    StoreBits0 \ 			    Loop \ 		    	} \ 		    	break; \ 		    case 2: \ 		    	while (hTmp--) { \ 			    GetBits; \ 			    StoreBits0 FirstStep StoreBits(1) \ 			    Loop \ 		    	} \ 		    	break; \ 		    case 3: \ 		    	while (hTmp--) { \ 			    GetBits; \ 			    StoreBits0 FirstStep StoreBits(1) Step StoreBits(2) \ 			    Loop \ 		    	} \ 		    	break; \ 		    case 4: \ 		    	while (hTmp--) { \ 			    GetBits; \ 			    StoreBits0 FirstStep StoreBits(1) Step \ 			    StoreBits(2) Step StoreBits(3) \ 			    Loop \ 		    	} \ 		    	break; \ 		    case 5: \ 		    	while (hTmp--) { \ 			    GetBits; \ 			    StoreBits0 FirstStep StoreBits(1) Step \ 			    StoreBits(2) Step StoreBits(3) Step \ 			    StoreBits(4) \ 			    Loop \ 		    	} \ 		    	break; \ 		    case 6: \ 		    	while (hTmp--) { \ 			    GetBits; \ 			    StoreBits0 FirstStep StoreBits(1) Step \  			    StoreBits(2) Step StoreBits(3) Step \ 			    StoreBits(4) Step StoreBits(5) \ 			    Loop \ 		    	} \ 		    	break; \ 		    case 7: \ 		    	while (hTmp--) { \ 			    GetBits; \ 			    StoreBits0 FirstStep StoreBits(1) Step \ 			    StoreBits(2) Step StoreBits(3) Step \ 			    StoreBits(4) Step StoreBits(5) Step \ 			    StoreBits(6) \ 			    Loop \ 		    	} \ 		    	break; \ 		    case 8: \ 		    	while (hTmp--) { \ 			    GetBits; \ 			    StoreBits0 FirstStep StoreBits(1) Step \ 			    StoreBits(2) Step StoreBits(3) Step \ 			    StoreBits(4) Step StoreBits(5) Step \ 			    StoreBits(6) Step StoreBits(7) \ 			    Loop \ 		    	} \ 		    	break; \ 		    }
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|FAST_CONSTANT_OFFSET_MODE
end_ifdef

begin_define
define|#
directive|define
name|StorePixels
parameter_list|(
name|o
parameter_list|,
name|p
parameter_list|)
value|dst[o] = p
end_define

begin_define
define|#
directive|define
name|Loop
value|dst += widthDst;
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|StorePixels
parameter_list|(
name|o
parameter_list|,
name|p
parameter_list|)
value|*dst++ = (p)
end_define

begin_define
define|#
directive|define
name|Loop
value|dst += widthLeft;
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|Step
value|NextFourBits(c);
end_define

begin_if
if|#
directive|if
operator|(
name|BITMAP_BIT_ORDER
operator|==
name|MSBFirst
operator|)
end_if

begin_define
define|#
directive|define
name|StoreBits
parameter_list|(
name|o
parameter_list|)
value|StorePixels(o,GetFourPixels(c));
end_define

begin_define
define|#
directive|define
name|FirstStep
value|Step
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|StoreBits
parameter_list|(
name|o
parameter_list|)
value|StorePixels(o,*((unsigned long *) (((char *) cfb8Pixels) + (c& 0x3c))));
end_define

begin_define
define|#
directive|define
name|FirstStep
value|c = BitLeft (c, 2);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|cfbImageGlyphBlt8
parameter_list|()
function_decl|;
end_function_decl

begin_function
name|void
name|CFBTEGBLT8
parameter_list|(
name|pDrawable
parameter_list|,
name|pGC
parameter_list|,
name|xInit
parameter_list|,
name|yInit
parameter_list|,
name|nglyph
parameter_list|,
name|ppci
parameter_list|,
name|pglyphBase
parameter_list|)
name|DrawablePtr
name|pDrawable
decl_stmt|;
name|GC
modifier|*
name|pGC
decl_stmt|;
name|int
name|xInit
decl_stmt|,
name|yInit
decl_stmt|;
name|unsigned
name|int
name|nglyph
decl_stmt|;
name|CharInfoPtr
modifier|*
name|ppci
decl_stmt|;
comment|/* array of character info */
name|unsigned
name|char
modifier|*
name|pglyphBase
decl_stmt|;
comment|/* start of array of glyphs */
block|{
specifier|register
name|unsigned
name|long
name|c
decl_stmt|;
specifier|register
name|unsigned
name|long
modifier|*
name|dst
decl_stmt|;
specifier|register
name|unsigned
name|long
name|leftMask
decl_stmt|,
name|rightMask
decl_stmt|;
specifier|register
name|int
name|hTmp
decl_stmt|;
specifier|register
name|int
name|xoff1
decl_stmt|;
specifier|register
name|int
name|xoff2
decl_stmt|;
if|#
directive|if
name|NGLYPHS
operator|>=
literal|3
specifier|register
name|int
name|xoff3
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|NGLYPHS
operator|>=
literal|4
specifier|register
name|int
name|xoff4
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|NGLYPHS
operator|>=
literal|5
specifier|register
name|int
name|xoff5
decl_stmt|;
endif|#
directive|endif
specifier|register
name|glyphPointer
name|char1
decl_stmt|;
specifier|register
name|glyphPointer
name|char2
decl_stmt|;
if|#
directive|if
name|NGLYPHS
operator|>=
literal|3
specifier|register
name|glyphPointer
name|char3
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|NGLYPHS
operator|>=
literal|4
specifier|register
name|glyphPointer
name|char4
decl_stmt|;
endif|#
directive|endif
if|#
directive|if
name|NGLYPHS
operator|>=
literal|5
specifier|register
name|glyphPointer
name|char5
decl_stmt|;
endif|#
directive|endif
name|FontPtr
name|pfont
init|=
name|pGC
operator|->
name|font
decl_stmt|;
name|unsigned
name|long
modifier|*
name|dstLine
decl_stmt|;
name|glyphPointer
name|oldRightChar
decl_stmt|;
name|unsigned
name|long
modifier|*
name|pdstBase
decl_stmt|;
name|glyphPointer
name|leftChar
decl_stmt|;
name|int
name|widthDst
decl_stmt|,
name|widthLeft
decl_stmt|;
name|int
name|widthGlyph
decl_stmt|;
name|int
name|h
decl_stmt|;
name|int
name|ew
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|BoxRec
name|bbox
decl_stmt|;
comment|/* for clipping */
name|int
name|lshift
decl_stmt|;
name|int
name|widthGlyphs
decl_stmt|;
ifdef|#
directive|ifdef
name|USE_LEFTBITS
specifier|register
name|int
name|glyphMask
decl_stmt|;
specifier|register
name|unsigned
name|int
name|tmpSrc
decl_stmt|;
specifier|register
name|int
name|glyphBytes
decl_stmt|;
endif|#
directive|endif
name|widthGlyph
operator|=
name|FONTMAXBOUNDS
argument_list|(
name|pfont
argument_list|,
name|characterWidth
argument_list|)
expr_stmt|;
name|h
operator|=
name|FONTASCENT
argument_list|(
name|pfont
argument_list|)
operator|+
name|FONTDESCENT
argument_list|(
name|pfont
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
name|h
condition|)
return|return;
name|x
operator|=
name|xInit
operator|+
name|FONTMAXBOUNDS
argument_list|(
name|pfont
argument_list|,
name|leftSideBearing
argument_list|)
operator|+
name|pDrawable
operator|->
name|x
expr_stmt|;
name|y
operator|=
name|yInit
operator|-
name|FONTASCENT
argument_list|(
name|pfont
argument_list|)
operator|+
name|pDrawable
operator|->
name|y
expr_stmt|;
name|bbox
operator|.
name|x1
operator|=
name|x
expr_stmt|;
name|bbox
operator|.
name|x2
operator|=
name|x
operator|+
operator|(
name|widthGlyph
operator|*
name|nglyph
operator|)
expr_stmt|;
name|bbox
operator|.
name|y1
operator|=
name|y
expr_stmt|;
name|bbox
operator|.
name|y2
operator|=
name|y
operator|+
name|h
expr_stmt|;
switch|switch
condition|(
call|(
modifier|*
name|pGC
operator|->
name|pScreen
operator|->
name|RectIn
call|)
argument_list|(
operator|(
operator|(
name|cfbPrivGC
operator|*
operator|)
operator|(
name|pGC
operator|->
name|devPrivates
index|[
name|cfbGCPrivateIndex
index|]
operator|.
name|ptr
operator|)
operator|)
operator|->
name|pCompositeClip
argument_list|,
operator|&
name|bbox
argument_list|)
condition|)
block|{
case|case
name|rgnPART
case|:
name|cfbImageGlyphBlt8
argument_list|(
name|pDrawable
argument_list|,
name|pGC
argument_list|,
name|xInit
argument_list|,
name|yInit
argument_list|,
name|nglyph
argument_list|,
name|ppci
argument_list|,
name|pglyphBase
argument_list|)
expr_stmt|;
case|case
name|rgnOUT
case|:
return|return;
block|}
if|if
condition|(
operator|!
name|cfb8CheckPixels
argument_list|(
name|pGC
operator|->
name|fgPixel
argument_list|,
name|pGC
operator|->
name|bgPixel
argument_list|)
condition|)
name|cfb8SetPixels
argument_list|(
name|pGC
operator|->
name|fgPixel
argument_list|,
name|pGC
operator|->
name|bgPixel
argument_list|)
expr_stmt|;
name|leftChar
operator|=
literal|0
expr_stmt|;
name|cfbGetLongWidthAndPointer
argument_list|(
argument|pDrawable
argument_list|,
argument|widthDst
argument_list|,
argument|pdstBase
argument_list|)
if|#
directive|if
name|NGLYPHS
operator|==
literal|2
name|widthGlyphs
operator|=
name|widthGlyph
operator|<<
literal|1
expr_stmt|;
else|#
directive|else
if|#
directive|if
name|NGLYPHS
operator|==
literal|4
name|widthGlyphs
operator|=
name|widthGlyph
operator|<<
literal|2
expr_stmt|;
else|#
directive|else
name|widthGlyphs
operator|=
name|widthGlyph
operator|*
name|NGLYPHS
expr_stmt|;
endif|#
directive|endif
endif|#
directive|endif
ifdef|#
directive|ifdef
name|USE_LEFTBITS
name|glyphMask
operator|=
name|endtab
index|[
name|widthGlyph
index|]
expr_stmt|;
name|glyphBytes
operator|=
name|GLYPHWIDTHBYTESPADDED
argument_list|(
operator|*
name|ppci
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|SET_REGISTERS_FOR_WRITING
argument_list|(
name|pDrawable
operator|->
name|pScreen
argument_list|,
operator|~
literal|0
argument_list|,
name|GXcopy
argument_list|)
expr_stmt|;
name|pdstBase
operator|+=
name|y
operator|*
name|widthDst
expr_stmt|;
ifdef|#
directive|ifdef
name|DO_COMMON
if|if
condition|(
name|widthGlyphs
operator|<=
literal|32
condition|)
endif|#
directive|endif
while|while
condition|(
name|nglyph
operator|>=
name|NGLYPHS
condition|)
block|{
name|nglyph
operator|-=
name|NGLYPHS
expr_stmt|;
name|hTmp
operator|=
name|h
expr_stmt|;
name|dstLine
operator|=
name|pdstBase
operator|+
operator|(
name|x
operator|>>
literal|2
operator|)
expr_stmt|;
name|xoff1
operator|=
name|x
operator|&
literal|0x3
expr_stmt|;
name|xoff2
operator|=
name|xoff1
operator|+
name|widthGlyph
expr_stmt|;
if|#
directive|if
name|NGLYPHS
operator|>=
literal|3
name|xoff3
operator|=
name|xoff2
operator|+
name|widthGlyph
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|NGLYPHS
operator|>=
literal|4
name|xoff4
operator|=
name|xoff3
operator|+
name|widthGlyph
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|NGLYPHS
operator|>=
literal|5
name|xoff5
operator|=
name|xoff4
operator|+
name|widthGlyph
expr_stmt|;
endif|#
directive|endif
name|char1
operator|=
operator|(
name|glyphPointer
operator|)
name|FONTGLYPHBITS
argument_list|(
name|pglyphBase
argument_list|,
operator|*
name|ppci
operator|++
argument_list|)
expr_stmt|;
name|char2
operator|=
operator|(
name|glyphPointer
operator|)
name|FONTGLYPHBITS
argument_list|(
name|pglyphBase
argument_list|,
operator|*
name|ppci
operator|++
argument_list|)
expr_stmt|;
if|#
directive|if
name|NGLYPHS
operator|>=
literal|3
name|char3
operator|=
operator|(
name|glyphPointer
operator|)
name|FONTGLYPHBITS
argument_list|(
name|pglyphBase
argument_list|,
operator|*
name|ppci
operator|++
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|NGLYPHS
operator|>=
literal|4
name|char4
operator|=
operator|(
name|glyphPointer
operator|)
name|FONTGLYPHBITS
argument_list|(
name|pglyphBase
argument_list|,
operator|*
name|ppci
operator|++
argument_list|)
expr_stmt|;
endif|#
directive|endif
if|#
directive|if
name|NGLYPHS
operator|>=
literal|5
name|char5
operator|=
operator|(
name|glyphPointer
operator|)
name|FONTGLYPHBITS
argument_list|(
name|pglyphBase
argument_list|,
operator|*
name|ppci
operator|++
argument_list|)
expr_stmt|;
endif|#
directive|endif
name|oldRightChar
operator|=
name|LastChar
expr_stmt|;
name|dst
operator|=
name|dstLine
expr_stmt|;
if|if
condition|(
name|xoff1
condition|)
block|{
name|ew
operator|=
operator|(
operator|(
name|widthGlyphs
operator|-
operator|(
literal|4
operator|-
name|xoff1
operator|)
operator|)
operator|>>
literal|2
operator|)
operator|+
literal|1
expr_stmt|;
ifndef|#
directive|ifndef
name|FAST_CONSTANT_OFFSET_MODE
name|widthLeft
operator|=
name|widthDst
operator|-
name|ew
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|leftChar
condition|)
block|{
name|leftMask
operator|=
name|cfbendtab
index|[
name|xoff1
index|]
expr_stmt|;
name|rightMask
operator|=
name|cfbstarttab
index|[
name|xoff1
index|]
expr_stmt|;
define|#
directive|define
name|StoreBits0
value|StorePixels (0,dst[0]& leftMask | \ 				       GetFourPixels(c)& rightMask);
define|#
directive|define
name|GetBits
value|GetBitsNS
name|SwitchEm
undef|#
directive|undef
name|GetBits
undef|#
directive|undef
name|StoreBits0
block|}
else|else
block|{
name|lshift
operator|=
name|widthGlyph
operator|-
name|xoff1
expr_stmt|;
define|#
directive|define
name|StoreBits0
value|StorePixels (0,GetFourPixels(c));
define|#
directive|define
name|GetBits
value|GetBitsNL
name|SwitchEm
undef|#
directive|undef
name|GetBits
undef|#
directive|undef
name|StoreBits0
block|}
block|}
else|else
block|{
if|#
directive|if
name|NGLYPHS
operator|==
literal|4
name|ew
operator|=
name|widthGlyph
expr_stmt|;
comment|/* widthGlyphs>> 2 */
else|#
directive|else
name|ew
operator|=
name|widthGlyphs
operator|>>
literal|2
expr_stmt|;
endif|#
directive|endif
ifndef|#
directive|ifndef
name|FAST_CONSTANT_OFFSET_MODE
name|widthLeft
operator|=
name|widthDst
operator|-
name|ew
expr_stmt|;
endif|#
directive|endif
define|#
directive|define
name|StoreBits0
value|StorePixels (0,GetFourPixels(c));
define|#
directive|define
name|GetBits
value|GetBitsNU
name|SwitchEm
undef|#
directive|undef
name|GetBits
undef|#
directive|undef
name|StoreBits0
block|}
name|x
operator|+=
name|widthGlyphs
expr_stmt|;
name|leftChar
operator|=
name|oldRightChar
expr_stmt|;
block|}
while|while
condition|(
name|nglyph
operator|--
condition|)
block|{
name|xoff1
operator|=
name|x
operator|&
literal|0x3
expr_stmt|;
name|char1
operator|=
operator|(
name|glyphPointer
operator|)
name|FONTGLYPHBITS
argument_list|(
name|pglyphBase
argument_list|,
operator|*
name|ppci
operator|++
argument_list|)
expr_stmt|;
name|hTmp
operator|=
name|h
expr_stmt|;
name|dstLine
operator|=
name|pdstBase
operator|+
operator|(
name|x
operator|>>
literal|2
operator|)
expr_stmt|;
name|oldRightChar
operator|=
name|char1
expr_stmt|;
name|dst
operator|=
name|dstLine
expr_stmt|;
if|if
condition|(
name|xoff1
condition|)
block|{
name|ew
operator|=
operator|(
operator|(
name|widthGlyph
operator|-
operator|(
literal|4
operator|-
name|xoff1
operator|)
operator|)
operator|>>
literal|2
operator|)
operator|+
literal|1
expr_stmt|;
ifndef|#
directive|ifndef
name|FAST_CONSTANT_OFFSET_MODE
name|widthLeft
operator|=
name|widthDst
operator|-
name|ew
expr_stmt|;
endif|#
directive|endif
if|if
condition|(
operator|!
name|leftChar
condition|)
block|{
name|leftMask
operator|=
name|cfbendtab
index|[
name|xoff1
index|]
expr_stmt|;
name|rightMask
operator|=
name|cfbstarttab
index|[
name|xoff1
index|]
expr_stmt|;
define|#
directive|define
name|StoreBits0
value|StorePixels (0,dst[0]& leftMask | GetFourPixels(c)& rightMask);
define|#
directive|define
name|GetBits
value|WGetBits1S
name|SwitchEm
undef|#
directive|undef
name|GetBits
undef|#
directive|undef
name|StoreBits0
block|}
else|else
block|{
name|lshift
operator|=
name|widthGlyph
operator|-
name|xoff1
expr_stmt|;
define|#
directive|define
name|StoreBits0
value|StorePixels (0,GetFourPixels(c));
define|#
directive|define
name|GetBits
value|WGetBits1L
name|SwitchEm
undef|#
directive|undef
name|GetBits
undef|#
directive|undef
name|StoreBits0
block|}
block|}
else|else
block|{
name|ew
operator|=
name|widthGlyph
operator|>>
literal|2
expr_stmt|;
ifndef|#
directive|ifndef
name|FAST_CONSTANT_OFFSET_MODE
name|widthLeft
operator|=
name|widthDst
operator|-
name|ew
expr_stmt|;
endif|#
directive|endif
define|#
directive|define
name|StoreBits0
value|StorePixels (0,GetFourPixels(c));
define|#
directive|define
name|GetBits
value|WGetBits1U
name|SwitchEm
undef|#
directive|undef
name|GetBits
undef|#
directive|undef
name|StoreBits0
block|}
name|x
operator|+=
name|widthGlyph
expr_stmt|;
name|leftChar
operator|=
name|oldRightChar
expr_stmt|;
block|}
comment|/*      * draw the tail of the last character      */
name|xoff1
operator|=
name|x
operator|&
literal|3
expr_stmt|;
if|if
condition|(
name|xoff1
condition|)
block|{
name|rightMask
operator|=
name|cfbstarttab
index|[
name|xoff1
index|]
expr_stmt|;
name|leftMask
operator|=
name|cfbendtab
index|[
name|xoff1
index|]
expr_stmt|;
name|lshift
operator|=
name|widthGlyph
operator|-
name|xoff1
expr_stmt|;
name|dst
operator|=
name|pdstBase
operator|+
operator|(
name|x
operator|>>
literal|2
operator|)
expr_stmt|;
name|hTmp
operator|=
name|h
expr_stmt|;
while|while
condition|(
name|hTmp
operator|--
condition|)
block|{
name|GetBitsL
expr_stmt|;
operator|*
name|dst
operator|=
operator|(
operator|*
name|dst
operator|&
name|rightMask
operator|)
operator||
operator|(
name|GetFourPixels
argument_list|(
name|c
argument_list|)
operator|&
name|leftMask
operator|)
expr_stmt|;
name|dst
operator|+=
name|widthDst
expr_stmt|;
block|}
block|}
block|}
end_function

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PPW == 4 */
end_comment

end_unit

