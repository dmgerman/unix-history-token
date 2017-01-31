begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988-1997  *	The Regents of the University of California.  All rights reserved.  *  * Copyright (c) 1998-2012  Michael Richardson<mcr@tcpdump.org>  *      The TCPDUMP project  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|"config.h"
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<netdissect-stdinc.h>
end_include

begin_include
include|#
directive|include
file|"netdissect.h"
end_include

begin_include
include|#
directive|include
file|<string.h>
end_include

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|USE_LIBSMI
end_ifdef

begin_include
include|#
directive|include
file|<smi.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/*  * Initialize anything that must be initialized before dissecting  * packets.  *  * This should be called at the beginning of the program; it does  * not need to be called, and should not be called, for every  * netdissect_options structure.  */
end_comment

begin_function
name|int
name|nd_init
parameter_list|(
name|char
modifier|*
name|errbuf
parameter_list|,
name|size_t
name|errbuf_size
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|_WIN32
name|WORD
name|wVersionRequested
decl_stmt|;
name|WSADATA
name|wsaData
decl_stmt|;
name|int
name|err
decl_stmt|;
comment|/* 	 * Request Winsock 2.2; we expect Winsock 2. 	 */
name|wVersionRequested
operator|=
name|MAKEWORD
argument_list|(
literal|2
argument_list|,
literal|2
argument_list|)
expr_stmt|;
name|err
operator|=
name|WSAStartup
argument_list|(
name|wVersionRequested
argument_list|,
operator|&
name|wsaData
argument_list|)
expr_stmt|;
if|if
condition|(
name|err
operator|!=
literal|0
condition|)
block|{
name|strlcpy
argument_list|(
name|errbuf
argument_list|,
literal|"Attempting to initialize Winsock failed"
argument_list|,
name|errbuf_size
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
endif|#
directive|endif
comment|/* _WIN32 */
ifdef|#
directive|ifdef
name|USE_LIBSMI
comment|/* 	 * XXX - should we just fail if this fails?  Some of the 	 * libsmi calls may fail. 	 */
name|smiInit
argument_list|(
literal|"tcpdump"
argument_list|)
expr_stmt|;
endif|#
directive|endif
comment|/* 	 * Clears the error buffer, and uses it so we don't get 	 * "unused argument" warnings at compile time. 	 */
name|strlcpy
argument_list|(
name|errbuf
argument_list|,
literal|""
argument_list|,
name|errbuf_size
argument_list|)
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
block|}
end_function

begin_comment
comment|/*  * Clean up anything that ndo_init() did.  */
end_comment

begin_function
name|void
name|nd_cleanup
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|USE_LIBSMI
comment|/* 	 * This appears, in libsmi 0.4.8, to do nothing if smiInit() 	 * wasn't done or failed, so we call it unconditionally. 	 */
name|smiExit
argument_list|()
expr_stmt|;
endif|#
directive|endif
ifdef|#
directive|ifdef
name|_WIN32
comment|/* 	 * Undo the WSAStartup() call above. 	 */
name|WSACleanup
argument_list|()
expr_stmt|;
endif|#
directive|endif
block|}
end_function

begin_function
name|int
name|nd_have_smi_support
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|USE_LIBSMI
return|return
operator|(
literal|1
operator|)
return|;
else|#
directive|else
return|return
operator|(
literal|0
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_comment
comment|/*  * Indicates whether an SMI module has been loaded, so that we can use  * libsmi to translate OIDs.  */
end_comment

begin_decl_stmt
name|int
name|nd_smi_module_loaded
decl_stmt|;
end_decl_stmt

begin_function
name|int
name|nd_load_smi_module
parameter_list|(
specifier|const
name|char
modifier|*
name|module
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|,
name|size_t
name|errbuf_size
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|USE_LIBSMI
if|if
condition|(
name|smiLoadModule
argument_list|(
name|module
argument_list|)
operator|==
literal|0
condition|)
block|{
name|snprintf
argument_list|(
name|errbuf
argument_list|,
name|errbuf_size
argument_list|,
literal|"could not load MIB module %s"
argument_list|,
name|module
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
block|}
name|nd_smi_module_loaded
operator|=
literal|1
expr_stmt|;
return|return
operator|(
literal|0
operator|)
return|;
else|#
directive|else
name|snprintf
argument_list|(
name|errbuf
argument_list|,
name|errbuf_size
argument_list|,
literal|"MIB module %s not loaded: no libsmi support"
argument_list|,
name|module
argument_list|)
expr_stmt|;
return|return
operator|(
operator|-
literal|1
operator|)
return|;
endif|#
directive|endif
block|}
end_function

begin_function
specifier|const
name|char
modifier|*
name|nd_smi_version_string
parameter_list|(
name|void
parameter_list|)
block|{
ifdef|#
directive|ifdef
name|USE_LIBSMI
return|return
operator|(
name|smi_version_string
operator|)
return|;
else|#
directive|else
return|return
operator|(
name|NULL
operator|)
return|;
endif|#
directive|endif
block|}
end_function

end_unit

