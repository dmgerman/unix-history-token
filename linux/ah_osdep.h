begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002-2008 Sam Leffler, Errno Consulting  * Copyright (c) 2002-2008 Atheros Communications, Inc.  *  * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR  * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN  * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF  * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $Id: ah_osdep.h,v 1.3 2008/11/10 04:08:05 sam Exp $  */
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

begin_comment
comment|/*  * Starting with 2.6.4 the kernel supports a configuration option  * to pass parameters in registers.  If this is enabled we must  * mark all function interfaces in+out of the HAL to pass parameters  * on the stack as this is the convention used internally (for  * maximum portability).  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_REGPARM
end_ifdef

begin_define
define|#
directive|define
name|__ahdecl
value|__attribute__((regparm(0)))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__ahdecl
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__packed
end_ifndef

begin_define
define|#
directive|define
name|__packed
value|__attribute__((__packed__))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Beware of these being mismatched against the contents of<linux/types.h>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_LINUX_TYPES_H
end_ifndef

begin_comment
comment|/* NB: arm defaults to unsigned so be explicit */
end_comment

begin_typedef
typedef|typedef
name|signed
name|char
name|int8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|short
name|int16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int
name|int32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|long
name|long
name|int64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|char
name|uint8_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|short
name|uint16_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|uint32_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|long
name|long
name|uint64_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|size_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|unsigned
name|int
name|u_int
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|void
modifier|*
name|va_list
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Linux/BSD gcc compatibility shims.  */
end_comment

begin_define
define|#
directive|define
name|__printflike
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|)
define|\
value|__attribute__ ((__format__ (__printf__, _a, _b)))
end_define

begin_define
define|#
directive|define
name|__va_list
value|va_list
end_define

begin_define
define|#
directive|define
name|OS_INLINE
value|__inline
end_define

begin_comment
comment|/*  * Delay n microseconds.  */
end_comment

begin_function_decl
specifier|extern
name|void
name|__ahdecl
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
name|__ahdecl
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
name|__ahdecl
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

begin_ifndef
ifndef|#
directive|ifndef
name|abs
end_ifndef

begin_define
define|#
directive|define
name|abs
parameter_list|(
name|_a
parameter_list|)
value|__builtin_abs(_a)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct_decl
struct_decl|struct
name|ath_hal
struct_decl|;
end_struct_decl

begin_function_decl
specifier|extern
name|uint32_t
name|__ahdecl
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
comment|/*  * Byte order/swapping support.  */
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

begin_ifndef
ifndef|#
directive|ifndef
name|AH_BYTE_ORDER
end_ifndef

begin_comment
comment|/*  * When the .inc file is not available (e.g. when building  * in a kernel source tree); look for some other way to  * setup the host byte order.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|__LITTLE_ENDIAN
end_ifdef

begin_define
define|#
directive|define
name|AH_BYTE_ORDER
value|AH_LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__BIG_ENDIAN
end_ifdef

begin_define
define|#
directive|define
name|AH_BYTE_ORDER
value|AH_BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|AH_BYTE_ORDER
end_ifndef

begin_error
error|#
directive|error
literal|"Do not know host byte order"
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AH_BYTE_ORDER */
end_comment

begin_if
if|#
directive|if
name|AH_BYTE_ORDER
operator|==
name|AH_BIG_ENDIAN
end_if

begin_comment
comment|/*  * This could be optimized but since we only use it for  * a few registers there's little reason to do so.  */
end_comment

