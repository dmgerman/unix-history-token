begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 The Regents of the University of California.  * All rights reserved.  *  * %sccs.include.redist.c%  *  *	@(#)dbm.h	5.4 (Berkeley) %G%  */
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

begin_comment
comment|/*  * Pre-define the page block size to be the old dbm size.  */
end_comment

begin_define
define|#
directive|define
name|PBLKSIZ
value|1024
end_define

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

end_unit

