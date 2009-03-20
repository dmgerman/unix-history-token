begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988-2002  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: /tcpdump/master/tcpdump/pcap-missing.h,v 1.2.2.1 2005/06/03 22:10:16 guy Exp $ (LBL)  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|tcpdump_pcap_missing_h
end_ifndef

begin_define
define|#
directive|define
name|tcpdump_pcap_missing_h
end_define

begin_comment
comment|/*  * Declarations of functions that might be missing from libpcap.  */
end_comment

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PCAP_LIST_DATALINKS
end_ifndef

begin_function_decl
specifier|extern
name|int
name|pcap_list_datalinks
parameter_list|(
name|pcap_t
modifier|*
parameter_list|,
name|int
modifier|*
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PCAP_DATALINK_NAME_TO_VAL
end_ifndef

begin_comment
comment|/*  * We assume no platform has one but not the other.  */
end_comment

begin_function_decl
specifier|extern
name|int
name|pcap_datalink_name_to_val
parameter_list|(
specifier|const
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|pcap_datalink_val_to_name
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PCAP_DATALINK_VAL_TO_DESCRIPTION
end_ifndef

begin_function_decl
specifier|extern
specifier|const
name|char
modifier|*
name|pcap_datalink_val_to_description
parameter_list|(
name|int
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_ifndef
ifndef|#
directive|ifndef
name|HAVE_PCAP_DUMP_FTELL
end_ifndef

begin_function_decl
specifier|extern
name|long
name|pcap_dump_ftell
parameter_list|(
name|pcap_dumper_t
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_endif
endif|#
directive|endif
end_endif

end_unit

