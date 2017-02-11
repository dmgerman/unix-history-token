begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2013-2015, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_I40E_OSDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_I40E_OSDEP_H_
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
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
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
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
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/pci/pcireg.h>
end_include

begin_define
define|#
directive|define
name|i40e_usec_delay
parameter_list|(
name|x
parameter_list|)
value|DELAY(x)
end_define

begin_define
define|#
directive|define
name|i40e_msec_delay
parameter_list|(
name|x
parameter_list|)
value|DELAY(1000 * (x))
end_define

begin_define
define|#
directive|define
name|DBG
value|0
end_define

begin_define
define|#
directive|define
name|MSGOUT
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
value|printf(S "\n", A, B)
end_define

begin_define
define|#
directive|define
name|DEBUGFUNC
parameter_list|(
name|F
parameter_list|)
value|DEBUGOUT(F);
end_define

begin_if
if|#
directive|if
name|DBG
end_if

begin_define
define|#
directive|define
name|DEBUGOUT
parameter_list|(
name|S
parameter_list|)
value|printf(S "\n")
end_define

begin_define
define|#
directive|define
name|DEBUGOUT1
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|)
value|printf(S "\n",A)
end_define

begin_define
define|#
directive|define
name|DEBUGOUT2
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
value|printf(S "\n",A,B)
end_define

begin_define
define|#
directive|define
name|DEBUGOUT3
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|)
value|printf(S "\n",A,B,C)
end_define

