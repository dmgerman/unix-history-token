begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Copyright (c) 1986, 1987 by Hewlett-Packard Company Copyright (c) 1986, 1987 by the Massachusetts Institute of Technology  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  HEWLETT-PACKARD MAKES NO WARRANTY OF ANY KIND WITH REGARD TO THIS SOFWARE, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  PURPOSE.  Hewlett-Packard shall not be liable for errors  contained herein or direct, indirect, special, incidental or  consequential damages in connection with the furnishing,  performance, or use of this material.  This software is not subject to any license of the American Telephone and Telegraph Company or of the Regents of the University of California.  */
end_comment

begin_comment
comment|/***********************************************************************  *  file: hpFonts.c  *  *  Font optimization/removal and text output routines  *  *		Hewlett Packard -- Corvallis Workstation Operation  *		Project -- port of X11 to HP9000  *		Harry Phinney -- MTS  *  *  */
end_comment

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
file|"misc.h"
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
file|"scrnintstr.h"
end_include

begin_include
include|#
directive|include
file|"hpOScrnBuf.h"
end_include

begin_include
include|#
directive|include
file|"hpFonts.h"
end_include

begin_include
include|#
directive|include
file|"hppriv.h"
end_include

begin_function_decl
specifier|extern
name|char
modifier|*
name|NameForAtom
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/* in dix/atom.c */
end_comment

begin_function_decl
specifier|static
name|int
name|hpAllocFontMem
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|static
name|void
name|hpStoreFont
parameter_list|()
function_decl|;
end_function_decl

begin_function
specifier|static
name|int
name|lookUpProperty
parameter_list|(
name|pFont
parameter_list|,
name|pName
parameter_list|)
specifier|register
name|FontRec
modifier|*
name|pFont
decl_stmt|;
specifier|register
name|char
modifier|*
name|pName
decl_stmt|;
block|{
specifier|register
name|int
name|n
init|=
name|FONTINFONPROPS
argument_list|(
name|pFont
argument_list|)
decl_stmt|;
specifier|register
name|FontPropPtr
name|pFP
init|=
name|FONTPROPS
argument_list|(
name|pFont
argument_list|)
decl_stmt|;
for|for
control|(
init|;
name|n
operator|--
condition|;
name|pFP
operator|++
control|)
block|{
specifier|register
name|char
modifier|*
name|pPropString
decl_stmt|;
if|if
condition|(
operator|(
name|pPropString
operator|=
name|NameForAtom
argument_list|(
name|pFP
operator|->
name|name
argument_list|)
operator|)
operator|&&
operator|!
name|strcmp
argument_list|(
name|pPropString
argument_list|,
name|pName
argument_list|)
condition|)
return|return
operator|(
name|int
operator|)
name|pFP
operator|->
name|value
return|;
block|}
return|return
literal|0
return|;
block|}
end_function

begin_comment
comment|/************************************************************************  *  Routine:	hpRealizeFont  *		Optimize the font i.e. store it in offscreen memory  *		This implementation (like our X10) only stores  *		the characters defined by STARTCHAR thru LASTCHAR in  *		offscreen.  It breaks them into offscreen chunks  *		of CHARSPERCHUNK size  *  *  Inputs: pScreen points to the ScreenRec we'll try to optimize for  *	    pFont points to the font we'll store in offscreen  *    *  Returns: TRUE (always)  *  *  Side Effects:  sets pFont->devPriv[pScreen->myNum] to point to an  *		hpFontRec which identifies the location of the font  *		in offscreen.  *  */
end_comment

