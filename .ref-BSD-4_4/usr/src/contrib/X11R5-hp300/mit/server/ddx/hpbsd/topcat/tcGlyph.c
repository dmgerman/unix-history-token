begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Copyright (c) 1986, 1987 by Hewlett-Packard Company Copyright (c) 1986, 1987 by the Massachusetts Institute of Technology  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  HEWLETT-PACKARD MAKES NO WARRANTY OF ANY KIND WITH REGARD TO THIS SOFWARE, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  PURPOSE.  Hewlett-Packard shall not be liable for errors  contained herein or direct, indirect, special, incidental or  consequential damages in connection with the furnishing,  performance, or use of this material.  This software is not subject to any license of the American Telephone and Telegraph Company or of the Regents of the University of California.  */
end_comment

begin_comment
comment|/***********************************************************************  *  file: topcatGlyph.c  *  *  *  ******************************************************************  *  *  (c) Copyright Hewlett-Packard Company, 1987.  All rights are  *  *  *  reserved.  Copying or other reproduction of this program      *  *  *  except for archival purposes is prohibited without prior      *  *  *  written consent of Hewlett-Packard Company.		     *  *  ******************************************************************  *  *  Glyph output routines  *  *		Hewlett Packard -- Corvallis Workstation Operation  *		Project -- port of X11 to HP9000  *		Harry Phinney -- MTS  *  *  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

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
file|"../cfb/cfb.h"
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
file|"regionstr.h"
end_include

begin_include
include|#
directive|include
file|"region.h"
end_include

begin_include
include|#
directive|include
file|"pixmapstr.h"
end_include

begin_include
include|#
directive|include
file|"pixmap.h"
end_include

begin_include
include|#
directive|include
file|"scrnintstr.h"
end_include

begin_include
include|#
directive|include
file|"windowstr.h"
end_include

begin_include
include|#
directive|include
file|"topcat.h"
end_include

begin_decl_stmt
specifier|extern
name|u_char
name|XHP_NewRule
index|[
literal|16
index|]
index|[
literal|6
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|XHP_pmap
index|[
literal|256
index|]
index|[
literal|2
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|XHP_QUADALIGN
decl_stmt|;
end_decl_stmt

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|static unsigned char masks[8] = { 0x1, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x80 };
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|unsigned
name|char
name|trailMasks
index|[
literal|8
index|]
init|=
block|{
literal|0x80
block|,
literal|0x40
block|,
literal|0x20
block|,
literal|0x10
block|,
literal|0x8
block|,
literal|0x4
block|,
literal|0x2
block|,
literal|0x1
block|}
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|DispAddr
parameter_list|(
name|pScreen
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|)
define|\
value|((getPrivScreenPtr(pScreen)->bits) + \        ((y) * getPrivScreenPtr(pScreen)->stride) + \        (x));
end_define

begin_comment
comment|/************************************************************************  *  Routine:	tcWholeGlyph  *		Output an entire glyph with no clipping  *		Used for putting chars in offscreen memory  *  *  Inputs: pScn points to the ScreenRec for the screen the glyph is going to  *	    pGlyph points to the bits of the glyph we're outputing  *	    pCi points to the character info struct for the glyph  *	    x,y specifies the screen location of the upper-left corner of glyph  *	    func is the display function (ROP)  *	    fore, back are the foreground and background colors  *	    planes is the plane mask (zmask)  *    *  Returns: nothing (it's a void...)  *  *  Side Effects:  none  *  */
end_comment

