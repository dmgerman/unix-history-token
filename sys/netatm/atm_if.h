begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * Core ATM Services  * -----------------  *  * ATM Physical and Network Interface definitions   *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_NETATM_ATM_IF_H
end_ifndef

begin_define
define|#
directive|define
name|_NETATM_ATM_IF_H
end_define

begin_comment
comment|/*  * Handy constants  */
end_comment

begin_define
define|#
directive|define
name|ATM_NIF_MTU
value|9180
end_define

begin_comment
comment|/* Default network interface MTU */
end_comment

begin_define
define|#
directive|define
name|ATM_PCR_TAXI100
value|227273
end_define

begin_comment
comment|/* Peak Cell Rate for 100 Mbs TAXI */
end_comment

begin_define
define|#
directive|define
name|ATM_PCR_TAXI140
value|318181
end_define

begin_comment
comment|/* Peak Cell Rate for 140 Mbs TAXI */
end_comment

begin_define
define|#
directive|define
name|ATM_PCR_OC3C
value|353207
end_define

begin_comment
comment|/* Peak Cell Rate for OC3c */
end_comment

begin_define
define|#
directive|define
name|ATM_PCR_OC12C
value|1416905
end_define

begin_comment
comment|/* Peak Cell Rate for OC12c */
end_comment

begin_comment
comment|/*  * Media Access Control (MAC) address  */
end_comment

