begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 2006-2008 Semihalf, Marian Balakowicz<m8@semihalf.com>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN  * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,  * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED  * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR  * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_MACHINE_BOOTINFO_H_
end_ifndef

begin_define
define|#
directive|define
name|_MACHINE_BOOTINFO_H_
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
end_if

begin_comment
comment|/* Platform hardware spec, received from loader(8) */
end_comment

begin_define
define|#
directive|define
name|BI_VERSION
value|1
end_define

begin_struct
struct|struct
name|bi_mem_region
block|{
name|vm_paddr_t
name|mem_base
decl_stmt|;
name|vm_size_t
name|mem_size
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bi_eth_addr
block|{
name|u_int8_t
name|mac_addr
index|[
literal|6
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|bootinfo
block|{
name|u_int32_t
name|bi_version
decl_stmt|;
name|vm_offset_t
name|bi_bar_base
decl_stmt|;
name|u_int32_t
name|bi_cpu_clk
decl_stmt|;
name|u_int32_t
name|bi_bus_clk
decl_stmt|;
name|u_int8_t
name|bi_mem_reg_no
decl_stmt|;
name|u_int8_t
name|bi_eth_addr_no
decl_stmt|;
name|u_int8_t
name|bi_data
index|[
literal|1
index|]
decl_stmt|;
comment|/* 	 * The bi_data container is allocated in run time and has the 	 * following layout: 	 * 	 * - bi_mem_reg_no elements of struct bi_mem_region 	 * - bi_eth_addr_no elements of struct bi_eth_addr 	 */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|struct
name|bootinfo
modifier|*
name|bootinfo
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _MACHINE_BOOTINFO_H_ */
end_comment

end_unit

