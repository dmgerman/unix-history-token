begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1986, Avadis Tevanian, Jr., Michael Wayne Young  * Copyright (c) 1987 Carnegie-Mellon University  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * The CMU software License Agreement specifies the terms and conditions  * for use and redistribution.  *  *	@(#)vm_user.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *	Kernel memory management definitions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VM_USER_
end_ifndef

begin_define
define|#
directive|define
name|_VM_USER_
end_define

begin_function_decl
name|int
name|vm_allocate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_deallocate
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_inherit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_protect
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|vm_statistics
parameter_list|()
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
endif|_VM_USER_
end_endif

end_unit

