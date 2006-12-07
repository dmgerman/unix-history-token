begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2006 Broadcom Corporation  *	David Christensen<davidch@broadcom.com>.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. Neither the name of Broadcom Corporation nor the name of its contributors  *    may be used to endorse or promote products derived from this software  *    without specific prior written consent.  *  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS'  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS  * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR  * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF  * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS  * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN  * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)  * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF  * THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BCE_H_DEFINED
end_ifndef

begin_define
define|#
directive|define
name|_BCE_H_DEFINED
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_KERNEL_OPTION_HEADERS
end_ifdef

begin_include
include|#
directive|include
file|"opt_device_polling.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/endian.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
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
file|<sys/module.h>
end_include

begin_include
include|#
directive|include
file|<sys/socket.h>
end_include

begin_include
include|#
directive|include
file|<sys/sysctl.h>
end_include

begin_include
include|#
directive|include
file|<sys/queue.h>
end_include

begin_include
include|#
directive|include
file|<net/if.h>
end_include

begin_include
include|#
directive|include
file|<net/if_arp.h>
end_include

begin_include
include|#
directive|include
file|<net/ethernet.h>
end_include

begin_include
include|#
directive|include
file|<net/if_dl.h>
end_include

begin_include
include|#
directive|include
file|<net/if_media.h>
end_include

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<net/if_types.h>
end_include

begin_include
include|#
directive|include
file|<net/if_vlan_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_comment
comment|/* for DELAY */
end_comment

begin_include
include|#
directive|include
file|<machine/bus_memio.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
end_include

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<dev/mii/mii.h>
end_include

begin_include
include|#
directive|include
file|<dev/mii/miivar.h>
end_include

begin_include
include|#
directive|include
file|<dev/mii/brgphyreg.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|"miibus_if.h"
end_include

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Conversion to FreeBSD type definitions.                                  */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|u64
value|uint64_t
end_define

begin_define
define|#
directive|define
name|u32
value|uint32_t
end_define

begin_define
define|#
directive|define
name|u16
value|uint16_t
end_define

begin_define
define|#
directive|define
name|u8
value|uint8_t
end_define

begin_if
if|#
directive|if
name|BYTE_ORDER
operator|==
name|BIG_ENDIAN
end_if

begin_define
define|#
directive|define
name|__BIG_ENDIAN
value|1
end_define

begin_undef
undef|#
directive|undef
name|__LITTLE_ENDIAN
end_undef

begin_else
else|#
directive|else
end_else

begin_undef
undef|#
directive|undef
name|__BIG_ENDIAN
end_undef

begin_define
define|#
directive|define
name|__LITTLE_ENDIAN
value|1
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Debugging macros and definitions.                                        */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|BCE_CP_LOAD
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BCE_CP_SEND
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BCE_CP_RECV
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BCE_CP_INTR
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BCE_CP_UNLOAD
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BCE_CP_RESET
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BCE_CP_ALL
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|BCE_CP_MASK
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|BCE_LEVEL_FATAL
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BCE_LEVEL_WARN
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BCE_LEVEL_INFO
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BCE_LEVEL_VERBOSE
value|0x03000000
end_define

begin_define
define|#
directive|define
name|BCE_LEVEL_EXCESSIVE
value|0x04000000
end_define

begin_define
define|#
directive|define
name|BCE_LEVEL_MASK
value|0xFF000000
end_define

