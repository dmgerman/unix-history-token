begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (C) 2004  Internet Systems Consortium, Inc. ("ISC")  * Copyright (C) 2000, 2001  Internet Software Consortium.  *  * Permission to use, copy, modify, and distribute this software for any  * purpose with or without fee is hereby granted, provided that the above  * copyright notice and this permission notice appear in all copies.  *  * THE SOFTWARE IS PROVIDED "AS IS" AND ISC DISCLAIMS ALL WARRANTIES WITH  * REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY  * AND FITNESS.  IN NO EVENT SHALL ISC BE LIABLE FOR ANY SPECIAL, DIRECT,  * INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM  * LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE  * OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR  * PERFORMANCE OF THIS SOFTWARE.  */
end_comment

begin_comment
comment|/* $Id: lwbuffer.h,v 1.15.206.1 2004/03/06 08:15:35 marka Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|LWRES_LWBUFFER_H
end_ifndef

begin_define
define|#
directive|define
name|LWRES_LWBUFFER_H
value|1
end_define

begin_comment
comment|/*****  ***** Module Info  *****/
end_comment

begin_comment
comment|/*  * Buffers  *  * A buffer is a region of memory, together with a set of related subregions.  * Buffers are used for parsing and I/O operations.  *  * The 'used region' and the 'available' region are disjoint, and their  * union is the buffer's region.  The used region extends from the beginning  * of the buffer region to the last used byte.  The available region  * extends from one byte greater than the last used byte to the end of the  * buffer's region.  The size of the used region can be changed using various  * buffer commands.  Initially, the used region is empty.  *  * The used region is further subdivided into two disjoint regions: the  * 'consumed region' and the 'remaining region'.  The union of these two  * regions is the used region.  The consumed region extends from the beginning  * of the used region to the byte before the 'current' offset (if any).  The  * 'remaining' region the current pointer to the end of the used  * region.  The size of the consumed region can be changed using various  * buffer commands.  Initially, the consumed region is empty.  *  * The 'active region' is an (optional) subregion of the remaining region.  * It extends from the current offset to an offset in the remaining region  * that is selected with lwres_buffer_setactive().  Initially, the active  * region is empty.  If the current offset advances beyond the chosen offset,  * the active region will also be empty.  *  *  /----- used region -----\/-- available --\  *  +----------------------------------------+  *  | consumed  | remaining |                |  *  +----------------------------------------+  *  a           b     c     d                e  *  * a == base of buffer.  * b == current pointer.  Can be anywhere between a and d.  * c == active pointer.  Meaningful between b and d.  * d == used pointer.  * e == length of buffer.  *  * a-e == entire (length) of buffer.  * a-d == used region.  * a-b == consumed region.  * b-d == remaining region.  * b-c == optional active region.  *  * The following invariants are maintained by all routines:  *  *	length> 0  *  *	base is a valid pointer to length bytes of memory  *  *	0<= used<= length  *  *	0<= current<= used  *  *	0<= active<= used  *	(although active< current implies empty active region)  *  * MP:  *	Buffers have no synchronization.  Clients must ensure exclusive  *	access.  *  * Reliability:  *	No anticipated impact.  *  * Resources:  *	Memory: 1 pointer + 6 unsigned integers per buffer.  *  * Security:  *	No anticipated impact.  *  * Standards:  *	None.  */
end_comment

begin_comment
comment|/***  *** Imports  ***/
end_comment

begin_include
include|#
directive|include
file|<lwres/lang.h>
end_include

begin_include
include|#
directive|include
file|<lwres/int.h>
end_include

begin_macro
name|LWRES_LANG_BEGINDECLS
end_macro

begin_comment
comment|/***  *** Magic numbers  ***/
end_comment

begin_define
define|#
directive|define
name|LWRES_BUFFER_MAGIC
value|0x4275663fU
end_define

begin_comment
comment|/* Buf?. */
end_comment

begin_define
define|#
directive|define
name|LWRES_BUFFER_VALID
parameter_list|(
name|b
parameter_list|)
value|((b) != NULL&& \ 					 (b)->magic == LWRES_BUFFER_MAGIC)
end_define

