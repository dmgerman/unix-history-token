begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*-  * Copyright (c) 2000 by Matthew Jacob  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * the GNU Public License ("GPL").  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCSI_ENC_H_
end_ifndef

begin_define
define|#
directive|define
name|_SCSI_ENC_H_
end_define

begin_include
include|#
directive|include
file|<cam/scsi/scsi_ses.h>
end_include

begin_define
define|#
directive|define
name|ENCIOC
value|('s' - 040)
end_define

begin_define
define|#
directive|define
name|ENCIOC_GETNELM
value|_IO(ENCIOC, 1)
end_define

begin_define
define|#
directive|define
name|ENCIOC_GETELMMAP
value|_IO(ENCIOC, 2)
end_define

begin_define
define|#
directive|define
name|ENCIOC_GETENCSTAT
value|_IO(ENCIOC, 3)
end_define

begin_define
define|#
directive|define
name|ENCIOC_SETENCSTAT
value|_IO(ENCIOC, 4)
end_define

begin_define
define|#
directive|define
name|ENCIOC_GETELMSTAT
value|_IO(ENCIOC, 5)
end_define

begin_define
define|#
directive|define
name|ENCIOC_SETELMSTAT
value|_IO(ENCIOC, 6)
end_define

begin_define
define|#
directive|define
name|ENCIOC_GETTEXT
value|_IO(ENCIOC, 7)
end_define

begin_define
define|#
directive|define
name|ENCIOC_INIT
value|_IO(ENCIOC, 8)
end_define

begin_define
define|#
directive|define
name|ENCIOC_GETELMDESC
value|_IO(ENCIOC, 9)
end_define

begin_define
define|#
directive|define
name|ENCIOC_GETELMDEVNAMES
value|_IO(ENCIOC, 10)
end_define

begin_define
define|#
directive|define
name|ENCIOC_GETSTRING
value|_IO(ENCIOC, 11)
end_define

begin_define
define|#
directive|define
name|ENCIOC_SETSTRING
value|_IO(ENCIOC, 12)
end_define

begin_comment
comment|/*  * Platform Independent Definitions for enclosure devices.  */
end_comment

begin_comment
comment|/*  * SCSI Based Environmental Services Application Defines  *  * Based almost entirely on SCSI-3 ENC Revision 8A specification,  * but slightly abstracted as the underlying device may in fact  * be a SAF-TE or vendor unique device.  */
end_comment

begin_comment
comment|/*  * ENC Driver Operations:  * (The defines themselves are platform and access method specific)  *  * ENCIOC_GETNELM  * ENCIOC_GETELMMAP  * ENCIOC_GETENCSTAT  * ENCIOC_SETENCSTAT  * ENCIOC_GETELMSTAT  * ENCIOC_SETELMSTAT  * ENCIOC_INIT  *  *  * An application finds out how many elements an enclosure instance  * is managing by performing a ENCIOC_GETNELM operation. It then  * performs a ENCIOC_GETELMMAP to get the map that contains the  * elment identifiers for all elements (see encioc_element_t below).  * This information is static.  *   * The application may perform ENCIOC_GETELMSTAT operations to retrieve  * status on an element (see the enc_elm_status_t structure below),  * ENCIOC_SETELMSTAT operations to set status for an element.  *  * Similarly, overall enclosure status me be fetched or set via  * ENCIOC_GETENCSTAT or  ENCIOC_SETENCSTAT operations (see encioc_enc_status_t  * below).  *  * Readers should note that there is nothing that requires either a set  * or a clear operation to actually latch and do anything in the target.  *  * A ENCIOC_INIT operation causes the enclosure to be initialized.  */
end_comment

begin_comment
comment|/* Element Types */
end_comment

begin_typedef
typedef|typedef
enum|enum
block|{
name|ELMTYP_UNSPECIFIED
init|=
literal|0x00
block|,
name|ELMTYP_DEVICE
init|=
literal|0x01
block|,
name|ELMTYP_POWER
init|=
literal|0x02
block|,
name|ELMTYP_FAN
init|=
literal|0x03
block|,
name|ELMTYP_THERM
init|=
literal|0x04
block|,
name|ELMTYP_DOORLOCK
init|=
literal|0x05
block|,
name|ELMTYP_ALARM
init|=
literal|0x06
block|,
name|ELMTYP_ESCC
init|=
literal|0x07
block|,
comment|/* Enclosure SCC */
name|ELMTYP_SCC
init|=
literal|0x08
block|,
comment|/* SCC */
name|ELMTYP_NVRAM
init|=
literal|0x09
block|,
name|ELMTYP_INV_OP_REASON
init|=
literal|0x0a
block|,
name|ELMTYP_UPS
init|=
literal|0x0b
block|,
name|ELMTYP_DISPLAY
init|=
literal|0x0c
block|,
name|ELMTYP_KEYPAD
init|=
literal|0x0d
block|,
name|ELMTYP_ENCLOSURE
init|=
literal|0x0e
block|,
name|ELMTYP_SCSIXVR
init|=
literal|0x0f
block|,
name|ELMTYP_LANGUAGE
init|=
literal|0x10
block|,
name|ELMTYP_COMPORT
init|=
literal|0x11
block|,
name|ELMTYP_VOM
init|=
literal|0x12
block|,
name|ELMTYP_AMMETER
init|=
literal|0x13
block|,
name|ELMTYP_SCSI_TGT
init|=
literal|0x14
block|,
name|ELMTYP_SCSI_INI
init|=
literal|0x15
block|,
name|ELMTYP_SUBENC
init|=
literal|0x16
block|,
name|ELMTYP_ARRAY_DEV
init|=
literal|0x17
block|,
name|ELMTYP_SAS_EXP
init|=
literal|0x18
block|,
comment|/* SAS expander */
name|ELMTYP_SAS_CONN
init|=
literal|0x19
comment|/* SAS connector */
block|}
name|elm_type_t
typedef|;
end_typedef

