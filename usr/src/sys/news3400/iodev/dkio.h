begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by the University of  *	California, Berkeley and its contributors.  * 4. Neither the name of the University nor the names of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * from: $Hdr: dkio.h,v 4.300 91/06/09 06:38:02 root Rel41 $ SONY  *  *	@(#)dkio.h	8.1 (Berkeley) 6/11/93  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__DKIO__
end_ifndef

begin_define
define|#
directive|define
name|__DKIO__
value|1
end_define

begin_define
define|#
directive|define
name|DKIOCGGEOM
value|_IOR('d', 0, struct dkst)
end_define

begin_comment
comment|/* get geometry info */
end_comment

begin_define
define|#
directive|define
name|DKIOCSGEOM
value|_IOW('d', 1, struct dkst)
end_define

begin_comment
comment|/* set geometry info */
end_comment

begin_define
define|#
directive|define
name|DKIOCGPART
value|_IOR('d', 2, struct Partinfo)
end_define

begin_comment
comment|/* get partition info */
end_comment

begin_define
define|#
directive|define
name|DKIOCSPART
value|_IOW('d', 3, struct Partinfo)
end_define

begin_comment
comment|/* set partition info */
end_comment

begin_define
define|#
directive|define
name|DKIOCGCHAN
value|_IOR('d', 4, int)
end_define

begin_comment
comment|/* get drive channel# */
end_comment

begin_define
define|#
directive|define
name|DKIOCGUNIT
value|_IOR('d', 5, int)
end_define

begin_comment
comment|/* get drive unit# */
end_comment

begin_define
define|#
directive|define
name|DKIOCSEEK
value|_IOW('d', 6, int)
end_define

begin_comment
comment|/* seek logical block */
end_comment

begin_define
define|#
directive|define
name|DKIOCRGEOM
value|_IOW('d', 7, int)
end_define

begin_comment
comment|/* reset geom info */
end_comment

begin_define
define|#
directive|define
name|RGEOM_SDINFO
value|0
end_define

begin_comment
comment|/* reset geom info */
end_comment

begin_define
define|#
directive|define
name|RGEOM_WDINFO
value|1
end_define

begin_comment
comment|/* reset geom info& write to disk */
end_comment

begin_define
define|#
directive|define
name|DKIOCRSEC0
value|_IOW('d', 8, char *)
end_define

begin_comment
comment|/* read sector #0 */
end_comment

begin_define
define|#
directive|define
name|DKIOCWSEC0
value|_IOW('d', 9, char *)
end_define

begin_comment
comment|/* write sector #0 */
end_comment

begin_define
define|#
directive|define
name|DKIOCRBOOT0
value|DKIOCRSEC0
end_define

begin_comment
comment|/* read sector #0 */
end_comment

begin_define
define|#
directive|define
name|DKIOCWBOOT0
value|DKIOCWSEC0
end_define

begin_comment
comment|/* write sector #0 */
end_comment

begin_define
define|#
directive|define
name|DKIOCRBOOT1
value|_IOW('d',10, char *)
end_define

begin_comment
comment|/* read sector #1~#15 */
end_comment

begin_define
define|#
directive|define
name|DKIOCWBOOT1
value|_IOW('d',11, char *)
end_define

begin_comment
comment|/* write sector #1~#15 */
end_comment

begin_define
define|#
directive|define
name|DKIOCRBOOT
value|_IOW('d',12, char *)
end_define

begin_comment
comment|/* read sector #0~#15 */
end_comment

begin_define
define|#
directive|define
name|DKIOCWBOOT
value|_IOW('d',13, char *)
end_define

begin_comment
comment|/* write sector #0~#15 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__DKIO__ */
end_comment

end_unit

