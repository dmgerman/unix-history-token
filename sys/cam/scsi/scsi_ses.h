begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_comment
comment|/*  * Copyright (c) 2000 by Matthew Jacob  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions, and the following disclaimer,  *    without modification, immediately at the beginning of the file.  * 2. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * Alternatively, this software may be distributed under the terms of the  * the GNU Public License ("GPL").  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND  * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE FOR  * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS  * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)  * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT  * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  */
end_comment

begin_define
define|#
directive|define
name|SESIOC
value|(('s' - 040)<< 8)
end_define

begin_define
define|#
directive|define
name|SESIOC_GETNOBJ
value|_IO(SESIOC, 1)
end_define

begin_define
define|#
directive|define
name|SESIOC_GETOBJMAP
value|_IO(SESIOC, 2)
end_define

begin_define
define|#
directive|define
name|SESIOC_GETENCSTAT
value|_IO(SESIOC, 3)
end_define

begin_define
define|#
directive|define
name|SESIOC_SETENCSTAT
value|_IO(SESIOC, 4)
end_define

begin_define
define|#
directive|define
name|SESIOC_GETOBJSTAT
value|_IO(SESIOC, 5)
end_define

begin_define
define|#
directive|define
name|SESIOC_SETOBJSTAT
value|_IO(SESIOC, 6)
end_define

begin_define
define|#
directive|define
name|SESIOC_GETTEXT
value|_IO(SESIOC, 7)
end_define

begin_define
define|#
directive|define
name|SESIOC_INIT
value|_IO(SESIOC, 8)
end_define

begin_comment
comment|/*  * Platform Independent Definitions for SES devices.  */
end_comment

begin_comment
comment|/*  * SCSI Based Environmental Services Application Defines  *  * Based almost entirely on SCSI-3 SES Revision 8A specification,  * but slightly abstracted as the underlying device may in fact  * be a SAF-TE or vendor unique device.  */
end_comment

begin_comment
comment|/*  * SES Driver Operations:  * (The defines themselves are platform and access method specific)  *  * SESIOC_GETNOBJ  * SESIOC_GETOBJMAP  * SESIOC_GETENCSTAT  * SESIOC_SETENCSTAT  * SESIOC_GETOBJSTAT  * SESIOC_SETOBJSTAT  * SESIOC_INIT  *  *  * An application finds out how many objects an SES instance  * is managing by performing a SESIOC_GETNOBJ operation. It then  * performs a SESIOC_GETOBJMAP to get the map that contains the  * object identifiers for all objects (see ses_object below).  * This information is static.  *   * The application may perform SESIOC_GETOBJSTAT operations to retrieve  * status on an object (see the ses_objstat structure below), SESIOC_SETOBJSTAT  * operations to set status for an object.  *  * Similarly overall enclosure status me be fetched or set via  * SESIOC_GETENCSTAT or  SESIOC_SETENCSTAT operations (see ses_encstat below).  *  * Readers should note that there is nothing that requires either a set  * or a clear operation to actually latch and do anything in the target.  *  * A SESIOC_INIT operation causes the enclosure to be initialized.  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|obj_id
decl_stmt|;
comment|/* Object Identifier */
name|unsigned
name|char
name|subencid
decl_stmt|;
comment|/* SubEnclosure ID */
name|unsigned
name|char
name|object_type
decl_stmt|;
comment|/* Object Type */
block|}
name|ses_object
typedef|;
end_typedef

begin_comment
comment|/* Object Types */
end_comment

begin_define
define|#
directive|define
name|SESTYP_UNSPECIFIED
value|0x00
end_define

begin_define
define|#
directive|define
name|SESTYP_DEVICE
value|0x01
end_define

begin_define
define|#
directive|define
name|SESTYP_POWER
value|0x02
end_define

begin_define
define|#
directive|define
name|SESTYP_FAN
value|0x03
end_define

begin_define
define|#
directive|define
name|SESTYP_THERM
value|0x04
end_define

begin_define
define|#
directive|define
name|SESTYP_DOORLOCK
value|0x05
end_define

begin_define
define|#
directive|define
name|SESTYP_ALARM
value|0x06
end_define

begin_define
define|#
directive|define
name|SESTYP_ESCC
value|0x07
end_define

begin_comment
comment|/* Enclosure SCC */
end_comment

begin_define
define|#
directive|define
name|SESTYP_SCC
value|0x08
end_define

begin_comment
comment|/* SCC */
end_comment

begin_define
define|#
directive|define
name|SESTYP_NVRAM
value|0x09
end_define

begin_define
define|#
directive|define
name|SESTYP_UPS
value|0x0b
end_define

begin_define
define|#
directive|define
name|SESTYP_DISPLAY
value|0x0c
end_define

begin_define
define|#
directive|define
name|SESTYP_KEYPAD
value|0x0d
end_define

begin_define
define|#
directive|define
name|SESTYP_SCSIXVR
value|0x0f
end_define

begin_define
define|#
directive|define
name|SESTYP_LANGUAGE
value|0x10
end_define

begin_define
define|#
directive|define
name|SESTYP_COMPORT
value|0x11
end_define

