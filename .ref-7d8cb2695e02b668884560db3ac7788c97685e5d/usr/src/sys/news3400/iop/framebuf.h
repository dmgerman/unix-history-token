begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: framebuf.h,v 4.300 91/06/09 06:42:21 root Rel41 $ SONY  *  *	@(#)framebuf.h	7.2 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__FRAMEBUF__
end_ifndef

begin_define
define|#
directive|define
name|__FRAMEBUF__
value|1
end_define

begin_typedef
typedef|typedef
name|unsigned
name|short
name|Word
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BitsPerWord
value|16
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|sPoint
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|x
decl_stmt|,
name|y
decl_stmt|;
block|}
name|lPoint
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|sPoint
name|origin
decl_stmt|;
name|sPoint
name|extent
decl_stmt|;
block|}
name|sRectangle
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|lPoint
name|origin
decl_stmt|;
name|lPoint
name|extent
decl_stmt|;
block|}
name|lRectangle
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|type
decl_stmt|;
comment|/* BM_FB, BM_MEM, BM_0, BM_1 or BM_LBP */
name|char
name|depth
decl_stmt|;
comment|/* bitmap depth */
name|unsigned
name|short
name|width
decl_stmt|;
comment|/* width in Words */
name|sRectangle
name|rect
decl_stmt|;
comment|/* defined area */
name|Word
modifier|*
name|base
decl_stmt|;
comment|/* for BM_MEM */
block|}
name|sBitmap
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|type
decl_stmt|;
comment|/* BM_FB, BM_MEM, BM_0, BM_1 or BM_LBP */
name|char
name|depth
decl_stmt|;
comment|/* bitmap depth */
name|unsigned
name|short
name|width
decl_stmt|;
comment|/* width in Words */
name|lRectangle
name|rect
decl_stmt|;
comment|/* defined area */
name|Word
modifier|*
name|base
decl_stmt|;
comment|/* for BM_MEM */
block|}
name|lBitmap
typedef|;
end_typedef

begin_define
define|#
directive|define
name|BM_FB
value|0
end_define

begin_comment
comment|/* frame buffer */
end_comment

begin_define
define|#
directive|define
name|BM_MEM
value|1
end_define

begin_comment
comment|/* bitmap in memory (XY format) */
end_comment

begin_define
define|#
directive|define
name|BM_0
value|2
end_define

begin_comment
comment|/* virtual bitmap of data '0' */
end_comment

begin_define
define|#
directive|define
name|BM_1
value|3
end_define

begin_comment
comment|/* virtual bitmap of data '1' */
end_comment

begin_define
define|#
directive|define
name|BM_LBP
value|4
end_define

begin_comment
comment|/* lbp page buffer (future support) */
end_comment

begin_comment
comment|/* 2 operand bitblt */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* function code */
name|char
name|transp
decl_stmt|;
comment|/* transparency */
name|int
name|fore_color
decl_stmt|;
comment|/* foreground color */
name|int
name|aux_color
decl_stmt|;
comment|/* auxiliary color */
name|int
name|planemask
decl_stmt|;
comment|/* select plane */
name|sBitmap
name|srcBitmap
decl_stmt|;
comment|/* source bitmap */
name|sRectangle
name|srcRect
decl_stmt|;
comment|/* source rectangle */
name|sBitmap
name|destBitmap
decl_stmt|;
comment|/* destination bitmap */
name|sRectangle
name|destClip
decl_stmt|;
comment|/* clip rectangle */
name|sPoint
name|destPoint
decl_stmt|;
comment|/* destination point */
block|}
name|sBitblt
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* function code */
name|char
name|transp
decl_stmt|;
comment|/* transparency */
name|int
name|fore_color
decl_stmt|;
comment|/* foreground color */
name|int
name|aux_color
decl_stmt|;
comment|/* auxiliary color */
name|int
name|planemask
decl_stmt|;
comment|/* select plane */
name|lBitmap
name|srcBitmap
decl_stmt|;
comment|/* source bitmap */
name|lRectangle
name|srcRect
decl_stmt|;
comment|/* source rectangle */
name|lBitmap
name|destBitmap
decl_stmt|;
comment|/* destination bitmap */
name|lRectangle
name|destClip
decl_stmt|;
comment|/* clip rectangle */
name|lPoint
name|destPoint
decl_stmt|;
comment|/* destination point */
block|}
name|lBitblt
typedef|;
end_typedef

begin_comment
comment|/* tile 2 operand bitblt */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* function code */
name|char
name|transp
decl_stmt|;
comment|/* transparency */
name|int
name|fore_color
decl_stmt|;
comment|/* foreground color */
name|int
name|aux_color
decl_stmt|;
comment|/* auxiliary color */
name|int
name|planemask
decl_stmt|;
comment|/* select plane */
name|sBitmap
name|ptnBitmap
decl_stmt|;
comment|/* pattern bitmap */
name|sRectangle
name|ptnRect
decl_stmt|;
comment|/* pattern rectangle */
name|sPoint
name|refPoint
decl_stmt|;
comment|/* reference point */
name|sBitmap
name|destBitmap
decl_stmt|;
comment|/* destination bitmap */
name|sRectangle
name|destClip
decl_stmt|;
comment|/* clip rectangle */
name|sRectangle
name|destRect
decl_stmt|;
comment|/* destination rectangle */
block|}
name|sTileBitblt
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* function code */
name|char
name|transp
decl_stmt|;
comment|/* transparency */
name|int
name|fore_color
decl_stmt|;
comment|/* foreground color */
name|int
name|aux_color
decl_stmt|;
comment|/* auxiliary color */
name|int
name|planemask
decl_stmt|;
comment|/* select plane */
name|lBitmap
name|ptnBitmap
decl_stmt|;
comment|/* pattern bitmap */
name|lRectangle
name|ptnRect
decl_stmt|;
comment|/* pattern rectangle */
name|lPoint
name|refPoint
decl_stmt|;
comment|/* reference point */
name|lBitmap
name|destBitmap
decl_stmt|;
comment|/* destination bitmap */
name|lRectangle
name|destClip
decl_stmt|;
comment|/* clip rectangle */
name|lRectangle
name|destRect
decl_stmt|;
comment|/* destination rectangle */
block|}
name|lTileBitblt
typedef|;
end_typedef

