begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $Header: font.h,v 10.1 86/11/19 10:45:35 jg Exp $ */
end_comment

begin_comment
comment|/* Copyright 1985 Massachusetts Institute of Technology */
end_comment

begin_comment
comment|/* font.h - Definitions required to access X fonts  * 		  *  *		Copyright (c) 1986 Brown University  *  * Permission to use, copy, modify and distribute this software and its  * documentation for any purpose and without fee is hereby granted, provided  * that the above copyright notice appear in all copies, and that both  * that copyright notice and this permission notice appear in supporting  * documentation, and that the name of Brown University not be used in  * advertising or publicity pertaining to distribution of the software  * without specific, written prior permission. Brown University makes no  * representations about the suitability of this software for any purpose.  * It is provided "as-is" without express or implied warranty.  */
end_comment

begin_define
define|#
directive|define
name|CHARPERFONT
value|256
end_define

begin_typedef
typedef|typedef
name|short
name|a_BitmapEntryPtr
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_Bitmap
block|{
name|a_BitmapEntryPtr
name|bm_address
decl_stmt|;
name|short
name|bm_width
decl_stmt|;
name|short
name|bm_height
decl_stmt|;
name|short
name|bm_bitsPerPixel
decl_stmt|;
block|}
name|BitMap
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_Bitmap
index|[
literal|5
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|a_FontWidthEntryPtr
index|[
literal|2
index|]
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_FontData
block|{
name|a_Bitmap
name|f_characters
decl_stmt|;
name|short
name|f_firstChar
decl_stmt|;
name|short
name|f_lastChar
decl_stmt|;
name|a_FontWidthEntryPtr
name|f_leftArray
decl_stmt|;
name|short
name|f_baseline
decl_stmt|;
name|short
name|f_spaceIndex
decl_stmt|;
name|short
name|f_fixedWidth
decl_stmt|;
block|}
name|FontData
typedef|;
end_typedef

end_unit

