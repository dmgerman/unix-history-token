begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Copyright (c) 1986, 1987 by Hewlett-Packard Company Copyright (c) 1986, 1987 by the Massachusetts Institute of Technology  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  HEWLETT-PACKARD MAKES NO WARRANTY OF ANY KIND WITH REGARD TO THIS SOFWARE, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  PURPOSE.  Hewlett-Packard shall not be liable for errors  contained herein or direct, indirect, special, incidental or  consequential damages in connection with the furnishing,  performance, or use of this material.  This software is not subject to any license of the American Telephone and Telegraph Company or of the Regents of the University of California.  */
end_comment

begin_comment
comment|/***********************************************************************  *  file: topcatText.c  *  *  *  ******************************************************************  *  *  (c) Copyright Hewlett-Packard Company, 1987.  All rights are  *  *  *  reserved.  Copying or other reproduction of this program      *  *  *  except for archival purposes is prohibited without prior      *  *  *  written consent of Hewlett-Packard Company.		     *  *  ******************************************************************  *  *  ImageText and PolyText routines for the topcat displays  *  *		Hewlett Packard -- Corvallis Workstation Operation  *		Project -- port of X11 to HP9000  *		Harry Phinney -- MTS  *  *  */
end_comment

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_ifndef
ifndef|#
directive|ifndef
name|hpux
end_ifndef

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_include
include|#
directive|include
file|<grfioctl.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/graphics.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"X.h"
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
file|"scrnintstr.h"
end_include

begin_include
include|#
directive|include
file|"cursorstr.h"
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
file|"dixfontstr.h"
end_include

begin_include
include|#
directive|include
file|"fontstruct.h"
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
file|"mi.h"
end_include

begin_include
include|#
directive|include
file|"topcat.h"
end_include

begin_include
include|#
directive|include
file|"hpFonts.h"
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

begin_comment
comment|/* array of replacement rules */
end_comment

begin_function
specifier|static
name|void
name|waitAwhile
parameter_list|(
name|screenPlanes
parameter_list|)
name|unsigned
name|int
name|screenPlanes
decl_stmt|;
block|{ }
end_function

begin_function
specifier|static
name|void
name|setRegs
parameter_list|(
name|hardware
parameter_list|,
name|pGC
parameter_list|,
name|zmask
parameter_list|)
name|TOPCAT
modifier|*
name|hardware
decl_stmt|;
name|GCPtr
name|pGC
decl_stmt|;
name|unsigned
name|int
name|zmask
decl_stmt|;
block|{
if|if
condition|(
name|pGC
operator|->
name|bgPixel
operator|==
operator|-
literal|1
condition|)
block|{
comment|/* 	 * handle special case of PolyText, so PolyText can be fast if 	 * it uses a solid fill 	 */
name|hardware
operator|->
name|write_enable
operator|=
name|zmask
operator|&
name|pGC
operator|->
name|fgPixel
expr_stmt|;
name|hardware
operator|->
name|window_move_replacement_rule
operator|=
name|XHP_NewRule
index|[
name|pGC
operator|->
name|alu
index|]
index|[
literal|4
index|]
expr_stmt|;
name|hardware
operator|->
name|write_enable
operator|=
name|zmask
operator|&
operator|~
name|pGC
operator|->
name|fgPixel
expr_stmt|;
name|hardware
operator|->
name|window_move_replacement_rule
operator|=
name|XHP_NewRule
index|[
name|pGC
operator|->
name|alu
index|]
index|[
literal|5
index|]
expr_stmt|;
block|}
else|else
block|{
comment|/* 	 * Set registers for normal ImageText case.  Note that pGC->alu 	 * is ignored, and GXcopy is forced. 	 */
name|hardware
operator|->
name|write_enable
operator|=
name|zmask
operator|&
operator|~
name|pGC
operator|->
name|fgPixel
operator|&
operator|~
name|pGC
operator|->
name|bgPixel
expr_stmt|;
name|hardware
operator|->
name|window_move_replacement_rule
operator|=
name|XHP_NewRule
index|[
name|GXcopy
index|]
index|[
literal|0
index|]
expr_stmt|;
name|hardware
operator|->
name|write_enable
operator|=
name|zmask
operator|&
operator|~
name|pGC
operator|->
name|fgPixel
operator|&
name|pGC
operator|->
name|bgPixel
expr_stmt|;
name|hardware
operator|->
name|window_move_replacement_rule
operator|=
name|XHP_NewRule
index|[
name|GXcopy
index|]
index|[
literal|1
index|]
expr_stmt|;
name|hardware
operator|->
name|write_enable
operator|=
name|zmask
operator|&
name|pGC
operator|->
name|fgPixel
operator|&
operator|~
name|pGC
operator|->
name|bgPixel
expr_stmt|;
name|hardware
operator|->
name|window_move_replacement_rule
operator|=
name|XHP_NewRule
index|[
name|GXcopy
index|]
index|[
literal|2
index|]
expr_stmt|;
name|hardware
operator|->
name|write_enable
operator|=
name|zmask
operator|&
name|pGC
operator|->
name|fgPixel
operator|&
name|pGC
operator|->
name|bgPixel
expr_stmt|;
name|hardware
operator|->
name|window_move_replacement_rule
operator|=
name|XHP_NewRule
index|[
name|GXcopy
index|]
index|[
literal|3
index|]
expr_stmt|;
block|}
name|hardware
operator|->
name|frame_buf_write_enable
operator|=
name|zmask
expr_stmt|;
name|hardware
operator|->
name|write_enable
operator|=
name|zmask
expr_stmt|;
name|hardware
operator|->
name|pixel_write_replacement_rule
operator|=
name|GXcopy
expr_stmt|;
block|}
end_function

