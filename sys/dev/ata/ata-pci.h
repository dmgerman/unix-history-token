begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 - 2007 Søren Schmidt<sos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
name|device_t
name|dev
decl_stmt|;
name|int
name|r_type1
decl_stmt|;
name|int
name|r_rid1
decl_stmt|;
name|struct
name|resource
modifier|*
name|r_res1
decl_stmt|;
name|int
name|r_type2
decl_stmt|;
name|int
name|r_rid2
decl_stmt|;
name|struct
name|resource
modifier|*
name|r_res2
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
name|channels
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
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|locking
function_decl|)
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|reset
function_decl|)
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|dmainit
function_decl|)
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
name|void
function_decl|(
modifier|*
name|setmode
function_decl|)
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|)
function_decl|;
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
literal|8
index|]
struct|;
comment|/* XXX SOS max ch# for now */
block|}
struct|;
end_struct

begin_comment
comment|/* structure for SATA connection update hotplug/hotswap support */
end_comment

begin_struct
struct|struct
name|ata_connect_task
block|{
name|struct
name|task
name|task
decl_stmt|;
name|device_t
name|dev
decl_stmt|;
name|int
name|action
decl_stmt|;
define|#
directive|define
name|ATA_C_ATTACH
value|1
define|#
directive|define
name|ATA_C_DETACH
value|2
block|}
struct|;
end_struct

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
name|ATA_ALI_1533
value|0x153310b9
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
name|ATA_ALI_5281
value|0x528110b9
end_define

begin_define
define|#
directive|define
name|ATA_ALI_5287
value|0x528710b9
end_define

begin_define
define|#
directive|define
name|ATA_ALI_5288
value|0x528810b9
end_define

begin_define
define|#
directive|define
name|ATA_ALI_5289
value|0x528910b9
end_define

begin_define
define|#
directive|define
name|ATA_ATI_ID
value|0x1002
end_define

begin_define
define|#
directive|define
name|ATA_ATI_IXP200
value|0x43491002
end_define

begin_define
define|#
directive|define
name|ATA_ATI_IXP300
value|0x43691002
end_define

begin_define
define|#
directive|define
name|ATA_ATI_IXP400
value|0x43761002
end_define

begin_define
define|#
directive|define
name|ATA_ATI_IXP300_S1
value|0x436e1002
end_define

begin_define
define|#
directive|define
name|ATA_ATI_IXP400_S1
value|0x43791002
end_define

begin_define
define|#
directive|define
name|ATA_ATI_IXP400_S2
value|0x437a1002
end_define

begin_define
define|#
directive|define
name|ATA_CENATEK_ID
value|0x16ca
end_define

begin_define
define|#
directive|define
name|ATA_CENATEK_ROCKET
value|0x000116ca
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
name|ATA_DEC_21150_1
value|0x00231011
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
name|ATA_I82801EB_S1
value|0x24d18086
end_define

begin_define
define|#
directive|define
name|ATA_I82801EB_R1
value|0x24df8086
end_define

begin_define
define|#
directive|define
name|ATA_I6300ESB
value|0x25a28086
end_define

begin_define
define|#
directive|define
name|ATA_I6300ESB_S1
value|0x25a38086
end_define

begin_define
define|#
directive|define
name|ATA_I6300ESB_R1
value|0x25b08086
end_define

begin_define
define|#
directive|define
name|ATA_I63XXESB2
value|0x269e8086
end_define

begin_define
define|#
directive|define
name|ATA_I63XXESB2_S1
value|0x26808086
end_define

begin_define
define|#
directive|define
name|ATA_I63XXESB2_S2
value|0x26818086
end_define

begin_define
define|#
directive|define
name|ATA_I63XXESB2_R1
value|0x26828086
end_define

begin_define
define|#
directive|define
name|ATA_I63XXESB2_R2
value|0x26838086
end_define

begin_define
define|#
directive|define
name|ATA_I82801FB
value|0x266f8086
end_define

begin_define
define|#
directive|define
name|ATA_I82801FB_S1
value|0x26518086
end_define

begin_define
define|#
directive|define
name|ATA_I82801FB_R1
value|0x26528086
end_define

begin_define
define|#
directive|define
name|ATA_I82801FBM
value|0x26538086
end_define

begin_define
define|#
directive|define
name|ATA_I82801GB
value|0x27df8086
end_define

begin_define
define|#
directive|define
name|ATA_I82801GB_S1
value|0x27c08086
end_define

begin_define
define|#
directive|define
name|ATA_I82801GB_AH
value|0x27c18086
end_define

begin_define
define|#
directive|define
name|ATA_I82801GB_R1
value|0x27c38086
end_define

begin_define
define|#
directive|define
name|ATA_I82801GBM_S1
value|0x27c48086
end_define

begin_define
define|#
directive|define
name|ATA_I82801GBM_AH
value|0x27c58086
end_define

begin_define
define|#
directive|define
name|ATA_I82801GBM_R1
value|0x27c68086
end_define

begin_define
define|#
directive|define
name|ATA_I82801HB_S1
value|0x28208086
end_define

