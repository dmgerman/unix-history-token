begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (C) 1994 by Rodney W. Grimes, Milwaukie, Oregon  97222  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgement:  *	This product includes software developed by Rodney W. Grimes.  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY RODNEY W. GRIMES ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL RODNEY W. GRIMES BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
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

begin_comment
comment|/* Only change the version number if you break compatibility. */
end_comment

begin_define
define|#
directive|define
name|BOOTINFO_VERSION
value|1
end_define

begin_define
define|#
directive|define
name|N_BIOS_GEOM
value|8
end_define

begin_comment
comment|/*  * A zero bootinfo field often means that there is no info available.  * Flags are used to indicate the validity of fields where zero is a  * normal value.  */
end_comment

begin_struct
struct|struct
name|bootinfo
block|{
name|u_int32_t
name|bi_version
decl_stmt|;
name|u_int32_t
name|bi_kernelname
decl_stmt|;
comment|/* represents a char * */
name|u_int32_t
name|bi_nfs_diskless
decl_stmt|;
comment|/* struct nfs_diskless * */
comment|/* End of fields that are always present. */
define|#
directive|define
name|bi_endcommon
value|bi_n_bios_used
name|u_int32_t
name|bi_n_bios_used
decl_stmt|;
name|u_int32_t
name|bi_bios_geom
index|[
name|N_BIOS_GEOM
index|]
decl_stmt|;
name|u_int32_t
name|bi_size
decl_stmt|;
name|u_int8_t
name|bi_memsizes_valid
decl_stmt|;
name|u_int8_t
name|bi_bios_dev
decl_stmt|;
comment|/* bootdev BIOS unit number */
name|u_int8_t
name|bi_pad
index|[
literal|2
index|]
decl_stmt|;
name|u_int32_t
name|bi_basemem
decl_stmt|;
name|u_int32_t
name|bi_extmem
decl_stmt|;
name|u_int32_t
name|bi_symtab
decl_stmt|;
comment|/* struct symtab * */
name|u_int32_t
name|bi_esymtab
decl_stmt|;
comment|/* struct symtab * */
comment|/* Items below only from advanced bootloader */
name|u_int32_t
name|bi_kernend
decl_stmt|;
comment|/* end of kernel space */
name|u_int32_t
name|bi_envp
decl_stmt|;
comment|/* environment */
name|u_int32_t
name|bi_modulep
decl_stmt|;
comment|/* preloaded modules */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_decl_stmt
specifier|extern
name|struct
name|bootinfo
name|bootinfo
decl_stmt|;
end_decl_stmt

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Constants for converting boot-style device number to type,  * adaptor (uba, mba, etc), unit number and partition number.  * Type (== major device number) is in the low byte  * for backward compatibility.  Except for that of the "magic  * number", each mask applies to the shifted value.  * Format:  *	 (4) (4) (4) (4)  (8)     (8)  *	--------------------------------  *	|MA | AD| CT| UN| PART  | TYPE |  *	--------------------------------  */
end_comment

begin_define
define|#
directive|define
name|B_ADAPTORSHIFT
value|24
end_define

begin_define
define|#
directive|define
name|B_ADAPTORMASK
value|0x0f
end_define

begin_define
define|#
directive|define
name|B_ADAPTOR
parameter_list|(
name|val
parameter_list|)
value|(((val)>> B_ADAPTORSHIFT)& B_ADAPTORMASK)
end_define

begin_define
define|#
directive|define
name|B_CONTROLLERSHIFT
value|20
end_define

begin_define
define|#
directive|define
name|B_CONTROLLERMASK
value|0xf
end_define

begin_define
define|#
directive|define
name|B_CONTROLLER
parameter_list|(
name|val
parameter_list|)
value|(((val)>>B_CONTROLLERSHIFT)& B_CONTROLLERMASK)
end_define

begin_define
define|#
directive|define
name|B_SLICESHIFT
value|20
end_define

begin_define
define|#
directive|define
name|B_SLICEMASK
value|0xff
end_define

begin_define
define|#
directive|define
name|B_SLICE
parameter_list|(
name|val
parameter_list|)
value|(((val)>>B_SLICESHIFT)& B_SLICEMASK)
end_define

begin_define
define|#
directive|define
name|B_UNITSHIFT
value|16
end_define

begin_define
define|#
directive|define
name|B_UNITMASK
value|0xf
end_define

begin_define
define|#
directive|define
name|B_UNIT
parameter_list|(
name|val
parameter_list|)
value|(((val)>> B_UNITSHIFT)& B_UNITMASK)
end_define

begin_define
define|#
directive|define
name|B_PARTITIONSHIFT
value|8
end_define

begin_define
define|#
directive|define
name|B_PARTITIONMASK
value|0xff
end_define

begin_define
define|#
directive|define
name|B_PARTITION
parameter_list|(
name|val
parameter_list|)
value|(((val)>> B_PARTITIONSHIFT)& B_PARTITIONMASK)
end_define

begin_define
define|#
directive|define
name|B_TYPESHIFT
value|0
end_define

begin_define
define|#
directive|define
name|B_TYPEMASK
value|0xff
end_define

begin_define
define|#
directive|define
name|B_TYPE
parameter_list|(
name|val
parameter_list|)
value|(((val)>> B_TYPESHIFT)& B_TYPEMASK)
end_define

begin_define
define|#
directive|define
name|B_MAGICMASK
value|0xf0000000
end_define

begin_define
define|#
directive|define
name|B_DEVMAGIC
value|0xa0000000
end_define

begin_define
define|#
directive|define
name|MAKEBOOTDEV
parameter_list|(
name|type
parameter_list|,
name|adaptor
parameter_list|,
name|controller
parameter_list|,
name|unit
parameter_list|,
name|partition
parameter_list|)
define|\
value|(((type)<< B_TYPESHIFT) | ((adaptor)<< B_ADAPTORSHIFT) | \ 	((controller)<< B_CONTROLLERSHIFT) | ((unit)<< B_UNITSHIFT) | \ 	((partition)<< B_PARTITIONSHIFT) | B_DEVMAGIC)
end_define

begin_define
define|#
directive|define
name|BASE_SLICE
value|2
end_define

begin_define
define|#
directive|define
name|COMPATIBILITY_SLICE
value|0
end_define

begin_define
define|#
directive|define
name|MAX_SLICES
value|32
end_define

begin_define
define|#
directive|define
name|WHOLE_DISK_SLICE
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_MACHINE_BOOTINFO_H_ */
end_comment

end_unit

