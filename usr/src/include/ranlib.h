begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 1990, 1993  *	The Regents of the University of California.  All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)ranlib.h	8.1 (Berkeley) %G%  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_RANLIB_H_
end_ifndef

begin_define
define|#
directive|define
name|_RANLIB_H_
end_define

begin_define
define|#
directive|define
name|RANLIBMAG
value|"__.SYMDEF"
end_define

begin_comment
comment|/* archive file name */
end_comment

begin_define
define|#
directive|define
name|RANLIBSKEW
value|3
end_define

begin_comment
comment|/* creation time offset */
end_comment

begin_struct
struct|struct
name|ranlib
block|{
union|union
block|{
name|long
name|ran_strx
decl_stmt|;
comment|/* string table index */
name|char
modifier|*
name|ran_name
decl_stmt|;
comment|/* in memory symbol name */
block|}
name|ran_un
union|;
name|long
name|ran_off
decl_stmt|;
comment|/* archive file offset */
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_RANLIB_H_ */
end_comment

end_unit

