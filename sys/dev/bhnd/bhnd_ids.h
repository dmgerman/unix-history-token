begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*-  * Copyright (c) 2015-2016 Landon Fuller<landon@landonf.org>  * Copyright (c) 1999-2015, Broadcom Corporation  *   * This file is derived from the bcmdevs.h header contributed by Broadcom   * to Android's bcmdhd driver module, later revisions of bcmdevs.h distributed  * with the dd-wrt project, and the hndsoc.h header distributed with Broadcom's  * initial brcm80211 Linux driver release as contributed to the Linux staging  * repository.  *   * Permission to use, copy, modify, and/or distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY  * SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES  * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION  * OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN  * CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  *  * $FreeBSD$  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_BHND_BHND_IDS_H_
end_ifndef

begin_define
define|#
directive|define
name|_BHND_BHND_IDS_H_
end_define

begin_comment
comment|/*  * JEDEC JEP-106 Core Vendor IDs  *   * These are the JEDEC JEP-106 manufacturer ID representions (with ARM's  * non-standard 4-bit continutation code), as used in ARM's PrimeCell  * identification registers, bcma(4) EROM core descriptors, etc.  *   * @note  * Bus implementations that predate the adoption of ARM IP  * will need to convert bus-specific vendor IDs to their BHND_MFGID  * JEP-106 equivalents.  *  * @par ARM 4-bit Continuation Code  *  * BHND MFGIDs are encoded using ARM's non-standard 4-bit continuation code  * format:  *  * @code{.unparsed}  * [11:8     ][7:0   ]  * [cont code][mfg id]  * @endcode  *  * The 4-bit continuation code field specifies the number of JEP-106  * continuation codes that prefix the manufacturer's ID code. In the case of  * ARM's JEP-106 ID of `0x7F 0x7F 0x7F 0x7F 0x3B`, the four 0x7F continuations  * are encoded as '4' in the 4-bit continuation code field (i.e. 0x43B).   */
end_comment

begin_define
define|#
directive|define
name|BHND_MFGID_ARM
value|0x043b
end_define

begin_comment
comment|/**< arm JEP-106 vendor id */
end_comment

begin_define
define|#
directive|define
name|BHND_MFGID_BCM
value|0x04bf
end_define

begin_comment
comment|/**< broadcom JEP-106 vendor id */
end_comment

begin_define
define|#
directive|define
name|BHND_MFGID_MIPS
value|0x04a7
end_define

begin_comment
comment|/**< mips JEP-106 vendor id */
end_comment

begin_define
define|#
directive|define
name|BHND_MFGID_INVALID
value|0x0000
end_define

begin_comment
comment|/**< invalid JEP-106 vendor id */
end_comment

begin_comment
comment|/*  * OCP (Open Core Protocol) Vendor IDs.  *   * OCP-IP assigned vendor codes are used by siba(4)  */
end_comment

begin_define
define|#
directive|define
name|OCP_VENDOR_BCM
value|0x4243
end_define

begin_comment
comment|/**< Broadcom OCP vendor id */
end_comment

begin_comment
comment|/* PCI vendor IDs */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_EPIGRAM
value|0xfeda
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_BROADCOM
value|0x14e4
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_3COM
value|0x10b7
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_NETGEAR
value|0x1385
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_DIAMOND
value|0x1092
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_INTEL
value|0x8086
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_DELL
value|0x1028
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_HP
value|0x103c
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_HP_COMPAQ
value|0x0e11
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_APPLE
value|0x106b
end_define

begin_define
define|#
directive|define
name|PCI_VENDOR_SI_IMAGE
value|0x1095
end_define

begin_comment
comment|/* Silicon Image, used by Arasan SDIO Host */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_BUFFALO
value|0x1154
end_define

begin_comment
comment|/* Buffalo vendor id */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_TI
value|0x104c
end_define

begin_comment
comment|/* Texas Instruments */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_RICOH
value|0x1180
end_define

begin_comment
comment|/* Ricoh */
end_comment

begin_define
define|#
directive|define
name|PCI_VENDOR_JMICRON
value|0x197b
end_define

begin_comment
comment|/* PCMCIA vendor IDs */
end_comment

begin_define
define|#
directive|define
name|PCMCIA_VENDOR_BROADCOM
value|0x02d0
end_define

begin_comment
comment|/* SDIO vendor IDs */
end_comment

begin_define
define|#
directive|define
name|SDIO_VENDOR_BROADCOM
value|0x00BF
end_define

begin_comment
comment|/* USB dongle VID/PIDs */
end_comment

begin_define
define|#
directive|define
name|USB_VID_BROADCOM
value|0x0a5c
end_define

begin_define
define|#
directive|define
name|USB_PID_BCM4328
value|0xbd12
end_define

begin_define
define|#
directive|define
name|USB_PID_BCM4322
value|0xbd13
end_define

begin_define
define|#
directive|define
name|USB_PID_BCM4319
value|0xbd16
end_define

begin_define
define|#
directive|define
name|USB_PID_BCM43236
value|0xbd17
end_define

begin_define
define|#
directive|define
name|USB_PID_BCM4332
value|0xbd18
end_define

begin_define
define|#
directive|define
name|USB_PID_BCM4330
value|0xbd19
end_define

begin_define
define|#
directive|define
name|USB_PID_BCM4334
value|0xbd1a
end_define

begin_define
define|#
directive|define
name|USB_PID_BCM43239
value|0xbd1b
end_define

begin_define
define|#
directive|define
name|USB_PID_BCM4324
value|0xbd1c
end_define

begin_define
define|#
directive|define
name|USB_PID_BCM4360
value|0xbd1d
end_define

begin_define
define|#
directive|define
name|USB_PID_BCM43143
value|0xbd1e
end_define

begin_define
define|#
directive|define
name|USB_PID_BCM43242
value|0xbd1f
end_define

begin_define
define|#
directive|define
name|USB_PID_BCM43342
value|0xbd21
end_define

begin_define
define|#
directive|define
name|USB_PID_BCM4335
value|0xbd20
end_define

begin_define
define|#
directive|define
name|USB_PID_BCM4350
value|0xbd23
end_define

begin_define
define|#
directive|define
name|USB_PID_BCM43341
value|0xbd22
end_define

begin_define
define|#
directive|define
name|USB_PID_BCM_DNGL_BDC
value|0x0bdc
end_define

begin_comment
comment|/* BDC USB device controller IP? */
end_comment

begin_define
define|#
directive|define
name|USB_PID_BCM_DNGL_JTAG
value|0x4a44
end_define

begin_comment
comment|/* HW USB BLOCK [CPULESS USB] PIDs */
end_comment

begin_define
define|#
directive|define
name|USB_PID_CCM_HWUSB_43239
value|43239
end_define

begin_comment
comment|/* PCI Device IDs */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4210
value|0x1072
end_define

begin_comment
comment|/* never used */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4230
value|0x1086
end_define

begin_comment
comment|/* never used */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4401_ENET
value|0x170c
end_define

begin_comment
comment|/* 4401b0 production enet cards */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM3352
value|0x3352
end_define

begin_comment
comment|/* bcm3352 device id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM3360
value|0x3360
end_define

begin_comment
comment|/* bcm3360 device id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4211
value|0x4211
end_define

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4231
value|0x4231
end_define

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4301
value|0x4301
end_define

begin_comment
comment|/* 4031 802.11b */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4303_D11B
value|0x4303
end_define

begin_comment
comment|/* 4303 802.11b */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4306
value|0x4306
end_define

begin_comment
comment|/* 4306 802.11b/g */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4307
value|0x4307
end_define

begin_comment
comment|/* 4307 802.11b, 10/100 ethernet, V.92 modem */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4311_D11G
value|0x4311
end_define

begin_comment
comment|/* 4311 802.11b/g id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4311_D11DUAL
value|0x4312
end_define

begin_comment
comment|/* 4311 802.11a/b/g id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4311_D11A
value|0x4313
end_define

begin_comment
comment|/* 4311 802.11a id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4328_D11DUAL
value|0x4314
end_define

begin_comment
comment|/* 4328/4312 802.11a/g id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4328_D11G
value|0x4315
end_define

begin_comment
comment|/* 4328/4312 802.11g id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4328_D11A
value|0x4316
end_define

begin_comment
comment|/* 4328/4312 802.11a id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4318_D11G
value|0x4318
end_define

begin_comment
comment|/* 4318 802.11b/g id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4318_D11DUAL
value|0x4319
end_define

begin_comment
comment|/* 4318 802.11a/b/g id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4318_D11A
value|0x431a
end_define

begin_comment
comment|/* 4318 802.11a id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4325_D11DUAL
value|0x431b
end_define

begin_comment
comment|/* 4325 802.11a/g id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4325_D11G
value|0x431c
end_define

begin_comment
comment|/* 4325 802.11g id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4325_D11A
value|0x431d
end_define

begin_comment
comment|/* 4325 802.11a id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4306_D11G
value|0x4320
end_define

begin_comment
comment|/* 4306 802.11g */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4306_D11A
value|0x4321
end_define

begin_comment
comment|/* 4306 802.11a */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4306_UART
value|0x4322
end_define

begin_comment
comment|/* 4306 uart */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4306_V90
value|0x4323
end_define

begin_comment
comment|/* 4306 v90 codec */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4306_D11DUAL
value|0x4324
end_define

begin_comment
comment|/* 4306 dual A+B */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4306_D11G_ID2
value|0x4325
end_define

begin_comment
comment|/* BCM4306_D11G; INF w/loose binding war */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4321_D11N
value|0x4328
end_define

