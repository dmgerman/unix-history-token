begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2002, 2003 Christian Bucari, Prosum   * Copyright (c) 2002, 2003 Vincent Jardin, Xavier Heiny, 6WIND  * Copyright (c) 2000, 2001 Richard Hodges and Matriplex, inc.  * Copyright (c) 1996, 1997, 1998, 1999 Mark Tinguely  *  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *	notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *	notice, this list of conditions and the following disclaimer in the  *	documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *	must display the following acknowledgement:  *	This product includes software developed by Prosum, 6wind and   *  Matriplex, inc  * 4. The name of the authors may not be used to endorse or promote products   *	derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  * DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT,  * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,  * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN  * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  * POSSIBILITY OF SUCH DAMAGE.  *  ******************************************************************************/
end_comment

begin_comment
comment|/* 14-02-2003 */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_PROATM_H
end_ifndef

begin_define
define|#
directive|define
name|_PROATM_H
end_define

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|MAXCARDS
value|10
end_define

begin_comment
comment|/* set to impossibly high */
end_comment

begin_include
include|#
directive|include
file|<sys/param.h>
end_include

begin_include
include|#
directive|include
file|<sys/systm.h>
end_include

begin_include
include|#
directive|include
file|<sys/conf.h>
end_include

begin_include
include|#
directive|include
file|<sys/mbuf.h>
end_include

begin_include
include|#
directive|include
file|<sys/protosw.h>
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
file|"opt_atm.h"
end_include

begin_include
include|#
directive|include
file|<sys/sockio.h>
end_include

begin_include
include|#
directive|include
file|<sys/errno.h>
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
file|<sys/proc.h>
end_include

begin_include
include|#
directive|include
file|<sys/signalvar.h>
end_include

begin_include
include|#
directive|include
file|<sys/mman.h>
end_include

begin_include
include|#
directive|include
file|<machine/clock.h>
end_include

begin_include
include|#
directive|include
file|<machine/cpu.h>
end_include

begin_comment
comment|/* bootverbose */
end_comment

begin_include
include|#
directive|include
file|<sys/bus.h>
end_include

begin_include
include|#
directive|include
file|<machine/bus.h>
end_include

begin_include
include|#
directive|include
file|<sys/rman.h>
end_include

begin_include
include|#
directive|include
file|<machine/resource.h>
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

begin_if
if|#
directive|if
name|MCLBYTES
operator|!=
literal|2048
end_if

begin_error
error|#
directive|error
literal|"This proatm driver depends on 2048 byte mbuf clusters."
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|INET
end_ifdef

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_systm.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in_var.h>
end_include

begin_include
include|#
directive|include
file|<netinet/ip.h>
end_include

begin_include
include|#
directive|include
file|<netinet/if_ether.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<vm/vm.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_kern.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_param.h>
end_include

begin_include
include|#
directive|include
file|<vm/pmap.h>
end_include

begin_include
include|#
directive|include
file|<vm/vm_extern.h>
end_include

begin_include
include|#
directive|include
file|<pci.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcivar.h>
end_include

begin_include
include|#
directive|include
file|<pci/pcireg.h>
end_include

begin_include
include|#
directive|include
file|<machine/stdarg.h>
end_include

begin_include
include|#
directive|include
file|<netatm/kern_include.h>
end_include

begin_comment
comment|/* HARP-specific definitions *************************************************/
end_comment

begin_define
define|#
directive|define
name|PROATM_DEV_NAME
value|"proatm"
end_define

begin_define
define|#
directive|define
name|PROATM_IFF_MTU
value|9188
end_define

begin_define
define|#
directive|define
name|PROATM_MAX_VCI
value|255
end_define

begin_comment
comment|/* 0 - 255 */
end_comment

begin_define
define|#
directive|define
name|PROATM_MAX_VPI
value|3
end_define

begin_comment
comment|/*  * Device VCC Entry  *  * Contains the common and PROATM-specific information for each VCC  * which is opened through a PROATM device.  */
end_comment

