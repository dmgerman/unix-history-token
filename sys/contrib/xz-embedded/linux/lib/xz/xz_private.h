begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Private includes and definitions  *  * Author: Lasse Collin<lasse.collin@tukaani.org>  *  * This file has been put into the public domain.  * You can do whatever you want with this file.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XZ_PRIVATE_H
end_ifndef

begin_define
define|#
directive|define
name|XZ_PRIVATE_H
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|__KERNEL__
end_ifdef

begin_include
include|#
directive|include
file|<linux/xz.h>
end_include

begin_include
include|#
directive|include
file|<linux/kernel.h>
end_include

begin_include
include|#
directive|include
file|<asm/unaligned.h>
end_include

begin_comment
comment|/* XZ_PREBOOT may be defined only via decompress_unxz.c. */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XZ_PREBOOT
end_ifndef

begin_include
include|#
directive|include
file|<linux/slab.h>
end_include

begin_include
include|#
directive|include
file|<linux/vmalloc.h>
end_include

begin_include
include|#
directive|include
file|<linux/string.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_XZ_DEC_X86
end_ifdef

begin_define
define|#
directive|define
name|XZ_DEC_X86
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_XZ_DEC_POWERPC
end_ifdef

begin_define
define|#
directive|define
name|XZ_DEC_POWERPC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_XZ_DEC_IA64
end_ifdef

begin_define
define|#
directive|define
name|XZ_DEC_IA64
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_XZ_DEC_ARM
end_ifdef

begin_define
define|#
directive|define
name|XZ_DEC_ARM
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_XZ_DEC_ARMTHUMB
end_ifdef

begin_define
define|#
directive|define
name|XZ_DEC_ARMTHUMB
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|CONFIG_XZ_DEC_SPARC
end_ifdef

begin_define
define|#
directive|define
name|XZ_DEC_SPARC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|memeq
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|size
parameter_list|)
value|(memcmp(a, b, size) == 0)
end_define

begin_define
define|#
directive|define
name|memzero
parameter_list|(
name|buf
parameter_list|,
name|size
parameter_list|)
value|memset(buf, 0, size)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|get_le32
parameter_list|(
name|p
parameter_list|)
value|le32_to_cpup((const uint32_t *)(p))
end_define

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* 	 * For userspace builds, use a separate header to define the required 	 * macros and functions. This makes it easier to adapt the code into 	 * different environments and avoids clutter in the Linux kernel tree. 	 */
end_comment

begin_include
include|#
directive|include
file|<contrib/xz-embedded/freebsd/xz_config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* If no specific decoding mode is requested, enable support for all modes. */
end_comment

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|XZ_DEC_SINGLE
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|XZ_DEC_PREALLOC
argument_list|)
expr|\
operator|&&
operator|!
name|defined
argument_list|(
name|XZ_DEC_DYNALLOC
argument_list|)
end_if

begin_define
define|#
directive|define
name|XZ_DEC_SINGLE
end_define

begin_define
define|#
directive|define
name|XZ_DEC_PREALLOC
end_define

begin_define
define|#
directive|define
name|XZ_DEC_DYNALLOC
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The DEC_IS_foo(mode) macros are used in "if" statements. If only some  * of the supported modes are enabled, these macros will evaluate to true or  * false at compile time and thus allow the compiler to omit unneeded code.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|XZ_DEC_SINGLE
end_ifdef

begin_define
define|#
directive|define
name|DEC_IS_SINGLE
parameter_list|(
name|mode
parameter_list|)
value|((mode) == XZ_SINGLE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEC_IS_SINGLE
parameter_list|(
name|mode
parameter_list|)
value|(false)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|XZ_DEC_PREALLOC
end_ifdef

begin_define
define|#
directive|define
name|DEC_IS_PREALLOC
parameter_list|(
name|mode
parameter_list|)
value|((mode) == XZ_PREALLOC)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEC_IS_PREALLOC
parameter_list|(
name|mode
parameter_list|)
value|(false)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|XZ_DEC_DYNALLOC
end_ifdef

begin_define
define|#
directive|define
name|DEC_IS_DYNALLOC
parameter_list|(
name|mode
parameter_list|)
value|((mode) == XZ_DYNALLOC)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEC_IS_DYNALLOC
parameter_list|(
name|mode
parameter_list|)
value|(false)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|XZ_DEC_SINGLE
argument_list|)
end_if

begin_define
define|#
directive|define
name|DEC_IS_MULTI
parameter_list|(
name|mode
parameter_list|)
value|(true)
end_define

