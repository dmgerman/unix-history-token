begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $NetBSD: cfe_api.h,v 1.3 2003/02/07 17:38:48 cgd Exp $ */
end_comment

begin_comment
comment|/* from: SiByte Id: cfe_api.h,v 1.29 2002/07/09 23:29:11 cgd Exp $ */
end_comment

begin_comment
comment|/*-  * Copyright 2000, 2001, 2002  * Broadcom Corporation. All rights reserved.  *  * This software is furnished under license and may be used and copied only  * in accordance with the following terms and conditions.  Subject to these  * conditions, you may download, copy, install, use, modify and distribute  * modified or unmodified copies of this software in source and/or binary  * form. No title or ownership is transferred hereby.  *  * 1) Any source code used, modified or distributed must reproduce and  *    retain this copyright notice and list of conditions as they appear in  *    the source file.  *  * 2) No right is granted to use any trade name, trademark, or logo of  *    Broadcom Corporation.  The "Broadcom Corporation" name may not be  *    used to endorse or promote products derived from this software  *    without the prior written permission of Broadcom Corporation.  *  * 3) THIS SOFTWARE IS PROVIDED "AS-IS" AND ANY EXPRESS OR IMPLIED  *    WARRANTIES, INCLUDING BUT NOT LIMITED TO, ANY IMPLIED WARRANTIES OF  *    MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, OR  *    NON-INFRINGEMENT ARE DISCLAIMED. IN NO EVENT SHALL BROADCOM BE LIABLE  *    FOR ANY DAMAGES WHATSOEVER, AND IN PARTICULAR, BROADCOM SHALL NOT BE  *    LIABLE FOR DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  *    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  *    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR  *    BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,  *    WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE  *    OR OTHERWISE), EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/*  *********************************************************************     *     *  Broadcom Common Firmware Environment (CFE)     *     *  Device function prototypes		File: cfe_api.h     *     *  This file contains declarations for doing callbacks to     *  cfe from an application.  It should be the only header     *  needed by the application to use this library     *     *  Authors:  Mitch Lichtenberg, Chris Demetriou     *     ********************************************************************* */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|CFE_API_H
end_ifndef

begin_define
define|#
directive|define
name|CFE_API_H
end_define

begin_comment
comment|/*  * Apply customizations here for different OSes.  These need to:  *	* typedef uint64_t, int64_t, intptr_t, uintptr_t.  *	* define cfe_strlen() if use of an existing function is desired.  *	* define CFE_API_IMPL_NAMESPACE if API functions are to use  *	  names in the implementation namespace.  * Also, optionally, if the build environment does not do so automatically,  * CFE_API_* can be defined here as desired.  */
end_comment

begin_comment
comment|/* Begin customization. */
end_comment

begin_include
include|#
directive|include
file|<sys/stdint.h>
end_include

begin_comment
comment|/* All of the typedefs.  */
end_comment

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_comment
comment|/* strlen() prototype.  */
end_comment

begin_define
define|#
directive|define
name|CFE_API_ALL
end_define

begin_define
define|#
directive|define
name|cfe_strlen
parameter_list|(
name|x
parameter_list|)
value|strlen(x)
end_define

begin_comment
comment|/* End customization. */
end_comment

begin_comment
comment|/*  *********************************************************************     *  Constants     ********************************************************************* */
end_comment

begin_comment
comment|/* Seal indicating CFE's presence, passed to user program. */
end_comment

begin_define
define|#
directive|define
name|CFE_EPTSEAL
value|0x43464531
end_define

begin_define
define|#
directive|define
name|CFE_MI_RESERVED
value|0
end_define

begin_comment
comment|/* memory is reserved, do not use */
end_comment

begin_define
define|#
directive|define
name|CFE_MI_AVAILABLE
value|1
end_define

begin_comment
comment|/* memory is available */
end_comment

begin_define
define|#
directive|define
name|CFE_FLG_WARMSTART
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CFE_FLG_FULL_ARENA
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CFE_FLG_ENV_PERMANENT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CFE_CPU_CMD_START
value|1
end_define

begin_define
define|#
directive|define
name|CFE_CPU_CMD_STOP
value|0
end_define

begin_define
define|#
directive|define
name|CFE_STDHANDLE_CONSOLE
value|0
end_define

begin_define
define|#
directive|define
name|CFE_DEV_NETWORK
value|1
end_define

begin_define
define|#
directive|define
name|CFE_DEV_DISK
value|2
end_define

begin_define
define|#
directive|define
name|CFE_DEV_FLASH
value|3
end_define

begin_define
define|#
directive|define
name|CFE_DEV_SERIAL
value|4
end_define

