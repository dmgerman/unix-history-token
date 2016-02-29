begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2011 Semihalf.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|TYPES_FREEBSD_H_
end_ifndef

begin_define
define|#
directive|define
name|TYPES_FREEBSD_H_
end_define

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<sys/libkern.h>
end_include

begin_include
include|#
directive|include
file|<sys/stddef.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<machine/pio.h>
end_include

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|__bool_true_false_are_defined
argument_list|)
end_if

begin_typedef
typedef|typedef
name|boolean_t
name|bool
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_typedef
typedef|typedef
name|vm_paddr_t
name|physAddress_t
typedef|;
end_typedef

begin_define
define|#
directive|define
name|_Packed
end_define

begin_define
define|#
directive|define
name|_PackedType
value|__attribute__ ((packed))
end_define

begin_comment
comment|/**  * Accessor defines.  * TODO: These are only stubs and have to be redefined (use bus_space  * facilities).  */
end_comment

begin_define
define|#
directive|define
name|GET_UINT32
parameter_list|(
name|arg
parameter_list|)
value|in32(&(arg))
end_define

begin_define
define|#
directive|define
name|GET_UINT64
parameter_list|(
name|arg
parameter_list|)
value|in64(&(arg))
end_define

begin_define
define|#
directive|define
name|_WRITE_UINT32
parameter_list|(
name|arg
parameter_list|,
name|data
parameter_list|)
value|out32(&(arg), (data))
end_define

begin_define
define|#
directive|define
name|_WRITE_UINT64
parameter_list|(
name|arg
parameter_list|,
name|data
parameter_list|)
value|out64(&(arg), (data))
end_define

begin_ifndef
ifndef|#
directive|ifndef
name|QE_32_BIT_ACCESS_RESTRICTION
end_ifndef

begin_define
define|#
directive|define
name|GET_UINT8
parameter_list|(
name|arg
parameter_list|)
value|in8(&(arg))
end_define

begin_define
define|#
directive|define
name|GET_UINT16
parameter_list|(
name|arg
parameter_list|)
value|in16(&(arg))
end_define

begin_define
define|#
directive|define
name|_WRITE_UINT8
parameter_list|(
name|arg
parameter_list|,
name|data
parameter_list|)
value|out8(&(arg), (data))
end_define

begin_define
define|#
directive|define
name|_WRITE_UINT16
parameter_list|(
name|arg
parameter_list|,
name|data
parameter_list|)
value|out16(&(arg), (data))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* QE_32_BIT_ACCESS_RESTRICTION */
end_comment

begin_define
define|#
directive|define
name|QE_32_BIT_ADDR
parameter_list|(
name|_arg
parameter_list|)
value|(uint32_t)((uint32_t)&(_arg)& 0xFFFFFFFC)
end_define

begin_define
define|#
directive|define
name|QE_32_BIT_SHIFT8
parameter_list|(
name|__arg
parameter_list|)
value|(uint32_t)((3 - ((uint32_t)&(__arg)& 0x3)) * 8)
end_define

begin_define
define|#
directive|define
name|QE_32_BIT_SHIFT16
parameter_list|(
name|__arg
parameter_list|)
value|(uint32_t)((2 - ((uint32_t)&(__arg)& 0x3)) * 8)
end_define

begin_define
define|#
directive|define
name|GET_UINT8
parameter_list|(
name|arg
parameter_list|)
value|(uint8_t)(in32(QE_32_BIT_ADDR(arg))>> QE_32_BIT_SHIFT8(arg))
end_define

begin_define
define|#
directive|define
name|GET_UINT16
parameter_list|(
name|arg
parameter_list|)
value|(uint16_t)(in32(QE_32_BIT_ADDR(arg))>> QE_32_BIT_SHIFT16(arg))
end_define

begin_define
define|#
directive|define
name|_WRITE_UINT8
parameter_list|(
name|arg
parameter_list|,
name|data
parameter_list|)
define|\
value|do                                                                                                  \     {                                                                                                   \         uint32_t addr = QE_32_BIT_ADDR(arg);                                                            \         uint32_t shift = QE_32_BIT_SHIFT8(arg);                                                         \         uint32_t tmp = in32(addr);                                                                      \         tmp = (uint32_t)((tmp& ~(0x000000FF<< shift)) | ((uint32_t)(data& 0x000000FF)<< shift));    \         out32(addr, tmp);                                                                               \     } while (0)
end_define

begin_define
define|#
directive|define
name|_WRITE_UINT16
parameter_list|(
name|arg
parameter_list|,
name|data
parameter_list|)
define|\
value|do                                                                                                  \     {                                                                                                   \         uint32_t addr = QE_32_BIT_ADDR(arg);                                                            \         uint32_t shift = QE_32_BIT_SHIFT16(arg);                                                        \         uint32_t tmp = in32(addr);                                                                      \         tmp = (uint32_t)((tmp& ~(0x0000FFFF<< shift)) | ((uint32_t)(data& 0x0000FFFF)<< shift));    \         out32(addr, tmp);                                                                               \     } while (0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* QE_32_BIT_ACCESS_RESTRICTION */
end_comment

begin_define
define|#
directive|define
name|WRITE_UINT8
value|_WRITE_UINT8
end_define

begin_define
define|#
directive|define
name|WRITE_UINT16
value|_WRITE_UINT16
end_define

begin_define
define|#
directive|define
name|WRITE_UINT32
value|_WRITE_UINT32
end_define

begin_define
define|#
directive|define
name|WRITE_UINT64
value|_WRITE_UINT64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* TYPES_FREEBSD_H_ */
end_comment

end_unit

