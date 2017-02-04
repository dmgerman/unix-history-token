begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996, 1997, 2000  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * Support for splitting captures into multiple files with a maximum  * file size:  *  * Copyright (c) 2001  *	Seth Webster<swebster@sst.ll.mit.edu>  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|print_h
end_ifndef

begin_define
define|#
directive|define
name|print_h
end_define

begin_function_decl
name|void
name|init_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
name|uint32_t
name|localnet
parameter_list|,
name|uint32_t
name|mask
parameter_list|,
name|uint32_t
name|timezone_offset
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|has_printer
parameter_list|(
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|if_printer
name|get_if_printer
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
name|int
name|type
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|pretty_print_packet
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|struct
name|pcap_pkthdr
modifier|*
name|h
parameter_list|,
specifier|const
name|u_char
modifier|*
name|sp
parameter_list|,
name|u_int
name|packets_captured
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ndo_set_function_pointers
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* print_h */
end_comment

end_unit