begin_comment
comment|/* 4321 802.11n dualband id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4321_D11N2G
value|0x4329
end_define

begin_comment
comment|/* 4321 802.11n 2.4Ghz band id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4321_D11N5G
value|0x432a
end_define

begin_comment
comment|/* 4321 802.11n 5Ghz band id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4322_D11N
value|0x432b
end_define

begin_comment
comment|/* 4322 802.11n dualband device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4322_D11N2G
value|0x432c
end_define

begin_comment
comment|/* 4322 802.11n 2.4GHz device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4322_D11N5G
value|0x432d
end_define

begin_comment
comment|/* 4322 802.11n 5GHz device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4329_D11N
value|0x432e
end_define

begin_comment
comment|/* 4329 802.11n dualband device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4329_D11N2G
value|0x432f
end_define

begin_comment
comment|/* 4329 802.11n 2.4G device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4329_D11N5G
value|0x4330
end_define

begin_comment
comment|/* 4329 802.11n 5G device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4315_D11DUAL
value|0x4334
end_define

begin_comment
comment|/* 4315 802.11a/g id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4315_D11G
value|0x4335
end_define

begin_comment
comment|/* 4315 802.11g id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4315_D11A
value|0x4336
end_define

begin_comment
comment|/* 4315 802.11a id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4319_D11N
value|0x4337
end_define

begin_comment
comment|/* 4319 802.11n dualband device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4319_D11N2G
value|0x4338
end_define

begin_comment
comment|/* 4319 802.11n 2.4G device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4319_D11N5G
value|0x4339
end_define

begin_comment
comment|/* 4319 802.11n 5G device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43231_D11N2G
value|0x4340
end_define

begin_comment
comment|/* 43231 802.11n 2.4GHz device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43221_D11N2G
value|0x4341
end_define

begin_comment
comment|/* 43221 802.11n 2.4GHz device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43222_D11N
value|0x4350
end_define

begin_comment
comment|/* 43222 802.11n dualband device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43222_D11N2G
value|0x4351
end_define

begin_comment
comment|/* 43222 802.11n 2.4GHz device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43222_D11N5G
value|0x4352
end_define

begin_comment
comment|/* 43222 802.11n 5GHz device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43224_D11N
value|0x4353
end_define

begin_comment
comment|/* 43224 802.11n dualband device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43224_D11N_ID_VEN1
value|0x0576
end_define

begin_comment
comment|/* Vendor specific 43224 802.11n db device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43226_D11N
value|0x4354
end_define

begin_comment
comment|/* 43226 802.11n dualband device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43236_D11N
value|0x4346
end_define

begin_comment
comment|/* 43236 802.11n dualband device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43236_D11N2G
value|0x4347
end_define

begin_comment
comment|/* 43236 802.11n 2.4GHz device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43236_D11N5G
value|0x4348
end_define

begin_comment
comment|/* 43236 802.11n 5GHz device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43225_D11N2G
value|0x4357
end_define

begin_comment
comment|/* 43225 802.11n 2.4GHz device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43421_D11N
value|0xA99D
end_define

begin_comment
comment|/* 43421 802.11n dualband device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4313_D11N2G
value|0x4727
end_define

begin_comment
comment|/* 4313 802.11n 2.4G device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4330_D11N
value|0x4360
end_define

begin_comment
comment|/* 4330 802.11n dualband device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4330_D11N2G
value|0x4361
end_define

begin_comment
comment|/* 4330 802.11n 2.4G device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4330_D11N5G
value|0x4362
end_define

begin_comment
comment|/* 4330 802.11n 5G device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4336_D11N
value|0x4343
end_define

begin_comment
comment|/* 4336 802.11n 2.4GHz device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM6362_D11N
value|0x435f
end_define

begin_comment
comment|/* 6362 802.11n dualband device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM6362_D11N2G
value|0x433f
end_define

begin_comment
comment|/* 6362 802.11n 2.4Ghz band id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM6362_D11N5G
value|0x434f
end_define

begin_comment
comment|/* 6362 802.11n 5Ghz band id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4331_D11N
value|0x4331
end_define

begin_comment
comment|/* 4331 802.11n dualband id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4331_D11N2G
value|0x4332
end_define

begin_comment
comment|/* 4331 802.11n 2.4Ghz band id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4331_D11N5G
value|0x4333
end_define

begin_comment
comment|/* 4331 802.11n 5Ghz band id */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43237_D11N
value|0x4355
end_define

begin_comment
comment|/* 43237 802.11n dualband device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43237_D11N5G
value|0x4356
end_define

begin_comment
comment|/* 43237 802.11n 5GHz device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43227_D11N2G
value|0x4358
end_define

begin_comment
comment|/* 43228 802.11n 2.4GHz device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43228_D11N
value|0x4359
end_define

begin_comment
comment|/* 43228 802.11n DualBand device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43228_D11N5G
value|0x435a
end_define

begin_comment
comment|/* 43228 802.11n 5GHz device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43362_D11N
value|0x4363
end_define

begin_comment
comment|/* 43362 802.11n 2.4GHz device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43239_D11N
value|0x4370
end_define

begin_comment
comment|/* 43239 802.11n dualband device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4324_D11N
value|0x4374
end_define

begin_comment
comment|/* 4324 802.11n dualband device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43217_D11N2G
value|0x43a9
end_define

begin_comment
comment|/* 43217 802.11n 2.4GHz device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43131_D11N2G
value|0x43aa
end_define

begin_comment
comment|/* 43131 802.11n 2.4GHz device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4314_D11N2G
value|0x4364
end_define

begin_comment
comment|/* 4314 802.11n 2.4G device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43142_D11N2G
value|0x4365
end_define

begin_comment
comment|/* 43142 802.11n 2.4G device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43143_D11N2G
value|0x4366
end_define

begin_comment
comment|/* 43143 802.11n 2.4G device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4334_D11N
value|0x4380
end_define

begin_comment
comment|/* 4334 802.11n dualband device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4334_D11N2G
value|0x4381
end_define

begin_comment
comment|/* 4334 802.11n 2.4G device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4334_D11N5G
value|0x4382
end_define

begin_comment
comment|/* 4334 802.11n 5G device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43342_D11N
value|0x4383
end_define

begin_comment
comment|/* 43342 802.11n dualband device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43342_D11N2G
value|0x4384
end_define

begin_comment
comment|/* 43342 802.11n 2.4G device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43342_D11N5G
value|0x4385
end_define

begin_comment
comment|/* 43342 802.11n 5G device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43341_D11N
value|0x4386
end_define

begin_comment
comment|/* 43341 802.11n dualband device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43341_D11N2G
value|0x4387
end_define

begin_comment
comment|/* 43341 802.11n 2.4G device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM43341_D11N5G
value|0x4388
end_define

begin_comment
comment|/* 43341 802.11n 5G device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4360_D11AC
value|0x43a0
end_define

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4360_D11AC2G
value|0x43a1
end_define

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4360_D11AC5G
value|0x43a2
end_define

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4335_D11AC
value|0x43ae
end_define

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4335_D11AC2G
value|0x43af
end_define

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4335_D11AC5G
value|0x43b0
end_define

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4352_D11AC
value|0x43b1
end_define

begin_comment
comment|/* 4352 802.11ac dualband device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4352_D11AC2G
value|0x43b2
end_define

begin_comment
comment|/* 4352 802.11ac 2.4G device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_BCM4352_D11AC5G
value|0x43b3
end_define

begin_comment
comment|/* 4352 802.11ac 5G device */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_PCIXX21_FLASHMEDIA0
value|0x8033
end_define

begin_comment
comment|/* TI PCI xx21 Standard Host Controller */
end_comment

begin_define
define|#
directive|define
name|PCI_DEVID_PCIXX21_SDIOH0
value|0x8034
end_define

begin_comment
comment|/* TI PCI xx21 Standard Host Controller */
end_comment

begin_comment
comment|/* PCI Subsystem Vendor IDs */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBVENDOR_BCM943228HMB
value|0x0607
end_define

begin_define
define|#
directive|define
name|PCI_SUBVENDOR_BCM94313HMGBL
value|0x0608
end_define

begin_define
define|#
directive|define
name|PCI_SUBVENDOR_BCM94313HMG
value|0x0609
end_define

begin_define
define|#
directive|define
name|PCI_SUBVENDOR_BCM943142HM
value|0x0611
end_define

begin_comment
comment|/* PCI Subsystem Device IDs */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM43143_D11N2G
value|0x4366
end_define

begin_comment
comment|/* 43143 802.11n 2.4G device */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM43242_D11N
value|0x4367
end_define

begin_comment
comment|/* 43242 802.11n dualband device */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM43242_D11N2G
value|0x4368
end_define

begin_comment
comment|/* 43242 802.11n 2.4G device */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM43242_D11N5G
value|0x4369
end_define

begin_comment
comment|/* 43242 802.11n 5G device */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM4350_D11AC
value|0x43a3
end_define

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM4350_D11AC2G
value|0x43a4
end_define

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM4350_D11AC5G
value|0x43a5
end_define

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCMGPRS_UART
value|0x4333
end_define

begin_comment
comment|/* Uart id used by 4306/gprs card */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCMGPRS2_UART
value|0x4344
end_define

begin_comment
comment|/* Uart id used by 4306/gprs card */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM_FPGA_JTAGM
value|0x43f0
end_define

begin_comment
comment|/* FPGA jtagm device id */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM_JTAGM
value|0x43f1
end_define

begin_comment
comment|/* BCM jtagm device id */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM_SDIOH_FPGA
value|0x43f2
end_define

begin_comment
comment|/* sdio host fpga */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM_SDIOH
value|0x43f3
end_define

begin_comment
comment|/* BCM sdio host id */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM_SDIOD_FPGA
value|0x43f4
end_define

begin_comment
comment|/* sdio device fpga */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM_SPIH_FPGA
value|0x43f5
end_define

begin_comment
comment|/* PCI SPI Host Controller FPGA */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM_SPIH
value|0x43f6
end_define

begin_comment
comment|/* Synopsis SPI Host Controller */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM_MIMO_FPGA
value|0x43f8
end_define

begin_comment
comment|/* FPGA mimo minimacphy device id */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM_JTAGM2
value|0x43f9
end_define

begin_comment
comment|/* PCI_SUBDEVID_BCM alternate jtagm device id */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM_SDHCI_FPGA
value|0x43fa
end_define

begin_comment
comment|/* Standard SDIO Host Controller FPGA */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM4402_ENET
value|0x4402
end_define

begin_comment
comment|/* 4402 enet */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM4402_V90
value|0x4403
end_define

begin_comment
comment|/* 4402 v90 codec */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM4410
value|0x4410
end_define

begin_comment
comment|/* bcm44xx family pci iline */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM4412
value|0x4412
end_define

begin_comment
comment|/* bcm44xx family pci enet */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM4430
value|0x4430
end_define

begin_comment
comment|/* bcm44xx family cardbus iline */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM4432
value|0x4432
end_define