begin_struct
struct|struct
name|mac_addr
block|{
name|u_char
name|ma_data
index|[
literal|6
index|]
decl_stmt|;
comment|/* MAC address */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|mac_addr
name|Mac_addr
typedef|;
end_typedef

begin_comment
comment|/*  * Adapter vendor identifiers  */
end_comment

begin_enum
enum|enum
name|atm_vendor
block|{
name|VENDOR_UNKNOWN
block|,
comment|/* Unknown vendor */
name|VENDOR_FORE
block|,
comment|/* FORE Systems, Inc. */
name|VENDOR_ENI
comment|/* Efficient Networks, Inc. */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|atm_vendor
name|Atm_vendor
typedef|;
end_typedef

begin_comment
comment|/*  * Adapter vendor interface identifiers  */
end_comment

begin_enum
enum|enum
name|atm_vendapi
block|{
name|VENDAPI_UNKNOWN
block|,
comment|/* Unknown interface */
name|VENDAPI_FORE_1
block|,
comment|/* FORE - 200 Series */
name|VENDAPI_ENI_1
comment|/* ENI - Midway */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|atm_vendapi
name|Atm_vendapi
typedef|;
end_typedef

begin_comment
comment|/*  * Adapter device model identifiers  */
end_comment

begin_enum
enum|enum
name|atm_device
block|{
name|DEV_UNKNOWN
block|,
comment|/* Unknown device */
name|DEV_FORE_SBA200E
block|,
comment|/* FORE SBA-200E */
name|DEV_FORE_SBA200
block|,
comment|/* FORE SBA-200 */
name|DEV_FORE_PCA200E
block|,
comment|/* FORE PCA-200E */
name|DEV_ENI_155P
comment|/* ENI-155p */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|atm_device
name|Atm_device
typedef|;
end_typedef

begin_comment
comment|/*  * Adapter media identifiers  */
end_comment

begin_enum
enum|enum
name|atm_media
block|{
name|MEDIA_UNKNOWN
block|,
comment|/* Unknown media type */
name|MEDIA_TAXI_100
block|,
comment|/* TAXI - 100 Mbps */
name|MEDIA_TAXI_140
block|,
comment|/* TAXI - 140 Mbps */
name|MEDIA_OC3C
block|,
comment|/* OC-3C */
name|MEDIA_OC12C
block|,
comment|/* OC-12C */
name|MEDIA_UTP155
comment|/* UTP-155 */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|atm_media
name|Atm_media
typedef|;
end_typedef

begin_comment
comment|/*  * Bus type identifiers  */
end_comment

begin_enum
enum|enum
name|atm_bus
block|{
name|BUS_UNKNOWN
block|,
comment|/* Unknown bus type */
name|BUS_SBUS_B16
block|,
comment|/* SBus: 16 byte (4 word) max burst */
name|BUS_SBUS_B32
block|,
comment|/* SBus: 32 byte (8 word) max burst */
name|BUS_PCI
comment|/* PCI */
block|}
enum|;
end_enum

begin_typedef
typedef|typedef
name|enum
name|atm_bus
name|Atm_bus
typedef|;
end_typedef

begin_define
define|#
directive|define
name|VERSION_LEN
value|16
end_define

begin_comment
comment|/* Length of version info string */
end_comment

begin_comment
comment|/*  * ATM adapter configuration information structure  */
end_comment

begin_struct
struct|struct
name|atm_config
block|{
name|Atm_vendor
name|ac_vendor
decl_stmt|;
comment|/* Vendor */
name|Atm_vendapi
name|ac_vendapi
decl_stmt|;
comment|/* Vendor interface */
name|Atm_device
name|ac_device
decl_stmt|;
comment|/* Device model */
name|Atm_media
name|ac_media
decl_stmt|;
comment|/* Media type */
name|u_long
name|ac_serial
decl_stmt|;
comment|/* Serial number */
name|Atm_bus
name|ac_bustype
decl_stmt|;
comment|/* Bus type */
name|u_long
name|ac_busslot
decl_stmt|;
comment|/* Bus slot info (bus type dependent) */
name|u_long
name|ac_ram
decl_stmt|;
comment|/* Device ram offset */
name|u_long
name|ac_ramsize
decl_stmt|;
comment|/* Device ram size */
name|Mac_addr
name|ac_macaddr
decl_stmt|;
comment|/* MAC address */
name|char
name|ac_hard_vers
index|[
name|VERSION_LEN
index|]
decl_stmt|;
comment|/* Hardware version */
name|char
name|ac_firm_vers
index|[
name|VERSION_LEN
index|]
decl_stmt|;
comment|/* Firmware version */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|atm_config
name|Atm_config
typedef|;
end_typedef

begin_ifdef
ifdef|#
directive|ifdef
name|_KERNEL
end_ifdef

begin_comment
comment|/*  * Common structure used to define each physical ATM device interface.  * This structure will (normally) be embedded at the top of each driver's   * device-specific interface structure.    */
end_comment

begin_struct
struct|struct
name|atm_pif
block|{
name|struct
name|atm_pif
modifier|*
name|pif_next
decl_stmt|;
comment|/* Next registered atm interface */
name|char
modifier|*
name|pif_name
decl_stmt|;
comment|/* Device name */
name|short
name|pif_unit
decl_stmt|;
comment|/* Device unit number */
name|u_char
name|pif_flags
decl_stmt|;
comment|/* Interface flags (see below) */
name|struct
name|sigmgr
modifier|*
name|pif_sigmgr
decl_stmt|;
comment|/* Signalling Manager for interface */
name|struct
name|siginst
modifier|*
name|pif_siginst
decl_stmt|;
comment|/* Signalling protocol instance */
name|struct
name|stack_defn
modifier|*
name|pif_services
decl_stmt|;
comment|/* Interface's stack services */
name|struct
name|mac_addr
name|pif_macaddr
decl_stmt|;
comment|/* Interface's MAC address */
name|struct
name|atm_nif
modifier|*
name|pif_nif
decl_stmt|;
comment|/* List of network interfaces */
name|struct
name|atm_pif
modifier|*
name|pif_grnext
decl_stmt|;
comment|/* Next atm device in group */
comment|/* Exported functions */
name|int
function_decl|(
modifier|*
name|pif_ioctl
function_decl|)
comment|/* Interface ioctl handler */
parameter_list|(
name|int
parameter_list|,
name|caddr_t
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
comment|/* Interface statistics */
name|long
name|pif_ipdus
decl_stmt|;
comment|/* PDUs received from interface */
name|long
name|pif_opdus
decl_stmt|;
comment|/* PDUs sent to interface */
name|long
name|pif_ibytes
decl_stmt|;
comment|/* Bytes received from interface */
name|long
name|pif_obytes
decl_stmt|;
comment|/* Bytes sent to interface */
name|long
name|pif_ierrors
decl_stmt|;
comment|/* Errors receiving from interface */
name|long
name|pif_oerrors
decl_stmt|;
comment|/* Errors sending to interface */
name|long
name|pif_cmderrors
decl_stmt|;
comment|/* Interface command errors */
name|caddr_t
name|pif_cardstats
decl_stmt|;
comment|/* Card specific statistics */
comment|/* Interface capabilities */
name|u_short
name|pif_maxvpi
decl_stmt|;
comment|/* Maximum VPI value supported */
name|u_short
name|pif_maxvci
decl_stmt|;
comment|/* Maximum VCI value supported */
name|u_int
name|pif_pcr
decl_stmt|;
comment|/* Peak Cell Rate */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Physical interface flags  */
end_comment

begin_define
define|#
directive|define
name|PIF_UP
value|0x01
end_define

begin_comment
comment|/* Interface is up */
end_comment

begin_define
define|#
directive|define
name|PIF_LOOPBACK
value|0x02
end_define

begin_comment
comment|/* Loopback local packets */
end_comment

begin_comment
comment|/*  * Structure defining an ATM network interface.  This structure is used as   * the hook between the standard BSD network layer interface mechanism and   * the ATM device layer.  There may be one or more network interfaces for   * each physical ATM interface.  */
end_comment

begin_struct
struct|struct
name|atm_nif
block|{
name|struct
name|ifnet
name|nif_if
decl_stmt|;
comment|/* Network interface */
name|struct
name|atm_pif
modifier|*
name|nif_pif
decl_stmt|;
comment|/* Our physical interface */
name|char
name|nif_name
index|[
name|IFNAMSIZ
index|]
decl_stmt|;
comment|/* Network interface name */
name|u_char
name|nif_sel
decl_stmt|;
comment|/* Interface's address selector */
name|struct
name|atm_nif
modifier|*
name|nif_pnext
decl_stmt|;
comment|/* Next net interface on phys i/f */
comment|/* Interface statistics (in addition to ifnet stats) */
name|long
name|nif_ibytes
decl_stmt|;
comment|/* Bytes received from interface */
name|long
name|nif_obytes
decl_stmt|;
comment|/* Bytes sent to interface */
block|}
struct|;
end_struct

begin_comment
comment|/*  * Common Device VCC Entry  *  * Contains the common information for each VCC which is opened  * through a particular device.  */
end_comment

begin_struct
struct|struct
name|cmn_vcc
block|{
name|struct
name|cmn_vcc
modifier|*
name|cv_next
decl_stmt|;
comment|/* Next in list */
name|void
modifier|*
name|cv_toku
decl_stmt|;
comment|/* Upper layer's token */
name|void
function_decl|(
modifier|*
name|cv_upper
function_decl|)
comment|/* Upper layer's interface */
parameter_list|(
name|int
parameter_list|,
name|void
modifier|*
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|Atm_connvc
modifier|*
name|cv_connvc
decl_stmt|;
comment|/* Associated connection VCC */
name|u_char
name|cv_state
decl_stmt|;
comment|/* VCC state (see below) */
name|u_char
name|cv_flags
decl_stmt|;
comment|/* VCC flags (see below) */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|cmn_vcc
name|Cmn_vcc
typedef|;
end_typedef

begin_comment
comment|/*  * VCC States  */
end_comment

begin_define
define|#
directive|define
name|CVS_FREE
value|0
end_define

begin_comment
comment|/* Not allocated */
end_comment

begin_define
define|#
directive|define
name|CVS_INST
value|1
end_define

begin_comment
comment|/* Instantiated, waiting for INIT */
end_comment

begin_define
define|#
directive|define
name|CVS_INITED
value|2
end_define

begin_comment
comment|/* Initialized, waiting for driver */
end_comment

begin_define
define|#
directive|define
name|CVS_ACTIVE
value|3
end_define

begin_comment
comment|/* Device activated by driver */
end_comment

begin_define
define|#
directive|define
name|CVS_PTERM
value|4
end_define

begin_comment
comment|/* Waiting for TERM */
end_comment

begin_define
define|#
directive|define
name|CVS_TERM
value|5
end_define

begin_comment
comment|/* Terminated */
end_comment

begin_comment
comment|/*  * VCC Flags  */
end_comment

begin_define
define|#
directive|define
name|CVF_RSVD
value|0x0f
end_define

begin_comment
comment|/* Reserved for device-specific use */
end_comment

begin_comment
comment|/*  * Common Device Unit Structure  *  * Contains the common information for a single device (adapter).  */
end_comment

begin_struct
struct|struct
name|cmn_unit
block|{
name|struct
name|atm_pif
name|cu_pif
decl_stmt|;
comment|/* Physical interface */
name|u_int
name|cu_unit
decl_stmt|;
comment|/* Local unit number */
name|u_char
name|cu_flags
decl_stmt|;
comment|/* Device flags (see below) */
name|u_int
name|cu_mtu
decl_stmt|;
comment|/* Interface MTU */
name|u_int
name|cu_open_vcc
decl_stmt|;
comment|/* Open VCC count */
name|Cmn_vcc
modifier|*
name|cu_vcc
decl_stmt|;
comment|/* List of VCC's on interface */
name|u_int
name|cu_intrpri
decl_stmt|;
comment|/* Highest unit interrupt priority */
name|int
name|cu_savepri
decl_stmt|;
comment|/* Saved priority for locking device */
name|struct
name|sp_info
modifier|*
name|cu_vcc_pool
decl_stmt|;
comment|/* Device VCC pool */
name|struct
name|sp_info
modifier|*
name|cu_nif_pool
decl_stmt|;
comment|/* Device NIF pool */
name|int
function_decl|(
modifier|*
name|cu_ioctl
function_decl|)
comment|/* Interface ioctl handler */
parameter_list|(
name|int
parameter_list|,
name|caddr_t
parameter_list|,
name|caddr_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|cu_instvcc
function_decl|)
comment|/* VCC stack instantion handler */
parameter_list|(
name|struct
name|cmn_unit
modifier|*
parameter_list|,
name|Cmn_vcc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|cu_openvcc
function_decl|)
comment|/* Open VCC handler */
parameter_list|(
name|struct
name|cmn_unit
modifier|*
parameter_list|,
name|Cmn_vcc
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|cu_closevcc
function_decl|)
comment|/* Close VCC handler */
parameter_list|(
name|struct
name|cmn_unit
modifier|*
parameter_list|,
name|Cmn_vcc
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|cu_output
function_decl|)
comment|/* Data output handler */
parameter_list|(
name|struct
name|cmn_unit
modifier|*
parameter_list|,
name|Cmn_vcc
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
name|Atm_config
name|cu_config
decl_stmt|;
comment|/* Device configuration data */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|cmn_unit
name|Cmn_unit
typedef|;
end_typedef

begin_comment
comment|/*  * Device flags  */
end_comment

begin_define
define|#
directive|define
name|CUF_REGISTER
value|0x01
end_define

begin_comment
comment|/* Device is registered */
end_comment

begin_define
define|#
directive|define
name|CUF_INITED
value|0x02
end_define

begin_comment
comment|/* Device is initialized */
end_comment

begin_comment
comment|/*  * Structure used to define a network convergence module and its associated  * entry points.  A convergence module is used to provide the interface  * translations necessary between the ATM system and the BSD network layer  * interface mechanism.  There will be one network convergence module for  * each protocol address family supporting ATM connections.  */
end_comment

begin_struct
struct|struct
name|atm_ncm
block|{
name|struct
name|atm_ncm
modifier|*
name|ncm_next
decl_stmt|;
comment|/* Next in registry list */
name|u_short
name|ncm_family
decl_stmt|;
comment|/* Protocol family */
comment|/* Exported functions */
name|int
function_decl|(
modifier|*
name|ncm_ifoutput
function_decl|)
comment|/* Interface if_output handler */
parameter_list|(
name|struct
name|ifnet
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ncm_stat
function_decl|)
comment|/* Network i/f status handler */
parameter_list|(
name|int
parameter_list|,
name|struct
name|atm_nif
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * ncm_stat() commands  */
end_comment

begin_define
define|#
directive|define
name|NCM_ATTACH
value|1
end_define

begin_comment
comment|/* Attaching a new net i/f */
end_comment

begin_define
define|#
directive|define
name|NCM_DETACH
value|2
end_define

begin_comment
comment|/* Detaching a current net i/f */
end_comment

begin_define
define|#
directive|define
name|NCM_SETADDR
value|3
end_define

begin_comment
comment|/* Net i/f address change */
end_comment

begin_define
define|#
directive|define
name|NCM_SIGATTACH
value|4
end_define

begin_comment
comment|/* Attaching a signalling manager */
end_comment

begin_define
define|#
directive|define
name|NCM_SIGDETACH
value|5
end_define

begin_comment
comment|/* Detaching a signalling manager */
end_comment

begin_comment
comment|/*  * atm_dev_alloc() parameters  */
end_comment

begin_define
define|#
directive|define
name|ATM_DEV_NONCACHE
value|1
end_define

begin_comment
comment|/* Allocate non-cacheable memory */
end_comment

begin_comment
comment|/*  * atm_dev_compress() buffer allocation sizes  */
end_comment

begin_define
define|#
directive|define
name|ATM_DEV_CMPR_LG
value|MCLBYTES
end_define

begin_comment
comment|/* Size of large buffers */
end_comment

begin_define
define|#
directive|define
name|ATM_DEV_CMPR_SM
value|MLEN
end_define

begin_comment
comment|/* Size of small buffers */
end_comment

begin_comment
comment|/*  * Macros to manage DMA addresses  */
end_comment

begin_define
define|#
directive|define
name|DMA_INIT
parameter_list|()
end_define

begin_define
define|#
directive|define
name|DMA_GET_ADDR
parameter_list|(
name|addr
parameter_list|,
name|len
parameter_list|,
name|align
parameter_list|,
name|flags
parameter_list|)
value|((void *)vtophys(addr))
end_define

begin_define
define|#
directive|define
name|DMA_FREE_ADDR
parameter_list|(
name|addr
parameter_list|,
name|daddr
parameter_list|,
name|len
parameter_list|,
name|flags
parameter_list|)
end_define

begin_define
define|#
directive|define
name|DMA_RELEASE
parameter_list|()
end_define

begin_comment
comment|/*  * Macros to lock out device interrupts  */
end_comment

begin_define
define|#
directive|define
name|DEVICE_LOCK
parameter_list|(
name|u
parameter_list|)
value|((u)->cu_savepri = splimp())
end_define

begin_define
define|#
directive|define
name|DEVICE_UNLOCK
parameter_list|(
name|u
parameter_list|)
value|((void) splx((u)->cu_savepri))
end_define

begin_comment
comment|/*  * SBus defines  */
end_comment

begin_if
if|#
directive|if
name|defined
argument_list|(
name|sun
argument_list|)
end_if

begin_define
define|#
directive|define
name|SBUS_BURST32
value|0x20
end_define

begin_comment
comment|/* Device supports 32-byte bursts */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Macro to schedule the ATM interrupt queue handler  */
end_comment

begin_typedef
typedef|typedef
name|void
function_decl|(
name|atm_intr_t
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|,
name|KBuffer
modifier|*
parameter_list|)
function_decl|;
end_typedef

begin_comment
comment|/* Callback function type */
end_comment

begin_typedef
typedef|typedef
name|atm_intr_t
modifier|*
name|atm_intr_func_t
typedef|;
end_typedef

begin_comment
comment|/* Pointer to callback function */
end_comment

begin_define
define|#
directive|define
name|SCHED_ATM
value|schednetisr(NETISR_ATM)
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
comment|/* _NETATM_ATM_IF_H */
end_comment

end_unit

