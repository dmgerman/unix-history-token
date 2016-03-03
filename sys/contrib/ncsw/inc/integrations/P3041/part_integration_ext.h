begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/******************************************************************************   © 1995-2003, 2004, 2005-2011 Freescale Semiconductor, Inc.  All rights reserved.   This is proprietary source code of Freescale Semiconductor Inc.,  and its use is subject to the NetComm Device Drivers EULA.  The copyright notice above does not evidence any actual or intended  publication of such source code.   ALTERNATIVELY, redistribution and use in source and binary forms, with  or without modification, are permitted provided that the following  conditions are met:      * Redistributions of source code must retain the above copyright        notice, this list of conditions and the following disclaimer.      * Redistributions in binary form must reproduce the above copyright        notice, this list of conditions and the following disclaimer in the        documentation and/or other materials provided with the distribution.      * Neither the name of Freescale Semiconductor nor the        names of its contributors may be used to endorse or promote products        derived from this software without specific prior written permission.   THIS SOFTWARE IS PROVIDED BY Freescale Semiconductor ``AS IS'' AND ANY  EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  DISCLAIMED. IN NO EVENT SHALL Freescale Semiconductor BE LIABLE FOR ANY  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND  ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.   **************************************************************************/
end_comment

begin_comment
comment|/**   @File          part_integration_ext.h   @Description   P3041 external definitions and structures. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|__PART_INTEGRATION_EXT_H
end_ifndef

begin_define
define|#
directive|define
name|__PART_INTEGRATION_EXT_H
end_define

begin_include
include|#
directive|include
file|"std_ext.h"
end_include

begin_include
include|#
directive|include
file|"ddr_std_ext.h"
end_include

begin_include
include|#
directive|include
file|"enet_ext.h"
end_include

begin_include
include|#
directive|include
file|"dpaa_integration_ext.h"
end_include

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         P3041_chip_id P3041 Application Programming Interface   @Description   P3041 Chip functions,definitions and enums.   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CORE_E500MC
end_define

begin_define
define|#
directive|define
name|INTG_MAX_NUM_OF_CORES
value|4
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Module types. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_ModuleId
block|{
name|e_MODULE_ID_DUART_1
init|=
literal|0
block|,
name|e_MODULE_ID_DUART_2
block|,
name|e_MODULE_ID_DUART_3
block|,
name|e_MODULE_ID_DUART_4
block|,
name|e_MODULE_ID_LAW
block|,
name|e_MODULE_ID_LBC
block|,
name|e_MODULE_ID_PAMU
block|,
name|e_MODULE_ID_QM
block|,
comment|/**< Queue manager module */
name|e_MODULE_ID_BM
block|,
comment|/**< Buffer manager module */
name|e_MODULE_ID_QM_CE_PORTAL_0
block|,
name|e_MODULE_ID_QM_CI_PORTAL_0
block|,
name|e_MODULE_ID_QM_CE_PORTAL_1
block|,
name|e_MODULE_ID_QM_CI_PORTAL_1
block|,
name|e_MODULE_ID_QM_CE_PORTAL_2
block|,
name|e_MODULE_ID_QM_CI_PORTAL_2
block|,
name|e_MODULE_ID_QM_CE_PORTAL_3
block|,
name|e_MODULE_ID_QM_CI_PORTAL_3
block|,
name|e_MODULE_ID_QM_CE_PORTAL_4
block|,
name|e_MODULE_ID_QM_CI_PORTAL_4
block|,
name|e_MODULE_ID_QM_CE_PORTAL_5
block|,
name|e_MODULE_ID_QM_CI_PORTAL_5
block|,
name|e_MODULE_ID_QM_CE_PORTAL_6
block|,
name|e_MODULE_ID_QM_CI_PORTAL_6
block|,
name|e_MODULE_ID_QM_CE_PORTAL_7
block|,
name|e_MODULE_ID_QM_CI_PORTAL_7
block|,
name|e_MODULE_ID_QM_CE_PORTAL_8
block|,
name|e_MODULE_ID_QM_CI_PORTAL_8
block|,
name|e_MODULE_ID_QM_CE_PORTAL_9
block|,
name|e_MODULE_ID_QM_CI_PORTAL_9
block|,
name|e_MODULE_ID_BM_CE_PORTAL_0
block|,
name|e_MODULE_ID_BM_CI_PORTAL_0
block|,
name|e_MODULE_ID_BM_CE_PORTAL_1
block|,
name|e_MODULE_ID_BM_CI_PORTAL_1
block|,
name|e_MODULE_ID_BM_CE_PORTAL_2
block|,
name|e_MODULE_ID_BM_CI_PORTAL_2
block|,
name|e_MODULE_ID_BM_CE_PORTAL_3
block|,
name|e_MODULE_ID_BM_CI_PORTAL_3
block|,
name|e_MODULE_ID_BM_CE_PORTAL_4
block|,
name|e_MODULE_ID_BM_CI_PORTAL_4
block|,
name|e_MODULE_ID_BM_CE_PORTAL_5
block|,
name|e_MODULE_ID_BM_CI_PORTAL_5
block|,
name|e_MODULE_ID_BM_CE_PORTAL_6
block|,
name|e_MODULE_ID_BM_CI_PORTAL_6
block|,
name|e_MODULE_ID_BM_CE_PORTAL_7
block|,
name|e_MODULE_ID_BM_CI_PORTAL_7
block|,
name|e_MODULE_ID_BM_CE_PORTAL_8
block|,
name|e_MODULE_ID_BM_CI_PORTAL_8
block|,
name|e_MODULE_ID_BM_CE_PORTAL_9
block|,
name|e_MODULE_ID_BM_CI_PORTAL_9
block|,
name|e_MODULE_ID_FM
block|,
comment|/**< Frame manager module */
name|e_MODULE_ID_FM_RTC
block|,
comment|/**< FM Real-Time-Clock */
name|e_MODULE_ID_FM_MURAM
block|,
comment|/**< FM Multi-User-RAM */
name|e_MODULE_ID_FM_BMI
block|,
comment|/**< FM BMI block */
name|e_MODULE_ID_FM_QMI
block|,
comment|/**< FM QMI block */
name|e_MODULE_ID_FM_PARSER
block|,
comment|/**< FM parser block */
name|e_MODULE_ID_FM_PORT_HO1
block|,
comment|/**< FM Host-command/offline-parsing port block */
name|e_MODULE_ID_FM_PORT_HO2
block|,
comment|/**< FM Host-command/offline-parsing port block */
name|e_MODULE_ID_FM_PORT_HO3
block|,
comment|/**< FM Host-command/offline-parsing port block */
name|e_MODULE_ID_FM_PORT_HO4
block|,
comment|/**< FM Host-command/offline-parsing port block */
name|e_MODULE_ID_FM_PORT_HO5
block|,
comment|/**< FM Host-command/offline-parsing port block */
name|e_MODULE_ID_FM_PORT_HO6
block|,
comment|/**< FM Host-command/offline-parsing port block */
name|e_MODULE_ID_FM_PORT_HO7
block|,
comment|/**< FM Host-command/offline-parsing port block */
name|e_MODULE_ID_FM_PORT_1GRx1
block|,
comment|/**< FM Rx 1G MAC port block */
name|e_MODULE_ID_FM_PORT_1GRx2
block|,
comment|/**< FM Rx 1G MAC port block */
name|e_MODULE_ID_FM_PORT_1GRx3
block|,
comment|/**< FM Rx 1G MAC port block */
name|e_MODULE_ID_FM_PORT_1GRx4
block|,
comment|/**< FM Rx 1G MAC port block */
name|e_MODULE_ID_FM_PORT_1GRx5
block|,
comment|/**< FM Rx 1G MAC port block */
name|e_MODULE_ID_FM_PORT_10GRx
block|,
comment|/**< FM Rx 10G MAC port block */
name|e_MODULE_ID_FM_PORT_1GTx1
block|,
comment|/**< FM Tx 1G MAC port block */
name|e_MODULE_ID_FM_PORT_1GTx2
block|,
comment|/**< FM Tx 1G MAC port block */
name|e_MODULE_ID_FM_PORT_1GTx3
block|,
comment|/**< FM Tx 1G MAC port block */
name|e_MODULE_ID_FM_PORT_1GTx4
block|,
comment|/**< FM Tx 1G MAC port block */
name|e_MODULE_ID_FM_PORT_1GTx5
block|,
comment|/**< FM Tx 1G MAC port block */
name|e_MODULE_ID_FM_PORT_10GTx
block|,
comment|/**< FM Tx 10G MAC port block */
name|e_MODULE_ID_FM_PLCR
block|,
comment|/**< FM Policer */
name|e_MODULE_ID_FM_KG
block|,
comment|/**< FM Keygen */
name|e_MODULE_ID_FM_DMA
block|,
comment|/**< FM DMA */
name|e_MODULE_ID_FM_FPM
block|,
comment|/**< FM FPM */
name|e_MODULE_ID_FM_IRAM
block|,
comment|/**< FM Instruction-RAM */
name|e_MODULE_ID_FM_1GMDIO1
block|,
comment|/**< FM 1G MDIO MAC 1*/
name|e_MODULE_ID_FM_1GMDIO2
block|,
comment|/**< FM 1G MDIO MAC 2*/
name|e_MODULE_ID_FM_1GMDIO3
block|,
comment|/**< FM 1G MDIO MAC 3*/
name|e_MODULE_ID_FM_1GMDIO4
block|,
comment|/**< FM 1G MDIO MAC 4*/
name|e_MODULE_ID_FM_1GMDIO5
block|,
comment|/**< FM 1G MDIO MAC 5*/
name|e_MODULE_ID_FM_10GMDIO
block|,
comment|/**< FM 10G MDIO */
name|e_MODULE_ID_FM_PRS_IRAM
block|,
comment|/**< FM SW-parser Instruction-RAM */
name|e_MODULE_ID_FM_1GMAC1
block|,
comment|/**< FM 1G MAC #1 */
name|e_MODULE_ID_FM_1GMAC2
block|,
comment|/**< FM 1G MAC #2 */
name|e_MODULE_ID_FM_1GMAC3
block|,
comment|/**< FM 1G MAC #3 */
name|e_MODULE_ID_FM_1GMAC4
block|,
comment|/**< FM 1G MAC #4 */
name|e_MODULE_ID_FM_1GMAC5
block|,
comment|/**< FM 1G MAC #5 */
name|e_MODULE_ID_FM_10GMAC
block|,
comment|/**< FM 10G MAC */
name|e_MODULE_ID_SEC_GEN
block|,
comment|/**< SEC 4.0 General registers      */
name|e_MODULE_ID_SEC_QI
block|,
comment|/**< SEC 4.0 QI registers           */
name|e_MODULE_ID_SEC_JQ0
block|,
comment|/**< SEC 4.0 JQ-0 registers         */
name|e_MODULE_ID_SEC_JQ1
block|,
comment|/**< SEC 4.0 JQ-1 registers         */
name|e_MODULE_ID_SEC_JQ2
block|,
comment|/**< SEC 4.0 JQ-2 registers         */
name|e_MODULE_ID_SEC_JQ3
block|,
comment|/**< SEC 4.0 JQ-3 registers         */
name|e_MODULE_ID_SEC_RTIC
block|,
comment|/**< SEC 4.0 RTIC registers         */
name|e_MODULE_ID_SEC_DECO0_CCB0
block|,
comment|/**< SEC 4.0 DECO-0/CCB-0 registers */
name|e_MODULE_ID_SEC_DECO1_CCB1
block|,
comment|/**< SEC 4.0 DECO-1/CCB-1 registers */
name|e_MODULE_ID_SEC_DECO2_CCB2
block|,
comment|/**< SEC 4.0 DECO-2/CCB-2 registers */
name|e_MODULE_ID_SEC_DECO3_CCB3
block|,
comment|/**< SEC 4.0 DECO-3/CCB-3 registers */
name|e_MODULE_ID_SEC_DECO4_CCB4
block|,
comment|/**< SEC 4.0 DECO-4/CCB-4 registers */
name|e_MODULE_ID_PIC
block|,
comment|/**< PIC */
name|e_MODULE_ID_GPIO
block|,
comment|/**< GPIO */
name|e_MODULE_ID_SERDES
block|,
comment|/**< SERDES */
name|e_MODULE_ID_CPC
block|,
comment|/**< CoreNet-Platform-Cache */
name|e_MODULE_ID_DUMMY_LAST
block|}
name|e_ModuleId
typedef|;
end_typedef

