begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  Copyright (c) 1986, 1987 by Hewlett-Packard Company Copyright (c) 1986, 1987 by the Massachusetts Institute of Technology  Permission to use, copy, modify, and distribute this software and its documentation for any purpose and without fee is hereby granted, provided that the above copyright notice appear in all copies and that both that copyright notice and this permission notice appear in supporting documentation, and that the name of M.I.T. not be used in advertising or publicity pertaining to distribution of the software without specific, written prior permission.  HEWLETT-PACKARD MAKES NO WARRANTY OF ANY KIND WITH REGARD TO THIS SOFWARE, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR  PURPOSE.  Hewlett-Packard shall not be liable for errors  contained herein or direct, indirect, special, incidental or  consequential damages in connection with the furnishing,  performance, or use of this material.  This software is not subject to any license of the American Telephone and Telegraph Company or of the Regents of the University of California.  */
end_comment

begin_comment
comment|/***********************************************************************  *  file: hpFonts.h  *  *  Header file for font and text routines  *  *		Hewlett Packard -- Corvallis Workstation Operation  *		Project -- port of X11 to HP9000  *		Harry Phinney -- MTS  *  *  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|_chunkcontents
block|{
name|int
name|startChar
decl_stmt|;
name|int
name|endChar
decl_stmt|;
block|}
name|hpCharRange
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_hpFontRec
block|{
name|int
name|NumChunks
decl_stmt|;
comment|/* num of segments the font is broken into */
name|hpCharRange
modifier|*
name|pRange
decl_stmt|;
comment|/* start& end char in each chunk */
name|hpChunk
modifier|*
modifier|*
name|ppChunk
decl_stmt|;
comment|/* array of chunks font is stored in */
name|hpChunk
modifier|*
name|stippleChunk
decl_stmt|;
comment|/* space for stippling one glyph at a time */
name|Bool
name|fDefaultExists
decl_stmt|;
comment|/* flag for existance of default char */
name|int
name|maxWidth
decl_stmt|;
name|int
name|maxHeight
decl_stmt|;
name|int
name|firstChar
decl_stmt|;
name|int
name|lastChar
decl_stmt|;
block|}
name|hpFontRec
typedef|;
end_typedef

begin_comment
comment|/*  * The following determine which characters get optimized, and what  * size chunks are allocated in offscreen memory.  * This info should probably be gotten from properties stored with the  * font. These choices are a bit ethnocentric, but there you are...  */
end_comment

begin_define
define|#
directive|define
name|STARTCHAR
value|32
end_define

begin_define
define|#
directive|define
name|LASTCHAR
value|127
end_define

begin_define
define|#
directive|define
name|CHARSPERCHUNK
value|32
end_define

end_unit