begin_elif
elif|#
directive|elif
name|defined
argument_list|(
name|XZ_DEC_PREALLOC
argument_list|)
operator|||
name|defined
argument_list|(
name|XZ_DEC_DYNALLOC
argument_list|)
end_elif

begin_define
define|#
directive|define
name|DEC_IS_MULTI
parameter_list|(
name|mode
parameter_list|)
value|((mode) != XZ_SINGLE)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEC_IS_MULTI
parameter_list|(
name|mode
parameter_list|)
value|(false)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * If any of the BCJ filter decoders are wanted, define XZ_DEC_BCJ.  * XZ_DEC_BCJ is used to enable generic support for BCJ decoders.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|XZ_DEC_BCJ
end_ifndef

begin_if
if|#
directive|if
name|defined
argument_list|(
name|XZ_DEC_X86
argument_list|)
operator|||
name|defined
argument_list|(
name|XZ_DEC_POWERPC
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|XZ_DEC_IA64
argument_list|)
operator|||
name|defined
argument_list|(
name|XZ_DEC_ARM
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|XZ_DEC_ARM
argument_list|)
operator|||
name|defined
argument_list|(
name|XZ_DEC_ARMTHUMB
argument_list|)
expr|\
operator|||
name|defined
argument_list|(
name|XZ_DEC_SPARC
argument_list|)
end_if

begin_define
define|#
directive|define
name|XZ_DEC_BCJ
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
comment|/*  * Allocate memory for LZMA2 decoder. xz_dec_lzma2_reset() must be used  * before calling xz_dec_lzma2_run().  */
end_comment

begin_function_decl
name|XZ_EXTERN
name|struct
name|xz_dec_lzma2
modifier|*
name|xz_dec_lzma2_create
parameter_list|(
name|enum
name|xz_mode
name|mode
parameter_list|,
name|uint32_t
name|dict_max
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Decode the LZMA2 properties (one byte) and reset the decoder. Return  * XZ_OK on success, XZ_MEMLIMIT_ERROR if the preallocated dictionary is not  * big enough, and XZ_OPTIONS_ERROR if props indicates something that this  * decoder doesn't support.  */
end_comment

begin_function_decl
name|XZ_EXTERN
name|enum
name|xz_ret
name|xz_dec_lzma2_reset
parameter_list|(
name|struct
name|xz_dec_lzma2
modifier|*
name|s
parameter_list|,
name|uint8_t
name|props
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Decode raw LZMA2 stream from b->in to b->out. */
end_comment

begin_function_decl
name|XZ_EXTERN
name|enum
name|xz_ret
name|xz_dec_lzma2_run
parameter_list|(
name|struct
name|xz_dec_lzma2
modifier|*
name|s
parameter_list|,
name|struct
name|xz_buf
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free the memory allocated for the LZMA2 decoder. */
end_comment

begin_function_decl
name|XZ_EXTERN
name|void
name|xz_dec_lzma2_end
parameter_list|(
name|struct
name|xz_dec_lzma2
modifier|*
name|s
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|XZ_DEC_BCJ
end_ifdef

begin_comment
comment|/*  * Allocate memory for BCJ decoders. xz_dec_bcj_reset() must be used before  * calling xz_dec_bcj_run().  */
end_comment

begin_function_decl
name|XZ_EXTERN
name|struct
name|xz_dec_bcj
modifier|*
name|xz_dec_bcj_create
parameter_list|(
name|bool
name|single_call
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Decode the Filter ID of a BCJ filter. This implementation doesn't  * support custom start offsets, so no decoding of Filter Properties  * is needed. Returns XZ_OK if the given Filter ID is supported.  * Otherwise XZ_OPTIONS_ERROR is returned.  */
end_comment

begin_function_decl
name|XZ_EXTERN
name|enum
name|xz_ret
name|xz_dec_bcj_reset
parameter_list|(
name|struct
name|xz_dec_bcj
modifier|*
name|s
parameter_list|,
name|uint8_t
name|id
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Decode raw BCJ + LZMA2 stream. This must be used only if there actually is  * a BCJ filter in the chain. If the chain has only LZMA2, xz_dec_lzma2_run()  * must be called directly.  */
end_comment

begin_function_decl
name|XZ_EXTERN
name|enum
name|xz_ret
name|xz_dec_bcj_run
parameter_list|(
name|struct
name|xz_dec_bcj
modifier|*
name|s
parameter_list|,
name|struct
name|xz_dec_lzma2
modifier|*
name|lzma2
parameter_list|,
name|struct
name|xz_buf
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Free the memory allocated for the BCJ filters. */
end_comment

begin_define
define|#
directive|define
name|xz_dec_bcj_end
parameter_list|(
name|s
parameter_list|)
value|kfree(s)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

