begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Marko Kiiskila carnil@cs.tut.fi   *   * Tampere University of Technology - Telecommunications Laboratory  *  * Permission to use, copy, modify and distribute this  * software and its documentation is hereby granted,  * provided that both the copyright notice and this  * permission notice appear in all copies of the software,  * derivative works or modified versions, and any portions  * thereof, that both notices appear in supporting  * documentation, and that the use of this software is  * acknowledged in any publications resulting from using  * the software.  *   * TUT ALLOWS FREE USE OF THIS SOFTWARE IN ITS "AS IS"  * CONDITION AND DISCLAIMS ANY LIABILITY OF ANY KIND FOR  * ANY DAMAGES WHATSOEVER RESULTING FROM THE USE OF THIS  * SOFTWARE.  *   */
end_comment

begin_comment
comment|/* $Id: lane.h,v 1.3 2000/10/03 02:54:56 itojun Exp $ */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|ETHER_ADDR_LEN
end_ifndef

begin_define
define|#
directive|define
name|ETHER_ADDR_LEN
value|6
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_struct
struct|struct
name|lecdatahdr_8023
block|{
name|u_int16_t
name|le_header
decl_stmt|;
name|u_int8_t
name|h_dest
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_int8_t
name|h_source
index|[
name|ETHER_ADDR_LEN
index|]
decl_stmt|;
name|u_int16_t
name|h_type
decl_stmt|;
block|}
struct|;
end_struct

end_unit