begin_struct
struct|struct
name|nproatm_vcc
block|{
name|struct
name|cmn_vcc
name|iv_cmn
decl_stmt|;
comment|/* Common VCC stuff */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|nproatm_vcc
name|Idt_vcc
typedef|;
end_typedef

begin_define
define|#
directive|define
name|iv_next
value|iv_cmn.cv_next
end_define

begin_define
define|#
directive|define
name|iv_toku
value|iv_cmn.cv_toku
end_define

begin_define
define|#
directive|define
name|iv_upper
value|iv_cmn.cv_upper
end_define

begin_define
define|#
directive|define
name|iv_vccb
value|iv_cmn.cv_connvc
end_define

begin_comment
comment|/* HARP 3.0 */
end_comment

begin_define
define|#
directive|define
name|iv_state
value|iv_cmn.cv_state
end_define

begin_define
define|#
directive|define
name|iu_pif
value|iu_cmn.cu_pif
end_define

begin_define
define|#
directive|define
name|iu_unit
value|iu_cmn.cu_unit
end_define

begin_define
define|#
directive|define
name|iu_flags
value|iu_cmn.cu_flags
end_define

begin_define
define|#
directive|define
name|iu_mtu
value|iu_cmn.cu_mtu
end_define

begin_define
define|#
directive|define
name|iu_open_vcc
value|iu_cmn.cu_open_vcc
end_define

begin_define
define|#
directive|define
name|iu_instvcc
value|iu_cmn.cu_instvcc
end_define

begin_comment
comment|/* HARP 3.0 */
end_comment

begin_define
define|#
directive|define
name|iu_vcc
value|iu_cmn.cu_vcc
end_define

begin_define
define|#
directive|define
name|iu_vcc_pool
value|iu_cmn.cu_vcc_pool
end_define

begin_define
define|#
directive|define
name|iu_nif_pool
value|iu_cmn.cu_nif_pool
end_define

begin_define
define|#
directive|define
name|iu_ioctl
value|iu_cmn.cu_ioctl
end_define

begin_define
define|#
directive|define
name|iu_openvcc
value|iu_cmn.cu_openvcc
end_define

begin_define
define|#
directive|define
name|iu_closevcc
value|iu_cmn.cu_closevcc
end_define

begin_define
define|#
directive|define
name|iu_output
value|iu_cmn.cu_output
end_define

begin_define
define|#
directive|define
name|iu_config
value|iu_cmn.cu_config
end_define

begin_comment
comment|/* fixbuf memory map *******************************************************************  *  *  *  0000 - 1fff:  TSQ  Transmit status queue 1024 entries *  8 bytes each  *  2000 - 3fff:  RSQ  Receive status queue,  512 entries * 16 bytes each  *  */
end_comment

begin_define
define|#
directive|define
name|PROATM_TSQ_OFFSET
value|0x0000
end_define

begin_define
define|#
directive|define
name|PROATM_RSQ_OFFSET
value|0x2000
end_define

begin_define
define|#
directive|define
name|PROATM_TSQ_SIZE
value|0x2000
end_define

begin_define
define|#
directive|define
name|PROATM_RSQ_SIZE
value|0x2000
end_define

begin_define
define|#
directive|define
name|IDT_SCQ_ENTRIES
value|64
end_define

begin_define
define|#
directive|define
name|IDT_SCQ_SIZE
value|(16*IDT_SCQ_ENTRIES)
end_define

begin_comment
comment|/* some #define for driver structures in host memory ************************/
end_comment

begin_comment
comment|/* TSQ entry */
end_comment

begin_define
define|#
directive|define
name|IDT_TSI_EMPTY
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IDT_TSI_TIMESTAMP_MASK
value|0x00FFFFFF
end_define

begin_define
define|#
directive|define
name|IDT_TSI_TYPE_MASK
value|0x60000000
end_define

begin_define
define|#
directive|define
name|IDT_TSI_TAG_MASK
value|(0x1F<<24)
end_define

begin_define
define|#
directive|define
name|IDT_TSI_TYPE_TMROF
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IDT_TSI_TYPE_TSR
value|0x20000000
end_define

begin_define
define|#
directive|define
name|IDT_TSI_TYPE_IDLE
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IDT_TSI_TYPE_TBD
value|0x60000000
end_define

begin_comment
comment|/* RSQ entry */
end_comment

begin_define
define|#
directive|define
name|IDT_RSQE_TYPE
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_VALID
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_POOL
value|0x00030000
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_BUFASSIGN
value|0x00008000
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_NZGFC
value|0x00004000
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_EOPDU
value|0x00002000
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_CBUF
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_CONGESTION
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_CLP
value|0x00000400
end_define

begin_define
define|#
directive|define
name|IDT_RSQE_CRCERR
value|0x00000200
end_define

begin_comment
comment|/*TBD */
end_comment

begin_define
define|#
directive|define
name|IDT_TSR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IDT_TBD_EOPDU
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IDT_TBD_AAL0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IDT_TBD_AAL34
value|0x04000000
end_define

begin_define
define|#
directive|define
name|IDT_TBD_AAL5
value|0x08000000
end_define

begin_define
define|#
directive|define
name|IDT_TBD_OAM
value|0x10000000
end_define

begin_define
define|#
directive|define
name|IDT_TBD_TSIF
value|0x20000000
end_define

begin_define
define|#
directive|define
name|IDT_TBD_GTSI
value|0x02000000
end_define

begin_define
define|#
directive|define
name|IDT_TBD_LOW_PRIORITY
value|0x00000001
end_define

begin_define
define|#
directive|define
name|PROATM_CLOSE_TAG
value|0x15
end_define

begin_define
define|#
directive|define
name|PROATM_PDU_TAG
value|0x0a
end_define

begin_define
define|#
directive|define
name|PROATM_CLOSE_CONNECTION
value|((void*)0x55)
end_define

begin_define
define|#
directive|define
name|IDT_TBD_VPI_MASK
value|0x0FF00000
end_define

begin_define
define|#
directive|define
name|IDT_TBD_VCI_MASK
value|0x000FFFF0
end_define

begin_define
define|#
directive|define
name|IDT_TBD_VC_MASK
value|(IDT_TBD_VPI_MASK | IDT_TBD_VCI_MASK)
end_define

begin_comment
comment|/* PROATM SRAM constants ******************************************/
end_comment

begin_comment
comment|/* TCT size set by CFG reg(b16-17), 8-words entries */
end_comment

begin_comment
comment|/* RCT size set by CFG reg(b16-17) 4-words entries */
end_comment

begin_comment
comment|/* RFBQ0 and RFBQ1 */
end_comment

begin_define
define|#
directive|define
name|PROATM_RFBQ_SIZE
value|0x400
end_define

begin_comment
comment|/* DTST size set by ABRSTD (2x2Kword-tables) (and b0-11 null) */
end_comment

begin_define
define|#
directive|define
name|PROATM_ABRSTD_SIZE
value|(2<<24)
end_define

begin_define
define|#
directive|define
name|PROATM_DTST_SIZE
value|4096
end_define

begin_comment
comment|/* TST */
end_comment

begin_define
define|#
directive|define
name|PROATM_TST_MAX
value|4096
end_define

begin_define
define|#
directive|define
name|PROATM_TST_RESERVED
value|340
end_define

begin_comment
comment|/* N. entries reserved for UBR/ABR/VBR */
end_comment

begin_comment
comment|/* SDCs (12 words, ==>must be aligned on 4-word boundary)*/
end_comment

begin_define
define|#
directive|define
name|IDT_STRUCT_SCD_SIZE
value|12
end_define

begin_comment
comment|/* 12 words */
end_comment

begin_comment
comment|/* RXFIFO size set by RXFD (4K words) (and b0-13 null) */
end_comment

begin_define
define|#
directive|define
name|PROATM_RXFIFO_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|PROATM_RXFD_SIZE
value|(3<<24)
end_define

begin_comment
comment|/* You may change these **********************************************************/
end_comment

begin_define
define|#
directive|define
name|PROATM_LBUFS
value|200
end_define

begin_comment
comment|/* default number of 2k buffers. Must be comprised */
end_comment

begin_comment
comment|/* between 70 and 510 */
end_comment

begin_define
define|#
directive|define
name|PROATM_SBUFS
value|200
end_define

begin_comment
comment|/* default number of 96-byte buffers. Must be */
end_comment

begin_comment
comment|/* comprised between 70 and 510 */
end_comment

begin_define
define|#
directive|define
name|PROATM_RSQSIZE
value|8192
end_define

begin_comment
comment|/* 2048, 4096 or 8192 */
end_comment

begin_define
define|#
directive|define
name|PROATM_VPIBITS
value|2
end_define

begin_comment
comment|/* 0, 1, 2, or 8 */
end_comment

begin_define
define|#
directive|define
name|RCQ_SUPPORT
end_define

begin_comment
comment|/* Enable Raw Cell support */
end_comment

begin_comment
comment|/*   	VPI_BASE sets the bottom of the VP range. (normaly 0)  			 It is a multiple of the number of VP's the card is able to manage 			 For example if PROATM_VPIBITS = 2, VPI_BASE may be 0, 4, 8, 12, etc. 			 Set it to 0 if you don't know what to do.   	VCI_BASE sets the bottom of the VC range. (normaly 0)   			 It is a multiple of the number of VC's the card is able to manage. 			 For example if the card has 128 KB memory and PROATM_VPIBITS = 2 			 then the number of VCI bits is 8 and the number of VCs is 256, 			 thus VPI_BASE may be 0, 256, 512, etc.   			 Set it to 0 if you don't know what to do.  	The VPM register value is dynamicaly computed by using VCI_BASE, VPI_BASE,  	PROATM_VPIBITS and the memory size */
end_comment

begin_define
define|#
directive|define
name|VCI_BASE
value|0
end_define

begin_define
define|#
directive|define
name|VPI_BASE
value|0
end_define

begin_comment
comment|/* define for use of clock recovered from receive signal as transmission clock    the  local oscillator is used by default */
end_comment

begin_undef
undef|#
directive|undef
name|PROATM_LOOPT
end_undef

begin_comment
comment|/* define for full SDH mode    follows the SONET specifications by default  */
end_comment

begin_undef
undef|#
directive|undef
name|PROATM_FULL_SDH
end_undef

begin_comment
comment|/* IDT77252 Registers *************************************************************/
end_comment

begin_define
define|#
directive|define
name|REGDR0
value|0x00
end_define

begin_comment
comment|/* Data Register 0 R/W*/
end_comment

begin_define
define|#
directive|define
name|REGDR1
value|0x04
end_define

begin_comment
comment|/* Data Register 1 W */
end_comment

begin_define
define|#
directive|define
name|REGDR2
value|0x08
end_define

begin_comment
comment|/* Data Register 2 W */
end_comment

begin_define
define|#
directive|define
name|REGDR3
value|0x0C
end_define

begin_comment
comment|/* Data Register 3 W */
end_comment

begin_define
define|#
directive|define
name|REGCMD
value|0x10
end_define

begin_comment
comment|/* command          w */
end_comment

begin_define
define|#
directive|define
name|REGCFG
value|0x14
end_define

begin_comment
comment|/* configuration  r/w */
end_comment

begin_define
define|#
directive|define
name|REGSTAT
value|0x18
end_define

begin_comment
comment|/* status         r/w */
end_comment

begin_define
define|#
directive|define
name|REGRSQB
value|0x1c
end_define

begin_comment
comment|/* RSQ base         w */
end_comment

begin_define
define|#
directive|define
name|REGRSQT
value|0x20
end_define

begin_comment
comment|/* RSQ tail         r */
end_comment

begin_define
define|#
directive|define
name|REGRSQH
value|0x24
end_define

begin_comment
comment|/* RSQ head         w */
end_comment

begin_define
define|#
directive|define
name|REGCDC
value|0x28
end_define

begin_comment
comment|/* cell drop cnt  r/c */
end_comment

begin_define
define|#
directive|define
name|REGVPEC
value|0x2c
end_define

begin_comment
comment|/* vci/vpi er cnt r/c */
end_comment

begin_define
define|#
directive|define
name|REGICC
value|0x30
end_define

begin_comment
comment|/* invalid cell   r/c */
end_comment

begin_define
define|#
directive|define
name|REGRAWT
value|0x34
end_define

begin_comment
comment|/* raw cell tail    r */
end_comment

begin_define
define|#
directive|define
name|REGTMR
value|0x38
end_define

begin_comment
comment|/* timer            r */
end_comment

begin_define
define|#
directive|define
name|REGTSTB
value|0x3c
end_define

begin_comment
comment|/* TST base       r/w */
end_comment

begin_define
define|#
directive|define
name|REGTSQB
value|0x40
end_define

begin_comment
comment|/* TSQ base         w */
end_comment

begin_define
define|#
directive|define
name|REGTSQT
value|0x44
end_define

begin_comment
comment|/* TSQ tail         r */
end_comment

begin_define
define|#
directive|define
name|REGTSQH
value|0x48
end_define

begin_comment
comment|/* TSQ head         w */
end_comment

begin_define
define|#
directive|define
name|REGGP
value|0x4c
end_define

begin_comment
comment|/* general purp   r/w */
end_comment

begin_define
define|#
directive|define
name|REGVMSK
value|0x50
end_define

begin_comment
comment|/* vci/vpi mask     w */
end_comment

begin_define
define|#
directive|define
name|REGRXFD
value|0x54
end_define

begin_comment
comment|/* Receive FIFO descriptor */
end_comment

begin_define
define|#
directive|define
name|REGRXFT
value|0x58
end_define

begin_comment
comment|/* Receive FIFO Tail */
end_comment

begin_define
define|#
directive|define
name|REGRXFH
value|0x5C
end_define

begin_comment
comment|/* Receive FIFO  Head */
end_comment

begin_define
define|#
directive|define
name|REGRAWHND
value|0x60
end_define

begin_comment
comment|/* Raw Cell Handle register */
end_comment

begin_define
define|#
directive|define
name|REGRXSTAT
value|0x64
end_define

begin_comment
comment|/* Receive Conn. State register */
end_comment

begin_define
define|#
directive|define
name|REGABRSTD
value|0x68
end_define

begin_comment
comment|/* ABR Schedule TableDescriptor */
end_comment

begin_define
define|#
directive|define
name|REGABRRQ
value|0x6C
end_define

begin_comment
comment|/* ABR Ready Queue Pointer register */
end_comment

begin_define
define|#
directive|define
name|REGVBRRQ
value|0x70
end_define

begin_comment
comment|/* VBR Ready Queue Pointer register */
end_comment

begin_define
define|#
directive|define
name|REGRTBL
value|0x74
end_define

begin_comment
comment|/* Rate Table Descriptor */
end_comment

begin_define
define|#
directive|define
name|REGMXDFCT
value|0x78
end_define

begin_comment
comment|/* Maximum Deficit Count register */
end_comment

begin_define
define|#
directive|define
name|REGTXSTAT
value|0x7C
end_define

begin_comment
comment|/* Transmit Conn. State register */
end_comment

begin_define
define|#
directive|define
name|REGTCMDQ
value|0x80
end_define

begin_comment
comment|/* Transmit Command Queue register */
end_comment

begin_define
define|#
directive|define
name|REGIRCP
value|0x84
end_define

begin_comment
comment|/* Inactive Receive Conn. Pointer */
end_comment

begin_define
define|#
directive|define
name|REGFBQP0
value|0x88
end_define

begin_comment
comment|/* Free Buffer Queue Pointer Register 0 */
end_comment

begin_define
define|#
directive|define
name|REGFBQP1
value|0x8C
end_define

begin_comment
comment|/* Free Buffer Queue Pointer Register 1 */
end_comment

begin_define
define|#
directive|define
name|REGFBQP2
value|0x90
end_define

begin_comment
comment|/* Free Buffer Queue Pointer Register 2 */
end_comment

begin_define
define|#
directive|define
name|REGFBQP3
value|0x94
end_define

begin_comment
comment|/* Free Buffer Queue Pointer Register 3 */
end_comment

begin_define
define|#
directive|define
name|REGFBQS0
value|0x98
end_define

begin_comment
comment|/* Free Buffer Queue Size Register 0 */
end_comment

begin_define
define|#
directive|define
name|REGFBQS1
value|0x9C
end_define

begin_comment
comment|/* Free Buffer Queue Size Register 1 */
end_comment

begin_define
define|#
directive|define
name|REGFBQS2
value|0xA0
end_define

begin_comment
comment|/* Free Buffer Queue Size Register 2 */
end_comment

begin_define
define|#
directive|define
name|REGFBQS3
value|0xA4
end_define

begin_comment
comment|/* Free Buffer Queue Size Register 3 */
end_comment

begin_define
define|#
directive|define
name|REGFBQWP0
value|0xA8
end_define

begin_comment
comment|/* Free Buffer Queue Write Pointer Register 0 */
end_comment

begin_define
define|#
directive|define
name|REGFBQWP1
value|0xAC
end_define

begin_comment
comment|/* Free Buffer Queue Write Pointer Register 1 */
end_comment

begin_define
define|#
directive|define
name|REGFBQWP2
value|0xB0
end_define

begin_comment
comment|/* Free Buffer Queue Write Pointer Register 2 */
end_comment

begin_define
define|#
directive|define
name|REGFBQWP3
value|0xB4
end_define

begin_comment
comment|/* Free Buffer Queue Write Pointer Register 3 */
end_comment

begin_define
define|#
directive|define
name|REGNOW
value|0xB8
end_define

begin_comment
comment|/* Current Transmit Schedule Table Address */
end_comment

begin_comment
comment|/* Commands issued to the COMMAND register **************************************/
end_comment

begin_define
define|#
directive|define
name|IDT_CMD_NO_OPERATION
value|(0<<28)
end_define

begin_define
define|#
directive|define
name|IDT_CMD_OPEN_CONNECTION
value|((2<<28) | (1<<19))
end_define

begin_define
define|#
directive|define
name|IDT_CMD_CLOSE_CONNECTION
value|(2<<28)
end_define

begin_define
define|#
directive|define
name|IDT_CMD_WRITE_SRAM
value|(4<<28)
end_define

begin_define
define|#
directive|define
name|IDT_CMD_READ_SRAM
value|(5<<28)
end_define

begin_define
define|#
directive|define
name|IDT_CMD_WRITE_FREEBUFQ
value|(6<<28)
end_define

begin_define
define|#
directive|define
name|IDT_CMD_READ_UTILITY_CS0
value|((8<<28) | (1<<8))
end_define

begin_define
define|#
directive|define
name|IDT_CMD_WRITE_UTILITY_CS0
value|((9<<28) | (1<<8))
end_define

begin_comment
comment|/* Commands issued to TCMDQ register ********************************************/
end_comment

begin_define
define|#
directive|define
name|IDT_TCMDQ_START
value|(1<<24)
end_define

begin_define
define|#
directive|define
name|IDT_TCMDQ_ULACR
value|(2<<24)
end_define

begin_define
define|#
directive|define
name|IDT_TCMDQ_START_ULACR
value|(3<<24)
end_define

begin_define
define|#
directive|define
name|IDT_TCMDQ_UPD_INITER
value|(4<<24)
end_define

begin_define
define|#
directive|define
name|IDT_TCMDQ_HALT
value|(5<<24)
end_define

begin_comment
comment|/* STATUS Register bits ******************************************************/
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_FRAC3_MASK
value|0xF0000000
end_define

begin_define
define|#
directive|define
name|IDT_STAT_FRAC2_MASK
value|0x0F000000
end_define

begin_define
define|#
directive|define
name|IDT_STAT_FRAC1_MASK
value|0x00F00000
end_define

begin_define
define|#
directive|define
name|IDT_STAT_FRAC0_MASK
value|0x000F0000
end_define

begin_define
define|#
directive|define
name|IDT_STAT_TSIF
value|0x00008000
end_define

begin_comment
comment|/* Transmit Status Queue Indicator */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_TXICP
value|0x00004000
end_define

begin_comment
comment|/* Transmit Incomplete PDU */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_TSQF
value|0x00001000
end_define

begin_comment
comment|/* Transmit Status Queue Full */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_TMROF
value|0x00000800
end_define

begin_comment
comment|/* Timer Overflow */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_PHYI
value|0x00000400
end_define

begin_comment
comment|/* PHY Device Interrupt */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_CMDBZ
value|0x00000200
end_define

begin_comment
comment|/* Command Busy */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_FBQ3A
value|0x00000100
end_define

begin_comment
comment|/* Free Buffer Queue Attention */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_FBQ2A
value|0x00000080
end_define

begin_comment
comment|/* Free Buffer Queue Attention */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_RSQF
value|0x00000040
end_define

begin_comment
comment|/* Receive Status Queue Full */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_EOPDU
value|0x00000020
end_define

begin_comment
comment|/* End of PDU */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_RAWCF
value|0x00000010
end_define

begin_comment
comment|/* Raw Cell Flag */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_FBQ1A
value|0x00000008
end_define

begin_comment
comment|/* Free Buffer Queue Attention */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_FBQ0A
value|0x00000004
end_define

begin_comment
comment|/* Free Buffer Queue Attention */
end_comment

begin_define
define|#
directive|define
name|IDT_STAT_RSQAF
value|0x00000002
end_define

begin_comment
comment|/* Receive Status Queue Almost Full */
end_comment

begin_comment
comment|/* Interrupt flags we must take into account */
end_comment

begin_define
define|#
directive|define
name|INT_FLAGS
value|( IDT_STAT_TSQF  |   \                     IDT_STAT_RSQAF |   \                     IDT_STAT_RAWCF |   \                     IDT_STAT_EOPDU |   \                     IDT_STAT_TMROF |   \                     IDT_STAT_TXICP |   \                     IDT_STAT_TSIF  |   \                     IDT_STAT_FBQ0A |   \                     IDT_STAT_FBQ1A |   \                     IDT_STAT_PHYI )
end_define

begin_comment
comment|/* Interrupt flags that are cleared by writing 1 */
end_comment

begin_define
define|#
directive|define
name|CLEAR_FLAGS
value|( IDT_STAT_TSIF | IDT_STAT_TXICP | IDT_STAT_TMROF \                         | IDT_STAT_PHYI | IDT_STAT_EOPDU | IDT_STAT_RAWCF)
end_define

begin_comment
comment|/* CONFIGURATION Register Bits *************************************************/
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_SWRST
value|0x80000000
end_define

begin_comment
comment|/* Software Reset */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_LOOP
value|0x40000000
end_define

begin_comment
comment|/* Enable internal loop back */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_RXPATH
value|0x20000000
end_define

begin_comment
comment|/* Receive Path Enable */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_IDLECLP
value|0x10000000
end_define

begin_comment
comment|/* CLP bit of Null Cells */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_TFIFOSIZE_MASK
value|0x0C000000
end_define

begin_comment
comment|/* Specifies size of tx FIFO */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_RSQSIZE_MASK
value|0x00C00000
end_define

begin_comment
comment|/* Receive Status Queue Size */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_ICACCEPT
value|0x00200000
end_define

begin_comment
comment|/* Invalid Cell Accept */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_IGNOREGFC
value|0x00100000
end_define

begin_comment
comment|/* Ignore General Flow Control */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_VPIBITS_MASK
value|0x000C0000
end_define

begin_comment
comment|/* VPI/VCI Bits Size Select */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_RCTSIZE_MASK
value|0x00030000
end_define

begin_comment
comment|/* Receive Connection Table Size */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_VCERRACCEPT
value|0x00008000
end_define

begin_comment
comment|/* VPI/VCI Error Cell Accept */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_RXINT_MASK
value|0x00007000
end_define

begin_comment
comment|/* End of Receive PDU Interrupt                                                Handling */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_RAWIE
value|0x00000800
end_define

begin_comment
comment|/* Raw Cell Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_RSQAFIE
value|0x00000400
end_define

begin_comment
comment|/* Receive Queue Almost Full                                                Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_CACHE
value|0x00000100
end_define

begin_comment
comment|/* Cache */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_TMRROIE
value|0x00000080
end_define

begin_comment
comment|/* Timer Roll Over Interrupt                                                Enable */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_FBIE
value|0x00000040
end_define

begin_comment
comment|/* Free Buffer Queue Int Enable */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_TXEN
value|0x00000020
end_define

begin_comment
comment|/* Transmit Operation Enable */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_TXIE
value|0x00000010
end_define

begin_comment
comment|/* Transmit Status Interrupt                                                Enable */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_TXURIE
value|0x00000008
end_define

begin_comment
comment|/* Transmit Under-run Interrupt                                                Enable */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_UMODE
value|0x00000004
end_define

begin_comment
comment|/* Utopia Mode (cell/byte) Select */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_TSQFIE
value|0x00000002
end_define

begin_comment
comment|/* Transmit Status Queue Full                                                Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_PHYIE
value|0x00000001
end_define

begin_comment
comment|/* PHY Interrupt Enable */
end_comment

begin_define
define|#
directive|define
name|IDT_CFG_RSQSIZE_2048
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IDT_CFG_RSQSIZE_4096
value|0x00400000
end_define

begin_define
define|#
directive|define
name|IDT_CFG_RSQSIZE_8192
value|0x00800000
end_define

begin_define
define|#
directive|define
name|IDT_CFG_VPIBITS_0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IDT_CFG_VPIBITS_1
value|0x00040000
end_define

begin_define
define|#
directive|define
name|IDT_CFG_VPIBITS_2
value|0x00080000
end_define

begin_define
define|#
directive|define
name|IDT_CFG_VPIBITS_8
value|0x000C0000
end_define

begin_define
define|#
directive|define
name|IDT_CFG_RCTSIZE_1024_ENTRIES
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IDT_CFG_RCTSIZE_4096_ENTRIES
value|0x00010000
end_define

begin_define
define|#
directive|define
name|IDT_CFG_RCTSIZE_16384_ENTRIES
value|0x00020000
end_define

begin_define
define|#
directive|define
name|IDT_CFG_RCTSIZE_512_ENTRIES
value|0x00030000
end_define

begin_define
define|#
directive|define
name|IDT_CFG_RXINT_NOINT
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IDT_CFG_RXINT_NODELAY
value|0x00001000
end_define

begin_define
define|#
directive|define
name|IDT_CFG_RXINT_2800CLK
value|0x00002000
end_define

begin_define
define|#
directive|define
name|IDT_CFG_RXINT_4F00CLK
value|0x00003000
end_define

begin_define
define|#
directive|define
name|IDT_CFG_RXINT_7400CLK
value|0x00004000
end_define

begin_comment
comment|/* GP Register Bits *************************************************/
end_comment

begin_define
define|#
directive|define
name|IDT_GP_EECLK
value|(1<<2)
end_define

begin_define
define|#
directive|define
name|IDT_GP_EECS
value|(1<<1)
end_define

begin_define
define|#
directive|define
name|IDT_GP_EEDO
value|1
end_define

begin_define
define|#
directive|define
name|IDT_GP_EEDI
value|(1<<16)
end_define

begin_comment
comment|/* NICStAR structures located in local SRAM ***********************************/
end_comment

begin_comment
comment|/* TCT - Transmit Connection Table  *  * Written by both the NICStAR and the device driver.  */
end_comment

begin_comment
comment|/* number of 32-bit word*/
end_comment

begin_define
define|#
directive|define
name|IDT_TCT_ENTRY_SIZE
value|8
end_define

begin_comment
comment|/* word 1 of TCTE */
end_comment

begin_define
define|#
directive|define
name|IDT_TCTE_TYPE_MASK
value|0xC0000000
end_define

begin_define
define|#
directive|define
name|IDT_TCTE_TYPE_CBR
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IDT_TCTE_TYPE_ABR
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IDT_TCTE_TYPE_VBR
value|0x40000000
end_define

begin_define
define|#
directive|define
name|IDT_TCTE_TYPE_UBR
value|0x00000000
end_define

begin_comment
comment|/* word 2 of TCTE */
end_comment

begin_define
define|#
directive|define
name|IDT_TCTE_TSIF
value|(1<<14)
end_define

begin_comment
comment|/* word 4 of TCTE */
end_comment

begin_define
define|#
directive|define
name|IDT_TCTE_HALT
value|0x80000000
end_define

begin_define
define|#
directive|define
name|IDT_TCTE_IDLE
value|0x40000000
end_define

begin_comment
comment|/* word 8 of UBR or CBR TCTE */
end_comment

begin_define
define|#
directive|define
name|IDT_TCTE_UBR_EN
value|0x80000000
end_define

begin_comment
comment|/* RCT - Receive Connection Table  *  * Written by both the NICStAR and the device driver.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|idt_rcte
block|{
name|u_int32_t
name|word_1
decl_stmt|;
name|u_int32_t
name|buffer_handle
decl_stmt|;
name|u_int32_t
name|dma_address
decl_stmt|;
name|u_int32_t
name|aal5_crc32
decl_stmt|;
block|}
name|idt_rcte
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IDT_RCTE_INACTLIM
value|0xE0000000
end_define

begin_define
define|#
directive|define
name|IDT_RCTE_INACTCOUNT
value|0x1C000000
end_define

begin_define
define|#
directive|define
name|IDT_RCTE_CIVC
value|0x00800000
end_define

begin_define
define|#
directive|define
name|IDT_RCTE_FBP
value|0x00600000
end_define

begin_define
define|#
directive|define
name|IDT_RCTE_NZGFC
value|0x00100000
end_define

begin_define
define|#
directive|define
name|IDT_RCTE_CONNECTOPEN
value|0x00080000
end_define

begin_define
define|#
directive|define
name|IDT_RCTE_AALMASK
value|0x00070000
end_define

begin_define
define|#
directive|define
name|IDT_RCTE_AAL0
value|0x00000000
end_define

begin_define
define|#
directive|define
name|IDT_RCTE_AAL34
value|0x00010000
end_define

begin_define
define|#
directive|define
name|IDT_RCTE_AAL5
value|0x00020000
end_define

begin_define
define|#
directive|define
name|IDT_RCTE_RCQ
value|0x00030000
end_define

begin_define
define|#
directive|define
name|IDT_RCTE_OAM
value|0x00040000
end_define

begin_define
define|#
directive|define
name|IDT_RCTE_RAWCELLINTEN
value|0x00008000
end_define

begin_define
define|#
directive|define
name|IDT_RCTE_RXCONSTCELLADDR
value|0x00004000
end_define

begin_define
define|#
directive|define
name|IDT_RCTE_BUFSTAT
value|0x00003000
end_define

begin_define
define|#
directive|define
name|IDT_RCTE_EFCI
value|0x00000800
end_define

begin_define
define|#
directive|define
name|IDT_RCTE_CLP
value|0x00000400
end_define

begin_define
define|#
directive|define
name|IDT_RCTE_CRCERROR
value|0x00000200
end_define

begin_define
define|#
directive|define
name|IDT_RCTE_CELLCOUNT_MASK
value|0x000001FF
end_define

begin_define
define|#
directive|define
name|IDT_RCT_ENTRY_SIZE
value|4
end_define

begin_comment
comment|/* Number of 32-bit words */
end_comment

begin_comment
comment|/* TST - Transmit Schedule Table */
end_comment

begin_define
define|#
directive|define
name|IDT_TST_OPCODE_MASK
value|0x60000000
end_define

begin_define
define|#
directive|define
name|IDT_TST_OPCODE_NULL
value|0x00000000
end_define

begin_comment
comment|/* Insert null cell */
end_comment

begin_define
define|#
directive|define
name|IDT_TST_OPCODE_FIXED
value|0x20000000
end_define

begin_comment
comment|/* Cell from a fixed rate channel */
end_comment

begin_define
define|#
directive|define
name|IDT_TST_OPCODE_VARIABLE
value|0x40000000
end_define

begin_comment
comment|/* Cell from variable rate channel */
end_comment

begin_define
define|#
directive|define
name|IDT_TST_OPCODE_END
value|0x60000000
end_define

begin_comment
comment|/* Jump */
end_comment

begin_comment
comment|/* New #define ******************************************************************/
end_comment

begin_define
define|#
directive|define
name|PROATM_MAX_QUEUE
value|4096
end_define

begin_if
if|#
directive|if
operator|(
name|PROATM_RSQSIZE
operator|==
literal|2048
operator|)
end_if

begin_define
define|#
directive|define
name|PROATM_CFG_RSQSIZE
value|IDT_CFG_RSQSIZE_2048
end_define

begin_elif
elif|#
directive|elif
operator|(
name|PROATM_RSQSIZE
operator|==
literal|4096
operator|)
end_elif

begin_define
define|#
directive|define
name|PROATM_CFG_RSQSIZE
value|IDT_CFG_RSQSIZE_4096
end_define

begin_elif
elif|#
directive|elif
operator|(
name|PROATM_RSQSIZE
operator|==
literal|8192
operator|)
end_elif

begin_define
define|#
directive|define
name|PROATM_CFG_RSQSIZE
value|IDT_CFG_RSQSIZE_8192
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|PROATM_RSQSIZE must be 2048, 4096 or 8192
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROATM_RSQSIZE */
end_comment

begin_define
define|#
directive|define
name|PROATM_LRG_SIZE
value|2048
end_define

begin_comment
comment|/* must be power of two */
end_comment

begin_define
define|#
directive|define
name|PROATM_FIXPAGES
value|((PROATM_TSQ_SIZE + PROATM_RSQ_SIZE)/PAGE_SIZE)
end_define

begin_if
if|#
directive|if
name|PROATM_VPIBITS
operator|==
literal|0
end_if

begin_define
define|#
directive|define
name|PROATM_CFG_VPIBITS
value|IDT_CFG_VPIBITS_0
end_define

begin_elif
elif|#
directive|elif
name|PROATM_VPIBITS
operator|==
literal|1
end_elif

begin_define
define|#
directive|define
name|PROATM_CFG_VPIBITS
value|IDT_CFG_VPIBITS_1
end_define

begin_elif
elif|#
directive|elif
name|PROATM_VPIBITS
operator|==
literal|2
end_elif

begin_define
define|#
directive|define
name|PROATM_CFG_VPIBITS
value|IDT_CFG_VPIBITS_2
end_define

begin_elif
elif|#
directive|elif
name|PROATM_VPIBITS
operator|==
literal|8
end_elif

begin_define
define|#
directive|define
name|PROATM_CFG_VPIBITS
value|IDT_CFG_VPIBITS_8
end_define

begin_else
else|#
directive|else
end_else

begin_error
error|#
directive|error
error|PROATM_VPIBITS must be 0, 1, 2 or 8
end_error

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* PROATM_VPIBITS */
end_comment

begin_comment
comment|/* free buf. queues *************************************************************/
end_comment

begin_comment
comment|/* registers #34-#37 */
end_comment

begin_define
define|#
directive|define
name|IDT_FBQPR_MASK
value|0x000007FF
end_define

begin_define
define|#
directive|define
name|IDT_FBQPW_MASK
value|0x07FF0000
end_define

begin_define
define|#
directive|define
name|diff
parameter_list|(
name|fbqp
parameter_list|)
value|(int32_t) ((int32_t)((((fbqp)& IDT_FBQPW_MASK)>>16) - \                                        ((fbqp)& IDT_FBQPR_MASK))/2)
end_define

begin_define
define|#
directive|define
name|idt_fbqc_get
parameter_list|(
name|fbqp
parameter_list|)
value|(diff(fbqp)>= 0 ? diff(fbqp) : 0x400 + diff(fbqp))
end_define

begin_comment
comment|/* FBQS registers */
end_comment

begin_comment
comment|/* unit = 512/16 = 32 */
end_comment

begin_define
define|#
directive|define
name|IDT_B0THLD
value|(2<<28)
end_define

begin_define
define|#
directive|define
name|IDT_B1THLD
value|(2<<28)
end_define

begin_define
define|#
directive|define
name|IDT_B0SIZE
value|2
end_define

begin_comment
comment|/*(MHLEN/48)*/
end_comment

begin_comment
comment|/* /sys/sys/mbuf.h */
end_comment

begin_define
define|#
directive|define
name|IDT_B1SIZE
value|(MCLBYTES/48)
end_define

begin_comment
comment|/* /sys/i386/include/param.h */
end_comment

begin_comment
comment|/* Configuration Register */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|RCQ_SUPPORT
end_ifdef

begin_define
define|#
directive|define
name|IDT_DEFAULT_CFG
value|( \             IDT_CFG_RXPATH | \ 			IDT_CFG_FBIE | \ 			PROATM_CFG_RSQSIZE | \ 			PROATM_CFG_VPIBITS | \ 			IDT_CFG_RXINT_NODELAY | \ 			IDT_CFG_ICACCEPT | \ 			IDT_CFG_RAWIE | \ 			IDT_CFG_IGNOREGFC | \ 			IDT_CFG_VCERRACCEPT | \ 			IDT_CFG_RSQAFIE | \ 			IDT_CFG_TMRROIE  | \ 			IDT_CFG_TXEN | \ 			IDT_CFG_TXIE | \ 			IDT_CFG_TSQFIE | \ 			IDT_CFG_PHYIE )
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|IDT_DEFAULT_CFG
value|( \             IDT_CFG_RXPATH | \ 			IDT_CFG_FBIE | \ 			PROATM_CFG_RSQSIZE | \ 			PROATM_CFG_VPIBITS | \ 			IDT_CFG_RXINT_NODELAY | \ 			IDT_CFG_RSQAFIE | \ 			IDT_CFG_TMRROIE  | \ 			IDT_CFG_TXEN | \ 			IDT_CFG_TXIE | \ 			IDT_CFG_TSQFIE | \ 			IDT_CFG_PHYIE )
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* ESI stuff ******************************************************************/
end_comment

begin_define
define|#
directive|define
name|EPROM_PROSUM_MAC_ADDR_OFFSET
value|36
end_define

begin_define
define|#
directive|define
name|EPROM_IDT_MAC_ADDR_OFFSET
value|0x6C
end_define

begin_define
define|#
directive|define
name|PROSUM_MAC_0
value|0x00
end_define

begin_define
define|#
directive|define
name|PROSUM_MAC_1
value|0xC0
end_define

begin_define
define|#
directive|define
name|PROSUM_MAC_2
value|0xFD
end_define

begin_comment
comment|/****************************************************************************/
end_comment

begin_if
if|#
directive|if
name|XDEBUG
end_if

begin_define
define|#
directive|define
name|LOGVCS
value|1
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|LOGVCS
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_decl_stmt
specifier|static
name|int32_t
name|proatm_sysctl_logbufs
init|=
literal|0
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* periodic buffer status messages */
end_comment

begin_decl_stmt
specifier|static
name|int32_t
name|proatm_sysctl_logvcs
init|=
name|LOGVCS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* log VC open& close events */
end_comment

begin_decl_stmt
specifier|static
name|int32_t
name|proatm_sysctl_buflarge
init|=
name|PROATM_LBUFS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* desired large buffer queue */
end_comment

begin_comment
comment|/* between 64 and 510 */
end_comment

begin_decl_stmt
specifier|static
name|int32_t
name|proatm_sysctl_bufsmall
init|=
name|PROATM_SBUFS
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* desired small buffer queue */
end_comment

begin_comment
comment|/* between 64 and 510 */
end_comment

begin_expr_stmt
name|SYSCTL_NODE
argument_list|(
name|_hw
argument_list|,
name|OID_AUTO
argument_list|,
name|proatm
argument_list|,
name|CTLFLAG_RW
argument_list|,
literal|0
argument_list|,
literal|"PROATM"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_hw_proatm
argument_list|,
name|OID_AUTO
argument_list|,
name|log_bufstat
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|proatm_sysctl_logbufs
argument_list|,
literal|0
argument_list|,
literal|"Log buffer status"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_hw_proatm
argument_list|,
name|OID_AUTO
argument_list|,
name|log_vcs
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|proatm_sysctl_logvcs
argument_list|,
literal|0
argument_list|,
literal|"Log VC open/close"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_hw_proatm
argument_list|,
name|OID_AUTO
argument_list|,
name|bufs_large
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|proatm_sysctl_buflarge
argument_list|,
name|PROATM_LBUFS
argument_list|,
literal|"Large buffer queue"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_expr_stmt
name|SYSCTL_INT
argument_list|(
name|_hw_proatm
argument_list|,
name|OID_AUTO
argument_list|,
name|bufs_small
argument_list|,
name|CTLFLAG_RW
argument_list|,
operator|&
name|proatm_sysctl_bufsmall
argument_list|,
name|PROATM_SBUFS
argument_list|,
literal|"Small buffer queue"
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* common VCI values **************************************************************/
end_comment

begin_comment
comment|/* 0/0  Idle cells 0/1  Meta signalling x/1  Meta signalling 0/2  Broadcast signalling x/2  Broadcast signalling x/3  Segment OAM F4 flow x/4  End-end OAM F4 flow 0/5  p-p signalling x/5  p-p signalling x/6  rate management 0/14 SPANS 0/15 SPANS 0/16 ILMI 0/18 PNNI */
end_comment

begin_comment
comment|/* AAL types */
end_comment

begin_define
define|#
directive|define
name|IDTAAL0
value|0
end_define

begin_define
define|#
directive|define
name|IDTAAL1
value|1
end_define

begin_define
define|#
directive|define
name|IDTAAL3_4
value|3
end_define

begin_define
define|#
directive|define
name|IDTAAL5
value|5
end_define

begin_define
define|#
directive|define
name|NICCBR
value|1
end_define

begin_define
define|#
directive|define
name|NICVBR
value|2
end_define

begin_define
define|#
directive|define
name|NICABR
value|3
end_define

begin_define
define|#
directive|define
name|NICUBR
value|4
end_define

begin_define
define|#
directive|define
name|NICUBR0
value|5
end_define

begin_comment
comment|/* RCQ - Raw Cell Queue  *  * Written by the NICStAR, read by the device driver.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|cell_payload
block|{
name|u_int32_t
name|word
index|[
literal|12
index|]
decl_stmt|;
block|}
name|cell_payload
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|rcqe
block|{
name|u_int32_t
name|word_1
decl_stmt|;
name|u_int32_t
name|word_2
decl_stmt|;
name|u_int32_t
name|word_3
decl_stmt|;
name|u_int32_t
name|word_4
decl_stmt|;
name|cell_payload
name|payload
decl_stmt|;
block|}
name|rcqe
typedef|;
end_typedef

begin_define
define|#
directive|define
name|IDT_RCQE_SIZE
value|64
end_define

begin_comment
comment|/* bytes */
end_comment

begin_comment
comment|/* TXQUEUE structure *************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|mbuf
modifier|*
name|mget
decl_stmt|;
comment|/* head of mbuf queue, pull mbufs from here */
name|struct
name|mbuf
modifier|*
name|mput
decl_stmt|;
comment|/* tail of mbuf queue, put mbufs here */
name|u_int32_t
name|scd
decl_stmt|;
comment|/* segmentation channel descriptor address */
name|u_int32_t
modifier|*
name|scq_base
decl_stmt|;
comment|/* segmentation channel queue base address */
name|u_int32_t
modifier|*
name|scq_next
decl_stmt|;
comment|/* next address */
name|u_int32_t
modifier|*
name|scq_last
decl_stmt|;
comment|/* last address written */
name|int32_t
name|scq_cur
decl_stmt|;
comment|/* current number entries in SCQ buffer known by the SAR */
name|int32_t
name|rate
decl_stmt|;
comment|/* cells per second allocated to this queue */
block|}
name|TX_QUEUE
typedef|;
end_typedef

begin_comment
comment|/*  To avoid expensive SRAM reads, scq_cur tracks the number of SCQ entries  *  in use.  Only proatm_transmit_top may increase this, and only proatm_intr_tsq  *  may decrease it.  *  *  mbuf chains on the queue use the fields:  *  m_next     is the usual pointer to next mbuf  *  m_nextpkt  is the next packet on the queue  *  m_pkthdr.rcvif is a pointer to the connection  *  m_pkthdr.header is a pointer to the TX queue  *  *  The TX_QUEUEs has to be R/W only at splimp().  */
end_comment

begin_comment
comment|/* CONNECTION structure *****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|struct
name|vccb
modifier|*
name|vccinf
decl_stmt|;
name|u_int8_t
name|vpi
decl_stmt|;
name|u_int16_t
name|vci
decl_stmt|;
name|int32_t
name|number
decl_stmt|;
comment|/* connection number */
name|TX_QUEUE
modifier|*
name|queue
decl_stmt|;
comment|/* transmit queue for this connection */
name|struct
name|mbuf
modifier|*
name|recv
decl_stmt|;
comment|/* current receive mbuf, or NULL */
name|int32_t
name|rlen
decl_stmt|;
comment|/* current receive length */
name|int32_t
name|maxpdu
decl_stmt|;
comment|/* largest PDU we will ever see */
name|int32_t
name|traf_pcr
decl_stmt|;
name|int32_t
name|traf_scr
decl_stmt|;
name|int32_t
name|traf_mbs
decl_stmt|;
name|u_int8_t
name|aal
decl_stmt|;
comment|/* AAL for this connection */
name|u_int8_t
name|class
decl_stmt|;
comment|/* NICCBR, NICVBR, NICUBR or NICUBR0 */
name|u_int8_t
name|flg_clp
range|:
literal|1
decl_stmt|;
comment|/* CLP flag for outbound cells */
name|u_int8_t
name|flg_active
range|:
literal|1
decl_stmt|;
comment|/* connection is active */
name|u_int8_t
name|flg_closing
range|:
literal|1
decl_stmt|;
comment|/* close pending */
name|u_int8_t
name|flg_open
range|:
literal|1
decl_stmt|;
comment|/* O if closed */
name|u_int8_t
name|lacr
decl_stmt|;
name|u_int8_t
name|init_er
decl_stmt|;
block|}
name|CONNECTION
typedef|;
end_typedef

begin_define
define|#
directive|define
name|GET_RDTSC
parameter_list|(
name|var
parameter_list|)
value|{__asm__ volatile("rdtsc":"=A"(var)); }
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_comment
comment|/* SUNI management and statistics *******************************************************/
end_comment

begin_struct
struct|struct
name|proatm_stats_oc3
block|{
name|u_int32_t
name|oc3_sect_bip8
decl_stmt|;
comment|/* Section 8-bit intrlv parity errors */
name|u_int32_t
name|oc3_path_bip8
decl_stmt|;
comment|/* Path 8-bit intrlv parity errors */
name|u_int32_t
name|oc3_line_bip24
decl_stmt|;
comment|/* Line 24-bit intrlv parity errors */
name|u_int32_t
name|oc3_line_febe
decl_stmt|;
comment|/* Line far-end block errors */
name|u_int32_t
name|oc3_path_febe
decl_stmt|;
comment|/* Path far-end block errors */
name|u_int32_t
name|oc3_hec_corr
decl_stmt|;
comment|/* Correctable HEC errors */
name|u_int32_t
name|oc3_hec_uncorr
decl_stmt|;
comment|/* Uncorrectable HEC errors */
name|u_int32_t
name|oc3_rx_cells
decl_stmt|;
comment|/* Receive cells */
name|u_int32_t
name|oc3_tx_cells
decl_stmt|;
comment|/* Transmit cells */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|proatm_stats_oc3
name|Proatm_Stats_oc3
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|READ_ONE
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|)
value|proatm_util_rd(proatm, (x),&t); y = t& 0xff;
end_define

begin_define
define|#
directive|define
name|READ_TWO
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|)
value|proatm_util_rd(proatm, (x+1),&t); y = (t& 0xff)<< 8; \              proatm_util_rd(proatm, (x),&t); y |= t& 0xff;
end_define

