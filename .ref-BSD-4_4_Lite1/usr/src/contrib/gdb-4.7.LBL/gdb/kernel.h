begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1992 Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the above copyright notice and this paragraph are  * duplicated in all such forms and that any documentation,  * advertising materials, and other materials related to such  * distribution and use acknowledge that the software was developed  * by the University of California, Lawrence Berkeley Laboratory,  * Berkeley, CA.  The name of the University may not be used to  * endorse or promote products derived from this software without  * specific prior written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header$ (LBL)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|GDB_KERNEL_H
end_ifndef

begin_define
define|#
directive|define
name|GDB_KERNEL_H
end_define

begin_decl_stmt
specifier|extern
name|int
name|kernel_debugging
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|is_a_vmunix
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|CORE_ADDR
name|ksym_lookup
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|kerninfo
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

