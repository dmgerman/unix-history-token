begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 2004-2007 Voltaire Inc.  All rights reserved.  * Copyright (c) 2007 Xsigo Systems Inc.  All rights reserved.  *  * This software is available to you under a choice of one of two  * licenses.  You may choose to be licensed under the terms of the GNU  * General Public License (GPL) Version 2, available from the file  * COPYING in the main directory of this source tree, or the  * OpenIB.org BSD license below:  *  *     Redistribution and use in source and binary forms, with or  *     without modification, are permitted provided that the following  *     conditions are met:  *  *      - Redistributions of source code must retain the above  *        copyright notice, this list of conditions and the following  *        disclaimer.  *  *      - Redistributions in binary form must reproduce the above  *        copyright notice, this list of conditions and the following  *        disclaimer in the documentation and/or other materials  *        provided with the distribution.  *  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,  * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF  * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND  * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS  * BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN  * ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN  * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE  * SOFTWARE.  *  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|_IBNETDISCOVER_H_
end_ifndef

begin_define
define|#
directive|define
name|_IBNETDISCOVER_H_
end_define

begin_define
define|#
directive|define
name|MAXHOPS
value|63
end_define

begin_define
define|#
directive|define
name|CA_NODE
value|1
end_define

begin_define
define|#
directive|define
name|SWITCH_NODE
value|2
end_define

begin_define
define|#
directive|define
name|ROUTER_NODE
value|3
end_define

begin_define
define|#
directive|define
name|LIST_CA_NODE
value|(1<< CA_NODE)
end_define

begin_define
define|#
directive|define
name|LIST_SWITCH_NODE
value|(1<< SWITCH_NODE)
end_define

begin_define
define|#
directive|define
name|LIST_ROUTER_NODE
value|(1<< ROUTER_NODE)
end_define

begin_comment
comment|/* Vendor IDs (for chassis based systems) */
end_comment

begin_define
define|#
directive|define
name|VTR_VENDOR_ID
value|0x8f1
end_define

begin_comment
comment|/* Voltaire */
end_comment

begin_define
define|#
directive|define
name|TS_VENDOR_ID
value|0x5ad
end_define

begin_comment
comment|/* Cisco */
end_comment

begin_define
define|#
directive|define
name|SS_VENDOR_ID
value|0x66a
end_define

begin_comment
comment|/* InfiniCon */
end_comment

begin_define
define|#
directive|define
name|XS_VENDOR_ID
value|0x1397
end_define

begin_comment
comment|/* Xsigo */
end_comment

begin_typedef
typedef|typedef
name|struct
name|Port
name|Port
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|Node
name|Node
typedef|;
end_typedef

begin_typedef
typedef|typedef
name|struct
name|ChassisRecord
name|ChassisRecord
typedef|;
end_typedef

begin_struct
struct|struct
name|ChassisRecord
block|{
name|ChassisRecord
modifier|*
name|next
decl_stmt|;
name|unsigned
name|char
name|chassisnum
decl_stmt|;
name|unsigned
name|char
name|anafanum
decl_stmt|;
name|unsigned
name|char
name|slotnum
decl_stmt|;
name|unsigned
name|char
name|chassistype
decl_stmt|;
name|unsigned
name|char
name|chassisslot
decl_stmt|;
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Port
block|{
name|Port
modifier|*
name|next
decl_stmt|;
name|uint64_t
name|portguid
decl_stmt|;
name|int
name|portnum
decl_stmt|;
name|int
name|lid
decl_stmt|;
name|int
name|lmc
decl_stmt|;
name|int
name|state
decl_stmt|;
name|int
name|physstate
decl_stmt|;
name|int
name|linkwidth
decl_stmt|;
name|int
name|linkspeed
decl_stmt|;
name|Node
modifier|*
name|node
decl_stmt|;
name|Port
modifier|*
name|remoteport
decl_stmt|;
comment|/* null if SMA */
block|}
struct|;
end_struct

begin_struct
struct|struct
name|Node
block|{
name|Node
modifier|*
name|htnext
decl_stmt|;
name|Node
modifier|*
name|dnext
decl_stmt|;
name|Port
modifier|*
name|ports
decl_stmt|;
name|ib_portid_t
name|path
decl_stmt|;
name|int
name|type
decl_stmt|;
name|int
name|dist
decl_stmt|;
name|int
name|numports
decl_stmt|;
name|int
name|localport
decl_stmt|;
name|int
name|smalid
decl_stmt|;
name|int
name|smalmc
decl_stmt|;
name|int
name|smaenhsp0
decl_stmt|;
name|uint32_t
name|devid
decl_stmt|;
name|uint32_t
name|vendid
decl_stmt|;
name|uint64_t
name|sysimgguid
decl_stmt|;
name|uint64_t
name|nodeguid
decl_stmt|;
name|uint64_t
name|portguid
decl_stmt|;
name|char
name|nodedesc
index|[
literal|64
index|]
decl_stmt|;
name|uint8_t
name|nodeinfo
index|[
literal|64
index|]
decl_stmt|;
name|ChassisRecord
modifier|*
name|chrecord
decl_stmt|;
block|}
struct|;
end_struct

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _IBNETDISCOVER_H_ */
end_comment

end_unit

