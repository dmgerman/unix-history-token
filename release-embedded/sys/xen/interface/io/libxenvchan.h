begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/**  * @file  * @section AUTHORS  *  * Copyright (C) 2010  Rafal Wojtczuk<rafal@invisiblethingslab.com>  *  *  Authors:  *       Rafal Wojtczuk<rafal@invisiblethingslab.com>  *       Daniel De Graaf<dgdegra@tycho.nsa.gov>  *  * @section LICENSE  *  *  This library is free software; you can redistribute it and/or  *  modify it under the terms of the GNU Lesser General Public  *  License as published by the Free Software Foundation; either  *  version 2.1 of the License, or (at your option) any later version.  *  *  This library is distributed in the hope that it will be useful,  *  but WITHOUT ANY WARRANTY; without even the implied warranty of  *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU  *  Lesser General Public License for more details.  *  *  You should have received a copy of the GNU Lesser General Public  *  License along with this library; if not, write to the Free Software  *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301 USA  *  * @section DESCRIPTION  *  *  Originally borrowed from the Qubes OS Project, http://www.qubes-os.org,  *  this code has been substantially rewritten to use the gntdev and gntalloc  *  devices instead of raw MFNs and map_foreign_range.  *  *  This is a library for inter-domain communication.  A standard Xen ring  *  buffer is used, with a datagram-based interface built on top.  The grant  *  reference and event channels are shared in XenStore under a user-specified  *  path.  *  *  The ring.h macros define an asymmetric interface to a shared data structure  *  that assumes all rings reside in a single contiguous memory space. This is  *  not suitable for vchan because the interface to the ring is symmetric except  *  for the setup. Unlike the producer-consumer rings defined in ring.h, the  *  size of the rings used in vchan are determined at execution time instead of  *  compile time, so the macros in ring.h cannot be used to access the rings.  */
end_comment

begin_include
include|#
directive|include
file|<stdint.h>
end_include

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_struct
struct|struct
name|ring_shared
block|{
name|uint32_t
name|cons
decl_stmt|,
name|prod
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|VCHAN_NOTIFY_WRITE
value|0x1
end_define

begin_define
define|#
directive|define
name|VCHAN_NOTIFY_READ
value|0x2
end_define

begin_comment
comment|/**  * vchan_interface: primary shared data structure  */
end_comment

begin_struct
struct|struct
name|vchan_interface
block|{
comment|/** 	 * Standard consumer/producer interface, one pair per buffer 	 * left is client write, server read 	 * right is client read, server write 	 */
name|struct
name|ring_shared
name|left
decl_stmt|,
name|right
decl_stmt|;
comment|/** 	 * size of the rings, which determines their location 	 * 10   - at offset 1024 in ring's page 	 * 11   - at offset 2048 in ring's page 	 * 12+  - uses 2^(N-12) grants to describe the multi-page ring 	 * These should remain constant once the page is shared. 	 * Only one of the two orders can be 10 (or 11). 	 */
name|uint16_t
name|left_order
decl_stmt|,
name|right_order
decl_stmt|;
comment|/** 	 * Shutdown detection: 	 *  0: client (or server) has exited 	 *  1: client (or server) is connected 	 *  2: client has not yet connected 	 */
name|uint8_t
name|cli_live
decl_stmt|,
name|srv_live
decl_stmt|;
comment|/** 	 * Notification bits: 	 *  VCHAN_NOTIFY_WRITE: send notify when data is written 	 *  VCHAN_NOTIFY_READ: send notify when data is read (consumed) 	 * cli_notify is used for the client to inform the server of its action 	 */
name|uint8_t
name|cli_notify
decl_stmt|,
name|srv_notify
decl_stmt|;
comment|/** 	 * Grant list: ordering is left, right. Must not extend into actual ring 	 * or grow beyond the end of the initial shared page. 	 * These should remain constant once the page is shared, to allow 	 * for possible remapping by a client that restarts. 	 */
name|uint32_t
name|grants
index|[
literal|0
index|]
decl_stmt|;
block|}
struct|;
end_struct

end_unit