begin_comment
comment|/* 3 operand bitblt */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* function code */
name|char
name|transp
decl_stmt|;
comment|/* transparency */
name|int
name|fore_color
decl_stmt|;
comment|/* foreground color */
name|int
name|aux_color
decl_stmt|;
comment|/* auxiliary color */
name|int
name|planemask
decl_stmt|;
comment|/* select plane */
name|sBitmap
name|ptnBitmap
decl_stmt|;
comment|/* pattern bitmap */
name|sRectangle
name|ptnRect
decl_stmt|;
comment|/* pattern rectangle */
name|sPoint
name|refPoint
decl_stmt|;
comment|/* reference point */
name|sBitmap
name|srcBitmap
decl_stmt|;
comment|/* source bitmap */
name|sRectangle
name|srcRect
decl_stmt|;
comment|/* source rectangle */
name|sBitmap
name|destBitmap
decl_stmt|;
comment|/* destination bitmap */
name|sRectangle
name|destClip
decl_stmt|;
comment|/* clip rectangle */
name|sPoint
name|destPoint
decl_stmt|;
comment|/* destination point */
block|}
name|sBitblt3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* function code */
name|char
name|transp
decl_stmt|;
comment|/* transparency */
name|int
name|fore_color
decl_stmt|;
comment|/* foreground color */
name|int
name|aux_color
decl_stmt|;
comment|/* auxiliary color */
name|int
name|planemask
decl_stmt|;
comment|/* select plane */
name|lBitmap
name|ptnBitmap
decl_stmt|;
comment|/* pattern bitmap */
name|lRectangle
name|ptnRect
decl_stmt|;
comment|/* pattern rectangle */
name|lPoint
name|refPoint
decl_stmt|;
comment|/* reference point */
name|lBitmap
name|srcBitmap
decl_stmt|;
comment|/* source bitmap */
name|lRectangle
name|srcRect
decl_stmt|;
comment|/* source rectangle */
name|lBitmap
name|destBitmap
decl_stmt|;
comment|/* destination bitmap */
name|lRectangle
name|destClip
decl_stmt|;
comment|/* clip rectangle */
name|lPoint
name|destPoint
decl_stmt|;
comment|/* destination point */
block|}
name|lBitblt3
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|sRectangle
name|srcRect
decl_stmt|;
comment|/* source rectangle */
name|sPoint
name|destPoint
decl_stmt|;
comment|/* destination point */
block|}
name|sSrcDest
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|lRectangle
name|srcRect
decl_stmt|;
comment|/* source rectangle */
name|lPoint
name|destPoint
decl_stmt|;
comment|/* destination point */
block|}
name|lSrcDest
typedef|;
end_typedef

begin_comment
comment|/*  * batch bitblt  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* function code */
name|char
name|transp
decl_stmt|;
comment|/* transparency */
name|int
name|fore_color
decl_stmt|;
comment|/* foreground color */
name|int
name|aux_color
decl_stmt|;
comment|/* auxiliary color */
name|int
name|planemask
decl_stmt|;
comment|/* select plane */
name|sBitmap
name|srcBitmap
decl_stmt|;
comment|/* source bitmap */
name|sBitmap
name|destBitmap
decl_stmt|;
comment|/* destination bitmap */
name|sRectangle
name|destClip
decl_stmt|;
comment|/* clip rectangle */
name|int
name|nSrcDest
decl_stmt|;
comment|/* number of src-dest in list */
name|sSrcDest
modifier|*
name|srcDestList
decl_stmt|;
comment|/* pointer to src-dest spec */
block|}
name|sBatchBitblt
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* function code */
name|char
name|transp
decl_stmt|;
comment|/* transparency */
name|int
name|fore_color
decl_stmt|;
comment|/* foreground color */
name|int
name|aux_color
decl_stmt|;
comment|/* auxiliary color */
name|int
name|planemask
decl_stmt|;
comment|/* select plane */
name|lBitmap
name|srcBitmap
decl_stmt|;
comment|/* source bitmap */
name|lBitmap
name|destBitmap
decl_stmt|;
comment|/* destination bitmap */
name|lRectangle
name|destClip
decl_stmt|;
comment|/* clip rectangle */
name|int
name|nSrcDest
decl_stmt|;
comment|/* number of src-dest in list */
name|lSrcDest
modifier|*
name|srcDestList
decl_stmt|;
comment|/* pointer to src-dest spec */
block|}
name|lBatchBitblt
typedef|;
end_typedef

begin_define
define|#
directive|define
name|MAX_BATCHBITBLT
value|1024
end_define

begin_comment
comment|/* max number in src-dest list */
end_comment

begin_comment
comment|/*  * set screen mode  */
end_comment

begin_define
define|#
directive|define
name|BLACK_ON_WHITE
value|0
end_define

begin_comment
comment|/* white - 0, black - 1 (default) */
end_comment

begin_define
define|#
directive|define
name|WHITE_ON_BLACK
value|1
end_define

begin_comment
comment|/* white - 1, black - 0 */
end_comment

begin_comment
comment|/*  * graphic primitive drawing  */
end_comment

begin_comment
comment|/* scan line array */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|y
decl_stmt|;
name|short
name|x0
decl_stmt|,
name|x1
decl_stmt|;
comment|/* x0<= x1 */
block|}
name|sScanl
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|y
decl_stmt|;
name|int
name|x0
decl_stmt|,
name|x1
decl_stmt|;
comment|/* x0<= x1 */
block|}
name|lScanl
typedef|;
end_typedef

