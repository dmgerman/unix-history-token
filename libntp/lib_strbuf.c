begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_comment
comment|/*  * lib_strbuf - library string storage  */
end_comment

begin_ifdef
ifdef|#
directive|ifdef
name|HAVE_CONFIG_H
end_ifdef

begin_include
include|#
directive|include
file|<config.h>
end_include

begin_endif
endif|#
directive|endif
end_endif

begin_include
include|#
directive|include
file|<isc/net.h>
end_include

begin_include
include|#
directive|include
file|<isc/result.h>
end_include

begin_include
include|#
directive|include
file|"ntp_fp.h"
end_include

begin_include
include|#
directive|include
file|"ntp_stdlib.h"
end_include

begin_include
include|#
directive|include
file|"lib_strbuf.h"
end_include

begin_comment
comment|/*  * Storage declarations  */
end_comment

begin_decl_stmt
name|int
name|debug
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|libbufstr
name|lib_stringbuf
index|[
name|LIB_NUMBUF
index|]
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lib_nextbuf
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipv4_works
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|ipv6_works
decl_stmt|;
end_decl_stmt

begin_decl_stmt
name|int
name|lib_inited
decl_stmt|;
end_decl_stmt

begin_comment
comment|/*  * initialization routine.  Might be needed if the code is ROMized.  */
end_comment

begin_function
name|void
name|init_lib
parameter_list|(
name|void
parameter_list|)
block|{
if|if
condition|(
name|lib_inited
condition|)
return|return;
name|ipv4_works
operator|=
operator|(
name|ISC_R_SUCCESS
operator|==
name|isc_net_probeipv4
argument_list|()
operator|)
expr_stmt|;
name|ipv6_works
operator|=
operator|(
name|ISC_R_SUCCESS
operator|==
name|isc_net_probeipv6
argument_list|()
operator|)
expr_stmt|;
name|init_systime
argument_list|()
expr_stmt|;
name|lib_inited
operator|=
name|TRUE
expr_stmt|;
block|}
end_function

end_unit

