begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2017, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IXGBE_OSDEP_H_
end_ifndef

begin_define
define|#
directive|define
name|_IXGBE_OSDEP_H_
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
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
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
name|ASSERT
parameter_list|(
name|x
parameter_list|)
value|if(!(x)) panic("IXGBE: x")
end_define

begin_define
define|#
directive|define
name|EWARN
parameter_list|(
name|H
parameter_list|,
name|W
parameter_list|)
value|printf(W)
end_define

begin_enum
enum|enum
block|{
name|IXGBE_ERROR_SOFTWARE
block|,
name|IXGBE_ERROR_POLLING
block|,
name|IXGBE_ERROR_INVALID_STATE
block|,
name|IXGBE_ERROR_UNSUPPORTED
block|,
name|IXGBE_ERROR_ARGUMENT
block|,
name|IXGBE_ERROR_CAUTION
block|, }
enum|;
end_enum

begin_comment
comment|/* The happy-fun DELAY macro is defined in /usr/src/sys/i386/include/clock.h */
end_comment

begin_define
define|#
directive|define
name|usec_delay
parameter_list|(
name|x
parameter_list|)
value|DELAY(x)
end_define

begin_define
define|#
directive|define
name|msec_delay
parameter_list|(
name|x
parameter_list|)
value|DELAY(1000*(x))
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
name|DEBUGOUT4
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
parameter_list|)
value|printf(S "\n",A,B,C,D)
end_define

begin_define
define|#
directive|define
name|DEBUGOUT5
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
parameter_list|)
value|printf(S "\n",A,B,C,D,E)
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
value|printf(S "\n",A,B,C,D,E,F)
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

begin_define
define|#
directive|define
name|ERROR_REPORT1
value|ERROR_REPORT
end_define

begin_define
define|#
directive|define
name|ERROR_REPORT2
value|ERROR_REPORT
end_define

begin_define
define|#
directive|define
name|ERROR_REPORT3
value|ERROR_REPORT
end_define