begin_define
define|#
directive|define
name|READ_THREE
parameter_list|(
name|y
parameter_list|,
name|x
parameter_list|)
value|proatm_util_rd(proatm,(x+2),&t); y = (t& 0xff)<< 16; \               proatm_util_rd(proatm,(x+1),&t); y = (t& 0xff)<< 8; \               proatm_util_rd(proatm,(x),&t); y |= t& 0xff;
end_define

begin_comment
comment|/* Some SUNI Register numbers */
end_comment

begin_define
define|#
directive|define
name|SUNI_MASTER_REG
value|0x00
end_define

begin_comment
comment|/* Master reset and ID */
end_comment

begin_define
define|#
directive|define
name|SUNI_IS_REG
value|0x02
end_define

begin_comment
comment|/* Master Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|SUNI_MSTR_CTRL_REG
value|0x05
end_define

begin_comment
comment|/* Master Control */
end_comment

begin_define
define|#
directive|define
name|SUNI_CLOCK_REG
value|0x06
end_define

begin_comment
comment|/* Clock synth/control/status */
end_comment

begin_define
define|#
directive|define
name|SUNI_RSOP_REG
value|0x10
end_define

begin_comment
comment|/* RSOP control/Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|SUNI_RSOP_SIS_REG
value|0x11
end_define

begin_comment
comment|/* RSOP status/interrupt status */
end_comment