begin_comment
comment|/* line */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|lptn
decl_stmt|;
comment|/* line pattern */
name|short
name|np
decl_stmt|;
comment|/* number of points */
name|sPoint
modifier|*
name|plist
decl_stmt|;
comment|/* point list */
name|int
name|fore_color
decl_stmt|;
comment|/* foreground color */
name|int
name|aux_color
decl_stmt|;
comment|/* auxiliary color */
name|int
name|planemask
decl_stmt|;
comment|/* select plane */
name|char
name|transp
decl_stmt|;
comment|/* transparency */
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* rop function code */
name|char
name|dlpf
decl_stmt|;
comment|/* draw last point flag */
name|sRectangle
name|clip
decl_stmt|;
comment|/* clip rectangle */
name|sBitmap
name|drawBM
decl_stmt|;
comment|/* drawing bitmap */
block|}
name|sPrimLine
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|lptn
decl_stmt|;
comment|/* line pattern */
name|short
name|np
decl_stmt|;
comment|/* number of points */
name|lPoint
modifier|*
name|plist
decl_stmt|;
comment|/* point list */
name|int
name|fore_color
decl_stmt|;
comment|/* foreground color */
name|int
name|aux_color
decl_stmt|;
comment|/* auxiliary color */
name|int
name|planemask
decl_stmt|;
comment|/* select plane */
name|char
name|transp
decl_stmt|;
comment|/* transparency */
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* rop function code */
name|char
name|dlpf
decl_stmt|;
comment|/* draw last point flag */
name|lRectangle
name|clip
decl_stmt|;
comment|/* clip rectangle */
name|lBitmap
name|drawBM
decl_stmt|;
comment|/* drawing bitmap */
block|}
name|lPrimLine
typedef|;
end_typedef

begin_comment
comment|/* rectangle filling */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|sRectangle
name|rect
decl_stmt|;
comment|/* rectangle */
name|sPoint
name|refPoint
decl_stmt|;
comment|/* fill reference point */
name|sRectangle
name|ptnRect
decl_stmt|;
comment|/* pattern rectangle */
name|sBitmap
name|ptnBM
decl_stmt|;
comment|/* pattern bitmap */
name|int
name|fore_color
decl_stmt|;
comment|/* foreground color */
name|int
name|aux_color
decl_stmt|;
comment|/* auxiliary color */
name|int
name|planemask
decl_stmt|;
comment|/* select plane */
name|char
name|transp
decl_stmt|;
comment|/* transparency */
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* rop function code */
name|sRectangle
name|clip
decl_stmt|;
comment|/* clip rectangle */
name|sBitmap
name|drawBM
decl_stmt|;
comment|/* drawing bitmap */
block|}
name|sPrimRect
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|lRectangle
name|rect
decl_stmt|;
comment|/* rectangle */
name|lPoint
name|refPoint
decl_stmt|;
comment|/* fill reference point */
name|lRectangle
name|ptnRect
decl_stmt|;
comment|/* pattern rectangle */
name|lBitmap
name|ptnBM
decl_stmt|;
comment|/* pattern bitmap */
name|int
name|fore_color
decl_stmt|;
comment|/* foreground color */
name|int
name|aux_color
decl_stmt|;
comment|/* auxiliary color */
name|int
name|planemask
decl_stmt|;
comment|/* select plane */
name|char
name|transp
decl_stmt|;
comment|/* transparency */
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* rop function code */
name|lRectangle
name|clip
decl_stmt|;
comment|/* clip rectangle */
name|lBitmap
name|drawBM
decl_stmt|;
comment|/* drawing bitmap */
block|}
name|lPrimRect
typedef|;
end_typedef

begin_comment
comment|/* pattern filling */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|nscan
decl_stmt|;
comment|/* number of scan element */
name|sScanl
modifier|*
name|scan
decl_stmt|;
comment|/* scan line data */
name|sPoint
name|refPoint
decl_stmt|;
comment|/* fill reference point */
name|sRectangle
name|ptnRect
decl_stmt|;
comment|/* pattern rectangle */
name|sBitmap
name|ptnBM
decl_stmt|;
comment|/* pattern bitmap */
name|int
name|fore_color
decl_stmt|;
comment|/* foreground color */
name|int
name|aux_color
decl_stmt|;
comment|/* auxiliary color */
name|int
name|planemask
decl_stmt|;
comment|/* select plane */
name|char
name|transp
decl_stmt|;
comment|/* transparency */
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* rop function code */
name|sRectangle
name|clip
decl_stmt|;
comment|/* clip rectangle */
name|sBitmap
name|drawBM
decl_stmt|;
comment|/* drawing bitmap */
block|}
name|sPrimFill
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|nscan
decl_stmt|;
comment|/* number of scan element */
name|lScanl
modifier|*
name|scan
decl_stmt|;
comment|/* scan line data */
name|lPoint
name|refPoint
decl_stmt|;
comment|/* fill reference point */
name|lRectangle
name|ptnRect
decl_stmt|;
comment|/* pattern rectangle */
name|lBitmap
name|ptnBM
decl_stmt|;
comment|/* pattern bitmap */
name|int
name|fore_color
decl_stmt|;
comment|/* foreground color */
name|int
name|aux_color
decl_stmt|;
comment|/* auxiliary color */
name|int
name|planemask
decl_stmt|;
comment|/* select plane */
name|char
name|transp
decl_stmt|;
comment|/* transparency */
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* rop function code */
name|lRectangle
name|clip
decl_stmt|;
comment|/* clip rectangle */
name|lBitmap
name|drawBM
decl_stmt|;
comment|/* drawing bitmap */
block|}
name|lPrimFill
typedef|;
end_typedef