begin_function
name|void
name|tcWholeGlyph
parameter_list|(
name|pScn
parameter_list|,
name|pGlyph
parameter_list|,
name|pCi
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|func
parameter_list|,
name|fore
parameter_list|,
name|back
parameter_list|,
name|planes
parameter_list|)
name|ScreenPtr
name|pScn
decl_stmt|;
name|char
modifier|*
name|pGlyph
decl_stmt|;
name|CharInfoPtr
name|pCi
decl_stmt|;
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
name|int
name|func
decl_stmt|;
name|int
name|fore
decl_stmt|,
name|back
decl_stmt|;
name|int
name|planes
decl_stmt|;
block|{
name|int
name|gwidth
decl_stmt|,
name|gheight
decl_stmt|,
name|rowBytes
decl_stmt|;
name|int
name|i
decl_stmt|,
name|j
decl_stmt|;
name|TOPCAT
modifier|*
name|hardware
init|=
name|getTcHardware
argument_list|(
name|pScn
argument_list|)
decl_stmt|;
name|int
name|XHP_bits
init|=
name|hardware
operator|->
name|bits
decl_stmt|;
name|gwidth
operator|=
name|GLYPHWIDTHPIXELS
argument_list|(
name|pCi
argument_list|)
expr_stmt|;
name|gheight
operator|=
name|GLYPHHEIGHTPIXELS
argument_list|(
name|pCi
argument_list|)
expr_stmt|;
name|rowBytes
operator|=
name|GLYPHWIDTHBYTESPADDED
argument_list|(
name|pCi
argument_list|)
expr_stmt|;
comment|/*      * call the MaskConfig routine to set the regs      */
name|SET_REGISTERS_FOR_WRITING
argument_list|(
name|pScn
argument_list|,
name|planes
argument_list|,
name|func
argument_list|)
expr_stmt|;
comment|/*      * if word/pixel (low res topcat) then write words, else write bytes      */
if|if
condition|(
name|XHP_bits
condition|)
block|{
specifier|register
name|u_short
modifier|*
name|dest
decl_stmt|,
modifier|*
name|base
decl_stmt|;
name|char
name|srcbyte
decl_stmt|;
name|char
modifier|*
name|pNextByte
decl_stmt|;
name|base
operator|=
operator|(
name|u_short
operator|*
operator|)
name|DispAddr
argument_list|(
name|pScn
argument_list|,
name|x
operator|<<
name|XHP_bits
argument_list|,
name|y
argument_list|)
expr_stmt|;
comment|/* 	 * make the colors word-wide symetric 	 */
name|fore
operator||=
name|fore
operator|<<
literal|8
expr_stmt|;
if|if
condition|(
name|back
operator|!=
operator|-
literal|1
condition|)
name|back
operator||=
name|back
operator|<<
literal|8
expr_stmt|;
while|while
condition|(
name|gheight
operator|--
condition|)
block|{
name|dest
operator|=
name|base
expr_stmt|;
name|base
operator|+=
operator|(
operator|(
name|hpPrivScreen
operator|*
operator|)
operator|(
name|pScn
operator|->
name|devPrivate
operator|)
operator|)
operator|->
name|stride
expr_stmt|;
name|srcbyte
operator|=
operator|*
name|pGlyph
expr_stmt|;
name|pNextByte
operator|=
name|pGlyph
operator|+
literal|1
expr_stmt|;
name|pGlyph
operator|+=
name|rowBytes
expr_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
name|j
operator|=
name|gwidth
expr_stmt|;
while|while
condition|(
name|j
operator|--
condition|)
block|{
if|if
condition|(
name|i
operator|++
operator|==
literal|8
condition|)
block|{
name|srcbyte
operator|=
operator|*
name|pNextByte
operator|++
expr_stmt|;
name|i
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|srcbyte
operator|&
literal|128
condition|)
comment|/* put out the MSB */
operator|*
name|dest
operator|++
operator|=
name|fore
expr_stmt|;
elseif|else
if|if
condition|(
name|back
operator|!=
operator|-
literal|1
condition|)
operator|*
name|dest
operator|++
operator|=
name|back
expr_stmt|;
else|else
name|dest
operator|++
expr_stmt|;
name|srcbyte
operator|<<=
literal|1
expr_stmt|;
comment|/* get next pix value in MSB */
block|}
block|}
return|return;
block|}
else|else
block|{
comment|/* high res topcat - copy bytes */
comment|/* 	 * code for byte/pixel displays 	 * XXX This could/should be sped up by writing more than one pixel at 	 * a time - i.e. write longs& shorts when appropriate. 	 */
specifier|register
name|u_char
modifier|*
name|dest
decl_stmt|,
modifier|*
name|base
decl_stmt|;
specifier|register
name|char
name|srcbyte
decl_stmt|;
name|char
modifier|*
name|pNextByte
decl_stmt|;
name|base
operator|=
operator|(
name|u_char
operator|*
operator|)
name|DispAddr
argument_list|(
name|pScn
argument_list|,
name|x
argument_list|,
name|y
argument_list|)
expr_stmt|;
while|while
condition|(
name|gheight
operator|--
condition|)
block|{
comment|/* for each row of pixels in glyph */
name|dest
operator|=
name|base
expr_stmt|;
name|base
operator|+=
operator|(
operator|(
name|hpPrivScreen
operator|*
operator|)
operator|(
name|pScn
operator|->
name|devPrivate
operator|)
operator|)
operator|->
name|stride
expr_stmt|;
name|srcbyte
operator|=
operator|*
name|pGlyph
expr_stmt|;
name|pNextByte
operator|=
name|pGlyph
operator|+
literal|1
expr_stmt|;
name|pGlyph
operator|+=
name|rowBytes
expr_stmt|;
name|i
operator|=
literal|0
expr_stmt|;
comment|/* counter of bits put out from current byte */
name|j
operator|=
name|gwidth
expr_stmt|;
comment|/* total bits in this row */
while|while
condition|(
name|j
operator|--
condition|)
block|{
if|if
condition|(
name|i
operator|++
operator|==
literal|8
condition|)
block|{
comment|/* if we've used up the byte, go to next one */
name|srcbyte
operator|=
operator|*
name|pNextByte
operator|++
expr_stmt|;
name|i
operator|=
literal|1
expr_stmt|;
block|}
if|if
condition|(
name|srcbyte
operator|&
literal|128
condition|)
operator|*
name|dest
operator|++
operator|=
name|fore
expr_stmt|;
elseif|else
if|if
condition|(
name|back
operator|!=
operator|-
literal|1
condition|)
operator|*
name|dest
operator|++
operator|=
name|back
expr_stmt|;
else|else
name|dest
operator|++
expr_stmt|;
name|srcbyte
operator|<<=
literal|1
expr_stmt|;
comment|/* get next pix bit in MSB */
block|}
comment|/* next bit in this row */
block|}
comment|/* next pixel row */
block|}
comment|/* end of byte/pixel code */
block|}
end_function

