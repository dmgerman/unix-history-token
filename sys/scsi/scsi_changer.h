begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1996 Jason R. Thorpe<thorpej@and.com>  * All rights reserved.  *  * Partially based on an autochanger driver written by Stefan Grefen  * and on an autochanger driver written by the Systems Programming Group  * at the University of Utah Computer Science Department.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that the following conditions  * are met:  * 1. Redistributions of source code must retain the above copyright  *    notice, this list of conditions and the following disclaimer.  * 2. Redistributions in binary form must reproduce the above copyright  *    notice, this list of conditions and the following disclaimer in the  *    documentation and/or other materials provided with the distribution.  * 3. All advertising materials mentioning features or use of this software  *    must display the following acknowledgements:  *	This product includes software developed by Jason R. Thorpe  *	for And Communications, http://www.and.com/  * 4. The name of the author may not be used to endorse or promote products  *    derived from this software without specific prior written permission.  *  * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR  * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES  * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,  * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;  * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED  * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY  * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF  * SUCH DAMAGE.  *  *	$Id: scsi_changer.h,v 1.10 1997/03/06 15:36:15 joerg Exp $  */
end_comment

begin_comment
comment|/*  * SCSI changer interface description  */
end_comment

begin_comment
comment|/*  * Partially derived from software written by Stefan Grefen  * (grefen@goofy.zdv.uni-mainz.de soon grefen@convex.com)  * based on the SCSI System by written Julian Elischer (julian@tfs.com)  * for TRW Financial Systems.  *  * TRW Financial Systems, in accordance with their agreement with Carnegie  * Mellon University, makes this software available to CMU to distribute  * or use in any manner that they see fit as long as this message is kept with   * the software. For this reason TFS also grants any other persons or  * organisations permission to use or modify this software.  *  * TFS supplies this software to be publicly redistributed  * on the understanding that TFS is not responsible for the correct  * functioning of this software in any circumstances.  *  * Ported to run under 386BSD by Julian Elischer (julian@tfs.com) Sept 1992  *  *	$Id: scsi_changer.h,v 1.7 1995/05/30 08:13:30 rgrimes Exp $  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_SCSI_SCSI_CHANGER_H
end_ifndef

begin_define
define|#
directive|define
name|_SCSI_SCSI_CHANGER_H
value|1
end_define

begin_comment
comment|/*  * SCSI command format  */
end_comment

begin_comment
comment|/*  * Exchange the medium in the source element with the medium  * located at the destination element.  */
end_comment