begin_comment
comment|/* bcm44xx family cardbus enet */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM4704_ENET
value|0x4706
end_define

begin_comment
comment|/* 4704 enet (Use 47XX_ENET_ID instead!) */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM4710
value|0x4710
end_define

begin_comment
comment|/* 4710 primary function 0 */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM47XX_AUDIO
value|0x4711
end_define

begin_comment
comment|/* 47xx audio codec */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM47XX_V90
value|0x4712
end_define

begin_comment
comment|/* 47xx v90 codec */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM47XX_ENET
value|0x4713
end_define

begin_comment
comment|/* 47xx enet */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM47XX_EXT
value|0x4714
end_define

begin_comment
comment|/* 47xx external i/f */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM47XX_GMAC
value|0x4715
end_define

begin_comment
comment|/* 47xx Unimac based GbE */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM47XX_USBH
value|0x4716
end_define

begin_comment
comment|/* 47xx usb host */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM47XX_USBD
value|0x4717
end_define

begin_comment
comment|/* 47xx usb device */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM47XX_IPSEC
value|0x4718
end_define

begin_comment
comment|/* 47xx ipsec */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM47XX_ROBO
value|0x4719
end_define

begin_comment
comment|/* 47xx/53xx roboswitch core */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM47XX_USB20H
value|0x471a
end_define

begin_comment
comment|/* 47xx usb 2.0 host */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM47XX_USB20D
value|0x471b
end_define

begin_comment
comment|/* 47xx usb 2.0 device */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM47XX_ATA100
value|0x471d
end_define

begin_comment
comment|/* 47xx parallel ATA */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM47XX_SATAXOR
value|0x471e
end_define

begin_comment
comment|/* 47xx serial ATA& XOR DMA */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM47XX_GIGETH
value|0x471f
end_define

begin_comment
comment|/* 47xx GbE (5700) */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM4712_MIPS
value|0x4720
end_define

begin_comment
comment|/* 4712 base devid */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM4716
value|0x4722
end_define

begin_comment
comment|/* 4716 base devid */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM47XX_USB30H
value|0x472a
end_define

begin_comment
comment|/* 47xx usb 3.0 host */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM47XX_USB30D
value|0x472b
end_define

begin_comment
comment|/* 47xx usb 3.0 device */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM47XX_SMBUS_EMU
value|0x47fe
end_define

begin_comment
comment|/* 47xx emulated SMBus device */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM47XX_XOR_EMU
value|0x47ff
end_define

begin_comment
comment|/* 47xx emulated XOR engine */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM_EPI41210
value|0xa0fa
end_define

begin_comment
comment|/* bcm4210 */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM_EPI41230
value|0xa10e
end_define

begin_comment
comment|/* bcm4230 */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM_JINVANI_SDIOH
value|0x4743
end_define

begin_comment
comment|/* Jinvani SDIO Gold Host */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM27XX_SDIOH
value|0x2702
end_define

begin_comment
comment|/* PCI_SUBDEVID_BCM27xx Standard SDIO Host */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM_PCIXX21_FLASHMEDIA
value|0x803b
end_define

begin_comment
comment|/* TI PCI xx21 Standard Host Controller */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM_PCIXX21_SDIOH
value|0x803c
end_define

begin_comment
comment|/* TI PCI xx21 Standard Host Controller */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM_R5C822_SDIOH
value|0x0822
end_define

begin_comment
comment|/* Ricoh Co Ltd R5C822 SD/SDIO/MMC/MS/MSPro Host */
end_comment

begin_define
define|#
directive|define
name|PCI_SUBDEVID_BCM_JMICRON_SDIOH
value|0x2381
end_define

begin_comment
comment|/* JMicron Standard SDIO Host Controller */
end_comment

begin_comment
comment|/* Broadcom ChipCommon Chip IDs */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4306
value|0x4306
end_define

begin_comment
comment|/* 4306 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4311
value|0x4311
end_define

begin_comment
comment|/* 4311 PCIe 802.11a/b/g */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43111
value|43111
end_define

begin_comment
comment|/* 43111 chipcommon chipid (OTP chipid) */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43112
value|43112
end_define

begin_comment
comment|/* 43112 chipcommon chipid (OTP chipid) */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4312
value|0x4312
end_define

begin_comment
comment|/* 4312 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4313
value|0x4313
end_define

begin_comment
comment|/* 4313 chip id */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43131
value|43131
end_define

begin_comment
comment|/* 43131 chip id (OTP chipid) */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4315
value|0x4315
end_define

begin_comment
comment|/* 4315 chip id */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4318
value|0x4318
end_define

begin_comment
comment|/* 4318 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4319
value|0x4319
end_define

begin_comment
comment|/* 4319 chip id */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4320
value|0x4320
end_define

begin_comment
comment|/* 4320 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4321
value|0x4321
end_define

begin_comment
comment|/* 4321 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43217
value|43217
end_define

begin_comment
comment|/* 43217 chip id (OTP chipid) */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4322
value|0x4322
end_define

begin_comment
comment|/* 4322 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43221
value|43221
end_define

begin_comment
comment|/* 43221 chipcommon chipid (OTP chipid) */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43222
value|43222
end_define

begin_comment
comment|/* 43222 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43224
value|43224
end_define

begin_comment
comment|/* 43224 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43225
value|43225
end_define

begin_comment
comment|/* 43225 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43227
value|43227
end_define

begin_comment
comment|/* 43227 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43228
value|43228
end_define

begin_comment
comment|/* 43228 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43226
value|43226
end_define

begin_comment
comment|/* 43226 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43231
value|43231
end_define

begin_comment
comment|/* 43231 chipcommon chipid (OTP chipid) */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43234
value|43234
end_define

begin_comment
comment|/* 43234 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43235
value|43235
end_define

begin_comment
comment|/* 43235 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43236
value|43236
end_define

begin_comment
comment|/* 43236 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43237
value|43237
end_define

begin_comment
comment|/* 43237 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43238
value|43238
end_define

begin_comment
comment|/* 43238 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43239
value|43239
end_define

begin_comment
comment|/* 43239 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43420
value|43420
end_define

begin_comment
comment|/* 43222 chipcommon chipid (OTP, RBBU) */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43421
value|43421
end_define

begin_comment
comment|/* 43224 chipcommon chipid (OTP, RBBU) */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43428
value|43428
end_define

begin_comment
comment|/* 43228 chipcommon chipid (OTP, RBBU) */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43431
value|43431
end_define

begin_comment
comment|/* 4331  chipcommon chipid (OTP, RBBU) */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43460
value|43460
end_define

begin_comment
comment|/* 4360  chipcommon chipid (OTP, RBBU) */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43462
value|0xA9C6
end_define

begin_comment
comment|/* 43462 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4325
value|0x4325
end_define

begin_comment
comment|/* 4325 chip id */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4328
value|0x4328
end_define

begin_comment
comment|/* 4328 chip id */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4329
value|0x4329
end_define

begin_comment
comment|/* 4329 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4331
value|0x4331
end_define

begin_comment
comment|/* 4331 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4336
value|0x4336
end_define

begin_comment
comment|/* 4336 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43362
value|43362
end_define

begin_comment
comment|/* 43362 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4330
value|0x4330
end_define

begin_comment
comment|/* 4330 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM6362
value|0x6362
end_define

begin_comment
comment|/* 6362 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4314
value|0x4314
end_define

begin_comment
comment|/* 4314 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43142
value|43142
end_define

begin_comment
comment|/* 43142 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43143
value|43143
end_define

begin_comment
comment|/* 43143 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4324
value|0x4324
end_define

begin_comment
comment|/* 4324 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43242
value|43242
end_define

begin_comment
comment|/* 43242 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43243
value|43243
end_define

begin_comment
comment|/* 43243 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4334
value|0x4334
end_define

begin_comment
comment|/* 4334 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4335
value|0x4335
end_define

begin_comment
comment|/* 4335 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4360
value|0x4360
end_define

begin_comment
comment|/* 4360 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43602
value|0xaa52
end_define

begin_comment
comment|/* 43602 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4352
value|0x4352
end_define

begin_comment
comment|/* 4352 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43526
value|0xAA06
end_define

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43341
value|43341
end_define

begin_comment
comment|/* 43341 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM43342
value|43342
end_define

begin_comment
comment|/* 43342 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4335
value|0x4335
end_define

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4350
value|0x4350
end_define

begin_comment
comment|/* 4350 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4342
value|4342
end_define

begin_comment
comment|/* 4342 chipcommon chipid (OTP, RBBU) */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4402
value|0x4402
end_define

begin_comment
comment|/* 4402 chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4704
value|0x4704
end_define

begin_comment
comment|/* 4704 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4706
value|0x5300
end_define

begin_comment
comment|/* 4706 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4707
value|53010
end_define

begin_comment
comment|/* 4707 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM53018
value|53018
end_define

begin_comment
comment|/* 53018 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_IS_BCM4707
parameter_list|(
name|chipid
parameter_list|)
define|\
value|(((chipid) == BHND_CHIPID_BCM4707) || \ 	((chipid) == BHND_CHIPID_BCM53018))
end_define

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4710
value|0x4710
end_define

begin_comment
comment|/* 4710 chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4712
value|0x4712
end_define

begin_comment
comment|/* 4712 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4716
value|0x4716
end_define

begin_comment
comment|/* 4716 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM47162
value|47162
end_define

begin_comment
comment|/* 47162 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4748
value|0x4748
end_define

begin_comment
comment|/* 4716 chipcommon chipid (OTP, RBBU) */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4749
value|0x4749
end_define

begin_comment
comment|/* 5357 chipcommon chipid (OTP, RBBU) */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM4785
value|0x4785
end_define

begin_comment
comment|/* 4785 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM5350
value|0x5350
end_define

begin_comment
comment|/* 5350 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM5352
value|0x5352
end_define

begin_comment
comment|/* 5352 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM5354
value|0x5354
end_define

begin_comment
comment|/* 5354 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM5365
value|0x5365
end_define

begin_comment
comment|/* 5365 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM5356
value|0x5356
end_define

begin_comment
comment|/* 5356 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM5357
value|0x5357
end_define

begin_comment
comment|/* 5357 chipcommon chipid */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPID_BCM53572
value|53572
end_define

