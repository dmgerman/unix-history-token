begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|tun_data
block|{
ifdef|#
directive|ifdef
name|__OpenBSD__
name|struct
name|tunnel_header
name|head
decl_stmt|;
endif|#
directive|endif
name|u_char
name|data
index|[
name|MAX_MRU
index|]
decl_stmt|;
block|}
struct|;
end_struct

begin_ifdef
ifdef|#
directive|ifdef
name|__OpenBSD__
end_ifdef

begin_define
define|#
directive|define
name|tun_fill_header
parameter_list|(
name|f
parameter_list|,
name|proto
parameter_list|)
value|do { (f).head.tun_af = (proto); } while (0)
end_define

begin_define
define|#
directive|define
name|tun_check_header
parameter_list|(
name|f
parameter_list|,
name|proto
parameter_list|)
value|((f).head.tun_af == (proto))
end_define

begin_else
else|#
directive|else
end_else

begin_define
define|#
directive|define
name|tun_fill_header
parameter_list|(
name|f
parameter_list|,
name|proto
parameter_list|)
value|do { } while (0)
end_define

begin_define
define|#
directive|define
name|tun_check_header
parameter_list|(
name|f
parameter_list|,
name|proto
parameter_list|)
value|(1)
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_function_decl
specifier|extern
name|void
name|tun_configure
parameter_list|(
name|int
parameter_list|,
name|int
parameter_list|)
function_decl|;
end_function_decl

end_unit