begin_comment
comment|/* marker */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|np
decl_stmt|;
comment|/* number of points */
name|sPoint
modifier|*
name|plist
decl_stmt|;
comment|/* point list */
name|sRectangle
name|ptnRect
decl_stmt|;
comment|/* pattern rectangle */
name|sBitmap
name|ptnBM
decl_stmt|;
comment|/* pattern bitmap */
name|int
name|fore_color
decl_stmt|;
comment|/* foreground color */
name|int
name|aux_color
decl_stmt|;
comment|/* auxiliary color */
name|int
name|planemask
decl_stmt|;
comment|/* select plane */
name|char
name|transp
decl_stmt|;
comment|/* transparency */
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* rop function code */
name|sRectangle
name|clip
decl_stmt|;
comment|/* clip rectangle */
name|sBitmap
name|drawBM
decl_stmt|;
comment|/* drawing bitmap */
block|}
name|sPrimMarker
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|np
decl_stmt|;
comment|/* number of points */
name|lPoint
modifier|*
name|plist
decl_stmt|;
comment|/* point list */
name|lRectangle
name|ptnRect
decl_stmt|;
comment|/* pattern rectangle */
name|lBitmap
name|ptnBM
decl_stmt|;
comment|/* pattern bitmap */
name|int
name|fore_color
decl_stmt|;
comment|/* foreground color */
name|int
name|aux_color
decl_stmt|;
comment|/* auxiliary color */
name|int
name|planemask
decl_stmt|;
comment|/* select plane */
name|char
name|transp
decl_stmt|;
comment|/* transparency */
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* rop function code */
name|lRectangle
name|clip
decl_stmt|;
comment|/* clip rectangle */
name|lBitmap
name|drawBM
decl_stmt|;
comment|/* drawing bitmap */
block|}
name|lPrimMarker
typedef|;
end_typedef

begin_comment
comment|/* text */
end_comment

begin_define
define|#
directive|define
name|MAX_STRING
value|1024
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|char
name|type
decl_stmt|;
comment|/* ROM-font, etc */
name|short
name|len
decl_stmt|;
comment|/* string length (byte) */
name|unsigned
name|char
modifier|*
name|str
decl_stmt|;
comment|/* string */
name|sPoint
name|p
decl_stmt|;
name|int
name|dx
decl_stmt|,
name|dy
decl_stmt|;
comment|/* vector (16bit left shifted) */
name|char
name|ex_factor
decl_stmt|;
comment|/* expansion factor */
name|sPoint
name|fp
decl_stmt|;
comment|/* bitmap font upper-left */
name|short
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* font width, font height */
name|short
name|column
decl_stmt|;
comment|/* number of characters in a row */
name|unsigned
name|short
name|first_chr
decl_stmt|;
comment|/* first character code */
name|unsigned
name|short
name|last_chr
decl_stmt|;
comment|/* last character code */
name|sBitmap
name|fontBM
decl_stmt|;
comment|/* font bitmap */
name|int
name|fore_color
decl_stmt|;
comment|/* foreground color */
name|int
name|aux_color
decl_stmt|;
comment|/* auxiliary color */
name|int
name|planemask
decl_stmt|;
comment|/* select plane */
name|char
name|transp
decl_stmt|;
comment|/* transparency */
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* rop function code */
name|sRectangle
name|clip
decl_stmt|;
comment|/* clip rectangle */
name|sBitmap
name|drawBM
decl_stmt|;
comment|/* drawing bitmap */
block|}
name|sPrimText
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|dx
decl_stmt|,
name|dy
decl_stmt|;
comment|/* vector (16bit left shifted) */
name|lPoint
name|fp
decl_stmt|;
comment|/* bitmap font upper-left */
name|short
name|width
decl_stmt|,
name|height
decl_stmt|;
comment|/* font width, font height */
name|short
name|column
decl_stmt|;
comment|/* number of characters in a row */
name|unsigned
name|short
name|first_chr
decl_stmt|;
comment|/* first character code */
name|unsigned
name|short
name|last_chr
decl_stmt|;
comment|/* last character code */
name|lBitmap
name|fontBM
decl_stmt|;
comment|/* font bitmap */
name|int
name|fore_color
decl_stmt|;
comment|/* foreground color */
name|int
name|aux_color
decl_stmt|;
comment|/* auxiliary color */
name|int
name|planemask
decl_stmt|;
comment|/* select plane */
name|lBitmap
name|drawBM
decl_stmt|;
comment|/* drawing bitmap */
name|lRectangle
name|clip
decl_stmt|;
comment|/* clip rectangle */
name|lPoint
name|p
decl_stmt|;
comment|/* output position */
name|unsigned
name|char
modifier|*
name|str
decl_stmt|;
comment|/* string */
name|short
name|len
decl_stmt|;
comment|/* string length (byte) */
name|char
name|type
decl_stmt|;
comment|/* ROM-font, etc */
name|char
name|transp
decl_stmt|;
comment|/* transparency */
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* rop function code */
name|char
name|ex_factor
decl_stmt|;
comment|/* expansion factor */
block|}
name|lPrimText
typedef|;
end_typedef

begin_comment
comment|/* dot */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|np
decl_stmt|;
comment|/* number of points */
name|sPoint
modifier|*
name|plist
decl_stmt|;
comment|/* point list */
name|int
name|fore_color
decl_stmt|;
comment|/* foreground color */
name|int
name|aux_color
decl_stmt|;
comment|/* auxiliary color */
name|int
name|planemask
decl_stmt|;
comment|/* select plane */
name|char
name|transp
decl_stmt|;
comment|/* transparency */
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* rop function code */
name|sRectangle
name|clip
decl_stmt|;
comment|/* clip rectangle */
name|sBitmap
name|drawBM
decl_stmt|;
comment|/* drawing bitmap */
block|}
name|sPrimDot
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|np
decl_stmt|;
comment|/* number of points */
name|lPoint
modifier|*
name|plist
decl_stmt|;
comment|/* point list */
name|int
name|fore_color
decl_stmt|;
comment|/* foreground color */
name|int
name|aux_color
decl_stmt|;
comment|/* auxiliary color */
name|int
name|planemask
decl_stmt|;
comment|/* select plane */
name|char
name|transp
decl_stmt|;
comment|/* transparency */
name|unsigned
name|char
name|func
decl_stmt|;
comment|/* rop function code */
name|lRectangle
name|clip
decl_stmt|;
comment|/* clip rectangle */
name|lBitmap
name|drawBM
decl_stmt|;
comment|/* drawing bitmap */
block|}
name|lPrimDot
typedef|;
end_typedef

