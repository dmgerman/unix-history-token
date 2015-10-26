begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_include
include|#
directive|include
file|<ntp_types.h>
end_include

begin_function_decl
name|void
name|ntp_crypto_srandom
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|ntp_crypto_random_buf
parameter_list|(
name|void
modifier|*
name|buf
parameter_list|,
name|size_t
name|nbytes
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|long
name|ntp_random
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ntp_srandom
parameter_list|(
name|unsigned
name|long
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ntp_srandomdev
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ntp_initstate
parameter_list|(
name|unsigned
name|long
parameter_list|,
comment|/* seed for R.N.G. */
name|char
modifier|*
parameter_list|,
comment|/* pointer to state array */
name|long
comment|/* # bytes of state info */
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|char
modifier|*
name|ntp_setstate
parameter_list|(
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* pointer to state array */
end_comment

end_unit

