begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1985, 1986, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)tablet.h	8.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_TABLET_H_
end_ifndef

begin_define
define|#
directive|define
name|_TABLET_H_
end_define

begin_comment
comment|/*  * Tablet line discipline.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"../h/ioctl.h"
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Reads on the tablet return one of the following structures, depending on  * the underlying tablet type.  The first two are defined such that a read of  * sizeof (gtcopos) on a non-gtco tablet will return meaningful info.  The  * in-proximity bit is simulated where the tablet does not directly provide  * the information.  */
end_comment

begin_struct
struct|struct
name|tbpos
block|{
name|int
name|xpos
decl_stmt|,
name|ypos
decl_stmt|;
comment|/* raw x-y coordinates */
name|short
name|status
decl_stmt|;
comment|/* buttons/pen down */
define|#
directive|define
name|TBINPROX
value|0100000
comment|/* pen in proximity of tablet */
name|short
name|scount
decl_stmt|;
comment|/* sample count */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|gtcopos
block|{
name|int
name|xpos
decl_stmt|,
name|ypos
decl_stmt|;
comment|/* raw x-y coordinates */
name|short
name|status
decl_stmt|;
comment|/* as above */
name|short
name|scount
decl_stmt|;
comment|/* sample count */
name|short
name|xtilt
decl_stmt|,
name|ytilt
decl_stmt|;
comment|/* raw tilt */
name|short
name|pressure
decl_stmt|;
name|short
name|pad
decl_stmt|;
comment|/* pad to longword boundary */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|polpos
block|{
name|short
name|p_x
decl_stmt|,
name|p_y
decl_stmt|,
name|p_z
decl_stmt|;
comment|/* raw 3-space coordinates */
name|short
name|p_azi
decl_stmt|,
name|p_pit
decl_stmt|,
name|p_rol
decl_stmt|;
comment|/* azimuth, pitch, and roll */
name|short
name|p_stat
decl_stmt|;
comment|/* status, as above */
name|char
name|p_key
decl_stmt|;
comment|/* calculator input keyboard */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|BIOSMODE
value|_IOW('b', 1, int)
end_define

begin_comment
comment|/* set mode bit(s) */
end_comment

begin_define
define|#
directive|define
name|BIOGMODE
value|_IOR('b', 2, int)
end_define

begin_comment
comment|/* get mode bit(s) */
end_comment

begin_define
define|#
directive|define
name|TBMODE
value|0xfff0
end_define

begin_comment
comment|/* mode bits: */
end_comment

begin_define
define|#
directive|define
name|TBPOINT
value|0x0010
end_define

begin_comment
comment|/* single point */
end_comment

begin_define
define|#
directive|define
name|TBRUN
value|0x0000
end_define

begin_comment
comment|/* runs contin. */
end_comment

begin_define
define|#
directive|define
name|TBSTOP
value|0x0020
end_define

begin_comment
comment|/* shut-up */
end_comment

begin_define
define|#
directive|define
name|TBGO
value|0x0000
end_define

begin_comment
comment|/* ~TBSTOP */
end_comment

begin_define
define|#
directive|define
name|TBTYPE
value|0x000f
end_define

begin_comment
comment|/* tablet type: */
end_comment

begin_define
define|#
directive|define
name|TBUNUSED
value|0x0
end_define

begin_define
define|#
directive|define
name|TBHITACHI
value|0x1
end_define

begin_comment
comment|/* hitachi tablet */
end_comment

begin_define
define|#
directive|define
name|TBTIGER
value|0x2
end_define

begin_comment
comment|/* hitachi tiger */
end_comment

begin_define
define|#
directive|define
name|TBGTCO
value|0x3
end_define

begin_comment
comment|/* gtco */
end_comment

begin_define
define|#
directive|define
name|TBPOL
value|0x4
end_define

begin_comment
comment|/* polhemus 3space */
end_comment

begin_define
define|#
directive|define
name|TBHDG
value|0x5
end_define

begin_comment
comment|/* hdg-1111b, low res */
end_comment

begin_define
define|#
directive|define
name|TBHDGHIRES
value|0x6
end_define

begin_comment
comment|/* hdg-1111b, high res */
end_comment

begin_define
define|#
directive|define
name|TBDIGI
value|0x7
end_define

begin_comment
comment|/* gtco digi-pad, low res */
end_comment

begin_define
define|#
directive|define
name|TBDIGIHIRES
value|0x8
end_define

begin_comment
comment|/* gtco digi-pad, high res */
end_comment

begin_define
define|#
directive|define
name|BIOSTYPE
value|_IOW('b', 3, int)
end_define

begin_comment
comment|/* set tablet type */
end_comment

begin_define
define|#
directive|define
name|BIOGTYPE
value|_IOR('b', 4, int)
end_define

begin_comment
comment|/* get tablet type*/
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_TABLET_H_ */
end_comment

end_unit

