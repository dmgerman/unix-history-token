begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1989 Jan-Simon Pendry  * Copyright (c) 1989 Imperial College of Science, Technology& Medicine  * Copyright (c) 1989 The Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * Jan-Simon Pendry at Imperial College, London.  *  * %sccs.include.redist.c%  *  *	@(#)os-utek.h	5.3 (Berkeley) %G%  *  * $Id: os-utek.h,v 5.2.1.1 91/05/07 22:20:06 jsp Alpha $  *  * Utek 4.0  definitions for Amd (automounter)  *	from Bill Trost<trost%reed@cse.ogi.edu>  */
end_comment

begin_define
define|#
directive|define
name|UTEK
end_define

begin_define
define|#
directive|define
name|__NFS_HEADER__
end_define

begin_comment
comment|/* prevent re-inclusion of<sys/nfs.h> */
end_comment

begin_comment
comment|/* ... and fake the rest */
end_comment

begin_include
include|#
directive|include
file|"os-sos3.h"
end_include

end_unit

