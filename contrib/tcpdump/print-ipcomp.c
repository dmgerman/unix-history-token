begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1988, 1989, 1990, 1991, 1993, 1994  *	The Regents of the University of California.  All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_comment
comment|/* \summary: IP Payload Compression Protocol (IPComp) printer */
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

begin_struct
struct|struct
name|ipcomp
block|{
name|uint8_t
name|comp_nxt
decl_stmt|;
comment|/* Next Header */
name|uint8_t
name|comp_flags
decl_stmt|;
comment|/* Length of data, in 32bit */
name|uint16_t
name|comp_cpi
decl_stmt|;
comment|/* Compression parameter index */
block|}
struct|;
end_struct

begin_include
include|#
directive|include
file|"netdissect.h"
end_include

begin_include
include|#
directive|include
file|"extract.h"
end_include

begin_function
name|void
name|ipcomp_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|register
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|)
block|{
specifier|register
specifier|const
name|struct
name|ipcomp
modifier|*
name|ipcomp
decl_stmt|;
name|uint16_t
name|cpi
decl_stmt|;
name|ipcomp
operator|=
operator|(
specifier|const
expr|struct
name|ipcomp
operator|*
operator|)
name|bp
expr_stmt|;
name|ND_TCHECK
argument_list|(
operator|*
name|ipcomp
argument_list|)
expr_stmt|;
name|cpi
operator|=
name|EXTRACT_16BITS
argument_list|(
operator|&
name|ipcomp
operator|->
name|comp_cpi
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"IPComp(cpi=0x%04x)"
operator|,
name|cpi
operator|)
argument_list|)
expr_stmt|;
comment|/* 	 * XXX - based on the CPI, we could decompress the packet here. 	 * Packet buffer management is a headache (if we decompress, 	 * packet will become larger). 	 * 	 * We would decompress the packet and then call a routine that, 	 * based on ipcomp->comp_nxt, dissects the decompressed data. 	 * 	 * Until we do that, however, we just return -1, so that 	 * the loop that processes "protocol"/"next header" types 	 * stops - there's nothing more it can do with a compressed 	 * payload. 	 */
return|return;
name|trunc
label|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"[|IPCOMP]"
operator|)
argument_list|)
expr_stmt|;
return|return;
block|}
end_function

end_unit

