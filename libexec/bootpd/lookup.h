begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/* lookup.h */
end_comment

begin_comment
comment|/* $FreeBSD$ */
end_comment

begin_include
include|#
directive|include
file|"bptypes.h"
end_include

begin_comment
comment|/* for int32, u_int32 */
end_comment

begin_function_decl
specifier|extern
name|u_char
modifier|*
name|lookup_hwa
parameter_list|(
name|char
modifier|*
name|hostname
parameter_list|,
name|int
name|htype
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lookup_ipa
parameter_list|(
name|char
modifier|*
name|hostname
parameter_list|,
name|u_int32
modifier|*
name|addr
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|extern
name|int
name|lookup_netmask
parameter_list|(
name|u_int32
name|addr
parameter_list|,
name|u_int32
modifier|*
name|mask
parameter_list|)
function_decl|;
end_function_decl

end_unit

