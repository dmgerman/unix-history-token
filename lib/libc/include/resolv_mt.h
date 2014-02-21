begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_ifndef
ifndef|#
directive|ifndef
name|_RESOLV_MT_H
end_ifndef

begin_define
define|#
directive|define
name|_RESOLV_MT_H
end_define

begin_include
include|#
directive|include
file|<sys/types.h>
end_include

begin_include
include|#
directive|include
file|<netinet/in.h>
end_include

begin_include
include|#
directive|include
file|<arpa/nameser.h>
end_include

begin_include
include|#
directive|include
file|<resolv.h>
end_include

begin_comment
comment|/* Access functions for the libresolv private interface */
end_comment

begin_function_decl
name|int
name|__res_enable_mt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|__res_disable_mt
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_comment
comment|/* Per-thread context */
end_comment

begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|no_hosts_fallback_private
decl_stmt|;
name|int
name|retry_save
decl_stmt|;
name|int
name|retry_private
decl_stmt|;
name|char
name|inet_nsap_ntoa_tmpbuf
index|[
literal|255
operator|*
literal|3
index|]
decl_stmt|;
name|char
name|sym_ntos_unname
index|[
literal|20
index|]
decl_stmt|;
name|char
name|sym_ntop_unname
index|[
literal|20
index|]
decl_stmt|;
name|char
name|p_option_nbuf
index|[
literal|40
index|]
decl_stmt|;
name|char
name|p_time_nbuf
index|[
literal|40
index|]
decl_stmt|;
name|char
name|precsize_ntoa_retbuf
index|[
sizeof|sizeof
expr|"90000000.00"]
expr_stmt|;
name|char
name|loc_ntoa_tmpbuf
index|[
sizeof|sizeof
expr|"1000 60 60.000 N 1000 60 60.000 W -12345678.00m 90000000.00m 90000000.00m 90000000.00m"]
expr_stmt|;
name|char
name|p_secstodate_output
index|[
literal|15
index|]
decl_stmt|;
block|}
name|mtctxres_t
typedef|;
end_typedef

begin_comment
comment|/* Thread-specific data (TSD) */
end_comment

begin_function_decl
name|mtctxres_t
modifier|*
name|___mtctxres
parameter_list|(
name|void
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|mtctxres
value|(___mtctxres())
end_define

begin_comment
comment|/* Various static data that should be TSD */
end_comment

begin_define
define|#
directive|define
name|sym_ntos_unname
value|(mtctxres->sym_ntos_unname)
end_define

begin_define
define|#
directive|define
name|sym_ntop_unname
value|(mtctxres->sym_ntop_unname)
end_define

begin_define
define|#
directive|define
name|inet_nsap_ntoa_tmpbuf
value|(mtctxres->inet_nsap_ntoa_tmpbuf)
end_define

begin_define
define|#
directive|define
name|p_option_nbuf
value|(mtctxres->p_option_nbuf)
end_define

begin_define
define|#
directive|define
name|p_time_nbuf
value|(mtctxres->p_time_nbuf)
end_define

begin_define
define|#
directive|define
name|precsize_ntoa_retbuf
value|(mtctxres->precsize_ntoa_retbuf)
end_define

begin_define
define|#
directive|define
name|loc_ntoa_tmpbuf
value|(mtctxres->loc_ntoa_tmpbuf)
end_define

begin_define
define|#
directive|define
name|p_secstodate_output
value|(mtctxres->p_secstodate_output)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* _RESOLV_MT_H */
end_comment

end_unit

