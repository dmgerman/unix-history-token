begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: text.h,v 10.1 86/11/19 10:46:56 jg Exp $ */
end_comment

begin_comment
comment|/* text.h - macros and global data used by X text functions  *  *	Author:  *		Dan Stone& Scott Bates  *		Brown University  *		IRIS, Box 1946  *		Providence, RI 02912  *  *  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software  * without specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  */
end_comment

begin_comment
comment|/*  * Macros for all the combination rules which can be used.  */
end_comment

begin_define
define|#
directive|define
name|GXcopy_OP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst = (src)
end_define

begin_define
define|#
directive|define
name|GXor_OP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst = (dst) | (src)
end_define

begin_define
define|#
directive|define
name|GXxor_OP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst = (dst) ^ (src)
end_define

begin_define
define|#
directive|define
name|GXand_OP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst = (dst)& (src)
end_define

begin_define
define|#
directive|define
name|GXcopyInverted_OP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst = ~(src)
end_define

begin_define
define|#
directive|define
name|GXorInverted_OP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst = (dst) | ~(src)
end_define

begin_define
define|#
directive|define
name|GXequiv_OP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst = (dst) ^ ~(src)
end_define

begin_define
define|#
directive|define
name|GXandInverted_OP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst = (dst)& ~(src)
end_define

begin_define
define|#
directive|define
name|GXorReverse_OP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst = (~(dst) | (src))
end_define

begin_define
define|#
directive|define
name|GXandReverse_OP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst = (~(dst)& (src))
end_define

begin_define
define|#
directive|define
name|GXinvert_OP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst = ~(dst)
end_define

begin_define
define|#
directive|define
name|GXnand_OP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst = (~(dst) | ~(src))
end_define

begin_define
define|#
directive|define
name|GXnor_OP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst = (~(dst)& ~(src))
end_define

begin_define
define|#
directive|define
name|GXclear_OP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst = 0
end_define

begin_define
define|#
directive|define
name|GXset_OP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst = 0xFFFF
end_define

begin_define
define|#
directive|define
name|GXnoop_OP
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|)
value|dst = dst
end_define

begin_define
define|#
directive|define
name|GXcopy_MASK
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|mask
parameter_list|)
value|dst = ((dst)& ~(mask)) |	       \ 						  ((src)& mask)
end_define

begin_define
define|#
directive|define
name|GXor_MASK
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|mask
parameter_list|)
value|dst = ((dst) | ((src)& mask))
end_define

begin_define
define|#
directive|define
name|GXxor_MASK
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|mask
parameter_list|)
value|dst = ((dst) ^ ((src)& mask))
end_define

begin_define
define|#
directive|define
name|GXand_MASK
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|mask
parameter_list|)
value|dst = ((dst)& ~(mask)) |	       \ 						  (((dst)& (src))& mask)
end_define

begin_define
define|#
directive|define
name|GXcopyInverted_MASK
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|mask
parameter_list|)
value|dst = ((dst)& ~(mask)) |	       \ 						  (~(src)& mask)
end_define

begin_define
define|#
directive|define
name|GXorInverted_MASK
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|mask
parameter_list|)
value|dst = ((dst) | (~(src)& mask))
end_define

begin_define
define|#
directive|define
name|GXequiv_MASK
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|mask
parameter_list|)
value|dst = ((dst) ^ (~(src)& mask))
end_define

begin_define
define|#
directive|define
name|GXandInverted_MASK
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|mask
parameter_list|)
value|dst = ((dst)& ~(mask)) |	       \ 						  (((dst)& ~(src))& mask)
end_define

begin_define
define|#
directive|define
name|GXandReverse_MASK
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|mask
parameter_list|)
value|dst = ((dst)& ~(mask)) |	       \ 						  ((~(dst)& (src))& mask)
end_define

begin_define
define|#
directive|define
name|GXorReverse_MASK
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|mask
parameter_list|)
value|dst = ((dst)& ~(mask)) |	       \ 						  ((~(dst) | (src))& mask)
end_define

begin_define
define|#
directive|define
name|GXinvert_MASK
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|mask
parameter_list|)
value|dst = ((dst)& ~(mask)) |	       \ 						  (~(dst)& (mask))
end_define

