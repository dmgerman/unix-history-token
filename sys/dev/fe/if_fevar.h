begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * All Rights Reserved, Copyright (C) Fujitsu Limited 1995  *  * This software may be used, modified, copied, distributed, and sold, in  * both source and binary form provided that the above copyright, these  * terms and the following disclaimer are retained.  The name of the author  * and/or the contributor may not be used to endorse or promote products  * derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND THE CONTRIBUTOR ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR THE CONTRIBUTOR BE LIABLE  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION.  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* How many registers does an fe-supported adapter have at maximum?  */
end_comment

begin_define
define|#
directive|define
name|MAXREGISTERS
value|32
end_define

begin_comment
comment|/* Shouldn't these be defined somewhere else such as isa_device.h?  */
end_comment

begin_define
define|#
directive|define
name|NO_IRQ
value|0
end_define

begin_comment
comment|/* Flags for stability.  */
end_comment

begin_define
define|#
directive|define
name|UNSTABLE_IRQ
value|0x01
end_define

begin_comment
comment|/* IRQ setting may be incorrect.  */
end_comment

begin_define
define|#
directive|define
name|UNSTABLE_MAC
value|0x02
end_define

begin_comment
comment|/* Probed MAC address may be incorrect.  */
end_comment

begin_define
define|#
directive|define
name|UNSTABLE_TYPE
value|0x04
end_define

begin_comment
comment|/* Probed vendor/model may be incorrect.  */
end_comment

begin_comment
comment|/* Mapping between media bitmap (in fe_softc.mbitmap) and ifm_media.  */
end_comment

begin_define
define|#
directive|define
name|MB_HA
value|0x0001
end_define

begin_define
define|#
directive|define
name|MB_HM
value|0x0002
end_define

begin_define
define|#
directive|define
name|MB_HT
value|0x0004
end_define

begin_define
define|#
directive|define
name|MB_H2
value|0x0008
end_define

begin_define
define|#
directive|define
name|MB_H5
value|0x0010
end_define

begin_define
define|#
directive|define
name|MB_HF
value|0x0020
end_define

begin_define
define|#
directive|define
name|MB_FT
value|0x0040
end_define

begin_comment
comment|/* Card types. */
end_comment

begin_define
define|#
directive|define
name|FE_TYPE_SSI
value|1
end_define

begin_define
define|#
directive|define
name|FE_TYPE_JLI
value|2
end_define

begin_define
define|#
directive|define
name|FE_TYPE_FMV
value|3
end_define

begin_define
define|#
directive|define
name|FE_TYPE_LNX
value|4
end_define

begin_define
define|#
directive|define
name|FE_TYPE_UBN
value|5
end_define

begin_define
define|#
directive|define
name|FE_TYPE_GWY
value|6
end_define

begin_define
define|#
directive|define
name|FE_TYPE_MBH
value|7
end_define

begin_define
define|#
directive|define
name|FE_TYPE_TDK
value|8
end_define

begin_define
define|#
directive|define
name|FE_TYPE_RE1000
value|9
end_define

begin_define
define|#
directive|define
name|FE_TYPE_CNET9NE
value|10
end_define

begin_define
define|#
directive|define
name|FE_TYPE_REX
value|11
end_define

begin_comment
comment|/*  * Data type for a multicast address filter on 8696x.  */
end_comment