begin_function
name|Bool
name|hpRealizeFont
parameter_list|(
name|pScreen
parameter_list|,
name|pFont
parameter_list|)
name|ScreenPtr
name|pScreen
decl_stmt|;
name|FontRec
modifier|*
name|pFont
decl_stmt|;
block|{
if|#
directive|if
literal|0
block|int index = pScreen->myNum;     CharInfoPtr pCI = pFont->pCI;     unsigned int chDefault =  FONTDEFAULTCH(pFont);     unsigned int firstCol = FONTFIRSTCOL(pFont);     unsigned int lastCol = FONTLASTCOL(pFont);     int glyphWidth = FONTMAXBOUNDS(pFont,rightSideBearing) - 	FONTMINBOUNDS(pFont,leftSideBearing);     int glyphHeight = FONTMAXBOUNDS(pFont,ascent) + 	FONTMAXBOUNDS(pFont,descent);     hpFontRec *pHpFrec;     hpCharRange *pRange;     int i, prop, startChar, lastChar;
comment|/*      * if it's right-to-left, or if the      * glyphs are bigger than 24 pixels wide,      * then don't optimize it.      */
block|if (pFont->info.drawDirection || (glyphWidth> 24))     { 	pFont->devPriv[index] = (pointer) NULL; 	return TRUE;     }
comment|/*      * allocate an hpFontRec      */
block|pHpFrec = (hpFontRec *) xalloc(sizeof (hpFontRec));     if (!pHpFrec)     { 	pFont->devPriv[index] = (pointer) NULL; 	return TRUE;     }
comment|/*      * allocate the space for stippling a character      */
block|if (!(pHpFrec->stippleChunk = hpBufAlloc(pScreen, glyphWidth, glyphHeight)))     { 	xfree(pHpFrec); 	pFont->devPriv[index] = (pointer) NULL; 	return TRUE;     }
comment|/*      * Check to see if the font has properties telling which characters      * to optimize      */
block|if (prop = lookUpProperty(pFont, "HPSTARTOPTIMIZE")) 	startChar = prop;     else 	startChar = STARTCHAR;     if (prop = lookUpProperty(pFont, "HPENDOPTIMIZE")) 	lastChar = prop;     else 	lastChar = LASTCHAR;
comment|/*      * allocate the offscreen, and put the chunk info in the hpFontRec      */
block|if (!hpAllocFontMem(pScreen, pFont, pHpFrec, startChar,  			lastChar, CHARSPERCHUNK))     { 	hpBufFree(pScreen, pHpFrec->stippleChunk); 	xfree(pHpFrec); 	pFont->devPriv[index] = (pointer) NULL; 	return TRUE;     }
comment|/*      * attach the hpFontRec to the devPriv field in the Font      */
block|pFont->devPriv[index] = (pointer) pHpFrec;      pRange = pHpFrec->pRange;
comment|/*      * store the font in the offscreen memory      */
block|for (i = 0; i< pHpFrec->NumChunks; i++)     { 	hpStoreFont(pScreen, pFont, i, startChar + (i * CHARSPERCHUNK),  		    CHARSPERCHUNK); 	pRange[i].startChar = startChar + (i * CHARSPERCHUNK); 	pRange[i].endChar = pRange[i].startChar + CHARSPERCHUNK - 1;     }     pHpFrec->maxWidth = glyphWidth;     pHpFrec->maxHeight = glyphHeight;     pHpFrec->firstChar = startChar;     pHpFrec->lastChar = lastChar;
comment|/*      * check for the existence of the default glyph.  If it exists, then      * hpStoreFont will have put it in place of any nonexistent glyphs.      * If it doesn't exist, then the text output routines have to skip      * any non-existent character.      */
block|pHpFrec->fDefaultExists = !((chDefault< firstCol) ||  				(chDefault> lastCol) || 				!pCI[chDefault - firstCol].exists);
endif|#
directive|endif
return|return
name|TRUE
return|;
block|}
end_function

begin_comment
comment|/************************************************************************  *  Routine:	hpUnrealizeFont  *		If the font had been stored in offscreen memory  *		then free all the associated memory.  *  *  Inputs: pScreen points to the ScreenRec the font was realized for  *	    pFont points to the font we're unrealizing  *    *  Returns: nothing of importance  *  *  Side Effects:  none  *  */
end_comment

begin_function
name|Bool
name|hpUnrealizeFont
parameter_list|(
name|pScreen
parameter_list|,
name|pFont
parameter_list|)
specifier|register
name|ScreenPtr
name|pScreen
decl_stmt|;
specifier|register
name|FontRec
modifier|*
name|pFont
decl_stmt|;
block|{
if|#
directive|if
literal|0
block|int index = pScreen->myNum;     register hpFontRec *pHpFrec;     register int i;
comment|/*      * test to see if we ever optimized this font      */
block|if (! pFont->devPriv[index]) 	return TRUE;           pHpFrec = (hpFontRec *) pFont->devPriv[index];
comment|/*      * mark the font as unoptimized      */
block|pFont->devPriv[index] = (pointer) NULL;
comment|/*      * free the offscreen chunks      */
block|for (i = 0; i< pHpFrec->NumChunks; i++) 	hpBufFree(pScreen, pHpFrec->ppChunk[i]);
comment|/*      * free the stippleChunk      */
block|hpBufFree(pScreen, pHpFrec->stippleChunk);
comment|/*      * free the chunk table      */
block|xfree(pHpFrec->ppChunk);
comment|/*      * free the range array      */
block|xfree(pHpFrec->pRange);
comment|/*      * finally, free the hpFontRec itself      */
block|xfree(pHpFrec);
endif|#
directive|endif
return|return
name|TRUE
return|;
block|}
end_function

