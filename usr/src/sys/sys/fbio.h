begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992, 1993  *	The Regents of the University of California.  All rights reserved.  *  * This code is derived from software developed by the Computer Systems  * Engineering group at Lawrence Berkeley Laboratory under DARPA  * contract BG 91-66 and contributed to Berkeley.  *  * %sccs.include.redist.c%  *  *	@(#)fbio.h	8.1 (Berkeley) %G%  *  * from: $Header: fbio.h,v 1.3 91/12/13 22:16:32 torek Exp $ (LBL)  */
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
name|FBTYPE_SUN1BW
value|0
end_define

begin_comment
comment|/* multibus mono */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUN1COLOR
value|1
end_define

begin_comment
comment|/* multibus color */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUN2BW
value|2
end_define

begin_comment
comment|/* memory mono */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUN2COLOR
value|3
end_define

begin_comment
comment|/* color w/rasterop chips */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUN2GP
value|4
end_define

begin_comment
comment|/* GP1/GP2 */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUN5COLOR
value|5
end_define

begin_comment
comment|/* RoadRunner accelerator */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUN3COLOR
value|6
end_define

begin_comment
comment|/* memory color */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_MEMCOLOR
value|7
end_define

begin_comment
comment|/* memory 24-bit */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUN4COLOR
value|8
end_define

begin_comment
comment|/* memory color w/overlay */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_NOTSUN1
value|9
end_define

begin_comment
comment|/* reserved for customer */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_NOTSUN2
value|10
end_define

begin_comment
comment|/* reserved for customer */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_NOTSUN3
value|11
end_define

begin_comment
comment|/* reserved for customer */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUNFAST_COLOR
value|12
end_define

begin_comment
comment|/* accelerated 8bit */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUNROP_COLOR
value|13
end_define

begin_comment
comment|/* MEMCOLOR with rop h/w */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_SUNFB_VIDEO
value|14
end_define

begin_comment
comment|/* Simple video mixing */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_RESERVED5
value|15
end_define

begin_comment
comment|/* reserved, do not use */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_RESERVED4
value|16
end_define

begin_comment
comment|/* reserved, do not use */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_RESERVED3
value|17
end_define

begin_comment
comment|/* reserved, do not use */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_RESERVED2
value|18
end_define

begin_comment
comment|/* reserved, do not use */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_RESERVED1
value|19
end_define

begin_comment
comment|/* reserved, do not use */
end_comment

begin_define
define|#
directive|define
name|FBTYPE_LASTPLUSONE
value|20
end_define

begin_comment
comment|/* max number of fbs (change as add) */
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

begin_ifdef
ifdef|#
directive|ifdef
name|notdef
end_ifdef

begin_comment
comment|/*  * General purpose structure for passing info in and out of frame buffers  * (used for gp1) -- unsupported.  */
end_comment

begin_struct
struct|struct
name|fbinfo
block|{
name|int
name|fb_physaddr
decl_stmt|;
comment|/* physical frame buffer address */
name|int
name|fb_hwwidth
decl_stmt|;
comment|/* fb board width */
name|int
name|fb_hwheight
decl_stmt|;
comment|/* fb board height */
name|int
name|fb_addrdelta
decl_stmt|;
comment|/* phys addr diff between boards */
name|u_char
modifier|*
name|fb_ropaddr
decl_stmt|;
comment|/* fb virtual addr */
name|int
name|fb_unit
decl_stmt|;
comment|/* minor devnum of fb */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FBIOGINFO
value|_IOR('F', 2, struct fbinfo)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Color map I/O.  */
end_comment

begin_struct
struct|struct
name|fbcmap
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
name|FBIOPUTCMAP
value|_IOW('F', 3, struct fbcmap)
end_define

begin_define
define|#
directive|define
name|FBIOGETCMAP
value|_IOW('F', 4, struct fbcmap)
end_define

begin_comment
comment|/*  * Set/get attributes.  */
end_comment

begin_define
define|#
directive|define
name|FB_ATTR_NDEVSPECIFIC
value|8
end_define

begin_comment
comment|/* no. of device specific values */
end_comment

begin_define
define|#
directive|define
name|FB_ATTR_NEMUTYPES
value|4
end_define

begin_comment
comment|/* no. of emulation types */
end_comment

begin_struct
struct|struct
name|fbsattr
block|{
name|int
name|flags
decl_stmt|;
comment|/* flags; see below */
name|int
name|emu_type
decl_stmt|;
comment|/* emulation type (-1 if unused) */
name|int
name|dev_specific
index|[
name|FB_ATTR_NDEVSPECIFIC
index|]
decl_stmt|;
comment|/* catchall */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|FB_ATTR_AUTOINIT
value|1
end_define

begin_comment
comment|/* emulation auto init flag */
end_comment

begin_define
define|#
directive|define
name|FB_ATTR_DEVSPECIFIC
value|2
end_define

begin_comment
comment|/* dev. specific stuff valid flag */
end_comment

begin_struct
struct|struct
name|fbgattr
block|{
name|int
name|real_type
decl_stmt|;
comment|/* real device type */
name|int
name|owner
decl_stmt|;
comment|/* PID of owner, 0 if myself */
name|struct
name|fbtype
name|fbtype
decl_stmt|;
comment|/* fbtype info for real device */
name|struct
name|fbsattr
name|sattr
decl_stmt|;
comment|/* see above */
name|int
name|emu_types
index|[
name|FB_ATTR_NEMUTYPES
index|]
decl_stmt|;
comment|/* possible emulations */
comment|/* (-1 if unused) */
block|}
struct|;
end_struct

begin_comment
comment|/*	FBIOSATTR	_IOW('F', 5, struct fbsattr) -- unsupported */
end_comment

begin_define
define|#
directive|define
name|FBIOGATTR
value|_IOR('F', 6, struct fbgattr)
end_define

begin_comment
comment|/*  * Video control.  */
end_comment

begin_define
define|#
directive|define
name|FBVIDEO_OFF
value|0
end_define

begin_define
define|#
directive|define
name|FBVIDEO_ON
value|1
end_define

begin_define
define|#
directive|define
name|FBIOSVIDEO
value|_IOW('F', 7, int)
end_define

begin_define
define|#
directive|define
name|FBIOGVIDEO
value|_IOR('F', 8, int)
end_define

end_unit