begin_comment
comment|/* 53572 chipcommon chipid */
end_comment

begin_comment
comment|/* Broadcom ChipCommon Package IDs */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4303
value|2
end_define

begin_comment
comment|/* 4303 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4309
value|1
end_define

begin_comment
comment|/* 4309 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4712LARGE
value|0
end_define

begin_comment
comment|/* 340pin 4712 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4712SMALL
value|1
end_define

begin_comment
comment|/* 200pin 4712 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4712MID
value|2
end_define

begin_comment
comment|/* 225pin 4712 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4328USBD11G
value|2
end_define

begin_comment
comment|/* 4328 802.11g USB package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4328USBDUAL
value|3
end_define

begin_comment
comment|/* 4328 802.11a/g USB package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4328SDIOD11G
value|4
end_define

begin_comment
comment|/* 4328 802.11g SDIO package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4328SDIODUAL
value|5
end_define

begin_comment
comment|/* 4328 802.11a/g SDIO package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4329_289PIN
value|0
end_define

begin_comment
comment|/* 4329 289-pin package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4329_182PIN
value|1
end_define

begin_comment
comment|/* 4329N 182-pin package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM5354E
value|1
end_define

begin_comment
comment|/* 5354E package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4716
value|8
end_define

begin_comment
comment|/* 4716 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4717
value|9
end_define

begin_comment
comment|/* 4717 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4718
value|10
end_define

begin_comment
comment|/* 4718 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM5356_NONMODE
value|1
end_define

begin_comment
comment|/* 5356 package without nmode suppport */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM5358U
value|8
end_define

begin_comment
comment|/* 5358U package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM5358
value|9
end_define

begin_comment
comment|/* 5358 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM47186
value|10
end_define

begin_comment
comment|/* 47186 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM5357
value|11
end_define

begin_comment
comment|/* 5357 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM5356U
value|12
end_define

begin_comment
comment|/* 5356U package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM53572
value|8
end_define

begin_comment
comment|/* 53572 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM5357C0
value|8
end_define

begin_comment
comment|/* 5357c0 package id (the same as 53572) */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM47188
value|9
end_define

begin_comment
comment|/* 47188 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM5358C0
value|0xa
end_define

begin_comment
comment|/* 5358c0 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM5356C0
value|0xb
end_define

begin_comment
comment|/* 5356c0 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4331TT
value|8
end_define

begin_comment
comment|/* 4331 12x12 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4331TN
value|9
end_define

begin_comment
comment|/* 4331 12x9 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4331TNA0
value|0xb
end_define

begin_comment
comment|/* 4331 12x9 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4706L
value|1
end_define

begin_comment
comment|/* 4706L package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_HDLSIM5350
value|1
end_define

begin_comment
comment|/* HDL simulator package id for a 5350 */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_HDLSIM
value|14
end_define

begin_comment
comment|/* HDL simulator package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_HWSIM
value|15
end_define

begin_comment
comment|/* Hardware simulator package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM43224_FAB_CSM
value|0x8
end_define

begin_comment
comment|/* the chip is manufactured by CSM */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM43224_FAB_SMIC
value|0xa
end_define

begin_comment
comment|/* the chip is manufactured by SMIC */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4336_WLBGA
value|0x8
end_define

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4330_WLBGA
value|0x0
end_define

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4314PCIE_ARM
value|(8 | 0)
end_define

begin_comment
comment|/* 4314 QFN PCI package id, bit 3 tie high */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4314SDIO
value|(8 | 1)
end_define

begin_comment
comment|/* 4314 QFN SDIO package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4314PCIE
value|(8 | 2)
end_define

begin_comment
comment|/* 4314 QFN PCI (ARM-less) package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4314SDIO_ARM
value|(8 | 3)
end_define

begin_comment
comment|/* 4314 QFN SDIO (ARM-less) package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4314SDIO_FPBGA
value|(8 | 4)
end_define

begin_comment
comment|/* 4314 FpBGA SDIO package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4314DEV
value|(8 | 6)
end_define

begin_comment
comment|/* 4314 Development package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4707
value|1
end_define

begin_comment
comment|/* 4707 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4708
value|2
end_define

begin_comment
comment|/* 4708 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4709
value|0
end_define

begin_comment
comment|/* 4709 package id */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4335_WLCSP
value|(0x0)
end_define

begin_comment
comment|/* WLCSP Module/Mobile SDIO/HSIC. */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4335_FCBGA
value|(0x1)
end_define

begin_comment
comment|/* FCBGA PC/Embedded/Media PCIE/SDIO */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4335_WLBGA
value|(0x2)
end_define

begin_comment
comment|/* WLBGA COB/Mobile SDIO/HSIC. */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_BCM4335_FCBGAD
value|(0x3)
end_define

begin_comment
comment|/* FCBGA Debug Debug/Dev All if's. */
end_comment

begin_define
define|#
directive|define
name|BHND_PKGID_PKG_MASK_BCM4335
value|(0x3)
end_define

begin_comment
comment|/* Broadcom Core IDs */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_INVALID
value|0x700
end_define

begin_comment
comment|/* Invalid coreid */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_CC
value|0x800
end_define

begin_comment
comment|/* chipcommon core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_ILINE20
value|0x801
end_define

begin_comment
comment|/* iline20 core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_SRAM
value|0x802
end_define

begin_comment
comment|/* sram core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_SDRAM
value|0x803
end_define

begin_comment
comment|/* sdram core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_PCI
value|0x804
end_define

begin_comment
comment|/* pci core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_MIPS
value|0x805
end_define

begin_comment
comment|/* mips core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_ENET
value|0x806
end_define

begin_comment
comment|/* enet mac core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_CODEC
value|0x807
end_define

begin_comment
comment|/* v90 codec core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_USB
value|0x808
end_define

begin_comment
comment|/* usb 1.1 host/device core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_ADSL
value|0x809
end_define

begin_comment
comment|/* ADSL core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_ILINE100
value|0x80a
end_define

begin_comment
comment|/* iline100 core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_IPSEC
value|0x80b
end_define

begin_comment
comment|/* ipsec core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_UTOPIA
value|0x80c
end_define

begin_comment
comment|/* utopia core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_PCMCIA
value|0x80d
end_define

begin_comment
comment|/* pcmcia core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_SOCRAM
value|0x80e
end_define

begin_comment
comment|/* internal memory core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_MEMC
value|0x80f
end_define

begin_comment
comment|/* memc sdram core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_OFDM
value|0x810
end_define

begin_comment
comment|/* OFDM phy core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_EXTIF
value|0x811
end_define

begin_comment
comment|/* external interface core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_D11
value|0x812
end_define

begin_comment
comment|/* 802.11 MAC core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_APHY
value|0x813
end_define

begin_comment
comment|/* 802.11a phy core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_BPHY
value|0x814
end_define

begin_comment
comment|/* 802.11b phy core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_GPHY
value|0x815
end_define

begin_comment
comment|/* 802.11g phy core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_MIPS33
value|0x816
end_define

begin_comment
comment|/* mips3302 core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_USB11H
value|0x817
end_define

begin_comment
comment|/* usb 1.1 host core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_USB11D
value|0x818
end_define

begin_comment
comment|/* usb 1.1 device core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_USB20H
value|0x819
end_define

begin_comment
comment|/* usb 2.0 host core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_USB20D
value|0x81a
end_define

begin_comment
comment|/* usb 2.0 device core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_SDIOH
value|0x81b
end_define

begin_comment
comment|/* sdio host core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_ROBO
value|0x81c
end_define

begin_comment
comment|/* roboswitch core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_ATA100
value|0x81d
end_define

begin_comment
comment|/* parallel ATA core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_SATAXOR
value|0x81e
end_define

begin_comment
comment|/* serial ATA& XOR DMA core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_GIGETH
value|0x81f
end_define

begin_comment
comment|/* gigabit ethernet core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_PCIE
value|0x820
end_define

begin_comment
comment|/* pci express core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_NPHY
value|0x821
end_define

begin_comment
comment|/* 802.11n 2x2 phy core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_SRAMC
value|0x822
end_define

begin_comment
comment|/* SRAM controller core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_MINIMAC
value|0x823
end_define

begin_comment
comment|/* MINI MAC/phy core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_ARM11
value|0x824
end_define

begin_comment
comment|/* ARM 1176 core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_ARM7S
value|0x825
end_define

begin_comment
comment|/* ARM7tdmi-s core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_LPPHY
value|0x826
end_define

begin_comment
comment|/* 802.11a/b/g phy core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_PMU
value|0x827
end_define

begin_comment
comment|/* PMU core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_SSNPHY
value|0x828
end_define

begin_comment
comment|/* 802.11n single-stream phy core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_SDIOD
value|0x829
end_define

begin_comment
comment|/* SDIO device core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_ARMCM3
value|0x82a
end_define

begin_comment
comment|/* ARM Cortex M3 core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_HTPHY
value|0x82b
end_define

begin_comment
comment|/* 802.11n 4x4 phy core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_MIPS74K
value|0x82c
end_define

begin_comment
comment|/* mips 74k core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_GMAC
value|0x82d
end_define

begin_comment
comment|/* Gigabit MAC core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_DMEMC
value|0x82e
end_define

begin_comment
comment|/* DDR1/2 memory controller core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_PCIERC
value|0x82f
end_define

begin_comment
comment|/* PCIE Root Complex core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_OCP
value|0x830
end_define

begin_comment
comment|/* OCP2OCP bridge core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_SC
value|0x831
end_define

begin_comment
comment|/* shared common core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_AHB
value|0x832
end_define

begin_comment
comment|/* OCP2AHB bridge core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_SPIH
value|0x833
end_define

begin_comment
comment|/* SPI host core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_I2S
value|0x834
end_define

begin_comment
comment|/* I2S core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_DMEMS
value|0x835
end_define

begin_comment
comment|/* SDR/DDR1 memory controller core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_UBUS_SHIM
value|0x837
end_define

begin_comment
comment|/* SHIM component in ubus/6362 */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_PCIE2
value|0x83c
end_define

begin_comment
comment|/* pci express (gen2) core */
end_comment

begin_comment
comment|/* ARM/AMBA Core IDs */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_APB_BRIDGE
value|0x135
end_define

