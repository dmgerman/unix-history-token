begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_typedef
typedef|typedef
struct|struct
block|{
name|int
name|fd_ctrl
decl_stmt|;
name|int
name|fd_debug
decl_stmt|;
name|int
name|binary
decl_stmt|;
name|int
name|passive
decl_stmt|;
name|int
name|addrtype
decl_stmt|;
name|char
modifier|*
name|host
decl_stmt|;
name|char
modifier|*
name|file
decl_stmt|;
block|}
typedef|*
name|FTP_t
typedef|;
end_typedef

begin_function_decl
name|FTP_t
name|FtpInit
parameter_list|()
function_decl|;
end_function_decl

begin_function_decl
name|int
name|FtpOpen
parameter_list|(
name|FTP_t
parameter_list|,
name|char
modifier|*
name|host
parameter_list|,
name|char
modifier|*
name|user
parameter_list|,
name|char
modifier|*
name|passwd
parameter_list|)
function_decl|;
end_function_decl

begin_define
define|#
directive|define
name|FtpBinary
parameter_list|(
name|ftp
parameter_list|,
name|bool
parameter_list|)
value|{ (ftp)->binary = (bool); }
end_define

begin_define
define|#
directive|define
name|FtpPassive
parameter_list|(
name|ftp
parameter_list|,
name|bool
parameter_list|)
value|{ (ftp)->passive = (bool); }
end_define

begin_define
define|#
directive|define
name|FtpDebug
parameter_list|(
name|ftp
parameter_list|,
name|bool
parameter_list|)
value|{ (ftp)->fd_debug = (bool); }
end_define

begin_comment
comment|/* void		FtpBinary(FTP_t, int); void		FtpPassive(FTP_t, int); void		FtpDebug(FTP_t, int); */
end_comment

begin_function_decl
name|int
name|FtpChdir
parameter_list|(
name|FTP_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|FtpGet
parameter_list|(
name|FTP_t
parameter_list|,
name|char
modifier|*
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|int
name|FtpEOF
parameter_list|(
name|FTP_t
parameter_list|)
function_decl|;
end_function_decl

begin_function_decl
name|void
name|FtpClose
parameter_list|(
name|FTP_t
parameter_list|)
function_decl|;
end_function_decl

end_unit

