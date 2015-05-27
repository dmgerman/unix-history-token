begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  *  fad-sita.c: Packet capture interface additions for SITA ACN devices  *  *  Copyright (c) 2007 Fulko Hew, SITA INC Canada, Inc<fulko.hew@sita.aero>  *  *  License: BSD  *  *  Redistribution and use in source and binary forms, with or without  *  modification, are permitted provided that the following conditions  *  are met:  *  *  1. Redistributions of source code must retain the above copyright  *     notice, this list of conditions and the following disclaimer.  *  2. Redistributions in binary form must reproduce the above copyright  *     notice, this list of conditions and the following disclaimer in  *     the documentation and/or other materials provided with the  *     distribution.  *  3. The names of the authors may not be used to endorse or promote  *     products derived from this software without specific prior  *     written permission.  *  *  THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR  *  IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED  *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
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
file|<string.h>
end_include

begin_include
include|#
directive|include
file|"pcap-int.h"
end_include

begin_include
include|#
directive|include
file|"pcap-sita.h"
end_include

begin_decl_stmt
specifier|extern
name|pcap_if_t
modifier|*
name|acn_if_list
decl_stmt|;
end_decl_stmt

begin_comment
comment|/* pcap's list of available interfaces */
end_comment

begin_function
name|int
name|pcap_findalldevs_interfaces
parameter_list|(
name|pcap_if_t
modifier|*
modifier|*
name|alldevsp
parameter_list|,
name|char
modifier|*
name|errbuf
parameter_list|)
block|{
comment|//printf("pcap_findalldevs()\n");				// fulko
operator|*
name|alldevsp
operator|=
literal|0
expr_stmt|;
comment|/* initialize the returned variables before we do anything */
name|strcpy
argument_list|(
name|errbuf
argument_list|,
literal|""
argument_list|)
expr_stmt|;
if|if
condition|(
name|acn_parse_hosts_file
argument_list|(
name|errbuf
argument_list|)
condition|)
comment|/* scan the hosts file for potential IOPs */
block|{
comment|//printf("pcap_findalldevs() returning BAD after parsehosts\n");				// fulko
return|return
operator|-
literal|1
return|;
block|}
comment|//printf("pcap_findalldevs() got hostlist now finding devs\n");				// fulko
if|if
condition|(
name|acn_findalldevs
argument_list|(
name|errbuf
argument_list|)
condition|)
comment|/* then ask the IOPs for their monitorable devices */
block|{
comment|//printf("pcap_findalldevs() returning BAD after findalldevs\n");				// fulko
return|return
operator|-
literal|1
return|;
block|}
operator|*
name|alldevsp
operator|=
name|acn_if_list
expr_stmt|;
name|acn_if_list
operator|=
literal|0
expr_stmt|;
comment|/* then forget our list head, because someone will call pcap_freealldevs() to empty the malloc'ed stuff */
comment|//printf("pcap_findalldevs() returning ZERO OK\n");				// fulko
return|return
literal|0
return|;
block|}
end_function

end_unit