begin_comment
comment|/*  *	screen type  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|colorwidth
decl_stmt|;
comment|/* palette color width */
name|short
name|plane
decl_stmt|;
comment|/* number of planes */
name|sRectangle
name|bufferrect
decl_stmt|;
comment|/* framebuffer region */
name|sRectangle
name|visiblerect
decl_stmt|;
comment|/* visible screen region */
block|}
name|sScrType
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|colorwidth
decl_stmt|;
comment|/* palette color width */
name|short
name|plane
decl_stmt|;
comment|/* number of planes */
name|char
name|type
decl_stmt|;
comment|/* device type */
name|char
name|unit
decl_stmt|;
comment|/* unit no */
name|lRectangle
name|bufferrect
decl_stmt|;
comment|/* framebuffer region */
name|lRectangle
name|visiblerect
decl_stmt|;
comment|/* visible screen region */
block|}
name|lScrType
typedef|;
end_typedef

begin_comment
comment|/* device type */
end_comment

begin_define
define|#
directive|define
name|FB_NWB512
value|1
end_define

begin_comment
comment|/* fb is B/W bitmap display (816x1024) */
end_comment

begin_define
define|#
directive|define
name|FB_NWB225
value|2
end_define

begin_comment
comment|/* fb is color bitmap display (1280x1024) */
end_comment

begin_define
define|#
directive|define
name|FB_POPM
value|3
end_define

begin_comment
comment|/* fb is B/W bitmap display (816x1024) */
end_comment

begin_define
define|#
directive|define
name|FB_POPC
value|4
end_define

begin_comment
comment|/* fb is color bitmap display (1024x768) */
end_comment

begin_define
define|#
directive|define
name|FB_NWB514
value|5
end_define

begin_comment
comment|/* fb is GrayScale bitmap display (1280x1280) */
end_comment

begin_define
define|#
directive|define
name|FB_NWB251
value|6
end_define

begin_comment
comment|/* fb is New color bitmap display (1280x1024) */
end_comment

begin_define
define|#
directive|define
name|FB_LCDM
value|7
end_define

begin_comment
comment|/* fb is lcd bitmap (1120x780) */
end_comment

begin_define
define|#
directive|define
name|FB_LCDC
value|8
end_define

begin_comment
comment|/* fb is LCD color bitmap display (?) */
end_comment

begin_define
define|#
directive|define
name|FB_NWB518
value|9
end_define

begin_comment
comment|/* fb is B/W bitmap display (1024x768) */
end_comment

begin_define
define|#
directive|define
name|FB_NWB252
value|10
end_define

begin_comment
comment|/* fb is color bitmap display (1024x768) */
end_comment

begin_define
define|#
directive|define
name|FB_NWB253
value|11
end_define

begin_comment
comment|/* fb is B/W bitmap display (816x1024) */
end_comment

begin_define
define|#
directive|define
name|FB_NWB254
value|12
end_define

begin_comment
comment|/* fb is color bitmap display (1024x768) */
end_comment

begin_define
define|#
directive|define
name|FB_NWB255
value|13
end_define

begin_comment
comment|/* fb is B/W bitmap display (1280x1280) */
end_comment

begin_define
define|#
directive|define
name|FB_SLB101
value|14
end_define

begin_comment
comment|/* fb is color bitmap display (1920x1035) */
end_comment

begin_define
define|#
directive|define
name|FB_NWB256
value|15
end_define

begin_comment
comment|/* fb is 3D-Rendaring Board (1280x1024) */
end_comment

begin_define
define|#
directive|define
name|FB_NWB257
value|16
end_define

begin_comment
comment|/* fb is color bitmap display (1280x1024) */
end_comment

begin_define
define|#
directive|define
name|FB_NWB240
value|200
end_define

begin_comment
comment|/* fb is A3 LPB/IR interface (3136x4516) */
end_comment

begin_define
define|#
directive|define
name|FB_NWB241
value|201
end_define

begin_comment
comment|/* fb is A4 LBP/IR interface (3904x5600) */
end_comment

begin_define
define|#
directive|define
name|FB_NWB242
value|202
end_define

begin_comment
comment|/* fb is A3 Image Processor (3136x4516) */
end_comment

begin_define
define|#
directive|define
name|FB_FB2015
value|254
end_define

begin_comment
comment|/* fb is full color big display (2048x1536) */
end_comment

begin_define
define|#
directive|define
name|FB_FB2020
value|255
end_define

begin_comment
comment|/* fb is full color big display (2048x2048) */
end_comment

begin_define
define|#
directive|define
name|FB_MONO0
value|1
end_define

begin_comment
comment|/* fb is B/W (compat-3.0) */
end_comment

begin_define
define|#
directive|define
name|FB_COLOR0
value|2
end_define

begin_comment
comment|/* fb is color (compat-3.0) */
end_comment

begin_comment
comment|/*  *	color  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|short
name|index
decl_stmt|;
comment|/* palette number */
struct|struct
block|{
name|short
name|r
decl_stmt|,
name|g
decl_stmt|,
name|b
decl_stmt|;
block|}
name|rgb
struct|;
block|}
name|sPalette
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|count
decl_stmt|;
name|sPalette
modifier|*
name|palette
decl_stmt|;
block|}
name|lPalette
typedef|;
end_typedef