begin_define
define|#
directive|define
name|GXnor_MASK
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|mask
parameter_list|)
value|dst = ((dst)& ~(mask)) |	       \ 						  ((~(dst)& ~(src))& mask)
end_define

begin_define
define|#
directive|define
name|GXnand_MASK
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|mask
parameter_list|)
value|dst = ((dst)& ~(mask)) |	       \ 						  ((~(dst) | ~(src))& mask)
end_define

begin_define
define|#
directive|define
name|GXclear_MASK
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|mask
parameter_list|)
value|dst = 0
end_define

begin_define
define|#
directive|define
name|GXset_MASK
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|mask
parameter_list|)
value|dst = 0xFFFF
end_define

begin_define
define|#
directive|define
name|GXnoop_MASK
parameter_list|(
name|src
parameter_list|,
name|dst
parameter_list|,
name|mask
parameter_list|)
value|dst = dst
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|BPL
end_ifndef

begin_define
define|#
directive|define
name|BPL
value|32
end_define

begin_define
define|#
directive|define
name|LOG2_BPL
value|5
end_define

begin_define
define|#
directive|define
name|MOD_BPL
parameter_list|(
name|value
parameter_list|)
value|((value)& (BPL - 1))
end_define

begin_define
define|#
directive|define
name|DIV_BPL
parameter_list|(
name|value
parameter_list|)
value|((value)>> LOG2_BPL)
end_define

begin_define
define|#
directive|define
name|MUL_BPL
parameter_list|(
name|value
parameter_list|)
value|((value)<< LOG2_BPL)
end_define

begin_comment
comment|/*  * Macro to convert Bits to Longs.  */
end_comment

begin_define
define|#
directive|define
name|BTOL
parameter_list|(
name|bits
parameter_list|)
value|(DIV_BPL((bits) + (BPL - 1)))
end_define

begin_define
define|#
directive|define
name|MUL_4
parameter_list|(
name|n
parameter_list|)
value|((n)<< 2)
end_define

begin_define
define|#
directive|define
name|DIV_4
parameter_list|(
name|n
parameter_list|)
value|((n)>> 2)
end_define

begin_endif
endif|#
directive|endif
endif|BPL
end_endif

begin_define
define|#
directive|define
name|SRC
value|((u_short *)src)
end_define

begin_define
define|#
directive|define
name|SRCPL
value|((u_short *)(src + 2))
end_define

begin_define
define|#
directive|define
name|DST
value|((u_short *)dst)
end_define

begin_define
define|#
directive|define
name|DSTPL
value|((u_short *)(dst + 2))
end_define

begin_comment
comment|/*  * Masks for to protect the left portion of a short.  That portion that should  * not be changed.  */
end_comment