begin_comment
comment|/************************************************************************  *  Routine:	hpAllocFontMem  *		Get enough offscreen memory on the screen to optomize  *		the font and store the locations in an hpFontRec  *  *  Inputs: pScreen points to the ScreenRec we'll get the memory on   *	    pFont points to the font we're allocating for  *	    phpFontRec we fill out telling where the memory is alloc'd  *	    first and last specify the first and last glyphs to allocate for  *	    size specifies the size of each chunk in glyphs  *    *  Returns: 1 for success, 0 for not enough offscreen memory  *  *  Side Effects:  none  *  */
end_comment

begin_function
specifier|static
name|int
name|hpAllocFontMem
parameter_list|(
name|pScn
parameter_list|,
name|pFnt
parameter_list|,
name|pHpFrec
parameter_list|,
name|first
parameter_list|,
name|last
parameter_list|,
name|size
parameter_list|)
name|ScreenPtr
name|pScn
decl_stmt|;
name|FontRec
modifier|*
name|pFnt
decl_stmt|;
name|hpFontRec
modifier|*
name|pHpFrec
decl_stmt|;
name|int
name|first
decl_stmt|,
name|last
decl_stmt|,
name|size
decl_stmt|;
block|{
name|int
name|i
decl_stmt|;
name|int
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* width& height of each chunk */
name|int
name|total
init|=
name|last
operator|-
name|first
operator|+
literal|1
decl_stmt|;
comment|/* total num chars to allocate for */
name|int
name|num_chunks
init|=
name|total
operator|/
name|size
decl_stmt|;
if|if
condition|(
name|total
operator|%
name|size
condition|)
name|num_chunks
operator|++
expr_stmt|;
name|pHpFrec
operator|->
name|ppChunk
operator|=
operator|(
name|hpChunk
operator|*
operator|*
operator|)
name|xalloc
argument_list|(
sizeof|sizeof
argument_list|(
name|hpChunk
operator|*
argument_list|)
operator|*
name|num_chunks
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|pHpFrec
operator|->
name|ppChunk
operator|)
condition|)
return|return
literal|0
return|;
name|pHpFrec
operator|->
name|NumChunks
operator|=
name|num_chunks
expr_stmt|;
name|pHpFrec
operator|->
name|pRange
operator|=
operator|(
name|hpCharRange
operator|*
operator|)
name|xalloc
argument_list|(
sizeof|sizeof
argument_list|(
name|hpCharRange
argument_list|)
operator|*
name|num_chunks
argument_list|)
expr_stmt|;
if|if
condition|(
operator|!
operator|(
name|pHpFrec
operator|->
name|pRange
operator|)
condition|)
return|return
literal|0
return|;
comment|/*      * figure out how much memory we need      * allocates enough memory to contain "total"      * number of maximum-sized glyphs      */
name|width
operator|=
operator|(
name|FONTMAXBOUNDS
argument_list|(
name|pFnt
argument_list|,
name|rightSideBearing
argument_list|)
operator|-
name|FONTMINBOUNDS
argument_list|(
name|pFnt
argument_list|,
name|leftSideBearing
argument_list|)
operator|)
operator|*
name|size
expr_stmt|;
name|height
operator|=
name|FONTMAXBOUNDS
argument_list|(
name|pFnt
argument_list|,
name|ascent
argument_list|)
operator|+
name|FONTMAXBOUNDS
argument_list|(
name|pFnt
argument_list|,
name|descent
argument_list|)
expr_stmt|;
for|for
control|(
name|i
operator|=
literal|0
init|;
name|i
operator|<
name|num_chunks
condition|;
name|i
operator|++
control|)
block|{
comment|/* 	 * get offscreen memory 	 */
if|if
condition|(
operator|(
name|pHpFrec
operator|->
name|ppChunk
index|[
name|i
index|]
operator|=
name|hpBufAlloc
argument_list|(
name|pScn
argument_list|,
name|width
argument_list|,
name|height
argument_list|)
operator|)
operator|==
name|NULL
condition|)
block|{
comment|/* 	     * if it fails, we've gotta free up all the data structures 	     */
while|while
condition|(
name|i
condition|)
name|hpBufFree
argument_list|(
name|pScn
argument_list|,
name|pHpFrec
operator|->
name|ppChunk
index|[
operator|--
name|i
index|]
argument_list|)
expr_stmt|;
name|pHpFrec
operator|->
name|NumChunks
operator|=
literal|0
expr_stmt|;
name|xfree
argument_list|(
name|pHpFrec
operator|->
name|ppChunk
argument_list|)
expr_stmt|;
name|pHpFrec
operator|->
name|ppChunk
operator|=
operator|(
name|hpChunk
operator|*
operator|*
operator|)
name|NULL
expr_stmt|;
name|xfree
argument_list|(
name|pHpFrec
operator|->
name|pRange
argument_list|)
expr_stmt|;
name|pHpFrec
operator|->
name|pRange
operator|=
operator|(
name|hpCharRange
operator|*
operator|)
name|NULL
expr_stmt|;
return|return
literal|0
return|;
block|}
block|}
return|return
literal|1
return|;
block|}
end_function

