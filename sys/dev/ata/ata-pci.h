begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 Søren Schmidt<sos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
end_comment

begin_comment
comment|/* structure holding chipset config info */
end_comment

begin_struct
struct|struct
name|ata_chip_id
block|{
name|u_int32_t
name|chipid
decl_stmt|;
name|u_int8_t
name|chiprev
decl_stmt|;
name|int
name|cfg1
decl_stmt|;
name|int
name|cfg2
decl_stmt|;
name|u_int8_t
name|max_dma
decl_stmt|;
name|char
modifier|*
name|text
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* structure describing a PCI ATA controller */
end_comment

begin_struct
struct|struct
name|ata_pci_controller
block|{
name|struct
name|resource
modifier|*
name|r_io1
decl_stmt|;
name|struct
name|resource
modifier|*
name|r_io2
decl_stmt|;
name|struct
name|resource
modifier|*
name|r_irq
decl_stmt|;
name|void
modifier|*
name|handle
decl_stmt|;
name|struct
name|ata_chip_id
modifier|*
name|chip
decl_stmt|;
name|int
function_decl|(
modifier|*
name|chipinit
function_decl|)
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|allocate
function_decl|)
parameter_list|(
name|device_t
parameter_list|,
name|struct
name|ata_channel
modifier|*
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|dmainit
function_decl|)
parameter_list|(
name|struct
name|ata_channel
modifier|*
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|setmode
function_decl|)
parameter_list|(
name|struct
name|ata_device
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|locking
function_decl|)
parameter_list|(
name|struct
name|ata_channel
modifier|*
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
name|locked_ch
decl_stmt|;
name|int
name|channels
decl_stmt|;
struct|struct
block|{
name|void
function_decl|(
modifier|*
name|function
function_decl|)
parameter_list|(
name|void
modifier|*
parameter_list|)
function_decl|;
name|void
modifier|*
name|argument
decl_stmt|;
block|}
name|interrupt
index|[
literal|4
index|]
struct|;
comment|/* XXX SOS max ch# for now */
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ATA_MASTERDEV
parameter_list|(
name|dev
parameter_list|)
value|((pci_get_progif(dev)& 0x80)&& \ 				 (pci_get_progif(dev)& 0x05) != 0x05)
end_define

begin_comment
comment|/* defines for known chipset PCI id's */
end_comment

begin_define
define|#
directive|define
name|ATA_ACARD_ID
value|0x1191
end_define

begin_define
define|#
directive|define
name|ATA_ATP850
value|0x00021191
end_define

begin_define
define|#
directive|define
name|ATA_ATP850A
value|0x00041191
end_define

begin_define
define|#
directive|define
name|ATA_ATP850R
value|0x00051191
end_define

begin_define
define|#
directive|define
name|ATA_ATP860A
value|0x00061191
end_define

begin_define
define|#
directive|define
name|ATA_ATP860R
value|0x00071191
end_define

begin_define
define|#
directive|define
name|ATA_ATP865A
value|0x00081191
end_define

begin_define
define|#
directive|define
name|ATA_ATP865R
value|0x00091191
end_define

begin_define
define|#
directive|define
name|ATA_AMD_ID
value|0x1022
end_define

begin_define
define|#
directive|define
name|ATA_AMD755
value|0x74011022
end_define

begin_define
define|#
directive|define
name|ATA_AMD756
value|0x74091022
end_define

begin_define
define|#
directive|define
name|ATA_AMD766
value|0x74111022
end_define

begin_define
define|#
directive|define
name|ATA_AMD768
value|0x74411022
end_define

begin_define
define|#
directive|define
name|ATA_AMD8111
value|0x74691022
end_define

begin_define
define|#
directive|define
name|ATA_ACER_LABS_ID
value|0x10b9
end_define

begin_define
define|#
directive|define
name|ATA_ALI_5229
value|0x522910b9
end_define

begin_define
define|#
directive|define
name|ATA_CYRIX_ID
value|0x1078
end_define

begin_define
define|#
directive|define
name|ATA_CYRIX_5530
value|0x01021078
end_define

begin_define
define|#
directive|define
name|ATA_CYPRESS_ID
value|0x1080
end_define

begin_define
define|#
directive|define
name|ATA_CYPRESS_82C693
value|0xc6931080
end_define

begin_define
define|#
directive|define
name|ATA_DEC_21150
value|0x00221011
end_define

begin_define
define|#
directive|define
name|ATA_HIGHPOINT_ID
value|0x1103
end_define

begin_define
define|#
directive|define
name|ATA_HPT366
value|0x00041103
end_define

begin_define
define|#
directive|define
name|ATA_HPT372
value|0x00051103
end_define

begin_define
define|#
directive|define
name|ATA_HPT302
value|0x00061103
end_define

begin_define
define|#
directive|define
name|ATA_HPT371
value|0x00071103
end_define

begin_define
define|#
directive|define
name|ATA_HPT374
value|0x00081103
end_define

begin_define
define|#
directive|define
name|ATA_INTEL_ID
value|0x8086
end_define

begin_define
define|#
directive|define
name|ATA_I960RM
value|0x09628086
end_define

begin_define
define|#
directive|define
name|ATA_I82371FB
value|0x12308086
end_define

begin_define
define|#
directive|define
name|ATA_I82371SB
value|0x70108086
end_define

begin_define
define|#
directive|define
name|ATA_I82371AB
value|0x71118086
end_define

begin_define
define|#
directive|define
name|ATA_I82443MX
value|0x71998086
end_define

begin_define
define|#
directive|define
name|ATA_I82451NX
value|0x84ca8086
end_define

begin_define
define|#
directive|define
name|ATA_I82372FB
value|0x76018086
end_define

begin_define
define|#
directive|define
name|ATA_I82801AB
value|0x24218086
end_define

begin_define
define|#
directive|define
name|ATA_I82801AA
value|0x24118086
end_define

begin_define
define|#
directive|define
name|ATA_I82801BA
value|0x244a8086
end_define

begin_define
define|#
directive|define
name|ATA_I82801BA_1
value|0x244b8086
end_define

begin_define
define|#
directive|define
name|ATA_I82801CA
value|0x248a8086
end_define

begin_define
define|#
directive|define
name|ATA_I82801CA_1
value|0x248b8086
end_define

begin_define
define|#
directive|define
name|ATA_I82801DB
value|0x24cb8086
end_define

begin_define
define|#
directive|define
name|ATA_I82801DB_1
value|0x24ca8086
end_define

begin_define
define|#
directive|define
name|ATA_I82801EB
value|0x24db8086
end_define

begin_define
define|#
directive|define
name|ATA_I82801EB_1
value|0x24d18086
end_define

begin_define
define|#
directive|define
name|ATA_NVIDIA_ID
value|0x10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE1
value|0x01bc10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE2
value|0x006510de
end_define

begin_define
define|#
directive|define
name|ATA_PROMISE_ID
value|0x105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20246
value|0x4d33105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20262
value|0x4d38105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20263
value|0x0d38105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20265
value|0x0d30105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20267
value|0x4d30105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20268
value|0x4d68105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20269
value|0x4d69105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20270
value|0x6268105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20271
value|0x6269105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20275
value|0x1275105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20276
value|0x5275105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20277
value|0x7275105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20318
value|0x3318105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20319
value|0x3319105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20371
value|0x3371105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20375
value|0x3375105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20376
value|0x3376105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20377
value|0x3377105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20378
value|0x3373105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20379
value|0x3372105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20617
value|0x6617105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20618
value|0x6626105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20619
value|0x6629105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20620
value|0x6620105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20621
value|0x6621105a
end_define

begin_define
define|#
directive|define
name|ATA_SERVERWORKS_ID
value|0x1166
end_define

begin_define
define|#
directive|define
name|ATA_ROSB4
value|0x02111166
end_define

begin_define
define|#
directive|define
name|ATA_CSB5
value|0x02121166
end_define

begin_define
define|#
directive|define
name|ATA_CSB6
value|0x02131166
end_define

begin_define
define|#
directive|define
name|ATA_CSB6_1
value|0x02171166
end_define

begin_define
define|#
directive|define
name|ATA_SILICON_IMAGE_ID
value|0x1095
end_define

begin_define
define|#
directive|define
name|ATA_SII0680
value|0x06801095
end_define

begin_define
define|#
directive|define
name|ATA_SII3112
value|0x31121095
end_define

begin_define
define|#
directive|define
name|ATA_CMD646
value|0x06461095
end_define

begin_define
define|#
directive|define
name|ATA_CMD648
value|0x06481095
end_define

begin_define
define|#
directive|define
name|ATA_CMD649
value|0x06491095
end_define

begin_define
define|#
directive|define
name|ATA_SIS_ID
value|0x1039
end_define

begin_define
define|#
directive|define
name|ATA_SISSOUTH
value|0x00081039
end_define

begin_define
define|#
directive|define
name|ATA_SIS5511
value|0x55111039
end_define

begin_define
define|#
directive|define
name|ATA_SIS5513
value|0x55131039
end_define

begin_define
define|#
directive|define
name|ATA_SIS5518
value|0x55181039
end_define

begin_define
define|#
directive|define
name|ATA_SIS5571
value|0x55711039
end_define

begin_define
define|#
directive|define
name|ATA_SIS5591
value|0x55911039
end_define

begin_define
define|#
directive|define
name|ATA_SIS5596
value|0x55961039
end_define

begin_define
define|#
directive|define
name|ATA_SIS5597
value|0x55971039
end_define

begin_define
define|#
directive|define
name|ATA_SIS5598
value|0x55981039
end_define

begin_define
define|#
directive|define
name|ATA_SIS5600
value|0x56001039
end_define

begin_define
define|#
directive|define
name|ATA_SIS530
value|0x05301039
end_define

begin_define
define|#
directive|define
name|ATA_SIS540
value|0x05401039
end_define

begin_define
define|#
directive|define
name|ATA_SIS550
value|0x05501039
end_define

begin_define
define|#
directive|define
name|ATA_SIS620
value|0x06201039
end_define

begin_define
define|#
directive|define
name|ATA_SIS630
value|0x06301039
end_define

begin_define
define|#
directive|define
name|ATA_SIS635
value|0x06351039
end_define

begin_define
define|#
directive|define
name|ATA_SIS633
value|0x06331039
end_define

begin_define
define|#
directive|define
name|ATA_SIS640
value|0x06401039
end_define

begin_define
define|#
directive|define
name|ATA_SIS645
value|0x06451039
end_define

begin_define
define|#
directive|define
name|ATA_SIS646
value|0x06461039
end_define

begin_define
define|#
directive|define
name|ATA_SIS648
value|0x06481039
end_define

begin_define
define|#
directive|define
name|ATA_SIS650
value|0x06501039
end_define

begin_define
define|#
directive|define
name|ATA_SIS651
value|0x06511039
end_define

begin_define
define|#
directive|define
name|ATA_SIS652
value|0x06521039
end_define

begin_define
define|#
directive|define
name|ATA_SIS655
value|0x06551039
end_define

begin_define
define|#
directive|define
name|ATA_SIS658
value|0x06581039
end_define

begin_define
define|#
directive|define
name|ATA_SIS730
value|0x07301039
end_define

begin_define
define|#
directive|define
name|ATA_SIS733
value|0x07331039
end_define

begin_define
define|#
directive|define
name|ATA_SIS735
value|0x07351039
end_define

begin_define
define|#
directive|define
name|ATA_SIS740
value|0x07401039
end_define

begin_define
define|#
directive|define
name|ATA_SIS745
value|0x07451039
end_define

begin_define
define|#
directive|define
name|ATA_SIS746
value|0x07461039
end_define

begin_define
define|#
directive|define
name|ATA_SIS748
value|0x07481039
end_define

begin_define
define|#
directive|define
name|ATA_SIS750
value|0x07501039
end_define

begin_define
define|#
directive|define
name|ATA_SIS751
value|0x07511039
end_define

begin_define
define|#
directive|define
name|ATA_SIS752
value|0x07521039
end_define

begin_define
define|#
directive|define
name|ATA_SIS755
value|0x07551039
end_define

begin_define
define|#
directive|define
name|ATA_SIS961
value|0x09611039
end_define

begin_define
define|#
directive|define
name|ATA_SIS962
value|0x09621039
end_define

begin_define
define|#
directive|define
name|ATA_SIS963
value|0x09631039
end_define

begin_define
define|#
directive|define
name|ATA_VIA_ID
value|0x1106
end_define

begin_define
define|#
directive|define
name|ATA_VIA82C571
value|0x05711106
end_define

begin_define
define|#
directive|define
name|ATA_VIA82C586
value|0x05861106
end_define

begin_define
define|#
directive|define
name|ATA_VIA82C596
value|0x05961106
end_define

begin_define
define|#
directive|define
name|ATA_VIA82C686
value|0x06861106
end_define

begin_define
define|#
directive|define
name|ATA_VIA8231
value|0x82311106
end_define

begin_define
define|#
directive|define
name|ATA_VIA8233
value|0x30741106
end_define

begin_define
define|#
directive|define
name|ATA_VIA8233A
value|0x31471106
end_define

begin_define
define|#
directive|define
name|ATA_VIA8233C
value|0x31091106
end_define

begin_define
define|#
directive|define
name|ATA_VIA8235
value|0x31771106
end_define

begin_define
define|#
directive|define
name|ATA_VIA8361
value|0x31121106
end_define

begin_define
define|#
directive|define
name|ATA_VIA8363
value|0x03051106
end_define

begin_define
define|#
directive|define
name|ATA_VIA8371
value|0x03911106
end_define

begin_define
define|#
directive|define
name|ATA_VIA8662
value|0x31021106
end_define

begin_comment
comment|/* chipset setup related defines */
end_comment

begin_define
define|#
directive|define
name|ATPOLD
value|1
end_define

begin_define
define|#
directive|define
name|ALIOLD
value|0x01
end_define

begin_define
define|#
directive|define
name|ALINEW
value|0x02
end_define

begin_define
define|#
directive|define
name|HPT366
value|0
end_define

begin_define
define|#
directive|define
name|HPT370
value|1
end_define

begin_define
define|#
directive|define
name|HPT372
value|2
end_define

begin_define
define|#
directive|define
name|HPT374
value|3
end_define

begin_define
define|#
directive|define
name|HPTOLD
value|0x01
end_define

begin_define
define|#
directive|define
name|PROLD
value|0
end_define

begin_define
define|#
directive|define
name|PRNEW
value|1
end_define

begin_define
define|#
directive|define
name|PRTX
value|2
end_define

begin_define
define|#
directive|define
name|PRMIO
value|3
end_define

begin_define
define|#
directive|define
name|PRIDX
value|4
end_define

begin_define
define|#
directive|define
name|PRTX4
value|0x01
end_define

begin_define
define|#
directive|define
name|PRSX4K
value|0x02
end_define

begin_define
define|#
directive|define
name|PRSX6K
value|0x04
end_define

begin_define
define|#
directive|define
name|PRSATA
value|0x08
end_define

begin_define
define|#
directive|define
name|PRDUAL
value|0x10
end_define

begin_define
define|#
directive|define
name|SWKS33
value|0
end_define

begin_define
define|#
directive|define
name|SWKS66
value|1
end_define

begin_define
define|#
directive|define
name|SWKS100
value|2
end_define

begin_define
define|#
directive|define
name|SIIMEMIO
value|1
end_define

begin_define
define|#
directive|define
name|SIIINTR
value|0x01
end_define

begin_define
define|#
directive|define
name|SIISETCLK
value|0x02
end_define

begin_define
define|#
directive|define
name|SIS_SOUTH
value|1
end_define

begin_define
define|#
directive|define
name|SIS133NEW
value|2
end_define

begin_define
define|#
directive|define
name|SIS133OLD
value|3
end_define

begin_define
define|#
directive|define
name|SIS100NEW
value|4
end_define

begin_define
define|#
directive|define
name|SIS100OLD
value|5
end_define

begin_define
define|#
directive|define
name|SIS66
value|6
end_define

begin_define
define|#
directive|define
name|SIS33
value|7
end_define

begin_define
define|#
directive|define
name|VIA33
value|0
end_define

begin_define
define|#
directive|define
name|VIA66
value|1
end_define

begin_define
define|#
directive|define
name|VIA100
value|2
end_define

begin_define
define|#
directive|define
name|VIA133
value|3
end_define

begin_define
define|#
directive|define
name|AMDNVIDIA
value|4
end_define

begin_define
define|#
directive|define
name|AMDCABLE
value|0x01
end_define

begin_define
define|#
directive|define
name|AMDBUG
value|0x02
end_define

begin_define
define|#
directive|define
name|NVIDIA
value|0x04
end_define

begin_define
define|#
directive|define
name|VIACLK
value|0x08
end_define

begin_define
define|#
directive|define
name|VIABUG
value|0x10
end_define

begin_comment
comment|/* global prototypes */
end_comment

begin_function_decl
name|int
name|ata_dmainit
parameter_list|(
name|struct
name|ata_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_dmastart
parameter_list|(
name|struct
name|ata_channel
modifier|*
parameter_list|,
name|caddr_t
parameter_list|,
name|int32_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_dmastop
parameter_list|(
name|struct
name|ata_channel
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_generic_ident
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_acard_ident
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_ali_ident
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_amd_ident
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_cyrix_ident
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_cypress_ident
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_highpoint_ident
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_intel_ident
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_nvidia_ident
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_promise_ident
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_serverworks_ident
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_sii_ident
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_sis_ident
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_via_ident
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