begin_comment
comment|/*  *	cursor  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|func
decl_stmt|;
name|char
name|cursor_color
decl_stmt|;
name|char
name|mask_color
decl_stmt|;
name|sPoint
name|hot
decl_stmt|;
name|sPoint
name|size
decl_stmt|;
name|sRectangle
name|cursorRect
decl_stmt|;
comment|/* Cursor Pattern rea */
name|sRectangle
name|maskRect
decl_stmt|;
comment|/* Mask Pattern Area */
name|sRectangle
name|saveRect
decl_stmt|;
comment|/* Save Pattern Area */
name|sRectangle
name|moveArea
decl_stmt|;
block|}
name|sCursor
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|func
decl_stmt|;
name|char
name|cursor_color
decl_stmt|;
name|char
name|mask_color
decl_stmt|;
name|lPoint
name|hot
decl_stmt|;
name|lPoint
name|size
decl_stmt|;
name|lRectangle
name|cursorRect
decl_stmt|;
comment|/* Cursor Pattern Area */
name|lRectangle
name|maskRect
decl_stmt|;
comment|/* Mask Pattern Area */
name|lRectangle
name|saveRect
decl_stmt|;
comment|/* Save Pattern Area */
name|lRectangle
name|moveArea
decl_stmt|;
block|}
name|lCursor
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|char
name|func
decl_stmt|;
name|int
name|cursor_color
decl_stmt|;
name|int
name|mask_color
decl_stmt|;
name|lPoint
name|hot
decl_stmt|;
name|lPoint
name|size
decl_stmt|;
name|lRectangle
name|cursorRect
decl_stmt|;
comment|/* Cursor Pattern Area */
name|lRectangle
name|maskRect
decl_stmt|;
comment|/* Mask Pattern Area */
name|lRectangle
name|saveRect
decl_stmt|;
comment|/* Save Pattern Area */
name|lRectangle
name|moveArea
decl_stmt|;
block|}
name|lCursor2
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|request
decl_stmt|;
name|lPoint
name|sp
decl_stmt|;
name|lPoint
name|dp
decl_stmt|;
name|lPoint
name|size
decl_stmt|;
name|int
name|refresh_rate
decl_stmt|;
name|int
name|func
decl_stmt|;
name|int
name|planemask
decl_stmt|;
block|}
name|lVideoCtl
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|request
decl_stmt|;
name|int
name|mode
decl_stmt|;
name|int
name|status
decl_stmt|;
name|lRectangle
name|vframe
decl_stmt|;
name|int
name|refresh_rate
decl_stmt|;
name|int
name|func
decl_stmt|;
name|int
name|planemask
decl_stmt|;
block|}
name|lVideoStatus
typedef|;
end_typedef

begin_comment
comment|/* Video Control Request */
end_comment

begin_define
define|#
directive|define
name|VIDEO_RESET
value|0x01
end_define

begin_define
define|#
directive|define
name|VIDEO_RUN
value|0x02
end_define

begin_define
define|#
directive|define
name|VIDEO_STOP
value|0x04
end_define

begin_define
define|#
directive|define
name|VIDEO_CONT
value|0x08
end_define

begin_define
define|#
directive|define
name|VIDEO_FRAME
value|0x10
end_define

begin_define
define|#
directive|define
name|VIDEO_ROP
value|0x20
end_define

begin_comment
comment|/* Video Status */
end_comment

begin_define
define|#
directive|define
name|VIDEO_STATUS
value|0x01
end_define

begin_define
define|#
directive|define
name|VIDEO_SIG_NTSC
value|0x01
end_define

begin_define
define|#
directive|define
name|VIDEO_SIG_PAL
value|0x02
end_define

begin_define
define|#
directive|define
name|VIDEO_STATUS_RUN
value|1
end_define

begin_define
define|#
directive|define
name|VIDEO_STATUS_STOP
value|2
end_define

begin_define
define|#
directive|define
name|VIDEO_STATUS_ERROR
value|4
end_define

begin_define
define|#
directive|define
name|VIDEO_ERROR_SIZE
value|0x100
end_define

begin_define
define|#
directive|define
name|VIDEO_ERROR_POINT
value|0x200
end_define

begin_define
define|#
directive|define
name|VIDEO_ERROR_PARAM
value|0x400
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|request
decl_stmt|;
name|int
name|param
index|[
literal|8
index|]
decl_stmt|;
block|}
name|lFbIoctl
typedef|;
end_typedef

begin_comment
comment|/* func */
end_comment

begin_define
define|#
directive|define
name|BF_0
value|0x0
end_define

begin_comment
comment|/* 0 */
end_comment

begin_define
define|#
directive|define
name|BF_SDA
value|0x1
end_define

begin_comment
comment|/* Src& Dest */
end_comment

begin_define
define|#
directive|define
name|BF_SDIA
value|0x2
end_define

begin_comment
comment|/* Src& ~Dest */
end_comment

begin_define
define|#
directive|define
name|BF_S
value|0x3
end_define

begin_comment
comment|/* Src */
end_comment

begin_define
define|#
directive|define
name|BF_SIDA
value|0x4
end_define

begin_comment
comment|/* ~Src& Dest */
end_comment

begin_define
define|#
directive|define
name|BF_D
value|0x5
end_define

begin_comment
comment|/* Dest */
end_comment

begin_define
define|#
directive|define
name|BF_SDX
value|0x6
end_define

begin_comment
comment|/* Src ^ Dest */
end_comment

begin_define
define|#
directive|define
name|BF_SDO
value|0x7
end_define

begin_comment
comment|/* Src | Dest */
end_comment

begin_define
define|#
directive|define
name|BF_SDOI
value|0x8
end_define

begin_comment
comment|/* ~(Src | Dest) */
end_comment

begin_define
define|#
directive|define
name|BF_SDXI
value|0x9
end_define

begin_comment
comment|/* ~(Src ^ Dest) */
end_comment

begin_define
define|#
directive|define
name|BF_DI
value|0xa
end_define

begin_comment
comment|/* ~Dest */
end_comment

begin_define
define|#
directive|define
name|BF_SDIO
value|0xb
end_define

begin_comment
comment|/* Src | ~Dest */
end_comment

begin_define
define|#
directive|define
name|BF_SI
value|0xc
end_define

