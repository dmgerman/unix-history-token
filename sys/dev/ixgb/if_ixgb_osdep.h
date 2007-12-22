begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*******************************************************************************  Copyright (c) 2001-2004, Intel Corporation All rights reserved.  Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code must retain the above copyright notice,     this list of conditions and the following disclaimer.   2. Redistributions in binary form must reproduce the above copyright     notice, this list of conditions and the following disclaimer in the     documentation and/or other materials provided with the distribution.   3. Neither the name of the Intel Corporation nor the names of its     contributors may be used to endorse or promote products derived from     this software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  ***************************************************************************/
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

begin_if
if|#
directive|if
name|__FreeBSD_version
operator|>=
literal|502000
end_if

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

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcireg.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ASSERT
parameter_list|(
name|x
parameter_list|)
value|if(!(x)) panic("IXGB: x")
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

begin_define
define|#
directive|define
name|le16_to_cpu
end_define

begin_struct
struct|struct
name|ixgb_osdep
block|{
name|bus_space_tag_t
name|mem_bus_space_tag
decl_stmt|;
name|bus_space_handle_t
name|mem_bus_space_handle
decl_stmt|;
name|struct
name|device
modifier|*
name|dev
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|IXGB_WRITE_FLUSH
parameter_list|(
name|a
parameter_list|)
value|IXGB_READ_REG(a, STATUS)
end_define

begin_define
define|#
directive|define
name|IXGB_READ_REG
parameter_list|(
name|a
parameter_list|,
name|reg
parameter_list|)
value|(\    bus_space_read_4( ((struct ixgb_osdep *)(a)->back)->mem_bus_space_tag, \                      ((struct ixgb_osdep *)(a)->back)->mem_bus_space_handle, \                      IXGB_##reg))
end_define

begin_define
define|#
directive|define
name|IXGB_WRITE_REG
parameter_list|(
name|a
parameter_list|,
name|reg
parameter_list|,
name|value
parameter_list|)
value|(\    bus_space_write_4( ((struct ixgb_osdep *)(a)->back)->mem_bus_space_tag, \                      ((struct ixgb_osdep *)(a)->back)->mem_bus_space_handle, \                      IXGB_##reg, value))
end_define

begin_define
define|#
directive|define
name|IXGB_READ_REG_ARRAY
parameter_list|(
name|a
parameter_list|,
name|reg
parameter_list|,
name|offset
parameter_list|)
value|(\    bus_space_read_4( ((struct ixgb_osdep *)(a)->back)->mem_bus_space_tag, \                      ((struct ixgb_osdep *)(a)->back)->mem_bus_space_handle, \                      (IXGB_##reg + ((offset)<< 2))))
end_define

begin_define
define|#
directive|define
name|IXGB_WRITE_REG_ARRAY
parameter_list|(
name|a
parameter_list|,
name|reg
parameter_list|,
name|offset
parameter_list|,
name|value
parameter_list|)
value|(\       bus_space_write_4( ((struct ixgb_osdep *)(a)->back)->mem_bus_space_tag, \                       ((struct ixgb_osdep *)(a)->back)->mem_bus_space_handle, \                       (IXGB_##reg + ((offset)<< 2)), value))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FREEBSD_OS_H_ */
end_comment

end_unit

