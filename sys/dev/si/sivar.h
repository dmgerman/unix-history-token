begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Device driver for Specialix range (SI/XIO) of serial line multiplexors.  *  * Copyright (C) 2000, Peter Wemm<peter@netplex.com.au>  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notices, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notices, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY ``AS IS'' AND ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN  * NO EVENT SHALL THE AUTHORS BE LIABLE.  *  * $FreeBSD$  */
end_comment

begin_function_decl
name|int
name|siattach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|si_intr
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_decl_stmt
specifier|extern
name|devclass_t
name|si_devclass
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* where the firmware lives; defined in si2_z280.c and si3_t225.c */
end_comment

begin_comment
comment|/* old: si2_z280.c */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|si2_z280_download
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|si2_z280_downloadaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|si2_z280_dsize
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* new: si3_t225.c */
end_comment

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|si3_t225_download
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|si3_t225_downloadaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|si3_t225_dsize
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|char
name|si3_t225_bootstrap
index|[]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|unsigned
name|short
name|si3_t225_bootloadaddr
decl_stmt|;
end_decl_stmt

begin_decl_stmt
specifier|extern
name|int
name|si3_t225_bsize
decl_stmt|;
end_decl_stmt

begin_struct
struct|struct
name|si_softc
block|{
name|int
name|sc_type
decl_stmt|;
comment|/* adapter type */
name|char
modifier|*
name|sc_typename
decl_stmt|;
comment|/* adapter type string */
name|struct
name|si_port
modifier|*
name|sc_ports
decl_stmt|;
comment|/* port structures for this card */
name|caddr_t
name|sc_paddr
decl_stmt|;
comment|/* physical addr of iomem */
name|caddr_t
name|sc_maddr
decl_stmt|;
comment|/* kvaddr of iomem */
name|int
name|sc_nport
decl_stmt|;
comment|/* # ports on this card */
name|int
name|sc_irq
decl_stmt|;
comment|/* copy of attach irq */
name|int
name|sc_iobase
decl_stmt|;
comment|/* EISA io port address */
name|struct
name|resource
modifier|*
name|sc_port_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_irq_res
decl_stmt|;
name|struct
name|resource
modifier|*
name|sc_mem_res
decl_stmt|;
name|int
name|sc_port_rid
decl_stmt|;
name|int
name|sc_irq_rid
decl_stmt|;
name|int
name|sc_mem_rid
decl_stmt|;
name|int
name|sc_memsize
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|SI_DEBUG
end_ifdef

begin_comment
comment|/*  * debugging stuff - manipulated using siconfig(8)  */
end_comment

begin_function_decl
name|void
name|si_dprintf
parameter_list|(
name|struct
name|si_port
modifier|*
name|pp
parameter_list|,
name|int
name|flags
parameter_list|,
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|DPRINT
parameter_list|(
name|x
parameter_list|)
value|si_dprintf x
end_define

begin_define
define|#
directive|define
name|DBG_ENTRY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|DBG_DRAIN
value|0x00000002
end_define

begin_define
define|#
directive|define
name|DBG_OPEN
value|0x00000004
end_define

begin_define
define|#
directive|define
name|DBG_CLOSE
value|0x00000008
end_define

begin_define
define|#
directive|define
name|DBG_READ
value|0x00000010
end_define

begin_define
define|#
directive|define
name|DBG_WRITE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|DBG_PARAM
value|0x00000040
end_define

begin_define
define|#
directive|define
name|DBG_INTR
value|0x00000080
end_define

begin_define
define|#
directive|define
name|DBG_IOCTL
value|0x00000100
end_define

begin_comment
comment|/*				0x00000200 */
end_comment

begin_define
define|#
directive|define
name|DBG_SELECT
value|0x00000400
end_define

begin_define
define|#
directive|define
name|DBG_OPTIM
value|0x00000800
end_define

begin_define
define|#
directive|define
name|DBG_START
value|0x00001000
end_define

begin_define
define|#
directive|define
name|DBG_EXIT
value|0x00002000
end_define

begin_define
define|#
directive|define
name|DBG_FAIL
value|0x00004000
end_define

begin_define
define|#
directive|define
name|DBG_STOP
value|0x00008000
end_define

begin_define
define|#
directive|define
name|DBG_AUTOBOOT
value|0x00010000
end_define

begin_define
define|#
directive|define
name|DBG_MODEM
value|0x00020000
end_define

begin_define
define|#
directive|define
name|DBG_DOWNLOAD
value|0x00040000
end_define

begin_define
define|#
directive|define
name|DBG_LSTART
value|0x00080000
end_define

begin_define
define|#
directive|define
name|DBG_POLL
value|0x00100000
end_define

begin_define
define|#
directive|define
name|DBG_ALL
value|0xffffffff
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DPRINT
parameter_list|(
name|x
parameter_list|)
end_define

begin_comment
comment|/* void */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* Adapter types */
end_comment

begin_define
define|#
directive|define
name|SIEMPTY
value|0
end_define

begin_define
define|#
directive|define
name|SIHOST
value|1
end_define

begin_define
define|#
directive|define
name|SIMCA
value|2
end_define

begin_define
define|#
directive|define
name|SIHOST2
value|3
end_define

begin_define
define|#
directive|define
name|SIEISA
value|4
end_define

begin_define
define|#
directive|define
name|SIPCI
value|5
end_define

begin_define
define|#
directive|define
name|SIJETPCI
value|6
end_define

begin_define
define|#
directive|define
name|SIJETISA
value|7
end_define

begin_define
define|#
directive|define
name|SI_ISJET
parameter_list|(
name|x
parameter_list|)
value|(((x) == SIJETPCI) || ((x) == SIJETISA))
end_define

end_unit

