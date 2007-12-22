begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003  *	Fraunhofer Institute for Open Communication Systems (FhG Fokus).  * 	All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * Author: Hartmut Brandt<harti@freebsd.org>  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_DEV_UTOPIA_UTOPIA_H
end_ifndef

begin_define
define|#
directive|define
name|_DEV_UTOPIA_UTOPIA_H
end_define

begin_comment
comment|/* Structure for user-level register formatting */
end_comment

begin_struct
struct|struct
name|utopia_print
block|{
name|uint8_t
name|type
decl_stmt|;
comment|/* register type */
name|uint8_t
name|reg
decl_stmt|;
comment|/* register number */
specifier|const
name|char
modifier|*
name|name
decl_stmt|;
comment|/* register name */
specifier|const
name|char
modifier|*
name|fmt
decl_stmt|;
comment|/* format for printing */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Types of registers  */
end_comment

begin_define
define|#
directive|define
name|UTP_REGT_BITS
value|0x0
end_define

begin_comment
comment|/* use printb to print */
end_comment

begin_define
define|#
directive|define
name|UTP_REGT_INT8
value|0x1
end_define

begin_comment
comment|/* 8 bit hex number */
end_comment

begin_define
define|#
directive|define
name|UTP_REGT_INT10BITS
value|0x2
end_define

begin_comment
comment|/* 10 bit hex number + 6 bit printb */
end_comment

begin_define
define|#
directive|define
name|UTP_REGT_INT12
value|0x3
end_define

begin_comment
comment|/* 12 bit LE hex */
end_comment

begin_define
define|#
directive|define
name|UTP_REGT_INT16
value|0x4
end_define

begin_comment
comment|/* 16 bit LE hex */
end_comment

begin_define
define|#
directive|define
name|UTP_REGT_INT19
value|0x5
end_define

begin_comment
comment|/* 19 bit LE hex */
end_comment

begin_define
define|#
directive|define
name|UTP_REGT_INT20
value|0x6
end_define

begin_comment
comment|/* 20 bit LE hex */
end_comment

begin_define
define|#
directive|define
name|UTP_REGT_INT21
value|0x7
end_define

begin_comment
comment|/* 21 bit LE hex */
end_comment

begin_define
define|#
directive|define
name|UTP_REGT_INT18
value|0x8
end_define

begin_comment
comment|/* 18 bit LE hex */
end_comment

begin_comment
comment|/* number of additional registers per type */
end_comment

begin_define
define|#
directive|define
name|UTP_REG_ADD
value|0, 0, 1, 1, 1, 2, 2, 2, 2
end_define

begin_comment
comment|/* flags field */
end_comment

begin_define
define|#
directive|define
name|UTP_FL_NORESET
value|0x0001
end_define

begin_comment
comment|/* cannot write MRESET register */
end_comment

begin_define
define|#
directive|define
name|UTP_FL_POLL_CARRIER
value|0x0002
end_define

begin_comment
comment|/* need to poll for carrier */
end_comment

begin_comment
comment|/* state field */
end_comment

begin_define
define|#
directive|define
name|UTP_ST_ACTIVE
value|0x0001
end_define

begin_comment
comment|/* registers accessible */
end_comment

begin_define
define|#
directive|define
name|UTP_ST_SDH
value|0x0002
end_define

begin_comment
comment|/* SDH or SONET */
end_comment

begin_define
define|#
directive|define
name|UTP_ST_UNASS
value|0x0004
end_define

begin_comment
comment|/* produce unassigned cells */
end_comment

begin_define
define|#
directive|define
name|UTP_ST_NOSCRAMB
value|0x0008
end_define

begin_comment
comment|/* no scrambling */
end_comment

begin_define
define|#
directive|define
name|UTP_ST_DETACH
value|0x0010
end_define

begin_comment
comment|/* detaching */
end_comment

begin_define
define|#
directive|define
name|UTP_ST_ATTACHED
value|0x0020
end_define

begin_comment
comment|/* successful attached */
end_comment

begin_comment
comment|/* carrier field */
end_comment

begin_define
define|#
directive|define
name|UTP_CARR_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|UTP_CARR_OK
value|1
end_define

begin_define
define|#
directive|define
name|UTP_CARR_LOST
value|2
end_define

begin_comment
comment|/* loopback field */
end_comment

begin_define
define|#
directive|define
name|UTP_LOOP_NONE
value|0x0000
end_define

begin_define
define|#
directive|define
name|UTP_LOOP_TIME
value|0x0001
end_define

begin_comment
comment|/* timing source loopback */
end_comment

begin_define
define|#
directive|define
name|UTP_LOOP_DIAG
value|0x0002
end_define

begin_comment
comment|/* diagnostic loopback */
end_comment

begin_define
define|#
directive|define
name|UTP_LOOP_LINE
value|0x0004
end_define

begin_comment
comment|/* serial line loopback */
end_comment

begin_define
define|#
directive|define
name|UTP_LOOP_PARAL
value|0x0008
end_define

begin_comment
comment|/* parallel diagnostic loopback */
end_comment

begin_define
define|#
directive|define
name|UTP_LOOP_TWIST
value|0x0010
end_define

begin_comment
comment|/* twisted pair diagnostic loopback */
end_comment

begin_define
define|#
directive|define
name|UTP_LOOP_PATH
value|0x0020
end_define

begin_comment
comment|/* diagnostic path loopback */
end_comment

begin_comment
comment|/* type */
end_comment

begin_define
define|#
directive|define
name|UTP_TYPE_UNKNOWN
value|0
end_define

begin_define
define|#
directive|define
name|UTP_TYPE_SUNI_LITE
value|1
end_define

begin_define
define|#
directive|define
name|UTP_TYPE_SUNI_ULTRA
value|2
end_define

begin_define
define|#
directive|define
name|UTP_TYPE_SUNI_622
value|3
end_define

begin_define
define|#
directive|define
name|UTP_TYPE_IDT77105
value|4
end_define

begin_define
define|#
directive|define
name|UTP_TYPE_IDT77155
value|5
end_define

begin_define
define|#
directive|define
name|UTP_TYPE_CX28250
value|6
end_define

begin_comment
comment|/*  * Statistics. These structures are versioned.  */
end_comment

begin_struct
struct|struct
name|utopia_stats1
block|{
name|uint32_t
name|version
decl_stmt|;
comment|/* version of this statistics struct */
name|uint32_t
name|fill
decl_stmt|;
name|uint64_t
name|rx_sbip
decl_stmt|;
comment|/* rx section BIP errors */
name|uint64_t
name|rx_lbip
decl_stmt|;
comment|/* rx line BIP errors */
name|uint64_t
name|rx_lfebe
decl_stmt|;
comment|/* rx line far end block errors */
name|uint64_t
name|rx_pbip
decl_stmt|;
comment|/* rx path BIP errors */
name|uint64_t
name|rx_pfebe
decl_stmt|;
comment|/* rx path far end block errors */
name|uint64_t
name|rx_cells
decl_stmt|;
comment|/* received cells */
name|uint64_t
name|rx_corr
decl_stmt|;
comment|/* correctable cell errors */
name|uint64_t
name|rx_uncorr
decl_stmt|;
comment|/* uncorrectable cell errors */
name|uint64_t
name|rx_symerr
decl_stmt|;
comment|/* symbol errors */
name|uint64_t
name|tx_cells
decl_stmt|;
comment|/* transmitted cells */
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_comment
comment|/*  * These must be implemented by the card driver  */
end_comment

begin_struct
struct|struct
name|utopia_methods
block|{
comment|/* read at most n PHY registers starting at reg into val */
name|int
function_decl|(
modifier|*
name|readregs
function_decl|)
parameter_list|(
name|struct
name|ifatm
modifier|*
parameter_list|,
name|u_int
name|reg
parameter_list|,
name|uint8_t
modifier|*
name|val
parameter_list|,
name|u_int
modifier|*
name|n
parameter_list|)
function_decl|;
comment|/* change the bits given by mask to them in val in register reg */
name|int
function_decl|(
modifier|*
name|writereg
function_decl|)
parameter_list|(
name|struct
name|ifatm
modifier|*
parameter_list|,
name|u_int
name|reg
parameter_list|,
name|u_int
name|mask
parameter_list|,
name|u_int
name|val
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Public state  */
end_comment

begin_struct
struct|struct
name|utopia
block|{
name|struct
name|ifatm
modifier|*
name|ifatm
decl_stmt|;
comment|/* driver data */
name|struct
name|ifmedia
modifier|*
name|media
decl_stmt|;
comment|/* driver supplied */
name|struct
name|mtx
modifier|*
name|lock
decl_stmt|;
comment|/* driver supplied */
specifier|const
name|struct
name|utopia_methods
modifier|*
name|methods
decl_stmt|;
name|LIST_ENTRY
argument_list|(
argument|utopia
argument_list|)
name|link
expr_stmt|;
comment|/* list of these structures */
name|u_int
name|flags
decl_stmt|;
comment|/* flags set by the driver */
name|u_int
name|state
decl_stmt|;
comment|/* current state */
name|u_int
name|carrier
decl_stmt|;
comment|/* carrier state */
name|u_int
name|loopback
decl_stmt|;
comment|/* loopback mode */
specifier|const
name|struct
name|utopia_chip
modifier|*
name|chip
decl_stmt|;
comment|/* chip operations */
name|struct
name|utopia_stats1
name|stats
decl_stmt|;
comment|/* statistics */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|utopia_chip
block|{
comment|/* type and name of the chip */
name|u_int
name|type
decl_stmt|;
specifier|const
name|char
modifier|*
specifier|const
name|name
decl_stmt|;
comment|/* number of registers */
name|u_int
name|nregs
decl_stmt|;
comment|/* reset chip to known state */
name|int
function_decl|(
modifier|*
name|reset
function_decl|)
parameter_list|(
name|struct
name|utopia
modifier|*
parameter_list|)
function_decl|;
comment|/* set SONET/SDH mode */
name|int
function_decl|(
modifier|*
name|set_sdh
function_decl|)
parameter_list|(
name|struct
name|utopia
modifier|*
parameter_list|,
name|int
name|sdh
parameter_list|)
function_decl|;
comment|/* set idle/unassigned cells */
name|int
function_decl|(
modifier|*
name|set_unass
function_decl|)
parameter_list|(
name|struct
name|utopia
modifier|*
parameter_list|,
name|int
name|unass
parameter_list|)
function_decl|;
comment|/* enable/disable scrambling */
name|int
function_decl|(
modifier|*
name|set_noscramb
function_decl|)
parameter_list|(
name|struct
name|utopia
modifier|*
parameter_list|,
name|int
name|noscramb
parameter_list|)
function_decl|;
comment|/* update carrier status */
name|int
function_decl|(
modifier|*
name|update_carrier
function_decl|)
parameter_list|(
name|struct
name|utopia
modifier|*
parameter_list|)
function_decl|;
comment|/* set loopback mode */
name|int
function_decl|(
modifier|*
name|set_loopback
function_decl|)
parameter_list|(
name|struct
name|utopia
modifier|*
parameter_list|,
name|u_int
name|mode
parameter_list|)
function_decl|;
comment|/* handle interrupt */
name|void
function_decl|(
modifier|*
name|intr
function_decl|)
parameter_list|(
name|struct
name|utopia
modifier|*
parameter_list|)
function_decl|;
comment|/* update statistics */
name|void
function_decl|(
modifier|*
name|update_stats
function_decl|)
parameter_list|(
name|struct
name|utopia
modifier|*
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * These are implemented in the common utopia code  */
end_comment

begin_function_decl
name|int
name|utopia_attach
parameter_list|(
name|struct
name|utopia
modifier|*
parameter_list|,
name|struct
name|ifatm
modifier|*
parameter_list|,
name|struct
name|ifmedia
modifier|*
parameter_list|,
name|struct
name|mtx
modifier|*
parameter_list|,
name|struct
name|sysctl_ctx_list
modifier|*
parameter_list|,
name|struct
name|sysctl_oid_list
modifier|*
parameter_list|,
specifier|const
name|struct
name|utopia_methods
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|utopia_detach
parameter_list|(
name|struct
name|utopia
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|utopia_start
parameter_list|(
name|struct
name|utopia
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|utopia_stop
parameter_list|(
name|struct
name|utopia
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|utopia_init_media
parameter_list|(
name|struct
name|utopia
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|utopia_reset_media
parameter_list|(
name|struct
name|utopia
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|utopia_reset
parameter_list|(
name|S
parameter_list|)
value|((S)->chip->reset((S)))
end_define

begin_define
define|#
directive|define
name|utopia_set_sdh
parameter_list|(
name|S
parameter_list|,
name|SDH
parameter_list|)
value|((S)->chip->set_sdh((S), (SDH)))
end_define

begin_define
define|#
directive|define
name|utopia_set_unass
parameter_list|(
name|S
parameter_list|,
name|U
parameter_list|)
value|((S)->chip->set_unass((S), (U)))
end_define

begin_define
define|#
directive|define
name|utopia_set_noscramb
parameter_list|(
name|S
parameter_list|,
name|N
parameter_list|)
value|((S)->chip->set_noscramb((S), (N)))
end_define

begin_define
define|#
directive|define
name|utopia_update_carrier
parameter_list|(
name|S
parameter_list|)
value|((S)->chip->update_carrier((S)))
end_define

begin_define
define|#
directive|define
name|utopia_update_stats
parameter_list|(
name|S
parameter_list|)
value|((S)->chip->update_stats((S)))
end_define

begin_define
define|#
directive|define
name|utopia_set_loopback
parameter_list|(
name|S
parameter_list|,
name|L
parameter_list|)
value|((S)->chip->set_loopback((S), (L)))
end_define

begin_define
define|#
directive|define
name|utopia_intr
parameter_list|(
name|S
parameter_list|)
value|((S)->chip->intr((S)))
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
comment|/* _DEV_UTOPIA_UTOPIA_H */
end_comment

end_unit

