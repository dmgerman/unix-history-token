begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/************************************************************************** **************************************************************************  Copyright (c) 2001 Intel Corporation All rights reserved.  Redistribution and use in source and binary forms of the Software, with or without modification, are permitted provided that the following conditions are met:   1. Redistributions of source code of the Software may retain the above     copyright notice, this list of conditions and the following disclaimer.   2. Redistributions in binary form of the Software may reproduce the above     copyright notice, this list of conditions and the following disclaimer     in the documentation and/or other materials provided with the     distribution.   3. Neither the name of the Intel Corporation nor the names of its     contributors shall be used to endorse or promote products derived from     this Software without specific prior written permission.  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE INTEL OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *************************************************************************** ***************************************************************************/
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
name|DelayInMicroseconds
parameter_list|(
name|x
parameter_list|)
value|DELAY(x)
end_define

begin_define
define|#
directive|define
name|DelayInMilliseconds
parameter_list|(
name|x
parameter_list|)
value|DELAY(1000*(x))
end_define

begin_typedef
typedef|typedef
name|u_int8_t
name|u8
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int16_t
name|u16
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|u_int32_t
name|u32
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|_E1000_64_BIT_PHYSICAL_ADDRESS
block|{
name|u32
name|Lo32
decl_stmt|;
name|u32
name|Hi32
decl_stmt|;
block|}
name|E1000_64_BIT_PHYSICAL_ADDRESS
operator|,
typedef|*
name|PE1000_64_BIT_PHYSICAL_ADDRESS
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IN
end_define

begin_define
define|#
directive|define
name|OUT
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
name|E1000_READ_REG
parameter_list|(
name|reg
parameter_list|)
define|\
value|bus_space_read_4(Adapter->bus_space_tag, Adapter->bus_space_handle, \         (Adapter->MacType>= MAC_LIVENGOOD)?offsetof(E1000_REGISTERS, reg): \         offsetof(OLD_REGISTERS, reg))
end_define

begin_define
define|#
directive|define
name|E1000_WRITE_REG
parameter_list|(
name|reg
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_4(Adapter->bus_space_tag, Adapter->bus_space_handle, \         (Adapter->MacType>= MAC_LIVENGOOD)?offsetof(E1000_REGISTERS, reg): \         offsetof(OLD_REGISTERS, reg), value)
end_define

begin_define
define|#
directive|define
name|WritePciConfigWord
parameter_list|(
name|Reg
parameter_list|,
name|PValue
parameter_list|)
value|pci_write_config(Adapter->dev, Reg, *PValue, 2);
end_define

begin_include
include|#
directive|include
file|<dev/em/if_em.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FREEBSD_OS_H_ */
end_comment

end_unit