begin_comment
comment|/************************************************************************  *  Routine:	tcImageGlyphBlt  *		Output a set of glyphs  *		Called by the tcImageText routine(s) iff the glyphs   * 		are not in offscreen memory and the destination drawable   *		is a window.  *  *  Inputs: pDraw points to the *window* we're drawing to  *	    pGC points to the graphics context  *	    dstx,dsty is the screen location of the glyph baseline  *	    nglyph is the number of glyphs  *	    ppCI is a pointer to the array of CharInfo's for the glyphs  *	    pGlyphBase points to the array of glyph bits  *    *  Returns: nothing (it's a void...)  *  *  Side Effects:  none  *  */
end_comment

begin_function
name|void
name|tcImageVarGlyph
parameter_list|(
name|pDraw
parameter_list|,
name|pGC
parameter_list|,
name|dstx
parameter_list|,
name|dsty
parameter_list|,
name|nglyph
parameter_list|,
name|ppCI
parameter_list|,
name|pGlyphBase
parameter_list|)
name|DrawablePtr
name|pDraw
decl_stmt|;
name|GC
modifier|*
name|pGC
decl_stmt|;
name|unsigned
name|int
name|dstx
decl_stmt|,
name|dsty
decl_stmt|;
name|unsigned
name|int
name|nglyph
decl_stmt|;
name|CharInfoPtr
modifier|*
name|ppCI
decl_stmt|;
name|char
modifier|*
name|pGlyphBase
decl_stmt|;
block|{
if|#
directive|if
literal|0
block|ExtentInfoRec info;
comment|/* used by QueryGlyphExtents() */
block|xRectangle backrect;     RegionPtr pRegion = ((cfbPrivGC *) 			 pGC->devPrivates[cfbGCPrivateIndex].ptr)->pCompositeClip;     register BoxPtr pBox;     int nbox;     TOPCAT *hardware = getTcHardware(pDraw->pScreen);     unsigned long screenPlanes = getPlanesMask(pDraw->pScreen);     unsigned long zmask = pGC->planemask& screenPlanes;     int back = pGC->bgPixel;     u_char *dest, *base;     int stride = ((hpPrivScreen *)(pDraw->pScreen->devPrivate))->stride;     register int i, x, y, dx, dy, h, w;     int XHP_bits = hardware->bits;     int fontAscent = FONTASCENT(pGC->font);      if (pDraw->type != DRAWABLE_WINDOW)     { 	if (pGC->bgPixel== -1)  	   miPolyGlyphBlt(pDraw, pGC, dstx, dsty, nglyph, ppCI, pGlyphBase); 	else 	   miImageGlyphBlt(pDraw, pGC, dstx, dsty, nglyph, ppCI, pGlyphBase);     }      if (!nglyph) 	return;      if (pGC->miTranslate)     {
comment|/* absolutize the coordinates */
block|dstx += pDraw->x; 	dsty += pDraw->y;     }      QueryGlyphExtents(pGC->font, ppCI, nglyph,&info);      backrect.x = dstx;     backrect.y = dsty - fontAscent;     backrect.width = info.overallWidth;     backrect.height = fontAscent + FONTDESCENT(pGC->font);      for (nbox = REGION_NUM_RECTS(pRegion), pBox = REGION_RECTS(pRegion); 	 nbox--; pBox++)     {
comment|/*  	 * for each rectangle in the list of clip rects, block fill the 	 * background for the characters and put down the foreground pixels 	 * from the glyphs 	 */
block|x = backrect.x; 	y = backrect.y; 	w = backrect.width; 	h = backrect.height; 	dx = 0; 	dy = 0;
comment|/* 	 * figure out the intersection between the character background box 	 * and the clip box, and fill the resulting rectangle 	 */
block|if (y< pBox->y1) 	{ 	    dy = pBox->y1 - y; 	    h -= dy; 	    if (h<= 0) continue; 	    y = pBox->y1; 	} 	if (y+h> pBox->y2) 	{ 	    h = pBox->y2 - y; 	    if (h<= 0) continue; 	}  	if (x< pBox->x1) 	{ 	    dx = pBox->x1 - x; 	    w -= dx; 	    if (w<= 0) continue; 	    x = pBox->x1; 	} 	if (x+w> pBox->x2) 	{ 	    w = pBox->x2 - x; 	    if (w<= 0) continue; 	}  	if (h> 0&& w> 0) 	{
comment|/* if the intersection was non-null */
block|int charx = dstx; 	    int slen = nglyph; 	    CharInfoPtr *ppci = ppCI; 	    register CharInfoPtr pci = *ppci++; 	    char *pGlyph;
comment|/* 	     * clear the rect to the background color 	     */
block|waitbusy(screenPlanes, hardware);  	    hardware->write_enable = zmask& back; 	    hardware->window_move_replacement_rule = XHP_NewRule[GXcopy][3]; 	    hardware->write_enable = zmask& ~back; 	    hardware->window_move_replacement_rule = XHP_NewRule[GXcopy][0]; 	    hardware->write_enable = zmask; 	    hardware->pixel_write_replacement_rule = GXcopy;                  	    hardware->source_x = x<< XHP_bits; 	    hardware->source_y = y; 	    hardware->dest_x = x<< XHP_bits; 	    hardware->dest_y = y; 	    hardware->window_width = w<< XHP_bits; 	    hardware->window_height = h; 	    hardware->start_move = zmask;
comment|/* 	     * while the character is to the left of the clipping rectangle, 	     * go to the next character 	     */
block|while (charx + pci->metrics.characterWidth< pBox->x1) 	    { 		if (--slen == 0) break; 		charx += pci->metrics.characterWidth; 		pci = *ppci++; 	    }
comment|/* 	     * clip the first (partially) in char to the left edge of pBox 	     */
block|dx = pBox->x1 - (charx + pci->metrics.leftSideBearing); 	    if (dx< 0) dx = 0; 	    if (charx+dx> pBox->x2) continue;
comment|/* 	     * Set up the registers so that writing 0xff will get us the 	     * foreground and writing 0x00 is a noop 	     */
block|waitbusy(screenPlanes, hardware); 	    hardware->write_enable = zmask& pGC->fgPixel; 	    hardware->pixel_write_replacement_rule = XHP_NewRule[GXcopy][4]; 	    hardware->write_enable = zmask& ~pGC->fgPixel; 	    hardware->pixel_write_replacement_rule = XHP_NewRule[GXcopy][5]; 	    hardware->frame_buf_write_enable = zmask;  	    for (; slen--; pci = *ppci++) 	    { 		int gwidth = GLYPHWIDTHPIXELS(pci); 		int gheight = GLYPHHEIGHTPIXELS(pci); 		int rowBytes = GLYPHWIDTHBYTESPADDED(pci); 		int height = gheight; 		int glyphy = dsty - pci->metrics.ascent;  		if (glyphy< pBox->y1) 		{ 		    dy = pBox->y1 - glyphy; 		    height -= dy; 		    glyphy = pBox->y1; 		    if (height<= 0) 		    { 			charx += pci->metrics.characterWidth; 			dx = 0; 			if (charx>= pBox->x2) break; 			continue; 		    } 		} 		else dy = 0;  		if (glyphy+height> pBox->y2) 		{ 		    height = pBox->y2 - glyphy; 		    if (height<= 0) 		    { 			charx += pci->metrics.characterWidth; 			dx = 0; 			if (charx>= pBox->x2) break; 			continue; 		    } 		}
comment|/* get address of first glyph row in the clip rect */
block|pGlyph = pGlyphBase + pci->byteOffset + dy * rowBytes;  		base = (u_char *) DispAddr(pDraw->pScreen,  					   charx + pci->metrics.leftSideBearing + dx, glyphy);
comment|/* 		 * clip to right edge 		 */
block|if ((charx+gwidth+pci->metrics.leftSideBearing)> pBox->x2) 		{ 		    gwidth = pBox->x2 - (charx+pci->metrics.leftSideBearing); 		    if (gwidth<= 0) break; 		}  		if (gwidth> dx) 		{ 		    int wholeBytes; 		    unsigned char srcbyte; 		    char *pNextByte;  		    if ((!XHP_QUADALIGN || ((unsigned int)base& 0x01))&& 			!dx&& (wholeBytes = gwidth / 8)) 		    { 			int trailingBits = gwidth - (wholeBytes<< 3); 			unsigned char srcbyte;  			for (;height--; pGlyph += rowBytes, base += stride) 			{ 			    register unsigned int *pdstInt = (unsigned int *) base; 			    srcbyte = *(pNextByte = pGlyph); 			    pNextByte++; 			    for (i = wholeBytes; i--; srcbyte = *pNextByte++) 			    { 				*pdstInt++ = XHP_pmap[srcbyte][0]; 				*pdstInt++ = XHP_pmap[srcbyte][1]; 			    } 			    if (trailingBits) 			    { 				dest = (u_char *) pdstInt; 				for (i = 0; i< trailingBits; i++) 				{ 				    if (srcbyte& trailMasks[i]) 					*dest++ = 0xff; 				    else 					dest++; 				} 			    } 			} 		    } 		    else 		    { 			while (height--) 			{ 			    register j;  			    srcbyte = *(pNextByte = pGlyph + (dx / 8))<< (dx % 8); 			    pNextByte++; 			    pGlyph += rowBytes;  			    dest = base; 			    base += stride; 			    i = dx& 7; 			    j = gwidth - dx;  			    while(j--) 			    { 				if (i++ == 8) 				{ 				    srcbyte = *pNextByte++; 				    i = 1; 				} 				if (srcbyte& 128)  				    *dest++ = 0xff; 				else  				    dest++; 				srcbyte<<= 1; 			    } 			} 		    } 		} 		charx += pci->metrics.characterWidth; 		dx = 0; 		if (charx>= pBox->x2) 		    slen = 0;
comment|/* kind of slimey break from loop */
block|} 	}     }     hardware->frame_buf_write_enable = 0xff;
endif|#
directive|endif
block|}
end_function