begin_define
define|#
directive|define
name|NUM_OF_MODULES
value|e_MODULE_ID_DUMMY_LAST
end_define

begin_comment
comment|/* Offsets relative to CCSR base */
end_comment

begin_define
define|#
directive|define
name|P3041_OFFSET_LAW
value|0x00000c00
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_DDR
value|0x00008000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_CPC
value|0x00010000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_CCM
value|0x00018000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_PAMU
value|0x00020000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_PIC
value|0x00040000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_GUTIL
value|0x000e0000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_RCPM
value|0x000e2000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_SERDES
value|0x000ea000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_DMA1
value|0x00100100
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_DMA2
value|0x00101100
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_ESPI
value|0x00110000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_ESDHC
value|0x00114000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_I2C1
value|0x00118000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_I2C2
value|0x00118100
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_I2C3
value|0x00119000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_I2C4
value|0x00119100
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_DUART1
value|0x0011c500
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_DUART2
value|0x0011c600
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_DUART3
value|0x0011d500
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_DUART4
value|0x0011d600
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_LBC
value|0x00124000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_GPIO
value|0x00130000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_PCIE1
value|0x00200000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_PCIE2
value|0x00201000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_PCIE3
value|0x00202000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_PCIE4
value|0x00203000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_USB1
value|0x00210000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_USB2
value|0x00211000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_USB_PHY
value|0x00214000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_SATA1
value|0x00220000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_SATA2
value|0x00221000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_SEC_GEN
value|0x00300000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_SEC_JQ0
value|0x00301000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_SEC_JQ1
value|0x00302000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_SEC_JQ2
value|0x00303000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_SEC_JQ3
value|0x00304000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_SEC_RESERVED
value|0x00305000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_SEC_RTIC
value|0x00306000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_SEC_QI
value|0x00307000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_SEC_DECO0_CCB0
value|0x00308000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_SEC_DECO1_CCB1
value|0x00309000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_PME
value|0x00316000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_QM
value|0x00318000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_BM
value|0x0031a000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM
value|0x00400000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_MURAM
value|P3041_OFFSET_FM
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_BMI
value|(P3041_OFFSET_FM + 0x00080000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_QMI
value|(P3041_OFFSET_FM + 0x00080400)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PARSER
value|(P3041_OFFSET_FM + 0x00080800)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PORT_HO1
value|(P3041_OFFSET_FM + 0x00081000)
end_define

begin_comment
comment|/* host command/offline parser */
end_comment

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PORT_HO2
value|(P3041_OFFSET_FM + 0x00082000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PORT_HO3
value|(P3041_OFFSET_FM + 0x00083000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PORT_HO4
value|(P3041_OFFSET_FM + 0x00084000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PORT_HO5
value|(P3041_OFFSET_FM + 0x00085000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PORT_HO6
value|(P3041_OFFSET_FM + 0x00086000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PORT_HO7
value|(P3041_OFFSET_FM + 0x00087000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PORT_1GRX1
value|(P3041_OFFSET_FM + 0x00088000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PORT_1GRX2
value|(P3041_OFFSET_FM + 0x00089000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PORT_1GRX3
value|(P3041_OFFSET_FM + 0x0008a000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PORT_1GRX4
value|(P3041_OFFSET_FM + 0x0008b000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PORT_1GRX5
value|(P3041_OFFSET_FM + 0x0008c000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PORT_10GRX
value|(P3041_OFFSET_FM + 0x00090000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PORT_1GTX1
value|(P3041_OFFSET_FM + 0x000a8000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PORT_1GTX2
value|(P3041_OFFSET_FM + 0x000a9000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PORT_1GTX3
value|(P3041_OFFSET_FM + 0x000aa000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PORT_1GTX4
value|(P3041_OFFSET_FM + 0x000ab000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PORT_1GTX5
value|(P3041_OFFSET_FM + 0x000ac000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PORT_10GTX
value|(P3041_OFFSET_FM + 0x000b0000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PLCR
value|(P3041_OFFSET_FM + 0x000c0000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_KG
value|(P3041_OFFSET_FM + 0x000c1000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_DMA
value|(P3041_OFFSET_FM + 0x000c2000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_FPM
value|(P3041_OFFSET_FM + 0x000c3000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_IRAM
value|(P3041_OFFSET_FM + 0x000c4000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_PARSER_IRAM
value|(P3041_OFFSET_FM + 0x000c7000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_1GMAC1
value|(P3041_OFFSET_FM + 0x000e0000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_1GMDIO
value|(P3041_OFFSET_FM + 0x000e1000 + 0x120)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_1GMAC2
value|(P3041_OFFSET_FM + 0x000e2000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_1GMAC3
value|(P3041_OFFSET_FM + 0x000e4000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_1GMAC4
value|(P3041_OFFSET_FM + 0x000e6000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_1GMAC5
value|(P3041_OFFSET_FM + 0x000e8000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_10GMAC
value|(P3041_OFFSET_FM + 0x000f0000)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_10GMDIO
value|(P3041_OFFSET_FM + 0x000f1000 + 0x030)
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_FM_RTC
value|(P3041_OFFSET_FM + 0x000fe000)
end_define

begin_comment
comment|/* Offsets relative to QM or BM portals base */
end_comment

begin_define
define|#
directive|define
name|P3041_OFFSET_PORTALS_CE_AREA
value|0x000000
end_define

begin_comment
comment|/* cache enabled area */
end_comment

begin_define
define|#
directive|define
name|P3041_OFFSET_PORTALS_CI_AREA
value|0x100000
end_define

begin_comment
comment|/* cache inhibited area */
end_comment

begin_define
define|#
directive|define
name|P3041_CE_PORTAL_SIZE
value|0x4000
end_define

begin_define
define|#
directive|define
name|P3041_CI_PORTAL_SIZE
value|0x1000
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_PORTALS_CE
parameter_list|(
name|portal
parameter_list|)
define|\
value|(P3041_OFFSET_PORTALS_CE_AREA + P3041_CE_PORTAL_SIZE * (portal))
end_define

begin_define
define|#
directive|define
name|P3041_OFFSET_PORTALS_CI
parameter_list|(
name|portal
parameter_list|)
define|\
value|(P3041_OFFSET_PORTALS_CI_AREA + P3041_CI_PORTAL_SIZE * (portal))
end_define

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Transaction source ID (for memory controllers error reporting). */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_TransSrc
block|{
name|e_TRANS_SRC_PCIE_1
init|=
literal|0x0
block|,
comment|/**< PCI Express 1                  */
name|e_TRANS_SRC_PCIE_2
init|=
literal|0x1
block|,
comment|/**< PCI Express 2                  */
name|e_TRANS_SRC_PCIE_3
init|=
literal|0x2
block|,
comment|/**< PCI Express 3                  */
name|e_TRANS_SRC_PCIE_4
init|=
literal|0x3
block|,
comment|/**< PCI Express 4                  */
name|e_TRANS_SRC_SRIO_1
init|=
literal|0x8
block|,
comment|/**< SRIO 1                         */
name|e_TRANS_SRC_SRIO_2
init|=
literal|0x9
block|,
comment|/**< SRIO 2                         */
name|e_TRANS_SRC_BMAN
init|=
literal|0x18
block|,
comment|/**< BMan                           */
name|e_TRANS_SRC_PAMU
init|=
literal|0x1C
block|,
comment|/**< PAMU                           */
name|e_TRANS_SRC_PME
init|=
literal|0x20
block|,
comment|/**< PME                            */
name|e_TRANS_SRC_SEC
init|=
literal|0x21
block|,
comment|/**< Security engine                */
name|e_TRANS_SRC_QMAN
init|=
literal|0x3C
block|,
comment|/**< QMan                           */
name|e_TRANS_SRC_USB_1
init|=
literal|0x40
block|,
comment|/**< USB 1                          */
name|e_TRANS_SRC_USB_2
init|=
literal|0x41
block|,
comment|/**< USB 2                          */
name|e_TRANS_SRC_ESDHC
init|=
literal|0x44
block|,
comment|/**< eSDHC                          */
name|e_TRANS_SRC_PBL
init|=
literal|0x48
block|,
comment|/**< Pre-boot loader                */
name|e_TRANS_SRC_NPC
init|=
literal|0x4B
block|,
comment|/**< Nexus port controller          */
name|e_TRANS_SRC_RMAN
init|=
literal|0x5D
block|,
comment|/**< RIO message manager            */
name|e_TRANS_SRC_SATA_1
init|=
literal|0x60
block|,
comment|/**< SATA 1                         */
name|e_TRANS_SRC_SATA_2
init|=
literal|0x61
block|,
comment|/**< SATA 2                         */
name|e_TRANS_SRC_DMA_1
init|=
literal|0x70
block|,
comment|/**< DMA 1                          */
name|e_TRANS_SRC_DMA_2
init|=
literal|0x71
block|,
comment|/**< DMA 2                          */
name|e_TRANS_SRC_CORE_0_INST
init|=
literal|0x80
block|,
comment|/**< Processor 0 (instruction)      */
name|e_TRANS_SRC_CORE_0_DATA
init|=
literal|0x81
block|,
comment|/**< Processor 0 (data)             */
name|e_TRANS_SRC_CORE_1_INST
init|=
literal|0x82
block|,
comment|/**< Processor 1 (instruction)      */
name|e_TRANS_SRC_CORE_1_DATA
init|=
literal|0x83
block|,
comment|/**< Processor 1 (data)             */
name|e_TRANS_SRC_CORE_2_INST
init|=
literal|0x84
block|,
comment|/**< Processor 2 (instruction)      */
name|e_TRANS_SRC_CORE_2_DATA
init|=
literal|0x85
block|,
comment|/**< Processor 2 (data)             */
name|e_TRANS_SRC_CORE_3_INST
init|=
literal|0x86
block|,
comment|/**< Processor 3 (instruction)      */
name|e_TRANS_SRC_CORE_3_DATA
init|=
literal|0x87
block|,
comment|/**< Processor 3 (data)             */
name|e_TRANS_SRC_FM_10G
init|=
literal|0xC0
block|,
comment|/**< FM XAUI                        */
name|e_TRANS_SRC_FM_HO_1
init|=
literal|0xC1
block|,
comment|/**< FM offline, host 1             */
name|e_TRANS_SRC_FM_HO_2
init|=
literal|0xC2
block|,
comment|/**< FM offline, host 2             */
name|e_TRANS_SRC_FM_HO_3
init|=
literal|0xC3
block|,
comment|/**< FM offline, host 3             */
name|e_TRANS_SRC_FM_HO_4
init|=
literal|0xC4
block|,
comment|/**< FM offline, host 4             */
name|e_TRANS_SRC_FM_HO_5
init|=
literal|0xC5
block|,
comment|/**< FM offline, host 5             */
name|e_TRANS_SRC_FM_HO_6
init|=
literal|0xC6
block|,
comment|/**< FM offline, host 6             */
name|e_TRANS_SRC_FM_HO_7
init|=
literal|0xC7
block|,
comment|/**< FM offline, host 7             */
name|e_TRANS_SRC_FM_GETH_1
init|=
literal|0xC8
block|,
comment|/**< FM GETH 1                      */
name|e_TRANS_SRC_FM_GETH_2
init|=
literal|0xC9
block|,
comment|/**< FM GETH 2                      */
name|e_TRANS_SRC_FM_GETH_3
init|=
literal|0xCA
block|,
comment|/**< FM GETH 3                      */
name|e_TRANS_SRC_FM_GETH_4
init|=
literal|0xCB
block|,
comment|/**< FM GETH 4                      */
name|e_TRANS_SRC_FM_GETH_5
init|=
literal|0xCC
comment|/**< FM GETH 5                      */
block|}
name|e_TransSrc
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Local Access Window Target interface ID */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_P3041LawTargetId
block|{
name|e_P3041_LAW_TARGET_PCIE_1
init|=
literal|0x0
block|,
comment|/**< PCI Express 1 */
name|e_P3041_LAW_TARGET_PCIE_2
init|=
literal|0x1
block|,
comment|/**< PCI Express 2 */
name|e_P3041_LAW_TARGET_PCIE_3
init|=
literal|0x2
block|,
comment|/**< PCI Express 3 */
name|e_P3041_LAW_TARGET_PCIE_4
init|=
literal|0x3
block|,
comment|/**< PCI Express 4 */
name|e_P3041_LAW_TARGET_SRIO_1
init|=
literal|0x8
block|,
comment|/**< SRIO 1 */
name|e_P3041_LAW_TARGET_SRIO_2
init|=
literal|0x9
block|,
comment|/**< SRIO 2 */
name|e_P3041_LAW_TARGET_DDR_CPC
init|=
literal|0x10
block|,
comment|/**< DDR controller or CPC SRAM */
name|e_P3041_LAW_TARGET_BMAN
init|=
literal|0x18
block|,
comment|/**< BMAN target interface ID */
name|e_P3041_LAW_TARGET_DCSR
init|=
literal|0x1D
block|,
comment|/**< DCSR */
name|e_P3041_LAW_TARGET_LBC
init|=
literal|0x1F
block|,
comment|/**< Local Bus target interface ID */
name|e_P3041_LAW_TARGET_QMAN
init|=
literal|0x3C
block|,
comment|/**< QMAN target interface ID */
name|e_P3041_LAW_TARGET_NONE
init|=
literal|0xFF
comment|/**< None */
block|}
name|e_P3041LawTargetId
typedef|;
end_typedef

begin_comment
comment|/***************************************************************     P3041 general routines ****************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         P3041_init_grp P3041 Initialization Unit   @Description   P3041 initialization unit API functions, definitions and enums   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Part ID and revision number */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_P3041DeviceName
block|{
name|e_P3041_REV_INVALID
init|=
literal|0x00000000
block|,
comment|/**< Invalid revision                     */
name|e_P3041_REV_1_0
init|=
operator|(
name|int
operator|)
literal|0x82190310
block|,
comment|/**< P3041 with security,    revision 1.0 */
name|e_P3041_REV_1_0_NO_SEC
init|=
operator|(
name|int
operator|)
literal|0x82110310
comment|/**< P3041 without security, revision 1.0 */
block|}
name|e_P3041DeviceName
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Description   Device Disable Register */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
enum|enum
name|e_P3041DeviceDisable
block|{
name|e_P3041_DEV_DISABLE_PCIE_1
init|=
literal|0
block|,
comment|/**< PCI Express controller 1 disable */
name|e_P3041_DEV_DISABLE_PCIE_2
block|,
comment|/**< PCI Express controller 2 disable */
name|e_P3041_DEV_DISABLE_PCIE_3
block|,
comment|/**< PCI Express controller 3 disable */
name|e_P3041_DEV_DISABLE_PCIE_4
block|,
comment|/**< PCI Express controller 4 disable */
name|e_P3041_DEV_DISABLE_RMAN
block|,
comment|/**< RapidIO message manager disable */
name|e_P3041_DEV_DISABLE_SRIO_1
block|,
comment|/**< Serial RapidIO controller 1 disable */
name|e_P3041_DEV_DISABLE_SRIO_2
block|,
comment|/**< Serial RapidIO controller 2 disable */
name|e_P3041_DEV_DISABLE_DMA_1
init|=
literal|9
block|,
comment|/**< DMA controller 1 disable */
name|e_P3041_DEV_DISABLE_DMA_2
block|,
comment|/**< DMA controller 2 disable */
name|e_P3041_DEV_DISABLE_DDR
block|,
comment|/**< DDR controller disable */
name|e_P3041_DEV_DISABLE_SATA_1
init|=
literal|17
block|,
comment|/**< SATA controller 1 disable */
name|e_P3041_DEV_DISABLE_SATA_2
block|,
comment|/**< SATA controller 2 disable */
name|e_P3041_DEV_DISABLE_LBC
block|,
comment|/**< eLBC controller disable */
name|e_P3041_DEV_DISABLE_USB_1
block|,
comment|/**< USB controller 1 disable */
name|e_P3041_DEV_DISABLE_USB_2
block|,
comment|/**< USB controller 2 disable */
name|e_P3041_DEV_DISABLE_ESDHC
init|=
literal|23
block|,
comment|/**< eSDHC controller disable */
name|e_P3041_DEV_DISABLE_GPIO
block|,
comment|/**< GPIO controller disable */
name|e_P3041_DEV_DISABLE_ESPI
block|,
comment|/**< eSPI controller disable */
name|e_P3041_DEV_DISABLE_I2C_1
block|,
comment|/**< I2C module 1 (controllers 1 and 2) disable */
name|e_P3041_DEV_DISABLE_I2C_2
block|,
comment|/**< I2C module 2 (controllers 3 and 4) disable */
name|e_P3041_DEV_DISABLE_DUART_1
init|=
literal|30
block|,
comment|/**< DUART controller 1 disable */
name|e_P3041_DEV_DISABLE_DUART_2
block|,
comment|/**< DUART controller 2 disable */
name|e_P3041_DEV_DISABLE_DISR1_DUMMY_LAST
init|=
literal|32
block|,
comment|/**< Dummy entry signing end of DEVDISR1 register controllers */
name|e_P3041_DEV_DISABLE_PME
init|=
name|e_P3041_DEV_DISABLE_DISR1_DUMMY_LAST
block|,
comment|/**< Pattern match engine disable */
name|e_P3041_DEV_DISABLE_SEC
block|,
comment|/**< Security disable */
name|e_P3041_DEV_DISABLE_QM_BM
init|=
name|e_P3041_DEV_DISABLE_DISR1_DUMMY_LAST
operator|+
literal|4
block|,
comment|/**< Queue manager/buffer manager disable */
name|e_P3041_DEV_DISABLE_FM
init|=
name|e_P3041_DEV_DISABLE_DISR1_DUMMY_LAST
operator|+
literal|6
block|,
comment|/**< Frame manager disable */
name|e_P3041_DEV_DISABLE_10G
block|,
comment|/**< 10G Ethernet controller disable */
name|e_P3041_DEV_DISABLE_DTSEC_1
block|,
comment|/**< dTSEC controller 1 disable */
name|e_P3041_DEV_DISABLE_DTSEC_2
block|,
comment|/**< dTSEC controller 2 disable */
name|e_P3041_DEV_DISABLE_DTSEC_3
block|,
comment|/**< dTSEC controller 3 disable */
name|e_P3041_DEV_DISABLE_DTSEC_4
block|,
comment|/**< dTSEC controller 4 disable */
name|e_P3041_DEV_DISABLE_DTSEC_5
comment|/**< dTSEC controller 5 disable */
block|}
name|e_P3041DeviceDisable
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/*  @Description   structure representing P3041 devices configuration */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_typedef
typedef|typedef
struct|struct
name|t_P3041Devices
block|{
struct|struct
block|{
struct|struct
block|{
name|bool
name|enabled
decl_stmt|;
name|uint8_t
name|serdesBank
decl_stmt|;
name|uint16_t
name|serdesLane
decl_stmt|;
comment|/**< Most significant bits represent lanes used by this bank,                                                          one bit for lane, lane A is the first and so on, e.g.,                                                          set 0xF000 for ABCD lanes */
name|e_EnetInterface
name|ethIf
decl_stmt|;
name|uint8_t
name|ratio
decl_stmt|;
name|bool
name|divByTwo
decl_stmt|;
name|bool
name|isTwoHalfSgmii
decl_stmt|;
block|}
name|dtsecs
index|[
name|FM_MAX_NUM_OF_1G_MACS
index|]
struct|;
struct|struct
block|{
name|bool
name|enabled
decl_stmt|;
name|uint8_t
name|serdesBank
decl_stmt|;
name|uint16_t
name|serdesLane
decl_stmt|;
block|}
name|tgec
struct|;
block|}
name|fm
struct|;
block|}
name|t_P3041Devices
typedef|;
end_typedef

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      P3041_GetRevInfo   @Description   Obtain revision information.   @Param[in]     gutilBase       - Gutil memory map virtual base address.   @Return        Part ID and revision. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|e_P3041DeviceName
name|P3041_GetRevInfo
parameter_list|(
name|uintptr_t
name|gutilBase
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      P3041_GetE500Factor   @Description   Obtain core's multiplication factors.   @Param[in]     gutilBase       - Gutil memory map virtual base address.  @Param[in]     coreIndex       - Core index.  @Param[out]    p_E500MulFactor - E500 to CCB multification factor.  @Param[out]    p_E500DivFactor - E500 to CCB division factor.  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|P3041_GetE500Factor
parameter_list|(
name|uintptr_t
name|gutilBase
parameter_list|,
name|uint8_t
name|coreIndex
parameter_list|,
name|uint32_t
modifier|*
name|p_E500MulFactor
parameter_list|,
name|uint32_t
modifier|*
name|p_E500DivFactor
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      P3041_GetCcbFactor   @Description   Obtain system multiplication factor.   @Param[in]     gutilBase       - Gutil memory map virtual base address.   @Return        System multiplication factor. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|P3041_GetCcbFactor
parameter_list|(
name|uintptr_t
name|gutilBase
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      P3041_GetDdrFactor   @Description   Obtain DDR clock multiplication factor.   @Param[in]     gutilBase       - Gutil memory map virtual base address.   @Return        DDR clock multiplication factor. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|uint32_t
name|P3041_GetDdrFactor
parameter_list|(
name|uintptr_t
name|gutilBase
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      P3041_GetDdrType   @Description   Obtain DDR memory type.   @Param[in]     gutilBase       - Gutil memory map virtual base address.   @Return        DDR type. */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|e_DdrType
name|P3041_GetDdrType
parameter_list|(
name|uintptr_t
name|gutilBase
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Function      P3041_GetFmFactor   @Description   returns FM multiplication factors. (This value is returned using                 two parameters to avoid using float parameter).   @Param[in]     gutilBase       - Gutil memory map virtual base address.  @Param[out]    p_FmMulFactor   - FM to CCB multification factor.  @Param[out]    p_FmDivFactor   - FM to CCB division factor.  */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_function_decl
name|void
name|P3041_GetFmFactor
parameter_list|(
name|uintptr_t
name|gutilBase
parameter_list|,
name|uint32_t
modifier|*
name|p_FmMulFactor
parameter_list|,
name|uint32_t
modifier|*
name|p_FmDivFactor
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|P3041_CoreTimeBaseEnable
parameter_list|(
name|uintptr_t
name|rcpmBase
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|P3041_CoreTimeBaseDisable
parameter_list|(
name|uintptr_t
name|rcpmBase
parameter_list|)
function_decl|;
end_function_decl

begin_typedef
typedef|typedef
enum|enum
name|e_SerdesProtocol
block|{
name|SRDS_PROTOCOL_NONE
init|=
literal|0
block|,
name|SRDS_PROTOCOL_PCIE1
block|,
name|SRDS_PROTOCOL_PCIE2
block|,
name|SRDS_PROTOCOL_PCIE3
block|,
name|SRDS_PROTOCOL_PCIE4
block|,
name|SRDS_PROTOCOL_SRIO1
block|,
name|SRDS_PROTOCOL_SRIO2
block|,
name|SRDS_PROTOCOL_SGMII_FM
block|,
name|SRDS_PROTOCOL_XAUI_FM
block|,
name|SRDS_PROTOCOL_SATA1
block|,
name|SRDS_PROTOCOL_SATA2
block|,
name|SRDS_PROTOCOL_AURORA
block|}
name|e_SerdesProtocol
typedef|;
end_typedef

begin_function_decl
name|t_Error
name|P3041_DeviceDisable
parameter_list|(
name|uintptr_t
name|gutilBase
parameter_list|,
name|e_P3041DeviceDisable
name|device
parameter_list|,
name|bool
name|disable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|P3041_GetDevicesConfiguration
parameter_list|(
name|uintptr_t
name|gutilBase
parameter_list|,
name|t_P3041Devices
modifier|*
name|p_Devices
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|t_Error
name|P3041_PamuDisableBypass
parameter_list|(
name|uintptr_t
name|gutilBase
parameter_list|,
name|uint8_t
name|pamuId
parameter_list|,
name|bool
name|disable
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|uint32_t
name|P3041_SerdesRcwGetProtocol
parameter_list|(
name|uintptr_t
name|gutilBase
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|P3041_SerdesRcwIsDeviceConfigured
parameter_list|(
name|uintptr_t
name|gutilBase
parameter_list|,
name|e_SerdesProtocol
name|device
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|bool
name|P3041_SerdesRcwIsLaneEnabled
parameter_list|(
name|uintptr_t
name|gutilBase
parameter_list|,
name|uint32_t
name|lane
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of P3041_init_grp group */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of P3041_grp group */
end_comment

begin_comment
comment|/*****************************************************************************  INTEGRATION-SPECIFIC MODULE CODES ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|MODULE_UNKNOWN
value|0x00000000
end_define

begin_define
define|#
directive|define
name|MODULE_MEM
value|0x00010000
end_define

begin_define
define|#
directive|define
name|MODULE_MM
value|0x00020000
end_define

begin_define
define|#
directive|define
name|MODULE_CORE
value|0x00030000
end_define

begin_define
define|#
directive|define
name|MODULE_P3041
value|0x00040000
end_define

begin_define
define|#
directive|define
name|MODULE_P3041_PLATFORM
value|0x00050000
end_define

begin_define
define|#
directive|define
name|MODULE_PM
value|0x00060000
end_define

begin_define
define|#
directive|define
name|MODULE_MMU
value|0x00070000
end_define

begin_define
define|#
directive|define
name|MODULE_PIC
value|0x00080000
end_define

begin_define
define|#
directive|define
name|MODULE_CPC
value|0x00090000
end_define

begin_define
define|#
directive|define
name|MODULE_DUART
value|0x000a0000
end_define

begin_define
define|#
directive|define
name|MODULE_SERDES
value|0x000b0000
end_define

begin_define
define|#
directive|define
name|MODULE_PIO
value|0x000c0000
end_define

begin_define
define|#
directive|define
name|MODULE_QM
value|0x000d0000
end_define

begin_define
define|#
directive|define
name|MODULE_BM
value|0x000e0000
end_define

begin_define
define|#
directive|define
name|MODULE_SEC
value|0x000f0000
end_define

begin_define
define|#
directive|define
name|MODULE_LAW
value|0x00100000
end_define

begin_define
define|#
directive|define
name|MODULE_LBC
value|0x00110000
end_define

begin_define
define|#
directive|define
name|MODULE_PAMU
value|0x00120000
end_define

begin_define
define|#
directive|define
name|MODULE_FM
value|0x00130000
end_define

begin_define
define|#
directive|define
name|MODULE_FM_MURAM
value|0x00140000
end_define

begin_define
define|#
directive|define
name|MODULE_FM_PCD
value|0x00150000
end_define

begin_define
define|#
directive|define
name|MODULE_FM_RTC
value|0x00160000
end_define

begin_define
define|#
directive|define
name|MODULE_FM_MAC
value|0x00170000
end_define

begin_define
define|#
directive|define
name|MODULE_FM_PORT
value|0x00180000
end_define

begin_define
define|#
directive|define
name|MODULE_DPA
value|0x00190000
end_define

begin_define
define|#
directive|define
name|MODULE_MII
value|0x001a0000
end_define

begin_define
define|#
directive|define
name|MODULE_I2C
value|0x001b0000
end_define

begin_define
define|#
directive|define
name|MODULE_DMA
value|0x001c0000
end_define

begin_define
define|#
directive|define
name|MODULE_DDR
value|0x001d0000
end_define

begin_define
define|#
directive|define
name|MODULE_ESPI
value|0x001e0000
end_define

begin_comment
comment|/*****************************************************************************  PAMU INTEGRATION-SPECIFIC DEFINITIONS ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|PAMU_NUM_OF_PARTITIONS
value|4
end_define

begin_comment
comment|/*****************************************************************************  LAW INTEGRATION-SPECIFIC DEFINITIONS ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|LAW_NUM_OF_WINDOWS
value|32
end_define

begin_define
define|#
directive|define
name|LAW_MIN_WINDOW_SIZE
value|0x0000000000001000LL
end_define

begin_comment
comment|/**< 4KB */
end_comment

begin_define
define|#
directive|define
name|LAW_MAX_WINDOW_SIZE
value|0x0000002000000000LL
end_define

begin_comment
comment|/**< 64GB */
end_comment

begin_comment
comment|/*****************************************************************************  LBC INTEGRATION-SPECIFIC DEFINITIONS ******************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Group         lbc_exception_grp LBC Exception Unit   @Description   LBC Exception unit API functions, definitions and enums   @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_comment
comment|/**************************************************************************/
end_comment

begin_comment
comment|/**  @Anchor        lbc_exbm   @Collection    LBC Errors Bit Mask                  These errors are reported through the exceptions callback..                 The values can be or'ed in any combination in the errors mask                 parameter of the errors report structure.                  These errors can also be passed as a bit-mask to                 LBC_EnableErrorChecking() or LBC_DisableErrorChecking(),                 for enabling or disabling error checking.  @{ */
end_comment

begin_comment
comment|/***************************************************************************/
end_comment

begin_define
define|#
directive|define
name|LBC_ERR_BUS_MONITOR
value|0x80000000
end_define

begin_comment
comment|/**< Bus monitor error */
end_comment

begin_define
define|#
directive|define
name|LBC_ERR_PARITY_ECC
value|0x20000000
end_define

begin_comment
comment|/**< Parity error for GPCM/UPM */
end_comment

begin_define
define|#
directive|define
name|LBC_ERR_WRITE_PROTECT
value|0x04000000
end_define

begin_comment
comment|/**< Write protection error */
end_comment

begin_define
define|#
directive|define
name|LBC_ERR_CHIP_SELECT
value|0x00080000
end_define

begin_comment
comment|/**< Unrecognized chip select */
end_comment

begin_define
define|#
directive|define
name|LBC_ERR_ALL
value|(LBC_ERR_BUS_MONITOR | LBC_ERR_PARITY_ECC | \                                  LBC_ERR_WRITE_PROTECT | LBC_ERR_CHIP_SELECT)
end_define

begin_comment
comment|/**< All possible errors */
end_comment

begin_comment
comment|/* @} */
end_comment

begin_comment
comment|/** @} */
end_comment

begin_comment
comment|/* end of lbc_exception_grp group */
end_comment

begin_define
define|#
directive|define
name|LBC_INCORRECT_ERROR_REPORT_ERRATA
end_define

begin_define
define|#
directive|define
name|LBC_NUM_OF_BANKS
value|8
end_define

begin_define
define|#
directive|define
name|LBC_MAX_CS_SIZE
value|0x0000000100000000LL
end_define

begin_comment
comment|/* Up to 4G memory block size */
end_comment

begin_define
define|#
directive|define
name|LBC_PARITY_SUPPORT
end_define

begin_define
define|#
directive|define
name|LBC_HIGH_CLK_DIVIDERS
end_define

begin_define
define|#
directive|define
name|LBC_FCM_AVAILABLE
end_define

begin_comment
comment|/*****************************************************************************  GPIO INTEGRATION-SPECIFIC DEFINITIONS ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|GPIO_NUM_OF_PORTS
value|1
end_define

begin_comment
comment|/**< Number of ports in GPIO module;                                      Each port contains up to 32 I/O pins. */
end_comment

begin_define
define|#
directive|define
name|GPIO_VALID_PIN_MASKS
define|\
value|{
comment|/* Port A */
value|0xFFFFFFFF }
end_define

begin_define
define|#
directive|define
name|GPIO_VALID_INTR_MASKS
define|\
value|{
comment|/* Port A */
value|0xFFFFFFFF }
end_define

begin_comment
comment|/*****************************************************************************  SERDES INTEGRATION-SPECIFIC DEFINITIONS ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|SRDS_MAX_LANES
value|18
end_define

begin_define
define|#
directive|define
name|SRDS_MAX_BANK
value|3
end_define

begin_comment
comment|/* Serdes lanes general information provided in the following form:    1) Lane index in Serdes Control Registers Map    2) Lane enable/disable bit number in RCW    3) Lane bank index */
end_comment

begin_define
define|#
directive|define
name|SRDS_LANES
define|\
value|{                   \     { 0,  152, 0 }, \     { 1,  153, 0 }, \     { 2,  154, 0 }, \     { 3,  155, 0 }, \     { 4,  156, 0 }, \     { 5,  157, 0 }, \     { 6,  158, 0 }, \     { 7,  159, 0 }, \     { 8,  160, 0 }, \     { 9,  161, 0 }, \     { 16, 162, 1 }, \     { 17, 163, 1 }, \     { 18, 164, 1 }, \     { 19, 165, 1 }, \     { 20, 166, 2 }, \     { 21, 167, 2 }, \     { 22, 168, 2 }, \     { 23, 169, 2 }  \ }
end_define

begin_define
define|#
directive|define
name|SRDS_PROTOCOL_ALL_OPTIONS
end_define

begin_comment
comment|/* Serdes lanes assignment and multiplexing.    Each option is selected by SRDS_PRTCL bits of RCW. */
end_comment

begin_define
define|#
directive|define
name|SRDS_PROTOCOL_OPTIONS
define|\
comment|/* Protocol  Lane assignment */
define|\
value|{ \
comment|/* 0x00 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, \              SRDS_PROTOCOL_PCIE4, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_SGMII_FM, 0, 0, 0}, \
comment|/* 0x01 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, \              SRDS_PROTOCOL_PCIE4, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM}, \
comment|/* 0x02 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, \              SRDS_PROTOCOL_PCIE4, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x03 */
value|{SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_SGMII_FM, 0, 0, 0}, \
comment|/* 0x04 */
value|{SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM}, \
comment|/* 0x05 */
value|{SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x06 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_SGMII_FM, 0, 0, 0}, \
comment|/* 0x07 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM}, \
comment|/* 0x08 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x09 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_SGMII_FM, 0, 0, 0}, \
comment|/* 0x0A */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM}, \
comment|/* 0x0B */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x0C */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x0D */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_SGMII_FM, 0, 0, 0}, \
comment|/* 0x0E */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM}, \
comment|/* 0x0F */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM}, \
comment|/* 0x10 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x11 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x12 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_SGMII_FM, 0, 0, 0}, \
comment|/* 0x13 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM}, \
comment|/* 0x14 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM}, \
comment|/* 0x15 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x16 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1}, \
comment|/* 0x17 */
value|{SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x18 */
value|{SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_SGMII_FM, 0, 0, 0}, \
comment|/* 0x19 */
value|{SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM}, \
comment|/* 0x1A */
value|{SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM}, \
comment|/* 0x1B */
value|{SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x1C */
value|{SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM}, \
comment|/* 0x1D */
value|{SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x1E */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x1F */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_SGMII_FM, 0, 0, 0}, \
comment|/* 0x20 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM}, \
comment|/* 0x21 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM}, \
comment|/* 0x22 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x23 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x24 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_SGMII_FM, 0, 0, 0}, \
comment|/* 0x25 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM}, \
comment|/* 0x26 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM}, \
comment|/* 0x27 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x28 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x29 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_SGMII_FM, 0, 0, 0}, \
comment|/* 0x2A */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM}, \
comment|/* 0x2B */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x2C */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, \              SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x2D */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, \              SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_SGMII_FM, 0, 0, 0}, \
comment|/* 0x2E */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, \              SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM}, \
comment|/* 0x2F */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, \              SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO2, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x30 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x31 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_SGMII_FM, 0, 0, 0}, \
comment|/* 0x32 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM}, \
comment|/* 0x33 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, \              SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, SRDS_PROTOCOL_SRIO1, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x34 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x35 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x36 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, \              SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2}, \
comment|/* 0x37 */
value|{SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE1, SRDS_PROTOCOL_PCIE3, SRDS_PROTOCOL_PCIE3, \              SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_PCIE2, SRDS_PROTOCOL_SGMII_FM, SRDS_PROTOCOL_SGMII_FM, \              SRDS_PROTOCOL_AURORA, SRDS_PROTOCOL_AURORA, \              SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, SRDS_PROTOCOL_XAUI_FM, \              0, 0, SRDS_PROTOCOL_SATA1, SRDS_PROTOCOL_SATA2} \ }
end_define

begin_comment
comment|/*****************************************************************************  DDR INTEGRATION-SPECIFIC DEFINITIONS ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DDR_NUM_OF_VALID_CS
value|4
end_define

begin_comment
comment|/*****************************************************************************  DMA INTEGRATION-SPECIFIC DEFINITIONS ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|DMA_NUM_OF_CONTROLLERS
value|2
end_define

begin_comment
comment|/*****************************************************************************  CPC INTEGRATION-SPECIFIC DEFINITIONS ******************************************************************************/
end_comment

begin_define
define|#
directive|define
name|CPC_MAX_SIZE_SRAM_ERRATA_CPC4
end_define

begin_define
define|#
directive|define
name|CPC_HARDWARE_FLUSH_ERRATA_CPC10
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* __PART_INTEGRATION_EXT_H */
end_comment

end_unit

