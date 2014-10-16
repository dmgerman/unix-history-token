begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Silicon Graphics International Corp.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    substantially similar to the "NO WARRANTY" disclaimer below  *    ("Disclaimer") and any redistribution must be conditioned upon  *    including a substantially similar Disclaimer requirement for further  *    binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR  * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT  * HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING  * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGES.  *  * $Id: //depot/users/kenm/FreeBSD-test2/sys/cam/ctl/ctl_debug.h#2 $  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  * CAM Target Layer debugging interface.  *  * Author: Ken Merry<ken@FreeBSD.org>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CTL_DEBUG_H_
end_ifndef

begin_define
define|#
directive|define
name|_CTL_DEBUG_H_
end_define

begin_comment
comment|/*  * Debugging flags.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CTL_DEBUG_NONE
init|=
literal|0x00
block|,
comment|/* no debugging */
name|CTL_DEBUG_INFO
init|=
literal|0x01
block|,
comment|/* SCSI errors */
name|CTL_DEBUG_CDB
init|=
literal|0x02
block|,
comment|/* SCSI CDBs and tasks */
name|CTL_DEBUG_CDB_DATA
init|=
literal|0x04
comment|/* SCSI CDB DATA */
block|}
name|ctl_debug_flags
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|CAM_CTL_DEBUG
end_ifdef

begin_define
define|#
directive|define
name|CTL_DEBUG_PRINT
parameter_list|(
name|X
parameter_list|)
define|\
value|do {				\ 		printf("ctl_debug: ");	\ 		printf X;		\ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* CAM_CTL_DEBUG */
end_comment

begin_define
define|#
directive|define
name|CTL_DEBUG_PRINT
parameter_list|(
name|X
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CAM_CTL_DEBUG */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CTL_DEBUG_H_ */
end_comment

end_unit

