begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * SPDX-License-Identifier: BSD-3-Clause  *  * Copyright (c) 2007 The DragonFly Project.  All rights reserved.  *   * This code is derived from software contributed to The DragonFly Project  * by Sepherosa Ziehau<sepherosa@gmail.com>  *   * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  *   * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in  *    the documentation and/or other materials provided with the  *    distribution.  * 3. Neither the name of The DragonFly Project nor the names of its  *    contributors may be used to endorse or promote products derived  *    from this software without specific, prior written permission.  *   * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS  * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE  * COPYRIGHT HOLDERS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT  * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *   * $DragonFly: src/sys/dev/netif/bwi/bwimac.h,v 1.2 2008/02/15 11:15:38 sephe Exp $  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BWI_MAC_H
end_ifndef

begin_define
define|#
directive|define
name|_BWI_MAC_H
end_define

begin_function_decl
name|int
name|bwi_mac_attach
parameter_list|(
name|struct
name|bwi_softc
modifier|*
parameter_list|,
name|int
parameter_list|,
name|uint8_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bwi_mac_lateattach
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_mac_detach
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bwi_mac_init
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_mac_reset
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bwi_mac_start
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bwi_mac_stop
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_mac_shutdown
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_mac_updateslot
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_mac_set_promisc
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_mac_calibrate_txpower
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|,
name|enum
name|bwi_txpwrcb_type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_mac_set_tpctl_11bg
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|,
specifier|const
name|struct
name|bwi_tpctl
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_mac_init_tpctl_11bg
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_mac_dummy_xmit
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_mac_reset_hwkeys
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bwi_mac_config_ps
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|bwi_mac_fw_alloc
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint16_t
name|bwi_memobj_read_2
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|,
name|uint16_t
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|bwi_memobj_read_4
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|,
name|uint16_t
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_memobj_write_2
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|,
name|uint16_t
parameter_list|,
name|uint16_t
parameter_list|,
name|uint16_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_memobj_write_4
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|,
name|uint16_t
parameter_list|,
name|uint16_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_tmplt_write_4
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|,
name|uint32_t
parameter_list|,
name|uint32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|bwi_hostflags_write
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|,
name|uint64_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint64_t
name|bwi_hostflags_read
parameter_list|(
name|struct
name|bwi_mac
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|MOBJ_WRITE_2
parameter_list|(
name|mac
parameter_list|,
name|objid
parameter_list|,
name|ofs
parameter_list|,
name|val
parameter_list|)
define|\
value|bwi_memobj_write_2((mac), (objid), (ofs), (val))
end_define

begin_define
define|#
directive|define
name|MOBJ_WRITE_4
parameter_list|(
name|mac
parameter_list|,
name|objid
parameter_list|,
name|ofs
parameter_list|,
name|val
parameter_list|)
define|\
value|bwi_memobj_write_4((mac), (objid), (ofs), (val))
end_define

begin_define
define|#
directive|define
name|MOBJ_READ_2
parameter_list|(
name|mac
parameter_list|,
name|objid
parameter_list|,
name|ofs
parameter_list|)
define|\
value|bwi_memobj_read_2((mac), (objid), (ofs))
end_define

begin_define
define|#
directive|define
name|MOBJ_READ_4
parameter_list|(
name|mac
parameter_list|,
name|objid
parameter_list|,
name|ofs
parameter_list|)
define|\
value|bwi_memobj_read_4((mac), (objid), (ofs))
end_define

begin_define
define|#
directive|define
name|MOBJ_SETBITS_4
parameter_list|(
name|mac
parameter_list|,
name|objid
parameter_list|,
name|ofs
parameter_list|,
name|bits
parameter_list|)
define|\
value|MOBJ_WRITE_4((mac), (objid), (ofs),	\ 		     MOBJ_READ_4((mac), (objid), (ofs)) | (bits))
end_define

begin_define
define|#
directive|define
name|MOBJ_CLRBITS_4
parameter_list|(
name|mac
parameter_list|,
name|objid
parameter_list|,
name|ofs
parameter_list|,
name|bits
parameter_list|)
define|\
value|MOBJ_WRITE_4((mac), (objid), (ofs),	\ 		     MOBJ_READ_4((mac), (objid), (ofs))& ~(bits))
end_define

begin_define
define|#
directive|define
name|MOBJ_FILT_SETBITS_2
parameter_list|(
name|mac
parameter_list|,
name|objid
parameter_list|,
name|ofs
parameter_list|,
name|filt
parameter_list|,
name|bits
parameter_list|)
define|\
value|MOBJ_WRITE_2((mac), (objid), (ofs),	\ 		     (MOBJ_READ_2((mac), (objid), (ofs))& (filt)) | (bits))
end_define

begin_define
define|#
directive|define
name|TMPLT_WRITE_4
parameter_list|(
name|mac
parameter_list|,
name|ofs
parameter_list|,
name|val
parameter_list|)
value|bwi_tmplt_write_4((mac), (ofs), (val))
end_define

begin_define
define|#
directive|define
name|HFLAGS_WRITE
parameter_list|(
name|mac
parameter_list|,
name|flags
parameter_list|)
value|bwi_hostflags_write((mac), (flags))
end_define

begin_define
define|#
directive|define
name|HFLAGS_READ
parameter_list|(
name|mac
parameter_list|)
value|bwi_hostflags_read((mac))
end_define

begin_define
define|#
directive|define
name|HFLAGS_CLRBITS
parameter_list|(
name|mac
parameter_list|,
name|bits
parameter_list|)
define|\
value|HFLAGS_WRITE((mac), HFLAGS_READ((mac)) | (bits))
end_define

begin_define
define|#
directive|define
name|HFLAGS_SETBITS
parameter_list|(
name|mac
parameter_list|,
name|bits
parameter_list|)
define|\
value|HFLAGS_WRITE((mac), HFLAGS_READ((mac))& ~(bits))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !_BWI_MAC_H */
end_comment

end_unit

