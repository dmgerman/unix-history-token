begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|CRYPTO_H
end_ifndef

begin_define
define|#
directive|define
name|CRYPTO_H
end_define

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

begin_include
include|#
directive|include
file|<stdlib.h>
end_include

begin_include
include|#
directive|include
file|<ntp_fp.h>
end_include

begin_include
include|#
directive|include
file|<ntp.h>
end_include

begin_include
include|#
directive|include
file|<ntp_stdlib.h>
end_include

begin_include
include|#
directive|include
file|<ntp_md5.h>
end_include

begin_comment
comment|/* provides OpenSSL digest API */
end_comment

begin_include
include|#
directive|include
file|"utilities.h"
end_include

begin_include
include|#
directive|include
file|"sntp-opts.h"
end_include

begin_define
define|#
directive|define
name|LEN_PKT_MAC
value|LEN_PKT_NOMAC + sizeof(u_int32)
end_define

begin_comment
comment|/* #include "sntp-opts.h" */
end_comment

begin_struct
struct|struct
name|key
block|{
name|struct
name|key
modifier|*
name|next
decl_stmt|;
name|int
name|key_id
decl_stmt|;
name|int
name|key_len
decl_stmt|;
name|char
name|type
index|[
literal|10
index|]
decl_stmt|;
name|char
name|key_seq
index|[
literal|64
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_function_decl
name|int
name|auth_init
parameter_list|(
specifier|const
name|char
modifier|*
name|keyfile
parameter_list|,
name|struct
name|key
modifier|*
modifier|*
name|keys
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|get_key
parameter_list|(
name|int
name|key_id
parameter_list|,
name|struct
name|key
modifier|*
modifier|*
name|d_key
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|make_mac
parameter_list|(
name|char
modifier|*
name|pkt_data
parameter_list|,
name|int
name|pkt_size
parameter_list|,
name|int
name|mac_size
parameter_list|,
name|struct
name|key
modifier|*
name|cmp_key
parameter_list|,
name|char
modifier|*
name|digest
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|auth_md5
parameter_list|(
name|char
modifier|*
name|pkt_data
parameter_list|,
name|int
name|pkt_size
parameter_list|,
name|int
name|mac_size
parameter_list|,
name|struct
name|key
modifier|*
name|cmp_key
parameter_list|)
function_decl|;
end_function_decl

begin_endif
endif|#
directive|endif
end_endif

end_unit