begin_decl_stmt
specifier|static
name|u_short
name|leftmask_lib
index|[]
init|=
block|{
literal|0xFFFF
block|,
literal|0x7FFF
block|,
literal|0x3FFF
block|,
literal|0x1FFF
block|,
literal|0x0FFF
block|,
literal|0x07FF
block|,
literal|0x03FF
block|,
literal|0x01FF
block|,
literal|0x00FF
block|,
literal|0x007F
block|,
literal|0x003F
block|,
literal|0x001F
block|,
literal|0x000F
block|,
literal|0x0007
block|,
literal|0x0003
block|,
literal|0x0001
block|,
literal|0x0000
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * Masks for to protect the right portion of a short.  That portion that should  * not be changed.  */
end_comment

begin_decl_stmt
specifier|static
name|u_short
name|rightmask_lib
index|[]
init|=
block|{
literal|0xFFFF
block|,
literal|0x8000
block|,
literal|0xC000
block|,
literal|0xE000
block|,
literal|0xF000
block|,
literal|0xF800
block|,
literal|0xFC00
block|,
literal|0xFE00
block|,
literal|0xFF00
block|,
literal|0xFF80
block|,
literal|0xFFC0
block|,
literal|0xFFE0
block|,
literal|0xFFF0
block|,
literal|0xFFF8
block|,
literal|0xFFFC
block|,
literal|0xFFFE
block|,
literal|0x0000
block|}
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * This macro is used to copy characters from the fonts character bitmaps  * to the offscreen bitmap. Later the offscreen bitmap is copied to the screen  * using the bltter.  *  * The CopyText_LOOP is an optimization, of a more general bitblt loop.  * Because most text characters are less than 16 bits wide the CopyText_LOOP  * has 2 special inner loops for this size character image.  A character  * image thats less than 16 bits wide can only span at most 2 destination  * shorts, so the 2 special inner loops are designed for 1 destination and  * 2 destination shorts changing per line.  IF more than 2 destination words  * are to change then the general purpose loop is used.  *  * Some special notes:  *  * bitptr - A long integer that "points to" or "indexes into" one offscreen  *	    buffer scanline.  As if one scanline was an array of bits.  *  * src,dst - Are unsigned CHAR pointers and are cast to unsigned shorts  *	     when used as pointers.  Why?  IF src was an unsigned SHORT  *	     pointer and src += n was done, the current RT compiler  *	     would generate 2 extra assembly language instructions,  *	     one to shift n left (multiply by 2) and the other to  *	     compute the address.  *  * The offscreen buffer is the destination.  *  * Here is the algorithm for the CopyText_LOOP:  *   * FOREACH character DO  *     IF the character is not printable THEN  *	   continue  *     IF the character is wider than zero THEN  *	   set start_dst = To the destination short which contains the first  *			   bit to be changed.  *	   set shift = The first bit within start_dst to be changed.  *	   Increment bitptr past the current character.  *	   IF bitptr is beyond the last bit in the destination THEN  *	       Decrement bitptr back to its previous value.  *	       Decrement the character count.  *	       Break out of the loop.  *	   ENDIF  *  *	   Set the right mask using the right mask library and the NEW bitptr.  *	   Calculate the source pointer.  *	   Calculate the destination pointer.  *	   Calculate the number of shorts changed in the destination.  *  *	   IF no shifting needed THEN  *	       IF 1 destination short changed THEN  *		   FOREACH scanline DO  *		       Use the edge macro (see above) to combine src, dst and  *			   mask.  *		       Increment the source to the next scanline.  *		       Increment the destination to the next scanline.  *		   ENDFOR  *	       ELSE IF 2 destination shorts changed THEN  *		   FOREACH scanline DO  *		       Use the macro (see above) to combine src and dst.  *		       Use the edge macro (see above) to combine src+2, dst+2  *			   and mask.  *		       Increment the source to the next scanline.  *		       Increment the destination to the next scanline.  *		   ENDFOR  *	       ELSE  *		   Calculate the amount to decrement the dst to get back  *		       to the first scanline next short(the + 2).  *		   Calculate the amount to decrement the src to get back  *		       to the first scanline next short(the + 2).  *	   FOREACH short in the destination DO  *		       FOREACH scanline DO  *			   Use the macro (see above) to combine src and dst.  *			   Increment the source to the next scanline.  *			   Increment the destination to the next scanline.  *		       ENDFOR  *		       Decrement dst back to the first scanline, next short.  *		       Decrement src back to the first scanline, next short.  *		       Reset the number of scanlines (height).  *		   ENDFOR  *		   FOREACH scanline DO  *		       Use the edge macro to combine src, dst and mask.  *		       Increment the source to the next scanline.  *		       Increment the destination to the next scanline.  *		   ENDFOR  *	       ENDIF  *	   ELSE  *	       Get the left mask from the left mask library using shift.  *	       IF 1 destination short changed THEN  *		   Combine left and right masks.  *		   FOREACH scanline DO  *		       Use the edge macro (see above) to combine src shifted,  *			   with dst and mask.  *		       Increment the source to the next scanline.  *		       Increment the destination to the next scanline.  *		   ENDFOR  *	       ELSE IF 2 destination shorts changed THEN  *		   Set the inverse of shift = 16 - shift.  *		   IF the src bitmap is only 1 short wide THEN  *		       FOREACH scanline DO  *			   Use the edge macro (see above) to combine src  *			       shifted, with dst and left mask.  *			   Use the edge macro (see above) to combine src  *			       inversely shifted with dst+2 and right mask.  *			   Increment the source to the next scanline.  *			   Increment the destination to the next scanline.  *		       ENDFOR  *		   ELSE	 # src bitmap is wider than 1 short and the 2nd short  *			 # may have useful info in it.  *		       FOREACH scanline DO  *			   Use the edge macro (see above) to combine src  *			       shifted with dst and left mask.  *			   Use the edge macro (see above) to combine src  *			       shifted, src+2 inversely shifted with   *			       dst+2 and right mask.  *			   Increment the source to the next scanline.  *			   Increment the destination to the next scanline.  *		       ENDFOR  *	       ELSE  *		   Calculate the amount to decrement the dst to get back  *		       to the first scanline next short(the + 2).  *		   Calculate the amount to decrement the src to get back  *		       to the first scanline next short(the + 2).  *		   # Deal with the left edge.  *		   FOREACH scanline DO  *		       Use the edge macro (see above) to combine src shifted  *			   with dst and left mask.  *		       Increment the source to the next scanline.  *		       Increment the destination to the next scanline.  *		   ENDFOR  *		   # Now deal with the shorts between the left edge and right  *		   # edge.  *	   FOREACH short in the destination DO  *		       FOREACH scanline DO  *			   Use the macro (see above) to combine src inversely  *			       shifted or'ed with src+2 shifted with dst.  *			   Increment the source to the next scanline.  *			   Increment the destination to the next scanline.  *		       ENDFOR  *		       Decrement dst back to the first scanline, next short.  *		       Decrement src back to the first scanline, next short.  *		       Reset the number of scanlines (height).  *		   ENDFOR  *		   IF the number of destination shorts == the number of  *		       shorts wide the src is THEN  *		       # We have incremented to the last short in the src  *		       # scanline and should not use src+2.  *		       FOREACH scanline DO  *			   Use the edge macro to combine src inversely shifted,  *			       with dst and right mask.  *			   Increment the source to the next scanline.  *			   Increment the destination to the next scanline.  *			ENDFOR  *		   ELSE  *		       FOREACH scanline DO  *			   Use the edge macro to combine src inversely shifted  *			       or'ed with src+2 shifted, with dst and right  *			       mask.  *			   Increment the source to the next scanline.  *			   Increment the destination to the next scanline.  *			ENDFOR  *		   ENDIF  *	       ENDIF  *	   ENDIF  *     ENDIF  * ENDFOR  *  * NOTE: Make sure ch_pad is not added to the last character copied.  */
end_comment

begin_define
define|#
directive|define
name|CopyText_LOOP
parameter_list|(
name|EDGE_OP
parameter_list|,
name|OP
parameter_list|)
value|{					    \     for (i = ch_count + 1; --i; ) {					    \ 	if ((c = (int)(*string++))< font->first || c> font->last)	    \ 	    continue;
comment|/* Character is unprintable. */
value|\ 	if (char_widths[c]> 0) {					    \ 	    shift = bitptr& 0x0F;					    \ 	    start_dst = DIV_BPW(bitptr);				    \ 	    if (((bitptr += char_widths[c]) + ch_pad)> maxbitptr){	    \ 		bitptr -= char_widths[c];				    \ 		ch_count -= i;						    \ 		break;
comment|/* Overflow: Get out of the loop */
value|\ 	    }								    \ 	    rtmask = rightmask_lib[bitptr& 0x0F];			    \ 	    src = (u_char *)(chrs_data) + (shorts_per_char *		    \ 		  (c - font->first));					    \ 	    dst = (u_char *)buf_bm->data + MUL_2(start_dst);		    \ 	    ndst_shorts = DIV_BPW(bitptr - 1) - start_dst + 1;		    \ 	    height = ht_plus1;						    \ 	    if (shift == 0) {						    \ 		if (ndst_shorts == 1) {					    \ 		    while (--height) {					    \ 			EDGE_OP(*SRC, *DST, rtmask);			    \ 			dst += dst_nextline;				    \ 			src += src_nextline;				    \ 		    }							    \ 		} else if (ndst_shorts == 2) {				    \ 		    while (--height) {					    \ 			OP(*SRC, *DST);					    \ 			EDGE_OP(*SRCPL, *DSTPL, rtmask);		    \ 			dst += dst_nextline;				    \ 			src += src_nextline;				    \ 		    }							    \ 		} else {						    \ 		    height = font->height;				    \ 		    dst_nextcol = (height*dst_nextline) - 2;		    \ 		    src_nextcol = (height*src_nextline) - 2;		    \ 		    height++;						    \ 		    while (--ndst_shorts> 0) {				    \ 			while (--height) {				    \ 			    OP(*SRC, *DST);				    \ 			    dst += dst_nextline;			    \ 			    src += src_nextline;			    \ 			}						    \ 			dst -= dst_nextcol;				    \ 			src -= src_nextcol;				    \ 			height = ht_plus1;				    \ 		    }							    \ 		    while (--height) {					    \ 			EDGE_OP(*SRC, *DST, rtmask);			    \ 			dst += dst_nextline;				    \ 			src += src_nextline;				    \ 		    }							    \ 		}							    \ 	    } else {							    \ 		leftmask = leftmask_lib[shift];				    \ 		if (ndst_shorts == 1) {					    \ 		    leftmask&= rtmask;					    \ 		    while (--height) {					    \ 			EDGE_OP((*SRC>> shift), *DST, leftmask);	    \ 			dst += dst_nextline;				    \ 			src += src_nextline;				    \ 		    }							    \ 		} else if (ndst_shorts == 2) {				    \ 		    inv_shift = BPW - shift;				    \ 		    if (chrs_nshorts == 1) {				    \ 			while (--height) {				    \ 			    EDGE_OP((*SRC>> shift), *DST, leftmask);	    \ 			    EDGE_OP(*(SRC)<< inv_shift, *(DSTPL), rtmask); \ 			    dst += dst_nextline;			    \ 			    src += src_nextline;			    \ 			}						    \ 		    } else {						    \ 			while (--height) {				    \ 			    EDGE_OP((*SRC>> shift), *DST, leftmask);	    \ 			    EDGE_OP((*SRC<<inv_shift)|(*(SRCPL)>>shift),    \ 			        *(DSTPL), rtmask);			    \ 			    dst += dst_nextline;			    \ 			    src += src_nextline;			    \ 			}						    \ 		    }							    \ 		} else {						    \ 		    height = font->height;				    \ 		    dst_nextcol = (height*dst_nextline) - 2;		    \ 		    src_nextcol = (height*src_nextline) - 2;		    \ 		    height++;						    \ 		    while (--height) {					    \ 			EDGE_OP((*SRC>> shift), *DST, leftmask);	    \ 			dst += dst_nextline;				    \ 			src += src_nextline;				    \ 		    }							    \ 		    dst -= dst_nextcol;					    \ 		    src -= (src_nextcol + 2);				    \ 		    inv_shift = BPW - shift;				    \ 		    nsrc_shorts = ndst_shorts - 1;			    \ 		    while (--ndst_shorts> 1) {				    \ 			height = ht_plus1;				    \ 			while (--height) {				    \ 			    OP((*SRC<<inv_shift)|(*(SRCPL)>>shift),*DST);   \ 			    dst += dst_nextline;			    \ 			    src += src_nextline;			    \ 			}						    \ 			dst -= dst_nextcol;				    \ 			src -= src_nextcol;				    \ 		    }							    \ 		    height = ht_plus1;					    \ 		    if (nsrc_shorts == chrs_nshorts) {			    \ 			while (--height) {				    \ 			    EDGE_OP((*SRC<< inv_shift), *DST, rtmask);	    \ 			    dst += dst_nextline;			    \ 			    src += src_nextline;			    \ 			}						    \ 		    } else {						    \ 			while (--height) {				    \ 			    EDGE_OP((*SRC<< inv_shift) | (*(SRCPL)>>	    \ 			    shift), *DST, rtmask);			    \ 			    dst += dst_nextline;			    \ 			    src += src_nextline;			    \ 			}						    \ 		    }							    \ 		}							    \ 	    }								    \ 	    bitptr += ch_pad;						    \ 	}								    \ 	if (c == font->space) {						    \ 	    if ((bitptr += sp_pad)> maxbitptr) {			    \ 		bitptr -= sp_pad;					    \ 		ch_count -= i;						    \ 		break;
comment|/* Overflow: Get out of the loop. */
value|\ 	    }								    \ 	}								    \     }									    \ }
end_define

end_unit

