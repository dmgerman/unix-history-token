begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  Device driver optimized for the Symbios/LSI 53C896/53C895A/53C1010   *  PCI-SCSI controllers.  *  *  Copyright (C) 1999-2000  Gerard Roudier<groudier@club-internet.fr>  *  *  This driver also supports the following Symbios/LSI PCI-SCSI chips:  *	53C810A, 53C825A, 53C860, 53C875, 53C876, 53C885, 53C895,  *	53C810,  53C815,  53C825 and the 53C1510D is 53C8XX mode.  *  *    *  This driver for FreeBSD-CAM is derived from the Linux sym53c8xx driver.  *  Copyright (C) 1998-1999  Gerard Roudier  *  *  The sym53c8xx driver is derived from the ncr53c8xx driver that had been   *  a port of the FreeBSD ncr driver to Linux-1.2.13.  *  *  The original ncr driver has been written for 386bsd and FreeBSD by  *          Wolfgang Stanglmeier<wolf@cologne.de>  *          Stefan Esser<se@mi.Uni-Koeln.de>  *  Copyright (C) 1994  Wolfgang Stanglmeier  *  *  The initialisation code, and part of the code that addresses   *  FreeBSD-CAM services is based on the aic7xxx driver for FreeBSD-CAM   *  written by Justin T. Gibbs.  *  *  Other major contributions:  *  *  NVRAM detection and reading.  *  Copyright (C) 1997 Richard Waltham<dormouse@farsrobt.demon.co.uk>  *  *-----------------------------------------------------------------------------  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHORS AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYM_CONF_H
end_ifndef

begin_define
define|#
directive|define
name|SYM_CONF_H
end_define

begin_comment
comment|/*-------------------------------------------------------------------  *  Static configuration.  *-------------------------------------------------------------------  */
end_comment

begin_comment
comment|/*  *  Also support early NCR 810, 815 and 825 chips.  */
end_comment

begin_define
define|#
directive|define
name|SYM_CONF_GENERIC_SUPPORT
end_define

begin_comment
comment|/*  *  Use Normal IO instead of MMIO.  */
end_comment

begin_comment
comment|/* #define SYM_CONF_IOMAPPED */
end_comment

begin_comment
comment|/*  *  Max tags for a device (logical unit)  * 	We use a power of 2, (7) means 2<<7=128  *  Maximum is 8 -> 256 tags  */
end_comment

begin_define
define|#
directive|define
name|SYM_CONF_MAX_TAG_ORDER
value|(6)
end_define

begin_comment
comment|/*  *  Max number of scatter/gather entries for en IO.  *  Each entry costs 8 bytes in the internal CCB data structure.  *  For now 65 should suffice given the BSD O/Ses capabilities.  */
end_comment

begin_define
define|#
directive|define
name|SYM_CONF_MAX_SG
value|(33)
end_define

begin_comment
comment|/*  *  Max number of targets.  *  Maximum is 16 and you are advised not to change this value.  */
end_comment

begin_define
define|#
directive|define
name|SYM_CONF_MAX_TARGET
value|(16)
end_define

begin_comment
comment|/*  *  Max number of logical units.  *  SPI-2 allows up to 64 logical units, but in real life, target  *  that implements more that 7 logical units are pretty rare.  *  Anyway, the cost of accepting up to 64 logical unit is low in   *  this driver, thus going with the maximum is acceptable.  */
end_comment

begin_define
define|#
directive|define
name|SYM_CONF_MAX_LUN
value|(64)
end_define

begin_comment
comment|/*  *  Max number of IO control blocks queued to the controller.  *  Each entry needs 8 bytes and the queues are allocated contiguously.  *  Since we donnot want to allocate more than a page, the theorical   *  maximum is PAGE_SIZE/8. For safety, we announce a bit less to the   *  access method. :)  *  When not supplied, as it is suggested, the driver compute some   *  good value for this parameter.  */
end_comment

begin_comment
comment|/* #define SYM_CONF_MAX_START	(PAGE_SIZE/8 - 16) */
end_comment

begin_comment
comment|/*  *  Support for NVRAM.  */
end_comment

begin_define
define|#
directive|define
name|SYM_CONF_NVRAM_SUPPORT
end_define

begin_comment
comment|/* #define SYM_CONF_NVRAM_SUPPORT */
end_comment

begin_comment
comment|/*  *  Support for Immediate Arbitration.  *  Not advised.  */
end_comment

begin_comment
comment|/* #define SYM_CONF_IARB_SUPPORT */
end_comment

begin_comment
comment|/*-------------------------------------------------------------------  *  Configuration that could be dynamic if it was possible   *  to pass arguments to the driver.  *-------------------------------------------------------------------  */
end_comment

begin_comment
comment|/*  *  HOST default scsi id.  */
end_comment

begin_define
define|#
directive|define
name|SYM_SETUP_HOST_ID
value|7
end_define

begin_comment
comment|/*  *  Max synchronous transfers.  */
end_comment

begin_define
define|#
directive|define
name|SYM_SETUP_MIN_SYNC
value|(9)
end_define

begin_comment
comment|/*  *  Max wide order.  */
end_comment

begin_define
define|#
directive|define
name|SYM_SETUP_MAX_WIDE
value|(1)
end_define

begin_comment
comment|/*  *  Max SCSI offset.  */
end_comment

begin_define
define|#
directive|define
name|SYM_SETUP_MAX_OFFS
value|(63)
end_define