begin_define
define|#
directive|define
name|ATA_I82801HB_AH6
value|0x28218086
end_define

begin_define
define|#
directive|define
name|ATA_I82801HB_R1
value|0x28228086
end_define

begin_define
define|#
directive|define
name|ATA_I82801HB_AH4
value|0x28248086
end_define

begin_define
define|#
directive|define
name|ATA_I82801HB_S2
value|0x28258086
end_define

begin_define
define|#
directive|define
name|ATA_I82801HBM_S1
value|0x28298086
end_define

begin_define
define|#
directive|define
name|ATA_I82801HBM_S2
value|0x282a8086
end_define

begin_define
define|#
directive|define
name|ATA_I31244
value|0x32008086
end_define

begin_define
define|#
directive|define
name|ATA_ITE_ID
value|0x1283
end_define

begin_define
define|#
directive|define
name|ATA_IT8211F
value|0x82111283
end_define

begin_define
define|#
directive|define
name|ATA_IT8212F
value|0x82121283
end_define

begin_define
define|#
directive|define
name|ATA_JMICRON_ID
value|0x197b
end_define

begin_define
define|#
directive|define
name|ATA_JMB360
value|0x2360197b
end_define

begin_define
define|#
directive|define
name|ATA_JMB361
value|0x2361197b
end_define

begin_define
define|#
directive|define
name|ATA_JMB363
value|0x2363197b
end_define

begin_define
define|#
directive|define
name|ATA_JMB365
value|0x2365197b
end_define

begin_define
define|#
directive|define
name|ATA_JMB366
value|0x2366197b
end_define

begin_define
define|#
directive|define
name|ATA_JMB368
value|0x2368197b
end_define

begin_define
define|#
directive|define
name|ATA_MARVELL_ID
value|0x11ab
end_define

begin_define
define|#
directive|define
name|ATA_M88SX5040
value|0x504011ab
end_define

begin_define
define|#
directive|define
name|ATA_M88SX5041
value|0x504111ab
end_define

begin_define
define|#
directive|define
name|ATA_M88SX5080
value|0x508011ab
end_define

begin_define
define|#
directive|define
name|ATA_M88SX5081
value|0x508111ab
end_define

begin_define
define|#
directive|define
name|ATA_M88SX6041
value|0x604111ab
end_define

begin_define
define|#
directive|define
name|ATA_M88SX6081
value|0x608111ab
end_define

begin_define
define|#
directive|define
name|ATA_M88SX6101
value|0x610111ab
end_define

begin_define
define|#
directive|define
name|ATA_M88SX6145
value|0x614511ab
end_define

begin_define
define|#
directive|define
name|ATA_MICRON_ID
value|0x1042
end_define

begin_define
define|#
directive|define
name|ATA_MICRON_RZ1000
value|0x10001042
end_define

begin_define
define|#
directive|define
name|ATA_MICRON_RZ1001
value|0x10011042
end_define

begin_define
define|#
directive|define
name|ATA_NATIONAL_ID
value|0x100b
end_define

begin_define
define|#
directive|define
name|ATA_SC1100
value|0x0502100b
end_define

begin_define
define|#
directive|define
name|ATA_NETCELL_ID
value|0x169c
end_define

begin_define
define|#
directive|define
name|ATA_NETCELL_SR
value|0x0044169c
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
name|ATA_NFORCE2_PRO
value|0x008510de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE2_PRO_S1
value|0x008e10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE3
value|0x00d510de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE3_PRO
value|0x00e510de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE3_PRO_S1
value|0x00e310de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE3_PRO_S2
value|0x00ee10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP04
value|0x003510de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP04_S1
value|0x003610de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP04_S2
value|0x003e10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_CK804
value|0x005310de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_CK804_S1
value|0x005410de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_CK804_S2
value|0x005510de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP51
value|0x026510de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP51_S1
value|0x026610de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP51_S2
value|0x026710de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP55
value|0x036e10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP55_S1
value|0x037e10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP55_S2
value|0x037f10de
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
name|ATA_PDC20571
value|0x3571105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20575
value|0x3d75105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20579
value|0x3574105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20771
value|0x3570105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC40518
value|0x3d18105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC40519
value|0x3519105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC40718
value|0x3d17105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC40719
value|0x3515105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC40775
value|0x3d73105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC40779
value|0x3577105a
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
name|ATA_PDC20622
value|0x6622105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC20624
value|0x6624105a
end_define

begin_define
define|#
directive|define
name|ATA_PDC81518
value|0x8002105a
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
name|ATA_ROSB4_ISA
value|0x02001166
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
name|ATA_HT1000
value|0x02141166
end_define

begin_define
define|#
directive|define
name|ATA_HT1000_S1
value|0x024b1166
end_define

begin_define
define|#
directive|define
name|ATA_HT1000_S2
value|0x024a1166
end_define

begin_define
define|#
directive|define
name|ATA_K2
value|0x02401166
end_define

begin_define
define|#
directive|define
name|ATA_FRODO4
value|0x02411166
end_define