begin_define
define|#
directive|define
name|ERROR_REPORT
parameter_list|(
name|level
parameter_list|,
name|format
parameter_list|,
name|arg
modifier|...
parameter_list|)
value|do { \ 		switch (level) { \ 		case IXGBE_ERROR_SOFTWARE: \ 		case IXGBE_ERROR_CAUTION: \ 		case IXGBE_ERROR_POLLING: \ 		case IXGBE_ERROR_INVALID_STATE: \ 		case IXGBE_ERROR_UNSUPPORTED: \ 		case IXGBE_ERROR_ARGUMENT: \ 			device_printf(ixgbe_dev_from_hw(hw), format, ## arg); \ 			break; \ 		default: \ 			break; \ 		} \ 	} while (0)
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
name|DEBUGOUT4
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
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DEBUGOUT5
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

begin_define
define|#
directive|define
name|ERROR_REPORT1
parameter_list|(
name|S
parameter_list|,
name|A
parameter_list|)
end_define

begin_define
define|#
directive|define
name|ERROR_REPORT2
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
name|ERROR_REPORT3
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

begin_endif
endif|#
directive|endif
end_endif

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

begin_comment
comment|/* Shared code dropped this define.. */
end_comment

begin_define
define|#
directive|define
name|IXGBE_INTEL_VENDOR_ID
value|0x8086
end_define

begin_comment
comment|/* Bunch of defines for shared code bogosity */
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
name|IXGBE_NTOHL
parameter_list|(
name|_i
parameter_list|)
value|ntohl(_i)
end_define

begin_define
define|#
directive|define
name|IXGBE_NTOHS
parameter_list|(
name|_i
parameter_list|)
value|ntohs(_i)
end_define

begin_comment
comment|/* XXX these need to be revisited */
end_comment

begin_define
define|#
directive|define
name|IXGBE_CPU_TO_LE16
value|htole16
end_define

begin_define
define|#
directive|define
name|IXGBE_CPU_TO_LE32
value|htole32
end_define

begin_define
define|#
directive|define
name|IXGBE_LE32_TO_CPU
value|le32toh
end_define

begin_define
define|#
directive|define
name|IXGBE_LE32_TO_CPUS
parameter_list|(
name|x
parameter_list|)
end_define

begin_define
define|#
directive|define
name|IXGBE_CPU_TO_BE16
value|htobe16
end_define

begin_define
define|#
directive|define
name|IXGBE_CPU_TO_BE32
value|htobe32
end_define

begin_define
define|#
directive|define
name|IXGBE_BE32_TO_CPU
value|be32toh
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

begin_ifndef
ifndef|#
directive|ifndef
name|__bool_true_false_are_defined
end_ifndef

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

begin_comment
comment|/* shared code requires this */
end_comment

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

begin_define
define|#
directive|define
name|le16_to_cpu
end_define

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|<
literal|800000
end_if

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
argument_list|)
end_if

begin_define
define|#
directive|define
name|mb
parameter_list|()
value|__asm volatile("mfence" ::: "memory")
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
value|__asm volatile("sfence" ::: "memory")
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
value|__asm volatile("lfence" ::: "memory")
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|mb
parameter_list|()
end_define

begin_define
define|#
directive|define
name|rmb
parameter_list|()
end_define

begin_define
define|#
directive|define
name|wmb
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_if
if|#
directive|if
name|defined
argument_list|(
name|__i386__
argument_list|)
operator|||
name|defined
argument_list|(
name|__amd64__
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

begin_comment
comment|/*  * Optimized bcopy thanks to Luigi Rizzo's investigative work.  Assumes  * non-overlapping regions and 32-byte padding on both src and dst.  */
end_comment

begin_function
specifier|static
name|__inline
name|int
name|ixgbe_bcopy
parameter_list|(
name|void
modifier|*
specifier|restrict
name|_src
parameter_list|,
name|void
modifier|*
specifier|restrict
name|_dst
parameter_list|,
name|int
name|l
parameter_list|)
block|{
name|uint64_t
modifier|*
name|src
init|=
name|_src
decl_stmt|;
name|uint64_t
modifier|*
name|dst
init|=
name|_dst
decl_stmt|;
for|for
control|(
init|;
name|l
operator|>
literal|0
condition|;
name|l
operator|-=
literal|32
control|)
block|{
operator|*
name|dst
operator|++
operator|=
operator|*
name|src
operator|++
expr_stmt|;
operator|*
name|dst
operator|++
operator|=
operator|*
name|src
operator|++
expr_stmt|;
operator|*
name|dst
operator|++
operator|=
operator|*
name|src
operator|++
expr_stmt|;
operator|*
name|dst
operator|++
operator|=
operator|*
name|src
operator|++
expr_stmt|;
block|}
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_struct
struct|struct
name|ixgbe_osdep
block|{
name|bus_space_tag_t
name|mem_bus_space_tag
decl_stmt|;
name|bus_space_handle_t
name|mem_bus_space_handle
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* These routines need struct ixgbe_hw declared */
end_comment

begin_struct_decl
struct_decl|struct
name|ixgbe_hw
struct_decl|;
end_struct_decl

begin_comment
comment|/* These routines are needed by the shared code */
end_comment

begin_function_decl
specifier|extern
name|u16
name|ixgbe_read_pci_cfg
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IXGBE_READ_PCIE_WORD
value|ixgbe_read_pci_cfg
end_define

begin_function_decl
specifier|extern
name|void
name|ixgbe_write_pci_cfg
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u16
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IXGBE_WRITE_PCIE_WORD
value|ixgbe_write_pci_cfg
end_define

begin_define
define|#
directive|define
name|IXGBE_WRITE_FLUSH
parameter_list|(
name|a
parameter_list|)
value|IXGBE_READ_REG(a, IXGBE_STATUS)
end_define

begin_function_decl
specifier|extern
name|u32
name|ixgbe_read_reg
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IXGBE_READ_REG
parameter_list|(
name|a
parameter_list|,
name|reg
parameter_list|)
value|ixgbe_read_reg(a, reg)
end_define

begin_function_decl
specifier|extern
name|void
name|ixgbe_write_reg
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u32
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IXGBE_WRITE_REG
parameter_list|(
name|a
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|ixgbe_write_reg(a, reg, val)
end_define

begin_function_decl
specifier|extern
name|u32
name|ixgbe_read_reg_array
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u32
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IXGBE_READ_REG_ARRAY
parameter_list|(
name|a
parameter_list|,
name|reg
parameter_list|,
name|offset
parameter_list|)
define|\
value|ixgbe_read_reg_array(a, reg, offset)
end_define

begin_function_decl
specifier|extern
name|void
name|ixgbe_write_reg_array
parameter_list|(
name|struct
name|ixgbe_hw
modifier|*
parameter_list|,
name|u32
parameter_list|,
name|u32
parameter_list|,
name|u32
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|IXGBE_WRITE_REG_ARRAY
parameter_list|(
name|a
parameter_list|,
name|reg
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
define|\
value|ixgbe_write_reg_array(a, reg, offset, val)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IXGBE_OSDEP_H_ */
end_comment

end_unit

