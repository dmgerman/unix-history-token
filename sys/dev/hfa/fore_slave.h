begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  * ===================================  * HARP  |  Host ATM Research Platform  * ===================================  *  *  * This Host ATM Research Platform ("HARP") file (the "Software") is  * made available by Network Computing Services, Inc. ("NetworkCS")  * "AS IS".  NetworkCS does not provide maintenance, improvements or  * support of any kind.  *  * NETWORKCS MAKES NO WARRANTIES OR REPRESENTATIONS, EXPRESS OR IMPLIED,  * INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS FOR A PARTICULAR PURPOSE, AS TO ANY ELEMENT OF THE  * SOFTWARE OR ANY SUPPORT PROVIDED IN CONNECTION WITH THIS SOFTWARE.  * In no event shall NetworkCS be responsible for any damages, including  * but not limited to consequential damages, arising from or relating to  * any use of the Software or related support.  *  * Copyright 1994-1998 Network Computing Services, Inc.  *  * Copies of this Software may be made, however, the above copyright  * notice must be reproduced on all copies.  *  *	@(#) $FreeBSD$  *  */
end_comment

begin_comment
comment|/*  * FORE Systems 200-Series Adapter Support  * ---------------------------------------  *  * Slave Interface definitions  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_FORE_SLAVE_H
end_ifndef

begin_define
define|#
directive|define
name|_FORE_SLAVE_H
end_define

begin_comment
comment|/*  * This file contains the (mostly hardware) definitions for each of the  * supported 200-series slave interfaces.  */
end_comment

begin_comment
comment|/*  * Structure defining the supported FORE 200-series interfaces  */
end_comment

begin_struct
struct|struct
name|fore_device
block|{
name|char
modifier|*
name|fd_name
decl_stmt|;
comment|/* Device name (from PROM) */
name|Atm_device
name|fd_devtyp
decl_stmt|;
comment|/* Device type */
block|}
struct|;
end_struct

begin_typedef
typedef|typedef
name|struct
name|fore_device
name|Fore_device
typedef|;
end_typedef

begin_comment
comment|/*  * Common definitions  * ------------------  */
end_comment

begin_define
define|#
directive|define
name|MON960_BASE
value|0x400
end_define

begin_comment
comment|/* Address offset of Mon960 */
end_comment

begin_define
define|#
directive|define
name|AALI_BASE
value|0x4d40
end_define

begin_comment
comment|/* Address offset of Aali */
end_comment

begin_typedef
typedef|typedef
specifier|volatile
name|unsigned
name|int
name|Fore_reg
typedef|;
end_typedef

begin_comment
comment|/* Slave control register */
end_comment

begin_typedef
typedef|typedef
specifier|volatile
name|unsigned
name|char
name|Fore_mem
typedef|;
end_typedef

begin_comment
comment|/* Slave memory */
end_comment

begin_comment
comment|/*  * SBA-200E SBus Slave Interface  * -----------------------------  */
end_comment

begin_define
define|#
directive|define
name|SBA200E_PROM_NAME
value|"FORE,sba-200e"
end_define

begin_comment
comment|/*  * SBA-200E Host Control Register (HCR)  */
end_comment

begin_define
define|#
directive|define
name|SBA200E_READ_BITS
value|0x1ff
end_define

begin_comment
comment|/* Valid read data bits */
end_comment

begin_define
define|#
directive|define
name|SBA200E_WRITE_BITS
value|0x01f
end_define

begin_comment
comment|/* Valid write data bits */
end_comment

begin_define
define|#
directive|define
name|SBA200E_STICKY_BITS
value|0x013
end_define

begin_comment
comment|/* Sticky data bits */
end_comment

begin_comment
comment|/* Read access */
end_comment

begin_define
define|#
directive|define
name|SBA200E_SBUS_INTR_RD
value|0x100
end_define

begin_comment
comment|/* State of SBus interrupt */
end_comment

begin_define
define|#
directive|define
name|SBA200E_TEST_MODE
value|0x080
end_define

begin_comment
comment|/* Device is in test-mode  */
end_comment

begin_define
define|#
directive|define
name|SBA200E_IFIFO_FULL
value|0x040
end_define

begin_comment
comment|/* Input FIFO almost full (when 0) */
end_comment

begin_define
define|#
directive|define
name|SBA200E_ESP_HOLD_RD
value|0x020
end_define

begin_comment
comment|/* State of ESP bus hold */
end_comment

begin_define
define|#
directive|define
name|SBA200E_SBUS_ENA_RD
value|0x010
end_define

begin_comment
comment|/* State of SBus interrupt enable */
end_comment

begin_define
define|#
directive|define
name|SBA200E_OFIFO_FULL
value|0x008
end_define

begin_comment
comment|/* Output FIFO almost full */
end_comment

begin_define
define|#
directive|define
name|SBA200E_SELFTEST_FAIL
value|0x004
end_define

begin_comment
comment|/* i960 self-test failed (when 0) */
end_comment

begin_define
define|#
directive|define
name|SBA200E_HOLD_LOCK_RD
value|0x002
end_define

begin_comment
comment|/* State of i960 hold lock signal */
end_comment

begin_define
define|#
directive|define
name|SBA200E_RESET_RD
value|0x001
end_define

begin_comment
comment|/* State of board reset signal */
end_comment

begin_comment
comment|/* Write access - bit set (clear) */
end_comment

begin_define
define|#
directive|define
name|SBA200E_SBUS_ENA
value|0x010
end_define

begin_comment
comment|/* Enable (disable) SBus interrupts */
end_comment

begin_define
define|#
directive|define
name|SBA200E_CLR_SBUS_INTR
value|0x008
end_define

begin_comment
comment|/* Clear SBus interrupt */
end_comment

begin_define
define|#
directive|define
name|SBA200E_I960_INTR
value|0x004
end_define

begin_comment
comment|/* Issue interrupt to i960 */
end_comment

begin_define
define|#
directive|define
name|SBA200E_HOLD_LOCK
value|0x002
end_define

begin_comment
comment|/* Set (clear) i960 hold lock signal */
end_comment

begin_define
define|#
directive|define
name|SBA200E_RESET
value|0x001
end_define

begin_comment
comment|/* Set (clear) board reset signal */
end_comment

begin_define
define|#
directive|define
name|SBA200E_HCR_INIT
parameter_list|(
name|hcr
parameter_list|,
name|bits
parameter_list|)
define|\
value|((hcr) = (SBA200E_WRITE_BITS& (bits)))
end_define

begin_define
define|#
directive|define
name|SBA200E_HCR_SET
parameter_list|(
name|hcr
parameter_list|,
name|bits
parameter_list|)
define|\
value|((hcr) = (((hcr)& SBA200E_STICKY_BITS) | (bits)))
end_define

begin_define
define|#
directive|define
name|SBA200E_HCR_CLR
parameter_list|(
name|hcr
parameter_list|,
name|bits
parameter_list|)
define|\
value|((hcr) = ((hcr)& (SBA200E_STICKY_BITS ^ (bits))))
end_define

begin_comment
comment|/*  * SBA-200 SBus Slave Interface  * ----------------------------  */
end_comment

begin_define
define|#
directive|define
name|SBA200_PROM_NAME
value|"FORE,sba-200"
end_define

begin_comment
comment|/*  * SBA-200 Board Control Register (BCR)  */
end_comment

begin_comment
comment|/* Write access - bit set */
end_comment

begin_define
define|#
directive|define
name|SBA200_CLR_SBUS_INTR
value|0x04
end_define

begin_comment
comment|/* Clear SBus interrupt */
end_comment

begin_define
define|#
directive|define
name|SBA200_RESET
value|0x01
end_define

begin_comment
comment|/* Assert board reset signal */
end_comment

begin_comment
comment|/* Write access - bit clear */
end_comment

begin_define
define|#
directive|define
name|SBA200_RESET_CLR
value|0x00
end_define

begin_comment
comment|/* Clear board reset signal */
end_comment

begin_comment
comment|/*  * PCA-200E PCI Bus Slave Interface  * --------------------------------  */
end_comment

begin_comment
comment|/*  * PCI Identifiers  */
end_comment

begin_define
define|#
directive|define
name|FORE_VENDOR_ID
value|0x1127
end_define

begin_define
define|#
directive|define
name|FORE_PCA200E_ID
value|0x0300
end_define

begin_comment
comment|/*  * PCA-200E PCI Configuration Space  */
end_comment

begin_define
define|#
directive|define
name|PCA200E_PCI_MEMBASE
value|0x10
end_define

begin_comment
comment|/* Memory base address */
end_comment

begin_define
define|#
directive|define
name|PCA200E_PCI_MCTL
value|0x40
end_define

begin_comment
comment|/* Master control */
end_comment

begin_comment
comment|/*  * PCA-200E Address Space  */
end_comment

begin_define
define|#
directive|define
name|PCA200E_RAM_SIZE
value|0x100000
end_define

begin_define
define|#
directive|define
name|PCA200E_HCR_OFFSET
value|0x100000
end_define

begin_define
define|#
directive|define
name|PCA200E_IMASK_OFFSET
value|0x100004
end_define

begin_define
define|#
directive|define
name|PCA200E_PSR_OFFSET
value|0x100008
end_define

begin_define
define|#
directive|define
name|PCA200E_MMAP_SIZE
value|0x10000c
end_define

begin_comment
comment|/*  * PCA-200E Master Control  */
end_comment

begin_define
define|#
directive|define
name|PCA200E_MCTL_SWAP
value|0x4000
end_define

begin_comment
comment|/* Convert Slave endianess */
end_comment

begin_comment
comment|/*  * PCA-200E Host Control Register (HCR)  */
end_comment

begin_define
define|#
directive|define
name|PCA200E_READ_BITS
value|0x0ff
end_define

begin_comment
comment|/* Valid read data bits */
end_comment

begin_define
define|#
directive|define
name|PCA200E_WRITE_BITS
value|0x01f
end_define

begin_comment
comment|/* Valid write data bits */
end_comment

begin_define
define|#
directive|define
name|PCA200E_STICKY_BITS
value|0x000
end_define

begin_comment
comment|/* Sticky data bits */
end_comment

begin_comment
comment|/* Read access */
end_comment

begin_define
define|#
directive|define
name|PCA200E_TEST_MODE
value|0x080
end_define

begin_comment
comment|/* Device is in test-mode */
end_comment

begin_define
define|#
directive|define
name|PCA200E_IFIFO_FULL
value|0x040
end_define

begin_comment
comment|/* Input FIFO almost full */
end_comment

begin_define
define|#
directive|define
name|PCA200E_ESP_HOLD_RD
value|0x020
end_define

begin_comment
comment|/* State of ESP hold bus */
end_comment

begin_define
define|#
directive|define
name|PCA200E_OFIFO_FULL
value|0x010
end_define

begin_comment
comment|/* Output FIFO almost full */
end_comment

begin_define
define|#
directive|define
name|PCA200E_HOLD_ACK
value|0x008
end_define

begin_comment
comment|/* State of Hold Ack */
end_comment

begin_define
define|#
directive|define
name|PCA200E_SELFTEST_FAIL
value|0x004
end_define

begin_comment
comment|/* i960 self-test failed */
end_comment

begin_define
define|#
directive|define
name|PCA200E_HOLD_LOCK_RD
value|0x002
end_define

begin_comment
comment|/* State of i960 hold lock signal */
end_comment

begin_define
define|#
directive|define
name|PCA200E_RESET_BD
value|0x001
end_define

begin_comment
comment|/* State of board reset signal */
end_comment

begin_comment
comment|/* Write access */
end_comment

begin_define
define|#
directive|define
name|PCA200E_CLR_HBUS_INT
value|0x010
end_define

begin_comment
comment|/* Clear host bus interrupt */
end_comment

begin_define
define|#
directive|define
name|PCA200E_I960_INTRA
value|0x008
end_define

begin_comment
comment|/* Set slave interrupt A */
end_comment

begin_define
define|#
directive|define
name|PCA200E_I960_INTRB
value|0x004
end_define

begin_comment
comment|/* Set slave interrupt B */
end_comment

begin_define
define|#
directive|define
name|PCA200E_HOLD_LOCK
value|0x002
end_define

begin_comment
comment|/* Set (clear) i960 hold lock signal */
end_comment

begin_define
define|#
directive|define
name|PCA200E_RESET
value|0x001
end_define

begin_comment
comment|/* Set (clear) board reset signal */
end_comment

begin_define
define|#
directive|define
name|PCA200E_HCR_INIT
parameter_list|(
name|hcr
parameter_list|,
name|bits
parameter_list|)
define|\
value|((hcr) = (PCA200E_WRITE_BITS& (bits)))
end_define

begin_define
define|#
directive|define
name|PCA200E_HCR_SET
parameter_list|(
name|hcr
parameter_list|,
name|bits
parameter_list|)
define|\
value|((hcr) = (bits))
end_define

begin_define
define|#
directive|define
name|PCA200E_HCR_CLR
parameter_list|(
name|hcr
parameter_list|,
name|bits
parameter_list|)
define|\
value|((hcr) = 0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _FORE_SLAVE_H */
end_comment

end_unit