begin_comment
comment|/* BP135 AMBA AXI-APB bridge */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_PL301
value|0x301
end_define

begin_comment
comment|/* PL301 AMBA AXI Interconnect */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_EROM
value|0x366
end_define

begin_comment
comment|/* Enumeration ROM */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_OOB_ROUTER
value|0x367
end_define

begin_comment
comment|/* OOB router core ID */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_AXI_UNMAPPED
value|0xfff
end_define

begin_comment
comment|/* AXI "Default Slave"; maps all unused address 							 * ranges, returning DECERR on read or write. */
end_comment

begin_comment
comment|/* Northstar Plus and BCM4706 Core IDs */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_4706_CC
value|0x500
end_define

begin_comment
comment|/* chipcommon core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_NS_PCIE2
value|0x501
end_define

begin_comment
comment|/* pci express (gen2) core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_NS_DMA
value|0x502
end_define

begin_comment
comment|/* dma core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_NS_SDIO
value|0x503
end_define

begin_comment
comment|/* sdio host core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_NS_USB20H
value|0x504
end_define

begin_comment
comment|/* usb 2.0 host core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_NS_USB30H
value|0x505
end_define

begin_comment
comment|/* usb 3.0 host core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_NS_A9JTAG
value|0x506
end_define

begin_comment
comment|/* ARM Cortex A9 JTAG core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_NS_DDR23_MEMC
value|0x507
end_define

begin_comment
comment|/* DDR2/3 cadence/denali memory controller core () */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_NS_ROM
value|0x508
end_define

begin_comment
comment|/* device ROM core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_NS_NAND
value|0x509
end_define

begin_comment
comment|/* NAND flash controller core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_NS_QSPI
value|0x50a
end_define

begin_comment
comment|/* QSPI flash controller core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_NS_CC_B
value|0x50b
end_define

begin_comment
comment|/* chipcommon `b' (auxiliary) core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_4706_SOCRAM
value|0x50e
end_define

begin_comment
comment|/* internal memory core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_IHOST_ARMCA9
value|0x510
end_define

begin_comment
comment|/* ARM Cortex A9 core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_4706_GMAC_CMN
value|0x5dc
end_define

begin_comment
comment|/* Gigabit MAC common core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_4706_GMAC
value|0x52d
end_define

begin_comment
comment|/* Gigabit MAC core */
end_comment

begin_define
define|#
directive|define
name|BHND_COREID_AMEMC
value|0x52e
end_define

begin_comment
comment|/* DDR1/2 cadence/denali memory controller core */
end_comment

begin_comment
comment|/* ARM PrimeCell Peripherial IDs. These were derived from inspection of the  * PrimeCell-compatible BCM4331 cores, but due to lack of documentation, the  * surmised core name/description may be incorrect. */
end_comment

begin_define
define|#
directive|define
name|BHND_PRIMEID_EROM
value|0x364
end_define

begin_comment
comment|/* Enumeration ROM's primecell ID */
end_comment

begin_define
define|#
directive|define
name|BHND_PRIMEID_SWRAP
value|0x368
end_define

begin_comment
comment|/* PL368 Device Management Interface (Slave) */
end_comment

begin_define
define|#
directive|define
name|BHND_PRIMEID_MWRAP
value|0x369
end_define

begin_comment
comment|/* PL369 Device Management Interface (Master) */
end_comment

begin_comment
comment|/* Core HW Revision Numbers */
end_comment

begin_define
define|#
directive|define
name|BHND_HWREV_INVALID
value|0xFF
end_define

begin_comment
comment|/* Invalid hardware revision ID */
end_comment

begin_comment
comment|/* Chip Types */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPTYPE_SIBA
value|0
end_define

begin_comment
comment|/**< siba(4) interconnect */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPTYPE_BCMA
value|1
end_define

begin_comment
comment|/**< bcma(4) interconnect */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPTYPE_UBUS
value|2
end_define

begin_comment
comment|/**< ubus interconnect found in bcm63xx devices */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPTYPE_BCMA_ALT
value|3
end_define

begin_comment
comment|/**< bcma(4) interconnect */
end_comment

begin_comment
comment|/** Evaluates to true if @p _type is a BCMA or BCMA-compatible interconenct */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPTYPE_IS_BCMA_COMPATIBLE
parameter_list|(
name|_type
parameter_list|)
define|\
value|((_type) == BHND_CHIPTYPE_BCMA ||	\ 	 (_type) == BHND_CHIPTYPE_BCMA_ALT ||	\ 	 (_type) == BHND_CHIPTYPE_UBUS)
end_define

begin_comment
comment|/** Evaluates to true if @p _type uses a BCMA EROM table */
end_comment

begin_define
define|#
directive|define
name|BHND_CHIPTYPE_HAS_EROM
parameter_list|(
name|_type
parameter_list|)
define|\
value|BHND_CHIPTYPE_IS_BCMA_COMPATIBLE(_type)
end_define

begin_comment
comment|/* Boardflags */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_BTC2WIRE
value|0x00000001
end_define

begin_comment
comment|/* old 2wire Bluetooth coexistence, OBSOLETE */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_BTCOEX
value|0x00000001
end_define

begin_comment
comment|/* Board supports BTCOEX */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_PACTRL
value|0x00000002
end_define

begin_comment
comment|/* Board has gpio 9 controlling the PA */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_AIRLINEMODE
value|0x00000004
end_define

begin_comment
comment|/* Board implements gpio 13 radio disable indication, UNUSED */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_ADCDIV
value|0x00000008
end_define

begin_comment
comment|/* Board has the rssi ADC divider */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_DIS_256QAM
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BHND_BFL_ENETROBO
value|0x00000010
end_define

begin_comment
comment|/* Board has robo switch or core */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_NOPLLDOWN
value|0x00000020
end_define

begin_comment
comment|/* Not ok to power down the chip pll and oscillator */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_CCKHIPWR
value|0x00000040
end_define

begin_comment
comment|/* Can do high-power CCK transmission */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_ENETADM
value|0x00000080
end_define

begin_comment
comment|/* Board has ADMtek switch */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_ENETVLAN
value|0x00000100
end_define

begin_comment
comment|/* Board has VLAN capability */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_LTECOEX
value|0x00000200
end_define

begin_comment
comment|/* Board has LTE coex capability */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_NOPCI
value|0x00000400
end_define

begin_comment
comment|/* Board leaves PCI floating */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_FEM
value|0x00000800
end_define

begin_comment
comment|/* Board supports the Front End Module */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_EXTLNA
value|0x00001000
end_define

begin_comment
comment|/* Board has an external LNA in 2.4GHz band */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_HGPA
value|0x00002000
end_define

begin_comment
comment|/* Board has a high gain PA */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_BTC2WIRE_ALTGPIO
value|0x00004000
end_define

begin_comment
comment|/* Board's BTC 2wire is in the alternate gpios OBSLETE */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_ALTIQ
value|0x00008000
end_define

begin_comment
comment|/* Alternate I/Q settings */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_NOPA
value|0x00010000
end_define

begin_comment
comment|/* Board has no PA */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_RSSIINV
value|0x00020000
end_define

begin_comment
comment|/* Board's RSSI uses positive slope(not TSSI) */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_PAREF
value|0x00040000
end_define

begin_comment
comment|/* Board uses the PARef LDO */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_3TSWITCH
value|0x00080000
end_define

begin_comment
comment|/* Board uses a triple throw switch shared with BT */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_PHASESHIFT
value|0x00100000
end_define

begin_comment
comment|/* Board can support phase shifter */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_BUCKBOOST
value|0x00200000
end_define

begin_comment
comment|/* Power topology uses BUCKBOOST */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_FEM_BT
value|0x00400000
end_define

begin_comment
comment|/* Board has FEM and switch to share antenna w/ BT */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_RXCHAIN_OFF_BT
value|0x00400000
end_define

begin_comment
comment|/* one rxchain is to be shut off when BT is active */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_NOCBUCK
value|0x00800000
end_define

begin_comment
comment|/* Power topology doesn't use CBUCK */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_CCKFAVOREVM
value|0x01000000
end_define

begin_comment
comment|/* Favor CCK EVM over spectral mask */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_PALDO
value|0x02000000
end_define

begin_comment
comment|/* Power topology uses PALDO */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_LNLDO2_2P5
value|0x04000000
end_define

begin_comment
comment|/* Select 2.5V as LNLDO2 output voltage */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_FASTPWR
value|0x08000000
end_define

begin_define
define|#
directive|define
name|BHND_BFL_UCPWRCTL_MININDX
value|0x08000000
end_define

begin_comment
comment|/* Enforce min power index to avoid FEM damage */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_EXTLNA_5GHz
value|0x10000000
end_define

begin_comment
comment|/* Board has an external LNA in 5GHz band */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_TRSW_1by2
value|0x20000000
end_define

begin_comment
comment|/* Board has 2 TRSW's in 1by2 designs */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_GAINBOOSTA01
value|0x20000000
end_define

begin_comment
comment|/* 5g Gainboost for core0 and core1 */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_LO_TRSW_R_5GHz
value|0x40000000
end_define

begin_comment
comment|/* In 5G do not throw TRSW to T for clipLO gain */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_ELNA_GAINDEF
value|0x80000000
end_define

begin_comment
comment|/* Backoff InitGain based on elna_2g/5g field 							 * when this flag is set 							 */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_EXTLNA_TX
value|0x20000000
end_define

begin_comment
comment|/* Temp boardflag to indicate to */
end_comment

begin_comment
comment|/* Boardflags2 */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_RXBB_INT_REG_DIS
value|0x00000001
end_define

begin_comment
comment|/* Board has an external rxbb regulator */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_APLL_WAR
value|0x00000002
end_define

begin_comment
comment|/* Flag to implement alternative A-band PLL settings */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_TXPWRCTRL_EN
value|0x00000004
end_define

begin_comment
comment|/* Board permits enabling TX Power Control */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_2X4_DIV
value|0x00000008
end_define

begin_comment
comment|/* Board supports the 2X4 diversity switch */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_5G_PWRGAIN
value|0x00000010
end_define

begin_comment
comment|/* Board supports 5G band power gain */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_PCIEWAR_OVR
value|0x00000020
end_define

