begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2003 - 2008 SÃ¸ren Schmidt<sos@FreeBSD.org>  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT  * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,  * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY  * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF  * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.  *  * $FreeBSD$  */
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
specifier|const
name|char
modifier|*
name|text
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|ATA_PCI_MAX_CH
value|8
end_define

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
name|int
name|r_irq_rid
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
specifier|const
name|struct
name|ata_chip_id
modifier|*
name|chip
decl_stmt|;
name|int
name|legacy
decl_stmt|;
name|int
name|channels
decl_stmt|;
name|int
name|ichannels
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
name|chipdeinit
function_decl|)
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|suspend
function_decl|)
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|resume
function_decl|)
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ch_attach
function_decl|)
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ch_detach
function_decl|)
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ch_suspend
function_decl|)
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|ch_resume
function_decl|)
parameter_list|(
name|device_t
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
name|int
function_decl|(
modifier|*
name|setmode
function_decl|)
parameter_list|(
name|device_t
parameter_list|,
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
name|int
function_decl|(
modifier|*
name|getrev
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
name|ATA_PCI_MAX_CH
index|]
struct|;
name|void
modifier|*
name|chipset_data
decl_stmt|;
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
name|ATA_ALI_5228
value|0x522810b9
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
name|ATA_AMD5536
value|0x209a1022
end_define

begin_define
define|#
directive|define
name|ATA_AMD_HUDSON2_S1
value|0x78001022
end_define

begin_define
define|#
directive|define
name|ATA_AMD_HUDSON2_S2
value|0x78011022
end_define

begin_define
define|#
directive|define
name|ATA_AMD_HUDSON2_S3
value|0x78021022
end_define

begin_define
define|#
directive|define
name|ATA_AMD_HUDSON2_S4
value|0x78031022
end_define

begin_define
define|#
directive|define
name|ATA_AMD_HUDSON2_S5
value|0x78041022
end_define

begin_define
define|#
directive|define
name|ATA_AMD_HUDSON2
value|0x780c1022
end_define

begin_define
define|#
directive|define
name|ATA_ADAPTEC_ID
value|0x9005
end_define

begin_define
define|#
directive|define
name|ATA_ADAPTEC_1420
value|0x02419005
end_define

begin_define
define|#
directive|define
name|ATA_ADAPTEC_1430
value|0x02439005
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
name|ATA_ATI_IXP300_S1
value|0x436e1002
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
name|ATA_ATI_IXP600
value|0x438c1002
end_define

begin_define
define|#
directive|define
name|ATA_ATI_IXP600_S1
value|0x43801002
end_define

begin_define
define|#
directive|define
name|ATA_ATI_IXP700
value|0x439c1002
end_define

begin_define
define|#
directive|define
name|ATA_ATI_IXP700_S1
value|0x43901002
end_define

begin_define
define|#
directive|define
name|ATA_ATI_IXP700_S2
value|0x43911002
end_define

begin_define
define|#
directive|define
name|ATA_ATI_IXP700_S3
value|0x43921002
end_define

begin_define
define|#
directive|define
name|ATA_ATI_IXP700_S4
value|0x43931002
end_define

begin_define
define|#
directive|define
name|ATA_ATI_IXP800_S1
value|0x43941002
end_define

begin_define
define|#
directive|define
name|ATA_ATI_IXP800_S2
value|0x43951002
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
name|ATA_I82801GBM_S1
value|0x27c48086
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
name|ATA_I82801HB_S2
value|0x28258086
end_define

begin_define
define|#
directive|define
name|ATA_I82801HBM
value|0x28508086
end_define

begin_define
define|#
directive|define
name|ATA_I82801HBM_S1
value|0x28288086
end_define

begin_define
define|#
directive|define
name|ATA_I82801IB_S1
value|0x29208086
end_define

begin_define
define|#
directive|define
name|ATA_I82801IB_S3
value|0x29218086
end_define

begin_define
define|#
directive|define
name|ATA_I82801IB_R1
value|0x29258086
end_define

begin_define
define|#
directive|define
name|ATA_I82801IB_S2
value|0x29268086
end_define

begin_define
define|#
directive|define
name|ATA_I82801IBM_S1
value|0x29288086
end_define

begin_define
define|#
directive|define
name|ATA_I82801IBM_S2
value|0x292d8086
end_define

begin_define
define|#
directive|define
name|ATA_I82801JIB_S1
value|0x3a208086
end_define

begin_define
define|#
directive|define
name|ATA_I82801JIB_S2
value|0x3a268086
end_define

begin_define
define|#
directive|define
name|ATA_I82801JD_S1
value|0x3a008086
end_define

begin_define
define|#
directive|define
name|ATA_I82801JD_S2
value|0x3a068086
end_define

begin_define
define|#
directive|define
name|ATA_I82801JI_S1
value|0x3a208086
end_define

begin_define
define|#
directive|define
name|ATA_I82801JI_S2
value|0x3a268086
end_define

begin_define
define|#
directive|define
name|ATA_IBP_S1
value|0x3b208086
end_define

begin_define
define|#
directive|define
name|ATA_IBP_S2
value|0x3b218086
end_define

begin_define
define|#
directive|define
name|ATA_IBP_S3
value|0x3b268086
end_define

begin_define
define|#
directive|define
name|ATA_IBP_S4
value|0x3b288086
end_define

begin_define
define|#
directive|define
name|ATA_IBP_S5
value|0x3b2d8086
end_define

begin_define
define|#
directive|define
name|ATA_IBP_S6
value|0x3b2e8086
end_define

begin_define
define|#
directive|define
name|ATA_CPT_S1
value|0x1c008086
end_define

begin_define
define|#
directive|define
name|ATA_CPT_S2
value|0x1c018086
end_define

begin_define
define|#
directive|define
name|ATA_CPT_S3
value|0x1c088086
end_define

begin_define
define|#
directive|define
name|ATA_CPT_S4
value|0x1c098086
end_define

begin_define
define|#
directive|define
name|ATA_PBG_S1
value|0x1d008086
end_define

begin_define
define|#
directive|define
name|ATA_PBG_S2
value|0x1d088086
end_define

begin_define
define|#
directive|define
name|ATA_PPT_S1
value|0x1e008086
end_define

begin_define
define|#
directive|define
name|ATA_PPT_S2
value|0x1e018086
end_define

begin_define
define|#
directive|define
name|ATA_PPT_S3
value|0x1e088086
end_define

begin_define
define|#
directive|define
name|ATA_PPT_S4
value|0x1e098086
end_define

begin_define
define|#
directive|define
name|ATA_AVOTON_S1
value|0x1f208086
end_define

begin_define
define|#
directive|define
name|ATA_AVOTON_S2
value|0x1f218086
end_define

begin_define
define|#
directive|define
name|ATA_AVOTON_S3
value|0x1f308086
end_define

begin_define
define|#
directive|define
name|ATA_AVOTON_S4
value|0x1f318086
end_define

begin_define
define|#
directive|define
name|ATA_LPT_S1
value|0x8c008086
end_define

begin_define
define|#
directive|define
name|ATA_LPT_S2
value|0x8c018086
end_define

begin_define
define|#
directive|define
name|ATA_LPT_S3
value|0x8c088086
end_define

begin_define
define|#
directive|define
name|ATA_LPT_S4
value|0x8c098086
end_define

begin_define
define|#
directive|define
name|ATA_WCPT_S1
value|0x8c808086
end_define

begin_define
define|#
directive|define
name|ATA_WCPT_S2
value|0x8c818086
end_define

begin_define
define|#
directive|define
name|ATA_WCPT_S3
value|0x8c888086
end_define

begin_define
define|#
directive|define
name|ATA_WCPT_S4
value|0x8c898086
end_define

begin_define
define|#
directive|define
name|ATA_WELLS_S1
value|0x8d008086
end_define

begin_define
define|#
directive|define
name|ATA_WELLS_S2
value|0x8d088086
end_define

begin_define
define|#
directive|define
name|ATA_WELLS_S3
value|0x8d608086
end_define

begin_define
define|#
directive|define
name|ATA_WELLS_S4
value|0x8d688086
end_define

begin_define
define|#
directive|define
name|ATA_LPTLP_S1
value|0x9c008086
end_define

begin_define
define|#
directive|define
name|ATA_LPTLP_S2
value|0x9c018086
end_define

begin_define
define|#
directive|define
name|ATA_LPTLP_S3
value|0x9c088086
end_define

begin_define
define|#
directive|define
name|ATA_LPTLP_S4
value|0x9c098086
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
name|ATA_ISCH
value|0x811a8086
end_define

begin_define
define|#
directive|define
name|ATA_COLETOCRK_S1
value|0x23a18086
end_define

begin_define
define|#
directive|define
name|ATA_COLETOCRK_S2
value|0x23a68086
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
name|ATA_IT8213F
value|0x82131283
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
name|ATA_JMB362
value|0x2362197b
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
name|ATA_JMB368_2
value|0x0368197b
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
name|ATA_M88SE6101
value|0x610111ab
end_define

begin_define
define|#
directive|define
name|ATA_M88SE6102
value|0x610211ab
end_define

begin_define
define|#
directive|define
name|ATA_M88SE6111
value|0x611111ab
end_define

begin_define
define|#
directive|define
name|ATA_M88SE6121
value|0x612111ab
end_define

begin_define
define|#
directive|define
name|ATA_M88SE6141
value|0x614111ab
end_define

begin_define
define|#
directive|define
name|ATA_M88SE6145
value|0x614511ab
end_define

begin_define
define|#
directive|define
name|ATA_MARVELL2_ID
value|0x1b4b
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
name|ATA_NFORCE_MCP61
value|0x03ec10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP61_S1
value|0x03e710de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP61_S2
value|0x03f610de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP61_S3
value|0x03f710de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP65
value|0x044810de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP65_A0
value|0x044c10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP65_A1
value|0x044d10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP65_A2
value|0x044e10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP65_A3
value|0x044f10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP65_A4
value|0x045c10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP65_A5
value|0x045d10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP65_A6
value|0x045e10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP65_A7
value|0x045f10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP67
value|0x056010de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP67_A0
value|0x055010de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP67_A1
value|0x055110de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP67_A2
value|0x055210de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP67_A3
value|0x055310de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP67_A4
value|0x055410de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP67_A5
value|0x055510de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP67_A6
value|0x055610de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP67_A7
value|0x055710de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP67_A8
value|0x055810de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP67_A9
value|0x055910de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP67_AA
value|0x055A10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP67_AB
value|0x055B10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP67_AC
value|0x058410de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP73
value|0x056c10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP73_A0
value|0x07f010de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP73_A1
value|0x07f110de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP73_A2
value|0x07f210de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP73_A3
value|0x07f310de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP73_A4
value|0x07f410de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP73_A5
value|0x07f510de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP73_A6
value|0x07f610de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP73_A7
value|0x07f710de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP73_A8
value|0x07f810de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP73_A9
value|0x07f910de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP73_AA
value|0x07fa10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP73_AB
value|0x07fb10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP77
value|0x075910de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP77_A0
value|0x0ad010de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP77_A1
value|0x0ad110de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP77_A2
value|0x0ad210de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP77_A3
value|0x0ad310de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP77_A4
value|0x0ad410de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP77_A5
value|0x0ad510de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP77_A6
value|0x0ad610de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP77_A7
value|0x0ad710de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP77_A8
value|0x0ad810de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP77_A9
value|0x0ad910de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP77_AA
value|0x0ada10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP77_AB
value|0x0adb10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP79_A0
value|0x0ab410de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP79_A1
value|0x0ab510de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP79_A2
value|0x0ab610de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP79_A3
value|0x0ab710de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP79_A4
value|0x0ab810de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP79_A5
value|0x0ab910de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP79_A6
value|0x0aba10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP79_A7
value|0x0abb10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP79_A8
value|0x0abc10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP79_A9
value|0x0abd10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP79_AA
value|0x0abe10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP79_AB
value|0x0abf10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP89_A0
value|0x0d8410de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP89_A1
value|0x0d8510de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP89_A2
value|0x0d8610de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP89_A3
value|0x0d8710de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP89_A4
value|0x0d8810de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP89_A5
value|0x0d8910de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP89_A6
value|0x0d8a10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP89_A7
value|0x0d8b10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP89_A8
value|0x0d8c10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP89_A9
value|0x0d8d10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP89_AA
value|0x0d8e10de
end_define

begin_define
define|#
directive|define
name|ATA_NFORCE_MCP89_AB
value|0x0d8f10de
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
name|ATA_VIA8237S
value|0x53371106
end_define

begin_define
define|#
directive|define
name|ATA_VIA8237_5372
value|0x53721106
end_define

begin_define
define|#
directive|define
name|ATA_VIA8237_7372
value|0x73721106
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

begin_define
define|#
directive|define
name|ATA_VIACX700IDE
value|0x05811106
end_define

begin_define
define|#
directive|define
name|ATA_VIACX700
value|0x83241106
end_define

begin_define
define|#
directive|define
name|ATA_VIASATAIDE
value|0x53241106
end_define

begin_define
define|#
directive|define
name|ATA_VIAVX800
value|0x83531106
end_define

begin_define
define|#
directive|define
name|ATA_VIASATAIDE2
value|0xc4091106
end_define

begin_define
define|#
directive|define
name|ATA_VIAVX855
value|0x84091106
end_define

begin_define
define|#
directive|define
name|ATA_VIASATAIDE3
value|0x90011106
end_define

begin_define
define|#
directive|define
name|ATA_VIAVX900
value|0x84101106
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
name|int
name|ata_pci_suspend
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_pci_resume
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_pci_read_ivar
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|which
parameter_list|,
name|uintptr_t
modifier|*
name|result
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_pci_write_ivar
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|which
parameter_list|,
name|uintptr_t
name|value
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|ata_pci_read_config
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|reg
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_pci_write_config
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|int
name|reg
parameter_list|,
name|uint32_t
name|val
parameter_list|,
name|int
name|width
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_pci_print_child
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_pci_child_location_str
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|device_t
name|child
parameter_list|,
name|char
modifier|*
name|buf
parameter_list|,
name|size_t
name|buflen
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
name|rman_res_t
name|start
parameter_list|,
name|rman_res_t
name|end
parameter_list|,
name|rman_res_t
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
name|driver_filter_t
modifier|*
name|filter
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
name|ata_pci_ch_attach
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_pci_ch_detach
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
name|ata_pci_hw
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
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_pci_dmafini
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|ata_pcivendor2str
parameter_list|(
name|device_t
name|dev
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

begin_function_decl
name|void
name|ata_generic_intr
parameter_list|(
name|void
modifier|*
name|data
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_generic_chipinit
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_generic_setmode
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|int
name|target
parameter_list|,
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_setup_interrupt
parameter_list|(
name|device_t
name|dev
parameter_list|,
name|void
modifier|*
name|intr_func
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ata_set_desc
parameter_list|(
name|device_t
name|dev
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|ata_chip_id
modifier|*
name|ata_match_chip
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|struct
name|ata_chip_id
modifier|*
name|index
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|struct
name|ata_chip_id
modifier|*
name|ata_find_chip
parameter_list|(
name|device_t
name|dev
parameter_list|,
specifier|const
name|struct
name|ata_chip_id
modifier|*
name|index
parameter_list|,
name|int
name|slot
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ata_mode2idx
parameter_list|(
name|int
name|mode
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* global prototypes from chipsets/ata-*.c */
end_comment

begin_function_decl
name|int
name|ata_sii_chipinit
parameter_list|(
name|device_t
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* externs */
end_comment

begin_decl_stmt
specifier|extern
name|devclass_t
name|ata_pci_devclass
decl_stmt|;
end_decl_stmt

begin_expr_stmt
name|MALLOC_DECLARE
argument_list|(
name|M_ATAPCI
argument_list|)
expr_stmt|;
end_expr_stmt

begin_comment
comment|/* macro for easy definition of all driver module stuff */
end_comment

begin_define
define|#
directive|define
name|ATA_DECLARE_DRIVER
parameter_list|(
name|dname
parameter_list|)
define|\
value|static device_method_t __CONCAT(dname,_methods)[] = { \     DEVMETHOD(device_probe,     __CONCAT(dname,_probe)), \     DEVMETHOD(device_attach,    ata_pci_attach), \     DEVMETHOD(device_detach,    ata_pci_detach), \     DEVMETHOD(device_suspend,   ata_pci_suspend), \     DEVMETHOD(device_resume,    ata_pci_resume), \     DEVMETHOD(device_shutdown,  bus_generic_shutdown), \     DEVMETHOD(bus_read_ivar,		ata_pci_read_ivar), \     DEVMETHOD(bus_write_ivar,		ata_pci_write_ivar), \     DEVMETHOD(bus_alloc_resource,       ata_pci_alloc_resource), \     DEVMETHOD(bus_release_resource,     ata_pci_release_resource), \     DEVMETHOD(bus_activate_resource,    bus_generic_activate_resource), \     DEVMETHOD(bus_deactivate_resource,  bus_generic_deactivate_resource), \     DEVMETHOD(bus_setup_intr,           ata_pci_setup_intr), \     DEVMETHOD(bus_teardown_intr,        ata_pci_teardown_intr), \     DEVMETHOD(pci_read_config,		ata_pci_read_config), \     DEVMETHOD(pci_write_config,		ata_pci_write_config), \     DEVMETHOD(bus_print_child,		ata_pci_print_child), \     DEVMETHOD(bus_child_location_str,	ata_pci_child_location_str), \     DEVMETHOD_END \ }; \ static driver_t __CONCAT(dname,_driver) = { \         "atapci", \         __CONCAT(dname,_methods), \         sizeof(struct ata_pci_controller) \ }; \ DRIVER_MODULE(dname, pci, __CONCAT(dname,_driver), ata_pci_devclass, NULL, NULL); \ MODULE_VERSION(dname, 1); \ MODULE_DEPEND(dname, ata, 1, 1, 1); \ MODULE_DEPEND(dname, atapci, 1, 1, 1);
end_define

end_unit

