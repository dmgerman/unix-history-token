begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software developed by the Computer Systems  * Engineering group at Lawrence Berkeley Laboratory under DARPA  * contract BG 91-66 and contributed to Berkeley.  *  * %sccs.include.redist.c%  *  * from: $Header: fbio.h,v 1.3 91/12/13 22:16:32 torek Exp $ (LBL)  *  * from: sys/fbio.h		7.2 (Berkeley) 4/1/92  *  *	@(#)fbio.h	7.3 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * Frame buffer ioctls (from Sprite, trimmed to essentials for X11).  */
end_comment

begin_comment
comment|/*  * Frame buffer type codes.  */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_BM
value|100
end_define

begin_comment
comment|/* LUNA 4bit(1bit) frame buffer */
end_comment

begin_comment
comment|/*  * Frame buffer descriptor as returned by FBIOGTYPE.  */
end_comment

begin_struct
struct|struct
name|fbtype
block|{
name|int
name|fb_type
decl_stmt|;
comment|/* as defined above */
name|int
name|fb_height
decl_stmt|;
comment|/* in pixels */
name|int
name|fb_width
decl_stmt|;
comment|/* in pixels */
name|int
name|fb_depth
decl_stmt|;
comment|/* bits per pixel */
name|int
name|fb_cmsize
decl_stmt|;
comment|/* size of color map (entries) */
name|int
name|fb_size
decl_stmt|;
comment|/* total size in bytes */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FBIOGTYPE
value|_IOR('F', 0, struct fbtype)
end_define

begin_comment
comment|/*  * Reflesh Countor I/O  */
end_comment

begin_struct
struct|struct
name|fb_rfc
block|{
name|short
name|rfc_hcnt
decl_stmt|;
name|short
name|rfc_vcnt
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FBIOSETRFCT
value|_IOW('F', 3, struct fb_rfc)
end_define

begin_define
define|#
directive|define
name|FBIOGETRFCT
value|_IOR('F', 4, struct fb_rfc)
end_define

begin_comment
comment|/*  * Color map I/O.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|notyet
end_ifdef

begin_struct
struct|struct
name|fb_palette
block|{
name|int
name|index
decl_stmt|;
comment|/* first element (0 origin) */
name|int
name|count
decl_stmt|;
comment|/* number of elements */
name|u_char
modifier|*
name|red
decl_stmt|;
comment|/* red color map elements */
name|u_char
modifier|*
name|green
decl_stmt|;
comment|/* green color map elements */
name|u_char
modifier|*
name|blue
decl_stmt|;
comment|/* blue color map elements */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FBIOSETPALT
value|_IOW('F', 5, struct fb_palette)
end_define

begin_define
define|#
directive|define
name|FBIOGETPALT
value|_IOR('F', 6, struct fb_palette)
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

