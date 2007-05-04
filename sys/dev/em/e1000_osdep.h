begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**************************************************************************  Copyright (c) 2001-2007, Intel Corporation All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Redistributions in binary form must reproduce the above copyright     notice, this list of conditions and the following disclaimer in the     documentation and/or other materials provided with the distribution.   3. Neither the name of the Intel Corporation nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  ***************************************************************************/
end_comment

begin_comment
comment|/*  * $FreeBSD$  */
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
value|if(!(x)) panic("EM: x")
end_define

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

begin_comment
comment|/* TODO: Should we be paranoid about delaying in interrupt context? */
end_comment

begin_define
define|#
directive|define
name|msec_delay_irq
parameter_list|(
name|x
parameter_list|)
value|DELAY(1000*(x))
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

begin_comment
comment|/* ** These typedefs are necessary due to the new ** shared code, they are native to Linux. */
end_comment

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
name|struct
name|device
modifier|*
name|dev
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|NO_82542_SUPPORT
end_ifdef

begin_define
define|#
directive|define
name|E1000_REGISTER
parameter_list|(
name|hw
parameter_list|,
name|reg
parameter_list|)
value|reg
end_define

begin_else
else|#
directive|else
end_else

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

begin_endif
endif|#
directive|endif
end_endif

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

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FREEBSD_OS_H_ */
end_comment

end_unit