begin_define
define|#
directive|define
name|SUNI_SECT_BIP_REG
value|0x12
end_define

begin_comment
comment|/* RSOP section BIP 8 LSB */
end_comment

begin_define
define|#
directive|define
name|SUNI_RLOP_REG
value|0x18
end_define

begin_comment
comment|/* RLOP control/Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|SUNI_LINE_BIP_REG
value|0x1A
end_define

begin_comment
comment|/* RLOP line BIP 8/24 LSB */
end_comment

begin_define
define|#
directive|define
name|SUNI_LINE_FEBE_REG
value|0x1D
end_define

begin_comment
comment|/* RLOP line FEBE LSB */
end_comment

begin_define
define|#
directive|define
name|SUNI_RPOP_IS_REG
value|0x31
end_define

begin_comment
comment|/* RPOP Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|SUNI_PATH_BIP_REG
value|0x38
end_define

begin_comment
comment|/* RPOP path BIP 8 LSB */
end_comment

begin_define
define|#
directive|define
name|SUNI_PATH_FEBE_REG
value|0x3A
end_define

begin_comment
comment|/* RPOP path FEBE LSB */
end_comment

begin_define
define|#
directive|define
name|SUNI_TPOP_MSB_REG
value|0x46
end_define

begin_comment
comment|/* TPOP arbitrary pointer MSB */
end_comment