begin_define
define|#
directive|define
name|SESTYP_VOM
value|0x12
end_define

begin_define
define|#
directive|define
name|SESTYP_AMMETER
value|0x13
end_define

begin_define
define|#
directive|define
name|SESTYP_SCSI_TGT
value|0x14
end_define

begin_define
define|#
directive|define
name|SESTYP_SCSI_INI
value|0x15
end_define

begin_define
define|#
directive|define
name|SESTYP_SUBENC
value|0x16
end_define

begin_comment
comment|/*  * Overall Enclosure Status  */
end_comment

begin_typedef
typedef|typedef
name|unsigned
name|char
name|ses_encstat
typedef|;
end_typedef

begin_define
define|#
directive|define
name|SES_ENCSTAT_UNRECOV
value|0x1
end_define

begin_define
define|#
directive|define
name|SES_ENCSTAT_CRITICAL
value|0x2
end_define

begin_define
define|#
directive|define
name|SES_ENCSTAT_NONCRITICAL
value|0x4
end_define

begin_define
define|#
directive|define
name|SES_ENCSTAT_INFO
value|0x8
end_define

begin_comment
comment|/*  * Object Status  */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|unsigned
name|int
name|obj_id
decl_stmt|;
name|unsigned
name|char
name|cstat
index|[
literal|4
index|]
decl_stmt|;
block|}
name|ses_objstat
typedef|;
end_typedef

begin_comment
comment|/* Summary SES Status Defines, Common Status Codes */
end_comment

begin_define
define|#
directive|define
name|SES_OBJSTAT_UNSUPPORTED
value|0
end_define

begin_define
define|#
directive|define
name|SES_OBJSTAT_OK
value|1
end_define

begin_define
define|#
directive|define
name|SES_OBJSTAT_CRIT
value|2
end_define

begin_define
define|#
directive|define
name|SES_OBJSTAT_NONCRIT
value|3
end_define

begin_define
define|#
directive|define
name|SES_OBJSTAT_UNRECOV
value|4
end_define

begin_define
define|#
directive|define
name|SES_OBJSTAT_NOTINSTALLED
value|5
end_define

begin_define
define|#
directive|define
name|SES_OBJSTAT_UNKNOWN
value|6
end_define

begin_define
define|#
directive|define
name|SES_OBJSTAT_NOTAVAIL
value|7
end_define

begin_comment
comment|/*  * For control pages, cstat[0] is the same for the  * enclosure and is common across all device types.  *  * If SESCTL_CSEL is set, then PRDFAIL, DISABLE and RSTSWAP  * are checked, otherwise bits that are specific to the device  * type in the other 3 bytes of cstat or checked.  */
end_comment

begin_define
define|#
directive|define
name|SESCTL_CSEL
value|0x80
end_define

begin_define
define|#
directive|define
name|SESCTL_PRDFAIL
value|0x40
end_define

begin_define
define|#
directive|define
name|SESCTL_DISABLE
value|0x20
end_define

begin_define
define|#
directive|define
name|SESCTL_RSTSWAP
value|0x10
end_define

begin_comment
comment|/* Control bits, Device Elements, byte 2 */
end_comment

begin_define
define|#
directive|define
name|SESCTL_DRVLCK
value|0x40
end_define

begin_comment
comment|/* "DO NOT REMOVE" */
end_comment

begin_define
define|#
directive|define
name|SESCTL_RQSINS
value|0x08
end_define

begin_comment
comment|/* RQST INSERT */
end_comment

begin_define
define|#
directive|define
name|SESCTL_RQSRMV
value|0x04
end_define

begin_comment
comment|/* RQST REMOVE */
end_comment

begin_define
define|#
directive|define
name|SESCTL_RQSID
value|0x02
end_define

begin_comment
comment|/* RQST IDENT */
end_comment

begin_comment
comment|/* Control bits, Device Elements, byte 3 */
end_comment

begin_define
define|#
directive|define
name|SESCTL_RQSFLT
value|0x20
end_define

begin_comment
comment|/* RQST FAULT */
end_comment

begin_define
define|#
directive|define
name|SESCTL_DEVOFF
value|0x10
end_define

begin_comment
comment|/* DEVICE OFF */
end_comment

begin_comment
comment|/* Control bits, Generic, byte 3 */
end_comment

begin_define
define|#
directive|define
name|SESCTL_RQSTFAIL
value|0x40
end_define

begin_define
define|#
directive|define
name|SESCTL_RQSTON
value|0x20
end_define

begin_comment
comment|/*  * Getting text for an object type is a little  * trickier because it's string data that can  * go up to 64 KBytes. Build this union and  * fill the obj_id with the id of the object who's  * help text you want, and if text is available,  * obj_text will be filled in, null terminated.  */
end_comment

begin_typedef
typedef|typedef
union|union
block|{
name|unsigned
name|int
name|obj_id
decl_stmt|;
name|char
name|obj_text
index|[
literal|1
index|]
decl_stmt|;
block|}
name|ses_hlptxt
typedef|;
end_typedef

end_unit