begin_comment
comment|/* Board overrides ASPM and Clkreq settings */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_CAESERS_BRD
value|0x00000040
end_define

begin_comment
comment|/* Board is Caesers brd (unused by sw) */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_BTC3WIRE
value|0x00000080
end_define

begin_comment
comment|/* Board support legacy 3 wire or 4 wire */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_BTCLEGACY
value|0x00000080
end_define

begin_comment
comment|/* Board support legacy 3/4 wire, to replace  							 * BHND_BFL2_BTC3WIRE 							 */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_SKWRKFEM_BRD
value|0x00000100
end_define

begin_comment
comment|/* 4321mcm93 board uses Skyworks FEM */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_SPUR_WAR
value|0x00000200
end_define

begin_comment
comment|/* Board has a WAR for clock-harmonic spurs */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_GPLL_WAR
value|0x00000400
end_define

begin_comment
comment|/* Flag to narrow G-band PLL loop b/w */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_TRISTATE_LED
value|0x00000800
end_define

begin_comment
comment|/* Tri-state the LED */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_SINGLEANT_CCK
value|0x00001000
end_define

begin_comment
comment|/* Tx CCK pkts on Ant 0 only */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_2G_SPUR_WAR
value|0x00002000
end_define

begin_comment
comment|/* WAR to reduce and avoid clock-harmonic spurs in 2G */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_BPHY_ALL_TXCORES
value|0x00004000
end_define

begin_comment
comment|/* Transmit bphy frames using all tx cores */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_FCC_BANDEDGE_WAR
value|0x00008000
end_define

begin_comment
comment|/* Activates WAR to improve FCC bandedge performance */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_GPLL_WAR2
value|0x00010000
end_define

begin_comment
comment|/* Flag to widen G-band PLL loop b/w */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_IPALVLSHIFT_3P3
value|0x00020000
end_define

begin_define
define|#
directive|define
name|BHND_BFL2_INTERNDET_TXIQCAL
value|0x00040000
end_define

begin_comment
comment|/* Use internal envelope detector for TX IQCAL */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_XTALBUFOUTEN
value|0x00080000
end_define

begin_comment
comment|/* Keep the buffered Xtal output from radio on */
end_comment

begin_comment
comment|/* Most drivers will turn it off without this flag */
end_comment

begin_comment
comment|/* to save power. */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_ANAPACTRL_2G
value|0x00100000
end_define

begin_comment
comment|/* 2G ext PAs are controlled by analog PA ctrl lines */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_ANAPACTRL_5G
value|0x00200000
end_define

begin_comment
comment|/* 5G ext PAs are controlled by analog PA ctrl lines */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_ELNACTRL_TRSW_2G
value|0x00400000
end_define

begin_comment
comment|/* AZW4329: 2G gmode_elna_gain controls TR Switch */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_BT_SHARE_ANT0
value|0x00800000
end_define

begin_comment
comment|/* WLAN/BT share antenna 0 */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_BT_SHARE_BM_BIT0
value|0x00800000
end_define

begin_comment
comment|/* bit 0 of WLAN/BT shared core bitmap */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_TEMPSENSE_HIGHER
value|0x01000000
end_define

begin_comment
comment|/* The tempsense threshold can sustain higher value 							 * than programmed. The exact delta is decided by 							 * driver per chip/boardtype. This can be used 							 * when tempsense qualification happens after shipment 							 */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_BTC3WIREONLY
value|0x02000000
end_define

begin_comment
comment|/* standard 3 wire btc only.  4 wire not supported */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_PWR_NOMINAL
value|0x04000000
end_define

begin_comment
comment|/* 0: power reduction on, 1: no power reduction */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_EXTLNA_PWRSAVE
value|0x08000000
end_define

begin_comment
comment|/* boardflag to enable ucode to apply power save 						  	 * ucode control of eLNA during Tx */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_4313_RADIOREG
value|0x10000000
end_define

begin_comment
comment|/*  board rework */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_DYNAMIC_VMID
value|0x10000000
end_define

begin_comment
comment|/* boardflag to enable dynamic Vmid idle TSSI CAL */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_SDR_EN
value|0x20000000
end_define

begin_comment
comment|/* SDR enabled or disabled */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_LNA1BYPFORTR2G
value|0x40000000
end_define

begin_comment
comment|/* acphy, enable lna1 bypass for clip gain, 2g */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_LNA1BYPFORTR5G
value|0x80000000
end_define

begin_comment
comment|/* acphy, enable lna1 bypass for clip gain, 5g */
end_comment

begin_comment
comment|/* SROM 11 - 11ac boardflag definitions */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_SROM11_BTCOEX
value|0x00000001
end_define

begin_comment
comment|/* Board supports BTCOEX */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_SROM11_WLAN_BT_SH_XTL
value|0x00000002
end_define

begin_comment
comment|/* bluetooth and wlan share same crystal */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_SROM11_EXTLNA
value|0x00001000
end_define

begin_comment
comment|/* Board has an external LNA in 2.4GHz band */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_SROM11_EXTLNA_5GHz
value|0x10000000
end_define

begin_comment
comment|/* Board has an external LNA in 5GHz band */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL_SROM11_GAINBOOSTA01
value|0x20000000
end_define

begin_comment
comment|/* 5g Gainboost for core0 and core1 */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_SROM11_APLL_WAR
value|0x00000002
end_define

begin_comment
comment|/* Flag to implement alternative A-band PLL settings */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_SROM11_ANAPACTRL_2G
value|0x00100000
end_define

begin_comment
comment|/* 2G ext PAs are ctrl-ed by analog PA ctrl lines */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL2_SROM11_ANAPACTRL_5G
value|0x00200000
end_define

begin_comment
comment|/* 5G ext PAs are ctrl-ed by analog PA ctrl lines */
end_comment

begin_comment
comment|/* Boardflags3 */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_FEMCTRL_SUB
value|0x00000007
end_define

begin_comment
comment|/* acphy, subrevs of femctrl on top of srom_femctrl */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_RCAL_WAR
value|0x00000008
end_define

begin_comment
comment|/* acphy, rcal war active on this board (4335a0) */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_TXGAINTBLID
value|0x00000070
end_define

begin_comment
comment|/* acphy, txgain table id */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_TXGAINTBLID_SHIFT
value|0x4
end_define

begin_comment
comment|/* acphy, txgain table id shift bit */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_TSSI_DIV_WAR
value|0x00000080
end_define

begin_comment
comment|/* acphy, Separate paparam for 20/40/80 */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_TSSI_DIV_WAR_SHIFT
value|0x7
end_define

begin_comment
comment|/* acphy, Separate paparam for 20/40/80 shift bit */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_FEMTBL_FROM_NVRAM
value|0x00000100
end_define

begin_comment
comment|/* acphy, femctrl table is read from nvram */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_FEMTBL_FROM_NVRAM_SHIFT
value|0x8
end_define

begin_comment
comment|/* acphy, femctrl table is read from nvram */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_AGC_CFG_2G
value|0x00000200
end_define

begin_comment
comment|/* acphy, gain control configuration for 2G */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_AGC_CFG_5G
value|0x00000400
end_define

begin_comment
comment|/* acphy, gain control configuration for 5G */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_PPR_BIT_EXT
value|0x00000800
end_define

begin_comment
comment|/* acphy, bit position for 1bit extension for ppr */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_PPR_BIT_EXT_SHIFT
value|11
end_define

begin_comment
comment|/* acphy, bit shift for 1bit extension for ppr */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_BBPLL_SPR_MODE_DIS
value|0x00001000
end_define

begin_comment
comment|/* acphy, disables bbpll spur modes */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_RCAL_OTP_VAL_EN
value|0x00002000
end_define

begin_comment
comment|/* acphy, to read rcal_trim value from otp */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_2GTXGAINTBL_BLANK
value|0x00004000
end_define

begin_comment
comment|/* acphy, blank the first X ticks of 2g gaintbl */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_2GTXGAINTBL_BLANK_SHIFT
value|14
end_define

begin_comment
comment|/* acphy, blank the first X ticks of 2g gaintbl */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_5GTXGAINTBL_BLANK
value|0x00008000
end_define

begin_comment
comment|/* acphy, blank the first X ticks of 5g gaintbl */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_5GTXGAINTBL_BLANK_SHIFT
value|15
end_define

begin_comment
comment|/* acphy, blank the first X ticks of 5g gaintbl */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_BT_SHARE_BM_BIT1
value|0x40000000
end_define

begin_comment
comment|/* bit 1 of WLAN/BT shared core bitmap */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_PHASETRACK_MAX_ALPHABETA
value|0x00010000
end_define

begin_comment
comment|/* acphy, to max out alpha,beta to 511 */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_PHASETRACK_MAX_ALPHABETA_SHIFT
value|16
end_define

begin_comment
comment|/* acphy, to max out alpha,beta to 511 */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_BT_SHARE_BM_BIT1
value|0x40000000
end_define

begin_comment
comment|/* bit 1 of WLAN/BT shared core bitmap */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_EN_NONBRCM_TXBF
value|0x10000000
end_define

begin_comment
comment|/* acphy, enable non-brcm TXBF */
end_comment

begin_define
define|#
directive|define
name|BHND_BFL3_EN_P2PLINK_TXBF
value|0x20000000
end_define

begin_comment
comment|/* acphy, enable TXBF in p2p links */
end_comment

begin_comment
comment|/* board specific GPIO assignment, gpio 0-3 are also customer-configurable led */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BOARD_BTC3W_IN
value|0x850
end_define

begin_comment
comment|/* bit 4 is RF_ACTIVE, bit 6 is STATUS, bit 11 is PRI */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BOARD_BTC3W_OUT
value|0x020
end_define

begin_comment
comment|/* bit 5 is TX_CONF */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BOARD_BTCMOD_IN
value|0x010
end_define

begin_comment
comment|/* bit 4 is the alternate BT Coexistence Input */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BOARD_BTCMOD_OUT
value|0x020
end_define

begin_comment
comment|/* bit 5 is the alternate BT Coexistence Out */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BOARD_BTC_IN
value|0x080
end_define

begin_comment
comment|/* bit 7 is BT Coexistence Input */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BOARD_BTC_OUT
value|0x100
end_define

begin_comment
comment|/* bit 8 is BT Coexistence Out */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BOARD_PACTRL
value|0x200
end_define