begin_struct
struct|struct
name|scsi_exchange_medium
block|{
name|u_int8_t
name|opcode
decl_stmt|;
define|#
directive|define
name|EXCHANGE_MEDIUM
value|0xa6
name|u_int8_t
name|byte2
decl_stmt|;
name|u_int8_t
name|tea
index|[
literal|2
index|]
decl_stmt|;
comment|/* transport element address */
name|u_int8_t
name|src
index|[
literal|2
index|]
decl_stmt|;
comment|/* source address */
name|u_int8_t
name|fdst
index|[
literal|2
index|]
decl_stmt|;
comment|/* first destination address */
name|u_int8_t
name|sdst
index|[
literal|2
index|]
decl_stmt|;
comment|/* second destination address */
name|u_int8_t
name|flags
decl_stmt|;
define|#
directive|define
name|EXCHANGE_MEDIUM_INV1
value|0x01
define|#
directive|define
name|EXCHANGE_MEDIUM_INV2
value|0x02
name|u_int8_t
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Cause the medium changer to check all elements for medium and any  * other status relevant to the element.  */
end_comment

begin_struct
struct|struct
name|scsi_initialize_elememt_status
block|{
name|u_int8_t
name|opcode
decl_stmt|;
define|#
directive|define
name|INITIALIZE_ELEMENT_STATUS
value|0x07
name|u_int8_t
name|byte2
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|3
index|]
decl_stmt|;
name|u_int8_t
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Request the changer to move a unit of media from the source element  * to the destination element.  */
end_comment

begin_struct
struct|struct
name|scsi_move_medium
block|{
name|u_int8_t
name|opcode
decl_stmt|;
define|#
directive|define
name|MOVE_MEDIUM
value|0xa5
name|u_int8_t
name|byte2
decl_stmt|;
name|u_int8_t
name|tea
index|[
literal|2
index|]
decl_stmt|;
comment|/* transport element address */
name|u_int8_t
name|src
index|[
literal|2
index|]
decl_stmt|;
comment|/* source element address */
name|u_int8_t
name|dst
index|[
literal|2
index|]
decl_stmt|;
comment|/* destination element address */
name|u_int8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
define|#
directive|define
name|MOVE_MEDIUM_INVERT
value|0x01
name|u_int8_t
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Position the specified transport element (picker) in front of  * the destination element specified.  */
end_comment

begin_struct
struct|struct
name|scsi_position_to_element
block|{
name|u_int8_t
name|opcode
decl_stmt|;
define|#
directive|define
name|POSITION_TO_ELEMENT
value|0x2b
name|u_int8_t
name|byte2
decl_stmt|;
name|u_int8_t
name|tea
index|[
literal|2
index|]
decl_stmt|;
comment|/* transport element address */
name|u_int8_t
name|dst
index|[
literal|2
index|]
decl_stmt|;
comment|/* destination element address */
name|u_int8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|flags
decl_stmt|;
define|#
directive|define
name|POSITION_TO_ELEMENT_INVERT
value|0x01
name|u_int8_t
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Request that the changer report the status of its internal elements.  */
end_comment

begin_struct
struct|struct
name|scsi_read_element_status
block|{
name|u_int8_t
name|opcode
decl_stmt|;
define|#
directive|define
name|READ_ELEMENT_STATUS
value|0xb8
name|u_int8_t
name|byte2
decl_stmt|;
define|#
directive|define
name|READ_ELEMENT_STATUS_VOLTAG
value|0x10
comment|/* report volume tag info */
comment|/* ...next 4 bits are an element type code... */
name|u_int8_t
name|sea
index|[
literal|2
index|]
decl_stmt|;
comment|/* starting element address */
name|u_int8_t
name|count
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of elements */
name|u_int8_t
name|reserved0
decl_stmt|;
name|u_int8_t
name|len
index|[
literal|3
index|]
decl_stmt|;
comment|/* length of data buffer */
name|u_int8_t
name|reserved1
decl_stmt|;
name|u_int8_t
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|scsi_request_volume_element_address
block|{
name|u_int8_t
name|opcode
decl_stmt|;
define|#
directive|define
name|REQUEST_VOLUME_ELEMENT_ADDRESS
value|0xb5
name|u_int8_t
name|byte2
decl_stmt|;
define|#
directive|define
name|REQUEST_VOLUME_ELEMENT_ADDRESS_VOLTAG
value|0x10
comment|/* ...next 4 bits are an element type code... */
name|u_int8_t
name|eaddr
index|[
literal|2
index|]
decl_stmt|;
comment|/* element address */
name|u_int8_t
name|count
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of elements */
name|u_int8_t
name|reserved0
decl_stmt|;
name|u_int8_t
name|len
index|[
literal|3
index|]
decl_stmt|;
comment|/* length of data buffer */
name|u_int8_t
name|reserved1
decl_stmt|;
name|u_int8_t
name|control
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/* XXX scsi_release */
end_comment

begin_comment
comment|/*  * Data returned by READ ELEMENT STATUS consists of an 8-byte header  * followed by one or more read_element_status_pages.  */
end_comment

begin_struct
struct|struct
name|read_element_status_header
block|{
name|u_int8_t
name|fear
index|[
literal|2
index|]
decl_stmt|;
comment|/* first element address reported */
name|u_int8_t
name|count
index|[
literal|2
index|]
decl_stmt|;
comment|/* number of elements available */
name|u_int8_t
name|reserved
decl_stmt|;
name|u_int8_t
name|nbytes
index|[
literal|3
index|]
decl_stmt|;
comment|/* byte count of all pages */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|read_element_status_page_header
block|{
name|u_int8_t
name|type
decl_stmt|;
comment|/* element type code; see type codes below */
name|u_int8_t
name|flags
decl_stmt|;
define|#
directive|define
name|READ_ELEMENT_STATUS_AVOLTAG
value|0x40
define|#
directive|define
name|READ_ELEMENT_STATUS_PVOLTAG
value|0x80
name|u_int8_t
name|edl
index|[
literal|2
index|]
decl_stmt|;
comment|/* element descriptor length */
name|u_int8_t
name|reserved
decl_stmt|;
name|u_int8_t
name|nbytes
index|[
literal|3
index|]
decl_stmt|;
comment|/* byte count of all descriptors */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|read_element_status_descriptor
block|{
name|u_int8_t
name|eaddr
index|[
literal|2
index|]
decl_stmt|;
comment|/* element address */
name|u_int8_t
name|flags1
decl_stmt|;
define|#
directive|define
name|READ_ELEMENT_STATUS_FULL
value|0x01
define|#
directive|define
name|READ_ELEMENT_STATUS_IMPEXP
value|0x02
define|#
directive|define
name|READ_ELEMENT_STATUS_EXCEPT
value|0x04
define|#
directive|define
name|READ_ELEMENT_STATUS_ACCESS
value|0x08
define|#
directive|define
name|READ_ELEMENT_STATUS_EXENAB
value|0x10
define|#
directive|define
name|READ_ELEMENT_STATUS_INENAB
value|0x20
define|#
directive|define
name|READ_ELEMENT_STATUS_MT_MASK1
value|0x05
define|#
directive|define
name|READ_ELEMENT_STATUS_ST_MASK1
value|0x0c
define|#
directive|define
name|READ_ELEMENT_STATUS_IE_MASK1
value|0x3f
define|#
directive|define
name|READ_ELEMENT_STATUS_DT_MASK1
value|0x0c
name|u_int8_t
name|reserved0
decl_stmt|;
name|u_int8_t
name|sense_code
decl_stmt|;
name|u_int8_t
name|sense_qual
decl_stmt|;
comment|/* 	 * dt_scsi_flags and dt_scsi_addr are valid only on data transport 	 * elements.  These bytes are undefined for all other element types. 	 */
name|u_int8_t
name|dt_scsi_flags
decl_stmt|;
define|#
directive|define
name|READ_ELEMENT_STATUS_DT_LUNMASK
value|0x07
define|#
directive|define
name|READ_ELEMENT_STATUS_DT_LUVALID
value|0x10
define|#
directive|define
name|READ_ELEMENT_STATUS_DT_IDVALID
value|0x20
define|#
directive|define
name|READ_ELEMENT_STATUS_DT_NOTBUS
value|0x80
name|u_int8_t
name|dt_scsi_addr
decl_stmt|;
name|u_int8_t
name|reserved1
decl_stmt|;
name|u_int8_t
name|flags2
decl_stmt|;
define|#
directive|define
name|READ_ELEMENT_STATUS_INVERT
value|0x40
define|#
directive|define
name|READ_ELEMENT_STATUS_SVALID
value|0x80
name|u_int8_t
name|ssea
index|[
literal|2
index|]
decl_stmt|;
comment|/* source storage element address */
comment|/* 	 * bytes 12-47:	Primary volume tag information. 	 *		(field omitted if PVOLTAG = 0) 	 * 	 * bytes 48-83:	Alternate volume tag information. 	 *		(field omitted if AVOLTAG = 0) 	 * 	 * bytes 84-87:	Reserved (moved up if either of the above fields 	 *		are omitted) 	 * 	 * bytes 88-end: Vendor-specific: (moved up if either of the 	 *		 above fields are missing) 	 */
block|}
struct|;
end_struct

begin_comment
comment|/* XXX add data returned by REQUEST VOLUME ELEMENT ADDRESS */
end_comment

begin_comment
comment|/* Element type codes */
end_comment

begin_define
define|#
directive|define
name|ELEMENT_TYPE_MASK
value|0x0f
end_define

begin_comment
comment|/* Note: these aren't bits */
end_comment

begin_define
define|#
directive|define
name|ELEMENT_TYPE_ALL
value|0x00
end_define

begin_define
define|#
directive|define
name|ELEMENT_TYPE_MT
value|0x01
end_define

begin_define
define|#
directive|define
name|ELEMENT_TYPE_ST
value|0x02
end_define

begin_define
define|#
directive|define
name|ELEMENT_TYPE_IE
value|0x03
end_define

begin_define
define|#
directive|define
name|ELEMENT_TYPE_DT
value|0x04
end_define

begin_comment
comment|/*  * XXX The following definitions should be common to all SCSI device types.  */
end_comment

begin_define
define|#
directive|define
name|PGCODE_MASK
value|0x3f
end_define

begin_comment
comment|/* valid page number bits in pg_code */
end_comment

begin_define
define|#
directive|define
name|PGCODE_PS
value|0x80
end_define

begin_comment
comment|/* indicates page is savable */
end_comment

begin_comment
comment|/*  * Device capabilities page.  *  * This page defines characteristics of the elemenet types in the  * medium changer device.  *  * Note in the definitions below, the following abbreviations are  * used:  *		MT	Medium transport element (picker)  *		ST	Storage transport element (slot)  *		IE	Import/export element (portal)  *		DT	Data tranfer element (tape/disk drive)  */
end_comment

begin_struct
struct|struct
name|page_device_capabilities
block|{
name|u_int8_t
name|pg_code
decl_stmt|;
comment|/* page code (0x1f) */
name|u_int8_t
name|pg_length
decl_stmt|;
comment|/* page length (0x12) */
comment|/* 	 * The STOR_xx bits indicate that an element of a given 	 * type may provide independent storage for a unit of 	 * media.  The top four bits of this value are reserved. 	 */
name|u_int8_t
name|stor
decl_stmt|;
define|#
directive|define
name|STOR_MT
value|0x01
define|#
directive|define
name|STOR_ST
value|0x02
define|#
directive|define
name|STOR_IE
value|0x04
define|#
directive|define
name|STOR_DT
value|0x08
name|u_int8_t
name|reserved0
decl_stmt|;
comment|/* 	 * The MOVE_TO_yy bits indicate the changer supports 	 * moving a unit of medium from an element of a given type to an 	 * element of type yy.  This is used to determine if a given 	 * MOVE MEDIUM command is legal.  The top four bits of each 	 * of these values are reserved. 	 */
name|u_int8_t
name|move_from_mt
decl_stmt|;
name|u_int8_t
name|move_from_st
decl_stmt|;
name|u_int8_t
name|move_from_ie
decl_stmt|;
name|u_int8_t
name|move_from_dt
decl_stmt|;
define|#
directive|define
name|MOVE_TO_MT
value|0x01
define|#
directive|define
name|MOVE_TO_ST
value|0x02
define|#
directive|define
name|MOVE_TO_IE
value|0x04
define|#
directive|define
name|MOVE_TO_DT
value|0x08
name|u_int8_t
name|reserved1
index|[
literal|2
index|]
decl_stmt|;
comment|/* 	 * Similar to above, but for EXCHANGE MEDIUM. 	 */
name|u_int8_t
name|exchange_with_mt
decl_stmt|;
name|u_int8_t
name|exchange_with_st
decl_stmt|;
name|u_int8_t
name|exchange_with_ie
decl_stmt|;
name|u_int8_t
name|exchange_with_dt
decl_stmt|;
define|#
directive|define
name|EXCHANGE_WITH_MT
value|0x01
define|#
directive|define
name|EXCHANGE_WITH_ST
value|0x02
define|#
directive|define
name|EXCHANGE_WITH_IE
value|0x04
define|#
directive|define
name|EXCHANGE_WITH_DT
value|0x08
block|}
struct|;
end_struct

begin_comment
comment|/*  * Medium changer elemement address assignment page.  *  * Some of these fields can be a little confusing, so an explanation  * is in order.  *  * Each component within a a medium changer apparatus is called an  * "element".  *  * The "medium transport element address" is the address of the first  * picker (robotic arm).  "Number of medium transport elements" tells  * us how many pickers exist in the changer.  *  * The "first storage element address" is the address of the first  * slot in the tape or disk magazine.  "Number of storage elements" tells  * us how many slots exist in the changer.  *  * The "first import/export element address" is the address of the first  * medium portal accessible both by the medium changer and an outside  * human operator.  This is where the changer might deposit tapes destined  * for some vault.  The "number of import/export elements" tells us  * not many of these portals exist in the changer.  NOTE: this number may  * be 0.  *  * The "first data transfer element address" is the address of the first  * tape or disk drive in the changer.  "Number of data transfer elements"  * tells us how many drives exist in the changer.  */
end_comment

begin_struct
struct|struct
name|page_element_address_assignment
block|{
name|u_int8_t
name|pg_code
decl_stmt|;
comment|/* page code (0x1d) */
name|u_int8_t
name|pg_length
decl_stmt|;
comment|/* page length (0x12) */
comment|/* Medium transport element address */
name|u_int8_t
name|mtea
index|[
literal|2
index|]
decl_stmt|;
comment|/* Number of medium transport elements */
name|u_int8_t
name|nmte
index|[
literal|2
index|]
decl_stmt|;
comment|/* First storage element address */
name|u_int8_t
name|fsea
index|[
literal|2
index|]
decl_stmt|;
comment|/* Number of storage elements */
name|u_int8_t
name|nse
index|[
literal|2
index|]
decl_stmt|;
comment|/* First import/export element address */
name|u_int8_t
name|fieea
index|[
literal|2
index|]
decl_stmt|;
comment|/* Number of import/export elements */
name|u_int8_t
name|niee
index|[
literal|2
index|]
decl_stmt|;
comment|/* First data transfer element address */
name|u_int8_t
name|fdtea
index|[
literal|2
index|]
decl_stmt|;
comment|/* Number of data trafer elements */
name|u_int8_t
name|ndte
index|[
literal|2
index|]
decl_stmt|;
name|u_int8_t
name|reserved
index|[
literal|2
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/*  * Transport geometry parameters page.  *  * Defines whether each medium transport element is a member of a set of  * elements that share a common robotics subsystem and whether the element  * is capable of media rotation.  One transport geometry descriptor is  * transferred for each medium transport element, beginning with the first  * medium transport element (other than the default transport element address  * of 0).  */
end_comment

begin_struct
struct|struct
name|page_transport_geometry_parameters
block|{
name|u_int8_t
name|pg_code
decl_stmt|;
comment|/* page code (0x1e) */
name|u_int8_t
name|pg_length
decl_stmt|;
comment|/* page length; variable */
comment|/* Transport geometry descriptor(s) are here. */
name|u_int8_t
name|misc
decl_stmt|;
define|#
directive|define
name|CAN_ROTATE
value|0x01
comment|/* Member number in transport element set. */
name|u_int8_t
name|member
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _SCSI_SCSI_CHANGER_H */
end_comment

end_unit

