begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1990, 1992, 1993, 1994, 1995, 1996, 1997  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  *  * @(#) $Header: /tcpdump/master/tcpdump/addrtoname.h,v 1.16 1999/10/30 05:11:07 itojun Exp $ (LBL)  */
end_comment

begin_comment
comment|/* Name to address translation routines. */
end_comment

begin_function_decl
specifier|extern
name|char
modifier|*
name|etheraddr_string
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|etherproto_string
parameter_list|(
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|tcpport_string
parameter_list|(
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|udpport_string
parameter_list|(
name|u_short
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|char
modifier|*
name|getname
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_function_decl
specifier|extern
name|char
modifier|*
name|getname6
parameter_list|(
specifier|const
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|char
modifier|*
name|intoa
parameter_list|(
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|void
name|init_addrtoname
parameter_list|(
name|u_int32_t
parameter_list|,
name|u_int32_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|struct
name|hnamemem
modifier|*
name|newhnamemem
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_function_decl
specifier|extern
name|struct
name|h6namemem
modifier|*
name|newh6namemem
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

begin_define
define|#
directive|define
name|ipaddr_string
parameter_list|(
name|p
parameter_list|)
value|getname((const u_char *)(p))
end_define

begin_ifdef
ifdef|#
directive|ifdef
name|INET6
end_ifdef

begin_define
define|#
directive|define
name|ip6addr_string
parameter_list|(
name|p
parameter_list|)
value|getname6((const u_char *)(p))
end_define

begin_endif
endif|#
directive|endif
end_endif

end_unit

