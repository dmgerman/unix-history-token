begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************    Copyright (c) 2001-2015, Intel Corporation    All rights reserved.      Redistribution and use in source and binary forms, with or without    modification, are permitted provided that the following conditions are met:       1. Redistributions of source code must retain the above copyright notice,        this list of conditions and the following disclaimer.       2. Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.       3. Neither the name of the Intel Corporation nor the names of its        contributors may be used to endorse or promote products derived from        this software without specific prior written permission.      THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"   AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE    ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE    LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR    CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF    SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN    CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)    ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE   POSSIBILITY OF SUCH DAMAGE.  ******************************************************************************/
end_comment

begin_comment
comment|/*$FreeBSD$*/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FREEBSD_OS_H_
end_ifndef

begin_define
define|#
directive|define
name|_FREEBSD_OS_H_
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
file|<sys/proc.h>
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
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_var.h>
end_include

begin_include
include|#
directive|include
file|<net/iflib.h>
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
value|if(!(x)) panic("EM: x")
end_define

begin_define
define|#
directive|define
name|us_scale
parameter_list|(
name|x
parameter_list|)
value|max(1, (x/(1000000/hz)))
end_define

begin_function
specifier|static
specifier|inline
name|int
name|ms_scale
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|hz
operator|==
literal|1000
condition|)
block|{
return|return
operator|(
name|x
operator|)
return|;
block|}
elseif|else
if|if
condition|(
name|hz
operator|>
literal|1000
condition|)
block|{
return|return
operator|(
name|x
operator|*
operator|(
name|hz
operator|/
literal|1000
operator|)
operator|)
return|;
block|}
else|else
block|{
return|return
operator|(
name|max
argument_list|(
literal|1
argument_list|,
name|x
operator|/
operator|(
literal|1000
operator|/
name|hz
operator|)
argument_list|)
operator|)
return|;
block|}
block|}
end_function

begin_decl_stmt
specifier|extern
name|int
name|cold
decl_stmt|;
end_decl_stmt