begin_define
define|#
directive|define
name|SUNI_RACP_REG
value|0x50
end_define

begin_comment
comment|/* RACP control/status */
end_comment

begin_define
define|#
directive|define
name|SUNI_HECS_REG
value|0x54
end_define

begin_comment
comment|/* RACP correctable HCS error count */
end_comment

begin_define
define|#
directive|define
name|SUNI_UHECS_REG
value|0x55
end_define

begin_comment
comment|/* RACP uncorrectable HCS err count */
end_comment

begin_define
define|#
directive|define
name|SUNI_RACP_RX_REG
value|0x56
end_define

begin_comment
comment|/* RACP receive cell counter */
end_comment

begin_define
define|#
directive|define
name|SUNI_TACP_REG
value|0x60
end_define

begin_comment
comment|/* TACP control/status */
end_comment

begin_define
define|#
directive|define
name|SUNI_TACP_TX_REG
value|0x64
end_define

begin_comment
comment|/* TACP transmit cell counter */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_comment
comment|/* IDT77105 management and statistics ***************************************************/
end_comment

begin_struct
struct|struct
name|proatm_stats_utp25
block|{
name|u_int32_t
name|utp25_symbol_errors
decl_stmt|;
comment|/* wire symbol errors */
name|u_int32_t
name|utp25_tx_cells
decl_stmt|;
comment|/* cells transmitted */
name|u_int32_t
name|utp25_rx_cells
decl_stmt|;
comment|/* cells received */
name|u_int32_t
name|utp25_rx_hec_errors
decl_stmt|;
comment|/* Header Error Check errors on receive */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|proatm_stats_utp25
name|Proatm_Stats_utp25
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|)
end_if

