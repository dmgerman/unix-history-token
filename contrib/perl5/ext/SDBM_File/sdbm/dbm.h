begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1983 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this notice are  * duplicated in all such forms.  *  * [additional clause stricken -- see below]  *  * The name of the University may not be used to endorse or promote   * products derived from this software without specific prior written   * permission.  THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY   * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE   * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR   * PURPOSE.  *   * This notice previously contained the additional clause:  *  *   and that any documentation, advertising materials, and other   *   materials related to such distribution and use acknowledge that   *   the software was developed by the University of California,   *   Berkeley.  *  * Pursuant to the licensing change made by the Office of Technology  * Licensing of the University of California, Berkeley on July 22,   * 1999 and documented in:  *  *   ftp://ftp.cs.berkeley.edu/pub/4bsd/README.Impt.License.Change  *  * this clause has been stricken and no longer is applicable to this  * software.  *  *    @(#)dbm.h    5.2 (Berkeley) 5/24/89  */
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

begin_ifdef
ifdef|#
directive|ifdef
name|I_NDBM
end_ifdef

begin_include
include|#
directive|include
file|<ndbm.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

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