begin_comment
comment|/*  * The following macros MUST be used only on valid buffers.  It is the  * caller's responsibility to ensure this by using the LWRES_BUFFER_VALID  * check above, or by calling another lwres_buffer_*() function (rather than  * another macro.)  */
end_comment

begin_comment
comment|/*  * Get the length of the used region of buffer "b"  */
end_comment

begin_define
define|#
directive|define
name|LWRES_BUFFER_USEDCOUNT
parameter_list|(
name|b
parameter_list|)
value|((b)->used)
end_define

begin_comment
comment|/*  * Get the length of the available region of buffer "b"  */
end_comment

begin_define
define|#
directive|define
name|LWRES_BUFFER_AVAILABLECOUNT
parameter_list|(
name|b
parameter_list|)
value|((b)->length - (b)->used)
end_define

begin_define
define|#
directive|define
name|LWRES_BUFFER_REMAINING
parameter_list|(
name|b
parameter_list|)
value|((b)->used - (b)->current)
end_define

begin_comment
comment|/*  * Note that the buffer structure is public.  This is principally so buffer  * operations can be implemented using macros.  Applications are strongly  * discouraged from directly manipulating the structure.  */
end_comment

begin_typedef
typedef|typedef
name|struct
name|lwres_buffer
name|lwres_buffer_t
typedef|;
end_typedef

begin_struct
struct|struct
name|lwres_buffer
block|{
name|unsigned
name|int
name|magic
decl_stmt|;
name|unsigned
name|char
modifier|*
name|base
decl_stmt|;
comment|/* The following integers are byte offsets from 'base'. */
name|unsigned
name|int
name|length
decl_stmt|;
name|unsigned
name|int
name|used
decl_stmt|;
name|unsigned
name|int
name|current
decl_stmt|;
name|unsigned
name|int
name|active
decl_stmt|;
block|}
struct|;
end_struct

begin_comment
comment|/***  *** Functions  ***/
end_comment