begin_define
define|#
directive|define
name|CFE_DEV_CPU
value|5
end_define

begin_define
define|#
directive|define
name|CFE_DEV_NVRAM
value|6
end_define

begin_define
define|#
directive|define
name|CFE_DEV_CLOCK
value|7
end_define

begin_define
define|#
directive|define
name|CFE_DEV_OTHER
value|8
end_define

begin_define
define|#
directive|define
name|CFE_DEV_MASK
value|0x0F
end_define

begin_define
define|#
directive|define
name|CFE_CACHE_FLUSH_D
value|1
end_define

begin_define
define|#
directive|define
name|CFE_CACHE_INVAL_I
value|2
end_define

begin_define
define|#
directive|define
name|CFE_CACHE_INVAL_D
value|4
end_define

begin_define
define|#
directive|define
name|CFE_CACHE_INVAL_L2
value|8
end_define

begin_define
define|#
directive|define
name|CFE_FWI_64BIT
value|0x00000001
end_define

begin_define
define|#
directive|define
name|CFE_FWI_32BIT
value|0x00000002
end_define

begin_define
define|#
directive|define
name|CFE_FWI_RELOC
value|0x00000004
end_define

begin_define
define|#
directive|define
name|CFE_FWI_UNCACHED
value|0x00000008
end_define

begin_define
define|#
directive|define
name|CFE_FWI_MULTICPU
value|0x00000010
end_define

begin_define
define|#
directive|define
name|CFE_FWI_FUNCSIM
value|0x00000020
end_define

begin_define
define|#
directive|define
name|CFE_FWI_RTLSIM
value|0x00000040
end_define

begin_typedef
typedef|typedef
struct|struct
block|{
name|int64_t
name|fwi_version
decl_stmt|;
comment|/* major, minor, eco version */
name|int64_t
name|fwi_totalmem
decl_stmt|;
comment|/* total installed mem */
name|int64_t
name|fwi_flags
decl_stmt|;
comment|/* various flags */
name|int64_t
name|fwi_boardid
decl_stmt|;
comment|/* board ID */
name|int64_t
name|fwi_bootarea_va
decl_stmt|;
comment|/* VA of boot area */
name|int64_t
name|fwi_bootarea_pa
decl_stmt|;
comment|/* PA of boot area */
name|int64_t
name|fwi_bootarea_size
decl_stmt|;
comment|/* size of boot area */
block|}
name|cfe_fwinfo_t
typedef|;
end_typedef

begin_comment
comment|/*  * cfe_strlen is handled specially: If already defined, it has been  * overridden in this environment with a standard strlen-like function.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|cfe_strlen
end_ifdef

begin_define
define|#
directive|define
name|CFE_API_STRLEN_CUSTOM
end_define

begin_else
else|#
directive|else
end_else

begin_ifdef
ifdef|#
directive|ifdef
name|CFE_API_IMPL_NAMESPACE
end_ifdef

begin_define
define|#
directive|define
name|cfe_strlen
parameter_list|(
name|a
parameter_list|)
value|__cfe_strlen(a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
name|int
name|cfe_strlen
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Defines and prototypes for functions which take no arguments.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CFE_API_IMPL_NAMESPACE
end_ifdef

begin_function_decl
name|int64_t
name|__cfe_getticks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|cfe_getticks
parameter_list|()
value|__cfe_getticks()
end_define

begin_else
else|#
directive|else
end_else

begin_function_decl
name|int64_t
name|cfe_getticks
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Defines and prototypes for the rest of the functions.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CFE_API_IMPL_NAMESPACE
end_ifdef

begin_define
define|#
directive|define
name|cfe_close
parameter_list|(
name|a
parameter_list|)
value|__cfe_close(a)
end_define

begin_define
define|#
directive|define
name|cfe_cpu_start
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|__cfe_cpu_start(a,b,c,d,e)
end_define

begin_define
define|#
directive|define
name|cfe_cpu_stop
parameter_list|(
name|a
parameter_list|)
value|__cfe_cpu_stop(a)
end_define

begin_define
define|#
directive|define
name|cfe_enumenv
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|)
value|__cfe_enumenv(a,b,d,e,f)
end_define

begin_define
define|#
directive|define
name|cfe_enummem
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|)
value|__cfe_enummem(a,b,c,d,e)
end_define

begin_define
define|#
directive|define
name|cfe_exit
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__cfe_exit(a,b)
end_define

begin_define
define|#
directive|define
name|cfe_flushcache
parameter_list|(
name|a
parameter_list|)
value|__cfe_cacheflush(a)
end_define

begin_define
define|#
directive|define
name|cfe_getdevinfo
parameter_list|(
name|a
parameter_list|)
value|__cfe_getdevinfo(a)
end_define

begin_define
define|#
directive|define
name|cfe_getenv
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__cfe_getenv(a,b,c)
end_define

begin_define
define|#
directive|define
name|cfe_getfwinfo
parameter_list|(
name|a
parameter_list|)
value|__cfe_getfwinfo(a)
end_define

begin_define
define|#
directive|define
name|cfe_getstdhandle
parameter_list|(
name|a
parameter_list|)
value|__cfe_getstdhandle(a)
end_define

begin_define
define|#
directive|define
name|cfe_init
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__cfe_init(a,b)
end_define

begin_define
define|#
directive|define
name|cfe_inpstat
parameter_list|(
name|a
parameter_list|)
value|__cfe_inpstat(a)
end_define

begin_define
define|#
directive|define
name|cfe_ioctl
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|,
name|e
parameter_list|,
name|f
parameter_list|)
value|__cfe_ioctl(a,b,c,d,e,f)
end_define

begin_define
define|#
directive|define
name|cfe_open
parameter_list|(
name|a
parameter_list|)
value|__cfe_open(a)
end_define

begin_define
define|#
directive|define
name|cfe_read
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__cfe_read(a,b,c)
end_define

begin_define
define|#
directive|define
name|cfe_readblk
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|__cfe_readblk(a,b,c,d)
end_define

begin_define
define|#
directive|define
name|cfe_setenv
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|)
value|__cfe_setenv(a,b)
end_define

begin_define
define|#
directive|define
name|cfe_write
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|)
value|__cfe_write(a,b,c)
end_define

begin_define
define|#
directive|define
name|cfe_writeblk
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|__cfe_writeblk(a,b,c,d)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CFE_API_IMPL_NAMESPACE */
end_comment

