begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * Redistribution and use in source and binary forms, with or without  * modification, are permitted provided that: (1) source code  * distributions retain the above copyright notice and this paragraph  * in its entirety, and (2) distributions including binary code include  * the above copyright notice and this paragraph in its entirety in  * the documentation or other materials provided with the distribution.  * THIS SOFTWARE IS PROVIDED ``AS IS'' AND  * WITHOUT ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, WITHOUT  * LIMITATION, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS  * FOR A PARTICULAR PURPOSE.  *  * Functions for signature and digest verification.  *  * Original code by Hannes Gredler (hannes@juniper.net)  */
end_comment

begin_comment
comment|/* for netdissect_options */
end_comment

begin_include
include|#
directive|include
file|"netdissect.h"
end_include

begin_comment
comment|/* signature checking result codes */
end_comment

begin_define
define|#
directive|define
name|SIGNATURE_VALID
value|0
end_define

begin_define
define|#
directive|define
name|SIGNATURE_INVALID
value|1
end_define

begin_define
define|#
directive|define
name|CANT_CHECK_SIGNATURE
value|2
end_define

begin_decl_stmt
specifier|extern
specifier|const
name|struct
name|tok
name|signature_check_values
index|[]
decl_stmt|;
end_decl_stmt

begin_function_decl
specifier|extern
name|int
name|signature_verify
parameter_list|(
name|netdissect_options
modifier|*
parameter_list|,
specifier|const
name|u_char
modifier|*
parameter_list|,
name|u_int
parameter_list|,
name|u_char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

