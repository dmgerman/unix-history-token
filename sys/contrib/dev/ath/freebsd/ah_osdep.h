begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2002-2006 Sam Leffler, Errno Consulting, Atheros  * Communications, Inc.  All rights reserved.  *  * Redistribution and use in source and binary forms are permitted  * provided that the following conditions are met:  * 1. The materials contained herein are unmodified and are used  *    unmodified.  * 2. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following NO  *    ''WARRANTY'' disclaimer below (''Disclaimer''), without  *    modification.  * 3. Redistributions in binary form must reproduce at minimum a  *    disclaimer similar to the Disclaimer below and any redistribution  *    must be conditioned upon including a substantially similar  *    Disclaimer requirement for further binary redistribution.  * 4. Neither the names of the above-listed copyright holders nor the  *    names of any contributors may be used to endorse or promote  *    product derived from this software without specific prior written  *    permission.  *  * NO WARRANTY  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ''AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF NONINFRINGEMENT,  * MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE  * FOR SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF  * USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGES.  *  * $Id: //depot/sw/linuxsrc/src/802_11/madwifi/hal/main/freebsd/ah_osdep.h#17 $  */
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
file|<machine/bus.h>
end_include

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

begin_typedef
typedef|typedef
name|bus_addr_t
name|HAL_BUS_ADDR
typedef|;
end_typedef

begin_comment
comment|/*  * Delay n microseconds.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|ath_hal_delay
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|OS_DELAY
parameter_list|(
name|_n
parameter_list|)
value|ath_hal_delay(_n)
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
value|ath_hal_memzero((_a), (_n))
end_define

begin_function_decl
specifier|extern
name|void
name|ath_hal_memzero
parameter_list|(
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

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
value|ath_hal_memcpy(_d,_s,_n)
end_define

begin_function_decl
specifier|extern
name|void
modifier|*
name|ath_hal_memcpy
parameter_list|(
name|void
modifier|*
parameter_list|,
specifier|const
name|void
modifier|*
parameter_list|,
name|size_t
parameter_list|)
function_decl|;
end_function_decl

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

begin_function_decl
specifier|extern
name|u_int32_t
name|ath_hal_getuptime
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|OS_GETUPTIME
parameter_list|(
name|_ah
parameter_list|)
value|ath_hal_getuptime(_ah)
end_define

begin_comment
comment|/*  * Register read/write; we assume the registers will always  * be memory-mapped.  Note that register accesses are done  * using target-specific functions when debugging is enabled  * (AH_DEBUG) or we are explicitly configured this way.  The  * latter is used on some platforms where the full i/o space  * cannot be directly mapped.  */
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

begin_comment
comment|/*  * The hardware registers are native little-endian byte order.  * Big-endian hosts are handled by enabling hardware byte-swap  * of register reads and writes at reset.  But the PCI clock  * domain registers are not byte swapped!  Thus, on big-endian  * platforms we have to byte-swap thoese registers specifically.  * Most of this code is collapsed at compile time because the  * register values are constants.  */
end_comment

begin_define
define|#
directive|define
name|AH_LITTLE_ENDIAN
value|1234
end_define

begin_define
define|#
directive|define
name|AH_BIG_ENDIAN
value|4321
end_define

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
name|OS_REG_WRITE
parameter_list|(
name|_ah
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
value|do {				\ 	if ( (_reg)>= 0x4000&& (_reg)< 0x5000)			\ 		bus_space_write_4((_ah)->ah_st, (_ah)->ah_sh,		\ 			(_reg), htole32(_val));			\ 	else								\ 		bus_space_write_4((_ah)->ah_st, (_ah)->ah_sh,		\ 			(_reg), (_val));				\ } while (0)
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
value|(((_reg)>= 0x4000&& (_reg)< 0x5000) ?			\ 		le32toh(bus_space_read_4((_ah)->ah_st, (_ah)->ah_sh,	\ 			(_reg))) :					\ 		bus_space_read_4((_ah)->ah_st, (_ah)->ah_sh, (_reg)))
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
name|OS_REG_WRITE
parameter_list|(
name|_ah
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
define|\
value|bus_space_write_4((_ah)->ah_st, (_ah)->ah_sh, (_reg), (_val))
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
value|((u_int32_t) bus_space_read_4((_ah)->ah_st, (_ah)->ah_sh, (_reg)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BYTE_ORDER */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AH_DEBUG || AH_REGFUNC || AH_DEBUG_ALQ */
end_comment

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