begin_function
specifier|static
specifier|inline
name|void
name|safe_pause_us
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|cold
condition|)
block|{
name|DELAY
argument_list|(
name|x
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|pause
argument_list|(
literal|"e1000_delay"
argument_list|,
name|max
argument_list|(
literal|1
argument_list|,
name|x
operator|/
operator|(
literal|1000000
operator|/
name|hz
operator|)
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_function
specifier|static
specifier|inline
name|void
name|safe_pause_ms
parameter_list|(
name|int
name|x
parameter_list|)
block|{
if|if
condition|(
name|cold
condition|)
block|{
name|DELAY
argument_list|(
name|x
operator|*
literal|1000
argument_list|)
expr_stmt|;
block|}
else|else
block|{
name|pause
argument_list|(
literal|"e1000_delay"
argument_list|,
name|ms_scale
argument_list|(
name|x
argument_list|)
argument_list|)
expr_stmt|;
block|}
block|}
end_function

begin_define
define|#
directive|define
name|usec_delay
parameter_list|(
name|x
parameter_list|)
value|safe_pause_us(x)
end_define

begin_define
define|#
directive|define
name|usec_delay_irq
parameter_list|(
name|x
parameter_list|)
value|usec_delay(x)
end_define

begin_define
define|#
directive|define
name|msec_delay
parameter_list|(
name|x
parameter_list|)
value|safe_pause_ms(x)
end_define

begin_define
define|#
directive|define
name|msec_delay_irq
parameter_list|(
name|x
parameter_list|)
value|msec_delay(x)
end_define

begin_comment
comment|/* Enable/disable debugging statements in shared code */
end_comment

begin_define
define|#
directive|define
name|DBG
value|0
end_define

begin_define
define|#
directive|define
name|DEBUGOUT
parameter_list|(
modifier|...
parameter_list|)
define|\
value|do { if (DBG) printf(__VA_ARGS__); } while (0)
end_define

begin_define
define|#
directive|define
name|DEBUGOUT1
parameter_list|(
modifier|...
parameter_list|)
value|DEBUGOUT(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|DEBUGOUT2
parameter_list|(
modifier|...
parameter_list|)
value|DEBUGOUT(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|DEBUGOUT3
parameter_list|(
modifier|...
parameter_list|)
value|DEBUGOUT(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|DEBUGOUT7
parameter_list|(
modifier|...
parameter_list|)
value|DEBUGOUT(__VA_ARGS__)
end_define

begin_define
define|#
directive|define
name|DEBUGFUNC
parameter_list|(
name|F
parameter_list|)
value|DEBUGOUT(F "\n")
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
name|FALSE
value|0
end_define

begin_define
define|#
directive|define
name|TRUE
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

begin_typedef
typedef|typedef
name|uint64_t
name|u64
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
name|uint16_t
name|u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|uint8_t
name|u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int64_t
name|s64
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
name|int16_t
name|s16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|int8_t
name|s8
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

begin_comment
comment|/*__FreeBSD_version< 800000 */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|INVARIANTS
end_ifdef

begin_define
define|#
directive|define
name|ASSERT_CTX_LOCK_HELD
parameter_list|(
name|hw
parameter_list|)
value|(sx_assert(iflib_ctx_lock_get(((struct e1000_osdep *)hw->back)->ctx), SX_XLOCKED))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASSERT_CTX_LOCK_HELD
parameter_list|(
name|hw
parameter_list|)
end_define

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

begin_struct
struct|struct
name|e1000_osdep
block|{
name|bus_space_tag_t
name|mem_bus_space_tag
decl_stmt|;
name|bus_space_handle_t
name|mem_bus_space_handle
decl_stmt|;
name|bus_space_tag_t
name|io_bus_space_tag
decl_stmt|;
name|bus_space_handle_t
name|io_bus_space_handle
decl_stmt|;
name|bus_space_tag_t
name|flash_bus_space_tag
decl_stmt|;
name|bus_space_handle_t
name|flash_bus_space_handle
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|if_ctx_t
name|ctx
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|E1000_REGISTER
parameter_list|(
name|hw
parameter_list|,
name|reg
parameter_list|)
value|(((hw)->mac.type>= e1000_82543) \     ? reg : e1000_translate_register_82542(reg))
end_define

begin_define
define|#
directive|define
name|E1000_WRITE_FLUSH
parameter_list|(
name|a
parameter_list|)
value|E1000_READ_REG(a, E1000_STATUS)
end_define

begin_comment
comment|/* Read from an absolute offset in the adapter's memory space */
end_comment

begin_define
define|#
directive|define
name|E1000_READ_OFFSET
parameter_list|(
name|hw
parameter_list|,
name|offset
parameter_list|)
define|\
value|bus_space_read_4(((struct e1000_osdep *)(hw)->back)->mem_bus_space_tag, \     ((struct e1000_osdep *)(hw)->back)->mem_bus_space_handle, offset)
end_define

begin_comment
comment|/* Write to an absolute offset in the adapter's memory space */
end_comment

begin_define
define|#
directive|define
name|E1000_WRITE_OFFSET
parameter_list|(
name|hw
parameter_list|,
name|offset
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_4(((struct e1000_osdep *)(hw)->back)->mem_bus_space_tag, \     ((struct e1000_osdep *)(hw)->back)->mem_bus_space_handle, offset, value)
end_define

begin_comment
comment|/* Register READ/WRITE macros */
end_comment

begin_define
define|#
directive|define
name|E1000_READ_REG
parameter_list|(
name|hw
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4(((struct e1000_osdep *)(hw)->back)->mem_bus_space_tag, \         ((struct e1000_osdep *)(hw)->back)->mem_bus_space_handle, \         E1000_REGISTER(hw, reg))
end_define

begin_define
define|#
directive|define
name|E1000_WRITE_REG
parameter_list|(
name|hw
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_4(((struct e1000_osdep *)(hw)->back)->mem_bus_space_tag, \         ((struct e1000_osdep *)(hw)->back)->mem_bus_space_handle, \         E1000_REGISTER(hw, reg), value)
end_define

begin_define
define|#
directive|define
name|E1000_READ_REG_ARRAY
parameter_list|(
name|hw
parameter_list|,
name|reg
parameter_list|,
name|index
parameter_list|)
define|\
value|bus_space_read_4(((struct e1000_osdep *)(hw)->back)->mem_bus_space_tag, \         ((struct e1000_osdep *)(hw)->back)->mem_bus_space_handle, \         E1000_REGISTER(hw, reg) + ((index)<< 2))
end_define

begin_define
define|#
directive|define
name|E1000_WRITE_REG_ARRAY
parameter_list|(
name|hw
parameter_list|,
name|reg
parameter_list|,
name|index
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_4(((struct e1000_osdep *)(hw)->back)->mem_bus_space_tag, \         ((struct e1000_osdep *)(hw)->back)->mem_bus_space_handle, \         E1000_REGISTER(hw, reg) + ((index)<< 2), value)
end_define

begin_define
define|#
directive|define
name|E1000_READ_REG_ARRAY_DWORD
value|E1000_READ_REG_ARRAY
end_define

begin_define
define|#
directive|define
name|E1000_WRITE_REG_ARRAY_DWORD
value|E1000_WRITE_REG_ARRAY
end_define

begin_define
define|#
directive|define
name|E1000_READ_REG_ARRAY_BYTE
parameter_list|(
name|hw
parameter_list|,
name|reg
parameter_list|,
name|index
parameter_list|)
define|\
value|bus_space_read_1(((struct e1000_osdep *)(hw)->back)->mem_bus_space_tag, \         ((struct e1000_osdep *)(hw)->back)->mem_bus_space_handle, \         E1000_REGISTER(hw, reg) + index)
end_define

begin_define
define|#
directive|define
name|E1000_WRITE_REG_ARRAY_BYTE
parameter_list|(
name|hw
parameter_list|,
name|reg
parameter_list|,
name|index
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_1(((struct e1000_osdep *)(hw)->back)->mem_bus_space_tag, \         ((struct e1000_osdep *)(hw)->back)->mem_bus_space_handle, \         E1000_REGISTER(hw, reg) + index, value)
end_define

begin_define
define|#
directive|define
name|E1000_WRITE_REG_ARRAY_WORD
parameter_list|(
name|hw
parameter_list|,
name|reg
parameter_list|,
name|index
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_2(((struct e1000_osdep *)(hw)->back)->mem_bus_space_tag, \         ((struct e1000_osdep *)(hw)->back)->mem_bus_space_handle, \         E1000_REGISTER(hw, reg) + (index<< 1), value)
end_define

begin_define
define|#
directive|define
name|E1000_WRITE_REG_IO
parameter_list|(
name|hw
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
value|do {\     bus_space_write_4(((struct e1000_osdep *)(hw)->back)->io_bus_space_tag, \         ((struct e1000_osdep *)(hw)->back)->io_bus_space_handle, \         (hw)->io_base, reg); \     bus_space_write_4(((struct e1000_osdep *)(hw)->back)->io_bus_space_tag, \         ((struct e1000_osdep *)(hw)->back)->io_bus_space_handle, \         (hw)->io_base + 4, value); } while (0)
end_define

begin_define
define|#
directive|define
name|E1000_READ_FLASH_REG
parameter_list|(
name|hw
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_4(((struct e1000_osdep *)(hw)->back)->flash_bus_space_tag, \         ((struct e1000_osdep *)(hw)->back)->flash_bus_space_handle, reg)
end_define

begin_define
define|#
directive|define
name|E1000_READ_FLASH_REG16
parameter_list|(
name|hw
parameter_list|,
name|reg
parameter_list|)
define|\
value|bus_space_read_2(((struct e1000_osdep *)(hw)->back)->flash_bus_space_tag, \         ((struct e1000_osdep *)(hw)->back)->flash_bus_space_handle, reg)
end_define

begin_define
define|#
directive|define
name|E1000_WRITE_FLASH_REG
parameter_list|(
name|hw
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_4(((struct e1000_osdep *)(hw)->back)->flash_bus_space_tag, \         ((struct e1000_osdep *)(hw)->back)->flash_bus_space_handle, reg, value)
end_define

begin_define
define|#
directive|define
name|E1000_WRITE_FLASH_REG16
parameter_list|(
name|hw
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_2(((struct e1000_osdep *)(hw)->back)->flash_bus_space_tag, \         ((struct e1000_osdep *)(hw)->back)->flash_bus_space_handle, reg, value)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|INVARIANTS
argument_list|)
end_if

begin_include
include|#
directive|include
file|<sys/proc.h>
end_include

begin_define
define|#
directive|define
name|ASSERT_NO_LOCKS
parameter_list|()
define|\
value|do {						\ 	     int unknown_locks = curthread->td_locks - mtx_owned(&Giant);	\ 	     if (unknown_locks> 0) {					\ 		     WITNESS_WARN(WARN_GIANTOK|WARN_SLEEPOK|WARN_PANIC, NULL, "unexpected non-sleepable lock"); \ 	     }								\ 	     MPASS(curthread->td_rw_rlocks == 0);			\ 	     MPASS(curthread->td_lk_slocks == 0);			\ 	} while (0)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|ASSERT_NO_LOCKS
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

begin_comment
comment|/* _FREEBSD_OS_H_ */
end_comment

end_unit