begin_function
name|void
name|tcImageGlyphBlt
parameter_list|(
name|pDraw
parameter_list|,
name|pGC
parameter_list|,
name|dstx
parameter_list|,
name|dsty
parameter_list|,
name|nglyph
parameter_list|,
name|ppCI
parameter_list|,
name|pGlyphBase
parameter_list|)
name|DrawablePtr
name|pDraw
decl_stmt|;
specifier|register
name|GC
modifier|*
name|pGC
decl_stmt|;
name|unsigned
name|int
name|dstx
decl_stmt|,
name|dsty
decl_stmt|;
name|unsigned
name|int
name|nglyph
decl_stmt|;
name|CharInfoPtr
modifier|*
name|ppCI
decl_stmt|;
name|char
modifier|*
name|pGlyphBase
decl_stmt|;
block|{
if|#
directive|if
literal|0
block|xRectangle backrect;     RegionPtr pRegion = ((cfbPrivGC *) 			 pGC->devPrivates[cfbGCPrivateIndex].ptr)->pCompositeClip;     register BoxPtr pBox;     int nbox;     TOPCAT *hardware = getTcHardware(pDraw->pScreen);     unsigned long screenPlanes = getPlanesMask(pDraw->pScreen);     unsigned long zmask = pGC->planemask& screenPlanes;     u_char *dest, *base;     int stride = ((hpPrivScreen *)(pDraw->pScreen->devPrivate))->stride;     register int i, x, y, dx, dy, h, w, dyBytes;     int fontAscent = FONTASCENT(pGC->font);     int glyphWidth, gwidth, height;     int rowBytes = GLYPHWIDTHBYTESPADDED((*ppCI));       if (!nglyph) 	return;      if (!TERMINALFONT(pGC->font))     {
comment|/* 	 * if the font isn't a terminal font, then call the routine that 	 * knows how to deal with variable-width fonts 	 */
block|tcImageVarGlyph(pDraw, pGC, dstx, dsty, nglyph, ppCI, pGlyphBase); 	return;     }      if (pGC->miTranslate)     {
comment|/* absolutize the coordinates */
block|dstx += pDraw->x; 	dsty += pDraw->y;     }      backrect.x = dstx;     backrect.y = dsty - fontAscent;     backrect.width = nglyph *  (glyphWidth = 		     (FONTMAXBOUNDS(pGC->font,rightSideBearing) - 		      FONTMINBOUNDS(pGC->font,leftSideBearing)));     backrect.height = fontAscent + FONTDESCENT(pGC->font);      waitbusy(screenPlanes, hardware);
comment|/* wait for all planes to quiet */
comment|/*      * set registers to get proper foreground/background colors      */
block|if (pGC->bgPixel == -1)     {
comment|/* 	 * handle special case of PolyText, so PolyText can be fast if 	 * it uses a solid fill 	 */
block|hardware->write_enable = zmask& pGC->fgPixel; 	hardware->pixel_write_replacement_rule = XHP_NewRule[pGC->alu][4]; 	hardware->write_enable = zmask& ~pGC->fgPixel; 	hardware->pixel_write_replacement_rule = XHP_NewRule[pGC->alu][5];     }     else     {
comment|/* 	 * Set registers for normal ImageText case.  Note that pGC->alu 	 * is ignored, and GXcopy is forced. 	 */
block|hardware->write_enable = zmask& ~pGC->fgPixel& ~pGC->bgPixel; 	hardware->pixel_write_replacement_rule = XHP_NewRule[GXcopy] [0]; 	hardware->write_enable = zmask& ~pGC->fgPixel& pGC->bgPixel; 	hardware->pixel_write_replacement_rule = XHP_NewRule[GXcopy] [1]; 	hardware->write_enable = zmask& pGC->fgPixel& ~pGC->bgPixel; 	hardware->pixel_write_replacement_rule = XHP_NewRule[GXcopy] [2]; 	hardware->write_enable = zmask& pGC->fgPixel& pGC->bgPixel; 	hardware->pixel_write_replacement_rule = XHP_NewRule[GXcopy] [3];     }     hardware->write_enable = zmask;
comment|/* XXX for catseye */
block|hardware->frame_buf_write_enable = zmask;      for (nbox = REGION_NUM_RECTS(pRegion), pBox = REGION_RECTS(pRegion); 	 nbox--; pBox++)     {
comment|/*  	 * for each rectangle in the list of clip rects, block fill the 	 * background for the characters and put down the foreground pixels 	 * from the glyphs 	 */
block|x = backrect.x; 	y = backrect.y; 	w = glyphWidth; 	h = backrect.height; 	dx = 0; 	dy = 0;
comment|/* 	 * clip the height once since all chars are the same height 	 */
block|if (y< pBox->y1) 	{ 	    dy = pBox->y1 - y; 	    h -= dy; 	    if (h<= 0) continue; 	    y = pBox->y1; 	} 	if (y+h> pBox->y2) 	{ 	    h = pBox->y2 - y; 	    if (h<= 0) continue; 	}  	if (h> 0) 	{ 	    int charx = dstx; 	    int slen = nglyph; 	    register CharInfoPtr *ppci = ppCI; 	    register CharInfoPtr pci; 	    char *pGlyph; 	    int wholeBytes = w>> 3; 	    int trailingBits = w - (wholeBytes<< 3); 	    u_char *stringBase;  	    dyBytes = dy * rowBytes;
comment|/* 	     * while the character is to the left of the clipping rectangle, 	     * go to the next character 	     */
block|while (charx + w<= pBox->x1) 	    { 		if (--slen == 0) break; 		charx += w; 		*ppci++; 	    } 	    if (!slen) continue;
comment|/* 	     * clip the first (partially) in char to the left edge of pBox 	     */
block|if ((dx = pBox->x1 - charx)< 0) dx = 0; 	    if (charx+dx>= pBox->x2) continue;
comment|/* 	     * trim string length to right edge of pBox 	     */
block|if ((charx + w * slen)>= pBox->x2) 	    {
comment|/* compute ceiling((pBox->x2 - charx)/w) */
block|slen = min((pBox->x2 - charx + w - 1)/w, slen); 		if (slen<= 0) continue; 	    }  	    stringBase = (u_char *) DispAddr(pDraw->pScreen, charx, y); 	    for (base = stringBase + dx, gwidth = w, pci = *ppci++; slen--;  		 dx = 0, charx += w, pci = *ppci++, base = (stringBase += w)) 	    { 		height = h;
comment|/* get address of first glyph row in the clip rect */
block|pGlyph = pGlyphBase + pci->byteOffset + dyBytes;
comment|/* 		 * clip the last character to the right edge of pBox 		 */
block|if (!slen) 		{ 		    if ((charx+gwidth)> pBox->x2) 		    { 			if ((gwidth = pBox->x2 - charx)<= 0) break; 			wholeBytes = gwidth>> 3; 			trailingBits = gwidth - (wholeBytes<< 3); 		    } 		}  		if (gwidth> dx) 		{ 		    unsigned char srcbyte; 		    char *pNextByte;  		    if ((!XHP_QUADALIGN || !((unsigned int)base& 0x01))&& 			!dx&& wholeBytes) 		    { 			unsigned char srcbyte;  			for (;height--; pGlyph += rowBytes, base += stride) 			{ 			    register unsigned int *pdstInt = (unsigned int *) base; 			    srcbyte = *(pNextByte = pGlyph); 			    pNextByte++; 			    for (i = wholeBytes; i--; srcbyte = *pNextByte++) 			    { 				*pdstInt++ = XHP_pmap[srcbyte][0]; 				*pdstInt++ = XHP_pmap[srcbyte][1]; 			    } 			    if (trailingBits) 			    { 				dest = (u_char *) pdstInt; 				for (i = 0; i< trailingBits; i++) 				{ 				    if (srcbyte& trailMasks[i]) 					*dest++ = 0xff; 				    else 					*dest++ = 0x00; 				} 			    } 			} 		    } 		    else 		    { 			while (height--) 			{ 			    register j;  			    srcbyte = *(pNextByte = pGlyph + (dx / 8))<< (dx % 8); 			    pNextByte++; 			    pGlyph += rowBytes;  			    dest = base; 			    base += stride; 			    i = dx& 7; 			    j = gwidth - dx;  			    while (j--) 			    { 				if (i++ == 8) 				{ 				    srcbyte = *pNextByte++; 				    i = 1; 				} 				if (srcbyte& 128)  				    *dest++ = 0xff; 				else  				    *dest++ = 0x00;  				srcbyte<<= 1; 			    } 			} 		    } 		} 	    } 	}     }     hardware->frame_buf_write_enable = 0xff;
endif|#
directive|endif
block|}
end_function

end_unit