begin_comment
comment|/* ~Src */
end_comment

begin_define
define|#
directive|define
name|BF_SIDO
value|0xd
end_define

begin_comment
comment|/* ~Src | Dest */
end_comment

begin_define
define|#
directive|define
name|BF_SDAI
value|0xe
end_define

begin_comment
comment|/* ~(Src& Dest) */
end_comment

begin_define
define|#
directive|define
name|BF_1
value|0xf
end_define

begin_comment
comment|/* 1 */
end_comment

begin_define
define|#
directive|define
name|BF_NOP
parameter_list|(
name|f
parameter_list|)
value|((f) == BF_D)
end_define

begin_define
define|#
directive|define
name|BF_INV
parameter_list|(
name|f
parameter_list|)
value|((f) == BF_DI)
end_define

begin_define
define|#
directive|define
name|BF_CON
parameter_list|(
name|f
parameter_list|)
value|((f) == BF_0 || (f) == BF_1)
end_define

begin_define
define|#
directive|define
name|BF_SRC
parameter_list|(
name|f
parameter_list|)
value|(!BF_NOP(f)&&!BF_INV(f)&&!BF_CON(f))
end_define

begin_comment
comment|/* Bitmap Font Type */
end_comment

begin_define
define|#
directive|define
name|ROM_ASCII
value|0
end_define

begin_define
define|#
directive|define
name|ROM_KANJI
value|1
end_define

begin_define
define|#
directive|define
name|ASCII
value|2
end_define

begin_define
define|#
directive|define
name|ROM_CONS
value|3
end_define

begin_comment
comment|/* Plane Mask */
end_comment

begin_define
define|#
directive|define
name|FB_PLANEALL
value|0xffffff
end_define

begin_define
define|#
directive|define
name|FB_PLANE0
value|0x000001
end_define

begin_define
define|#
directive|define
name|FB_PLANE1
value|0x000002
end_define

begin_define
define|#
directive|define
name|FB_PLANE2
value|0x000004
end_define

begin_define
define|#
directive|define
name|FB_PLANE3
value|0x000008
end_define

begin_define
define|#
directive|define
name|FB_PLANE4
value|0x000010
end_define

begin_define
define|#
directive|define
name|FB_PLANE5
value|0x000020
end_define

begin_define
define|#
directive|define
name|FB_PLANE6
value|0x000040
end_define

begin_define
define|#
directive|define
name|FB_PLANE7
value|0x000080
end_define

begin_define
define|#
directive|define
name|FB_PLANE8
value|0x000100
end_define

begin_define
define|#
directive|define
name|FB_PLANE9
value|0x000200
end_define

begin_define
define|#
directive|define
name|FB_PLANE10
value|0x000400
end_define

begin_define
define|#
directive|define
name|FB_PLANE11
value|0x000800
end_define

begin_define
define|#
directive|define
name|FB_PLANE12
value|0x001000
end_define

begin_define
define|#
directive|define
name|FB_PLANE13
value|0x002000
end_define

begin_define
define|#
directive|define
name|FB_PLANE14
value|0x004000
end_define

begin_define
define|#
directive|define
name|FB_PLANE15
value|0x008000
end_define

begin_define
define|#
directive|define
name|FB_PLANE16
value|0x010000
end_define

begin_define
define|#
directive|define
name|FB_PLANE17
value|0x020000
end_define

begin_define
define|#
directive|define
name|FB_PLANE18
value|0x040000
end_define

begin_define
define|#
directive|define
name|FB_PLANE19
value|0x080000
end_define

begin_define
define|#
directive|define
name|FB_PLANE20
value|0x100000
end_define

begin_define
define|#
directive|define
name|FB_PLANE21
value|0x200000
end_define

begin_define
define|#
directive|define
name|FB_PLANE22
value|0x400000
end_define

begin_define
define|#
directive|define
name|FB_PLANE23
value|0x800000
end_define

begin_comment
comment|/* Line Pattern */
end_comment

begin_define
define|#
directive|define
name|LINE_SLD
value|(unsigned)0xffffffff
end_define

begin_comment
comment|/* solid */
end_comment

begin_define
define|#
directive|define
name|LINE_DSH
value|(unsigned)0xfcfcfcfc
end_define

begin_comment
comment|/* dash */
end_comment

begin_define
define|#
directive|define
name|LINE_DOT
value|(unsigned)0xcccccccc
end_define

begin_comment
comment|/* dot */
end_comment

begin_define
define|#
directive|define
name|LINE_DSHDOT
value|(unsigned)0xfff18fff
end_define

begin_comment
comment|/* dash dot */
end_comment

begin_define
define|#
directive|define
name|LINE_DSHDOTDOT
value|(unsigned)0xff8c63ff
end_define

begin_comment
comment|/* dash dot dot */
end_comment

begin_comment
comment|/*  * FB IOCTL  */
end_comment

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_define
define|#
directive|define
name|FBIOCSETSCR
value|_IOW('F', 0, int)
end_define

begin_define
define|#
directive|define
name|FBIOCGETSCR
value|_IOR('F', 1, int)
end_define

begin_define
define|#
directive|define
name|FBIOCSETDIM
value|_IOW('F', 2, int)
end_define

begin_define
define|#
directive|define
name|FBIOCGETDIM
value|_IOR('F', 3, int)
end_define

begin_define
define|#
directive|define
name|FBIOCSETSCRMODE
value|_IOW('F', 4, int)
end_define

begin_define
define|#
directive|define
name|FBIOCGETSCRMODE
value|_IOR('F', 5, int)
end_define

begin_define
define|#
directive|define
name|FBIOCAUTODIM
value|_IOW('F', 6, int)
end_define

begin_define
define|#
directive|define
name|FBIOCBITBLT
value|_IOW('F', 10, sBitblt)
end_define

begin_define
define|#
directive|define
name|FBIOCBATCHBITBLT
value|_IOW('F', 11, sBatchBitblt)
end_define

