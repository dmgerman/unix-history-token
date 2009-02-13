begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2000, 2001 Ben Harris  * Copyright (c) 1996 Scott K. Stevens  *  * Mach Operating System  * Copyright (c) 1991,1990 Carnegie Mellon University  * All Rights Reserved.  *   * Permission to use, copy, modify and distribute this software and its  * documentation is hereby granted, provided that both the copyright  * notice and this permission notice appear in all copies of the  * software, derivative works or modified versions, and any portions  * thereof, and that both notices appear in supporting documentation.  *   * CARNEGIE MELLON ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION.  CARNEGIE MELLON DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS SOFTWARE.  *   * Carnegie Mellon requests users of this software to return to  *   *  Software Distribution Coordinator  or  Software.Distribution@CS.CMU.EDU  *  School of Computer Science  *  Carnegie Mellon University  *  Pittsburgh PA 15213-3890  *   * any improvements or extensions that they make and grant Carnegie the  * rights to redistribute these changes.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_STACK_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_STACK_H_
end_define

begin_define
define|#
directive|define
name|INKERNEL
parameter_list|(
name|va
parameter_list|)
value|(((vm_offset_t)(va))>= VM_MIN_KERNEL_ADDRESS)
end_define

begin_define
define|#
directive|define
name|FR_SCP
value|(0)
end_define

begin_define
define|#
directive|define
name|FR_RLV
value|(-1)
end_define

begin_define
define|#
directive|define
name|FR_RSP
value|(-2)
end_define

begin_define
define|#
directive|define
name|FR_RFP
value|(-3)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_STACK_H_ */
end_comment

end_unit

