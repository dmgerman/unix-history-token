begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996, by Steve Passe  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. The name of the developer may NOT be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_MPAPIC_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_MPAPIC_H_
end_define

begin_comment
comment|/*  * Size of APIC ID list.  * Also used a MAX size of various other arrays.  */
end_comment

begin_define
define|#
directive|define
name|NAPICID
value|16
end_define

begin_comment
comment|/* these don't really belong in here... */
end_comment

begin_enum
enum|enum
name|busTypes
block|{
name|CBUS
init|=
literal|1
block|,
name|CBUSII
init|=
literal|2
block|,
name|EISA
init|=
literal|3
block|,
name|MCA
init|=
literal|4
block|,
name|ISA
init|=
literal|6
block|,
name|PCI
init|=
literal|13
block|,
name|XPRESS
init|=
literal|18
block|,
name|MAX_BUSTYPE
init|=
literal|18
block|,
name|UNKNOWN_BUSTYPE
init|=
literal|0xff
block|}
enum|;
end_enum

begin_comment
comment|/*  * the physical/logical APIC ID management macors  */
end_comment

begin_define
define|#
directive|define
name|CPU_TO_ID
parameter_list|(
name|CPU
parameter_list|)
value|(cpu_num_to_apic_id[CPU])
end_define

begin_define
define|#
directive|define
name|ID_TO_CPU
parameter_list|(
name|ID
parameter_list|)
value|(apic_id_to_logical[ID])
end_define

begin_define
define|#
directive|define
name|IO_TO_ID
parameter_list|(
name|IO
parameter_list|)
value|(io_num_to_apic_id[IO])
end_define

begin_define
define|#
directive|define
name|ID_TO_IO
parameter_list|(
name|ID
parameter_list|)
value|(apic_id_to_logical[ID])
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_MPAPIC_H */
end_comment

end_unit

