begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Sony Corp. and Kazumasa Utashiro of Software Research Associates, Inc.  *  * %sccs.include.redist.c%  *  * from: $Hdr: dkio.h,v 4.300 91/06/09 06:38:02 root Rel41 $ SONY  *  *	@(#)dkio.h	7.1 (Berkeley) %G%  */
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