begin_comment
comment|/* bit 9 controls the PA on new 4306 boards */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BOARD_12
value|0x1000
end_define

begin_comment
comment|/* gpio 12 */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BOARD_13
value|0x2000
end_define

begin_comment
comment|/* gpio 13 */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BOARD_BTC4_IN
value|0x0800
end_define

begin_comment
comment|/* gpio 11, coex4, in */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BOARD_BTC4_BT
value|0x2000
end_define

begin_comment
comment|/* gpio 12, coex4, bt active */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BOARD_BTC4_STAT
value|0x4000
end_define

begin_comment
comment|/* gpio 14, coex4, status */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BOARD_BTC4_WLAN
value|0x8000
end_define

begin_comment
comment|/* gpio 15, coex4, wlan active */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BOARD_1_WLAN_PWR
value|0x02
end_define

begin_comment
comment|/* throttle WLAN power on X21 board */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BOARD_3_WLAN_PWR
value|0x08
end_define

begin_comment
comment|/* throttle WLAN power on X28 board */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BOARD_4_WLAN_PWR
value|0x10
end_define

begin_comment
comment|/* throttle WLAN power on X19 board */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BTC4W_OUT_4312
value|0x010
end_define

begin_comment
comment|/* bit 4 is BT_IODISABLE */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BTC4W_OUT_43224
value|0x020
end_define

begin_comment
comment|/* bit 5 is BT_IODISABLE */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BTC4W_OUT_43224_SHARED
value|0x0e0
end_define

begin_comment
comment|/* bit 5 is BT_IODISABLE */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BTC4W_OUT_43225
value|0x0e0
end_define

begin_comment
comment|/* bit 5 BT_IODISABLE, bit 6 SW_BT, bit 7 SW_WL */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BTC4W_OUT_43421
value|0x020
end_define

begin_comment
comment|/* bit 5 is BT_IODISABLE */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BTC4W_OUT_4313
value|0x060
end_define

begin_comment
comment|/* bit 5 SW_BT, bit 6 SW_WL */
end_comment

begin_define
define|#
directive|define
name|BHND_GPIO_BTC4W_OUT_4331_SHARED
value|0x010
end_define

begin_comment
comment|/* GPIO 4  */
end_comment

begin_comment
comment|/* Board Types */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BU4710
value|0x0400
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_VSIM4710
value|0x0401
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_QT4710
value|0x0402
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BU4309
value|0x040a
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94309CB
value|0x040b
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94309MP
value|0x040c
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM4309AP
value|0x040d
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94302MP
value|0x040e
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BU4306
value|0x0416
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94306CB
value|0x0417
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94306MP
value|0x0418
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94710D
value|0x041a
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94710R1
value|0x041b
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94710R4
value|0x041c
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94710AP
value|0x041d
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BU2050
value|0x041f
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94309G
value|0x0421
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BU4704
value|0x0423
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BU4702
value|0x0424
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94306PC
value|0x0425
end_define

begin_comment
comment|/* pcmcia 3.3v 4306 card */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94702MN
value|0x0428
end_define

begin_comment
comment|/* BCM4702 1U CompactPCI Board */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94702CPCI
value|0x0429
end_define

begin_comment
comment|/* BCM4702 with BCM95380 VLAN Router */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM95380RR
value|0x042a
end_define

begin_comment
comment|/* cb4306 with SiGe PA */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94306CBSG
value|0x042b
end_define

begin_comment
comment|/* cb4306 with SiGe PA */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_PCSG94306
value|0x042d
end_define

begin_comment
comment|/* bu4704 with sdram */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BU4704SD
value|0x042e
end_define

begin_comment
comment|/* Dual 11a/11g Router */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94704AGR
value|0x042f
end_define

begin_comment
comment|/* 11a-only minipci */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94308MP
value|0x0430
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BU4712
value|0x0444
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BU4712SD
value|0x045d
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BU4712L
value|0x045f
end_define

begin_comment
comment|/* BCM4712 boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94712AP
value|0x0445
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94712P
value|0x0446
end_define

begin_comment
comment|/* BCM4318 boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BU4318
value|0x0447
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_CB4318
value|0x0448
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_MPG4318
value|0x0449
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_MP4318
value|0x044a
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_SD4318
value|0x044b
end_define

begin_comment
comment|/* BCM4313 boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94313BU
value|0x050f
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94313HM
value|0x0510
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94313EPA
value|0x0511
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94313HMG
value|0x051C
end_define

begin_comment
comment|/* BCM63XX boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM96338
value|0x6338
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM96348
value|0x6348
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM96358
value|0x6358
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM96368
value|0x6368
end_define

begin_comment
comment|/* Another mp4306 with SiGe */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94306P
value|0x044c
end_define

begin_comment
comment|/* mp4303 */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94303MP
value|0x044e
end_define

begin_comment
comment|/* mpsgh4306 */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94306MPSGH
value|0x044f
end_define

begin_comment
comment|/* BRCM 4306 w/ Front End Modules */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94306MPM
value|0x0450
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94306MPL
value|0x0453
end_define

begin_comment
comment|/* 4712agr */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94712AGR
value|0x0451
end_define

begin_comment
comment|/* pcmcia 4303 */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_PC4303
value|0x0454
end_define

begin_comment
comment|/* 5350K */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM95350K
value|0x0455
end_define

begin_comment
comment|/* 5350R */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM95350R
value|0x0456
end_define

begin_comment
comment|/* 4306mplna */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94306MPLNA
value|0x0457
end_define

begin_comment
comment|/* 4320 boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BU4320
value|0x0458
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BU4320S
value|0x0459
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94320PH
value|0x045a
end_define

begin_comment
comment|/* 4306mph */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94306MPH
value|0x045b
end_define

begin_comment
comment|/* 4306pciv */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94306PCIV
value|0x045c
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BU4712SD
value|0x045d
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94320PFLSH
value|0x045e
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BU4712L
value|0x045f
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94712LGR
value|0x0460
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94320R
value|0x0461
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BU5352
value|0x0462
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94318MPGH
value|0x0463
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BU4311
value|0x0464
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94311MC
value|0x0465
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94311MCAG
value|0x0466
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM95352GR
value|0x0467
end_define

begin_comment
comment|/* bcm95351agr */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM95351AGR
value|0x0470
end_define

begin_comment
comment|/* bcm94704mpcb */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94704MPCB
value|0x0472
end_define

begin_comment
comment|/* 4785 boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BU4785
value|0x0478
end_define

begin_comment
comment|/* 4321 boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM4321BU
value|0x046b
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM4321BUE
value|0x047c
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM4321MP
value|0x046c
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM4321CB2
value|0x046d
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM4321CB2_AG
value|0x0066
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM4321MC
value|0x046e
end_define

begin_comment
comment|/* 4328 boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BU4328
value|0x0481
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM4328SDG
value|0x0482
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM4328SDAG
value|0x0483
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM4328UG
value|0x0484
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM4328UAG
value|0x0485
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM4328PC
value|0x0486
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM4328CF
value|0x0487
end_define

begin_comment
comment|/* 4325 boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94325DEVBU
value|0x0490
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94325BGABU
value|0x0491
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94325SDGWB
value|0x0492
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94325SDGMDL
value|0x04aa
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94325SDGMDL2
value|0x04c6
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94325SDGMDL3
value|0x04c9
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94325SDABGWBA
value|0x04e1
end_define

begin_comment
comment|/* 4322 boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94322MC
value|0x04a4
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94322USB
value|0x04a8
end_define

begin_comment
comment|/* dualband */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94322HM
value|0x04b0
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94322USB2D
value|0x04bf
end_define

begin_comment
comment|/* single band discrete front end */
end_comment

begin_comment
comment|/* 4312 boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM4312MCGSG
value|0x04b5
end_define

begin_comment
comment|/* 4315 boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94315DEVBU
value|0x04c2
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94315USBGP
value|0x04c7
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94315BGABU
value|0x04ca
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94315USBGP41
value|0x04cb
end_define

begin_comment
comment|/* 4319 boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319DEVBU
value|0X04e5
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319USB
value|0X04e6
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319SD
value|0X04e7
end_define

begin_comment
comment|/* 4716 boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94716NR2
value|0x04cd
end_define

begin_comment
comment|/* 4319 boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319DEVBU
value|0X04e5
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319USBNP4L
value|0X04e6
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319WLUSBN4L
value|0X04e7
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319SDG
value|0X04ea
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319LCUSBSDN4L
value|0X04eb
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319USBB
value|0x04ee
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319LCSDN4L
value|0X0507
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319LSUSBN4L
value|0X0508
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319SDNA4L
value|0X0517
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319SDELNA4L
value|0X0518
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319SDELNA6L
value|0X0539
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319ARCADYAN
value|0X0546
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319WINDSOR
value|0x0561
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319MLAP
value|0x0562
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319SDNA
value|0x058b
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319BHEMU3
value|0x0563
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319SDHMB
value|0x058c
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319SDBREF
value|0x05a1
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94319USBSDB
value|0x05a2
end_define

begin_comment
comment|/* 4329 boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94329AGB
value|0X04b9
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94329TDKMDL1
value|0X04ba
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94329TDKMDL11
value|0X04fc
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94329OLYMPICN18
value|0X04fd
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94329OLYMPICN90
value|0X04fe
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94329OLYMPICN90U
value|0X050c
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94329OLYMPICN90M
value|0X050b
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94329AGBF
value|0X04ff
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94329OLYMPICX17
value|0X0504
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94329OLYMPICX17M
value|0X050a
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94329OLYMPICX17U
value|0X0509
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94329OLYMPICUNO
value|0X0564
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94329MOTOROLA
value|0X0565
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94329OLYMPICLOCO
value|0X0568
end_define

begin_comment
comment|/* 4336 SDIO board types */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94336SD_WLBGABU
value|0x0511
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94336SD_WLBGAREF
value|0x0519
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94336SDGP
value|0x0538
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94336SDG
value|0x0519
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94336SDGN
value|0x0538
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94336SDGFC
value|0x056B
end_define