begin_comment
comment|/* The IDT77105 registers */
end_comment

begin_define
define|#
directive|define
name|IDT77105_MCR_REG
value|0x00
end_define

begin_comment
comment|/* Master Control Register */
end_comment

begin_define
define|#
directive|define
name|IDT77105_ISTAT_REG
value|0x01
end_define

begin_comment
comment|/* Interrupt Status */
end_comment

begin_define
define|#
directive|define
name|IDT77105_DIAG_REG
value|0x02
end_define

begin_comment
comment|/* Diagnostic Control */
end_comment

begin_define
define|#
directive|define
name|IDT77105_LEDHEC_REG
value|0x03
end_define

begin_comment
comment|/* LED Driver& HEC Status/Control */
end_comment

begin_define
define|#
directive|define
name|IDT77105_CTRLO_REG
value|0x04
end_define

begin_comment
comment|/* Low Byte Counter Register */
end_comment

begin_define
define|#
directive|define
name|IDT77105_CTRHI_REG
value|0x05
end_define

begin_comment
comment|/* High Byte Counter Register */
end_comment

begin_define
define|#
directive|define
name|IDT77105_CTRSEL_REG
value|0x06
end_define

begin_comment
comment|/* Counter Register Read Select */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_comment
comment|/* Proam Soft Drivers Statistics *********************************************************/
end_comment

