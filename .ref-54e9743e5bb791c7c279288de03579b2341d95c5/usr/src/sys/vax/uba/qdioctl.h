begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1982, 1986  *	The Regents of the University of California.  All rights reserved.  * (c) UNIX System Laboratories, Inc.  * All or some portions of this file are derived from material licensed  * to the University of California by American Telephone and Telegraph  * Co. or Unix System Laboratories, Inc. and are reproduced herein with  * the permission of UNIX System Laboratories, Inc.  *  * %sccs.include.redist.c%  *  *	@(#)qdioctl.h	7.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *	derived from: qdioctl.h	1.1	(ULTRIX)	8/22/85  */
end_comment

begin_comment
comment|/*  * QDSS IOCTL definitions  */
end_comment

begin_comment
comment|/************************************************************************  *									*  *			Copyright (c) 1985 by				*  *		Digital Equipment Corporation, Maynard, MA		*  *			All rights reserved.				*  *									*  *   This software is furnished under a license and may be used and	*  *   copied  only  in accordance with the terms of such license and	*  *   with the  inclusion  of  the  above  copyright  notice.   This	*  *   software  or  any  other copies thereof may not be provided or	*  *   otherwise made available to any other person.  No title to and	*  *   ownership of the software is hereby transferred.			*  *									*  *   This software is  derived  from  software  received  from  the	*  *   University    of   California,   Berkeley,   and   from   Bell	*  *   Laboratories.  Use, duplication, or disclosure is  subject  to	*  *   restrictions  under  license  agreements  with  University  of	*  *   California and with AT&T.						*  *									*  *   The information in this software is subject to change  without	*  *   notice  and should not be construed as a commitment by Digital	*  *   Equipment Corporation.						*  *									*  *   Digital assumes no responsibility for the use  or  reliability	*  *   of its software on equipment which is not supplied by Digital.	*  *									*  ************************************************************************/
end_comment

begin_comment
comment|/*************************************************************************** *	revision history: (belongs in sccs) **************************************************************************** * * 22 oct 85  longo  fixed QD_PRGTABRES cmd number to be 22 instead of 12 * 14 oct 85  longo  added QD_KERN_LOOP and QD_KERN_UNLOOP * 02 oct 85  longo  added QD_MAPCOLOR and QD_UNMAPCOLOR * 17 sep 85  longo  made QD_MAPIOBUF a read/write command type * ***************************************************************************/
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|KERNEL
end_ifdef

begin_include
include|#
directive|include
file|"sys/ioctl.h"
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

begin_define
define|#
directive|define
name|QD_GETEVENT
value|_IOR('g', 1, struct _vs_event)
end_define

begin_comment
comment|/* get oldest event */
end_comment

begin_define
define|#
directive|define
name|QD_WTCURSOR
value|_IOW('g', 2, short[32])
end_define

begin_comment
comment|/* write cursor bitmap */
end_comment

begin_define
define|#
directive|define
name|QD_RDCURSOR
value|_IOR('g', 3, 64)
end_define

begin_comment
comment|/* read cursor bitmap */
end_comment

begin_define
define|#
directive|define
name|QD_CLRSCRN
value|_IO('g', 4)
end_define

begin_comment
comment|/* clear the screen */
end_comment

begin_define
define|#
directive|define
name|QD_RDCONFIG
value|_IOR('g', 5, short)
end_define

begin_comment
comment|/* read QDSS configuration */
end_comment

begin_define
define|#
directive|define
name|QD_PRGMOUSE
value|_IOW('g', 6, char)
end_define

begin_comment
comment|/* program mouse */
end_comment

begin_define
define|#
directive|define
name|QD_PRGTABLET
value|_IOW('g', 7, char)
end_define

begin_comment
comment|/* program tablet */
end_comment

begin_define
define|#
directive|define
name|QD_PRGKBD
value|_IOW('g', 8, struct prgkbd)
end_define

begin_comment
comment|/* program LK201 kbd */
end_comment

begin_define
define|#
directive|define
name|QD_MAPDEVICE
value|_IOR('g', 9, struct qdmap)
end_define

begin_comment
comment|/* map device to user */
end_comment

begin_define
define|#
directive|define
name|QD_MAPIOBUF
value|_IOWR('g', 10, caddr_t)
end_define

begin_comment
comment|/* map DMA iobuf to user */
end_comment

begin_define
define|#
directive|define
name|QD_MAPEVENT
value|_IOR('g', 11, caddr_t)
end_define

begin_comment
comment|/* map event queue to user */
end_comment

begin_define
define|#
directive|define
name|QD_PRGCURSOR
value|_IOW('g', 12, struct prg_cursor)
end_define

begin_comment
comment|/* program cursor */
end_comment

begin_define
define|#
directive|define
name|QD_RESET
value|_IO('g', 13)
end_define

begin_comment
comment|/* set device& driver defaults */
end_comment

begin_define
define|#
directive|define
name|QD_POSCURSOR
value|_IOW('g', 14, struct _vs_cursor)
end_define

begin_comment
comment|/* position cursor */
end_comment

begin_define
define|#
directive|define
name|QD_SET
value|_IO('g', 15)
end_define

begin_comment
comment|/* set DUART& driver defaults */
end_comment

begin_define
define|#
directive|define
name|QD_MAPSCROLL
value|_IOR('g', 16, caddr_t)
end_define

begin_comment
comment|/* map scroll param area */
end_comment

begin_define
define|#
directive|define
name|QD_UNMAPSCROLL
value|_IO('g', 17)
end_define

begin_comment
comment|/* unmap scroll param area */
end_comment

begin_define
define|#
directive|define
name|QD_MAPCOLOR
value|_IOR('g', 18, caddr_t)
end_define

begin_comment
comment|/* map color map write buf */
end_comment

begin_define
define|#
directive|define
name|QD_UNMAPCOLOR
value|_IO('g', 19)
end_define

begin_comment
comment|/* unmap color map write buf */
end_comment

begin_define
define|#
directive|define
name|QD_KERN_LOOP
value|_IO('g', 20)
end_define

begin_comment
comment|/* detour kernel console output */
end_comment

begin_define
define|#
directive|define
name|QD_KERN_UNLOOP
value|_IO('g', 21)
end_define

begin_comment
comment|/* un-detour kernel console output */
end_comment

begin_define
define|#
directive|define
name|QD_PRGTABRES
value|_IOW('g', 22, short)
end_define

begin_comment
comment|/* program tablet resolution */
end_comment

end_unit

