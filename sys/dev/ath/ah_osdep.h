begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification.  * 2. Redistributions in binary form must reproduce at minimum a disclaimer  *    similar to the "NO WARRANTY" disclaimer below ("Disclaimer") and any  *    redistribution must be conditioned upon including a substantially  *    similar Disclaimer requirement for further binary redistribution.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT, MERCHANTIBILITY  * AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL  * THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR SPECIAL, EXEMPLARY,  * OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER  * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGES.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_ATH_AH_OSDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_ATH_AH_OSDEP_H_
end_define

begin_comment
comment|/*  * Atheros Hardware Access Layer (HAL) OS Dependent Definitions.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/linker_set.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_comment
comment|/*  * Bus i/o type definitions.  */
end_comment

begin_typedef
typedef|typedef
name|void
modifier|*
name|HAL_SOFTC
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|bus_space_tag_t
name|HAL_BUS_TAG
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|bus_space_handle_t
name|HAL_BUS_HANDLE
typedef|;
end_typedef

begin_comment
comment|/*  * Although the underlying hardware may support 64 bit DMA, the  * current Atheros hardware only supports 32 bit addressing.  */
end_comment

begin_typedef
typedef|typedef
name|uint32_t
name|HAL_DMA_ADDR
typedef|;
end_typedef

begin_comment
comment|/*  * Linker set writearounds for chip and RF backend registration.  */
end_comment

begin_define
define|#
directive|define
name|OS_DATA_SET
parameter_list|(
name|set
parameter_list|,
name|item
parameter_list|)
value|DATA_SET(set, item)
end_define

begin_define
define|#
directive|define
name|OS_SET_DECLARE
parameter_list|(
name|set
parameter_list|,
name|ptype
parameter_list|)
value|SET_DECLARE(set, ptype)
end_define

begin_define
define|#
directive|define
name|OS_SET_FOREACH
parameter_list|(
name|pvar
parameter_list|,
name|set
parameter_list|)
value|SET_FOREACH(pvar, set)
end_define

begin_comment
comment|/*  * Delay n microseconds.  */
end_comment

begin_define
define|#
directive|define
name|OS_DELAY
parameter_list|(
name|_n
parameter_list|)
value|DELAY(_n)
end_define

begin_define
define|#
directive|define
name|OS_INLINE
value|__inline
end_define

begin_define
define|#
directive|define
name|OS_MEMZERO
parameter_list|(
name|_a
parameter_list|,
name|_n
parameter_list|)
value|bzero((_a), (_n))
end_define

begin_define
define|#
directive|define
name|OS_MEMCPY
parameter_list|(
name|_d
parameter_list|,
name|_s
parameter_list|,
name|_n
parameter_list|)
value|memcpy(_d,_s,_n)
end_define

begin_define
define|#
directive|define
name|OS_MEMCMP
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_l
parameter_list|)
value|memcmp((_a), (_b), (_l))
end_define

begin_define
define|#
directive|define
name|abs
parameter_list|(
name|_a
parameter_list|)
value|__builtin_abs(_a)
end_define

begin_struct_decl
struct_decl|struct
name|ath_hal
struct_decl|;
end_struct_decl

begin_comment
comment|/*  * The hardware registers are native little-endian byte order.  * Big-endian hosts are handled by enabling hardware byte-swap  * of register reads and writes at reset.  But the PCI clock  * domain registers are not byte swapped!  Thus, on big-endian  * platforms we have to explicitly byte-swap those registers.  * OS_REG_UNSWAPPED identifies the registers that need special handling.  *  * This is not currently used by the FreeBSD HAL osdep code; the HAL  * currently does not configure hardware byteswapping for register space  * accesses and instead does it through the FreeBSD bus space code.  */
end_comment

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|OS_REG_UNSWAPPED
parameter_list|(
name|_reg
parameter_list|)
define|\
value|(((_reg)>= 0x4000&& (_reg)< 0x5000) || \ 	 ((_reg)>= 0x7000&& (_reg)< 0x8000))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _BYTE_ORDER == _LITTLE_ENDIAN */
end_comment

begin_define
define|#
directive|define
name|OS_REG_UNSWAPPED
parameter_list|(
name|_reg
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BYTE_ORDER */
end_comment

begin_comment
comment|/*  * For USB/SDIO support (where access latencies are quite high);  * some write accesses may be buffered and then flushed when  * either a read is done, or an explicit flush is done.  *  * These are simply placeholders for now.  */
end_comment

begin_define
define|#
directive|define
name|OS_REG_WRITE_BUFFER_ENABLE
parameter_list|(
name|_ah
parameter_list|)
define|\
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|OS_REG_WRITE_BUFFER_DISABLE
parameter_list|(
name|_ah
parameter_list|)
define|\
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|OS_REG_WRITE_BUFFER_FLUSH
parameter_list|(
name|_ah
parameter_list|)
define|\
value|do { } while (0)
end_define

begin_comment
comment|/*  * Register read/write operations are either handled through  * platform-dependent routines (or when debugging is enabled  * with AH_DEBUG); or they are inline expanded using the macros  * defined below.  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|AH_DEBUG
argument_list|)
operator|||
name|defined
argument_list|(
name|AH_REGOPS_FUNC
argument_list|)
operator|||
name|defined
argument_list|(
name|AH_DEBUG_ALQ
argument_list|)
end_if

begin_define
define|#
directive|define
name|OS_REG_WRITE
parameter_list|(
name|_ah
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
value|ath_hal_reg_write(_ah, _reg, _val)
end_define

begin_define
define|#
directive|define
name|OS_REG_READ
parameter_list|(
name|_ah
parameter_list|,
name|_reg
parameter_list|)
value|ath_hal_reg_read(_ah, _reg)
end_define

begin_function_decl
specifier|extern
name|void
name|ath_hal_reg_write
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int
name|reg
parameter_list|,
name|u_int32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|u_int32_t
name|ath_hal_reg_read
parameter_list|(
name|struct
name|ath_hal
modifier|*
name|ah
parameter_list|,
name|u_int
name|reg
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OS_REG_WRITE
parameter_list|(
name|_ah
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|bus_space_write_4((bus_space_tag_t)(_ah)->ah_st,		\ 	    (bus_space_handle_t)(_ah)->ah_sh, (_reg), (_val))
end_define

begin_define
define|#
directive|define
name|OS_REG_READ
parameter_list|(
name|_ah
parameter_list|,
name|_reg
parameter_list|)
define|\
value|bus_space_read_4((bus_space_tag_t)(_ah)->ah_st,			\ 	    (bus_space_handle_t)(_ah)->ah_sh, (_reg))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|AH_DEBUG_ALQ
end_ifdef

begin_function_decl
specifier|extern
name|void
name|OS_MARK
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
name|id
parameter_list|,
name|u_int32_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|OS_MARK
parameter_list|(
name|_ah
parameter_list|,
name|_id
parameter_list|,
name|_v
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_AH_OSDEP_H_ */
end_comment

end_unit