begin_function_decl
name|void
name|lwres_buffer_init
parameter_list|(
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
name|void
modifier|*
name|base
parameter_list|,
name|unsigned
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make 'b' refer to the 'length'-byte region starting at base.  *  * Requires:  *  *	'length'> 0  *  *	'base' is a pointer to a sequence of 'length' bytes.  *  */
end_comment

begin_function_decl
name|void
name|lwres_buffer_invalidate
parameter_list|(
name|lwres_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make 'b' an invalid buffer.  *  * Requires:  *	'b' is a valid buffer.  *  * Ensures:  *	If assertion checking is enabled, future attempts to use 'b' without  *	calling lwres_buffer_init() on it will cause an assertion failure.  */
end_comment

begin_function_decl
name|void
name|lwres_buffer_add
parameter_list|(
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Increase the 'used' region of 'b' by 'n' bytes.  *  * Requires:  *  *	'b' is a valid buffer  *  *	used + n<= length  *  */
end_comment

begin_function_decl
name|void
name|lwres_buffer_subtract
parameter_list|(
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Decrease the 'used' region of 'b' by 'n' bytes.  *  * Requires:  *  *	'b' is a valid buffer  *  *	used>= n  *  */
end_comment

begin_function_decl
name|void
name|lwres_buffer_clear
parameter_list|(
name|lwres_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make the used region empty.  *  * Requires:  *  *	'b' is a valid buffer  *  * Ensures:  *  *	used = 0  *  */
end_comment

begin_function_decl
name|void
name|lwres_buffer_first
parameter_list|(
name|lwres_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Make the consumed region empty.  *  * Requires:  *  *	'b' is a valid buffer  *  * Ensures:  *  *	current == 0  *  */
end_comment

begin_function_decl
name|void
name|lwres_buffer_forward
parameter_list|(
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Increase the 'consumed' region of 'b' by 'n' bytes.  *  * Requires:  *  *	'b' is a valid buffer  *  *	current + n<= used  *  */
end_comment

begin_function_decl
name|void
name|lwres_buffer_back
parameter_list|(
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
name|unsigned
name|int
name|n
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Decrease the 'consumed' region of 'b' by 'n' bytes.  *  * Requires:  *  *	'b' is a valid buffer  *  *	n<= current  *  */
end_comment

begin_function_decl
name|lwres_uint8_t
name|lwres_buffer_getuint8
parameter_list|(
name|lwres_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Read an unsigned 8-bit integer from 'b' and return it.  *  * Requires:  *  *	'b' is a valid buffer.  *  *	The length of the available region of 'b' is at least 1.  *  * Ensures:  *  *	The current pointer in 'b' is advanced by 1.  *  * Returns:  *  *	A 8-bit unsigned integer.  */
end_comment

begin_function_decl
name|void
name|lwres_buffer_putuint8
parameter_list|(
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
name|lwres_uint8_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Store an unsigned 8-bit integer from 'val' into 'b'.  *  * Requires:  *	'b' is a valid buffer.  *  *	The length of the unused region of 'b' is at least 1.  *  * Ensures:  *	The used pointer in 'b' is advanced by 1.  */
end_comment

begin_function_decl
name|lwres_uint16_t
name|lwres_buffer_getuint16
parameter_list|(
name|lwres_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Read an unsigned 16-bit integer in network byte order from 'b', convert  * it to host byte order, and return it.  *  * Requires:  *  *	'b' is a valid buffer.  *  *	The length of the available region of 'b' is at least 2.  *  * Ensures:  *  *	The current pointer in 'b' is advanced by 2.  *  * Returns:  *  *	A 16-bit unsigned integer.  */
end_comment

begin_function_decl
name|void
name|lwres_buffer_putuint16
parameter_list|(
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
name|lwres_uint16_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Store an unsigned 16-bit integer in host byte order from 'val'  * into 'b' in network byte order.  *  * Requires:  *	'b' is a valid buffer.  *  *	The length of the unused region of 'b' is at least 2.  *  * Ensures:  *	The used pointer in 'b' is advanced by 2.  */
end_comment

begin_function_decl
name|lwres_uint32_t
name|lwres_buffer_getuint32
parameter_list|(
name|lwres_buffer_t
modifier|*
name|b
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Read an unsigned 32-bit integer in network byte order from 'b', convert  * it to host byte order, and return it.  *  * Requires:  *  *	'b' is a valid buffer.  *  *	The length of the available region of 'b' is at least 2.  *  * Ensures:  *  *	The current pointer in 'b' is advanced by 2.  *  * Returns:  *  *	A 32-bit unsigned integer.  */
end_comment

begin_function_decl
name|void
name|lwres_buffer_putuint32
parameter_list|(
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
name|lwres_uint32_t
name|val
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Store an unsigned 32-bit integer in host byte order from 'val'  * into 'b' in network byte order.  *  * Requires:  *	'b' is a valid buffer.  *  *	The length of the unused region of 'b' is at least 4.  *  * Ensures:  *	The used pointer in 'b' is advanced by 4.  */
end_comment

begin_function_decl
name|void
name|lwres_buffer_putmem
parameter_list|(
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
specifier|const
name|unsigned
name|char
modifier|*
name|base
parameter_list|,
name|unsigned
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Copy 'length' bytes of memory at 'base' into 'b'.  *  * Requires:  *	'b' is a valid buffer.  *  *	'base' points to 'length' bytes of valid memory.  *  */
end_comment

begin_function_decl
name|void
name|lwres_buffer_getmem
parameter_list|(
name|lwres_buffer_t
modifier|*
name|b
parameter_list|,
name|unsigned
name|char
modifier|*
name|base
parameter_list|,
name|unsigned
name|int
name|length
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/*  * Copy 'length' bytes of memory from 'b' into 'base'.  *  * Requires:  *	'b' is a valid buffer.  *  *	'base' points to at least 'length' bytes of valid memory.  *  *	'b' have at least 'length' bytes remaining.  */
end_comment

begin_macro
name|LWRES_LANG_ENDDECLS
end_macro

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* LWRES_LWBUFFER_H */
end_comment

end_unit

