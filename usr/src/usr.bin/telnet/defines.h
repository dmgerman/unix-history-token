begin_unit|revision:0.9.5;language:C;cregit-version:0.0.1
begin_define
define|#
directive|define
name|settimer
parameter_list|(
name|x
parameter_list|)
value|clocks.x = clocks.system++
end_define

begin_if
if|#
directive|if
operator|!
name|defined
argument_list|(
name|TN3270
argument_list|)
end_if

begin_define
define|#
directive|define
name|ExitString
parameter_list|(
name|f
parameter_list|,
name|s
parameter_list|,
name|r
parameter_list|)
value|{ fprintf(f, s); exit(r); }
end_define

begin_define
define|#
directive|define
name|Exit
parameter_list|(
name|x
parameter_list|)
value|exit(x)
end_define

begin_define
define|#
directive|define
name|SetIn3270
parameter_list|()
end_define

begin_endif
endif|#
directive|endif
end_endif

begin_comment
comment|/* !defined(TN3270) */
end_comment

begin_define
define|#
directive|define
name|NETADD
parameter_list|(
name|c
parameter_list|)
value|{ *nfrontp++ = c; }
end_define

begin_define
define|#
directive|define
name|NET2ADD
parameter_list|(
name|c1
parameter_list|,
name|c2
parameter_list|)
value|{ NETADD(c1); NETADD(c2); }
end_define

begin_define
define|#
directive|define
name|NETLOC
parameter_list|()
value|(nfrontp)
end_define

begin_define
define|#
directive|define
name|NETMAX
parameter_list|()
value|(netobuf+sizeof netobuf-1)
end_define

begin_define
define|#
directive|define
name|NETBYTES
parameter_list|()
value|(nfrontp-nbackp)
end_define

begin_define
define|#
directive|define
name|NETROOM
parameter_list|()
value|(NETMAX()-NETLOC()+1)
end_define

begin_define
define|#
directive|define
name|TTYADD
parameter_list|(
name|c
parameter_list|)
value|{ if (!(SYNCHing||flushout)) { *tfrontp++ = c; } }
end_define

begin_define
define|#
directive|define
name|TTYLOC
parameter_list|()
value|(tfrontp)
end_define

begin_define
define|#
directive|define
name|TTYMAX
parameter_list|()
value|(ttyobuf+sizeof ttyobuf-1)
end_define

begin_define
define|#
directive|define
name|TTYMIN
parameter_list|()
value|(netobuf)
end_define

begin_define
define|#
directive|define
name|TTYBYTES
parameter_list|()
value|(tfrontp-tbackp)
end_define

begin_define
define|#
directive|define
name|TTYROOM
parameter_list|()
value|(TTYMAX()-TTYLOC()+1)
end_define

begin_comment
comment|/*	Various modes */
end_comment

begin_define
define|#
directive|define
name|MODE_LINE
parameter_list|(
name|m
parameter_list|)
value|(modelist[m].modetype& LINE)
end_define

begin_define
define|#
directive|define
name|MODE_LOCAL_CHARS
parameter_list|(
name|m
parameter_list|)
value|(modelist[m].modetype&  LOCAL_CHARS)
end_define

begin_define
define|#
directive|define
name|MODE_LOCAL_ECHO
parameter_list|(
name|m
parameter_list|)
value|(modelist[m].modetype& LOCAL_ECHO)
end_define

begin_define
define|#
directive|define
name|MODE_COMMAND_LINE
parameter_list|(
name|m
parameter_list|)
value|(modelist[m].modetype& COMMAND_LINE)
end_define

begin_define
define|#
directive|define
name|LOCAL_CHARS
value|0x01
end_define

begin_comment
comment|/* Characters processed locally */
end_comment

begin_define
define|#
directive|define
name|LINE
value|0x02
end_define

begin_comment
comment|/* Line-by-line mode of operation */
end_comment

begin_define
define|#
directive|define
name|LOCAL_ECHO
value|0x04
end_define

begin_comment
comment|/* Echoing locally */
end_comment

begin_define
define|#
directive|define
name|COMMAND_LINE
value|0x08
end_define

begin_comment
comment|/* Command line mode */
end_comment

end_unit

