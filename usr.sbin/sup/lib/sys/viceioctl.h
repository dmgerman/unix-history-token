begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1991 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *  * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *  * Carnegie Mellon requests users of this software to return to  *  *  Software Distribution Coordinator   or   Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *  * any improvements or extensions that they make and grant Carnegie the rights  * to redistribute these changes.  */
end_comment

begin_comment
comment|/*   * Mach Operating System  * Copyright (c) 1989 Carnegie-Mellon University  * Copyright (c) 1988 Carnegie-Mellon University  * Copyright (c) 1987 Carnegie-Mellon University  * All rights reserved.  The CMU software License Agreement specifies  * the terms and conditions for use and redistribution.  */
end_comment

begin_comment
comment|/*  * Revision 2.4  90/08/30  11:51:12  bohman  */
end_comment

begin_comment
comment|/*  * ITC Remote file system - vice ioctl interface module  */
end_comment

begin_comment
comment|/*  *  TODO:  Find /usr/local/include/viceioctl.h.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SYS_VICEIOCTL_H_
end_ifndef

begin_define
define|#
directive|define
name|_SYS_VICEIOCTL_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/ioctl.h>
end_include

begin_struct
struct|struct
name|ViceIoctl
block|{
name|caddr_t
name|in
decl_stmt|,
name|out
decl_stmt|;
comment|/* Data to be transferred in, or out */
name|short
name|in_size
decl_stmt|;
comment|/* Size of input buffer<= 2K */
name|short
name|out_size
decl_stmt|;
comment|/* Maximum size of output buffer,<= 2K */
block|}
struct|;
end_struct

begin_comment
comment|/* The 2K limits above are a consequence of the size of the kernel buffer    used to buffer requests from the user to venus--2*MAXPATHLEN.    The buffer pointers may be null, or the counts may be 0 if there    are no input or output parameters  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_define
define|#
directive|define
name|_VICEIOCTL
parameter_list|(
name|id
parameter_list|)
value|((unsigned int ) _IOW('V', id, struct ViceIoctl))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|_VICEIOCTL
parameter_list|(
name|id
parameter_list|)
value|((unsigned int ) _IOW(V, id, struct ViceIoctl))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Use this macro to define up to 256 vice ioctl's.  These ioctl's    all potentially have in/out parameters--this depends upon the    values in the ViceIoctl structure.  This structure is itself passed    into the kernel by the normal ioctl parameter passing mechanism.  */
end_comment

begin_define
define|#
directive|define
name|_VALIDVICEIOCTL
parameter_list|(
name|com
parameter_list|)
value|(com>= _VICEIOCTL(0)&& com<= _VICEIOCTL(255))
end_define

begin_endif
endif|#
directive|endif
endif|_SYS_VICEIOCTL_H_
end_endif

end_unit

