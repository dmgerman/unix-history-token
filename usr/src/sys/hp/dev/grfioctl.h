begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988 University of Utah.  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * the Systems Programming Group of the University of Utah Computer  * Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: Utah $Hdr: grfioctl.h 1.17 93/08/13$  *  *	@(#)grfioctl.h	8.2 (Berkeley) 9/9/93  */
end_comment

begin_struct
struct|struct
name|grfinfo
block|{
name|int
name|gd_id
decl_stmt|;
comment|/* HPUX identifier */
name|caddr_t
name|gd_regaddr
decl_stmt|;
comment|/* control registers physaddr */
name|int
name|gd_regsize
decl_stmt|;
comment|/* control registers size */
name|caddr_t
name|gd_fbaddr
decl_stmt|;
comment|/* frame buffer physaddr */
name|int
name|gd_fbsize
decl_stmt|;
comment|/* frame buffer size */
name|short
name|gd_colors
decl_stmt|;
comment|/* number of colors */
name|short
name|gd_planes
decl_stmt|;
comment|/* number of planes */
comment|/* new stuff */
name|int
name|gd_fbwidth
decl_stmt|;
comment|/* frame buffer width */
name|int
name|gd_fbheight
decl_stmt|;
comment|/* frame buffer height */
name|int
name|gd_dwidth
decl_stmt|;
comment|/* displayed part width */
name|int
name|gd_dheight
decl_stmt|;
comment|/* displayed part height */
name|int
name|gd_pad
index|[
literal|6
index|]
decl_stmt|;
comment|/* for future expansion */
block|}
struct|;
end_struct

begin_comment
comment|/* types */
end_comment

begin_define
define|#
directive|define
name|GRFGATOR
value|8
end_define

begin_define
define|#
directive|define
name|GRFBOBCAT
value|9
end_define

begin_define
define|#
directive|define
name|GRFCATSEYE
value|9
end_define

begin_define
define|#
directive|define
name|GRFRBOX
value|10
end_define

begin_define
define|#
directive|define
name|GRFFIREEYE
value|11
end_define

begin_define
define|#
directive|define
name|GRFHYPERION
value|12
end_define

begin_define
define|#
directive|define
name|GRFDAVINCI
value|14
end_define

begin_comment
comment|/*  * HPUX ioctls (here for the benefit of the driver)  */
end_comment

begin_struct
struct|struct
name|grf_slot
block|{
name|int
name|slot
decl_stmt|;
name|u_char
modifier|*
name|addr
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|grf_fbinfo
block|{
name|int
name|id
decl_stmt|;
name|int
name|mapsize
decl_stmt|;
name|int
name|dwidth
decl_stmt|,
name|dlength
decl_stmt|;
name|int
name|width
decl_stmt|,
name|length
decl_stmt|;
name|int
name|xlen
decl_stmt|;
name|int
name|bpp
decl_stmt|,
name|bppu
decl_stmt|;
name|int
name|npl
decl_stmt|,
name|nplbytes
decl_stmt|;
name|char
name|name
index|[
literal|32
index|]
decl_stmt|;
name|int
name|attr
decl_stmt|;
name|caddr_t
name|fbbase
decl_stmt|,
name|regbase
decl_stmt|;
name|caddr_t
name|regions
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifndef
ifndef|#
directive|ifndef
name|_IOH
end_ifndef

begin_define
define|#
directive|define
name|_IOH
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(IOC_IN|((x)<<8)|y)
end_define

begin_comment
comment|/* IOC_IN is IOC_VOID */
end_comment

begin_define
define|#
directive|define
name|GCID
value|_IOR('G', 0, int)
end_define

begin_define
define|#
directive|define
name|GCON
value|_IOH('G', 1)
end_define

begin_define
define|#
directive|define
name|GCOFF
value|_IOH('G', 2)
end_define

begin_define
define|#
directive|define
name|GCAON
value|_IOH('G', 3)
end_define

begin_define
define|#
directive|define
name|GCAOFF
value|_IOH('G', 4)
end_define

begin_define
define|#
directive|define
name|GCMAP
value|_IOWR('G', 5, int)
end_define

begin_define
define|#
directive|define
name|GCUNMAP
value|_IOWR('G', 6, int)
end_define

begin_define
define|#
directive|define
name|GCLOCK
value|_IOH('G', 7)
end_define

begin_define
define|#
directive|define
name|GCUNLOCK
value|_IOH('G', 8)
end_define

begin_define
define|#
directive|define
name|GCLOCK_MINIMUM
value|_IOH('G', 9)
end_define

begin_define
define|#
directive|define
name|GCUNLOCK_MINIMUM
value|_IOH('G', 10)
end_define

begin_define
define|#
directive|define
name|GCSTATIC_CMAP
value|_IOH('G', 11)
end_define

begin_define
define|#
directive|define
name|GCVARIABLE_CMAP
value|_IOH('G', 12)
end_define

begin_define
define|#
directive|define
name|GCSLOT
value|_IOWR('G', 13, struct grf_slot)
end_define

begin_define
define|#
directive|define
name|GCDESCRIBE
value|_IOR('G', 21, struct grf_fbinfo)
end_define

begin_comment
comment|/* XXX: for now */
end_comment

begin_define
define|#
directive|define
name|IOMAPID
value|_IOR('M',0,int)
end_define

begin_comment
comment|/* ??? */
end_comment

begin_define
define|#
directive|define
name|IOMAPMAP
value|_IOWR('M',1,int)
end_define

begin_define
define|#
directive|define
name|IOMAPUNMAP
value|_IOWR('M',2,int)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * BSD ioctls  */
end_comment

begin_define
define|#
directive|define
name|GRFIOCGINFO
value|_IOR('G', 0, struct grfinfo)
end_define

begin_comment
comment|/* get info on device */
end_comment

begin_define
define|#
directive|define
name|GRFIOCON
value|_IO('G', 1)
end_define

begin_comment
comment|/* turn graphics on */
end_comment

begin_define
define|#
directive|define
name|GRFIOCOFF
value|_IO('G', 2)
end_define

begin_comment
comment|/* turn graphics off */
end_comment

begin_define
define|#
directive|define
name|GRFIOCMAP
value|_IOWR('G', 5, int)
end_define

begin_comment
comment|/* map in regs+framebuffer */
end_comment

begin_define
define|#
directive|define
name|GRFIOCUNMAP
value|_IOW('G', 6, int)
end_define

begin_comment
comment|/* unmap regs+framebuffer */
end_comment

end_unit

