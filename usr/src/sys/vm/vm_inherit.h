begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*   * Copyright (c) 1985, Avadis Tevanian, Jr., Michael Wayne Young  * Copyright (c) 1987 Carnegie-Mellon University  * Copyright (c) 1991 Regents of the University of California.  * All rights reserved.  *  * This code is derived from software contributed to Berkeley by  * The Mach Operating System project at Carnegie-Mellon University.  *  * The CMU software License Agreement specifies the terms and conditions  * for use and redistribution.  *  *	@(#)vm_inherit.h	7.1 (Berkeley) %G%  */
end_comment

begin_comment
comment|/*  *	Virtual memory map inheritance definitions.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_VM_INHERIT_
end_ifndef

begin_define
define|#
directive|define
name|_VM_INHERIT_
end_define

begin_comment
comment|/*  *	Types defined:  *  *	vm_inherit_t	inheritance codes.  */
end_comment

begin_typedef
typedef|typedef
name|int
name|vm_inherit_t
typedef|;
end_typedef

begin_comment
comment|/* might want to change this */
end_comment

begin_comment
comment|/*  *	Enumeration of valid values for vm_inherit_t.  */
end_comment

begin_define
define|#
directive|define
name|VM_INHERIT_SHARE
value|((vm_inherit_t) 0)
end_define

begin_comment
comment|/* share with child */
end_comment

begin_define
define|#
directive|define
name|VM_INHERIT_COPY
value|((vm_inherit_t) 1)
end_define

begin_comment
comment|/* copy into child */
end_comment

begin_define
define|#
directive|define
name|VM_INHERIT_NONE
value|((vm_inherit_t) 2)
end_define

begin_comment
comment|/* absent from child */
end_comment

begin_define
define|#
directive|define
name|VM_INHERIT_DONATE_COPY
value|((vm_inherit_t) 3)
end_define

begin_comment
comment|/* copy and delete */
end_comment

begin_define
define|#
directive|define
name|VM_INHERIT_DEFAULT
value|VM_INHERIT_COPY
end_define

begin_endif
endif|#
directive|endif
endif|_VM_INHERIT_
end_endif

end_unit