begin_struct
struct|struct
name|fe_filter
block|{
name|u_char
name|data
index|[
name|FE_FILTER_LEN
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * fe_softc: per line info and status  */
end_comment

begin_struct
struct|struct
name|fe_softc
block|{
comment|/* Used by "common" codes.  */
name|struct
name|arpcom
name|arpcom
decl_stmt|;
comment|/* Ethernet common */
comment|/* Used by config codes.  */
name|int
name|type
decl_stmt|;
name|int
name|port_used
decl_stmt|;
name|struct
name|resource
modifier|*
name|port_res
decl_stmt|;
name|bus_space_tag_t
name|iot
decl_stmt|;
name|bus_space_handle_t
name|ioh
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq_res
decl_stmt|;
name|void
modifier|*
name|irq_handle
decl_stmt|;
comment|/* Set by probe() and not modified in later phases.  */
name|char
specifier|const
modifier|*
name|typestr
decl_stmt|;
comment|/* printable name of the interface.  */
name|u_short
name|txb_size
decl_stmt|;
comment|/* size of TX buffer, in bytes  */
name|u_char
name|proto_dlcr4
decl_stmt|;
comment|/* DLCR4 prototype.  */
name|u_char
name|proto_dlcr5
decl_stmt|;
comment|/* DLCR5 prototype.  */
name|u_char
name|proto_dlcr6
decl_stmt|;
comment|/* DLCR6 prototype.  */
name|u_char
name|proto_dlcr7
decl_stmt|;
comment|/* DLCR7 prototype.  */
name|u_char
name|proto_bmpr13
decl_stmt|;
comment|/* BMPR13 prototype.  */
name|u_char
name|stability
decl_stmt|;
comment|/* How stable is this?  */
name|u_short
name|priv_info
decl_stmt|;
comment|/* info specific to a vendor/model.  */
comment|/* Vendor/model specific hooks.  */
name|void
function_decl|(
modifier|*
name|init
function_decl|)
parameter_list|(
name|struct
name|fe_softc
modifier|*
parameter_list|)
function_decl|;
comment|/* Just before fe_init().  */
name|void
function_decl|(
modifier|*
name|stop
function_decl|)
parameter_list|(
name|struct
name|fe_softc
modifier|*
parameter_list|)
function_decl|;
comment|/* Just after fe_stop().  */
comment|/* Transmission buffer management.  */
name|u_short
name|txb_free
decl_stmt|;
comment|/* free bytes in TX buffer  */
name|u_char
name|txb_count
decl_stmt|;
comment|/* number of packets in TX buffer  */
name|u_char
name|txb_sched
decl_stmt|;
comment|/* number of scheduled packets  */
comment|/* Excessive collision counter (see fe_tint() for details.)  */
name|u_char
name|tx_excolls
decl_stmt|;
comment|/* # of excessive collisions.  */
comment|/* Multicast address filter management.  */
name|u_char
name|filter_change
decl_stmt|;
comment|/* MARs must be changed ASAP. */
name|struct
name|fe_filter
name|filter
decl_stmt|;
comment|/* new filter value.  */
comment|/* Network management.  */
name|struct
name|ifmib_iso_8802_3
name|mibdata
decl_stmt|;
comment|/* Media information.  */
name|struct
name|ifmedia
name|media
decl_stmt|;
comment|/* used by if_media.  */
name|u_short
name|mbitmap
decl_stmt|;
comment|/* bitmap for supported media; see bit2media */
name|int
name|defmedia
decl_stmt|;
comment|/* default media  */
name|void
function_decl|(
modifier|*
name|msel
function_decl|)
parameter_list|(
name|struct
name|fe_softc
modifier|*
parameter_list|)
function_decl|;
comment|/* media selector.  */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|sc_if
value|arpcom.ac_if
end_define

begin_define
define|#
directive|define
name|sc_unit
value|arpcom.ac_if.if_unit
end_define

begin_define
define|#
directive|define
name|sc_enaddr
value|arpcom.ac_enaddr
end_define

begin_struct
struct|struct
name|fe_simple_probe_struct
block|{
name|u_char
name|port
decl_stmt|;
comment|/* Offset from the base I/O address.  */
name|u_char
name|mask
decl_stmt|;
comment|/* Bits to be checked.  */
name|u_char
name|bits
decl_stmt|;
comment|/* Values to be compared against.  */
block|}
struct|;
end_struct

begin_decl_stmt
specifier|extern
name|devclass_t
name|fe_devclass
decl_stmt|;
end_decl_stmt

begin_function_decl
name|int
name|fe_attach
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fe_alloc_port
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fe_alloc_irq
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe_release_resource
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|fe_simple_probe
parameter_list|(
name|struct
name|fe_softc
specifier|const
modifier|*
parameter_list|,
name|struct
name|fe_simple_probe_struct
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|valid_Ether_p
parameter_list|(
name|u_char
specifier|const
modifier|*
parameter_list|,
name|unsigned
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe_softc_defaults
parameter_list|(
name|struct
name|fe_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe_stop
parameter_list|(
name|struct
name|fe_softc
modifier|*
name|sc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe_irq_failure
parameter_list|(
name|char
specifier|const
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|,
name|char
specifier|const
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe_msel_965
parameter_list|(
name|struct
name|fe_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe_read_eeprom_jli
parameter_list|(
name|struct
name|fe_softc
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe_init_jli
parameter_list|(
name|struct
name|fe_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe_read_eeprom_ssi
parameter_list|(
name|struct
name|fe_softc
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe_read_eeprom_lnx
parameter_list|(
name|struct
name|fe_softc
modifier|*
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe_init_lnx
parameter_list|(
name|struct
name|fe_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|fe_init_ubn
parameter_list|(
name|struct
name|fe_softc
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|fe_inb
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_1((sc)->iot, (sc)->ioh, (port))
end_define

begin_define
define|#
directive|define
name|fe_outb
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_1((sc)->iot, (sc)->ioh, (port), (value))
end_define

begin_define
define|#
directive|define
name|fe_inw
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|)
define|\
value|bus_space_read_2((sc)->iot, (sc)->ioh, (port))
end_define

begin_define
define|#
directive|define
name|fe_outw
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|value
parameter_list|)
define|\
value|bus_space_write_2((sc)->iot, (sc)->ioh, (port), (value))
end_define

begin_define
define|#
directive|define
name|fe_insb
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_1((sc)->iot, (sc)->ioh, (port), (addr), (count))
end_define

begin_define
define|#
directive|define
name|fe_outsb
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_multi_1((sc)->iot, (sc)->ioh, (port), (addr), (count))
end_define

begin_define
define|#
directive|define
name|fe_insw
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_multi_2((sc)->iot, (sc)->ioh, (port), (addr), (count))
end_define

begin_define
define|#
directive|define
name|fe_outsw
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_multi_2((sc)->iot, (sc)->ioh, (port), (addr), (count))
end_define

begin_define
define|#
directive|define
name|fe_inblk
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_read_region_1((sc)->iot, (sc)->ioh, (port), (addr), (count))
end_define

begin_define
define|#
directive|define
name|fe_outblk
parameter_list|(
name|sc
parameter_list|,
name|port
parameter_list|,
name|addr
parameter_list|,
name|count
parameter_list|)
define|\
value|bus_space_write_region_1((sc)->iot, (sc)->ioh, (port), (addr), (count))
end_define

end_unit