begin_define
define|#
directive|define
name|BCE_WARN_LOAD
value|(BCE_CP_LOAD | BCE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BCE_INFO_LOAD
value|(BCE_CP_LOAD | BCE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BCE_VERBOSE_LOAD
value|(BCE_CP_LOAD | BCE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BCE_EXCESSIVE_LOAD
value|(BCE_CP_LOAD | BCE_LEVEL_EXCESSIVE)
end_define

begin_define
define|#
directive|define
name|BCE_WARN_SEND
value|(BCE_CP_SEND | BCE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BCE_INFO_SEND
value|(BCE_CP_SEND | BCE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BCE_VERBOSE_SEND
value|(BCE_CP_SEND | BCE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BCE_EXCESSIVE_SEND
value|(BCE_CP_SEND | BCE_LEVEL_EXCESSIVE)
end_define

begin_define
define|#
directive|define
name|BCE_WARN_RECV
value|(BCE_CP_RECV | BCE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BCE_INFO_RECV
value|(BCE_CP_RECV | BCE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BCE_VERBOSE_RECV
value|(BCE_CP_RECV | BCE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BCE_EXCESSIVE_RECV
value|(BCE_CP_RECV | BCE_LEVEL_EXCESSIVE)
end_define

begin_define
define|#
directive|define
name|BCE_WARN_INTR
value|(BCE_CP_INTR | BCE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BCE_INFO_INTR
value|(BCE_CP_INTR | BCE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BCE_VERBOSE_INTR
value|(BCE_CP_INTR | BCE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BCE_EXCESSIVE_INTR
value|(BCE_CP_INTR | BCE_LEVEL_EXCESSIVE)
end_define

begin_define
define|#
directive|define
name|BCE_WARN_UNLOAD
value|(BCE_CP_UNLOAD | BCE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BCE_INFO_UNLOAD
value|(BCE_CP_UNLOAD | BCE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BCE_VERBOSE_UNLOAD
value|(BCE_CP_UNLOAD | BCE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BCE_EXCESSIVE_UNLOAD
value|(BCE_CP_UNLOAD | BCE_LEVEL_EXCESSIVE)
end_define

begin_define
define|#
directive|define
name|BCE_WARN_RESET
value|(BCE_CP_RESET | BCE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BCE_INFO_RESET
value|(BCE_CP_RESET | BCE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BCE_VERBOSE_RESET
value|(BCE_CP_RESET | BCE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BCE_EXCESSIVE_RESET
value|(BCE_CP_RESET | BCE_LEVEL_EXCESSIVE)
end_define

begin_define
define|#
directive|define
name|BCE_FATAL
value|(BCE_CP_ALL | BCE_LEVEL_FATAL)
end_define

begin_define
define|#
directive|define
name|BCE_WARN
value|(BCE_CP_ALL | BCE_LEVEL_WARN)
end_define

begin_define
define|#
directive|define
name|BCE_INFO
value|(BCE_CP_ALL | BCE_LEVEL_INFO)
end_define

begin_define
define|#
directive|define
name|BCE_VERBOSE
value|(BCE_CP_ALL | BCE_LEVEL_VERBOSE)
end_define

begin_define
define|#
directive|define
name|BCE_EXCESSIVE
value|(BCE_CP_ALL | BCE_LEVEL_EXCESSIVE)
end_define

begin_define
define|#
directive|define
name|BCE_CODE_PATH
parameter_list|(
name|cp
parameter_list|)
value|((cp& BCE_CP_MASK)& bce_debug)
end_define

begin_define
define|#
directive|define
name|BCE_MSG_LEVEL
parameter_list|(
name|lv
parameter_list|)
value|((lv& BCE_LEVEL_MASK)<= (bce_debug& BCE_LEVEL_MASK))
end_define

begin_define
define|#
directive|define
name|BCE_LOG_MSG
parameter_list|(
name|m
parameter_list|)
value|(BCE_CODE_PATH(m)&& BCE_MSG_LEVEL(m))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|BCE_DEBUG
end_ifdef

begin_comment
comment|/* Print a message based on the logging level and code path. */
end_comment

begin_define
define|#
directive|define
name|DBPRINT
parameter_list|(
name|sc
parameter_list|,
name|level
parameter_list|,
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|if (BCE_LOG_MSG(level)) {							\ 		device_printf(sc->bce_dev, format, ## args);						\ 	}
end_define

begin_comment
comment|/* Runs a particular command based on the logging level and code path. */
end_comment

begin_define
define|#
directive|define
name|DBRUN
parameter_list|(
name|m
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|if (BCE_LOG_MSG(m)) { \ 		args; \ 	}
end_define

begin_comment
comment|/* Runs a particular command based on the logging level. */
end_comment

begin_define
define|#
directive|define
name|DBRUNLV
parameter_list|(
name|level
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|if (BCE_MSG_LEVEL(level)) { \ 		args; \ 	}
end_define

begin_comment
comment|/* Runs a particular command based on the code path. */
end_comment

begin_define
define|#
directive|define
name|DBRUNCP
parameter_list|(
name|cp
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|if (BCE_CODE_PATH(cp)) { \ 		args; \ 	}
end_define

begin_comment
comment|/* Runs a particular command based on a condition. */
end_comment

begin_define
define|#
directive|define
name|DBRUNIF
parameter_list|(
name|cond
parameter_list|,
name|args
modifier|...
parameter_list|)
define|\
value|if (cond) { \ 		args; \ 	}
end_define

begin_comment
comment|/* Needed for random() function which is only used in debugging. */
end_comment

begin_include
include|#
directive|include
file|<sys/random.h>
end_include

begin_comment
comment|/* Returns FALSE in "defects" per 2^31 - 1 calls, otherwise returns TRUE. */
end_comment

begin_define
define|#
directive|define
name|DB_RANDOMFALSE
parameter_list|(
name|defects
parameter_list|)
value|(random()> defects)
end_define

begin_define
define|#
directive|define
name|DB_OR_RANDOMFALSE
parameter_list|(
name|defects
parameter_list|)
value||| (random()> defects)
end_define

begin_define
define|#
directive|define
name|DB_AND_RANDOMFALSE
parameter_list|(
name|defects
parameter_list|)
value|&& (random()> ddfects)
end_define

begin_comment
comment|/* Returns TRUE in "defects" per 2^31 - 1 calls, otherwise returns FALSE. */
end_comment

begin_define
define|#
directive|define
name|DB_RANDOMTRUE
parameter_list|(
name|defects
parameter_list|)
value|(random()< defects)
end_define

begin_define
define|#
directive|define
name|DB_OR_RANDOMTRUE
parameter_list|(
name|defects
parameter_list|)
value||| (random()< defects)
end_define

begin_define
define|#
directive|define
name|DB_AND_RANDOMTRUE
parameter_list|(
name|defects
parameter_list|)
value|&& (random()< defects)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|DBPRINT
parameter_list|(
name|level
parameter_list|,
name|format
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBRUN
parameter_list|(
name|m
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBRUNLV
parameter_list|(
name|level
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBRUNCP
parameter_list|(
name|cp
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DBRUNIF
parameter_list|(
name|cond
parameter_list|,
name|args
modifier|...
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DB_RANDOMFALSE
parameter_list|(
name|defects
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DB_OR_RANDOMFALSE
parameter_list|(
name|percent
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DB_AND_RANDOMFALSE
parameter_list|(
name|percent
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DB_RANDOMTRUE
parameter_list|(
name|defects
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DB_OR_RANDOMTRUE
parameter_list|(
name|percent
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DB_AND_RANDOMTRUE
parameter_list|(
name|percent
parameter_list|)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* BCE_DEBUG */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Device identification definitions.                                       */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|BRCM_VENDORID
value|0x14E4
end_define

begin_define
define|#
directive|define
name|BRCM_DEVICEID_BCM5706
value|0x164A
end_define

begin_define
define|#
directive|define
name|BRCM_DEVICEID_BCM5706S
value|0x16AA
end_define

begin_define
define|#
directive|define
name|BRCM_DEVICEID_BCM5708
value|0x164C
end_define

begin_define
define|#
directive|define
name|BRCM_DEVICEID_BCM5708S
value|0x16AC
end_define

begin_define
define|#
directive|define
name|HP_VENDORID
value|0x103C
end_define

begin_define
define|#
directive|define
name|PCI_ANY_ID
value|(u_int16_t) (~0U)
end_define

begin_comment
comment|/* chip num:16-31, rev:12-15, metal:4-11, bond_id:0-3 */
end_comment

begin_define
define|#
directive|define
name|BCE_CHIP_NUM
parameter_list|(
name|sc
parameter_list|)
value|(((sc)->bce_chipid)& 0xffff0000)
end_define

begin_define
define|#
directive|define
name|BCE_CHIP_NUM_5706
value|0x57060000
end_define

begin_define
define|#
directive|define
name|BCE_CHIP_NUM_5708
value|0x57080000
end_define

begin_define
define|#
directive|define
name|BCE_CHIP_REV
parameter_list|(
name|sc
parameter_list|)
value|(((sc)->bce_chipid)& 0x0000f000)
end_define

begin_define
define|#
directive|define
name|BCE_CHIP_REV_Ax
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BCE_CHIP_REV_Bx
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BCE_CHIP_REV_Cx
value|0x00002000
end_define

begin_define
define|#
directive|define
name|BCE_CHIP_METAL
parameter_list|(
name|sc
parameter_list|)
value|(((sc)->bce_chipid)& 0x00000ff0)
end_define

begin_define
define|#
directive|define
name|BCE_CHIP_BOND
parameter_list|(
name|bp
parameter_list|)
value|(((sc)->bce_chipid)& 0x0000000f)
end_define

begin_define
define|#
directive|define
name|BCE_CHIP_ID
parameter_list|(
name|sc
parameter_list|)
value|(((sc)->bce_chipid)& 0xfffffff0)
end_define

begin_define
define|#
directive|define
name|BCE_CHIP_ID_5706_A0
value|0x57060000
end_define

begin_define
define|#
directive|define
name|BCE_CHIP_ID_5706_A1
value|0x57060010
end_define

begin_define
define|#
directive|define
name|BCE_CHIP_ID_5706_A2
value|0x57060020
end_define

begin_define
define|#
directive|define
name|BCE_CHIP_ID_5708_A0
value|0x57080000
end_define

begin_define
define|#
directive|define
name|BCE_CHIP_ID_5708_B0
value|0x57081000
end_define

begin_define
define|#
directive|define
name|BCE_CHIP_ID_5708_B1
value|0x57081010
end_define

begin_define
define|#
directive|define
name|BCE_CHIP_BOND_ID
parameter_list|(
name|sc
parameter_list|)
value|(((sc)->bce_chipid)& 0xf)
end_define

begin_comment
comment|/* A serdes chip will have the first bit of the bond id set. */
end_comment

begin_define
define|#
directive|define
name|BCE_CHIP_BOND_ID_SERDES_BIT
value|0x01
end_define

begin_comment
comment|/* shorthand one */
end_comment

begin_define
define|#
directive|define
name|BCE_ASICREV
parameter_list|(
name|x
parameter_list|)
value|((x)>> 28)
end_define

begin_define
define|#
directive|define
name|BCE_ASICREV_BCM5700
value|0x06
end_define

begin_comment
comment|/* chip revisions */
end_comment

begin_define
define|#
directive|define
name|BCE_CHIPREV
parameter_list|(
name|x
parameter_list|)
value|((x)>> 24)
end_define

begin_define
define|#
directive|define
name|BCE_CHIPREV_5700_AX
value|0x70
end_define

begin_define
define|#
directive|define
name|BCE_CHIPREV_5700_BX
value|0x71
end_define

begin_define
define|#
directive|define
name|BCE_CHIPREV_5700_CX
value|0x72
end_define

begin_define
define|#
directive|define
name|BCE_CHIPREV_5701_AX
value|0x00
end_define

begin_struct
struct|struct
name|bce_type
block|{
name|u_int16_t
name|bce_vid
decl_stmt|;
name|u_int16_t
name|bce_did
decl_stmt|;
name|u_int16_t
name|bce_svid
decl_stmt|;
name|u_int16_t
name|bce_sdid
decl_stmt|;
name|char
modifier|*
name|bce_name
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Byte order conversions.                                                  */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|bce_htobe16
parameter_list|(
name|x
parameter_list|)
value|htobe16(x)
end_define

begin_define
define|#
directive|define
name|bce_htobe32
parameter_list|(
name|x
parameter_list|)
value|htobe32(x)
end_define

begin_define
define|#
directive|define
name|bce_htobe64
parameter_list|(
name|x
parameter_list|)
value|htobe64(x)
end_define

begin_define
define|#
directive|define
name|bce_htole16
parameter_list|(
name|x
parameter_list|)
value|htole16(x)
end_define

begin_define
define|#
directive|define
name|bce_htole32
parameter_list|(
name|x
parameter_list|)
value|htole32(x)
end_define

begin_define
define|#
directive|define
name|bce_htole64
parameter_list|(
name|x
parameter_list|)
value|htole64(x)
end_define

begin_define
define|#
directive|define
name|bce_be16toh
parameter_list|(
name|x
parameter_list|)
value|be16toh(x)
end_define

begin_define
define|#
directive|define
name|bce_be32toh
parameter_list|(
name|x
parameter_list|)
value|be32toh(x)
end_define

begin_define
define|#
directive|define
name|bce_be64toh
parameter_list|(
name|x
parameter_list|)
value|be64toh(x)
end_define

begin_define
define|#
directive|define
name|bce_le16toh
parameter_list|(
name|x
parameter_list|)
value|le16toh(x)
end_define

begin_define
define|#
directive|define
name|bce_le32toh
parameter_list|(
name|x
parameter_list|)
value|le32toh(x)
end_define

begin_define
define|#
directive|define
name|bce_le64toh
parameter_list|(
name|x
parameter_list|)
value|le64toh(x)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* NVRAM Access                                                             */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Buffered flash (Atmel: AT45DB011B) specific information */
end_comment

begin_define
define|#
directive|define
name|SEEPROM_PAGE_BITS
value|2
end_define

begin_define
define|#
directive|define
name|SEEPROM_PHY_PAGE_SIZE
value|(1<< SEEPROM_PAGE_BITS)
end_define

begin_define
define|#
directive|define
name|SEEPROM_BYTE_ADDR_MASK
value|(SEEPROM_PHY_PAGE_SIZE-1)
end_define

begin_define
define|#
directive|define
name|SEEPROM_PAGE_SIZE
value|4
end_define

begin_define
define|#
directive|define
name|SEEPROM_TOTAL_SIZE
value|65536
end_define

begin_define
define|#
directive|define
name|BUFFERED_FLASH_PAGE_BITS
value|9
end_define

begin_define
define|#
directive|define
name|BUFFERED_FLASH_PHY_PAGE_SIZE
value|(1<< BUFFERED_FLASH_PAGE_BITS)
end_define

begin_define
define|#
directive|define
name|BUFFERED_FLASH_BYTE_ADDR_MASK
value|(BUFFERED_FLASH_PHY_PAGE_SIZE-1)
end_define

begin_define
define|#
directive|define
name|BUFFERED_FLASH_PAGE_SIZE
value|264
end_define

begin_define
define|#
directive|define
name|BUFFERED_FLASH_TOTAL_SIZE
value|0x21000
end_define

begin_define
define|#
directive|define
name|SAIFUN_FLASH_PAGE_BITS
value|8
end_define

begin_define
define|#
directive|define
name|SAIFUN_FLASH_PHY_PAGE_SIZE
value|(1<< SAIFUN_FLASH_PAGE_BITS)
end_define

begin_define
define|#
directive|define
name|SAIFUN_FLASH_BYTE_ADDR_MASK
value|(SAIFUN_FLASH_PHY_PAGE_SIZE-1)
end_define

begin_define
define|#
directive|define
name|SAIFUN_FLASH_PAGE_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|SAIFUN_FLASH_BASE_TOTAL_SIZE
value|65536
end_define

begin_define
define|#
directive|define
name|ST_MICRO_FLASH_PAGE_BITS
value|8
end_define

begin_define
define|#
directive|define
name|ST_MICRO_FLASH_PHY_PAGE_SIZE
value|(1<< ST_MICRO_FLASH_PAGE_BITS)
end_define

begin_define
define|#
directive|define
name|ST_MICRO_FLASH_BYTE_ADDR_MASK
value|(ST_MICRO_FLASH_PHY_PAGE_SIZE-1)
end_define

begin_define
define|#
directive|define
name|ST_MICRO_FLASH_PAGE_SIZE
value|256
end_define

begin_define
define|#
directive|define
name|ST_MICRO_FLASH_BASE_TOTAL_SIZE
value|65536
end_define

begin_define
define|#
directive|define
name|NVRAM_TIMEOUT_COUNT
value|30000
end_define

begin_define
define|#
directive|define
name|BCE_FLASHDESC_MAX
value|64
end_define

begin_define
define|#
directive|define
name|FLASH_STRAP_MASK
value|(BCE_NVM_CFG1_FLASH_MODE | \ 										 BCE_NVM_CFG1_BUFFER_MODE  | \ 										 BCE_NVM_CFG1_PROTECT_MODE | \ 										 BCE_NVM_CFG1_FLASH_SIZE)
end_define

begin_define
define|#
directive|define
name|FLASH_BACKUP_STRAP_MASK
value|(0xf<< 26)
end_define

begin_struct
struct|struct
name|flash_spec
block|{
name|u32
name|strapping
decl_stmt|;
name|u32
name|config1
decl_stmt|;
name|u32
name|config2
decl_stmt|;
name|u32
name|config3
decl_stmt|;
name|u32
name|write1
decl_stmt|;
name|u32
name|buffered
decl_stmt|;
name|u32
name|page_bits
decl_stmt|;
name|u32
name|page_size
decl_stmt|;
name|u32
name|addr_mask
decl_stmt|;
name|u32
name|total_size
decl_stmt|;
name|u8
modifier|*
name|name
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Shared Memory layout                                                     */
end_comment

begin_comment
comment|/* The BCE bootcode will initialize this data area with port configurtion   */
end_comment

begin_comment
comment|/* information which can be accessed by the driver.                         */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*   * This value (in milliseconds) determines the frequency of the driver  * issuing the PULSE message code.  The firmware monitors this periodic  * pulse to determine when to switch to an OS-absent mode.   */
end_comment

begin_define
define|#
directive|define
name|DRV_PULSE_PERIOD_MS
value|250
end_define

begin_comment
comment|/*   * This value (in milliseconds) determines how long the driver should  * wait for an acknowledgement from the firmware before timing out.  Once  * the firmware has timed out, the driver will assume there is no firmware  * running and there won't be any firmware-driver synchronization during a  * driver reset.   */
end_comment

begin_define
define|#
directive|define
name|FW_ACK_TIME_OUT_MS
value|100
end_define

begin_define
define|#
directive|define
name|BCE_DRV_RESET_SIGNATURE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BCE_DRV_RESET_SIGNATURE_MAGIC
value|0x4841564b
end_define

begin_comment
comment|/* HAVK */
end_comment

begin_define
define|#
directive|define
name|BCE_DRV_MB
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BCE_DRV_MSG_CODE
value|0xff000000
end_define

begin_define
define|#
directive|define
name|BCE_DRV_MSG_CODE_RESET
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BCE_DRV_MSG_CODE_UNLOAD
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BCE_DRV_MSG_CODE_SHUTDOWN
value|0x03000000
end_define

begin_define
define|#
directive|define
name|BCE_DRV_MSG_CODE_SUSPEND_WOL
value|0x04000000
end_define

begin_define
define|#
directive|define
name|BCE_DRV_MSG_CODE_FW_TIMEOUT
value|0x05000000
end_define

begin_define
define|#
directive|define
name|BCE_DRV_MSG_CODE_PULSE
value|0x06000000
end_define

begin_define
define|#
directive|define
name|BCE_DRV_MSG_CODE_DIAG
value|0x07000000
end_define

begin_define
define|#
directive|define
name|BCE_DRV_MSG_CODE_SUSPEND_NO_WOL
value|0x09000000
end_define

begin_define
define|#
directive|define
name|BCE_DRV_MSG_DATA
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|BCE_DRV_MSG_DATA_WAIT0
value|0x00010000
end_define

begin_define
define|#
directive|define
name|BCE_DRV_MSG_DATA_WAIT1
value|0x00020000
end_define

begin_define
define|#
directive|define
name|BCE_DRV_MSG_DATA_WAIT2
value|0x00030000
end_define

begin_define
define|#
directive|define
name|BCE_DRV_MSG_DATA_WAIT3
value|0x00040000
end_define

begin_define
define|#
directive|define
name|BCE_DRV_MSG_SEQ
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|BCE_FW_MB
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BCE_FW_MSG_ACK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|BCE_FW_MSG_STATUS_MASK
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|BCE_FW_MSG_STATUS_OK
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BCE_FW_MSG_STATUS_FAILURE
value|0x00ff0000
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_INIT_VALUE
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_LINK_UP
value|0x1
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_LINK_DOWN
value|0x0
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_SPEED_MASK
value|0x1e
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_AN_INCOMPLETE
value|(0<<1)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_10HALF
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_10FULL
value|(2<<1)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_100HALF
value|(3<<1)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_100BASE_T4
value|(4<<1)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_100FULL
value|(5<<1)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_1000HALF
value|(6<<1)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_1000FULL
value|(7<<1)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_2500HALF
value|(8<<1)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_2500FULL
value|(9<<1)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_AN_ENABLED
value|(1<<5)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_AN_COMPLETE
value|(1<<6)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_PARALLEL_DET
value|(1<<7)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_RESERVED
value|(1<<8)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_PARTNER_AD_1000FULL
value|(1<<9)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_PARTNER_AD_1000HALF
value|(1<<10)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_PARTNER_AD_100BT4
value|(1<<11)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_PARTNER_AD_100FULL
value|(1<<12)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_PARTNER_AD_100HALF
value|(1<<13)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_PARTNER_AD_10FULL
value|(1<<14)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_PARTNER_AD_10HALF
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_TX_FC_ENABLED
value|(1<<16)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_RX_FC_ENABLED
value|(1<<17)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_PARTNER_SYM_PAUSE_CAP
value|(1<<18)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_PARTNER_ASYM_PAUSE_CAP
value|(1<<19)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_SERDES_LINK
value|(1<<20)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_PARTNER_AD_2500FULL
value|(1<<21)
end_define

begin_define
define|#
directive|define
name|BCE_LINK_STATUS_PARTNER_AD_2500HALF
value|(1<<22)
end_define

begin_define
define|#
directive|define
name|BCE_DRV_PULSE_MB
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BCE_DRV_PULSE_SEQ_MASK
value|0x00007fff
end_define

begin_comment
comment|/* Indicate to the firmware not to go into the  * OS absent when it is not getting driver pulse.  * This is used for debugging. */
end_comment

begin_define
define|#
directive|define
name|BCE_DRV_MSG_DATA_PULSE_CODE_ALWAYS_ALIVE
value|0x00080000
end_define

begin_define
define|#
directive|define
name|BCE_DEV_INFO_SIGNATURE
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BCE_DEV_INFO_SIGNATURE_MAGIC
value|0x44564900
end_define

begin_define
define|#
directive|define
name|BCE_DEV_INFO_SIGNATURE_MAGIC_MASK
value|0xffffff00
end_define

begin_define
define|#
directive|define
name|BCE_DEV_INFO_FEATURE_CFG_VALID
value|0x01
end_define

begin_define
define|#
directive|define
name|BCE_DEV_INFO_SECONDARY_PORT
value|0x80
end_define

begin_define
define|#
directive|define
name|BCE_DEV_INFO_DRV_ALWAYS_ALIVE
value|0x40
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG_PART_NUM
value|0x00000024
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG_POWER_DISSIPATED
value|0x00000034
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG_POWER_STATE_D3_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG_POWER_STATE_D2_MASK
value|0xff0000
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG_POWER_STATE_D1_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG_POWER_STATE_D0_MASK
value|0xff
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG_POWER_CONSUMED
value|0x00000038
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG_CONFIG
value|0x0000003c
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG_DESIGN_NIC
value|0
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG_DESIGN_LOM
value|0x1
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG_PHY_COPPER
value|0
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG_PHY_FIBER
value|0x2
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG_PHY_2_5G
value|0x20
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG_PHY_BACKPLANE
value|0x40
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG_LED_MODE_SHIFT_BITS
value|8
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG_LED_MODE_MASK
value|0x300
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG_LED_MODE_MAC
value|0
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG_LED_MODE_GPHY1
value|0x100
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG_LED_MODE_GPHY2
value|0x200
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG_CONFIG2
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_HW_CFG2_NVM_SIZE_MASK
value|0x00fff000
end_define

begin_define
define|#
directive|define
name|BCE_DEV_INFO_BC_REV
value|0x0000004c
end_define

begin_define
define|#
directive|define
name|BCE_PORT_HW_CFG_MAC_UPPER
value|0x00000050
end_define

begin_define
define|#
directive|define
name|BCE_PORT_HW_CFG_UPPERMAC_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|BCE_PORT_HW_CFG_MAC_LOWER
value|0x00000054
end_define

begin_define
define|#
directive|define
name|BCE_PORT_HW_CFG_CONFIG
value|0x00000058
end_define

begin_define
define|#
directive|define
name|BCE_PORT_HW_CFG_CFG_TXCTL3_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|BCE_PORT_HW_CFG_CFG_DFLT_LINK_MASK
value|0x001f0000
end_define

begin_define
define|#
directive|define
name|BCE_PORT_HW_CFG_CFG_DFLT_LINK_AN
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BCE_PORT_HW_CFG_CFG_DFLT_LINK_1G
value|0x00030000
end_define

begin_define
define|#
directive|define
name|BCE_PORT_HW_CFG_CFG_DFLT_LINK_2_5G
value|0x00040000
end_define

begin_define
define|#
directive|define
name|BCE_PORT_HW_CFG_IMD_MAC_A_UPPER
value|0x00000068
end_define

begin_define
define|#
directive|define
name|BCE_PORT_HW_CFG_IMD_MAC_A_LOWER
value|0x0000006c
end_define

begin_define
define|#
directive|define
name|BCE_PORT_HW_CFG_IMD_MAC_B_UPPER
value|0x00000070
end_define

begin_define
define|#
directive|define
name|BCE_PORT_HW_CFG_IMD_MAC_B_LOWER
value|0x00000074
end_define

begin_define
define|#
directive|define
name|BCE_PORT_HW_CFG_ISCSI_MAC_UPPER
value|0x00000078
end_define

begin_define
define|#
directive|define
name|BCE_PORT_HW_CFG_ISCSI_MAC_LOWER
value|0x0000007c
end_define

begin_define
define|#
directive|define
name|BCE_DEV_INFO_PER_PORT_HW_CONFIG2
value|0x000000b4
end_define

begin_define
define|#
directive|define
name|BCE_DEV_INFO_FORMAT_REV
value|0x000000c4
end_define

begin_define
define|#
directive|define
name|BCE_DEV_INFO_FORMAT_REV_MASK
value|0xff000000
end_define

begin_define
define|#
directive|define
name|BCE_DEV_INFO_FORMAT_REV_ID
value|('A'<< 24)
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_FEATURE
value|0x000000c8
end_define

begin_define
define|#
directive|define
name|BCE_SHARED_FEATURE_MASK
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE
value|0x000000d8
end_define

begin_define
define|#
directive|define
name|BCE_PORT2_FEATURE
value|0x00000014c
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_WOL_ENABLED
value|0x01000000
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_ENABLED
value|0x02000000
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_ASF_ENABLED
value|0x04000000
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_IMD_ENABLED
value|0x08000000
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_BAR1_SIZE_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_BAR1_SIZE_DISABLED
value|0x0
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_BAR1_SIZE_64K
value|0x1
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_BAR1_SIZE_128K
value|0x2
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_BAR1_SIZE_256K
value|0x3
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_BAR1_SIZE_512K
value|0x4
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_BAR1_SIZE_1M
value|0x5
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_BAR1_SIZE_2M
value|0x6
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_BAR1_SIZE_4M
value|0x7
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_BAR1_SIZE_8M
value|0x8
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_BAR1_SIZE_16M
value|0x9
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_BAR1_SIZE_32M
value|0xa
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_BAR1_SIZE_64M
value|0xb
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_BAR1_SIZE_128M
value|0xc
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_BAR1_SIZE_256M
value|0xd
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_BAR1_SIZE_512M
value|0xe
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_BAR1_SIZE_1G
value|0xf
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_WOL
value|0xdc
end_define

begin_define
define|#
directive|define
name|BCE_PORT2_FEATURE_WOL
value|0x150
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_WOL_DEFAULT_SHIFT_BITS
value|4
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_WOL_DEFAULT_MASK
value|0x30
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_WOL_DEFAULT_DISABLE
value|0
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_WOL_DEFAULT_MAGIC
value|0x10
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_WOL_DEFAULT_ACPI
value|0x20
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_WOL_DEFAULT_MAGIC_AND_ACPI
value|0x30
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_WOL_LINK_SPEED_MASK
value|0xf
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_WOL_LINK_SPEED_AUTONEG
value|0
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_WOL_LINK_SPEED_10HALF
value|1
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_WOL_LINK_SPEED_10FULL
value|2
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_WOL_LINK_SPEED_100HALF
value|3
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_WOL_LINK_SPEED_100FULL
value|4
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_WOL_LINK_SPEED_1000HALF
value|5
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_WOL_LINK_SPEED_1000FULL
value|6
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_WOL_AUTONEG_ADVERTISE_1000
value|0x40
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_WOL_RESERVED_PAUSE_CAP
value|0x400
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_WOL_RESERVED_ASYM_PAUSE_CAP
value|0x800
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA
value|0xe0
end_define

begin_define
define|#
directive|define
name|BCE_PORT2_FEATURE_MBA
value|0x154
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_BOOT_AGENT_TYPE_SHIFT_BITS
value|0
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_BOOT_AGENT_TYPE_MASK
value|0x3
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_BOOT_AGENT_TYPE_PXE
value|0
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_BOOT_AGENT_TYPE_RPL
value|1
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_BOOT_AGENT_TYPE_BOOTP
value|2
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_LINK_SPEED_SHIFT_BITS
value|2
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_LINK_SPEED_MASK
value|0x3c
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_LINK_SPEED_AUTONEG
value|0
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_LINK_SPEED_10HALF
value|0x4
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_LINK_SPEED_10FULL
value|0x8
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_LINK_SPEED_100HALF
value|0xc
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_LINK_SPEED_100FULL
value|0x10
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_LINK_SPEED_1000HALF
value|0x14
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_LINK_SPEED_1000FULL
value|0x18
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_SETUP_PROMPT_ENABLE
value|0x40
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_HOTKEY_CTRL_S
value|0
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_HOTKEY_CTRL_B
value|0x80
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_EXP_ROM_SIZE_SHIFT_BITS
value|8
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_EXP_ROM_SIZE_MASK
value|0xff00
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_EXP_ROM_SIZE_DISABLED
value|0
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_EXP_ROM_SIZE_1K
value|0x100
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_EXP_ROM_SIZE_2K
value|0x200
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_EXP_ROM_SIZE_4K
value|0x300
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_EXP_ROM_SIZE_8K
value|0x400
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_EXP_ROM_SIZE_16K
value|0x500
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_EXP_ROM_SIZE_32K
value|0x600
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_EXP_ROM_SIZE_64K
value|0x700
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_EXP_ROM_SIZE_128K
value|0x800
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_EXP_ROM_SIZE_256K
value|0x900
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_EXP_ROM_SIZE_512K
value|0xa00
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_EXP_ROM_SIZE_1M
value|0xb00
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_EXP_ROM_SIZE_2M
value|0xc00
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_EXP_ROM_SIZE_4M
value|0xd00
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_EXP_ROM_SIZE_8M
value|0xe00
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_EXP_ROM_SIZE_16M
value|0xf00
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_MSG_TIMEOUT_SHIFT_BITS
value|16
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_MSG_TIMEOUT_MASK
value|0xf0000
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_BIOS_BOOTSTRAP_SHIFT_BITS
value|20
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_BIOS_BOOTSTRAP_MASK
value|0x300000
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_BIOS_BOOTSTRAP_AUTO
value|0
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_BIOS_BOOTSTRAP_BBS
value|0x100000
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_BIOS_BOOTSTRAP_INT18H
value|0x200000
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_BIOS_BOOTSTRAP_INT19H
value|0x300000
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_IMD
value|0xe4
end_define

begin_define
define|#
directive|define
name|BCE_PORT2_FEATURE_IMD
value|0x158
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_IMD_LINK_OVERRIDE_DEFAULT
value|0
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_IMD_LINK_OVERRIDE_ENABLE
value|1
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_VLAN
value|0xe8
end_define

begin_define
define|#
directive|define
name|BCE_PORT2_FEATURE_VLAN
value|0x15c
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_VLAN_TAG_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|BCE_PORT_FEATURE_MBA_VLAN_ENABLE
value|0x10000
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RESET_TYPE
value|0x000001c0
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RESET_TYPE_SIG
value|0x00005254
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RESET_TYPE_SIG_MASK
value|0x0000ffff
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RESET_TYPE_NONE
value|(BCE_BC_STATE_RESET_TYPE_SIG | \ 					  0x00010000)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RESET_TYPE_PCI
value|(BCE_BC_STATE_RESET_TYPE_SIG | \ 					  0x00020000)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RESET_TYPE_VAUX
value|(BCE_BC_STATE_RESET_TYPE_SIG | \ 					  0x00030000)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RESET_TYPE_DRV_MASK
value|DRV_MSG_CODE
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RESET_TYPE_DRV_RESET
value|(BCE_BC_STATE_RESET_TYPE_SIG | \ 					    DRV_MSG_CODE_RESET)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RESET_TYPE_DRV_UNLOAD
value|(BCE_BC_STATE_RESET_TYPE_SIG | \ 					     DRV_MSG_CODE_UNLOAD)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RESET_TYPE_DRV_SHUTDOWN
value|(BCE_BC_STATE_RESET_TYPE_SIG | \ 					       DRV_MSG_CODE_SHUTDOWN)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RESET_TYPE_DRV_WOL
value|(BCE_BC_STATE_RESET_TYPE_SIG | \ 					  DRV_MSG_CODE_WOL)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RESET_TYPE_DRV_DIAG
value|(BCE_BC_STATE_RESET_TYPE_SIG | \ 					   DRV_MSG_CODE_DIAG)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RESET_TYPE_VALUE
parameter_list|(
name|msg
parameter_list|)
value|(BCE_BC_STATE_RESET_TYPE_SIG | \ 					     (msg))
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE
value|0x000001c4
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_ERR_MASK
value|0x0000ff00
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_SIGN
value|0x42530000
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_SIGN_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_BC1_START
value|(BCE_BC_STATE_SIGN | 0x1)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_GET_NVM_CFG1
value|(BCE_BC_STATE_SIGN | 0x2)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_PROG_BAR
value|(BCE_BC_STATE_SIGN | 0x3)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_INIT_VID
value|(BCE_BC_STATE_SIGN | 0x4)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_GET_NVM_CFG2
value|(BCE_BC_STATE_SIGN | 0x5)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_APPLY_WKARND
value|(BCE_BC_STATE_SIGN | 0x6)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_LOAD_BC2
value|(BCE_BC_STATE_SIGN | 0x7)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_GOING_BC2
value|(BCE_BC_STATE_SIGN | 0x8)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_GOING_DIAG
value|(BCE_BC_STATE_SIGN | 0x9)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RT_FINAL_INIT
value|(BCE_BC_STATE_SIGN | 0x81)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RT_WKARND
value|(BCE_BC_STATE_SIGN | 0x82)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RT_DRV_PULSE
value|(BCE_BC_STATE_SIGN | 0x83)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RT_FIOEVTS
value|(BCE_BC_STATE_SIGN | 0x84)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RT_DRV_CMD
value|(BCE_BC_STATE_SIGN | 0x85)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RT_LOW_POWER
value|(BCE_BC_STATE_SIGN | 0x86)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RT_SET_WOL
value|(BCE_BC_STATE_SIGN | 0x87)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RT_OTHER_FW
value|(BCE_BC_STATE_SIGN | 0x88)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_RT_GOING_D3
value|(BCE_BC_STATE_SIGN | 0x89)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_ERR_BAD_VERSION
value|(BCE_BC_STATE_SIGN | 0x0100)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_ERR_BAD_BC2_CRC
value|(BCE_BC_STATE_SIGN | 0x0200)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_ERR_BC1_LOOP
value|(BCE_BC_STATE_SIGN | 0x0300)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_ERR_UNKNOWN_CMD
value|(BCE_BC_STATE_SIGN | 0x0400)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_ERR_DRV_DEAD
value|(BCE_BC_STATE_SIGN | 0x0500)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_ERR_NO_RXP
value|(BCE_BC_STATE_SIGN | 0x0600)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_ERR_TOO_MANY_RBUF
value|(BCE_BC_STATE_SIGN | 0x0700)
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_DEBUG_CMD
value|0x1dc
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_BC_DBG_CMD_SIGNATURE
value|0x42440000
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_BC_DBG_CMD_SIGNATURE_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_BC_DBG_CMD_LOOP_CNT_MASK
value|0xffff
end_define

begin_define
define|#
directive|define
name|BCE_BC_STATE_BC_DBG_CMD_LOOP_INFINITE
value|0xffff
end_define

begin_define
define|#
directive|define
name|HOST_VIEW_SHMEM_BASE
value|0x167c00
end_define

begin_comment
comment|/*  * PCI registers defined in the PCI 2.2 spec.  */
end_comment

begin_define
define|#
directive|define
name|BCE_PCI_PCIX_CMD
value|0x42
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Convenience definitions.                                                 */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|BCE_PRINTF
parameter_list|(
name|sc
parameter_list|,
name|fmt
parameter_list|,
name|args
modifier|...
parameter_list|)
value|device_printf(sc->bce_dev, fmt, ##args)
end_define

begin_define
define|#
directive|define
name|REG_WR
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_4(sc->bce_btag, sc->bce_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|REG_WR16
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|val
parameter_list|)
value|bus_space_write_2(sc->bce_btag, sc->bce_bhandle, reg, val)
end_define

begin_define
define|#
directive|define
name|REG_RD
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|)
value|bus_space_read_4(sc->bce_btag, sc->bce_bhandle, reg)
end_define

begin_define
define|#
directive|define
name|REG_RD_IND
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|)
value|bce_reg_rd_ind(sc, offset)
end_define

begin_define
define|#
directive|define
name|REG_WR_IND
parameter_list|(
name|sc
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
value|bce_reg_wr_ind(sc, offset, val)
end_define

begin_define
define|#
directive|define
name|CTX_WR
parameter_list|(
name|sc
parameter_list|,
name|cid_addr
parameter_list|,
name|offset
parameter_list|,
name|val
parameter_list|)
value|bce_ctx_wr(sc, cid_addr, offset, val)
end_define

begin_define
define|#
directive|define
name|BCE_SETBIT
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
value|REG_WR(sc, reg, (REG_RD(sc, reg) | (x)))
end_define

begin_define
define|#
directive|define
name|BCE_CLRBIT
parameter_list|(
name|sc
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|)
value|REG_WR(sc, reg, (REG_RD(sc, reg)& ~(x)))
end_define

begin_define
define|#
directive|define
name|PCI_SETBIT
parameter_list|(
name|dev
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|)
value|pci_write_config(dev, reg, (pci_read_config(dev, reg, s) | (x)), s)
end_define

begin_define
define|#
directive|define
name|PCI_CLRBIT
parameter_list|(
name|dev
parameter_list|,
name|reg
parameter_list|,
name|x
parameter_list|,
name|s
parameter_list|)
value|pci_write_config(dev, reg, (pci_read_config(dev, reg, s)& ~(x)), s)
end_define

begin_define
define|#
directive|define
name|BCE_STATS
parameter_list|(
name|x
parameter_list|)
value|(u_long) stats->stat_ ## x ## _lo
end_define

begin_if
if|#
directive|if
operator|(
name|BUS_SPACE_MAXADDR
operator|>
literal|0xFFFFFFFF
operator|)
end_if

begin_define
define|#
directive|define
name|BCE_ADDR_LO
parameter_list|(
name|y
parameter_list|)
value|((u64) (y)& 0xFFFFFFFF)
end_define

begin_define
define|#
directive|define
name|BCE_ADDR_HI
parameter_list|(
name|y
parameter_list|)
value|((u64) (y)>> 32)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BCE_ADDR_LO
parameter_list|(
name|y
parameter_list|)
value|((u32)y)
end_define

begin_define
define|#
directive|define
name|BCE_ADDR_HI
parameter_list|(
name|y
parameter_list|)
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * The following data structures are generated from RTL code.  * Do not modify any values below this line.  */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* Do not modify any of the following data structures, they are generated   */
end_comment

begin_comment
comment|/* from RTL code.                                                           */
end_comment

begin_comment
comment|/*                                                                          */
end_comment

begin_comment
comment|/* Begin machine generated definitions.                                     */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/*  *  tx_bd definition  */
end_comment

begin_struct
struct|struct
name|tx_bd
block|{
name|u32
name|tx_bd_haddr_hi
decl_stmt|;
name|u32
name|tx_bd_haddr_lo
decl_stmt|;
name|u32
name|tx_bd_mss_nbytes
decl_stmt|;
name|u16
name|tx_bd_flags
decl_stmt|;
name|u16
name|tx_bd_vlan_tag
decl_stmt|;
define|#
directive|define
name|TX_BD_FLAGS_CONN_FAULT
value|(1<<0)
define|#
directive|define
name|TX_BD_FLAGS_TCP_UDP_CKSUM
value|(1<<1)
define|#
directive|define
name|TX_BD_FLAGS_IP_CKSUM
value|(1<<2)
define|#
directive|define
name|TX_BD_FLAGS_VLAN_TAG
value|(1<<3)
define|#
directive|define
name|TX_BD_FLAGS_COAL_NOW
value|(1<<4)
define|#
directive|define
name|TX_BD_FLAGS_DONT_GEN_CRC
value|(1<<5)
define|#
directive|define
name|TX_BD_FLAGS_END
value|(1<<6)
define|#
directive|define
name|TX_BD_FLAGS_START
value|(1<<7)
define|#
directive|define
name|TX_BD_FLAGS_SW_OPTION_WORD
value|(0x1f<<8)
define|#
directive|define
name|TX_BD_FLAGS_SW_FLAGS
value|(1<<13)
define|#
directive|define
name|TX_BD_FLAGS_SW_SNAP
value|(1<<14)
define|#
directive|define
name|TX_BD_FLAGS_SW_LSO
value|(1<<15)
block|}
struct|;
end_struct

begin_comment
comment|/*  *  rx_bd definition  */
end_comment

begin_struct
struct|struct
name|rx_bd
block|{
name|u32
name|rx_bd_haddr_hi
decl_stmt|;
name|u32
name|rx_bd_haddr_lo
decl_stmt|;
name|u32
name|rx_bd_len
decl_stmt|;
name|u32
name|rx_bd_flags
decl_stmt|;
define|#
directive|define
name|RX_BD_FLAGS_NOPUSH
value|(1<<0)
define|#
directive|define
name|RX_BD_FLAGS_DUMMY
value|(1<<1)
define|#
directive|define
name|RX_BD_FLAGS_END
value|(1<<2)
define|#
directive|define
name|RX_BD_FLAGS_START
value|(1<<3)
block|}
struct|;
end_struct

begin_comment
comment|/*  *  status_block definition  */
end_comment

begin_struct
struct|struct
name|status_block
block|{
name|u32
name|status_attn_bits
decl_stmt|;
define|#
directive|define
name|STATUS_ATTN_BITS_LINK_STATE
value|(1L<<0)
define|#
directive|define
name|STATUS_ATTN_BITS_TX_SCHEDULER_ABORT
value|(1L<<1)
define|#
directive|define
name|STATUS_ATTN_BITS_TX_BD_READ_ABORT
value|(1L<<2)
define|#
directive|define
name|STATUS_ATTN_BITS_TX_BD_CACHE_ABORT
value|(1L<<3)
define|#
directive|define
name|STATUS_ATTN_BITS_TX_PROCESSOR_ABORT
value|(1L<<4)
define|#
directive|define
name|STATUS_ATTN_BITS_TX_DMA_ABORT
value|(1L<<5)
define|#
directive|define
name|STATUS_ATTN_BITS_TX_PATCHUP_ABORT
value|(1L<<6)
define|#
directive|define
name|STATUS_ATTN_BITS_TX_ASSEMBLER_ABORT
value|(1L<<7)
define|#
directive|define
name|STATUS_ATTN_BITS_RX_PARSER_MAC_ABORT
value|(1L<<8)
define|#
directive|define
name|STATUS_ATTN_BITS_RX_PARSER_CATCHUP_ABORT
value|(1L<<9)
define|#
directive|define
name|STATUS_ATTN_BITS_RX_MBUF_ABORT
value|(1L<<10)
define|#
directive|define
name|STATUS_ATTN_BITS_RX_LOOKUP_ABORT
value|(1L<<11)
define|#
directive|define
name|STATUS_ATTN_BITS_RX_PROCESSOR_ABORT
value|(1L<<12)
define|#
directive|define
name|STATUS_ATTN_BITS_RX_V2P_ABORT
value|(1L<<13)
define|#
directive|define
name|STATUS_ATTN_BITS_RX_BD_CACHE_ABORT
value|(1L<<14)
define|#
directive|define
name|STATUS_ATTN_BITS_RX_DMA_ABORT
value|(1L<<15)
define|#
directive|define
name|STATUS_ATTN_BITS_COMPLETION_ABORT
value|(1L<<16)
define|#
directive|define
name|STATUS_ATTN_BITS_HOST_COALESCE_ABORT
value|(1L<<17)
define|#
directive|define
name|STATUS_ATTN_BITS_MAILBOX_QUEUE_ABORT
value|(1L<<18)
define|#
directive|define
name|STATUS_ATTN_BITS_CONTEXT_ABORT
value|(1L<<19)
define|#
directive|define
name|STATUS_ATTN_BITS_CMD_SCHEDULER_ABORT
value|(1L<<20)
define|#
directive|define
name|STATUS_ATTN_BITS_CMD_PROCESSOR_ABORT
value|(1L<<21)
define|#
directive|define
name|STATUS_ATTN_BITS_MGMT_PROCESSOR_ABORT
value|(1L<<22)
define|#
directive|define
name|STATUS_ATTN_BITS_MAC_ABORT
value|(1L<<23)
define|#
directive|define
name|STATUS_ATTN_BITS_TIMER_ABORT
value|(1L<<24)
define|#
directive|define
name|STATUS_ATTN_BITS_DMAE_ABORT
value|(1L<<25)
define|#
directive|define
name|STATUS_ATTN_BITS_FLSH_ABORT
value|(1L<<26)
define|#
directive|define
name|STATUS_ATTN_BITS_GRC_ABORT
value|(1L<<27)
define|#
directive|define
name|STATUS_ATTN_BITS_PARITY_ERROR
value|(1L<<31)
name|u32
name|status_attn_bits_ack
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|u16
name|status_tx_quick_consumer_index0
decl_stmt|;
name|u16
name|status_tx_quick_consumer_index1
decl_stmt|;
name|u16
name|status_tx_quick_consumer_index2
decl_stmt|;
name|u16
name|status_tx_quick_consumer_index3
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index0
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index1
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index2
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index3
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index4
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index5
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index6
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index7
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index8
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index9
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index10
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index11
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index12
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index13
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index14
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index15
decl_stmt|;
name|u16
name|status_completion_producer_index
decl_stmt|;
name|u16
name|status_cmd_consumer_index
decl_stmt|;
name|u16
name|status_idx
decl_stmt|;
name|u16
name|status_unused
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|u16
name|status_tx_quick_consumer_index1
decl_stmt|;
name|u16
name|status_tx_quick_consumer_index0
decl_stmt|;
name|u16
name|status_tx_quick_consumer_index3
decl_stmt|;
name|u16
name|status_tx_quick_consumer_index2
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index1
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index0
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index3
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index2
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index5
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index4
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index7
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index6
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index9
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index8
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index11
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index10
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index13
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index12
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index15
decl_stmt|;
name|u16
name|status_rx_quick_consumer_index14
decl_stmt|;
name|u16
name|status_cmd_consumer_index
decl_stmt|;
name|u16
name|status_completion_producer_index
decl_stmt|;
name|u16
name|status_unused
decl_stmt|;
name|u16
name|status_idx
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  *  statistics_block definition  */
end_comment

begin_struct
struct|struct
name|statistics_block
block|{
name|u32
name|stat_IfHCInOctets_hi
decl_stmt|;
name|u32
name|stat_IfHCInOctets_lo
decl_stmt|;
name|u32
name|stat_IfHCInBadOctets_hi
decl_stmt|;
name|u32
name|stat_IfHCInBadOctets_lo
decl_stmt|;
name|u32
name|stat_IfHCOutOctets_hi
decl_stmt|;
name|u32
name|stat_IfHCOutOctets_lo
decl_stmt|;
name|u32
name|stat_IfHCOutBadOctets_hi
decl_stmt|;
name|u32
name|stat_IfHCOutBadOctets_lo
decl_stmt|;
name|u32
name|stat_IfHCInUcastPkts_hi
decl_stmt|;
name|u32
name|stat_IfHCInUcastPkts_lo
decl_stmt|;
name|u32
name|stat_IfHCInMulticastPkts_hi
decl_stmt|;
name|u32
name|stat_IfHCInMulticastPkts_lo
decl_stmt|;
name|u32
name|stat_IfHCInBroadcastPkts_hi
decl_stmt|;
name|u32
name|stat_IfHCInBroadcastPkts_lo
decl_stmt|;
name|u32
name|stat_IfHCOutUcastPkts_hi
decl_stmt|;
name|u32
name|stat_IfHCOutUcastPkts_lo
decl_stmt|;
name|u32
name|stat_IfHCOutMulticastPkts_hi
decl_stmt|;
name|u32
name|stat_IfHCOutMulticastPkts_lo
decl_stmt|;
name|u32
name|stat_IfHCOutBroadcastPkts_hi
decl_stmt|;
name|u32
name|stat_IfHCOutBroadcastPkts_lo
decl_stmt|;
name|u32
name|stat_emac_tx_stat_dot3statsinternalmactransmiterrors
decl_stmt|;
name|u32
name|stat_Dot3StatsCarrierSenseErrors
decl_stmt|;
name|u32
name|stat_Dot3StatsFCSErrors
decl_stmt|;
name|u32
name|stat_Dot3StatsAlignmentErrors
decl_stmt|;
name|u32
name|stat_Dot3StatsSingleCollisionFrames
decl_stmt|;
name|u32
name|stat_Dot3StatsMultipleCollisionFrames
decl_stmt|;
name|u32
name|stat_Dot3StatsDeferredTransmissions
decl_stmt|;
name|u32
name|stat_Dot3StatsExcessiveCollisions
decl_stmt|;
name|u32
name|stat_Dot3StatsLateCollisions
decl_stmt|;
name|u32
name|stat_EtherStatsCollisions
decl_stmt|;
name|u32
name|stat_EtherStatsFragments
decl_stmt|;
name|u32
name|stat_EtherStatsJabbers
decl_stmt|;
name|u32
name|stat_EtherStatsUndersizePkts
decl_stmt|;
name|u32
name|stat_EtherStatsOverrsizePkts
decl_stmt|;
name|u32
name|stat_EtherStatsPktsRx64Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsRx65Octetsto127Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsRx128Octetsto255Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsRx256Octetsto511Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsRx512Octetsto1023Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsRx1024Octetsto1522Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsRx1523Octetsto9022Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsTx64Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsTx65Octetsto127Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsTx128Octetsto255Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsTx256Octetsto511Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsTx512Octetsto1023Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsTx1024Octetsto1522Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsTx1523Octetsto9022Octets
decl_stmt|;
name|u32
name|stat_XonPauseFramesReceived
decl_stmt|;
name|u32
name|stat_XoffPauseFramesReceived
decl_stmt|;
name|u32
name|stat_OutXonSent
decl_stmt|;
name|u32
name|stat_OutXoffSent
decl_stmt|;
name|u32
name|stat_FlowControlDone
decl_stmt|;
name|u32
name|stat_MacControlFramesReceived
decl_stmt|;
name|u32
name|stat_XoffStateEntered
decl_stmt|;
name|u32
name|stat_IfInFramesL2FilterDiscards
decl_stmt|;
name|u32
name|stat_IfInRuleCheckerDiscards
decl_stmt|;
name|u32
name|stat_IfInFTQDiscards
decl_stmt|;
name|u32
name|stat_IfInMBUFDiscards
decl_stmt|;
name|u32
name|stat_IfInRuleCheckerP4Hit
decl_stmt|;
name|u32
name|stat_CatchupInRuleCheckerDiscards
decl_stmt|;
name|u32
name|stat_CatchupInFTQDiscards
decl_stmt|;
name|u32
name|stat_CatchupInMBUFDiscards
decl_stmt|;
name|u32
name|stat_CatchupInRuleCheckerP4Hit
decl_stmt|;
name|u32
name|stat_GenStat00
decl_stmt|;
name|u32
name|stat_GenStat01
decl_stmt|;
name|u32
name|stat_GenStat02
decl_stmt|;
name|u32
name|stat_GenStat03
decl_stmt|;
name|u32
name|stat_GenStat04
decl_stmt|;
name|u32
name|stat_GenStat05
decl_stmt|;
name|u32
name|stat_GenStat06
decl_stmt|;
name|u32
name|stat_GenStat07
decl_stmt|;
name|u32
name|stat_GenStat08
decl_stmt|;
name|u32
name|stat_GenStat09
decl_stmt|;
name|u32
name|stat_GenStat10
decl_stmt|;
name|u32
name|stat_GenStat11
decl_stmt|;
name|u32
name|stat_GenStat12
decl_stmt|;
name|u32
name|stat_GenStat13
decl_stmt|;
name|u32
name|stat_GenStat14
decl_stmt|;
name|u32
name|stat_GenStat15
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  *  l2_fhdr definition  */
end_comment

begin_struct
struct|struct
name|l2_fhdr
block|{
name|u32
name|l2_fhdr_status
decl_stmt|;
define|#
directive|define
name|L2_FHDR_STATUS_RULE_CLASS
value|(0x7<<0)
define|#
directive|define
name|L2_FHDR_STATUS_RULE_P2
value|(1<<3)
define|#
directive|define
name|L2_FHDR_STATUS_RULE_P3
value|(1<<4)
define|#
directive|define
name|L2_FHDR_STATUS_RULE_P4
value|(1<<5)
define|#
directive|define
name|L2_FHDR_STATUS_L2_VLAN_TAG
value|(1<<6)
define|#
directive|define
name|L2_FHDR_STATUS_L2_LLC_SNAP
value|(1<<7)
define|#
directive|define
name|L2_FHDR_STATUS_RSS_HASH
value|(1<<8)
define|#
directive|define
name|L2_FHDR_STATUS_IP_DATAGRAM
value|(1<<13)
define|#
directive|define
name|L2_FHDR_STATUS_TCP_SEGMENT
value|(1<<14)
define|#
directive|define
name|L2_FHDR_STATUS_UDP_DATAGRAM
value|(1<<15)
define|#
directive|define
name|L2_FHDR_ERRORS_BAD_CRC
value|(1<<17)
define|#
directive|define
name|L2_FHDR_ERRORS_PHY_DECODE
value|(1<<18)
define|#
directive|define
name|L2_FHDR_ERRORS_ALIGNMENT
value|(1<<19)
define|#
directive|define
name|L2_FHDR_ERRORS_TOO_SHORT
value|(1<<20)
define|#
directive|define
name|L2_FHDR_ERRORS_GIANT_FRAME
value|(1<<21)
define|#
directive|define
name|L2_FHDR_ERRORS_TCP_XSUM
value|(1<<28)
define|#
directive|define
name|L2_FHDR_ERRORS_UDP_XSUM
value|(1<<31)
name|u32
name|l2_fhdr_hash
decl_stmt|;
if|#
directive|if
name|defined
argument_list|(
name|__BIG_ENDIAN
argument_list|)
name|u16
name|l2_fhdr_pkt_len
decl_stmt|;
name|u16
name|l2_fhdr_vlan_tag
decl_stmt|;
name|u16
name|l2_fhdr_ip_xsum
decl_stmt|;
name|u16
name|l2_fhdr_tcp_udp_xsum
decl_stmt|;
elif|#
directive|elif
name|defined
argument_list|(
name|__LITTLE_ENDIAN
argument_list|)
name|u16
name|l2_fhdr_vlan_tag
decl_stmt|;
name|u16
name|l2_fhdr_pkt_len
decl_stmt|;
name|u16
name|l2_fhdr_tcp_udp_xsum
decl_stmt|;
name|u16
name|l2_fhdr_ip_xsum
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_comment
comment|/*  *  l2_context definition  */
end_comment

begin_define
define|#
directive|define
name|BCE_L2CTX_TYPE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_TYPE_SIZE_L2
value|((0xc0/0x20)<<16)
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_TYPE_TYPE
value|(0xf<<28)
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_TYPE_TYPE_EMPTY
value|(0<<28)
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_TYPE_TYPE_L2
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_TX_HOST_BIDX
value|0x00000088
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_EST_NBD
value|0x00000088
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_CMD_TYPE
value|0x00000088
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_CMD_TYPE_TYPE
value|(0xf<<24)
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_CMD_TYPE_TYPE_L2
value|(0<<24)
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_CMD_TYPE_TYPE_TCP
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_TX_HOST_BSEQ
value|0x00000090
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_TSCH_BSEQ
value|0x00000094
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_TBDR_BSEQ
value|0x00000098
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_TBDR_BOFF
value|0x0000009c
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_TBDR_BIDX
value|0x0000009c
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_TBDR_BHADDR_HI
value|0x000000a0
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_TBDR_BHADDR_LO
value|0x000000a4
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_TXP_BOFF
value|0x000000a8
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_TXP_BIDX
value|0x000000a8
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_TXP_BSEQ
value|0x000000ac
end_define

begin_comment
comment|/*  *  l2_bd_chain_context definition  */
end_comment

begin_define
define|#
directive|define
name|BCE_L2CTX_BD_PRE_READ
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_CTX_SIZE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_CTX_TYPE
value|0x00000000
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_CTX_TYPE_SIZE_L2
value|((0x20/20)<<16)
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_CTX_TYPE_CTX_BD_CHN_TYPE
value|(0xf<<28)
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_CTX_TYPE_CTX_BD_CHN_TYPE_UNDEFINED
value|(0<<28)
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_CTX_TYPE_CTX_BD_CHN_TYPE_VALUE
value|(1<<28)
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_HOST_BDIDX
value|0x00000004
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_HOST_BSEQ
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_NX_BSEQ
value|0x0000000c
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_NX_BDHADDR_HI
value|0x00000010
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_NX_BDHADDR_LO
value|0x00000014
end_define

begin_define
define|#
directive|define
name|BCE_L2CTX_NX_BDIDX
value|0x00000018
end_define

begin_comment
comment|/*  *  pci_config_l definition  *  offset: 0000  */
end_comment

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_CONFIG
value|0x00000068
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_CONFIG_TARGET_BYTE_SWAP
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_CONFIG_TARGET_MB_WORD_SWAP
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_CONFIG_CLOCK_CTL_ENA
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_CONFIG_TARGET_GRC_WORD_SWAP
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_CONFIG_REG_WINDOW_ENA
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_CONFIG_CORE_RST_REQ
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_CONFIG_CORE_RST_BSY
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_CONFIG_ASIC_METAL_REV
value|(0xffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_CONFIG_ASIC_BASE_REV
value|(0xfL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_CONFIG_ASIC_ID
value|(0xfL<<28)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_CONFIG_ASIC_REV
value|(0xffffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_STATUS
value|0x0000006c
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_STATUS_INTA_VALUE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_STATUS_32BIT_DET
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_STATUS_M66EN
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_STATUS_PCIX_DET
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_STATUS_PCIX_SPEED
value|(0x3L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_STATUS_PCIX_SPEED_66
value|(0L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_STATUS_PCIX_SPEED_100
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_STATUS_PCIX_SPEED_133
value|(2L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MISC_STATUS_PCIX_SPEED_PCI_MODE
value|(3L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS
value|0x00000070
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_PCI_CLK_SPD_DET
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_PCI_CLK_SPD_DET_32MHZ
value|(0L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_PCI_CLK_SPD_DET_38MHZ
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_PCI_CLK_SPD_DET_48MHZ
value|(2L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_PCI_CLK_SPD_DET_55MHZ
value|(3L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_PCI_CLK_SPD_DET_66MHZ
value|(4L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_PCI_CLK_SPD_DET_80MHZ
value|(5L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_PCI_CLK_SPD_DET_95MHZ
value|(6L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_PCI_CLK_SPD_DET_133MHZ
value|(7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_PCI_CLK_SPD_DET_LOW
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_CORE_CLK_DISABLE
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_CORE_CLK_ALT
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_CORE_CLK_ALT_SRC
value|(0x7L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_CORE_CLK_ALT_SRC_UNDEF
value|(0L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_CORE_CLK_ALT_SRC_12
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_CORE_CLK_ALT_SRC_6
value|(2L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_CORE_CLK_ALT_SRC_62
value|(4L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_PLAY_DEAD
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_CORE_CLK_PLL_SPEED
value|(0xfL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_CORE_CLK_PLL_SPEED_100
value|(0L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_CORE_CLK_PLL_SPEED_80
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_CORE_CLK_PLL_SPEED_50
value|(2L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_CORE_CLK_PLL_SPEED_40
value|(4L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_CORE_CLK_PLL_SPEED_25
value|(8L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_CORE_CLK_PLL_STOP
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_PCI_PLL_STOP
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_RESERVED_18
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_USE_SPD_DET
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_PCI_CLOCK_CONTROL_BITS_RESERVED
value|(0xfffL<<20)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_REG_WINDOW_ADDRESS
value|0x00000078
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_REG_WINDOW
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_INT_ACK_CMD
value|0x00000084
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_INT_ACK_CMD_INDEX
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_INT_ACK_CMD_INDEX_VALID
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_INT_ACK_CMD_USE_INT_HC_PARAM
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_INT_ACK_CMD_MASK_INT
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_STATUS_BIT_SET_CMD
value|0x00000088
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_STATUS_BIT_CLEAR_CMD
value|0x0000008c
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MAILBOX_QUEUE_ADDR
value|0x00000090
end_define

begin_define
define|#
directive|define
name|BCE_PCICFG_MAILBOX_QUEUE_DATA
value|0x00000094
end_define

begin_comment
comment|/*  *  pci_reg definition  *  offset: 0x400  */
end_comment

begin_define
define|#
directive|define
name|BCE_PCI_GRC_WINDOW_ADDR
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BCE_PCI_GRC_WINDOW_ADDR_PCI_GRC_WINDOW_ADDR_VALUE
value|(0x3ffffL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_1
value|0x00000404
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_1_READ_BOUNDARY
value|(0x7L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_1_READ_BOUNDARY_OFF
value|(0L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_1_READ_BOUNDARY_16
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_1_READ_BOUNDARY_32
value|(2L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_1_READ_BOUNDARY_64
value|(3L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_1_READ_BOUNDARY_128
value|(4L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_1_READ_BOUNDARY_256
value|(5L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_1_READ_BOUNDARY_512
value|(6L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_1_READ_BOUNDARY_1024
value|(7L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_1_WRITE_BOUNDARY
value|(0x7L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_1_WRITE_BOUNDARY_OFF
value|(0L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_1_WRITE_BOUNDARY_16
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_1_WRITE_BOUNDARY_32
value|(2L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_1_WRITE_BOUNDARY_64
value|(3L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_1_WRITE_BOUNDARY_128
value|(4L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_1_WRITE_BOUNDARY_256
value|(5L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_1_WRITE_BOUNDARY_512
value|(6L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_1_WRITE_BOUNDARY_1024
value|(7L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2
value|0x00000408
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_BAR1_SIZE
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_BAR1_SIZE_DISABLED
value|(0L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_BAR1_SIZE_64K
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_BAR1_SIZE_128K
value|(2L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_BAR1_SIZE_256K
value|(3L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_BAR1_SIZE_512K
value|(4L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_BAR1_SIZE_1M
value|(5L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_BAR1_SIZE_2M
value|(6L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_BAR1_SIZE_4M
value|(7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_BAR1_SIZE_8M
value|(8L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_BAR1_SIZE_16M
value|(9L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_BAR1_SIZE_32M
value|(10L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_BAR1_SIZE_64M
value|(11L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_BAR1_SIZE_128M
value|(12L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_BAR1_SIZE_256M
value|(13L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_BAR1_SIZE_512M
value|(14L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_BAR1_SIZE_1G
value|(15L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_BAR1_64ENA
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_EXP_ROM_RETRY
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_CFG_CYCLE_RETRY
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_FIRST_CFG_DONE
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_EXP_ROM_SIZE
value|(0xffL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_EXP_ROM_SIZE_DISABLED
value|(0L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_EXP_ROM_SIZE_1K
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_EXP_ROM_SIZE_2K
value|(2L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_EXP_ROM_SIZE_4K
value|(3L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_EXP_ROM_SIZE_8K
value|(4L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_EXP_ROM_SIZE_16K
value|(5L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_EXP_ROM_SIZE_32K
value|(6L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_EXP_ROM_SIZE_64K
value|(7L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_EXP_ROM_SIZE_128K
value|(8L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_EXP_ROM_SIZE_256K
value|(9L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_EXP_ROM_SIZE_512K
value|(10L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_EXP_ROM_SIZE_1M
value|(11L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_EXP_ROM_SIZE_2M
value|(12L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_EXP_ROM_SIZE_4M
value|(13L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_EXP_ROM_SIZE_8M
value|(14L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_EXP_ROM_SIZE_16M
value|(15L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_MAX_SPLIT_LIMIT
value|(0x1fL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_MAX_READ_LIMIT
value|(0x3L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_MAX_READ_LIMIT_512
value|(0L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_MAX_READ_LIMIT_1K
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_MAX_READ_LIMIT_2K
value|(2L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_MAX_READ_LIMIT_4K
value|(3L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_FORCE_32_BIT_MSTR
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_FORCE_32_BIT_TGT
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_2_KEEP_REQ_ASSERT
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_3
value|0x0000040c
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_3_STICKY_BYTE
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_3_FORCE_PME
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_3_PME_STATUS
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_3_PME_ENABLE
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_3_PM_STATE
value|(0x3L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_3_VAUX_PRESET
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_CONFIG_3_PCI_POWER
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_PM_DATA_A
value|0x00000410
end_define

begin_define
define|#
directive|define
name|BCE_PCI_PM_DATA_A_PM_DATA_0_PRG
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_PM_DATA_A_PM_DATA_1_PRG
value|(0xffL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_PM_DATA_A_PM_DATA_2_PRG
value|(0xffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_PM_DATA_A_PM_DATA_3_PRG
value|(0xffL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_PM_DATA_B
value|0x00000414
end_define

begin_define
define|#
directive|define
name|BCE_PCI_PM_DATA_B_PM_DATA_4_PRG
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_PM_DATA_B_PM_DATA_5_PRG
value|(0xffL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_PM_DATA_B_PM_DATA_6_PRG
value|(0xffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_PM_DATA_B_PM_DATA_7_PRG
value|(0xffL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_SWAP_DIAG0
value|0x00000418
end_define

begin_define
define|#
directive|define
name|BCE_PCI_SWAP_DIAG1
value|0x0000041c
end_define

begin_define
define|#
directive|define
name|BCE_PCI_EXP_ROM_ADDR
value|0x00000420
end_define

begin_define
define|#
directive|define
name|BCE_PCI_EXP_ROM_ADDR_ADDRESS
value|(0x3fffffL<<2)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_EXP_ROM_ADDR_REQ
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_EXP_ROM_DATA
value|0x00000424
end_define

begin_define
define|#
directive|define
name|BCE_PCI_VPD_INTF
value|0x00000428
end_define

begin_define
define|#
directive|define
name|BCE_PCI_VPD_INTF_INTF_REQ
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_VPD_ADDR_FLAG
value|0x0000042c
end_define

begin_define
define|#
directive|define
name|BCE_PCI_VPD_ADDR_FLAG_ADDRESS
value|(0x1fff<<2)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_VPD_ADDR_FLAG_WR
value|(1<<15)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_VPD_DATA
value|0x00000430
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL1
value|0x00000434
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL1_DEVICE_ID
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL1_VENDOR_ID
value|(0xffffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL2
value|0x00000438
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL2_SUBSYSTEM_VENDOR_ID
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL2_SUBSYSTEM_ID
value|(0xffffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL3
value|0x0000043c
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL3_CLASS_CODE
value|(0xffffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL3_REVISION_ID
value|(0xffL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4
value|0x00000440
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_CAP_ENA
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_CAP_ENA_0
value|(0L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_CAP_ENA_1
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_CAP_ENA_2
value|(2L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_CAP_ENA_3
value|(3L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_CAP_ENA_4
value|(4L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_CAP_ENA_5
value|(5L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_CAP_ENA_6
value|(6L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_CAP_ENA_7
value|(7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_CAP_ENA_8
value|(8L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_CAP_ENA_9
value|(9L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_CAP_ENA_10
value|(10L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_CAP_ENA_11
value|(11L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_CAP_ENA_12
value|(12L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_CAP_ENA_13
value|(13L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_CAP_ENA_14
value|(14L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_CAP_ENA_15
value|(15L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_PM_SCALE_PRG
value|(0x3L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_PM_SCALE_PRG_0
value|(0L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_PM_SCALE_PRG_1
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_PM_SCALE_PRG_2
value|(2L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_PM_SCALE_PRG_3
value|(3L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_MSI_LIMIT
value|(0x7L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_MSI_ADVERTIZE
value|(0x7L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_MSI_ENABLE
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_MAX_64_ADVERTIZE
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_MAX_133_ADVERTIZE
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_MAX_MEM_READ_SIZE
value|(0x3L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_MAX_SPLIT_SIZE
value|(0x7L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL4_MAX_CUMULATIVE_SIZE
value|(0x7L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL5
value|0x00000444
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL5_D1_SUPPORT
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL5_D2_SUPPORT
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL5_PME_IN_D0
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL5_PME_IN_D1
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL5_PME_IN_D2
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL5_PME_IN_D3_HOT
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_PCIX_EXTENDED_STATUS
value|0x00000448
end_define

begin_define
define|#
directive|define
name|BCE_PCI_PCIX_EXTENDED_STATUS_NO_SNOOP
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_PCIX_EXTENDED_STATUS_LONG_BURST
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_PCIX_EXTENDED_STATUS_SPLIT_COMP_MSG_CLASS
value|(0xfL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_PCIX_EXTENDED_STATUS_SPLIT_COMP_MSG_IDX
value|(0xffL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL6
value|0x0000044c
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL6_MAX_LAT
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL6_MIN_GNT
value|(0xffL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_ID_VAL6_BIST
value|(0xffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_MSI_DATA
value|0x00000450
end_define

begin_define
define|#
directive|define
name|BCE_PCI_MSI_DATA_PCI_MSI_DATA
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_PCI_MSI_ADDR_H
value|0x00000454
end_define

begin_define
define|#
directive|define
name|BCE_PCI_MSI_ADDR_L
value|0x00000458
end_define

begin_comment
comment|/*  *  misc_reg definition  *  offset: 0x800  */
end_comment

begin_define
define|#
directive|define
name|BCE_MISC_COMMAND
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BCE_MISC_COMMAND_ENABLE_ALL
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_COMMAND_DISABLE_ALL
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_COMMAND_CORE_RESET
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_COMMAND_HARD_RESET
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_COMMAND_PAR_ERROR
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_COMMAND_PAR_ERR_RAM
value|(0x7fL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CFG
value|0x00000804
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CFG_PCI_GRC_TMOUT
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CFG_NVM_WR_EN
value|(0x3L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CFG_NVM_WR_EN_PROTECT
value|(0L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CFG_NVM_WR_EN_PCI
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CFG_NVM_WR_EN_ALLOW
value|(2L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CFG_NVM_WR_EN_ALLOW2
value|(3L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CFG_BIST_EN
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CFG_CK25_OUT_ALT_SRC
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CFG_BYPASS_BSCAN
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CFG_BYPASS_EJTAG
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CFG_CLK_CTL_OVERRIDE
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CFG_LEDMODE
value|(0x3L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CFG_LEDMODE_MAC
value|(0L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CFG_LEDMODE_GPHY1
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CFG_LEDMODE_GPHY2
value|(2L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ID
value|0x00000808
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ID_BOND_ID
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ID_CHIP_METAL
value|(0xffL<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ID_CHIP_REV
value|(0xfL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ID_CHIP_NUM
value|(0xffffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS
value|0x0000080c
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_TX_SCHEDULER_ENABLE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_TX_BD_READ_ENABLE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_TX_BD_CACHE_ENABLE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_TX_PROCESSOR_ENABLE
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_TX_DMA_ENABLE
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_TX_PATCHUP_ENABLE
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_TX_PAYLOAD_Q_ENABLE
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_TX_HEADER_Q_ENABLE
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_TX_ASSEMBLER_ENABLE
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_EMAC_ENABLE
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_RX_PARSER_MAC_ENABLE
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_RX_PARSER_CATCHUP_ENABLE
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_RX_MBUF_ENABLE
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_RX_LOOKUP_ENABLE
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_RX_PROCESSOR_ENABLE
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_RX_V2P_ENABLE
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_RX_BD_CACHE_ENABLE
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_RX_DMA_ENABLE
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_COMPLETION_ENABLE
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_HOST_COALESCE_ENABLE
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_MAILBOX_QUEUE_ENABLE
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_CONTEXT_ENABLE
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_CMD_SCHEDULER_ENABLE
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_CMD_PROCESSOR_ENABLE
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_MGMT_PROCESSOR_ENABLE
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_TIMER_ENABLE
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_DMA_ENGINE_ENABLE
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_STATUS_BITS_UMP_ENABLE
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS
value|0x00000810
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_TX_SCHEDULER_ENABLE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_TX_BD_READ_ENABLE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_TX_BD_CACHE_ENABLE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_TX_PROCESSOR_ENABLE
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_TX_DMA_ENABLE
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_TX_PATCHUP_ENABLE
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_TX_PAYLOAD_Q_ENABLE
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_TX_HEADER_Q_ENABLE
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_TX_ASSEMBLER_ENABLE
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_EMAC_ENABLE
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_RX_PARSER_MAC_ENABLE
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_RX_PARSER_CATCHUP_ENABLE
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_RX_MBUF_ENABLE
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_RX_LOOKUP_ENABLE
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_RX_PROCESSOR_ENABLE
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_RX_V2P_ENABLE
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_RX_BD_CACHE_ENABLE
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_RX_DMA_ENABLE
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_COMPLETION_ENABLE
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_HOST_COALESCE_ENABLE
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_MAILBOX_QUEUE_ENABLE
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_CONTEXT_ENABLE
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_CMD_SCHEDULER_ENABLE
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_CMD_PROCESSOR_ENABLE
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_MGMT_PROCESSOR_ENABLE
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_TIMER_ENABLE
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_DMA_ENGINE_ENABLE
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_SET_BITS_UMP_ENABLE
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS
value|0x00000814
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_TX_SCHEDULER_ENABLE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_TX_BD_READ_ENABLE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_TX_BD_CACHE_ENABLE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_TX_PROCESSOR_ENABLE
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_TX_DMA_ENABLE
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_TX_PATCHUP_ENABLE
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_TX_PAYLOAD_Q_ENABLE
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_TX_HEADER_Q_ENABLE
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_TX_ASSEMBLER_ENABLE
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_EMAC_ENABLE
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_RX_PARSER_MAC_ENABLE
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_RX_PARSER_CATCHUP_ENABLE
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_RX_MBUF_ENABLE
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_RX_LOOKUP_ENABLE
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_RX_PROCESSOR_ENABLE
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_RX_V2P_ENABLE
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_RX_BD_CACHE_ENABLE
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_RX_DMA_ENABLE
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_COMPLETION_ENABLE
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_HOST_COALESCE_ENABLE
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_MAILBOX_QUEUE_ENABLE
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_CONTEXT_ENABLE
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_CMD_SCHEDULER_ENABLE
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_CMD_PROCESSOR_ENABLE
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_MGMT_PROCESSOR_ENABLE
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_TIMER_ENABLE
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_DMA_ENGINE_ENABLE
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ENABLE_CLR_BITS_UMP_ENABLE
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS
value|0x00000818
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_PCI_CLK_SPD_DET
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_PCI_CLK_SPD_DET_32MHZ
value|(0L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_PCI_CLK_SPD_DET_38MHZ
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_PCI_CLK_SPD_DET_48MHZ
value|(2L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_PCI_CLK_SPD_DET_55MHZ
value|(3L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_PCI_CLK_SPD_DET_66MHZ
value|(4L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_PCI_CLK_SPD_DET_80MHZ
value|(5L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_PCI_CLK_SPD_DET_95MHZ
value|(6L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_PCI_CLK_SPD_DET_133MHZ
value|(7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_PCI_CLK_SPD_DET_LOW
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_CORE_CLK_DISABLE
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_CORE_CLK_ALT
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_CORE_CLK_ALT_SRC
value|(0x7L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_CORE_CLK_ALT_SRC_UNDEF
value|(0L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_CORE_CLK_ALT_SRC_12
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_CORE_CLK_ALT_SRC_6
value|(2L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_CORE_CLK_ALT_SRC_62
value|(4L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_PLAY_DEAD
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_CORE_CLK_PLL_SPEED
value|(0xfL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_CORE_CLK_PLL_SPEED_100
value|(0L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_CORE_CLK_PLL_SPEED_80
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_CORE_CLK_PLL_SPEED_50
value|(2L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_CORE_CLK_PLL_SPEED_40
value|(4L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_CORE_CLK_PLL_SPEED_25
value|(8L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_CORE_CLK_PLL_STOP
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_PCI_PLL_STOP
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_RESERVED_18
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_USE_SPD_DET
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CLOCK_CONTROL_BITS_RESERVED
value|(0xfffL<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_GPIO
value|0x0000081c
end_define

begin_define
define|#
directive|define
name|BCE_MISC_GPIO_VALUE
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_GPIO_SET
value|(0xffL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_GPIO_CLR
value|(0xffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_GPIO_FLOAT
value|(0xffL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_GPIO_INT
value|0x00000820
end_define

begin_define
define|#
directive|define
name|BCE_MISC_GPIO_INT_INT_STATE
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_GPIO_INT_OLD_VALUE
value|(0xfL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_GPIO_INT_OLD_SET
value|(0xfL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_GPIO_INT_OLD_CLR
value|(0xfL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CONFIG_LFSR
value|0x00000824
end_define

begin_define
define|#
directive|define
name|BCE_MISC_CONFIG_LFSR_DIV
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS
value|0x00000828
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_TX_SCHEDULER_ENABLE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_TX_BD_READ_ENABLE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_TX_BD_CACHE_ENABLE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_TX_PROCESSOR_ENABLE
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_TX_DMA_ENABLE
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_TX_PATCHUP_ENABLE
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_TX_PAYLOAD_Q_ENABLE
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_TX_HEADER_Q_ENABLE
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_TX_ASSEMBLER_ENABLE
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_EMAC_ENABLE
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_RX_PARSER_MAC_ENABLE
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_RX_PARSER_CATCHUP_ENABLE
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_RX_MBUF_ENABLE
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_RX_LOOKUP_ENABLE
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_RX_PROCESSOR_ENABLE
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_RX_V2P_ENABLE
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_RX_BD_CACHE_ENABLE
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_RX_DMA_ENABLE
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_COMPLETION_ENABLE
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_HOST_COALESCE_ENABLE
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_MAILBOX_QUEUE_ENABLE
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_CONTEXT_ENABLE
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_CMD_SCHEDULER_ENABLE
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_CMD_PROCESSOR_ENABLE
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_MGMT_PROCESSOR_ENABLE
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_TIMER_ENABLE
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_DMA_ENGINE_ENABLE
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_LFSR_MASK_BITS_UMP_ENABLE
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_REQ0
value|0x0000082c
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_REQ1
value|0x00000830
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_REQ2
value|0x00000834
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_REQ3
value|0x00000838
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_REQ4
value|0x0000083c
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_FREE0
value|0x00000840
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_FREE1
value|0x00000844
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_FREE2
value|0x00000848
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_FREE3
value|0x0000084c
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_FREE4
value|0x00000850
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_REQ_STATUS0
value|0x00000854
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_REQ_STATUS1
value|0x00000858
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_REQ_STATUS2
value|0x0000085c
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_REQ_STATUS3
value|0x00000860
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_REQ_STATUS4
value|0x00000864
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT0
value|0x00000868
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT0_0
value|(0x7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT0_1
value|(0x7L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT0_2
value|(0x7L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT0_3
value|(0x7L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT0_4
value|(0x7L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT0_5
value|(0x7L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT0_6
value|(0x7L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT0_7
value|(0x7L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT1
value|0x0000086c
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT1_8
value|(0x7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT1_9
value|(0x7L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT1_10
value|(0x7L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT1_11
value|(0x7L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT1_12
value|(0x7L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT1_13
value|(0x7L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT1_14
value|(0x7L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT1_15
value|(0x7L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT2
value|0x00000870
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT2_16
value|(0x7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT2_17
value|(0x7L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT2_18
value|(0x7L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT2_19
value|(0x7L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT2_20
value|(0x7L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT2_21
value|(0x7L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT2_22
value|(0x7L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT2_23
value|(0x7L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT3
value|0x00000874
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT3_24
value|(0x7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT3_25
value|(0x7L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT3_26
value|(0x7L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT3_27
value|(0x7L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT3_28
value|(0x7L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT3_29
value|(0x7L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT3_30
value|(0x7L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_ARB_GNT3_31
value|(0x7L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PRBS_CONTROL
value|0x00000878
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PRBS_CONTROL_EN
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PRBS_CONTROL_RSTB
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PRBS_CONTROL_INV
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PRBS_CONTROL_ERR_CLR
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PRBS_CONTROL_ORDER
value|(0x3L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PRBS_CONTROL_ORDER_7TH
value|(0L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PRBS_CONTROL_ORDER_15TH
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PRBS_CONTROL_ORDER_23RD
value|(2L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PRBS_CONTROL_ORDER_31ST
value|(3L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PRBS_STATUS
value|0x0000087c
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PRBS_STATUS_LOCK
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PRBS_STATUS_STKY
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PRBS_STATUS_ERRORS
value|(0x3fffL<<2)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PRBS_STATUS_STATE
value|(0xfL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SM_ASF_CONTROL
value|0x00000880
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SM_ASF_CONTROL_ASF_RST
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SM_ASF_CONTROL_TSC_EN
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SM_ASF_CONTROL_WG_TO
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SM_ASF_CONTROL_HB_TO
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SM_ASF_CONTROL_PA_TO
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SM_ASF_CONTROL_PL_TO
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SM_ASF_CONTROL_RT_TO
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SM_ASF_CONTROL_SMB_EVENT
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SM_ASF_CONTROL_RES
value|(0xfL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SM_ASF_CONTROL_SMB_EN
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SM_ASF_CONTROL_SMB_BB_EN
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SM_ASF_CONTROL_SMB_NO_ADDR_FILT
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SM_ASF_CONTROL_SMB_AUTOREAD
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SM_ASF_CONTROL_NIC_SMB_ADDR1
value|(0x3fL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SM_ASF_CONTROL_NIC_SMB_ADDR2
value|(0x3fL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SM_ASF_CONTROL_EN_NIC_SMB_ADDR_0
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SM_ASF_CONTROL_SMB_EARLY_ATTN
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_IN
value|0x00000884
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_IN_DAT_IN
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_IN_RDY
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_IN_DONE
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_IN_FIRSTBYTE
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_IN_STATUS
value|(0x7L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_IN_STATUS_OK
value|(0x0L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_IN_STATUS_PEC
value|(0x1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_IN_STATUS_OFLOW
value|(0x2L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_IN_STATUS_STOP
value|(0x3L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_IN_STATUS_TIMEOUT
value|(0x4L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT
value|0x00000888
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_DAT_OUT
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_RDY
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_START
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_LAST
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_ACC_TYPE
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_ENB_PEC
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_GET_RX_LEN
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_SMB_READ_LEN
value|(0x3fL<<14)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_SMB_OUT_STATUS
value|(0xfL<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_SMB_OUT_STATUS_OK
value|(0L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_SMB_OUT_STATUS_FIRST_NACK
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_SMB_OUT_STATUS_SUB_NACK
value|(9L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_SMB_OUT_STATUS_UFLOW
value|(2L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_SMB_OUT_STATUS_STOP
value|(3L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_SMB_OUT_STATUS_TIMEOUT
value|(4L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_SMB_OUT_STATUS_FIRST_LOST
value|(5L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_SMB_OUT_STATUS_SUB_LOST
value|(0xdL<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_SMB_OUT_STATUS_BADACK
value|(0x6L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_SMB_OUT_SLAVEMODE
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_SMB_OUT_DAT_EN
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_SMB_OUT_DAT_IN
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_SMB_OUT_CLK_EN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_OUT_SMB_OUT_CLK_IN
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_WATCHDOG
value|0x0000088c
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_WATCHDOG_WATCHDOG
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_HEARTBEAT
value|0x00000890
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_HEARTBEAT_HEARTBEAT
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_POLL_ASF
value|0x00000894
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_POLL_ASF_POLL_ASF
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_POLL_LEGACY
value|0x00000898
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_POLL_LEGACY_POLL_LEGACY
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_RETRAN
value|0x0000089c
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_RETRAN_RETRAN
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_TIMESTAMP
value|0x000008a0
end_define

begin_define
define|#
directive|define
name|BCE_MISC_SMB_TIMESTAMP_TIMESTAMP
value|(0xffffffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0
value|0x000008a4
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_COM_MISC_CTXC
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_COM_MISC_REGF
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_COM_MISC_SCPAD
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_CP_MISC_CTXC
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_CP_MISC_REGF
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_CP_MISC_SCPAD
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_CS_MISC_TMEM
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_CTX_MISC_ACCM0
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_CTX_MISC_ACCM1
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_CTX_MISC_ACCM2
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_CTX_MISC_ACCM3
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_CTX_MISC_ACCM4
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_CTX_MISC_ACCM5
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_CTX_MISC_PGTBL
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_DMAE_MISC_DR0
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_DMAE_MISC_DR1
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_DMAE_MISC_DR2
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_DMAE_MISC_DR3
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_DMAE_MISC_DR4
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_DMAE_MISC_DW0
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_DMAE_MISC_DW1
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_DMAE_MISC_DW2
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_HC_MISC_DMA
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_MCP_MISC_REGF
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_MCP_MISC_SCPAD
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_MQ_MISC_CTX
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_RBDC_MISC
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_RBUF_MISC_MB
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_RBUF_MISC_PTR
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_RDE_MISC_RPC
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_RDE_MISC_RPM
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA0_RV2P_MISC_CB0REGS
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1
value|0x000008a8
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_RV2P_MISC_CB1REGS
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_RV2P_MISC_P1IRAM
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_RV2P_MISC_P2IRAM
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_RXP_MISC_CTXC
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_RXP_MISC_REGF
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_RXP_MISC_SCPAD
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_RXP_MISC_RBUFC
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_TBDC_MISC
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_TDMA_MISC
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_THBUF_MISC_MB0
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_THBUF_MISC_MB1
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_TPAT_MISC_REGF
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_TPAT_MISC_SCPAD
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_TPBUF_MISC_MB
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_TSCH_MISC_LR
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_TXP_MISC_CTXC
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_TXP_MISC_REGF
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_TXP_MISC_SCPAD
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_UMP_MISC_FIORX
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_UMP_MISC_FIOTX
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_UMP_MISC_RX
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_UMP_MISC_TX
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_RDMAQ_MISC
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_CSQ_MISC
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_CPQ_MISC
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_MCPQ_MISC
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_RV2PMQ_MISC
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_RV2PPQ_MISC
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_RV2PTQ_MISC
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_RXPQ_MISC
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_RXPCQ_MISC
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA1_RLUPQ_MISC
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA2
value|0x000008ac
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA2_COMQ_MISC
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA2_COMXQ_MISC
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA2_COMTQ_MISC
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA2_TSCHQ_MISC
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA2_TBDRQ_MISC
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA2_TXPQ_MISC
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA2_TDMAQ_MISC
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA2_TPATQ_MISC
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_PERR_ENA2_TASQ_MISC
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_DEBUG_VECTOR_SEL
value|0x000008b0
end_define

begin_define
define|#
directive|define
name|BCE_MISC_DEBUG_VECTOR_SEL_0
value|(0xfffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_DEBUG_VECTOR_SEL_1
value|(0xfffL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_VREG_CONTROL
value|0x000008b4
end_define

begin_define
define|#
directive|define
name|BCE_MISC_VREG_CONTROL_1_2
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_VREG_CONTROL_2_5
value|(0xfL<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_FINAL_CLK_CTL_VAL
value|0x000008b8
end_define

begin_define
define|#
directive|define
name|BCE_MISC_FINAL_CLK_CTL_VAL_MISC_FINAL_CLK_CTL_VAL
value|(0x3ffffffL<<6)
end_define

begin_define
define|#
directive|define
name|BCE_MISC_UNUSED0
value|0x000008bc
end_define

begin_comment
comment|/*  *  nvm_reg definition  *  offset: 0x6400  */
end_comment

begin_define
define|#
directive|define
name|BCE_NVM_COMMAND
value|0x00006400
end_define

begin_define
define|#
directive|define
name|BCE_NVM_COMMAND_RST
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_COMMAND_DONE
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_COMMAND_DOIT
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_COMMAND_WR
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_COMMAND_ERASE
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_COMMAND_FIRST
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_COMMAND_LAST
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_COMMAND_WREN
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_COMMAND_WRDI
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_COMMAND_EWSR
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_COMMAND_WRSR
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_STATUS
value|0x00006404
end_define

begin_define
define|#
directive|define
name|BCE_NVM_STATUS_PI_FSM_STATE
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_STATUS_EE_FSM_STATE
value|(0xfL<<4)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_STATUS_EQ_FSM_STATE
value|(0xfL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_WRITE
value|0x00006408
end_define

begin_define
define|#
directive|define
name|BCE_NVM_WRITE_NVM_WRITE_VALUE
value|(0xffffffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_WRITE_NVM_WRITE_VALUE_BIT_BANG
value|(0L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_WRITE_NVM_WRITE_VALUE_EECLK
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_WRITE_NVM_WRITE_VALUE_EEDATA
value|(2L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_WRITE_NVM_WRITE_VALUE_SCLK
value|(4L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_WRITE_NVM_WRITE_VALUE_CS_B
value|(8L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_WRITE_NVM_WRITE_VALUE_SO
value|(16L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_WRITE_NVM_WRITE_VALUE_SI
value|(32L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_ADDR
value|0x0000640c
end_define

begin_define
define|#
directive|define
name|BCE_NVM_ADDR_NVM_ADDR_VALUE
value|(0xffffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_ADDR_NVM_ADDR_VALUE_BIT_BANG
value|(0L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_ADDR_NVM_ADDR_VALUE_EECLK
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_ADDR_NVM_ADDR_VALUE_EEDATA
value|(2L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_ADDR_NVM_ADDR_VALUE_SCLK
value|(4L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_ADDR_NVM_ADDR_VALUE_CS_B
value|(8L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_ADDR_NVM_ADDR_VALUE_SO
value|(16L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_ADDR_NVM_ADDR_VALUE_SI
value|(32L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_READ
value|0x00006410
end_define

begin_define
define|#
directive|define
name|BCE_NVM_READ_NVM_READ_VALUE
value|(0xffffffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_READ_NVM_READ_VALUE_BIT_BANG
value|(0L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_READ_NVM_READ_VALUE_EECLK
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_READ_NVM_READ_VALUE_EEDATA
value|(2L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_READ_NVM_READ_VALUE_SCLK
value|(4L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_READ_NVM_READ_VALUE_CS_B
value|(8L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_READ_NVM_READ_VALUE_SO
value|(16L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_READ_NVM_READ_VALUE_SI
value|(32L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG1
value|0x00006414
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG1_FLASH_MODE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG1_BUFFER_MODE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG1_PASS_MODE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG1_BITBANG_MODE
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG1_STATUS_BIT
value|(0x7L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG1_STATUS_BIT_FLASH_RDY
value|(0L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG1_STATUS_BIT_BUFFER_RDY
value|(7L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG1_SPI_CLK_DIV
value|(0xfL<<7)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG1_SEE_CLK_DIV
value|(0x7ffL<<11)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG1_PROTECT_MODE
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG1_FLASH_SIZE
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG1_COMPAT_BYPASSS
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG2
value|0x00006418
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG2_ERASE_CMD
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG2_DUMMY
value|(0xffL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG2_STATUS_CMD
value|(0xffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG3
value|0x0000641c
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG3_BUFFER_RD_CMD
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG3_WRITE_CMD
value|(0xffL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG3_BUFFER_WRITE_CMD
value|(0xffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_CFG3_READ_CMD
value|(0xffL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_SW_ARB
value|0x00006420
end_define

begin_define
define|#
directive|define
name|BCE_NVM_SW_ARB_ARB_REQ_SET0
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_SW_ARB_ARB_REQ_SET1
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_SW_ARB_ARB_REQ_SET2
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_SW_ARB_ARB_REQ_SET3
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_SW_ARB_ARB_REQ_CLR0
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_SW_ARB_ARB_REQ_CLR1
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_SW_ARB_ARB_REQ_CLR2
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_SW_ARB_ARB_REQ_CLR3
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_SW_ARB_ARB_ARB0
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_SW_ARB_ARB_ARB1
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_SW_ARB_ARB_ARB2
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_SW_ARB_ARB_ARB3
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_SW_ARB_REQ0
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_SW_ARB_REQ1
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_SW_ARB_REQ2
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_SW_ARB_REQ3
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_ACCESS_ENABLE
value|0x00006424
end_define

begin_define
define|#
directive|define
name|BCE_NVM_ACCESS_ENABLE_EN
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_ACCESS_ENABLE_WR_EN
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_WRITE1
value|0x00006428
end_define

begin_define
define|#
directive|define
name|BCE_NVM_WRITE1_WREN_CMD
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_WRITE1_WRDI_CMD
value|(0xffL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_NVM_WRITE1_SR_DATA
value|(0xffL<<16)
end_define

begin_comment
comment|/*  *  dma_reg definition  *  offset: 0xc00  */
end_comment

begin_define
define|#
directive|define
name|BCE_DMA_COMMAND
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|BCE_DMA_COMMAND_ENABLE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_STATUS
value|0x00000c04
end_define

begin_define
define|#
directive|define
name|BCE_DMA_STATUS_PAR_ERROR_STATE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_STATUS_READ_TRANSFERS_STAT
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_STATUS_READ_DELAY_PCI_CLKS_STAT
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_STATUS_BIG_READ_TRANSFERS_STAT
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_STATUS_BIG_READ_DELAY_PCI_CLKS_STAT
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_STATUS_BIG_READ_RETRY_AFTER_DATA_STAT
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_STATUS_WRITE_TRANSFERS_STAT
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_STATUS_WRITE_DELAY_PCI_CLKS_STAT
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_STATUS_BIG_WRITE_TRANSFERS_STAT
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_STATUS_BIG_WRITE_DELAY_PCI_CLKS_STAT
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_STATUS_BIG_WRITE_RETRY_AFTER_DATA_STAT
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_CONFIG
value|0x00000c08
end_define

begin_define
define|#
directive|define
name|BCE_DMA_CONFIG_DATA_BYTE_SWAP
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_CONFIG_DATA_WORD_SWAP
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_CONFIG_CNTL_BYTE_SWAP
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_CONFIG_CNTL_WORD_SWAP
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_CONFIG_ONE_DMA
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_CONFIG_CNTL_TWO_DMA
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_CONFIG_CNTL_FPGA_MODE
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_CONFIG_CNTL_PING_PONG_DMA
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_CONFIG_CNTL_PCI_COMP_DLY
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_CONFIG_NO_RCHANS_IN_USE
value|(0xfL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_CONFIG_NO_WCHANS_IN_USE
value|(0xfL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_CONFIG_PCI_CLK_CMP_BITS
value|(0x7L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_CONFIG_PCI_FAST_CLK_CMP
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_CONFIG_BIG_SIZE
value|(0xfL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_CONFIG_BIG_SIZE_NONE
value|(0x0L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_CONFIG_BIG_SIZE_64
value|(0x1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_CONFIG_BIG_SIZE_128
value|(0x2L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_CONFIG_BIG_SIZE_256
value|(0x4L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_CONFIG_BIG_SIZE_512
value|(0x8L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_BLACKOUT
value|0x00000c0c
end_define

begin_define
define|#
directive|define
name|BCE_DMA_BLACKOUT_RD_RETRY_BLACKOUT
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_BLACKOUT_2ND_RD_RETRY_BLACKOUT
value|(0xffL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_BLACKOUT_WR_RETRY_BLACKOUT
value|(0xffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT
value|0x00000c30
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_COMP_CODE_0
value|(0x7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_PAR_ERR_0
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_COMP_CODE_1
value|(0x7L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_PAR_ERR_1
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_COMP_CODE_2
value|(0x7L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_PAR_ERR_2
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_COMP_CODE_3
value|(0x7L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_PAR_ERR_3
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_COMP_CODE_4
value|(0x7L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_PAR_ERR_4
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_COMP_CODE_5
value|(0x7L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_PAR_ERR_5
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_COMP_CODE_6
value|(0x7L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_PAR_ERR_6
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_COMP_CODE_7
value|(0x7L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_PAR_ERR_7
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT
value|0x00000c34
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_COMP_CODE_0
value|(0x7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_PAR_ERR_0
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_COMP_CODE_1
value|(0x7L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_PAR_ERR_1
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_COMP_CODE_2
value|(0x7L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_PAR_ERR_2
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_COMP_CODE_3
value|(0x7L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_PAR_ERR_3
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_COMP_CODE_4
value|(0x7L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_PAR_ERR_4
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_COMP_CODE_5
value|(0x7L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_PAR_ERR_5
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_COMP_CODE_6
value|(0x7L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_PAR_ERR_6
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_COMP_CODE_7
value|(0x7L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_PAR_ERR_7
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_ASSIGNMENT
value|0x00000c38
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_ASSIGNMENT_0
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_ASSIGNMENT_1
value|(0xfL<<4)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_ASSIGNMENT_2
value|(0xfL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_ASSIGNMENT_3
value|(0xfL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_ASSIGNMENT_4
value|(0xfL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_ASSIGNMENT_5
value|(0xfL<<20)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_ASSIGNMENT_6
value|(0xfL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_ASSIGNMENT_7
value|(0xfL<<28)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_ASSIGNMENT
value|0x00000c3c
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_ASSIGNMENT_0
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_ASSIGNMENT_1
value|(0xfL<<4)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_ASSIGNMENT_2
value|(0xfL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_ASSIGNMENT_3
value|(0xfL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_ASSIGNMENT_4
value|(0xfL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_ASSIGNMENT_5
value|(0xfL<<20)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_ASSIGNMENT_6
value|(0xfL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_ASSIGNMENT_7
value|(0xfL<<28)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_00
value|0x00000c40
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_00_RCHAN_STA_HOST_ADDR_LOW
value|(0xffffffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_01
value|0x00000c44
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_01_RCHAN_STA_HOST_ADDR_HIGH
value|(0xffffffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_02
value|0x00000c48
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_02_LENGTH
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_02_WORD_SWAP
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_02_BYTE_SWAP
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_02_PRIORITY_LVL
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_10
value|0x00000c4c
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_11
value|0x00000c50
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_12
value|0x00000c54
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_20
value|0x00000c58
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_21
value|0x00000c5c
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_22
value|0x00000c60
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_30
value|0x00000c64
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_31
value|0x00000c68
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_32
value|0x00000c6c
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_40
value|0x00000c70
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_41
value|0x00000c74
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_42
value|0x00000c78
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_50
value|0x00000c7c
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_51
value|0x00000c80
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_52
value|0x00000c84
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_60
value|0x00000c88
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_61
value|0x00000c8c
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_62
value|0x00000c90
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_70
value|0x00000c94
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_71
value|0x00000c98
end_define

begin_define
define|#
directive|define
name|BCE_DMA_RCHAN_STAT_72
value|0x00000c9c
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_00
value|0x00000ca0
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_00_WCHAN_STA_HOST_ADDR_LOW
value|(0xffffffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_01
value|0x00000ca4
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_01_WCHAN_STA_HOST_ADDR_HIGH
value|(0xffffffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_02
value|0x00000ca8
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_02_LENGTH
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_02_WORD_SWAP
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_02_BYTE_SWAP
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_02_PRIORITY_LVL
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_10
value|0x00000cac
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_11
value|0x00000cb0
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_12
value|0x00000cb4
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_20
value|0x00000cb8
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_21
value|0x00000cbc
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_22
value|0x00000cc0
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_30
value|0x00000cc4
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_31
value|0x00000cc8
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_32
value|0x00000ccc
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_40
value|0x00000cd0
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_41
value|0x00000cd4
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_42
value|0x00000cd8
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_50
value|0x00000cdc
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_51
value|0x00000ce0
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_52
value|0x00000ce4
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_60
value|0x00000ce8
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_61
value|0x00000cec
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_62
value|0x00000cf0
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_70
value|0x00000cf4
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_71
value|0x00000cf8
end_define

begin_define
define|#
directive|define
name|BCE_DMA_WCHAN_STAT_72
value|0x00000cfc
end_define

begin_define
define|#
directive|define
name|BCE_DMA_ARB_STAT_00
value|0x00000d00
end_define

begin_define
define|#
directive|define
name|BCE_DMA_ARB_STAT_00_MASTER
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_ARB_STAT_00_MASTER_ENC
value|(0xffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_ARB_STAT_00_CUR_BINMSTR
value|(0xffL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_ARB_STAT_01
value|0x00000d04
end_define

begin_define
define|#
directive|define
name|BCE_DMA_ARB_STAT_01_LPR_RPTR
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_ARB_STAT_01_LPR_WPTR
value|(0xfL<<4)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_ARB_STAT_01_LPB_RPTR
value|(0xfL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_ARB_STAT_01_LPB_WPTR
value|(0xfL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_ARB_STAT_01_HPR_RPTR
value|(0xfL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_ARB_STAT_01_HPR_WPTR
value|(0xfL<<20)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_ARB_STAT_01_HPB_RPTR
value|(0xfL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_ARB_STAT_01_HPB_WPTR
value|(0xfL<<28)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL0_CMD
value|0x00000f00
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL0_CMD_PWRUP_DONE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL0_CMD_SHIFT_DONE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL0_CMD_SHIFT
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL0_CMD_LOAD
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL0_CMD_SEL
value|(0xfL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL0_DATA
value|0x00000f04
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL1_CMD
value|0x00000f08
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL1_CMD_PWRUP_DONE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL1_CMD_SHIFT_DONE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL1_CMD_SHIFT
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL1_CMD_LOAD
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL1_CMD_SEL
value|(0xfL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL1_DATA
value|0x00000f0c
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL2_CMD
value|0x00000f10
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL2_CMD_PWRUP_DONE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL2_CMD_SHIFT_DONE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL2_CMD_SHIFT
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL2_CMD_LOAD
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL2_CMD_SEL
value|(0xfL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_DMA_FUSE_CTRL2_DATA
value|0x00000f14
end_define

begin_comment
comment|/*  *  context_reg definition  *  offset: 0x1000  */
end_comment

begin_define
define|#
directive|define
name|BCE_CTX_COMMAND
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BCE_CTX_COMMAND_ENABLED
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_STATUS
value|0x00001004
end_define

begin_define
define|#
directive|define
name|BCE_CTX_STATUS_LOCK_WAIT
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_STATUS_READ_STAT
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_STATUS_WRITE_STAT
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_STATUS_ACC_STALL_STAT
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_STATUS_LOCK_STALL_STAT
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_VIRT_ADDR
value|0x00001008
end_define

begin_define
define|#
directive|define
name|BCE_CTX_VIRT_ADDR_VIRT_ADDR
value|(0x7fffL<<6)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_PAGE_TBL
value|0x0000100c
end_define

begin_define
define|#
directive|define
name|BCE_CTX_PAGE_TBL_PAGE_TBL
value|(0x3fffL<<6)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_DATA_ADR
value|0x00001010
end_define

begin_define
define|#
directive|define
name|BCE_CTX_DATA_ADR_DATA_ADR
value|(0x7ffffL<<2)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_DATA
value|0x00001014
end_define

begin_define
define|#
directive|define
name|BCE_CTX_LOCK
value|0x00001018
end_define

begin_define
define|#
directive|define
name|BCE_CTX_LOCK_TYPE
value|(0x7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_LOCK_TYPE_LOCK_TYPE_VOID
value|(0x0L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_LOCK_TYPE_LOCK_TYPE_COMPLETE
value|(0x7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_LOCK_TYPE_LOCK_TYPE_PROTOCOL
value|(0x1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_LOCK_TYPE_LOCK_TYPE_TX
value|(0x2L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_LOCK_TYPE_LOCK_TYPE_TIMER
value|(0x4L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_LOCK_CID_VALUE
value|(0x3fffL<<7)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_LOCK_GRANTED
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_LOCK_MODE
value|(0x7L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_LOCK_MODE_UNLOCK
value|(0x0L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_LOCK_MODE_IMMEDIATE
value|(0x1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_LOCK_MODE_SURE
value|(0x2L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_LOCK_STATUS
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_LOCK_REQ
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_ACCESS_STATUS
value|0x00001040
end_define

begin_define
define|#
directive|define
name|BCE_CTX_ACCESS_STATUS_MASTERENCODED
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_ACCESS_STATUS_ACCESSMEMORYSM
value|(0x3L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_ACCESS_STATUS_PAGETABLEINITSM
value|(0x3L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_ACCESS_STATUS_ACCESSMEMORYINITSM
value|(0x3L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_ACCESS_STATUS_QUALIFIED_REQUEST
value|(0x7ffL<<17)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_DBG_LOCK_STATUS
value|0x00001044
end_define

begin_define
define|#
directive|define
name|BCE_CTX_DBG_LOCK_STATUS_SM
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_DBG_LOCK_STATUS_MATCH
value|(0x3ffL<<22)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_CHNL_LOCK_STATUS_0
value|0x00001080
end_define

begin_define
define|#
directive|define
name|BCE_CTX_CHNL_LOCK_STATUS_0_CID
value|(0x3fffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_CHNL_LOCK_STATUS_0_TYPE
value|(0x3L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_CHNL_LOCK_STATUS_0_MODE
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_CTX_CHNL_LOCK_STATUS_1
value|0x00001084
end_define

begin_define
define|#
directive|define
name|BCE_CTX_CHNL_LOCK_STATUS_2
value|0x00001088
end_define

begin_define
define|#
directive|define
name|BCE_CTX_CHNL_LOCK_STATUS_3
value|0x0000108c
end_define

begin_define
define|#
directive|define
name|BCE_CTX_CHNL_LOCK_STATUS_4
value|0x00001090
end_define

begin_define
define|#
directive|define
name|BCE_CTX_CHNL_LOCK_STATUS_5
value|0x00001094
end_define

begin_define
define|#
directive|define
name|BCE_CTX_CHNL_LOCK_STATUS_6
value|0x00001098
end_define

begin_define
define|#
directive|define
name|BCE_CTX_CHNL_LOCK_STATUS_7
value|0x0000109c
end_define

begin_define
define|#
directive|define
name|BCE_CTX_CHNL_LOCK_STATUS_8
value|0x000010a0
end_define

begin_comment
comment|/*  *  emac_reg definition  *  offset: 0x1400  */
end_comment

begin_define
define|#
directive|define
name|BCE_EMAC_MODE
value|0x00001400
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MODE_RESET
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MODE_HALF_DUPLEX
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MODE_PORT
value|(0x3L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MODE_PORT_NONE
value|(0L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MODE_PORT_MII
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MODE_PORT_GMII
value|(2L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MODE_PORT_MII_10
value|(3L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MODE_MAC_LOOP
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MODE_25G
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MODE_TAGGED_MAC_CTL
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MODE_TX_BURST
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MODE_MAX_DEFER_DROP_ENA
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MODE_EXT_LINK_POL
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MODE_FORCE_LINK
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MODE_MPKT
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MODE_MPKT_RCVD
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MODE_ACPI_RCVD
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_STATUS
value|0x00001404
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_STATUS_LINK
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_STATUS_LINK_CHANGE
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_STATUS_MI_COMPLETE
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_STATUS_MI_INT
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_STATUS_AP_ERROR
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_STATUS_PARITY_ERROR_STATE
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_ATTENTION_ENA
value|0x00001408
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_ATTENTION_ENA_LINK
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_ATTENTION_ENA_MI_COMPLETE
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_ATTENTION_ENA_MI_INT
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_ATTENTION_ENA_AP_ERROR
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_LED
value|0x0000140c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_LED_OVERRIDE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_LED_1000MB_OVERRIDE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_LED_100MB_OVERRIDE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_LED_10MB_OVERRIDE
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_LED_TRAFFIC_OVERRIDE
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_LED_BLNK_TRAFFIC
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_LED_TRAFFIC
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_LED_1000MB
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_LED_100MB
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_LED_10MB
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_LED_TRAFFIC_STAT
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_LED_BLNK_RATE
value|(0xfffL<<19)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_LED_BLNK_RATE_ENA
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH0
value|0x00001410
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH1
value|0x00001414
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH2
value|0x00001418
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH3
value|0x0000141c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH4
value|0x00001420
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH5
value|0x00001424
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH6
value|0x00001428
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH7
value|0x0000142c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH8
value|0x00001430
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH9
value|0x00001434
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH10
value|0x00001438
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH11
value|0x0000143c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH12
value|0x00001440
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH13
value|0x00001444
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH14
value|0x00001448
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH15
value|0x0000144c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH16
value|0x00001450
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH17
value|0x00001454
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH18
value|0x00001458
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH19
value|0x0000145c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH20
value|0x00001460
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH21
value|0x00001464
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH22
value|0x00001468
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH23
value|0x0000146c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH24
value|0x00001470
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH25
value|0x00001474
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH26
value|0x00001478
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH27
value|0x0000147c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH28
value|0x00001480
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH29
value|0x00001484
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH30
value|0x00001488
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MAC_MATCH31
value|0x0000148c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_BACKOFF_SEED
value|0x00001498
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_BACKOFF_SEED_EMAC_BACKOFF_SEED
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_MTU_SIZE
value|0x0000149c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_MTU_SIZE_MTU_SIZE
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_MTU_SIZE_JUMBO_ENA
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_SERDES_CNTL
value|0x000014a4
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_SERDES_CNTL_RXR
value|(0x7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_SERDES_CNTL_RXG
value|(0x3L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_SERDES_CNTL_RXCKSEL
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_SERDES_CNTL_TXBIAS
value|(0x7L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_SERDES_CNTL_BGMAX
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_SERDES_CNTL_BGMIN
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_SERDES_CNTL_TXMODE
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_SERDES_CNTL_TXEDGE
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_SERDES_CNTL_SERDES_MODE
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_SERDES_CNTL_PLLTEST
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_SERDES_CNTL_CDET_EN
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_SERDES_CNTL_TBI_LBK
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_SERDES_CNTL_REMOTE_LBK
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_SERDES_CNTL_REV_PHASE
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_SERDES_CNTL_REGCTL12
value|(0x3L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_SERDES_CNTL_REGCTL25
value|(0x3L<<22)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_SERDES_STATUS
value|0x000014a8
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_SERDES_STATUS_RX_STAT
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_SERDES_STATUS_COMMA_DET
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_COMM
value|0x000014ac
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_COMM_DATA
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_COMM_REG_ADDR
value|(0x1fL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_COMM_PHY_ADDR
value|(0x1fL<<21)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_COMM_COMMAND
value|(0x3L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_COMM_COMMAND_UNDEFINED_0
value|(0L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_COMM_COMMAND_WRITE
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_COMM_COMMAND_READ
value|(2L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_COMM_COMMAND_UNDEFINED_3
value|(3L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_COMM_FAIL
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_COMM_START_BUSY
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_COMM_DISEXT
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_STATUS
value|0x000014b0
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_STATUS_LINK
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_STATUS_10MB
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_MODE
value|0x000014b4
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_MODE_SHORT_PREAMBLE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_MODE_AUTO_POLL
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_MODE_BIT_BANG
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_MODE_MDIO
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_MODE_MDIO_OE
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_MODE_MDC
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_MODE_MDINT
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_MODE_CLOCK_CNT
value|(0x1fL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_AUTO_STATUS
value|0x000014b8
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MDIO_AUTO_STATUS_AUTO_ERR
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_MODE
value|0x000014bc
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_MODE_RESET
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_MODE_EXT_PAUSE_EN
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_MODE_FLOW_EN
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_MODE_BIG_BACKOFF
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_MODE_LONG_PAUSE
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_MODE_LINK_AWARE
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STATUS
value|0x000014c0
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STATUS_XOFFED
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STATUS_XOFF_SENT
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STATUS_XON_SENT
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STATUS_LINK_UP
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STATUS_UNDERRUN
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_LENGTHS
value|0x000014c4
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_LENGTHS_SLOT
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_LENGTHS_IPG
value|(0xfL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_LENGTHS_IPG_CRS
value|(0x3L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_MODE
value|0x000014c8
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_MODE_RESET
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_MODE_FLOW_EN
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_MODE_KEEP_MAC_CONTROL
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_MODE_KEEP_PAUSE
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_MODE_ACCEPT_OVERSIZE
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_MODE_ACCEPT_RUNTS
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_MODE_LLC_CHK
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_MODE_PROMISCUOUS
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_MODE_NO_CRC_CHK
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_MODE_KEEP_VLAN_TAG
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_MODE_FILT_BROADCAST
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_MODE_SORT_MODE
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STATUS
value|0x000014cc
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STATUS_FFED
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STATUS_FF_RECEIVED
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STATUS_N_RECEIVED
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MULTICAST_HASH0
value|0x000014d0
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MULTICAST_HASH1
value|0x000014d4
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MULTICAST_HASH2
value|0x000014d8
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MULTICAST_HASH3
value|0x000014dc
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MULTICAST_HASH4
value|0x000014e0
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MULTICAST_HASH5
value|0x000014e4
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MULTICAST_HASH6
value|0x000014e8
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_MULTICAST_HASH7
value|0x000014ec
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_IFHCINOCTETS
value|0x00001500
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_IFHCINBADOCTETS
value|0x00001504
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_ETHERSTATSFRAGMENTS
value|0x00001508
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_IFHCINUCASTPKTS
value|0x0000150c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_IFHCINMULTICASTPKTS
value|0x00001510
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_IFHCINBROADCASTPKTS
value|0x00001514
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_DOT3STATSFCSERRORS
value|0x00001518
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_DOT3STATSALIGNMENTERRORS
value|0x0000151c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_DOT3STATSCARRIERSENSEERRORS
value|0x00001520
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_XONPAUSEFRAMESRECEIVED
value|0x00001524
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_XOFFPAUSEFRAMESRECEIVED
value|0x00001528
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_MACCONTROLFRAMESRECEIVED
value|0x0000152c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_XOFFSTATEENTERED
value|0x00001530
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_DOT3STATSFRAMESTOOLONG
value|0x00001534
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_ETHERSTATSJABBERS
value|0x00001538
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_ETHERSTATSUNDERSIZEPKTS
value|0x0000153c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_ETHERSTATSPKTS64OCTETS
value|0x00001540
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_ETHERSTATSPKTS65OCTETSTO127OCTETS
value|0x00001544
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_ETHERSTATSPKTS128OCTETSTO255OCTETS
value|0x00001548
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_ETHERSTATSPKTS256OCTETSTO511OCTETS
value|0x0000154c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_ETHERSTATSPKTS512OCTETSTO1023OCTETS
value|0x00001550
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_ETHERSTATSPKTS1024OCTETSTO1522OCTETS
value|0x00001554
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_ETHERSTATSPKTS1523OCTETSTO9022OCTETS
value|0x00001558
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG0
value|0x0000155c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG1
value|0x00001560
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG1_LENGTH_NE_BYTE_COUNT
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG1_LENGTH_OUT_RANGE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG1_BAD_CRC
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG1_RX_ERROR
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG1_ALIGN_ERROR
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG1_LAST_DATA
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG1_ODD_BYTE_START
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG1_BYTE_COUNT
value|(0xffffL<<7)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG1_SLOT_TIME
value|(0xffL<<23)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2
value|0x00001564
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_SM_STATE
value|(0x7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_SM_STATE_IDLE
value|(0x0L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_SM_STATE_SFD
value|(0x1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_SM_STATE_DATA
value|(0x2L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_SM_STATE_SKEEP
value|(0x3L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_SM_STATE_EXT
value|(0x4L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_SM_STATE_DROP
value|(0x5L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_SM_STATE_SDROP
value|(0x6L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_SM_STATE_FC
value|(0x7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_IDI_STATE
value|(0xfL<<3)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_IDI_STATE_IDLE
value|(0x0L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_IDI_STATE_DATA0
value|(0x1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_IDI_STATE_DATA1
value|(0x2L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_IDI_STATE_DATA2
value|(0x3L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_IDI_STATE_DATA3
value|(0x4L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_IDI_STATE_ABORT
value|(0x5L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_IDI_STATE_WAIT
value|(0x6L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_IDI_STATE_STATUS
value|(0x7L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_IDI_STATE_LAST
value|(0x8L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_BYTE_IN
value|(0xffL<<7)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_FALSEC
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_TAGGED
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_PAUSE_STATE
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_PAUSE_STATE_IDLE
value|(0L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_PAUSE_STATE_PAUSED
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_SE_COUNTER
value|(0xfL<<19)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG2_QUANTA
value|(0x1fL<<23)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG3
value|0x00001568
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG3_PAUSE_CTR
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG3_TMP_PAUSE_CTR
value|(0xffffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4
value|0x0000156c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_TYPE_FIELD
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE
value|(0x3fL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_IDLE
value|(0x0L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_UMAC2
value|(0x1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_UMAC3
value|(0x2L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_UNI
value|(0x3L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_MMAC2
value|(0x7L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_MMAC3
value|(0x5L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_PSA1
value|(0x6L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_PSA2
value|(0x7L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_PSA3
value|(0x8L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_MC2
value|(0x9L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_MC3
value|(0xaL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_MWAIT1
value|(0xeL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_MWAIT2
value|(0xfL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_MCHECK
value|(0x10L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_MC
value|(0x11L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_BC2
value|(0x12L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_BC3
value|(0x13L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_BSA1
value|(0x14L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_BSA2
value|(0x15L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_BSA3
value|(0x16L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_BTYPE
value|(0x17L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_BC
value|(0x18L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_PTYPE
value|(0x19L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_CMD
value|(0x1aL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_MAC
value|(0x1bL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_LATCH
value|(0x1cL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_XOFF
value|(0x1dL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_XON
value|(0x1eL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_PAUSED
value|(0x1fL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_NPAUSED
value|(0x20L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_TTYPE
value|(0x21L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_TVAL
value|(0x22L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_USA1
value|(0x23L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_USA2
value|(0x24L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_USA3
value|(0x25L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_UTYPE
value|(0x26L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_UTTYPE
value|(0x27L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_UTVAL
value|(0x28L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_MTYPE
value|(0x29L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FILT_STATE_DROP
value|(0x2aL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_DROP_PKT
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_SLOT_FILLED
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_FALSE_CARRIER
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_LAST_DATA
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_sfd_FOUND
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_ADVANCE
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG4_START
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5
value|0x00001570
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_PS_IDISM
value|(0x7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_PS_IDISM_IDLE
value|(0L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_PS_IDISM_WAIT_EOF
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_PS_IDISM_WAIT_STAT
value|(2L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_PS_IDISM_SET_EOF4FCRC
value|(3L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_PS_IDISM_SET_EOF4RDE
value|(4L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_PS_IDISM_SET_EOF4ALL
value|(5L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_PS_IDISM_1WD_WAIT_STAT
value|(6L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_CCODE_BUF1
value|(0x7L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_CCODE_BUF1_VDW
value|(0x0L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_CCODE_BUF1_STAT
value|(0x1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_CCODE_BUF1_AEOF
value|(0x2L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_CCODE_BUF1_NEOF
value|(0x3L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_CCODE_BUF1_SOF
value|(0x4L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_CCODE_BUF1_SAEOF
value|(0x6L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_CCODE_BUF1_SNEOF
value|(0x7L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_EOF_DETECTED
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_CCODE_BUF0
value|(0x7L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_RPM_IDI_FIFO_FULL
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_LOAD_CCODE
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_LOAD_DATA
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_LOAD_STAT
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_CLR_STAT
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_IDI_RPM_CCODE
value|(0x3L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_IDI_RPM_ACCEPT
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_DEBUG5_FMLEN
value|(0xfffL<<20)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC0
value|0x00001580
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC1
value|0x00001584
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC2
value|0x00001588
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC3
value|0x0000158c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC4
value|0x00001590
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC5
value|0x00001594
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC6
value|0x00001598
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC7
value|0x0000159c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC8
value|0x000015a0
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC9
value|0x000015a4
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC10
value|0x000015a8
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC11
value|0x000015ac
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC12
value|0x000015b0
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC13
value|0x000015b4
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC14
value|0x000015b8
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC15
value|0x000015bc
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC16
value|0x000015c0
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC17
value|0x000015c4
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC18
value|0x000015c8
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC19
value|0x000015cc
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC20
value|0x000015d0
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC21
value|0x000015d4
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RX_STAT_AC22
value|0x000015d8
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_RXMAC_SUC_DBG_OVERRUNVEC
value|0x000015dc
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_IFHCOUTOCTETS
value|0x00001600
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_IFHCOUTBADOCTETS
value|0x00001604
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_ETHERSTATSCOLLISIONS
value|0x00001608
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_OUTXONSENT
value|0x0000160c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_OUTXOFFSENT
value|0x00001610
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_FLOWCONTROLDONE
value|0x00001614
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_DOT3STATSSINGLECOLLISIONFRAMES
value|0x00001618
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_DOT3STATSMULTIPLECOLLISIONFRAMES
value|0x0000161c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_DOT3STATSDEFERREDTRANSMISSIONS
value|0x00001620
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_DOT3STATSEXCESSIVECOLLISIONS
value|0x00001624
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_DOT3STATSLATECOLLISIONS
value|0x00001628
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_IFHCOUTUCASTPKTS
value|0x0000162c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_IFHCOUTMULTICASTPKTS
value|0x00001630
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_IFHCOUTBROADCASTPKTS
value|0x00001634
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_ETHERSTATSPKTS64OCTETS
value|0x00001638
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_ETHERSTATSPKTS65OCTETSTO127OCTETS
value|0x0000163c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_ETHERSTATSPKTS128OCTETSTO255OCTETS
value|0x00001640
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_ETHERSTATSPKTS256OCTETSTO511OCTETS
value|0x00001644
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_ETHERSTATSPKTS512OCTETSTO1023OCTETS
value|0x00001648
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_ETHERSTATSPKTS1024OCTETSTO1522OCTETS
value|0x0000164c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_ETHERSTATSPKTS1523OCTETSTO9022OCTETS
value|0x00001650
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_DOT3STATSINTERNALMACTRANSMITERRORS
value|0x00001654
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG0
value|0x00001658
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG1
value|0x0000165c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG1_ODI_STATE
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG1_ODI_STATE_IDLE
value|(0x0L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG1_ODI_STATE_START0
value|(0x1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG1_ODI_STATE_DATA0
value|(0x4L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG1_ODI_STATE_DATA1
value|(0x5L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG1_ODI_STATE_DATA2
value|(0x6L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG1_ODI_STATE_DATA3
value|(0x7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG1_ODI_STATE_WAIT0
value|(0x8L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG1_ODI_STATE_WAIT1
value|(0x9L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG1_CRS_ENABLE
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG1_BAD_CRC
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG1_SE_COUNTER
value|(0xfL<<6)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG1_SEND_PAUSE
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG1_LATE_COLLISION
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG1_MAX_DEFER
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG1_DEFERRED
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG1_ONE_BYTE
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG1_IPG_TIME
value|(0xfL<<15)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG1_SLOT_TIME
value|(0xffL<<19)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG2
value|0x00001660
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG2_BACK_OFF
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG2_BYTE_COUNT
value|(0xffffL<<10)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG2_COL_COUNT
value|(0x1fL<<26)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG2_COL_BIT
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3
value|0x00001664
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_SM_STATE
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_SM_STATE_IDLE
value|(0x0L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_SM_STATE_PRE1
value|(0x1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_SM_STATE_PRE2
value|(0x2L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_SM_STATE_SFD
value|(0x3L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_SM_STATE_DATA
value|(0x4L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_SM_STATE_CRC1
value|(0x5L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_SM_STATE_CRC2
value|(0x6L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_SM_STATE_EXT
value|(0x7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_SM_STATE_STATB
value|(0x8L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_SM_STATE_STATG
value|(0x9L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_SM_STATE_JAM
value|(0xaL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_SM_STATE_EJAM
value|(0xbL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_SM_STATE_BJAM
value|(0xcL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_SM_STATE_SWAIT
value|(0xdL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_SM_STATE_BACKOFF
value|(0xeL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_FILT_STATE
value|(0x7L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_FILT_STATE_IDLE
value|(0x0L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_FILT_STATE_WAIT
value|(0x1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_FILT_STATE_UNI
value|(0x2L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_FILT_STATE_MC
value|(0x3L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_FILT_STATE_BC2
value|(0x4L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_FILT_STATE_BC3
value|(0x5L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_FILT_STATE_BC
value|(0x6L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_CRS_DONE
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_XOFF
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_SE_COUNTER
value|(0xfL<<9)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG3_QUANTA_COUNTER
value|(0x1fL<<13)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4
value|0x00001668
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_PAUSE_COUNTER
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_PAUSE_STATE
value|(0xfL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_PAUSE_STATE_IDLE
value|(0x0L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_PAUSE_STATE_MCA1
value|(0x2L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_PAUSE_STATE_MCA2
value|(0x3L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_PAUSE_STATE_MCA3
value|(0x6L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_PAUSE_STATE_SRC1
value|(0x7L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_PAUSE_STATE_SRC2
value|(0x5L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_PAUSE_STATE_SRC3
value|(0x4L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_PAUSE_STATE_TYPE
value|(0xcL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_PAUSE_STATE_CMD
value|(0xeL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_PAUSE_STATE_TIME
value|(0xaL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_PAUSE_STATE_CRC1
value|(0x8L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_PAUSE_STATE_CRC2
value|(0x9L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_PAUSE_STATE_WAIT
value|(0xdL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_STATS0_VALID
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_APPEND_CRC
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_SLOT_FILLED
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_MAX_DEFER
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_SEND_EXTEND
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_SEND_PADDING
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_EOF_LOC
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_COLLIDING
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_COL_IN
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_BURSTING
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_ADVANCE
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_DEBUG4_GO
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC0
value|0x00001680
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC1
value|0x00001684
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC2
value|0x00001688
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC3
value|0x0000168c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC4
value|0x00001690
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC5
value|0x00001694
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC6
value|0x00001698
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC7
value|0x0000169c
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC8
value|0x000016a0
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC9
value|0x000016a4
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC10
value|0x000016a8
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC11
value|0x000016ac
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC12
value|0x000016b0
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC13
value|0x000016b4
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC14
value|0x000016b8
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC15
value|0x000016bc
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC16
value|0x000016c0
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC17
value|0x000016c4
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC18
value|0x000016c8
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC19
value|0x000016cc
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC20
value|0x000016d0
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TX_STAT_AC21
value|0x000016d4
end_define

begin_define
define|#
directive|define
name|BCE_EMAC_TXMAC_SUC_DBG_OVERRUNVEC
value|0x000016d8
end_define

begin_comment
comment|/*  *  rpm_reg definition  *  offset: 0x1800  */
end_comment

begin_define
define|#
directive|define
name|BCE_RPM_COMMAND
value|0x00001800
end_define

begin_define
define|#
directive|define
name|BCE_RPM_COMMAND_ENABLED
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_COMMAND_OVERRUN_ABORT
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_STATUS
value|0x00001804
end_define

begin_define
define|#
directive|define
name|BCE_RPM_STATUS_MBUF_WAIT
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_STATUS_FREE_WAIT
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_CONFIG
value|0x00001808
end_define

begin_define
define|#
directive|define
name|BCE_RPM_CONFIG_NO_PSD_HDR_CKSUM
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_CONFIG_ACPI_ENA
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_CONFIG_ACPI_KEEP
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_CONFIG_MP_KEEP
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_CONFIG_SORT_VECT_VAL
value|(0xfL<<4)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_CONFIG_IGNORE_VLAN
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_VLAN_MATCH0
value|0x00001810
end_define

begin_define
define|#
directive|define
name|BCE_RPM_VLAN_MATCH0_RPM_VLAN_MTCH0_VALUE
value|(0xfffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_VLAN_MATCH1
value|0x00001814
end_define

begin_define
define|#
directive|define
name|BCE_RPM_VLAN_MATCH1_RPM_VLAN_MTCH1_VALUE
value|(0xfffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_VLAN_MATCH2
value|0x00001818
end_define

begin_define
define|#
directive|define
name|BCE_RPM_VLAN_MATCH2_RPM_VLAN_MTCH2_VALUE
value|(0xfffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_VLAN_MATCH3
value|0x0000181c
end_define

begin_define
define|#
directive|define
name|BCE_RPM_VLAN_MATCH3_RPM_VLAN_MTCH3_VALUE
value|(0xfffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER0
value|0x00001820
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER0_PM_EN
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER0_BC_EN
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER0_MC_EN
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER0_MC_HSH_EN
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER0_PROM_EN
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER0_VLAN_EN
value|(0xfL<<20)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER0_PROM_VLAN
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER0_ENA
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER1
value|0x00001824
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER1_PM_EN
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER1_BC_EN
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER1_MC_EN
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER1_MC_HSH_EN
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER1_PROM_EN
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER1_VLAN_EN
value|(0xfL<<20)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER1_PROM_VLAN
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER1_ENA
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER2
value|0x00001828
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER2_PM_EN
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER2_BC_EN
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER2_MC_EN
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER2_MC_HSH_EN
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER2_PROM_EN
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER2_VLAN_EN
value|(0xfL<<20)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER2_PROM_VLAN
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER2_ENA
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER3
value|0x0000182c
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER3_PM_EN
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER3_BC_EN
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER3_MC_EN
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER3_MC_HSH_EN
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER3_PROM_EN
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER3_VLAN_EN
value|(0xfL<<20)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER3_PROM_VLAN
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_SORT_USER3_ENA
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_STAT_L2_FILTER_DISCARDS
value|0x00001840
end_define

begin_define
define|#
directive|define
name|BCE_RPM_STAT_RULE_CHECKER_DISCARDS
value|0x00001844
end_define

begin_define
define|#
directive|define
name|BCE_RPM_STAT_IFINFTQDISCARDS
value|0x00001848
end_define

begin_define
define|#
directive|define
name|BCE_RPM_STAT_IFINMBUFDISCARD
value|0x0000184c
end_define

begin_define
define|#
directive|define
name|BCE_RPM_STAT_RULE_CHECKER_P4_HIT
value|0x00001850
end_define

begin_define
define|#
directive|define
name|BCE_RPM_STAT_AC0
value|0x00001880
end_define

begin_define
define|#
directive|define
name|BCE_RPM_STAT_AC1
value|0x00001884
end_define

begin_define
define|#
directive|define
name|BCE_RPM_STAT_AC2
value|0x00001888
end_define

begin_define
define|#
directive|define
name|BCE_RPM_STAT_AC3
value|0x0000188c
end_define

begin_define
define|#
directive|define
name|BCE_RPM_STAT_AC4
value|0x00001890
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0
value|0x00001900
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_OFFSET
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_CLASS
value|(0x7L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_PRIORITY
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_P4
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_HDR_TYPE
value|(0x7L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_HDR_TYPE_START
value|(0L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_HDR_TYPE_IP
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_HDR_TYPE_TCP
value|(2L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_HDR_TYPE_UDP
value|(3L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_HDR_TYPE_DATA
value|(4L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_COMP
value|(0x3L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_COMP_EQUAL
value|(0L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_COMP_NEQUAL
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_COMP_GREATER
value|(2L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_COMP_LESS
value|(3L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_SBIT
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_CMDSEL
value|(0xfL<<20)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_MAP
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_DISCARD
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_MASK
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_P1
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_P2
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_P3
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_0_NBIT
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_VALUE_MASK_0
value|0x00001904
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_VALUE_MASK_0_VALUE
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_VALUE_MASK_0_MASK
value|(0xffffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_1
value|0x00001908
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_1_A
value|(0x3ffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_1_B
value|(0xfffL<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_VALUE_MASK_1
value|0x0000190c
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_2
value|0x00001910
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_2_A
value|(0x3ffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_2_B
value|(0xfffL<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_VALUE_MASK_2
value|0x00001914
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_3
value|0x00001918
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_3_A
value|(0x3ffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_3_B
value|(0xfffL<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_VALUE_MASK_3
value|0x0000191c
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_4
value|0x00001920
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_4_A
value|(0x3ffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_4_B
value|(0xfffL<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_VALUE_MASK_4
value|0x00001924
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_5
value|0x00001928
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_5_A
value|(0x3ffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_5_B
value|(0xfffL<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_VALUE_MASK_5
value|0x0000192c
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_6
value|0x00001930
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_6_A
value|(0x3ffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_6_B
value|(0xfffL<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_VALUE_MASK_6
value|0x00001934
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_7
value|0x00001938
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_7_A
value|(0x3ffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_7_B
value|(0xfffL<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_VALUE_MASK_7
value|0x0000193c
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_8
value|0x00001940
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_8_A
value|(0x3ffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_8_B
value|(0xfffL<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_VALUE_MASK_8
value|0x00001944
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_9
value|0x00001948
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_9_A
value|(0x3ffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_9_B
value|(0xfffL<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_VALUE_MASK_9
value|0x0000194c
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_10
value|0x00001950
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_10_A
value|(0x3ffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_10_B
value|(0xfffL<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_VALUE_MASK_10
value|0x00001954
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_11
value|0x00001958
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_11_A
value|(0x3ffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_11_B
value|(0xfffL<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_VALUE_MASK_11
value|0x0000195c
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_12
value|0x00001960
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_12_A
value|(0x3ffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_12_B
value|(0xfffL<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_VALUE_MASK_12
value|0x00001964
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_13
value|0x00001968
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_13_A
value|(0x3ffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_13_B
value|(0xfffL<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_VALUE_MASK_13
value|0x0000196c
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_14
value|0x00001970
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_14_A
value|(0x3ffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_14_B
value|(0xfffL<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_VALUE_MASK_14
value|0x00001974
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_15
value|0x00001978
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_15_A
value|(0x3ffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CNTL_15_B
value|(0xfffL<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_VALUE_MASK_15
value|0x0000197c
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CONFIG
value|0x00001980
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CONFIG_RULE_ENABLE
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_RC_CONFIG_DEF_CLASS
value|(0x7L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG0
value|0x00001984
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG0_FM_BCNT
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG0_T_DATA_OFST_VLD
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG0_T_UDP_OFST_VLD
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG0_T_TCP_OFST_VLD
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG0_T_IP_OFST_VLD
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG0_IP_MORE_FRGMT
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG0_T_IP_NO_TCP_UDP_HDR
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG0_LLC_SNAP
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG0_FM_STARTED
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG0_DONE
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG0_WAIT_4_DONE
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG0_USE_TPBUF_CKSUM
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG0_RX_NO_PSD_HDR_CKSUM
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG0_IGNORE_VLAN
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG0_RP_ENA_ACTIVE
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1
value|0x00001988
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_FSM_CUR_ST
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_FSM_CUR_ST_IDLE
value|(0L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_FSM_CUR_ST_ETYPE_B6_ALL
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_FSM_CUR_ST_ETYPE_B2_IPLLC
value|(2L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_FSM_CUR_ST_ETYPE_B6_IP
value|(4L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_FSM_CUR_ST_ETYPE_B2_IP
value|(8L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_FSM_CUR_ST_IP_START
value|(16L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_FSM_CUR_ST_IP
value|(32L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_FSM_CUR_ST_TCP
value|(64L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_FSM_CUR_ST_UDP
value|(128L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_FSM_CUR_ST_AH
value|(256L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_FSM_CUR_ST_ESP
value|(512L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_FSM_CUR_ST_ESP_PAYLOAD
value|(1024L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_FSM_CUR_ST_DATA
value|(2048L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_FSM_CUR_ST_ADD_CARRY
value|(0x2000L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_FSM_CUR_ST_ADD_CARRYOUT
value|(0x4000L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_FSM_CUR_ST_LATCH_RESULT
value|(0x8000L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_HDR_BCNT
value|(0x7ffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_UNKNOWN_ETYPE_D
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_VLAN_REMOVED_D2
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_VLAN_REMOVED_D1
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG1_EOF_0XTRA_WD
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG2
value|0x0000198c
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG2_CMD_HIT_VEC
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG2_IP_BCNT
value|(0xffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG2_THIS_CMD_M4
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG2_THIS_CMD_M3
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG2_THIS_CMD_M2
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG2_THIS_CMD_M1
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG2_IPIPE_EMPTY
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG2_FM_DISCARD
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG2_LAST_RULE_IN_FM_D2
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG2_LAST_RULE_IN_FM_D1
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3
value|0x00001990
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_AVAIL_MBUF_PTR
value|(0x1ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_RDE_RLUPQ_WR_REQ_INT
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_RDE_RBUF_WR_LAST_INT
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_RDE_RBUF_WR_REQ_INT
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_RDE_RBUF_FREE_REQ
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_RDE_RBUF_ALLOC_REQ
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_DFSM_MBUF_NOTAVAIL
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_RBUF_RDE_SOF_DROP
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_DFIFO_VLD_ENTRY_CT
value|(0xfL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_RDE_SRC_FIFO_ALMFULL
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_DROP_NXT_VLD
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_DROP_NXT
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_FTQ_FSM
value|(0x3L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_FTQ_FSM_IDLE
value|(0x0L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_FTQ_FSM_WAIT_ACK
value|(0x1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_FTQ_FSM_WAIT_FREE
value|(0x2L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_MBWRITE_FSM
value|(0x3L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_MBWRITE_FSM_WAIT_SOF
value|(0x0L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_MBWRITE_FSM_GET_MBUF
value|(0x1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_MBWRITE_FSM_DMA_DATA
value|(0x2L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_MBWRITE_FSM_WAIT_DATA
value|(0x3L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_MBWRITE_FSM_WAIT_EOF
value|(0x4L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_MBWRITE_FSM_WAIT_MF_ACK
value|(0x5L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_MBWRITE_FSM_WAIT_DROP_NXT_VLD
value|(0x6L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_MBWRITE_FSM_DONE
value|(0x7L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_MBFREE_FSM
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_MBFREE_FSM_IDLE
value|(0L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_MBFREE_FSM_WAIT_ACK
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_MBALLOC_FSM
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_MBALLOC_FSM_ET_MBUF
value|(0x0L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_MBALLOC_FSM_IVE_MBUF
value|(0x1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG3_CCODE_EOF_ERROR
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG4
value|0x00001994
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG4_DFSM_MBUF_CLUSTER
value|(0x1ffffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG4_DFIFO_CUR_CCODE
value|(0x7L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG4_MBWRITE_FSM
value|(0x7L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG4_DFIFO_EMPTY
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG5
value|0x00001998
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG5_RDROP_WPTR
value|(0x1fL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG5_RDROP_ACPI_RPTR
value|(0x1fL<<5)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG5_RDROP_MC_RPTR
value|(0x1fL<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG5_RDROP_RC_RPTR
value|(0x1fL<<15)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG5_RDROP_ACPI_EMPTY
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG5_RDROP_MC_EMPTY
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG5_RDROP_AEOF_VEC_AT_RDROP_MC_RPTR
value|(1L<<22)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG5_HOLDREG_WOL_DROP_INT
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG5_HOLDREG_DISCARD
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG5_HOLDREG_MBUF_NOTAVAIL
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG5_HOLDREG_MC_EMPTY
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG5_HOLDREG_RC_EMPTY
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG5_HOLDREG_FC_EMPTY
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG5_HOLDREG_ACPI_EMPTY
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG5_HOLDREG_FULL_T
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG5_HOLDREG_RD
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG6
value|0x0000199c
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG6_ACPI_VEC
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG6_VEC
value|(0xffffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG7
value|0x000019a0
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG7_RPM_DBG7_LAST_CRC
value|(0xffffffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8
value|0x000019a4
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_PS_ACPI_FSM
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_PS_ACPI_FSM_IDLE
value|(0L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_PS_ACPI_FSM_SOF_W1_ADDR
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_PS_ACPI_FSM_SOF_W2_ADDR
value|(2L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_PS_ACPI_FSM_SOF_W3_ADDR
value|(3L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_PS_ACPI_FSM_SOF_WAIT_THBUF
value|(4L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_PS_ACPI_FSM_W3_DATA
value|(5L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_PS_ACPI_FSM_W0_ADDR
value|(6L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_PS_ACPI_FSM_W1_ADDR
value|(7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_PS_ACPI_FSM_W2_ADDR
value|(8L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_PS_ACPI_FSM_W3_ADDR
value|(9L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_PS_ACPI_FSM_WAIT_THBUF
value|(10L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_COMPARE_AT_W0
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_COMPARE_AT_W3_DATA
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_COMPARE_AT_SOF_WAIT
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_COMPARE_AT_SOF_W3
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_COMPARE_AT_SOF_W2
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_EOF_W_LTEQ6_VLDBYTES
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_EOF_W_LTEQ4_VLDBYTES
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_NXT_EOF_W_12_VLDBYTES
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_EOF_DET
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_SOF_DET
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_WAIT_4_SOF
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_ALL_DONE
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_THBUF_ADDR
value|(0x7fL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG8_BYTE_CTR
value|(0xffL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG9
value|0x000019a8
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG9_OUTFIFO_COUNT
value|(0x7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG9_RDE_ACPI_RDY
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG9_VLD_RD_ENTRY_CT
value|(0x7L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG9_OUTFIFO_OVERRUN_OCCURRED
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG9_INFIFO_OVERRUN_OCCURRED
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG9_ACPI_MATCH_INT
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_DEBUG9_ACPI_ENABLE_SYN
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_RPM_ACPI_DBG_BUF_W00
value|0x000019c0
end_define

begin_define
define|#
directive|define
name|BCE_RPM_ACPI_DBG_BUF_W01
value|0x000019c4
end_define

begin_define
define|#
directive|define
name|BCE_RPM_ACPI_DBG_BUF_W02
value|0x000019c8
end_define

begin_define
define|#
directive|define
name|BCE_RPM_ACPI_DBG_BUF_W03
value|0x000019cc
end_define

begin_define
define|#
directive|define
name|BCE_RPM_ACPI_DBG_BUF_W10
value|0x000019d0
end_define

begin_define
define|#
directive|define
name|BCE_RPM_ACPI_DBG_BUF_W11
value|0x000019d4
end_define

begin_define
define|#
directive|define
name|BCE_RPM_ACPI_DBG_BUF_W12
value|0x000019d8
end_define

begin_define
define|#
directive|define
name|BCE_RPM_ACPI_DBG_BUF_W13
value|0x000019dc
end_define

begin_define
define|#
directive|define
name|BCE_RPM_ACPI_DBG_BUF_W20
value|0x000019e0
end_define

begin_define
define|#
directive|define
name|BCE_RPM_ACPI_DBG_BUF_W21
value|0x000019e4
end_define

begin_define
define|#
directive|define
name|BCE_RPM_ACPI_DBG_BUF_W22
value|0x000019e8
end_define

begin_define
define|#
directive|define
name|BCE_RPM_ACPI_DBG_BUF_W23
value|0x000019ec
end_define

begin_define
define|#
directive|define
name|BCE_RPM_ACPI_DBG_BUF_W30
value|0x000019f0
end_define

begin_define
define|#
directive|define
name|BCE_RPM_ACPI_DBG_BUF_W31
value|0x000019f4
end_define

begin_define
define|#
directive|define
name|BCE_RPM_ACPI_DBG_BUF_W32
value|0x000019f8
end_define

begin_define
define|#
directive|define
name|BCE_RPM_ACPI_DBG_BUF_W33
value|0x000019fc
end_define

begin_comment
comment|/*  *  rbuf_reg definition  *  offset: 0x200000  */
end_comment

begin_define
define|#
directive|define
name|BCE_RBUF_COMMAND
value|0x00200000
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_COMMAND_ENABLED
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_COMMAND_FREE_INIT
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_COMMAND_RAM_INIT
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_COMMAND_OVER_FREE
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_COMMAND_ALLOC_REQ
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_STATUS1
value|0x00200004
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_STATUS1_FREE_COUNT
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_STATUS2
value|0x00200008
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_STATUS2_FREE_TAIL
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_STATUS2_FREE_HEAD
value|(0x3ffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_CONFIG
value|0x0020000c
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_CONFIG_XOFF_TRIP
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_CONFIG_XON_TRIP
value|(0x3ffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_FW_BUF_ALLOC
value|0x00200010
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_FW_BUF_ALLOC_VALUE
value|(0x1ffL<<7)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_FW_BUF_FREE
value|0x00200014
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_FW_BUF_FREE_COUNT
value|(0x7fL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_FW_BUF_FREE_TAIL
value|(0x1ffL<<7)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_FW_BUF_FREE_HEAD
value|(0x1ffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_FW_BUF_SEL
value|0x00200018
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_FW_BUF_SEL_COUNT
value|(0x7fL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_FW_BUF_SEL_TAIL
value|(0x1ffL<<7)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_FW_BUF_SEL_HEAD
value|(0x1ffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_CONFIG2
value|0x0020001c
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_CONFIG2_MAC_DROP_TRIP
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_CONFIG2_MAC_KEEP_TRIP
value|(0x3ffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_CONFIG3
value|0x00200020
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_CONFIG3_CU_DROP_TRIP
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_CONFIG3_CU_KEEP_TRIP
value|(0x3ffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_PKT_DATA
value|0x00208000
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_CLIST_DATA
value|0x00210000
end_define

begin_define
define|#
directive|define
name|BCE_RBUF_BUF_DATA
value|0x00220000
end_define

begin_comment
comment|/*  *  rv2p_reg definition  *  offset: 0x2800  */
end_comment

begin_define
define|#
directive|define
name|BCE_RV2P_COMMAND
value|0x00002800
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_COMMAND_ENABLED
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_COMMAND_PROC1_INTRPT
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_COMMAND_PROC2_INTRPT
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_COMMAND_ABORT0
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_COMMAND_ABORT1
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_COMMAND_ABORT2
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_COMMAND_ABORT3
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_COMMAND_ABORT4
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_COMMAND_ABORT5
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_COMMAND_PROC1_RESET
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_COMMAND_PROC2_RESET
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_COMMAND_CTXIF_RESET
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_STATUS
value|0x00002804
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_STATUS_ALWAYS_0
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_STATUS_RV2P_GEN_STAT0_CNT
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_STATUS_RV2P_GEN_STAT1_CNT
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_STATUS_RV2P_GEN_STAT2_CNT
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_STATUS_RV2P_GEN_STAT3_CNT
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_STATUS_RV2P_GEN_STAT4_CNT
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_STATUS_RV2P_GEN_STAT5_CNT
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG
value|0x00002808
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_STALL_PROC1
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_STALL_PROC2
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PROC1_STALL_ON_ABORT0
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PROC1_STALL_ON_ABORT1
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PROC1_STALL_ON_ABORT2
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PROC1_STALL_ON_ABORT3
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PROC1_STALL_ON_ABORT4
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PROC1_STALL_ON_ABORT5
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PROC2_STALL_ON_ABORT0
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PROC2_STALL_ON_ABORT1
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PROC2_STALL_ON_ABORT2
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PROC2_STALL_ON_ABORT3
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PROC2_STALL_ON_ABORT4
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PROC2_STALL_ON_ABORT5
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PAGE_SIZE
value|(0xfL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PAGE_SIZE_256
value|(0L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PAGE_SIZE_512
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PAGE_SIZE_1K
value|(2L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PAGE_SIZE_2K
value|(3L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PAGE_SIZE_4K
value|(4L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PAGE_SIZE_8K
value|(5L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PAGE_SIZE_16K
value|(6L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PAGE_SIZE_32K
value|(7L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PAGE_SIZE_64K
value|(8L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PAGE_SIZE_128K
value|(9L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PAGE_SIZE_256K
value|(10L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PAGE_SIZE_512K
value|(11L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_CONFIG_PAGE_SIZE_1M
value|(12L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_GEN_BFR_ADDR_0
value|0x00002810
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_GEN_BFR_ADDR_0_VALUE
value|(0xffffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_GEN_BFR_ADDR_1
value|0x00002814
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_GEN_BFR_ADDR_1_VALUE
value|(0xffffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_GEN_BFR_ADDR_2
value|0x00002818
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_GEN_BFR_ADDR_2_VALUE
value|(0xffffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_GEN_BFR_ADDR_3
value|0x0000281c
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_GEN_BFR_ADDR_3_VALUE
value|(0xffffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_INSTR_HIGH
value|0x00002830
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_INSTR_HIGH_HIGH
value|(0x1fL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_INSTR_LOW
value|0x00002834
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PROC1_ADDR_CMD
value|0x00002838
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PROC1_ADDR_CMD_ADD
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PROC1_ADDR_CMD_RDWR
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PROC2_ADDR_CMD
value|0x0000283c
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PROC2_ADDR_CMD_ADD
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PROC2_ADDR_CMD_RDWR
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PROC1_GRC_DEBUG
value|0x00002840
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PROC2_GRC_DEBUG
value|0x00002844
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_GRC_PROC_DEBUG
value|0x00002848
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_DEBUG_VECT_PEEK
value|0x0000284c
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_DEBUG_VECT_PEEK_1_VALUE
value|(0x7ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_DEBUG_VECT_PEEK_1_PEEK_EN
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_DEBUG_VECT_PEEK_1_SEL
value|(0xfL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_DEBUG_VECT_PEEK_2_VALUE
value|(0x7ffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_DEBUG_VECT_PEEK_2_PEEK_EN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_DEBUG_VECT_PEEK_2_SEL
value|(0xfL<<28)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PFTQ_DATA
value|0x00002b40
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PFTQ_CMD
value|0x00002b78
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PFTQ_CMD_OFFSET
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PFTQ_CMD_WR_TOP
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PFTQ_CMD_WR_TOP_0
value|(0L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PFTQ_CMD_WR_TOP_1
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PFTQ_CMD_SFT_RESET
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PFTQ_CMD_RD_DATA
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PFTQ_CMD_ADD_INTERVEN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PFTQ_CMD_ADD_DATA
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PFTQ_CMD_INTERVENE_CLR
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PFTQ_CMD_POP
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PFTQ_CMD_BUSY
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PFTQ_CTL
value|0x00002b7c
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PFTQ_CTL_INTERVENE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PFTQ_CTL_OVERFLOW
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PFTQ_CTL_FORCE_INTERVENE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PFTQ_CTL_MAX_DEPTH
value|(0x3ffL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_PFTQ_CTL_CUR_DEPTH
value|(0x3ffL<<22)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_TFTQ_DATA
value|0x00002b80
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_TFTQ_CMD
value|0x00002bb8
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_TFTQ_CMD_OFFSET
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_TFTQ_CMD_WR_TOP
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_TFTQ_CMD_WR_TOP_0
value|(0L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_TFTQ_CMD_WR_TOP_1
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_TFTQ_CMD_SFT_RESET
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_TFTQ_CMD_RD_DATA
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_TFTQ_CMD_ADD_INTERVEN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_TFTQ_CMD_ADD_DATA
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_TFTQ_CMD_INTERVENE_CLR
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_TFTQ_CMD_POP
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_TFTQ_CMD_BUSY
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_TFTQ_CTL
value|0x00002bbc
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_TFTQ_CTL_INTERVENE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_TFTQ_CTL_OVERFLOW
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_TFTQ_CTL_FORCE_INTERVENE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_TFTQ_CTL_MAX_DEPTH
value|(0x3ffL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_TFTQ_CTL_CUR_DEPTH
value|(0x3ffL<<22)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_MFTQ_DATA
value|0x00002bc0
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_MFTQ_CMD
value|0x00002bf8
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_MFTQ_CMD_OFFSET
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_MFTQ_CMD_WR_TOP
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_MFTQ_CMD_WR_TOP_0
value|(0L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_MFTQ_CMD_WR_TOP_1
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_MFTQ_CMD_SFT_RESET
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_MFTQ_CMD_RD_DATA
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_MFTQ_CMD_ADD_INTERVEN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_MFTQ_CMD_ADD_DATA
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_MFTQ_CMD_INTERVENE_CLR
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_MFTQ_CMD_POP
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_MFTQ_CMD_BUSY
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_MFTQ_CTL
value|0x00002bfc
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_MFTQ_CTL_INTERVENE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_MFTQ_CTL_OVERFLOW
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_MFTQ_CTL_FORCE_INTERVENE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_MFTQ_CTL_MAX_DEPTH
value|(0x3ffL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_RV2P_MFTQ_CTL_CUR_DEPTH
value|(0x3ffL<<22)
end_define

begin_comment
comment|/*  *  mq_reg definition  *  offset: 0x3c00  */
end_comment

begin_define
define|#
directive|define
name|BCE_MQ_COMMAND
value|0x00003c00
end_define

begin_define
define|#
directive|define
name|BCE_MQ_COMMAND_ENABLED
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_COMMAND_OVERFLOW
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_COMMAND_WR_ERROR
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_COMMAND_RD_ERROR
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_STATUS
value|0x00003c04
end_define

begin_define
define|#
directive|define
name|BCE_MQ_STATUS_CTX_ACCESS_STAT
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_STATUS_CTX_ACCESS64_STAT
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_STATUS_PCI_STALL_STAT
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_CONFIG
value|0x00003c08
end_define

begin_define
define|#
directive|define
name|BCE_MQ_CONFIG_TX_HIGH_PRI
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_CONFIG_HALT_DIS
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_CONFIG_KNL_BYP_BLK_SIZE
value|(0x7L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_CONFIG_KNL_BYP_BLK_SIZE_256
value|(0L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_CONFIG_KNL_BYP_BLK_SIZE_512
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_CONFIG_KNL_BYP_BLK_SIZE_1K
value|(2L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_CONFIG_KNL_BYP_BLK_SIZE_2K
value|(3L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_CONFIG_KNL_BYP_BLK_SIZE_4K
value|(4L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_CONFIG_MAX_DEPTH
value|(0x7fL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_CONFIG_CUR_DEPTH
value|(0x7fL<<20)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_ENQUEUE1
value|0x00003c0c
end_define

begin_define
define|#
directive|define
name|BCE_MQ_ENQUEUE1_OFFSET
value|(0x3fL<<2)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_ENQUEUE1_CID
value|(0x3fffL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_ENQUEUE1_BYTE_MASK
value|(0xfL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_ENQUEUE1_KNL_MODE
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_ENQUEUE2
value|0x00003c10
end_define

begin_define
define|#
directive|define
name|BCE_MQ_BAD_WR_ADDR
value|0x00003c14
end_define

begin_define
define|#
directive|define
name|BCE_MQ_BAD_RD_ADDR
value|0x00003c18
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_BYP_WIND_START
value|0x00003c1c
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_BYP_WIND_START_VALUE
value|(0xfffffL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_WIND_END
value|0x00003c20
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_WIND_END_VALUE
value|(0xffffffL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_WRITE_MASK1
value|0x00003c24
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_TX_MASK1
value|0x00003c28
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_CMD_MASK1
value|0x00003c2c
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_COND_ENQUEUE_MASK1
value|0x00003c30
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_RX_V2P_MASK1
value|0x00003c34
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_WRITE_MASK2
value|0x00003c38
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_TX_MASK2
value|0x00003c3c
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_CMD_MASK2
value|0x00003c40
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_COND_ENQUEUE_MASK2
value|0x00003c44
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_RX_V2P_MASK2
value|0x00003c48
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_BYP_WRITE_MASK1
value|0x00003c4c
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_BYP_TX_MASK1
value|0x00003c50
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_BYP_CMD_MASK1
value|0x00003c54
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_BYP_COND_ENQUEUE_MASK1
value|0x00003c58
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_BYP_RX_V2P_MASK1
value|0x00003c5c
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_BYP_WRITE_MASK2
value|0x00003c60
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_BYP_TX_MASK2
value|0x00003c64
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_BYP_CMD_MASK2
value|0x00003c68
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_BYP_COND_ENQUEUE_MASK2
value|0x00003c6c
end_define

begin_define
define|#
directive|define
name|BCE_MQ_KNL_BYP_RX_V2P_MASK2
value|0x00003c70
end_define

begin_define
define|#
directive|define
name|BCE_MQ_MEM_WR_ADDR
value|0x00003c74
end_define

begin_define
define|#
directive|define
name|BCE_MQ_MEM_WR_ADDR_VALUE
value|(0x3fL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_MEM_WR_DATA0
value|0x00003c78
end_define

begin_define
define|#
directive|define
name|BCE_MQ_MEM_WR_DATA0_VALUE
value|(0xffffffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_MEM_WR_DATA1
value|0x00003c7c
end_define

begin_define
define|#
directive|define
name|BCE_MQ_MEM_WR_DATA1_VALUE
value|(0xffffffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_MEM_WR_DATA2
value|0x00003c80
end_define

begin_define
define|#
directive|define
name|BCE_MQ_MEM_WR_DATA2_VALUE
value|(0x3fffffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_MEM_RD_ADDR
value|0x00003c84
end_define

begin_define
define|#
directive|define
name|BCE_MQ_MEM_RD_ADDR_VALUE
value|(0x3fL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_MEM_RD_DATA0
value|0x00003c88
end_define

begin_define
define|#
directive|define
name|BCE_MQ_MEM_RD_DATA0_VALUE
value|(0xffffffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_MEM_RD_DATA1
value|0x00003c8c
end_define

begin_define
define|#
directive|define
name|BCE_MQ_MEM_RD_DATA1_VALUE
value|(0xffffffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MQ_MEM_RD_DATA2
value|0x00003c90
end_define

begin_define
define|#
directive|define
name|BCE_MQ_MEM_RD_DATA2_VALUE
value|(0x3fffffffL<<0)
end_define

begin_comment
comment|/*  *  tbdr_reg definition  *  offset: 0x5000  */
end_comment

begin_define
define|#
directive|define
name|BCE_TBDR_COMMAND
value|0x00005000
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_COMMAND_ENABLE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_COMMAND_SOFT_RST
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_COMMAND_MSTR_ABORT
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_STATUS
value|0x00005004
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_STATUS_DMA_WAIT
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_STATUS_FTQ_WAIT
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_STATUS_FIFO_OVERFLOW
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_STATUS_FIFO_UNDERFLOW
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_STATUS_SEARCHMISS_ERROR
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_STATUS_FTQ_ENTRY_CNT
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_STATUS_BURST_CNT
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_CONFIG
value|0x00005008
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_CONFIG_MAX_BDS
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_CONFIG_SWAP_MODE
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_CONFIG_PRIORITY
value|(1L<<9)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_CONFIG_CACHE_NEXT_PAGE_PTRS
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_CONFIG_PAGE_SIZE
value|(0xfL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_CONFIG_PAGE_SIZE_256
value|(0L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_CONFIG_PAGE_SIZE_512
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_CONFIG_PAGE_SIZE_1K
value|(2L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_CONFIG_PAGE_SIZE_2K
value|(3L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_CONFIG_PAGE_SIZE_4K
value|(4L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_CONFIG_PAGE_SIZE_8K
value|(5L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_CONFIG_PAGE_SIZE_16K
value|(6L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_CONFIG_PAGE_SIZE_32K
value|(7L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_CONFIG_PAGE_SIZE_64K
value|(8L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_CONFIG_PAGE_SIZE_128K
value|(9L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_CONFIG_PAGE_SIZE_256K
value|(10L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_CONFIG_PAGE_SIZE_512K
value|(11L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_CONFIG_PAGE_SIZE_1M
value|(12L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_DEBUG_VECT_PEEK
value|0x0000500c
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_DEBUG_VECT_PEEK_1_VALUE
value|(0x7ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_DEBUG_VECT_PEEK_1_PEEK_EN
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_DEBUG_VECT_PEEK_1_SEL
value|(0xfL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_DEBUG_VECT_PEEK_2_VALUE
value|(0x7ffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_DEBUG_VECT_PEEK_2_PEEK_EN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_DEBUG_VECT_PEEK_2_SEL
value|(0xfL<<28)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_FTQ_DATA
value|0x000053c0
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_FTQ_CMD
value|0x000053f8
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_FTQ_CMD_OFFSET
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_FTQ_CMD_WR_TOP
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_FTQ_CMD_WR_TOP_0
value|(0L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_FTQ_CMD_WR_TOP_1
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_FTQ_CMD_SFT_RESET
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_FTQ_CMD_RD_DATA
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_FTQ_CMD_ADD_INTERVEN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_FTQ_CMD_ADD_DATA
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_FTQ_CMD_INTERVENE_CLR
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_FTQ_CMD_POP
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_FTQ_CMD_BUSY
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_FTQ_CTL
value|0x000053fc
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_FTQ_CTL_INTERVENE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_FTQ_CTL_OVERFLOW
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_FTQ_CTL_FORCE_INTERVENE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_FTQ_CTL_MAX_DEPTH
value|(0x3ffL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_TBDR_FTQ_CTL_CUR_DEPTH
value|(0x3ffL<<22)
end_define

begin_comment
comment|/*  *  tdma_reg definition  *  offset: 0x5c00  */
end_comment

begin_define
define|#
directive|define
name|BCE_TDMA_COMMAND
value|0x00005c00
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_COMMAND_ENABLED
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_COMMAND_MASTER_ABORT
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_COMMAND_BAD_L2_LENGTH_ABORT
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_STATUS
value|0x00005c04
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_STATUS_DMA_WAIT
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_STATUS_PAYLOAD_WAIT
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_STATUS_PATCH_FTQ_WAIT
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_STATUS_LOCK_WAIT
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_STATUS_FTQ_ENTRY_CNT
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_STATUS_BURST_CNT
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_CONFIG
value|0x00005c08
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_CONFIG_ONE_DMA
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_CONFIG_ONE_RECORD
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_CONFIG_LIMIT_SZ
value|(0xfL<<4)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_CONFIG_LIMIT_SZ_64
value|(0L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_CONFIG_LIMIT_SZ_128
value|(0x4L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_CONFIG_LIMIT_SZ_256
value|(0x6L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_CONFIG_LIMIT_SZ_512
value|(0x8L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_CONFIG_LINE_SZ
value|(0xfL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_CONFIG_LINE_SZ_64
value|(0L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_CONFIG_LINE_SZ_128
value|(4L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_CONFIG_LINE_SZ_256
value|(6L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_CONFIG_LINE_SZ_512
value|(8L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_CONFIG_ALIGN_ENA
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_CONFIG_CHK_L2_BD
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_CONFIG_FIFO_CMP
value|(0xfL<<20)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_PAYLOAD_PROD
value|0x00005c0c
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_PAYLOAD_PROD_VALUE
value|(0x1fffL<<3)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DBG_WATCHDOG
value|0x00005c10
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DBG_TRIGGER
value|0x00005c14
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DMAD_FSM
value|0x00005c80
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DMAD_FSM_BD_INVLD
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DMAD_FSM_PUSH
value|(0xfL<<4)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DMAD_FSM_ARB_TBDC
value|(0x3L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DMAD_FSM_ARB_CTX
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DMAD_FSM_DR_INTF
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DMAD_FSM_DMAD
value|(0x7L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DMAD_FSM_BD
value|(0xfL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DMAD_STATUS
value|0x00005c84
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DMAD_STATUS_RHOLD_PUSH_ENTRY
value|(0x3L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DMAD_STATUS_RHOLD_DMAD_ENTRY
value|(0x3L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DMAD_STATUS_RHOLD_BD_ENTRY
value|(0x3L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DMAD_STATUS_IFTQ_ENUM
value|(0xfL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DR_INTF_FSM
value|0x00005c88
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DR_INTF_FSM_L2_COMP
value|(0x3L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DR_INTF_FSM_TPATQ
value|(0x7L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DR_INTF_FSM_TPBUF
value|(0x3L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DR_INTF_FSM_DR_BUF
value|(0x7L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DR_INTF_FSM_DMAD
value|(0x7L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DR_INTF_STATUS
value|0x00005c8c
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DR_INTF_STATUS_HOLE_PHASE
value|(0x7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DR_INTF_STATUS_DATA_AVAIL
value|(0x3L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DR_INTF_STATUS_SHIFT_ADDR
value|(0x7L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DR_INTF_STATUS_NXT_PNTR
value|(0xfL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_DR_INTF_STATUS_BYTE_COUNT
value|(0x7L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_FTQ_DATA
value|0x00005fc0
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_FTQ_CMD
value|0x00005ff8
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_FTQ_CMD_OFFSET
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_FTQ_CMD_WR_TOP
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_FTQ_CMD_WR_TOP_0
value|(0L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_FTQ_CMD_WR_TOP_1
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_FTQ_CMD_SFT_RESET
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_FTQ_CMD_RD_DATA
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_FTQ_CMD_ADD_INTERVEN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_FTQ_CMD_ADD_DATA
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_FTQ_CMD_INTERVENE_CLR
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_FTQ_CMD_POP
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_FTQ_CMD_BUSY
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_FTQ_CTL
value|0x00005ffc
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_FTQ_CTL_INTERVENE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_FTQ_CTL_OVERFLOW
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_FTQ_CTL_FORCE_INTERVENE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_FTQ_CTL_MAX_DEPTH
value|(0x3ffL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_TDMA_FTQ_CTL_CUR_DEPTH
value|(0x3ffL<<22)
end_define

begin_comment
comment|/*  *  hc_reg definition  *  offset: 0x6800  */
end_comment

begin_define
define|#
directive|define
name|BCE_HC_COMMAND
value|0x00006800
end_define

begin_define
define|#
directive|define
name|BCE_HC_COMMAND_ENABLE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_COMMAND_SKIP_ABORT
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_HC_COMMAND_COAL_NOW
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_HC_COMMAND_COAL_NOW_WO_INT
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_HC_COMMAND_STATS_NOW
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_HC_COMMAND_FORCE_INT
value|(0x3L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_HC_COMMAND_FORCE_INT_NULL
value|(0L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_HC_COMMAND_FORCE_INT_HIGH
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_HC_COMMAND_FORCE_INT_LOW
value|(2L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_HC_COMMAND_FORCE_INT_FREE
value|(3L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_HC_COMMAND_CLR_STAT_NOW
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STATUS
value|0x00006804
end_define

begin_define
define|#
directive|define
name|BCE_HC_STATUS_MASTER_ABORT
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STATUS_PARITY_ERROR_STATE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STATUS_PCI_CLK_CNT_STAT
value|(1L<<16)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STATUS_CORE_CLK_CNT_STAT
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STATUS_NUM_STATUS_BLOCKS_STAT
value|(1L<<18)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STATUS_NUM_INT_GEN_STAT
value|(1L<<19)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STATUS_NUM_INT_MBOX_WR_STAT
value|(1L<<20)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STATUS_CORE_CLKS_TO_HW_INTACK_STAT
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STATUS_CORE_CLKS_TO_SW_INTACK_STAT
value|(1L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STATUS_CORE_CLKS_DURING_SW_INTACK_STAT
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_HC_CONFIG
value|0x00006808
end_define

begin_define
define|#
directive|define
name|BCE_HC_CONFIG_COLLECT_STATS
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_CONFIG_RX_TMR_MODE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_HC_CONFIG_TX_TMR_MODE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_HC_CONFIG_COM_TMR_MODE
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_HC_CONFIG_CMD_TMR_MODE
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_HC_CONFIG_STATISTIC_PRIORITY
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_HC_CONFIG_STATUS_PRIORITY
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_HC_CONFIG_STAT_MEM_ADDR
value|(0xffL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_HC_ATTN_BITS_ENABLE
value|0x0000680c
end_define

begin_define
define|#
directive|define
name|BCE_HC_STATUS_ADDR_L
value|0x00006810
end_define

begin_define
define|#
directive|define
name|BCE_HC_STATUS_ADDR_H
value|0x00006814
end_define

begin_define
define|#
directive|define
name|BCE_HC_STATISTICS_ADDR_L
value|0x00006818
end_define

begin_define
define|#
directive|define
name|BCE_HC_STATISTICS_ADDR_H
value|0x0000681c
end_define

begin_define
define|#
directive|define
name|BCE_HC_TX_QUICK_CONS_TRIP
value|0x00006820
end_define

begin_define
define|#
directive|define
name|BCE_HC_TX_QUICK_CONS_TRIP_VALUE
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_TX_QUICK_CONS_TRIP_INT
value|(0xffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_HC_COMP_PROD_TRIP
value|0x00006824
end_define

begin_define
define|#
directive|define
name|BCE_HC_COMP_PROD_TRIP_VALUE
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_COMP_PROD_TRIP_INT
value|(0xffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_HC_RX_QUICK_CONS_TRIP
value|0x00006828
end_define

begin_define
define|#
directive|define
name|BCE_HC_RX_QUICK_CONS_TRIP_VALUE
value|(0xffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_RX_QUICK_CONS_TRIP_INT
value|(0xffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_HC_RX_TICKS
value|0x0000682c
end_define

begin_define
define|#
directive|define
name|BCE_HC_RX_TICKS_VALUE
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_RX_TICKS_INT
value|(0x3ffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_HC_TX_TICKS
value|0x00006830
end_define

begin_define
define|#
directive|define
name|BCE_HC_TX_TICKS_VALUE
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_TX_TICKS_INT
value|(0x3ffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_HC_COM_TICKS
value|0x00006834
end_define

begin_define
define|#
directive|define
name|BCE_HC_COM_TICKS_VALUE
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_COM_TICKS_INT
value|(0x3ffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_HC_CMD_TICKS
value|0x00006838
end_define

begin_define
define|#
directive|define
name|BCE_HC_CMD_TICKS_VALUE
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_CMD_TICKS_INT
value|(0x3ffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_HC_PERIODIC_TICKS
value|0x0000683c
end_define

begin_define
define|#
directive|define
name|BCE_HC_PERIODIC_TICKS_HC_PERIODIC_TICKS
value|(0xffffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_COLLECT_TICKS
value|0x00006840
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_COLLECT_TICKS_HC_STAT_COLL_TICKS
value|(0xffL<<4)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STATS_TICKS
value|0x00006844
end_define

begin_define
define|#
directive|define
name|BCE_HC_STATS_TICKS_HC_STAT_TICKS
value|(0xffffL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_MEM_DATA
value|0x0000684c
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0
value|0x00006850
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0
value|(0x7fL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RXP_STAT0
value|(0L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RXP_STAT1
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RXP_STAT2
value|(2L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RXP_STAT3
value|(3L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RXP_STAT4
value|(4L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RXP_STAT5
value|(5L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RXP_STAT6
value|(6L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RXP_STAT7
value|(7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RXP_STAT8
value|(8L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RXP_STAT9
value|(9L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RXP_STAT10
value|(10L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RXP_STAT11
value|(11L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TXP_STAT0
value|(12L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TXP_STAT1
value|(13L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TXP_STAT2
value|(14L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TXP_STAT3
value|(15L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TXP_STAT4
value|(16L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TXP_STAT5
value|(17L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TXP_STAT6
value|(18L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TXP_STAT7
value|(19L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_COM_STAT0
value|(20L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_COM_STAT1
value|(21L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_COM_STAT2
value|(22L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_COM_STAT3
value|(23L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_COM_STAT4
value|(24L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_COM_STAT5
value|(25L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_COM_STAT6
value|(26L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_COM_STAT7
value|(27L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_COM_STAT8
value|(28L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_COM_STAT9
value|(29L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_COM_STAT10
value|(30L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_COM_STAT11
value|(31L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TPAT_STAT0
value|(32L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TPAT_STAT1
value|(33L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TPAT_STAT2
value|(34L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TPAT_STAT3
value|(35L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_CP_STAT0
value|(36L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_CP_STAT1
value|(37L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_CP_STAT2
value|(38L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_CP_STAT3
value|(39L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_CP_STAT4
value|(40L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_CP_STAT5
value|(41L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_CP_STAT6
value|(42L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_CP_STAT7
value|(43L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_MCP_STAT0
value|(44L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_MCP_STAT1
value|(45L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_MCP_STAT2
value|(46L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_MCP_STAT3
value|(47L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_MCP_STAT4
value|(48L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_MCP_STAT5
value|(49L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_MCP_STAT6
value|(50L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_MCP_STAT7
value|(51L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_PCI_CLK_CNT
value|(52L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_CORE_CLK_CNT
value|(53L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_HC_NUM_STATUS_BLOCKS
value|(54L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_HC_NUM_INT_GEN
value|(55L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_HC_NUM_INT_MBOX_WR
value|(56L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_HC_CORE_CLKS_TO_HW_INTACK
value|(59L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_HC_CORE_CLKS_TO_SW_INTACK
value|(60L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_HC_CORE_CLKS_DURING_SW_INTACK
value|(61L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TSCH_CMD_CNT
value|(62L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TSCH_SLOT_CNT
value|(63L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_CSCH_CMD_CNT
value|(64L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_CSCH_SLOT_CNT
value|(65L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RLUPQ_VALID_CNT
value|(66L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RXPQ_VALID_CNT
value|(67L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RXPCQ_VALID_CNT
value|(68L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RV2PPQ_VALID_CNT
value|(69L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RV2PMQ_VALID_CNT
value|(70L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RV2PTQ_VALID_CNT
value|(71L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RDMAQ_VALID_CNT
value|(72L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TSCHQ_VALID_CNT
value|(73L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TBDRQ_VALID_CNT
value|(74L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TXPQ_VALID_CNT
value|(75L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TDMAQ_VALID_CNT
value|(76L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TPATQ_VALID_CNT
value|(77L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TASQ_VALID_CNT
value|(78L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_CSQ_VALID_CNT
value|(79L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_CPQ_VALID_CNT
value|(80L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_COMXQ_VALID_CNT
value|(81L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_COMTQ_VALID_CNT
value|(82L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_COMQ_VALID_CNT
value|(83L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_MGMQ_VALID_CNT
value|(84L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_DMAE_READ_TRANSFERS_CNT
value|(85L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_DMAE_READ_DELAY_PCI_CLKS_CNT
value|(86L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_DMAE_BIG_READ_TRANSFERS_CNT
value|(87L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_DMAE_BIG_READ_DELAY_PCI_CLKS_CNT
value|(88L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_DMAE_BIG_READ_RETRY_AFTER_DATA_CNT
value|(89L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_DMAE_WRITE_TRANSFERS_CNT
value|(90L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_DMAE_WRITE_DELAY_PCI_CLKS_CNT
value|(91L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_DMAE_BIG_WRITE_TRANSFERS_CNT
value|(92L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_DMAE_BIG_WRITE_DELAY_PCI_CLKS_CNT
value|(93L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_DMAE_BIG_WRITE_RETRY_AFTER_DATA_CNT
value|(94L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_CTX_WR_CNT64
value|(95L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_CTX_RD_CNT64
value|(96L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_CTX_ACC_STALL_CLKS
value|(97L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_CTX_LOCK_STALL_CLKS
value|(98L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_MBQ_CTX_ACCESS_STAT
value|(99L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_MBQ_CTX_ACCESS64_STAT
value|(100L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_MBQ_PCI_STALL_STAT
value|(101L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TBDR_FTQ_ENTRY_CNT
value|(102L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TBDR_BURST_CNT
value|(103L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TDMA_FTQ_ENTRY_CNT
value|(104L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TDMA_BURST_CNT
value|(105L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RDMA_FTQ_ENTRY_CNT
value|(106L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RDMA_BURST_CNT
value|(107L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RLUP_MATCH_CNT
value|(108L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TMR_POLL_PASS_CNT
value|(109L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TMR_TMR1_CNT
value|(110L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TMR_TMR2_CNT
value|(111L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TMR_TMR3_CNT
value|(112L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TMR_TMR4_CNT
value|(113L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_TMR_TMR5_CNT
value|(114L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RV2P_STAT0
value|(115L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RV2P_STAT1
value|(116L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RV2P_STAT2
value|(117L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RV2P_STAT3
value|(118L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RV2P_STAT4
value|(119L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RV2P_STAT5
value|(120L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RBDC_PROC1_MISS
value|(121L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RBDC_PROC2_MISS
value|(122L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_0_RBDC_BURST_CNT
value|(127L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_1
value|(0x7fL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_2
value|(0x7fL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_0_GEN_SEL_3
value|(0x7fL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_1
value|0x00006854
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_1_GEN_SEL_4
value|(0x7fL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_1_GEN_SEL_5
value|(0x7fL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_1_GEN_SEL_6
value|(0x7fL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_1_GEN_SEL_7
value|(0x7fL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_2
value|0x00006858
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_2_GEN_SEL_8
value|(0x7fL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_2_GEN_SEL_9
value|(0x7fL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_2_GEN_SEL_10
value|(0x7fL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_2_GEN_SEL_11
value|(0x7fL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_3
value|0x0000685c
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_3_GEN_SEL_12
value|(0x7fL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_3_GEN_SEL_13
value|(0x7fL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_3_GEN_SEL_14
value|(0x7fL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_SEL_3_GEN_SEL_15
value|(0x7fL<<24)
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT0
value|0x00006888
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT1
value|0x0000688c
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT2
value|0x00006890
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT3
value|0x00006894
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT4
value|0x00006898
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT5
value|0x0000689c
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT6
value|0x000068a0
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT7
value|0x000068a4
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT8
value|0x000068a8
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT9
value|0x000068ac
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT10
value|0x000068b0
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT11
value|0x000068b4
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT12
value|0x000068b8
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT13
value|0x000068bc
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT14
value|0x000068c0
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT15
value|0x000068c4
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT_AC0
value|0x000068c8
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT_AC1
value|0x000068cc
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT_AC2
value|0x000068d0
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT_AC3
value|0x000068d4
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT_AC4
value|0x000068d8
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT_AC5
value|0x000068dc
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT_AC6
value|0x000068e0
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT_AC7
value|0x000068e4
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT_AC8
value|0x000068e8
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT_AC9
value|0x000068ec
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT_AC10
value|0x000068f0
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT_AC11
value|0x000068f4
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT_AC12
value|0x000068f8
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT_AC13
value|0x000068fc
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT_AC14
value|0x00006900
end_define

begin_define
define|#
directive|define
name|BCE_HC_STAT_GEN_STAT_AC15
value|0x00006904
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS
value|0x00006908
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_STAT_BUILD_STATE
value|(0xfL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_STAT_BUILD_STATE_IDLE
value|(0L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_STAT_BUILD_STATE_START
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_STAT_BUILD_STATE_REQUEST
value|(2L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_STAT_BUILD_STATE_UPDATE64
value|(3L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_STAT_BUILD_STATE_UPDATE32
value|(4L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_STAT_BUILD_STATE_UPDATE_DONE
value|(5L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_STAT_BUILD_STATE_DMA
value|(6L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_STAT_BUILD_STATE_MSI_CONTROL
value|(7L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_STAT_BUILD_STATE_MSI_LOW
value|(8L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_STAT_BUILD_STATE_MSI_HIGH
value|(9L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_STAT_BUILD_STATE_MSI_DATA
value|(10L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_DMA_STAT_STATE
value|(0xfL<<8)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_DMA_STAT_STATE_IDLE
value|(0L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_DMA_STAT_STATE_STATUS_PARAM
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_DMA_STAT_STATE_STATUS_DMA
value|(2L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_DMA_STAT_STATE_WRITE_COMP
value|(3L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_DMA_STAT_STATE_COMP
value|(4L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_DMA_STAT_STATE_STATISTIC_PARAM
value|(5L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_DMA_STAT_STATE_STATISTIC_DMA
value|(6L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_DMA_STAT_STATE_WRITE_COMP_1
value|(7L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_DMA_STAT_STATE_WRITE_COMP_2
value|(8L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_DMA_STAT_STATE_WAIT
value|(9L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_DMA_STAT_STATE_ABORT
value|(15L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_DMA_MSI_STATE
value|(0x7L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_STATISTIC_DMA_EN_STATE
value|(0x3L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_STATISTIC_DMA_EN_STATE_IDLE
value|(0L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_STATISTIC_DMA_EN_STATE_COUNT
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_STATISTIC_DMA_EN_STATE_START
value|(2L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1
value|0x0000690c
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_HW_INTACK_STATE
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_HW_INTACK_STATE_IDLE
value|(0L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_HW_INTACK_STATE_COUNT
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_SW_INTACK_STATE
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_SW_INTACK_STATE_IDLE
value|(0L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_SW_INTACK_STATE_COUNT
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_DURING_SW_INTACK_STATE
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_DURING_SW_INTACK_STATE_IDLE
value|(0L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_DURING_SW_INTACK_STATE_COUNT
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_MAILBOX_COUNT_STATE
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_MAILBOX_COUNT_STATE_IDLE
value|(0L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_MAILBOX_COUNT_STATE_COUNT
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_RAM_RD_ARB_STATE
value|(0xfL<<17)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_RAM_RD_ARB_STATE_IDLE
value|(0L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_RAM_RD_ARB_STATE_DMA
value|(1L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_RAM_RD_ARB_STATE_UPDATE
value|(2L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_RAM_RD_ARB_STATE_ASSIGN
value|(3L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_RAM_RD_ARB_STATE_WAIT
value|(4L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_RAM_RD_ARB_STATE_REG_UPDATE
value|(5L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_RAM_RD_ARB_STATE_REG_ASSIGN
value|(6L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_RAM_RD_ARB_STATE_REG_WAIT
value|(7L<<17)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_RAM_WR_ARB_STATE
value|(0x3L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_RAM_WR_ARB_STATE_NORMAL
value|(0L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_RAM_WR_ARB_STATE_CLEAR
value|(1L<<21)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_INT_GEN_STATE
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_INT_GEN_STATE_DLE
value|(0L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_INT_GEN_STATE_NTERRUPT
value|(1L<<23)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_STAT_CHAN_ID
value|(0x7L<<24)
end_define

begin_define
define|#
directive|define
name|BCE_HC_VIS_1_INT_B
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_HC_DEBUG_VECT_PEEK
value|0x00006910
end_define

begin_define
define|#
directive|define
name|BCE_HC_DEBUG_VECT_PEEK_1_VALUE
value|(0x7ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_HC_DEBUG_VECT_PEEK_1_PEEK_EN
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_HC_DEBUG_VECT_PEEK_1_SEL
value|(0xfL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_HC_DEBUG_VECT_PEEK_2_VALUE
value|(0x7ffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_HC_DEBUG_VECT_PEEK_2_PEEK_EN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_HC_DEBUG_VECT_PEEK_2_SEL
value|(0xfL<<28)
end_define

begin_comment
comment|/*  *  txp_reg definition  *  offset: 0x40000  */
end_comment

begin_define
define|#
directive|define
name|BCE_TXP_CPU_MODE
value|0x00045000
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_MODE_LOCAL_RST
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_MODE_STEP_ENA
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_MODE_PAGE_0_DATA_ENA
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_MODE_PAGE_0_INST_ENA
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_MODE_MSG_BIT1
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_MODE_INTERRUPT_ENA
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_MODE_SOFT_HALT
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_MODE_BAD_DATA_HALT_ENA
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_MODE_BAD_INST_HALT_ENA
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_MODE_FIO_ABORT_HALT_ENA
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_MODE_SPAD_UNDERFLOW_HALT_ENA
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_STATE
value|0x00045004
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_STATE_BREAKPOINT
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_STATE_BAD_INST_HALTED
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_STATE_PAGE_0_DATA_HALTED
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_STATE_PAGE_0_INST_HALTED
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_STATE_BAD_DATA_ADDR_HALTED
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_STATE_BAD_pc_HALTED
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_STATE_ALIGN_HALTED
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_STATE_FIO_ABORT_HALTED
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_STATE_SOFT_HALTED
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_STATE_SPAD_UNDERFLOW
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_STATE_INTERRRUPT
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_STATE_DATA_ACCESS_STALL
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_STATE_INST_FETCH_STALL
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_STATE_BLOCKED_READ
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_EVENT_MASK
value|0x00045008
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_EVENT_MASK_BREAKPOINT_MASK
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_EVENT_MASK_BAD_INST_HALTED_MASK
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_EVENT_MASK_PAGE_0_DATA_HALTED_MASK
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_EVENT_MASK_PAGE_0_INST_HALTED_MASK
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_EVENT_MASK_BAD_DATA_ADDR_HALTED_MASK
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_EVENT_MASK_BAD_PC_HALTED_MASK
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_EVENT_MASK_ALIGN_HALTED_MASK
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_EVENT_MASK_FIO_ABORT_MASK
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_EVENT_MASK_SOFT_HALTED_MASK
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_EVENT_MASK_SPAD_UNDERFLOW_MASK
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_EVENT_MASK_INTERRUPT_MASK
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_PROGRAM_COUNTER
value|0x0004501c
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_INSTRUCTION
value|0x00045020
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_DATA_ACCESS
value|0x00045024
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_INTERRUPT_ENABLE
value|0x00045028
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_INTERRUPT_VECTOR
value|0x0004502c
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_INTERRUPT_SAVED_PC
value|0x00045030
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_HW_BREAKPOINT
value|0x00045034
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_HW_BREAKPOINT_DISABLE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_HW_BREAKPOINT_ADDRESS
value|(0x3fffffffL<<2)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_DEBUG_VECT_PEEK
value|0x00045038
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_DEBUG_VECT_PEEK_1_VALUE
value|(0x7ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_DEBUG_VECT_PEEK_1_PEEK_EN
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_DEBUG_VECT_PEEK_1_SEL
value|(0xfL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_DEBUG_VECT_PEEK_2_VALUE
value|(0x7ffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_DEBUG_VECT_PEEK_2_PEEK_EN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_DEBUG_VECT_PEEK_2_SEL
value|(0xfL<<28)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_LAST_BRANCH_ADDR
value|0x00045048
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_LAST_BRANCH_ADDR_TYPE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_LAST_BRANCH_ADDR_TYPE_JUMP
value|(0L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_LAST_BRANCH_ADDR_TYPE_BRANCH
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_LAST_BRANCH_ADDR_LBA
value|(0x3fffffffL<<2)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_CPU_REG_FILE
value|0x00045200
end_define

begin_define
define|#
directive|define
name|BCE_TXP_FTQ_DATA
value|0x000453c0
end_define

begin_define
define|#
directive|define
name|BCE_TXP_FTQ_CMD
value|0x000453f8
end_define

begin_define
define|#
directive|define
name|BCE_TXP_FTQ_CMD_OFFSET
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_FTQ_CMD_WR_TOP
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_FTQ_CMD_WR_TOP_0
value|(0L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_FTQ_CMD_WR_TOP_1
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_FTQ_CMD_SFT_RESET
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_FTQ_CMD_RD_DATA
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_FTQ_CMD_ADD_INTERVEN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_FTQ_CMD_ADD_DATA
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_FTQ_CMD_INTERVENE_CLR
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_FTQ_CMD_POP
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_FTQ_CMD_BUSY
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_FTQ_CTL
value|0x000453fc
end_define

begin_define
define|#
directive|define
name|BCE_TXP_FTQ_CTL_INTERVENE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_FTQ_CTL_OVERFLOW
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_FTQ_CTL_FORCE_INTERVENE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_FTQ_CTL_MAX_DEPTH
value|(0x3ffL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_FTQ_CTL_CUR_DEPTH
value|(0x3ffL<<22)
end_define

begin_define
define|#
directive|define
name|BCE_TXP_SCRATCH
value|0x00060000
end_define

begin_comment
comment|/*  *  tpat_reg definition  *  offset: 0x80000  */
end_comment

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_MODE
value|0x00085000
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_MODE_LOCAL_RST
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_MODE_STEP_ENA
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_MODE_PAGE_0_DATA_ENA
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_MODE_PAGE_0_INST_ENA
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_MODE_MSG_BIT1
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_MODE_INTERRUPT_ENA
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_MODE_SOFT_HALT
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_MODE_BAD_DATA_HALT_ENA
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_MODE_BAD_INST_HALT_ENA
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_MODE_FIO_ABORT_HALT_ENA
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_MODE_SPAD_UNDERFLOW_HALT_ENA
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_STATE
value|0x00085004
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_STATE_BREAKPOINT
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_STATE_BAD_INST_HALTED
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_STATE_PAGE_0_DATA_HALTED
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_STATE_PAGE_0_INST_HALTED
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_STATE_BAD_DATA_ADDR_HALTED
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_STATE_BAD_pc_HALTED
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_STATE_ALIGN_HALTED
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_STATE_FIO_ABORT_HALTED
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_STATE_SOFT_HALTED
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_STATE_SPAD_UNDERFLOW
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_STATE_INTERRRUPT
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_STATE_DATA_ACCESS_STALL
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_STATE_INST_FETCH_STALL
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_STATE_BLOCKED_READ
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_EVENT_MASK
value|0x00085008
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_EVENT_MASK_BREAKPOINT_MASK
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_EVENT_MASK_BAD_INST_HALTED_MASK
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_EVENT_MASK_PAGE_0_DATA_HALTED_MASK
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_EVENT_MASK_PAGE_0_INST_HALTED_MASK
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_EVENT_MASK_BAD_DATA_ADDR_HALTED_MASK
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_EVENT_MASK_BAD_PC_HALTED_MASK
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_EVENT_MASK_ALIGN_HALTED_MASK
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_EVENT_MASK_FIO_ABORT_MASK
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_EVENT_MASK_SOFT_HALTED_MASK
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_EVENT_MASK_SPAD_UNDERFLOW_MASK
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_EVENT_MASK_INTERRUPT_MASK
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_PROGRAM_COUNTER
value|0x0008501c
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_INSTRUCTION
value|0x00085020
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_DATA_ACCESS
value|0x00085024
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_INTERRUPT_ENABLE
value|0x00085028
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_INTERRUPT_VECTOR
value|0x0008502c
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_INTERRUPT_SAVED_PC
value|0x00085030
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_HW_BREAKPOINT
value|0x00085034
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_HW_BREAKPOINT_DISABLE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_HW_BREAKPOINT_ADDRESS
value|(0x3fffffffL<<2)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_DEBUG_VECT_PEEK
value|0x00085038
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_DEBUG_VECT_PEEK_1_VALUE
value|(0x7ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_DEBUG_VECT_PEEK_1_PEEK_EN
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_DEBUG_VECT_PEEK_1_SEL
value|(0xfL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_DEBUG_VECT_PEEK_2_VALUE
value|(0x7ffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_DEBUG_VECT_PEEK_2_PEEK_EN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_DEBUG_VECT_PEEK_2_SEL
value|(0xfL<<28)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_LAST_BRANCH_ADDR
value|0x00085048
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_LAST_BRANCH_ADDR_TYPE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_LAST_BRANCH_ADDR_TYPE_JUMP
value|(0L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_LAST_BRANCH_ADDR_TYPE_BRANCH
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_LAST_BRANCH_ADDR_LBA
value|(0x3fffffffL<<2)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_CPU_REG_FILE
value|0x00085200
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_FTQ_DATA
value|0x000853c0
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_FTQ_CMD
value|0x000853f8
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_FTQ_CMD_OFFSET
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_FTQ_CMD_WR_TOP
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_FTQ_CMD_WR_TOP_0
value|(0L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_FTQ_CMD_WR_TOP_1
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_FTQ_CMD_SFT_RESET
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_FTQ_CMD_RD_DATA
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_FTQ_CMD_ADD_INTERVEN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_FTQ_CMD_ADD_DATA
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_FTQ_CMD_INTERVENE_CLR
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_FTQ_CMD_POP
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_FTQ_CMD_BUSY
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_FTQ_CTL
value|0x000853fc
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_FTQ_CTL_INTERVENE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_FTQ_CTL_OVERFLOW
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_FTQ_CTL_FORCE_INTERVENE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_FTQ_CTL_MAX_DEPTH
value|(0x3ffL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_FTQ_CTL_CUR_DEPTH
value|(0x3ffL<<22)
end_define

begin_define
define|#
directive|define
name|BCE_TPAT_SCRATCH
value|0x000a0000
end_define

begin_comment
comment|/*  *  rxp_reg definition  *  offset: 0xc0000  */
end_comment

begin_define
define|#
directive|define
name|BCE_RXP_CPU_MODE
value|0x000c5000
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_MODE_LOCAL_RST
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_MODE_STEP_ENA
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_MODE_PAGE_0_DATA_ENA
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_MODE_PAGE_0_INST_ENA
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_MODE_MSG_BIT1
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_MODE_INTERRUPT_ENA
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_MODE_SOFT_HALT
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_MODE_BAD_DATA_HALT_ENA
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_MODE_BAD_INST_HALT_ENA
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_MODE_FIO_ABORT_HALT_ENA
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_MODE_SPAD_UNDERFLOW_HALT_ENA
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_STATE
value|0x000c5004
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_STATE_BREAKPOINT
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_STATE_BAD_INST_HALTED
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_STATE_PAGE_0_DATA_HALTED
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_STATE_PAGE_0_INST_HALTED
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_STATE_BAD_DATA_ADDR_HALTED
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_STATE_BAD_pc_HALTED
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_STATE_ALIGN_HALTED
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_STATE_FIO_ABORT_HALTED
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_STATE_SOFT_HALTED
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_STATE_SPAD_UNDERFLOW
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_STATE_INTERRRUPT
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_STATE_DATA_ACCESS_STALL
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_STATE_INST_FETCH_STALL
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_STATE_BLOCKED_READ
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_EVENT_MASK
value|0x000c5008
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_EVENT_MASK_BREAKPOINT_MASK
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_EVENT_MASK_BAD_INST_HALTED_MASK
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_EVENT_MASK_PAGE_0_DATA_HALTED_MASK
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_EVENT_MASK_PAGE_0_INST_HALTED_MASK
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_EVENT_MASK_BAD_DATA_ADDR_HALTED_MASK
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_EVENT_MASK_BAD_PC_HALTED_MASK
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_EVENT_MASK_ALIGN_HALTED_MASK
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_EVENT_MASK_FIO_ABORT_MASK
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_EVENT_MASK_SOFT_HALTED_MASK
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_EVENT_MASK_SPAD_UNDERFLOW_MASK
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_EVENT_MASK_INTERRUPT_MASK
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_PROGRAM_COUNTER
value|0x000c501c
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_INSTRUCTION
value|0x000c5020
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_DATA_ACCESS
value|0x000c5024
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_INTERRUPT_ENABLE
value|0x000c5028
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_INTERRUPT_VECTOR
value|0x000c502c
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_INTERRUPT_SAVED_PC
value|0x000c5030
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_HW_BREAKPOINT
value|0x000c5034
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_HW_BREAKPOINT_DISABLE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_HW_BREAKPOINT_ADDRESS
value|(0x3fffffffL<<2)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_DEBUG_VECT_PEEK
value|0x000c5038
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_DEBUG_VECT_PEEK_1_VALUE
value|(0x7ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_DEBUG_VECT_PEEK_1_PEEK_EN
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_DEBUG_VECT_PEEK_1_SEL
value|(0xfL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_DEBUG_VECT_PEEK_2_VALUE
value|(0x7ffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_DEBUG_VECT_PEEK_2_PEEK_EN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_DEBUG_VECT_PEEK_2_SEL
value|(0xfL<<28)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_LAST_BRANCH_ADDR
value|0x000c5048
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_LAST_BRANCH_ADDR_TYPE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_LAST_BRANCH_ADDR_TYPE_JUMP
value|(0L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_LAST_BRANCH_ADDR_TYPE_BRANCH
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_LAST_BRANCH_ADDR_LBA
value|(0x3fffffffL<<2)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CPU_REG_FILE
value|0x000c5200
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CFTQ_DATA
value|0x000c5380
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CFTQ_CMD
value|0x000c53b8
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CFTQ_CMD_OFFSET
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CFTQ_CMD_WR_TOP
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CFTQ_CMD_WR_TOP_0
value|(0L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CFTQ_CMD_WR_TOP_1
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CFTQ_CMD_SFT_RESET
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CFTQ_CMD_RD_DATA
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CFTQ_CMD_ADD_INTERVEN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CFTQ_CMD_ADD_DATA
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CFTQ_CMD_INTERVENE_CLR
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CFTQ_CMD_POP
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CFTQ_CMD_BUSY
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CFTQ_CTL
value|0x000c53bc
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CFTQ_CTL_INTERVENE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CFTQ_CTL_OVERFLOW
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CFTQ_CTL_FORCE_INTERVENE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CFTQ_CTL_MAX_DEPTH
value|(0x3ffL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_CFTQ_CTL_CUR_DEPTH
value|(0x3ffL<<22)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_FTQ_DATA
value|0x000c53c0
end_define

begin_define
define|#
directive|define
name|BCE_RXP_FTQ_CMD
value|0x000c53f8
end_define

begin_define
define|#
directive|define
name|BCE_RXP_FTQ_CMD_OFFSET
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_FTQ_CMD_WR_TOP
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_FTQ_CMD_WR_TOP_0
value|(0L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_FTQ_CMD_WR_TOP_1
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_FTQ_CMD_SFT_RESET
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_FTQ_CMD_RD_DATA
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_FTQ_CMD_ADD_INTERVEN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_FTQ_CMD_ADD_DATA
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_FTQ_CMD_INTERVENE_CLR
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_FTQ_CMD_POP
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_FTQ_CMD_BUSY
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_FTQ_CTL
value|0x000c53fc
end_define

begin_define
define|#
directive|define
name|BCE_RXP_FTQ_CTL_INTERVENE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_FTQ_CTL_OVERFLOW
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_FTQ_CTL_FORCE_INTERVENE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_FTQ_CTL_MAX_DEPTH
value|(0x3ffL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_FTQ_CTL_CUR_DEPTH
value|(0x3ffL<<22)
end_define

begin_define
define|#
directive|define
name|BCE_RXP_SCRATCH
value|0x000e0000
end_define

begin_comment
comment|/*  *  com_reg definition  *  offset: 0x100000  */
end_comment

begin_define
define|#
directive|define
name|BCE_COM_CPU_MODE
value|0x00105000
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_MODE_LOCAL_RST
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_MODE_STEP_ENA
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_MODE_PAGE_0_DATA_ENA
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_MODE_PAGE_0_INST_ENA
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_MODE_MSG_BIT1
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_MODE_INTERRUPT_ENA
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_MODE_SOFT_HALT
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_MODE_BAD_DATA_HALT_ENA
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_MODE_BAD_INST_HALT_ENA
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_MODE_FIO_ABORT_HALT_ENA
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_MODE_SPAD_UNDERFLOW_HALT_ENA
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_STATE
value|0x00105004
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_STATE_BREAKPOINT
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_STATE_BAD_INST_HALTED
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_STATE_PAGE_0_DATA_HALTED
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_STATE_PAGE_0_INST_HALTED
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_STATE_BAD_DATA_ADDR_HALTED
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_STATE_BAD_pc_HALTED
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_STATE_ALIGN_HALTED
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_STATE_FIO_ABORT_HALTED
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_STATE_SOFT_HALTED
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_STATE_SPAD_UNDERFLOW
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_STATE_INTERRRUPT
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_STATE_DATA_ACCESS_STALL
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_STATE_INST_FETCH_STALL
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_STATE_BLOCKED_READ
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_EVENT_MASK
value|0x00105008
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_EVENT_MASK_BREAKPOINT_MASK
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_EVENT_MASK_BAD_INST_HALTED_MASK
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_EVENT_MASK_PAGE_0_DATA_HALTED_MASK
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_EVENT_MASK_PAGE_0_INST_HALTED_MASK
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_EVENT_MASK_BAD_DATA_ADDR_HALTED_MASK
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_EVENT_MASK_BAD_PC_HALTED_MASK
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_EVENT_MASK_ALIGN_HALTED_MASK
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_EVENT_MASK_FIO_ABORT_MASK
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_EVENT_MASK_SOFT_HALTED_MASK
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_EVENT_MASK_SPAD_UNDERFLOW_MASK
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_EVENT_MASK_INTERRUPT_MASK
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_PROGRAM_COUNTER
value|0x0010501c
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_INSTRUCTION
value|0x00105020
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_DATA_ACCESS
value|0x00105024
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_INTERRUPT_ENABLE
value|0x00105028
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_INTERRUPT_VECTOR
value|0x0010502c
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_INTERRUPT_SAVED_PC
value|0x00105030
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_HW_BREAKPOINT
value|0x00105034
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_HW_BREAKPOINT_DISABLE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_HW_BREAKPOINT_ADDRESS
value|(0x3fffffffL<<2)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_DEBUG_VECT_PEEK
value|0x00105038
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_DEBUG_VECT_PEEK_1_VALUE
value|(0x7ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_DEBUG_VECT_PEEK_1_PEEK_EN
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_DEBUG_VECT_PEEK_1_SEL
value|(0xfL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_DEBUG_VECT_PEEK_2_VALUE
value|(0x7ffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_DEBUG_VECT_PEEK_2_PEEK_EN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_DEBUG_VECT_PEEK_2_SEL
value|(0xfL<<28)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_LAST_BRANCH_ADDR
value|0x00105048
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_LAST_BRANCH_ADDR_TYPE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_LAST_BRANCH_ADDR_TYPE_JUMP
value|(0L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_LAST_BRANCH_ADDR_TYPE_BRANCH
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_LAST_BRANCH_ADDR_LBA
value|(0x3fffffffL<<2)
end_define

begin_define
define|#
directive|define
name|BCE_COM_CPU_REG_FILE
value|0x00105200
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMXQ_FTQ_DATA
value|0x00105340
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMXQ_FTQ_CMD
value|0x00105378
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMXQ_FTQ_CMD_OFFSET
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMXQ_FTQ_CMD_WR_TOP
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMXQ_FTQ_CMD_WR_TOP_0
value|(0L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMXQ_FTQ_CMD_WR_TOP_1
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMXQ_FTQ_CMD_SFT_RESET
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMXQ_FTQ_CMD_RD_DATA
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMXQ_FTQ_CMD_ADD_INTERVEN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMXQ_FTQ_CMD_ADD_DATA
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMXQ_FTQ_CMD_INTERVENE_CLR
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMXQ_FTQ_CMD_POP
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMXQ_FTQ_CMD_BUSY
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMXQ_FTQ_CTL
value|0x0010537c
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMXQ_FTQ_CTL_INTERVENE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMXQ_FTQ_CTL_OVERFLOW
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMXQ_FTQ_CTL_FORCE_INTERVENE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMXQ_FTQ_CTL_MAX_DEPTH
value|(0x3ffL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMXQ_FTQ_CTL_CUR_DEPTH
value|(0x3ffL<<22)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMTQ_FTQ_DATA
value|0x00105380
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMTQ_FTQ_CMD
value|0x001053b8
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMTQ_FTQ_CMD_OFFSET
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMTQ_FTQ_CMD_WR_TOP
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMTQ_FTQ_CMD_WR_TOP_0
value|(0L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMTQ_FTQ_CMD_WR_TOP_1
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMTQ_FTQ_CMD_SFT_RESET
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMTQ_FTQ_CMD_RD_DATA
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMTQ_FTQ_CMD_ADD_INTERVEN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMTQ_FTQ_CMD_ADD_DATA
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMTQ_FTQ_CMD_INTERVENE_CLR
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMTQ_FTQ_CMD_POP
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMTQ_FTQ_CMD_BUSY
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMTQ_FTQ_CTL
value|0x001053bc
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMTQ_FTQ_CTL_INTERVENE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMTQ_FTQ_CTL_OVERFLOW
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMTQ_FTQ_CTL_FORCE_INTERVENE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMTQ_FTQ_CTL_MAX_DEPTH
value|(0x3ffL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMTQ_FTQ_CTL_CUR_DEPTH
value|(0x3ffL<<22)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMQ_FTQ_DATA
value|0x001053c0
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMQ_FTQ_CMD
value|0x001053f8
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMQ_FTQ_CMD_OFFSET
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMQ_FTQ_CMD_WR_TOP
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMQ_FTQ_CMD_WR_TOP_0
value|(0L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMQ_FTQ_CMD_WR_TOP_1
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMQ_FTQ_CMD_SFT_RESET
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMQ_FTQ_CMD_RD_DATA
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMQ_FTQ_CMD_ADD_INTERVEN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMQ_FTQ_CMD_ADD_DATA
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMQ_FTQ_CMD_INTERVENE_CLR
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMQ_FTQ_CMD_POP
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMQ_FTQ_CMD_BUSY
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMQ_FTQ_CTL
value|0x001053fc
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMQ_FTQ_CTL_INTERVENE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMQ_FTQ_CTL_OVERFLOW
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMQ_FTQ_CTL_FORCE_INTERVENE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMQ_FTQ_CTL_MAX_DEPTH
value|(0x3ffL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_COM_COMQ_FTQ_CTL_CUR_DEPTH
value|(0x3ffL<<22)
end_define

begin_define
define|#
directive|define
name|BCE_COM_SCRATCH
value|0x00120000
end_define

begin_comment
comment|/*  *  cp_reg definition  *  offset: 0x180000  */
end_comment

begin_define
define|#
directive|define
name|BCE_CP_CPU_MODE
value|0x00185000
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_MODE_LOCAL_RST
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_MODE_STEP_ENA
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_MODE_PAGE_0_DATA_ENA
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_MODE_PAGE_0_INST_ENA
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_MODE_MSG_BIT1
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_MODE_INTERRUPT_ENA
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_MODE_SOFT_HALT
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_MODE_BAD_DATA_HALT_ENA
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_MODE_BAD_INST_HALT_ENA
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_MODE_FIO_ABORT_HALT_ENA
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_MODE_SPAD_UNDERFLOW_HALT_ENA
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_STATE
value|0x00185004
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_STATE_BREAKPOINT
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_STATE_BAD_INST_HALTED
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_STATE_PAGE_0_DATA_HALTED
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_STATE_PAGE_0_INST_HALTED
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_STATE_BAD_DATA_ADDR_HALTED
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_STATE_BAD_pc_HALTED
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_STATE_ALIGN_HALTED
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_STATE_FIO_ABORT_HALTED
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_STATE_SOFT_HALTED
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_STATE_SPAD_UNDERFLOW
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_STATE_INTERRRUPT
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_STATE_DATA_ACCESS_STALL
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_STATE_INST_FETCH_STALL
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_STATE_BLOCKED_READ
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_EVENT_MASK
value|0x00185008
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_EVENT_MASK_BREAKPOINT_MASK
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_EVENT_MASK_BAD_INST_HALTED_MASK
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_EVENT_MASK_PAGE_0_DATA_HALTED_MASK
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_EVENT_MASK_PAGE_0_INST_HALTED_MASK
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_EVENT_MASK_BAD_DATA_ADDR_HALTED_MASK
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_EVENT_MASK_BAD_PC_HALTED_MASK
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_EVENT_MASK_ALIGN_HALTED_MASK
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_EVENT_MASK_FIO_ABORT_MASK
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_EVENT_MASK_SOFT_HALTED_MASK
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_EVENT_MASK_SPAD_UNDERFLOW_MASK
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_EVENT_MASK_INTERRUPT_MASK
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_PROGRAM_COUNTER
value|0x0018501c
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_INSTRUCTION
value|0x00185020
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_DATA_ACCESS
value|0x00185024
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_INTERRUPT_ENABLE
value|0x00185028
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_INTERRUPT_VECTOR
value|0x0018502c
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_INTERRUPT_SAVED_PC
value|0x00185030
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_HW_BREAKPOINT
value|0x00185034
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_HW_BREAKPOINT_DISABLE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_HW_BREAKPOINT_ADDRESS
value|(0x3fffffffL<<2)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_DEBUG_VECT_PEEK
value|0x00185038
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_DEBUG_VECT_PEEK_1_VALUE
value|(0x7ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_DEBUG_VECT_PEEK_1_PEEK_EN
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_DEBUG_VECT_PEEK_1_SEL
value|(0xfL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_DEBUG_VECT_PEEK_2_VALUE
value|(0x7ffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_DEBUG_VECT_PEEK_2_PEEK_EN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_DEBUG_VECT_PEEK_2_SEL
value|(0xfL<<28)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_LAST_BRANCH_ADDR
value|0x00185048
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_LAST_BRANCH_ADDR_TYPE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_LAST_BRANCH_ADDR_TYPE_JUMP
value|(0L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_LAST_BRANCH_ADDR_TYPE_BRANCH
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_LAST_BRANCH_ADDR_LBA
value|(0x3fffffffL<<2)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPU_REG_FILE
value|0x00185200
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPQ_FTQ_DATA
value|0x001853c0
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPQ_FTQ_CMD
value|0x001853f8
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPQ_FTQ_CMD_OFFSET
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPQ_FTQ_CMD_WR_TOP
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPQ_FTQ_CMD_WR_TOP_0
value|(0L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPQ_FTQ_CMD_WR_TOP_1
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPQ_FTQ_CMD_SFT_RESET
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPQ_FTQ_CMD_RD_DATA
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPQ_FTQ_CMD_ADD_INTERVEN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPQ_FTQ_CMD_ADD_DATA
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPQ_FTQ_CMD_INTERVENE_CLR
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPQ_FTQ_CMD_POP
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPQ_FTQ_CMD_BUSY
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPQ_FTQ_CTL
value|0x001853fc
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPQ_FTQ_CTL_INTERVENE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPQ_FTQ_CTL_OVERFLOW
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPQ_FTQ_CTL_FORCE_INTERVENE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPQ_FTQ_CTL_MAX_DEPTH
value|(0x3ffL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_CP_CPQ_FTQ_CTL_CUR_DEPTH
value|(0x3ffL<<22)
end_define

begin_define
define|#
directive|define
name|BCE_CP_SCRATCH
value|0x001a0000
end_define

begin_comment
comment|/*  *  mcp_reg definition  *  offset: 0x140000  */
end_comment

begin_define
define|#
directive|define
name|BCE_MCP_CPU_MODE
value|0x00145000
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_MODE_LOCAL_RST
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_MODE_STEP_ENA
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_MODE_PAGE_0_DATA_ENA
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_MODE_PAGE_0_INST_ENA
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_MODE_MSG_BIT1
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_MODE_INTERRUPT_ENA
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_MODE_SOFT_HALT
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_MODE_BAD_DATA_HALT_ENA
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_MODE_BAD_INST_HALT_ENA
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_MODE_FIO_ABORT_HALT_ENA
value|(1L<<13)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_MODE_SPAD_UNDERFLOW_HALT_ENA
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_STATE
value|0x00145004
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_STATE_BREAKPOINT
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_STATE_BAD_INST_HALTED
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_STATE_PAGE_0_DATA_HALTED
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_STATE_PAGE_0_INST_HALTED
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_STATE_BAD_DATA_ADDR_HALTED
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_STATE_BAD_pc_HALTED
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_STATE_ALIGN_HALTED
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_STATE_FIO_ABORT_HALTED
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_STATE_SOFT_HALTED
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_STATE_SPAD_UNDERFLOW
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_STATE_INTERRRUPT
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_STATE_DATA_ACCESS_STALL
value|(1L<<14)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_STATE_INST_FETCH_STALL
value|(1L<<15)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_STATE_BLOCKED_READ
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_EVENT_MASK
value|0x00145008
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_EVENT_MASK_BREAKPOINT_MASK
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_EVENT_MASK_BAD_INST_HALTED_MASK
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_EVENT_MASK_PAGE_0_DATA_HALTED_MASK
value|(1L<<3)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_EVENT_MASK_PAGE_0_INST_HALTED_MASK
value|(1L<<4)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_EVENT_MASK_BAD_DATA_ADDR_HALTED_MASK
value|(1L<<5)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_EVENT_MASK_BAD_PC_HALTED_MASK
value|(1L<<6)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_EVENT_MASK_ALIGN_HALTED_MASK
value|(1L<<7)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_EVENT_MASK_FIO_ABORT_MASK
value|(1L<<8)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_EVENT_MASK_SOFT_HALTED_MASK
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_EVENT_MASK_SPAD_UNDERFLOW_MASK
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_EVENT_MASK_INTERRUPT_MASK
value|(1L<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_PROGRAM_COUNTER
value|0x0014501c
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_INSTRUCTION
value|0x00145020
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_DATA_ACCESS
value|0x00145024
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_INTERRUPT_ENABLE
value|0x00145028
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_INTERRUPT_VECTOR
value|0x0014502c
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_INTERRUPT_SAVED_PC
value|0x00145030
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_HW_BREAKPOINT
value|0x00145034
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_HW_BREAKPOINT_DISABLE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_HW_BREAKPOINT_ADDRESS
value|(0x3fffffffL<<2)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_DEBUG_VECT_PEEK
value|0x00145038
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_DEBUG_VECT_PEEK_1_VALUE
value|(0x7ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_DEBUG_VECT_PEEK_1_PEEK_EN
value|(1L<<11)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_DEBUG_VECT_PEEK_1_SEL
value|(0xfL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_DEBUG_VECT_PEEK_2_VALUE
value|(0x7ffL<<16)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_DEBUG_VECT_PEEK_2_PEEK_EN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_DEBUG_VECT_PEEK_2_SEL
value|(0xfL<<28)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_LAST_BRANCH_ADDR
value|0x00145048
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_LAST_BRANCH_ADDR_TYPE
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_LAST_BRANCH_ADDR_TYPE_JUMP
value|(0L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_LAST_BRANCH_ADDR_TYPE_BRANCH
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_LAST_BRANCH_ADDR_LBA
value|(0x3fffffffL<<2)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_CPU_REG_FILE
value|0x00145200
end_define

begin_define
define|#
directive|define
name|BCE_MCP_MCPQ_FTQ_DATA
value|0x001453c0
end_define

begin_define
define|#
directive|define
name|BCE_MCP_MCPQ_FTQ_CMD
value|0x001453f8
end_define

begin_define
define|#
directive|define
name|BCE_MCP_MCPQ_FTQ_CMD_OFFSET
value|(0x3ffL<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_MCPQ_FTQ_CMD_WR_TOP
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_MCPQ_FTQ_CMD_WR_TOP_0
value|(0L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_MCPQ_FTQ_CMD_WR_TOP_1
value|(1L<<10)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_MCPQ_FTQ_CMD_SFT_RESET
value|(1L<<25)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_MCPQ_FTQ_CMD_RD_DATA
value|(1L<<26)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_MCPQ_FTQ_CMD_ADD_INTERVEN
value|(1L<<27)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_MCPQ_FTQ_CMD_ADD_DATA
value|(1L<<28)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_MCPQ_FTQ_CMD_INTERVENE_CLR
value|(1L<<29)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_MCPQ_FTQ_CMD_POP
value|(1L<<30)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_MCPQ_FTQ_CMD_BUSY
value|(1L<<31)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_MCPQ_FTQ_CTL
value|0x001453fc
end_define

begin_define
define|#
directive|define
name|BCE_MCP_MCPQ_FTQ_CTL_INTERVENE
value|(1L<<0)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_MCPQ_FTQ_CTL_OVERFLOW
value|(1L<<1)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_MCPQ_FTQ_CTL_FORCE_INTERVENE
value|(1L<<2)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_MCPQ_FTQ_CTL_MAX_DEPTH
value|(0x3ffL<<12)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_MCPQ_FTQ_CTL_CUR_DEPTH
value|(0x3ffL<<22)
end_define

begin_define
define|#
directive|define
name|BCE_MCP_ROM
value|0x00150000
end_define

begin_define
define|#
directive|define
name|BCE_MCP_SCRATCH
value|0x00160000
end_define

begin_define
define|#
directive|define
name|BCE_SHM_HDR_SIGNATURE
value|BCE_MCP_SCRATCH
end_define

begin_define
define|#
directive|define
name|BCE_SHM_HDR_SIGNATURE_SIG_MASK
value|0xffff0000
end_define

begin_define
define|#
directive|define
name|BCE_SHM_HDR_SIGNATURE_SIG
value|0x53530000
end_define

begin_define
define|#
directive|define
name|BCE_SHM_HDR_SIGNATURE_VER_MASK
value|0x000000ff
end_define

begin_define
define|#
directive|define
name|BCE_SHM_HDR_SIGNATURE_VER_ONE
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BCE_SHM_HDR_ADDR_0
value|BCE_MCP_SCRATCH + 4
end_define

begin_define
define|#
directive|define
name|BCE_SHM_HDR_ADDR_1
value|BCE_MCP_SCRATCH + 8
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* End machine generated definitions.                                     */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|NUM_MC_HASH_REGISTERS
value|8
end_define

begin_comment
comment|/* PHY_ID1: bits 31-16; PHY_ID2: bits 15-0.  */
end_comment

begin_define
define|#
directive|define
name|PHY_BCM5706_PHY_ID
value|0x00206160
end_define

begin_define
define|#
directive|define
name|PHY_ID
parameter_list|(
name|id
parameter_list|)
value|((id)& 0xfffffff0)
end_define

begin_define
define|#
directive|define
name|PHY_REV_ID
parameter_list|(
name|id
parameter_list|)
value|((id)& 0xf)
end_define

begin_comment
comment|/* 5708 Serdes PHY registers */
end_comment

begin_define
define|#
directive|define
name|BCM5708S_UP1
value|0xb
end_define

begin_define
define|#
directive|define
name|BCM5708S_UP1_2G5
value|0x1
end_define

begin_define
define|#
directive|define
name|BCM5708S_BLK_ADDR
value|0x1f
end_define

begin_define
define|#
directive|define
name|BCM5708S_BLK_ADDR_DIG
value|0x0000
end_define

begin_define
define|#
directive|define
name|BCM5708S_BLK_ADDR_DIG3
value|0x0002
end_define

begin_define
define|#
directive|define
name|BCM5708S_BLK_ADDR_TX_MISC
value|0x0005
end_define

begin_comment
comment|/* Digital Block */
end_comment

begin_define
define|#
directive|define
name|BCM5708S_1000X_CTL1
value|0x10
end_define

begin_define
define|#
directive|define
name|BCM5708S_1000X_CTL1_FIBER_MODE
value|0x0001
end_define

begin_define
define|#
directive|define
name|BCM5708S_1000X_CTL1_AUTODET_EN
value|0x0010
end_define

begin_define
define|#
directive|define
name|BCM5708S_1000X_CTL2
value|0x11
end_define

begin_define
define|#
directive|define
name|BCM5708S_1000X_CTL2_PLLEL_DET_EN
value|0x0001
end_define

begin_define
define|#
directive|define
name|BCM5708S_1000X_STAT1
value|0x14
end_define

begin_define
define|#
directive|define
name|BCM5708S_1000X_STAT1_SGMII
value|0x0001
end_define

begin_define
define|#
directive|define
name|BCM5708S_1000X_STAT1_LINK
value|0x0002
end_define

begin_define
define|#
directive|define
name|BCM5708S_1000X_STAT1_FD
value|0x0004
end_define

begin_define
define|#
directive|define
name|BCM5708S_1000X_STAT1_SPEED_MASK
value|0x0018
end_define

begin_define
define|#
directive|define
name|BCM5708S_1000X_STAT1_SPEED_10
value|0x0000
end_define

begin_define
define|#
directive|define
name|BCM5708S_1000X_STAT1_SPEED_100
value|0x0008
end_define

begin_define
define|#
directive|define
name|BCM5708S_1000X_STAT1_SPEED_1G
value|0x0010
end_define

begin_define
define|#
directive|define
name|BCM5708S_1000X_STAT1_SPEED_2G5
value|0x0018
end_define

begin_define
define|#
directive|define
name|BCM5708S_1000X_STAT1_TX_PAUSE
value|0x0020
end_define

begin_define
define|#
directive|define
name|BCM5708S_1000X_STAT1_RX_PAUSE
value|0x0040
end_define

begin_comment
comment|/* Digital3 Block */
end_comment

begin_define
define|#
directive|define
name|BCM5708S_DIG_3_0
value|0x10
end_define

begin_define
define|#
directive|define
name|BCM5708S_DIG_3_0_USE_IEEE
value|0x0001
end_define

begin_comment
comment|/* Tx/Misc Block */
end_comment

begin_define
define|#
directive|define
name|BCM5708S_TX_ACTL1
value|0x15
end_define

begin_define
define|#
directive|define
name|BCM5708S_TX_ACTL1_DRIVER_VCM
value|0x30
end_define

begin_define
define|#
directive|define
name|BCM5708S_TX_ACTL3
value|0x17
end_define

begin_define
define|#
directive|define
name|RX_COPY_THRESH
value|92
end_define

begin_define
define|#
directive|define
name|DMA_READ_CHANS
value|5
end_define

begin_define
define|#
directive|define
name|DMA_WRITE_CHANS
value|3
end_define

begin_comment
comment|/* Use the natural page size of the host CPU. */
end_comment

begin_comment
comment|/* XXX: This has only been tested on amd64/i386 systems using 4KB pages. */
end_comment

begin_define
define|#
directive|define
name|BCM_PAGE_BITS
value|PAGE_SHIFT
end_define

begin_define
define|#
directive|define
name|BCM_PAGE_SIZE
value|PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|TX_PAGES
value|2
end_define

begin_define
define|#
directive|define
name|TOTAL_TX_BD_PER_PAGE
value|(BCM_PAGE_SIZE / sizeof(struct tx_bd))
end_define

begin_define
define|#
directive|define
name|USABLE_TX_BD_PER_PAGE
value|(TOTAL_TX_BD_PER_PAGE - 1)
end_define

begin_define
define|#
directive|define
name|TOTAL_TX_BD
value|(TOTAL_TX_BD_PER_PAGE * TX_PAGES)
end_define

begin_define
define|#
directive|define
name|USABLE_TX_BD
value|(USABLE_TX_BD_PER_PAGE * TX_PAGES)
end_define

begin_define
define|#
directive|define
name|MAX_TX_BD
value|(TOTAL_TX_BD - 1)
end_define

begin_define
define|#
directive|define
name|BCE_TX_SLACK_SPACE
value|16
end_define

begin_define
define|#
directive|define
name|RX_PAGES
value|2
end_define

begin_define
define|#
directive|define
name|TOTAL_RX_BD_PER_PAGE
value|(BCM_PAGE_SIZE / sizeof(struct rx_bd))
end_define

begin_define
define|#
directive|define
name|USABLE_RX_BD_PER_PAGE
value|(TOTAL_RX_BD_PER_PAGE - 1)
end_define

begin_define
define|#
directive|define
name|TOTAL_RX_BD
value|(TOTAL_RX_BD_PER_PAGE * RX_PAGES)
end_define

begin_define
define|#
directive|define
name|USABLE_RX_BD
value|(USABLE_RX_BD_PER_PAGE * RX_PAGES)
end_define

begin_define
define|#
directive|define
name|MAX_RX_BD
value|(TOTAL_RX_BD - 1)
end_define

begin_define
define|#
directive|define
name|BCE_RX_SLACK_SPACE
value|(MAX_RX_BD - 8)
end_define

begin_define
define|#
directive|define
name|NEXT_TX_BD
parameter_list|(
name|x
parameter_list|)
value|(((x)& USABLE_TX_BD_PER_PAGE) ==	\ 		(USABLE_TX_BD_PER_PAGE - 1)) ?					  	\ 		(x) + 2 : (x) + 1
end_define

begin_define
define|#
directive|define
name|TX_CHAIN_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)& MAX_TX_BD)
end_define

begin_define
define|#
directive|define
name|TX_PAGE
parameter_list|(
name|x
parameter_list|)
value|(((x)& ~USABLE_TX_BD_PER_PAGE)>> 8)
end_define

begin_define
define|#
directive|define
name|TX_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)& USABLE_TX_BD_PER_PAGE)
end_define

begin_define
define|#
directive|define
name|NEXT_RX_BD
parameter_list|(
name|x
parameter_list|)
value|(((x)& USABLE_RX_BD_PER_PAGE) ==	\ 		(USABLE_RX_BD_PER_PAGE - 1)) ?					\ 		(x) + 2 : (x) + 1
end_define

begin_define
define|#
directive|define
name|RX_CHAIN_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)& MAX_RX_BD)
end_define

begin_define
define|#
directive|define
name|RX_PAGE
parameter_list|(
name|x
parameter_list|)
value|(((x)& ~USABLE_RX_BD_PER_PAGE)>> 8)
end_define

begin_define
define|#
directive|define
name|RX_IDX
parameter_list|(
name|x
parameter_list|)
value|((x)& USABLE_RX_BD_PER_PAGE)
end_define

begin_comment
comment|/* Context size. */
end_comment

begin_define
define|#
directive|define
name|CTX_SHIFT
value|7
end_define

begin_define
define|#
directive|define
name|CTX_SIZE
value|(1<< CTX_SHIFT)
end_define

begin_define
define|#
directive|define
name|CTX_MASK
value|(CTX_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|GET_CID_ADDR
parameter_list|(
name|_cid
parameter_list|)
value|((_cid)<< CTX_SHIFT)
end_define

begin_define
define|#
directive|define
name|GET_CID
parameter_list|(
name|_cid_addr
parameter_list|)
value|((_cid_addr)>> CTX_SHIFT)
end_define

begin_define
define|#
directive|define
name|PHY_CTX_SHIFT
value|6
end_define

begin_define
define|#
directive|define
name|PHY_CTX_SIZE
value|(1<< PHY_CTX_SHIFT)
end_define

begin_define
define|#
directive|define
name|PHY_CTX_MASK
value|(PHY_CTX_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|GET_PCID_ADDR
parameter_list|(
name|_pcid
parameter_list|)
value|((_pcid)<< PHY_CTX_SHIFT)
end_define

begin_define
define|#
directive|define
name|GET_PCID
parameter_list|(
name|_pcid_addr
parameter_list|)
value|((_pcid_addr)>> PHY_CTX_SHIFT)
end_define

begin_define
define|#
directive|define
name|MB_KERNEL_CTX_SHIFT
value|8
end_define

begin_define
define|#
directive|define
name|MB_KERNEL_CTX_SIZE
value|(1<< MB_KERNEL_CTX_SHIFT)
end_define

begin_define
define|#
directive|define
name|MB_KERNEL_CTX_MASK
value|(MB_KERNEL_CTX_SIZE - 1)
end_define

begin_define
define|#
directive|define
name|MB_GET_CID_ADDR
parameter_list|(
name|_cid
parameter_list|)
value|(0x10000 + ((_cid)<< MB_KERNEL_CTX_SHIFT))
end_define

begin_define
define|#
directive|define
name|MAX_CID_CNT
value|0x4000
end_define

begin_define
define|#
directive|define
name|MAX_CID_ADDR
value|(GET_CID_ADDR(MAX_CID_CNT))
end_define

begin_define
define|#
directive|define
name|INVALID_CID_ADDR
value|0xffffffff
end_define

begin_define
define|#
directive|define
name|TX_CID
value|16
end_define

begin_define
define|#
directive|define
name|RX_CID
value|0
end_define

begin_define
define|#
directive|define
name|MB_TX_CID_ADDR
value|MB_GET_CID_ADDR(TX_CID)
end_define

begin_define
define|#
directive|define
name|MB_RX_CID_ADDR
value|MB_GET_CID_ADDR(RX_CID)
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* BCE Processor Firmwware Load Definitions                                 */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_struct
struct|struct
name|cpu_reg
block|{
name|u32
name|mode
decl_stmt|;
name|u32
name|mode_value_halt
decl_stmt|;
name|u32
name|mode_value_sstep
decl_stmt|;
name|u32
name|state
decl_stmt|;
name|u32
name|state_value_clear
decl_stmt|;
name|u32
name|gpr0
decl_stmt|;
name|u32
name|evmask
decl_stmt|;
name|u32
name|pc
decl_stmt|;
name|u32
name|inst
decl_stmt|;
name|u32
name|bp
decl_stmt|;
name|u32
name|spad_base
decl_stmt|;
name|u32
name|mips_view_base
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|fw_info
block|{
name|u32
name|ver_major
decl_stmt|;
name|u32
name|ver_minor
decl_stmt|;
name|u32
name|ver_fix
decl_stmt|;
name|u32
name|start_addr
decl_stmt|;
comment|/* Text section. */
name|u32
name|text_addr
decl_stmt|;
name|u32
name|text_len
decl_stmt|;
name|u32
name|text_index
decl_stmt|;
name|u32
modifier|*
name|text
decl_stmt|;
comment|/* Data section. */
name|u32
name|data_addr
decl_stmt|;
name|u32
name|data_len
decl_stmt|;
name|u32
name|data_index
decl_stmt|;
name|u32
modifier|*
name|data
decl_stmt|;
comment|/* SBSS section. */
name|u32
name|sbss_addr
decl_stmt|;
name|u32
name|sbss_len
decl_stmt|;
name|u32
name|sbss_index
decl_stmt|;
name|u32
modifier|*
name|sbss
decl_stmt|;
comment|/* BSS section. */
name|u32
name|bss_addr
decl_stmt|;
name|u32
name|bss_len
decl_stmt|;
name|u32
name|bss_index
decl_stmt|;
name|u32
modifier|*
name|bss
decl_stmt|;
comment|/* Read-only section. */
name|u32
name|rodata_addr
decl_stmt|;
name|u32
name|rodata_len
decl_stmt|;
name|u32
name|rodata_index
decl_stmt|;
name|u32
modifier|*
name|rodata
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|RV2P_PROC1
value|0
end_define

begin_define
define|#
directive|define
name|RV2P_PROC2
value|1
end_define

begin_define
define|#
directive|define
name|BCE_MIREG
parameter_list|(
name|x
parameter_list|)
value|((x& 0x1F)<< 16)
end_define

begin_define
define|#
directive|define
name|BCE_MIPHY
parameter_list|(
name|x
parameter_list|)
value|((x& 0x1F)<< 21)
end_define

begin_define
define|#
directive|define
name|BCE_PHY_TIMEOUT
value|50
end_define

begin_define
define|#
directive|define
name|BCE_NVRAM_SIZE
value|0x200
end_define

begin_define
define|#
directive|define
name|BCE_NVRAM_MAGIC
value|0x669955aa
end_define

begin_define
define|#
directive|define
name|BCE_CRC32_RESIDUAL
value|0xdebb20e3
end_define

begin_define
define|#
directive|define
name|BCE_TX_TIMEOUT
value|5
end_define

begin_define
define|#
directive|define
name|BCE_MAX_SEGMENTS
value|8
end_define

begin_define
define|#
directive|define
name|BCE_DMA_ALIGN
value|8
end_define

begin_define
define|#
directive|define
name|BCE_DMA_BOUNDARY
value|0
end_define

begin_comment
comment|/* The BCM5708 has a problem with addresses greater that 40bits. */
end_comment

begin_comment
comment|/* Handle the sizing issue in an architecture agnostic fashion.  */
end_comment

begin_if
if|#
directive|if
operator|(
name|BUS_SPACE_MAXADDR
operator|<
literal|0xFFFFFFFFFF
operator|)
end_if

begin_define
define|#
directive|define
name|BCE_BUS_SPACE_MAXADDR
value|BUS_SPACE_MAXADDR
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BCE_BUS_SPACE_MAXADDR
value|0xFFFFFFFFFF
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * XXX Checksum offload involving IP fragments seems to cause problems on  * transmit.  Disable it for now, hopefully there will be a more elegant  * solution later.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|BCE_IP_CSUM
end_ifdef

begin_define
define|#
directive|define
name|BCE_IF_HWASSIST
value|(CSUM_IP | CSUM_TCP | CSUM_UDP)
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|BCE_IF_HWASSIST
value|(CSUM_TCP | CSUM_UDP)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|BCE_IF_CAPABILITIES
value|(IFCAP_HWCSUM)
end_define

begin_define
define|#
directive|define
name|BCE_MIN_MTU
value|60
end_define

begin_define
define|#
directive|define
name|BCE_MIN_ETHER_MTU
value|64
end_define

begin_define
define|#
directive|define
name|BCE_MAX_STD_MTU
value|1500
end_define

begin_define
define|#
directive|define
name|BCE_MAX_STD_ETHER_MTU
value|1518
end_define

begin_define
define|#
directive|define
name|BCE_MAX_STD_ETHER_MTU_VLAN
value|1522
end_define

begin_define
define|#
directive|define
name|BCE_MAX_JUMBO_MTU
value|9000
end_define

begin_define
define|#
directive|define
name|BCE_MAX_JUMBO_ETHER_MTU
value|9018
end_define

begin_define
define|#
directive|define
name|BCE_MAX_JUMBO_ETHER_MTU_VLAN
value|9022
end_define

begin_if
if|#
directive|if
literal|0
end_if

begin_define
define|#
directive|define
name|BCE_MAX_MTU
value|ETHER_MAX_LEN_JUMBO + ETHER_VLAN_ENCAP_LEN
end_define

begin_comment
comment|/* 9022 */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/****************************************************************************/
end_comment

begin_comment
comment|/* BCE Device State Data Structure                                          */
end_comment

begin_comment
comment|/****************************************************************************/
end_comment

begin_define
define|#
directive|define
name|BCE_STATUS_BLK_SZ
value|sizeof(struct status_block)
end_define

begin_define
define|#
directive|define
name|BCE_STATS_BLK_SZ
value|sizeof(struct statistics_block)
end_define

begin_define
define|#
directive|define
name|BCE_TX_CHAIN_PAGE_SZ
value|BCM_PAGE_SIZE
end_define

begin_define
define|#
directive|define
name|BCE_RX_CHAIN_PAGE_SZ
value|BCM_PAGE_SIZE
end_define

begin_struct
struct|struct
name|bce_softc
block|{
name|struct
name|arpcom
name|arpcom
decl_stmt|;
name|device_t
name|bce_dev
decl_stmt|;
comment|/* Parent device handle */
name|u_int8_t
name|bce_unit
decl_stmt|;
comment|/* Interface number */
name|struct
name|resource
modifier|*
name|bce_res
decl_stmt|;
comment|/* Device resource handle */
name|struct
name|ifmedia
name|bce_ifmedia
decl_stmt|;
comment|/* TBI media info */
name|bus_space_tag_t
name|bce_btag
decl_stmt|;
comment|/* Device bus tag */
name|bus_space_handle_t
name|bce_bhandle
decl_stmt|;
comment|/* Device bus handle */
name|vm_offset_t
name|bce_vhandle
decl_stmt|;
comment|/* Device virtual memory handle */
name|struct
name|resource
modifier|*
name|bce_irq
decl_stmt|;
comment|/* IRQ Resource Handle */
name|void
modifier|*
name|bce_intrhand
decl_stmt|;
comment|/* Interrupt handler */
comment|/* ASIC Chip ID. */
name|u32
name|bce_chipid
decl_stmt|;
comment|/* General controller flags. */
name|u32
name|bce_flags
decl_stmt|;
define|#
directive|define
name|BCE_PCIX_FLAG
value|0x01
define|#
directive|define
name|BCE_PCI_32BIT_FLAG
value|0x02
define|#
directive|define
name|BCE_ONE_TDMA_FLAG
value|0x04
comment|/* Deprecated */
define|#
directive|define
name|BCE_NO_WOL_FLAG
value|0x08
define|#
directive|define
name|BCE_USING_DAC_FLAG
value|0x10
define|#
directive|define
name|BCE_USING_MSI_FLAG
value|0x20
define|#
directive|define
name|BCE_MFW_ENABLE_FLAG
value|0x40
comment|/* PHY specific flags. */
name|u32
name|bce_phy_flags
decl_stmt|;
define|#
directive|define
name|BCE_PHY_SERDES_FLAG
value|1
define|#
directive|define
name|BCE_PHY_CRC_FIX_FLAG
value|2
define|#
directive|define
name|BCE_PHY_PARALLEL_DETECT_FLAG
value|4
define|#
directive|define
name|BCE_PHY_2_5G_CAPABLE_FLAG
value|8
define|#
directive|define
name|BCE_PHY_INT_MODE_MASK_FLAG
value|0x300
define|#
directive|define
name|BCE_PHY_INT_MODE_AUTO_POLLING_FLAG
value|0x100
define|#
directive|define
name|BCE_PHY_INT_MODE_LINK_READY_FLAG
value|0x200
name|bus_addr_t
name|max_bus_addr
decl_stmt|;
name|u16
name|bus_speed_mhz
decl_stmt|;
comment|/* PCI bus speed */
name|struct
name|flash_spec
modifier|*
name|bce_flash_info
decl_stmt|;
comment|/* Flash NVRAM settings */
name|u32
name|bce_flash_size
decl_stmt|;
comment|/* Flash NVRAM size */
name|u32
name|bce_shmem_base
decl_stmt|;
comment|/* Shared Memory base address */
name|char
modifier|*
name|bce_name
decl_stmt|;
comment|/* Name string */
comment|/* Tracks the version of bootcode firmware. */
name|u32
name|bce_fw_ver
decl_stmt|;
comment|/* Tracks the state of the firmware.  0 = Running while any     */
comment|/* other value indicates that the firmware is not responding.   */
name|u16
name|bce_fw_timed_out
decl_stmt|;
comment|/* An incrementing sequence used to coordinate messages passed   */
comment|/* from the driver to the firmware.                              */
name|u16
name|bce_fw_wr_seq
decl_stmt|;
comment|/* An incrementing sequence used to let the firmware know that   */
comment|/* the driver is still operating.  Without the pulse, management */
comment|/* firmware such as IPMI or UMP will operate in OS absent state. */
name|u16
name|bce_fw_drv_pulse_wr_seq
decl_stmt|;
comment|/* These setting are used by the host coalescing (HC) block to   */
comment|/* to control how often the status block, statistics block and   */
comment|/* interrupts are generated.                                     */
name|u16
name|bce_tx_quick_cons_trip_int
decl_stmt|;
name|u16
name|bce_tx_quick_cons_trip
decl_stmt|;
name|u16
name|bce_rx_quick_cons_trip_int
decl_stmt|;
name|u16
name|bce_rx_quick_cons_trip
decl_stmt|;
name|u16
name|bce_comp_prod_trip_int
decl_stmt|;
name|u16
name|bce_comp_prod_trip
decl_stmt|;
name|u16
name|bce_tx_ticks_int
decl_stmt|;
name|u16
name|bce_tx_ticks
decl_stmt|;
name|u16
name|bce_rx_ticks_int
decl_stmt|;
name|u16
name|bce_rx_ticks
decl_stmt|;
name|u16
name|bce_com_ticks_int
decl_stmt|;
name|u16
name|bce_com_ticks
decl_stmt|;
name|u16
name|bce_cmd_ticks_int
decl_stmt|;
name|u16
name|bce_cmd_ticks
decl_stmt|;
name|u32
name|bce_stats_ticks
decl_stmt|;
comment|/* The address of the integrated PHY on the MII bus. */
name|int
name|bce_phy_addr
decl_stmt|;
comment|/* The device handle for the MII bus child device. */
name|device_t
name|bce_miibus
decl_stmt|;
comment|/* Driver maintained TX chain pointers and byte counter. */
name|u16
name|rx_prod
decl_stmt|;
name|u16
name|rx_cons
decl_stmt|;
name|u32
name|rx_prod_bseq
decl_stmt|;
comment|/* Counts the bytes used.  */
name|u16
name|tx_prod
decl_stmt|;
name|u16
name|tx_cons
decl_stmt|;
name|u32
name|tx_prod_bseq
decl_stmt|;
comment|/* Counts the bytes used.  */
name|int
name|bce_link
decl_stmt|;
name|struct
name|callout
name|bce_stat_ch
decl_stmt|;
comment|/* Frame size and mbuf allocation size for RX frames. */
name|u32
name|max_frame_size
decl_stmt|;
name|int
name|mbuf_alloc_size
decl_stmt|;
comment|/* Receive mode settings (i.e promiscuous, multicast, etc.). */
name|u32
name|rx_mode
decl_stmt|;
ifdef|#
directive|ifdef
name|DEVICE_POLLING
name|int
name|bce_rxcycles
decl_stmt|;
comment|/* Counter for receive polling cycles */
endif|#
directive|endif
comment|/* Bus tag for the bce controller. */
name|bus_dma_tag_t
name|parent_tag
decl_stmt|;
comment|/* H/W maintained TX buffer descriptor chain structure. */
name|bus_dma_tag_t
name|tx_bd_chain_tag
decl_stmt|;
name|bus_dmamap_t
name|tx_bd_chain_map
index|[
name|TX_PAGES
index|]
decl_stmt|;
name|struct
name|tx_bd
modifier|*
name|tx_bd_chain
index|[
name|TX_PAGES
index|]
decl_stmt|;
name|bus_addr_t
name|tx_bd_chain_paddr
index|[
name|TX_PAGES
index|]
decl_stmt|;
comment|/* H/W maintained RX buffer descriptor chain structure. */
name|bus_dma_tag_t
name|rx_bd_chain_tag
decl_stmt|;
name|bus_dmamap_t
name|rx_bd_chain_map
index|[
name|RX_PAGES
index|]
decl_stmt|;
name|struct
name|rx_bd
modifier|*
name|rx_bd_chain
index|[
name|RX_PAGES
index|]
decl_stmt|;
name|bus_addr_t
name|rx_bd_chain_paddr
index|[
name|RX_PAGES
index|]
decl_stmt|;
comment|/* H/W maintained status block. */
name|bus_dma_tag_t
name|status_tag
decl_stmt|;
name|bus_dmamap_t
name|status_map
decl_stmt|;
name|struct
name|status_block
modifier|*
name|status_block
decl_stmt|;
comment|/* virtual address */
name|bus_addr_t
name|status_block_paddr
decl_stmt|;
comment|/* Physical address */
comment|/* Driver maintained status block values. */
name|u16
name|last_status_idx
decl_stmt|;
name|u16
name|hw_rx_cons
decl_stmt|;
name|u16
name|hw_tx_cons
decl_stmt|;
comment|/* H/W maintained statistics block. */
name|bus_dma_tag_t
name|stats_tag
decl_stmt|;
name|bus_dmamap_t
name|stats_map
decl_stmt|;
name|struct
name|statistics_block
modifier|*
name|stats_block
decl_stmt|;
comment|/* Virtual address */
name|bus_addr_t
name|stats_block_paddr
decl_stmt|;
comment|/* Physical address */
comment|/* Bus tag for RX/TX mbufs. */
name|bus_dma_tag_t
name|rx_mbuf_tag
decl_stmt|;
name|bus_dma_tag_t
name|tx_mbuf_tag
decl_stmt|;
comment|/* S/W maintained mbuf TX chain structure. */
name|bus_dmamap_t
name|tx_mbuf_map
index|[
name|TOTAL_TX_BD
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|tx_mbuf_ptr
index|[
name|TOTAL_TX_BD
index|]
decl_stmt|;
comment|/* S/W maintained mbuf RX chain structure. */
name|bus_dmamap_t
name|rx_mbuf_map
index|[
name|TOTAL_RX_BD
index|]
decl_stmt|;
name|struct
name|mbuf
modifier|*
name|rx_mbuf_ptr
index|[
name|TOTAL_RX_BD
index|]
decl_stmt|;
comment|/* Track the number of rx_bd and tx_bd's in use. */
name|u16
name|free_rx_bd
decl_stmt|;
name|u16
name|used_tx_bd
decl_stmt|;
comment|/* Provides access to hardware statistics through sysctl. */
name|u64
name|stat_IfHCInOctets
decl_stmt|;
name|u64
name|stat_IfHCInBadOctets
decl_stmt|;
name|u64
name|stat_IfHCOutOctets
decl_stmt|;
name|u64
name|stat_IfHCOutBadOctets
decl_stmt|;
name|u64
name|stat_IfHCInUcastPkts
decl_stmt|;
name|u64
name|stat_IfHCInMulticastPkts
decl_stmt|;
name|u64
name|stat_IfHCInBroadcastPkts
decl_stmt|;
name|u64
name|stat_IfHCOutUcastPkts
decl_stmt|;
name|u64
name|stat_IfHCOutMulticastPkts
decl_stmt|;
name|u64
name|stat_IfHCOutBroadcastPkts
decl_stmt|;
name|u32
name|stat_emac_tx_stat_dot3statsinternalmactransmiterrors
decl_stmt|;
name|u32
name|stat_Dot3StatsCarrierSenseErrors
decl_stmt|;
name|u32
name|stat_Dot3StatsFCSErrors
decl_stmt|;
name|u32
name|stat_Dot3StatsAlignmentErrors
decl_stmt|;
name|u32
name|stat_Dot3StatsSingleCollisionFrames
decl_stmt|;
name|u32
name|stat_Dot3StatsMultipleCollisionFrames
decl_stmt|;
name|u32
name|stat_Dot3StatsDeferredTransmissions
decl_stmt|;
name|u32
name|stat_Dot3StatsExcessiveCollisions
decl_stmt|;
name|u32
name|stat_Dot3StatsLateCollisions
decl_stmt|;
name|u32
name|stat_EtherStatsCollisions
decl_stmt|;
name|u32
name|stat_EtherStatsFragments
decl_stmt|;
name|u32
name|stat_EtherStatsJabbers
decl_stmt|;
name|u32
name|stat_EtherStatsUndersizePkts
decl_stmt|;
name|u32
name|stat_EtherStatsOverrsizePkts
decl_stmt|;
name|u32
name|stat_EtherStatsPktsRx64Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsRx65Octetsto127Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsRx128Octetsto255Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsRx256Octetsto511Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsRx512Octetsto1023Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsRx1024Octetsto1522Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsRx1523Octetsto9022Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsTx64Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsTx65Octetsto127Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsTx128Octetsto255Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsTx256Octetsto511Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsTx512Octetsto1023Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsTx1024Octetsto1522Octets
decl_stmt|;
name|u32
name|stat_EtherStatsPktsTx1523Octetsto9022Octets
decl_stmt|;
name|u32
name|stat_XonPauseFramesReceived
decl_stmt|;
name|u32
name|stat_XoffPauseFramesReceived
decl_stmt|;
name|u32
name|stat_OutXonSent
decl_stmt|;
name|u32
name|stat_OutXoffSent
decl_stmt|;
name|u32
name|stat_FlowControlDone
decl_stmt|;
name|u32
name|stat_MacControlFramesReceived
decl_stmt|;
name|u32
name|stat_XoffStateEntered
decl_stmt|;
name|u32
name|stat_IfInFramesL2FilterDiscards
decl_stmt|;
name|u32
name|stat_IfInRuleCheckerDiscards
decl_stmt|;
name|u32
name|stat_IfInFTQDiscards
decl_stmt|;
name|u32
name|stat_IfInMBUFDiscards
decl_stmt|;
name|u32
name|stat_IfInRuleCheckerP4Hit
decl_stmt|;
name|u32
name|stat_CatchupInRuleCheckerDiscards
decl_stmt|;
name|u32
name|stat_CatchupInFTQDiscards
decl_stmt|;
name|u32
name|stat_CatchupInMBUFDiscards
decl_stmt|;
name|u32
name|stat_CatchupInRuleCheckerP4Hit
decl_stmt|;
name|struct
name|sysctl_ctx_list
name|sysctl_ctx
decl_stmt|;
name|struct
name|sysctl_oid
modifier|*
name|sysctl_tree
decl_stmt|;
ifdef|#
directive|ifdef
name|BCE_DEBUG
comment|/* Track the number of enqueued mbufs. */
name|int
name|tx_mbuf_alloc
decl_stmt|;
name|int
name|rx_mbuf_alloc
decl_stmt|;
comment|/* Track how many and what type of interrupts are generated. */
name|u32
name|interrupts_generated
decl_stmt|;
name|u32
name|interrupts_handled
decl_stmt|;
name|u32
name|rx_interrupts
decl_stmt|;
name|u32
name|tx_interrupts
decl_stmt|;
name|u32
name|rx_low_watermark
decl_stmt|;
comment|/* Lowest number of rx_bd's free. */
name|u32
name|tx_hi_watermark
decl_stmt|;
comment|/* Greatest number of tx_bd's used. */
name|u32
name|mbuf_alloc_failed
decl_stmt|;
comment|/* Mbuf allocation failure counter. */
name|u32
name|l2fhdr_status_errors
decl_stmt|;
name|u32
name|unexpected_attentions
decl_stmt|;
name|u32
name|lost_status_block_updates
decl_stmt|;
endif|#
directive|endif
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* #ifndef _BCE_H_DEFINED */
end_comment

end_unit

