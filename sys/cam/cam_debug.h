begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Macros for tracing/loging information in the CAM layer  *  * Copyright (c) 1997 Justin T. Gibbs.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_CAM_CAM_DEBUG_H
end_ifndef

begin_define
define|#
directive|define
name|_CAM_CAM_DEBUG_H
value|1
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CAMDEBUG
argument_list|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CAMDEBUG&& _KERNEL */
end_comment

begin_comment
comment|/*  * Debugging flags.  */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|CAM_DEBUG_NONE
init|=
literal|0x00
block|,
comment|/* no debugging */
name|CAM_DEBUG_INFO
init|=
literal|0x01
block|,
comment|/* scsi commands, errors, data */
name|CAM_DEBUG_TRACE
init|=
literal|0x02
block|,
comment|/* routine flow tracking */
name|CAM_DEBUG_SUBTRACE
init|=
literal|0x04
block|,
comment|/* internal to routine flows */
name|CAM_DEBUG_CDB
init|=
literal|0x08
block|,
comment|/* print out SCSI CDBs only */
name|CAM_DEBUG_XPT
init|=
literal|0x10
block|,
comment|/* print out xpt scheduling */
name|CAM_DEBUG_PERIPH
init|=
literal|0x20
comment|/* print out peripheral calls */
block|}
name|cam_debug_flags
typedef|;
end_typedef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|CAMDEBUG
argument_list|)
operator|&&
name|defined
argument_list|(
name|_KERNEL
argument_list|)
end_if

begin_comment
comment|/* Path we want to debug */
end_comment

begin_decl_stmt
specifier|extern
name|struct
name|cam_path
modifier|*
name|cam_dpath
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Current debug levels set */
end_comment

begin_decl_stmt
specifier|extern
name|u_int32_t
name|cam_dflags
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Printf delay value (to prevent scrolling */
end_comment

begin_decl_stmt
specifier|extern
name|u_int32_t
name|cam_debug_delay
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* Debugging macros. */
end_comment

begin_define
define|#
directive|define
name|CAM_DEBUGGED
parameter_list|(
name|path
parameter_list|,
name|flag
parameter_list|)
define|\
value|((cam_dflags& (flag))				\&& (cam_dpath != NULL)				\&& (xpt_path_comp(cam_dpath, path)>= 0)	\&& (xpt_path_comp(cam_dpath, path)< 2))
end_define

begin_define
define|#
directive|define
name|CAM_DEBUG
parameter_list|(
name|path
parameter_list|,
name|flag
parameter_list|,
name|printfargs
parameter_list|)
define|\
value|if ((cam_dflags& (flag))			\&& (cam_dpath != NULL)				\&& (xpt_path_comp(cam_dpath, path)>= 0)	\&& (xpt_path_comp(cam_dpath, path)< 2)) {	\ 		xpt_print_path(path);			\  		printf printfargs;			\ 		if (cam_debug_delay != 0)		\ 			DELAY(cam_debug_delay);		\ 	}
end_define

begin_define
define|#
directive|define
name|CAM_DEBUG_PRINT
parameter_list|(
name|flag
parameter_list|,
name|printfargs
parameter_list|)
define|\
value|if (cam_dflags& (flag)) {			\ 		printf("cam_debug: ");			\  		printf printfargs;			\ 		if (cam_debug_delay != 0)		\ 			DELAY(cam_debug_delay);		\ 	}
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* !CAMDEBUG || !_KERNEL */
end_comment

begin_define
define|#
directive|define
name|CAM_DEBUGGED
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
value|0
end_define

begin_define
define|#
directive|define
name|CAM_DEBUG
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|)
end_define

begin_define
define|#
directive|define
name|CAM_DEBUG_PRINT
parameter_list|(
name|A
parameter_list|,
name|B
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CAMDEBUG&& _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _CAM_CAM_DEBUG_H */
end_comment

end_unit