begin_define
define|#
directive|define
name|DEBUGOUT7
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|,
name|D
parameter_list|,
name|E
parameter_list|,
name|F
parameter_list|,
name|G
parameter_list|)
value|printf(S "\n",A,B,C,D,E,F,G)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DEBUGOUT
parameter_list|(
name|S
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUGOUT1
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUGOUT2
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUGOUT3
parameter_list|(
name|S
parameter_list|,
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
name|DEBUGOUT6
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|,
name|D
parameter_list|,
name|E
parameter_list|,
name|F
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUGOUT7
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|,
name|B
parameter_list|,
name|C
parameter_list|,
name|D
parameter_list|,
name|E
parameter_list|,
name|F
parameter_list|,
name|G
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Remove unused shared code macros */
end_comment

begin_define
define|#
directive|define
name|UNREFERENCED_PARAMETER
parameter_list|(
name|_p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|UNREFERENCED_1PARAMETER
parameter_list|(
name|_p
parameter_list|)
end_define

begin_define
define|#
directive|define
name|UNREFERENCED_2PARAMETER
parameter_list|(
name|_p
parameter_list|,
name|_q
parameter_list|)
end_define

begin_define
define|#
directive|define
name|UNREFERENCED_3PARAMETER
parameter_list|(
name|_p
parameter_list|,
name|_q
parameter_list|,
name|_r
parameter_list|)
end_define

begin_define
define|#
directive|define
name|UNREFERENCED_4PARAMETER
parameter_list|(
name|_p
parameter_list|,
name|_q
parameter_list|,
name|_r
parameter_list|,
name|_s
parameter_list|)
end_define

begin_define
define|#
directive|define
name|UNREFERENCED_5PARAMETER
parameter_list|(
name|_p
parameter_list|,
name|_q
parameter_list|,
name|_r
parameter_list|,
name|_s
parameter_list|,
name|_t
parameter_list|)
end_define

begin_define
define|#
directive|define
name|STATIC
value|static
end_define

begin_define
define|#
directive|define
name|INLINE
value|inline
end_define

begin_define
define|#
directive|define
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|false
value|0
end_define

begin_comment
comment|/* shared code requires this */
end_comment

begin_define
define|#
directive|define
name|TRUE
value|1
end_define

begin_define
define|#
directive|define
name|true
value|1
end_define

begin_define
define|#
directive|define
name|CMD_MEM_WRT_INVALIDATE
value|0x0010
end_define

begin_comment
comment|/* BIT_4 */
end_comment

begin_define
define|#
directive|define
name|PCI_COMMAND_REGISTER
value|PCIR_COMMAND
end_define

begin_define
define|#
directive|define
name|ARRAY_SIZE
parameter_list|(
name|a
parameter_list|)
value|(sizeof(a) / sizeof((a)[0]))
end_define

begin_define
define|#
directive|define
name|i40e_memset
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|memset((a), (b), (c))
end_define

begin_define
define|#
directive|define
name|i40e_memcpy
parameter_list|(
name|a
parameter_list|,
name|b
parameter_list|,
name|c
parameter_list|,
name|d
parameter_list|)
value|memcpy((a), (b), (c))
end_define

begin_define
define|#
directive|define
name|CPU_TO_LE16
parameter_list|(
name|o
parameter_list|)
value|htole16(o)
end_define

begin_define
define|#
directive|define
name|CPU_TO_LE32
parameter_list|(
name|s
parameter_list|)
value|htole32(s)
end_define

begin_define
define|#
directive|define
name|CPU_TO_LE64
parameter_list|(
name|h
parameter_list|)
value|htole64(h)
end_define

begin_define
define|#
directive|define
name|LE16_TO_CPU
parameter_list|(
name|a
parameter_list|)
value|le16toh(a)
end_define

begin_define
define|#
directive|define
name|LE32_TO_CPU
parameter_list|(
name|c
parameter_list|)
value|le32toh(c)
end_define

begin_define
define|#
directive|define
name|LE64_TO_CPU
parameter_list|(
name|k
parameter_list|)
value|le64toh(k)
end_define

begin_define
define|#
directive|define
name|I40E_NTOHS
parameter_list|(
name|a
parameter_list|)
value|ntohs(a)
end_define

begin_define
define|#
directive|define
name|I40E_NTOHL
parameter_list|(
name|a
parameter_list|)
value|ntohl(a)
end_define

begin_define
define|#
directive|define
name|I40E_HTONS
parameter_list|(
name|a
parameter_list|)
value|htons(a)
end_define

begin_define
define|#
directive|define
name|I40E_HTONL
parameter_list|(
name|a
parameter_list|)
value|htonl(a)
end_define

begin_define
define|#
directive|define
name|FIELD_SIZEOF
parameter_list|(
name|x
parameter_list|,
name|y
parameter_list|)
value|(sizeof(((x*)0)->y))
end_define

begin_typedef
typedef|typedef
name|uint8_t
name|u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int8_t
name|s8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint16_t
name|u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int16_t
name|s16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint32_t
name|u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int32_t
name|s32
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint64_t
name|u64
typedef|;
end_typedef

begin_comment
comment|/* long string relief */
end_comment

begin_typedef
typedef|typedef
name|enum
name|i40e_status_code
name|i40e_status
typedef|;
end_typedef

begin_define
define|#
directive|define
name|__le16
value|u16
end_define

begin_define
define|#
directive|define
name|__le32
value|u32
end_define

begin_define
define|#
directive|define
name|__le64
value|u64
end_define

begin_define
define|#
directive|define
name|__be16
value|u16
end_define

begin_define
define|#
directive|define
name|__be32
value|u32
end_define

begin_define
define|#
directive|define
name|__be64
value|u64
end_define

begin_comment
comment|/* SW spinlock */
end_comment

begin_struct
struct|struct
name|i40e_spinlock
block|{
name|struct
name|mtx
name|mutex
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|le16_to_cpu
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__amd64__
argument_list|)
operator|||
name|defined
argument_list|(
name|i386
argument_list|)
end_if

begin_function
specifier|static
name|__inline
name|void
name|prefetch
parameter_list|(
name|void
modifier|*
name|x
parameter_list|)
block|{
asm|__asm volatile("prefetcht0 %0" :: "m" (*(unsigned long *)x));
block|}
end_function

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|prefetch
parameter_list|(
name|x
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|i40e_osdep
block|{
name|bus_space_tag_t
name|mem_bus_space_tag
decl_stmt|;
name|bus_space_handle_t
name|mem_bus_space_handle
decl_stmt|;
name|bus_size_t
name|mem_bus_space_size
decl_stmt|;
name|uint32_t
name|flush_reg
decl_stmt|;
name|int
name|i2c_intfc_num
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|i40e_dma_mem
block|{
name|void
modifier|*
name|va
decl_stmt|;
name|u64
name|pa
decl_stmt|;
name|bus_dma_tag_t
name|tag
decl_stmt|;
name|bus_dmamap_t
name|map
decl_stmt|;
name|bus_dma_segment_t
name|seg
decl_stmt|;
name|bus_size_t
name|size
decl_stmt|;
name|int
name|nseg
decl_stmt|;
name|int
name|flags
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|i40e_virt_mem
block|{
name|void
modifier|*
name|va
decl_stmt|;
name|u32
name|size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct_decl
struct_decl|struct
name|i40e_hw
struct_decl|;
end_struct_decl

begin_comment
comment|/* forward decl */
end_comment

begin_function_decl
name|u16
name|i40e_read_pci_cfg
parameter_list|(
name|struct
name|i40e_hw
modifier|*
parameter_list|,
name|u32
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|i40e_write_pci_cfg
parameter_list|(
name|struct
name|i40e_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u16
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** i40e_debug - OS dependent version of shared code debug printing */
end_comment

begin_enum_decl
enum_decl|enum
name|i40e_debug_mask
enum_decl|;
end_enum_decl

begin_define
define|#
directive|define
name|i40e_debug
parameter_list|(
name|h
parameter_list|,
name|m
parameter_list|,
name|s
parameter_list|,
modifier|...
parameter_list|)
value|i40e_debug_shared(h, m, s, ##__VA_ARGS__)
end_define

begin_function_decl
specifier|extern
name|void
name|i40e_debug_shared
parameter_list|(
name|struct
name|i40e_hw
modifier|*
name|hw
parameter_list|,
name|enum
name|i40e_debug_mask
name|mask
parameter_list|,
name|char
modifier|*
name|fmt_str
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Non-busy-wait that uses kern_yield() */
end_comment

begin_function_decl
name|void
name|i40e_msec_pause
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|ixl_vc_opcode_str
parameter_list|(
name|uint16_t
name|op
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* ** This hardware supports either 16 or 32 byte rx descriptors; ** the driver only uses the 32 byte kind. */
end_comment

begin_define
define|#
directive|define
name|i40e_rx_desc
value|i40e_32byte_rx_desc
end_define

begin_function
specifier|static
name|__inline
name|uint32_t
name|rd32_osdep
parameter_list|(
name|struct
name|i40e_osdep
modifier|*
name|osdep
parameter_list|,
name|uint32_t
name|reg
parameter_list|)
block|{
name|KASSERT
argument_list|(
name|reg
operator|<
name|osdep
operator|->
name|mem_bus_space_size
argument_list|,
operator|(
literal|"ixl: register offset %#jx too large (max is %#jx)"
operator|,
operator|(
name|uintmax_t
operator|)
name|reg
operator|,
operator|(
name|uintmax_t
operator|)
name|osdep
operator|->
name|mem_bus_space_size
operator|)
argument_list|)
expr_stmt|;
return|return
operator|(
name|bus_space_read_4
argument_list|(
name|osdep
operator|->
name|mem_bus_space_tag
argument_list|,
name|osdep
operator|->
name|mem_bus_space_handle
argument_list|,
name|reg
argument_list|)
operator|)
return|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|wr32_osdep
parameter_list|(
name|struct
name|i40e_osdep
modifier|*
name|osdep
parameter_list|,
name|uint32_t
name|reg
parameter_list|,
name|uint32_t
name|value
parameter_list|)
block|{
name|KASSERT
argument_list|(
name|reg
operator|<
name|osdep
operator|->
name|mem_bus_space_size
argument_list|,
operator|(
literal|"ixl: register offset %#jx too large (max is %#jx)"
operator|,
operator|(
name|uintmax_t
operator|)
name|reg
operator|,
operator|(
name|uintmax_t
operator|)
name|osdep
operator|->
name|mem_bus_space_size
operator|)
argument_list|)
expr_stmt|;
name|bus_space_write_4
argument_list|(
name|osdep
operator|->
name|mem_bus_space_tag
argument_list|,
name|osdep
operator|->
name|mem_bus_space_handle
argument_list|,
name|reg
argument_list|,
name|value
argument_list|)
expr_stmt|;
block|}
end_function

begin_function
specifier|static
name|__inline
name|void
name|ixl_flush_osdep
parameter_list|(
name|struct
name|i40e_osdep
modifier|*
name|osdep
parameter_list|)
block|{
name|rd32_osdep
argument_list|(
name|osdep
argument_list|,
name|osdep
operator|->
name|flush_reg
argument_list|)
expr_stmt|;
block|}
end_function

begin_define
define|#
directive|define
name|rd32
parameter_list|(
name|a
parameter_list|,
name|reg
parameter_list|)
value|rd32_osdep((a)->back, (reg))
end_define

begin_define
define|#
directive|define
name|wr32
parameter_list|(
name|a
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
value|wr32_osdep((a)->back, (reg), (value))
end_define

begin_define
define|#
directive|define
name|rd64
parameter_list|(
name|a
parameter_list|,
name|reg
parameter_list|)
value|(\    bus_space_read_8( ((struct i40e_osdep *)(a)->back)->mem_bus_space_tag, \                      ((struct i40e_osdep *)(a)->back)->mem_bus_space_handle, \                      reg))
end_define

begin_define
define|#
directive|define
name|wr64
parameter_list|(
name|a
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
value|(\    bus_space_write_8( ((struct i40e_osdep *)(a)->back)->mem_bus_space_tag, \                      ((struct i40e_osdep *)(a)->back)->mem_bus_space_handle, \                      reg, value))
end_define

begin_define
define|#
directive|define
name|ixl_flush
parameter_list|(
name|a
parameter_list|)
value|ixl_flush_osdep((a)->back)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _I40E_OSDEP_H_ */
end_comment

end_unit

