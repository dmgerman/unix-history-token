begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software developed by the Computer Systems  * Engineering group at Lawrence Berkeley Laboratory under DARPA  * contract BG 91-66 and contributed to Berkeley.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: $Header: fbio.h,v 1.3 91/12/13 22:16:32 torek Exp $ (LBL)  *  * from: sys/fbio.h		7.2 (Berkeley) 4/1/92  *  *	@(#)fbio.h	8.1 (Berkeley) 6/10/93  */
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