begin_comment
comment|/*  *  Default number of tags.  */
end_comment

begin_define
define|#
directive|define
name|SYM_SETUP_MAX_TAG
value|(1<<SYM_CONF_MAX_TAG_ORDER)
end_define

begin_comment
comment|/*  *  SYMBIOS NVRAM format support.  */
end_comment

begin_define
define|#
directive|define
name|SYM_SETUP_SYMBIOS_NVRAM
value|(1)
end_define

begin_comment
comment|/*  *  TEKRAM NVRAM format support.  */
end_comment

begin_define
define|#
directive|define
name|SYM_SETUP_TEKRAM_NVRAM
value|(1)
end_define

begin_comment
comment|/*  *  PCI parity checking.  *  It should not be an option, but some poor or broken   *  PCI-HOST bridges have been reported to make problems   *  when this feature is enabled.  *  Setting this option to 0 tells the driver not to   *  enable the checking against PCI parity.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYM_SETUP_PCI_PARITY
end_ifndef

begin_define
define|#
directive|define
name|SYM_SETUP_PCI_PARITY
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *  SCSI parity checking.  */
end_comment

begin_define
define|#
directive|define
name|SYM_SETUP_SCSI_PARITY
value|(1)
end_define

begin_comment
comment|/*  *  SCSI activity LED.  */
end_comment

begin_define
define|#
directive|define
name|SYM_SETUP_SCSI_LED
value|(0)
end_define

begin_comment
comment|/*  *  SCSI High Voltage Differential support.  *  *  HVD/LVD/SE capable controllers (895, 895A, 896, 1010)   *  report the actual SCSI BUS mode from the STEST4 IO   *  register.  *  *  But for HVD/SE only capable chips (825a, 875, 885),   *  the driver uses some heuristic to probe against HVD.   *  Normally, the chip senses the DIFFSENS signal and   *  should switch its BUS tranceivers to high impedance   *  in situation of the driver having been wrong about   *  the actual BUS mode. May-be, the BUS mode probing of   *  the driver is safe, but, given that it may be partially   *  based on some previous IO register settings, it   *  cannot be stated so. Thus, decision has been taken   *  to require a user option to be set for the DIFF probing   *  to be applied for the 825a, 875 and 885 chips.  *    *  This setup option works as follows:  *  *    0  ->  HVD only supported for 895, 895A, 896, 1010.  *    1  ->  HVD probed  for 825A, 875, 885.  *    2  ->  HVD assumed for 825A, 875, 885 (not advised).  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYM_SETUP_SCSI_DIFF
end_ifndef

begin_define
define|#
directive|define
name|SYM_SETUP_SCSI_DIFF
value|(0)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *  IRQ mode.  */
end_comment

begin_define
define|#
directive|define
name|SYM_SETUP_IRQ_MODE
value|(0)
end_define

begin_comment
comment|/*  *  Check SCSI BUS signal on reset.  */
end_comment

begin_define
define|#
directive|define
name|SYM_SETUP_SCSI_BUS_CHECK
value|(1)
end_define

begin_comment
comment|/*  *  Max burst for PCI (1<<value)  *  7 means: (1<<7) = 128 DWORDS.  */
end_comment

begin_define
define|#
directive|define
name|SYM_SETUP_BURST_ORDER
value|(7)
end_define

begin_comment
comment|/*  *  Only relevant if IARB support configured.  *  - Max number of successive settings of IARB hints.  *  - Set IARB on arbitration lost.  */
end_comment

begin_define
define|#
directive|define
name|SYM_CONF_IARB_MAX
value|3
end_define

begin_define
define|#
directive|define
name|SYM_CONF_SET_IARB_ON_ARB_LOST
value|1
end_define

begin_comment
comment|/*  *  Returning wrong residuals may make problems.  *  When zero, this define tells the driver to   *  always return 0 as transfer residual.  *  Btw, all my testings of residuals have succeeded.  */
end_comment

begin_define
define|#
directive|define
name|SYM_CONF_RESIDUAL_SUPPORT
value|1
end_define

begin_comment
comment|/*  *  Supported maximum number of LUNs to announce to   *  the access method.  *  The driver supports up to 64 LUNs per target as   *  required by SPI-2/SPI-3. However some SCSI devices    *  designed prior to these specifications or not being    *  conformant may be highly confused when they are   *  asked about a LUN> 7.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYM_SETUP_MAX_LUN
end_ifndef

begin_define
define|#
directive|define
name|SYM_SETUP_MAX_LUN
value|(8)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  *  Low priority probe map.  *   *  This option is used as a bitmap to tell the driver   *  about chips that are to be claimed with a low priority   *  (-2000) by the probe method. This allows any other driver   *  that may return some higher priority value for the same   *  chips to take precedence over this driver (sym).  *  This option may be used when both the ncr driver and this   *  driver are configured.  *  *  Bits are to be coded as follows:  *    0x01  ->  810a, 860  *    0x02  ->  825a, 875, 885, 895  *    0x04  ->  895a, 896, 1510d  *    0x08  ->  1010  *    0x40  ->  810, 815, 825  *  *  For example, value 5 tells the driver to claim support   *  for 810a, 860, 895a, 896 and 1510d with low priority,   *  allowing the ncr driver to take precedence if configured.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|SYM_SETUP_LP_PROBE_MAP
end_ifndef

begin_define
define|#
directive|define
name|SYM_SETUP_LP_PROBE_MAP
value|0
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* SYM_CONF_H */
end_comment

end_unit

