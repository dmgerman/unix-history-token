begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * hpspritest.h  *  * hp sprite structures  */
end_comment

begin_comment
comment|/* $XConsortium: mispritest.h,v 5.8 89/10/03 19:45:31 keith Exp $ */
end_comment

begin_comment
comment|/* Copyright 1989 by the Massachusetts Institute of Technology  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  M.I.T. makes no representations about the suitability of this software for any purpose.  It is provided "as is" without express or implied warranty. */
end_comment

begin_define
define|#
directive|define
name|SOURCE_COLOR
value|0
end_define

begin_define
define|#
directive|define
name|MASK_COLOR
value|1
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|GCFuncs
modifier|*
name|wrapFuncs
decl_stmt|;
name|GCOps
modifier|*
name|wrapOps
decl_stmt|;
block|}
name|hpSpriteGCRec
operator|,
typedef|*
name|hpSpriteGCPtr
typedef|;
end_typedef

begin_function_decl
specifier|extern
name|void
name|QueryGlyphExtents
parameter_list|()
function_decl|;
end_function_decl

begin_comment
comment|/*  * Overlap BoxPtr and Box elements  */
end_comment

begin_define
define|#
directive|define
name|BOX_OVERLAP
parameter_list|(
name|pCbox
parameter_list|,
name|X1
parameter_list|,
name|Y1
parameter_list|,
name|X2
parameter_list|,
name|Y2
parameter_list|)
define|\
value|(((pCbox)->x1<= (X2))&& ((X1)<= (pCbox)->x2)&& \ 	 ((pCbox)->y1<= (Y2))&& ((Y1)<= (pCbox)->y2))
end_define

begin_comment
comment|/*  * Overlap BoxPtr, origins, and rectangle  */
end_comment

begin_define
define|#
directive|define
name|ORG_OVERLAP
parameter_list|(
name|pCbox
parameter_list|,
name|xorg
parameter_list|,
name|yorg
parameter_list|,
name|x
parameter_list|,
name|y
parameter_list|,
name|w
parameter_list|,
name|h
parameter_list|)
define|\
value|BOX_OVERLAP((pCbox),(x)+(xorg),(y)+(yorg),(x)+(xorg)+(w),(y)+(yorg)+(h))
end_define

begin_comment
comment|/*  * Overlap BoxPtr, origins and RectPtr  */
end_comment

begin_define
define|#
directive|define
name|ORGRECT_OVERLAP
parameter_list|(
name|pCbox
parameter_list|,
name|xorg
parameter_list|,
name|yorg
parameter_list|,
name|pRect
parameter_list|)
define|\
value|ORG_OVERLAP((pCbox),(xorg),(yorg),(pRect)->x,(pRect)->y, \ 		(int)((pRect)->width), (int)((pRect)->height))
end_define

begin_comment
comment|/*  * Overlap BoxPtr and horizontal span  */
end_comment

begin_define
define|#
directive|define
name|SPN_OVERLAP
parameter_list|(
name|pCbox
parameter_list|,
name|y
parameter_list|,
name|x
parameter_list|,
name|w
parameter_list|)
value|BOX_OVERLAP((pCbox),(x),(y),(x)+(w),(y))
end_define

begin_define
define|#
directive|define
name|LINE_SORT
parameter_list|(
name|x1
parameter_list|,
name|y1
parameter_list|,
name|x2
parameter_list|,
name|y2
parameter_list|)
define|\
value|{ int _t; \   if (x1> x2) { _t = x1; x1 = x2; x2 = _t; } \   if (y1> y2) { _t = y1; y1 = y2; y2 = _t; } }
end_define

begin_define
define|#
directive|define
name|LINE_OVERLAP
parameter_list|(
name|pCbox
parameter_list|,
name|x1
parameter_list|,
name|y1
parameter_list|,
name|x2
parameter_list|,
name|y2
parameter_list|,
name|lw2
parameter_list|)
define|\
value|BOX_OVERLAP((pCbox), (x1)-(lw2), (y1)-(lw2), (x2)+(lw2), (y2)+(lw2))
end_define

end_unit