begin_define
define|#
directive|define
name|ATA_FRODO8
value|0x02421166
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
name|ATA_SII3114
value|0x31141095
end_define

begin_define
define|#
directive|define
name|ATA_SII3512
value|0x35121095
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
name|ATA_SII3112_1
value|0x02401095
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
name|ATA_SIS5517
value|0x55171039
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
name|ATA_SIS661
value|0x06611039
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
name|ATA_SIS964
value|0x09641039
end_define

begin_define
define|#
directive|define
name|ATA_SIS965
value|0x09651039
end_define

begin_define
define|#
directive|define
name|ATA_SIS180
value|0x01801039
end_define

begin_define
define|#
directive|define
name|ATA_SIS181
value|0x01811039
end_define

begin_define
define|#
directive|define
name|ATA_SIS182
value|0x01821039
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
name|ATA_VIA8237
value|0x32271106
end_define

begin_define
define|#
directive|define
name|ATA_VIA8237A
value|0x05911106
end_define

begin_define
define|#
directive|define
name|ATA_VIA8251
value|0x33491106
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

begin_define
define|#
directive|define
name|ATA_VIA6410
value|0x31641106
end_define

begin_define
define|#
directive|define
name|ATA_VIA6420
value|0x31491106
end_define

begin_define
define|#
directive|define
name|ATA_VIA6421
value|0x32491106
end_define

begin_comment
comment|/* chipset setup related defines */
end_comment

begin_define
define|#
directive|define
name|AHCI
value|1
end_define

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
name|ALISATA
value|0x04
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
name|MV50XX
value|50
end_define

begin_define
define|#
directive|define
name|MV60XX
value|60
end_define

begin_define
define|#
directive|define
name|MV61XX
value|61
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
name|PRTX4
value|0x01
end_define

begin_define
define|#
directive|define
name|PRSX4X
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
name|PRPATA
value|0x08
end_define

begin_define
define|#
directive|define
name|PRCMBO
value|0x10
end_define

begin_define
define|#
directive|define
name|PRCMBO2
value|0x20
end_define

begin_define
define|#
directive|define
name|PRSATA
value|0x40
end_define

begin_define
define|#
directive|define
name|PRSATA2
value|0x80
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
name|SWKSMIO
value|3
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
name|SIIBUG
value|0x04
end_define

begin_define
define|#
directive|define
name|SII4CH
value|0x08
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
name|SISSATA
value|2
end_define

begin_define
define|#
directive|define
name|SIS133NEW
value|3
end_define

begin_define
define|#
directive|define
name|SIS133OLD
value|4
end_define

begin_define
define|#
directive|define
name|SIS100NEW
value|5
end_define

begin_define
define|#
directive|define
name|SIS100OLD
value|6
end_define

begin_define
define|#
directive|define
name|SIS66
value|7
end_define

begin_define
define|#
directive|define
name|SIS33
value|8
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
value|0x0001
end_define

begin_define
define|#
directive|define
name|AMDBUG
value|0x0002
end_define

begin_define
define|#
directive|define
name|NVIDIA
value|0x0004
end_define

begin_define
define|#
directive|define
name|NV4
value|0x0010
end_define

begin_define
define|#
directive|define
name|NVQ
value|0x0020
end_define

begin_define
define|#
directive|define
name|VIACLK
value|0x0100
end_define

begin_define
define|#
directive|define
name|VIABUG
value|0x0200
end_define

begin_define
define|#
directive|define
name|VIABAR
value|0x0400
end_define

begin_define
define|#
directive|define
name|VIAAHCI
value|0x0800
end_define

begin_comment
comment|/* global prototypes ata-pci.c */
end_comment

begin_function_decl
name|int
name|ata_pci_probe
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_pci_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_pci_detach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|struct
name|resource
modifier|*
name|ata_pci_alloc_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|type
parameter_list|,
name|int
modifier|*
name|rid
parameter_list|,
name|u_long
name|start
parameter_list|,
name|u_long
name|end
parameter_list|,
name|u_long
name|count
parameter_list|,
name|u_int
name|flags
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_pci_release_resource
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|type
parameter_list|,
name|int
name|rid
parameter_list|,
name|struct
name|resource
modifier|*
name|r
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_pci_setup_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|struct
name|resource
modifier|*
name|irq
parameter_list|,
name|int
name|flags
parameter_list|,
name|driver_intr_t
modifier|*
name|function
parameter_list|,
name|void
modifier|*
name|argument
parameter_list|,
name|void
modifier|*
modifier|*
name|cookiep
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_pci_teardown_intr
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|struct
name|resource
modifier|*
name|irq
parameter_list|,
name|void
modifier|*
name|cookie
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_pci_allocate
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_pci_hw
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_pci_status
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_pci_dmainit
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* global prototypes ata-chipset.c */
end_comment

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
name|ata_ati_ident
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
name|ata_ite_ident
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_jmicron_ident
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_marvell_ident
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_national_ident
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
name|ata_netcell_ident
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

begin_function_decl
name|int
name|ata_legacy
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* global prototypes ata-dma.c */
end_comment

begin_function_decl
name|void
name|ata_dmainit
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