begin_function_decl
name|int
name|cfe_close
parameter_list|(
name|int
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfe_cpu_start
parameter_list|(
name|int
name|cpu
parameter_list|,
name|void
function_decl|(
modifier|*
name|fn
function_decl|)
parameter_list|(
name|void
parameter_list|)
parameter_list|,
name|long
name|sp
parameter_list|,
name|long
name|gp
parameter_list|,
name|long
name|a1
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfe_cpu_stop
parameter_list|(
name|int
name|cpu
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfe_enumenv
parameter_list|(
name|int
name|idx
parameter_list|,
name|char
modifier|*
name|name
parameter_list|,
name|int
name|namelen
parameter_list|,
name|char
modifier|*
name|val
parameter_list|,
name|int
name|vallen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfe_enummem
parameter_list|(
name|int
name|idx
parameter_list|,
name|int
name|flags
parameter_list|,
name|uint64_t
modifier|*
name|start
parameter_list|,
name|uint64_t
modifier|*
name|length
parameter_list|,
name|uint64_t
modifier|*
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfe_exit
parameter_list|(
name|int
name|warm
parameter_list|,
name|int
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfe_flushcache
parameter_list|(
name|int
name|flg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfe_getdevinfo
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfe_getenv
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|dest
parameter_list|,
name|int
name|destlen
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfe_getfwinfo
parameter_list|(
name|cfe_fwinfo_t
modifier|*
name|info
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfe_getstdhandle
parameter_list|(
name|int
name|flg
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfe_init
parameter_list|(
name|uint64_t
name|handle
parameter_list|,
name|uint64_t
name|ept
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfe_inpstat
parameter_list|(
name|int
name|handle
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfe_ioctl
parameter_list|(
name|int
name|handle
parameter_list|,
name|unsigned
name|int
name|ioctlnum
parameter_list|,
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|length
parameter_list|,
name|int
modifier|*
name|retlen
parameter_list|,
name|uint64_t
name|offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfe_open
parameter_list|(
name|char
modifier|*
name|name
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfe_read
parameter_list|(
name|int
name|handle
parameter_list|,
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfe_readblk
parameter_list|(
name|int
name|handle
parameter_list|,
name|int64_t
name|offset
parameter_list|,
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfe_setenv
parameter_list|(
name|char
modifier|*
name|name
parameter_list|,
name|char
modifier|*
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfe_write
parameter_list|(
name|int
name|handle
parameter_list|,
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|cfe_writeblk
parameter_list|(
name|int
name|handle
parameter_list|,
name|int64_t
name|offset
parameter_list|,
name|unsigned
name|char
modifier|*
name|buffer
parameter_list|,
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* CFE_API_H */
end_comment

end_unit