begin_function
specifier|static
name|__inline__
name|uint32_t
name|__bswap32
parameter_list|(
name|uint32_t
name|_x
parameter_list|)
block|{
return|return
operator|(
call|(
name|uint32_t
call|)
argument_list|(
operator|(
operator|(
operator|(
specifier|const
name|uint8_t
operator|*
operator|)
operator|(
operator|&
name|_x
operator|)
operator|)
index|[
literal|0
index|]
operator|)
operator||
operator|(
operator|(
operator|(
specifier|const
name|uint8_t
operator|*
operator|)
operator|(
operator|&
name|_x
operator|)
operator|)
index|[
literal|1
index|]
operator|<<
literal|8
operator|)
operator||
operator|(
operator|(
operator|(
specifier|const
name|uint8_t
operator|*
operator|)
operator|(
operator|&
name|_x
operator|)
operator|)
index|[
literal|2
index|]
operator|<<
literal|16
operator|)
operator||
operator|(
operator|(
operator|(
specifier|const
name|uint8_t
operator|*
operator|)
operator|(
operator|&
name|_x
operator|)
operator|)
index|[
literal|3
index|]
operator|<<
literal|24
operator|)
argument_list|)
operator|)
return|;
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|__bswap32
parameter_list|(
name|_x
parameter_list|)
value|(_x)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Register read/write; we assume the registers will always  * be memory-mapped.  Note that register accesses are done  * using target-specific functions when debugging is enabled  * (AH_DEBUG) or we are explicitly configured this way.  The  * latter is used on some platforms where the full i/o space  * cannot be directly mapped.  *  * The hardware registers are native little-endian byte order.  * Big-endian hosts are handled by enabling hardware byte-swap  * of register reads and writes at reset.  But the PCI clock  * domain registers are not byte swapped!  Thus, on big-endian  * platforms we have to byte-swap thoese registers specifically.  * Most of this code is collapsed at compile time because the  * register values are constants.  */
end_comment

begin_if
if|#
directive|if
name|AH_BYTE_ORDER
operator|==
name|AH_BIG_ENDIAN
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

begin_define
define|#
directive|define
name|_OS_REG_WRITE
parameter_list|(
name|_ah
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
value|do {				    \ 	if (OS_REG_UNSWAPPED(_reg))					    \ 		*((volatile uint32_t *)((_ah)->ah_sh + (_reg))) =	    \ 			__bswap32((_val));				    \ 	else								    \ 		*((volatile uint32_t *)((_ah)->ah_sh + (_reg))) = (_val);  \ } while (0)
end_define

begin_define
define|#
directive|define
name|_OS_REG_READ
parameter_list|(
name|_ah
parameter_list|,
name|_reg
parameter_list|)
define|\
value|(OS_REG_UNSWAPPED(_reg) ? \ 		__bswap32(*((volatile uint32_t *)((_ah)->ah_sh + (_reg)))) : \ 		*((volatile uint32_t *)((_ah)->ah_sh + (_reg))))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* AH_LITTLE_ENDIAN */
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

begin_define
define|#
directive|define
name|_OS_REG_WRITE
parameter_list|(
name|_ah
parameter_list|,
name|_reg
parameter_list|,
name|_val
parameter_list|)
value|do { \ 	*((volatile uint32_t *)((_ah)->ah_sh + (_reg))) = (_val); \ } while (0)
end_define

begin_define
define|#
directive|define
name|_OS_REG_READ
parameter_list|(
name|_ah
parameter_list|,
name|_reg
parameter_list|)
define|\
value|*((volatile uint32_t *)((_ah)->ah_sh + (_reg)))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* AH_BYTE_ORDER */
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

begin_comment
comment|/* use functions to do register operations */
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
name|__ahdecl
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
name|uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|uint32_t
name|__ahdecl
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
comment|/* inline register operations */
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
value|_OS_REG_WRITE(_ah, _reg, _val)
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
value|_OS_REG_READ(_ah, _reg)
end_define

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
name|__ahdecl
name|OS_MARK
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|,
name|u_int
name|id
parameter_list|,
name|uint32_t
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

begin_comment
comment|/*  * Linux-specific attach/detach methods needed for module reference counting.  *  * XXX We can't use HAL_STATUS because the type isn't defined at this  *     point (circular dependency); we wack the type and patch things  *     up in the function.  *  * NB: These are intentionally not marked __ahdecl since they are  *     compiled with the default calling convetion and are not called  *     from within the HAL.  */
end_comment

begin_function_decl
specifier|extern
name|struct
name|ath_hal
modifier|*
name|_ath_hal_attach
parameter_list|(
name|uint16_t
name|devid
parameter_list|,
name|HAL_SOFTC
parameter_list|,
name|HAL_BUS_TAG
parameter_list|,
name|HAL_BUS_HANDLE
parameter_list|,
name|void
modifier|*
name|status
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|ath_hal_detach
parameter_list|(
name|struct
name|ath_hal
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _ATH_AH_OSDEP_H_ */
end_comment

end_unit

