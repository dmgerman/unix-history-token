begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1982, 1986, 1989, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)dir.h	8.2 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  * The information in this file should be obtained from<dirent.h>  * and is provided solely (and temporarily) for backward compatibility.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_DIR_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_DIR_H_
end_define

begin_include
include|#
directive|include
file|<dirent.h>
end_include

begin_comment
comment|/*  * Backwards compatibility.  */
end_comment

begin_define
define|#
directive|define
name|direct
value|dirent
end_define

begin_comment
comment|/*  * The DIRSIZ macro gives the minimum record length which will hold  * the directory entry.  This requires the amount of space in struct direct  * without the d_name field, plus enough space for the name with a terminating  * null byte (dp->d_namlen+1), rounded up to a 4 byte boundary.  */
end_comment

begin_undef
undef|#
directive|undef
name|DIRSIZ
end_undef

begin_define
define|#
directive|define
name|DIRSIZ
parameter_list|(
name|dp
parameter_list|)
define|\
value|((sizeof (struct direct) - (MAXNAMLEN+1)) + (((dp)->d_namlen+1 + 3)&~ 3))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_SYS_DIR_H_ */
end_comment

end_unit