begin_struct
struct|struct
name|proatm_stats_atm
block|{
name|u_int32_t
name|atm_xmit
decl_stmt|;
comment|/* Cells transmitted */
name|u_int32_t
name|atm_rcvd
decl_stmt|;
comment|/* Cells received */
name|u_int32_t
name|atm_pad
index|[
literal|2
index|]
decl_stmt|;
comment|/* Pad to quad-word boundary */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|proatm_stats_atm
name|Proatm_Stats_atm
typedef|;
end_typedef

begin_struct
struct|struct
name|proatm_stats_aal0
block|{
name|u_int32_t
name|aal0_xmit
decl_stmt|;
comment|/* Cells transmitted */
name|u_int32_t
name|aal0_rcvd
decl_stmt|;
comment|/* Cells received */
name|u_int32_t
name|aal0_drops
decl_stmt|;
comment|/* Cells dropped */
name|u_int32_t
name|aal0_pad
decl_stmt|;
comment|/* Pad to quad-word boundary */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|proatm_stats_aal0
name|Proatm_Stats_aal0
typedef|;
end_typedef

begin_struct
struct|struct
name|proatm_stats_aal4
block|{
name|u_int32_t
name|aal4_xmit
decl_stmt|;
comment|/* Cells transmitted */
name|u_int32_t
name|aal4_rcvd
decl_stmt|;
comment|/* Cells received */
name|u_int32_t
name|aal4_crc
decl_stmt|;
comment|/* Cells with payload CRC errors */
name|u_int32_t
name|aal4_sar_cs
decl_stmt|;
comment|/* Unknown proto */
name|u_int32_t
name|aal4_drops
decl_stmt|;
comment|/* Cell drops */
name|u_int32_t
name|aal4_pdu_xmit
decl_stmt|;
comment|/* CS PDUs transmitted */
name|u_int32_t
name|aal4_pdu_rcvd
decl_stmt|;
comment|/* CS PDUs received */
name|u_int32_t
name|aal4_pdu_errs
decl_stmt|;
comment|/* CS PDUs with PDU errors */
name|u_int32_t
name|aal4_pdu_drops
decl_stmt|;
comment|/* CS PDUs dropped */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|proatm_stats_aal4
name|Proatm_Stats_aal4
typedef|;
end_typedef

begin_struct
struct|struct
name|proatm_stats_aal5
block|{
name|u_int32_t
name|aal5_xmit
decl_stmt|;
comment|/* Cells transmitted */
name|u_int32_t
name|aal5_rcvd
decl_stmt|;
comment|/* Cells received */
name|u_int32_t
name|aal5_crc_len
decl_stmt|;
comment|/* Cells with CRC/length errors */
name|u_int32_t
name|aal5_drops
decl_stmt|;
comment|/* Cell drops */
name|u_int32_t
name|aal5_pdu_xmit
decl_stmt|;
comment|/* CS PDUs transmitted */
name|u_int32_t
name|aal5_pdu_rcvd
decl_stmt|;
comment|/* CS PDUs received */
name|u_int32_t
name|aal5_pdu_crc
decl_stmt|;
comment|/* CS PDUs with CRC errors */
name|u_int32_t
name|aal5_pdu_drops
decl_stmt|;
comment|/* CS PDUs dropped */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|proatm_stats_aal5
name|Proatm_Stats_aal5
typedef|;
end_typedef

begin_struct
struct|struct
name|proatm_stats_driver
block|{
comment|/* 	 * VCM sats [OK] 	 */
name|u_int32_t
name|drv_vc_maxpdu
decl_stmt|;
comment|/* Requested PDU size too large */
name|u_int32_t
name|drv_vc_badrng
decl_stmt|;
comment|/* VPI and/or VCI too large */
name|u_int32_t
name|drv_vc_outofbw
decl_stmt|;
comment|/* Not enough bandwidth for requested CBR VC */
comment|/* 	 * Receive stats [OK] 	 */
name|u_int32_t
name|drv_rv_nocx
decl_stmt|;
comment|/* No SAR CONNECTION */
name|u_int32_t
name|drv_rv_nopkthdr
decl_stmt|;
comment|/* No M_PKTHDR within first mbuf */
name|u_int32_t
name|drv_rv_invchain
decl_stmt|;
comment|/* Invalid mbuf chain */
name|u_int32_t
name|drv_rv_toobigpdu
decl_stmt|;
comment|/* Received len> cx's maxpdu */
name|u_int32_t
name|drv_rv_novcc
decl_stmt|;
comment|/* No HARP vpi/vci connection */
name|u_int32_t
name|drv_rv_nobufs
decl_stmt|;
comment|/* Not enough buffer space */
name|u_int32_t
name|drv_rv_null
decl_stmt|;
comment|/* Trying to pass null PDU up stack */
name|u_int32_t
name|drv_rv_intrq
decl_stmt|;
comment|/* No room in atm_intrq */
comment|/* 	 * RAW receive stats [OK] 	 */
name|u_int32_t
name|drv_rv_rnotrdy
decl_stmt|;
comment|/* RAW cell received, buffers not ready */
name|u_int32_t
name|drv_rv_rnobufs
decl_stmt|;
comment|/* Not enough buffer space for raw cells */
comment|/* 	 * Transmit stats [OK] 	 */
name|u_int32_t
name|drv_xm_txicp
decl_stmt|;
comment|/* Transmit Error Incomplete PDU */
name|u_int32_t
name|drv_xm_ntbd
decl_stmt|;
comment|/* Number of TBDs transmited to the SAR */
name|u_int32_t
name|drv_xm_idlevbr
decl_stmt|;
comment|/* Number of idle VBR VCs */
name|u_int32_t
name|drv_xm_closing
decl_stmt|;
comment|/* Number close VC requests in progress */
name|u_int32_t
name|drv_xm_qufree
decl_stmt|;
comment|/* Number of free txqueue = txqueue_free_count */
name|u_int32_t
name|drv_xm_cbrbw
decl_stmt|;
comment|/* CBR bandwidth reserved on the board */
name|u_int32_t
name|drv_xm_ubr0free
decl_stmt|;
comment|/* Number of free slots of the UBR0 queue */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|proatm_stats_driver
name|Proatm_Stats_drv
typedef|;
end_typedef

begin_struct
struct|struct
name|proatm_stats
block|{
name|Proatm_Stats_oc3
name|proatm_st_oc3
decl_stmt|;
comment|/* OC3 layer stats */
name|Proatm_Stats_utp25
name|proatm_st_utp25
decl_stmt|;
comment|/* UTP25 layer stats */
name|Proatm_Stats_atm
name|proatm_st_atm
decl_stmt|;
comment|/* ATM layer stats */
name|Proatm_Stats_aal0
name|proatm_st_aal0
decl_stmt|;
comment|/* AAL0 layer stats */
name|Proatm_Stats_aal4
name|proatm_st_aal4
decl_stmt|;
comment|/* AAL3/4 layer stats */
name|Proatm_Stats_aal5
name|proatm_st_aal5
decl_stmt|;
comment|/* AAL5 layer stats */
name|Proatm_Stats_drv
name|proatm_st_drv
decl_stmt|;
comment|/* Driver stats */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|proatm_stats
name|Proatm_stats
typedef|;
end_typedef

begin_if
if|#
directive|if
operator|(
name|defined
argument_list|(
name|_KERNEL
argument_list|)
operator|||
name|defined
argument_list|(
name|KERNEL
argument_list|)
operator|)
end_if

begin_define
define|#
directive|define
name|BYTES_PER_CELL
value|48
end_define

begin_comment
comment|/* Device softc structure ****************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|Cmn_unit
name|iu_cmn
decl_stmt|;
comment|/* Common unit stuff */
name|int32_t
name|unit
decl_stmt|;
comment|/* unit number of this device */
name|vm_offset_t
name|virt_baseaddr
decl_stmt|;
comment|/* nicstar register virtual address */
name|vm_offset_t
name|fixbuf
decl_stmt|;
comment|/* buffer that holds TSQ, RSQ, variable SCQ */
name|int32_t
name|sram_size
decl_stmt|;
comment|/* In words, 0x4000 or 0x10000 */
name|u_int32_t
name|rct
decl_stmt|;
comment|/* SRAM address of the RCT */
name|int32_t
name|rct_size
decl_stmt|;
comment|/* Number of RCT entries */
name|u_int32_t
name|rate
decl_stmt|;
comment|/* SRAM address of the Rate tables */
name|u_int32_t
name|tst
decl_stmt|;
comment|/* SRAM address of the TST */
name|u_int32_t
name|tst_num
decl_stmt|;
comment|/* Number of usable TST entries */
name|u_int32_t
name|dtst
decl_stmt|;
comment|/* SRAM address of the DTST */
name|u_int32_t
name|scd
decl_stmt|;
comment|/* SRAM address of the SCDs */
name|int32_t
name|scd_size
decl_stmt|;
comment|/* number of SCD entries */
name|int32_t
name|scd_ubr0
decl_stmt|;
comment|/* SCD reserved for unspecified-pcr connections */
name|u_int32_t
name|rxfifo
decl_stmt|;
comment|/* SRAM address of the Receive FIFO */
name|int32_t
name|vpibits
decl_stmt|;
comment|/* Number of VPI bits */
name|int32_t
name|vcibits
decl_stmt|;
comment|/* Number of VCI bits */
name|u_int32_t
name|vpm
decl_stmt|;
comment|/* mask register value */
name|int32_t
name|max_connection
decl_stmt|;
comment|/* Max number of connections */
name|int32_t
name|conn_maxvpi
decl_stmt|;
comment|/* number of VPI values */
name|int32_t
name|conn_maxvci
decl_stmt|;
comment|/* number of VCI values */
name|u_int32_t
name|timer_wrap
decl_stmt|;
comment|/* keep track of wrapped timers */
name|u_int32_t
name|rsqh
decl_stmt|;
comment|/* Receive Status Queue, reg is write-only */
name|struct
name|arpcom
name|proatm_ac
decl_stmt|;
comment|/* ifnet for device */
name|CONNECTION
modifier|*
name|connection
decl_stmt|;
comment|/* table of connections, indexed by vpi*vci */
name|u_int32_t
name|max_pcr
decl_stmt|;
name|int32_t
name|cellrate_tcur
decl_stmt|;
comment|/* current CBR TX cellrate */
name|int32_t
name|txslots_cur
decl_stmt|;
comment|/* current number of TST slots in use */
name|TX_QUEUE
name|txqueue
index|[
name|PROATM_MAX_QUEUE
index|]
decl_stmt|;
name|TX_QUEUE
name|txqueue_ubr0
decl_stmt|;
comment|/* tx queue for unspecified-pcr connections */
name|TX_QUEUE
modifier|*
name|txqueue_free
index|[
name|PROATM_MAX_QUEUE
index|]
decl_stmt|;
name|int32_t
name|txqueue_free_count
decl_stmt|;
name|TX_QUEUE
modifier|*
name|tst_slot
index|[
name|PROATM_TST_MAX
index|]
decl_stmt|;
name|vm_offset_t
name|scq_cluster_base
decl_stmt|;
comment|/* base of memory for SCQ TX queues */
name|int32_t
name|scq_cluster_size
decl_stmt|;
comment|/* size of memory for SCQ TX queues */
name|u_int8_t
name|scq_ubr0_cluster
index|[
name|IDT_SCQ_SIZE
operator|*
literal|2
index|]
decl_stmt|;
name|u_int32_t
name|raw_headp
decl_stmt|;
comment|/* head of raw cell queue, physical */
name|struct
name|mbuf
modifier|*
name|raw_headm
decl_stmt|;
comment|/* head of raw cell queue, virtual */
name|u_int32_t
name|raw_hnd
index|[
literal|2
index|]
decl_stmt|;
comment|/* raw cell queue tail pointer and rawcell handle*/
name|rcqe
modifier|*
name|raw_ch
decl_stmt|;
comment|/* raw cell head pointer */
name|u_int32_t
modifier|*
name|tsq_base
decl_stmt|;
comment|/* virtual TSQ base address */
name|u_int32_t
modifier|*
name|tsq_head
decl_stmt|;
comment|/* virtual TSQ head pointer */
name|int32_t
name|tsq_size
decl_stmt|;
comment|/* number of TSQ entries (1024) */
define|#
directive|define
name|PROATM_MCHECK_COUNT
value|1024
comment|/* 1024 pointers on mbufs */
name|struct
name|mbuf
modifier|*
modifier|*
name|mcheck
decl_stmt|;
name|struct
name|callout_handle
name|stat_ch
decl_stmt|;
name|struct
name|resource
modifier|*
name|mem
decl_stmt|;
name|struct
name|resource
modifier|*
name|irq
decl_stmt|;
name|void
modifier|*
name|irqcookie
decl_stmt|;
name|bus_space_tag_t
name|bustag
decl_stmt|;
name|bus_space_handle_t
name|bushandle
decl_stmt|;
name|int32_t
name|pci_rev
decl_stmt|;
comment|/* hardware revision ID */
name|char
name|hardware
index|[
literal|16
index|]
decl_stmt|;
comment|/* hardware description string */
specifier|volatile
name|int32_t
name|tst_free_entries
decl_stmt|;
name|u_int32_t
name|flg_25
range|:
literal|1
decl_stmt|;
comment|/* flag indicates 25.6 Mbps instead of 155 Mbps */
name|u_int32_t
name|flg_igcrc
range|:
literal|1
decl_stmt|;
comment|/* ignore receive CRC errors */
name|u_int32_t
name|flg_pad
range|:
literal|30
decl_stmt|;
name|Proatm_stats
name|pu_stats
decl_stmt|;
comment|/* Statistics */
block|}
name|proatm_reg_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|proatm_reg_t
name|PROATM
typedef|;
end_typedef

begin_decl_stmt
specifier|static
name|proatm_reg_t
modifier|*
name|nicstar
index|[
name|MAXCARDS
index|]
decl_stmt|;
end_decl_stmt

begin_define
define|#
directive|define
name|iu_pif
value|iu_cmn.cu_pif
end_define

begin_define
define|#
directive|define
name|stats_ipdus
value|iu_pif.pif_ipdus
end_define

begin_define
define|#
directive|define
name|stats_opdus
value|iu_pif.pif_opdus
end_define

begin_define
define|#
directive|define
name|stats_ibytes
value|iu_pif.pif_ibytes
end_define

begin_define
define|#
directive|define
name|stats_obytes
value|iu_pif.pif_obytes
end_define

begin_define
define|#
directive|define
name|stats_ierrors
value|iu_pif.pif_ierrors
end_define

begin_define
define|#
directive|define
name|stats_oerrors
value|iu_pif.pif_oerrors
end_define

begin_define
define|#
directive|define
name|stats_cmderrors
value|iu_pif.pif_cmderrors
end_define

begin_comment
comment|/****************************************************************************************/
end_comment

begin_define
define|#
directive|define
name|ALIGN_ADDR
parameter_list|(
name|addr
parameter_list|,
name|alignment
parameter_list|)
define|\
value|((((u_int32_t) (addr)) + (((u_int32_t) (alignment)) - 1))& ~(((u_int32_t) (alignment)) - 1))
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* KERNEL */
end_comment

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _PROATM_H */
end_comment

end_unit