begin_comment
comment|/************************************************************************  *  Routine:	hpStoreFont  *		Write font glyphs into previously allocated offscreen memory  *		Stores a contiguous range of glyphs e.g. 32-63  *		Calls hpWholeGlyph (LIE) to put the bits in the framebuffer  *		with no clipping  *  *  Inputs: pScreen points to the ScreenRec whose memory we write to  *	    pFont points to the font we'll store in offscreen  *	    index gets us to the chunk to store the glyphs in  *	    start and num define the range of glyphs to store  *    *  Returns: nothing of importance  *  *  Side Effects:  none  *  */
end_comment

begin_decl_stmt
specifier|static
name|void
name|hpStoreFont
argument_list|(
name|pScn
argument_list|,
name|pFnt
argument_list|,
name|chunkNum
argument_list|,
name|startGlyph
argument_list|,
name|numGlyphs
argument_list|)
name|ScreenPtr
name|pScn
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|register
name|FontRec
modifier|*
name|pFnt
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|chunkNum
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* index into array of chunks */
end_comment

begin_decl_stmt
name|int
name|startGlyph
decl_stmt|;
end_decl_stmt

begin_expr_stmt
specifier|register
name|numGlyphs
expr_stmt|;
end_expr_stmt

begin_block
block|{
if|#
directive|if
literal|0
block|int glyphNum = startGlyph;     char *pCurrentGlyph;     register CharInfoPtr pCi;     int cellWidth = FONTMAXBOUNDS(pFnt,rightSideBearing) - 	FONTMINBOUNDS(pFnt,leftSideBearing);     int defaultChar = FONTDEFAULTCH(pFnt);     hpChunk *pChunk = ((hpFontRec *)pFnt->devPriv[pScn->myNum])-> 	ppChunk[chunkNum];     hpPrivScreenPtr pPrivScn = getPrivScreenPtr(pScn);     register x;     int y;     unsigned int firstCol = FONTFIRSTCOL(pFnt);     unsigned int lastCol = FONTLASTCOL(pFnt);     CharInfoPtr pDefaultCi = (CharInfoPtr)&(pFnt->pCI[defaultChar - firstCol]);     char *pDefaultGlyph = FONTGLYPHS(pFnt) + pDefaultCi->byteOffset;     int fDefaultExists = !((defaultChar< firstCol) || 			   (defaultChar> lastCol) || 			   !pDefaultCi->exists);      x = pChunk->x;     y = pChunk->y;      while (numGlyphs--)     { 	if (glyphNum> lastCol) break;  	pCi =&(pFnt->pCI[glyphNum - firstCol]); 	if ((glyphNum>= firstCol)&& pCi->exists) 	{ 	    pCurrentGlyph = FONTGLYPHS(pFnt) + pCi->byteOffset; 	    (*pPrivScn->WholeGlyph)(pScn, pCurrentGlyph, pCi, x, y, 				    GXcopy, ~0, 0, pPrivScn->planesMask); 	} 	else 	{ 	    if (fDefaultExists) 		(*pPrivScn->WholeGlyph)(pScn, pDefaultGlyph, pDefaultCi, x, y, 					GXcopy, ~0, 0, pPrivScn->planesMask); 	} 	glyphNum++; 	x += cellWidth; 	pCi++;     }
endif|#
directive|endif
block|}
end_block

end_unit

