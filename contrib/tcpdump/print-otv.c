begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code  * distributions retain the above copyright notice and this paragraph  * in its entirety, and (2) distributions including binary code include  * the above copyright notice and this paragraph in its entirety in  * the documentation or other materials provided with the distribution.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND  * WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, WITHOUT  * LIMITATION, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE.  *  * Original code by Francesco Fondelli (francesco dot fondelli, gmail dot com)  */
end_comment

begin_comment
comment|/* \summary: Overlay Transport Virtualization (OTV) printer */
end_comment

begin_comment
comment|/* specification: draft-hasmit-otv-04 */
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
file|"extract.h"
end_include

begin_comment
comment|/*  * OTV header, draft-hasmit-otv-04  *  *     0                   1                   2                   3  *     0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1  *     +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *     |R|R|R|R|I|R|R|R|           Overlay ID                          |  *     +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  *     |          Instance ID                          | Reserved      |  *     +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+  */
end_comment

begin_function
name|void
name|otv_print
parameter_list|(
name|netdissect_options
modifier|*
name|ndo
parameter_list|,
specifier|const
name|u_char
modifier|*
name|bp
parameter_list|,
name|u_int
name|len
parameter_list|)
block|{
name|uint8_t
name|flags
decl_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"OTV, "
operator|)
argument_list|)
expr_stmt|;
if|if
condition|(
name|len
operator|<
literal|8
condition|)
goto|goto
name|trunc
goto|;
name|ND_TCHECK
argument_list|(
operator|*
name|bp
argument_list|)
expr_stmt|;
name|flags
operator|=
operator|*
name|bp
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"flags [%s] (0x%02x), "
operator|,
name|flags
operator|&
literal|0x08
condition|?
literal|"I"
else|:
literal|"."
operator|,
name|flags
operator|)
argument_list|)
expr_stmt|;
name|bp
operator|+=
literal|1
expr_stmt|;
name|ND_TCHECK2
argument_list|(
operator|*
name|bp
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"overlay %u, "
operator|,
name|EXTRACT_24BITS
argument_list|(
name|bp
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|bp
operator|+=
literal|3
expr_stmt|;
name|ND_TCHECK2
argument_list|(
operator|*
name|bp
argument_list|,
literal|3
argument_list|)
expr_stmt|;
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|"instance %u\n"
operator|,
name|EXTRACT_24BITS
argument_list|(
name|bp
argument_list|)
operator|)
argument_list|)
expr_stmt|;
name|bp
operator|+=
literal|3
expr_stmt|;
comment|/* Reserved */
name|ND_TCHECK
argument_list|(
operator|*
name|bp
argument_list|)
expr_stmt|;
name|bp
operator|+=
literal|1
expr_stmt|;
name|ether_print
argument_list|(
name|ndo
argument_list|,
name|bp
argument_list|,
name|len
operator|-
literal|8
argument_list|,
name|ndo
operator|->
name|ndo_snapend
operator|-
name|bp
argument_list|,
name|NULL
argument_list|,
name|NULL
argument_list|)
expr_stmt|;
return|return;
name|trunc
label|:
name|ND_PRINT
argument_list|(
operator|(
name|ndo
operator|,
literal|" [|OTV]"
operator|)
argument_list|)
expr_stmt|;
block|}
end_function

end_unit