begin_typedef
typedef|typedef
struct|struct
name|encioc_element
block|{
comment|/* Element Index */
name|unsigned
name|int
name|elm_idx
decl_stmt|;
comment|/* ID of SubEnclosure containing Element*/
name|unsigned
name|int
name|elm_subenc_id
decl_stmt|;
comment|/* Element Type */
name|elm_type_t
name|elm_type
decl_stmt|;
block|}
name|encioc_element_t
typedef|;
end_typedef

begin_comment
comment|/*  * Overall Enclosure Status  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|encioc_enc_status_t
typedef|;
end_typedef

begin_comment
comment|/*  * Element Status  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|encioc_elm_status
block|{
name|unsigned
name|int
name|elm_idx
decl_stmt|;
name|unsigned
name|char
name|cstat
index|[
literal|4
index|]
decl_stmt|;
block|}
name|encioc_elm_status_t
typedef|;
end_typedef

begin_comment
comment|/*  * ENC String structure, for StringIn and StringOut commands; use this with  * the ENCIOC_GETSTRING and ENCIOC_SETSTRING ioctls.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|encioc_string
block|{
name|size_t
name|bufsiz
decl_stmt|;
comment|/* IN/OUT: length of string provided/returned */
define|#
directive|define
name|ENC_STRING_MAX
value|0xffff
name|uint8_t
modifier|*
name|buf
decl_stmt|;
comment|/* IN/OUT: string */
block|}
name|encioc_string_t
typedef|;
end_typedef

begin_comment
comment|/*============================================================================*/
end_comment

begin_comment
comment|/*   * SES v2 r20 6.1.10 (pg 39) - Element Descriptor diagnostic page  * Tables 21, 22, and 23  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|encioc_elm_desc
block|{
name|unsigned
name|int
name|elm_idx
decl_stmt|;
comment|/* IN: elment requested */
name|uint16_t
name|elm_desc_len
decl_stmt|;
comment|/* IN: buffer size; OUT: bytes written */
name|char
modifier|*
name|elm_desc_str
decl_stmt|;
comment|/* IN/OUT: buffer for descriptor data */
block|}
name|encioc_elm_desc_t
typedef|;
end_typedef

begin_comment
comment|/*  * ENCIOC_GETELMDEVNAMES:  * ioctl structure to get an element's device names, if available  */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|encioc_elm_devnames
block|{
name|unsigned
name|int
name|elm_idx
decl_stmt|;
comment|/* IN: element index */
name|size_t
name|elm_names_size
decl_stmt|;
comment|/* IN: size of elm_devnames */
name|size_t
name|elm_names_len
decl_stmt|;
comment|/* OUT: actual size returned */
comment|/* 	 * IN/OUT: comma separated list of peripheral driver 	 * instances servicing this element. 	 */
name|char
modifier|*
name|elm_devnames
decl_stmt|;
block|}
name|encioc_elm_devnames_t
typedef|;
end_typedef

begin_comment
comment|/* ioctl structure for requesting FC info for a port */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|encioc_elm_fc_port
block|{
name|unsigned
name|int
name|elm_idx
decl_stmt|;
name|unsigned
name|int
name|port_idx
decl_stmt|;
name|struct
name|ses_elm_fc_port
name|port_data
decl_stmt|;
block|}
name|encioc_elm_fc_port_t
typedef|;
end_typedef

begin_comment
comment|/* ioctl structure for requesting SAS info for element phys */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|encioc_elm_sas_device_phy
block|{
name|unsigned
name|int
name|elm_idx
decl_stmt|;
name|unsigned
name|int
name|phy_idx
decl_stmt|;
name|struct
name|ses_elm_sas_device_phy
name|phy_data
decl_stmt|;
block|}
name|enioc_elm_sas_phy_t
typedef|;
end_typedef

begin_comment
comment|/* ioctl structure for requesting SAS info for an expander phy */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|encioc_elm_sas_expander_phy
block|{
name|unsigned
name|int
name|elm_idx
decl_stmt|;
name|unsigned
name|int
name|phy_idx
decl_stmt|;
name|struct
name|ses_elm_sas_expander_phy
name|phy_data
decl_stmt|;
block|}
name|encioc_elm_sas_expander_phy_t
typedef|;
end_typedef

begin_comment
comment|/* ioctl structure for requesting SAS info for a port phy */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|encioc_elm_sas_port_phy
block|{
name|unsigned
name|int
name|elm_idx
decl_stmt|;
name|unsigned
name|int
name|phy_idx
decl_stmt|;
name|struct
name|ses_elm_sas_port_phy
name|phy_data
decl_stmt|;
block|}
name|enioc_elm_sas_port_phy_t
typedef|;
end_typedef

begin_comment
comment|/* ioctl structure for requesting additional status for an element */
end_comment

begin_typedef
typedef|typedef
struct|struct
name|encioc_addl_status
block|{
name|unsigned
name|int
name|elm_idx
decl_stmt|;
name|union
name|ses_elm_addlstatus_descr_hdr
name|addl_hdr
decl_stmt|;
name|union
name|ses_elm_addlstatus_proto_hdr
name|proto_hdr
decl_stmt|;
block|}
name|enioc_addl_status_t
typedef|;
end_typedef

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCSI_ENC_H_ */
end_comment

end_unit