begin_comment
comment|/************************************************************************  *  Routine:    tcImageOptText  *              Render text strings to the display with "optimized" fonts.  *              Uses the Topcat block mover to place the character if the  *              character has been "optimized" (stored in offscreen memory).  *              If it's not in offscreen then we call pGC->ImageGlyphBlt.  *              It is assumed that these are *terminal fonts*, drawn left  *              to right, and have the most-used characters stored in  *              offscreen memory. The characters must be stored in increasing  *		order in the chunks, e.g. char 78 *must* be further down the  *		list of chunks than char 57, though char 63 doesn't have to   *		be stored in offscreen. No chunk can have holes - the chars  *		must be contiguous within a chunk. In the example above, if  *		char 63 isn't stored, 57 and 78 *must* be in different chunks.  *  *		If pGC->bgPixel is -1, then assume we are being called by  *		PolyText, and make the glyph background a no-op (transparent).  *		This allows PolyText to be fast iff FillStyle == Solid.  *  *  Inputs: pDraw points to the drawable we're to print to  *          pGC points to the GC we're to use  *          x, y is the starting location for the string in the drawable  *          count is the number of characters we're to put out  *          chars points to an array of the characters we're to put out(!)  *          encoding is Linear8Bit, Linear16Bit, etc.  *  *  Returns: nothing  *  *  Side Effects: none  *  */
end_comment