begin_define
define|#
directive|define
name|FBIOCTILEBITBLT
value|_IOW('F', 12, sTileBitblt)
end_define

begin_define
define|#
directive|define
name|FBIOCBITBLT3
value|_IOW('F', 13, sBitblt3)
end_define

begin_define
define|#
directive|define
name|FBIOCPOLYLINE
value|_IOW('F', 20, sPrimLine)
end_define

begin_define
define|#
directive|define
name|FBIOCDJPOLYLINE
value|_IOW('F', 21, sPrimLine)
end_define

begin_define
define|#
directive|define
name|FBIOCPOLYMARKER
value|_IOW('F', 22, sPrimMarker)
end_define

begin_define
define|#
directive|define
name|FBIOCRECTANGLE
value|_IOW('F', 23, sPrimRect)
end_define

begin_define
define|#
directive|define
name|FBIOCFILLSCAN
value|_IOW('F', 24, sPrimFill)
end_define

begin_define
define|#
directive|define
name|FBIOCTEXT
value|_IOW('F', 25, sPrimText)
end_define

begin_define
define|#
directive|define
name|FBIOCPOLYDOT
value|_IOW('F', 26, sPrimDot)
end_define

begin_define
define|#
directive|define
name|FBIOCGETSCRTYPE
value|_IOR('F', 30, sScrType)
end_define

begin_comment
comment|/* for color display */
end_comment

begin_define
define|#
directive|define
name|FBIOCSETPALETTE
value|_IOW('F', 31, sPalette)
end_define

begin_define
define|#
directive|define
name|FBIOCGETPALETTE
value|_IOWR('F', 32, sPalette)
end_define

begin_define
define|#
directive|define
name|FBIOCSETDADDR
value|_IOW('F', 33, int)
end_define

begin_define
define|#
directive|define
name|FBIOCENABLE
value|_IO('F', 40)
end_define

begin_define
define|#
directive|define
name|FBIOCDISABLE
value|_IO('F', 41)
end_define

begin_define
define|#
directive|define
name|FBIOCSETCURSOR
value|_IOW('F', 42, sCursor)
end_define

begin_define
define|#
directive|define
name|FBIOCUNSETCURSOR
value|_IO('F', 43)
end_define

begin_define
define|#
directive|define
name|FBIOCSHOWCURSOR
value|_IO('F', 44)
end_define

begin_define
define|#
directive|define
name|FBIOCHIDECURSOR
value|_IO('F', 45)
end_define

begin_define
define|#
directive|define
name|FBIOCSETXY
value|_IOW('F', 46, sPoint)
end_define

begin_define
define|#
directive|define
name|FBIOCNBITBLT
value|_IOW('F', 50, lBitblt)
end_define

begin_define
define|#
directive|define
name|FBIOCNBATCHBITBLT
value|_IOW('F', 51, lBatchBitblt)
end_define

begin_define
define|#
directive|define
name|FBIOCNTILEBITBLT
value|_IOW('F', 52, lTileBitblt)
end_define

begin_define
define|#
directive|define
name|FBIOCNBITBLT3
value|_IOW('F', 53, lBitblt3)
end_define

begin_define
define|#
directive|define
name|FBIOCNPOLYLINE
value|_IOW('F', 60, lPrimLine)
end_define

begin_define
define|#
directive|define
name|FBIOCNDJPOLYLINE
value|_IOW('F', 61, lPrimLine)
end_define

begin_define
define|#
directive|define
name|FBIOCNPOLYMARKER
value|_IOW('F', 62, lPrimMarker)
end_define

begin_define
define|#
directive|define
name|FBIOCNRECTANGLE
value|_IOW('F', 63, lPrimRect)
end_define

begin_define
define|#
directive|define
name|FBIOCNFILLSCAN
value|_IOW('F', 64, lPrimFill)
end_define

begin_define
define|#
directive|define
name|FBIOCNTEXT
value|_IOW('F', 65, lPrimText)
end_define

begin_define
define|#
directive|define
name|FBIOCNPOLYDOT
value|_IOW('F', 66, lPrimDot)
end_define

begin_define
define|#
directive|define
name|FBIOCNGETSCRTYPE
value|_IOR('F', 70, lScrType)
end_define

begin_define
define|#
directive|define
name|FBIOCNSETPALETTE
value|_IOW('F', 71, lPalette)
end_define

begin_define
define|#
directive|define
name|FBIOCNGETPALETTE
value|_IOWR('F', 72, lPalette)
end_define

begin_define
define|#
directive|define
name|FBIOCNSETPALETTEMODE
value|_IOW('F', 73, int)
end_define

begin_define
define|#
directive|define
name|FBIOCNGETPALETTEMODE
value|_IOR('F', 74, int)
end_define

begin_define
define|#
directive|define
name|FBIOCNSETCURSOR
value|_IOW('F', 80, lCursor)
end_define

begin_define
define|#
directive|define
name|FBIOCNUNSETCURSOR
value|_IO('F', 81)
end_define

begin_define
define|#
directive|define
name|FBIOCNSHOWCURSOR
value|_IO('F', 82)
end_define

begin_define
define|#
directive|define
name|FBIOCNHIDECURSOR
value|_IO('F', 83)
end_define

begin_define
define|#
directive|define
name|FBIOCNSETXY
value|_IOW('F', 84, lPoint)
end_define

begin_define
define|#
directive|define
name|FBIOCNSETCURSOR2
value|_IOW('F', 85, lCursor2)
end_define

begin_define
define|#
directive|define
name|FBIOCNSETVIDEO
value|_IOW('F', 90, lVideoCtl)
end_define

begin_define
define|#
directive|define
name|FBIOCNGETVIDEO
value|_IOR('F', 91, lVideoStatus)
end_define

begin_define
define|#
directive|define
name|FBIOCNIOCTL
value|_IOWR('F', 100, lFbIoctl)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__FRAMEBUF__ */
end_comment

end_unit

