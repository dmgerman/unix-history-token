begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_struct
struct|struct
name|ctl_buf
block|{
name|char
modifier|*
name|text
decl_stmt|;
name|size_t
name|used
decl_stmt|;
block|}
struct|;
end_struct

begin_define
define|#
directive|define
name|MAX_LINELEN
value|990
end_define

begin_comment
comment|/* Like SMTP. */
end_comment

begin_define
define|#
directive|define
name|MAX_NTOP
value|(sizeof "[255.255.255.255].65535")
end_define

begin_define
define|#
directive|define
name|allocated_p
parameter_list|(
name|Buf
parameter_list|)
value|((Buf).text != NULL)
end_define

begin_define
define|#
directive|define
name|buffer_init
parameter_list|(
name|Buf
parameter_list|)
value|((Buf).text = 0, (Buf.used) = 0)
end_define

begin_define
define|#
directive|define
name|ctl_bufget
value|__ctl_bufget
end_define

begin_define
define|#
directive|define
name|ctl_bufput
value|__ctl_bufput
end_define

begin_define
define|#
directive|define
name|ctl_sa_ntop
value|__ctl_sa_ntop
end_define

begin_define
define|#
directive|define
name|ctl_sa_copy
value|__ctl_sa_copy
end_define

begin_function_decl
name|int
name|ctl_bufget
parameter_list|(
name|struct
name|ctl_buf
modifier|*
parameter_list|,
name|ctl_logfunc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_bufput
parameter_list|(
name|struct
name|ctl_buf
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
specifier|const
name|char
modifier|*
name|ctl_sa_ntop
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|char
modifier|*
parameter_list|,
name|size_t
parameter_list|,
name|ctl_logfunc
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|ctl_sa_copy
parameter_list|(
specifier|const
name|struct
name|sockaddr
modifier|*
parameter_list|,
name|struct
name|sockaddr
modifier|*
parameter_list|)
function_decl|;
end_function_decl

end_unit