begin_function
name|void
name|tcImageOptTEText8
parameter_list|(
name|pDraw
parameter_list|,
name|pGC
parameter_list|,
name|dstx
parameter_list|,
name|dsty
parameter_list|,
name|count
parameter_list|,
name|chars
comment|/*, encoding */
parameter_list|)
name|DrawablePtr
name|pDraw
decl_stmt|;
name|GCPtr
name|pGC
decl_stmt|;
name|int
name|dstx
decl_stmt|,
name|dsty
decl_stmt|;
name|int
name|count
decl_stmt|;
name|u_char
modifier|*
name|chars
decl_stmt|;
comment|/* FontEncoding encoding; */
block|{
if|#
directive|if
literal|0
block|FontEncoding encoding = Linear8Bit;
comment|/* should be passed in ... */
block|register TOPCAT *hardware = getTcHardware(pDraw->pScreen);     unsigned long screenPlanes = getPlanesMask(pDraw->pScreen);     unsigned long zmask = pGC->planemask& screenPlanes;     int fore = pGC->fgPixel;     int back = pGC->bgPixel;      FontPtr pfont = pGC->font;     CharInfoPtr pCI = pfont->pCI;     register unsigned int firstCol = FONTFIRSTCOL(pfont);     int numCols = FONTLASTCOL(pfont) - firstCol + 1;     unsigned int chDefault = FONTDEFAULTCH(pfont);      hpFontRec *pfrec = (hpFontRec *)(pfont->devPriv[pDraw->pScreen->myNum]);     hpChunk *pChunk;     Bool fDefaultExists = pfrec->fDefaultExists;      RegionPtr pRegion = 	((cfbPrivGC *)pGC->devPrivates[cfbGCPrivateIndex].ptr)->pCompositeClip;     register BoxPtr pBox = REGION_RECTS(pRegion);     int nbox = REGION_NUM_RECTS(pRegion);      int x, y, dx, dy, h, w;     int srcx, srcy;     int found;
comment|/* flag for in/out of offscreen */
comment|/*     * some stupid applications send a request to output a zero length     * string, so I have to check for it.     */
block|if (!count) 	return;
comment|/*     * absolutize the coordinates      */
block|dstx += pDraw->x;     dsty += pDraw->y;
comment|/*      * adjust dsty from char baseline to top edge      * because we assume terminal fonts, all ascents are the same      */
block|dsty -= FONTMAXBOUNDS(pfont,ascent);      while (screenPlanes& hardware->move_active) 	waitAwhile(screenPlanes);          setRegs(hardware, pGC, zmask);      switch (encoding)     {       case Linear8Bit:        case TwoD8Bit: 	for (; nbox--; pBox++) 	{
comment|/* for each clip box */
comment|/* 	     * because we assume terminal fonts, we just need the w& h  	     * of any random character from the font 	     * (since they're all the same) 	     */
block|w = pfrec->maxWidth; 	    h = pfrec->maxHeight; 	    y = dsty; 	    dx = 0; 	    dy = 0;
comment|/* 	     * clip the height only once since all chars are same height&ascent 	     */
block|if (y< pBox->y1) 	    { 		dy = pBox->y1 - y; 		h -= dy; 		y = pBox->y1; 	    } 	    if (y+h> pBox->y2) 		h -= y + h - pBox->y2;
comment|/*  	     * if any part is in the y-band of the box, write it 	     */
block|if (h> 0) 	    { 		register u_char *str = chars; 		register unsigned char st; 		register slen = count; 		x = dstx;  		if (x< pBox->x1) 		{
comment|/* 		     * while the character is to the left of the clipping 		     * rectangle, go to the next character 		     */
block|while (x+w<= pBox->x1) 		    { 			if (--slen == 0) 			    break; 			x += w; 			str++; 		    } 		    if (!slen) 			continue;
comment|/* 		     * clip the first "in" character to the edge 		     */
block|if ((dx = pBox->x1 - x)< 0) 			dx = 0; 		    if (x+dx>= pBox->x2) 			continue; 		}
comment|/* 		 * trim length to right edge of pBox  		 */
block|if ((x + w*slen)>= pBox->x2) 		{
comment|/* compute ceiling((pBox->x2 - x)/w) */
block|slen = min((pBox->x2 - x + w - 1)/w, slen); 		    if (slen<= 0) 			continue; 		}
comment|/* 		 * if the first glyph is clipped by the left edge, 		 * put it out 		 */
block|if (dx) 		{ 		    st = *str++;  		    slen--; 		    while (!fDefaultExists&& 			   ((st< firstCol) || (st> FONTLASTCOL(pfont)) || 			    !pCI[st - firstCol].exists)) 		    {
comment|/* 			 * if the default char doesn't exist, and this character 			 * doesn't exist, then go on to next character 			 */
block|if (!--slen) 			    continue; 			st = *str++; 		    } 		    found = 0;
comment|/* 		     * find the char's location in offscreen (hopefully) 		     */
block|if (st>= pfrec->firstChar&& st<= pfrec->lastChar) 		    { 			srcx =  			    (pChunk = pfrec->ppChunk[(st - pfrec->firstChar)>> 5])->x + 				((st - pfrec->firstChar) % 32) * pfrec->maxWidth; 			srcy = pChunk->y; 			found = 1; 		    } 		    if (!found) 		    { 			CharInfoPtr pci; 			int oldTranslate = pGC->miTranslate; 			pGC->miTranslate = 0;
comment|/* we already translated it */
block|if ((st< firstCol) || (st> FONTLASTCOL(pfont)) || 			    !(pci =&pCI[st - firstCol])->exists) 			{
comment|/* 			     * we know the default char exists, or we 			     * would have skipped over this glyph. 			     * So put out the default glyph 			     */
block|pci =&pCI[chDefault - firstCol]; 			} 			if (back == -1) 			{ 			    (*pGC->ops->PolyGlyphBlt)(pDraw, pGC, x,  						      dsty + FONTMAXBOUNDS(pfont,ascent), 						      1,&pci, FONTGLYPHS(pfont)); 			    hardware->write_enable = zmask& fore; 			    hardware->window_move_replacement_rule =  				XHP_NewRule[pGC->alu][4]; 			    hardware->write_enable = zmask& ~fore; 			    hardware->window_move_replacement_rule = 				XHP_NewRule[pGC->alu][5]; 			} 			else 			{ 			    (*pGC->ops->ImageGlyphBlt)(pDraw, pGC, x,  						       dsty + FONTMAXBOUNDS(pfont,ascent), 						       1,&pci, FONTGLYPHS(pfont)); 			    hardware->write_enable = zmask& ~fore& ~back; 			    hardware->window_move_replacement_rule =  				XHP_NewRule[GXcopy] [0]; 			    hardware->write_enable = zmask& ~fore& back; 			    hardware->window_move_replacement_rule =  				XHP_NewRule[GXcopy] [1]; 			    hardware->write_enable = zmask& fore& ~back; 			    hardware->window_move_replacement_rule =  				XHP_NewRule[GXcopy] [2]; 			    hardware->write_enable = zmask& fore& back; 			    hardware->window_move_replacement_rule =  				XHP_NewRule[GXcopy] [3]; 			} 			pGC->miTranslate = oldTranslate; 			hardware->write_enable = zmask; 			hardware->frame_buf_write_enable = zmask; 			hardware->pixel_write_replacement_rule = GXcopy; 		    } 		    else 		    {
comment|/* 			 * use the block mover to place the glyph 			 */
block|if (!slen) 			{ 			    if (x+w> pBox->x2) 			    {
comment|/* clip last char to right edge */
block|w = pBox->x2 - x; 			    } 			}  			while (screenPlanes& hardware->move_active)  			    waitAwhile(screenPlanes); 			hardware->source_x = srcx + dx; 			hardware->source_y = srcy + dy; 			hardware->dest_x = x + dx; 			hardware->dest_y = y; 			hardware->window_width = w - dx; 			hardware->window_height = h; 			hardware->start_move = zmask; 		    } 		    x += w;
comment|/* move to start pos of next char on screen */
block|if (!slen) 			continue; 		}
comment|/* 		 * completely inside the clip box, put out each character 		 */
block|for (st = *str++; slen--; st = *str++) 		{ 		    if (!fDefaultExists&& 			((st< firstCol) || (st> numCols) || 			 !pCI[st - firstCol].exists)) 		    {
comment|/* 			 * if the default char doesn't exist, and this 			 * character doesn't exist, then do nothing 			 */
block|continue; 		    }  		    found = 0; 		    if (st>= pfrec->firstChar&& st<= pfrec->lastChar) 		    { 			srcx = 			    (pChunk = pfrec->ppChunk[(st - pfrec->firstChar)>> 5])->x + 				((st - pfrec->firstChar) % 32) * pfrec->maxWidth; 			srcy = pChunk->y; 			found = 1; 		    }  		    if (!found) 		    {
comment|/* 			 * the char wasn't in any chunk, so call ImageGlyphBlt 			 */
block|CharInfoPtr pci; 			int oldTranslate = pGC->miTranslate; 			pGC->miTranslate = 0;
comment|/* we already translated it */
block|if ((st< firstCol) || (st> numCols) || 			    !(pci =&pCI[st - firstCol])->exists) 			{
comment|/* 			     * we know the default char exists, or we 			     * would have skipped over this glyph. 			     * So put out the default glyph 			     */
block|pci =&pCI[chDefault - firstCol]; 			} 			if (back == -1) 			{ 			    (*pGC->ops->PolyGlyphBlt)(pDraw, pGC, x,  						      dsty + FONTMAXBOUNDS(pfont,ascent), 						      1,&pci, FONTGLYPHS(pfont)); 			    hardware->write_enable = zmask& fore; 			    hardware->window_move_replacement_rule =  				XHP_NewRule[pGC->alu][4]; 			    hardware->write_enable = zmask& ~fore; 			    hardware->window_move_replacement_rule = 				XHP_NewRule[pGC->alu][5]; 			} 			else 			{ 			    (*pGC->ops->ImageGlyphBlt)(pDraw, pGC, x,  						       dsty + FONTMAXBOUNDS(pfont,ascent), 						       1,&pci, FONTGLYPHS(pfont)); 			    hardware->write_enable = zmask& ~fore& ~back; 			    hardware->window_move_replacement_rule =  				XHP_NewRule[GXcopy] [0]; 			    hardware->write_enable = zmask& ~fore& back; 			    hardware->window_move_replacement_rule =  				XHP_NewRule[GXcopy] [1]; 			    hardware->write_enable = zmask& fore& ~back; 			    hardware->window_move_replacement_rule =  				XHP_NewRule[GXcopy] [2]; 			    hardware->write_enable = zmask& fore& back; 			    hardware->window_move_replacement_rule =  				XHP_NewRule[GXcopy] [3]; 			} 			pGC->miTranslate = oldTranslate; 			hardware->write_enable = zmask; 			hardware->frame_buf_write_enable = zmask; 			hardware->pixel_write_replacement_rule = GXcopy; 		    } 		    else 		    {
comment|/* 			 * use the block mover to place the glyph 			 */
block|if (!slen) 			{ 			    if (x+w> pBox->x2) 			    {
comment|/* clip last char to right edge */
block|w = pBox->x2 - x; 			    } 			}  			while(screenPlanes& hardware->move_active)  			    waitAwhile(screenPlanes); 			hardware->source_x = srcx; 			hardware->source_y = srcy + dy; 			hardware->dest_x = x; 			hardware->dest_y = y; 			hardware->window_width = w; 			hardware->window_height = h; 			hardware->start_move = zmask; 		    } 		    x += w;
comment|/* move to start pos of next char on screen */
block|} 	    } 	} 	break;       case Linear16Bit:       case TwoD16Bit: 	break;     }
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/************************************************************************  *  Routine:    tcImageVarText  *              Render text strings to the display with "optimized" fonts  *		in the case where the font is variable-width, and varible  *		ascent, etc.  *              Uses the Topcat block mover to place the character if the  *              character has been "optimized" (stored in offscreen memory).  *              If it's not in offscreen then we call pGC->ImageGlyphBlt.  *              It is assumed that these characters are drawn left  *              to right, and have the most-used characters stored in  *              offscreen memory. The characters must be stored in increasing  *		order in the chunks, e.g. char 78 *must* be further down the  *		list of chunks than char 57, though char 63 doesn't have to   *		be stored in offscreen. No chunk can have holes - the chars  *		must be contiguous within a chunk. In the example above, if  *		char 63 isn't stored, 57 and 78 *must* be in different chunks.  *  *		If pGC->bgPixel is -1, then assume we are being called by  *		PolyText, and make the glyph background a no-op (transparent).  *		This allows PolyText to be fast iff FillStyle == Solid.  *  *  Inputs: pDraw points to the drawable we're to print to  *          pGC points to the GC we're to use  *          x, y is the starting location for the string in the drawable  *          count is the number of characters we're to put out  *          chars points to an array of the characters we're to put out  *          encoding is Linear8Bit, Linear16Bit, etc.  *  *  Returns: nothing  *  *  Side Effects: none  *  */
end_comment

begin_function
name|void
name|tcImageOptText8
parameter_list|(
name|pDraw
parameter_list|,
name|pGC
parameter_list|,
name|dstx
parameter_list|,
name|dsty
parameter_list|,
name|count
parameter_list|,
name|chars
comment|/*, encoding */
parameter_list|)
name|DrawablePtr
name|pDraw
decl_stmt|;
name|GCPtr
name|pGC
decl_stmt|;
name|int
name|dstx
decl_stmt|,
name|dsty
decl_stmt|;
name|int
name|count
decl_stmt|;
name|u_char
modifier|*
name|chars
decl_stmt|;
comment|/* FontEncoding encoding; */
block|{
if|#
directive|if
literal|0
block|FontEncoding encoding = Linear8Bit;
comment|/* should be passed in ... */
block|register TOPCAT *hardware = getTcHardware(pDraw->pScreen);     int XHP_bits = hardware->bits;     unsigned long screenPlanes = getPlanesMask(pDraw->pScreen);     unsigned long zmask = pGC->planemask& screenPlanes;     int fore = pGC->fgPixel;     int back = pGC->bgPixel;      FontPtr pfont = pGC->font;     unsigned int firstCol = FONTFIRSTCOL(pfont);     unsigned int numCols = FONTLASTCOL(pfont) - firstCol + 1;     unsigned int chDefault = FONTDEFAULTCH(pfont);      int miny, maxy, minx, maxx;      CharInfoPtr pCI = pfont->pCI;     CharInfoPtr *ppCI;     ExtentInfoRec info;      hpFontRec *pfrec = (hpFontRec *)(pfont->devPriv[pDraw->pScreen->myNum]);     hpChunk *pChunk;     int numChunks = pfrec->NumChunks;     hpCharRange *pRange;     unsigned int maxWidth = pfrec->maxWidth;      RegionPtr pRegion = 	((cfbPrivGC *)pGC->devPrivates[cfbGCPrivateIndex].ptr)->pCompositeClip;     register BoxPtr pBox = REGION_RECTS(pRegion);     int nbox = REGION_NUM_RECTS(pRegion);      register int i, x, y, dx, dy, h, w, oldAlu, oldFS;     int n;     CARD32 oldFG;     int srcx, srcy;     int found = 0;
comment|/* flag for in/out of offscreen */
block|if (!count) 	return;      if (back != -1)     {
comment|/* 	 * Fill the background rectangle to the background color 	 */
comment|/* 	 * build the array of CharInfo struct pointers for glyphs in the string 	 */
block|if (!(ppCI = (CharInfoPtr *)ALLOCATE_LOCAL(count*sizeof(CharInfoPtr)))) 	    return; 	GetGlyphs(pfont, count, chars, Linear8Bit,&n, ppCI); 	QueryGlyphExtents(pGC->font, ppCI, n,&info);  	oldAlu = pGC->alu; 	oldFG = pGC->fgPixel; 	oldFS = pGC->fillStyle;
comment|/* fill in the background */
block|pGC->alu = (long) GXcopy; 	pGC->fgPixel = (long) pGC->bgPixel; 	pGC->fillStyle = (long) FillSolid; 	tcPaintBlockClipped(pDraw,pGC, 	    dstx +  		((pDraw->type == DRAWABLE_WINDOW) ? pDraw->x : PIXER(pDraw)->pChunk->x), 	    dsty - FONTASCENT(pGC->font) +  		((pDraw->type == DRAWABLE_WINDOW) ? pDraw->y : PIXER(pDraw)->pChunk->y), 	    info.overallWidth, 	    FONTASCENT(pGC->font) + FONTDESCENT(pGC->font));
comment|/* 	 * put the GC back except for alu 	 * in an ImageText, the effective alu is GXcopy 	 */
block|pGC->fgPixel = oldFG; 	pGC->fillStyle = oldFS;     }
comment|/*      * absolutize the coordinates       */
block|dstx += pDraw->x;     dsty += pDraw->y;      miny = dsty - FONTMAXBOUNDS(pfont,ascent);     maxy = dsty + FONTMAXBOUNDS(pfont,descent);     minx = dstx + FONTMINBOUNDS(pfont,leftSideBearing);
comment|/* is this right? */
block|maxx = dstx + count * maxWidth;      waitbusy(screenPlanes, hardware);
comment|/*      * set a PolyText type of replacement rule.      * we've cleared the background rectangle for the string in the case      * of an Imagetext call.      */
block|hardware->write_enable = zmask& fore;     hardware->window_move_replacement_rule = XHP_NewRule[pGC->alu][4];     hardware->write_enable = zmask& ~fore;     hardware->window_move_replacement_rule = XHP_NewRule[pGC->alu][5];      hardware->write_enable = zmask;     hardware->frame_buf_write_enable = zmask;     hardware->pixel_write_replacement_rule = GXcopy;      switch (encoding)     {       case Linear8Bit:        case TwoD8Bit: 	while (nbox--) 	{
comment|/* for each clip box */
comment|/* 	     * check to see if any characters may be in the clip box 	     * if any part may be in the box, write it 	     */
block|if ((pBox->x1<= maxx)&& (minx<= pBox->x2)&& 		(pBox->y1<= maxy)&& (miny<= pBox->y2)) 	    { 		register int slen = count; 		register u_char *str = chars; 		register unsigned char st = *str++; 		CharInfoPtr pci = pCI + st - firstCol;  		x = dstx;  		while ((st< firstCol) || (st> numCols) || !pci->exists) 		{
comment|/* 		     * check for non-existent glyphs& replace w/the default 		     * or skip it if the default doesn't exist 		     */
block|if ((chDefault< firstCol) ||  			!pCI[chDefault - firstCol].exists) 		    {
comment|/* 			 * if the default char doesn't exist, then do nothing 			 */
block|st = *str++; 			pci = pCI + st - firstCol; 			if (--slen == 0) 			    break; 			continue; 		    } 		    pci = pCI + chDefault - firstCol; 		    st = chDefault; 		}
comment|/* 		 * while the character is to the left of the clipping 		 * rectangle, go to the next character 		 */
block|while ((x+(w = pci->metrics.characterWidth))<= pBox->x1) 		{ 		    if (--slen<= 0) 		    { 			if (slen< 0) slen = 0; 			break; 		    } 		    x += w; 		    st = *str++; 		    pci = pCI + st - firstCol; 		    if (!pci->exists) 		    { 			pci = pCI + (chDefault - firstCol); 			st = chDefault; 		    } 		}
comment|/* 		 * clip the first "in" character to the edge 		 */
block|if ((dx = pBox->x1 - (x+pci->metrics.leftSideBearing))< 0) 		    dx = 0; 		if ((x+dx+pci->metrics.leftSideBearing)> pBox->x2) 		    slen = 0;
comment|/* 		 * in the clip box, put out each character 		 */
block|while (slen--) 		{
comment|/* for each char left in the string */
block|pci =&pCI[st - firstCol]; 		    if ((st< firstCol) || (st> numCols) || !pci->exists) 		    {
comment|/* 			 * check for non-existent glyphs& replace w/the default 			 */
block|st = chDefault; 			pci =&pCI[chDefault - firstCol]; 			if (st< firstCol || (st> numCols) || !pci->exists) 			{
comment|/* 			     * if the default doesn't exist, skip the char 			     */
block|st = *str++; 			    continue; 			} 		    }
comment|/* 		     * find the char's location in offscreen (hopefully) 		     */
block|found = 0;
comment|/* flag for in/out of offscreen */
block|for (i = 0, pRange = pfrec->pRange; i< numChunks; i++, pRange++) 		    { 			if (st<= pRange->endChar) 			{ 			    if (st>= pRange->startChar) 			    { 				found = 1;
comment|/* we found it */
block|pChunk = pfrec->ppChunk[i];  				srcx = pChunk->x + maxWidth * (st - pRange->startChar); 				srcy = pChunk->y; 				break; 			    } 			    else 			    {
comment|/* 				 * it's not in any of the chunks 				 */
block|break; 			    } 			} 		    }  		    if (!found) 		    {
comment|/* 			 * the char wasn't in any chunk, so call ImageGlyphBlt 			 */
block|CharInfoPtr localpci =&pCI[st - firstCol]; 			int oldTranslate = pGC->miTranslate; 			pGC->miTranslate = 0;
comment|/* we already translated it */
block|if (back == -1) 			    (*pGC->ops->PolyGlyphBlt)(pDraw, pGC, x, dsty, 						      1,&localpci, FONTGLYPHS(pfont)); 			else 			    (*pGC->ops->ImageGlyphBlt)(pDraw, pGC, x, dsty, 						       1,&localpci, FONTGLYPHS(pfont)); 			hardware->write_enable = zmask& fore; 			hardware->window_move_replacement_rule =  			    XHP_NewRule[pGC->alu][4]; 			hardware->write_enable = zmask& ~fore; 			hardware->window_move_replacement_rule = 			    XHP_NewRule[pGC->alu][5]; 			hardware->write_enable = zmask; 			hardware->frame_buf_write_enable = zmask; 			hardware->pixel_write_replacement_rule = GXcopy;  			pGC->miTranslate = oldTranslate;
comment|/* put it back */
block|} 		    else 		    {
comment|/* 			 * use the block mover to place the glyph 			 */
block|w = GLWIDTHPIXELS(pci); 			if (x+w+pci->metrics.leftSideBearing> pBox->x2) 			{
comment|/* clip to right edge */
block|w = pBox->x2 - (x + pci->metrics.leftSideBearing); 			}
comment|/* 			 * clip the height of the glyph 			 */
block|y = dsty - pci->metrics.ascent; 			dy = 0; 			h = GLHEIGHTPIXELS(pci); 			if (y< pBox->y1) 			{ 			    dy = pBox->y1 - y; 			    h -= dy; 			    y = pBox->y1; 			} 			if (y+h> pBox->y2) 			    h -= y + h -pBox->y2; 			 			if ((h> 0)&& (w> dx)) 			{ 			    waitbusy(screenPlanes, hardware); 			    hardware->source_x = (srcx + dx)<< XHP_bits; 			    hardware->source_y = srcy + dy; 			    hardware->dest_x = (x + dx +  						pci->metrics.leftSideBearing)<< XHP_bits; 			    hardware->dest_y = y; 			    hardware->window_width = (w - dx)<< XHP_bits; 			    hardware->window_height = h; 			    hardware->start_move = zmask; 			} 		    }
comment|/* move to start pos of next char on screen */
block|x += pci->metrics.characterWidth; 		    dx = 0; 		    if (x>= pBox->x2) 			slen = 0;
comment|/* no more within pBox */
block|st = *str++; 		} 	    } 	    pBox++; 	} 	break;       case Linear16Bit:       case TwoD16Bit: 	break;     }     if (back != -1)
comment|/* put the alu back right */
block|pGC->alu = oldAlu;      DEALLOCATE_LOCAL(ppCI);
endif|#
directive|endif
block|}
end_function

begin_function
name|int
name|tcPolyOptText8
parameter_list|(
name|pDraw
parameter_list|,
name|pGC
parameter_list|,
name|dstx
parameter_list|,
name|dsty
parameter_list|,
name|count
parameter_list|,
name|chars
comment|/*, encoding */
parameter_list|)
name|DrawablePtr
name|pDraw
decl_stmt|;
name|GCPtr
name|pGC
decl_stmt|;
name|int
name|dstx
decl_stmt|,
name|dsty
decl_stmt|;
name|int
name|count
decl_stmt|;
name|u_char
modifier|*
name|chars
decl_stmt|;
comment|/* FontEncoding encoding; */
block|{
if|#
directive|if
literal|0
block|if ((pGC->alu == GXcopy)&& (pGC->fillStyle == FillSolid))     {
comment|/* 	 * it looks enough like an imagetext that we can use tcImage???Text 	 */
block|register FontPtr pFont = pGC->font; 	int oldBackground; 	CharInfoPtr pci = pFont->pCI; 	unsigned char *thischar = chars;
comment|/* 	 * set background to -1 to tell tcImage???Text that the background 	 * should be transparent (no-op) 	 */
block|oldBackground = pGC->bgPixel; 	pGC->bgPixel = -1; 	(* pGC->ops->ImageText8)(pDraw, pGC, dstx, dsty, count, chars); 	pGC->bgPixel = oldBackground;  	while (count--) 	{ 	    dstx += pci[*thischar].metrics.characterWidth; 	    thischar++; 	} 	return dstx;     }     else 	return miPolyText8(pDraw, pGC, dstx, dsty, count, chars);
endif|#
directive|endif
block|}
end_function

end_unit

