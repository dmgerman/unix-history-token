begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) KATO Takenori, 1996.  All rights reserved.  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer as  *    the first lines of this file unmodified.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PC98_PC98_PC98_MACHDEP_H__
end_ifndef

begin_define
define|#
directive|define
name|__PC98_PC98_PC98_MACHDEP_H__
end_define

begin_decl_stmt
name|void
name|pc98_init_dmac
name|__P
argument_list|(
operator|(
name|void
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|unsigned
name|int
name|pc98_getmemsize
name|__P
argument_list|(
operator|(
name|unsigned
operator|*
operator|,
name|unsigned
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_struct_decl
struct_decl|struct
name|ccb_calc_geometry
struct_decl|;
end_struct_decl

begin_decl_stmt
name|int
name|scsi_da_bios_params
name|__P
argument_list|(
operator|(
expr|struct
name|ccb_calc_geometry
operator|*
operator|)
argument_list|)
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|PC98_VECTOR_SIZE
value|(0x400)
end_define

begin_define
define|#
directive|define
name|PC98_SYSTEM_PARAMETER_SIZE
value|(0x230)
end_define

begin_define
define|#
directive|define
name|PC98_SAVE_AREA
parameter_list|(
name|highreso_flag
parameter_list|)
value|(0xa1000)
end_define

begin_define
define|#
directive|define
name|PC98_SAVE_AREA_ADDRESS
value|(0x10)
end_define

begin_if
if|#
directive|if
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|&&
operator|!
name|defined
argument_list|(
name|LOCORE
argument_list|)
end_if

begin_comment
comment|/* BIOS parameter block */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|pc98_system_parameter
index|[]
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* in locore.c */
end_comment

begin_define
define|#
directive|define
name|OFS_BOOT_boothowto
value|0x210
end_define

begin_define
define|#
directive|define
name|OFS_BOOT_bootdev
value|0x214
end_define

begin_define
define|#
directive|define
name|OFS_BOOT_cyloffset
value|0x218
end_define

begin_define
define|#
directive|define
name|OFS_WD_BIOS_SECSIZE
parameter_list|(
name|i
parameter_list|)
value|(0x200+(i)*6)
end_define

begin_define
define|#
directive|define
name|OFS_WD_BIOS_NCYL
parameter_list|(
name|i
parameter_list|)
value|(0x202+(i)*6)
end_define

begin_define
define|#
directive|define
name|OFS_WD_BIOS_HEAD
parameter_list|(
name|i
parameter_list|)
value|(0x205+(i)*6)
end_define

begin_define
define|#
directive|define
name|OFS_WD_BIOS_SEC
parameter_list|(
name|i
parameter_list|)
value|(0x204+(i)*6)
end_define

begin_define
define|#
directive|define
name|OFS_pc98_machine_type
value|0x220
end_define

begin_define
define|#
directive|define
name|OFS_epson_machine_id
value|0x224
end_define

begin_define
define|#
directive|define
name|OFS_epson_bios_id
value|0x225
end_define

begin_define
define|#
directive|define
name|OFS_epson_system_type
value|0x226
end_define

begin_define
define|#
directive|define
name|PC98_SYSTEM_PARAMETER
parameter_list|(
name|x
parameter_list|)
value|pc98_system_parameter[(x)-0x400]
end_define

begin_define
define|#
directive|define
name|BOOT_boothowto
value|(*(unsigned long*)(&pc98_system_parameter[OFS_BOOT_boothowto]))
end_define

begin_define
define|#
directive|define
name|BOOT_bootdev
value|(*(unsigned long*)(&pc98_system_parameter[OFS_BOOT_bootdev]))
end_define

begin_define
define|#
directive|define
name|BOOT_cyloffset
value|(*(unsigned long*)(&pc98_system_parameter[OFS_BOOT_cyloffset]))
end_define

begin_define
define|#
directive|define
name|WD_BIOS_SECSIZE
parameter_list|(
name|i
parameter_list|)
value|(*(unsigned short*)(&pc98_system_parameter[OFS_WD_BIOS_SECSIZE(i)]))
end_define

begin_define
define|#
directive|define
name|WD_BIOS_NCYL
parameter_list|(
name|i
parameter_list|)
value|(*(unsigned short*)(&pc98_system_parameter[OFS_WD_BIOS_NCYL(i)]))
end_define

begin_define
define|#
directive|define
name|WD_BIOS_HEAD
parameter_list|(
name|i
parameter_list|)
value|(pc98_system_parameter[OFS_WD_BIOS_HEAD(i)])
end_define

begin_define
define|#
directive|define
name|WD_BIOS_SEC
parameter_list|(
name|i
parameter_list|)
value|(pc98_system_parameter[OFS_WD_BIOS_SEC(i)])
end_define

begin_define
define|#
directive|define
name|pc98_machine_type
value|(*(unsigned long*)&pc98_system_parameter[OFS_pc98_machine_type])
end_define

begin_define
define|#
directive|define
name|epson_machine_id
value|(pc98_system_parameter[OFS_epson_machine_id])
end_define

begin_define
define|#
directive|define
name|epson_bios_id
value|(pc98_system_parameter[OFS_epson_bios_id])
end_define

begin_define
define|#
directive|define
name|epson_system_type
value|(pc98_system_parameter[OFS_epson_system_type])
end_define

begin_define
define|#
directive|define
name|PC98_TYPE_CHECK
parameter_list|(
name|x
parameter_list|)
value|((pc98_machine_type& (x)) == (x))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PC98_PC98_PC98_MACHDEP_H__ */
end_comment

end_unit

