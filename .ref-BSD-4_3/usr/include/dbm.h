begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1980 Regents of the University of California.  * All rights reserved.  The Berkeley software License Agreement  * specifies the terms and conditions for redistribution.  *  *	@(#)dbm.h	5.1 (Berkeley) 3/27/86  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|NULL
end_ifndef

begin_comment
comment|/*  * this is lunacy, we no longer use it (and never should have  * unconditionally defined it), but, this whole file is for  * backwards compatability - someone may rely on this.  */
end_comment

begin_define
define|#
directive|define
name|NULL
value|((char *) 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<ndbm.h>
end_include

begin_function_decl
name|datum
name|fetch
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|datum
name|firstkey
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|datum
name|nextkey
parameter_list|()
function_decl|;
end_function_decl

begin_if
if|#
directive|if
literal|0
end_if

begin_endif
unit|datum	makdatum(); datum	firsthash(); long	calchash(); long	hashinc();
endif|#
directive|endif
end_endif

end_unit