begin_comment
comment|/* 4330 SDIO board types */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94330SDG
value|0x0528
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94330SD_FCBGABU
value|0x052e
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94330SD_WLBGABU
value|0x052f
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94330SD_FCBGA
value|0x0530
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94330FCSDAGB
value|0x0532
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94330OLYMPICAMG
value|0x0549
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94330OLYMPICAMGEPA
value|0x054F
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94330OLYMPICUNO3
value|0x0551
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94330WLSDAGB
value|0x0547
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94330CSPSDAGBB
value|0x054A
end_define

begin_comment
comment|/* 43224 boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943224X21
value|0x056e
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943224X21_FCC
value|0x00d1
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943224X21B
value|0x00e9
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943224M93
value|0x008b
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943224M93A
value|0x0090
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943224X16
value|0x0093
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94322X9
value|0x008d
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94322M35e
value|0x008e
end_define

begin_comment
comment|/* 43228 Boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943228BU8
value|0x0540
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943228BU9
value|0x0541
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943228BU
value|0x0542
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943227HM4L
value|0x0543
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943227HMB
value|0x0544
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943228HM4L
value|0x0545
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943228SD
value|0x0573
end_define

begin_comment
comment|/* 43239 Boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943239MOD
value|0x05ac
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943239REF
value|0x05aa
end_define

begin_comment
comment|/* 4331 boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331X19
value|0x00D6
end_define

begin_comment
comment|/* X19B */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331X28
value|0x00E4
end_define

begin_comment
comment|/* X28 */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331X28B
value|0x010E
end_define

begin_comment
comment|/* X28B */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331PCIEBT3Ax
value|BCM94331X28
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331X12_2G
value|0x00EC
end_define

begin_comment
comment|/* X12 2G */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331X12_5G
value|0x00ED
end_define

begin_comment
comment|/* X12 5G */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331X29B
value|0x00EF
end_define

begin_comment
comment|/* X29B */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331X29D
value|0x010F
end_define

begin_comment
comment|/* X29D */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331CSAX
value|BCM94331X29B
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331X19C
value|0x00F5
end_define

begin_comment
comment|/* X19C */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331X33
value|0x00F4
end_define

begin_comment
comment|/* X33 */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331BU
value|0x0523
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331S9BU
value|0x0524
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331MC
value|0x0525
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331MCI
value|0x0526
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331PCIEBT4
value|0x0527
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331HM
value|0x0574
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331PCIEDUAL
value|0x059B
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331MCH5
value|0x05A9
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331CS
value|0x05C6
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94331CD
value|0x05DA
end_define

begin_comment
comment|/* 4314 Boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94314BU
value|0x05b1
end_define

begin_comment
comment|/* 53572 Boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM953572BU
value|0x058D
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM953572NR2
value|0x058E
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM947188NR2
value|0x058F
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM953572SDRNR2
value|0x0590
end_define

begin_comment
comment|/* 43236 boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943236OLYMPICSULLEY
value|0x594
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943236PREPROTOBLU2O3
value|0x5b9
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943236USBELNA
value|0x5f8
end_define

begin_comment
comment|/* 4314 Boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94314BUSDIO
value|0x05c8
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94314BGABU
value|0x05c9
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94314HMEPA
value|0x05ca
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94314HMEPABK
value|0x05cb
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94314SUHMEPA
value|0x05cc
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94314SUHM
value|0x05cd
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94314HM
value|0x05d1
end_define

begin_comment
comment|/* 4334 Boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94334FCAGBI
value|0x05df
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94334WLAGBI
value|0x05dd
end_define

begin_comment
comment|/* 4335 Boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94335X52
value|0x0114
end_define

begin_comment
comment|/* 4345 Boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94345
value|0x0687
end_define

begin_comment
comment|/* 4360 Boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94360X52C
value|0X0117
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94360X52D
value|0X0137
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94360X29C
value|0X0112
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94360X29CP2
value|0X0134
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94360X51
value|0x0111
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94360X51P2
value|0x0129
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94360X51A
value|0x0135
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94360X51B
value|0x0136
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94360CS
value|0x061B
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94360J28_D11AC2G
value|0x0c00
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94360J28_D11AC5G
value|0x0c01
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94360USBH5_D11AC5G
value|0x06aa
end_define

begin_comment
comment|/* 4350 Boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94350X52B
value|0X0116
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94350X14
value|0X0131
end_define

begin_comment
comment|/* 43217 Boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943217BU
value|0x05d5
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943217HM2L
value|0x05d6
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943217HMITR2L
value|0x05d7
end_define

begin_comment
comment|/* 43142 Boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943142HM
value|0x05e0
end_define

begin_comment
comment|/* 43341 Boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943341WLABGS
value|0x062d
end_define

begin_comment
comment|/* 43342 Boards */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943342FCAGBI
value|0x0641
end_define

begin_comment
comment|/* 43602 Boards, unclear yet what boards will be created. */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943602RSVD1
value|0x06a5
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943602RSVD2
value|0x06a6
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943602X87
value|0X0133
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM943602X238
value|0X0132
end_define

begin_comment
comment|/* 4354 board types */
end_comment

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94354WLSAGBI
value|0x06db
end_define

begin_define
define|#
directive|define
name|BHND_BOARD_BCM94354Z
value|0x0707
end_define

begin_comment
comment|/* # of GPIO pins */
end_comment

begin_define
define|#
directive|define
name|BHND_BCM43XX_GPIO_NUMPINS
value|32
end_define

begin_comment
comment|/* These values are used by dhd USB host driver. */
end_comment

begin_define
define|#
directive|define
name|BHND_USB_RDL_RAM_BASE_4319
value|0x60000000
end_define

begin_define
define|#
directive|define
name|BHND_USB_RDL_RAM_BASE_4329
value|0x60000000
end_define

begin_define
define|#
directive|define
name|BHND_USB_RDL_RAM_SIZE_4319
value|0x48000
end_define

begin_define
define|#
directive|define
name|BHND_USB_RDL_RAM_SIZE_4329
value|0x48000
end_define

begin_define
define|#
directive|define
name|BHND_USB_RDL_RAM_SIZE_43236
value|0x70000
end_define

begin_define
define|#
directive|define
name|BHND_USB_RDL_RAM_BASE_43236
value|0x60000000
end_define

begin_define
define|#
directive|define
name|BHND_USB_RDL_RAM_SIZE_4328
value|0x60000
end_define

begin_define
define|#
directive|define
name|BHND_USB_RDL_RAM_BASE_4328
value|0x80000000
end_define

begin_define
define|#
directive|define
name|BHND_USB_RDL_RAM_SIZE_4322
value|0x60000
end_define

begin_define
define|#
directive|define
name|BHND_USB_RDL_RAM_BASE_4322
value|0x60000000
end_define

begin_define
define|#
directive|define
name|BHND_USB_RDL_RAM_SIZE_4360
value|0xA0000
end_define

begin_define
define|#
directive|define
name|BHND_USB_RDL_RAM_BASE_4360
value|0x60000000
end_define

begin_define
define|#
directive|define
name|BHND_USB_RDL_RAM_SIZE_43242
value|0x90000
end_define

begin_define
define|#
directive|define
name|BHND_USB_RDL_RAM_BASE_43242
value|0x60000000
end_define

begin_define
define|#
directive|define
name|BHND_USB_RDL_RAM_SIZE_43143
value|0x70000
end_define

begin_define
define|#
directive|define
name|BHND_USB_RDL_RAM_BASE_43143
value|0x60000000
end_define

begin_define
define|#
directive|define
name|BHND_USB_RDL_RAM_SIZE_4350
value|0xC0000
end_define

begin_define
define|#
directive|define
name|BHND_USB_RDL_RAM_BASE_4350
value|0x180800
end_define

begin_comment
comment|/* generic defs for nvram "muxenab" bits * Note: these differ for 4335a0. refer bcmchipc.h for specific mux options. */
end_comment

begin_define
define|#
directive|define
name|BHND_NVRAM_MUXENAB_UART
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BHND_NVRAM_MUXENAB_GPIO
value|0x00000002
end_define

begin_define
define|#
directive|define
name|BHND_NVRAM_MUXENAB_ERCX
value|0x00000004
end_define

begin_comment
comment|/* External Radio BT coex */
end_comment

begin_define
define|#
directive|define
name|BHND_NVRAM_MUXENAB_JTAG
value|0x00000008
end_define

begin_define
define|#
directive|define
name|BHND_NVRAM_MUXENAB_HOST_WAKE
value|0x00000010
end_define

begin_comment
comment|/* configure GPIO for SDIO host_wake */
end_comment

begin_define
define|#
directive|define
name|BHND_NVRAM_MUXENAB_I2S_EN
value|0x00000020
end_define

begin_define
define|#
directive|define
name|BHND_NVRAM_MUXENAB_I2S_MASTER
value|0x00000040
end_define

begin_define
define|#
directive|define
name|BHND_NVRAM_MUXENAB_I2S_FULL
value|0x00000080
end_define

begin_define
define|#
directive|define
name|BHND_NVRAM_MUXENAB_SFLASH
value|0x00000100
end_define

begin_define
define|#
directive|define
name|BHND_NVRAM_MUXENAB_RFSWCTRL0
value|0x00000200
end_define

begin_define
define|#
directive|define
name|BHND_NVRAM_MUXENAB_RFSWCTRL1
value|0x00000400
end_define

begin_define
define|#
directive|define
name|BHND_NVRAM_MUXENAB_RFSWCTRL2
value|0x00000800
end_define

begin_define
define|#
directive|define
name|BHND_NVRAM_MUXENAB_SECI
value|0x00001000
end_define

begin_define
define|#
directive|define
name|BHND_NVRAM_MUXENAB_BT_LEGACY
value|0x00002000
end_define

begin_define
define|#
directive|define
name|BHND_NVRAM_MUXENAB_HOST_WAKE1
value|0x00004000
end_define

begin_comment
comment|/* configure alternative GPIO for SDIO host_wake */
end_comment

begin_comment
comment|/* Boot flags */
end_comment

begin_define
define|#
directive|define
name|BHND_BOOTFLAG_FLASH_KERNEL_NFLASH
value|0x00000001
end_define

begin_define
define|#
directive|define
name|BHND_BOOTFLAG_FLASH_BOOT_NFLASH
value|0x00000002
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _BHND_BHND_IDS_H_ */
end_comment

end_unit

