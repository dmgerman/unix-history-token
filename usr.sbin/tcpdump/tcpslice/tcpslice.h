begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Copyright (c) 1987-1990 The Regents of the University of California.  * All rights reserved.  *  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code distributions  * retain the above copyright notice and this paragraph in its entirety, (2)  * distributions including binary code include the above copyright notice and  * this paragraph in its entirety in the documentation or other materials  * provided with the distribution, and (3) all advertising materials mentioning  * features or use of this software display the following acknowledgement:  * ``This product includes software developed by the University of California,  * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of  * the University nor the names of its contributors may be used to endorse  * or promote products derived from this software without specific prior  * written permission.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED  * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF  * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  */
end_comment

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<sys/time.h>
end_include

begin_include
include|#
directive|include
file|<sys/file.h>
end_include

begin_include
include|#
directive|include
file|<sys/stat.h>
end_include

begin_include
include|#
directive|include
file|<net/bpf.h>
end_include

begin_include
include|#
directive|include
file|<ctype.h>
end_include

begin_ifdef
ifdef|#
directive|ifdef
name|SOLARIS
end_ifdef

begin_include
include|#
directive|include
file|<fcntl.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_ifdef
ifdef|#
directive|ifdef
name|__STDC__
end_ifdef

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<stdio.h>
end_include

begin_if
if|#
directive|if
name|__STDC__
end_if

begin_include
include|#
directive|include
file|<stdarg.h>
end_include

begin_else
else|#
directive|else
end_else

begin_include
include|#
directive|include
file|<varargs.h>
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
file|<unistd.h>
end_include

begin_include
include|#
directive|include
file|"pcap.h"
end_include

begin_include
include|#
directive|include
file|"version.h"
end_include

begin_function_decl
name|time_t
name|gwtm2secs
parameter_list|(
name|struct
name|tm
modifier|*
name|tm
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sf_find_end
parameter_list|(
name|struct
name|pcap
modifier|*
name|p
parameter_list|,
name|struct
name|timeval
modifier|*
name|first_timestamp
parameter_list|,
name|struct
name|timeval
modifier|*
name|last_timestamp
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sf_timestamp_less_than
parameter_list|(
name|struct
name|timeval
modifier|*
name|t1
parameter_list|,
name|struct
name|timeval
modifier|*
name|t2
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|sf_find_packet
parameter_list|(
name|struct
name|pcap
modifier|*
name|p
parameter_list|,
name|struct
name|timeval
modifier|*
name|min_time
parameter_list|,
name|long
name|min_pos
parameter_list|,
name|struct
name|timeval
modifier|*
name|max_time
parameter_list|,
name|long
name|max_pos
parameter_list|,
name|struct
name|timeval
modifier|*
name|desired_time
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|error
parameter_list|(
specifier|const
name|char
modifier|*
name|fmt
parameter_list|,
modifier|...
parameter_list|)
function_decl|;
end_function_decl

end_unit

