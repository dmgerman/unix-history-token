begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2007-2014 QLogic Corporation. All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS'  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/cdefs.h>
end_include

begin_expr_stmt
name|__FBSDID
argument_list|(
literal|"$FreeBSD$"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_ifndef
ifndef|#
directive|ifndef
name|ECORE_SP_H
end_ifndef

begin_define
define|#
directive|define
name|ECORE_SP_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/lock.h>
end_include

begin_include
include|#
directive|include
file|<sys/mutex.h>
end_include

begin_include
include|#
directive|include
file|<sys/malloc.h>
end_include

begin_include
include|#
directive|include
file|<sys/kernel.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_if
if|#
directive|if
name|_BYTE_ORDER
operator|==
name|_LITTLE_ENDIAN
end_if

begin_ifndef
ifndef|#
directive|ifndef
name|LITTLE_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__LITTLE_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|__LITTLE_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|BIG_ENDIAN
end_undef

begin_undef
undef|#
directive|undef
name|__BIG_ENDIAN
end_undef

begin_else
else|#
directive|else
end_else

begin_comment
comment|/* _BIG_ENDIAN */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|__BIG_ENDIAN
end_ifndef

begin_define
define|#
directive|define
name|__BIG_ENDIAN
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_undef
undef|#
directive|undef
name|LITTLE_ENDIAN
end_undef

begin_undef
undef|#
directive|undef
name|__LITTLE_ENDIAN
end_undef

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|"ecore_mfw_req.h"
end_include

begin_include
include|#
directive|include
file|"ecore_fw_defs.h"
end_include

begin_include
include|#
directive|include
file|"ecore_hsi.h"
end_include

begin_include
include|#
directive|include
file|"ecore_reg.h"
end_include

begin_struct_decl
struct_decl|struct
name|bxe_softc
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|bus_addr_t
name|ecore_dma_addr_t
typedef|;
end_typedef

begin_comment
comment|/* expected to be 64 bit wide */
end_comment

begin_typedef
typedef|typedef
specifier|volatile
name|int
name|ecore_atomic_t
typedef|;
end_typedef

begin_ifndef
ifndef|#
directive|ifndef
name|__bool_true_false_are_defined
end_ifndef

begin_ifndef
ifndef|#
directive|ifndef
name|__cplusplus
end_ifndef

begin_define
define|#
directive|define
name|bool
value|_Bool
end_define

begin_if
if|#
directive|if
name|__STDC_VERSION__
operator|<
literal|199901L
operator|&&
name|__GNUC__
operator|<
literal|3
operator|&&
operator|!
name|defined
argument_list|(
name|__INTEL_COMPILER
argument_list|)
end_if

begin_typedef
typedef|typedef
name|_Bool
name|bool
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__cplusplus */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !__bool_true_false_are_defined$ */
end_comment

begin_define
define|#
directive|define
name|ETH_ALEN
value|ETHER_ADDR_LEN
end_define

begin_comment
comment|/* 6 */
end_comment

begin_define
define|#
directive|define
name|ECORE_SWCID_SHIFT
value|17
end_define

begin_define
define|#
directive|define
name|ECORE_SWCID_MASK
value|((0x1<< ECORE_SWCID_SHIFT) - 1)
end_define

begin_define
define|#
directive|define
name|ECORE_MC_HASH_SIZE
value|8
end_define

begin_define
define|#
directive|define
name|ECORE_MC_HASH_OFFSET
parameter_list|(
name|sc
parameter_list|,
name|i
parameter_list|)
define|\
value|(BAR_TSTRORM_INTMEM +                                                    \      TSTORM_APPROXIMATE_MATCH_MULTICAST_FILTERING_OFFSET(FUNC_ID(sc)) + i*4)
end_define

begin_define
define|#
directive|define
name|ECORE_MAX_MULTICAST
value|64
end_define

begin_define
define|#
directive|define
name|ECORE_MAX_EMUL_MULTI
value|1
end_define

begin_define
define|#
directive|define
name|IRO
value|sc->iro_array
end_define

begin_typedef
typedef|typedef
name|struct
name|mtx
name|ECORE_MUTEX
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ECORE_MUTEX_INIT
parameter_list|(
name|_mutex
parameter_list|)
define|\
value|mtx_init(_mutex, "ecore_lock", "ECORE Lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|ECORE_MUTEX_LOCK
parameter_list|(
name|_mutex
parameter_list|)
value|mtx_lock(_mutex)
end_define

begin_define
define|#
directive|define
name|ECORE_MUTEX_UNLOCK
parameter_list|(
name|_mutex
parameter_list|)
value|mtx_unlock(_mutex)
end_define

begin_typedef
typedef|typedef
name|struct
name|mtx
name|ECORE_MUTEX_SPIN
typedef|;
end_typedef

begin_define
define|#
directive|define
name|ECORE_SPIN_LOCK_INIT
parameter_list|(
name|_spin
parameter_list|,
name|_sc
parameter_list|)
define|\
value|mtx_init(_spin, "ecore_lock", "ECORE Lock", MTX_DEF)
end_define

begin_define
define|#
directive|define
name|ECORE_SPIN_LOCK_BH
parameter_list|(
name|_spin
parameter_list|)
value|mtx_lock(_spin)
end_define

begin_comment
comment|/* bh = bottom-half */
end_comment

begin_define
define|#
directive|define
name|ECORE_SPIN_UNLOCK_BH
parameter_list|(
name|_spin
parameter_list|)
value|mtx_unlock(_spin)
end_define

begin_comment
comment|/* bh = bottom-half */
end_comment

begin_define
define|#
directive|define
name|ECORE_SMP_MB_AFTER_CLEAR_BIT
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|ECORE_SMP_MB_BEFORE_CLEAR_BIT
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|ECORE_SMP_MB
parameter_list|()
value|mb()
end_define

begin_define
define|#
directive|define
name|ECORE_SMP_RMB
parameter_list|()
value|rmb()
end_define

begin_define
define|#
directive|define
name|ECORE_SMP_WMB
parameter_list|()
value|wmb()
end_define

begin_define
define|#
directive|define
name|ECORE_MMIOWB
parameter_list|()
value|wmb()
end_define

begin_define
define|#
directive|define
name|ECORE_SET_BIT_NA
parameter_list|(
name|bit
parameter_list|,
name|var
parameter_list|)
value|bit_set(var, bit)
end_define

begin_comment
comment|/* non-atomic */
end_comment

begin_define
define|#
directive|define
name|ECORE_CLEAR_BIT_NA
parameter_list|(
name|bit
parameter_list|,
name|var
parameter_list|)
value|bit_clear(var, bit)
end_define

begin_comment
comment|/* non-atomic */
end_comment

begin_define
define|#
directive|define
name|ECORE_TEST_BIT
parameter_list|(
name|bit
parameter_list|,
name|var
parameter_list|)
value|bxe_test_bit(bit, var)
end_define

begin_define
define|#
directive|define
name|ECORE_SET_BIT
parameter_list|(
name|bit
parameter_list|,
name|var
parameter_list|)
value|bxe_set_bit(bit, var)
end_define

begin_define
define|#
directive|define
name|ECORE_CLEAR_BIT
parameter_list|(
name|bit
parameter_list|,
name|var
parameter_list|)
value|bxe_clear_bit(bit, var)
end_define

begin_define
define|#
directive|define
name|ECORE_TEST_AND_CLEAR_BIT
parameter_list|(
name|bit
parameter_list|,
name|var
parameter_list|)
value|bxe_test_and_clear_bit(bit, var)
end_define

begin_define
define|#
directive|define
name|ECORE_ATOMIC_READ
parameter_list|(
name|a
parameter_list|)
value|atomic_load_acq_int((volatile int *)a)
end_define

begin_define
define|#
directive|define
name|ECORE_ATOMIC_SET
parameter_list|(
name|a
parameter_list|,
name|v
parameter_list|)
value|atomic_store_rel_int((volatile int *)a, v)
end_define

begin_define
define|#
directive|define
name|ECORE_ATOMIC_CMPXCHG
parameter_list|(
name|a
parameter_list|,
name|o
parameter_list|,
name|n
parameter_list|)
value|bxe_cmpxchg((volatile int *)a, o, n)
end_define

begin_define
define|#
directive|define
name|ECORE_RET_PENDING
parameter_list|(
name|pending_bit
parameter_list|,
name|pending
parameter_list|)
define|\
value|(ECORE_TEST_BIT(pending_bit, pending) ? ECORE_PENDING : ECORE_SUCCESS)
end_define

begin_define
define|#
directive|define
name|ECORE_SET_FLAG
parameter_list|(
name|value
parameter_list|,
name|mask
parameter_list|,
name|flag
parameter_list|)
define|\
value|do {                                       \         (value)&= ~(mask);                    \         (value) |= ((flag)<< (mask##_SHIFT)); \     } while (0)
end_define

begin_define
define|#
directive|define
name|ECORE_GET_FLAG
parameter_list|(
name|value
parameter_list|,
name|mask
parameter_list|)
define|\
value|(((value)&= (mask))>> (mask##_SHIFT))
end_define

begin_define
define|#
directive|define
name|ECORE_MIGHT_SLEEP
parameter_list|()
end_define

begin_define
define|#
directive|define
name|ECORE_FCOE_CID
parameter_list|(
name|sc
parameter_list|)
value|((sc)->fp[FCOE_IDX(sc)].cl_id)
end_define

begin_define
define|#
directive|define
name|ECORE_MEMCMP
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_s
parameter_list|)
value|memcmp(_a, _b, _s)
end_define

begin_define
define|#
directive|define
name|ECORE_MEMCPY
parameter_list|(
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_s
parameter_list|)
value|memcpy(_a, _b, _s)
end_define

begin_define
define|#
directive|define
name|ECORE_MEMSET
parameter_list|(
name|_a
parameter_list|,
name|_c
parameter_list|,
name|_s
parameter_list|)
value|memset(_a, _c, _s)
end_define

begin_define
define|#
directive|define
name|ECORE_CPU_TO_LE16
parameter_list|(
name|x
parameter_list|)
value|htole16(x)
end_define

begin_define
define|#
directive|define
name|ECORE_CPU_TO_LE32
parameter_list|(
name|x
parameter_list|)
value|htole32(x)
end_define

begin_define
define|#
directive|define
name|ECORE_WAIT
parameter_list|(
name|_s
parameter_list|,
name|_t
parameter_list|)
value|DELAY(1000)
end_define

begin_define
define|#
directive|define
name|ECORE_MSLEEP
parameter_list|(
name|_t
parameter_list|)
value|DELAY((_t) * 1000)
end_define

begin_define
define|#
directive|define
name|ECORE_LIKELY
parameter_list|(
name|x
parameter_list|)
value|__predict_true(x)
end_define

begin_define
define|#
directive|define
name|ECORE_UNLIKELY
parameter_list|(
name|x
parameter_list|)
value|__predict_false(x)
end_define

begin_define
define|#
directive|define
name|ECORE_ZALLOC
parameter_list|(
name|_size
parameter_list|,
name|_flags
parameter_list|,
name|_sc
parameter_list|)
define|\
value|malloc(_size, M_TEMP, (M_NOWAIT | M_ZERO))
end_define

begin_define
define|#
directive|define
name|ECORE_CALLOC
parameter_list|(
name|_len
parameter_list|,
name|_size
parameter_list|,
name|_flags
parameter_list|,
name|_sc
parameter_list|)
define|\
value|malloc(_len * _size, M_TEMP, (M_NOWAIT | M_ZERO))
end_define

begin_define
define|#
directive|define
name|ECORE_FREE
parameter_list|(
name|_s
parameter_list|,
name|_buf
parameter_list|,
name|_size
parameter_list|)
value|free(_buf, M_TEMP)
end_define

begin_define
define|#
directive|define
name|SC_ILT
parameter_list|(
name|sc
parameter_list|)
value|((sc)->ilt)
end_define

begin_define
define|#
directive|define
name|ILOG2
parameter_list|(
name|x
parameter_list|)
value|bxe_ilog2(x)
end_define

begin_define
define|#
directive|define
name|ECORE_ILT_ZALLOC
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|size
parameter_list|)
define|\
value|do {                                                                   \         x = malloc(sizeof(struct bxe_dma), M_DEVBUF, (M_NOWAIT | M_ZERO)); \         if (x) {                                                           \             if (bxe_dma_alloc((struct bxe_softc *)sc,                      \                               size, (struct bxe_dma *)x,                   \                               "ECORE_ILT") != 0) {                         \                 free(x, M_DEVBUF);                                         \                 x = NULL;                                                  \                 *y = 0;                                                    \             } else {                                                       \                 *y = ((struct bxe_dma *)x)->paddr;                         \             }                                                              \         }                                                                  \     } while (0)
end_define

begin_define
define|#
directive|define
name|ECORE_ILT_FREE
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|,
name|size
parameter_list|)
define|\
value|do {                                             \         if (x) {                                     \             bxe_dma_free((struct bxe_softc *)sc, x); \             free(x, M_DEVBUF);                       \             x = NULL;                                \             y = 0;                                   \         }                                            \     } while (0)
end_define

begin_define
define|#
directive|define
name|ECORE_IS_VALID_ETHER_ADDR
parameter_list|(
name|_mac
parameter_list|)
value|TRUE
end_define

begin_define
define|#
directive|define
name|ECORE_IS_MF_SD_MODE
value|IS_MF_SD_MODE
end_define

begin_define
define|#
directive|define
name|ECORE_IS_MF_SI_MODE
value|IS_MF_SI_MODE
end_define

begin_define
define|#
directive|define
name|ECORE_IS_MF_AFEX_MODE
value|IS_MF_AFEX_MODE
end_define

begin_define
define|#
directive|define
name|ECORE_SET_CTX_VALIDATION
value|bxe_set_ctx_validation
end_define

begin_define
define|#
directive|define
name|ECORE_UPDATE_COALESCE_SB_INDEX
value|bxe_update_coalesce_sb_index
end_define

begin_define
define|#
directive|define
name|ECORE_ALIGN
parameter_list|(
name|x
parameter_list|,
name|a
parameter_list|)
value|((((x) + (a) - 1) / (a)) * (a))
end_define

begin_define
define|#
directive|define
name|ECORE_REG_WR_DMAE_LEN
value|REG_WR_DMAE_LEN
end_define

begin_define
define|#
directive|define
name|ECORE_PATH_ID
value|SC_PATH
end_define

begin_define
define|#
directive|define
name|ECORE_PORT_ID
value|SC_PORT
end_define

begin_define
define|#
directive|define
name|ECORE_FUNC_ID
value|SC_FUNC
end_define

begin_define
define|#
directive|define
name|ECORE_ABS_FUNC_ID
value|SC_ABS_FUNC
end_define

begin_function_decl
name|uint32_t
name|calc_crc32
parameter_list|(
name|uint8_t
modifier|*
name|crc32_packet
parameter_list|,
name|uint32_t
name|crc32_length
parameter_list|,
name|uint32_t
name|crc32_seed
parameter_list|,
name|uint8_t
name|complement
parameter_list|)
function_decl|;
end_function_decl

begin_function
specifier|static
specifier|inline
name|uint32_t
name|ECORE_CRC32_LE
parameter_list|(
name|uint32_t
name|seed
parameter_list|,
name|uint8_t
modifier|*
name|mac
parameter_list|,
name|uint32_t
name|len
parameter_list|)
block|{
name|uint32_t
name|packet_buf
index|[
literal|2
index|]
init|=
block|{
literal|0
block|}
decl_stmt|;
name|memcpy
argument_list|(
operator|(
operator|(
name|uint8_t
operator|*
operator|)
operator|(
operator|&
name|packet_buf
index|[
literal|0
index|]
operator|)
operator|)
operator|+
literal|2
argument_list|,
operator|&
name|mac
index|[
literal|0
index|]
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|memcpy
argument_list|(
operator|&
name|packet_buf
index|[
literal|1
index|]
argument_list|,
operator|&
name|mac
index|[
literal|2
index|]
argument_list|,
literal|4
argument_list|)
expr_stmt|;
return|return
name|bswap32
argument_list|(
name|calc_crc32
argument_list|(
operator|(
name|uint8_t
operator|*
operator|)
name|packet_buf
argument_list|,
literal|8
argument_list|,
name|seed
argument_list|,
literal|0
argument_list|)
argument_list|)
return|;
block|}
end_function

begin_define
define|#
directive|define
name|ecore_sp_post
parameter_list|(
name|_sc
parameter_list|,
name|_a
parameter_list|,
name|_b
parameter_list|,
name|_c
parameter_list|,
name|_d
parameter_list|)
define|\
value|bxe_sp_post(_sc, _a, _b, U64_HI(_c), U64_LO(_c), _d)
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|ECORE_STOP_ON_ERROR
end_ifdef

begin_define
define|#
directive|define
name|ECORE_DBG_BREAK_IF
parameter_list|(
name|exp
parameter_list|)
define|\
value|do {                            \         if (__predict_false(exp)) { \             panic("ECORE");         \         }                           \     } while (0)
end_define

begin_define
define|#
directive|define
name|ECORE_BUG
parameter_list|()
define|\
value|do {                                          \         panic("BUG (%s:%d)", __FILE__, __LINE__); \     } while(0);
end_define

begin_define
define|#
directive|define
name|ECORE_BUG_ON
parameter_list|(
name|exp
parameter_list|)
define|\
value|do {                                                 \         if (__predict_true(exp)) {                       \             panic("BUG_ON (%s:%d)", __FILE__, __LINE__); \         }                                                \     } while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_decl_stmt
specifier|extern
name|unsigned
name|long
name|bxe_debug
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|BXE_DEBUG_ECORE_DBG_BREAK_IF
value|0x01
end_define

begin_define
define|#
directive|define
name|BXE_DEBUG_ECORE_BUG
value|0x02
end_define

begin_define
define|#
directive|define
name|BXE_DEBUG_ECORE_BUG_ON
value|0x04
end_define

begin_define
define|#
directive|define
name|ECORE_DBG_BREAK_IF
parameter_list|(
name|exp
parameter_list|)
define|\
value|if (bxe_debug& BXE_DEBUG_ECORE_DBG_BREAK_IF) \         printf("%s (%s,%d)\n", __FUNCTION__, __FILE__, __LINE__);
end_define

begin_define
define|#
directive|define
name|ECORE_BUG
parameter_list|(
name|exp
parameter_list|)
define|\
value|if (bxe_debug& BXE_DEBUG_ECORE_BUG) \         printf("%s (%s,%d)\n", __FUNCTION__, __FILE__, __LINE__);
end_define

begin_define
define|#
directive|define
name|ECORE_BUG_ON
parameter_list|(
name|exp
parameter_list|)
define|\
value|if (bxe_debug& BXE_DEBUG_ECORE_BUG_ON) \         printf("%s (%s,%d)\n", __FUNCTION__, __FILE__, __LINE__);
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifdef ECORE_STOP_ON_ERROR */
end_comment

begin_define
define|#
directive|define
name|ECORE_ERR
parameter_list|(
name|str
parameter_list|,
modifier|...
parameter_list|)
define|\
value|BLOGE(sc, "ECORE: " str, ##__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|DBG_SP
value|0x00000004
end_define

begin_comment
comment|/* defined in bxe.h */
end_comment

begin_define
define|#
directive|define
name|ECORE_MSG
parameter_list|(
name|sc
parameter_list|,
name|m
parameter_list|,
modifier|...
parameter_list|)
define|\
value|BLOGD(sc, DBG_SP, "ECORE: " m, ##__VA_ARGS__)
end_define

begin_typedef
typedef|typedef
struct|struct
name|_ecore_list_entry_t
block|{
name|struct
name|_ecore_list_entry_t
modifier|*
name|next
decl_stmt|,
modifier|*
name|prev
decl_stmt|;
block|}
name|ecore_list_entry_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|ecore_list_t
block|{
name|ecore_list_entry_t
modifier|*
name|head
decl_stmt|,
modifier|*
name|tail
decl_stmt|;
name|unsigned
name|long
name|cnt
decl_stmt|;
block|}
name|ecore_list_t
typedef|;
end_typedef

begin_comment
comment|/* initialize the list */
end_comment

begin_define
define|#
directive|define
name|ECORE_LIST_INIT
parameter_list|(
name|_list
parameter_list|)
define|\
value|do {                       \         (_list)->head = NULL;  \         (_list)->tail = NULL;  \         (_list)->cnt  = 0;     \     } while (0)
end_define

begin_comment
comment|/* return TRUE if the element is the last on the list */
end_comment

begin_define
define|#
directive|define
name|ECORE_LIST_IS_LAST
parameter_list|(
name|_elem
parameter_list|,
name|_list
parameter_list|)
define|\
value|(_elem == (_list)->tail)
end_define

begin_comment
comment|/* return TRUE if the list is empty */
end_comment

begin_define
define|#
directive|define
name|ECORE_LIST_IS_EMPTY
parameter_list|(
name|_list
parameter_list|)
define|\
value|((_list)->cnt == 0)
end_define

begin_comment
comment|/* return the first element */
end_comment

begin_define
define|#
directive|define
name|ECORE_LIST_FIRST_ENTRY
parameter_list|(
name|_list
parameter_list|,
name|cast
parameter_list|,
name|_link
parameter_list|)
define|\
value|(cast *)((_list)->head)
end_define

begin_comment
comment|/* return the next element */
end_comment

begin_define
define|#
directive|define
name|ECORE_LIST_NEXT
parameter_list|(
name|_elem
parameter_list|,
name|_link
parameter_list|,
name|cast
parameter_list|)
define|\
value|(cast *)((&((_elem)->_link))->next)
end_define

begin_comment
comment|/* push an element on the head of the list */
end_comment

begin_define
define|#
directive|define
name|ECORE_LIST_PUSH_HEAD
parameter_list|(
name|_elem
parameter_list|,
name|_list
parameter_list|)
define|\
value|do {                                                \         (_elem)->prev = (ecore_list_entry_t *)0;        \         (_elem)->next = (_list)->head;                  \         if ((_list)->tail == (ecore_list_entry_t *)0) { \             (_list)->tail = (_elem);                    \         } else {                                        \             (_list)->head->prev = (_elem);              \         }                                               \         (_list)->head = (_elem);                        \         (_list)->cnt++;                                 \     } while (0)
end_define

begin_comment
comment|/* push an element on the tail of the list */
end_comment

begin_define
define|#
directive|define
name|ECORE_LIST_PUSH_TAIL
parameter_list|(
name|_elem
parameter_list|,
name|_list
parameter_list|)
define|\
value|do {                                         \         (_elem)->next = (ecore_list_entry_t *)0; \         (_elem)->prev = (_list)->tail;           \         if ((_list)->tail) {                     \             (_list)->tail->next = (_elem);       \         } else {                                 \             (_list)->head = (_elem);             \         }                                        \         (_list)->tail = (_elem);                 \         (_list)->cnt++;                          \     } while (0)
end_define

begin_comment
comment|/* push list1 on the head of list2 and return with list1 as empty */
end_comment

begin_define
define|#
directive|define
name|ECORE_LIST_SPLICE_INIT
parameter_list|(
name|_list1
parameter_list|,
name|_list2
parameter_list|)
define|\
value|do {                                           \         (_list1)->tail->next = (_list2)->head;     \         if ((_list2)->head) {                      \             (_list2)->head->prev = (_list1)->tail; \         } else {                                   \             (_list2)->tail = (_list1)->tail;       \         }                                          \         (_list2)->head = (_list1)->head;           \         (_list2)->cnt += (_list1)->cnt;            \         (_list1)->head = NULL;                     \         (_list1)->tail = NULL;                     \         (_list1)->cnt  = 0;                        \     } while (0)
end_define

begin_comment
comment|/* remove an element from the list */
end_comment

begin_define
define|#
directive|define
name|ECORE_LIST_REMOVE_ENTRY
parameter_list|(
name|_elem
parameter_list|,
name|_list
parameter_list|)
define|\
value|do {                                                           \         if ((_list)->head == (_elem)) {                            \             if ((_list)->head) {                                   \                 (_list)->head = (_list)->head->next;               \                 if ((_list)->head) {                               \                     (_list)->head->prev = (ecore_list_entry_t *)0; \                 } else {                                           \                     (_list)->tail = (ecore_list_entry_t *)0;       \                 }                                                  \                 (_list)->cnt--;                                    \             }                                                      \         } else if ((_list)->tail == (_elem)) {                     \             if ((_list)->tail) {                                   \                 (_list)->tail = (_list)->tail->prev;               \                 if ((_list)->tail) {                               \                     (_list)->tail->next = (ecore_list_entry_t *)0; \                 } else {                                           \                     (_list)->head = (ecore_list_entry_t *)0;       \                 }                                                  \                 (_list)->cnt--;                                    \             }                                                      \         } else {                                                   \             (_elem)->prev->next = (_elem)->next;                   \             (_elem)->next->prev = (_elem)->prev;                   \             (_list)->cnt--;                                        \         }                                                          \     } while (0)
end_define

begin_comment
comment|/* walk the list */
end_comment

begin_define
define|#
directive|define
name|ECORE_LIST_FOR_EACH_ENTRY
parameter_list|(
name|pos
parameter_list|,
name|_list
parameter_list|,
name|_link
parameter_list|,
name|cast
parameter_list|)
define|\
value|for (pos = ECORE_LIST_FIRST_ENTRY(_list, cast, _link); \          pos;                                              \          pos = ECORE_LIST_NEXT(pos, _link, cast))
end_define

begin_comment
comment|/* walk the list (safely) */
end_comment

begin_define
define|#
directive|define
name|ECORE_LIST_FOR_EACH_ENTRY_SAFE
parameter_list|(
name|pos
parameter_list|,
name|n
parameter_list|,
name|_list
parameter_list|,
name|_link
parameter_list|,
name|cast
parameter_list|)
define|\
value|for (pos = ECORE_LIST_FIRST_ENTRY(_list, cast, _lint),        \           n = (pos) ? ECORE_LIST_NEXT(pos, _link, cast) : NULL;    \           pos != NULL;                                             \           pos = (cast *)n,                                         \           n = (pos) ? ECORE_LIST_NEXT(pos, _link, cast) : NULL)
end_define

begin_comment
comment|/* Manipulate a bit vector defined as an array of uint64_t */
end_comment

begin_comment
comment|/* Number of bits in one sge_mask array element */
end_comment

begin_define
define|#
directive|define
name|BIT_VEC64_ELEM_SZ
value|64
end_define

begin_define
define|#
directive|define
name|BIT_VEC64_ELEM_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|BIT_VEC64_ELEM_MASK
value|((uint64_t)BIT_VEC64_ELEM_SZ - 1)
end_define

begin_define
define|#
directive|define
name|__BIT_VEC64_SET_BIT
parameter_list|(
name|el
parameter_list|,
name|bit
parameter_list|)
define|\
value|do {                                        \         el = ((el) | ((uint64_t)0x1<< (bit))); \     } while (0)
end_define

begin_define
define|#
directive|define
name|__BIT_VEC64_CLEAR_BIT
parameter_list|(
name|el
parameter_list|,
name|bit
parameter_list|)
define|\
value|do {                                           \         el = ((el)& (~((uint64_t)0x1<< (bit)))); \     } while (0)
end_define

begin_define
define|#
directive|define
name|BIT_VEC64_SET_BIT
parameter_list|(
name|vec64
parameter_list|,
name|idx
parameter_list|)
define|\
value|__BIT_VEC64_SET_BIT((vec64)[(idx)>> BIT_VEC64_ELEM_SHIFT], \                         (idx)& BIT_VEC64_ELEM_MASK)
end_define

begin_define
define|#
directive|define
name|BIT_VEC64_CLEAR_BIT
parameter_list|(
name|vec64
parameter_list|,
name|idx
parameter_list|)
define|\
value|__BIT_VEC64_CLEAR_BIT((vec64)[(idx)>> BIT_VEC64_ELEM_SHIFT], \                           (idx)& BIT_VEC64_ELEM_MASK)
end_define

begin_define
define|#
directive|define
name|BIT_VEC64_TEST_BIT
parameter_list|(
name|vec64
parameter_list|,
name|idx
parameter_list|)
define|\
value|(((vec64)[(idx)>> BIT_VEC64_ELEM_SHIFT]>> \       ((idx)& BIT_VEC64_ELEM_MASK))& 0x1)
end_define

begin_comment
comment|/*  * Creates a bitmask of all ones in less significant bits.  * idx - index of the most significant bit in the created mask  */
end_comment

begin_define
define|#
directive|define
name|BIT_VEC64_ONES_MASK
parameter_list|(
name|idx
parameter_list|)
define|\
value|(((uint64_t)0x1<< (((idx)& BIT_VEC64_ELEM_MASK) + 1)) - 1)
end_define

begin_define
define|#
directive|define
name|BIT_VEC64_ELEM_ONE_MASK
value|((uint64_t)(~0))
end_define

begin_comment
comment|/* fill in a MAC address the way the FW likes it */
end_comment

begin_function
specifier|static
specifier|inline
name|void
name|ecore_set_fw_mac_addr
parameter_list|(
name|uint16_t
modifier|*
name|fw_hi
parameter_list|,
name|uint16_t
modifier|*
name|fw_mid
parameter_list|,
name|uint16_t
modifier|*
name|fw_lo
parameter_list|,
name|uint8_t
modifier|*
name|mac
parameter_list|)
block|{
operator|(
operator|(
name|uint8_t
operator|*
operator|)
name|fw_hi
operator|)
index|[
literal|0
index|]
operator|=
name|mac
index|[
literal|1
index|]
expr_stmt|;
operator|(
operator|(
name|uint8_t
operator|*
operator|)
name|fw_hi
operator|)
index|[
literal|1
index|]
operator|=
name|mac
index|[
literal|0
index|]
expr_stmt|;
operator|(
operator|(
name|uint8_t
operator|*
operator|)
name|fw_mid
operator|)
index|[
literal|0
index|]
operator|=
name|mac
index|[
literal|3
index|]
expr_stmt|;
operator|(
operator|(
name|uint8_t
operator|*
operator|)
name|fw_mid
operator|)
index|[
literal|1
index|]
operator|=
name|mac
index|[
literal|2
index|]
expr_stmt|;
operator|(
operator|(
name|uint8_t
operator|*
operator|)
name|fw_lo
operator|)
index|[
literal|0
index|]
operator|=
name|mac
index|[
literal|5
index|]
expr_stmt|;
operator|(
operator|(
name|uint8_t
operator|*
operator|)
name|fw_lo
operator|)
index|[
literal|1
index|]
operator|=
name|mac
index|[
literal|4
index|]
expr_stmt|;
block|}
end_function

begin_enum
enum|enum
name|ecore_status_t
block|{
name|ECORE_EXISTS
init|=
operator|-
literal|6
block|,
name|ECORE_IO
init|=
operator|-
literal|5
block|,
name|ECORE_TIMEOUT
init|=
operator|-
literal|4
block|,
name|ECORE_INVAL
init|=
operator|-
literal|3
block|,
name|ECORE_BUSY
init|=
operator|-
literal|2
block|,
name|ECORE_NOMEM
init|=
operator|-
literal|1
block|,
name|ECORE_SUCCESS
init|=
literal|0
block|,
comment|/* PENDING is not an error and should be positive */
name|ECORE_PENDING
init|=
literal|1
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|SWITCH_UPDATE
block|,
name|AFEX_UPDATE
block|, }
enum|;
end_enum

begin_struct_decl
struct_decl|struct
name|bxe_softc
struct_decl|;
end_struct_decl

begin_struct_decl
struct_decl|struct
name|eth_context
struct_decl|;
end_struct_decl

begin_comment
comment|/* Bits representing general command's configuration */
end_comment

begin_enum
enum|enum
block|{
name|RAMROD_TX
block|,
name|RAMROD_RX
block|,
comment|/* Wait until all pending commands complete */
name|RAMROD_COMP_WAIT
block|,
comment|/* Don't send a ramrod, only update a registry */
name|RAMROD_DRV_CLR_ONLY
block|,
comment|/* Configure HW according to the current object state */
name|RAMROD_RESTORE
block|,
comment|/* Execute the next command now */
name|RAMROD_EXEC
block|,
comment|/* Don't add a new command and continue execution of posponed 	 * commands. If not set a new command will be added to the 	 * pending commands list. 	 */
name|RAMROD_CONT
block|,
comment|/* If there is another pending ramrod, wait until it finishes and 	 * re-try to submit this one. This flag can be set only in sleepable 	 * context, and should not be set from the context that completes the 	 * ramrods as deadlock will occur. 	 */
name|RAMROD_RETRY
block|, }
enum|;
end_enum

begin_typedef
typedef|typedef
enum|enum
block|{
name|ECORE_OBJ_TYPE_RX
block|,
name|ECORE_OBJ_TYPE_TX
block|,
name|ECORE_OBJ_TYPE_RX_TX
block|, }
name|ecore_obj_type
typedef|;
end_typedef

begin_comment
comment|/* Public slow path states */
end_comment

begin_enum
enum|enum
block|{
name|ECORE_FILTER_MAC_PENDING
block|,
name|ECORE_FILTER_VLAN_PENDING
block|,
name|ECORE_FILTER_VLAN_MAC_PENDING
block|,
name|ECORE_FILTER_RX_MODE_PENDING
block|,
name|ECORE_FILTER_RX_MODE_SCHED
block|,
name|ECORE_FILTER_ISCSI_ETH_START_SCHED
block|,
name|ECORE_FILTER_ISCSI_ETH_STOP_SCHED
block|,
name|ECORE_FILTER_FCOE_ETH_START_SCHED
block|,
name|ECORE_FILTER_FCOE_ETH_STOP_SCHED
block|,
name|ECORE_FILTER_BYPASS_RX_MODE_PENDING
block|,
name|ECORE_FILTER_BYPASS_MAC_PENDING
block|,
name|ECORE_FILTER_BYPASS_RSS_CONF_PENDING
block|,
name|ECORE_FILTER_MCAST_PENDING
block|,
name|ECORE_FILTER_MCAST_SCHED
block|,
name|ECORE_FILTER_RSS_CONF_PENDING
block|,
name|ECORE_AFEX_FCOE_Q_UPDATE_PENDING
block|,
name|ECORE_AFEX_PENDING_VIFSET_MCP_ACK
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ecore_raw_obj
block|{
name|uint8_t
name|func_id
decl_stmt|;
comment|/* Queue params */
name|uint8_t
name|cl_id
decl_stmt|;
name|uint32_t
name|cid
decl_stmt|;
comment|/* Ramrod data buffer params */
name|void
modifier|*
name|rdata
decl_stmt|;
name|ecore_dma_addr_t
name|rdata_mapping
decl_stmt|;
comment|/* Ramrod state params */
name|int
name|state
decl_stmt|;
comment|/* "ramrod is pending" state bit */
name|unsigned
name|long
modifier|*
name|pstate
decl_stmt|;
comment|/* pointer to state buffer */
name|ecore_obj_type
name|obj_type
decl_stmt|;
name|int
function_decl|(
modifier|*
name|wait_comp
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_raw_obj
modifier|*
name|o
parameter_list|)
function_decl|;
name|bool
function_decl|(
modifier|*
name|check_pending
function_decl|)
parameter_list|(
name|struct
name|ecore_raw_obj
modifier|*
name|o
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|clear_pending
function_decl|)
parameter_list|(
name|struct
name|ecore_raw_obj
modifier|*
name|o
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_pending
function_decl|)
parameter_list|(
name|struct
name|ecore_raw_obj
modifier|*
name|o
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/************************* VLAN-MAC commands related parameters ***************/
end_comment

begin_struct
struct|struct
name|ecore_mac_ramrod_data
block|{
name|uint8_t
name|mac
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|uint8_t
name|is_inner_mac
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_vlan_ramrod_data
block|{
name|uint16_t
name|vlan
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_vlan_mac_ramrod_data
block|{
name|uint8_t
name|mac
index|[
name|ETH_ALEN
index|]
decl_stmt|;
name|uint8_t
name|is_inner_mac
decl_stmt|;
name|uint16_t
name|vlan
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|ecore_classification_ramrod_data
block|{
name|struct
name|ecore_mac_ramrod_data
name|mac
decl_stmt|;
name|struct
name|ecore_vlan_ramrod_data
name|vlan
decl_stmt|;
name|struct
name|ecore_vlan_mac_ramrod_data
name|vlan_mac
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/* VLAN_MAC commands */
end_comment

begin_enum
enum|enum
name|ecore_vlan_mac_cmd
block|{
name|ECORE_VLAN_MAC_ADD
block|,
name|ECORE_VLAN_MAC_DEL
block|,
name|ECORE_VLAN_MAC_MOVE
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ecore_vlan_mac_data
block|{
comment|/* Requested command: ECORE_VLAN_MAC_XX */
name|enum
name|ecore_vlan_mac_cmd
name|cmd
decl_stmt|;
comment|/* used to contain the data related vlan_mac_flags bits from 	 * ramrod parameters. 	 */
name|unsigned
name|long
name|vlan_mac_flags
decl_stmt|;
comment|/* Needed for MOVE command */
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|target_obj
decl_stmt|;
name|union
name|ecore_classification_ramrod_data
name|u
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************** Exe Queue obj ************************************/
end_comment

begin_union
union|union
name|ecore_exe_queue_cmd_data
block|{
name|struct
name|ecore_vlan_mac_data
name|vlan_mac
decl_stmt|;
struct|struct
block|{
comment|/* TODO */
block|}
name|mcast
struct|;
block|}
union|;
end_union

begin_struct
struct|struct
name|ecore_exeq_elem
block|{
name|ecore_list_entry_t
name|link
decl_stmt|;
comment|/* Length of this element in the exe_chunk. */
name|int
name|cmd_len
decl_stmt|;
name|union
name|ecore_exe_queue_cmd_data
name|cmd_data
decl_stmt|;
block|}
struct|;
end_struct

begin_union_decl
union_decl|union
name|ecore_qable_obj
union_decl|;
end_union_decl

begin_union
union|union
name|ecore_exeq_comp_elem
block|{
name|union
name|event_ring_elem
modifier|*
name|elem
decl_stmt|;
block|}
union|;
end_union

begin_struct_decl
struct_decl|struct
name|ecore_exe_queue_obj
struct_decl|;
end_struct_decl

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|exe_q_validate
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|union
name|ecore_qable_obj
modifier|*
name|o
parameter_list|,
name|struct
name|ecore_exeq_elem
modifier|*
name|elem
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|exe_q_remove
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|union
name|ecore_qable_obj
modifier|*
name|o
parameter_list|,
name|struct
name|ecore_exeq_elem
modifier|*
name|elem
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Return positive if entry was optimized, 0 - if not, negative  * in case of an error.  */
end_comment

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|exe_q_optimize
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|union
name|ecore_qable_obj
modifier|*
name|o
parameter_list|,
name|struct
name|ecore_exeq_elem
modifier|*
name|elem
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|int
function_decl|(
modifier|*
name|exe_q_execute
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|union
name|ecore_qable_obj
modifier|*
name|o
parameter_list|,
name|ecore_list_t
modifier|*
name|exe_chunk
parameter_list|,
name|unsigned
name|long
modifier|*
name|ramrod_flags
parameter_list|)
function_decl|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ecore_exeq_elem
modifier|*
function_decl|(
modifier|*
name|exe_q_get
function_decl|)
parameter_list|(
name|struct
name|ecore_exe_queue_obj
modifier|*
name|o
parameter_list|,
name|struct
name|ecore_exeq_elem
modifier|*
name|elem
parameter_list|)
function_decl|;
end_typedef

begin_struct
struct|struct
name|ecore_exe_queue_obj
block|{
comment|/* Commands pending for an execution. */
name|ecore_list_t
name|exe_queue
decl_stmt|;
comment|/* Commands pending for an completion. */
name|ecore_list_t
name|pending_comp
decl_stmt|;
name|ECORE_MUTEX_SPIN
name|lock
decl_stmt|;
comment|/* Maximum length of commands' list for one execution */
name|int
name|exe_chunk_len
decl_stmt|;
name|union
name|ecore_qable_obj
modifier|*
name|owner
decl_stmt|;
comment|/****** Virtual functions ******/
comment|/** 	 * Called before commands execution for commands that are really 	 * going to be executed (after 'optimize'). 	 * 	 * Must run under exe_queue->lock 	 */
name|exe_q_validate
name|validate
decl_stmt|;
comment|/** 	 * Called before removing pending commands, cleaning allocated 	 * resources (e.g., credits from validate) 	 */
name|exe_q_remove
name|remove
decl_stmt|;
comment|/** 	 * This will try to cancel the current pending commands list 	 * considering the new command. 	 * 	 * Returns the number of optimized commands or a negative error code 	 * 	 * Must run under exe_queue->lock 	 */
name|exe_q_optimize
name|optimize
decl_stmt|;
comment|/** 	 * Run the next commands chunk (owner specific). 	 */
name|exe_q_execute
name|execute
decl_stmt|;
comment|/** 	 * Return the exe_queue element containing the specific command 	 * if any. Otherwise return NULL. 	 */
name|exe_q_get
name|get
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/***************** Classification verbs: Set/Del MAC/VLAN/VLAN-MAC ************/
end_comment

begin_comment
comment|/*  * Element in the VLAN_MAC registry list having all current configured  * rules.  */
end_comment

begin_struct
struct|struct
name|ecore_vlan_mac_registry_elem
block|{
name|ecore_list_entry_t
name|link
decl_stmt|;
comment|/* Used to store the cam offset used for the mac/vlan/vlan-mac. 	 * Relevant for 57710 and 57711 only. VLANs and MACs share the 	 * same CAM for these chips. 	 */
name|int
name|cam_offset
decl_stmt|;
comment|/* Needed for DEL and RESTORE flows */
name|unsigned
name|long
name|vlan_mac_flags
decl_stmt|;
name|union
name|ecore_classification_ramrod_data
name|u
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* Bits representing VLAN_MAC commands specific flags */
end_comment

begin_enum
enum|enum
block|{
name|ECORE_UC_LIST_MAC
block|,
name|ECORE_ETH_MAC
block|,
name|ECORE_ISCSI_ETH_MAC
block|,
name|ECORE_NETQ_ETH_MAC
block|,
name|ECORE_DONT_CONSUME_CAM_CREDIT
block|,
name|ECORE_DONT_CONSUME_CAM_CREDIT_DEST
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ecore_vlan_mac_ramrod_params
block|{
comment|/* Object to run the command from */
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|vlan_mac_obj
decl_stmt|;
comment|/* General command flags: COMP_WAIT, etc. */
name|unsigned
name|long
name|ramrod_flags
decl_stmt|;
comment|/* Command specific configuration request */
name|struct
name|ecore_vlan_mac_data
name|user_req
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_vlan_mac_obj
block|{
name|struct
name|ecore_raw_obj
name|raw
decl_stmt|;
comment|/* Bookkeeping list: will prevent the addition of already existing 	 * entries. 	 */
name|ecore_list_t
name|head
decl_stmt|;
comment|/* Implement a simple reader/writer lock on the head list. 	 * all these fields should only be accessed under the exe_queue lock 	 */
name|uint8_t
name|head_reader
decl_stmt|;
comment|/* Num. of readers accessing head list */
name|bool
name|head_exe_request
decl_stmt|;
comment|/* Pending execution request. */
name|unsigned
name|long
name|saved_ramrod_flags
decl_stmt|;
comment|/* Ramrods of pending execution */
comment|/* Execution queue interface instance */
name|struct
name|ecore_exe_queue_obj
name|exe_queue
decl_stmt|;
comment|/* MACs credit pool */
name|struct
name|ecore_credit_pool_obj
modifier|*
name|macs_pool
decl_stmt|;
comment|/* VLANs credit pool */
name|struct
name|ecore_credit_pool_obj
modifier|*
name|vlans_pool
decl_stmt|;
comment|/* RAMROD command to be used */
name|int
name|ramrod_cmd
decl_stmt|;
comment|/* copy first n elements onto preallocated buffer 	 * 	 * @param n number of elements to get 	 * @param buf buffer preallocated by caller into which elements 	 *            will be copied. Note elements are 4-byte aligned 	 *            so buffer size must be able to accommodate the 	 *            aligned elements. 	 * 	 * @return number of copied bytes 	 */
name|int
function_decl|(
modifier|*
name|get_n_elements
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|o
parameter_list|,
name|int
name|n
parameter_list|,
name|uint8_t
modifier|*
name|base
parameter_list|,
name|uint8_t
name|stride
parameter_list|,
name|uint8_t
name|size
parameter_list|)
function_decl|;
comment|/** 	 * Checks if ADD-ramrod with the given params may be performed. 	 * 	 * @return zero if the element may be added 	 */
name|int
function_decl|(
modifier|*
name|check_add
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|o
parameter_list|,
name|union
name|ecore_classification_ramrod_data
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/** 	 * Checks if DEL-ramrod with the given params may be performed. 	 * 	 * @return TRUE if the element may be deleted 	 */
name|struct
name|ecore_vlan_mac_registry_elem
modifier|*
function_decl|(
modifier|*
name|check_del
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|o
parameter_list|,
name|union
name|ecore_classification_ramrod_data
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/** 	 * Checks if DEL-ramrod with the given params may be performed. 	 * 	 * @return TRUE if the element may be deleted 	 */
name|bool
function_decl|(
modifier|*
name|check_move
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|src_o
parameter_list|,
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|dst_o
parameter_list|,
name|union
name|ecore_classification_ramrod_data
modifier|*
name|data
parameter_list|)
function_decl|;
comment|/** 	 *  Update the relevant credit object(s) (consume/return 	 *  correspondingly). 	 */
name|bool
function_decl|(
modifier|*
name|get_credit
function_decl|)
parameter_list|(
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|o
parameter_list|)
function_decl|;
name|bool
function_decl|(
modifier|*
name|put_credit
function_decl|)
parameter_list|(
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|o
parameter_list|)
function_decl|;
name|bool
function_decl|(
modifier|*
name|get_cam_offset
function_decl|)
parameter_list|(
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|o
parameter_list|,
name|int
modifier|*
name|offset
parameter_list|)
function_decl|;
name|bool
function_decl|(
modifier|*
name|put_cam_offset
function_decl|)
parameter_list|(
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|o
parameter_list|,
name|int
name|offset
parameter_list|)
function_decl|;
comment|/** 	 * Configures one rule in the ramrod data buffer. 	 */
name|void
function_decl|(
modifier|*
name|set_one_rule
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|o
parameter_list|,
name|struct
name|ecore_exeq_elem
modifier|*
name|elem
parameter_list|,
name|int
name|rule_idx
parameter_list|,
name|int
name|cam_offset
parameter_list|)
function_decl|;
comment|/** 	*  Delete all configured elements having the given 	*  vlan_mac_flags specification. Assumes no pending for 	*  execution commands. Will schedule all all currently 	*  configured MACs/VLANs/VLAN-MACs matching the vlan_mac_flags 	*  specification for deletion and will use the given 	*  ramrod_flags for the last DEL operation. 	 * 	 * @param sc 	 * @param o 	 * @param ramrod_flags RAMROD_XX flags 	 * 	 * @return 0 if the last operation has completed successfully 	 *         and there are no more elements left, positive value 	 *         if there are pending for completion commands, 	 *         negative value in case of failure. 	 */
name|int
function_decl|(
modifier|*
name|delete_all
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|o
parameter_list|,
name|unsigned
name|long
modifier|*
name|vlan_mac_flags
parameter_list|,
name|unsigned
name|long
modifier|*
name|ramrod_flags
parameter_list|)
function_decl|;
comment|/** 	 * Reconfigures the next MAC/VLAN/VLAN-MAC element from the previously 	 * configured elements list. 	 * 	 * @param sc 	 * @param p Command parameters (RAMROD_COMP_WAIT bit in 	 *          ramrod_flags is only taken into an account) 	 * @param ppos a pointer to the cookie that should be given back in the 	 *        next call to make function handle the next element. If 	 *        *ppos is set to NULL it will restart the iterator. 	 *        If returned *ppos == NULL this means that the last 	 *        element has been handled. 	 * 	 * @return int 	 */
name|int
function_decl|(
modifier|*
name|restore
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_vlan_mac_ramrod_params
modifier|*
name|p
parameter_list|,
name|struct
name|ecore_vlan_mac_registry_elem
modifier|*
modifier|*
name|ppos
parameter_list|)
function_decl|;
comment|/** 	 * Should be called on a completion arrival. 	 * 	 * @param sc 	 * @param o 	 * @param cqe Completion element we are handling 	 * @param ramrod_flags if RAMROD_CONT is set the next bulk of 	 *		       pending commands will be executed. 	 *		       RAMROD_DRV_CLR_ONLY and RAMROD_RESTORE 	 *		       may also be set if needed. 	 * 	 * @return 0 if there are neither pending nor waiting for 	 *         completion commands. Positive value if there are 	 *         pending for execution or for completion commands. 	 *         Negative value in case of an error (including an 	 *         error in the cqe). 	 */
name|int
function_decl|(
modifier|*
name|complete
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|o
parameter_list|,
name|union
name|event_ring_elem
modifier|*
name|cqe
parameter_list|,
name|unsigned
name|long
modifier|*
name|ramrod_flags
parameter_list|)
function_decl|;
comment|/** 	 * Wait for completion of all commands. Don't schedule new ones, 	 * just wait. It assumes that the completion code will schedule 	 * for new commands. 	 */
name|int
function_decl|(
modifier|*
name|wait
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|o
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_enum
enum|enum
block|{
name|ECORE_LLH_CAM_ISCSI_ETH_LINE
init|=
literal|0
block|,
name|ECORE_LLH_CAM_ETH_LINE
block|,
name|ECORE_LLH_CAM_MAX_PF_LINE
init|=
name|NIG_REG_LLH1_FUNC_MEM_SIZE
operator|/
literal|2
block|}
enum|;
end_enum

begin_function_decl
name|void
name|ecore_set_mac_in_nig
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|bool
name|add
parameter_list|,
name|unsigned
name|char
modifier|*
name|dev_addr
parameter_list|,
name|int
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** RX_MODE verbs:DROP_ALL/ACCEPT_ALL/ACCEPT_ALL_MULTI/ACCEPT_ALL_VLAN/NORMAL */
end_comment

begin_comment
comment|/* RX_MODE ramrod special flags: set in rx_mode_flags field in  * a ecore_rx_mode_ramrod_params.  */
end_comment

begin_enum
enum|enum
block|{
name|ECORE_RX_MODE_FCOE_ETH
block|,
name|ECORE_RX_MODE_ISCSI_ETH
block|, }
enum|;
end_enum

begin_enum
enum|enum
block|{
name|ECORE_ACCEPT_UNICAST
block|,
name|ECORE_ACCEPT_MULTICAST
block|,
name|ECORE_ACCEPT_ALL_UNICAST
block|,
name|ECORE_ACCEPT_ALL_MULTICAST
block|,
name|ECORE_ACCEPT_BROADCAST
block|,
name|ECORE_ACCEPT_UNMATCHED
block|,
name|ECORE_ACCEPT_ANY_VLAN
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ecore_rx_mode_ramrod_params
block|{
name|struct
name|ecore_rx_mode_obj
modifier|*
name|rx_mode_obj
decl_stmt|;
name|unsigned
name|long
modifier|*
name|pstate
decl_stmt|;
name|int
name|state
decl_stmt|;
name|uint8_t
name|cl_id
decl_stmt|;
name|uint32_t
name|cid
decl_stmt|;
name|uint8_t
name|func_id
decl_stmt|;
name|unsigned
name|long
name|ramrod_flags
decl_stmt|;
name|unsigned
name|long
name|rx_mode_flags
decl_stmt|;
comment|/* rdata is either a pointer to eth_filter_rules_ramrod_data(e2) or to 	 * a tstorm_eth_mac_filter_config (e1x). 	 */
name|void
modifier|*
name|rdata
decl_stmt|;
name|ecore_dma_addr_t
name|rdata_mapping
decl_stmt|;
comment|/* Rx mode settings */
name|unsigned
name|long
name|rx_accept_flags
decl_stmt|;
comment|/* internal switching settings */
name|unsigned
name|long
name|tx_accept_flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_rx_mode_obj
block|{
name|int
function_decl|(
modifier|*
name|config_rx_mode
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_rx_mode_ramrod_params
modifier|*
name|p
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|wait_comp
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_rx_mode_ramrod_params
modifier|*
name|p
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/********************** Set multicast group ***********************************/
end_comment

begin_struct
struct|struct
name|ecore_mcast_list_elem
block|{
name|ecore_list_entry_t
name|link
decl_stmt|;
name|uint8_t
modifier|*
name|mac
decl_stmt|;
block|}
struct|;
end_struct

begin_union
union|union
name|ecore_mcast_config_data
block|{
name|uint8_t
modifier|*
name|mac
decl_stmt|;
name|uint8_t
name|bin
decl_stmt|;
comment|/* used in a RESTORE flow */
block|}
union|;
end_union

begin_struct
struct|struct
name|ecore_mcast_ramrod_params
block|{
name|struct
name|ecore_mcast_obj
modifier|*
name|mcast_obj
decl_stmt|;
comment|/* Relevant options are RAMROD_COMP_WAIT and RAMROD_DRV_CLR_ONLY */
name|unsigned
name|long
name|ramrod_flags
decl_stmt|;
name|ecore_list_t
name|mcast_list
decl_stmt|;
comment|/* list of struct ecore_mcast_list_elem */
comment|/** TODO: 	 *      - rename it to macs_num. 	 *      - Add a new command type for handling pending commands 	 *        (remove "zero semantics"). 	 * 	 *  Length of mcast_list. If zero and ADD_CONT command - post 	 *  pending commands. 	 */
name|int
name|mcast_list_len
decl_stmt|;
block|}
struct|;
end_struct

begin_enum
enum|enum
name|ecore_mcast_cmd
block|{
name|ECORE_MCAST_CMD_ADD
block|,
name|ECORE_MCAST_CMD_CONT
block|,
name|ECORE_MCAST_CMD_DEL
block|,
name|ECORE_MCAST_CMD_RESTORE
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ecore_mcast_obj
block|{
name|struct
name|ecore_raw_obj
name|raw
decl_stmt|;
union|union
block|{
struct|struct
block|{
define|#
directive|define
name|ECORE_MCAST_BINS_NUM
value|256
define|#
directive|define
name|ECORE_MCAST_VEC_SZ
value|(ECORE_MCAST_BINS_NUM / 64)
name|uint64_t
name|vec
index|[
name|ECORE_MCAST_VEC_SZ
index|]
decl_stmt|;
comment|/** Number of BINs to clear. Should be updated 			 *  immediately when a command arrives in order to 			 *  properly create DEL commands. 			 */
name|int
name|num_bins_set
decl_stmt|;
block|}
name|aprox_match
struct|;
struct|struct
block|{
name|ecore_list_t
name|macs
decl_stmt|;
name|int
name|num_macs_set
decl_stmt|;
block|}
name|exact_match
struct|;
block|}
name|registry
union|;
comment|/* Pending commands */
name|ecore_list_t
name|pending_cmds_head
decl_stmt|;
comment|/* A state that is set in raw.pstate, when there are pending commands */
name|int
name|sched_state
decl_stmt|;
comment|/* Maximal number of mcast MACs configured in one command */
name|int
name|max_cmd_len
decl_stmt|;
comment|/* Total number of currently pending MACs to configure: both 	 * in the pending commands list and in the current command. 	 */
name|int
name|total_pending_num
decl_stmt|;
name|uint8_t
name|engine_id
decl_stmt|;
comment|/** 	 * @param cmd command to execute (ECORE_MCAST_CMD_X, see above) 	 */
name|int
function_decl|(
modifier|*
name|config_mcast
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_mcast_ramrod_params
modifier|*
name|p
parameter_list|,
name|enum
name|ecore_mcast_cmd
name|cmd
parameter_list|)
function_decl|;
comment|/** 	 * Fills the ramrod data during the RESTORE flow. 	 * 	 * @param sc 	 * @param o 	 * @param start_idx Registry index to start from 	 * @param rdata_idx Index in the ramrod data to start from 	 * 	 * @return -1 if we handled the whole registry or index of the last 	 *         handled registry element. 	 */
name|int
function_decl|(
modifier|*
name|hdl_restore
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_mcast_obj
modifier|*
name|o
parameter_list|,
name|int
name|start_bin
parameter_list|,
name|int
modifier|*
name|rdata_idx
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|enqueue_cmd
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_mcast_obj
modifier|*
name|o
parameter_list|,
name|struct
name|ecore_mcast_ramrod_params
modifier|*
name|p
parameter_list|,
name|enum
name|ecore_mcast_cmd
name|cmd
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_one_rule
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_mcast_obj
modifier|*
name|o
parameter_list|,
name|int
name|idx
parameter_list|,
name|union
name|ecore_mcast_config_data
modifier|*
name|cfg_data
parameter_list|,
name|enum
name|ecore_mcast_cmd
name|cmd
parameter_list|)
function_decl|;
comment|/** Checks if there are more mcast MACs to be set or a previous 	 *  command is still pending. 	 */
name|bool
function_decl|(
modifier|*
name|check_pending
function_decl|)
parameter_list|(
name|struct
name|ecore_mcast_obj
modifier|*
name|o
parameter_list|)
function_decl|;
comment|/** 	 * Set/Clear/Check SCHEDULED state of the object 	 */
name|void
function_decl|(
modifier|*
name|set_sched
function_decl|)
parameter_list|(
name|struct
name|ecore_mcast_obj
modifier|*
name|o
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|clear_sched
function_decl|)
parameter_list|(
name|struct
name|ecore_mcast_obj
modifier|*
name|o
parameter_list|)
function_decl|;
name|bool
function_decl|(
modifier|*
name|check_sched
function_decl|)
parameter_list|(
name|struct
name|ecore_mcast_obj
modifier|*
name|o
parameter_list|)
function_decl|;
comment|/* Wait until all pending commands complete */
name|int
function_decl|(
modifier|*
name|wait_comp
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_mcast_obj
modifier|*
name|o
parameter_list|)
function_decl|;
comment|/** 	 * Handle the internal object counters needed for proper 	 * commands handling. Checks that the provided parameters are 	 * feasible. 	 */
name|int
function_decl|(
modifier|*
name|validate
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_mcast_ramrod_params
modifier|*
name|p
parameter_list|,
name|enum
name|ecore_mcast_cmd
name|cmd
parameter_list|)
function_decl|;
comment|/** 	 * Restore the values of internal counters in case of a failure. 	 */
name|void
function_decl|(
modifier|*
name|revert
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_mcast_ramrod_params
modifier|*
name|p
parameter_list|,
name|int
name|old_num_bins
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|get_registry_size
function_decl|)
parameter_list|(
name|struct
name|ecore_mcast_obj
modifier|*
name|o
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|set_registry_size
function_decl|)
parameter_list|(
name|struct
name|ecore_mcast_obj
modifier|*
name|o
parameter_list|,
name|int
name|n
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************** Credit handling **********************************/
end_comment

begin_struct
struct|struct
name|ecore_credit_pool_obj
block|{
comment|/* Current amount of credit in the pool */
name|ecore_atomic_t
name|credit
decl_stmt|;
comment|/* Maximum allowed credit. put() will check against it. */
name|int
name|pool_sz
decl_stmt|;
comment|/* Allocate a pool table statically. 	 * 	 * Currently the maximum allowed size is MAX_MAC_CREDIT_E2(272) 	 * 	 * The set bit in the table will mean that the entry is available. 	 */
define|#
directive|define
name|ECORE_POOL_VEC_SIZE
value|(MAX_MAC_CREDIT_E2 / 64)
name|uint64_t
name|pool_mirror
index|[
name|ECORE_POOL_VEC_SIZE
index|]
decl_stmt|;
comment|/* Base pool offset (initialized differently */
name|int
name|base_pool_offset
decl_stmt|;
comment|/** 	 * Get the next free pool entry. 	 * 	 * @return TRUE if there was a free entry in the pool 	 */
name|bool
function_decl|(
modifier|*
name|get_entry
function_decl|)
parameter_list|(
name|struct
name|ecore_credit_pool_obj
modifier|*
name|o
parameter_list|,
name|int
modifier|*
name|entry
parameter_list|)
function_decl|;
comment|/** 	 * Return the entry back to the pool. 	 * 	 * @return TRUE if entry is legal and has been successfully 	 *         returned to the pool. 	 */
name|bool
function_decl|(
modifier|*
name|put_entry
function_decl|)
parameter_list|(
name|struct
name|ecore_credit_pool_obj
modifier|*
name|o
parameter_list|,
name|int
name|entry
parameter_list|)
function_decl|;
comment|/** 	 * Get the requested amount of credit from the pool. 	 * 	 * @param cnt Amount of requested credit 	 * @return TRUE if the operation is successful 	 */
name|bool
function_decl|(
modifier|*
name|get
function_decl|)
parameter_list|(
name|struct
name|ecore_credit_pool_obj
modifier|*
name|o
parameter_list|,
name|int
name|cnt
parameter_list|)
function_decl|;
comment|/** 	 * Returns the credit to the pool. 	 * 	 * @param cnt Amount of credit to return 	 * @return TRUE if the operation is successful 	 */
name|bool
function_decl|(
modifier|*
name|put
function_decl|)
parameter_list|(
name|struct
name|ecore_credit_pool_obj
modifier|*
name|o
parameter_list|,
name|int
name|cnt
parameter_list|)
function_decl|;
comment|/** 	 * Reads the current amount of credit. 	 */
name|int
function_decl|(
modifier|*
name|check
function_decl|)
parameter_list|(
name|struct
name|ecore_credit_pool_obj
modifier|*
name|o
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*************************** RSS configuration ********************************/
end_comment

begin_enum
enum|enum
block|{
comment|/* RSS_MODE bits are mutually exclusive */
name|ECORE_RSS_MODE_DISABLED
block|,
name|ECORE_RSS_MODE_REGULAR
block|,
name|ECORE_RSS_SET_SRCH
block|,
comment|/* Setup searcher, E1x specific flag */
name|ECORE_RSS_IPV4
block|,
name|ECORE_RSS_IPV4_TCP
block|,
name|ECORE_RSS_IPV4_UDP
block|,
name|ECORE_RSS_IPV6
block|,
name|ECORE_RSS_IPV6_TCP
block|,
name|ECORE_RSS_IPV6_UDP
block|,
name|ECORE_RSS_TUNNELING
block|,
if|#
directive|if
name|defined
argument_list|(
name|__VMKLNX__
argument_list|)
operator|&&
operator|(
name|VMWARE_ESX_DDK_VERSION
operator|<
literal|55000
operator|)
comment|/* ! BNX2X_UPSTREAM */
name|ECORE_RSS_MODE_ESX51
block|,
endif|#
directive|endif
block|}
enum|;
end_enum

begin_struct
struct|struct
name|ecore_config_rss_params
block|{
name|struct
name|ecore_rss_config_obj
modifier|*
name|rss_obj
decl_stmt|;
comment|/* may have RAMROD_COMP_WAIT set only */
name|unsigned
name|long
name|ramrod_flags
decl_stmt|;
comment|/* ECORE_RSS_X bits */
name|unsigned
name|long
name|rss_flags
decl_stmt|;
comment|/* Number hash bits to take into an account */
name|uint8_t
name|rss_result_mask
decl_stmt|;
comment|/* Indirection table */
name|uint8_t
name|ind_table
index|[
name|T_ETH_INDIRECTION_TABLE_SIZE
index|]
decl_stmt|;
comment|/* RSS hash values */
name|uint32_t
name|rss_key
index|[
literal|10
index|]
decl_stmt|;
comment|/* valid only iff ECORE_RSS_UPDATE_TOE is set */
name|uint16_t
name|toe_rss_bitmap
decl_stmt|;
comment|/* valid iff ECORE_RSS_TUNNELING is set */
name|uint16_t
name|tunnel_value
decl_stmt|;
name|uint16_t
name|tunnel_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_rss_config_obj
block|{
name|struct
name|ecore_raw_obj
name|raw
decl_stmt|;
comment|/* RSS engine to use */
name|uint8_t
name|engine_id
decl_stmt|;
comment|/* Last configured indirection table */
name|uint8_t
name|ind_table
index|[
name|T_ETH_INDIRECTION_TABLE_SIZE
index|]
decl_stmt|;
comment|/* flags for enabling 4-tupple hash on UDP */
name|uint8_t
name|udp_rss_v4
decl_stmt|;
name|uint8_t
name|udp_rss_v6
decl_stmt|;
name|int
function_decl|(
modifier|*
name|config_rss
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_config_rss_params
modifier|*
name|p
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*********************** Queue state update ***********************************/
end_comment

begin_comment
comment|/* UPDATE command options */
end_comment

begin_enum
enum|enum
block|{
name|ECORE_Q_UPDATE_IN_VLAN_REM
block|,
name|ECORE_Q_UPDATE_IN_VLAN_REM_CHNG
block|,
name|ECORE_Q_UPDATE_OUT_VLAN_REM
block|,
name|ECORE_Q_UPDATE_OUT_VLAN_REM_CHNG
block|,
name|ECORE_Q_UPDATE_ANTI_SPOOF
block|,
name|ECORE_Q_UPDATE_ANTI_SPOOF_CHNG
block|,
name|ECORE_Q_UPDATE_ACTIVATE
block|,
name|ECORE_Q_UPDATE_ACTIVATE_CHNG
block|,
name|ECORE_Q_UPDATE_DEF_VLAN_EN
block|,
name|ECORE_Q_UPDATE_DEF_VLAN_EN_CHNG
block|,
name|ECORE_Q_UPDATE_SILENT_VLAN_REM_CHNG
block|,
name|ECORE_Q_UPDATE_SILENT_VLAN_REM
block|,
name|ECORE_Q_UPDATE_TX_SWITCHING_CHNG
block|,
name|ECORE_Q_UPDATE_TX_SWITCHING
block|, }
enum|;
end_enum

begin_comment
comment|/* Allowed Queue states */
end_comment

begin_enum
enum|enum
name|ecore_q_state
block|{
name|ECORE_Q_STATE_RESET
block|,
name|ECORE_Q_STATE_INITIALIZED
block|,
name|ECORE_Q_STATE_ACTIVE
block|,
name|ECORE_Q_STATE_MULTI_COS
block|,
name|ECORE_Q_STATE_MCOS_TERMINATED
block|,
name|ECORE_Q_STATE_INACTIVE
block|,
name|ECORE_Q_STATE_STOPPED
block|,
name|ECORE_Q_STATE_TERMINATED
block|,
name|ECORE_Q_STATE_FLRED
block|,
name|ECORE_Q_STATE_MAX
block|, }
enum|;
end_enum

begin_comment
comment|/* Allowed Queue states */
end_comment

begin_enum
enum|enum
name|ecore_q_logical_state
block|{
name|ECORE_Q_LOGICAL_STATE_ACTIVE
block|,
name|ECORE_Q_LOGICAL_STATE_STOPPED
block|, }
enum|;
end_enum

begin_comment
comment|/* Allowed commands */
end_comment

begin_enum
enum|enum
name|ecore_queue_cmd
block|{
name|ECORE_Q_CMD_INIT
block|,
name|ECORE_Q_CMD_SETUP
block|,
name|ECORE_Q_CMD_SETUP_TX_ONLY
block|,
name|ECORE_Q_CMD_DEACTIVATE
block|,
name|ECORE_Q_CMD_ACTIVATE
block|,
name|ECORE_Q_CMD_UPDATE
block|,
name|ECORE_Q_CMD_UPDATE_TPA
block|,
name|ECORE_Q_CMD_HALT
block|,
name|ECORE_Q_CMD_CFC_DEL
block|,
name|ECORE_Q_CMD_TERMINATE
block|,
name|ECORE_Q_CMD_EMPTY
block|,
name|ECORE_Q_CMD_MAX
block|, }
enum|;
end_enum

begin_comment
comment|/* queue SETUP + INIT flags */
end_comment

begin_enum
enum|enum
block|{
name|ECORE_Q_FLG_TPA
block|,
name|ECORE_Q_FLG_TPA_IPV6
block|,
name|ECORE_Q_FLG_TPA_GRO
block|,
name|ECORE_Q_FLG_STATS
block|,
name|ECORE_Q_FLG_ZERO_STATS
block|,
name|ECORE_Q_FLG_ACTIVE
block|,
name|ECORE_Q_FLG_OV
block|,
name|ECORE_Q_FLG_VLAN
block|,
name|ECORE_Q_FLG_COS
block|,
name|ECORE_Q_FLG_HC
block|,
name|ECORE_Q_FLG_HC_EN
block|,
name|ECORE_Q_FLG_DHC
block|,
name|ECORE_Q_FLG_OOO
block|,
name|ECORE_Q_FLG_FCOE
block|,
name|ECORE_Q_FLG_LEADING_RSS
block|,
name|ECORE_Q_FLG_MCAST
block|,
name|ECORE_Q_FLG_DEF_VLAN
block|,
name|ECORE_Q_FLG_TX_SWITCH
block|,
name|ECORE_Q_FLG_TX_SEC
block|,
name|ECORE_Q_FLG_ANTI_SPOOF
block|,
name|ECORE_Q_FLG_SILENT_VLAN_REM
block|,
name|ECORE_Q_FLG_FORCE_DEFAULT_PRI
block|,
name|ECORE_Q_FLG_REFUSE_OUTBAND_VLAN
block|,
name|ECORE_Q_FLG_PCSUM_ON_PKT
block|,
name|ECORE_Q_FLG_TUN_INC_INNER_IP_ID
block|}
enum|;
end_enum

begin_comment
comment|/* Queue type options: queue type may be a combination of below. */
end_comment

begin_enum
enum|enum
name|ecore_q_type
block|{
name|ECORE_Q_TYPE_FWD
block|,
comment|/** TODO: Consider moving both these flags into the init() 	 *        ramrod params. 	 */
name|ECORE_Q_TYPE_HAS_RX
block|,
name|ECORE_Q_TYPE_HAS_TX
block|, }
enum|;
end_enum

begin_define
define|#
directive|define
name|ECORE_PRIMARY_CID_INDEX
value|0
end_define

begin_define
define|#
directive|define
name|ECORE_MULTI_TX_COS_E1X
value|3
end_define

begin_comment
comment|/* QM only */
end_comment

begin_define
define|#
directive|define
name|ECORE_MULTI_TX_COS_E2_E3A0
value|2
end_define

begin_define
define|#
directive|define
name|ECORE_MULTI_TX_COS_E3B0
value|3
end_define

begin_define
define|#
directive|define
name|ECORE_MULTI_TX_COS
value|3
end_define

begin_comment
comment|/* Maximum possible */
end_comment

begin_define
define|#
directive|define
name|MAC_PAD
value|(ECORE_ALIGN(ETH_ALEN, sizeof(uint32_t)) - ETH_ALEN)
end_define

begin_struct
struct|struct
name|ecore_queue_init_params
block|{
struct|struct
block|{
name|unsigned
name|long
name|flags
decl_stmt|;
name|uint16_t
name|hc_rate
decl_stmt|;
name|uint8_t
name|fw_sb_id
decl_stmt|;
name|uint8_t
name|sb_cq_index
decl_stmt|;
block|}
name|tx
struct|;
struct|struct
block|{
name|unsigned
name|long
name|flags
decl_stmt|;
name|uint16_t
name|hc_rate
decl_stmt|;
name|uint8_t
name|fw_sb_id
decl_stmt|;
name|uint8_t
name|sb_cq_index
decl_stmt|;
block|}
name|rx
struct|;
comment|/* CID context in the host memory */
name|struct
name|eth_context
modifier|*
name|cxts
index|[
name|ECORE_MULTI_TX_COS
index|]
decl_stmt|;
comment|/* maximum number of cos supported by hardware */
name|uint8_t
name|max_cos
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_queue_terminate_params
block|{
comment|/* index within the tx_only cids of this queue object */
name|uint8_t
name|cid_index
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_queue_cfc_del_params
block|{
comment|/* index within the tx_only cids of this queue object */
name|uint8_t
name|cid_index
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_queue_update_params
block|{
name|unsigned
name|long
name|update_flags
decl_stmt|;
comment|/* ECORE_Q_UPDATE_XX bits */
name|uint16_t
name|def_vlan
decl_stmt|;
name|uint16_t
name|silent_removal_value
decl_stmt|;
name|uint16_t
name|silent_removal_mask
decl_stmt|;
comment|/* index within the tx_only cids of this queue object */
name|uint8_t
name|cid_index
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|rxq_pause_params
block|{
name|uint16_t
name|bd_th_lo
decl_stmt|;
name|uint16_t
name|bd_th_hi
decl_stmt|;
name|uint16_t
name|rcq_th_lo
decl_stmt|;
name|uint16_t
name|rcq_th_hi
decl_stmt|;
name|uint16_t
name|sge_th_lo
decl_stmt|;
comment|/* valid iff ECORE_Q_FLG_TPA */
name|uint16_t
name|sge_th_hi
decl_stmt|;
comment|/* valid iff ECORE_Q_FLG_TPA */
name|uint16_t
name|pri_map
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* general */
end_comment

begin_struct
struct|struct
name|ecore_general_setup_params
block|{
comment|/* valid iff ECORE_Q_FLG_STATS */
name|uint8_t
name|stat_id
decl_stmt|;
name|uint8_t
name|spcl_id
decl_stmt|;
name|uint16_t
name|mtu
decl_stmt|;
name|uint8_t
name|cos
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_rxq_setup_params
block|{
comment|/* dma */
name|ecore_dma_addr_t
name|dscr_map
decl_stmt|;
name|ecore_dma_addr_t
name|sge_map
decl_stmt|;
name|ecore_dma_addr_t
name|rcq_map
decl_stmt|;
name|ecore_dma_addr_t
name|rcq_np_map
decl_stmt|;
name|uint16_t
name|drop_flags
decl_stmt|;
name|uint16_t
name|buf_sz
decl_stmt|;
name|uint8_t
name|fw_sb_id
decl_stmt|;
name|uint8_t
name|cl_qzone_id
decl_stmt|;
comment|/* valid iff ECORE_Q_FLG_TPA */
name|uint16_t
name|tpa_agg_sz
decl_stmt|;
name|uint16_t
name|sge_buf_sz
decl_stmt|;
name|uint8_t
name|max_sges_pkt
decl_stmt|;
name|uint8_t
name|max_tpa_queues
decl_stmt|;
name|uint8_t
name|rss_engine_id
decl_stmt|;
comment|/* valid iff ECORE_Q_FLG_MCAST */
name|uint8_t
name|mcast_engine_id
decl_stmt|;
name|uint8_t
name|cache_line_log
decl_stmt|;
name|uint8_t
name|sb_cq_index
decl_stmt|;
comment|/* valid iff BXN2X_Q_FLG_SILENT_VLAN_REM */
name|uint16_t
name|silent_removal_value
decl_stmt|;
name|uint16_t
name|silent_removal_mask
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_txq_setup_params
block|{
comment|/* dma */
name|ecore_dma_addr_t
name|dscr_map
decl_stmt|;
name|uint8_t
name|fw_sb_id
decl_stmt|;
name|uint8_t
name|sb_cq_index
decl_stmt|;
name|uint8_t
name|cos
decl_stmt|;
comment|/* valid iff ECORE_Q_FLG_COS */
name|uint16_t
name|traffic_type
decl_stmt|;
comment|/* equals to the leading rss client id, used for TX classification*/
name|uint8_t
name|tss_leading_cl_id
decl_stmt|;
comment|/* valid iff ECORE_Q_FLG_DEF_VLAN */
name|uint16_t
name|default_vlan
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_queue_setup_params
block|{
name|struct
name|ecore_general_setup_params
name|gen_params
decl_stmt|;
name|struct
name|ecore_txq_setup_params
name|txq_params
decl_stmt|;
name|struct
name|ecore_rxq_setup_params
name|rxq_params
decl_stmt|;
name|struct
name|rxq_pause_params
name|pause_params
decl_stmt|;
name|unsigned
name|long
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_queue_setup_tx_only_params
block|{
name|struct
name|ecore_general_setup_params
name|gen_params
decl_stmt|;
name|struct
name|ecore_txq_setup_params
name|txq_params
decl_stmt|;
name|unsigned
name|long
name|flags
decl_stmt|;
comment|/* index within the tx_only cids of this queue object */
name|uint8_t
name|cid_index
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_queue_state_params
block|{
name|struct
name|ecore_queue_sp_obj
modifier|*
name|q_obj
decl_stmt|;
comment|/* Current command */
name|enum
name|ecore_queue_cmd
name|cmd
decl_stmt|;
comment|/* may have RAMROD_COMP_WAIT set only */
name|unsigned
name|long
name|ramrod_flags
decl_stmt|;
comment|/* Params according to the current command */
union|union
block|{
name|struct
name|ecore_queue_update_params
name|update
decl_stmt|;
name|struct
name|ecore_queue_setup_params
name|setup
decl_stmt|;
name|struct
name|ecore_queue_init_params
name|init
decl_stmt|;
name|struct
name|ecore_queue_setup_tx_only_params
name|tx_only
decl_stmt|;
name|struct
name|ecore_queue_terminate_params
name|terminate
decl_stmt|;
name|struct
name|ecore_queue_cfc_del_params
name|cfc_del
decl_stmt|;
block|}
name|params
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_viflist_params
block|{
name|uint8_t
name|echo_res
decl_stmt|;
name|uint8_t
name|func_bit_map_res
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_queue_sp_obj
block|{
name|uint32_t
name|cids
index|[
name|ECORE_MULTI_TX_COS
index|]
decl_stmt|;
name|uint8_t
name|cl_id
decl_stmt|;
name|uint8_t
name|func_id
decl_stmt|;
comment|/* number of traffic classes supported by queue. 	 * The primary connection of the queue supports the first traffic 	 * class. Any further traffic class is supported by a tx-only 	 * connection. 	 * 	 * Therefore max_cos is also a number of valid entries in the cids 	 * array. 	 */
name|uint8_t
name|max_cos
decl_stmt|;
name|uint8_t
name|num_tx_only
decl_stmt|,
name|next_tx_only
decl_stmt|;
name|enum
name|ecore_q_state
name|state
decl_stmt|,
name|next_state
decl_stmt|;
comment|/* bits from enum ecore_q_type */
name|unsigned
name|long
name|type
decl_stmt|;
comment|/* ECORE_Q_CMD_XX bits. This object implements "one 	 * pending" paradigm but for debug and tracing purposes it's 	 * more convenient to have different bits for different 	 * commands. 	 */
name|unsigned
name|long
name|pending
decl_stmt|;
comment|/* Buffer to use as a ramrod data and its mapping */
name|void
modifier|*
name|rdata
decl_stmt|;
name|ecore_dma_addr_t
name|rdata_mapping
decl_stmt|;
comment|/** 	 * Performs one state change according to the given parameters. 	 * 	 * @return 0 in case of success and negative value otherwise. 	 */
name|int
function_decl|(
modifier|*
name|send_cmd
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_queue_state_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/** 	 * Sets the pending bit according to the requested transition. 	 */
name|int
function_decl|(
modifier|*
name|set_pending
function_decl|)
parameter_list|(
name|struct
name|ecore_queue_sp_obj
modifier|*
name|o
parameter_list|,
name|struct
name|ecore_queue_state_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/** 	 * Checks that the requested state transition is legal. 	 */
name|int
function_decl|(
modifier|*
name|check_transition
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_queue_sp_obj
modifier|*
name|o
parameter_list|,
name|struct
name|ecore_queue_state_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/** 	 * Completes the pending command. 	 */
name|int
function_decl|(
modifier|*
name|complete_cmd
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_queue_sp_obj
modifier|*
name|o
parameter_list|,
name|enum
name|ecore_queue_cmd
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|wait_comp
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_queue_sp_obj
modifier|*
name|o
parameter_list|,
name|enum
name|ecore_queue_cmd
name|cmd
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/********************** Function state update *********************************/
end_comment

begin_comment
comment|/* Allowed Function states */
end_comment

begin_enum
enum|enum
name|ecore_func_state
block|{
name|ECORE_F_STATE_RESET
block|,
name|ECORE_F_STATE_INITIALIZED
block|,
name|ECORE_F_STATE_STARTED
block|,
name|ECORE_F_STATE_TX_STOPPED
block|,
name|ECORE_F_STATE_MAX
block|, }
enum|;
end_enum

begin_comment
comment|/* Allowed Function commands */
end_comment

begin_enum
enum|enum
name|ecore_func_cmd
block|{
name|ECORE_F_CMD_HW_INIT
block|,
name|ECORE_F_CMD_START
block|,
name|ECORE_F_CMD_STOP
block|,
name|ECORE_F_CMD_HW_RESET
block|,
name|ECORE_F_CMD_AFEX_UPDATE
block|,
name|ECORE_F_CMD_AFEX_VIFLISTS
block|,
name|ECORE_F_CMD_TX_STOP
block|,
name|ECORE_F_CMD_TX_START
block|,
name|ECORE_F_CMD_SWITCH_UPDATE
block|,
name|ECORE_F_CMD_MAX
block|, }
enum|;
end_enum

begin_struct
struct|struct
name|ecore_func_hw_init_params
block|{
comment|/* A load phase returned by MCP. 	 * 	 * May be: 	 *		FW_MSG_CODE_DRV_LOAD_COMMON_CHIP 	 *		FW_MSG_CODE_DRV_LOAD_COMMON 	 *		FW_MSG_CODE_DRV_LOAD_PORT 	 *		FW_MSG_CODE_DRV_LOAD_FUNCTION 	 */
name|uint32_t
name|load_phase
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_func_hw_reset_params
block|{
comment|/* A load phase returned by MCP. 	 * 	 * May be: 	 *		FW_MSG_CODE_DRV_LOAD_COMMON_CHIP 	 *		FW_MSG_CODE_DRV_LOAD_COMMON 	 *		FW_MSG_CODE_DRV_LOAD_PORT 	 *		FW_MSG_CODE_DRV_LOAD_FUNCTION 	 */
name|uint32_t
name|reset_phase
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_func_start_params
block|{
comment|/* Multi Function mode: 	 *	- Single Function 	 *	- Switch Dependent 	 *	- Switch Independent 	 */
name|uint16_t
name|mf_mode
decl_stmt|;
comment|/* Switch Dependent mode outer VLAN tag */
name|uint16_t
name|sd_vlan_tag
decl_stmt|;
comment|/* Function cos mode */
name|uint8_t
name|network_cos_mode
decl_stmt|;
comment|/* NVGRE classification enablement */
name|uint8_t
name|nvgre_clss_en
decl_stmt|;
comment|/* NO_GRE_TUNNEL/NVGRE_TUNNEL/L2GRE_TUNNEL/IPGRE_TUNNEL */
name|uint8_t
name|gre_tunnel_mode
decl_stmt|;
comment|/* GRE_OUTER_HEADERS_RSS/GRE_INNER_HEADERS_RSS/NVGRE_KEY_ENTROPY_RSS */
name|uint8_t
name|gre_tunnel_rss
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_func_switch_update_params
block|{
name|uint8_t
name|suspend
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_func_afex_update_params
block|{
name|uint16_t
name|vif_id
decl_stmt|;
name|uint16_t
name|afex_default_vlan
decl_stmt|;
name|uint8_t
name|allowed_priorities
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_func_afex_viflists_params
block|{
name|uint16_t
name|vif_list_index
decl_stmt|;
name|uint8_t
name|func_bit_map
decl_stmt|;
name|uint8_t
name|afex_vif_list_command
decl_stmt|;
name|uint8_t
name|func_to_clear
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_func_tx_start_params
block|{
name|struct
name|priority_cos
name|traffic_type_to_priority_cos
index|[
name|MAX_TRAFFIC_TYPES
index|]
decl_stmt|;
name|uint8_t
name|dcb_enabled
decl_stmt|;
name|uint8_t
name|dcb_version
decl_stmt|;
name|uint8_t
name|dont_add_pri_0
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_func_state_params
block|{
name|struct
name|ecore_func_sp_obj
modifier|*
name|f_obj
decl_stmt|;
comment|/* Current command */
name|enum
name|ecore_func_cmd
name|cmd
decl_stmt|;
comment|/* may have RAMROD_COMP_WAIT set only */
name|unsigned
name|long
name|ramrod_flags
decl_stmt|;
comment|/* Params according to the current command */
union|union
block|{
name|struct
name|ecore_func_hw_init_params
name|hw_init
decl_stmt|;
name|struct
name|ecore_func_hw_reset_params
name|hw_reset
decl_stmt|;
name|struct
name|ecore_func_start_params
name|start
decl_stmt|;
name|struct
name|ecore_func_switch_update_params
name|switch_update
decl_stmt|;
name|struct
name|ecore_func_afex_update_params
name|afex_update
decl_stmt|;
name|struct
name|ecore_func_afex_viflists_params
name|afex_viflists
decl_stmt|;
name|struct
name|ecore_func_tx_start_params
name|tx_start
decl_stmt|;
block|}
name|params
union|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_func_sp_drv_ops
block|{
comment|/* Init tool + runtime initialization: 	 *      - Common Chip 	 *      - Common (per Path) 	 *      - Port 	 *      - Function phases 	 */
name|int
function_decl|(
modifier|*
name|init_hw_cmn_chip
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|init_hw_cmn
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|init_hw_port
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|init_hw_func
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
comment|/* Reset Function HW: Common, Port, Function phases. */
name|void
function_decl|(
modifier|*
name|reset_hw_cmn
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|reset_hw_port
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|reset_hw_func
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
comment|/* Init/Free GUNZIP resources */
name|int
function_decl|(
modifier|*
name|gunzip_init
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|gunzip_end
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
comment|/* Prepare/Release FW resources */
name|int
function_decl|(
modifier|*
name|init_fw
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|release_fw
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|ecore_func_sp_obj
block|{
name|enum
name|ecore_func_state
name|state
decl_stmt|,
name|next_state
decl_stmt|;
comment|/* ECORE_FUNC_CMD_XX bits. This object implements "one 	 * pending" paradigm but for debug and tracing purposes it's 	 * more convenient to have different bits for different 	 * commands. 	 */
name|unsigned
name|long
name|pending
decl_stmt|;
comment|/* Buffer to use as a ramrod data and its mapping */
name|void
modifier|*
name|rdata
decl_stmt|;
name|ecore_dma_addr_t
name|rdata_mapping
decl_stmt|;
comment|/* Buffer to use as a afex ramrod data and its mapping. 	 * This can't be same rdata as above because afex ramrod requests 	 * can arrive to the object in parallel to other ramrod requests. 	 */
name|void
modifier|*
name|afex_rdata
decl_stmt|;
name|ecore_dma_addr_t
name|afex_rdata_mapping
decl_stmt|;
comment|/* this mutex validates that when pending flag is taken, the next 	 * ramrod to be sent will be the one set the pending bit 	 */
name|ECORE_MUTEX
name|one_pending_mutex
decl_stmt|;
comment|/* Driver interface */
name|struct
name|ecore_func_sp_drv_ops
modifier|*
name|drv
decl_stmt|;
comment|/** 	 * Performs one state change according to the given parameters. 	 * 	 * @return 0 in case of success and negative value otherwise. 	 */
name|int
function_decl|(
modifier|*
name|send_cmd
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_func_state_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/** 	 * Checks that the requested state transition is legal. 	 */
name|int
function_decl|(
modifier|*
name|check_transition
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_func_sp_obj
modifier|*
name|o
parameter_list|,
name|struct
name|ecore_func_state_params
modifier|*
name|params
parameter_list|)
function_decl|;
comment|/** 	 * Completes the pending command. 	 */
name|int
function_decl|(
modifier|*
name|complete_cmd
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_func_sp_obj
modifier|*
name|o
parameter_list|,
name|enum
name|ecore_func_cmd
name|cmd
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|wait_comp
function_decl|)
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_func_sp_obj
modifier|*
name|o
parameter_list|,
name|enum
name|ecore_func_cmd
name|cmd
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/********************** Interfaces ********************************************/
end_comment

begin_comment
comment|/* Queueable objects set */
end_comment

begin_union
union|union
name|ecore_qable_obj
block|{
name|struct
name|ecore_vlan_mac_obj
name|vlan_mac
decl_stmt|;
block|}
union|;
end_union

begin_comment
comment|/************** Function state update *********/
end_comment

begin_function_decl
name|void
name|ecore_init_func_obj
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_func_sp_obj
modifier|*
name|obj
parameter_list|,
name|void
modifier|*
name|rdata
parameter_list|,
name|ecore_dma_addr_t
name|rdata_mapping
parameter_list|,
name|void
modifier|*
name|afex_rdata
parameter_list|,
name|ecore_dma_addr_t
name|afex_rdata_mapping
parameter_list|,
name|struct
name|ecore_func_sp_drv_ops
modifier|*
name|drv_iface
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ecore_func_state_change
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_func_state_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|enum
name|ecore_func_state
name|ecore_func_get_state
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_func_sp_obj
modifier|*
name|o
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/******************* Queue State **************/
end_comment

begin_function_decl
name|void
name|ecore_init_queue_obj
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_queue_sp_obj
modifier|*
name|obj
parameter_list|,
name|uint8_t
name|cl_id
parameter_list|,
name|uint32_t
modifier|*
name|cids
parameter_list|,
name|uint8_t
name|cid_cnt
parameter_list|,
name|uint8_t
name|func_id
parameter_list|,
name|void
modifier|*
name|rdata
parameter_list|,
name|ecore_dma_addr_t
name|rdata_mapping
parameter_list|,
name|unsigned
name|long
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ecore_queue_state_change
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_queue_state_params
modifier|*
name|params
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ecore_get_q_logical_state
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_queue_sp_obj
modifier|*
name|obj
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/********************* VLAN-MAC ****************/
end_comment

begin_function_decl
name|void
name|ecore_init_mac_obj
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|mac_obj
parameter_list|,
name|uint8_t
name|cl_id
parameter_list|,
name|uint32_t
name|cid
parameter_list|,
name|uint8_t
name|func_id
parameter_list|,
name|void
modifier|*
name|rdata
parameter_list|,
name|ecore_dma_addr_t
name|rdata_mapping
parameter_list|,
name|int
name|state
parameter_list|,
name|unsigned
name|long
modifier|*
name|pstate
parameter_list|,
name|ecore_obj_type
name|type
parameter_list|,
name|struct
name|ecore_credit_pool_obj
modifier|*
name|macs_pool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ecore_init_vlan_obj
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|vlan_obj
parameter_list|,
name|uint8_t
name|cl_id
parameter_list|,
name|uint32_t
name|cid
parameter_list|,
name|uint8_t
name|func_id
parameter_list|,
name|void
modifier|*
name|rdata
parameter_list|,
name|ecore_dma_addr_t
name|rdata_mapping
parameter_list|,
name|int
name|state
parameter_list|,
name|unsigned
name|long
modifier|*
name|pstate
parameter_list|,
name|ecore_obj_type
name|type
parameter_list|,
name|struct
name|ecore_credit_pool_obj
modifier|*
name|vlans_pool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ecore_init_vlan_mac_obj
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|vlan_mac_obj
parameter_list|,
name|uint8_t
name|cl_id
parameter_list|,
name|uint32_t
name|cid
parameter_list|,
name|uint8_t
name|func_id
parameter_list|,
name|void
modifier|*
name|rdata
parameter_list|,
name|ecore_dma_addr_t
name|rdata_mapping
parameter_list|,
name|int
name|state
parameter_list|,
name|unsigned
name|long
modifier|*
name|pstate
parameter_list|,
name|ecore_obj_type
name|type
parameter_list|,
name|struct
name|ecore_credit_pool_obj
modifier|*
name|macs_pool
parameter_list|,
name|struct
name|ecore_credit_pool_obj
modifier|*
name|vlans_pool
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ecore_vlan_mac_h_read_lock
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|o
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ecore_vlan_mac_h_read_unlock
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|o
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ecore_vlan_mac_h_write_lock
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|o
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ecore_vlan_mac_h_write_unlock
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|o
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ecore_config_vlan_mac
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_vlan_mac_ramrod_params
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ecore_vlan_mac_move
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_vlan_mac_ramrod_params
modifier|*
name|p
parameter_list|,
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|dest_o
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/********************* RX MODE ****************/
end_comment

begin_function_decl
name|void
name|ecore_init_rx_mode_obj
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_rx_mode_obj
modifier|*
name|o
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ecore_config_rx_mode - Send and RX_MODE ramrod according to the provided parameters.  *  * @p: Command parameters  *  * Return: 0 - if operation was successful and there is no pending completions,  *         positive number - if there are pending completions,  *         negative - if there were errors  */
end_comment

begin_function_decl
name|int
name|ecore_config_rx_mode
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_rx_mode_ramrod_params
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************** MULTICASTS ****************/
end_comment

begin_function_decl
name|void
name|ecore_init_mcast_obj
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_mcast_obj
modifier|*
name|mcast_obj
parameter_list|,
name|uint8_t
name|mcast_cl_id
parameter_list|,
name|uint32_t
name|mcast_cid
parameter_list|,
name|uint8_t
name|func_id
parameter_list|,
name|uint8_t
name|engine_id
parameter_list|,
name|void
modifier|*
name|rdata
parameter_list|,
name|ecore_dma_addr_t
name|rdata_mapping
parameter_list|,
name|int
name|state
parameter_list|,
name|unsigned
name|long
modifier|*
name|pstate
parameter_list|,
name|ecore_obj_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ecore_config_mcast - Configure multicast MACs list.  *  * @cmd: command to execute: BNX2X_MCAST_CMD_X  *  * May configure a new list  * provided in p->mcast_list (ECORE_MCAST_CMD_ADD), clean up  * (ECORE_MCAST_CMD_DEL) or restore (ECORE_MCAST_CMD_RESTORE) a current  * configuration, continue to execute the pending commands  * (ECORE_MCAST_CMD_CONT).  *  * If previous command is still pending or if number of MACs to  * configure is more that maximum number of MACs in one command,  * the current command will be enqueued to the tail of the  * pending commands list.  *  * Return: 0 is operation was successfull and there are no pending completions,  *         negative if there were errors, positive if there are pending  *         completions.  */
end_comment

begin_function_decl
name|int
name|ecore_config_mcast
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_mcast_ramrod_params
modifier|*
name|p
parameter_list|,
name|enum
name|ecore_mcast_cmd
name|cmd
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************** CREDIT POOL ****************/
end_comment

begin_function_decl
name|void
name|ecore_init_mac_credit_pool
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_credit_pool_obj
modifier|*
name|p
parameter_list|,
name|uint8_t
name|func_id
parameter_list|,
name|uint8_t
name|func_num
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ecore_init_vlan_credit_pool
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_credit_pool_obj
modifier|*
name|p
parameter_list|,
name|uint8_t
name|func_id
parameter_list|,
name|uint8_t
name|func_num
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/****************** RSS CONFIGURATION ****************/
end_comment

begin_function_decl
name|void
name|ecore_init_rss_config_obj
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_rss_config_obj
modifier|*
name|rss_obj
parameter_list|,
name|uint8_t
name|cl_id
parameter_list|,
name|uint32_t
name|cid
parameter_list|,
name|uint8_t
name|func_id
parameter_list|,
name|uint8_t
name|engine_id
parameter_list|,
name|void
modifier|*
name|rdata
parameter_list|,
name|ecore_dma_addr_t
name|rdata_mapping
parameter_list|,
name|int
name|state
parameter_list|,
name|unsigned
name|long
modifier|*
name|pstate
parameter_list|,
name|ecore_obj_type
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ecore_config_rss - Updates RSS configuration according to provided parameters  *  * Return: 0 in case of success  */
end_comment

begin_function_decl
name|int
name|ecore_config_rss
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_config_rss_params
modifier|*
name|p
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**  * ecore_get_rss_ind_table - Return the current ind_table configuration.  *  * @ind_table: buffer to fill with the current indirection  *                  table content. Should be at least  *                  T_ETH_INDIRECTION_TABLE_SIZE bytes long.  */
end_comment

begin_function_decl
name|void
name|ecore_get_rss_ind_table
parameter_list|(
name|struct
name|ecore_rss_config_obj
modifier|*
name|rss_obj
parameter_list|,
name|uint8_t
modifier|*
name|ind_table
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* set as inline so printout will show the offending function */
end_comment

begin_function_decl
name|int
name|validate_vlan_mac
parameter_list|(
name|struct
name|bxe_softc
modifier|*
name|sc
parameter_list|,
name|struct
name|ecore_vlan_mac_obj
modifier|*
name|vlan_mac
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ECORE_SP_H */
end_comment

end_unit

